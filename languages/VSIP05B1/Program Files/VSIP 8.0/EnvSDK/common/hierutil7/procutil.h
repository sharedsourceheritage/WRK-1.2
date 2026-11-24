//--------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (c) 2000 Microsoft Corporation Inc.
// All rights reserved
//
// procutil.h : some functions to help out with running processes
// 
// NOTE: All functions here are mbcs/unicode compliant.
//       Do NOT add non mbcs/unicode compliant functions!
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif
#ifndef __PROCUTIL_H__
#define __PROCUTIL_H__

#define RUNPROC_HIDE_WINDOW             1
#define RUNPROC_CAPTURE_STDOUT          2
#define RUNPROC_CAPTURE_STDERR          4
#define RUNPROC_USE_PASSED_HANDLES      8
#define RUNPROC_CAPTURE_EXIT_CODE       16

#define RUNPROC_DEFAULT                 RUNPROC_HIDE_WINDOW | \
                                        RUNPROC_CAPTURE_STDOUT | \
                                        RUNPROC_CAPTURE_STDERR | \
                                        RUNPROC_USE_PASSED_HANDLES | \
                                        RUNPROC_CAPTURE_EXIT_CODE

#define ASSERTWritePtr(ptr) ASSERT(ptr && !IsBadWritePtr(ptr, sizeof(*ptr)))
#define VERIFYWritePtr(ptr) ASSERTWritePtr(ptr); if (!ptr || IsBadWritePtr(ptr, sizeof(*ptr))) return E_INVALIDARG

#define UnicodeToAnsi(szA, szW) WideCharToMultiByte( CP_ACP, 0, szW, -1, szA, lstrlen(szW) + 1, NULL, NULL )
#define AnsiToUnicode(szW, szA) MultiByteToWideChar( CP_ACP, 0, szA, -1, szW, strlen(szA) + 1 )

// Creates a process and captures its standard output and error to files
HRESULT RunProcess(/* in */ LPCTSTR pszExecutable, 
                   /* in */ LPTSTR pszCommandLineArgs, 
                   /* in */ LPCTSTR pszInitialDirectory,
                   /* in */ DWORD dwTimeout, 
                   /* in */ DWORD dwFlags,
                   /* out */ DWORD* pdwExitCode, 
                   /* in/out */ HANDLE* phStdOut, 
                   /* in/out */ HANDLE* phStdErr);

#endif          // __PROCUTIL_H__
// End of lutils.h
