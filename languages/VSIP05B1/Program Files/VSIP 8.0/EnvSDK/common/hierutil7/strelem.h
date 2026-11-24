//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (C) 1992-2000 Microsoft Corporation
// All rights reserved.
//
// This code was originally ported from the Microsoft Foundation Class Library.
//
// Collection implementation helpers
//
//-----------------------------------------------------------------------------

#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

/////////////////////////////////////////////////////////////////////////////
// Special implementations for CStrings
// it is faster to bit-wise copy a CString than to call an official
//   constructor - since an empty CString can be bit-wise copied

// The constructor does have to be called to get the right value for m_pchData
#ifdef new
#pragma push_macro("new")
#undef new
#define _REDEF_NEW
#endif

static inline void ConstructElement(CString* pNewData)
{
//  memcpy(pNewData, &_cstrPchNil, sizeof(CString));
    ::new(pNewData) CString();
}

#ifdef _REDEF_NEW
#pragma pop_macro("new")
#undef _REDEF_NEW
#endif

static inline void DestructElement(CString* pOldData)
{
    pOldData->~CString();
}

static inline void CopyElement(CString* pSrc, CString* pDest)
{
    *pSrc = *pDest;
}

/////////////////////////////////////////////////////////////////////////////
