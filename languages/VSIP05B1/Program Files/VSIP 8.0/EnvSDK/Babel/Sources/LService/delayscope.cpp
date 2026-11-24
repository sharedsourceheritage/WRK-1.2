/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include "delayscope.h"
#include "package.h"

/*---------------------------------------------------------
 DelayScope
---------------------------------------------------------*/
DelayScope::DelayScope( in IServiceProvider* provider
                      , in IBabelProject* project
                      , in BSTR fileName )
{
  TRACE_CREATE( "DelayScope", static_cast<IScope*>(this) );

  m_refCount = 1;
  m_provider = provider; ADDREF(m_provider);
  m_fileName = SysAllocString(fileName);
  m_project  = project; if (m_project) m_project->AddRef();
  m_scope    = NULL;
}


DelayScope::~DelayScope()
{
  RELEASE(m_scope);
  bstrFree(m_fileName);
  RELEASE(m_provider);
  RELEASE(m_project);

  TRACE_DESTROY( static_cast<IScope*>(this));
}



STDMETHODIMP DelayScope::LoadScope()
{
  if (m_scope) return S_OK;
  if (!m_fileName || !m_provider) return E_POINTER;

  IBabelPackage* babelPackage = NULL;
  HRESULT hr = m_provider->QueryService( SID_IBabelPackage, IID_IBabelPackage, (void**)&babelPackage );
  if (FAILED(hr)) return hr;

  hr = babelPackage->LoadScope( DirectLoad, m_fileName, m_project, &m_scope );
  RELEASE(babelPackage);
  if (FAILED(hr)) return hr;

  return S_OK;
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP DelayScope::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IDispatch || iid == IID_IScope)
  {
    TRACE("DelayScope::QueryInterface for IUnknown/IDispatch/IScope");
    *obj = static_cast<IScope*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) DelayScope::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) DelayScope::Release()
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
  IDispatch 
-----------------------------------------------------------*/
STDMETHODIMP DelayScope::GetTypeInfoCount( out UINT* count )
{
  HRESULT hr = LoadScope();
  if (FAILED(hr)) return hr;
  
  return m_scope->GetTypeInfoCount( count );
}

STDMETHODIMP DelayScope::GetTypeInfo( in UINT index, in LCID lcid, out ITypeInfo** typeInfo )
{
  HRESULT hr = LoadScope();
  if (FAILED(hr)) return hr;
  
  return m_scope->GetTypeInfo( index, lcid, typeInfo );
}

STDMETHODIMP DelayScope::GetIDsOfNames( in REFIID iid, in OLECHAR** names, in UINT count, 
                                       in LCID lcid, out DISPID* dispids )
{
  HRESULT hr = LoadScope();
  if (FAILED(hr)) return hr;
  
  return m_scope->GetIDsOfNames( iid, names, count, lcid, dispids );
}

STDMETHODIMP DelayScope::Invoke( in DISPID dispid, in REFIID iid, in LCID lcid, 
                                in WORD flags, in DISPPARAMS* args, 
                                out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg )
{
  HRESULT hr = LoadScope();
  if (FAILED(hr)) return hr;
  
  return m_scope->Invoke( dispid, iid, lcid, flags, args, result, error, errorArg );
}
  
/*---------------------------------------------------------
 IDelayScope
---------------------------------------------------------*/
STDMETHODIMP DelayScope::GetDataTipText( in long line, in long idx, 
                                     in INames* names,
                                     out BSTR* text )
{
  HRESULT hr = LoadScope();
  if (FAILED(hr)) return hr;
  
  return m_scope->GetDataTipText( line, idx, names, text );
}


STDMETHODIMP DelayScope::GetDeclarations( in long line, in long idx, 
                                     in INames* names,
                                     out IDeclarations** idecls )
{
  HRESULT hr = LoadScope();
  if (FAILED(hr)) return hr;
  
  return m_scope->GetDeclarations( line, idx, names, idecls );
}


STDMETHODIMP DelayScope::GetMethods( in long line, in long idx, 
                                in INames* names, out IMethods** imethods )
{
  HRESULT hr = LoadScope();
  if (FAILED(hr)) return hr;
  
  return m_scope->GetMethods( line, idx, names, imethods );
}

STDMETHODIMP DelayScope::Narrow( in long line, in long idx, out BSTR* name, out long* nameLine )
{
  HRESULT hr = LoadScope();
  if (FAILED(hr)) return hr;

  return m_scope->Narrow( line, idx, name, nameLine );
}
