/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef methoddata_h
#define methoddata_h

/*---------------------------------------------------------
 MethodData.
---------------------------------------------------------*/
class MethodData : public IVsMethodData
{
private:
  ULONG               m_refCount;
  IVsMethodTipWindow* m_methodTip;

  bool                m_displayed;
  IVsTextView*        m_textView;
  IMethods*           m_methods;
  long                m_currentMethod;
  long                m_currentParameter;

  BSTR    m_parStart;
  BSTR    m_parSep;
  BSTR    m_parEnd;
  BSTR    m_typeStart;
  BSTR    m_typeEnd;
  bool    m_typePrefixed;
  
  wchar_t m_text[MAX_PATH+1];
  
public:
  MethodData();
  ~MethodData();

  STDMETHODIMP Init( in IServiceProvider* provider, in IBabelService* babelService );
  STDMETHODIMP Done();

  STDMETHODIMP_(bool) IsDisplayed();
  STDMETHODIMP Refresh( in IVsTextView* textView, in IMethods* methods, in long currentParameter );
  STDMETHODIMP AdjustCurrentParameter( in long increment );
  STDMETHODIMP Dismiss();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IVsMethodData
  STDMETHODIMP_(long) GetOverloadCount();
  STDMETHODIMP_(long) GetCurMethod();
  STDMETHODIMP_(long) NextMethod();
  STDMETHODIMP_(long) PrevMethod();  
  STDMETHODIMP_(long) GetParameterCount( in long method );
  STDMETHODIMP_(long) GetCurrentParameter(in long method );  
  STDMETHODIMP_(void) OnDismiss();
  STDMETHODIMP_(void) UpdateView();
  STDMETHODIMP        GetContextStream( in long* pos, in long* length );
  STDMETHODIMP_(const WCHAR*) GetMethodText( in long method, in MethodTextType type );
  STDMETHODIMP_(const WCHAR*) GetParameterText( in long method, 
                                                in long parameter, 
								                in ParameterTextType type );
};


#endif
