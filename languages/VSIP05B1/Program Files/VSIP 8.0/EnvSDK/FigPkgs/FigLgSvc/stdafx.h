
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

#define _ATL_APARTMENT_THREADED
#pragma warning (disable: 4786)

// Turn off warning about unreferenced local functions being removed.
#pragma warning(disable: 4505)

// #define _WIN32_WINNT 0x0400

#ifndef _ATL_STATIC_REGISTRY
#define _ATL_STATIC_REGISTRY 
#endif

#include <atlbase.h>

#include "dte.h"           // for extensibility
#include "objext.h"        // for ILocalRegistry
#include "vshelp.h"        // for Help
#include "uilocale.h"      // for IUIHostLocale2
#include "fpstfmt.h"            // for IPersistFileFormat

#include "Parse.h"                // for IFigParse
#include "FigEdit.h"            // for IFigOutline provider 
#include "FigLgSvc.h"

#include "VsModule.h"            // CVsComModule
#include "VSRegKeyNames.h"

extern CVsComModule _AtlModule;

#include <atlcom.h>

#ifndef ASSERT
#define ASSERT _ASSERTE
#endif //ASSERT


#include <commctrl.h>
#include <comdef.h>

#include <iostream>                // for stl templates (wstring)
#include <string>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

#ifdef DEBUG
  #undef DEBUG
#endif

#ifdef _DEBUG
  #define DEBUG 1
#else
  #define DEBUG 0
#endif

#include <vsassert.h>
#include "macros.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

