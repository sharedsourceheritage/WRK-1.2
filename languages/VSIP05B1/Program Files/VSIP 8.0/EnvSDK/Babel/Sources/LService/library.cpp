/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "dllmain.h"    //for g_typeInfoParseSink
#include "preferences.h"
#include "scope.h"
#include "delayscope.h"
#include "library.h"
#include "vsmem.h"

/*---------------------------------------------------------
  Library 
-----------------------------------------------------------*/
Library::Library( 
           in IServiceProvider* provider,          
           in Preferences*      preferences, 
           in IBabelService*    babelService, 
           in IBabelProject*    project,
           in BSTR              filePath )
{
  TRACE_CREATE( "Library", static_cast<IParseSink*>(this) );

  m_refCount    = 1;
  m_provider    = provider;     ADDREF(m_provider);
  m_preferences = preferences;  ADDREF(m_preferences);
  m_project     = project;
  if (m_project) m_project->AddRef();
  
  m_babelService= babelService; 
  if (m_babelService) m_babelService->AddRef();

  m_filePath    = SysAllocString(filePath);
  m_scope       = NULL;
  m_iscope      = NULL;
}


Library::~Library()
{
  bstrFree(m_filePath);
  if (m_babelService) m_babelService->Release();
  
  RELEASE(m_project);
  RELEASE(m_scope);
  RELEASE(m_iscope);
  RELEASE(m_preferences);
  RELEASE(m_provider);
  TRACE_DESTROY( static_cast<IParseSink*>(this) );
}

STDMETHODIMP Library::Init()
{
  if (!m_babelService) return E_FAIL;

  BSTR text;
  if (m_preferences->IsBinary())
  {
    text = NULL;
  }
  else
  {
    FILE* handle = fopen( CW2A(m_filePath), "rb" );
    if (!handle) return E_FAIL;

    //find length
    long result;
    result = fseek( handle, 0, SEEK_END );
    if (result != 0) { fclose(handle); return E_FAIL; }

    long size;
    size = ftell( handle );

    result = fseek( handle, 0, SEEK_SET );
    if (result != 0) { fclose(handle); return E_FAIL; }

    //alloc a buffer & read
    char* ctext = NALLOC(char,size+1 );
    if (!ctext) { fclose(handle); return E_OUTOFMEMORY; };

    long total = 0;
    while (total < size)
    {
      long read = (long)fread( ctext+total, 1, size, handle );
      if (read <= 0) { FREE(ctext); fclose(handle); return E_FAIL; }

      total += read;
    }
    fclose(handle);
    
    //convert
    ctext[size] = 0;
    text = SysAllocString(CA2W(ctext));
    FREE(ctext);
  }

  m_scope   = new Scope();
  m_iscope  = NULL;    
  HRESULT hr = m_babelService->ParseSource( text, static_cast<IParseSink*>(this), ReasonCheck, 0, &m_iscope );    
  bstrFree(text);

  if (m_iscope)
  {
    RELEASE(m_scope);
  }
  else
  {
    m_iscope = static_cast<IScope*>(m_scope);
    m_scope  = NULL;
  }

  return hr;
}

/*---------------------------------------------------------
  Library
-----------------------------------------------------------*/
STDMETHODIMP_(bool) Library::SamePath( in BSTR filePath )
{
  TRACE2("LoadScope '%S', already loaded library?: '%S'", filePath, m_filePath);
    
  return (strICompare(filePath,m_filePath) == 0);
}

STDMETHODIMP Library::GetScope( out IScope** scope )
{
  if (!m_iscope) return E_FAIL;
  return m_iscope->QueryInterface( IID_IScope, reinterpret_cast<void**>(scope) );
}
  

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Library::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("Library::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else if (iid == IID_IDispatch)
  {
    TRACE("Library::QueryInterface for IDispatch");
    *obj = static_cast<IDispatch*>(this);
  }
  else if (iid == IID_IParseSink)
  {
    TRACE("Library::QueryInterface for IParseSink");
    *obj = static_cast<IParseSink*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Library::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Library::Release()
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
  implement IDispatch (for IParseSink only)
-----------------------------------------------------------*/
STDMETHODIMP Library::GetTypeInfoCount( out UINT* count )
{
  OUTARG(count);

  if (g_typeInfoParseSink) *count = 1;
                      else *count = 0;
  return S_OK;
}

STDMETHODIMP Library::GetTypeInfo( in UINT index, in LCID lcid, out ITypeInfo** typeInfo )
{
  OUTARG(typeInfo);
  if (index != 0) return E_INVALIDARG;
  if (!g_typeInfoParseSink) return TYPE_E_CANTLOADLIBRARY;

  *typeInfo = g_typeInfoParseSink;
  return S_OK;
}

STDMETHODIMP Library::GetIDsOfNames( in REFIID iid, in OLECHAR** names, in UINT count, 
                                       in LCID lcid, out DISPID* dispids )
{
  if (!g_typeInfoParseSink) return TYPE_E_CANTLOADLIBRARY;
  return g_typeInfoParseSink->GetIDsOfNames( names, count, dispids );
}

STDMETHODIMP Library::Invoke( in DISPID dispid, in REFIID iid, in LCID lcid, 
                                in WORD flags, in DISPPARAMS* args, 
                                out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg )
{
  if (!g_typeInfoParseSink) return TYPE_E_CANTLOADLIBRARY;  
  return g_typeInfoParseSink->Invoke( static_cast<IParseSink*>(this), 
                                      dispid, flags, args, result, error, errorArg );
}
  

/*---------------------------------------------------------
  IParseSink
-----------------------------------------------------------*/
STDMETHODIMP Library::ErrorMessage( 
                           in long startLine, in long endLine,
                           in long startIdx,  in long endIdx,
                           in Severity severity, in BSTR message )
{
  return S_OK;
}

STDMETHODIMP Library::MatchPair( in long startLine1, in long startIdx1
                      , in long endLine1,   in long endIdx1 
                      , in long startLine2, in long startIdx2
                      , in long endLine2,   in long endIdx2 )
{
  return S_OK;
}

STDMETHODIMP Library::MatchTriple( in long startLine1, in long startIdx1
                      , in long endLine1,   in long endIdx1 
                      , in long startLine2, in long startIdx2
                      , in long endLine2,   in long endIdx2
                      , in long startLine3, in long startIdx3
                      , in long endLine3,   in long endIdx3 )
{
  return S_OK;
}

STDMETHODIMP Library::AutoExpression( in long startLine, in long endLine,
                               in long startIdx,  in long endIdx )
{
  return S_OK;
}

STDMETHODIMP Library::CodeSpan( in long startLine, in long startIdx, 
                               in long endLine, in long endIdx )
{
  return S_OK;
}

STDMETHODIMP Library::StartName( in long line, in long startIdx, in long endIdx )
{
  return S_OK;
}
  

STDMETHODIMP Library::QualifyName( in long lineSelect, in long startIdxSelect, in long endIdxSelect,
                                   in long line, in long startIdx, in long endIdx )
{
  return S_OK;  
}


STDMETHODIMP Library::StartParameters( in long line, in long idx )
{
  return S_OK;
}

STDMETHODIMP Library::Parameter( in long line, in long idx )
{
  return S_OK;
}

STDMETHODIMP Library::EndParameters  ( in long line, in long idx )
{
  return S_OK;
}

/*---------------------------------------------------------
  Context
-----------------------------------------------------------*/
STDMETHODIMP Library::GetPackage( out IBabelPackage** package )
{
  OUTARG(package);
  
  //get a reference to this package
  HRESULT hr = m_provider->QueryService( SID_IBabelPackage, IID_IBabelPackage, reinterpret_cast<void**>(package) );
  if (FAILED(hr)) return hr;

  return S_OK;

}

STDMETHODIMP Library::GetProject( out IBabelProject** project )
{
  OUTARG(project);
  if (!m_project) return E_FAIL;
  return m_project->QueryInterface( IID_IBabelProject, reinterpret_cast<void**>(project) );  
}

STDMETHODIMP Library::GetFileName( out BSTR* filePath )
{
  OUTARG(filePath);
  *filePath = SysAllocString(m_filePath);
  return S_OK;
}

/*---------------------------------------------------------
  Scope Builder
-----------------------------------------------------------*/
STDMETHODIMP Library::AddScope(  in long startLine, in long startIdx,
                        in long endLine,   in long endIdx,
                        in enum ScopeKind kind,
                        in enum ScopeAccess access,
                        in enum ScopeStorage storage,
                        in long glyph,
                        in BSTR name,     in BSTR type,
                        in BSTR display,  in BSTR description,
                        in VARIANT_BOOL merge
                      )                       
{
  return m_scope->InsertScope( merge != 0, 
                      startLine, startIdx, endLine, endIdx,
                      kind, access, storage, glyph,
                      name, type, display, description );
}



STDMETHODIMP Library::AddInclude( in long startLine, in long startIdx,
								 in long endLine,   in long endIdx,
								 in enum ScopeAccess access, in BSTR name )
{
  return m_scope->AddIncludeScope( startLine, startIdx, endLine, endIdx, access, name );
}

STDMETHODIMP Library::AddExtern( in long startLine, in long startIdx,
 							    in long endLine,   in long endIdx,
							    in IScope* scope )
{
  return m_scope->AddExternScope( startLine, startIdx, endLine, endIdx, scope );
}
