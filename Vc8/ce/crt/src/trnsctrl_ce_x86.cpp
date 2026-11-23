//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of your Microsoft Windows CE
// Source Alliance Program license form.  If you did not accept the terms of
// such a license, you are not authorized to use this source code.
//
/***
*trnsctrl.cpp -  Routines for doing control transfers
*
*
*Purpose:
*    Routines for doing control transfers; written using inline
*    assembly in naked functions.  Contains the public routine
*    _CxxFrameHandler, the entry point for the frame handler
*
****/

#include "kernel.h"
#include "excpt.h"

#include <mtdll.h>

#include <ehdata.h>
#include <trnsctrl.h>
#include <eh.h>
#include <ehhooks.h>
#include <process.h>

#pragma hdrstop

/////////////////////////////////////////////////////////////////////////////
//
// _CallMemberFunction0 - call a parameterless member function using __thiscall
//                         calling convention, with 0 parameters.
//

__declspec(naked) void __stdcall _CallMemberFunction0(
    void *pthis,         // Value for 'this' pointer
    void *pmfn             // Pointer to the member function
) {
    __asm {
        pop        eax            // Save return address
        pop        ecx            // Get 'this'
        xchg    [esp],eax    // Get function address, stash return address
        jmp        eax            // jump to the function (function will return
                            // to caller of this func)
        }
    }


/////////////////////////////////////////////////////////////////////////////
//
// _CallMemberFunction1 - call a member function using __thiscall
//                         calling convention, with 1 parameter.
//

__declspec(naked) void __stdcall _CallMemberFunction1(
    void *pthis,         // Value for 'this' pointer
    void *pmfn,         // Pointer to the member function
    void *pthat            // Value of 1st parameter (type assumes copy ctor)
) {
    __asm {
        pop        eax            // Save return address
        pop        ecx            // Get 'this'
        xchg    [esp],eax    // Get function address, stash return address
        jmp        eax            // jump to the function (function will return
                            // to caller of this func)
        }
    }


/////////////////////////////////////////////////////////////////////////////
//
// _CallMemberFunction2 - call a member function using __thiscall
//                         calling convention, with 2 parameter.
//

__declspec(naked) void __stdcall _CallMemberFunction2(
    void *pthis,         // Value for 'this' pointer
    void *pmfn,         // Pointer to the member function
    void *pthat,        // Value of 1st parameter (type assumes copy ctor)
    int      val2            // Value of 2nd parameter (type assumes copy ctor w/vb)
) {
    __asm {
        pop        eax            // Save return address
        pop        ecx            // Get 'this'
        xchg    [esp],eax    // Get function address, stash return address
        jmp        eax            // jump to the function (function will return
                            // to caller of this func)
        }
    }


extern "C" EXCEPTION_DISPOSITION __cdecl __InternalCxxFrameHandler(
    EHExceptionRecord  *pExcept,        // Information for this exception
    EHRegistrationNode *pRN,            // Dynamic information for this frame
    CONTEXT            *pContext,       // Context info
    DispatcherContext  *pDC,            // More dynamic info for this frame
    FuncInfo           *pFuncInfo,      // Static information for this frame
    int                CatchDepth);    // How deeply nested are we?


/////////////////////////////////////////////////////////////////////////////
//
// __CxxFrameHandler3 - Real entrypoint to the runtime; this thunk fixes up
//        the parameters, and then calls the workhorse.
//
extern "C" _CRTIMP __declspec(naked) EXCEPTION_DISPOSITION __cdecl __CxxFrameHandler3(
/*
    EAX=FuncInfo   *pFuncInfo,             // Static information for this frame
*/
    EHExceptionRecord  *pExcept,           // Information for this exception
    EHRegistrationNode *pRN,               // Dynamic information for this frame
    CONTEXT            *pContext,          // Context info
    DispatcherContext  *pDC                // More dynamic info for this frame (ignored on Intel)
) {
    FuncInfo   *pFuncInfo;
    EXCEPTION_DISPOSITION result;

    __asm {
        //
        // Standard function prolog
        //
        push    ebp
        mov     ebp, esp
        sub     esp, __LOCAL_SIZE
        push    ebx
        push    esi
        push    edi
        cld          // A bit of paranoia -- Our code-gen assumes this

        //
        // Save the extra parameter
        //
        mov     pFuncInfo, eax
    }

    result = __InternalCxxFrameHandler(pExcept, pRN, pContext, pDC, pFuncInfo, 0);

    __asm {
        pop     edi
        pop     esi
        pop     ebx
        mov     eax, result
        mov     esp, ebp
        pop     ebp
        ret     0
    }
}

/////////////////////////////////////////////////////////////////////////////
//
// _CallCatchBlock2 - The nitty-gritty details to get the catch called
//        correctly.
//
// We need to guard the call to the catch block with a special registration
// node, so that if there is an exception which should be handled by a try
// block within the catch, we handle it without unwinding the SEH node
// in CallCatchBlock.
//

struct CatchGuardRN {
    EHRegistrationNode *pNext;              // Frame link
    void               *pFrameHandler;      // Frame Handler
    UINT_PTR           RandomCookie;        // __security_cookie XOR node address
    FuncInfo           *pFuncInfo;          // Static info for subject function
    EHRegistrationNode *pRN;                // Dynamic info for subject function
    int                CatchDepth;          // How deeply nested are we?
    };

static EXCEPTION_DISPOSITION __cdecl CatchGuardHandler( EHExceptionRecord*, CatchGuardRN *,  CONTEXT *, void * );

#pragma warning(disable:4733)
void *_CallCatchBlock2(
    EHRegistrationNode *pRN,                // Dynamic info of function with catch
    FuncInfo           *pFuncInfo,          // Static info of function with catch
    void               *handlerAddress,     // Code address of handler
    int                CatchDepth,          // How deeply nested in catch blocks are we?
    unsigned long      NLGCode
) {
    //
    // First, create and link in our special guard node:
    //
    CatchGuardRN CGRN = { NULL,
                          (void*)CatchGuardHandler,
                          __security_cookie ^ (UINT_PTR)&CGRN,
                          pFuncInfo,
                          pRN,
                          CatchDepth + 1
    };

    __asm {
        mov        eax, FS:[0]              // Fetch frame list head
        mov        CGRN.pNext, eax          // Link this node in
        lea        eax, CGRN                // Put this node at the head
        mov        FS:[0], eax
        }

    //
    // Call the catch (Context parameter to CallSettingFrame unused on x86)
    //
    void *continuationAddress = _CallSettingFrame( handlerAddress, pRN, NULL, NLGCode );

    //
    // Unlink our registration node
    //
    __asm {
        mov        eax, CGRN.pNext    // Get parent node
        mov        FS:[0], eax        // Put it at the head
        }

    return continuationAddress;
    }
#pragma warning(default:4733)


/////////////////////////////////////////////////////////////////////////////
//
// CatchGuardHandler - frame handler for the catch guard node.
//
// This function will attempt to find a handler for the exception within
// the current catch block (ie any nested try blocks).  If none is found,
// or the handler rethrows, returns ExceptionContinueSearch; otherwise does
// not return.
//
// Does nothing on an unwind.
//

static EXCEPTION_DISPOSITION __cdecl CatchGuardHandler(
    EHExceptionRecord  *pExcept,           // Information for this exception
    CatchGuardRN       *pRN,               // The special marker frame
    CONTEXT            *pContext,          // Context info
    DispatcherContext  *pDC                // Dispatcher Context
) {
    __asm cld;        // Our code-gen assumes this

    //
    // Validate our registration record, to secure against hacker attacks.
    //

    __security_check_cookie(pRN->RandomCookie ^ (UINT_PTR)pRN);

    return __InternalCxxFrameHandler( pExcept, pRN->pRN, pContext, pDC, pRN->pFuncInfo, pRN->CatchDepth);
    }


/////////////////////////////////////////////////////////////////////////////
//
// _GetRangeOfTrysToCheck - determine which try blocks are of interest, given
//   the current catch block nesting depth.  We only check the trys at a single
//   depth.
//
// Returns:
//      Address of first try block of interest is returned
//      pStart and pEnd get the indices of the range in question
//

TryBlockMapEntry* _GetRangeOfTrysToCheck(
        FuncInfo   *pFuncInfo,
        int                     CatchDepth,
        __ehstate_t curState,
        unsigned   *pStart,
        unsigned   *pEnd
)
{
    TryBlockMapEntry *pEntry = FUNC_PTRYBLOCK(*pFuncInfo, 0);
    unsigned start = FUNC_NTRYBLOCKS(*pFuncInfo);
    unsigned end = start;
    unsigned end1 = end;

    while (CatchDepth >= 0) {
        DEBUGCHK(start != -1);
        start--;

        if ( TBME_HIGH(pEntry[start]) < curState && curState <= TBME_CATCHHIGH(pEntry[start])
                || (start == -1)
        ) {
            CatchDepth--;
            end = end1;
            end1 = start;
        }
    }

    *pStart = ++start;     // We always overshoot by 1 (we may even wrap around)
    *pEnd = end;

    DEBUGCHK( end <= FUNC_NTRYBLOCKS(*pFuncInfo) && start <= end );
    return &(pEntry[start]);
}
