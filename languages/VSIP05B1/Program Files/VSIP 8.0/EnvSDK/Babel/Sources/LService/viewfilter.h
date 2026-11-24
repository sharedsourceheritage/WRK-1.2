/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef viewfilter_h
#define viewfilter_h

class LanguageService;
class Preferences;
class Source;
class CTextTipData;

/*---------------------------------------------------------
  ViewFilter
---------------------------------------------------------*/
class ViewFilter :     
    public IVsTextViewFilter,
    public IOleCommandTarget
{
private:
  ULONG               m_refCount;
  LanguageService*    m_lservice;
  Preferences*        m_preferences;
  
  IVsTextView*        m_textView;             //the view we filter
  Source*             m_source;               //the associated buffer
  IVsTextLines*       m_textLines;
  IOleCommandTarget*  m_nextCommandTarget;    

  //callback: quick info
  long                m_quickInfoLine;
  long                m_quickInfoIdx;
  BSTR                m_quickInfoText;

  CTextTipData*       m_pTextTipData;

public:
  ViewFilter( in LanguageService* lservice, in Preferences* preferences, in IVsTextView* textView );
  ~ViewFilter();

  STDMETHODIMP Init();
  STDMETHODIMP Done();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  // IVsTextViewFilter methods: 
  STDMETHODIMP GetWordExtent( in long line, in CharIndex index, in DWORD flags, out TextSpan* span);
  STDMETHODIMP GetDataTipText( out TextSpan* span, out BSTR* text );
  STDMETHODIMP GetPairExtents( in long line, in CharIndex index, out TextSpan* span);
  
  // IOleCommandTarget methods:
  STDMETHODIMP QueryStatus(in const GUID* commandGroup, in ULONG count, out OLECMD commands[], out OLECMDTEXT* commandText );
  STDMETHODIMP Exec(in const GUID *commandGroup, in DWORD command, in DWORD options, in VARIANT* arg, out VARIANT* result);

protected:
  STDMETHODIMP HandleQuickInfo();
  CTextTipData* GetTextTipData();
  HRESULT GetFullDataTipText(
    in  BSTR        bstrCurrentText,
    in  TextSpan    ts,
    out BSTR*       pbstrFullText);

};

#endif
