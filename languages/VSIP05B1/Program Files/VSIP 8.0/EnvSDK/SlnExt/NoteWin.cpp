
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// NoteWin.cpp :  Implementation of CNoteToolWindow
//

#include "stdafx.h"
#include "PrjInc.h"
#include "notewin.h"
#include "slnnote.h"
#include "richedit.h"
#include "commctrl.h"


BOOL CNoteToolWindow::m_bFirstInit = FALSE;
TCHAR CNoteToolWindow::m_szClassName[] = _T("NoteToolWin");
/////////////////////////////////////////////////////////////////////////////////////////////
// CNoteToolWindow

CNoteToolWindow::CNoteToolWindow()
{
    ATLTRACE(_T("Creating CNoteToolWindow: 0x%X\n"), this);

    m_fZombie = FALSE;
    m_fCmdEnabled = FALSE;

    m_hwndParent = NULL;
    m_hwndMain = NULL;
    m_hwndList = NULL;
    m_hwndEdit = NULL;

    if (!m_bFirstInit)
        m_bFirstInit = RegisterWindowClass();

    InitCommonControls();
}

CNoteToolWindow::~CNoteToolWindow()
{
    ATLTRACE(_T("Destructing CNoteToolWindow: 0x%X\n"), this);
    
    //Kill off all of the notes
    DestroyNotes();
}

HRESULT CNoteToolWindow::Close()
{
    CComPtr<IVsSolution> srpSolution;
    m_fZombie = TRUE;
    
    DestroyNotes();
    
    //unadvise the events
    m_srpServiceProvider->QueryService(SID_SVsSolution, IID_IVsSolution, (LPVOID*)&srpSolution);
    srpSolution->UnadviseSolutionEvents(m_lEventsCookie);

    //release the pointers
    m_srpServiceProvider.Release();

    return NOERROR;
}

    
/////////////////////////////////////////////////////////////////////////////
// CNoteToolWindow IVsWindowPane Implementation

STDMETHODIMP CNoteToolWindow::SetSite(IServiceProvider* pSP)
{
    if (!pSP)
        return E_POINTER;
    CComPtr<IVsSolution> srpSolution;
    m_srpServiceProvider = pSP;

    m_srpServiceProvider->QueryService(SID_SVsSolution, IID_IVsSolution, (LPVOID*)&srpSolution);
    srpSolution->AdviseSolutionEvents((IVsSolutionEvents*)this, &m_lEventsCookie);
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::CreatePaneWindow(HWND hwndParent, int x, int y, int cx, int cy, HWND* phwnd)
{
    if (!phwnd)
        return E_POINTER;
    m_hwndParent = hwndParent;
    m_hwndMain = CreateWindowEx(0,                            // dwExStyle
                            m_szClassName,                    // lpszClassName
                            _T("Notes List Main"),             // lpszWindowName
                            WS_VISIBLE | WS_CHILD |
                            WS_CLIPSIBLINGS |
                            WS_CLIPCHILDREN,              // dwStyle
                            x, y, cx, cy,                 // x, y, nWidth, nHeight
                            hwndParent,                   // hWndParent
                            NULL,                          // hMenu
                            _AtlBaseModule.GetModuleInstance(),  // hInstance
                            this); 
    m_hwndList = CreateWindowEx(0,                            // dwExStyle
                            WC_LISTVIEW,                    // lpszClassName
                            _T("Notes List"),             // lpszWindowName
                            WS_VISIBLE | WS_CHILD |
                            WS_CLIPCHILDREN |
                            LVS_REPORT | 
                            LVS_SINGLESEL | 
                            LVS_EDITLABELS |
                            LVS_SHOWSELALWAYS,                // dwStyle
                            x, y, cx, cy,                 // x, y, nWidth, nHeight
                            m_hwndMain,                   // hWndParent
                            NULL,                          // hMenu
                            _AtlBaseModule.GetModuleInstance(),  // hInstance
                            0);

    InitListViewImageList();
    InitListViewColumns();

    *phwnd = m_hwndMain;
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::GetDefaultSize(SIZE* psize)
{
    if (!psize)
        return E_POINTER;
    psize->cx = 75;
    psize->cy = 100;
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::ClosePane()
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::LoadViewState(IStream* pstream)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::SaveViewState(IStream* pstream)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::TranslateAccelerator(LPMSG lpmsg)
{
    return S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CNoteToolWindow IVsBroadcastMessageEvents Implementation


STDMETHODIMP CNoteToolWindow::OnBroadcastMessage(UINT msg, WPARAM wparam, LPARAM lparam)
{
    return NOERROR;
}

/////////////////////////////////////////////////////////////////////////////
// CNoteToolWindow IOleCommandTarget Implementation

STDMETHODIMP CNoteToolWindow::QueryStatus(const GUID* pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT* pCmdText)
{
if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(cCmds == 1);
    _ASSERTE(prgCmds && pguidCmdGroup);

    if ((prgCmds == NULL) || (pguidCmdGroup == NULL))
        return E_INVALIDARG;

    DWORD cmdf;

    if (*pguidCmdGroup == guidSlnExtCtxCmdSet)
    {
        // The following bitwise flags control the state of a command:
        //        OLECMDF_SUPPORTED, OLECMDF_ENABLED, OLECMDF_LATCHED,
        //        OLECMDF_NINCHED, OLECMDF_INVISIBLE, OLECMDF_DEFHIDEONCTXTMENU
        //
        // Common cases are the following:
        //    1. Enable a command --  cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED
        //    2. Disable a command -- cmdf = OLECMDF_SUPPORTED
        //    3. Hide a command --    cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE
        cmdf = OLECMDF_SUPPORTED;

        switch (prgCmds[0].cmdID)
        {
        case icmdDeleteNote:
        case icmdRenameNote:
            {
                cmdf = OLECMDF_SUPPORTED | (m_fCmdEnabled ? OLECMDF_ENABLED : 0);
            }
            break;

            default:
                return OLECMDERR_E_NOTSUPPORTED;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    prgCmds[0].cmdf = cmdf;
    return S_OK;
}

STDMETHODIMP CNoteToolWindow::Exec(const GUID* pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANT* pvaIn, VARIANT* pvaOut)
{
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(pguidCmdGroup);

    if (pguidCmdGroup == NULL)
        return E_INVALIDARG;

    HRESULT hr = S_OK;

    if (*pguidCmdGroup == guidSlnExtCtxCmdSet)
    {
        // IOleCommandTargt::Exec should report errors that may occur
        // in the execution of a command. Therefore clear any existing
        // existing error info first
        _AtlModule.ClearErrorInfo();

        switch (nCmdID)
        {
            case icmdDeleteNote:
                DoDeleteNote(ListView_GetSelectionMark(m_hwndList));
                break;

            case icmdRenameNote:
                ListView_EditLabel(m_hwndList, ListView_GetSelectionMark(m_hwndList));
                break;

            default:
                return OLECMDERR_E_NOTSUPPORTED;
        }

        if (FAILED(hr))
        {
            _AtlModule.ReportErrorInfo(hr);
            hr = S_OK;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    return hr;
}

/////////////////////////////////////////////////////////////////////////////
// CNoteToolWindow ISelectionContainer Implementation

STDMETHODIMP CNoteToolWindow::CountObjects(DWORD dwFlags, ULONG* pc)
{
    if(!pc) return E_POINTER;

    switch(dwFlags)
    {
    case GETOBJS_SELECTED:
        {
            if(GetSelectedNote())
                *pc = 1;
            else
                *pc = 0;

            return NOERROR;
        }
    case GETOBJS_ALL:
        {
            UINT nCount = GetNoteCount();
            *pc = nCount;
            return NOERROR;
        }
    default:
        return E_UNEXPECTED;
    }
}

STDMETHODIMP CNoteToolWindow::GetObjects(DWORD dwFlags, ULONG uCount, IUnknown** apUnkObjects)
{
    if(!apUnkObjects) return E_POINTER;

    switch(dwFlags)
    {
    case GETOBJS_SELECTED:
        {
            CSlnNote* pNote = GetSelectedNote();;
            
            if(pNote)
                return pNote->QueryInterface(IID_ISolutionNote, (LPVOID*)apUnkObjects);
            else
                return E_UNEXPECTED;

        }
    case GETOBJS_ALL:
        {
#ifdef _DEBUG
            ULONG nCount = GetNoteCount(), curCount = 0;
            _ASSERTE( nCount == uCount || !_T("Counts don't match!"));
#endif

            HRESULT hr = NOERROR;
            ULONG i = 0, listCount = ListView_GetItemCount(m_hwndList);
            for(i; i < listCount; i++)
            {
                LVITEM lvi;
                lvi.mask = LVIF_PARAM;
                lvi.iItem = i;
                lvi.iSubItem = 0;

                ListView_GetItem(m_hwndList, &lvi);
                CSlnNote* pNote = (CSlnNote*)lvi.lParam;
                if(pNote)
                {
                    IfFailGo(pNote->QueryInterface(IID_ISolutionNote, (LPVOID*)&apUnkObjects[i]));
#ifdef _DEBUG
                    curCount++;
#endif
                }            
            }
#ifdef _DEBUG
            _ASSERTE( curCount == uCount || !_T("Counts don't match!"));
#endif

            return hr;

Error:        
            for(ULONG j = 0; j < i; j++)
            {
                apUnkObjects[j]->Release();
                apUnkObjects[j] = NULL;
            }

            return hr;
        }
    default:
        return E_UNEXPECTED;
    }
}

STDMETHODIMP CNoteToolWindow::SelectObjects(ULONG cCount, IUnknown** apUnkObjects, DWORD dwFlags)
{
    if(cCount != 1) return E_UNEXPECTED;

    if(!apUnkObjects) return E_POINTER;

    if(!(*apUnkObjects)) return E_UNEXPECTED;

    USES_CONVERSION;
    HRESULT hr = NOERROR;
    CComQIPtr<ISolutionNote> srpNote(*apUnkObjects);
    BSTR bstrName = NULL;

    if(SUCCEEDED(hr = srpNote->get_Name(&bstrName)))
    {
        LVFINDINFO lvfi;
        lvfi.flags = LVFI_STRING;
        lvfi.psz = OLE2T(bstrName);
        UINT nSel = ListView_FindItem(m_hwndList, -1, &lvfi);
        if(nSel == -1)
        {
            SysFreeString(bstrName);
            return E_UNEXPECTED;
        }
        
        ListView_SetSelectionMark(m_hwndList, nSel);
        ListView_SetItemState(m_hwndList, nSel, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED);
    }

    if(bstrName) SysFreeString(bstrName);
    return hr;
}

/////////////////////////////////////////////////////////////////////////////
// ISelectionContainer helper functions

CSlnNote* CNoteToolWindow::GetSelectedNote()
{
    UINT nSel = ListView_GetSelectionMark(m_hwndList);

    if(nSel == -1) return NULL;

    LVITEM lvi;
    lvi.mask = LVIF_PARAM;
    lvi.iItem = nSel;
    lvi.iSubItem = 0;
    
    ListView_GetItem(m_hwndList, &lvi);
    return (CSlnNote*)lvi.lParam;
}

ULONG CNoteToolWindow::GetNoteCount()
{
    // it is posible for their to be a list view item
    // without a note attached, when we are deleting
    // a note. So don't count those.

    ULONG accurate = 0, current = 0;

    current = ListView_GetItemCount(m_hwndList);

    for(ULONG i = 0; i < current; i++)
    {
        LVITEM lvi;
        lvi.mask = LVIF_PARAM;
        lvi.iItem = i;
        lvi.iSubItem = 0;
        
        ListView_GetItem(m_hwndList, &lvi);

        if(lvi.lParam) accurate++;
    }

    return accurate;
}

/////////////////////////////////////////////////////////////////////////////
// CNoteToolWindow WindowProcs and Message Handlers

BOOL CNoteToolWindow::RegisterWindowClass()
{
    ATLTRACE(_T("CNoteToolWindow::RegisterWindowClass\n"));

    WNDCLASS wc;

    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = (WNDPROC)StaticWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = EXTRABYTES;
    wc.hInstance = _AtlBaseModule.GetModuleInstance();
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = GetSysColorBrush(COLOR_WINDOW);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = m_szClassName;

    return RegisterClass(&wc);
}

void CNoteToolWindow::InitListViewImageList()
{
    HICON hicon;
    HIMAGELIST himlLarge;
    HIMAGELIST himlSmall;
    
    // Create the full-sized and small icon image lists. 
    himlLarge = ImageList_Create(GetSystemMetrics(SM_CXICON), 
        GetSystemMetrics(SM_CYICON), TRUE, 1, 1); 
    himlSmall = ImageList_Create(GetSystemMetrics(SM_CXSMICON), 
        GetSystemMetrics(SM_CYSMICON), TRUE, 1, 1);  
    // Add an icon to each image list. 
    if (hicon = LoadIcon(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDI_NOTE)))
    {
        ImageList_AddIcon(himlLarge, hicon); 
        ImageList_AddIcon(himlSmall, hicon);     
        DestroyIcon(hicon);
    }
    
    if (hicon = LoadIcon(_AtlBaseModule.GetResourceInstance(), MAKEINTRESOURCE(IDI_ISSUE)))
    {
        ImageList_AddIcon(himlLarge, hicon); 
        ImageList_AddIcon(himlSmall, hicon);     
        DestroyIcon(hicon);
    }
    
    // Assign the image lists to the list view control. 
    ListView_SetImageList(m_hwndList, himlLarge, LVSIL_NORMAL); 
    ListView_SetImageList(m_hwndList, himlSmall, LVSIL_SMALL); 

}

#define cColumns 3
void CNoteToolWindow::InitListViewColumns()
{
    TCHAR szTemp[256];     // temporary buffer
    LVCOLUMN lvc; 
    int iCol;
    
    // Initialize the LVCOLUMN structure. 
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 
    lvc.fmt = LVCFMT_LEFT;
    lvc.cx = 100;
    lvc.pszText = szTemp;

    // Add the columns
    for (iCol = 0; iCol < cColumns; iCol++)
    { 
        lvc.iSubItem = iCol; 
        LoadString(_AtlBaseModule.GetResourceInstance(), IDS_COLUMN1 + iCol, szTemp, countof(szTemp)); 
        ListView_InsertColumn(m_hwndList, iCol, &lvc);
        
    }
}

LRESULT CALLBACK CNoteToolWindow::StaticWndProc(HWND hwnd, UINT iMsg,
                                               WPARAM wParam, LPARAM lParam)
{
    CNoteToolWindow *pThis;

    if (iMsg == WM_CREATE)
    {
        pThis = (CNoteToolWindow*)((LPCREATESTRUCT)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, EB_THIS, (LONG_PTR)pThis);
        pThis->m_hwndMain = hwnd;
    }
    else
        pThis = (CNoteToolWindow*)GetWindowLongPtr(hwnd, EB_THIS);

    if (pThis)
        return pThis->WndProc(iMsg, wParam, lParam);
    else
        return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int CALLBACK CNoteToolWindow::ListCompare(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
    CSlnNote* pNote1 = (CSlnNote*)lParam1, *pNote2 = (CSlnNote*)lParam2;
    LVCOL col = (LVCOL)lParamSort;
    HRESULT hr = NOERROR;
    int ret = 0;

    CComBSTR bstrName1, bstrName2;
    VARIANT_BOOL bool1, bool2;

    IfFailGo(pNote1->get_Name(&bstrName1));
    IfFailGo(pNote2->get_Name(&bstrName2));

    if(bstrName1.Length() == 0 || bstrName2.Length() == 0) return E_UNEXPECTED;

    ret = _wcsicmp(bstrName1, bstrName2);
    if(col == lvName) return ret;
    else if(col == lvIssue)
    {
        IfFailGo(pNote1->get_IsIssue(&bool1));
        IfFailGo(pNote2->get_IsIssue(&bool2));

        return (bool1 == bool2) ? ret : (bool1) ? -1 : 1;
    }
    else
    {
        IfFailGo(pNote1->get_IsShared(&bool1));
        IfFailGo(pNote2->get_IsShared(&bool2));

        return (bool1 == bool2) ? ret : (bool1) ? -1 : 1;
    }

Error:
    return 0;

}

LRESULT CNoteToolWindow::WndProc(UINT iMsg, WPARAM wParam, LPARAM lParam)
{
   switch (iMsg)
    {
   case WM_SIZE:
       {
           OnSize(wParam, LOWORD(lParam), HIWORD(lParam));
           break;
       }            
   case WM_NOTIFY:
       {
           return OnNotify(lParam);
       }
       break;
    }
    return DefWindowProc(m_hwndMain, iMsg, wParam, lParam);
}

void CNoteToolWindow::OnSize(WPARAM, WORD wWidth, WORD wHeight)
{
    //Pass this onto the Listbox
     MoveWindow(m_hwndList, 0, 0, wWidth, wHeight, TRUE);
}

LRESULT CNoteToolWindow::OnNotify(LPARAM lp)
{
    switch(((LPNMHDR)lp)->code)
    {
    case LVN_ENDLABELEDIT:
        DoRenameNote(((NMLVDISPINFO*)lp)->item.pszText, ((NMLVDISPINFO*)lp)->item.iItem);
        break;
    case NM_RCLICK:
        DoSelectionChange();
        DoContextMenu(((LPNMITEMACTIVATE)lp)->ptAction);
        break;
    case LVN_COLUMNCLICK:
        DoSort(((LPNMLISTVIEW)lp)->iSubItem);
        break;
    case LVN_ITEMACTIVATE:
        DoShowNote(); //fall thtough to selection too.
    case LVN_ITEMCHANGED:
    case NM_CLICK:
        DoSelectionChange();
        break;
    default:
        break;
    }

    return 0;
}

LRESULT CNoteToolWindow::DoSelectionChange()
{
    CComPtr<ITrackSelection> srpTrackSelection;

    if(SUCCEEDED(m_srpServiceProvider->QueryService(SID_STrackSelection, IID_ITrackSelection, (LPVOID*)&srpTrackSelection)))
    {
        srpTrackSelection->OnSelectChange((ISelectionContainer*)this);
    }

    return 0;
}

LRESULT CNoteToolWindow::DoContextMenu(POINT pt)
{
    CComPtr<IVsUIShell> srpShell;

    POINTS    ptsTemp;
    m_fCmdEnabled = (GetIDFromCursor() != -1);

    // Convert to screen coords
    ClientToScreen(m_hwndList, &pt);
    POINTTOPOINTS(pt);
    ptsTemp.x = (SHORT) pt.x;
    ptsTemp.y = (SHORT) pt.y;
    
    if(SUCCEEDED(_AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (LPVOID*)&srpShell)))
    {
        srpShell->ShowContextMenu(0, guidSlnExtPkg, IDMX_SLNNOTE_CTX, ptsTemp, (IOleCommandTarget*)this);
    }

    return 0;
}

HRESULT CNoteToolWindow::DoDeleteNote(UINT idx)
{
    HRESULT hr = NOERROR;
    LVITEM lvi;
    lvi.mask = LVIF_PARAM;
    lvi.iItem = idx;
    lvi.iSubItem = 0;

    ListView_GetItem(m_hwndList, &lvi);
    CSlnNote* pNote = (CSlnNote*)lvi.lParam;
    IfFailGo(pNote->Close());
    pNote->Release();\
    lvi.lParam = NULL;
    ListView_SetItem(m_hwndList, &lvi);
    ListView_DeleteItem(m_hwndList,idx);

Error:
    return NOERROR;
}

HRESULT CNoteToolWindow::DoRenameNote(TCHAR* szNewName, UINT id)
{
    // Check whether a duplicate name is attempted
    LVFINDINFO lvfi;
    lvfi.flags = LVFI_STRING;
    lvfi.psz = szNewName;
    if (-1 != ListView_FindItem(m_hwndList, -1, &lvfi)) {
        ::MessageBox(NULL,_T("A note with this name already exists!"),_T("Can't Rename"), MB_OK);
        return NOERROR;
    }
    // Change the name
    USES_CONVERSION;
    LVITEM lvi;
    lvi.mask = LVIF_PARAM;
    lvi.iItem = id;
    lvi.iSubItem = 0;

    ListView_GetItem(m_hwndList, &lvi);
    CSlnNote* pNote = (CSlnNote*)lvi.lParam;
    CComBSTR cbstrNewName(szNewName);
    if ((szNewName != NULL) && (_tcslen(szNewName) != 0) && (cbstrNewName.Length() == 0))
        return E_OUTOFMEMORY;
    return pNote->put_Name(cbstrNewName);
}

HRESULT CNoteToolWindow::DestroyNotes()
{
    //Kill off all of the notes
    UINT nCount = ListView_GetItemCount(m_hwndList);
    for(UINT i = 0; i < nCount; i++)
    {
        DoDeleteNote(0);
    }
    return NOERROR;
}

HRESULT CNoteToolWindow::DoSort(UINT col)
{
    ListView_SortItems(m_hwndList, ListCompare, col);

    //now go through and reset the ids
    UINT nCount = ListView_GetItemCount(m_hwndList);
    for(UINT i = 0; i < nCount; i++)
    {
        LVITEM lvi;
        lvi.mask = LVIF_PARAM;
        lvi.iItem = i;
        lvi.iSubItem = 0;

        ListView_GetItem(m_hwndList, &lvi);

        ((CSlnNote*)lvi.lParam)->SetIdx(i);
    }

    return NOERROR;
}

HRESULT CNoteToolWindow::DoShowNote()
{
    LVITEM lvi;
    lvi.mask = LVIF_PARAM;
    lvi.iItem = ListView_GetSelectionMark(m_hwndList);
    lvi.iSubItem = 0;

    ListView_GetItem(m_hwndList, &lvi);

    return ((CSlnNote*)lvi.lParam)->put_Visible(VARIANT_TRUE);
}

UINT CNoteToolWindow::GetIDFromCursor()
{
    LVHITTESTINFO lvhti;
    
    GetCursorPos(&lvhti.pt);
    ScreenToClient(m_hwndList, &lvhti.pt);

    ListView_HitTest(m_hwndList, &lvhti);

    if((lvhti.flags & LVHT_ONITEM)) return lvhti.iItem;
    else return -1;
}

HRESULT CNoteToolWindow::SaveOpts(IStream* pstm)
{
    if (!pstm)
        return E_POINTER;
    HRESULT hr = NOERROR;
    UINT nCount = ListView_GetItemCount(m_hwndList), nRealCount = 0;
    ULONG writ;
    ULARGE_INTEGER uliSPOld, uliSPNew;
    LARGE_INTEGER li;
    UINT i = 0;
    memset(&li, 0, sizeof li);

    //first stash the current seek pointer
    IfFailGo(pstm->Seek(li, STREAM_SEEK_CUR, &uliSPOld));
    // now write the full count as a placeholder
    IfFailGo(pstm->Write(&nCount, sizeof nCount, &writ));
    for(i; i < nCount; i++)
    {
        LVITEM lvi;
        VARIANT_BOOL fIsShared = FALSE;
        lvi.mask = LVIF_PARAM;
        lvi.iItem = i;
        lvi.iSubItem = 0;

        ListView_GetItem(m_hwndList, &lvi);

        CSlnNote* pNote = (CSlnNote*)lvi.lParam;
        IfFailGo(pNote->get_IsShared(&fIsShared));
        if(fIsShared == VARIANT_FALSE)
        {
            IfFailGo(pNote->SaveOpts(pstm));
            IfFailGo(pNote->ClearModifiedFlag());
            nRealCount++;
        }
    }

    // now stash the current pointer
    IfFailGo(pstm->Seek(li, STREAM_SEEK_CUR, &uliSPNew));
    // now back up and write the real count
    li.LowPart = uliSPOld.LowPart;
    li.HighPart = uliSPOld.HighPart;
    IfFailGo(pstm->Seek(li, STREAM_SEEK_SET, NULL));
    IfFailGo(pstm->Write(&nRealCount, sizeof nRealCount, &writ));
    li.LowPart = uliSPNew.LowPart;
    li.HighPart = uliSPNew.HighPart;
    IfFailGo(pstm->Seek(li, STREAM_SEEK_SET, NULL));

Error:
    return hr;
}

HRESULT CNoteToolWindow::SaveProps(IPropertyBag* pProps)
{
    if (!pProps)
        return E_POINTER;
    HRESULT hr = NOERROR;
    CComVariant varCount;
    long nRealCount = 0;
    UINT nCount = ListView_GetItemCount(m_hwndList);
    for(UINT i = 0; i < nCount; i++)
    {
        LVITEM lvi;
        VARIANT_BOOL fIsShared = FALSE;
        lvi.mask = LVIF_PARAM;
        lvi.iItem = i;
        lvi.iSubItem = 0;

        ListView_GetItem(m_hwndList, &lvi);

        CSlnNote* pNote = (CSlnNote*)lvi.lParam;
        IfFailGo(pNote->get_IsShared(&fIsShared));
        if(fIsShared == VARIANT_TRUE)
        {
            IfFailGo(pNote->SaveProps(pProps, ++nRealCount));
            IfFailGo(pNote->ClearModifiedFlag());
        }
    }

    varCount = nRealCount;
    varCount.ChangeType(VT_BSTR);

    IfFailGo(pProps->Write(L"NumNotes", &varCount));

Error:
    return hr;
}

HRESULT CNoteToolWindow::LoadOpts(IStream* pstm)
{
    if (!pstm)
        return E_POINTER;
    HRESULT hr = NOERROR;
    UINT i = 0;
    UINT nCount = 0;
    ULONG read;
    // first read in the count of these guys
    IfFailGo(pstm->Read(&nCount, sizeof nCount, &read));

    for(i; i < nCount; i++)
    {
        CComObject<CSlnNote>* pNote;

        IfFailGo(CComObject<CSlnNote>::CreateInstance(&pNote));

        pNote->AddRef(); //hold a reference

        hr = pNote->LoadFromStream(this, pstm); // adds itself to listbox
        if ( FAILED(hr) )
        {
            pNote->Release();
            goto Error;
        }

    }

    IfFailGo(DoSort(0));

Error:
    return hr;
}

HRESULT CNoteToolWindow::LoadProps(LPCOLESTR szKey, IPropertyBag* pProps)
{
    if (!pProps)
        return E_POINTER;
    HRESULT hr = NOERROR;
    long i = 0;
    CComVariant varNum;

    if ( FAILED(pProps->Read(L"NumNotes", &varNum, NULL)) )
         return S_OK;
    IfFailGo(varNum.ChangeType(VT_I4));

    for(i; i < varNum.lVal; i++)
    {
        CComObject<CSlnNote>* pNote;

        IfFailGo(CComObject<CSlnNote>::CreateInstance(&pNote));
        IfFailGo(pNote->LoadFromPropBag(this, i + 1, pProps)); // adds itself to listbox

        pNote->AddRef(); //hold a reference
    }
    
    IfFailGo(DoSort(0));
Error:
    return hr;
}

HRESULT CNoteToolWindow::GetModified()
{
    // returns S_OK if any note is modified,
    // and S_FALSE if all are clean

    UINT nCount = ListView_GetItemCount(m_hwndList);
    for(UINT i = 0; i < nCount; i++)
    {
        LVITEM lvi;
        lvi.mask = LVIF_PARAM;
        lvi.iItem = i;
        lvi.iSubItem = 0;
        VARIANT_BOOL fMod = VARIANT_FALSE;

        ListView_GetItem(m_hwndList, &lvi);

        ((CSlnNote*)lvi.lParam)->get_Modified(&fMod);
        if(fMod == VARIANT_TRUE) return S_OK;
    }

    return S_FALSE;
}
/////////////////////////////////////////////////////////////////////////////
// CNoteToolWindow ISolutionNotes Implementation

STDMETHODIMP CNoteToolWindow::get_DTE(_DTE** ppDTE)
{
    return _AtlModule.QueryService(SID_SDTE, IID__DTE, (LPVOID*)ppDTE);
}

STDMETHODIMP CNoteToolWindow::get_Parent(_DTE** ppParent)
{
    return _AtlModule.QueryService(SID_SDTE, IID__DTE, (LPVOID*)ppParent);
}

STDMETHODIMP CNoteToolWindow::get_Count(long* pCount)
{
    if(!pCount) return E_POINTER;

    *pCount = (long)ListView_GetItemCount(m_hwndList);
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::get__NewEnum(IUnknown** ppEnum)
{
    if (!ppEnum) return E_POINTER;

    CEnumNotes* pNotes = new CEnumNotes(m_hwndList);
    if (!pNotes)
        return E_OUTOFMEMORY;
    return pNotes->QueryInterface(IID_IUnknown, (LPVOID*)ppEnum);
}

STDMETHODIMP CNoteToolWindow::Item(VARIANT varIndex, ISolutionNote** ppVal)
{
    if(!ppVal) return E_POINTER;

    VARIANT varFinal;
    VariantInit(&varFinal);
    if(SUCCEEDED(VariantChangeType(&varFinal, &varIndex, 0, VT_I4)))
    {
        LVITEM lvi;
        lvi.mask = LVIF_PARAM;
        lvi.iItem = varFinal.lVal - 1;
        lvi.iSubItem = 0;

        if(ListView_GetItem(m_hwndList, &lvi) == FALSE) return E_INVALIDARG;
        
        return ((CSlnNote*)lvi.lParam)->QueryInterface(IID_ISolutionNote, (LPVOID*)ppVal);
    }
    else if(varIndex.vt == VT_BSTR)
    {
        USES_CONVERSION;
        LVFINDINFO lvfi;
        lvfi.flags = LVFI_STRING;
        lvfi.psz = OLE2T(varIndex.bstrVal);
        ULONG idx = ListView_FindItem(m_hwndList, -1, &lvfi);
        if(idx == -1) return E_INVALIDARG;

        LVITEM lvi;
        lvi.mask = LVIF_PARAM;
        lvi.iItem = idx;
        lvi.iSubItem = 0;

        ListView_GetItem(m_hwndList, &lvi);
        CSlnNote* pNote = (CSlnNote*)lvi.lParam;
        return pNote->QueryInterface(IID_ISolutionNote, (LPVOID*)ppVal);
    }

    return E_INVALIDARG;
}

STDMETHODIMP CNoteToolWindow::Add(ISolutionNote** ppAdd)
{
    CComObject<CSlnNote>* pNote;
    HRESULT hr = NOERROR;

    if(FAILED(hr = CComObject<CSlnNote>::CreateInstance(&pNote)))
        return hr;

    if(FAILED(hr = pNote->Init(this))) //adds itself to the listbox
        return hr;

    pNote->AddRef(); //hold a reference

    // fire the event
    Fire_NoteAdded((ISolutionNote*)pNote);

    if(ppAdd)
        return pNote->QueryInterface(IID_ISolutionNote, (LPVOID*)ppAdd);

    return NOERROR;
}

/////////////////////////////////////////////////////////////////////////////
// CNoteToolWindow IVsSolutionEvents Implementation
STDMETHODIMP CNoteToolWindow::OnAfterOpenProject(IVsHierarchy*, BOOL)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::OnQueryCloseProject(IVsHierarchy*,BOOL, BOOL*)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::OnBeforeCloseProject(IVsHierarchy*, BOOL)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::OnAfterLoadProject(IVsHierarchy*, IVsHierarchy*)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::OnQueryUnloadProject(IVsHierarchy*, BOOL*)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::OnBeforeUnloadProject(IVsHierarchy*, IVsHierarchy*)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::OnAfterOpenSolution(IUnknown*, BOOL)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::OnQueryCloseSolution(IUnknown*, BOOL*)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::OnBeforeCloseSolution(IUnknown*)
{
    return NOERROR;
}

STDMETHODIMP CNoteToolWindow::OnAfterCloseSolution(IUnknown*)
{
    return DestroyNotes();
}
/////////////////////////////////////////////////////////////////////////////
// CEnumNotes

CEnumNotes::CEnumNotes(HWND hwndList)
{
    m_hwndList = hwndList;
    m_idxCur = 0;
    m_cRef = 0;
}

CEnumNotes::CEnumNotes(CEnumNotes* pCopy)
{
    m_hwndList = pCopy->m_hwndList;
    m_idxCur = pCopy->m_idxCur;
    m_cRef = 0;
}

/////////////////////////////////////////////////////////////////////////////
// CEnumNotes IUnknown Implementation

STDMETHODIMP CEnumNotes::QueryInterface(REFIID riid, LPVOID* ppvObj)
{
    if(!ppvObj) return E_POINTER;

    if( riid == IID_IUnknown )
        *ppvObj = (LPVOID)(LPUNKNOWN)this;
    else if( riid == IID_IEnumVARIANT )
        *ppvObj = (LPVOID)(LPENUMVARIANT)this;
    else
        return E_NOINTERFACE;

    AddRef();

    return NOERROR;
}

/////////////////////////////////////////////////////////////////////////////
// CEnumNotes IEnumVARIANT Implementation

STDMETHODIMP CEnumNotes::Next(ULONG celt, VARIANT* rgvar, ULONG* celtFetched)
{
    ULONG nFetched = 0;
    ULONG i = 0;

    for(i; i < celt; i++)
    {
        LVITEM lvi;
        lvi.mask = LVIF_PARAM;
        lvi.iItem = m_idxCur;
        lvi.iSubItem = 0;

        if(ListView_GetItem(m_hwndList, &lvi) != FALSE)
        {
            VariantInit(&rgvar[i]);
            V_VT(&rgvar[i]) = VT_DISPATCH;

            if(SUCCEEDED(((CSlnNote*)lvi.lParam)->QueryInterface(IID_ISolutionNote, (LPVOID*)&rgvar[i].pdispVal)))
            {
                nFetched++;
                m_idxCur++;
            }
            else
            {
                V_VT(&rgvar[i]) = VT_ERROR;
                break;
            }
        }
    }

    if(celtFetched) *celtFetched = nFetched;

    return celt == nFetched ? S_OK : S_FALSE;
}

STDMETHODIMP CEnumNotes::Skip(ULONG celt)
{
    ULONG nCount = ListView_GetItemCount(m_hwndList);
    m_idxCur = m_idxCur + celt >= nCount ?  nCount - 1 : m_idxCur + celt;
    return NOERROR;
}

STDMETHODIMP CEnumNotes::Reset()
{
    m_idxCur = 0;
    return NOERROR;
}

STDMETHODIMP CEnumNotes::Clone(IEnumVARIANT** ppenum)
{
    if (!ppenum) return E_POINTER;

    CEnumNotes* pNotes = new CEnumNotes(this);
    if (!pNotes) return E_OUTOFMEMORY;
    return pNotes->QueryInterface(IID_IEnumVARIANT, (LPVOID*)ppenum);
}
