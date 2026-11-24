
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once


/*---------------------------------------------------------
  CValueProperty
-----------------------------------------------------------*/
class CValueProperty : public IDebugProperty2
{
private:
  ULONG   m_refCount;
  BSTR    m_expr;
  VARIANT m_type;
  VARIANT m_value;

public:
  CValueProperty();
  HRESULT Init(in LPCOLESTR pszExpr, in VARIANT& type, in VARIANT& value);
  ~CValueProperty();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out LPVOID* pobj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IDebugProperty2
  STDMETHODIMP GetPropertyInfo( 
    in DEBUGPROP_INFO_FLAGS infoFlags,
    in DWORD                radix,
    in DWORD                timeout,
    in IDebugReference2**   ppargs,
    in DWORD                argCount,
    out DEBUG_PROPERTY_INFO* ppropertyInfo
    );
  
  STDMETHODIMP SetValueAsString( 
      in LPCOLESTR pszValue,
      in DWORD     radix,
      in DWORD     timeout
      );
  
  STDMETHODIMP SetValueAsReference( 
      in IDebugReference2** ppargs,
      in DWORD              argCount,
      in IDebugReference2*  pvalue,
      in DWORD              timeout
      );
  
  STDMETHODIMP EnumChildren( 
      in DEBUGPROP_INFO_FLAGS infoFlags,
      in DWORD                radix,
      in REFGUID              guidFilter,
      in DBG_ATTRIB_FLAGS     attribFilter,
      in LPCOLESTR            pszNameFilter,
      in DWORD                timeout,
      out IEnumDebugPropertyInfo2 ** ppchildren );
  
  STDMETHODIMP GetParent( out IDebugProperty2 **ppparent);
  STDMETHODIMP GetDerivedMostProperty( out IDebugProperty2 **ppderivedMost);
  STDMETHODIMP GetMemoryBytes( out IDebugMemoryBytes2 **ppmemoryBytes);
  STDMETHODIMP GetMemoryContext( out IDebugMemoryContext2 **ppmemory);
  STDMETHODIMP GetSize( out DWORD *psize);  
  STDMETHODIMP GetReference( out IDebugReference2 **ppreference);  
  STDMETHODIMP GetExtendedInfo( in REFGUID  guidExtendedInfo, out VARIANT *pvarExtendedInfo);        
};
