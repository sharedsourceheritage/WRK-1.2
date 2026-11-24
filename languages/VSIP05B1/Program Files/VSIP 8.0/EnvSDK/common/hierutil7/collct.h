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
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __COLLCT_H__
#define __COLLCT_H__

struct CVxPlex     // warning variable length structure
{
    CVxPlex* pNext;
    DWORD dwReserved[1];    // align on 8 byte boundary
    // BYTE data[maxNum*elementSize];

    void* data() { return this+1; }

    static CVxPlex* PASCAL Create(CVxPlex*& head, UINT nMax, UINT cbElement);
            // like 'calloc' but no zero fill
            // may throw memory exceptions

    void FreeDataChain();       // free this one and links
};

/////////////////////////////////////////////////////////////////////////////
// Classes declared in this file

    // Arrays
    class CVxPtrArray;              // array of void*
    class CVxPtrList;               // List of void*
    class CVxMapPtrToPtr;           // map from void* to void*
    class CVxStringArray;           // array of CStrings
    class CVxMapStringToPtr;        // map from CString to void*
    class CVxMapStringToString;     // map from CString to void*
    class CVxMapStringToPtrNoCase;  // case-insensitive map from CString to void*

/////////////////////////////////////////////////////////////////////////////
class CVxPtrArray
{
public:

// Construction
    CVxPtrArray();

// Attributes
    int GetSize() const;
    int GetUpperBound() const;
    void SetSize(int nNewSize, int nGrowBy = -1);

// Operations
    // Clean up
    void FreeExtra();
    void RemoveAll();

    // Accessing elements
    void* GetAt(int nIndex) const;
    void SetAt(int nIndex, void* newElement);
    void*& ElementAt(int nIndex);

    // Direct Access to the element data (may return NULL)
    const void** GetData() const;
    void** GetData();

    // Potentially growing the array
    void SetAtGrow(int nIndex, void* newElement);
    int Add(void* newElement);
    int Append(const CVxPtrArray& src);
    void Copy(const CVxPtrArray& src);

    // overloaded operator helpers
    void* operator[](int nIndex) const;
    void*& operator[](int nIndex);

    // Operations that move elements around
    void InsertAt(int nIndex, void* newElement, int nCount = 1);
    void RemoveAt(int nIndex, int nCount = 1);
    void InsertAt(int nStartIndex, CVxPtrArray* pNewArray);

// Implementation
protected:
    void** m_pData;   // the actual array of data
    int m_nSize;     // # of elements (upperBound - 1)
    int m_nMaxSize;  // max allocated
    int m_nGrowBy;   // grow amount

public:
    ~CVxPtrArray();
#ifdef _DEBUG
    void AssertValid() const;
#endif //!_DEBUG

protected:
    // local typedefs for class templates
    typedef void* BASE_TYPE;
    typedef void* BASE_ARG_TYPE;
};

////////////////////////////////////////////////////////////////////////////
class CVxPtrList
{

protected:
    struct CNode
    {
        CNode* pNext;
        CNode* pPrev;
        void* data;
    };
public:

// Construction
    CVxPtrList(int nBlockSize = 10);

// Attributes (head and tail)
    // count of elements
    int GetCount() const;
    BOOL IsEmpty() const;

    // peek at head or tail
    void*& GetHead();
    void* GetHead() const;
    void*& GetTail();
    void* GetTail() const;

// Operations
    // get head or tail (and remove it) - don't call on empty list!
    void* RemoveHead();
    void* RemoveTail();

    // add before head or after tail
    POSITION AddHead(void* newElement);
    POSITION AddTail(void* newElement);

    // add another list of elements before head or after tail
    void AddHead(CVxPtrList* pNewList);
    void AddTail(CVxPtrList* pNewList);

    // remove all elements
    void RemoveAll();

    // iteration
    POSITION GetHeadPosition() const;
    POSITION GetTailPosition() const;
    void*& GetNext(POSITION& rPosition); // return *Position++
    void* GetNext(POSITION& rPosition) const; // return *Position++
    void*& GetPrev(POSITION& rPosition); // return *Position--
    void* GetPrev(POSITION& rPosition) const; // return *Position--

    // getting/modifying an element at a given position
    void*& GetAt(POSITION position);
    void* GetAt(POSITION position) const;
    void SetAt(POSITION pos, void* newElement);
    void RemoveAt(POSITION position);

    // inserting before or after a given position
    POSITION InsertBefore(POSITION position, void* newElement);
    POSITION InsertAfter(POSITION position, void* newElement);

    // helper functions (note: O(n) speed)
    POSITION Find(void* searchValue, POSITION startAfter = NULL) const;
                        // defaults to starting at the HEAD
                        // return NULL if not found
    POSITION FindIndex(int nIndex) const;
                        // get the 'nIndex'th element (may return NULL)

// Implementation
protected:
    CNode* m_pNodeHead;
    CNode* m_pNodeTail;
    int m_nCount;
    CNode* m_pNodeFree;
    struct CVxPlex* m_pBlocks;
    int m_nBlockSize;

    CNode* NewNode(CNode*, CNode*);
    void FreeNode(CNode*);

public:
    ~CVxPtrList();
#ifdef _DEBUG
    void AssertValid() const;
#endif
    // local typedefs for class templates
    typedef void* BASE_TYPE;
    typedef void* BASE_ARG_TYPE;
};


////////////////////////////////////////////////////////////////////////////
class CVxStringArray
{
public:
// Construction
    CVxStringArray();

// Attributes
    int GetSize() const;
    int GetUpperBound() const;
    void SetSize(int nNewSize, int nGrowBy = -1);

// Operations
    // Clean up
    void FreeExtra();
    void RemoveAll();

    // Accessing elements
    CString GetAt(int nIndex) const;
    void SetAt(int nIndex, LPCTSTR newElement);
    CString& ElementAt(int nIndex);

    // Direct Access to the element data (may return NULL)
    const CString* GetData() const;
    CString* GetData();

    // Potentially growing the array
    void SetAtGrow(int nIndex, LPCTSTR newElement);
    int Add(LPCTSTR newElement);
    int Append(const CVxStringArray& src);
    void Copy(const CVxStringArray& src);

    // overloaded operator helpers
    CString operator[](int nIndex) const;
    CString& operator[](int nIndex);

    // Operations that move elements around
    void InsertAt(int nIndex, LPCTSTR newElement, int nCount = 1);
    void RemoveAt(int nIndex, int nCount = 1);
    void InsertAt(int nStartIndex, CVxStringArray* pNewArray);

// Implementation
protected:
    CString* m_pData;   // the actual array of data
    int m_nSize;     // # of elements (upperBound - 1)
    int m_nMaxSize;  // max allocated
    int m_nGrowBy;   // grow amount

public:
    ~CVxStringArray();

#ifdef _DEBUG
    void AssertValid() const;
#endif //!_DEBUG

protected:
    // local typedefs for class templates
    typedef CString BASE_TYPE;
    typedef LPCTSTR BASE_ARG_TYPE;
};

/////////////////////////////////////////////////////////////////////////////
class CVxMapPtrToPtr
{

protected:
    // Association
    struct CAssoc
    {
        CAssoc* pNext;
        void* key;
        void* value;
    };

public:

// Construction
    CVxMapPtrToPtr(int nBlockSize = 10);

// Attributes
    // number of elements
    int GetCount() const;
    BOOL IsEmpty() const;

    // Lookup
    BOOL Lookup(void* key, void*& rValue) const;

// Operations
    // Lookup and add if not there
    void*& operator[](void* key);

    // add a new (key, value) pair
    void SetAt(void* key, void* newValue);

    // removing existing (key, ?) pair
    BOOL RemoveKey(void* key);
    void RemoveAll();

    // iterating all (key, value) pairs
    POSITION GetStartPosition() const;
    void GetNextAssoc(POSITION& rNextPosition, void*& rKey, void*& rValue) const;

    // advanced features for derived classes
    UINT GetHashTableSize() const;
    void InitHashTable(UINT hashSize, BOOL bAllocNow = TRUE);

// Overridables: special non-virtual (see map implementation for details)
    // Routine used to user-provided hash keys
    UINT HashKey(void* key) const;

// Implementation
protected:
    CAssoc** m_pHashTable;
    UINT m_nHashTableSize;
    int m_nCount;
    CAssoc* m_pFreeList;
    struct CVxPlex* m_pBlocks;
    int m_nBlockSize;

    CAssoc* NewAssoc();
    void FreeAssoc(CAssoc*);
    CAssoc* GetAssocAt(void*, UINT&) const;

public:
    ~CVxMapPtrToPtr();
#ifdef _DEBUG
    void AssertValid() const;
#endif //!_DEBUG


    void* GetValueAt(void* key) const;


protected:
    // local typedefs for CVxTypedPtrMap class template
    typedef void* BASE_KEY;
    typedef void* BASE_ARG_KEY;
    typedef void* BASE_VALUE;
    typedef void* BASE_ARG_VALUE;
};

/////////////////////////////////////////////////////////////////////////////
class CVxMapStringToPtr
{
protected:
    // Association
    struct CAssoc
    {
        CAssoc* pNext;
        UINT nHashValue;  // needed for efficient iteration
        CString key;
        void* value;
    };

public:
// Construction
    CVxMapStringToPtr(int nBlockSize = 10);
    
// Attributes
    // number of elements
    int GetCount() const;
    BOOL IsEmpty() const;

    // Lookup
    BOOL Lookup(LPCTSTR key, void*& rValue) const;
    BOOL LookupKey(LPCTSTR key, LPCTSTR& rKey) const;

// Operations
    // Lookup and add if not there
    void*& operator[](LPCTSTR key);

    // add a new (key, value) pair
    void SetAt(LPCTSTR key, void* newValue);

    // removing existing (key, ?) pair
    BOOL RemoveKey(LPCTSTR key);
    void RemoveAll();

    // iterating all (key, value) pairs
    POSITION GetStartPosition() const;
    void GetNextAssoc(POSITION& rNextPosition, CString& rKey, void*& rValue) const;

    // advanced features for derived classes
    UINT GetHashTableSize() const;
    void InitHashTable(UINT hashSize, BOOL bAllocNow = TRUE);

// Overridables: special non-virtual (see map implementation for details)
    // Routine used to user-provided hash keys
    UINT HashKey(LPCTSTR key) const;

// Implementation
protected:
    CAssoc** m_pHashTable;
    UINT m_nHashTableSize;
    int m_nCount;
    CAssoc* m_pFreeList;
    struct CVxPlex* m_pBlocks;
    int m_nBlockSize;

    CAssoc* NewAssoc();
    void FreeAssoc(CAssoc*);
    CAssoc* GetAssocAt(LPCTSTR, UINT&) const;

public:
    ~CVxMapStringToPtr();
#ifdef _DEBUG
    void AssertValid() const;
#endif //!_DEBUG


protected:
    // local typedefs for CVxTypedPtrMap class template
    typedef CString BASE_KEY;
    typedef LPCTSTR BASE_ARG_KEY;
    typedef void* BASE_VALUE;
    typedef void* BASE_ARG_VALUE;
};


/////////////////////////////////////////////////////////////////////////////
class CVxMapStringToString
{

protected:
    // Association
    struct CAssoc
    {
        CAssoc* pNext;
        UINT nHashValue;  // needed for efficient iteration
        CString key;
        CString value;
    };

public:

// Construction
    CVxMapStringToString(int nBlockSize = 10);

// Attributes
    // number of elements
    int GetCount() const;
    BOOL IsEmpty() const;

    // Lookup
    BOOL Lookup(LPCTSTR key, CString& rValue) const;
    BOOL LookupKey(LPCTSTR key, LPCTSTR& rKey) const;

// Operations
    // Lookup and add if not there
    CString& operator[](LPCTSTR key);

    // add a new (key, value) pair
    void SetAt(LPCTSTR key, LPCTSTR newValue);

    // removing existing (key, ?) pair
    BOOL RemoveKey(LPCTSTR key);
    void RemoveAll();

    // iterating all (key, value) pairs
    POSITION GetStartPosition() const;
    void GetNextAssoc(POSITION& rNextPosition, CString& rKey, CString& rValue) const;

    // advanced features for derived classes
    UINT GetHashTableSize() const;
    void InitHashTable(UINT hashSize, BOOL bAllocNow = TRUE);

// Overridables: special non-virtual (see map implementation for details)
    // Routine used to user-provided hash keys
    UINT HashKey(LPCTSTR key) const;

// Implementation
protected:
    CAssoc** m_pHashTable;
    UINT m_nHashTableSize;
    int m_nCount;
    CAssoc* m_pFreeList;
    struct CVxPlex* m_pBlocks;
    int m_nBlockSize;

    CAssoc* NewAssoc();
    void FreeAssoc(CAssoc*);
    CAssoc* GetAssocAt(LPCTSTR, UINT&) const;

public:
    ~CVxMapStringToString();

#ifdef _DEBUG
    void AssertValid() const;
#endif //!_DEBUG


protected:
    // local typedefs for CVxTypedPtrMap class template
    typedef CString BASE_KEY;
    typedef LPCTSTR BASE_ARG_KEY;
    typedef CString BASE_VALUE;
    typedef LPCTSTR BASE_ARG_VALUE;
};

/////////////////////////////////////////////////////////////////////////////
class CVxMapStringToPtrNoCase 
{
protected:
    // Association
    struct CAssoc
    {
        CAssoc* pNext;
        UINT nHashValue;  // needed for efficient iteration
        CString key;
        void* value;
    };

public:
// Construction
    CVxMapStringToPtrNoCase(int nBlockSize = 10);
    
// Attributes
    // number of elements
    int GetCount() const;
    BOOL IsEmpty() const;

    // Lookup
    BOOL Lookup(LPCTSTR key, void*& rValue) const;
    BOOL LookupKey(LPCTSTR key, LPCTSTR& rKey) const;

// Operations
    // Lookup and add if not there
    void*& operator[](LPCTSTR key);

    // add a new (key, value) pair
    void SetAt(LPCTSTR key, void* newValue);

    // Same as SetAt except it fails if the key already exists in map. More performant
    // than doing a lookup followed by an add
    BOOL SetAtFailIfExists(LPCTSTR key, void* newValue);

    // removing existing (key, ?) pair
    BOOL RemoveKey(LPCTSTR key);
    void RemoveAll();

    // iterating all (key, value) pairs
    POSITION GetStartPosition() const;
    void GetNextAssoc(POSITION& rNextPosition, CString& rKey, void*& rValue) const;

    // advanced features for derived classes
    UINT GetHashTableSize() const;
    void InitHashTable(UINT hashSize, BOOL bAllocNow = TRUE);

// Implementation
protected:
    CAssoc** m_pHashTable;
    UINT m_nHashTableSize;
    int m_nCount;
    CAssoc* m_pFreeList;
    struct CVxPlex* m_pBlocks;
    int m_nBlockSize;

    CAssoc* NewAssoc();
    void FreeAssoc(CAssoc*);
    CAssoc* GetAssocAt(LPCTSTR, UINT&) const;

    // Overridables: special non-virtual (see map implementation for details)
    // Routine used to user-provided hash keys
    UINT HashKey(LPCTSTR key) const;

public:
    ~CVxMapStringToPtrNoCase();
#ifdef _DEBUG
    void AssertValid() const;
#endif //!_DEBUG


protected:
    // local typedefs for CVxTypedPtrMap class template
    typedef CString BASE_KEY;
    typedef LPCTSTR BASE_ARG_KEY;
    typedef void* BASE_VALUE;
    typedef void* BASE_ARG_VALUE;
};


//=============================================================================
// Inlines
//=============================================================================
inline int CVxPtrArray::GetSize() const
    { return m_nSize; }
inline int CVxPtrArray::GetUpperBound() const
    { return m_nSize-1; }
inline void CVxPtrArray::RemoveAll()
    { SetSize(0); }
inline void* CVxPtrArray::GetAt(int nIndex) const
    { ASSERT(nIndex >= 0 && nIndex < m_nSize);
        return m_pData[nIndex]; }
inline void CVxPtrArray::SetAt(int nIndex, void* newElement)
    { ASSERT(nIndex >= 0 && nIndex < m_nSize);
        m_pData[nIndex] = newElement; }
inline void*& CVxPtrArray::ElementAt(int nIndex)
    { ASSERT(nIndex >= 0 && nIndex < m_nSize);
        return m_pData[nIndex]; }
inline const void** CVxPtrArray::GetData() const
    { return (const void**)m_pData; }
inline void** CVxPtrArray::GetData()
    { return (void**)m_pData; }
inline int CVxPtrArray::Add(void* newElement)
    { int nIndex = m_nSize;
        SetAtGrow(nIndex, newElement);
        return nIndex; }
inline void* CVxPtrArray::operator[](int nIndex) const
    { return GetAt(nIndex); }
inline void*& CVxPtrArray::operator[](int nIndex)
    { return ElementAt(nIndex); }


////////////////////////////////////////////////////////////////////////////
inline int CVxPtrList::GetCount() const
    { return m_nCount; }
inline BOOL CVxPtrList::IsEmpty() const
    { return m_nCount == 0; }
inline void*& CVxPtrList::GetHead()
    { ASSERT(m_pNodeHead != NULL);
        return m_pNodeHead->data; }
inline void* CVxPtrList::GetHead() const
    { ASSERT(m_pNodeHead != NULL);
        return m_pNodeHead->data; }
inline void*& CVxPtrList::GetTail()
    { ASSERT(m_pNodeTail != NULL);
        return m_pNodeTail->data; }
inline void* CVxPtrList::GetTail() const
    { ASSERT(m_pNodeTail != NULL);
        return m_pNodeTail->data; }
inline POSITION CVxPtrList::GetHeadPosition() const
    { return (POSITION) m_pNodeHead; }
inline POSITION CVxPtrList::GetTailPosition() const
    { return (POSITION) m_pNodeTail; }
inline void*& CVxPtrList::GetNext(POSITION& rPosition) // return *Position++
    { CNode* pNode = (CNode*) rPosition;
        ASSERT(VxIsValidAddress(pNode, sizeof(CNode)));
        rPosition = (POSITION) pNode->pNext;
        return pNode->data; }
inline void* CVxPtrList::GetNext(POSITION& rPosition) const // return *Position++
    { CNode* pNode = (CNode*) rPosition;
        ASSERT(VxIsValidAddress(pNode, sizeof(CNode)));
        rPosition = (POSITION) pNode->pNext;
        return pNode->data; }
inline void*& CVxPtrList::GetPrev(POSITION& rPosition) // return *Position--
    { CNode* pNode = (CNode*) rPosition;
        ASSERT(VxIsValidAddress(pNode, sizeof(CNode)));
        rPosition = (POSITION) pNode->pPrev;
        return pNode->data; }
inline void* CVxPtrList::GetPrev(POSITION& rPosition) const // return *Position--
    { CNode* pNode = (CNode*) rPosition;
        ASSERT(VxIsValidAddress(pNode, sizeof(CNode)));
        rPosition = (POSITION) pNode->pPrev;
        return pNode->data; }
inline void*& CVxPtrList::GetAt(POSITION position)
    { CNode* pNode = (CNode*) position;
        ASSERT(VxIsValidAddress(pNode, sizeof(CNode)));
        return pNode->data; }
inline void* CVxPtrList::GetAt(POSITION position) const
    { CNode* pNode = (CNode*) position;
        ASSERT(VxIsValidAddress(pNode, sizeof(CNode)));
        return pNode->data; }
inline void CVxPtrList::SetAt(POSITION pos, void* newElement)
    { CNode* pNode = (CNode*) pos;
        ASSERT(VxIsValidAddress(pNode, sizeof(CNode)));
        pNode->data = newElement; }

////////////////////////////////////////////////////////////////////////////
inline int CVxStringArray::GetSize() const
    { return m_nSize; }
inline int CVxStringArray::GetUpperBound() const
    { return m_nSize-1; }
inline void CVxStringArray::RemoveAll()
    { SetSize(0); }
inline CString CVxStringArray::GetAt(int nIndex) const
    { ASSERT(nIndex >= 0 && nIndex < m_nSize);
        return m_pData[nIndex]; }
inline void CVxStringArray::SetAt(int nIndex, LPCTSTR newElement)
    { ASSERT(nIndex >= 0 && nIndex < m_nSize);
        m_pData[nIndex] = newElement; }
inline CString& CVxStringArray::ElementAt(int nIndex)
    { ASSERT(nIndex >= 0 && nIndex < m_nSize);
        return m_pData[nIndex]; }
inline const CString* CVxStringArray::GetData() const
    { return (const CString*)m_pData; }
inline CString* CVxStringArray::GetData()
    { return (CString*)m_pData; }
inline int CVxStringArray::Add(LPCTSTR newElement)
    { int nIndex = m_nSize;
        SetAtGrow(nIndex, newElement);
        return nIndex; }
inline CString CVxStringArray::operator[](int nIndex) const
    { return GetAt(nIndex); }
inline CString& CVxStringArray::operator[](int nIndex)
    { return ElementAt(nIndex); }

////////////////////////////////////////////////////////////////////////////
inline int CVxMapPtrToPtr::GetCount() const
    { return m_nCount; }
inline BOOL CVxMapPtrToPtr::IsEmpty() const
    { return m_nCount == 0; }
inline void CVxMapPtrToPtr::SetAt(void* key, void* newValue)
    { (*this)[key] = newValue; }
inline POSITION CVxMapPtrToPtr::GetStartPosition() const
    { return (m_nCount == 0) ? NULL : BEFORE_START_POSITION; }
inline UINT CVxMapPtrToPtr::GetHashTableSize() const
    { return m_nHashTableSize; }


////////////////////////////////////////////////////////////////////////////
inline int CVxMapStringToPtr::GetCount() const
    { return m_nCount; }
inline BOOL CVxMapStringToPtr::IsEmpty() const
    { return m_nCount == 0; }
inline void CVxMapStringToPtr::SetAt(LPCTSTR key, void* newValue)
    { (*this)[key] = newValue; }
inline POSITION CVxMapStringToPtr::GetStartPosition() const
    { return (m_nCount == 0) ? NULL : BEFORE_START_POSITION; }
inline UINT CVxMapStringToPtr::GetHashTableSize() const
    { return m_nHashTableSize; }


////////////////////////////////////////////////////////////////////////////
inline int CVxMapStringToString::GetCount() const
    { return m_nCount; }
inline BOOL CVxMapStringToString::IsEmpty() const
    { return m_nCount == 0; }
inline void CVxMapStringToString::SetAt(LPCTSTR key, LPCTSTR newValue)
    { (*this)[key] = newValue; }
inline POSITION CVxMapStringToString::GetStartPosition() const
    { return (m_nCount == 0) ? NULL : BEFORE_START_POSITION; }
inline UINT CVxMapStringToString::GetHashTableSize() const
    { return m_nHashTableSize; }


////////////////////////////////////////////////////////////////////////////
inline int CVxMapStringToPtrNoCase::GetCount() const
    { return m_nCount; }
inline BOOL CVxMapStringToPtrNoCase::IsEmpty() const
    { return m_nCount == 0; }
inline void CVxMapStringToPtrNoCase::SetAt(LPCTSTR key, void* newValue)
    { (*this)[key] = newValue; }
inline POSITION CVxMapStringToPtrNoCase::GetStartPosition() const
    { return (m_nCount == 0) ? NULL : BEFORE_START_POSITION; }
inline UINT CVxMapStringToPtrNoCase::GetHashTableSize() const
    { return m_nHashTableSize; }


#endif //!__COLLCT_H__
