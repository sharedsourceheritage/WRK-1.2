/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef stringlist_h
#define stringlist_h

class LineSpanList;

class StringList : public IVsEnumBSTR
{
private:
  ULONG     m_refCount;

  BSTR*     m_strings;
  ULONG     m_count;
  ULONG     m_current;

public:
  StringList();
  ~StringList();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //StringList
  STDMETHODIMP Init( in IVsTextLines* textLines, in LineSpanList* spans );

  //IVsEnumBSTR
  STDMETHODIMP Next( in  ULONG count, 
                     out BSTR* elements, out ULONG* fetched );
  STDMETHODIMP Skip( in ULONG count );
  STDMETHODIMP Reset( void );
  STDMETHODIMP Clone( out IVsEnumBSTR** enumBstr );
  STDMETHODIMP GetCount( out ULONG* count );
};

#endif
