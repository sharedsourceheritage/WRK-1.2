
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Context.h : Declaration of the CDebugContext

#ifndef __DEBUGCONTEXT_H_
#define __DEBUGCONTEXT_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDebugContext
class ATL_NO_VTABLE CDebugContext : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDebugContext, &CLSID_DebugContext>,
	public IDebugCodeContext2,
	public IDebugDocumentContext2
{
public:
	CDebugContext()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DEBUGCONTEXT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDebugContext)
	COM_INTERFACE_ENTRY(IDebugCodeContext2)
	COM_INTERFACE_ENTRY(IDebugDocumentContext2)
END_COM_MAP()

// IDebugCodeContext2 methods
public:
	void Initialize(LPCWSTR pszFileName, TEXT_POSITION& pos);
   STDMETHOD(GetDocumentContext)(IDebugDocumentContext2 **ppSrcCxt);

// IDebugMemoryContext2 methods
   STDMETHOD(GetName)(BSTR* pbstrName);
   STDMETHOD(GetInfo)(CONTEXT_INFO_FIELDS dwFields, CONTEXT_INFO* pInfo);
   STDMETHOD(Add)(UINT64 dwCount, IDebugMemoryContext2** ppMemCxt);
   STDMETHOD(Subtract)(UINT64 dwCount, IDebugMemoryContext2** ppMemCxt);
   STDMETHOD(Compare)(CONTEXT_COMPARE compare, IDebugMemoryContext2** rgpMemoryContextSet, DWORD dwMemoryContextSetLen, DWORD* pdwMemoryContext);

// IDebugDocumentContext2 methods
   STDMETHOD(GetDocument)(IDebugDocument2 **ppDocument);
   STDMETHOD(GetName)(GETNAME_TYPE gnType, BSTR *pbstrFileName);
   STDMETHOD(EnumCodeContexts)(IEnumDebugCodeContexts2 **ppEnumCodeCxts);
   STDMETHOD(GetLanguageInfo)(BSTR* pbstrLanguage, GUID* pguidLanguage);
   STDMETHOD(GetStatementRange)(TEXT_POSITION* pBegPosition, TEXT_POSITION* pEndPosition);
   STDMETHOD(GetSourceRange)(TEXT_POSITION* pBegPosition, TEXT_POSITION* pEndPosition);
   STDMETHOD(Compare)(DOCCONTEXT_COMPARE compare, IDebugDocumentContext2** rgpDocContextSet, DWORD dwDocContextSetLen, DWORD* pdwDocContext);
STDMETHOD(Seek)(int ncount, IDebugDocumentContext2 **ppDocContext);
protected:
   CComBSTR m_sbstrFileName;
   TEXT_POSITION m_pos;
};

// Context.h : Declaration of the CBreakpointResolution


/////////////////////////////////////////////////////////////////////////////
// CBreakpointResolution
class ATL_NO_VTABLE CBreakpointResolution : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBreakpointResolution, &CLSID_BreakpointResolution>,
	public IDebugBreakpointResolution2
{
public:
	CBreakpointResolution();
	virtual ~CBreakpointResolution();

DECLARE_REGISTRY_RESOURCEID(IDR_BREAKPOINTRESOLUTION1)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CBreakpointResolution)
	COM_INTERFACE_ENTRY(IDebugBreakpointResolution2)
END_COM_MAP()

// IDebugBreakpointResolution2
public:
	void Initialize(IDebugCodeContext2 *pCodeContext);
   STDMETHOD(GetBreakpointType)(BP_TYPE* pBPType);
   STDMETHOD(GetResolutionInfo)(
      BPRESI_FIELDS dwFields,
      BP_RESOLUTION_INFO* pBPResolutionInfo);

public:
   BP_RESOLUTION_INFO m_bpResolutionInfo;
};

#endif //__DEBUGCONTEXT_H_
