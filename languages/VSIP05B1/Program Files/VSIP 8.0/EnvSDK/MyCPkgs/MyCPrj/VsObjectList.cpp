
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsObjectList.cpp: implementation of the CVsObjectList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PrjInc.h"

#ifndef MYCBROWSER
#include "VsObjectListStub.h"
#endif


//==========================================================================
//                                                construct, init , destruct


HRESULT CVsObjectList::CreateInstance(
    /* [in]  */ IBrowseDataProvider* pIBrowseDataProvider, 
    /* [in]  */ IVsLibrary*          pIVsLibrary, 
    /* [in]  */ LIB_LISTTYPE         eListType, 
    /* [in]  */ LIB_LISTFLAGS        flags, 
    /* [in]  */ VSOBSEARCHCRITERIA * pobSrch, 
    /* [out] */ IVsObjectList **     ppList)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::CreateInstance ") );

    ExpectedPtrRet(ppList);
    InitParam(ppList);

    CComObject<CVsObjectList>* pco = NULL;
    HRESULT hr = CComObject<CVsObjectList>::CreateInstance(&pco);
    IfFailRet(hr);

    ASSERT(pco != NULL);
    pco->AddRef();
    hr = pco->Init(
                pIBrowseDataProvider, 
                pIVsLibrary, 
                eListType, 
                flags, 
                pobSrch);
    IfFailGo(hr);

    hr = pco->QueryInterface(
                IID_IVsObjectList, 
                (void**)ppList);

Error:
    if (pco)
        pco->Release();

    return hr;
    
    
}

 
CVsObjectList::CVsObjectList() :
    m_dwIBrowseDataProviderEventsCookie(0)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CVsObjectList::CVsObjectList , this = 0x%x \n"), this );
}


STDMETHODIMP CVsObjectList::Init(
    /* [in]  */ IBrowseDataProvider* pIBrowseDataProvider, 
    /* [in]  */ IVsLibrary*          pIVsLibrary, 
    /* [in]  */ LIB_LISTTYPE         eListType, 
    /* [in]  */ LIB_LISTFLAGS        flags, 
    /* [in]  */ VSOBSEARCHCRITERIA * pobSrch)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::Init ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pIBrowseDataProvider);
    ExpectedPtrRet(pIVsLibrary);

    HRESULT hr;

    m_srpIBrowseDataProvider = pIBrowseDataProvider;
    m_srpIVsLibrary          = pIVsLibrary;
    m_eListType              = eListType;

    // listen to provider events
    if (! m_dwIBrowseDataProviderEventsCookie)
    {
        hr = pIBrowseDataProvider->AdviseBrowseDataProviderEvents(
            static_cast<IBrowseDataProviderEvents *> (this), 
            &m_dwIBrowseDataProviderEventsCookie);
        IfFailRet(hr);
    }

    // fill the browse nodes
    hr = pIBrowseDataProvider->AddBrowseNodesToArray(
        eListType,
        &m_rgpBrowseNode);

    return hr;
}


CVsObjectList::~CVsObjectList()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CVsObjectList::~CVsObjectList , this = 0x%x \n"), this );
    HRESULT hr = Close();
    ASSERT(SUCCEEDED(hr));
}


STDMETHODIMP CVsObjectList::Close()
{
    HRESULT hr    = S_OK;
    HRESULT hrRet = S_OK;

    // unadvise
    if (m_dwIBrowseDataProviderEventsCookie != NULL)
    {
        hr = m_srpIBrowseDataProvider->UnadviseBrowseDataProviderEvents(
                m_dwIBrowseDataProviderEventsCookie);
        if (FAILED(hr))
            hrRet = hr;
        m_dwIBrowseDataProviderEventsCookie = NULL;
    }

    // release the array
    m_rgpBrowseNode.RemoveAll();

    return hrRet;
}

ULONG CVsObjectList::InternalRelease()
{
    if (m_dwRef == 2)
    {
        if (m_dwIBrowseDataProviderEventsCookie != NULL)
        {
            VSCOOKIE dwCookie = m_dwIBrowseDataProviderEventsCookie;
            m_dwIBrowseDataProviderEventsCookie = NULL;
            HRESULT hr = m_srpIBrowseDataProvider->UnadviseBrowseDataProviderEvents(
                    dwCookie);
            ASSERT(SUCCEEDED(hr));
        }
    }
    return CComObjectRoot::InternalRelease();
}

//                                                construct, init , destruct
//==========================================================================


//==========================================================================
//                                                            Common helpers

STDMETHODIMP_(BOOL) CVsObjectList::IsValidIndex(
    /* [in] */ ULONG uIndex)
{
    ULONG cBrowseObject;
    GetItemCount(&cBrowseObject);

    if (uIndex < cBrowseObject)
        return TRUE;
    else
        return FALSE;
};

//                                                            Common helpers
//==========================================================================


//==========================================================================
//                                                           IVsLiteTreeList
//

STDMETHODIMP CVsObjectList::GetFlags(
    /* [out] */ VSTREEFLAGS *pFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetFlags /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pFlags);
    
    if (m_eListType & ( LLT_PHYSICALCONTAINERS | LLT_CLASSES ))
    {
        //State change and expansion
        *pFlags = TF_NOEVERYTHING ^ (TF_NOSTATECHANGE | TF_NOUPDATES | TF_NOEXPANSION); 
    }
    else
    {
        //State change only
        *pFlags = TF_NOEVERYTHING ^ (TF_NOSTATECHANGE | TF_NOUPDATES );  
    }

    return S_OK;
}


STDMETHODIMP CVsObjectList::GetItemCount(
    /* [out] */ ULONG* pCount)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetItemCount /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pCount);

    *pCount = m_rgpBrowseNode.GetSize();
    return S_OK;
}


STDMETHODIMP CVsObjectList::GetExpandedList(
    /* [in]  */ ULONG              uIndex, 
    /* [out] */ BOOL *             pfCanRecurse, 
    /* [out] */ IVsLiteTreeList ** pptlNode)
{
    ATLTRACENOTIMPL(
                    _T(": CVsObjectList::GetExpandedList /IVsLiteTreeList/ "));
}


STDMETHODIMP CVsObjectList::LocateExpandedList(
    /* [in]  */ IVsLiteTreeList* pExpandedList, 
    /* [out] */ ULONG *          uIndex)
{
    ATLTRACENOTIMPL(
        _T(": CVsObjectList::LocateExpandedList /IVsLiteTreeList/ "));
}


STDMETHODIMP CVsObjectList::OnClose(
    /* [out] */ VSTREECLOSEACTIONS *ptca)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::OnClose /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(ptca);
    *ptca = TCA_NOTHING;
    return S_OK;
}


STDMETHODIMP CVsObjectList::GetText(
    /* [in]  */ ULONG             uIndex, 
    /* [in]  */ VSTREETEXTOPTIONS tto, 
    /* [out] */ const WCHAR **    ppszText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetText /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    return m_rgpBrowseNode[uIndex]->GetText(tto, ppszText);
}


STDMETHODIMP CVsObjectList::GetTipText(
    /* [in]  */ ULONG          uIndex, 
    /* [in]  */ VSTREETOOLTIPTYPE eTipType, 
    /* [out] */ const WCHAR ** ppszText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetTipText /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    return m_rgpBrowseNode[uIndex]->GetTipText(eTipType, ppszText);
}


STDMETHODIMP CVsObjectList::GetExpandable(
    /* [in]  */ ULONG  uIndex, 
    /* [out] */ BOOL * pfExpandable)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetExpandable /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pfExpandable);
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    if (m_eListType & (LLT_PHYSICALCONTAINERS | LLT_CLASSES) )
        *pfExpandable = TRUE;
    else
        *pfExpandable = FALSE;
    return S_OK;
}


STDMETHODIMP CVsObjectList::GetDisplayData(
    /* [in]  */ ULONG               uIndex, 
    /* [out] */ VSTREEDISPLAYDATA * pData)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetDisplayData /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;
    ExpectedPtrRet(pData);

    CComPtr<ILibrary> srpILibrary;
    HRESULT hr = m_srpIVsLibrary->QueryInterface(
        IID_ILibrary,
        (void**) &srpILibrary);
    IfFailRet(hr);

    hr = srpILibrary->GetImageList(&pData->hImageList);
    IfFailRet(hr);
    return m_rgpBrowseNode[uIndex]->GetDisplayData(pData);
}


STDMETHODIMP CVsObjectList::UpdateCounter(
    /* [out] */ ULONG *                 puCurUpdate,  
    /* [out] */ VSTREEITEMCHANGESMASK * pgrfChanges)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::UpdateCounter /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );
 
    return m_counter.UpdateCounter(puCurUpdate, pgrfChanges);
}


STDMETHODIMP CVsObjectList::GetListChanges(
    /*[in,out]                 */ ULONG *pcChanges, 
    /*[in, size_is(*pcChanges)]*/ VSTREELISTITEMCHANGE *prgListChanges)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetListChanges /IVsLiteTreeList/ ")
        _T(", this = 0x%x \n"), this );

    return m_counter.GetListChanges(pcChanges, prgListChanges);
}


STDMETHODIMP CVsObjectList::ToggleState(
    /* [in]  */ ULONG                      uIndex, 
    /* [out] */ VSTREESTATECHANGEREFRESH * ptscr)
{
    ATLTRACENOTIMPL(
        _T(": CVsObjectList::ToggleState /IVsLiteTreeList/ "));
}

//
//                                                           IVsLiteTreeList
//==========================================================================



//==========================================================================
//                                                             IVsObjectList
//


STDMETHODIMP CVsObjectList::GetCapabilities(
    /* [out] */  LIB_LISTCAPABILITIES *pCapabilities)
{
    ATLTRACENOTIMPL(
        _T(": CVsObjectList::GetCapabilities /IVsObjectList/ "));
}


STDMETHODIMP CVsObjectList::GetList(
    /* [in]  */ ULONG                uIndex, 
    /* [in]  */ LIB_LISTTYPE         eListType, 
    /* [in]  */ LIB_LISTFLAGS        flags, 
    /* [in]  */ VSOBSEARCHCRITERIA * pobSrch, 
    /* [out] */ IVsObjectList **     ppList)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetList /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    if (flags & LLF_USESEARCHFILTER)
        return E_NOTIMPL;

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;
    ExpectedPtrRet(ppList);
    InitParam(ppList);

    HRESULT hr;
    CComPtr<IBrowseDataProvider> srpIBrowseDataProvider;

    switch (m_eListType)
    {
        // if I am a container list - create the sublist for the specific container
        case LLT_PHYSICALCONTAINERS:
            hr = static_cast<CLibraryItem*>(m_rgpBrowseNode[uIndex])->QueryInterface(
                            IID_IBrowseDataProvider,
                            (void**) &srpIBrowseDataProvider);
            IfFailRet(hr);

            return CVsObjectList::CreateInstance(
                srpIBrowseDataProvider,
                m_srpIVsLibrary,
                eListType,
                flags,
                pobSrch,
                ppList);

        // if I am a class list - forward the call to the specific class
        case LLT_CLASSES:
            return GetListForClass(
                m_rgpBrowseNode[uIndex],
                eListType,
                flags,
                pobSrch,
                ppList);
        default:
            ENVSDK_TRACE(atlTraceNotImpl, TLI, 
                _T(": CVsObjectList::GetList /IVsObjectList/ ")
                _T(", this = 0x%x, eListType = 0x%x \n"), this, eListType );
            return E_FAIL;
    }

}


STDMETHODIMP CVsObjectList::GetListForClass(
    /* [in]  */ CBrowseNode *        pBrowseNode, 
    /* [in]  */ LIB_LISTTYPE         eListType, 
    /* [in]  */ LIB_LISTFLAGS        flags, 
    /* [in]  */ VSOBSEARCHCRITERIA * pobSrch, 
    /* [out] */ IVsObjectList **     ppList)
{
#ifdef MYCBROWSER
    // this method should be implemented with real logic 
    // to provide IVsObjectList for a class
#else
    // call a stub implementation
    return CVsObjectListStub::CreateInstance(
        pBrowseNode,
        m_srpIVsLibrary,
        eListType,
        flags,
        pobSrch,
        ppList);
#endif
}


STDMETHODIMP CVsObjectList::GetCategoryField(
    /* [in]  */ ULONG           uIndex, 
    /* [in]  */ LIB_CATEGORY    eCategory, 
    /*[out,retval]*/ DWORD*     pField)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetCategoryField /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    if ( (!IsValidIndex(uIndex)) && (uIndex != NULINDEX) )
        return E_UNEXPECTED;
    ExpectedPtrRet(pField);
    *pField = 0;

    HRESULT hr = S_OK;
    switch (eCategory)
    {
    case LC_LISTTYPE:
        switch (m_eListType)
        {
        case LLT_PACKAGE:
            *pField = LLT_CLASSES;
            break;
        case LLT_CLASSES:
            *pField = LLT_MEMBERS;
            break;
        case LLT_MEMBERS:
            *pField = 0;
            break;
        default:
            *pField = 0;
            ENVSDK_TRACE(atlTraceNotImpl, TLI, 
                _T(": CVsObjectList::GetCategoryField /IVsObjectList/ ")
                _T(", this = 0x%x, m_eListType = 0x%x \n"), this, m_eListType );
            break;
        }
        break;
    case LC_VISIBILITY:
        *pField = LCV_VISIBLE;
        break;
    case LC_MEMBERTYPE:
        ASSERT(uIndex != NULINDEX);
        return m_rgpBrowseNode[uIndex]->GetCategoryField(eCategory, pField);
    default:
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CVsObjectList::GetCategoryField /IVsObjectList/ ")
            _T(", eCategory = 0x%x \n"), eCategory );
        break;
    }

    return hr;
}


STDMETHODIMP CVsObjectList::GetExpandable2(
    /* [in]  */ ULONG         uIndex, 
    /* [in]  */ LIB_LISTTYPE  ListTypeExcluded, 
    /* [out] */ BOOL *        pfExpandable)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetExpandable2 /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    ATLTRACENOTIMPL(
                    _T(": CVsObjectList::GetExpandable2 /IVsObjectList/ "));
}


STDMETHODIMP CVsObjectList::GetNavigationInfo(
    /* [in]     */ ULONG                 uIndex, 
    /* [in, out]*/ VSOBNAVIGATIONINFO2 * pobNav)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetNavigationInfo /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;
    ExpectedPtrRet(pobNav);

    HRESULT hr = S_OK;

    hr = m_srpIVsLibrary->GetGuid((const GUID **) &(pobNav->pguidLib));
    IfFailRet(hr);

    ExpectedPtrRet(pobNav->pName);
    pobNav->pName->lltName = m_eListType;
    return m_rgpBrowseNode[uIndex]->GetNavigationInfo(pobNav);

}


STDMETHODIMP CVsObjectList::LocateNavigationInfo(
    /* [in]  */ VSOBNAVIGATIONINFO2 *pobNav, 
    /* [in]  */ VSOBNAVNAMEINFONODE *pobName, 
    /* [in]  */ BOOL fDontUpdate, 
    /* [out] */ BOOL *pfMatchedName, 
    /* [out] */ ULONG *pIndex)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::LocateNavigationInfo /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pobNav);
    ExpectedPtrRet(pobName);
    ExpectedPtrRet(pfMatchedName);
    ExpectedPtrRet(pIndex);   
    *pfMatchedName = TRUE; //This will be the case most often   
    *pIndex = NULINDEX;    //default to failure
    HRESULT hr = E_FAIL;

    switch (m_eListType)
    {
        case LLT_PACKAGE:
        case LLT_CLASSES:
        case LLT_MEMBERS:
        {
            // Check the list type in pobName.  
            // If this listtype is not the same as pobName list type then 
            // look at pobNav and make sure that pfMatchedName = FALSE;
            WCHAR * pMatchName = pobName->pszName;
            
            if (pobName->lltName != m_eListType)
            {
                *pfMatchedName = FALSE;
                pMatchName = pobNav->pszLibName;
            }

            //Walk through each of nodes and match up the names
            ULONG cBrowseNodes;
            GetItemCount(&cBrowseNodes);
            ExpectedPtrRet(pMatchName);
            for (ULONG uIndex = 0; uIndex < cBrowseNodes; uIndex++)
            {
                WCHAR * pName;
                hr = GetText(uIndex, TTO_DEFAULT, (const WCHAR **)&pName);
                IfFailRet(hr);

                //Do we match?
                if (! wcscmp(pMatchName, pName))
                {
                    *pIndex = uIndex;
                    hr = S_OK;
                    break;
                }
            }
            break;
        }

        default:
            ASSERT(FALSE); // Unsupported list type in LocateNavigationInfo
    }

    return hr;
}


STDMETHODIMP CVsObjectList::GetBrowseObject(
    /* [in]  */ ULONG uIndex, 
    /* [out] */ IDispatch **ppdispBrowseObj)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetBrowseObject /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    return E_NOTIMPL;
}

STDMETHODIMP CVsObjectList::GetUserContext(
    /* [in]  */ ULONG uIndex, 
    /* [out] */ IUnknown **ppunkUserCtx)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetUserContext /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    return E_NOTIMPL;
}

STDMETHODIMP CVsObjectList::ShowHelp(
    /* [in]  */ ULONG uIndex)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::ShowHelp /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    return E_NOTIMPL;
}

STDMETHODIMP CVsObjectList::GetSourceContext(
    /* [in]  */ ULONG uIndex, 
    /* [out] */ const WCHAR **pszFileName, 
    /* [out] */ ULONG *pulLineNum)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetSourceContext /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    return m_rgpBrowseNode[uIndex]->GetSourceContext(pszFileName, pulLineNum);
}



STDMETHODIMP CVsObjectList::CountSourceItems(
    /* [in]  */ ULONG uIndex, 
    /* [out] */ IVsHierarchy **ppHier, 
    /* [out] */ VSITEMID *pitemid, 
    /*[out, retval]*/ ULONG *pcItems)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::CountSourceItems /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    return m_rgpBrowseNode[uIndex]->CountSourceItems(ppHier, pitemid, pcItems);
}


STDMETHODIMP CVsObjectList::GetMultipleSourceItems(
    /* [in]  */ ULONG uIndex, 
    /* [in]  */ VSGSIFLAGS grfGSI, 
    /* [in]  */ ULONG cItems, 
    /*[out, size_is(cItems)]*/ VSITEMSELECTION rgItemSel[])
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GetMultipleSourceItems /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    ASSERT(FALSE); // we do not return multiple sources
    return E_NOTIMPL; 
}


STDMETHODIMP CVsObjectList::CanGoToSource(
    /* [in]  */ ULONG            uIndex, 
    /* [in]  */ VSOBJGOTOSRCTYPE eSrcType, 
    /* [out] */ BOOL *           pfOK)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::CanGoToSource /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pfOK);
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    //Default to fail.
    *pfOK = FALSE;
   
    if (m_eListType & (LLT_CLASSES))
    {
        // for classes (currently the file), we can go to the first line
        *pfOK = TRUE;
        return S_OK;//No Error
    }
    else if (m_eListType & (LLT_PACKAGE))
    {
        return S_OK;//No Error, but we can't go to source.
    }

    return S_OK;
}


STDMETHODIMP CVsObjectList::GoToSource(
    /* [in]  */ ULONG uIndex, 
    /* [in]  */ VSOBJGOTOSRCTYPE eSrcType)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::GoToSource /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    if (m_eListType & (LLT_PACKAGE))
        return E_FAIL;

    return m_rgpBrowseNode[uIndex]->GoToSource(eSrcType);
}


STDMETHODIMP CVsObjectList::GetContextMenu(
    /* [in]  */ ULONG uIndex, 
    /* [out] */ CLSID *pclsidActive, 
    /* [out] */ LONG *pnMenuId, 
    /* [out] */ IOleCommandTarget **ppCmdTrgtActive)
{
    ATLTRACENOTIMPL(
        _T(": CVsObjectList::GetContextMenu /IVsObjectList/ "));
}

STDMETHODIMP CVsObjectList::QueryDragDrop(
    /* [in]  */ ULONG uIndex, 
    /* [in]  */ IDataObject *pDataObject, 
    /* [in]  */ DWORD grfKeyState, 
    /*[in, out]*/DWORD * pdwEffect)
{
    ATLTRACENOTIMPL(
        _T(": CVsObjectList::QueryDragDrop /IVsObjectList/ "));
}

STDMETHODIMP CVsObjectList::DoDragDrop(
    /* [in]  */ ULONG uIndex, 
    /* [in]  */ IDataObject * pDataObject, 
    /* [in]  */ DWORD grfKeyState, 
    /*[in, out]*/DWORD * pdwEffect)
{
    ATLTRACENOTIMPL( 
        _T(": CVsObjectList::DoDragDrop /IVsObjectList/ "));
}


STDMETHODIMP CVsObjectList::CanRename(
    /* [in]  */ ULONG uIndex, 
    /* [in]  */ LPCOLESTR pszNewName, 
    /* [out] */ BOOL *pfOK)
{
    ATLTRACENOTIMPL( 
        _T(": CVsObjectList::CanRename /IVsObjectList/ "));
}


STDMETHODIMP CVsObjectList::DoRename(
    /* [in]  */ ULONG uIndex, 
    /* [in]  */ LPCOLESTR pszNewName,
    /* [in]  */ VSOBJOPFLAGS grfFlags)
{
    ATLTRACENOTIMPL( 
        _T(": CVsObjectList::DoRename /IVsObjectList/ "));
}


STDMETHODIMP CVsObjectList::CanDelete(
    /* [in]  */ ULONG uIndex, 
    /* [out] */ BOOL *pfOK)
{
    ATLTRACENOTIMPL( 
        _T(": CVsObjectList::CanDelete /IVsObjectList/ "));
}


STDMETHODIMP CVsObjectList::DoDelete(
    /* [in]  */ ULONG uIndex,
    /* [in]  */ VSOBJOPFLAGS grfFlags)
{
    ATLTRACENOTIMPL( 
        _T(": CVsObjectList::DoDelete /IVsObjectList/ "));
}

STDMETHODIMP CVsObjectList::FillDescription(
    /* [in]  */ ULONG uIndex, 
    /* [in]  */ VSOBJDESCOPTIONS grfOptions, 
    /* [in]  */ IVsObjectBrowserDescription2 *pobDesc)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::FillDescription /IVsObjectList/ ")
        _T(", this = 0x%x \n"), this );

    (grfOptions); // not used
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;
    ExpectedPtrRet(pobDesc);

    WCHAR* pType = NULL;
    switch(m_eListType)
    {
        case LLT_CLASSES:
            pType = L"class ";
            break;
        default:
            pType = L"";
            break;
    }
    pobDesc->ClearDescriptionText();
    pobDesc->AddDescriptionText(pType, OBDS_MISC, NULL);
    
    // call the browse node to add additional info if any
    return m_rgpBrowseNode[uIndex]->FillDescription(pobDesc);
}


STDMETHODIMP CVsObjectList::EnumClipboardFormats(
    /* [in]                     */ ULONG             Index, 
    /* [in]                     */ VSOBJCFFLAGS      grfFlags,
    /* [in]                     */ ULONG             celt, 
    /* [in, out, size_is(celt)] */ VSOBJCLIPFORMAT   rgcfFormats[],
    /* [out, optional]          */ ULONG *           pcActual)
{
    // we do not support drag/drop and copy/paste currently
    ATLTRACENOTIMPL( 
        _T(": CVsObjectList::EnumClipboardFormats /IVsObjectList/ "));
}

STDMETHODIMP CVsObjectList::GetClipboardFormat(
    /* [in]  */ ULONG           Index,
    /* [in]  */ VSOBJCFFLAGS    grfFlags,
    /* [in]  */ FORMATETC *     pFormatetc,
    /* [in]  */ STGMEDIUM *     pMedium)
{
    // we do not support drag/drop and copy/paste currently
    ATLTRACENOTIMPL( 
        _T(": CVsObjectList::GetClipboardFormat /IVsObjectList/ "));
}

STDMETHODIMP CVsObjectList::GetExtendedClipboardVariant(
    /* [in]  */ ULONG                   Index,
    /* [in]  */ VSOBJCFFLAGS            grfFlags,
    /* [in]  */ const VSOBJCLIPFORMAT * pcfFormat,
    /* [out] */ VARIANT *               pvarFormat)
{
    // we do not support drag/drop and copy/paste currently
    ATLTRACENOTIMPL( 
        _T(": CVsObjectList::GetExtendedClipboardVariant /IVsObjectList/ "));
}

//                                                             IVsObjectList
//==========================================================================


//==========================================================================
//                                                 IBrowseDataProviderEvents

STDMETHODIMP CVsObjectList::OnBrowseDataAdded(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode)

{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::OnBrowseDataAdded ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pCBrowseNode);
    
    VSTREELISTITEMCHANGE listChanges;
    if (eListType == m_eListType)
    {
        // check if we have the node
        ULONG cItems;
        GetItemCount(&cItems);
        for (ULONG uIndex = 0; uIndex < cItems; uIndex++)
        {
            if (m_rgpBrowseNode[uIndex] == pCBrowseNode)
                return S_OK;
        }
        // add the node
        m_rgpBrowseNode.Add(pCBrowseNode);

        listChanges.grfChange = TCT_ITEMADDED; 
        listChanges.Index = cItems;

        m_counter.Increment(listChanges);
    } 
    else if (eListType == LLT_PHYSICALCONTAINERS)
    {
        listChanges.grfChange = TCT_TOOMANYCHANGES; 
        listChanges.Index = NULINDEX;
        m_counter.Increment(listChanges);
    }
    
    return S_OK;
}


STDMETHODIMP CVsObjectList::OnBrowseDataRemoved(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::OnBrowseDataRemoved ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pCBrowseNode);
    
    VSTREELISTITEMCHANGE listChanges;
    if (eListType == m_eListType)
    {
        // check if we have the node
        ULONG cItems;
        GetItemCount(&cItems);
        for (ULONG uIndex = 0; uIndex < cItems; uIndex++)
        {
            if (m_rgpBrowseNode[uIndex] == pCBrowseNode)
            {
                // remove the node
                m_rgpBrowseNode.RemoveAt(uIndex);

                listChanges.grfChange = TCT_ITEMDELETED; 
                listChanges.Index = uIndex;

                m_counter.Increment(listChanges);
                return S_OK;
            }
        }
    } 
    else if (eListType == LLT_PHYSICALCONTAINERS)
    {
        listChanges.grfChange = TCT_TOOMANYCHANGES; 
        listChanges.Index = NULINDEX;
        m_counter.Increment(listChanges);
    }
    
    return S_OK;
}


STDMETHODIMP CVsObjectList::OnBrowseDataPropertyChanged(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectList::OnBrowseDataPropertyChanged ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pCBrowseNode);
    
    VSTREELISTITEMCHANGE listChanges;
    if (eListType == m_eListType)
    {
        // check if we have the node
        ULONG cItems;
        GetItemCount(&cItems);
        for (ULONG uIndex = 0; uIndex < cItems; uIndex++)
        {
            if (m_rgpBrowseNode[uIndex] == pCBrowseNode)
            {
                listChanges.grfChange = TCT_ITEMNAMECHANGED | TCT_ITEMPROPSCHANGED; 
                listChanges.Index = uIndex;

                m_counter.Increment(listChanges);
                return S_OK;
            }
        }
    } 
    else
    {
        listChanges.grfChange = TCT_TOOMANYCHANGES; 
        listChanges.Index = NULINDEX;
        m_counter.Increment(listChanges);
    }
    
    return S_OK;
}


//                                                 IBrowseDataProviderEvents
//==========================================================================


