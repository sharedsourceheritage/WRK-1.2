
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
***************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// ARRAY.CPP

#include "pch.h"

#include "util.h"
#include "vsmem.h"

#define Assert(exp) VSASSERT(exp, "")
#undef ASSERT
#define ASSERT(exp) VSASSERT(exp, "")
#undef VERIFY
#define VERIFY(exp) VSASSERT(exp, "")

#pragma intrinsic(memcpy, memcmp)

/////////////////////////////////////////////////////////////////////////////
// CEnvSDKPtrArrayImpl::CEnvSDKPtrArrayImpl

//---------------------------------------------------------------------------
CEnvSDKPtrArrayImpl::~CEnvSDKPtrArrayImpl()
{
    if (m_ppData) VSFree(m_ppData);
}

//---------------------------------------------------------------------------
void CEnvSDKPtrArrayImpl::_Attach (size_t cel, void ** ppData)
{
    if (m_ppData) VSFree(m_ppData);
    m_ppData = ppData;
    m_iAlloc = m_iCount = cel;
}

//---------------------------------------------------------------------------
BOOL CEnvSDKPtrArrayImpl::RemoveAt(size_t i)
{
    if (i >= 0 && i < m_iCount)
    {
        memcpy(m_ppData + i, m_ppData + i + 1, (m_iCount - (i + 1)) * sizeof(void*));
        m_iCount--;
        return TRUE;
    }

    return FALSE;
}

//---------------------------------------------------------------------------
BOOL CEnvSDKPtrArrayImpl::_InsertAt(size_t i, void* pObj)
{
    if (m_iCount == m_iAlloc)
        if (!_ReallocData(m_iAlloc + ALLOC_INCR))
            return FALSE;
    m_iCount++;
    if (i >= 0 && i < m_iCount)
    {
        memmove(m_ppData + i + 1, m_ppData + i, (m_iCount - (i + 1)) * sizeof(void*));
        m_ppData[i] = pObj;
        return TRUE;
    }
    return FALSE;
}

//---------------------------------------------------------------------------
void* CEnvSDKPtrArrayImpl::_GetAt(size_t i)
{
    if (i >= 0 && i < m_iCount)
        return m_ppData[i];

    return NULL;
}

//---------------------------------------------------------------------------
void CEnvSDKPtrArrayImpl::_SetAt(size_t i, void* pObj)
{
    if (i >= 0 && i < m_iCount)
        m_ppData[i] = pObj;
}

//---------------------------------------------------------------------------
BOOL CEnvSDKPtrArrayImpl::_Add(void* pObj)
{
    if (m_iCount == m_iAlloc)
    {
        size_t iNewSize = m_iAlloc;
        if (m_iAlloc <= m_MaxArraySize/2)
            iNewSize = m_iAlloc * 2;
        else if (m_iAlloc <= m_MaxArraySize-ALLOC_INCR)
            iNewSize = m_iAlloc + ALLOC_INCR;
        iNewSize = max(ALLOC_INCR, iNewSize);       // at least ALLOC_INCR
        if (iNewSize <= m_iAlloc)
            return FALSE;
        if (!_ReallocData(iNewSize))
        {
            return FALSE;
        }
    }
    m_ppData[m_iCount++] = pObj;
    return TRUE;
}

//---------------------------------------------------------------------------
BOOL CEnvSDKPtrArrayImpl::_Remove(void* pObj)
{
    for (size_t i = 0; i < m_iCount; i++)
    {
        if (m_ppData[i] == pObj)
        {
            RemoveAt(i);
            return TRUE;
        }
    }

    return FALSE;
}

//---------------------------------------------------------------------------
BOOL CEnvSDKPtrArrayImpl::_ReallocData(size_t iAlloc)
{
    if (iAlloc == m_iAlloc)
        return TRUE;

    if (iAlloc > m_MaxArraySize)
        return FALSE;

    void** pData = (void**)(m_ppData ? VSRealloc(m_ppData, iAlloc * sizeof(void*)) :
                                       VSAlloc(iAlloc * sizeof(void*)));
    if (pData == NULL)
        return FALSE;

    m_iAlloc = iAlloc;
    m_ppData = pData;
    return TRUE;
}

//---------------------------------------------------------------------------
void CEnvSDKPtrArrayImpl::_Sort(int (__cdecl *compare )(const void *p1, const void *p2))
{
    if (m_iCount > 0)
        qsort(&m_ppData[0], m_iCount, sizeof(void *), compare);
}

//---------------------------------------------------------------------------
int CEnvSDKPtrArrayImpl::_BSearch(const void *key, int (__cdecl *compare )(const void *p1, const void *p2))
{
    if (m_iCount <= 0 || !m_ppData)
        return -1;
    const void ** p = (const void **)bsearch(key, m_ppData, m_iCount, sizeof(void*), compare);
    if (p)
        return (LONG32)(p - m_ppData);
    else
        return -1;
}

