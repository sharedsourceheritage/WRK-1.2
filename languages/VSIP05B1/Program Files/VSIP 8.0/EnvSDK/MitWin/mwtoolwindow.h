
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// MWToolWindow.h: interface for the CMWToolWindow class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

// Manage the tool windows
class CMWToolWindow :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IVsWindowPane,
    public IOleCommandTarget,
    public CVsWindowFrameNotifyImpl // IVsWindowFrameNotify

{

// =========================================================================
//                                 Construct, initialize, copy, and destruct
//
public:
    CMWToolWindow();

    HRESULT Initialize(
        /*[in]*/ IVsWindowFrame*    pFrame);

    virtual ~CMWToolWindow();
//
//                                 Construct, initialize, copy, and destruct
// =========================================================================

// =========================================================================
//                                                                   ATL COM 
//

DECLARE_NOT_AGGREGATABLE(CMWToolWindow)
DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CMWToolWindow)
    COM_INTERFACE_ENTRY(IVsWindowPane)
    COM_INTERFACE_ENTRY(IOleCommandTarget)
    COM_INTERFACE_ENTRY(IVsWindowFrameNotify)
END_COM_MAP()
//
//                                                                   ATL COM 
// =========================================================================


// =========================================================================
//                                                             IVsWindowPane
//
public:

    STDMETHOD(SetSite)(
                    /*[in]*/ IServiceProvider* pSP);

    STDMETHOD(CreatePaneWindow)(
                    /*[in] */ HWND  hwndParent,
                    /*[in] */ int   x,
                    /*[in] */ int   y,
                    /*[in] */ int   cx,
                    /*[in] */ int   cy,
                    /*[out]*/ HWND* phwnd);

    STDMETHOD(GetDefaultSize)(
                    /*[out]*/ SIZE* pSize);

    STDMETHOD(ClosePane)(void);

    STDMETHOD(LoadViewState)(
                    /*[in]*/ IStream* pStream);

    STDMETHOD(SaveViewState)(
                    /*[in]*/ IStream* pStream);

    STDMETHOD(TranslateAccelerator)(
                    /*[in]*/ LPMSG lpmsg);
//
//                                                             IVsWindowPane
// =========================================================================

// =========================================================================
//                                                         IOleCommandTarget
//
// -------------------------------------------------------------------------
//                                               IOleCommandTarget interface
//
public:

    STDMETHOD(QueryStatus)(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText);
    STDMETHOD(Exec)(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdExecOpt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut);
//
//                                               IOleCommandTarget interface
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
//                                          IOleCommandTarget implementation
// 
public:

    // Query the status of the main comand in the "View" menu
    static HRESULT QueryToolWindowCmdStatus(
                                DWORD*      pCmdf, 
                                OLECMDTEXT* pCmdText);

    // Query the status of the commands in the cascading menu
    static HRESULT QueryToolWindowListCmdStatus(
                                DWORD       dwCmdIndex,		  
                                DWORD*      pCmdf,			
                                OLECMDTEXT* pCmdText);	
    
    // Execute a command from the tool window list
    static HRESULT ExecToolWindowListCmd(
                                DWORD dwCmdIndex = 0);

protected:
    HRESULT OnMWNewWindow();
//
//                                          IOleCommandTarget implementation
// -------------------------------------------------------------------------
//
//                                                         IOleCommandTarget
// =========================================================================

// =========================================================================
//                                                      IVsWindowFrameNotify
//
public:

    STDMETHOD(OnShow)(/*[in]*/ FRAMESHOW fShow);
    // STDMETHOD(OnMove)();
    // STDMETHOD(OnSize)()
    // STDMETHOD(OnDockableChange)(/*[in]*/ BOOL fDockable);
//
//
//                                                      IVsWindowFrameNotify
// =========================================================================

// =========================================================================
//                                                     CMWToolWindow methods
//	
public:

    // Get next available ID
    static HRESULT GetID(
                    DWORD* pdw);

    // Get the number of the active windows
    static HRESULT CMWToolWindow::GetCount(
                    DWORD* pdwCount);
//	
//	
//                                                     CMWToolWindow methods
// =========================================================================

// =========================================================================
//                                                                   Members
//	
protected:
    // ---------------------------------------------------------------------
    //                                                       Static memebers
    //
    static CEnvSDKPtrArray<IVsWindowFrame> ms_prgMWFrames;
    //
    //                                                       Static memebers
    // ---------------------------------------------------------------------

    BOOL                        m_fZombie;

    CComPtr<IServiceProvider>   m_srpSiteSP;
    CComPtr<IVsWindowFrame>     m_srpWindowFrame;
    CMWToolDialog               m_wnd;        
//	
//                                                                   Members
// =========================================================================

};
