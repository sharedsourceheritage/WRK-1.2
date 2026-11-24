
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential
//*****************************************************************************
// FigOutline.cpp
//
// Implementation of CFigOutline
// Provides a document outline whenever a fig document is the active
// window.
//
//*****************************************************************************


#include "stdafx.h"
#include "PrjInc.h"     // project includes
#include "FigOutline.h"
#include "vsmem.h"


//==========================================================================
//                                                               static data

ATOM         CFigOutline::ms_atomWndClass = NULL;
const TCHAR* CFigOutline::ms_lpszOutlineClass = _T("FigOutlineWindow");
CAtlString   CFigOutline::ms_rgstrFixedNodes[OUTLINE_FIXED_NODE_COUNT];
BOOL         CFigOutline::ms_fFixedNodesInitialized = FALSE;

//                                                               static data
//==========================================================================


//==========================================================================
//                                                      construct & destruct

HRESULT CFigOutline::CreateInstance(
    /* [out] */ IFigOutline**  ppIFigOutline)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::CreateInstance ") );

    ExpectedPtrRet(ppIFigOutline);
    InitParam(ppIFigOutline);

    CComObject<CFigOutline>* pco = NULL;
    HRESULT hr = CComObject<CFigOutline>::CreateInstance(&pco);
    IfFailRet(hr);
 
    ASSERT(pco != NULL);
    pco->AddRef();

    hr = pco->QueryInterface(
                IID_IFigOutline, 
                (void**)ppIFigOutline);

    if (pco)
        pco->Release();

    return hr;    
}


CFigOutline::CFigOutline()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CFigOutline::CFigOutline , this = 0x%x \n"), this );

    m_hwndParent = NULL;
    m_hwndMain   = NULL;
    m_hwndTree   = NULL;
    m_hilTree    = NULL;
    m_hFontUI    = NULL;

    for (int i = 0; i < OUTLINE_FIXED_NODE_COUNT; i++)
    {
        m_rghtiFixed[i] = NULL;
        m_rgnExpandedState[i] = 0;
    }

    m_dwIVsTextLinesEventsCookie = NULL;
    m_dwIVsBroadcastMessageEventsCookie = 0;
    m_vscookieIVsUserContext = NULL; 
    m_vscookieIVsUserContextUpdate = NULL; 

    m_fOutlineTreeInitialized = FALSE;
    m_fZombie    = TRUE;
}


CFigOutline::~CFigOutline()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CFigOutline::~CFigOutline , this = 0x%x \n"), this );

    ASSERT(m_fZombie); // must call Close first

    if (m_hwndMain != NULL)
    {
        DestroyWindow(m_hwndMain);
        m_hwndMain = NULL;
    }

    if (m_hilTree)
    {
        ImageList_Destroy(m_hilTree);
        m_hilTree = NULL;
    }

    if (m_hFontUI)
    {
        DeleteObject(m_hFontUI);
        m_hFontUI = NULL;
    }

    int  cOtii = m_rgotii.Count();
    for (int iIndex = 0; iIndex < cOtii; iIndex ++)
    {
        delete m_rgotii.GetAt(iIndex);
    }
    m_rgotii.RemoveAll();
}

//                                                      construct & destruct
//==========================================================================


//==========================================================================
//                                                               IFigOutline

STDMETHODIMP CFigOutline::Init(
    /* [in]  */ IVsTextLines* pIVsTextLines,
    /* [in]  */ HWND          hwndParent,
    /* [in]  */ IVsTextView*  pIVsTextViewPrimary) // can be NULL 
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::Init ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pIVsTextLines);
    IfNullRet(hwndParent);

    if ( !m_fZombie) //one init is enough
    {
        ASSERT(FALSE);
        return E_UNEXPECTED;
    }

    HRESULT hr = S_OK;
    m_fZombie = FALSE;

    m_srpIVsTextLines       = pIVsTextLines;
    m_hwndParent            = hwndParent;
    m_srpIVsTextViewPrimary = pIVsTextViewPrimary;

   	CComPtr<ILocalRegistry>	srpLocalRegistry;
    CComPtr<IVsShell> srpIVsShell;
	CComPtr<IConnectionPointContainer> srpConPtCont;
	CComPtr<IConnectionPoint> srpConPt;

    // get the name of document from the buffer
    CComPtr<IVsUserData> srpIVsUserData;
    hr = m_srpIVsTextLines->QueryInterface(IID_IVsUserData, (void**) &srpIVsUserData);
    _ASSERTE(SUCCEEDED(hr) && srpIVsUserData);
    IfFailGo(hr);

    VARIANT varMkDoc;
    VariantInit(&varMkDoc);

    hr = srpIVsUserData->GetData(GUID_VsBufferMoniker, &varMkDoc);
    _ASSERTE(SUCCEEDED(hr) && (varMkDoc.vt == VT_BSTR));
    IfFailGo(hr);

    m_cbstrMkDoc.Attach(varMkDoc.bstrVal);
    // don't free the variant, since m_cbstrMkDoc owns the BSTR now
    varMkDoc.vt = VT_EMPTY;

    // load the static data
    if (!ms_fFixedNodesInitialized)
    {
        for (int i = 0; i < OUTLINE_FIXED_NODE_COUNT; i++)
            ms_rgstrFixedNodes[i].LoadString(IDS_OUTLINE_NODE_ARROWS + i);
        ms_fFixedNodesInitialized = TRUE;
    }

    // create the document outline window
    hr = RegisterOutlineClass();
    IfFailGo(hr);

    HWND hwnd;
    ASSERT(m_hwndParent);
    hwnd = CreateWindowEx(0,                            // dwExStyle,
                          ms_lpszOutlineClass,          // window class,
                          _T("VS7FigDocOutline"),       // window name
                          WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,              // dwStyle
                          0, 0, 1, 1,                   // x, y, width, height
                          m_hwndParent,                 // hwndParent
                          NULL,                         // hMenu
                          _AtlModule.GetModuleInstance(),// hInstance
                          this);                        // lpParam

    ExpectedExprGo(hwnd);

    // setup an IVsTextLinesEvents advise on the buffer
	hr = m_srpIVsTextLines->QueryInterface( IID_IConnectionPointContainer,
											(void **)&srpConPtCont );
    IfFailGo(hr);

	hr = srpConPtCont->FindConnectionPoint( IID_IVsTextLinesEvents,
											&srpConPt );
    IfFailGo(hr);

	hr = srpConPt->Advise(
                    static_cast<IVsTextLinesEvents *>(this), 
                    &m_dwIVsTextLinesEventsCookie );
    IfFailGo(hr);
    _ASSERTE(m_dwIVsTextLinesEventsCookie);

    // sink to broadcast events, so we can forward them to the outline
    hr = _AtlModule.QueryService(SID_SVsShell, IID_IVsShell, (void**)&srpIVsShell);
    if (SUCCEEDED(hr))
    {
        _ASSERTE(srpIVsShell);
        srpIVsShell->AdviseBroadcastMessages(
                                static_cast<IVsBroadcastMessageEvents*>(this),
                                &m_dwIVsBroadcastMessageEventsCookie);
        _ASSERTE(m_dwIVsBroadcastMessageEventsCookie);
    }


	// get a parser
	// get the ILocalRegistry interface so we can use it to
	// load the COM parser from the shell's local registry.
	//
	hr = _AtlModule.QueryService( 
				SID_SLocalRegistry, IID_ILocalRegistry, 
				(void **)&srpLocalRegistry );
    IfFailGo(hr);

	// create our parser object (does CoCreateInstance if not in shell's registry)
	hr = srpLocalRegistry->CreateInstance( 
				CLSID_FigParse, NULL, IID_IFigParse, CLSCTX_INPROC_SERVER, 
				(LPVOID*)&m_srpIFigParse );
    IfFailGo(hr);

    hr = CreateUserContext(&m_srpIVsUserContext);
    IfFailGo(hr);

OnError:
    if (FAILED(hr))
    {
        // cleanup
        Close();
    }
    return hr;
}


STDMETHODIMP CFigOutline::Close()
{
    HRESULT hr    = S_OK;
    HRESULT hrRet = S_OK;

	// unadvise IVsTextLinesEvents from buffer
    if (m_dwIVsTextLinesEventsCookie != NULL)
    {
	    CComPtr<IConnectionPointContainer> srpConPtCont;
	    hr = m_srpIVsTextLines->QueryInterface( IID_IConnectionPointContainer,
											    (void **)&srpConPtCont );
	    if( SUCCEEDED( hr ))
	    {
		    CComPtr<IConnectionPoint> srpConPt;
		    hr = srpConPtCont->FindConnectionPoint( IID_IVsTextLinesEvents,
											        &srpConPt );
		    if( SUCCEEDED( hr ))
		    {
			    hr = srpConPt->Unadvise( m_dwIVsTextLinesEventsCookie );
                m_dwIVsTextLinesEventsCookie = NULL;

		    }
	    }
    }
    if (FAILED(hr))
        hrRet = hr;

    // unadvise from broadcase events source
    if (m_dwIVsBroadcastMessageEventsCookie != NULL)
    {
        CComPtr<IVsShell> srpIVsShell;

        hr = _AtlModule.QueryService(SID_SVsShell, IID_IVsShell, (void**)&srpIVsShell);
		if( SUCCEEDED( hr ))
		{
            _ASSERTE(srpIVsShell);
            srpIVsShell->UnadviseBroadcastMessages(m_dwIVsBroadcastMessageEventsCookie);
            m_dwIVsBroadcastMessageEventsCookie = NULL;
        }
    }
    if (FAILED(hr))
        hrRet = hr;

    m_srpIVsTextLines.Release();
	m_srpIFigParse.Release();			// release the parser
    m_srpIVsTextViewPrimary.Release();
    
    if ( (m_vscookieIVsUserContext != NULL) || (m_vscookieIVsUserContextUpdate != NULL))
    {
        RemoveSubcontext();
    }
    m_srpIVsUserContext.Release();
    ASSERT(!m_vscookieIVsUserContext);
    ASSERT(!m_vscookieIVsUserContextUpdate);

    m_fZombie = TRUE;

    return hrRet;
}



STDMETHODIMP CFigOutline::RegisterOutlineClass()
{

	// check and see if wndclass was already registered
	if (ms_atomWndClass != NULL)
	{
		return S_OK;
	}

    INITCOMMONCONTROLSEX iccex;
    iccex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    iccex.dwICC = ICC_TREEVIEW_CLASSES;

    InitCommonControlsEx(&iccex);

    WNDCLASS wc;

    wc.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = (WNDPROC)StaticWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = EXTRABYTES;
    wc.hInstance = _AtlModule.GetModuleInstance();
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = GetSysColorBrush(COLOR_BTNSHADOW);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = ms_lpszOutlineClass;

    ms_atomWndClass = RegisterClass(&wc);
	ASSERT(ms_atomWndClass);
	if (!ms_atomWndClass)
		return E_FAIL;

	return S_OK;
}

//                                                               IFigOutline
//==========================================================================


//==========================================================================
//                                                     IVsDocOutlineProvider

STDMETHODIMP CFigOutline::GetOutlineCaption(
    /*[in] */ VSOUTLINECAPTION nCaptionType, 
    /*[out]*/ BSTR* pbstrCaption)
{
    CheckZombieState(m_fZombie);
    ExpectedPtrRet(pbstrCaption);
    InitParam(pbstrCaption);

    if ( (nCaptionType != OUTLINECAPTION_FULL) &&
         (nCaptionType != OUTLINECAPTION_SIMPLE))
    {
        ASSERT(FALSE);
	    return E_NOTIMPL;
    }

    CComBSTR cbstrCaption;

    if ((nCaptionType == OUTLINECAPTION_SIMPLE) || !m_cbstrMkDoc)
    {
        cbstrCaption.LoadString(IDS_OUTLINE_SHORT);
    }
    else
    {
        cbstrCaption.LoadString(IDS_OUTLINE_FULL);
        if (cbstrCaption.Length() == 0)
            return E_OUTOFMEMORY;
        cbstrCaption.Append(m_cbstrMkDoc);
    }

    if (cbstrCaption.Length() != 0)
        return cbstrCaption.CopyTo(pbstrCaption);
    else
        return E_OUTOFMEMORY;
}


STDMETHODIMP CFigOutline::GetOutline(
    /*[out]*/ HWND* phwnd, 
    /*[out]*/ IOleCommandTarget** ppCmdTarget)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::GetOutline : ")
        _T(", this = 0x%x,  \n"), this); 

    CheckZombieState(m_fZombie);
    ExpectedPtrRet(phwnd);
    ExpectedPtrRet(ppCmdTarget);
    InitParam(phwnd);
    InitParam(ppCmdTarget);

    if (m_hwndMain == NULL)
        return E_UNEXPECTED;

    HRESULT hr = E_UNEXPECTED;

    hr = UpdateOutlineTree(FALSE);
    IfFailRet(hr);

    // add our context
    hr = AddSubcontext();
    IfFailRet(hr);

    *phwnd = m_hwndMain;

    *ppCmdTarget = static_cast<IOleCommandTarget*>(this);
    (*ppCmdTarget)->AddRef();

    return S_OK;
}


STDMETHODIMP CFigOutline::ReleaseOutline(
    /*[in]*/ HWND hwnd, 
    /*[in]*/ IOleCommandTarget* pCmdTarget)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::ReleaseOutline : ")
        _T(", this = 0x%x,  \n"), this); 

    CheckZombieState(m_fZombie);
	ExpectedExprRet(hwnd == m_hwndMain);
	ExpectedExprRet(pCmdTarget == static_cast<IOleCommandTarget*>(this));

    // remove our context
    HRESULT hr = RemoveSubcontext();
    IfFailRet(hr);

    return S_OK;
}


STDMETHODIMP CFigOutline::OnOutlineStateChange(
    /*[in]*/ VSOUTLINESTATES dwMask, 
    /*[in]*/ VSOUTLINESTATES dwState)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::OnOutlineStateChange : ")
        _T(", this = 0x%x,  \n"), this); 

    CheckZombieState(m_fZombie);
    return S_OK;
}


STDMETHODIMP CFigOutline::UpdateOutlineTree(
    /* [in] */ BOOL fForceUpdate)
{
    CheckZombieState(m_fZombie);
    // if the tree is initilized and we are not forced to update
    // then just return
    if ( m_fOutlineTreeInitialized && !fForceUpdate)
        return S_OK;

    // the tree should be created at this time
    if ( (m_hwndTree == NULL) || (m_srpIVsTextLines == NULL))
    {
        ASSERT(FALSE);
        return E_UNEXPECTED;
    }

    HRESULT hr = S_OK;

    SendMessage(m_hwndTree, WM_SETREDRAW, FALSE, 0);
    TreeView_DeleteAllItems(m_hwndTree);

    AddFixedNodes();
	long cLines = 0;
	hr = m_srpIVsTextLines->GetLineCount( &cLines );
    IfFailGo(hr);

	TextLineChange tlc;
	tlc.iStartLine = 0;				// starting line number
	tlc.iStartIndex = 0;
	tlc.iOldEndLine = 0;
	tlc.iOldEndIndex = 0;
	tlc.iNewEndLine = cLines - 1;		// ending line number
	tlc.iNewEndIndex = 1;

    m_fOutlineTreeInitialized = TRUE;
	
    OnChangeLineText( &tlc, TRUE );

OnError:

    SendMessage(m_hwndTree, WM_SETREDRAW, TRUE, 0);

    return hr;
}

//                                                     IVsDocOutlineProvider
//==========================================================================


//==========================================================================
//                                                          IOleCommandTarget

STDMETHODIMP CFigOutline::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    CheckZombieState(m_fZombie);

    IfNullRet(pguidCmdGroup);
    IfNullRet(prgCmds);
    ExpectedExprRet(cCmds == 1);

    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;
    prgCmds[0].cmdf = 0;
    return hr;
}

STDMETHODIMP CFigOutline::Exec(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdExecOpt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut)
{
    CheckZombieState(m_fZombie);
    IfNullRet(pguidCmdGroup);
    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;
    return hr;
}

//                                                          IOleCommandTarget
//==========================================================================



//==========================================================================
//                                                        IVsTextLinesEvents

// The text buffer advises us of any changes by calling this method
//
STDMETHODIMP_(void) CFigOutline::OnChangeLineText(
					/*[in] */ const TextLineChange *pTextLineChange,
					/*[in] */ BOOL fLast )
{   
    _ASSERTE(pTextLineChange != NULL);
    if (!pTextLineChange)
        return;
    ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
        _T(": CFigOutline::OnChangeLineText : ")
        _T(", this = 0x%x, pTextLineChange = %d %d %d %d %d %d  \n"), 
                this,
		        pTextLineChange->iStartLine,		// starting line number
		        pTextLineChange->iStartIndex,
		        pTextLineChange->iOldEndLine,		// for deleted line
		        pTextLineChange->iOldEndIndex,
		        pTextLineChange->iNewEndLine,		// ending line number
		        pTextLineChange->iNewEndIndex );

    // check if the tree is init-ed
    // if not - do not bother now - we will take the data during the tree init
    if ( m_fZombie || !m_fOutlineTreeInitialized)
        return;

    long nLine;

	// anything to delete
	if( (pTextLineChange->iOldEndLine  != pTextLineChange->iStartLine ) ||
	    (pTextLineChange->iOldEndIndex != pTextLineChange->iStartIndex ) )
    {
        // delete the lines 
        for (nLine = pTextLineChange->iOldEndLine; 
             nLine > pTextLineChange->iStartLine; 
             nLine --)
        {
			DeleteLine(nLine);
        }
        // set the updated line
        nLine = pTextLineChange->iStartLine;
		SetLine(nLine);
    }

	// anything to add
	if( (pTextLineChange->iNewEndLine  != pTextLineChange->iStartLine ) ||
	    (pTextLineChange->iNewEndIndex != pTextLineChange->iStartIndex ) )
    {        
        // set the updated line
        nLine = pTextLineChange->iStartLine;
		SetLine(nLine);

        // add the new lines 
        for (nLine = pTextLineChange->iStartLine + 1; 
             nLine <= pTextLineChange->iNewEndLine; 
             nLine ++)
        {
		    AddLine(nLine);
        }
    }

}

STDMETHODIMP_(void) CFigOutline::OnChangeLineAttributes (
					/*[in] */ long iFirstLine,
					/*[in] */ long iLastLine )
{
    return;
}


STDMETHODIMP CFigOutline::AddLine( 
    /* [in] */ long nLine)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::AddLine : ")
        _T(" this = 0x%x, line = %d \n"), this, nLine);

    CheckZombieState(m_fZombie);
    _ASSERTE(m_hwndTree);

	// We have to renumber the subsequent lines.
    int  cOtii = m_rgotii.Count();
    for (int iIndex = 0; iIndex < cOtii; iIndex ++)
    {
        long* pnCurLine = &((m_rgotii.GetAt(iIndex))->lLineNumber);
		if( *pnCurLine >= nLine)
        {
            ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
                _T(": CFigOutline::AddLine : ")
                _T(", this = 0x%x, m_rgotii[%d] with line=%d to be incremented \n"), 
                this, iIndex, *pnCurLine);
			(*pnCurLine)++; 
        }
	}

    // now check the new line
	FigLineType flt = FigInvalid;
	long lP1 = 0;
	long lP2 = 0;
	long lP3 = 0;
	long lP4 = 0;
	CComBSTR cbstrComment;

	ParseLine(nLine, &flt, &lP1, &lP2, &lP3, &lP4, &cbstrComment);

    ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
        _T(": CFigOutline::AddLine : ")
        _T(", this = 0x%x, line = %d, flt=%d, lP1=%d, lP2=%d, lP3=%d,lP4=%d \n"), 
        this, nLine, flt, lP1, lP2, lP3, lP4);

    if ( (flt < FigArrow) || (flt >= FigInvalid) )
        return S_OK;

    // add it to the tree
    TCHAR buf[50];
    CAtlString strData;
    if (flt == FigComment)
    {
        if (cbstrComment.Length() != 0)
            strData = cbstrComment;
    }
    else
    {
        strData =  _ltot(lP1, buf, 10 );
        strData += _T(" ");
        strData +=  _ltot(lP2, buf, 10 );
        strData += _T(" ");
        strData +=  _ltot(lP3, buf, 10 );
        if (flt != FigCircle)
        {
            strData += _T(" ");
            strData +=  _ltot(lP4, buf, 10 );
        }
    }

    // OutlineTvItemInfo struct is attached to each treeview item 
    // See the description in the structure declaration.
    OutlineTvItemInfo* potii = new OutlineTvItemInfo;
    IfFailAllocRet(potii);
    potii->fltFigType  = flt;
    potii->lLineNumber = nLine;

    // add it to the array
    m_rgotii.Add(potii);
    
    // add it to the tree
    TV_INSERTSTRUCT tvis;

    tvis.hParent = GetParentNode(flt);
    tvis.hInsertAfter = TVI_SORT;
    tvis.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_STATE | TVIF_PARAM | TVIF_TEXT;
    tvis.item.stateMask = 0;
    tvis.item.iImage = flt;
    tvis.item.iSelectedImage = flt;
    tvis.item.lParam = (LPARAM)potii;
    tvis.item.pszText = (LPTSTR)(LPCTSTR)strData;

    TreeView_InsertItem(m_hwndTree, &tvis);
    return S_OK;
}


#ifndef MAX_FIG_MARKS
#define MAX_FIG_MARKS 100
#endif

// called to parse a line of text from the buffer
STDMETHODIMP CFigOutline::ParseLine( 
    /* [in]  */ long nLine, 
    /* [out] */ FigLineType *pType, 
    /* [out] */ long *pP1, 
    /* [out] */ long *pP2, 
	/* [out] */ long *pP3, 
    /* [out] */ long *pP4, 
    /* [out] */ BSTR *pbstrComment)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::ParseLine : ")
        _T(", this = 0x%x \n"), this); 

    CheckZombieState(m_fZombie);

    ExpectedPtrRet(m_srpIFigParse);
    ExpectedPtrRet(m_srpIVsTextLines);
    return m_srpIFigParse->ParseLine(m_srpIVsTextLines, nLine, 
                                     pType, pP1, pP2, pP3, pP4, pbstrComment);
}


HTREEITEM CFigOutline::GetParentNode(FigLineType flt)
{
    switch (flt)
    {
        case FigArrow:
            return m_rghtiFixed[OutlineGroupArrows];
        case FigCircle:
            return m_rghtiFixed[OutlineGroupCircles];
        case FigRectangle:
            return m_rghtiFixed[OutlineGroupRectangles];
        case FigComment:
            return m_rghtiFixed[OutlineGroupComments];
        default:
            ASSERT (FALSE); // unknown flt type
            return m_rghtiFixed[OutlineRoot];
    }
}


STDMETHODIMP CFigOutline::DeleteLine(
    /* [in] */ long nLineIndex)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::DeleteLine : ")
        _T(", this = 0x%x, line = %d \n"), this, nLineIndex); 

    CheckZombieState(m_fZombie);

    HRESULT hr = S_OK;

    HTREEITEM   htiParent    = NULL;
    HTREEITEM   hti          = NULL;
    OutlineTvItemInfo* potii = NULL;

    hr = FindTreeItemFromLineNumber(nLineIndex, &htiParent, &hti, &potii);

    if (hr == S_OK)
    {
        ASSERT( (htiParent!=NULL) && (hti!=NULL) && (potii!=NULL));

        TreeView_DeleteItem(m_hwndTree, hti);
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigOutline::DeleteLine : ")
            _T(", this = 0x%x, line = %d  - deleted \n"), this, nLineIndex); 

        // remove from the array
        delete potii;
        m_rgotii.Remove(potii);

    }
    else
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CFigOutline::DeleteLine : ")
            _T(", this = 0x%x, line = %d  - not deleted \n"), this, nLineIndex); 
    }

	// We have to renumber the subsequent lines.
    int  cOtii = m_rgotii.Count();
    for (int iIndex = 0; iIndex < cOtii; iIndex ++)
    {
        long* pnCurLine = &((m_rgotii.GetAt(iIndex))->lLineNumber);
		if( *pnCurLine >= nLineIndex)
        {
            ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
                _T(": CFigOutline::DeleteLine : ")
                _T(", this = 0x%x, m_rgotii[%d] with line=%d to be decremented \n"), 
                this, iIndex, *pnCurLine);
			(*pnCurLine)--; 
        }
	}

    return hr;

}

STDMETHODIMP CFigOutline::SetLine( 
    /* [in] */ long nLine)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::SetLine : ") 
        _T(" this = 0x%x, line = %d \n"), this, nLine );
    
    CheckZombieState(m_fZombie);

	HRESULT hr = S_OK;
    DeleteLine(nLine);
    AddLine(nLine);
    return hr;
}


STDMETHODIMP CFigOutline::FindTreeItemFromLineNumber(
    /* [in]  */ long       nLineIndex,
    /* [out] */ HTREEITEM* phtiParent,
    /* [out] */ HTREEITEM* phti,
    /* [out] */ OutlineTvItemInfo** ppotii)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFigOutline::FindTreeItemFromLineNumber : ")
        _T(", this = 0x%x, line = %d \n"), this, nLineIndex); 

    ExpectedPtrRet(phtiParent); 
    ExpectedPtrRet(phti);       
    ExpectedPtrRet(ppotii);       
    *phtiParent = NULL;
    *phti       = NULL;
    *ppotii     = NULL;

    // find the item we want to delete
    for (int i = 0; i < OUTLINE_FIXED_NODE_COUNT - 1; i++)
    {
        HTREEITEM htiParent = m_rghtiFixed[i];
        TVITEM    tvItem;
        HTREEITEM hItem;

        hItem = TreeView_GetChild(m_hwndTree, htiParent);
        while (hItem)
        {
            tvItem.hItem = hItem;
            tvItem.mask = TVIF_PARAM | TVIF_CHILDREN;
            TreeView_GetItem(m_hwndTree, &tvItem);
        
            OutlineTvItemInfo* potii = (OutlineTvItemInfo*)tvItem.lParam;
            if (potii == NULL)
            {
                ASSERT(FALSE);
            } 
            else
            {
                ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
                    _T(": CFigOutline::FindTreeItemFromLineNumber : ")
                    _T(", this=0x%x, potii=0x%x, fltFigType=%d, lLineNumber=%d \n"), 
                    this, potii, potii->fltFigType, potii->lLineNumber); 
                if (nLineIndex == potii->lLineNumber)
                {
                    *phtiParent = htiParent;
                    *phti       = hItem;
                    *ppotii     = potii;
                    ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
                        _T(": CFigOutline::FindTreeItemFromLineNumber : ")
                        _T(", this = 0x%x, line = %d  - found \n"), this, nLineIndex); 
                    return S_OK;
                }
            }
            hItem = TreeView_GetNextSibling(m_hwndTree, hItem);
        }
    }

    ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
        _T(": CFigOutline::FindTreeItemFromLineNumber : ")
        _T(", this = 0x%x, line = %d  - not found \n"), this, nLineIndex); 
    return S_FALSE;
}

//                                                        IVsTextLinesEvents
//==========================================================================


//==========================================================================
//                                                 IVsBroadcastMessageEvents

STDMETHODIMP CFigOutline::OnBroadcastMessage(
                    /*[in]*/ UINT   msg,
                    /*[in]*/ WPARAM wParam,
                    /*[in]*/ LPARAM lParam)
{
    // Propagate message to child window
    SendMessage(m_hwndTree, msg, wParam, lParam);

    return S_OK;
}

//                                                 IVsBroadcastMessageEvents
//==========================================================================


//==========================================================================
//                                                    Context Window support

STDMETHODIMP CFigOutline::AddSubcontext()
{
    // have we initialized the m_srpIVsUserContext?
    ExpectedExprRet(m_srpIVsUserContext != NULL);

    // check if we have non-NULL cookies already
    ExpectedExprRet(m_vscookieIVsUserContext == NULL);
    ExpectedExprRet(m_vscookieIVsUserContextUpdate == NULL);

    HRESULT hr = S_OK;

    // get the doc outline user context
    CComPtr<IVsUserContext> srpIVsUserContext_DocOutline;
    hr = GetDocOutlineUserContext(&srpIVsUserContext_DocOutline);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsUserContext_DocOutline != NULL);

    // add our subcontext
    hr = srpIVsUserContext_DocOutline->AddSubcontext(            
            /* IVsUserContext* pSubCtx */ m_srpIVsUserContext,
            /* int lPriority           */ VSUC_Priority_ToolWndSel,
            /* VSCOOKIE* pdwCookie     */ &m_vscookieIVsUserContext);
    IfFailRet(hr);
    ExpectedExprRet(m_vscookieIVsUserContext != NULL);

    hr = m_srpIVsUserContext->AdviseUpdate(
        /* IVsUserContextUpdate* */ static_cast<IVsUserContextUpdate*>(this),
        /* VSCOOKIE*             */ &m_vscookieIVsUserContextUpdate);
    IfFailRet(hr);
    ExpectedExprRet(m_vscookieIVsUserContextUpdate != NULL);

    return hr;
}


STDMETHODIMP CFigOutline::RemoveSubcontext()
{
    // check if we have a NULL cookie
    ASSERT(m_vscookieIVsUserContext != NULL);
    ASSERT(m_vscookieIVsUserContextUpdate != NULL);

    HRESULT hr = S_FALSE;

    if (m_vscookieIVsUserContextUpdate && (m_srpIVsUserContext != NULL))
    {
        hr = m_srpIVsUserContext->UnadviseUpdate(
            /* VSCOOKIE */ m_vscookieIVsUserContextUpdate);        
        ASSERT(SUCCEEDED(hr));// check the result but continue

        m_vscookieIVsUserContextUpdate = NULL;
    }

    if (m_vscookieIVsUserContext)
    {
        // get the doc outline user context
        CComPtr<IVsUserContext> srpIVsUserContext_DocOutline;
        hr = GetDocOutlineUserContext(&srpIVsUserContext_DocOutline);
        if (SUCCEEDED(hr) && (srpIVsUserContext_DocOutline != NULL))
        {
            // remove our subcontext
            hr = srpIVsUserContext_DocOutline->RemoveSubcontext(            
                    /* VSCOOKIE* dwCookie     */ m_vscookieIVsUserContext);
        }
        ASSERT(SUCCEEDED(hr));// check the result but continue

        m_vscookieIVsUserContext = NULL;
    }

    return hr;
}
 
   
STDMETHODIMP CFigOutline::GetDocOutlineUserContext(
    /* [out] */ IVsUserContext** ppIVsUserContext)
{
    HRESULT hr = S_OK;

    // get the IVsUIShell
    CComPtr<IVsUIShell> srpIVsUIShell = _AtlModule.GetIVsUIShell();
    ExpectedExprRet(srpIVsUIShell!=NULL);

    // get the DocOutline window frame from the shell
    CComPtr<IVsWindowFrame> srpIVsWindowFrame;
    hr = srpIVsUIShell->FindToolWindow(
            /* VSFINDTOOLWIN grfFTW           */ NULL,
            /* REFGUID rguidPersistenceSlot   */ GUID_DocOutline,
            /* IVsWindowFrame **ppWindowFrame */ &srpIVsWindowFrame);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsWindowFrame != NULL);

    // get the UserContext
    CComVariant cvar;
    hr = srpIVsWindowFrame->GetProperty(VSFPROPID_UserContext, &cvar);
    IfFailRet(hr);
    ExpectedExprRet((V_VT(&cvar) == VT_UNKNOWN) && V_UNKNOWN(&cvar));
    
    hr = V_UNKNOWN(&cvar)->QueryInterface(
            IID_IVsUserContext, 
            (void**)ppIVsUserContext);

    return hr;
}


STDMETHODIMP CFigOutline::UpdateUserContext(
    /* [in] */ IVsUserContext * pCtx, 
    /* [in] */ VSCOOKIE dwCookie)
{
    ExpectedPtrRet(pCtx);

    HRESULT hr = S_OK;

    // clean the user context
    hr = pCtx->RemoveAttribute(NULL, NULL);
    ASSERT(SUCCEEDED(hr));

    // get the selection
    HTREEITEM htiSelected = TreeView_GetSelection(m_hwndTree);

    // add the new attributes
    // check if the selection is a folder node
    if (htiSelected == m_rghtiFixed[OutlineGroupArrows])
    {
        hr = pCtx->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.folder.arrow");
    }
    else if (htiSelected == m_rghtiFixed[OutlineGroupCircles])
    {
        hr = pCtx->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.folder.circle");
    }
    else if (htiSelected == m_rghtiFixed[OutlineGroupRectangles])
    {
        hr = pCtx->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.folder.rectangle");
    }
    else if (htiSelected == m_rghtiFixed[OutlineGroupComments])
    {
        hr = pCtx->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.folder.comment");
    }
    else if (htiSelected == m_rghtiFixed[OutlineRoot])
    {
        // nothing here for now
    }
    else
    {
        // it must be a node in a folder
        // get the information about the node
        TVITEM tvi;
        tvi.mask = TVIF_PARAM | TVIF_HANDLE;
        tvi.hItem = htiSelected;

        TreeView_GetItem(m_hwndTree, &tvi);

        OutlineTvItemInfo* potii = (OutlineTvItemInfo*)tvi.lParam;
        if (!potii)
            ASSERT(FALSE);
        else
            hr = AddUserContextForFigLineType(pCtx, potii->fltFigType);
    }
    
    ASSERT(SUCCEEDED(hr));
    return hr;
}
//                                                    Context Window support
//==========================================================================


//==========================================================================
//                                                     Window implementation

// StaticWndProc - Window procedure registered for fig outline windows
LRESULT CFigOutline::StaticWndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    CFigOutline* pThis = NULL;

    if (iMsg == WM_CREATE)
    {
        // store the 'this' pointer into the the window data the first
        // time around
        pThis = (CFigOutline*)((LPCREATESTRUCT)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, EB_THIS, (LONG_PTR)pThis);
        pThis->m_hwndMain = hwnd;
    }
    else
        pThis = (CFigOutline*)GetWindowLongPtr(hwnd, EB_THIS);

    if (pThis)
        return pThis->WndProc(iMsg, wParam, lParam);
    else
        return DefWindowProc(hwnd, iMsg, wParam, lParam);
}


// WndProc - Window procedure for outline window
LRESULT CFigOutline::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
            return OnCreate();
        case WM_SIZE:
            return OnSize(wParam, LOWORD(lParam), HIWORD(lParam));
        case WM_SETFOCUS:
            return OnSetFocus((HWND)wParam);
            
        case WM_NOTIFY:
            {
                NMHDR* pnmh = (NMHDR*)lParam;
                if (pnmh->idFrom == IDC_DOCOUTLINE_TREE)
                {
                    switch (pnmh->code)
                    {
                        case NM_DBLCLK:
                            return OnDblClickItem();
                        case TVN_KEYDOWN: // works on win98, TVN_KEYDOWNA isn't defined
                            if (((NMTVKEYDOWN*)pnmh)->wVKey == VK_RETURN)
                            {
                                // enter key press == double click
                                return OnDblClickItem();
                            }
                            break;
                        case TVN_SELCHANGED:
                        case TVN_SELCHANGEDA: // this is for win98
                            return OnSelChangeItem();
                    }
                }
            }
            return 0;
        default:
            return DefWindowProc(m_hwndMain, uMsg, wParam, lParam);
    }
}


LRESULT CFigOutline::OnCreate()
{
    // create the tree itself
    RECT rc;
    GetClientRect(m_hwndMain, &rc);

    m_hwndTree = CreateWindowEx(0,                                          // dwExStyle
                                WC_TREEVIEW,                                // lpszClassName
                                _T("VS7FigDocOutlineTree"),                 // lpszWindowName
                                WS_CHILD | WS_VISIBLE | TVS_HASLINES |      // dwStyle
                                TVS_SHOWSELALWAYS | TVS_HASBUTTONS,
                                1, 1,                                       // x, y
                                rc.right - 2, rc.bottom - 2,                // nWidth, nHeight
                                m_hwndMain,                                 // hwndParent
                                (HMENU)IDC_DOCOUTLINE_TREE,                 // hMenu
                                _AtlModule.GetModuleInstance(),                // hInstance
                                NULL);                                      // lpParam
    _ASSERTE(m_hwndTree);

    if (m_hwndTree)
        InitTree();

    return 0;
}


// InitTree - Initializes the outline tree
void CFigOutline::InitTree()
{
    _ASSERTE(m_hwndTree);

    InitFont();

    // set the ui font
    if (m_hFontUI)
        SendMessage(m_hwndTree, WM_SETFONT, (WPARAM)m_hFontUI, MAKELPARAM(TRUE, 0));

    // create the image list we use for the tree
    if (m_hilTree == NULL)
    {
        m_hilTree = ImageList_LoadBitmap(
                        _AtlModule.GetModuleInstance(),
                        MAKEINTRESOURCE(IDB_IMAGELIST),
                        16, 0, RGB(0,255,0));
    }
   _ASSERTE(m_hilTree);

    // set the image list
    TreeView_SetImageList(m_hwndTree, m_hilTree, TVSIL_NORMAL);

    AddFixedNodes();
}


// InitFont - Initialize the font to be used in the outline
void CFigOutline::InitFont()
{
    _ASSERTE(!m_hFontUI);
    if (m_hFontUI)
        return;

    HRESULT hr;
    CComPtr<IUIHostLocale> srpIUIHostLocale;
    UIDLGLOGFONT lfDlg;

    hr = _AtlModule.QueryService(SID_SUIHostLocale, IID_IUIHostLocale, (void**)&srpIUIHostLocale);
    IfFailGo(hr);

    hr = srpIUIHostLocale->GetDialogFont(&lfDlg);
    IfFailGo(hr);

    m_hFontUI = CreateFontIndirect((LOGFONT*)&lfDlg);
    ExpectedPtrGo(m_hFontUI);

OnError:
    if (FAILED(hr))
    {
        // default font if we fail is Tahoma, 13px tall (== 8.25 pt)
        m_hFontUI = CreateFont(13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _T("Tahoma"));
    }
    _ASSERTE(m_hFontUI);
}


void CFigOutline::AddFixedNodes()
{
    _ASSERTE(m_hwndTree);

    TV_INSERTSTRUCT tvis;

    // add the root node
    tvis.hParent = TVI_ROOT;
    tvis.hInsertAfter = TVI_FIRST;
    tvis.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_STATE | TVIF_PARAM | TVIF_TEXT;
    tvis.item.state = TVIS_EXPANDED;
    tvis.item.stateMask = TVIS_EXPANDED;
    tvis.item.iImage = GetFixedNodeImageIndex(OutlineRoot);
    tvis.item.iSelectedImage = GetFixedNodeImageIndex(OutlineRoot);
    tvis.item.lParam = NULL;
    tvis.item.pszText = ms_rgstrFixedNodes[OutlineRoot].LockBuffer();
    m_rghtiFixed[OutlineRoot] = TreeView_InsertItem(m_hwndTree, &tvis);
    ms_rgstrFixedNodes[OutlineRoot].UnlockBuffer();

    tvis.hParent = m_rghtiFixed[OutlineRoot];
    tvis.hInsertAfter = TVI_LAST;
    tvis.item.stateMask = TVIS_EXPANDED;

    // add the group nodes
    for (int i = OutlineGroupArrows; i < OutlineRoot; i++)
    {
        tvis.item.iImage = GetFixedNodeImageIndex((OutlineFixedNode) i);
        tvis.item.iSelectedImage = GetFixedNodeImageIndex((OutlineFixedNode)i);
        tvis.item.lParam = NULL;
        tvis.item.state = m_rgnExpandedState[i];
        tvis.item.pszText = ms_rgstrFixedNodes[i].LockBuffer();
        m_rghtiFixed[i] = TreeView_InsertItem(m_hwndTree, &tvis);
        ms_rgstrFixedNodes[i].UnlockBuffer();
    }
}

int CFigOutline::GetFixedNodeImageIndex(OutlineFixedNode ofn)
{
    switch (ofn)
    {
    case OutlineRoot:
        return ILI_FIGURES;
    case OutlineGroupArrows:
    case OutlineGroupCircles:
    case OutlineGroupRectangles:
    case OutlineGroupComments:
        return ILI_FOLDER;
    default:
        ASSERT (FALSE); // unknown node type
        return 0;
    }
}

LRESULT CFigOutline::OnSize(WPARAM nFlag, int cx, int cy)
{
    // size the tree to fit the window, leaving a 1 pixel padding
    if (nFlag != SIZE_MINIMIZED)
        MoveWindow(m_hwndTree, 1, 1, cx - 2, cy - 2, TRUE);

    return 0;
}


LRESULT CFigOutline::OnSetFocus(HWND hwndLastFocus)
{
    if (hwndLastFocus != m_hwndTree)
    {
        IVsUIShell* pUIShell = _AtlModule.GetIVsUIShell();      // un-addref'd
        if (pUIShell)
        {
            pUIShell->UpdateCommandUI(FALSE);
        }

        SetFocus(m_hwndTree);
    }
    return 0;
}


LRESULT CFigOutline::OnDblClickItem()
{

    HTREEITEM htiSelected = TreeView_GetSelection(m_hwndTree);

    NavigateToItem(htiSelected, TRUE);
    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// Navigates to the view where the item is defined if its not a fixed node

BOOL CFigOutline::NavigateToItem(HTREEITEM hti, BOOL fActivateSource)
{
    _ASSERTE(hti);

    TVITEM tvi;

    tvi.mask = TVIF_PARAM | TVIF_HANDLE;
    tvi.hItem = hti;

    TreeView_GetItem(m_hwndTree, &tvi);
    if (tvi.lParam == NULL)
        return FALSE;

    OutlineTvItemInfo* potii = (OutlineTvItemInfo*)tvi.lParam;

    if (m_srpIVsTextViewPrimary == NULL) //not a text view
        return FALSE;

    long nLineNumber = potii->lLineNumber;
    HRESULT hr;

    long nLineLength;
	hr = m_srpIVsTextLines->GetLengthOfLine(nLineNumber, &nLineLength );
	if( FAILED(hr) || (nLineLength == 0) ) 
        return FALSE;

    if (fActivateSource)
    {

        CComPtr<IVsTextManager> srpTextMgr;
        hr = _AtlModule.QueryService(
                            SID_SVsTextManager, 
                            IID_IVsTextManager,
                            (void**)&srpTextMgr);
        if (FAILED(hr))
            return FALSE;
        
        hr = srpTextMgr->NavigateToLineAndColumn(
                            m_srpIVsTextLines, 
                            LOGVIEWID_Primary,
                            nLineNumber, 0,
                            nLineNumber, nLineLength);
        _ASSERTE(SUCCEEDED(hr));
        if (FAILED(hr))
            return FALSE;
    }

    m_srpIVsTextViewPrimary->CenterLines(nLineNumber, 0);
    hr = m_srpIVsTextViewPrimary->SetSelection(
            nLineNumber, 
            0, 
            nLineNumber, 
            nLineLength);
    if (FAILED(hr))
        return FALSE;

    return TRUE;
}


LRESULT CFigOutline::OnSelChangeItem()
{
    if (m_srpIVsUserContext != NULL)
        m_srpIVsUserContext->SetDirty(TRUE);
   
    return 0;
}

//                                                     Window implementation
//==========================================================================


