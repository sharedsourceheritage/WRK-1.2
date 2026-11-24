
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// FeTbxPropPage.cpp 

#include "stdafx.h"     // system includes
#include "PrjInc.h"     // project includes
#include "time.h"       // localtime

//  Default Toolbox Fig Items
static FigLineType rgfltTbxDefault[] = 
{ 
    FigArrow, 
    FigCircle, 
    FigRectangle 
};

// Extra data associated with each item in the listview
// FE_LVITEM_INFO struct is attached to each item and maintains the info about
// whether the item is already on the toolbox or not, so we do not need
// to enumerate again when the dialog is dismissed, 
// srpIDataObject contains the pointer to IDataObject when the item is on the toolbox
// The data is freed when the ListView is destroyed
typedef struct tagFE_LVITEM_INFO
{
    CComPtr<IDataObject> srpIDataObject;  // IDataObject pointer if known
    CAtlString           strShortName;    // Short name to appear in the list view
    FigLineType          fltFigType;      // Type of the figure object
    FigsInfo             fiFigsInfo;      // Info about the figures in the IDataObject
                            // FigsInfo is designed to contain multiple figures,
                            // although only single figures are currently supported
                            // in the FigPkgs sample toolbox 
} FE_LVITEM_INFO;



// ========================================================================
//                                Construct, initialize, copy, and destruct
//

//-------------------------------------------------------------------------
//                                                           CFeTbxPropPage
//-------------------------------------------------------------------------
CFeTbxPropPage::CFeTbxPropPage()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        TEXT(": CFeTbxPropPage::CFeTbxPropPage \n") );

    m_srpIVsToolbox   = NULL;
    m_hwndLV  = NULL;

}

//-------------------------------------------------------------------------
//                                                                     Init
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::Init()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        TEXT(": CFeTbxPropPage::Init \n") );

    // register private clipboard format
    m_cf = RegisterClipboardFormatW(WSTR_CF_FigureSampleLine);
    ExpectedExprRet(m_cf);

    return S_OK;
}

//-------------------------------------------------------------------------
//                                                          ~CFeTbxPropPage
//-------------------------------------------------------------------------
CFeTbxPropPage::~CFeTbxPropPage()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        TEXT(": CFeTbxPropPage::~CFeTbxPropPage \n") );

    // Clean
    // m_srpIVsToolbox

}

//
//                                Construct, initialize, copy, and destruct
// ========================================================================



// ========================================================================
//                                                       IVsPackage support
//

//-------------------------------------------------------------------------
//                                                            ResetTbxItems
//
// Implements IVsPackage ::ResetDefaults for toolbox items
//  Add the default figure items to the toolbox
//  Parameters;
//    /* [in] */ PKGRESETFLAGS dwFlags
//          PKGRF_TOOLBOXITEMS 
//             Package to add its default items to toolbox
//          PKGRF_TOOLBOXSETUP 
//              Package to add additional default items to toolbox
//              For future upgrade of the package dll that adds new item to 
//              the toolbox. The number in 'Default Items' value in the 
//              registry is compared with the number persisted in the 
//              toolbox file. If the numbers are different, ResetDefaults 
//              is called with PKGRF_TOOLBOXSETUP
// Returns: 
//      S_OK if successful 
//      E_code if not
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::ResetTbxItems
(
    /* [in] */ PKGRESETFLAGS grfFlags
)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CFeTbxPropPage::ResetDefaults \n") );

    if( !(grfFlags & PKGRF_TOOLBOXITEMS) && !(grfFlags & PKGRF_TOOLBOXSETUP))
        return S_OK;

    HRESULT hr = S_OK;

    // Get Toolbox
    if (!m_srpIVsToolbox)
    {
        hr = _AtlModule.QueryService(SID_SVsToolbox, IID_IVsToolbox, (void**) &m_srpIVsToolbox);
        IfFailRet(hr);
    }

    // Get the tab name
    CAtlString str;
    if (! str.LoadString(IDS_TBXTABNAME)) 
        return E_FAIL;

    USES_CONVERSION;
    LPCOLESTR lpszTab = T2COLE(str);

    // Add localized Toolbox tab name here
    // if tab with the same name exist the call will return E_FAIL
    // so we do not check the result
    m_srpIVsToolbox->AddTab(lpszTab);

    // Add all the items
    int iNumItems = sizeof(rgfltTbxDefault) / sizeof(rgfltTbxDefault[0]);

    FigsInfo fiFigsInfo;

    // check for items already in the toolbox when PKGRF_TOOLBOXSETUP is the flag
    if (grfFlags & PKGRF_TOOLBOXSETUP)
    {
        CComPtr<IEnumToolboxItems>  srpETI;
        hr = EnumItemsOnToolbox(&srpETI);
        IfFailGo(hr);

        for(int i = 0; i < iNumItems; ++i)
        {
            CDataObject* pDO = new CDataObject(rgfltTbxDefault[i]); //ctor does not add a ref
            IfFailAllocGo(pDO);
            pDO->AddRef(); 
            FigsInfoEmpty(&fiFigsInfo);
            hr = GetFigsInfo(pDO, &fiFigsInfo);
            pDO->Release();
            IfFailGo(hr);
            if (IsOnToolbox(&fiFigsInfo, srpETI, NULL) != S_OK)
                hr = NewToolboxItem(rgfltTbxDefault[i], lpszTab, NULL);
            IfFailGo(hr);
        }
    } 
    else
        for(int i = 0; i < iNumItems; ++i)
        {
            hr = NewToolboxItem(rgfltTbxDefault[i], lpszTab, NULL);
            IfFailGo(hr);
        }

OnError:
    FigsInfoEmpty(&fiFigsInfo);
    return hr;
}


//-------------------------------------------------------------------------
//                                                          GetPropertyPage
//
// Implements IVsPackage ::GetPropertyPage
//
// Returns: 
//      S_OK if successful 
//      E_FAIL if not
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::GetPropertyPage
(
    /* [in]      */ REFGUID         rguidPage, 
    /* [in, out] */ VSPROPSHEETPAGE *ppage
)
{ 
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CFeTbxPropPage::GetPropertyPage\n") );

    if (!(IsEqualGUID(rguidPage, guidFigEditTbxPropPage))) return E_FAIL;

    // VSPROPSHEETPAGE:
    //      DWORD             dwSize;
    //      DWORD             dwFlags;        // same flags as PROPSHEETPAGE except 
                                              // PSP_USEHICON, PSP_USEICONID, PSP_USETITLE
    //      HINSTANCE         hInstance;
    //      WORD              wTemplateId;    // note: cant use named res
    //      DWORD             dwTemplateSize; // use dwTemplateSize & pTemplate with 
                                              // PSP_DLGINDIRECT
    //      BYTE             *pTemplate;
    //      DLGPROC           pfnDlgProc;
    //      LPARAM            lParam;
    //      LPFNPSPCALLBACKA  pfnCallback;
    //      UINT             *pcRefParent;
    //      DWORD             dwReserved;
    //      HWND              hwndDlg;        // if you can't pass a dialog template, 
                                    //  pass hInstance of NULL and
                                    //  fill in this field instead, we'll dummy up 
                                    //  a page and stick your hwnd on it.  
                                    //  If you do this, don't use lParam for anything

    ppage->dwSize      = sizeof(VSPROPSHEETPAGE);
    ppage->dwFlags     = PSP_HASHELP;
                         // same flags as PROPSHEETPAGE except 
                         // PSP_USEHICON, PSP_USEICONID, PSP_USETITLE
    ppage->hInstance   = _AtlModule.GetResourceInstance(); // get the UI dll
    ppage->wTemplateId = IDD_FETBXPROPPAGE;
    ppage->pfnDlgProc  = (DLGPROC)StaticTbxPropPageDlgProc;
    ppage->lParam      = (LPARAM)this;
    ppage->pfnCallback = NULL;
    ppage->pcRefParent = NULL;
  
    return S_OK;
}

//
//                                                       IVsPackage support
// ========================================================================



// ========================================================================
//                                         Property Page Dialog Box Support
//

//-------------------------------------------------------------------------
//                                                 StaticTbxPropPageDlgProc
//
// Returns: 
//      As per windows convention
//-------------------------------------------------------------------------
BOOL CALLBACK StaticTbxPropPageDlgProc
(
    HWND    hwnd,
    UINT    uMsg,
    WPARAM  wParam,
    LPARAM  lParam
)
{
    static CFeTbxPropPage* pTPP = NULL;

    if (uMsg == WM_INITDIALOG)
        pTPP = (CFeTbxPropPage*)((PROPSHEETPAGE*)lParam)->lParam;
  
    BOOL fRet = pTPP ? pTPP->TbxPropPageDlgProc(hwnd, uMsg, wParam, lParam) : FALSE;

    if (uMsg == WM_DESTROY)
        pTPP = NULL;

    return fRet;
}


//-------------------------------------------------------------------------
//                                                       TbxPropPageDlgProc
//
//
// Returns: 
//      As per windows convention
//-------------------------------------------------------------------------
BOOL CFeTbxPropPage::TbxPropPageDlgProc
(
    HWND      hwnd,
    UINT      uMsg,
    WPARAM    wParam,
    LPARAM    lParam
)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
        {
            // Initialize listview with appropriate columns
            LV_COLUMN     lvc;
            HWND          hwndLV = GetDlgItem(hwnd, IDC_FECDI_INSERTABLELIST);

            m_hwndLV = hwndLV;

            // Turn ListView into a checked ListView and set a few fancy bits
            DWORD dwExStyle = LVES_CHECKED | LVES_AUTOSORT | LVES_FULLROW ;
            ListView_ExtendStyle(hwndLV, dwExStyle);

            // Insert columns
            lvc.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
            lvc.fmt  = LVCFMT_LEFT;

            RECT rc;
            INT  cx;
            GetClientRect(hwndLV, &rc);

            cx = (rc.right - GetSystemMetrics(SM_CXVSCROLL)) / 5;

            // Name column
            lvc.cx    = cx * 2;
            CAtlString str;
            str.LoadString(IDS_FE_PP_LV_COLUMN1);
            lvc.pszText = (LPTSTR)(LPCTSTR) str;
            ListView_InsertColumn(hwndLV, 1, &lvc);

            // Path column
            lvc.cx    = cx * 2;
            str.LoadString(IDS_FE_PP_LV_COLUMN2);
            lvc.pszText = (LPTSTR)(LPCTSTR) str;
            ListView_InsertColumn(hwndLV, 2, &lvc);

            // Last Modified column
            lvc.cx    = cx;
            str.LoadString(IDS_FE_PP_LV_COLUMN3);
            lvc.pszText = (LPTSTR)(LPCTSTR) str;
            ListView_InsertColumn(hwndLV, 3, &lvc);

            // Fill the listview with the appropriate figures
            FillListView(hwndLV);

            return TRUE;
        }

        case WM_COMMAND:
            // check for browse button clicked when supported
            break;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            BeginPaint(hwnd, &ps);
            ShowItemDescription(m_hwndLV, -1);
            EndPaint(hwnd, &ps);
            return TRUE;
        }

        case WM_NOTIFY:
        {

            LPNMHDR pnmh   = (LPNMHDR)lParam;
            if (pnmh->hwndFrom == m_hwndLV)
            {
                if (pnmh->hwndFrom == GetFocus())
                {
                    // Is it a state change notification?
                    if ( pnmh->code == LVN_ITEMCHANGED && 
                         (((NM_LISTVIEW*)pnmh)->uChanged & LVIF_STATE))
                    {
                        // Yup, so is it a Checked state change notification?
                        NM_LISTVIEW* pLV = (NM_LISTVIEW*)pnmh;

                        if (((pLV->uNewState & LV_CHECKED)   && (pLV->uOldState & LV_UNCHECKED)) ||
                            ((pLV->uNewState & LV_UNCHECKED) && (pLV->uOldState & LV_CHECKED)))
                        {
                            // First, activate the Apply button since an item has changed
                            // PropSheet_Changed(GetParent(hwnd), hwnd);
                        }
                        else if (  (pLV->uNewState & LVIS_FOCUSED) && 
                                  !(pLV->uOldState & LVIS_FOCUSED))
                        {
                            ShowItemDescription(m_hwndLV, pLV->iItem);
                        }
                    }
                }
            }
            else if (pnmh->code == PSN_HELP)
            {
            }
            else if (pnmh->code == PSN_APPLY)
            {
                // Property page notification
                LV_ITEM lvi;
    
                lvi.mask  = LVIF_PARAM;
                lvi.iItem = 0;

                while (ListView_GetItem(m_hwndLV, &lvi))
                {
                    FE_LVITEM_INFO* plvii = (FE_LVITEM_INFO*)lvi.lParam;

                    if (ListView_IsItemChecked(m_hwndLV, lvi.iItem))
                    {
                        // Item is checked, so if it is not already on the toolbox
                        // create a new item and add it to the toolbox
                        if (!plvii->srpIDataObject)
                        {
                            NewToolboxItem(plvii->fltFigType, NULL, &plvii->srpIDataObject);
                        }
                    }
                    else
                    {                       
                        // Item not check and is on toolbox, so remove it, 
                        // and any duplicates of the same item
                        while (plvii->srpIDataObject)
                        {
                            m_srpIVsToolbox->RemoveItem(plvii->srpIDataObject);
                            plvii->srpIDataObject.Release();
                            IsOnToolbox(&(plvii->fiFigsInfo),NULL, &plvii->srpIDataObject);
                        }
                    }
                    lvi.iItem++;
                }
            }
            break;
        }
        case WM_DESTROY:
        {
            // Free associated data attached to each item in Listview
            LV_ITEM lvi;
            INT     iItem = 0;

            ZeroMemory(&lvi, sizeof(LV_ITEM));
            lvi.mask  = LVIF_PARAM;
            lvi.iItem = iItem;

            while (ListView_GetItem(m_hwndLV, &lvi))
            {
                FE_LVITEM_INFO* plvii = (FE_LVITEM_INFO*)lvi.lParam;

                if (plvii)
                {                    
                    // clean plvii->fiFigsInfo
                    FigsInfoEmpty(&plvii->fiFigsInfo);
                    // plvii->srpIDataObject cleanes itself
                    // plvii->strShortName cleanes itself
                    delete plvii;
                }   
                lvi.iItem = ++iItem;
            }

            // NULL out the ListView handles
            m_hwndLV = NULL;
            break;
        }
        default:
            break;
    }   
    return FALSE;
}


//-------------------------------------------------------------------------
//                                                             FillListView
//
// Fills the listview with the figure items
//
// Returns: 
//      S_OK if successful, 
//      E_code if not
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::FillListView
(
    /* [in] */  HWND hwndLV
)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CFeTbxPropPage::FillListView\n") );

    HRESULT hr;

    //  Enumerate current toolbox items so we can check/uncheck items based
    //  on if they are already on the toolbox or not
    CComPtr<IEnumToolboxItems> srpETI;
    hr = EnumItemsOnToolbox(&srpETI);
    IfFailRet(hr);

    // Now run through the list adding each to the Listview, inserting the name
    // and the item data
    // checking all items that are already on the toolbox.
    HCURSOR hCurOld = SetCursor(LoadCursor(NULL, IDC_WAIT));

    // Get the standard Fig Items
    // The default ones are used as a standard set
    int iNumItems = sizeof(rgfltTbxDefault) / sizeof(rgfltTbxDefault[0]);
    for(int i = 0; i < iNumItems; ++i)
    {
        CDataObject* pDO = new CDataObject(rgfltTbxDefault[i]); //ctor does not add a ref
        IfFailAllocGo(pDO);
        pDO->AddRef(); 

        hr = InsertListItem(    hwndLV, 
                                static_cast<IDataObject*>(pDO), 
                                srpETI, 
                                rgfltTbxDefault[i]);
        pDO->Release();

        IfFailGo(hr); 
    }

    if (SUCCEEDED (hr) )
    {
        UINT stateLV = LVIS_SELECTED | LVIS_FOCUSED;
        UINT maskLV  = LVIS_SELECTED | LVIS_FOCUSED;
        ListView_SetItemState(hwndLV, 0, stateLV, maskLV);
    }

OnError:
    // Final cleanup
    SetCursor(hCurOld);

    return hr;
}



//-------------------------------------------------------------------------
//                                                           InsertListItem
//
// Returns: 
//  S_OK    - the item is added to the list, 
//  E_xxx   - error
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::InsertListItem
(
    /* [in]      */ HWND                  hwndLV,
    /* [in, ref] */ IDataObject*          pDO,
    /* [in, ref] */ IEnumToolboxItems*    pETI,
    /* [in]      */ FigLineType           flt
)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CFeTbxPropPage::InsertListItem\n") );
    ExpectedPtrRet(hwndLV);
    ExpectedPtrRet(pDO);
    ExpectedPtrRet(pETI);

    HRESULT  hr = E_FAIL;
    BOOL fChecked = FALSE;
    USES_CONVERSION;

    // FE_LVITEM_INFO struct is attached to each listview item 
    // See the description in the structure declaration.
    FE_LVITEM_INFO* plvii = new FE_LVITEM_INFO;
    IfFailAllocRet(plvii);

    LV_ITEMA lvi;
    ZeroMemory(&lvi, sizeof(LV_ITEMA));

    // Insert the item
    lvi.mask   |= LVIF_TEXT | LVIF_PARAM;
    //LVIF_TEXT     The pszText member is valid or must be filled in.
    //LVIF_PARAM    The lParam member is valid or must be filled in.
    
    // initialize the plvii
    hr = GetFigsInfo(pDO, &plvii->fiFigsInfo);
    IfFailGo(hr);

    hr = IsOnToolbox(&plvii->fiFigsInfo, pETI, &plvii->srpIDataObject);
    IfFailGo(hr);

    plvii->fltFigType = plvii->fiFigsInfo.GetAt(0)->flt;

    if (plvii->fiFigsInfo.Count() > 1)
        plvii->strShortName.LoadString(IDS_TOOLMULFIGS);
    else 
        GetFigShortName(plvii->fltFigType, &plvii->strShortName); 

    {
    CT2A aszText(plvii->strShortName);
    lvi.pszText = aszText;
    lvi.lParam  = (LPARAM)plvii;

    // Check the item if it is on toolbox
    fChecked = (plvii->srpIDataObject != NULL );

    lvi.iItem   = ListView_InsertCheckItem(hwndLV, &lvi, fChecked);
  
    if (lvi.iItem >= 0)
    {
        // Item successfully added
        hr = S_OK;

        // Fill in server path & name
           TCHAR szPath[_MAX_PATH];
        DWORD dwLen = ::GetModuleFileName(_AtlModule.GetModuleInstance(), szPath, _MAX_PATH);
        // make sure we null-terminate the buffer
        if (dwLen == 0) 
            szPath[0] = _T('\0');
        else if (dwLen == _MAX_PATH) 
            szPath[_MAX_PATH - 1] = _T('\0');
        ListView_SetItemText(hwndLV, lvi.iItem, 1, szPath);

        // Fill in last modified date for server name
        struct _stat buf;
        int     result = _tstat(szPath, &buf);

        if (result == 0)
        {
              TCHAR szTime[50];
              struct tm* newtime = localtime(&buf.st_mtime);

              _tcsftime(szTime, sizeof(szTime)/sizeof(szTime[0]), _T("%m/%d/%y %H:%M%p"), newtime);
              ListView_SetItemText(hwndLV, lvi.iItem, 2, szTime);
        }
    }
    else
        hr = E_FAIL;
    }
OnError:
    if (FAILED(hr))
    {
        FigsInfoEmpty(&plvii->fiFigsInfo);
        delete plvii;
    }
    return hr;
}


//-----------------------------------------------------------------------------
//                                                           EnumItemsOnToolbox
//
// Enumerates toolbox items
//
// Returns: 
//  S_OK    - if successful, 
//  E_xxx   - error
//-----------------------------------------------------------------------------
HRESULT CFeTbxPropPage::EnumItemsOnToolbox
(
    /* [out] */ IEnumToolboxItems** ppETI
)
{
    ExpectedPtrRet(ppETI);
    InitParam(ppETI);

    HRESULT hr = S_OK;
    
    if (!m_srpIVsToolbox)
    {
        hr = _AtlModule.QueryService(SID_SVsToolbox, IID_IVsToolbox, (void**) &m_srpIVsToolbox);
        IfFailRet(hr);
    }

    hr = m_srpIVsToolbox->EnumItems(NULL, ppETI); // Entire Toolbox
    IfFailRet(hr);

    return hr;
}


//-----------------------------------------------------------------------------
//                                                               NewToolboxItem
//
// Adds a new toolbox item to the toolbox with the given type, 
//
// Returns: 
//  S_xxx    - if successful, 
//  E_xxx   - error
//-----------------------------------------------------------------------------
HRESULT CFeTbxPropPage::NewToolboxItem
(
    /* [in]  */  FigLineType     flt,             // figure to add
    /* [in]  */  LPCOLESTR       pszTab,          // on pszTab Toolbox tab, can be NULL 
    /* [out] */  IDataObject**   ppIDataObject    // can be NULL
)
{
    HRESULT hr = E_OUTOFMEMORY;
    SafeInitParam(ppIDataObject);

    CDataObject* pDataObject = new CDataObject(flt);
    IfFailAllocRet(pDataObject);

    IDataObject* pIDataObject = static_cast<IDataObject*>(pDataObject);
    pIDataObject->AddRef();

    TBXITEMINFO tbxinfo;
    hr = GetTbxItemInfoBitmap(flt, &tbxinfo);
    IfFailGo(hr);
    hr = GetTbxItemInfoText(flt, &(tbxinfo.bstrText) );
    IfFailGo(hr);

    if (ppIDataObject)
    {
        *ppIDataObject = pIDataObject;
        pIDataObject->AddRef();
    }
    hr = m_srpIVsToolbox->AddItem(pIDataObject, &tbxinfo, pszTab);

OnError:
    pIDataObject->Release();

    if (tbxinfo.hBmp)
        DeleteObject((HGDIOBJ)(HBITMAP)(tbxinfo.hBmp));

    if (tbxinfo.bstrText)
        SysFreeString(tbxinfo.bstrText);

    return hr;
}


//-----------------------------------------------------------------------------
//                                                          ShowItemDescription
//
//  Displays the figure description and image inthe description area
//
// Returns: 
//  S_OK  - if successful, 
//  E_xxx - error
//-----------------------------------------------------------------------------
HRESULT CFeTbxPropPage::ShowItemDescription
(
    /* [in] */  HWND hwndLV, 
    /* [in] */  INT  iItem
)
{
    ExpectedExprRet(hwndLV);

    // Clear out the current image
    HWND    hwndDlg = GetParent(hwndLV);
    HDC     hdc     = GetDC(hwndDlg);
    RECT    rc;

    GetWindowRect(GetDlgItem(hwndDlg, IDC_CDI_BITMAP), &rc);
    ScreenToClient(hwndDlg, (LPPOINT)&rc.left);
    ScreenToClient(hwndDlg, (LPPOINT)&rc.right);
    FillRect(hdc, &rc, (HBRUSH)(COLOR_3DFACE+1));

    // Get index of currently selected image if there is one
    if (iItem < 0)
        iItem = ListView_GetNextItem(hwndLV, -1, LVNI_FOCUSED);

    if (iItem >= 0)
    {
        // Get Item info referenced by the lParam of the item
        LVITEM lvi;

        ZeroMemory(&lvi, sizeof(LV_ITEM));
        lvi.mask  = LVIF_PARAM;
        lvi.iItem = iItem;

        if (ListView_GetItem(hwndLV, &lvi))
        {
            // Got the item info, now get the actual bitmap
            // image list to get transparency
            FE_LVITEM_INFO* pItem = (FE_LVITEM_INFO*)lvi.lParam;
            TBXITEMINFO Info;
            BITMAP        bmp;

            GetTbxItemInfoBitmap(pItem->fltFigType, &Info);    
            GetObject(Info.hBmp, sizeof(BITMAP), &bmp);
            HIMAGELIST hImage = ImageList_Create(Info.iImageWidth,
                          bmp.bmHeight, 
                          ILC_COLOR4 | ILC_MASK, 
                          1, 1);
            if (hImage)
            {
                // Finally, display the image via an Image list
                ImageList_AddMasked(hImage, Info.hBmp, Info.clrTransparent);      
                ImageList_Draw(hImage,
                                Info.iImageIndex,
                                hdc, 
                                rc.left + (rc.right  - rc.left - Info.iImageWidth)  / 2,
                                rc.top  + (rc.bottom - rc.top  - bmp.bmHeight) / 2,
                                ILD_TRANSPARENT);
                ImageList_Destroy(hImage);
            }

            DeleteObject((HGDIOBJ)(HBITMAP)(Info.hBmp));
      
            // Now get the description for this item
            CAtlString strDescr;
            GetDescription(&pItem->fiFigsInfo, &strDescr);
            SetWindowText(GetDlgItem(hwndDlg, IDC_FECDI_INFOLOCATION), 
                            strDescr);

            // Get the version 
            // Note: When the server version is registered get it from the registry
            TCHAR vers[] = _T("1.0");
            SetWindowText(GetDlgItem(hwndDlg, IDC_VERSION), vers);
            
            // Get the language
            // Note; When using controls, get the language for the control, via its typelib
            TCHAR lang[] = _T("Language Neutral");
            SetWindowText(GetDlgItem(hwndDlg, IDC_LANGUAGE), lang);
            
        }
    }
    ReleaseDC(hwndDlg, hdc);
    return S_OK;
}


//-------------------------------------------------------------------------
//                                                              IsOnToolbox
//                  
// Determines if the given item is already on the toolbox
//
// Returns: 
//      S_OK    - YES, it is    => *ppIDataObject is a pointer to IDataObject
//      S_FALSE - NO, it is not => *ppIDataObject is NULL
//      E_xxx   - Error 
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::IsOnToolbox
(
    /* [in, ref]    */  FigsInfo *          pFigsInfo,       // the object we are looking for
    /* [in, unique] */  IEnumToolboxItems*  pIEnumToolboxItems, //can be NULL => enumerate 
    /* [out]        */  IDataObject**       ppIDataObject       // optional
)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CFeTbxPropPage::IsOnToolbox \n") );

    ExpectedPtrRet(pFigsInfo);
    if (ppIDataObject)
        *ppIDataObject=NULL;

    HRESULT     hr;

    BOOL fReleaseETI = FALSE; // indicates who created the pIEnumToolboxItems
    if (!pIEnumToolboxItems)
    {
        //enumerate the items
        hr = EnumItemsOnToolbox(&pIEnumToolboxItems);
        IfFailRet(hr);
        fReleaseETI = TRUE;
    }

    BOOL                 fOnToolbox = FALSE;
    FORMATETC            fetc       = { m_cf, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
    FigsInfo             fiDataObject;
    CComPtr<IDataObject> srpIDataObject;

    pIEnumToolboxItems->Reset();
    
    while (!fOnToolbox && (pIEnumToolboxItems->Next(1, &srpIDataObject, NULL) == S_OK))
    {
        if (GetFigsInfo(srpIDataObject,&fiDataObject) == S_OK)
        {
            fOnToolbox = (AreFiguresEqual(pFigsInfo, &fiDataObject) == S_OK);          
            FigsInfoEmpty(&fiDataObject);
            if (fOnToolbox)
                break;
        }
        srpIDataObject.Release();
    }

    // If we obtained the enumeration object, release it
    if (fReleaseETI)
        pIEnumToolboxItems->Release();
    
    if (fOnToolbox)
        hr = S_OK;
    else
        hr = S_FALSE;

    if (ppIDataObject)
        *ppIDataObject = srpIDataObject.Detach();

    return hr;
}


//-------------------------------------------------------------------------
//                                                          AreFiguresEqual
//
// Determines if the two figures sets are equal
//
// Returns: 
//      S_OK    - YES, they are
//      S_FALSE - NO, the are not
//      E_xxx   - error
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::AreFiguresEqual
(
    /* [in, ptr]  */  FigsInfo * pFigsInfo1,       
    /* [in, ptr]  */  FigsInfo * pFigsInfo2    
)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CFeTbxPropPage::AreFiguresEqual \n") );

    ExpectedPtrRet(pFigsInfo1);
    ExpectedPtrRet(pFigsInfo2);

    if (pFigsInfo1->Count() != pFigsInfo2->Count()) 
        return S_FALSE;

    FE_FIG_INFO * pfi1;
    FE_FIG_INFO * pfi2;

    for (size_t i = 0; i < pFigsInfo1->Count(); i++)
    {
        pfi1 = pFigsInfo1->GetAt(i);
        pfi2 = pFigsInfo2->GetAt(i);

        if (pfi1->flt != pfi2->flt) 
            return S_FALSE;
        if (pfi1->lPar1 != pfi2->lPar1) 
            return S_FALSE;
        if (pfi1->lPar2 != pfi2->lPar2) 
            return S_FALSE;
        if (pfi1->lPar3 != pfi2->lPar3) 
            return S_FALSE;
        if (pfi1->lPar4 != pfi2->lPar4) 
            return S_FALSE;       
    }
    return S_OK;
}


//-------------------------------------------------------------------------
//                                                            FigsInfoEmpty
// Clean FigsInfo
// Returns: 
//      S_OK    - if successful
//      E_xxx   - if error 
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::FigsInfoEmpty
(
    /* [in, out] */  FigsInfo *  pFigsInfo // the object to clean
)
{
    ExpectedPtrRet(pFigsInfo);

    for (size_t i=0; i< pFigsInfo->Count(); i++)
    {
        delete pFigsInfo->GetAt(i);
    }
    pFigsInfo->RemoveAll();
    return S_OK;
}

//
//                                         Property Page Dialog Box Support
// ========================================================================



//=========================================================================
//                                                         Get info methods
//

//-------------------------------------------------------------------------
//                                                              GetFigsInfo
//
// Get the information about the figures contained in a data object
//
// Returns: 
//      S_OK    - ok
//      xxx     - Fails to get the info 
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::GetFigsInfo(
    /* [in, ref]  */  IDataObject * pIDataObject, // object to get info from 
    /* [out]      */  FigsInfo *    pFigsInfo
    )
{
    //ENVSDK_TRACE(envsdkTraceGeneral, TLF,  _T(": GetFigsInfo \n") );

    // check the input
    ExpectedPtrRet(pIDataObject);
    ExpectedPtrRet(pFigsInfo);
    ExpectedExprRet( (m_cf != 0) );

    // set the output
    FigsInfoEmpty(pFigsInfo);

    HRESULT     hr;

    // Query for our format
    FORMATETC   fmtetc;
    fmtetc.cfFormat = m_cf;
    fmtetc.dwAspect = DVASPECT_CONTENT;
    fmtetc.ptd      = NULL;
    fmtetc.lindex   = -1;
    fmtetc.tymed    = TYMED_HGLOBAL;
    hr = pIDataObject->QueryGetData(&fmtetc);
    if (hr != S_OK) return hr;

    STGMEDIUM   stgm;
    memset(&stgm, 0, sizeof stgm);
    hr = pIDataObject->GetData( &fmtetc, &stgm);
    if (hr != S_OK) return hr;

    // Now get the data in m_cf format
    HANDLE      hData = stgm.hGlobal;

    // figure out how much memory was allocated per line (without comment)
    ULONG cPerLine =    sizeof(ULONG) +         // total number of bytes
                        sizeof(FigLineType) +   // type
                        (4 * sizeof(long));     // parameters

    ULONG cItems; // number of lines

    BYTE* pData = ((BYTE*)GlobalLock(hData));
    IfFailAllocGo(pData);

    cItems = *(ULONG *)pData;           
    pData += sizeof(ULONG);

    // get each item's properties from the memory block
    while (cItems --)
    {
        FE_FIG_INFO * pfiTmp = new FE_FIG_INFO;
        IfFailAllocGo(pfiTmp); 

        ULONG cLineBytes;
        cLineBytes = (ULONG)*pData;             // number of bytes in this line
        pData += sizeof(ULONG);

        pfiTmp->flt = *(FigLineType *)pData;   // type
        pData += sizeof(FigLineType);

        pfiTmp->lPar1 = (long)*pData;          // params
        pData += sizeof(long);
        pfiTmp->lPar2 = (long)*pData;          // params
        pData += sizeof(long);
        pfiTmp->lPar3 = (long)*pData;          // params
        pData += sizeof(long);
        pfiTmp->lPar4 = (long)*pData;          // params
        pData += sizeof(long);

        ULONG cCmtChar = cLineBytes - cPerLine;
        CAtlString strTmp((WCHAR*)pData, cCmtChar/* /sizeof(WCHAR) */); ///note: see the note in DataObj
        pfiTmp->strComment = strTmp;      
        pData += cCmtChar * sizeof(WCHAR);
        
        pFigsInfo->Add(pfiTmp);
    }

OnError:
    if (FAILED(hr)) 
    {
        FigsInfoEmpty(pFigsInfo);
    }
    if (hData) GlobalUnlock(hData);
    if (stgm.pstm) ReleaseStgMedium(&stgm);
    return hr;
}


//-------------------------------------------------------------------------
//                                                           GetDescription
//  Get the full description of the figure(s)
// Returns: 
//  S_OK    - if successful, 
//  E_xxx   - error
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::GetDescription
(
    /* [in, ref] */  FigsInfo *    pFigsInfo,
    /* [out]     */  CAtlString *  pstr
)
{
    ExpectedPtrRet(pFigsInfo);
    ExpectedPtrRet(pstr);
    pstr->Empty();

    HRESULT         hr      = S_OK;
    size_t          cFigs   = pFigsInfo->Count();
    CAtlString      str;
    FE_FIG_INFO *   pfi;
    TCHAR           buf[50];
   
    if (cFigs > 1)
    {
        if (! str.LoadString(IDS_TOOLMULFIGS)) 
            hr = E_FAIL;
        IfFailGo(hr);
        (*pstr) += str;
    }

    for (size_t i = 0; i < cFigs; i++)
    {
        pfi = pFigsInfo->GetAt(i);
        str.Empty();
        hr = GetFigShortName(pfi->flt,&str);
        if (FAILED(hr))
            continue;

        (*pstr) += str;
        (*pstr) += _T(" ");
        (*pstr) +=  _ltot( pfi->lPar1, buf, 10 );
        (*pstr) += _T(" ");
        (*pstr) +=  _ltot( pfi->lPar2, buf, 10 );
        (*pstr) += _T(" ");
        (*pstr) +=  _ltot( pfi->lPar3, buf, 10 );
        (*pstr) += _T(" ");
        if (pfi->flt != FigCircle)
        {
            (*pstr) +=  _ltot( pfi->lPar4, buf, 10 );
            (*pstr) += _T(" ");
        }
        (*pstr) += pfi->strComment;
    }

OnError:
    if (FAILED(hr))
        pstr->Empty();
    return hr;
}


//-------------------------------------------------------------------------
//                                                          GetFigShortName
// Obtains the text to be used for the item label/tooltips
//
// Returns: 
//  S_OK    - if successful, 
//  E_xxx   - error
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::GetFigShortName
(
    /* [in]  */   FigLineType  flt,
    /* [out] */   CAtlString*  pstr
)
{
    ExpectedPtrRet(pstr);

    ULONG resid = 0;

    switch (flt)
    {
        case FigArrow:
            resid = IDS_TOOLARROW;
            break;
        case FigCircle:
            resid = IDS_TOOLCIRCLE;
            break;
        case FigRectangle:
            resid = IDS_TOOLRECTANGLE;
            break;
        default:
            break;
    }
    if (! resid) return E_INVALIDARG;

    if (! pstr->LoadString(resid)) return E_FAIL;
    return S_OK;

}


//-------------------------------------------------------------------------
//                                                       GetTbxItemInfoText
//
// Obtains the text to be used for the item label/tooltips
//
// Returns: 
//  S_OK    - if successful, 
//  E_xxx   - error
//-------------------------------------------------------------------------
HRESULT CFeTbxPropPage::GetTbxItemInfoText
(
    /* [in]  */ FigLineType flt,
    /* [out] */ BSTR *      pbstrText
)
{
 
    ExpectedPtrRet(pbstrText);
    InitParam(pbstrText);

    HRESULT     hr  = S_OK;
    CAtlString  str;
    
    hr = GetFigShortName(flt, &str);
    IfFailRet(hr);

    *pbstrText = str.AllocSysString();
    if (! (*pbstrText))
        hr = E_OUTOFMEMORY;

    return hr;
}


//-----------------------------------------------------------------------------
//                                                         GetTbxItemInfoBitmap
//
// Obtains the bitmap to be used for the item in the toolbox
//
// Returns: 
//  S_OK    - if successful, 
//  E_xxx   - error
//-----------------------------------------------------------------------------
HRESULT CFeTbxPropPage::GetTbxItemInfoBitmap
(
    /* [in]  */ FigLineType     flt,
    /* [out] */ TBXITEMINFO *   ptbxinfo
)
{
    ExpectedPtrRet(ptbxinfo);

    HRESULT hr = S_OK;
    ptbxinfo->dwFlags = TBXIF_IMAGEINDEX | TBXIF_DELETEBITMAP;
    ptbxinfo->hBmp  = LoadBitmap( _AtlModule.GetModuleInstance(), 
                                  MAKEINTRESOURCE(IDB_IMAGELIST) );

    ptbxinfo->clrTransparent = RGB(0,255,0);
    ptbxinfo->iImageIndex = flt;
    ptbxinfo->iImageWidth = 16;

    return hr;
}

//                                                         Get info methods
//=========================================================================
