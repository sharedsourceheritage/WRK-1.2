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

#ifdef _DEBUG       // entire file for debugging


#ifndef _WIN32_WCE
#include "dde.h"
#endif // !_WIN32_WCE


/////////////////////////////////////////////////////////////////////////////
// Build data tables by including data file three times

struct AFX_MAP_MESSAGE
{
	UINT    nMsg;
	LPCSTR  lpszMsg;
};

#define DEFINE_MESSAGE(wm)  { wm, #wm }

static const AFX_MAP_MESSAGE allMessages[] =
{
	DEFINE_MESSAGE(WM_CREATE),
	DEFINE_MESSAGE(WM_DESTROY),
	DEFINE_MESSAGE(WM_MOVE),
	DEFINE_MESSAGE(WM_SIZE),
	DEFINE_MESSAGE(WM_ACTIVATE),
	DEFINE_MESSAGE(WM_SETFOCUS),
	DEFINE_MESSAGE(WM_KILLFOCUS),
	DEFINE_MESSAGE(WM_ENABLE),
	DEFINE_MESSAGE(WM_SETREDRAW),
	DEFINE_MESSAGE(WM_SETTEXT),
	DEFINE_MESSAGE(WM_GETTEXT),
	DEFINE_MESSAGE(WM_GETTEXTLENGTH),
	DEFINE_MESSAGE(WM_PAINT),
	DEFINE_MESSAGE(WM_CLOSE),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_QUERYENDSESSION),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_QUIT),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_QUERYOPEN),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_ERASEBKGND),
	DEFINE_MESSAGE(WM_SYSCOLORCHANGE),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_ENDSESSION),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_SHOWWINDOW),
	DEFINE_MESSAGE(WM_CTLCOLORMSGBOX),
	DEFINE_MESSAGE(WM_CTLCOLOREDIT),
	DEFINE_MESSAGE(WM_CTLCOLORLISTBOX),
	DEFINE_MESSAGE(WM_CTLCOLORBTN),
	DEFINE_MESSAGE(WM_CTLCOLORDLG),
	DEFINE_MESSAGE(WM_CTLCOLORSCROLLBAR),
	DEFINE_MESSAGE(WM_CTLCOLORSTATIC),
	DEFINE_MESSAGE(WM_WININICHANGE),
	DEFINE_MESSAGE(WM_SETTINGCHANGE),
#ifndef _AFX_NO_PRINTING_SUPPORT
	DEFINE_MESSAGE(WM_DEVMODECHANGE),
#endif // !_AFX_NO_PRINTING_SUPPORT
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_ACTIVATEAPP),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_FONTCHANGE),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_TIMECHANGE),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_CANCELMODE),
	DEFINE_MESSAGE(WM_SETCURSOR),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_MOUSEACTIVATE),
	DEFINE_MESSAGE(WM_CHILDACTIVATE),
	DEFINE_MESSAGE(WM_QUEUESYNC),
	DEFINE_MESSAGE(WM_GETMINMAXINFO),
	DEFINE_MESSAGE(WM_ICONERASEBKGND),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_NEXTDLGCTL),
#ifndef _AFX_NO_PRINTING_SUPPORT
	DEFINE_MESSAGE(WM_SPOOLERSTATUS),
#endif // !_AFX_NO_PRINTING_SUPPORT
	DEFINE_MESSAGE(WM_DRAWITEM),
	DEFINE_MESSAGE(WM_MEASUREITEM),
	DEFINE_MESSAGE(WM_DELETEITEM),
	DEFINE_MESSAGE(WM_VKEYTOITEM),
	DEFINE_MESSAGE(WM_CHARTOITEM),
	DEFINE_MESSAGE(WM_SETFONT),
	DEFINE_MESSAGE(WM_GETFONT),
	DEFINE_MESSAGE(WM_QUERYDRAGICON),
	DEFINE_MESSAGE(WM_COMPAREITEM),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_COMPACTING),
	DEFINE_MESSAGE(WM_NCCREATE),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_NCDESTROY),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_NCCALCSIZE),
	DEFINE_MESSAGE(WM_NCHITTEST),
	DEFINE_MESSAGE(WM_NCPAINT),
	DEFINE_MESSAGE(WM_NCACTIVATE),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_GETDLGCODE),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_NCMOUSEMOVE),
	DEFINE_MESSAGE(WM_NCLBUTTONDOWN),
	DEFINE_MESSAGE(WM_NCLBUTTONUP),
	DEFINE_MESSAGE(WM_NCLBUTTONDBLCLK),
	DEFINE_MESSAGE(WM_NCRBUTTONDOWN),
	DEFINE_MESSAGE(WM_NCRBUTTONUP),
	DEFINE_MESSAGE(WM_NCRBUTTONDBLCLK),
	DEFINE_MESSAGE(WM_NCMBUTTONDOWN),
	DEFINE_MESSAGE(WM_NCMBUTTONUP),
	DEFINE_MESSAGE(WM_NCMBUTTONDBLCLK),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_KEYDOWN),
	DEFINE_MESSAGE(WM_KEYUP),
	DEFINE_MESSAGE(WM_CHAR),
	DEFINE_MESSAGE(WM_DEADCHAR),
	DEFINE_MESSAGE(WM_SYSKEYDOWN),
	DEFINE_MESSAGE(WM_SYSKEYUP),
	DEFINE_MESSAGE(WM_SYSCHAR),
	DEFINE_MESSAGE(WM_SYSDEADCHAR),
	DEFINE_MESSAGE(WM_KEYLAST),
	DEFINE_MESSAGE(WM_INITDIALOG),
	DEFINE_MESSAGE(WM_COMMAND),
	DEFINE_MESSAGE(WM_SYSCOMMAND),
	DEFINE_MESSAGE(WM_TIMER),
	DEFINE_MESSAGE(WM_HSCROLL),
	DEFINE_MESSAGE(WM_VSCROLL),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_INITMENU),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_INITMENUPOPUP),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_MENUSELECT),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_MENUCHAR),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_ENTERIDLE),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_MOUSEWHEEL),
	DEFINE_MESSAGE(WM_MOUSEMOVE),
	DEFINE_MESSAGE(WM_LBUTTONDOWN),
	DEFINE_MESSAGE(WM_LBUTTONUP),
	DEFINE_MESSAGE(WM_LBUTTONDBLCLK),
	DEFINE_MESSAGE(WM_RBUTTONDOWN),
	DEFINE_MESSAGE(WM_RBUTTONUP),
	DEFINE_MESSAGE(WM_RBUTTONDBLCLK),
	DEFINE_MESSAGE(WM_MBUTTONDOWN),
	DEFINE_MESSAGE(WM_MBUTTONUP),
	DEFINE_MESSAGE(WM_MBUTTONDBLCLK),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_PARENTNOTIFY),
	DEFINE_MESSAGE(WM_MDICREATE),
	DEFINE_MESSAGE(WM_MDIDESTROY),
	DEFINE_MESSAGE(WM_MDIACTIVATE),
	DEFINE_MESSAGE(WM_MDIRESTORE),
	DEFINE_MESSAGE(WM_MDINEXT),
	DEFINE_MESSAGE(WM_MDIMAXIMIZE),
	DEFINE_MESSAGE(WM_MDITILE),
	DEFINE_MESSAGE(WM_MDICASCADE),
	DEFINE_MESSAGE(WM_MDIICONARRANGE),
	DEFINE_MESSAGE(WM_MDIGETACTIVE),
	DEFINE_MESSAGE(WM_MDISETMENU),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_CUT),
	DEFINE_MESSAGE(WM_COPYDATA),
	DEFINE_MESSAGE(WM_COPY),
	DEFINE_MESSAGE(WM_PASTE),
	DEFINE_MESSAGE(WM_CLEAR),
	DEFINE_MESSAGE(WM_UNDO),
	DEFINE_MESSAGE(WM_RENDERFORMAT),
	DEFINE_MESSAGE(WM_RENDERALLFORMATS),
	DEFINE_MESSAGE(WM_DESTROYCLIPBOARD),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_DRAWCLIPBOARD),
	DEFINE_MESSAGE(WM_PAINTCLIPBOARD),
	DEFINE_MESSAGE(WM_VSCROLLCLIPBOARD),
	DEFINE_MESSAGE(WM_SIZECLIPBOARD),
	DEFINE_MESSAGE(WM_ASKCBFORMATNAME),
	DEFINE_MESSAGE(WM_CHANGECBCHAIN),
	DEFINE_MESSAGE(WM_HSCROLLCLIPBOARD),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_QUERYNEWPALETTE),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_PALETTEISCHANGING),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_PALETTECHANGED),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_DDE_INITIATE),
	DEFINE_MESSAGE(WM_DDE_TERMINATE),
	DEFINE_MESSAGE(WM_DDE_ADVISE),
	DEFINE_MESSAGE(WM_DDE_UNADVISE),
	DEFINE_MESSAGE(WM_DDE_ACK),
	DEFINE_MESSAGE(WM_DDE_DATA),
	DEFINE_MESSAGE(WM_DDE_REQUEST),
	DEFINE_MESSAGE(WM_DDE_POKE),
	DEFINE_MESSAGE(WM_DDE_EXECUTE),
	DEFINE_MESSAGE(WM_DROPFILES),
	DEFINE_MESSAGE(WM_POWER),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_WINDOWPOSCHANGED),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_WINDOWPOSCHANGING),
#endif // !_WIN32_WCE
#ifdef _WIN32_WCE
	DEFINE_MESSAGE(WM_HIBERNATE),
#endif // _WIN32_WCE
// MFC specific messages
	DEFINE_MESSAGE(WM_SIZEPARENT),
	DEFINE_MESSAGE(WM_SETMESSAGESTRING),
	DEFINE_MESSAGE(WM_IDLEUPDATECMDUI),
	DEFINE_MESSAGE(WM_INITIALUPDATE),
	DEFINE_MESSAGE(WM_COMMANDHELP),
	DEFINE_MESSAGE(WM_HELPHITTEST),
	DEFINE_MESSAGE(WM_EXITHELPMODE),
	DEFINE_MESSAGE(WM_HELP),
	DEFINE_MESSAGE(WM_NOTIFY),
	DEFINE_MESSAGE(WM_CONTEXTMENU),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_TCARD),
	DEFINE_MESSAGE(WM_MDIREFRESHMENU),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_STYLECHANGED),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_STYLECHANGING),
	DEFINE_MESSAGE(WM_SETHOTKEY),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_PRINT),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_PRINTCLIENT),
	DEFINE_MESSAGE(WM_POWERBROADCAST),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_HOTKEY),
	DEFINE_MESSAGE(WM_GETICON),
	DEFINE_MESSAGE(WM_EXITMENULOOP),
	DEFINE_MESSAGE(WM_ENTERMENULOOP),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_DISPLAYCHANGE),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_GETICON),
	DEFINE_MESSAGE(WM_SETICON),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_SIZING),
	DEFINE_MESSAGE(WM_MOVING),
#endif // !_WIN32_WCE
	DEFINE_MESSAGE(WM_CAPTURECHANGED),
#ifndef _WIN32_WCE
	DEFINE_MESSAGE(WM_DEVICECHANGE),
#endif // !_WIN32_WCE
	{ 0, NULL, }    // end of message list
};

#undef DEFINE_MESSAGE

#ifndef _WIN32_WCE
/////////////////////////////////////////////////////////////////////////////
// DDE special case

static void AFXAPI TraceDDE(LPCTSTR lpszPrefix, const MSG* pMsg)
{
	ENSURE_ARG(pMsg != NULL);
	if (pMsg->message == WM_DDE_EXECUTE)
	{
		UINT_PTR nDummy;
		HGLOBAL hCommands;
		if (!UnpackDDElParam(WM_DDE_EXECUTE, pMsg->lParam,
			&nDummy, (UINT_PTR*)&hCommands))
		{
			TRACE(traceAppMsg, 0, "Warning: Unable to unpack WM_DDE_EXECUTE lParam %08lX.\n",
				pMsg->lParam);
			return;
		}
		ASSERT(hCommands != NULL);

		LPCTSTR lpszCommands = (LPCTSTR)::GlobalLock(hCommands);
		ENSURE_THROW(lpszCommands != NULL, ::AfxThrowMemoryException() );
		TRACE(traceAppMsg, 0, _T("%s: Execute '%s'.\n"), lpszPrefix, lpszCommands);
		::GlobalUnlock(hCommands);
	}
	else if (pMsg->message == WM_DDE_ADVISE)
	{
		UINT_PTR nItem;
		ATOM aItem;
		HGLOBAL hAdvise;
		if (!UnpackDDElParam(WM_DDE_ADVISE, pMsg->lParam,
			(UINT_PTR*)&hAdvise, &nItem))
		{
			TRACE(traceAppMsg, 0, "Warning: Unable to unpack WM_DDE_ADVISE lParam %08lX.\n",
				pMsg->lParam);
			return;
		}
		aItem = (ATOM)nItem;
		ASSERT(aItem != NULL);
		ASSERT(hAdvise != NULL);

		DDEADVISE* lpAdvise = (DDEADVISE*)::GlobalLock(hAdvise);
		ENSURE_THROW(lpAdvise != NULL, ::AfxThrowMemoryException() );
		TCHAR szItem[80];
		szItem[0] = '\0';

		if (aItem != 0)
			::GlobalGetAtomName(aItem, szItem, _countof(szItem));

		TCHAR szFormat[80];
		szFormat[0] = '\0';
		if (((UINT)0xC000 <= (UINT)lpAdvise->cfFormat) &&
				((UINT)lpAdvise->cfFormat <= (UINT)0xFFFF))
		{
			::GetClipboardFormatName(lpAdvise->cfFormat,
				szFormat, _countof(szFormat));

			// User defined clipboard formats have a range of 0xC000->0xFFFF
			// System clipboard formats have other ranges, but no printable
			// format names.
		}

		AfxTrace(
			_T("%s: Advise item='%s', Format='%s', Ack=%d, Defer Update= %d\n"),
			 lpszPrefix, szItem, szFormat, lpAdvise->fAckReq,
			lpAdvise->fDeferUpd);
		::GlobalUnlock(hAdvise);
	}
}
#endif // !_WIN32_WCE

/////////////////////////////////////////////////////////////////////////////

void AFXAPI _AfxTraceMsg(LPCTSTR lpszPrefix, const MSG* pMsg)
{
	ENSURE_ARG(AfxIsValidString(lpszPrefix));
	ENSURE_ARG(pMsg != NULL);

	if (pMsg->message == WM_MOUSEMOVE || 
		pMsg->message == WM_SETCURSOR ||
#ifndef _WIN32_WCE
		pMsg->message == WM_NCMOUSEMOVE ||
		pMsg->message == WM_NCHITTEST ||
#endif // !_WIN32_WCE
		pMsg->message == WM_CTLCOLORBTN ||
		pMsg->message == WM_CTLCOLORDLG ||
		pMsg->message == WM_CTLCOLOREDIT ||
		pMsg->message == WM_CTLCOLORLISTBOX ||
		pMsg->message == WM_CTLCOLORMSGBOX ||
		pMsg->message == WM_CTLCOLORSCROLLBAR ||
		pMsg->message == WM_CTLCOLORSTATIC ||
#ifndef _WIN32_WCE
		pMsg->message == WM_ENTERIDLE ||
#endif // !_WIN32_WCE
		pMsg->message == WM_CANCELMODE ||
		pMsg->message == 0x0118)    // WM_SYSTIMER (caret blink)
	{
		// don't report very frequently sent messages
		return;
	}

	LPCSTR lpszMsgName = NULL;
	TCHAR szBuf[80];

	// find message name
	if (pMsg->message >= 0xC000)
	{
		// Window message registered with 'RegisterWindowMessage'
		//  (actually a USER atom)
		if (::GetClipboardFormatName(pMsg->message, szBuf, _countof(szBuf)))
			lpszMsgName = CT2A(szBuf);
	}
	else if (pMsg->message >= WM_USER)
	{
		// User message
#ifndef _WIN32_WCE
		sprintf_s(szBuf, _countof(szBuf), "WM_USER+0x%04X", pMsg->message - WM_USER);
		lpszMsgName = szBuf;
#else // !_WIN32_WCE
		wsprintf(szBuf, _T("WM_USER+0x%04X"), pMsg->message - WM_USER);
		lpszMsgName = CT2A(szBuf);
#endif // !_WIN32_WCE
	}
	else
	{
		// a system windows message
		const AFX_MAP_MESSAGE* pMapMsg = allMessages;
		for (/*null*/; pMapMsg->lpszMsg != NULL; pMapMsg++)
		{
			if (pMapMsg->nMsg == pMsg->message)
			{
				lpszMsgName = pMapMsg->lpszMsg;
				break;
			}
		}
	}

	if (lpszMsgName != NULL)
	{
#ifdef WIN64
		TRACE(traceWinMsg, 4, _T("%s: hwnd=%p, msg = %hs (%p, %p)\n"),
			lpszPrefix, pMsg->hwnd, lpszMsgName,
			pMsg->wParam, pMsg->lParam);
#else
		TRACE(traceWinMsg, 4, _T("%s: hwnd=0x%08X, msg = %hs (0x%08X, 0x%08X)\n"),
			lpszPrefix, pMsg->hwnd, lpszMsgName,
			pMsg->wParam, pMsg->lParam);
#endif
	}
	else
	{
#ifdef WIN64
		TRACE(traceWinMsg, 4, _T("%s: hwnd=%p, msg = 0x%04X (%p, %p)\n"),
			lpszPrefix, pMsg->hwnd, lpszMsgName,
			pMsg->wParam, pMsg->lParam);
#else
		TRACE(traceWinMsg, 4, _T("%s: hwnd=0x%08X, msg = 0x%04X (0x%08X, 0x%08X)\n"),
			lpszPrefix, pMsg->hwnd, lpszMsgName,
			pMsg->wParam, pMsg->lParam);
#endif
	}

#ifndef _WIN32_WCE
	if (pMsg->message >= WM_DDE_FIRST && pMsg->message <= WM_DDE_LAST)
		TraceDDE(lpszPrefix, pMsg);
#endif // !_WIN32_WCE
}

/////////////////////////////////////////////////////////////////////////////

#endif // _DEBUG (entire file)
