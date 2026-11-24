/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef scope_h 
#define scope_h

/*---------------------------------------------------------
 Scope
 default scope implementation
 this needs a major cleanup, this is the only module
 still using STL.
---------------------------------------------------------*/
class Scope;

typedef vector<Scope*> ScopeList;


HRESULT InsertScope( 
        Scope* rootScope, bool merge,
        int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeKind kind,
        enum ScopeAccess access,
        enum ScopeStorage storage,
        BSTR name,     BSTR type,
        BSTR display,  BSTR description );

HRESULT AddIncludeScope( 
        Scope* rootScope, 
        int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeAccess access, BSTR name );
        
HRESULT AddExternScope( 
        Scope* rootScope, 
        int startLine, int startIdx,
        int endLine,   int endIdx,
        IScope* externScope );


class Scope : public IScope
{
private:  
  ULONG     m_refCount;
  BSTR      m_name;
  BSTR      m_type;
  BSTR      m_display;
  BSTR      m_description;
  int       m_startLine,m_startIdx;
  int       m_endLine, m_endIdx;
  ScopeKind m_kind;
  ScopeAccess m_access;
  ScopeStorage m_storage;

  Scope*    m_parent;  
  ScopeList m_members;

  friend bool isBefore( Scope& scope1, Scope& scope2 );
  friend bool startsInside( Scope& scope1, Scope& scope2 );
  
private:
  STDMETHODIMP GetCount  ( VARIANT_BOOL locally, long* count );
  STDMETHODIMP MatchBest ( VARIANT_BOOL locally, BSTR name, long* index, VARIANT_BOOL* uniqueMatch );
  
  STDMETHODIMP GetParameterCount( long* count );
  STDMETHODIMP GetParameter( long index, Scope** parameter );

  STDMETHODIMP NarrowScope( long line, long idx, Scope** scope );
  
  STDMETHODIMP GetExternCount( long* count );
  STDMETHODIMP GetExtern( long index, BSTR* external );

	
  virtual void clear();
  int     memberCount();
  Scope*  narrowScope( int line, int idx );
  HRESULT matchBest( bool local, int i, int best, BSTR prefix, long* index, DWORD* flags );


public:
  void insertScope( bool merge, Scope* scope );
  STDMETHODIMP GetInfo   ( enum ScopeKind* kind, 
                           enum ScopeAccess* access,
                           enum ScopeStorage* storage,  
                           BSTR* name, 
                           BSTR* type,
                           BSTR* display, 
                           BSTR* description
                         ); 
  STDMETHODIMP GetScope  ( long index, Scope** scope );
  STDMETHODIMP LookupNames( BSTR name, Scope** matches );

public:
  Scope( int line, int idx );	//used in parser to create 'root' scope
  Scope(int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeKind kind,
        enum ScopeAccess access,
        enum ScopeStorage storage,
        BSTR name,     BSTR type,
        BSTR display,  BSTR description );

  virtual ~Scope();

  // IUnknown methods 
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  STDMETHODIMP_(ULONG) InternAddRef();
  STDMETHODIMP_(ULONG) InternRelease();

  //implement IDispatch (for IScope only)
  STDMETHODIMP GetTypeInfoCount( out UINT* count );
  STDMETHODIMP GetTypeInfo     ( in UINT index, in LCID lcid, out ITypeInfo** typeInfo );
  STDMETHODIMP GetIDsOfNames   ( in REFIID iid, in OLECHAR** names, in UINT count, in LCID lcid, out DISPID* dispids );
  STDMETHODIMP Invoke          ( in DISPID dispid, in REFIID iid, in LCID lcid, in WORD flags, in DISPPARAMS* args, out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg );

  //IScope
  STDMETHODIMP GetDeclarations( in long line, in long idx, 
                                in INames* names, out IDeclarations** decls );   
  STDMETHODIMP GetDataTipText ( in long line, in long idx, 
                                in INames* names, out BSTR* text );   
  STDMETHODIMP GetMethods     ( in long line, in long idx, 
                                in INames* names, out IMethods** methods );   
  
  
  
};

#endif
