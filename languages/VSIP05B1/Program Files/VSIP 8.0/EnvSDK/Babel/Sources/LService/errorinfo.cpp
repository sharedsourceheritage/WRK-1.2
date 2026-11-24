/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"


#include "errorinfo.h"
#include "tasktokens.h"
#include "taskitem.h"

/*---------------------------------------------------------
  ErrorInfo 
-----------------------------------------------------------*/
ErrorInfo::ErrorInfo( in const wchar_t* message, in TextSpan& span, in Severity severity )
{
  TRACE_CREATE_HIDE( "ErrorInfo", static_cast<ErrorInfo*>(this) );
  //TRACE1( "ErrorInfo::ErrorInfo: %S", message );

  m_refCount  = 1;

  m_message   = SysAllocString(message);
  m_span      = span;
  m_severity  = severity;
}


ErrorInfo::~ErrorInfo()
{
  TRACE_DESTROY( static_cast<ErrorInfo*>(this) );
  bstrFree(m_message);
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP ErrorInfo::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    //TRACE("ErrorInfo::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) ErrorInfo::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) ErrorInfo::Release()
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
  ErrorInfo
-----------------------------------------------------------*/
STDMETHODIMP ErrorInfo::CreateTask( in  IServiceProvider* provider,
                                    in  TaskTokens*       taskTokens,
                                    in  const wchar_t*    fileName,
                                    in  IVsTextLines*     textLines,
                                    out IVsTaskItem**     taskItem )
{
  OUTARG(taskItem);
  HRESULT hr;

  //normalize text span
  TextSpanNormalize( &m_span, textLines );

  //remove control characters
  for (wchar_t* p = m_message; *p != L'\0'; p++)
  {
    if (*p < L' ') *p = L' ';
  }

  //set options
  VSTASKPRIORITY priority     = TP_NORMAL;
  VSTASKBITMAP   bitmap       = BMP_SQUIGGLE; 
  VSTASKCATEGORY category     = CAT_CODESENSE;

#if (defined(VS6) && defined(VS7SDK))
  MARKERTYPE     markerType   = (MARKERTYPE)(11);
#else
  MARKERTYPE     markerType   = MARKER_CODESENSE_ERROR;
#endif

  if (m_severity == SevFatal)
  {
    priority   = TP_HIGH;    
  }
  else if (m_severity == SevHint)
  {
    if (taskTokens)
    {
      hr = taskTokens->IsTaskToken( m_message, &priority );
      if (hr != S_OK) return hr;
    }
    bitmap     = BMP_COMMENT; 
    category   = CAT_COMMENTS;    
    markerType = MARKER_INVISIBLE;
  }

  //create task
  hr = ::CreateTask( provider, textLines, markerType,
                     m_message, fileName, true, m_span,
                     priority, bitmap, category, 
                     taskItem );
  if (FAILED(hr)) return hr;

  return S_OK;
}
