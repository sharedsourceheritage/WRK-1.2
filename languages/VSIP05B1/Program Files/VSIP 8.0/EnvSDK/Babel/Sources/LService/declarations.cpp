/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include "vsmem.h"

#include "dllmain.h"        //g_typeInfoDeclarations
#include "declarations.h"

/*---------------------------------------------------------
  Declarations 
-----------------------------------------------------------*/
Declarations::Declarations()
{
  TRACE_CREATE( "Declarations", static_cast<IDeclarations*>(this) );

  m_refCount = 1;
  m_decls    = NULL; 
}


Declarations::~Declarations()
{
  DeclInfo* decl = m_decls;
  while (decl)
  {
    DeclInfo* next = decl->next;
    bstrFree( decl->name );
    bstrFree( decl->description );
    FREE(decl);
    decl = next;
  }
  
  TRACE_DESTROY( static_cast<IDeclarations*>(this) );
}



STDMETHODIMP Declarations::Insert( in BSTR name, in BSTR description, in long glyph, bool allowMultiple )
{
  DeclInfo* decl = ALLOC(DeclInfo);
  if (!decl) return E_OUTOFMEMORY;

  decl->name        = SysAllocString(name);
  decl->description = SysAllocString(description);
  decl->glyph       = glyph;
  
  DeclInfo* prev    = NULL;
  DeclInfo* current = m_decls;
  while( current && strICompare( current->name, name ) < 0) 
  {
    prev    = current;
    current = current->next;
  }

  if (!allowMultiple && current && strCompare(current->name, name) == 0)
    return S_OK;
  
  decl->next = current;
  if (prev) prev->next = decl;
       else m_decls    = decl;
  
  return S_OK;
}



/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Declarations::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("Declarations::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else if (iid == IID_IDispatch)
  {
    TRACE("Declarations::QueryInterface for IDispatch");
    *obj = static_cast<IDispatch*>(this);
  }
  else if (iid == IID_IDeclarations)
  {
    TRACE("Declarations::QueryInterface for IDeclarations");
    *obj = static_cast<IDeclarations*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Declarations::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Declarations::Release()
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
  implement IDispatch (for IDeclarations only)
-----------------------------------------------------------*/
STDMETHODIMP Declarations::GetTypeInfoCount( out UINT* count )
{
  OUTARG(count);
  if (g_typeInfoDeclarations) *count = 1;
                         else *count = 0;
  return S_OK;
}

STDMETHODIMP Declarations::GetTypeInfo( in UINT index, in LCID lcid, out ITypeInfo** typeInfo )
{
  OUTARG(typeInfo);
  if (index != 0) return E_INVALIDARG;
  if (!g_typeInfoDeclarations) return TYPE_E_CANTLOADLIBRARY;

  *typeInfo = g_typeInfoDeclarations;
  return S_OK;
}

STDMETHODIMP Declarations::GetIDsOfNames( in REFIID iid, in OLECHAR** names, in UINT count, 
                                       in LCID lcid, out DISPID* dispids )
{
  if (!g_typeInfoDeclarations) return TYPE_E_CANTLOADLIBRARY;
  return g_typeInfoDeclarations->GetIDsOfNames( names, count, dispids );
}

STDMETHODIMP Declarations::Invoke( in DISPID dispid, in REFIID iid, in LCID lcid, 
                                in WORD flags, in DISPPARAMS* args, 
                                out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg )
{
  if (!g_typeInfoDeclarations) return TYPE_E_CANTLOADLIBRARY;  
  return g_typeInfoDeclarations->Invoke( static_cast<IDeclarations*>(this), 
                                      dispid, flags, args, result, error, errorArg );
}
  

/*---------------------------------------------------------
  IDeclarations
-----------------------------------------------------------*/
STDMETHODIMP Declarations::GetCount( out long* count )
{
  OUTARG(count);
  *count = 0;
  for (DeclInfo* decl = m_decls; decl; decl = decl->next ) *count += 1;
  return S_OK;
}

STDMETHODIMP Declarations::GetDecl( in long index, out DeclInfo** decl )
{
  OUTARG(decl);
  *decl = m_decls;
  while (index > 0)
  {
    if (*decl == NULL) return E_INVALIDARG;
    *decl = (*decl)->next;
    index--;
  }

  if (*decl == NULL) return E_INVALIDARG;
  return S_OK;
}

STDMETHODIMP Declarations::GetName( in long index, out BSTR* name )
{
  OUTARG(name);
  HRESULT   hr;  
  DeclInfo* decl;
  hr = GetDecl( index, &decl );
  if (FAILED(hr)) return hr;
  *name = decl->name;

  return S_OK;
}
STDMETHODIMP Declarations::GetDescription( in long index, out BSTR* description )
{
  OUTARG(description);
  HRESULT   hr;  
  DeclInfo* decl;
  hr = GetDecl( index, &decl );
  if (FAILED(hr)) return hr;
  *description = decl->description;

  return S_OK;

}

STDMETHODIMP Declarations::GetGlyph( in long index, out long* glyph )
{ 
  OUTARG(glyph);
  HRESULT   hr;  
  DeclInfo* decl;
  hr = GetDecl( index, &decl );
  if (FAILED(hr)) return hr;
  *glyph = decl->glyph;

  return S_OK;
}

STDMETHODIMP Declarations::GetBestMatch( in BSTR text, out long* index, out VARIANT_BOOL* uniqueMatch )
{
  OUTARG(index);
  OUTARG(uniqueMatch);
  if (SysStringLen(text)==0) { *index = 0; return S_FALSE; }

  int len = SysStringLen(text);
  DeclInfo* decl;
  for (*index = 0, decl = m_decls; decl; *index += 1, decl = decl->next)
  {
    if (strICompareLen( decl->name, text, len ) == 0)
    {
      if (decl->next == NULL) 
        *uniqueMatch = TRUE;
      else 
        *uniqueMatch = (strICompareLen( decl->next->name, text, len) != 0);
      return S_OK;
    }
  }

  *index = 0;
  return S_FALSE;
}
