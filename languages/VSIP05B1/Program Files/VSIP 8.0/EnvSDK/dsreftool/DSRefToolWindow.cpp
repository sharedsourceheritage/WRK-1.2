
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// DSRefToolWindow.cpp: implementation of the CDSRefToolWindow class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "DSRefToolWindow.h"
#include "dsrfid.h"
#include "resource.h"
#include "DSRefToolui\\resource.h"



BOOL CDSRefToolWindow::m_bFirstInit = FALSE;
TCHAR CDSRefToolWindow::m_szClassName[] = _T("DSRefToolWin");

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDSRefToolWindow::CDSRefToolWindow()
{
    m_fZombie = FALSE;
    m_hwndParent = NULL;
    m_hwndMain = NULL;
    m_hwndTree = NULL;
    m_hwndEdit = NULL;
    m_uClipFmt = RegisterClipboardFormat(szcfDSRef);

    if (!m_bFirstInit)
        m_bFirstInit = RegisterWindowClass();

    InitCommonControls();
}

CDSRefToolWindow::~CDSRefToolWindow()
{

}

STDMETHODIMP CDSRefToolWindow::SetSite(IServiceProvider* pSP)
{
    return NOERROR;
}

STDMETHODIMP CDSRefToolWindow::CreatePaneWindow(HWND hwndParent, int x, int y, int cx, int cy, HWND* phwnd)
{
    if (!phwnd)
        return E_POINTER;

    m_hwndParent = hwndParent;
    m_hwndMain = CreateWindowEx(0,                            // dwExStyle
                            m_szClassName,                    // lpszClassName
                            _T("DSRefWin Main"),             // lpszWindowName
                            WS_VISIBLE | WS_CHILD |
                            WS_CLIPSIBLINGS |
                            WS_CLIPCHILDREN,              // dwStyle
                            x, y, cx, cy,                 // x, y, nWidth, nHeight
                            hwndParent,                   // hWndParent
                            NULL,                         // hMenu
                            _AtlBaseModule.GetModuleInstance(),  // hInstance
                            this); 
    

    if(!m_hwndMain) return E_UNEXPECTED;

    RegisterDragDrop(m_hwndMain, (IDropTarget*)this);

    *phwnd = m_hwndMain;
    return NOERROR;
}

STDMETHODIMP CDSRefToolWindow::GetDefaultSize(SIZE* psize)
{
    if (!psize)
        return E_POINTER;

    psize->cx = 75;
    psize->cy = 100;
    return NOERROR;
}

STDMETHODIMP CDSRefToolWindow::ClosePane()
{
    RevokeDragDrop(m_hwndMain);
    m_srpCurrentDSRef.Release();
    return NOERROR;
}

STDMETHODIMP CDSRefToolWindow::LoadViewState(IStream* pstream)
{
    return NOERROR;
}

STDMETHODIMP CDSRefToolWindow::SaveViewState(IStream* pstream)
{
    return NOERROR;
}

STDMETHODIMP CDSRefToolWindow::TranslateAccelerator(LPMSG lpmsg)
{
    return S_FALSE;
}

STDMETHODIMP CDSRefToolWindow::DragEnter(IDataObject* pDataObj, DWORD grfKeyState, POINTL pt, DWORD* pdwEffect)
{
    _ASSERT(!m_srpCurrentDragee);

    if (!pDataObj)
        return E_POINTER;
    if (!pdwEffect)
        return E_POINTER;

    m_srpCurrentDragee = pDataObj;
    *pdwEffect = DROPEFFECT_NONE;

    // only accept simple drag
    if(grfKeyState != MK_LBUTTON)
    {
        return NOERROR;
    }

    // now see if it contains CF_DSREF
    FORMATETC fmtetc;
    // this just retrives the previously registered
    // custom format value
    fmtetc.cfFormat = m_uClipFmt;
    fmtetc.dwAspect = DVASPECT_CONTENT;
    fmtetc.lindex = -1;
    fmtetc.ptd = NULL;
    fmtetc.tymed = TYMED_HGLOBAL;

    if(SUCCEEDED(m_srpCurrentDragee->QueryGetData(&fmtetc)))
    {
        // it does, change drop effect
        *pdwEffect = DROPEFFECT_COPY;
    }

    return NOERROR;
}

STDMETHODIMP CDSRefToolWindow::DragOver(DWORD grfKeyState, POINTL pt, DWORD* pdwEffect)
{
    _ASSERT(m_srpCurrentDragee);

    if (!pdwEffect)
        return E_POINTER;

    *pdwEffect = DROPEFFECT_NONE;

    // only accept simple drag
    if(grfKeyState != MK_LBUTTON)
    {
        return NOERROR;
    }

    // now see if it contains CF_DSREF
    FORMATETC fmtetc;
    // this just retrives the previously registered
    // custom format value
    fmtetc.cfFormat = m_uClipFmt;
    fmtetc.dwAspect = DVASPECT_CONTENT;
    fmtetc.lindex = -1;
    fmtetc.ptd = NULL;
    fmtetc.tymed = TYMED_HGLOBAL;

    if(SUCCEEDED(m_srpCurrentDragee->QueryGetData(&fmtetc)))
    {
        // it does, change drop effect
        *pdwEffect = DROPEFFECT_COPY;
    }

    return NOERROR;
}

STDMETHODIMP CDSRefToolWindow::DragLeave()
{
    m_srpCurrentDragee.Release();
    return NOERROR;
}

STDMETHODIMP CDSRefToolWindow::Drop(IDataObject* pDataObj, DWORD grfKeyState, POINTL pt, DWORD* pdwEffect)
{
    _ASSERT(m_srpCurrentDragee);

    if (!pDataObj)
        return E_POINTER;
    if (!pdwEffect)
        return E_POINTER;

    // kill the current dragee
    m_srpCurrentDragee.Release();

    *pdwEffect = DROPEFFECT_NONE;

    // only accept simple drop
    // no keys down at this point
    if(grfKeyState != 0)
    {
        return NOERROR;
    }

    // now see if it contains CF_DSREF
    FORMATETC fmtetc;
    // this just retrives the previously registered
    // custom format value
    fmtetc.cfFormat = m_uClipFmt;
    fmtetc.dwAspect = DVASPECT_CONTENT;
    fmtetc.lindex = -1;
    fmtetc.ptd = NULL;
    fmtetc.tymed = TYMED_HGLOBAL;

    if(SUCCEEDED(pDataObj->QueryGetData(&fmtetc)))
    {
        //get the DSREF out of it
        HRESULT hr = NOERROR;
        STGMEDIUM stgmed;
        memset(&stgmed, 0, sizeof(STGMEDIUM));

        if(SUCCEEDED(hr = pDataObj->GetData(&fmtetc, &stgmed)))
        {
            _ASSERT(stgmed.tymed == TYMED_HGLOBAL);

            CComPtr<IStream> srpStream;

            if(SUCCEEDED(hr = CreateStreamOnHGlobal(stgmed.hGlobal, FALSE, &srpStream)))
            {
                IDSRefConsumer* pConsumer;
                if(SUCCEEDED(hr = OleLoadFromStream(srpStream, IID_IDSRefConsumer, (LPVOID*)&pConsumer)))
                {
                    //success, kill the old tree and create a new one
                    if(SUCCEEDED(hr = GenerateNewTree(pConsumer)))
                    {
                        *pdwEffect = DROPEFFECT_COPY;
                        return hr;
                    }
                }
                ReleaseStgMedium(&stgmed);
            }
        }

        return hr;
    }

    return NOERROR;
}

///////////////////////////////////////////////////////////////////////////////
// CDSRefToolWindow IOleCommandTarget Implementation

#pragma warning(disable:4065) // switch statement contains 'default' but no 'case' labels

STDMETHODIMP CDSRefToolWindow::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(cCmds == 1);
    _ASSERTE(prgCmds && pguidCmdGroup);

    if ((prgCmds == NULL) || (pguidCmdGroup == NULL))
        return E_INVALIDARG;

    DWORD cmdf;

    if (*pguidCmdGroup == CLSID_StandardCommandSet97)
    {
        // The following bitwise flags control the state of a command:
        //      OLECMDF_SUPPORTED, OLECMDF_ENABLED, OLECMDF_LATCHED,
        //      OLECMDF_NINCHED, OLECMDF_INVISIBLE, OLECMDF_DEFHIDEONCTXTMENU
        //
        // Common cases are the following:
        //  1. Enable a command --  cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED
        //  2. Disable a command -- cmdf = OLECMDF_SUPPORTED
        //  3. Hide a command --    cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE
        cmdf = OLECMDF_SUPPORTED;

        switch (prgCmds[0].cmdID)
        {
        case cmdidPaste:
            if(QueryPaste())
                cmdf |= OLECMDF_ENABLED;
            else
                return OLECMDERR_E_NOTSUPPORTED;
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

STDMETHODIMP CDSRefToolWindow::Exec(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdexecopt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut)
{
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(pguidCmdGroup);

    if (pguidCmdGroup == NULL)
        return E_INVALIDARG;

    HRESULT hr = S_OK;

    if (*pguidCmdGroup == CLSID_StandardCommandSet97)
    {
        // IOleCommandTargt::Exec should report errors that may occur
        // in the execution of a command. Therefore clear any existing
        // existing error info first
        _AtlModule.ClearErrorInfo();

        switch (nCmdID)
        {
            
        case cmdidPaste:
            hr = DoPaste();
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
// CDSRefToolWindow WindowProcs and Message Handlers

BOOL CDSRefToolWindow::RegisterWindowClass()
{
    ATLTRACE(_T("CDSRefToolWindow::RegisterWindowClass\n"));

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

LRESULT CALLBACK CDSRefToolWindow::StaticWndProc(HWND hwnd, UINT iMsg,
                                               WPARAM wParam, LPARAM lParam)
{
    CDSRefToolWindow *pThis;

    if (iMsg == WM_CREATE)
    {
        pThis = (CDSRefToolWindow*)((LPCREATESTRUCT)lParam)->lpCreateParams;
        SetWindowLong(hwnd, EB_THIS, (UINT)pThis);
        pThis->m_hwndMain = hwnd;
    }
    else
        pThis = (CDSRefToolWindow*)GetWindowLong(hwnd, EB_THIS);

    if (pThis)
        return pThis->WndProc(iMsg, wParam, lParam);
    else
        return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

LRESULT CDSRefToolWindow::WndProc(UINT imsg, WPARAM wparam, LPARAM lparam)
{
    switch(imsg)
    {
    case WM_PAINT:
        {
            //only paint if we don't have a tree view
            if(!m_hwndTree)
            {
                PAINTSTRUCT ps;
                BeginPaint(m_hwndMain, &ps);
                
                HFONT hfOld = (HFONT)SelectObject(ps.hdc, GetStockObject(DEFAULT_GUI_FONT));
                // note we are using the ANSI functions here
                // because the Win9x Unicode lib does not support TextOutW
                char str[_MAX_PATH];
                LoadStringA(_AtlBaseModule.GetResourceInstance(), IDS_NOREF, str, _MAX_PATH - 1);
                TextOutA(ps.hdc, 0, 0, str, lstrlenA(str));

                SelectObject(ps.hdc, hfOld);
                
                EndPaint(m_hwndMain, &ps);

            }
        }
        break;
    case WM_SIZE:
        {
            if(m_hwndTree && m_hwndEdit)
            {
                MoveWindow(m_hwndTree, 0, 0, LOWORD(lparam), 2 * (HIWORD(lparam) / 3), TRUE);
                MoveWindow(m_hwndEdit, 0, 2 * (HIWORD(lparam) / 3), LOWORD(lparam), HIWORD(lparam) - (2 * (HIWORD(lparam) / 3)), TRUE);
            }
        }
        break;
    case WM_NOTIFY:
        {
            switch(((NMHDR*)lparam)->code)
            {
                        // we have to explicitly check for A and W here
                        // as we'll get the A version on Win9x
                        // if we accessed any of the strings coming in
                        // we would of course handle these two cases differently
            case TVN_SELCHANGEDA:
                        case TVN_SELCHANGEDW:
                WriteInfoForItem((DSREFNODEID)((NMTREEVIEW*)lparam)->itemNew.lParam);
                break;
            }
            break;
        }
    case WM_CTLCOLORSTATIC:
        {
            //make sure it is the edit control
            if((HWND)lparam == m_hwndEdit)
            {
                SetBkColor((HDC)wparam, GetSysColor(COLOR_INFOBK));
                SetTextColor((HDC)wparam, GetSysColor(COLOR_INFOTEXT));

                return (LRESULT)GetSysColorBrush(COLOR_INFOBK);
            }
        }
        break;
    }
    return DefWindowProc(m_hwndMain, imsg, wparam, lparam);
}



/////////////////////////////////////////////////////////////////////////////
// Tree Generation

HRESULT CDSRefToolWindow::GenerateNewTree(IDSRefConsumer* pConsumer)
{
    HWND hwndOldTree, hwndOldEdit;

    if (!pConsumer)
        return E_POINTER;

    hwndOldTree = m_hwndTree;
    hwndOldEdit = m_hwndEdit;
    
    if(m_srpCurrentDSRef) m_srpCurrentDSRef.Release();

    m_srpCurrentDSRef = pConsumer;

    //the assignment above causes an AddRef, so
    //explicitly release the passed in pointer
    pConsumer->Release();

    RECT rc;
    GetClientRect(m_hwndMain, &rc);

    m_hwndTree = CreateWindowEx(WS_EX_CLIENTEDGE,         // dwExStyle
                            WC_TREEVIEW,                  // lpszClassName
                            _T("DSRef Tree"),             // lpszWindowName
                            WS_VISIBLE | WS_CHILD |
                            WS_CLIPCHILDREN |
                            TVS_HASLINES | 
                            TVS_HASBUTTONS | 
                            TVS_LINESATROOT |
                            TVS_SHOWSELALWAYS,              // dwStyle
                            rc.left, rc.top, rc.right - rc.left, 2 * ((rc.bottom - rc.top) / 3), // x, y, nWidth, nHeight
                            m_hwndMain,                   // hWndParent
                            NULL,                         // hMenu
                            _AtlBaseModule.GetModuleInstance(),  // hInstance
                            0);

    m_hwndEdit = CreateWindowEx(WS_EX_CLIENTEDGE,         // dwExStyle
                            _T("Edit"),                   // lpszClassName
                            _T(""),                       // lpszWindowName
                            WS_VISIBLE | WS_CHILD |
                            WS_CLIPCHILDREN |
                            ES_LEFT | 
                            ES_MULTILINE | 
                            ES_READONLY,                // dwStyle
                            rc.left, rc.top + 2 * ((rc.bottom - rc.top) / 3), rc.right - rc.left, (rc.bottom - rc.top) / 3, // x, y, nWidth, nHeight
                            m_hwndMain,                   // hWndParent
                            NULL,                         // hMenu
                            _AtlBaseModule.GetModuleInstance(),  // hInstance
                            0);

    //set the font in the edit control
    SendMessage(m_hwndEdit, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), 0);


    HIMAGELIST hlist = ImageList_LoadBitmap(_AtlBaseModule.GetModuleInstance(), MAKEINTRESOURCE(IDB_IMAGELIST), 16, 0, RGB(255,0,255));
    if(hlist == NULL) return E_OUTOFMEMORY;

    TreeView_SetImageList(m_hwndTree, hlist, TVSIL_NORMAL);

    HRESULT hr = GenerateChildren(DSREFNODEID_ROOT, NULL);

    if(SUCCEEDED(hr))
    {
        //select something
        TreeView_SelectItem(m_hwndTree, TreeView_GetLastVisible(m_hwndTree));
    }

    if(hwndOldTree)
        DestroyWindow(hwndOldTree);

    if(hwndOldEdit)
        DestroyWindow(hwndOldEdit);

    return hr;

}


HRESULT CDSRefToolWindow::GenerateChildren(DSREFNODEID idParent, HTREEITEM htiParent)
{
    DSREFNODEID idCur;
    HRESULT hr = NOERROR;

    if(SUCCEEDED(hr = m_srpCurrentDSRef->GetFirstChildNode(idParent, &idCur)))
    {
        while(idCur)
        {
            // add this one
            DSREFNODEID idLast;
            HTREEITEM htiLast;

            if(FAILED(hr = AddNodeToTree(idCur, htiParent, &htiLast)))
                return hr;

            //now do its children
            if(FAILED(hr = GenerateChildren(idCur, htiLast)))
                return hr;

            idLast = idCur;
            if(FAILED(hr = m_srpCurrentDSRef->GetNextSiblingNode(idLast, &idCur)))
                return hr;
        }

        TreeView_Expand(m_hwndTree, htiParent, TVE_EXPAND);
    }
    
    return hr;
}

HRESULT CDSRefToolWindow::AddNodeToTree(DSREFNODEID id, HTREEITEM htiParent, HTREEITEM* phtiNew)
{
    TVINSERTSTRUCT tvis;

    if (!phtiNew)
        return E_POINTER;

    tvis.hParent = htiParent;
    tvis.hInsertAfter = TVI_SORT;
    tvis.itemex.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
    tvis.itemex.lParam = (long)id;
    tvis.itemex.iImage = tvis.itemex.iSelectedImage = GetImageForNode(id);
    
    BSTR bstrText;
    m_srpCurrentDSRef->GetName(id, &bstrText);

    tvis.itemex.pszText = W2T(bstrText);

    *phtiNew = TreeView_InsertItem(m_hwndTree, &tvis);
    
    SysFreeString(bstrText);

    return NOERROR;
}

int CDSRefToolWindow::GetImageForNode(DSREFNODEID id)
{
    int ret = 0;
    DSREFTYPE type;

    if(SUCCEEDED(m_srpCurrentDSRef->GetType(id, &type)))
    {
        if(type & DSREFTYPE_FIELD)
            return 0;
        if(type & DSREFTYPE_TABLE)
            return 1;
        if(type & DSREFTYPE_QUERY)
            return 2;
        if(type & DSREFTYPE_DATABASE)
            return 3;
        if(type & DSREFTYPE_TRIGGER)
            return 4;
        if(type & DSREFTYPE_STOREDPROCEDURE)
            return 5;
        if(type & DSREFTYPE_EXTENDED)
            return 6;
        if(type & DSREFTYPE_SCHEMADIAGRAM)
            return 7;
        if(type & DSREFTYPE_VIEW)
            return 8;
        if(type & DSREFTYPE_SYNONYM)
            return 9;
        if(type & DSREFTYPE_FUNCTION)
            return 10;
        if(type & DSREFTYPE_PACKAGE)
            return 11;
        if(type & DSREFTYPE_PACKAGEBODY)
            return 12;
        if(type & DSREFTYPE_RELATIONSHIP)
            return 13;
    }

    return 6;
}

char* CDSRefToolWindow::GetTypeString(DSREFTYPE type)
{
    char* strType = NULL;
    UINT id = 0;

    if(type & DSREFTYPE_NODE)
    {
        id = type & DSREFTYPE_NODE;
        if(id & DSREFTYPE_EXTENDED) id = id & ~(DSREFTYPE_EXTENDED);
        UINT shift = 0;
        while(id > 0xFFFF)
        {
            id = id >> 4;
            shift++;
        }
        id += shift;
    }           
    else
        id = IDS_UNKNOWNTYPE;

    strType = (char*)LocalAlloc(LPTR, 100);

    if(strType)
        LoadStringA(_AtlBaseModule.GetResourceInstance(), id, strType, 99);

    _ASSERT(strType && *strType);

    return strType;
}

HRESULT CDSRefToolWindow::WriteInfoForItem(DSREFNODEID id)
{
    BSTR bstrName = NULL, bstrOwner = NULL;
    FILETIME timestamp;
    SYSTEMTIME systime;
    DSREFTYPE type;
    DWORD version;
    char* strType = NULL;
               
    HRESULT hr = NOERROR;
    IfFailGo(m_srpCurrentDSRef->GetName(id, &bstrName));
    IfFailGo(m_srpCurrentDSRef->GetOwner(id, &bstrOwner));
    IfFailGo(m_srpCurrentDSRef->GetTimestamp(&timestamp));
    IfFailGo(m_srpCurrentDSRef->GetType(id, &type));
    IfFailGo(m_srpCurrentDSRef->GetVersion(&version));

    FileTimeToSystemTime(&timestamp, &systime);

    {
        const DWORD dwSize = 2048;
        WCHAR wszTxt[dwSize];
        WCHAR wszFmt[1024];
        strType = GetTypeString(type);

        int iRet = LoadStringW(_AtlBaseModule.GetResourceInstance(), IDS_FORMATSTRING, wszFmt, 1023);
        if (iRet == 0)
        {
            hr = HRESULT_FROM_WIN32(::GetLastError());
            goto Error;
        }

        iRet = _snwprintf( wszTxt, dwSize-2, wszFmt, 
            /* Data Source Reference Node: %s\r\n */ bstrName,
            /* Owner:\t%s\r\n */ bstrOwner,
            /* Type:\t%S\r\n  */ strType,
            /* Created:\t%d:%d:%d.%d %d\\%d\\%d\r\n */ 
                systime.wHour, systime.wMinute, systime.wSecond, systime.wMilliseconds,
                systime.wMonth, systime.wDay,systime.wYear,
            /* Version:\t%d"*/ version);
        wszTxt[dwSize-1] = L'\0';

        SendMessageW(m_hwndEdit, WM_SETTEXT, 0, (LPARAM)wszTxt);
    }   

    //make sure the whole window gets drawn
    InvalidateRect(m_hwndEdit, NULL, TRUE);

Error:

//  if(txt) LocalFree((HLOCAL)txt);

    if(bstrName)
        SysFreeString(bstrName);

    if(bstrOwner)
        SysFreeString(bstrOwner);

    if(strType)
        LocalFree((HLOCAL)strType);

    return hr;
}

//Paste Helpers

BOOL CDSRefToolWindow::QueryPaste()
{
    UINT uFmtNext = 0;

    BOOL ret = FALSE;
    OpenClipboard(m_hwndMain);

    while(uFmtNext = EnumClipboardFormats(uFmtNext))
    {
        if(uFmtNext == m_uClipFmt)
        {
            ret = TRUE;
            break;
        }
    }

    CloseClipboard();
    return ret;
}

HRESULT CDSRefToolWindow::DoPaste()
{
    HRESULT hr = NOERROR;
    OpenClipboard(m_hwndMain);

    HGLOBAL hglob = (HGLOBAL)GetClipboardData(m_uClipFmt);

    //now turn it into a IDSRefConsumer
    if(hglob)
    {
        CComPtr<IStream> srpStream;

        if(SUCCEEDED(hr = CreateStreamOnHGlobal(hglob, FALSE, &srpStream)))
        {
            IDSRefConsumer* pConsumer;
            if(SUCCEEDED(hr = OleLoadFromStream(srpStream, IID_IDSRefConsumer, (LPVOID*)&pConsumer)))
            {
                //success, kill the old tree and create a new one
                hr = GenerateNewTree(pConsumer);
            }
        }
    }
    CloseClipboard();

    return hr;
}
