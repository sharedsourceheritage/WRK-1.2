/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef declarations_h
#define declarations_h

struct DeclInfo
{
  DeclInfo* next;
  BSTR      name;
  BSTR      description;
  long      glyph;
};

/*---------------------------------------------------------
  Declarations
-----------------------------------------------------------*/
class Declarations : public IDeclarations
{
private:
  ULONG     m_refCount;
  DeclInfo* m_decls;

  STDMETHODIMP GetDecl( in long index, out DeclInfo** decl );

public:
  Declarations();
  ~Declarations();

  STDMETHODIMP Insert( in BSTR name, in BSTR description, in long glyph, in bool allowMultiple = false );

  // IUnknown methods:
  STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //implement IDispatch (for IDeclarations only)
  STDMETHODIMP GetTypeInfoCount( out UINT* count );
  STDMETHODIMP GetTypeInfo     ( in UINT index, in LCID lcid, out ITypeInfo** typeInfo );
  STDMETHODIMP GetIDsOfNames   ( in REFIID iid, in OLECHAR** names, in UINT count, in LCID lcid, out DISPID* dispids );
  STDMETHODIMP Invoke          ( in DISPID dispid, in REFIID iid, in LCID lcid, in WORD flags, in DISPPARAMS* args, out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg );

  //IDeclarations
  STDMETHODIMP GetCount      ( out long* count );
  STDMETHODIMP GetName       ( in long index, out BSTR* name );
  STDMETHODIMP GetDescription( in long index, out BSTR* description );    
  STDMETHODIMP GetGlyph      ( in long index, out long* glyph );
  STDMETHODIMP GetBestMatch  ( in BSTR text, out long* index, out VARIANT_BOOL* uniqueMatch );
};

#endif
