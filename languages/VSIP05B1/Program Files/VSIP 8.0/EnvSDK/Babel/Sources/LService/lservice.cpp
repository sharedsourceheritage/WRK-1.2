/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "lservice.h"
#include "source.h"
#include "coloritem.h"
#include "codewinmgr.h"
#include "parser.h"
#include "preferences.h"
#include "library.h"
#include "stringlist.h"

/*---------------------------------------------------------
  LanguageService 
-----------------------------------------------------------*/
LanguageService::LanguageService( in const wchar_t* languageName )
: m_sources(), m_libraries()
{
  TRACE_CREATE( "LanguageService", static_cast<IVsLanguageInfo*>(this) );

  m_refCount            = 1;
  m_babelService        = NULL;
  m_provider            = NULL;
  m_parser              = NULL;

  m_languageName        = SysAllocString( languageName );
  m_languageExtensions  = NULL;
  m_preferences         = NULL;
  m_debugger            = NULL;
}


LanguageService::~LanguageService()
{
  TRACE_DESTROY( static_cast<IVsLanguageInfo*>(this) );
  Done();

  ObjectElem* current;
  Source*     source;

#ifndef NDEBUG
  m_sources.GetFirst( &current, reinterpret_cast<IUnknown**>(&source) );
  ASSERT(source == NULL /* there shouldn't be any sources left now */ );
#endif

  for( m_sources.GetFirst( &current, reinterpret_cast<IUnknown**>(&source) ); source != NULL; m_sources.GetNext( &current, reinterpret_cast<IUnknown**>(&source) ) )
  {
    source->Done();
  }
  m_sources.Clear();
  m_libraries.Clear();

  bstrFree(m_languageName);
  bstrFree(m_languageExtensions);
}


STDMETHODIMP LanguageService::Init( in HKEY key )
{
  TRACE("LanguageService::Init");
  HRESULT hr;

  wchar_t  valueStr[MAXPATH+1];
  DWORD valueLen;

  //get clsid from registry
  valueLen = MAXPATH;
  hr = hrRegQueryValueEx( key, NULL, 0, NULL, (BYTE*)valueStr, &valueLen );
  if (FAILED(hr)) return hr;

  hr = CLSIDFromString( valueStr, &m_languageId );
  if (FAILED(hr)) return hr;

  //get extensions from registry
  valueLen = MAXPATH;
  hr = RegQueryValueEx( key, L"Extensions", 0, NULL, (BYTE*)valueStr, &valueLen );
  if (SUCCEEDED(hr))
      m_languageExtensions = SysAllocString(valueStr);
  
  
  //initialize preferences
  if (!m_preferences)
  {
    m_preferences = new Preferences();
    if (!m_preferences) return E_OUTOFMEMORY;

    hr = m_preferences->Init( key );
    if (FAILED(hr)) { RELEASE(m_preferences); return hr; }
  }

  return S_OK;
}

STDMETHODIMP LanguageService::SetSite( in IServiceProvider* serviceProvider )
{
  TRACE1("LanguageService::SetSite: %S", m_languageName );
  REFARG(serviceProvider);
  HRESULT hr;

  //check for changes or multiple calls
  RELEASE(m_provider);
  m_provider = serviceProvider;
  
  //set service provider
  m_provider = serviceProvider;
  ADDREF(m_provider);

  //connect preferences 
  hr = m_preferences->Connect( m_provider );
  if (FAILED(hr)) return hr;

  //load the babel service
  if (!m_babelService)
  {
    hr = ProviderCreateInstance( m_provider, m_languageId, IID_IBabelService, (void**)&m_babelService );
    if (FAILED(hr)) return hr;

    hr = m_babelService->Init( ProviderGetLocale( m_provider ), (long)m_provider );
    if (FAILED(hr)) { RELEASE(m_babelService); return hr; }
  }

  //load the parser
  if (!m_parser)
  {
    hr = CreateParser( m_provider, m_babelService, m_preferences, &m_parser );
    if (FAILED(hr)) return hr;
  }

  return S_OK;
}

STDMETHODIMP LanguageService::Done()
{
  TRACE("LanguageService::Done");
 
  if (m_babelService) 
  {
    m_babelService->Done();
  }

  m_libraries.Clear();

  if (m_preferences) 
  {
    m_preferences->Done();  //let it disconnect first
    RELEASE(m_preferences);
  }

  RELEASE(m_parser);
  RELEASE(m_babelService);
  RELEASE(m_provider);  
  RELEASE(m_debugger);
  return S_OK;
}


/*---------------------------------------------------------
  IServiceProvider
-----------------------------------------------------------*/
STDMETHODIMP LanguageService::QueryService( in REFGUID guidService, in REFIID iid, void** obj )
{
  OUTARG(obj);
  if (!m_provider) return E_UNEXPECTED;

  return m_provider->QueryService( guidService, iid, obj );
}


/*---------------------------------------------------------
  Query
-----------------------------------------------------------*/
STDMETHODIMP LanguageService::GetLanguageId( out CLSID* languageId )
{
  if (!languageId) return E_INVALIDARG;
            
  *languageId = m_languageId;
  return S_OK;
}



/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP LanguageService::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsLanguageInfo)
  {
    TRACE("LanguageService::QueryInterface for IUnknown/IVsLanguageInfo");
    *obj = static_cast<IVsLanguageInfo*>(this);
  }
  else if (iid == IID_IServiceProvider)
  {
    TRACE("LanguageService::QueryInterface for IServiceProvider");
    *obj = static_cast<IServiceProvider*>(this);
  }
  else if (iid == IID_IVsProvideColorableItems)
  {
    TRACE("LanguageService::QueryInterface for IVsProvideColorableItems");
    *obj = static_cast<IVsProvideColorableItems*>(this);
  }
  else if (iid == IID_IVsLanguageDebugInfo)
  {
    TRACE("LanguageService::QueryInterface for IVsLanguageDebugInfo");
    *obj = static_cast<IVsLanguageDebugInfo*>(this);
  }
  else 
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) LanguageService::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) LanguageService::Release()
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
  Idle
-----------------------------------------------------------*/
STDMETHODIMP_(bool) LanguageService::OnIdle( bool periodic )
{
  //TRACE("LanguageService::OnIdle");
  bool moreToDo = false;

  if (m_parser) { moreToDo |= m_parser->OnIdle(periodic); }

  ObjectElem* current;
  Source*     source;
  for( m_sources.GetFirst( &current, reinterpret_cast<IUnknown**>(&source) ); source != NULL; m_sources.GetNext( &current, reinterpret_cast<IUnknown**>(&source) ) )\
  {
    moreToDo |= source->OnIdle(periodic);
  }

  return moreToDo;
}

/*---------------------------------------------------------
  IVsLanguageInfo methods 
-----------------------------------------------------------*/
STDMETHODIMP LanguageService::GetLanguageName( out BSTR* name )
{
  TRACE("LanguageService::GetLanguageName");
  OUTARG(name);

  *name = SysAllocString( m_languageName );
  return S_OK;
}

STDMETHODIMP LanguageService::GetFileExtensions( out BSTR* extensions )
{
  TRACE("LanguageService::GetFileExtensions");
  OUTARG(extensions);

  if (m_languageExtensions) *extensions = SysAllocString(m_languageExtensions);
  return E_NOTIMPL;
}

STDMETHODIMP LanguageService::GetColorizer( in IVsTextLines* textLines, 
                                            out IVsColorizer** colorizer )
{
  TRACE("LanguageService::GetColorizer");
  OUTARG(colorizer);
  REFARG(textLines);
  
  HRESULT hr;

  //see, if we already have a source for these text lines
  Source* source = NULL;
  hr = GetSource( textLines, &source );  
  if (FAILED(hr)) return hr;
  if (hr == S_FALSE) 
  {
    //create a new source
    source = new Source( static_cast<IServiceProvider*>(this), 
                         m_preferences,
                         m_babelService, 
                         textLines, 
                         m_parser );
    if (!source) return E_OUTOFMEMORY;

    hr = source->Init();
    if (FAILED(hr)) { source->Done(); RELEASE(source); return hr; }

    hr = m_sources.Insert( static_cast<IVsTextLinesEvents*>(source) );
    source->Release();                  //the list keeps a pointer
    if (FAILED(hr)) return hr;

    //if we have a library loaded for this source, remove it
    BSTR filePath = NULL;
    hr = GetFilePath( textLines, &filePath );
    if (SUCCEEDED(hr))
    {
      ObjectElem* current = NULL;
      Library*    lib     = NULL;
      for( m_libraries.GetFirst( &current, reinterpret_cast<IUnknown**>(&lib) ); lib != NULL; m_libraries.GetNext( &current, reinterpret_cast<IUnknown**>(&lib) ) )
      {
        if (lib->SamePath(filePath))
        {
          break;
        }    
      }
      //if found, remove it
      if (lib) 
      {
        m_libraries.Remove(static_cast<IUnknown*>(lib));
      }
    }
    bstrFree(filePath);
  }
  ASSERT(source);

  hr = source->GetColorizer( colorizer );
  if (FAILED(hr)) return hr;
  
  return S_OK;
}

STDMETHODIMP LanguageService::GetCodeWindowManager( 
                                   in  IVsCodeWindow*         codeWin, 
                                   out IVsCodeWindowManager** codeWinManager )
{
  TRACE("LanguageService::GetCodeWindowManager");
  OUTARG(codeWinManager);
  REFARG(codeWin);

  *codeWinManager = new CodeWindowManager( this, m_preferences, codeWin );
  if (*codeWinManager == NULL) return E_OUTOFMEMORY;

  TRACE_LIVE_OBJECTS( "LanguageService::GetCodeWindowManager" );
  return S_OK;
}

/*---------------------------------------------------------
  Sources
-----------------------------------------------------------*/
STDMETHODIMP LanguageService::GetSource( in IVsTextBuffer* textLines, out Source** outsource )
{
  OUTARG(outsource);
  REFARG(textLines);

  ObjectElem* current;
  Source*     source;
  for( m_sources.GetFirst( &current, reinterpret_cast<IUnknown**>(&source) ); source != NULL; m_sources.GetNext( &current, reinterpret_cast<IUnknown**>(&source) ) )\
  {
    if (source->SameBuffer( textLines ))
    {
      *outsource = source;  ADDREF(*outsource);
      return S_OK;
    }
  }

  return S_FALSE;
}

STDMETHODIMP LanguageService::GetSourceFromView( in IVsTextView* textView, out Source** source )
{
  OUTARG(source);
  REFARG(textView);

  HRESULT hr;
  IVsTextLines* textLines;
  hr = textView->GetBuffer( &textLines );
  if (FAILED(hr)) return hr;

  hr = GetSource( textLines, source );
  RELEASE(textLines);  
  return hr;
}

STDMETHODIMP_(void) LanguageService::CloseSource( in Source* source )
{
  TRACE("LanguageService::CloseSource");
  ASSERT(source);
  HRESULT hr;

  hr = source->Done(); 
  ASSERT(hr==S_OK);

  hr = m_sources.Remove( static_cast<IVsTextLinesEvents*>(source) );
  ASSERT(hr==S_OK);

  return;
}


STDMETHODIMP LanguageService::LoadScope( in BSTR filePath
                                       , in IBabelProject* project                               
                                       , out IScope** scope )
{
  OUTARG(scope);
  //has the babel service loaded?
  if (!m_babelService) return S_FALSE;
  
  //is it already loaded?
  HRESULT hr;    
  ObjectElem* current;
  Source*     source;
  for( m_sources.GetFirst( &current, reinterpret_cast<IUnknown**>(&source) ); source != NULL; m_sources.GetNext( &current, reinterpret_cast<IUnknown**>(&source) ) )
  {
    BSTR sourcePath = NULL;
    hr = source->GetFilePath( &sourcePath );
    if (FAILED(hr)) continue;

    TRACE2("LoadScope '%S', already loaded source?: '%S'", filePath, sourcePath);
    bool equal = (strICompare(filePath,sourcePath) == 0);
    bstrFree(sourcePath);
    if (equal)
    {
      TRACE1("LoadScope '%S', already loaded source", filePath);
      return source->GetScope( scope ); 
    }
  }

  //is it loaded as library?
  Library* lib;
  for( m_libraries.GetFirst( &current, reinterpret_cast<IUnknown**>(&lib) ); lib != NULL; m_libraries.GetNext( &current, reinterpret_cast<IUnknown**>(&lib) ) )
  {
    if (lib->SamePath(filePath))
    {
      TRACE1("LoadScope '%S', already loaded library", filePath );    
      return lib->GetScope( scope ); 
    }    
  }


  //try to load it as a library
  lib = new Library( static_cast<IServiceProvider*>(this), m_preferences, m_babelService
                                , project, filePath );
  if (!lib) return E_OUTOFMEMORY;

  hr = lib->Init();
  if (FAILED(hr)) { RELEASE(lib); return hr; }

  hr = lib->GetScope( scope );
  if (FAILED(hr)) { RELEASE(lib); return hr; }

  hr = m_libraries.Insert( lib );
  RELEASE(lib);
  //if (FAILED(hr)) return hr; 

  return S_OK;
}

/*---------------------------------------------------------
  IVsProvideColorableItems
-----------------------------------------------------------*/
STDMETHODIMP LanguageService::GetItemCount( out int* count)
{
  TRACE("LanguageService::GetItemCount");
  OUTARG(count);

  HRESULT hr;
  long lcount = 0;
  hr = m_babelService->ColorCount( &lcount );
  if (hr == E_NOTIMPL) 
  {
    lcount = 6;
    hr = S_OK;
  } 
  else 
    if (FAILED(hr)) 
      return hr;

  *count = lcount;
  return S_OK;
}

STDMETHODIMP LanguageService::GetColorableItem( in int index, out IVsColorableItem** item )
{
  TRACE1("LanguageService::GetColorableItem: %i", index );
  OUTARG(item);
  
  HRESULT hr;
  BSTR description = NULL;
  BSTR style       = NULL;
      
  hr = m_babelService->GetColorInfo( index, &description, &style );
  if (FAILED(hr)) return hr;

  ColorItem* citem = new ColorItem( description, style );
  bstrFree(description);
  bstrFree(style);
  if (!citem) return E_OUTOFMEMORY;

  hr = citem->QueryInterface( IID_IVsColorableItem, reinterpret_cast<void**>(item) );
  RELEASE(citem);     
  if (FAILED(hr)) return hr;

  return S_OK;
}



/*---------------------------------------------------------
  IVsLanguageDebugInfo
-----------------------------------------------------------*/
STDMETHODIMP LanguageService::GetScopeFromBuffer( in IVsTextBuffer* textBuffer,
                                                  out IScope** scope )
{
  OUTARG(scope);
  INARG(textBuffer);

  //get the file name
  BSTR    filePath = NULL;
  HRESULT hr = GetFilePath( textBuffer, &filePath );
  if (FAILED(hr)) return hr;

  //use it to find the associated project
  IBabelProject* project = NULL;
  IVsHierarchy*  hierarchy = NULL;
  VSITEMID       item;
  hr = ProviderGetHierarchy( m_provider, filePath, &hierarchy, &item );
  if (SUCCEEDED(hr))
  {
    hierarchy->QueryInterface( IID_IBabelProject, reinterpret_cast<void**>(&project) );
    RELEASE(hierarchy);
  }

  //use the normal LoadScope now to get the scope
  hr = LoadScope( filePath, project, scope );
  bstrFree(filePath);
  RELEASE(project);
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP LanguageService::GetProximityExpressions (in  IVsTextBuffer *textBuffer,
                                      in  long line, in  long idx,
#ifndef VS6SDK
                                      in  long lineCount,
#endif
                                      out IVsEnumBSTR **exprs)
{
#ifdef VS6SDK
  const long  lineCount = 1;
#endif

  TRACE2( "LanguageService(%S)::GetProximityExpressions: line %i", m_languageName, line );
  OUTARG(exprs);
  INARG(textBuffer);

  //check the linecount
  if (lineCount <= 0) lineCount = 1;

  //get the source 
  //TODO: this only works for sources that are opened in the environment
  HRESULT hr;
  Source* source = NULL;
  hr = GetSource( textBuffer, &source );
  if (FAILED(hr) || !source) return hr;

  //parse and find the proximity expressions
  StringList* strings = NULL;
  hr = source->GetAutos( line - 1, line + lineCount - 1, &strings );
  RELEASE(source);
  if (FAILED(hr)) return hr;

  hr = strings->QueryInterface( IID_IVsEnumBSTR, reinterpret_cast<void**>(exprs) );
  RELEASE(strings);
  if (FAILED(hr)) return hr;
  
  return S_OK;
}

STDMETHODIMP LanguageService::ValidateBreakpointLocation (in  IVsTextBuffer *textBuffer,
                                         in  long line, in  long idx,
                                         out TextSpan *codeSpan)
{
  TRACE1( "LanguageService(%S)::ValidateBreakPointLocation", m_languageName );
  REFARG(codeSpan);
  INARG(textBuffer);

  return E_NOTIMPL;
}

STDMETHODIMP LanguageService::GetNameOfLocation (in  IVsTextBuffer *textBuffer,
                                in  long line, in  long idx,
                                out BSTR *name,
                                out long *lineOffset)
{
  TRACE1( "LanguageService(%S)::GetNameOfLocation", m_languageName );
  OUTARG(lineOffset);
  OUTARG(name);
  INARG(textBuffer);

  HRESULT hr;
  IScope* scope = NULL;
  hr = GetScopeFromBuffer( textBuffer, &scope );
  if (FAILED(hr)) return hr;
  
  long realLine = line;
  hr = scope->Narrow( line, idx, name, &realLine );
  RELEASE(scope);
  if (hr != S_OK) return hr;

  *lineOffset = line - realLine;
  return S_OK;
}

//obsolete method
STDMETHODIMP LanguageService::GetLocationOfName (in  LPCOLESTR name,
                                out BSTR *docName,
                                out TextSpan *span)
{
  REFARG(span);
  OUTARG(docName);
  INARG(name);

  return E_NOTIMPL;
}

//TODO: how can we resolve a name without a location???
STDMETHODIMP LanguageService::ResolveName (in LPCOLESTR name,
                          in DWORD flags,
                          out IVsEnumDebugName **names)
{
  TRACE2( "LanguageService(%S)::ResolveName: %S", m_languageName, name );
  OUTARG(names);
  INARG(name);

  return E_NOTIMPL;
}

STDMETHODIMP LanguageService::GetLanguageID (in IVsTextBuffer *textBuffer,
                            in long line, in  long idx,
                            out GUID *languageId)
{
  TRACE1( "LanguageService(%S)::GetLanguageID", m_languageName );
  REFARG(languageId);
  INARG(textBuffer);

  *languageId = m_languageId;
  return S_OK;
}

STDMETHODIMP LanguageService::IsMappedLocation (in  IVsTextBuffer *textBuffer,
                               in  long line, in  long idx )
{
  INARG(textBuffer);
  return S_FALSE;   //never mapped!
}

IVsDebugger* LanguageService::GetIVsDebugger()
{
  if (!m_debugger)
    if (m_provider)
      m_provider->QueryService(SID_SVsShellDebugger, IID_IVsDebugger, (void **)&m_debugger);
  return m_debugger;
}

IServiceProvider* LanguageService::GetIServiceProvider()
{
  return m_provider;
}
