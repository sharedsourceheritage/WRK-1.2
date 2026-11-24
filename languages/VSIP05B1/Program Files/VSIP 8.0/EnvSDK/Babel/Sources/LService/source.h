/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef source_h
#define source_h

class Colorizer;
class LanguageService;
class Preferences;
class Parser;
class TaskProvider;
class CompletionSet;
class LineSpanList;
class MethodData;
class StringList;

/*---------------------------------------------------------
  CommentInfo, used for automatic (un)commenting of selections
-----------------------------------------------------------*/
struct CommentInfo
{
  BSTR lineStart;
  BSTR blockStart;
  BSTR blockEnd;
  bool useLineComment;
  bool supported;
};

/*---------------------------------------------------------
 CharInfo, used to get fast info about the line tokens
---------------------------------------------------------*/
struct CharInfo
{
  bool         newToken;
  CharClass    charClass;
  TriggerClass triggerClass;
};

/*---------------------------------------------------------
  Source
-----------------------------------------------------------*/
class Source :     
     public IVsTextLinesEvents              
#ifdef VS7SDK
    ,public IVsFinalTextChangeCommitEvents
#endif
{
private:
  static DWORD      ms_taskID;
  static DWORD      GetNewTaskID();

  ULONG               m_refCount;
  
  Preferences*        m_preferences;
  IVsTextLines*       m_textLines;
  IBabelService*      m_babelService;
  IServiceProvider*   m_provider;         
  IVsStatusbar*       m_statusBar;

  //each source has one parser/task provider/completion set/method data/scope
  TaskProvider*       m_taskProvider;
  Parser*             m_parser;
  CompletionSet*      m_completionSet;
  MethodData*         m_methodData;
  IScope*             m_scope;
  TextSpan            m_scopeFirstError;    //first error position for this scope

  //keep track of source changes, we check in idle time if needed
  ULONG               m_dirty;        //0 = not dirty, 1 = dirty, 2 = extra dirty (=line change commit)
  DWORD               m_dirtyTime;
  ObjectList*         m_errors;

  DWORD               m_textLinesConnect;     //IVsTextLinesEvents
  DWORD               m_textChangeConnect;    //IVsFinalTextChangeCommitEvents


  //each source has one colorizer
  Colorizer*          m_colorizer;
  IVsTextColorState*  m_colorState;  

  //automatic commenting
  CommentInfo         m_commentInfo;

  
  //callback: pair extents
  TextSpan*           m_pairExtents;

  //callback: auto expressions
  StringList**        m_autos;

  //callback: quick info
  long                m_quickInfoLine;
  long                m_quickInfoIdx;
  BSTR*               m_quickInfoText;

  // sync quick info 
  // we might check if we can reuse the quick info members declared above
  // but to be safe let's use different ones 
  BSTR*               m_pbstrSyncQuickInfo;
  long                m_lSyncQuickInfoLine;
  long                m_lSyncQuickInfoIdx;
  DWORD               m_taskIDSyncQuickInfo;


public:
  Source( in IServiceProvider* provider,
          in Preferences*     preferences,
          in IBabelService*   babelService, 
          in IVsTextLines*    textLines,
          in Parser*          parser );
  ~Source();

  STDMETHODIMP Init();
  STDMETHODIMP Done();
  STDMETHODIMP_(void) CloseColorizer();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //Query
  STDMETHODIMP_(bool) SameBuffer( in IVsTextBuffer* textLines );
  STDMETHODIMP GetBuffer( out IVsTextLines** textLines );
  STDMETHODIMP GetFilePath( out BSTR* filePath );
  STDMETHODIMP GetText( in long maxLine, out BSTR* text );
  STDMETHODIMP GetScope( out IScope** scope );

  STDMETHODIMP GetColorizer( out IVsColorizer** colorizer );
  STDMETHODIMP GetLineInfo( in unsigned line, out const CharInfo** lineInfo, out unsigned* lineLen );
  STDMETHODIMP_(bool) IsCommitChar( in const wchar_t* text, in wchar_t commitChar );

  //called from ViewFilter
  STDMETHODIMP OnCommand( in IVsTextView* textView, DWORD command, bool backward );
  STDMETHODIMP GetPairExtents( long line, long idx, TextSpan* span );
  STDMETHODIMP Completion( in IVsTextView* textView, in bool completeWord );
  STDMETHODIMP MethodTip( in IVsTextView* textView, long line, long idx );
  STDMETHODIMP GetWordExtent( in long line, in long idx, in DWORD flags, out long* startIdx, out long* endIdx );
  STDMETHODIMP OnQuickInfo( in IVsTextView* textView, in long line, in long idx, in BSTR* text);
  STDMETHODIMP OnSyncQuickInfo( in IVsTextView* textView, in long line, in long idx, in BSTR* text);
  STDMETHODIMP DismissMethodTip();

  //called from LanguageService
  STDMETHODIMP GetAutos( in long startLine, in long endLine, out StringList** strings );
  
  //Parser
  STDMETHODIMP_(bool) OnIdle( bool periodic );
  STDMETHODIMP ResponseOnCheck( in ObjectList*     errors, 
                                in const TextSpan& firstError,
                                in IScope*         scope );
  STDMETHODIMP ResponseOnCompletion( in IVsTextView* textView, in LineSpanList* names, bool completeWord );
  STDMETHODIMP ResponseOnMethodTip( in IVsTextView* textView, 
                                    in LineSpanList* names,
                                    in unsigned      currentParameter );
  STDMETHODIMP ResponseOnMatchBraces( in IVsTextView* textView, in LineSpanList* spans );
  STDMETHODIMP ResponseOnQuickInfo( in LineSpanList* spans );
  STDMETHODIMP ResponseOnSyncQuickInfo( in LineSpanList* spans, in DWORD taskID );

  STDMETHODIMP ResponseOnAutos( in LineSpanList* spans );
  
  // IVsFinalTextChangeCommitEvents
  STDMETHODIMP_(void) OnChangesCommitted( in DWORD reason, in TextSpan* changedArea);

  // IVsTextLinesEvents
  STDMETHODIMP_(void) OnChangeLineText( in const TextLineChange* lineChange, in BOOL last);
  STDMETHODIMP_(void) OnChangeLineAttributes( in long firstLine, in long lastLine)
  {}


  //Commenting
  STDMETHODIMP_(bool) CommentSupported();
  STDMETHODIMP CommentSelection( in IVsTextView* textView );
  STDMETHODIMP UnCommentSelection( in IVsTextView* textView );  
};

#endif
