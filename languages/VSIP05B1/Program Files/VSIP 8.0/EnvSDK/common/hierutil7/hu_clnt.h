//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// File: hu_clnt.h
// Area: IHierarchy Utilities implementation
//
// Contents:
//  Hierarchy Utility Client includes & defines. Client DLL's only need to
//  include this file because it includes all utility header files in
//  the correct order
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef _HU_CLNT_H_
#define _HU_CLNT_H_


// Includes needed to compile this lib ----------------------------------------
#include <commctrl.h>

// Includes for this lib ------------------------------------------------------
#include <mfcincl.h>
#include <hierutil.h>
#include <hu_image.h>
#include <hu_archy.h>
#include <hu_node.h>
#include <hu_ctnr.h>
#include <hu_nest.h>
#include <hu_util.h>
#include <namelist.h>
#include <vsdialog.h>
#include <register.h>
#include <statbar.h>
#include <advislst.h>
#include <lutil.h>
#include <hiertasklist.h>
#endif //_HU_CLNT_H_
