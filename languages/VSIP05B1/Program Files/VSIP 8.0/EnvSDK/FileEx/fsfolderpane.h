
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSFolderPane.h
//
// Declaration of CFileSystemFolderPane
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CFileSystemFolderPane
//*****************************************************************************

class ATL_NO_VTABLE CFileSystemFolderPane :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IVsSplitPane,
    public IOleCommandTarget,
    public IVsToolWindowToolbar,
    public IVsBroadcastMessageEvents,
    public IFileSystemPane,
    public IFileSystemFolderPane
{
// Constructor/Destructor
public:
    CFileSystemFolderPane();
    ~CFileSystemFolderPane();

// COM Interface Map
BEGIN_COM_MAP(CFileSystemFolderPane)
    COM_INTERFACE_ENTRY(IVsSplitPane)
    COM_INTERFACE_ENTRY(IOleCommandTarget)
    COM_INTERFACE_ENTRY(IVsToolWindowToolbar)
    COM_INTERFACE_ENTRY(IVsBroadcastMessageEvents)
    COM_INTERFACE_ENTRY(IFileSystemPane)
    COM_INTERFACE_ENTRY(IFileSystemFolderPane)
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

// IFileSystemFolderPane

// Windows Related Implementation
protected:
    static BOOL m_fClassRegistered;
    static LPCTSTR m_szClassName;

    enum
    {
        EB_THIS = 0,
        EXTRABYTES = 4,
    };

    enum
    {
        viewFolders = 0,
        viewShortcuts = 1
    };

    BOOL RegisterWindowClass();
    static LRESULT CALLBACK StaticWndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

// Message Handlers
protected:
    LRESULT WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
    LRESULT OnCreate();
    LRESULT OnSize(WPARAM flag, int width, int height);
    LRESULT OnSetFocus();
    LRESULT OnPaint();

    LRESULT OnTreeItemExpanding(HWND hwndTree, NMTREEVIEW* pnmtv);
    LRESULT OnTreeItemSelChanged(HWND hwndTree);
    LRESULT OnTreeItemDoubleClicked(HWND hwndTree);
    LRESULT OnTreeItemRightClicked(HWND hwndTree);
    LRESULT OnContextMenu(short x, short y);

// Command Handlers
protected:
    HRESULT OnSwitchView(int nView);
    HRESULT OnRefresh(BOOL fThis);
    HRESULT OnAddShortcut();
    HRESULT OnDeleteShortcut();
    HRESULT OnBrowseShortcut();
    HRESULT OnFindHere();
    HRESULT OnExplorer();
    HRESULT OnMSDOS();

// Implementation
protected:
    void InitDrives();
    void InitShortcuts();
    HTREEITEM AddDriveToTree(CFileSystemFolderItem* pDrive, BOOL fSelect);
    HTREEITEM AddShortcutToTree(CFileSystemFolderItem* pShortcut, BOOL fSelect);
    HTREEITEM AddFolderToTree(HWND hwndTree, HTREEITEM htiParent, CFileSystemFolderItem* pFolder, BOOL fSelect, int iImage, int iSelectedImage);
    void UpdateContextItem(HTREEITEM htiContext);
    void UpdateFolderSelection(CFileSystemFolderItem* pSelFolder, BOOL fNotifyFilePane);

// Attributes
protected:
    CComPtr<IServiceProvider> m_srpSiteSP;
    CComPtr<IVsSplitter> m_srpParentSplitter;
    CComPtr<IVsToolWindowToolbarHost> m_srpToolbarHost;
    CComPtr<IFileSystemSelectionContainer> m_srpSelection;
    CComPtr<IFileSystemFilePane> m_srpFilePane;

    HWND m_hwndPane;
    HWND m_hwndParent;
    HWND m_hwndFolders;
    HWND m_hwndShortcuts;
    HFONT m_hFont;
    HIMAGELIST m_himlFolders;

    CFileSystemFolderItem* m_pSelFolderItem;
    CFileSystemFolderItem* m_pSelShortcutItem;

    VSCOOKIE m_dwBroadcastCookie;

    BOOL m_nViewMode;
};
