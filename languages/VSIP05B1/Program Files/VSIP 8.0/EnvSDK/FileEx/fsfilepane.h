
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSFilePane.h
//
// Declaration of CFileSystemFilePane
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CFileSystemFolderPane
//*****************************************************************************

class ATL_NO_VTABLE CFileSystemFilePane :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IVsSplitPane,
    public IOleCommandTarget,
    public IVsToolWindowToolbar,
    public IVsBroadcastMessageEvents,
    public IFileSystemPane,
    public IFileSystemFilePane
{
// Constructor/Destructor
public:
    CFileSystemFilePane();
    ~CFileSystemFilePane();

// COM Interface Map
BEGIN_COM_MAP(CFileSystemFilePane)
    COM_INTERFACE_ENTRY(IVsSplitPane)
    COM_INTERFACE_ENTRY(IOleCommandTarget)
    COM_INTERFACE_ENTRY(IVsToolWindowToolbar)
    COM_INTERFACE_ENTRY(IVsBroadcastMessageEvents)
    COM_INTERFACE_ENTRY(IFileSystemPane)
    COM_INTERFACE_ENTRY(IFileSystemFilePane)
END_COM_MAP()

public:
// IVsSplitPane
    STDMETHOD(SetParentSplitter)(
                    /*[in]*/ IVsSplitter* pSplitter);
    STDMETHOD(GetParentSplitter)(
                    /*[out]*/ IVsSplitter** ppSplitter);
    STDMETHOD(SetFocus)(void);
    STDMETHOD(SetPosition)(
                    /*[in]*/ long iLeft,
                    /*[in]*/ long iTop,
                    /*[in]*/ long iRight,
                    /*[in]*/ long iBottom);
    STDMETHOD(GetPosition)(
                    /*[out]*/ long* piLeft,
                    /*[out]*/ long* piTop,
                    /*[out]*/ long* piRight,
                    /*[out]*/ long* piBottom);
    STDMETHOD(GetSizeExtents)(
                    /*[out]*/ long* piMinHorz,
                    /*[out]*/ long* piMaxHorz,
                    /*[out]*/ long* piMinVert,
                    /*[out]*/ long* piMaxVert);
    STDMETHOD(GetParentWindow)(
                    /*[out]*/ HWND* phwndParent);
    STDMETHOD(GetPaneFlags)(
                    /*[out]*/ DWORD* pdwPaneFlags);
    STDMETHOD(ClosePane)(void);
    STDMETHOD(NotifyPane)(
                    /*[in]*/ SPLITNOTIFYCODE iCode);
    STDMETHOD(DetachPane)(void);

// IOleCommandTarget
    STDMETHOD(QueryStatus)(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText);
    STDMETHOD(Exec)(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdexecopt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut);

// IVsToolWindowToolbar methods
    STDMETHOD(GetBorder)(
                    /*[out]*/ RECT* prc);
    STDMETHOD(SetBorderSpace)(
                    /*[in]*/ LPCBORDERWIDTHS pbw);

// IVsBroadcastMessageEvents
    STDMETHOD(OnBroadcastMessage)(
                    /*[in]*/ UINT   msg,
                    /*[in]*/ WPARAM wParam,
                    /*[in]*/ LPARAM lParam);

// IFileSystemPane
    STDMETHOD(Initialize)(
                    /*[in]*/ IServiceProvider* pSP,
                    /*[in]*/ HWND              hwndParent,
                    /*[in]*/ HFONT             hFont);
    STDMETHOD(GetPaneWindow)(
                    /*[out]*/ HWND* phwndPane);

// IFileSystemFilePane
    STDMETHOD(SetCurrentFolder)(
                    /*[in]*/ DWORD_PTR dwFolderPtr);

// Windows Related Implementation
protected:
    static BOOL s_fClassRegistered;
    static LPCTSTR s_szClassName;
    static WNDPROC s_lpfnEditProc;

    enum
    {
        EB_THIS = 0,
        EXTRABYTES = 4,
    };

    BOOL RegisterWindowClass();
    static LRESULT CALLBACK StaticWndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK CmdEditWndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

// Message Handlers
protected:
    LRESULT WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
    LRESULT OnCreate();
    LRESULT OnSize(WPARAM flag, int width, int height);
    LRESULT OnSetFocus();
    LRESULT OnPaint();
    LRESULT OnDrawItem(DRAWITEMSTRUCT* pdis);

    LRESULT OnTreeItemSelChanged();
    LRESULT OnTreeItemDoubleClicked();
    LRESULT OnTreeItemRightClicked();
    LRESULT OnContextMenu(short x, short y);
    LRESULT OnExecCommand();

// Command Handlers
protected:
    HRESULT OnOpenFile(BOOL fOpenWith);
    HRESULT OnPreviewFile();
    HRESULT OnRefresh();
    HRESULT OnSortFiles(short nSortType);
    HRESULT OnFilterChanged(VARIANT* pvaIn);

// Implementation
protected:
    void SetEnabledState();
    void SubclassCmdEdit();
    void UnsubclassCmdEdit();
    HTREEITEM AddFileToTree(CFileSystemFileItem* pFile);
    void UpdateContextItem(HTREEITEM htiContext);
    static int CALLBACK CompareFiles(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

// Attributes
protected:
    CComPtr<IServiceProvider> m_srpSiteSP;
    CComPtr<IVsSplitter> m_srpParentSplitter;
    CComPtr<IVsToolWindowToolbarHost> m_srpToolbarHost;
    CComPtr<IFileSystemSelectionContainer> m_srpSelection;

    CFileSystemFolderItem* m_pSelFolder;
    CFileSystemCachedFolder* m_pCachedFolder;
    CFileSystemFileItem* m_pSelFile;

    HWND m_hwndPane;
    HWND m_hwndParent;
    HWND m_hwndFiles;
    HWND m_hwndCmdText;
    HWND m_hwndCmdExec;
    HFONT m_hFont;
    HIMAGELIST m_himlState;
    HICON m_hiconCmdExec;

    enum { sortName = 1, sortExtension = 2, sortReadOnly = 3 };
    short m_nSortType;

    VSCOOKIE m_dwBroadcastCookie;

    BOOL m_fIgnoreSelChanges;
};
