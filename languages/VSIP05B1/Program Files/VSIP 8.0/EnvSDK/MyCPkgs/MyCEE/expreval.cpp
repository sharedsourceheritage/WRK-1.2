
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  CExpressionEvaluator 
-----------------------------------------------------------*/
CExpressionEvaluator::CExpressionEvaluator()
{
  TRACE1("create ExprEval: 0x%x", this);
  m_refCount = 1;
}


CExpressionEvaluator::~CExpressionEvaluator()
{
  TRACE1("destroy ExprEval: 0x%x", this);
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP CExpressionEvaluator::QueryInterface( in REFIID iid, out LPVOID* pobj )
{
  OUTARG(pobj);

  if (iid == IID_IUnknown || iid == IID_IDebugExpressionEvaluator)
  {
    TRACE("ExprEval::QueryInterface for IDebugExpressionEvaluator");
    *pobj = static_cast<IDebugExpressionEvaluator*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) CExpressionEvaluator::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CExpressionEvaluator::Release()
{
  if (DecRefCount(&m_refCount) == 0)
  {
    delete this;
    return 0;
  }
  else
    return m_refCount;
}


/*---------------------------------------------------------
  IDebugExpressionEvaluator 
-----------------------------------------------------------*/
STDMETHODIMP CExpressionEvaluator::Parse
  ( in LPCOLESTR               pszExpression,
    in PARSEFLAGS              flags,
    in UINT                    radix,
    out BSTR                    *pbstrErrorMessages,
    inout UINT                  *perrorCount,
    out IDebugParsedExpression  **ppparsedExpression
  )
{
  TRACE1( "ExprEval::Parse %S", pszExpression );
  OUTARG(pbstrErrorMessages);
  INOUTARG(perrorCount);
  OUTARG(ppparsedExpression);

  HRESULT hr;
  hr = ::Parse( pszExpression, pbstrErrorMessages );
  if (hr != S_OK) return hr;

  CParsedExpression* pparsedExpr = new CParsedExpression( radix, flags, pszExpression );
  if (!pparsedExpr) return E_OUTOFMEMORY;

  hr = pparsedExpr->QueryInterface( IID_IDebugParsedExpression, reinterpret_cast<void**>(ppparsedExpression) );
  RELEASE(pparsedExpr);
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP CExpressionEvaluator::GetMethodProperty
  ( in IDebugSymbolProvider    *pprovider,
    in IDebugAddress           *paddress,
    in IDebugBinder            *pbinder,
    in BOOL                    includeHiddenLocals,
    out IDebugProperty2         **ppproperty
  )
{
  TRACE( "ExprEval::GetMethodProperty" );
  OUTARG(ppproperty);
  REFARG(pprovider);

  HRESULT hr;
  IDebugContainerField* pcontainer = NULL;
  
  hr = pprovider->GetContainerField(paddress, &pcontainer);
  if (FAILED(hr)) return hr;
  
  IDebugMethodField*    pmethod    = NULL;  
  hr = pcontainer->QueryInterface( IID_IDebugMethodField, reinterpret_cast<void**>(&pmethod));
  RELEASE(pcontainer);
  if (FAILED(hr)) return hr;

  CFieldProperty* pfieldProperty = new CFieldProperty( pprovider, paddress, pbinder, pmethod );
  RELEASE(pmethod);
  if (!pfieldProperty) return E_OUTOFMEMORY;

  hr = pfieldProperty->Init();
  if (FAILED(hr)) { RELEASE(pfieldProperty); return hr; }

  hr = pfieldProperty->QueryInterface( IID_IDebugProperty2, reinterpret_cast<void**>(ppproperty));
  RELEASE(pfieldProperty);

  return hr;
}

STDMETHODIMP CExpressionEvaluator::GetMethodLocationProperty
  ( in LPCOLESTR			pszFullyQualifiedMethodPlusOffset,
	in IDebugSymbolProvider	*pprovider,
	in IDebugAddress		*paddress,
	in IDebugBinder			*pbinder,
	out IDebugProperty2     **ppproperty
  )
{  
  TRACE1( "ExprEval::GetMethodLocationProperty '%S'", pszFullyQualifiedMethodPlusOffset );
  OUTARG(ppproperty);

  return E_NOTIMPL;
}

STDMETHODIMP CExpressionEvaluator::SetLocale(
    WORD wLangID)
{
    return E_NOTIMPL;
}

STDMETHODIMP CExpressionEvaluator::SetRegistryRoot(
	LPCOLESTR szRegRoot)
{
	return E_NOTIMPL;
}

