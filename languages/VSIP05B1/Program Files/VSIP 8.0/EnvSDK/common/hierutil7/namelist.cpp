//--------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (c) 1994-2000 Microsoft Corporation Inc.
// All rights reserved
//
//---------------------------------------------------------------------------
#include "hu_pch.h"

#include "bsort.h"
#include "namelist.h"

#define COMPARE_FILENAMES   _tcsicmp
#define COMPARE_NOCASE      _tcsicmp

//---------------------------------------------------------------------------
// Constructor
//---------------------------------------------------------------------------
CNameList::CNameList() 
{
    return;
}


//---------------------------------------------------------------------------
// Destructor - free alloc'd memory
//---------------------------------------------------------------------------
CNameList::~CNameList( VOID ) 
{
    ULONG i;

    // Walk the list and free all elements
    for (i = 0; i < m_ListSize; i++)
        NodeFree( m_List[i] );

}

//------------------------------------------------------------------------
// Find a match - comparing strings
//---------------------------------------------------------------------------
int CNameList::Match( PVOID arg1, PVOID arg2 ) 
{
    return COMPARE_FILENAMES(*(CString*) arg1, *(CString*) arg2);    
}


//------------------------------------------------------------------------
// Create new node for data
//---------------------------------------------------------------------------
PVOID CNameList::NodeNew( PVOID Data ) 
{
    CString *str;
    str = new CString( (LPTSTR) Data );
    return (PVOID) str;
}


//------------------------------------------------------------------------
// Free the node
//---------------------------------------------------------------------------
VOID CNameList::NodeFree ( PVOID Data ) 
{
    CString *str = (CString *) Data;
    delete str;
}

//------------------------------------------------------------------------
// Adds only the members from pstrListToAdd that are not already present in
// pstrList. To add all members, use UtilAppendList().
// returns TRUE if any file got added.
//------------------------------------------------------------------------
BOOL CNameList::AddList(CNameList *pstrListToAdd)
{
    ULONG cFilesToAdd = pstrListToAdd->Size();
    ULONG cFiles = Size();
    ULONG   iFileToAdd = 0, iFile = 0;
    BOOL  fRet = FALSE;

    // do a quick return if there are no files to add.
    if (cFilesToAdd == 0)
        return FALSE;
        
    // sort the new list.
    Sort();

    // sort the old list.
    pstrListToAdd->Sort();
    
    CString **ppListToAdd = (CString **)pstrListToAdd->GetArray();
    CString **ppList = (CString **)GetArray();

    while (iFileToAdd < cFilesToAdd)
    {
        int c = 1; // initialize c to be greater than 0.

        if (iFile < cFiles)
            c = (*ppList[iFile]).Compare(*ppListToAdd[iFileToAdd]);

        if (c < 0)
        { // old file is earlier in the sort order - proceed to next file in the old list.
            iFile++;
        }
        else if (c == 0)
        { // file is already present in the old list - proceed to next file in both lists.
            iFile++;
            iFileToAdd++;
        }
        else
        { // new file is earlier in the sort order - add it to the end of the old files list.
            Add((void *)(LPCTSTR)(*ppListToAdd[iFileToAdd++]));
            // !!ppList may have moved after the Add() - need to refetch!!
            ppList = (CString **)GetArray();
            fRet = TRUE;
        }
    }
    return fRet;
}


//------------------------------------------------------------------------
// append name list from one to another.
//------------------------------------------------------------------------
void CNameList::AppendList(CNameList *pstrListSrc)
{
    ULONG cFiles = pstrListSrc->Size();
    CString **ppList = (CString **)pstrListSrc->GetArray();
    for (ULONG iFile = 0; iFile < cFiles; iFile++)
        Add((void *)(LPCTSTR)(*ppList[iFile]));
}


//------------------------------------------------------------------------
// Compare lists - return 0 if identical and non-zero if not.
//------------------------------------------------------------------------
BOOL CNameList::CompareList(CNameList *pList2)
{
    ULONG cFiles = Size();

    // return quickly if # of files is not the same.
    if (cFiles != pList2->Size())
        return 1;

    CString **ppList1 = (CString **)GetArray();
    CString **ppList2 = (CString **)pList2->GetArray();

    for (ULONG iFile = 0; iFile < cFiles; iFile++)
        if (COMPARE_FILENAMES(*ppList1[iFile], *ppList2[iFile]) != 0)
            return 1;
    return 0;
}



//---------------------------------------------------------------------------
// Compare two strings
//---------------------------------------------------------------------------
int __cdecl _CStringsCompare(const void *arg1, const void *arg2) {
   CString *node1, *node2;

   node1 = (*((CString **) arg1));
   node2 = (*((CString **) arg2));

   return COMPARE_NOCASE(*node1, *node2); 

}

//---------------------------------------------------------------------------
// constructor
//---------------------------------------------------------------------------
CPropValueList::CPropValueList()    
{
    // these lists are never sorted but they
    // have to be initialized for anything to work.
    m_PropertyList.Init(_CStringsCompare);
    m_ValueList.Init(_CStringsCompare);
}

//---------------------------------------------------------------------------
// find the index of the property with name=strProperty and read its value 
// from the corresponding valuelist, into strValue.
// THIS IS VERY SLOW - does a linear search.
//---------------------------------------------------------------------------
BOOL CPropValueList::Find(CString &strProperty, CString &strValue)
{
    ULONG   uIndex, uMac;
    CString **ppList = (CString **)m_PropertyList.GetArray();

    // NOTE: Cannot use binary search since this list is not sorted!!
    // and cannot sort it because the value list will not correspond.
    uMac = Size();
    for (uIndex = 0; uIndex < uMac; uIndex++)
    {
        if (COMPARE_NOCASE(strProperty, *ppList[uIndex]) == 0)
        {
            strValue = *(CString *)m_ValueList.Enum(uIndex);
            return TRUE;
        }
    }
    return FALSE;
}

//---------------------------------------------------------------------------
// Add property, value pair to the corresponding lists.
//---------------------------------------------------------------------------
DWORD CPropValueList::Add(PVOID strProperty, PVOID strValue)
{
    if (m_PropertyList.Add(strProperty) == ERROR_SUCCESS)
    {
        if (m_ValueList.Add(strValue) != ERROR_SUCCESS)
        {
            ASSERT(FALSE);
        }
    }
    return ERROR_SUCCESS;
}

//---------------------------------------------------------------------------
// return property and/or value given index
//---------------------------------------------------------------------------
BOOL  CPropValueList::Enum(ULONG i, void **ppProp, void **ppVal)
{
    ASSERT(i < Size());
    ASSERT(ppProp || ppVal);
    
    if (i >= Size())
        return FALSE;
    if (ppProp)
        *ppProp = m_PropertyList.Enum(i);
    if (ppVal)
        *ppVal  = m_ValueList.Enum(i);
    return TRUE;
}

//---------------------------------------------------------------------------
// return property and/or value list as cstring arrays
//---------------------------------------------------------------------------
void CPropValueList::GetArrays(void ***pppProp, void ***pppVal)
{
    ASSERT(pppProp || pppVal);
    if (pppProp)
        *pppProp = (void **)m_PropertyList.GetArray();
    if (pppVal)
        *pppVal  = (void **)m_ValueList.GetArray();
}

