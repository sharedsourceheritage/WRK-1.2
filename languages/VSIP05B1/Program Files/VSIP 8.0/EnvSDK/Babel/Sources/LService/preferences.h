/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef preferences_h
#define preferences_h

/*---------------------------------------------------------
  Preferences
-----------------------------------------------------------*/
class Preferences : public IVsTextManagerEvents
{
private:
  ULONG             m_refCount;
 
  IVsTextManager*   m_textManager;
  DWORD             m_textManagerConnect;
  
  LANGPREFERENCES   m_languagePref;
  VIEWPREFERENCES   m_viewPref;
  bool              m_enableCodeSense;
  bool              m_enableCodeSenseFastOnLineChange;
  bool              m_enableMatchBraces;
  bool              m_enableQuickInfo;
  bool              m_enableShowMatchingBrace;
  bool              m_enableMatchBracesAtCaret;
  unsigned          m_maxErrorMessages;
  unsigned          m_codeSenseDelay;
  unsigned          m_threadModel;
  bool              m_binary;

public:
  Preferences();
  ~Preferences();

  STDMETHODIMP Init( in HKEY key );
  STDMETHODIMP Connect( in IServiceProvider* provider );
  STDMETHODIMP Done();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //Preferences
  STDMETHODIMP_(unsigned) GetThreadModel()        { return m_threadModel;       }
  STDMETHODIMP_(unsigned) GetMaxErrorMessages()   { return m_maxErrorMessages;  }
  STDMETHODIMP_(unsigned) GetCodeSenseDelay()     { return m_codeSenseDelay;    }
  STDMETHODIMP_(unsigned) GetTabSize();
  
  STDMETHODIMP_(bool)     EnableCodeSense()           { return m_enableCodeSense;   }
  STDMETHODIMP_(bool)     EnableCodeSenseFastOnLineChange() { return m_enableCodeSenseFastOnLineChange; }
  STDMETHODIMP_(bool)     EnableQuickInfo()           { return m_enableQuickInfo;   }
  STDMETHODIMP_(bool)     EnableMatchBraces()         { return m_enableMatchBraces; }
  STDMETHODIMP_(bool)     EnableShowMatchingBrace()   { return m_enableShowMatchingBrace; }
  STDMETHODIMP_(bool)     EnableMatchBracesAtCaret()  { return m_enableMatchBracesAtCaret; }
  STDMETHODIMP_(bool)     EnableMemberSelect();
  STDMETHODIMP_(bool)     EnableMethodTip();
  STDMETHODIMP_(bool)     IsBinary()                  { return m_binary; }


  //IVsTextManagerEvents
  STDMETHODIMP_(void) OnRegisterMarkerType( in long markerType)   {}
  STDMETHODIMP_(void) OnRegisterView( in IVsTextView* textView)   {}
  STDMETHODIMP_(void) OnUnregisterView( in IVsTextView* textView) {}
  STDMETHODIMP_(void) OnUserPreferencesChanged(in const VIEWPREFERENCES*      viewPrefs, 
                                               in const FRAMEPREFERENCES*     framePrefs, 
                                               in const LANGPREFERENCES*      langPrefs, 
                                               in const FONTCOLORPREFERENCES* colorPrefs);

};

#endif
