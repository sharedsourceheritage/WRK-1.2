/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef linespan_h
#define linespan_h

struct LineSpan
{
  long  startLine;
  long  startIdx;
  long  endIdx;
};


const int MaxLineSpans  = 50;

class LineSpanList : public IUnknown
{
private:
  ULONG     m_refCount;

  LineSpan  m_list[MaxLineSpans];
  unsigned  m_count;

public:
  LineSpanList();
  ~LineSpanList();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //LineSpanList
  void     Clear();
  unsigned GetCount();

  HRESULT  PushBack( in const TextSpan& textSpan );
  HRESULT  MergeTop( in const TextSpan& textSpan );
  HRESULT  Get( in unsigned index, out TextSpan* textSpan );
  HRESULT  GetNames( in IVsTextLines* textLines, out INames** names );
};

#endif
