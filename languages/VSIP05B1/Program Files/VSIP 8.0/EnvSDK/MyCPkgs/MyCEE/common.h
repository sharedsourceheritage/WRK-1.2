
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

/*---------------------------------------------------------
  Debugging
-----------------------------------------------------------*/
void  Trace( const char* format, ... );

#ifdef NDEBUG
# define ASSERT(x)
# define TRACE(s)       
# define TRACE1(s,x)     
# define TRACE2(s,x,y)   
# define TRACE3(s,x,y,z) 
#else
# define ASSERT(x)       assert(x)
# define TRACE(s)        Trace(s)
# define TRACE1(s,x)     Trace(s,x)
# define TRACE2(s,x,y)   Trace(s,x,y)
# define TRACE3(s,x,y,z) Trace(s,x,y,z)
#endif


/*---------------------------------------------------------
  IDL
-----------------------------------------------------------*/
#define in
#define out
#define inout


/*---------------------------------------------------------
  Argument checking
-----------------------------------------------------------*/
#define OUTARG(p)       ASSERT(p); if (!(p)) return E_INVALIDARG; else *(p) = 0;
#define OUTVAR(v)       ASSERT(v); if (!(v)) return E_INVALIDARG; else VariantInit(v);

#define INOUTARG(p)     ASSERT(p); if (!(p)) return E_INVALIDARG;
#define REFARG(p)       ASSERT(p); if (!(p)) return E_INVALIDARG;


/*---------------------------------------------------------
  Memory management
-----------------------------------------------------------*/
#ifdef DELETE
#undef DELETE
#endif

#define ALLOC(tp)       (tp*)malloc(sizeof(tp))
#define NALLOC(tp,n)    (tp*)malloc(sizeof(tp)*(n))

#define FREE(p)         if (p) { free((void*)(p)); (p) = NULL; }
#define DELETE(p)       if (p) { delete (p); (p) = NULL; }
#define RELEASE(p)      if (p) { (p)->Release(); (p) = NULL; }
#define REMOVE(p)       if (p) { while ((p)->Release() != 0) ; (p) = NULL; }
#define ADDREF(p)       ASSERT(p); if (p) { (p)->AddRef(); }

inline void FREEBSTR( BSTR& bstr ) 
{ 
  if (bstr) { SysFreeString(bstr); bstr = NULL; }
}

#ifndef NUMBER_OF
#define NUMBER_OF(array)    sizeof(array)/sizeof(array[0])
#endif

/*---------------------------------------------------------
  Reference counting
-----------------------------------------------------------*/
ULONG IncRefCount( inout ULONG* pRefCount );
ULONG DecRefCount( inout ULONG* pRefCount );


/*---------------------------------------------------------
  OLE versions of windows api
-----------------------------------------------------------*/
#define OLE(s)      L##s
#define WINERROR	HRESULT_FROM_WIN32

HRESULT OleRegOpenKey         ( in HKEY keyRoot, in LPCOLESTR pszPath, out HKEY* pkey );
HRESULT OleRegCreateKey       ( in HKEY keyRoot, in LPCOLESTR pszPath, out HKEY* pkey );
HRESULT OleRegSetValue        ( in HKEY key,     in LPCOLESTR pszName, in  LPCOLESTR pszValue );
HRESULT OleRegGetValue        ( in HKEY key,     in LPCOLESTR pszName, out LPOLESTR pszValue, in  ULONG length );
HRESULT OleRegDeleteRecursive ( in HKEY keyRoot, in LPCOLESTR pszPath );

bool    OleFileExist( in LPCOLESTR pszPath );
HRESULT OleFindFirst( in LPCOLESTR pszPath, out WIN32_FIND_DATA* pfindData, out HANDLE* pfindHandle );

HRESULT OleLoadLibrary( in LPCOLESTR pszPath, in DWORD flags, out HMODULE* pdll );
HRESULT OleLoadString( in HMODULE dll, in UINT resourceId, out BSTR* pbstrString );
