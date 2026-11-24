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
#include <tchar.h>


//jscript
#pragma warning(push)
#pragma warning(disable:4336)
#pragma warning(disable:4278)
#pragma warning(disable:4279)

#import "Microsoft.Vsa.tlb" no_namespace no_implementation raw_interfaces_only

#define parse Parse
#import "Microsoft.Jscript.tlb" no_namespace no_implementation raw_interfaces_only exclude("JSToken")
#undef parse

#pragma warning(pop)


//common: macros and utilities
#include "common.h"

//babel
#include "babelservice.h"

//ecma babel service
#include "ecmaservice.h"

#endif
