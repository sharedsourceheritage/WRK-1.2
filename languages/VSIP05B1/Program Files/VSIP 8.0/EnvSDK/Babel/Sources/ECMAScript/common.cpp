/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include <stdio.h>
#include <stdarg.h>


#ifdef _UNICODE
#define TCHAR_WIDE
#endif

/*---------------------------------------------------------
  Reference counting
-----------------------------------------------------------*/
ULONG IncRefCount( inout ULONG* refCount )
{
  return (ULONG)InterlockedIncrement( (LONG*)refCount );
}

ULONG DecRefCount( inout ULONG* refCount )
{
  return (ULONG)InterlockedDecrement( (LONG*)refCount );
}

/*---------------------------------------------------------
  Debugging
-----------------------------------------------------------*/
void Trace( const char* format, ... )
{
  va_list args;
  va_start( args, format );

  char buffer[1024];
  _vsnprintf( buffer, 1024, format, args );

#ifdef TraceDllName
  OutputDebugStringA(TraceDllName);
  OutputDebugStringA(": ");
#endif

  OutputDebugStringA(buffer);
  OutputDebugStringA("\n");

  va_end( args );
  return;
}

/*---------------------------------------------------------
  OLE conversion
-----------------------------------------------------------*/
void OleToText( LPTSTR textStr, LPCOLESTR oleStr, ULONG maxSize )
{
  textStr[0] = 0;
  if (oleStr == NULL) return;
  
#ifdef TCHAR_WIDE
  wcsncpy(textStr,oleStr,maxSize);
#else
  wcstombs( textStr, oleStr, maxSize );
#endif

  textStr[maxSize] = 0;
  return;
}

void TextToOle( LPOLESTR oleStr, LPCTSTR textStr, ULONG maxSize )
{
  oleStr[0] = 0;
  if (textStr == NULL) return;

#ifdef TCHAR_WIDE
  wcsncpy( oleStr, textStr, maxSize );
#else
  mbstowcs( oleStr, textStr, maxSize );
#endif

  oleStr[maxSize] = 0;
  return;
}

/*---------------------------------------------------------
  OLE versions of windows API
-----------------------------------------------------------*/

/*---------------------------------------------------------
  Libraries
-----------------------------------------------------------*/

HRESULT OleGetModuleFileName( in HINSTANCE instance, out LPOLESTR path, in ULONG maxSize )
{
  REFARG(path);
  TCHAR tpath[MAX_PATH+1];

  if (GetModuleFileName(instance,tpath,MAX_PATH) == 0)
  {
    return WINERROR(GetLastError());
  }

  TextToOle( path, tpath, maxSize );
  return S_OK;
}

HRESULT OleLoadLibrary( in LPCOLESTR path, in DWORD flags, out HMODULE* dll )
{
  OUTARG(dll);
  REFARG(path);

  TCHAR tpath[MAX_PATH+1];
  OleToText( tpath, path, MAX_PATH );

  *dll = LoadLibraryEx( tpath, NULL, flags );
  if (*dll == NULL) return WINERROR(GetLastError());

  return S_OK;
}

HRESULT OleLoadString( in HMODULE dll, in UINT resourceId, out BSTR* string )
{
  OUTARG(string);
 
  TCHAR tstring[MAX_PATH+1];
  if (LoadString( dll, resourceId, tstring, MAX_PATH ) == 0)
    return WINERROR(GetLastError());

  OLECHAR olestring[MAX_PATH+1];
  TextToOle( olestring, tstring, MAX_PATH );

  *string = SysAllocString( olestring );
  if (*string==NULL) return E_OUTOFMEMORY;

  return S_OK;
}


/*---------------------------------------------------------
  File finding
-----------------------------------------------------------*/
bool OleFileExist( in LPCOLESTR path )
{
  if (!path) return false;

  TCHAR tpath[MAX_PATH+1];
  OleToText( tpath, path, MAX_PATH );

  return (0xFFFFFFFF != GetFileAttributes( tpath ));
}

HRESULT OleFindFirst( in LPCOLESTR path, out WIN32_FIND_DATA* findData, out HANDLE* findHandle )
{
  OUTARG(findHandle);
  if (!findData) return E_INVALIDARG;
            else memset( findData, 0, sizeof(*findData));
  REFARG(path);

  TCHAR tpath[MAX_PATH+1];
  OleToText( tpath, path, MAX_PATH );

  *findHandle = FindFirstFile( tpath, findData );
  if (*findHandle == INVALID_HANDLE_VALUE) return WINERROR(GetLastError());

  return S_OK;
}


/*---------------------------------------------------------
  Registry
-----------------------------------------------------------*/
HRESULT OleRegOpenKey( in HKEY keyRoot, in LPCOLESTR path, out HKEY* key )
{
  OUTARG(key);
  REFARG(path);

  TCHAR   tpath[MAX_PATH+1];
  OleToText( tpath, path, MAX_PATH );
  return WINERROR( RegOpenKeyEx( keyRoot, tpath, 0, KEY_ALL_ACCESS, key ));
}

HRESULT OleRegCreateKey( in HKEY keyRoot, in LPCOLESTR path, out HKEY* key )
{
  OUTARG(key);
  REFARG(path);

  TCHAR   tpath[MAX_PATH+1];
  OleToText( tpath, path, MAX_PATH );
  return WINERROR( RegCreateKeyEx( keyRoot, tpath, 0, NULL, REG_OPTION_NON_VOLATILE,
                                    KEY_ALL_ACCESS, NULL, key, NULL ));
}

HRESULT OleRegSetValue( in HKEY key, in LPCOLESTR name, in LPCOLESTR value )
{
  TCHAR   tname[MAX_PATH+1];
  OleToText( tname, name, MAX_PATH );

  TCHAR   tvalue[MAX_PATH+1];
  OleToText( tvalue, value, MAX_PATH );

  return WINERROR( RegSetValueEx( key, (name ? tname : NULL), 0, REG_SZ, (BYTE*)tvalue, ((_tcslen(tvalue)+1) * sizeof(TCHAR)) ));
}


HRESULT OleRegSetValueDword( in HKEY key, in LPCOLESTR name, in DWORD value )
{
  TCHAR   tname[MAX_PATH+1];
  OleToText( tname, name, MAX_PATH );

  return WINERROR( RegSetValueEx( key, (name ? tname : NULL), 0, REG_DWORD, (BYTE*)(&value), sizeof(value)));
}


HRESULT OleRegGetValue( in HKEY key, in LPCOLESTR name, out LPOLESTR value, in ULONG length )
{
  if (!value)  return E_INVALIDARG;
          else value[0] = 0;

  TCHAR   tname[MAX_PATH+1];
  OleToText( tname, name, MAX_PATH );

  TCHAR   tvalue[MAX_PATH+1];
  DWORD   size  = sizeof(tvalue);
  DWORD   type  = REG_SZ;

  HRESULT hr = WINERROR( RegQueryValueEx( key, (name ? tname : NULL), 0, &type, reinterpret_cast<BYTE*>(tvalue), &size ));
  if (FAILED(hr))     return hr;
  if (type != REG_SZ) return E_FAIL;

  TextToOle( value, tvalue, length );
  return S_OK;
}


HRESULT RegDeleteRecursive( in HKEY keyRoot, in LPCTSTR path )
{
  HRESULT hr;
  HKEY    key       = 0;
  ULONG   subKeys   = 0;
  ULONG   maxKeyLen = 0;

  ULONG   currentKey= 0;
  LPTSTR  keyName   = NULL;
  
  hr = WINERROR(RegOpenKeyEx( keyRoot, path, 0, KEY_ALL_ACCESS, &key ));
  if (FAILED(hr)) goto fail;

  hr = WINERROR(RegQueryInfoKey( key, NULL, NULL, NULL,
                                &subKeys, &maxKeyLen, 
                                NULL, NULL, NULL, NULL, NULL, NULL ));
  if (FAILED(hr))   goto fail;
  if (subKeys == 0) goto fail;

  keyName = (LPTSTR)_alloca( sizeof(TCHAR) * (maxKeyLen+1) );
  if (keyName == NULL) goto fail;

  for (currentKey = 0; currentKey < subKeys; currentKey++)
  {
    ULONG keyLen;

    keyLen = maxKeyLen+1;
    hr = WINERROR( RegEnumKeyEx( key, currentKey, keyName, &keyLen, NULL, NULL, NULL, NULL ));
    if (SUCCEEDED(hr))
    {
      RegDeleteRecursive(key,keyName);
    }
    else ASSERT(0);
  }

fail:
  hr = WINERROR(RegDeleteKey( keyRoot, path ));
  if (key) RegCloseKey(key);
  return hr;
}

HRESULT OleRegDeleteRecursive( in HKEY keyRoot, in LPCOLESTR path )
{
  REFARG(path);

  TCHAR   tpath[MAX_PATH+1];
  OleToText( tpath, path, MAX_PATH );
  return RegDeleteRecursive( keyRoot, tpath );
}
