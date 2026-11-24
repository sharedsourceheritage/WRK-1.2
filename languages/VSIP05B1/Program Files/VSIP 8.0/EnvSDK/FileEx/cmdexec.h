
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// CmdExec.h
//
// Declaration of CCommandExecuter
//
//*****************************************************************************
  
#pragma once
 
//*****************************************************************************
// CCommandExecuter
//*****************************************************************************
 
class ATL_NO_VTABLE CCommandExecuter :
    public CComObjectRootEx<CComSingleThreadModel>,
    public ICommandExecuter
{
// Constructor/Destructor
public:
    CCommandExecuter();
    ~CCommandExecuter();

// COM Interface Map
BEGIN_COM_MAP(CCommandExecuter)
    COM_INTERFACE_ENTRY(ICommandExecuter)
END_COM_MAP()

public:
// ICommandExecuter
    STDMETHOD(ExecuteCommand)(
                    /*[in]*/ LPCOLESTR lpszCommand,
                    /*[in]*/ LPCOLESTR lpszArguments,
                    /*[in]*/ LPCOLESTR lpszWorkingDir,
                    /*[in]*/ DWORD     dwFlags);

// Implementation
protected:
    HRESULT ExecuteComSpecCommand(LPCOLESTR lpszCommand, LPCOLESTR lpszArguments, LPCOLESTR lpszWorkingDir, DWORD dwFlags);
    HRESULT ExecuteOutputCommand(LPCOLESTR lpszCommand, LPCOLESTR lpszArguments, LPCOLESTR lpszWorkingDir, DWORD dwFlags);
    HRESULT ExecuteShellCommand(LPCOLESTR lpszCommand, LPCOLESTR lpszArguments, LPCOLESTR lpszWorkingDir);

    class CCmdOutputReaderPipe
    {
    // Constructor/Destructor
    public:
        CCmdOutputReaderPipe();
        ~CCmdOutputReaderPipe();

    // Operations
    public:
        BOOL CreatePipe(HANDLE* phReadPipe, HANDLE* phWritePipe);

        HRESULT Start(HANDLE hReadPipe, HANDLE hProcess, BOOL fClearOutput, IVsOutputWindowPane* pOutputPane);
        void Stop();

        static DWORD WINAPI PipeReadThreadStart(void* pThis);
        DWORD ThreadExecute();

        static DWORD WINAPI ProcessMonitorThreadStart(void* pThis);
        DWORD ProcessMonitor();

        void ReadPipe(void* pBuffer, DWORD nToRead, DWORD* pnRead);
        void OutputString(char* lpszString);

    // Attributes
    protected:
        CComPtr<IVsOutputWindowPane> m_srpOutputPane;
        HANDLE m_hReadPipe;

        HANDLE m_hThread;
        HANDLE m_hThreadExitEvent;
        BOOL m_fThreadDie;

        static SECURITY_ATTRIBUTES s_sa;

        HANDLE m_hProcess;
        HANDLE m_hMonitorThread;
    };
};
