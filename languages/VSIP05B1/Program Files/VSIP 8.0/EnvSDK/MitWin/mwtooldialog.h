
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// MWToolDialog.h : Declaration of the CMWToolDialog

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CMWToolDialog
class CMWToolDialog : 
    public CAxDialogImpl<CMWToolDialog>
{
public:
    CMWToolDialog()
    {
        ENVSDK_TRACE(atlTraceWindowing, TLC, _T(" CMWToolDialog::CMWToolDialog : this = 0x%x\n"), this);
    }

    ~CMWToolDialog()
    {
        ENVSDK_TRACE(atlTraceWindowing, TLD, _T(" CMWToolDialog::~CMWToolDialog : this = 0x%x\n"), this);
    }

    enum { IDD = IDD_MWTOOLDIALOG };

BEGIN_MSG_MAP(CMWToolDialog)
    MESSAGE_HANDLER(WM_INITDIALOG,  OnInitDialog)
    MESSAGE_HANDLER(WM_SIZE,        OnSize)
    MESSAGE_HANDLER(WM_CLOSE,       OnClose)
    MESSAGE_HANDLER(WM_KILLFOCUS,   OnKillFocus)
    MESSAGE_HANDLER(WM_SETFOCUS,    OnSetFocus)
    COMMAND_HANDLER(IDC_BUTTON,     BN_CLICKED, OnClickedButton)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        ENVSDK_TRACE(atlTraceWindowing, TLF, _T(" CMWToolDialog::OnInitDialog : this = 0x%x\n"), this);

        m_hWndControl = GetDlgItem(IDC_BUTTON);
        return 1;  // Let the system set the focus
    }

    LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        ENVSDK_TRACE(atlTraceWindowing, TLF, _T(" CMWToolDialog::OnSize : this = 0x%x\n"), this);

        ::MoveWindow(m_hWndControl,0,0,LOWORD(lParam),HIWORD(lParam), TRUE);             
        return 0;
    }

    LRESULT OnClickedButton(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
    {
        ENVSDK_TRACE(atlTraceWindowing, TLF, _T(" CMWToolDialog::OnClickedButton : this = 0x%x\n"), this);

        IVsUIShell* pIVsUIShell=_AtlModule.GetIVsUIShell();
        if (pIVsUIShell != NULL)
        {
            pIVsUIShell->EnableModeless(FALSE);
            ///\\ MessageBox(_T("Hello there"),_T("MWToolWindow"));
            ::MessageBox(NULL, _T("Hello there"),_T("MWToolWindow"), MB_OK | MB_TASKMODAL);        
            pIVsUIShell->EnableModeless(TRUE);
        }
        return 0;
    }

    LRESULT OnClose(UINT, WPARAM, LPARAM, BOOL& )
    {
        ENVSDK_TRACE(atlTraceWindowing, TLF, _T(" CMWToolDialog::OnClose : this = 0x%x\n"), this);
        DestroyWindow();
        return 0;
    }

    HRESULT Initialize(/* [in] */ IVsToolWindowToolbarHost *pIVsToolWindowToolbarHost)
    {
        ENVSDK_TRACE(atlTraceWindowing, TLF, _T(" CMWToolDialog::Initialize : this = 0x%x\n"), this);

        ExpectedPtrRet(pIVsToolWindowToolbarHost);
        m_srpIVsToolWindowToolbarHost = pIVsToolWindowToolbarHost;
        return S_OK;
    }

    LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        ENVSDK_TRACE(atlTraceWindowing, TLF, _T(" CMWToolDialog::OnKillFocus : this = 0x%x\n"), this);

        m_srpIVsToolWindowToolbarHost->ShowHideToolbar(
            /* [in] const GUID * pguid  */ &guidMitWinMenuGrp,
            /* [in] DWORD dwId          */ IDM_TLB_MWTOOL,
            /* [in] BOOL fShow          */ FALSE);
        return 0;
    }

    LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        ENVSDK_TRACE(atlTraceWindowing, TLF, _T(" CMWToolDialog::OnSetFocus : this = 0x%x\n"), this);

        m_srpIVsToolWindowToolbarHost->ShowHideToolbar(
            /* [in] const GUID * pguid  */ &guidMitWinMenuGrp,
            /* [in] DWORD dwId          */ IDM_TLB_MWTOOL,
            /* [in] BOOL fShow          */ TRUE);
        return 0;
    }

private:
    HWND m_hWndControl;
    CComPtr<IVsToolWindowToolbarHost> m_srpIVsToolWindowToolbarHost;
};
