
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


#define _WIN32_WINNT 0x0400
#define _ATL_APARTMENT_THREADED

#include "VSRegKeyNames.h"
#include <atlbase.h>
#include <atlcom.h>

#include "Parse.h"
#include "FigParseModule.h"
extern CFigParseModule _AtlModule;

#define _ExpectedPtrRet(ptr) \
    if (!(ptr)) \
        { return E_POINTER; }

#define ExpectedPtrRet(ptr) \
    { \
        _ASSERTE(ptr); \
        _ExpectedPtrRet(ptr); \
    }

#define _IfFailRetEx(hr, hrReturn) \
    if (FAILED(hr)) \
        { return hrReturn; }

#define IfFailRetEx(hr, hrReturn) \
    { \
        _ASSERTE(SUCCEEDED(hr)); \
        _IfFailRetEx(hr, hrReturn); \
    }

#define IfFailRet(hr) \
    IfFailRetEx(hr, hr);

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.
