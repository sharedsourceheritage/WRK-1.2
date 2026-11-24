
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSCmdDlg.h
//
// Declaration of CFileSystemCommandDlg
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CFileSystemCommandDlg
//*****************************************************************************

class CFileSystemCommandDlg :
    public CVsDialogImpl<CFileSystemCommandDlg>
{
// Constructor/Destructor
public:
    CFileSystemCommandDlg();
    ~CFileSystemCommandDlg();

    enum { IDD = IDD_COMMANDS };

// Message Map
BEGIN_MSG_MAP(CFileSystemCommandDlg)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    COMMAND_ID_HANDLER(IDOK, OnOK)
    COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
    COMMAND_HANDLER(IDC_CMD_COMMANDLIST, LBN_SELCHANGE, OnCmdListSelChange)
    COMMAND_HANDLER(IDC_CMD_CMDUP, BN_CLICKED, OnCmdListSortUp)
    COMMAND_HANDLER(IDC_CMD_CMDDOWN, BN_CLICKED, OnCmdListSortDown)
    COMMAND_HANDLER(IDC_CMD_CMDDEL, BN_CLICKED, OnCmdListDelete)
    COMMAND_HANDLER(IDC_CMD_CMDBROWSE, BN_CLICKED, OnCmdBrowse)
    COMMAND_HANDLER(IDC_CMD_ADD, BN_CLICKED, OnCmdAdd)
    COMMAND_HANDLER(IDC_CMD_UPDATE, BN_CLICKED, OnCmdUpdate)
    COMMAND_HANDLER(IDC_CMD_ARGMACRO, BN_CLICKED, OnCmdArgMacro)
END_MSG_MAP()

// Message Handlers
public:
    // Prototypes:
    // LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    // LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    // LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCmdListSelChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCmdListSortUp(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCmdListSortDown(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCmdListDelete(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCmdBrowse(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCmdAdd(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCmdUpdate(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnCmdArgMacro(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

// Implementation
protected:
    int LoadCommands();
    void LoadCommandDetails();
    void UpdateCurrentCommand();
    void SetEnabledState();
    void AddCommand(int nIndex);

    class CMacroMenuCmdTarget : public IOleCommandTarget
    {
    // Constructor
    public:
        CMacroMenuCmdTarget(CFileSystemCommandDlg* pDlg);

    // IUnknown, IOleCommandTarget
    public:
        STDMETHOD(QueryInterface)(
                    /*[in] */ REFIID riid,
                    /*[out]*/ void** ppvObject);
        STDMETHOD_(ULONG, AddRef)(void);
        STDMETHOD_(ULONG, Release)(void);
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

    // Attributes
    protected:
        CFileSystemCommandDlg* m_pDlg;
    };
    friend class CMacroMenuCmdTarget;

// Attributes
public:
    BOOL m_fChanged;
protected:
    HICON m_hIconSortUp;
    HICON m_hIconSortDown;
    HICON m_hIconDelete;
    HICON m_hIconPrompt;

    CFileSystemCommand* m_pCurCommand;
};
