/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  EcmaService 
-----------------------------------------------------------*/
EcmaService::EcmaService( in ITypeInfo* typeInfo )
{
  TRACE1("create EcmaService: 0x%x", this);
  m_refCount = 1;
  m_typeInfo = typeInfo;
  ADDREF(m_typeInfo);

  m_colorizer = NULL;
  m_parser    = NULL;
  m_parseSink = NULL;
}


EcmaService::~EcmaService()
{
  TRACE1("destroy EcmaService: 0x%x", this);
  Done();
  RELEASE(m_typeInfo);
}



HRESULT EcmaService::Init()
{
  HRESULT hr;

  IAuthorServices* author;
  hr = ::CoCreateInstance( __uuidof(JSAuthor), NULL, CLSCTX_INPROC_SERVER,
                           __uuidof(IAuthorServices), reinterpret_cast<void**>(&author));
  if (FAILED(hr)) return hr;

  if (!m_colorizer)
  {
    hr = author->GetColorizer( &m_colorizer );
    if (FAILED(hr)) { RELEASE(author); return hr; }
  }

  if (!m_parser)
  {
    hr = author->GetCodeSense( &m_parser );
    if (FAILED(hr)) { RELEASE(author); return hr; }
  }

  RELEASE(author);
  return S_OK;
}

HRESULT EcmaService::Done()
{
  RELEASE(m_parser);
  RELEASE(m_colorizer);
  return S_OK;
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP EcmaService::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IDispatch || iid == IID_IBabelService )
  {
    TRACE("EcmaService::QueryInterface for IUnknown/IDispatch/IBabelService");
    *obj = static_cast<IBabelService*>(this);
  }
  else if (iid == __uuidof(IErrorHandler) )
  {
    TRACE("EcmaService::QueryInterface for IErrorHandler");
    *obj = static_cast<IErrorHandler*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) EcmaService::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) EcmaService::Release()
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
  IDispatch
-----------------------------------------------------------*/
STDMETHODIMP EcmaService::GetTypeInfoCount( UINT * count )
{
    if (count) *count = 1;
    return S_OK;
}

STDMETHODIMP EcmaService::GetTypeInfo( UINT i, LCID lcid, ITypeInfo **tinfo )
{
    if (i != 0)  return TYPE_E_ELEMENTNOTFOUND;
    OUTARG(tinfo);
    if (!m_typeInfo) return TYPE_E_CANTLOADLIBRARY;

    *tinfo = m_typeInfo;
    (*tinfo)->AddRef();
    return S_OK;
}

STDMETHODIMP EcmaService::GetIDsOfNames( REFIID iid, OLECHAR **names, 
					                     UINT count, LCID lcid, DISPID *dispids)
{
    if (iid != IID_NULL) return DISP_E_UNKNOWNINTERFACE;
    if (!m_typeInfo) return TYPE_E_CANTLOADLIBRARY;

    return m_typeInfo->GetIDsOfNames( names, count, dispids );
}


STDMETHODIMP EcmaService::Invoke( DISPID dispid, REFIID iid, LCID lcid, 
				                  WORD flags, DISPPARAMS * dp, 
				                  VARIANT *res, EXCEPINFO * ex, UINT * err)
{
    if (iid != IID_NULL) return DISP_E_UNKNOWNINTERFACE;
    if (!m_typeInfo) return TYPE_E_CANTLOADLIBRARY;
    
    return m_typeInfo->Invoke( static_cast<IBabelService*>(this), dispid, flags, dp, res, ex, err );
}


/*---------------------------------------------------------
  IBabelService
-----------------------------------------------------------*/
STDMETHODIMP EcmaService::ColorCount( out ColorClass* count )
{
  TRACE( "EcmaService::ColorCount" );
  OUTARG(count);
  *count = 6;
  return S_OK;
}

STDMETHODIMP EcmaService::GetColorInfo( in  ColorClass index, 
                                        out BSTR*      description,
                                        out BSTR*      style )
{
  TRACE1( "EcmaService::GetColorInfo %i", index );
  OUTARG(style);
  OUTARG(description);
  return E_NOTIMPL;
}

STDMETHODIMP EcmaService::ColorLine( in    BSTR          line, 
                                     in    IColorSink*   sink,
                                     inout long* state )
{
  TRACE2( "EcmaService::ColorLine: %i %S", *state, line );
  INOUTARG(state);
  if (!m_colorizer) return E_FAIL;
  HRESULT hr;

  if (sink)
  { 
    int lineLen = SysStringLen(line);

    //get tokens
    ITokenEnumerator* tokenEnum;
    hr = m_colorizer->Colorize( line, (SourceState)(*state), &tokenEnum );
    if (FAILED(hr)) return hr;

    //colorize tokens
    ColorClass color      = ClassDefault;
    CharClass  charClass  = CharDefault;
    long start = 0;
    long end   = 0;
    ITokenColorInfo* colorInfo = NULL;
    while (SUCCEEDED(tokenEnum->GetNext(&colorInfo)) && colorInfo)
    {
      colorInfo->get_StartPosition(&start); 

      //fill out empty space
      if (start > end) 
        sink->Colorize( end, start, ClassDefault, CharWhiteSpace, TriggerNone );

      colorInfo->get_EndPosition(&end);
      colorInfo->get_Color(reinterpret_cast<TokenColor*>(&color) );
      switch (color)
      {
      case TokenColor_COLOR_TEXT:       color = ClassText;        charClass = CharText;       break;
      case TokenColor_COLOR_IDENTIFIER: color = ClassIdentifier;  charClass = CharIdentifier; break;
      case TokenColor_COLOR_KEYWORD:    color = ClassKeyword;     charClass = CharKeyword;    break;
      case TokenColor_COLOR_COMMENT:    color = ClassComment;     charClass = CharComment;    break;
      case TokenColor_COLOR_OPERATOR:   color = ClassText;        charClass = CharOperator;   break;
      case TokenColor_COLOR_NUMBER:     color = ClassNumber;      charClass = CharLiteral;    break;
      case TokenColor_COLOR_STRING:     color = ClassString;      charClass = CharString;     break;
      case TokenColor_COLOR_CONDITIONAL_COMP: color = ClassText;  charClass = CharEmbedded;   break;
      default:
        ASSERT(0);
        color     = ClassDefault;
        charClass = CharDefault;
        break;
      }
      
      sink->Colorize( start, end, color, charClass, TriggerNone );
      RELEASE(colorInfo);
    }

    
    //next state
    //m_colorizer->GetStateForText( line, (SourceState)(*state), reinterpret_cast<SourceState*>(state) );
    m_colorizer->GetStateForText( NULL, (SourceState)0, reinterpret_cast<SourceState*>(state) );
    TRACE1( "EcmaService::ColorLine:next state: %i", *state );
  
    //fill the tail of the line
    if (end < lineLen)
    {
      switch (*state)
      {
      case SourceState_STATE_COLOR_COMMENT: color = ClassComment; charClass = CharComment; break;
      case SourceState_STATE_COLOR_STRING:  color = ClassString;  charClass = CharString;  break;
      default:                              color = ClassDefault; charClass = CharDefault; break;
      }

      sink->Colorize( end, lineLen, color, charClass, TriggerNone );
    }
  }
  else
  {
    //next state
    m_colorizer->GetStateForText( line, (SourceState)(*state), reinterpret_cast<SourceState*>(state) );
  }


  return S_OK;
}

STDMETHODIMP EcmaService::ParseSource( in  BSTR             text, 
                                       in  IParseSink*      sink,
                                       in  enum ParseReason reason,
                                       out IScope**         scope )
{
  TRACE( "EcmaService::ParseSource" );
  if (scope) *scope = NULL;
  if (!m_parser) return E_FAIL;

  m_reason = reason;
  {
    HRESULT hr;
    m_parseSink = sink;
    hr = m_parser->Parse( text, static_cast<IErrorHandler*>(this) );
    m_parseSink = NULL;
    ASSERT(SUCCEEDED(hr)); if (FAILED(hr)) return hr;
  }

  return S_OK;
}


STDMETHODIMP EcmaService::GetMethodFormat( out BSTR*         parStart,
                                           out BSTR*         parSep, 
                                           out BSTR*         parEnd,
                                           out BSTR*         typeStart, 
                                           out BSTR*         typeEnd,
                                           out VARIANT_BOOL* typePrefixed )
{
  TRACE( "EcmaService::GetMethodFormat" );
  OUTARG(typePrefixed);
  OUTARG(typeEnd);
  OUTARG(typeStart);
  OUTARG(parEnd);
  OUTARG(parSep);
  OUTARG(parStart);

  return E_NOTIMPL;
}

STDMETHODIMP EcmaService::GetCommentFormat( out BSTR*         lineStart, 
                                            out BSTR*         blockStart,
                                            out BSTR*         blockEnd,
                                            out VARIANT_BOOL* useLineComments )
{
  TRACE( "EcmaService::GetCommentFormat" );
  OUTARG(useLineComments);
  OUTARG(blockEnd);
  OUTARG(blockStart);
  OUTARG(lineStart);

  return E_NOTIMPL;
}

STDMETHODIMP EcmaService::GetImageList( out long* imageListHandle )
{
  OUTARG(imageListHandle);
  return E_NOTIMPL;
}

/*---------------------------------------------------------
  IErrorHandler
-----------------------------------------------------------*/
STDMETHODIMP EcmaService::OnCompilerError( in IVsaFullErrorInfo* fullError, out VARIANT_BOOL* abort )
{
  OUTARG(abort); *abort = 1;
  REFARG(fullError);
  if (m_reason != ReasonCheck) return S_OK;
  ASSERT(m_parseSink); if (!m_parseSink) return E_FAIL;

  HRESULT hr;
  IVsaError* error;
  hr = fullError->QueryInterface( __uuidof(IVsaError), reinterpret_cast<void**>(&error) );
  if (FAILED(hr)) return hr;

  BSTR message = NULL;
  long  startLine, startIdx, endLine, endIdx;
  
  error->get_Description( &message );
  error->get_Line( &startLine );
  error->get_Column( &startIdx ); 
  fullError->get_EndLine( &endLine );
  fullError->get_EndColumn( &endIdx ); 
  startLine--;
  startIdx--;
  endLine--;
  endIdx--;
  m_parseSink->ErrorMessage( startLine, endLine,
                             startIdx,  endIdx,
                             SevError, message );
//  FREEBSTR(message);
  RELEASE(error);
  return S_OK;
}

