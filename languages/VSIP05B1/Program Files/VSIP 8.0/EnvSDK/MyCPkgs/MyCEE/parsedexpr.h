
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

/*---------------------------------------------------------
  Class CParsedExpression
-----------------------------------------------------------*/
class CParsedExpression : public IDebugParsedExpression
{
private:
  ULONG       m_refCount;
  DWORD       m_radix;
  PARSEFLAGS  m_parseFlags;
  BSTR        m_expr;

public:
  CParsedExpression( in DWORD radix, in PARSEFLAGS parseFlags, in LPCOLESTR pszExpr );
  ~CParsedExpression();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out LPVOID* pobj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IDebugParsedExpression
  STDMETHODIMP EvaluateSync( in DWORD                 evalFlags,
                             in DWORD                 dwTimeout,
                             in IDebugSymbolProvider* pprovider,
                             in IDebugAddress*        paddress,
                             in IDebugBinder*         pbinder,
                             in BSTR                  bstrResultType,
                             out IDebugProperty2**    ppproperty );
};
