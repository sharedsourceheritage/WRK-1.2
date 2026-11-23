// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXCE_H__
#define __AFXCE_H__

#ifdef _WIN32_WCE

#if !defined(WINVER) || (WINVER != 0x0400)
#undef WINVER
// This is value is not strongly correlated to the OS version being targeted
#define WINVER 0x0400
#endif // WINVER

#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif

#ifdef _WIN32_IE
#undef _WIN32_IE
// Windows CE IE feature set closely maps to IE4.0
#define _WIN32_IE	0x0400
#endif

#define _CE_CRT_ALLOW_WIN_MINMAX
#include "altcecrt.h"
#include "atldefce.h"

#include <resdefce.h>
#include <shlwapi.h>
#include <stdlib.h>
#include <commctrl.h>
#include <ceconfig.h>
#include <aygshell.h>

// for PropertySheet
#include <prsht.h>

// DAO
#ifndef _AFX_NO_DAO_SUPPORT
#define _AFX_NO_DAO_SUPPORT
#endif

// Internet Services
#ifndef _AFX_NO_INET_SUPPORT
#define _AFX_NO_INET_SUPPORT
#endif

// RichEdit
#ifndef _AFX_NO_RICHEDIT_SUPPORT
#define _AFX_NO_RICHEDIT_SUPPORT
#endif

// Printing
#ifndef _AFX_NO_PRINTING_SUPPORT
#define _AFX_NO_PRINTING_SUPPORT
#endif

// Database
#ifndef _AFX_NO_DB_SUPPORT
#define _AFX_NO_DB_SUPPORT
#endif

// Html
#ifndef _AFX_NO_HTML_SUPPORT
#define _AFX_NO_HTML_SUPPORT
#endif

// context sensitive help - winhelp and htmlhelp
#ifndef _WIN32_WCE_NO_HELP_SUPPORT
#define _WIN32_WCE_NO_HELP_SUPPORT
#endif

// GDI Transform
#ifndef _AFX_NO_GDITRANSFORM_SUPPORT
#define _AFX_NO_GDITRANSFORM_SUPPORT
#endif

#ifndef _AFX_NO_DOCOBJECT_SUPPORT
#define _AFX_NO_DOCOBJECT_SUPPORT
#endif 

#ifndef _AFX_NO_DEBUG_CRT
#define _AFX_NO_DEBUG_CRT
#endif

#ifndef _WIN32_WCE_NO_TOOLTIPS
#define _WIN32_WCE_NO_TOOLTIPS
#endif

#ifndef _WIN32_WCE_NO_AYGSHELL
#define _WIN32_WCE_NO_AYGSHELL
#endif

#ifndef _WIN32_WCE_NO_HELP_SUPPORT
#define _WIN32_WCE_NO_HELP_SUPPORT
#endif

#if defined(WIN32_PLATFORM_PSPC) || defined(_MFC_DLL_BLD) || defined(_MFC_STAT_BLD)
#define _WIN32_WCE_DOCLIST_SUPPORT
#endif

#if defined(WIN32_PLATFORM_PSPC) || defined(WIN32_PLATFORM_WFSP) || defined(_MFC_DLL_BLD) || defined(_MFC_STAT_BLD)
#ifndef _DEVICE_RESOLUTION_AWARE
#define _DEVICE_RESOLUTION_AWARE
#endif
#endif

#ifdef _DEVICE_RESOLUTION_AWARE
#include "DeviceResolutionAware.h"
#endif

#ifndef _AFX_NOFORCE_MANIFEST
#define _AFX_NOFORCE_MANIFEST
#endif

// warnings specific to build for CE targets
#pragma warning(disable: 4103)  // used #pragma pack to change alignment
#pragma warning(disable: 4201)  // nonstandard extension used : nameless struct/union

#endif // _WIN32_WCE

#endif // __AFXCE_H__
