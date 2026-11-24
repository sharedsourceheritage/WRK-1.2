/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef library_h
#define library_h

class Library : public IParseSink
{
private:
  ULONG             m_refCount;

  BSTR              m_filePath;
  IServiceProvider* m_provider;
  Preferences*      m_preferences;
  IBabelService*    m_babelService;  
  IBabelProject*    m_project;
  IScope*           m_iscope;
  
  //just live during sinking
  Scope*            m_scope;

public:
  Library( in IServiceProvider* provider,
           in Preferences*      preferences, 
           in IBabelService*    babelService, 
           in IBabelProject*    project,
           in BSTR              filePath );
  ~Library();

  STDMETHODIMP Init();

  //Library
  STDMETHODIMP_(bool) SamePath( in BSTR filePath );
  STDMETHODIMP        GetScope( out IScope** scope );
  
  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

   //implement IDispatch (for IParseSink only)
  STDMETHODIMP GetTypeInfoCount( out UINT* count );
  STDMETHODIMP GetTypeInfo     ( in UINT index, in LCID lcid, out ITypeInfo** typeInfo );
  STDMETHODIMP GetIDsOfNames   ( in REFIID iid, in OLECHAR** names, in UINT count, in LCID lcid, out DISPID* dispids );
  STDMETHODIMP Invoke          ( in DISPID dispid, in REFIID iid, in LCID lcid, in WORD flags, in DISPPARAMS* args, out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg );

  // IParseSink
  STDMETHODIMP ErrorMessage( in long startLine, in long endLine,
                             in long startIdx,  in long endIdx,
                             in Severity sev, in BSTR message );

  STDMETHODIMP MatchPair( in long startLine1, in long startIdx1
                        , in long endLine1,   in long endIdx1 
                        , in long startLine2, in long startIdx2
                        , in long endLine2,   in long endIdx2 );
  
  STDMETHODIMP MatchTriple( in long startLine1, in long startIdx1
                        , in long endLine1,   in long endIdx1 
                        , in long startLine2, in long startIdx2
                        , in long endLine2,   in long endIdx2
                        , in long startLine3, in long startIdx3
                        , in long endLine3,   in long endIdx3 );
  
  STDMETHODIMP StartName( in long line, in long startIdx, in long endIdx );
  STDMETHODIMP QualifyName( in long lineSelect, in long startIdxSelect, in long endIdxSelect,
                            in long line, in long startIdx, in long endIdx );

  STDMETHODIMP AutoExpression( in long startLine, in long endLine,
                               in long startIdx,  in long endIdx );     
  STDMETHODIMP CodeSpan( in long startLine, in long startIdx, 
                         in long endLine, in long endIdx );
  

  STDMETHODIMP StartParameters( in long line, in long idx );
  STDMETHODIMP Parameter      ( in long line, in long idx );
  STDMETHODIMP EndParameters  ( in long line, in long idx );

  STDMETHODIMP GetPackage( out IBabelPackage** package );
  STDMETHODIMP GetProject( out IBabelProject** project );
  STDMETHODIMP GetFileName( out BSTR* filePath );								

  STDMETHODIMP AddScope(  in long startLine, in long startIdx,
                          in long endLine,   in long endIdx,
                          in enum ScopeKind kind,
                          in enum ScopeAccess access,
                          in enum ScopeStorage storage,
                          in long glyph,
                          in BSTR name,     in BSTR type,
                          in BSTR display,  in BSTR description,
                          in VARIANT_BOOL merge
                        );                       
  STDMETHODIMP AddInclude( in long startLine, in long startIdx,
                           in long endLine,   in long endIdx,
                           in enum ScopeAccess access, in BSTR name );
  STDMETHODIMP AddExtern( in long startLine, in long startIdx,
                           in long endLine,   in long endIdx,
                           in IScope* scope );

};

#endif
