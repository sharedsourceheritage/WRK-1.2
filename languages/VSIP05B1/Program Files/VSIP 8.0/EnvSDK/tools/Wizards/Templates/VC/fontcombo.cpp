
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//////////////////////////////////////////////////////////////////////////////
// FontCombo.cpp : Font command combo helper functions
//
//////////////////////////////////////////////////////////////////////////////
// Note on font combo boxes.
//
// Our font combo boxes are now defined in appid\cmddef\pkgui\StdCmdDef.ctc
// with the corresponding definitions in common\inc\stdidcmd.h. We have defined
// two combo boxes; one for the font name and one for the font size.
// Each combo box consists of effectively two commands. There is one 
// command to display or change the value and another command to fill
// the drop-down list with the selectable values. In our case the two pairs
// of commands are:-
//    - cmdidFontName and cmdidFontNameGetList (font names)
//    - cmdidFontSize and cmdidFontSizeGetList (font sizes)
// Note that these commands are fully defined within the COMBOS_BEGIN 
// ...... COMBOS_END section (the command group being defined in
// the NEWGROUPS_BEGIN ...... NEWGROUPS_END section). These commands
// have no references in the CMDPLACEMENT section their positions on
// the toolbar being defined by their PRIORITY field.
// Note that the shell will only query for cmdidFontName and cmdidFontSize
// but exec will be called on all four commands. cmdidFontNameGetList and
// cmdidFontSizeGetList have only a single form and are invoked to obtain
// the strings required to fill the drop-down lists. cmdidFontName and
// cmdidFontSize have two forms. They are called with a null input parameter
// and a non-null output parameter to retrieve the font name and font size
// respectively, and with a non-null input parameter to set the font name
// and font size respectively.
///////////////////////////////////////////////////////////////////////////////
//
#include "stdafx.h"

#include "EdCommon.h"

#include "..\%ProjectName%UI\guids.h"
#include "..\%ProjectName%UI\resource.h"

// Selectable font sizes to be displaced in drop-down list
const int       SIZE_ARRAY_COUNT  = 16;
static TCHAR    *s_rgTrigenFontSizeStrings[] =
                { 
                    _T("8"), 
                    _T("9"), 
                    _T("10"), 
                    _T("11"), 
                    _T("12"), 
                    _T("14"), 
                    _T("16"), 
                    _T("18"),
                    _T("20"),
                    _T("22"),
                    _T("24"),
                    _T("26"),
                    _T("28"),
                    _T("36"),
                    _T("48"),
                    _T("72")
                };

///////////////////////////////////////////////////////////////////////////////
//
// Function:    CompareBSTRPtrs 
//              This function is used by qsort to compare two wide strings
//
// Parameters:
//  arg1        Pointer to the first string.
//  arg2        Pointer to the second string.
//
// Returns:     The result of the comparison
///////////////////////////////////////////////////////////////////////////////
inline int __cdecl CompareBSTRPtrs(const void *arg1, const void *arg2 )
{
    // Compare all of both strings:
    FontData*   fd1 = (FontData*)arg1;
    FontData*   fd2 = (FontData*)arg2;
    
   return wcscmp(fd1->szFontName, fd2->szFontName );
}

///////////////////////////////////////////////////////////////////////////////
//
// Function:    EnumFontNamesCallBack (EnumFontFamiliesEx callback function)
//              This function is called for each font family returned by
//              EnumFontFamiliesEx. We store the font name and character set
//              for each unique TrueType font returned. Note that we ignore
//              other than TrueType fonts. Note also that this function
//              will be called multiple times for the same font where there
//              are multiple character sets within the font file. In these
//              cases we only store the font and the character set for the
//              first occurence.
//
// Parameters:
//  pEnumLogFont    logical-font data
//  pTextMetric     physical-font data (not used)
//  fontType        type of font
//  lParam          application-defined data - pointer to document(object)
//
// Returns:     A boolean value
///////////////////////////////////////////////////////////////////////////////
static int CALLBACK EnumFontNamesCallBack(const ENUMLOGFONTEX* pEnumLogFont,
    const NEWTEXTMETRICEX* pTextMetric, int fontType, LPARAM lParam)
{
    USES_CONVERSION;

    _ASSERTE(lParam != NULL);

    // Get the pointer to our document object.
    CBscEditorDocument* pDoc = (CBscEditorDocument*)lParam;

    // First we check if the font is a TrueType. If not we ignore it
    // because of font scaling issues.

    if (!(TRUETYPE_FONTTYPE & fontType))
    {
        // Reduce the overall count of fonts.
        pDoc->DecrFontNameCount();
        return TRUE;
    }

    _ASSERTE(NULL != pEnumLogFont);
    _ASSERTE(NULL != pTextMetric);
    _ASSERTE(NULL != pEnumLogFont->elfLogFont.lfFaceName);

    // Add this font name to the global BSTR* array if it's different to the previous
    pDoc->SetFontNameEntry(T2BSTR( pEnumLogFont->elfLogFont.lfFaceName ));
    pDoc->SetFontCharSetEntry(pEnumLogFont->elfLogFont.lfCharSet);

    // If this font name is the same as the last then reduce the count 
    // and do not increment the index.
    if (pDoc->GetFontNameIndex())
    {
        if
        (
            wcscmp
            (
                pDoc->GetFontNameEntry(pDoc->GetFontNameIndex()), 
                pDoc->GetFontNameEntry(pDoc->GetFontNameIndex() - 1)
            )
            == 0
        )
        {
            pDoc->DecrFontNameCount();
            return TRUE;
        }
    }

    // We have at this point added a new entry to our array so we 
    // increment the index value.
    pDoc->IncrFontNameIndex();

    return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function:    CountFontNamesCallBack (EnumFontFamiliesEx callback function)
//              This function is called for each font family returned by
//              EnumFontFamiliesEx. We merely increment a count each time.
//
// Parameters:
//  pEnumLogFont    logical-font data (not used)
//  pTextMetric     physical-font data (not used)
//  fontType        type of font (not used)
//  lParam          application-defined data - pointer to document(object)
//
// Returns:     A boolean value
///////////////////////////////////////////////////////////////////////////////
static int CALLBACK CountFontNamesCallBack(const ENUMLOGFONTEX* pEnumLogFont,
    const NEWTEXTMETRICEX* pTextMetric, int fontType, LPARAM lParam)
{
    _ASSERTE(lParam != NULL);

    // Get the pointer to our document object.
    CBscEditorDocument* pDoc = (CBscEditorDocument*)lParam;

    // Increment our font count. Note that there may be duplicate names and
    // non-TrueType fonts but we handle these in the EnumFontNamesCallback
    // decrementing the overall count as appropriate.
    pDoc->IncrFontNameCount();

    return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function:    CreateFontNameArray 
//              This function is called once to store an array of font names
//              and character sets for each TrueType font available on the
//              system. Data from this array is used to fill the drop down
//              list of fonts for the font combo box. We also use this data
//              to determine the corresponding charset value for a font
//              selected by the user. Note we pass the font and charset to
//              the RTF control to select the font. The charset value is
//              critcal for "Symbol" fonts such as Wingdings, Symbol etc.
//
// Parameters:
//  None
//
// Returns:     HRESULT
///////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::CreateFontNameArray()
{
    if(m_pFonts)
        return S_OK;            // Guard against multiple invocations.

    HRESULT hr = S_OK;
    HDC hDC; // Desktop device context handle.

    // get the desktop window's DC
    hDC = ::GetDC(GetDesktopWindow());
    _ASSERTE(NULL != hDC);
    if (!hDC)
        return HrLastError();

    // get the number of fonts on the system via enumeration
    EnumFontFamiliesEx(hDC, NULL, (FONTENUMPROC)CountFontNamesCallBack, (LPARAM)this, 0);

    // create an array of BSTR* of the required size
    m_pFonts = new FontData[m_cFontNames];
    if (!m_pFonts)
    {
        hr = E_OUTOFMEMORY;
        goto Error;
    }

    // enumerate the fonts, which fills the supplied array of BSTR*
    EnumFontFamiliesEx(hDC, NULL, (FONTENUMPROC)EnumFontNamesCallBack, (LPARAM)this, 0);

    // qsort the array of fonts
    qsort(m_pFonts, m_cFontNames, sizeof(FontData), CompareBSTRPtrs);

Error:
    ::ReleaseDC(GetDesktopWindow(), hDC);

    return hr;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function:    FillFontNameArray 
//              This function is called in response to an cmdidFontNameGetList
//              command to supply an array of BSTRs to fill the drop-down list
//              with the names of the available fonts.
//
// Parameters:
//  pvarOut     Output variant in which to place the array of BSTRs containing
//              the available fonts.
//
// Returns:     HRESULT
///////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::FillFontNameArray(VARIANT *pvarOut)
{
    SAFEARRAYBOUND  saBound[1];         // Bounds of array of font names
    LONG            rgIndices[1];       // Index parameter for SafeArrayPutElement      

    HRESULT hr = S_OK;
    // If the array of font names has not yet been created then we call the
    // appropriate function here.
    if (!m_pFonts)
    {
        hr = CreateFontNameArray();
        if (FAILED(hr))
            return hr;
    }

    SAFEARRAY *psaFonts = NULL;         // Array in which to store font names

    _ASSERTE(NULL != pvarOut);

    // clear out any existing stuff
    VariantClear(pvarOut);

    // tag our variant as string array
    V_VT(pvarOut) = VT_ARRAY | VT_BSTR;

    // create the safe array of required size
    saBound[0].cElements = m_cFontNames;
    saBound[0].lLbound = 0;
    psaFonts = SafeArrayCreate(VT_BSTR, 1, saBound);
    _ASSERTE(NULL != psaFonts);
    if (psaFonts == NULL)
        return E_OUTOFMEMORY;

    // copy the font names to the safe array
    for (int iFont = 0; iFont < m_cFontNames; iFont++)
    {
        rgIndices[0] = iFont;
        hr = SafeArrayPutElement(psaFonts, &rgIndices[0], m_pFonts[iFont].szFontName);
        if (FAILED(hr))
            break;
    }

    // put array into  variant and return
    if (SUCCEEDED(hr))
    {
        V_ARRAY(pvarOut) = psaFonts;
    }
    else
    {
        VariantClear(pvarOut);
        (void)SafeArrayDestroy(psaFonts);
    }
    return hr;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function:    FillFontSizeArray 
//              This function is called in response to an cmdidFontSizeGetList
//              command to supply an array of BSTRs to fill the drop-down list
//              with selectable font sizes. Note this list contains commonly
//              used font sizes but the user may enter sizes other than these.
//
// Parameters:
//  pvarOut     Output variant in which to place the array of BSTRs containing
//              font sizes.
//
// Returns:     HRESULT
///////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::FillFontSizeArray(VARIANT *pvarOut)
{
    CComBSTR        bstrFontSize;       // Temporary storage for font size string
    SAFEARRAY       *psaFontSizes;      // Array of font size stings
    SAFEARRAYBOUND  saBound[1];         // Bounds of font size string array
    LONG            rgIndices[1];       // Index parameter for SafeArrayPutElement

    _ASSERTE(NULL != pvarOut);

    // clear out any existing stuff
    VariantClear(pvarOut);

    // tag our variant as string array
    V_VT(pvarOut) = VT_ARRAY | VT_BSTR;

    // create the safe array of required size
    saBound[0].cElements = SIZE_ARRAY_COUNT;
    saBound[0].lLbound = 0;
    psaFontSizes = SafeArrayCreate(VT_BSTR, 1, saBound);
    if (psaFontSizes == NULL)
    {
        VariantClear(pvarOut);
        return E_OUTOFMEMORY;
    }

    HRESULT hr = S_OK;
    // add each font size from our hard-coded list to the safe array
    for (int i = 0; i < SIZE_ARRAY_COUNT; i++)
    {
        // add this font name to the global safe array
        rgIndices[0] = i;
        bstrFontSize = s_rgTrigenFontSizeStrings[i];
        hr = SafeArrayPutElement(psaFontSizes, &rgIndices[0], bstrFontSize);
        _ASSERTE(SUCCEEDED(hr));
        if (FAILED(hr))
            break;
        bstrFontSize.Empty();
    }

    if (FAILED(hr))
    {
        (void)SafeArrayDestroy(psaFontSizes);
    }
    else
    {
        // put array into variant and return
        V_ARRAY(pvarOut) = psaFontSizes;
    }
    return hr;
}



///////////////////////////////////////////////////////////////////////////////
//
// Function:    SetFontName 
//              This function is called in response to an cmdidFontName
//              command to set the font to the given name in pvarNew.
//              We search our array of font names and charsets and
//              extract the charset corresponding to the font name. We
//              then send the font name and charset to the RTF control
//              to implement the selection. Note that if we do not find
//              the font name in our array we set the charset to
//              DEFAULT_CHARSET. Note that if the font name or the
//              charset is not recognized by the system a default font
//              is chosen (typically Arial).
//              NOTE that ideally we would use the ITextFont interface
//              in the Text Object Model however there is no method of
//              setting the character set value via that interface. This
//              limitation prevents us using that interface to select
//              "symbol" fonts such as Wingdings.
//
// Parameters:
//  pvarNew     Variant containing the name of the font the user has selected.
//
// Returns:     An HRESULT
///////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::SetFontName(VARIANT *pvarNew)
{
    _ASSERTE(pvarNew);
    if (pvarNew == NULL)
        return E_INVALIDARG;

    // Character formatting data structure (Note explicit "A" version)
    CHARFORMATW cf; 
    cf.cbSize = sizeof(CHARFORMATW);

    _ASSERTE(m_hwndRTF);
    // Copy the font name to the character formatting data structure.
    // Note that the user may manually select any font rather than
    // selecting a font from the drop-down list. 
    if (::SysStringLen(pvarNew->bstrVal) >= LF_FACESIZE)
        return E_UNEXPECTED;
    wcscpy(cf.szFaceName, pvarNew->bstrVal);
    cf.bCharSet = DEFAULT_CHARSET;          // Initialise charset value.

    // Set flags to indicate we are changing font face name and charset.
    cf.dwMask = CFM_FACE | CFM_CHARSET;

    // Search for a font name in our list to match the input string. If a 
    // match is found then extract the corresponding character set.
    for (DWORD i = 0; i < m_dwFontNameIndex; i++)
    {
        if (wcscmp(pvarNew->bstrVal, m_pFonts[i].szFontName) == 0)
        {
            cf.bCharSet = m_pFonts[i].bCharSet;
            break;
        }
    }

    // Inform RTF control of our new font and charset.
    SendMessageW(m_hwndRTF, EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM) &cf);
    return S_OK;
}


///////////////////////////////////////////////////////////////////////////////
//
// Function:    SetFontSize 
//              This function is called in response to an cmdidFontSize
//              command to set the point size to that given in pvarNew.
//              Note that the input parameter is a string whereas the
//              interface requires the size in floating point points.
//
// Parameters:
//  pvarNew     Variant containing the point size the user has selected.
//
// Returns:     An HRESULT
///////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::SetFontSize(VARIANT *pvarNew)
{
    HRESULT                 hr;
    CComPtr<ITextSelection> srpTextSelection;   // Current selection
    CComPtr<ITextFont>      srpTextFont;        // Font object
    float                   fontSize;           // Font size in floating point

    // Get the current selection.
    if (FAILED(hr = m_srpTextDocObj->GetSelection(&srpTextSelection)))
        return hr;

    // Get the current font object for the selection.
    if (FAILED(hr = srpTextSelection->GetFont(&srpTextFont)))
        return hr;

    // Set character height in floating point points.
    fontSize = (float)wcstol(V_BSTR(pvarNew), NULL, 10);

    return srpTextFont->SetSize(fontSize);
}


///////////////////////////////////////////////////////////////////////////////
//
// Function:    GetFontName 
//              This function is called in response to an cmdidFontName
//              command to retrieve the current font name in order to
//              display it in the font combo box. This function uses
//              the ITextFont interface to retrieve the font face name.
//
// Parameters:
//  pvarOut     Variant in which to place the font face name.
//
// Returns:     An HRESULT
///////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::GetFontName(VARIANT *pvarOut)
{
    HRESULT                 hr;
    CComPtr<ITextSelection> srpTextSelection;   // Current selection
    CComPtr<ITextFont>      srpTextFont;        // Font object

    _ASSERTE(pvarOut);

    // Get the current selection.
    if (FAILED(hr = m_srpTextDocObj->GetSelection(&srpTextSelection)))
        return hr;

    // Get the current font object for the selection.
    if (FAILED(hr = srpTextSelection->GetFont(&srpTextFont)))
        return hr;

    // Call method to retrieve font face name
    V_VT(pvarOut)       = VT_BSTR;
    V_BSTR(pvarOut)     = NULL;
    return srpTextFont->GetName(&pvarOut->bstrVal);
}


///////////////////////////////////////////////////////////////////////////////
//
// Function:    GetFontSize 
//              This function is called in response to an cmdidFontSize
//              command to retrieve the current font size in order to
//              display it in the font combo box. This function retrieves
//              the font size via the ITextFont interface.
//              Note that the output parameter requires the size in
//              points as a string whereas the returned value from
//              the ITextFont interface is floating point.
//
// Parameters:
//  pvarOut     Variant in which to place the font size in points.
//
// Returns:     An HRESULT
///////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::GetFontSize(VARIANT *pvarOut)
{
    HRESULT                 hr;
    CComPtr<ITextSelection> srpTextSelection;   // Current selection
    CComPtr<ITextFont>      srpTextFont;        // Font object
    long                    lPointSize;         // Character height in points.
    float                   fontSize;           // Character size in floating point
    wchar_t                 szPointSize[20];    // Character point size as a string

    _ASSERTE(pvarOut);

    // Get the current selection.
    if (FAILED(hr = m_srpTextDocObj->GetSelection(&srpTextSelection)))
        return hr;

    // Get the current font object for the selection.
    if (FAILED(hr = srpTextSelection->GetFont(&srpTextFont)))
        return hr;

    // Get the current font size for the selection.
    if (FAILED(hr = srpTextFont->GetSize(&fontSize)))
        return hr;

    // Convert size to long rounding in the process
    lPointSize = (long)(fontSize + 0.5);

    ::VariantClear(pvarOut);
    _ltow(lPointSize, szPointSize, 10);

    // Place point size in the output variant.
    V_VT(pvarOut)       = VT_BSTR;
    V_BSTR(pvarOut)     = NULL;

    pvarOut->bstrVal = SysAllocString(szPointSize);

    return S_OK;
}



