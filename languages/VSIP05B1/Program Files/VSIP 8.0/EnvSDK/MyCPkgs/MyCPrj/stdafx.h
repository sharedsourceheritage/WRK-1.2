
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

// Turn off warning about template expansion being > 255 chars.
#pragma warning(disable:4786)

// Turn off warning about unreferenced local functions being removed.
#pragma warning(disable: 4505)

#ifndef _ATL_STATIC_REGISTRY
#define _ATL_STATIC_REGISTRY 
#endif

#include <atlbase.h>

#include <objbase.h>
#include <process.h>

#ifndef ASSERT
#define ASSERT _ASSERTE
#endif //ASSERT

#include <vssplash.h>        // IVsInstalledProduct
#include <fpstfmt.h>    // IPersistFileFormat
#include <msdbg.h>        // guidXXXEng
#include <dpkg.h>                       // IVsSolutionDebuggingAssistant2
#include "vsmanaged.h"        // IVSMDPropertyGrid

interface CommandBars; //So MSO*.h is not needed
#include "DTE.h"

#include <IVsTrackProjectDocuments2.h>  // for IVsTrackProjectDocuments2

// SCC includes
#include <scc.h>                        // SCC_STATUS
#include <IVsQueryEditQuerySave2.h>     // for IVsQueryEditQuerySave2
#include <IVsSccManager2.h>             // IVsSccManager2
#include <IVsSccProject2.h>             // IVsSccProject2

#include <shlobj.h>     // SHBrowseForFolder

#include <atlcom.h>
#include <atlwin.h>
#include <atlstr.h>


#include "VsModule.h"
#include "VSRegKeyNames.h"



// util includes
#include <oleref.h>

#ifdef DEBUG
  #undef DEBUG
  #define DEBUG 1
#endif

#include <vsassert.h>
#include <hu_clnt.h>    // everything else from our hierutl utility directory


#include "MyCPrj.h"
#include "MyCExt.h"

#include "vspkg.h"

extern CVxModule _VxModule;
extern CMyCPrjModule _AtlModule;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

