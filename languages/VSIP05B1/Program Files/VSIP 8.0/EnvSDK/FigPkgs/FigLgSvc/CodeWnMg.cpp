
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// CodeWnMg.cpp : Implementation of CFigCodeWindowManager and CFigTextViewFilter

#include "stdafx.h"     // system includes
#include "PrjInc.h"     // project includes
#include "stdidcmd.h"   // CommandSet ID definitions

#define MAX_FIG_MARKS 100


CFigCodeWindowManager::CFigCodeWindowManager( CVsPackage *pCVsPkg, IVsCodeWindow *pCodeWin )
{
    ATLTRACE(TEXT(">> Constructing CFigCodeWindowManager: 0x%X\n"), this);
    m_dwRef = 0;
    m_fZombie = FALSE;
    m_srpCodeWindow = pCodeWin;     // Note: assignment to a smart pointer does an AddRef()
    m_pCVsPkg = pCVsPkg;
}

CFigCodeWindowManager::~CFigCodeWindowManager()
{
    ATLTRACE(TEXT(">> Destructing CFigCodeWindowManager: 0x%X\n"), this);

    // free the list of textview objs we created.
    for( listTextView_type::iterator pos = m_listViews.begin(); 
         pos != m_listViews.end(); 
         pos++ ) 
    {
        (*pos)->UnInit();
        (*pos)->Release();  // should be final release which destroys text veiw filter
    }

    ASSERT (m_srpIVsDocOutlineProvider == NULL);
    ASSERT (m_srpIFigOutline == NULL);

}


// *** IUnknown methods ***
STDMETHODIMP CFigCodeWindowManager::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;     // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigCodeWindowManager, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = (IVsColorizer *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsCodeWindowManager )
    {
        ATLTRACE(TEXT(">> CFigCodeWindowManager, received QI for IID_IVsCodeWindowManager.\n"));
        AddRef();
        *ppvObj = (IVsCodeWindowManager *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsDocOutlineProvider )
    {
        ATLTRACE(TEXT(">> CFigCodeWindowManager, received QI for IID_IVsDocOutlineProvider.\n"));
        AddRef();
        *ppvObj = (IVsDocOutlineProvider *) this;
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigCodeWindowManager::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigCodeWindowManager::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


// IVsCodeWindowManager methods:

// Called by a code window to provide opportunity to add adornments
// (additional split panes) to the code window, etc.
STDMETHODIMP CFigCodeWindowManager::AddAdornments()
{
    // call on new view ourselves for the current view
    HRESULT hr = S_OK;
    CComPtr<IVsTextView> srpTV;
    if( SUCCEEDED( m_srpCodeWindow->GetPrimaryView( &srpTV )))
        OnNewView( srpTV );
    else
        _ASSERTE( FALSE );  // If there's no view, we shouldn't have been
                            // asked to adorn nothing...

    // get a doc outline provider
    if (m_srpIVsDocOutlineProvider == NULL) 
    {
        if (m_srpIFigOutline == NULL)
        {
            // get the service
            hr = _AtlModule.QueryService(
                            SID_SFigOutline, 
                            IID_IFigOutline, 
                            (void**)&m_srpIFigOutline);
            IfFailGo(hr);
            _ASSERTE (m_srpIFigOutline != NULL);

            CComPtr<IVsTextLines> srpIVsTextLines;
            hr = m_srpCodeWindow->GetBuffer(&srpIVsTextLines);
            ASSERT(SUCCEEDED(hr));

            HWND hwndParent = srpTV->GetWindowHandle();
            _ASSERTE(hwndParent);

            hr = m_srpIFigOutline->Init(srpIVsTextLines, hwndParent, srpTV);
            IfFailGo(hr);
        }

        hr = m_srpIFigOutline->QueryInterface(
                        IID_IVsDocOutlineProvider,
                        (void**) &m_srpIVsDocOutlineProvider);
        IfFailGo(hr);
    }

    {
        // retrieve the IServiceProvider from the code window
        CComPtr<IServiceProvider> srpIServiceProvider;
        hr = m_srpCodeWindow->QueryInterface(
                                  IID_IServiceProvider,
                                  (void**)&srpIServiceProvider);
        IfFailGo(hr);

        CComPtr<IVsWindowFrame> srpFrame;
        // inherit the keybindings of the standard text editor
        hr = srpIServiceProvider->QueryService(SID_SVsWindowFrame, IID_IVsWindowFrame,
                                       (void**)&srpFrame);
        IfFailGo(hr);
        hr = srpFrame->SetGuidProperty(VSFPROPID_InheritKeyBindings, CMDUIGUID_TextEditor);
        _ASSERTE(SUCCEEDED(hr));
    }

Error:

    srpTV.Release();
    if( SUCCEEDED( m_srpCodeWindow->GetSecondaryView( &srpTV )))
        OnNewView( srpTV );

    return S_OK;
}

// The language has changed, or the code window is going away; this
// code win mgr needs to now remove its adornments
STDMETHODIMP CFigCodeWindowManager::RemoveAdornments()
{
    // take our view out of the command target chain
    for( listTextView_type::iterator pos = m_listViews.begin(); 
                                pos != m_listViews.end(); pos++ )
        (*pos)->m_srpTextView->RemoveCommandFilter( (*pos) );

    // close the doc outline provider
    m_srpIVsDocOutlineProvider.Release();

    if (m_srpIFigOutline)
        m_srpIFigOutline->Close();
    m_srpIFigOutline.Release();

    return S_OK;
}

// A new text view has been created in the code window; now's your
// chance to provide a filter for it.
STDMETHODIMP CFigCodeWindowManager::OnNewView( /*[in]*/ IVsTextView *pView )
{
    HRESULT hr = NOERROR;

    ExpectedPtrRet(pView);
    CFigTextViewFilter *pTextViewFilter;
    pTextViewFilter = new CFigTextViewFilter( m_pCVsPkg, pView );
    if( !pTextViewFilter )
        return E_OUTOFMEMORY;
    pTextViewFilter->AddRef();          // ref count of 1
    hr = pTextViewFilter->Init();
    if( FAILED( hr ))
    {
        pTextViewFilter->Release();
        return hr;
    }

    m_listViews.insert( m_listViews.begin(), pTextViewFilter ); // insert into linked list

    return hr;
}


//IVsDocOutlineProvider
STDMETHODIMP CFigCodeWindowManager::GetOutlineCaption(
    /*[in] */ VSOUTLINECAPTION nCaptionType, 
    /*[out]*/ BSTR* pbstrCaption)
{
    if (m_srpIVsDocOutlineProvider != NULL)
        return m_srpIVsDocOutlineProvider->GetOutlineCaption(nCaptionType, pbstrCaption);

    return E_UNEXPECTED;
}


STDMETHODIMP CFigCodeWindowManager::GetOutline(
    /*[out]*/ HWND* phwnd, 
    /*[out]*/ IOleCommandTarget** ppCmdTarget)
{
    if (m_srpIVsDocOutlineProvider != NULL)
        return m_srpIVsDocOutlineProvider->GetOutline(phwnd, ppCmdTarget);

    return E_UNEXPECTED;

}


STDMETHODIMP CFigCodeWindowManager::ReleaseOutline(
    /*[in]*/ HWND hwnd, 
    /*[in]*/ IOleCommandTarget* pCmdTarget)
{
    if (m_srpIVsDocOutlineProvider != NULL)
        return m_srpIVsDocOutlineProvider->ReleaseOutline(hwnd, pCmdTarget);

    return E_UNEXPECTED;
}


STDMETHODIMP CFigCodeWindowManager::OnOutlineStateChange(
    /*[in]*/ VSOUTLINESTATES dwMask, 
    /*[in]*/ VSOUTLINESTATES dwState)
{
    if (m_srpIVsDocOutlineProvider != NULL)
        return m_srpIVsDocOutlineProvider->OnOutlineStateChange(dwMask, dwState);

    return E_UNEXPECTED;
}



////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
// CFigTextViewFilter

CFigTextViewFilter::CFigTextViewFilter( CVsPackage *pCVsPkg, IVsTextView *pView )
{
    ATLTRACE(TEXT(">> Constructing CFigTextViewFilter: 0x%X\n"), this);
    m_dwRef = 0;
    m_fZombie = FALSE;
    m_fInit = FALSE;
    m_srpNextCmdTarg = NULL;
    m_pCVsPkg = pCVsPkg;
    m_srpTextView = pView;      // Note: assignment to a smart pointer does an AddRef()
    m_pMks = NULL;  
    m_fTipWinDisplayed = FALSE;
}

CFigTextViewFilter::~CFigTextViewFilter()
{
    ATLTRACE(TEXT(">> Destructing CFigTextViewFilter: 0x%X\n"), this);

    m_pMethodData->Release();       // release our method data obj

    if( m_pMks )
        delete[] m_pMks;     // free array of tokens
}

STDMETHODIMP CFigTextViewFilter::UnInit()
{
    if( !m_fInit )
        return E_FAIL;  

    // unadvise IVsTextViewEvents from view
    HRESULT hr;
    CComPtr<IConnectionPointContainer> srpConPtCont;
    hr = m_srpTextView->QueryInterface( IID_IConnectionPointContainer,
                                            (void **)&srpConPtCont );
    if( SUCCEEDED( hr ))
    {
        CComPtr<IConnectionPoint> srpConPt;
        hr = srpConPtCont->FindConnectionPoint( IID_IVsTextViewEvents,
                                            &srpConPt );
        if( SUCCEEDED( hr ))
        {
            hr = srpConPt->Unadvise( m_dwTextViewEventsCookie );
        }
    }

    return hr;
}

STDMETHODIMP CFigTextViewFilter::Init()
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    // keep a ptr to the text buffer
    HRESULT hr = S_OK;
    hr = m_srpTextView->GetBuffer( &m_srpTextLines );
    if( FAILED( hr ))
        return hr;

    // get the intf. ptr. to the CFigBufferTaskProvider from the
    // VsTextBuffer's VsUserData object so we can call
    // IFigTaskManager::CreateTask()
    //
    CComPtr<IVsUserData> srpUserData;
    hr = m_srpTextLines->QueryInterface( IID_IVsUserData, (void **)&srpUserData );
    if( FAILED( hr ))
        return hr;
    CComVariant svPtr;
    srpUserData->GetData( GUID_BufferTaskProvider, &svPtr );
    if( VT_UNKNOWN != svPtr.vt || NULL == svPtr.punkVal )
        return E_FAIL;
    hr = svPtr.punkVal->QueryInterface( IID_IFigTaskManager, (void **)&m_srpTaskManager );
    if( FAILED( hr ))
        return hr;

    // create a statement completion object
    CFigStatementCompletion* pSC = new CFigStatementCompletion( m_pCVsPkg, m_srpTextView );
    if( NULL == pSC )
        return E_OUTOFMEMORY;
    m_srpCompletionSet = pSC;   // Note: assignment to a smart pointer does an AddRef()

    // create a method data object
    m_pMethodData = new CFigMethodData( m_pCVsPkg, m_srpTextView );
    if( NULL == m_pMethodData )
        return E_OUTOFMEMORY;
    m_pMethodData->AddRef();
    hr = m_pMethodData->Init();
    if( FAILED( hr ))
        return hr;

    // get a parser
    // get the ILocalRegistry interface so we can use it to
    // load the COM parser from the shell's local registry.
    //
    CComPtr<ILocalRegistry> srpLocalRegistry;
    hr = _AtlModule.QueryService( 
                SID_SLocalRegistry, IID_ILocalRegistry, 
                (void **)&srpLocalRegistry );
    if( FAILED( hr ))
        return hr;

    // create our parser object (does CoCreateInstance if not in shell's registry)
    hr = srpLocalRegistry->CreateInstance( 
                CLSID_FigParse, NULL, IID_IFigParse, CLSCTX_INPROC_SERVER, 
                (LPVOID*)&m_srpParse );
    if( FAILED( hr ))
        return hr;

    // create a method tip window  
    hr = srpLocalRegistry->CreateInstance( 
                CLSID_VsMethodTipWindow, NULL, IID_IVsMethodTipWindow, CLSCTX_INPROC_SERVER, 
                (LPVOID*)&m_srpMethodTipWindow );
    if( FAILED( hr ))
        return hr;

    // give the method tip window object the method data object it will use
    // when update is called.
    hr = m_srpMethodTipWindow->SetMethodData( 
                    static_cast<IVsMethodData*>( m_pMethodData ));
    if( FAILED( hr ))
        return hr;

    // allocate an array of tokens for the parser
    m_pMks = new FIGMARK[ MAX_FIG_MARKS ];  
    if( NULL == m_pMks )
        return E_OUTOFMEMORY;

    // hook ourselves into the command target chain
    hr = m_srpTextView->AddCommandFilter( this, &m_srpNextCmdTarg );
    if( FAILED( hr ))
        return hr;

    // setup an IVsTextViewEvents advise on the view, intf is impl on this view filter obj.
    CComPtr<IConnectionPointContainer> srpConPtCont;
    hr = m_srpTextView->QueryInterface( IID_IConnectionPointContainer,
                                            (void **)&srpConPtCont );
    if( FAILED( hr ))
        return hr;
    CComPtr<IConnectionPoint> srpConPt;
    hr = srpConPtCont->FindConnectionPoint( IID_IVsTextViewEvents,
                                            &srpConPt );
    if( FAILED( hr ))
        return hr;
    hr = srpConPt->Advise( static_cast<IVsTextViewEvents*>(this), 
                            &m_dwTextViewEventsCookie );
    if( FAILED( hr ))
        return hr;


    if( m_fInit )
        return E_FAIL;  
    m_fInit = TRUE;

    return hr;
}


// *** IUnknown methods ***
STDMETHODIMP CFigTextViewFilter::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;     // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigTextViewFilter, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = (IVsColorizer *) this;
        return NOERROR;
    }
    else if( riid == IID_IOleCommandTarget )
    {
        ATLTRACE(TEXT(">> CFigTextViewFilter, received QI for IID_IOleCommandTarget.\n"));
        AddRef();
        *ppvObj = (IOleCommandTarget *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsTextViewEvents )
    {
        ATLTRACE(TEXT(">> CFigTextViewFilter, received QI for IID_IVsTextViewEvents.\n"));
        AddRef();
        *ppvObj = (IVsTextViewEvents *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsTextViewFilter )
    {
        ATLTRACE(TEXT(">> CFigTextViewFilter, received QI for IID_IVsTextViewFilter.\n"));
        AddRef();
        *ppvObj = (IVsTextViewFilter *) this;
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigTextViewFilter::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigTextViewFilter::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


// IOleCommandTarget Implementation
//
HRESULT CFigTextViewFilter::QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;

    _ASSERTE( NULL != pguidCmdGroup );
    ExpectedPtrRet(pguidCmdGroup);
    ExpectedPtrRet(prgCmds);

    if( guidEditPkg == *pguidCmdGroup )
    {
        _ASSERTE( 1 == cCmds ); // we get a call for every command
        _ASSERTE( NULL != prgCmds );

        BOOL fEnable = FALSE;

        switch( prgCmds[0].cmdID )  // enable/disable only commands which differ for us from the default
        {
        case icmdAddArrow:
        case icmdAddCircle:
        case icmdAddComment:
        case icmdAddRectangle:
            // get the current cursor column
            long    nLine;
            ViewCol nCol, nCols;
            if( FAILED( m_srpTextView->GetCaretPos( &nLine, &nCol ) )
             || FAILED( m_srpTextLines->GetLengthOfLine( nLine, &nCols ) )
             || 0 == nCol   // Enable this option if column is 0 or last on line or we can't tell
             || nCol == nCols )
                prgCmds[0].cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
            else
                prgCmds[0].cmdf = OLECMDF_SUPPORTED;
            break;
        default:
            prgCmds[0].cmdf = OLECMDF_DEFHIDEONCTXTMENU | OLECMDF_SUPPORTED | OLECMDF_INVISIBLE;
        }
        return NOERROR;
    }
    else if( CMDSETID_StandardCommandSet2K == *pguidCmdGroup)
    {
        switch( prgCmds[0].cmdID )
        {
            case ECMD_SHOWMEMBERLIST:
            case ECMD_COMPLETEWORD:
              prgCmds[0].cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
              return S_OK;

            default:
            //fall through
            ;
        }
    }

    // pass this cmd on to next in chain (the view so it will show up)
    return m_srpNextCmdTarg->QueryStatus( pguidCmdGroup, cCmds, prgCmds, pCmdText );
}

// NOTE: pass on the commands we don't use to m_srpNextCmdTarg
//       otherwise they wont show up in the view.  Cmd Targs are CHAINED.
//
HRESULT CFigTextViewFilter::Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANT *pvaIn, VARIANT *pvaOut)
{

    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard
    if( !m_fInit )
        return E_UNEXPECTED;

    HRESULT hr = NOERROR;
    BOOL fHandled = TRUE;

    _ASSERTE( NULL != pguidCmdGroup );
    ExpectedPtrRet(pguidCmdGroup);
    if( guidEditPkg == *pguidCmdGroup )
    {
        // The IOleCommandTarget::Exec handler should take care of reporting
        // error messages to the user that occur in the execution of a command.
        // The convention is that the function that calls ReportErrorInfo()
        // should clear any cached error message before calling the functions
        // that could possibly generate errors.
        m_pCVsPkg->SetErrorInfo(NOERROR, NULL, 0);
        long    nLine;
        ViewCol nCol, nCols;
        if( SUCCEEDED( hr = m_srpTextView->GetCaretPos( &nLine, &nCol ) )
         && SUCCEEDED( hr = m_srpTextLines->GetLengthOfLine( nLine, &nCols ) ) )
        {
            CComBSTR    bstrCode;

            if( 0 != nCol ) // Appending to end of a line?
                bstrCode = "\n";
            switch( nCmdID )
            {
            case icmdAddArrow:
                bstrCode += "draw arrow 0 0 0 0 'Arrow";
                break;
            case icmdAddCircle:
                bstrCode += "draw circle 0 0 0 'Circle";
                break;
            case icmdAddComment:
                bstrCode += "'";
                break;
            case icmdAddRectangle:
                bstrCode += "draw rectangle 0 0 0 0 'Rectangle";
                break;
            default:
                return NOERROR; // we don't support this command from our custom menu
            }
            // handle the special case of inserting to last line in the buffer:
            long nLines;
            hr = m_srpTextLines->GetLineCount( &nLines );
            if( SUCCEEDED( hr ) )
            {
                _ASSERTE( nLines > 0 );
                if( 0 == nCol   // Not appending to last line?
                 && ( nLine + 1 < nLines || 0 < nCols ) )
                    bstrCode += "\n";

                // Inserts the specified span of text
                TextSpan ts;
                hr = m_srpTextLines->ReplaceLines(
                    nLine,              // starting line
                    nCol,               // starting character index within the line (must be <= length of line)
                    nLine,              // ending line
                    nCol,               // ending character index within the line (must be <= length of line)
                    bstrCode,           // new line text to insert
                    bstrCode.Length(),  // # of chars to insert, if any
                    &ts );              // range of characters changed
            }
        }
        // Display any error message to the user and then reset the returned "hr"
        // to NOERROR because the error has been handled.
        if( FAILED( hr ))
            m_pCVsPkg->ReportErrorInfo( hr );
        return NOERROR;
    }
    else if( CMDSETID_StandardCommandSet2K == *pguidCmdGroup )
    {
        // The IOleCommandTarget::Exec handler should take care of reporting
        // error messages to the user that occur in the execution of a command.
        // The convention is that the function that calls ReportErrorInfo()
        // should clear any cached error message before calling the functions
        // that could possibly generate errors.
        m_pCVsPkg->SetErrorInfo(NOERROR, NULL, 0);  
        BOOL fCompleteWord = FALSE;

        switch( nCmdID )
        {
        case ECMD_COMPLETEWORD:     // Ctrl-<space> completes a word (arrow,circle,rectangle)
            fCompleteWord = TRUE;
            // fall through
        case ECMD_SHOWMEMBERLIST:   // Ctrl-j       drops the statement completion box           
            {
            BOOL fShowDraw    = TRUE;
            BOOL fShowFigures = FALSE;
            CComBSTR cbstrText;
            hr = GetCurrentLineText(&cbstrText);
            if (SUCCEEDED(hr))
            {
                long nTokens = 0;
                hr = GetTokens(cbstrText, &nTokens);
                if (SUCCEEDED(hr) && nTokens > 0)
                {
                    // show 'draw' unless we have it already
                    if( eCommand == m_pMks[0].eTokenType )
                    {
                        fShowDraw = FALSE;

                        // show 'type' unless we have it already
                        if( (nTokens < 2) || (eType != m_pMks[1].eTokenType) )
                            fShowFigures = TRUE;
                    }
                }
            }

            if (!fShowDraw && !fShowFigures)
                break;

            DWORD dwFlags = 0;
            m_srpCompletionSet->Reset(
                /* [in]   BOOL   fDraw = FALSE   */ fShowDraw,
                /* [out]  DWORD* pdwFlags = NULL */ &dwFlags);
            if (fCompleteWord)
                dwFlags = dwFlags | UCS_COMPLETEWORD;
            hr = m_srpTextView->UpdateCompletionStatus( m_srpCompletionSet, dwFlags);
            }
            break;

        case ECMD_RETURN:           // dismiss method tip window if it's displayed
        case ECMD_BACKSPACE:        // dismiss method tip window if it's displayed
            if( m_fTipWinDisplayed ) {
                hr = m_srpTextView->UpdateTipWindow( 
                                m_srpMethodTipWindow, UTW_DISMISS );
                m_fTipWinDisplayed = FALSE;
            }
            // pass this character 'cmd' on to next in chain (the view so it will show up)
            fHandled = FALSE;
            hr = m_srpNextCmdTarg->Exec( pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut );
            break;

        case ECMD_TYPECHAR:         // any character
            {
                ExpectedPtrRet(pvaIn);
                fHandled = FALSE;
                // pass this character 'cmd' on to next in chain (the view so it will show up)
                hr = m_srpNextCmdTarg->Exec( pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut );

                if(pvaIn[0].vt != VT_UI2)
                    break;
                // did the user type a space after "draw" or "draw <type>" or is the 
                // tip window still displayed ?
                if (pvaIn[ 0 ].uiVal != ' ' && !m_fTipWinDisplayed)
                    break;

                HRESULT hrLocal = S_OK;

                // get the current line where the cursor is
                long nLine = 0;
                ViewCol vc;
                hrLocal = m_srpTextView->GetCaretPos( &nLine, &vc );
                if( FAILED( hrLocal )) 
                    break;

                // get the number of chars on the line
                long nLineLength;
                hrLocal = m_srpTextLines->GetLengthOfLine( nLine, &nLineLength );
                if( FAILED(hrLocal) || nLineLength == 0 ) 
                    break;

                // see if current line contains "draw" (starting at the beggining of the line)
                CComBSTR bstrLine;
                hrLocal = m_srpTextLines->GetLineText(  
                    nLine,          // starting line
                    0,              // starting character index within the line (must be <= length of line)
                    nLine,          // ending line
                    nLineLength,    // ending character index within the line (must be <= length of line)
                    &bstrLine );    // line text, if any
                if( FAILED(hrLocal) || bstrLine.Length() == 0 )
                    break;

                // parse the line
                long ncMarks = MAX_FIG_MARKS;
                if (!m_pMks)
                    break;
                memset( m_pMks, 0, MAX_FIG_MARKS * sizeof( FIGMARK ));

                // null terminate the input line for our parser
                WCHAR *wszLine;
                wszLine = new WCHAR[ nLineLength + 1 ];
                if (!wszLine)
                    break;
                memset( wszLine, 0, ( nLineLength + 1 ) * sizeof( WCHAR ));
                wcsncpy( wszLine, bstrLine, nLineLength );
                bstrLine.Empty();

                // call the Line method on the parse object
                CComBSTR bstrError;
                hrLocal = m_srpParse->Line( wszLine, &ncMarks, &m_pMks, &bstrError );

                if( FAILED( hrLocal )) {
                    // parse call failed
                    delete[] wszLine;
                    break;
                }

                // if last token is an error token, don't count it
                long nTokens = ncMarks;
                if( eError == m_pMks[ ncMarks - 1 ].eTokenType )
                    nTokens--;

                // convert wchar line into multibyte for adding to list
                size_t cmb = wcstombs(NULL, wszLine, nLineLength + 1) + 1;
                CHAR *pchLine = new CHAR[ cmb ];
                wcstombs( pchLine, wszLine, cmb );
                delete[] wszLine;

                // what type of line ?   base on the parsed tokens
                BOOL fShowTipWin = FALSE;
                if( eCommand == m_pMks[ 0 ].eTokenType  &&  1 == nTokens &&
                                                    pvaIn[ 0 ].uiVal == ' ' ) {

                    // if "draw" show statement completion list box

                    DWORD dwFlags = 0;
                    m_srpCompletionSet->Reset(
                        /* [in]   BOOL   fDraw = FALSE   */ FALSE,
                        /* [out]  DWORD* pdwFlags = NULL */ &dwFlags);
                    hrLocal = m_srpTextView->UpdateCompletionStatus( m_srpCompletionSet, dwFlags);
                
                } else  // if "draw <type>" show method tip
                if( eType == m_pMks[ 1 ].eTokenType  &&  2 <= nTokens  ) {
                    if( !strnicmp( &pchLine[ m_pMks[ 1 ].nStart ], "arrow", 
                                    ( m_pMks[ 1 ].nEnd - m_pMks[ 1 ].nStart ) + 1 )) {
                        // show method tip window
                        m_pMethodData->SetType( IDXARROW );
                        // first param not typed yet
                        if( 2 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {     
                            m_pMethodData->SetCurrentParam( 0 );
                            fShowTipWin = TRUE;
                        }
                        // first param
                        else if( 3 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 0 );
                            fShowTipWin = TRUE;
                        }
                        // second param not typed yet
                        else if( 3 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {    
                            m_pMethodData->SetCurrentParam( 1 );
                            fShowTipWin = TRUE;
                        }
                        // second param
                        else if( 4 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 1 );
                            fShowTipWin = TRUE;
                        }
                        // third param not typed yet
                        else if( 4 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {    
                            m_pMethodData->SetCurrentParam( 2 );
                            fShowTipWin = TRUE;
                        }
                        // third param
                        else if( 5 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 2 );
                            fShowTipWin = TRUE;
                        }
                        // fourth param not typed yet
                        else if( 5 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {    
                            m_pMethodData->SetCurrentParam( 3 );
                            fShowTipWin = TRUE;
                        }
                        // fourth param
                        else if( 6 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 3 );
                            fShowTipWin = TRUE;
                        }
                        else {                      // past the params
                            fShowTipWin = FALSE;
                        }
                    } else
                    if( !strnicmp( &pchLine[ m_pMks[ 1 ].nStart ], "circle", 
                                    ( m_pMks[ 1 ].nEnd - m_pMks[ 1 ].nStart ) + 1 )) {

                        // show method tip window
                        m_pMethodData->SetType( IDXCIRCLE );
                        // first param not typed yet
                        if( 2 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {     
                            m_pMethodData->SetCurrentParam( 0 );
                            fShowTipWin = TRUE;
                        }
                        // first param
                        else if( 3 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 0 );
                            fShowTipWin = TRUE;
                        }
                        // second param not typed yet
                        else if( 3 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {    
                            m_pMethodData->SetCurrentParam( 1 );
                            fShowTipWin = TRUE;
                        }
                        // second param
                        else if( 4 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 1 );
                            fShowTipWin = TRUE;
                        }
                        // third param not typed yet
                        else if( 4 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {    
                            m_pMethodData->SetCurrentParam( 2 );
                            fShowTipWin = TRUE;
                        }
                        // third param
                        else if( 5 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 2 );
                            fShowTipWin = TRUE;
                        }
                        else {                      // past the params
                            fShowTipWin = FALSE;
                        }
                    } else
                    if( !strnicmp( &pchLine[ m_pMks[ 1 ].nStart ], "rectangle", 
                                    ( m_pMks[ 1 ].nEnd - m_pMks[ 1 ].nStart ) + 1 )) {

                        // show method tip window
                        m_pMethodData->SetType( IDXRECTANGLE );
                        // first param not typed yet
                        if( 2 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {     
                            m_pMethodData->SetCurrentParam( 0 );
                            fShowTipWin = TRUE;
                        }
                        // first param
                        else if( 3 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 0 );
                            fShowTipWin = TRUE;
                        }
                        // second param not typed yet
                        else if( 3 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {    
                            m_pMethodData->SetCurrentParam( 1 );
                            fShowTipWin = TRUE;
                        }
                        // second param
                        else if( 4 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 1 );
                            fShowTipWin = TRUE;
                        }
                        // third param not typed yet
                        else if( 4 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {    
                            m_pMethodData->SetCurrentParam( 2 );
                            fShowTipWin = TRUE;
                        }
                        // third param
                        else if( 5 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 2 );
                            fShowTipWin = TRUE;
                        }
                        // fourth param not typed yet
                        else if( 5 == nTokens && pvaIn[ 0 ].uiVal == ' ' ) {    
                            m_pMethodData->SetCurrentParam( 3 );
                            fShowTipWin = TRUE;
                        }
                        // fourth param
                        else if( 6 == nTokens && pvaIn[ 0 ].uiVal != ' ' ) {    
                            m_pMethodData->SetCurrentParam( 3 );
                            fShowTipWin = TRUE;
                        }
                        else {                      // past the params
                            fShowTipWin = FALSE;
                        }
                    } 

                    if( fShowTipWin ) {
                        hrLocal = m_srpTextView->UpdateTipWindow( 
                                        m_srpMethodTipWindow, 0 );
                        m_fTipWinDisplayed = TRUE;
                    } else {
                        hrLocal = m_srpTextView->UpdateTipWindow( 
                                        m_srpMethodTipWindow, UTW_DISMISS );
                        m_fTipWinDisplayed = FALSE;
                    }
                }
                delete[] pchLine;
            }
            break;

        default:    
            // pass this cmd on to next in chain (the view so it will show up)
            fHandled = FALSE;
            hr = m_srpNextCmdTarg->Exec( pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut );
            break;
        }

        // Display any error message to the user and then reset the returned "hr"
        // to NOERROR because the error has been handled.
        if(fHandled && FAILED(hr))
            m_pCVsPkg->ReportErrorInfo(hr);

        // parse the line on each "command" to show red squigglies
        {
        long nLine = 0;
        ViewCol vc;
        m_srpTextView->GetCaretPos( &nLine, &vc );
        HRESULT hrLocal = m_srpTaskManager->CreateTask( nLine, m_srpTextView );
        if( FAILED(hrLocal))
            m_pCVsPkg->ReportErrorInfo(hrLocal);
        }

        // if we handled the command return OK - we have reported any error
        // otherwise passed the result returned from the next command target
        if (fHandled)
            return NOERROR;
        else
            return hr;
    }
    return m_srpNextCmdTarg->Exec( pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut );
}


// IVsTextViewEvents methods:
//
STDMETHODIMP_(void) CFigTextViewFilter::OnSetFocus( 
                        /*[in] */ IVsTextView *pView )
{
    if( m_fZombie || !m_fInit )
        return;
}

STDMETHODIMP_(void) CFigTextViewFilter::OnKillFocus(
                        /*[in] */ IVsTextView *pView )
{
    if( m_fZombie || !m_fInit )
        return;
}

STDMETHODIMP_(void) CFigTextViewFilter::OnSetBuffer(
                        /*[in] */ IVsTextView *pView, 
                        /*[in] */ IVsTextLines *pBuffer )
{
    if( m_fZombie || !m_fInit )
        return;
    if( m_srpTextView != pView )
        return;
    if( m_srpTextLines != pBuffer )
        return;
}

STDMETHODIMP_(void) CFigTextViewFilter::OnChangeScrollInfo(
                        /*[in] */ IVsTextView *pView, 
                        /*[in] */ long iBar, 
                        /*[in] */ long iMinUnit, 
                        /*[in] */ long iMaxUnits, 
                        /*[in] */ long iVisibleUnits, 
                        /*[in] */ long iFirstVisibleUnit )
{
    if( m_fZombie || !m_fInit )
        return;
}

STDMETHODIMP_(void) CFigTextViewFilter::OnChangeCaretLine(
                        /*[in] */ IVsTextView *pView, 
                        /*[in] */ long iNewLine, 
                        /*[in] */ long iOldLine )
{
    if( m_fZombie || !m_fInit )
        return;

    // is this our view ?
    if( m_srpTextView != pView )
        return;

    // see if we should create a task
    HRESULT hr = m_srpTaskManager->CreateTask( iOldLine, m_srpTextView );
}

HRESULT CFigTextViewFilter::GetCurrentLineText(
    /* [out] */ BSTR* pbstrLineText)
{
    ExpectedPtrRet(pbstrLineText);
    *pbstrLineText = NULL;

    // get the current line where the cursor is
    long nLine = 0;
    ViewCol vc;
    HRESULT hr = m_srpTextView->GetCaretPos( &nLine, &vc );
    if( FAILED(hr) )
        return hr;

    // get the number of chars on the line
    long nLineLength;
    hr = m_srpTextLines->GetLengthOfLine( nLine, &nLineLength );
    if( FAILED( hr ) || nLineLength == 0 ) 
        return hr;

    // see if current line contains "draw" (starting at the beggining of the line)
    CComBSTR cbstrLine;
    hr = m_srpTextLines->GetLineText(  
        nLine,          // starting line
        0,              // starting character index within the line (must be <= length of line)
        nLine,          // ending line
        nLineLength,    // ending character index within the line (must be <= length of line)
        pbstrLineText );    // line text, if any  
    return hr;
}


HRESULT CFigTextViewFilter::GetTokens(
    /* [in]  */ BSTR bstrLine,
    /* [out] */ long* pnTokens)
{
    if (pnTokens)
        *pnTokens = 0;
    UINT nLineLength = ::SysStringLen(bstrLine);
    if (!nLineLength)
        return S_FALSE;

    // parse the line
    long ncMarks = MAX_FIG_MARKS;
    if (!m_pMks)
        return E_UNEXPECTED;
    memset( m_pMks, 0, MAX_FIG_MARKS * sizeof( FIGMARK ));

    // null terminate the input line for our parser
    WCHAR * wszLine = new WCHAR[ nLineLength + 1 ];
    if (!wszLine)
        return E_OUTOFMEMORY;
    memset( wszLine, 0, ( nLineLength + 1 ) * sizeof( WCHAR ));
    wcsncpy( wszLine, bstrLine, nLineLength );

    // call the Line method on the parse object
    CComBSTR bstrError;
    HRESULT hr = m_srpParse->Line( wszLine, &ncMarks, &m_pMks, &bstrError );
    delete[] wszLine;

    if( FAILED( hr )) 
        return hr;

    if (pnTokens)
        *pnTokens = ncMarks;

    return S_OK;
}
// end of file CodeWnMg.cpp
