
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


// Event.h: interface for the CEvent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EVENT_H__E44E16B4_CD4E_44BE_8090_68EC3127AE15__INCLUDED_)
#define AFX_EVENT_H__E44E16B4_CD4E_44BE_8090_68EC3127AE15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// IUnknown methods declaration macro
#define DECLARE_IUNKNOWN \
   STDMETHOD_(ULONG, AddRef)(void); \
   STDMETHOD_(ULONG, Release)(void); \
   STDMETHOD(QueryInterface)(REFIID riid, LPVOID *ppvObj);


class CEvent : public IDebugEvent2  
{
public:
	HRESULT SendEvent(IDebugEventCallback2 *pCallback, IDebugEngine2 *pEngine, IDebugProgram2 *pProgram, IDebugThread2 *pThread);
	CEvent(REFIID riid, DWORD dwAttrib);
	virtual ~CEvent();

// IUnknown methods
   STDMETHOD_(ULONG, AddRef)(void);
   STDMETHOD_(ULONG, Release)(void);
   STDMETHOD(QueryInterface)(REFIID riid, LPVOID *ppvObj);

   // IDebugEvent2 methods
   STDMETHOD(GetAttributes)(DWORD* pdwAttrib);

protected:
   IID m_riid;
   DWORD m_dwAttrib;

   ULONG m_iRefCount;
};


class CEngineCreateEvent : public IDebugEngineCreateEvent2, public CEvent  
{
public:
	CEngineCreateEvent(IDebugEngine2 *pEngine);
	virtual ~CEngineCreateEvent();

   // IUnknown methods
   DECLARE_IUNKNOWN

	// IDebugEngineCreateEvent2 methods
   STDMETHOD(GetEngine)(IDebugEngine2 **ppEngine);

protected:
   CComPtr<IDebugEngine2> m_spEngine;


};


class CProgramCreateEvent : 
	public IDebugProgramCreateEvent2 , 
	public CEvent  
{
public:
	CProgramCreateEvent();
	virtual ~CProgramCreateEvent();

	// IUnknown methods
   DECLARE_IUNKNOWN

};

class CLoadCompleteEvent : 
   public CEvent,
   public IDebugLoadCompleteEvent2 
{
public:
   CLoadCompleteEvent();
   virtual ~CLoadCompleteEvent();

   // IUnknown methods
   DECLARE_IUNKNOWN
};

class CEntryPointEvent : 
   public CEvent,
   public IDebugEntryPointEvent2 
{
public:
   CEntryPointEvent();
   virtual ~CEntryPointEvent();

   // IUnknown methods
   DECLARE_IUNKNOWN
};



class CBreakpointBoundEvent : public IDebugBreakpointBoundEvent2, public CEvent  
{
public:
	CBreakpointBoundEvent(IEnumDebugBoundBreakpoints2 *pEnum, 
      IDebugPendingBreakpoint2 *pPending);
	virtual ~CBreakpointBoundEvent();

   // IUnknown methods
   DECLARE_IUNKNOWN

   ////////////////////////////////////////////////////////////
   //IDebugBreakpointBoundEvent2 methods
   STDMETHOD(GetPendingBreakpoint)(IDebugPendingBreakpoint2** ppPendingBP);
   STDMETHOD(EnumBoundBreakpoints)(IEnumDebugBoundBreakpoints2** ppEnum);

protected:
   CComPtr<IEnumDebugBoundBreakpoints2> m_spEnum;
   CComPtr<IDebugPendingBreakpoint2> m_spPending;
};


class CCodeBreakpointEvent : 
	public IDebugBreakpointEvent2, 
	public CEvent  
{
public:
	CCodeBreakpointEvent(IDebugBoundBreakpoint2 *pBP);
	virtual ~CCodeBreakpointEvent();

	// IUnknown methods
   DECLARE_IUNKNOWN

   ////////////////////////////////////////////////////////////
   //IDebugBreakpointEvent2 methods
   STDMETHOD(EnumBreakpoints)(IEnumDebugBoundBreakpoints2 **ppEnum);

protected:
   CComPtr<IDebugBoundBreakpoint2> m_spBP;
};


class CProgramDestroyEvent : 
	public IDebugProgramDestroyEvent2 , 
	public CEvent  
{
public:
	CProgramDestroyEvent(DWORD dwExitCode);
	virtual ~CProgramDestroyEvent();

// IUnknown methods
   DECLARE_IUNKNOWN

   /////////////////////////////////////
   // IDebugProgramDestroyEvent2 methods
   STDMETHOD(GetExitCode)(DWORD *pdwExit);

protected:
   DWORD m_dwExitCode;
};

#endif // !defined(AFX_EVENT_H__E44E16B4_CD4E_44BE_8090_68EC3127AE15__INCLUDED_)
