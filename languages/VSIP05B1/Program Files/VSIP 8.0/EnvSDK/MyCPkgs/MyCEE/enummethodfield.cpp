
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  EnumProperty
-----------------------------------------------------------*/
CEnumMethodField::CEnumMethodField(in IDebugField* pfieldThis, 
                                 in IEnumDebugFields* pparameters,
                                 in IEnumDebugFields* plocals )
{
  TRACE1( "create CEnumMethodField: 0x%x", this );
  m_refCount       = 1;
  m_currentIdx     = 0;
  m_parameterCount = 0;
  m_localCount     = 0;
  m_thisCount      = 0;

  m_fieldThis      = pfieldThis;  if (m_fieldThis)  m_fieldThis->AddRef();
  m_parameters     = pparameters; if (m_parameters) m_parameters->AddRef();
  m_locals         = plocals;     if (m_locals)     m_locals->AddRef();

  if (m_fieldThis)  m_thisCount = 1;
  if (m_parameters) m_parameters->GetCount( &m_parameterCount );
  if (m_locals)     m_locals->GetCount( &m_localCount );
}

CEnumMethodField::~CEnumMethodField()
{
  TRACE1( "destroy CEnumMethodField: 0x%x", this );
  RELEASE( m_fieldThis );
  RELEASE( m_parameters );
  RELEASE( m_locals );
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP CEnumMethodField::QueryInterface( in REFIID iid, out LPVOID* pobj )
{
  OUTARG(pobj);

  if (iid == IID_IUnknown || iid == IID_IEnumDebugFields)
  {
    TRACE("CEnumMethodField::QueryInterface for IEnumDebugFields");
    *pobj = static_cast<IEnumDebugFields*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) CEnumMethodField::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CEnumMethodField::Release()
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
  IEnumDebugFields
-----------------------------------------------------------*/
STDMETHODIMP CEnumMethodField::Next( in ULONG count, out IDebugField** ppelements, out ULONG* pfetched )
{
  TRACE( "CEnumMethodField::Next" );
  if (pfetched)   *pfetched = 0;
  if (!ppelements) return E_INVALIDARG;
            else memset( ppelements, 0, count * sizeof(IDebugField*));

  ULONG fetched = 0;
  while (fetched < count)
  {
    HRESULT hr;
    ULONG        fetchedFields;
    IDebugField* pfield;

    if (m_currentIdx < m_thisCount) 
    {
      ASSERT(m_fieldThis);
      hr = m_fieldThis->QueryInterface( IID_IDebugField, reinterpret_cast<void**>(&pfield) );
      if (FAILED(hr)) return hr;
    }
    else if (m_currentIdx < m_parameterCount + m_thisCount)
    {
      ASSERT(m_parameters);
      hr = m_parameters->Next(1,&pfield,&fetchedFields );
      if (hr != S_OK) return hr;     
    }
    else if (m_currentIdx < m_localCount + m_parameterCount + m_thisCount)
    {
      ASSERT(m_locals);
      hr = m_locals->Next(1,&pfield,&fetchedFields);
      if (hr != S_OK) return hr;
    }
    else
    {
      //out of bound
      return S_FALSE;
    }

    ppelements[fetched] = pfield;
    m_currentIdx++;
    fetched++;
    if (pfetched != NULL) 
        *pfetched = fetched;
  }

  return S_OK;
}

STDMETHODIMP CEnumMethodField::Skip( in ULONG count )
{
  TRACE( "CEnumMethodField::Skip" );
  HRESULT hr;

  while (count > 0)
  {
    if (m_currentIdx < m_thisCount) 
    {
      //nothing to do
      ;
    }
    else if (m_currentIdx < m_parameterCount + m_thisCount)
    {
      ASSERT(m_parameters);
      hr = m_parameters->Skip(1);
      if (FAILED(hr)) return hr;
      
    }
    else if (m_currentIdx < m_localCount + m_parameterCount + m_thisCount)
    {
      ASSERT(m_locals);
      hr = m_locals->Skip(1);
      if (FAILED(hr)) return hr;
    }
    else
    {
      //out of bound
      return S_FALSE;
    }

    m_currentIdx++;
    count--;
  }

  return S_OK;
}


STDMETHODIMP CEnumMethodField::Reset()
{
  TRACE( "CEnumMethodField::Reset" );

  m_currentIdx = 0;
  if (m_parameters) m_parameters->Reset();
  if (m_locals)     m_locals->Reset();
  return S_OK;
}

STDMETHODIMP CEnumMethodField::Clone( out IEnumDebugFields** ppclone )
{
  TRACE( "CEnumMethodField::Clone" );
  OUTARG(ppclone);

  HRESULT hr = S_OK;
  IDebugField*      pfieldThis  = NULL;
  IEnumDebugFields* pparameters = NULL;
  IEnumDebugFields* plocals     = NULL;
  CEnumMethodField* penumMethodField = NULL;

  if (m_parameters) 
  { 
    hr = m_parameters->Clone(&pparameters);
    if (FAILED(hr)) goto fail;
  }

  if (m_locals) 
  {
    hr = m_locals->Clone(&plocals);
    if (FAILED(hr)) goto fail;
  }

  if (m_fieldThis) 
  {
    hr = m_fieldThis->QueryInterface( IID_IDebugField, reinterpret_cast<void**>(&pfieldThis) );
    if (FAILED(hr)) goto fail;
  }

  penumMethodField = new CEnumMethodField( pfieldThis, pparameters, plocals );
  if (!penumMethodField) { hr = E_OUTOFMEMORY; goto fail; }

  hr = penumMethodField->QueryInterface( IID_IEnumDebugFields, reinterpret_cast<void**>(ppclone) );
  if (FAILED(hr)) goto fail;

fail:
  RELEASE(pfieldThis);
  RELEASE(pparameters);
  RELEASE(plocals);
  RELEASE(penumMethodField);
  return hr;
}

STDMETHODIMP CEnumMethodField::GetCount( out ULONG* pcount )
{
  TRACE( "CEnumMethodField::GetCount" );
  OUTARG(pcount);

  *pcount = m_thisCount + m_parameterCount + m_localCount;
  return S_OK;
}
