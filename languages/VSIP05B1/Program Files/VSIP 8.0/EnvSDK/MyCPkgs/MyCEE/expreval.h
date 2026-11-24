
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

/*---------------------------------------------------------
  Class CExpressionEvaluator 
-----------------------------------------------------------*/
class CExpressionEvaluator : public IDebugExpressionEvaluator
{
private:
  ULONG   m_refCount;

public:
  CExpressionEvaluator();
  ~CExpressionEvaluator();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out LPVOID* pobj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IDebugExpressionEvaluator
  STDMETHODIMP Parse
    ( in LPCOLESTR               pszExpression,
      in PARSEFLAGS              flags,
      in UINT                    radix,
      out BSTR                    *pbstrErrorMessages,
      out UINT                    *perrorCount,
      out IDebugParsedExpression  **ppparsedExpression
    );

  STDMETHODIMP GetMethodProperty
    ( in IDebugSymbolProvider    *pprovider,
      in IDebugAddress           *paddress,
      in IDebugBinder            *pbinder,
      in BOOL                    includeHiddenLocals,
      out IDebugProperty2         **ppproperty
    );

  STDMETHODIMP GetMethodLocationProperty
	( in LPCOLESTR				pszFullyQualifiedMethodPlusOffset,
	  in IDebugSymbolProvider	*pprovider,
	  in IDebugAddress			*paddress,
	  in IDebugBinder			*pbinder,
	  out IDebugProperty2 		**ppproperty
	);

  STDMETHODIMP SetLocale(
      WORD wLangID);

  STDMETHODIMP SetRegistryRoot( 
	  LPCOLESTR in_szRegistryRoot );
};
