
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// vspkg.cpp : Implementation of CVsPackage and interfaces

#include "stdafx.h"
#include "PrjInc.h"

// Our one and only Package object
//
CVsPackage*                CVsPackage::g_pPkg = NULL;
PUIHierarchyImageList    CVsPackage::g_pil = NULL;

// Global execution context
CExecutionCtx CVsPackage::g_executionCtx;


static ImageListItem g_rgImageListItems[] ={

    {&GUID_NODETYPE_FileVw_Project,        IDI_FILEVW_PROJECT},
    {&GUID_NODETYPE_FileVw_File,        IDI_FILEVW_FILE},
    {&GUID_NODETYPE_FileVw_Folder,        IDI_FILEVW_FOLDER},    
    {NULL,                                0}
};

static const UINT    cxIMAGE = VSHPROJICON_WIDTH;
static const UINT    cyIMAGE = VSHPROJICON_WIDTH;


/////////////////////////////////////////////////////////////////////////////
// CVsPackage

CVsPackage::CVsPackage()
{
    ATLTRACE(TEXT("Constructing CVsPackage: 0x%X\n"), this);
    m_fZombie = FALSE;
    m_dwProjectCookie = NULL;
    CVsPackage::g_pPkg = this;
}

CVsPackage::~CVsPackage()
{
    ATLTRACE(TEXT("Destructing CVsPackage: 0x%X\n"), this);
    ASSERT(CVsPackage::g_pPkg == this);
    DestroyImageList();
    CVsPackage::g_pPkg = NULL;
}

//-----------------------------------------------------------------------------
// does creation code that could possibly fail -- which would mean that
//    the CoCreate called to make this object would fail
//-----------------------------------------------------------------------------
HRESULT CVsPackage::FinalConstruct()
{
    HRESULT        hr = CreateImageList();

    if (FAILED(hr))
    {
        DestroyImageList();
    }

    return hr;
}


//-----------------------------------------------------------------------------
// Just init's our 1 DLL image list.
//-----------------------------------------------------------------------------
HRESULT CVsPackage::CreateImageList()
{
    HRESULT        hr = S_OK;
    ASSERT(!g_pil);    // we should only be constructed once

    // now we need to create the image list we use
    //
    if (!g_pil)
    {
        // Create ImageList
        //
        g_pil = new CUIHierarchyImageList(_VxModule.GetModuleInstance(),
                                        g_rgImageListItems,
                                        IT_ICON,
                                        cxIMAGE,
                                        cyIMAGE);
        if (!g_pil)
            hr = E_OUTOFMEMORY;

        // if we succeeded with memory allocations, then just return the status
        //    our image-list says it is in as our status.
        //
        if (SUCCEEDED(hr))
            hr = g_pil->GetStatus();
    }

    return hr;
}

// This is a helper method to get a localized string 
// from the satellite resource only DLL (Projui)
//
HRESULT CVsPackage::GetLocalizedString(ULONG resid, BSTR *pbstrOut)
{
    if (!pbstrOut)
        return E_INVALIDARG;

    HRESULT hr = NOERROR;
    CComPtr<IVsShell>    srpVsShell;

    // get the IVsShell interface so we can use it to
    // load the string from the satellite DLL for this package.
    //
    hr = _VxModule.QueryService(SID_SVsShell, IID_IVsShell, (void **)&srpVsShell);

    if (FAILED( hr ))
        return hr;

    hr = srpVsShell->LoadPackageString( 
                CLSID_FigPrjPackage,    // REFGUID guidPackage
                resid,                        // ULONG resid
                pbstrOut );                    // BSTR *pbstrOut

    return hr;
}

// This is a helper method to set up error information 
// that should be reported back to the user when an 
// error HRESULT is first generated.
//
void CVsPackage::SetErrorInfo(
            /* [in] */ HRESULT hrError,
            /* [in] */ ULONG residErrMsg,
            /* [in] */ DWORD dwHelpContextID)
{

    // short cut the NOERROR case
    if (NOERROR == hrError)
        {
        ::SetErrorInfo(NOERROR, NULL);
        return;
        }
        
    HRESULT hr = NOERROR;
    CComBSTR bstr;
    CComPtr<IVsUIShell>    srpVsUIShell;

    // get the IVsShell interface so we can use it to
    // load the string from the satellite DLL for this package.
    //
    hr = _VxModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpVsUIShell);
    if (FAILED( hr ))
        return;

    hr = GetLocalizedString(residErrMsg, &bstr);
    if (FAILED( hr ))
        return;

    hr = srpVsUIShell->SetErrorInfo( 
            hrError,
            bstr,
            dwHelpContextID,
            NULL,    /* pszHelpFile -- this sample does not have a help file */
            NULL);    /* pszSource */

    return;
}

// This is a helper method to report errors to the user. 
//
void CVsPackage::ReportErrorInfo(
            /* [in] */ HRESULT hrError)
{
    HRESULT hr = NOERROR;
    CComPtr<IVsUIShell>    srpVsUIShell;

    // get the IVsShell interface so we can use it to
    // load the string from the satellite DLL for this package.
    //
    hr = _VxModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpVsUIShell);

    if (FAILED( hr ))
        return;

    hr = srpVsUIShell->ReportErrorInfo(hrError);

    return;
}


/* static */ 
HRESULT WINAPI CVsPackage::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the DEVENV_PATH
    CComBSTR cbstrDevenvPath;
    hr = GetRegDevenvPath(&cbstrDevenvPath);
    if (FAILED(hr))
    {
        // the call may fail when VS is uninstalled
        if (bRegister)
            return hr;
        else
            cbstrDevenvPath="devenv.exe"; // we can continue
    }

    // get the PROGID_VERSION
    CComBSTR cbstrProgidVersion;
    hr = GetRegProgidVersion(&cbstrProgidVersion);
    if (FAILED(hr))
    {
        // the call may fail when VS is uninstalled
        if (bRegister)
            return hr;
        else
            cbstrProgidVersion="7.1"; // we can continue
    }

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    IfFailRet(hr);

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName;
    hr = GetRegDefaultResourceStrings(&cbstrResDllPath, &cbstrResDllName);
    IfFailRet(hr);

    // get the TEMPLATE_PATH
    CComBSTR cbstrTemplatePath;
    hr = GetRegDefaultTemplatePath(&cbstrTemplatePath);
    IfFailRet(hr);

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_FigPrjPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrCLSID_MiscFilesProject(CLSID_MiscellaneousFilesProject);
    if (!cbstrCLSID_MiscFilesProject) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_MyProjectType(GUID_MyProjectType);
    if (!cbstrGUID_MyProjectType) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_EFProjectType(GUID_EFProjectType);
    if (!cbstrGUID_EFProjectType) 
        return E_OUTOFMEMORY;

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    WCHAR wszIDS_PROJECT_TYPE[iMaxResIdLen];
    WCHAR wszIDS_DISPLAY_PROJ_FILE_EXT[iMaxResIdLen];
    WCHAR wszIDS_OPENFILES_FILTER[iMaxResIdLen];
    WCHAR wszIDS_FINDFILES_FILTER[iMaxResIdLen];
    WCHAR wszIDS_ADDITEM_TEMPLATES_ENTRY[iMaxResIdLen];
    WCHAR wszIDS_NEWPROJ_TEMPLATES_ENTRY[iMaxResIdLen];
    _ultow(IDS_PACKAGE_LOAD_KEY,        wszIDS_PACKAGE_LOAD_KEY,        10);
    _ultow(IDS_PROJECT_TYPE,            wszIDS_PROJECT_TYPE,            10);
    _ultow(IDS_DISPLAY_PROJ_FILE_EXT,   wszIDS_DISPLAY_PROJ_FILE_EXT,   10);
    _ultow(IDS_OPENFILES_FILTER,        wszIDS_OPENFILES_FILTER,        10);
    _ultow(IDS_FINDFILES_FILTER,        wszIDS_FINDFILES_FILTER,        10);
    _ultow(IDS_ADDITEM_TEMPLATES_ENTRY, wszIDS_ADDITEM_TEMPLATES_ENTRY, 10);
    _ultow(IDS_NEWPROJ_TEMPLATES_ENTRY, wszIDS_NEWPROJ_TEMPLATES_ENTRY, 10);

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"DEVENV_PATH",                    cbstrDevenvPath},
        {L"PROGID_VERSION",                 cbstrProgidVersion},
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"RESOURCE_PATH",                  cbstrResDllPath},
        {L"RESOURCE_DLL",                   cbstrResDllName},
        {L"TEMPLATE_PATH",                  cbstrTemplatePath},
        {L"CLSID_Package",                  cbstrCLSID_Package},
        {L"CLSID_MiscFilesProject",         cbstrCLSID_MiscFilesProject},
        {L"GUID_MyProjectType",             cbstrGUID_MyProjectType},
        {L"GUID_EFProjectType",             cbstrGUID_EFProjectType},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_PROJECT_TYPE",               wszIDS_PROJECT_TYPE},
        {L"IDS_DISPLAY_PROJ_FILE_EXT",      wszIDS_DISPLAY_PROJ_FILE_EXT},
        {L"IDS_OPENFILES_FILTER",           wszIDS_OPENFILES_FILTER},
        {L"IDS_FINDFILES_FILTER",           wszIDS_FINDFILES_FILTER},
        {L"IDS_ADDITEM_TEMPLATES_ENTRY",    wszIDS_ADDITEM_TEMPLATES_ENTRY},
        {L"IDS_NEWPROJ_TEMPLATES_ENTRY",    wszIDS_NEWPROJ_TEMPLATES_ENTRY},
        {L"AutomationProjects",             g_wszAutomationProjects},
        {L"AutomationProjectsEvents",       g_wszAutomationProjectsEvents},
        {L"AutomationProjectItemsEvents",   g_wszAutomationProjectItemsEvents},
        {NULL, NULL}
    };

    hr = _AtlModule.UpdateRegistryFromResource(IDR_REGISTRYSCRIPT, bRegister, rgMap);
    IfFailRet(hr);

    // now register/unregister the typelibs
    int rgTlb[] = 
    { 
        IDTLIB_PRJ,     // main typelib
        IDTLIB_PRJEXT   // ext typelib
    };
    for (int iTlbRes = 0; iTlbRes < NUMBER_OF(rgTlb); iTlbRes++)
    {
        WCHAR wszTypeLibRes[21];
        lstrcpyW(wszTypeLibRes, L"\\");
        _itow(rgTlb[iTlbRes], wszTypeLibRes+lstrlenW(wszTypeLibRes), 10);
        if (bRegister)
            hr = _AtlModule.RegisterTypeLib(wszTypeLibRes);
        else
            hr = _AtlModule.UnRegisterTypeLib(wszTypeLibRes);

        IfFailRet(hr);
    }

    return hr;
}


/*****************************************************************************
** IVsPackage Implementation
*****************************************************************************/

STDMETHODIMP CVsPackage::SetSite(IServiceProvider *pSP)
{
    ExpectedPtrRet(pSP);
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard
    
    HRESULT hr = NOERROR;
    hr = _VxModule.SetModuleSite(pSP);
    IfFailRet(hr);

    CComPtr<IVsShell> srpShell;
    hr = _VxModule.QueryService(SID_SVsShell, IID_IVsShell, (void**)&srpShell);
    _ASSERTE(SUCCEEDED(hr));
    IfFailRet(hr); ExpectedExprRet(srpShell != NULL);

    // Initialize "_VxModule.m_hInstResource" to point to our localized satellite DLL.
    // This will then make CString.LoadString load strings from our satellite DLL.
    // after this point _VxModule.->GetResourceInstance() will return the hinst of 
    // our localized satellite DLL not our VsPackage implementation DLL.
    HINSTANCE hResource;
    hr = srpShell->LoadUILibrary(CLSID_FigPrjPackage, 0, (DWORD_PTR*)&hResource);
    if (FAILED(hr) || !hResource)
    {
        _ASSERTE((SUCCEEDED(hr) && hResource));
        return E_FAIL;
    }
    _AtlModule.SetResourceInstance(hResource);

    CComPtr<IVsRegisterProjectTypes> srpRegProjTypes;
    if ((SUCCEEDED(hr = _VxModule.QueryService(SID_SVsRegisterProjectTypes, IID_IVsRegisterProjectTypes, (void **)&srpRegProjTypes))) && (srpRegProjTypes != NULL))
    {
        CComPtr<IVsProjectFactory> srpProjFac;
        CComObject<CMyProjectFactory>    *pMyProjFac = NULL;

        hr = CComObject<CMyProjectFactory>::CreateInstance (&pMyProjFac);
        IfFailRet(hr);
        srpProjFac = pMyProjFac;
        if (srpProjFac != NULL)
            hr = srpRegProjTypes->RegisterProjectType(GUID_MyProjectType, srpProjFac, &m_dwProjectCookie);
    }

    return hr;
}

STDMETHODIMP CVsPackage::QueryClose(BOOL *pCanClose)
{
    ExpectedPtrRet(pCanClose);
    *pCanClose = TRUE;
    return NOERROR;
}

STDMETHODIMP CVsPackage::Close()
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard
    
    m_fZombie = TRUE;

    CComPtr<IVsRegisterProjectTypes> srpRegProjTypes;
    if (m_dwProjectCookie && (SUCCEEDED(_VxModule.QueryService(SID_SVsRegisterProjectTypes, IID_IVsRegisterProjectTypes, (void **)&srpRegProjTypes))) && (srpRegProjTypes != NULL))
        srpRegProjTypes->UnregisterProjectType(m_dwProjectCookie);

    // A package should not call IProfferService::RevokeService() in its Close() implementation 
    // (Note: the debug version of the Shell will Assert to help catch offenders). All services 
    // are expected to remain available for the entire duration of calling Close() on all packages. 
    // The Shell will automatically revoke and release the services after all packages have been 
    // called Close().

    _VxModule.Close();

    // release the satelitte dll
    ASSERT(_VxModule.GetModuleInstance() != _VxModule.GetResourceInstance());
    ::FreeLibrary(_VxModule.GetResourceInstance());
    _AtlModule.SetResourceInstance( _AtlModule.GetModuleInstance() );

    if (m_srpAutomationProjects != NULL)
        static_cast<CACProjects*>((IDispatch*)m_srpAutomationProjects)->Close();
    m_srpAutomationProjects.Release();
    CAutomationEvents::ReleaseAutomationEvents();

    return NOERROR;
}



STDMETHODIMP CVsPackage::GetAutomationObject(
    /* [in]  */ LPCOLESTR       pszPropName, 
    /* [out] */ IDispatch **    ppIDispatch)
{
    ExpectedPtrRet(pszPropName);
    ExpectedPtrRet(ppIDispatch);
    *ppIDispatch = NULL;

    if (m_fZombie)
        return E_UNEXPECTED;

    if (_wcsicmp(pszPropName, g_wszAutomationProjects) == 0)
    {
        return GetAutomationProjects(ppIDispatch);
    }
    else if (_wcsicmp(pszPropName, g_wszAutomationProjectsEvents) == 0)
    {
        return CAutomationEvents::GetAutomationEvents(ppIDispatch);
    }
    else if (_wcsicmp(pszPropName, g_wszAutomationProjectItemsEvents) == 0)
    {
        return CAutomationEvents::GetAutomationEvents(ppIDispatch);
    }
    return E_INVALIDARG;
}


STDMETHODIMP CVsPackage::CreateTool(REFGUID rguid) 
{ 
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    return E_NOTIMPL;
}

STDMETHODIMP CVsPackage::ResetDefaults(PKGRESETFLAGS dwFlags) { return NOERROR; }

STDMETHODIMP CVsPackage::GetPropertyPage(REFGUID rguidPage, VSPROPSHEETPAGE *ppage) { return E_NOTIMPL; }


/*****************************************************************************
** IVsInstalledProduct Implementation
*****************************************************************************/
STDMETHODIMP CVsPackage::get_IdBmpSplash(
    UINT* pIdBmp)
{
    if (NULL == pIdBmp)
        return E_POINTER;

    *pIdBmp = IDB_SPLASHSCREEN;
    return S_OK;
} 

STDMETHODIMP CVsPackage::get_OfficialName(
    BSTR* pbstrName)
{
    if (NULL == pbstrName)
        return E_POINTER;

    CComBSTR bstrName;
    bstrName.LoadString(_VxModule.GetResourceInstance(), IDS_OFFICIALNAME);
    *pbstrName = bstrName.Detach();

    return (*pbstrName) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CVsPackage::get_ProductID(
    BSTR* pbstrPID)
{
    if (NULL == pbstrPID)
        return E_POINTER;

    CComBSTR bstr;
    bstr.LoadString(_VxModule.GetResourceInstance(), IDS_PRODUCTID);
    *pbstrPID = bstr.Detach();

    return (*pbstrPID) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CVsPackage::get_ProductDetails(
    BSTR* pbstrProductDetails)
{
    if (NULL == pbstrProductDetails)
        return E_POINTER;

    CComBSTR bstr;
    bstr.LoadString(_VxModule.GetResourceInstance(), IDS_PRODUCTDETAILS);
    *pbstrProductDetails = bstr.Detach();

    return (*pbstrProductDetails) ? S_OK : E_OUTOFMEMORY;
}

STDMETHODIMP CVsPackage::get_IdIcoLogoForAboutbox(
    UINT* pIdIco)
{
    if (NULL == pIdIco)
        return E_POINTER;

    *pIdIco = IDI_HELPABOUT;
    return S_OK;
}


/*****************************************************************************
** IOleCommandTarget Implementation
*****************************************************************************/

HRESULT CVsPackage::QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    _ASSERTE(cCmds==1);

    if (prgCmds==NULL)
        return E_INVALIDARG;
    
    if ( pguidCmdGroup == NULL )
    {
        return OLECMDERR_E_NOTSUPPORTED;
    }
    else if ( CLSID_FigPrjPackage == *pguidCmdGroup )
    {
        BOOL fEnable = FALSE;
//        switch(prgCmds[0].cmdID)
//        {

//        default:
        fEnable = -2;
//            break;
//        }

        if(fEnable == -2)
          return OLECMDERR_E_NOTSUPPORTED;
        else if(fEnable == -1)
          prgCmds[0].cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE;
        else if(fEnable)
          prgCmds[0].cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
        else
          prgCmds[0].cmdf = OLECMDF_SUPPORTED;
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    return NOERROR;
}


HRESULT CVsPackage::Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANT *pvaIn, VARIANT *pvaOut)
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    HRESULT hr = NOERROR;

    if ( pguidCmdGroup == NULL )
    {
        return OLECMDERR_E_NOTSUPPORTED;
    }
    else if ( CLSID_FigPrjPackage == *pguidCmdGroup )
    {
        // The IOleCommandTarget::Exec handler should take care of reporting
        // error messages to the user that occur in the execution of a command.
        // The convention is that the function that calls ReportErrorInfo()
        // should clear any cached error message before calling the functions
        // that could possibly generate errors.
        SetErrorInfo(NOERROR, NULL, 0);    

//        switch (nCmdID)
//        {
                
//            default:    
                return OLECMDERR_E_NOTSUPPORTED;
//                break;
//        }

        // Display any error message to the user and then reset the returned "hr"
        // to NOERROR because the error has been handled.
        if (FAILED(hr))
        {
            ReportErrorInfo(hr);
            hr = NOERROR;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    return hr;
}


/*****************************************************************************
** IServiceProvider Implementation
*****************************************************************************/

STDMETHODIMP CVsPackage::QueryService
(
REFGUID rsid,
REFIID riid,
void **ppvObject
)
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    if (ppvObject == NULL)
        return E_INVALIDARG;

    HRESULT hr = E_NOINTERFACE;
    *ppvObject = NULL;                // always initialize out parameters

    return hr;
}


HRESULT CVsPackage::GetAutomationProjects(/* [out] */ IDispatch ** ppIDispatch)
{
    ExpectedPtrRet(ppIDispatch);
    *ppIDispatch = NULL;

    if (!m_srpAutomationProjects)
    {
        HRESULT hr = CACProjects::CreateInstance(&m_srpAutomationProjects);
        IfFailRet(hr);
        ExpectedExprRet(m_srpAutomationProjects != NULL);
    }
    return m_srpAutomationProjects.CopyTo(ppIDispatch);
}



/////////////////////////////////////////////////////////////////////////////
