// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXCOMCTL32_H__
#define __AFXCOMCTL32_H__

#ifdef _AFX_NO_AFXCMN_SUPPORT
	#error Windows Common Control classes not supported in this library variant.
#endif

#pragma once

#pragma warning(disable: 4127)  // conditional expression constant

/////////////////////////////////////////////////////////////////////////////

#if (_WIN32_WINNT >= 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED

HANDLE WINAPI AfxCreateActCtxW(PCACTCTXW pActCtx);
void WINAPI AfxReleaseActCtx(HANDLE hActCtx);
BOOL WINAPI AfxActivateActCtx(HANDLE hActCtx, ULONG_PTR *lpCookie);
BOOL WINAPI AfxDeactivateActCtx(DWORD dwFlags, ULONG_PTR ulCookie);

#else

HANDLE WINAPI AfxCreateActCtxW(void *pActCtx);
void WINAPI AfxReleaseActCtx(HANDLE hActCtx);
BOOL WINAPI AfxActivateActCtx(HANDLE hActCtx, ULONG_PTR *lpCookie);
BOOL WINAPI AfxDeactivateActCtx(DWORD dwFlags, ULONG_PTR ulCookie);

#endif

/////////////////////////////////////////////////////////////////////////////

#pragma push_macro("COMCTL_FUNC")
#pragma push_macro("COMCTL_PROC")

#define PROC_PTR_TYPE(type, name, params) \
	struct name##_Type \
	{ \
		typedef type (WINAPI *Ptr)##params; \
		Ptr p; \
		name##_Type() : p(NULL) {} \
		void operator=(Ptr q) { p = q; } \
		Ptr operator->() { return p; } \
		operator Ptr() { return p; } \
		bool operator!() const { return !p; } \
	}

#define COMCTL_FUNC(type, name, params, args) \
	struct name##_Type \
	{ \
		typedef type (WINAPI *Ptr)##params; \
		Ptr p; \
		name##_Type() : p(NULL) {} \
		void operator=(Ptr q) { p = q; } \
		Ptr operator->() { return p; } \
		operator Ptr() { return p; } \
		bool operator!() const { return !p; } \
	} m__##name; \
	\
	name##_Type GetProcAddress_##name() \
	{ \
		if (!m__##name) \
		{ \
			m__##name = (name##_Type::Ptr) ::GetProcAddress(GetModuleHandle(), _T(#name)); \
		} \
		return m__##name; \
	} \
	\
	type _##name##params \
	{ \
		GetProcAddress_##name(); \
		ENSURE(m__##name != NULL); \
		return m__##name##args; \
	}

#ifndef _WIN32_WCE
#define COMCTL_FUNC2(type, name, params, args) COMCTL_FUNC(type, name, params, args)
#else
#define COMCTL_FUNC2(type, name, params, args) \
	struct name##_Type \
	{ \
		typedef type (WINAPI *Ptr)##params; \
		Ptr p; \
		name##_Type() : p(NULL) {} \
		void operator=(Ptr q) { p = q; } \
		Ptr operator->() { return p; } \
		operator Ptr() { return p; } \
		bool operator!() const { return !p; } \
	} m__##name; \
	\
	name##_Type GetProcAddress_##name() \
	{ \
		if (!m__##name) \
		{ \
			m__##name = (name##_Type::Ptr) ::GetProcAddress(GetModuleHandle2(), _T(#name)); \
		} \
		return m__##name; \
	} \
	\
	type _##name##params \
	{ \
		GetProcAddress_##name(); \
		ENSURE(m__##name != NULL); \
		return m__##name##args; \
	}
#endif // !_WIN32_WCE

#define COMCTL_PROC(name, params, args) \
	struct name##_Type \
	{ \
		typedef void (WINAPI *Ptr)##params; \
		Ptr p; \
		name##_Type() : p(NULL) {} \
		void operator=(Ptr q) { p = q; } \
		Ptr operator->() { return p; } \
		operator Ptr() { return p; } \
		bool operator!() const { return !p; } \
	} m__##name; \
	\
	name##_Type GetProcAddress_##name() \
	{ \
		if (!m__##name) \
		{ \
			m__##name = (name##_Type::Ptr) ::GetProcAddress(GetModuleHandle(), _T(#name)); \
		} \
		return m__##name; \
	} \
	\
	void _##name##params \
	{ \
		GetProcAddress_##name(); \
		ENSURE(m__##name != NULL); \
		m__##name##args; \
	}

#ifndef _WIN32_WCE
#define COMCTL_PROC2(name, params, args) COMCTL_PROC(name, params, args)
#else
#define COMCTL_PROC2(name, params, args) \
	struct name##_Type \
	{ \
		typedef void (WINAPI *Ptr)##params; \
		Ptr p; \
		name##_Type() : p(NULL) {} \
		void operator=(Ptr q) { p = q; } \
		Ptr operator->() { return p; } \
		operator Ptr() { return p; } \
		bool operator!() const { return !p; } \
	} m__##name; \
	\
	name##_Type GetProcAddress_##name() \
	{ \
		if (!m__##name) \
		{ \
			m__##name = (name##_Type::Ptr) ::GetProcAddress(GetModuleHandle2(), _T(#name)); \
		} \
		return m__##name; \
	} \
	\
	void _##name##params \
	{ \
		GetProcAddress_##name(); \
		ENSURE(m__##name != NULL); \
		m__##name##args; \
	}
#endif // !_WIN32_WCE

#define AFX_COMCTL32_IF_EXISTS(proc) (afxComCtlWrapper->GetProcAddress_##proc() != NULL)

#if defined(_UNICODE)
#define AFX_COMCTL32_IF_EXISTS2(proc) (afxComCtlWrapper->GetProcAddress_##proc##W() != NULL)
#else
#define AFX_COMCTL32_IF_EXISTS2(proc) (afxComCtlWrapper->GetProcAddress_##proc##A() != NULL)
#endif

/////////////////////////////////////////////////////////////////////////////

class CComCtlWrapper : public CNoTrackObject
{
	HMODULE m_hModule;
	bool m_bFreeLib;

#ifdef _WIN32_WCE
	HMODULE m_hModule2;
	bool m_bFreeLib2;
#endif // _WIN32_WCE

public:
	HMODULE GetModuleHandle()
	{
		if (m_hModule == NULL)
		{
#ifndef _WIN32_WCE
			m_hModule = ::GetModuleHandle(_T("comctl32.dll"));
#else
			m_hModule = ::GetModuleHandle(_T("commctrl.dll"));
#endif // _WIN32_WCE
			if (m_hModule == NULL)
			{
#ifndef _WIN32_WCE
				m_hModule = ::LoadLibrary(_T("comctl32.dll"));
#else
				m_hModule = ::LoadLibrary(_T("commctrl.dll"));
#endif // _WIN32_WCE
				m_bFreeLib = m_hModule != NULL;
			}
		}
		return m_hModule;
	}

#ifdef _WIN32_WCE
	HMODULE GetModuleHandle2()
	{
		if (m_hModule2 == NULL)
		{
			m_hModule2 = ::GetModuleHandle(_T("coredll.dll"));
			if (m_hModule2 == NULL)
			{
				m_hModule2 = ::LoadLibrary(_T("coredll.dll"));
				m_bFreeLib2 = m_hModule2 != NULL;
			}
		}
		return m_hModule2;
	}
#endif // _WIN32_WCE

public:
	CComCtlWrapper() : 
		m_hModule(NULL), m_bFreeLib(false)
#ifdef _WIN32_WCE
		, m_hModule2(NULL), m_bFreeLib2(false) 
#endif // _WIN32_WCE
		{}

	virtual ~CComCtlWrapper()
	{ 
		m_bFreeLib && ::FreeLibrary(m_hModule);
#ifdef _WIN32_WCE
		m_bFreeLib2 && ::FreeLibrary(m_hModule2);
#endif // _WIN32_WCE
	}

public:
	COMCTL_PROC(InitCommonControls, (), ())
	COMCTL_FUNC(BOOL, InitCommonControlsEx, (LPINITCOMMONCONTROLSEX unnamed1), (unnamed1))
	COMCTL_FUNC2(HIMAGELIST, ImageList_Create, (int cx,int cy,UINT flags,int cInitial,int cGrow), (cx,cy,flags,cInitial,cGrow))
	COMCTL_FUNC2(BOOL, ImageList_Destroy, (HIMAGELIST himl), (himl))
	COMCTL_FUNC2(int, ImageList_GetImageCount, (HIMAGELIST himl), (himl))
	COMCTL_FUNC2(BOOL, ImageList_SetImageCount, (HIMAGELIST himl,UINT uNewCount), (himl,uNewCount))
	COMCTL_FUNC2(int, ImageList_Add, (HIMAGELIST himl,HBITMAP hbmImage,HBITMAP hbmMask), (himl,hbmImage,hbmMask))
	COMCTL_FUNC2(int, ImageList_ReplaceIcon, (HIMAGELIST himl,int i,HICON hicon), (himl,i,hicon))
	COMCTL_FUNC2(COLORREF, ImageList_SetBkColor, (HIMAGELIST himl,COLORREF clrBk), (himl,clrBk))
	COMCTL_FUNC2(COLORREF, ImageList_GetBkColor, (HIMAGELIST himl), (himl))
	COMCTL_FUNC2(BOOL, ImageList_SetOverlayImage, (HIMAGELIST himl,int iImage,int iOverlay), (himl,iImage,iOverlay))
	COMCTL_FUNC2(BOOL, ImageList_Draw, (HIMAGELIST himl,int i,HDC hdcDst,int x,int y,UINT fStyle), (himl,i,hdcDst,x,y,fStyle))
	COMCTL_FUNC2(BOOL, ImageList_Replace, (HIMAGELIST himl,int i,HBITMAP hbmImage,HBITMAP hbmMask), (himl,i,hbmImage,hbmMask))
	COMCTL_FUNC2(int, ImageList_AddMasked, (HIMAGELIST himl,HBITMAP hbmImage,COLORREF crMask), (himl,hbmImage,crMask))
	COMCTL_FUNC2(BOOL, ImageList_DrawEx, (HIMAGELIST himl,int i,HDC hdcDst,int x,int y,int dx,int dy,COLORREF rgbBk,COLORREF rgbFg,UINT fStyle), (himl,i,hdcDst,x,y,dx,dy,rgbBk,rgbFg,fStyle))
	COMCTL_FUNC2(BOOL, ImageList_DrawIndirect, (IMAGELISTDRAWPARAMS*pimldp), (pimldp))
	COMCTL_FUNC2(BOOL, ImageList_Remove, (HIMAGELIST himl,int i), (himl,i))
	COMCTL_FUNC2(HICON, ImageList_GetIcon, (HIMAGELIST himl,int i,UINT flags), (himl,i,flags))
#ifndef _WIN32_WCE
	COMCTL_FUNC2(HIMAGELIST, ImageList_LoadImageA, (HINSTANCE hi,LPCSTR lpbmp,int cx,int cGrow,COLORREF crMask,UINT uType,UINT uFlags), (hi,lpbmp,cx,cGrow,crMask,uType,uFlags))
	COMCTL_FUNC2(HIMAGELIST, ImageList_LoadImageW, (HINSTANCE hi,LPCWSTR lpbmp,int cx,int cGrow,COLORREF crMask,UINT uType,UINT uFlags), (hi,lpbmp,cx,cGrow,crMask,uType,uFlags))
#else
	COMCTL_FUNC2(HIMAGELIST, ImageList_LoadImage, (HINSTANCE hi,LPCTSTR lpbmp,int cx,int cGrow,COLORREF crMask,UINT uType,UINT uFlags), (hi,lpbmp,cx,cGrow,crMask,uType,uFlags))
#endif // !_WIN32_WCE
	COMCTL_FUNC2(BOOL, ImageList_Copy, (HIMAGELIST himlDst,int iDst,HIMAGELIST himlSrc,int iSrc,UINT uFlags), (himlDst,iDst,himlSrc,iSrc,uFlags))
	COMCTL_FUNC2(BOOL, ImageList_BeginDrag, (HIMAGELIST himlTrack,int iTrack,int dxHotspot,int dyHotspot), (himlTrack,iTrack,dxHotspot,dyHotspot))
	COMCTL_PROC2(ImageList_EndDrag, (), ())
	COMCTL_FUNC2(BOOL, ImageList_DragEnter, (HWND hwndLock,int x,int y), (hwndLock,x,y))
	COMCTL_FUNC2(BOOL, ImageList_DragLeave, (HWND hwndLock), (hwndLock))
	COMCTL_FUNC2(BOOL, ImageList_DragMove, (int x,int y), (x,y))
	COMCTL_FUNC2(BOOL, ImageList_SetDragCursorImage, (HIMAGELIST himlDrag,int iDrag,int dxHotspot,int dyHotspot), (himlDrag,iDrag,dxHotspot,dyHotspot))
	COMCTL_FUNC2(BOOL, ImageList_DragShowNolock, (BOOL fShow), (fShow))
	COMCTL_FUNC2(HIMAGELIST, ImageList_GetDragImage, (POINT*ppt,POINT*pptHotspot), (ppt,pptHotspot))
#ifndef _WIN32_WCE
	COMCTL_FUNC2(HIMAGELIST, ImageList_Read, (IStream *pstm), (pstm))
	COMCTL_FUNC2(BOOL, ImageList_Write, (HIMAGELIST himl,IStream *pstm), (himl,pstm))
	
	COMCTL_FUNC2(HRESULT, ImageList_ReadEx, (DWORD dwFlags,IStream *pstm,REFIID riid,PVOID*ppv), (dwFlags,pstm,riid,ppv))
	COMCTL_FUNC2(HRESULT, ImageList_WriteEx, (HIMAGELIST himl,DWORD dwFlags,IStream *pstm), (himl,dwFlags,pstm))
#endif // !_WIN32_WCE
	COMCTL_FUNC2(BOOL, ImageList_GetIconSize, (HIMAGELIST himl,int*cx,int*cy), (himl,cx,cy))
	COMCTL_FUNC2(BOOL, ImageList_SetIconSize, (HIMAGELIST himl,int cx,int cy), (himl,cx,cy))
	COMCTL_FUNC2(BOOL, ImageList_GetImageInfo, (HIMAGELIST himl,int i,IMAGEINFO*pImageInfo), (himl,i,pImageInfo))
	COMCTL_FUNC2(HIMAGELIST, ImageList_Merge, (HIMAGELIST himl1,int i1,HIMAGELIST himl2,int i2,int dx,int dy), (himl1,i1,himl2,i2,dx,dy))
	COMCTL_FUNC2(HIMAGELIST, ImageList_Duplicate, (HIMAGELIST himl), (himl))

	COMCTL_FUNC(HWND, CreateToolbarEx, (HWND hwnd,DWORD ws,UINT wID,int nBitmaps,HINSTANCE hBMInst,UINT_PTR wBMID,LPCTBBUTTON lpButtons,int iNumButtons,int dxButton,int dyButton,int dxBitmap,int dyBitmap,UINT uStructSize), (hwnd,ws,wID,nBitmaps,hBMInst,wBMID,lpButtons,iNumButtons,dxButton,dyButton,dxBitmap,dyBitmap,uStructSize))
#ifndef _WIN32_WCE // LPCOLORMAP
	COMCTL_FUNC(HBITMAP, CreateMappedBitmap, (HINSTANCE hInstance,INT_PTR idBitmap,UINT wFlags,LPCOLORMAP lpColorMap,int iNumMaps), (hInstance,idBitmap,wFlags,lpColorMap,iNumMaps))
#endif // !_WIN32_WCE
	COMCTL_PROC(DrawStatusTextA, (HDC hDC,LPRECT lprc,LPCSTR pszText,UINT uFlags), (hDC,lprc,pszText,uFlags))
	COMCTL_PROC(DrawStatusTextW, (HDC hDC,LPRECT lprc,LPCWSTR pszText,UINT uFlags), (hDC,lprc,pszText,uFlags))
	COMCTL_FUNC(HWND, CreateStatusWindowA, (long style,LPCSTR lpszText,HWND hwndParent,UINT wID), (style,lpszText,hwndParent,wID))
	COMCTL_FUNC(HWND, CreateStatusWindowW, (long style,LPCWSTR lpszText,HWND hwndParent,UINT wID), (style,lpszText,hwndParent,wID))
#ifndef _WIN32_WCE
	COMCTL_PROC(MenuHelp, (UINT uMsg,WPARAM wParam,LPARAM lParam,HMENU hMainMenu,HINSTANCE hInst,HWND hwndStatus,UINT*lpwIDs), (uMsg,wParam,lParam,hMainMenu,hInst,hwndStatus,lpwIDs))
	COMCTL_FUNC(BOOL, ShowHideMenuCtl, (HWND hWnd,UINT_PTR uFlags,LPINT lpInfo), (hWnd,uFlags,lpInfo))
	COMCTL_PROC(GetEffectiveClientRect, (HWND hWnd,LPRECT lprc,LPINT lpInfo), (hWnd,lprc,lpInfo))
	COMCTL_FUNC(BOOL, MakeDragList, (HWND hLB), (hLB))
	COMCTL_PROC(DrawInsert, (HWND handParent,HWND hLB,int nItem), (handParent,hLB,nItem))
	COMCTL_FUNC(int, LBItemFromPt, (HWND hLB,POINT pt,BOOL bAutoScroll), (hLB,pt,bAutoScroll))
#endif // !_WIN32_WCE
	COMCTL_FUNC(HWND, CreateUpDownControl, (DWORD dwStyle,int x,int y,int cx,int cy,HWND hParent,int nID,HINSTANCE hInst,HWND hBuddy,int nUpper,int nLower,int nPos), (dwStyle,x,y,cx,cy,hParent,nID,hInst,hBuddy,nUpper,nLower,nPos))
#ifndef _WIN32_WCE
	COMCTL_PROC(InitMUILanguage, (LANGID uiLang), (uiLang))
	COMCTL_FUNC(LANGID, GetMUILanguage, (), ())
#endif // !_WIN32_WCE
#ifndef _WIN32_WCE // HDSA and HDPA
	COMCTL_FUNC(HDSA, DSA_Create, (int cbItem,int cItemGrow), (cbItem,cItemGrow))
	COMCTL_FUNC(BOOL, DSA_Destroy, (HDSA hdsa), (hdsa))
	COMCTL_PROC(DSA_DestroyCallback, (HDSA hdsa,PFNDSAENUMCALLBACK pfnCB,void*pData), (hdsa,pfnCB,pData))
	COMCTL_FUNC(PVOID, DSA_GetItemPtr, (HDSA hdsa,int i), (hdsa,i))
	COMCTL_FUNC(int, DSA_InsertItem, (HDSA hdsa,int i,void*pitem), (hdsa,i,pitem))
	COMCTL_FUNC(HDPA, DPA_Create, (int cItemGrow), (cItemGrow))
	COMCTL_FUNC(BOOL, DPA_Destroy, (HDPA hdpa), (hdpa))
	COMCTL_FUNC(PVOID, DPA_DeletePtr, (HDPA hdpa,int i), (hdpa,i))
	COMCTL_FUNC(BOOL, DPA_DeleteAllPtrs, (HDPA hdpa), (hdpa))
	COMCTL_PROC(DPA_EnumCallback, (HDPA hdpa,PFNDPAENUMCALLBACK pfnCB,void*pData), (hdpa,pfnCB,pData))
	COMCTL_PROC(DPA_DestroyCallback, (HDPA hdpa,PFNDPAENUMCALLBACK pfnCB,void*pData), (hdpa,pfnCB,pData))
	COMCTL_FUNC(BOOL, DPA_SetPtr, (HDPA hdpa,int i,void*p), (hdpa,i,p))
	COMCTL_FUNC(int, DPA_InsertPtr, (HDPA hdpa,int i,void*p), (hdpa,i,p))
	COMCTL_FUNC(PVOID, DPA_GetPtr, (HDPA hdpa,INT_PTR i), (hdpa,i))
	COMCTL_FUNC(BOOL, DPA_Sort, (HDPA hdpa,PFNDPACOMPARE pfnCompare,LPARAM lParam), (hdpa,pfnCompare,lParam))
	COMCTL_FUNC(int, DPA_Search, (HDPA hdpa,void*pFind,int iStart,PFNDPACOMPARE pfnCompare,LPARAM lParam,UINT options), (hdpa,pFind,iStart,pfnCompare,lParam,options))
#endif // !_WIN32_WCE
	COMCTL_FUNC(BOOL, Str_SetPtrW, (LPWSTR*ppsz,LPCWSTR psz), (ppsz,psz))
	
#ifndef _WIN32_WCE // LPTRACKMOUSEEVENT
	COMCTL_FUNC(BOOL, _TrackMouseEvent, (LPTRACKMOUSEEVENT lpEventTrack), (lpEventTrack))
#endif // !_WIN32_WCE
	
#ifndef _WIN32_WCE
	COMCTL_FUNC(BOOL, FlatSB_EnableScrollBar, (HWND unnamed1,int unnamed2,UINT unnamed3), (unnamed1,unnamed2,unnamed3))
	COMCTL_FUNC(BOOL, FlatSB_ShowScrollBar, (HWND unnamed1,int code,BOOL unnamed2), (unnamed1,code,unnamed2))
	COMCTL_FUNC(BOOL, FlatSB_GetScrollRange, (HWND unnamed1,int code,LPINT unnamed2,LPINT unnamed3), (unnamed1,code,unnamed2,unnamed3))
	COMCTL_FUNC(BOOL, FlatSB_GetScrollInfo, (HWND unnamed1,int code,LPSCROLLINFO unnamed2), (unnamed1,code,unnamed2))
	COMCTL_FUNC(int, FlatSB_GetScrollPos, (HWND unnamed1,int code), (unnamed1,code))
	COMCTL_FUNC(BOOL, FlatSB_GetScrollProp, (HWND unnamed1,int propIndex,LPINT unnamed2), (unnamed1,propIndex,unnamed2))
	COMCTL_FUNC(BOOL, FlatSB_GetScrollPropPtr, (HWND unnamed1,int propIndex,PINT_PTR unnamed2), (unnamed1,propIndex,unnamed2))
	COMCTL_FUNC(int, FlatSB_SetScrollPos, (HWND unnamed1,int code,int pos,BOOL fRedraw), (unnamed1,code,pos,fRedraw))
	COMCTL_FUNC(int, FlatSB_SetScrollInfo, (HWND unnamed1,int code,LPSCROLLINFO unnamed2,BOOL fRedraw), (unnamed1,code,unnamed2,fRedraw))
	COMCTL_FUNC(int, FlatSB_SetScrollRange, (HWND unnamed1,int code,int min,int max,BOOL fRedraw), (unnamed1,code,min,max,fRedraw))
	COMCTL_FUNC(BOOL, FlatSB_SetScrollProp, (HWND unnamed1,UINT index,INT_PTR newValue,BOOL unnamed2), (unnamed1,index,newValue,unnamed2))
	COMCTL_FUNC(BOOL, InitializeFlatSB, (HWND unnamed1), (unnamed1))
	COMCTL_FUNC(HRESULT, UninitializeFlatSB, (HWND unnamed1), (unnamed1))

	typedef LRESULT (CALLBACK *SUBCLASSPROC)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);

	COMCTL_FUNC(BOOL, SetWindowSubclass, (HWND hWnd,SUBCLASSPROC pfnSubclass,UINT_PTR uIdSubclass,DWORD_PTR dwRefData), (hWnd,pfnSubclass,uIdSubclass,dwRefData))
	COMCTL_FUNC(BOOL, GetWindowSubclass, (HWND hWnd,SUBCLASSPROC pfnSubclass,UINT_PTR uIdSubclass,DWORD_PTR*pdwRefData), (hWnd,pfnSubclass,uIdSubclass,pdwRefData))
	COMCTL_FUNC(BOOL, RemoveWindowSubclass, (HWND hWnd,SUBCLASSPROC pfnSubclass,UINT_PTR uIdSubclass), (hWnd,pfnSubclass,uIdSubclass))
	
	COMCTL_FUNC(LRESULT, DefSubclassProc, (HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam), (hWnd,uMsg,wParam,lParam))
	COMCTL_FUNC(int, DrawShadowText, (HDC hdc,LPCWSTR pszText,UINT cch,RECT*prc,DWORD dwFlags,COLORREF crText,COLORREF crShadow,int ixOffset,int iyOffset), (hdc,pszText,cch,prc,dwFlags,crText,crShadow,ixOffset,iyOffset))
#endif // !_WIN32_WCE

	COMCTL_FUNC(HPROPSHEETPAGE, CreatePropertySheetPageA, (LPCPROPSHEETPAGEA constPropSheetPagePointer), (constPropSheetPagePointer))
	COMCTL_FUNC(HPROPSHEETPAGE, CreatePropertySheetPageW, (LPCPROPSHEETPAGEW constPropSheetPagePointer), (constPropSheetPagePointer))
	COMCTL_FUNC(BOOL, DestroyPropertySheetPage, (HPROPSHEETPAGE unnamed1), (unnamed1))
	COMCTL_FUNC(INT_PTR, PropertySheetA, (LPCPROPSHEETHEADERA unnamed1), (unnamed1))
	COMCTL_FUNC(INT_PTR, PropertySheetW, (LPCPROPSHEETHEADERW unnamed1), (unnamed1))
};

/////////////////////////////////////////////////////////////////////////////

#pragma pop_macro("COMCTL_FUNC")
#pragma pop_macro("COMCTL_PROC")

/////////////////////////////////////////////////////////////////////////////

#ifdef _UNICODE
#define AfxCreateStatusWindow AfxCreateStatusWindowW
#define AfxDrawStatusText AfxDrawStatusTextW
#ifndef _WIN32_WCE
#define AfxImageList_LoadImage AfxImageList_LoadImageW
#endif // !_WIN32_WCE
#define AfxCreatePropertySheetPage AfxCreatePropertySheetPageW
#define AfxPropertySheet AfxPropertySheetW
#else
#define AfxCreateStatusWindow AfxCreateStatusWindowA
#define AfxDrawStatusText AfxDrawStatusTextA
#define AfxImageList_LoadImage AfxImageList_LoadImageA
#define AfxCreatePropertySheetPage AfxCreatePropertySheetPageA
#define AfxPropertySheet AfxPropertySheetA
#endif

#define AfxImageList_RemoveAll(himl) AfxImageList_Remove(himl, -1)
#define AfxImageList_ExtractIcon(hi, himl, i) AfxImageList_GetIcon(himl, i, 0)
#define AfxImageList_LoadBitmap(hi, lpbmp, cx, cGrow, crMask) AfxImageList_LoadImage(hi, lpbmp, cx, cGrow, crMask, IMAGE_BITMAP, 0)
#define AfxImageList_AddIcon(himl, hicon) AfxImageList_ReplaceIcon(himl, -1, hicon)

/////////////////////////////////////////////////////////////////////////////

#ifdef _WIN32_WCE
#define AfxCtxGetOpenFileName GetOpenFileName
#define AfxCtxGetSaveFileName GetSaveFileName
#define AfxCtxGetFileTitle	  GetFileTitle
#define AfxCtxChooseColor	  ChooseColor
#define AfxCtxFindText		  FindText
#define AfxCtxReplaceText	  ReplaceText
#define AfxCtxChooseFont	  ChooseFont
#define AfxCtxPrintDlg		  PrintDlgW
#define AfxCtxCommDlgExtendedError CommDlgExtendedErrorW
#define AfxCtxPageSetupDlg	  PageSetupDlgW
#define AfxCtxPrintDlgEx	  PrintDlgExW

#define AfxCtxLoadLibrary LoadLibraryW
#define AfxCtxLoadLibraryEx LoadLibraryExW
#define AfxCtxRegisterClass   RegisterClassW
#define AfxCtxUnregisterClass UnregisterClassW
#define AfxCtxGetClassInfo   GetClassInfoW
#define AfxCtxRegisterClassEx RegisterClassExW
#define AfxCtxGetClassInfoEx GetClassInfoExW
#define AfxCtxCreateWindowEx CreateWindowExW
#define AfxCtxCreateDialogParam CreateDialogParamW
#define AfxCtxCreateDialogIndirectParam CreateDialogIndirectParamW
#define AfxCtxDialogBoxParam DialogBoxParamW
#define AfxCtxDialogBoxIndirectParam DialogBoxIndirectParamW
#define AfxCtxMessageBox MessageBoxW
#define AfxCtxMessageBoxEx MessageBoxExW
#define AfxCtxMessageBoxIndirect MessageBoxIndirectW
#endif // _WIN32_WCE

#endif // __AFXCOMCTL32_H__
