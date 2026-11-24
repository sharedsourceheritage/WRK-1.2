/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef project_h
#define project_h


//standard libraries
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

//standard windows libraries
#include <windows.h>
#include <commctrl.h>   //for image lists
//#include "vsmem.h" 

//vs extensibility interfaces
#include "vsshell.h"
#include "textmgr.h"
#include "objext.h"

//text: string conversions and utilities
//#include "text.h"
#include <atlbase.h>
#include <atlconv.h>

//common: macros 
#include "common.h"

//list of interfaces
#include "objectlist.h"

//babel
#include "babelservice.h"

//vstudio common
#include "vscommon.h"

//disable some warnings
#pragma warning (disable: 4100) //unreferenced formal parameter

#endif
