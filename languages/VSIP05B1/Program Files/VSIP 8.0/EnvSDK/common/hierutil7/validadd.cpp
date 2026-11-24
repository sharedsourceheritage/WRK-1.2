//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (C) 1992-2000 Microsoft Corporation
// All rights reserved.
//
// This code was originally ported from the Microsoft Foundation Class Library.
//
//-----------------------------------------------------------------------------

#include "hu_pch.h"
#include "validadd.h"

BOOL VxIsValidString(LPCWSTR lpsz, int nLength)
{
    if (lpsz == NULL)
        return FALSE;
    return ::IsBadStringPtrW(lpsz, nLength) == 0;
}

BOOL VxIsValidString(LPCSTR lpsz, int nLength)
{
    if (lpsz == NULL)
        return FALSE;
    return ::IsBadStringPtrA(lpsz, nLength) == 0;
}

BOOL VxIsValidAddress(const void* lp, UINT nBytes, BOOL bReadWrite)
{
    // simple version using Win-32 APIs for pointer validation.
    return (lp != NULL && !IsBadReadPtr(lp, nBytes) &&
        (!bReadWrite || !IsBadWritePtr((LPVOID)lp, nBytes)));
}
