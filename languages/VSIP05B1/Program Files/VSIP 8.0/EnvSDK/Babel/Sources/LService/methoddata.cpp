/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "methoddata.h"
#include "strsafe.h"

/*---------------------------------------------------------
  MethodData 
-----------------------------------------------------------*/
MethodData::MethodData()
{
  TRACE_CREATE( "MethodData", static_cast<IVsMethodData*>(this) );
  m_refCount      = 1;
  m_methodTip     = NULL;

  m_textView      = NULL;
  m_methods       = NULL;
  m_displayed     = false;
  m_currentMethod    = 0;
  m_currentParameter = 0;

  m_parStart      = NULL;
  m_parSep        = NULL;
  m_parEnd        = NULL;
  m_typeStart     = NULL;
  m_typeEnd       = NULL;
  m_typePrefixed  = true;
}


MethodData::~MethodData()
{
  TRACE_DESTROY( static_cast<IVsMethodData*>(this) );
  Done();
}


STDMETHODIMP MethodData::Init( in IServiceProvider* provider, in IBabelService* babelService )
{
  TRACE("MethodData::Init");
  REFARG(provider);
  REFARG(babelService);
  HRESULT hr;

  if (!m_methodTip)
  {
    hr = ProviderCreateInstance( provider, CLSID_VsMethodTipWindow,IID_IVsMethodTipWindow, 
                                 reinterpret_cast<void**>(&m_methodTip) );
    if (FAILED(hr)) return hr;
  
    hr = m_methodTip->SetMethodData( this );
    if (FAILED(hr)) { RELEASE(m_methodTip); return hr; }
  }

  VARIANT_BOOL typePrefixed;
  hr = babelService->GetMethodFormat( &m_parStart, &m_parSep, &m_parEnd,
                                      &m_typeStart, &m_typeEnd, &typePrefixed );
  if (SUCCEEDED(hr)) 
  {
    m_typePrefixed = (typePrefixed != 0);
  }

  return S_OK;
}


STDMETHODIMP MethodData::Done()
{
  TRACE("MethodData::Done");
  Dismiss();
  RELEASE(m_methodTip);
  bstrFree(m_parStart);
  bstrFree(m_parSep);
  bstrFree(m_parEnd);
  bstrFree(m_typeStart);
  bstrFree(m_typeEnd);  
  return S_OK;
}

STDMETHODIMP_(bool) MethodData::IsDisplayed()
{
  return m_displayed;
}

STDMETHODIMP MethodData::Refresh( in IVsTextView* textView, 
                                  in IMethods*    methods,
                                  in long         currentParameter)
{
  TRACE("MethodData::Refresh");
  REFARG(textView);
  REFARG(methods);
 
  Dismiss();  
  m_textView = textView; ADDREF(m_textView);
  m_methods  = methods;  ADDREF(m_methods);
  m_currentMethod    = 0;
  m_currentParameter = currentParameter;
  AdjustCurrentParameter( 0 );
  return S_OK;
}

STDMETHODIMP MethodData::AdjustCurrentParameter( in long increment )
{
  TRACE("MethodData::AdjustCurrentParameter" );

  m_currentParameter += increment;
  if (m_currentParameter < 0) 
    m_currentParameter = -1;
  else if (m_currentParameter >= GetParameterCount( m_currentMethod )) 
    m_currentParameter = GetParameterCount(m_currentMethod);
  
  UpdateView();
  return S_OK;
}

STDMETHODIMP MethodData::Dismiss()
{
  TRACE("MethodData::Dismiss");

  if (m_displayed && m_textView)
  {
    m_textView->UpdateTipWindow( m_methodTip, UTW_DISMISS );
    ASSERT(!m_displayed);
    m_displayed = false;
  }

  OnDismiss();
  return S_OK;
}

STDMETHODIMP_(void) MethodData::OnDismiss()
{
  TRACE("MethodData::OnDismiss");
  RELEASE(m_textView);
  RELEASE(m_methods);
  m_currentMethod    = 0;
  m_currentParameter = 0;
  m_displayed        = false;
}


STDMETHODIMP_(void) MethodData::UpdateView()
{
  TRACE("MethodData::UpdateView");
  if (!m_textView) return;

  m_textView->UpdateTipWindow( m_methodTip, UTW_CONTENTCHANGED | UTW_CONTEXTCHANGED );
  m_displayed = true;
}
  

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP MethodData::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsMethodData)
  {
    TRACE("MethodData::QueryInterface for IUnknown/IVsMethodData");
    *obj = static_cast<IVsMethodData*>(this);
  } 
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) MethodData::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) MethodData::Release()
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
  IVsMethodData
-----------------------------------------------------------*/

STDMETHODIMP_(long) MethodData::GetOverloadCount()
{
  if (!m_textView || !m_methods) return 0;

  long count = 0;
  if (SUCCEEDED(m_methods->GetCount(&count)))
    return count;
  else
    return 0;
}

STDMETHODIMP_(long) MethodData::GetCurMethod()
{
  return m_currentMethod;
}

STDMETHODIMP_(long) MethodData::NextMethod()
{
  if (m_currentMethod < GetOverloadCount()-1)  m_currentMethod++;

  return m_currentMethod;
}

STDMETHODIMP_(long) MethodData::PrevMethod()  
{
  if (m_currentMethod > 0) m_currentMethod--;

  return m_currentMethod;
}

STDMETHODIMP_(long) MethodData::GetParameterCount( in long method )
{
  if (!m_methods) return 0;
  if (method < 0 || method >= GetOverloadCount()) return 0;

  long count = 0;
  if (SUCCEEDED(m_methods->GetParameterCount( method, &count )))
    return count;
  else
    return 0;
}
  
STDMETHODIMP_(long) MethodData::GetCurrentParameter( in long method )  
{
  return m_currentParameter;
}


STDMETHODIMP MethodData::GetContextStream( in long* pos, in long* length )
{
  OUTARG(pos);
  OUTARG(length);
  if (!m_textView) return E_UNEXPECTED;
  HRESULT hr;

  long line;
  long idx;
  hr = m_textView->GetCaretPos( &line, &idx );
  if (FAILED(hr)) return hr;

  long vspace;
  hr = m_textView->GetNearestPosition( line, idx, pos, &vspace );
  if (FAILED(hr)) return hr;

  *length = 0;
  return S_OK;
}

STDMETHODIMP_(const WCHAR*) MethodData::GetMethodText( in long method, 
                                                       in MethodTextType type )
{    
  HRESULT hr;
  if (!m_methods) return NULL;
  if (method < 0 || method >= GetOverloadCount()) return NULL;

  //a type
  if ((type == MTT_TYPEPREFIX && m_typePrefixed) ||
      (type == MTT_TYPEPOSTFIX && !m_typePrefixed))
  {
    BSTR bstrType;
    hr = m_methods->GetType( method, &bstrType );
    if (FAILED(hr))                 return NULL;
    if (!m_typeStart && !m_typeEnd) return bstrType;
    
    //this is potentially unsafe (but the alternative is maintaining a list of bstr's :-(
    StringCchCopy( m_text, MAX_PATH, m_typeStart );
    StringCchCat ( m_text, MAX_PATH, bstrType    );
    StringCchCat ( m_text, MAX_PATH, m_typeEnd   );
    return m_text;
  }

  //other
  switch (type) 
  {
#ifndef VS6SDK
  case MTT_OPENBRACKET:
    return m_parStart;

  case MTT_CLOSEBRACKET:
    return m_parEnd;

//TODO: change to MTT_DELIMITER
  case (MTT_CLOSEBRACKET+1):
    return m_parSep;
#endif

  case MTT_NAME:
    {
      BSTR name = NULL;
      hr = m_methods->GetName( &name );
      if (FAILED(hr)) return NULL;
      return name;
    }

  case MTT_DESCRIPTION:
    /*
    {
      BSTR description = NULL;
      hr = m_methods->GetDescription( method, &description );
      if (FAILED(hr)) return NULL;
      return description;
    }
    */

  case MTT_TYPEPREFIX:
  case MTT_TYPEPOSTFIX:
  default:
      return NULL;
  }
}

STDMETHODIMP_(const WCHAR*) MethodData::GetParameterText( 
                                              in long method, 
                                              in long parameter, 
                                              in ParameterTextType type )
{
  HRESULT hr;
  if (!m_methods) return NULL;
  if (method < 0 || method >= GetOverloadCount()) return NULL;
  if (parameter < 0 || parameter >= GetParameterCount( method )) return NULL;

  BSTR name;
  BSTR description;
  BSTR display;
  hr = m_methods->GetParameterInfo( method, parameter, &name, &display, &description );
  if (FAILED(hr)) return NULL;

  switch (type)
  {
  case PTT_NAME:        return name;
  case PTT_DESCRIPTION: return NULL; //description;
  case PTT_DECLARATION: return display;
  default:              return NULL;
  }
}
