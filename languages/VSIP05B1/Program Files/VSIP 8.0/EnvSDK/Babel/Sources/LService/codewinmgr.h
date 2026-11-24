/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef codewinmgr_h
#define codewinmgr_h

class LanguageService;
class Preferences;

/*---------------------------------------------------------
  CodeWindowManager
---------------------------------------------------------*/
class CodeWindowManager : public IVsCodeWindowManager
{
private:
  ULONG             m_refCount;
  IVsCodeWindow*    m_codeWindow;
  LanguageService*  m_lservice;
  Preferences*      m_preferences;
  ObjectList        m_viewFilters;

public:
  CodeWindowManager( in LanguageService* lservice, in Preferences* preferences, 
                     in IVsCodeWindow* codeWindow );
  ~CodeWindowManager();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IVsCodeWindowManager
  STDMETHODIMP AddAdornments();
  STDMETHODIMP RemoveAdornments();
  STDMETHODIMP OnNewView( in IVsTextView* textView );
};

#endif
