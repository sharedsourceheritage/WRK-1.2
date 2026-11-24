/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include "vsmem.h"

#include "dllmain.h"    //for g_typeInfoColorSink
#include "source.h"     //for CharInfo
#include "colorizer.h"

/*---------------------------------------------------------
  Colorizer 
-----------------------------------------------------------*/
Colorizer::Colorizer( in IBabelService* babelService )
{
  TRACE_CREATE( "Colorizer", static_cast<IVsColorizer*>(this) );
  ASSERT( babelService );

  m_refCount        = 1;
  m_babelService    = babelService;     ADDREF(m_babelService);

  m_line            = -1;
  m_lineAttributes  = NULL;
  m_lineLen         = 0;

  m_lineCached      = -1;
  m_lineCachedLen   = 0;
  m_lineCachedInfo  = NULL;
}


Colorizer::~Colorizer()
{
  TRACE_DESTROY( static_cast<IVsColorizer*>(this) );
  FREE(m_lineCachedInfo);
  RELEASE(m_babelService);
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Colorizer::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsColorizer)
  {
    TRACE("Colorizer::QueryInterface for IUnknown/IVsColorizer");
    *obj = static_cast<IVsColorizer*>(this);
  }
  else if (iid == IID_IDispatch)
  {
    TRACE("Colorizer::QueryInterface for IDispatch");
    *obj = static_cast<IDispatch*>(this);
  }
  else if (iid == IID_IColorSink)
  {
    TRACE("Colorizer::QueryInterface for IColorSink");
    *obj = static_cast<IColorSink*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Colorizer::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Colorizer::Release()
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
  implement IDispatch (for IColorSink only)
-----------------------------------------------------------*/
STDMETHODIMP Colorizer::GetTypeInfoCount( out UINT* count )
{
  OUTARG(count);

  if (g_typeInfoColorSink) *count = 1;
                      else *count = 0;
  return S_OK;
}

STDMETHODIMP Colorizer::GetTypeInfo( in UINT index, in LCID lcid, out ITypeInfo** typeInfo )
{
  OUTARG(typeInfo);
  if (index != 0) return E_INVALIDARG;
  if (!g_typeInfoColorSink) return TYPE_E_CANTLOADLIBRARY;

  *typeInfo = g_typeInfoColorSink;
  return S_OK;
}

STDMETHODIMP Colorizer::GetIDsOfNames( in REFIID iid, in OLECHAR** names, in UINT count, 
                                       in LCID lcid, out DISPID* dispids )
{
  if (!g_typeInfoColorSink) return TYPE_E_CANTLOADLIBRARY;
  return g_typeInfoColorSink->GetIDsOfNames( names, count, dispids );
}

STDMETHODIMP Colorizer::Invoke( in DISPID dispid, in REFIID iid, in LCID lcid, 
                                in WORD flags, in DISPPARAMS* args, 
                                out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg )
{
  if (!g_typeInfoColorSink) return TYPE_E_CANTLOADLIBRARY;  
  return g_typeInfoColorSink->Invoke( static_cast<IColorSink*>(this), 
                                      dispid, flags, args, result, error, errorArg );
}
  

/*---------------------------------------------------------
  IVsColorizer
-----------------------------------------------------------*/
STDMETHODIMP Colorizer::GetStateMaintenanceFlag( out BOOL* useState )
{
  OUTARG(useState);
  *useState = true;
  return S_OK;
}

STDMETHODIMP Colorizer::GetStartState( out long* startState )
{
 // TRACE("Colorizer::GetStartState");
  OUTARG(startState);
  *startState = 0;
  return S_OK;
}

STDMETHODIMP_(long) Colorizer::ColorizeLine( 
                                  in long         line,
				                  in long         length,
				                  in const WCHAR* text,
				                  in long         state,
				                  in ULONG*       attributes )
{
  if (!text) return state;
  if (!m_babelService) return 0;  //can happen after "save as"
  BSTR bstrText = SysAllocStringLen(text, length+1);
  if (!bstrText) return state;
  
  //set current line info
  m_lineLen        = length+1;       //count eol character as one
  m_line           = line;          
  m_lineAttributes = attributes;
  if (m_lineAttributes)
  {
    memset( m_lineAttributes, 0, m_lineLen*sizeof(ULONG) );
  }
  
  //set up cached line info
  if (m_line == m_lineCached)
  {
    m_lineCachedLen = m_lineLen;
    FREE(m_lineCachedInfo);
    m_lineCachedInfo = NALLOC( CharInfo, m_lineCachedLen );
    if (m_lineCachedInfo) memset( m_lineCachedInfo, 0, m_lineCachedLen*sizeof(CharInfo) );
  }

  //marshall parameters to the babel service
  bstrText[m_lineLen-1] = L'\n';

  IColorSink*  sink;
  if (m_lineAttributes || (m_lineCached == m_line))
    sink = static_cast<IColorSink*>(this);
  else
    sink = NULL;

  m_babelService->ColorLine( bstrText, sink, &state );
  bstrFree(bstrText);

  return state;  //return new state
}


STDMETHODIMP_(long) Colorizer::GetStateAtEndOfLine( 
                                         in long         line,
					                     in long         length,
					                     in const WCHAR* text,
					                     in long         state )
{
  return ColorizeLine( line, length, text, state, NULL );
}

STDMETHODIMP_(void) Colorizer::CloseColorizer( void )
{
  TRACE("Colorizer::CloseColorizer");

  FREE(m_lineCachedInfo);
  RELEASE(m_babelService);
  return;
}

/*---------------------------------------------------------
  IColorSink callback
-----------------------------------------------------------*/
STDMETHODIMP Colorizer::Colorize(  in long          startIdx, 
                                   in long          endIdx, 
                                   in ColorClass    colorClass,
                                   in CharClass     charClass, 
                                   in TriggerClass  triggerClass )
{
  //color attributes
  if (m_lineAttributes)
  {
   if (endIdx >= m_lineLen) endIdx   = m_lineLen-1;
   if (startIdx < 0)        startIdx = 0;

   for (long i = startIdx; i <= endIdx; i++)
     m_lineAttributes[i] = colorClass;
  }

  //character information
  if ((m_lineCached == m_line) && m_lineCachedInfo)
  {
   if (endIdx >= m_lineCachedLen) endIdx   = m_lineCachedLen -1;
   if (startIdx < 0)              startIdx = 0;

   for (long i = startIdx; i <= endIdx; i++)
   {
     m_lineCachedInfo[i].charClass    = charClass;
     m_lineCachedInfo[i].triggerClass = triggerClass;
   }
  
   if (startIdx <= endIdx)
     m_lineCachedInfo[startIdx].newToken = true;
  }

  return S_OK;
}


/*---------------------------------------------------------
  LineInfo; used internally for fast info about tokens on a line
-----------------------------------------------------------*/
STDMETHODIMP Colorizer::SetCachedLine( in long line )
{
  if (line != m_lineCached) 
  {
    m_lineCached = line;
    FREE(m_lineCachedInfo);
    m_lineCachedInfo = NULL;
    m_lineCachedLen  = 0;
  }

  return S_OK;
}

STDMETHODIMP Colorizer::GetLineInfo(  in  long               line, 
                                      in  IVsTextColorState* colorState,
                                      out const CharInfo**   lineInfo, 
                                      out unsigned*          length )
{
  OUTARG(length);
  OUTARG(lineInfo);
  REFARG(colorState);

  //hopefully, the line is in the cache
  if ((line == m_lineCached) && m_lineCachedInfo)
  {
    //TRACE("Colorizer::GetLineInfo: line in cache");
    *lineInfo = m_lineCachedInfo;
    *length   = m_lineCachedLen;
    return S_OK;
  }
  else
  {
    //TRACE("Colorizer::GetLineInfo: recolorize line");
  }

  //otherwise we have to recolorize the line
  SetCachedLine(line);

  //call ColorizeLine indirectly
  HRESULT hr = colorState->ReColorizeLines( line, line );
  if (FAILED(hr)) return hr;

  //now it should be in the cache
  if ((line != m_lineCached) || (m_lineCachedInfo == NULL))
    return E_FAIL;

  *lineInfo = m_lineCachedInfo;
  *length   = m_lineCachedLen;
  return S_OK;
}

STDMETHODIMP Colorizer::GetLineInfoText( in const WCHAR*      text, 
                                         in long              textLen,
                                         inout long*          state,
                                         out const CharInfo** lineInfo, 
                                         out unsigned*        length )
{
  OUTARG(length);
  OUTARG(lineInfo);
  INOUTARG(state);
  long line = -1;

  SetCachedLine( line );
  *state = ColorizeLine( line, textLen-1, text, *state, NULL );
  
  //now it should be in the cache
  if ((line != m_lineCached) || (m_lineCachedInfo == NULL))
    return E_FAIL;

  *lineInfo = m_lineCachedInfo;
  *length   = m_lineCachedLen;
  return S_OK;
}
