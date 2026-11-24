
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

// Turn off warning about template expansion being > 255 chars.
#pragma warning(disable:4786)

// Turn off warning about unreferenced local functions being removed.
#pragma warning(disable: 4505)

// #define _WIN32_WINNT 0x0400

#ifndef _ATL_STATIC_REGISTRY
#define _ATL_STATIC_REGISTRY 
#endif

#include <atlbase.h>
#include <objbase.h>
#include <process.h>

#ifndef ASSERT
#define ASSERT _ASSERTE
#endif //ASSERT

#include "DTE.h"
#include "msdbg.h"          // for debug - guidCOMPlusNativeEng
#include <VSShellInterfaces.h>
#include <fpstfmt.h>        // for IPersistFileFormat
#include <IVsTrackProjectDocuments2.h>  // for IVsTrackProjectDocuments2

// SCC includes
#include <scc.h>                        // SCC_STATUS
#include <IVsQueryEditQuerySave2.h>     // for IVsQueryEditQuerySave2
#include <IVsSccManager2.h>             // IVsSccManager2
#include <IVsSccProject2.h>             // IVsSccProject2


#include "VsModule.h"
#include "VSRegKeyNames.h"

extern CVxModule _VxModule;


#include <atlcom.h>
#include <atlwin.h>
#include <atlstr.h>


// hierutil7 includes
#include <oleref.h>     // COleRef
#include <hu_clnt.h>    // everything else from hierutil directory

#ifdef DEBUG
#undef DEBUG
#define DEBUG 1
#endif

#include <vsassert.h>

// package includes
#include "BscPrj.h"
#include "BscExt.h"
#include "VsPkg.h"
extern CBscPrjModule _AtlModule;


//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

