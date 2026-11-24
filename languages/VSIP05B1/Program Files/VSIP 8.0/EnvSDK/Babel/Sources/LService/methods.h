/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef methods_h
#define methods_h

struct ParameterInfo
{
  ParameterInfo* next;
  BSTR  name;
  BSTR  display;
  BSTR  description;
};

struct MethodInfo
{
  MethodInfo*    next;
  BSTR           description;
  BSTR           type;
  ParameterInfo* params;
};

/*---------------------------------------------------------
  Methods
-----------------------------------------------------------*/
class Methods : public IMethods
{
private:
  ULONG       m_refCount;
  BSTR        m_name;
  MethodInfo* m_methods;

public:
  Methods();
  ~Methods();

  STDMETHODIMP Init( in BSTR name);
  STDMETHODIMP Insert( in BSTR description, in BSTR type );
  STDMETHODIMP InsertParameter( in BSTR name, in BSTR display, in BSTR description );

  STDMETHODIMP GetMethod( in long index, out MethodInfo** method );
  STDMETHODIMP_(MethodInfo*) GetLast();

  // IUnknown methods:
  STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //implement IDispatch (for IMethods only)
  STDMETHODIMP GetTypeInfoCount( out UINT* count );
  STDMETHODIMP GetTypeInfo     ( in UINT index, in LCID lcid, out ITypeInfo** typeInfo );
  STDMETHODIMP GetIDsOfNames   ( in REFIID iid, in OLECHAR** names, in UINT count, in LCID lcid, out DISPID* dispids );
  STDMETHODIMP Invoke          ( in DISPID dispid, in REFIID iid, in LCID lcid, in WORD flags, in DISPPARAMS* args, out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg );

  //IMethods
  STDMETHODIMP GetCount      ( out long* count );
  STDMETHODIMP GetName       ( out BSTR* name );
  STDMETHODIMP GetDescription( in long index, out BSTR* description );    
  STDMETHODIMP GetType       ( in long index, out BSTR* type );
    
  STDMETHODIMP GetParameterCount( in long index, out long* count );
  STDMETHODIMP GetParameterInfo ( in long index, 
                                  in long parameter, 
                                  out BSTR* name,
                                  out BSTR* display,
                                  out BSTR* description );
};

#endif
