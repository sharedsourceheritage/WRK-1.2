
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// CodeWnMg.h : Declaration of CFigCodeWindowManager and CFigTextViewFilter

#pragma once

/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CFigTextViewFilter;
class CVsPackage;
class CFigMethodData;
class CFigStatementCompletion;
typedef list<CFigTextViewFilter*> listTextView_type;  

/////////////////////////////////////////////////////////////////////////////
// CFigCodeWindowManager

class CFigCodeWindowManager :
    public IVsDocOutlineProvider,
	public IVsCodeWindowManager
{
public:
	CFigCodeWindowManager( CVsPackage *pCVsPkg, IVsCodeWindow *pCodeWin );
	~CFigCodeWindowManager();
	
	BEGIN_INTERFACE
	// *** IUnknown methods **********************************************************
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// *** IVsCodeWindowManager methods ******************************************************

	// Called by a code window to provide opportunity to add adornments
	// (additional split panes) to the code window, etc.
	STDMETHODIMP AddAdornments();

	// The language has changed, or the code window is going away; this
	// code win mgr needs to now remove its adornments
 	STDMETHODIMP RemoveAdornments();

	// A new text view has been created in the code window; now's your
	// chance to provide a filter for it.
	STDMETHODIMP OnNewView( /*[in]*/ IVsTextView *pView );

    //IVsDocOutlineProvider
	STDMETHOD(GetOutlineCaption)(
        /*[in] */ VSOUTLINECAPTION nCaptionType, 
        /*[out]*/ BSTR* pbstrCaption);
	STDMETHOD(GetOutline)(
        /*[out]*/ HWND* phwnd, 
        /*[out]*/ IOleCommandTarget** ppCmdTarget);
	STDMETHOD(ReleaseOutline)(
        /*[in]*/ HWND hwnd, 
        /*[in]*/ IOleCommandTarget* pCmdTarget);
	STDMETHOD(OnOutlineStateChange)(
        /*[in]*/ VSOUTLINESTATES dwMask, 
        /*[in]*/ VSOUTLINESTATES dwState);

private:
	DWORD m_dwRef;
	BOOL m_fZombie;
	CComPtr<IVsCodeWindow> m_srpCodeWindow;
	listTextView_type m_listViews;		// an STL linked list of pointers to CFigTextViewFilter objs
	CVsPackage* m_pCVsPkg;

    //IVsDocOutlineProvider data
    CComPtr<IVsDocOutlineProvider> m_srpIVsDocOutlineProvider;
    CComPtr<IFigOutline>           m_srpIFigOutline;
};


/////////////////////////////////////////////////////////////////////////////
// CFigTextViewFilter

class CFigTextViewFilter :
	public IOleCommandTarget,
	public IVsTextViewEvents,
	public IVsTextViewFilter
{
friend CFigCodeWindowManager;  // to access the view ptr.

public:
	CFigTextViewFilter( CVsPackage *pCVsPkg, IVsTextView *pView );
	~CFigTextViewFilter();
	STDMETHODIMP UnInit();
	STDMETHODIMP Init();
	
	BEGIN_INTERFACE
	// *** IUnknown methods **********************************************************
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// IOleCommandTarget methods:
	STDMETHODIMP QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText);
	STDMETHODIMP Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANT *pvaIn, VARIANT *pvaOut);

	// IVsTextViewEvents methods:
	STDMETHODIMP_(void) OnSetFocus( 
							/*[in] */ IVsTextView *pView );
	STDMETHODIMP_(void) OnKillFocus(
							/*[in] */ IVsTextView *pView );
	STDMETHODIMP_(void) OnSetBuffer(
							/*[in] */ IVsTextView *pView, 
							/*[in] */ IVsTextLines *pBuffer );
	STDMETHODIMP_(void) OnChangeScrollInfo(
							/*[in] */ IVsTextView *pView, 
							/*[in] */ long iBar, 
							/*[in] */ long iMinUnit, 
							/*[in] */ long iMaxUnits, 
							/*[in] */ long iVisibleUnits, 
							/*[in] */ long iFirstVisibleUnit );
	STDMETHODIMP_(void) OnChangeCaretLine(
							/*[in] */ IVsTextView *pView, 
							/*[in] */ long iNewLine, 
							/*[in] */ long iOldLine );

	// IVsTextViewFilter methods: (not used by this sample)
	// Word extent calculation
	STDMETHODIMP GetWordExtent(	long iLine, CharIndex iIndex, DWORD dwFlags, TextSpan *pSpan)
	{
		return E_NOTIMPL;
	}
	// Data-tip support.  piPos and piLength are in/out -- they indicate the selected characters
	// on the way in, and indicate the bounding context of the tip on the way out.
	STDMETHODIMP GetDataTipText( TextSpan *pSpan, BSTR *bstrText )
	{
		return E_NOTIMPL;
	}
	STDMETHODIMP GetPairExtents( long iLine, CharIndex iIndex, TextSpan *pSpan )
	{
		return E_NOTIMPL;
	}

protected:
    HRESULT GetCurrentLineText(
        /* [out] */ BSTR* pbstrLineText);

    HRESULT CFigTextViewFilter::GetTokens(
        /* [in]  */ BSTR bstrLine,
        /* [out] */ long* pnTokens);

private:
	DWORD m_dwRef;
	BOOL m_fZombie;
	BOOL m_fInit;
	CComPtr<IOleCommandTarget> m_srpNextCmdTarg;
	CVsPackage* m_pCVsPkg;
	CComPtr<IVsTextView> m_srpTextView;
	CComPtr<IVsTextLines> m_srpTextLines;
	CComPtr<CFigStatementCompletion> m_srpCompletionSet;
	CComPtr<IFigParse> m_srpParse;	// for parser
	LPFIGMARK	m_pMks;				// ''
	CFigMethodData* m_pMethodData;
	CComPtr<IVsMethodTipWindow> m_srpMethodTipWindow;
	BOOL m_fTipWinDisplayed;
	CComPtr<IFigTaskManager> m_srpTaskManager;
	DWORD m_dwTextViewEventsCookie;	// for IVsTextViewEvents advise sink
};
