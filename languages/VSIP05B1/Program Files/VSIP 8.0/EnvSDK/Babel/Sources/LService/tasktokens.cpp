/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include <strsafe.h>
#include "vsmem.h"

#include "tasktokens.h"

/*---------------------------------------------------------
  TaskTokens 
-----------------------------------------------------------*/
TaskTokens::TaskTokens( in IServiceProvider* provider )
{
  TRACE_CREATE( "TaskTokens", static_cast<IUnknown*>(this) );
  ASSERT(provider);

  m_refCount  = 1;
  m_provider  = provider; ADDREF(provider);
  m_tokens    = NULL;
  m_count     = 0;
}


TaskTokens::~TaskTokens()
{
  TRACE_DESTROY( static_cast<IUnknown*>(this) );
  Clear();
  RELEASE(m_provider);
}


STDMETHODIMP_(void) TaskTokens::Clear()
{
  for (unsigned index = 0; index < m_count; index++)
  {
    bstrFree(m_tokens[index].token);
  }
  FREE(m_tokens);
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP TaskTokens::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("TaskTokens::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) TaskTokens::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) TaskTokens::Release()
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
  TaskTokens
-----------------------------------------------------------*/
STDMETHODIMP TaskTokens::Refresh()
{
  TRACE("TaskTokens::Refresh");
  HRESULT hr;

  //Get token enumerator and allocate memory
  IVsCommentTaskInfo* commentTaskInfo = NULL;
  hr = m_provider->QueryService( SID_SVsTaskList, IID_IVsCommentTaskInfo, reinterpret_cast<void**>(&commentTaskInfo) );
  if (FAILED(hr)) return hr;

  long count;
  hr = commentTaskInfo->get_TokenCount( &count );
  if (FAILED(hr)) { RELEASE(commentTaskInfo); return hr; }

  IVsEnumCommentTaskTokens* commentTaskTokens = NULL;
  hr = commentTaskInfo->get_EnumTokens( &commentTaskTokens );
  RELEASE(commentTaskInfo);
  if (FAILED(hr)) return hr;

  TaskToken* tokens = NALLOC(TaskToken,count);
  if (tokens == NULL) { RELEASE(commentTaskTokens); return E_OUTOFMEMORY; }

  //Get all tokens
  long index;
  for (index = 0; index < count; index++)
  {
    ULONG                fetched;
    IVsCommentTaskToken* commentTaskToken;

    hr = commentTaskTokens->Next( 1, &commentTaskToken, &fetched );
    if (hr != S_OK) break;
    //ASSERT(fetched == 1);

    hr = commentTaskToken->get_Text( &tokens[index].token );
    if (FAILED(hr)) { RELEASE(commentTaskToken); break; }

    hr = commentTaskToken->get_Priority( &tokens[index].priority );
    RELEASE(commentTaskToken); 
    if (FAILED(hr)) { bstrFree(tokens[index].token); break; }
  }
  RELEASE(commentTaskTokens);
  if (FAILED(hr))
  {
    //free allocate strings
    index--;
    while (index > 0) { bstrFree(tokens[index].token); index--; }
    FREE(tokens);
    return hr;
  }
  ASSERT(index == count);   //all items processed?
  

  //update the token information
  Clear();
  m_count  = count;
  m_tokens = tokens;

  return S_OK;
}


STDMETHODIMP TaskTokens::IsTaskToken( in BSTR text, out VSTASKPRIORITY* priority )
{
  if (!priority) return E_INVALIDARG;
            else *priority = TP_NORMAL;
  if (!text) return S_FALSE;

  //extract the token
  const wchar_t* p = text;  
  while (iswspace(*p)) { p++; }   //skip spaces

  ULONG len = 0;
  while (!iswspace(p[len]) && p[len] != L':' && p[len] != 0) { len++; }
  if (len == 0) return S_FALSE;
  
  wchar_t token[MAX_PATH];
  if (len >= MAX_PATH) return S_FALSE;
  StringCchCopy( token, len, p );

  //check if this is a defined token
  for (unsigned index = 0; index < m_count; index++)
  {
    if (strCompare(token,m_tokens[index].token) == 0) 
    {
      *priority = m_tokens[index].priority;
      return S_OK;
    }
  }

  return S_FALSE;
}
