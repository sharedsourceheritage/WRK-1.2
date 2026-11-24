//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// bsort.H
//
//  Copyright (C) 1997 - 2000 Microsoft Corporation.  
//  All rights reserved.
//
// Description:
//
//  Classes for doing sorted lists.  Lists are sorted via quicksort and
//  searched using binary-search.
//
// Notes:
//
//  Lists are an array of pointers to data structures.  The constructor
//  is passed a comparison function used in sorting and searching.
//
//   Routines:
//      BSORT_LIST::BSORT_LIST
//      BSORT_LIST::~BSORT_LIST
//      BSORT_LIST::Size
//      BSORT_LIST::Add
//      BSORT_LIST::Delete
//      BSORT_LIST::Find
//
//---------------------------------------------------------------------------

#ifndef _BSORT_H_
#define _BSORT_H_

#include <stdlib.h>

#define ERROR_LIST_MATCH 0xFFFFFFFF


//------------------------------------------------------------------------------
// BSORT_LIST Class
//
// Routine Description:
//
//
// Arguments:
//
//
// Return Value:
//
//    None
//
// Notes:
//
//------------------------------------------------------------------------------
class BSORT_LIST {
protected:
    BOOL        m_bInit;
    ULONG       m_AllocSize;
    ULONG       m_ListSize;
    PVOID       *m_List;
    int  (__cdecl *m_Compare) (const void *arg1, const void *arg2);

    void    FreeData();

    virtual int     Match ( PVOID arg1, PVOID arg2 ) = 0;
    virtual PVOID   NodeNew  ( PVOID Data ) = 0;
    virtual VOID    NodeFree ( PVOID Data ) = 0;

public:
    BSORT_LIST();
    ~BSORT_LIST();

    // This object is valid if it was initialized
    BOOL  IsValid    ( VOID )    { return m_bInit; }

    ULONG Size       ( VOID )    { return m_ListSize; }

    PVOID Enum       ( ULONG i ) { return (i < m_ListSize) ? (PVOID) m_List[i] : NULL; }
    PVOID GetArray   ( VOID )    { return (PVOID) m_List; }

    VOID  Init       ( int (__cdecl *fCompare) (const void *arg1, const void *arg2) = NULL);
    DWORD Add        ( PVOID pData, BOOL DoSort = FALSE );
    DWORD Remove     ( ULONG iItem );
    PVOID Find       ( PVOID item, PULONG pIndex = NULL );
    VOID  Sort       ( VOID );

}; // Class BSORT_LIST

#endif
