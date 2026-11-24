//-----------------------------------------------------------
// Microsoft Visual Basic
//
// Copyrigtht (c) 1994-2000 Microsoft Corp.
// All Rights Reserved
//
// procutil.cpp:  utilities to do stuff with processes
//
// NOTE: All functions here are mbcs/unicode compliant.
//       Do NOT add non mbcs/unicdoe compliant functions!
//-----------------------------------------------------------

#include "hu_pch.h"
#include "hu_util.h"
#include "procutil.h"
#include "lutil.h"

static HANDLE RunProcess_CreateTempFile();

HRESULT RunProcess(LPCTSTR pszExec, LPTSTR pszCommandLineArgs, LPCTSTR pszInitialDirectory,
                   DWORD dwTimeout, DWORD dwFlags, DWORD* pdwExitCode, HANDLE* phStdOut, HANDLE* phStdErr)
{
    // Runs a process and optionally returns handles to files containing its
    // standard output and standard error.  
    //
    // pszExec              = name of the executable to be run
    // pszCommandLineArgs   = command line arguments
    // pszInitialDirectory  = directory in which the process will run; can be NULL to
    //                        specify the same directory as the parent process
    // dwTimeout            = timeout for the process, can be INFINITE
    // dwFlags              = flags to control the operation of this function.  See
    //                        the header file for details.
    // pdwExitCode          = optional, receives the exit code of the process.  Can
    //                        be NULL.
    // phStdOut             = optional pointer to a handle that will receive
    //                        a handle to the file containing the standard output
    //                        of the process.  Can be NULL.  
    // phStdErr             = same as phStdOut, except applies to standard error.
    
    // Local handles for standard error/standard output
    HANDLE hErr = INVALID_HANDLE_VALUE;
    HANDLE hOut = INVALID_HANDLE_VALUE;

    // Process creation stuff
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // Local variables needed in the function
    BOOL bSuccess, bCreateStdOut, bCreateStdErr;
    HRESULT hr = S_OK;
    DWORD dwResult;

    // Check for validity of arguments
    if ((dwFlags & RUNPROC_CAPTURE_STDOUT) && !phStdOut)
        return E_INVALIDARG;
    if ((dwFlags & RUNPROC_CAPTURE_STDERR) && !phStdErr)
        return E_INVALIDARG;
    if ((dwFlags & RUNPROC_CAPTURE_EXIT_CODE) && !pdwExitCode)
        return E_INVALIDARG;
    
    // Initialize output parameters
    if (dwFlags & RUNPROC_CAPTURE_EXIT_CODE)
        *pdwExitCode = 0;

    // Do the handles need to be created?
    bCreateStdOut = (!(dwFlags & RUNPROC_USE_PASSED_HANDLES) && (dwFlags & RUNPROC_CAPTURE_STDOUT));
    bCreateStdErr = (!(dwFlags & RUNPROC_USE_PASSED_HANDLES) && (dwFlags & RUNPROC_CAPTURE_STDERR));

    if (bCreateStdOut)
    {
        hOut = RunProcess_CreateTempFile();
        if (hOut == INVALID_HANDLE_VALUE)
        {
            hr = LUtilSetWin32Err();
            goto ERROR_EXIT;
        }
    }

    if (bCreateStdErr)
    {
        hErr = RunProcess_CreateTempFile();
        if (hErr == INVALID_HANDLE_VALUE)
        {
            hr = LUtilSetWin32Err();
            goto ERROR_EXIT;
        }
    }

    // Setup the handles in the startup info structure
    ZeroMemory((PVOID) &si, sizeof(STARTUPINFO));
    si.cb = sizeof(si);
    if (bCreateStdOut)
    {
        si.hStdOutput = hOut;
        si.dwFlags = STARTF_USESTDHANDLES;
    }
    if (bCreateStdErr)
    {
        si.hStdError = hErr;
        si.dwFlags = STARTF_USESTDHANDLES;
    }

    // Hide the window of the called process, if necessary
    if (dwFlags & RUNPROC_HIDE_WINDOW)
    {
        si.dwFlags |= STARTF_USESHOWWINDOW;
        si.wShowWindow = SW_HIDE;
    }
   
    // Start up the desired process!
    bSuccess = CreateProcess(pszExec, pszCommandLineArgs,    
                             NULL, NULL,                      // Proc & thread security attribs
                             bCreateStdErr || bCreateStdOut, 
                             0,                               // No special creation flags
                             NULL,                            // Inherit environment strings
                             pszInitialDirectory,             // Default current working directory
                             &si, &pi);
    if (!bSuccess)
    {
        hr = LUtilSetWin32Err();
        goto ERROR_EXIT;
    }

    // We don't do anything special with the process' thread, so close the handle
    // to avoid resource leaks.
    CloseHandle(pi.hThread);

    // And now wait for the process to complete.  
    dwResult = WaitForSingleObject(pi.hProcess, dwTimeout);
    if (dwResult == WAIT_TIMEOUT || dwResult == WAIT_ABANDONED)
    {
        hr = E_FAIL;
        goto ERROR_EXIT;
    }

    // Get the exit code if we're interested
    if (dwFlags & RUNPROC_CAPTURE_EXIT_CODE)
        GetExitCodeProcess(pi.hProcess, pdwExitCode);

    CloseHandle(pi.hProcess);

ERROR_EXIT:

    if (FAILED(hr))
    {
        // Bailing out, need to cleanup handles
        if (hOut != INVALID_HANDLE_VALUE)
            CloseHandle(hOut);

        if (hErr != INVALID_HANDLE_VALUE)
            CloseHandle(hErr);

        if (bCreateStdOut)
            *phStdOut = INVALID_HANDLE_VALUE;

        if (bCreateStdErr)
            *phStdErr = INVALID_HANDLE_VALUE;
    }
    else
    {
        // Success.  Populate output arguments.  Note that we do 
        // not need to populate the process exit code because it has
        // already been populated above.  
        if (bCreateStdOut)
        {
            FlushFileBuffers(hOut);
            *phStdOut = hOut;
        }

        if (bCreateStdErr)
        {
            FlushFileBuffers(hErr);
            *phStdErr = hErr;
        }
    }

    return hr;
}

HANDLE RunProcess_CreateTempFile()
{
    // Creates an inheritable handle to a temporary file on disk.

    TCHAR pszTempPath[_MAX_PATH + 1];
    TCHAR pszTempFileName[_MAX_PATH + 1];

    // Initialize the security attributes structure so that all handles created
    // by us are inheritable.
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;

    // Get a temporary file in the temp directory
    DWORD rv = GetTempPath(_MAX_PATH + 1, pszTempPath);
    if (rv == 0 || rv > _MAX_PATH)
        return INVALID_HANDLE_VALUE;
    if (GetTempFileName(pszTempPath, _T("VST"), 0, pszTempFileName) == 0)
        return INVALID_HANDLE_VALUE;

    return CreateFile(pszTempFileName,                      // file name
                      GENERIC_READ | GENERIC_WRITE,         // file access
                      FILE_SHARE_READ,
                      &sa,                                  // security attribs
                      CREATE_ALWAYS,                        // overwrite
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
}
    
