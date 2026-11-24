/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef vscommon_h
#define vscommon_h

extern const GUID SID_IBabelPackage;

/*---------------------------------------------------------
  TextSpan
-----------------------------------------------------------*/
bool TextSpanPositive( in const TextSpan& span );
bool TextSpanAfterAt( in const TextSpan& span1, in const TextSpan& span2 );
bool TextSpanIsEmpty( in const TextSpan& span );
void TextSpanEmpty( out TextSpan* span );

void TextSpanMakePositive( inout TextSpan* span );
void TextSpanNormalize( inout TextSpan* span, in IVsTextLines* textLines = NULL );

void TextSpanMerge( in const TextSpan& span1, 
                    in const TextSpan& span2,
                    out TextSpan* span );


/*---------------------------------------------------------
  GetFileName
-----------------------------------------------------------*/
STDMETHODIMP GetFilePath( in IVsTextBuffer* textLines, out BSTR* filePath );

/*---------------------------------------------------------
  OpenDocument
-----------------------------------------------------------*/
STDMETHODIMP OpenDocument( in IServiceProvider* provider,
                           in wchar_t*          docName,
                           out IVsUIHierarchy** hierarchy,
                           out VSITEMID*        itemID,
                           out IVsWindowFrame** windowFrame,
                           out IVsTextView**    textView
                         );


/*---------------------------------------------------------
  IServiceProvider
-----------------------------------------------------------*/
HRESULT ProviderCreateInstance( in IServiceProvider* provider,
                                in const CLSID& clsid, in const IID& iid, out void** obj );

HRESULT ProviderClearErrorInfo( in IServiceProvider* provider );
HRESULT ProviderReportErrorInfo( in IServiceProvider* provider, in HRESULT hresult );
HRESULT ProviderGetHierarchy( in IServiceProvider* provider, in BSTR filePath, 
                              out IVsHierarchy** hierarchy, out VSITEMID* item );
LCID    ProviderGetLocale( in IServiceProvider* provider );
#endif
