/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef names_h
#define names_h

struct NameInfo
{
  BSTR  m_name;
  BSTR  m_selector;
};

class Names : public INames
{
private:
  ULONG     m_refCount;
  NameInfo* m_names;
  long      m_size;

  long      m_last;
  long      m_start;

public:
  Names();
  virtual ~Names();

  STDMETHODIMP Init( in long size );
  STDMETHODIMP InsertNoDup( in BSTR name, in BSTR selector );

  STDMETHODIMP InitFromNames( in INames* names );
  STDMETHODIMP DropHead();
  STDMETHODIMP DropLast();
  STDMETHODIMP PushHead( in BSTR name, in BSTR selector );
  STDMETHODIMP PushLast( in BSTR name, in BSTR selector );

  STDMETHODIMP_(bool) IsEmpty();
  STDMETHODIMP_(bool) SameNameHead( in BSTR name );

  // IUnknown methods:
  STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //implement IDispatch (for INames only)
  STDMETHODIMP GetTypeInfoCount( out UINT* count );
  STDMETHODIMP GetTypeInfo     ( in UINT index, in LCID lcid, out ITypeInfo** typeInfo );
  STDMETHODIMP GetIDsOfNames   ( in REFIID iid, in OLECHAR** names, in UINT count, in LCID lcid, out DISPID* dispids );
  STDMETHODIMP Invoke          ( in DISPID dispid, in REFIID iid, in LCID lcid, in WORD flags, in DISPPARAMS* args, out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg );

  //INames
  STDMETHODIMP GetCount( out long* count );
  STDMETHODIMP GetName( in long index, out BSTR* name );
  STDMETHODIMP GetSelector( in long index, out BSTR* selector );
};

#endif
