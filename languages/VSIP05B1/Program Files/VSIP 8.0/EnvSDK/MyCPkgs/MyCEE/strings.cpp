
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  Prototypes
-----------------------------------------------------------*/
static HRESULT LoadResourceDll( in HMODULE instance, 
                                in const CLSID& clsid, 
                                out HMODULE* presourceDll );


/*---------------------------------------------------------
  String Info
-----------------------------------------------------------*/
struct StringInfo
{
  UINT      stringId;
  LPCOLESTR pszStringDefault;
  BSTR      bstrStringResource;
};

StringInfo stringTable[] =
{
  { IDS_INFO_MYCDESCRIPTION   ,OLE("MyC Expression Evaluator")              },
  { IDS_MSG_UNKNOWNTYPE       ,OLE("")                                      },
  { IDS_MSG_UNKNOWNVALUE      ,OLE("(unknown)")                             },
  { IDS_MSG_UNKNOWNVALUEBITS  ,OLE("(unknown)")                             },
  { IDS_MSG_VALUEFALSE        ,OLE("false")                                 },
  { IDS_MSG_VALUETRUE         ,OLE("true")                                  },
  { IDS_ERR_INVALIDEXPR       ,OLE("invalid expression (at '%s')")          },
  { IDS_ERR_NOTATEND          ,OLE("invalid expression (at '%s')")          },
  { IDS_ERR_AMBIGIOUSASSOC    ,OLE("ambiguous use of '%s'")                 },
  { IDS_ERR_ILLEGALOPERANDS   ,OLE("illegal operand types for '%s'")        },
  { IDS_ERR_ILLEGALOPERAND    ,OLE("illegal operand type for '%s'")         },
  { IDS_ERR_UNBALANCEDPARENS  ,OLE("unbalanced parenthesis")                },
  { IDS_ERR_EXPECTHEXADECIMAL ,OLE("expecting hexadecimal number (at '%s')")},
  { IDS_ERR_NOTINSCOPE        ,OLE("symbol '%s' is not defined")            },
  { IDS_ERR_DIVIDEBYZERO      ,OLE("divide by zero" )                       },
  { 0 }
};


/*---------------------------------------------------------
  GetString:
    Returns a localised string or it returns a default 
    string if the resource dll could somehow not be loaded.
    This functions never fails!
-----------------------------------------------------------*/

LPCOLESTR GetString( in ULONG stringId )
{
  //for all strings
  for (StringInfo* pstringInfo = stringTable; pstringInfo->stringId != 0; pstringInfo++)
  {
    //free the string
    if (stringId == pstringInfo->stringId)
    {
      //if resource loaded
      if (pstringInfo->bstrStringResource)
        return pstringInfo->bstrStringResource;
      //if default string
      else if (pstringInfo->pszStringDefault)
        return pstringInfo->pszStringDefault;
      
      //otherwise return ""
      break;
    }
  }

  return OLE("");
}

/*---------------------------------------------------------
  InitString/DoneString
----------------------------------------------------------*/
HRESULT InitStrings( in HMODULE instance, in const CLSID& clsid )
{
  HRESULT hr;

  //free any old resource entries
  hr = DoneStrings();
  if (FAILED(hr)) return hr;
  
  //load the resource dll
  HMODULE resourceDll = 0;
  hr = LoadResourceDll( instance, clsid, &resourceDll );
  //ASSERT(SUCCEEDED(hr));
  if (FAILED(hr)) return hr;

  //initialize every entry in the string info table
  for (StringInfo* pstringInfo = stringTable; pstringInfo->stringId != 0; pstringInfo++)
  {
    //we don't care about succeeding or not
    hr = OleLoadString( resourceDll, pstringInfo->stringId, &(pstringInfo->bstrStringResource));
    ASSERT(SUCCEEDED(hr));
  }

  //unload the resource dll
  FreeModule( resourceDll );
  return S_OK;
}


HRESULT DoneStrings()
{
  //for all strings
  for (StringInfo* pstringInfo = stringTable; pstringInfo->stringId != 0; pstringInfo++)
  {
    //free the string
    FREEBSTR(pstringInfo->bstrStringResource);
  }

  return S_OK;
}



/*---------------------------------------------------------
  LoadResourceDll
    The following code should be highly robust, it is better
    to load something than to fail at the first error
-----------------------------------------------------------*/

/*---------------------------------------------------------
  GetResourceDllPathInfoFromRegistry:    
    Try to load the dll root path and name from the
    "HKCR\CLSID\{...}\SatelliteDll" entry
-----------------------------------------------------------*/
HRESULT GetResourceDllPathInfoFromRegistry( in  const CLSID& clsid,
                                            out BSTR*        pbstrRootPath, 
                                            out BSTR*        pbstrDllName )
{
  OUTARG(pbstrRootPath);
  OUTARG(pbstrDllName)
  HRESULT hr = S_OK;

  //setup registry path to "CLSID\{...}\SateliteDll"
  OLECHAR szClsidStr[128+1];

  if (StringFromGUID2(clsid, szClsidStr, 128) == 0)
    return E_FAIL;

  OLECHAR szClassPath[MAX_PATH+1];
  _snwprintf( szClassPath, MAX_PATH, OLE("CLSID\\%s\\SatelliteDll"), szClsidStr );
  szClassPath[MAX_PATH] = L'\0';

  HKEY keyClass = 0;
  LONG lRetVal = RegOpenKeyExW(HKEY_CLASSES_ROOT, szClassPath, 0, KEY_READ, &keyClass );
  if (ERROR_SUCCESS!=lRetVal) return HRESULT_FROM_WIN32(lRetVal);

  //read the values
  OLECHAR szBuffer[MAX_PATH+1];
  hr = OleRegGetValue( keyClass, OLE("path"), szBuffer, MAX_PATH );
  if (SUCCEEDED(hr)) *pbstrRootPath = SysAllocString( szBuffer );

  hr = OleRegGetValue( keyClass, OLE("dllName"), szBuffer, MAX_PATH );
  if (SUCCEEDED(hr)) *pbstrDllName = SysAllocString( szBuffer );

  RegCloseKey(keyClass);
  return S_OK;
}

/*---------------------------------------------------------
  GetResourceDllPathInfo:
    - first try to get the path and dll name from the registry
    - if that fails, take the dll path of this dll
      as the root path and its name plus "ui" as the name of
      the resource dll
-----------------------------------------------------------*/
HRESULT GetResourceDllPathInfo( in HMODULE      instance, 
                                in const CLSID& clsid,
                                out BSTR*       pbstrRootPath, 
                                out BSTR*       pbstrDllName )
{
  OUTARG(pbstrRootPath);
  OUTARG(pbstrDllName);
  HRESULT hr = S_OK;
  
  GetResourceDllPathInfoFromRegistry( clsid, pbstrRootPath, pbstrDllName );
  if (*pbstrRootPath == NULL || *pbstrDllName == NULL)
  {
    //use the dll directory as root and its name+"ui" as the path
    OLECHAR szDllPath[MAX_PATH];
    DWORD dwLen = ::GetModuleFileNameW(instance, szDllPath, MAX_PATH);
    if (dwLen == 0)
    {
        hr = HRESULT_FROM_WIN32(::GetLastError());
        goto fail;
    }
    if (dwLen == MAX_PATH)
    {
        hr = HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
        goto fail;
    }

    LPOLESTR pszNameStart = wcsrchr( szDllPath, OLE('\\'));
    if (pszNameStart == NULL) { hr = E_FAIL; goto fail; };

    LPOLESTR pszExtStart  = wcsrchr( szDllPath, OLE('.'));
    if (pszExtStart == NULL) { hr = E_FAIL; goto fail; };

    //if no pbstrDllName
    if (*pbstrDllName == NULL)
    {
        const WCHAR wszUIDll[] = L"ui.dll";
        int cchFreeBuffer = MAX_PATH - abs(pszExtStart - szDllPath);
        if (cchFreeBuffer <= lstrlenW(wszUIDll))
        {
            hr = HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
            goto fail;
        }
        wcscpy(pszExtStart, wszUIDll);
        *pbstrDllName = SysAllocString( pszNameStart+1 );
        if (*pbstrDllName == NULL) { hr = E_OUTOFMEMORY; goto fail; }
    }

    //if no pbstrRootPath
    if (*pbstrRootPath == NULL)
    {
     *pszNameStart = 0;
     *pbstrRootPath = SysAllocString( szDllPath );
     if (*pbstrRootPath == NULL) { hr = E_OUTOFMEMORY; goto fail; }
    }
  }
      
fail:
  if (FAILED(hr))
  {
    FREEBSTR(*pbstrRootPath);
    FREEBSTR(*pbstrDllName);
  }
  return hr;
}

/*---------------------------------------------------------
  GetResourceDllPath:
  - first get the root path and dll name using GetResourceDllPathInfo
  - try to load it from the following subdirectories
    * lcid user 
    * lcid user with default sublanguage
    * lcid system 
    * lcid system with default sublanguage
    * us english
  - if that failed try to load it from any subdirectory
  - if that failed we give up and use default strings
-----------------------------------------------------------*/
HRESULT GetResourceDllPath( in LPCOLESTR pszRootPath, in LPCOLESTR pszDllName, out BSTR* pbstrDllPath )
{
  OUTARG(pbstrDllPath);
  REFARG(pszDllName);
  REFARG(pszRootPath);
  HRESULT hr;
  OLECHAR szPath[MAX_PATH+1];  

  //lookup according to LCID table: 
  // user, user /default sub language, system , system /default sublanguage, us english
  LCID lcidUser   = GetUserDefaultLCID();
  LCID lcidSystem = GetSystemDefaultLCID();
  LCID lcidTable[] = { lcidUser,
                       MAKELCID(MAKELANGID(PRIMARYLANGID(lcidUser), SUBLANG_DEFAULT), SORTIDFROMLCID(lcidUser)),
                       lcidSystem,
                       MAKELCID(MAKELANGID(PRIMARYLANGID(lcidSystem), SUBLANG_DEFAULT), SORTIDFROMLCID(lcidSystem)),
                       0x409
                     };
  const int  lcidTableSize = sizeof(lcidTable)/sizeof(LCID);

  for (int i = 0; i < lcidTableSize; i++)
  {
    if (lcidTable[i] == 0) continue;

    _snwprintf( szPath, MAX_PATH, OLE("%s\\%u\\%s"), pszRootPath, lcidTable[i], pszDllName );
    szPath[MAX_PATH] = L'\0';

    if (OleFileExist(szPath)) 
    {
       //we found it!
       *pbstrDllPath = SysAllocString(szPath);
       if (*pbstrDllPath == NULL) return E_OUTOFMEMORY;

       return S_OK;
    }
  }

  //if that failed, we try to find the first resource dll in a subdirectory
  WIN32_FIND_DATA findData;
  HANDLE          findHandle;

  _snwprintf( szPath, MAX_PATH, OLE("%s\\*.*"), pszRootPath );
  szPath[MAX_PATH] = L'\0';

  hr = OleFindFirst( szPath, &findData, &findHandle );
  if (FAILED(hr)) return hr;

  do{
    if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0) continue;
    if (lstrcmp(findData.cFileName,TEXT(".")) == 0) continue;
    if (lstrcmp(findData.cFileName,TEXT("..")) == 0) continue;

#ifdef UNICODE
    _snwprintf( szPath, MAX_PATH, OLE("%s\\%s\\%s"), pszRootPath, findData.cFileName, pszDllName );
#else
    _snwprintf( szPath, MAX_PATH, OLE("%s\\%S\\%s"), pszRootPath, findData.cFileName, pszDllName );
#endif
    szPath[MAX_PATH] = L'\0';

    if (OleFileExist(szPath))
    {
      //we found it!
       FindClose(findHandle);
       *pbstrDllPath = SysAllocString(szPath);
       if (*pbstrDllPath == NULL) return E_OUTOFMEMORY;

       return S_OK;
    }
  } while (FindNextFile( findHandle, &findData ));
  FindClose(findHandle);


  //we failed to find anything
  return E_FAIL;
}

/*---------------------------------------------------------
  LoadResourceDll
-----------------------------------------------------------*/
HRESULT LoadResourceDll( in HMODULE instance, in const CLSID& clsid, out HMODULE* presourceDll )
{
  OUTARG(presourceDll);
  HRESULT hr;

  //get the root path and dll name
  BSTR bstrRootPath = NULL;
  BSTR bstrDllName  = NULL;

  hr = GetResourceDllPathInfo( instance, clsid, &bstrRootPath, &bstrDllName );
  if (FAILED(hr)) return hr;

  //get the resource dll path according to the LCID
  BSTR bstrResourceDllPath = NULL;
  hr = GetResourceDllPath( bstrRootPath, bstrDllName, &bstrResourceDllPath );
  FREEBSTR(bstrRootPath);
  FREEBSTR(bstrDllName);
  if (FAILED(hr)) return hr;

  //load the resource dll
  hr = OleLoadLibrary( bstrResourceDllPath, LOAD_LIBRARY_AS_DATAFILE, presourceDll );
  FREEBSTR(bstrResourceDllPath);
  if (FAILED(hr)) return hr;

  return S_OK;
};

