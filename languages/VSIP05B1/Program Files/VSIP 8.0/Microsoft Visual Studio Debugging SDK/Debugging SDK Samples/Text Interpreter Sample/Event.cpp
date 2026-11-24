// Event.cpp: implementation of the CEvent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TextInterpreter.h"
#include "Event.h"

typedef CComEnumWithCount<IEnumDebugBoundBreakpoints2,    &IID_IEnumDebugBoundBreakpoints2, IDebugBoundBreakpoint2*,    _CopyInterface<IDebugBoundBreakpoint2> > CEnumDebugBoundBreakpoints;

// IUnknown methods implementation macro
#define IMPLEMENT_IUNKNOWN(T, I) \
ULONG T::AddRef(void) { return CEvent::AddRef(); } \
ULONG T::Release(void) { return CEvent::Release(); } \
HRESULT T::QueryInterface(REFIID riid, LPVOID *ppvObj) { \
   if (IID_##I == riid) { \
   *ppvObj = (I *)(this); AddRef(); return S_OK; \
   } \
   return CEvent::QueryInterface(riid, ppvObj); \
}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEvent::CEvent(REFIID riid, DWORD dwAttrib)
{
	m_riid = riid;
	m_dwAttrib = dwAttrib;
	m_iRefCount = 0;
}

CEvent::~CEvent()
{

}


// CEvent IUnknown methods
ULONG CEvent::AddRef(void) {
   return ++m_iRefCount;
}

ULONG CEvent::Release(void) {
   m_iRefCount--;
   if (m_iRefCount == 0) {
   delete this;
   return 0;
   }
   return m_iRefCount;
}

HRESULT CEvent::QueryInterface(REFIID riid, LPVOID *ppvObj) {
   if (riid == IID_IUnknown)
   *ppvObj = (IUnknown*) this;
   else if (riid == IID_IDebugEvent2)
   *ppvObj = (IDebugEvent2*) this;
   else return E_NOINTERFACE;

   AddRef();
   return S_OK;
}

// CEvent::GetAttributes
HRESULT CEvent::GetAttributes(DWORD* pdwAttrib) {
   *pdwAttrib = m_dwAttrib;
   return S_OK;
}

//////////////////////////////////////////////////////////////////////
// CEngineCreateEvent Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEngineCreateEvent::CEngineCreateEvent(IDebugEngine2 *pEngine)
   : CEvent(IID_IDebugEngineCreateEvent2, EVENT_ASYNCHRONOUS)
{
   m_spEngine = pEngine;
}


CEngineCreateEvent::~CEngineCreateEvent()
{

}

HRESULT CEngineCreateEvent::GetEngine(IDebugEngine2 **ppEngine) {
   *ppEngine = m_spEngine;
   (*ppEngine)->AddRef();
   return S_OK;
}

IMPLEMENT_IUNKNOWN(CEngineCreateEvent, IDebugEngineCreateEvent2)

//////////////////////////////////////////////////////////////////////
// CProgramCreateEvent Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProgramCreateEvent::CProgramCreateEvent()
: CEvent(IID_IDebugProgramCreateEvent2, EVENT_ASYNCHRONOUS)
{

}

CProgramCreateEvent::~CProgramCreateEvent()
{

}

IMPLEMENT_IUNKNOWN(CProgramCreateEvent, IDebugProgramCreateEvent2)


HRESULT CEvent::SendEvent(IDebugEventCallback2 *pCallback, IDebugEngine2 *pEngine, IDebugProgram2 *pProgram, IDebugThread2 *pThread)
{
	AddRef();
   HRESULT hr = pCallback->Event(
      pEngine, NULL, pProgram, pThread, (IDebugEvent2 *) this,
      m_riid, m_dwAttrib);
   
   // If event is synchronous, pump messages and wait for continuation.
   if (SUCCEEDED(hr) && (m_dwAttrib == EVENT_SYNCHRONOUS))
   {
      while (true)
      {
         MSG msg;
         if (GetMessage(&msg, NULL, 0, 0))
         {
            if (msg.message == WM_CONTINUE_SYNC_EVENT)
               break;
            DispatchMessage(&msg);
         }
      }
   }
   Release();
   return hr;

}


CLoadCompleteEvent::CLoadCompleteEvent()
   : CEvent(IID_IDebugLoadCompleteEvent2, EVENT_SYNC_STOP)
{
}
CLoadCompleteEvent::~CLoadCompleteEvent()
{

}
CEntryPointEvent::CEntryPointEvent()
   : CEvent(IID_IDebugEntryPointEvent2, EVENT_SYNC_STOP)
{
}
CEntryPointEvent::~CEntryPointEvent()
{

}


IMPLEMENT_IUNKNOWN(CLoadCompleteEvent, IDebugLoadCompleteEvent2)
IMPLEMENT_IUNKNOWN(CEntryPointEvent, IDebugEntryPointEvent2)


//////////////////////////////////////////////////////////////////////
// CBreakpointBoundEvent Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBreakpointBoundEvent::CBreakpointBoundEvent(
   IEnumDebugBoundBreakpoints2 *pEnum, 
   IDebugPendingBreakpoint2 *pPending)
: CEvent(IID_IDebugBreakpointBoundEvent2, EVENT_ASYNCHRONOUS)
{
   m_spEnum = pEnum;
   m_spPending = pPending;
}


CBreakpointBoundEvent::~CBreakpointBoundEvent()
{

}

IMPLEMENT_IUNKNOWN(CBreakpointBoundEvent, IDebugBreakpointBoundEvent2)

// Get the pending breakpoint that was bound to the breakpoint
HRESULT CBreakpointBoundEvent::GetPendingBreakpoint(IDebugPendingBreakpoint2** ppPendingBP) {
   *ppPendingBP = m_spPending;
   (*ppPendingBP)->AddRef();
   return S_OK;
}

// Get the list of breakpoints bound on this event
HRESULT CBreakpointBoundEvent::EnumBoundBreakpoints(IEnumDebugBoundBreakpoints2** ppEnum) {
   *ppEnum = m_spEnum;
   (*ppEnum)->AddRef();
   return S_OK;
}

//////////////////////////////////////////////////////////////////////
// CCodeBreakpointEvent Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCodeBreakpointEvent::CCodeBreakpointEvent(IDebugBoundBreakpoint2 *pBP)
: CEvent(IID_IDebugBreakpointEvent2, EVENT_SYNC_STOP)
{
   m_spBP = pBP;
}

CCodeBreakpointEvent::~CCodeBreakpointEvent()
{

}

IMPLEMENT_IUNKNOWN(CCodeBreakpointEvent, IDebugBreakpointEvent2);

HRESULT CCodeBreakpointEvent::EnumBreakpoints(
   IEnumDebugBoundBreakpoints2 **ppEnum)
{
   // Create the bound enumerator
   CComObject<CEnumDebugBoundBreakpoints>* pBoundEnum;
   CComObject<CEnumDebugBoundBreakpoints>::CreateInstance(&pBoundEnum);

   IDebugBoundBreakpoint2* rgpBoundBP[] = { m_spBP };
   pBoundEnum->Init(rgpBoundBP, &(rgpBoundBP[1]), NULL, AtlFlagCopy);

   *ppEnum = pBoundEnum;
   (*ppEnum)->AddRef();

   return S_OK;
}

//////////////////////////////////////////////////////////////////////
// CProgramDestroyEvent Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProgramDestroyEvent::CProgramDestroyEvent(DWORD dwExitCode)
   : CEvent(IID_IDebugProgramDestroyEvent2, EVENT_ASYNCHRONOUS)
{
   m_dwExitCode = dwExitCode;
}

CProgramDestroyEvent::~CProgramDestroyEvent()
{

}

IMPLEMENT_IUNKNOWN(CProgramDestroyEvent, IDebugProgramDestroyEvent2)

HRESULT CProgramDestroyEvent::GetExitCode(DWORD *pdwExit) {
   *pdwExit = m_dwExitCode;
   return S_OK;
}