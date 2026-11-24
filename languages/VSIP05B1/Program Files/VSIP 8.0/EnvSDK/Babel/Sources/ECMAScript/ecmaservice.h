/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef ecmaservice_h
#define ecmaservice_h

/*---------------------------------------------------------
  EcmaService 
-----------------------------------------------------------*/
class EcmaService : public IBabelService, public IErrorHandler
{
private:
  ULONG           m_refCount;
  ITypeInfo*      m_typeInfo;   //on IBabelService

  IColorizeText*  m_colorizer;  
  IParseText*     m_parser;
  IParseSink*     m_parseSink;
  ParseReason     m_reason;

public:
  EcmaService( in ITypeInfo* typeInfo );
  ~EcmaService();

  HRESULT Init();
  HRESULT Done();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //implement IDispatch (on IBabelService) for automation clients
  STDMETHODIMP GetTypeInfoCount(UINT *);
  STDMETHODIMP GetTypeInfo(UINT, LCID, ITypeInfo **);
  STDMETHODIMP GetIDsOfNames(REFIID, OLECHAR **, UINT, LCID, DISPID *);
  STDMETHODIMP Invoke(DISPID, REFIID, LCID, WORD, DISPPARAMS *, VARIANT *, EXCEPINFO *, UINT *);

  //IBabelService
  STDMETHODIMP ColorCount( out ColorClass* count );
  STDMETHODIMP GetColorInfo( in  ColorClass index, 
                             out BSTR*      description,
                             out BSTR*      style );

  STDMETHODIMP ColorLine( in    BSTR          line, 
                          in    IColorSink*   sink,
                          inout long* state );

  STDMETHODIMP ParseSource( in  BSTR             text, 
                            in  IParseSink*      sink,
                            in  enum ParseReason reason,
                            out IScope**         scope );

  STDMETHODIMP GetMethodFormat( out BSTR*         parStart,
                                out BSTR*         parSep, 
                                out BSTR*         parEnd,
                                out BSTR*         typeStart, 
                                out BSTR*         typeEnd,
                                out VARIANT_BOOL* typePrefixed );

  STDMETHODIMP GetCommentFormat( out BSTR*         lineStart, 
                                 out BSTR*         blockStart,
                                 out BSTR*         blockEnd,
                                 out VARIANT_BOOL* useLineComments );

  STDMETHODIMP GetImageList( out long* imageListHandle );

  //IErrorHandler
  STDMETHODIMP OnCompilerError( in IVsaFullErrorInfo* error, out VARIANT_BOOL* abort );
};

#endif
