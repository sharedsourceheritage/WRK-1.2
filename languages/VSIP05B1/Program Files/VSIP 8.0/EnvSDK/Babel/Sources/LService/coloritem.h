/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef coloritem_h
#define coloritem_h

/*---------------------------------------------------------
  ColorItem
---------------------------------------------------------*/
class ColorItem: public IVsColorableItem
{
private:
  ULONG       m_refCount;
  BSTR        m_description;

public:
  //these should be treated as private but are declared public
  //so that the property setters can be global functions that
  //can be put in a lookup table.
  COLORINDEX  m_foreColor;
  COLORINDEX  m_backColor;
  DWORD       m_fontFlags;

public:
  // [style] is a CSS style specification
  ColorItem( in BSTR description, in BSTR style );
  ~ColorItem();

  // IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  // IVsColorableItem
  STDMETHODIMP GetDefaultColors( out COLORINDEX* foreColor, out COLORINDEX* backColor);
  STDMETHODIMP GetDefaultFontFlags( out DWORD* fontFlags );
  STDMETHODIMP GetDisplayName( out BSTR* description );
};


#endif
