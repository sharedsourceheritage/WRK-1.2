
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// StackFrame.h : Declaration of the CStackFrame

#ifndef __STACKFRAME_H_
#define __STACKFRAME_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStackFrame
class ATL_NO_VTABLE CStackFrame : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CStackFrame, &CLSID_StackFrame>,
	public IDebugStackFrame2
{
public:
	CStackFrame()
	{
	}
   
	void Init(IDebugDocumentContext2* pDocContext);

DECLARE_REGISTRY_RESOURCEID(IDR_STACKFRAME)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CStackFrame)
	COM_INTERFACE_ENTRY(IDebugStackFrame2)
END_COM_MAP()

// IDebugStackFrame2
public:
   STDMETHOD(GetCodeContext)(IDebugCodeContext2 **ppCodeCxt);
   STDMETHOD(GetDocumentContext)(IDebugDocumentContext2 **ppCxt);
   STDMETHOD(GetName)(BSTR* pbstrName);
   STDMETHOD(GetInfo)(FRAMEINFO_FLAGS dwFieldSpec, UINT nRadix, FRAMEINFO *pFrameInfo);
   STDMETHOD(GetPhysicalStackRange)(UINT64* paddrMin, UINT64* paddrMax);
   STDMETHOD(GetExpressionContext)(IDebugExpressionContext2 **ppExprCxt);
   STDMETHOD(GetLanguageInfo)(BSTR* pbstrLanguage, GUID* pguidLanguage);
   STDMETHOD(GetDebugProperty)(IDebugProperty2 **ppDebugProp);
   STDMETHOD(EnumProperties)(DEBUGPROP_INFO_FLAGS dwFields, UINT nRadix, REFGUID guidFilter, DWORD dwTimeout, ULONG *pcelt, IEnumDebugPropertyInfo2 **ppepi);
   STDMETHOD(GetThread)(IDebugThread2** ppThread);

protected:
   CComPtr<IDebugDocumentContext2> m_spDocContext;
};

// StackFrame.h : Declaration of the CEnumFrameInfo


/////////////////////////////////////////////////////////////////////////////
// CEnumFrameInfo
class ATL_NO_VTABLE CEnumFrameInfo : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEnumFrameInfo, &CLSID_EnumFrameInfo>,
	public IEnumDebugFrameInfo2
{
public:
	CEnumFrameInfo()
	{
	}

   void FinalRelease();

   void Init(FRAMEINFO *pFrameInfo);

private:
   void CopyEnumElement(FRAMEINFO* pDest, FRAMEINFO* pSrc);

public:
DECLARE_REGISTRY_RESOURCEID(IDR_ENUMFRAMEINFO)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CEnumFrameInfo)
	COM_INTERFACE_ENTRY(IEnumDebugFrameInfo2)
END_COM_MAP()

// IEnumDebugFrameInfo2
public:
   STDMETHOD(Next)(ULONG celt, FRAMEINFO *rgelt, ULONG* pceltFetched);
   STDMETHOD(Skip)(ULONG celt);
   STDMETHOD(Reset)();
   STDMETHOD(Clone)(IEnumDebugFrameInfo2** ppEnum);
   STDMETHOD(GetCount)(ULONG* pcelt);

protected:
   FRAMEINFO m_FrameInfo;
};

#endif //__STACKFRAME_H_
