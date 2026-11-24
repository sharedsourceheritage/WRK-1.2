/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef common_h
#define common_h

inline HRESULT HRFromLastError()
{
    DWORD dwErr = GetLastError();
    return HRESULT_FROM_WIN32(dwErr);
}

/*---------------------------------------------------------
  Registry (Inline functions to return a HRESULT)
-----------------------------------------------------------*/
inline HRESULT hrRegOpenKeyEx(HKEY hKey, LPCTSTR lpSubKey, DWORD dwOptions, REGSAM samDesired, PHKEY phkResult)
{
    LONG lRetCode = RegOpenKeyEx(hKey, lpSubKey, dwOptions, samDesired, phkResult);
    return (ERROR_SUCCESS == lRetCode) ? S_OK : HRESULT_FROM_WIN32(lRetCode);
}
inline HRESULT hrRegCreateKeyEx(HKEY hKey, LPCTSTR lpSubKey, DWORD Reserved, LPTSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition)
{
    LONG lRetCode = RegCreateKeyEx(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition);
    return (ERROR_SUCCESS == lRetCode) ? S_OK : HRESULT_FROM_WIN32(lRetCode);
}
inline HRESULT hrRegQueryValueExA(HKEY key, const char *lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpchData)
{
    LONG lRetCode = RegQueryValueExA(key, lpValueName, lpReserved, lpType, lpData, lpchData);
    return (ERROR_SUCCESS == lRetCode) ? S_OK : HRESULT_FROM_WIN32(lRetCode);
}
inline HRESULT hrRegQueryValueEx(HKEY key, LPCTSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpchData)
{
    LONG lRetCode = RegQueryValueEx(key, lpValueName, lpReserved, lpType, lpData, lpchData);
    return (ERROR_SUCCESS == lRetCode) ? S_OK : HRESULT_FROM_WIN32(lRetCode);
}
inline HRESULT hrRegSetValueEx(HKEY hKey, LPCTSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE* lpData, DWORD cbData)
{
    LONG lRetCode = RegSetValueEx(hKey, lpValueName, Reserved, dwType, lpData, cbData);
    return (ERROR_SUCCESS == lRetCode) ? S_OK : HRESULT_FROM_WIN32(lRetCode);
}


/*---------------------------------------------------------
  String Utilities
-----------------------------------------------------------*/
inline void bstrFree(BSTR& bstr)
{
    ::SysFreeString(bstr);
    bstr = NULL;
}

inline BSTR bstrCopy( BSTR& bstr, const wchar_t* src, int maxLen )
{
    if (maxLen<0)  maxLen = lstrlenW(src); 
    if (maxLen<=0) return NULL;
    
    if (bstr) 
      SysReAllocStringLen( &bstr, src, maxLen );
    else
      bstr = SysAllocStringLen( src, maxLen );

    return bstr;
}

inline bool strEmpty(const wchar_t* str)
{
    return ( (NULL==str) || (0==lstrlenW(str)) );
}

inline int strCompare(const wchar_t* s, const wchar_t* t)
{
    if (s == t) return 0;
    if (!s)     return (-1);
    if (!t)     return 1;
                return wcscmp(s,t);
}

inline int strICompare(const wchar_t* s, const wchar_t* t)
{
    if (s == t) return 0;
    if (!s)     return (-1);
    if (!t)     return 1;
                return wcsicmp(s,t);
}

inline int strCompareLen(const wchar_t* s, const wchar_t* t, unsigned int n)
{
    if (n == 0) return 0;
    if (s == t) return 0;
    if (!s)     return (-1);
    if (!t)     return 1;
                return wcsncmp(s,t,n);
}

inline int strICompareLen(const wchar_t* s, const wchar_t* t, unsigned int n)
{
    if (n == 0) return 0;
    if (s == t) return 0;
    if (!s)     return (-1);
    if (!t)     return 1;
                return wcsnicmp(s,t,n);
}
/*---------------------------------------------------------
  Debugging
-----------------------------------------------------------*/
void  Trace( const char* format, ... );

void  TraceInit( const char* moduleName, wchar_t* regPath );
void  TraceDone();
void  TraceCreate( const char* name, IUnknown* obj, bool hide );
void  TraceDestroy( IUnknown* obj );
void  TraceLiveObjects( const char* msg );

#ifdef NDEBUG
# define ASSERT(x)
# define TRACE(s)       
# define TRACE1(s,x)     
# define TRACE2(s,x,y)   
# define TRACE3(s,x,y,z) 

# define TRACE_INIT(name,regPath)
# define TRACE_DONE()
# define TRACE_LIVE_OBJECTS(msg)
# define TRACE_CREATE(name,obj)  
# define TRACE_DESTROY(obj)      
# define TRACE_CREATE_HIDE(name,obj)  
#else
# define ASSERT(x)       assert(x)
# define TRACE(s)        Trace(s)
# define TRACE1(s,x)     Trace(s,x)
# define TRACE2(s,x,y)   Trace(s,x,y)
# define TRACE3(s,x,y,z) Trace(s,x,y,z)

# define TRACE_INIT(name,regPath)        TraceInit(name,regPath)
# define TRACE_DONE()            TraceDone()
# define TRACE_LIVE_OBJECTS(msg) TraceLiveObjects(msg)
# define TRACE_CREATE(name,obj)  TraceCreate(name,obj,false)
# define TRACE_DESTROY(obj)      TraceDestroy(obj)
# define TRACE_CREATE_HIDE(name,obj)  TraceCreate(name,obj,true)
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

#define INARG(p)        ASSERT(p); if (!(p)) return E_INVALIDARG;
#define INOUTARG(p)     ASSERT(p); if (!(p)) return E_INVALIDARG;
#define REFARG(p)       ASSERT(p); if (!(p)) return E_INVALIDARG;


/*---------------------------------------------------------
  Memory management
-----------------------------------------------------------*/
#ifdef DELETE
#undef DELETE
#endif

#define ALLOC(tp)       (tp*)VSAlloc(sizeof(tp))
#define NALLOC(tp,n)    (tp*)VSAlloc(sizeof(tp)*(n))

#define FREE(p)         if (p) { VSFree ((void*)(p)); (p) = NULL; }
#define DELETE(p)       if (p) { delete (p); (p) = NULL; }
#define RELEASE(p)      if (p) { (p)->Release(); (p) = NULL; }
#define REMOVE(p)       if (p) { while ((p)->Release() != 0) ; (p) = NULL; }
#define ADDREF(p)       ASSERT(p); if (p) { (p)->AddRef(); }



/*---------------------------------------------------------
  Reference counting
-----------------------------------------------------------*/
ULONG IncRefCount( inout ULONG* refCount );
ULONG DecRefCount( inout ULONG* refCount );


/*---------------------------------------------------------
  COM
-----------------------------------------------------------*/
bool         SameObject ( in IUnknown* obj1, in IUnknown* obj2 );

STDMETHODIMP Connect    ( in IUnknown* eventSource, in IUnknown* eventSink, 
                          in const IID& eventIID, out DWORD* cookie );
STDMETHODIMP DisConnect ( in IUnknown* eventSource, 
                          in const IID& eventIID, inout DWORD* cookie );

/*---------------------------------------------------------
  CONSTANTS
-----------------------------------------------------------*/
#define MAXSTR		255
#define MAXPATH		255
#define MAXNAME		99
#define MAXGUID	    99
#define MAXIID      MAXGUID
#define MAXCLSID    MAXGUID

#endif
