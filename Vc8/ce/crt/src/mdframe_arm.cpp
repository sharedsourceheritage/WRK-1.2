//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of your Microsoft Windows CE
// Source Alliance Program license form.  If you did not accept the terms of
// such a license, you are not authorized to use this source code.
//
/***
*mdframe.cpp -  Routines for doing control transfers
*
*
*Purpose:
*    ARM specific routines for finding the catch frame for unwind.
*
****/

#include "excpt.h"

#include <mtdll.h>
#include "corecrtstorage.h"
#include <corecrt.h>
#include <ehdata.h>
#include <trnsctrl.h>
#include <eh.h>
#include <ehhooks.h>
#include <ehstate.h>
#include <ehglobs.h>
#include <coredll.h>
#pragma hdrstop

// Find Frame pointer for unwind handler.

EHRegistrationNode *
FindFrameForUnwind (
    EHRegistrationNode *pRN, 
    FuncInfo *pFuncInfo
    )
{
   EHRegistrationNode *Frame=pRN ;
   CATCHFRAMEINFO *pCatchFrame = pCatchChain;

    while( pCatchFrame != NULL ) {
        if (pCatchFrame->pFuncInfo == pFuncInfo) {
            Frame = pCatchFrame->pRN ;
            DEBUGMSG(DBGEH,(TEXT("CatchFrame %08x pFuncInfo %08lx Nest Level %d\r\n"),
                     Frame, pCatchFrame->pFuncInfo, pCatchFrame->NestLevel)) ;
        }
        pCatchFrame = pCatchFrame->next;
    }

    return (Frame) ;
}


EHRegistrationNode *
FindCatchFrame (
    EHRegistrationNode *pRN, 
    ULONG pIndex
    )
{
   EHRegistrationNode *Frame=pRN ;
   CATCHFRAMEINFO *pCatchFrame = pCatchChain;

    if (pIndex <= 1)
            return (Frame) ;

    while( pCatchFrame != NULL ) {
        Frame = pCatchFrame->pRN ;
        DEBUGMSG(DBGEH,(TEXT("====Frame %08x pFuncInfo %08lx Nest Level %d\r\n"),
             Frame, pCatchFrame->pFuncInfo, pCatchFrame->NestLevel)) ;
        pCatchFrame = pCatchFrame->next;
    }

    return (Frame) ;
}


EHRegistrationNode *
AdjustFrameForCatch (
    EHRegistrationNode *pRN,
    FuncInfo *pFuncInfo
    )
{
    ULONG ptrFrame;
    ULONG ptrArguments;

    // If the stack was dynamically aligned, adjust the stack
    // pointer before building the catch object

    if ((FUNC_MAGICNUM(*pFuncInfo) >= EH_MAGIC_NUMBER3) &&
        ((FUNC_FLAGS(*pFuncInfo) & FI_DYNSTKALIGN_FLAG) != 0)) {
        ptrFrame = (ULONG)pRN;
        ptrArguments = ptrFrame + FUNC_OFFSTKALIGN(*pFuncInfo);
        ptrFrame -= ptrArguments & (FUNC_STKALIGN(*pFuncInfo) - 1);
        pRN = (EHRegistrationNode*)ptrFrame;
    }

    return pRN;
}

