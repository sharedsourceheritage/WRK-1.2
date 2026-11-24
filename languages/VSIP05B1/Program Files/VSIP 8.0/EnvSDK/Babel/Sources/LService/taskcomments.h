/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef taskcomments_h
#define taskcomments_h

/*---------------------------------------------------------
  TaskComments
-----------------------------------------------------------*/
struct TaskComment
{
  BSTR            comment;
  VSTASKPRIORITY  priority;
};


class TaskComments : public IUnknown
{
private:
  ULONG          m_refCount;
  TaskComment**  m_comments;
  ULONG          m_count;

public:
  TaskComments();
  ~TaskComments();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //TaskComments
  STDMETHODIMP Refresh( in IVsTaskProvider* taskProvider );
  STDMETHODIMP IsTaskComment( in BSTR text, out VSTASKPRIORITY* priority );
};

#endif
