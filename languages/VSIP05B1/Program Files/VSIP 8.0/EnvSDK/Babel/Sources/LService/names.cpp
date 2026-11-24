/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "dllmain.h"  //g_typeInfoNames
#include "names.h"
#include "vsmem.h"

/*---------------------------------------------------------
  Names 
-----------------------------------------------------------*/
Names::Names()
{
  TRACE_CREATE_HIDE( "Names", static_cast<INames*>(this) );

  m_refCount = 1;
  m_names    = NULL;
  m_size     = 0;
  m_start    = 0;
  m_last     = 0;
}


Names::~Names()
{
  TRACE_DESTROY( static_cast<INames*>(this) );
  if (m_names)
  {
    for (long index = m_start; index < m_last; index++)
    {
      bstrFree(m_names[index].m_name);
      bstrFree(m_names[index].m_selector);
    }
  }
  FREE(m_names);
}


STDMETHODIMP Names::Init( in long size )
{
  ASSERT(m_names == NULL && m_start == 0 && m_last == 0 && m_size == 0);

  m_names = NALLOC(NameInfo,size);
  if (!m_names) return E_OUTOFMEMORY;

  m_size  = size;
  return S_OK;
}

STDMETHODIMP Names::InsertNoDup( in BSTR name, in BSTR selector )
{
  //TRACE1("Names::Insert: %S", name );
  ASSERT(m_names && m_last < m_size);
  if (m_last >= m_size) return E_FAIL;

  m_names[m_last].m_name = name;
  m_names[m_last].m_selector = selector;
  m_last++;
  return S_OK;
}


STDMETHODIMP Names::InitFromNames( in INames* names )
{
  if (!names) return S_OK;

  long count = 0;
  names->GetCount(&count);

  HRESULT hr = Init( count );
  if ( FAILED(hr) )
    return hr;

  for (long index = 0; index < count; index++)
  {
    BSTR name;
    hr = names->GetName(index, &name);
    if (FAILED(hr)) return hr;

    BSTR selector;
    hr = names->GetSelector(index,&selector);
    if (FAILED(hr)) { bstrFree(name); return hr; }
    InsertNoDup(name, selector ); //no dup => no free!
  }

  return S_OK;
}

STDMETHODIMP Names::DropHead()
{
  if (m_start < m_last)
  {
    bstrFree( m_names[m_start].m_name );
    bstrFree( m_names[m_start].m_selector );
    m_start++;
  }
  return S_OK;
}

STDMETHODIMP Names::DropLast()
{
  if (m_last > m_start)
  {
    bstrFree( m_names[m_last-1].m_name );
    bstrFree( m_names[m_last-1].m_selector );
    m_last--;
  }
  return S_OK;
}


STDMETHODIMP Names::PushHead( in BSTR name, in BSTR selector )
{
  if (m_start <= 0) return S_FALSE;

  m_start--;
  m_names[m_start].m_name     = SysAllocString(name);
  m_names[m_start].m_selector = SysAllocString(selector);
  return S_OK;
}
 
STDMETHODIMP Names::PushLast( in BSTR name, in BSTR selector )
{
  if (m_last >= m_size) return S_FALSE;
  
  m_names[m_last].m_name = SysAllocString(name);
  m_names[m_last].m_selector = SysAllocString(selector);
  m_last++;
  return S_OK;
}


STDMETHODIMP_(bool) Names::IsEmpty()
{
  return (m_start >= m_last);
}

STDMETHODIMP_(bool) Names::SameNameHead( in BSTR name )
{
  if (IsEmpty()) return false;
  return (strICompare( m_names[m_start].m_name, name ) == 0);
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Names::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("Names::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else if (iid == IID_IDispatch)
  {
    TRACE("Names::QueryInterface for IDispatch");
    *obj = static_cast<IDispatch*>(this);
  }
  else if (iid == IID_INames)
  {
    TRACE("Names::QueryInterface for INames");
    *obj = static_cast<INames*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Names::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Names::Release()
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
  implement IDispatch (for INames only)
-----------------------------------------------------------*/
STDMETHODIMP Names::GetTypeInfoCount( out UINT* count )
{
  OUTARG(count);

  if (g_typeInfoNames) *count = 1;
                      else *count = 0;
  return S_OK;
}

STDMETHODIMP Names::GetTypeInfo( in UINT index, in LCID lcid, out ITypeInfo** typeInfo )
{
  OUTARG(typeInfo);
  if (index != 0) return E_INVALIDARG;
  if (!g_typeInfoNames) return TYPE_E_CANTLOADLIBRARY;

  *typeInfo = g_typeInfoNames;
  return S_OK;
}

STDMETHODIMP Names::GetIDsOfNames( in REFIID iid, in OLECHAR** names, in UINT count, 
                                       in LCID lcid, out DISPID* dispids )
{
  if (!g_typeInfoNames) return TYPE_E_CANTLOADLIBRARY;
  return g_typeInfoNames->GetIDsOfNames( names, count, dispids );
}

STDMETHODIMP Names::Invoke( in DISPID dispid, in REFIID iid, in LCID lcid, 
                                in WORD flags, in DISPPARAMS* args, 
                                out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg )
{
  if (!g_typeInfoNames) return TYPE_E_CANTLOADLIBRARY;  
  return g_typeInfoNames->Invoke( static_cast<INames*>(this), 
                                      dispid, flags, args, result, error, errorArg );
}
  

/*---------------------------------------------------------
  INames
-----------------------------------------------------------*/
STDMETHODIMP Names::GetCount( out long* count )
{
  OUTARG(count);
  *count = m_last - m_start;
  return S_OK;
}

STDMETHODIMP Names::GetName( in long index, out BSTR* name )
{
  OUTARG(name);
  if (index < 0 || index >= (m_last-m_start)) return E_INVALIDARG;

  *name = SysAllocString( m_names[m_start + index].m_name );
  if (SysStringLen(*name)==0) 
    return S_FALSE;
  else
    return S_OK;
}

STDMETHODIMP Names::GetSelector( in long index, out BSTR* selector )
{
  OUTARG(selector);
  if (index < 0 || index >= (m_last-m_start)) return E_INVALIDARG;

  *selector = SysAllocString( m_names[m_start + index].m_selector );
  if (SysStringLen(*selector)==0) 
    return S_FALSE;
  else
    return S_OK;
}
