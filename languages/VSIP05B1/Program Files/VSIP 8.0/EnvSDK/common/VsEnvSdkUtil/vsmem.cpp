
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
***************************************************************************/

//=----------------------------------------------------------------------=
// VsMem.Cpp
//=----------------------------------------------------------------------=
// Common memory allocation routines
//
#include "pch.h"
#include "vsmem.h"

//=----------------------------------------------------------------------=
// Debug allocation routines.  
//
// Here we overload the new and delete operators to point to the debug
// memory allocator in vsassert.dll
//

#if DEBUG

// We redefine this in vsmem.h.  However, we're going to have to undef
// it here if we are to actually overload it!
//
#undef new

PVOID  _cdecl operator new(size_t size) { return VSAlloc(size); }
#if _MSC_VER > 1200
PVOID  _cdecl operator new[](size_t size) { return VSAlloc(size); }
#endif // _MSC_VER
PVOID  _cdecl operator new(size_t size, LPSTR pszFile, UINT uLine) { return VsDebugAllocInternal(DEFAULT_HEAP, 0, size, pszFile, uLine, INSTANCE_GLOBAL, NULL); }
#if _MSC_VER > 1200
PVOID  _cdecl operator new[](size_t size, LPSTR pszFile, UINT uLine) { return VsDebugAllocInternal(DEFAULT_HEAP, 0, size, pszFile, uLine, INSTANCE_GLOBAL, NULL); }
#endif // _MSC_VER

void   _cdecl operator delete(PVOID pv) { if(pv) VSFree(pv); }
#if _MSC_VER > 1200
void   _cdecl operator delete[](PVOID pv) { if(pv) VSFree(pv); }
#endif // _MSC_VER

#else

PVOID  WINAPI VSRetAlloc (SIZE_T cb)             { return HeapAlloc(GetProcessHeap(), 0, cb); }
PVOID  WINAPI VSRetAllocZero (SIZE_T cb)         { return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, cb); }
PVOID  WINAPI VSRetRealloc (PVOID pv, SIZE_T cb) { return HeapReAlloc(GetProcessHeap(), 0, pv, cb); }
PVOID  WINAPI VSRetReallocZero (PVOID pv, SIZE_T cb) { return HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, pv, cb); }
BOOL   WINAPI VSRetFree (PVOID pv)              { return HeapFree(GetProcessHeap(), 0, pv); }
SIZE_T WINAPI VSRetSize (PVOID pv)              { return HeapSize(GetProcessHeap(), 0, pv); }

#endif // DEBUG
