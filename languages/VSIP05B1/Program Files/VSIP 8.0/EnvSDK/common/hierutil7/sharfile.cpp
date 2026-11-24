//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (c) 1997 - 2000, Microsoft Corporation
// All Rights Reserved
//
//---------------------------------------------------------------------------
#include "hu_pch.h"
#include "VsFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////
// CVsSharedFile implementation

CVsSharedFile::CVsSharedFile(UINT nAllocFlags, UINT nGrowBytes)
    : CVsMemFile(nGrowBytes)
{
    m_nAllocFlags = nAllocFlags;
    m_hGlobalMemory = NULL;
    m_bAllowGrow = TRUE;
}

CVsSharedFile::~CVsSharedFile()
{
    if (m_lpBuffer)
        Close();        // call appropriate Close/Free
    ASSERT(m_lpBuffer == NULL);
}

void CVsSharedFile::SetHandle(HGLOBAL hGlobalMemory, BOOL bAllowGrow)
{
    ASSERT(m_hGlobalMemory == NULL);        // do once only
    ASSERT(m_lpBuffer == NULL);     // do once only
    ASSERT(m_nPosition == 0);

    m_hGlobalMemory = hGlobalMemory;
    m_lpBuffer = (BYTE*)::GlobalLock(m_hGlobalMemory);
    ASSERT(::GlobalSize(m_hGlobalMemory) < INT_MAX);
    m_nBufferSize = m_nFileSize = (LONG32) ::GlobalSize(m_hGlobalMemory);
    m_bAllowGrow = bAllowGrow;
}

BYTE* CVsSharedFile::Alloc(DWORD nBytes)
{
    ASSERT(m_hGlobalMemory == NULL);        // do once only
    m_hGlobalMemory = ::GlobalAlloc(m_nAllocFlags, nBytes);
    if (m_hGlobalMemory == NULL)
        return NULL;
    return (BYTE*)::GlobalLock(m_hGlobalMemory);
}

BYTE* CVsSharedFile::Realloc(BYTE*, DWORD nBytes)
{
    if (!m_bAllowGrow)
        return NULL;
    ASSERT(m_hGlobalMemory != NULL);
    ::GlobalUnlock(m_hGlobalMemory);
    HGLOBAL hNew;
    hNew = ::GlobalReAlloc(m_hGlobalMemory, nBytes, m_nAllocFlags);
    if (hNew == NULL)
        return NULL;
    m_hGlobalMemory = hNew;
    return (BYTE*)::GlobalLock(m_hGlobalMemory);
}

void CVsSharedFile::Free(BYTE*)
{
    ASSERT(m_hGlobalMemory != NULL);
    ::GlobalUnlock(m_hGlobalMemory);
    ::GlobalFree(m_hGlobalMemory);
}

HGLOBAL CVsSharedFile::Detach()
{
    HGLOBAL hMem;
    ASSERT(m_hGlobalMemory != NULL);
    hMem = m_hGlobalMemory;

    m_hGlobalMemory = NULL; // detach from global handle

    // re-initialize the CMemFile parts too
    m_lpBuffer = NULL;
    m_nBufferSize = 0;

    return hMem;
}

