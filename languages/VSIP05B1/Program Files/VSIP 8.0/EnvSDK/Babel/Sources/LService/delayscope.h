/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef delayscope_h
#define delayscope_h

/*---------------------------------------------------------
  DelayScope
---------------------------------------------------------*/
class DelayScope: public IScope
{
private:
  ULONG             m_refCount;

  IServiceProvider* m_provider;
  IBabelProject*    m_project;
  BSTR              m_fileName;
  IScope*           m_scope;


  STDMETHODIMP LoadScope();

public:
  DelayScope( in IServiceProvider* provider, in IBabelProject* project, in BSTR fileName );
  ~DelayScope();

  // IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IDispatch 
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

};

#endif
