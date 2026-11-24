//--------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (c) 1994-2000 Microsoft Corporation Inc.
// All rights reserved
//
// Implementation of parmeterized Map from CString to value
//
//---------------------------------------------------------------------------
#include "hu_pch.h"
#include "mfcincl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "strelem.h"  // used for special creation

/////////////////////////////////////////////////////////////////////////////

CVxMapStringToString::CVxMapStringToString(int nBlockSize)
{
    ASSERT(nBlockSize > 0);

    m_pHashTable = NULL;
    m_nHashTableSize = 17;  // default size
    m_nCount = 0;
    m_pFreeList = NULL;
    m_pBlocks = NULL;
    m_nBlockSize = nBlockSize;
}

inline UINT CVxMapStringToString::HashKey(LPCTSTR key) const
{
    UINT nHash = 0;
    while (*key)
        nHash = (nHash<<5) + nHash + *key++;
    return nHash;
}

void CVxMapStringToString::InitHashTable(UINT nHashSize, BOOL bAllocNow)
{
//
// Used to force allocation of a hash table or to override the default
//   hash table size of (which is fairly small)
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

void CVxMapStringToString::RemoveAll()
{
    ASSERT_VALID(this);

    if (m_pHashTable != NULL)
    {
        // destroy elements
        for (UINT nHash = 0; nHash < m_nHashTableSize; nHash++)
        {
            CAssoc* pAssoc;
            for (pAssoc = m_pHashTable[nHash]; pAssoc != NULL;
              pAssoc = pAssoc->pNext)
            {
                DestructElement(&pAssoc->key);  // free up string data

                DestructElement(&pAssoc->value);

            }
        }

        // free hash table
        delete [] m_pHashTable;
        m_pHashTable = NULL;
    }

    m_nCount = 0;
    m_pFreeList = NULL;
    m_pBlocks->FreeDataChain();
    m_pBlocks = NULL;
}

CVxMapStringToString::~CVxMapStringToString()
{
    RemoveAll();
    ASSERT(m_nCount == 0);
}

/////////////////////////////////////////////////////////////////////////////
// Assoc helpers
// same as CList implementation except we store CAssoc's not CNode's
//    and CAssoc's are singly linked all the time

CVxMapStringToString::CAssoc* CVxMapStringToString::NewAssoc()
{
    if (m_pFreeList == NULL)
    {
        // add another block
        CVxPlex* newBlock = CVxPlex::Create(m_pBlocks, m_nBlockSize,
                            sizeof(CVxMapStringToString::CAssoc));
        // chain them into free list
        CVxMapStringToString::CAssoc* pAssoc =
                (CVxMapStringToString::CAssoc*) newBlock->data();
        // free in reverse order to make it easier to debug
        pAssoc += m_nBlockSize - 1;
        for (int i = m_nBlockSize-1; i >= 0; i--, pAssoc--)
        {
            pAssoc->pNext = m_pFreeList;
            m_pFreeList = pAssoc;
        }
    }
    ASSERT(m_pFreeList != NULL);  // we must have something

    CVxMapStringToString::CAssoc* pAssoc = m_pFreeList;
    m_pFreeList = m_pFreeList->pNext;
    m_nCount++;
    ASSERT(m_nCount > 0);  // make sure we don't overflow
    ConstructElement(&pAssoc->key);
//  memcpy(&pAssoc->key, &_cstrPchNil, sizeof(CString));

    ConstructElement(&pAssoc->value);
    return pAssoc;
}

void CVxMapStringToString::FreeAssoc(CVxMapStringToString::CAssoc* pAssoc)
{
    ASSERT(pAssoc);
    if(!pAssoc)
        return;

    DestructElement(&pAssoc->key);  // free up string data

    DestructElement(&pAssoc->value);

    pAssoc->pNext = m_pFreeList;
    m_pFreeList = pAssoc;
    m_nCount--;
    ASSERT(m_nCount >= 0);  // make sure we don't underflow

    // if no more elements, cleanup completely
    if (m_nCount == 0)
        RemoveAll();
}

CVxMapStringToString::CAssoc* CVxMapStringToString::GetAssocAt(LPCTSTR key, UINT& nHash) const
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

/////////////////////////////////////////////////////////////////////////////
BOOL CVxMapStringToString::Lookup(LPCTSTR key, CString& rValue) const
{
    ASSERT_VALID(this);

    UINT nHash;
    CAssoc* pAssoc = GetAssocAt(key, nHash);
    if (pAssoc == NULL)
        return FALSE;  // not in map

    rValue = pAssoc->value;
    return TRUE;
}

BOOL CVxMapStringToString::LookupKey(LPCTSTR key, LPCTSTR& rKey) const
{
    ASSERT_VALID(this);

    UINT nHash;
    CAssoc* pAssoc = GetAssocAt(key, nHash);
    if (pAssoc == NULL)
        return FALSE;  // not in map

    rKey = pAssoc->key;
    return TRUE;
}

CString& CVxMapStringToString::operator[](LPCTSTR key)
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
        pAssoc->nHashValue = nHash;
        pAssoc->key = key;
        // 'pAssoc->value' is a constructed object, nothing more

        // put into hash table
        pAssoc->pNext = m_pHashTable[nHash];
        m_pHashTable[nHash] = pAssoc;
    }
    return pAssoc->value;  // return new reference
}


BOOL CVxMapStringToString::RemoveKey(LPCTSTR key)
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

void CVxMapStringToString::GetNextAssoc(POSITION& rNextPosition,
    CString& rKey, CString& rValue) const
{
    ASSERT_VALID(this);
    ASSERT(m_pHashTable != NULL);  // never call on empty map

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
    CAssoc* pAssocNext;
    if ((pAssocNext = pAssocRet->pNext) == NULL)
    {
        // go to next bucket
        for (UINT nBucket = pAssocRet->nHashValue + 1;
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
void CVxMapStringToString::AssertValid() const
{
    ASSERT(m_nHashTableSize > 0);
    ASSERT(m_nCount == 0 || m_pHashTable != NULL);
        // non-empty map should have hash table
}
#endif //_DEBUG
