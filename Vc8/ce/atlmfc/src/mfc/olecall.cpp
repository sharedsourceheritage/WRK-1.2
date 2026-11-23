// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"


// Note: because of the nature of these functions, it is not possible
//  to create a 'C' or 'C++' version of them.  These functions are used
//  for the lowest level of the OLE IDispatch implementation, and need
//  to be ported to each supported platform.

extern "C" {

#ifndef _WIN32_WCE
/////////////////////////////////////////////////////////////////////////////
// Intel 386 version

#ifdef _M_IX86

__declspec(naked) void AFXAPI
_AfxDispatchCall(AFX_PMSG /*pfn*/, void* /*pArgs*/, UINT /*nSizeArgs*/)
{
	_asm
	{
		pop     edx         // edx = return address
		pop     eax         // eax = pfn
		pop     ecx         // ecx = pArgs
		add     ecx,[esp]   // ecx += nSizeArgs (=scratch area)
		mov     [ecx],edx   // scratch[0] = return address
		sub     ecx,[esp]   // ecx = pArgs (again)
		mov     esp,ecx     // esp = pArgs (usually already correct)
		pop     ecx         // ecx = this pointer (the CCmdTarget*)
		call    eax         // call member function
		ret                 // esp[0] should = scratch[0] = return address
	}
}
#endif // _M_IX86

/////////////////////////////////////////////////////////////////////////////
// AMD 64 version

#ifdef _AMD64_

// Note: AMD64 version is in src\x8664\olecall_.s

// The AMD64 compiler does not support inline assembly, so it
//  must be built separately with the MASM assembler.

#endif // _AMD64_

/////////////////////////////////////////////////////////////////////////////
// MIPS R4000 version

#ifdef _MIPS_

extern "C" void _asm(char *, ...);
void AFXAPI
_AfxDispatchCall(AFX_PMSG /*pfn*/, void* /*pArgs*/, UINT /*nSizeArgs*/)
{
	_asm("addiu     %sp,%a1,0x0");      // sp = pArgs
	_asm("addiu     %t6,%a0,0x0");      // t6 = pfn (save it)
	_asm("lw        %a0,0x0(%sp)");     // a0 = param0
	_asm("lw        %a1,0x4(%sp)");     // a1 = param1
	_asm("lw        %a2,0x8(%sp)");     // a2 = param2
	_asm("lw        %a3,0xc(%sp)");     // a3 = param3
	_asm("j         %t6");              // ip = pfn (jump to target function)
}

#endif // _MIPS_

/////////////////////////////////////////////////////////////////////////////
// DEC Alpha AXP version

#ifdef _ALPHA_

// Note: ALPHA version is in src\alpha\olecall_.s

// The ALPHA compiler does not support inline assembly, so it
//  must be build separately with the ASAXP assembler.

#endif // _ALPHA_

#ifdef _IA64_

// Note: IA64 version is in src\ia64\olecall_.s

// The IA64 compiler does not support inline assembly, so it
//  must be built separately with the IAS assembler.

#endif

#else // !_WIN32_WCE

// AFXAPI uses __stdcall, which maps to __cdecl under Windows CE
__declspec(naked) void AFXAPI
_AfxDispatchCall(AFX_PMSG /*pfn*/, void* /*pArgs*/, UINT /*nSizeArgs*/)
{
#if defined(_M_IX86)
	_asm
	{
		pop     edx         // edx = return address
		pop     eax         // eax = pfn
		pop     ecx         // ecx = pArgs
		add     ecx,[esp]   // ecx += nSizeArgs (=scratch area)
		mov     [ecx],edx   // scratch[0] = return address
		sub     ecx,[esp]   // ecx = pArgs (again)
		mov     esp,ecx     // esp = pArgs (usually already correct)
		pop     ecx         // ecx = this pointer (the CCmdTarget*)
		call    eax         // call member function
		ret                 // esp[0] should = scratch[0] = return address
	}
#elif defined(ARMV4)
	// Set up the stack pointer. Note that the first four dwords of arguments
	// are saved on the callee's stack so 16 is added to the pointer to
	// the arguments.
	__emit(0xe281d010);     // add  sp, r1, #16
	// Save the function pointer in r12 (the only available scratch register)
	__emit(0xe1a0c000);     // mov  r12, r0
	// Copy four words of arguments into r0-r3
	__emit(0xe5910000);     // ldr  r0, [r1]
	__emit(0xe5912008);     // ldr  r2, [r1, #8]
	__emit(0xe591300c);     // ldr  r3, [r1, #12]
	__emit(0xe5911004);     // ldr  r1, [r1, #4]
	// Jump to the function
	__emit(0xe1a0f00c);     // mov  pc, r12
#elif defined(ARMV4I)
	// Set up the stack pointer. Note that the first four dwords of arguments
	// are saved on the callee's stack so 16 is added to the pointer to
	// the arguments.
	__emit(0xe281d010);     // add  sp, r1, #16
	// Save the function pointer in r12 (the only available scratch register)
	__emit(0xe1a0c000);     // mov  r12, r0
	// Copy four words of arguments into r0-r3
	__emit(0xe5910000);     // ldr  r0, [r1]
	__emit(0xe5912008);     // ldr  r2, [r1, #8]
	__emit(0xe591300c);     // ldr  r3, [r1, #12]
	__emit(0xe5911004);     // ldr  r1, [r1, #4]
	// Jump to the function
	__emit(0xe12fff1c);     // bx   r12
#elif defined(MIPSII)
	__asm("addiu %sp,%a1,0x0");      // sp = pArgs
	__asm("addiu %t6,%a0,0x0");      // t6 = pfn (save it)
	__asm("lw    %a0,0x0(%sp)");     // a0 = param0
	__asm("lw    %a1,0x4(%sp)");     // a1 = param1
	__asm("lw    %a2,0x8(%sp)");     // a2 = param2
	__asm("lw    %a3,0xc(%sp)");     // a3 = param3
	__asm("j     %t6");              // ip = pfn (jump to target function)
#elif defined(MIPSIV)
    __asm("addiu     %sp,%a1,0x0");      // sp = pArgs
    __asm("addiu     %t6,%a0,0x0");      // t6 = pfn (save it)
    __asm("ld        %a0,0x0(%sp)");     // a0 = param0
    __asm("ld        %a1,0x8(%sp)");     // a1 = param1
    __asm("ld        %a2,0x10(%sp)");    // a2 = param2
    __asm("ld        %a3,0x18(%sp)");    // a3 = param3
    __asm("j         %t6");              // ip = pfn (jump to target function)
#elif defined(MIPSII_FP) || defined(MIPSIV_FP)
    // nothing, the thunk builder will take care of things for us
#elif (_M_SH==4)
    // We need to deal with the function arguments, packaged on the stack,
    // in a special way. So AfxDispatchCall will not be used for these
    // processors. Rather, a special function will be called instead of
    // AfxDispatchCall. The reason for special handling is because of the
    // way floating point values are passed on the stack. At present,
    // none of the other architectures bother about floating point values
    // at all. As a result, for these processors, we need to generate a
    // thunk on the fly, encode and execute it dynamically. At present,
    // for other architectures, we are statically creating a thunk that
    // will work well for int arguments.
    // unresolved external symbol ___asm
    // __asm("nop\n");
#else
	#error No _AfxDispatchCall implementation found for this CPU.
#endif
}
#endif // !_WIN32_WCE

} // end extern "C" block

/////////////////////////////////////////////////////////////////////////////
