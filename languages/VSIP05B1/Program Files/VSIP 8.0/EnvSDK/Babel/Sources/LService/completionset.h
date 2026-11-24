/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef completion_set
#define completion_set

class Source;

/*---------------------------------------------------------
 CompletionSet.
---------------------------------------------------------*/
class CompletionSet : public IVsCompletionSet
{
private:
  ULONG           m_refCount;
  HANDLE          m_imageList;
  long            m_glyphCount;
  Source*         m_source;

  bool            m_displayed;
  bool            m_completeWord;
  IVsTextView*    m_textView;
  IDeclarations*  m_decls;
  
public:
  CompletionSet( in HANDLE imageList, in long glyphCount, in Source* source );
  ~CompletionSet();

  STDMETHODIMP Init( in IVsTextView* textView, in IDeclarations* decls, in bool completeWord );
  STDMETHODIMP Done();
  
  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IVsCompletionSet
  STDMETHODIMP_(DWORD) GetFlags( void );
  STDMETHODIMP_(long)  GetCount( void );

  STDMETHODIMP GetImageList( out HANDLE* images );
  STDMETHODIMP GetDisplayText( in long index, out const WCHAR** text, out long* glyph );
  STDMETHODIMP GetDescriptionText( in long index, out BSTR* description );
  STDMETHODIMP GetInitialExtent( out long* line, out long* col, out long* len );
  STDMETHODIMP GetBestMatch( in const WCHAR *textSoFar, in long len, out long* index, out DWORD* flags );
  
  STDMETHODIMP_(void) Dismiss( void );
  STDMETHODIMP OnCommit( in const WCHAR* textSoFar, in long index
					   , in BOOL selected, in WCHAR commitChar, out BSTR* completeWord );
};

#endif
