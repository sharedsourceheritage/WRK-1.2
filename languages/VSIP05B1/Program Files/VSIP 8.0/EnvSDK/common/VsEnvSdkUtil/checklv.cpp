//=----------------------------------------------------------------------=
// CheckLV.Cpp
//=----------------------------------------------------------------------=
// Checked list view code.  
//
//=----------------------------------------------------------------------=
// Copyright 1997 Microsoft Corporation, all rights reserved.
// Information Contained Herein Is Proprietary and Confidential.

#include "pch.h"
#include "vsmem.h"
#include "checklv.h"

#define ImageList_CreateAPI    ImageList_Create
#define ImageList_DestroyAPI   ImageList_Destroy
#define ImageList_AddMaskedAPI ImageList_AddMasked
#define ImageList_AddAPI       ImageList_Add

#define WM_REDRAWFRAME WM_USER + 1

#define STATE_NONE  0
#define STATE_LEFT  1
#define STATE_RIGHT 2

//=----------------------------------------------------------------------=
// Private goodies
//

struct STYLEDATA
  {
  LONG       idcListView;
  HWND       hwndHeader;
  WNDPROC    pfnOldListViewProc;
  DWORD      dwFlags;
  int	     nLastCol; // Last column sorted on if LVES_AUTOSORT
  DWORD	     dwSort;   // LVS_SORTASCENDING or LVS_SORTDESCENDING
  BOOL       fHeader;  // TRUE if the header data below is valid
  HD_ITEM    hdr;      // First column in the header; we owner draw this
  RECT       rcItem;
  TCHAR      szHdrText[100];
  STYLEDATA *pNext;
  };
typedef STYLEDATA *PSTYLEDATA;

struct SUBCLASSDATA
  {
  WNDPROC     pfnOldParentProc;
  PSTYLEDATA  pStyles;
  };
typedef SUBCLASSDATA *PSUBCLASSDATA;

struct COMPAREDATA
  {
  HWND  hwndListView;
  int   nCol;
  DWORD dwSort;	// LVS_SORTASCENDING or LVS_SORTDESCENDING
  };
typedef COMPAREDATA *PCOMPAREDATA;

static const TCHAR _szDataProp[] = "ListView_StyleData";
static LRESULT CALLBACK _ListViewParentProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
static LRESULT CALLBACK _ListViewProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

static void _ConfigureListViewHeader(HWND hwndListView, PSTYLEDATA pData);
static void _ResetListViewHeader(HWND hwndListView, PSTYLEDATA pData);
static void _DrawHeaderItem(PSTYLEDATA pData, WPARAM fCheck);
static int  _FindListViewItem(HWND hwndListView, LPARAM lparam);
static void _OnClick(HWND hwnd);
static void _OnDblClk(HWND hwnd);
static void _OnKeyDown(HWND hwnd, WORD wVirtKey);
static void _ToggleState(HWND hwnd, int nItem);

static int CALLBACK _GenericListViewCompare(LPARAM l1, LPARAM l2, LPARAM lParam);
static int CALLBACK _CheckListViewCompare(LPARAM l1, LPARAM l2, LPARAM lParam);

static int cxBitmap;
static int cyBitmap;

//
//
// Public functions
//
//


//=----------------------------------------------------------------------=
// DrawCheck
//=----------------------------------------------------------------------=
// Draws a check box.
// 
void DrawCheck
(
  HDC   hdc,        // hdc to draw the checkmark to
  int   nx,         // x position of upper left corner of check
  int   ny,         // y position of upper left corner of check
  int   nWidth,     // width of check, use DRAWCHECK_WIDTH for standard width
  int   nHeight,    // height of check, use DRAWCHECK_HEIGHT for standard height
  DWORD dwStyle     // style.  Must be one of the four styles above.
)
  {
  static HBITMAP hbmChecks = NULL;
  static int nBitmapSize = 0;
  static COLORREF clrBtnFace;
  static COLORREF clrBtnShadow;
  static COLORREF clrBtnText;
  static COLORREF clrWindow;

  // Checks look really stupid if they're not square
  //
  int nCheckSize = min(nWidth, nHeight);
  int nHeightOffset = (nHeight - nCheckSize) / 2;
  int nWidthOffset = (nWidth - nCheckSize) / 2;

  if(!hbmChecks 
    || nBitmapSize != nCheckSize
    || clrBtnFace != GetSysColor(COLOR_BTNFACE)
    || clrBtnShadow != GetSysColor(COLOR_BTNSHADOW)
    || clrBtnText != GetSysColor(COLOR_BTNTEXT)
    || clrWindow != GetSysColor(COLOR_WINDOW))
    {
    RECT rc = {nx, ny, nx + nWidth, ny + nHeight};

    if(hbmChecks) DeleteObject(hbmChecks);

    nBitmapSize = nCheckSize;
    clrBtnFace = GetSysColor(COLOR_BTNFACE);
    clrBtnShadow = GetSysColor(COLOR_BTNSHADOW);
    clrBtnText = GetSysColor(COLOR_BTNTEXT);
    clrWindow = GetSysColor(COLOR_WINDOW);

    HDC hdcChecks = CreateCompatibleDC(hdc);
    HDC hdcMask = CreateCompatibleDC(hdc);
    HBITMAP hbmMask = CreateCompatibleBitmap(hdc, nCheckSize, nCheckSize);
    hbmChecks = CreateCompatibleBitmap(hdc, nCheckSize * 4, nCheckSize);
    hbmChecks = (HBITMAP)SelectObject(hdcChecks, hbmChecks);

    // Create a monochrome mask bitmap of the checkmark.
    //
    RECT rc2 = {0, -2, nCheckSize + nCheckSize / 4, nCheckSize + nCheckSize / 4};
    hbmMask = (HBITMAP)SelectObject(hdcMask, hbmMask);
    DrawFrameControl(hdcMask, &rc2, DFC_MENU, DFCS_MENUCHECK);

    for(int i = 0; i < 4; i++)
      {
      HBRUSH brush;
      HPEN   pen;

      // Background color of check box
      //
      brush = CreateSolidBrush( i & DRAWCHECK_GREYED ? clrBtnFace : clrWindow);
      brush = (HBRUSH)SelectObject(hdcChecks, brush);
      PatBlt(hdcChecks, i * nCheckSize, 0, nCheckSize, nCheckSize, PATCOPY);
      brush = (HBRUSH)SelectObject(hdcChecks, brush);
      DeleteObject(brush);

      // Checkmark
      //
      if(i & DRAWCHECK_CHECKED)
        {
        //brush = CreateSolidBrush(i & DRAWCHECK_GREYED ? clrBtnShadow : clrBtnText);
        brush = CreateSolidBrush(clrBtnText);
        brush = (HBRUSH)SelectObject(hdcChecks, brush);

        // 0x00B8074A = PSDPxax.  This draws the checkmark with a background equal
        // to the existing background, and a check the color of the current brush.
        //
        BitBlt(hdcChecks, i * nCheckSize, 0, nCheckSize, nCheckSize, hdcMask, 0, 0, 0x00B8074A);
        brush = (HBRUSH)SelectObject(hdcChecks, brush);
        DeleteObject(brush);
        }

      // Surrounding border
      //
      POINT border[] = { 
        {i * nCheckSize,           0}, 
        {(i + 1) * nCheckSize - 1, 0},
        {(i + 1) * nCheckSize - 1, nCheckSize - 1},
        {i * nCheckSize,           nCheckSize - 1},
        {i * nCheckSize,           0}
        };

      pen = CreatePen(PS_SOLID, 1, clrBtnShadow);
      pen = (HPEN)SelectObject(hdcChecks, pen);
      Polyline(hdcChecks, border, sizeof(border) / sizeof(*border));
      pen = (HPEN)SelectObject(hdcChecks, pen);
      DeleteObject(pen);
      }

    hbmChecks = (HBITMAP)SelectObject(hdcChecks, hbmChecks);
    hbmMask = (HBITMAP)SelectObject(hdcMask, hbmMask);
    DeleteObject(hbmMask);
    DeleteDC(hdcMask);
    DeleteDC(hdcChecks);
    }

  // Ok.  We have the bitmap.  Now draw!
  //
  HDC hdcMem = CreateCompatibleDC(hdc);
  hbmChecks = (HBITMAP)SelectObject(hdcMem, hbmChecks);
  BitBlt(hdc, nx + nWidthOffset, ny + nHeightOffset, nCheckSize, nCheckSize, 
         hdcMem, dwStyle * nCheckSize, 0, SRCCOPY);
  hbmChecks = (HBITMAP)SelectObject(hdcMem, hbmChecks);
  DeleteDC(hdcMem);
  }


//=----------------------------------------------------------------------=
// ListView_ExtendStyle
//=----------------------------------------------------------------------=
// Modifies the given listview in ways determined by the dwFlags parameter
// of PLV_EXTEND_STYLE.
//
// Returns:     HRESULT
//
HRESULT ListView_ExtendStyle
(
  HWND              hwndListView, // the listview hwnd
  DWORD             dwFlags       // new exciting style flags
)
  {
  // The list view should have a parent - we will need to subclass it
  //
  HWND hwndParent = GetParent(hwndListView);
  if(!hwndParent)
    return E_UNEXPECTED;

  // If there is only one column in the listview, the listview's contents 
  // will be unstable during a call to the ListView_SortItems macro.
  // So, we add another invisible column here.
  //
  if(dwFlags & LVES_AUTOSORT)
    {
    HWND hwndHeader = ListView_GetHeader(hwndListView);
    if(1 == Header_GetItemCount(hwndHeader))
      {
      LV_COLUMN lc;
      lc.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
      lc.fmt = LVCFMT_LEFT;
      lc.cx = 0;
      lc.pszText = "";
      lc.iSubItem = 1;
      ListView_InsertColumn(hwndListView, 1, &lc);
      }
    }

  // handle the checked list view style
  //
  if(dwFlags & LVES_CHECKED)
    {
    COLORREF clrMask = RGB(0, 255, 0);

    cxBitmap = GetSystemMetrics(SM_CXSMICON);
    cyBitmap = GetSystemMetrics(SM_CYSMICON);
    // set up the image list stuff
    //
    HDC hdc = GetDC(NULL);
    HDC hdcMem = CreateCompatibleDC(hdc);
    HBITMAP hbmp = CreateCompatibleBitmap(hdc, 2 * cxBitmap, cyBitmap);
    ReleaseDC(NULL, hdc);

    BITMAP bmp;
    RECT rc = {0, 0, 2 * cxBitmap, cyBitmap};

    GetObject(hbmp, sizeof(BITMAP), (PVOID)&bmp);
    HIMAGELIST himgStates = ImageList_CreateAPI(cxBitmap, cyBitmap, ILC_MASK | bmp.bmBitsPixel, 0, 1);
    if(!himgStates)
      return E_OUTOFMEMORY;

    HBRUSH hbr = CreateSolidBrush(clrMask);
    hbmp = (HBITMAP)SelectObject(hdcMem, hbmp);
    FillRect(hdcMem, &rc, hbr);
    DeleteObject(hbr);

    int cxOffset = (cxBitmap - DRAWCHECK_WIDTH) / 2;
    int cyOffset = (cyBitmap - DRAWCHECK_HEIGHT) / 2;

    DrawCheck(hdcMem, cxOffset, cyOffset, DRAWCHECK_WIDTH, DRAWCHECK_HEIGHT, DRAWCHECK_NORMAL);
    DrawCheck(hdcMem, cxOffset + cxBitmap, cyOffset, DRAWCHECK_WIDTH, DRAWCHECK_HEIGHT, DRAWCHECK_CHECKED);

    hbmp = (HBITMAP)SelectObject(hdcMem, hbmp);

    ImageList_AddMaskedAPI(himgStates, hbmp, clrMask);
    ListView_SetImageList(hwndListView, himgStates, LVSIL_STATE);

    DeleteDC(hdcMem);
    DeleteObject(hbmp);
    }

  // and the full line style. 
  if(dwFlags & LVES_FULLROW)
    {
    DWORD dwExStyle = ListView_GetExtendedListViewStyle(hwndListView);
    dwExStyle |= LVS_EX_FULLROWSELECT;

    ListView_SetExtendedListViewStyle(hwndListView, dwExStyle);
    }

  PSTYLEDATA pdata = (PSTYLEDATA)VSAlloc(sizeof(STYLEDATA));
  if(!pdata)
    {
    HIMAGELIST himgStates = ListView_GetImageList(hwndListView, LVSIL_STATE);
    ListView_SetImageList(hwndListView, NULL, LVSIL_STATE);
    ImageList_DestroyAPI(himgStates);

    return E_OUTOFMEMORY;
    }

  // Now, subclass the listview so we can respond to it's events.  We actually
  // subclass the listview's parent, as that's where all the groovy notifications
  // are.  Because of this, and the fact that there may be multiple listviews for
  // a given parent window, we must be a little sneaky here.
  //
  PSUBCLASSDATA pSub = (PSUBCLASSDATA)GetProp(hwndParent, _szDataProp);
  if(!pSub)
    {
    pSub = (PSUBCLASSDATA)VSAlloc(sizeof(SUBCLASSDATA));
    if(!pSub)
      {
      HIMAGELIST himgStates = ListView_GetImageList(hwndListView, LVSIL_STATE);
      ListView_SetImageList(hwndListView, NULL, LVSIL_STATE);
      ImageList_DestroyAPI(himgStates);

      VSFree(pdata);

      return E_OUTOFMEMORY;
      }
    pSub->pStyles = NULL;
    pSub->pfnOldParentProc = (WNDPROC)GetWindowLongPtr(hwndParent, GWLP_WNDPROC);

    SetProp(hwndParent, _szDataProp, (HANDLE)pSub);
    SetWindowLongPtr(hwndParent, GWLP_WNDPROC, (INT_PTR)_ListViewParentProc);
    }

  pdata->idcListView = GetWindowLong(hwndListView, GWL_ID);
  pdata->hwndHeader = GetWindow(hwndListView, GW_CHILD);
  pdata->dwFlags = dwFlags;
  pdata->pNext = pSub->pStyles;
  pdata->fHeader = FALSE;
  pdata->hdr.pszText = pdata->szHdrText;
  pdata->pfnOldListViewProc = (WNDPROC)GetWindowLongPtr(hwndListView, GWLP_WNDPROC);
  SetProp(hwndListView, _szDataProp, (HANDLE)pdata);
  SetWindowLongPtr(hwndListView, GWLP_WNDPROC, (INT_PTR)_ListViewProc);
  pSub->pStyles = pdata;
  _ConfigureListViewHeader(hwndListView, pdata);

  pdata->dwSort   = GetWindowLong(hwndListView, GWL_STYLE) & (LVS_SORTASCENDING | LVS_SORTDESCENDING);
  pdata->nLastCol = pdata->dwSort ? 0 : -2;
  
  return S_OK;
  }


//=----------------------------------------------------------------------=
// ListView_IsItemChecked
//=----------------------------------------------------------------------=
// Is the given item checked?
//
BOOL ListView_IsItemChecked
(
  HWND  hwndListView, 
  int   nItem
)
  {
  return (LV_CHECKED == ListView_GetItemState(hwndListView, nItem, LVIS_STATEIMAGEMASK));
  }


//=----------------------------------------------------------------------=
// ListView_CheckItem
//=----------------------------------------------------------------------=
// Checks / unchecks the given item
//
void ListView_CheckItem
(
  HWND hwndListView,
  int  nItem,
  BOOL fChecked
)
  {
  ListView_SetItemState(hwndListView, nItem, (fChecked ? LV_CHECKED : LV_UNCHECKED), 
                        LVIS_STATEIMAGEMASK);
  }


//=----------------------------------------------------------------------=
// ListView_InsertCheckItem
//=----------------------------------------------------------------------=
// Adds a checkable item to the list view.  You should use this INSTEAD
// of ListView_InsertItem for checked list views.
//
int ListView_InsertCheckItem
(
  HWND     hwndListView,
  LV_ITEM *pli,
  BOOL     fChecked
)
  {
  if(!(pli->mask & LVIF_STATE))
    {
    pli->state = 0;
    pli->stateMask = 0;
    }

  pli->state &= ~LVIS_STATEIMAGEMASK;
  pli->state |= (fChecked ? LV_CHECKED : LV_UNCHECKED);
  pli->stateMask |= LVIS_STATEIMAGEMASK;
  pli->mask |= LVIF_STATE;

#if DEBUG
  PSTYLEDATA pdata = (PSTYLEDATA)GetProp(hwndListView, _szDataProp);
  if(pdata && (pdata->dwFlags & LVES_AUTOSORT))
    {
    LV_FINDINFO lf;
    lf.flags = LVFI_PARAM;
    lf.lParam = pli->lParam;
    int iItem = ListView_FindItem(hwndListView, -1, &lf);
    VSASSERT(iItem == -1, "Duplicate lParam entry in autosorted list view");
    }
#endif // DEBUG

  return ListView_InsertItem(hwndListView, pli);
  }
#define ListView_InsertItemW(hwnd, pitem)   \
    (int)SNDMSG((hwnd), LVM_INSERTITEMW, 0, (LPARAM)(const LV_ITEMW FAR*)(pitem))
int ListView_InsertCheckItemW
(
  HWND     hwndListView,
  LV_ITEMW *pli,
  BOOL     fChecked
)
  {
  if(!(pli->mask & LVIF_STATE))
    {
    pli->state = 0;
    pli->stateMask = 0;
    }

  pli->state &= ~LVIS_STATEIMAGEMASK;
  pli->state |= (fChecked ? LV_CHECKED : LV_UNCHECKED);
  pli->stateMask |= LVIS_STATEIMAGEMASK;
  pli->mask |= LVIF_STATE;

#if DEBUG
  PSTYLEDATA pdata = (PSTYLEDATA)GetProp(hwndListView, _szDataProp);
  if(pdata && (pdata->dwFlags & LVES_AUTOSORT))
    {
    LV_FINDINFO lf;
    lf.flags = LVFI_PARAM;
    lf.lParam = pli->lParam;
    int iItem = ListView_FindItem(hwndListView, -1, &lf);
    VSASSERT(iItem == -1, "Duplicate lParam entry in autosorted list view");
    }
#endif // DEBUG

  return ListView_InsertItemW(hwndListView, pli);
  }


//
//
// Private functions
//
//


//=----------------------------------------------------------------------=
// _ConfigureListViewHeader
//=----------------------------------------------------------------------=
// Gets the list view header control and configures it so the first item
// is owner draw.  We need this so we can draw the checkmark click region
// on it.  This will get called when the control is initially setup and 
// again when a user inserts or removes a column.
//
void _ConfigureListViewHeader
(
  HWND        hwndListView,
  PSTYLEDATA  pdata
)
  {
  HD_ITEM hdrNew;

  if(0 == Header_GetItemCount(pdata->hwndHeader))
    return;

  pdata->hdr.cchTextMax = sizeof(pdata->szHdrText) / sizeof(*pdata->szHdrText);
  pdata->hdr.mask = HDI_BITMAP | HDI_FORMAT | HDI_HEIGHT | HDI_LPARAM | HDI_TEXT | HDI_WIDTH;

  if(!Header_GetItem(pdata->hwndHeader, 0, &pdata->hdr))
    return;

  // We don't even try with owner draw and bitmaps
  if(!(pdata->hdr.fmt & HDF_STRING))
    return;

  hdrNew = pdata->hdr;
  hdrNew.fmt &= ~HDF_STRING;
  hdrNew.fmt |= HDF_OWNERDRAW;

  if(!Header_SetItem(pdata->hwndHeader, 0, &hdrNew))
    return;

  pdata->fHeader = TRUE;
  }


//=----------------------------------------------------------------------=
// _DrawHeaderItem
//=----------------------------------------------------------------------=
// Draws the header item for the checked column
//
void _DrawHeaderItem
(
  PSTYLEDATA  pData,
  WPARAM      uState
)
  {
  RECT  rc;
  HDC   hdc;
  DWORD dwAlign;
  DWORD dwState;
  BOOL  fButtons;

  hdc = GetDC(pData->hwndHeader);

  rc.left = pData->rcItem.left;
  rc.top  = pData->rcItem.top;
  rc.right = cxBitmap + 4;
  rc.bottom = pData->rcItem.bottom;

  dwState = DFCS_ADJUSTRECT | DFCS_BUTTONPUSH;
  fButtons = (GetWindowLong(pData->hwndHeader, GWL_STYLE) & HDS_BUTTONS) != 0;

  if(!fButtons)
    dwState |= DFCS_FLAT;

  RECT rcTemp = rc;
  DrawFrameControl(hdc, &rcTemp, DFC_BUTTON, 
    dwState | (uState == STATE_LEFT ? DFCS_PUSHED | DFCS_FLAT : 0));

  InflateRect(&rcTemp, -2, -2);

  if(uState == STATE_LEFT)
    {
    OffsetRect(&rcTemp, 1, 1);
    }

  if(fButtons)
    {
    int offset = (rcTemp.right - rcTemp.left - (rcTemp.bottom - rcTemp.top)) / 2;
    DrawCheck(hdc, rcTemp.left + offset, rcTemp.top, rcTemp.right - rcTemp.left, 
              rcTemp.bottom - rcTemp.top, DRAWCHECK_INDETERMINATE);
    }

  rc.left = rc.right;
  rc.right = pData->rcItem.right;


  if(uState == STATE_RIGHT)
    dwState |= DFCS_PUSHED | DFCS_FLAT;

  DrawFrameControl(hdc, &rc, DFC_BUTTON, dwState);

  if(pData->hdr.fmt & HDF_CENTER)
    dwAlign = DT_CENTER;
  else if (pData->hdr.fmt & HDF_RIGHT)
    dwAlign = DT_RIGHT;
  else
    dwAlign = DT_LEFT;

  if(uState == STATE_RIGHT)
    {
    OffsetRect(&rc, 1, 1);
    }

  rc.left += 5;
  SelectObject(hdc, (HFONT)SendMessage(pData->hwndHeader, WM_GETFONT, 0, 0));
  SetTextColor(hdc, GetSysColor(COLOR_BTNTEXT));
  SetBkMode(hdc, TRANSPARENT);
  DrawTextEx(hdc, pData->hdr.pszText, -1, &rc, DT_BOTTOM | DT_SINGLELINE | DT_END_ELLIPSIS | dwAlign, NULL);

  ReleaseDC(pData->hwndHeader, hdc);
  }


//=----------------------------------------------------------------------=
// _FindListViewItem
//=----------------------------------------------------------------------=
// Returns the item ID associated with the given lparam.
//
int _FindListViewItem
(
  HWND   hwndListView,
  LPARAM lparam
)
  {
  LV_FINDINFO lf;
  lf.flags = LVFI_PARAM;
  lf.lParam = lparam;
  return ListView_FindItem(hwndListView, -1, &lf);
  }


//=----------------------------------------------------------------------=
// _ResetListViewHeader
//=----------------------------------------------------------------------=
// Gets the list view header control and removes any style we've previously
// set.  We do this so if a user adds columns we can propagate the owner
// draw stuff transparently.
//
void _ResetListViewHeader
(
  HWND        hwndListView,
  PSTYLEDATA  pdata
)
  {
  if(!pdata->fHeader)
    return;

  HWND hwndHeader = GetWindow(hwndListView, GW_CHILD);
  Header_SetItem(pdata->hwndHeader, 0, &pdata->hdr);
  pdata->fHeader = FALSE;
  }


//=----------------------------------------------------------------------=
// _CheckListViewCompare
//=----------------------------------------------------------------------=
// Does comparison sorting based on the check of the list view
//
int CALLBACK _CheckListViewCompare
(
  LPARAM l1,    // lparam of first item to compare
  LPARAM l2,    // lparam of second item to compare
  LPARAM lParam // user defined lparam.  Here, it is a pointer to a 
                // COMPAREDATA struct
)
  {
  LV_ITEM       lv;
  int           nCheck1, nCheck2;
  PCOMPAREDATA  pcmp = (PCOMPAREDATA)lParam;

  nCheck1 = nCheck2 = 0;

  // Setup our struct
  //
  lv.mask = LVIF_STATE;
  lv.stateMask = LVIS_STATEIMAGEMASK;
  lv.iSubItem = 0;

  // Get the stuff for the first item.
  //
  lv.iItem = _FindListViewItem(pcmp->hwndListView, l1);
  if(lv.iItem != -1)
    {
    ListView_GetItem(pcmp->hwndListView, &lv);
    nCheck1 = ((lv.state & LV_CHECKED) == LV_CHECKED);
    }

  // And now the second item
  //
  lv.iItem = _FindListViewItem(pcmp->hwndListView, l2);
  if(lv.iItem != -1)
    {
    ListView_GetItem(pcmp->hwndListView, &lv);
    nCheck2 = ((lv.state & LV_CHECKED) == LV_CHECKED);
    }

  // Finally, return the comparison between the two
  //
  int iCmp = nCheck2 - nCheck1;

  return (pcmp->dwSort == LVS_SORTASCENDING) ? iCmp : iCmp * -1;
  }


//=----------------------------------------------------------------------=
// _GenericListViewCompare
//=----------------------------------------------------------------------=
// Does a simple text based comparison of list view items
//
int CALLBACK _GenericListViewCompare
(
  LPARAM l1,    // lparam of first item to compare
  LPARAM l2,    // lparam of second item to compare
  LPARAM lParam // user defined lparam.  Here, it is a pointer to a 
                // COMPAREDATA struct
)
  {
  // First step - get the column text for the items we're interested in.  I'm
  // only sorting on the first 50 chars for speed, which should be more than
  // sufficient for most cases.
  //
  const size_t  sizeItem = 50;
  TCHAR         szItem1[sizeItem];
  TCHAR         szItem2[sizeItem];
  LV_ITEM       lv;
  PCOMPAREDATA  pcmp = (PCOMPAREDATA)lParam;

  // If, for some reason, we fail, we will default to comparing two
  // empty strings and we won't move the items.
  //
  *szItem1 = *szItem2 = '\0';

  // Setup our struct
  //
  lv.mask = LVIF_TEXT;
  lv.stateMask = 0;
  lv.iSubItem = pcmp->nCol;

  // Get the stuff for the first item.
  //
  lv.iItem = _FindListViewItem(pcmp->hwndListView, l1);
  if(lv.iItem != -1)
    {
    lv.pszText = szItem1;
    lv.cchTextMax = sizeItem;
    ListView_GetItem(pcmp->hwndListView, &lv);
    }

  // And now the second item
  //
  lv.iItem = _FindListViewItem(pcmp->hwndListView, l2);
  if(lv.iItem != -1)
    {
    lv.pszText = szItem2;
    lv.cchTextMax = sizeItem;
    ListView_GetItem(pcmp->hwndListView, &lv);
    }

  // Finally, return the comparison between the two
  //
  int iCmp = lstrcmpi(szItem1, szItem2);

  return (pcmp->dwSort == LVS_SORTASCENDING) ? iCmp : iCmp * -1;
  }


//=----------------------------------------------------------------------=
// _ListViewParentProc
//=----------------------------------------------------------------------=
// Subclass for the list view's parent to get it to handle checking / unchecking
//
LRESULT CALLBACK _ListViewParentProc
(
  HWND   hwnd, 
  UINT   msg, 
  WPARAM wp, 
  LPARAM lp
)
  {
  PSUBCLASSDATA pSub = (PSUBCLASSDATA)GetProp(hwnd, _szDataProp);

  // shouldn't happen, but the consequences of it are severe
  //
  if(!pSub) return DefWindowProc(hwnd, msg, wp, lp);

  switch(msg)
    {
    case WM_DESTROY:
      {
      // we're done.  Unhook the subclass and destroy the property data
      //
      SetWindowLongPtr(hwnd, GWLP_WNDPROC, (INT_PTR)pSub->pfnOldParentProc);
      RemoveProp(hwnd, _szDataProp);
      LRESULT lResult = CallWindowProc((WNDPROC)pSub->pfnOldParentProc, hwnd, msg, wp, lp);
      VSFree(pSub);
      return lResult;
      }
      break;

    case WM_NOTIFY:
      {
      // Respond to the proper control
      //
      for(PSTYLEDATA pdata = pSub->pStyles; pdata; pdata = pdata->pNext)
        {
        if(pdata->idcListView == (LONG)wp)
          {
          NMHDR *pn = (NMHDR *)lp;
          HWND   hwndListView = GetDlgItem(hwnd, pdata->idcListView);

          switch(pn->code)
            {
            case LVN_KEYDOWN:
              if(pdata->dwFlags & LVES_CHECKED)
                _OnKeyDown(hwndListView, ((LV_KEYDOWN *)lp)->wVKey);
              break;

            case LVN_COLUMNCLICK:
              {
              NM_LISTVIEW *pnmv = (NM_LISTVIEW *)pn;
              COMPAREDATA  cmp;

              cmp.hwndListView = hwndListView;
              cmp.nCol	 = pnmv->iSubItem;

              if(cmp.nCol == 0)
                {
                POINT pt;
                GetCursorPos(&pt);
                ScreenToClient(pdata->hwndHeader, &pt);
                if(pt.x <= cxBitmap + 4)
                  cmp.nCol = -1;
                }

              if((pdata->dwFlags & LVES_AUTOSORT) || -1 == cmp.nCol)
                {
		if (pdata->nLastCol == cmp.nCol)
		  {
		  // Sorting on same column as last time sorted, so toggle sort mode
		  pdata->dwSort = (pdata->dwSort == LVS_SORTASCENDING) ? LVS_SORTDESCENDING :
									 LVS_SORTASCENDING;
		  }
		else
		  {
		  // Sorting on different column than last, so always sort ascending
		  // in this case
		  pdata->dwSort   = LVS_SORTASCENDING;
		  pdata->nLastCol = cmp.nCol;
		  }

		cmp.dwSort = pdata->dwSort;
                if(-1 == cmp.nCol)
                  ListView_SortItems(hwndListView, _CheckListViewCompare, (LPARAM)&cmp);
                else
                  ListView_SortItems(hwndListView, _GenericListViewCompare, (LPARAM)&cmp);
                return 0; // we've responded, so don't forward it to the parent
                }
              }
              break;

            case NM_DBLCLK:
              if(pdata->dwFlags & LVES_CHECKED)
                _OnDblClk(hwndListView);
              break;

            case NM_CLICK:
              if(pdata->dwFlags & LVES_CHECKED)
                _OnClick(hwndListView);
              break;
            }
          break; // get out of the "for" since we've found the ctl
          }
        }
      }
      break;
    }

  // we're non-obtrusive, so we send ALL data back to the parent
  //
  return CallWindowProc((WNDPROC)pSub->pfnOldParentProc, hwnd, msg, wp, lp);
  }


//=----------------------------------------------------------------------=
// _ListViewProc
//=----------------------------------------------------------------------=
// Subclass for the list view itself so we can trap column adds/delets
//
LRESULT CALLBACK _ListViewProc
(
  HWND   hwnd, 
  UINT   msg, 
  WPARAM wp, 
  LPARAM lp
)
  {
  PSTYLEDATA pdata = (PSTYLEDATA)GetProp(hwnd, _szDataProp);
  LRESULT       lResult;

  // shouldn't happen, but the consequences of it are severe
  //
  if(!pdata) return DefWindowProc(hwnd, msg, wp, lp);

  switch(msg)
    {
    case WM_DESTROY:
      // we're done.  Unhook the subclass
      //
      SetWindowLongPtr(hwnd, GWLP_WNDPROC, (INT_PTR)pdata->pfnOldListViewProc);
      lResult = CallWindowProc((WNDPROC)pdata->pfnOldListViewProc, hwnd, msg, wp, lp);
      if(pdata->dwFlags & LVES_CHECKED)
        {
        HIMAGELIST himg = ListView_GetImageList(hwnd, LVSIL_STATE);
        ListView_SetImageList(hwnd, NULL, LVSIL_STATE);
        ImageList_DestroyAPI(himg);
        }
      VSFree(pdata);
      return lResult;

    case LVM_INSERTCOLUMN:
    case LVM_DELETECOLUMN:
    case LVM_SETCOLUMN:
      if(pdata->dwFlags & LVES_CHECKED && (0 == wp || 0 == Header_GetItemCount(pdata->hwndHeader)))
        {
        _ResetListViewHeader(hwnd, pdata);
        lResult = CallWindowProc((WNDPROC)pdata->pfnOldListViewProc, hwnd, msg, wp, lp);
        _ConfigureListViewHeader(hwnd, pdata);
        return lResult;
        }
      break;

    case WM_DRAWITEM:
      {
      LPDRAWITEMSTRUCT pdis = (LPDRAWITEMSTRUCT)lp;
      if(pdata->dwFlags & LVES_CHECKED && ODT_HEADER == pdis->CtlType && 0 == pdis->itemID && pdata->fHeader)
        {
        POINT pt;
        UINT  uState = STATE_NONE;
        GetCursorPos(&pt);
        ScreenToClient(pdata->hwndHeader, &pt);
        pdata->rcItem = pdis->rcItem;
        if(pdis->itemState == ODS_SELECTED)
          uState = (pt.x <= cxBitmap ? STATE_LEFT : STATE_RIGHT);
        PostMessage(hwnd, WM_REDRAWFRAME, (WPARAM)uState, 0);
        return TRUE;
        }
      }
      break;

    case WM_REDRAWFRAME:
      {
      _DrawHeaderItem(pdata, wp);
      return 0;
      }
    }

  // we're non-obtrusive, so we send ALL data back to the list view
  //
  return CallWindowProc((WNDPROC)pdata->pfnOldListViewProc, hwnd, msg, wp, lp);
  }


//=----------------------------------------------------------------------=
// _OnClick
//=----------------------------------------------------------------------=
// Handles clicking on the state image for the list view - this checks and
// unchecks the image
//
void _OnClick
(
  HWND hwndListView
)
  {
  LV_HITTESTINFO  lh;

  GetCursorPos(&lh.pt);
  ScreenToClient(hwndListView, &lh.pt);

  if(-1 == ListView_HitTest(hwndListView, &lh) || lh.flags != LVHT_ONITEMSTATEICON)
    return; // no click on the state icon

  _ToggleState(hwndListView, lh.iItem);
  }


//=----------------------------------------------------------------------=
// _OnDblClk
//=----------------------------------------------------------------------=
// Handles double clicking the list -- this toggles the check on 
// the active control
//
void _OnDblClk
(
  HWND hwndListView
)
  {
  LV_HITTESTINFO  lh;
  int             nItem = ListView_GetNextItem(hwndListView, -1, LVNI_FOCUSED | LVNI_SELECTED);

  if(-1 == nItem)
    return; // user didn't click on an element

  GetCursorPos(&lh.pt);
  ScreenToClient(hwndListView, &lh.pt);

  if(-1 == ListView_HitTest(hwndListView, &lh) || lh.flags == LVHT_ONITEMSTATEICON)
    return; // ignore double clicks on state icons

  _ToggleState(hwndListView, nItem);
  }


//=----------------------------------------------------------------------=
// _OnKeyDown
//=----------------------------------------------------------------------=
// Called when someone hit a key while the focus was on the list.
// The only keys we care about are those that could effect the checkboxes
//
void _OnKeyDown
(
  HWND hwndListView,
  WORD wVirtKey
)
  {
  if(wVirtKey != VK_SPACE)
    return; // don't care

  int  nItem = ListView_GetNextItem(hwndListView, -1, LVNI_FOCUSED);

  if(-1 == nItem)
    return; // nobody has focus, we don't want to change

  _ToggleState(hwndListView, nItem);
  }

//=----------------------------------------------------------------------=
// _ToggleState
//=----------------------------------------------------------------------=
// This is the worker for OnKeyDown, OnClick and OnDblClick
//
void _ToggleState
(
  HWND hwndListView,  // hwnd of list view to change
  int  nItem          // nItem of item whose state will change.  We will
                      // change all selected items to the inverse of this
                      // item's state.
)
  {
  // Determine a target state for all selected items based on the inverse of the
  // state of the guy with keyboard focus
  //
  int nState = ListView_GetItemState(hwndListView, nItem, LVIS_STATEIMAGEMASK);
  nState = (nState == LV_CHECKED ? LV_UNCHECKED : LV_CHECKED);

  // Is the current item selected?  If so, then go ahead and change the state
  // of all selected items.  Otherwise, only change the current one
  //
  if(LVIS_SELECTED == ListView_GetItemState(hwndListView, nItem, LVIS_SELECTED))
    {
    // Touch all selected items
    //
    nItem = -1;
    while(-1 != (nItem = ListView_GetNextItem(hwndListView, nItem, LVNI_SELECTED)))
      ListView_SetItemState(hwndListView, nItem, nState, LVIS_STATEIMAGEMASK);
    }
  else
    {
    // Only touch this item
    //
    ListView_SetItemState(hwndListView, nItem, nState, LVIS_STATEIMAGEMASK);
    }
  }
