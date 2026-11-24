
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

/***                              
*  VsLibrary.cpp
*****************************************************************************/

#include "stdafx.h"
#include "PrjInc.h"

#define IMGLIST_WIDTH           16
#define IMGLIST_BACKGROUND      0x0000ff00


// {FCEEC8D7-44C7-4b9e-A794-5245372D08DE}
static GUID guidMyCLibrary = 
{ 0xfceec8d7, 0x44c7, 0x4b9e, { 0xa7, 0x94, 0x52, 0x45, 0x37, 0x2d, 0x8, 0xde } };


//==========================================================================
//                                                construct, init , destruct

HRESULT CVsLibrary::CreateInstance(
        /* [out] */ ILibrary**     ppILibrary)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::CreateInstance \n"));

    ExpectedPtrRet(ppILibrary);
    InitParam(ppILibrary);

    CComObject<CVsLibrary>* pco = NULL;
    HRESULT hr = CComObject<CVsLibrary>::CreateInstance(&pco);
    IfFailRet(hr);

    ASSERT(pco != NULL);
    pco->AddRef();
    hr = pco->Init();
    IfFailGo(hr);

    hr = pco->QueryInterface(
                IID_ILibrary, 
                (void**)ppILibrary);

Error:
    if (pco)
        pco->Release();

    return hr;
}


CVsLibrary::CVsLibrary() :
    m_hImages(NULL),
    m_dwIVsSolutionEventsCookie(NULL)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CVsLibrary::CVsLibrary , this = 0x%x \n"), this );
};


STDMETHODIMP CVsLibrary::Init()
{

    m_cbstrName.LoadString(IDS_OBJBRW_PROJECT_NAME);
    if (m_cbstrName.Length() == 0)
    {
        ASSERT(FALSE);
        return E_OUTOFMEMORY;
    }

    m_eCheckState = LCS_CHECKED;
    m_eLibFlags   = LF_PROJECT | LF_EXPANDABLE;

    //Load the image list
    m_hImages = ImageList_LoadBitmap(_AtlBaseModule.GetResourceInstance(),
        MAKEINTRESOURCE(IDB_BROWSER_GLYPH), IMGLIST_WIDTH, 0, IMGLIST_BACKGROUND);
    if(m_hImages == NULL)
    {
        ASSERT(FALSE);
        return E_OUTOFMEMORY;
    }

    m_uLibraryCounter    = 0;

    //Sync up to the Solution Events
    CComPtr<IVsSolution> srpIVsSolution;
    HRESULT hr;

    hr = _VxModule.QueryService(
            SID_SVsSolution, 
            IID_IVsSolution, 
            (void **) &srpIVsSolution);
    IfFailRet(hr);

    hr = srpIVsSolution->AdviseSolutionEvents(
            static_cast<IVsSolutionEvents *> (this), 
            &m_dwIVsSolutionEventsCookie);
    IfFailRet(hr);


    return S_OK; 
};  


CVsLibrary::~CVsLibrary()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CVsLibrary::~CVsLibrary , this = 0x%x \n"), this );

    // destroy the image list
    if (m_hImages != NULL)
    {
        ImageList_Destroy(m_hImages);
        m_hImages = NULL;
    }

    // release the array
    ULONG cLibraryItems;
    GetItemCount(&cLibraryItems);

    for (ULONG uIndex = 0 ; uIndex < cLibraryItems; uIndex++)
    {
        NotifyOnBrowseDataRemoved(LLT_PHYSICALCONTAINERS, m_rgpLibraryItem[uIndex]);
        m_rgpLibraryItem[uIndex]->Release();
    }
    m_rgpLibraryItem.RemoveAll();

    ASSERT(m_dwIVsSolutionEventsCookie == NULL);
    ASSERT(m_rgpLibraryItem.GetSize() == 0);

};


STDMETHODIMP CVsLibrary::Close()
{
    HRESULT hr    = S_OK;
    HRESULT hrRet = S_OK;

    // m_cbstrName

    if (m_dwIVsSolutionEventsCookie != NULL)
    {
        //unadvise the Solution Events
        CComPtr<IVsSolution> srpIVsSolution;

        hr = _VxModule.QueryService(
                SID_SVsSolution, 
                IID_IVsSolution, 
                (void **) &srpIVsSolution);

        if (SUCCEEDED(hr))
        {
            hr = srpIVsSolution->UnadviseSolutionEvents(
                    m_dwIVsSolutionEventsCookie);
            m_dwIVsSolutionEventsCookie = NULL;
        }
        if (FAILED(hr))
            hrRet = hr;
    }

    // close the array
    ULONG cLibraryItems;
    GetItemCount(&cLibraryItems);

    for (ULONG uIndex = 0 ; uIndex < cLibraryItems; uIndex++)
    {
        m_rgpLibraryItem[uIndex]->Close();
    }

    return hrRet;
}

//                                                construct, init , destruct
//==========================================================================



//==========================================================================
//                                                                  ILibrary
//

STDMETHODIMP CVsLibrary::GetName(
    /* [out] */ WCHAR **pszName)
{
    ExpectedPtrRet(pszName);
    *pszName = m_cbstrName;
    return S_OK;
};


STDMETHODIMP CVsLibrary::ToggleCheck()
{

    // Other than the library node there is no nesting and 
    // the checks can only be LCS_CHECKED or LCS_UNCHECKED

    BOOL  fToggle = FALSE;
    ULONG cLibraryItems;
    ULONG cChecked = 0;
    ULONG cUnchecked = 0;

    GetItemCount(&cLibraryItems);

    CountChecks(&cChecked, &cUnchecked);

    BOOL fNewActive = (m_eCheckState == LCS_UNCHECKED);
    if (fNewActive)
    {
         if(cUnchecked == cLibraryItems)  //All projects were not selected
         {
            m_eCheckState = LCS_CHECKED;
            fToggle = TRUE;
         }
         else
             m_eCheckState = LCS_CHECKEDGRAY;
    }

    if (!fNewActive)
    {
        m_eCheckState = LCS_UNCHECKED;
        if(cChecked == cLibraryItems)   //All projects were selected
        {
            fToggle = TRUE;
        }
    }
 
    //Cycle back through the items and set the check states
    if (fToggle)
    {
        // we toggle the state of all library items
        for (ULONG uIndex = 0 ; uIndex < cLibraryItems; uIndex++)
            m_rgpLibraryItem[uIndex]->ToggleState();
    }

    m_uLibraryCounter++;

    return S_OK;
};


STDMETHODIMP CVsLibrary::GetCheckState(
    /* [out] */ LIB_CHECKSTATE *pstate)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetCheckState ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pstate);
    *pstate = m_eCheckState;
    return S_OK;
};



STDMETHODIMP CVsLibrary::GetImageList(
        /* [out] */ HANDLE *    phImageList)
{
    ExpectedPtrRet(phImageList);
    *phImageList = m_hImages;
    return S_OK;
}


STDMETHODIMP_(BOOL) CVsLibrary::IsValidIndex(
    /* [in] */ ULONG uIndex)
{
    ULONG cLibraryItems;
    GetItemCount(&cLibraryItems);

    if (uIndex < cLibraryItems)
        return TRUE;
    else
        return FALSE;
};



STDMETHODIMP CVsLibrary::CountChecks(
    /* [out]  */ ULONG* pcChecked,  
    /* [out]  */ ULONG* pcUnchecked) 
{
    ExpectedPtrRet(pcChecked);
    ExpectedPtrRet(pcUnchecked);
    *pcChecked   = 0;
    *pcUnchecked = 0;

    ULONG cLibraryItems;

    GetItemCount(&cLibraryItems);

    for (ULONG uIndex = 0 ; uIndex < cLibraryItems; uIndex++)
    {
        LIB_CHECKSTATE lcs;
        m_rgpLibraryItem[uIndex]->GetCheckState(&lcs);
        if (lcs == LCS_CHECKED)
            (*pcChecked)++;
        else if (lcs == LCS_UNCHECKED)
            (*pcUnchecked)++;
        else 
            ASSERT(FALSE); // check state is not correct
    }

    return S_OK; 
}

//
//                                                                  ILibrary
//==========================================================================




//==========================================================================
//                                                       IBrowseDataProvider
STDMETHODIMP CVsLibrary::AddBrowseNodesToArray(
    /* [in]      */ LIB_LISTTYPE         eListType, 
    /* [in,out]  */ BrowseNodeArray*     pBrowseNodeArray)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::AddBrowseNodesToArray /IBrowseDataProvider/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pBrowseNodeArray);

    // if the library is not checked do not add anything
    if (m_eCheckState == LCS_UNCHECKED)
        return S_OK;

    HRESULT hr = S_OK;
    
    ULONG cLibraryItems;
    GetItemCount(&cLibraryItems);

    for (ULONG uIndex = 0 ; uIndex < cLibraryItems; uIndex++)
    {
        LIB_CHECKSTATE lcs;
        m_rgpLibraryItem[uIndex]->GetCheckState(&lcs);
        if (lcs == LCS_CHECKED)
        {
            switch (eListType)
            {
            case LLT_PACKAGE:   
                 pBrowseNodeArray->Add((CBrowseNode*)(m_rgpLibraryItem[uIndex]));
                 break;

            case LLT_CLASSES:
            case LLT_MEMBERS:
                 hr = m_rgpLibraryItem[uIndex]->AddBrowseNodesToArray(
                     eListType, pBrowseNodeArray);
                 break;
            default:
                 hr = m_rgpLibraryItem[uIndex]->AddBrowseNodesToArray(
                     eListType, pBrowseNodeArray);
                ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
                    _T(": CVsLibrary::AddBrowseNodesToArray /IBrowseDataProvider/ ")
                    _T(", eListType = 0x%x \n"), eListType );
                 break;
            }
        }
        IfFailRet(hr);
    }
    return hr;
}
//                                                       IBrowseDataProvider
//==========================================================================

//==========================================================================
//                                                                IVsLibrary
//
//--------------------------------------------------------------------------
//                                                      IVsLibrary interface
//

STDMETHODIMP CVsLibrary::GetSupportedCategoryFields(
        /*[in]         */ LIB_CATEGORY eCategory, 
        /*[out, retval]*/ DWORD *      pCatField)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::get_SupportedCategoryFields /IVsLibrary/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pCatField);

    switch ( eCategory )
    {
    case LC_MEMBERTYPE:
        //  LCMT_METHOD   = 0x0001,
        //  LCMT_PROPERTY = 0x0002,
        //  LCMT_EVENT    = 0x0004,
        //  LCMT_FIELD    = 0x0008,
        //  LCMT_CONSTANT = 0x0010,
        //  LCMT_OPERATOR = 0x0020,
        //  LCMT_MAPITEM  = 0x0040,
        //  LCMT_VARIABLE = 0x0080,
        //  LCMT_ENUMITEM = 0x0100,
        //  LCMT_TYPEDEF  = 0x0200,
        //  LCMT_FUNCTION = 0x0400,
        *pCatField = 
                     LCMT_FUNCTION |
                     LCMT_VARIABLE;
        break;

    case LC_MEMBERACCESS:
        //  LCMA_PUBLIC    = 0x0001,
        //  LCMA_PRIVATE   = 0x0002,
        //  LCMA_PROTECTED = 0x0004,
        //  LCMA_PACKAGE   = 0x0008,
        //  LCMA_FRIEND    = 0x0010,
        //  LCMA_SEALED    = 0x0020
        *pCatField = 
                     LCMA_PUBLIC    ;
        break;

    case LC_CLASSTYPE:
        //  LCCT_CLASS     = 0x0001,
        //  LCCT_INTERFACE = 0x0002,
        //  LCCT_EXCEPTION = 0x0004,
        //  LCCT_STRUCT    = 0x0008,
        //  LCCT_ENUM      = 0x0010,
        //  LCCT_MODULE    = 0x0020,
        //  LCCT_UNION     = 0x0040,
        //  LCCT_INTRINSIC = 0x0080,
        //  LCCT_DELEGATE  = 0x0100,
        //  LCCT_TYPEDEF   = 0x0200,
        //  LCCT_MACRO     = 0x0400,
        //  LCCT_MAP       = 0x0800,
        //  LCCT_GLOBAL    = 0x1000,
        *pCatField = 
                     LCCT_CLASS     ;
        break;

    case LC_CLASSACCESS:
        //  LCCA_PUBLIC    = 0x0001,
        //  LCCA_PRIVATE   = 0x0002,
        //  LCCA_PROTECTED = 0x0004,
        //  LCCA_PACKAGE   = 0x0008,
        //  LCCA_FRIEND    = 0x0010,
        //  LCCA_SEALED    = 0x0020
        *pCatField =    
                     LCCA_PUBLIC    ; 
        break;

    case LC_ACTIVEPROJECT:
        //  LCAP_SHOWALWAYS   = 0x0001,
        //  LCAP_MUSTBEACTIVE = 0x0002,
        *pCatField = 
                     LCAP_SHOWALWAYS;
        break;

    case LC_LISTTYPE:
        //  LLT_CLASSES                 = 0x000001, 
        //  LLT_MEMBERS                 = 0x000002, 
        //  LLT_PHYSICALCONTAINERS      = 0x000004,     
        //  LLT_PACKAGE                 = 0x000004, same as above (old name)
        //  LLT_NAMESPACES              = 0x000008,
        //  LLT_CONTAINMENT             = 0x000010,
        //  LLT_CONTAINEDBY             = 0x000020,
        //  LLT_USESCLASSES             = 0x000040,
        //  LLT_USEDBYCLASSES           = 0x000080,
        //  LLT_NESTEDCLASSES           = 0x000100,
        //  LLT_INHERITEDINTERFACES     = 0x000200,
        //  LLT_INTERFACEUSEDBYCLASSES  = 0x000400,
        //  LLT_DEFINITIONS             = 0x000800,
        //  LLT_REFERENCES              = 0x001000,
        //  LLT_HIERARCHY               = 0x002000, 
        *pCatField = 
                     LLT_PHYSICALCONTAINERS |
                     LLT_CLASSES            |
                     LLT_MEMBERS;
        break;

    case LC_VISIBILITY:
        //  LCV_VISIBLE  = 0x0001,
        //  LCV_HIDDEN   = 0x0002,
        *pCatField = 
                     LCV_VISIBLE ; 
        break;

    case LC_MODIFIER:
        //  LCMDT_VIRTUAL       = 0x0001,
        //  LCMDT_PUREVIRTUAL   = 0x0002,
        //  LCMDT_NONVIRTUAL    = 0x0004,
        //  LCMDT_FINAL         = 0x0008,
        //  LCMDT_STATIC        = 0x0010,
        *pCatField = 
                     LCMDT_STATIC;
        break;

    default:
        ASSERT(FALSE); // Unknown category
        *pCatField = 0;
        return E_FAIL;
    }

    return S_OK;
}

STDMETHODIMP CVsLibrary::GetList(
    /*[in]         */ LIB_LISTTYPE         eListType,  
    /*[in]         */ LIB_LISTFLAGS        eFlags, 
    /*[in]         */ VSOBSEARCHCRITERIA * pobSrch, 
    /*[out, retval]*/ IVsObjectList **     ppList)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetList /IVsLibrary/ ")
        _T(", this = 0x%x \n"), this );

    if (eFlags & LLF_USESEARCHFILTER)
        return E_NOTIMPL;

    return CVsObjectList::CreateInstance(
                static_cast<IBrowseDataProvider*>(this), 
                static_cast<IVsLibrary*>(this), 
                eListType, 
                eFlags, 
                pobSrch, 
                ppList); 
}


STDMETHODIMP CVsLibrary::GetLibList(
    /*[in]         */ LIB_PERSISTTYPE lptType,
    /*[out, retval]*/ IVsLiteTreeList **ppList)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::get_GetLibList /IVsLibrary/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(ppList);
    if (LPT_PROJECT != lptType)
      return E_INVALIDARG;  // We only support project browse containers

    HRESULT hr = m_counterLibList.ResetChanges();
    IfFailRet(hr);

    *ppList = static_cast<IVsLiteTreeList*>(this);
    (*ppList)->AddRef();
    return S_OK;
}

STDMETHODIMP CVsLibrary::GetLibFlags(
    /*[out, retval]*/ LIB_FLAGS *pfFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetLibFlags /IVsLibrary/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pfFlags);
    *pfFlags = m_eLibFlags;
    return S_OK;
}

STDMETHODIMP CVsLibrary::UpdateCounter(
    /*[out]*/ ULONG *pCurUpdate)
{
    /*
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::UpdateCounter /IVsLibrary/ ")
        _T(", this = 0x%x \n"), this );
    */

    ExpectedPtrRet(pCurUpdate);
    *pCurUpdate = m_uLibraryCounter;
    return S_OK;
}



STDMETHODIMP CVsLibrary::GetGuid(const GUID **ppguidLib)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetGuid /IVsLibrary/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(ppguidLib);

    *ppguidLib = &guidMyCLibrary; 
    return S_OK;
}



STDMETHODIMP CVsLibrary::GetSeparatorString(
    LPCWSTR *pszSeparator) 
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetSeparatorString /IVsLibrary/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pszSeparator);
    return E_NOTIMPL;
}


STDMETHODIMP CVsLibrary::LoadState(
    /* [in] */ IStream *        pIStream, 
    /* [in] */ LIB_PERSISTTYPE  lptType)
{
    // we do not save/load persisted state
    return E_NOTIMPL; 
}


STDMETHODIMP CVsLibrary::SaveState(
    /* [in] */ IStream *        pIStream,
    /* [in] */ LIB_PERSISTTYPE  lptType)
{
    // we do not save/load persisted state
    return E_NOTIMPL; 
}


STDMETHODIMP CVsLibrary::GetBrowseContainersForHierarchy(
    /* [in]                     */ IVsHierarchy *    pHierarchy,
    /* [in]                     */ ULONG             celt,
    /* [in, out, size_is(celt)] */ VSBROWSECONTAINER rgBrowseContainers[],
    /* [out, optional]          */ ULONG *           pcActual)
{
    HRESULT hr = S_OK;
    if (pcActual != NULL)
        *pcActual = 0;

    //Do we have this project?
    ULONG cLibraryItems;
    GetItemCount(&cLibraryItems);
    for (ULONG i = 0; i < cLibraryItems; i++ )
    {
        //Compare the pHeir Pointers
        CComPtr<IVsHierarchy> srpIVsHierarchy;
        hr = m_rgpLibraryItem[i]->GetHierarchy(&srpIVsHierarchy);
        IfFailRet(hr);

        if ( (IVsHierarchy*) srpIVsHierarchy == pHierarchy )
        {
            if (celt && rgBrowseContainers)
            {
                hr = GetGuid((const struct _GUID **)&rgBrowseContainers[0].pguidLib);
                IfFailRet(hr);
                hr = m_rgpLibraryItem[i]->GetText(TTO_DEFAULT, (const WCHAR **)&rgBrowseContainers[0].szName);
                IfFailRet(hr);
            }
             
            if (pcActual != NULL)
                *pcActual = 1;// We always only have one library. 

            break;
        }
    }

    return S_OK;
}


STDMETHODIMP CVsLibrary::AddBrowseContainer(
    /* [in]      */ PVSCOMPONENTSELECTORDATA pcdComponent,
    /* [in, out] */ LIB_ADDREMOVEOPTIONS *   pgrfOptions,
    /* [out]     */ BSTR *                   pbstrComponentAdded)
{
    // we do not support GLOBAL browse containers
    return E_NOTIMPL; 
}


STDMETHODIMP CVsLibrary::RemoveBrowseContainer(
    /* [in] */ DWORD    dwReserved, 
    /* [in] */ LPCWSTR  pszLibName)
{
    // we do not support GLOBAL browse containers
    return E_NOTIMPL; 
}

//
//                                                                IVsLibrary
//==========================================================================




//==========================================================================
//                                                           IVsLiteTreeList
//

STDMETHODIMP CVsLibrary::GetFlags(
    /* [out] */ VSTREEFLAGS *pFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetFlags /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pFlags);

    //State change and update only
    *pFlags = TF_NOEVERYTHING ^ (TF_NOSTATECHANGE | TF_NOUPDATES);

    return S_OK;
}


STDMETHODIMP CVsLibrary::GetItemCount(
    /* [out] */ ULONG* pCount)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetItemCount /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );
 
    ExpectedPtrRet(pCount);

    *pCount = m_rgpLibraryItem.GetSize();
    return S_OK;
}


STDMETHODIMP CVsLibrary::GetExpandedList(
    /* [in]  */ ULONG              uIndex, 
    /* [out] */ BOOL *             pfCanRecurse, 
    /* [out] */ IVsLiteTreeList ** pptlNode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetExpandedList /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ASSERT(FALSE); // TF_NOEXPANSION is set: this shouldn't be called
    return E_FAIL;
}


STDMETHODIMP CVsLibrary::LocateExpandedList(
    /* [in]  */ IVsLiteTreeList* pExpandedList, 
    /* [out] */ ULONG *          uIndex)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::LocateExpandedList /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ASSERT(FALSE); // TF_NOEXPANSION and TF_NORELOCATE is set: this shouldn't be called
    return E_FAIL;
}


//Called when a list is collapsed by the user.
STDMETHODIMP CVsLibrary::OnClose(
    /* [out] */ VSTREECLOSEACTIONS *ptca)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnClose /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(ptca);

    // Since handing the list back out is almost free and
    // the list isn't expandable, there's no reason for
    // the tree to keep a reference.
    *ptca = TCA_CLOSEANDDISCARD;
    return S_OK;
}


STDMETHODIMP CVsLibrary::GetText(
    /* [in]  */ ULONG             uIndex, 
    /* [in]  */ VSTREETEXTOPTIONS tto, 
    /* [out] */ const WCHAR **    ppszText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetText /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(ppszText);
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    return m_rgpLibraryItem[uIndex]->GetText(tto, ppszText);
}


STDMETHODIMP CVsLibrary::GetTipText(
    /* [in]  */ ULONG          uIndex, 
    /* [in]  */ VSTREETOOLTIPTYPE eTipType, 
    /* [out] */ const WCHAR ** ppszText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetTipText /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(ppszText);
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    return m_rgpLibraryItem[uIndex]->GetTipText(eTipType, ppszText);
}


STDMETHODIMP CVsLibrary::GetExpandable(
    /* [in]  */ ULONG  uIndex, 
    /* [out] */ BOOL * pfExpandable)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetExpandable /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pfExpandable);
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    *pfExpandable = FALSE;
    return S_OK;
}


STDMETHODIMP CVsLibrary::GetDisplayData(
    /* [in]  */ ULONG               uIndex, 
    /* [out] */ VSTREEDISPLAYDATA * pData)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetDisplayData /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;
    ExpectedPtrRet(pData);

    GetImageList(&pData->hImageList);

    BOOL fIsLibraryChecked = (m_eCheckState == LCS_UNCHECKED) ? FALSE : TRUE;
    return m_rgpLibraryItem[uIndex]->GetDisplayData(fIsLibraryChecked, pData);
}


STDMETHODIMP CVsLibrary::UpdateCounter(
    /* [out] */ ULONG *                 puCurUpdate,  
    /* [out] */ VSTREEITEMCHANGESMASK * pgrfChanges)
{
    /*
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::UpdateCounter /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );
    */
    return m_counterLibList.UpdateCounter(puCurUpdate, pgrfChanges);
}


STDMETHODIMP CVsLibrary::GetListChanges(
    /*[in,out]                 */ ULONG *pcChanges, 
    /*[in, size_is(*pcChanges)]*/ VSTREELISTITEMCHANGE *prgListChanges)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::GetListChanges /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    return m_counterLibList.GetListChanges(pcChanges, prgListChanges);

}


STDMETHODIMP CVsLibrary::ToggleState(
    /* [in]  */ ULONG                      uIndex, 
    /* [out] */ VSTREESTATECHANGEREFRESH * ptscr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::ToggleState /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;
    ExpectedPtrRet(ptscr);

    HRESULT hr = m_rgpLibraryItem[uIndex]->ToggleState();
    IfFailRet(hr);

    *ptscr = TSCR_CURRENT | TSCR_PARENTS | TSCR_CHILDREN | TSCR_PARENTSCHILDREN;

    LIB_CHECKSTATE lcs;
    m_rgpLibraryItem[uIndex]->GetCheckState(&lcs);

    // check if this change the library state
    BOOL fUpdateLibraryCounter    = FALSE;
    ULONG cChecked;
    ULONG cUnchecked;

    CountChecks(&cChecked,&cUnchecked);

    if (lcs == LCS_CHECKED) // item has been checked
    {
        // we should update if the library has been unchecked
        fUpdateLibraryCounter = (m_eCheckState == LCS_UNCHECKED);

        if (!cUnchecked) // the last unchecked has been checked
            m_eCheckState = LCS_CHECKED;// change the library state
        else
            // change the library state
            m_eCheckState = LCS_CHECKEDGRAY;
    }
    else // item has been unchecked
    {
        if (m_eCheckState != LCS_UNCHECKED)
            if (!cChecked)
            {
                // the last checked has been unchecked
                m_eCheckState = LCS_UNCHECKED;
                // we should update if the library is unchecked
                fUpdateLibraryCounter = TRUE;
            }
            else
                m_eCheckState = LCS_CHECKEDGRAY;
    }

    if (fUpdateLibraryCounter)
        m_uLibraryCounter++;
    else
    {
        // notify any lists for the change
        CBrowseNode * pBrowseNode = m_rgpLibraryItem[uIndex];
        if (lcs == LCS_CHECKED)
            NotifyOnBrowseDataAdded(LLT_PHYSICALCONTAINERS, pBrowseNode);
        else
            NotifyOnBrowseDataRemoved(LLT_PHYSICALCONTAINERS, pBrowseNode);
    }

    return hr; 
}

//
//                                                           IVsLiteTreeList
//==========================================================================



//==========================================================================
//                                                         IVsSolutionEvents
//

STDMETHODIMP CVsLibrary::OnAfterOpenProject(
    /* [in] */ IVsHierarchy * pIVsHierarchy, 
    /* [in] */ BOOL fAdded)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnAfterOpenProject /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pIVsHierarchy);

    HRESULT hr;

    //Do we already have this project?
    ULONG cLibraryItems;
    GetItemCount(&cLibraryItems);
    for (ULONG i = 0; i < cLibraryItems; i++ )
    {
        //Compare the pHeir Pointers
        CComPtr<IVsHierarchy> srpIVsHierarchy;
        hr = m_rgpLibraryItem[i]->GetHierarchy(&srpIVsHierarchy);
        IfFailRet(hr);

        if ( (IVsHierarchy*) srpIVsHierarchy == pIVsHierarchy )
            return S_OK;
    }

    // check to see if this is a myc project
    GUID guidProject;
    hr = pIVsHierarchy->GetGuidProperty(
            VSITEMID_ROOT, 
            VSHPROPID_TypeGuid, 
            &guidProject);
    _IfFailRet(hr);

    if (!IsEqualGUID(guidProject, GUID_NODETYPE_FileVw_Project))
        return S_OK;

   //Create a new project info struct
    CComObject<CLibraryItem>* pLibraryItem = NULL;
    hr = CLibraryItem::CreateInstance(
        static_cast<IVsLibrary*>(this),
        pIVsHierarchy,
        &pLibraryItem);
    IfFailRet(hr);
    ASSERT(pLibraryItem!=NULL);

    m_rgpLibraryItem.Add(pLibraryItem);

    // inform the lists if any
    NotifyOnBrowseDataAdded(LLT_PHYSICALCONTAINERS, pLibraryItem);
    
    // update the liblist
    VSTREELISTITEMCHANGE listChanges;
    listChanges.grfChange = TCT_ITEMADDED; 
    listChanges.Index     = cLibraryItems;

    hr = m_counterLibList.Increment(listChanges);

    return hr;
}


STDMETHODIMP CVsLibrary::OnQueryCloseProject(
    /*[in]    */ IVsHierarchy *pHierarchy, 
    /*[in]    */ BOOL fRemoving, 
    /*[in,out]*/ BOOL *pfCancel)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnQueryCloseProject /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}


STDMETHODIMP CVsLibrary::OnBeforeCloseProject(
    /*[in]*/ IVsHierarchy *pIVsHierarchy, 
    /*[in]*/ BOOL fRemoved)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnBeforeCloseProject /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pIVsHierarchy);

    HRESULT hr;

    //Do we have this project?

    ULONG uIndex = 0;
    ULONG cLibraryItems;
    GetItemCount(&cLibraryItems);
    for (uIndex = 0; uIndex < cLibraryItems; uIndex++ )
    {
        //Compare the pointers
        CComPtr<IVsHierarchy> srpIVsHierarchy;
        hr = m_rgpLibraryItem[uIndex]->GetHierarchy(&srpIVsHierarchy);
        IfFailRet(hr);

        if ( (IVsHierarchy*) srpIVsHierarchy == pIVsHierarchy )
        {
            break;
        }
    }

    if (uIndex == cLibraryItems) // we do not have it
        return S_OK;

    // remove the data
    CComObject<CLibraryItem> * pLibraryItem = m_rgpLibraryItem[uIndex];
    m_rgpLibraryItem.RemoveAt(uIndex);

    // inform the lists if any
    NotifyOnBrowseDataRemoved(LLT_PHYSICALCONTAINERS, pLibraryItem);
    
    // update the liblist
    VSTREELISTITEMCHANGE listChanges;
    listChanges.grfChange = TCT_ITEMDELETED; 
    listChanges.Index     = uIndex;
    hr = m_counterLibList.Increment(listChanges);

    pLibraryItem->Close();
    pLibraryItem->Release();

    return hr;
}


STDMETHODIMP CVsLibrary::OnAfterLoadProject(
    /*[in]*/ IVsHierarchy *pStubHierarchy, 
    /*[in]*/ IVsHierarchy *pRealHierarchy)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnAfterLoadProject /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK; 
}


STDMETHODIMP CVsLibrary::OnQueryUnloadProject(
    /*[in]    */ IVsHierarchy *pRealHierarchy, 
    /*[in,out]*/ BOOL *pfCancel)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnQueryUnloadProject /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}


STDMETHODIMP CVsLibrary::OnBeforeUnloadProject(
    /*[in]*/ IVsHierarchy *pRealHierarchy, 
    /*[in]*/ IVsHierarchy *pStubHierarchy)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnBeforeUnloadProject /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}


STDMETHODIMP CVsLibrary::OnAfterOpenSolution(
    /*[in]*/ IUnknown *pUnkReserved, 
    /*[in]*/ BOOL fNewSolution)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnAfterOpenSolution /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}


STDMETHODIMP CVsLibrary::OnQueryCloseSolution(
    /*[in]    */ IUnknown *pUnkReserved, 
    /*[in,out]*/ BOOL *pfCancel)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnQueryCloseSolution /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}


STDMETHODIMP CVsLibrary::OnBeforeCloseSolution(
    /*[in]*/ IUnknown *pUnkReserved)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnBeforeCloseSolution /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}


STDMETHODIMP CVsLibrary::OnAfterCloseSolution(
    /*[in]*/ IUnknown *pUnkReserved)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnAfterCloseSolution /IVsSolutionEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}

//                                                         IVsSolutionEvents
//==========================================================================



//==========================================================================
//                                                 IBrowseDataProviderEvents

STDMETHODIMP CVsLibrary::OnBrowseDataAdded(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode)

{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnBrowseDataAdded ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pCBrowseNode);
    // notify the listeners
    NotifyOnBrowseDataAdded(eListType, pCBrowseNode);

    return S_OK;
}


STDMETHODIMP CVsLibrary::OnBrowseDataRemoved(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnBrowseDataRemoved ")
        _T(", this = 0x%x \n"), this );
    ExpectedPtrRet(pCBrowseNode);
    // notify the listeners
    NotifyOnBrowseDataRemoved(eListType, pCBrowseNode);
        
    return S_OK;
}


STDMETHODIMP CVsLibrary::OnBrowseDataPropertyChanged(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibrary::OnBrowseDataPropertyChanged ")
        _T(", this = 0x%x \n"), this );
    ExpectedPtrRet(pCBrowseNode);
    // notify the listeners
    NotifyOnBrowseDataPropertyChanged(eListType, pCBrowseNode);
        
    return S_OK;
}
//                                                 IBrowseDataProviderEvents
//==========================================================================

