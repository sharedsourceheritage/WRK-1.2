
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  CValueProperty
-----------------------------------------------------------*/
CValueProperty::CValueProperty( )
{
  TRACE1( "create CValueProperty: 0x%x", this );
  m_refCount  = 1;
}


HRESULT CValueProperty::Init(in LPCOLESTR pszExpr, in VARIANT& type, in VARIANT& value)
{
  m_expr = SysAllocString(pszExpr);
  if ((pszExpr != NULL) && (wcslen(pszExpr) != 0) && (m_expr == NULL))
      return E_OUTOFMEMORY;
  HRESULT hr = S_OK;

  VariantInit(&m_type);
  VariantInit(&m_value);

  hr = VariantCopy( &m_type, &type );
  if (FAILED(hr))
      return hr;
  hr = VariantCopy( &m_value, &value );  
  return hr;
}

CValueProperty::~CValueProperty()
{
  TRACE1( "destroy CValueProperty: 0x%x", this );
  FREEBSTR(m_expr);
  VariantClear(&m_type);
  VariantClear(&m_value);
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP CValueProperty::QueryInterface( in REFIID iid, out LPVOID* pobj )
{
  OUTARG(pobj);

  if (iid == IID_IUnknown || iid == IID_IDebugProperty2)
  {
    TRACE("CValueProperty::QueryInterface for IDebugProperty2");
    *pobj = static_cast<IDebugProperty2*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) CValueProperty::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CValueProperty::Release()
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
  IDebugValueProperty2
-----------------------------------------------------------*/
STDMETHODIMP CValueProperty::GetPropertyInfo( 
  in DEBUGPROP_INFO_FLAGS infoFlags,
  in DWORD                radix,
  in DWORD                timeout,
  in IDebugReference2**   ppargs,
  in DWORD                argCount,
  out DEBUG_PROPERTY_INFO* ppropertyInfo
  )
{
  TRACE("CValueProperty::GetValuePropertyInfo");
  if (!ppropertyInfo) return E_INVALIDARG;
                else memset(ppropertyInfo,0,sizeof(*ppropertyInfo));

  
  //simple ones
  if (infoFlags & DEBUGPROP_INFO_FULLNAME)
  {
    TRACE1( "-attrib: full name: %S", m_expr );
    ppropertyInfo->dwFields     |= DEBUGPROP_INFO_FULLNAME;
    ppropertyInfo->bstrFullName  = SysAllocString( m_expr );
  }

  if (infoFlags & DEBUGPROP_INFO_NAME)
  {
    TRACE1( "-attrib: name: %S", m_expr );
    ppropertyInfo->dwFields     |= DEBUGPROP_INFO_NAME;
    ppropertyInfo->bstrName     = SysAllocString( m_expr );
  }

  
  if (infoFlags & DEBUGPROP_INFO_TYPE)
  {
    TRACE1( "-attrib: type", m_type );
    ppropertyInfo->dwFields     |= DEBUGPROP_INFO_TYPE;
    if (FAILED(VariantTypeToString( m_type, &(ppropertyInfo->bstrType) )))
      ppropertyInfo->bstrType = SysAllocString( GetString(IDS_MSG_UNKNOWNTYPE) );
  }

  if (infoFlags & DEBUGPROP_INFO_PROP)
  {
    TRACE( "-attrib: property" );
    ppropertyInfo->dwFields     |= DEBUGPROP_INFO_PROP;
    QueryInterface( IID_IDebugProperty2, reinterpret_cast<void**>(&(ppropertyInfo->pProperty)) );
  }


  if (infoFlags & DEBUGPROP_INFO_VALUE)
  {
    TRACE( "-attrib: value" );
    ppropertyInfo->dwFields   |= DEBUGPROP_INFO_VALUE;
    if (FAILED(VariantValueToString( radix, NULL, m_value, &(ppropertyInfo->bstrValue) )))
      ppropertyInfo->bstrValue = SysAllocString( GetString(IDS_MSG_UNKNOWNVALUE) );
  }
  
  // AUTOEXPAND is ignored in MycEE
  if (infoFlags & DEBUGPROP_INFO_VALUE_AUTOEXPAND)
  {
    TRACE( "-attrib: value-autoexpand" );
  }


  if (infoFlags & DEBUGPROP_INFO_ATTRIB)
  {
    TRACE( "-attrib: attributes" );
    ppropertyInfo->dwFields |= DEBUGPROP_INFO_ATTRIB;
    ppropertyInfo->dwAttrib  = DBG_ATTRIB_ACCESS_PUBLIC
                             | DBG_ATTRIB_VALUE_READONLY
                             | DBG_ATTRIB_TYPE_CONSTANT
                             | DBG_ATTRIB_DATA;

    if (m_type.vt == VT_BOOL)
    {
        ppropertyInfo->dwAttrib |= DBG_ATTRIB_VALUE_BOOLEAN;
        if (m_value.boolVal) 
        {
            ppropertyInfo->dwAttrib |= DBG_ATTRIB_VALUE_BOOLEAN_TRUE;
        }
    }
  }
 
  return S_OK;
}

STDMETHODIMP CValueProperty::SetValueAsString( 
    in LPCOLESTR pszValue,
    in DWORD     radix,
    in DWORD     timeout
    )
{
  TRACE1("CValueProperty::SetValueAsString: '%S'", pszValue );
  return E_FAIL;
}


STDMETHODIMP CValueProperty::SetValueAsReference( 
    in IDebugReference2** ppargs,
    in DWORD              argCount,
    in IDebugReference2*  pvalue,
    in DWORD              timeout
    )
{
  TRACE("CValueProperty::SetValueAsReference");
  return E_NOTIMPL;
}


STDMETHODIMP CValueProperty::EnumChildren( 
    in DEBUGPROP_INFO_FLAGS infoFlags,
    in DWORD                radix,
    in REFGUID              guidFilter,
    in DBG_ATTRIB_FLAGS     attribFilter,
    in LPCOLESTR            pszNameFilter,
    in DWORD                timeout,
    out IEnumDebugPropertyInfo2 ** ppchildren )
{
  TRACE("CValueProperty::EnumChildren");
  OUTARG(ppchildren);
  return E_FAIL;
}

/*---------------------------------------------------------
  IDebugProperty2: simple properties
-----------------------------------------------------------*/
STDMETHODIMP CValueProperty::GetParent( out IDebugProperty2 **ppparent)
{
  TRACE("CValueProperty::GetParent");
  OUTARG(ppparent);

  return E_FAIL;
}


STDMETHODIMP CValueProperty::GetDerivedMostProperty( out IDebugProperty2 **ppderivedMost)
{
  TRACE("CValueProperty::GetDerivedMostProperty");
  OUTARG(ppderivedMost);

  return E_NOTIMPL;
}


STDMETHODIMP CValueProperty::GetMemoryBytes( out IDebugMemoryBytes2 **ppmemoryBytes)
{
  TRACE("CValueProperty::GetMemoryBytes");
  OUTARG(ppmemoryBytes);

  return E_NOTIMPL;
}


STDMETHODIMP CValueProperty::GetMemoryContext( out IDebugMemoryContext2 **ppmemory)
{
  TRACE("CValueProperty::GetMemoryContext");
  OUTARG(ppmemory);

  return E_NOTIMPL;
}


STDMETHODIMP CValueProperty::GetSize( out DWORD *psize)
{
  TRACE("CValueProperty::GetSize");
  OUTARG(psize);

  return E_NOTIMPL;
}


STDMETHODIMP CValueProperty::GetReference( out IDebugReference2 **ppreference)
{
  TRACE("CValueProperty::GetReference");
  OUTARG(ppreference);

  return E_NOTIMPL;
}


STDMETHODIMP CValueProperty::GetExtendedInfo( in REFGUID  guidExtendedInfo, out VARIANT *pvarExtendedInfo)
{
  TRACE("CValueProperty::GetExtendedInfo");
  if (!pvarExtendedInfo) return E_INVALIDARG;
               else  VariantClear(pvarExtendedInfo);

  return E_NOTIMPL;
}



