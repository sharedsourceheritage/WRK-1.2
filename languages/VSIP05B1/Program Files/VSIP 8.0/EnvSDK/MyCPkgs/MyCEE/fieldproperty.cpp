
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  CFieldProperty
-----------------------------------------------------------*/
CFieldProperty::CFieldProperty( 
          in IDebugSymbolProvider *pprovider,
          in IDebugAddress        *paddress,
          in IDebugBinder         *pbinder,
          in IDebugField          *pfield
        )
{
  TRACE1( "create CFieldProperty: 0x%x", this );
  ASSERT(pprovider);
  ASSERT(paddress);
  ASSERT(pfield);

  m_refCount  = 1;
  m_provider  = pprovider;  ADDREF(m_provider);
  m_address   = paddress;   ADDREF(m_address);
  m_field     = pfield;     ADDREF(m_field);
  m_binder    = pbinder;    if (m_binder) m_binder->AddRef();    //no ASSERT since pbinder is allowed to be NULL
  
  m_fieldKind = FIELD_KIND_NONE;
  memset( &m_fieldInfo, 0, sizeof(m_fieldInfo));
}

CFieldProperty::~CFieldProperty()
{
  TRACE1( "destroy CFieldProperty: 0x%x", this );
  Done();
  RELEASE(m_provider);
  RELEASE(m_address);
  RELEASE(m_binder);
  RELEASE(m_field);
}

HRESULT CFieldProperty::Init()
{
  HRESULT hr;
  if (!m_provider) return E_FAIL;
  if (!m_address)  return E_FAIL;
  if (!m_field)    return E_FAIL;

  hr = m_field->GetKind( &m_fieldKind );
  if (FAILED(hr)) return hr;

  hr = m_field->GetInfo( FIF_ALL, &m_fieldInfo );
  if (FAILED(hr)) return hr;

  return S_OK;
}

HRESULT CFieldProperty::Done()
{
  FREEBSTR(m_fieldInfo.bstrFullName);
  FREEBSTR(m_fieldInfo.bstrName);
  FREEBSTR(m_fieldInfo.bstrType);
  return S_OK;
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP CFieldProperty::QueryInterface( in REFIID iid, out LPVOID* pobj )
{
  OUTARG(pobj);

  if (iid == IID_IUnknown || iid == IID_IDebugProperty2)
  {
    TRACE("CFieldProperty::QueryInterface for IDebugProperty2");
    *pobj = static_cast<IDebugProperty2*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) CFieldProperty::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CFieldProperty::Release()
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
  IDebugProperty2
-----------------------------------------------------------*/
STDMETHODIMP CFieldProperty::GetPropertyInfo( 
  in DEBUGPROP_INFO_FLAGS infoFlags,
  in DWORD                radix,
  in DWORD                timeout,
  in IDebugReference2**   ppargs,
  in DWORD                argCount,
  out DEBUG_PROPERTY_INFO* ppropertyInfo
  )
{
  TRACE("CFieldProperty::GetPropertyInfo");
  if (!ppropertyInfo) return E_INVALIDARG;
                else memset(ppropertyInfo,0,sizeof(*ppropertyInfo));

  if (infoFlags & DEBUGPROP_INFO_FULLNAME)
  {
    TRACE1( "-attrib: full name: %S", m_fieldInfo.bstrFullName );
    ASSERT(m_fieldInfo.bstrFullName);
    ppropertyInfo->dwFields     |= DEBUGPROP_INFO_FULLNAME;
    ppropertyInfo->bstrFullName  = SysAllocString( m_fieldInfo.bstrFullName );
  }

  if (infoFlags & DEBUGPROP_INFO_NAME)
  {
    TRACE1( "-attrib: name: %S", m_fieldInfo.bstrName );
    ASSERT(m_fieldInfo.bstrName);
    ppropertyInfo->dwFields     |= DEBUGPROP_INFO_NAME;
    ppropertyInfo->bstrName     = SysAllocString( m_fieldInfo.bstrName );
  }

  
  if (infoFlags & DEBUGPROP_INFO_TYPE)
  {
    TRACE1( "-attrib: type: %S", m_fieldInfo.bstrType );
    ASSERT(m_fieldInfo.bstrType);
    ppropertyInfo->dwFields     |= DEBUGPROP_INFO_TYPE;

    VARIANT type;
    if (SUCCEEDED(FieldGetType( m_field, &type )))
    {      
       VariantTypeToString( type, &(ppropertyInfo->bstrType) );
       VariantClear(&type);

    }
    if (ppropertyInfo->bstrType == NULL) 
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

    //only show primitive values
    VARIANT value;
    if (SUCCEEDED(FieldGetValue(m_field, &value)))
    {
      VariantValueToString( radix, m_binder, value, &(ppropertyInfo->bstrValue) );
      VariantClear(&value);
    }

    if (ppropertyInfo->bstrValue == NULL) 
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
    ppropertyInfo->dwFields   |= DEBUGPROP_INFO_ATTRIB;
    
    FIELD_MODIFIERS   modifiers = m_fieldInfo.dwModifiers;
    DBG_ATTRIB_FLAGS  attrib    = DBG_ATTRIB_NONE;
    
    //access    
    if (modifiers & FIELD_MOD_ACCESS_PUBLIC)     attrib |= DBG_ATTRIB_ACCESS_PUBLIC;
    if (modifiers & FIELD_MOD_ACCESS_PRIVATE)    attrib |= DBG_ATTRIB_ACCESS_PRIVATE;
    if (modifiers & FIELD_MOD_ACCESS_PROTECTED)  attrib |= DBG_ATTRIB_ACCESS_PROTECTED;
    if (modifiers & FIELD_MOD_FINAL)             attrib |= DBG_ATTRIB_ACCESS_FINAL;
    
    //constant
    if (modifiers & FIELD_MOD_CONSTANT)          attrib |= DBG_ATTRIB_VALUE_READONLY;

    //storage
    if (m_fieldKind & FIELD_SYM_GLOBAL)          attrib |= DBG_ATTRIB_STORAGE_GLOBAL;
    if (modifiers & FIELD_MOD_STATIC)            attrib |= DBG_ATTRIB_STORAGE_STATIC;

    //type modifier
    if (modifiers & FIELD_MOD_VIRTUAL)           attrib |= DBG_ATTRIB_TYPE_VIRTUAL;
    if (modifiers & FIELD_MOD_CONSTANT)          attrib |= DBG_ATTRIB_TYPE_CONSTANT;
    if (modifiers & FIELD_MOD_SYNCHRONIZED)      attrib |= DBG_ATTRIB_TYPE_SYNCHRONIZED;
    if (modifiers & FIELD_MOD_VOLATILE)          attrib |= DBG_ATTRIB_TYPE_VOLATILE;

    //type
    if (m_fieldKind & FIELD_TYPE_METHOD)         attrib |= DBG_ATTRIB_METHOD;
    if (m_fieldKind & FIELD_TYPE_PROP)           attrib |= DBG_ATTRIB_PROPERTY;
    if (m_fieldKind & FIELD_TYPE_CLASS)          attrib |= DBG_ATTRIB_CLASS;
    if (m_fieldKind & FIELD_TYPE_INTERFACE)      attrib |= DBG_ATTRIB_INTERFACE;
    if (m_fieldKind & FIELD_TYPE_INNERCLASS)     attrib |= DBG_ATTRIB_INNERCLASS;
    if (m_fieldKind & FIELD_KIND_SYMBOL)         attrib |= DBG_ATTRIB_DATA;

    //set the debug attributes
    ppropertyInfo->dwAttrib = attrib;
  }
 
    
  return S_OK;
}

STDMETHODIMP CFieldProperty::SetValueAsString( 
    in LPCOLESTR pszValueStr,
    in DWORD     radix,
    in DWORD     timeout
    )
{
  TRACE1("CFieldProperty::SetValueAsString: '%S'", pszValueStr );
  HRESULT hr;

  //evaluate the value
  VARIANT value;
  hr = Evaluate( m_provider, m_address, m_binder, pszValueStr, NULL, &value );
  if (FAILED(hr))    return hr;
  if (hr == S_FALSE) return E_FAIL;   //parse failed

  //copy the bits
  hr = FieldSetValue( m_binder, m_field, value );
  if (FAILED(hr)) return hr;

  return S_OK;
}


STDMETHODIMP CFieldProperty::SetValueAsReference( 
    in IDebugReference2** ppargs,
    in DWORD              argCount,
    in IDebugReference2*  pvalue,
    in DWORD              timeout
    )
{
  TRACE("CFieldProperty::SetValueAsReference");
  return E_NOTIMPL;
}


STDMETHODIMP CFieldProperty::EnumChildren( 
    in DEBUGPROP_INFO_FLAGS infoFlags,
    in DWORD                radix,
    in REFGUID              guidFilter,
    in DBG_ATTRIB_FLAGS     attribFilter,
    in LPCOLESTR            pszNameFilter,
    in DWORD                timeout,
    out IEnumDebugPropertyInfo2 ** ppchildren )
{
  TRACE("CFieldProperty::EnumChildren");
  OUTARG(ppchildren);
  
  //get enumeration
  HRESULT hr;
  IEnumDebugFields*     pfields    = NULL;

  if (m_fieldKind & FIELD_TYPE_METHOD)
  {
    //-----------------------------------------------------
    // A Method

    IDebugMethodField*  pmethod    = NULL;

    //enumerate the requested properties
    hr = m_field->QueryInterface( IID_IDebugMethodField, reinterpret_cast<void**>(&pmethod) );
    if (FAILED(hr)) return hr;

    if (guidFilter == guidFilterArgs)
    {
      hr = pmethod->EnumParameters( &pfields );  
    }
    else if (guidFilter == guidFilterLocals)
    {
      hr = pmethod->EnumLocals( m_address, &pfields );
    }
    else if (guidFilter == guidFilterAllLocals)
    {
      hr = pmethod->EnumAllLocals( m_address, &pfields );
    }
    else if (guidFilter == guidFilterLocalsPlusArgs)
    {
      //we create a special enumerator implemented in [enummethodfield.cpp] for this
      IDebugClassField* pfieldThis  = NULL;
      IEnumDebugFields* pparameters = NULL;
      IEnumDebugFields* plocals     = NULL;
      
      pmethod->GetThis( &pfieldThis );
      pmethod->EnumParameters( &pparameters );
      pmethod->EnumLocals( m_address, &plocals );

      CEnumMethodField* penumMethodField = new CEnumMethodField( pfieldThis, pparameters, plocals );
      RELEASE(pfieldThis);
      RELEASE(pparameters);
      RELEASE(plocals);
      if (!penumMethodField) 
      { 
        hr = E_OUTOFMEMORY;
      }
      else
      {
        hr = penumMethodField->QueryInterface( IID_IEnumDebugFields, reinterpret_cast<void**>(&pfields) );
        RELEASE(penumMethodField);
      }
    }
    else if (guidFilter == guidFilterThis )
    {      
      IDebugClassField* pfieldThis  = NULL;
      
      hr = pmethod->GetThis( &pfieldThis );
      if (SUCCEEDED(hr))
      {
        CEnumMethodField* penumMethodField = new CEnumMethodField( pfieldThis, NULL, NULL );
        RELEASE(pfieldThis);
        if (!penumMethodField) 
        { 
          hr = E_OUTOFMEMORY;
        }
        else
        {
          hr = penumMethodField->QueryInterface( IID_IEnumDebugFields, reinterpret_cast<void**>(&pfields) );
          RELEASE(penumMethodField);
        }
      }
    }
    else
    {
      hr = E_FAIL;
    }

    RELEASE(pmethod);
    if (hr != S_OK) return hr;
  }
  else
  {
    //-----------------------------------------------------
    //try to use a general enumerator

    //convert attributes
    FIELD_KIND      fieldKind  = FIELD_KIND_NONE;
    FIELD_MODIFIERS fieldMod   = FIELD_MOD_NONE;
    
    if (attribFilter & DBG_ATTRIB_ACCESS_PUBLIC)    fieldMod |= FIELD_MOD_ACCESS_PUBLIC;
    if (attribFilter & DBG_ATTRIB_ACCESS_PRIVATE)   fieldMod |= FIELD_MOD_ACCESS_PRIVATE;
    if (attribFilter & DBG_ATTRIB_ACCESS_PROTECTED) fieldMod |= FIELD_MOD_ACCESS_PROTECTED;
    if (attribFilter & DBG_ATTRIB_ACCESS_FINAL)     fieldMod |= FIELD_MOD_FINAL;
  
    if (attribFilter & DBG_ATTRIB_STORAGE_GLOBAL)   fieldKind|= FIELD_SYM_GLOBAL;
    if (attribFilter & DBG_ATTRIB_STORAGE_STATIC)   fieldMod |= FIELD_MOD_STATIC;   

    if (attribFilter & DBG_ATTRIB_TYPE_VIRTUAL)     fieldMod |= FIELD_MOD_VIRTUAL;
    if (attribFilter & DBG_ATTRIB_TYPE_CONSTANT)    fieldMod |= FIELD_MOD_CONSTANT;
    if (attribFilter & DBG_ATTRIB_TYPE_SYNCHRONIZED)fieldMod |= FIELD_MOD_SYNCHRONIZED;

    if (attribFilter & DBG_ATTRIB_DATA)             fieldKind|= FIELD_KIND_SYMBOL;
    if (attribFilter & DBG_ATTRIB_METHOD)           fieldKind|= FIELD_TYPE_METHOD;
    if (attribFilter & DBG_ATTRIB_PROPERTY)         fieldKind|= FIELD_TYPE_PROP;
    if (attribFilter & DBG_ATTRIB_CLASS)            fieldKind|= FIELD_TYPE_CLASS;
    if (attribFilter & DBG_ATTRIB_BASECLASS)        fieldKind|= FIELD_TYPE_CLASS;   
    if (attribFilter & DBG_ATTRIB_INTERFACE)        fieldKind|= FIELD_TYPE_INTERFACE;
    if (attribFilter & DBG_ATTRIB_INNERCLASS)       fieldKind|= FIELD_TYPE_INNERCLASS;
  
    IDebugContainerField* pcontainer = NULL;
    hr = m_field->QueryInterface( IID_IDebugContainerField, reinterpret_cast<void**>(&pcontainer) );
    if (FAILED(hr)) return hr;

    hr = pcontainer->EnumFields( fieldKind, fieldMod, pszNameFilter, nmCaseSensitive, &pfields );
    RELEASE(pcontainer);
    if (hr != S_OK) return hr;
  }

  //create a property info enumeration around the field enumerator
  CEnumPropertyInfo* pproperties = new CEnumPropertyInfo( m_provider, m_address, m_binder, 
                                                       radix, pfields, infoFlags );
  RELEASE(pfields);
  if (!pproperties) return E_OUTOFMEMORY;

  hr = pproperties->QueryInterface( IID_IEnumDebugPropertyInfo2, reinterpret_cast<void**>(ppchildren) );
  RELEASE(pproperties);

  return hr;
}


/*---------------------------------------------------------
  IDebugProperty2: simple properties
-----------------------------------------------------------*/
STDMETHODIMP CFieldProperty::GetParent( out IDebugProperty2 **ppparent)
{
  TRACE("CFieldProperty::GetParent");
  OUTARG(ppparent);

  HRESULT hr;
  IDebugContainerField* pcontainer = NULL;
  hr = m_field->GetContainer( &pcontainer );
  if (FAILED(hr)) return hr;

  CFieldProperty* pproperty = new CFieldProperty( m_provider, m_address, m_binder, pcontainer );
  RELEASE(pcontainer);
  if (!pproperty) return E_OUTOFMEMORY;

  hr = pproperty->Init();
  if (FAILED(hr)) { RELEASE(pproperty); return hr; }

  hr = pproperty->QueryInterface( IID_IDebugProperty2, reinterpret_cast<void**>(ppparent) );
  RELEASE(pproperty);
  if (FAILED(hr)) return hr;

  return S_OK;
}


STDMETHODIMP CFieldProperty::GetDerivedMostProperty( out IDebugProperty2 **ppderivedMost)
{
  TRACE("CFieldProperty::GetDerivedMostProperty");
  OUTARG(ppderivedMost);

  return E_NOTIMPL;
}


STDMETHODIMP CFieldProperty::GetMemoryBytes( out IDebugMemoryBytes2 **ppmemoryBytes)
{
  TRACE("CFieldProperty::GetMemoryBytes");
  OUTARG(ppmemoryBytes);

  return E_NOTIMPL;
}


STDMETHODIMP CFieldProperty::GetMemoryContext( out IDebugMemoryContext2 **ppmemory)
{
  TRACE("CFieldProperty::GetMemoryContext");
  OUTARG(ppmemory);
  ASSERT(m_binder); if (!m_binder) return E_FAIL;

  HRESULT hr;
  IDebugObject* pobject = NULL;
  hr = m_binder->Bind( NULL, m_field, &pobject );
  if (FAILED(hr)) return hr;

  hr = pobject->GetMemoryContext( ppmemory );
  RELEASE(pobject);
  if (FAILED(hr)) return hr;

  return S_OK;
}


STDMETHODIMP CFieldProperty::GetSize( out DWORD *psize)
{
  TRACE("CFieldProperty::GetSize");
  OUTARG(psize);

  return m_field->GetSize( psize );
}


STDMETHODIMP CFieldProperty::GetReference( out IDebugReference2 **ppreference)
{
  TRACE("CFieldProperty::GetReference");
  OUTARG(ppreference);

  return E_NOTIMPL;
}


STDMETHODIMP CFieldProperty::GetExtendedInfo( in REFGUID  guidExtendedInfo, out VARIANT *pvarExtendedInfo)
{
  TRACE("CFieldProperty::GetExtendedInfo");
  OUTVAR(pvarExtendedInfo);

  return E_NOTIMPL;
}


