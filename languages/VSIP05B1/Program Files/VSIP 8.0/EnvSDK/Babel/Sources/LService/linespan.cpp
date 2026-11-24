/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "linespan.h"
#include "names.h"

/*---------------------------------------------------------
  LineSpanList 
-----------------------------------------------------------*/
LineSpanList::LineSpanList()
{
  TRACE_CREATE_HIDE( "LineSpanList", static_cast<IUnknown*>(this) );
  m_refCount = 1;
  m_count    = 0;
}


LineSpanList::~LineSpanList()
{
  TRACE_DESTROY( static_cast<IUnknown*>(this) );
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP LineSpanList::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("LineSpanList::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) LineSpanList::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) LineSpanList::Release()
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
  LineSpanList
-----------------------------------------------------------*/
void LineSpanList::Clear()
{
  m_count = 0;
}

unsigned LineSpanList::GetCount()
{
  return m_count;
}

HRESULT LineSpanList::PushBack( in const TextSpan& textSpan )
{
  ASSERT( textSpan.iStartLine == textSpan.iEndLine );
  //if (textSpan.iStartLine != textSpan.iEndLine) return E_INVALIDARG;
  ASSERT(m_count < MaxLineSpans);
  if (m_count >= MaxLineSpans) return E_FAIL;

  m_list[m_count].startLine = textSpan.iStartLine;
  m_list[m_count].startIdx  = textSpan.iStartIndex;
  m_list[m_count].endIdx    = textSpan.iEndIndex;
  m_count += 1;
  return S_OK;
}

HRESULT LineSpanList::MergeTop( in const TextSpan& textSpan )
{
  ASSERT( textSpan.iStartLine == textSpan.iEndLine );
  //if (textSpan.iStartLine != textSpan.iEndLine) return E_INVALIDARG;
  ASSERT(m_count < MaxLineSpans);
  if (m_count >= MaxLineSpans) return E_FAIL;
  if (m_count == 0) return PushBack( textSpan );

  //get
  TextSpan topSpan;
  Get( m_count-1, &topSpan );

  //merge
  TextSpan newSpan;
  TextSpanMerge( textSpan, topSpan, &newSpan );

  //push new
  return PushBack( newSpan );
}

HRESULT LineSpanList::Get( in unsigned index, out TextSpan* textSpan )
{
  REFARG(textSpan);
  if (index >= m_count) return E_INVALIDARG;

  textSpan->iStartLine  = textSpan->iEndLine = m_list[index].startLine;
  textSpan->iStartIndex = m_list[index].startIdx; 
  textSpan->iEndIndex   = m_list[index].endIdx;
  return S_OK;
}

HRESULT LineSpanList::GetNames( in IVsTextLines* textLines, out INames** inames )
{
  OUTARG(inames);
  REFARG(textLines);
  HRESULT hr;

//the spans are a sequence of "name selector" pairs. 
//the last selector might be lacking.
  Names* names = new Names();
  if (!names) return E_OUTOFMEMORY;
  
  unsigned count = (GetCount()+1)/2;
  hr = names->Init( count );
  if (FAILED(hr)) { RELEASE(names); return hr; }

  unsigned index = 0;
  while (index < m_count)
  {
    BSTR textName;
    hr = textLines->GetLineText( m_list[index].startLine, m_list[index].startIdx,
                                 m_list[index].startLine, m_list[index].endIdx, &textName );
    if (FAILED(hr)) { RELEASE(names); return hr; }


    BSTR textSelect = NULL;
    if (index+1 < m_count)
    {
      hr = textLines->GetLineText( m_list[index+1].startLine, m_list[index+1].startIdx,
                                   m_list[index+1].startLine, m_list[index+1].endIdx, &textSelect );
      if (FAILED(hr)) { bstrFree(textName); RELEASE(names); return hr; }
    }    

    TRACE2( "LineSpanList::GetNames %S(%S)", textName, textSelect );

    names->InsertNoDup( textName, textSelect );
    index = index + 2;
  }
  
  *inames = static_cast<INames*>(names);
  return S_OK;
}
