//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (C) 1992-2000 Microsoft Corporation
// All rights reserved.
//
// This code was originally ported from the Microsoft Foundation Class Library.
//
// Implementation of parameterized Array
//
//-----------------------------------------------------------------------------

#include "hu_pch.h"
#include "mfcincl.h"

/////////////////////////////////////////////////////////////////////////////
CVxPtrArray::CVxPtrArray()
{
    m_pData = NULL;
    m_nSize = m_nMaxSize = m_nGrowBy = 0;
}

CVxPtrArray::~CVxPtrArray()
{
    ASSERT_VALID(this);

    delete[] (BYTE*)m_pData;
}

void CVxPtrArray::SetSize(int nNewSize, int nGrowBy)
{
    ASSERT_VALID(this);
    ASSERT(nNewSize >= 0);

    if (nGrowBy != -1)
        m_nGrowBy = nGrowBy;  // set new size

    if (nNewSize == 0)
    {
        // shrink to nothing
        delete[] (BYTE*)m_pData;
        m_pData = NULL;
        m_nSize = m_nMaxSize = 0;
    }
    else if (m_pData == NULL)
    {
        // create one with exact size
#ifdef SIZE_T_MAX
        ASSERT(nNewSize <= SIZE_T_MAX/sizeof(void*));    // no overflow
#endif
        m_pData = (void**) new BYTE[nNewSize * sizeof(void*)];

        ASSERT(m_pData);

        if(!m_pData)
            return;

        memset(m_pData, 0, nNewSize * sizeof(void*));  // zero fill

        m_nSize = m_nMaxSize = nNewSize;
    }
    else if (nNewSize <= m_nMaxSize)
    {
        // it fits
        if (nNewSize > m_nSize)
        {
            // initialize the new elements

            memset(&m_pData[m_nSize], 0, (nNewSize-m_nSize) * sizeof(void*));

        }

        m_nSize = nNewSize;
    }
    else
    {
        // otherwise, grow array
        int nGrowBy = m_nGrowBy;
        if (nGrowBy == 0)
        {
            // heuristically determine growth when nGrowBy == 0
            //  (this avoids heap fragmentation in many situations)
            nGrowBy = min(1024, max(4, m_nSize / 8));
        }
        int nNewMax;
        if (nNewSize < m_nMaxSize + nGrowBy)
            nNewMax = m_nMaxSize + nGrowBy;  // granularity
        else
            nNewMax = nNewSize;  // no slush

        ASSERT(nNewMax >= m_nMaxSize);  // no wrap around
#ifdef SIZE_T_MAX
        ASSERT(nNewMax <= SIZE_T_MAX/sizeof(void*)); // no overflow
#endif
        void** pNewData = (void**) new BYTE[nNewMax * sizeof(void*)];

        ASSERT(pNewData);

        if(!pNewData)
            return;

        // copy new data from old
        memcpy(pNewData, m_pData, m_nSize * sizeof(void*));

        // construct remaining elements
        ASSERT(nNewSize > m_nSize);

        memset(&pNewData[m_nSize], 0, (nNewSize-m_nSize) * sizeof(void*));


        // get rid of old stuff (note: no destructors called)
        delete[] (BYTE*)m_pData;
        m_pData = pNewData;
        m_nSize = nNewSize;
        m_nMaxSize = nNewMax;
    }
}

int CVxPtrArray::Append(const CVxPtrArray& src)
{
    ASSERT_VALID(this);
    ASSERT(this != &src);   // cannot append to itself

    int nOldSize = m_nSize;
    SetSize(m_nSize + src.m_nSize);

    memcpy(m_pData + nOldSize, src.m_pData, src.m_nSize * sizeof(void*));

    return nOldSize;
}

void CVxPtrArray::Copy(const CVxPtrArray& src)
{
    ASSERT_VALID(this);
    ASSERT(this != &src);   // cannot append to itself

    SetSize(src.m_nSize);

    ASSERT((m_pData && src.m_pData) || !src.m_nSize);

    if(m_pData && src.m_pData)
        memcpy(m_pData, src.m_pData, src.m_nSize * sizeof(void*));

}

void CVxPtrArray::FreeExtra()
{
    ASSERT_VALID(this);

    if(!m_pData)
        return;

    if (m_nSize != m_nMaxSize)
    {
        // shrink to desired size
#ifdef SIZE_T_MAX
        ASSERT(m_nSize <= SIZE_T_MAX/sizeof(void*)); // no overflow
#endif
        void** pNewData = NULL;
        if (m_nSize != 0)
        {
            pNewData = (void**) new BYTE[m_nSize * sizeof(void*)];

            ASSERT(pNewData);

            if(!pNewData)
                return;

            // copy new data from old
            memcpy(pNewData, m_pData, m_nSize * sizeof(void*));
        }

        // get rid of old stuff (note: no destructors called)
        delete[] (BYTE*)m_pData;
        m_pData = pNewData;
        m_nMaxSize = m_nSize;
    }
}

/////////////////////////////////////////////////////////////////////////////

void CVxPtrArray::SetAtGrow(int nIndex, void* newElement)
{
    ASSERT_VALID(this);
    ASSERT(nIndex >= 0);

    if (nIndex >= m_nSize)
        SetSize(nIndex+1);

    ASSERT(m_pData);

    if(!m_pData)
        return;

    m_pData[nIndex] = newElement;
}

void CVxPtrArray::InsertAt(int nIndex, void* newElement, int nCount)
{
    ASSERT_VALID(this);
    ASSERT(nIndex >= 0);    // will expand to meet need
    ASSERT(nCount > 0);     // zero or negative size not allowed

    if (nIndex >= m_nSize)
    {
        // adding after the end of the array
        SetSize(nIndex + nCount);  // grow so nIndex is valid
    }
    else
    {
        // inserting in the middle of the array
        int nOldSize = m_nSize;
        SetSize(m_nSize + nCount);  // grow it to new size
        // shift old data up to fill gap
        memmove(&m_pData[nIndex+nCount], &m_pData[nIndex],
            (nOldSize-nIndex) * sizeof(void*));

        // re-init slots we copied from

        memset(&m_pData[nIndex], 0, nCount * sizeof(void*));

    }

    // insert new value in the gap
    ASSERT(nIndex + nCount <= m_nSize);

    ASSERT(m_pData);

    if(!m_pData)
        return;

    while (nCount--)
        m_pData[nIndex++] = newElement;
}

void CVxPtrArray::RemoveAt(int nIndex, int nCount)
{
    ASSERT_VALID(this);
    ASSERT(nIndex >= 0);
    ASSERT(nCount >= 0);
    ASSERT(nIndex + nCount <= m_nSize);
    ASSERT(m_pData);

    if(!m_pData)
        return;

    // just remove a range
    int nMoveCount = m_nSize - (nIndex + nCount);

    if (nMoveCount)
        memcpy(&m_pData[nIndex], &m_pData[nIndex + nCount],
            nMoveCount * sizeof(void*));

    m_nSize -= nCount;
}

void CVxPtrArray::InsertAt(int nStartIndex, CVxPtrArray* pNewArray)
{
    ASSERT_VALID(this);
    ASSERT(pNewArray != NULL);
    ASSERT_VALID(pNewArray);
    ASSERT(nStartIndex >= 0);

    if (pNewArray->GetSize() > 0)
    {
        InsertAt(nStartIndex, pNewArray->GetAt(0), pNewArray->GetSize());
        for (int i = 0; i < pNewArray->GetSize(); i++)
            SetAt(nStartIndex + i, pNewArray->GetAt(i));
    }
}

/////////////////////////////////////////////////////////////////////////////
// Diagnostics

#ifdef _DEBUG
void CVxPtrArray::AssertValid() const
{
    if (m_pData == NULL)
    {
        ASSERT(m_nSize == 0);
        ASSERT(m_nMaxSize == 0);
    }
    else
    {
        ASSERT(m_nSize >= 0);
        ASSERT(m_nMaxSize >= 0);
        ASSERT(m_nSize <= m_nMaxSize);
        ASSERT(VxIsValidAddress(m_pData, m_nMaxSize * sizeof(void*)));
    }
}
#endif //_DEBUG
/////////////////////////////////////////////////////////////////////////////
