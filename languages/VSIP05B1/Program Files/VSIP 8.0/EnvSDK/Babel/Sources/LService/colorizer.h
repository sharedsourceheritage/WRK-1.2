/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef colorizer_h
#define colorizer_h



/*---------------------------------------------------------
 Colorizer
---------------------------------------------------------*/
class Colorizer : public IVsColorizer, 
                  public IColorSink
{
private:
  ULONG             m_refCount;
  IBabelService*    m_babelService;

  long              m_line;
  ULONG*            m_lineAttributes;
  long              m_lineLen;

  long              m_lineCached;         
  long              m_lineCachedLen;
  CharInfo*         m_lineCachedInfo;
  
public:
  Colorizer( in IBabelService* babelService );
  ~Colorizer();

   // IUnknown methods 
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj);
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //implement IDispatch (for IColorSink only)
  STDMETHODIMP GetTypeInfoCount( out UINT* count );
  STDMETHODIMP GetTypeInfo     ( in UINT index, in LCID lcid, out ITypeInfo** typeInfo );
  STDMETHODIMP GetIDsOfNames   ( in REFIID iid, in OLECHAR** names, in UINT count, in LCID lcid, out DISPID* dispids );
  STDMETHODIMP Invoke          ( in DISPID dispid, in REFIID iid, in LCID lcid, in WORD flags, in DISPPARAMS* args, out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg );

  // IVsColorizer
  STDMETHODIMP GetStateMaintenanceFlag( out BOOL* useState );
  STDMETHODIMP GetStartState( out long* startState );

  STDMETHODIMP_(long) ColorizeLine( in long         line,
				                    in long         length,
				                    in const WCHAR* text,
				                    in long         state,
				                    in ULONG*       attributes );

  STDMETHODIMP_(long) GetStateAtEndOfLine( in long         line,
					                       in long         length,
					                       in const WCHAR* text,
					                       in long         state );

  STDMETHODIMP_(void) CloseColorizer( void );

  //IColorSink callback
  STDMETHODIMP Colorize( in long          startIdx, 
                         in long          endIdx, 
                         in ColorClass    colorClass,
                         in CharClass     charClass, 
                         in TriggerClass  triggerClass );


  //LineInfo; used internally for fast info about tokens on a line
  STDMETHODIMP SetCachedLine( in long line );
  STDMETHODIMP GetLineInfo( in  long               line, 
                            in  IVsTextColorState* colorState,
                            out const CharInfo**   lineInfo, 
                            out unsigned*          length );

  STDMETHODIMP GetLineInfoText( in const WCHAR*      text, 
                                in long              textLen,
                                inout long*          state,
                                out const CharInfo** lineInfo, 
                                out unsigned*        length );


};

#endif
