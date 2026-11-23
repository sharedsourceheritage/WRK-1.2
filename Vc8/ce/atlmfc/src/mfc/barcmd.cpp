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

#ifdef AFX_CORE3_SEG
#pragma code_seg(AFX_CORE3_SEG)
#endif


#define new DEBUG_NEW

#ifdef _WIN32_WCE
#pragma comment(lib, "commctrl.lib")

/////////////////////////////////////////////////////////////////////////////
// CReBar

BEGIN_MESSAGE_MAP(CCommandBar, CToolBar)
#ifdef _WIN32_WCE_DOCLIST_SUPPORT
	ON_COMMAND(ID_FILE_NEW, &CCommandBar::OnSharedNew)
#endif // _WIN32_WCE_DOCLIST_SUPPORT
END_MESSAGE_MAP()

CCommandBar::CCommandBar(HWND /*hWnd*/) 
{
	m_bAppendBitmaps = FALSE;
	m_bAdornmentsAdded = FALSE;
	m_pCommandBar = this;
	m_hCommandBar = NULL;	// handle to commandbar or menubar
	m_pMenu = NULL;		// pointer to the menu on commandbar or menubar
}

CCommandBar::~CCommandBar()
{
	if (m_hWnd != NULL)
	{
		CFrameWnd* pFrameWnd = GetParentFrame();
		if (pFrameWnd != NULL && pFrameWnd->m_hCommandBar == m_hCommandBar)
		{
			pFrameWnd->m_hCommandBar = NULL;
		}

		HWND hWnd = m_hWnd;
		Detach();
		::DestroyWindow(hWnd);
	}

	if (m_pMenu != NULL)
	{
		if (m_pMenu->m_hMenu != NULL)
		{
			m_pMenu->DestroyMenu();
		}
		delete m_pMenu;
	}
}

#ifdef _WIN32_WCE_DOCLIST_SUPPORT
void CCommandBar::OnSharedNew()
{
	if (AfxGetAygshellUIModel() == PocketPC)
	{
		CWinApp* pApp = AfxGetApp();
		if (pApp != NULL)
		{
			pApp->OnCmdMsg(ID_FILE_NEW, 0, NULL, NULL);	
		}
	}
}
#endif // _WIN32_WCE_DOCLIST_SUPPORT

BOOL CCommandBar::Create(CWnd* pWndParent, DWORD dwStyle, UINT /*nBarID*/)
{
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel != PocketPC && aygshellUIModel != Smartphone)
	{	
		// for CommandBar on Windows CE, the current window IS the commandbar window
		m_hCommandBar = m_hWnd;
		return CToolBar::Create(pWndParent, dwStyle, AFX_IDW_TOOLBAR);
	}
	else
	{
		return CreateEx(pWndParent);
	}

	return FALSE;
}

BOOL CCommandBar::CreateEx(CWnd* pWndParent, DWORD dwCtrlStyle, DWORD dwStyle, CRect rcBorders, UINT /*nBarID*/)
{
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel != PocketPC && aygshellUIModel != Smartphone)
	{
		// for CommandBar on Windows CE, the current window IS the commandbar window
		m_hCommandBar = m_hWnd;
		return CToolBar::CreateEx(pWndParent, dwCtrlStyle, dwStyle, rcBorders, AFX_IDW_TOOLBAR);
	}

	UINT nToolBarId = AFX_IDR_SCRATCH_SHMENU;
	HINSTANCE hInstance = AfxFindResourceHandle(MAKEINTRESOURCE(nToolBarId), RT_RCDATA);
	ASSERT(hInstance != NULL);

	// create an empty menubar so that we can make use of the parent window in the later 
	SHMENUBARINFO mbi;
	ZeroMemory(&mbi, sizeof(SHMENUBARINFO));
	mbi.cbSize = sizeof(SHMENUBARINFO);
	mbi.hwndParent = pWndParent->GetSafeHwnd();
	mbi.nToolBarId = nToolBarId;
	mbi.hInstRes   = hInstance;

	if (!AYGSHELL::SHCreateMenuBar(&mbi)) 
	{
#ifdef _DEBUG
		TRACE1("Warning: Failed creating menu bar at the bottom of the window: GetLastError returns 0x%8.8X\n", GetLastError());
#endif
	}

	if (mbi.hwndMB == NULL)
	{
		return FALSE;
	}
	
	// for MenuBar on Pocket PC and Smartphone, the menubar window is pointed to by mbi.hwndMB
	m_hCommandBar = mbi.hwndMB;

	VERIFY(SubclassWindow(mbi.hwndMB));

	if (pWndParent->IsFrameWnd())
	{
		m_pDockSite = (CFrameWnd*)pWndParent;
		m_pDockSite->AddControlBar(this);
		m_pDockSite->m_hCommandBar = mbi.hwndMB;
	}

	VERIFY(DefWindowProc(TB_DELETEBUTTON, 0, 0));

	return TRUE;
}

void CCommandBar::Destroy()
{
	// If the command bar's parent window is being destroyed, it's not necessary to call CommandBar_Destroy.
	// And when CommandBar_Destroy is called, it actually calls the DestroyWindow function to destroy the
	// command bar, which is defined in SDK commctrl.h. But the CControlBar::DestroyWindow does not take
	// any parameters, so we call DestroyWindow() directly at here.
	DestroyWindow();
}

BOOL CCommandBar::Show(BOOL bShow)
{
	ASSERT(::IsWindow(m_hWnd)); 
	return ::CommandBar_Show(m_hWnd, bShow);
}

BOOL CCommandBar::IsVisible() const
{
	ASSERT(::IsWindow(m_hWnd));

	// CommandBar_IsVisible is defined to be IsWindowVisible taking one parameter which is the handle to current
	// command bar.  But CWnd::IsWindowVisible does not take any parameters, so we call IsWindowVisible directly
	// at here.
	return IsWindowVisible();
}

int CCommandBar::Height() const
{
	ASSERT(::IsWindow(m_hWnd)); 
	return ::CommandBar_Height(m_hWnd);
}

HMENU CCommandBar::GetMenu() const
{
	return m_pMenu->m_hMenu;
}

BOOL CCommandBar::AddAdornments(DWORD dwFlags)
{
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel == PocketPC || aygshellUIModel == Smartphone)
	{
		return TRUE;
	}

	ASSERT(::IsWindow(m_hWnd)); 
	ASSERT((dwFlags == 0) || (dwFlags & CMDBAR_OK) || (dwFlags & CMDBAR_HELP));

	if (m_bAdornmentsAdded)
		return FALSE;	// Can add adornments only once

	CFrameWnd* pFrame = GetParentFrame();
	if (pFrame != NULL)
		pFrame->RecalcLayout(FALSE); // This is necessary to right align the adornment buttons

	HIMAGELIST hImageList = (HIMAGELIST)DefWindowProc(TB_GETIMAGELIST, 0, 0);
	int nBitmapCount = 0;
	if(hImageList != NULL)
		nBitmapCount = ImageList_GetImageCount(hImageList);

	// before calling the CommandBar_AddAdornments...
	int nButtonCountBefore = ::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0);

	if (!::CommandBar_AddAdornments(m_hWnd, dwFlags, 0))
		return FALSE;

	// after calling the CommandBar_AddAdornments, we might have more buttons added
	int nButtonCountAfter = ::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0);

	m_bAdornmentsAdded = TRUE;

	int nAdornments = 1;
	nAdornments += (dwFlags & CMDBAR_OK) ? 1 : 0;
	nAdornments += (dwFlags & CMDBAR_HELP) ? 1 : 0;

	// Adornments may have incorrect bitmap indices because of our ImageList_Add
	// workaround in bartool.cpp, so fix them. The adornment indices are in decreasing
	// order.
	TBBUTTON tbButton; memset(&tbButton, 0, sizeof(TBBUTTON));
	for (int idxButton = nButtonCountBefore ; idxButton < nButtonCountAfter ; idxButton++)
	{
		_GetButton(idxButton, &tbButton);
		if (tbButton.fsStyle != TBSTYLE_SEP)
		{
			if ((tbButton.idCommand == WM_CLOSE) || (tbButton.idCommand == IDOK))
			{
				tbButton.iBitmap = nBitmapCount + nAdornments - 1;
				_SetButton(idxButton, &tbButton);
			}
			nAdornments--;
		}
	}

	return TRUE;
}

int CCommandBar::AddBitMap(int nBitmapID, int nNumImages)
{
	ASSERT(::IsWindow(m_hWnd)); 

	// When HINST_COMMCTRL is specified in the instance handle, system-defined button
	// bitmaps could be used by specifying either IDB_STD_SMALL_COLOR or IDB_VIEW_SMALL_COLOR
	return ::CommandBar_AddBitmap(m_hWnd, AfxGetInstanceHandle(), nBitmapID, nNumImages, 0, 0);
}

BOOL CCommandBar::AddButtons(UINT uNumButtons, LPTBBUTTON lpButtons)
{
	ASSERT(::IsWindow(m_hWnd));

	return ::CommandBar_AddButtons(m_hWnd, uNumButtons, lpButtons);
}

#ifndef _WIN32_WCE_NO_TOOLTIPS
BOOL CCommandBar::AddToolTips(UINT uNumToolTips, LPTSTR lpToolTips)
{
	ASSERT(::IsWindow(m_hWnd));
	return ::CommandBar_AddToolTips(m_hWnd, uNumToolTips, lpToolTips);
}
#endif // !_WIN32_WCE_NO_TOOLTIPS

BOOL CCommandBar::DrawMenuBar(WORD wButton)
{
	ASSERT(::IsWindow(m_hWnd));

	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel == PocketPC || aygshellUIModel == Smartphone)
	{
		return TRUE;
	}

	return ::CommandBar_DrawMenuBar(m_hWnd, wButton);
}

BOOL CCommandBar::InsertButton(int nButton, LPTBBUTTON lpButton)
{
	ASSERT(::IsWindow(m_hWnd));
	return ::CommandBar_InsertButton(m_hWnd, nButton, lpButton); 
}

CComboBox* CCommandBar::InsertComboBox(int nWidth, DWORD dwStyle, WORD wComboBoxID, WORD wButton)
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(nWidth >= 1);

	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel == Smartphone)
	{
		return NULL;
	}
	
	WORD wButtonCount = (WORD)::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0);
	ASSERT((wButton == CMDBAR_END) || ((wButton >=0) && (wButton <= wButtonCount)));

	BOOL bTempButton = FALSE;
	if ((wButton == CMDBAR_END) || (wButton == wButtonCount))
	{
		// adding combo boxes at the end doesn't work quite right, 
		// so workaround with a temporary button.
		VERIFY(InsertSeparator());

		wButton = (WORD)::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0) - 1;
		bTempButton = TRUE;
	}

	HWND hwndCmdBar = NULL;
	if (aygshellUIModel == PocketPC)
	{
		hwndCmdBar = ::GetWindow(m_hWnd, GW_CHILD);
	}
	else
	{
		hwndCmdBar = m_hWnd;
	}
	HWND hComboBox = ::CommandBar_InsertComboBox(hwndCmdBar, AfxGetInstanceHandle(), nWidth, 
		dwStyle | CBS_DROPDOWN, wComboBoxID, wButton);
	ASSERT(hComboBox != NULL);

	if (bTempButton)
		VERIFY(DefWindowProc(TB_DELETEBUTTON, wButton + 1, 0));

	CComboBox* pComboBox = new CComboBox; 
	if (pComboBox != NULL)
	{
		if (aygshellUIModel == PocketPC)
		{
			pComboBox->SubclassWindow(hComboBox);
		}
		else
		{
			pComboBox->Attach(hComboBox);
		}
	}
	else
	{
		ASSERT(FALSE);
	}

	m_nCount = (WORD)::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0);

	TBBUTTON tbButton; memset(&tbButton, 0, sizeof(TBBUTTON));
	_GetButton(m_nCount - 1, &tbButton);
	tbButton.idCommand = -1;
	_SetButton(m_nCount - 1, &tbButton);

	CFrameWnd* pFrame = GetParentFrame();
	if (pFrame != NULL)
		pFrame->DelayRecalcLayout(FALSE); 

	return (CComboBox*)pComboBox;
}

BOOL CCommandBar::InsertMenuBar(WORD wMenuID, WORD wButton)
{
	return InsertMenuBarEx(MAKEINTRESOURCE(wMenuID), wButton);
}

BOOL CCommandBar::InsertMenuBarEx(LPTSTR pszMenu, WORD wButton)
{
	ASSERT(::IsWindow(m_hWnd));

	HMENU hMenu = NULL;

	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel == PocketPC || aygshellUIModel == Smartphone)
	{
		CWnd *pParentWnd = GetParent();
		ASSERT(pParentWnd != NULL);  

		DestroyWindow();

		HINSTANCE hInstance = AfxGetResourceHandle();
		ASSERT(hInstance != NULL);

		SHMENUBARINFO mbi;
		ZeroMemory(&mbi, sizeof(SHMENUBARINFO));

		mbi.cbSize     = sizeof(SHMENUBARINFO);
		mbi.hwndParent = pParentWnd->GetSafeHwnd();
		mbi.nToolBarId = (int)pszMenu;
		mbi.hInstRes   = hInstance; 

		HRSRC hRsrc = NULL;
		if ((hRsrc = ::FindResource(hInstance, pszMenu, RT_RCDATA)) == NULL)
		{
			mbi.dwFlags |= SHCMBF_HMENU;
		}

		if (!AYGSHELL::SHCreateMenuBar(&mbi))
		{
#ifdef _DEBUG
			if (hRsrc == NULL && aygshellUIModel == Smartphone)
			{
				OSVERSIONINFO osvi;
				ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
				osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
				::GetVersionEx(&osvi);

				ASSERT(osvi.dwPlatformId == VER_PLATFORM_WIN32_CE);

				if(osvi.dwMajorVersion < 5)
				{
					TRACE1("Warning: SHMENUBAR resource should be presented when targeting Smartphone 2003. GetLastError returns 0x%8.8X\n", GetLastError());
				}
			}
			else
			{
				TRACE1("Warning: Failed creating menu bar at the bottom of the window: GetLastError returns 0x%8.8X\n", GetLastError());
			}
#endif
			return FALSE;
		}
		
		// for MenuBar on Pocket PC and Smartphone, the menubar window is pointed to by mbi.hwndMB
		ASSERT(mbi.hwndMB != NULL);
		if (mbi.hwndMB == NULL)
		{
			return FALSE;
		}
		m_hCommandBar = mbi.hwndMB;

		// subclass and mimic CControlBar::OnCreate().
		VERIFY(SubclassWindow(mbi.hwndMB)); 
		if (pParentWnd->IsFrameWnd())
		{
			m_pDockSite = (CFrameWnd*)pParentWnd;
			m_pDockSite->AddControlBar(this);
			m_pDockSite->m_hCommandBar = mbi.hwndMB;
		}

		hMenu = ::LoadMenu(hInstance, pszMenu);
	}
	else
	{
		WORD nButtonCount = (WORD)::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0);
		ASSERT((wButton == CMDBAR_END) || ((wButton >=0) && (wButton <= nButtonCount)));

		wButton = (wButton == nButtonCount) ? nButtonCount - 1 : wButton;

		HINSTANCE hInstance = AfxFindResourceHandle(pszMenu, RT_MENU);
		ASSERT(hInstance != NULL);

		if (!::CommandBar_InsertMenubarEx(m_hWnd, hInstance, (LPTSTR)pszMenu, wButton))
		{
			return FALSE;
		}

		nButtonCount = (WORD)::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0);
		wButton = (wButton == CMDBAR_END) ? nButtonCount - 1 : wButton;
	
		hMenu = ::CommandBar_GetMenu(m_hWnd, wButton);
		ASSERT((hMenu != NULL) && ::IsMenu(hMenu));

		nButtonCount = (WORD)::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0);

		// expectcustom controls to have their idcommand set to -1
		TBBUTTON tbButton; memset(&tbButton, 0, sizeof(TBBUTTON));
		_GetButton(nButtonCount - 1, &tbButton);
		tbButton.idCommand = -1;
		_SetButton(nButtonCount - 1, &tbButton);
	}

	m_pMenu = new CMenu;
	if (m_pMenu != NULL)
	{
		m_pMenu->Attach(hMenu);
	}

	CFrameWnd* pFrameWnd = GetParentFrame();
	if (pFrameWnd != NULL)
	{
		if (pFrameWnd->GetMenu() == NULL)
		{
			// set the frame window's m_hMenu so it can service CWnd::GetMenu()
			::SetMenu(pFrameWnd->m_hWnd, hMenu);
		}
		pFrameWnd->DelayRecalcLayout(FALSE);
	}

	return TRUE;
}

BOOL CCommandBar::InsertSeparator(int nWidth, WORD wButton)
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(nWidth > 0);

	WORD nButtonCount = (WORD)::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0);
	ASSERT((wButton == CMDBAR_END) || ((wButton >=0) && (wButton <= nButtonCount)));

	wButton = (wButton == nButtonCount) ? CMDBAR_END : wButton;

	TBBUTTON tbButton = {nWidth, 0, TBSTATE_ENABLED, TBSTYLE_SEP, 0, 0, 0, 0};
	BOOL bResult = DefWindowProc(TB_INSERTBUTTON, wButton, (LPARAM)&tbButton);
	
	// update based on the most recent change
	m_nCount = (WORD)::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0);

	CFrameWnd* pFrameWnd = GetParentFrame();
	if(pFrameWnd != NULL)
		pFrameWnd->DelayRecalcLayout(FALSE); 

	return bResult;
}

#ifndef _WIN32_WCE_NO_TOOLTIPS
INT_PTR CCommandBar::OnToolHitTest(CPoint point, TOOLINFO* pTI) const
{
	ASSERT(::IsWindow(m_hWnd));

	HWND hWndChild = _AfxChildWindowFromPoint(m_hWnd, point);
	CWnd* pWnd = CWnd::FromHandlePermanent(hWndChild);
	if (pWnd == NULL)
		return CToolBar::OnToolHitTest(point, pTI);

	ASSERT(pWnd->m_hWnd == hWndChild);
	return pWnd->OnToolHitTest(point, pTI);
}
#endif // !_WIN32_WCE_NO_TOOLTIPS

CSize CCommandBar::CalcFixedLayout(BOOL bStretch, BOOL bHorz)
{
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel != PocketPC && aygshellUIModel != Smartphone)
	{
		return CToolBar::CalcFixedLayout(bStretch, bHorz);
	}
	
	ASSERT(::IsWindow(m_hWnd));
	return CSize(0, 0);
}

CSize CCommandBar::CalcDynamicLayout(int nLength, DWORD dwMode)
{
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel != PocketPC && aygshellUIModel != Smartphone)
	{
		return CToolBar::CalcDynamicLayout(nLength, dwMode);
	}
	
	ASSERT(::IsWindow(m_hWnd));
	return CSize(0, 0);
}

#ifdef AFX_INIT_SEG
#pragma code_seg(AFX_INIT_SEG)
#endif

IMPLEMENT_DYNAMIC(CCommandBar, CToolBar)

/////////////////////////////////////////////////////////////////////////////
#endif // _WIN32_WCE

