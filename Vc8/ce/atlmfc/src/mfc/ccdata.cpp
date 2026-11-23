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


#ifndef _WIN32_WCE
#pragma comment(lib, "imagehlp.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "winspool.lib")
#pragma comment(lib, "advapi32.lib")
#else
#pragma comment(lib, "commctrl.lib")
#endif // !_WIN32_WCE

/////////////////////////////////////////////////////////////////////////////
// AfxGetPropSheetFont

struct _AFX_PROPPAGEFONTINFO : public CNoTrackObject
{
	LPTSTR m_pszFaceName;
	WORD m_wSize;
	_AFX_PROPPAGEFONTINFO() : m_pszFaceName(NULL), m_wSize(0) {}
	~_AFX_PROPPAGEFONTINFO() { GlobalFree(m_pszFaceName); }
};

PROCESS_LOCAL(_AFX_PROPPAGEFONTINFO, _afxPropPageFontInfo)

#define IDD_PROPSHEET   1006
#define IDD_WIZARD      1020

static int CALLBACK FontEnumProc(const LOGFONT*, const TEXTMETRIC*, DWORD, LPARAM lParam)
{
	if (lParam != NULL)
	{
		*(BOOL*)lParam = TRUE;
	}
	return 0;
}

static BOOL IsFontInstalled(LPCTSTR pszFace)
{
	BOOL bInstalled=FALSE;
	HDC hDC=NULL;
	LOGFONT lf;

	memset(&lf, 0, sizeof(lf));

	size_t nLenFace=_tcslen(pszFace);
	ENSURE(nLenFace<LF_FACESIZE);

	Checked::tcscpy_s(lf.lfFaceName, _countof(lf.lfFaceName), pszFace);
	lf.lfCharSet = DEFAULT_CHARSET;

	bInstalled = FALSE;
	hDC = ::GetDC(NULL);
	if (hDC != NULL)
	{
#ifndef _WIN32_WCE // the win32 api EnumFontFamiliesEx could not be matched although it's declared in CE SDK headers
		::EnumFontFamiliesEx(hDC, &lf, FontEnumProc, (LPARAM)&bInstalled, 0);
#else
		::EnumFontFamilies(hDC, lf.lfFaceName, FontEnumProc, (LPARAM)&bInstalled);
#endif // !_WIN32_WCE
		::ReleaseDC(NULL, hDC);
	}

	return bInstalled;
}

typedef LANGID (WINAPI* PFNGETUSERDEFAULTUILANGUAGE)();

BOOL AFXAPI AfxGetPropSheetFont(CString& strFace, WORD& wSize, BOOL bWizard)
{
	_AFX_PROPPAGEFONTINFO* pFontInfo = _afxPropPageFontInfo.GetData();

	// determine which font property sheet will use
	if (pFontInfo->m_wSize == 0)
	{
		ASSERT(pFontInfo->m_pszFaceName == NULL);

		HINSTANCE hInst = afxComCtlWrapper->GetModuleHandle();
		if (hInst != NULL)
		{
			HRSRC hResource = NULL;
			WORD wLang = 0;
#ifndef _WIN32_WCE
			HMODULE hKernel32 = ::GetModuleHandleA("KERNEL32.DLL");
#else
// coreloc.lib is the required link library for GetUserDefaultUILanguage, but there is no corresponding dll to it.
// Going further, the win32 api could be found in coredll.lib for Pocket PC 2003 SDK but not Standard SDK. 
			HMODULE hKernel32 = ::GetModuleHandle(_T("COREDLL.DLL"));
#endif // !_WIN32_WCE
			PFNGETUSERDEFAULTUILANGUAGE pfnGetUserDefaultUILanguage;
			pfnGetUserDefaultUILanguage = (PFNGETUSERDEFAULTUILANGUAGE)::GetProcAddress(
				hKernel32, _T("GetUserDefaultUILanguage"));
			if (pfnGetUserDefaultUILanguage != NULL)
			{
				LANGID langid;
				langid = pfnGetUserDefaultUILanguage();
				if ((PRIMARYLANGID(langid) == LANG_JAPANESE) && 
					IsFontInstalled(_T("MS UI Gothic")))
					wLang = MAKELANGID(LANG_JAPANESE, 0x3f);
			}
#ifndef _WIN32_WCE // unsupported win32 api call to FindResourceEx
			if (wLang != 0)
			{
				hResource = ::FindResourceEx(hInst, RT_DIALOG, 
					MAKEINTRESOURCE(bWizard ? IDD_WIZARD : IDD_PROPSHEET), wLang);
			}
#endif // !_WIN32_WCE
			if (hResource == NULL)
			{
				hResource = ::FindResource(hInst,
					MAKEINTRESOURCE(bWizard ? IDD_WIZARD : IDD_PROPSHEET),
					RT_DIALOG);
			}
			if(hResource!=NULL)
			{
				HGLOBAL hTemplate = LoadResource(hInst, hResource);
				if (hTemplate != NULL)
				{
					CDialogTemplate::GetFont((DLGTEMPLATE*)hTemplate, strFace,
						wSize);
				}
			}
		}

		pFontInfo->m_pszFaceName = (LPTSTR)GlobalAlloc(GPTR, static_cast<UINT>(::ATL::AtlMultiplyThrow(static_cast<UINT>((strFace.GetLength() + 1)),static_cast<UINT>(sizeof(TCHAR))) ));
		ENSURE_THROW(pFontInfo->m_pszFaceName!=NULL, ::AfxThrowMemoryException() );
		Checked::tcscpy_s(pFontInfo->m_pszFaceName, strFace.GetLength() + 1, strFace);
		pFontInfo->m_wSize = wSize;
	}

	strFace = pFontInfo->m_pszFaceName;
	wSize = pFontInfo->m_wSize;

	return (wSize != 0xFFFF);
}

/////////////////////////////////////////////////////////////////////////////
