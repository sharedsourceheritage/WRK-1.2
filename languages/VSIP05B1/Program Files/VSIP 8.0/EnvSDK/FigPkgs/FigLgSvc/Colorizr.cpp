
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Colorizr.cpp : Implementation of CFigColorizer

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes


#define MAX_FIG_MARKS 100
CFigColorizer::CFigColorizer( IFigParse *pIFigParse, CFigBufferTaskProvider* pCFigBufferTaskProvider)
{
    ATLTRACE(TEXT(">> Constructing CFigColorizer: 0x%X\n"), this);
    m_dwRef = 0;
    m_fZombie = FALSE;
    m_srpParse = pIFigParse;  // NOTE: assignment to a smart pointer does an AddRef()

    // allocate a token array for our parser to fill
    m_pMks = new FIGMARK[ MAX_FIG_MARKS ];  // allocate an array of tokens

    m_pCFigBufferTaskProvider = pCFigBufferTaskProvider; 
    m_pCFigBufferTaskProvider->AddRef();
}

CFigColorizer::~CFigColorizer()
{
    ATLTRACE(TEXT(">> Destructing CFigColorizer: 0x%X\n"), this);

    if( m_pMks )
        delete[] m_pMks;  // free array of tokens
}


// *** IUnknown methods ***
STDMETHODIMP CFigColorizer::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;        // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigColorizer, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = (IVsColorizer *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsColorizer )
    {
        ATLTRACE(TEXT(">> CFigColorizer, received QI for IID_IVsColorizer.\n"));
        AddRef();
        *ppvObj = (IVsColorizer *) this;
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigColorizer::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigColorizer::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


// IVsColorizer methods:
STDMETHODIMP CFigColorizer::GetStateMaintenanceFlag( BOOL *pfFlag )
{
    if( NULL == pfFlag )
        return( E_INVALIDARG );
    *pfFlag = FALSE;
    return S_OK;
}

STDMETHODIMP CFigColorizer::GetStartState( long *piStartState )
{
    return S_OK;
}

// Colorize the given text.  For each character in the line of text
// given, a matching index into the colorizer's syntax item array (+1) should
// be placed in the color index array provided.  The colorizer should
// start in the state provided, and return its current state (which will
// be stored and provided as the start state when the following line is
// colorized).  The index array given is gauranteed to be ONE ELEMENT
// longer than the number of characters in the line.  This element is
// used to determine the (background) color of the space to the right of
// the last character on the line.
// Color indexes are 1-BASED -- use 0 to specify default text color.
// pText is NOT null-terminated.  iLength is the length of the line
// MINUS the end-of-line marker (CR, LF, CRLF pair, or 0 (EOF)), which
// will be present.
//
// NOTES:
// The color of each character in the line is specified by setting a 'value'
// in the provided pAttributes array.
// The 'value' is really an index into an array of possible ColorableItems.
// We are using values from the DEFAULTITEMS enum in textmgr.idl.
// Our sample language uses the stock set of color items (which can be changed
// in the options dialog). 
// It is possible to invent your own unique set of colors but you would need
// to implement IVsProvideColorableItems and IVsColorableItem. 
// 
STDMETHODIMP_(long) CFigColorizer::ColorizeLine( 
                        long iLine,                // line number
                        long iLength,            // length of line w/out EOL marker
                        const WCHAR *pText,        // line
                        long iState,            // current color state
                        ULONG *pAttributes )    // [out] provided color index array 
{
    HRESULT hr = NOERROR;
    //ATLTRACE(TEXT(">> CFigColorizer, ColorizeLine called.\n"));

    // set all colors to default or shell crashes
    if( NULL == pAttributes )
        return( E_INVALIDARG );
    memset( pAttributes, COLITEM_TEXT, (iLength + 1) * sizeof(ULONG));

    if( NULL == pText )
        return COLITEM_TEXT;
    if( iLength <= 0 )
        return COLITEM_TEXT;
    if( m_srpParse == NULL )
        return COLITEM_TEXT;

    long ncMarks = MAX_FIG_MARKS;
    if (!m_pMks)
        return E_UNEXPECTED;
    memset( m_pMks, 0, MAX_FIG_MARKS * sizeof( FIGMARK ));

    // null terminate the input line for our parser
    WCHAR *wszLine;
    wszLine = new WCHAR[ iLength + 1 ];
    if (!wszLine)
        return E_OUTOFMEMORY;    
    memset( wszLine, 0, ( iLength + 1 ) * sizeof( WCHAR ));
    wcsncpy( wszLine, pText, iLength );

    // call the Line method on the parse object
    BSTR bstrError = NULL;
    hr = m_srpParse->Line( wszLine, &ncMarks, &m_pMks, &bstrError );
    delete[] wszLine;

    if( ::SysStringLen(bstrError) > 0 ) {
        size_t cmb = wcstombs(NULL, bstrError, SysStringLen(bstrError)) + 1;
        CHAR *pch = new CHAR[ cmb ];
        if ( NULL != pch )
        {
            wcstombs( pch, bstrError, cmb );
            // ATLTRACE( ">> ERROR: %s\n", pch );
            delete[] pch;
        }
    } else if( hr == E_INVALIDARG )  // Line method failed, show error status
        ATLTRACE( ">> Invalid args passed to pParse->Line()\n" );    
    else if( hr == E_OUTOFMEMORY ) 
        ATLTRACE( ">> Too many tokens on the line.\n" );    
    SysFreeString( bstrError );     // free returned error BSTR

    // set color marks based on the parsed tokens
    long icMarks = 0;
    ULONG type;
    while( icMarks < ncMarks ) {
        // We color one of the following 6 ways, as defined in textmgr.idl
        //COLITEM_TEXT = 0,           // Default
        //COLITEM_KEYWORD,            // Keyword
        //COLITEM_COMMENT,            // Comment
        //COLITEM_IDENTIFIER,         // Identifier
        //COLITEM_STRING,             // String
        //COLITEM_NUMBER              // Number
        switch( m_pMks[ icMarks ].eTokenType ) {
        case eCommand:        type = COLITEM_KEYWORD;        break;
        case eType:            type = COLITEM_IDENTIFIER;    break;
        case eParameter:    type = COLITEM_NUMBER;        break;
        case eComment:        type = COLITEM_COMMENT;        break;
        default:            type = COLITEM_TEXT;
        }

        // color the token
        long iStart = m_pMks[ icMarks ].nStart;
        long iEnd = m_pMks[ icMarks ].nEnd;
        if( m_pMks[ icMarks ].eTokenType == eComment ) 
            iEnd = iLength;
        for( long i = iStart; i <= iEnd; i++ )
            pAttributes[ i ] = type;

        ++icMarks;
    }

    // The pAttributes array given is gauranteed to be ONE ELEMENT
    // longer than the number of characters in the line.  This element is
    // used to determine the (background) color of the space to the right of
    // the last character on the line.
    pAttributes[ iLength ] = pAttributes[ iLength - 1 ];

    return COLITEM_TEXT;  // return the current state 
}


STDMETHODIMP_(long) CFigColorizer::GetStateAtEndOfLine( 
                        long iLine,
                        long iLength,
                        const WCHAR *pText,
                        long iState )
{
    return 0;
}

STDMETHODIMP_(void) CFigColorizer::CloseColorizer( void )
{
    if( m_pMks ) {
        delete[] m_pMks;  // free array of tokens
        m_pMks = NULL;
    }
    m_pCFigBufferTaskProvider->UnInit();
    m_pCFigBufferTaskProvider->Release();
}


// end of file Colorizr.cpp
