/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include <process.h>    //for _beginthread / _endthread
#include "dllmain.h"    //for g_typeInfoParseSink
#include "source.h"
#include "errorinfo.h"
#include "parser.h"
#include "scope.h"      
#include "preferences.h"
#include "linespan.h"   //for LineSpanList
#include "delayscope.h" 

#define CHECK(r)        ((r) == ReasonCheck)
#define SELECT(r)       ((r) >= ReasonMemberSelect && (r) <= ReasonMethodTip)
#define METHODTIP(r)    ((r) == ReasonMethodTip || (r) == ReasonQuickInfo)
#define MATCHBRACES(r)  ((r) == ReasonHighlightBraces || (r) == ReasonMatchBraces)
#define AUTOS(r)        ((r) == ReasonAutos)

 
/*---------------------------------------------------------
  CreateParser
-----------------------------------------------------------*/
void _cdecl ParserThread( void* parser )
{
  TRACE( "Start thread" );
  SetThreadPriority( GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL );

  ((Parser*)parser)->Main();

  TRACE("End thread" );
  _endthread();
}


HRESULT CreateParser( in  IServiceProvider* provider,
                      in  IBabelService* babelService, 
                      in  Preferences* preferences,
                      out Parser** parser )
{
  OUTARG(parser);
  REFARG(babelService);
  REFARG(preferences);
  

  *parser = new Parser( provider, babelService, 
                        preferences->GetMaxErrorMessages(),
                        preferences->GetThreadModel() );
  if (*parser == NULL) return E_OUTOFMEMORY;

  HRESULT hr = (*parser)->Init();
  if (FAILED(hr)) { (*parser)->Done(); delete *parser; *parser = NULL; return hr; }

  _beginthread( ParserThread, 0, *parser );

  return S_OK;
}


/*---------------------------------------------------------
  Parser 
-----------------------------------------------------------*/
Parser::Parser( in IServiceProvider* provider, in IBabelService* babelService, in unsigned errorMax, in unsigned threadModel )
: m_methodCalls()
{
  TRACE_CREATE( "Parser", static_cast<IParseSink*>(this) );
  ASSERT(babelService);

  m_refCount          = 1;
  m_eventDeleted      = NULL;
  m_errorMax          = errorMax;
  m_threadModel       = threadModel;
  m_babelService      = babelService; ADDREF(m_babelService);
  m_provider          = provider;     ADDREF(m_provider);

  m_request.eventSet  = NULL;
  m_request.eventEmpty= NULL;
  m_request.empty     = true;
  m_request.source    = NULL;
  m_request.text      = NULL;
  m_request.line      = 0;
  m_request.idx       = 0;
  m_request.textView  = NULL;
  m_request.fSync     = false;
  m_request.taskID    = 0;

  m_response.eventSet = NULL;
  m_response.eventEmpty= NULL;
  m_response.empty    = true;
  m_response.errors   = NULL;
  m_response.source   = NULL;
  m_response.scope    = NULL;
  TextSpanEmpty( &m_response.firstError );
  m_response.spans    = NULL;
  m_response.textView = NULL;
  m_response.fSync    = false;
  m_response.taskID   = 0;


  m_text              = NULL;
  m_source            = NULL;
  m_scope             = NULL;
  m_errors            = NULL;
  TextSpanEmpty( &m_firstError );

  m_found             = false;
  m_passed            = false;
  m_textView          = NULL;
  m_line              = 0;
  m_idx               = 0;
  m_spans             = NULL;
}


Parser::~Parser()
{
  TRACE_DESTROY( static_cast<IParseSink*>(this) );

  //Done();
  RELEASE(m_spans);
  RELEASE(m_textView);

  RELEASE(m_errors);
  RELEASE(m_source);
  RELEASE(m_scope);
  bstrFree(m_text);
  RELEASE(m_babelService);
  RELEASE(m_provider);
}


STDMETHODIMP Parser::Init()
{
  TRACE1("Parser::Init: at 0x%x", this );
  
  m_eventDeleted = CreateEvent( NULL, TRUE /*no auto reset*/, FALSE, NULL );
  if (m_eventDeleted == NULL) { return HRFromLastError(); }

  m_request.eventSet = CreateEvent( NULL, FALSE /*auto reset*/, FALSE /*non-signaled*/, NULL );
  if (m_request.eventSet == NULL) { return HRFromLastError(); }

  m_request.eventEmpty = CreateEvent( NULL, FALSE /*auto reset*/, TRUE /*signaled*/, NULL );
  if (m_request.eventEmpty == NULL) { return HRFromLastError(); }

  m_request.valid = true;

  m_response.eventSet = CreateEvent( NULL, FALSE /*auto reset*/, FALSE /*non-signaled*/, NULL );
  if (m_response.eventSet == NULL) { return HRFromLastError(); }

  m_response.eventEmpty = CreateEvent( NULL, FALSE /*auto reset*/, TRUE /*signaled*/, NULL );
  if (m_response.eventEmpty == NULL) { return HRFromLastError(); }

  m_response.valid = true;

  return S_OK;
}

STDMETHODIMP Parser::Done()
{
  TRACE1("Parser::Done: at 0x%x", this );
  if ( m_request.GetLock() )
  {
    RELEASE(m_request.source);
    bstrFree(m_request.text);
    CloseHandle( m_request.eventSet );
    CloseHandle( m_request.eventEmpty );
    m_request.valid = false;
    LeaveCriticalSection( &m_request.guard );
  }
    
  if ( m_response.GetLock() )
  {
    RELEASE(m_response.source);
    RELEASE(m_response.errors);    
    CloseHandle( m_response.eventSet );
    CloseHandle( m_response.eventEmpty );
    m_response.valid = false;
    LeaveCriticalSection( &m_response.guard );  
  }

  return S_OK;
};

/*---------------------------------------------------------
  Called from other threads
-----------------------------------------------------------*/
STDMETHODIMP_(bool) Parser::OnIdle( bool periodic )
{
  //TRACE("Parser::OnIdle");
  DWORD result = WaitForSingleObject( m_response.eventSet, 0 );
  if (result == WAIT_TIMEOUT)  return true;
  if (result != WAIT_OBJECT_0) return false;

  HandleResponse();
  return false;
}

STDMETHODIMP_(void) Parser::HandleResponse()  
{
  //TRACE("Parser::HandleResponse");
  //handle the response
  ASSERT(!m_response.empty);
  ASSERT(m_response.source);
  HRESULT hr = S_OK;

  if ( !m_response.GetLock() )
  {
    return;
  }
  //tell source about result
  switch (m_response.reason)
  {
  case ReasonCheck:
    hr = m_response.source->ResponseOnCheck( m_response.errors, 
                                             m_response.firstError,
                                             m_response.scope );
    break;
  case ReasonMemberSelect:
    hr = m_response.source->ResponseOnCompletion( m_response.textView,
                                                  m_response.spans,
                                                  false );
    break;
  case ReasonCompleteWord:
    hr = m_response.source->ResponseOnCompletion( m_response.textView,
                                                  m_response.spans,
                                                  true );
    break;
  case ReasonMethodTip:
    hr = m_response.source->ResponseOnMethodTip( m_response.textView,
                                                 m_response.spans,
                                                 m_response.currentParameter );
    break;

  case ReasonQuickInfo:
    if (m_response.fSync)
        hr = m_response.source->ResponseOnSyncQuickInfo( m_response.spans, m_response.taskID );
    else
        hr = m_response.source->ResponseOnQuickInfo( m_response.spans );
    break;

  case ReasonMatchBraces:
  case ReasonHighlightBraces:
    hr = m_response.source->ResponseOnMatchBraces( m_response.textView,
                                                   m_response.spans );
    break;
  case ReasonAutos:
    hr = m_response.source->ResponseOnAutos( m_response.spans );
    break;
  }
//  ASSERT(SUCCEEDED(hr));

  m_response.empty = true;
  RELEASE(m_response.errors);
  RELEASE(m_response.source);
  RELEASE(m_response.scope);
  TextSpanEmpty( &m_response.firstError );
  RELEASE(m_response.textView);
  RELEASE(m_response.spans);
  LeaveCriticalSection( &m_response.guard );

  //raise event
  BOOL success = SetEvent( m_response.eventEmpty );
  ASSERT(success);

  return;
}


STDMETHODIMP Parser::OnCheck( in Source* source, bool onIdle )
{
  //TRACE1("Parser::OnCheck: %i", onIdle);
  REFARG(source);
  if ( !m_request.valid )
    return E_UNEXPECTED;

  HRESULT hr = S_OK;
  
  BSTR text;
  hr = source->GetText( 0, &text );
  if (FAILED(hr)) return hr;
  
  //optimization: don't queue up on parse checks
  if ( !m_request.GetLock() )
  {
    return E_UNEXPECTED;
  }

  if (   !m_request.empty 
      && SameObject(static_cast<IVsTextLinesEvents*>(m_request.source),
                    static_cast<IVsTextLinesEvents*>(source) )
      && m_request.reason == ReasonCheck)
  {
    bstrFree(m_request.text);
    m_request.text = text;
  
    //leave early here
    LeaveCriticalSection( &m_request.guard );
    return S_OK;
  }
  LeaveCriticalSection( &m_request.guard );

  //wait until the request queue is empty
  DWORD result = WaitForSingleObject( m_request.eventEmpty, (onIdle ? 0 : 500) );
  if (result != WAIT_OBJECT_0) { bstrFree(text); return E_FAIL; }

  //set the request
  if ( !m_request.GetLock() )
  {
    return E_UNEXPECTED;
  }

  ASSERT(m_request.empty);
  m_request.empty  = false;
  m_request.reason = ReasonCheck;
  m_request.source = source; ADDREF(m_request.source);
  m_request.text   = text;
  m_request.fSync  = false;
  m_request.taskID = 0;

  BOOL success = SetEvent( m_request.eventSet );
  ASSERT(success);
  LeaveCriticalSection( &m_request.guard );

  //if synchronous, wait for response
  if (m_threadModel == 0)
  {
      result = WaitForSingleObject( m_response.eventSet, INFINITE );
      if (result != WAIT_OBJECT_0) return E_FAIL;
      
      HandleResponse();
  }

  return S_OK;
}


STDMETHODIMP Parser::OnTrigger( in Source* source, 
                                in IVsTextView* textView, 
                                in long line,
                                in long idx,
                                in ParseReason reason )
{
  TRACE( "Parser::OnTrigger" );
  REFARG(source);
  if ( !m_request.valid )
    return E_UNEXPECTED;

  //REFARG(textView);
  HRESULT hr;

  BSTR text;
  if (reason == ReasonMemberSelect || reason == ReasonMethodTip)
    hr = source->GetText( line, &text );
  else if (reason == ReasonCompleteWord || reason == ReasonQuickInfo)
    hr = source->GetText( line+1, &text );
  else
    hr = source->GetText( 0, &text );
  if (FAILED(hr)) return hr;
  

  //optimization: don't queue up on parse checks
  if ( !m_request.GetLock() )
  {
    return E_UNEXPECTED;
  }

  if (   !m_request.empty 
      && SameObject(static_cast<IVsTextLinesEvents*>(m_request.source),
                    static_cast<IVsTextLinesEvents*>(source) ) 
      && CHECK(m_request.reason))
  {
    bstrFree(m_request.text);
    
    m_request.reason = reason;
    m_request.text = text;
    m_request.idx  = idx;
    m_request.line = line;
    m_request.textView = textView; ADDREF(m_request.textView);
    
    //leave early here
    LeaveCriticalSection( &m_request.guard );
    return S_OK;
  }
  LeaveCriticalSection( &m_request.guard );

  //wait until the request queue is empty
  DWORD result = WaitForSingleObject( m_request.eventEmpty, 500 );
  if (result != WAIT_OBJECT_0) { bstrFree(text); return E_FAIL; }

  //set the request
  if ( !m_request.GetLock() )
  {
    return E_UNEXPECTED;
  }

  ASSERT(m_request.empty);
  m_request.empty  = false;
  m_request.reason = reason;
  m_request.source = source; ADDREF(m_request.source);
  m_request.text   = text;
  m_request.idx    = idx;
  m_request.line   = line;
  m_request.fSync  = false;
  m_request.taskID = 0;
  m_request.textView = textView; ADDREF(m_request.textView);   
  BOOL success = SetEvent( m_request.eventSet );
  ASSERT(success);
  LeaveCriticalSection( &m_request.guard );

  //if synchronous, wait for response
  if (m_threadModel == 0)
  {
      result = WaitForSingleObject( m_response.eventSet, INFINITE );
      if (result != WAIT_OBJECT_0) return E_FAIL;
      
      HandleResponse();
  }

  return S_OK;
}


STDMETHODIMP Parser::OnGetPairExtents( in Source* source, in long line, in long idx )
{
  TRACE( "Parser::OnGetPairExtents" );
  REFARG(source);
  HRESULT hr;

  
  BSTR text;
  hr = source->GetText( 0, &text );
  if (FAILED(hr)) return hr;
  

  //never queue up on any other request
  if ( !m_request.GetLock() )
  {
      return E_UNEXPECTED;
  }
  if ( !m_request.empty )
  {
    RELEASE(m_request.textView);
    RELEASE(m_request.source);
    bstrFree(m_request.text);
  }

  m_request.reason = ReasonMatchBraces;
  m_request.text = text;
  m_request.idx  = idx;
  m_request.line = line;
  m_request.textView = NULL; 
  m_request.fSync = true; 
  m_request.taskID = 0; 
  m_request.source   = source;   ADDREF(m_request.source);
  
  if (m_request.empty)
  {
    m_request.empty = false;
    BOOL success = SetEvent( m_request.eventSet );
    ASSERT(success);
  }
  LeaveCriticalSection( &m_request.guard );

  //wait for response
  DWORD result = WaitForSingleObject( m_response.eventSet, 5000 );
  if (result != WAIT_OBJECT_0) return E_FAIL;
  
  bool thisRequest;
  if ( !m_response.GetLock() )
  {
    return E_UNEXPECTED;
  }
  thisRequest = (m_response.reason == ReasonMatchBraces && m_response.source == source);
  LeaveCriticalSection( &m_response.guard );

  HandleResponse();
  
  if (!thisRequest) 
  {
    //wait for response again, this time the real one
    result = WaitForSingleObject( m_response.eventSet, 5000 );
    if (result != WAIT_OBJECT_0) return E_FAIL;
  
    HandleResponse();
  }

  return S_OK;
}

STDMETHODIMP Parser::OnGetAutos( in Source* source, in long line, in long endLine )
{
  TRACE( "Parser::OnGetAutos" );
  REFARG(source);
  if ( !m_request.valid ) 
    return E_UNEXPECTED;
  HRESULT hr;

  
  BSTR text;
  hr = source->GetText( endLine+1, &text );
  if (FAILED(hr)) return hr;
  

  //never queue up on any other request
  if ( !m_request.GetLock() )
  {
    return E_UNEXPECTED;
  }
  if ( !m_request.empty )
  {
    RELEASE(m_request.textView);
    RELEASE(m_request.source);
    bstrFree(m_request.text);
  }

  m_request.reason = ReasonAutos;
  m_request.text = text;
  
  m_request.idx  = line; // temp. use idx to hold the start line
  m_request.line = endLine;
  m_request.textView = NULL; 
  m_request.fSync = true; 
  m_request.taskID = 0; 
  m_request.source   = source;   ADDREF(m_request.source);
  
  if (m_request.empty)
  {
    m_request.empty = false;
    BOOL success = SetEvent( m_request.eventSet );
    ASSERT(success);
  }
  LeaveCriticalSection( &m_request.guard );

  //wait for response
  DWORD result = WaitForSingleObject( m_response.eventSet, 5000 );
  if (result != WAIT_OBJECT_0) return E_FAIL;
  
  bool thisRequest;
  if ( !m_response.GetLock() )
    return E_UNEXPECTED;
  thisRequest = (m_response.reason == ReasonAutos && m_response.source == source);
  LeaveCriticalSection( &m_response.guard );

  HandleResponse();
  
  if (!thisRequest) 
  {
    //wait for response again, this time the real one
    result = WaitForSingleObject( m_response.eventSet, 5000 );
    if (result != WAIT_OBJECT_0) return E_FAIL;
  
    HandleResponse();
  }

  return S_OK;
}


/*---------------------------------------------------------
  Main
-----------------------------------------------------------*/
#pragma warning( disable: 4127 ) //conditional expression is constant

STDMETHODIMP Parser::Main()
{
  TRACE1("Parser::Main: at 0x%x", this );
  while (true)
  { 
    //wait for request
    DWORD result = WaitForSingleObject( m_request.eventSet, 1000 );
    if (result == WAIT_TIMEOUT) 
    { 
      //TRACE1("Parser::Main: at 0x%x: request timeout", this); 
      continue; 
    }
    
    if (result != WAIT_OBJECT_0)
    {
      TRACE("Parser::Main: m_request.eventSet invalid");
      DeleteThis();
      return S_OK; 
    }
        

    if ( !m_request.GetLock() )
    {
      DeleteThis();
      return S_OK;
    }

    ASSERT(!m_request.empty);
    
    m_request.empty  = true;
    m_reason         = m_request.reason;
    m_source         = m_request.source;
    m_text           = m_request.text;
    m_textView       = m_request.textView;
    m_line           = m_request.line;
    m_idx            = m_request.idx;
    m_fSync          = m_request.fSync;
    m_taskID         = m_request.taskID;
    m_request.source = NULL;
    m_request.text   = NULL;
    m_request.textView = NULL;
    m_request.fSync  = false; 
    m_request.taskID = 0; 

    
    SetEvent( m_request.eventEmpty );
    LeaveCriticalSection( &m_request.guard );
    
    //handle request
    if (CHECK(m_reason))
    {
      m_errors = new ObjectList();
      if (!m_errors) continue;
      TextSpanEmpty( &m_firstError );      
      m_scope       = new Scope();      
    }
    else if (SELECT(m_reason) || MATCHBRACES(m_reason) || AUTOS(m_reason))
    {
      ASSERT(m_spans == NULL);
      m_spans = new LineSpanList();
      if (!m_spans) continue;
      m_methodCalls.Clear();
    }

    m_passed = m_found = false;
    IScope* scope = NULL;
    HRESULT hr = m_babelService->ParseSource( m_text, static_cast<IParseSink*>(this), m_reason, (long)m_textView, &scope );    
    bstrFree(m_text);
    
    if (scope)
    {
      RELEASE(m_scope);
    }
    else
    {
      scope = static_cast<IScope*>(m_scope);
      m_scope = NULL;
    }
    
    unsigned currentParameter;
    currentParameter = 0;
    if (m_reason == ReasonMethodTip)
    {
      RELEASE(m_spans);
      m_methodCalls.GetCurrentMethodCall( &m_spans, &currentParameter );
    }
    else if (!m_found)
    {
      RELEASE(m_spans);
      //RELEASE(m_textView);
    }
    m_methodCalls.Clear();

    if (FAILED(hr)) 
    { 
      RELEASE(m_textView);
      RELEASE(m_spans); 
      RELEASE(scope); 
      RELEASE(m_errors); 
      continue; 
    }
    
    //set response
    do{ result = WaitForSingleObject( m_response.eventEmpty, 1000 ); }
    while (result == WAIT_TIMEOUT);

    if ( (result != WAIT_OBJECT_0) || (!m_response.GetLock()) )
    { 
      TRACE("Parser::Main: m_response.eventEmpty invalid");
      RELEASE(m_textView);
      RELEASE(m_spans); 
      RELEASE(scope); 
      RELEASE(m_errors); 
      continue; 
    }

    ASSERT(m_response.empty);
    m_response.reason     = m_reason;
    m_response.source     = m_source;
    m_response.scope      = scope;
    m_response.errors     = m_errors;
    m_response.firstError = m_firstError;
    m_response.spans      = m_spans;
    m_response.currentParameter = currentParameter;
    m_response.textView   = m_textView;
    m_response.empty      = false;
    m_response.fSync      = m_fSync;
    m_response.taskID     = m_taskID;


    m_errors          = NULL;
    m_source          = NULL;
    m_scope           = NULL;
    m_textView        = NULL;
    m_spans           = NULL;
    TextSpanEmpty( &m_firstError );
    LeaveCriticalSection( &m_response.guard );

    SetEvent( m_response.eventSet );
  }
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Parser::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("Parser::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else if (iid == IID_IDispatch)
  {
    TRACE("Parser::QueryInterface for IDispatch");
    *obj = static_cast<IDispatch*>(this);
  }
  else if (iid == IID_IParseSink)
  {
    TRACE("Parser::QueryInterface for IParseSink");
    *obj = static_cast<IParseSink*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Parser::AddRef()
{
  IncRefCount(&m_refCount);
  if (DecRefCount(&m_refCount) != 0)
  {
    return IncRefCount(&m_refCount);
  }
  else
    return 0;
}

STDMETHODIMP_(ULONG) Parser::Release()
{
  if (DecRefCount(&m_refCount) == 0)
  {
    //Done closes all handles which causes Main eventually to delete itself
    Done(); 
    
    //give the parser some time to delete itself
    EVENT eventDeleted = m_eventDeleted; //save handle
    DWORD result = WaitForSingleObject( m_eventDeleted, 1500 );

#ifndef NDEBUG
    switch (result)
    {
    case WAIT_TIMEOUT: TRACE("deletion timed out"); break;
    case WAIT_ABANDONED: TRACE("deletion abandoned"); break;
    }
#endif

    CloseHandle(eventDeleted);
    return 0;
  }
  else
    return m_refCount;
}

/*---------------------------------------------------------
  implement IDispatch (for IParseSink only)
-----------------------------------------------------------*/
STDMETHODIMP Parser::GetTypeInfoCount( out UINT* count )
{
  OUTARG(count);

  if (g_typeInfoParseSink) *count = 1;
                      else *count = 0;
  return S_OK;
}

STDMETHODIMP Parser::GetTypeInfo( in UINT index, in LCID lcid, out ITypeInfo** typeInfo )
{
  OUTARG(typeInfo);
  if (index != 0) return E_INVALIDARG;
  if (!g_typeInfoParseSink) return TYPE_E_CANTLOADLIBRARY;

  *typeInfo = g_typeInfoParseSink;
  return S_OK;
}

STDMETHODIMP Parser::GetIDsOfNames( in REFIID iid, in OLECHAR** names, in UINT count, 
                                       in LCID lcid, out DISPID* dispids )
{
  if (!g_typeInfoParseSink) return TYPE_E_CANTLOADLIBRARY;
  return g_typeInfoParseSink->GetIDsOfNames( names, count, dispids );
}

STDMETHODIMP Parser::Invoke( in DISPID dispid, in REFIID iid, in LCID lcid, 
                                in WORD flags, in DISPPARAMS* args, 
                                out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg )
{
  if (!g_typeInfoParseSink) return TYPE_E_CANTLOADLIBRARY;  
  return g_typeInfoParseSink->Invoke( static_cast<IParseSink*>(this), 
                                      dispid, flags, args, result, error, errorArg );
}
  

/*---------------------------------------------------------
  IParseSink
-----------------------------------------------------------*/
STDMETHODIMP Parser::ErrorMessage( 
                           in long startLine, in long endLine,
                           in long startIdx,  in long endIdx,
                           in Severity severity, in BSTR message )
{
  //TRACE1("Parser::ErrorMessage", message );
  if (!message)  return E_INVALIDARG;
  if (!CHECK(m_reason)) return S_OK;
  if (!m_errors) return E_UNEXPECTED;

  ULONG errorCount = m_errors->GetCount();
  if (errorCount > m_errorMax)  return S_FALSE;
  
  //set error
  TextSpan span;
  span.iStartLine  = startLine;
  span.iStartIndex = startIdx;
  span.iEndLine    = endLine;
  span.iEndIndex   = endIdx;

  if (TextSpanIsEmpty(m_firstError ) && (severity > SevWarning))
  {
    m_firstError = span;
  }

  ErrorInfo* error = new ErrorInfo( message, span, severity );
  if (!error) return E_OUTOFMEMORY;

  m_errors->Insert( error );
  RELEASE(error);
  
  //check error count
  if (errorCount == m_errorMax)
  {
    error = new ErrorInfo( L"sorry, maximal number of error messages reached", span, severity );
    if (!error) return E_OUTOFMEMORY;

    m_errors->Insert( error );
    RELEASE(error);
  }

  return S_OK;
}

STDMETHODIMP Parser::MatchPair( in long startLine1, in long startIdx1
                      , in long endLine1,   in long endIdx1 
                      , in long startLine2, in long startIdx2
                      , in long endLine2,   in long endIdx2 )
{
  //TRACE("Parser::MatchPair");
  if (!MATCHBRACES(m_reason)) return S_OK;
  //if (m_found) return S_OK;
  HRESULT hr;

  bool foundLeftParen = (m_line >= startLine1 && m_line <= endLine1 &&
                         (m_line != startLine1 || m_idx >= startIdx1) &&
                         (m_line != endLine1 || m_idx <= endIdx1));
  
  bool foundRightParen= (m_line >= startLine2 && m_line <= endLine2 &&
                         (m_line != startLine2 || m_idx >= startIdx2) &&
                         (m_line != endLine2 || m_idx <= endIdx2));

  if (foundLeftParen || foundRightParen)
  {
    m_found = true;
    
    TextSpan spanLeftParen, spanRightParen;

    spanLeftParen.iStartLine = startLine1;
    spanLeftParen.iEndLine   = endLine1;
    spanLeftParen.iStartIndex= startIdx1;
    spanLeftParen.iEndIndex  = endIdx1;

    spanRightParen.iStartLine = startLine2;
    spanRightParen.iEndLine   = endLine2;
    spanRightParen.iStartIndex= startIdx2;
    spanRightParen.iEndIndex  = endIdx2;

    TextSpan* spanFound;
    TextSpan* spanOther;
    if (foundRightParen)
    {
      spanFound = &spanRightParen; 
      spanOther = &spanLeftParen;
    }
    else
    {
      spanFound = &spanLeftParen;
      spanOther = &spanRightParen;
    }

    //check which one is preferred in case of 2 touching braces
    if (m_spans->GetCount() > 0)
    {
      TextSpan prevFound;
      m_spans->Get( 0, &prevFound );
      if (prevFound.iEndLine == spanFound->iStartLine  && prevFound.iEndIndex == spanFound->iStartIndex)
      {
        //previous was left-most
        if (m_reason == ReasonHighlightBraces) return S_OK; //favor leftmost
      }
      else if (prevFound.iStartLine == spanFound->iEndLine && prevFound.iStartIndex == spanFound->iEndIndex)
      {
        //previous was right-most
        if (m_reason == ReasonMatchBraces) return S_OK; //favor right most
      }
      else
      {
        ASSERT("MatchPair: found, but not left or right??");
      }
    }

    m_spans->Clear();
    hr = m_spans->PushBack( *spanFound );
    if (FAILED(hr)) return hr;
    
    hr = m_spans->PushBack( *spanOther );
    if (FAILED(hr)) return hr;
   }

  return S_OK;
}

STDMETHODIMP Parser::MatchTriple( in long startLine1, in long startIdx1
                      , in long endLine1,   in long endIdx1 
                      , in long startLine2, in long startIdx2
                      , in long endLine2,   in long endIdx2
                      , in long startLine3, in long startIdx3
                      , in long endLine3,   in long endIdx3 )
{
  //TRACE("Parser::MatchTriple");
  if (!MATCHBRACES(m_reason)) return S_OK;
  if (m_found) return S_OK;
  HRESULT hr;

  bool foundLeftParen = (m_line >= startLine1 && m_line <= endLine1 &&
                         (m_line != startLine1 || m_idx >= startIdx1) &&
                         (m_line != endLine1 || m_idx <= endIdx1));
  
  
  bool foundMiddleParen=(m_line >= startLine2 && m_line <= endLine2 &&
                         (m_line != startLine2 || m_idx >= startIdx2) &&
                         (m_line != endLine2 || m_idx <= endIdx2));
  
  bool foundRightParen= (m_line >= startLine3 && m_line <= endLine3 &&
                         (m_line != startLine3 || m_idx >= startIdx3) &&
                         (m_line != endLine3 || m_idx <= endIdx3));

  m_found = foundLeftParen || foundMiddleParen || foundRightParen;

  if (m_found)
  {
    TextSpan spanLeftParen, spanMiddleParen, spanRightParen;

    spanLeftParen.iStartLine = startLine1;
    spanLeftParen.iEndLine   = endLine1;
    spanLeftParen.iStartIndex= startIdx1;
    spanLeftParen.iEndIndex  = endIdx1;

    spanMiddleParen.iStartLine = startLine2;
    spanMiddleParen.iEndLine   = endLine2;
    spanMiddleParen.iStartIndex= startIdx2;
    spanMiddleParen.iEndIndex  = endIdx2;
    
    spanRightParen.iStartLine = startLine3;
    spanRightParen.iEndLine   = endLine3;
    spanRightParen.iStartIndex= startIdx3;
    spanRightParen.iEndIndex  = endIdx3;

    if (foundRightParen)
    {
      hr = m_spans->PushBack( spanLeftParen );
      if (FAILED(hr)) return hr;
    
      hr = m_spans->PushBack( spanMiddleParen );
      if (FAILED(hr)) return hr;

      hr = m_spans->PushBack( spanRightParen );
      if (FAILED(hr)) return hr;
    }
    else
    {
      hr = m_spans->PushBack( spanRightParen );
      if (FAILED(hr)) return hr;

      hr = m_spans->PushBack( spanMiddleParen );
      if (FAILED(hr)) return hr;

      hr = m_spans->PushBack( spanLeftParen );
      if (FAILED(hr)) return hr;
    }
  }

  return S_OK;
}


STDMETHODIMP Parser::StartName( in long line, in long startIdx, in long endIdx )
{
  //TRACE2("Parser::StartName: line=%i, idx=%i", line, startIdx );
  HRESULT hr;
  
  //autos
  if (AUTOS(m_reason) && line >= m_idx && line <= m_line)
  {
    m_found = true;
    //TRACE( "Parser::AutoName" );
    TextSpan span;
    span.iStartLine = span.iEndLine = line;
    span.iStartIndex = startIdx;
    span.iEndIndex   = endIdx;
    hr = m_spans->PushBack( span );
    if (FAILED(hr)) return hr;
    
    return S_OK;
  }
  
  //----------
  //not autos
  if (!SELECT(m_reason)) return S_OK;
  if (m_passed) return S_OK;
  
  m_found  = (line == m_line && startIdx <= m_idx && endIdx >= m_idx);
  m_passed = (line > m_line || (line == m_line && endIdx >= m_idx));
  //if (m_found)  TRACE("Parser::StartName: found!");
  //if (m_passed) TRACE("Parser::StartName: passed!");
  
  m_spans->Clear();

  TextSpan span;
  span.iStartLine = span.iEndLine = line;
  span.iStartIndex = startIdx;
  span.iEndIndex   = endIdx;
  hr = m_spans->PushBack( span );
  if (FAILED(hr)) return hr;

  return S_OK;
}
  

STDMETHODIMP Parser::QualifyName( in long lineSelect, in long startIdxSelect, in long endIdxSelect,
                          in long line, in long startIdx, in long endIdx )
{
  //TRACE2("Parser::QualifyName: line=%i idx=%i", line, startIdx );
  HRESULT hr;
  
  //autos
  if (AUTOS(m_reason) && (line == m_line || lineSelect == m_line))
  {
    m_found = true;
    //TRACE( "Parser::AutoQualifyName" );

    TextSpan span1;
    span1.iStartLine  = span1.iEndLine = line;
    span1.iStartIndex = startIdx;
    span1.iEndIndex   = endIdx;

    TextSpan span2;
    span2.iStartLine  = span2.iEndLine = lineSelect;
    span2.iStartIndex = startIdxSelect;
    span2.iEndIndex   = endIdxSelect;

    TextSpan span;
    TextSpanMerge( span1, span2, &span );
    
    hr = m_spans->MergeTop( span );
    if (FAILED(hr)) return hr;
    
    return S_OK;
  }

  //-----------
  //not autos
  if (!SELECT(m_reason)) return S_OK;
  if (m_passed) return S_OK;
  
    
  m_found  = ((lineSelect == m_line && startIdxSelect <= m_idx && endIdxSelect >= m_idx)
            || (line == m_line && startIdx <= m_idx && endIdx >= m_idx) );
  m_passed = (line > m_line || (line == m_line && endIdx >= m_idx));
  //if (m_found)  TRACE("Parser::QualifyName: found!");
  //if (m_passed) TRACE("Parser::QualifyName: passed!");
   
  
  TextSpan select;
  select.iStartLine  = select.iEndLine = lineSelect;
  select.iStartIndex = startIdxSelect;
  select.iEndIndex   = endIdxSelect;
  hr = m_spans->PushBack( select );

  
  TextSpan span;
  if (lineSelect == line && startIdxSelect == startIdx) 
  {
    //parsed a selector but not a name anymore.
    // span.iStartLine = span.iEndLine = line;
    // span.iStartIndex = span.iEndIndex = endIdx;
  }
  else
  {
    span.iStartLine = span.iEndLine = line;
    span.iStartIndex = startIdx;
    span.iEndIndex   = endIdx;
    hr = m_spans->PushBack( span );
    if (FAILED(hr)) return hr;
  }  
    
  return S_OK;  
}


STDMETHODIMP Parser::AutoExpression( in long startLine, in long endLine,
                                     in long startIdx,  in long endIdx )
{
  HRESULT hr;
  if (!AUTOS(m_reason)) return S_OK;

  TextSpan span;
  span.iStartLine  = startLine,
  span.iEndLine    = endLine;
  span.iStartIndex = startIdx;
  span.iEndIndex   = endIdx;
  hr = m_spans->PushBack( span );
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP Parser::CodeSpan( in long startLine, in long startIdx, 
                               in long endLine, in long endIdx )
{
  //TODO: implement this
  return S_OK;
}
  

STDMETHODIMP Parser::StartParameters( in long line, in long idx )
{
  //TRACE("Parser::StartParameters");
  if (m_passed) return S_OK;

  m_found  = (line == m_line && idx == m_idx);
  m_passed = (line > m_line || (line == m_line && idx >= m_idx));
  if (m_passed && !m_found) return S_OK;

  if (m_spans->GetCount() == 0)
    m_methodCalls.Push( NULL );
  else
    m_methodCalls.Push( m_spans );
  
  m_spans->Clear();

  return S_OK;
}

STDMETHODIMP Parser::Parameter( in long line, in long idx )
{
  //TRACE("Parser::Parameter");
  if (m_passed) return S_OK;

  m_found  = (line == m_line && idx == m_idx);
  m_passed = (line > m_line || (line == m_line && idx >= m_idx));
  if (m_passed && !m_found) return S_OK;

  m_methodCalls.NextParameter();
  return S_OK;
}

STDMETHODIMP Parser::EndParameters  ( in long line, in long idx )
{
  //TRACE("Parser::EndParameters");
  if (m_passed) return S_OK;

  m_found  = (line == m_line && idx == m_idx);
  m_passed = (line > m_line || (line == m_line && idx >= m_idx));
  if (m_passed && !m_found) return S_OK;

  m_methodCalls.Pop();
  return S_OK;
}

/*---------------------------------------------------------
  Context
-----------------------------------------------------------*/
/*
STDMETHODIMP Parser::FindSource( in BSTR name, out BSTR* fileName )
{
  TRACE1("Parser::FindSource: %S", name );
  if (fileName) bstrFree(*fileName);
  if (!CHECK(m_reason)) return S_FALSE;
  OUTARG(fileName);
  
  //get a reference to this package
  IBabelPackage* babelPackage = NULL;
  HRESULT hr = m_provider->QueryService( SID_IBabelPackage, IID_IBabelPackage, (void**)&babelPackage );
  if (FAILED(hr)) return hr;

  //get the source name of this file
  BSTR sourcePath = NULL;
  hr = m_source->GetFilePath( &sourcePath );
  if (FAILED(hr)) { RELEASE(babelPackage); return hr; }

  //ask the package for the source name
  hr = babelPackage->FindSource( sourcePath, name, fileName );
  bstrFree(sourcePath);
  RELEASE(babelPackage);
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP Parser::LoadScope ( in VARIANT_BOOL delayLoad, in BSTR fileName, 
								 out IScope** scope )
{
  TRACE1("Parser::LoadScope: %S", fileName );
  if (scope) *scope = NULL;
  if (!CHECK(m_reason)) return S_FALSE;
  OUTARG(scope);

  //delay loading the real scope but return a "stub" interface
  *scope = new DelayScope( m_provider, fileName );
  return S_OK;
}
*/
STDMETHODIMP Parser::GetPackage( out IBabelPackage** package )
{
  OUTARG(package);

  //get a reference to this package
  HRESULT hr = m_provider->QueryService( SID_IBabelPackage, IID_IBabelPackage, reinterpret_cast<void**>(package) );
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP Parser::GetProject( out IBabelProject** project )
{
  OUTARG(project);
  if (!m_source) return E_FAIL;

  //get the file path
  BSTR filePath = NULL;
  HRESULT hr = m_source->GetFilePath( &filePath );
  if (FAILED(hr)) return hr;

  //get the hierarchy
  IVsHierarchy* hierarchy = NULL;
  VSITEMID      item = VSITEMID_NIL;
  hr = ProviderGetHierarchy( m_provider, filePath, &hierarchy, &item );
  bstrFree(filePath);
  if (FAILED(hr)) return hr;

  //QI for IBabelPackage
  hr = hierarchy->QueryInterface( IID_IBabelProject, reinterpret_cast<void**>(project) );
  RELEASE(hierarchy);
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP Parser::GetFileName( out BSTR* filePath )
{
  OUTARG(filePath);
  if (!m_source) return E_FAIL;
  return m_source->GetFilePath( filePath );
}


/*---------------------------------------------------------
  Scope Builder
-----------------------------------------------------------*/
STDMETHODIMP Parser::AddScope(  in long startLine, in long startIdx,
                        in long endLine,   in long endIdx,
                        in enum ScopeKind kind,
                        in enum ScopeAccess access,
                        in enum ScopeStorage storage,
                        in long glyph,
                        in BSTR name,     in BSTR type,
                        in BSTR display,  in BSTR description,
                        in VARIANT_BOOL merge
                      )                       
{
  //TRACE1("Parser::AddScope: %S", name );
  if (!CHECK(m_reason)) return S_OK;

  return m_scope->InsertScope( merge != 0, 
                      startLine, startIdx, endLine, endIdx,
                      kind, access, storage, glyph,
                      name, type, display, description );
}



STDMETHODIMP Parser::AddInclude( in long startLine, in long startIdx,
								 in long endLine,   in long endIdx,
								 in enum ScopeAccess access, in BSTR name )
{
  TRACE("Parser::AddInclude");
  if (!CHECK(m_reason)) return S_OK;

  return m_scope->AddIncludeScope( startLine, startIdx, endLine, endIdx, access, name );
}

STDMETHODIMP Parser::AddExtern( in long startLine, in long startIdx,
 							    in long endLine,   in long endIdx,
							    in IScope* scope )
{
  TRACE("Parser::AddExtern");
  if (!CHECK(m_reason)) return S_OK;
  
  return m_scope->AddExternScope( startLine, startIdx, endLine, endIdx, scope );
}


/*---------------------------------------------------------
  MethodCalls
-----------------------------------------------------------*/
MethodCalls::MethodCalls()
{
  m_count = 0;
}

MethodCalls::~MethodCalls()
{
}

STDMETHODIMP_(void) MethodCalls::Clear()
{
  m_count = 0;
}

STDMETHODIMP_(void) MethodCalls::Push( in LineSpanList* spans )
{
  if (m_count >= MaxCallNesting) 
  {
    m_count++; 
  }
  else
  {
    m_calls[m_count].count = 0;
    m_calls[m_count].currentParameter = 0;
    if (spans != NULL)
    {
      for (unsigned index = 0; index < spans->GetCount(); index++)
      {
        spans->Get( index, m_calls[m_count].spans + m_calls[m_count].count );
        m_calls[m_count].count++;      
      }
    }
    m_count++;
  }
  return;
}
  
STDMETHODIMP_(void) MethodCalls::NextParameter()
{
  //ASSERT(m_count > 0);
  if (m_count > 0 && m_count <= MaxCallNesting) 
  {
    m_calls[m_count-1].currentParameter++;
  }
}
  
STDMETHODIMP_(void) MethodCalls::Pop()
{
  //ASSERT(m_count > 0);
  if (m_count > 0) m_count--;
}

STDMETHODIMP MethodCalls::GetCurrentMethodCall( out LineSpanList** spans, out unsigned* currentParameter )
{
  OUTARG(spans);
  OUTARG(currentParameter);
  
  if (m_count <= 0 || m_count > MaxCallNesting) return S_FALSE;
  unsigned current = m_count-1;
  if (m_calls[current].count <= 0) return S_FALSE;

  *spans = new LineSpanList();
  if (*spans == NULL) return E_OUTOFMEMORY;

  for (unsigned index = 0; index < m_calls[current].count; index++)
  {
    (*spans)->PushBack( m_calls[current].spans[index] );
  }

  *currentParameter = m_calls[current].currentParameter;
  return S_OK;
}



STDMETHODIMP Parser::OnSyncQuickInfo( 
                                in Source* source, 
                                in IVsTextView* textView, 
                                in long line,
                                in long idx,
                                in ParseReason reason,
                                in DWORD taskID)
{
    TRACE( "Parser::OnSyncQuickInfo" );
    REFARG(source);
    if ( !m_request.valid ) return E_UNEXPECTED;
    HRESULT hr;

    BSTR text;
    hr = source->GetText( line+1, &text );
    if (FAILED(hr)) return hr;
  
    //never queue up on any other request
    if ( !m_request.GetLock() )
    {
      return E_UNEXPECTED;
    }
    if ( !m_request.empty )
    {
        RELEASE(m_request.textView);
        RELEASE(m_request.source);
        bstrFree(m_request.text);
    }

    m_request.reason = ReasonQuickInfo;
    m_request.text = text;
    m_request.idx  = idx;
    m_request.line = line;
    m_request.textView = textView; ADDREF(m_request.textView);
    m_request.source   = source;   ADDREF(m_request.source);
    m_request.fSync = true; 
    m_request.taskID = taskID; 
  
    if (m_request.empty)
    {
        m_request.empty = false;
        BOOL success = SetEvent( m_request.eventSet );
        ASSERT(success);
    }
    LeaveCriticalSection( &m_request.guard );

    DWORD dwTimeout = 50000; ///INFINITE
    
    if (m_threadModel == 0)//if synchronous, wait for response
        dwTimeout = INFINITE;

    DWORD result = WaitForSingleObject( m_response.eventSet, dwTimeout );
    if (result != WAIT_OBJECT_0) 
        return E_FAIL;
  
    bool thisRequest;
    if ( !m_response.GetLock() )
    {
      return E_UNEXPECTED;
    }
    thisRequest = ( m_response.reason == ReasonQuickInfo 
                 && m_response.source == source 
                 && m_response.fSync == true 
                 && m_response.taskID == taskID 
                 );
    LeaveCriticalSection( &m_response.guard );

    HandleResponse();
  
    if (!thisRequest) 
    {
        //wait for response again, this time the real one
        result = WaitForSingleObject( m_response.eventSet, dwTimeout );
        if (result != WAIT_OBJECT_0) return E_FAIL;
  
        HandleResponse();
    }

    return S_OK;
}

