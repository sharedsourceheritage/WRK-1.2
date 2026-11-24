
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// EditFact.cpp : Implementation of CFigEditorFactory

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes


CFigEditorFactory::CFigEditorFactory(
    /* [in] */ CVsPackage * pCVsPkg, 
    /* [in] */ BOOL fEncoding)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFigEditorFactory::CFigEditorFactory \n") );

    m_dwRef = 0;
    m_fZombie = FALSE;
    m_pCVsPkg = pCVsPkg;
    m_srpEdFactSiteSP = NULL;
    m_fEncoding = fEncoding;
}

CFigEditorFactory::~CFigEditorFactory()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFigEditorFactory::~CFigEditorFactory \n") );

}

/*****************************************************************************
** IUnknown Implementation
*****************************************************************************/
STDMETHODIMP CFigEditorFactory::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFigEditorFactory::QueryInterface \n") );

    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;     // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        AddRef();
        *ppvObj = (IVsEditorFactory *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsEditorFactory )
    {
        AddRef();
        *ppvObj = (IVsEditorFactory *) this;
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigEditorFactory::AddRef()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFigEditorFactory::AddRef \n") );

    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigEditorFactory::Release()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFigEditorFactory::Release \n") );

    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


/*****************************************************************************
** IVsEditorFactory Implementation
*****************************************************************************/

// An editor factory acts like an OLE ClassFactory for instantiating 
// document view objects (DocView) and document data objects (DocData). 
// The editor factory architecture enables creating editors that support 
// data/view separation (e.g. an editor could support the Window.NewWindow 
// functionality). The Shell helps coordinate tracking whether a document 
// is already open via a service called the RunningDocumentTable (a.k.a. RDT). 
// When an editor factory is asked to create a secondary view then 
// punkDocDataExisting will be non-NULL. This punkDocDataExisting must be 
// the punkDocData object that is registered in the RDT.
//
STDMETHODIMP CFigEditorFactory::CreateEditorInstance( 
    /*[in] */ VSCREATEEDITORFLAGS   grfCreateDoc,       // only open or silent is valid
    /*[in] */ LPCOLESTR             pszMkDocument,      // moniker file name
    /*[in] */ LPCOLESTR             pszPhysicalView,    // physical view name
    /*[in] */ IVsHierarchy*         pvHier,             // project
    /*[in] */ VSITEMID              itemid,
    /*[in] */ IUnknown*             punkDocDataExisting,// buffer already created ?
    /*[out]*/ IUnknown**            ppunkDocView,       // return our view
    /*[out]*/ IUnknown**            ppunkDocData,       // return our buffer
    /*[out]*/ BSTR*                 pbstrEditorCaption, // return our part of the caption [Custom] and [Readonly] if applicable
    /*[out]*/ GUID*                 pguidCmdUI,         // the package guid for our menus (in the .ctc file in the satelite dll too)
    /*[out]*/ VSEDITORCREATEDOCWIN* pgrfCDW)            // flags to be passed to CreateDocumentWindow
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFigEditorFactory::CreateEditorInstance \n") );
    
    USES_CONVERSION;
    if( m_fZombie )
        return E_UNEXPECTED;

    //if pszPhysicalView is null, make it the default: 
    LPCOLESTR pszLocalPhysicalView = NULL;
    if( !pszPhysicalView ) 
        pszLocalPhysicalView = L"Code";  // default view is Code (the std text view)
    else
        pszLocalPhysicalView = pszPhysicalView;

    HRESULT hr = S_OK;

    // perform parameter validation and initialization
    ExpectedPtrRet(pszMkDocument);
    ExpectedPtrRet(ppunkDocView);
    InitParam(ppunkDocView);
    ExpectedPtrRet(ppunkDocData);
    InitParam(ppunkDocData);
    ExpectedPtrRet(pbstrEditorCaption);
    InitParam(pbstrEditorCaption);
    ExpectedPtrRet(pguidCmdUI);
    InitParamTo(pguidCmdUI, GUID_NULL);
    ExpectedPtrRet(pgrfCDW);
    InitParamTo(pgrfCDW, NULL);

    // If we are the editor factory with encoding and the buffer already exist
    // then the doc should be closed before we try to open it with the
    // user-specified encoding
    if (m_fEncoding && punkDocDataExisting)
    {
        // return VS_E_INCOMPATIBLEDOCDATA - this will cause the shell 
        // to prompt the user whether to close the doc.
        // If the doc is closed, we will be called again to open it
        // with the user-specified encoding
        return VS_E_INCOMPATIBLEDOCDATA;
    }

    // only open or silent is valid
    if (! (grfCreateDoc & (CEF_OPENFILE | CEF_SILENT)) )
        return E_INVALIDARG;

    DWORD dwAttrs = GetFileAttributes(W2CT(pszMkDocument)); 
    BOOL fReadOnly = ( dwAttrs & FILE_ATTRIBUTE_READONLY );

    size_t cmb = wcstombs( NULL, pszLocalPhysicalView, wcslen( pszLocalPhysicalView ));
    string pmbcsPhysicalView;  // STL string template, free'd when out of scope
    pmbcsPhysicalView.resize( cmb );
    wcstombs( &pmbcsPhysicalView[0], pszLocalPhysicalView, cmb );

    ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
        _T(": CFigEditorFactory::CreateEditorInstance ")
        _T(": pszMkDocument= %s , pszLocalPhysicalView = %s\n"), 
        W2CT(pszMkDocument), W2CT(pszLocalPhysicalView) );

    // Create a text buffer if one is not passed to us
    //
    // If you look in textmgr.idl you will see that the
    // object described by 'coclass VsTextBuffer' has two interfaces.
    //
    // By looking at IVsTextLines you see it inherits from IVsTextBuffer
    // so by getting a pointer to IVsTextLines you can call all the methods
    // described by both interfaces.
    //
    CComPtr<IVsTextLines> srpTextLines;

    if( punkDocDataExisting == NULL ) 
    {   
        // we need to create a text buffer

        // get the ILocalRegistry interface so we can use it to
        // load the text buffer from the shell's local registry.
        //
        CComPtr<ILocalRegistry> srpLocalRegistry;
        hr = _AtlModule.QueryService( 
                    SID_SLocalRegistry, IID_ILocalRegistry, 
                    (void **)&srpLocalRegistry);
        IfFailRet(hr);

        // create buffer (does CoCreateInstance if not in shell's registry)
        hr = srpLocalRegistry->CreateInstance( 
                    CLSID_VsTextBuffer, NULL, IID_IVsTextLines, 
                    CLSCTX_INPROC_SERVER, 
                    (void **)&srpTextLines );
        IfFailRet(hr);

        // set the buffer's site
        CComPtr<IObjectWithSite> srpObjWSite;
        hr = srpTextLines->QueryInterface( IID_IObjectWithSite, (void **)&srpObjWSite );
        IfFailRet(hr);
        ExpectedExprRet(srpObjWSite != NULL);

        hr = srpObjWSite->SetSite( m_srpEdFactSiteSP );
        IfFailRet(hr);

        // if open with encoding, prompt the user to select the encoding
        if (m_fEncoding)
        {
            CComPtr<IVsUserData> srpIVsUserData;
            hr = srpTextLines->QueryInterface (IID_IVsUserData, (void **)&srpIVsUserData);
            IfFailRet(hr);

            VARIANTARG var;
            VariantInit(&var);
            var.vt = VT_UI4;
            var.ulVal = codepagePrompt;
            hr = srpIVsUserData->SetData(GUID_VsBufferEncodingPromptOnLoad, var);                                
            IfFailRet(hr);
        }

    } 
    else 
    {   
        // use the existing text buffer

        // QI existing buffer for text lines
        hr = punkDocDataExisting->QueryInterface( IID_IVsTextLines, 
                                                  (void **)&srpTextLines );
        if( FAILED( hr ))
        {
            // Let's give a useful error message if punkDocDataExisting is not compatible for us.
            m_pCVsPkg->SetErrorInfo( hr, IDS_E_INCOMPATABLEDOCDATA, 0 );
            return hr;
        }
    }

    // Create the editor view obj, if needed
    //
    CComPtr<IUnknown> srpIUnkEdView;
    if( !pmbcsPhysicalView.compare( "Form" )) 
    {   

        // let the view know we are attaching to an existing buffer
        BOOL fExistBuf = FALSE;
        if( punkDocDataExisting != NULL ) 
            fExistBuf = TRUE;

        // Create our 'Form' view, our custom editor
        CComPtr<IVsTextLinesEvents> srpView;
        CFigEditorView *pFigEditorView = NULL;
        srpView = pFigEditorView = new CFigEditorView( m_pCVsPkg, srpTextLines, fExistBuf ); // Note: assignment to a smart pointer does an AddRef()
        if( srpView == NULL ) 
            return E_OUTOFMEMORY;

        srpIUnkEdView = srpView;

        // setup editor caption. we do this by letting the TextBuffer actually 
        // manage the caption so that it can properly add the "[ReadOnly]" part.
        // we temporarily give the buffer the base part of our custom editor caption ("[Form]")
        // via the call to SetBaseEditorCaption(). we call GetEditorCaption to let the 
        // TextBuffer compose the window caption. we then restore the normal
        hr = m_pCVsPkg->GetLocalizedString( IDS_EDITFORM, pbstrEditorCaption );  // see FigPkgUI string table
        if( FAILED( hr ))
            *pbstrEditorCaption = SysAllocString( L" [Form]" ); // our contribution to the caption
        hr = pFigEditorView->SetBaseEditorCaption((LPCOLESTR*)pbstrEditorCaption);
        IfFailRet(hr);

        SysFreeString(*pbstrEditorCaption);
        *pbstrEditorCaption = NULL;
        hr = pFigEditorView->GetEditorCaption(fReadOnly ? ROSTATUS_ReadOnly : ROSTATUS_NotReadOnly, 
            pbstrEditorCaption);
        IfFailRet(hr);

        // The CmdUIGuid for our Form view is unique to our custom editor. This controls
        // which menus and command accelerators should be available.
        *pguidCmdUI = guidFigEditCmdUI;         // the package guid for our menus (in pkgicmd.h, used in the .ctc file in the satelite dll too)

    } 
    else if( !pmbcsPhysicalView.compare( "Code" )) 
    {   

        // Create a std code view (text)
        CComPtr<ILocalRegistry> srpLocalRegistry;
        hr = _AtlModule.QueryService( 
                    SID_SLocalRegistry, IID_ILocalRegistry, 
                    (void **)&srpLocalRegistry);
        IfFailRet(hr);

        // create code view (does CoCreateInstance if not in shell's registry)
        CComPtr<IVsCodeWindow> srpCodeWin;
        hr = srpLocalRegistry->CreateInstance( 
                    CLSID_VsCodeWindow, NULL, IID_IVsCodeWindow, 
                    CLSCTX_INPROC_SERVER, 
                    (void **)&srpCodeWin );
        IfFailRet(hr);

        srpIUnkEdView = srpCodeWin;

        // setup editor caption. we do this by letting the TextBuffer actually 
        // manage the caption so that it can properly add the "[ReadOnly]" part.
        // we give the buffer the base part of our editor caption ("[Code]")
        // via the call to SetBaseEditorCaption().
        hr = m_pCVsPkg->GetLocalizedString( IDS_EDITCODE, pbstrEditorCaption );  // see FigPkgUI string table
        if( FAILED( hr ))
            *pbstrEditorCaption = SysAllocString( L" [Code]" ); // our contribution to the caption
        hr = srpCodeWin->SetBaseEditorCaption((LPCOLESTR*)pbstrEditorCaption);
        IfFailRet(hr);

        SysFreeString(*pbstrEditorCaption);
        *pbstrEditorCaption = NULL;
        hr = srpCodeWin->GetEditorCaption(fReadOnly ? ROSTATUS_ReadOnly : ROSTATUS_NotReadOnly, 
            pbstrEditorCaption);
        IfFailRet(hr);

        // hook up the Code Window with the text buffer (DocData)
        hr = srpCodeWin->SetBuffer( srpTextLines );
        IfFailRet(hr);

        // The CmdUIGuid for our Code view is unique so we can use it in 
        // ToolWindows\{ToolGuid}\Visibility. 
        // In our code view we inherit the standard text editor key bindings
        // and show the standard text editor toolbar in the visibility
        // section
        *pguidCmdUI = guidFigCodeCmdUI;
    } 
    else 
    {
        return E_INVALIDARG;  // invalid Physical View param passed in.
    }


    // Return out params
    *ppunkDocData = srpTextLines.Detach();  // our doc data
    *ppunkDocView = srpIUnkEdView.Detach(); // our doc view
    *pgrfCDW = NULL;                        // we have no GUI the user could enter a cancel from

    return S_OK;
}


STDMETHODIMP CFigEditorFactory::SetSite( 
                    /*[in] */ IServiceProvider *pSP )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFigEditorFactory::SetSite \n") );

    ExpectedPtrRet(pSP);
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    m_srpEdFactSiteSP = pSP;        // Note: assignment to a smart pointer does an AddRef()

    return NOERROR;
}


STDMETHODIMP CFigEditorFactory::Close( void )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFigEditorFactory::Close \n") );

    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    m_fZombie = TRUE;

    m_srpEdFactSiteSP.Release();

    return NOERROR;
}


// This method is called before the CreateEditorInstance method
// to allow us to map LOGICAL views to PHYSICAL ones. Our Editor
// Factory supports two physical views:
//     1. a standard text editor view (our default/primary view)
//     2. a graphical "Form/Designer" view
//
// NOTE: Physical views are identified by a string of our choice with the 
// one constraint that the default/primary physical view for an editor  
// *MUST* use a NULL string as its physical view name (*pbstrPhysicalView = NULL).
//
// Our Editor Factory supports the following logical views which
// map to one of our physical views:
//
//     1. LOGVIEWID_Primary     maps to text editor view (used by Open/OpenWith cmd)
//     2. LOGVIEWID_Code        maps to text editor view (used by our Fig project View.Code cmd)
//     3. LOGVIEWID_TextView    maps to text editor view (used for find/replace)
//     4. LOGVIEWID_Debugging   maps to text editor view (used by debugger to open files)
//     5. LOGVIEWID_Designer    maps to custom editor view (used by our Fig project View.Form cmd)
//
STDMETHODIMP CFigEditorFactory::MapLogicalView( 
                    /*[in] */ REFGUID    rguidLogicalView,
                    /*[out]*/ BSTR      *pbstrPhysicalView )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFigEditorFactory::MapLogicalView \n") );

    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    if( !pbstrPhysicalView )
        return E_INVALIDARG;

    *pbstrPhysicalView = NULL;      // initialize out parameter

    if( rguidLogicalView == LOGVIEWID_Primary ||
        rguidLogicalView == LOGVIEWID_TextView ||
        rguidLogicalView == LOGVIEWID_Code ||
        rguidLogicalView == LOGVIEWID_Debugging )  // default/primary view 
        *pbstrPhysicalView = NULL;  // Physical view name for primary view must be NULL string
    else if( rguidLogicalView == LOGVIEWID_Designer )
        *pbstrPhysicalView = SysAllocString( L"Form" );
    else
        return E_NOTIMPL;   // we do not support this logical view

    return NOERROR;
}


// end of file EditFact.cpp
