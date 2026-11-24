
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// StatComp.cpp : Implementation of CFigStatementCompletion

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes

typedef struct ComplEntryID
{
    const WCHAR*  wszName;
    ULONG         ulID;
    long          lImageIndex;
} ComplEntryID;

static ComplEntryID s_rgComplEntryIDFigures[] =
{
//    wszName,      ulID,               lImageIndex;
    { L"arrow",     IDS_ARROW_DESC,     0   },
    { L"circle",    IDS_CIRCLE_DESC,    1   },
    { L"rectangle", IDS_RECTANGLE_DESC, 2   },
};

ComplEntry CFigStatementCompletion::ms_rgComplEntryFigures[NUM_FIG_COMPLETIONS];
ComplEntry CFigStatementCompletion::ms_rgComplEntryDraw[NUM_DRAW_COMPLETIONS];
BOOL  CFigStatementCompletion::ms_fCompletionEntriesInitialized = FALSE;

CFigStatementCompletion::CFigStatementCompletion(
    /* [in] */ CVsPackage *pCVsPkg, 
    /* [in] */ IVsTextView *pView )
{
    ATLTRACE(TEXT(">> Constructing CFigStatementCompletion: 0x%X\n"), this);
    m_dwRef = 0;
    m_fZombie = FALSE;
    m_pCVsPkg = pCVsPkg;
    m_srpTextView = pView;        // Note: assignment to a smart pointer does an AddRef()

    ComplEntry*       m_pComplEntry = NULL;
    int               m_cEntries = NULL;

    // completion list box image list
    m_hImageList = ImageList_LoadBitmap( _AtlModule.GetModuleInstance(),
                                         MAKEINTRESOURCE( IDB_IMAGELIST ), 
                                         IMAGEWIDTH, IMAGEGROWBY, RGB( 0, 255, 0 ));

    // load the static data
    if (!ms_fCompletionEntriesInitialized)
    {
        for (int i = 0; i < NUM_FIG_COMPLETIONS; i++)
        {
            ms_rgComplEntryFigures[i].bstrName = s_rgComplEntryIDFigures[i].wszName;
            ms_rgComplEntryFigures[i].bstrDescription.LoadString(s_rgComplEntryIDFigures[i].ulID);
            ms_rgComplEntryFigures[i].lImageIndex = s_rgComplEntryIDFigures[i].lImageIndex;
        }
        ms_rgComplEntryDraw[0].bstrName = L"draw";
        ms_rgComplEntryDraw[0].bstrDescription.LoadString(IDS_DRAW_DESC);
        ms_rgComplEntryDraw[0].lImageIndex = 5;

        ms_fCompletionEntriesInitialized = TRUE;
    }

}

CFigStatementCompletion::~CFigStatementCompletion()
{
    ATLTRACE(TEXT(">> Destructing CFigStatementCompletion: 0x%X\n"), this);
    if( m_hImageList != NULL )
        ImageList_Destroy( m_hImageList );
}


HRESULT CFigStatementCompletion::Reset(
    /* [in]  */ BOOL   fDraw    /*= FALSE */,
    /* [out] */ DWORD* pdwFlags /*= NULL  */)
{
    if (fDraw)
    {
        m_pComplEntry = ms_rgComplEntryDraw;
        m_cEntries = NUM_DRAW_COMPLETIONS;
    }
    else
    {
        m_pComplEntry = ms_rgComplEntryFigures;
        m_cEntries = NUM_FIG_COMPLETIONS;
    }
    if (pdwFlags)
        *pdwFlags = *pdwFlags | UCS_NAMESCHANGED;

    return S_OK;
}

// *** IUnknown methods ***
STDMETHODIMP CFigStatementCompletion::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;        // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigStatementCompletion, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = (IVsColorizer *) this;
        return NOERROR;
    }
    else if( riid == IID_IVsCompletionSet )
    {
        ATLTRACE(TEXT(">> CFigStatementCompletion, received QI for IID_IVsCompletionSet.\n"));
        AddRef();
        *ppvObj = (IVsCompletionSet *) this;
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigStatementCompletion::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigStatementCompletion::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


// *** IVsCompletionSet methods ******************************************************
//

// Flags indicating specific behaviors of this completion set (CSF_* in textmgr.idl)
STDMETHODIMP_(DWORD) CFigStatementCompletion::GetFlags( void )
{
    return CSF_HAVEDESCRIPTIONS;
}

// Get the number of available completions (assert > 1?)
STDMETHODIMP_(long) CFigStatementCompletion::GetCount( void )
{
    return m_cEntries;
}

// Get the text of a completion, as it is to be displayed in the list.
// The pointer returned should be maintained by the completion set
// object, and remain valid until final release, or until updated
// through IVsTextView::UpdateCompletionStatus
STDMETHODIMP CFigStatementCompletion::GetDisplayText(
                /*[in] */ long iIndex, 
                /*[out]*/ const WCHAR **ppszText, 
                /*[out]*/ long *piGlyph )
{
    if(iIndex >= m_cEntries)
        return E_INVALIDARG;

    ExpectedPtrRet(ppszText);
    ExpectedExprRet(m_pComplEntry);
    *ppszText = m_pComplEntry[iIndex].bstrName;

    // if this pointer is NOT NULL then you must return the
    // index into our images list.
    if( NULL != piGlyph )  
        *piGlyph = m_pComplEntry[iIndex].lImageIndex;

    return S_OK;
}

// Get the list of images (glyphs) supported by this completion set.
STDMETHODIMP CFigStatementCompletion::GetImageList( 
                /*[out]*/ HANDLE *phImages )
{
    ExpectedPtrRet(phImages);
    *phImages = (HANDLE)m_hImageList;
    return S_OK;
}

// Return text describing the indicated item
STDMETHODIMP CFigStatementCompletion::GetDescriptionText(
                /*[in] */ long iIndex, 
                /*[out]*/ BSTR *pbstrDescription )
{
    // Allocate a description string.
    if(iIndex >= m_cEntries)
        return E_INVALIDARG;

    ExpectedPtrRet(pbstrDescription);
    ExpectedExprRet(m_pComplEntry);
    return m_pComplEntry[iIndex].bstrDescription.CopyTo(pbstrDescription);
}

// Get the initial extent of the word to be completed.  *piEndCol
// should be an index on the line *piLine
STDMETHODIMP CFigStatementCompletion::GetInitialExtent( 
                /*[out]*/ long *piLine, 
                /*[out]*/ long *piStartCol, 
                /*[out]*/ long *piEndCol)
{
    ASSERT(piLine && piStartCol && piEndCol);
    if (!piLine || !piStartCol || !piEndCol)
        return E_POINTER;
    *piLine = *piStartCol = *piEndCol = 0;

    HRESULT hr = S_OK;
    
    // get the current line where the cursor is
    if (!m_srpTextView)
        return E_UNEXPECTED;
    hr = m_srpTextView->GetCaretPos( piLine, piStartCol );
    if (SUCCEEDED(hr))
    {
        *piEndCol = *piStartCol;
    }

    return hr;
}

// Determine the index of the closest matching completion, given
// what has been typed so far.  Note that this is only called if
// CSF_CUSTOMMATCHING is set in this completion set's flags.  If
// *pdwFlags is set to contain one of the GBM_* flags
// The default matching in the view uses case sensitive comparison.
STDMETHODIMP CFigStatementCompletion::GetBestMatch( 
                /*[in] */ const WCHAR *pszSoFar, 
                /*[in] */ long iLength, 
                /*[out]*/ long *piIndex, 
                /*[out]*/ DWORD *pdwFlags )
{
return E_NOTIMPL;
}

// Commit a completion.  S_FALSE return causes 'ding', and commit
// character is NOT inserted.  S_OK return with *pbstrCompleteWord == pszSoFar
// will match the default behavior if fSelected is FALSE.  If fSelected
// is TRUE, the default behavior is to replace pszSoFar in the editor
// with the text returned by GetDisplayText.  This is only called
// if this completion set's flags include CSF_CUSTOMCOMMIT.
STDMETHODIMP CFigStatementCompletion::OnCommit(
                /*[in] */ const WCHAR *pszSoFar, 
                /*[in] */ long iIndex, 
                /*[in] */ BOOL fSelected, 
                /*[in] */ WCHAR cCommit, 
                /*[out]*/ BSTR *pbstrCompleteWord )
{
return E_NOTIMPL;
}

// Called by the view when the completion set is no longer needed.
// Note that if a language filter wants to force a dismiss of a completion
// set, it calls IVsTextView::UpdateCompletionStatus with pCompSet == NULL;
// if the view has a completion set pointer cached, it calls Dismiss()
// on it and then releases it (and also removes the UI, etc).
STDMETHODIMP_(void) CFigStatementCompletion::Dismiss( void )
{
}


// end of file StatComp.cpp
