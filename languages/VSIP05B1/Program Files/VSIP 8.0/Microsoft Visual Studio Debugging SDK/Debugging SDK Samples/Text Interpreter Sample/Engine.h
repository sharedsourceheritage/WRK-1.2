
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Engine.h : Declaration of the CEngine

#ifndef __ENGINE_H_
#define __ENGINE_H_

#include "resource.h"       // main symbols
class CProgram;      // forward reference

/////////////////////////////////////////////////////////////////////////////
// CEngine
class ATL_NO_VTABLE CEngine : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEngine, &CLSID_Engine>,
	public IDebugEngine2
{
public:
	CEngine()
	{
	}

	void Start(CComObject<CProgram> *pProgram);

DECLARE_REGISTRY_RESOURCEID(IDR_ENGINE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CEngine)
	COM_INTERFACE_ENTRY(IDebugEngine2)
END_COM_MAP()

//IDebugEngine2
public:
   STDMETHOD(EnumPrograms)(IEnumDebugPrograms2** ppEnum);
   STDMETHOD(Attach)( IDebugProgram2 **rgpPrograms,
           IDebugProgramNode2 **rgpProgramNodes,
            DWORD celtPrograms,
            IDebugEventCallback2 *pCallback,
            ATTACH_REASON dwReason);
   STDMETHOD(CreatePendingBreakpoint)(
      IDebugBreakpointRequest2 *pBPRequest,
      IDebugPendingBreakpoint2** ppPendingBP);
   STDMETHOD(SetException)(EXCEPTION_INFO* pException);
   STDMETHOD(RemoveSetException)(EXCEPTION_INFO* pException);
   STDMETHOD(RemoveAllSetExceptions)(REFGUID guidType);
   STDMETHOD(GetEngineId)(GUID *pguidEngine);
   STDMETHOD(DestroyProgram)(IDebugProgram2* pProgram);
   STDMETHOD(ContinueFromSynchronousEvent)(IDebugEvent2* pEvent);
   STDMETHOD(SetLocale)(WORD wLangID);
   STDMETHOD(SetRegistryRoot)(LPCOLESTR pszRegistryRoot);
   STDMETHOD(SetMetric)(LPCOLESTR pszMetric, VARIANT varValue);
   STDMETHOD(CauseBreak)( void);

protected:
   CComObject<CProgram> *m_pProgram;
};

#endif //__ENGINE_H_
