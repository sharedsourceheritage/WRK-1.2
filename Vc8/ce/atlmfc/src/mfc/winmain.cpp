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
#include "sal.h"


/////////////////////////////////////////////////////////////////////////////
// Standard WinMain implementation
//  Can be replaced as long as 'AfxWinInit' is called first

#ifdef _WIN32_WCE
typedef struct ModuleInfo
{
	wchar_t *pszModuleFileName;
	HWND hwnd;
} 
MODULEINFO, *PMODULEINFO;

BOOL CALLBACK _AfxFindModuleInfoProc(HWND hwnd, LPARAM lParam)
{
	DWORD		dwProcessID;
	PMODULEINFO	pModuleInfo = (PMODULEINFO)lParam;

	::GetWindowThreadProcessId(hwnd, &dwProcessID);
	if (!dwProcessID) 
	{
		return TRUE;
	}

	wchar_t szModuleFileName[MAX_PATH];
	if (!::GetModuleFileName((HMODULE)dwProcessID, szModuleFileName, MAX_PATH)) 
	{
		return TRUE;
	}

	if (!::wcsicmp(szModuleFileName, pModuleInfo->pszModuleFileName))
	{	
		pModuleInfo->hwnd = hwnd;		
		return FALSE;
	}

	return TRUE;
}
#endif // _WIN32_WCE

int AFXAPI AfxWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	__in LPTSTR lpCmdLine, int nCmdShow)
{
	ASSERT(hPrevInstance == NULL);

	int nReturnCode = -1;
	CWinThread* pThread = AfxGetThread();
	CWinApp* pApp = AfxGetApp();

	// AFX internal initialization
	if (!AfxWinInit(hInstance, hPrevInstance, lpCmdLine, nCmdShow))
		goto InitFailure;

	// App global initializations (rare)
	if (pApp != NULL && !pApp->InitApplication())
		goto InitFailure;

#ifdef _WIN32_WCE
	int aygshellUIModel = AfxGetAygshellUIModel();
	if (aygshellUIModel == PocketPC || aygshellUIModel == Smartphone)
	{
		// only one application instance can be run
		wchar_t szTempFileName[MAX_PATH], szModuleFileName[MAX_PATH];
	
		int nFileNameLen = ::GetModuleFileName(NULL, szModuleFileName, MAX_PATH);			
		int idxTempFileName = 0;
		for (int idxModuleFileName = 0; idxModuleFileName < nFileNameLen; idxModuleFileName++) 
		{
			if (szModuleFileName[idxModuleFileName] == L'\\') 
			{
				szTempFileName[idxTempFileName++] = L'/';
			}
			else
			{
				szTempFileName[idxTempFileName++] = szModuleFileName[idxModuleFileName];
			}
		}
		szTempFileName[idxTempFileName] = L'\0';

		HANDLE hMutex = ::CreateMutex(NULL, FALSE, szTempFileName);
		if (hMutex != NULL)
		{
			if (::GetLastError() == ERROR_ALREADY_EXISTS) 
			{
				BOOL bGoAway = FALSE;
				
				MODULEINFO moduleInfo;
				ZeroMemory(&moduleInfo, sizeof(MODULEINFO));
				moduleInfo.pszModuleFileName = szModuleFileName;

				int nThreadPriority = pThread->GetThreadPriority();

				// Retry for 10 seconds (40 * 250 millisecons = 10000 milliseconds)
				for (int i = 0; i < 40; ++i) 
				{
					::EnumWindows(_AfxFindModuleInfoProc, (LPARAM)&moduleInfo);

					if (moduleInfo.hwnd) 
					{
						::SetForegroundWindow((HWND)(((DWORD)moduleInfo.hwnd) | 0x00000001));		
						bGoAway = TRUE;
						break;
					}
					// wait for other app to finish starting or stopping
					pThread->SetThreadPriority(THREAD_PRIORITY_IDLE);
					Sleep(250); // sleep for one quarter second (arbitrary)
					pThread->SetThreadPriority(nThreadPriority);
				}
				
				if (bGoAway) 
				{
					::ReleaseMutex(hMutex);
					goto InitFailure;
				}
			}
			::ReleaseMutex(hMutex);
		}
	}
#endif

	// Perform specific initializations
	if (!pThread->InitInstance())
	{
		if (pThread->m_pMainWnd != NULL)
		{
			TRACE(traceAppMsg, 0, _T("Warning: Destroying non-NULL m_pMainWnd\n"));
			pThread->m_pMainWnd->DestroyWindow();
		}
		nReturnCode = pThread->ExitInstance();
		goto InitFailure;
	}
	nReturnCode = pThread->Run();

InitFailure:
#ifdef _DEBUG
	// Check for missing AfxLockTempMap calls
	if (AfxGetModuleThreadState()->m_nTempMapLock != 0)
	{
		TRACE(traceAppMsg, 0, _T("Warning: Temp map lock count non-zero (%ld).\n"),
			AfxGetModuleThreadState()->m_nTempMapLock);
	}
	AfxLockTempMaps();
	AfxUnlockTempMaps(-1);
#endif

	AfxWinTerm();
	return nReturnCode;
}

/////////////////////////////////////////////////////////////////////////////
