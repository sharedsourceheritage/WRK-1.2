/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "preferences.h"

/*---------------------------------------------------------
  Preferences 
-----------------------------------------------------------*/
Preferences::Preferences()
{
  TRACE_CREATE( "Preferences", static_cast<IUnknown*>(this) );
  m_refCount            = 1;
  
  m_textManager         = NULL;
  m_textManagerConnect  = 0;

  memset( &m_languagePref, 0, sizeof(m_languagePref));
  memset( &m_viewPref,     0, sizeof(m_viewPref));

  m_enableCodeSense     = true;
  m_enableMatchBraces   = true;
  m_enableQuickInfo     = true;
  m_enableShowMatchingBrace  = false;
  m_enableMatchBracesAtCaret = true;
  m_enableCodeSenseFastOnLineChange = true;
  m_maxErrorMessages    = 5;
  m_codeSenseDelay      = 1000;  
  m_threadModel         = 1;
  m_binary              = false;
}


Preferences::~Preferences()
{
  TRACE_DESTROY( static_cast<IUnknown*>(this) );
  Done();
}


STDMETHODIMP Preferences::Init( in HKEY key )
{
  TRACE("Preferences::Init");
  HRESULT hr;

  //get preferences from registry
  DWORD enabled = 0;
  
  DWORD valueLen = sizeof(enabled);
  hr = hrRegQueryValueEx( key, L"CodeSense", 0, NULL, (BYTE*)&enabled, &valueLen );
  if (SUCCEEDED(hr)) 
      m_enableCodeSense = (enabled != 0);

  valueLen = sizeof(enabled);
  hr = hrRegQueryValueEx( key, L"CodeSenseFastOnLineChange", 0, NULL, (BYTE*)&enabled, &valueLen );
  if (SUCCEEDED(hr)) 
      m_enableCodeSenseFastOnLineChange = (enabled != 0);

  valueLen = sizeof(enabled);
  hr = hrRegQueryValueEx( key, L"MatchBraces", 0, NULL, (BYTE*)&enabled, &valueLen );
  if (SUCCEEDED(hr)) 
      m_enableMatchBraces = (enabled != 0);
 
  valueLen = sizeof(enabled);
  hr = hrRegQueryValueEx( key, L"QuickInfo", 0, NULL, (BYTE*)&enabled, &valueLen );
  if (SUCCEEDED(hr)) 
      m_enableQuickInfo = (enabled != 0);
 
  valueLen = sizeof(enabled);
  hr = hrRegQueryValueEx( key, L"ShowMatchingBrace", 0, NULL, (BYTE*)&enabled, &valueLen );
  if (SUCCEEDED(hr)) 
      m_enableShowMatchingBrace = (enabled != 0);

  valueLen = sizeof(enabled);
  hr = hrRegQueryValueEx( key, L"MatchBracesAtCaret", 0, NULL, (BYTE*)&enabled, &valueLen );
  if (SUCCEEDED(hr)) 
      m_enableMatchBracesAtCaret = (enabled != 0);

  DWORD count = 0;
  valueLen = sizeof(count);
  hr = hrRegQueryValueEx( key, L"MaxErrorMessages", 0, NULL, (BYTE*)&count, &valueLen );
  if (SUCCEEDED(hr)) 
      m_maxErrorMessages = count;
 
  count = 0;
  valueLen = sizeof(count);
  hr = hrRegQueryValueEx( key, L"CodeSenseDelay", 0, NULL, (BYTE*)&count, &valueLen );
  if (SUCCEEDED(hr)) 
      m_codeSenseDelay = count;
 
  DWORD model = 0;
  valueLen = sizeof(model);
  hr = hrRegQueryValueEx( key, L"ThreadModel", 0, NULL, (BYTE*)&model, &valueLen );
  if (SUCCEEDED(hr)) 
      m_threadModel = model;
 
  enabled = 0;
  valueLen = sizeof(enabled);
  hr = hrRegQueryValueEx( key, L"Binary", 0, NULL, (BYTE*)&enabled, &valueLen );
  if (SUCCEEDED(hr)) 
      m_binary = (enabled != 0);
 
  return S_OK;
}

STDMETHODIMP Preferences::Connect( in IServiceProvider* provider )
{
  REFARG(provider);
  HRESULT hr;

  if (!m_textManager)
  {
    TRACE("Preferences::Connect:Init");
  
    hr = provider->QueryService(SID_SVsTextManager, IID_IVsTextManager, reinterpret_cast<void**>(&m_textManager) );
    if (FAILED(hr)) return hr;
  
    //get user preferences from textmanager
    hr = m_textManager->GetUserPreferences (&m_viewPref, NULL, &m_languagePref, NULL);
    //if (FAILED(hr)) return hr;
  }
  
  //connect to text manager events to catch preference changes
  if (!m_textManagerConnect)
  {
    TRACE("Preferences::Connect");
  
    hr = ::Connect( m_textManager, static_cast<IVsTextManagerEvents*>(this), 
                    IID_IVsTextManagerEvents, &m_textManagerConnect );
    if (FAILED(hr)) return hr;
  }

  return S_OK;
}


STDMETHODIMP Preferences::Done()
{
  TRACE("Preferences::Done");
  if (m_textManagerConnect)
    DisConnect( m_textManager, IID_IVsTextManagerEvents, &m_textManagerConnect );

  RELEASE(m_textManager);
  return S_OK;
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Preferences::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("Preferences::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else if (iid == IID_IVsTextManagerEvents)
  {
    TRACE("Preferences::QueryInterface for IVsTextManagerEvents");
    *obj = static_cast<IVsTextManagerEvents*>(this);
  }  
  else 
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Preferences::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Preferences::Release()
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
  IVsTextManagerEvents
-----------------------------------------------------------*/
void Preferences::OnUserPreferencesChanged( in const VIEWPREFERENCES*      viewPrefs, 
                                            in const FRAMEPREFERENCES*     framePrefs, 
                                            in const LANGPREFERENCES*      langPrefs, 
                                            in const FONTCOLORPREFERENCES* colorPrefs)
{
  TRACE("Preferences::OnUserPreferencesChanged");
  if (langPrefs) m_languagePref = *langPrefs;
  if (viewPrefs) m_viewPref     = *viewPrefs;
}

/*---------------------------------------------------------
  Preferences
-----------------------------------------------------------*/
STDMETHODIMP_(unsigned) Preferences::GetTabSize()
{
  if (m_languagePref.uTabSize == 0)
    return 8;
  else
    return m_languagePref.uTabSize;
}

STDMETHODIMP_(bool) Preferences::EnableMemberSelect()
{
  return (m_languagePref.fAutoListMembers != 0);
}

STDMETHODIMP_(bool) Preferences::EnableMethodTip()
{
  return (m_languagePref.fAutoListParams != 0);
}


