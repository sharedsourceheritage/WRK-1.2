
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Program.cpp : Implementation of CProgram
#include "stdafx.h"
#include "TextInterpreter.h"
#include "Engine.h"
#include "Program.h"
#include "Event.h"
#include "Breakpoint.h"
#include "StackFrame.h"
#include "Context.h"

/////////////////////////////////////////////////////////////////////////////
// CProgram

// IDebugProgramNode2 methods
HRESULT CProgram::GetProgramName(BSTR* pbstrProgramName)
   { return E_NOTIMPL; }
HRESULT CProgram::GetHostName(DWORD dwHostNameType, BSTR* pbstrHostName)
   { return E_NOTIMPL; }
HRESULT CProgram::GetHostMachineName(BSTR* pbstrHostMachineName)
   { return E_NOTIMPL; }
HRESULT CProgram::DetachDebugger(void)
   { return E_NOTIMPL; }

HRESULT CProgram::GetEngineInfo(BSTR* pbstrEngine, GUID* pguidEngine)
{
   if ( (NULL==pbstrEngine) || (NULL==pguidEngine) )
       return E_POINTER;
   *pbstrEngine = SysAllocString(L"Text Interpreter DE");
   *pguidEngine = __uuidof(Engine);

   return S_OK;
}

HRESULT CProgram::GetHostPid(AD_PROCESS_ID *pHostProcessId)
{
   pHostProcessId->ProcessIdType = AD_PROCESS_ID_SYSTEM;
   pHostProcessId->ProcessId.dwProcessId = GetCurrentProcessId();

   return S_OK;
}

HRESULT CProgram::Attach(IDebugProgram2* pMDMProgram,
   IDebugEventCallback2* pCallback, DWORD dwReason)
{ 
    
   m_spCallback = pCallback;

   pMDMProgram->GetProgramId(&m_guidProgId);

   CEngineCreateEvent *pDECE = new CEngineCreateEvent(m_spEngine);
   pDECE->SendEvent(pCallback, m_spEngine, NULL, NULL);

   CProgramCreateEvent *pDPCE = new CProgramCreateEvent;
   pDPCE->SendEvent(pCallback, m_spEngine, this, NULL);
   
   CLoadCompleteEvent *pDLCE = new CLoadCompleteEvent;
   pDLCE->SendEvent(pCallback, m_spEngine, this, this);
   
   
   return S_OK;
}


//////////////////////////////////////////
// IDebugProgram2 methods
HRESULT CProgram::EnumThreads(IEnumDebugThreads2** ppEnum)
{ return E_NOTIMPL; }
HRESULT CProgram::GetName(BSTR* pbstrName)
{ return E_NOTIMPL; }
HRESULT CProgram::GetProcess(IDebugProcess2** ppProcess)
{ return E_NOTIMPL; }
HRESULT CProgram::Terminate(void)
{ return E_NOTIMPL; }
HRESULT CProgram::Attach(IDebugEventCallback2* pCallback)
{ return E_NOTIMPL; }
HRESULT CProgram::Detach(void)
{ return E_NOTIMPL; }
HRESULT CProgram::GetDebugProperty(IDebugProperty2** ppProperty)
{ return E_NOTIMPL; }
HRESULT CProgram::CauseBreak(void)
{ return E_NOTIMPL; }
HRESULT CProgram::EnumCodeContexts(IDebugDocumentPosition2* pDocPos, IEnumDebugCodeContexts2** ppEnum)
{ return E_NOTIMPL; }
HRESULT CProgram::GetMemoryBytes(IDebugMemoryBytes2** ppMemoryBytes)
{ return E_NOTIMPL; }
HRESULT CProgram::GetDisassemblyStream(DISASSEMBLY_STREAM_SCOPE dwScope, IDebugCodeContext2* pCodeContext, IDebugDisassemblyStream2** ppDisassemblyStream)
{ return E_NOTIMPL; }
HRESULT CProgram::EnumModules(IEnumDebugModules2** ppEnum)
{ return E_NOTIMPL; }
HRESULT CProgram::GetENCUpdate(IDebugENCUpdate** ppUpdate)
{ return E_NOTIMPL; }
HRESULT CProgram::EnumCodePaths(LPCOLESTR pszHint, IDebugCodeContext2* pStart, IDebugStackFrame2* pFrame, BOOL fSource, IEnumCodePaths2** ppEnum, IDebugCodeContext2** ppSafety)
{ return E_NOTIMPL; }
HRESULT CProgram::WriteDump(DUMPTYPE DumpType,LPCOLESTR pszCrashDumpUrl)
{ return E_NOTIMPL; }

HRESULT CProgram::GetProgramId(GUID* pguidProgramId)
{ 
   *pguidProgramId = m_guidProgId;
   return S_OK;
}

HRESULT CProgram::Execute(void)
{ 
   PostThreadMessage(
      GetCurrentThreadId(), WM_CONTINUE, 0, (LPARAM)this);
   return S_OK; 
}
HRESULT CProgram::Continue(IDebugThread2 *pThread)
{ 
   PostThreadMessage(
      GetCurrentThreadId(), WM_CONTINUE, 0, (LPARAM)this);
   return S_OK; 
}
HRESULT CProgram::Step(IDebugThread2 *pThread, STEPKIND sk, STEPUNIT step)
{ 
   PostThreadMessage(
      GetCurrentThreadId(), WM_CONTINUE, 0, (LPARAM)this);
   return S_OK; 
}

///////////////////////////////////////////////////////////////////////
//IDebugThread2 methods
HRESULT CProgram::SetThreadName(LPCOLESTR pszName)
{ return E_NOTIMPL; }
HRESULT CProgram::GetProgram(IDebugProgram2** ppProgram)
{ return E_NOTIMPL; }
HRESULT CProgram::CanSetNextStatement(IDebugStackFrame2 *pStackFrame, IDebugCodeContext2 *pCodeContext)
{ return E_NOTIMPL; }
HRESULT CProgram::SetNextStatement(IDebugStackFrame2 *pStackFrame, IDebugCodeContext2 *pCodeContext)
{ return E_NOTIMPL; }
HRESULT CProgram::Suspend(DWORD *pdwSuspendCount)
{ return E_NOTIMPL; }
HRESULT CProgram::Resume(DWORD *pdwSuspendCount)
{ return E_NOTIMPL; }
HRESULT CProgram::GetThreadProperties(THREADPROPERTY_FIELDS dwFields, THREADPROPERTIES *ptp)
{ return E_NOTIMPL; }
HRESULT CProgram::GetLogicalThread(IDebugStackFrame2 *pStackFrame, IDebugLogicalThread2 **ppLogicalThread)
{ return E_NOTIMPL; }

void CProgram::Start(IDebugEngine2 *pEngine)
{
   m_spEngine = pEngine;


   HRESULT hr = m_srpProgramPublisher.CoCreateInstance(CLSID_ProgramPublisher);
   if ( FAILED(hr) )
   {
      ATLTRACE("Failed to create the program publisher: 0x%x.", hr);
      return;
   }

   hr = m_srpProgramPublisher->PublishProgramNode(static_cast<IDebugProgramNode2*>(this));
   if ( FAILED(hr) )
   {
      ATLTRACE("Failed to publish the program node: 0x%x.", hr);
      m_srpProgramPublisher.Release();
      return;
   }


   ATLTRACE("Added program node.\n");
}


HRESULT CProgram::GetThreadId(DWORD* pdwThreadId)
{ *pdwThreadId = GetCurrentThreadId();
   return S_OK;
}

void CProgram::Go()
{

    // Wait for load complete event.
   if (!bAttached) {
      bAttached = true;

      // At this point, all pending breakpoints are bound.
      // Fire entry point event.
      CEntryPointEvent *pDEPE = new CEntryPointEvent;
      pDEPE->SendEvent(m_spCallback, m_spEngine, this, this);
      return;
   }
   if (!bEntered) {
      bEntered = true;

      // Fire breakpoint event.
      CCodeBreakpointEvent *pCBPE = new CCodeBreakpointEvent(gpBP);
      pCBPE->SendEvent(m_spCallback, m_spEngine, this, this);
   
      return;
   }

    NotifyProgramEnd();

}

HRESULT CProgram::CreatePendingBreakpoint(IDebugBreakpointRequest2 *pBPRequest, IDebugPendingBreakpoint2 **ppPendingBP)
{

    CComObject<CPendingBreakpoint> *pPending;
   CComObject<CPendingBreakpoint>::CreateInstance(&pPending);
   pPending->AddRef();

   pPending->Initialize(pBPRequest, m_spCallback, m_spEngine);
   pPending->QueryInterface(ppPendingBP);
   
   pPending->Release();
   return S_OK;

}

void CProgram::FinalRelease()
{
   if (gpBP)
      gpBP->Release();
}

CProgram::CProgram()
{
   gpBP = NULL;
   bAttached = false;
    bEntered = false;
}

HRESULT CProgram::EnumFrameInfo(FRAMEINFO_FLAGS dwFieldSpec, UINT nRadix, IEnumDebugFrameInfo2 **ppEnum)
{ // Create a single stack frame.
   FRAMEINFO *pFrameInfo = (FRAMEINFO *) malloc(sizeof(FRAMEINFO));
   if (NULL == pFrameInfo)
      return E_OUTOFMEMORY;
   memset(pFrameInfo, 0, sizeof(FRAMEINFO));

   FRAMEINFO_FLAGS fi = 
      FIF_LANGUAGE | FIF_FUNCNAME | FIF_STACKRANGE | FIF_FRAME;
   pFrameInfo->m_dwValidFields = fi;

   pFrameInfo->m_bstrLanguage = SysAllocString(L"Simple Language");
   pFrameInfo->m_bstrFuncName = SysAllocString(L"Simple Function");

   CComObject<CStackFrame> *pFrame;
   CComObject<CStackFrame>::CreateInstance(&pFrame);
   pFrame->AddRef();
   pFrameInfo->m_pFrame = (IDebugStackFrame2 *) pFrame;

   // Initialize code and doc contexts here.
   // Get sbstrFile and pos.
   CComPtr<IDebugBreakpointResolution2> pBPResolution;
   gpBP->GetBreakpointResolution(&pBPResolution);

   BP_RESOLUTION_INFO bpResInfo;
   pBPResolution->GetResolutionInfo(BPRESI_ALLFIELDS, &bpResInfo);
   IDebugDocumentContext2 *pDocContext;
   bpResInfo.bpResLocation.bpResLocation.bpresCode.pCodeContext->
      GetDocumentContext(&pDocContext);
   bpResInfo.bpResLocation.bpResLocation.bpresCode.pCodeContext->
      Release();
   
   CComBSTR sbstrDoc;
   TEXT_POSITION posBeg;
   pDocContext->GetName(GN_FILENAME, &sbstrDoc);
   pDocContext->GetSourceRange(&posBeg, NULL);
   pDocContext->Release();

   CComObject<CDebugContext> *pContext;
   CComObject<CDebugContext>::CreateInstance(&pContext);
   pContext->AddRef();
   pContext->Initialize(sbstrDoc, posBeg);

   pFrame->Init(pContext);
   pContext->Release();
   
   // Create and initialize enumerator.
   CComObject<CEnumFrameInfo> *pEnum;
   CComObject<CEnumFrameInfo>::CreateInstance(&pEnum);
   pEnum->AddRef();
   pEnum->Init(pFrameInfo);

   // Free frame resources.
   SysFreeString(pFrameInfo->m_bstrLanguage);
   SysFreeString(pFrameInfo->m_bstrFuncName);
   pFrame->Release();
   free(pFrameInfo);

   *ppEnum = pEnum;

   return S_OK;
}

void CProgram::NotifyProgramEnd()
{
    CProgramDestroyEvent *pProgramDestroy = 
      new CProgramDestroyEvent(0);
    pProgramDestroy->SendEvent(m_spCallback, m_spEngine, this, NULL);

    if (m_srpProgramPublisher != NULL)
    {
        m_srpProgramPublisher->UnpublishProgramNode(static_cast<IDebugProgramNode2*>(this));
        m_srpProgramPublisher.Release();
    }

}
HRESULT CProgram::CanDetach(void)
{ return E_NOTIMPL; }
