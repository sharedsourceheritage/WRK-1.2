/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "resource.h"       //for IDB_COMPLETION_SET
#include "dllmain.h"        //for g_instance
#include "completionset.h"
#include "source.h"         //for IsCommitChar

/*---------------------------------------------------------
  CompletionSet 
-----------------------------------------------------------*/
CompletionSet::CompletionSet( in HANDLE imageList, in long glyphCount, in Source* source )
{
  TRACE_CREATE( "CompletionSet", static_cast<IVsCompletionSet*>(this) );
  ASSERT(source);

  m_refCount      = 1;
  m_imageList     = imageList;
  m_glyphCount    = glyphCount;
  m_source        = source;     ADDREF(source);

  m_textView      = NULL;
  m_decls         = NULL;
  m_displayed     = false;
  m_completeWord  = false;
}


CompletionSet::~CompletionSet()
{
  TRACE_DESTROY( static_cast<IVsCompletionSet*>(this) );
  Done();
  RELEASE(m_source);
}


STDMETHODIMP CompletionSet::Init( in IVsTextView* textView, in IDeclarations* decls, in bool completeWord )
{
//  TRACE("CompletionSet::Init");
  REFARG(textView);
  REFARG(decls);
  HRESULT hr;
  
  Done();
  
  ASSERT(!m_displayed);       m_displayed = false;
  ASSERT(m_textView == NULL); RELEASE(m_textView);
  ASSERT(m_decls == NULL);    RELEASE(m_decls);

  //check if we have members
  long count = 0;
  hr = decls->GetCount( &count );
  if (FAILED(hr)) return hr;
  if (count <= 0) return S_FALSE;

  //initialise and refresh
  m_decls        = decls;    ADDREF(m_decls);
  m_textView     = textView; ADDREF(m_textView);  
  m_completeWord = completeWord;

  DWORD flags = UCS_NAMESCHANGED;
  if (m_completeWord) flags |= UCS_COMPLETEWORD;

  hr = m_textView->UpdateCompletionStatus( this, flags );
  if (FAILED(hr)) return hr;

  m_displayed = true;
  return S_OK;
}


STDMETHODIMP CompletionSet::Done()
{
//  TRACE("CompletionSet::Done");
  if (m_displayed && m_textView)
  {
    m_textView->UpdateCompletionStatus( NULL, 0 );
    ASSERT(!m_displayed);
  }

  m_displayed = false;
  RELEASE(m_textView);
  RELEASE(m_decls);
  return S_OK;
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP CompletionSet::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsCompletionSet)
  {
    TRACE("CompletionSet::QueryInterface for IUnknown/IVsCompletionSet");
    *obj = static_cast<IVsCompletionSet*>(this);
  } 
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) CompletionSet::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CompletionSet::Release()
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
  IVsCompletionSet
-----------------------------------------------------------*/
STDMETHODIMP_(DWORD) CompletionSet::GetFlags( void )
{
  DWORD flags = CSF_HAVEDESCRIPTIONS;

  if (m_source)  flags |= (CSF_CUSTOMCOMMIT | CSF_INITIALEXTENTKNOWN);

  if (m_decls)
  {
    HRESULT      hr;
    long         index;
    VARIANT_BOOL unique;
    hr = m_decls->GetBestMatch( NULL, &index, &unique );
    if (hr != E_NOTIMPL) flags |= CSF_CUSTOMMATCHING;
  }

  return flags;
}

STDMETHODIMP_(long)  CompletionSet::GetCount( void )
{
  //TRACE("CompletionSet::GetCount");
  if (!m_decls) return 0;

  HRESULT hr;
  long    count = 0;
  hr = m_decls->GetCount(&count );
  if (FAILED(hr)) return 0;

  return count;
}
  

STDMETHODIMP CompletionSet::GetImageList( out HANDLE* imageList )
{
  OUTARG(imageList);
  if (!m_imageList) return E_NOTIMPL;

  *imageList = m_imageList;
  return S_OK;
}

STDMETHODIMP CompletionSet::GetDisplayText( in long index, out const WCHAR** text, out long* glyph )
{
  OUTARG(text);
  if (glyph) *glyph = 0;
  ASSERT(m_decls); if (!m_decls) return E_UNEXPECTED;

  HRESULT hr;
  if (glyph) 
  {
    hr = m_decls->GetGlyph( index, glyph );
    if (*glyph >= m_glyphCount) *glyph = 0;
    if (FAILED(hr)) return hr;
  }

  BSTR bstrText;
  hr = m_decls->GetName( index, &bstrText );
  if (FAILED(hr)) return hr;
  *text = bstrText;
  
  return S_OK;
}

STDMETHODIMP CompletionSet::GetDescriptionText( in long index, out BSTR* description )
{
  OUTARG(description);
  ASSERT(m_decls); if (!m_decls) return E_UNEXPECTED;

  HRESULT hr;
  BSTR bstrDesc;
  hr = m_decls->GetDescription( index, &bstrDesc );
  if (FAILED(hr)) return hr;
  *description = ::SysAllocString(bstrDesc);

  return S_OK;
}



#ifdef VS6
STDMETHODIMP CompletionSet::GetInitialExtent( out long* line, 
                                              out long* startIdx, 
                                              out long* len )
{
  //TRACE("CompletionSet::GetInitialExtent");
  OUTARG(len);
  OUTARG(startIdx);
  OUTARG(line);
  ASSERT(m_textView); if (!m_textView) return E_UNEXPECTED;
  
  long idx;
  HRESULT hr = m_textView->GetCaretPos( line, &idx );
  *len = 0;
  *startIdx = idx;
  if (FAILED(hr)) return hr;

  long endIdx;
  hr = m_source->GetWordExtent( *line, idx, WORDEXT_CURRENT, startIdx, &endIdx );
  if (FAILED(hr)) return hr;
  if (hr == S_FALSE && idx > 0) 
  {
    hr = m_source->GetWordExtent( *line, idx-1, WORDEXT_CURRENT, startIdx, &endIdx );
    if (FAILED(hr)) return hr;
    if (hr == S_FALSE) { *startIdx = idx; return hr; }
  }
  *len = endIdx - *startIdx;

  return S_OK;
}
#else
STDMETHODIMP CompletionSet::GetInitialExtent( out long* line, out long* startIdx, out long* endIdx )
{
  //TRACE("CompletionSet::GetInitialExtent");
  OUTARG(endIdx);
  OUTARG(startIdx);
  OUTARG(line);
  ASSERT(m_textView); if (!m_textView) return E_UNEXPECTED;
  
  long idx;
  HRESULT hr = m_textView->GetCaretPos( line, &idx );
  *endIdx = *startIdx = idx;
  if (FAILED(hr)) return hr;

  hr = m_source->GetWordExtent( *line, idx, WORDEXT_CURRENT, startIdx, endIdx );
  if (FAILED(hr)) return hr;
  if (hr == S_FALSE && idx > 0) 
  {
    hr = m_source->GetWordExtent( *line, idx-1, WORDEXT_CURRENT, startIdx, endIdx );
    if (FAILED(hr)) return hr;
    if (hr == S_FALSE) { *endIdx = *startIdx = idx; return hr; }
  }
  
  return S_OK;
}
#endif

STDMETHODIMP CompletionSet::GetBestMatch( in const WCHAR *textSoFar, in long len, out long* index, out DWORD* flags )
{
  TRACE2( "CompletionSet::GetBestMatch: len=%i, text=%S", len, textSoFar );
  OUTARG( flags );
  OUTARG( index );

  VARIANT_BOOL uniqueMatch = false;
  BSTR         prefix      = NULL;   bstrCopy( prefix, textSoFar, len );
  HRESULT hr = m_decls->GetBestMatch( prefix, index, &uniqueMatch );
  bstrFree(prefix);
  if (FAILED(hr)) return hr;

  if (hr == S_OK)  *flags |= GBM_SELECT;
  if (uniqueMatch) *flags |= GBM_UNIQUE;

  return S_OK;
}
    
STDMETHODIMP_(void) CompletionSet::Dismiss()
{
//  TRACE("CompletionSet::Dismiss");
//  ASSERT(m_displayed);

  m_displayed = false;
  RELEASE(m_decls);
  RELEASE(m_textView);
}

STDMETHODIMP CompletionSet::OnCommit( in const WCHAR* textSoFar, in long index
					                , in BOOL selected, in WCHAR commitChar, out BSTR* completeWord )
{
  TRACE2("CompletionSet::OnCommit: %S, %c", textSoFar, commitChar );
  OUTARG(completeWord);
  REFARG(textSoFar);

  bool isCommitChar = false;
  if (m_source) isCommitChar = m_source->IsCommitChar( textSoFar, commitChar );
           else isCommitChar = (iswalnum(commitChar) == 0) || (commitChar == '_');
#ifdef VS6
  if (isCommitChar)
#else
  if (selected && isCommitChar)
#endif
  {
    HRESULT hr;
    const WCHAR* displayText;
    hr = GetDisplayText( index, &displayText, NULL );
    if (FAILED(hr)) return hr;

    *completeWord = SysAllocString(displayText);
    return S_OK;
  }
  else
  {
      *completeWord = SysAllocString( textSoFar );
    return S_FALSE;
  }
}
