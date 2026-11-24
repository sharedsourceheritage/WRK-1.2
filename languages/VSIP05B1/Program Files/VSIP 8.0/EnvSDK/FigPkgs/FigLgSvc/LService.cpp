
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// LService.cpp : Implementation of CFigLanguageService

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes


CFigLanguageService::CFigLanguageService( CVsPackage *pCVsPkg )
{
    ATLTRACE(TEXT(">> Constructing CFigLanguageService: 0x%X\n"), this);
    m_dwRef = 0;
    m_fZombie = FALSE;
    m_pCVsPkg = pCVsPkg;
    m_srpParse = NULL;
    m_srpUserCtx = NULL;
}

CFigLanguageService::~CFigLanguageService()
{
    ATLTRACE(TEXT(">> Destructing CFigLanguageService: 0x%X\n"), this);
}


// *** IUnknown methods ***
STDMETHODIMP CFigLanguageService::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;        // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigLanguageService, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = static_cast<IVsLanguageInfo*>(this);
        return NOERROR;
    }
    else if( riid == IID_IVsLanguageInfo )
    {
        ATLTRACE(TEXT(">> CFigLanguageService, received QI for IID_IVsLanguageInfo.\n"));
        AddRef();
        *ppvObj = (IVsLanguageInfo *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsProvideUserContextForObject )
    {
        ATLTRACE(TEXT(">> CFigLanguageService, received QI for IID_IVsProvideUserContextForObject.\n"));
        AddRef();
        *ppvObj = (IVsProvideUserContextForObject *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsLanguageContextProvider )
    {
        ATLTRACE(TEXT(">> CFigLanguageService, received QI for IID_IVsLanguageContextProvider.\n"));
        AddRef();
        *ppvObj = static_cast<IVsLanguageContextProvider*>(this);
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigLanguageService::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigLanguageService::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


// IVsLanguageInfo methods:
STDMETHODIMP CFigLanguageService::GetLanguageName( BSTR *bstrName )
{
    HRESULT hr = E_INVALIDARG;
    if (NULL != bstrName)
    {
        // get a localize string
        hr = m_pCVsPkg->GetLocalizedString( IDS_LANGUAGE_NAME, bstrName );  // see FigPkgUI string table

        if( FAILED( hr ))
            *bstrName = ::SysAllocString( L"Figure" );

         hr = S_OK;
        if( !*bstrName )
            hr = E_OUTOFMEMORY;
    }
    return hr;
}

STDMETHODIMP CFigLanguageService::GetFileExtensions( BSTR *bstrExtensions )
{
    HRESULT hr = E_INVALIDARG;
    if (bstrExtensions != NULL)
    {
        *bstrExtensions = ::SysAllocString( L".fig" );
        hr = S_OK;
        if( !*bstrExtensions )
            hr = E_OUTOFMEMORY;
    }
    return hr;
}

STDMETHODIMP CFigLanguageService::GetColorizer( 
                        IVsTextLines *pBuffer,            // [in]
                        IVsColorizer **ppColorizer )    // [out]
{
    // This is a convienent place to load the parser object,
    // which is handed to each of the language services that need
    // it.

    // get the ILocalRegistry interface so we can use it to
    // load the COM parser from the shell's local registry.
    //
    HRESULT hr = NOERROR;
    if (! m_srpParse)
    {
        hr = InitFigParser();
        if( FAILED( hr ))
            return hr;
    }
    ExpectedExprRet(m_srpParse != NULL);
    ExpectedPtrRet(ppColorizer);
    ExpectedPtrRet(pBuffer);

    // create a buffer task provider obj.  (one per buffer)
    //
    CFigBufferTaskProvider *pBufTaskProv;
    pBufTaskProv = new CFigBufferTaskProvider( m_pCVsPkg, pBuffer, m_srpParse );
    if( !pBufTaskProv )
        return E_OUTOFMEMORY;
    pBufTaskProv->AddRef();
    hr = pBufTaskProv->Init();
    if( FAILED( hr ))
        goto Error;

    // create the requested colorizer object and hand back it's IVsColorizer interface
    //
    *ppColorizer = new CFigColorizer(m_srpParse, pBufTaskProv);  // return the colorizer interface on a new object
    if( !*ppColorizer )
    {
        hr = E_OUTOFMEMORY;
        goto Error;
    }
    (*ppColorizer)->AddRef();            // return object with ref count of 1

Error:
    pBufTaskProv->Release();
    return hr;
}

// Create and hand back a pointer to the code window manager.
// It participates in per-view filtering for statement completion and method tips.
//
STDMETHODIMP CFigLanguageService::GetCodeWindowManager( 
                        /*[in]*/  IVsCodeWindow  *pCodeWin,
                        /*[out]*/ IVsCodeWindowManager  **ppCodeWinMgr )
{
    HRESULT hr = NOERROR;

    ExpectedPtrRet(ppCodeWinMgr);
    ExpectedPtrRet(pCodeWin);
    *ppCodeWinMgr = new CFigCodeWindowManager( m_pCVsPkg, pCodeWin );  // return the CodeWindowManager interface on a new object
    if( !*ppCodeWinMgr )
        return E_OUTOFMEMORY;
    (*ppCodeWinMgr)->AddRef();            // return object with ref count of 1

    return hr;  
}


STDMETHODIMP CFigLanguageService::InitFigParser()
{
    HRESULT hr = S_OK;
    if (m_srpParse != NULL)
        return S_FALSE;

    CComPtr<ILocalRegistry>    srpLocalRegistry;
    hr = _AtlModule.QueryService(SID_SLocalRegistry, IID_ILocalRegistry, (void **)&srpLocalRegistry);
    if( FAILED( hr ))
        return hr;

    // create our parser object (does CoCreateInstance if not in shell's registry)
    hr = srpLocalRegistry->CreateInstance( 
                CLSID_FigParse, NULL, IID_IFigParse, CLSCTX_INPROC_SERVER, 
                (LPVOID*)&m_srpParse );
    if( FAILED( hr ))
        return hr;

    return hr;
}


//==========================================================================
//                                               User Context Window support
//
STDMETHODIMP CFigLanguageService::GetObjectContext(
    /* [in]          */ IUnknown*        punk,
    /* [out, retval] */ IVsUserContext** ppctx)
{
    HRESULT hr = S_OK;

    ASSERT(ppctx);
    IfFalseGo(ppctx, E_POINTER);
    *ppctx = NULL;

    if ( !m_srpUserCtx ) 
    {
        // Create context bag for Context window if it hasn't already been created
        CComPtr<IVsMonitorUserContext> srpmuc;
        
        // Get a pointer to the VsMonitorContextService
        IfFailGo(_AtlModule.QueryService(SID_SVsMonitorUserContext,IID_IVsMonitorUserContext,reinterpret_cast<void**>(&srpmuc)));
        IfFalseGo((srpmuc!=NULL), E_POINTER);
        
        // Create a new empty context bag
        IfFailGo(srpmuc->CreateEmptyContext(&m_srpUserCtx));    
        IfFalseGo((m_srpUserCtx!=NULL), E_POINTER);
            
        // Add our attribute name and value to the context bag
        IfFailGo(m_srpUserCtx->AddAttribute (VSUC_Usage_Filter, L"DevLang", L"vs.envsdk.figure"));

    }
    *ppctx = m_srpUserCtx;
    (*ppctx)->AddRef();

Error:
    return hr;            
};


STDMETHODIMP CFigLanguageService::UpdateLanguageContext(
    DWORD dwHint,                   // ORing of LanguageContextHint enum values
    IVsTextLines *pBuffer,          // buffer in question
    TextSpan *ptsSelection,         // relevant range of text
    IVsUserContext *pUC)            // context to update
{
    ExpectedPtrRet(pBuffer);
    ExpectedPtrRet(ptsSelection);
    ExpectedPtrRet(pUC);

    HRESULT hr = S_OK;
    ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
        _T(": CFigLanguageService::UpdateLanguageContext : ")
        _T("hint: %d, Selection: (%d,%d)-(%d,%d)\n"), 
              dwHint, ptsSelection->iStartLine, ptsSelection->iStartIndex, 
                      ptsSelection->iEndLine,   ptsSelection->iEndIndex);

    // Note that the hint may be used to distinguish between F1 lookup
    // and regular lookup
    // We will not perform different processing for now
    
    // clean the bag first
    pUC->RemoveAttribute(NULL,NULL);

    // check if we have the parser
      if (! m_srpParse)
    {
        hr = InitFigParser();
        IfFailRet(hr);
    }
    ExpectedExprRet(m_srpParse != NULL);

    // Let's parse the selection and give the context the attributes
    long iLine = 0;
    for (  iLine = ptsSelection->iStartLine; 
           iLine <= ptsSelection->iEndLine; 
           iLine++)
    {
        // get the line type
        FigLineType flt = FigInvalid;
        long lP1 = 0;
        long lP2 = 0;
        long lP3 = 0;
        long lP4 = 0;
        CComBSTR cbstrComment;

        hr = m_srpParse->ParseLine(pBuffer, iLine, &flt, &lP1, &lP2, &lP3, &lP4, &cbstrComment);
        IfFailRet(hr);

        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigLanguageService::UpdateLanguageContext : ")
            _T(", this = 0x%x, line = %d, flt=%d, lP1=%d, lP2=%d, lP3=%d,lP4=%d \n"), 
            this, iLine, flt, lP1, lP2, lP3, lP4);

        if ( (flt < FigArrow) || (flt >= FigInvalid) )
            continue;

        // add the keywords
        switch (flt)
        {
            case FigArrow:
                hr = pUC->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.arrow");
                break;
            case FigCircle:
                hr = pUC->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.circle");
                break;
            case FigRectangle:
                hr = pUC->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.rectangle");
                break;
            case FigComment:
                hr = pUC->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.comment");
                break;
            default:
                ASSERT(FALSE); // unknown flt type
        }
    }

    return hr;
}

//                                               User Context Window support
//==========================================================================

// end of file LService.cpp