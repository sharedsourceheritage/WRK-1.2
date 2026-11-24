/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "dllmain.h"        //g_typeInfoMethods
#include "methods.h"
#include "vsmem.h"

/*---------------------------------------------------------
  Methods 
-----------------------------------------------------------*/
Methods::Methods()
{
  TRACE_CREATE( "Methods", static_cast<IMethods*>(this) );

  m_refCount = 1;
  m_name     = NULL;
  m_methods  = NULL;
}


Methods::~Methods()
{
  TRACE_DESTROY( static_cast<IMethods*>(this) );
  
  bstrFree(m_name);

  MethodInfo* method = m_methods; 
  while (method)
  {
    bstrFree(method->type);
    bstrFree(method->description);

    ParameterInfo* param = method->params;
    while (param)
    {
      bstrFree( param->name );
      bstrFree( param->display );
      bstrFree( param->description );

      ParameterInfo* next;
      next  = param->next;
      FREE(param);
      param = next;
    }

    MethodInfo* next;
    next = method->next;
    FREE(method);
    method = next;
  }
}


STDMETHODIMP Methods::Init( in BSTR name )
{
  ASSERT(m_methods == NULL);

  m_name    = SysAllocString(name);
  return S_OK;
}

STDMETHODIMP_(MethodInfo*) Methods::GetLast()
{
  MethodInfo* last = m_methods;
  if (last)
  {
    while (last->next) last = last->next;
  }
  return last;
}

STDMETHODIMP Methods::Insert( in BSTR description, in BSTR type )
{
  MethodInfo* method = ALLOC(MethodInfo);
  if (!method) return E_OUTOFMEMORY;

  method->next        = NULL;
  method->type        = SysAllocString(type);
  method->description = SysAllocString(description);
  method->params      = NULL;
  
  MethodInfo* last = GetLast();
  if (last) last->next = method;
       else m_methods = method;

  return S_OK;
}

STDMETHODIMP Methods::InsertParameter( in BSTR name, in BSTR display, in BSTR description )
{
  ASSERT(m_methods);
  MethodInfo* method = GetLast();
  if (!method) return E_FAIL;
  
  ParameterInfo* param = ALLOC(ParameterInfo);
  if (!param) return E_OUTOFMEMORY;

  param->next        = NULL;
  param->name        = SysAllocString(name);
  param->display     = SysAllocString(display);
  param->description = SysAllocString(description);
  
  ParameterInfo* last = method->params;
  if (!last)
    method->params = param;
  else
  {
    while (last->next) last = last->next;
    last->next = param;
  }

  return S_OK;
}

STDMETHODIMP Methods::GetMethod( in long index, out MethodInfo** method )
{
  OUTARG(method);

  for (*method = m_methods; (*method != NULL) && (index > 0); *method = (*method)->next )
  {
    index--;
  }
  if ((*method == NULL) || index > 0) return E_INVALIDARG;

  return S_OK;
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Methods::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("Methods::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else if (iid == IID_IDispatch)
  {
    TRACE("Methods::QueryInterface for IDispatch");
    *obj = static_cast<IDispatch*>(this);
  }
  else if (iid == IID_IMethods)
  {
    TRACE("Methods::QueryInterface for IMethods");
    *obj = static_cast<IMethods*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Methods::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Methods::Release()
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
  implement IDispatch (for IMethods only)
-----------------------------------------------------------*/
STDMETHODIMP Methods::GetTypeInfoCount( out UINT* count )
{
  OUTARG(count);

  if (g_typeInfoMethods) *count = 1;
                    else *count = 0;
  return S_OK;
}

STDMETHODIMP Methods::GetTypeInfo( in UINT index, in LCID lcid, out ITypeInfo** typeInfo )
{
  OUTARG(typeInfo);
  if (index != 0) return E_INVALIDARG;
  if (!g_typeInfoMethods) return TYPE_E_CANTLOADLIBRARY;

  *typeInfo = g_typeInfoMethods;
  return S_OK;
}

STDMETHODIMP Methods::GetIDsOfNames( in REFIID iid, in OLECHAR** names, in UINT count, 
                                       in LCID lcid, out DISPID* dispids )
{
  if (!g_typeInfoMethods) return TYPE_E_CANTLOADLIBRARY;
  return g_typeInfoMethods->GetIDsOfNames( names, count, dispids );
}

STDMETHODIMP Methods::Invoke( in DISPID dispid, in REFIID iid, in LCID lcid, 
                                in WORD flags, in DISPPARAMS* args, 
                                out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg )
{
  if (!g_typeInfoMethods) return TYPE_E_CANTLOADLIBRARY;  
  return g_typeInfoMethods->Invoke( static_cast<IMethods*>(this), 
                                      dispid, flags, args, result, error, errorArg );
}
  

/*---------------------------------------------------------
  IMethods
-----------------------------------------------------------*/
STDMETHODIMP Methods::GetCount( out long* count )
{
  OUTARG(count);
  *count = 0;
  for( MethodInfo* method = m_methods; method; method = method->next)
  {
    *count += 1;
  }
  return S_OK;
}

STDMETHODIMP Methods::GetName( out BSTR* name )
{
  OUTARG(name);
  *name = m_name;
  return S_OK;
}
STDMETHODIMP Methods::GetDescription( in long index, out BSTR* description )
{
  OUTARG(description);
  MethodInfo* method;
  HRESULT hr = GetMethod( index, &method );
  if (FAILED(hr)) return hr;

  *description = method->description;
  return S_OK;
}

STDMETHODIMP Methods::GetType( in long index, out BSTR* type )
{ 
  OUTARG(type);
  MethodInfo* method;
  HRESULT hr = GetMethod( index, &method );
  if (FAILED(hr)) return hr;

  *type = method->type;
  return S_OK;
}

STDMETHODIMP Methods::GetParameterCount( in long index, out long* count )
{
  OUTARG(count);
  MethodInfo* method;
  HRESULT hr = GetMethod( index, &method );
  if (FAILED(hr)) return hr;

  *count = 0;
  for (ParameterInfo* param = method->params; param; param = param->next)
  {
    *count += 1;
  }
  
  return S_OK;
}

STDMETHODIMP Methods::GetParameterInfo ( in long index, 
                                         in long parameter, 
                                         out BSTR* name,
                                         out BSTR* display,
                                         out BSTR* description )
{
  MethodInfo* method;
  HRESULT hr = GetMethod( index, &method );
  if (FAILED(hr)) return hr;

  for( ParameterInfo* param = method->params; param && (parameter > 0); param = param->next )
  {
    parameter--;
  }
  if (index > 0 || param == NULL) return E_INVALIDARG;

  if (name)         *name  = NULL;
  if (display)      *display = NULL;
  if (description)  *description = NULL;
  
  if (name)         *name  = param->name;
  if (display)      *display = param->display;
  if (description)  *description = param->description;

  return S_OK;
}
