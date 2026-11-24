
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
// Underscore versions do not assert. Those ending with 'Msg' take in a
// message msg, that is used in the assert dialog
// 'Ret' versions return
// 'Go' versions jump to OnError after setting hr appropriately
//
//*****************************************************************************

#pragma once

// Error Handling Macros
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

#define _ExpectedExprRet(expr) \
	if (!(expr)) \
		{ return E_UNEXPECTED; }

#define ExpectedExprRet(expr) \
    { \
	    _ASSERTE(expr); \
	    _ExpectedExprRet(expr); \
    } \

#define _ExpectedPtrRet(ptr) \
	if (!(ptr)) \
		{ return E_POINTER; }

#define ExpectedPtrRet(ptr) \
    { \
	    _ASSERTE(ptr); \
	    _ExpectedPtrRet(ptr); \
    }

#define _IfFailRetEx(hr, hrReturn) \
	if (FAILED(hr)) \
		{ return hrReturn; }

#define IfFailRetEx(hr, hrReturn) \
    { \
	    _ASSERTE(SUCCEEDED(hr)); \
	    _IfFailRetEx(hr, hrReturn); \
    }

#define IfFailRet(hr) \
	IfFailRetEx(hr, hr);

/// Trace
#ifdef _ATL // ATL used
    #define ENVSDK_TRACE ATLTRACE2
    extern CTraceCategory envsdkTraceGeneral;
#else   // no ATL
    #error no ATL tracing
#endif
