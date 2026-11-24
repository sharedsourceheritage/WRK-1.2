
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

////////////////////////////////////////////////////////////////////////////
// 
//  MWToolWindow.cpp: implementation of the CMWToolWindow class.
//
////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "PrjInc.h"

// Default size for the tool window
#define MWT_DEFAULT_CX  75   
#define MWT_DEFAULT_CY  100

// =========================================================================
//                                             Static members initialization
//
CEnvSDKPtrArray<IVsWindowFrame>   CMWToolWindow::ms_prgMWFrames;
//
//                                             Static members initialization
// =========================================================================

// =========================================================================
//                                 Construct, initialize, copy, and destruct
//

CMWToolWindow::CMWToolWindow()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 3, _T(" CMWToolWindow::CMWToolWindow \n") );
}

CMWToolWindow::~CMWToolWindow()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 3, _T(" CMWToolWindow::~CMWToolWindow \n") );
}


HRESULT CMWToolWindow::Initialize(
                       /*[in]*/ IVsWindowFrame* pFrame) 
{
    ENVSDK_TRACE(envsdkTraceGeneral, 3, _T(" CMWToolWindow::Initialize \n") );

    ExpectedPtrRet(pFrame);

    HRESULT hr = S_OK;
    m_srpWindowFrame = pFrame;

    // get the IVsToolWindowToolbarHost interface pointer
    CComVariant varToolbarHost;
    CComPtr<IVsToolWindowToolbarHost> srpToolWindowToolbarHost;
    CComVariant varBitmap;

    hr = m_srpWindowFrame->GetProperty(
        /* [in]  VSFPROPID propid */ VSFPROPID_ToolbarHost,
        /* [out] VARIANT * pvar   */ &varToolbarHost);
    IfFailRet(hr);
    ExpectedExprRet(varToolbarHost.vt == VT_UNKNOWN);
    ExpectedExprRet(varToolbarHost.punkVal != NULL);
    hr = varToolbarHost.punkVal->QueryInterface(IID_IVsToolWindowToolbarHost,
                                                (void **)& srpToolWindowToolbarHost); 
    IfFailRet(hr);ExpectedExprRet(srpToolWindowToolbarHost != NULL);  

    // add the toolbar
    hr = srpToolWindowToolbarHost->AddToolbar(
            /* [in] VSTWT_LOCATION dwLoc */  VSTWT_TOP,
            /* [in] const GUID *pguid    */  &guidMitWinMenuGrp,
            /* [in] DWORD dwId           */  IDM_TLB_MWTOOL);    
    IfFailRet(hr);

    //initialize the bitmap
    varBitmap = IDB_CMDBAR;
    hr = m_srpWindowFrame->SetProperty(
            /* [in] VSFPROPID propid */  VSFPROPID_BitmapResource,
            /* [in] VARIANT   var    */  varBitmap);
    IfFailRet(hr);

    varBitmap = bmpidMWTool - 1;          // cmdbar bitmap indexes are 1-based
    hr = m_srpWindowFrame->SetProperty(
            /* [in] VSFPROPID propid */  VSFPROPID_BitmapIndex,
            /* [in] VARIANT   var    */  varBitmap);
    IfFailRet(hr);

    //init the dialog
    hr = m_wnd.Initialize(srpToolWindowToolbarHost);
    IfFailRet(hr);

    ms_prgMWFrames.Add(pFrame);
    m_fZombie = FALSE;
    return hr;
}

//
//                                 Construct, initialize, copy, and destruct
// =========================================================================


// =========================================================================
//                                                             IVsWindowPane
//
// -------------------------------------------------------------------------
//                                                   IVsWindowPane interface
//
STDMETHODIMP CMWToolWindow::SetSite(
                    /*[in] */ IServiceProvider* pSP)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::SetSite \n") );

    ExpectedPtrRet(pSP);

    m_srpSiteSP = pSP;

    return S_OK;
}

STDMETHODIMP CMWToolWindow::CreatePaneWindow(
                    /*[in] */ HWND  hwndParent,
                    /*[in] */ int   x,
                    /*[in] */ int   y,
                    /*[in] */ int   cx,
                    /*[in] */ int   cy,
                    /*[out]*/ HWND* phwnd)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::CreatePaneWindow \n") );

    ExpectedPtrRet(hwndParent);
    ExpectedPtrRet(phwnd);

    HRESULT hr = S_OK;

    m_wnd.Create(hwndParent);
    *phwnd=m_wnd.m_hWnd;
    ExpectedExprGo(*phwnd);

    m_wnd.ShowWindow( SW_SHOW );
    m_wnd.MoveWindow(x,y,cx,cy,TRUE);
 
OnError:
    return hr;
}

STDMETHODIMP CMWToolWindow::GetDefaultSize(
                    /*[out]*/ SIZE* pSize)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::GetDefaultSize \n") );

    ExpectedPtrRet(pSize);

    pSize->cx = MWT_DEFAULT_CX;
    pSize->cy = MWT_DEFAULT_CY;

    return S_OK;
}

STDMETHODIMP CMWToolWindow::ClosePane(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::ClosePane \n") );
    
    ms_prgMWFrames.Remove(m_srpWindowFrame.p);
    m_wnd.DestroyWindow();
    m_srpWindowFrame.Release();
    m_srpSiteSP.Release();

    return S_OK;
}

STDMETHODIMP CMWToolWindow::LoadViewState(
                    /*[in] */ IStream* pStream)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::LoadViewState \n") );
    return S_OK;
}

STDMETHODIMP CMWToolWindow::SaveViewState(
                    /*[in] */ IStream* pStream)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::SaveViewState \n") );
    return S_OK;
}

STDMETHODIMP CMWToolWindow::TranslateAccelerator(
                    /*[in]*/ LPMSG lpmsg)
{
    //ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::TranslateAccelerator \n") );
    return S_FALSE;
}

//
//                                                   IVsWindowPane interface
// -------------------------------------------------------------------------
//
//                                                             IVsWindowPane
// =========================================================================

// =========================================================================
//                                                         IOleCommandTarget
//
// -------------------------------------------------------------------------
//                                               IOleCommandTarget interface
//
STDMETHODIMP CMWToolWindow::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    //ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMWToolWindow::QueryStatus : this = 0x%x \n"), this );

    ExpectedPtrRet(pguidCmdGroup);
    ExpectedPtrRet(prgCmds);
    ExpectedExprRet(cCmds == 1);
    if (m_fZombie) return E_UNEXPECTED;

    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;
    
    // The following bitwise flags control the state of a command:
    //      OLECMDF_SUPPORTED, OLECMDF_ENABLED, OLECMDF_LATCHED,
    //      OLECMDF_NINCHED, OLECMDF_INVISIBLE, OLECMDF_DEFHIDEONCTXTMENU
    //
    // Common cases are the following:
    //  1. Enable a command --  cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED
    //  2. Disable a command -- cmdf = OLECMDF_SUPPORTED
    //  3. Hide a command --    cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE
    DWORD cmdf = 0;

    if (*pguidCmdGroup == guidMitWinCmdSet)
    {

        cmdf = OLECMDF_SUPPORTED;
        BOOL fEnable = FALSE;

        switch (prgCmds[0].cmdID)
        {

        case icmdNewWindow:
            ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::QueryStatus : icmdNewWindow, this = 0x%x \n"), this );
            cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
            hr   = S_OK;
            break;

        case icmdMWToolWindow:
            ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::QueryStatus : icmdMWToolWindow, this = 0x%x \n"), this );
            return CMWToolWindow::QueryToolWindowCmdStatus(&prgCmds[0].cmdf,pCmdText); 

        default:
            if ((prgCmds[0].cmdID >= icmdListFirst) &&
               (prgCmds[0].cmdID <= icmdListLast) )
            {
                ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::QueryStatus : icmdListXXX, this = 0x%x \n"), this );
                // Query status of the list
                return hr = CMWToolWindow::QueryToolWindowListCmdStatus(
                                        prgCmds[0].cmdID - icmdListFirst, // index  
                                        &prgCmds[0].cmdf, 
                                        pCmdText); 
            }
            
            hr = OLECMDERR_E_NOTSUPPORTED;
            break;
        }
    }
    else if (*pguidCmdGroup == guidVSStd97)
    {
        // indicate supported standard commands
        switch (prgCmds[0].cmdID)
        {
        case cmdidNewWindow:
            ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::QueryStatus : cmdidNewWindow, this = 0x%x \n"), this );
            cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
            hr = S_OK;
            break;
        default:
            hr = OLECMDERR_E_NOTSUPPORTED;
            break;
        }
    }

    prgCmds[0].cmdf = cmdf;
    return hr;
}

STDMETHODIMP CMWToolWindow::Exec(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdexecopt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMWToolWindow::Exec\n") );

    ExpectedPtrRet(pguidCmdGroup);
    if (m_fZombie) return E_UNEXPECTED;

    HRESULT hr = S_OK;

    // IOleCommandTargt::Exec should report errors that may occur
    // in the execution of a command. Therefore clear any existing
    // existing error info first
    _AtlModule.ClearErrorInfo();

    if (*pguidCmdGroup == guidMitWinCmdSet)
    {

        switch (nCmdID)
        {
        case icmdNewWindow:
            ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::Exec : icmdNewWindow \n") );
            hr = CMWToolWindow::OnMWNewWindow();
            break;
        case icmdMWToolWindow:
            {
                ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::Exec : icmdMWToolWindow\n") );
                hr = CMWToolWindow::ExecToolWindowListCmd();
                break;
            }

        default:
            {
                if ((nCmdID >= icmdListFirst) && (nCmdID <= icmdListLast) )
                {
                    ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::Exec : (nCmdID >= icmdListFirst) && (nCmdID <= icmdListLast) \n") );
                    hr = CMWToolWindow::ExecToolWindowListCmd(nCmdID - icmdListFirst);  
                }
                else 
                {
                    ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::Exec : OLECMDERR_E_NOTSUPPORTED \n") );
                    return OLECMDERR_E_NOTSUPPORTED;
                }
                break;
            }
        }

    }
    else if (*pguidCmdGroup == guidVSStd97)
    {
        // execute supported standard commands
        switch (nCmdID)
        {
        case cmdidNewWindow:
            {
                ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::Exec : cmdidNewWindow \n") );
                hr = CMWToolWindow::OnMWNewWindow();
                break;
            }
        default:
            {
                ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::Exec : OLECMDERR_E_NOTSUPPORTED \n") );
                return OLECMDERR_E_NOTSUPPORTED;
            }
        }
    }
    else
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::Exec : OLECMDERR_E_UNKNOWNGROUP \n") );
        return OLECMDERR_E_UNKNOWNGROUP;
    }
    if (FAILED(hr))
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMWToolWindow::Exec : Failed \n") );
        _AtlModule.ReportErrorInfo(hr);
        hr = S_OK;
    }

    return hr;
}

//
//                                               IOleCommandTarget interface
// -------------------------------------------------------------------------

// -------------------------------------------------------------------------
//                                          IOleCommandTarget implementation
//
HRESULT CMWToolWindow::QueryToolWindowCmdStatus(DWORD * pCmdf,
                                                OLECMDTEXT* pCmdText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMWToolWindow::QueryToolWindowCmdStatus \n") );

    ExpectedPtrRet(pCmdf);

    *pCmdf = 0;

    DWORD dwCount = (DWORD) ms_prgMWFrames.Count();  

    if(dwCount < 2)
      *pCmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
    else
      *pCmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE;

    return S_OK;
}
 
 
HRESULT CMWToolWindow::QueryToolWindowListCmdStatus(DWORD dwCmdIndex,
                                            DWORD * pCmdf, 
                                            OLECMDTEXT* pCmdText)
{
    ExpectedPtrRet(pCmdf);
    *pCmdf = 0;

    HRESULT hr = OLECMDERR_E_NOTSUPPORTED;
     
    // if there is only one item in the list then the cascading menu is not shown
    DWORD dwCount = (DWORD) ms_prgMWFrames.Count();
    if ((dwCount <= 1) || (dwCmdIndex >= dwCount ))
        return OLECMDERR_E_NOTSUPPORTED;

    *pCmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
    
    // fill in the text
    if (!pCmdText || (pCmdText->cmdtextf != OLECMDTEXTF_NAME))
        return S_OK;

    ULONG cwchBuffer = pCmdText->cwBuf;
    if (cwchBuffer == 0)
        return S_OK;

    pCmdText->rgwz[0] = 0;
    pCmdText->cwActual = 0;

    IVsWindowFrame* pWindowFrame = ms_prgMWFrames.GetAt(dwCmdIndex);
    _ASSERTE(pWindowFrame != NULL);
    if (!pWindowFrame)
        return OLECMDERR_E_NOTSUPPORTED;
    
    CComVariant varCaption;
    hr = pWindowFrame->GetProperty(VSFPROPID_Caption, &varCaption);
    if(FAILED(hr) || (VT_BSTR != varCaption.vt) || (0 == ::SysStringLen(varCaption.bstrVal)))
        return OLECMDERR_E_NOTSUPPORTED;

    _snwprintf(pCmdText->rgwz, cwchBuffer - 1, L"%u %s", dwCmdIndex+1, varCaption.bstrVal);
    pCmdText->rgwz[cwchBuffer - 1] = L'\0';
    pCmdText->cwActual = lstrlenW(pCmdText->rgwz);
    return S_OK;
}


HRESULT CMWToolWindow::ExecToolWindowListCmd(DWORD dwCmdIndex)
{
    HRESULT hr = E_FAIL;

    // check if a tool has been created 
    if ( (!dwCmdIndex) && (!ms_prgMWFrames.Count())) 
    {
        // get the service
        CComPtr<IMWTool> srpMWSrvc;
        hr = _AtlModule.QueryService(SID_SMWTool, IID_IMWTool, (void**)&srpMWSrvc);
        IfFailRet(hr);
        ExpectedExprRet(srpMWSrvc != NULL);

        hr = srpMWSrvc->CreateMWToolWindow(GUID_NULL, NULL);
        IfFailRet(hr);
    } 

    if(dwCmdIndex < (DWORD)ms_prgMWFrames.Count())
    {
        ms_prgMWFrames.GetAt(dwCmdIndex)->Show();
        hr = S_OK;
    }
  
    return hr;
}

HRESULT CMWToolWindow::OnMWNewWindow()
{
    HRESULT hr = E_FAIL;

    // create a tool
    CComPtr<IMWTool> srpMWSrvc;
    hr = _AtlModule.QueryService(SID_SMWTool, IID_IMWTool, (void**)&srpMWSrvc);
    IfFailRet(hr);
    ExpectedExprRet(srpMWSrvc != NULL);

    hr = srpMWSrvc->CreateMWToolWindow(GUID_NULL, NULL);
    IfFailRet(hr);

    // show it
    IVsWindowFrame* pWindowFrame = ms_prgMWFrames.GetAt(ms_prgMWFrames.Count()-1);
    ExpectedExprRet(pWindowFrame != NULL);
    pWindowFrame->Show();
    hr = S_OK;
  
    return hr;
}
//
//                                          IOleCommandTarget implementation
// -------------------------------------------------------------------------
//
//                                                         IOleCommandTarget
// =========================================================================


// =========================================================================
//                                                      IVsWindowFrameNotify
//
// The interface is not used in the implementation but is here
// to show the messages sent by the environment when frame is shown or 
// destroyed. 
STDMETHODIMP CMWToolWindow::OnShow(/*[in]*/ FRAMESHOW fShow)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::OnShow \n") );

    HRESULT hr = S_OK;

    if(FRAMESHOW_DestroyMultInst == fShow)
    {
        ENVSDK_TRACE(envsdkTraceGeneral, 4, 
                  _T(" CMWToolWindow::OnShow : FRAMESHOW_DestroyMultInst \n") );
    }
    else if(FRAMESHOW_WinShown == fShow)
    {
        ENVSDK_TRACE(envsdkTraceGeneral, 4, 
                  _T(" CMWToolWindow::OnShow : FRAMESHOW_WinShown \n") );
    }

    return hr;
}
//
//                                                      IVsWindowFrameNotify
// =========================================================================


// =========================================================================
//                                                     CMWToolWindow methods
//
HRESULT CMWToolWindow::GetID(DWORD* pdw)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::GetID \n") );

    ExpectedPtrRet(pdw);

    DWORD                   dwID = 1;
    CComPtr<IVsWindowFrame> srpWinFrame;
    CComPtr<IVsUIShell>     srpIVsUIShell   = _AtlModule.GetIVsUIShell(); 
    GUID                    guidToolWnd     = GUID_MWTool;
 
    ExpectedExprRet(srpIVsUIShell != NULL);
    while(SUCCEEDED(srpIVsUIShell->FindToolWindowEx(0, guidToolWnd, dwID, &srpWinFrame)))
    {
      srpWinFrame.Release();
      dwID++;
    }

    *pdw = dwID; 
    return S_OK;
}

// Get the count of the active windows
HRESULT CMWToolWindow::GetCount(DWORD* pdwCount)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolWindow::GetCount \n") );

    ExpectedPtrRet(pdwCount);

    *pdwCount = ms_prgMWFrames.Count(); 
    
    return S_OK;
}
//
//                                                     CMWToolWindow methods
// =========================================================================




