
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSCmdDlg.cpp
//
// Implementation of CFileSystemCommandDlg
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "FSCmdDlg.h"

//*****************************************************************************
// CFileSystemCommandDlg Constructor/Destructor
//*****************************************************************************

CFileSystemCommandDlg::CFileSystemCommandDlg()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemCommandDlg::CFileSystemCommandDlg \n") );

    m_fChanged = FALSE;
    m_hIconSortUp = NULL;
    m_hIconSortDown = NULL;
    m_hIconDelete = NULL;
    m_hIconPrompt = NULL;

    m_pCurCommand = NULL;
}

CFileSystemCommandDlg::~CFileSystemCommandDlg()
{
    if (m_hIconSortUp)
    {
        DeleteObject(m_hIconSortUp);
    }
    if (m_hIconSortDown)
    {
        DeleteObject(m_hIconSortDown);
    }
    if (m_hIconDelete)
    {
        DeleteObject(m_hIconDelete);
    }
    if (m_hIconPrompt)
    {
        DeleteObject(m_hIconPrompt);
    }
}


//*****************************************************************************
// CFileSystemCommandDlg Message Handlers
//*****************************************************************************

LRESULT CFileSystemCommandDlg::OnInitDialog(UINT uMsg, WPARAM wParam,
                                            LPARAM lParam, BOOL& bHandled)
{
    m_hIconSortUp = LoadIcon(_AtlBaseModule.GetResourceInstance(),
                             MAKEINTRESOURCE(IDI_CMD_SORTUP));
    m_hIconSortDown = LoadIcon(_AtlBaseModule.GetResourceInstance(),
                               MAKEINTRESOURCE(IDI_CMD_SORTDOWN));
    m_hIconDelete = LoadIcon(_AtlBaseModule.GetResourceInstance(),
                             MAKEINTRESOURCE(IDI_CMD_DELETE));
    m_hIconPrompt = LoadIcon(_AtlBaseModule.GetResourceInstance(),
                             MAKEINTRESOURCE(IDI_CMD_PROMPT));
    SendDlgItemMessage(IDC_CMD_CMDUP, BM_SETIMAGE, IMAGE_ICON, (LPARAM)m_hIconSortUp);
    SendDlgItemMessage(IDC_CMD_CMDDOWN, BM_SETIMAGE, IMAGE_ICON, (LPARAM)m_hIconSortDown);
    SendDlgItemMessage(IDC_CMD_CMDDEL, BM_SETIMAGE, IMAGE_ICON, (LPARAM)m_hIconDelete);
    SendDlgItemMessage(IDC_CMD_ARGMACRO, BM_SETIMAGE, IMAGE_ICON, (LPARAM)m_hIconPrompt);

    SendDlgItemMessage(IDC_CMD_NAME, EM_LIMITTEXT, MAX_CMD_NAME - 1, 0);
    SendDlgItemMessage(IDC_CMD_COMMAND, EM_LIMITTEXT, _MAX_PATH - 1, 0);
    SendDlgItemMessage(IDC_CMD_ARGUMENTS, EM_LIMITTEXT, _MAX_PATH - 1, 0);

    if (LoadCommands())
    {
        SendDlgItemMessage(IDC_CMD_COMMANDLIST, LB_SETCURSEL, 0, 0);
        UpdateCurrentCommand();
    }
    SetEnabledState();

    return 1;
}
                                            
LRESULT CFileSystemCommandDlg::OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl,
                                    BOOL& bHandled)
{
    EndDialog(wID);
    return 0;
}

LRESULT CFileSystemCommandDlg::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl,
                                        BOOL& bHandled)
{
    EndDialog(wID);
    return 0;
}

LRESULT CFileSystemCommandDlg::OnCmdListSelChange(WORD wNotifyCode, WORD wID,
                                                  HWND hWndCtl, BOOL& bHandled)
{
    UpdateCurrentCommand();
    SetEnabledState();
    return 0;
}

LRESULT CFileSystemCommandDlg::OnCmdListSortUp(WORD wNotifyCode, WORD wID,
                                               HWND hWndCtl, BOOL& bHandled)
{
    HWND hwndCmdList = GetDlgItem(IDC_CMD_COMMANDLIST);
    int nIndex = (int)::SendMessage(hwndCmdList, LB_GETCURSEL, 0, 0);
    int nCommands = (int)::SendMessage(hwndCmdList, LB_GETCOUNT, 0, 0);

    _ASSERTE((nIndex > 0) && (nIndex < nCommands));

    CFileSystemCommand* pCommand =
        (CFileSystemCommand*)::SendMessage(hwndCmdList, LB_GETITEMDATA, nIndex, 0);
    _ASSERTE(pCommand);

    g_FileSys.SwapCommands(nIndex, nIndex - 1);

    // remove the font and add it back in at the previous index
    ::SendMessage(hwndCmdList, LB_DELETESTRING, nIndex, 0);
    ::SendMessage(hwndCmdList, LB_INSERTSTRING, nIndex - 1,
                  (LPARAM)pCommand->GetCommandName());
    ::SendMessage(hwndCmdList, LB_SETITEMDATA, nIndex - 1,
                  (LPARAM)pCommand);
    ::SendMessage(hwndCmdList, LB_SETCURSEL, nIndex - 1, 0);

    UpdateCurrentCommand();

    // reset the enabled state
    SetEnabledState();

    m_fChanged = TRUE;
    return 0;
}

LRESULT CFileSystemCommandDlg::OnCmdListSortDown(WORD wNotifyCode, WORD wID,
                                                 HWND hWndCtl, BOOL& bHandled)
{
    HWND hwndCmdList = GetDlgItem(IDC_CMD_COMMANDLIST);
    int nIndex = (int)::SendMessage(hwndCmdList, LB_GETCURSEL, 0, 0);
    int nCommands = (int)::SendMessage(hwndCmdList, LB_GETCOUNT, 0, 0);

    _ASSERTE((nIndex >= 0) && (nIndex < nCommands - 1));

    CFileSystemCommand* pCommand =
        (CFileSystemCommand*)::SendMessage(hwndCmdList, LB_GETITEMDATA, nIndex, 0);
    _ASSERTE(pCommand);

    g_FileSys.SwapCommands(nIndex, nIndex + 1);

    // remove the font and add it back in at the next index
    ::SendMessage(hwndCmdList, LB_DELETESTRING, nIndex, 0);
    ::SendMessage(hwndCmdList, LB_INSERTSTRING, nIndex + 1,
                  (LPARAM)pCommand->GetCommandName());
    ::SendMessage(hwndCmdList, LB_SETITEMDATA, nIndex + 1,
                  (LPARAM)pCommand);
    ::SendMessage(hwndCmdList, LB_SETCURSEL, nIndex + 1, 0);

    UpdateCurrentCommand();

    // reset the enabled state
    SetEnabledState();

    m_fChanged = TRUE;
    return 0;
}

LRESULT CFileSystemCommandDlg::OnCmdListDelete(WORD wNotifyCode, WORD wID,
                                               HWND hWndCtl, BOOL& bHandled)
{
    HWND hwndCmdList = GetDlgItem(IDC_CMD_COMMANDLIST);
    INT_PTR nIndex = ::SendMessage(hwndCmdList, LB_GETCURSEL, 0, 0);
    INT_PTR nCommands = ::SendMessage(hwndCmdList, LB_GETCOUNT, 0, 0);

    _ASSERTE((nIndex >= 0) && (nIndex < nCommands));

    CFileSystemCommand* pCommand =
        (CFileSystemCommand*)::SendMessage(hwndCmdList, LB_GETITEMDATA, nIndex, 0);
    _ASSERTE(pCommand);

    ::SendMessage(hwndCmdList, LB_DELETESTRING, nIndex, 0);
    g_FileSys.RemoveCommand(pCommand);

    // set the selection to another command in the list if there is one
    nCommands--;
    if (nCommands > 0) {
        if (nIndex > 0)
            nIndex--;
        ::SendMessage(hwndCmdList, LB_SETCURSEL, nIndex, 0);
    }
    else {
        ::SetFocus(hwndCmdList);
    }
    UpdateCurrentCommand();
    SetEnabledState();

    m_fChanged = TRUE;
    return 0;
}

LRESULT CFileSystemCommandDlg::OnCmdBrowse(WORD wNotifyCode, WORD wID,
                                           HWND hWndCtl, BOOL& bHandled)
{
    TCHAR szCommand[_MAX_PATH];
    CString strFilter;
    CString strCaption;
    VSOPENFILENAMEW vsofn;
    BOOL fResult = FALSE;

    strFilter.LoadString(IDS_CMD_BROWSEFILTER);
    strCaption.LoadString(IDS_CMD_BROWSECAPTION);

    int nFilterLen = strFilter.GetLength();
    for (int i = 0; i < nFilterLen; i++)
    {
        if (strFilter.GetAt(i) == _T('|'))
            strFilter.SetAt(i, _T('\0'));
    }

    if (m_pCurCommand && (m_pCurCommand->GetCommandCommand() != NULL) && (lstrlen(m_pCurCommand->GetCommandCommand()) < _MAX_PATH))
        _tcscpy(szCommand, m_pCurCommand->GetCommandCommand());
    else
        szCommand[0] = _T('\0');

    ZeroMemory(&vsofn, sizeof(VSOPENFILENAMEW));
    vsofn.lStructSize = sizeof(VSOPENFILENAMEW);
    vsofn.hwndOwner = m_hWnd;
    vsofn.pwzDlgTitle = strCaption;
    vsofn.pwzFileName = szCommand;
    vsofn.nMaxFileName = _MAX_PATH;
    vsofn.pwzInitialDir = NULL;
    vsofn.pwzFilter = strFilter;
    vsofn.nFilterIndex = 1;
    vsofn.nFileOffset = 0;
    vsofn.nFileExtension = 0;
    vsofn.dwHelpTopic = 0;
    vsofn.dwFlags = 0;

    CComPtr<IVsUIShell> srpUIShell;
    if ((SUCCEEDED(_VxModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpUIShell))) && (srpUIShell))
      fResult = SUCCEEDED(srpUIShell->GetOpenFileNameViaDlg(&vsofn));

    if (fResult)
    {
        SetDlgItemText(IDC_CMD_COMMAND, szCommand);
    }

    return 0;
}

LRESULT CFileSystemCommandDlg::OnCmdAdd(WORD wNotifyCode, WORD wID, HWND hWndCtl,
                                        BOOL& bHandled)
{
    AddCommand(-1);
    return 0;
}

LRESULT CFileSystemCommandDlg::OnCmdUpdate(WORD wNotifyCode, WORD wID, HWND hWndCtl,
                                           BOOL& bHandled)
{
    int nIndex = (int)SendDlgItemMessage(IDC_CMD_COMMANDLIST, LB_GETCURSEL, 0, 0);
    _ASSERTE(nIndex != LB_ERR);

    AddCommand(nIndex);
    return 0;
}

LRESULT CFileSystemCommandDlg::OnCmdArgMacro(WORD wNotifyCode, WORD wID, HWND hWndCtl,
                                             BOOL& bHandled)
{
    CComPtr<IOleComponentUIManager> srpUIMgr;
    CMacroMenuCmdTarget cmdTarget(this);
    RECT rc;
    POINTS pts;
    HRESULT hr;

    hr = _VxModule.QueryService(SID_OleComponentUIManager, IID_IOleComponentUIManager,
                              (void**)&srpUIMgr);
    IfFailGo(hr);

    if (!hWndCtl)
        goto OnError;

    ::GetWindowRect(hWndCtl, &rc);

    pts.x = (short)(rc.right - 1);
    pts.y = (short)(rc.top - 1);
    hr = srpUIMgr->ShowContextMenu(OLEROLE_TOPLEVELCOMPONENT,
                                   guidEUGrp, IDM_CTX_CMDMACRO, pts,
                                   static_cast<IOleCommandTarget*>(&cmdTarget));
    IfFailGo(hr);

OnError:
    return 0;
}


//*****************************************************************************
// CFileSystemCommandDlg Implementation
//*****************************************************************************

int CFileSystemCommandDlg::LoadCommands()
{
    HWND hwndCommands = GetDlgItem(IDC_CMD_COMMANDLIST);
    int nCommands = g_FileSys.GetCommandCount();
    CFileSystemCommand* pCommand;

    for (int i = 0; i < nCommands; i++)
    {
        pCommand = g_FileSys.GetCommand(i);
        _ASSERTE(pCommand);

        ::SendMessage(hwndCommands, LB_ADDSTRING, 0, (LPARAM)pCommand->GetCommandName());
        ::SendMessage(hwndCommands, LB_SETITEMDATA, i, (LPARAM)pCommand);
    }
    return nCommands;
}

void CFileSystemCommandDlg::LoadCommandDetails()
{
    if (m_pCurCommand)
    {
        SetDlgItemText(IDC_CMD_NAME, m_pCurCommand->GetCommandName());
        SetDlgItemText(IDC_CMD_COMMAND, m_pCurCommand->GetCommandCommand());
        SetDlgItemText(IDC_CMD_ARGUMENTS, m_pCurCommand->GetCommandArgs());
        if (m_pCurCommand->GetCommandFlags() & CMF_UseOutput)
        {
            SendDlgItemMessage(IDC_CMD_USEOUTPUT, BM_SETCHECK,
                               BST_CHECKED, 0);
            SendDlgItemMessage(IDC_CMD_CLEAROUTPUT, BM_SETCHECK,
                               (m_pCurCommand->GetCommandFlags() & CMF_ClearOutput) ? BST_CHECKED : BST_UNCHECKED,
                               0);
            ::EnableWindow(GetDlgItem(IDC_CMD_CLEAROUTPUT), TRUE);
        }
        else
        {
            SendDlgItemMessage(IDC_CMD_USEOUTPUT, BM_SETCHECK,
                               BST_CHECKED, 0);
            SendDlgItemMessage(IDC_CMD_CLEAROUTPUT, BM_SETCHECK, BST_UNCHECKED, 0);
            ::EnableWindow(GetDlgItem(IDC_CMD_CLEAROUTPUT), FALSE);
        }
    }
    else
    {
        SetDlgItemText(IDC_CMD_NAME, _T(""));
        SetDlgItemText(IDC_CMD_COMMAND, _T(""));
        SetDlgItemText(IDC_CMD_ARGUMENTS, _T(""));
        SendDlgItemMessage(IDC_CMD_USEOUTPUT, BM_SETCHECK, BST_UNCHECKED, 0);
        SendDlgItemMessage(IDC_CMD_CLEAROUTPUT, BM_SETCHECK, BST_UNCHECKED, 0);
        ::EnableWindow(GetDlgItem(IDC_CMD_CLEAROUTPUT), FALSE);
    }
}

void CFileSystemCommandDlg::UpdateCurrentCommand()
{
    HWND hwndCommands = GetDlgItem(IDC_CMD_COMMANDLIST);
    INT_PTR nIndex = ::SendMessage(hwndCommands, LB_GETCURSEL, 0, 0);

    m_pCurCommand = NULL;
    if (nIndex != LB_ERR)
    {
        m_pCurCommand = (CFileSystemCommand*)::SendMessage(hwndCommands,
                                                           LB_GETITEMDATA,
                                                           nIndex, 0);
    }
    LoadCommandDetails();
}

void CFileSystemCommandDlg::SetEnabledState()
{
    HWND hwndCommands = GetDlgItem(IDC_CMD_COMMANDLIST);
    INT_PTR nIndex = ::SendMessage(hwndCommands, LB_GETCURSEL, 0, 0);
    INT_PTR nCommands = ::SendMessage(hwndCommands, LB_GETCOUNT, 0, 0);

    ::EnableWindow(GetDlgItem(IDC_CMD_CMDUP), nCommands && (nIndex > 0));
    ::EnableWindow(GetDlgItem(IDC_CMD_CMDDOWN), nCommands && (nIndex < nCommands - 1));
    ::EnableWindow(GetDlgItem(IDC_CMD_CMDDEL), nCommands && (nIndex != LB_ERR));

    ::EnableWindow(GetDlgItem(IDC_CMD_UPDATE), m_pCurCommand != NULL);
}

void CFileSystemCommandDlg::AddCommand(int nIndex)
{
    CFileSystemCommand* pCommand = NULL;

    if (nIndex == -1)
        pCommand = new CFileSystemCommand();
    else
    {
        pCommand = g_FileSys.GetCommand(nIndex);
        _ASSERTE(pCommand);
    }
    if (pCommand == NULL)
        return;

    TCHAR szCommandName[MAX_CMD_NAME];
    TCHAR szCommand[_MAX_PATH];
    TCHAR szArgs[_MAX_PATH];
    DWORD dwFlags = 0;

    GetDlgItemText(IDC_CMD_NAME, szCommandName, MAX_CMD_NAME - 1);
    GetDlgItemText(IDC_CMD_COMMAND, szCommand, _MAX_PATH - 1);
    GetDlgItemText(IDC_CMD_ARGUMENTS, szArgs, _MAX_PATH - 1);

    if (SendDlgItemMessage(IDC_CMD_USEOUTPUT, BM_GETCHECK, 0, 0) == BST_CHECKED)
    {
        dwFlags = CMF_UseOutput;
        if (SendDlgItemMessage(IDC_CMD_CLEAROUTPUT, BM_GETCHECK, 0, 0) == BST_CHECKED)
            dwFlags |= CMF_ClearOutput;
    }

    if (nIndex == -1)
    {
        // Initialize the new command
        HRESULT hr = pCommand->InitCommand(szCommandName, szCommand, szArgs, dwFlags);
        if (SUCCEEDED(hr))
        {
            // and add it to the file system and to the UI
            if (g_FileSys.AddCommand(pCommand, TRUE))
            {
                HWND hwndCommands = GetDlgItem(IDC_CMD_COMMANDLIST);
                INT_PTR nIndex;

                nIndex = ::SendMessage(hwndCommands, LB_ADDSTRING, 0, (LPARAM)szCommandName);
                ::SendMessage(hwndCommands, LB_SETITEMDATA, nIndex, (LPARAM)pCommand);
                ::SendMessage(hwndCommands, LB_SETCURSEL, nIndex, 0);
            }
        }
        else
        {
            delete pCommand;
            pCommand = NULL;
        }
    }
    else
    {
        // Just update the existing command and set the file system to dirty
        pCommand->SetCommand(szCommandName, szCommand, szArgs, dwFlags);
        g_FileSys.SetFileSystemOptionsDirty();
    }

    m_fChanged = TRUE;
}



//*****************************************************************************
// CMacroMenuCmdTarget Implementation
//*****************************************************************************

CFileSystemCommandDlg::CMacroMenuCmdTarget::CMacroMenuCmdTarget(CFileSystemCommandDlg* pDlg)
{
    _ASSERTE(pDlg);
    m_pDlg = pDlg;
}

//*****************************************************************************
// CMacroMenuCmdTarget IUnknown Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemCommandDlg::CMacroMenuCmdTarget::QueryInterface(
                /*[in] */ REFIID riid,
                /*[out]*/ void** ppvObject)
{
    ExpectedPtrRet(ppvObject);

    InitParam(ppvObject);
    HRESULT hr = E_NOINTERFACE;

    if ((riid == IID_IOleCommandTarget) ||
        (riid == IID_IUnknown))
    {
        *ppvObject = static_cast<IOleCommandTarget*>(this);
        hr = S_OK;
    }
    return hr;
}

STDMETHODIMP_(ULONG) CFileSystemCommandDlg::CMacroMenuCmdTarget::AddRef(void)
{
    return 1;
}

STDMETHODIMP_(ULONG) CFileSystemCommandDlg::CMacroMenuCmdTarget::Release(void)
{
    return 1;
}

//*****************************************************************************
// CMacroMenuCmdTarget IOleCommandTarget Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemCommandDlg::CMacroMenuCmdTarget::QueryStatus(
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
            case cmdidMacroSelFolder:
            case cmdidMacroFileDir:
            case cmdidMacroFileName:
            case cmdidMacroFilePath:
            case cmdidMacroFileExt:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                hr = S_OK;
                break;
            default:
                hr = OLECMDERR_E_NOTSUPPORTED;
                break;
        }
    }

    prgCmds[0].cmdf = cmdf;
    return hr;
}

STDMETHODIMP CFileSystemCommandDlg::CMacroMenuCmdTarget::Exec(
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
        LPCTSTR lpszMacro = NULL;

        switch (nCmdID)
        {
            case cmdidMacroSelFolder:
                lpszMacro = s_lpszSelFolder;
                goto AddMacroToArgs;
            case cmdidMacroFileDir:
                lpszMacro = s_lpszFileDirectory;
                goto AddMacroToArgs;
            case cmdidMacroFileName:
                lpszMacro = s_lpszFileName;
                goto AddMacroToArgs;
            case cmdidMacroFilePath:
                lpszMacro = s_lpszFilePath;
                goto AddMacroToArgs;
            case cmdidMacroFileExt:
                lpszMacro = s_lpszFileExtension;
                goto AddMacroToArgs;
AddMacroToArgs:
                _ASSERTE(lpszMacro && (lstrlen(lpszMacro) < MAX_PATH) );
                if (lpszMacro && (lstrlen(lpszMacro) < MAX_PATH))
                {
                    TCHAR szMacroText[_MAX_PATH + 1];
                    _sntprintf(szMacroText, NUMBER_OF(szMacroText), _T(" %s"), lpszMacro);

                    HWND hwndArgs = m_pDlg->GetDlgItem(IDC_CMD_ARGUMENTS);
                    INT_PTR nTemp = ::SendMessage(hwndArgs, EM_LINELENGTH, 0, 0);
                    

                    ::SendMessage(hwndArgs, EM_SETSEL, nTemp, nTemp);
                    ::SendMessage(hwndArgs, EM_REPLACESEL, TRUE, (LPARAM)szMacroText);
                }
                fHandled = TRUE;
                hr = S_OK;
                break;
            default:
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
