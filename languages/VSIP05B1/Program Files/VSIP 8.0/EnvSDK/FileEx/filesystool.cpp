
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FileSysTool.h
//
// Declaration of CFileSystemToolWindow
//
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "FileSysTool.h"
#include "FSFolderPane.h"
#include "FSFilePane.h"

#define FST_DEFAULT_CX  200
#define FST_DEFAULT_CY  300

BOOL CFileSystemToolWindow::m_fClassRegistered = FALSE;
LPCTSTR CFileSystemToolWindow::m_szClassName = _T("WCFileSysTool");


//*****************************************************************************
// CFileSystemToolWindow Constructor/Destructor
//*****************************************************************************

CFileSystemToolWindow::CFileSystemToolWindow()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::CFileSystemToolWindow \n") );

    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Creating CFileSystemToolWindow: 0x%X\n"), this);
    }

    m_hwndParent = NULL;
    m_hwndMain = NULL;
    m_hwndRoot = NULL;
    m_hwndFolderPane = NULL;
    m_hwndFilePane = NULL;
    m_hFontUI = NULL;
}

CFileSystemToolWindow::~CFileSystemToolWindow()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::~CFileSystemToolWindow \n") );

    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Destructing CFileSystemToolWindow: 0x%X\n"), this);
    }
    if (m_hFontUI)
    {
        DeleteObject(m_hFontUI);
    }
}


//*****************************************************************************
// CFileSystemToolWindow Operations
//*****************************************************************************

HRESULT CFileSystemToolWindow::CreateTool(IVsWindowFrame** ppFrame)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::CreateTool \n") );

    _ASSERTE(ppFrame);

    USES_CONVERSION;

    HRESULT hr = E_FAIL;

    InitParam(ppFrame);

    IVsUIShell* pUIShell = _VxModule.GetVsUIShell(); // un-addref'd
    
    if (pUIShell)
    {
        CString strCaption;
        CComPtr<IVsWindowPane> srpPane;
        CComVariant varBitmap;

        AtlCreateInstance(CFileSystemToolWindow, IID_IVsWindowPane, &srpPane);
        IfFailGo(hr);

        strCaption.LoadString(IDS_FILESYSTOOL);
    
        hr = pUIShell->CreateToolWindow((VSCREATETOOLWIN)CTW_fForceCreate,
                                        NULL,
                                        srpPane,
                                        CLSID_NULL,
                                        guidFileSysTool,
                                        GUID_NULL,
                                        NULL,
                                        T2CW(strCaption),
                                        NULL,
                                        ppFrame);
        IfFailGo(hr);

        varBitmap = IDB_CMDBAR;
        (*ppFrame)->SetProperty(VSFPROPID_BitmapResource, varBitmap);

        varBitmap = bmpidFileSysTool - 1;          // cmdbar bitmap indexes are 1-based
        (*ppFrame)->SetProperty(VSFPROPID_BitmapIndex, varBitmap);
    }

OnError:
    return hr;
}


//*****************************************************************************
// CFileSystemToolWindow IVsWindowPane Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemToolWindow::SetSite(
                    /*[in] */ IServiceProvider* pSP)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::SetSite \n") );

    ExpectedPtrRet(pSP);

    HRESULT hr;

    hr = pSP->QueryService(SID_STrackSelection, IID_ITrackSelection,
                           (void**)&m_srpSelTracker);
    IfFailGo(hr);

    m_srpSiteSP = pSP;

OnError:
    return hr;
}

STDMETHODIMP CFileSystemToolWindow::CreatePaneWindow(
                    /*[in] */ HWND  hwndParent,
                    /*[in] */ int   x,
                    /*[in] */ int   y,
                    /*[in] */ int   cx,
                    /*[in] */ int   cy,
                    /*[out]*/ HWND* phwnd)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::CreatePaneWindow \n") );

    ExpectedPtrRet(hwndParent);
    ExpectedPtrRet(phwnd);

    HRESULT hr = S_OK;

    if (!m_fClassRegistered)
        m_fClassRegistered = RegisterWindowClass();
    ExpectedExprGo(m_fClassRegistered);

    *phwnd = CreateWindowEx(0,                            // dwExStyle
                            m_szClassName,                // lpszClassName
                            _T("File System Browser"),    // lpszWindowName
                            WS_VISIBLE | WS_CHILD |
                            WS_CLIPSIBLINGS |
                            WS_CLIPCHILDREN,              // dwStyle
                            x, y, cx, cy,                 // x, y, nWidth, nHeight
                            hwndParent,                   // hWndParent
                            (HMENU)IDC_FILESYSTOOL_MAIN,  // hMenu
                            _AtlBaseModule.GetModuleInstance(),  // hInstance
                            this);                        // lpParam

    ExpectedExprGo(*phwnd);

    m_hwndParent = hwndParent;

    // make sure the property browser is tracking us. Somehow the shell doesn't
    // track until a cmdidPropertiesOrPropPages is executed
    OnSelectChange(NULL);

OnError:
    return hr;
}

STDMETHODIMP CFileSystemToolWindow::GetDefaultSize(
                    /*[out]*/ SIZE* pSize)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::GetDefaultSize \n") );

    ExpectedPtrRet(pSize);

    pSize->cx = FST_DEFAULT_CX;
    pSize->cy = FST_DEFAULT_CY;
    return S_OK;
}

STDMETHODIMP CFileSystemToolWindow::ClosePane(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::ClosePane \n") );

    // release the selection tracker
    OnSelectChange(NULL);
    m_srpSelTracker.Release();

    // release the file panes
    CComPtr<IVsSplitPane> srpSplitPane;
    if (m_srpFilePane)
    {
        m_srpFilePane->QueryInterface(IID_IVsSplitPane, (void**)&srpSplitPane);
        _ASSERTE(srpSplitPane);

        srpSplitPane->ClosePane();
        srpSplitPane.Release();
        m_srpFilePane.Release();
    }
    m_srpFilePaneCmdTgt.Release();

    // release the folder
    if (m_srpFolderPane)
    {
        m_srpFolderPane->QueryInterface(IID_IVsSplitPane, (void**)&srpSplitPane);
        _ASSERTE(srpSplitPane);

        srpSplitPane->ClosePane();
        srpSplitPane.Release();
        m_srpFolderPane.Release();
    }
    m_srpFolderPaneCmdTgt.Release();

    // close the root splitter
    if (m_srpRootWindow)
    {
        m_srpRootWindow->ClosePane();
        m_srpRootWindow->SetSite(NULL);
        m_srpRootWindow.Release();
    }
    m_srpRootSplitter.Release();

    // finally release the site
    m_srpSiteSP.Release();
    return S_OK;
}

STDMETHODIMP CFileSystemToolWindow::LoadViewState(
                    /*[in] */ IStream* pStream)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::LoadViewState \n") );
    return S_OK;
}

STDMETHODIMP CFileSystemToolWindow::SaveViewState(
                    /*[in] */ IStream* pStream)
{
    // ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::SaveViewState \n") );
    return S_OK;
}

STDMETHODIMP CFileSystemToolWindow::TranslateAccelerator(
                    /*[in]*/ LPMSG lpmsg)
{
    // ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::TranslateAccelerator \n") );
    return S_FALSE;
}


//*****************************************************************************
// CFileSystemToolWindow IOleCommandTarget Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemToolWindow::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    // ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::QueryStatus \n") );

    ExpectedPtrRet(pguidCmdGroup);
    ExpectedExprRet(cCmds);
    ExpectedPtrRet(pCmdText);
    ExpectedPtrRet(prgCmds);

    CComPtr<IOleCommandTarget> srpCmdTgt;
    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;
    DWORD cmdf = 0;

    if (*pguidCmdGroup == guidEUCmd)
    {
        switch (prgCmds[0].cmdID)
        {
            case cmdidFilesOpenFile:
            case cmdidFilesPreviewFile:
            case cmdidFilesRefresh:
            case cmdidFilesFilter:
            case cmdidFilesSortName:
            case cmdidFilesSortExtension:
                srpCmdTgt = m_srpFilePaneCmdTgt;
                break;
            case cmdidFolderView:
            case cmdidShortcutView:
            case cmdidFoldersRefresh:
            case cmdidBrowseShortcut:
                srpCmdTgt = m_srpFolderPaneCmdTgt;
                break;
            default:
                hr = OLECMDERR_E_NOTSUPPORTED;
        }
    }

    if (srpCmdTgt)
    {
        hr = srpCmdTgt->QueryStatus(pguidCmdGroup, cCmds, prgCmds, pCmdText);
    }
    else
    {
        prgCmds[0].cmdf = 0;
    }

    return hr;
}

STDMETHODIMP CFileSystemToolWindow::Exec(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdExecOpt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::Exec \n") );

    ExpectedPtrRet(pguidCmdGroup);

    CComPtr<IOleCommandTarget> srpCmdTgt;
    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;

    if (*pguidCmdGroup == guidEUCmd)
    {
        switch (nCmdID)
        {
            case cmdidFilesOpenFile:
            case cmdidFilesPreviewFile:
            case cmdidFilesRefresh:
            case cmdidFilesFilter:
            case cmdidFilesSortName:
            case cmdidFilesSortExtension:
            case cmdidFilesSortReadOnly:
                srpCmdTgt = m_srpFilePaneCmdTgt;
                break;
            case cmdidFolderView:
            case cmdidShortcutView:
            case cmdidFoldersRefresh:
            case cmdidBrowseShortcut:
                srpCmdTgt = m_srpFolderPaneCmdTgt;
                break;
            default:
                hr = OLECMDERR_E_NOTSUPPORTED;
        }
    }

    if (srpCmdTgt)
    {
        hr = srpCmdTgt->Exec(pguidCmdGroup, nCmdID, nCmdExecOpt, pvaIn, pvaOut);
    }
    return hr;
}


//*****************************************************************************
// CFileSystemToolWindow IServiceProvider Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemToolWindow::QueryService(
                    /*[in] */ REFGUID rsid,
                    /*[in] */ REFIID  riid,
                    /*[out]*/ void**  ppvObject)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::QueryService \n") );

    _ASSERTE(ppvObject);

    if ((rsid == SID_SFileSystemToolWindow) ||
        (rsid == SID_STrackSelection))
    {
        return QueryInterface(riid, ppvObject);
    }
    else if (rsid == SID_SFileSystemFolderPane)
    {
        if (m_srpFolderPane)
            return m_srpFolderPane->QueryInterface(riid, ppvObject);
    }
    else if (rsid == SID_SFileSystemFilePane)
    {
        if (m_srpFilePane)
            return m_srpFilePane->QueryInterface(riid, ppvObject);
    }
    else if (m_srpSiteSP)
    {
        return m_srpSiteSP->QueryService(rsid, riid, ppvObject);
    }


    InitParam(ppvObject);
    return E_NOINTERFACE;
}


//*****************************************************************************
// CFileSystemToolWindow ITrackSelection Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemToolWindow::OnSelectChange(
                    /*[in]*/ ISelectionContainer* pSC)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::OnSelectChange \n") );

    if (m_srpSelTracker)
    {
        if (pSC)
            m_srpSelTracker->OnSelectChange(NULL);
        return m_srpSelTracker->OnSelectChange(pSC);
    }
    else
        return E_UNEXPECTED;
}


//*****************************************************************************
// CFileSystemToolWindow IFileSystemToolWindow Implementation
//*****************************************************************************


//*****************************************************************************
// CFileSystemToolWindow Implementation
//*****************************************************************************

HRESULT CFileSystemToolWindow::CreateSubPanes()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::CreateSubPanes \n") );

    CComPtr<IVsSplitter> srpSplitter;
    CComPtr<IVsSplitPane> srpFolderSplitPane;
    CComPtr<IVsSplitPane> srpFileSplitPane;
    long left, top, right, bottom;
    HWND hwndPaneParent;
    RECT rc;
    int nHeight;
    int nHeightFolderPane;
    HRESULT hr;

    // create the splitter
    //hr = _VxModule.VsCreateInstance(CLSID_VsSplitRoot, NULL, CLSCTX_INPROC_SERVER,
    //                              IID_IVsSplitRoot, (void**)&m_srpRootSplitter);
    hr = _VxModule.VsCreateInstance(CLSID_VsSplitRoot, IID_IVsSplitRoot, 
                                    (void**)&m_srpRootSplitter,    NULL, 
                                    CLSCTX_INPROC_SERVER);
    IfFailGo(hr);

    hr = m_srpRootSplitter->QueryInterface(IID_IVsWindowPane,
                                           (void**)&m_srpRootWindow);
    IfFailGo(hr);

    hr = m_srpRootWindow->SetSite(m_srpSiteSP);
    IfFailGo(hr);

    // create the root splitter's window
    GetWindowRect(m_hwndMain, &rc);

    hr = m_srpRootWindow->CreatePaneWindow(m_hwndMain, 0, 0, rc.right - rc.left, rc.bottom - rc.top, &m_hwndRoot);
    IfFailGo(hr);

    hr = m_srpRootSplitter->GetRootSplitter(&srpSplitter);
    IfFailGo(hr);

    hr = m_srpRootSplitter->GetWindowHandle(&hwndPaneParent);
    IfFailGo(hr);

    hr = srpSplitter->GetPosition(&left, &top, &right, &bottom);
    IfFailGo(hr);

    // now create the folder pane
    AtlCreateInstance(CFileSystemFolderPane, IID_IFileSystemPane, &m_srpFolderPane);
    IfFailGo(hr);

    // now create the file pane
    AtlCreateInstance(CFileSystemFilePane, IID_IFileSystemPane, &m_srpFilePane);
    IfFailGo(hr);

    hr = m_srpFilePane->Initialize(static_cast<IServiceProvider*>(this),
                                   hwndPaneParent, m_hFontUI);
    IfFailGo(hr);

    hr = m_srpFolderPane->Initialize(static_cast<IServiceProvider*>(this),
                                     hwndPaneParent, m_hFontUI);
    IfFailGo(hr);

    hr = m_srpFolderPane->QueryInterface(IID_IVsSplitPane, (void**)&srpFolderSplitPane);
    _ASSERTE(SUCCEEDED(hr));

    hr = m_srpFolderPane->QueryInterface(IID_IOleCommandTarget, (void**)&m_srpFolderPaneCmdTgt);
    _ASSERTE(SUCCEEDED(hr));

    hr = m_srpFilePane->QueryInterface(IID_IVsSplitPane, (void**)&srpFileSplitPane);
    _ASSERTE(SUCCEEDED(hr));

    hr = m_srpFilePane->QueryInterface(IID_IOleCommandTarget, (void**)&m_srpFilePaneCmdTgt);
    _ASSERTE(SUCCEEDED(hr));

    nHeight = bottom - top;
    nHeightFolderPane = nHeight / 2;
    hr = srpSplitter->SplitPane(srpFileSplitPane, 0, nHeight - nHeightFolderPane,
                                SF_MAKEPRIMARY | SF_HORIZONTAL, NULL);
    IfFailGo(hr);

    m_srpFilePane->GetPaneWindow(&m_hwndFilePane);
    ShowWindow(m_hwndFilePane, SW_SHOW);

    hr = srpSplitter->SplitPane(srpFolderSplitPane, 0, nHeightFolderPane,
                                SF_MAKESECONDARY | SF_HORIZONTAL, NULL);
    IfFailGo(hr);

    m_srpFolderPane->GetPaneWindow(&m_hwndFolderPane);
    ShowWindow(m_hwndFolderPane, SW_SHOW);

OnError:
    return hr;
}

BOOL CFileSystemToolWindow::RegisterWindowClass()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::RegisterWindowClass \n") );

    WNDCLASS wc;

    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = (WNDPROC)StaticWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = EXTRABYTES;
    wc.hInstance = _AtlBaseModule.GetModuleInstance();
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = m_szClassName;

    return RegisterClass(&wc);
}

void CFileSystemToolWindow::InitUIFont()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::InitUIFont \n") );

    _ASSERTE(!m_hFontUI);
    _ASSERTE(m_srpSiteSP);

    HRESULT hr;
    CComPtr<IUIHostLocale> srpUIHL;

    hr = m_srpSiteSP->QueryService(SID_SUIHostLocale, IID_IUIHostLocale,
                                   (void**)&srpUIHL);
    IfFailGo(hr);

    UIDLGLOGFONT lfDlg;

    hr = srpUIHL->GetDialogFont(&lfDlg);
    IfFailGo(hr);

#ifndef _UNICODE
    char szFaceName[LF_FACESIZE];

    WideCharToMultiByte(CP_ACP, 0, lfDlg.lfFaceName, -1, szFaceName, 
                        LF_FACESIZE, NULL, NULL);
    lstrcpyA((LPSTR)lfDlg.lfFaceName, szFaceName);
#endif
    m_hFontUI = CreateFontIndirect((LOGFONT*)&lfDlg);

OnError:
    if (m_hFontUI == NULL)
    {
        m_hFontUI = CreateFont(13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _T("Tahoma"));
    }
}

LRESULT CALLBACK CFileSystemToolWindow::StaticWndProc(HWND hwnd, UINT iMsg,
                                                      WPARAM wParam, LPARAM lParam)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::StaticWndProc \n") );

    CFileSystemToolWindow *pThis = NULL;

    if (iMsg == WM_CREATE)
    {
        pThis = (CFileSystemToolWindow*)((LPCREATESTRUCT)lParam)->lpCreateParams;
        SetWindowLongPtr(hwnd, EB_THIS, (LONG_PTR)pThis);
        pThis->m_hwndMain = hwnd;
    }
    else
        pThis = (CFileSystemToolWindow*)GetWindowLongPtr(hwnd, EB_THIS);

    if (pThis)
        return pThis->WndProc(hwnd, iMsg, wParam, lParam);
    else
        return DefWindowProc(hwnd, iMsg, wParam, lParam);
}


//*****************************************************************************
// CFileSystemToolWindow Message Handlers
//*****************************************************************************

LRESULT CFileSystemToolWindow::WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::WndProc \n") );

    switch (iMsg)
    {
        case WM_CREATE:
            return OnCreate();
        case WM_SIZE:
            return OnSize(wParam, LOWORD(lParam), HIWORD(lParam));
    }
    return DefWindowProc(m_hwndMain, iMsg, wParam, lParam);
}

LRESULT CFileSystemToolWindow::OnCreate()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::OnCreate \n") );

    HRESULT hr;

    InitUIFont();

    hr = CreateSubPanes();
    return SUCCEEDED(hr) ? 0 : -1;
}

LRESULT CFileSystemToolWindow::OnSize(WPARAM flag, int width, int height)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemToolWindow::OnSize \n") );

    MoveWindow(m_hwndRoot, 1, 1, width - 2, height - 2, FALSE);
    return 0;
}
