/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef errorinfo_h
#define errorinfo_h

class TaskTokens;

/*---------------------------------------------------------
  ErrorInfo
-----------------------------------------------------------*/
class ErrorInfo : public IUnknown
{
private:
  ULONG             m_refCount;
  BSTR              m_message;
  TextSpan          m_span;
  Severity          m_severity;

public:
  ErrorInfo( in const wchar_t* message, in TextSpan& span, in Severity severity );
  ~ErrorInfo();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //ErrorInfo
  STDMETHODIMP CreateTask( in  IServiceProvider* provider,
                           in  TaskTokens*       taskTokens,
                           in  const wchar_t*    fileName,
                           in  IVsTextLines*     textLines,
                           out IVsTaskItem**     taskItem );
};

#endif
