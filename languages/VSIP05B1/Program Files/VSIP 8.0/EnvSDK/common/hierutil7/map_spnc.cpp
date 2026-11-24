//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (C) 1992-2000 Microsoft Corporation
// All rights reserved.
//
// Implementation of case-insensitive parmeterized Map from CString to value
//
//-----------------------------------------------------------------------------

#include "hu_pch.h"
#include "mfcincl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "strelem.h"  // used for special creation

#ifdef UNICODE
PWSTR WINAPI FilenameToLowerCaseInPlace(PWSTR pBuffer);
#define STRING_LOWERCASE_NOLOCALE       FilenameToLowerCaseInPlace
#else
#define STRING_LOWERCASE_NOLOCALE       _tcslwr
#endif

#ifdef _DEBUG
#define ASSERT_KEY_LOWERCASE(key)                                   \
{                                                                   \
    TCHAR* pStg = (TCHAR*) _alloca((_tcslen(key) + 1) * sizeof(TCHAR));      \
    _tcscpy(pStg, key);                                             \
    STRING_LOWERCASE_NOLOCALE(pStg);                                                  \
    ASSERT(_tcscmp(pStg, key) == 0);                                \
}
#else
#define ASSERT_KEY_LOWERCASE(key) { }
#endif // _DEBUG

/////////////////////////////////////////////////////////////////////////////

CVxMapStringToPtrNoCase::CVxMapStringToPtrNoCase(int nBlockSize)
{
    ASSERT(nBlockSize > 0);

    m_pHashTable = NULL;
    m_nHashTableSize = 17;  // default size
    m_nCount = 0;
    m_pFreeList = NULL;
    m_pBlocks = NULL;
    m_nBlockSize = nBlockSize;
}

inline UINT CVxMapStringToPtrNoCase::HashKey(LPCTSTR key) const
{
    ASSERT_KEY_LOWERCASE(key)

    UINT nHash = 0;
    while (*key)
        nHash = (nHash<<5) + nHash + *key++;
    return nHash;
}

void CVxMapStringToPtrNoCase::InitHashTable(UINT nHashSize, BOOL bAllocNow)
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

void CVxMapStringToPtrNoCase::RemoveAll()
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

CVxMapStringToPtrNoCase::~CVxMapStringToPtrNoCase()
{
    RemoveAll();
    ASSERT(m_nCount == 0);
}

/////////////////////////////////////////////////////////////////////////////
// Assoc helpers
// same as CList implementation except we store CAssoc's not CNode's
//    and CAssoc's are singly linked all the time

CVxMapStringToPtrNoCase::CAssoc* CVxMapStringToPtrNoCase::NewAssoc()
{
    if (m_pFreeList == NULL)
    {
        // add another block
        CVxPlex* newBlock = CVxPlex::Create(m_pBlocks, m_nBlockSize,
                            sizeof(CVxMapStringToPtrNoCase::CAssoc));
        // chain them into free list
        CVxMapStringToPtrNoCase::CAssoc* pAssoc =
                (CVxMapStringToPtrNoCase::CAssoc*) newBlock->data();
        // free in reverse order to make it easier to debug
        pAssoc += m_nBlockSize - 1;
        for (int i = m_nBlockSize-1; i >= 0; i--, pAssoc--)
        {
            pAssoc->pNext = m_pFreeList;
            m_pFreeList = pAssoc;
        }
    }
    ASSERT(m_pFreeList != NULL);  // we must have something

    CVxMapStringToPtrNoCase::CAssoc* pAssoc = m_pFreeList;
    m_pFreeList = m_pFreeList->pNext;
    m_nCount++;
    ASSERT(m_nCount > 0);  // make sure we don't overflow
    ConstructElements(&pAssoc->key, 1);
//  memcpy(&pAssoc->key, &_cstrPchNil, sizeof(CString));



    pAssoc->value = 0;

    return pAssoc;
}

void CVxMapStringToPtrNoCase::FreeAssoc(CVxMapStringToPtrNoCase::CAssoc* pAssoc)
{
    DestructElement(&pAssoc->key);  // free up string data

    pAssoc->pNext = m_pFreeList;
    m_pFreeList = pAssoc;
    m_nCount--;
    ASSERT(m_nCount >= 0);  // make sure we don't underflow

    // if no more elements, cleanup completely
    if (m_nCount == 0)
        RemoveAll();
}

CVxMapStringToPtrNoCase::CAssoc* CVxMapStringToPtrNoCase::GetAssocAt(LPCTSTR key, UINT& nHash) const
// find association (or return NULL)
{
    ASSERT_KEY_LOWERCASE(key);

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
BOOL CVxMapStringToPtrNoCase::Lookup(LPCTSTR key, void*& rValue) const
{
    ASSERT_VALID(this);
    ASSERT(key);
    if(!key)
        return FALSE;
    
    // Lowercase the key
    size_t size = _tcslen(key) * sizeof(TCHAR) + sizeof(TCHAR);
    TCHAR* pszlckey = (TCHAR*) _alloca(size);
    memcpy(pszlckey, key, size);
    STRING_LOWERCASE_NOLOCALE(pszlckey);
    
    UINT nHash;
    CAssoc* pAssoc = GetAssocAt(pszlckey, nHash);  
    if (pAssoc == NULL)
        return FALSE;  // not in map

    rValue = pAssoc->value;
    return TRUE;
}

BOOL CVxMapStringToPtrNoCase::LookupKey(LPCTSTR key, LPCTSTR& rKey) const
{
    ASSERT_VALID(this);
    ASSERT(key);
    if(!key)
        return FALSE;
    
    // Lowercase the key
    size_t size = _tcslen(key) * sizeof(TCHAR) + sizeof(TCHAR); 
    TCHAR* pszlckey = (TCHAR*) _alloca(size);
    memcpy(pszlckey, key, size);
    STRING_LOWERCASE_NOLOCALE(pszlckey);

    UINT nHash;
    CAssoc* pAssoc = GetAssocAt(pszlckey, nHash);
    if (pAssoc == NULL)
        return FALSE;  // not in map

    rKey = pAssoc->key;
    return TRUE;
}

void*& CVxMapStringToPtrNoCase::operator[](LPCTSTR key)
{
    ASSERT_VALID(this);
    ASSERT(key);
    
    // Lowercase the key
    size_t size = _tcslen(key) * sizeof(TCHAR) + sizeof(TCHAR);
    TCHAR* pszlckey = (TCHAR*) _alloca(size);
    memcpy(pszlckey, key, size);
    STRING_LOWERCASE_NOLOCALE(pszlckey);

    UINT nHash;
    CAssoc* pAssoc;
    if ((pAssoc = GetAssocAt(pszlckey, nHash)) == NULL)
    {
        if (m_pHashTable == NULL)
            InitHashTable(m_nHashTableSize);

        ASSERT(m_pHashTable);
        // it doesn't exist, add a new Association
        pAssoc = NewAssoc();
        pAssoc->nHashValue = nHash;
        pAssoc->key = pszlckey;
        // 'pAssoc->value' is a constructed object, nothing more

        // put into hash table
        pAssoc->pNext = m_pHashTable[nHash];
        m_pHashTable[nHash] = pAssoc;
    }
    return pAssoc->value;  // return new reference
}

// Same as SetAt except it will fail if there is already an value set for this
// key. It is more performant than code which does a lookup first followed by
// an add since we only have to lowercase the key once. Returns FALSE on 
// failure, TRUE otherwise
BOOL CVxMapStringToPtrNoCase::SetAtFailIfExists(LPCTSTR key, void* newValue)
{
    ASSERT_VALID(this);
    ASSERT(key);
    BOOL bRet = FALSE;
    // Lowercase the key
    size_t size = _tcslen(key) * sizeof(TCHAR) + sizeof(TCHAR);
    TCHAR* pszlckey = (TCHAR*) _alloca(size);
    memcpy(pszlckey, key, size);
    STRING_LOWERCASE_NOLOCALE(pszlckey);

    UINT nHash;
    CAssoc* pAssoc;
    if ((pAssoc = GetAssocAt(pszlckey, nHash)) == NULL)
    {
        if (m_pHashTable == NULL)
            InitHashTable(m_nHashTableSize);

        ASSERT(m_pHashTable);
        // it doesn't exist, add a new Association
        pAssoc = NewAssoc();
        pAssoc->nHashValue = nHash;
        pAssoc->key = pszlckey;
        pAssoc->value = newValue;

        // put into hash table
        pAssoc->pNext = m_pHashTable[nHash];
        m_pHashTable[nHash] = pAssoc;
        bRet = TRUE;
    }
    return bRet;
}


BOOL CVxMapStringToPtrNoCase::RemoveKey(LPCTSTR key)
// remove key - return TRUE if removed
{
    ASSERT_VALID(this);
    ASSERT(key);
    if(!key)
        return FALSE;

    if (m_pHashTable == NULL)
        return FALSE;  // nothing in the table
    
    // Lowercase the key
    size_t size = _tcslen(key) * sizeof(TCHAR) + sizeof(TCHAR);
    TCHAR* pszlckey = (TCHAR*) _alloca(size);
    memcpy(pszlckey, key, size);
    STRING_LOWERCASE_NOLOCALE(pszlckey);

    CAssoc** ppAssocPrev;
    ppAssocPrev = &m_pHashTable[HashKey(pszlckey) % m_nHashTableSize];

    CAssoc* pAssoc;
    for (pAssoc = *ppAssocPrev; pAssoc != NULL; pAssoc = pAssoc->pNext)
    {
        if (pAssoc->key == pszlckey)
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

void CVxMapStringToPtrNoCase::GetNextAssoc(POSITION& rNextPosition,
    CString& rKey, void*& rValue) const
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
    if(!pAssocRet)
        return;
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
void CVxMapStringToPtrNoCase::AssertValid() const
{
    ASSERT(m_nHashTableSize > 0);
    ASSERT(m_nCount == 0 || m_pHashTable != NULL);
        // non-empty map should have hash table
}
#endif //_DEBUG

