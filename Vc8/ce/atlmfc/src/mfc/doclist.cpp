// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1999 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"

#ifdef _WIN32_WCE_DOCLIST_SUPPORT

#ifdef AFX_AUX_SEG
#pragma code_seg(AFX_AUX_SEG)
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define new DEBUG_NEW

////////////////////////////////////////////////////////////////////////////
// CDocList
CDocList::CDocList()
	: m_pDocTemplate(NULL)
{
}

CDocList::CDocList(CDocListDocTemplate* pDocTemplate) 
	: m_pDocTemplate(pDocTemplate)
{
}

CDocList::~CDocList() 
{ 
	if (::IsWindow(m_hWnd))
		OnClose();
}

BEGIN_MESSAGE_MAP(CDocList, CWnd)
	ON_NOTIFY_REFLECT(DLN_ITEMACTIVATED, &CDocList::OnItemActivated)
END_MESSAGE_MAP()


BOOL CDocList::Create(CWnd* pParentWnd, LPCTSTR lpszFilterList, LPCTSTR lpszFolder, DWORD dwFlags)
{
	ASSERT(m_hWnd == NULL);

	// setup initial folder name
	m_strFolder = lpszFolder;

	memset(&m_dlc, 0, sizeof(m_dlc)); // initialize structure to 0
	m_dlc.dwStructSize = sizeof(m_dlc);
	m_dlc.pszFolder    = (LPCTSTR)m_strFolder;
	m_dlc.wFilterIndex = 1;
	m_dlc.dwFlags      = dwFlags;
	m_dlc.wId          = AFX_ID_DOCLIST;

	// Translate filter list into commdlg format (lots of \0)
	if (lpszFilterList != NULL)
	{
		m_strFilterList.LoadString(AFX_IDS_INTL_ALLFILES);
		m_strFilterList += lpszFilterList;
		
		LPTSTR pch = m_strFilterList.GetBuffer(0); // modify the buffer in place
		// MFC delimits with '|' not '\0'
		while ((pch = _tcschr(pch, '|')) != NULL)
			*pch++ = '\0';
		m_dlc.pstrFilter = m_strFilterList;
		// do not call ReleaseBuffer() since the string contains '\0' characters
	}

	m_dlc.hwndParent = pParentWnd->GetSafeHwnd();
	if (m_dlc.hwndParent == NULL)
	{
#ifdef _DEBUG
		TRACE0("Warning: DocList creation failed: needs a parent window.");
#endif
		return FALSE;
	}

	HWND hWndDocList = NULL;
	HINSTANCE hDocListDLL = ::LoadLibrary(_T("DOCLIST.DLL"));
	if (hDocListDLL != NULL)
	{
		typedef HWND (__cdecl * DOCLISTCREATE)(PDOCLISTCREATE);
		DOCLISTCREATE pfnDocListCreate = 
			(DOCLISTCREATE)::GetProcAddress(hDocListDLL, _T("DocList_Create"));
		if (pfnDocListCreate != NULL)
		{
			hWndDocList = (*pfnDocListCreate)(&m_dlc);
		}
	}
	if (hWndDocList == NULL)
	{
		return FALSE;
	}

	VERIFY(Attach(hWndDocList)); 

	OnCreate(); // the doclist control doesn't like to be subclassed, so we call it manually

	return TRUE;
}

HRESULT CDocList::Refresh()
{
	ASSERT(::IsWindow(m_hWnd));
	return ::SendMessage(m_hWnd, DLM_REFRESH, 0, 0L);
}

HRESULT CDocList::Update()
{
	ASSERT(::IsWindow(m_hWnd));
	return ::SendMessage(m_hWnd, DLM_UPDATE, 0, 0L);
}

void CDocList::DisableUpdate()
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, DLM_DISABLEUPDATES, 0, 0L);
}

void CDocList::EnableUpdate()
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, DLM_ENABLEUPDATES, 0, 0L);
}

BOOL CDocList::SetSortOrder()
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)::SendMessage(m_hWnd, DLM_SETSORTORDER, 0, 0L);
}

HRESULT CDocList::SetFilterIndex(int nIndex)
{
	ASSERT(::IsWindow(m_hWnd));
	return ::SendMessage(m_hWnd, DLM_SETFILTERINDEX, (WPARAM)nIndex, 0L);
}

int CDocList::GetFilterIndex()
{
	ASSERT(::IsWindow(m_hWnd));
	return (int)::SendMessage(m_hWnd, DLM_GETFILTERINDEX, 0, 0L);
}

BOOL CDocList::GetSelectedPathname(LPTSTR pszPath, WORD nSize)
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)::SendMessage(m_hWnd, DLM_GETSELPATHNAME, (WPARAM) nSize, (LPARAM) pszPath);
}

void CDocList::SetSelectedPathname(LPTSTR pszPath)
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, DLM_SETSELPATHNAME, 0, (LPARAM) pszPath);
}

HRESULT CDocList::SelectItem(LPTSTR pszPath, BOOL fVisible)
{
	ASSERT(::IsWindow(m_hWnd));
	return ::SendMessage(m_hWnd, DLM_SELECTITEM, (WPARAM) fVisible, (LPARAM) pszPath);
}

void CDocList::SetSelection(int wItem)
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, DLM_SETSELECT, (WPARAM) wItem, 0L);
}

HRESULT CDocList::DeleteSelection() 
{
	ASSERT(::IsWindow(m_hWnd));
	return ::SendMessage(m_hWnd, DLM_DELETESEL, 0, 0L);
}

void CDocList::SetOneItem(int nItem, PAstruct *pPA)
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, DLM_SETONEITEM, (WPARAM) nItem, (LPARAM) pPA);
}

void CDocList::SetFolder(LPTSTR pszFolder)
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, DLM_SETFOLDER, 0, (LPARAM) pszFolder);
}

int CDocList::GetSelectCount()
{
	ASSERT(::IsWindow(m_hWnd));
	return (int)::SendMessage(m_hWnd, DLM_GETSELCOUNT, 0, 0L);
}

BOOL CDocList::GetNextWaveFile(int *pnItem)
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)::SendMessage(m_hWnd, DLM_GETNEXTWAVE, 0, (LPARAM) pnItem);
}

BOOL CDocList::GetPrevWaveFile(int *pnItem)
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)::SendMessage(m_hWnd, DLM_GETPREVWAVE, 0, (LPARAM) pnItem);
}

BOOL CDocList::RenameMoveSelectedItems()
{
	ASSERT(::IsWindow(m_hWnd));
	return (BOOL)::SendMessage(m_hWnd, DLM_RENAMEMOVE, 0, 0);
}

void CDocList::SendIR(LPTSTR pszPath)
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, DLM_SENDIR, 0, (LPARAM) pszPath);
}

void CDocList::ReceiveIR(LPTSTR pszPath)
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, DLM_RECEIVEIR, 0, (LPARAM) pszPath);
}

void CDocList::SendEMail(LPTSTR pszPath)
{
	ASSERT(::IsWindow(m_hWnd));
	::SendMessage(m_hWnd, DLM_SENDEMAIL, 0, (LPARAM) pszPath);
}

int CDocList::GetItemCount()
{
	ASSERT(::IsWindow(m_hWnd));
	return (int)::SendMessage(m_hWnd, DLM_GETITEMCOUNT, 0, 0L);
}

int CDocList::GetNextItem(int nStart, UINT nFlags)
{
	ASSERT(::IsWindow(m_hWnd));
	return (int)::SendMessage(m_hWnd, DLM_GETNEXTITEM, (WPARAM) nStart, MAKELPARAM(nFlags, 0));
}

BOOL CDocList::SetItemState(int nItem, UINT nState, UINT nStateMask)
{
	ASSERT(::IsWindow(m_hWnd));
	LV_ITEM _ms_lvi;
	_ms_lvi.stateMask = nStateMask;
	_ms_lvi.state = nState;
	return (BOOL)::SendMessage(m_hWnd, DLM_SETITEMSTATE, (WPARAM)nItem, 
		(LPARAM)(LV_ITEM FAR *) &_ms_lvi);
}

void CDocList::OnCreate()
{
	SetDlgCtrlID(AFX_ID_DOCLIST);
	CWnd* pOwner = GetParent();
	if(pOwner != NULL)
	{
		DLNHDR dlhmhdr = {{m_hWnd, m_dlc.wId, DLN_DOCLIST_CREATE}, 0, NULL};
		ASSERT(::IsWindow(pOwner->m_hWnd));
		::SendMessage(pOwner->m_hWnd, WM_NOTIFY, DLN_DOCLIST_CREATE, (LPARAM)&dlhmhdr);
	}
}

void CDocList::OnClose()
{
	CWnd* pOwner = GetParent();
	if(pOwner != NULL)
	{
		DLNHDR dlhmhdr = {{m_hWnd, m_dlc.wId, DLN_DOCLIST_DESTROY}, 0, NULL};
		ASSERT(::IsWindow(pOwner->m_hWnd));
		::SendMessage(pOwner->m_hWnd, WM_NOTIFY, DLN_DOCLIST_DESTROY, (LPARAM)&dlhmhdr);
	}

	::DestroyWindow(Detach());
}


BEGIN_MESSAGE_MAP(CDocListCommandBar, CCommandBar)
	ON_COMMAND(ID_FILE_NEW, &CDocListCommandBar::OnSharedNew)
END_MESSAGE_MAP()

void CDocListCommandBar::OnSharedNew()
{
	CWinApp* pApp = AfxGetApp();
	if (pApp != NULL)
	{
		CWnd *pWndApp = pApp->GetMainWnd();
		ASSERT(::IsWindow(pWndApp->m_hWnd));
		pWndApp->PostMessage(WM_COMMAND, ID_FILE_NEW);

		ASSERT(m_pWndDocList != NULL);
		m_pWndDocList->OnClose();
	}
}

BOOL CDocListCommandBar::OnCmdMsg( UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo )
{
	CWinApp* pApp = AfxGetApp();
	if (pApp == NULL)
		return FALSE;

	CWnd *pWndApp = pApp->GetMainWnd();
	ASSERT(::IsWindow(pWndApp->m_hWnd));

	// If the object(s) in the extended command route don't handle
	// the command, then let the base class OnCmdMsg handle it.
	return CCommandBar::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CDocList::OnItemActivated(DLNHDR* pNotify, LRESULT*)
{
	CWinApp* pApp = AfxGetApp();
	if (pApp == NULL)
		return;
	
	if(pApp->OpenDocumentFile(pNotify->pszPath) != NULL)
	{
		// Only dismiss the DocList if the open was successful
		OnClose();
	}
}

#ifdef AFX_INIT_SEG
#pragma code_seg(AFX_INIT_SEG)
#endif

IMPLEMENT_DYNAMIC(CDocList, CWnd)
IMPLEMENT_DYNAMIC(CDocListCommandBar, CCommandBar)

#endif // _WIN32_WCE_DOCLIST_SUPPORT

