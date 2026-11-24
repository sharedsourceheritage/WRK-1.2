
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  FieldLookup
-----------------------------------------------------------*/
HRESULT FieldLookup( in  IDebugSymbolProvider* pprovider, 
                     in  IDebugAddress*        paddress, 
                     in  LPCOLESTR             pszName, 
                     out IDebugField**         ppfield )
{
  OUTARG(ppfield);
  REFARG(pszName);
  REFARG(paddress);
  REFARG(pprovider);

  //get the current container
  HRESULT hr;
  IDebugContainerField* pcontainer;
  hr = pprovider->GetContainerField( paddress,  &pcontainer );
  if (FAILED(hr)) return hr;

  //keep looking for a member
  while (pcontainer)
  {
    IEnumDebugFields* pchildren;

    hr = pcontainer->EnumFields( FIELD_KIND_ALL, FIELD_MOD_ALL, pszName, nmCaseSensitive, &pchildren );
    if (hr == S_OK) 
    {      
      ULONG fetched;
      hr = pchildren->Next( 1, ppfield, &fetched );
      RELEASE(pchildren);
      if (hr == S_OK) 
      { 
        RELEASE(pcontainer);
        return S_OK;
      }
    }
  
    //go to the parent and try again
    IDebugContainerField* pparent = NULL;
    hr = pcontainer->GetContainer( &pparent );
    RELEASE(pcontainer);
    if (FAILED(hr)) return hr;
    
    pcontainer = pparent;
  }

  return S_FALSE;
}


/*---------------------------------------------------------
  FieldGetType
-----------------------------------------------------------*/
struct PrimitiveTypeInfo
{
  LPCOLESTR  pszName;
  UINT       size;
  VARTYPE    vt;
};

PrimitiveTypeInfo primitiveTypeTable[] =
{
  { OLE("string"),    0,    VT_BSTR },
  { OLE("whole"),     1,    VT_I1   },
  { OLE("whole"),     2,    VT_I2   },
  { OLE("whole"),     4,    VT_I4   },
  { OLE("whole"),     8,    VT_I8   },
  { OLE("uwhole"),    1,    VT_UI1  },
  { OLE("uwhole"),    2,    VT_UI2  },
  { OLE("uwhole"),    4,    VT_UI4  },
  { OLE("uwhole"),    8,    VT_UI8  },
  { OLE("real"),      4,    VT_R4   },
  { OLE("real"),      8,    VT_R8   },
  { OLE("bool"),      1,    VT_BOOL },
  { OLE("bool"),      2,    VT_BOOL },
  { OLE("bool"),      4,    VT_BOOL },

  { OLE("System.String"),   0,  VT_BSTR },
  { OLE("System.SByte"),    1,  VT_I1   },
  { OLE("System.Int16"),    2,  VT_I2   },
  { OLE("System.Int32"),    4,  VT_I4   },
  { OLE("System.Int64"),    8,  VT_I8   },
  { OLE("System.Byte"),     1,  VT_UI1  },
  { OLE("System.Char"),     1,  VT_UI2  },
  { OLE("System.UInt16"),   2,  VT_UI2  },
  { OLE("System.UInt32"),   4,  VT_UI4  },
  { OLE("System.UInt64"),   8,  VT_UI8  },
  { OLE("System.Single"),   4,  VT_R4   },
  { OLE("System.Double"),   8,  VT_R8   },
  { OLE("System.Boolean"),  1,  VT_BOOL },
  { OLE("System.Boolean"),  2,  VT_BOOL },
  { OLE("System.Boolean"),  4,  VT_BOOL },
  
  { NULL, 0, VT_EMPTY }
};

HRESULT FieldGetType( in IDebugField* pfield, out VARIANT* pvarType )
{
  REFARG(pfield);
  OUTVAR(pvarType);

  HRESULT hr;

  //get type size and name
  DWORD        fieldTypeSize;
  FIELD_INFO   fieldTypeInfo;
  IDebugField* pfieldType = NULL;
  
  hr = pfield->GetType( &pfieldType );
  if (FAILED(hr)) return hr; 
 
  hr = pfieldType->GetSize( &fieldTypeSize );
  if (FAILED(hr)) { RELEASE(pfieldType); return hr; }

  hr = pfieldType->GetInfo( FIF_NAME, &fieldTypeInfo );  
  if (FAILED(hr)) { RELEASE(pfieldType); return hr; }

  //check for primitive types
  memset( pvarType, 0, sizeof(*pvarType) );
  VariantInit(pvarType);

  for (PrimitiveTypeInfo* pprimTypeInfo = primitiveTypeTable; pprimTypeInfo->pszName != NULL; pprimTypeInfo++)
  {
    if (pprimTypeInfo->size == fieldTypeSize && (wcscmp(pprimTypeInfo->pszName,fieldTypeInfo.bstrName) == 0))
    {
      pvarType->vt = pprimTypeInfo->vt;
      break;
    }
  }

  //VT_UNKNOWN is used for all other (structured) types
  if (pvarType->vt == VT_EMPTY)
  {
    pvarType->vt      = VT_UNKNOWN;
    pvarType->punkVal = pfieldType;
    pvarType->punkVal->AddRef();
  }

  FREEBSTR(fieldTypeInfo.bstrName);
  RELEASE(pfieldType);
  return S_OK;
}


/*---------------------------------------------------------
  FieldGetValue
-----------------------------------------------------------*/
HRESULT FieldGetValue( in IDebugField* pfield, out VARIANT* pvarValue )
{
  OUTVAR(pvarValue);
  REFARG(pfield);

  //we delay getting the primitive value by just setting VT_UNKNOWN
  pvarValue->vt      = VT_UNKNOWN;
  pvarValue->punkVal = pfield;
  pvarValue->punkVal->AddRef();

  return S_OK;
}


/*---------------------------------------------------------
  FieldCoerceValueType
-----------------------------------------------------------*/
HRESULT FieldCoerceValueType( in IDebugBinder* pbinder, in IDebugField* pfield, in VARIANT& rawValue, out VARIANT* pvarValue )
{
  OUTVAR(pvarValue);
  REFARG(pfield);
  REFARG(pbinder);
  
  HRESULT hr;
  
  //try to normalize the pvarValue
  hr = VariantValueNormalize( pbinder, rawValue, pvarValue );
  if (FAILED(hr)) 
  {
    hr = VariantCopy( pvarValue, &rawValue );
    if (FAILED(hr)) return hr;
  }
  
  //get the ype
  VARIANT type;
  VariantInit(&type);
  hr = FieldGetType( pfield, &type );
  if (FAILED(hr)) { VariantClear(pvarValue); return hr; }


  bool typeEqual = false;

  //if the value is a structured value, we check equality of the string representation
  if (pvarValue->vt == VT_UNKNOWN && pvarValue->punkVal)
  {
    IDebugField* valueField;
    hr = pvarValue->punkVal->QueryInterface( IID_IDebugField, reinterpret_cast<void**>(&valueField) );
    if (FAILED(hr)) goto fail;

    VARIANT valueType;
    hr = FieldGetType( valueField, &valueType );
    if (FAILED(hr)) goto fail;

    BSTR valueTypeName;
    hr = VariantTypeToString( valueType, &valueTypeName );
    VariantClear(&valueType);
    if (FAILED(hr)) goto fail;

    BSTR typeName;
    hr = VariantTypeToString( type, &typeName );
    if (FAILED(hr)) { FREEBSTR(valueTypeName); goto fail; }

    typeEqual = (wcscmp(typeName, valueTypeName) == 0);
    FREEBSTR(typeName);
    FREEBSTR(valueTypeName);
  }
  else
  {
    //otherwise we check type equality; 
    hr = VariantChangeType( pvarValue, pvarValue, 0, type.vt );
    typeEqual = SUCCEEDED(hr);
  }

fail:
  VariantClear(&type);
  if (FAILED(hr)) { VariantClear(pvarValue); return hr; }

  return (typeEqual ? S_OK : S_FALSE);
}

/*---------------------------------------------------------
  FieldSetValue
-----------------------------------------------------------*/
HRESULT FieldSetValue( in IDebugBinder* pbinder, in IDebugField* pfield, in VARIANT& rawValue )
{
  REFARG(pfield);
  REFARG(pbinder);

  HRESULT       hr     = S_OK;
  IDebugObject* pobject = NULL;
  VARIANT       value;
  VariantInit(&value);
  
  //check the type
  hr = FieldCoerceValueType( pbinder, pfield, rawValue, &value );
  if (FAILED(hr))    goto fail;
  if (hr == S_FALSE) { hr = E_FAIL; goto fail; }
  
  //get the object
  hr = pbinder->Bind( NULL, pfield, &pobject );
  if (FAILED(hr))   goto fail;

  //set the value
  switch (value.vt)
  {
  case VT_BSTR:
    {
      if (value.bstrVal == NULL)
      {
        LPOLESTR pszEmptyStr = OLE("");
        hr = pobject->SetValue( reinterpret_cast<BYTE*>(pszEmptyStr), sizeof(OLECHAR) );
      }
      else
        hr = pobject->SetValue( reinterpret_cast<BYTE*>(value.bstrVal), (SysStringLen(value.bstrVal)+1) * sizeof(wchar_t) );
    }

  case VT_BOOL:
  case VT_I1:
  case VT_UI1:
    hr = pobject->SetValue( reinterpret_cast<BYTE*>(&(value.byref)), 1 );
    break;

  case VT_I2:
  case VT_UI2:
    hr = pobject->SetValue( reinterpret_cast<BYTE*>(&(value.byref)), 2 );
    break;

  case VT_I4:
  case VT_UI4:
  case VT_R4:
    hr = pobject->SetValue( reinterpret_cast<BYTE*>(&(value.byref)), 4 );
    break;

  case VT_I8:
  case VT_UI8:
  case VT_R8:
    hr = pobject->SetValue( reinterpret_cast<BYTE*>(&(value.byref)), 8 );
    break;

  case VT_VOID:
  case VT_EMPTY:
    hr = E_FAIL;
    break;

  case VT_UNKNOWN:
    {
      //this is also a field (structured type)
      ASSERT(value.punkVal);
      if (value.punkVal == NULL) { hr = E_FAIL; goto fail; };

      IDebugField* valueField;
      hr = value.punkVal->QueryInterface( IID_IDebugField, reinterpret_cast<void**>(&valueField) );
      if (FAILED(hr)) goto fail;

      //for MyC we simply copy the bits
      IDebugObject* valueObject;
      hr = pbinder->Bind( NULL, valueField, &valueObject );
      RELEASE(valueField);
      if (FAILED(hr)) goto fail;

      BYTE* pvalueBits;
      UINT  valueSize;
      hr = valueObject->GetSize( &valueSize );
      if (FAILED(hr)) { RELEASE(valueObject); goto fail; }

      pvalueBits = NALLOC(BYTE,valueSize+1);
      if (!pvalueBits) { RELEASE(valueObject); hr = E_OUTOFMEMORY; goto fail; }

      hr = valueObject->GetValue( pvalueBits, valueSize );
      RELEASE(valueObject);
      if (FAILED(hr)) { FREE(pvalueBits); goto fail; }

      hr = pobject->SetValue( pvalueBits, valueSize );
      FREE(pvalueBits);
      if (FAILED(hr)) goto fail;

      break;
    }

  default:
    //not a primitive type
    hr = E_FAIL;
    break;
  }

fail:
  VariantClear( &value );
  RELEASE(pobject);
  if (FAILED(hr)) return hr;

  return S_OK;
}



/*---------------------------------------------------------
  FieldGetPrimitiveValue
-----------------------------------------------------------*/
HRESULT FieldGetPrimitiveValue( in IDebugBinder* pbinder, in IDebugField* pfield, out VARIANT* pvarValue )
{
  OUTVAR(pvarValue);
  REFARG(pfield);
  REFARG(pbinder);

  //get the value as bits
  HRESULT hr;
  UINT          valueSize = 0;
  BYTE*         pvalueBits = NULL;
  IDebugObject* pobject    = NULL;
  
  hr = pbinder->Bind( NULL, pfield, &pobject );
  if (FAILED(hr)) return hr;

  hr = pobject->GetSize( &valueSize );
  if (FAILED(hr)) { RELEASE(pobject); return hr; }

  pvalueBits = NALLOC(BYTE,valueSize);
  if (!pvalueBits) { RELEASE(pobject); return E_OUTOFMEMORY; }

  hr = pobject->GetValue( pvalueBits, valueSize );
  RELEASE(pobject);
  if (FAILED(hr)) { FREE(pvalueBits); return hr; }

  //get the type
  VARIANT     valueType;
  
  hr = FieldGetType( pfield, &valueType );
  if (FAILED(hr)) { FREE(pvalueBits); return hr; }

  //copy a primitive value
  switch (valueType.vt)
  {
  case VT_BSTR:
    {
      pvarValue->vt = VT_BSTR;
      if (valueSize == 0)
        pvarValue->bstrVal = SysAllocString( OLE("") );
      else
        pvarValue->bstrVal = SysAllocStringByteLen( reinterpret_cast<char*>(pvalueBits), valueSize );
    }

  case VT_BOOL:
  case VT_I1:
  case VT_I2:
  case VT_I4:
  case VT_I8:
  case VT_UI1:
  case VT_UI2:
  case VT_UI4:
  case VT_UI8:
  case VT_R4:
  case VT_R8:
    pvarValue->vt = valueType.vt;

    ASSERT(valueSize <= 8); if (valueSize > 8) valueSize = 8;
    memcpy( &(pvarValue->iVal), pvalueBits, valueSize );
    break;

  case VT_VOID:
  case VT_EMPTY:
    pvarValue->vt = valueType.vt;
    break;

  default:
    //not a primitive type
    VariantClear(&valueType);
    FREE(pvalueBits);
    return E_FAIL;
  }

  FREE(pvalueBits);
  VariantClear(&valueType);
  return S_OK; 
}


