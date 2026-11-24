//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//
// File: oleref.cpp
// Area: IHierarchy Utilities implementation
//
// Contents:
//
//-----------------------------------------------------------------------------

// Includes -------------------------------------------------------------------
#include "hu_pch.h"
#include "oleref.h"

//-----------------------------------------------------------------------------
// Name:    FreeOlePtr
//
// Description:
//  Free a pointer allocated through IMalloc
//
//-----------------------------------------------------------------------------
void FreeOlePtr(void * pv)
{
    ASSERT(pv);

    COleRef<IMalloc>    srpMalloc;

    ::CoGetMalloc(MEMCTX_TASK, &srpMalloc);
    ASSERT(srpMalloc != NULL);

    srpMalloc->Free(pv);
}


