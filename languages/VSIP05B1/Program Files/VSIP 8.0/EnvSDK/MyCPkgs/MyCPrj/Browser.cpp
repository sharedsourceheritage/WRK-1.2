
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Browser.cpp:
//
//////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "PrjInc.h" 

CBrowseCounter::CBrowseCounter() :
    m_uCounter(0),
    m_cChanges(0),
    m_fIsCounterDirty(FALSE)
{
    m_listChanges.Index     = NULINDEX;
    m_listChanges.grfChange = TCT_NOCHANGE;
}


CBrowseCounter::~CBrowseCounter()
{
}

STDMETHODIMP CBrowseCounter::ResetChanges()
{
    m_cChanges = 0;
    m_fIsCounterDirty = FALSE;
    m_listChanges.Index     = NULINDEX;
    m_listChanges.grfChange = TCT_NOCHANGE;
    return S_OK;
}


STDMETHODIMP CBrowseCounter::Increment(
    /* [in] */  VSTREELISTITEMCHANGE listChanges)
{
    if (m_fIsCounterDirty)
    {
        m_listChanges.Index     = NULINDEX;
        m_listChanges.grfChange = TCT_TOOMANYCHANGES;
    }
    else
    {
        m_listChanges = listChanges; 
    }

    m_fIsCounterDirty = TRUE;
    m_uCounter ++;
    m_cChanges ++;

    return S_OK;
};


STDMETHODIMP CBrowseCounter::UpdateCounter(
    /* [out] */ ULONG *                 puCurUpdate,  
    /* [out] */ VSTREEITEMCHANGESMASK * pgrfChanges)
{
    ExpectedPtrRet(puCurUpdate);
    ExpectedPtrRet(pgrfChanges);

    *puCurUpdate = m_uCounter;
    *pgrfChanges = m_listChanges.grfChange;
    return S_OK;
};


STDMETHODIMP CBrowseCounter::GetListChanges(
    /*[in,out]                 */ ULONG *                pcChanges, 
    /*[in, size_is(*pcChanges)]*/ VSTREELISTITEMCHANGE * prgListChanges)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseCounter::GetListChanges ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pcChanges);
    ASSERT(m_cChanges == 1);
    ASSERT(m_fIsCounterDirty);
    ASSERT((m_listChanges.Index != NULINDEX) || 
           (m_listChanges.grfChange == TCT_TOOMANYCHANGES) );
    ASSERT(m_listChanges.grfChange != TCT_NOCHANGE);

    if (!prgListChanges)
    {
        *pcChanges = m_cChanges;
        return S_OK;
    }

    ASSERT(*pcChanges == 1);
    prgListChanges[0] = m_listChanges;
    m_fIsCounterDirty = FALSE;
    m_cChanges = 0;
    m_listChanges.Index = NULINDEX;
    m_listChanges.grfChange = TCT_NOCHANGE;

    return S_OK;
}


//==========================================================================
//                                                construct, init , destruct

HRESULT CBrowseNode::CreateInstance(
    /* [in] */ ILibraryItem*    pILibraryItem,
    /* [in] */ BSTR             bstrName,
    /* [in] */ BROWSE_NODE_TYPE eType,
    /* [in] */ VSITEMID         itemId,
    /* [in] */ ULONG            uLineNumber,
    /* [out]*/ CBrowseNode **   ppCBrowseNode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::CreateInstance \n"));

    ExpectedPtrRet(ppCBrowseNode);
    InitParam(ppCBrowseNode);

    CBrowseNode* pNode = new CBrowseNode;
    if (pNode == NULL) 
        return E_OUTOFMEMORY;

    HRESULT hr = pNode->Init(pILibraryItem, bstrName, eType, itemId, uLineNumber);
    IfFailGo(hr);

    *ppCBrowseNode = pNode;
    return hr;

Error:
    delete pNode;

    return hr;
}


CBrowseNode::CBrowseNode()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CBrowseNode::CBrowseNode , this = 0x%x \n"), this );
}

CBrowseNode::~CBrowseNode()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CBrowseNode::~CBrowseNode , this = 0x%x \n"), this );
}

STDMETHODIMP CBrowseNode::Init(
            /* [in] */ ILibraryItem*    pILibraryItem,
            /* [in] */ BSTR             bstrName,
            /* [in] */ BROWSE_NODE_TYPE eType,
            /* [in] */ VSITEMID         itemId,
            /* [in] */ ULONG            uLineNumber)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::Init ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pILibraryItem);

    m_pILibraryItem = pILibraryItem;
    // addref is not called here - the browse node is a child of the LibraryItem 
    // and its lifetime is controlled by the ILibraryItem lifetime

    m_cbstrName      = bstrName;
    if (m_cbstrName.Length() == 0)
    {
        ASSERT(FALSE);
        return E_INVALIDARG;
    }

    m_eType        = eType;
    m_itemId       = itemId;
    m_uLineNumber  = uLineNumber;

    return S_OK; 
};

//                                                construct, init , destruct
//==========================================================================


STDMETHODIMP CBrowseNode::GetLibraryItem(
        /* [out] */ ILibraryItem** ppILibraryItem)
{
    ExpectedPtrRet(ppILibraryItem);

    *ppILibraryItem = m_pILibraryItem;
    (*ppILibraryItem)->AddRef();
    return S_OK;
}

STDMETHODIMP CBrowseNode::GetItemId(
    /* [out]  */ VSITEMID* pitemId)
{
    ExpectedPtrRet(pitemId);
    *pitemId = m_itemId;
    return S_OK;
}


STDMETHODIMP CBrowseNode::GetText(
    /* [in]  */ VSTREETEXTOPTIONS tto, 
    /* [out] */ const WCHAR **    ppszText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::GetText ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(ppszText);

    *ppszText = (WCHAR *) m_cbstrName; 

    return S_OK;
}

STDMETHODIMP CBrowseNode::GetTipText(
    /* [in] */ VSTREETOOLTIPTYPE eTipType,                                       
    /* [out] */ const WCHAR ** ppszText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::GetTipText ")
        _T(", this = 0x%x \n"), this );

    return E_NOTIMPL;
}

STDMETHODIMP CBrowseNode::GetDisplayData(
    /* [out] */ VSTREEDISPLAYDATA * pData)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::GetDisplayData ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pData);

    GetDisplayStateFromType(&(pData->State));
    GetGlyphIndexFromType(&(pData->Image));
    pData->SelectedImage = pData->Image;

    return S_OK;
}
STDMETHODIMP CBrowseNode::GetDisplayStateFromType(
          VSTREEDISPLAYSTATE * pState)
{ 
    switch (m_eType) 
    {
        case BNT_PHYSICALCONTAINER:
        case BNT_CLASS:
            *pState = TDS_BOLD;
            break;
        default:
            break;
    }
    return S_OK;
}

STDMETHODIMP CBrowseNode::GetGlyphIndexFromType(
          USHORT* pBmpIndex)

{
    // the value of the type is the index in the bitmap currently 
    *pBmpIndex = (INT)m_eType - 1;
    return S_OK;
}


STDMETHODIMP CBrowseNode::GetNavigationInfo(
    /* [in, out]*/ VSOBNAVIGATIONINFO2 * pobNav)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::GetNavigationInfo ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pobNav);

    HRESULT hr = S_OK;
   
    hr = m_pILibraryItem->GetText(TTO_DEFAULT, (const WCHAR **)&(pobNav->pszLibName));
    IfFailRet(hr);
    ExpectedPtrRet(pobNav->pName);
    hr = GetText(TTO_DEFAULT, (const WCHAR **) &(pobNav->pName->pszName));      
    IfFailRet(hr);

    return hr;
}


STDMETHODIMP CBrowseNode::GetSourceContext(
    /* [out] */ const WCHAR **pszFileName, 
    /* [out] */ ULONG *pulLineNum)
{
    ATLTRACENOTIMPL(
                    _T(": CBrowseNode::GetSourceContext"));
}


STDMETHODIMP CBrowseNode::CountSourceItems(
    /* [out] */ IVsHierarchy **ppHier, 
    /* [out] */ VSITEMID *pitemid, 
    /*[out, retval]*/ ULONG *pcItems)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::CountSourceItems ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pcItems);
    HRESULT hr;

    if ( (m_itemId == VSITEMID_ROOT)  )
    {
        *pcItems = 0;
    }
    *pcItems = 1;
    if (ppHier)
    {
        // get the gierarchy
        CComPtr<IVsHierarchy> srpIVsHierarchy;
        hr = m_pILibraryItem->GetHierarchy(&srpIVsHierarchy);
        IfFailRet(hr);
        hr = srpIVsHierarchy.CopyTo(ppHier);
        IfFailRet(hr);
    }

    if (pitemid)
    {
        *pitemid = m_itemId;
    }

    return S_OK;
}


STDMETHODIMP CBrowseNode::GoToSource(
    /* [in]  */ VSOBJGOTOSRCTYPE eSrcType)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::GoToSource ")
        _T(", this = 0x%x \n"), this );

    HRESULT hr = S_OK;
 
    CComBSTR cbstrSrcFullName;

    // get the gierarchy
    CComPtr<IVsHierarchy> srpIVsHierarchy;
    hr = m_pILibraryItem->GetHierarchy(&srpIVsHierarchy);
    IfFailRet(hr);

    CComPtr<IVsProject> srpIVsProject;
    hr = srpIVsHierarchy->QueryInterface(IID_IVsProject, (void**) &srpIVsProject);
    IfFailRet(hr);
    hr = srpIVsProject->GetMkDocument(m_itemId, &cbstrSrcFullName);
    IfFailRet(hr);

    //Does this file exist? 
    if (GetFileAttributesW(cbstrSrcFullName) == -1)
        return E_FAIL;

    CComPtr<IVsUIHierarchy> srpIVsUIHierarchy;

    hr = srpIVsHierarchy->QueryInterface(&srpIVsUIHierarchy);
    IfFailRet(hr);

    VSITEMID itemid = NULL;

    CComPtr<IVsUIShellOpenDocument> srpIVsUIShellOpenDocument;
    hr = _VxModule.QueryService(
                SID_SVsUIShellOpenDocument, 
                IID_IVsUIShellOpenDocument,
                reinterpret_cast<void **>(&srpIVsUIShellOpenDocument));
    IfFailRet(hr);

    CComPtr<IVsWindowFrame> srpIVsWindowFrame;
    BOOL bIsOpen = FALSE;
    hr = srpIVsUIShellOpenDocument->IsDocumentOpen(
                srpIVsUIHierarchy, 
                itemid, 
                cbstrSrcFullName, 
                GUID_NULL, 
                0, 
                NULL, 
                NULL, 
                &srpIVsWindowFrame, 
                &bIsOpen);
    IfFailRet(hr);

    if (!bIsOpen)
    {
        hr = srpIVsUIShellOpenDocument->OpenDocumentViaProject(
                cbstrSrcFullName, 
                LOGVIEWID_Primary, 
                NULL, 
                NULL, 
                NULL, 
                &srpIVsWindowFrame);
        IfFailRet(hr);
    }

    if (srpIVsWindowFrame)
    {
        srpIVsWindowFrame->Show();

        IUnknown *pUnk;
        hr = srpIVsWindowFrame->QueryViewInterface(__uuidof(IVsCodeWindow), (void**)&pUnk);
        IfFailRet(hr);

        CComQIPtr<IVsCodeWindow> spCodeWnd(pUnk);
        pUnk->Release();
        if (!spCodeWnd)
            return E_FAIL;
        CComPtr<IVsTextView> srpIVsTextView;
        hr = spCodeWnd->GetPrimaryView(&srpIVsTextView);
        IfFailRet(hr);

        // Set the caret and center the line in the view
        hr = srpIVsTextView->SetCaretPos (m_uLineNumber, 0);
        hr = srpIVsTextView->CenterLines (m_uLineNumber, 1);
    }

    return S_OK;

}


STDMETHODIMP CBrowseNode::FillDescription(
    /* [in]  */ IVsObjectBrowserDescription2 *pobDesc)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::FillDescription ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pobDesc);

    pobDesc->AddDescriptionText((LPCWSTR)m_cbstrName, OBDS_NAME, NULL);
    
    return S_OK;
}


STDMETHODIMP CBrowseNode::GetCategoryField(
    /* [in]  */ LIB_CATEGORY    eCategory, 
    /*[out,retval]*/ DWORD*     pField)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::GetCategoryField  ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pField);
    *pField = 0;

    HRESULT hr = S_OK;

    switch (eCategory)
    {
    case LC_MEMBERTYPE:
        switch (m_eType)
        {
        case BNT_FUNCTION:
            *pField = LCMT_FUNCTION;
            break;
        case BNT_VARIABLE:
            *pField = LCMT_VARIABLE;
            break;
        }
        break;
    default:
        ASSERT(FALSE); // category not supported
        break;
    }

    return hr;
}

STDMETHODIMP CBrowseNode::UpdateName(
    /* [in]  */ BSTR    bstrName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBrowseNode::UpdateName  ")
        _T(", this = 0x%x \n"), this );

    m_cbstrName = bstrName;
    return S_OK;
}


IBrowseDataProviderImpl::IBrowseDataProviderImpl() 
{
}


IBrowseDataProviderImpl::~IBrowseDataProviderImpl()
{
}


STDMETHODIMP IBrowseDataProviderImpl::AdviseBrowseDataProviderEvents(
    /* [in]   */ IBrowseDataProviderEvents* pIBrowseDataProviderEvents, 
    /* [out]  */ VSCOOKIE *    pdwCookie)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": IBrowseDataProviderImpl::AdviseBrowseDataProviderEvents ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pIBrowseDataProviderEvents);
    ExpectedPtrRet(pdwCookie);
    InitParam(pdwCookie);

    // Do not addref because SetAdvise() does so automatically
    HRESULT hr = m_alBrowseDataProviderEvents.SetAdvise(
                pIBrowseDataProviderEvents, 
                pdwCookie);
    return hr;
}


STDMETHODIMP IBrowseDataProviderImpl::UnadviseBrowseDataProviderEvents(
    /* [in]  */ VSCOOKIE     dwCookie)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": IBrowseDataProviderImpl::UnadviseBrowseDataProviderEvents ")
        _T(", this = 0x%x \n"), this );

    return m_alBrowseDataProviderEvents.UnAdvise(dwCookie);

};


STDMETHODIMP IBrowseDataProviderImpl::NotifyOnBrowseDataAdded(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": IBrowseDataProviderImpl::NotifyOnBrowseDataAdded ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pCBrowseNode);

    for (int i = 0; i < m_alBrowseDataProviderEvents.GetCount(); ++i)
    {
        HRESULT hr = m_alBrowseDataProviderEvents.GetAdviseSink(i)->OnBrowseDataAdded(eListType, pCBrowseNode);
        ASSERT(SUCCEEDED(hr));
    }
    return S_OK;
}


STDMETHODIMP IBrowseDataProviderImpl::NotifyOnBrowseDataRemoved(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": IBrowseDataProviderImpl::NotifyOnBrowseDataRemoved ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pCBrowseNode);


    for (int i = 0; i < m_alBrowseDataProviderEvents.GetCount(); ++i)
    {
        HRESULT hr = m_alBrowseDataProviderEvents.GetAdviseSink(i)->OnBrowseDataRemoved(eListType, pCBrowseNode);
        ASSERT(SUCCEEDED(hr));
    }
    return S_OK;
}

STDMETHODIMP IBrowseDataProviderImpl::NotifyOnBrowseDataPropertyChanged(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": IBrowseDataProviderImpl::NotifyOnBrowseDataPropertyChanged ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pCBrowseNode);


    for (int i = 0; i < m_alBrowseDataProviderEvents.GetCount(); ++i)
    {
        HRESULT hr = m_alBrowseDataProviderEvents.GetAdviseSink(i)->OnBrowseDataPropertyChanged(eListType, pCBrowseNode);
        ASSERT(SUCCEEDED(hr));
    }
    return S_OK;
}

//==========================================================================
//                                                construct, init , destruct
 
HRESULT CLibraryItem::CreateInstance(
    /* [in]  */ IVsLibrary*    pIVsLibrary,
    /* [in]  */ IVsHierarchy*  pIVsHierarchy,
    /* [out] */ CComObject<CLibraryItem> ** ppCLibraryItem)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::CreateInstance \n"));

    ExpectedPtrRet(pIVsLibrary);
    ExpectedPtrRet(pIVsHierarchy);
    ExpectedPtrRet(ppCLibraryItem);
    InitParam(ppCLibraryItem);

    CComObject<CLibraryItem>* pco = NULL;
    HRESULT hr = CComObject<CLibraryItem>::CreateInstance(&pco);
    IfFailRet(hr);

    ASSERT(pco != NULL);
    pco->AddRef();
    hr = pco->Init(pIVsLibrary, pIVsHierarchy);
    IfFailGo(hr);

    *ppCLibraryItem = pco;
    return hr;

Error:
    if (pco)
        pco->Release();

    return hr;
}


CLibraryItem::CLibraryItem() :
    m_dwIVsHierarchyEventsCookie(NULL)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CLibraryItem::CLibraryItem , this = 0x%x \n"), this );
}


STDMETHODIMP CLibraryItem::Init(
    /* [in]  */ IVsLibrary*    pIVsLibrary,
    /* [in]  */ IVsHierarchy*  pIVsHierarchy)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::Init ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pIVsLibrary);
    ExpectedPtrRet(pIVsHierarchy);

    HRESULT hr;

    m_srpIVsLibrary   = pIVsLibrary;
    m_srpIVsHierarchy = pIVsHierarchy;

    m_eCheckState     = LCS_CHECKED;
    fIsBrowseNodeArrayInitialized = FALSE;
   
    //Advise Events on the project
    hr = m_srpIVsHierarchy->AdviseHierarchyEvents(
        static_cast<IVsHierarchyEvents *>(this), 
        &m_dwIVsHierarchyEventsCookie);
    IfFailRet(hr);

    //Get the Name
    CComVariant cvarName;
    hr = m_srpIVsHierarchy->GetProperty(VSITEMID_ROOT, VSHPROPID_Name, &cvarName);
    IfFailRet(hr);

    return CBrowseNode::Init(
        static_cast<ILibraryItem *>(this), 
        cvarName.bstrVal,
        BNT_PHYSICALCONTAINER,
        VSITEMID_ROOT,
        0);

};


CLibraryItem::~CLibraryItem()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CLibraryItem::~CLibraryItem , this = 0x%x \n"), this );

    // release the array
    ULONG cBrowseNodes = GetItemCount();
    for (ULONG uIndex = 0 ; uIndex < cBrowseNodes; uIndex++)
    {
        NotifyOnBrowseDataRemoved(LLT_CLASSES, m_rgpBrowseNode[uIndex]);
        delete m_rgpBrowseNode[uIndex];
    }
    m_rgpBrowseNode.RemoveAll();
    
}


STDMETHODIMP CLibraryItem::Close()
{
    HRESULT hr = S_OK;
    if (m_dwIVsHierarchyEventsCookie)
    {
        hr = m_srpIVsHierarchy->UnadviseHierarchyEvents(
            m_dwIVsHierarchyEventsCookie);
        m_dwIVsHierarchyEventsCookie = 0;
    }

    m_srpIVsLibrary.Release();
    m_srpIVsHierarchy.Release();
    return hr;
}

//                                                construct, init , destruct
//==========================================================================



//==========================================================================
//                                                              ILibraryItem


STDMETHODIMP CLibraryItem::GetHierarchy(
        /* [out]  */ IVsHierarchy **  ppIVsHierarchy)
{
    ExpectedPtrRet(ppIVsHierarchy);

    *ppIVsHierarchy = m_srpIVsHierarchy;

    if (*ppIVsHierarchy)
        (*ppIVsHierarchy)->AddRef();

    return S_OK;
}



STDMETHODIMP CLibraryItem::ToggleState()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::ToggleState ")
        _T(", this = 0x%x \n"), this );

    if (m_eCheckState == LCS_CHECKED)
    {
        m_eCheckState = LCS_UNCHECKED;
    }
    else if (m_eCheckState == LCS_UNCHECKED)
    {
        m_eCheckState = LCS_CHECKED;
    }
    else 
    {
        ASSERT(FALSE);
        return E_FAIL;
    }

    return S_OK;
}


STDMETHODIMP CLibraryItem::GetCheckState(
    /* [out] */ LIB_CHECKSTATE *pstate)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::GetCheckState ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pstate);
    *pstate = m_eCheckState;
    return S_OK;
};

 
STDMETHODIMP CLibraryItem::GetText(
    /* [in]  */ VSTREETEXTOPTIONS tto, 
    /* [out] */ const WCHAR **    ppszText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::GetText ")
        _T(", this = 0x%x \n"), this );

    return CBrowseNode::GetText(tto, ppszText);
}

//                                                              ILibraryItem
//==========================================================================


//==========================================================================
//                                                       IBrowseDataProvider
STDMETHODIMP CLibraryItem::AddBrowseNodesToArray(
    /* [in]      */ LIB_LISTTYPE         eListType, 
    /* [in,out]  */ BrowseNodeArray*     pBrowseNodeArray)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::AddBrowseNodesToArray /IBrowseDataProvider/ ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pBrowseNodeArray);
        
    HRESULT hr = S_OK;
    
    if (! fIsBrowseNodeArrayInitialized)
    {
        hr = InitBrowseNodeArray();
        IfFailRet(hr);
    }

    ULONG cBrowseNodes = GetItemCount();
    switch (eListType)
    {
    case LLT_CLASSES:
        for (ULONG uIndex = 0 ; uIndex < cBrowseNodes; uIndex++)
        {
            pBrowseNodeArray->Add(m_rgpBrowseNode[uIndex]);
        }
        break;
    default:
        // nothing for now
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CLibraryItem::AddBrowseNodesToArray /IBrowseDataProvider/ ")
            _T(", eListType = 0x%x \n"), eListType );
         break;
    }
    return hr;
}
//                                                       IBrowseDataProvider
//==========================================================================

//==========================================================================
//                                                        IVsHierarchyEvents
STDMETHODIMP CLibraryItem::OnItemAdded(
    /* [in] */ VSITEMID itemidParent, 
    /* [in] */ VSITEMID itemidSiblingPrev, 
    /* [in] */ VSITEMID itemidAdded)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::OnItemAdded /IVsHierarchyEvents/ ")
        _T(", this = 0x%x \n"), this );
     
    // check if the node array is init-ed 
    // if not - do not bother now - we will get the info during the array init
    if (! fIsBrowseNodeArrayInitialized)
        return S_OK;
    
    // check if we have the item
    ULONG cBrowseNodes = GetItemCount();
    for (ULONG uIndex = 0 ; uIndex < cBrowseNodes; uIndex++)
    {
        VSITEMID itemIdCur;
        m_rgpBrowseNode[uIndex]->GetItemId(&itemIdCur);
        if (itemidAdded == itemIdCur)
        {
            // we have it already but some info could be wrong - let's refresh it
            OnItemDeleted(itemIdCur);
            OnItemAdded(itemidParent, itemidSiblingPrev, itemidAdded);
            return S_OK;
        }
    }

    HRESULT hr = S_OK;
    
    CComBSTR cbstrSrcFullName;
    CComPtr<IVsProject> srpIVsProject;
    hr = m_srpIVsHierarchy->QueryInterface(IID_IVsProject, (void**) &srpIVsProject);
    IfFailRet(hr);
    hr = srpIVsProject->GetMkDocument(itemidAdded, &cbstrSrcFullName);
    IfFailRet(hr);

    BOOL fMycFile = FALSE;
    CComBSTR cbstrDisplayName;
    hr = IsFileMyc(cbstrSrcFullName, &fMycFile, &cbstrDisplayName);
    IfFailRet(hr);

    if (fMycFile)
    {
        // create a new browse node
        CBrowseNode* pBrowseNode = NULL;
        hr = CBrowseNode::CreateInstance(
            this,
            cbstrDisplayName,
            BNT_CLASS,
            itemidAdded,
            0,
            &pBrowseNode);
        IfFailRet(hr);

        // update the array
        m_rgpBrowseNode.Add(pBrowseNode);

        //notify the library so it can update its children lists
        CComPtr<IBrowseDataProviderEvents> srpIBrowseDataProviderEvents;
        hr = m_srpIVsLibrary->QueryInterface(
            IID_IBrowseDataProviderEvents,
            (void**) &srpIBrowseDataProviderEvents);
        if (SUCCEEDED(hr))
            srpIBrowseDataProviderEvents->OnBrowseDataAdded(LLT_CLASSES, pBrowseNode);

        // inform the lists 
        // for us each new file is a new class
        NotifyOnBrowseDataAdded(LLT_CLASSES,pBrowseNode);
    }

    return hr;
}

STDMETHODIMP CLibraryItem::OnItemsAppended(
    /* [in] */ VSITEMID itemidParent)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::OnItemsAppended /IVsHierarchyEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}


STDMETHODIMP CLibraryItem::OnItemDeleted(
    /* [in] */ VSITEMID itemid)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::OnItemDeleted /IVsHierarchyEvents/ ")
        _T(", this = 0x%x \n"), this );

    HRESULT hr = S_OK;

    // find the browse node
    ULONG cBrowseNodes = GetItemCount();
    for (ULONG uIndex = 0 ; uIndex < cBrowseNodes; uIndex++)
    {
        VSITEMID itemIdCur;
        m_rgpBrowseNode[uIndex]->GetItemId(&itemIdCur);
        if (itemid == itemIdCur)
        {
            CBrowseNode* pBrowseNode = m_rgpBrowseNode[uIndex];

            //notify the library so it can update its children lists
            CComPtr<IBrowseDataProviderEvents> srpIBrowseDataProviderEvents;
            hr = m_srpIVsLibrary->QueryInterface(
                IID_IBrowseDataProviderEvents,
                (void**) &srpIBrowseDataProviderEvents);
            if (SUCCEEDED(hr))
                srpIBrowseDataProviderEvents->OnBrowseDataRemoved(LLT_CLASSES, pBrowseNode);

            // notify the lists
            NotifyOnBrowseDataRemoved(LLT_CLASSES, pBrowseNode);

            // remove the node
            pBrowseNode = m_rgpBrowseNode[uIndex];
            m_rgpBrowseNode.RemoveAt(uIndex);

            // delete the node
            delete pBrowseNode;
            break;
        }
    }

    return S_OK;
}



STDMETHODIMP CLibraryItem::OnPropertyChanged(
    /* [in] */ VSITEMID itemid, 
    /* [in] */ VSHPROPID propid, 
    /* [in] */ DWORD flags) 
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::OnPropertyChanged /IVsHierarchyEvents/ ")
        _T(", this = 0x%x \n"), this );
    return S_OK;
}

STDMETHODIMP CLibraryItem::OnInvalidateItems(
    /* [in] */ VSITEMID itemidParent)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::OnInvalidateItems /IVsHierarchyEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}

STDMETHODIMP CLibraryItem::OnInvalidateIcon(
    /* [in] */ HICON hicon)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::OnInvalidateIcon /IVsHierarchyEvents/ ")
        _T(", this = 0x%x \n"), this );

    return S_OK;
}

//                                                        IVsHierarchyEvents
//==========================================================================



STDMETHODIMP CLibraryItem::GetDisplayData(
    /* [in]  */ BOOL fIsLibraryChecked,
    /* [out] */ VSTREEDISPLAYDATA * pData)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::GetDisplayData ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pData);

    VSTREEDISPLAYDATA & Data = *pData;
    LIB_CHECKSTATE lcs = m_eCheckState;

    Data.Image = 0;
    Data.SelectedImage = 0;
    Data.State = 0;

    if ( fIsLibraryChecked && (lcs != LCS_UNCHECKED) )
            Data.State |= TDS_BOLD;

    VSTDDSetUserState(Data,lcs);
    return S_OK;
}


STDMETHODIMP_(ULONG) CLibraryItem::GetItemCount()
{
    return m_rgpBrowseNode.GetSize();
};


STDMETHODIMP CLibraryItem::InitBrowseNodeArray()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CLibraryItem::InitBrowseNodeArray ")
        _T(", this = 0x%x \n"), this );

    ASSERT(m_srpIVsHierarchy != NULL);
    ASSERT(!fIsBrowseNodeArrayInitialized);

    // here we rely on the following assumptions:
    // - the name of the file is the name of the class
    // - the list of the files in the project is flat

    HRESULT  hr;

    CComPtr<IVsProject> srpIVsProject;
    hr = m_srpIVsHierarchy->QueryInterface(IID_IVsProject, (void**) &srpIVsProject);
    IfFailRet(hr);

	// Now iterate through the project children
	CComVariant cvarItemId;
	hr = m_srpIVsHierarchy->GetProperty(VSITEMID_ROOT, VSHPROPID_FirstChild, &cvarItemId);
	while (SUCCEEDED(hr) && cvarItemId.lVal != VSITEMID_NIL)
	{
        // get the name
        CComBSTR cbstrSrcFullName;
        hr = srpIVsProject->GetMkDocument(cvarItemId.lVal, &cbstrSrcFullName);
        if (SUCCEEDED(hr))
        {
            CComBSTR cbstrDisplayName;
            BOOL     fMycFile = FALSE;
            hr = IsFileMyc(cbstrSrcFullName, &fMycFile, &cbstrDisplayName);

            if (SUCCEEDED(hr) && fMycFile)
            {           
                // create a new browse node
                CBrowseNode* pBrowseNode = NULL;
                hr = CBrowseNode::CreateInstance(
                    this,
                    cbstrDisplayName,
                    BNT_CLASS,
                    cvarItemId.lVal,
                    0,
                    &pBrowseNode);
                IfFailRet(hr);
                m_rgpBrowseNode.Add(pBrowseNode);
            }
        }
		hr = m_srpIVsHierarchy->GetProperty(cvarItemId.lVal, VSHPROPID_NextSibling, &cvarItemId);
    }
    
    fIsBrowseNodeArrayInitialized = TRUE;
    return S_OK;
}


STDMETHODIMP CLibraryItem::IsFileMyc(
    /* [in]  */ BSTR  bstrFileFullName,
    /* [out] */ BOOL* pfMycFile,
    /* [out] */ BSTR* pbstrDisplayName)
{
    ExpectedPtrRet(bstrFileFullName);
    ExpectedPtrRet(pfMycFile);
    ExpectedPtrRet(pbstrDisplayName);
    InitParam(pbstrDisplayName);
    *pfMycFile = FALSE;

    CComBSTR cbstrDisplayName;
    WCHAR szFName[_MAX_FNAME];
    WCHAR szDrive[_MAX_DRIVE];
    WCHAR szDir[_MAX_DIR];
    WCHAR szExt[_MAX_EXT];
    _wsplitpath(bstrFileFullName, szDrive, szDir, szFName, szExt);
    
    // check the extension
    if ( _wcsicmp(szExt, L".myc") != 0)
        return S_OK;

    cbstrDisplayName = szFName;
    *pbstrDisplayName = cbstrDisplayName.Detach();
    *pfMycFile = TRUE;
    return (*pbstrDisplayName) ? S_OK : E_OUTOFMEMORY;

}
