/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef tasktokens_h
#define tasktokens_h

/*---------------------------------------------------------
  TaskTokens
-----------------------------------------------------------*/
struct TaskToken
{
  BSTR            token;
  VSTASKPRIORITY  priority;
};


class TaskTokens : public IUnknown
{
private:
  ULONG             m_refCount;
  IServiceProvider* m_provider;

  TaskToken*        m_tokens;
  ULONG             m_count;

public:
  TaskTokens( in IServiceProvider* provider );
  ~TaskTokens();
  
  STDMETHODIMP_(void)  Clear();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //TaskTokens
  STDMETHODIMP Refresh();
  STDMETHODIMP IsTaskToken( in BSTR text, out VSTASKPRIORITY* priority );
};

#endif
