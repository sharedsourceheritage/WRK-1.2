//Copyright (C) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.

/* To prevent VisualStudio from refusing to load your provider as you
develop it and add capabilities, you must set the following registry keys.

The "WarnedOldMSSCCIProvider" key will decrement each time you restart
Visual Studio, so you may need to reset the value to 500 after you have
restarted Visual Studio 500 times.

    [HKEY_CURRENT_USER\Software\Microsoft\VisualStudio\8.0\SourceControl]
    "WarnedOldMSSCCIProvider"=dword:00000500
    "UseOldSCC"=dword:00000001
    "DontDisplayCheckDotNETCompatible"=dword:00000000

To load your MSSCCI provider in Visual Studio, you must set the following
registry key. Update the "SCCServerPath" to the path to your dll.

    [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\SourceSafe]
    "SCCServerName"="MSSCCI Sample"
    "SCCServerPath"="C:\\sample\\debug\\samplemsscci.dll"

NOTE: End-users of the MSSCCI provider you are creating may already
have an existing MSSCCI provider installed. The installation program for
the MSSCCI provider you create should check to see if there are already
values for these retistry keys. If these keys are already set, your installation
program should ask the end-user whether or not to register your provider
as the primary provider and take the place of the already installed one.
*/

// SampleMSSCCI.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "SampleMSSCCI.h"
#include "scc.h"


bool fInitialized = false;

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
    return TRUE;
}

SCCEXTERNC LONG EXTFUN SccGetVersion(void)
{
	if (!fInitialized)
	{
		CoInitialize(0);
		fInitialized = true;
	}

	MessageBoxW(HWND_DESKTOP, L"Hello world", L"Sample MSSCCI Provider", MB_OK);

	return SCC_VER_NUM;
}

SCCEXTERNC SCCRTN EXTFUN SccInitialize(
	LPVOID * ppContext, 
	HWND hWnd, 
	LPCSTR lpCallerName,
	LPSTR lpSccName, 
	LPLONG lpSccCaps, 
	LPSTR lpAuxPathLabel, 
	LPLONG pnCheckoutCommentLen, 
	LPLONG pnCommentLen
	)
{
	if (!fInitialized)
	{
		CoInitialize(0);
		fInitialized = true;
	}

	return SCC_OK;
}


SCCEXTERNC SCCRTN EXTFUN SccUninitialize(
	LPVOID pContext
	)
{
	if (fInitialized)
	{
		CoUninitialize();
	}

	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccOpenProject(
	LPVOID pContext,
	HWND hWnd, 
	LPSTR lpUser,
	LPSTR lpProjName,
	LPCSTR lpLocalProjPath,
	LPSTR lpAuxProjPath,
	LPCSTR lpComment,
	LPTEXTOUTPROC lpTextOutProc,
	LONG dwFlags
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccCloseProject(
	LPVOID pContext
	)
{
	return SCC_OK;
}


SCCEXTERNC SCCRTN EXTFUN SccCheckout(
	LPVOID pContext, 
	HWND hWnd, 
	LONG nFiles, 
	LPCSTR* lpFileNames, 
	LPCSTR lpComment, 
	LONG dwFlags,
	LPCMDOPTS pvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccUncheckout(
	LPVOID pContext, 
	HWND hWnd, 
	LONG nFiles, 
	LPCSTR* lpFileNames, 
	LONG dwFlags,
	LPCMDOPTS pvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccCheckin(
	LPVOID pContext, 
	HWND hWnd, 
	LONG nFiles, 
	LPCSTR* lpFileNames, 
	LPCSTR lpComment, 
	LONG dwFlags,
	LPCMDOPTS pvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccAdd(
	LPVOID pContext, 
	HWND hWnd, 
	LONG nFiles, 
	LPCSTR* lpFileNames, 
	LPCSTR lpComment, 
	LONG * pdwFlags,
	LPCMDOPTS pvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccRemove(
	LPVOID pContext, 
	HWND hWnd, 
	LONG nFiles, 
	LPCSTR* lpFileNames, 
	LPCSTR lpComment,
	LONG dwFlags,
	LPCMDOPTS pvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccGet(
	LPVOID pContext, 
	HWND hWnd, 
	LONG nFiles, 
	LPCSTR* lpFileNames, 
	LONG dwFlags,
	LPCMDOPTS pvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccDiff(
	LPVOID pContext, 
	HWND hWnd, 
	LPCSTR lpFileName, 
	LONG dwFlags,
	LPCMDOPTS pvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccDirDiff(
	LPVOID pContext, 
	HWND hWnd, 
	LPCSTR lpDirName, 
	LONG dwFlags,
	LPCMDOPTS pvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccHistory(
	LPVOID pContext, 
	HWND hWnd, 
	LONG nFiles, 
	LPCSTR* lpFileNames, 
	LONG dwFlags,
	LPCMDOPTS pvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccQueryInfo(
	LPVOID pContext, 
	LONG nFiles, 
	LPCSTR* lpFileNames, 
	LPLONG lpStatus 
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccDirQueryInfo(
	LPVOID pContext, 
	LONG nDirs, 
	LPCSTR* lpDirNames, 
	LPLONG lpStatus 
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccGetEvents(
	LPVOID pContext, 
	LPSTR lpFileName,
	LPLONG lpStatus,
	LPLONG pnEventsRemaining
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccRunScc(
	LPVOID pContext, 
	HWND hWnd, 
	LONG nFiles, 
	LPCSTR* lpFileNames
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccGetProjPath(
	LPVOID pContext, 
	HWND hWnd, 
	LPSTR lpUser,
	LPSTR lpProjName, 
	LPSTR lpLocalProjPath,
	LPSTR lpAuxProjPath,
	BOOL bAllowChangePath,
	LPBOOL pbNew
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccGetCommandOptions(
	LPVOID pContext, 
	HWND hWnd, 
	SCCCOMMAND nCommand,
	LPCMDOPTS * ppvOptions
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN
SccBeginBatch
(
	void
)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN
SccEndBatch
(
	void
)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccRename(
	LPVOID pContext, 
	HWND hWnd, 
	LPCSTR lpFileName,
	LPCSTR lpNewName
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccAddFromScc(
	LPVOID pContext, 
	HWND hWnd, 
	LPLONG pnFiles,
	LPCSTR** lplpFileNames
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccProperties(
	LPVOID pContext, 
	HWND hWnd, 
	LPCSTR lpFileName
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccPopulateList(
	LPVOID pContext, 
	SCCCOMMAND nCommand, 
	LONG nFiles, 
	LPCSTR* lpFileNames, 
	POPLISTFUNC pfnPopulate, 
	LPVOID pvCallerData,
	LPLONG lpStatus, 
	LONG dwFlags
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccSetOption(
	LPVOID pContext,
	LONG nOption,
	LONG dwVal
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccCreateSubProject(
	LPVOID pContext, 
    HWND hWnd, 
    LPSTR lpUser,
    LPCSTR lpParentProjPath, 
    LPCSTR lpSubProjName,
    LPSTR lpAuxProjPath,
    LPSTR lpSubProjPath
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN EXTFUN SccGetParentProjectPath(
	LPVOID pContext, 
    HWND hWnd, 
    LPSTR lpUser,
    LPCSTR lpProjPath, 
    LPSTR lpAuxProjPath,
    LPSTR lpParentProjPath
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN SccIsMultiCheckoutEnabled(
	LPVOID pContext,
	LPBOOL pbMultiCheckout
	)
{
	return SCC_OK;
}

SCCEXTERNC SCCRTN SccWillCreateSccFile(
	LPVOID pContext,
	LONG nFiles,
	LPCSTR* lpFileNames,
	LPBOOL pbSccFiles
	)
{
	return SCC_OK;
}

