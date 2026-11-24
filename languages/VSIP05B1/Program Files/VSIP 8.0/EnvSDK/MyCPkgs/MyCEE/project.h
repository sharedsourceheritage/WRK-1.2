
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

//standard libraries
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

//standard windows libraries
#include <windows.h>
#include <tchar.h>

//debugger interfaces
#include <ee.h>
#include <sh.h>
#include <msdbg.h>

//localised string identifiers
#include "..\myceeui\resource.h"

//common: macros and utilities
#include "common.h"

//localised strings
#include "strings.h"

//expression evaluator 
#include "expreval.h"

//debug properties
#include "fieldproperty.h"
#include "valueproperty.h"

//parsing and evaluation
#include "parsedexpr.h"
#include "evaluator.h"

//enumerators
#include "enumpropertyinfo.h"
#include "enummethodfield.h"

//helpers for fields and variants
#include "field.h"
#include "variant.h"
