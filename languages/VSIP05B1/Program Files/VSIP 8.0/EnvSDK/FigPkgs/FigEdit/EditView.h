
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// EditView.h : Declaration of CFigEditorView

#pragma once

/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CVsPackage;
class CEditor;
class CFigEditLine;

/////////////////////////////////////////////////////////////////////////////
// CFigEditorView

class CFigEditorView :
	public IOleCommandTarget,
	public IVsWindowPane,
	public IVsTextLinesEvents,
	public ISelectionContainer,
	public IVsTextBufferDataEvents,
	public IVsToolboxUser,
	public IDropTarget,
    public IVsDocOutlineProvider

{
	friend CEditor;

public:
	CFigEditorView(CVsPackage *pCVsPkg, IVsTextLines *pVsTextLines, BOOL fBufExists );
	~CFigEditorView();

	BEGIN_INTERFACE
	// *** IUnknown methods ***
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// IOleCommandTarget methods:
	STDMETHODIMP QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText);
	STDMETHODIMP Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANT *pvaIn, VARIANT *pvaOut);

	// IVsWindowPane methods:
	STDMETHODIMP SetSite(
					/*[in] */ IServiceProvider *pSP );
	STDMETHODIMP CreatePaneWindow(
					/*[in] */ HWND hwndParent,
					/*[in] */ int x,
					/*[in] */ int y,
					/*[in] */ int cx,
					/*[in] */ int cy,
					/*[out]*/ HWND *hwnd );
	STDMETHODIMP GetDefaultSize(
					/*[out]*/ SIZE *psize );
	STDMETHODIMP ClosePane( void );
	STDMETHODIMP LoadViewState(
					/*[in] */ IStream *pstream );
	STDMETHODIMP SaveViewState(
					/*[in] */ IStream *pstream );
	STDMETHODIMP TranslateAccelerator(
							  LPMSG lpmsg );

	// IVsTextLinesEvents methods:
	STDMETHODIMP_(void) OnChangeLineText(
					/*[in] */ const TextLineChange *pTextLineChange,
					/*[in] */ BOOL fLast );
	STDMETHODIMP_(void) OnChangeLineAttributes (
					/*[in] */ long iFirstLine,
					/*[in] */ long iLastLine );

	// ISelectionContainer methods:
    STDMETHODIMP CountObjects(
					/*[in] */ DWORD dwFlags, 
					/*[out]*/ ULONG * pc );
    STDMETHODIMP GetObjects(
					/*[in] */ DWORD dwFlags, 
					/*[in] */ ULONG cObjects,
					/*[out]*/ IUnknown ** apUnkObjects );
    STDMETHODIMP SelectObjects(
					/*[in] */ ULONG cSelect,
					/*[in] */ IUnknown ** apUnkSelect,
					/*[in] */ DWORD dwFlags );

	// IVsTextBufferDataEvents methods:
	STDMETHOD_(void,OnFileChanged)(
					/*[in] */ DWORD grfChange, 
					/*[in] */ DWORD dwFileAttrs);
	STDMETHOD(OnLoadCompleted)(
					/*[in] */ BOOL fReload);

	// IVsToolboxUser
	STDMETHOD(IsSupported)(
					/*[in] */ IDataObject* pDO);
	STDMETHOD(ItemPicked)(
					/*[in] */ IDataObject* pDO);

	// IDropTarget methods:
	STDMETHODIMP DragEnter(
					/*[in] */ IDataObject * pDataObject,
					/*[in] */ DWORD grfKeyState,
					/*[in] */ POINTL pt,
					/*[in,out] */ DWORD * pdwEffect);
	STDMETHODIMP DragOver(
					/*[in] */ DWORD grfKeyState,
					/*[in] */ POINTL pt,
					/*[in,out] */ DWORD * pdwEffect);
	STDMETHODIMP DragLeave( void );
	STDMETHODIMP Drop(
					/*[in] */ IDataObject * pDataObject,
					/*[in] */ DWORD grfKeyState,
					/*[in] */ POINTL pt,
					/*[in,out] */ DWORD * pdwEffect);

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
				
	// helpers
	HRESULT OnSelectChange();	// called by the Editor when the selection changes
	HRESULT	OnDragDrop( void );

	// called when advised of changes to the text buffer,
	// these methods create/destroy line objects, map entries and tell
	// the editor to create/destroy the corresponding item in the list view.
	HRESULT AddLine( long nLine, FigLineType Type, long P1, long P2, 
					 long P3, long P4, BSTR bstrComment );
	HRESULT DeleteLine( long nLine );
	HRESULT SetLine( long nLine, FigLineType Type, long P1, long P2, 
					 long P3, long P4, BSTR bstrComment );

	// called to parse a line of text from the buffer
	HRESULT ParseLine( long nLine, FigLineType *pType, long *pP1, long *pP2, 
					   long *pP3, long *pP4, BSTR *pbstrComment );

	// for cut/copy/paste/delete
	HRESULT CopyLines( void );
	HRESULT DeleteLines(BOOL fCut = FALSE);
	HRESULT PasteLines( void );
	HRESULT PasteLinesFromDataObject( IDataObject* srpDO, long nLineStart );	// does NOT AddRef pointer
	HRESULT CreateLinesFromClipboard( long startLine, BYTE *pMem );

	// helpers for managing editor caption
	HRESULT SetBaseEditorCaption(LPCOLESTR *pszBaseEditorCaption);
	HRESULT GetEditorCaption(READONLYSTATUS dwReadOnly, BSTR *pbstrEditorCaption);

private:
	// internal helpers
	ULONG	_CreateSelectionList( listLines_type &rSel );	// appends all selected lines to list rSel & returns count added
	HRESULT	_DeletePasteLines(IDataObject* pPasteObj, UINT uIdCompoundAction);
	CDataObject* _CreateCopyData( void );	// helper for drag/drop & clipboard operations

private:
	DWORD m_dwRef;
	BOOL m_fZombie;
	BOOL m_fBufExists;
	CVsPackage* m_pCVsPkg;
	CComPtr<IServiceProvider> m_srpWndPaneSiteSP;

	CComPtr<IVsTextLines> m_srpVsTextLines;
    CComPtr<IVsCompoundAction> m_srpIVsCompoundAction;
    BOOL m_fCompoundAction;
    BOOL m_fDragSource;
	CEditor* m_pCEd;
	SIZE m_WinSize;
	DWORD m_dwTextLinesEventsCookie;	  // for IVsTextLinesEvents advise sink
	DWORD m_dwTextBufferDataEventsCookie; // for IVsTextBufferDataEvents advise sink

	CComPtr<IVsUserContext> m_srpUserCtx;

	CComPtr<IFigParse> m_srpParse;	// for parser
	LPFIGMARK	m_pMks;				// ''

	listLines_type m_listLines;		// an STL linked list of pointers to CFigEditLine objs

	BSTR m_bstrBaseEditorCaption;
	UINT m_cf;						// our custom clipboard format
	static bool m_bDropFormatOK;	// set if DragEnter determines a format is droppable
	static long m_nDropFocusLine;	// line number to show focus for drop target

    //IVsDocOutlineProvider data
    CComPtr<IVsDocOutlineProvider> m_srpIVsDocOutlineProvider;
    CComPtr<IFigOutline>           m_srpIFigOutline;
};

/////////////////////////////////////////////////////////////////////////////
