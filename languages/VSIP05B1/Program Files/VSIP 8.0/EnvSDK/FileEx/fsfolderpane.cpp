
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSFilePane.cpp
//
// Implementation of CFileSystemFolderPane
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "FSFolderPane.h"
#include "FSSelection.h"

BOOL CFileSystemFolderPane::m_fClassRegistered = FALSE;
LPCTSTR CFileSystemFolderPane::m_szClassName = _T("WCFileSysFolderPane");

//*****************************************************************************
// CFileSystemFolderPane Constructor/Destructor
//*****************************************************************************

CFileSystemFolderPane::CFileSystemFolderPane()
{
    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Creating CFileSystemFolderPane: 0x%X\n"), this);
    }

    m_hwndParent = NULL;
    m_hwndPane = NULL;
    m_hwndFolders = NULL;
    m_hwndShortcuts = NULL;
    m_hFont = NULL;
    m_himlFolders = NULL;

    m_pSelFolderItem = NULL;
    m_pSelShortcutItem = NULL;

    m_dwBroadcastCookie = 0;

    m_nViewMode = viewFolders;
}

CFileSystemFolderPane::~CFileSystemFolderPane()
{
    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Destructing CFileSystemFolderPane: 0x%X\n"), this);
    }

    _ASSERTE_MSG(m_dwBroadcastCookie == 0,
                 "CFileSystemFolderPane did not unadvise from IVsBroadcastMessageEvents");

    if (m_himlFolders)
    {
        ImageList_Destroy(m_himlFolders);
        m_himlFolders = NULL;
    }
}


//*****************************************************************************
// CFileSystemFolderPane IVsSplitPane Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFolderPane::SetParentSplitter(
                    /*[in]*/ IVsSplitter* pSplitter)
{
    m_srpParentSplitter = pSplitter;
    return S_OK;
}

STDMETHODIMP CFileSystemFolderPane::GetParentSplitter(
                    /*[out]*/ IVsSplitter** ppSplitter)
{
    ExpectedPtrRet(ppSplitter);

    *ppSplitter = m_srpParentSplitter;
    if (*ppSplitter)
    {
        (*ppSplitter)->AddRef();
        return S_OK;
    }
    else
        return E_FAIL;
}

STDMETHODIMP CFileSystemFolderPane::SetFocus(void)
{
    if (m_nViewMode == viewFolders)
    {
        ::SetFocus(m_hwndFolders);
        UpdateFolderSelection(m_pSelFolderItem, FALSE);
    }
    else
    {
        ::SetFocus(m_hwndShortcuts);
        UpdateFolderSelection(m_pSelShortcutItem, FALSE);
    }
    return S_OK;
}

STDMETHODIMP CFileSystemFolderPane::SetPosition(
                    /*[in]*/ long iLeft,
                    /*[in]*/ long iTop,
                    /*[in]*/ long iRight,
                    /*[in]*/ long iBottom)
{
    SetWindowPos(m_hwndPane, NULL, iLeft, iTop, iRight - iLeft, iBottom - iTop, SWP_NOZORDER);
    if (m_srpToolbarHost)
    {
        m_srpToolbarHost->BorderChanged();
    }
    return S_OK;
}

STDMETHODIMP CFileSystemFolderPane::GetPosition(
                    /*[out]*/ long* piLeft,
                    /*[out]*/ long* piTop,
                    /*[out]*/ long* piRight,
                    /*[out]*/ long* piBottom)
{
    return E_NOTIMPL;
}

STDMETHODIMP CFileSystemFolderPane::GetSizeExtents(
                    /*[out]*/ long* piMinHorz,
                    /*[out]*/ long* piMaxHorz,
                    /*[out]*/ long* piMinVert,
                    /*[out]*/ long* piMaxVert)
{
    return E_NOTIMPL;
}

STDMETHODIMP CFileSystemFolderPane::GetParentWindow(
                    /*[out]*/ HWND* phwndParent)
{
    ExpectedPtrRet(phwndParent);

    *phwndParent = m_hwndParent;
    return S_OK;
}

STDMETHODIMP CFileSystemFolderPane::GetPaneFlags(
                    /*[out]*/ DWORD* pdwPaneFlags)
{
    ExpectedPtrRet(pdwPaneFlags);

    *pdwPaneFlags = PF_ELASTICY;
    return S_OK;
}

STDMETHODIMP CFileSystemFolderPane::ClosePane(void)
{
    TreeView_DeleteAllItems(m_hwndShortcuts);
    TreeView_DeleteAllItems(m_hwndFolders);
    m_pSelShortcutItem = NULL;
    m_pSelFolderItem = NULL;

    if (m_srpSelection)
    {
        m_srpSelection->Close();
        m_srpSelection.Release();
    }

    if (m_dwBroadcastCookie)
    {
        IVsShell* pVsShell = _VxModule.GetIVsShell(); // un-addref'd
        pVsShell->UnadviseBroadcastMessages(m_dwBroadcastCookie);

        m_dwBroadcastCookie = 0;
    }

    if (m_srpParentSplitter)
    {
        m_srpParentSplitter->NotifySplitter(static_cast<IVsSplitPane*>(this),
                                            PE_CLOSED);
        m_srpParentSplitter.Release();
    }

    m_srpToolbarHost.Release();
    m_srpSiteSP.Release();

    return S_OK;
}

STDMETHODIMP CFileSystemFolderPane::NotifyPane(
                    /*[in]*/ SPLITNOTIFYCODE iCode)
{
    // handle the notification if needed
    switch (iCode)
    {
        // attaching/detaching
        case SNC_ANCESTORDETACHED:
            break;
        case SNC_ANCESTORATTACHED:
            break;

        // resizing
        case SNC_BEGINSIZE:
            break;
        case SNC_ENDSIZE:
            break;
    }
    return S_OK;
}

STDMETHODIMP CFileSystemFolderPane::DetachPane(void)
{
    if (m_srpParentSplitter)
    {

        m_srpParentSplitter->NotifySplitter(static_cast<IVsSplitPane*>(this),
                                            PE_DETACHED);
        m_srpParentSplitter.Release();
    }
    NotifyPane(SNC_ANCESTORDETACHED);
    return S_OK;
}


//*****************************************************************************
// CFileSystemFolderPane IOleCommandTarget Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFolderPane::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    _ASSERTE(pguidCmdGroup);
    _ASSERTE(prgCmds);
    _ASSERTE(cCmds == 1);

    if (!pguidCmdGroup)
        return E_POINTER;
    if (!prgCmds)
        return E_POINTER;

    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;
    DWORD cmdf = 0;

    if (*pguidCmdGroup == guidEUCmd)
    {
        hr = S_OK;

        switch (prgCmds[0].cmdID)
        {
            case cmdidFolderView:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                if (m_nViewMode == viewFolders)
                    cmdf |= OLECMDF_LATCHED;
                hr = S_OK;
                break;
            case cmdidShortcutView:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                if (m_nViewMode == viewShortcuts)
                    cmdf |= OLECMDF_LATCHED;
                hr = S_OK;
                break;
            case cmdidFoldersRefresh:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                hr = S_OK;
                break;
            case cmdidFoldersRefreshThis:
                {
                    CFileSystemFolderItem* pSelItem;

                    pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;
                    cmdf = OLECMDF_SUPPORTED;
                    if (pSelItem && !pSelItem->IsUNCFolder())
                        cmdf |= OLECMDF_ENABLED;
                    hr = S_OK;
                }
                break;
            case cmdidAddShortcut:
                {
                    CFileSystemFolderItem* pSelItem;
                    
                    cmdf = OLECMDF_SUPPORTED;
                    pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;

                    if (pSelItem &&
                        (pSelItem->GetFolderType() != CFileSystemFolderItem::fsiShortcut))
                        cmdf |= OLECMDF_ENABLED;
                    hr = S_OK;
                }
                break;
            case cmdidDeleteShortcut:
                {
                    CFileSystemFolderItem* pSelItem;
                    
                    cmdf = OLECMDF_SUPPORTED;
                    pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;

                    if (pSelItem &&
                        (pSelItem->GetFolderType() == CFileSystemFolderItem::fsiShortcut))
                        cmdf |= OLECMDF_ENABLED;
                    hr = S_OK;
                }
                break;
            case cmdidBrowseShortcut:
                cmdf = OLECMDF_SUPPORTED;
                cmdf |= ((m_nViewMode == viewShortcuts) ? OLECMDF_ENABLED : OLECMDF_INVISIBLE);
                hr = S_OK;
                break;
            case cmdidFindHere:
            case cmdidExplorer:
                {
                    CFileSystemFolderItem* pSelItem;

                    pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;
                    cmdf = OLECMDF_SUPPORTED;
                    if (pSelItem)
                        cmdf |= OLECMDF_ENABLED;
                    hr = S_OK;
                }
                break;
            case cmdidMSDOS:
                {
                    CFileSystemFolderItem* pSelItem;

                    pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;
                    cmdf = OLECMDF_SUPPORTED;
                    if (pSelItem && !pSelItem->IsUNCFolder())
                        cmdf |= OLECMDF_ENABLED;
                    hr = S_OK;
                }
                break;
            case cmdidNoCommands:
                cmdf = OLECMDF_SUPPORTED;
                if (g_FileSys.GetCommandCount() > 0)
                    cmdf |= OLECMDF_INVISIBLE;
                hr = S_OK;
                break;
            case cmdidDefineCommands:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                hr = S_OK;
                break;
            default:
                if ((prgCmds[0].cmdID >= cmdidCommandList0) &&
                    (prgCmds[0].cmdID <= cmdidCommandList15))
                {
                    int nCommandIndex = prgCmds[0].cmdID - cmdidCommandList0;
                    int nCommands = g_FileSys.GetCommandCount();

                    if (nCommandIndex < nCommands)
                    {
                        CFileSystemCommand* pCommand = g_FileSys.GetCommand(nCommandIndex);
                        _ASSERTE(pCommand);

                        CFileSystemFolderItem* pSelFolder =
                            (m_nViewMode == viewFolders ? m_pSelFolderItem : m_pSelShortcutItem);

                        cmdf = OLECMDF_SUPPORTED;

                        // enable only if it doesn't require a selected file (cmd applies
                        // only to file pane) and we either have a selected folder or
                        // the command does not require a folder
                        if (!pCommand->RequiresFile() &&
                            (pSelFolder || !pCommand->RequiresFolder()))
                        {
                            cmdf |= OLECMDF_ENABLED;
                        }

                        if (pCmdText && pCmdText->cmdtextf)
                        {
                            USES_CONVERSION;
                            LPCTSTR lpszName = pCommand->GetCommandName();
                            UINT nLen = lstrlen(lpszName);

                            pCmdText->cwActual = nLen;
                            if (pCmdText->cwBuf - 1 < nLen)
                                nLen = pCmdText->cwBuf - 1;
                            wcsncpy(pCmdText->rgwz, T2CW(lpszName), nLen);
                            pCmdText->rgwz[nLen] = L'\0';
                        }
                        hr = S_OK;
                        break;
                    }
                }
                hr = OLECMDERR_E_NOTSUPPORTED;
                break;
        }
    }

    prgCmds[0].cmdf = cmdf;
    return hr;
}

STDMETHODIMP CFileSystemFolderPane::Exec(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdexecopt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut)
{
    _ASSERTE(pguidCmdGroup);
    if (!pguidCmdGroup)
        return E_POINTER;

    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;
    BOOL fHandled = FALSE;

    _VxModule.ClearErrorInfo();

    if (*pguidCmdGroup == guidEUCmd)
    {
        fHandled = TRUE;

        switch (nCmdID)
        {
            case cmdidFolderView:
                hr = OnSwitchView(viewFolders);
                break;
            case cmdidShortcutView:
                hr = OnSwitchView(viewShortcuts);
                break;
            case cmdidFoldersRefresh:
                hr = OnRefresh(FALSE);
                break;
            case cmdidFoldersRefreshThis:
                hr = OnRefresh(TRUE);
                break;
            case cmdidAddShortcut:
                hr = OnAddShortcut();
                break;
            case cmdidDeleteShortcut:
                hr = OnDeleteShortcut();
                break;
            case cmdidBrowseShortcut:
                hr = OnBrowseShortcut();
                break;
            case cmdidFindHere:
                hr = OnFindHere();
                break;
            case cmdidExplorer:
                hr = OnExplorer();
                break;
            case cmdidMSDOS:
                hr = OnMSDOS();
                break;
            case cmdidDefineCommands:
                fHandled = TRUE;
                if (g_FileSys.DefineCommands())
                    UpdateCommandUI(FALSE);
                hr = S_OK;
                break;
            default:
                if ((nCmdID >= cmdidCommandList0) &&
                    (nCmdID <= cmdidCommandList15))
                {
                    int nCommandIndex = nCmdID - cmdidCommandList0;
                    _ASSERTE(nCommandIndex < g_FileSys.GetCommandCount());

                    CFileSystemCommand* pCommand = g_FileSys.GetCommand(nCommandIndex);
                    _ASSERTE(pCommand);

                    CFileSystemFolderItem* pSelFolder =
                        (m_nViewMode == viewFolders ? m_pSelFolderItem : m_pSelShortcutItem);

                    hr = pCommand->Execute(pSelFolder, NULL);
                    fHandled = TRUE;
                    break;
                }
                hr = OLECMDERR_E_NOTSUPPORTED;
                break;
        }
    }

    if (fHandled)
    {
        _VxModule.ReportErrorInfo(hr);
        hr = S_OK;
    }

    return hr;
}


//*****************************************************************************
// CFileSystemFolderPane IVsToolWindowToolbar Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFolderPane::GetBorder(
                    /*[out]*/ RECT* prc)
{
    _ASSERTE(m_hwndPane && IsWindow(m_hwndPane));

    GetClientRect(m_hwndPane, prc);
    return S_OK;
}

STDMETHODIMP CFileSystemFolderPane::SetBorderSpace(
                    /*[in]*/ LPCBORDERWIDTHS pbw)
{
    RECT rect;
    if (!pbw)
        return E_POINTER;

    GetClientRect(m_hwndPane, &rect);

    rect.left += pbw->left;
    rect.top += pbw->top;
    rect.right -= (pbw->left + pbw->right);
    rect.bottom -= (pbw->top + pbw->bottom);

    MoveWindow(m_hwndFolders, rect.left + 1, rect.top + 2, rect.right - 2, rect.bottom - 4,
               m_nViewMode == viewFolders);
    MoveWindow(m_hwndShortcuts, rect.left + 1, rect.top + 2, rect.right - 2, rect.bottom - 4,
               m_nViewMode == viewShortcuts);
    return S_OK;
}


//*****************************************************************************
// CFileSystemFolderPane IVsBroadcastMessageEvents Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFolderPane::OnBroadcastMessage(
                    /*[in]*/ UINT   msg,
                    /*[in]*/ WPARAM wParam,
                    /*[in]*/ LPARAM lParam)
{
    // Propagate message to child windows
    SendMessage(m_hwndFolders, msg, wParam, lParam);
    SendMessage(m_hwndShortcuts, msg, wParam, lParam);

    return S_OK;
}


//*****************************************************************************
// CFileSystemFolderPane IFileSystemPane Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFolderPane::Initialize(
                    /*[in]*/ IServiceProvider* pSP,
                    /*[in]*/ HWND              hwndParent,
                    /*[in]*/ HFONT             hFont)
{
    _ASSERTE(pSP && !m_srpSiteSP);
    _ASSERTE(hwndParent && !m_hwndParent);
    _ASSERTE(hFont && !m_hFont);

    if (!pSP)
        return E_POINTER;
    if (!hwndParent)
        return E_POINTER;
    if (!hFont)
        return E_POINTER;

    HRESULT hr;

    hr = pSP->QueryService(SID_SFileSystemFilePane, IID_IFileSystemFilePane,
                           (void**)&m_srpFilePane);
    IfFailGo(hr);

    AtlCreateInstance(CFileSystemSelection, IID_IFileSystemSelectionContainer,
                      &m_srpSelection);
    IfFailGo(hr);

    hr = m_srpSelection->Initialize(pSP);
    IfFailGo(hr);

    m_srpSiteSP = pSP;
    m_hwndParent = hwndParent;
    m_hFont = hFont;

OnError:
    return hr;
}

STDMETHODIMP CFileSystemFolderPane::GetPaneWindow(
                    /*[out]*/ HWND* phwndPane)
{
    _ASSERTE(phwndPane);
    _ASSERTE(m_hwndParent);
    _ASSERTE(m_srpSiteSP);
    _ASSERTE(m_hFont);
    if (!phwndPane)
        return E_POINTER;

    HRESULT hr;

    if (!m_hwndPane)
    {
        if (!m_fClassRegistered)
            m_fClassRegistered = RegisterWindowClass();
        ExpectedExprGo(m_fClassRegistered);

        *phwndPane = CreateWindowEx(0,                                 // dwExStyle
                                    m_szClassName,                     // lpszClassName
                                    _T("FileSystemBrowser FilePane"),  // lpszWindowName
                                    WS_VISIBLE | WS_CHILD |
                                    WS_CLIPSIBLINGS |
                                    WS_CLIPCHILDREN,                   // dwStyle
                                    0, 0, 1, 1,                        // x, y, nWidth, nHeight
                                    m_hwndParent,                      // hWndParent
                                    (HMENU)IDC_FILESYSPANE_FOLDER,     // hMenu
                                    _AtlBaseModule.GetModuleInstance(),       // hInstance
                                    this);                             // lpParam

        IVsShell* pVsShell = _VxModule.GetIVsShell(); // un-addref'd
        if (pVsShell)
        {
            pVsShell->AdviseBroadcastMessages(static_cast<IVsBroadcastMessageEvents*>(this),
                                              &m_dwBroadcastCookie);
            _ASSERTE(m_dwBroadcastCookie);
        }

        hr = *phwndPane ? S_OK : E_FAIL;
    }
    else
    {
        *phwndPane = m_hwndPane;
        hr = S_OK;
    }

OnError:
    return hr;
}



//*****************************************************************************
// CFileSystemFolderPane Windows Related Implementation
//*****************************************************************************

BOOL CFileSystemFolderPane::RegisterWindowClass()
{
    WNDCLASS wc;

    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = (WNDPROC)StaticWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = EXTRABYTES;
    wc.hInstance = _AtlBaseModule.GetModuleInstance();
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = m_szClassName;

    return RegisterClass(&wc);
}

LRESULT CALLBACK CFileSystemFolderPane::StaticWndProc(HWND hwnd, UINT iMsg,
                                                    WPARAM wParam, LPARAM lParam)
{
    CFileSystemFolderPane* pThis = NULL;

    if (iMsg == WM_CREATE)
    {
        pThis = (CFileSystemFolderPane*)((LPCREATESTRUCT)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, EB_THIS, (LONG_PTR)pThis);
        pThis->m_hwndPane = hwnd;
    }
    else
        pThis = (CFileSystemFolderPane*)GetWindowLongPtr(hwnd, EB_THIS);

    if (pThis)
        return pThis->WndProc(hwnd, iMsg, wParam, lParam);
    else
        return DefWindowProc(hwnd, iMsg, wParam, lParam);
}


//*****************************************************************************
// CFileSystemFolderPane Message Handlers
//*****************************************************************************

LRESULT CFileSystemFolderPane::WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    if (m_srpToolbarHost)
        m_srpToolbarHost->ProcessMouseActivation(hwnd, iMsg, wParam, lParam);

    switch (iMsg)
    {
        case WM_CREATE:
            return OnCreate();
        case WM_SIZE:
            return OnSize(wParam, LOWORD(lParam), HIWORD(lParam));
        case WM_SETFOCUS:
            return OnSetFocus();
        case WM_PAINT:
            return OnPaint();
        case WM_CONTEXTMENU:
            return OnContextMenu(LOWORD(lParam), HIWORD(lParam));
        case WM_NOTIFY:
            {
                NMHDR* pnmh = (NMHDR*)lParam;
                HWND hwndTree = NULL;

                if (pnmh->idFrom == IDC_FILESYSFOLDER_SHCUTTREE)
                    hwndTree = m_hwndShortcuts;
                else if (pnmh->idFrom == IDC_FILESYSFOLDER_FOLDERTREE)
                    hwndTree = m_hwndFolders;

                if (hwndTree)
                {
                    switch (pnmh->code)
                    {
                        case TVN_ITEMEXPANDINGW:
                        case TVN_ITEMEXPANDINGA:
                            return OnTreeItemExpanding(hwndTree, (NMTREEVIEW*)pnmh);
                        case TVN_SELCHANGEDW:
                        case TVN_SELCHANGEDA:
                            return OnTreeItemSelChanged(hwndTree);
                        case NM_DBLCLK:
                            return OnTreeItemDoubleClicked(hwndTree);
                        case TVN_KEYDOWN:
                            if (((NMTVKEYDOWN*)pnmh)->wVKey == VK_RETURN)
                            {
                                // enter key press == double click
                                return OnTreeItemDoubleClicked(hwndTree);
                            }
                            break;
                        case NM_RCLICK:
                            return OnTreeItemRightClicked(hwndTree);
                        case NM_SETFOCUS:
                            return SetFocus();
                    }
                }
            }
            return 0;
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

LRESULT CFileSystemFolderPane::OnCreate()
{
    BOOL fHaveShortcuts = (g_FileSys.GetShortcutCount() > 0);

    // create the folders tree view
    m_hwndFolders = CreateWindowEx(0,
                                   WC_TREEVIEW,
                                   _T("FolderPaneFoldersTree"),
                                   (fHaveShortcuts ? 0 : WS_VISIBLE) |
                                   WS_CHILD | TVS_HASLINES | TVS_LINESATROOT |
                                   TVS_HASBUTTONS | TVS_SHOWSELALWAYS |
                                   TVS_DISABLEDRAGDROP,
                                   0, 0, 1, 1,
                                   m_hwndPane,
                                   (HMENU)IDC_FILESYSFOLDER_FOLDERTREE,
                                   _AtlBaseModule.GetModuleInstance(),
                                   NULL);

    // create the shortcuts tree view
    m_hwndShortcuts = CreateWindowEx(0,
                                     WC_TREEVIEW,
                                     _T("FolderPaneShortcutsTree"),
                                     (fHaveShortcuts ? WS_VISIBLE : 0) |
                                     WS_CHILD | TVS_HASLINES | TVS_LINESATROOT |
                                     TVS_HASBUTTONS | TVS_SHOWSELALWAYS |
                                     TVS_DISABLEDRAGDROP,
                                     0, 0, 1, 1,
                                     m_hwndPane,
                                     (HMENU)IDC_FILESYSFOLDER_SHCUTTREE,
                                     _AtlBaseModule.GetModuleInstance(),
                                     NULL);

    // set the fonts
    SendMessage(m_hwndFolders, WM_SETFONT, (WPARAM)m_hFont, 0);
    SendMessage(m_hwndShortcuts, WM_SETFONT, (WPARAM)m_hFont, 0);

    // set the image list
    m_himlFolders = ImageList_LoadBitmap(_AtlBaseModule.GetResourceInstance(),
                                         MAKEINTRESOURCE(IDB_ILFOLDERS),
                                         16, 0, RGB(0, 128, 128));
    TreeView_SetImageList(m_hwndFolders, m_himlFolders, TVSIL_NORMAL);
    TreeView_SetImageList(m_hwndShortcuts, m_himlFolders, TVSIL_NORMAL);

    // default to shortcuts view if we have shortcuts; otherwise open up folders
    m_nViewMode = fHaveShortcuts ? viewShortcuts : viewFolders;

    IVsUIShell* pUIShell = _VxModule.GetVsUIShell();      // un-addref'd

    // setup the toolbar
    if (pUIShell)
    {
        HRESULT hr;
        hr = pUIShell->SetupToolbar(m_hwndPane, static_cast<IVsToolWindowToolbar*>(this),
                                    &m_srpToolbarHost);
        IfFailGo(hr);

        hr = m_srpToolbarHost->AddToolbar(VSTWT_TOP, &guidEUGrp, IDM_TLB_FILESYSFOLDER);
        _ASSERTE(SUCCEEDED(hr));
        if (FAILED(hr))
        {
            m_srpToolbarHost.Release();
            goto OnError;
        }
    }

    // initialize the shortcuts
    if (fHaveShortcuts)
        InitShortcuts();

    // initialze the drives
    InitDrives();

    UpdateCommandUI(FALSE);

OnError:
    return 0;
}

LRESULT CFileSystemFolderPane::OnSize(WPARAM flag, int width, int height)
{
    if (m_srpToolbarHost)
    {
        m_srpToolbarHost->BorderChanged();
    }
    return 0;
}

LRESULT CFileSystemFolderPane::OnSetFocus()
{
    if (m_srpParentSplitter)
    {
       m_srpParentSplitter->NotifySplitter(static_cast<IVsSplitPane*>(this),
                                            PE_GOTFOCUS);
    }
    return 0;
}

LRESULT CFileSystemFolderPane::OnPaint()
{
    PAINTSTRUCT ps;
    RECT rc;

    BeginPaint(m_hwndPane, &ps);
  
    GetWindowRect(m_hwndFolders, &rc);
    ScreenToClient(m_hwndPane, (LPPOINT)&rc.left);
    ScreenToClient(m_hwndPane, (LPPOINT)&rc.right);
    InflateRect(&rc, 1, 1);
    FrameRect(ps.hdc, &rc, GetSysColorBrush(COLOR_3DSHADOW));

    EndPaint(m_hwndPane, &ps);

    return 0;
}

LRESULT CFileSystemFolderPane::OnTreeItemExpanding(HWND hwndTree,
                                                   NMTREEVIEW* pnmtv)
{
    _ASSERTE(pnmtv);

    HTREEITEM htiFolder = pnmtv->itemNew.hItem;
    CFileSystemFolderItem* pFolder = (CFileSystemFolderItem*)pnmtv->itemNew.lParam;
    BOOL fDisallowAction = TRUE;

    if (!pnmtv)
        return fDisallowAction;
    if (!pFolder)
        return fDisallowAction;

    _ASSERTE(pFolder);

    SendMessage(m_hwndShortcuts, WM_SETREDRAW, FALSE, 0);

    if (pnmtv->action == TVE_COLLAPSE)
    {
        // folder being collapsed... reset the collapsed state
        TreeView_Expand(hwndTree, htiFolder, TVE_COLLAPSE | TVE_COLLAPSERESET);
    }
    else
    {
        // folder being expanded... make sure we build up the hierarchy
        // and then fill it into the tree

        pFolder->EnsureHierarchy();

        TVITEM tvi;
        int nHierarchyCount = pFolder->GetHierarchyItemCount();

        // set cChildren to the number of items we have
        tvi.mask = TVIF_HANDLE | TVIF_CHILDREN;
        tvi.hItem = htiFolder;
        tvi.cChildren = nHierarchyCount;
        TreeView_SetItem(hwndTree, &tvi);

        if (nHierarchyCount > 0)
        {
            // add the hierarchy items into the tree
            CFileSystemFolderItem* pSubFolder;

            for (int i = 0; i < nHierarchyCount; i++)
            {
                pSubFolder = pFolder->GetHierarchyItem(i);
                _ASSERTE(pFolder);

                AddFolderToTree(hwndTree, htiFolder, pSubFolder, FALSE,
                                ILI_ILFOLDERS_FOLDERC, ILI_ILFOLDERS_FOLDERO);
            }

            // allow the expanding action to continue
            fDisallowAction = FALSE;
        }
    }

    SendMessage(m_hwndShortcuts, WM_SETREDRAW, TRUE, 0);

    return fDisallowAction;
}

LRESULT CFileSystemFolderPane::OnTreeItemSelChanged(HWND hwndTree)
{
    HTREEITEM htiSelected = TreeView_GetSelection(hwndTree);
    UpdateContextItem(htiSelected);

    UpdateCommandUI(FALSE);
    return 0;
}

LRESULT CFileSystemFolderPane::OnTreeItemDoubleClicked(HWND hwndTree)
{
    CFileSystemFolderItem* pSelFolder;

    if (m_nViewMode == viewFolders)
        pSelFolder = m_pSelFolderItem;
    else
        pSelFolder = m_pSelShortcutItem;

    UpdateFolderSelection(pSelFolder, TRUE);
    return 1;
}

LRESULT CFileSystemFolderPane::OnTreeItemRightClicked(HWND hwndTree)
{
    TV_HITTESTINFO hitInfo;
    HTREEITEM htiHit;
    DWORD dwPos = GetMessagePos();

    hitInfo.pt.x = LOWORD(dwPos);
    hitInfo.pt.y = HIWORD(dwPos);
    ScreenToClient(hwndTree, &hitInfo.pt);

    htiHit = TreeView_HitTest(hwndTree, &hitInfo);
    if (hitInfo.flags & TVHT_NOWHERE)
        htiHit = NULL;
    if (htiHit)
        TreeView_SelectItem(hwndTree, htiHit);

    return 0;
}

LRESULT CFileSystemFolderPane::OnContextMenu(short x, short y)
{
    HWND hwndTree = (m_nViewMode == viewFolders) ? m_hwndFolders : m_hwndShortcuts;
    HTREEITEM htiContext = TreeView_GetSelection(hwndTree);
    CComPtr<IOleComponentUIManager> srpUIMgr;
    POINT pt;
    POINTS pts;
    BOOL fKeyboard = FALSE;
    HRESULT hr;

    hr = _VxModule.QueryService(SID_OleComponentUIManager, IID_IOleComponentUIManager,
                              (void**)&srpUIMgr);
    IfFailGo(hr);

    if ((x == -1) && (y == -1))
    {
        // context menu being brought up from keyboard
        fKeyboard = TRUE;

        RECT rcTree;
        RECT rcItem;

        // figure out the mouse position; its horizontally and
        // vertically centered on the selected items rectangle, but
        // within the tree control's bounds

        GetClientRect(hwndTree, &rcTree);
        TreeView_GetItemRect(hwndTree, htiContext,
                             &rcItem, TRUE);

        x = (short)(rcItem.left + ((rcItem.right - rcItem.left) >> 1));
        if (x < 0)
            x = 0;
        if (x >= rcTree.right)
            x = (short)rcTree.right - 1;

        y = (short)(rcItem.top + ((rcItem.bottom - rcItem.top) >> 1));
        if (y < 0)
            y = 0;
        if (y >= rcTree.bottom)
            y = (short)rcTree.bottom - 1;
    }

    pt.x = x;
    pt.y = y;
    if (fKeyboard)
        ClientToScreen(hwndTree, &pt);
    pts.x = (short)pt.x;
    pts.y = (short)pt.y;

    // update the context item, and bring up the context menu
    UpdateContextItem(htiContext);
    hr = srpUIMgr->ShowContextMenu(OLEROLE_TOPLEVELCOMPONENT,
                                   guidEUGrp, IDM_CTX_FILESYSFOLDER, pts,
                                   static_cast<IOleCommandTarget*>(this));
    _ASSERTE_MSG(SUCCEEDED(hr), "Failed to bring up folder context menu");

OnError:
    return 0;
}


//*****************************************************************************
// CFileSystemFolderPane Command Handlers
//*****************************************************************************

HRESULT CFileSystemFolderPane::OnSwitchView(int nView)
{
    if (m_nViewMode != nView)
    {
        m_nViewMode = nView;
        if (m_nViewMode == viewFolders)
        {
            ShowWindow(m_hwndFolders, SW_SHOWNA);
            ShowWindow(m_hwndShortcuts, SW_HIDE);

            UpdateFolderSelection(m_pSelFolderItem, TRUE);
        }
        else
        {
            ShowWindow(m_hwndShortcuts, SW_SHOWNA);
            ShowWindow(m_hwndFolders, SW_HIDE);

            UpdateFolderSelection(m_pSelShortcutItem, TRUE);
        }

        UpdateCommandUI(FALSE);
    }
    return S_OK;
}

HRESULT CFileSystemFolderPane::OnRefresh(BOOL fThis)
{
    HWND hwndTree = (m_nViewMode == viewFolders) ? m_hwndFolders : m_hwndShortcuts;

    if (fThis)
    {
        CFileSystemFolderItem* pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;
        HTREEITEM htiThis;
        HTREEITEM htiPrevious;
        HTREEITEM htiParent;
        BOOL fExpanded;
        BOOL fStillExists;
        TVITEM tvi;

        SendMessage(hwndTree, WM_SETREDRAW, FALSE, 0);

        htiThis = TreeView_GetSelection(hwndTree);
        _ASSERTE(htiThis);

        htiParent = TreeView_GetParent(hwndTree, htiThis);
        htiPrevious = TreeView_GetPrevSibling(hwndTree, htiThis);
        if (htiPrevious == NULL)
            htiPrevious = htiParent;

        tvi.mask = TVIF_STATE;
        tvi.hItem = htiThis;
        tvi.stateMask = TVIS_EXPANDED;
        TreeView_GetItem(hwndTree, &tvi);
        fExpanded = (tvi.state & TVIS_EXPANDED) != 0;

        fStillExists = pSelItem->Refresh(fExpanded);
        TreeView_DeleteItem(hwndTree, htiThis);

        if (fStillExists)
        {
            switch (pSelItem->GetFolderType())
            {
                case CFileSystemFolderItem::fsiDrive:
                    htiThis = AddDriveToTree(pSelItem, TRUE);
                    break;
                case CFileSystemFolderItem::fsiShortcut:
                    htiThis = AddShortcutToTree(pSelItem, TRUE);
                    break;
                case CFileSystemFolderItem::fsiFolder:
                case CFileSystemFolderItem::fsiShortcutSubFolder:
                    htiThis = AddFolderToTree(hwndTree, htiParent, pSelItem, TRUE,
                                              ILI_ILFOLDERS_FOLDERC,
                                              ILI_ILFOLDERS_FOLDERO);
                    break;
                default:
                    _ASSERTE(FALSE);
            }
            if (fExpanded)
            {
                TreeView_Expand(hwndTree, htiThis, TVE_EXPAND);
            }
        }
        else
        {
            TreeView_SelectItem(hwndTree, htiPrevious);
        }

        SendMessage(hwndTree, WM_SETREDRAW, TRUE, 0);
    }
    else
    {
        SendMessage(hwndTree, WM_SETREDRAW, FALSE, 0);

        CFileSystemFolderItem* pFolder;
        int nFolders;

        TreeView_DeleteAllItems(hwndTree);
        UpdateContextItem(NULL);

        if (m_nViewMode == viewFolders)
        {
            nFolders = g_FileSys.GetDriveCount();
            for (int i = 0; i < nFolders; i++)
            {
                pFolder = g_FileSys.GetDrive(i);
                pFolder->Refresh(FALSE);
            }
            InitDrives();
        }
        else
        {
            nFolders = g_FileSys.GetShortcutCount();
            for (int i = 0; i < nFolders; i++)
            {
                pFolder = g_FileSys.GetShortcut(i);
                if (!pFolder->Refresh(FALSE))
                {
                    // the folder does not exist, so it was removed from the collection
                    // decrement both i and nFolders so we reflect the new count and
                    // look at the next folder which is now at index i...
                    // ... kinda hacky

                    i--;
                    nFolders--;
                }
            }

            if (g_FileSys.GetShortcutCount() > 0)
            {
                InitShortcuts();
            }
            else
            {
                OnSwitchView(viewFolders);
            }
        }

        SendMessage(hwndTree, WM_SETREDRAW, TRUE, 0);
    }

    return S_OK;
}

HRESULT CFileSystemFolderPane::OnAddShortcut()
{
    CFileSystemFolderItem* pSelItem;
    CFileSystemFolderItem* pShortcut;
    CString strPath;

    pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;
    _ASSERTE(pSelItem);
    _ASSERTE(pSelItem->GetFolderType() != CFileSystemFolderItem::fsiShortcut);

    pSelItem->GetFolderPath(strPath);
    pShortcut = g_FileSys.AddShortcut(strPath, TRUE);

    if (pShortcut)
    {
        OnSwitchView(viewShortcuts);
        AddShortcutToTree(pShortcut, TRUE);
    }
    else
    {
        CString strError;
        CString strCaption;

        strCaption.LoadString(IDS_FILESYS_BRSHCUT_TITLE);
        strError.Format(IDS_FILESYS_BRSHCUT_ERROR, strPath);

        ShowMessage(strCaption, strError);

        OnRefresh(TRUE);
    }
    UpdateCommandUI(FALSE);

    return S_OK;
}

HRESULT CFileSystemFolderPane::OnDeleteShortcut()
{
    _ASSERTE(m_nViewMode == viewShortcuts);
    _ASSERTE(m_pSelShortcutItem);

    CFileSystemFolderItem* pSelItem = m_pSelShortcutItem;
    HTREEITEM htiSelItem = pSelItem->GetFolderTreeHandle();

    m_pSelShortcutItem = NULL;
    UpdateFolderSelection(NULL, TRUE);

    TreeView_DeleteItem(m_hwndShortcuts, htiSelItem);
    g_FileSys.RemoveShortcut(pSelItem);

    UpdateCommandUI(FALSE);

    return S_OK;
}

HRESULT CFileSystemFolderPane::OnBrowseShortcut()
{
    _ASSERTE(m_nViewMode == viewShortcuts);

    VSBROWSEINFOW vsbi;
    CString strCaption;
    TCHAR szPath[_MAX_PATH];

    CVsModalState modalState;

    strCaption.LoadString(IDS_FILESYS_BROWSE_SHORTCUT);

    memset(&vsbi, 0, sizeof(VSBROWSEINFOW));
    vsbi.lStructSize = sizeof(VSBROWSEINFOW);
    vsbi.hwndOwner = modalState.GetDialogOwnerHwnd();
    vsbi.pwzDlgTitle = strCaption;
    vsbi.pwzDirName = szPath;
    vsbi.nMaxDirName = MAX_PATH;
    vsbi.pwzInitialDir = NULL;
    vsbi.dwHelpTopic = 0;
    vsbi.dwFlags = BIF_RETURNONLYFSDIRS;

    CComPtr<IVsUIShell> srpUIShell;
    _VxModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpUIShell);

    if (SUCCEEDED(srpUIShell->GetDirectoryViaBrowseDlg(&vsbi)))
    {
        CFileSystemFolderItem* pShortcut;
        BOOL fCreatedShortcut = FALSE;

        // must contain a '\' from either drive letter or from UNC path
        if (_tcschr(szPath, _T('\\')))
        {
            size_t nPathLen = _tcslen(szPath);

            // remove trailing '\' if one exists
            if (szPath[nPathLen - 1] == _T('\\'))
                szPath[nPathLen - 1] = _T('\0');

            // add the shortcut to the file system and the tree
            pShortcut = g_FileSys.AddShortcut(szPath, TRUE);
            if (pShortcut)
            {
                AddShortcutToTree(pShortcut, TRUE);
                fCreatedShortcut = TRUE;

                UpdateCommandUI(FALSE);
            }
        }

        if (!fCreatedShortcut)
        {
            CString strError;

            strCaption.LoadString(IDS_FILESYS_BRSHCUT_TITLE);
            strError.Format(IDS_FILESYS_BRSHCUT_ERROR, szPath);

            ShowMessage(strCaption, strError);
        }
    }

    return S_OK;
}

HRESULT CFileSystemFolderPane::OnFindHere()
{
    CFileSystemFolderItem* pSelItem;
    CString strFolderPath;
    CComBSTR bstrFolderPath;

    CComPtr<_DTE> srpDTE;
    CComPtr<Find> srpFind;
    CComBSTR bstrCommand;
    HRESULT hr;

    pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;
    _ASSERTE(pSelItem);

    pSelItem->GetFolderPath(strFolderPath);

    hr = _VxModule.QueryService(SID_SDTE, IID__DTE, (void**)&srpDTE);
    IfFailGoMsg(hr, "Failed to get SID_SDTE");

    hr = srpDTE->get_Find(&srpFind);
    IfFailGo(hr);

    bstrFolderPath.Attach(strFolderPath.AllocSysString());
    hr = srpFind->put_SearchPath(bstrFolderPath);
    _ASSERTE(SUCCEEDED(hr));

    hr = srpFind->put_Target(vsFindTargetFiles);
    _ASSERTE(SUCCEEDED(hr));

    srpFind->put_SearchSubfolders(VARIANT_TRUE);
    _ASSERTE(SUCCEEDED(hr));

    srpFind->put_Action(vsFindActionFindAll);
    _ASSERTE(SUCCEEDED(hr));

    bstrCommand = L"Edit.FindinFiles";
    hr = srpDTE->ExecuteCommand(bstrCommand);
    IfFailGo(hr);

OnError:
    return hr;
}

HRESULT CFileSystemFolderPane::OnExplorer()
{
    CFileSystemFolderItem* pSelItem;
    CString strPath;

    USES_CONVERSION;

    pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;
    _ASSERTE(pSelItem);

    pSelItem->GetFolderPath(strPath);

    // No Unicode wrapper for ShellExecuteW... so for now call the Ansi
    // version directly
    ShellExecuteA(NULL, "explore", T2CA((LPCTSTR)strPath), NULL, NULL, SW_SHOW);
    return S_OK;
}

HRESULT CFileSystemFolderPane::OnMSDOS()
{
    CFileSystemFolderItem* pSelItem;
    CString strPath;
    CString strParams;

    USES_CONVERSION;

    pSelItem = (m_nViewMode == viewFolders) ? m_pSelFolderItem : m_pSelShortcutItem;
    _ASSERTE(pSelItem);

    pSelItem->GetFolderPath(strPath);
    strParams.Format(_T("/K cd /D \"%s\""), strPath);


    const TCHAR szCmdName[] = _T("cmd.exe");
    TCHAR szCmdPath[_MAX_PATH + 5 + 7 /* cmd.exe */ ];
    szCmdPath[0] = '"';
    UINT cchCopied = ::GetSystemDirectory(&szCmdPath[1], _MAX_PATH + 1);
    if (cchCopied == 0)
        return HRESULT_FROM_WIN32(::GetLastError());
    if (cchCopied > _MAX_PATH)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    if (szCmdPath[cchCopied-1] != _T('\\'))
        _tcscat(szCmdPath, _T("\\"));
    _tcscat(szCmdPath, szCmdName);
    _tcscat(szCmdPath, _T("\""));

    ShellExecute(NULL, NULL, szCmdPath, strParams, NULL, SW_SHOW);
    return S_OK;
}


//*****************************************************************************
// CFileSystemFolderPane Implementation
//*****************************************************************************

void CFileSystemFolderPane::InitDrives()
{
    CFileSystemFolderItem* pDrive;
    int nDrives = g_FileSys.GetDriveCount();

    _ASSERTE(nDrives > 0);

    SendMessage(m_hwndFolders, WM_SETREDRAW, FALSE, 0);

    for (int i = 0; i < nDrives; i++)
    {
        pDrive = g_FileSys.GetDrive(i);
        _ASSERTE(pDrive);

        AddDriveToTree(pDrive, FALSE);
    }

    SendMessage(m_hwndFolders, WM_SETREDRAW, TRUE, 0);
}

void CFileSystemFolderPane::InitShortcuts()
{
    CFileSystemFolderItem* pShortcut;
    int nShortcuts = g_FileSys.GetShortcutCount();

    _ASSERTE(nShortcuts > 0);

    SendMessage(m_hwndShortcuts, WM_SETREDRAW, FALSE, 0);

    for (int i = 0; i < nShortcuts; i++)
    {
        pShortcut = g_FileSys.GetShortcut(i);
        _ASSERTE(pShortcut);

        AddShortcutToTree(pShortcut, FALSE);
    }

    SendMessage(m_hwndShortcuts, WM_SETREDRAW, TRUE, 0);
}

HTREEITEM CFileSystemFolderPane::AddDriveToTree(CFileSystemFolderItem* pDrive,
                                                BOOL fSelect)
{
    int iImage;
    int iSelectedImage;

    if (!pDrive)
        return NULL;

    switch (pDrive->GetDriveType())
    {
        case CFileSystemFolderItem::fsdUnknown:
            iImage = ILI_ILFOLDERS_FOLDERC;
            iSelectedImage = ILI_ILFOLDERS_FOLDERC;
            break;
        case CFileSystemFolderItem::fsdFixed:
            iImage = iSelectedImage = ILI_ILFOLDERS_FIXEDDRIVE;
            break;
        case CFileSystemFolderItem::fsdFloppy:
            iImage = iSelectedImage = ILI_ILFOLDERS_FLOPPYDRIVE;
            break;
        case CFileSystemFolderItem::fsdCDROM:
            iImage = iSelectedImage = ILI_ILFOLDERS_CDROMDRIVE;
            break;
        case CFileSystemFolderItem::fsdNetwork:
            iImage = iSelectedImage = ILI_ILFOLDERS_NETWORKDRIVE;
            break;
    }

    return AddFolderToTree(m_hwndFolders, TVI_ROOT, pDrive, fSelect,
                           iImage, iSelectedImage);
}

HTREEITEM CFileSystemFolderPane::AddShortcutToTree(CFileSystemFolderItem* pShortcut,
                                                   BOOL fSelect)
{
    return AddFolderToTree(m_hwndShortcuts, TVI_ROOT, pShortcut, fSelect,
                           ILI_ILFOLDERS_SHFOLDERC, ILI_ILFOLDERS_SHFOLDERO);
}

HTREEITEM CFileSystemFolderPane::AddFolderToTree(HWND hwndTree, HTREEITEM htiParent,
                                                 CFileSystemFolderItem* pFolder,
                                                 BOOL fSelect,
                                                 int iImage, int iSelectedImage)
{
    _ASSERTE(pFolder);
    if (!pFolder)
        return NULL;

    TV_INSERTSTRUCT tvis;

    tvis.hParent = htiParent;
    tvis.hInsertAfter = TVI_SORT;
    tvis.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM | TVIF_TEXT |
                     TVIF_CHILDREN;
    tvis.item.iImage = iImage;
    tvis.item.iSelectedImage = iSelectedImage;
    tvis.item.lParam = (LPARAM)pFolder;
    tvis.item.cChildren = 1;
    tvis.item.pszText = (LPTSTR)pFolder->GetFolderText();

    HTREEITEM hti = TreeView_InsertItem(hwndTree, &tvis);
    _ASSERTE_MSG(hti, "Failed to add shortcut to tree");

    pFolder->SetFolderTreeHandle(hti);
    if (fSelect)
    {
        TreeView_SelectItem(hwndTree, hti);
        TreeView_EnsureVisible(hwndTree, hti);
    }

    return hti;
}

void CFileSystemFolderPane::UpdateContextItem(HTREEITEM htiContext)
{
    HWND hwndTree = (m_nViewMode == viewFolders) ? m_hwndFolders : m_hwndShortcuts;
    CFileSystemFolderItem* pSelItem = NULL;

    if (htiContext)
    {
        TV_ITEM tvi;

        tvi.mask = TVIF_PARAM | TVIF_HANDLE;
        tvi.hItem = htiContext;

        TreeView_GetItem(hwndTree, &tvi);
        pSelItem = (CFileSystemFolderItem*)tvi.lParam;
    }
    if (m_nViewMode == viewFolders)
        m_pSelFolderItem = pSelItem;
    else
        m_pSelShortcutItem = pSelItem;

    UpdateFolderSelection(pSelItem, FALSE);
}

void CFileSystemFolderPane::UpdateFolderSelection(CFileSystemFolderItem* pSelFolder,
                                                  BOOL fNotifyFilePane)
{
    m_srpSelection->UpdateFolderSelection((DWORD_PTR)pSelFolder);

    if (fNotifyFilePane)
        m_srpFilePane->SetCurrentFolder((DWORD_PTR)pSelFolder);
}
