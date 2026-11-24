
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// CmdExec.cpp
//
// Implementation of CCommandExecuter
// 
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "CmdExec.h"

//*****************************************************************************
// CCommandExecuter Constructor/Destructor
//*****************************************************************************

CCommandExecuter::CCommandExecuter()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCommandExecuter \n") );

    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Creating CCommandExecuter: 0x%X\n"), this);
    }
}

CCommandExecuter::~CCommandExecuter()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::~CCommandExecuter \n") );

    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Destructing CCommandExecuter: 0x%X\n"), this);
    }
}


//*****************************************************************************
// CCommandExecuter ICommandExecuter Implementation
//*****************************************************************************

STDMETHODIMP CCommandExecuter::ExecuteCommand(
                    /*[in]*/ LPCOLESTR lpszCommand,
                    /*[in]*/ LPCOLESTR lpszArguments,
                    /*[in]*/ LPCOLESTR lpszWorkingDir,
                    /*[in]*/ DWORD     dwFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::ExecuteCommand \n") );

    ExpectedPtrRet(lpszCommand);
    ExpectedPtrRet(lpszArguments);

    HRESULT hr;

    if (dwFlags & CMF_UseOutput)
    {
        hr = ExecuteOutputCommand(lpszCommand, lpszArguments, lpszWorkingDir,
                                  dwFlags);
    }
    else
    {
        hr = ExecuteShellCommand(lpszCommand, lpszArguments, lpszWorkingDir);
    }

    _ASSERTE_MSG(SUCCEEDED(hr), "Failed to execute command");

    return hr;
}


//*****************************************************************************
// CCommandExecuter Implementation
//*****************************************************************************

HRESULT CCommandExecuter::ExecuteComSpecCommand(LPCOLESTR lpszCommand,
                                                LPCOLESTR lpszArguments,
                                                LPCOLESTR lpszWorkingDir,
                                                DWORD dwFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::ExecuteComSpecCommand \n") );

    CString strCommand;
    CString strArguments;
    TCHAR szComSpec[_MAX_PATH];
    HRESULT hr;

    USES_CONVERSION;

    // use the command shell
    hr = GetEnvironmentVariable(_T("ComSpec"), szComSpec, _MAX_PATH);
    ExpectedExprGo(hr != 0);

    strCommand = szComSpec;
    strArguments.Format(_T("/C \"%s\" %s"), W2CT(lpszCommand), W2CT(lpszArguments));

    {
        // set up the output window and execute the command

        CComPtr<IVsOutputWindowPane> srpOutputPane;
        CComPtr<IVsOutputWindow> srpOutput;
        CComPtr<IVsWindowFrame> srpOutputFrame;
        CComPtr<IVsLaunchPad> srpLaunchPad;
        IVsUIShell* pUIShell = NULL;
        LAUNCHPAD_FLAGS launchFlags = 0;

        hr = _VxModule.QueryService(SID_SVsOutputWindow, IID_IVsOutputWindow,
                                  (void**)&srpOutput);
        IfFailGoMsg(hr, "Failed to get SID_SVsOutputWindow");

        hr = srpOutput->GetPane(guidFileSysOutputWindow, &srpOutputPane);
        IfFailGo(hr);

        launchFlags |= LPF_PipeStdoutToOutputWindow;
        if (dwFlags & CMF_ClearOutput)
            launchFlags |= LPF_ClearOutputWindow;

        pUIShell = _VxModule.GetVsUIShell();      // un-addref'd
        _ASSERTE(pUIShell);

        hr = pUIShell->FindToolWindow(0, GUID_OutputWindow, &srpOutputFrame);
        if (SUCCEEDED(hr))
        {
            srpOutputFrame->Show();
        }

        hr = _VxModule.QueryService(SID_SVsLaunchPad, IID_IVsLaunchPad,
                                  (void**)&srpLaunchPad);
        IfFailGoMsg(hr, "Failed to get SID_SVsLaunchPad");

        hr = srpLaunchPad->ExecCommand(T2CW((LPCTSTR)strCommand), T2CW((LPCTSTR)strArguments),
                                       (lpszWorkingDir ? lpszWorkingDir : NULL),
                                       launchFlags,
                                       srpOutputPane,
                                       0, 0, NULL,
                                       NULL, NULL, NULL);
    }

OnError:
    return hr;
}

HRESULT CCommandExecuter::ExecuteOutputCommand(LPCOLESTR lpszCommand,
                                               LPCOLESTR lpszArguments,
                                               LPCOLESTR lpszWorkingDir,
                                               DWORD dwFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::ExecuteOutputCommand \n") );

    // set up the output window and execute the command

    CComPtr<IVsOutputWindowPane> srpOutputPane;
    CComPtr<IVsOutputWindow> srpOutput;
    CComPtr<IVsWindowFrame> srpOutputFrame;
    IVsUIShell* pUIShell = NULL;

    CString strArguments;

    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    CCmdOutputReaderPipe* pPipe = NULL;
    HANDLE hReadPipe = NULL;
    HANDLE hWritePipe = NULL;
    BOOL fResult = FALSE;

    HRESULT hr;

    hr = _VxModule.QueryService(SID_SVsOutputWindow, IID_IVsOutputWindow,
                              (void**)&srpOutput);
    IfFailGoMsg(hr, "Failed to get SID_SVsOutputWindow");

    hr = srpOutput->GetPane(guidFileSysOutputWindow, &srpOutputPane);
    IfFailGo(hr);

    if (dwFlags & CMF_ClearOutput)
        srpOutputPane->Clear();

    pUIShell = _VxModule.GetVsUIShell();      // un-addref'd
    _ASSERTE(pUIShell);
    ExpectedExprGo(pUIShell != NULL);

    hr = pUIShell->FindToolWindow(0, GUID_OutputWindow, &srpOutputFrame);
    if (SUCCEEDED(hr))
    {
        srpOutputFrame->Show();
    }

    pPipe = new CCmdOutputReaderPipe();
    IfFailAllocGo(pPipe);
    if (!pPipe->CreatePipe(&hReadPipe, &hWritePipe))
    {
        delete pPipe;
        hr = GetLastError();
        goto OnError;
    }

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_SHOWNORMAL;
    si.hStdOutput = hWritePipe;
    si.hStdError = hWritePipe;

    strArguments = lpszArguments;
    fResult = CreateProcess(lpszCommand, strArguments.LockBuffer(), NULL, NULL,
                            TRUE, 0, NULL, W2CT(lpszWorkingDir),
                            &si, &pi);
    strArguments.UnlockBuffer();

    if (fResult)
    {
        pPipe->Start(hReadPipe, pi.hProcess,
                     (dwFlags & CMF_ClearOutput), srpOutputPane);
        hr = S_OK;
    }
    else
    {
        delete pPipe;

        // could be a command shell command
        hr = ExecuteComSpecCommand(lpszCommand, lpszArguments,
                                   lpszWorkingDir, dwFlags);
    }

OnError:
    return hr;
}

HRESULT CCommandExecuter::ExecuteShellCommand(LPCOLESTR lpszCommand,
                                              LPCOLESTR lpszArguments,
                                              LPCOLESTR lpszWorkingDir)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::ExecuteShellCommand \n") );

    _ASSERTE(lpszCommand);
    _ASSERTE(lpszArguments);
	if (!lpszCommand)
		return E_POINTER;
	if (!lpszArguments)
		return E_POINTER;

    USES_CONVERSION;

    CString strCommand;
    CString strArguments;

    TCHAR* szCommand = W2T((LPOLESTR)lpszCommand);
    TCHAR* szStartCommand = szCommand;
    TCHAR* szEndCommand = NULL;

    if (szCommand[0] == _T('"'))
    {
        szStartCommand++;
        szEndCommand = _tcschr(szStartCommand, _T('"'));
    }
    else
    {
        szEndCommand = _tcschr(szStartCommand, _T(' '));
    }

    if (szEndCommand)
    {
        TCHAR chTemp = *szEndCommand;

        *szEndCommand = _T('\0');
        strCommand = szStartCommand;
        strArguments = szEndCommand + 1;
        *szEndCommand = chTemp;

        if (lpszArguments)
        {
            strArguments += _T(" ");
            strArguments += W2CT(lpszArguments);
        }
    }
    else
    {
        strCommand = szStartCommand;
        strArguments = W2CT(lpszArguments);
    }

    strCommand = '"' + szStartCommand + '"';
    ShellExecute(NULL, _T("open"), strCommand, strArguments, (lpszWorkingDir ? W2CT(lpszWorkingDir) : _T("")), SW_SHOWNORMAL);
    return S_OK;
}



//*****************************************************************************
// CCmdOutputReaderPipe Implementation
//*****************************************************************************

SECURITY_ATTRIBUTES CCommandExecuter::CCmdOutputReaderPipe::s_sa =
    { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };

#define READBUFFERSIZE      1024
#define SLEEPTIME           50


CCommandExecuter::CCmdOutputReaderPipe::CCmdOutputReaderPipe()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::CCmdOutputReaderPipe \n") );

    m_hReadPipe = NULL;
    m_hThread = NULL;
    m_hThreadExitEvent = NULL;

    m_hProcess = NULL;
    m_hMonitorThread = NULL;
}

CCommandExecuter::CCmdOutputReaderPipe::~CCmdOutputReaderPipe()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::~CCmdOutputReaderPipe \n") );

    Stop();
    CloseHandle(m_hProcess);
    CloseHandle(m_hThread);
    CloseHandle(m_hMonitorThread);
}

BOOL CCommandExecuter::CCmdOutputReaderPipe::CreatePipe(HANDLE* phReadPipe,
                                                        HANDLE* phWritePipe)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::CreatePipe \n") );

    return ::CreatePipe(phReadPipe, phWritePipe, &s_sa, READBUFFERSIZE);
}

HRESULT CCommandExecuter::CCmdOutputReaderPipe::Start(HANDLE hReadPipe, HANDLE hProcess,
                                                      BOOL fClearOutput,
                                                      IVsOutputWindowPane* pOutputPane)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::Start \n") );

    _ASSERTE(hReadPipe);
    _ASSERTE(hProcess);
    _ASSERTE(pOutputPane);
    _ASSERTE(!m_hThread);

	if (!hReadPipe)
		return E_FAIL;

	if (!hProcess)
		return E_FAIL;

	if (!pOutputPane)
		return E_FAIL;

	DWORD dwThreadID;
    HRESULT hr = S_OK;

    m_hReadPipe = hReadPipe;
    m_hProcess = hProcess;
    m_srpOutputPane = pOutputPane;

    m_hThreadExitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    m_fThreadDie = FALSE;

    ExpectedPtrGo(m_hThreadExitEvent);

    // Thread to pipe output into output window
    m_hThread = CreateThread(NULL, 0, PipeReadThreadStart, this, 0, &dwThreadID);
    ExpectedPtrGo(m_hThread);

    // Thread that watches the executable
    m_hMonitorThread = CreateThread(NULL, 0, ProcessMonitorThreadStart, this, 0, &dwThreadID);
    ExpectedPtrGo(m_hMonitorThread);

    if (fClearOutput)
        m_srpOutputPane->Clear();
    m_srpOutputPane->Activate();

OnError:
    return hr;
}

void CCommandExecuter::CCmdOutputReaderPipe::Stop()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::Stop \n") );

    if (m_hThread)
    {
        m_fThreadDie = TRUE;
        WaitForSingleObject(m_hThreadExitEvent, INFINITE);
    }
    if (m_hThreadExitEvent)
    {
        CloseHandle(m_hThreadExitEvent);
        m_hThreadExitEvent = NULL;
    }
    if (m_hReadPipe)
    {
        // Flush the pipe before closing it

        DWORD dwAvailable = 0;
        DWORD dwRead = 0;

        PeekNamedPipe(m_hReadPipe, NULL, 0, NULL, &dwAvailable, NULL);
        if (dwAvailable > 0)
        {
            char rgchOutputBuffer[READBUFFERSIZE];

            if (ReadFile(m_hReadPipe, rgchOutputBuffer, min(READBUFFERSIZE - 2, dwAvailable), &dwRead, NULL) &&
                (dwRead > 0))
            {
                rgchOutputBuffer[dwRead] = '\0';
                rgchOutputBuffer[dwRead-1] = '\0';

                OutputString(rgchOutputBuffer);
            }
        }

        CloseHandle(m_hReadPipe);
        m_hReadPipe = NULL;
    }
}

DWORD WINAPI CCommandExecuter::CCmdOutputReaderPipe::PipeReadThreadStart(void* pThis)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::PipeReadThreadStart \n") );

    _ASSERTE(pThis);
	if (!pThis)
		return 0;
    return ((CCmdOutputReaderPipe*)pThis)->ThreadExecute();
}

DWORD CCommandExecuter::CCmdOutputReaderPipe::ThreadExecute()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::ThreadExecute \n") );

    DWORD dwRead;
    char rgchOutputBuffer[READBUFFERSIZE];

    while (!m_fThreadDie)
    {
        ReadPipe(rgchOutputBuffer, READBUFFERSIZE - 2, &dwRead);

        if (dwRead > 0)
        {
            rgchOutputBuffer[dwRead] = '\0';
            rgchOutputBuffer[dwRead+1] = '\0';

            OutputString(rgchOutputBuffer);
            Sleep(200);
        }
        else
            m_fThreadDie = TRUE;
    }

    SetEvent(m_hThreadExitEvent);
    ExitThread(0);
    return 0;
}

DWORD WINAPI CCommandExecuter::CCmdOutputReaderPipe::ProcessMonitorThreadStart(void* pThis)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::ProcessMonitorThreadStart \n") );

    _ASSERTE(pThis);
 	if (!pThis)
		return 0;
    return ((CCmdOutputReaderPipe*)pThis)->ProcessMonitor();
}

DWORD CCommandExecuter::CCmdOutputReaderPipe::ProcessMonitor()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::ProcessMonitor \n") );

    DWORD dwExitCode;

    while (GetExitCodeProcess(m_hProcess, &dwExitCode) && (dwExitCode == STILL_ACTIVE))
        Sleep(500);

    Stop();

    delete this;
    ExitThread(0);
    return 0;
}

void CCommandExecuter::CCmdOutputReaderPipe::ReadPipe(void* pBuffer, DWORD nToRead,
                                                      DWORD* pnRead)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::ReadPipe \n") );

    DWORD dwAvailable = 0;

    while (PeekNamedPipe(m_hReadPipe, NULL, 0, NULL, &dwAvailable, NULL) &&
           (dwAvailable == 0) && !m_fThreadDie)
    {
        Sleep(SLEEPTIME);
    }

	if (pnRead)
		*pnRead = 0;
    if (dwAvailable != 0)
        ReadFile(m_hReadPipe, pBuffer, min(nToRead, dwAvailable), pnRead, NULL);
}

void CCommandExecuter::CCmdOutputReaderPipe::OutputString(char* lpszString)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CCommandExecuter::CCmdOutputReaderPipe::OutputString \n") );

    HRESULT hr;

    USES_CONVERSION;

    if (m_srpOutputPane != NULL)
    {
		if (lpszString != NULL)
		{
			CA2W wszString(lpszString);
			hr = m_srpOutputPane->OutputString(wszString);
			_ASSERTE(SUCCEEDED(hr));
		}
    }
}

