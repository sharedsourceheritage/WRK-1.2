//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (C) 1992-2000 Microsoft Corporation
// All rights reserved.
//
// This code was originally ported from the Microsoft Foundation Class Library.
//
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __VALIDADD_H__
#define __VALIDADD_H__

// Low level sanity checks for memory blocks
BOOL VxIsValidAddress(const void* lp, UINT nBytes, BOOL bReadWrite = TRUE);
BOOL VxIsValidString(LPCWSTR lpsz, int nLength = -1);
BOOL VxIsValidString(LPCSTR lpsz, int nLength = -1);

#ifdef _DEBUG
#define ASSERT_VALID(pOb)  (pOb->AssertValid())
#else
#define ASSERT_VALID(exp)   ((void)0)
#endif

#endif
