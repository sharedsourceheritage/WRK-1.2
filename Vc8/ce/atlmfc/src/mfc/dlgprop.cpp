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

#ifdef _WIN32_WCE

struct DlgTemplateSwap
{
	LPDLGTEMPLATE pClonedDlgTemplate;
	LPCDLGTEMPLATE pOldDlgTemplate;
};

inline LPWSTR SkipThisSz(LPWSTR pwsz)
{
	while (*pwsz++ != 0)
		;
	return pwsz;
}
 
LPWSTR SkipThisOrdinalOrSz(LPWSTR pwsz)
{
	// If first byte is 0xFF, next two bytes are ordinal name.
	if (*pwsz == 0xFFFF)
	{
		return (pwsz + 2);
	}
	else
	{
		// If string skip it
		return SkipThisSz(pwsz);
	}
}

bool _AfxCloneDialogTemplate(LPDLGTEMPLATE &rpClone, LPCDLGTEMPLATE pOriginal)
{
	// Start cloned code (cloned CE OS prpage.cpp)

	LPWSTR lpszMenu, lpszClass, lpszText;
	LPBYTE lpExtra, lpEnd, lpStart;
	WORD cDlgItmTmplts;
	WORD wExtraBytes;

	//  We need to calculate the size of the resource buffer that we 
	//  need to allocate and then copy into from pDlgTemplate.  Below
	//  we are doing pretty much the same thing that CreateDialogIndirect()
	//  does on this data.  This will ensure that we copy the right amount
	//  of data and pass it to CreateDialogIndirect() so that no AV's happen
	//  For details of whats going on, look at the implementation of 
	//  CreateDialogIndirect() in  private\winceos\coreos\gwe\dlgmrg\main\cmncore\loaddlg.cpp

	// NOTE - extended dialog templates are not currenlty supported on Windows CE;
	// however, if that should change in the future, this code will need to be updated
	// to handle extended dialog templates as well.

	lpStart = lpEnd = (LPBYTE)pOriginal;

	lpEnd += sizeof(DLGTEMPLATE);

	lpszMenu = (LPWSTR)lpEnd;
	// Skip over menu name.
	lpszClass = SkipThisOrdinalOrSz(lpszMenu);
	// Skip class string.
	lpszText = SkipThisOrdinalOrSz(lpszClass);
	// Skip over caption string.
	lpEnd = (LPBYTE)SkipThisSz(lpszText);

	if ( pOriginal->style & DS_SETFONT )
	{
		lpEnd = (LPBYTE)SkipThisSz(((LPWSTR)lpEnd)+1);
	}

	cDlgItmTmplts = pOriginal->cdit;
	while (cDlgItmTmplts-- != 0)
	{
		// align lpEnd on a DWORD boundary
		if ((DWORD)lpEnd%4)
		{
			lpEnd+=2;
		}
		lpEnd += sizeof(DLGITEMTEMPLATE);

		lpszClass = (LPWSTR)lpEnd;
		if (*lpszClass==0xFFFF)
		{
			lpszText = lpszClass + 2;
		}
		else
		{
			lpszText = SkipThisSz(lpszClass);
		}

		lpExtra = (LPBYTE)SkipThisOrdinalOrSz(lpszText);
		wExtraBytes = *((WORD*) lpExtra) + sizeof(WORD);
		lpEnd = lpExtra + wExtraBytes;
	}

	size_t cbTemplate = lpEnd - lpStart; 

	// End cloned code
	
	// Allocate the appropriate amount of memory.
	rpClone = reinterpret_cast<LPDLGTEMPLATE>(new char[cbTemplate]);
	if(rpClone == NULL)
	{
		return false;
	}

	// Copy the contents
	Checked::memcpy_s(rpClone, cbTemplate, pOriginal, cbTemplate);
	
	return true;
}

static bool _AfxCommCtrlDlgTemplateHackRequired()
{
	OSVERSIONINFO osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	::GetVersionEx(&osvi);

	ASSERT(osvi.dwPlatformId == VER_PLATFORM_WIN32_CE);

	// Required for OS version less then 5.01
	if(osvi.dwMajorVersion < 5 || (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion < 1))
	{
		return true;
	}

	return false;
}

static HPROPSHEETPAGE AfxCreatePropertySheetPage2(LPPROPSHEETPAGEW lppsp)
{
	HPROPSHEETPAGE hpspRet = NULL;
	
	DlgTemplateSwap dlgTemplateSwap = { NULL, NULL };
	
	bool bHack = _AfxCommCtrlDlgTemplateHackRequired(); 

	if(bHack)
	{
		dlgTemplateSwap.pOldDlgTemplate = lppsp->pResource;
		
		// dlgTemplateSwap.pClonedDlgTemplate will be allocated via new so it must be deleted
		if(!_AfxCloneDialogTemplate(dlgTemplateSwap.pClonedDlgTemplate, dlgTemplateSwap.pOldDlgTemplate))
		{
			// Failed to clone template, bail
			return hpspRet;
		}

		lppsp->pResource = dlgTemplateSwap.pClonedDlgTemplate;

		// This forces the dialog for the page to be created immediatley, so that the necessary
		// lifetime of the copy is well understood.  We just leave the flag on after the call,
		// as there is no harm in it (the property sheet is owned by CPropertySheet).
		lppsp->dwFlags |= PSP_PREMATURE;
	}

	hpspRet = AfxCreatePropertySheetPage(lppsp);

	return hpspRet;
}

static INT_PTR AfxPropertySheet2(LPPROPSHEETHEADERW lppsph)
{
	unsigned int nAllocated = 0;
	INT_PTR piRet = -1; // Indicates error
	
	DlgTemplateSwap *pDlgTemplateSwap = NULL;

	bool bHack = _AfxCommCtrlDlgTemplateHackRequired();
	
	if(bHack)
	{
		pDlgTemplateSwap = new DlgTemplateSwap[lppsph->nPages];
		
		if(pDlgTemplateSwap == NULL)
		{
			return piRet;
		}
		
		for(unsigned int i = 0; i < lppsph->nPages; ++i)
		{
			// Clone the dialog template into process specific R/W heap memory
			// instead of R/O memery shared across processes (what LoadResource/LockResource return)
			if(lppsph->ppsp[i].pResource != NULL)
			{
				pDlgTemplateSwap[i].pOldDlgTemplate = lppsph->ppsp[i].pResource;

				// pDlgTemplateSwap[i].pClonedDlgTemplate will be allocated via new so it must be deleted
				if(!_AfxCloneDialogTemplate(pDlgTemplateSwap[i].pClonedDlgTemplate, pDlgTemplateSwap[i].pOldDlgTemplate))
				{
					return piRet;
				}
				
				++nAllocated;

				LPPROPSHEETPAGEW pPropSheet = const_cast<LPPROPSHEETPAGEW>(lppsph->ppsp + i);
				
				pPropSheet->pResource = pDlgTemplateSwap[i].pClonedDlgTemplate;

				// This forces the dialog for the page to be created immediatley, so that the necessary
				// lifetime of the copy is well understood.  We just leave the flag on after the call,
				// as there is no harm in it (the property sheet is owned by CPropertySheet).
				pPropSheet->dwFlags |= PSP_PREMATURE;
			}
		}
	}

	// PropertySheet will modify values on the dialog templates, so they must be in non-shared R/W memory
	piRet = AfxPropertySheet(lppsph);

	return piRet;
}

#else // _WIN32_WCE
#define AfxCreatePropertySheetPage2 AfxCreatePropertySheetPage
#define AfxPropertySheet2 AfxPropertySheet
#endif // _WIN32_WCE

////////////////////////////////////////////////////////////////////////////
// CPropertyPage -- one page of a tabbed dialog

UINT CALLBACK
AfxPropPageCallback(HWND, UINT message, PROPSHEETPAGE* pPropPage)
{
	switch (message)
	{
	case PSPCB_CREATE:
		{
			ASSERT(AfxIsValidAddress(pPropPage, pPropPage->dwSize));
			CPropertyPage* pPage =
				STATIC_DOWNCAST(CPropertyPage, (CObject*)pPropPage->lParam);
			ASSERT_VALID(pPage);
			TRY
			{
				AfxHookWindowCreate(pPage);
			}
			CATCH_ALL(e)
			{
				// Note: DELETE_EXCEPTION(e) not necessary
				return FALSE;
			}
			END_CATCH_ALL
		}
		return TRUE;

	case PSPCB_RELEASE:
		AfxUnhookWindowCreate();
		break;
	}

	return 0;
}

BEGIN_MESSAGE_MAP(CPropertyPage, CDialog)
	//{{AFX_MSG_MAP(CPropertyPage)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


const PROPSHEETPAGE& CPropertyPage::GetPSP() const
{
	return *m_pPSP;
}

PROPSHEETPAGE& CPropertyPage::GetPSP()
{
	return *m_pPSP;
}

void CPropertyPage::AllocPSP(DWORD dwSize)
{
	if (dwSize == 0)
	{
		dwSize = sizeof(PROPSHEETPAGE);
	}

	// size of PROPSHEETPAGE must be at least version 4
#ifndef _WIN32_WCE // PROPSHEETPAGE_V2_SIZE
	ASSERT(dwSize >= PROPSHEETPAGE_V2_SIZE);
#endif // !_WIN32_WCE
	// allocate memory for PROPSHEETPAGE struct based on size passed in
	m_pPSP = static_cast<LPPROPSHEETPAGE>(malloc(dwSize));
	ASSERT(m_pPSP != NULL);
	if (m_pPSP == NULL)
		AfxThrowMemoryException();

	memset(m_pPSP,0,dwSize);
	m_pPSP->dwSize = dwSize;
}

// simple construction

CPropertyPage::CPropertyPage(UINT nIDTemplate, UINT nIDCaption, DWORD dwSize)
{
	ASSERT(nIDTemplate != 0);
	AllocPSP(dwSize);
	CommonConstruct(MAKEINTRESOURCE(nIDTemplate), nIDCaption);
}

CPropertyPage::CPropertyPage(LPCTSTR lpszTemplateName, UINT nIDCaption, DWORD dwSize)
{
	ENSURE_ARG(AfxIsValidString(lpszTemplateName));
	AllocPSP(dwSize);
	CommonConstruct(lpszTemplateName, nIDCaption);
}

void CPropertyPage::Construct(UINT nIDTemplate, UINT nIDCaption)
{
	ASSERT(nIDTemplate != 0);
	CommonConstruct(MAKEINTRESOURCE(nIDTemplate), nIDCaption);
}

void CPropertyPage::Construct(LPCTSTR lpszTemplateName, UINT nIDCaption)
{
	ENSURE_ARG(IS_INTRESOURCE(lpszTemplateName) ||
		AfxIsValidString(lpszTemplateName));
	CommonConstruct(lpszTemplateName, nIDCaption);
}

CPropertyPage::CPropertyPage()
{
	AllocPSP(0);
	CommonConstruct(NULL, 0);
}

void CPropertyPage::CommonConstruct(LPCTSTR lpszTemplateName, UINT nIDCaption)
{
	m_psp.dwFlags = PSP_USECALLBACK;
	if (lpszTemplateName != NULL)
		m_psp.hInstance = AfxFindResourceHandle(lpszTemplateName, RT_DIALOG);
	m_psp.pszTemplate = lpszTemplateName;
#ifndef _WIN32_WCE
	m_psp.pfnDlgProc = AfxDlgProc;
#else
	m_psp.pfnDlgProc = AfxDlgProcEx;
#endif // !_WIN32_WCE
	m_psp.lParam = (LPARAM)this;
	m_psp.pfnCallback = AfxPropPageCallback;
	if (nIDCaption != 0)
	{
		VERIFY(m_strCaption.LoadString(nIDCaption));
		m_psp.pszTitle = m_strCaption;
		m_psp.dwFlags |= PSP_USETITLE;
	}
	if (AfxHelpEnabled())
		m_psp.dwFlags |= PSP_HASHELP;
	if (IS_INTRESOURCE(lpszTemplateName))
		m_nIDHelp = LOWORD((DWORD_PTR)lpszTemplateName);
	m_lpszTemplateName = m_psp.pszTemplate;
	m_bFirstSetActive = TRUE;
}

CPropertyPage::CPropertyPage(UINT nIDTemplate, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle, DWORD dwSize)
{
	ASSERT(nIDTemplate != 0);
	AllocPSP(dwSize);
	CommonConstruct(MAKEINTRESOURCE(nIDTemplate), nIDCaption, nIDHeaderTitle, nIDHeaderSubTitle);
}

CPropertyPage::CPropertyPage(LPCTSTR lpszTemplateName, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle, DWORD dwSize)
{
	ASSERT(AfxIsValidString(lpszTemplateName));
	AllocPSP(dwSize);
	CommonConstruct(lpszTemplateName, nIDCaption, nIDHeaderTitle, nIDHeaderSubTitle);
}

void CPropertyPage::Construct(UINT nIDTemplate, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle)
{
	ASSERT(nIDTemplate != 0);
	CommonConstruct(MAKEINTRESOURCE(nIDTemplate), nIDCaption, nIDHeaderTitle, nIDHeaderSubTitle);
}

void CPropertyPage::Construct(LPCTSTR lpszTemplateName, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle)
{
	ENSURE_ARG(HIWORD(lpszTemplateName) == 0 ||
		AfxIsValidString(lpszTemplateName));
	CommonConstruct(lpszTemplateName, nIDCaption, nIDHeaderTitle, nIDHeaderSubTitle);
}

void CPropertyPage::CommonConstruct(LPCTSTR lpszTemplateName, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle)
{
	CommonConstruct(lpszTemplateName, nIDCaption);

	if (nIDHeaderTitle != 0)
	{
		VERIFY(m_strHeaderTitle.LoadString(nIDHeaderTitle));
	}

	if (nIDHeaderSubTitle != 0)
	{
		VERIFY(m_strHeaderSubTitle.LoadString(nIDHeaderSubTitle));
	}
}


CPropertyPage::~CPropertyPage()
{
	free(m_pPSP);
#ifndef _AFX_NO_OCC_SUPPORT
	Cleanup();
#endif

	if (m_hDialogTemplate != NULL)
		GlobalFree(m_hDialogTemplate);
}

#ifndef _AFX_NO_OCC_SUPPORT

void CPropertyPage::Cleanup()
{
	COccManager* pOccManager = afxOccManager;
	if ((pOccManager != NULL) && (m_pOccDialogInfo != NULL))
	{
		pOccManager->PostCreateDialog(m_pOccDialogInfo);
		free(m_pOccDialogInfo);
		m_pOccDialogInfo = NULL;
	}
}

AFX_STATIC DLGTEMPLATE* AFXAPI
_AfxChangePropPageFont(const DLGTEMPLATE* pTemplate, BOOL bWizard)
{
	CString strFaceDefault;
	WORD wSizeDefault;

	if (!AfxGetPropSheetFont(strFaceDefault, wSizeDefault, bWizard))
		return NULL;

	// set font of property page to same font used by property sheet
	CString strFace;
	WORD wSize;
	if ((!CDialogTemplate::GetFont(pTemplate, strFace, wSize)) ||
		(strFace != strFaceDefault) || (wSize != wSizeDefault))
	{
		CDialogTemplate dlgTemplate(pTemplate);
		dlgTemplate.SetFont(strFaceDefault, wSizeDefault);
		return (DLGTEMPLATE*)dlgTemplate.Detach();
	}

	return NULL;
}

const DLGTEMPLATE* CPropertyPage::InitDialogInfo(const DLGTEMPLATE* pTemplate)
{
	// cleanup from previous run, if any
	Cleanup();

	m_pOccDialogInfo = (_AFX_OCC_DIALOG_INFO*)malloc(
		sizeof(_AFX_OCC_DIALOG_INFO));

	return afxOccManager->PreCreateDialog(m_pOccDialogInfo, pTemplate);
}

#endif

void CPropertyPage::PreProcessPageTemplate(PROPSHEETPAGE& psp, BOOL bWizard)
{
	const DLGTEMPLATE* pTemplate;

	if (psp.dwFlags & PSP_DLGINDIRECT)
	{
		pTemplate = psp.pResource;
	}
	else
	{
		HRSRC hResource = ::FindResource(psp.hInstance,	psp.pszTemplate, RT_DIALOG);
		if (hResource == NULL)
		{
			AfxThrowResourceException();
		}
		HGLOBAL hTemplate = LoadResource(psp.hInstance,	hResource);
		if (hTemplate == NULL)
		{
			AfxThrowResourceException();
		}
		pTemplate = (LPCDLGTEMPLATE)LockResource(hTemplate);
		if (pTemplate == NULL)
		{
			AfxThrowResourceException();
		}
	}

#ifndef _WIN32_WCE
#ifdef _DEBUG
	// Windows currently does not support DIALOGEX resources!
	// Assert that the template is *not* a DIALOGEX template.
	// DIALOGEX templates are not supported by the PropertySheet API.

	// To change a DIALOGEX template back to a DIALOG template,
	// remove the following:
	//  1. Extended styles on the dialog
	//  2. Help IDs on any control in the dialog
	//  3. Control IDs that are DWORDs
	//  4. Weight, italic, or charset attributes on the dialog's font

	if (((DLGTEMPLATEEX*)pTemplate)->signature == 0xFFFF)
	{
		// it's a DIALOGEX -- we'd better check
		DWORD dwVersion = ::GetVersion();
		if (dwVersion & 0x80000000)
		{
			// it's Win95 -- versions of COMCTL32.DLL that export
			// a function called DllGetVersion are okay

			HINSTANCE hInst = afxComCtlWrapper->GetModuleHandle();
			ASSERT(hInst != NULL);
			if (hInst != NULL)
			{
				FARPROC proc = GetProcAddress(hInst, _T("DllGetVersion"));
				if (proc == NULL)
					ASSERT(FALSE);
			}
		}
		else if (LOBYTE(LOWORD(dwVersion)) == 3)
		{
			// it's Windows NT 3.x; we have no hope of this working
			ASSERT(FALSE);
		}
	}
#endif // _DEBUG
#endif // !_WIN32_WCE

#ifndef _AFX_NO_OCC_SUPPORT
	// if the dialog could contain OLE controls, deal with them now
	if (afxOccManager != NULL)
		pTemplate = InitDialogInfo(pTemplate);
#endif

#ifndef _WIN32_WCE
	// set font of property page to same font used by property sheet
	HGLOBAL hTemplate = _AfxChangePropPageFont(pTemplate, bWizard);

	if (m_hDialogTemplate != NULL)
	{
		GlobalFree(m_hDialogTemplate);
		m_hDialogTemplate = NULL;
	}

	if (hTemplate != NULL)
	{
		pTemplate = (LPCDLGTEMPLATE)hTemplate;
		m_hDialogTemplate = hTemplate;
	}
#else
	(bWizard);
#endif // !_WIN32_WCE

	psp.pResource = pTemplate;
	psp.dwFlags |= PSP_DLGINDIRECT;
}

void CPropertyPage::CancelToClose()
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(GetParent() != NULL);

	GetParent()->SendMessage(PSM_CANCELTOCLOSE);
}

void CPropertyPage::SetModified(BOOL bChanged)
{
	if (m_hWnd == NULL) // allowed for backward compatibility
		return;

	ASSERT(::IsWindow(m_hWnd));
	ASSERT(GetParent() != NULL);

	CWnd* pParentWnd = GetParent();
	if (bChanged)
		pParentWnd->SendMessage(PSM_CHANGED, (WPARAM)m_hWnd);
	else
		pParentWnd->SendMessage(PSM_UNCHANGED, (WPARAM)m_hWnd);
}

LRESULT CPropertyPage::QuerySiblings(WPARAM wParam, LPARAM lParam)
{
	ASSERT(::IsWindow(m_hWnd));
	ASSERT(GetParent() != NULL);

	return GetParent()->SendMessage(PSM_QUERYSIBLINGS, wParam, lParam);
}

BOOL CPropertyPage::OnApply()
{
	ASSERT_VALID(this);

	OnOK();
	return TRUE;
}

void CPropertyPage::OnReset()
{
	ASSERT_VALID(this);

	OnCancel();
}

void CPropertyPage::OnOK()
{
	ASSERT_VALID(this);
}

void CPropertyPage::OnCancel()
{
	ASSERT_VALID(this);
}

BOOL CPropertyPage::OnSetActive()
{
	ASSERT_VALID(this);

	if (m_bFirstSetActive)
		m_bFirstSetActive = FALSE;
	else
		UpdateData(FALSE);
	return TRUE;
}

BOOL CPropertyPage::OnKillActive()
{
	ASSERT_VALID(this);

	if (!UpdateData())
	{
		TRACE(traceAppMsg, 0, _T("UpdateData failed during page deactivation\n"));
		return FALSE;
	}
	return TRUE;
}

BOOL CPropertyPage::OnQueryCancel()
{
	return TRUE;    // ok to cancel
}

#ifndef _WIN32_WCE
LRESULT CPropertyPage::OnWizardBack()
{
	return 0;
}

LRESULT CPropertyPage::OnWizardNext()
{
	return 0;
}

HWND CPropertyPage::OnWizardFinishEx()
{	
	//Reversing the return values from OnWizardFinish.
	return OnWizardFinish() ? (HWND)FALSE : (HWND)TRUE;
}


BOOL CPropertyPage::OnWizardFinish()
{
	BOOL bClose=FALSE;
	if (UpdateData())
	{
		CWnd* pParent = GetParent();
		CPropertySheet* pSheet = DYNAMIC_DOWNCAST(CPropertySheet, pParent);
		if (pSheet != NULL)
		{
			if (pSheet->IsModeless() && pSheet->IsWizard())
			{
				//Msg is posted so PreTranslateMessage of CPropertySheet is called
				//and it will immediatly DestoryWindow().
				pSheet->PostMessage(WM_NULL,0,0);
			}
		}
		bClose=TRUE;
	}
	return bClose;
}

LRESULT CPropertyPage::MapWizardResult(LRESULT lToMap)
{
	// -1 and 0 are special
	if (lToMap == -1 || lToMap == 0)
		return lToMap;

	// only do special stuff if MFC owns the property sheet
	CWnd* pParent = GetParent();
	CPropertySheet* pSheet = DYNAMIC_DOWNCAST(CPropertySheet, pParent);
	if (pSheet != NULL)
	{
		// search the pages for a matching ID
		const PROPSHEETPAGE* ppsp = pSheet->m_psh.ppsp;
		for (int i = 0; i < pSheet->m_pages.GetSize(); i++)
		{
			// check page[i] for a match
			CPropertyPage* pPage = pSheet->GetPage(i);
			if ((LRESULT)pPage->m_psp.pszTemplate == lToMap)
				return (LRESULT)ppsp->pResource;

			// jump to next page
			(BYTE*&)ppsp += ppsp->dwSize;
		}
	}
	// otherwise, just use the original value
	return lToMap;
}
#endif // !_WIN32_WCE

BOOL CPropertyPage::IsButtonEnabled(int iButton)
{
	HWND hWnd = ::GetDlgItem(::GetParent(m_hWnd), iButton);
	if (hWnd == NULL)
		return FALSE;
	return ::IsWindowEnabled(hWnd);
}

BOOL CPropertyPage::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	ASSERT(pResult != NULL);
	NMHDR* pNMHDR = (NMHDR*)lParam;

	// allow message map to override
	if (CDialog::OnNotify(wParam, lParam, pResult))
		return TRUE;

	// don't handle messages not from the page/sheet itself
	if (pNMHDR->hwndFrom != m_hWnd && pNMHDR->hwndFrom != ::GetParent(m_hWnd))
		return FALSE;

	// handle default
	switch (pNMHDR->code)
	{
	case PSN_SETACTIVE:
		{
			CPropertySheet* pSheet = DYNAMIC_DOWNCAST(CPropertySheet, GetParent());
			if (pSheet != NULL && !(pSheet->m_nFlags & WF_CONTINUEMODAL) && !(pSheet->m_bModeless))
				*pResult = -1;
			else
				*pResult = OnSetActive() ? 0 : -1;
		}
		break;
	case PSN_KILLACTIVE:
		*pResult = !OnKillActive();
		break;
	case PSN_APPLY:
		*pResult = OnApply() ? PSNRET_NOERROR : PSNRET_INVALID_NOCHANGEPAGE;
		break;
	case PSN_RESET:
		OnReset();
		break;
	case PSN_QUERYCANCEL:
		*pResult = !OnQueryCancel();
		break;
#ifndef _WIN32_WCE
	case PSN_WIZNEXT:
		// Win32 will send a PSN_WIZBACK even if the button is disabled.
		if (IsButtonEnabled(ID_WIZNEXT))
			*pResult = MapWizardResult(OnWizardNext());
		break;
	case PSN_WIZBACK:
		// Win32 will send a PSN_WIZBACK even if the button is disabled.
		if (IsButtonEnabled(ID_WIZBACK))
			*pResult = MapWizardResult(OnWizardBack());
		break;
	case PSN_WIZFINISH:
		*pResult = reinterpret_cast<LRESULT>(OnWizardFinishEx());		
		break;
#endif // !_WIN32_WCE
	case PSN_HELP:
		SendMessage(WM_COMMAND, ID_HELP);
		break;

	default:
		return FALSE;   // not handled
	}

	return TRUE;    // handled
}

/////////////////////////////////////////////////////////////////////////////
// CPropertyPage message Handlers

BOOL CPropertyPage::PreTranslateMessage(MSG* pMsg)
{
	VERIFY(!CWnd::PreTranslateMessage(pMsg));

	return FALSE;   // handled by CPropertySheet::PreTranslateMessage
}

HBRUSH CPropertyPage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	LRESULT lResult;
	if (pWnd->SendChildNotifyLastMsg(&lResult))
		return (HBRUSH)lResult;

	return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
}

/////////////////////////////////////////////////////////////////////////////
// CPropertyPage Diagnostics

#ifdef _DEBUG
void CPropertyPage::AssertValid() const
{
	CDialog::AssertValid();
	ASSERT(m_psp.dwFlags & PSP_USECALLBACK);
#ifndef _WIN32_WCE
	ASSERT(m_psp.pfnDlgProc == AfxDlgProc);
#else
	ASSERT(m_psp.pfnDlgProc == AfxDlgProcEx);
#endif // !_WIN32_WCE
	ASSERT(m_psp.lParam == (LPARAM)this);
}

#ifndef _WIN32_WCE
void CPropertyPage::Dump(CDumpContext& dc) const
{
	CDialog::Dump(dc);

	dc << "m_strCaption = " << m_strCaption << "\n";
	dc << "m_psp.dwFlags = " << m_psp.dwFlags << "\n";
}
#endif // !_WIN32_WCE
#endif //_DEBUG

void CPropertyPage::EndDialog(int nID)
{
	// Normally you shouldn't call EndDialog from a page. But in case it does
	// happen during error situations, call CPropertySheet::EndDialog instead.

	CPropertySheet* pParent = DYNAMIC_DOWNCAST(CPropertySheet, GetParent());
	if (pParent != NULL)
		pParent->EndDialog(nID);
}

/////////////////////////////////////////////////////////////////////////////
// CPropertySheet -- a tabbed "dialog" (really a popup-window)

BEGIN_MESSAGE_MAP(CPropertySheet, CWnd)
	//{{AFX_MSG_MAP(CPropertySheet)
	ON_WM_CTLCOLOR()
#ifndef _WIN32_WCE
	ON_WM_NCCREATE()
#endif // !_WIN32_WCE
	ON_MESSAGE(WM_INITDIALOG, &CPropertySheet::HandleInitDialog)
#ifndef _WIN32_WCE_NO_HELP_SUPPORT
	ON_MESSAGE(WM_COMMANDHELP,&CPropertySheet::OnCommandHelp)
#endif // !_WIN32_WCE_NO_HELP_SUPPORT
	ON_WM_CLOSE()
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(DM_SETDEFID, &CPropertySheet::OnSetDefID)
	ON_MESSAGE(WM_KICKIDLE,&CPropertySheet::OnKickIdle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

AFX_STATIC_DATA const int _afxPropSheetIDs[4] = { ID_WIZNEXT, ID_WIZFINISH, ID_WIZBACK, IDCANCEL };

LRESULT CPropertySheet::OnSetDefID(WPARAM wParam, LPARAM lParam)
{
	// A wrong or invalid ID may be passed in here.  If this is the case, then look for a valid one
	HWND hWndParam;
	if (IsWizard() &&
		(
			((hWndParam = ::GetDlgItem(m_hWnd, (int)wParam)) == NULL) ||
			!(::GetWindowLong(hWndParam, GWL_STYLE) & WS_VISIBLE) ||
			!::IsWindowEnabled(hWndParam)
		))
	{

		for (int i = 0; i < _countof(_afxPropSheetIDs); i++)
		{
			// find first button that is visible and  enabled
			HWND hWnd = ::GetDlgItem(m_hWnd, _afxPropSheetIDs[i]);
			if ((GetWindowLong(hWnd, GWL_STYLE) & WS_VISIBLE) &&
				::IsWindowEnabled(hWnd))
			{
				// focus could be incorrect as well in this case
				// so ... let's set it to the default button
				HWND hWndFocus = ::GetFocus();
				if (!::IsWindowEnabled(hWndFocus))
					::SetFocus(hWnd);
				return DefWindowProc(DM_SETDEFID, _afxPropSheetIDs[i], lParam);
			}
		}
	}
	return Default();
}

// simple construction

CPropertySheet::CPropertySheet()
{
	CommonConstruct(NULL, 0);
}

CPropertySheet::CPropertySheet(UINT nIDCaption, CWnd* pParentWnd,
	UINT iSelectPage)
{
	ASSERT(nIDCaption != 0);

	VERIFY(m_strCaption.LoadString(nIDCaption));
	CommonConstruct(pParentWnd, iSelectPage);
}

CPropertySheet::CPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd,
	UINT iSelectPage)
{
	ENSURE_ARG(AfxIsValidString(pszCaption));

	m_strCaption = pszCaption;
	CommonConstruct(pParentWnd, iSelectPage);
}

void CPropertySheet::Construct(UINT nIDCaption, CWnd* pParentWnd,
	UINT iSelectPage)
{
	ASSERT(nIDCaption != 0);

	VERIFY(m_strCaption.LoadString(nIDCaption));
	CommonConstruct(pParentWnd, iSelectPage);
}

void CPropertySheet::Construct(LPCTSTR pszCaption, CWnd* pParentWnd,
	UINT iSelectPage)
{
	ENSURE_ARG(AfxIsValidString(pszCaption));

	m_strCaption = pszCaption;
	CommonConstruct(pParentWnd, iSelectPage);
}

void CPropertySheet::CommonConstruct(CWnd* pParentWnd, UINT iSelectPage)
{
	memset(&m_psh, 0, sizeof(m_psh));
	m_psh.dwSize = sizeof(m_psh);
#ifndef _WIN32_WCE
	m_psh.dwFlags = PSH_PROPSHEETPAGE;
#else
	m_psh.dwFlags = PSH_PROPSHEETPAGE | PSH_NOAPPLYNOW;
#endif // !_WIN32_WCE
#ifdef _WIN32_WCE
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel == PocketPC)
	{
		int CALLBACK AfxPropSheetCallback(HWND hwndDlg, UINT message, LPARAM lParam);
		m_psh.dwFlags |= PSH_USECALLBACK;
		m_psh.dwFlags |= PSH_MAXIMIZE;
		m_psh.pfnCallback = AfxPropSheetCallback;
	}
#endif // _WIN32_WCE
	m_psh.pszCaption = m_strCaption;
	m_psh.nStartPage = iSelectPage;
	m_bStacked = TRUE;
	m_bModeless = FALSE;

	if (AfxHelpEnabled())
		m_psh.dwFlags |= PSH_HASHELP;

	m_pParentWnd = pParentWnd;  // m_psh.hwndParent set in DoModal/create
}

CPropertySheet::CPropertySheet(UINT nIDCaption, CWnd* pParentWnd,
	UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark,
	HBITMAP hbmHeader)
{
	ASSERT(nIDCaption != 0);

	VERIFY(m_strCaption.LoadString(nIDCaption));
	CommonConstruct(pParentWnd, iSelectPage, hbmWatermark, hpalWatermark, hbmHeader);
}

CPropertySheet::CPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd,
	UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark,
	HBITMAP hbmHeader)
{
	ENSURE_ARG(AfxIsValidString(pszCaption));

	m_strCaption = pszCaption;
	CommonConstruct(pParentWnd, iSelectPage, hbmWatermark, hpalWatermark, hbmHeader);
}

void CPropertySheet::Construct(UINT nIDCaption, CWnd* pParentWnd,
	UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark,
	HBITMAP hbmHeader)
{
	ASSERT(nIDCaption != 0);

	VERIFY(m_strCaption.LoadString(nIDCaption));
	CommonConstruct(pParentWnd, iSelectPage, hbmWatermark, hpalWatermark, hbmHeader);
}

void CPropertySheet::Construct(LPCTSTR pszCaption, CWnd* pParentWnd,
	UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark,
	HBITMAP hbmHeader)
{
	ENSURE_ARG(AfxIsValidString(pszCaption));

	m_strCaption = pszCaption;
	CommonConstruct(pParentWnd, iSelectPage, hbmWatermark, hpalWatermark, hbmHeader);
}

void CPropertySheet::CommonConstruct(CWnd* pParentWnd, UINT iSelectPage,
	HBITMAP hbmWatermark, HPALETTE hpalWatermark, HBITMAP hbmHeader)
{
	CommonConstruct(pParentWnd, iSelectPage);

// hbmWatermark, hplWatermark and hbmHeader are not members of _PROPSHEETHEADERW
// undeclared identifer PSH_USEHBMWATERMARK, PSH_WATERMARK, PSH_USEHPLWATERMARK, PSH_USEHBMHEADER and PSH_HEADER
#ifndef _WIN32_WCE 
	if (hbmWatermark != NULL)
	{
		m_psh.hbmWatermark = hbmWatermark;
		m_psh.dwFlags |= (PSH_USEHBMWATERMARK | PSH_WATERMARK);
		m_psh.dwSize = sizeof(m_psh);
	}
	if (hpalWatermark != NULL)
	{
		m_psh.hplWatermark = hpalWatermark;
		m_psh.dwFlags |= PSH_USEHPLWATERMARK;
		m_psh.dwSize = sizeof(m_psh);
	}
	if (hbmHeader != NULL)
	{
		m_psh.hbmHeader = hbmHeader;
		m_psh.dwFlags |= (PSH_USEHBMHEADER | PSH_HEADER);
		m_psh.dwSize = sizeof(m_psh);
	}
#else
	(hbmWatermark, hpalWatermark, hbmHeader);
#endif // !_WIN32_WCE
}

void CPropertySheet::EnableStackedTabs(BOOL bStacked)
{
	m_bStacked = bStacked;
}

void CPropertySheet::SetTitle(LPCTSTR lpszText, UINT nStyle)
{
	ASSERT((nStyle & ~PSH_PROPTITLE) == 0); // only PSH_PROPTITLE is valid
	ASSERT(lpszText == NULL || AfxIsValidString(lpszText));

	if (m_hWnd == NULL)
	{
		// set internal state
		m_strCaption = lpszText;
		m_psh.pszCaption = m_strCaption;
		m_psh.dwFlags &= ~PSH_PROPTITLE;
		m_psh.dwFlags |= nStyle;
	}
	else
	{
		// set external state
		SendMessage(PSM_SETTITLE, nStyle, (LPARAM)lpszText);
	}
}

CPropertySheet::~CPropertySheet()
{
	free((void*)m_psh.ppsp);
}

BOOL CPropertySheet::PreTranslateMessage(MSG* pMsg)
{
	ASSERT_VALID(this);

	// allow tooltip messages to be filtered
	if (CWnd::PreTranslateMessage(pMsg))
		return TRUE;

	if (NULL == PropSheet_GetCurrentPageHwnd(m_hWnd))
	{		
		DestroyWindow();
		return TRUE;
	} 
	// allow sheet to translate Ctrl+Tab, Shift+Ctrl+Tab,
	//  Ctrl+PageUp, and Ctrl+PageDown
	if (pMsg->message == WM_KEYDOWN && GetAsyncKeyState(VK_CONTROL) < 0 &&
		(pMsg->wParam == VK_TAB || pMsg->wParam == VK_PRIOR || pMsg->wParam == VK_NEXT))
	{
		if (SendMessage(PSM_ISDIALOGMESSAGE, 0, (LPARAM)pMsg))
			return TRUE;
	}

	// handle rest with IsDialogMessage
	return PreTranslateInput(pMsg);
}

BOOL CPropertySheet::OnCmdMsg(UINT nID, int nCode, void* pExtra,
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

CPropertyPage* CPropertySheet::GetActivePage() const
{
	ASSERT_VALID(this);

	CPropertyPage* pPage;
	if (m_hWnd != NULL)
		pPage = STATIC_DOWNCAST(CPropertyPage,
			CWnd::FromHandle((HWND)::SendMessage(m_hWnd, PSM_GETCURRENTPAGEHWND, 0, 0)));
	else
		pPage = GetPage(GetActiveIndex());
	return pPage;
}

BOOL CPropertySheet::ContinueModal()
{
	// allow CWnd::EndModalLoop to be used
	if (!CWnd::ContinueModal())
		return FALSE;

	// when active page is NULL, the modal loop should end
	ASSERT(::IsWindow(m_hWnd));
	BOOL bResult = SendMessage(PSM_GETCURRENTPAGEHWND) != 0;
	return bResult;
}

INT_PTR CPropertySheet::DoModal()
{
	ASSERT_VALID(this);
	ASSERT(m_hWnd == NULL);

	// register common controls
	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTLS_REG));
#ifndef _WIN32_WCE
	AfxDeferRegisterClass(AFX_WNDCOMMCTLSNEW_REG);
#endif // !_WIN32_WCE

	// finish building PROPSHEETHEADER structure
	BuildPropPageArray();

	// allow OLE servers to disable themselves
	CWinApp* pApp = AfxGetApp();
	if (pApp != NULL)
		pApp->EnableModeless(FALSE);

	// find parent HWND
	HWND hWndTop;
	HWND hWndParent = CWnd::GetSafeOwner_(m_pParentWnd->GetSafeHwnd(), &hWndTop);
	m_psh.hwndParent = hWndParent;
	BOOL bEnableParent = FALSE;
	if (hWndParent != NULL && ::IsWindowEnabled(hWndParent))
	{
		::EnableWindow(hWndParent, FALSE);
		bEnableParent = TRUE;
	}
	HWND hWndCapture = ::GetCapture();
	if (hWndCapture != NULL)
		::SendMessage(hWndCapture, WM_CANCELMODE, 0, 0);

	// setup for modal loop and creation
	m_nModalResult = 0;
	m_nFlags |= WF_CONTINUEMODAL;

	// hook for creation of window
	AfxHookWindowCreate(this);
#ifdef _WIN32_WCE
	// tweak the m_pWndInit... we reserve that for the dialog pages.
	_AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
	pThreadState->m_pWndInitPropertySheet = pThreadState->m_pWndInit;
	pThreadState->m_pWndInit = NULL;	
#endif // _WIN32_WCE
	m_psh.dwFlags |= PSH_MODELESS;
	m_nFlags |= WF_CONTINUEMODAL;
	HWND hWnd = (HWND)::AfxPropertySheet2(&m_psh);
#ifdef _DEBUG
	DWORD dwError = ::GetLastError();
#endif
	m_psh.dwFlags &= ~PSH_MODELESS;
	AfxUnhookWindowCreate();

	// handle error
	if (hWnd == NULL || hWnd == (HWND)-1)
	{
#ifdef _DEBUG
		TRACE(traceAppMsg, 0, _T("PropertySheet() failed: GetLastError returned %d\n"), dwError);
#endif
		m_nFlags &= ~WF_CONTINUEMODAL;
	}

	INT_PTR nResult = m_nModalResult;
	if (ContinueModal())
	{
		// enter modal loop
		DWORD dwFlags = MLF_SHOWONIDLE;
		if (GetStyle() & DS_NOIDLEMSG)
			dwFlags |= MLF_NOIDLEMSG;
		nResult = RunModalLoop(dwFlags);
	}

	// hide the window before enabling parent window, etc.
	if (m_hWnd != NULL)
	{
		SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW|
			SWP_NOSIZE|SWP_NOMOVE|SWP_NOACTIVATE|SWP_NOZORDER);
	}
	if (bEnableParent)
		::EnableWindow(hWndParent, TRUE);
	if (hWndParent != NULL && ::GetActiveWindow() == m_hWnd)
		::SetActiveWindow(hWndParent);

	// cleanup
	DestroyWindow();

	// allow OLE servers to enable themselves
	if (pApp != NULL)
		pApp->EnableModeless(TRUE);
	if (hWndTop != NULL)
		::EnableWindow(hWndTop, TRUE);

	return nResult;
}

int CALLBACK
AfxPropSheetCallback(HWND hwndDlg, UINT message, LPARAM lParam)
{
#ifdef _WIN32_WCE
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel == PocketPC)
	{
		switch(message) 
		{
			case PSCB_INITIALIZED:
			{
				HWND hWnd = GetDlgItem(hwndDlg, AFX_IDC_TAB_CONTROL);
				DWORD dwStyle = GetWindowLong(hWnd, GWL_STYLE) | TCS_BOTTOM;
				::SetWindowLong(hWnd, GWL_STYLE, dwStyle);
				break;
			}
			
			case PSCB_GETVERSION:
				// Pocket PC applications that use property sheets should have the basic style and 
				// appearance of the latest platform. TO do so, one of the two requirements is that
				// PSH_MAXIMIZE must be specified as a flag in the dwFlags member of the
				// PROPSHEETHEADER structure, and the other is that the callback function must
				// return COMCTL32_VERSION when the uMsg parameter equals PSCB_GETVERSION
				return COMCTL32_VERSION;
				
			default:
				break;
		}
	}
	else
#endif // _WIN32_WCE
	{	
		switch (message)
		{
			case PSCB_PRECREATE:
			{
				_AFX_THREAD_STATE* pState = AfxGetThreadState();
				LPDLGTEMPLATE lpTemplate = (LPDLGTEMPLATE)lParam;
				if (lpTemplate->style != pState->m_dwPropStyle ||
					lpTemplate->dwExtendedStyle != pState->m_dwPropExStyle)
				{
// Windows CE ensures the template is in writeable memory, it must be copied, as it may be in ROM, 
// and can't be made writeable.  Any other callers must do the same on CE.
#ifndef _WIN32_WCE 	
					// Mark the dialog template as read-write.
					DWORD dwOldProtect;
					VirtualProtect(lpTemplate, sizeof(DLGTEMPLATE), PAGE_READWRITE, &dwOldProtect);
#endif

					// Ensure DS_SETFONT is set correctly.
					lpTemplate->style = lpTemplate->style & DS_SETFONT ?
									pState->m_dwPropStyle | DS_SETFONT :
									pState->m_dwPropStyle & ~DS_SETFONT;

					lpTemplate->dwExtendedStyle = pState->m_dwPropExStyle;
					return TRUE;
				}
				return FALSE;
			}
		}
	}

	return 0;
}

BOOL CPropertySheet::Create(CWnd* pParentWnd, DWORD dwStyle, DWORD dwExStyle)
{
	_AFX_THREAD_STATE* pState = AfxGetThreadState();

	// Calculate the default window style.
	if (dwStyle == (DWORD)-1)
	{
#ifndef _WIN32_WCE
		pState->m_dwPropStyle = DS_MODALFRAME | DS_3DLOOK | DS_CONTEXTHELP |
#else
		pState->m_dwPropStyle = DS_MODALFRAME | DS_3DLOOK | DS_CENTER |
#endif // _WIN32_WCE
					DS_SETFONT | WS_POPUP | WS_VISIBLE | WS_CAPTION;

#ifdef _WIN32_WCE
		int aygshellUIModel = AfxGetAygshellUIModel();
		if (aygshellUIModel == PocketPC)
		{
			// UI guidelines for PPC and SP state not to use 3D controls.
			pState->m_dwPropStyle &= ~DS_3DLOOK;
		}
#endif // _WIN32_WCE

		// Wizards don't have WS_SYSMENU.
		if (!IsWizard())
			pState->m_dwPropStyle |= WS_SYSMENU;
	}
	else
	{
		pState->m_dwPropStyle = dwStyle;
	}
	pState->m_dwPropExStyle = dwExStyle;

	ASSERT_VALID(this);
	ASSERT(m_hWnd == NULL);

	VERIFY(AfxDeferRegisterClass(AFX_WNDCOMMCTLS_REG));
#ifndef _WIN32_WCE
	AfxDeferRegisterClass(AFX_WNDCOMMCTLSNEW_REG);
#endif // !_WIN32_WCE

	// finish building PROPSHEETHEADER structure
	BuildPropPageArray();
	m_bModeless = TRUE;
	m_psh.dwFlags |= (PSH_MODELESS|PSH_USECALLBACK);
#ifdef _WIN32_WCE
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel != PocketPC)
	{
		m_psh.pfnCallback = NULL;
	}
	else
#endif // _WIN32_WCE
	{
		m_psh.pfnCallback = AfxPropSheetCallback;
	}

	m_psh.hwndParent = pParentWnd->GetSafeHwnd();

	// hook the window creation process
	AfxHookWindowCreate(this);
#ifdef _WIN32_WCE
	// tweak the m_pWndInit... we reserve that for the dialog pages.
	_AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
	pThreadState->m_pWndInitPropertySheet = pThreadState->m_pWndInit;
	pThreadState->m_pWndInit = NULL;	
#endif // _WIN32_WCE
	HWND hWnd = (HWND)AfxPropertySheet2(&m_psh);
#ifdef _DEBUG
	DWORD dwError = ::GetLastError();
#endif

	// cleanup on failure, otherwise return TRUE
	if (!AfxUnhookWindowCreate())
		PostNcDestroy();    // cleanup if Create fails

	if (hWnd == NULL || hWnd == (HWND)-1)
	{
#ifdef _DEBUG
		TRACE(traceAppMsg, 0, _T("PropertySheet() failed: GetLastError returned %d\n"), dwError);
#endif
		return FALSE;
	}

	ASSERT(hWnd == m_hWnd);
	return TRUE;
}

void CPropertySheet::BuildPropPageArray()
{
	// delete existing prop page array
	free((void*)m_psh.ppsp);
	m_psh.ppsp = NULL;

	// determine size of PROPSHEETPAGE array
	int i;
	int nBytes = 0;
	for (i = 0; i < m_pages.GetSize(); i++)
	{
		CPropertyPage* pPage = GetPage(i);
		nBytes += pPage->m_psp.dwSize;
	}

	// build new PROPSHEETPAGE array
	PROPSHEETPAGE* ppsp = (PROPSHEETPAGE*)malloc(nBytes);
	BYTE* ppspOrigByte=reinterpret_cast<BYTE*>(ppsp);
	if (ppsp == NULL)
		AfxThrowMemoryException();
	BYTE* pPropSheetPagesArrEnd=ppspOrigByte + nBytes;
	ENSURE(pPropSheetPagesArrEnd >= ppspOrigByte);
	m_psh.ppsp = ppsp;
#ifndef _WIN32_WCE // undeclared identifier PSH_WIZARD97
	BOOL bWizard = (m_psh.dwFlags & (PSH_WIZARD | PSH_WIZARD97));
#else
	BOOL bWizard = FALSE;
#endif // !_WIN32_WCE
	for (i = 0; i < m_pages.GetSize(); i++)
	{
		CPropertyPage* pPage = GetPage(i);
		BYTE* ppspByte=reinterpret_cast<BYTE*>(ppsp);		
		ENSURE_THROW(ppspByte >= ppspOrigByte && ppspByte <= pPropSheetPagesArrEnd,AfxThrowMemoryException());
		Checked::memcpy_s(ppsp, pPropSheetPagesArrEnd - reinterpret_cast<BYTE*>(ppsp), &pPage->m_psp, pPage->m_psp.dwSize);

		// pszHeaderTitle and pszHeaderSubTitle are not members of _PROPSHEETPAGEW
		// undeclared identifier PSP_USEHEADERTITLE and PSP_USEHEADERSUBTITLE
#ifndef _WIN32_WCE
		if (!pPage->m_strHeaderTitle.IsEmpty())
		{
			ppsp->pszHeaderTitle = pPage->m_strHeaderTitle;
			ppsp->dwFlags |= PSP_USEHEADERTITLE;
		}
		if (!pPage->m_strHeaderSubTitle.IsEmpty())
		{
			ppsp->pszHeaderSubTitle = pPage->m_strHeaderSubTitle;
			ppsp->dwFlags |= PSP_USEHEADERSUBTITLE;
		}
#endif // !_WIN32_WCE

		pPage->PreProcessPageTemplate(*ppsp, bWizard);
		(BYTE*&)ppsp += ppsp->dwSize;
	}
	m_psh.nPages = (int)m_pages.GetSize();
}

////////////////////////////////////////////////////////////////////////////

int CPropertySheet::GetPageCount() const
{
	ASSERT_VALID(this);

	if (m_hWnd == NULL)
		return (int)m_pages.GetSize();

	CTabCtrl* pTab = GetTabControl();
	ENSURE(pTab);
	return pTab->GetItemCount();
}

int CPropertySheet::GetActiveIndex() const
{
	if (m_hWnd == NULL)
		return m_psh.nStartPage;

	CTabCtrl* pTab = GetTabControl();
	ENSURE(pTab);
	return pTab->GetCurSel();
}

BOOL CPropertySheet::SetActivePage(int nPage)
{
	if (m_hWnd == NULL)
	{
		m_psh.nStartPage = nPage;
		return TRUE;
	}
	return (BOOL)SendMessage(PSM_SETCURSEL, nPage);
}

int CPropertySheet::GetPageIndex(CPropertyPage* pPage)
{
	for (int i = 0; i < GetPageCount(); i++)
	{
		if (GetPage(i) == pPage)
			return i;
	}
	return -1;  // pPage not found
}

BOOL CPropertySheet::SetActivePage(CPropertyPage* pPage)
{
	ASSERT_VALID(this);
	ENSURE_VALID(pPage);
	ASSERT_KINDOF(CPropertyPage, pPage);

	int nPage = GetPageIndex(pPage);
	ASSERT(pPage >= 0);

	return SetActivePage(nPage);
}

#ifdef _WIN32_WCE
// The width of the property sheet is too big (with an error proportional to the desired width). 
// We correct for this here.
void AFXAPI _AfxAdjustPropertySheetSize(CPropertySheet *pSheet)
{
	int nMaxWidth = 0, nMaxHeight = 0;

	ASSERT(pSheet->m_hWnd != NULL);

	for (int iPage = 0; iPage < pSheet->GetPageCount() ; iPage++)
	{
		const DLGTEMPLATE* pTemplate;
		CPropertyPage* pPage = pSheet->GetPage(iPage);
		if (pPage == NULL)
			return;

		if (pPage->m_psp.dwFlags & PSP_DLGINDIRECT)
		{
			pTemplate = pPage->m_psp.pResource;
		}
		else
		{
			HRSRC hResource = ::FindResource(pPage->m_psp.hInstance, pPage->m_psp.pszTemplate, RT_DIALOG);
			if (hResource == NULL)
				return;

			HGLOBAL hTemplate = LoadResource(pPage->m_psp.hInstance, hResource);
			pTemplate = (LPCDLGTEMPLATE)LockResource(hTemplate);
		}

		CSize size;
		CDialogTemplate dlgTemplate(pTemplate);
		dlgTemplate.GetSizeInPixels(&size);
		if (size.cx > nMaxWidth)
			nMaxWidth = size.cx;
		if (size.cy > nMaxHeight)
			nMaxHeight = size.cy;
	}

	CTabCtrl* pWndTab = (CTabCtrl*)pSheet->GetDlgItem(AFX_IDC_TAB_CONTROL);
	if (pWndTab != NULL)
	{
		CRect rectWndTab, rectWndDlg;

		pSheet->GetWindowRect(rectWndDlg);
		pWndTab->GetWindowRect(rectWndTab);
		int dx = (rectWndTab.left-rectWndDlg.left) + (rectWndTab.right-rectWndDlg.right);
		int dy = (rectWndTab.top-rectWndDlg.top) + (rectWndTab.bottom-rectWndDlg.bottom);

		CRect rectDisplayTab = rectWndTab;
		pWndTab->AdjustRect(FALSE,&rectDisplayTab);
		int nButtonHeight = rectDisplayTab.top-rectWndTab.top;
		int nHSlop = 2, nVSlop = 12;

		int nWidth  = nMaxWidth  + 
			::GetSystemMetrics(SM_CXEDGE)*2 +
			::GetSystemMetrics(SM_CXDLGFRAME)*2 + nHSlop;
		int nHeight = nMaxHeight + nButtonHeight + nVSlop + 
			::GetSystemMetrics(SM_CYEDGE)*2 + 
			::GetSystemMetrics(SM_CYDLGFRAME)*2 +
			::GetSystemMetrics(SM_CYCAPTION);

		pSheet->SetWindowPos(NULL, 0, 0, nWidth, nHeight,
			SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
		pWndTab->SetWindowPos(NULL, 0, 0, nWidth - dx, nHeight - dy,
			SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	}
}
#endif // _WIN32_WCE

void CPropertySheet::AddPage(CPropertyPage* pPage)
{
	ASSERT_VALID(this);
	ENSURE_VALID(pPage);
	ASSERT_KINDOF(CPropertyPage, pPage);

	// add page to internal list
	m_pages.Add(pPage);

	// add page externally
	if (m_hWnd != NULL)
	{
		// determine size of PROPSHEETPAGE array
		PROPSHEETPAGE* ppsp = const_cast<PROPSHEETPAGE*>(m_psh.ppsp);
		int nBytes = 0;
		int nNextBytes;
		for (UINT i = 0; i < m_psh.nPages; i++)
		{
			nNextBytes = nBytes + ppsp->dwSize;
			if ((nNextBytes < nBytes) || (nNextBytes < (int)ppsp->dwSize))
				AfxThrowMemoryException();
			nBytes = nNextBytes;
			(BYTE*&)ppsp += ppsp->dwSize;
		}

		nNextBytes = nBytes + pPage->m_psp.dwSize;
		if ((nNextBytes < nBytes) || (nNextBytes < (int)pPage->m_psp.dwSize))
			AfxThrowMemoryException();

		// build new prop page array
		ppsp = (PROPSHEETPAGE*)realloc((void*)m_psh.ppsp, nNextBytes);
		if (ppsp == NULL)
			AfxThrowMemoryException();
		m_psh.ppsp = ppsp;

		// copy processed PROPSHEETPAGE struct to end
		(BYTE*&)ppsp += nBytes;
		Checked::memcpy_s(ppsp, nNextBytes - nBytes , &pPage->m_psp, pPage->m_psp.dwSize);
		pPage->PreProcessPageTemplate(*ppsp, IsWizard());

		// pszHeaderTitle and pszHeaderSubTitle are not members of _PROPSHEETPAGEW
		// undeclared identifier PSP_USEHEADERTITLE and PSP_USEHEADERSUBTITLE
#ifndef _WIN32_WCE
		if (!pPage->m_strHeaderTitle.IsEmpty())
		{
			ppsp->pszHeaderTitle = pPage->m_strHeaderTitle;
			ppsp->dwFlags |= PSP_USEHEADERTITLE;
		}
		if (!pPage->m_strHeaderSubTitle.IsEmpty())
		{
			ppsp->pszHeaderSubTitle = pPage->m_strHeaderSubTitle;
			ppsp->dwFlags |= PSP_USEHEADERSUBTITLE;
		}
#endif // !_WIN32_WCE

		HPROPSHEETPAGE hPSP = AfxCreatePropertySheetPage2(ppsp);
		if (hPSP == NULL)
			AfxThrowMemoryException();

		if (!SendMessage(PSM_ADDPAGE, 0, (LPARAM)hPSP))
		{
			AfxDestroyPropertySheetPage(hPSP);
			AfxThrowMemoryException();
		}
#ifdef _WIN32_WCE
		int aygshellUIModel = AfxGetAygshellUIModel();
		if (aygshellUIModel != PocketPC)
		{
			_AfxAdjustPropertySheetSize(this);
		}
#endif
		++m_psh.nPages;
	}
}

void CPropertySheet::RemovePage(CPropertyPage* pPage)
{
	ASSERT_VALID(this);
	ENSURE_VALID(pPage);
	ASSERT_KINDOF(CPropertyPage, pPage);

	int nPage = GetPageIndex(pPage);
	ASSERT(nPage >= 0);

	RemovePage(nPage);
}

void CPropertySheet::RemovePage(int nPage)
{
	ASSERT_VALID(this);

	// remove the page externally
	if (m_hWnd != NULL)
		SendMessage(PSM_REMOVEPAGE, nPage);

	// remove the page from internal list
	m_pages.RemoveAt(nPage);
}

void CPropertySheet::EndDialog(int nEndID)
{
	ASSERT_VALID(this);
	CWnd::EndModalLoop(nEndID);
	//Now PSN_RESET and other notifications are sent to property pages.
#ifndef _WIN32_WCE
	::PropSheet_PressButton(m_hWnd, PSBTN_CANCEL); 
#else
	if (m_bModeless)
	{
		DestroyWindow();
	}
	else
	{
		PostMessage(PSM_PRESSBUTTON, PSBTN_CANCEL);
	}
#endif // !_WIN32_WCE
}

void CPropertySheet::OnClose()
{
	m_nModalResult = IDCANCEL;
	if (m_bModeless)
	{
		//Now PSN_RESET and other notifications are sent to property pages.
#ifndef _WIN32_WCE
		::PropSheet_PressButton(m_hWnd, PSBTN_CANCEL);
#else
		DestroyWindow();
#endif // !_WIN32_WCE
	}
	else
	{
		Default();
	}
}

LRESULT CPropertySheet::OnKickIdle(WPARAM wp, LPARAM lp)
{
	ASSERT_VALID(this);
	/* Forward the message on to the active page of the property sheet */
	CPropertyPage * pPage = GetActivePage();
	if( pPage != NULL )
	{
		ASSERT_VALID(pPage);
		return pPage->SendMessage( WM_KICKIDLE, wp, lp );
	}
	else
		return 0;
}

void CPropertySheet::OnSysCommand(UINT nID, LPARAM)
{
	m_nModalResult = IDCANCEL;
	switch (nID & 0xFFF0)
	{
	case SC_CLOSE:
		if (m_bModeless)
		{
			SendMessage(WM_CLOSE);
			return;
		}
	}
	Default();
}

/////////////////////////////////////////////////////////////////////////////
// CPropertySheet message handlers

AFX_STATIC_DATA int _afxPropSheetButtons[] = { IDOK, IDCANCEL, ID_APPLY_NOW, IDHELP };

BOOL CPropertySheet::OnInitDialog()
{
	// change tab style if scrolling tabs desired (stacked tabs are default)
	if (!m_bStacked)
	{
		HWND hWndTab = (HWND)::GetDlgItem(m_hWnd, AFX_IDC_TAB_CONTROL);
		if (hWndTab != NULL)
			CWnd::ModifyStyle(hWndTab, TCS_MULTILINE, TCS_SINGLELINE, 0);
	}

#ifndef _WIN32_WCE
	if (!IsWizard())
	{
		// resize the tab control so the layout is less restrictive
		HWND hWnd = (HWND)::GetDlgItem(m_hWnd, AFX_IDC_TAB_CONTROL);
		ASSERT(hWnd != NULL);
		CRect rectOld;
		::GetWindowRect(hWnd, &rectOld);
		ScreenToClient(rectOld);
		CRect rectNew(0, 0, 0, 32);
		::MapDialogRect(m_hWnd, &rectNew);
		if (rectNew.bottom < rectOld.bottom)
		{
			// move tab control
			int cyDiff = rectOld.Height() - rectNew.bottom;
			::SetWindowPos(hWnd, NULL, 0, 0, rectOld.Width(), rectNew.bottom,
				SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

			// move buttons by similar amount
			for (int i = 0; i < _countof(_afxPropSheetButtons); i++)
			{
				hWnd = ::GetDlgItem(m_hWnd, _afxPropSheetButtons[i]);
				if (hWnd != NULL)
				{
					::GetWindowRect(hWnd, &rectOld);
					ScreenToClient(&rectOld);
					::SetWindowPos(hWnd, NULL,
						rectOld.left, rectOld.top - cyDiff,
						0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
				}
			}

			// resize property sheet itself similarly
			GetWindowRect(&rectOld);
			SetWindowPos(NULL, 0, 0, rectOld.Width(), rectOld.Height() - cyDiff,
				SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
		}
	}

	BOOL bResult = (BOOL)Default();

	if (m_bModeless && !IsWizard())
	{
		// layout property sheet so button area is not accounted for
		CRect rectWnd;
		GetWindowRect(rectWnd);
		CRect rectButton;
		HWND hWnd = ::GetDlgItem(m_hWnd, IDOK);
		if (hWnd != NULL)
		{
			::GetWindowRect(hWnd, rectButton);
			SetWindowPos(NULL, 0, 0,
				rectWnd.Width(), rectButton.top - rectWnd.top,
				SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
		}

		// remove standard buttons for modeless dialogs
		for (int i = 0; i < _countof(_afxPropSheetButtons); i++)
		{
			HWND hWndButton = ::GetDlgItem(m_hWnd, _afxPropSheetButtons[i]);
			if (hWndButton != NULL)
			{
				::ShowWindow(hWndButton, SW_HIDE);
				::EnableWindow(hWndButton, FALSE);
			}
		}
	}

	// center the property sheet relative to the parent window
	if (!(GetStyle() & WS_CHILD))
		CenterWindow();
#else
	BOOL bResult = TRUE;

	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel != PocketPC)
	{
		_AfxAdjustPropertySheetSize(this);
	}
#endif // !_WIN32_WCE

	return bResult;
}

#ifndef _WIN32_WCE
BOOL CPropertySheet::OnNcCreate(LPCREATESTRUCT)
{
	// By default, MFC does not directly support the new style
	// help button in the caption, so it is turned off here.
	// It can be added back in and implemented by derived classes
	// from CPropertySheet.
	ModifyStyleEx(WS_EX_CONTEXTHELP, 0);

	return (BOOL)Default();
}
#endif // !_WIN32_WCE

LRESULT CPropertySheet::HandleInitDialog(WPARAM, LPARAM)
{
	LRESULT lResult = OnInitDialog();
	return lResult;
}

BOOL CPropertySheet::OnCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32_WCE
	if (AfxGetAygshellUIModel() == WindowsCE)
	{
		// allow message map override
		if (CWnd::OnCommand(wParam, lParam))
			return TRUE;
	}
#endif // _WIN32_WCE

	// crack message parameters
	UINT nID = LOWORD(wParam);
	HWND hWndCtrl = (HWND)lParam;
	int nCode = HIWORD(wParam);

#ifdef _WIN32_WCE
	// the OK button is somewhere else (i.e. hWndCtrl isn't set). Check for it differently 
	if (nID == IDOK)
	{
		if (m_bModeless)
			EndDialog(nID);
		else
			m_nModalResult = nID;
	}
	else
#endif // _WIN32_WCE	
	// set m_nModalResult to ID of button, whenever button is clicked
	if (hWndCtrl != NULL && nCode == BN_CLICKED)
	{
		if (::SendMessage(hWndCtrl, WM_GETDLGCODE, 0, 0) &
			(DLGC_BUTTON|DLGC_DEFPUSHBUTTON))
		{
			LONG lStyle = ::GetWindowLong(hWndCtrl, GWL_STYLE) & 0x0F;
			if (lStyle == BS_PUSHBUTTON || lStyle == BS_DEFPUSHBUTTON ||
				lStyle == BS_USERBUTTON || lStyle == BS_OWNERDRAW)
			{
				m_nModalResult = nID;
			}
		}
	}
#ifdef _WIN32_WCE
	else
	{
		int aygshellUIModel = AfxGetAygshellUIModel();
		if (aygshellUIModel == PocketPC)
		{
			// allow message map override
			if (CWnd::OnCommand(wParam, lParam))
				return TRUE;
		}
	}
#endif // _WIN32_WCE
	return FALSE;
}

#ifndef _WIN32_WCE_NO_HELP_SUPPORT
LRESULT CPropertySheet::OnCommandHelp(WPARAM wParam, LPARAM lParam)
{
	ASSERT_VALID(this);

	CPropertyPage* pPage = GetActivePage();
	ASSERT_VALID(pPage);
	return AfxCallWndProc(pPage, pPage->m_hWnd, WM_COMMANDHELP, wParam, lParam);
}
#endif // !_WIN32_WCE_NO_HELP_SUPPORT

HBRUSH CPropertySheet::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	ENSURE_ARG(pWnd != NULL);
	LRESULT lResult;
	if (pWnd->SendChildNotifyLastMsg(&lResult))
		return (HBRUSH)lResult;

	return CWnd::OnCtlColor(pDC, pWnd, nCtlColor);
}

/////////////////////////////////////////////////////////////////////////////
// CPropertySheet Diagnostics

#ifdef _DEBUG
void CPropertySheet::AssertValid() const
{
	CWnd::AssertValid();
	m_pages.AssertValid();
	ASSERT(m_psh.dwSize == sizeof(m_psh));
	ASSERT((m_psh.dwFlags & PSH_PROPSHEETPAGE) == PSH_PROPSHEETPAGE);
}

#ifndef _WIN32_WCE
void CPropertySheet::Dump(CDumpContext& dc) const
{
	CWnd::Dump(dc);

	dc << "m_strCaption = " << m_strCaption << "\n";
	dc << "Number of Pages = " << LONGLONG(m_pages.GetSize()) << "\n";
	dc << "Stacked = " << m_bStacked << "\n";
	dc << "Modeless = " << m_bModeless << "\n";
}
#endif // !_WIN32_WCE
#endif //_DEBUG


IMPLEMENT_DYNAMIC(CPropertyPage, CDialog)
IMPLEMENT_DYNAMIC(CPropertySheet, CWnd)

/////////////////////////////////////////////////////////////////////////////
