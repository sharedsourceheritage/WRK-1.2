/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "dllmain.h"      //g_imageList
#include "lservice.h"
#include "preferences.h"
#include "source.h"
#include "colorizer.h"
#include "parser.h"
#include "taskprovider.h"
#include "completionset.h"
#include "methoddata.h"
#include "linespan.h"
#include "stringlist.h"
#include "vsmem.h"

#include <strsafe.h>

/*---------------------------------------------------------
  Source 
-----------------------------------------------------------*/

/* static */ DWORD Source::ms_taskID = 0;

/* static */ 
DWORD Source::GetNewTaskID()
{ 
  if (ms_taskID != (DWORD) -1) ///keep 0 reserved
      ms_taskID++; 
  else
      ms_taskID = 1;
  return ms_taskID;
}

Source::Source( in IServiceProvider* provider,
                in Preferences*     preferences,
                in IBabelService*   babelService, 
                in IVsTextLines*    textLines,
                in Parser*          parser )  
{
  TRACE_CREATE( "Source", static_cast<IVsTextLinesEvents*>(this) );
  ASSERT(provider);
  ASSERT(preferences);
  ASSERT(babelService);
  ASSERT(textLines);

  m_refCount        = 1;
  m_textLines       = textLines;        ADDREF(m_textLines);
  m_provider        = provider;         ADDREF(m_provider);
  m_babelService    = babelService;     ADDREF(m_babelService);
  m_preferences     = preferences;      ADDREF(m_preferences);
  m_parser          = parser;           ADDREF(m_parser);
  m_colorizer       = NULL;
  m_colorState      = NULL;
  m_taskProvider    = NULL;
  m_statusBar       = NULL;

  //parsing
  m_dirty             = 0;
  m_dirtyTime         = 0;
  m_errors            = NULL;

  //parsing
  m_textLinesConnect  = 0;     //IVsTextLinesEvents
  m_textChangeConnect = 0;     //IVsFinalTextChangeCommitEvents
  m_completionSet     = NULL;
  m_methodData        = NULL;
  m_scope             = NULL;
  memset( &m_scopeFirstError, 0, sizeof(m_scopeFirstError));

  //commenting
  memset( &m_commentInfo, 0, sizeof(m_commentInfo));
  m_commentInfo.supported = false;
  
  
  //callback: pair extents
  m_pairExtents       = NULL;

  //callback: auto expressions
  m_autos             = NULL;

  //callback: quick info
  m_quickInfoLine     = 0;
  m_quickInfoIdx      = 0;
  m_quickInfoText     = NULL;

  // sync quick info 
  m_pbstrSyncQuickInfo  = NULL;
  m_lSyncQuickInfoLine  = 0;
  m_lSyncQuickInfoIdx   = 0;
  m_taskIDSyncQuickInfo = 0;
  
}


Source::~Source()
{
  TRACE_DESTROY( static_cast<IVsTextLinesEvents*>(this) );
  Done();
  RELEASE(m_errors);
  RELEASE(m_scope);
  RELEASE(m_parser);
  RELEASE(m_preferences);
  RELEASE(m_babelService);
  RELEASE(m_provider);
  RELEASE(m_textLines);
}


STDMETHODIMP Source::Init()
{
  HRESULT hr;
  
  if (!m_colorizer)
  {
    m_colorizer = new Colorizer( m_babelService );
    if (!m_colorizer) return E_OUTOFMEMORY;
  }

  if (!m_colorState)
  {
    hr = m_textLines->QueryInterface( IID_IVsTextColorState, reinterpret_cast<void**>(&m_colorState) );
    if (FAILED(hr)) return hr;
  }

  if (!m_taskProvider)
  {
    m_taskProvider = new TaskProvider();
    if (!m_taskProvider) return E_OUTOFMEMORY;

    hr = m_taskProvider->Init(m_provider);
    if (FAILED(hr)) { m_taskProvider->Done(); RELEASE(m_taskProvider); return hr; }
  }

  if (!m_completionSet)
  {
    long imageListHandle;
    long glyphCount;
    hr = m_babelService->GetImageList( &imageListHandle, &glyphCount );

    HIMAGELIST imageList;
    if (FAILED(hr)) 
    {
      imageList  = g_imageList;
      glyphCount = g_imageListCount;
    }
    else
    {
      ASSERT(sizeof(imageListHandle) == sizeof(imageList));
      imageList = reinterpret_cast<HIMAGELIST>(imageListHandle);
    }

    m_completionSet = new CompletionSet( imageList, glyphCount, this );
    if (!m_completionSet) return E_OUTOFMEMORY;
  }

  if (!m_methodData)
  {
    m_methodData = new MethodData();
    if (!m_methodData) return E_OUTOFMEMORY;

    hr = m_methodData->Init( m_provider, m_babelService );
    if (FAILED(hr)) { m_methodData->Done(); return hr; }
  }

  if (!m_statusBar)
  {
    hr = m_provider->QueryService( SID_SVsStatusbar, IID_IVsStatusbar, (void**)&m_statusBar );
    //if (FAILED(hr)) return hr;
  }


  if (!m_commentInfo.supported)
  {
    VARIANT_BOOL useLineComment = 0;
    hr = m_babelService->GetCommentFormat( &m_commentInfo.lineStart,
                                           &m_commentInfo.blockStart, 
                                           &m_commentInfo.blockEnd,
                                           &useLineComment );
    if (hr == S_OK)
    {
      m_commentInfo.useLineComment = (useLineComment != 0);
      m_commentInfo.supported      = true;
    }
  }

  // track source changes
#ifdef VS7SDK
  if (!m_textChangeConnect && m_preferences->EnableCodeSenseFastOnLineChange())
  {
    hr = Connect( m_textLines, static_cast<IVsFinalTextChangeCommitEvents*>(this),
                  IID_IVsFinalTextChangeCommitEvents, &m_textChangeConnect );
    //if (FAILED(hr)) return hr;
  }
#endif

  if (!m_textLinesConnect)
  {
    hr = Connect( m_textLines, static_cast<IVsTextLinesEvents*>(this), 
                  IID_IVsTextLinesEvents, &m_textLinesConnect );
    if (FAILED(hr)) return hr;
  }

  return S_OK;
}

STDMETHODIMP Source::Done()
{
  if (m_textLinesConnect) DisConnect( m_textLines, IID_IVsTextLinesEvents, &m_textLinesConnect );

#ifdef VS7SDK
  if (m_textChangeConnect) DisConnect( m_textLines, IID_IVsFinalTextChangeCommitEvents, &m_textChangeConnect );
#endif

  bstrFree(m_commentInfo.lineStart);
  bstrFree(m_commentInfo.blockStart);
  bstrFree(m_commentInfo.blockEnd);
  m_commentInfo.useLineComment = false;
  m_commentInfo.supported      = false;

  RELEASE(m_statusBar);

  if (m_methodData)
  {
    m_methodData->Dismiss();
    m_methodData->Done();
    RELEASE(m_methodData);
  }

  if (m_completionSet)
  {
    m_completionSet->Done();
    RELEASE(m_completionSet);
  }

  if (m_taskProvider)
  {
    m_taskProvider->Done();
    RELEASE(m_taskProvider);
  }

  RELEASE(m_provider);
  RELEASE(m_colorState);  
  RELEASE(m_colorizer);
  return S_OK;
}



/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Source::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("Source::QueryInterface for IUnknown");
    *obj = static_cast<IVsTextLinesEvents*>(this);
  }
  else if (iid == IID_IVsTextLinesEvents)
  {
    TRACE("Source::QueryInterface for IVsTextLinesEvents");
    *obj = static_cast<IVsTextLinesEvents*>(this);
  }
#ifdef VS7SDK
  else if (iid == IID_IVsFinalTextChangeCommitEvents)
  {
    TRACE("Source::QueryInterface for IVsFinalTextChangeCommitEvents");
    *obj = static_cast<IVsFinalTextChangeCommitEvents*>(this);
  }
#endif
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Source::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Source::Release()
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
  Query
-----------------------------------------------------------*/
STDMETHODIMP_(bool) Source::SameBuffer( in IVsTextBuffer* textLines )
{
  return SameObject( m_textLines, textLines );
}

STDMETHODIMP Source::GetBuffer( out IVsTextLines** textLines )
{
  OUTARG(textLines);
 
  *textLines = m_textLines; ADDREF(*textLines);
  return S_OK;
}

STDMETHODIMP Source::GetFilePath( out BSTR* filePath )
{
  OUTARG(filePath);
  return ::GetFilePath( m_textLines, filePath );
}

STDMETHODIMP Source::GetText( in long line, out BSTR* text )
{
  OUTARG(text);
  HRESULT hr;

  long lastLine;
  hr = m_textLines->GetLineCount( &lastLine );
  lastLine--;
  if (FAILED(hr)) return hr;

  if (line > 0) lastLine = min( line, lastLine );
  
  long lastIdx;
  hr = m_textLines->GetLengthOfLine( lastLine, &lastIdx );
  if (FAILED(hr)) return hr;

  hr = m_textLines->GetLineText( 0, 0, lastLine, lastIdx, text );
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP Source::GetScope( out IScope** scope )
{
  OUTARG(scope);
  if (!m_scope) return E_FAIL;
  return m_scope->QueryInterface( IID_IScope, reinterpret_cast<void**>(scope) );
}

STDMETHODIMP Source::GetColorizer( out IVsColorizer** colorizer )
{
  OUTARG(colorizer);
  ASSERT(m_colorizer);
  if (!m_colorizer) return E_UNEXPECTED;

  return m_colorizer->QueryInterface( IID_IVsColorizer, reinterpret_cast<void**>(colorizer) );
}

STDMETHODIMP Source::GetLineInfo( in unsigned line, out const CharInfo** lineInfo, out unsigned* lineLen )
{
  OUTARG(lineInfo);
  OUTARG(lineLen);
  if (!m_colorizer) return E_UNEXPECTED;

  return m_colorizer->GetLineInfo( line, m_colorState, lineInfo, lineLen );
}

STDMETHODIMP_(bool) Source::IsCommitChar( in const wchar_t* text, in wchar_t commitChar )
{
  //hmm, tricky business; we need to disguise the text 
  // as if it was a line in the text editor. I think that part of this logic
  // should be in the GetLineInfoText method
  long len = lstrlenW(text);
  wchar_t* commitText = NALLOC(wchar_t,len+3);
  if (!commitText) return true;

  StringCchCopy( commitText, len, text );
  commitText[len]   = commitChar;
  commitText[len+1] = L'\n';
  commitText[len+2] = 0;

  const CharInfo* lineInfo;
  unsigned        length;
  long            state = 0;
  HRESULT hr = m_colorizer->GetLineInfoText( commitText, len+2, &state, &lineInfo, &length );
  FREE(commitText);
  if (FAILED(hr)) return true;

  //if nothing has been typed we check if it something else
  // than an identifier
  if (strEmpty(text))
    return (lineInfo[length-2].charClass > CharIdentifier);
  //otherwise we use a better method: has a new token started?
  else
    return (lineInfo[length-2].newToken);
}


/*---------------------------------------------------------
  IVsFinalTextChangeCommitEvents
-----------------------------------------------------------*/
STDMETHODIMP_(void) Source::OnChangesCommitted( in DWORD reason, in TextSpan* changedArea)
{
  TRACE("Source::OnChangesCommitted");
  if (m_dirty == 0 && m_taskProvider) m_taskProvider->RemoveErrorTasks();  
  if (m_dirty < 2) m_dirty = 2;    
  return;
}

/*---------------------------------------------------------
  IVsTextLinesEvents
-----------------------------------------------------------*/
STDMETHODIMP_(void) Source::OnChangeLineText( in const TextLineChange* lineChange, in BOOL last)
{
  TRACE("Source::OnChangeLineText");
  if (m_dirty == 0 && m_taskProvider) m_taskProvider->RemoveErrorTasks();
  if (m_dirty < 1) m_dirty = 1;
  return;
}

/*---------------------------------------------------------
  Triggers
-----------------------------------------------------------*/
static bool commandOneOnLine( DWORD command )
{
  switch (command)
  {
  case ECMD_TYPECHAR:
  case ECMD_BACKSPACE:
  case ECMD_TAB:
  case ECMD_BACKTAB:
  case ECMD_DELETE:
  case ECMD_LEFT:
  case ECMD_LEFT_EXT:
  case ECMD_RIGHT:
  case ECMD_RIGHT_EXT:
    return true;
  default:
    return false;
  }
}

STDMETHODIMP Source::OnCommand( in IVsTextView* textView, in DWORD command, in bool backward )
{
  REFARG(textView);
  if (!m_parser) return S_FALSE;
  HRESULT hr;

  //get current line 
  long line;
  long idx;
  hr = textView->GetCaretPos( &line, &idx );
  if (FAILED(hr)) return hr;

  //get line info
  unsigned        length   = 0;
  const CharInfo* lineInfo = NULL;
  hr = GetLineInfo( line, &lineInfo, &length );
  if (FAILED(hr)) return hr;

  //set character info
  TriggerClass triggerClass = TriggerNone;  
  if (idx > 0) triggerClass = lineInfo[idx-1].triggerClass;

  if ((triggerClass & TriggerMemberSelect) && (command == ECMD_TYPECHAR) && m_preferences->EnableMemberSelect())
  {
    TRACE("Source::OnCommand: member select");
    hr = Completion( textView, false );
    if (FAILED(hr)) return hr;
  }
     
#if (defined(VS7) && defined(VS7SDK))
  if ((triggerClass & TriggerMatchBraces) && m_preferences->EnableMatchBraces()) 
  {
    if ( (command != ECMD_BACKSPACE) && ((command == ECMD_TYPECHAR) || m_preferences->EnableMatchBracesAtCaret()))
    {
      TRACE("Source::OnCommand: match braces");
      hr = m_parser->OnTrigger( this, textView, line, idx, ReasonHighlightBraces );
      if (FAILED(hr)) return hr;
    }
  }
#endif

  //displayed & a trigger found
  if ((triggerClass & TriggerMethodTip) && m_methodData->IsDisplayed())
  {    
    if (commandOneOnLine(command) && ((triggerClass & TriggerMethodTip) == TriggerParamNext))
    {
      //this is an optimization
      TRACE("Source::OnCommand: method info - displayed - adjust parameter" );
      hr = m_methodData->AdjustCurrentParameter( (backward && idx > 0) ? -1 : +1 );
      if (FAILED(hr)) return hr;     
    }
    else
    {
      //this is the general case
      TRACE("Source::OnCommand: method info - displayed - trigger");
      hr = MethodTip( textView, line, (backward && idx > 0) ? idx-1 : idx );
      if (FAILED(hr)) return hr;
    }
  }
  //displayed & complex command
  else if (m_methodData->IsDisplayed() && !commandOneOnLine(command))
  { 
    TRACE("Source::OnCommand: method info - displayed - complex command");
    hr = MethodTip( textView, line, idx );
    if (FAILED(hr)) return hr;
  }
  //not displayed & trigger found & character typed & method info enabled
  else if ((triggerClass & TriggerMethodTip) && (command == ECMD_TYPECHAR) && m_preferences->EnableMethodTip())      
  {
    TRACE("Source::OnCommand: method info");
    hr = MethodTip( textView, line, idx );
    if (FAILED(hr)) return hr;
  }
  
  return S_OK;
}

/*---------------------------------------------------------
  Parser
-----------------------------------------------------------*/
STDMETHODIMP_(bool) Source::OnIdle( bool periodic )
{
  if (m_dirty != 0) 
  {
    RELEASE(m_errors);          //if errors, throw them away
    if (m_dirty == 1 && !periodic) return true; //only try to check at the periodic interval
    
    if (m_parser->OnCheck( this, true /*in idle time*/ ) == S_OK)
    {
      if (m_dirty > 1) m_dirtyTime = 0;    //no delay
                  else m_dirtyTime = GetTickCount();
      m_dirty     = 0;
      
    }
    return m_parser->OnIdle( periodic );
  }
  else
  {
    if (m_preferences->EnableCodeSense() && m_errors && m_taskProvider)
    {
       DWORD msec = GetTickCount();
       if ((msec < m_dirtyTime) ||                                    //overflow
           (msec > m_dirtyTime + m_preferences->GetCodeSenseDelay())) //at least X secs have passed
       {
          m_taskProvider->RefreshTasks( m_provider, m_textLines, m_errors );
          RELEASE(m_errors);          
       }
    }
    return false;
  }
}

STDMETHODIMP Source::ResponseOnCheck( in ObjectList*     errors, 
                                      in const TextSpan& firstError,
                                      in IScope*         scope )
{
  //TRACE("Source::ResponseOnCheck");
  if (!m_taskProvider) return E_UNEXPECTED;

  //update scope
  if (scope && 
      (TextSpanIsEmpty(firstError) ||
       (!TextSpanIsEmpty(m_scopeFirstError) && TextSpanAfterAt(firstError,m_scopeFirstError))
      )
     )
  {
    //TRACE("Source::ResponseOnCheck: update scope");
    RELEASE(m_scope);
    m_scope = scope; ADDREF(m_scope);
    m_scopeFirstError = firstError;
  }

  //set errors if source hasn't changed in the mean time
  if (m_dirty != 0) return S_FALSE;

  RELEASE(m_errors);
  m_errors = errors; 
  ADDREF(m_errors);
  
  return S_OK;
}

/*---------------------------------------------------------
  Response MatchBraces
-----------------------------------------------------------*/
STDMETHODIMP Source::GetPairExtents( long line, long idx, TextSpan* span )
{
  if (!span) return E_INVALIDARG;
        else memset( span, 0, sizeof(*span));
  if (!m_parser) return E_UNEXPECTED;
  HRESULT hr;

  m_pairExtents = span;
  hr = m_parser->OnGetPairExtents( this, line, idx );
  m_pairExtents = NULL;
  if (FAILED(hr)) return hr;

  if (span->iStartLine == span->iEndLine && span->iStartIndex == span->iEndIndex)
    return S_FALSE;

  return S_OK;
}

STDMETHODIMP Source::ResponseOnMatchBraces( in IVsTextView* textView, in LineSpanList* spanList  )
{
  TRACE("Source::ResponseOnMatchBraces");
  if (!spanList) return S_OK;
  HRESULT hr;
  
  //transform spanList into an array of spans
  const int MaxSpans = 10;
  
  TextSpan spans[MaxSpans];
  unsigned spanCount = spanList->GetCount();

  if (spanCount > MaxSpans) spanCount = MaxSpans;
  if (spanCount == 0)  return S_OK; 

  for( unsigned index = 0; index < spanCount; index++)
  {
    hr = spanList->Get( index, spans+index );
    if (FAILED(hr)) return hr;

    TextSpanNormalize( spans+index, m_textLines );
  }


  if (m_pairExtents)
  {
    //called from ViewFilter::GetPairExtents
    if (spans[0].iStartLine < spans[spanCount-1].iStartLine ||
        (spans[0].iStartLine == spans[spanCount-1].iStartLine && spans[0].iStartIndex <= spans[spanCount-1].iStartIndex ))
    {
      m_pairExtents->iStartLine  = spans[0].iStartLine;
      m_pairExtents->iStartIndex = spans[0].iStartIndex;
      m_pairExtents->iEndLine    = spans[spanCount-1].iStartLine;
      m_pairExtents->iEndIndex   = spans[spanCount-1].iStartIndex;
    }
    else
    {
      m_pairExtents->iStartLine  = spans[spanCount-1].iStartLine;
      m_pairExtents->iStartIndex = spans[spanCount-1].iStartIndex;
      m_pairExtents->iEndLine    = spans[0].iStartLine;
      m_pairExtents->iEndIndex   = spans[0].iStartIndex;
    }
    m_pairExtents = NULL;
  }
  else
  {
    //called from OnCommand, trigger
    REFARG(textView);

#if (defined(VS7) && defined(VS7SDK))
    //highlight
    hr = textView->HighlightMatchingBrace( 0, spanCount, spans );
    if (FAILED(hr)) return hr;

    //try to show the matching line in the statusbar
    if (m_statusBar && m_preferences->EnableShowMatchingBrace())
    {
      TextSpan* span = &spans[spanCount-1]; //the matching brace

      BSTR text;
      hr = m_textLines->GetLineText( span->iEndLine, 0, 
                                     span->iEndLine, span->iEndIndex, &text );
      if (FAILED(hr)) return hr;

      long start;
      for (start = 0; start < span->iEndIndex && 
                      text[start] && 
                      iswspace(text[start]); start++) ;

      if (start < span->iEndIndex) 
      {
        const size_t messageSize = 81;
        wchar_t message[messageSize] = L"match: ";
        StringCchCat( message, messageSize, text+start );
        
        hr = m_statusBar->SetText( message );
        if (FAILED(hr)) { bstrFree(text); return hr; }
      }

      bstrFree(text);     
    }
#endif 
  }

  return S_OK;
}

/*---------------------------------------------------------
  Response Auto Expressions
-----------------------------------------------------------*/
STDMETHODIMP Source::GetAutos( in long startLine, in long endLine, out StringList** autos )
{
  OUTARG(autos);
  if (!m_parser) return E_UNEXPECTED;
  HRESULT hr;

  m_autos = autos;
  hr = m_parser->OnGetAutos( this, startLine, endLine );
  m_autos = NULL;
  if (FAILED(hr)) return hr;
  if (*autos == NULL) return E_FAIL;

  return S_OK;
}


STDMETHODIMP Source::ResponseOnAutos( in LineSpanList* spans )
{
  TRACE("Source::ResponseOnAutos");
  if (!spans)   return E_INVALIDARG;
  if (!m_autos) return E_UNEXPECTED;
  if (!m_textLines) return E_UNEXPECTED;

  HRESULT hr;
  *m_autos = new StringList();
  if (*m_autos == NULL) return E_OUTOFMEMORY;
  
  hr = (*m_autos)->Init( m_textLines, spans );
  if (FAILED(hr)) { RELEASE(*m_autos); return hr; }

  m_autos = NULL;
  return S_OK;
}
  
/*---------------------------------------------------------
  Response Completion
-----------------------------------------------------------*/
STDMETHODIMP Source::Completion( in IVsTextView* textView, in bool completeWord )
{
  REFARG(textView);
  if (!m_parser) return E_UNEXPECTED;

  HRESULT hr;
  long line;
  long idx;
  hr = textView->GetCaretPos( &line, &idx );
  if (FAILED(hr)) return hr;

  hr = m_parser->OnTrigger( this, textView, line, idx, 
                            (completeWord ? ReasonCompleteWord : ReasonMemberSelect) );
  if (FAILED(hr)) return hr;

  return S_OK;
}


STDMETHODIMP Source::ResponseOnCompletion( in IVsTextView* textView, 
                                           in LineSpanList* spans,
                                           bool completeWord )
{
  TRACE("Source::ResponseOnComplete");
  REFARG(textView);
  if (!m_scope)  return E_UNEXPECTED;
  if (!m_completionSet) return E_UNEXPECTED;

  HRESULT hr;
  long line;
  long idx;
  hr = textView->GetCaretPos( &line, &idx );
  if (FAILED(hr)) return hr; 

  INames* names = NULL;
  if (spans)
  {
    hr = spans->GetNames( m_textLines, &names );
    if (FAILED(hr)) return hr;
  }

  IDeclarations* decls;
  hr = m_scope->GetDeclarations( line, idx, names, &decls );
  RELEASE(names);
  if (hr != S_OK) return hr;

  hr = m_completionSet->Init( textView, decls, completeWord );
  RELEASE(decls);
  if (hr != S_OK) return hr;

  return S_OK;
}


/*---------------------------------------------------------
  Response MethodTip
-----------------------------------------------------------*/
STDMETHODIMP Source::MethodTip( in IVsTextView* textView, in long line, in long idx )
{
  REFARG(textView);
  if (!m_parser) return E_UNEXPECTED;
  HRESULT hr;

  hr = m_parser->OnTrigger( this, textView, line, idx, ReasonMethodTip );
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP Source::ResponseOnMethodTip( in IVsTextView* textView, 
                                          in LineSpanList* spans,
                                          in unsigned currentParameter )
{
  TRACE("Source::ResponseOnMethodTip");
  REFARG(textView);
  if (!m_scope)  return E_UNEXPECTED;
  if (!m_methodData) return E_UNEXPECTED;
  HRESULT hr;

  if (!spans)    { hr = S_FALSE; goto fail; }

  long line;
  long idx;
  hr = textView->GetCaretPos( &line, &idx );
  if (FAILED(hr)) goto fail; 

  INames* names;
  hr = spans->GetNames( m_textLines, &names );
  if (FAILED(hr)) goto fail;
  
  IMethods* methods;
  hr = m_scope->GetMethods( line, idx, names, &methods );
  RELEASE(names);
  if (hr != S_OK) goto fail;
  if (methods == NULL) { hr = S_FALSE; goto fail; }

  hr = m_methodData->Refresh( textView, methods, currentParameter );
  RELEASE(methods);
  if (hr != S_OK) goto fail;

fail:
  if (hr != S_OK) 
  {
    DismissMethodTip();
    return hr;
  }

  return S_OK;
}


/*---------------------------------------------------------
  Response QuickInfo
-----------------------------------------------------------*/
STDMETHODIMP Source::OnQuickInfo( in IVsTextView* textView, in long line, in long idx, in BSTR* text)
{
  REFARG(text);
  if (m_quickInfoText) return E_PENDING;  //we are already working on quickinfo, try again later
    
  m_quickInfoLine = line;
  m_quickInfoIdx  = idx;
  m_quickInfoText = text;

  HRESULT hr = m_parser->OnTrigger( this, textView, line, idx, ReasonQuickInfo );
  if (FAILED(hr)) return hr;

  return E_PENDING;
}

STDMETHODIMP Source::ResponseOnQuickInfo( in LineSpanList* spans )
{
  //TRACE("Source::ResponseOnQuickInfo");
  if (!m_quickInfoText) return S_OK;
  BSTR* quickInfoText = m_quickInfoText;
  m_quickInfoText = NULL;

  *quickInfoText = SysAllocString(L"");
  if (!m_scope) return S_FALSE;
  if (!spans)   return S_FALSE;
  
  HRESULT hr;
  INames* names;
  hr = spans->GetNames( m_textLines, &names );
  if (FAILED(hr)) return hr;

  BSTR text;
  hr = m_scope->GetDataTipText( m_quickInfoLine, m_quickInfoIdx, names, &text );
  RELEASE(names);
  if (FAILED(hr)) return hr;

  bstrFree(*quickInfoText);
  *quickInfoText = text;

  return S_OK;
}


/*---------------------------------------------------------
  Response SyncQuickInfo
-----------------------------------------------------------*/
STDMETHODIMP Source::OnSyncQuickInfo( 
    in IVsTextView* textView, in long line, in long idx, in BSTR* text)
{
  TRACE2("Source::OnSyncQuickInfo : line=%i, idx=%i", line, idx);
  REFARG(text);

  // guard the members if they are called from different threads
  // right now they are always called from the UI thread
  m_pbstrSyncQuickInfo = text;
  m_lSyncQuickInfoLine = line;
  m_lSyncQuickInfoIdx  = idx;
  m_taskIDSyncQuickInfo = GetNewTaskID();

  HRESULT hr = m_parser->OnSyncQuickInfo( this, textView, line, idx, ReasonQuickInfo, m_taskIDSyncQuickInfo );

  // if everything is OK :
  //    - ResponseOnSyncQuickInfo has been called 
  //    - '*text' has been initialized to contain the info
  //    - m_pbstrSyncQuickInfo has been set to NULL
  // if not (e.g., timeout) 
  //    - ResponseOnSyncQuickInfo might be called later (on parser's OnIdle)
  //      so we need to set m_pbstrSyncQuickInfo to NULL here
  m_pbstrSyncQuickInfo = NULL;
  m_taskIDSyncQuickInfo = 0;

  return hr;
}


STDMETHODIMP Source::ResponseOnSyncQuickInfo( in LineSpanList* spans, in DWORD taskID )
{
  TRACE3("Source::ResponseOnSyncQuickInfo : line=%i, idx=%i, m_pbstrSyncQuickInfo=0x%x", m_lSyncQuickInfoLine, m_lSyncQuickInfoIdx, m_pbstrSyncQuickInfo);
  if (taskID != m_taskIDSyncQuickInfo) // we do not expect this quick info task
    return S_OK;
  if (!m_pbstrSyncQuickInfo) return S_OK;
  BSTR* pbstrSyncQuickInfo = m_pbstrSyncQuickInfo;
  m_pbstrSyncQuickInfo = NULL;

  *pbstrSyncQuickInfo = SysAllocString(L"");
  if (!m_scope) return S_FALSE;
  if (!spans)   return S_FALSE;
  
  HRESULT hr;
  INames* names;
  hr = spans->GetNames( m_textLines, &names );
  if (FAILED(hr)) return hr;

  BSTR text;
  hr = m_scope->GetDataTipText( m_lSyncQuickInfoLine, m_lSyncQuickInfoIdx, names, &text );
  RELEASE(names);
  if (FAILED(hr)) return hr;

  bstrFree(*pbstrSyncQuickInfo);
  *pbstrSyncQuickInfo = text;

  return S_OK;
}


STDMETHODIMP Source::DismissMethodTip()
{
    if (m_methodData)
        m_methodData->Dismiss();
    return S_OK;
}

/*---------------------------------------------------------
  GetWordExtent
-----------------------------------------------------------*/
static bool matchToken( DWORD flags, const CharInfo& charInfo )
{
  if (charInfo.newToken)
  {
    if ((flags & WORDEXT_FINDTOKEN) != 0)
      return !(charInfo.charClass == CharComment ||
               charInfo.charClass == CharLineComment ||
               charInfo.charClass == CharEmbedded);
    else 
      return (charInfo.charClass == CharKeyword ||
              charInfo.charClass == CharIdentifier ||
              charInfo.charClass == CharString ||
              charInfo.charClass == CharLiteral );
  }

  return false;
}

STDMETHODIMP Source::GetWordExtent( in long line, in long idx, in DWORD flags, 
                                    out long* startIdx, out long* endIdx )
{
  TRACE("Source::GetWordExtent");
  OUTARG(endIdx);
  OUTARG(startIdx);
  ASSERT(line >=0 && idx >= 0);
  HRESULT hr;

  //get the character classes
  const CharInfo*  charInfos = NULL;
  unsigned         ucount     = 0;
  hr = GetLineInfo( line, &charInfos, &ucount );
  if (FAILED(hr)) return hr;

  long count = ucount;

  //check bounds
  if (idx >= count) idx = count-1;
  if (idx < 0)      idx = 0;

  //don't do anything in comment space
  if (charInfos[idx].charClass == CharComment || 
      charInfos[idx].charClass == CharLineComment ||
      charInfos[idx].charClass == CharEmbedded )
    return S_FALSE;

  //search for a token
  switch (flags & WORDEXT_MOVETYPE_MASK)
  {
  case WORDEXT_PREVIOUS:
    idx--;
    while (idx >= 0 && !matchToken(flags,charInfos[idx])) idx--;
    if (idx < 0) return S_FALSE;
    break;

  case WORDEXT_NEXT:
    idx++;
    while (idx < count && !matchToken(flags,charInfos[idx])) idx++;
    if (idx >= count) return S_FALSE;
    break;

  case WORDEXT_NEAREST:
    {
      long prevIdx = idx;
      prevIdx--;
      while (prevIdx >= 0 && !matchToken(flags,charInfos[prevIdx])) prevIdx--;

      long nextIdx = idx;
      while (nextIdx < count && !matchToken(flags,charInfos[nextIdx])) nextIdx++;
      
           if (prevIdx < 0 && nextIdx >= count) return S_FALSE;
      else if (nextIdx >= count) idx = prevIdx;
      else if (prevIdx <  0)     idx = nextIdx;
      else if (idx - prevIdx < nextIdx - idx) idx = prevIdx;
                                         else idx = nextIdx;      
      break;
    }
  case WORDEXT_CURRENT:
  default:
   // if (idx >= 0 && !matchToken(flags,charInfos[idx])) idx--;

    while (idx >= 0 && !(charInfos[idx].newToken)) idx--;  
    if (idx < 0 || !matchToken(flags,charInfos[idx])) 
      return S_FALSE;
    break;
  }


  //we found something, set the span
  *startIdx = idx;
  idx++;
  while (idx < count-1 && !(charInfos[idx].newToken)) idx++;
  *endIdx = idx;
  hr = S_OK;

  TRACE2( "Source::GetWordExtent: found word extent %i %i", *startIdx, *endIdx );
  return S_OK;
}


/*---------------------------------------------------------
  Commenting
-----------------------------------------------------------*/
STDMETHODIMP_(bool) Source::CommentSupported()
{
  //TRACE("Source::CommentSupported");
  return m_commentInfo.supported;
}

STDMETHODIMP Source::CommentSelection( in IVsTextView* textView )
{
  TRACE("Source::CommentSelection");
  REFARG(textView);
  HRESULT hr;

  //get text range
  TextSpan span;
  hr = textView->GetSelectionSpan(&span);
  if (FAILED(hr)) return hr;


  //check bounds
  if (span.iEndIndex == 0) span.iEndLine--;

  //get line lengths
  long startLen,endLen;

  hr = m_textLines->GetLengthOfLine( span.iStartLine, &startLen );
  if (FAILED(hr)) return hr;

  hr = m_textLines->GetLengthOfLine( span.iEndLine, &endLen );
  if (FAILED(hr)) return hr;

  // adjust end index if necessary
  if (span.iEndIndex == 0) span.iEndIndex = endLen;

  int adjustment = 0;

  //try to use line comments first
  if ( (0!=SysStringLen(m_commentInfo.lineStart) && 0==SysStringLen(m_commentInfo.blockStart)) //we have to use line comments! 
       || (m_commentInfo.useLineComment && span.iStartIndex == 0 && span.iEndIndex == endLen)) //we can use line comments
  { 
     //comment each line
     for (long line = span.iStartLine; line <= span.iEndLine; line++)
     {
        hr = m_textLines->ReplaceLines( line, 0, line, 0
                                      , m_commentInfo.lineStart, SysStringLen(m_commentInfo.lineStart), NULL );
        if (FAILED(hr)) return hr;
     }

     adjustment      = SysStringLen( m_commentInfo.lineStart );
     span.iStartIndex = 0;
  }

  //then try to use block comments
  else if (0!=SysStringLen(m_commentInfo.blockStart))
  {
     //add end comment
     hr = m_textLines->ReplaceLines( span.iEndLine, span.iEndIndex, span.iEndLine, span.iEndIndex
                                 , m_commentInfo.blockEnd, SysStringLen(m_commentInfo.blockEnd), NULL );
     if (FAILED(hr)) return hr;
     //add start comment
     hr = m_textLines->ReplaceLines( span.iStartLine, span.iStartIndex, span.iStartLine, span.iStartIndex
                                 , m_commentInfo.blockStart, SysStringLen(m_commentInfo.blockStart), NULL );
     if (FAILED(hr)) return hr;

     adjustment = SysStringLen(m_commentInfo.blockEnd);
     if (span.iStartLine == span.iEndLine) adjustment += SysStringLen(m_commentInfo.blockStart);
  }
  else
    return E_FAIL;

       
  if (TextSpanPositive(span))
   hr = textView->SetSelection( span.iStartLine, span.iStartIndex, span.iEndLine, span.iEndIndex + adjustment );
  else
   hr = textView->SetSelection( span.iEndLine, span.iEndIndex + adjustment, span.iStartLine, span.iStartIndex );
  if (FAILED(hr)) return hr;
  
  return S_OK;
}

STDMETHODIMP Source::UnCommentSelection( in IVsTextView* textView )
{
  TRACE("Source::UnCommentSelection");
  REFARG(textView);
  HRESULT hr;

  //get text range
  TextSpan span;
  hr = textView->GetSelectionSpan(&span);
  if (FAILED(hr)) return hr;

  //check bounds
  if (span.iEndIndex == 0) span.iEndLine--;

  //get line lengths
  long startLen,endLen;

  hr = m_textLines->GetLengthOfLine( span.iStartLine, &startLen );
  if (FAILED(hr)) return hr;

  hr = m_textLines->GetLengthOfLine( span.iEndLine, &endLen );
  if (FAILED(hr)) return hr;

  // adjust end index if necessary
  if (span.iEndIndex == 0) span.iEndIndex = endLen;

  
  int adjustment = 0;

  // is block comment selected?
  if (0!=SysStringLen(m_commentInfo.blockStart))
  {
    BSTR startText = NULL;
    hr = m_textLines->GetLineText( span.iStartLine, span.iStartIndex, span.iStartLine, span.iStartIndex+SysStringLen(m_commentInfo.blockStart), &startText );
    if (FAILED(hr)) return hr;

    bool equal = strICompare(startText,m_commentInfo.blockStart)==0;
    bstrFree(startText);

    if (equal) 
    {
      BSTR endText = NULL;
      hr =m_textLines->GetLineText( span.iEndLine, span.iEndIndex-SysStringLen(m_commentInfo.blockEnd), span.iEndLine, span.iEndIndex, &endText );
      if (FAILED(hr)) return hr;

      equal = strICompare(endText,m_commentInfo.blockEnd)==0;
      bstrFree(endText);
      if (equal)
      {
        //yes, block comment selected; remove it        
        hr = m_textLines->ReplaceLines( span.iEndLine, span.iEndIndex-SysStringLen(m_commentInfo.blockEnd), span.iEndLine, span.iEndIndex, NULL, 0, NULL );
        if (FAILED(hr)) return hr;
        
        hr = m_textLines->ReplaceLines( span.iStartLine, span.iStartIndex, span.iStartLine, span.iStartIndex+SysStringLen(m_commentInfo.blockStart), NULL, 0, NULL );
        if (FAILED(hr)) return hr;
  
        adjustment = -(int)SysStringLen(m_commentInfo.blockEnd);
        if (span.iStartLine == span.iEndLine) adjustment -= SysStringLen(m_commentInfo.blockStart);
 
        goto end;
      }
    }
  }

  //if no line comment possible, we are done
  if (0==SysStringLen(m_commentInfo.lineStart)) return S_FALSE;
  
  //try if we can remove line comments
  // any line in the selection that starts with a line comment (maybe preceded by whitespace)
  // will be uncommented
  long line;
  for (line = span.iStartLine; line <= span.iEndLine; line++)
  {
    unsigned        lineLen;
    const CharInfo* lineInfo;

    hr = GetLineInfo( line, &lineInfo, &lineLen );
    if (FAILED(hr)) return hr;

    int idx;
    int endIdx;

    if (line == span.iStartLine) idx = span.iStartIndex;
                             else idx = 0;

    if (line == span.iEndLine) endIdx = span.iEndIndex;
                           else endIdx = lineLen;


    while (idx < endIdx && lineInfo[idx].charClass == CharWhiteSpace) idx++;
    if (idx == endIdx) continue;
    if (lineInfo[idx].charClass != CharLineComment) continue;

    // is it a start line token?
    BSTR startText = NULL;
    hr = m_textLines->GetLineText( line, idx, line, idx+SysStringLen(m_commentInfo.lineStart), &startText );
    if (FAILED(hr)) return hr;

    bool equal = strICompare(startText,m_commentInfo.lineStart)==0;
    bstrFree(startText);

    if (equal)
    {
      //yes remove it
      hr = m_textLines->ReplaceLines( line, idx, line, idx+SysStringLen(m_commentInfo.lineStart), NULL, 0, NULL );
      if (FAILED(hr)) return hr;

      if (line == span.iEndLine)
      {
        adjustment = -(int)SysStringLen(m_commentInfo.lineStart);
      }
    }
  }

end:
  if (TextSpanPositive(span))
   hr = textView->SetSelection( span.iStartLine, span.iStartIndex, span.iEndLine, span.iEndIndex + adjustment );
  else
   hr = textView->SetSelection( span.iEndLine, span.iEndIndex + adjustment, span.iStartLine, span.iStartIndex );
  if (FAILED(hr)) return hr;

  return S_OK;
}

