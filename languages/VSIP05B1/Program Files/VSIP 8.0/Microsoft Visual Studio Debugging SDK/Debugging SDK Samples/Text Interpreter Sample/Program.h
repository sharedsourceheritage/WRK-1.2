
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


// Program.h : Declaration of the CProgram

#ifndef __PROGRAM_H_
#define __PROGRAM_H_

#include "resource.h"       // main symbols
#include "windows.h"

/////////////////////////////////////////////////////////////////////////////
// CProgram
class ATL_NO_VTABLE CProgram : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CProgram, &CLSID_Program>,
    public IDebugProgramNode2,
   public IDebugProgram2,
   public IDebugThread2
{
public:
    CProgram();

    void Start(IDebugEngine2 *pEngine);

DECLARE_REGISTRY_RESOURCEID(IDR_PROGRAM)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CProgram)
    COM_INTERFACE_ENTRY(IDebugProgramNode2)
    COM_INTERFACE_ENTRY(IDebugProgram2)
   COM_INTERFACE_ENTRY(IDebugThread2)
END_COM_MAP()

// IDebugProgramNode2
public:
    void NotifyProgramEnd();
    void FinalRelease();
    HRESULT CreatePendingBreakpoint(IDebugBreakpointRequest2 *pBPRequest, IDebugPendingBreakpoint2** ppPendingBP);
    void Go();
   STDMETHOD(GetProgramName)(BSTR* pbstrProgramName);
   STDMETHOD(GetHostName)(DWORD dwHostNameType, BSTR* pbstrHostName);
   STDMETHOD(GetHostPid)(AD_PROCESS_ID *pHostProcessId);
   STDMETHOD(GetHostMachineName)(BSTR* pbstrHostMachineName);
   STDMETHOD(Attach)(
      IDebugProgram2* pMDMProgram, IDebugEventCallback2* pCallback, 
      DWORD dwReason);
   STDMETHOD(GetEngineInfo)(BSTR* pbstrEngine, GUID* pguidEngine);
   STDMETHOD(DetachDebugger)(void);

// IDebugProgram2
   STDMETHOD(EnumThreads)(IEnumDebugThreads2** ppEnum);
   STDMETHOD(GetName)(BSTR* pbstrName);
   STDMETHOD(GetProcess)(IDebugProcess2** ppProcess);
   STDMETHOD(Terminate)(void);
   STDMETHOD(Attach)(IDebugEventCallback2* pCallback);
   STDMETHOD(Detach)(void);
   STDMETHOD(GetProgramId)(GUID* pguidProgramId);
   STDMETHOD(GetDebugProperty)(IDebugProperty2** ppProperty);
   STDMETHOD(Execute)(void);
   STDMETHOD(Continue)(IDebugThread2 *pThread);
   STDMETHOD(Step)(IDebugThread2 *pThread, STEPKIND sk, STEPUNIT step);
   STDMETHOD(CauseBreak)(void);
   //GetEngineInfo already defined for IDebugProgramNode2
   STDMETHOD(EnumCodeContexts)(IDebugDocumentPosition2* pDocPos, IEnumDebugCodeContexts2** ppEnum);
   STDMETHOD(GetMemoryBytes)(IDebugMemoryBytes2** ppMemoryBytes);
   STDMETHOD(GetDisassemblyStream)(DISASSEMBLY_STREAM_SCOPE dwScope, IDebugCodeContext2* pCodeContext, IDebugDisassemblyStream2** ppDisassemblyStream);
   STDMETHOD(EnumModules)(IEnumDebugModules2** ppEnum);
   STDMETHOD(GetENCUpdate)(IDebugENCUpdate** ppUpdate);
   STDMETHOD(EnumCodePaths)(LPCOLESTR pszHint, IDebugCodeContext2* pStart, IDebugStackFrame2* pFrame, BOOL fSource, IEnumCodePaths2** ppEnum, IDebugCodeContext2** ppSafety);
   STDMETHOD(WriteDump)(DUMPTYPE DumpType, LPCOLESTR pszCrashDumpUrl);
   STDMETHOD(CanDetach)(void);


// IDebugThread2
   STDMETHOD(EnumFrameInfo)(FRAMEINFO_FLAGS dwFieldSpec, UINT nRadix,       IEnumDebugFrameInfo2 **ppEnum);
   // GetName already defined for IDebugProgram
   STDMETHOD(SetThreadName)(LPCOLESTR pszName);
   STDMETHOD(GetProgram)(IDebugProgram2** ppProgram);
   STDMETHOD(CanSetNextStatement)(IDebugStackFrame2 *pStackFrame,       IDebugCodeContext2 *pCodeContext);
   STDMETHOD(SetNextStatement) (IDebugStackFrame2 *pStackFrame,       IDebugCodeContext2 *pCodeContext);
   STDMETHOD(GetThreadId)(DWORD* pdwThreadId);
   STDMETHOD(Suspend)(DWORD *pdwSuspendCount);
   STDMETHOD(Resume)(DWORD *pdwSuspendCount);
   STDMETHOD(GetThreadProperties)(THREADPROPERTY_FIELDS dwFields,       THREADPROPERTIES *ptp);
   STDMETHOD(GetLogicalThread)(IDebugStackFrame2 *pStackFrame,       IDebugLogicalThread2 **ppLogicalThread);

protected:
   GUID m_guidProgId;
    bool bAttached;
    bool bEntered;

   CComPtr<IDebugEngine2> m_spEngine;
   CComPtr<IDebugProgramPublisher2> m_srpProgramPublisher;
    CComPtr<IDebugPortNotify2> m_spPortNotify;
    CComPtr<IDebugEventCallback2> m_spCallback;
};

#endif //__PROGRAM_H_
