/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef parser_h
#define parser_h

#include "linespan.h"

/*---------------------------------------------------------
  ParseRequest/Response
-----------------------------------------------------------*/
typedef HANDLE           EVENT;
typedef CRITICAL_SECTION GUARD;

struct ParseQueue
{
  EVENT         eventSet;
  EVENT         eventEmpty;
  GUARD         guard;  
  bool          empty;
  bool          valid;

  ParseQueue() : valid(false) { InitializeCriticalSection(&guard); }
  virtual ~ParseQueue() { DeleteCriticalSection(&guard); }

  bool GetLock()
  {
    if ( !valid )
      return false;
    EnterCriticalSection( &guard );
    if ( !valid )
    {
      LeaveCriticalSection( &guard );
      return false;
    }
    return true;
  }
};

struct ParseRequest : public ParseQueue
{
  ParseReason   reason;
  Source*       source;

  //for parsing + others
  BSTR          text;

  //for completion
  IVsTextView*  textView;
  long          line;
  long          idx;

  bool          fSync;
  DWORD         taskID;
};

struct ParseResponse : public ParseQueue
{
  ParseReason   reason;
  Source*       source;

  //for parsing
  IScope*       scope;
  ObjectList*   errors;
  TextSpan      firstError;

  //for completion & methodtip
  IVsTextView*  textView;
  LineSpanList* spans;  
  unsigned      currentParameter;

  bool          fSync;
  DWORD         taskID;
};


/*---------------------------------------------------------
  MethodTip stack
-----------------------------------------------------------*/
const int MaxCallNesting = 10;

struct MethodCall
{
  unsigned  currentParameter;
  unsigned  count;
  TextSpan  spans[MaxLineSpans];            //the method name  
};

class MethodCalls
{
private:
  MethodCall  m_calls[MaxCallNesting];
  unsigned    m_count;

public:
  MethodCalls();
  virtual ~MethodCalls();

  STDMETHODIMP_(void) Clear();
  STDMETHODIMP_(void) Push( in LineSpanList* spans );
  STDMETHODIMP_(void) NextParameter();
  STDMETHODIMP_(void) Pop();
  STDMETHODIMP GetCurrentMethodCall( out LineSpanList** spans, out unsigned* currentParameter );
};


/*---------------------------------------------------------
  Parser
-----------------------------------------------------------*/
class Scope;
class Preferences;

class Parser : public IParseSink
{
private:

  ULONG             m_refCount;
  unsigned          m_errorMax;
  unsigned          m_threadModel;
  IBabelService*    m_babelService;
  IServiceProvider* m_provider;
  EVENT             m_eventDeleted;

  //communication queues (for now of 1 element)
  ParseRequest      m_request;
  ParseResponse     m_response;
  
  //parsing
  ParseReason       m_reason;
  Source*           m_source;
  BSTR              m_text;
  bool              m_fSync;
  DWORD             m_taskID;

  //- check
  Scope*            m_scope;
  ObjectList*       m_errors;
  TextSpan          m_firstError;

  //- completion
  bool              m_found;
  bool              m_passed;

  IVsTextView*      m_textView;
  long              m_line;
  long              m_idx;
  
  LineSpanList*     m_spans;
  
  //- method tip
  MethodCalls       m_methodCalls;

  void DeleteThis()
  {
    ASSERT(m_refCount == 0);
    EVENT eventDeleted = m_eventDeleted; //save handle
    delete this; 
    SetEvent( eventDeleted );
  }

public:
  Parser( in IServiceProvider* provider, in IBabelService* babelService, 
          in unsigned errorMax, in unsigned threadModel );
  virtual ~Parser();

  STDMETHODIMP Init();
  STDMETHODIMP Done();

  //called from foreign threads
  STDMETHODIMP_(void) HandleResponse();

  STDMETHODIMP_(bool) OnIdle( bool periodic );
  STDMETHODIMP OnCheck( in Source* source, in bool onIdle );
  STDMETHODIMP OnTrigger( in Source* source, in IVsTextView* textView, in long line, in long idx, in ParseReason reason );
  STDMETHODIMP OnGetPairExtents( in Source* source, in long line, in long idx );
  STDMETHODIMP OnGetAutos( in Source* source, in long line, in long endLine );
  STDMETHODIMP OnSyncQuickInfo( in Source* source, in IVsTextView* textView, in long line, in long idx, in ParseReason, in DWORD taskID);

  //used from the parser thread
  STDMETHODIMP Destroy();
  STDMETHODIMP Main();  


  // IUnknown methods:
  STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //implement IDispatch (for IParseSink only)
  STDMETHODIMP GetTypeInfoCount( out UINT* count );
  STDMETHODIMP GetTypeInfo     ( in UINT index, in LCID lcid, out ITypeInfo** typeInfo );
  STDMETHODIMP GetIDsOfNames   ( in REFIID iid, in OLECHAR** names, in UINT count, in LCID lcid, out DISPID* dispids );
  STDMETHODIMP Invoke          ( in DISPID dispid, in REFIID iid, in LCID lcid, in WORD flags, in DISPPARAMS* args, out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg );

  // IParseSink
  STDMETHODIMP ErrorMessage( in long startLine, in long endLine,
                             in long startIdx,  in long endIdx,
                             in Severity sev, in BSTR message );

  STDMETHODIMP MatchPair( in long startLine1, in long startIdx1
                        , in long endLine1,   in long endIdx1 
                        , in long startLine2, in long startIdx2
                        , in long endLine2,   in long endIdx2 );
  
  STDMETHODIMP MatchTriple( in long startLine1, in long startIdx1
                        , in long endLine1,   in long endIdx1 
                        , in long startLine2, in long startIdx2
                        , in long endLine2,   in long endIdx2
                        , in long startLine3, in long startIdx3
                        , in long endLine3,   in long endIdx3 );
  
  STDMETHODIMP StartName( in long line, in long startIdx, in long endIdx );
  STDMETHODIMP QualifyName( in long lineSelect, in long startIdxSelect, in long endIdxSelect,
                            in long line, in long startIdx, in long endIdx );
  
  STDMETHODIMP AutoExpression( in long startLine, in long endLine,
                               in long startIdx,  in long endIdx );
  STDMETHODIMP CodeSpan( in long startLine, in long startIdx, 
                         in long endLine, in long endIdx );
  
  STDMETHODIMP StartParameters( in long line, in long idx );
  STDMETHODIMP Parameter      ( in long line, in long idx );
  STDMETHODIMP EndParameters  ( in long line, in long idx );

  STDMETHODIMP GetPackage( out IBabelPackage** package );
  STDMETHODIMP GetProject( out IBabelProject** project );
  STDMETHODIMP GetFileName( out BSTR* filePath );
								

  STDMETHODIMP AddScope(  in long startLine, in long startIdx,
                          in long endLine,   in long endIdx,
                          in enum ScopeKind kind,
                          in enum ScopeAccess access,
                          in enum ScopeStorage storage,
                          in long glyph,
                          in BSTR name,     in BSTR type,
                          in BSTR display,  in BSTR description,
                          in VARIANT_BOOL merge
                        );                       
  STDMETHODIMP AddInclude( in long startLine, in long startIdx,
                           in long endLine,   in long endIdx,
                           in enum ScopeAccess access, in BSTR name );
  STDMETHODIMP AddExtern( in long startLine, in long startIdx,
                           in long endLine,   in long endIdx,
                           in IScope* scope );
};

/*---------------------------------------------------------
  CreateParser
-----------------------------------------------------------*/
HRESULT CreateParser( in IServiceProvider* provider, 
                      in  IBabelService* babelService, 
                      in  Preferences* preferences,
                      out Parser** parser );

#endif
