
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cpp : Implementation of CBscPkgPackage
//

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"

/////////////////////////////////////////////////////////////////////////////
// CBscPkgPackage

CBscPkgPackage::CBscPkgPackage()
{
    ATLTRACE(_T("Creating CBscPkgPackage: 0x%X\n"), this);

    m_fZombie = FALSE;
}

CBscPkgPackage::~CBscPkgPackage()
{
    ATLTRACE(_T("Destructing CBscPkgPackage: 0x%X\n"), this);
}


/* static */ 
HRESULT WINAPI CBscPkgPackage::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = _AtlModule.GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    if (FAILED(hr))
        return hr;

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName;
    hr = _AtlModule.GetRegDefaultResourceStrings(&cbstrResDllPath, &cbstrResDllName);
    if (FAILED(hr))
        return hr;

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_BscPkgPackage);
    if (!cbstrCLSID_Package) 
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
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}


/////////////////////////////////////////////////////////////////////////////
// CBscPkgPackage IVsPackage Implementation

STDMETHODIMP CBscPkgPackage::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ATLTRACE(_T("CBscPkgPackage::SetSite\n"));
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
    hr = _AtlModule.LoadUILibrary(CLSID_BscPkgPackage, IDS_E_BADINSTALL);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }

    return S_OK;
}

STDMETHODIMP CBscPkgPackage::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ATLTRACE(_T("CBscPkgPackage::QueryClose\n"));
    _ASSERTE(pCanClose);
    if (!pCanClose)
        return E_POINTER;
    *pCanClose = TRUE;
    return S_OK;
}

STDMETHODIMP CBscPkgPackage::Close(void)
{
    ATLTRACE(_T("CBscPkgPackage::Close\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);

    // set our state for protection
    m_fZombie = TRUE;
    return S_OK;
}

STDMETHODIMP CBscPkgPackage::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ATLTRACE(_T("CBscPkgPackage::GetAutomationObject\n"));
    _ASSERTE(ppDisp);
    if (!ppDisp)
        return E_POINTER;

    *ppDisp = NULL;
    return E_NOTIMPL;
}

STDMETHODIMP CBscPkgPackage::CreateTool(
                    /*[in]*/ REFGUID rguid) 
{ 
    ATLTRACE(_T("CBscPkgPackage::CreateTool\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    return E_NOTIMPL;
}

STDMETHODIMP CBscPkgPackage::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ATLTRACE(_T("CBscPkgPackage::ResetDefaults\n"));

    return E_NOTIMPL;
}

STDMETHODIMP CBscPkgPackage::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage)
{
    ATLTRACE(_T("CBscPkgPackage::GetPropertyPage\n"));

    return E_NOTIMPL;
}


///////////////////////////////////////////////////////////////////////////////
// CBscPkgPackage IOleCommandTarget Implementation

#pragma warning(disable:4065) // switch statement contains 'default' but no 'case' labels

STDMETHODIMP CBscPkgPackage::QueryStatus(
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

    if (*pguidCmdGroup == guidBscPkgCmdSet)
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
            // *********************************************
            // <--- ADD YOUR COMMAND HANDLING HERE. --->
            // *********************************************

            default:
                return OLECMDERR_E_NOTSUPPORTED;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    prgCmds[0].cmdf = cmdf;
    return S_OK;
}

STDMETHODIMP CBscPkgPackage::Exec(
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

    if (*pguidCmdGroup == guidBscPkgCmdSet)
    {
        // IOleCommandTargt::Exec should report errors that may occur
        // in the execution of a command. Therefore clear any existing
        // existing error info first
        _AtlModule.ClearErrorInfo();

        switch (nCmdID)
        {
            // *********************************************
            // <--- ADD YOUR COMMAND HANDLING HERE. --->
            // *********************************************

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
// CBscPkgPackage IServiceProvider Implementation

STDMETHODIMP CBscPkgPackage::QueryService(
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
