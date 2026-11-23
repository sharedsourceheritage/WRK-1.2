// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"

__declspec(selectany) int __mixedModuleStartup;

#define new DEBUG_NEW

/////////////////////////////////////////////////////////////////////////////
// global data

#ifdef _AFX_DLLMODULE_HELPER

	// If building the MFC static libraries, define a function
	// that will ensure the availability of definitions for the 
	// functions called by the implementation of DllMain in dllmodul.cpp.
	// This function should never be called!!
	extern "C" void _AfxDllModulHelper(CWinApp** ppApp, CObject** ppObj)
	{
		*ppApp = AfxGetApp();

		*ppObj = new CDynLinkLibrary(NULL, NULL);
	}

#else // _AFX_DLLMODULE_HELPER

// The following symbol used to force inclusion of this module for _USRDLL
#if  defined(_M_IX86) || defined(_M_SH)
extern "C" { int _afxForceUSRDLL; }
#else
extern "C" { int __afxForceUSRDLL; }
#endif

#ifdef _AFXDLL

#ifndef _WIN32_WCE
#include <mfcassem.h>
#endif // !_WIN32_WCE

static AFX_EXTENSION_MODULE controlDLL;

// force initialization early
#pragma warning(disable: 4074)
#pragma init_seg(lib)

/////////////////////////////////////////////////////////////////////////////
// static-linked version of AfxWndProc for use by this module

LRESULT CALLBACK AfxWndProcDllStatic(HWND, UINT, WPARAM, LPARAM);

class _AFX_DLL_MODULE_STATE : public AFX_MODULE_STATE
{
public:
	_AFX_DLL_MODULE_STATE() : AFX_MODULE_STATE(TRUE, AfxWndProcDllStatic, _MFC_VER)
		{ }
};

static _AFX_DLL_MODULE_STATE afxModuleState;

#undef AfxWndProc
LRESULT CALLBACK
AfxWndProcDllStatic(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	AFX_MANAGE_STATE(&afxModuleState);
	return AfxWndProc(hWnd, nMsg, wParam, lParam);
}

AFX_MODULE_STATE* AFXAPI AfxGetStaticModuleState()
{
	AFX_MODULE_STATE* pModuleState = &afxModuleState;
	return pModuleState;
}

#else

AFX_MODULE_STATE* AFXAPI AfxGetStaticModuleState()
{
	AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
	return pModuleState;
}

#endif

/////////////////////////////////////////////////////////////////////////////
// export DllMain for the DLL

extern "C"
#ifndef _WIN32_WCE
BOOL WINAPI InternalDllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
#else
BOOL WINAPI InternalDllMain(HANDLE hHandle, DWORD dwReason, LPVOID)
{
	HINSTANCE hInstance = (HINSTANCE)hHandle;
#endif // !_WIN32_WCE

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		BOOL bResult = FALSE;

#ifdef _AFXDLL
		// wire up resources from core DLL
		AfxCoreInitModule();
#endif

		_AFX_THREAD_STATE* pState = AfxGetThreadState();
		AFX_MODULE_STATE* pPrevModState = pState->m_pPrevModuleState;

		// Initialize DLL's instance(/module) not the app's
		if (!AfxWinInit(hInstance, NULL, _T(""), 0))
		{
			AfxWinTerm();
			goto Cleanup;       // Init Failed
		}

		// initialize the single instance DLL
		CWinApp* pApp; pApp = AfxGetApp();
		if (pApp != NULL && !pApp->InitInstance())
		{
			pApp->ExitInstance();
			AfxWinTerm();
			goto Cleanup;       // Init Failed
		}

		pState->m_pPrevModuleState = pPrevModState;
#ifdef _AFXDLL
		// wire up this DLL into the resource chain
		VERIFY(AfxInitExtensionModule(controlDLL, hInstance));
		TRY
		{
			CDynLinkLibrary* pDLL; 
			pDLL = new CDynLinkLibrary(controlDLL);
		}
		CATCH(CMemoryException, e)
		{
			DELETE_EXCEPTION(e);
			pApp->ExitInstance();
			AfxWinTerm();
			goto Cleanup;       // Init Failed
		}
		END_CATCH
#else
		AfxInitLocalData(hInstance);
#endif

		bResult = TRUE;

Cleanup:
		pState->m_pPrevModuleState = pPrevModState;
#ifdef _AFXDLL
		// restore previously-saved module state
		VERIFY(AfxSetModuleState(AfxGetThreadState()->m_pPrevModuleState) ==
			&afxModuleState);
		DEBUG_ONLY(AfxGetThreadState()->m_pPrevModuleState = NULL);
#endif
		return bResult;
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
#ifdef _AFXDLL
		// set module state for cleanup
		ASSERT(AfxGetThreadState()->m_pPrevModuleState == NULL);
		AfxGetThreadState()->m_pPrevModuleState =
			AfxSetModuleState(&afxModuleState);
#endif

		CWinApp* pApp = AfxGetApp();
		if (pApp != NULL)
			pApp->ExitInstance();

#ifdef _DEBUG
		// check for missing AfxLockTempMap calls
		if (AfxGetModuleThreadState()->m_nTempMapLock != 0)
		{
			TRACE(traceAppMsg, 0, _T("Warning: Temp map lock count non-zero (%ld).\n"),
				AfxGetModuleThreadState()->m_nTempMapLock);
		}
#endif
		AfxLockTempMaps();
		AfxUnlockTempMaps(-1);

		// terminate the library before destructors are called
		AfxWinTerm();

#ifdef _AFXDLL
		AfxTermExtensionModule(controlDLL, TRUE);
#else
		AfxTermLocalData(hInstance, TRUE);
#endif
	}
	else if (dwReason == DLL_THREAD_DETACH)
	{
	    { //<--- Added braces to restrict scope of the following C++ object

#ifdef _AFXDLL
		AFX_MANAGE_STATE(&afxModuleState);
#endif

#ifdef _DEBUG
		// check for missing AfxLockTempMap calls
		if (AfxGetModuleThreadState()->m_nTempMapLock != 0)
		{
			TRACE(traceAppMsg, 0, _T("Warning: Temp map lock count non-zero (%ld).\n"),
				AfxGetModuleThreadState()->m_nTempMapLock);
		}
#endif
		AfxLockTempMaps();
		AfxUnlockTempMaps(-1);
	    }
		AfxTermThread(hInstance);
	}

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// initialize app state such that it points to this module's core state

#ifndef _WIN32_WCE
extern "C" BOOL WINAPI RawDllMain(HINSTANCE, DWORD dwReason, LPVOID);
#else
extern "C" BOOL WINAPI RawDllMain(HANDLE, DWORD dwReason, LPVOID);
#endif // !_WIN32_WCE

#ifndef _WIN32_WCE
extern "C" BOOL (WINAPI * const _pActualRawDllMain)(HINSTANCE , DWORD , LPVOID) = &RawDllMain;
#else
__declspec(selectany) BOOL (WINAPI * _pAtlRawDllMain)(HANDLE , DWORD , LPVOID) = &RawDllMain;
#endif // !_WIN32_WCE

extern "C"
#ifndef _WIN32_WCE
BOOL WINAPI RawDllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID)
{
	hInstance;
#else
BOOL WINAPI RawDllMain(HANDLE hHandle, DWORD dwReason, LPVOID)
{
	HINSTANCE hInstance = reinterpret_cast<HINSTANCE>(hHandle);
#endif // !_WIN32_WCE

	if (dwReason == DLL_PROCESS_ATTACH)
	{
#ifdef _AFXDLL
		// make sure we have enough memory to attempt to start (8kb)
		void* pMinHeap = LocalAlloc(NONZEROLPTR, 0x2000);
		if (pMinHeap == NULL)
			return FALSE;   // fail if memory alloc fails
		LocalFree(pMinHeap);

		// set module state before initialization
		_AFX_THREAD_STATE* pState = AfxGetThreadState();
		pState->m_pPrevModuleState = AfxSetModuleState(&afxModuleState);
	}
	else if (dwReason == DLL_PROCESS_DETACH && !__mixedModuleStartup)
	{
		// restore module state after cleanup
		_AFX_THREAD_STATE* pState = AfxGetThreadState();
		VERIFY(AfxSetModuleState(pState->m_pPrevModuleState) ==
			&afxModuleState);
		DEBUG_ONLY(pState->m_pPrevModuleState = NULL);

#endif //_AFXDLL
	}
	return TRUE;
}


extern "C"
#ifndef _WIN32_WCE
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
#else
BOOL WINAPI DllMain(HANDLE hHandle, DWORD dwReason, LPVOID lpReserved)
{
	HINSTANCE hInstance = (HINSTANCE)hHandle;
#endif // !_WIN32_WCE
	if (__mixedModuleStartup)
	{
		// Skip initialization in mixed mode (done in PostDllMain, see afxdisp.h)
		if (dwReason == DLL_PROCESS_ATTACH)
		{
			// save the module instance
			AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
			pModuleState->m_hCurrentInstanceHandle = hInstance;
#ifdef _AFXDLL
			// restore previously-saved module state
			VERIFY(AfxSetModuleState(AfxGetThreadState()->m_pPrevModuleState) ==
				&afxModuleState);
			DEBUG_ONLY(AfxGetThreadState()->m_pPrevModuleState = NULL);
#endif
			return TRUE;
		}
		else if (dwReason == DLL_PROCESS_DETACH)
		{
			return TRUE;
		}
		else
		{
			return InternalDllMain(hInstance, dwReason, lpReserved);
		}
	}
	else
	{
		return InternalDllMain(hInstance, dwReason, lpReserved);
	}
}

/////////////////////////////////////////////////////////////////////////////
// Special case for static library startup/termination

#ifndef _AFXDLL

// force initialization early
#pragma warning(disable: 4074)
#pragma init_seg(lib)

void AFX_CDECL AfxTermDllState()
{
	// terminate local data and critical sections
	AfxTermLocalData(NULL, TRUE);
	AfxCriticalTerm();

	// release the reference to thread local storage data
	AfxTlsRelease();
}

char _afxTermDllState = (char)(AfxTlsAddRef(), atexit(&AfxTermDllState));

#endif // !_AFXDLL

/////////////////////////////////////////////////////////////////////////////

#endif // !_AFX_DLLMODULE_HELPER
