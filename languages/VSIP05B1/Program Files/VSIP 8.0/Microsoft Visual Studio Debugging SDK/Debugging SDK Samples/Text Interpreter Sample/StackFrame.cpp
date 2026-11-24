
/***************************************************************************
         Copyright  Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// StackFrame.cpp : Implementation of CStackFrame
#include "stdafx.h"
#include "TextInterpreter.h"
#include "StackFrame.h"

/////////////////////////////////////////////////////////////////////////////
// CStackFrame

HRESULT CStackFrame::GetCodeContext(IDebugCodeContext2 **ppCodeCxt)
{ return E_NOTIMPL; }
HRESULT CStackFrame::GetName(BSTR* pbstrName)
{ return E_NOTIMPL; }
HRESULT CStackFrame::GetInfo(
   FRAMEINFO_FLAGS dwFieldSpec, UINT nRadix, FRAMEINFO *pFrameInfo)
{ return E_NOTIMPL; }
HRESULT CStackFrame::GetPhysicalStackRange(
   UINT64* paddrMin, UINT64* paddrMax)
{ return E_NOTIMPL; }
HRESULT CStackFrame::GetExpressionContext(
   IDebugExpressionContext2 **ppExprCxt)
{ return E_NOTIMPL; }
HRESULT CStackFrame::GetLanguageInfo(
   BSTR* pbstrLanguage, GUID* pguidLanguage)
{ return E_NOTIMPL; }
HRESULT CStackFrame::GetDebugProperty(IDebugProperty2 **ppDebugProp)
{ return E_NOTIMPL; }
HRESULT CStackFrame::EnumProperties(
   DEBUGPROP_INFO_FLAGS dwFields, UINT nRadix, REFGUID guidFilter,    DWORD dwTimeout, ULONG *pcelt, IEnumDebugPropertyInfo2 **ppepi)
{ return E_NOTIMPL; }
HRESULT CStackFrame::GetThread(IDebugThread2** ppThread)
{ return E_NOTIMPL; }

HRESULT CStackFrame::GetDocumentContext(IDebugDocumentContext2 **ppCxt)
{ 
   *ppCxt = m_spDocContext;
   (*ppCxt)->AddRef();

   return S_OK; 
}

void CStackFrame::Init(IDebugDocumentContext2* pDocContext)
{   
   m_spDocContext = pDocContext;
}

/////////////////////////////////////////////////////////////////////////////
// CEnumFrameInfo

HRESULT CEnumFrameInfo::Skip(ULONG celt)
{ return E_NOTIMPL; }
HRESULT CEnumFrameInfo::Clone(IEnumDebugFrameInfo2** ppEnum)
{ return E_NOTIMPL; }

HRESULT CEnumFrameInfo::Reset()
{ return S_OK; }

HRESULT CEnumFrameInfo::GetCount(ULONG* pcelt)
{ 
   *pcelt = 1;
   return S_OK; 
}

// Return one frame.
HRESULT CEnumFrameInfo::Next(ULONG celt, FRAMEINFO *rgelt, ULONG* pceltFetched)
{ 
   if (celt == 0 || celt > 1)
      return E_NOTIMPL;

   CopyEnumElement(&rgelt[0], &m_FrameInfo);
   *pceltFetched = 1;
   
   return S_OK; 
}

void CEnumFrameInfo::FinalRelease()
{
   SysFreeString(m_FrameInfo.m_bstrLanguage);
   SysFreeString(m_FrameInfo.m_bstrFuncName);
   (m_FrameInfo.m_pFrame)->Release();
}

// Copy source FRAMEINFO to destination FRAMEINFO.
void CEnumFrameInfo::CopyEnumElement(FRAMEINFO* pDest, FRAMEINFO* pSrc)
{
   // Start with rough copy.
   memcpy(pDest, pSrc, sizeof(FRAMEINFO));

   pDest->m_bstrFuncName = SysAllocString(pSrc->m_bstrFuncName);
   pDest->m_bstrLanguage = SysAllocString(pSrc->m_bstrLanguage);

   pDest->m_pFrame = pSrc->m_pFrame;
   if (pDest->m_pFrame)
      pDest->m_pFrame->AddRef();
}

// Copy source FRAMEINFO to member FRAMEINFO.
void CEnumFrameInfo::Init(FRAMEINFO *pFrameInfo)
{
   CopyEnumElement(&m_FrameInfo, pFrameInfo);
}
