
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  CParsedExpression
-----------------------------------------------------------*/
CParsedExpression::CParsedExpression( in DWORD radix, in PARSEFLAGS parseFlags, in LPCOLESTR pszExpr )
{
  TRACE1( "create CParsedExpression: 0x%x", this );
  m_refCount    = 1;
  m_radix       = radix;
  m_parseFlags  = parseFlags;
  m_expr        = SysAllocString(pszExpr);
}

CParsedExpression::~CParsedExpression()
{
  TRACE1( "destroy CParsedExpression: 0x%x", this );
  FREEBSTR(m_expr);
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP CParsedExpression::QueryInterface( in REFIID iid, out LPVOID* pobj )
{
  OUTARG(pobj);

  if (iid == IID_IUnknown || iid == IID_IDebugParsedExpression)
  {
    TRACE("ExprEval::QueryInterface for IDebugParsedExpression");
    *pobj = static_cast<IDebugParsedExpression*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) CParsedExpression::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CParsedExpression::Release()
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
  IDebugParsedExpression
-----------------------------------------------------------*/
STDMETHODIMP CParsedExpression::EvaluateSync( 
                           in DWORD                 evalFlags,
                           in DWORD                 dwTimeout,
                           in IDebugSymbolProvider* pprovider,
                           in IDebugAddress*        paddress,
                           in IDebugBinder*         pbinder,
                           in BSTR                  bstrResultType,
                           out IDebugProperty2**    ppproperty )
{
  // dwTimeout parameter is ignored in this implementation but custom 
  // expression evaluator might implement it.
  TRACE2( "CParsedExpression::EvaluateSync: '%S', bstrResultType: '%S'", m_expr, bstrResultType );
  REFARG(pprovider);
  REFARG(paddress);
  REFARG(pbinder);
  OUTARG(ppproperty);

  HRESULT hr;
  VARIANT value;
  BSTR    bstrErrorMessage = NULL;
  hr = ::Evaluate( pprovider, paddress, pbinder, m_expr, &bstrErrorMessage, &value );
  if (hr != S_OK)
  {
    if (bstrErrorMessage == NULL) return hr;

    //we can display better messages ourselves.
    HRESULT hrLocal = S_OK;
    VARIANT varType;
    VARIANT varErrorMessage;
    
    VariantInit( &varType );
    VariantInit( &varErrorMessage );
    varErrorMessage.vt      = VT_BSTR;
    varErrorMessage.bstrVal = bstrErrorMessage;

    CValueProperty* valueProperty = new CValueProperty();
    if (valueProperty != NULL)
    {
        hrLocal = valueProperty->Init(m_expr, varType, varErrorMessage);
        if (SUCCEEDED(hrLocal)) 
        {
            hrLocal = valueProperty->QueryInterface( IID_IDebugProperty2, reinterpret_cast<void**>(ppproperty) );
        }
    }
   
    VariantClear(&varType);
    VariantClear(&varErrorMessage); //frees BSTR
    if (!valueProperty) return hr;
    RELEASE(valueProperty);
    if (FAILED(hrLocal)) return hr;
  }
  else
  {
    ASSERT( bstrErrorMessage == NULL );
    FREEBSTR(bstrErrorMessage);

    hr = VariantValueToProperty( pprovider, paddress, pbinder, m_radix, m_expr, value, ppproperty );
    VariantClear(&value);
    if (FAILED(hr)) return hr;
  }

  return S_OK;
}

