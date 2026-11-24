
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// MethdTip.cpp : Implementation of CFigMethodData

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes


CFigMethodData::CFigMethodData( CVsPackage *pCVsPkg, IVsTextView *pView )
{
    ATLTRACE(TEXT(">> Constructing CFigMethodData: 0x%X\n"), this);
    m_dwRef = 0;
    m_fZombie = FALSE;
    m_fInit = FALSE;
    m_pCVsPkg = pCVsPkg;
    m_srpTextView = pView;        // Note: assignment to a smart pointer does an AddRef()
    m_MethodType = 0;
    m_curParam = 0;
    for( int i = 0; i < NUM_METHOD_TYPES; i++ ) {
        m_nParameters[ i ] = 0;
        m_MethodTexts[ i ] = NULL;
        for( int j = 0; j < MAX_NUM_PARAMS; j++ ) {
             m_ParamsTexts[ i ][ j ] = NULL;
        }
    }
}

CFigMethodData::~CFigMethodData()
{
    ATLTRACE(TEXT(">> Destructing CFigMethodData: 0x%X\n"), this);
    for( int i = 0; i < NUM_METHOD_TYPES; i++ ) {
        if( NULL != m_MethodTexts[ i ] ) {
            delete [] m_MethodTexts[ i ];
            m_MethodTexts[ i ] = NULL;
        }
        for( int j = 0; j < MAX_NUM_PARAMS; j++ ) {
            if( NULL != m_ParamsTexts[ i ][ j ] ) {
                delete [] m_ParamsTexts[ i ][ j ];
                m_ParamsTexts[ i ][ j ] = NULL;
            }
        }
    }
}

STDMETHODIMP CFigMethodData::Init()
{
    // load strings from localized satellite dll

    // method names: alloc and file with localized strings
    HRESULT hr = S_OK;
    if( m_fInit )
        return E_FAIL;    
    if( !m_pCVsPkg )
        return E_FAIL;    

    // description of the methods
    hr = GetDescription(IDS_METHOD1, &(m_MethodTexts[0]));
    if (FAILED(hr))
        goto OnError;
    hr = GetDescription(IDS_METHOD2, &(m_MethodTexts[1]));
    if (FAILED(hr))
        goto OnError;
    hr = GetDescription(IDS_METHOD3, &(m_MethodTexts[2]));
    if (FAILED(hr))
        goto OnError;

    // params for arrow: alloc and file with localized strings
    m_nParameters[0] = 0;
    hr = GetDescription(IDS_PARAM_SX, &(m_ParamsTexts[0][0]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[0];
    hr = GetDescription(IDS_PARAM_SY, &(m_ParamsTexts[0][1]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[0];
    hr = GetDescription(IDS_PARAM_EX, &(m_ParamsTexts[0][2]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[0];
    hr = GetDescription(IDS_PARAM_EY, &(m_ParamsTexts[0][3]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[0];

    // params for circle: alloc and file with localized strings
    m_nParameters[1] = 0;
    hr = GetDescription(IDS_PARAM_HC, &(m_ParamsTexts[1][0]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[1];
    hr = GetDescription(IDS_PARAM_VC, &(m_ParamsTexts[1][1]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[1];
    hr = GetDescription(IDS_PARAM_R, &(m_ParamsTexts[1][2]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[1];

    // params for rectangle: alloc and file with localized strings
    m_nParameters[2] = 0;
    hr = GetDescription(IDS_PARAM_L, &(m_ParamsTexts[2][0]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[2];
    hr = GetDescription(IDS_PARAM_T, &(m_ParamsTexts[2][1]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[2];
    hr = GetDescription(IDS_PARAM_W, &(m_ParamsTexts[2][2]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[2];
    hr = GetDescription(IDS_PARAM_H, &(m_ParamsTexts[2][3]));
    if (FAILED(hr))
        goto OnError;
    ++m_nParameters[2];

    hr = S_OK;
    m_fInit = TRUE;

OnError:
    if (FAILED(hr))
    {
        for( int i = 0; i < NUM_METHOD_TYPES; i++ ) {
            if( NULL != m_MethodTexts[i] ) 
            {
                delete[] m_MethodTexts[i];
                m_MethodTexts[i] = NULL;
            }
            for(int j = 0; j < MAX_NUM_PARAMS; j++ ) 
            {
                if(NULL != m_ParamsTexts[i][j]) 
                {
                    delete[] m_ParamsTexts[i][j];
                    m_ParamsTexts[i][j] = NULL;
                }
            }
        }
    }
    
    return hr;
}

STDMETHODIMP CFigMethodData::SetType( int type )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;

    m_MethodType = type;
    return S_OK;
}

STDMETHODIMP CFigMethodData::SetCurrentParam( long curParam )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;

    m_curParam = curParam;
    return S_OK;
}


// *** IUnknown methods ***
STDMETHODIMP CFigMethodData::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;        // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigMethodData, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = (IVsColorizer *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsMethodData )
    {
        ATLTRACE(TEXT(">> CFigMethodData, received QI for IID_IVsMethodData.\n"));
        AddRef();
        *ppvObj = (IVsMethodData *) this;
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigMethodData::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigMethodData::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


// *** IVsMethodData methods ******************************************************
//

STDMETHODIMP_(long) CFigMethodData::GetOverloadCount( void )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;

    return 0;    // no overloads
}

STDMETHODIMP_(const WCHAR *) CFigMethodData::GetMethodText(
                                /*[in] */ long iMethod, 
                                /*[in] */ MethodTextType type )
{
    if( m_fZombie )
        return NULL;        // recursion guard
    if( !m_fInit )
        return NULL;

    // Note that GetMethodText can return NULL for any of these types except NAME.
    // Any that it does not will be displayed.  Format is as follows:
    //  [TYPEPREFIX] [NAME] ( <parms> ) [TYPEPOSTFIX]
    //       [DESCRIPTION]
    // MTT_TYPEPREFIX,   // return type if prefixed, ala Java/C++ ("long foo()")
    // MTT_TYPEPOSTFIX,  // return type if postfixed, ala Basic ("foo() as long") (text must include "as" keyword)
    // MTT_NAME,         // Method name
    // MTT_DESCRIPTION   // Description of method (gets its own line)
    switch( type ) {
    case MTT_TYPEPREFIX:
    case MTT_TYPEPOSTFIX:
    case MTT_DESCRIPTION:
        return NULL;
    case MTT_NAME:
        return m_MethodTexts[ m_MethodType ];
    case MTT_OPENBRACKET:        
    case MTT_CLOSEBRACKET:
    case MTT_DELIMITER:
        return L" ";
    }

    return NULL;
}

STDMETHODIMP_(long) CFigMethodData::GetParameterCount(
                                /*[in] */ long iMethod )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;

    return m_nParameters[ m_MethodType ];    // only one method (no overloads)
}

STDMETHODIMP_(const WCHAR *) CFigMethodData::GetParameterText(
                                /*[in] */ long iMethod, 
                                /*[in] */ long iParm, 
                                /*[in] */ ParameterTextType type )
{
    if( m_fZombie )
        return NULL;        // recursion guard
    if( !m_fInit )
        return NULL;

    // Note that GetParameterText can return NULL for any except DECLARATION, and NAME if DESCRIPTION is non-NULL.
    // PTT_DECLARATION, // full decl as it appears in signature (i.e. "long x", or "x as long")
    // PTT_NAME,        // parameter name only (i.e. "x")
    // PTT_DESCRIPTION  // description (gets its own line, and is prefixed with NAME: (bolded))
    switch( type ) {
    case PTT_NAME:
    case PTT_DESCRIPTION:
        return NULL;
    case PTT_DECLARATION:
        return m_ParamsTexts[ m_MethodType ][ iParm ];
    }

    return NULL;
}

STDMETHODIMP_(long) CFigMethodData::GetCurrentParameter(
                                /*[in] */ long iMethod )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;

    return m_curParam;
}

STDMETHODIMP_(HRESULT) CFigMethodData::GetContextStream(
                                /*[out]*/ long *piPos, 
                                /*[out]*/ long *piLength )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;
    if( NULL==piLength )
        return E_POINTER;
    if( NULL==piPos )
        return E_POINTER;

    HRESULT hr;
    long iLine, iCol;
    hr = m_srpTextView->GetCaretPos( &iLine, &iCol );
    long vspace;
    hr = m_srpTextView->GetNearestPosition( iLine, iCol, piPos, &vspace );
    *piLength = 0;
    return S_OK;
}

STDMETHODIMP_(void) CFigMethodData::OnDismiss( void )
{
    if( m_fZombie )
        return;        // recursion guard
    if( !m_fInit )
        return;
}

STDMETHODIMP_(long) CFigMethodData::GetCurMethod( void )
{
    if( m_fZombie )
        return 0;        // recursion guard
    if( !m_fInit )
        return 0;

    return 0;        // no overloads
}

STDMETHODIMP_(void) CFigMethodData::UpdateView( void )
{
    if( m_fZombie )
        return;        // recursion guard
    if( !m_fInit )
        return;
}

STDMETHODIMP_(long) CFigMethodData::NextMethod( void )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;

    return 0;        // no overloads
}

STDMETHODIMP_(long)  CFigMethodData::PrevMethod( void )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;

    return 0;        // no overloads
}

// Private helper function to load method's description from the resource dll.
HRESULT CFigMethodData::GetDescription(
                /* [in]  */ int resourceID,
                /* [out] */ WCHAR ** pString)
{
    if (NULL == pString)
        return E_POINTER;
    HRESULT hr = S_OK;
    CComBSTR cbstrText;
    hr = m_pCVsPkg->GetLocalizedString(resourceID, &cbstrText);  // see FigPkgUI string table
    if (FAILED(hr))
        return hr;
    int cchText = cbstrText.Length();
    *pString = new WCHAR[ cchText + 1 ];
    if ( NULL == *pString)
    {
        return E_OUTOFMEMORY;
    }
    wcsncpy(*pString, cbstrText, cchText);
    (*pString)[cchText] = L'\0';

    return hr;
}


// end of file MethdTip.cpp
