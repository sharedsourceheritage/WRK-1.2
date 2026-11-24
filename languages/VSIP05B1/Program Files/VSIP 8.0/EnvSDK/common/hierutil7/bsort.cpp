//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// bsort.cpp
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

#include "hu_pch.h"

#include "bsort.h"


/*****************************************************************************
 *
 *  Constructor
 */
BSORT_LIST::BSORT_LIST() 
: m_ListSize(0),
  m_AllocSize(0),
  m_bInit(FALSE),
  m_List(NULL)
{
} // BSORT_LIST::BSORT_LIST


/*****************************************************************************
 *
 *  Destructor - free alloc'd memory
 */
BSORT_LIST::~BSORT_LIST() 
{
    // Only destroy if we have a valid object
    if ( !IsValid() )
        return;

    // zap our IsValid flag
    m_bInit = FALSE;

    // Now free the list itself
    if (m_List) 
       VSFree(m_List);

    return;
} // BSORT_LIST::~BSORT_LIST


/*****************************************************************************
 *
 *  Init the list
 */
VOID BSORT_LIST::Init( int (__cdecl *fCompare) (const void *arg1, const void *arg2) ) 
{
    ULONG i;

    m_ListSize = 0;
    m_AllocSize = 0;

    // If we have any old data - destroy it
    if ( m_List ) {
        // Walk the list and free all elements
        for (i = 0; i < m_ListSize; i++)
            NodeFree( m_List[i] );

        // Now free the list itself
        if (m_List) 
            VSFree(m_List);
    }

    m_List = NULL;

    if (fCompare != NULL)
        m_Compare = fCompare;

    if (m_Compare != NULL)
        m_bInit = TRUE;

    return;
} // BSORT_LIST::Init


/*****************************************************************************
 *
 *  Add an item to the list
 */
DWORD BSORT_LIST::Add( PVOID pData, BOOL DoSort ) 
{
    PVOID pRec;

    if ( !IsValid() )
        return ERROR_INVALID_PARAMETER;

    if (pData == NULL) {
        ASSERT(FALSE);
        return ERROR_INVALID_PARAMETER;
    }

    //
    // No record - so create a new one
    //
    if (m_ListSize >= m_AllocSize) {
        m_AllocSize += 10;
        if (m_List == NULL) {
            m_List = ( PVOID * ) VSAlloc( sizeof(PVOID) * m_AllocSize );
        } else {
            m_List = ( PVOID * ) VSRealloc(m_List, sizeof(PVOID) * m_AllocSize );
        }
    }

    //
    // Make sure we could allocate the list
    //
    if ( m_List == NULL ) {
        ASSERT( FALSE );
        m_List = NULL;
        m_ListSize = m_AllocSize = 0;
        return ERROR_NOT_ENOUGH_MEMORY;
    }

    pRec = NodeNew( pData );
    if ( pRec == NULL ) {
        ASSERT( FALSE );
        return ERROR_NOT_ENOUGH_MEMORY;
    }

    m_List[m_ListSize] = pRec;

    m_ListSize++;

    // Have added the entry - now need to sort it in ascending order
    if ( DoSort )
        qsort((void *) m_List, (size_t) m_ListSize, sizeof(PVOID), m_Compare);

    return ERROR_SUCCESS;
} // BSORT_LIST::Add

/*****************************************************************************
 *
 *  Remove an item from the list
 */
DWORD BSORT_LIST::Remove( ULONG iItem ) 
{
    if ( !IsValid() )
        return ERROR_INVALID_PARAMETER;

    if (iItem >= m_ListSize) {
        ASSERT(FALSE);  // we don't have that many items...
        return ERROR_INVALID_PARAMETER;
    }

    NodeFree(m_List[iItem]);

    // loop across all values including & after the iItem'th element,
    //  and push everything back one space
    //
    for (ULONG iElem=iItem; iElem<m_ListSize-1; iElem++)
    {
        m_List[iElem] = m_List[iElem+1];
    }

    // just to be safe, set what used to be our last element to NULL
    m_List[m_ListSize-1] = NULL;

    // now reduce the list size by one element
    m_ListSize--;

    // since we are already a sorted list, we do not need to resort...

    return ERROR_SUCCESS;
} // BSORT_LIST::Add


/*****************************************************************************
 *
 *  Find an item in the list
 */
PVOID BSORT_LIST::Find( PVOID item, PULONG pIndex ) 
{
    LONG begin = 0;
    LONG end = (LONG) m_ListSize - 1;
    LONG cur = 0;
    int match;
    PVOID pRec;

    if ( !IsValid() )
        return NULL;

    if (pIndex != NULL)
        *pIndex = ERROR_LIST_MATCH;

    if ((m_ListSize == 0) || (item == NULL))
        return NULL;

    while (end >= begin) {
        // go halfway in-between
        cur = (begin + end) / 2;
        pRec = m_List[cur];

        // compare the two result into match
        match = Match(item, pRec);

        if (match < 0)
            // move new begin
            end = cur - 1;
        else
            begin = cur + 1;

        if (match == 0) {
            if (pIndex != NULL)
                *pIndex = cur;

            return (PVOID) pRec;
        }
    }

    if (pIndex != NULL) {
        // If end has moved then we have found something bigger then our
        // item, otherwise there isn't anything big enough
        if (end != (LONG) m_ListSize - 1)
            *pIndex = cur;
    }

    return NULL;
} // BSORT_LIST::Find


/*****************************************************************************
 *
 *  Resort the list using quicksort
 */
VOID BSORT_LIST::Sort(VOID) 
{
    if ( !IsValid() )
        return;

    // Have added the entry - now need to sort it in ascending order
    qsort((void *) m_List, (size_t) m_ListSize, sizeof(PVOID), m_Compare);
} // BSORT_LIST::Sort


