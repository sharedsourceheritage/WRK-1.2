
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
#include "servprov.h"      // for IServiceProvider
#include "vsshell.h"       // for various shell interfaces
#include "uilocale.h"      // for IUIHostLocale2
#include "designer.h"      // for ITrackSelection and ISelectionContainer
#include "oleipc.h"        // for IOleComponentUIManager
#include "helpsys.h"       // for IVsHelpSystem
#include "textmgr.h"       // for IVsTextLines etc
#include "fpstfmt.h"       // for IPersistFileFormat
#include "RDTView.h"      // for private interfaces

#include "VsModule.h"      // CVsComModule
#include "VSRegKeyNames.h"

extern CVsComModule _Module;

#include <atlcom.h>

#include "docview.h"

// Assert/Verify macros
#define Assert(x)	_ASSERTE(x)

#ifdef _DEBUG
	#define Verify(x)	Assert(x)
#else
	#define	Verify(x)	(x)
#endif

#define IfFailGo(expr)			{ if (FAILED(expr)) goto _done; }
#define IfFailAssertGo(expr)	{ if (FAILED(expr)) { Assert(FALSE); goto _done; } }

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.
