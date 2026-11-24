/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef common_h
#define common_h

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

#define TraceDllName  "EcmaService"

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


/*---------------------------------------------------------
  Reference counting
-----------------------------------------------------------*/
ULONG IncRefCount( inout ULONG* refCount );
ULONG DecRefCount( inout ULONG* refCount );


/*---------------------------------------------------------
  OLE versions of windows api
-----------------------------------------------------------*/
#define OLE(s)      L##s
#define WINERROR	HRESULT_FROM_WIN32

HRESULT OleRegOpenKey         ( in HKEY keyRoot, in LPCOLESTR path, out HKEY* key );
HRESULT OleRegCreateKey       ( in HKEY keyRoot, in LPCOLESTR path, out HKEY* key );
HRESULT OleRegSetValue        ( in HKEY key,     in LPCOLESTR name, in  LPCOLESTR value );
HRESULT OleRegSetValueDword   ( in HKEY key,     in LPCOLESTR name, in  DWORD value );
HRESULT OleRegGetValue        ( in HKEY key,     in LPCOLESTR name, out LPOLESTR value, in  ULONG length );
HRESULT OleRegDeleteRecursive ( in HKEY keyRoot, in LPCOLESTR path );

bool    OleFileExist( in LPCOLESTR path );
HRESULT OleFindFirst( in LPCOLESTR path, out WIN32_FIND_DATA* findData, out HANDLE* findHandle );

HRESULT OleGetModuleFileName  ( in HINSTANCE instance, out LPOLESTR path, in ULONG maxSize );
HRESULT OleLoadLibrary( in LPCOLESTR path, in DWORD flags, out HMODULE* dll );
HRESULT OleLoadString( in HMODULE dll, in UINT resourceId, out BSTR* string );

#endif
