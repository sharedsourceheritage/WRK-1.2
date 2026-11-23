// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "occimpl.h"



#define new DEBUG_NEW

/////////////////////////////////////////////////////////////////////////////
// AfxDlgProc - does nothing since all messages are handled via AfxWndProc

INT_PTR CALLBACK AfxDlgProc(HWND hWnd, UINT message, WPARAM, LPARAM)
{
	if (message == WM_INITDIALOG)
	{
		// special case for WM_INITDIALOG
		CDialog* pDlg = DYNAMIC_DOWNCAST(CDialog, CWnd::FromHandlePermanent(hWnd));
		if (pDlg != NULL)
			return pDlg->OnInitDialog();
		else
			return 1;
	}
	return 0;
}

#ifdef _WIN32_WCE
void AFXAPI _AfxSendDlgCreateMsg(HWND hWnd)
{
	CREATESTRUCT cs; // We "recreate" this by doing detective work.
	TCHAR szDummy[2];

	int nLen = GetWindowText(hWnd, szDummy, 1); // query len
	cs.lpszName = new TCHAR[nLen+1];
	if (cs.lpszName == NULL)
		return;
	GetWindowText(hWnd, (TCHAR*)cs.lpszName, nLen); // un-const cast

	TCHAR lpszClass[64];
	cs.lpszClass = lpszClass;
	GetClassName(hWnd, (TCHAR*)cs.lpszClass, sizeof(lpszClass)/sizeof(lpszClass[0]));

	cs.style = GetWindowLong(hWnd, GWL_STYLE);
	cs.dwExStyle = GetWindowLong(hWnd, GWL_EXSTYLE);

	cs.hwndParent = GetParent(hWnd);
	cs.hInstance = AfxGetInstanceHandle();

	RECT rectDlg;
	GetWindowRect(hWnd, &rectDlg);
	if (cs.hwndParent != NULL) // child window?
	{
		RECT rectParent;
		GetWindowRect(cs. hwndParent, &rectParent);
		OffsetRect(&rectDlg, -rectParent.left, -rectParent.right);
	}
	cs.x = rectDlg.left;
	cs.y = rectDlg.top;
	cs.cx = rectDlg.right-rectDlg.left;
	cs.cy = rectDlg.bottom-rectDlg.top;
	
	cs.hMenu = NULL;
	cs.lpCreateParams = 0; // We lost the real lParam when WM_CREATE got consumed by Windows CE

	SendMessage(hWnd, WM_CREATE, 0, (LPARAM)&cs);

	delete[] (TCHAR*)cs.lpszName;
}

BOOL CALLBACK AfxDlgProcEx(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	// This gets called only once--on the first message sent to the dialog window.

	// We don't own the dlgproc for property sheet, so we have to use the first message
	// for the first property page as our CBT Hook opportunity.  We fake the
	// missed WM_INITDIALOG hook.  MFC *will* handle this in dlgprop.cpp (a subset of
	// the original OnInitDialog implemention) and won't delegate back to the real
	// dlgproc for the property sheet (if it did, it'd be processing WM_INITDIALOG for
	// the second time.)
	_AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
	CWnd *pWnd = pThreadState->m_pWndInit;
	if (pThreadState->m_pWndInitPropertySheet != NULL)
	{
		HWND hWndPropertySheet = ::GetParent(hWnd);
		ASSERT(hWndPropertySheet != NULL);
		ASSERT(pThreadState->m_pWndInit != NULL);

		CWnd *pWndInitFirstPropPage = pThreadState->m_pWndInit;
		pThreadState->m_pWndInit    = pThreadState->m_pWndInitPropertySheet;
		_AfxCbtFilterHook(0, (WPARAM)hWndPropertySheet, NULL);
		pThreadState->m_pWndInit    = pWndInitFirstPropPage;

		((CPropertySheet*)pThreadState->m_pWndInitPropertySheet)->OnInitDialog();
		pThreadState->m_pWndInitPropertySheet = NULL;
	}

	// Make sure the standard dialog box loop is the OS-owned one
	::SetWindowLong(hWnd, GWL_WNDPROC, (LONG)::DefDlgProc);

	// Let MFC subclass the dialog procedure.
	if (!pWnd->IsKindOf(RUNTIME_CLASS(CCommonDialog)))
	{
		// Common dialogs have OS-owned dialog procedures.  That's why 
		// MFC hooks with _AfxCommDlgProc. We don't want this relationship broken.
		::SetWindowLong(hWnd, DWL_DLGPROC, (LONG)AfxDlgProc); 
	}
	
	// Do normal WNDPROC subclassing now.  Note: after this call, m_pWndInit will
	// be NULL.  This is important in avoiding reentrancy via _AfxCommDlgProc.
	_AfxCbtFilterHook(0, (WPARAM)hWnd,NULL);

	// Delegate this message to the new subclassed WndProc
	WNDPROC afxWndProc = AfxGetAfxWndProc();

	// WM_CREATE on dialog boxes don't make it to the dialog procedure.
	// MFC depends this on at least for one reason: the CFormView (which is a dialog) wants
	// to have its OnCreate() called.  Since we're at the actual first message, now 
	// is the best time to fake the WM_CREATE.  
	if( (pWnd != NULL) && (pWnd->IsKindOf(RUNTIME_CLASS( CFormView ) ) ) )
		_AfxSendDlgCreateMsg(hWnd);

	// Repump the message through the entire chain.
	return afxWndProc(hWnd,nMsg,wParam,lParam);
};
#endif // _WIN32_WCE

/////////////////////////////////////////////////////////////////////////////
// CDialog - Modeless and Modal

BEGIN_MESSAGE_MAP(CDialog, CWnd)
	//{{AFX_MSG_MAP(CDialog)
	ON_COMMAND(IDOK, &CDialog::OnOK)
	ON_COMMAND(IDCANCEL, &CDialog::OnCancel)
#ifndef _WIN32_WCE_NO_HELP_SUPPORT
	ON_MESSAGE(WM_COMMANDHELP, &CDialog::OnCommandHelp)
	ON_MESSAGE(WM_HELPHITTEST, &CDialog::OnHelpHitTest)
#endif // !_WIN32_WCE_NO_HELP_SUPPORT
	ON_MESSAGE(WM_INITDIALOG, &CDialog::HandleInitDialog)
	ON_MESSAGE(WM_SETFONT, &CDialog::HandleSetFont)
#ifdef _WIN32_WCE
	ON_WM_SETTINGCHANGE()
	ON_WM_ACTIVATE()
#endif // _WIN32_WCE
#ifdef _DEVICE_RESOLUTION_AWARE
	ON_WM_SIZE()
#endif // _DEVICE_RESOLUTION_AWARE
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDialog::PreTranslateMessage(MSG* pMsg)
{
	// for modeless processing (or modal)
	ASSERT(m_hWnd != NULL);

	// allow tooltip messages to be filtered
	if (CWnd::PreTranslateMessage(pMsg))
		return TRUE;

#ifndef _WIN32_WCE_NO_HELP_SUPPORT
	// don't translate dialog messages when in Shift+F1 help mode
	CFrameWnd* pFrameWnd = GetTopLevelFrame();
	if (pFrameWnd != NULL && pFrameWnd->m_bHelpMode)
		return FALSE;
#endif // !_WIN32_WCE_NO_HELP_SUPPORT

	// fix around for VK_ESCAPE in a multiline Edit that is on a Dialog
	// that doesn't have a cancel or the cancel is disabled.
	if (pMsg->message == WM_KEYDOWN &&
		(pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_CANCEL) &&
		(::GetWindowLong(pMsg->hwnd, GWL_STYLE) & ES_MULTILINE) &&
		_AfxCompareClassName(pMsg->hwnd, _T("Edit")))
	{
		HWND hItem = ::GetDlgItem(m_hWnd, IDCANCEL);
		if (hItem == NULL || ::IsWindowEnabled(hItem))
		{
			SendMessage(WM_COMMAND, IDCANCEL, 0);
			return TRUE;
		}
	}
	// filter both messages to dialog and from children
	return PreTranslateInput(pMsg);
}

BOOL CDialog::OnCmdMsg(UINT nID, int nCode, void* pExtra,
	AFX_CMDHANDLERINFO* pHandlerInfo)
{
	if (CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	if ((nCode != CN_COMMAND && nCode != CN_UPDATE_COMMAND_UI) ||
			!IS_COMMAND_ID(nID) || nID >= 0xf000)
	{
		// control notification or non-command button or system command
		return FALSE;       // not routed any further
	}

	// if we have an owner window, give it second crack
	CWnd* pOwner = GetParent();
	if (pOwner != NULL)
	{
		TRACE(traceCmdRouting, 1, _T("Routing command id 0x%04X to owner window.\n"), nID);

		ASSERT(pOwner != this);
		if (pOwner->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
			return TRUE;
	}

	// last crack goes to the current CWinThread object
	CWinThread* pThread = AfxGetThread();
	if (pThread != NULL)
	{
		TRACE(traceCmdRouting, 1, _T("Routing command id 0x%04X to app.\n"), nID);

		if (pThread->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
			return TRUE;
	}

	TRACE(traceCmdRouting, 1, _T("IGNORING command id 0x%04X sent to %hs dialog.\n"), nID,
			GetRuntimeClass()->m_lpszClassName);

	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Modeless Dialogs have 2-phase construction

CDialog::CDialog()
{
	ASSERT(m_hWnd == NULL);
	AFX_ZERO_INIT_OBJECT(CWnd);

#ifdef _WIN32_WCE
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel == PocketPC || aygshellUIModel == Smartphone)
	{
		m_bFullScreen = TRUE;
		ZeroMemory(&m_SHActivateInfo, sizeof(SHACTIVATEINFO));
		m_SHActivateInfo.cbSize = sizeof(SHACTIVATEINFO)	;
	}
	else
	{
		m_bFullScreen = FALSE;
	}
#endif // _WIN32_WCE
}

CDialog::~CDialog()
{
	if (m_hWnd != NULL)
	{
		TRACE(traceAppMsg, 0, _T("Warning: calling DestroyWindow in CDialog::~CDialog --\n"));
		TRACE(traceAppMsg, 0, _T("\tOnDestroy or PostNcDestroy in derived class will not be called.\n"));
		DestroyWindow();
	}
}

void CDialog::OnPaint()
{
	CPaintDC dc(this);
	if (PaintWindowlessControls(&dc))
	   return;
	Default();
}

BOOL CDialog::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
{
	ASSERT(IS_INTRESOURCE(lpszTemplateName) ||
		AfxIsValidString(lpszTemplateName));

	m_lpszTemplateName = lpszTemplateName;  // used for help
	if (IS_INTRESOURCE(m_lpszTemplateName) && m_nIDHelp == 0)
		m_nIDHelp = LOWORD((DWORD_PTR)m_lpszTemplateName);

#ifdef _DEBUG
	if (!_AfxCheckDialogTemplate(lpszTemplateName, FALSE))
	{
		ASSERT(FALSE);          // invalid dialog template name
		PostNcDestroy();        // cleanup if Create fails too soon
		return FALSE;
	}
#endif //_DEBUG

	HINSTANCE hInst = AfxFindResourceHandle(lpszTemplateName, RT_DIALOG);
	HRSRC hResource = ::FindResource(hInst, lpszTemplateName, RT_DIALOG);
	HGLOBAL hTemplate = LoadResource(hInst, hResource);
	BOOL bResult = CreateIndirect(hTemplate, pParentWnd, hInst);
	FreeResource(hTemplate);

	return bResult;
}

// for backward compatibility
BOOL CDialog::CreateIndirect(HGLOBAL hDialogTemplate, CWnd* pParentWnd)
{
	return CreateIndirect(hDialogTemplate, pParentWnd, NULL);
}

BOOL CDialog::CreateIndirect(HGLOBAL hDialogTemplate, CWnd* pParentWnd,
	HINSTANCE hInst)
{
	ASSERT(hDialogTemplate != NULL);

	LPCDLGTEMPLATE lpDialogTemplate = (LPCDLGTEMPLATE)LockResource(hDialogTemplate);
	BOOL bResult = CreateIndirect(lpDialogTemplate, pParentWnd, NULL, hInst);
	UnlockResource(hDialogTemplate);

	return bResult;
}

// for backward compatibility
BOOL CDialog::CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd,
	void* lpDialogInit)
{
	return CreateIndirect(lpDialogTemplate, pParentWnd, lpDialogInit, NULL);
}

BOOL CDialog::CreateIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd,
	void* lpDialogInit, HINSTANCE hInst)
{
	ASSERT(lpDialogTemplate != NULL);

	if (pParentWnd == NULL)
		pParentWnd = AfxGetMainWnd();
	m_lpDialogInit = lpDialogInit;

	return CreateDlgIndirect(lpDialogTemplate, pParentWnd, hInst);
}

BOOL CWnd::CreateDlg(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
{
	// load resource
	LPCDLGTEMPLATE lpDialogTemplate = NULL;
	HGLOBAL hDialogTemplate = NULL;
	HINSTANCE hInst = AfxFindResourceHandle(lpszTemplateName, RT_DIALOG);
	HRSRC hResource = ::FindResource(hInst, lpszTemplateName, RT_DIALOG);
	hDialogTemplate = LoadResource(hInst, hResource);
	if (hDialogTemplate != NULL)
		lpDialogTemplate = (LPCDLGTEMPLATE)LockResource(hDialogTemplate);
	ASSERT(lpDialogTemplate != NULL);

	// create a modeless dialog
	BOOL bSuccess = CreateDlgIndirect(lpDialogTemplate, pParentWnd, hInst);

	// free resource
	UnlockResource(hDialogTemplate);
	FreeResource(hDialogTemplate);

	return bSuccess;
}

BOOL CWnd::CreateDlgIndirect(LPCDLGTEMPLATE lpDialogTemplate,
	CWnd* pParentWnd, HINSTANCE hInst)
{
	ASSERT(lpDialogTemplate != NULL);
	if (pParentWnd != NULL)
		ASSERT_VALID(pParentWnd);

	if(!hInst)
		hInst = AfxGetResourceHandle();

#ifndef _AFX_NO_OCC_SUPPORT
	_AFX_OCC_DIALOG_INFO occDialogInfo;
	COccManager* pOccManager = afxOccManager;
#endif

	HGLOBAL hTemplate = NULL;

	HWND hWnd = NULL;
#ifdef _DEBUG
	DWORD dwError = 0;
#endif

	TRY
	{
		VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTLS_REG));
		AfxDeferRegisterClass(AFX_WNDCOMMCTLSNEW_REG);

#ifndef _AFX_NO_OCC_SUPPORT
		// separately create OLE controls in the dialog template
		if (pOccManager != NULL)
		{
			if (!SetOccDialogInfo(&occDialogInfo))
				return FALSE;

			lpDialogTemplate = pOccManager->PreCreateDialog(&occDialogInfo,
				lpDialogTemplate);
		}

		if (lpDialogTemplate == NULL)
			return FALSE;
#endif //!_AFX_NO_OCC_SUPPORT

		// If no font specified, set the system font.
		CString strFace;
		WORD wSize = 0;
		BOOL bSetSysFont = !CDialogTemplate::GetFont(lpDialogTemplate, strFace,
			wSize);

		if (afxData.bWin95 && !bSetSysFont && GetSystemMetrics(SM_DBCSENABLED))
		{
			bSetSysFont = (strFace == _T("MS Shell Dlg"));
			if (bSetSysFont && (wSize == 8))
				wSize = 0;
		}

		if (bSetSysFont)
		{
			CDialogTemplate dlgTemp(lpDialogTemplate);
			dlgTemp.SetSystemFont(wSize);
			hTemplate = dlgTemp.Detach();
		}

		if (hTemplate != NULL)
			lpDialogTemplate = (DLGTEMPLATE*)GlobalLock(hTemplate);

		// setup for modal loop and creation
		m_nModalResult = -1;
		m_nFlags |= WF_CONTINUEMODAL;

		// create modeless dialog
		AfxHookWindowCreate(this);
#ifdef _WIN32_WCE
		int aygshellUIModel = AfxGetAygshellUIModel();
		if ((aygshellUIModel == PocketPC || aygshellUIModel == Smartphone) && (lpDialogTemplate->style & DS_MODALFRAME)) 
		{
			// Fail DS_MODALFRAME can't be set for Pocket PC and Smartphone
			TRACE(traceAppMsg, 0, _T("ERROR: dialog template has DS_MODALFRAME set, which is not supported for Pocket PC and Smartphone\n"));
			return FALSE;
		}

		// CreateDialogIndirect is a macro, so just the last parameter can't be preprocessed differently
		hWnd = ::CreateDialogIndirect(hInst, lpDialogTemplate,
			pParentWnd->GetSafeHwnd(), AfxDlgProcEx);
#else // _WIN32_WCE
		hWnd = ::CreateDialogIndirect(hInst, lpDialogTemplate,
			pParentWnd->GetSafeHwnd(), AfxDlgProc);
#endif // _WIN32_WCE

#ifdef _DEBUG
		dwError = ::GetLastError();
#endif
	}
	CATCH_ALL(e)
	{
		DELETE_EXCEPTION(e);
		m_nModalResult = -1;
	}
	END_CATCH_ALL

#ifndef _AFX_NO_OCC_SUPPORT
	if (pOccManager != NULL)
	{
		pOccManager->PostCreateDialog(&occDialogInfo);
		if (hWnd != NULL)
			SetOccDialogInfo(NULL);
	}
#endif //!_AFX_NO_OCC_SUPPORT

	if (!AfxUnhookWindowCreate())
		PostNcDestroy();        // cleanup if Create fails too soon

	// handle EndDialog calls during OnInitDialog
#ifdef _DEBUG
#ifndef _AFX_NO_OCC_SUPPORT
	DWORD dwOldFlags = m_nFlags;
#endif
#endif
	if (hWnd != NULL && !(m_nFlags & WF_CONTINUEMODAL))
	{
		::DestroyWindow(hWnd);
		hWnd = NULL;
	}

	if (hTemplate != NULL)
	{
		GlobalUnlock(hTemplate);
		GlobalFree(hTemplate);
	}

	// help with error diagnosis (only if WM_INITDIALOG didn't EndDialog())
	if (hWnd == NULL)
	{
#ifdef _DEBUG
#ifndef _AFX_NO_OCC_SUPPORT
		if (dwOldFlags & WF_CONTINUEMODAL)
		{
			if (afxOccManager == NULL)
			{
				TRACE(traceAppMsg, 0, _T(">>> If this dialog has OLE controls:\n"));
				TRACE(traceAppMsg, 0, _T(">>> AfxEnableControlContainer has not been called yet.\n"));
				TRACE(traceAppMsg, 0, _T(">>> You should call it in your app's InitInstance function.\n"));
			}
			else if (dwError != 0)
			{
				TRACE(traceAppMsg, 0, _T("Warning: Dialog creation failed!  GetLastError returns 0x%8.8X\n"), dwError);
			}
		}
#endif //!_AFX_NO_OCC_SUPPORT
#endif //_DEBUG
		return FALSE;
	}

	ASSERT(hWnd == m_hWnd);
	return TRUE;
}

#ifndef _AFX_NO_OCC_SUPPORT

BOOL CDialog::SetOccDialogInfo(_AFX_OCC_DIALOG_INFO* pOccDialogInfo)
{
	m_pOccDialogInfo = pOccDialogInfo;
	return TRUE;
}

_AFX_OCC_DIALOG_INFO* CDialog::GetOccDialogInfo()
{
	return m_pOccDialogInfo;	
}

#endif

/////////////////////////////////////////////////////////////////////////////
// Modal Dialogs

// Modal Constructors just save parameters
CDialog::CDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
{
	ASSERT(IS_INTRESOURCE(lpszTemplateName) ||
		AfxIsValidString(lpszTemplateName));

	AFX_ZERO_INIT_OBJECT(CWnd);

	m_pParentWnd = pParentWnd;
	m_lpszTemplateName = lpszTemplateName;
	if (IS_INTRESOURCE(m_lpszTemplateName))
		m_nIDHelp = LOWORD((DWORD_PTR)m_lpszTemplateName);

#ifdef _WIN32_WCE
	CDialog::SHInitDialog();
#endif // _WIN32_WCE
}

CDialog::CDialog(UINT nIDTemplate, CWnd* pParentWnd)
{
	AFX_ZERO_INIT_OBJECT(CWnd);

	m_pParentWnd = pParentWnd;
	m_lpszTemplateName = MAKEINTRESOURCE(nIDTemplate);
	m_nIDHelp = nIDTemplate;

#ifdef _WIN32_WCE
	CDialog::SHInitDialog();
#endif // _WIN32_WCE
}

#ifdef _DEVICE_RESOLUTION_AWARE
CDialog::CDialog(UINT nIDTemplate, UINT nIDWideTemplate, CWnd* pParentWnd)
{
	AFX_ZERO_INIT_OBJECT(CWnd);

	m_pParentWnd = pParentWnd;
	m_lpszTemplateName = MAKEINTRESOURCE(nIDTemplate);
	m_nIDHelp = nIDTemplate;

	m_lpszWideTemplateName = MAKEINTRESOURCE(nIDWideTemplate);

	CDialog::SHInitDialog();
}
#endif // _DEVICE_RESOLUTION_AWARE

#ifdef _WIN32_WCE
void CDialog::SHInitDialog()
{
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel == PocketPC || aygshellUIModel == Smartphone)
	{
		m_bFullScreen = TRUE;
		ZeroMemory(&m_SHActivateInfo, sizeof(SHACTIVATEINFO));
		m_SHActivateInfo.cbSize = sizeof(SHACTIVATEINFO)	;
	}
	else
	{
		m_bFullScreen = FALSE;
	}
}
#endif // _WIN32_WCE

BOOL CDialog::InitModalIndirect(HGLOBAL hDialogTemplate, CWnd* pParentWnd)
{
	// must be called on an empty constructed CDialog
	ASSERT(m_lpszTemplateName == NULL);
	ASSERT(m_hDialogTemplate == NULL);
	ASSERT(hDialogTemplate != NULL);

	if (m_pParentWnd == NULL)
		m_pParentWnd = pParentWnd;

	m_hDialogTemplate = hDialogTemplate;

	return TRUE;    // always ok (DoModal actually brings up dialog)
}

BOOL CDialog::InitModalIndirect(LPCDLGTEMPLATE lpDialogTemplate, CWnd* pParentWnd,
	void* lpDialogInit)
{
	// must be called on an empty constructed CDialog
	ASSERT(m_lpszTemplateName == NULL);
	ASSERT(m_lpDialogTemplate == NULL);
	ASSERT(lpDialogTemplate != NULL);

	if (m_pParentWnd == NULL)
		m_pParentWnd = pParentWnd;

	m_lpDialogTemplate = lpDialogTemplate;
	m_lpDialogInit = lpDialogInit;

	return TRUE;    // always ok (DoModal actually brings up dialog)
}

HWND CDialog::PreModal()
{
	// cannot call DoModal on a dialog already constructed as modeless
	ASSERT(m_hWnd == NULL);

	// allow OLE servers to disable themselves
	CWinApp* pApp = AfxGetApp();
	if (pApp != NULL)
		pApp->EnableModeless(FALSE);

	// find parent HWND
	HWND hWnd = CWnd::GetSafeOwner_(m_pParentWnd->GetSafeHwnd(), &m_hWndTop);

	// hook for creation of dialog
	AfxHookWindowCreate(this);

	// return window to use as parent for dialog
	return hWnd;
}

void CDialog::PostModal()
{
	AfxUnhookWindowCreate();   // just in case
	Detach();               // just in case

	// re-enable windows
	if (::IsWindow(m_hWndTop))
		::EnableWindow(m_hWndTop, TRUE);
	m_hWndTop = NULL;
	CWinApp* pApp = AfxGetApp();
	if (pApp != NULL)
		pApp->EnableModeless(TRUE);
}

INT_PTR CDialog::DoModal()
{
	// can be constructed with a resource template or InitModalIndirect
	ASSERT(m_lpszTemplateName != NULL || m_hDialogTemplate != NULL ||
		m_lpDialogTemplate != NULL);

	// load resource as necessary
	LPCDLGTEMPLATE lpDialogTemplate = m_lpDialogTemplate;
	HGLOBAL hDialogTemplate = m_hDialogTemplate;
	HINSTANCE hInst = AfxGetResourceHandle();
	if (m_lpszTemplateName != NULL)
	{
		hInst = AfxFindResourceHandle(m_lpszTemplateName, RT_DIALOG);
		HRSRC hResource = ::FindResource(hInst, m_lpszTemplateName, RT_DIALOG);
		hDialogTemplate = LoadResource(hInst, hResource);
	}
	if (hDialogTemplate != NULL)
		lpDialogTemplate = (LPCDLGTEMPLATE)LockResource(hDialogTemplate);

	// return -1 in case of failure to load the dialog template resource
	if (lpDialogTemplate == NULL)
		return -1;

	// disable parent (before creating dialog)
	HWND hWndParent = PreModal();
	AfxUnhookWindowCreate();
	BOOL bEnableParent = FALSE;
#ifndef _AFX_NO_OLE_SUPPORT
	CWnd* pMainWnd = NULL;
	BOOL bEnableMainWnd = FALSE;
#endif
	if (hWndParent && hWndParent != ::GetDesktopWindow() && ::IsWindowEnabled(hWndParent))
	{
		::EnableWindow(hWndParent, FALSE);
		bEnableParent = TRUE;
#ifndef _AFX_NO_OLE_SUPPORT
		pMainWnd = AfxGetMainWnd();
		if (pMainWnd && pMainWnd->IsFrameWnd() && pMainWnd->IsWindowEnabled())
		{
			//
			// We are hosted by non-MFC container
			// 
			pMainWnd->EnableWindow(FALSE);
			bEnableMainWnd = TRUE;
		}
#endif
	}

	TRY
	{
		// create modeless dialog
		AfxHookWindowCreate(this);
		if (CreateDlgIndirect(lpDialogTemplate,
						CWnd::FromHandle(hWndParent), hInst))
		{
			if (m_nFlags & WF_CONTINUEMODAL)
			{
				// enter modal loop
				DWORD dwFlags = MLF_SHOWONIDLE;
				if (GetStyle() & DS_NOIDLEMSG)
					dwFlags |= MLF_NOIDLEMSG;
				VERIFY(RunModalLoop(dwFlags) == m_nModalResult);
			}

			// hide the window before enabling the parent, etc.
			if (m_hWnd != NULL)
				SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW|
					SWP_NOSIZE|SWP_NOMOVE|SWP_NOACTIVATE|SWP_NOZORDER);
		}
	}
	CATCH_ALL(e)
	{
		DELETE_EXCEPTION(e);
		m_nModalResult = -1;
	}
	END_CATCH_ALL

#ifndef _AFX_NO_OLE_SUPPORT
	if (bEnableMainWnd)
		pMainWnd->EnableWindow(TRUE);
#endif
	if (bEnableParent)
		::EnableWindow(hWndParent, TRUE);
	if (hWndParent != NULL && ::GetActiveWindow() == m_hWnd)
		::SetActiveWindow(hWndParent);

	// destroy modal window
	DestroyWindow();
	PostModal();

	// unlock/free resources as necessary
	if (m_lpszTemplateName != NULL || m_hDialogTemplate != NULL)
		UnlockResource(hDialogTemplate);
	if (m_lpszTemplateName != NULL)
		FreeResource(hDialogTemplate);

	return m_nModalResult;
}

void CDialog::EndDialog(int nResult)
{
	ASSERT(::IsWindow(m_hWnd));

	if (m_nFlags & (WF_MODALLOOP|WF_CONTINUEMODAL))
		EndModalLoop(nResult);

	::EndDialog(m_hWnd, nResult);
}

/////////////////////////////////////////////////////////////////////////////
// Standard CDialog implementation

LRESULT CDialog::HandleSetFont(WPARAM wParam, LPARAM)
{
	OnSetFont(CFont::FromHandle((HFONT)wParam));
	return Default();
}

void CDialog::PreInitDialog()
{
	// ignore it
}

LRESULT CDialog::HandleInitDialog(WPARAM, LPARAM)
{
	PreInitDialog();

#ifndef _AFX_NO_OCC_SUPPORT
	// create OLE controls
	COccManager* pOccManager = afxOccManager;
	if ((pOccManager != NULL) && (m_pOccDialogInfo != NULL))
	{
		BOOL bDlgInit;
		if (m_lpDialogInit != NULL)
			bDlgInit = pOccManager->CreateDlgControls(this, m_lpDialogInit,
				m_pOccDialogInfo);
		else
			bDlgInit = pOccManager->CreateDlgControls(this, m_lpszTemplateName,
				m_pOccDialogInfo);

		if (!bDlgInit)
		{
			TRACE(traceAppMsg, 0, _T("Warning: CreateDlgControls failed during dialog init.\n"));
			EndDialog(-1);
			return FALSE;
		}
	}
#endif

	// Default will call the dialog proc, and thus OnInitDialog
	LRESULT bResult = Default();

#ifndef _AFX_NO_OCC_SUPPORT
	if (bResult && (m_nFlags & WF_OLECTLCONTAINER))
	{
		CWnd* pWndNext = GetNextDlgTabItem(NULL);
		if (pWndNext != NULL)
		{
			pWndNext->SetFocus();   // UI Activate OLE control
			bResult = FALSE;
		}
	}
#endif

	return bResult;
}

BOOL AFXAPI AfxHelpEnabled()
{
	if (AfxGetApp() == NULL)
		return FALSE;

	// help is enabled if the app has a handler for ID_HELP
	AFX_CMDHANDLERINFO info;

	// check main window first
	CWnd* pWnd = AfxGetMainWnd();
	if (pWnd != NULL && pWnd->OnCmdMsg(ID_HELP, CN_COMMAND, NULL, &info))
		return TRUE;

	// check app last
	return AfxGetApp()->OnCmdMsg(ID_HELP, CN_COMMAND, NULL, &info);
}

void CDialog::OnSetFont(CFont*)
{
	// ignore it
}

BOOL CDialog::OnInitDialog()
{
	// execute dialog RT_DLGINIT resource
	BOOL bDlgInit;
	if (m_lpDialogInit != NULL)
		bDlgInit = ExecuteDlgInit(m_lpDialogInit);
	else
		bDlgInit = ExecuteDlgInit(m_lpszTemplateName);

	if (!bDlgInit)
	{
		TRACE(traceAppMsg, 0, _T("Warning: ExecuteDlgInit failed during dialog init.\n"));
		EndDialog(-1);
		return FALSE;
	}

	// transfer data into the dialog from member variables
	if (!UpdateData(FALSE))
	{
		TRACE(traceAppMsg, 0, _T("Warning: UpdateData failed during dialog init.\n"));
		EndDialog(-1);
		return FALSE;
	}

	// enable/disable help button automatically
	CWnd* pHelpButton = GetDlgItem(ID_HELP);
	if (pHelpButton != NULL)
		pHelpButton->ShowWindow(AfxHelpEnabled() ? SW_SHOW : SW_HIDE);

#ifdef _WIN32_WCE
	int aygshellUIModel = AfxGetAygshellUIModel();
	if ((aygshellUIModel == PocketPC || aygshellUIModel == Smartphone) && m_bFullScreen)
	{
		// zero-initialize the SHACTIVATEINFO structure as a prerequsite for calling SHHandleWMActivate 
		// and SHHandleWMSettingChange in the first time. Typically, this would be done during WM_CREATE
		// or WM_INITDIALOG processing. 
		ZeroMemory(&m_SHActivateInfo, sizeof(SHACTIVATEINFO));
		m_SHActivateInfo.cbSize = sizeof(SHACTIVATEINFO);

		//
		SHINITDLGINFO shidi;
		ZeroMemory(&shidi, sizeof(SHINITDLGINFO));
		
		shidi.dwMask = SHIDIM_FLAGS;
		if (aygshellUIModel == PocketPC)
		{
			shidi.dwFlags = SHIDIF_DONEBUTTON | SHIDIF_SIPDOWN | SHIDIF_SIZEDLGFULLSCREEN | SHIDIF_EMPTYMENU;
		}
		else
		{
			shidi.dwFlags = SHIDIF_SIZEDLGFULLSCREEN;
		}
		shidi.hDlg = m_hWnd;

		::SetForegroundWindow(m_hWnd);

		if (!AYGSHELL::SHInitDialog(&shidi))
		{
#ifdef _DEBUG
			TRACE(traceAppMsg, 0, _T("Making Fullscreen dialog failed during dialog init."));
#endif
		}
	}
#endif // _WIN32_WCE

	return TRUE;    // set focus to first one
}

void CDialog::OnOK()
{
	if (!UpdateData(TRUE))
	{
		TRACE(traceAppMsg, 0, _T("UpdateData failed during dialog termination.\n"));
		// the UpdateData routine will set focus to correct item
		return;
	}
	EndDialog(IDOK);
}

void CDialog::OnCancel()
{
	EndDialog(IDCANCEL);
}

#ifdef _WIN32_WCE
void CDialog::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	int aygshellUIModel = AfxGetAygshellUIModel();
	if ((aygshellUIModel == PocketPC || aygshellUIModel == Smartphone) && !(GetStyle() & WS_CHILD))
	{
		_AFX_THREAD_STATE* pThreadState = _afxThreadState.GetData();

		AYGSHELL::SHHandleWMSettingChange(m_hWnd, pThreadState->m_lastSentMsg.wParam,
			pThreadState->m_lastSentMsg.lParam, &m_SHActivateInfo);
	}
	
	CWnd::OnSettingChange(uFlags, lpszSection);
}

void CDialog::OnActivate(UINT nState, CWnd* pWndOther,	BOOL bMinimized)
{
	int aygshellUIModel = AfxGetAygshellUIModel();
	if ((aygshellUIModel == PocketPC || aygshellUIModel == Smartphone) && !(GetStyle() & WS_CHILD))
	{
		_AFX_THREAD_STATE* pThreadState = _afxThreadState.GetData();

		AYGSHELL::SHHandleWMActivate(m_hWnd, pThreadState->m_lastSentMsg.wParam, 
			pThreadState->m_lastSentMsg.lParam, &m_SHActivateInfo, FALSE);
	}
	
	CWnd::OnActivate(nState, pWndOther, bMinimized);
}
#endif // _WIN32_WCE

#ifdef _DEVICE_RESOLUTION_AWARE
void CDialog::OnSize(UINT nType, int cx, int cy)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetInstanceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? m_lpszWideTemplateName : m_lpszTemplateName);
	}
	else
	{
		CWnd::OnSize(nType, cx, cy);
	}
}
#endif // _DEVICE_RESOLUTION_AWARE

BOOL CDialog::CheckAutoCenter()
{
	// load resource as necessary
	LPCDLGTEMPLATE lpDialogTemplate = m_lpDialogTemplate;
	HGLOBAL hDialogTemplate = m_hDialogTemplate;
	if (m_lpszTemplateName != NULL)
	{
		HINSTANCE hInst = AfxFindResourceHandle(m_lpszTemplateName, RT_DIALOG);
		HRSRC hResource = ::FindResource(hInst, m_lpszTemplateName, RT_DIALOG);
		hDialogTemplate = LoadResource(hInst, hResource);
	}
	if (hDialogTemplate != NULL)
		lpDialogTemplate = (LPCDLGTEMPLATE)LockResource(hDialogTemplate);

	// determine if dialog should be centered
	BOOL bResult = TRUE;

	if (lpDialogTemplate != NULL)
	{
		DWORD dwStyle = lpDialogTemplate->style;
		short x;
		short y;

		if (((DLGTEMPLATEEX*)lpDialogTemplate)->signature == 0xFFFF)
		{
			// it's a DIALOGEX resource
			dwStyle = ((DLGTEMPLATEEX*)lpDialogTemplate)->style;
			x = ((DLGTEMPLATEEX*)lpDialogTemplate)->x;
			y = ((DLGTEMPLATEEX*)lpDialogTemplate)->y;
		}
		else
		{
			// it's a DIALOG resource
			x = lpDialogTemplate->x;
			y = lpDialogTemplate->y;
		}

		bResult = !(dwStyle & (DS_CENTER|DS_CENTERMOUSE|DS_ABSALIGN)) &&
			x == 0 && y == 0;
	}

	// unlock/free resources as necessary
	if (m_lpszTemplateName != NULL || m_hDialogTemplate != NULL)
		UnlockResource(hDialogTemplate);
	if (m_lpszTemplateName != NULL)
		FreeResource(hDialogTemplate);

	return bResult; // TRUE if auto-center is ok
}

/////////////////////////////////////////////////////////////////////////////
// CDialog support for context sensitive help.

#ifndef _WIN32_WCE_NO_HELP_SUPPORT
LRESULT CDialog::OnCommandHelp(WPARAM, LPARAM lParam)
{
	if (lParam == 0 && m_nIDHelp != 0)
		lParam = HID_BASE_RESOURCE + m_nIDHelp;
	if (lParam != 0)
	{
		CWinApp* pApp = AfxGetApp();
		if (pApp != NULL)
			pApp->WinHelpInternal(lParam);
		return TRUE;
	}
	return FALSE;
}

LRESULT CDialog::OnHelpHitTest(WPARAM, LPARAM)
{
	if (m_nIDHelp != 0)
		return HID_BASE_RESOURCE + m_nIDHelp;
	return 0;
}
#endif // !_WIN32_WCE_NO_HELP_SUPPORT

/////////////////////////////////////////////////////////////////////////////
// CDialog Diagnostics

#ifdef _DEBUG
void CDialog::AssertValid() const
{
	CWnd::AssertValid();
}

#ifndef _WIN32_WCE
void CDialog::Dump(CDumpContext& dc) const
{
	CWnd::Dump(dc);

	dc << "m_lpszTemplateName = ";
	if (IS_INTRESOURCE(m_lpszTemplateName))
		dc << (int)LOWORD((DWORD_PTR)m_lpszTemplateName);
	else
		dc << m_lpszTemplateName;

	dc << "\nm_hDialogTemplate = " << (void*)m_hDialogTemplate;
	dc << "\nm_lpDialogTemplate = " << (void*)m_lpDialogTemplate;
	dc << "\nm_pParentWnd = " << (void*)m_pParentWnd;
	dc << "\nm_nIDHelp = " << m_nIDHelp;

	dc << "\n";
}
#endif // !_WIN32_WCE

// diagnostic routine to check for and decode dialog templates
// return FALSE if a program error occurs (i.e. bad resource ID or
//   bad dialog styles).
BOOL AFXAPI _AfxCheckDialogTemplate(LPCTSTR lpszResource, BOOL bInvisibleChild)
{
	ASSERT(lpszResource != NULL);
	HINSTANCE hInst = AfxFindResourceHandle(lpszResource, RT_DIALOG);
	HRSRC hResource = ::FindResource(hInst, lpszResource, RT_DIALOG);
	if (hResource == NULL)
	{
		if (DWORD_PTR(lpszResource) > 0xffff)
			TRACE(traceAppMsg, 0, _T("ERROR: Cannot find dialog template named '%s'.\n"),
				lpszResource);
		else
			TRACE(traceAppMsg, 0, _T("ERROR: Cannot find dialog template with IDD 0x%04X.\n"),
				LOWORD((DWORD_PTR)lpszResource));
		return FALSE;
	}

	if (!bInvisibleChild)
		return TRUE;        // that's all we need to check

	// we must check that the dialog template is for an invisible child
	//  window that can be used for a form-view or dialog-bar
	HGLOBAL hTemplate = LoadResource(hInst, hResource);
	if (hTemplate == NULL)
	{
		TRACE(traceAppMsg, 0, _T("Warning: LoadResource failed for dialog template.\n"));
		// this is only a warning, the real call to CreateDialog will fail
		return TRUE;        // not a program error - just out of memory
	}
	DLGTEMPLATEEX* pTemplate = (DLGTEMPLATEEX*)LockResource(hTemplate);
	DWORD dwStyle;
	if (pTemplate->signature == 0xFFFF)
		dwStyle = pTemplate->style;
	else
		dwStyle = ((DLGTEMPLATE*)pTemplate)->style;
	UnlockResource(hTemplate);
	FreeResource(hTemplate);

	if (dwStyle & WS_VISIBLE)
	{
		if (DWORD_PTR(lpszResource) > 0xffff)
			TRACE(traceAppMsg, 0, _T("ERROR: Dialog named '%s' must be invisible.\n"),
				lpszResource);
		else
			TRACE(traceAppMsg, 0, _T("ERROR: Dialog with IDD 0x%04X must be invisible.\n"),
				LOWORD((DWORD_PTR)lpszResource));
		return FALSE;
	}
	if (!(dwStyle & WS_CHILD))
	{
		if (DWORD_PTR(lpszResource) > 0xffff)
			TRACE(traceAppMsg, 0, _T("ERROR: Dialog named '%s' must have the child style.\n"),
				lpszResource);
		else
			TRACE(traceAppMsg, 0, _T("ERROR: Dialog with IDD 0x%04X must have the child style.\n"),
				LOWORD((DWORD_PTR)lpszResource));
		return FALSE;
	}

	return TRUE;
}

#endif //_DEBUG


IMPLEMENT_DYNAMIC(CDialog, CWnd)

/////////////////////////////////////////////////////////////////////////////
