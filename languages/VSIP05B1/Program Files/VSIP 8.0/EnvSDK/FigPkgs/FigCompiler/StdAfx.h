
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#pragma once

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>

#include <iostream>
#include <stdio.h>
#include <io.h>
#include <string.h> 
#include <vector>
#include <direct.h>
#include <time.h>
#include <windows.h>
#include <comdef.h>

#define MAXLINE 1024
#define MAXTOKENS 1024

#define CIRCLE "circle"
#define ARROW "arrow"
#define RECTANGLE "rectangle"
#define UNASSIGNED (-999999)

using namespace std;

#include "VSRegKeyNames.h"
#include "parse.h"
#include "DLLEntry.h"

// The global object derived from CAtlDllModuleT
extern CFigCompilerModule _AtlModule;
#include <atlcom.h>

#ifndef NUMBER_OF
#define NUMBER_OF(array)    sizeof(array)/sizeof(array[0])
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

