//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1992 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// This code was originally ported from the Microsoft Foundation Class Library.
//
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __MFCINCL_H__
#define __MFCINCL_H__

#include <limits.h>

#ifndef __ATLCOLL_H__
struct __POSITION { };
#endif
typedef __POSITION* POSITION;
#define BEFORE_START_POSITION ((POSITION)-1L)

// Used by the collection classes.
#ifndef SIZE_T_MAX
    #define SIZE_T_MAX  UINT_MAX
#endif

#ifndef  __VALIDADD_H__
#include "validadd.h"
#endif //__VALIDADD_H__

#ifndef  __COLLCT_H__
#include "collct.h"
#endif //__COLLCT_H__

#ifndef  __TEMPL_H__
#include "templ.h"
#endif //__TEMPL_H__

#ifndef  __DATETIME_H__
#include "datetime.h"
#endif //__DATETIME_H__

#ifndef  __MFCMISC_H__
#include "mfcmisc.h"
#endif //__MFCMISC_H__

#ifndef  __OLEDOBJ2_H__
#include "oledobj2.h"
#endif //__OLEDOBJ2_H__

#ifndef  __VSFILE_H__
#include "VsFile.h"
#endif //__VSFILE_H__

#endif //__MFCINCL_H__
