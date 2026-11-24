
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


#include <atlbase.h>

#include "objext.h"        // for ILocalRegistry
#include "vshelp.h"        // for Help
#include "dte.h"           // for _DTE
#include "uilocale.h"      // for IUIHostLocale2

#include "util.h"

// import VSLangProj.tlb for CATID constants
#import "VSLangProj.tlb" raw_interfaces_only no_namespace

#include "SlnExt.h"        // for private interfaces
#include "Automation.h"    // for automation interfaces

#include "VsModule.h"      // CVsComModule
#include "VSRegKeyNames.h"

extern CVsComModule _AtlModule;

#include <atlcom.h>


// Error Handling
#define IfFailGo(EXPR) \
    { hr = (EXPR); if(FAILED(hr)) goto Error; }

#define _ExpectedExprRet(expr) if (!(expr)) { return E_UNEXPECTED; }

#define ExpectedExprRet(expr)  { \
        _ASSERTE(expr); \
        _ExpectedExprRet(expr); } 

#define _IfFailRet(EXPR) {          \
        hr = (EXPR);                \
        if (FAILED(hr))             \
        {                           \
            return hr;              \
        }                }                                


#define IfFailRet(EXPR)             \
    {                               \
        hr = (EXPR);                \
        _ASSERTE(SUCCEEDED(hr));    \
        if (FAILED(hr))             \
        {                           \
            return hr;              \
        }                           \
    }                                

#define countof(exp) ( sizeof( exp ) / sizeof( ( exp )[0] ) )

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.
