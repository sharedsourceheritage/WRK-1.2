//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// This source code is licensed under Microsoft Shared Source License
// Version 1.0 for Windows CE.
// For a copy of the license visit http://go.microsoft.com/fwlink/?LinkId=3223.
//

#include <corecrtstorage.h>

#define INVALID_TLS_INDEX ((DWORD)0xFFFFFFFF)

static DWORD g_tlsIndex = INVALID_TLS_INDEX;

crtGlob_t*
GetCRTStorage(
    void
    )
{
    crtGlob_t* pcrtg;
    DWORD tlsIndex;

    if (g_tlsIndex == INVALID_TLS_INDEX)
    {
        tlsIndex = TlsAlloc();

        if (InterlockedCompareExchange((LPLONG)&g_tlsIndex,
                                       (LONG)tlsIndex,
                                       (LONG)INVALID_TLS_INDEX) != INVALID_TLS_INDEX)
        {
            TlsFree(tlsIndex);
        }
    }

    tlsIndex = g_tlsIndex;

    pcrtg = TlsGetValue(tlsIndex);
    if (pcrtg == 0)
    {
        pcrtg = LocalAlloc(LPTR, sizeof(crtGlob_t));
    }

    if (pcrtg != 0)
    {
        TlsSetValue(tlsIndex, pcrtg);
    }

    return pcrtg;
}

