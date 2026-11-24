//--------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (c) 1994-2000 Microsoft Corporation Inc.
// All rights reserved
//
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif
#ifndef _NAMELIST_H_
#define _NAMELIST_H_

#include <bsort.h>

class CNameList : public BSORT_LIST {
protected:

    virtual int     Match ( PVOID arg1, PVOID arg2 );
    virtual PVOID   NodeNew  ( PVOID Data );
    virtual VOID    NodeFree ( PVOID Data );

public:
    CNameList();
    ~CNameList();

    BOOL AddList(CNameList *pstrListToAdd);
    void AppendList(CNameList *pstrListSrc);
    BOOL CompareList(CNameList *pList2);

}; // Class CNameList

extern int __cdecl _CStringsCompare(const void *arg1, const void *arg2);

class CPropValueList
{
protected:
    CNameList   m_PropertyList;
    CNameList   m_ValueList;
    
public:
    CPropValueList();
    BOOL Find(CString &strProperty, CString &strValue);
    DWORD Add(PVOID strProperty, PVOID strValue);
    ULONG Size() { ASSERT(m_PropertyList.Size() == m_ValueList.Size()); return m_PropertyList.Size(); }
    BOOL  Enum(ULONG i, void **ppProp, void **ppVal);
    void GetArrays(void ***pppProp, void ***pppVal);
}; // Class CPropValueList

#endif
