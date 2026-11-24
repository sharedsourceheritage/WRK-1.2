
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential
//*****************************************************************************
// TriHost.cpp
//
// Implementation of CTridentHost
// Implements the client site for mshtml docobject, so that the docobject may
// be hosted as a child window of a given hwnd.
//
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "TriHost.h"

//*****************************************************************************
// CTridentHost Constructor/Destructor
//*****************************************************************************

CTridentHost::CTridentHost()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::CTridentHost \n") );

    m_hwndParent = NULL;
    m_dwAdviseCookie = 0;
}

CTridentHost::~CTridentHost()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::~CTridentHost \n") );

    _ASSERTE(!m_srpUnkTrident);
    _ASSERTE(!m_srpObjTrident);
    _ASSERTE(!m_srpDocView);
}


//*****************************************************************************
// CTridentHost Operations
//*****************************************************************************

HRESULT CTridentHost::CreateTridentHost(HWND hwndParent)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::CreateTridentHost \n") );

    _ASSERTE(IsWindow(hwndParent));
	if (!hwndParent)
		return E_FAIL;

    CComPtr<IPersistStreamInit> srpPSI;
    HRESULT hr = E_FAIL;

    m_hwndParent = hwndParent;

    // create the mshtml document object
    hr = CreateDocument();
    IfFailGo(hr);

    // initialize the document to a blank document
    hr = m_srpUnkTrident->QueryInterface(IID_IPersistStreamInit,
                                         (void**)&srpPSI);
    IfFailGo(hr);

    hr = srpPSI->InitNew();
    IfFailGo(hr);

OnError:
    if (FAILED(hr))
    {
        CloseDocument();
    }
    return hr;
}

HRESULT CTridentHost::CreateTridentHost(HWND hwndParent, LPCOLESTR lpszURL)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::CreateTridentHost \n") );

    _ASSERTE(IsWindow(hwndParent));

    CComPtr<IPersistMoniker> srpPMk;
    CComPtr<IMoniker> srpMk;
    CComPtr<IBindCtx> srpBindCtx;
    HRESULT hr = E_FAIL;

    m_hwndParent = hwndParent;

    // create a bind context for loading the url
    hr = CreateBindCtx(0, &srpBindCtx);
    IfFailGo(hr);

    // create a moniker representing the url
    hr = CreateURLMoniker(NULL, lpszURL, &srpMk);
    IfFailGo(hr);

    // create the mshtml document object
    hr = CreateDocument();
    IfFailGo(hr);

    // initialize the document with the specified url
    hr = m_srpUnkTrident->QueryInterface(IID_IPersistMoniker,
                                         (void**)&srpPMk);
    IfFailGo(hr);

    hr = srpPMk->Load(FALSE, srpMk, srpBindCtx, STGM_READ);
    IfFailGo(hr);

OnError:
    if (FAILED(hr))
    {
        CloseDocument();
    }
    return hr;
}

HRESULT CTridentHost::CloseTridentHost(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::CreateTridentHost \n") );

    // deactivate and release the mshtml document
    CloseDocument();

    return S_OK;
}

HRESULT CTridentHost::ActivateTrident()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::ActivateTrident \n") );

    ExpectedPtrRet(m_srpUnkTrident);

    // activate the document and make it visible
    return RunAndShowDocument();
}

HRESULT CTridentHost::GetTrident(IHTMLDocument2** ppTrident)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetTrident \n") );

    _ASSERTE(ppTrident);

    InitParam(ppTrident);
    HRESULT hr = E_UNEXPECTED;

    if (m_srpUnkTrident)
    {
        hr = m_srpUnkTrident->QueryInterface(IID_IHTMLDocument2, (void**)ppTrident);
    }
    return hr;
}

void CTridentHost::SetPosition(long x, long y, long cx, long cy)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::SetPosition \n") );

    if (m_srpDocView)
    {
        RECT rc;
        rc.left = x;
        rc.top = y;
        rc.right = cx;
        rc.bottom = cy;
        m_srpDocView->SetRect(&rc);
    }
}


//*****************************************************************************
// CTridentHost IOleClientSite Implementation
//*****************************************************************************

STDMETHODIMP CTridentHost::SaveObject(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::SaveObject \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::GetMoniker(
                    /*[in] */ DWORD      dwAssign,
                    /*[in] */ DWORD      dwWhichMoniker,
                    /*[out]*/ IMoniker** ppMk)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetMoniker \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::GetContainer(
                    /*[out]*/ IOleContainer** ppContainer)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetContainer \n") );

    return E_NOINTERFACE;
}

STDMETHODIMP CTridentHost::ShowObject(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::ShowObject \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::OnShowWindow(
                    /*[in]*/ BOOL fShow)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnShowWindow \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::RequestNewObjectLayout(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::RequestNewObjectLayout \n") );

    return E_NOTIMPL;
}


//*****************************************************************************
// CTridentHost IOleDocumentSite Implementation
//*****************************************************************************

STDMETHODIMP CTridentHost::ActivateMe(
                    /*[in]*/ IOleDocumentView* pViewToActivate)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::ActivateMe \n") );

    if (!pViewToActivate)
        return E_INVALIDARG;

    RECT r;
    GetClientRect(m_hwndParent, &r);

    m_srpDocView = pViewToActivate;

    m_srpDocView->SetInPlaceSite(this);
    m_srpDocView->UIActivate(TRUE);
    m_srpDocView->SetRect(&r);
    m_srpDocView->Show(TRUE);

    return S_OK;
}


//*****************************************************************************
// CTridentHost IOleInPlaceSite Implementation
//*****************************************************************************

STDMETHODIMP CTridentHost::CanInPlaceActivate(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::CanInPlaceActivate \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::OnInPlaceActivate(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnInPlaceActivate \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::OnUIActivate(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnUIActivate \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::GetWindowContext(
                    /*[out]*/ IOleInPlaceFrame**    ppFrame,
                    /*[out]*/ IOleInPlaceUIWindow** ppDoc,
                    /*[out]*/ LPRECT                lprcPosRect,
                    /*[out]*/ LPRECT                lprcClipRect,
                    /*[out]*/ LPOLEINPLACEFRAMEINFO lpFrameInfo)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetWindowContext \n") );

    ExpectedExprRet(ppFrame && ppDoc && lprcPosRect &&
                    lprcClipRect && lpFrameInfo);

    RECT rect;

    *ppFrame = static_cast<IOleInPlaceFrame *>(this);
    (*ppFrame)->AddRef();

    *ppDoc = NULL;

    GetClientRect(m_hwndParent, &rect);
    lprcPosRect->left = 0;
    lprcPosRect->top = 0;
    lprcPosRect->right = rect.right;
    lprcPosRect->bottom = rect.bottom;

    *lprcClipRect = *lprcPosRect;
 
    lpFrameInfo->cb = sizeof(OLEINPLACEFRAMEINFO);
    lpFrameInfo->fMDIApp = FALSE;
    lpFrameInfo->hwndFrame = m_hwndParent;
    lpFrameInfo->haccel = NULL;
    lpFrameInfo->cAccelEntries = 0;

    return S_OK;
}

STDMETHODIMP CTridentHost::Scroll(
                    /*[in]*/ SIZE scrollExtent)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::Scroll \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::OnUIDeactivate(
                    /*[in]*/ BOOL fUndoable)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnUIDeactivate \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::OnInPlaceDeactivate(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnInPlaceDeactivate \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::DiscardUndoState(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::DiscardUndoState \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::DeactivateAndUndo(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::DeactivateAndUndo \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::OnPosRectChange(
                    /*[in]*/ LPCRECT lprcPosRect)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnPosRectChange \n") );

    return S_OK;
}


//*****************************************************************************
// CTridentHost IOleWindow Implementation
//*****************************************************************************

STDMETHODIMP CTridentHost::GetWindow(
                    /*[out]*/ HWND* phwnd)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetWindow \n") );

    ExpectedPtrRet(phwnd);

    if (!IsWindow(m_hwndParent))
        return S_FALSE;

    *phwnd = m_hwndParent;
    return S_OK;
}

STDMETHODIMP CTridentHost::ContextSensitiveHelp(
                    /*[in]*/ BOOL fEnterMode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::ContextSensitiveHelp \n") );

    return E_NOTIMPL;
}


//*****************************************************************************
// CTridentHost IOleInPlaceUIWindow Implementation
//*****************************************************************************

STDMETHODIMP CTridentHost::GetBorder(
                    /*[out]*/ LPRECT lprectBorder)

{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetBorder \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::RequestBorderSpace(
                    /*[in]*/ LPCBORDERWIDTHS lpborderwidths)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::RequestBorderSpace \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::SetBorderSpace(
                    /*[in]*/ LPCBORDERWIDTHS lpborderwidths)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::SetBorderSpace \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::SetActiveObject(
                    /*[in]*/ IOleInPlaceActiveObject* pActiveObject,
                    /*[in]*/ LPCOLESTR lpszObjName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::SetActiveObject \n") );

    return E_NOTIMPL;
}


//*****************************************************************************
// CTridentHost IOleInPlaceFrame Implementation
//*****************************************************************************

STDMETHODIMP CTridentHost::InsertMenus(
                    /*[in]    */ HMENU                hmenuShared,
                    /*[in,out]*/ LPOLEMENUGROUPWIDTHS lpMenuWidths)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::InsertMenus \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::SetMenu(
                    /*[in]*/ HMENU    hmenuShared,
                    /*[in]*/ HOLEMENU holemenu,
                    /*[in]*/ HWND     hwndActiveObject)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::SetMenu \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::RemoveMenus(
                    /*[in]*/ HMENU hmenuShared)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::RemoveMenus \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::SetStatusText(
                    /*[in]*/ LPCOLESTR pszStatusText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::SetStatusText \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::EnableModeless(
                    /*[in]*/ BOOL fEnable)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::EnableModeless \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::TranslateAccelerator(
                    /*[in]*/ LPMSG lpmsg,
                    /*[in]*/ WORD  wID)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::TranslateAccelerator \n") );

    return S_FALSE;
}


//*****************************************************************************
// CTridentHost IAdviseSink Implementation
//*****************************************************************************

STDMETHODIMP_(void) CTridentHost::OnDataChange(
                    /*[in]*/ FORMATETC* pFormatetc,
                    /*[in]*/ STGMEDIUM* pmedium)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnDataChange \n") );

}

STDMETHODIMP_(void) CTridentHost::OnViewChange(
                    /*[in]*/ DWORD dwAspect,
                    /*[in]*/ LONG  lindex)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnViewChange \n") );

}

STDMETHODIMP_(void) CTridentHost::OnRename(
                    /*[in]*/ IMoniker* pmk)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnRename \n") );

}

STDMETHODIMP_(void) CTridentHost::OnSave(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnSave \n") );

}

STDMETHODIMP_(void) CTridentHost::OnClose(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnClose \n") );

}


//*****************************************************************************
// CTridentHost IDocHostUIHandler Implementation
//*****************************************************************************

STDMETHODIMP CTridentHost::GetHostInfo(
                    /*[in,out]*/ DOCHOSTUIINFO* pInfo)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetHostInfo \n") );

    _ASSERTE(pInfo);

    pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;
    pInfo->dwFlags = DOCHOSTUIFLAG_FLAT_SCROLLBAR | DOCHOSTUIFLAG_NO3DBORDER;

    return S_OK;
}

STDMETHODIMP CTridentHost::ShowUI(
                    /*[in]*/ DWORD dwID,
                    /*[in]*/ IOleInPlaceActiveObject* pActiveObject,
                    /*[in]*/ IOleCommandTarget* pCommandTarget,
                    /*[in]*/ IOleInPlaceFrame* pFrame,
                    /*[in]*/ IOleInPlaceUIWindow* pDoc)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::ShowUI \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::HideUI(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::HideUI \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::UpdateUI(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::UpdateUI \n") );

    return S_OK;
}

STDMETHODIMP CTridentHost::OnDocWindowActivate(
                    /*[in]*/ BOOL fActivate)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnDocWindowActivate \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::OnFrameWindowActivate(
                    /*[in]*/ BOOL fActivate)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::OnFrameWindowActivate \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::ResizeBorder(
                    /*[in]*/ LPCRECT prcBorder,
                    /*[in]*/ IOleInPlaceUIWindow* pUIWindow,
                    /*[in]*/ BOOL fRameWindow)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::ResizeBorder \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::TranslateAccelerator(
                    /*[in]*/ LPMSG       lpMsg,
                    /*[in]*/ const GUID* pguidCmdGroup, 
                    /*[in]*/ DWORD       nCmdID)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::TranslateAccelerator \n") );

    return S_FALSE;
}

STDMETHODIMP CTridentHost::ShowContextMenu(
                    /*[in]*/ DWORD dwID,
                    /*[in]*/ POINT* pptPosition,
                    /*[in]*/ IUnknown* pCommandTarget,
                    /*[in]*/ IDispatch* pDispatchObjectHit)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::ShowContextMenu \n") );

    return S_OK;    // suppress Trident's own context menu
}

STDMETHODIMP CTridentHost::GetOptionKeyPath(
                    /*[out]*/ BSTR* pbstrKey,
                    /*[in] */ DWORD dw)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetOptionKeyPath \n") );

    return S_FALSE;
}

STDMETHODIMP CTridentHost::GetDropTarget(
                    /*[in] */ IDropTarget* pDropTarget,
                    /*[out]*/ IDropTarget** ppDropTarget)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetDropTarget \n") );

    if (!ppDropTarget)
        return E_POINTER;

    // suppress dragging in anything
    *ppDropTarget = NULL;
    return S_OK;
}


STDMETHODIMP CTridentHost::GetExternal(
                    /*[out]*/ IDispatch** ppDispatch)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::GetExternal \n") );

    _ASSERTE(ppDispatch);

	if (!ppDispatch)
		return E_POINTER;
    *ppDispatch = NULL;
    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::TranslateUrl(
                    /*[in] */ DWORD dwTranslate,
                    /*[in] */ OLECHAR* pchURLIn,
                    /*[out]*/ OLECHAR** ppchURLOut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::TranslateUrl \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CTridentHost::FilterDataObject(
                    /*[in] */ IDataObject* pDO,
                    /*[out]*/ IDataObject** ppDORet)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::FilterDataObject \n") );

    if (!ppDORet)
        return E_POINTER;

    // suppress dragging out anything
    *ppDORet = NULL;
    return S_OK;
}


//*****************************************************************************
// CTridentHost IDocHostShowUI Implementation
//*****************************************************************************

STDMETHODIMP CTridentHost::ShowMessage(
                   /*[in] */ HWND     hwnd,
                   /*[in] */ LPOLESTR lpstrText,
                   /*[in] */ LPOLESTR lpstrCaption,
                   /*[in] */ DWORD    dwType,
                   /*[in] */ LPOLESTR lpstrHelpFile,
                   /*[in] */ DWORD    dwHelpContext,
                   /*[out]*/ LRESULT* plResult)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::ShowMessage \n") );

    // suppress message boxes from trident
    return S_OK;
}

STDMETHODIMP CTridentHost::ShowHelp(
                   /*[in] */ HWND       hwnd,
                   /*[in] */ LPOLESTR   pszHelpFile,
                   /*[in] */ UINT       uCommand,
                   /*[in] */ DWORD      dwData,
                   /*[in] */ POINT      ptMouse,
                   /*[out]*/ IDispatch* pDispatchObjectHit)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::ShowHelp \n") );

    // suppress help for trident
    return S_OK;
}


//*****************************************************************************
// CTridentHost Implementation
//*****************************************************************************

///////////////////////////////////////////////////////////////////////////////
// Creates an instance of mshtml docobject and sets up its client site

HRESULT CTridentHost::CreateDocument()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::CreateDocument \n") );

    HRESULT hr;

    hr = CoCreateInstance(CLSID_HTMLDocument, NULL, CLSCTX_INPROC_SERVER,
                          IID_IUnknown, (void**)&m_srpUnkTrident);
    IfFailGoMsg(hr, "Failed to create CLSID_HTMLDocument");

    hr = m_srpUnkTrident->QueryInterface(IID_IOleObject, (void**)&m_srpObjTrident);
    IfFailGo(hr);

    // pass it our client site and our advise
    m_srpObjTrident->SetClientSite(static_cast<IOleClientSite*>(this));
    m_srpObjTrident->Advise(static_cast<IAdviseSink*>(this), &m_dwAdviseCookie);

    hr = S_OK;

OnError:
    return hr;
}

///////////////////////////////////////////////////////////////////////////////
// Activate the mshtml docobject and make it visible within the parent window

HRESULT CTridentHost::RunAndShowDocument()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::RunAndShowDocument \n") );

    _ASSERTE(m_srpUnkTrident);
    _ASSERTE(m_srpObjTrident);

    HRESULT hr;

    hr = OleRun(m_srpUnkTrident);
    IfFailGo(hr);

    RECT rc;   
    GetClientRect(m_hwndParent, &rc);

    hr = m_srpObjTrident->DoVerb(OLEIVERB_SHOW, NULL, this, 0, m_hwndParent, &rc);

OnError:
    return hr;
}

///////////////////////////////////////////////////////////////////////////////
// Deactivate the mshtml docobject and release it

HRESULT CTridentHost::CloseDocument()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CTridentHost::CloseDocument \n") );

    if (!m_srpUnkTrident)
        return S_OK;

    HRESULT hr;
    CComPtr<IOleInPlaceObject> srpInPlaceObject;

    if (m_dwAdviseCookie)
    {
        _ASSERTE(m_srpObjTrident);
        m_srpObjTrident->Unadvise(m_dwAdviseCookie);
        m_dwAdviseCookie = 0;
    }

    hr = m_srpUnkTrident->QueryInterface(IID_IOleInPlaceObject,
                                         (void**)&srpInPlaceObject);
    if (SUCCEEDED(hr) && srpInPlaceObject)
    {
        srpInPlaceObject->InPlaceDeactivate();
        srpInPlaceObject.Release();
    }

    // release our cached interfaces
    m_srpObjTrident.Release();
    m_srpDocView.Release();
    m_srpUnkTrident.Release();

    return S_OK;
}
