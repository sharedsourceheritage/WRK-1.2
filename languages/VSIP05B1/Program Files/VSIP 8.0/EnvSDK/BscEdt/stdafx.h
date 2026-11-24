
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

#ifndef NOT_USING_ATL_CONNECTION_CLASSES
#pragma message("Using ATL connection classes...")
#else    // NOT_USING_ATL_CONNECTION_CLASSES
#pragma message("Not using ATL connection classes...")
#endif    // NOT_USING_ATL_CONNECTION_CLASSES

//#define _WIN32_WINNT 0x0400
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
#include <IVsQueryEditQuerySave2.h>     // for IVsQueryEditQuerySave2

#include "vbapkg.h"            // for IVsMacroRecorder
#include "fpstfmt.h"        // for IPersistFileFormat
#include "initguid.h"
#include "tom.h"            // for ITextDocument et al

#include "VSRegKeyNames.h"
#include "BscEdt.h"
#include "BscEdtUI\resource.h"
#include "BscEdtUI\PkgCmdID.h"

#include "VsModule.h"        // CVsComModule
extern CVsComModule _AtlModule;

#include <atlcom.h>
#include "vspkg.h"

#define countof(exp) ( sizeof( exp ) / sizeof( ( exp )[0] ) )

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

