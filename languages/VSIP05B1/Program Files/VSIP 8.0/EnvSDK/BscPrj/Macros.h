
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// Macros.h
//
// Error checking macros and other utility macros
// 'Ret' versions return
// 'Go' versions jump to Error after setting hr appropriately
//
//*****************************************************************************

#pragma once

///////////////////////////////////////////////////////////////////////////////
// Error Checking Marcos


#define IfFailGo(EXPR) \
    { hr = (EXPR); if(FAILED(hr)) goto Error; }

#define IfFalseGo(EXPR, HR) \
    { if(!(EXPR)) { hr = (HR); goto Error; } }

#define IfFailGoto(EXPR, LABEL) \
    { hr = (EXPR); if(FAILED(hr)) goto LABEL; }

#define IfFalseGoto(EXPR, HR, LABEL) \
    { if(!(EXPR)) { hr = (HR); goto LABEL; } }

#define IfNullFail(s) \
    { 	if (!(s)) { \
      	  hr = E_OUTOFMEMORY; \
      	  goto Error;}}

#define IfNullGo(EXPR, HR) \
    { if(!(EXPR)) { hr = (HR); goto Error; } }

#define _IfFailRet(EXPR)            \
    {                               \
        hr = (EXPR);                \
	    if (FAILED(hr))             \
		{                           \
            return hr;              \
        }                           \
    }                                


#define IfFailRet(EXPR)             \
    {                               \
        hr = (EXPR);                \
	    _ASSERTE(SUCCEEDED(hr));    \
	    if (FAILED(hr))             \
		{                           \
            return hr;              \
        }                           \
    }                                


#define ExpectedPtrRet(ptr)         \
    {                               \
	    _ASSERTE(ptr);              \
	    if (!(ptr))                 \
		{ return E_POINTER; }       \
    }


#define InitParamTo(param, value) \
    { \
	    _ASSERTE(param); \
	    *param = value; \
    }

#define InitParam(param) \
	InitParamTo(param, NULL);

#define _ExpectedExprRet(expr) \
	if (!(expr)) \
		{ return E_UNEXPECTED; }

#define ExpectedExprRet(expr) \
    { \
	    _ASSERTE(expr); \
	    _ExpectedExprRet(expr); \
    } \

#define _ExpectedExprGo(expr) \
	if (!(expr)) \
		{ hr = E_UNEXPECTED; goto Error; }

#define ExpectedExprGo(expr) \
    { \
	    _ASSERTE(expr); \
	    _ExpectedExprGo(expr); \
    }

#define _IfNotValidRet(hr, idErrMsg) \
        if(!IsValid()) \
        { \
            ATLTRACE(_T("Warning: Function called for invalid item.\n"));\
			if (idErrMsg) \
				LUtilSetErrString(idErrMsg);\
            return hr; \
        }


#define NUMBER_OF(x) (sizeof(x) / sizeof((x)[0]))

#ifndef ENVSDK_DECLSPEC_SELECT_ANY
#define ENVSDK_DECLSPEC_SELECT_ANY __declspec(selectany)
#endif // ENVSDK_DECLSPEC_SELECT_ANY

/// Trace
#ifdef _ATL // ATL used
    #define ENVSDK_TRACE ATLTRACE2

    extern CTraceCategory envsdkTraceGeneral;

#else   // no ATL
    #error no ATL tracing
#endif
 
