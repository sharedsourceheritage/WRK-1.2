
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// FindRepl.cpp : This file contains methods relating to find and replace

#include "stdafx.h"

#include "EdCommon.h"

#include "guids.h"
#include "BscEdtUI\resource.h"

/////////////////////////////////////////////////////////////////////////////
// CBscEditorDocument IVsFindTarget Implementation
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// Function:    GetCapabilites (IVsFindTarget interface)
//                This function indicates to the caller which Find/Replace
//                options we are supporting. We set the pfImage flag to
//                FALSE because we are not supporting the IVsTextImage interface.
//
// Parameters:
//    pfImage        An output flag to set to TRUE if we are supporting IVsTextImage
//    pgrfOptions    An output filed indicating the supported options
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::GetCapabilities (BOOL * pfImage, DWORD * pgrfOptions)
{
    if (pgrfOptions)
    {
        // Our capabilites are those supported by the Text Object Model
        //  - match case
        //  - match whole words
        //  - find/replace
        //  - forwards or backwards
        DWORD   dwOpts =    FR_CommonOptions    |    // Match case, whole words
                            FR_Backwards        |    // Backwards from insertion point
                            FR_Selection        |    // Search selection only
                            FR_Plain            |    // Plain (as opposed to reg expression)
//                            FR_RegExpr            |    // Regular expressions
                            FR_ActionMask;            // Find/replace capabilities

        // If the file is "Read Only" then disable the replace options
        if (FIsReadOnly())
            dwOpts &= ~(FR_ReplaceAll | FR_Replace);

        // If the selection is empty then disable the "Search Selection Only" option
        if (FEmptySelection())
            dwOpts &= ~FR_Selection;

        *pgrfOptions = dwOpts;
    }
    if (pfImage) *pfImage = false;
    return S_OK;
}



/////////////////////////////////////////////////////////////////////////////
//
// Function:    GetSearchImage (IVsFindTarget interface)
//                We implement Find and Replace instead of this function.
//
// Parameters:
//    grfOptions    Not used.
//    ppSpans        Not used.
//    ppTextImage    Not used.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::GetSearchImage
(
    DWORD               grfOptions, 
    IVsTextSpanSet **   ppSpans, 
    IVsTextImage **     ppTextImage
)
{
    // We need either to implement GetSearchImage or Find and Replace.
    // In our case we are implementing Find and Replace
    return E_NOTIMPL;
}


/////////////////////////////////////////////////////////////////////////////
//
// Function:    Find (IVsFindTarget interface)
//                In the find function we establish the search options,
//                determine the search limits and then use the RTF
//                control interface function to search for the string.
//                
// Parameters:
//    pszSearch            Search string.
//    grfOptions            Search options (match case, whole words etc)
//    fResetStartPoint    If this is TRUE then this is a new search.
//    pHelper                Find helper function (not used).
//    pResult                We set this to TRUE if we find the search string.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::Find
(
    LPCOLESTR pszSearch,
    VSFINDOPTIONS grfOptions,
    BOOL fResetStartPoint,
    IVsFindHelper * pHelper, 
    VSFINDRESULT * pResult
) 
{
    _ASSERTE(pResult != NULL);
    if (!pResult)
        return E_POINTER;

    HRESULT                    hr;
    CComBSTR                bstrSearch = pszSearch;        // Search BSTR

    // Set up text search options
    long grfSearchFlags =    ((grfOptions & FR_MatchCase) ? tomMatchCase : 0) |
                            ((grfOptions & FR_WholeWord) ? tomMatchWord : 0);

    // Get the current selection object so we can determine the search
    // start character position.
    CComPtr<ITextSelection>    srpTextSelection;
    if (FAILED(hr = m_srpTextDocObj->GetSelection(&srpTextSelection)))
        return hr;

    // At this point we duplicate the selection range. We do this
    // because we may need to modify the range for the start of
    // our search to allow for wrap around the end of the document
    // but we do not want to modify the selection range until we
    // find a match.
    CComPtr<ITextRange>    srpSearchRange;
    if (FAILED(hr = srpTextSelection->GetDuplicate(&srpSearchRange)))
        return hr;

    // Now we must establish the limits for our search depending
    // on such criteria as whether the fRestStartPoint flag is set
    // or clear, whether we are searching within a selection only
    // or the whole document, the search direction etc.
    if (FAILED(hr = SetSearchLimits(srpSearchRange, grfOptions, fResetStartPoint)))
        return hr;

    // Search for the given string
    long cLength;
    // Number of characters to search
    long cCount;

    // Note that if we are searching backwards and our end point is
    // zero we must adjust it to -1.
    if ((grfOptions & FR_Backwards) && m_cSearchEnd == 0)
        cCount = m_cSearchEnd - m_cSearchStart - 1;
    else
        cCount = m_cSearchEnd - m_cSearchStart;
    if
    (
        FAILED(hr =    srpSearchRange->FindText
                    (
                        bstrSearch,
                        cCount,
                        grfSearchFlags,
                        &cLength
                    ))
    )
        return hr;

    // If the length is zero it indicates the string was not located
    if (cLength == 0)
    {
        *pResult = m_SearchFailResult;
    }
    else
    {
        // We have found a match. This means that the start and end
        // positions of srpSearchRange correspond to the matched text
        // so we make this range the active selection.

        if (FAILED(hr = srpSearchRange->Select()))
            return hr;
        *pResult = VSFR_Found;
    }

    m_LastResult = *pResult;
    return S_OK;
}



/////////////////////////////////////////////////////////////////////////////
//
// Function:    Replace (IVsFindTarget interface)
//                In this function we verify the the current selection
//                matches the given search string and if so we call the
//                appropriate RTF control function to perform the
//                replacement.
//
// Parameters:
//    pszSearch            Search string.
//    pszReplace            Replace string.
//    grfOptions            Search options (not used).
//    fResetStartPoint    Reset search flag (not used).
//    pHelper                Find helper function (not used).
//    pReplace            We set this to TRUE if we have performed the replace.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::Replace
(
    LPCOLESTR pszSearch,
    LPCOLESTR pszReplace,
    VSFINDOPTIONS grfOptions,
    BOOL fResetStartPoint,
    IVsFindHelper * pHelper,
    BOOL * pbReplaced
)
{    
    _ASSERTE(pbReplaced != NULL);
    if (!pbReplaced)
        return E_POINTER;
    *pbReplaced = false;// initialize it

    // "Find" is called prior to "Replace" so all we have to do here is:
    //    - Check that the current selection string is equal to the
    //      search string.
    //    - If the above test is satisfied then replace the search text
    //      with the replacement text.
    // Note also that we do not need to cater for "Replace All", the
    // shell will merely call "Find" and then "Replace" iteratively
    // until the search fails.

    HRESULT            hr;

    // First we make a check for an empty selection. If it is empty then we
    // merely set the flag to FALSE and return.
    if (FEmptySelection())
    {
        *pbReplaced = false;
        return S_OK;
    }

    // Get the current selection object so we can obtain the
    // currently selected text.
    CComPtr<ITextSelection>    srpTextSelection;
    if (FAILED(hr = m_srpTextDocObj->GetSelection(&srpTextSelection)))
        return hr;
    CComBSTR        bstrSelection;                // Current selection
    if (FAILED(hr = srpTextSelection->GetText(&bstrSelection)))
        return hr;

    // Check whether the currently selected text matches the search string.
    // Note that we need to take into account whether we are doing a case
    // sensitive or case insensitive match.
    if (StringsAreSame(bstrSelection, pszSearch, (grfOptions & FR_MatchCase) != 0))
    {
        // Store the starting position of this selection
        long lSelectionStart;
        if ( FAILED(hr=srpTextSelection->GetStart(&lSelectionStart)) )
            return hr;

        // Call the function to replace the currently selected text
        // with the given replacement string
        CComBSTR    bstrReplace = pszReplace;    // Replacement text

        // Now get the difference between the length of the old and new text
        long lDeltaLen = bstrReplace.Length() - bstrSelection.Length();

        // Do the actual replace
        if (FAILED(hr = srpTextSelection->SetText(bstrReplace)))
            return hr;
        *pbReplaced = true;
        if ((grfOptions & FR_Backwards) == 0)
        {
            // In case of forward search we have to place the insertion point at the
            // end of the new text, so it will be skipped during the next call to Find.
            long lEndPosition;
            if ( SUCCEEDED(srpTextSelection->GetEnd(&lEndPosition)) )
            {
                srpTextSelection->SetStart( lEndPosition );
                // Check if this replacement moves the end position of the wrap region.
                if ( lSelectionStart < m_cWrapEnd )
                {
                    m_cPermittedEnd += lDeltaLen;
                    m_cSearchEnd += lDeltaLen;
                }
                else
                    srpTextSelection->GetStoryLength(&m_cSearchEnd);
            }
        }
        else
        {
            // If the search is backward, then set the end postion at the
            // beginning of the new text.
            srpTextSelection->SetEnd( lSelectionStart );
            // Check if this replacement moves the end position of the wrap region.
            if ( lSelectionStart < m_cWrapEnd )
                m_cWrapStart += lDeltaLen;
            srpTextSelection->GetStoryLength(&m_cWrapStart);
        }
    }
    else
    {
        *pbReplaced = false;    // Selection does not match search
    }

    return S_OK;
}



/////////////////////////////////////////////////////////////////////////////
//
// Function:    GetProperty (IVsFindTarget interface)
//                The function returns the required property in the given
//                variant. Note that not all cases are implemented.
//
// Parameters:
//    propid        ID of the property required.
//    pvar        Variant in which the required property is returned.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::GetProperty (VSFTPROPID propid, VARIANT *pvar)
{
    if (!pvar) return E_POINTER;
    HRESULT hr = E_NOTIMPL;
    switch (propid)
    {
    // Return a copy of the file name string
    case VSFTPROPID_DocName: 
        pvar->vt = VT_BSTR;
        pvar->bstrVal = ::SysAllocString(m_bsFileName.m_str);
        hr = (m_bsFileName ? S_OK : E_FAIL);
        break;

    // We assume that the file is always on disk
    case VSFTPROPID_IsDiskFile: 
        pvar->vt = VT_BOOL;
        pvar->boolVal = true;
        hr = S_OK;
        break;

    // Block name is not applicable to RTF files
    case VSFTPROPID_BlockName: 
        hr = E_NOTIMPL;
        break;

    // Here we get the selection text (if any)
    case VSFTPROPID_InitialPatternAggressive:
    case VSFTPROPID_InitialPattern: 
        pvar->vt = VT_BSTR;
        hr = GetInitialPattern(&pvar->bstrVal);
        break;

    // Get the window frame from the site
    case VSFTPROPID_WindowFrame: 
        pvar->vt = VT_UNKNOWN;
        hr = m_srpSiteSP->QueryService(SID_SVsWindowFrame, IID_IVsWindowFrame, (LPVOID*)&pvar->punkVal);
        break;
    }
    return hr;
}


/////////////////////////////////////////////////////////////////////////////
//
// Function:    GetMatchRect (IVsFindTarget interface)
//                Not implemented
//
// Parameters:
//    prc            Not used.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::GetMatchRect (PRECT prc)
{
    return E_NOTIMPL;
}



/////////////////////////////////////////////////////////////////////////////
//
// Function:    NavigateTo (IVsFindTarget interface)
//                When this function is called we merely activate the window.
//
// Parameters:
//    pts            Not used.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::NavigateTo (const TextSpan * pts)
{
    // If this method gets called we merely activate the window
    if (m_srpSiteSP)
    {
        CComPtr<IVsWindowFrame> srpFrame;

        // Query from the IVsWindowFrame interface from the site pointer
        HRESULT hr = m_srpSiteSP->QueryService(SID_SVsWindowFrame, IID_IVsWindowFrame, (LPVOID*)&srpFrame);
        if (SUCCEEDED(hr) && srpFrame)
        {
            hr = srpFrame->Show();
        }
        return hr;
    }

    return E_NOTIMPL;
}



/////////////////////////////////////////////////////////////////////////////
//
// Function:    GetCurrentSpan (IVsFindTarget interface)
//                Not implemented.
//
// Parameters:
//    pts            Not used.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::GetCurrentSpan (TextSpan * pts)
{
    return E_NOTIMPL;
}



/////////////////////////////////////////////////////////////////////////////
//
// Function:    SetFindState (IVsFindTarget interface)
//                Boiler plate function - the same for everry implementation
//                of IVSFindTarget - it is used to store an object pointer.
//
// Parameters:
//    punk        Object.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::SetFindState (IUnknown * punk)
{
    if (m_pUnkFindState)
        m_pUnkFindState->Release();
    if (punk)
    {
        punk->AddRef();
        m_pUnkFindState = punk;
    }
    return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
//
// Function:    GetFindState (IVsFindTarget interface)
//                Boiler plate function - the same for everry implementation
//                of IVSFindTarget - it is used to retrieve a previously
//                stored object pointer.
//
// Parameters:
//    ppunk        Return location for object pointer.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::GetFindState (IUnknown **ppunk)
{
    _ASSERTE(ppunk != NULL);
    if (!ppunk)
        return E_POINTER;
    *ppunk = m_pUnkFindState;
    if (m_pUnkFindState)
        m_pUnkFindState->AddRef();
    return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
//
// This implementation does not require any of the notifications
//
STDMETHODIMP CBscEditorDocument::NotifyFindTarget(VSFTNOTIFY)
{
  return NOERROR;
}

/////////////////////////////////////////////////////////////////////////////
//
// Only IVsTextImage providers implement this method.
//
STDMETHODIMP CBscEditorDocument::MarkSpan(const TextSpan *)
{
  return E_NOTIMPL;
}

/////////////////////////////////////////////////////////////////////////////////
//    Helper Functions
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
// Function:    GetInitialPattern (IVsFindTarget helper)
//                This function determines the selection string (if any) to be used
//                in the find dialogue box. Note that if the selection is empty or
//                is multiline then we do not set up a selection string.
//
// Parameters:
//    pbstrPattern        Location to receive the selection string
//
// Returns an HRESULT
////////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::GetInitialPattern(BSTR *pbstrPattern)
{
    HRESULT hr;

    // First check if the selection is empty.
    if (FEmptySelection())
    {
        *pbstrPattern = NULL;
        return S_OK;
    }

    // We now check if the selection is multiline. 
    // We do this by :-
    //    - Getting and then duplicating the current text range.
    //    - Advancing the start of the duplicate by one line
    //    - Checking if the duplicate range is still within
    //      the original range.
    // If the check is true then the selection is multiline.
    CComPtr<ITextSelection>    srpTextSelection;
    CComPtr<ITextRange>    srpTextDuplicate;
    long cEndOrig;
    long cEndDup;

    // Get the text selection
    if (FAILED(hr = m_srpTextDocObj->GetSelection(&srpTextSelection)))
        return hr;

    // Duplicate the text selection and advance the start by one line
    if (FAILED(hr = srpTextSelection->GetDuplicate(&srpTextDuplicate)))
        return hr;
    if (FAILED(hr = srpTextDuplicate->MoveStart(tomLine, 1, NULL)))
        return hr;

    // Test if the duplicate is still within the original selection.
    // We do this by getting the ends of each range. If they are
    // still the same then the selection is multiline.
    if (FAILED(hr = srpTextSelection->GetEnd(&cEndOrig)))
        return hr;
    if (FAILED(hr = srpTextDuplicate->GetEnd(&cEndDup)))
        return hr;

    if (cEndOrig == cEndDup)
    {
        *pbstrPattern = NULL;
        return S_OK;
    }

    // The selection is all within a single line so retrieve the selection text.
    hr = srpTextSelection->GetText(pbstrPattern);
    return hr;
}



    
/////////////////////////////////////////////////////////////////////////////////
//
// Function:    SetSearchLimits (IVsFindTarget helper)
//                This function determines the search limits for a find and also 
//                adjusts the given range limits to cater for wrap in a search. 
//                When the given reset flag is TRUE the function determines and 
//                stores variables to control the search. The function also checks 
//                for anomalies when the given reset flag is FALSE. If anomalies 
//                are detected the function treats this as a new document search.
//
// Parameters:
//    pSearchRange        Range object - contains the current selection
//                        or insertion point
//    grfOptions            Search options (Backwards/forwards, selection
//                        are of interest)
//    fResetStartPoint    Reset flag - If TRUE indicates a new search
//
// Returns an HRESULT
/////////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::SetSearchLimits
(
    ITextRange *pSearchRange,
    VSFINDOPTIONS grfOptions,
    BOOL fResetStartPoint
)
{
    HRESULT hr;
    // Obtain the start of the given range. This is either the start of the
    // current selection or the current insertion point.
    long cFirst;
    if (FAILED(hr = pSearchRange->GetStart(&cFirst)))
        return hr;

    // Determine search direction
    BOOL fBackwards = (grfOptions & FR_Backwards) ? true : false;

    // Determine if selection or whole document search
    BOOL fSelectionSearch = (grfOptions & FR_Selection) ? true : false;

    // We have a number of scenarios to cater for when the given reset flag
    // is FALSE but conditions dictate that we treat this as a new search.
    // This typically occurs when the user repositions the cursor after a
    // search has been commenced.
    BOOL fForcedReset;

    // Check for forced reset conditions only if the given reset flag is FALSE.
    // Also, we need only check for wrapping if the reset flag is FALSE.
    if (!fResetStartPoint)
    {
        fForcedReset = ResetRequired(cFirst, fBackwards);

        // If we don't need a reset we must check for wrap here
        if (!fForcedReset)
        {
            if (VSFR_EndOfDoc == m_LastResult)
            {
                // We must set the given range limits to
                // the new area of search.
                m_cPermittedStart = m_cWrapStart;
                m_cPermittedEnd = m_cWrapEnd;
                m_cSearchStart = m_cPermittedStart;
                m_cSearchEnd = m_cPermittedEnd;

                if (fBackwards)
                    // Adjust the range limits (note 1st parameter is m_cSearchEnd)
                    hr = pSearchRange->SetRange(m_cSearchEnd, m_cSearchStart);
                else
                    // Adjust the range limits
                    hr = pSearchRange->SetRange(m_cSearchStart, m_cSearchEnd);

                // At this point the failure is "...EndOfDoc" so we
                // update the failure return for future search failures.
                // Note that the caller (i.e. the shell) does not regard
                // "...EndOfDoc" as a failure condition but calls "Find"
                // again (with fResetStartPoint clear i.e. FALSE)
                m_SearchFailResult = VSFR_EndOfSearch;
                return hr;
            }
            else if (VSFR_Found == m_LastResult)
            {
                // All we need to do here is adjust the search start
                // to the current position.
                m_cSearchStart = cFirst;
                return S_OK;
            }
            else
            {
                // We should never reach here
                return E_FAIL;
            }
        }
    }

    // If we have reached this point we must do a reset because either
    // fForcedReset or fResetStartPoint is TRUE.
    m_fBackwards = fBackwards;

    // If the selection flag is FALSE or the selection flag is TRUE but
    // the selection is empty then we set up a document search.
    long cLast;                // End of document or end of selection
    if (!fSelectionSearch || FEmptySelection())
    {
        // Get the last character position in the document
        if (FAILED(hr = pSearchRange->GetStoryLength(&cLast)))
            return hr;
        m_cPermittedStart = cFirst;
        m_cPermittedEnd = fBackwards ? 0 : cLast;
        if ( fResetStartPoint )
        {
            m_cWrapStart = fBackwards ? cLast : 0;
            m_cWrapEnd = cFirst;
        }

        // Set the search failure result for "Find" to "...EndOfDoc"
        // to enable wrapping.
        m_SearchFailResult = VSFR_EndOfDoc;
    }
    else
    {
        // Selection search

        // Get the last character position in the search range
        if (FAILED(hr = pSearchRange->GetEnd(&cLast)))
            return hr;
        m_cPermittedStart = fBackwards ? cLast : cFirst;
        m_cPermittedEnd = fBackwards ? cFirst : cLast;

        // Set the search failure result for "Find" to "...EndOfSearch"
        // to disable wrapping.
        m_SearchFailResult = VSFR_EndOfSearch;
    }

    // Set the search limits for the next find
    m_cSearchStart = m_cPermittedStart;
    m_cSearchEnd = m_cPermittedEnd;
    return S_OK;
}



////////////////////////////////////////////////////////////////////////////////
//
// Function:    ResetRequired (IVsFindTarget helper)
//                This function checks whether a new search is required.
//
// Parameters:
//    cFirst                Current insertion point or selection start.
//    fBackwards            TRUE if search is backwards
//
// Returns an HRESULT
////////////////////////////////////////////////////////////////////////////////
BOOL CBscEditorDocument::ResetRequired(long cFirst, BOOL fBackwards)
{
    // Check for change of search direction
    if (fBackwards != m_fBackwards)
        return true;

    // Check if current point is within the expected limits;
    long cLimitStart = fBackwards ? m_cPermittedEnd : m_cPermittedStart;
    long cLimitEnd = fBackwards ? m_cPermittedStart : m_cPermittedEnd;
    if (cFirst < cLimitStart || cFirst > cLimitEnd)
        return true;

    // If we reach here a reset is not required
    return false;
}
        
////////////////////////////////////////////////////////////////////////////////
//
// Function:    StringsAreSame (IVsFindTarget helper)
//                This function compares two strings either case sensitively
//              or case non-sensitively depending on a given flag.
//
// Parameters:
//    pszString1            First string to compare.
//    pszString2            Second string to compare.
//    fCaseSensitive        TRUE if case sensitive match is required
//
// Returns an HRESULT
////////////////////////////////////////////////////////////////////////////////
BOOL CBscEditorDocument::StringsAreSame
(
    LPCOLESTR pszString1,
    LPCOLESTR pszString2,
    BOOL fCaseSensitive
)
{
    if (fCaseSensitive)
    {
        if (wcscmp(pszString1, pszString2) == 0)
            return true;                // Case sensitive match
    }
    else
    {
        if (_wcsicmp(pszString1, pszString2) == 0)
            return true;                // Case insensitive match
    }
    return false;
}
        
