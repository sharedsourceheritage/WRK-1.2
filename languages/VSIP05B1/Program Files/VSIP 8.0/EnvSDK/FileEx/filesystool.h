
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FileSysTool.h
//
// Declaration of CFileSystemToolWindow
//
//*****************************************************************************

#pragma once


//*****************************************************************************
// CFileSystemToolWindow
//*****************************************************************************

class ATL_NO_VTABLE CFileSystemToolWindow :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IVsWindowPane,
    public IOleCommandTarget,
    public IServiceProvider,
    public ITrackSelection,
    public IFileSystemToolWindow
{
// Constructor/Destructor
public:
    CFileSystemToolWindow();
    ~CFileSystemToolWindow();

// Operations
public:
    static HRESULT CreateTool(IVsWindowFrame** ppFrame);

// COM Interface Map
BEGIN_COM_MAP(CFileSystemToolWindow)
    COM_INTERFACE_ENTRY(IVsWindowPane)
    COM_INTERFACE_ENTRY(IOleCommandTarget)
    COM_INTERFACE_ENTRY(IServiceProvider)
    COM_INTERFACE_ENTRY(ITrackSelection)
    COM_INTERFACE_ENTRY(IFileSystemToolWindow)
END_COM_MAP()

public:
// IVsWindowPane
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

// IOleCommandTarget
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

// IServiceProvider
    STDMETHOD(QueryService)(
                    /*[in] */ REFGUID rsid,
                    /*[in] */ REFIID  riid,
                    /*[out]*/ void**  ppvObject);

// ISelectionContainer
    STDMETHOD(OnSelectChange)(
                    /*[in]*/ ISelectionContainer* pSC);

// IFileSystemToolWindow

// Implementation
protected:
    static BOOL m_fClassRegistered;
    static LPCTSTR m_szClassName;

    enum
    {
        EB_THIS = 0,
        EXTRABYTES = 4,
    };

    HRESULT CreateSubPanes();
    BOOL RegisterWindowClass();
    void InitUIFont();
    static LRESULT CALLBACK StaticWndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

// Message Handlers
protected:
    LRESULT WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
    LRESULT OnCreate();
    LRESULT OnSize(WPARAM flag, int width, int height);
    LRESULT OnPaint();

// Attributes
protected:
    CComPtr<IServiceProvider> m_srpSiteSP;
    CComPtr<ITrackSelection> m_srpSelTracker;
    CComPtr<ISelectionContainer> m_srpSelection;

    HWND m_hwndRoot;
    HWND m_hwndMain;
    HWND m_hwndParent;
    HWND m_hwndFolderPane;
    HWND m_hwndFilePane;
    HFONT m_hFontUI;

    CComPtr<IVsSplitRoot> m_srpRootSplitter;
    CComPtr<IVsWindowPane> m_srpRootWindow;

    CComPtr<IFileSystemPane> m_srpFilePane;
    CComPtr<IOleCommandTarget> m_srpFilePaneCmdTgt;

    CComPtr<IFileSystemPane> m_srpFolderPane;
    CComPtr<IOleCommandTarget> m_srpFolderPaneCmdTgt;
};
