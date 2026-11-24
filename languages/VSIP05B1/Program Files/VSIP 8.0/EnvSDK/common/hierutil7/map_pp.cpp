//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// This code was originally ported from the Microsoft Foundation Class Library.
//
// Implementation of parmeterized Map
//
//-----------------------------------------------------------------------------

#include "hu_pch.h"
#include "mfcincl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Plex code stuck here.
CVxPlex* PASCAL CVxPlex::Create(CVxPlex*& pHead, UINT nMax, UINT cbElement)
{
    ASSERT(nMax > 0 && cbElement > 0);
    CVxPlex* p = (CVxPlex*) new BYTE[sizeof(CVxPlex) + nMax * cbElement];
            // may throw exception
    ASSERT(p);
    if(!p)
        return NULL;
    p->pNext = pHead;
    pHead = p;  // change head (adds in reverse order for simplicity)
    return p;
}

void CVxPlex::FreeDataChain()     // free this one and links
{
    CVxPlex* p = this;
    while (p != NULL)
    {
        BYTE* bytes = (BYTE*) p;
        CVxPlex* pNext = p->pNext;
        delete[] bytes;
        p = pNext;
    }
}

/////////////////////////////////////////////////////////////////////////////

CVxMapPtrToPtr::CVxMapPtrToPtr(int nBlockSize)
{
    ASSERT(nBlockSize > 0);

    m_pHashTable = NULL;
    m_nHashTableSize = 17;  // default size
    m_nCount = 0;
    m_pFreeList = NULL;
    m_pBlocks = NULL;
    m_nBlockSize = nBlockSize;
}

inline UINT CVxMapPtrToPtr::HashKey(void* key) const
{
    // default identity hash - works for most primitive values
    return ((UINT)(DWORD_PTR)key) >> 4;
}

void CVxMapPtrToPtr::InitHashTable(UINT nHashSize, BOOL bAllocNow)
//
// Used to force allocation of a hash table or to override the default
//   hash table size of (which is fairly small)
{
    ASSERT_VALID(this);
    ASSERT(m_nCount == 0);
    ASSERT(nHashSize > 0);

    if (m_pHashTable != NULL)
    {
        // free hash table
        delete[] m_pHashTable;
        m_pHashTable = NULL;
    }

    if (bAllocNow)
    {
        m_pHashTable = new CAssoc* [nHashSize];
        ASSERT(m_pHashTable);
        if(!m_pHashTable)
            return;
        memset(m_pHashTable, 0, sizeof(CAssoc*) * nHashSize);
    }
    m_nHashTableSize = nHashSize;
}

void CVxMapPtrToPtr::RemoveAll()
{
    ASSERT_VALID(this);
    if (m_pHashTable != NULL)
    {
        // free hash table
        delete[] m_pHashTable;
        m_pHashTable = NULL;
    }

    m_nCount = 0;
    m_pFreeList = NULL;
    m_pBlocks->FreeDataChain();
    m_pBlocks = NULL;
}

CVxMapPtrToPtr::~CVxMapPtrToPtr()
{
    RemoveAll();
    ASSERT(m_nCount == 0);
}

/////////////////////////////////////////////////////////////////////////////
// Assoc helpers
// same as CList implementation except we store CAssoc's not CNode's
//    and CAssoc's are singly linked all the time

CVxMapPtrToPtr::CAssoc*
CVxMapPtrToPtr::NewAssoc()
{
    if (m_pFreeList == NULL)
    {
        // add another block
        CVxPlex* newBlock = CVxPlex::Create(m_pBlocks, m_nBlockSize, sizeof(CVxMapPtrToPtr::CAssoc));
        // chain them into free list
        CVxMapPtrToPtr::CAssoc* pAssoc = (CVxMapPtrToPtr::CAssoc*) newBlock->data();
        // free in reverse order to make it easier to debug
        pAssoc += m_nBlockSize - 1;
        for (int i = m_nBlockSize-1; i >= 0; i--, pAssoc--)
        {
            pAssoc->pNext = m_pFreeList;
            m_pFreeList = pAssoc;
        }
    }
    ASSERT(m_pFreeList != NULL);  // we must have something

    CVxMapPtrToPtr::CAssoc* pAssoc = m_pFreeList;
    m_pFreeList = m_pFreeList->pNext;
    m_nCount++;
    ASSERT(m_nCount > 0);  // make sure we don't overflow

    pAssoc->key = 0;
    pAssoc->value = 0;

    return pAssoc;
}

void CVxMapPtrToPtr::FreeAssoc(CVxMapPtrToPtr::CAssoc* pAssoc)
{

    pAssoc->pNext = m_pFreeList;
    m_pFreeList = pAssoc;
    m_nCount--;
    ASSERT(m_nCount >= 0);  // make sure we don't underflow

    // if no more elements, cleanup completely
    if (m_nCount == 0)
        RemoveAll();
}

CVxMapPtrToPtr::CAssoc* CVxMapPtrToPtr::GetAssocAt(void* key, UINT& nHash) const
// find association (or return NULL)
{
    nHash = HashKey(key) % m_nHashTableSize;

    if (m_pHashTable == NULL)
        return NULL;

    // see if it exists
    CAssoc* pAssoc;
    for (pAssoc = m_pHashTable[nHash]; pAssoc != NULL; pAssoc = pAssoc->pNext)
    {
        if (pAssoc->key == key)
            return pAssoc;
    }
    return NULL;
}


void* CVxMapPtrToPtr::GetValueAt(void* key) const
// find value (or return NULL -- NULL values not different as a result)
{
    if (m_pHashTable == NULL)
        return NULL;

    UINT nHash = HashKey(key) % m_nHashTableSize;

    // see if it exists
    CAssoc* pAssoc;
    for (pAssoc = m_pHashTable[nHash]; pAssoc != NULL; pAssoc = pAssoc->pNext)
    {
        if (pAssoc->key == key)
            return pAssoc->value;
    }
    return NULL;
}


/////////////////////////////////////////////////////////////////////////////
BOOL CVxMapPtrToPtr::Lookup(void* key, void*& rValue) const
{
    ASSERT_VALID(this);

    UINT nHash;
    CAssoc* pAssoc = GetAssocAt(key, nHash);
    if (pAssoc == NULL)
        return FALSE;  // not in map

    rValue = pAssoc->value;
    return TRUE;
}

void*& CVxMapPtrToPtr::operator[](void* key)
{
    ASSERT_VALID(this);

    UINT nHash;
    CAssoc* pAssoc;
    if ((pAssoc = GetAssocAt(key, nHash)) == NULL)
    {
        if (m_pHashTable == NULL)
            InitHashTable(m_nHashTableSize);

        ASSERT(m_pHashTable);
        
        // it doesn't exist, add a new Association
        pAssoc = NewAssoc();

        pAssoc->key = key;
        // 'pAssoc->value' is a constructed object, nothing more

        // put into hash table
        pAssoc->pNext = m_pHashTable[nHash];
        m_pHashTable[nHash] = pAssoc;
    }
    return pAssoc->value;  // return new reference
}


BOOL CVxMapPtrToPtr::RemoveKey(void* key)
// remove key - return TRUE if removed
{
    ASSERT_VALID(this);

    if (m_pHashTable == NULL)
        return FALSE;  // nothing in the table

    CAssoc** ppAssocPrev;
    ppAssocPrev = &m_pHashTable[HashKey(key) % m_nHashTableSize];

    CAssoc* pAssoc;
    for (pAssoc = *ppAssocPrev; pAssoc != NULL; pAssoc = pAssoc->pNext)
    {
        if (pAssoc->key == key)
        {
            // remove it
            *ppAssocPrev = pAssoc->pNext;  // remove from list
            FreeAssoc(pAssoc);
            return TRUE;
        }
        ppAssocPrev = &pAssoc->pNext;
    }
    return FALSE;  // not found
}


/////////////////////////////////////////////////////////////////////////////
// Iterating

void CVxMapPtrToPtr::GetNextAssoc(POSITION& rNextPosition,
    void*& rKey, void*& rValue) const
{
    ASSERT_VALID(this);
    ASSERT(m_pHashTable != NULL);  // never call on empty map
    if(!m_pHashTable)
    {
        rNextPosition = NULL;
        return;
    }

    CAssoc* pAssocRet = (CAssoc*)rNextPosition;
    ASSERT(pAssocRet != NULL);

    if (pAssocRet == (CAssoc*) BEFORE_START_POSITION)
    {
        // find the first association
        for (UINT nBucket = 0; nBucket < m_nHashTableSize; nBucket++)
            if ((pAssocRet = m_pHashTable[nBucket]) != NULL)
                break;
        ASSERT(pAssocRet != NULL);  // must find something
    }

    // find next association
    ASSERT(VxIsValidAddress(pAssocRet, sizeof(CAssoc)));
    if(!pAssocRet)
        return;
    CAssoc* pAssocNext;
    if ((pAssocNext = pAssocRet->pNext) == NULL)
    {

        // go to next bucket
        for (UINT nBucket = (HashKey(pAssocRet->key) % m_nHashTableSize) + 1;
          nBucket < m_nHashTableSize; nBucket++)
            if ((pAssocNext = m_pHashTable[nBucket]) != NULL)
                break;

    }

    rNextPosition = (POSITION) pAssocNext;

    // fill in return data
    rKey = pAssocRet->key;
    rValue = pAssocRet->value;
}


/////////////////////////////////////////////////////////////////////////////
// Diagnostics

#ifdef _DEBUG
void CVxMapPtrToPtr::AssertValid() const
{
    ASSERT(m_nHashTableSize > 0);
    ASSERT(m_nCount == 0 || m_pHashTable != NULL);
        // non-empty map should have hash table
}
#endif //_DEBUG
