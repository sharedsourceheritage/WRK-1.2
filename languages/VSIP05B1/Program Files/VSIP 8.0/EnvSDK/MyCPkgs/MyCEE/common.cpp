
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
ULONG IncRefCount( inout ULONG* pRefCount )
{
  return (ULONG)InterlockedIncrement( (LONG*)pRefCount );
}

ULONG DecRefCount( inout ULONG* pRefCount )
{
  return (ULONG)InterlockedDecrement( (LONG*)pRefCount );
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
  buffer[1023] = '\0';
  OutputDebugStringA("MyC EE: ");
  OutputDebugStringA(buffer);
  OutputDebugStringA("\n");

  va_end( args );
  return;
}

/*---------------------------------------------------------
  OLE conversion
-----------------------------------------------------------*/
void OleToText( LPTSTR pszTextStr, LPCOLESTR pszOleStr, ULONG maxSize )
{
  if (pszTextStr == NULL) return;
  pszTextStr[0] = 0;
  if (pszOleStr == NULL) return;
  
#ifdef TCHAR_WIDE
  wcsncpy(pszTextStr,pszOleStr,maxSize);
#else
  wcstombs( pszTextStr, pszOleStr, maxSize );
#endif

  pszTextStr[maxSize] = 0;
  return;
}

void TextToOle( LPOLESTR pszOleStr, LPCTSTR pszTextStr, ULONG maxSize )
{
  if (pszOleStr == NULL) return;
  pszOleStr[0] = 0;
  if (pszTextStr == NULL) return;

#ifdef TCHAR_WIDE
  wcsncpy( pszOleStr, pszTextStr, maxSize );
#else
  mbstowcs( pszOleStr, pszTextStr, maxSize );
#endif

  pszOleStr[maxSize] = 0;
  return;
}

/*---------------------------------------------------------
  OLE versions of windows API
-----------------------------------------------------------*/

/*---------------------------------------------------------
  Libraries
-----------------------------------------------------------*/

HRESULT OleLoadLibrary( in LPCOLESTR pszPath, in DWORD flags, out HMODULE* pdll )
{
  OUTARG(pdll);
  REFARG(pszPath);

  TCHAR szTPath[MAX_PATH+1];
  OleToText( szTPath, pszPath, MAX_PATH );

  *pdll = LoadLibraryEx( szTPath, NULL, flags );
  if (*pdll == NULL) return WINERROR(GetLastError());

  return S_OK;
}

HRESULT OleLoadString( in HMODULE dll, in UINT resourceId, out BSTR* pbstrString )
{
  OUTARG(pbstrString);
 
  TCHAR szTString[MAX_PATH+1];
  if (LoadString( dll, resourceId, szTString, MAX_PATH ) == 0)
    return WINERROR(GetLastError());

  OLECHAR szOleString[MAX_PATH+1];
  TextToOle( szOleString, szTString, MAX_PATH );

  *pbstrString = SysAllocString( szOleString );
  if (*pbstrString==NULL) return E_OUTOFMEMORY;

  return S_OK;
}


/*---------------------------------------------------------
  File finding
-----------------------------------------------------------*/
bool OleFileExist( in LPCOLESTR pszPath )
{
  if (!pszPath) return false;

  TCHAR szTPath[MAX_PATH+1];
  OleToText( szTPath, pszPath, MAX_PATH );

  return (0xFFFFFFFF != GetFileAttributes( szTPath ));
}

HRESULT OleFindFirst( in LPCOLESTR pszPath, out WIN32_FIND_DATA* pfindData, out HANDLE* pfindHandle )
{
  OUTARG(pfindHandle);
  if (!pfindData) return E_INVALIDARG;
            else memset( pfindData, 0, sizeof(*pfindData));
  REFARG(pszPath);

  TCHAR szTPath[MAX_PATH+1];
  OleToText( szTPath, pszPath, MAX_PATH );

  *pfindHandle = FindFirstFile( szTPath, pfindData );
  if (*pfindHandle == INVALID_HANDLE_VALUE) return WINERROR(GetLastError());

  return S_OK;
}


/*---------------------------------------------------------
  Registry
-----------------------------------------------------------*/
HRESULT OleRegOpenKey( in HKEY keyRoot, in LPCOLESTR pszPath, out HKEY* pkey )
{
  OUTARG(pkey);
  REFARG(pszPath);
  HRESULT hr = S_OK;

  TCHAR   szTPath[MAX_PATH+1];
  OleToText( szTPath, pszPath, MAX_PATH );
  LONG lRetVal = RegOpenKeyEx( keyRoot, szTPath, 0, KEY_ALL_ACCESS, pkey );
  if (ERROR_SUCCESS != lRetVal)
      hr = HRESULT_FROM_WIN32(lRetVal);

  return hr;
}

HRESULT OleRegCreateKey( in HKEY keyRoot, in LPCOLESTR pszPath, out HKEY* pkey )
{
  OUTARG(pkey);
  REFARG(pszPath);
  HRESULT hr = S_OK;

  TCHAR   szTPath[MAX_PATH+1];
  OleToText( szTPath, pszPath, MAX_PATH );
  LONG lRetVal = RegCreateKeyEx( keyRoot, szTPath, 0, NULL, REG_OPTION_NON_VOLATILE,
                                 KEY_ALL_ACCESS, NULL, pkey, NULL );
  if (ERROR_SUCCESS != lRetVal)
      hr = HRESULT_FROM_WIN32(lRetVal);

  return hr;

}

HRESULT OleRegSetValue( in HKEY key, in LPCOLESTR pszName, in LPCOLESTR pszValue )
{
  TCHAR   szTName[MAX_PATH+1];
  HRESULT hr = S_OK;
  OleToText( szTName, pszName, MAX_PATH );

  TCHAR   szTValue[MAX_PATH+1];
  OleToText( szTValue, pszValue, MAX_PATH );

  LONG lRetVal = RegSetValueEx( key, (pszName ? szTName : NULL), 0, REG_SZ, (BYTE*)szTValue, ((lstrlen(szTValue)+1) * sizeof(TCHAR)) );
  if (ERROR_SUCCESS != lRetVal)
      hr = HRESULT_FROM_WIN32(lRetVal);

  return hr;
}

HRESULT OleRegGetValue( in HKEY key, in LPCOLESTR pszName, out LPOLESTR pszValue, in ULONG length )
{
  if (!pszValue)  return E_INVALIDARG;
          else pszValue[0] = 0;

  HRESULT hr = S_OK;
  TCHAR   szTName[MAX_PATH+1];
  OleToText( szTName, pszName, MAX_PATH );

  TCHAR   szTValue[MAX_PATH+1];
  DWORD   size  = sizeof(szTValue);
  DWORD   type  = REG_SZ;

  LONG lRetVal = RegQueryValueEx( key, (pszName ? szTName : NULL), 0, &type, reinterpret_cast<BYTE*>(szTValue), &size );
  if (ERROR_SUCCESS != lRetVal)
      return HRESULT_FROM_WIN32(lRetVal);

  if (type != REG_SZ) return E_FAIL;

  TextToOle( pszValue, szTValue, length );
  return S_OK;
}


HRESULT RegDeleteRecursive( in HKEY keyRoot, in LPCTSTR pszPath )
{
  HRESULT hr = S_OK;
  HKEY    key       = 0;
  ULONG   subKeys   = 0;
  ULONG   maxKeyLen = 0;

  ULONG   currentKey= 0;
  LPTSTR  pszKeyName   = NULL;
  
  LONG lRetVal = RegOpenKeyEx( keyRoot, pszPath, 0, KEY_ALL_ACCESS, &key );
  if (ERROR_SUCCESS != lRetVal)
  {
      hr = HRESULT_FROM_WIN32(lRetVal);
      goto fail;
  }

  lRetVal = RegQueryInfoKey( key, NULL, NULL, NULL,
                             &subKeys, &maxKeyLen, 
                             NULL, NULL, NULL, NULL, NULL, NULL );
  if (ERROR_SUCCESS != lRetVal)
  {
      hr = HRESULT_FROM_WIN32(lRetVal);
      goto fail;
  }
  if (subKeys == 0) goto fail;

  pszKeyName = (LPTSTR) malloc( sizeof(TCHAR) * (maxKeyLen+1) );
  if (pszKeyName == NULL) 
  {
	  hr = E_OUTOFMEMORY;
	  goto fail;
  }

  for (currentKey = 0; currentKey < subKeys; currentKey++)
  {
    ULONG keyLen;

    keyLen = maxKeyLen+1;
    lRetVal = RegEnumKeyEx( key, currentKey, pszKeyName, &keyLen, NULL, NULL, NULL, NULL );
    if (ERROR_SUCCESS == lRetVal)
    {
      RegDeleteRecursive(key,pszKeyName);
    }
    else 
    {
        ASSERT(0);
        hr = HRESULT_FROM_WIN32(hr);
    }
  }

fail:
  lRetVal = RegDeleteKey( keyRoot, pszPath );
  if (SUCCEEDED(hr) && (ERROR_SUCCESS!=lRetVal))
      hr = HRESULT_FROM_WIN32(hr);
  if (key) RegCloseKey(key);
  if (pszKeyName) free(pszKeyName);
  return hr;
}

HRESULT OleRegDeleteRecursive( in HKEY keyRoot, in LPCOLESTR pszPath )
{
  REFARG(pszPath);

  TCHAR   szTPath[MAX_PATH+1];
  OleToText( szTPath, pszPath, MAX_PATH );
  return RegDeleteRecursive( keyRoot, szTPath );
}
