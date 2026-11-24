/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include <fpstfmt.h>  //for IPersistFileFormat
#include <uilocale.h> //for IUILocale
#include "vscommon.h"


#ifdef VS6SDK
const IID IID_IPersistFileFormat 
  = { 0x3afae242, 0xb530, 0x11d0, { 0x81, 0x99, 0x0, 0xa0, 0xc9, 0x1b, 0xbe, 0xe3 }};
#endif
  

/*---------------------------------------------------------
  IServiceProvider
-----------------------------------------------------------*/
HRESULT ProviderCreateInstance( in IServiceProvider* provider,
                                in const CLSID& clsid, in const IID& iid, out void** obj )
{
  OUTARG(obj);
  REFARG(provider);
  HRESULT hr;

  ILocalRegistry* localRegistry = NULL;
  hr = provider->QueryService( SID_SLocalRegistry, IID_ILocalRegistry, reinterpret_cast<void**>(&localRegistry));
  if (FAILED(hr)) return hr;

  hr = localRegistry->CreateInstance( clsid, NULL, iid, CLSCTX_INPROC_SERVER, obj );
  RELEASE(localRegistry);
  if (FAILED(hr)) return hr;
  
  return S_OK;
}

HRESULT ProviderClearErrorInfo( in IServiceProvider* provider )
{
  return SetErrorInfo( S_OK, NULL );
}

HRESULT ProviderReportErrorInfo( in IServiceProvider* provider, in HRESULT hresult )
{
  if (SUCCEEDED(hresult)) return S_OK;
  REFARG(provider);

  HRESULT     hr;
  IVsUIShell* shell;

  hr = provider->QueryService( SID_SVsUIShell, IID_IVsUIShell, reinterpret_cast<void**>(&shell) );
  if (FAILED(hr)) return hr;

  hr = shell->ReportErrorInfo( hresult );
  RELEASE(shell);
  if (FAILED(hr)) return hr;

  return S_OK;
}

LCID ProviderGetLocale( in IServiceProvider* provider )
{
  LCID lcid = GetUserDefaultLCID();

  if (provider)
  {
    HRESULT hr = S_OK;
    IUIHostLocale* locale = NULL;
    hr = provider->QueryService( SID_SUIHostLocale, IID_IUIHostLocale, reinterpret_cast<void**>(&locale) );
    if (FAILED(hr)) return lcid;

    hr = locale->GetUILocale( &lcid );
    RELEASE(locale);
    if (FAILED(hr)) return lcid;
  }

  return lcid;
}


HRESULT ProviderGetHierarchy( in IServiceProvider* provider, in BSTR filePath, 
                              out IVsHierarchy** hierarchy, out VSITEMID* item )
{
  OUTARG(item);
  OUTARG(hierarchy);
  INARG(filePath);
  INARG(provider);
  HRESULT hr = S_OK;

  //get the running document table
  TRACE( "ProviderGetHierarchy: get the running doc table" );
  IVsRunningDocumentTable* docTable = NULL;
  hr = provider->QueryService( SID_SVsRunningDocumentTable, IID_IVsRunningDocumentTable, reinterpret_cast<void**>(&docTable) );
  if (FAILED(hr)) return hr;

  //get the hierarchy from the RDT
  TRACE1( "ProviderGetHierarchy: get document %S from the RDT", filePath );
  hr = docTable->FindAndLockDocument( 0 // RDT_ReadLock | RDT_DontAutoOpen
                                     , filePath
                                     , hierarchy
                                     , item
                                     , NULL
                                     , NULL
                                     );
  RELEASE(docTable);
  if (FAILED(hr)) return hr;
  TRACE( "ProviderGetHierarchy: found the document" );

  return S_OK;
}

/*---------------------------------------------------------
  TextSpan
-----------------------------------------------------------*/
bool TextSpanAfterAt( in const TextSpan& span1, in const TextSpan& span2 )
{
  return (span1.iStartLine > span2.iStartLine ||
          (span1.iStartLine == span2.iStartLine && span1.iStartIndex >= span2.iStartIndex));
}


bool TextSpanEndsBeforeAt( in const TextSpan& span1, in const TextSpan& span2 )
{
  return (span1.iEndLine < span2.iEndLine ||
          (span1.iEndLine == span2.iEndLine && span1.iEndIndex <= span2.iEndIndex));
}


void TextSpanMerge( in const TextSpan& span1, 
                    in const TextSpan& span2,
                    out TextSpan* span )
{
  ASSERT(span);
  if (TextSpanAfterAt(span1,span2))
  {
    span->iStartLine  = span2.iStartLine;
    span->iStartIndex = span2.iStartIndex;
  }
  else
  {
    span->iStartLine  = span1.iStartLine;
    span->iStartIndex = span1.iStartIndex;
  }
  
  if (TextSpanEndsBeforeAt(span1,span2))
  {
    span->iEndLine  = span2.iEndLine;
    span->iEndIndex = span2.iEndIndex;
  }
  else
  {
    span->iEndLine  = span1.iEndLine;
    span->iEndIndex = span1.iEndIndex;
  }
}

bool TextSpanPositive( in const TextSpan& span )
{
  return (span.iStartLine < span.iEndLine ||
          (span.iStartLine == span.iEndLine && span.iStartIndex <= span.iEndIndex));
}



void TextSpanEmpty( out TextSpan* span )
{
  span->iStartLine = span->iEndLine = -1;
  span->iStartIndex = span->iEndIndex = -1;
}

bool TextSpanIsEmpty( in const TextSpan& span )
{
  return (span.iStartLine < 0 || span.iEndLine < 0 || span.iStartIndex < 0 || span.iEndIndex < 0 );
}

void TextSpanMakePositive( inout TextSpan* span )
{
  ASSERT(span);
  if (!TextSpanPositive(*span))
  {
    long line;
    long idx;
    line = span->iStartLine;
    idx  = span->iStartIndex;
    span->iStartLine   = span->iEndLine;
    span->iStartIndex  = span->iEndIndex;
    span->iEndLine     = line;
    span->iEndIndex    = idx;
  }
  return;
}


void TextSpanNormalize( inout TextSpan* span, in IVsTextLines* textLines )
{
  ASSERT(span);
  TextSpanMakePositive( span );
  if (!textLines) return;

  HRESULT hr;

  //adjust max. lines
  long lineCount;
  hr = textLines->GetLineCount( &lineCount );
  if (FAILED(hr)) return;  
  span->iEndLine = min( span->iEndLine, lineCount-1 );
  
  //make sure the start is still before the end
  if (!TextSpanPositive(*span))
  {
    span->iStartLine  = span->iEndLine;
    span->iStartIndex = span->iEndIndex;
  }
  
  //adjust for line length
  long lineLength;
  hr = textLines->GetLengthOfLine( span->iStartLine, &lineLength );
  if (FAILED(hr)) return;
  span->iStartIndex = min( span->iStartIndex, lineLength );

  hr = textLines->GetLengthOfLine( span->iEndLine, &lineLength );
  if (FAILED(hr)) return;
  span->iEndIndex = min( span->iEndIndex, lineLength );

  return;
}



/*---------------------------------------------------------
  GetFilePath
-----------------------------------------------------------*/
STDMETHODIMP GetFilePath( in IVsTextBuffer* textLines, out BSTR* filePath )
{
  OUTARG(filePath);
  REFARG(textLines);
  HRESULT hr;

  IPersistFileFormat* fileFormat;
  hr = textLines->QueryInterface( IID_IPersistFileFormat, reinterpret_cast<void**>(&fileFormat) );
  if (FAILED(hr)) return hr;

  wchar_t* oleFileName;
  DWORD    format;
  hr = fileFormat->GetCurFile( &oleFileName, &format );
  RELEASE(fileFormat);
  if (FAILED(hr)) return hr;
  
  *filePath = SysAllocString(oleFileName);
  
  IMalloc* allocator = NULL;
  hr = CoGetMalloc(1,&allocator);
  ASSERT(SUCCEEDED(hr));
  if (SUCCEEDED(hr)) 
  {
    allocator->Free( oleFileName );
    RELEASE(allocator);
  }

  return S_OK;
}



/*---------------------------------------------------------
  OpenDocument
-----------------------------------------------------------*/
HRESULT WindowFrameGetTextView( in IVsWindowFrame* windowFrame, out IVsTextView** textView );

STDMETHODIMP OpenDocument( in IServiceProvider* provider,
                           in wchar_t*          docName,
                           out IVsUIHierarchy** _hierarchy,
                           out VSITEMID*        _itemID,
                           out IVsWindowFrame** _windowFrame,
                           out IVsTextView**    _textView
                         )
{
  REFARG(provider);  
  if (_textView)      *_textView    = NULL;
  if (_windowFrame)   *_windowFrame = NULL;
  if (_itemID)        *_itemID      = VSITEMID_NIL;
  if (_hierarchy)     *_hierarchy   = NULL;

  HRESULT hr;

  //open document
  IVsUIShellOpenDocument* shellOpenDoc  = NULL;
  hr = provider->QueryService( SID_SVsUIShellOpenDocument, IID_IVsUIShellOpenDocument, 
                               reinterpret_cast<void**>(&shellOpenDoc) );
  if (FAILED(hr)) return hr;

  IVsWindowFrame*  windowFrame = NULL;
  IVsUIHierarchy*  hierarchy   = NULL;
  VSITEMID         itemID      = VSITEMID_NIL;
  
  hr = shellOpenDoc->OpenDocumentViaProject(
            docName,
			LOGVIEWID_Primary,
            NULL,
            &hierarchy,
            &itemID,
			&windowFrame);
  RELEASE(shellOpenDoc);
  if (FAILED(hr)) return hr;

  
  //return objects
  if (_textView)
  {
    hr = WindowFrameGetTextView( windowFrame, _textView );
    if (FAILED(hr)) { RELEASE(windowFrame); RELEASE(hierarchy); return hr; }
  }
  
  if (_windowFrame) *_windowFrame = windowFrame;
               else RELEASE(windowFrame);
  if (_hierarchy)   *_hierarchy   = hierarchy;
               else RELEASE(hierarchy);
  if (_itemID)      *_itemID      = itemID;

  
  return S_OK;
}        



HRESULT WindowFrameGetTextView( in IVsWindowFrame* windowFrame, out IVsTextView** textView )
{
  OUTARG(textView);
  REFARG(windowFrame);

  HRESULT hr;

  VARIANT var;
  VariantInit(&var);
  hr = windowFrame->GetProperty( VSFPROPID_DocView, &var );
  if (FAILED(hr)) return hr;

  ASSERT( V_VT(&var) == VT_UNKNOWN && V_UNKNOWN(&var) != NULL);

  hr = V_UNKNOWN(&var)->QueryInterface( IID_IVsTextView, reinterpret_cast<void**>(textView) );
  if (FAILED(hr))
  {
    IVsCodeWindow* codeWin;
    hr = V_UNKNOWN(&var)->QueryInterface( IID_IVsCodeWindow, reinterpret_cast<void**>(&codeWin) );        
    VariantClear(&var);
    if (FAILED(hr)) return hr;

    hr = codeWin->GetPrimaryView( textView );
    RELEASE(codeWin);
    if (FAILED(hr)) return hr;
  }
  else
  {
    VariantClear(&var);
  }

  return S_OK;
}
