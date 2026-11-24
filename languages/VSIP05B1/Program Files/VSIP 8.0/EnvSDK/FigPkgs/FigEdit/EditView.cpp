
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// EditView.cpp : Implementation of CFigEditorView

#include "stdafx.h"     // system includes
#include "PrjInc.h"     // project includes
#include "FigOutline.h" 
    
#define MAX_FIG_MARKS 100


CFigEditorView::CFigEditorView( CVsPackage *pCVsPkg, 
                                IVsTextLines *pVsTextLines, 
                                BOOL fBufExists )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CFigEditorView::CFigEditorView : ")
        _T(", this = 0x%x \n"), this); 

    m_dwRef = 0;
    m_fZombie = FALSE;
    m_pCVsPkg = pCVsPkg;
    m_srpVsTextLines = pVsTextLines;  // Note: assignment to a smart pointer does an AddRef()
    m_fCompoundAction = FALSE;
    m_fDragSource = FALSE;
    m_fBufExists = fBufExists;
    m_srpWndPaneSiteSP = NULL;
    m_WinSize.cx = 50;
    m_WinSize.cy = 50;
    m_dwTextLinesEventsCookie = 0;
    m_dwTextBufferDataEventsCookie = 0;
    m_srpParse = NULL;
    m_pMks = NULL;  
    m_bstrBaseEditorCaption = NULL;
    m_srpUserCtx = NULL;

    // Register our custom format
    m_cf = RegisterClipboardFormatW(WSTR_CF_FigureSampleLine);
    ASSERT(m_cf != 0);

    if( m_cf == 0 )
        m_cf = 100;
}

CFigEditorView::~CFigEditorView()
{
    if (m_bstrBaseEditorCaption)
        SysFreeString(m_bstrBaseEditorCaption);

    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CFigEditorView::~CFigEditorView : ")
        _T(", this = 0x%x \n"), this); 
    _ASSERTE( 0 == m_dwRef );
}


// called by the custom Form Editor when the selection changes

HRESULT CFigEditorView::OnSelectChange()
{
    HRESULT hr = S_OK;

    // get a ptr to the track selection intf via the shell's service prov.
    //
    CComPtr<ITrackSelection>    srpITrackSelection;
    hr = m_srpWndPaneSiteSP->QueryService( 
                SID_STrackSelection, IID_ITrackSelection, 
                (void **)&srpITrackSelection );
    if( FAILED( hr ))
        return hr; 
 
    // make sure the ISelectionContainer methods on this view obj 
    // are called when the selection changes
    hr = srpITrackSelection->OnSelectChange( (ISelectionContainer *)this );

    return hr;
}


// AddLine(), DeleteLine(), SetLine() are
// called when advised of changes to the text buffer,
// these methods create/destroy line objects, list entries and tell
// the editor to create/destroy the corresponding item in the list view.
//
HRESULT CFigEditorView::AddLine( long nLine, FigLineType Type, long P1, long P2, 
                                 long P3, long P4, BSTR bstrComment )
{
    HRESULT hr = S_OK;

    // create new line obj
    CFigEditLine *pCLine;
    pCLine = new CFigEditLine( nLine, m_srpVsTextLines, Type, P1, P2, P3, P4, bstrComment ); 
    if( pCLine == NULL ) 
        return E_OUTOFMEMORY;
    pCLine->AddRef();

    // If the line number exists in the list, then this is an
    // insert.  We have to renumber the subsequent lines in each obj.
    listLines_type::iterator InsertPos = m_listLines.end(); 
    listLines_type::iterator pos; 
    long nCurLine;
    for( pos = m_listLines.begin(); pos != m_listLines.end(); pos++ ) { // search list
        if(( nCurLine = (*pos)->GetLineNumber()) >= nLine )     // does this line already exist ?
            (*pos)->SetLineNumber( nCurLine + 1 );              // incr. line num.
        if( nLine == nCurLine )
            InsertPos = pos;                                    // save insert pos
    }

    m_listLines.insert( InsertPos, pCLine );    // insert into linked list
    
    m_pCEd->AddLine( pCLine );                  // tell editor to add a new line !

    return hr;
}

HRESULT CFigEditorView::DeleteLine( long nLine )
{
    HRESULT hr = S_OK;

    // Find the line to delete in the linked list.
    // We have to renumber the subsequent lines in each obj.
    listLines_type::iterator DeletePos = m_listLines.end(); 
    listLines_type::iterator pos; 
    long nCurLine;
    for( pos = m_listLines.begin(); pos != m_listLines.end(); pos++ ) { // search list
        if(( nCurLine = (long)(*pos)->GetLineNumber()) > nLine )      // does this line exist ?
            (*pos)->SetLineNumber( nCurLine - 1 );              // decr. line num.
        if( nLine == nCurLine )
            DeletePos = pos;                                    // save insert pos
    }

    if( DeletePos != m_listLines.end() ) {      // handle line number outside existing range
        
        m_pCEd->DeleteLine( *DeletePos );   // tell editor to delete the line !

        (*DeletePos)->Release();            // release the line obj.
        
        m_listLines.erase( DeletePos );     // delete pos from linked list
    }

    return hr;
}

HRESULT CFigEditorView::SetLine( long nLine, FigLineType Type, long P1, long P2, 
                                 long P3, long P4, BSTR bstrComment )
{
    HRESULT hr = S_OK;

    // Find the line obj. in the linked list
    listLines_type::iterator pos; 
    for( pos = m_listLines.begin(); pos != m_listLines.end(); pos++ ) // search list
        if( (*pos)->GetLineNumber() == nLine ) {        // does this line exist ?
            break;                                      // YES, we found it
        }

    if( pos != m_listLines.end() ) {        // we found the line

        (*pos)->DoBufferUpdate( FALSE );    // turn off buffer updates to a avoid circular loop: put_XXX will normally update the buffer !

        (*pos)->SetLineNumber( nLine );     
        (*pos)->put_Type( Type );
        (*pos)->put_Parameter1( P1 );
        (*pos)->put_Parameter2( P2 );
        (*pos)->put_Parameter3( P3 );
        (*pos)->put_Parameter4( P4 );
        (*pos)->put_Comment( bstrComment );

        (*pos)->DoBufferUpdate( TRUE );     // turn on buf updates

        m_pCEd->SetLine( *pos );            // make editor redraw this line.
    }

    return hr;
}


// called to parse a line of text from the buffer
HRESULT CFigEditorView::ParseLine( long nLine, FigLineType *pType, long *pP1, long *pP2, 
                                   long *pP3, long *pP4, BSTR *pbstrComment )
{
    // validate input params
    // initialize out params
    ExpectedPtrRet(pType);*pType = FigInvalid;
    ExpectedPtrRet(pP1);*pP1 = 0;
    ExpectedPtrRet(pP2);*pP2 = 0;
    ExpectedPtrRet(pP3);*pP3 = 0;
    ExpectedPtrRet(pP4); *pP4 = 0;
    ExpectedPtrRet(pbstrComment);

    HRESULT hr = S_OK;

    if (!m_srpParse || !m_srpVsTextLines)
        return E_UNEXPECTED;
    hr = m_srpParse->ParseLine(m_srpVsTextLines, nLine, pType, pP1, pP2, pP3, pP4, pbstrComment);
    return hr;
}



/*****************************************************************************
** IUnknown Implementation
*****************************************************************************/

STDMETHODIMP CFigEditorView::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;     // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::QueryInterface for IID_IUnknown")
            _T(", this = 0x%x \n"), this );
        AddRef();
        *ppvObj = (IVsEditorFactory *) this;
        return NOERROR;
    }
    else if( riid == IID_IOleCommandTarget )
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::QueryInterface for IID_IOleCommandTarget")
            _T(", this = 0x%x \n"), this );
        AddRef();
        *ppvObj = (IOleCommandTarget *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsWindowPane )
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::QueryInterface for IID_IVsWindowPane")
            _T(", this = 0x%x \n"), this );
        AddRef();
        *ppvObj = (IVsWindowPane *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsTextLinesEvents )
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::QueryInterface for IID_IVsTextLinesEvents")
            _T(", this = 0x%x \n"), this );
        AddRef();
        *ppvObj = (IVsTextLinesEvents *) this;
        return NOERROR;
    }
    else if( riid == IID_ISelectionContainer )
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::QueryInterface for IID_ISelectionContainer")
            _T(", this = 0x%x \n"), this );
        AddRef();
        *ppvObj = (ISelectionContainer *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsTextBufferDataEvents )
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::QueryInterface for IID_IVsTextBufferDataEvents")
            _T(", this = 0x%x \n"), this );
        AddRef();
        *ppvObj = (IVsTextBufferDataEvents *) this;
        return NOERROR;
    }
    else if( riid == IID_IDropTarget )
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::QueryInterface for IID_IDropTarget")
            _T(", this = 0x%x \n"), this );
        AddRef();
        *ppvObj = (IDropTarget *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsToolboxUser )
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::QueryInterface for IID_IVsToolboxUser")
            _T(", this = 0x%x \n"), this );
        AddRef();
        *ppvObj = (IVsToolboxUser *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsDocOutlineProvider )
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::QueryInterface for IID_IVsDocOutlineProvider")
            _T(", this = 0x%x \n"), this );
        AddRef();
        *ppvObj = static_cast<IVsDocOutlineProvider *>(this);
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigEditorView::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigEditorView::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


/*****************************************************************************
** IOleCommandTarget Implementation
*****************************************************************************/

HRESULT CFigEditorView::QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
{

    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    int     fEnable = FALSE;

    ExpectedExprRet(cCmds==1);
    ExpectedPtrRet(prgCmds);
    ExpectedPtrRet(pguidCmdGroup);

    prgCmds[0].cmdf = NULL;

    if( CLSID_StandardCommandSet97 == *pguidCmdGroup )
    {
        switch( prgCmds[0].cmdID )
        {
        case cmdidPaste:
            {
            // make sure there is something in the clipboard to paste
            // make sure an item is selected before enabling delete
            CComPtr <IDataObject> srpDO;
            if( OleGetClipboard( &srpDO ) != S_OK )
                break;

            FORMATETC fe;
            SETDefFormatEtc( fe, m_cf, TYMED_HGLOBAL );
            if( srpDO->QueryGetData( &fe ) == NOERROR ) 
                fEnable = TRUE;
            break;
            }

        case cmdidCopy:
        case cmdidCut:
        case cmdidDelete:
            {
            // make sure an item is selected before enabling cut/copy/delete
            BOOL fSel;
            for( listLines_type::iterator pos = m_listLines.begin(); 
                                    pos != m_listLines.end(); pos++ ) {
                if( SUCCEEDED( (*pos)->GetSelection( &fSel ) )
                 && fSel ) {
                    fEnable = TRUE;
                    break;          // out of for loop
                }
            }
            break;
            }

        case cmdidSelectAll:
            if( 0 < m_listLines.size() )
                fEnable = TRUE;
            break;

        default:
            return OLECMDERR_E_NOTSUPPORTED;
        }
    }
    else if( CLSID_FigEditPackage == *pguidCmdGroup )
    {
        switch(prgCmds[0].cmdID)
        {
        case icmdAddArrow:
        case icmdAddCircle:
        case icmdAddRectangle:
        case icmdAddComment:
            {
            fEnable = TRUE;     // add/insert is always avail when view is up.
            break;
            }
        default:
            fEnable = -3;
            break;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    if( -3 == fEnable )
      prgCmds[0].cmdf = OLECMDF_DEFHIDEONCTXTMENU | OLECMDF_SUPPORTED |  OLECMDF_INVISIBLE;
    else if( fEnable )
      prgCmds[0].cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
    else
      prgCmds[0].cmdf = OLECMDF_SUPPORTED;

    return NOERROR;
}

HRESULT CFigEditorView::Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANT *pvaIn, VARIANT *pvaOut)
{
    ExpectedPtrRet(pguidCmdGroup);
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    if ( CLSID_StandardCommandSet97 == *pguidCmdGroup )
    {
        switch( nCmdID )
        {
        case cmdidCopy:
        case cmdidCut:
            CopyLines();
            if( nCmdID == cmdidCut )
                DeleteLines(/* BOOL fCut = FALSE */ TRUE);
            break;

        case cmdidPaste:
            PasteLines();
            break;

        case cmdidDelete:
            DeleteLines(/* BOOL fCut = FALSE */);
            break;

        case cmdidSelectAll:
            {
            _ASSERTE( NULL != m_pCEd );
            for( long nSelLine = (long)m_listLines.size(); nSelLine-- > 0; )
                m_pCEd->SelectLine( nSelLine );
            break;
            }

        default:    
            return OLECMDERR_E_NOTSUPPORTED;
            break;
        }
    }
    else if ( CLSID_FigEditPackage == *pguidCmdGroup )
    {
        FigLineType type;
        listLines_type  Sel;
        long    nLine = _CreateSelectionList( Sel );
        if (0 < nLine)  // did we find a selected line?
            nLine = (*Sel.begin())->GetLineNumber();
        else            // no, so add at end.
            nLine = (long)m_listLines.size();

        CComBSTR bstrComment;
        switch (nCmdID)
        {
        case icmdAddArrow:
            type = FigArrow;
            bstrComment = "Arrow";
            break;
        case icmdAddCircle:
            type = FigCircle;
            bstrComment = "Circle";
            break;
        case icmdAddRectangle:
            type = FigRectangle;
            bstrComment = "Rectangle";
            break;
        case icmdAddComment:
            type = FigComment;
            break;
        default:    
            return OLECMDERR_E_NOTSUPPORTED;
        }

        // create temporary line obj
        CFigEditLine *pTmp = new CFigEditLine( ++nLine, m_srpVsTextLines, type, 0, 0, 0, 0,
                                               bstrComment ); 
        if( pTmp == NULL ) 
            return E_OUTOFMEMORY;
        pTmp->AddRef();
        // add this line to the buffer, which will notify us of the event and then we will 
        // add a line object and update the list view.
        HRESULT hr = pTmp->InsertLineToBuffer();   
        pTmp->Release();                // release (destroy) temp object.
        return hr;
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    return NOERROR;
}


/*****************************************************************************
** IVsWindowPane Implementation
*****************************************************************************/
STDMETHODIMP CFigEditorView::SetSite(
                    /*[in] */ IServiceProvider *pSP )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    m_srpWndPaneSiteSP = pSP;       // Note: assignment to a smart pointer does an AddRef()
    if (m_srpVsTextLines)
        m_srpVsTextLines->QueryInterface(IID_IVsCompoundAction, (void**)&m_srpIVsCompoundAction);

    return NOERROR;
}


STDMETHODIMP CFigEditorView::CreatePaneWindow(
                    /*[in] */ HWND hwndParent,
                    /*[in] */ int x,
                    /*[in] */ int y,
                    /*[in] */ int cx,
                    /*[in] */ int cy,
                    /*[out]*/ HWND * pHwnd )
{
    ExpectedPtrRet(pHwnd);
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    // create editor window
    m_pCEd = new CEditor( this );
    if (!m_pCEd)
        return E_OUTOFMEMORY;

    RECT rc;
    rc.left   = x;
    rc.top    = y;
    rc.right  = x + cx;
    rc.bottom = y + cy;
    if(( *pHwnd = m_pCEd->Create( hwndParent, rc, _T("yo"),
                    WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE )) == NULL ) {

        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigEditorView::CreatePaneWindow : ")
            _T(", this = 0x%x : Create Failed! \n"), this); 

        return E_FAIL;
    }

    // get a doc outline provider
    if (m_srpIVsDocOutlineProvider == NULL)
    {
        if (m_srpIFigOutline == NULL)
        {
            // get the service
            HRESULT hr = _AtlModule.QueryService(
                                SID_SFigOutline, 
                                IID_IFigOutline, 
                                (void**)&m_srpIFigOutline);
            IfFailRet(hr);
            _ASSERTE (m_srpIFigOutline != NULL);

            hr = m_srpIFigOutline->Init(m_srpVsTextLines, m_pCEd->m_hWnd, NULL);
            IfFailRet(hr);
        }

        HRESULT hr = m_srpIFigOutline->QueryInterface(
                                IID_IVsDocOutlineProvider,
                                (void**) &m_srpIVsDocOutlineProvider);
        IfFailRet(hr);

    }
    ASSERT(m_srpIVsDocOutlineProvider != NULL);

    // register our independent view with the IVsTextManager so that it knows
    // the user is working with a view over the text buffer. this will trigger
    // the text buffer to prompt the user whether to reload the file if it is
    // edited outside of the development Environment.
    CComPtr<IVsTextManager> srpTextManager;
    if (SUCCEEDED(_AtlModule.QueryService(SID_SVsTextManager, IID_IVsTextManager, (void **)&srpTextManager))) 
    {
      CComPtr<IVsWindowPane> srpWindowPane;
      if (SUCCEEDED(this->QueryInterface(IID_IVsWindowPane, (void **)&srpWindowPane))) {
          srpTextManager->RegisterIndependentView(srpWindowPane, m_srpVsTextLines);
      }
    }

    // setup an IVsTextLinesEvents advise on the buffer, intf is impl on view
    HRESULT hr;
    CComPtr<IConnectionPointContainer> srpConPtCont;
    hr = m_srpVsTextLines->QueryInterface( IID_IConnectionPointContainer,
                                            (void **)&srpConPtCont );
    if( FAILED( hr ))
        return hr;

    CComPtr<IConnectionPoint> srpConPt;
    hr = srpConPtCont->FindConnectionPoint( IID_IVsTextLinesEvents,
                                            &srpConPt );
    if( FAILED( hr ))
        return hr;

    hr = srpConPt->Advise( (IVsTextLinesEvents *)this, &m_dwTextLinesEventsCookie );
    if( FAILED( hr ))
        return hr;


    // setup an IVsTextBufferDataEvents advise on the buffer, intf is impl on view
    CComPtr<IConnectionPoint> srpConPt2;
    hr = srpConPtCont->FindConnectionPoint( IID_IVsTextBufferDataEvents,
                                            &srpConPt2 );
    if( FAILED( hr ))
        return hr;

    hr = srpConPt2->Advise( (IVsTextBufferDataEvents *)this, &m_dwTextBufferDataEventsCookie );
    // NOTE: we do not consider it fatal if we fail to setup the IVsTextBufferDataEvents advise.
    // this only means that we will not properly track file changes on disk outside of the IDE.
    if( FAILED( hr ))
        hr = S_OK;

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

    // make sure the ISelectionContainer methods on this view obj 
    // are called when the selection changes
    hr = OnSelectChange();
    if( FAILED( hr ))
        return hr;

    // allocate a token array for our parser to fill
    m_pMks = new FIGMARK[ MAX_FIG_MARKS ];  // allocate an array of tokens
    if (!m_pMks)
        return E_OUTOFMEMORY;

    // We are attaching to an existing buffer, so we need to make
    // sure to call the initial CFigEditorView::OnChangeLineText 
    // This is done automatically when the buffer is created/loaded.
    //
    if( m_fBufExists ) {    
        long iLineCnt = 0;
        hr = m_srpVsTextLines->GetLineCount( &iLineCnt );
        TextLineChange tlc;
        tlc.iStartLine = 0;             // starting line number
        tlc.iStartIndex = 0;
        tlc.iOldEndLine = 0;
        tlc.iOldEndIndex = 0;
        tlc.iNewEndLine = iLineCnt;     // ending line number
        tlc.iNewEndIndex = 0;
        OnChangeLineText( &tlc, TRUE );
    }

    // set this window as a drag/drop target
    RegisterDragDrop( *pHwnd, this );


    // Context window
    hr = S_OK;
    if (!m_srpUserCtx)
        hr = CreateUserContext(&m_srpUserCtx);

    if (SUCCEEDED(hr) && (m_srpUserCtx != NULL))
    {
        // add the editor keywords here (with VSUC_Priority_Window priority)
        m_srpUserCtx->AddAttribute(VSUC_Usage_Filter, L"DevLang", L"vs.envsdk.figure");
        m_srpUserCtx->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.designer");

        IVsTrackSelectionEx * pts;
        if (SUCCEEDED(m_srpWndPaneSiteSP->QueryService(SID_SVsTrackSelectionEx, IID_IVsTrackSelectionEx, (void**)&pts)))
        {
            VARIANT v;
            
            V_VT(&v) = VT_UNKNOWN;
            V_UNKNOWN(&v) = m_srpUserCtx;
            
            pts->OnElementValueChange(SEID_UserContext, FALSE, v);
            pts->Release();
        }
    }

    return NOERROR;
}


STDMETHODIMP CFigEditorView::GetDefaultSize(
                    /*[out]*/ SIZE *psize )
{
    ExpectedPtrRet(psize);
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    *psize = m_WinSize;

    return NOERROR;
}


STDMETHODIMP CFigEditorView::ClosePane( void )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    m_fZombie = TRUE;

    RevokeDragDrop(m_pCEd->m_hWnd);

    // unregister our custom editor view with the IVsTextManager that coordinates
    // all views over a TextBuffer. we register our independent view with the 
    // IVsTextManager so that it knows the user is working with a view over the 
    // text buffer. this will trigger the text buffer to prompt the user whether 
    // to reload the file if it is edited outside of the development Environment.
    CComPtr<IVsTextManager> srpTextManager;
    if (SUCCEEDED(_AtlModule.QueryService(SID_SVsTextManager, IID_IVsTextManager, (void **)&srpTextManager))) 
    {
      CComPtr<IVsWindowPane> srpWindowPane;
      if (SUCCEEDED(this->QueryInterface(IID_IVsWindowPane, (void **)&srpWindowPane))) {
          srpTextManager->UnregisterIndependentView(srpWindowPane, m_srpVsTextLines);
      }
    }

    // close the doc outline provider
    m_srpIVsDocOutlineProvider.Release();

    if (m_srpIFigOutline)
        m_srpIFigOutline->Close();
    m_srpIFigOutline.Release();

    // destroy editor window
    m_pCEd->DestroyWindow();
    delete m_pCEd;

    // unadvise IVsTextLinesEvents from buffer
    HRESULT hr;
    CComPtr<IConnectionPointContainer> srpConPtCont;
    hr = m_srpVsTextLines->QueryInterface( IID_IConnectionPointContainer,
                                            (void **)&srpConPtCont );
    if( SUCCEEDED( hr ))
    {
        CComPtr<IConnectionPoint> srpConPt;
        hr = srpConPtCont->FindConnectionPoint( IID_IVsTextLinesEvents,
                                            &srpConPt );
        if( SUCCEEDED( hr ))
        {
            hr = srpConPt->Unadvise( m_dwTextLinesEventsCookie );
        }

        // unadvise IVsTextBufferDataEvents from buffer
        CComPtr<IConnectionPoint> srpConPt2;
        hr = srpConPtCont->FindConnectionPoint( IID_IVsTextBufferDataEvents,
                                                &srpConPt2 );
        if( SUCCEEDED( hr ))
        {
            hr = srpConPt2->Unadvise( m_dwTextBufferDataEventsCookie );
        }
    }

    // A package should not call IProfferService::RevokeService() in its Close() implementation 
    // (Note: the debug version of the Shell will Assert to help catch offenders). All services 
    // are expected to remain available for the entire duration of calling Close() on all packages. 
    // The Shell will automatically revoke and release the services after all packages have been 
    // called Close().

    m_srpWndPaneSiteSP.Release();
    m_srpIVsCompoundAction.Release();
    m_srpVsTextLines.Release();     // release our buffer
    m_srpParse.Release();           // release the parser

    if( m_pMks )
        delete[] m_pMks;     // free array of tokens

    // release line objects
    for( listLines_type::iterator pos = m_listLines.begin(); 
                                pos != m_listLines.end(); pos++ )
        (*pos)->Release();

    // remove the line objects from STL list
    m_listLines.clear();

    // flush clipboard and release last IDataObject put there
    OleFlushClipboard();

    return NOERROR;
}


STDMETHODIMP CFigEditorView::LoadViewState(
                    /*[in] */ IStream *pstream )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    return NOERROR;
}


STDMETHODIMP CFigEditorView::SaveViewState(
                    /*[in] */ IStream *pstream )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    return NOERROR;
}


STDMETHODIMP CFigEditorView::TranslateAccelerator(
                              LPMSG lpmsg )
{
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    return S_FALSE; // we don't handle any messages
}


/*****************************************************************************
** IVsTextLinesEvents Implementation
*****************************************************************************/

// The text buffer advises us of any changes by calling this method
//
STDMETHODIMP_(void) CFigEditorView::OnChangeLineText(
                    /*[in] */ const TextLineChange *pTextLineChange,
                    /*[in] */ BOOL fLast )
{
    if (!pTextLineChange)
        return;
    if( m_fZombie )
        return;             // recursion guard

    ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
        _T(": CFigEditorView::OnChangeLineText : ")
        _T(", this = 0x%x, pTextLineChange = %d %d %d %d %d %d  \n"), 
                this, 
                pTextLineChange->iStartLine,        // starting line number
                pTextLineChange->iStartIndex,
                pTextLineChange->iOldEndLine,       // for deleted line
                pTextLineChange->iOldEndIndex,
                pTextLineChange->iNewEndLine,       // ending line number
                pTextLineChange->iNewEndIndex );

    // The following rules apply to the line numbers passed in:
    //
    //   if iNewEndLine > iOldEndLine then line(s) added
    //     add line from iOldEndLine to < iNewEndLine 
    //
    //   if iOldEndLine > iNewEndLine then line(s) deleted
    //     delete from iStartLine to < iOldEndLine
    //
    //   if iStartLine == iOldEndLine == iNewEndLine then a one line change
    //     set line iStartLine

    FigLineType type;
    long P1 = 0;
    long P2 = 0;
    long P3 = 0;
    long P4 = 0;
    CComBSTR bstrComment;

    // Any lines to ADD ?
    if( (pTextLineChange->iNewEndLine > pTextLineChange->iOldEndLine ) ||
        (m_listLines.empty())) // If the list of lines is empty, every line is new
    {
        long nLine = pTextLineChange->iOldEndLine; 

        if( pTextLineChange->iStartIndex != 0 ||
            pTextLineChange->iOldEndIndex != 0 ) {  // this is not a multi line paste

            nLine++; 
            ParseLine( nLine, &type, &P1, &P2, &P3, &P4, &bstrComment );
            AddLine( nLine, type, P1, P2, P3, P4, bstrComment );
            bstrComment.Empty();
        } else {

            long nEnd;
            if( pTextLineChange->iNewEndIndex != 0 )
                nEnd = pTextLineChange->iNewEndLine;
            else
                nEnd = pTextLineChange->iNewEndLine - 1;

            for( ; nLine <= nEnd ; nLine++ ) {
                ParseLine( nLine, &type, &P1, &P2, &P3, &P4, &bstrComment );
                AddLine( nLine, type, P1, P2, P3, P4, bstrComment );
                bstrComment.Empty();
            }
        }
    }
    // Any lines to DELETE ?  (in reverse order)
    else if( pTextLineChange->iOldEndLine > pTextLineChange->iNewEndLine ) {

        long nLine;
        if( pTextLineChange->iStartIndex != 0 ||
            pTextLineChange->iNewEndIndex != 0 ) {  // this is not a multi line cut

            DeleteLine( pTextLineChange->iOldEndLine );
        } else {
            if( pTextLineChange->iOldEndIndex != 0 )
                nLine = pTextLineChange->iOldEndLine;
            else
                nLine = pTextLineChange->iOldEndLine - 1;

            for( ; nLine >= pTextLineChange->iStartLine; nLine-- ) {
                DeleteLine( nLine );
            }

            if( pTextLineChange->iStartLine == 0 ) {
                HRESULT hr = S_OK;
                hr = m_srpVsTextLines->GetLineCount( &nLine );
                if( FAILED( hr ))
                    return;
                if( nLine == 1 && m_listLines.size() == 0 ) {       
                    // oops !  we deleted all the lines, but the text buffer will always have one.
                    AddLine( 0, FigInvalid, P1, P2, P3, P4, bstrComment );
                }
            }
        }
    }
    // Any edits on one line ?
    else if( pTextLineChange->iStartLine == pTextLineChange->iOldEndLine &&
             pTextLineChange->iStartLine == pTextLineChange->iNewEndLine ) {
        long nLine = pTextLineChange->iStartLine;
        ParseLine( nLine, &type, &P1, &P2, &P3, &P4, &bstrComment );
        SetLine( nLine, type, P1, P2, P3, P4, bstrComment );
    }
    else
        return;
}

STDMETHODIMP_(void) CFigEditorView::OnChangeLineAttributes (
                    /*[in] */ long iFirstLine,
                    /*[in] */ long iLastLine )
{
    if( m_fZombie )
        return;             // recursion guard

    // don't care about line color changes in our custom Form editor.
}


/*****************************************************************************
** ISelectionContainer Implementation
*****************************************************************************/

// ignore the flags and just return the count of
// SELECTED lines in the list
//
STDMETHODIMP CFigEditorView::CountObjects(
                /*[in] */ DWORD dwFlags, 
                /*[out]*/ ULONG * pc )
{
    HRESULT hr = S_OK;
    ExpectedPtrRet(pc);
    
    switch (dwFlags)
    {
    case GETOBJS_ALL:
        // Offer up all objects - doesn't make sense for ev. simply fall-thru
        
    case GETOBJS_SELECTED:
        *pc = 0;  // initialize count
        
        BOOL fSel;
        for( listLines_type::iterator pos = m_listLines.begin(); 
        pos != m_listLines.end(); pos++ )
        {
            if( SUCCEEDED( (*pos)->GetSelection( &fSel ) )
                && fSel )       // if this line is selected
            {
                (*pc)++;    // incr. count
            }
        }       
        break;
        
    default:
        hr = E_FAIL;
        
    }
    
    return hr;
}


// alloc and return an array of IUnk ptrs to the selected line objects.
// ignore the flags.
//
STDMETHODIMP CFigEditorView::GetObjects(
                /*[in] */ DWORD dwFlags, 
                /*[in] */ ULONG cObjects,
                /*[out]*/ IUnknown ** apUnkObjects )
{
    ExpectedPtrRet(apUnkObjects);
    HRESULT hr = S_OK;
    listLines_type::iterator pos;
    listLines_type Sel;

    switch (dwFlags)
    {
    case GETOBJS_ALL:
        // Offer up all objects - doesn't make sense for ev. simply fall-thru
        
    case GETOBJS_SELECTED:
        // get the selection list
        if (cObjects != _CreateSelectionList( Sel ))
        {
            *apUnkObjects = NULL;   // NULL the out pointer
            hr = E_UNEXPECTED;
            break;
        }
        
        // alloc memory for IUnk ptrs
        if( (*apUnkObjects = (IUnknown *)CoTaskMemAlloc( cObjects * sizeof( IUnknown * ) )) 
            == NULL )
        {
            hr = E_OUTOFMEMORY;
            break;
        }
        
        pos = Sel.begin();  // iterator 
        for( ULONG i = 0; i < cObjects; i++, pos++ )    // iterate expected number of SELECTED objs 
        {
            _ASSERTE( pos != Sel.end() );   // this assert fires if cObjects doesn't match the flagged selection count
            IUnknown *  srpIUnk;
            hr = (*pos)->QueryInterface( IID_IUnknown, (void **)&srpIUnk );
            if( SUCCEEDED( hr ) )
                apUnkObjects[i] = srpIUnk;  // set IUnk ptr (already AddRef'd in QI)
            else    // something wrong - clean up
            {
                while( i-- )    // release objects
                    apUnkObjects[i]->Release();
                CoTaskMemFree( *apUnkObjects ); // free the memory
                *apUnkObjects = NULL;   // NULL the out pointer
                hr = E_UNEXPECTED;
                break;
            }
        }
        break;
    default:
        hr = E_FAIL;
    }

    return hr;
}


// we dont use this method
//
STDMETHODIMP CFigEditorView::SelectObjects(
                /*[in] */ ULONG cSelect,
                /*[in] */ IUnknown ** apUnkSelect,
                /*[in] */ DWORD dwFlags )               // what is this for ?
{
  // Since we never give more objects thann the currently selected ones
  // ie GETOBJS_ALL always returns the same thing as GETOBJS_SELECTED, we
  // should never be called on this
  VSASSERT(false, "Who's calling this?");
  return E_NOTIMPL;
}


// cut/copy/paste/delete helpers
//

// appends all selected lines to list rSel & returns count added
// highest line number is first on the list
// pointers are not AddRef()'d (assumes function users know this)
ULONG CFigEditorView::_CreateSelectionList( listLines_type &rSel )
{
    ULONG   nCount = 0;
    listLines_type::iterator    pos = m_listLines.end();
    while( pos != m_listLines.begin() )
    {
        --pos;
        BOOL    fSel;
        if( SUCCEEDED( (*pos)->GetSelection( &fSel ))
         && fSel )
        {
            rSel.insert( rSel.end(), *pos );
            ++nCount;
        }
    }
    return nCount;
}

// encapsulates the common logic between Delete and Paste, guaranteeing that line selection
//  works the same:
//  - Function occurs starting at topmost selected line.
//  - After delete, same line number is selected or the one above if that was the last line.
//  - After Paste, the newly pasted lines are selected and replace previously selected lines.
// if pPasteObj is NULL, assumes we are deleting current selection
// otherwise, assumes we are pasting over current selection
HRESULT CFigEditorView::_DeletePasteLines(IDataObject* pPasteObj, UINT uIdCompoundAction)
{
    HRESULT         hr = NOERROR;
    listLines_type  toDel;      // an STL linked list of pointers to CFigEditLine objs
    long            nSelLine = _CreateSelectionList( toDel );
    listLines_type::iterator    pos;
    long    nMaxLines = (long)m_listLines.size();

    CComBSTR cbstrCompoundAction;
    cbstrCompoundAction.LoadString(uIdCompoundAction);
    if (m_srpIVsCompoundAction)
    {
        hr = m_srpIVsCompoundAction->OpenCompoundAction(cbstrCompoundAction);
        if (SUCCEEDED(hr))
            m_fCompoundAction = TRUE;
    }

    if (0 != nSelLine)
    {
        nSelLine = toDel.back()->GetLineNumber();
        for (pos = toDel.begin(); pos != toDel.end(); pos++)
        {
            // delete this line from text buffer, 
            // which will notify us of the event and then we will 
            // delete the object and remove it from the other list.
            hr = (*pos)->DeleteLineFromBuffer();
            if (FAILED(hr))
            {
                if (m_fCompoundAction)
                {
                    m_srpIVsCompoundAction->AbortCompoundAction();
                    m_fCompoundAction = FALSE;
                }
                return hr;
            }
        }
        if (nSelLine > nMaxLines)
            nSelLine = nMaxLines;
    }
    else nSelLine = nMaxLines;
    if (NULL != pPasteObj)  // are we pasting?
        hr = PasteLinesFromDataObject( pPasteObj, nSelLine );
    else if (nSelLine == nMaxLines && 0 < nMaxLines)
        --nSelLine; // select previous line if Delete on last line(s)
    _ASSERTE( NULL != m_pCEd );
    m_pCEd->SelectLine( nSelLine );

    if (m_fCompoundAction)
    {
        m_fCompoundAction = FALSE;
        if (SUCCEEDED(hr))
            m_srpIVsCompoundAction->CloseCompoundAction();
        else
            m_srpIVsCompoundAction->AbortCompoundAction();
    }

    return hr;
}

CDataObject* CFigEditorView::_CreateCopyData( void )
{
    listLines_type  Sel;    // an STL linked list of pointers to CFigEditLine objs
    _CreateSelectionList( Sel );
    // the data object will create copies of the line objs
    return new CDataObject( m_cf, Sel, m_srpVsTextLines );
}

HRESULT CFigEditorView::CopyLines( void )
{
    HRESULT         hr = NOERROR;
    CDataObject*    pDO = _CreateCopyData();
    if (NULL == pDO)
        return E_OUTOFMEMORY;

    return OleSetClipboard( pDO );  // this does an AddRef
}

HRESULT CFigEditorView::DeleteLines(BOOL fCut /* = FALSE */)
{
    UINT uIdCompoundAction = fCut ? IDS_COMPOUNDACTION_CUT : IDS_COMPOUNDACTION_DELETE;
    return _DeletePasteLines(NULL, uIdCompoundAction);
}

HRESULT CFigEditorView::PasteLines( void )
{
    HRESULT         hr = NOERROR;
    CComPtr<IDataObject>    srpDO;
    hr = OleGetClipboard( &srpDO );
    if( FAILED( hr ))
        return hr;

    return _DeletePasteLines(srpDO, IDS_COMPOUNDACTION_PASTE);
}

HRESULT CFigEditorView::PasteLinesFromDataObject( IDataObject* pDO, long nLineStart )
{
    ExpectedPtrRet(pDO);
    HRESULT hr = NOERROR;

    FORMATETC fe;
    SETDefFormatEtc( fe, m_cf, TYMED_HGLOBAL );     // custom format 
    hr = pDO->QueryGetData( &fe );
    if( FAILED( hr ) )
        return hr;

    STGMEDIUM stm;
    hr = pDO->GetData( &fe, &stm );
    if( FAILED( hr ))
        return hr;

    BYTE *pMem = (BYTE *)GlobalLock( stm.hGlobal );
    if( pMem != NULL )
    {
        hr = CreateLinesFromClipboard( nLineStart, pMem );
        GlobalUnlock( stm.hGlobal );
    }
    ReleaseStgMedium( &stm );
    return hr;
}

// convert the byte stream from clipboard back into line object(s) 
// that are inserted into the text buffer (PASTE)
//
HRESULT CFigEditorView::CreateLinesFromClipboard( long startLine, BYTE *pMem )
{
    ExpectedPtrRet(pMem);
    // create line objects from the (could be multiple)
    // lines in the memory block

    // figure out how much memory was allocated per line (without comment)
    ULONG cPerLine =    sizeof( ULONG ) +           // total number of bytes
                        sizeof( FigLineType ) +     // type
                        (4 * sizeof( long ));       // parameters

    ULONG cLine = *(ULONG *)pMem;           // number of lines
    pMem += sizeof( ULONG );

    // get each line obj's properties from the memory block
    for( ULONG i = 0; i < cLine; i++ )
    {
        ULONG cLineBytes;
        FigLineType Ftype;
        long P1, P2, P3, P4;
        ULONG cCmtChars;
        CComBSTR bstrCmt;

        cLineBytes = (ULONG)*pMem;  // number of bytes in this line
        pMem += sizeof( ULONG );

        Ftype = *(FigLineType *)pMem;       // type
        pMem += sizeof( FigLineType );

        P1 = (long)*pMem;                   // params
        pMem += sizeof( long );
        P2 = (long)*pMem;   
        pMem += sizeof( long );
        P3 = (long)*pMem;   
        pMem += sizeof( long );
        P4 = (long)*pMem;   
        pMem += sizeof( long );

        cCmtChars = cLineBytes - cPerLine;
        HRESULT hr = bstrCmt.Append( (WCHAR *)pMem, cCmtChars ); // comment 
        _IfFailRet(hr);
        pMem += cCmtChars * sizeof( WCHAR );

        // create a temporary line object and tell it to 
        // insert itself into the text buffer
        CComPtr<CFigEditLine>   pTmp = new CFigEditLine( ++startLine, m_srpVsTextLines, 
                                    Ftype, P1, P2, P3, P4, bstrCmt ); 
        if (pTmp == NULL) 
            return E_OUTOFMEMORY;
        // add this line to the buffer,
        // which will notify us of the event and then we will 
        // add a line object and update the list view.
        hr = pTmp->InsertLineToBuffer();
        _IfFailRet(hr);
    }

    return NOERROR;
}

// Perform drag-n-drop for FigEditView
HRESULT CFigEditorView::OnDragDrop( void )
{
    CDataObject* pDataObject = _CreateCopyData();
    if (pDataObject == NULL)
        return E_UNEXPECTED;

    HRESULT hr = S_OK;
    m_fDragSource = TRUE;

    DWORD   dwEffect;
    listLines_type  Sel;
    _CreateSelectionList( Sel );    // save the current selection
    hr = DoDragDrop( pDataObject, pDataObject, DROPEFFECT_COPY | DROPEFFECT_MOVE, &dwEffect );
    if (FAILED(hr))
        goto Error;
    if ((DROPEFFECT_MOVE != dwEffect) && (DROPEFFECT_COPY != dwEffect))
        goto Error;

    if ((DROPEFFECT_MOVE == dwEffect) && !m_fCompoundAction && m_srpIVsCompoundAction)
    {
        CComBSTR cbstrCompoundAction;
        cbstrCompoundAction.LoadString(IDS_COMPOUNDACTION_DRAGDROP);
        if (SUCCEEDED(m_srpIVsCompoundAction->OpenCompoundAction(cbstrCompoundAction)))
            m_fCompoundAction = TRUE;
    }
    long    nSels = (long)Sel.size();
    for (listLines_type::iterator   pos = Sel.begin();
        pos != Sel.end(); pos++ )
    {
        long    nLine = (*pos)->GetLineNumber();
        if (DROPEFFECT_MOVE == dwEffect)
        {
            hr = (*pos)->DeleteLineFromBuffer(); // remove selected source lines
            if (FAILED(hr))
                goto Error;
            if (nLine <= m_nDropFocusLine)
                --m_nDropFocusLine;
        }
        else
            m_pCEd->UnselectLine( nLine );  // unselect copy source lines
    }
    // select dropped lines
    for (nSels += m_nDropFocusLine; --nSels >= m_nDropFocusLine;)
        m_pCEd->SelectLine( nSels );
Error:

    if (m_fCompoundAction)
    {
        m_fCompoundAction = FALSE;
        if (SUCCEEDED(hr))
            hr = m_srpIVsCompoundAction->CloseCompoundAction();
        else
            m_srpIVsCompoundAction->AbortCompoundAction();
    }
    m_fDragSource = FALSE;
    return hr;
}


/*****************************************************************************
** IVsTextBufferDataEvents Implementation
*****************************************************************************/

// IVsTextStreamDataEvents
//
// This event forwards the IVsFileChangeEvents::FilesChanged notification that the TextStream monitors to other
// interested parties. Non-TextEditorView (e.g. a Form view) will want to hook up to this event to manage whether
// "[ReadOnly]" should be included in the document window caption (VSFPROPID_EditorCaption).
// Note: dwFileAttrs is only valid if VSFILECHG_Attr is set in which case it returns the result of WinAPI GetFileAttributes().
// This is useful to check for (dwFileAttrs & FILE_ATTRIBUTE_READONLY) to know if the file's ReadOnly status changes.
void CFigEditorView::OnFileChanged(DWORD grfChange, DWORD dwFileAttrs)
{
    if (grfChange == VSFILECHG_Attr)
    {
        IVsWindowFrame * pFrame = NULL;
        
        HRESULT hr = E_FAIL;
        
        if (m_srpWndPaneSiteSP != NULL)
            hr = m_srpWndPaneSiteSP->QueryService(SID_SVsWindowFrame, IID_IVsWindowFrame, (LPVOID*)&pFrame);
        
        if (SUCCEEDED(hr))
        {
            VARIANT vt;
            VariantInit(&vt);

            vt.vt = VT_BSTR;

            if ((dwFileAttrs & FILE_ATTRIBUTE_READONLY) != 0)
                hr = GetEditorCaption(ROSTATUS_ReadOnly, &vt.bstrVal);
            else
                hr = GetEditorCaption(ROSTATUS_NotReadOnly, &vt.bstrVal);

            if ( SUCCEEDED(hr) )
                hr = pFrame->SetProperty(VSFPROPID_EditorCaption, vt);

            if (vt.bstrVal)
                SysFreeString(vt.bstrVal);

            pFrame->Release();
        }
    }
}

// This event is fired after the buffer is first initialized with data either by a call to IVsPersistDocData::LoadDocData, 
// IPersistStream::Load, IVsTextStream::InitializeContent, IPersistFile::Load/InitNew. This event is also fired if the 
// buffer executes a reload of its file in response to a OnFileChanged event (i.e. file edited outside of the Environment).
STDMETHODIMP CFigEditorView::OnLoadCompleted(BOOL fReload)
{
    _ASSERTE( (fReload && m_fBufExists) || (!fReload && !m_fBufExists) );

    if (fReload)
    {
        // delete all lines from the list view and
        m_pCEd->DeleteAllLines();

        // release all existing line objects
        for( listLines_type::iterator pos = m_listLines.begin(); 
                                        pos != m_listLines.end(); pos++ )
            (*pos)->Release();  

        // remove line objects from STL list (must be done separately from above loop)
        m_listLines.erase( m_listLines.begin(), m_listLines.end() );

        // assume every line has changed and force the OnChangeLineText event
        long iLineCnt = 0;
        (void) m_srpVsTextLines->GetLineCount( &iLineCnt );
        TextLineChange tlc;
        tlc.iStartLine = 0;             // starting line number
        tlc.iStartIndex = 0;
        tlc.iOldEndLine = 0;
        tlc.iOldEndIndex = 0;
        tlc.iNewEndLine = iLineCnt;     // ending line number
        tlc.iNewEndIndex = 0;
        OnChangeLineText( &tlc, TRUE );
    }
    return S_OK;
}


/*****************************************************************************
** editor caption helper methods
*****************************************************************************/

HRESULT CFigEditorView::SetBaseEditorCaption(LPCOLESTR *pszBaseEditorCaption)
{
    ExpectedPtrRet(pszBaseEditorCaption);
    if (m_bstrBaseEditorCaption)
        SysFreeString(m_bstrBaseEditorCaption);
    m_bstrBaseEditorCaption = SysAllocString(*pszBaseEditorCaption);
    return S_OK;
}

HRESULT CFigEditorView::GetEditorCaption(READONLYSTATUS dwReadOnly, BSTR *pbstrEditorCaption)
{
    ExpectedPtrRet(pbstrEditorCaption);
    BSTR bstrReadOnly = NULL;
    int iLenBase = 0;
    int iLenReadOnly = 0;
    HRESULT hr = S_OK;

    if (dwReadOnly == ROSTATUS_ReadOnly)
    {
        hr = m_pCVsPkg->GetLocalizedString( IDS_READONLY, &bstrReadOnly );  // see FigPkgUI string table
        if( FAILED( hr ))
            bstrReadOnly = SysAllocString( L"[ReadOnly]" );
        iLenReadOnly = SysStringLen(bstrReadOnly);
    }

    if (m_bstrBaseEditorCaption)
        iLenBase = SysStringLen(m_bstrBaseEditorCaption);

    if (iLenBase + iLenReadOnly == 0)
    {
        *pbstrEditorCaption = (BSTR) SysAllocStringLen(L"", 0);
        return NOERROR;
    }
    else
        *pbstrEditorCaption = (BSTR) SysAllocStringLen(NULL, iLenBase + iLenReadOnly + 1);


    if (*pbstrEditorCaption != NULL)
    {
        int CBWCH = (sizeof WCHAR);

        if (m_bstrBaseEditorCaption)
            memcpy(*pbstrEditorCaption, m_bstrBaseEditorCaption, ((iLenBase + 1) * CBWCH));

        if (iLenReadOnly)
        {
            memcpy(*pbstrEditorCaption + iLenBase, bstrReadOnly, ((iLenReadOnly + 1) * CBWCH));
            SysFreeString(bstrReadOnly);
        }

        return NOERROR;
    }
    else
    {
        if (iLenReadOnly)
            SysFreeString(bstrReadOnly);

        return E_OUTOFMEMORY;
    }
    return S_OK;
}

/*****************************************************************************
** IVsToolboxUser Implementation
*****************************************************************************/

STDMETHODIMP CFigEditorView::IsSupported(IDataObject *pDO)
{
    if(pDO == NULL)
        return S_FALSE;

    HRESULT hr;
    CComPtr<IEnumFORMATETC> pEnum;
    FORMATETC fmtetc;
    ULONG n;

    hr = pDO->EnumFormatEtc(DATADIR_GET, &pEnum);
    if(FAILED(hr))
        return hr;

    while ((S_OK == pEnum->Next(1, &fmtetc, &n)) && n == 1)
    {
        if(fmtetc.cfFormat == m_cf ||
            fmtetc.cfFormat == CF_TEXT)
        {
            // found a supported format I will accept your DO
            return S_OK;
        }
    }

    return S_FALSE;
}

STDMETHODIMP CFigEditorView::ItemPicked(IDataObject *pDO)
{
    ExpectedPtrRet(pDO);
    HRESULT hResult;

    listLines_type  Sel;
    _CreateSelectionList( Sel );    // save the current selection

    long nInsertAt = 0;             // if no selection, insert at first line

    if (Sel.size() > 0)
    {
        listLines_type::iterator pos = Sel.end();
        nInsertAt = (*--pos)->GetLineNumber();
    }

    _ASSERTE( NULL != pDO );
    hResult = PasteLinesFromDataObject( pDO, nInsertAt );

    return hResult;
}

/*****************************************************************************
** IDropTarget Implementation
*****************************************************************************/

bool CFigEditorView::m_bDropFormatOK;   // set if DragEnter determines a format is droppable
long CFigEditorView::m_nDropFocusLine;  // line number to show focus for drop target

// ::DragEnter
//
// Purpose:
//  Retrieves data described by a specific FormatEtc into a StgMedium
//  allocated by this function.  Used like GetClipboardData.
//  USER must FREE the hglobal in the STM if successful.
//
// Parameters:
//  pDataObject     IDataObject* describing the dragged data.
//  grfKeyState     DWORD current state of keyboard modifier keys.
//  pt              POINTL containing current cursor coordinates.
//  pdwEffect       DWORD* containing effect of the drag-and-drop; test, set on return.
//
// Return Value:
//  HRESULT         S_OK if successful, or E_OUTOFMEMORY, E_INVALIDARG, or E_UNEXPECTED.
//
STDMETHODIMP CFigEditorView::DragEnter( IDataObject * pDataObject, DWORD grfKeyState, POINTL pt, DWORD * pdwEffect)
{
    ExpectedPtrRet(pDataObject);
    ExpectedPtrRet(pdwEffect);
    // Test requested effect against key state (SHIFT or none = MOVE; CTRL = COPY)
    m_bDropFormatOK = true; // fake DragOver for initial call
    m_nDropFocusLine = -1;  // set drop target focus line
    HRESULT     hResult = DragOver( grfKeyState, pt, pdwEffect );
    m_bDropFormatOK = false;
    DWORD       dwRetEffect = *pdwEffect;

    // check data format
    _ASSERTE( NULL != pDataObject );
    CComPtr<IEnumFORMATETC> pEnumFmtEtc;
    FORMATETC   FmtEtc;
    hResult = pDataObject->EnumFormatEtc( DATADIR_GET, &pEnumFmtEtc );
    if (SUCCEEDED( hResult))
        while (S_OK == pEnumFmtEtc->Next( 1, &FmtEtc, NULL ))
        {
            if (m_cf == FmtEtc.cfFormat)    // only support dropping our custom format
            {
                m_bDropFormatOK = true;
                break;
            }
        }
    if (!m_bDropFormatOK    // no acceptable format found?
     || DROPEFFECT_NONE == dwRetEffect)
    {
        dwRetEffect = DROPEFFECT_NONE;
        DragLeave();    // call explicitly here in case DoDragDrop doesn't if DragEnter fails
    }

    *pdwEffect = dwRetEffect;
    return hResult;
}

// ::DragOver
//
// Purpose:
//  Retrieves data described by a specific FormatEtc into a StgMedium
//  allocated by this function.  Used like GetClipboardData.
//  USER must FREE the hglobal in the STM if successful.
//
// Parameters:
//  grfKeyState     DWORD current state of keyboard modifier keys.
//  pt              POINTL containing current cursor coordinates.
//  pdwEffect       DWORD* containing effect of the drag-and-drop; test, set on return.
//
// Return Value:
//  HRESULT         S_OK if successful, or E_OUTOFMEMORY, E_INVALIDARG, or E_UNEXPECTED.
//
STDMETHODIMP CFigEditorView::DragOver( DWORD grfKeyState, POINTL pt, DWORD * pdwEffect )
{
    ExpectedPtrRet(pdwEffect);
    DWORD       dwRetEffect = *pdwEffect;
    HRESULT     hResult = S_OK; // hope for the best

    _ASSERTE( NULL != m_pCEd );
    long        nDropFocusLine = m_pCEd->CalcDropLineFromPt( pt );

    if (nDropFocusLine != m_nDropFocusLine) // need to move focus line?
    {
        m_pCEd->UnselectDropTargetLine( m_nDropFocusLine );
        m_pCEd->SelectDropTargetLine( m_nDropFocusLine = nDropFocusLine );
    }

    if (m_bDropFormatOK)    // is data object format acceptable? (flag set in DragEnter)
    {
        // Test requested effect against key state (SHIFT or none = MOVE; CTRL = COPY)
        switch (grfKeyState & (MK_CONTROL | MK_SHIFT | MK_ALT))
        {
        case 0:         // move data by default
        case MK_SHIFT:  // permit move if requested
            dwRetEffect = (dwRetEffect & DROPEFFECT_MOVE)
                ? DROPEFFECT_MOVE
                : DROPEFFECT_NONE;
            break;
        case MK_CONTROL:
            dwRetEffect = (dwRetEffect & DROPEFFECT_COPY)
                ? DROPEFFECT_COPY
                : DROPEFFECT_NONE;
            break;
        default:        // attempt to link data or invalid key combination
            dwRetEffect = DROPEFFECT_NONE;
            break;
        }
    }
    else
        dwRetEffect = DROPEFFECT_NONE;
    *pdwEffect = dwRetEffect;

    return hResult;
}

// ::DragLeave
// Purpose:
//  removes any target feedback that is currently displayed; releases any references held
//  to the data transfer object
//
// Return:
//  HRESULT         S_OK or E_OUTOFMEMORY
STDMETHODIMP CFigEditorView::DragLeave( void )
{
    _ASSERTE( NULL != m_pCEd );
    m_pCEd->UnselectDropTargetLine( m_nDropFocusLine );
    return S_OK;
}

STDMETHODIMP CFigEditorView::Drop( IDataObject * pDataObject, DWORD grfKeyState, POINTL pt, DWORD * pdwEffect )
{
    ExpectedPtrRet(pDataObject);
    ExpectedPtrRet(pdwEffect);
    // Test requested effect against key state (SHIFT or none = MOVE; CTRL = COPY)
    HRESULT     hResult = DragOver( grfKeyState, pt, pdwEffect );
    DWORD       dwRetEffect = *pdwEffect;

    _ASSERTE( NULL != m_pCEd );
    m_pCEd->UnselectDropTargetLine( m_nDropFocusLine ); // remove target feedback

    // if drop permissible, check data format
    if (DROPEFFECT_NONE != dwRetEffect)
    {
        // Calculate drop location from pt
        long    nInsertAt = m_pCEd->CalcDropLineFromPt( pt );
        if (nInsertAt >= 0) // Did we get a line number back?
        {
            if (!m_fCompoundAction && m_srpIVsCompoundAction)
            {
                CComBSTR cbstrCompoundAction;
                if (m_fDragSource)
                    cbstrCompoundAction.LoadString(IDS_COMPOUNDACTION_DRAGDROP);
                else
                    cbstrCompoundAction.LoadString(IDS_COMPOUNDACTION_DROP);

                if (SUCCEEDED(m_srpIVsCompoundAction->OpenCompoundAction(cbstrCompoundAction)))
                    m_fCompoundAction = TRUE;
            }
            hResult = PasteLinesFromDataObject( pDataObject, nInsertAt );
            if (!m_fDragSource && m_fCompoundAction)
            {
                m_fCompoundAction = FALSE;
                if (SUCCEEDED(hResult))
                    m_srpIVsCompoundAction->CloseCompoundAction();
                else
                    m_srpIVsCompoundAction->AbortCompoundAction();
            }
        }
        else
            hResult = E_UNEXPECTED;
    }
    return hResult;
}


//IVsDocOutlineProvider
STDMETHODIMP CFigEditorView::GetOutlineCaption(
    /*[in] */ VSOUTLINECAPTION nCaptionType, 
    /*[out]*/ BSTR* pbstrCaption)
{
    if (m_srpIVsDocOutlineProvider != NULL)
        return m_srpIVsDocOutlineProvider->GetOutlineCaption(nCaptionType, pbstrCaption);

    return E_UNEXPECTED;
}


STDMETHODIMP CFigEditorView::GetOutline(
    /*[out]*/ HWND* phwnd, 
    /*[out]*/ IOleCommandTarget** ppCmdTarget)
{
    if (m_srpIVsDocOutlineProvider != NULL)
        return m_srpIVsDocOutlineProvider->GetOutline(phwnd, ppCmdTarget);

    return E_UNEXPECTED;

}


STDMETHODIMP CFigEditorView::ReleaseOutline(
    /*[in]*/ HWND hwnd, 
    /*[in]*/ IOleCommandTarget* pCmdTarget)
{
    if (m_srpIVsDocOutlineProvider != NULL)
        return m_srpIVsDocOutlineProvider->ReleaseOutline(hwnd, pCmdTarget);

    return E_UNEXPECTED;
}


STDMETHODIMP CFigEditorView::OnOutlineStateChange(
    /*[in]*/ VSOUTLINESTATES dwMask, 
    /*[in]*/ VSOUTLINESTATES dwState)
{
    if (m_srpIVsDocOutlineProvider != NULL)
        return m_srpIVsDocOutlineProvider->OnOutlineStateChange(dwMask, dwState);

    return E_UNEXPECTED;
}


// end of file EditView.cpp