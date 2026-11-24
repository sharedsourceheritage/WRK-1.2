/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef scope_h 
#define scope_h

class Scope;

/*---------------------------------------------------------
 Scope
---------------------------------------------------------*/
class Block;

class Scope : public IScope
{
private:  
  ULONG       m_refCount;
  Block*      m_block;
  ObjectList  m_externs;
  bool        m_entered;
  
  HRESULT enter();
  void    leave();


public:
  Scope();	
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
  STDMETHODIMP Narrow         ( in long line, in long idx,
                                out BSTR* name, out long* nameLine );
  
  //ScopeBuilder
  HRESULT InsertScope(
        bool merge,
        int startLine, int startIdx,
        int endLine,   int endIdx,
        enum ScopeKind kind,
        enum ScopeAccess access,
        enum ScopeStorage storage,
        long glyph,
        BSTR name,     BSTR type,
        BSTR display,  BSTR description );
  
  HRESULT AddIncludeScope( 
          int startLine, int startIdx,
          int endLine,   int endIdx,
          enum ScopeAccess access, BSTR name );

  HRESULT AddExternScope( 
          int startLine, int startIdx,
          int endLine,   int endIdx,
          IScope* externScope );
};

#endif
