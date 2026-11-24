
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

#ifndef _ASSERTE_MSG
#define _ASSERTE_MSG(expr, msg) _ASSERTE(expr)
#endif

///////////////////////////////////////////////////////////////////////////////
// Error Checking Marcos

#define _ExpectedExprRet(expr) \
	if (!(expr)) \
		{ return E_UNEXPECTED; }

#define ExpectedExprRetMsg(expr, msg) \
    { \
	    _ASSERTE_MSG(expr, msg); \
	    _ExpectedExprRet(expr); \
    } \

#define ExpectedExprRet(expr) \
    { \
	    _ASSERTE(expr); \
	    _ExpectedExprRet(expr); \
    } \


#define _ExpectedExprGo(expr) \
	if (!(expr)) \
		{ hr = E_UNEXPECTED; goto OnError; }

#define ExpectedExprGoMsg(expr, msg) \
    { \
	    _ASSERTE_MSG(expr, msg); \
	    _ExpectedExprGo(expr); \
    }

#define ExpectedExprGo(expr) \
    { \
	    _ASSERTE(expr); \
	    _ExpectedExprGo(expr); \
    }


#define _ExpectedPtrRet(ptr) \
	if (!(ptr)) \
		{ return E_POINTER; }

#define ExpectedPtrRetMsg(ptr, msg) \
    { \
	    _ASSERTE_MSG(ptr, msg); \
	    _ExpectedPtrRet(ptr); \
    }

#define ExpectedPtrRet(ptr) \
    { \
	    _ASSERTE(ptr); \
	    _ExpectedPtrRet(ptr); \
    }


#define _ExpectedPtrGo(ptr) \
	if (!(ptr)) \
		{ hr = E_POINTER; goto OnError; }

#define ExpectedPtrGoMsg(ptr, msg) \
    { \
	    _ASSERTE_MSG(ptr, msg); \
	    _ExpectedPtrGo(ptr); \
    }

#define ExpectedPtrGo(ptr) \
    { \
	    _ASSERTE(ptr); \
	    _ExpectedPtrGo(ptr); \
    }

#define _IfNullRet(param) \
	if (param == NULL) \
		{ return E_INVALIDARG; }

#define IfNullRetMsg(param, msg) \
    { \
	    _ASSERTE_MSG(param, msg); \
	    _IfNullRet(param); \
    }

#define IfNullRet(param) \
    { \
	    _ASSERTE(param); \
	    _IfNullRet(param); \
    }


#define _IfNullGo(param) \
	if (param == NULL) \
		{ hr = E_UNEXPECTED; goto OnError; }

#define IfNullGoMsg(param, msg) \
    { \
	    _ASSERTE_MSG(param, msg); \
	    _IfNullGo(param); \
    }

#define IfNullGo(param) \
    { \
	    _ASSERTE(param); \
	    _IfNullGo(param); \
    }


#define IfFailAllocRet(ptr) \
	if (!(ptr)) \
		{ return E_OUTOFMEMORY; }


#define IfFailAllocGo(ptr) \
	if (!(ptr)) \
		{ hr = E_OUTOFMEMORY; goto OnError; }


#define _IfFailRetEx(hr, hrReturn) \
	if (FAILED(hr)) \
		{ return hrReturn; }

#define IfFailRetExMsg(hr, hrReturn, msg) \
    { \
	    _ASSERTE_MSG(SUCCEEDED(hr), msg); \
	    _IfFailRetEx(hr, hrReturn); \
    }

#define IfFailRetEx(hr, hrReturn) \
    { \
	    _ASSERTE(SUCCEEDED(hr)); \
	    _IfFailRetEx(hr, hrReturn); \
    }


#define _IfFailRet(hr) \
	_IfFailRetEx(hr, hr);

#define IfFailRetMsg(hr, msg) \
	IfFailRetExMsg(hr, hr, msg);

#define IfFailRet(hr) \
	IfFailRetEx(hr, hr);


#define _IfFailGoEx(hr, hrSet) \
	if (FAILED(hr)) \
		{ hr = hrSet; goto OnError; }

#define IfFailGoExMsg(hr, hrSet, msg) \
    { \
	    _ASSERTE_MSG(SUCCEEDED(hr), msg); \
	    _IfFailGoEx(hr, hrSet); \
    }

#define IfFailGoEx(hr, hrSet) \
    { \
	    _ASSERTE(SUCCEEDED(hr)); \
	    _IfFailGoEx(hr, hrSet); \
    }


#define _IfFailGo(hr) \
    if (FAILED(hr)) \
        { goto OnError; }

#define IfFailGoMsg(hr, msg) \
    { \
        _ASSERTE_MSG(SUCCEEDED(hr), msg); \
        _IfFailGo(hr); \
    }

#define IfFailGo(hr) \
    { \
        _ASSERTE(SUCCEEDED(hr)); \
        _IfFailGo(hr); \
    }


#define _CheckZombieState(fZombie) \
    if (fZombie) \
        return E_UNEXPECTED;

#define CheckZombieState(fZombie) \
    { \
        _ASSERTE_MSG(!fZombie, "Object is in zombie state!"); \
        _CheckZombieState(fZombie); \
    }


///////////////////////////////////////////////////////////////////////////////
// AtlCreateInstance and AtlCreateAggInstance

#define AtlCreateInstance(ClassName, riid, ppUnk) \
	{ \
		CComObject<ClassName>* pObject = NULL; \
		if(SUCCEEDED(CComObject<ClassName>::CreateInstance(&pObject)) && pObject) \
		{ \
			hr = pObject->QueryInterface(riid, (void**)ppUnk); \
		} \
		else \
			hr = E_OUTOFMEMORY; \
	}

#define AtlCreateAggInstance(ClassName, riid, pUnkOuter, ppUnk) \
	{ \
		CComAggObject<ClassName>* pObject = NULL; \
		if (SUCCEEDED(CComAggObject<ClassName>::CreateInstance(pUnkOuter, &pObject)) && pObject) \
		{ \
			hr = pObject->QueryInterface(riid, (void**)ppUnk); \
		} \
		else \
			hr = E_OUTOFMEMORY; \
	}


///////////////////////////////////////////////////////////////////////////////
// SafeInitParam and InitParam

#define SafeInitParamTo(param, value) \
	if (param) \
		*param = value;

#define SafeInitParam(param) \
	SafeInitParamTo(param, NULL);

#define InitParamTo(param, value) \
    { \
	    _ASSERTE(param); \
	    *param = value; \
    }

#define InitParam(param) \
	InitParamTo(param, NULL);


// AddRef/Release with guard for NULL
#ifndef ADDREF
#define ADDREF(PUNK) { if (PUNK) (PUNK)->AddRef(); }
#endif

#ifndef RELEASE
#define RELEASE(PUNK)                \
{                                    \
    if (PUNK)                        \
    {                                \
        LPUNKNOWN punkXXX = (PUNK);  \
        (PUNK) = NULL;               \
        punkXXX->Release();          \
    }                                \
}

#endif

/// Trace
#ifdef _ATL // ATL used

    #define ENVSDK_TRACE ATLTRACE2
    extern CTraceCategory envsdkTraceGeneral;

#else   // no ATL
    #error no ATL tracing
#endif
