
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// EditLine.cpp : Implementation of CFigEditLine

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes


CFigEditLine::CFigEditLine( long Line, IVsTextLines *pVsTextLines )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, _T(" CFigEditLine::CFigEditLine \n") );

    m_dwRef = 0;
    m_fZombie = FALSE;
    m_Line = Line;
    m_Type = FigInvalid;
    m_P1 = 0;
    m_P2 = 0;
    m_P3 = 0;
    m_P4 = 0;
    m_fSelected = FALSE;
    m_fUpdate = TRUE;
    m_srpVsTextLines = pVsTextLines;  // Note: assignment to a smart pointer does an AddRef()
}

CFigEditLine::CFigEditLine( long Line, IVsTextLines *pVsTextLines, FigLineType Type, 
            long P1, long P2, long P3, long P4, BSTR bstrComment )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, _T(" CFigEditLine::CFigEditLine \n") );

    m_dwRef = 0;
    m_fZombie = FALSE;
    m_Line = Line;
    m_Type = Type;
    m_P1 = P1;
    m_P2 = P2;
    m_P3 = P3;
    m_P4 = P4;
    m_bstrComment = bstrComment;
    m_fSelected = FALSE;
    m_fUpdate = TRUE;
    m_srpVsTextLines = pVsTextLines;  // Note: assignment to a smart pointer does an AddRef()
}

CFigEditLine::~CFigEditLine()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, _T(" CFigEditLine::~CFigEditLine \n") );

    _ASSERTE( 0 == m_dwRef );
    m_bstrComment.Empty();
}


/*****************************************************************************
** IUnknown Implementation
*****************************************************************************/

STDMETHODIMP CFigEditLine::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::QueryInterface \n") );

    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;        // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        AddRef();
        *ppvObj = static_cast<IUnknown *>(static_cast<IDispatch *>(this));
        return NOERROR;
    }
    else if( riid == IID_IDispatch )
    {
        AddRef();
        *ppvObj = (IDispatch *) this;
        return NOERROR;
    }
    else if( riid == IID_IFigEditLine )
    {
        AddRef();
        *ppvObj = (IFigEditLine *) this;
        return NOERROR;
    }
    else if( riid == IID_IFigLineSelect )
    {
        AddRef();
        *ppvObj = (IFigLineSelect *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsProvideUserContext )
    {
        AddRef();
        *ppvObj = static_cast<IVsProvideUserContext*>(this);
        return NOERROR;
    }
    
    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigEditLine::AddRef()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::AddRef \n") );

    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigEditLine::Release()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::Release \n") );

    _ASSERTE( 0 != m_dwRef );
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


/*****************************************************************************
** IDispatch Property methods
*****************************************************************************/

STDMETHODIMP CFigEditLine::put_Type( FigLineType Type )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::put_Type \n") );

    HRESULT hr = S_OK;

    if( Type >= FigArrow && Type <= FigInvalid ) 
    {
        // check if we can edit the buffer
        hr = CanEditBuffer();
        _IfFailRet(hr);

        m_Type = Type;

        hr = UpdateBuffer();
        IfFailRet(hr);

        hr = UpdateUserContext();
        IfFailRet(hr);

        CComPtr<IVsUIShell> srpIVsUIShell;
        hr = _AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void**)&srpIVsUIShell);
        IfFailRet(hr);
        hr = srpIVsUIShell->RefreshPropertyBrowser(DISPID_UNKNOWN);

        return hr;
    } else
        return E_INVALIDARG;
}

STDMETHODIMP CFigEditLine::get_Type( FigLineType *pType )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::get_Type \n") );

    if( pType == NULL )
        return E_INVALIDARG;

    *pType = m_Type;
    return S_OK;
}

STDMETHODIMP CFigEditLine::put_Parameter1( long Param )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::put_Parameter1 \n") );

    HRESULT hr = S_OK;

    if( Param >= FIG_PARAM_MIN && Param <= FIG_PARAM_MAX ) 
    {
        // check if we can edit the buffer
        hr = CanEditBuffer();
        _IfFailRet(hr);

        m_P1 = Param;

        hr = UpdateBuffer();
        return hr;
    } else
        return E_INVALIDARG;
}

STDMETHODIMP CFigEditLine::put_Parameter2( long Param )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::put_Parameter2 \n") );

    HRESULT hr = S_OK;

    if( Param >= FIG_PARAM_MIN && Param <= FIG_PARAM_MAX ) 
    {
        // check if we can edit the buffer
        hr = CanEditBuffer();
        _IfFailRet(hr);

        m_P2 = Param;

        hr = UpdateBuffer();
        return hr;
    } else
        return E_INVALIDARG;
}

STDMETHODIMP CFigEditLine::put_Parameter3( long Param )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::put_Parameter3 \n") );

    HRESULT hr = S_OK;

    if( Param >= FIG_PARAM_MIN && Param <= FIG_PARAM_MAX ) 
    {
        // check if we can edit the buffer
        hr = CanEditBuffer();
        _IfFailRet(hr);

        m_P3 = Param;

        hr = UpdateBuffer();
        return hr;
    } else
        return E_INVALIDARG;
}

STDMETHODIMP CFigEditLine::put_Parameter4( long Param )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::put_Parameter4 \n") );

    HRESULT hr = S_OK;

    if( Param >= FIG_PARAM_MIN && Param <= FIG_PARAM_MAX ) 
    {
        // check if we can edit the buffer
        hr = CanEditBuffer();
        _IfFailRet(hr);

        m_P4 = Param;

        hr = UpdateBuffer();
        return hr;
    } else
        return E_INVALIDARG;
}

STDMETHODIMP CFigEditLine::get_Parameter1( long *pParam )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::get_Parameter1 \n") );

    if( pParam == NULL )
        return E_INVALIDARG;

    *pParam = m_P1;
    return S_OK;
}

STDMETHODIMP CFigEditLine::get_Parameter2( long *pParam )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::get_Parameter2 \n") );

    if( pParam == NULL )
        return E_INVALIDARG;

    *pParam = m_P2;
    return S_OK;
}

STDMETHODIMP CFigEditLine::get_Parameter3( long *pParam )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::get_Parameter3 \n") );

    if( pParam == NULL )
        return E_INVALIDARG;

    *pParam = m_P3;
    return S_OK;
}

STDMETHODIMP CFigEditLine::get_Parameter4( long *pParam )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::get_Parameter4 \n") );

    if( pParam == NULL )
        return E_INVALIDARG;

    *pParam = m_P4;
    return S_OK;
}

STDMETHODIMP CFigEditLine::put_Comment( BSTR pbstrComment )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::put_Comment \n") );

    if( pbstrComment == NULL )
        return E_INVALIDARG;

    // check if we can edit the buffer
    HRESULT hr = CanEditBuffer();
    _IfFailRet(hr);

    m_bstrComment = pbstrComment;

    hr = UpdateBuffer();
    return hr;
}

STDMETHODIMP CFigEditLine::get_Comment( BSTR *ppbstrComment )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::get_Comment \n") );

    if( ppbstrComment == NULL )
        return E_INVALIDARG;

    *ppbstrComment = m_bstrComment.Copy();
    return S_OK;
}


/*****************************************************************************
** IFigLineSelect methods
*****************************************************************************/

STDMETHODIMP CFigEditLine::SetSelection( BOOL fSelected )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::SetSelection \n") );

    m_fSelected = fSelected;
    return S_OK;
}

STDMETHODIMP CFigEditLine::GetSelection( BOOL *pfSelected )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::GetSelection \n") );

    if( pfSelected == NULL )
        return E_INVALIDARG;

    *pfSelected = m_fSelected;
    return S_OK;
}


/*****************************************************************************
** public methods
*****************************************************************************/

long CFigEditLine::GetLineNumber( void )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::GetLineNumber \n") );

    return m_Line;
}

void CFigEditLine::SetLineNumber( long nLine )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::SetLineNumber \n") );

    m_Line = nLine;
}

void CFigEditLine::DoBufferUpdate( BOOL fUpdate )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::DoBufferUpdate \n") );

    m_fUpdate = fUpdate;
}

HRESULT CFigEditLine::UpdateBuffer( void )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::UpdateBuffer \n") );

    HRESULT hr = S_OK;

    if( !m_fUpdate )    // don't do any updates to the buffer. (change originated from buffer, not user)
        return hr;

    // build a line from the properties:
    CComBSTR bstrLine;
    MakeLine( &bstrLine );

    long nOldLineLength;
    hr = m_srpVsTextLines->GetLengthOfLine( m_Line, &nOldLineLength );
    if( FAILED( hr )) 
        return hr;

    // Replaces the specified span of text
    TextSpan ts;
    hr = m_srpVsTextLines->ReplaceLines(
        m_Line,                // starting line
        0,                    // starting character index within the line (must be <= length of line)
        m_Line,                // ending line
        nOldLineLength,        // ending character index within the line (must be <= length of line)
        bstrLine,            // new line text to insert
        bstrLine.Length(),    // # of chars to insert, if any
        &ts );                // range of characters changed
    if( FAILED( hr ))
        return hr;

    return hr;
}

HRESULT CFigEditLine::InsertLineToBuffer( void )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::InsertLineToBuffer \n") );

    HRESULT hr = S_OK;

    // check if we can edit the buffer
    hr = CanEditBuffer();
    _IfFailRet(hr);

    // build a line from the properties:
    CComBSTR bstrLine;
    MakeLine( &bstrLine );

    // handle the special case of inserting last line in the buffer:
    long nLines, nLine, nCol = 0;
    hr = m_srpVsTextLines->GetLineCount( &nLines );
    if (nLines != 0)            // Text already exists?
    {
        if (m_Line > nLines)    // Append to end?
        {
            nLine = nLines - 1;
            hr = m_srpVsTextLines->GetLengthOfLine( nLine, &nCol );
            if( FAILED( hr )) 
                return hr;

            if (nCol > 0)        // Is the last line not empty?
            {
                CComBSTR    bstrTmp( "\n" );    // must add a newline
                bstrTmp += bstrLine;
                bstrLine = bstrTmp;
            }
        }
        else if (m_Line > 0)    // Inserting in the middle?
        {
            nLine = m_Line - 1;
            bstrLine += "\n";
        }
    }
    else                        // Inserting to empty buffer
        nLine = 0;

    // Inserts the specified span of text
    TextSpan ts;
    hr = m_srpVsTextLines->ReplaceLines(
        nLine,                // starting line
        nCol,                // starting character index within the line (must be <= length of line)
        nLine,                // ending line
        nCol,                // ending character index within the line (must be <= length of line)
        bstrLine,            // new line text to insert
        bstrLine.Length(),    // # of chars to insert, if any
        &ts );                // range of characters changed
    if( FAILED( hr ))
        return hr;

    return hr;
}

HRESULT CFigEditLine::DeleteLineFromBuffer( void )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::DeleteLineFromBuffer \n") );

    HRESULT hr = S_OK;

    // check if we can edit the buffer
    hr = CanEditBuffer();
    _IfFailRet(hr);

    // handle the special case of deleting the last line:
    long nLines, nStart, nEnd, nLength, nStartCol;
    nStart = m_Line;
    hr = m_srpVsTextLines->GetLineCount( &nLines );
    if( FAILED( hr ))
        return hr;
    _ASSERTE( nLines > m_Line );
    if( (nLines - 1) == nStart ) {
        nEnd = nStart;
        hr = m_srpVsTextLines->GetLengthOfLine( nStart, &nLength );
        if( FAILED( hr ))
            return hr;
        if (nStart > 0)    // If the last line is not the first line
        {
            --nStart;
            hr = m_srpVsTextLines->GetLengthOfLine( nStart, &nStartCol );
            if( FAILED( hr ))
                return hr;
        }
        else nStartCol = 0;
    } else  {
        nEnd = m_Line + 1;
        nLength = 0;
        nStartCol = 0;
    }

    // Delete this line
    TextSpan ts;
    hr = m_srpVsTextLines->ReplaceLines(
        nStart,                // starting line
        nStartCol,            // starting character index within the line (must be <= length of line)
        nEnd,                // ending line (subsequent line, to incl EOL)
        nLength,            // ending line index (start of next line)
        NULL,                // no text to replace
        0,                    // no length of text
        &ts );                // range of characters changed
    if( FAILED( hr ))
        return hr;

    return hr;
}

void CFigEditLine::MakeLine( BSTR *pbstrLine )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CFigEditLine::MakeLine \n") );

    // build a line from the properties:
    CComBSTR bstrLine;
    char buf[50];
    switch( m_Type ) {
    case FigArrow:
        bstrLine = "draw arrow ";
        bstrLine += ltoa( m_P1, buf, 10 );
        bstrLine += " ";
        bstrLine += ltoa( m_P2, buf, 10 );
        bstrLine += " ";
        bstrLine += ltoa( m_P3, buf, 10 );
        bstrLine += " ";
        bstrLine += ltoa( m_P4, buf, 10 );
        if( m_bstrComment.Length() > 0 ) {
            bstrLine += " '";
            bstrLine += m_bstrComment;
        }
        break;
    case FigCircle:
        bstrLine = "draw circle ";
        bstrLine += ltoa( m_P1, buf, 10 );
        bstrLine += " ";
        bstrLine += ltoa( m_P2, buf, 10 );
        bstrLine += " ";
        bstrLine += ltoa( m_P3, buf, 10 );
        if( m_bstrComment.Length() > 0 ) {
            bstrLine += " '";
            bstrLine += m_bstrComment;
        }
        break;
    case FigRectangle:
        bstrLine = "draw rectangle ";
        bstrLine += ltoa( m_P1, buf, 10 );
        bstrLine += " ";
        bstrLine += ltoa( m_P2, buf, 10 );
        bstrLine += " ";
        bstrLine += ltoa( m_P3, buf, 10 );
        bstrLine += " ";
        bstrLine += ltoa( m_P4, buf, 10 );
        if( m_bstrComment.Length() > 0 ) {
            bstrLine += " '";
            bstrLine += m_bstrComment;
        }
        break;
    case FigComment:
        bstrLine = "'";
        bstrLine += m_bstrComment;
        break;
    default:
        bstrLine = m_bstrComment;
        break;
    }
    
    *pbstrLine = bstrLine.Detach();
}


STDMETHODIMP CFigEditLine::CanEditBuffer()
{
    ExpectedPtrRet(m_srpVsTextLines);

    HRESULT hr = E_FAIL;

    // If the buffer is already dirty we do not check further
    DWORD dwFlags = 0;
    hr = m_srpVsTextLines->GetStateFlags(&dwFlags);
    IfFailRet(hr);
    if (dwFlags & BSF_MODIFIED) 
        return S_OK;

    // get the doc moniker 
    CComPtr<IVsUserData> srpIVsUserData;
    hr = m_srpVsTextLines->QueryInterface(IID_IVsUserData, (void**) &srpIVsUserData);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsUserData != NULL);

    CComVariant cvar;
    hr = srpIVsUserData->GetData(GUID_VsBufferMoniker, &cvar);
    IfFailRet(hr);
    ExpectedExprRet(cvar.vt == VT_BSTR);

    // get the text manager
    CComPtr<IVsTextManager> srpIVsTextManager;
    hr = _AtlModule.QueryService(
        SID_SVsTextManager, 
        IID_IVsTextManager, 
        (LPVOID *) &srpIVsTextManager);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsTextManager != NULL);

    int  iStatusFlags;
    BOOL fCheckoutSucceeded;
    hr = srpIVsTextManager->AttemptToCheckOutBufferFromScc2(
        /* [in ] const WCHAR * */ cvar.bstrVal,        // filename
        /* [out] BOOL *        */ &fCheckoutSucceeded, // whether the checkout succeeded
        /* [out] int *         */ &iStatusFlags);      // may be NULL; add'l status flags; 
    IfFailRet(hr);

    if (fCheckoutSucceeded)
        hr = S_OK;
    else
        hr = E_ABORT;

    return hr;
}


//==========================================================================
//                                                     IVsProvideUserContext

STDMETHODIMP CFigEditLine::GetUserContext (
    /* [out, retval] */ IVsUserContext** ppctx)
{
    ExpectedPtrRet(ppctx);
    *ppctx = NULL;

    HRESULT hr = S_OK;
    if (!m_srpIVsUserContext)
    {
        // create a user context
        hr = CreateUserContext(&m_srpIVsUserContext);
        IfFailRet(hr);
        ExpectedExprRet(m_srpIVsUserContext != NULL);

        hr = UpdateUserContext();
        IfFailRet(hr);
    }
        
    return m_srpIVsUserContext.CopyTo(ppctx);
}



STDMETHODIMP CFigEditLine::UpdateUserContext()
{
    if (!m_srpIVsUserContext)
        return S_FALSE;

    HRESULT hr = S_OK;

    // clean our user context
    hr = m_srpIVsUserContext->RemoveAttribute(NULL, NULL);
    IfFailRet(hr);

    hr = AddUserContextForFigLineType(m_srpIVsUserContext, m_Type);
    IfFailRet(hr);

    return S_OK;
}

//                                                     IVsProvideUserContext
//==========================================================================

// end of file EditLine.cpp