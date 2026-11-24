
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include <limits.h>


/*---------------------------------------------------------
  VariantValueToProperty
-----------------------------------------------------------*/
HRESULT VariantValueToProperty( in IDebugSymbolProvider* pprovider,
                                in IDebugAddress*        paddress,
                                in IDebugBinder*         pbinder,
                                in DWORD                 radix,
                                in LPCOLESTR             pszExpr,
                                in VARIANT&              value, 
                                out IDebugProperty2**    ppproperty )
{
  OUTARG(ppproperty);
  HRESULT hr;

  if (value.vt == VT_UNKNOWN)
  {
    ASSERT(value.punkVal);
    IDebugField* pfield = NULL;

    hr = value.punkVal->QueryInterface( IID_IDebugField, reinterpret_cast<void**>(&pfield) );
    if (FAILED(hr)) return hr;

    CFieldProperty* pprop = new CFieldProperty( pprovider, paddress, pbinder, pfield );
    RELEASE(pfield);
    if (!pprop) return E_OUTOFMEMORY;

    hr = pprop->Init();
    if (FAILED(hr)) { RELEASE(pprop); return hr; }

    hr = pprop->QueryInterface( IID_IDebugProperty2, reinterpret_cast<void**>(ppproperty) );
    RELEASE(pprop);
    if (FAILED(hr)) return hr;
  }
  else
  {
    VARIANT type;
    VariantInit(&type);
    type.vt = value.vt;

    CValueProperty* pvalueProperty = new CValueProperty();
    if (!pvalueProperty) return E_OUTOFMEMORY;
    hr = pvalueProperty->Init(pszExpr, type, value );
    if (SUCCEEDED(hr))
        hr = pvalueProperty->QueryInterface( IID_IDebugProperty2, reinterpret_cast<void**>(ppproperty) );
    RELEASE(pvalueProperty);
    if (FAILED(hr)) return hr;
  }

  return S_OK;
}

/*---------------------------------------------------------
  VariantValueCoerce:
-----------------------------------------------------------*/
HRESULT VariantValueCoerce( in IDebugBinder* pbinder, in VARTYPE type, in VARIANT& var, out VARIANT* pvarResult )
{
  if (!pvarResult) return E_INVALIDARG;
  if (pvarResult != &var) VariantInit(pvarResult);
  REFARG(pbinder);
  HRESULT hr;
  
  //if we want a primitive type
  if (type != VT_UNKNOWN) 
  {
    //normalize it first
    hr = VariantValueNormalize( pbinder, var, pvarResult );
    if (FAILED(hr)) return hr;

    hr = VariantChangeType( pvarResult, pvarResult, 0, type );
    if (FAILED(hr)) return hr;
  }
  else
  {
    hr = VariantChangeType( pvarResult, &var, 0, type );
    if (FAILED(hr)) return hr;
  }
  
  return S_OK;
}


/*---------------------------------------------------------
  VariantValueNormalize
-----------------------------------------------------------*/
HRESULT VariantValueNormalize( in IDebugBinder* pbinder, in VARIANT& value, out VARIANT* pvarResult )
{
  if (!pvarResult) return E_INVALIDARG;
  if (pvarResult != &value) VariantInit(pvarResult);
  HRESULT hr;

  if (value.vt == VT_UNKNOWN && value.punkVal)
  {
   IDebugField* pfield;
    hr = value.punkVal->QueryInterface( IID_IDebugField, reinterpret_cast<void**>(&pfield) );
    if (FAILED(hr)) return hr;

    hr = FieldGetPrimitiveValue( pbinder, pfield, pvarResult );
    RELEASE(pfield);
    if (FAILED(hr)) return hr;
  }
  else if (pvarResult != &value)
  {
    hr = VariantCopy( pvarResult, &value );
    if (FAILED(hr)) return hr;
  }

  return S_OK;
}
  


/*---------------------------------------------------------
  VariantTypeToString
-----------------------------------------------------------*/
HRESULT VariantTypeToString( in VARIANT& type, out BSTR* pbstrTypeName )
{
  OUTARG(pbstrTypeName);
  
  switch (type.vt)
  {
  case VT_BSTR:   *pbstrTypeName = SysAllocString( OLE("string") ); break;
  case VT_BOOL:   *pbstrTypeName = SysAllocString( OLE("bool") ); break;

  case VT_I1:     *pbstrTypeName = SysAllocString( OLE("signed byte") ); break;
  case VT_UI1:    *pbstrTypeName = SysAllocString( OLE("byte") ); break;

  case VT_I2:     *pbstrTypeName = SysAllocString( OLE("short") ); break;
  case VT_I4:     *pbstrTypeName = SysAllocString( OLE("int") ); break;
  case VT_I8:     *pbstrTypeName = SysAllocString( OLE("int64") ); break;

  case VT_UI2:    *pbstrTypeName = SysAllocString( OLE("char") ); break;
  case VT_UI4:    *pbstrTypeName = SysAllocString( OLE("unsigned int") ); break;
  case VT_UI8:    *pbstrTypeName = SysAllocString( OLE("unsigned int64") ); break;

  case VT_R4:     *pbstrTypeName = SysAllocString( OLE("float") ); break;
  case VT_R8:     *pbstrTypeName = SysAllocString( OLE("double") ); break;

  case VT_VOID:   *pbstrTypeName = SysAllocString( OLE("void") ); break;
  case VT_EMPTY:  *pbstrTypeName = SysAllocString( OLE("") );  break;

  case VT_UNKNOWN: 
    {
      ASSERT(type.punkVal);
      if (type.punkVal == NULL) return E_INVALIDARG;
        
      HRESULT hr;
      IDebugField*  pfieldType;
      FIELD_INFO    fieldTypeInfo;
      hr = type.punkVal->QueryInterface( IID_IDebugField, reinterpret_cast<void**>(&pfieldType) );
      if (FAILED(hr)) return hr;
  
      hr = pfieldType->GetInfo( FIF_NAME, &fieldTypeInfo );
      RELEASE(pfieldType);
      if (FAILED(hr)) return hr;

      *pbstrTypeName = fieldTypeInfo.bstrName;
      break;
    }

  default:          
    {
      if (type.vt & VT_BYREF)
        *pbstrTypeName = SysAllocString( OLE("(pointer)") ); 
      else
        return E_FAIL;
      break;
    }
  }
  
  return S_OK;
}


/*---------------------------------------------------------
  VariantValueToString
-----------------------------------------------------------*/
HRESULT VariantValueToString( in DWORD radix, in IDebugBinder* pbinder, in VARIANT& value, out BSTR* pbstrValueStr )
{
  OUTARG(pbstrValueStr);
  
  OLECHAR szBuffer[128];
  szBuffer[0] = 0;

  switch (value.vt)
  {
  case VT_BSTR:
    *pbstrValueStr = SysAllocString(value.bstrVal);
    break;

  case VT_BOOL:
    if (value.boolVal == 0) *pbstrValueStr = SysAllocString( GetString(IDS_MSG_VALUEFALSE) );
                      else  *pbstrValueStr = SysAllocString( GetString(IDS_MSG_VALUETRUE) );
    break;

  case VT_I1:
    if (radix == 16) swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("0x%hx"), value.cVal );
                else swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%c"), value.cVal );
    break;
  case VT_I2:
    if (radix == 16) swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("0x%hx"), value.iVal );
                else swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%hi"), value.iVal );
    break;
  case VT_I4:
    if (radix == 16) swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("0x%x"), value.lVal );
                else swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%i"), value.lVal );
    break;
  case VT_I8:
    if (radix == 16) swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("0x%I64x"), value.llVal );
                else swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%I64i"), value.llVal );
    break;

  case VT_UI1:
    if (radix == 16) swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("0x%hx"), value.bVal );
                else swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%hu"), value.bVal );
    break;
  case VT_UI2:
    if (radix == 16) swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("0x%hx"), value.uiVal );
                else swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%hu"), value.uiVal );
    break;
  case VT_UI4:
    if (radix == 16) swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("0x%x"), value.ulVal );
                else swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%u"), value.ulVal );
    break;
  case VT_UI8:
    if (radix == 16) swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("0x%I64x"), value.ullVal );
                else swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%I64u"), value.ullVal );
    break;

  case VT_R4:
    swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%g"), (double)value.fltVal );
    break;
  case VT_R8:
    swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("%g"), value.dblVal );
    break;

  case VT_VOID:
    *pbstrValueStr = SysAllocString( OLE("(void)") );
    break;

  case VT_EMPTY:
    *pbstrValueStr = SysAllocString( OLE("") );
    break;

  case VT_UNKNOWN:
    {
      //this is a structured value (but MyC can only deal with primitive ones)
      ASSERT(value.punkVal);
      if (value.punkVal == NULL) return E_FAIL;
      
      HRESULT hr;
      IDebugField* pfield;

      hr = value.punkVal->QueryInterface( IID_IDebugField, reinterpret_cast<void**>(&pfield) );
      if (FAILED(hr)) return hr;

      VARIANT primValue;
      hr = FieldGetPrimitiveValue( pbinder, pfield, &primValue );
      RELEASE(pfield);
      if (FAILED(hr)) return hr;

      hr = VariantValueToString( radix, pbinder, primValue, pbstrValueStr );
      VariantClear(&primValue);
      if (FAILED(hr)) return hr;
      break;
    }

  default:
    if (value.vt & VT_BYREF)
      swprintf( szBuffer, NUMBER_OF(szBuffer), OLE("0x%p (pointer)"), value.byref );
    else
    {
      if (radix == 16) 
          _snwprintf(szBuffer, 127, OLE("0x%x %s"), value.ulVal, GetString(IDS_MSG_UNKNOWNVALUEBITS) );
      else 
          _snwprintf(szBuffer, 127, OLE("%i %s"), value.ulVal, GetString(IDS_MSG_UNKNOWNVALUEBITS) );
      szBuffer[127] = L'\0';
    }
    break;
  }

  if (*pbstrValueStr == NULL)
  {
    if (szBuffer[0] == 0) 
      return E_FAIL;
    else
      *pbstrValueStr = SysAllocString( szBuffer );
  }

  return S_OK;
}

