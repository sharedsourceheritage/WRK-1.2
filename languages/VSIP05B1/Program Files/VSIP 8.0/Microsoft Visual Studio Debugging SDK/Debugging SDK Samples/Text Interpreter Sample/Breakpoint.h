
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Breakpoint.h : Declaration of the CPendingBreakpoint

#ifndef __PENDINGBREAKPOINT_H_
#define __PENDINGBREAKPOINT_H_

#include "resource.h"       // main symbols

typedef CComEnumWithCount<IEnumDebugBoundBreakpoints2,    &IID_IEnumDebugBoundBreakpoints2, IDebugBoundBreakpoint2*,    _CopyInterface<IDebugBoundBreakpoint2> > CEnumDebugBoundBreakpoints;

/////////////////////////////////////////////////////////////////////////////
// CPendingBreakpoint
class ATL_NO_VTABLE CPendingBreakpoint : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPendingBreakpoint, &CLSID_PendingBreakpoint>,
	public IDebugPendingBreakpoint2
{
public:
	CPendingBreakpoint()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PENDINGBREAKPOINT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPendingBreakpoint)
	COM_INTERFACE_ENTRY(IDebugPendingBreakpoint2)
END_COM_MAP()

// IDebugPendingBreakpoint2
public:
	void SendBoundEvent(IDebugBoundBreakpoint2* pBoundBP);
	void Initialize(IDebugBreakpointRequest2* pBPRequest, IDebugEventCallback2 *pCallback, IDebugEngine2 *pEngine);
   STDMETHOD(CanBind)(IEnumDebugErrorBreakpoints2** ppErrorEnum);
   STDMETHOD(Bind)(void);
   STDMETHOD(GetState)(PENDING_BP_STATE_INFO* pState);
   STDMETHOD(GetBreakpointRequest)(IDebugBreakpointRequest2** ppBPRequest);
   STDMETHOD(Virtualize)(BOOL fVirtualize);
   STDMETHOD(Enable)(BOOL fEnable);
   STDMETHOD(SetCondition)(BP_CONDITION bpCondition);
   STDMETHOD(SetPassCount)(BP_PASSCOUNT bpPassCount);
   STDMETHOD(EnumBoundBreakpoints)(IEnumDebugBoundBreakpoints2** ppEnum);
   STDMETHOD(EnumErrorBreakpoints)(BP_ERROR_TYPE bpErrorType, IEnumDebugErrorBreakpoints2** ppEnum);
   STDMETHOD(Delete)(void);

protected:
	CComBSTR m_sbstrDoc;
   TEXT_POSITION m_posBeg;

   CComPtr<IDebugEventCallback2> m_spCallback;
   CComPtr<IDebugEngine2> m_spEngine;
   CComPtr<IDebugBreakpointRequest2> m_spBPRequest;
};

// Breakpoint.h : Declaration of the CBoundBreakpoint


/////////////////////////////////////////////////////////////////////////////
// CBoundBreakpoint
class ATL_NO_VTABLE CBoundBreakpoint : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBoundBreakpoint, &CLSID_BoundBreakpoint>,
	public IDebugBoundBreakpoint2
{
public:
	CBoundBreakpoint()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_BOUNDBREAKPOINT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CBoundBreakpoint)
	COM_INTERFACE_ENTRY(IDebugBoundBreakpoint2)
END_COM_MAP()

// IDebugBoundBreakpoint2
public:
   STDMETHOD(Initialize)(IDebugPendingBreakpoint2 *pPending,IDebugBreakpointResolution2 *pBPRes);
   STDMETHOD(GetPendingBreakpoint)(IDebugPendingBreakpoint2** ppPendingBreakpoint);
   STDMETHOD(GetState)(BP_STATE* pState);
   STDMETHOD(GetHitCount)(DWORD* pdwHitCount);
   STDMETHOD(GetBreakpointResolution)(IDebugBreakpointResolution2** ppBPResolution);
   STDMETHOD(Enable)(BOOL fEnable);
   STDMETHOD(SetHitCount)(DWORD dwHitCount);
   STDMETHOD(SetCondition)(BP_CONDITION bpCondition);
   STDMETHOD(SetPassCount)(BP_PASSCOUNT bpPassCount);
   STDMETHOD(Delete)(void);

protected:
   CComPtr<IDebugPendingBreakpoint2> m_spPendingBP;
   CComPtr<IDebugBreakpointResolution2> m_spBPRes;
};

extern CComObject<CBoundBreakpoint> *gpBP;

#endif //__PENDINGBREAKPOINT_H_
