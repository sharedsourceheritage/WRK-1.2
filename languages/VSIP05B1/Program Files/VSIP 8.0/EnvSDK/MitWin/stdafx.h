
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

#include "dte.h"           // for extensibility
#include "objext.h"        // for ILocalRegistry
#include "vshelp.h"        // for Help
#include "uilocale.h"      // for IUIHostLocale2

#include "util.h"

#include "MitWin.h"      // for private interfaces

#include "VsModule.h"      // CVsComModule
#include "VSRegKeyNames.h"

extern CVsComModule _AtlModule;

#include <atlcom.h>
#include <atlhost.h>

#include "MitWin.h"

#define countof(exp) ( sizeof( exp ) / sizeof( ( exp )[0] ) )

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.
