
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// StatComp.h : Declaration of CFigStatementCompletion

#pragma once

#define NUM_FIG_COMPLETIONS 3
#define NUM_DRAW_COMPLETIONS 1

#define IMAGEWIDTH			16		// for image list
#define IMAGEGROWBY			4
#define IDXARROW		0
#define IDXCIRCLE		1
#define IDXRECTANGLE	2

typedef struct ComplEntry
{
    CComBSTR bstrName;
    CComBSTR bstrDescription;
    long     lImageIndex;
} ComplEntry;



/////////////////////////////////////////////////////////////////////////////
// forward declarations

/////////////////////////////////////////////////////////////////////////////
// CFigStatementCompletion

class CFigStatementCompletion :
	public IVsCompletionSet
{
public:
	CFigStatementCompletion( CVsPackage *pCVsPkg, IVsTextView *pView );
    HRESULT Reset(
        /* [in]  */ BOOL   fDraw    = FALSE,
        /* [out] */ DWORD* pdwFlags = NULL);
	~CFigStatementCompletion();
	
	BEGIN_INTERFACE
	// *** IUnknown methods **********************************************************
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();


	// *** IVsCompletionSet methods ******************************************************
	//
	STDMETHODIMP_(DWORD) GetFlags( void );

	// Get the number of available completions (assert > 1?)
	STDMETHODIMP_(long) GetCount( void );

	// Get the text of a completion, as it is to be displayed in the list.
	// The pointer returned should be maintained by the completion set
	// object, and remain valid until final release, or until updated
	// through IVsTextView::UpdateCompletionStatus
	STDMETHODIMP GetDisplayText(
					/*[in] */ long iIndex, 
					/*[out]*/ const WCHAR **ppszText, 
					/*[out]*/ long *piGlyph );

	// Get the list of images (glyphs) supported by this completion set.
	STDMETHODIMP GetImageList( 
					/*[out]*/ HANDLE *phImages );

	// Return text describing the indicated item
	STDMETHODIMP GetDescriptionText(
					/*[in] */ long iIndex, 
					/*[out]*/ BSTR *pbstrDescription );

    // Get the initial extent of the word to be completed.  *piEndCol
    // should be an index on the line *piLine
	STDMETHODIMP GetInitialExtent( 
					/*[out]*/ long *piLine, 
					/*[out]*/ long *piStartCol, 
					/*[out]*/ long *piEndCol);

	// Determine the index of the closest matching completion, given
	// what has been typed so far.  Note that this is only called if
	// CSF_CUSTOMMATCHING is set in this completion set's flags.  If
	// *pdwFlags is set to contain one of the GBM_* flags
	// The default matching in the view uses case sensitive comparison.
	STDMETHODIMP GetBestMatch( 
					/*[in] */ const WCHAR *pszSoFar, 
					/*[in] */ long iLength, 
					/*[out]*/ long *piIndex, 
					/*[out]*/ DWORD *pdwFlags );

	// Commit a completion.  S_FALSE return causes 'ding', and commit
	// character is NOT inserted.  S_OK return with *pbstrCompleteWord == pszSoFar
	// will match the default behavior if fSelected is FALSE.  If fSelected
	// is TRUE, the default behavior is to replace pszSoFar in the editor
	// with the text returned by GetDisplayText.  This is only called
	// if this completion set's flags include CSF_CUSTOMCOMMIT.
	STDMETHODIMP OnCommit(
					/*[in] */ const WCHAR *pszSoFar, 
					/*[in] */ long iIndex, 
					/*[in] */ BOOL fSelected, 
					/*[in] */ WCHAR cCommit, 
					/*[out]*/ BSTR *pbstrCompleteWord );

	// Called by the view when the completion set is no longer needed.
	// Note that if a language filter wants to force a dismiss of a completion
	// set, it calls IVsTextView::UpdateCompletionStatus with pCompSet == NULL;
	// if the view has a completion set pointer cached, it calls Dismiss()
	// on it and then releases it (and also removes the UI, etc).
	STDMETHODIMP_(void) Dismiss( void );


private:
	DWORD m_dwRef;
	BOOL m_fZombie;
	CVsPackage* m_pCVsPkg;
	CComPtr<IVsTextView> m_srpTextView;
	HIMAGELIST  m_hImageList;
    
    ComplEntry*       m_pComplEntry;
    int               m_cEntries;
    static ComplEntry ms_rgComplEntryFigures[NUM_FIG_COMPLETIONS];
    static ComplEntry ms_rgComplEntryDraw[NUM_DRAW_COMPLETIONS];
    static BOOL            ms_fCompletionEntriesInitialized;

};
