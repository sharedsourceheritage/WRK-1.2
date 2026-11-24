
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cpp : Implementation of CMitWinPackage
//

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"

/////////////////////////////////////////////////////////////////////////////
// CMitWinPackage

CMitWinPackage::CMitWinPackage()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, _T(" CMitWinPackage::CMitWinPackage : this = 0x%x \n"), this );

    m_srpMWSrvc = NULL;
    m_fZombie = FALSE;
}


CMitWinPackage::~CMitWinPackage()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, _T(" CMitWinPackage::~CMitWinPackage \n") );
}



/* static */ 
HRESULT WINAPI CMitWinPackage::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = _AtlModule.GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    IfFailRet(hr);

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName;
    hr = _AtlModule.GetRegDefaultResourceStrings(&cbstrResDllPath, &cbstrResDllName);
    IfFailRet(hr);

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_MitWinPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrSID_SMWTool(SID_SMWTool);
    if (!cbstrSID_SMWTool) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_MWTool(GUID_MWTool);
    if (!cbstrGUID_MWTool) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_TaskList(GUID_TaskList);
    if (!cbstrGUID_TaskList) 
        return E_OUTOFMEMORY;

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    WCHAR wszIDS_OFFICIALNAME[iMaxResIdLen];
    WCHAR wszIDS_PRODUCTDETAILS[iMaxResIdLen];
    _ultow(IDS_PACKAGE_LOAD_KEY,        wszIDS_PACKAGE_LOAD_KEY,        10);
    _ultow(IDS_OFFICIALNAME,            wszIDS_OFFICIALNAME,            10);
    _ultow(IDS_PRODUCTDETAILS,          wszIDS_PRODUCTDETAILS,          10);

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"RESOURCE_PATH",                  cbstrResDllPath},
        {L"RESOURCE_DLL",                   cbstrResDllName},
        {L"CLSID_Package",                  cbstrCLSID_Package},
        {L"SID_SMWTool",                    cbstrSID_SMWTool},
        {L"GUID_MWTool",                    cbstrGUID_MWTool},
        {L"GUID_TaskList",                  cbstrGUID_TaskList},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_OFFICIALNAME",               wszIDS_OFFICIALNAME},
        {L"IDS_PRODUCTDETAILS",             wszIDS_PRODUCTDETAILS},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}


/////////////////////////////////////////////////////////////////////////////
// CMitWinPackage IVsPackage Implementation

STDMETHODIMP CMitWinPackage::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::SetSite : this = 0x%x \n"), this );

    ExpectedExprRet(!m_fZombie);
    ExpectedPtrRet(pSP);

    HRESULT hr;

    hr = _AtlModule.SetModuleSite(pSP);
    IfFailRet(hr);

    // Load the UI Library.
    // This call will initialize "_AtlModule.m_hInstResource" to point to our 
    // localized satellite DLL.
    // Note that IDS_E_BADINSTALL is the id of a string resource within the 
    // package dll itself.
    hr = _AtlModule.LoadUILibrary(CLSID_MitWinPackage, IDS_E_BADINSTALL);
    IfFailRet(hr);

    CComPtr<IProfferService> srpProffer;
    if ((SUCCEEDED(_AtlModule.QueryService(SID_SProfferService, IID_IProfferService, (void **)&srpProffer))) && (srpProffer != NULL))
    {
        DWORD dwCookie;
        srpProffer->ProfferService(SID_SMWTool, (IServiceProvider *) this, &dwCookie);
    }

    return S_OK;
}


STDMETHODIMP CMitWinPackage::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::QueryClose : this = 0x%x \n"), this );

    ExpectedPtrRet(pCanClose);

    *pCanClose = TRUE;
    return S_OK;
}


STDMETHODIMP CMitWinPackage::Close(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::Close : this = 0x%x \n"), this );

    ExpectedExprRet(!m_fZombie);

    // set our state for protection
    m_fZombie = TRUE;

    m_srpMWSrvc.Release();
    
    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);

    return S_OK;
}


STDMETHODIMP CMitWinPackage::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::GetAutomationObject : this = 0x%x \n"), this );
    ExpectedPtrRet(ppDisp);

    *ppDisp = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CMitWinPackage::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::ResetDefaults : this = 0x%x \n"), this );

    return E_NOTIMPL;
}


STDMETHODIMP CMitWinPackage::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::GetPropertyPage : this = 0x%x \n"), this );

    return E_NOTIMPL;
}


STDMETHODIMP CMitWinPackage::CreateTool(
                    /*[in]*/ REFGUID rguid) 
{ 
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::CreateTool : this = 0x%x \n"), this );

    return CreateToolWindow(rguid, 0);
}


//--------------------------------------------------------
//IVsToolWindowFactory
//--------------------------------------------------------

STDMETHODIMP CMitWinPackage::CreateToolWindow(
                    /*[in]*/ REFGUID rguidPersistenceSlot, 
                    /*[in]*/ DWORD dwToolWindowId)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::CreateToolWindow : this = 0x%x \n"), this );

    ExpectedExprRet(!m_fZombie);
    HRESULT hr;

    if ( !m_srpMWSrvc ) 
    {
        hr = CreateMitWinService();
        IfFailRet(hr);
    }
    ExpectedExprRet(m_srpMWSrvc != NULL);
    hr = m_srpMWSrvc->CreateMWToolWindow(rguidPersistenceSlot, dwToolWindowId);

    return hr;
}


///////////////////////////////////////////////////////////////////////////////
// CMitWinPackage IOleCommandTarget Implementation

STDMETHODIMP CMitWinPackage::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    //ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::QueryStatus : this = 0x%x \n"), this );

    ExpectedExprRet(!m_fZombie);
    ExpectedPtrRet(pguidCmdGroup);
    ExpectedPtrRet(prgCmds);
    ExpectedExprRet(cCmds == 1);

    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;
    
    DWORD cmdf = 0;
        // The following bitwise flags control the state of a command:
        //      OLECMDF_SUPPORTED, OLECMDF_ENABLED, OLECMDF_LATCHED,
        //      OLECMDF_NINCHED, OLECMDF_INVISIBLE, OLECMDF_DEFHIDEONCTXTMENU
        //
        // Common cases are the following:
        //  1. Enable a command --  cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED
        //  2. Disable a command -- cmdf = OLECMDF_SUPPORTED
        //  3. Hide a command --    cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE

    if (*pguidCmdGroup == guidMitWinCmdSet)
    {

        cmdf = OLECMDF_SUPPORTED;
        BOOL fEnable = FALSE;

        switch (prgCmds[0].cmdID)
        {
        case icmdNewWindow:
            ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMitWinPackage::QueryStatus : icmdNewWindow, this = 0x%x \n"), this );
            cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE;
            break;

        case icmdMWToolWindow:
            ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMitWinPackage::QueryStatus : icmdMWToolWindow, this = 0x%x \n"), this );
            return CMWToolWindow::QueryToolWindowCmdStatus(
                                        &prgCmds[0].cmdf, 
                                        pCmdText); 

        default:
            if ((prgCmds[0].cmdID >= icmdListFirst) &&
               (prgCmds[0].cmdID <= icmdListLast) )
            {
                ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T(" CMitWinPackage::QueryStatus : icmdListXXX, this = 0x%x \n"), this );
                // Query status of the list
                return CMWToolWindow::QueryToolWindowListCmdStatus(
                                        prgCmds[0].cmdID - icmdListFirst,   
                                        &prgCmds[0].cmdf, 
                                        pCmdText); 
            }
            
            hr = OLECMDERR_E_NOTSUPPORTED;
            break;
        }
    }

    prgCmds[0].cmdf = cmdf;
    return hr;
}

STDMETHODIMP CMitWinPackage::Exec(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdexecopt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CMitWinPackage::Exec\n") );
    ExpectedExprRet(!m_fZombie);
    ExpectedPtrRet(pguidCmdGroup);

    HRESULT hr = S_OK;

    // IOleCommandTargt::Exec should report errors that may occur
    // in the execution of a command. Therefore clear any existing
    // existing error info first
    _AtlModule.ClearErrorInfo();

    if (*pguidCmdGroup == guidMitWinCmdSet)
    {
        switch (nCmdID)
        {
        case icmdMWToolWindow:
            {                
                ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T("MitWin: CMitWinPackage::Exec : icmdMWToolWindow \n") );
                hr = CMWToolWindow::ExecToolWindowListCmd();
                break;
            }

        default:
            {
                if ((nCmdID >= icmdListFirst) && (nCmdID <= icmdListLast) )
                {
                    ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T("MitWin: CMitWinPackage::Exec : (nCmdID >= icmdListFirst) && (nCmdID <= icmdListLast) \n") );
                    hr = CMWToolWindow::ExecToolWindowListCmd(nCmdID - icmdListFirst);  
                }
                else
                {
                    ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T("MitWin: CMitWinPackage::Exec : OLECMDERR_E_NOTSUPPORTED \n") );
                    return OLECMDERR_E_NOTSUPPORTED;
                }
                break;
            }
        }
    }
    else
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T("MitWin: CMitWinPackage::Exec : OLECMDERR_E_UNKNOWNGROUP \n") );
        return OLECMDERR_E_UNKNOWNGROUP;
    }
    if (FAILED(hr))
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T("MitWin: CMitWinPackage::Exec : Failed \n") );
        _AtlModule.ReportErrorInfo(hr);
        hr = S_OK;
    }

    return hr;
}


///////////////////////////////////////////////////////////////////////////////
// CMitWinPackage IServiceProvider Implementation

STDMETHODIMP CMitWinPackage::QueryService(
                    /*[in] */ REFGUID rsid,
                    /*[in] */ REFIID  riid,
                    /*[out]*/ void**  ppvObject)
{

    ExpectedExprRet(!m_fZombie);
    ExpectedPtrRet(ppvObject);

    HRESULT hr = E_NOINTERFACE;
    *ppvObject = NULL;

    // We provide one service from our package.
    if (rsid == SID_SMWTool)
    {
        if (!m_srpMWSrvc) 
        {
            hr = CreateMitWinService();
            if (FAILED(hr)) return hr;
        }
        ExpectedExprRet(m_srpMWSrvc != NULL);
        hr = m_srpMWSrvc->QueryInterface(riid, ppvObject );
    }

    return hr;
}


STDMETHODIMP CMitWinPackage::CreateMitWinService()
{
    if(! m_srpMWSrvc ) m_srpMWSrvc = new CMWToolService( this ); 
    // Note: assignment to a smart pointer does an AddRef()
    
    if( ! m_srpMWSrvc ) return E_OUTOFMEMORY;
    
    return S_OK;
}