
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  EnumProperty
-----------------------------------------------------------*/
CEnumPropertyInfo::CEnumPropertyInfo( 
                  in IDebugSymbolProvider *pprovider,
                  in IDebugAddress        *paddress,
                  in IDebugBinder         *pbinder,
                  in DWORD                radix,
                  in IEnumDebugFields     *pfields,
                  in DEBUGPROP_INFO_FLAGS infoFlags )
{
  TRACE1( "create CEnumPropertyInfo: 0x%x", this );
  ASSERT(pprovider);
  ASSERT(paddress);
  ASSERT(pfields);

  m_refCount  = 1;
  m_radix     = radix;
  m_provider  = pprovider;      ADDREF(m_provider);
  m_address   = paddress;       ADDREF(m_address);
  m_fields    = pfields;        ADDREF(m_fields);
  m_binder    = pbinder;        if (m_binder) m_binder->AddRef(); //pbinder may be NULL
  m_infoFlags = infoFlags;
}


CEnumPropertyInfo::~CEnumPropertyInfo()
{
  TRACE1( "destroy CEnumPropertyInfo: 0x%x", this );
  RELEASE(m_provider);
  RELEASE(m_address);
  RELEASE(m_binder);
  RELEASE(m_fields);
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP CEnumPropertyInfo::QueryInterface( in REFIID iid, out LPVOID* pobj )
{
  OUTARG(pobj);

  if (iid == IID_IUnknown || iid == IID_IEnumDebugPropertyInfo2)
  {
    TRACE("CEnumPropertyInfo::QueryInterface for IEnumDebugPropertyInfo2");
    *pobj = static_cast<IEnumDebugPropertyInfo2*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) CEnumPropertyInfo::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CEnumPropertyInfo::Release()
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
  IEnumDebugPropertyInfo2:

  This is a wrapper around [IEnumDebugFields], 
  creating [CFieldProperty] instances on the
  fly to retrieve the [DEBUG_PROPERTY_INFO] using the 
  [GetPropertyInfo] method.
-----------------------------------------------------------*/
STDMETHODIMP CEnumPropertyInfo::Next( in ULONG count,
                                     out DEBUG_PROPERTY_INFO* pelements, 
                                     out ULONG* pfetched )
{
  TRACE( "CEnumPropertyInfo::Next" );
  if (pfetched)   *pfetched = 0;
  if (!pelements) return E_INVALIDARG;
            else memset( pelements, 0, count * sizeof(DEBUG_PROPERTY_INFO));

  HRESULT hr  = S_OK;
  ULONG   idx = 0;
  while (idx < count)
  {
    ULONG        fetchedFields;
    IDebugField* pfield;

    //get the next field
    hr = m_fields->Next( 1, &pfield, &fetchedFields );
    if (FAILED(hr))         goto fail;
    if (fetchedFields != 1) goto fail;
    idx++;

    //create a CFieldProperty to retrieve the DEBUG_PROPERTY_INFO
    CFieldProperty* pproperty = new CFieldProperty( m_provider, m_address, m_binder, pfield );
    RELEASE(pfield);
    if (!pproperty) { hr = E_OUTOFMEMORY; goto fail; }

    hr = pproperty->Init();
    if (FAILED(hr)) { RELEASE(pproperty); goto fail; }

    hr = pproperty->GetPropertyInfo( m_infoFlags, m_radix, 0, NULL, 0, pelements + idx - 1);
    RELEASE(pproperty);
    if (FAILED(hr)) goto fail;
  }

fail:
  if (pfetched) *pfetched = idx;
  return hr;
}


STDMETHODIMP CEnumPropertyInfo::Skip( in ULONG count )
{
  TRACE( "CEnumPropertyInfo::Skip" );
  return m_fields->Skip(count);
}


STDMETHODIMP CEnumPropertyInfo::Reset()
{
  TRACE( "CEnumPropertyInfo::Reset" );
  return m_fields->Reset();
}


STDMETHODIMP CEnumPropertyInfo::Clone( out IEnumDebugPropertyInfo2** ppclone )
{
  TRACE( "CEnumPropertyInfo::Clone" );
  OUTARG(ppclone);

  HRESULT hr;
  IEnumDebugFields* pfields = NULL;

  hr = m_fields->Clone(&pfields);
  if (FAILED(hr)) return hr;

  CEnumPropertyInfo* pproperties = new CEnumPropertyInfo( m_provider, m_address, m_binder, 
                                                       m_radix, pfields, m_infoFlags );
  RELEASE(pfields); 
  if (!pproperties) return E_OUTOFMEMORY;

  hr = pproperties->QueryInterface( IID_IEnumDebugPropertyInfo2, reinterpret_cast<void**>(ppclone) );
  RELEASE(pproperties);
  return hr;
}

STDMETHODIMP CEnumPropertyInfo::GetCount( out ULONG* pcount )
{
  TRACE( "CEnumPropertyInfo::GetCount" );
  return m_fields->GetCount(pcount);
}
