// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

#ifndef __ATLOSAPICE_H__
#define __ATLOSAPICE_H__

#pragma once

/////////////////////////////////////////////////////////////////////////////
// The following are provided only to minimize #ifdef's in the ATL code base, which is why they are in the ATL namespace.

#ifdef _WIN32_WCE

#include <ocidl.h>
#if defined(SHELLSDK_MODULES_AYGSHELL) || defined(SHELLW_MODULES_AYGSHELL)
#ifdef SHELLSDK_MODULES_AYGSHELL
#include <shellsdk.h>
#else
#include <aygshell.h>
#endif
#ifndef SHGetMenu
#define SHGetMenu(hWndMB) reinterpret_cast<HMENU>(::SendMessage((hWndMB), SHCMBM_GETMENU, (WPARAM)0, (LPARAM)0));
#endif // !SHGetMenu
#endif // SHELLSDK_MODULES_AYGSHELL || SHELLW_MODULES_AYGSHELL

// Windows CE doesn't support a system menu, but in order to maintain application compatibility a  macro was 
// provided to allow disabling of the close box on the caption; however, this macro causes compile errors for 
// CWnd::GetSystemMenu.
#ifdef GetSystemMenu
#undef GetSystemMenu
inline HMENU GetSystemMenu(HWND hWnd, BOOL /*bRevert*/)
{
	return reinterpret_cast<HMENU>(hWnd);
}
#endif

// PropertySheet
// Current CESDK (Mckendric) utilized for building MFC only define this when MDD_PORT is defined.
// But in Pocket PC 2003 SDK there is no such constraint. 
#ifndef PSCB_GETVERSION
#define PSCB_GETVERSION		3
#endif

#ifndef SM_DBCSENABLED
#define SM_DBCSENABLED		42
#endif

/* WM_PRINT flags */
#ifndef PRF_CHILDREN
#define PRF_CHILDREN            0x00000010L
#endif

#ifndef PRF_CLIENT
#define PRF_CLIENT              0x00000004L
#endif

/* Menu and CommandBar */
// height of CommandBar
#ifndef CB_HEIGHT
#define CB_HEIGHT               26
#endif

// flags to control the appearance and behavior of the new menu item
#ifndef MF_BITMAP
#define MF_BITMAP		0 // tells system to use a bitmap rather than a text string to display a menu item...but it's not a supported flag on Windows CE
#endif

#ifndef MF_DISABLED
#define MF_DISABLED		0
#endif


/* mapping modes */
// Windows CE does not support multiple mapping modes. The only mapping mode is MM_TEXT, which maps logical coordinates 
// to the physical coordinates in a 1:1 ratio from left to right and top to bottom. [From Macallan Help]
#ifndef MM_TEXT
#define MM_TEXT                 1
#endif

#ifndef WM_PRINT
#define WM_PRINT                WM_PAINT
#endif
// WM_NCDESTROY is not a supported message on WINCE, but we want to keep the logic
// (OnNcDestroy mainly) behind it... 
#ifndef WM_NCDESTROY
#define WM_NCDESTROY            (WM_APP - 1)
#endif

#ifndef WS_EX_LAYOUTRTL
#define WS_EX_LAYOUTRTL         0x00400000L
#endif

#ifndef SW_NORMAL
#define SW_NORMAL               (SW_SHOWNORMAL)
#endif

#ifndef SW_SHOWMINNOACTIVE
#define SW_SHOWMINNOACTIVE      (SW_HIDE)
#endif

#ifndef MB_TYPEMASK
#define MB_TYPEMASK             0x0000000FL
#endif

#ifndef MB_ICONMASK
#define MB_ICONMASK             0x000000F0L
#endif

#ifndef CTLCOLOR_SCROLLBAR
#define CTLCOLOR_SCROLLBAR      CTLCOLOR_EDIT
#endif

#ifndef DEFAULT_GUI_FONT
#define DEFAULT_GUI_FONT        SYSTEM_FONT
#endif

#ifndef PS_DOT
#define PS_DOT                  2
#endif

#ifndef CWP_SKIPINVISIBLE
#define CWP_SKIPINVISIBLE       0x0001
#endif

#ifndef CWP_SKIPDISABLED
#define CWP_SKIPDISABLED        0x0002
#endif

#ifndef SWP_NOREDRAW
#define SWP_NOREDRAW            0
#endif

#ifndef MB_TASKMODAL
#define MB_TASKMODAL            0
#endif

#ifndef MB_SYSTEMMODAL
#define MB_SYSTEMMODAL          MB_APPLMODAL
#endif

#ifndef GMEM_LOCKCOUNT
#define GMEM_LOCKCOUNT          LMEM_LOCKCOUNT
#endif

#ifndef ILS_NORMAL
#define ILS_NORMAL              0x00000000 
#endif

#ifndef LBSELCHSTRING
#define LBSELCHSTRING           TEXT("commdlg_LBSelChangedNotify")
#endif

#ifndef SHAREVISTRING
#define SHAREVISTRING           TEXT("commdlg_ShareViolation")
#endif

#ifndef FILEOKSTRING 
#define FILEOKSTRING            TEXT("commdlg_FileNameOK")
#endif

#ifndef COLOROKSTRING
#define COLOROKSTRING           TEXT("commdlg_ColorOK")
#endif

#ifndef SETRGBSTRING
#define SETRGBSTRING            TEXT("commdlg_SetRGBColor")
#endif

#ifndef HELPMSGSTRING
#define HELPMSGSTRING           TEXT("commdlg_help")
#endif

#ifndef FINDMSGSTRING
#define FINDMSGSTRING           TEXT("commdlg_FindReplace")
#endif

#ifndef DRAGLISTMSGSTRING
#define DRAGLISTMSGSTRING       TEXT("commctrl_DragListMsg")
#endif

#ifndef CDSIZEOF_STRUCT
#define CDSIZEOF_STRUCT(structname, member)    (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))
#endif

#ifndef OPENFILENAME_SIZE_VERSION_400W
#define OPENFILENAME_SIZE_VERSION_400W  CDSIZEOF_STRUCT(OPENFILENAMEW,lpTemplateName)
#endif

#ifndef OPENFILENAME_SIZE_VERSION_400
#define OPENFILENAME_SIZE_VERSION_400  OPENFILENAME_SIZE_VERSION_400W
#endif

extern "C" DWORD GetProcessIndexFromID(HANDLE hProc);
extern "C" HANDLE GetProcessIDFromIndex(DWORD dwIdx);

namespace ATL
{
// These are not provided on Windows CE
#ifndef GWLP_WNDPROC
#define GWLP_WNDPROC GWL_WNDPROC
#endif
#ifndef GWLP_USERDATA
#define GWLP_USERDATA GWL_USERDATA
#endif
#ifndef DWLP_MSGRESULT
#define DWLP_MSGRESULT DWL_MSGRESULT
#endif
#ifndef DWLP_DLGPROC
#define DWLP_DLGPROC DWL_DLGPROC
#endif

#ifndef SetWindowLongPtr 
#define SetWindowLongPtr SetWindowLongPtrW
#endif

#ifndef GetWindowLongPtr 
#define GetWindowLongPtr GetWindowLongPtrW
#endif

// The following are not included in Windows CE SDK headers, but they are included in
// the windows headers, and they are utilized by ATL.

#ifndef IS_INTRESOURCE 
#define IS_INTRESOURCE(_r) (((ULONG_PTR)(_r) >> 16) == 0)
#endif

#ifndef MulDiv
inline int MulDiv(
  int nNumber,
  int nNumerator,
  int nDenominator
)
{
	return static_cast<int>((static_cast<__int64>(nNumber)*static_cast<__int64>(nNumerator))/static_cast<__int64>(nDenominator));
}
#endif

#ifndef VARCMP_LT  
#define VARCMP_LT   0
#endif
#ifndef VARCMP_EQ 
#define VARCMP_EQ   1
#endif
#ifndef VARCMP_GT 
#define VARCMP_GT   2
#endif
#ifndef VARCMP_NULL 
#define VARCMP_NULL 3
#endif

#ifndef VTDATEGRE_MAX
#define VTDATEGRE_MAX 2958465   /* Dec 31, 9999, 0:0:0 in Gregorain Calendar */
#endif

#ifndef VTDATEGRE_MIN
#define VTDATEGRE_MIN -657434   /* Jan  1,  100, 0:0:0 in Gregorain Calendar */
#endif

#ifndef WS_OVERLAPPEDWINDOW
#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP)
#define WS_OVERLAPPEDWINDOW (WS_SYSMENU)
#else
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#endif
#endif

#ifndef _MAX_FNAME
#define _MAX_FNAME                 64
#endif

STDAPI SafeArrayGetVartype(SAFEARRAY * psa, VARTYPE * pvt);
STDAPI VarBstrCat(BSTR bstrLeft, BSTR bstrRight, LPBSTR pbstrResult);
STDAPI VarCmp(LPVARIANT pvarLeft, LPVARIANT pvarRight, LCID lcid, ULONG dwFlags);
STDAPI VarBstrCmp(BSTR bstrLeft, BSTR bstrRight, LCID lcid, ULONG dwFlags); // dwFlags passed to CompareString
STDAPI_(LPWSTR*) CommandLineToArgvW(LPCWSTR lpCmdLine, int* pNumArgs);

// taken from winbase.h
#define MAX_COMPUTERNAME_LENGTH 15

inline BOOL IsWindowUnicode(
	HWND /*hWnd*/)
{
	return TRUE;
}

inline BOOL IsIconic(HWND hWnd)
{
	return !::IsWindowEnabled(hWnd);
}

inline int GetScrollPos(
	HWND hWnd, int nBar)
{
	SCROLLINFO lpsi = {sizeof(SCROLLINFO), SIF_POS};
	if(::GetScrollInfo(hWnd, nBar, &lpsi))
	{
		return lpsi.nPos;
	}
	return 0;
}

inline BOOL GetScrollRange(
	HWND hWnd,
	int nBar,
	LPINT lpMinPos,
	LPINT lpMaxPos)
{
	SCROLLINFO lpsi = {sizeof(SCROLLINFO), SIF_RANGE};

	if (::GetScrollInfo(hWnd, nBar, &lpsi))
	{
		*lpMinPos = lpsi.nMin;
		*lpMaxPos = lpsi.nMax;
		return TRUE;
	}
	return FALSE;
}

inline HWND GetTopWindow(
	HWND hWnd)
{
	return ::GetWindow(hWnd, GW_CHILD);
}

inline HWND GetNextWindow(HWND hWnd, UINT nDirection)
{
	if(!(nDirection & GW_HWNDNEXT|GW_HWNDPREV))
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return NULL;
	}
		
	return ::GetWindow(hWnd, nDirection);
}

inline void ScrollChildren(HWND hWnd, int cx, int cy)
{
	// WinCE does not perform any scrolling if the window is
	// not visible. This leaves child windows unscrolled.
	// To account for this oversight, the child windows are moved
	// directly instead.
	HWND hWndChild = ::GetWindow(hWnd, GW_CHILD);
	if (hWndChild != NULL)
	{
		for (; hWndChild != NULL;
			hWndChild = GetNextWindow(hWndChild, GW_HWNDNEXT))
		{
			RECT rect;
			::GetWindowRect(hWndChild, &rect);
			::ScreenToClient(hWnd,(POINT*)&rect.left);
			::SetWindowPos(hWndChild, NULL,	rect.left-cx, rect.top-cy,
				0, 0, SWP_NOSIZE|SWP_NOACTIVATE|SWP_NOZORDER);
		}
	}
}

inline BOOL GetViewportOrgEx(HDC hdc, LPPOINT lpPoint)
{
	if (hdc == NULL)
		return FALSE;

	lpPoint->x = 0;
	lpPoint->y = 0;

	return TRUE;
}

inline BOOL GetViewportExtEx(HDC hdc, LPSIZE lpSize)
{
	if (hdc == NULL)
		return FALSE;

	lpSize->cx = 1;
	lpSize->cy = 1;

	return TRUE;
}

inline BOOL GetWindowOrgEx(HDC hdc, LPPOINT lpPoint)
{
	if (hdc == NULL)
		return FALSE;

	lpPoint->x = 0;
	lpPoint->y = 0;

	return TRUE;
}

inline BOOL GetWindowExtEx(HDC hdc, LPSIZE lpSize)
{
	if (hdc == NULL)
		return FALSE;

	lpSize->cx = 1;
	lpSize->cy = 1;

	return TRUE;
}

inline BOOL DPtoLP(HDC hdc, LPPOINT /*lpPoints*/, int /*nCount*/)
{
	if (hdc == NULL)
		return FALSE;

	return TRUE;
}

inline BOOL LPtoDP(HDC hdc, LPPOINT /*lpPoints*/, int /*nCount*/)
{
	if (hdc == NULL)
		return FALSE;

	return TRUE;
}

inline BOOL PolyPolygon(HDC hdc, const POINT* lpPoints, const int* lpPolyCounts, int nCount)
{
	if (nCount < 2)
		return FALSE;

	BOOL bResult = TRUE;
	for (int nPolygon = 0, nVertex = 0 ; bResult && (nPolygon < nCount) ; nPolygon++, nVertex += lpPolyCounts[nPolygon])
	{
		bResult = (lpPolyCounts[nPolygon] < 2) ? FALSE :
				::Polygon(hdc, &(lpPoints[nVertex]), lpPolyCounts[nPolygon]);
	}
	return bResult;
}

inline BOOL EnumChildWindows(
	HWND hWndParent,
	WNDENUMPROC lpEnumFunc,
	LPARAM lParam)
{
	if(lpEnumFunc == NULL)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return FALSE;
	}
	
	HWND hWndChild = ::GetWindow(hWndParent, GW_CHILD);
	if(hWndChild == NULL)
	{
		// Leave last error to whatever GetWindow set it as
		return FALSE;
	}
	
	for(; hWndChild != NULL; hWndChild = ::GetWindow(hWndChild, GW_HWNDNEXT))
	{
		lpEnumFunc(hWndChild, lParam);
		ATL::EnumChildWindows(hWndChild, lpEnumFunc, lParam);
	}

	return TRUE;
}

inline HWND GetLastActivePopup(
	HWND hWnd)
{
	(hWnd);
	return ::GetActiveWindow();
}

inline BOOL ShowScrollBar(
	HWND hWnd,
	int wBar,
	BOOL bShow)
{
	DWORD dwStyle = ::GetWindowLong(hWnd, GWL_STYLE);

	DWORD dwStyleDelta = 0;
	
	switch(wBar)
	{
		case SB_BOTH:
			dwStyleDelta |= WS_HSCROLL | WS_VSCROLL;
			break;

		case SB_HORZ:
			dwStyleDelta |= WS_HSCROLL;
			break;
		case SB_VERT:
			dwStyleDelta |= WS_VSCROLL;
			break;
		default:
			::SetLastError(ERROR_INVALID_PARAMETER);
			return FALSE;
	}
	
	if(bShow)
	{
		dwStyle |= dwStyleDelta;
	}
	else
	{
		dwStyle &= ~dwStyleDelta;
	}
	
	return (::SetWindowLong(hWnd, GWL_STYLE, dwStyle) != 0);
}

inline BOOL IsMenu(HMENU hMenu)
{
	MENUITEMINFO mii;
	ZeroMemory(&mii, sizeof(mii));
	mii.cbSize = sizeof(mii);

	SetLastError(0);
	if (::GetMenuItemInfo(hMenu, 0, TRUE, &mii))
	{
		return TRUE;
	}
	else
	{
		return (::GetLastError() != ERROR_INVALID_MENU_HANDLE);
	}
}

#if defined(SHELLSDK_MODULES_AYGSHELL) || defined(SHELLW_MODULES_AYGSHELL)
inline HMENU GetMenu(HWND hWnd)
{
	HWND hWndMB = ::SHFindMenuBar(hWnd);
	if(hWndMB != NULL)
	{
		return SHGetMenu(hWndMB);
	}
	return NULL;
}
#endif // SHELLSDK_MODULES_AYGSHELL || SHELLW_MODULES_AYGSHELL

inline int GetMenuItemCount(HMENU hMenu)
{
	if(!ATL::IsMenu(hMenu))
	{
		::SetLastError(ERROR_INVALID_HANDLE);
		return -1;
	}
	
	MENUITEMINFO mii;
	memset((char *)&mii, 0, sizeof(mii));
	mii.cbSize = sizeof(mii);

	UINT i = 0;
	
	while(true)
	{
		if(0 == ::GetMenuItemInfo(hMenu, i, TRUE, &mii))
		{
			break;
		}
		++i;
	}

	return i;
}

inline UINT GetMenuItemID(
	HMENU hMenu,
	int nPos)
{
	MENUITEMINFO mii;
	memset((char *)&mii, 0, sizeof(mii));
	mii.cbSize = sizeof(mii); 
	mii.fMask  = MIIM_ID; 
	
	if((0 == ::GetMenuItemInfo(hMenu, nPos, TRUE, &mii)) || (mii.hSubMenu != NULL))
	{
		return 0xFFFFFFFF;
	}

	return mii.wID; 
}

inline BOOL IsByPosition(UINT uFlags)
{
	// MF_BYCOMMAND, which is 0, is the default, but MF_BYPOSITION overrides if both are set
	return (uFlags & MF_BYPOSITION) ? TRUE : FALSE;
}

inline int GetMenuStringW(
	HMENU hMenu, 
	UINT uIDItem, 
	LPWSTR lpString, 
	int nMaxCount, 
	UINT uFlag)
{ 
	MENUITEMINFO mii;
	memset((char *)&mii, 0, sizeof(mii));
	mii.cbSize = sizeof(mii);
	mii.fMask = MIIM_TYPE;
	mii.fType = MFT_STRING;
	mii.dwTypeData = lpString;
	mii.cch = nMaxCount;

	if((0 == ::GetMenuItemInfo(hMenu, uIDItem, IsByPosition(uFlag), &mii)) || (lpString != mii.dwTypeData))
	{
		return 0;
	}

	return (lpString != NULL) ? ::wcslen(lpString) : mii.cch;
}

#ifndef GetMenuString
#define GetMenuString GetMenuStringW
#endif

inline UINT GetMenuState(HMENU hMenu, UINT uId, UINT uFlags)
{
	MENUITEMINFO mii;
	memset((char *)&mii, 0, sizeof(mii));
	mii.cbSize = sizeof(mii);
	mii.fMask  = MIIM_STATE;

	if(0 == ::GetMenuItemInfo(hMenu, uId, IsByPosition(uFlags), &mii))
	{
		return 0;
	}

	return mii.fState;
}


inline BOOL ModifyMenuW(
	HMENU hMenu,
	UINT uPosition,
	UINT uFlags,
	UINT_PTR uIDNewItem,
	LPCWSTR lpNewItem)
{
	if(!IsByPosition(uFlags))
	{	
		MENUITEMINFO mii;
		memset((char *)&mii, 0, sizeof(mii));
		mii.cbSize = sizeof(mii); 
		mii.fMask  = MIIM_ID; 

		UINT uCount = 0;
		while(true)
		{
			if((0 == ::GetMenuItemInfo(hMenu, uCount, TRUE, &mii)) || (mii.wID == uPosition))
			{
				break;  // We rely on DeleteMenu to fiail if we break out due to error on GetMenuItemInfo, since that should mean the uCount is a bogus item
			}
			++uCount;
		}

		if(uCount == 0)
		{
			// GetMenuItemInfo will call SetLastError
			return FALSE;
		}

		// Now we have the position
		uPosition = uCount;
		uFlags |= MF_BYPOSITION;
	}

	if(0 == ::DeleteMenu(hMenu, uPosition, uFlags))
	{
		// DeleteMenu will call SetLastError
		return FALSE;
	}

	// InsertMenu will call SetLastError
	return ::InsertMenu(hMenu, uPosition, uFlags, uIDNewItem, lpNewItem);
}

#ifndef ModifyMenu 
#define ModifyMenu  ModifyMenuW
#endif

// There is a macro for TrackPopupMenu defined in SDK winuser.h, which could result in compilation errors 
// "not enough actual parameters for macro 'TrackPopupMenu'". redefine it to be a function
#ifdef TrackPopupMenu
#undef TrackPopupMenu
inline BOOL TrackPopupMenu(
	HMENU hMenu,
	UINT uFlags,
	int x,
	int y,
	int nReserved,
	HWND hWnd,
	const RECT* prcRect)
{
	(nReserved, prcRect);
	return TrackPopupMenuEx(hMenu, uFlags, x, y, hWnd, 0);
}
#endif

inline int ExtSelectClipRgn(
	HDC hdc,
	HRGN hrgn,
	int fnMode)
{
	if(hdc == NULL || (hrgn == NULL && fnMode != RGN_COPY))
	{
		return ERROR;
	}

	if(fnMode == RGN_COPY)
	{
		return ::SelectClipRgn(hdc, hrgn);
	}

	HRGN hrgnCurrentClip = CreateRectRgn(0, 0, 1, 1); // bogus region that will get overwritten
	if(-1 == ::GetClipRgn(hdc, hrgnCurrentClip))
	{
		return ERROR;
	}

	HRGN hrgnNewClip = CreateRectRgn(0, 0, 1, 1); // bogus region that will get overwritten
	CombineRgn(hrgnNewClip, hrgnCurrentClip, hrgn, fnMode);

	int nRet = ::SelectClipRgn(hdc, hrgnNewClip);

	if(0 == ::DeleteObject(hrgnNewClip))
	{
		return ERROR;
	}

	return nRet;
}

#ifdef DrawIcon
#undef DrawIcon  // The CE headers define this as a macro with parameters, which causes problems.

inline BOOL DrawIcon(
	HDC hDC, 
	int X, 
	int Y, 
	HICON hIcon
)
{
	return DrawIconEx(hDC,X,Y,hIcon,0,0,0,NULL, DI_NORMAL);
}
#endif

#ifndef PS_DOT
#define PS_DOT              2
#endif

inline HPEN CreatePen(
	int nPenStyle, 
	int nWidth, 
	COLORREF crColor
)
{
	LOGPEN logPen;
	
	logPen.lopnStyle   = (nPenStyle == PS_DOT) ? PS_DASH : nPenStyle;
	logPen.lopnWidth.x = (nWidth == 0) ? 1 : nWidth;
	logPen.lopnWidth.y = 1;
	logPen.lopnColor   = crColor;

	return ::CreatePenIndirect(&logPen); 	
}

inline HBRUSH CreateBrushIndirect(const LOGBRUSH* lplb)
{
	HBRUSH hBrush = NULL;

	if (lplb == NULL)
		return hBrush;

	switch (lplb->lbStyle)
	{
		case BS_SOLID:
			hBrush = ::CreateSolidBrush(lplb->lbColor);
			break;
		
		case BS_NULL:
			hBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
			break;

		case BS_DIBPATTERNPT:
			if (lplb->lbColor == DIB_RGB_COLORS)
			{
				hBrush = ::CreateDIBPatternBrushPt((void*)lplb->lbHatch, lplb->lbColor);
			}
			break;

		default:
			break;
	}

	return hBrush;
}

// Unlike RegSetValue, RegSetValueEx won't create the specified (sub)key 
// if it doesn't exist at all. What RegSetValueEx does is to create another 
// value under the specified parent key. 
inline LONG RegSetValue(HKEY hKey, 
	LPCTSTR lpKey, 
	DWORD dwType, 
	LPCTSTR lpData, 
	DWORD cbData)
{
	LONG lResult = ERROR_SUCCESS;
	HKEY hSubKey;

	if((lpKey == NULL) || (*lpKey == _T('\0')))
	{
		return ::RegSetValueEx(hKey, lpKey, 0, dwType, (CONST BYTE*)lpData, cbData);
	}

	lResult = RegOpenKeyEx(hKey, lpKey, 0, 0, &hSubKey);
	if(lResult != ERROR_SUCCESS) 
	{	
		DWORD dwType,dwSize;
		lResult = ::RegQueryValueEx(hKey, lpKey, 0, &dwType, NULL, &dwSize);
		if(lResult == ERROR_SUCCESS) 
		{
			// it's a value, keep it.
			return ::RegSetValueEx(hKey, lpKey, 0, dwType, (CONST BYTE*)lpData, cbData);
		}
		else
		{
			// it's empty, create a key
			DWORD dwDisposition;
			lResult = ::RegCreateKeyEx(hKey, lpKey, 0, NULL, NULL, KEY_ALL_ACCESS, NULL, &hSubKey, &dwDisposition);
			if(lResult != ERROR_SUCCESS)
				return lResult;
		}
	}

	lResult = ::RegSetValueEx(hSubKey, _T(""), 0, dwType, (CONST BYTE*)lpData, cbData);
	::RegCloseKey(hSubKey);

	return lResult;
}

inline int WINAPI lstrlenA(LPCSTR lpszString)
{
	// This function is not safe, per the Windows Platform SDK documentation on lstrlen.
	int iLen = 0;

	if(lpszString != NULL)
	{
		for(LPCSTR lpszCur = lpszString; *lpszCur != '\0'; ++lpszCur, ++iLen)
		{
			// intentionally empty
		}
	}
	
	return iLen;
}

#ifndef lstrcmpA
#define lstrcmpA strcmp
#endif

#ifndef lstrcpyA
#define lstrcpyA strcpy
#endif

#ifdef lstrlenW
#undef lstrlenW
inline size_t __cdecl lstrlenW(const wchar_t *string)
{
	return ((string != NULL) ? ::wcslen(string) : 0);
}
#endif

inline LPWSTR lstrcpynW(LPWSTR lpszString1, LPCWSTR lpszString2, int iMaxLength)
{
	if(iMaxLength <= 0 || lpszString1 == NULL || lpszString2 == NULL)
	{
		return NULL;
	}
	
	::wcsncpy(lpszString1, lpszString2, iMaxLength);
	lpszString1[iMaxLength-1] = '\0';
	
	return lpszString1;
}

#ifndef lstrcpyn
#define lstrcpyn lstrcpynW
#endif

inline int __cdecl wvsprintfW(wchar_t *string, const wchar_t *format, va_list ap)
{
	const size_t maxcount = 1024;
		
	int len = _vsnwprintf(string, maxcount, format, ap);

	// _vsnwprintf returns -1 if buffer is not big enough (or an error occurs)
	if(len < 0)
	{
		// null terminate the string
		// note that maximum size is 1024 characters plus terminating null.
		string[len = maxcount] = 0;
	}

	return len;
}

inline int __cdecl wvsprintfA(char *string, const char *format, va_list ap)
{
	const size_t maxcount = 1024;
		
	int len = _vsnprintf(string, maxcount, format, ap);

	// _vsnprintf returns -1 if buffer is not big enough (or an error occurs)
	if(len < 0)
	{
		// null terminate the string
		// note that maximum size is 1024 characters plus terminating null.
		string[len = maxcount] = 0;
	}

	return len;
}

inline LCID GetThreadLocale(void)
{
	return ::GetSystemDefaultLCID();	
}

#ifdef GetVersion
#undef GetVersion
#endif
inline DWORD GetVersion(void)
{
	OSVERSIONINFO vi;
	ZeroMemory(&vi, sizeof(OSVERSIONINFO));
	vi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	::GetVersionEx(&vi);

	return ((DWORD)(LOBYTE(LOWORD(vi.dwMajorVersion))) |
		(DWORD)(LOBYTE(LOWORD(vi.dwMinorVersion))) << 8 | 
		(DWORD)(LOWORD(vi.dwBuildNumber)) << 16 |
		(vi.dwPlatformId != VER_PLATFORM_WIN32_NT) ? 0x80000000 : 0);
}

inline LPWSTR STDAPICALLTYPE PathFindExtensionW(LPCWSTR pszPath)
{
	if(pszPath == NULL)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return NULL;
	}
	
	LPWSTR pszLastDot = NULL;
	LPWSTR pszCh;
	for(pszCh = const_cast<LPWSTR>(pszPath); *pszCh != L'\0'; ++pszCh)
	{
		if(L'.' == *pszCh)
		{
			pszLastDot = pszCh;
		}
	}

	if(pszLastDot != NULL)
	{
		// Make sure there are no \ or / after the dot, or the . doesn't signify the file extension
		for(LPWSTR pszCh2 = pszCh; pszCh2 == pszLastDot; --pszCh2)
		{
			if(L'\\' == *pszCh || L'/' == *pszCh)
			{
				return pszCh;
			}
		}

		// Return the file extension
		return pszLastDot;
	}
	
	return pszCh;
}

#ifndef PathFindExtension 
#define PathFindExtension PathFindExtensionW
#endif

inline void PathRemoveExtension(LPTSTR pszPath)
{
	if (pszPath == NULL)
	{
		return;
	}

	for (LPTSTR pszCh = pszPath ; *pszCh !=  L'\0' ; ++pszCh)
	{
		if (L'.' == *pszCh)
		{
			*pszCh = L'\0';
			return;
		}
	}
}

inline LPTSTR PathFindFileName(LPCTSTR lpszPathName)
{
	LPTSTR lpszFileName = (LPWSTR)lpszPathName;
	for (LPCTSTR lpsz = lpszPathName; *lpsz != '\0'; lpsz = _wcsinc(lpsz))
	{
		// remember last directory/drive separator
		if (*lpsz == '\\' || *lpsz == '/' || *lpsz == ':')
			lpszFileName = (LPTSTR)_wcsinc(lpsz);
	}

	return lpszFileName;
}

inline LPCWSTR FindFilePart(LPCWSTR pszPath, LPCWSTR& pszEnd)
{
	LPCWSTR pszLastSlash = NULL;
	
	for(pszEnd = pszPath; *pszEnd != L'\0'; ++pszEnd)
	{
		if(L'\\' == *pszEnd || L'/' == *pszEnd)
		{
			pszLastSlash = pszEnd;
		}
	}

	if(pszLastSlash == NULL)
	{
		// No slashes, so path is just a filename
		return pszPath;
	}

	++pszLastSlash;

	if(pszLastSlash != L'\0')
	{
		return pszLastSlash + 1;
	}

	// Only got a path without a filename
	return NULL;
}

// This isn't implemented exactly as for Win32, but it's sufficient the needs of ATL and MFC, 
// which pass in a full path, rather then just a filename without the expectation that
// that the current drive and directory be utilized, since that doesn't exist on WinCE.
inline DWORD WINAPI GetFullPathNameW(
    IN LPCWSTR pszFileName,
    IN DWORD nBufferLength,
    OUT LPWSTR pszBuffer,
    OUT LPWSTR *pszFilePart)
{
	if(pszFileName == NULL || pszBuffer == NULL || pszFilePart == NULL)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return 0;
	}
	
	LPCWSTR pszCh = const_cast<LPWSTR>(pszFileName);
	LPCWSTR pszFilePartTemp = FindFilePart(pszFileName, pszCh);

	if(pszFilePartTemp == NULL)
	{
		return 0;
	}

	// Plus 1 to turn diff into count (pszCh points to null terminator)
	DWORD dwLen = pszCh - pszFileName + 1;
	
	// pszBuffer isn't big enough.  Bail!!!
	if(dwLen > nBufferLength)
	{
		return dwLen;
	}

	::wcsncpy(pszBuffer, pszFileName, dwLen);

	// Everything is fine so return the correct values
	*pszFilePart = pszBuffer + (pszFilePartTemp - pszFileName);

	// Minus one to get count chars, which is the correct value to return
	--dwLen;

	return dwLen;
}

#ifndef GetFullPathName
#define GetFullPathName GetFullPathNameW
#endif

// This isn't implemented exactly as for Win32, but it's sufficient for MFC's needs, 
// which only requires spliting of the filename from the rest of the path
inline short GetFileTitleW(
	LPCWSTR lpszFile,
	LPWSTR lpszTitle,
	WORD cbBuf
)
{
	if(lpszFile == NULL || lpszTitle == NULL)
	{
		::SetLastError(ERROR_INVALID_PARAMETER);
		return -1;
	}

	LPCWSTR pszCh = const_cast<LPWSTR>(lpszFile);
	LPCWSTR pszFilePart = FindFilePart(lpszFile, pszCh);

	if(pszFilePart == NULL)
	{
		return -1;
	}

	// Plus 1 to turn diff into count (pszCh points to null terminator)
	unsigned int uLen = pszCh - pszFilePart + 1;
	
	// lpszTitle isn't big enough.  Bail!!!
	if(uLen > cbBuf)
	{
		// If uLen is to big to be cast to a short, then lpszFile isn't valid,
		// and in that case, this API has an unknown return value.
		return static_cast<short>(uLen);
	}

	::wcsncpy(lpszTitle, pszFilePart, uLen);

	return 0;
}

#ifndef GetFileTitle
#define GetFileTitle GetFileTitleW
#endif

//---------------------------------------------------------------------
// Convert encoded RGB colors to "TRUE" RGB colors.  I.E. where the
// high bit is set, the low word is a SysColor index.  Then, where
// hpal != NULL, convert colors to palette-relative colors.
//---------------------------------------------------------------------
inline HRESULT OleTranslateColor(OLE_COLOR clr, HPALETTE hpal, COLORREF *pcolorref)
{

#ifdef _DEBUG
	if(pcolorref != NULL && ::IsBadWritePtr(pcolorref, sizeof(COLORREF)))
	{
		return ResultFromScode(E_INVALIDARG);
	}
#endif

	switch(clr & (0xff000000^SYS_COLOR_INDEX_FLAG))
	{
	case 0x80000000:
	{
		int syscolor = static_cast<int>(clr & (0xFFFF | SYS_COLOR_INDEX_FLAG));

		if(syscolor < SYS_COLOR_INDEX_FLAG || syscolor >= C_SYS_COLOR_TYPES)
		{
			return ResultFromScode(E_INVALIDARG);
		}

		if(pcolorref != NULL)
		{
			clr = ::GetSysColor(syscolor);
		}
		break;
	}

	case 0x01000000:
	{
		if((clr & (0xffff0000^SYS_COLOR_INDEX_FLAG)) != 0x01000000)
		{
			return ResultFromScode(E_INVALIDARG);
		}
         
		// Check validity of index
		if(hpal != NULL)
		{
			PALETTEENTRY pe;
			// Try to get palette entry; if it fails we assume index is invalid
			if(!::GetPaletteEntries(hpal, (UINT)(clr & 0xffff), 1, &pe))
			{
				return ResultFromScode(E_INVALIDARG);
			}
		}
		break;
	}

	case 0x02000000:
		break;

	case 0:
	{
		if(hpal != NULL)
		{
			clr |= 0x02000000;
		}
		break;
	}

	default:
		return ResultFromScode(E_INVALIDARG);
	}

	if (pcolorref != NULL)
	{
		*pcolorref = clr;
	}

	return NOERROR;
}

inline HFONT CreateFont(
	int nHeight, 
	int nWidth, 
	int nEscapement,
	int nOrientation, 
	int nWeight, 
	BYTE bItalic, 
	BYTE bUnderline,
	BYTE cStrikeOut, 
	BYTE nCharSet, 
	BYTE nOutPrecision,
	BYTE nClipPrecision, 
	BYTE nQuality, 
	BYTE nPitchAndFamily,
	LPCTSTR lpszFacename)
{
	LOGFONT logFont;
	logFont.lfHeight = nHeight;
	logFont.lfWidth = nWidth;
	logFont.lfEscapement = nEscapement;
	logFont.lfOrientation = nOrientation;
	logFont.lfWeight = nWeight;
	logFont.lfItalic = bItalic;
	logFont.lfUnderline = bUnderline;
	logFont.lfStrikeOut = cStrikeOut;
	logFont.lfCharSet = nCharSet;
	logFont.lfOutPrecision = nOutPrecision;
	logFont.lfClipPrecision = nClipPrecision;
	logFont.lfQuality = nQuality;
	logFont.lfPitchAndFamily = nPitchAndFamily;
	::wcsncpy_s(logFont.lfFaceName, _countof(logFont.lfFaceName), lpszFacename, _countof(logFont.lfFaceName));

	return ::CreateFontIndirect(&logFont);
}

inline int FrameRect(
	HDC hdc, 
	const RECT* lprc, 
	HBRUSH hbr)
{
	// Fill a "line-size" rectangle for each edge of the frame, using hbr
	// Note that right/bottom borders not painted by FillRect (or FrameRect)
	RECT rectEdge;

	// Top edge of frame
	if (::SetRect(&rectEdge, lprc->left, lprc->top, lprc->right, lprc->top + 1) == FALSE)
		return FALSE;
	if (::FillRect(hdc, &rectEdge, hbr) == FALSE)
		return FALSE;
	
	// Right edge of frame
	if (::SetRect(&rectEdge, lprc->right - 1, lprc->top, lprc->right, lprc->bottom) == FALSE) 
		return FALSE;
	if (::FillRect(hdc, &rectEdge, hbr) == FALSE)
		return FALSE;

	// Bottom edge of frame
	if (::SetRect(&rectEdge, lprc->left, lprc->bottom - 1, lprc->right, lprc->bottom) == FALSE) 
		return FALSE;
	if (::FillRect(hdc, &rectEdge, hbr) == FALSE)
		return FALSE;

	// Left edge of frame
	if (::SetRect(&rectEdge, lprc->left, lprc->top, lprc->left + 1, lprc->bottom) == FALSE) 
		return FALSE;
	return ::FillRect(hdc, &rectEdge, hbr);
}

#ifndef _OLE32_
__inline int InlineIsEqualGUID(REFGUID rguid1, REFGUID rguid2)
{
   return (
      ((unsigned long *) &rguid1)[0] == ((unsigned long *) &rguid2)[0] &&
      ((unsigned long *) &rguid1)[1] == ((unsigned long *) &rguid2)[1] &&
      ((unsigned long *) &rguid1)[2] == ((unsigned long *) &rguid2)[2] &&
      ((unsigned long *) &rguid1)[3] == ((unsigned long *) &rguid2)[3]);
}
#endif

#include <kfuncs.h>

#define GetCurrentProcessIndex() GetProcessIndexFromID(GetCurrentProcess())

/*

	CePtr's provide encapsulation and manipulation of Windows CE pointers.  

	In CE, the bottom 1 gig of memory is divided into 32 slots of 32 meg each:

		Slot  0, 0x00000000 - 0x01ffffff
		Slot  1, 0x02000000 - 0x03ffffff
		Slot  2, 0x04000000 - 0x05ffffff
		Slot  3, 0x06000000 - 0x07ffffff
			.
			.
			.
		Slot 31, 0x3e000000 - 0x3fffffff
		Slot 32, 0x40000000 - 0x41ffffff


	Note that by laying out the bits of the address carefully, it's possible 
	to determine the slot number.


	Slot 0 and Slot 1 are special.  Slot 0 is reserved for the currently 
	running process.  Slot 1 is reserved for dll's.  All code has to be run in 
	the context of a particular process.  For Slot 0 and Slot 1 addresses, 
	there is no way to determine the associated process by looking at just the 
	bits in the address.

	For other addresses, the slot number uniquely identifies the 
	associated process.  These addresses are often called mapped pointers: 
	their values have been mapped to a particular slot.

	Most applications programmers will never use the details of CE pointers.  
	Pointers will work just like regular C pointers so these routines will not 
	be necessary or particularly useful.  System programmers will need to have 
	some knowledge of how the pointers work however and these routines will be 
	very useful.
	
	System programmers will often need to pass pointers to different processes 
	and deal with pointers that have come in from other processes.
	
	The primary operations on the pointers are:
	
		1.  Encoding the pointer's associated process into the pointer, usually 
		called "mapping the pointer".
		
		2.  Extracting the associated process from a mapped pointer, here called 
		"Unpacking the pointer".


	CePtr's lay out the address so that the bits of the address that 
	correspond to the slot number are easily accessible and modifiable.
	
	Mapping slot 0 addresses is simple: the slot number of the process is set into 
	the appropriate bits of the address.  Mapping slot 1 address is only 
	slightly more complex.  If the incoming address is a slot 1 address, this 
	is remembered by setting a normally unused bit of the address.  The index 
	of the process is then set into the appropriate bits of the address.  
	Addresses in other slots do not need any modifications.  They are already 
	mapped.
	
	Unpacking the mapped pointer is also straightforward.  The OS is queried 
	for the process that corresponds to the index bits of the addres.  Then the 
	dll flag bit is checked.  If the bit is 0, the index of the pointer is set 
	to 0 to form a slot 0 address.  If the bit is 1, the index of the pointer 
	is set to to 1 to form a slot 1 address.

	IMPORTANT: Note that CePtr's are the exact size of C pointers.  This 
	allows them to be passed across processes as regular C pointers.  

*/



class CePtrBase_t
{
private:
	union
		{
		void*				m_Ptr;
		long				m_PtrLong;
		unsigned long		m_PtrUnsignedLong;
		struct
			{
			unsigned int	m_Address		: 25;
			unsigned int	m_ProcessIndex	:  6;
			unsigned int	m_IsDllAddress	:  1;
			};
		};

protected:

	/*
		Default CePtr constructor initializes pointer to 0.
	*/
	CePtrBase_t(
		void
		)
	{
		m_Ptr = 0;
	}


	/*
		Create a CePtr from the raw bits of a C pointer.
	*/
	CePtrBase_t(
		void*	p
		)
	{
		m_Ptr = p;
	}


	/*
		Create a CePtr from the raw bits of an unsigned long.
	*/
	CePtrBase_t(
		unsigned long	l
		)
	{
		m_PtrUnsignedLong = l;
	}



	/*
		Create a CePtr from the raw bits of a long.
	*/
	CePtrBase_t(
		long	l
		)
	{
		m_PtrLong = l;
	}



	/*
		Create a CePtr and map it to the given process.  If the pointer is already 
		mapped, it will not be modified.  If the process handle is 0, the pointer 
		will be mapped to the current process.  
	*/
	CePtrBase_t(
		void*		p,
		HPROCESS	hProcessToMapTo
		)
	{
		m_Ptr = p;
		MapToProcess(hProcessToMapTo);
		return;
	}



	/*
		Unpack the unmapped pointer and process handle from the ceptr.
	*/
	void
	Unpack(
		void**		pUnmapped,
		HPROCESS*	hProcessMappedTo
		) const;


	/*
		Return the pointer as a C++ pointer.
	*/
	void*
	AsCppPtr(
		void
		) const
	{
		return m_Ptr;
	}



public:


	/*
		Map the ceptr to the given process.  If the pointer is already 
		mapped, it will not be modified.  If the process handle is 0, the pointer 
		will be mapped to the current process.  
	*/
	void
	MapToProcess(
		HPROCESS	hProcessToMapTo
		);


	/*
		Maps a pointer to the current process.  See MapToProcess.
	*/
	void
	MapToCurrentProcess(
		void
		)
	{
		MapToProcess(0);
	}


	/*
		Returns true if the pointer is mapped.
	*/
	bool
	IsMapped(
		void
		) const
	{
		return ( m_Ptr == 0 ) ||
			   ( ( m_ProcessIndex != 0 ) && ( m_ProcessIndex != 1 ) );
	}

	bool
	IsMappedOrDll(
		void
		) const
	{
		return IsMapped() || ( m_ProcessIndex == 1 );
	}



	/*
		Returns true if the pointer is mapped.
		Debug version will assert if the pointer is not mapped.
	*/
	bool
	IsMappedAssert(
		void
		) const;


	/*
		Returns true if the pointer is 0.
	*/
	bool
	IsNull(
		void
		) const
	{
		return m_Ptr == 0;
	}


	/*
		Returns the pointer as a long value.
	*/
	long
	AsLong(
		void
		)
	{
		return m_PtrLong;
	}



};


template <class C_t> class CePtr_t : public CePtrBase_t
{
public:

	CePtr_t<C_t>(
		void
		) : CePtrBase_t()
	{
	}


	explicit
	CePtr_t<C_t>(
		C_t	p
		) : CePtrBase_t(p)
	{
	}


	explicit
	CePtr_t<C_t>(
		unsigned long	l
		) : CePtrBase_t(l)
	{
	}



	CePtr_t<C_t>(
		C_t			p,
		HPROCESS	hProcessToMapTo
		) : CePtrBase_t(p, hProcessToMapTo)
	{
	}


	void
	Unpack(
		C_t*		pUnmapped,
		HPROCESS*	phProcessMappedTo
		) const
	{
		CePtrBase_t::Unpack(reinterpret_cast<void**>(pUnmapped), phProcessMappedTo);
	}


	CePtr_t<C_t>&
	MapToProcess(
		HPROCESS	hProcessToMapTo
		)
	{
		CePtrBase_t::MapToProcess(hProcessToMapTo);
		return *this;
	}


	CePtr_t<C_t>&
	MapToCurrentProcess(
		void
		)
	{
		CePtrBase_t::MapToProcess(0);
		return *this;
	}


	C_t
	AsCppPtr(
		void
		) const
	{
		return reinterpret_cast<C_t>(CePtrBase_t::AsCppPtr());
	}



	/*
		Maps the given pointer to the current process.
	*/
	static
	void
	MapToCurrentProcess(
		C_t*	p
		)
	{
		*p = CePtr_t<C_t>(*p,0).AsCppPtr();
		return;
	}



};

inline bool
CePtrBase_t::
IsMappedAssert(
	void
	) const
{
	bool	PtrIsMapped = IsMapped();

	if ( !PtrIsMapped )
		{
		ATLASSERT(0);
		}

	return PtrIsMapped;
}




inline void
CePtrBase_t::
MapToProcess(
	HPROCESS	hProcessToMapTo
	)
{
	if ( IsMapped() )
		{
		//	Pointer is already mapped.  Leave it alone.
		}
	else
		{
		//	Remember if this is a dll address.
		if ( m_ProcessIndex == 1 )
			{
			m_IsDllAddress = 1;
			}

		if ( hProcessToMapTo == 0 )
			{
			m_ProcessIndex = GetCurrentProcessIndex() + 1;
			}
		else
			{
			m_ProcessIndex = GetProcessIndexFromID(hProcessToMapTo) + 1;
			}
		}

	return;
}



inline void
CePtrBase_t::
Unpack(
	void**		pp,
	HPROCESS*	phProcess
	) const
{
	void*		p = 0;
	HPROCESS	hProcess = 0;

	if ( m_Ptr )
		{
		//	Need to make a copy so that we don't destroy the original.
		CePtrBase_t	CePtr(m_Ptr);

		//	Get the process that this pointer originally came from.
		hProcess = GetProcessIDFromIndex(CePtr.m_ProcessIndex - 1);

		//	If the address was a dll address,
		//	set it back to slot 1,
		//	otherwise, set it back to slot 0.
		if ( CePtr.m_IsDllAddress )
			{
			CePtr.m_ProcessIndex = 1;
			CePtr.m_IsDllAddress = 0;
			}
		else
			{
			CePtr.m_ProcessIndex = 0;
			}

		p = CePtr.m_Ptr;
		}

	if ( phProcess )
		{
		*phProcess = hProcess;
		}

	if ( pp )
		{
		*pp = p;
		}

	return;
	
}

// Unpack the mapped WNDPROC/DLGPROC SetWindowLongPtr and GetWindowLongPtr returns so it can be compared to a standard non-mapped pointer
template <class ProcType_t>
inline ProcType_t _UnpackMappedProc(ProcType_t pProc)
{
	HPROCESS hProcess = NULL;
	(CePtr_t<ProcType_t>(pProc)).Unpack(&pProc, &hProcess);
	return pProc;
}

// Map a standard pointer so it can be passed to CallWindowProc
template <class ProcType_t>
inline ProcType_t _MapProc(ProcType_t pProc)
{
	CePtr_t<ProcType_t> pCePtr(pProc);
	pCePtr.MapToCurrentProcess();
	return pCePtr.AsCppPtr();
}

#else // _WIN32_WCE

using ::IsWindowUnicode;
using ::GetScrollPos;
using ::GetScrollRange;
using ::GetTopWindow;
using ::GetLastActivePopup;
using ::ShowScrollBar;
using ::IsMenu;
using ::GetMenu;
using ::GetMenuStringW;

using ::CreatePen;
using ::GetViewportOrgEx;
using ::GetViewportExtEx;
using ::GetWindowOrgEx;
using ::GetWindowExtEx;
using ::DPtoLP;
using ::LPtoDP;
using ::PolyPolygon;
using ::CreateFont;
using ::FrameRect;

using ::RegSetValue;

using ::lstrlenA;
using ::lstrlenW;
using ::wvsprintfW;
using ::wvsprintfA;

using ::GetThreadLocale;

using ::PathFindExtension;
using ::GetFullPathName;

using ::SafeArrayGetVartype;
using ::VarBstrCat;
using ::VarCmp;
using ::VarBstrCmp;
using ::CommandLineToArgvW;

#define _UnpackMappedProc(pProc) (pProc)
#define _IsMappedProc(pProc) (false)

#endif // _WIN32_WCE

} // namespace ATL


#endif	// __ATLOSAPICE_H__

