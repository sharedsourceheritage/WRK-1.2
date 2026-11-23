// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// Platform specific defines
#ifndef _WIN32_WCE

#include <afxv_cpu.h>

#ifdef _M_IX86
#define _STACK_CHAR     long
#define _STACK_SHORT    long
#define _STACK_LONG     long
#define _STACK_LONGLONG __int64
#define _STACK_FLOAT    float
#define _STACK_DOUBLE   double
#define _STACK_PTR      void*
#define _SCRATCH_SIZE   16
#define _STACK_OFFSET   0
#define _STACK_MIN      0
#endif

#ifdef _IA64_
#define _ALIGN_DOUBLES  8
#define _ALIGN_STACKPOINTER	16
#define _ALIGN_STACK	8
#define _STACK_CHAR		__int64
#define _STACK_SHORT	__int64
#define _STACK_INT      __int64
#define _STACK_LONG     __int64
#define _STACK_LONGLONG	__int64
#define _STACK_FLOAT    float
#define _STACK_DOUBLE   double
#define _STACK_PTR      void*
#define _SCRATCH_SIZE   (16+(_SHADOW_DOUBLES*sizeof(double)))
#define _STACK_OFFSET   48
#define _STACK_MIN      64 // 8 64-bit registers
#endif

#ifdef _AMD64_
//#define _ALIGN_DOUBLES  8
#define _ALIGN_STACKPOINTER	16
#define _ALIGN_STACK	8
#define _STACK_CHAR		__int64
#define _STACK_SHORT	__int64
#define _STACK_INT      __int64
#define _STACK_LONG     __int64
#define _STACK_LONGLONG	__int64
#define _STACK_FLOAT    float
#define _STACK_DOUBLE   double
#define _STACK_PTR      void*
#define _SCRATCH_SIZE   32
#define _STACK_OFFSET   0
#define _STACK_MIN      0
#endif

#else // !_WIN32_WCE

#define _STACK_LONGLONG __int64

#if defined(MIPSIV) || defined(MIPSIV_FP)
// stack arguments are packed in 8-byte slots
#define _STACK_INT      __int64
#define _STACK_CHAR     __int64
#define _STACK_SHORT    __int64
#define _STACK_LONG     __int64
#else
#define _STACK_INT      int
#define _STACK_CHAR     long
#define _STACK_SHORT    long
#define _STACK_LONG     long
#endif // MIPSIV || MIPSIV_FP

#define _STACK_FLOAT    float
#define _STACK_DOUBLE   double

#if defined(MIPSIV) || defined(MIPSIV_FP)
// stack arguments are packed in 8-byte slots
#define _STACK_PTR      __int64 
#else
#define _STACK_PTR      void*
#endif // MIPSIV || MIPSIV_FP

#if defined(_M_IX86)
#define _SCRATCH_SIZE   16
#define _STACK_OFFSET   0
#define _STACK_MIN      0
#elif defined(MIPSII) || defined(MIPSII_FP) || defined(MIPSIV) || defined(MIPSIV_FP)
#define _ALIGN_DOUBLES  8
#define _SCRATCH_SIZE   0
#define _STACK_OFFSET   0
#define _STACK_MIN      32      // 4 32-bit registers
#elif (_M_SH==4)
#define _ALIGN_DOUBLES  4	
#define _SCRATCH_SIZE   0
#define _STACK_OFFSET   0
#define _STACK_MIN      32      // 4 32-bit registers
#elif defined(_M_ARM) // applies to all variants of ARM
#define _ALIGN_DOUBLES  4
#define _SCRATCH_SIZE   0
#define _STACK_OFFSET   0
#define _STACK_MIN      32      // 4 32-bit registers
#else
#pragma message("Warning: no _AfxDispatchCall information set for this CPU.")
#endif

#endif // !_WIN32_WCE

/////////////////////////////////////////////////////////////////////////////
