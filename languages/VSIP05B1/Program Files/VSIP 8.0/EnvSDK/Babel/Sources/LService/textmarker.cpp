/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "textmarker.h"

/*---------------------------------------------------------
  TextMarkerClient
-----------------------------------------------------------*/
class TextMarkerClient : public IVsTextMarkerClient
{
private:
  ULONG             m_refCount;
  BSTR              m_tipText;

public:
  TextMarkerClient( in BSTR tipText );
  ~TextMarkerClient();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IVsTextMarkerClient
  STDMETHODIMP_(void) MarkerInvalidated( void );
  STDMETHODIMP_(void) OnBufferSave( in const wchar_t* fileName );
  STDMETHODIMP_(void) OnBeforeBufferClose( void );
  STDMETHODIMP_(void) OnAfterSpanReload( void );

  STDMETHODIMP OnAfterMarkerChange( in IVsTextMarker* marker);
  STDMETHODIMP GetTipText(in IVsTextMarker* marker, out BSTR* tipText );
  
  STDMETHODIMP GetMarkerCommandInfo( in  IVsTextMarker* marker, 
                                     in  long           item, 
                                     out BSTR*          text, 
                                     out DWORD*         commandFlags );
  STDMETHODIMP ExecMarkerCommand( in IVsTextMarker* marker, in long item );
};


/*---------------------------------------------------------
  CreateMarker
-----------------------------------------------------------*/
HRESULT CreateMarker( in  IVsTextLines* textLines,
                      in  TextSpan&     span,
                      in  BSTR          tipText,
                      in  MARKERTYPE    markerType,
                      out IVsTextLineMarker** textLineMarker )
{
  //TRACE("CreateMarker");
  REFARG(textLines);
  if (textLineMarker) *textLineMarker = NULL;
  HRESULT hr;

  TextMarkerClient* textMarkerClient = new TextMarkerClient( tipText );
  if (!textMarkerClient) return E_OUTOFMEMORY;

  hr = textLines->CreateLineMarker( 
            markerType,
            span.iStartLine, span.iStartIndex, 
            span.iEndLine,   span.iEndIndex,
            static_cast<IVsTextMarkerClient*>(textMarkerClient), textLineMarker );
  RELEASE(textMarkerClient);
  if (FAILED(hr)) return hr;

  return S_OK;
}


/*---------------------------------------------------------
  TextMarkerClient 
-----------------------------------------------------------*/
TextMarkerClient::TextMarkerClient( in BSTR tipText )
{
  TRACE_CREATE_HIDE( "TextMarkerClient", static_cast<IVsTextMarkerClient*>(this) );
  m_refCount  = 1;
  m_tipText   = SysAllocString(tipText);
}


TextMarkerClient::~TextMarkerClient()
{
  TRACE_DESTROY( static_cast<IVsTextMarkerClient*>(this) );
  bstrFree(m_tipText);
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP TextMarkerClient::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsTextMarkerClient)
  {
    TRACE("TextMarkerClient::QueryInterface for IUnknown/IVsTextMarkerClient");
    *obj = static_cast<IVsTextMarkerClient*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) TextMarkerClient::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) TextMarkerClient::Release()
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
  IVsTextMarkerClient
-----------------------------------------------------------*/
STDMETHODIMP_(void) TextMarkerClient::MarkerInvalidated( void )
{
  //TRACE("TextMarkerClient::MarkerInvalidated" );
  return;
}

STDMETHODIMP_(void) TextMarkerClient::OnBufferSave( in const wchar_t* fileName )
{
  //TRACE1("TextMarkerClient::OnBufferSave: %S", fileName );
  return;
}

STDMETHODIMP_(void) TextMarkerClient::OnBeforeBufferClose( void )
{
  //TRACE("TextMarkerClient::OnBeforeBufferClose" );
  return;
}

STDMETHODIMP_(void) TextMarkerClient::OnAfterSpanReload( void )
{
  //TRACE("TextMarkerClient::OnAfterSpanReload" );
  return;
}

STDMETHODIMP TextMarkerClient::OnAfterMarkerChange( in IVsTextMarker* marker)
{
  //TRACE("TextMarkerClient::OnAfterMarkerChange" );
  return S_OK;
}

STDMETHODIMP TextMarkerClient::GetTipText(in IVsTextMarker* marker, out BSTR* tipText )
{
  TRACE("TextMarkerClient::GetTipText" );
  OUTARG(tipText);
  REFARG(marker);

  *tipText = SysAllocString(m_tipText);
  return S_OK;
}

STDMETHODIMP TextMarkerClient::GetMarkerCommandInfo( 
                                   in  IVsTextMarker* marker, 
                                   in  long           item, 
                                   out BSTR*          text, 
                                   out DWORD*         commandFlags )
{
  TRACE1("TextMarkerClient::GetMarkerCommandInfo: %i", item );
  OUTARG(commandFlags);
  OUTARG(text);
  REFARG(marker);

  *text = SysAllocString(m_tipText);
  return S_OK;
}

STDMETHODIMP TextMarkerClient::ExecMarkerCommand( in IVsTextMarker* marker, in long item )
{
  TRACE1("TextMarkerClient::ExecMarkerCommand: %i", item );
  REFARG(marker);

  return S_OK;
}
