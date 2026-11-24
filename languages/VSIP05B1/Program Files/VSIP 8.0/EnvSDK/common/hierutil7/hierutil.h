//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// File: hierutil.h
// Area: IHierarchy Utilities implementation
//
// Contents:
//	Generally useful macros & DLL import/export definitions
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __HIERUTIL_H__
#define __HIERUTIL_H__

//Useful macros:
#define ADDREF(x)		{ if(x) { (x)->AddRef(); } }
#define RELEASE(x)		{ if(x) { (x)->Release(); (x) = NULL; } }
#define FREEBSTR(x)     { ::SysFreeString(x); (x) = NULL;}

#define DllPort

#endif //__HIERUTIL_H__
