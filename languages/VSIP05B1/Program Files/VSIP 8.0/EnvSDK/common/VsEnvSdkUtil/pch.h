
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
***************************************************************************/

// pch.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_PCH_H__1F9F6C89_1DB9_40D2_A7D5_421E01708052__INCLUDED_)
#define AFX_PCH_H__1F9F6C89_1DB9_40D2_A7D5_421E01708052__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

// nameless struct/union is triggered by Windows.h
#pragma warning(disable: 4201)
// unreferenced inline function has been removed
#pragma warning(disable: 4514)
// conditional exp is const
#pragma warning(disable: 4127)

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <commctrl.h>


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__1F9F6C89_1DB9_40D2_A7D5_421E01708052__INCLUDED_)
