
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


// Context.cpp : Implementation of CDebugContext
#include "stdafx.h"
#include "TextInterpreter.h"
#include "Context.h"

/////////////////////////////////////////////////////////////////////////////
// CDebugContext

// IDebugMemoryContext2 methods
HRESULT CDebugContext::GetInfo(CONTEXT_INFO_FIELDS dwFields, CONTEXT_INFO* pInfo)
{ return E_NOTIMPL; }
HRESULT CDebugContext::Add(UINT64 dwCount, IDebugMemoryContext2** ppMemCxt)
{ return E_NOTIMPL; }
HRESULT CDebugContext::Subtract(UINT64 dwCount, IDebugMemoryContext2** ppMemCxt)
{ return E_NOTIMPL; }
HRESULT CDebugContext::Compare(CONTEXT_COMPARE compare, IDebugMemoryContext2** rgpMemoryContextSet, DWORD dwMemoryContextSetLen, DWORD* pdwMemoryContext)
{ return E_NOTIMPL; }

// IDebugDocumentContext2 methods
HRESULT CDebugContext::GetDocument(IDebugDocument2 **ppDocument)
{ return E_NOTIMPL; }
HRESULT CDebugContext::GetName(BSTR* pbstrName)
{ return E_NOTIMPL; }
HRESULT CDebugContext::EnumCodeContexts(IEnumDebugCodeContexts2 **ppEnumCodeCxts)
{ return E_NOTIMPL; }
HRESULT CDebugContext::GetLanguageInfo(BSTR* pbstrLanguage, GUID* pguidLanguage)
{ return E_NOTIMPL; }
HRESULT CDebugContext::Compare(DOCCONTEXT_COMPARE compare, IDebugDocumentContext2** rgpDocContextSet, DWORD dwDocContextSetLen, DWORD* pdwDocContext)
{ return E_NOTIMPL; }
HRESULT CDebugContext::Seek(int ncount, IDebugDocumentContext2 **ppDocContext)
{return E_NOTIMPL;}

// IDebugCodeContext2 methods

void CDebugContext::Initialize(LPCWSTR pszFileName, TEXT_POSITION &pos)
{
   m_sbstrFileName = pszFileName;
   memcpy(&m_pos, &pos, sizeof(TEXT_POSITION));
}

HRESULT CDebugContext::GetDocumentContext(IDebugDocumentContext2 **ppSrcCxt)
{ 
   *ppSrcCxt = (IDebugDocumentContext2 *) this;
   (*ppSrcCxt)->AddRef();

   return S_OK; 
} 

HRESULT CDebugContext::GetName(GETNAME_TYPE gnType, BSTR *pbstrFileName)
{ 
   *pbstrFileName = SysAllocString(m_sbstrFileName);
   return S_OK; 
}

HRESULT CDebugContext::GetSourceRange(TEXT_POSITION* pBegPosition, TEXT_POSITION* pEndPosition)
{ 
   if (pBegPosition)
      memcpy(pBegPosition, &m_pos, sizeof(TEXT_POSITION));
   if (pEndPosition)
      memcpy(pEndPosition, &m_pos, sizeof(TEXT_POSITION));
   return S_OK; 
}
HRESULT CDebugContext::GetStatementRange(TEXT_POSITION* pBegPosition, TEXT_POSITION* pEndPosition)
{ 
   return GetSourceRange(pBegPosition, pEndPosition); 
}

/////////////////////////////////////////////////////////////////////////////
// CBreakpointResolution

// IDebugBreakpointResolution2
HRESULT CBreakpointResolution::GetBreakpointType(BP_TYPE* pBPType)
{ 
	return BPT_CODE; 
}

HRESULT CBreakpointResolution::GetResolutionInfo(BPRESI_FIELDS dwFields, BP_RESOLUTION_INFO* pBPResolutionInfo)
{ 
	// Start with a raw copy
   memcpy(pBPResolutionInfo, &m_bpResolutionInfo, sizeof(BP_RESOLUTION_INFO));

   // Set the fields.
   pBPResolutionInfo->dwFields =
      dwFields & m_bpResolutionInfo.dwFields;

   // Fill in the bp resolution destination
   if (pBPResolutionInfo->dwFields & BPRESI_BPRESLOCATION)
   {
      pBPResolutionInfo->
      bpResLocation.bpResLocation.bpresCode.pCodeContext->AddRef();
      return S_OK;
   }

   return E_NOTIMPL; 
}

void CBreakpointResolution::Initialize(IDebugCodeContext2 *pCodeContext)
{
   m_bpResolutionInfo.bpResLocation.bpResLocation.bpresCode.pCodeContext = pCodeContext;
   m_bpResolutionInfo.bpResLocation.bpResLocation.bpresCode.pCodeContext->AddRef();
}


CBreakpointResolution::CBreakpointResolution()
{
   memset(&m_bpResolutionInfo, 0, sizeof(BP_RESOLUTION_INFO));

   m_bpResolutionInfo.bpResLocation.bpType = BPT_CODE;
   m_bpResolutionInfo.dwFields = BPRESI_BPRESLOCATION;
}

CBreakpointResolution::~CBreakpointResolution()
{
   m_bpResolutionInfo.bpResLocation.bpResLocation.bpresCode.pCodeContext->Release();
}
