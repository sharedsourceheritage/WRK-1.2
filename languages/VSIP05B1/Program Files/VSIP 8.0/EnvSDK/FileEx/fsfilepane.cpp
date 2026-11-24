
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
// Implementation of CFileSystemFilePane
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "FSFilePane.h"
#include "FSSelection.h"

BOOL CFileSystemFilePane::s_fClassRegistered = FALSE;
LPCTSTR CFileSystemFilePane::s_szClassName = _T("WCFileSysFilePane");
WNDPROC CFileSystemFilePane::s_lpfnEditProc = NULL;

#define MAX_CMDTEXT_LEN     1024
#define WM_CMDEDIT_ENTER    (WM_USER + 1)

//*****************************************************************************
// CFileSystemFilePane Constructor/Destructor
//*****************************************************************************

CFileSystemFilePane::CFileSystemFilePane()
{
    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Creating CFileSystemFilePane: 0x%X\n"), this);
    }

    m_hwndParent = NULL;
    m_hwndPane = NULL;
    m_hwndFiles = NULL;
    m_hwndCmdText = NULL;
    m_hwndCmdExec = NULL;
    m_hFont = NULL;
    m_himlState = NULL;
    m_hiconCmdExec = NULL;

    m_pSelFolder = NULL;
    m_pCachedFolder = NULL;
    m_pSelFile = NULL;

    m_nSortType = sortName;

    m_dwBroadcastCookie = 0;

    m_fIgnoreSelChanges = FALSE;
}

CFileSystemFilePane::~CFileSystemFilePane()
{
    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Destructing CFileSystemFilePane: 0x%X\n"), this);
    }

    _ASSERTE_MSG(m_dwBroadcastCookie == 0,
                 "CFileSystemFilePane did not unadvise from IVsBroadcastMessageEvents");

    if (m_himlState)
    {
        ImageList_Destroy(m_himlState);
        m_himlState = NULL;
    }

    if (m_hiconCmdExec)
    {
        DeleteObject(m_hiconCmdExec);
        m_hiconCmdExec = NULL;
    }
}


//*****************************************************************************
// CFileSystemFilePane IVsSplitPane Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFilePane::SetParentSplitter(
                    /*[in]*/ IVsSplitter* pSplitter)
{
    m_srpParentSplitter = pSplitter;
    return S_OK;
}

STDMETHODIMP CFileSystemFilePane::GetParentSplitter(
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

STDMETHODIMP CFileSystemFilePane::SetFocus(void)
{
    ::SetFocus(m_hwndFiles);
    m_srpSelection->UpdateFileSelection((DWORD_PTR)m_pSelFile);
    return S_OK;
}

STDMETHODIMP CFileSystemFilePane::SetPosition(
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

STDMETHODIMP CFileSystemFilePane::GetPosition(
                    /*[out]*/ long* piLeft,
                    /*[out]*/ long* piTop,
                    /*[out]*/ long* piRight,
                    /*[out]*/ long* piBottom)
{
    return E_NOTIMPL;
}

STDMETHODIMP CFileSystemFilePane::GetSizeExtents(
                    /*[out]*/ long* piMinHorz,
                    /*[out]*/ long* piMaxHorz,
                    /*[out]*/ long* piMinVert,
                    /*[out]*/ long* piMaxVert)
{
    return E_NOTIMPL;
}

STDMETHODIMP CFileSystemFilePane::GetParentWindow(
                    /*[out]*/ HWND* phwndParent)
{
    ExpectedPtrRet(phwndParent);

    *phwndParent = m_hwndParent;
    return S_OK;
}

STDMETHODIMP CFileSystemFilePane::GetPaneFlags(
                    /*[out]*/ DWORD* pdwPaneFlags)
{
    ExpectedPtrRet(pdwPaneFlags);

    *pdwPaneFlags = PF_ELASTICY;
    return S_OK;
}

STDMETHODIMP CFileSystemFilePane::ClosePane(void)
{
    TreeView_DeleteAllItems(m_hwndFiles);
    if (m_pCachedFolder)
    {
        g_FileSys.FreeFolderFiles(m_pCachedFolder);
        m_pCachedFolder = NULL;
    }
    m_pSelFolder = NULL;
    m_pSelFile = NULL;

    UnsubclassCmdEdit();

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

STDMETHODIMP CFileSystemFilePane::NotifyPane(
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

STDMETHODIMP CFileSystemFilePane::DetachPane(void)
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
// CFileSystemFilePane IOleCommandTarget Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFilePane::QueryStatus(
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
            case cmdidFilesOpenFile:
            case cmdidFilesOpenFileWith:
            case cmdidFilesPreviewFile:
                cmdf = OLECMDF_SUPPORTED;
                if (m_pSelFile)
                    cmdf |= OLECMDF_ENABLED;
                hr = S_OK;
                break;
            case cmdidFilesRefresh:
                cmdf = OLECMDF_SUPPORTED;
                if (m_pSelFolder)
                    cmdf |= OLECMDF_ENABLED;
                hr = S_OK;
                break;
            case cmdidFilesSortName:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                if (m_nSortType == sortName)
                    cmdf |= OLECMDF_LATCHED;
                hr = S_OK;
                break;
            case cmdidFilesSortExtension:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                if (m_nSortType == sortExtension)
                    cmdf |= OLECMDF_LATCHED;
                hr = S_OK;
                break;
            case cmdidFilesSortReadOnly:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                if (m_nSortType == sortReadOnly)
                    cmdf |= OLECMDF_LATCHED;
                hr = S_OK;
                break;
            case cmdidFilesFilter:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                hr = S_OK;
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

                        cmdf = OLECMDF_SUPPORTED;

                        // enable only if it doesn't require a selected folder (cmd applies
                        // only to folder pane) and we either have a selected file or
                        // the command does not require a file
                        if ((m_pSelFolder || !pCommand->RequiresFolder()) &&
                            (m_pSelFile || !pCommand->RequiresFile()))
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

STDMETHODIMP CFileSystemFilePane::Exec(
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
        switch (nCmdID)
        {
            case cmdidFilesOpenFile:
            case cmdidFilesOpenFileWith:
                fHandled = TRUE;
                hr = OnOpenFile(nCmdID == cmdidFilesOpenFileWith);
                break;
            case cmdidFilesPreviewFile:
                fHandled = TRUE;
                hr = OnPreviewFile();
                break;
            case cmdidFilesRefresh:
                hr = OnRefresh();
                break;
            case cmdidFilesSortName:
                fHandled = TRUE;
                hr = (m_nSortType != sortName) ? OnSortFiles(sortName) : S_OK;
                break;
            case cmdidFilesSortExtension:
                fHandled = TRUE;
                hr = (m_nSortType != sortExtension) ? OnSortFiles(sortExtension) : S_OK;
                break;
            case cmdidFilesSortReadOnly:
                fHandled = TRUE;
                hr = (m_nSortType != sortReadOnly) ? OnSortFiles(sortReadOnly) : S_OK;
                break;
            case cmdidFilesFilter:
                if (pvaIn)
                {
                    // new filter typed
                    hr = OnFilterChanged(pvaIn);
                    fHandled = TRUE;
                }
                else if (pvaOut)
                {
                    // return current filter
                    hr = g_FileSys.ExecGetCurrentFilter(pvaOut);
                    fHandled = TRUE;
                }
                break;
            case cmdidFilesFilterHandler:
                {
                    // return list of filters
                    hr = g_FileSys.ExecFilterHandler(pvaOut);
                    fHandled = TRUE;
                }
                break;
            case cmdidDefineCommands:
                fHandled = TRUE;
                if (g_FileSys.DefineCommands())
                    UpdateCommandUI(TRUE);
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

                    hr = pCommand->Execute(m_pSelFolder, m_pSelFile);
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
// CFileSystemFilePane IVsToolWindowToolbar Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFilePane::GetBorder(
                    /*[out]*/ RECT* prc)
{
    _ASSERTE(m_hwndPane && IsWindow(m_hwndPane));

    GetClientRect(m_hwndPane, prc);
    return S_OK;
}

STDMETHODIMP CFileSystemFilePane::SetBorderSpace(
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

    MoveWindow(m_hwndFiles,
               rect.left + 1, rect.top + 2,
               rect.right - 2, rect.bottom - 4 - 16 - 3,
               TRUE);
    MoveWindow(m_hwndCmdText,
               rect.left + 1, rect.top + 2 + rect.bottom - 4 - 16 + 1,
               rect.right - 2 - 20, 16,
               TRUE);
    MoveWindow(m_hwndCmdExec,
               rect.left + 1 + rect.right - 20 + 1,
               rect.top + 2 + rect.bottom - 4 - 16, 18, 18,
               TRUE);
    return S_OK;
}


//*****************************************************************************
// CFileSystemFilePane IVsBroadcastMessageEvents Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFilePane::OnBroadcastMessage(
                    /*[in]*/ UINT   msg,
                    /*[in]*/ WPARAM wParam,
                    /*[in]*/ LPARAM lParam)
{
    // Propagate message to child window
    SendMessage(m_hwndFiles, msg, wParam, lParam);

    return S_OK;
}


//*****************************************************************************
// CFileSystemFilePane IFileSystemPane Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFilePane::Initialize(
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

STDMETHODIMP CFileSystemFilePane::GetPaneWindow(
                    /*[out]*/ HWND* phwndPane)
{
    _ASSERTE(phwndPane);
    _ASSERTE(m_hwndParent);
    _ASSERTE(m_srpSiteSP);
    _ASSERTE(m_hFont);

    HRESULT hr;

    if (!m_hwndPane)
    {
        if (!phwndPane)
            return E_POINTER;

        if (!s_fClassRegistered)
            s_fClassRegistered = RegisterWindowClass();
        ExpectedExprGo(s_fClassRegistered);

        *phwndPane = CreateWindowEx(WS_EX_CONTROLPARENT,               // dwExStyle
                                    s_szClassName,                     // lpszClassName
                                    _T("FileSystemBrowser FilePane"),  // lpszWindowName
                                    WS_VISIBLE | WS_CHILD |
                                    WS_CLIPSIBLINGS |
                                    WS_CLIPCHILDREN,                   // dwStyle
                                    0, 0, 1, 1,                        // x, y, nWidth, nHeight
                                    m_hwndParent,                      // hWndParent
                                    (HMENU)IDC_FILESYSPANE_FILE,       // hMenu
                                    _AtlBaseModule.GetModuleInstance(),// hInstance
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
// CFileSystemFilePane IFileSystemFilePane Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemFilePane::SetCurrentFolder(
                    /*[in]*/ DWORD_PTR dwFolderPtr)
{
    CFileSystemFolderItem* pFolder = (CFileSystemFolderItem*)dwFolderPtr;

    if ((!pFolder && m_pSelFolder) ||
        (pFolder && !m_pSelFolder) ||
        (pFolder && m_pSelFolder && pFolder->ComparePath(m_pSelFolder) != 0))
    {
        m_pSelFolder = pFolder;

        m_fIgnoreSelChanges = TRUE;

        SendMessage(m_hwndFiles, WM_SETREDRAW, FALSE, 0);
        TreeView_DeleteAllItems(m_hwndFiles);

        if (m_pCachedFolder)
        {
            g_FileSys.FreeFolderFiles(m_pCachedFolder);
            m_pCachedFolder = NULL;
        }

        m_pSelFile = NULL;

        if (m_pSelFolder != NULL)
        {
            m_pCachedFolder = g_FileSys.GetFolderFiles(m_pSelFolder);
            if (m_pCachedFolder)
            {
                CFileSystemFileItem* pFile;
                int nFiles = m_pCachedFolder->GetFileCount();

                for (int i = 0; i < nFiles; i++)
                {
                    pFile = m_pCachedFolder->GetFile(i);
                    _ASSERTE(pFile);

                    AddFileToTree(pFile);
                }
            }
        }

        OnSortFiles(m_nSortType);
        TreeView_SelectItem(m_hwndFiles, TreeView_GetChild(m_hwndFiles, TVI_ROOT));
        SendMessage(m_hwndFiles, WM_SETREDRAW, TRUE, 0);

        m_fIgnoreSelChanges = FALSE;
    }

    SetEnabledState();
    OnTreeItemSelChanged();
    UpdateCommandUI(FALSE);
    return S_OK;
}


//*****************************************************************************
// CFileSystemFilePane Windows Related Implementation
//*****************************************************************************

BOOL CFileSystemFilePane::RegisterWindowClass()
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
    wc.lpszClassName = s_szClassName;

    return RegisterClass(&wc);
}

LRESULT CALLBACK CFileSystemFilePane::StaticWndProc(HWND hwnd, UINT iMsg,
                                                    WPARAM wParam, LPARAM lParam)
{
    CFileSystemFilePane* pThis = NULL;

    if (iMsg == WM_CREATE)
    {
        pThis = (CFileSystemFilePane*)((LPCREATESTRUCT)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, EB_THIS, (LONG_PTR)pThis);
        pThis->m_hwndPane = hwnd;
    }
    else
        pThis = (CFileSystemFilePane*)GetWindowLongPtr(hwnd, EB_THIS);

    if (pThis)
        return pThis->WndProc(hwnd, iMsg, wParam, lParam);
    else
        return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

LRESULT CALLBACK CFileSystemFilePane::CmdEditWndProc(HWND hwnd, UINT iMsg,
                                                     WPARAM wParam, LPARAM lParam)
{
    if ((iMsg == WM_KEYDOWN) && (wParam == VK_RETURN))
    {
        HWND hwndFilePane = GetParent(hwnd);
        _ASSERTE(hwndFilePane);

        SendMessage(hwndFilePane, WM_CMDEDIT_ENTER, 0, 0);
    }

    return CallWindowProc(s_lpfnEditProc, hwnd, iMsg, wParam, lParam);
}


//*****************************************************************************
// CFileSystemFilePane Message Handlers
//*****************************************************************************

LRESULT CFileSystemFilePane::WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
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

                if (pnmh->idFrom == IDC_FILESYSFILE_TREE)
                {
                    switch (pnmh->code)
                    {
                        case TVN_SELCHANGEDW:
                        case TVN_SELCHANGEDA:
                            return OnTreeItemSelChanged();
                        case NM_DBLCLK:
                            return OnTreeItemDoubleClicked();
                        case TVN_KEYDOWN:
                            if (((NMTVKEYDOWN*)pnmh)->wVKey == VK_RETURN)
                            {
                                // enter key press == double click
                                return OnTreeItemDoubleClicked();
                            }
                            break;
                        case NM_RCLICK:
                            return OnTreeItemRightClicked();
                        case NM_SETFOCUS:
                            return SetFocus();
                    }
                }
            }
            return 0;
        case WM_DRAWITEM:
            return OnDrawItem((DRAWITEMSTRUCT*)lParam);
        case WM_COMMAND:
            {
                int nID = LOWORD(wParam);
                int nCommand = HIWORD(wParam);

                if ((nID == IDC_FILESYSFILE_CMDEXEC) &&
                    (nCommand == BN_CLICKED))
                {
                    return OnExecCommand();
                }
            }
            return 0;
        case WM_CMDEDIT_ENTER:
            return OnExecCommand();
    }
    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

LRESULT CFileSystemFilePane::OnCreate()
{
    HRESULT hr;

    // Create the child controls
    m_hwndFiles = CreateWindowEx(0,
                                 WC_TREEVIEW,
                                 _T("FilePaneFilesTree"),
                                 WS_VISIBLE | WS_CHILD | WS_TABSTOP |
                                 TVS_DISABLEDRAGDROP | TVS_SHOWSELALWAYS,
                                 0, 0, 1, 1,
                                 m_hwndPane,
                                 (HMENU)IDC_FILESYSFILE_TREE,
                                 _AtlBaseModule.GetModuleInstance(),
                                 NULL);
    _ASSERTE(m_hwndFiles);
    SendMessage(m_hwndFiles, WM_SETFONT, (WPARAM)m_hFont, 0);

    m_hwndCmdText = CreateWindowEx(0,
                                   _T("EDIT"),
                                   _T(""),
                                   WS_VISIBLE | WS_CHILD | WS_TABSTOP |
                                   ES_AUTOHSCROLL,
                                   0, 0, 1, 1,
                                   m_hwndPane,
                                   (HMENU)IDC_FILESYSFILE_CMDTEXT,
                                   _AtlBaseModule.GetModuleInstance(),
                                   NULL);
    _ASSERTE(m_hwndCmdText);
    SendMessage(m_hwndCmdText, WM_SETFONT, (WPARAM)m_hFont, 0);
    SendMessage(m_hwndCmdText, EM_LIMITTEXT, MAX_CMDTEXT_LEN, 0);
    SendMessage(m_hwndCmdText, EM_SETMARGINS, EC_LEFTMARGIN | EC_RIGHTMARGIN, MAKELPARAM(4, 4));
    SubclassCmdEdit();

    m_hwndCmdExec = CreateWindowEx(0,
                                   _T("BUTTON"),
                                   _T(""),
                                   WS_VISIBLE | WS_CHILD | WS_TABSTOP |
                                   BS_OWNERDRAW,
                                   0, 0, 1, 1,
                                   m_hwndPane,
                                   (HMENU)IDC_FILESYSFILE_CMDEXEC,
                                   _AtlBaseModule.GetModuleInstance(),
                                   NULL);
    _ASSERTE(m_hwndCmdExec);

    m_hiconCmdExec = LoadIcon(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDI_FILES_CMDEXEC));
    _ASSERTE(m_hiconCmdExec);

    // set the image list
    TreeView_SetImageList(m_hwndFiles, g_ExtMgr.GetExtensionsImageList(),
                          TVSIL_NORMAL);

    // set the state image list
    m_himlState = ImageList_LoadBitmap(_AtlBaseModule.GetResourceInstance(),
                                       MAKEINTRESOURCE(IDB_ILSTATE),
                                       9, 0, RGB(0, 128, 128));
    TreeView_SetImageList(m_hwndFiles, m_himlState, TVSIL_STATE);

    // Items appear squished, so we'll tweak the item height
    TreeView_SetItemHeight(m_hwndFiles, TreeView_GetItemHeight(m_hwndFiles) + 2);

    SetEnabledState();

    IVsUIShell* pUIShell = _VxModule.GetVsUIShell();      // un-addref'd

    if (pUIShell)
    {
        hr = pUIShell->SetupToolbar(m_hwndPane, static_cast<IVsToolWindowToolbar*>(this),
                                    &m_srpToolbarHost);
        IfFailGo(hr);

        hr = m_srpToolbarHost->AddToolbar(VSTWT_TOP, &guidEUGrp, IDM_TLB_FILESYSFILE);
        _ASSERTE(SUCCEEDED(hr));
        if (FAILED(hr))
        {
            m_srpToolbarHost.Release();
            goto OnError;
        }
    }

OnError:
    return 0;
}

LRESULT CFileSystemFilePane::OnSize(WPARAM flag, int width, int height)
{
    if (m_srpToolbarHost)
    {
        m_srpToolbarHost->BorderChanged();
    }
    return 0;
}

LRESULT CFileSystemFilePane::OnSetFocus()
{
    if (m_srpParentSplitter)
        m_srpParentSplitter->NotifySplitter(static_cast<IVsSplitPane*>(this),
                                            PE_GOTFOCUS);
    return 0;
}

LRESULT CFileSystemFilePane::OnPaint()
{
    PAINTSTRUCT ps;
    RECT rc;

    BeginPaint(m_hwndPane, &ps);
  
    GetWindowRect(m_hwndFiles, &rc);
    ScreenToClient(m_hwndPane, (LPPOINT)&rc.left);
    ScreenToClient(m_hwndPane, (LPPOINT)&rc.right);
    InflateRect(&rc, 1, 1);
    FrameRect(ps.hdc, &rc, GetSysColorBrush(COLOR_3DSHADOW));

    GetWindowRect(m_hwndCmdText, &rc);
    ScreenToClient(m_hwndPane, (LPPOINT)&rc.left);
    ScreenToClient(m_hwndPane, (LPPOINT)&rc.right);
    InflateRect(&rc, 1, 1);
    FrameRect(ps.hdc, &rc, GetSysColorBrush(COLOR_3DSHADOW));

    EndPaint(m_hwndPane, &ps);

    return 0;
}

LRESULT CFileSystemFilePane::OnDrawItem(DRAWITEMSTRUCT* pdis)
{
    if (!pdis)
        return FALSE;

    if (pdis->CtlID == IDC_FILESYSFILE_CMDEXEC)
    {
        _ASSERTE(pdis->CtlType == ODT_BUTTON);

        COLORREF clrTopLeft;
        COLORREF clrBottomRight;
        RECT rc;

        BOOL fEnabled = (pdis->itemState & ODS_DISABLED) == 0;

#if _3DBORDERS
        BOOL fSelected = pdis->itemState & ODS_SELECTED;
        if (fSelected)
        {
            clrTopLeft = GetSysColor(COLOR_BTNSHADOW);
            clrBottomRight = GetSysColor(COLOR_BTNHIGHLIGHT);
        }
        else
        {
            clrTopLeft = GetSysColor(COLOR_BTNHIGHLIGHT);
            clrBottomRight = GetSysColor(COLOR_BTNSHADOW);
        }
#else
        clrTopLeft = GetSysColor(COLOR_BTNFACE);
        clrBottomRight = GetSysColor(COLOR_BTNFACE);
#endif // _3DBORDERS

        // left and top
        SetBkColor(pdis->hDC, clrTopLeft);

        rc = pdis->rcItem;
        rc.right = rc.left + 1;
        ExtTextOut(pdis->hDC, 0, 0, ETO_OPAQUE, &rc, NULL, 0, NULL);
        rc.right = pdis->rcItem.right;
        rc.bottom = rc.top + 1;
        ExtTextOut(pdis->hDC, 0, 0, ETO_OPAQUE, &rc, NULL, 0, NULL);

        // right and bottom
        SetBkColor(pdis->hDC, clrBottomRight);

        rc.bottom = pdis->rcItem.bottom;
        rc.left = rc.right - 1;
        ExtTextOut(pdis->hDC, 0, 0, ETO_OPAQUE, &rc, NULL, 0, NULL);
        rc.left = pdis->rcItem.left;
        rc.top = rc.bottom - 1;
        ExtTextOut(pdis->hDC, 0, 0, ETO_OPAQUE, &rc, NULL, 0, NULL);

        if (fEnabled)
        {
            DrawStateA(pdis->hDC, NULL, NULL, (LONG_PTR)m_hiconCmdExec, 0, -7, -7, 32, 32,
                       DST_ICON);
        }
        else
        {
            DrawStateA(pdis->hDC, NULL, NULL, (LONG_PTR)m_hiconCmdExec, 0, -7, -7, 32, 32,
                       DSS_DISABLED | DST_ICON);
        }

        return TRUE;
    }

    return FALSE;
}

LRESULT CFileSystemFilePane::OnTreeItemSelChanged()
{
    if (m_fIgnoreSelChanges)
        return 0;

    HTREEITEM htiSelected = TreeView_GetSelection(m_hwndFiles);
    UpdateContextItem(htiSelected);

    UpdateCommandUI(FALSE);
    return 0;
}

LRESULT CFileSystemFilePane::OnTreeItemDoubleClicked()
{
    if (m_pSelFile)
    {
        m_srpSelection->UpdateFileSelection((DWORD_PTR)m_pSelFile);

        HRESULT hr;

        hr = OnOpenFile(FALSE);
        if (FAILED(hr))
        {
            _VxModule.ReportErrorInfo(hr);
        }
    }
    return 1;
}

LRESULT CFileSystemFilePane::OnTreeItemRightClicked()
{
    TV_HITTESTINFO hitInfo;
    HTREEITEM htiHit;
    DWORD dwPos = GetMessagePos();

    hitInfo.pt.x = LOWORD(dwPos);
    hitInfo.pt.y = HIWORD(dwPos);
    ScreenToClient(m_hwndFiles, &hitInfo.pt);

    htiHit = TreeView_HitTest(m_hwndFiles, &hitInfo);
    if (hitInfo.flags & TVHT_NOWHERE)
        htiHit = NULL;
    if (htiHit)
        TreeView_SelectItem(m_hwndFiles, htiHit);

    return 0;
}

LRESULT CFileSystemFilePane::OnContextMenu(short x, short y)
{
    HTREEITEM htiContext = TreeView_GetSelection(m_hwndFiles);
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

        GetClientRect(m_hwndFiles, &rcTree);
        TreeView_GetItemRect(m_hwndFiles, htiContext,
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
        ClientToScreen(m_hwndFiles, &pt);
    pts.x = (short)pt.x;
    pts.y = (short)pt.y;

    // update the context item, and bring up the context menu
    UpdateContextItem(htiContext);
    hr = srpUIMgr->ShowContextMenu(OLEROLE_TOPLEVELCOMPONENT,
                                   guidEUGrp, IDM_CTX_FILESYSFILE, pts,
                                   static_cast<IOleCommandTarget*>(this));
    _ASSERTE_MSG(SUCCEEDED(hr), "Failed to bring up file context menu");

OnError:
    return 0;
}

LRESULT CFileSystemFilePane::OnExecCommand()
{
    TCHAR szCmdText[MAX_CMDTEXT_LEN+1];
    TCHAR* pszCmd = szCmdText;

    int nLen = GetWindowText(m_hwndCmdText, szCmdText, MAX_CMDTEXT_LEN+1);
    if (nLen)
    {
        // trim leading and trailing spaces
        while (*pszCmd == _T(' '))
            pszCmd++;

        nLen--;
        while (pszCmd[nLen] == _T(' '))
        {
            pszCmd[nLen] = _T('\0');
            nLen--;
        }

        if (_tcslen(pszCmd))
            g_FileSys.ExecCommand(pszCmd, m_pSelFolder);
    }
    return 0;
}


//*****************************************************************************
// CFileSystemFilePane Command Handlers
//*****************************************************************************

HRESULT CFileSystemFilePane::OnOpenFile(BOOL fOpenWith)
{
    _ASSERTE(m_pSelFile);

    USES_CONVERSION;

    CComPtr<IVsUIShellOpenDocument> srpOpenDoc;
    CComPtr<IVsUIHierarchy> srpHier;
    CComPtr<IVsWindowFrame> srpFrame;
    CComPtr<IServiceProvider> srpSP;
    VSITEMID itemid;
    CString strPath;
    HRESULT hr;

    hr = _VxModule.QueryService(SID_SVsUIShellOpenDocument, IID_IVsUIShellOpenDocument,
                              (void**)&srpOpenDoc);
    IfFailGo(hr);

    m_pSelFile->GetFilePath(strPath);

    hr = srpOpenDoc->OpenDocumentViaProject(T2COLE(strPath),
                                            (fOpenWith ? LOGVIEWID_UserChooseView : LOGVIEWID_Primary),
                                            &srpSP,
                                            &srpHier, &itemid,
                                            &srpFrame);
    if (fOpenWith)
    {
        _IfFailGo(hr);  // Canceling out of Open With dialog returns error
    }
    else
    {
        IfFailGo(hr);
    }

    if (srpFrame)
    {
        // srpFrame could be NULL if an external editor was launched
        srpFrame->Show();
    }

OnError:
    return hr;
}

HRESULT CFileSystemFilePane::OnPreviewFile()
{
    _ASSERTE(m_pSelFile);

    USES_CONVERSION;

    CComPtr<IVsUIShellOpenDocument> srpOpenDoc;
    CString strPath;
    HRESULT hr;

    hr = _VxModule.QueryService(SID_SVsUIShellOpenDocument, IID_IVsUIShellOpenDocument,
                              (void**)&srpOpenDoc);
    IfFailGo(hr);

    m_pSelFile->GetFilePath(strPath);

    hr = srpOpenDoc->OpenStandardPreviewer(0, T2COLE(strPath), PR_Default, NULL);
    IfFailGo(hr);

OnError:
    return hr;
}

HRESULT CFileSystemFilePane::OnRefresh()
{
    _ASSERTE(m_pSelFolder);
    _ASSERTE(m_pCachedFolder);

    CFileSystemFileItem* pFile;
    int nFiles;

    m_pCachedFolder->RefreshFolder();
    m_pSelFile = NULL;

    m_fIgnoreSelChanges = TRUE;

    SendMessage(m_hwndFiles, WM_SETREDRAW, FALSE, 0);
    TreeView_DeleteAllItems(m_hwndFiles);

    nFiles = m_pCachedFolder->GetFileCount();

    for (int i = 0; i < nFiles; i++)
    {
        pFile = m_pCachedFolder->GetFile(i);
        _ASSERTE(pFile);

        AddFileToTree(pFile);
    }

    OnSortFiles(m_nSortType);

    TreeView_SelectItem(m_hwndFiles, TreeView_GetChild(m_hwndFiles, TVI_ROOT));
    SendMessage(m_hwndFiles, WM_SETREDRAW, TRUE, 0);

    m_fIgnoreSelChanges = FALSE;
    OnTreeItemSelChanged();

    UpdateCommandUI(FALSE);

    return S_OK;
}

HRESULT CFileSystemFilePane::OnSortFiles(short nSortType)
{
    m_nSortType = nSortType;

    TVSORTCB tvsort;

    tvsort.hParent = TVI_ROOT;
    tvsort.lpfnCompare = CFileSystemFilePane::CompareFiles;
    tvsort.lParam = m_nSortType;

    TreeView_SortChildrenCB(m_hwndFiles, &tvsort, 0);
    return S_OK;
}

HRESULT CFileSystemFilePane::OnFilterChanged(VARIANT* pvaIn)
{
    g_FileSys.ExecSetCurrentFilter(pvaIn);

    if (m_pSelFolder && m_pCachedFolder)
        return OnRefresh();
    return S_OK;
}


//*****************************************************************************
// CFileSystemFilePane Implementation
//*****************************************************************************

void CFileSystemFilePane::SetEnabledState()
{
    EnableWindow(m_hwndCmdText, m_pSelFolder != NULL);
    EnableWindow(m_hwndCmdExec, m_pSelFolder != NULL);
}

void CFileSystemFilePane::SubclassCmdEdit()
{
    _ASSERTE(!s_lpfnEditProc);
    _ASSERTE(m_hwndCmdText);

    s_lpfnEditProc = (WNDPROC)SetWindowLongPtr(m_hwndCmdText, GWLP_WNDPROC,
                                            (LONG_PTR)CmdEditWndProc);
    _ASSERTE(s_lpfnEditProc);
}

void CFileSystemFilePane::UnsubclassCmdEdit()
{
    _ASSERTE(s_lpfnEditProc);
    SetWindowLongPtr(m_hwndCmdText, GWLP_WNDPROC, (LONG_PTR)s_lpfnEditProc);
    s_lpfnEditProc = NULL;
}

HTREEITEM CFileSystemFilePane::AddFileToTree(CFileSystemFileItem* pFile)
{
    _ASSERTE(pFile);
    if (!pFile)
        return NULL;

    if (g_FileSys.IsFilterEnabled() && (g_FileSys.FilterFile(pFile) == FALSE))
        return NULL;

    TV_INSERTSTRUCT tvis;
    int nIcon = g_ExtMgr.GetExtensionIconIndex(pFile);

    tvis.hParent = TVI_ROOT;
    tvis.hInsertAfter = TVI_LAST;
    tvis.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_PARAM | TVIF_TEXT |
                     TVIF_STATE;
    tvis.item.iImage = nIcon;
    tvis.item.iSelectedImage = nIcon;
    tvis.item.stateMask = TVIS_STATEIMAGEMASK;
    tvis.item.state = INDEXTOSTATEIMAGEMASK(pFile->IsReadOnly() ?
                                            ILI_ILSTATE_READONLY : ILI_ILSTATE_NONE);
    tvis.item.lParam = (LPARAM)pFile;
    tvis.item.pszText = (LPTSTR)pFile->GetFileName();

    HTREEITEM hti = TreeView_InsertItem(m_hwndFiles, &tvis);
    _ASSERTE_MSG(hti, "Failed to add shortcut to tree");

    return hti;
}


void CFileSystemFilePane::UpdateContextItem(HTREEITEM htiContext)
{
    CFileSystemFileItem* pSelItem = NULL;

    if (htiContext)
    {
        TV_ITEM tvi;

        tvi.mask = TVIF_PARAM | TVIF_HANDLE;
        tvi.hItem = htiContext;

        TreeView_GetItem(m_hwndFiles, &tvi);
        pSelItem = (CFileSystemFileItem*)tvi.lParam;
    }
    m_pSelFile = pSelItem;

    m_srpSelection->UpdateFileSelection((DWORD_PTR)pSelItem);
}

int CALLBACK CFileSystemFilePane::CompareFiles(LPARAM lParam1, LPARAM lParam2,
                                               LPARAM lParamSort)
{
    _ASSERTE(lParam1);
    _ASSERTE(lParam2);

    CFileSystemFileItem* pFile1 = (CFileSystemFileItem*)lParam1;
    CFileSystemFileItem* pFile2 = (CFileSystemFileItem*)lParam2;

    if (lParamSort == sortReadOnly)
    {
        BOOL fReadOnlyFile1 = pFile1->IsReadOnly();
        BOOL fReadOnlyFile2 = pFile2->IsReadOnly();

        if ((fReadOnlyFile1 && fReadOnlyFile2) ||
            (!fReadOnlyFile1 && !fReadOnlyFile2))
        {
            // resort to name comparison if both have same readonly status
            return pFile1->CompareFile(pFile2, FALSE);
        }
        else if (fReadOnlyFile1 && !fReadOnlyFile2)
            return -1;      // read only files come first, so they are 'smaller'
        else
            return 1;
    }
    else
        return pFile1->CompareFile(pFile2, (lParamSort == sortExtension ? TRUE : FALSE));
}
