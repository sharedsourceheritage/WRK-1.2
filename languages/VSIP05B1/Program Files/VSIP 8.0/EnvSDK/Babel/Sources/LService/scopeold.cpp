/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

/*---------------------------------------------------------
 this module needs a good cleanup, ie a complete rewrite
 at least the dependency on STL should be removed.
 but there is lots of superfluent code in here.

 the InternAddRef/Release are to keep the root of
 the scope tree alive if there is an outside pointer
 into the tree somewhere, the root could always be 
 accessed through the m_parent members which are normally
 not addref'd 
---------------------------------------------------------*/
#include "project.h"
#include "dllmain.h"  //for g_typeInfoScope
#include "scope.h"
#include "declarations.h"
#include "methods.h"

enum NameKind
{
  Definition,
  Reference,
  External
};



HRESULT InsertScope(
        Scope* rootScope, bool merge,
        int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeKind kind,
        enum ScopeAccess access,
        enum ScopeStorage storage,
        BSTR name,     BSTR type,
        BSTR display,  BSTR description )
{
  Scope* scope = new Scope( startLine, startIdx, endLine, endIdx, kind, access, storage, name, type,display, description );
  if (!scope) return E_OUTOFMEMORY;

  rootScope->insertScope( merge, scope );
  scope->InternRelease();
  return S_OK;
}

HRESULT AddIncludeScope( 
        Scope* rootScope, 
        int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeAccess access, BSTR name )
{
  return E_NOTIMPL;
}
        
HRESULT AddExternScope( 
        Scope* rootScope, 
        int startLine, int startIdx,
        int endLine,   int endIdx,
        IScope* externScope )
{
  return E_NOTIMPL;
}


/*---------------------------------------------------------
 Scope
---------------------------------------------------------*/
Scope::Scope(int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeKind kind,
        enum ScopeAccess access,
        enum ScopeStorage storage,
        BSTR name,     BSTR type,
        BSTR display,  BSTR description )
{
  TRACE_CREATE_HIDE( "Scope", static_cast<IScope*>(this) );
  m_refCount= 1;
  m_parent  = NULL;

  m_endLine   = endLine;
  m_startLine = startLine;
  m_endIdx    = endIdx;
  m_startIdx  = startIdx;   

  m_name        = (name ? name : bstrNew(""));
  m_display     = (display ? display : bstrDup(m_name));
  m_description = (description ? description : bstrDup(m_display));
  m_type        = (type ? type : bstrNew(""));
  m_kind        = kind;
  m_access      = access;
  m_storage     = storage;
}


Scope::Scope(int line, int idx )
{
  TRACE_CREATE_HIDE( "Scope", static_cast<IScope*>(this) );
  m_refCount= 1;
  m_parent  = NULL;

  m_endLine = m_startLine    = line;
  m_endIdx  = m_startIdx     = idx;
  m_name    = bstrNew("");
  m_display = NULL;
  m_description = NULL;
  m_type    = NULL;
  m_kind    = ScopeUnknown;
  m_access  = AccessPublic;
  m_storage = StorageStatic;
}

Scope::~Scope()
{
  TRACE_DESTROY( static_cast<IScope*>(this));
  clear();
  bstrFree(m_name);
  bstrFree(m_display);
  bstrFree(m_type);
  bstrFree(m_description);
}

void Scope::clear()
{
  ScopeList::iterator iter;
  for (iter = m_members.begin(); iter != m_members.end(); iter++)
  {
    (*iter)->InternRelease();
  }  
  m_members.clear(); 
}


int Scope::memberCount()
{
  // return m_members.size();
  ScopeList::iterator iter;
  int count = 0;
  for (iter = m_members.begin(); iter != m_members.end(); iter++)
  {
    if (!bstrEmpty((*iter)->m_name)) count++;
  }
  return count;
}


bool isBefore( Scope& scope1, Scope& scope2 )
{
  return (scope1.m_endLine < scope2.m_startLine 
        || (scope1.m_endLine == scope2.m_startLine && scope1.m_endIdx < scope2.m_startIdx));
}

bool startsInside( Scope& scope1, Scope& scope2 )
{
  return (  (scope1.m_startLine > scope2.m_startLine 
             || (scope1.m_startLine == scope2.m_startLine && scope1.m_startIdx > scope2.m_startIdx))
         && (scope1.m_startLine < scope2.m_endLine  
             || (scope1.m_startLine == scope2.m_endLine && scope1.m_startIdx < scope2.m_endIdx)) );
}         

void Scope::insertScope( bool merge, Scope* scope )
{
  ScopeList::iterator iter;
  for (iter = m_members.begin(); iter != m_members.end(); iter++)
  {
    if (isBefore(*scope,**iter))
      break; //first in line
    if (isBefore(**iter,*scope)) 
      continue; //after this one
    //there is overlap
    else if (startsInside(*scope,**iter))
      (*iter)->insertScope( merge, scope ); //subsumed
    else 
    {
      //the new scope encloses one or more members
      ScopeList::iterator iterEnd;
      for (iterEnd = iter;   iterEnd != m_members.end()
                          && startsInside(**iterEnd,*scope); iterEnd++)
      {
        scope->insertScope( merge, (*iterEnd) );
        (*iterEnd)->InternRelease();
      }
      m_members.erase( iter, iterEnd );
      break;
    }
  }

  //insert the new scope right here
  m_members.insert( iter, scope );
  scope->m_parent = this;
  scope->InternAddRef();
  return;
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Scope::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IScope)
  {
    TRACE("Scope::QueryInterface for IUnknown/IScope");
    *obj = static_cast<IScope*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Scope::InternAddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Scope::InternRelease()
{
  if (DecRefCount(&m_refCount) == 0)
  {
    delete this;
    return 0;
  }
  else
    return m_refCount;
}

STDMETHODIMP_(ULONG) Scope::AddRef()
{
  Scope* root = this;
  while (root->m_parent) root = root->m_parent;
  return root->InternAddRef();
}

STDMETHODIMP_(ULONG) Scope::Release()
{
  Scope* root = this;
  while (root->m_parent) root = root->m_parent;
  return root->InternRelease();
}


/*---------------------------------------------------------
  implement IDispatch (for IScope only)
-----------------------------------------------------------*/
STDMETHODIMP Scope::GetTypeInfoCount( out UINT* count )
{
  OUTARG(count);

  if (g_typeInfoScope) *count = 1;
                  else *count = 0;
  return S_OK;
}

STDMETHODIMP Scope::GetTypeInfo( in UINT index, in LCID lcid, out ITypeInfo** typeInfo )
{
  OUTARG(typeInfo);
  if (index != 0) return E_INVALIDARG;
  if (!g_typeInfoScope) return TYPE_E_CANTLOADLIBRARY;

  *typeInfo = g_typeInfoScope;
  return S_OK;
}

STDMETHODIMP Scope::GetIDsOfNames( in REFIID iid, in OLECHAR** names, in UINT count, 
                                       in LCID lcid, out DISPID* dispids )
{
  if (!g_typeInfoScope) return TYPE_E_CANTLOADLIBRARY;
  return g_typeInfoScope->GetIDsOfNames( names, count, dispids );
}

STDMETHODIMP Scope::Invoke( in DISPID dispid, in REFIID iid, in LCID lcid, 
                                in WORD flags, in DISPPARAMS* args, 
                                out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg )
{
  if (!g_typeInfoScope) return TYPE_E_CANTLOADLIBRARY;  
  return g_typeInfoScope->Invoke( static_cast<IScope*>(this), 
                                      dispid, flags, args, result, error, errorArg );
}
  
/*---------------------------------------------------------
 IScope
---------------------------------------------------------*/
static HRESULT lookupMember( inout Scope** scope, in INames* names, bool quickInfo )
{
  REFARG(scope);
  REFARG(names);
  if (*scope == NULL) return E_INVALIDARG;
  HRESULT hr;

  long count = 0;
  names->GetCount(&count);

  for (long index = 0; index < count-1; index++)    //all but the last name
  {
    Scope*  nextScope;
    BSTR    text;

    //get text
    hr = names->GetName( index, &text );
    if (FAILED(hr)) return hr;

    while (!bstrEmpty(text))
    {
      TRACE1("lookupMember: %S", text );
      hr = (*scope)->LookupNames( text, &nextScope );
      bstrFree(text);
      if (hr != S_OK || !nextScope) return S_FALSE;
      

      RELEASE(*scope);
      *scope = nextScope;
      nextScope = NULL;

      //get type
      ScopeStorage  storage;
      hr = (*scope)->GetInfo( NULL, NULL, &storage, NULL, &text, NULL, NULL );
      if (FAILED(hr)) return hr;

      if (storage == StorageType || storage == StorageOther)
      {
        bstrFree(text);
      }
    }
    bstrFree(text);
  }

  if (quickInfo)
  {
    Scope*  nextScope;
    BSTR    text;
    
    hr = names->GetName( index, &text );
    if (FAILED(hr)) return hr;
    if (bstrEmpty(text)) return S_FALSE;

    hr = (*scope)->LookupNames( text, &nextScope );
    bstrFree(text);
    if (hr != S_OK || !nextScope) return S_FALSE;

    RELEASE(*scope);
    *scope = nextScope;
    nextScope = NULL;
  }

  return S_OK;
}

STDMETHODIMP Scope::GetDataTipText( in long line, in long idx, 
                                     in INames* names,
                                     out BSTR* text )
{
  OUTARG(text);
  HRESULT hr;

  Scope* scope;
  NarrowScope( line, idx, &scope );
  if (names) 
  {
    long count;
    hr = names->GetCount( &count );
    if (FAILED(hr)) { RELEASE(scope); return hr; }
    if (count > 0)
    {
      hr = lookupMember( &scope, names, true );
      if (hr != S_OK) { RELEASE(scope); return hr; }
    }
  }

  hr = scope->GetInfo( NULL, NULL, NULL, NULL, NULL, NULL, text );
  RELEASE(scope);
  if (FAILED(hr)) return hr;
  
  return S_OK;
}

STDMETHODIMP Scope::GetDeclarations( in long line, in long idx, 
                                     in INames* names,
                                     out IDeclarations** idecls )
{
  OUTARG(idecls);
  HRESULT hr;

  bool membersOnly = false;

  Scope* scope;
  NarrowScope( line, idx, &scope );
  if (names) 
  {
    long count;
    hr = names->GetCount( &count );
    if (FAILED(hr)) { RELEASE(scope); return hr; }
    if (count > 1)
    {
      membersOnly = true;
      hr = lookupMember( &scope, names, false );
      if (hr != S_OK) { RELEASE(scope); return hr; }
    }
  }

  long count;
  hr = scope->GetCount( membersOnly, &count );
  if (FAILED(hr)) { RELEASE(scope); return hr; }

  Declarations* decls = NULL;
  decls = new Declarations();
  if (!decls) { RELEASE(scope); return E_OUTOFMEMORY; }

  hr = decls->Init( count );
  if (FAILED(hr)) { RELEASE(decls); RELEASE(scope); return hr; }

  for (long index = 0; index < count; index++)
  {
    Scope* indexScope;
    hr = scope->GetScope(index,&indexScope);
    if (FAILED(hr)) break;

    ScopeKind    kind;
    ScopeStorage storage;
    ScopeAccess  access;
    BSTR         name;
    BSTR         description;
    hr = indexScope->GetInfo( &kind, &access, &storage, &name, NULL, NULL, &description );
    RELEASE(indexScope);
    if (FAILED(hr)) break;

    long glyph = 0;
    switch (kind)
    {
      case ScopeModule:   glyph = 0;  break;
      case ScopeClass:    glyph = 1;  break;
      case ScopeInterface:glyph = 1;  break;
      case ScopeUnion:    glyph = 1;  break;

      case ScopeProcedure:glyph = 2;  break;

      case ScopeVariable:
        {
          switch (storage)
          {
          case StorageMember:      glyph = 3; break;
          
          case StorageParameter:
          case StorageResult:      glyph = 5; break;

          case StorageConstant:
          case StorageStatic:
          
          case StorageLocal:
          case StorageType:
          case StorageOther:
          default:                 glyph = 4; break;              
          }
          break;
        }

      case ScopeBlock:    glyph = 4;  break;
      
      
      //obsolete
      case ScopeMethod:   glyph = 2;  break;
      case ScopeField:    glyph = 3;  break;
      case ScopeParameter:glyph = 5;  break;
      case ScopeResult:   glyph = 5;  break;
      default:
        glyph = 3;
        break;
    }

    hr = decls->Insert( name, description, glyph );
    if (FAILED(hr)) break;
  }
  RELEASE(scope);
  if (FAILED(hr)) { RELEASE(decls); return hr; }

  hr = decls->Sort();
  if (FAILED(hr)) { RELEASE(decls); return hr; }

  *idecls = static_cast<IDeclarations*>(decls);

  return S_OK;
}


STDMETHODIMP Scope::GetMethods( in long line, in long idx, 
                                in INames* names, out IMethods** imethods )
{
  OUTARG(imethods);
  REFARG(names);
  HRESULT hr;

  Scope* scope;
  NarrowScope( line, idx, &scope );
  
  long count;
  hr = names->GetCount( &count );
  if (FAILED(hr)) { RELEASE(scope); return hr; }
  if (count <= 0) return S_FALSE;

  hr = lookupMember( &scope, names, true );
  if (hr != S_OK) { RELEASE(scope); return hr; }
  
  ScopeKind    kind;
  hr = scope->GetInfo( &kind, NULL, NULL, NULL, NULL, NULL, NULL );
  if (FAILED(hr))             { RELEASE(scope); return hr; }
  if (kind != ScopeProcedure) { RELEASE(scope); return S_FALSE; }

  BSTR display;
  hr = scope->GetInfo( NULL, NULL, NULL, NULL, NULL, &display, NULL );
  if (FAILED(hr)) { RELEASE(scope); return hr; }

  Methods* methods = new Methods();
  if (methods == NULL) { RELEASE(scope); return E_OUTOFMEMORY; }

  hr = methods->Init( display, 1 );
  if (FAILED(hr)) { RELEASE(methods); RELEASE(scope); return hr; }

  
  long paramsCount;
  hr = scope->GetParameterCount( &paramsCount );
  if (FAILED(hr)) { RELEASE(methods); RELEASE(scope); return hr; }

  BSTR type;
  BSTR description;
  hr = scope->GetInfo( NULL, NULL, NULL, NULL, &type, NULL, &description );
  if (FAILED(hr)) { RELEASE(methods); RELEASE(scope); return hr; }

  hr = methods->Insert( description, type, paramsCount );
  if (FAILED(hr)) { RELEASE(methods); RELEASE(scope); return hr; }

  for (long paramIndex = 0; paramIndex < paramsCount; paramIndex++)
  {
    Scope* parameter;
    hr = scope->GetParameter( paramIndex, &parameter );
    if (FAILED(hr)) { RELEASE(methods); RELEASE(scope); return hr; }

    BSTR display;
    BSTR description;
    hr = parameter->GetInfo( NULL, NULL, NULL, NULL, NULL, &display, &description );
    RELEASE(parameter);
    if (FAILED(hr)) { RELEASE(methods); RELEASE(scope); return hr; }

    hr = methods->InsertParameter( display, description, NULL );    
    if (FAILED(hr)) { RELEASE(methods); RELEASE(scope); return hr; }
  }

  RELEASE(scope);

  *imethods = static_cast<IMethods*>(methods);
  return S_OK;
}


/*---------------------------------------------------------
 IScope
---------------------------------------------------------*/
STDMETHODIMP Scope::GetInfo( enum ScopeKind* kind, 
                         enum ScopeAccess* access,
                         enum ScopeStorage* storage,  
                         BSTR* name, 
                         BSTR* type,
                         BSTR* display, 
                         BSTR* description
                       ) 
{
  if (name) *name = bstrDup(m_name);
  if (type) *type = bstrDup(m_type);
  if (display)     
  {
    if (!m_display)
      *display     = bstrDup(m_name);
    else
      *display     = bstrDup(m_display);
  }

  if (description) 
  {
    if (!m_description)
    {
      if (m_display)
        *description = bstrDup(m_display);  
      else
        *description = bstrDup(m_name);
    }
    else
      *description = bstrDup(m_description);
  }

  if (kind)        *kind        = m_kind;
  if (access)      *access      = m_access;
  if (storage)     *storage     = m_storage;

  return S_OK;
}

STDMETHODIMP Scope::GetCount  ( VARIANT_BOOL locally, long* count )
{
   if (!count) return E_INVALIDARG;
          else *count = memberCount();

   if (!locally && m_parent)
   {
     long parentCount = 0;
     HRESULT hr = m_parent->GetCount( false, &parentCount);
     if (FAILED(hr)) return hr;
     *count += parentCount;
   }

   return S_OK;
}

STDMETHODIMP Scope::GetScope  ( long index, Scope** scope )
{
  if (!scope) return E_INVALIDARG;
         else *scope = NULL;

  ULONG count = memberCount();
  if (count <= index) 
  {
     if (m_parent) return m_parent->GetScope( index - count, scope );
              else return E_INVALIDARG;
  }
  else
  {
    ScopeList::iterator iter;
    for (iter = m_members.begin(); iter != m_members.end(); iter++)
    {
      if (!bstrEmpty((*iter)->m_name)) 
      {
        if (index == 0)
        {
          *scope = *iter;
          (*scope)->AddRef();
          return S_OK;
        }
        else index--;
      }
    }
    
    return E_FAIL;
  }
}

STDMETHODIMP Scope::MatchBest ( VARIANT_BOOL locally, BSTR name, long* index, VARIANT_BOOL* uniqueMatch )
{
  if (!index) return E_INVALIDARG;
        else  *index = 0;
  if (!uniqueMatch) return E_INVALIDARG;
        else  *uniqueMatch = 0;

  DWORD flags = 0;
  HRESULT hr  = matchBest( locally != 0, 0, 0, name, index, &flags );
  if (SUCCEEDED(hr))
  {
    if (flags & GBM_UNIQUE) *uniqueMatch = 1;
  }

  return hr;
}

STDMETHODIMP Scope::GetParameterCount( long* count )
{
  if (!count) return E_INVALIDARG;
        else *count = 0;

  ScopeList::iterator iter;
  for (iter = m_members.begin(); iter != m_members.end(); iter++)
  {
    if (((*iter)->m_kind == ScopeParameter || (*iter)->m_storage == StorageParameter)
        && !bstrEmpty((*iter)->m_name)) 
    {
      (*count)++;
    }
  }
  
  return S_OK;
}

STDMETHODIMP Scope::GetParameter( long index, Scope** parameter )
{
  if (!parameter) return E_INVALIDARG;
            else  *parameter = NULL;

  ScopeList::iterator iter;
  for (iter = m_members.begin(); iter != m_members.end(); iter++)
  {
    if (((*iter)->m_kind == ScopeParameter || (*iter)->m_storage == StorageParameter)
        && !bstrEmpty((*iter)->m_name)) 
    {
      if (index == 0) 
      {
        *parameter = *iter;
        (*parameter)->AddRef();
        return S_OK;
      }
      else index--;
    }
  }
 
  return E_FAIL;
}

STDMETHODIMP Scope::NarrowScope( long line, long idx, Scope** scope )
{
  if (!scope) return E_INVALIDARG;
        else  *scope = NULL;

  *scope = narrowScope( line, idx );
  return S_OK;
}

STDMETHODIMP Scope::LookupNames( BSTR name, Scope** matches )
{
  if (!matches) return E_INVALIDARG;
          else  *matches = NULL;

  if (bstrCompare( name, m_name ) == 0)
  {
    *matches = this;
    AddRef();
    return S_OK;
  }

  ScopeList::iterator iter;
  for (iter = m_members.begin(); iter != m_members.end(); iter++)
  {
    if (bstrCompare( name, (*iter)->m_name ) == 0)
    {
      *matches = *iter;
      (*matches)->AddRef();
      return S_OK;
    }
  }
  if (m_parent) return m_parent->LookupNames(name,matches);
          else  return S_FALSE;
}

STDMETHODIMP Scope::GetExternCount( long* count )
{
  if (!count) return E_INVALIDARG;
        else  *count = 0;
  return S_OK;
}

STDMETHODIMP Scope::GetExtern( long index, BSTR* external )
{
  if (!external) return E_INVALIDARG;
            else *external = NULL;

  return E_INVALIDARG;
}



/*---------------------------------------------------------
 finding
---------------------------------------------------------*/

Scope* Scope::narrowScope( int line, int idx )
{
  ScopeList::iterator iter;
  ScopeList::iterator prev;

  if (m_members.size() == 0)
  {
    AddRef();
    return this;
  }

  for (prev = iter = m_members.begin(); iter != m_members.end(); prev = iter, iter++)
  {
    if (((*iter)->m_startLine > line) ||
        ((*iter)->m_startLine == line && (*iter)->m_startIdx > idx))
      break;   
  }

  Scope* result = (*prev)->narrowScope( line,idx );  
  if (result->m_endLine < line ||
      (result->m_endLine == line && result->m_endIdx < idx)) 
    return this;
  else
    return result;
}


int bstrMatch( BSTR s, BSTR t )
{
  if (!s)       return 0;
  if (!t)       return 0;
  
  int i;
  for( i = 0; s[i] && t[i]; i++ )
  {
    if (s[i] != t[i]) break;
  }

  return i;
}
    

HRESULT Scope::matchBest( bool local, int i, int best, BSTR prefix, long* index, DWORD* flags )
{
  if (!index) return E_INVALIDARG;         
  
  long prefixLen = bstrLen(prefix);
  if (prefixLen == 0) return S_FALSE;
  

  ScopeList::iterator iter;
  for (iter = m_members.begin(); iter != m_members.end(); iter++)
  {
    int cmp = bstrMatch( prefix, (*iter)->m_name );
    
    if (cmp == prefixLen)
    {
    TRACE2( " found match: %i, %S\n", cmp, (*iter)->m_name );
      if (cmp > best)
      {
        best   = cmp;
        *index = i;
        *flags = GBM_UNIQUE;
      }
      else
      {
        *flags = 0;
      }
    }
    if (cmp > best)
    {
    TRACE2( " found good match: %i %S\n", cmp, (*iter)->m_name );
      best   = cmp;
      *index = i;
    }

    if (bstrLen((*iter)->m_name) > 0) i++;
  }

  if (m_parent && !local) 
    return m_parent->matchBest( local, i, best, prefix, index, flags );
  else
  {
    if (best == 0) 
    {
      *index = 0;
      return S_FALSE;
    }
    else 
      return S_OK;
  }
}

