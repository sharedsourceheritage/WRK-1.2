// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

// atl.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"
#include "RegObj.h"
#ifndef _WIN32_WCE
#include "AtlAssem.h"
#include <io.h>
#endif // _WIN32_WCE


CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_Registrar, CDLLRegObject)
	OBJECT_ENTRY_NON_CREATEABLE(CAxHostWindow)
END_OBJECT_MAP()

#ifndef _WIN32_WCE
static BOOL __cdecl _atl_check_manifest(HMODULE hDllHandle, unsigned int winmajor, unsigned int winminor);  /* local function */
#endif // WIN32_WCE

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
#ifndef _WIN32_WCE
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
#else // _WIN32_WCE
BOOL WINAPI DllMain(HANDLE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
#endif // _WIN32_WCE
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		bAtlAxWinInitialized = false;
#ifndef _WIN32_WCE
		OSVERSIONINFOA info;
		info.dwOSVersionInfoSize = sizeof(info);
		if (GetVersionExA(&info))
		{
#ifdef _UNICODE
			if (info.dwPlatformId != VER_PLATFORM_WIN32_NT)
			{
				MessageBoxA(NULL, "Can not run Unicode version of ATL80.DLL on Windows 95, Windows98 or Windows Me.\nPlease install the ANSI version.", "ATL", MB_ICONSTOP|MB_OK);
				return FALSE;
			}
#else
			if (info.dwPlatformId == VER_PLATFORM_WIN32_NT)
			{
				OutputDebugString(_T("Slight Performace loss due to running ANSI version of ATL80.DLL on Windows NT, Windows 2000, Windows XP or Windows Server 2003 \nPlease install the Unicode version.\n"));
			}
#endif
		}
#endif // _WIN32_WCE
#if defined(_DEBUG) && !defined(_WIN32_WCE)
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF);
		int n = 0;
		_CrtSetBreakAlloc(n);
#endif
		_Module.Init(ObjectMap, static_cast<HINSTANCE>(hInstance), &LIBID_ATLLib);
#ifdef _ATL_DEBUG_INTERFACES
		int ni = 0;
		_Module.m_nIndexBreakAt = ni;
#endif // _ATL_DEBUG_INTERFACES
#ifndef _WIN32_WCE
#if defined(_ATL_CHECK_MANIFEST)
		if (!_atl_check_manifest(hInstance, info.dwMajorVersion, info.dwMinorVersion))
		{
			MessageBoxA(NULL, "Error: ATL DLL was loaded without a manifest.", "Microsoft Visual C++ Runtime Library", MB_ICONSTOP|MB_OK);
			return FALSE;
		}
#endif
#endif // WIN32_WCE
		DisableThreadLibraryCalls(static_cast<HMODULE>(hInstance));
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
#ifdef _DEBUG
		::OutputDebugString(_T("ATL80.DLL exiting.\n"));
#endif
		_Module.Term();
		if (bAtlAxWinInitialized)
			AtlAxWinTerm();
#if defined(_DEBUG) && !defined(_WIN32_WCE)
		if (_CrtDumpMemoryLeaks())
			::MessageBeep(MB_ICONEXCLAMATION);
#endif
	}
	return TRUE;    // ok
}

namespace ATL
{
STDAPI AtlCreateRegistrar(IRegistrar** ppReg)
{
	if (ppReg == NULL)
		return E_POINTER;
	*ppReg = NULL;

	return( CDLLRegObject::_CreatorClass::CreateInstance(NULL, IID_IRegistrar, (void**)ppReg) );
}

STDAPI AtlUpdateRegistryFromResourceD(HINSTANCE hInst, LPCOLESTR lpszRes,
	BOOL bRegister, struct _ATL_REGMAP_ENTRY* pMapEntries, IRegistrar* pReg)
{
	ATLASSERT(hInst != NULL);
	if (hInst == NULL)
		return E_INVALIDARG;

	HRESULT hRes = S_OK;
	CComPtr<IRegistrar> p;

	if (pReg != NULL)
		p = pReg;
	else
	{
		hRes = AtlCreateRegistrar(&p);
	}
	if (NULL != pMapEntries)
	{
		while (NULL != pMapEntries->szKey)
		{
			ATLASSERT(NULL != pMapEntries->szData);
			p->AddReplacement(pMapEntries->szKey, pMapEntries->szData);
			pMapEntries++;
		}
	}
	if (SUCCEEDED(hRes))
	{
		TCHAR szModule[_MAX_PATH];
		int nRet = GetModuleFileName(hInst, szModule, _MAX_PATH);
		if(nRet == _MAX_PATH)
			return AtlHresultFromWin32(ERROR_BUFFER_OVERFLOW);
		
		if(nRet == 0)
			return AtlHresultFromLastError();

		USES_CONVERSION_EX;
		LPOLESTR pszModule = T2OLE_EX(szModule, _ATL_SAFE_ALLOCA_DEF_THRESHOLD);
#ifndef _UNICODE
		if(pszModule == NULL) 
			return E_OUTOFMEMORY;
#endif
		
		// Buffer Size is Multiplied by 2 because we are calling ReplaceSingleQuote
		OLECHAR pszModuleUnquoted[_MAX_PATH * 2];
		CAtlModule::EscapeSingleQuote(pszModuleUnquoted, _countof(pszModuleUnquoted), pszModule);
		if (hInst == GetModuleHandle(NULL)) // register as EXE
		{
			// If Registering as an EXE, then we quote the resultant path.
			// We don't do it for a DLL, because LoadLibrary fails if the path is
			// quoted
			OLECHAR pszModuleQuote[(_MAX_PATH + _ATL_QUOTES_SPACE)*2];
			pszModuleQuote[0] = OLESTR('\"');			
#if _SECURE_ATL
			if(!ocscpy_s(pszModuleQuote + 1, ((_MAX_PATH + _ATL_QUOTES_SPACE)*2)-1, pszModuleUnquoted))
			{
				return E_FAIL;
			}
			size_t nLen = ocslen(pszModuleQuote);
#else
			ocscpy(pszModuleQuote + 1, pszModuleUnquoted);
			int nLen = ocslen(pszModuleQuote);
#endif
			pszModuleQuote[nLen] = OLESTR('\"');
			pszModuleQuote[nLen + 1] = 0;
			
			hRes = p->AddReplacement(OLESTR("Module"), pszModuleQuote);			
		}
		else
		{
			hRes = p->AddReplacement(OLESTR("Module"), pszModuleUnquoted);
		}
		if(FAILED(hRes))
			return hRes;
	
		hRes = p->AddReplacement(OLESTR("Module_Raw"), pszModuleUnquoted);
		if(FAILED(hRes))
			return hRes;
	
		LPCOLESTR szType = OLESTR("REGISTRY");
		if (IS_INTRESOURCE(lpszRes))
		{
			if (bRegister)
				hRes = p->ResourceRegister(pszModule, ((UINT)LOWORD((DWORD_PTR)lpszRes)), szType);
			else
				hRes = p->ResourceUnregister(pszModule, ((UINT)LOWORD((DWORD_PTR)lpszRes)), szType);
		}
		else
		{
			if (bRegister)
				hRes = p->ResourceRegisterSz(pszModule, lpszRes, szType);
			else
				hRes = p->ResourceUnregisterSz(pszModule, lpszRes, szType);
		}

	}
	return hRes;
}

// Cannot pull these in from the static lib. The functions they reference are decorated
// with C++ calling convention. The functions are exported from the DLL with the 
// C calling convention
#ifdef _DEBUG
//CAtlWinModule _AtlWinModule;
CAtlComModule _AtlComModule;
#endif

}


/////////////////////////////////////////////////////////////////////////////
/* used in _ATL_CHECK_MANIFEST */
#ifndef _WIN32_WCE
#define _PATH_LEN 8000
#define _WINSXS_FOLDER _T("WinSxS\\")

#ifdef _UNICODE
#define _FINDACTCTXSECTIONSTRING "FindActCtxSectionStringW"
#define _TCSRCHR wcsrchr
#define _TCSNCAT_S wcsncat_s
#else
#define _FINDACTCTXSECTIONSTRING "FindActCtxSectionStringA"
#define _TCSRCHR strrchr
#define _TCSNCAT_S strncat_s
#endif

#define _MANIFEST_FILENAME _T(__LIBRARIES_ASSEMBLY_NAME_PREFIX)_T(".ATL.manifest")
#define _ATL_DLL_FILENAME _T("atl80.dll")

typedef BOOL (WINAPI * PFN_FINDAC)(DWORD dwFlags, const GUID *lpExtensionGuid,ULONG ulSectionId,LPCTSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);

static BOOL __cdecl _atl_check_manifest(HMODULE hDllHandle, unsigned int winmajor, unsigned int winminor)
{
	/* We check that the dll is loaded through a manifest.
	 *
	 * We check several conditions and exceptions:
	 *
	 * (1)  if ((OSVersion < WinXP) || (OSVersion < Win2K3))
	 *         return TRUE; [no need to check]
	 *
	 * (2)  if (dll is loaded from system32)
	 *          return FALSE;
	 *
	 * (3)  if (!(loaded through a manifest))
	 *          return FALSE;
	 *
	 * (4)  if (OSVersion >= LongHorn)
	 *          return TRUE
	 *
	 * (5)  if (loaded from %SystemRoot%\WinSxS)
	 *          return TRUE; [loaded from the WinSxS cache]
	 *
	 * (6)  if (manifest is in the same folder as the dll)
	 *          return TRUE;
	 *
	 * (7)  return FALSE; [loaded with another manifest]
	 *
	 * In general, when we encounter an error condition or something
	 * which blocks us from checking if the dll is loaded through a
	 * manifest, we do not return an error, but we let the dll to be
	 * loaded. Notice that this is not a security feature: it's an helper
	 * which will try (as much as possible) to discourage the practice
	 * of not using a manifest to load the ATL dll.
	 */

	TCHAR moduleFilePath[_PATH_LEN];
	TCHAR systemRoot[MAX_PATH];
	size_t moduleFilePathLen = 0;
	size_t systemRootLen = 0;

	/* check condition (1) */
	/* 5.1 is WinXP, 5.2 is Win2k3 */
	if (winmajor < 5 ||
		 (winmajor == 5 && winminor < 1))
	{
		return TRUE; /* no need to check */
	}

	///* retrieve moduleFilePath and systemRoot */
	{
		TCHAR tempPath[_PATH_LEN];
		TCHAR *myTestModuleName = NULL;
		DWORD ret = GetModuleFileName(hDllHandle, tempPath, _countof(tempPath));
		if (ret == 0 || ret >= _countof(tempPath))
		{
		 	/* error or filename longer than _PATH_LEN: we just let
		 	 * the user load the dll, without checking the manifest */
			return TRUE;
		}
		ret = GetLongPathName(tempPath, moduleFilePath, _countof(moduleFilePath));
		if (ret == 0 || ret >= _countof(moduleFilePath))
		{
		 	/* error or filename longer than _PATH_LEN: we just let
		 	  * the user load the dll, without checking the manifest */
			return TRUE;
		}

		myTestModuleName = const_cast<TCHAR*>(_TCSRCHR(moduleFilePath, L'\\'));

		if (myTestModuleName == NULL)
		{
			/* error: we could not find a backslash in moduleFilePath */
			return TRUE;
		}
		myTestModuleName++;
		*myTestModuleName = 0;
		/* moduleFilePath now contains only the path of the module ending with a backslash */
		moduleFilePathLen = _tcsnlen(moduleFilePath, _countof(moduleFilePath));

		ret = GetSystemDirectory(systemRoot, _countof(systemRoot));
		if (ret == 0 || ret >= _countof(systemRoot))
		{
			/* error or path longer than MAX_PATH: we just let
			 * the user load the dll, without checking the manifest */
			return TRUE;
		}
		/* add a trailing backslash if not there already */
		systemRootLen = ret;
		if (systemRoot[systemRootLen - 1] != _T('\\'))
		{
			if (_TCSNCAT_S(systemRoot, _countof(systemRoot), _T("\\"), _TRUNCATE) != 0)
			{
				/* error or not enough space */
				return TRUE;
			}
		}
		systemRootLen = _tcsnlen(systemRoot, _countof(systemRoot));
	}

	/* check condition (2) */
	if (moduleFilePathLen == systemRootLen)
	{
		size_t nRet = CompareString( LOCALE_INVARIANT, NORM_IGNORECASE, 
									 moduleFilePath, (DWORD)moduleFilePathLen, 
									 systemRoot, (DWORD)systemRootLen);
		if( 0 == nRet )
		{
			/* error comparing the strings */
			return TRUE;
		}
		if( CSTR_EQUAL == nRet )
		{
			return FALSE; /* dll loaded from system32 */
		}
	}

	/* check condition (3) */
	{
		HINSTANCE hKernel32 = GetModuleHandle(_T("kernel32.dll"));
		PFN_FINDAC pfnFindActCtxSectionString =NULL;
		ACTCTX_SECTION_KEYED_DATA askd = { sizeof(askd) };
		if (hKernel32 == NULL) 
		{
			/* unexpected condition, probably some strange loader lock situation */
			return TRUE;
		}

		pfnFindActCtxSectionString = (PFN_FINDAC) GetProcAddress(hKernel32, _FINDACTCTXSECTIONSTRING);

		if (pfnFindActCtxSectionString == NULL) 
		{
			/* pre-fusion OS, so no more checking. We shouldn't get to herem because we checked OS version earlier */
			return TRUE;
		}

		if (!(*pfnFindActCtxSectionString)(0, NULL, ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION, _ATL_DLL_FILENAME, &askd))
		{
			/* no activation context used to load ATL DLL, means no manifest present in the process */
			return FALSE;
		}
	}

	/* check condition (4) */
	if (winmajor >= 6)
	{
		return TRUE;
	}

	/* check condition (5) */
	{
		/* retrieves the windows folder */
		systemRootLen = GetSystemWindowsDirectory(systemRoot, _countof(systemRoot));
		if (systemRootLen == 0 || systemRootLen >= _countof(systemRoot))
		{
			/* error or path longer than MAX_PATH: we just let
			 * the user load the dll, without checking the manifest */
			return TRUE;
		}
		/* add a trailing backslash if not there already */
		if (systemRoot[systemRootLen - 1] != L'\\')
		{
			if (_TCSNCAT_S(systemRoot, _countof(systemRoot), _T("\\") _WINSXS_FOLDER, _TRUNCATE) != 0)
			{
				/* error or not enough space */
				return TRUE;
			}
		}
		else
		{
			if (_TCSNCAT_S(systemRoot, _countof(systemRoot), _WINSXS_FOLDER, _TRUNCATE) != 0)
			{
				/* error or not enough space */
				return TRUE;
			}
		}
		systemRootLen = _tcsnlen(systemRoot, _countof(systemRoot));

		size_t nRet = CompareString( LOCALE_INVARIANT, NORM_IGNORECASE, 
									 moduleFilePath, (DWORD)systemRootLen, 
									 systemRoot, (DWORD)systemRootLen);
		if( 0 == nRet )
		{
			/* error comparing the strings */
			return TRUE;
		}
		if( CSTR_EQUAL == nRet )
		{
			/* moduleFileName begins with %SYSTEMROOT%\WinSxS\ */
			return TRUE; /* dll has been loaded from the WinSxS cache */
		}
	}

	/* check condition (6) */
	{
		WIN32_FIND_DATA findData = { 0 };
		HANDLE hFind = INVALID_HANDLE_VALUE;

		if (_TCSNCAT_S(moduleFilePath, _countof(moduleFilePath), _MANIFEST_FILENAME, _TRUNCATE) != 0)
		{
			/* error or truncation */
			return TRUE;
		}

		hFind = FindFirstFile(moduleFilePath, &findData);
		if (hFind != INVALID_HANDLE_VALUE) 
		{
			FindClose(hFind);
			return TRUE; /* manifest is in the same folder as the dll */
		} 
		/* we could not find the manifest in the same folder as the dll */
		moduleFilePath[moduleFilePathLen] = 0;
		/* restore moduleFilePath so that it contains only the path of the module with final backslash */
	}

	/* case (7): loaded with another manifest */
	return FALSE;
}
#endif // WIN32_WCE

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

/*
STDAPI DllCanUnloadNow(void)
{
	return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	// registers object, typelib and all interfaces in typelib
	return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	//No need to unregister typelib since ATL is a system component.
	return S_OK;
}
*/

// No delay loading on WinCE
#ifndef _WIN32_WCE
#include <delayimp.h>

extern "C"
{
FARPROC
WINAPI
Downlevel_DelayLoadFailureHook(
	UINT unReason,
	PDelayLoadInfo pDelayInfo
	);

PfnDliHook __pfnDliFailureHook2 = Downlevel_DelayLoadFailureHook;

}

#endif // _WIN32_WCE

