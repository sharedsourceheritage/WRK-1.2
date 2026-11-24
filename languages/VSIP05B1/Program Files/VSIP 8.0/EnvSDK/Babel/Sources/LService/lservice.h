/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef lservice_h
#define lservice_h

class Source;
class Parser;
class Preferences;

/*---------------------------------------------------------
 LanguageService
---------------------------------------------------------*/
class LanguageService :
    public IVsLanguageInfo,
    public IVsLanguageDebugInfo,
    public IVsProvideColorableItems,
    public IServiceProvider
{
private:
    ULONG                     m_refCount;
    BSTR                      m_languageName;
    BSTR                      m_languageExtensions;
    CLSID                     m_languageId;

    IBabelService*            m_babelService;
    IServiceProvider*         m_provider;
    Parser*                   m_parser;
    Preferences*              m_preferences;

    ObjectList                m_sources;
    ObjectList                m_libraries;
    IVsDebugger*              m_debugger; 

    STDMETHODIMP GetScopeFromBuffer( in  IVsTextBuffer* textBuffer,
                                     out IScope** scope );

public:
    LanguageService( in const wchar_t* name );
    ~LanguageService();
    
    // Initialisation
    STDMETHODIMP Init( in HKEY key );
    STDMETHODIMP SetSite( in IServiceProvider* serviceProvider );
    STDMETHODIMP Done();

    // Query
    STDMETHODIMP GetLanguageId( out CLSID* languageId );
    
    // Sources
    STDMETHODIMP GetSource( in IVsTextBuffer* textLines, out Source** source );
    STDMETHODIMP GetSourceFromView( in IVsTextView* textView, out Source** source );
    STDMETHODIMP_(void) CloseSource( in Source* source );


    // IUnknown methods 
    STDMETHODIMP QueryInterface( in REFIID iid, out void** obj);
    STDMETHODIMP_(ULONG) AddRef();
    STDMETHODIMP_(ULONG) Release();

    // IServiceProvider
    STDMETHODIMP QueryService( in REFGUID guidService, in REFIID iid, void** obj );
    
    //OnIdle
    STDMETHODIMP_(bool) OnIdle( bool periodic );

    // IVsLanguageInfo methods 
    STDMETHODIMP GetLanguageName( out BSTR* name );
    STDMETHODIMP GetFileExtensions( out BSTR* extensions );
    STDMETHODIMP GetColorizer( in IVsTextLines* textLines, out IVsColorizer** colorizer );   
    STDMETHODIMP GetCodeWindowManager( in  IVsCodeWindow*         codeWin, 
                                       out IVsCodeWindowManager** codeWinManager );
    

    // IVsProvideColorableItems
    STDMETHODIMP GetItemCount( out int* count);
    STDMETHODIMP GetColorableItem( in int index, out IVsColorableItem** item ); 

    // Scope Loading
    STDMETHODIMP LoadScope( in BSTR filePath,
                            in IBabelProject* project,
                            out IScope** scope );

    // IVsLanguageDebugInfo 
    STDMETHODIMP GetProximityExpressions (in  IVsTextBuffer *textBuffer,
                                          in  long line, in  long idx,
#ifndef VS6SDK
                                          in  long lineCount,
#endif
                                          out IVsEnumBSTR **exprs);
    STDMETHODIMP ValidateBreakpointLocation (in  IVsTextBuffer *textBuffer,
                                             in  long line, in  long idx,
                                             out TextSpan *codeSpan);
    STDMETHODIMP GetNameOfLocation (in  IVsTextBuffer *textBuffer,
                                    in  long line, in  long idx,
                                    out BSTR *name,
                                    out long *lineOffset);
    STDMETHODIMP GetLocationOfName (in  LPCOLESTR name,
                                    out BSTR *docName,
                                    out TextSpan *span);
    STDMETHODIMP ResolveName (in LPCOLESTR name,
                              in DWORD flags,
                              out IVsEnumDebugName **names);
    STDMETHODIMP GetLanguageID (in IVsTextBuffer *textBuffer,
                                in long line, in  long idx,
                                out GUID *languageId);
    STDMETHODIMP IsMappedLocation (in  IVsTextBuffer *textBuffer,
                                   in  long line, in  long idx );

    IVsDebugger* GetIVsDebugger();
    IServiceProvider* GetIServiceProvider();


};



#endif
