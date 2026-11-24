/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "lservice.h"
#include "preferences.h"
#include "source.h"
#include "viewfilter.h"
#include "TextTipData.h"

#ifdef VS6SDK
const GUID CMDSETID_StandardCommandSet2K = CLSID_CTextViewCommandGroup; 
#define ECMD_COMMENT_BLOCK    ECMD_COMMENTBLOCK
#define ECMD_UNCOMMENT_BLOCK  ECMD_UNCOMMENTBLOCK
#define TIP_S_ONLYIFNOMARKER  S_OK
#else //VS7SDK
const GUID CMDSETID_StandardCommandSet2K 
    = { 0x1496A755, 0x94DE, 0x11D0, { 0x8C, 0x3F, 0x00, 0xC0, 0x4F, 0xC2, 0xAA, 0xE2 }};
#endif



/*---------------------------------------------------------
  ViewFilter
-----------------------------------------------------------*/
ViewFilter::ViewFilter( in LanguageService* lservice, 
                        in Preferences*     preferences,
                        in IVsTextView*     textView )
{
  TRACE_CREATE( "ViewFilter", static_cast<IVsTextViewFilter*>(this) );
  ASSERT(lservice);
  ASSERT(textView);
  ASSERT(preferences);

  m_refCount          = 1;
  m_lservice          = lservice;     ADDREF(m_lservice);
  m_textView          = textView;     ADDREF(m_textView);
  m_preferences       = preferences;  ADDREF(m_preferences);

  m_source            = NULL;
  m_textLines         = NULL;
  m_nextCommandTarget = NULL;

  //callback: quick info
  m_quickInfoLine     = 0;
  m_quickInfoIdx      = 0;
  m_quickInfoText     = NULL;

  m_pTextTipData      = NULL;
}


ViewFilter::~ViewFilter()
{
  TRACE_DESTROY( static_cast<IVsTextViewFilter*>(this) );

  Done();
  bstrFree(m_quickInfoText);
  
  RELEASE(m_textView);
  RELEASE(m_preferences);
  RELEASE(m_lservice);
}

/*---------------------------------------------------------
  Init/Done
-----------------------------------------------------------*/
STDMETHODIMP ViewFilter::Init()
{
  HRESULT hr;

  //get the buffer
  if (!m_textLines)
  {
    hr = m_textView->GetBuffer( &m_textLines );
    if (FAILED(hr)) return hr;
  }

  //get the source
  if (!m_source)
  {
    hr = m_lservice->GetSource(m_textLines, &m_source );
    if (FAILED(hr)) return hr;
  }

  //hook up into the command chain
  if (!m_nextCommandTarget)
  {
    hr = m_textView->AddCommandFilter( this, &m_nextCommandTarget );
    if (FAILED(hr)) return hr;
  }

  return S_OK;
}


STDMETHODIMP ViewFilter::Done()
{
  if (m_nextCommandTarget)
  {
    RELEASE(m_nextCommandTarget);
    m_textView->RemoveCommandFilter(this);
  }

  RELEASE(m_source);
  RELEASE(m_textLines);
  if (m_pTextTipData)
    m_pTextTipData->Close();
  RELEASE(m_pTextTipData);

  return S_OK;
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP ViewFilter::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsTextViewFilter)
  {
    TRACE("ViewFilter::QueryInterface for IUnknown/IVsTextViewFilter");
    *obj = static_cast<IVsTextViewFilter*>(this);
  }
  else if (iid == IID_IOleCommandTarget)
  {
    TRACE("ViewFilter::QueryInterface for IOleCommandTarget");
    *obj = static_cast<IOleCommandTarget*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) ViewFilter::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) ViewFilter::Release()
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
  IVsTextViewFilter methods
-----------------------------------------------------------*/
STDMETHODIMP ViewFilter::GetWordExtent( in long line, in CharIndex index, in DWORD flags
                                      , out TextSpan* span)
{
  TRACE("ViewFilter::GetWordExtent");
  ASSERT(line>=0 && index >=0);
  if (!span) return E_INVALIDARG;
        else memset(span,0,sizeof(*span));

  long startIdx;
  long endIdx;
  HRESULT hr = m_source->GetWordExtent( line, index, flags, &startIdx, &endIdx );
  if (hr != S_OK) return hr;

  span->iStartLine = span->iEndLine = line;
  span->iStartIndex = startIdx;
  span->iEndIndex   = endIdx;

  return S_OK;
}

STDMETHODIMP ViewFilter::GetDataTipText( inout TextSpan* span, out BSTR* text )
{
  TRACE("ViewFilter::GetDataTipText");
  OUTARG(text);
  REFARG(span);
  HRESULT hr;

  if (!m_preferences->EnableQuickInfo()) 
  { 
    bstrFree(m_quickInfoText); 
    return E_FAIL; 
  }

  if (span->iEndLine == m_quickInfoLine && span->iEndIndex == m_quickInfoIdx)
  {
    m_quickInfoLine = -1;
    m_quickInfoIdx  = -1;
    if (!m_quickInfoText) 
      return E_PENDING;

    if (0==SysStringLen(m_quickInfoText)) 
    { 
        bstrFree(m_quickInfoText); 
        return E_FAIL; 
    }

    // Now, check if the debugger is running and has anything to offer
    BSTR bstrDebugDataTip = NULL;
    IVsDebugger* pIVsDebugger = m_lservice->GetIVsDebugger();// un-addref
    if (pIVsDebugger)
    {
      TextSpan ts(*span);

      hr = S_OK;
      BOOL fSelection = ( (span->iStartLine  != span->iEndLine) || (span->iStartIndex != span->iEndIndex) );
      if (!fSelection)
      {
        // The debugger can't determine the current word by itself. 
        // Do it for them...
        hr = m_textView->GetWordExtent(span->iStartLine, span->iStartIndex, WORDEXT_FINDWORD|WORDEXT_CURRENT, &ts);
      }
      if (SUCCEEDED(hr))
      {
        hr = pIVsDebugger->GetDataTipValue(m_textLines, &ts, NULL, &bstrDebugDataTip);
      }
    }

    if (0!=SysStringLen(bstrDebugDataTip))
    {
      UINT len = ::SysStringLen(m_quickInfoText) + ::SysStringLen(bstrDebugDataTip);
      size_t bufferSize = len + 5;
      WCHAR* pwsz = new WCHAR[bufferSize];
      if (NULL == pwsz)
         return E_OUTOFMEMORY;
      pwsz[bufferSize-1] = 0;
      if (pwsz != NULL)
      {
        wcsncpy(pwsz, m_quickInfoText, bufferSize-1);

        // try to merge by looking for '='
        PWSTR pszEqual = wcschr (bstrDebugDataTip, '=');
        if (pszEqual == NULL)
        {
          // No equal sign -- default to the DEBUGGER tip, not the quick info tip...
          wcsncpy(pwsz, bstrDebugDataTip, bufferSize-1);
        }
        else
        {
          if (pszEqual[1] == ' ')
            wcscat(pwsz, L" ");
          wcscat(pwsz, pszEqual);
        }
      }

      BSTR bstrDataTip = ::SysAllocString(pwsz);

      bstrFree(m_quickInfoText);
      bstrFree(bstrDebugDataTip);
      if (pwsz) 
        delete[] pwsz;

      if (0==SysStringLen(bstrDataTip)) 
      { 
        bstrFree(bstrDataTip); 
        return E_FAIL;
      }

      *text = bstrDataTip;
    }
    else
    {
      bstrFree(bstrDebugDataTip);
      *text = m_quickInfoText;
      m_quickInfoText = NULL;
    }

    GetWordExtent( span->iStartLine, span->iStartIndex, WORDEXT_CURRENT | WORDEXT_FINDTOKEN, span );
  }
  else
  {
    bstrFree(m_quickInfoText);
    m_quickInfoLine = span->iEndLine;
    m_quickInfoIdx  = span->iEndIndex;
    hr = m_source->OnQuickInfo( m_textView, m_quickInfoLine, m_quickInfoIdx, &m_quickInfoText );
    if (FAILED(hr)) return hr;  //always E_PENDING
  }

#ifdef VS6
  return S_OK; 
#else
  return TIP_S_ONLYIFNOMARKER;
#endif
}

STDMETHODIMP ViewFilter::GetPairExtents( in long line, in CharIndex index, out TextSpan* span)
{
  TRACE("ViewFilter::GetWordExtent");
  ASSERT(line>=0 && index >=0);
  if (!span) return E_INVALIDARG;
        else memset(span,0,sizeof(*span));
  HRESULT hr;

  hr = m_source->GetPairExtents( line, index, span );
  if (FAILED(hr)) return hr;

  return S_OK;
}


/*---------------------------------------------------------
  IOleCommandTarget 
-----------------------------------------------------------*/
STDMETHODIMP ViewFilter::QueryStatus(in const GUID* commandGroup, in ULONG count, out OLECMD commands[], out OLECMDTEXT* commandText )
{
//  TRACE("ViewFilter::QueryStatus");
  REFARG(commands);
  REFARG(commandGroup);
  
  if( CMDSETID_StandardCommandSet2K == *commandGroup)
  {
    switch( commands[0].cmdID )
    {
    case ECMD_COMMENT_BLOCK:
    case ECMD_UNCOMMENT_BLOCK:
      if (!m_source || !m_source->CommentSupported()) break;
      commands[0].cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
      return S_OK;

    case ECMD_SHOWMEMBERLIST:
    case ECMD_COMPLETEWORD:
    case ECMD_PARAMINFO:
      commands[0].cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
      return S_OK;
    case ECMD_QUICKINFO:
      if (m_preferences->EnableQuickInfo())
      {
        commands[0].cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
        return S_OK;
      }
      break;

#if (!defined(VS6SDK) && !defined(FEB00SDK))
    case ECMD_HANDLEIMEMESSAGE:
      commands[0].cmdf = 0;
      return S_OK;
#endif

    default:
      //fall through
      ;
    }
  }

  // pass this command to the next in chain 
  if (!m_nextCommandTarget) 
    return E_FAIL;
  else     
    return m_nextCommandTarget->QueryStatus( commandGroup, count, commands, commandText );
}


STDMETHODIMP ViewFilter::Exec(in const GUID * commandGroup, 
                              in DWORD        command, 
                              in DWORD        options, 
                              in VARIANT*     arg, 
                              out VARIANT*    result)
{ 
//  TRACE("ViewFilter::Exec");
  if (result) VariantInit(result);
  REFARG(commandGroup);
  HRESULT hr = S_OK;

  // On every command, update the tip window if it's active.
  if (m_pTextTipData != NULL && m_pTextTipData->IsActive())
      m_pTextTipData->CheckCaretPosition ();

  if( CMDSETID_StandardCommandSet2K == *commandGroup && (m_source != NULL))
  {
    ProviderClearErrorInfo( m_lservice );   

    switch( command )
    {      
    case ECMD_COMMENT_BLOCK:
      hr = m_source->CommentSelection( m_textView );
      break;

    case ECMD_UNCOMMENT_BLOCK:
      hr = m_source->UnCommentSelection( m_textView );
      break;
    
    case ECMD_COMPLETEWORD:
      hr = m_source->Completion( m_textView, true );
      break;

    case ECMD_SHOWMEMBERLIST:
      hr = m_source->Completion( m_textView, false );
      break;

    case ECMD_PARAMINFO:
      { 
        long line;
        long idx;
        hr = m_textView->GetCaretPos( &line, &idx );
        if (SUCCEEDED(hr))
        {
          hr = m_source->MethodTip( m_textView, line, idx );
        }
        break;
      }
    case ECMD_QUICKINFO:
        {
            HandleQuickInfo();
            break;
        }

#if (!defined(VS6SDK) && !defined(FEB00SDK))
    case ECMD_HANDLEIMEMESSAGE:
      if (result)
      {
        result->vt      = VT_BOOL;
        result->boolVal = FALSE;
      }
      hr = m_nextCommandTarget->Exec( commandGroup, command, options, arg, result );      
      return hr;
#endif
      
    case ECMD_BACKSPACE:
    case ECMD_BACKTAB:
    case ECMD_LEFT:
    case ECMD_LEFT_EXT:
      m_source->OnCommand( m_textView, command, true );
      hr = m_nextCommandTarget->Exec( commandGroup, command, options, arg, result );
      return hr;

    default:          
      hr = m_nextCommandTarget->Exec( commandGroup, command, options, arg, result );
      m_source->OnCommand( m_textView, command, false );
      return hr; 
    }

    if (FAILED(hr)) ProviderReportErrorInfo( m_lservice, hr );
    return S_OK;
  }
  else
  {
    return m_nextCommandTarget->Exec( commandGroup, command, options, arg, result ); 
  }
}


STDMETHODIMP ViewFilter::HandleQuickInfo()
{
    BSTR bstrText = NULL;
    TextSpan    ts;
    HRESULT     hr;

    // Get the caret position
    hr = m_textView->GetCaretPos (&ts.iStartLine, &ts.iStartIndex);
    if (FAILED(hr))
        return hr;
    ts.iEndLine  = ts.iStartLine;
    ts.iEndIndex = ts.iStartIndex;

    // Get the tip text at that location. 
    // Wait, since the user specifically requested this one...
    hr = m_source->OnSyncQuickInfo(
        m_textView, 
        ts.iEndLine, 
        ts.iEndIndex, 
        &bstrText);
    if ( FAILED(hr) )
        return hr;

    if (0==SysStringLen(bstrText)) // nothing to show
    {
        bstrFree(bstrText);
        return S_OK;
    }

    BSTR bstrFullText = NULL;
    hr = GetFullDataTipText(bstrText, ts, &bstrFullText);
    if (FAILED(hr))
    {
        bstrFree(bstrText);
        bstrFree(bstrFullText);
        return hr;
    }

    long iPos, iPosEnd, iSpace, iLength;

    // Calculate the stream position
    if (SUCCEEDED (hr = m_textView->GetNearestPosition (ts.iStartLine, ts.iStartIndex, &iPos, &iSpace)) &&
        SUCCEEDED (hr = m_textView->GetNearestPosition (ts.iEndLine, ts.iEndIndex, &iPosEnd, &iSpace)))
    {
        iLength = max (iPosEnd - iPos, 1);
    }

    // Tear down the method tip if it's there
    m_source->DismissMethodTip();

    // Update the text tip window
    CTextTipData* pTextTipData = GetTextTipData();
    if (pTextTipData)
        hr = pTextTipData->Update(bstrFullText, iPos, iLength);
    else
        hr = E_UNEXPECTED;

    bstrFree(bstrText);
    bstrFree(bstrFullText);

    return hr;
}


HRESULT ViewFilter::GetFullDataTipText(
    in  BSTR        bstrCurrentText,
    in  TextSpan    ts,
    out BSTR*       pbstrFullText)
{
    HRESULT hr = S_OK;

    // Now, check if the debugger is running and has anything to offer
    BSTR bstrDebugDataTip = NULL;
    IVsDebugger* pIVsDebugger = m_lservice->GetIVsDebugger();// un-addref
    if (pIVsDebugger)
    {
        TextSpan tsDeb(ts);
        hr = S_OK;
        BOOL fSelection = ( (ts.iStartLine  != ts.iEndLine) || (ts.iStartIndex != ts.iEndIndex) );
        if (!fSelection)
        {
            // The debugger can't determine the current word by itself. 
            // Do it for them...
            hr = m_textView->GetWordExtent(ts.iStartLine, ts.iStartIndex, WORDEXT_FINDWORD|WORDEXT_CURRENT, &tsDeb);
        }
      
        if (SUCCEEDED(hr))
        {
            hr = pIVsDebugger->GetDataTipValue(m_textLines, &tsDeb, NULL, &bstrDebugDataTip);
        }
    }

    if (0==SysStringLen(bstrDebugDataTip))
    {
        bstrFree(bstrDebugDataTip);
        *pbstrFullText = SysAllocString(bstrCurrentText);
        return S_OK;
    }


    UINT len = ::SysStringLen(bstrCurrentText) + ::SysStringLen(bstrDebugDataTip);
    size_t bufferSize = len + 5;
    WCHAR* pwsz = new WCHAR[bufferSize];
    if (NULL == pwsz)
        return E_OUTOFMEMORY;
    pwsz[bufferSize-1] = 0;
    if (pwsz != NULL)
    {
        if ( ::SysStringLen(bstrCurrentText) > 0 )
            wcsncpy(pwsz, bstrCurrentText, bufferSize-1);
        else
            pwsz[0] = '\0';

        // try to merge by looking for '='
        PWSTR pszEqual = wcschr (bstrDebugDataTip, '=');
        if (pszEqual == NULL)
        {
            // No equal sign -- default to the DEBUGGER tip, not the quick info tip...
            wcsncpy(pwsz, bstrDebugDataTip, bufferSize-1);
        }
        else
        {
            if (pszEqual[1] == ' ')
            wcscat(pwsz, L" ");
            wcscat(pwsz, pszEqual);
        }
    }

    BSTR bstrDataTip = ::SysAllocString(pwsz);

    bstrFree(bstrDebugDataTip);
    if (pwsz) 
        delete[] pwsz;

    if (0==SysStringLen(bstrDataTip)) 
    { 
        bstrFree(bstrDataTip); 
        return E_FAIL;
    }

    *pbstrFullText = bstrDataTip;
    return S_OK;
}



CTextTipData* ViewFilter::GetTextTipData()
{
    if (m_pTextTipData != NULL)
       return m_pTextTipData;

    // create it 
    m_pTextTipData = new CTextTipData();
    if (!m_pTextTipData) 
        return NULL;

    IServiceProvider* pIServiceProvider = m_lservice->GetIServiceProvider();// un-addref

    HRESULT hr = m_pTextTipData->Init(pIServiceProvider, m_textView);
    if (FAILED(hr) )
    {
        delete m_pTextTipData;
        m_pTextTipData = NULL;
        return NULL;
    }

    m_pTextTipData->AddRef();

    return m_pTextTipData;
}
