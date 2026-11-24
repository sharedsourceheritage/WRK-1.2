/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "taskcomments.h"

/*---------------------------------------------------------
  TaskComments 
-----------------------------------------------------------*/
TaskComments::TaskComments()
{
  TRACE_CREATE( "TaskComments", static_cast<IUnknown*>(this) );
  
  m_refCount  = 1;
  m_comments  = NULL;
  m_count     = 0;
}


TaskComments::~TaskComments()
{
  TRACE_DESTROY( static_cast<IUnknown*>(this) );
  FREE(m_comments);
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP TaskComments::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("TaskComments::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) TaskComments::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) TaskComments::Release()
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
  TaskComments
-----------------------------------------------------------*/
STDMETHODIMP TaskComments::Refresh( in IVsTaskList* taskList )
{
  REFARG(taskList);
  HRESULT hr;

  IVsCommentTaskInfo* commentTaskInfo = NULL;
  hr = taskList->QueryInterface( IID_IVsCommentTaskInfo, reinterpret_cast<void**>(&commentTaskInfo) );
  if (FAILED(hr)) return hr;

  ULONG count;
  hr = commentTaskInfo->GetCount( &count );
  if (FAILED(hr)) { RELEASE(commentTaskInfo); return hr; }

  IVsEnumCommentTaskTokens* commentTaskTokens = NULL;
  hr = commentTaskInfo->EnumTokens( &commentTaskTokens );
  RELEASE(commentTaskInfo);
  if (FAILED(hr)) return hr;

  TaskComment
  hr = 

}

