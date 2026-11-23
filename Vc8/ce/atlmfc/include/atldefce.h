// This is a part of the Active Template Library and the 
// Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library and Microsoft Foundation Classes 
// Reference and related electronic documentation provided 
// with the libraries.
// See these sources for detailed information regarding the
// Active Template Library and Microsoft Foundation Classes
// products.

#ifndef __ATLDEFCE_H__
#define __ATLDEFCE_H__

//#pragma once

#ifndef _WIN32_WCE
	#error atldefce.h requires _WIN32_WCE to be defined and altdefce.h will automatically be included if _WIN32_WCE is defined
#endif

#include <ceconfig.h>

//
// Determine the level of support the Windows CE SDK includes
//

#undef _CE_BASE
#undef _CE_COM
#undef _CE_OLE
#undef _CE_DCOM
#undef _CE_WIN
#undef _CE_ACTIVEX

#if !defined(_ATL_DLL_IMPL) && !defined(_ATL_STATIC_LIB_IMPL)

#if defined(_WIN32_WCE) && (_WIN32_WCE >= 0x420)
#define _CE_BASE
#endif

#if defined(_CE_BASE) && defined(DCOM_MODULES_OLE32) && defined(DCOM_MODULES_OLEAUT32) && defined(DCOM_MODULES_UUID) && defined(OLE32_MCOMBASE) && defined(OLE32_MCOMMEM) && defined(OLE32_MCOMSTR) && defined(OLEAUT32_OAALL ) && defined(CE_MODULES_FILESYS) && ( defined(COREDLL_CORELOC) || defined(COREDLL_LOCUSA) )
#define _CE_COM
#endif

#if defined(_CE_COM) && defined(OLE32_MCOMMON) && (defined(OLE32_MCOMSTM) || defined(OLE32_STG)) && defined(OLE32_DOCFILE) && defined(OLE32_OLE232)
#define _CE_OLE
#endif

#if defined(_CE_BASE) && defined(DCOM_MODULES_OLE32) && defined(DCOM_MODULES_OLEAUT32) && defined(DCOM_MODULES_UUID) && defined(OLE32_DCOMOLE) && defined(OLEAUT32_OAALL) && defined(OLEAUT32_IDISPPROXY)
#define _CE_DCOM
#endif

#if !defined(_CE_OLE) && !defined(_CE_DCOM)
	#error This Windows CE SDK does not support mini-COM with OLE or the full DCOM.  One of these is required inorder to use ATL.
#endif

#if (defined(_CE_DCOM) || defined(_CE_OLE)) && defined(CE_MODULES_GWES) && defined(GWES_WMBASE) && defined(GWES_MSGQUE) && defined(GWES_WINMGR) && defined(GWES_DRAWMBAR) && defined(GWES_TIMER) && defined(GWES_DLGMGR) && defined(GWES_SBCMN) && defined(GWES_CARET) && defined(GWES_CLIPBD) && defined(GWES_BTNCTL) && defined(GWES_EDCTL) && defined(GWES_LBCTL) && defined(GWES_MSGBOX) && defined(GWES_SCBCTL) && defined(GWES_STCCTL) && (defined(GWES_MGTT) || defined(GWES_MGRAST) || defined(GWES_GDIFONTS) || defined(GWES_PGDI)) && (defined(GWES_MGBASE) || defined(GWES_PGDI)) && (defined(GWES_MGBLT) || defined(GWES_PGDI)) && (defined(COREDLL_GDI_C) || defined(COREDLL_MGDI_C)) && (defined(GWES_MGBLT2) || defined(GWES_PGDI)) && (defined(GWES_MGDRAW) || defined(GWES_PGDI)) && defined(GWES_LOADIMG) && defined(COREDLL_RECTAPI) && defined(GWES_FOREGND) && (defined(GWES_CURSOR) || defined(GWES_MCURSOR)) && defined(GWES_KBDUI) && defined(GWES_CMBCTL)
#define _CE_WIN
#else
	#pragma message("_CE_WIN was not defined because this Windows CE SDK does not support the necessary GUI components.")
#endif

#if defined(_CE_WIN) && (defined(_CE_DCOM) || defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA))
#define _CE_ACTIVEX
#elif !defined(_CE_DCOM)
	#pragma message("_CE_ACTIVEX was not defined because this Windows CE SDK does not have DCOM.")
	#pragma message("\t_CE_ACTIVEX could be caused to be defined by defining _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, but it is recommended that this be done only for single-threaded apps.")
#endif

#else // !defined(_ATL_DLL_IMPL) && !defined(_ATL_STATIC_LIB_IMPL)

// Turn on highest support levels for the internal build of ATL
#define _CE_BASE
#ifndef _ATL_NO_DCOM_IMPL
#define _CE_DCOM
#endif // !_ATL_NO_DCOM_IMPL
#define _CE_WIN
#define _CE_ACTIVEX

#endif // !defined(_ATL_DLL_IMPL) && !defined(_ATL_STATIC_LIB_IMPL)

#if defined(SHELLW_MODULES_IEXPLORE)
#define _CE_PIE
#else
#if defined(IE_MODULES_UUID)
#define _CE_IE
#endif
#endif

#ifdef _CE_DCOM

#ifdef _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA
	#undef _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA
	#pragma message("_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA was undefined because this Windows CE SDK has DCOM support")
#endif // _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA

#else // _CE_DCOM

// _CE_DCOM not defined, so all objects live in the MTA
#ifndef _ATL_FREE_THREADED 
#define _ATL_FREE_THREADED
#endif

#ifdef _ATL_APARTMENT_THREADED
	#undef _ATL_APARTMENT_THREADED
	#pragma message("_ATL_APARTMENT_THREADED was undefined and _ATL_FREE_THREADED was defined because this Windows CE SDK does not have DCOM support")
#endif

#ifdef _ATL_SINGLE_THREADED
	#undef _ATL_SINGLE_THREADED
	#pragma message("_ATL_SINGLE_THREADED was undefined and _ATL_FREE_THREADED was defined because this Windows CE SDK does not have DCOM support")
#endif

#endif // _CE_DCOM

#if !defined(_CE_ACTIVEX) && !defined(_ATL_NO_HOSTING)
	#define _ATL_NO_HOSTING
	#pragma message("_ATL_NO_HOSTING was defined because _CE_ACTIVEX was not defined.")
#endif

#if !defined(_CE_WIN) && !defined(_ATL_CE_NO_GUI)
	#define _ATL_CE_NO_GUI
	#pragma message("_ATL_CE_NO_GUI was defined because _CE_WIN was not defined.")
#endif

#if defined(_CE_WIN) && !defined(_WINGDI_)
// _CE_WIN is defined, so define _WINGDI_ since it is not defined in Windows CE's wingdi.h 
// and it is needed in atlconv.h
#define _WINGDI_
#endif

#if !defined(WINVER) || (WINVER < 0x0400)
	#undef WINVER
	#define WINVER 0x0400 // This is value is not strongly correlated to the OS version being targeted
	#pragma message("WINVER was defined to be 0x0400, as it was either not set or set to a lower value")
#endif // WINVER

#if defined(_WIN32_WINDOWS)
	#undef _WIN32_WINDOWS
	#pragma message("_WIN32_WINDOWS was undefined as it is not supported for Windows CE")
#endif // WINVER

#if defined(_WIN32_WINNT)
	#undef _WIN32_WINNT
	#pragma message("_WIN32_WINNT was undefined as it is not supported for Windows CE")
#endif // WINVER

#ifdef _ATL_MIN_CRT
	#undef _ATL_MIN_CRT
	#pragma message("_ATL_MIN_CRT was undefined because atlmincrt.lib is not supported for Windows CE")
#endif // _ATL_MIN_CRT

// Windows CE SDKs do no include the correct API's to support the CRT based CStrings.
#ifndef _ATL_CSTRING_NO_CRT
#define _ATL_CSTRING_NO_CRT
#endif

// Windows CE SDKs don't include a debug version of the CRT, nor do Windows CE images.
#ifndef _ATL_NO_DEBUG_CRT
#define _ATL_NO_DEBUG_CRT
#endif

// Don't utilize thread locales, as they are unsupported on Windows CE.
#ifndef _CONVERSION_DONT_USE_THREAD_LOCALE
#define _CONVERSION_DONT_USE_THREAD_LOCALE
#endif

// The semantics of Windows CE services are not compatible with those of Windows services
#ifndef _ATL_NO_SERVICE
#define _ATL_NO_SERVICE
#endif

// Make sure Unicode is turned on, as ANSI/MBCS is largely unsupported on Windows CE
// and ATLMFC is Unicode only.
#ifndef UNICODE
#define UNICODE         // UNICODE is used by Windows headers
#endif
#ifndef _UNICODE
#define _UNICODE        // _UNICODE is used by Visual C++ library headers
#endif

#ifdef _MBCS
	#undef _MBCS
	#pragma message("_MBCS was undefined because only Unicode is support for ATLMFC on Windows CE")
#endif // _MBCS

// The methods associated with NO_SHLWAPI_PATH are only provided by IE (not Pocket IE).
#if !defined(_CE_IE) || defined(_ATL_DLL_IMPL) || defined(_ATL_STATIC_LIB_IMPL)
#define NO_SHLWAPI_PATH
#endif

// The Imagehelp APIs are not supported by Windows CE.
#ifndef _ATL_NO_IMAGEHLP
#define _ATL_NO_IMAGEHLP
#endif

// ACLs are not supported by Windows CE.
#ifndef ATL_NO_ACLAPI
#define ATL_NO_ACLAPI
#endif

// CSoapMSXMLInetClient CoCreates a ServerXMLHTTP30, which does not appear to be supported on OSes with only PocketIE.
// Exclude for all platforms as it isn't necessary for just consuming web services, which is all that is supported in ATL Server for CE.
#ifndef ATLSOAP_NOMSXML_INET
#define ATLSOAP_NOMSXML_INET
#endif

#ifdef _M_IX86

#ifndef x86
#define x86 1
#endif

#ifndef _X86_
#define _X86_ 1
#endif

#elif _M_ARM

#ifndef ARM
#define ARM 1
#endif

#ifndef _ARM_
#define _ARM_ 1
#endif

#elif _M_MRX000

#ifndef MIPS
#define MIPS 1
#endif

#ifndef _MIPS_
#define _MIPS_ 1
#endif

#elif (_M_SH==4)

#ifndef SHx
#define SHx 1
#endif

#ifndef _SHX_
#define _SHX_ 1
#endif

#ifndef SH4
#define SH4 1
#endif

#else
	#error Only supported for X86, ARM, MIPS, and SH4.
#endif

#endif  //__ATLDEFCE_H__

