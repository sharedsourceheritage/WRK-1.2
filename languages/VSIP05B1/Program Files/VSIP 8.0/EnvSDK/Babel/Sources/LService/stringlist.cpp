/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "linespan.h"
#include "stringlist.h"
#include "vsmem.h"

/*---------------------------------------------------------
  StringList 
-----------------------------------------------------------*/
StringList::StringList()
{
  TRACE_CREATE_HIDE( "StringList", static_cast<IUnknown*>(this) );
  m_refCount = 1;

  m_strings  = NULL;
  m_count    = 0;
  m_current  = 0;
}


StringList::~StringList()
{
  if (m_strings)
  {
    for (ULONG i = 0; i < m_count; i++)
    {
      bstrFree( m_strings[i] );
    }
    FREE(m_strings);
    m_count = 0;
    m_current = 0;
  }

  TRACE_DESTROY( static_cast<IUnknown*>(this) );
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP StringList::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsEnumBSTR)
  {
    TRACE("StringList::QueryInterface for IUnknown/IVsEnumBSTR");
    *obj = static_cast<IVsEnumBSTR*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) StringList::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) StringList::Release()
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
  Init
-----------------------------------------------------------*/
STDMETHODIMP StringList::Init( in IVsTextLines* textLines,
                               in LineSpanList* spans )
{
  INARG(spans);
  INARG(textLines);
  ASSERT(m_strings == NULL);

  ULONG count = spans->GetCount();
  m_count   = 0;
  m_strings = NALLOC( BSTR, count );
  if (!m_strings) return E_OUTOFMEMORY;
  
  for (ULONG i = 0; i < count; i++)
  {
    HRESULT  hr;    
    TextSpan span;

    hr = spans->Get( i, &span );
    if (FAILED(hr)) return hr;

    BSTR text = NULL;
    hr = textLines->GetLineText( span.iStartLine, span.iStartIndex,
                                 span.iEndLine, span.iEndIndex, 
                                 &text );
    if (FAILED(hr)) return hr; 
    
    //only add if not a duplicate
    for( ULONG j = 0; j < m_count; j++)
    {
        if (strCompare( m_strings[j], text ) == 0)
        {
            //duplicate
            bstrFree(text);
            break;
        }
    }
    if ( ::SysStringLen(text) > 0 )
    {
        m_strings[m_count] = text;
        m_count++;
    }


  }

  return S_OK;
}


/*---------------------------------------------------------
  IVsEnumBSTR
-----------------------------------------------------------*/
STDMETHODIMP StringList::Next( in  ULONG count, 
                               out BSTR* elements, 
                               out ULONG* fetched )
{
  OUTARG(elements);
  ULONG _fetched = 0;
  if (!fetched) fetched = &_fetched;

  *fetched = 0;
  ULONG i = 0;
  while (i < count && m_current < m_count) 
  {
     elements[i] = SysAllocString( m_strings[m_current] );
     m_current++;
     i++;
  }
  *fetched = i;

  if (*fetched == count) return S_OK;
                    else return S_FALSE;
}

STDMETHODIMP StringList::Skip( in ULONG count )
{
  ULONG i = 0;
  while (i < count && m_current < m_count)
  {
    i++;
    m_current++;
  }

  if (i == count) return S_OK; 
             else return S_FALSE;
}

STDMETHODIMP StringList::Reset( void )
{
  m_current = 0;
  return S_OK;
}

STDMETHODIMP StringList::Clone( out IVsEnumBSTR** enumBstr )
{
  OUTARG(enumBstr);
  
  StringList* strings = new StringList();
  if (!strings) return E_OUTOFMEMORY;
  
  strings->m_count   = 0;
  strings->m_current = m_current;
  strings->m_strings = NALLOC( BSTR, m_count );
  if (!strings->m_strings) 
  {
    RELEASE(strings);
    return E_OUTOFMEMORY;
  }

  for (ULONG i = 0; i < m_count; i++)
  {
      strings->m_strings[i] = SysAllocString( m_strings[i] );
    if (strings->m_strings[i] == NULL)
    {
      RELEASE(strings);
      return E_OUTOFMEMORY;
    }

    strings->m_count++;
  }

  *enumBstr = strings;
  return S_OK;
}

STDMETHODIMP StringList::GetCount( out ULONG* count )
{
  OUTARG(count);
  *count = m_count;
  return S_OK;
}
