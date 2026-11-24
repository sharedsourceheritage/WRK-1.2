
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// vspkg.cpp : Implementation of CVsPackage and interfaces

#include "stdafx.h"
#include "guids.h"
#include "EdtFact.h"

/////////////////////////////////////////////////////////////////////////////
// CVsPackage

CVsPackage::CVsPackage()
{
    ATLTRACE(TEXT("Constructing CVsPackage: 0x%X\n"), this);
    m_fZombie = FALSE;
}

CVsPackage::~CVsPackage()
{
    ATLTRACE(TEXT("Destructing CVsPackage: 0x%X\n"), this);
}


/*****************************************************************************
** IVsPackage Implementation
*****************************************************************************/



/* static */ 
HRESULT WINAPI CVsPackage::UpdateRegistry(
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

    // get the TEMPLATE_PATH
    CComBSTR cbstrTemplatePath;
    hr = _AtlModule.GetRegDefaultTemplatePath(&cbstrTemplatePath);
    if FAILED(hr)
        return hr;

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_BscEdtPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_BscEditorFactory(GUID_BscEditorFactory);
    if (!cbstrGUID_BscEditorFactory) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrCLSID_MiscFilesProject(CLSID_MiscellaneousFilesProject);
    if (!cbstrCLSID_MiscFilesProject) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrLOGVIEWID_TextView(LOGVIEWID_TextView);
    if (!cbstrLOGVIEWID_TextView)
        return E_OUTOFMEMORY;

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    WCHAR wszIDS_OFFICIALNAME[iMaxResIdLen];
    WCHAR wszIDS_PRODUCTDETAILS[iMaxResIdLen];
    WCHAR wszIDS_NEWFILE_TEMPLATES_ENTRY[iMaxResIdLen];
    _ultow(IDS_PACKAGE_LOAD_KEY,        wszIDS_PACKAGE_LOAD_KEY,        10);
    _ultow(IDS_OFFICIALNAME,            wszIDS_OFFICIALNAME,            10);
    _ultow(IDS_PRODUCTDETAILS,          wszIDS_PRODUCTDETAILS,          10);
    _ultow(IDS_NEWFILE_TEMPLATES_ENTRY, wszIDS_NEWFILE_TEMPLATES_ENTRY, 10);

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"RESOURCE_PATH",                  cbstrResDllPath},
        {L"RESOURCE_DLL",                   cbstrResDllName},
        {L"TEMPLATE_PATH",                  cbstrTemplatePath},
        {L"CLSID_Package",                  cbstrCLSID_Package},
        {L"CLSID_MiscFilesProject",         cbstrCLSID_MiscFilesProject},
        {L"GUID_BscEditorFactory",          cbstrGUID_BscEditorFactory},
        {L"LOGVIEWID_TextView",             cbstrLOGVIEWID_TextView},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_OFFICIALNAME",               wszIDS_OFFICIALNAME},
        {L"IDS_PRODUCTDETAILS",             wszIDS_PRODUCTDETAILS},
        {L"IDS_NEWFILE_TEMPLATES_ENTRY",    wszIDS_NEWFILE_TEMPLATES_ENTRY},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResource(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}


STDMETHODIMP CVsPackage::SetSite(IServiceProvider *pSP)
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    m_srpPkgSiteSP = pSP;            // Note: assignment to a smart pointer does an AddRef()

    HRESULT hr = S_OK;

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
    hr = _AtlModule.LoadUILibrary(CLSID_BscEdtPackage, IDS_E_BADINSTALL);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }
    
    // create editor factory
    if (m_srpEdFact == NULL) 
    {
        CComObject<CBscEditorFactory> *pEdFact = new CComObject<CBscEditorFactory>;
        if (NULL == pEdFact)
            return E_OUTOFMEMORY;

        if (!pEdFact->FInit(this))
            return E_UNEXPECTED;

        m_srpEdFact = (IVsEditorFactory *) pEdFact;    // Note: assignment to a smart pointer does an AddRef()
    }

    // QS for IVsRegisterEditors, register our editor factory
    CComPtr<IVsRegisterEditors> srpRegEd;
    if ((SUCCEEDED(m_srpPkgSiteSP->QueryService(SID_SVsRegisterEditors, 
                                                IID_IVsRegisterEditors, 
                                                (void **)&srpRegEd ))) && 
        (srpRegEd != NULL))
    {
        ATLTRACE(TEXT(">> CVsPackage, registering editor factory.\n"));
        if (FAILED(srpRegEd->RegisterEditor(GUID_BscEditorFactory, 
                                            m_srpEdFact, &m_dwEditorCookie))) 
        {
            ATLTRACE(TEXT(">> CVsPackage, RegisterEditor() failed.\n"));
            return E_FAIL;
        }
    }

    return S_OK;
}

STDMETHODIMP CVsPackage::QueryClose(BOOL *pCanClose)
{
    _ASSERTE(pCanClose != NULL);
    if (!pCanClose)
        return E_POINTER;
    *pCanClose = TRUE;
    return NOERROR;
}

STDMETHODIMP CVsPackage::Close()
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard
    
    m_fZombie = TRUE;

    // A package should not call IProfferService::RevokeService() in its Close() implementation 
    // (Note: the debug version of the Shell will Assert to help catch offenders). All services 
    // are expected to remain available for the entire duration of calling Close() on all packages. 
    // The Shell will automatically revoke and release the services after all packages have been 
    // called Close().

    // QS for IVsRegisterEditors, unregister our editor factory
    CComPtr<IVsRegisterEditors> srpRegEd;
    if ((SUCCEEDED(m_srpPkgSiteSP->QueryService(SID_SVsRegisterEditors, 
                                                IID_IVsRegisterEditors, 
                                                (void **)&srpRegEd ))) && 
        (srpRegEd != NULL))
    {
        ATLTRACE(TEXT(">> CVsPackage, unregistering editor factory.\n"));
        if (FAILED(srpRegEd->UnregisterEditor(m_dwEditorCookie))) 
        {
            ATLTRACE(TEXT(">> CVsPackage, UnregisterEditor() failed.\n"));
            return E_FAIL;
        }
    }
    m_srpEdFact.Release();            // release our editor factory, destroys itself when ref count reaches zero
    m_srpUIShell.Release();            // release our ptr to the shell's ui service
    m_srpPkgSiteSP.Release();        // release our ptr to service provider

    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);

    return NOERROR;
}

STDMETHODIMP CVsPackage::GetAutomationObject(LPCOLESTR pszPropName, IDispatch **ppDisp)
{
    _ASSERTE(ppDisp != NULL);
    if (!ppDisp)
        return E_POINTER;
    *ppDisp = NULL;
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    return E_NOTIMPL;
}

STDMETHODIMP CVsPackage::CreateTool(REFGUID rguid) 
{ 
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    return E_NOTIMPL;
}

STDMETHODIMP CVsPackage::ResetDefaults(PKGRESETFLAGS dwFlags) { return NOERROR; }

STDMETHODIMP CVsPackage::GetPropertyPage(REFGUID rguidPage, VSPROPSHEETPAGE *ppage) { return E_NOTIMPL; }


/////////////////////////////////////////////////////////////////////////////



HRESULT CVsPackage::GetShellUISvc(
                            IVsUIShell **ppSvc)
{
    _ASSERTE(ppSvc != NULL);
    if (!ppSvc)
        return E_POINTER;
    *ppSvc = NULL;
    HRESULT hr = NOERROR;

    // get it anc cache if if we don't have it already
    if (!m_srpUIShell.p)
    {
        _ASSERTE(m_srpPkgSiteSP.p);
        hr = m_srpPkgSiteSP->QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **) &m_srpUIShell);
        if (FAILED(hr))
            return hr;
        if (!m_srpUIShell.p)
            return E_UNEXPECTED;
    }

    *ppSvc = m_srpUIShell.p;
    if (*ppSvc)
        (*ppSvc)->AddRef();
        
    return hr;
}



HRESULT CVsPackage::GetShellSvc(
                            REFGUID rsid,
                            REFIID riid,
                            void **ppv)
{
    _ASSERTE(m_srpPkgSiteSP.p);
    return m_srpPkgSiteSP->QueryService(rsid, riid, ppv);
}    
