
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cpp : Implementation of CDSRefToolPackage
//

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"
#include "dsreftoolwindow.h"

/////////////////////////////////////////////////////////////////////////////
// CDSRefToolPackage

CDSRefToolPackage::CDSRefToolPackage()
{
    ATLTRACE(_T("Creating CDSRefToolPackage: 0x%X\n"), this);

    m_fZombie = FALSE;
}

CDSRefToolPackage::~CDSRefToolPackage()
{
    ATLTRACE(_T("Destructing CDSRefToolPackage: 0x%X\n"), this);
}

/* static */ 
HRESULT WINAPI CDSRefToolPackage::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;    
    hr = _AtlModule.GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    if FAILED(hr)
        return hr;

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName;
    hr = _AtlModule.GetRegDefaultResourceStrings(&cbstrResDllPath, &cbstrResDllName);
    if FAILED(hr)
        return hr;

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_DSRefToolPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_DSRefToolWindow(GUID_DSRefToolWindow);
    if (!cbstrGUID_DSRefToolWindow) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_TaskList(GUID_TaskList);
    if (!cbstrGUID_TaskList) 
        return E_OUTOFMEMORY;

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    _ultow(IDS_PACKAGE_LOAD_KEY,        wszIDS_PACKAGE_LOAD_KEY,        10);

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"RESOURCE_PATH",                  cbstrResDllPath},
        {L"RESOURCE_DLL",                   cbstrResDllName},
        {L"CLSID_Package",                  cbstrCLSID_Package},
        {L"GUID_DSRefToolWindow",           cbstrGUID_DSRefToolWindow},
        {L"GUID_TaskList",                  cbstrGUID_TaskList},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}


HRESULT CDSRefToolPackage::ShowToolWinFrame(void)
{ 
    HRESULT hr = NOERROR;

    // it is important to delay creating tool windows for performance reasons.
    // a good strategy is to wait until the first time that the tool window
    // needs to be shown. this is why we put the call to CreateTool in ShowToolWinFrame.
    if (!m_srpToolWinFrame)
        hr = CreateTool(GUID_DSRefToolWindow);    // call our own IVsPackage::CreateTool method
    if (SUCCEEDED(hr))
        hr = m_srpToolWinFrame->Show();
    return hr;
}

/////////////////////////////////////////////////////////////////////////////
// CDSRefToolPackage IVsPackage Implementation

STDMETHODIMP CDSRefToolPackage::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ATLTRACE(_T("CDSRefToolPackage::SetSite\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;    // protect against multiple SetSite calls

    HRESULT hr;

    hr = _AtlModule.SetModuleSite(pSP);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }

    // Load the UI Library.
    // This call will initialize "_AtlModule.m_hInstResource" to point to our 
    // localized satellite DLL.
    // Note that IDS_E_BADINSTALL is the id of a string resource within the 
    // package dll itself.
    hr = _AtlModule.LoadUILibrary(CLSID_DSRefToolPackage, IDS_E_BADINSTALL);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }

    return S_OK;
}

STDMETHODIMP CDSRefToolPackage::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ATLTRACE(_T("CDSRefToolPackage::QueryClose\n"));
    _ASSERTE(pCanClose);
    if (!pCanClose)
        return E_POINTER;

    *pCanClose = TRUE;
    return S_OK;
}

STDMETHODIMP CDSRefToolPackage::Close(void)
{
    ATLTRACE(_T("CDSRefToolPackage::Close\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    // set our state for protection
    m_fZombie = TRUE;

    m_srpToolWindow.Release();
    m_srpToolWinFrame.Release();
    
    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);
    
    return S_OK;
}

STDMETHODIMP CDSRefToolPackage::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ATLTRACE(_T("CDSRefToolPackage::GetAutomationObject\n"));
    _ASSERTE(ppDisp);
    if (!ppDisp)
        return E_POINTER;

    *ppDisp = NULL;
    return E_NOTIMPL;
}

STDMETHODIMP CDSRefToolPackage::CreateTool(
                    /*[in]*/ REFGUID rguid) 
{ 
    ATLTRACE(_T("CDSRefToolPackage::CreateTool\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;
    
    if (rguid == GUID_DSRefToolWindow)
    {
        CComPtr<IVsUIShell>    srpShell;

        // now get the IVsUIShell interface so we can create a tool window
        //
        HRESULT hr = _AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpShell);

        if (SUCCEEDED(hr))
        {
            USES_CONVERSION;
            BOOL    fDefaultPosition = TRUE;
            CComBSTR bstrTitle;
            TCHAR szTitle[128];
            
            if (! ::LoadString(_AtlBaseModule.GetResourceInstance(), IDS_WINDOW_TITLE, szTitle, countof(szTitle)))
            {
                _ASSERTE(FALSE);
                return HRESULT_FROM_WIN32(::GetLastError());
            }

            hr = CComObject<CDSRefToolWindow>::CreateInstance(&m_pToolWinObj);
            _ASSERTE((SUCCEEDED(hr) && m_pToolWinObj) || !_T("Failed to create notes window"));
            if (!m_pToolWinObj)
                return E_OUTOFMEMORY;

            hr = m_pToolWinObj->QueryInterface(IID_IVsWindowPane, (void**)&m_srpToolWindow);
            _ASSERTE(SUCCEEDED(hr) || !_T("Could not get IVsWindowPane from notes toolwindow"));

            hr = srpShell->CreateToolWindow(
                /* [in] VSCREATETOOLWIN grfCTW   */ CTW_fInitNew | CTW_fForceCreate,
                /* [in] DWORD dwToolWindowId     */ NULL,
                /* [in] IUnknown *punkTool       */ (IUnknown*)m_srpToolWindow.p,
                /* [in] REFCLSID rclsidTool      */ GUID_NULL,
                /* [in] REFGUID rguidPersistenceSlot*/ GUID_DSRefToolWindow,
                /* [in] REFGUID rguidAutoActivate*/ GUID_NULL,
                /* [in] IServiceProvider *pSP    */ NULL,
                /* [in] LPCOLESTR pszCaption     */ T2COLE(szTitle),
                /* [out] BOOL *pfDefaultPosition */ &fDefaultPosition,
                /* [out] IVsWindowFrame **ppWindowFrame*/ &m_srpToolWinFrame);
        
            // if CreateToolWindow failed let's give the user a useful error message
            if (FAILED(hr))
            {
                _AtlModule.SetErrorInfo(hr, IDS_E_CANTCREATETOOL, 0);
                return hr;
            }
            hr = m_srpToolWinFrame->Show();

            return hr;
        }
    }


    return E_NOTIMPL;
}

STDMETHODIMP CDSRefToolPackage::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ATLTRACE(_T("CDSRefToolPackage::ResetDefaults\n"));

    return E_NOTIMPL;
}

STDMETHODIMP CDSRefToolPackage::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage)
{
    ATLTRACE(_T("CDSRefToolPackage::GetPropertyPage\n"));

    return E_NOTIMPL;
}


///////////////////////////////////////////////////////////////////////////////
// CDSRefToolPackage IOleCommandTarget Implementation

#pragma warning(disable:4065) // switch statement contains 'default' but no 'case' labels

STDMETHODIMP CDSRefToolPackage::QueryStatus(
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

    if (*pguidCmdGroup == guidDSRefToolCmdSet)
    {
        // The following bitwise flags control the state of a command:
        //        OLECMDF_SUPPORTED, OLECMDF_ENABLED, OLECMDF_LATCHED,
        //        OLECMDF_NINCHED, OLECMDF_INVISIBLE, OLECMDF_DEFHIDEONCTXTMENU
        //
        // Common cases are the following:
        //    1. Enable a command --  cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED
        //    2. Disable a command -- cmdf = OLECMDF_SUPPORTED
        //    3. Hide a command --    cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE
        cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;

        switch (prgCmds[0].cmdID)
        {
        case icmdDSRefTool:
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

STDMETHODIMP CDSRefToolPackage::Exec(
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

    if (*pguidCmdGroup == guidDSRefToolCmdSet)
    {
        // IOleCommandTargt::Exec should report errors that may occur
        // in the execution of a command. Therefore clear any existing
        // existing error info first
        _AtlModule.ClearErrorInfo();

        switch (nCmdID)
        {
            
        case icmdDSRefTool:
            hr = ShowToolWinFrame();
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


///////////////////////////////////////////////////////////////////////////////
// CDSRefToolPackage IServiceProvider Implementation

STDMETHODIMP CDSRefToolPackage::QueryService(
                    /*[in] */ REFGUID rsid,
                    /*[in] */ REFIID  riid,
                    /*[out]*/ void**  ppvObject)
{
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(ppvObject);

    if (ppvObject == NULL)
        return E_POINTER;

    HRESULT hr = E_NOINTERFACE;
    *ppvObject = NULL;

    return hr;
}
