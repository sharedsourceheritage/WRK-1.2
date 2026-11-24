/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

/*---------------------------------------------------------
 TODO: doesn't support includes yet. 
        (used for example with inheritance)
 TODO: doesn't support visibility yet (private, protected, public)
---------------------------------------------------------*/
#include "project.h"
#include "dllmain.h"  //for g_typeInfoScope
#include "scope.h"
#include "declarations.h"
#include "methods.h"
#include "names.h"

/*---------------------------------------------------------
 Block
---------------------------------------------------------*/
class Block
{
public:
  Block*  m_next;
  Block*  m_parent;

  int     m_startLine, m_startIdx;
  int     m_endLine, m_endIdx;
  
  
public:    
  Block( int startLine, int startIdx,
         int endLine,   int endIdx );
  virtual ~Block();

  virtual bool isBefore( Block* block );
  virtual bool startsInside( Block* block );
  virtual void insertBlock( bool merge, Block* block );

  virtual bool    contains( int line, int idx );
  virtual Block*  narrow( int line, int idx );

  virtual HRESULT getNameLine( out BSTR* name, out long* line ) = 0;
  virtual HRESULT getDataTipText( in INames* names, out BSTR* text ) = 0;
  virtual HRESULT getMethods( in INames* names, out IMethods** methods ) = 0;
  virtual HRESULT insertParameter( in Methods* methods );
  virtual HRESULT getDeclarations( in bool local, in INames* names, in Declarations* decls ) = 0;
  virtual HRESULT insertInto( in Declarations* decls ) = 0;
  
  virtual HRESULT lookup( in Names* names, out Block** block );
  virtual HRESULT lookupMember( in Names* names, out Block** block ) = 0;
  virtual HRESULT lookupSelf( in Names* names, out Block** block ) = 0;
};


class NamedBlock : public Block
{
private:
  Block*  m_members;

  BSTR    m_name;
  BSTR    m_type;
  BSTR    m_display;
  BSTR    m_description;
  long    m_glyph;

  ScopeKind     m_kind;
  ScopeAccess   m_access;
  ScopeStorage  m_storage;

  long    guessGlyph();
  long    groupIcon( in long group );

public:
  NamedBlock( int startLine, int startIdx,
              int endLine,   int endIdx,     
              enum ScopeKind    kind,
              enum ScopeAccess  access,
              enum ScopeStorage storage,
              long glyph,
              BSTR name,     BSTR type,
              BSTR display,  BSTR description );

  ~NamedBlock();

  void insertBlock( bool merge, Block* block );
  Block*  narrow( int line, int idx );

  HRESULT getDeclarations( in bool local, in INames* names, in Declarations* decls );
  HRESULT insertInto( in Declarations* decls );

  HRESULT getNameLine( out BSTR* name, out long* line );
  HRESULT getDataTipText( in INames* names, out BSTR* text );
  HRESULT getMethods( in INames* names, out IMethods** methods );
  HRESULT insertParameter( in Methods* methods );
  HRESULT lookupMember( in Names* names, out Block** block );
  HRESULT lookupSelf( in Names* names, out Block** block );

};



class ExternBlock : public Block
{
private:
  IScope* m_scope;

public:
  ExternBlock( int startLine, int startIdx,
               int endLine,   int endIdx,     
               IScope* scope );
              
  ~ExternBlock();  

  virtual bool isBefore( Block* block );
  virtual bool startsInside( Block* block );



  HRESULT getDeclarations( in bool local, in INames* names, in Declarations* decls );
  HRESULT insertInto( in Declarations* decls );

  HRESULT getNameLine( out BSTR* name, out long* line );
  HRESULT getDataTipText( in INames* names, out BSTR* text );
  HRESULT getMethods( in INames* names, out IMethods** methods );

  HRESULT lookupMember( in Names* names, out Block** block );
  HRESULT lookupSelf( in Names* names, out Block** block );
};


/*---------------------------------------------------------
 Scope
---------------------------------------------------------*/

#define ENTER      if (FAILED(enter())) return E_FAIL
#define LEAVE(x)   return (leave(), x)

/*---------------------------------------------------------
 Scope
---------------------------------------------------------*/
Scope::Scope() : m_externs()
{
  TRACE_CREATE_HIDE( "Scope", static_cast<IScope*>(this) );
  m_refCount= 1;
  m_entered = false;
  m_block   = new NamedBlock( 0, 0, 0, 0, ScopeUnknown, AccessPublic, StorageStatic, 0, NULL, NULL, NULL, NULL );
}

Scope::~Scope()
{
  DELETE(m_block);
  m_externs.Clear();  //paranoia
  TRACE_DESTROY( static_cast<IScope*>(this));
}


HRESULT Scope::enter()
{
  TRACE("scope::enter");
  if (m_entered)
  {
    TRACE( "scope::enter failed" );
    return E_FAIL;
  }
  else
  {
    m_entered = true;
    return S_OK;
  }
}

void Scope::leave()
{
  TRACE("scope::leave");
  ASSERT(m_entered);
  m_entered = false;
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

STDMETHODIMP_(ULONG) Scope::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Scope::Release()
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
HRESULT lookupBlock( in long line, in long idx, in INames* inames,
                     in bool includeLast,
                     out Names** names,
                     inout Block** block )
{
  INOUTARG(block);
  OUTARG(names);
  HRESULT hr = S_OK;
  
  //narrow scope to lexical position
  *block = (*block)->narrow( line, idx );
  if (*block == NULL) return E_FAIL;

  //create duplicate of names
  *names = new Names();
  if (*names == NULL) return E_OUTOFMEMORY;

  hr = (*names)->InitFromNames(inames);
  if (FAILED(hr)) { RELEASE(*names); return hr; }

  //drop last?
  if (!includeLast)
  {
    (*names)->DropLast();   
  }

  if (!(*names)->IsEmpty())
  {
    hr = (*block)->lookup( *names, block );
    if (FAILED(hr))     { RELEASE(*names); return hr; }
    if (*block == NULL) { RELEASE(*names); return E_FAIL; }
  }
  
  return S_OK;
}

STDMETHODIMP Scope::Narrow( in long line, in long idx, out BSTR* name, out long* nameLine )
{
  OUTARG(name);
  if (nameLine) *nameLine = 0;

  Block* block = m_block->narrow( line, idx );
  if (block == NULL) return E_FAIL;
  
  HRESULT hr = block->getNameLine( name, nameLine );
  if (FAILED(hr)) return hr;

  return S_OK;
}


STDMETHODIMP Scope::GetDataTipText( in long line, in long idx, 
                                     in INames* inames,
                                     out BSTR* text )
{
  TRACE("Scope::GetDataTipText" );
  OUTARG(text);
  HRESULT hr;

  ENTER;

#ifndef NDEBUG  
  if (inames)
  {
    long count;
    inames->GetCount(&count);
    for (long index = 0; index < count; index++)
    {
      BSTR name;
      BSTR selector;
      inames->GetName( index, &name );
      inames->GetSelector( index, &selector );
      TRACE2( "-- '%S' %S'", name, selector );
      bstrFree(name);
      bstrFree(selector);
    }
  }
#endif

  Block* block = m_block;
  Names* names = NULL;
  hr = lookupBlock( line, idx, inames, true, &names, &block );
  if (FAILED(hr)) LEAVE(hr);

  hr = block->getDataTipText( names, text );
  RELEASE(names);
  if (FAILED(hr)) LEAVE(hr);

  LEAVE(S_OK);
}


STDMETHODIMP Scope::GetDeclarations( in long line, in long idx, 
                                     in INames* inames,
                                     out IDeclarations** idecls )
{
  TRACE( "Scope::GetDeclarations" );
  OUTARG(idecls);
  HRESULT hr;
  ENTER;

#ifndef NDEBUG
  if (inames)
  {
    long count;
    inames->GetCount(&count);
    for (long index = 0; index < count; index++)
    {
      BSTR name;
      BSTR selector;
      inames->GetName( index, &name );
      inames->GetSelector( index, &selector );
      TRACE2( "-- '%S' %S'", name, selector );
      bstrFree(name);
      bstrFree(selector);
    }
  }
#endif

  //get names count
  long count = 0;
  BSTR lastName     = NULL;
  BSTR lastSelector = NULL;
  if (inames) 
  {
    inames->GetCount(&count);
    if (count > 0)
    {
      inames->GetName( count-1, &lastName );
      inames->GetSelector( count-1, &lastSelector );
    }
  }

  bool includeLast = (SysStringLen(lastSelector)>0);


  Block* block = m_block;
  Names* names = NULL;
  hr = lookupBlock( line, idx, inames, includeLast, &names, &block );
  if (FAILED(hr)) { bstrFree(lastName);  bstrFree(lastSelector); LEAVE(hr); }

  if (!includeLast)   
  {
    names->PushLast(lastName,lastSelector);
  }
  bstrFree(lastName);
  bstrFree(lastSelector);

  Declarations* decls = new Declarations();
  if (!decls) { RELEASE(names); LEAVE(E_OUTOFMEMORY); }

  hr = block->getDeclarations( (count > 1) || (includeLast), names, decls );
  RELEASE(names);
  if (FAILED(hr)) { RELEASE(decls); LEAVE(hr); }

  hr = decls->QueryInterface( IID_IDeclarations, reinterpret_cast<void**>(idecls) );
  RELEASE(decls);
  if (FAILED(hr)) LEAVE(hr);

  LEAVE(S_OK);
}


STDMETHODIMP Scope::GetMethods( in long line, in long idx, 
                                in INames* inames, out IMethods** imethods )
{
  OUTARG(imethods);
  HRESULT hr;
  ENTER;

  Block* block  = m_block;
  Names* names  = NULL;
  hr = lookupBlock( line, idx, inames, true, &names, &block );
  if (hr != S_OK || !block) { RELEASE(names); LEAVE(E_FAIL); }

  hr = block->getMethods( names, imethods );
  RELEASE(names);
  if (FAILED(hr)) LEAVE(hr);

  LEAVE(S_OK);
}



/*---------------------------------------------------------
 Scope::InsertScope
---------------------------------------------------------*/
HRESULT Scope::InsertScope(
        bool merge,
        int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeKind kind,
        enum ScopeAccess access,
        enum ScopeStorage storage,
        long glyph,
        BSTR name,     BSTR type,
        BSTR display,  BSTR description )
{
  Block* block = new NamedBlock( startLine, startIdx, endLine, endIdx, 
                                kind, access, storage, glyph,
                                name, type, display, description );
  if (!block) return E_OUTOFMEMORY;

  m_block->insertBlock( merge, block );  
  
  return S_OK;
}


HRESULT Scope::AddIncludeScope( 
        int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeAccess access, BSTR name )
{
  return E_NOTIMPL;
}
        
HRESULT Scope::AddExternScope( 
        int startLine, int startIdx,
        int endLine,   int endIdx,
        IScope* externScope )
{
  TRACE("AddExternScope");
  Block* block = new ExternBlock( startLine, startIdx, endLine, endIdx, externScope );
  if (!block) return E_OUTOFMEMORY;

  m_block->insertBlock( false, block );
  return S_OK;
}


/*---------------------------------------------------------
 Block
---------------------------------------------------------*/
Block::Block( 
        int startLine, int startIdx,
        int endLine,   int endIdx )
{
  m_next      = NULL;
  m_parent    = NULL;

  m_endLine   = endLine;
  m_startLine = startLine;
  m_endIdx    = endIdx;
  m_startIdx  = startIdx;   
}

Block::~Block()
{
  DELETE(m_next);
}


/*---------------------------------------------------------
 insertBlock
---------------------------------------------------------*/
bool Block::isBefore( Block* block )
{  
  return (m_endLine < block->m_startLine 
        || (m_endLine == block->m_startLine && m_endIdx < block->m_startIdx));
}

bool Block::startsInside( Block* block )
{
  return (  (m_startLine > block->m_startLine 
             || (m_startLine == block->m_startLine && m_startIdx > block->m_startIdx))
         && (m_startLine < block->m_endLine  
             || (m_startLine == block->m_endLine && m_startIdx < block->m_endIdx)) );
}


void Block::insertBlock( bool merge, Block* block )
{
  TRACE("illegal call to Block::insertBlock");
  DELETE(block);
}

HRESULT Block::insertParameter( in Methods* methods )
{
  return S_FALSE;
}

/*---------------------------------------------------------
 narrowScope
---------------------------------------------------------*/
bool Block::contains( int line, int idx )
{
  return (  (m_startLine < line || (m_startLine == line && m_startIdx <= idx))
         && (m_endLine > line || (m_endLine == line && m_endIdx >= idx)) );
}


Block* Block::narrow( int line, int idx )
{
  return this;
}


/*---------------------------------------------------------
 Block::lookup
---------------------------------------------------------*/
HRESULT Block::lookup( in Names* names, out Block** block )
{
  //first look if we have a member
  HRESULT hr = lookupMember( names, block );
  if (hr != S_OK && m_parent)
    return m_parent->lookup( names, block ); //and than in the parent scope
  else
    return hr;
}



/*---------------------------------------------------------
 NamedBlock
---------------------------------------------------------*/
NamedBlock::NamedBlock( 
        int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeKind kind,
        enum ScopeAccess access,
        enum ScopeStorage storage,
        long glyph,
        BSTR name,     BSTR type,
        BSTR display,  BSTR description ) : Block( startLine, startIdx, endLine, endIdx )
{
  m_members   = NULL;

  m_name        = (name ? SysAllocString(name) : SysAllocString(L""));
  m_display     = (display ? SysAllocString(display) : SysAllocString(m_name));
  m_description = (description ? SysAllocString(description) : SysAllocString(m_display));
  m_type        = (type ? SysAllocString(type) : SysAllocString(L""));
  m_kind        = kind;
  m_access      = access;
  m_storage     = storage;

  m_glyph       = glyph;
  if (m_glyph < 0 || m_glyph >= g_imageListCount) m_glyph = guessGlyph();  
}

NamedBlock::~NamedBlock()
{
  DELETE(m_members);
  
  bstrFree(m_name);
  bstrFree(m_display);
  bstrFree(m_type);
  bstrFree(m_description);
}

void NamedBlock::insertBlock( bool merge, Block* block )
{
  Block* prev   = NULL;
  Block* member = NULL;
  for (member = m_members; member; prev = member, member = member->m_next )
  {
    if (block->isBefore(member))
      break; //first
    else if (member->isBefore(block))
      continue; //after this one
    else if (block->startsInside(member))
      member->insertBlock(merge, block); //subsume
    else
    {
      //the new block encloses one or more members
      Block* final = member;
      while (final && final->startsInside(block) )
      {
        Block* next = final->m_next;
        block->insertBlock( merge, final );
        final = next;
      }
      if (prev) prev->m_next = final;
           else m_members    = final;
      break;
    }
  }
    
  //insert right before member
  block->m_parent = this;
  if (prev) 
  {
    block->m_next   = prev->m_next;
    prev->m_next    = block;
  }
  else
  {
    block->m_next   = m_members;
    m_members       = block;
  }
}
  

Block* NamedBlock::narrow( int line, int idx )
{
  if (line == 0 && idx == 0) return this;

  for (Block* member = m_members; member; member = member->m_next )
  {
    if (member->contains(line,idx))
      return member->narrow( line, idx );
  }

  return this;
}

HRESULT NamedBlock::lookupSelf( in Names* names, out Block** block )
{
  OUTARG(block);
  INARG(names);

  //is it us?
  if (names->SameNameHead(m_name))
  {
    TRACE1("NamedBlock::lookupSelf: matched: %S", m_name );
    
    //if typed variable, lookup the type
    if (m_kind == ScopeVariable && SysStringLen(m_type)>0)
    {
       BSTR selector = NULL;
       names->GetSelector(0,&selector );
       names->DropHead();
       if (0 == SysStringLen(selector))
       {
          //no selector, we are done
         bstrFree(selector);
          *block = this;
          return S_OK;
       }
       else
       {
          //lookup the type          
          names->PushHead(m_type,selector);
          bstrFree(selector);
       }
       return lookup( names, block );
    }
    else
    {
      //are we done?
      names->DropHead();
      if (names->IsEmpty())
      {
        *block = this;
        return S_OK;
      }
      else 
      {
        //otherwise try the members
        return lookupMember( names, block );
      }
    }
  }

  return S_FALSE;
}

HRESULT NamedBlock::lookupMember( in Names* names, out Block** block )
{
  BSTR name =NULL;
  names->GetName( 0, &name );
TRACE2("NamedBlock::lookupMembers: %S for %S", m_name, name );
  bstrFree(name);

  //do we have a member with this name?
  for (Block* member = m_members; member; member = member->m_next )
  {
    HRESULT hr = member->lookupSelf( names, block );
    if (hr == S_OK) return hr;      
  }

  return S_FALSE;
}


HRESULT NamedBlock::getNameLine( out BSTR* name, out long* line )
{
  OUTARG(name);

  if ((0==SysStringLen(m_name)) && m_parent)
  {
    m_parent->getNameLine( name, line );
  }
  else
  {
    if (line) *line = m_startLine;
    *name = SysAllocString( m_name );
  }
  return S_OK;
}


HRESULT NamedBlock::getDataTipText( in INames* names, out BSTR* text )
{
  OUTARG(text);
  *text = SysAllocString( m_description );
  return S_OK;
}

HRESULT NamedBlock::getMethods( in INames* names, out IMethods** imethods )
{
  OUTARG(imethods);
  HRESULT hr;

  if (m_kind != ScopeProcedure) return S_FALSE;
  
  Methods* methods = new Methods();
  if (!methods) return E_OUTOFMEMORY;

  hr = methods->Init( m_name );
  if (FAILED(hr)) { RELEASE(methods); return hr; }

  hr = methods->Insert( m_description, m_type );
  if (FAILED(hr)) { RELEASE(methods); return hr; }

  for (Block* member = m_members; member; member = member->m_next )
  {
    member->insertParameter( methods );
    //HRESULT hr = member->insertParameter( methods );
    //if (FAILED(hr)) { RELEASE(methods); return hr; }
  }

  hr = methods->QueryInterface( IID_IMethods, reinterpret_cast<void**>(imethods) );
  RELEASE(methods);
  if (FAILED(hr)) return hr;

  return S_OK;
}

HRESULT NamedBlock::insertParameter( in Methods* methods )
{
  INARG(methods);
  if (m_storage == StorageParameter) 
  {
    TRACE3( "NamedBlock::insertParameter: %S %S %S", m_name, m_display, m_description );
    return methods->InsertParameter( m_display, m_description, NULL );
  }
  else
  {
    return S_FALSE;
  }
}

HRESULT NamedBlock::getDeclarations( in bool local, in INames* names, in Declarations* decls )
{
  for (Block* member = m_members; member; member = member->m_next )
  {
    member->insertInto( decls );
    //HRESULT hr = member->insertInto( decls );
    //if (FAILED(hr)) return hr;
  }

  if (!local && m_parent) return m_parent->getDeclarations( false, names, decls );
                    else  return S_OK;
}

HRESULT NamedBlock::insertInto( in Declarations* decls )
{
  INARG(decls);
  if (0==SysStringLen(m_name)) return S_OK;
                    else return decls->Insert( m_name, m_description, m_glyph );
}


long  NamedBlock::groupIcon( in long group )
{
  switch (m_access) 
  {
    case AccessPrivate  : return (group * IconGroupSize + IconItemPrivate );
    case AccessProtected: return (group * IconGroupSize + IconItemProtected );
    case AccessPublic   :
    default             : return (group * IconGroupSize + IconItemPublic );
  }
}

long  NamedBlock::guessGlyph()
{
    switch (m_kind)
    {
      case ScopeModule:   return IconLibrary;
      case ScopeClass:    return groupIcon( IconGroupClass );
      case ScopeInterface:return groupIcon( IconGroupInterface );
      case ScopeUnion:    return groupIcon( IconGroupUnion );

      case ScopeProcedure:return groupIcon( IconGroupMethod );

      case ScopeVariable:
        {
          switch (m_storage)
          {
          case StorageMember:     return groupIcon( IconGroupFieldBlue ); 
          
          case StorageConstant:
          case StorageStatic:     return groupIcon( IconGroupFieldRed );
          
          
          case StorageParameter:  
          case StorageResult:     
          case StorageLocal:      return groupIcon( IconGroupFieldYellow );
          case StorageType:       return groupIcon( IconGroupType );
          case StorageOther:
          default:                return groupIcon( IconGroupFieldBlue ); 
          }
          break;
        }

      case ScopeBlock:    return groupIcon( IconGroupNameSpace );       
      default:            return groupIcon( IconGroupMethod );
    }
}


/*---------------------------------------------------------
 ExternBlock
---------------------------------------------------------*/
ExternBlock::ExternBlock( 
        int startLine, int startIdx,
        int endLine,   int endIdx,
        IScope* scope ) : Block( startLine, startIdx, endLine, endIdx )
{
  TRACE("Create ExternBlock");
  m_scope = scope; ADDREF(m_scope);
}

ExternBlock::~ExternBlock()
{
  TRACE("Destroy ExternBlock");
  RELEASE(m_scope);
}

bool ExternBlock::isBefore( Block* block )
{
  return true;
}

bool ExternBlock::startsInside( Block* block )
{
  return true;
}


HRESULT ExternBlock::lookupSelf( in Names* names, out Block** block )
{
  OUTARG(block);
  INARG(names);

  return lookupMember(names,block);
}

HRESULT ExternBlock::lookupMember( in Names* names, out Block** block )
{
  OUTARG(block);
  INARG(names);

  //do we have a member with this name?
  BSTR text = NULL;
  HRESULT hr = m_scope->GetDataTipText( 0,0, static_cast<INames*>(names), &text );
  bstrFree(text);
  if (SUCCEEDED(hr))
  {
    *block = this;
    return S_OK;
  }
  else
    return hr;
}

HRESULT ExternBlock::getNameLine( out BSTR* name, out long* line )
{
  if (m_parent) return m_parent->getNameLine( name, line );
           else return m_scope->Narrow( 0, 0, name, line );
}

HRESULT ExternBlock::getDataTipText( in INames* names, out BSTR* text )
{
  OUTARG(text);
  return m_scope->GetDataTipText( 0, 0, names, text );
}

HRESULT ExternBlock::getMethods( in INames* names, out IMethods** methods )
{
  OUTARG(methods);
  return m_scope->GetMethods( 0,0,names,methods );
}

HRESULT ExternBlock::getDeclarations( in bool local, in INames* names, in Declarations* decls )
{
  TRACE("ExternBlock::GetDeclarations");
  INARG(decls);
  HRESULT hr = S_OK;

  IDeclarations* idecls = NULL;
  hr = m_scope->GetDeclarations( 0, 0, names, &idecls );
  if (FAILED(hr)) return hr;

  BSTR name = NULL;
  BSTR desc = NULL;
  long glyph = 0;
  long count = 0;
  long i     = 0;

  hr = idecls->GetCount( &count );
  if (FAILED(hr)) goto end;

  for (i = 0; i < count; i++)
  {
    hr = idecls->GetName( i, &name );
    if (FAILED(hr)) goto end;

    hr = idecls->GetDescription( i, &desc );
    if (FAILED(hr)) goto end;

    hr = idecls->GetGlyph( i, &glyph );
    if (FAILED(hr)) goto end;

    hr = decls->Insert( name, desc, glyph );
    if (FAILED(hr)) goto end;
  }

end:
  RELEASE(idecls);

  //return hr;
  return S_OK;
}

HRESULT ExternBlock::insertInto( in Declarations* decls )
{
  INARG(decls);
  return getDeclarations( true, NULL, decls );
}
