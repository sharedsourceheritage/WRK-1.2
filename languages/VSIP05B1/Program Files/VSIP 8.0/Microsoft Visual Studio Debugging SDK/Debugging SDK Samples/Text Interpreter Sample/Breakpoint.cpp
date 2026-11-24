// Breakpoint.cpp : Implementation of CPendingBreakpoint
#include "stdafx.h"
#include "TextInterpreter.h"
#include "Event.h"

/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "Context.h"
#include "Breakpoint.h"

CComObject<CBoundBreakpoint> *gpBP;

/////////////////////////////////////////////////////////////////////////////
// CPendingBreakpoint

HRESULT CPendingBreakpoint::CanBind(IEnumDebugErrorBreakpoints2** ppErrorEnum)
{ return E_NOTIMPL; }
HRESULT CPendingBreakpoint::GetState(PENDING_BP_STATE_INFO* pState)
{ return E_NOTIMPL; }
HRESULT CPendingBreakpoint::Virtualize(BOOL fVirtualize)
{ return S_OK; }
HRESULT CPendingBreakpoint::Enable(BOOL fEnable)
{ return S_OK; }
HRESULT CPendingBreakpoint::SetCondition(BP_CONDITION bpCondition)
{ return E_NOTIMPL; }
HRESULT CPendingBreakpoint::SetPassCount(BP_PASSCOUNT bpPassCount)
{ return E_NOTIMPL; }
HRESULT CPendingBreakpoint::EnumBoundBreakpoints(IEnumDebugBoundBreakpoints2** ppEnum)
{ return E_NOTIMPL; }
HRESULT CPendingBreakpoint::EnumErrorBreakpoints(BP_ERROR_TYPE bpErrorType, IEnumDebugErrorBreakpoints2** ppEnum)
{ return E_NOTIMPL; }
HRESULT CPendingBreakpoint::Delete(void)
{ return E_NOTIMPL; }

void CPendingBreakpoint::Initialize(IDebugBreakpointRequest2 *pBPRequest, IDebugEventCallback2 *pCallback, IDebugEngine2 *pEngine)
{
   m_spCallback = pCallback;
   m_spEngine = pEngine;
   m_spBPRequest = pBPRequest;
}

HRESULT CPendingBreakpoint::GetBreakpointRequest(IDebugBreakpointRequest2** ppBPRequest)
{ 
   *ppBPRequest = m_spBPRequest;
   (*ppBPRequest)->AddRef();

   return S_OK;
}

HRESULT CPendingBreakpoint::Bind(void)
{ 
	BP_REQUEST_INFO bpRequestInfo;
   m_spBPRequest->GetRequestInfo(BPREQI_ALLFIELDS, &bpRequestInfo);

   if (bpRequestInfo.dwFields & BPREQI_BPLOCATION &&
      bpRequestInfo.bpLocation.bpLocationType == BPLT_CODE_FILE_LINE) {
   
      // Get the file name of the document.
      bpRequestInfo.bpLocation.bpLocation.bplocCodeFileLine.pDocPos->
         GetFileName(&m_sbstrDoc);
      // Get the position in the document
      bpRequestInfo.bpLocation.bpLocation.bplocCodeFileLine.pDocPos->
         GetRange(&m_posBeg, NULL);

      // Create a context
      CComObject<CDebugContext>* pContext;
      CComObject<CDebugContext>::CreateInstance(&pContext);
      pContext->AddRef();

      pContext->Initialize(m_sbstrDoc, m_posBeg);

      // Create a breakpoint resolution
      CComObject<CBreakpointResolution>* pBPRes;
      CComObject<CBreakpointResolution>::CreateInstance(&pBPRes);
      pBPRes->AddRef();

      pBPRes->Initialize(pContext);

      // Create a bound breakpoint
      CComObject<CBoundBreakpoint>* pBoundBP;
      CComObject<CBoundBreakpoint>::CreateInstance(&pBoundBP);
      pBoundBP->AddRef();

      pBoundBP->Initialize(this, pBPRes);

      SendBoundEvent(pBoundBP);
      
      // Save the last bound event.
      if (gpBP)
         gpBP->Release();
      gpBP = pBoundBP;
      gpBP->AddRef();

      pBoundBP->Release();
      pBPRes->Release();
      pContext->Release();

      return S_OK;
   }
   return E_NOTIMPL;
}


// IDebugBoundBreakpoint2
HRESULT CBoundBreakpoint::GetState(BP_STATE* pState)
{ return E_NOTIMPL; }
HRESULT CBoundBreakpoint::GetHitCount(DWORD* pdwHitCount)
{ return E_NOTIMPL; }
HRESULT CBoundBreakpoint::Enable(BOOL fEnable)
{ return E_NOTIMPL; }
HRESULT CBoundBreakpoint::SetHitCount(DWORD dwHitCount)
{ return E_NOTIMPL; }
HRESULT CBoundBreakpoint::SetCondition(BP_CONDITION bpCondition)
{ return E_NOTIMPL; }
HRESULT CBoundBreakpoint::SetPassCount(BP_PASSCOUNT bpPassCount)
{ return E_NOTIMPL; }
HRESULT CBoundBreakpoint::Delete(void)
{ return E_NOTIMPL; }


/////////////////////////////////////////////////////////////////////////////
// CBoundBreakpoint


HRESULT CBoundBreakpoint::Initialize(IDebugPendingBreakpoint2 *pPending, IDebugBreakpointResolution2 *pBPRes)
{
   m_spPendingBP = pPending;
   m_spBPRes = pBPRes;
   return S_OK;
}

HRESULT CBoundBreakpoint::GetPendingBreakpoint(
   IDebugPendingBreakpoint2** ppPendingBreakpoint)
{ 
   *ppPendingBreakpoint = m_spPendingBP;
   (*ppPendingBreakpoint)->AddRef();
   return S_OK;
}

HRESULT CBoundBreakpoint::GetBreakpointResolution(
   IDebugBreakpointResolution2** ppBPResolution)
{
   *ppBPResolution = m_spBPRes;
   (*ppBPResolution)->AddRef();
   return S_OK;
}


void CPendingBreakpoint::SendBoundEvent(IDebugBoundBreakpoint2 *pBoundBP)
{
	// Create the bound enumerator
   CComObject<CEnumDebugBoundBreakpoints>* pBoundEnum;
   CComObject<CEnumDebugBoundBreakpoints>::CreateInstance(&pBoundEnum);
   pBoundEnum->AddRef();

   IDebugBoundBreakpoint2* rgpBoundBP[] = { pBoundBP };
   pBoundEnum->Init(rgpBoundBP, &(rgpBoundBP[1]), NULL, AtlFlagCopy);

   CBreakpointBoundEvent* pBoundEvent = 
      new CBreakpointBoundEvent(pBoundEnum, this);
   pBoundEvent->SendEvent(m_spCallback, m_spEngine, NULL, NULL);

   pBoundEnum->Release();
}
