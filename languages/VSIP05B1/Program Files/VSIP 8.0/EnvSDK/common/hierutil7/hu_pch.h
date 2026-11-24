//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// File: hu_pch.h
// Area: IHierarchy Utilities implementation
//
// Contents:
//  include file for standard system include files
//  or project-specific include files that rarely change.
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef HU_PCH_H
#define HU_PCH_H 1

// STRICT is the only supported option (NOSTRICT is no longer supported)
#ifndef STRICT
#define STRICT 1
#endif

#undef ASSERT
#define ASSERT(cond) VSASSERT(cond, "")

// add these warnings to default build system
#pragma warning(1 : 4706)       // assignment within conditional expression

// remove these warnings from default build system
#pragma warning(disable: 4100)  // unreferenced formal param
#pragma warning(disable: 4510)  // default constructor could not be generated
#pragma warning(disable: 4511)  // copy ctor could not be generated
#pragma warning(disable: 4610)  // union '__unnamed' can never be instantiated - user defined constructor required

#include <new.h>
#include <atlbase.h>
#include "VsModule.h"

// You must declare an instance of CVxModule called _VxModule in your dll and call SetModuleSite() on it
// when your package is sited with an IServiceProvider. You need to call Close() when your package is being
// closed.
extern CVxModule _VxModule;
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
#include <atlstr.h>
#include <limits.h>

#ifdef  _DEBUG
#define VERIFY(exp) ASSERT(exp)
#else
#define VERIFY(exp) ((void)(exp))
#endif

#include <commctrl.h>

#include <ole2.h>
#include <ocidl.h>

#include "oleipc.h"

#include "oleidl.h"
typedef  DWORD DROPEFFECT;

//

// Debug / retail common shell memory allocation and assert business.
// Here we point all of our debug goodies to use vsassert.dll
#include "vsassert.h"
#include "vsmem.h"      // memory tracking

#include <docobj.h>         // Visual Studio Shell
#include <objext.h>
#include <oleipc.h>
#include <VSShellInterfaces.h>        // Visual Studio Shell
#include <vsshlids.h>
#include <fpstfmt.h>
#include <uilocale.h>

#include <helpsys.h>        // html help

#undef __Properties_FWD_DEFINED__
#undef __Property_FWD_DEFINED__
#include <dte.h>            // Design-Time Extensibility

typedef VxDTE::_Project         _Project;
typedef VxDTE::_Projects            _Projects;
typedef VxDTE::_ProjectItem     _ProjectItem;
typedef VxDTE::_ProjectItems        _ProjectItems;

// Start tool specific includes here
//
#include    "hierutil.h"

// Error goto macro
#define IfErrGo(exp) { if (FAILED(hr = (exp))) goto ERROR_EXIT; }

#if !defined(NUMBER_OF)
#define NUMBER_OF(x) (sizeof(x) / sizeof((x)[0]))
#endif // !defined(NUMBER_OF)

#endif  // HU_PCH_H

