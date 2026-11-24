//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// Util.h -- utility classes
//---------------------------------------------------------------------------
#pragma once

/////////////////////////////////////////////////////////////////////////////
// CPtrArrayImpl -- implementation class for CPtrArray

class CEnvSDKPtrArrayImpl
{
private:
    enum { ALLOC_INCR = 8 };

    const static size_t m_MaxArraySize = 0xFFFFFFFF / sizeof(void*);

    void**      m_ppData;
    size_t      m_iCount;
    size_t      m_iAlloc;

    // No implementation provided, so CPtrArrayImpl cannot be copied!
    CEnvSDKPtrArrayImpl(const CEnvSDKPtrArrayImpl&);
    CEnvSDKPtrArrayImpl& operator=(const CEnvSDKPtrArrayImpl&);

protected:
    void *  _GetAt      (size_t i);
    void    _SetAt      (size_t i, void* pData);
    BOOL    _Add        (void* pData);
    BOOL    _Remove     (void* pData);
    BOOL    _InsertAt   (size_t i, void* pObj);

    BOOL    _ReallocData (size_t iAlloc);

    void    _Sort    (                 int (__cdecl *compare )(const void *p1, const void *p2));
    int     _BSearch (const void *key, int (__cdecl *compare )(const void *p1, const void *p2));

    void    _Attach  (size_t cel, void** prgObj);
    void    _Detach  (void) { m_ppData = NULL; m_iCount = m_iAlloc = 0; }

public:
    CEnvSDKPtrArrayImpl(size_t iAlloc = 0);
    ~CEnvSDKPtrArrayImpl();

    BOOL    RemoveAt    (size_t i);
    void    RemoveAll   (void)     { m_iCount = 0; }
    void    SetTop      (size_t i) { m_iCount = i; }
    size_t  Count       (void)     { return m_iCount; }
};

inline CEnvSDKPtrArrayImpl::CEnvSDKPtrArrayImpl(size_t iAlloc) :
	m_ppData(NULL),
	m_iCount(0),
	m_iAlloc(0)
{
	_ReallocData(iAlloc);
}

/////////////////////////////////////////////////////////////////////////////
// CPtrArray -- simple array of pointers

template <class T>
class CEnvSDKPtrArray : public CEnvSDKPtrArrayImpl
{
public:
    CEnvSDKPtrArray (size_t iAlloc = 0) : CEnvSDKPtrArrayImpl(iAlloc) {}
    ~CEnvSDKPtrArray() { RemoveAll(); }

    T *     GetAt       (size_t i)                  { return (T*)_GetAt(i); }
    void    SetAt       (size_t i, T * pObj)        { _SetAt(i, pObj); }
    BOOL    Add         (T * pObj)                  { return _Add(pObj); }
    BOOL    Remove      (T * pObj)                  { return _Remove(pObj); }
    BOOL    InsertAt    (size_t i, T * pObj)        { return _InsertAt(i, pObj); }
                        
    void    Sort        (               int (__cdecl *compare)(T** p1, T** p2)) { _Sort((int (__cdecl *)(const void *, void const *))compare); }
    int     BSearch     (const T *pkey, int (__cdecl *compare)(T** p1, T** p2)) { return _BSearch((const void *)pkey, (int (__cdecl *)(const void *, void const *))compare); }
                        
    void    Attach      (size_t cel, T** prgObj)    { _Attach(cel, prgObj); }
    void    Detach      (void)                      { _Detach(); }
};

#define CArray CPtrArray	// for compatibility

