/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "lservice.h"
#include "preferences.h"
#include "source.h"
#include "codewinmgr.h"
#include "viewfilter.h"

/*---------------------------------------------------------
  CodeWindowManager
-----------------------------------------------------------*/
CodeWindowManager::CodeWindowManager( in LanguageService* lservice, 
                                      in Preferences*     preferences,
                                      in IVsCodeWindow*   codeWindow )
: m_viewFilters()
{
  TRACE_CREATE( "CodeWindowManager", static_cast<IVsCodeWindowManager*>(this) );
  ASSERT(lservice);
  ASSERT(codeWindow);
  ASSERT(preferences);

  m_refCount      = 1;
  m_codeWindow    = codeWindow;   ADDREF(m_codeWindow);
  m_lservice      = lservice;     ADDREF(m_lservice);
  m_preferences   = preferences;  ADDREF(m_preferences);
}


CodeWindowManager::~CodeWindowManager()
{
  TRACE_DESTROY( static_cast<IVsCodeWindowManager*>(this) );

  RemoveAdornments();
  
  //close the associated source
  HRESULT hr;
  IVsTextLines* textLines;
  hr = m_codeWindow->GetBuffer( &textLines );
  if (SUCCEEDED(hr))
  {
    Source* source;
    hr = m_lservice->GetSource( textLines, &source );
    RELEASE(textLines);
    if (SUCCEEDED(hr))
    {
      if (hr == S_OK) m_lservice->CloseSource( source ); //calls eventually [Source::Done]
      RELEASE(source);
    }
  }

  RELEASE(m_preferences);
  RELEASE(m_codeWindow);
  RELEASE(m_lservice);
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP CodeWindowManager::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsCodeWindowManager)
  {
    TRACE("CodeWindowManager::QueryInterface for IUnknown/IVsCodeWindowManager");
    *obj = static_cast<IVsCodeWindowManager*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) CodeWindowManager::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CodeWindowManager::Release()
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
  IVsCodeWindowManager
-----------------------------------------------------------*/
STDMETHODIMP CodeWindowManager::AddAdornments()
{
  TRACE("CodeWindowManager::AddAdornments");
  HRESULT hr;
  
  IVsTextView* textView;
  hr = m_codeWindow->GetPrimaryView( &textView );
  if (FAILED(hr)) return hr;

  hr = OnNewView( textView );
  RELEASE(textView);
  if (FAILED(hr)) return hr;

  hr = m_codeWindow->GetSecondaryView( &textView );
  if (FAILED(hr)) return hr;

  hr = OnNewView( textView );
  RELEASE(textView);
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP CodeWindowManager::RemoveAdornments()
{
  TRACE("CodeWindowManager::RemoveAdornments");
  ViewFilter* viewFilter;
  ObjectElem* elem;

  for (m_viewFilters.GetFirst( &elem, (IUnknown**)(&viewFilter)); viewFilter; m_viewFilters.GetNext( &elem, (IUnknown**)(&viewFilter)) )
  {
    viewFilter->Done();
  }

  m_viewFilters.Clear();
  return S_OK;
}

STDMETHODIMP CodeWindowManager::OnNewView( in IVsTextView* textView )
{
  TRACE("CodeWindowManager::OnNewView");
  HRESULT hr;

  ViewFilter* viewFilter = new ViewFilter( m_lservice, m_preferences, textView );
  if (!viewFilter) return E_OUTOFMEMORY;

  hr = viewFilter->Init();
  if (FAILED(hr)) { viewFilter->Done(); RELEASE(viewFilter); return hr; }

  hr = m_viewFilters.Insert( static_cast<IVsTextViewFilter*>(viewFilter) );
  RELEASE(viewFilter);
  if (FAILED(hr)) return hr;

  return S_OK;
}
