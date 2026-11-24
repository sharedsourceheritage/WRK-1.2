
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// FETbxPropPage.h : header file
//

#pragma once


// Information about a figure
typedef struct tagFE_FIG_INFO
{
    FigLineType flt;           // type
    long        lPar1;         // parameter1
    long        lPar2;         // parameter2
    long        lPar3;         // parameter3
    long        lPar4;         // parameter4
    CAtlString  strComment;    // comments
} FE_FIG_INFO;

// information about a set of figures
typedef CEnvSDKPtrArray<FE_FIG_INFO> FigsInfo;



/////////////////////////////////////////////////////////////////////////////
//                                                            CFeTbxPropPage
class CFeTbxPropPage
{

// ========================================================================
//                                                                  friends
//

    //---------------------------------------------------------------------
    //                                             StaticTbxPropPageDlgProc
    // Returns: 
    //      As per windows convention
    friend BOOL CALLBACK StaticTbxPropPageDlgProc
    (
        HWND    hwnd,
        UINT    uMsg,
        WPARAM  wParam,
        LPARAM  lParam
    );
    //---------------------------------------------------------------------
//
//                                                                  friends
// ========================================================================

// ========================================================================
//                                Construct, initialize, copy, and destruct
//
public:
    CFeTbxPropPage();
    HRESULT Init();
    virtual ~CFeTbxPropPage();
//
//                                Construct, initialize, copy, and destruct
// ========================================================================


// ========================================================================
//                                                       IVsPackage support
//
public:
    //---------------------------------------------------------------------
    //                                                        ResetTbxItems
    //
    // Implements IVsPackage ::ResetDefaults for toolbox items
    //  Add the default figure items to the toolbox
    //  Parameters;
    //    /* [in] */ PKGRESETFLAGS dwFlags
    //          PKGRF_TOOLBOXITEMS 
    //             Package to add its default items to toolbox
    //          PKGRF_TOOLBOXSETUP 
    //              Package to add additional default items to toolbox
    //              For future upgrade of the package dll that adds new item 
    //              to the toolbox. The number in 'Default Items' value in  
    //              the registry is compared with the number persisted in the 
    //              toolbox file. If the numbers are different, ResetDefaults 
    //              is called with PKGRF_TOOLBOXSETUP
    // Returns: 
    //      S_OK if successful 
    //      E_code if not
    //---------------------------------------------------------------------
    HRESULT ResetTbxItems
    (
        /* [in] */ PKGRESETFLAGS dwFlags
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                      GetPropertyPage
    // Implements IVsPackage ::GetPropertyPage
    // Returns: 
    //      S_OK if successful 
    //      E_FAIL if not
    HRESULT GetPropertyPage
    (
        /* [in]      */ REFGUID         rguidPage, 
        /* [in, out] */ VSPROPSHEETPAGE *ppage
    );
    //---------------------------------------------------------------------

//
//                                                       IVsPackage support
// ========================================================================


// ========================================================================
//                                         Property Page Dialog Box Support
//
protected:
    //---------------------------------------------------------------------
    //                                                   TbxPropPageDlgProc
    // Returns: 
    //      As per windows convention
    BOOL TbxPropPageDlgProc
    (
        HWND      hwnd,
        UINT      uMsg,
        WPARAM    wParam,
        LPARAM    lParam
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                         FillListView
    // Fills the listview with the figure items
    // Returns: 
    //      S_OK if successful, 
    //      E_code if not
    HRESULT FillListView
    (
        /* [in] */  HWND hwndLV
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                       InsertListItem
    // Returns: 
    //  S_OK    - the item is added to the list, 
    //  E_xxx   - error
    HRESULT InsertListItem
    (
        /* [in]      */ HWND                  hwndLV,
        /* [in, ref] */ IDataObject*          pDO,
        /* [in, ref] */ IEnumToolboxItems*    pETI,
        /* [in]      */ FigLineType           flt
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                   EnumItemsOnToolbox
    //
    // Enumerates toolbox items
    //
    // Returns: 
    //  S_OK    - if successful, 
    //  E_xxx   - error
    HRESULT EnumItemsOnToolbox
    (
        /* [out] */ IEnumToolboxItems** ppETI
    );
    //---------------------------------------------------------------------



    //---------------------------------------------------------------------
    //                                                       NewToolboxItem
    // Adds a new toolbox item to the toolbox with the given type, 
    // Returns: 
    //  S_xxx    - if successful, 
    //  E_xxx   - error
    HRESULT NewToolboxItem
    (
        /* [in]  */  FigLineType     flt,             // figure to add
        /* [in]  */  LPCOLESTR       pszTab,          // on pszTab Toolbox tab, can be NULL 
        /* [out] */  IDataObject**   ppIDataObject    // can be NULL
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                  ShowItemDescription
    // Displays the figure description and image inthe description area
    // Returns: 
    //  S_OK  - if successful, 
    //  E_xxx - error
    HRESULT ShowItemDescription
    (
        /* [in] */  HWND hwndLV, 
        /* [in] */  INT  iItem
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                          IsOnToolbox
    // Determines if the given item is already on the toolbox
    // Returns: 
    //      S_OK    - YES, it is    => *ppIDataObject is a pointer to IDataObject
    //      S_FALSE - NO, it is not => *ppIDataObject is NULL
    //      E_xxx   - Error 
    HRESULT IsOnToolbox
    (
        /* [in, ref]    */  FigsInfo *          pFigsInfo,       // the object we are looking for
        /* [in, unique] */  IEnumToolboxItems*  pIEnumToolboxItems, //can be NULL => enumerate 
        /* [out]        */  IDataObject**       ppIDataObject    // optional
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                      AreFiguresEqual
    // Determines if the two figures sets are equal
    // Returns: 
    //      S_OK    - YES, they are
    //      S_FALSE - NO, the are not
    //      E_xxx   - error
    HRESULT AreFiguresEqual
    (
        /* [in, ptr]  */  FigsInfo * pFigsInfo1,       
        /* [in, ptr]  */  FigsInfo * pFigsInfo2    
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                        FigsInfoEmpty
    // Clean FigsInfo
    // Returns: 
    //      S_OK    - if successful
    //      E_xxx   - if error 
    HRESULT FigsInfoEmpty
    (
        /* [in, out] */  FigsInfo *  pFigsInfo // the object to clean
    );
    //---------------------------------------------------------------------
//
//                                         Property Page Dialog Box Support
// ========================================================================


//=========================================================================
//                                                         Get info methods
//
protected:
    //---------------------------------------------------------------------
    //                                                          GetFigsInfo
    //
    // Get the information about the figures contained in a data object
    //
    // Returns: 
    //      S_OK    - ok
    //      xxx     - Fails to get the info 
    HRESULT GetFigsInfo
    (
        /* [in, ref]  */  IDataObject * pIDataObject, // object to get info from 
        /* [out]      */  FigsInfo *    pFigsInfo
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                       GetDescription
    //  Get the full description of the figure(s)
    // Returns: 
    //  S_OK    - if successful, 
    //  E_xxx   - error
    HRESULT GetDescription
    (
        /* [in, ref] */  FigsInfo *    pFigsInfo,
        /* [out]     */  CAtlString *  pstr
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                      GetFigShortName
    // Obtains the text to be used for the item label/tooltips
    //
    // Returns: 
    //  S_OK    - if successful, 
    //  E_xxx   - error
    HRESULT GetFigShortName
    (
        /* [in]  */   FigLineType  flt,
        /* [out] */   CAtlString*  pstr
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                   GetTbxItemInfoText
    //
    // Obtains the text to be used for the item label/tooltips
    //
    // Returns: 
    //  S_OK    - if successful, 
    //  E_xxx   - error
    HRESULT GetTbxItemInfoText
    (
        /* [in]  */ FigLineType flt,
        /* [out] */ BSTR *      pbstrText
    );
    //---------------------------------------------------------------------


    //---------------------------------------------------------------------
    //                                                 GetTbxItemInfoBitmap
    //
    // Obtains the bitmap to be used for the item in the toolbox
    //
    // Returns: 
    //  S_OK    - if successful, 
    //  E_xxx   - error
    HRESULT GetTbxItemInfoBitmap
    (
        /* [in]  */ FigLineType     flt,
        /* [out] */ TBXITEMINFO *   ptbxinfo
    );
    //---------------------------------------------------------------------

//                                                         Get info methods
//=========================================================================


// ========================================================================
//                                                                  Members
//  
protected:

    CComPtr<IVsToolbox>     m_srpIVsToolbox;  // Pointer to the one and only toolbox
    HWND                    m_hwndLV; // Handle to the List View control
    UINT                    m_cf;     // Custom Clipboard Format

//  
//                                                                  Members
// ========================================================================

};
