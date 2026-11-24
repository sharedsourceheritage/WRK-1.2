
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential
//*****************************************************************************
// TriHost.h
//
// Declaration of CTridentHost
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CTridentHost
//*****************************************************************************

class ATL_NO_VTABLE CTridentHost :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IOleClientSite,
    public IOleDocumentSite,
    public IOleInPlaceSite,
    public IOleInPlaceFrame,
    public IAdviseSink,
    public IDocHostUIHandler,
    public IDocHostShowUI
{
// Constructor/Destructor
public:
    CTridentHost();
    ~CTridentHost();

// Operations
    HRESULT CreateTridentHost(HWND hwndParent);
    HRESULT CreateTridentHost(HWND hwndParent, LPCOLESTR lpszURL);
    HRESULT CloseTridentHost(void);
    HRESULT ActivateTrident();
    HRESULT GetTrident(IHTMLDocument2** ppTrident);
    void SetPosition(long x, long y, long cx, long cy);

// COM Map
BEGIN_COM_MAP(CTridentHost)
    COM_INTERFACE_ENTRY(IOleClientSite)
    COM_INTERFACE_ENTRY(IOleDocumentSite)
    COM_INTERFACE_ENTRY(IOleInPlaceSite)
    COM_INTERFACE_ENTRY(IOleInPlaceFrame)
    COM_INTERFACE_ENTRY(IAdviseSink)
    COM_INTERFACE_ENTRY(IDocHostUIHandler)
    COM_INTERFACE_ENTRY(IDocHostShowUI)
    COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceFrame)
    COM_INTERFACE_ENTRY2(IOleInPlaceUIWindow, IOleInPlaceFrame)
END_COM_MAP()

public:
// IOleClientSite
    STDMETHOD(SaveObject)(void);
    STDMETHOD(GetMoniker)(
                    /*[in] */ DWORD      dwAssign,
                    /*[in] */ DWORD      dwWhichMoniker,
                    /*[out]*/ IMoniker** ppMk);
    STDMETHOD(GetContainer)(
                    /*[out]*/ IOleContainer** ppContainer);
    STDMETHOD(ShowObject)(void);
    STDMETHOD(OnShowWindow)(
                    /*[in]*/ BOOL fShow);
    STDMETHOD(RequestNewObjectLayout)(void);

// IOleDocumentSite
    STDMETHOD(ActivateMe)(
                    /*[in]*/ IOleDocumentView* pViewToActivate);

// IOleInPlaceSite
    STDMETHOD(CanInPlaceActivate)(void);
    STDMETHOD(OnInPlaceActivate)(void);
    STDMETHOD(OnUIActivate)(void);
    STDMETHOD(GetWindowContext)(
                    /*[out]*/ IOleInPlaceFrame**    ppFrame,
                    /*[out]*/ IOleInPlaceUIWindow** ppDoc,
                    /*[out]*/ LPRECT                lprcPosRect,
                    /*[out]*/ LPRECT                lprcClipRect,
                    /*[out]*/ LPOLEINPLACEFRAMEINFO lpFrameInfo);
    STDMETHOD(Scroll)(
                    /*[in]*/ SIZE scrollExtent);
    STDMETHOD(OnUIDeactivate)(
                    /*[in]*/ BOOL fUndoable);
    STDMETHOD(OnInPlaceDeactivate)(void);
    STDMETHOD(DiscardUndoState)(void);
    STDMETHOD(DeactivateAndUndo)(void);
    STDMETHOD(OnPosRectChange)(
                    /*[in]*/ LPCRECT lprcPosRect);

// IOleWindow
    STDMETHOD(GetWindow)(
                    /*[out]*/ HWND* phwnd);
    STDMETHOD(ContextSensitiveHelp)(
                    /*[in]*/ BOOL fEnterMode);

// IOleInPlaceUIWindow
    STDMETHOD(GetBorder)(
                    /*[out]*/ LPRECT lprectBorder);
    STDMETHOD(RequestBorderSpace)(
                    /*[in]*/ LPCBORDERWIDTHS lpborderwidths);
    STDMETHOD(SetBorderSpace)(
                    /*[in]*/ LPCBORDERWIDTHS lpborderwidths);
    STDMETHOD(SetActiveObject)(
                    /*[in]*/ IOleInPlaceActiveObject* pActiveObject,
                    /*[in]*/ LPCOLESTR lpszObjName);

// IOleInPlaceFrame
    STDMETHOD(InsertMenus)(
                    /*[in]    */ HMENU                hmenuShared,
                    /*[in,out]*/ LPOLEMENUGROUPWIDTHS lpMenuWidths);
    STDMETHOD(SetMenu)(
                    /*[in]*/ HMENU    hmenuShared,
                    /*[in]*/ HOLEMENU holemenu,
                    /*[in]*/ HWND     hwndActiveObject);
    STDMETHOD(RemoveMenus)(
                    /*[in]*/ HMENU hmenuShared);
    STDMETHOD(SetStatusText)(
                    /*[in]*/ LPCOLESTR pszStatusText);
    STDMETHOD(EnableModeless)(
                    /*[in]*/ BOOL fEnable);
    STDMETHOD(TranslateAccelerator)(
                    /*[in]*/ LPMSG lpmsg,
                    /*[in]*/ WORD  wID);

// IAdviseSink
    STDMETHOD_(void, OnDataChange)(
                    /*[in]*/ FORMATETC* pFormatetc,
                    /*[in]*/ STGMEDIUM* pmedium);
    STDMETHOD_(void, OnViewChange)(
                    /*[in]*/ DWORD dwAspect,
                    /*[in]*/ LONG  lindex);
    STDMETHOD_(void, OnRename)(
                    /*[in]*/ IMoniker* pmk);
    STDMETHOD_(void, OnSave)(void);
    STDMETHOD_(void, OnClose)(void);

// IDocHostUIHandler
    STDMETHOD(ShowContextMenu)(
                    /*[in]*/ DWORD      dwID, 
                    /*[in]*/ POINT*     ppt, 
                    /*[in]*/ IUnknown*  pcmdtReserved,  
                    /*[in]*/ IDispatch* pdispReserved);
    STDMETHOD(GetHostInfo)(
                    /*[in, out]*/ DOCHOSTUIINFO* pInfo);
    STDMETHOD(ShowUI)(
                    /*[in]*/ DWORD                    dwID,
                    /*[in]*/ IOleInPlaceActiveObject* pActiveObject,
                    /*[in]*/ IOleCommandTarget*       pCommandTarget,
                    /*[in]*/ IOleInPlaceFrame*        pFrame,
                    /*[in]*/ IOleInPlaceUIWindow*     pDoc);
    STDMETHOD(HideUI)(void);
    STDMETHOD(UpdateUI)(void);
    STDMETHOD(OnDocWindowActivate)(
                    /*[in]*/ BOOL fActivate);
    STDMETHOD(OnFrameWindowActivate)(
                    /*[in]*/ BOOL fActivate);
    STDMETHOD(ResizeBorder)(
                    /*[in]*/ LPCRECT              prcBorder,
                    /*[in]*/ IOleInPlaceUIWindow* pUIWindow,
                    /*[in]*/ BOOL                 fRameWindow);
    STDMETHOD(TranslateAccelerator)(
                    /*[in]*/ LPMSG       lpMsg,
                    /*[in]*/ const GUID* pguidCmdGroup, 
                    /*[in]*/ DWORD       nCmdID);
    STDMETHOD(GetOptionKeyPath)(
                    /*[out]*/ LPOLESTR* pchKey,
                    /*[in] */ DWORD     dw);
    STDMETHOD(GetDropTarget)(
                    /*[in] */ IDropTarget*  pDropTarget, 
                    /*[out]*/ IDropTarget** ppDropTarget);
    STDMETHOD(GetExternal)(
                    /*[out]*/ IDispatch** ppDispatch);
    STDMETHOD(TranslateUrl)(
                    /*[in] */ DWORD     dwTranslate,
                    /*[in] */ OLECHAR*  pchURLIn,
                    /*[out]*/ OLECHAR** ppchURLOut);
    STDMETHOD(FilterDataObject)(
                    /*[in] */ IDataObject*  pDO,
                    /*[out]*/ IDataObject** ppDORet);

// IDocHostShowUI
    STDMETHOD(ShowMessage)(
                   /*[in] */ HWND     hwnd,
                   /*[in] */ LPOLESTR lpstrText,
                   /*[in] */ LPOLESTR lpstrCaption,
                   /*[in] */ DWORD    dwType,
                   /*[in] */ LPOLESTR lpstrHelpFile,
                   /*[in] */ DWORD    dwHelpContext,
                   /*[out]*/ LRESULT* plResult);
    STDMETHOD(ShowHelp)(
                   /*[in] */ HWND       hwnd,
                   /*[in] */ LPOLESTR   pszHelpFile,
                   /*[in] */ UINT       uCommand,
                   /*[in] */ DWORD      dwData,
                   /*[in] */ POINT      ptMouse,
                   /*[out]*/ IDispatch* pDispatchObjectHit);

// Implementation
protected:
    HRESULT CreateDocument();
    HRESULT RunAndShowDocument();
    HRESULT CloseDocument();

// Attributes
protected:
    HWND m_hwndParent;
    DWORD m_dwAdviseCookie;

    CComPtr<IUnknown> m_srpUnkTrident;
    CComPtr<IOleObject> m_srpObjTrident;
    CComPtr<IOleDocumentView> m_srpDocView;
};
