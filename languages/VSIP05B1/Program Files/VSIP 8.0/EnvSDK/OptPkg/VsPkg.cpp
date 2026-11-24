
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cpp : Implementation of COptPkgPackage
//

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"
#include "OptPpg.h"



/////////////////////////////////////////////////////////////////////////////
// COptPkgPackage

COptPkgPackage::COptPkgPackage()
{
    ATLTRACE(_T("Creating COptPkgPackage: 0x%X\n"), this);

    m_fZombie = FALSE;
}

COptPkgPackage::~COptPkgPackage()
{
    ATLTRACE(_T("Destructing COptPkgPackage: 0x%X\n"), this);
}



/* static */ 
HRESULT WINAPI COptPkgPackage::UpdateRegistry(
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
    CComBSTR cbstrCLSID_Package(CLSID_OptPkgPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrguidOptionsPage(guidOptionsPage);
    if (!cbstrguidOptionsPage) 
        return E_OUTOFMEMORY;

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    WCHAR wszIDS_OFFICIALNAME[iMaxResIdLen];
    WCHAR wszIDS_PRODUCTDETAILS[iMaxResIdLen];
    WCHAR wszIDS_PACKAGE[iMaxResIdLen];
    WCHAR wszIDS_GENERAL[iMaxResIdLen];
    _ultow(IDS_PACKAGE_LOAD_KEY,        wszIDS_PACKAGE_LOAD_KEY,        10);
    _ultow(IDS_OFFICIALNAME,            wszIDS_OFFICIALNAME,            10);
    _ultow(IDS_PRODUCTDETAILS,          wszIDS_PRODUCTDETAILS,          10);
    _ultow(IDS_PACKAGE,                 wszIDS_PACKAGE,                 10);
    _ultow(IDS_GENERAL,                 wszIDS_GENERAL,                 10);

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"RESOURCE_PATH",                  cbstrResDllPath},
        {L"RESOURCE_DLL",                   cbstrResDllName},
        {L"CLSID_Package",                  cbstrCLSID_Package},
        {L"guidOptionsPage",                cbstrguidOptionsPage},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_OFFICIALNAME",               wszIDS_OFFICIALNAME},
        {L"IDS_PRODUCTDETAILS",             wszIDS_PRODUCTDETAILS},
        {L"IDS_PACKAGE",                    wszIDS_PACKAGE},
        {L"IDS_GENERAL",                    wszIDS_GENERAL},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}


/////////////////////////////////////////////////////////////////////////////
// COptPkgPackage IVsPackage Implementation

STDMETHODIMP COptPkgPackage::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ATLTRACE(_T("COptPkgPackage::SetSite\n"));
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
    // This call will initialize "_AtlBaseModule.m_hInstResource" to point to our 
    // localized satellite DLL.
    // Note that IDS_E_BADINSTALL is the id of a string resource within the 
    // package dll itself.
    hr = _AtlModule.LoadUILibrary(CLSID_OptPkgPackage, IDS_E_BADINSTALL);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }

    return S_OK;
}

STDMETHODIMP COptPkgPackage::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ATLTRACE(_T("COptPkgPackage::QueryClose\n"));
    _ASSERTE(pCanClose);

    *pCanClose = TRUE;
    return S_OK;
}

STDMETHODIMP COptPkgPackage::Close(void)
{
    ATLTRACE(_T("COptPkgPackage::Close\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    m_srpOptionsPreferences.Release();
    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);

    // set our state for protection
    m_fZombie = TRUE;
    return S_OK;
}

STDMETHODIMP COptPkgPackage::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ATLTRACE(_T("COptPkgPackage::GetAutomationObject\n"));
    _ASSERTE(ppDisp);

    *ppDisp = NULL;

    if(_wcsicmp(pszPropName, L"OptionsSample.General") == 0)
    {
        CComPtr<_OptionsPreferences> srpOptionsPreferences;
        HRESULT hr = GetOptionsPreferences(&srpOptionsPreferences);
        _ASSERTE(SUCCEEDED(hr));
        if (FAILED(hr))
            return hr;
        _ASSERTE(srpOptionsPreferences != NULL);
        if (!srpOptionsPreferences)
            return E_UNEXPECTED;

        return srpOptionsPreferences->QueryInterface(IID_IDispatch, (void**)ppDisp);
    }     
    
    return E_NOTIMPL;
}

STDMETHODIMP COptPkgPackage::CreateTool(
                    /*[in]*/ REFGUID rguid) 
{ 
    ATLTRACE(_T("COptPkgPackage::CreateTool\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    return E_NOTIMPL;
}

STDMETHODIMP COptPkgPackage::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ATLTRACE(_T("COptPkgPackage::ResetDefaults\n"));

    return E_NOTIMPL;
}

STDMETHODIMP COptPkgPackage::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage)
{
    ATLTRACE(_T("COptPkgPackage::GetPropertyPage\n"));

    if (rguidPage == guidOptionsPage)
    {
        CComPtr<_OptionsPreferences> srpOptionsPreferences;
        HRESULT hr = GetOptionsPreferences(&srpOptionsPreferences);
        _ASSERTE(SUCCEEDED(hr));
        if (FAILED(hr))
            return hr;
        _ASSERTE(srpOptionsPreferences != NULL);
        if (!srpOptionsPreferences)
            return E_UNEXPECTED;

        return COptionsPpg::GetPage(srpOptionsPreferences, ppage);
    }
    else
        return E_FAIL;
}


///////////////////////////////////////////////////////////////////////////////
// COptPkgPackage IOleCommandTarget Implementation

STDMETHODIMP COptPkgPackage::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    return OLECMDERR_E_UNKNOWNGROUP;
}

STDMETHODIMP COptPkgPackage::Exec(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdexecopt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut)
{
    return OLECMDERR_E_UNKNOWNGROUP;
}


///////////////////////////////////////////////////////////////////////////////
// COptPkgPackage IServiceProvider Implementation

STDMETHODIMP COptPkgPackage::QueryService(
                    /*[in] */ REFGUID rsid,
                    /*[in] */ REFIID  riid,
                    /*[out]*/ void**  ppvObject)
{
    return E_NOINTERFACE;
}


STDMETHODIMP COptPkgPackage::GetOptionsPreferences(    
    /* [out] */ _OptionsPreferences** ppOptionsPreferences)
{
    HRESULT hr = S_OK;
    if (!m_srpOptionsPreferences)
    {
        hr = COptionsPreferences::CreateInstance(&m_srpOptionsPreferences);
        _ASSERTE(SUCCEEDED(hr));
        if (FAILED(hr))
            return hr;
        _ASSERTE(m_srpOptionsPreferences != NULL);
        if (!m_srpOptionsPreferences)
            return E_UNEXPECTED;
    }
    hr = m_srpOptionsPreferences->QueryInterface(IID__OptionsPreferences, (void**)ppOptionsPreferences);
    return hr;
}
