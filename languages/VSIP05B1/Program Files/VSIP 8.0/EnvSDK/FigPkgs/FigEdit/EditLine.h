
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// EditLine.h : Declaration of CFigEditLine

#pragma once

/////////////////////////////////////////////////////////////////////////////
// forward declarations

/////////////////////////////////////////////////////////////////////////////
// CFigEditLine

class CFigEditLine :
    public IDispatchImpl<IFigEditLine, &IID_IFigEditLine, &LIBID_FigPkgLib>, // and ATL template to impl. IDisp for us.
    public IVsProvideUserContext, // to provide the context for selected item
    public IFigLineSelect
{
public:
    CFigEditLine( long Line, IVsTextLines *pVsTextLines );
    CFigEditLine( long Line, IVsTextLines *pVsTextLines, FigLineType Type, 
            long P1, long P2, long P3, long P4, BSTR bstrComment );
    ~CFigEditLine();
    
    BEGIN_INTERFACE
    // *** IUnknown methods ***
    STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
    STDMETHODIMP_(ULONG) AddRef();
    STDMETHODIMP_(ULONG) Release();

    // IDispatch methods are implemented by the ATL template IDispatchImpl.
    // The following ATL macro is used with IDispatchImpl.
BEGIN_PROP_MAP(CFigEditLine)
    PROP_ENTRY("Type", 100, CLSID_NULL)
    PROP_ENTRY("Parameter1", 101, CLSID_NULL)
    PROP_ENTRY("Parameter2", 102, CLSID_NULL)
    PROP_ENTRY("Parameter3", 103, CLSID_NULL)
    PROP_ENTRY("Parameter4", 104, CLSID_NULL)
    PROP_ENTRY("Comment", 105, CLSID_NULL)
END_PROP_MAP()

    // IDispatch properties:
    STDMETHODIMP put_Type( FigLineType Type );
    STDMETHODIMP get_Type( FigLineType *pType );
    STDMETHODIMP put_Parameter1( long Param );
    STDMETHODIMP get_Parameter1( long *pParam );
    STDMETHODIMP put_Parameter2( long Param );
    STDMETHODIMP get_Parameter2( long *pParam );
    STDMETHODIMP put_Parameter3( long Param );
    STDMETHODIMP get_Parameter3( long *pParam );
    STDMETHODIMP put_Parameter4( long Param );
    STDMETHODIMP get_Parameter4( long *pParam ); 
    STDMETHODIMP put_Comment( BSTR pbstrComment );
    STDMETHODIMP get_Comment( BSTR *ppbstrComment );

    // IFigLineSelect methods:
    STDMETHODIMP SetSelection( BOOL fSelected );
    STDMETHODIMP GetSelection( BOOL *pfSelected );

    // public methods:
    long GetLineNumber( void );
    void SetLineNumber( long nLine );
    void DoBufferUpdate( BOOL fUpdate );
    HRESULT UpdateBuffer( void );
    HRESULT InsertLineToBuffer( void );
    HRESULT DeleteLineFromBuffer( void );
    void MakeLine( BSTR *pbstrLine );

    //----------------------------------------------------------------------
    // Function:    CanEditBuffer
    //              Check whether the buffer is editable. 
    // Parameters:  
    //
    // Returns:     HRESULT :
    //                  S_OK     - the buffer is editable
    //                  E_ABORT  - the buffer is  not editable (the checkout 
    //                             was cancelled)
    //                  E_xxx    - failure
    // Notes:
    //              Checks with IVsQueryEditQuerySave to see if the file
    //              can be edited (via AttemptToCheckOutBufferFromScc2)
    //----------------------------------------------------------------------
    STDMETHOD(CanEditBuffer)();


//==========================================================================
//                                                     IVsProvideUserContext
public:

    STDMETHOD(GetUserContext)(
        /* [out, retval] */ IVsUserContext** ppctx);

protected:

    STDMETHOD(UpdateUserContext)();
//                                                     IVsProvideUserContext
//==========================================================================


private:
    DWORD m_dwRef;
    BOOL m_fZombie;
    long m_Line;
    FigLineType m_Type;
    long m_P1, m_P2, m_P3, m_P4;
    CComBSTR m_bstrComment;
    BOOL m_fSelected;
    BOOL m_fUpdate;
    CComPtr<IVsTextLines> m_srpVsTextLines;
    CComPtr<IVsUserContext> m_srpIVsUserContext; // context for the selection
};

typedef CFigEditLine *CFigEditLinePtr;
typedef list<CFigEditLine*> listLines_type;  

/////////////////////////////////////////////////////////////////////////////
