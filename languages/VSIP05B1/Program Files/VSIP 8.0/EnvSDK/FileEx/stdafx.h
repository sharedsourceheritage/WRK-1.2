
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
#endif //STRICT

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

  
#ifndef _ATL_STATIC_REGISTRY
#define _ATL_STATIC_REGISTRY 
#endif

#include <atlbase.h>
#include <objbase.h>
#include <process.h>

#ifndef ASSERT
#define ASSERT _ASSERTE
#endif //ASSERT

#include "VsAssert.h"      // from src\common\inc
#define _ASSERTE_MSG(expr, msg) VSASSERT(expr, msg)

#include "FileEx.h"        // for package interfaces

#include "objext.h"         // for ILocalRegistry, ICategorizeProperties
#include "vsshlex.h"        // for IVsPackageStaticExData
#include "dte.h"            // for _DTE

#include <atlcom.h>
#include <atlwin.h>
#include <atlstr.h>


#include "VsModule.h"        // CVxModule
#include "VsPkg.h"
#include "VSRegKeyNames.h"

extern CVxModule _VxModule;
extern CFileExModule _AtlModule;

// IProfferService is defined in shlobjidl.h too!
#define __IProfferService_INTERFACE_DEFINED__
#include <shlobj.h>

//=========================================================================
//                                                                  MFCIncl.h 
// define stuff we don't want to include from MFCIncl.h
#define  __DATETIME_H__
#define  __MFCMISC_H__
#define  __OLEDOBJ2_H__
#define  __VSFILE_H__
#include "MFCIncl.h"      // hierutil7
//#include "ValidAdd.h"
//#include "Collct.h"
//#include "Templ.h"
//=========================================================================

typedef CVxPtrArray CPtrArray; // hierutil7

#include "VsDialog.h"

#include "Macros.h"
#include "FSFolder.h"
#include "FSFile.h"
#include "FSCachedFolder.h"
#include "FSExtMgr.h"
#include "FSCommand.h"
#include "FileSys.h"
#include "Global.h"
#include <limits.h>

extern CFileSystem g_FileSys;
extern CFileSystemExtensionManager g_ExtMgr;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#ifndef NUMBER_OF
#define NUMBER_OF(array)    sizeof(array)/sizeof(array[0])
#endif
