
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Engine.cpp : Implementation of CEngine
#include "stdafx.h"
#include "TextInterpreter.h"
#include "Engine.h"
#include "Program.h"

/////////////////////////////////////////////////////////////////////////////
// CEngine

//IDebugEngine2 methods
HRESULT CEngine::EnumPrograms(IEnumDebugPrograms2** ppEnum)
{ return E_NOTIMPL; }
HRESULT CEngine::Attach( IDebugProgram2 **rgpPrograms,
            IDebugProgramNode2 **rgpProgramNodes,
            DWORD celtPrograms,
            IDebugEventCallback2 *pCallback,
            ATTACH_REASON dwReason)
{ return E_NOTIMPL; }
HRESULT CEngine::SetException(EXCEPTION_INFO* pException)
{ return E_NOTIMPL; }
HRESULT CEngine::RemoveSetException(EXCEPTION_INFO* pException)
{ return E_NOTIMPL; }
HRESULT CEngine::RemoveAllSetExceptions(REFGUID guidType)
{ return E_NOTIMPL; }
HRESULT CEngine::GetEngineId(GUID *pguidEngine)
{ return E_NOTIMPL; }
HRESULT CEngine::DestroyProgram(IDebugProgram2* pProgram)
{ return E_NOTIMPL; }
HRESULT CEngine::SetLocale(WORD wLangID)
{ return E_NOTIMPL; }
HRESULT CEngine::SetRegistryRoot(LPCOLESTR pszRegistryRoot)
{ return E_NOTIMPL; }
HRESULT CEngine::SetMetric(LPCOLESTR pszMetric, VARIANT varValue)
{ return E_NOTIMPL; }

HRESULT CEngine::ContinueFromSynchronousEvent(IDebugEvent2* pEvent)
{ 
   PostThreadMessage(
      GetCurrentThreadId(), WM_CONTINUE_SYNC_EVENT, 0, 0);
   return S_OK;
}


void CEngine::Start(CComObject<CProgram> *pProgram)
{
   m_pProgram = pProgram;
}

HRESULT CEngine::CreatePendingBreakpoint(
   IDebugBreakpointRequest2 *pBPRequest, 
   IDebugPendingBreakpoint2** ppPendingBP)
{	
	 
   return m_pProgram->CreatePendingBreakpoint(pBPRequest, ppPendingBP);
}
HRESULT CEngine::CauseBreak(void)
{
	return E_NOTIMPL ;
}