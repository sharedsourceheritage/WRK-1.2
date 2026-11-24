
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cpp : Implementation of C%ProjectClass%Package
//

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"
#include "..\%ProjectName%UI\guids.h"
%EditorStart%
#include "edtfact.h"
#include "bscedtid.h"
%EditorEnd%

/////////////////////////////////////////////////////////////////////////////
// C%ProjectClass%Package

C%ProjectClass%Package::C%ProjectClass%Package()
{
    ATLTRACE(_T("Creating C%ProjectClass%Package: 0x%X\n"), this);
    m_fZombie = FALSE;
%ToolWindowItemStart%
    m_srpToolWinFrame = NULL;
%ToolWindowItemEnd%
%EditorStart%
    m_srpPkgSiteSP = NULL;
    m_srpUIShell = NULL;
    m_srpEdFact = NULL;
%EditorEnd%
}

C%ProjectClass%Package::~C%ProjectClass%Package()
{
    ATLTRACE(_T("Destructing C%ProjectClass%Package: 0x%X\n"), this);
}


/* static */ 
HRESULT WINAPI C%ProjectClass%Package::UpdateRegistry(
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
    CComBSTR cbstrResDllPathUnescaped;
    CComBSTR cbstrResDllNameUnescaped;
    hr = _AtlModule.GetRegDefaultResourceStrings(&cbstrResDllPathUnescaped, &cbstrResDllNameUnescaped);
    if FAILED(hr)
        return hr;

    // escape single quotes
    CComBSTR cbstrResDllPath(cbstrResDllPathUnescaped.Length() * 2);
    CAtlModule::EscapeSingleQuote(cbstrResDllPath, cbstrResDllPathUnescaped);

    CComBSTR cbstrResDllName(cbstrResDllNameUnescaped.Length() * 2);
    CAtlModule::EscapeSingleQuote(cbstrResDllName, cbstrResDllNameUnescaped);

    // get the TEMPLATE_PATH
    CComBSTR cbstrTemplatePathUnescaped;
    hr = _AtlModule.GetRegDefaultTemplatePath(&cbstrTemplatePathUnescaped);
    if FAILED(hr)
        return hr;
    // escape single quotes
    CComBSTR cbstrTemplatePath(cbstrTemplatePathUnescaped.Length() * 2);
    CAtlModule::EscapeSingleQuote(cbstrTemplatePath, cbstrTemplatePathUnescaped);

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_%ProjectClass%Package);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
%ToolWindowItemStart%
    CComBSTR cbstrGUID_ToolPersistance(GUID_guidPersistanceSlot);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
%ToolWindowItemEnd%
%EditorStart%
    CComBSTR cbstrGUID_BscEditorFactory(GUID_BscEditorFactory);
    if (!cbstrGUID_BscEditorFactory) 
        return E_OUTOFMEMORY;
%EditorEnd%
    CComBSTR cbstrGUID_TaskList(GUID_TaskList);
    if (!cbstrGUID_TaskList) 
        return E_OUTOFMEMORY;
%EditorStart%
    CComBSTR cbstrCLSID_MiscFilesProject(CLSID_MiscFilesProject);
    if (!cbstrCLSID_MiscFilesProject) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrLOGVIEWID_TextView(LOGVIEWID_TextView);
    if (!cbstrLOGVIEWID_TextView)
        return E_OUTOFMEMORY;
%EditorEnd%

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    WCHAR wszIDS_OFFICIALNAME[iMaxResIdLen];
    WCHAR wszIDS_PRODUCTDETAILS[iMaxResIdLen];
%EditorStart%    WCHAR wszIDS_NEWFILE_TEMPLATES_ENTRY[iMaxResIdLen];%EditorEnd%
    _ultow(IDS_PACKAGE_LOAD_KEY,        wszIDS_PACKAGE_LOAD_KEY,        10);
    _ultow(IDS_OFFICIALNAME,            wszIDS_OFFICIALNAME,            10);
    _ultow(IDS_PRODUCTDETAILS,          wszIDS_PRODUCTDETAILS,          10);
%EditorStart%    _ultow(IDS_EDITOR_TEMPLATE,         wszIDS_NEWFILE_TEMPLATES_ENTRY, 10);%EditorEnd%

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
        {L"GUID_TaskList",                  cbstrGUID_TaskList},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_OFFICIALNAME",               wszIDS_OFFICIALNAME},
        {L"IDS_PRODUCTDETAILS",             wszIDS_PRODUCTDETAILS},
%ToolWindowItemStart%        {L"GUID_ToolWindowPersistance",     cbstrGUID_ToolPersistance},%ToolWindowItemEnd%
%EditorStart%        {L"CLSID_MiscFilesProject",         cbstrCLSID_MiscFilesProject},
        {L"GUID_BscEditorFactory",          cbstrGUID_BscEditorFactory},
        {L"LOGVIEWID_TextView",             cbstrLOGVIEWID_TextView},
        {L"IDS_EDITOR_TEMPLATE",            wszIDS_NEWFILE_TEMPLATES_ENTRY},%EditorEnd%
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}
%ToolWindowItemStart%
HRESULT C%ProjectClass%Package::ShowToolWinFrame(void)
{ 
    HRESULT hr = NOERROR;

    // it is important to delay creating tool windows for performance reasons.
    // a good strategy is to wait until the first time that the tool window
    // needs to be shown. this is why we put the call to CreateTool in ShowToolWinFrame.
    if (!m_srpToolWinFrame)
    {
        hr = CreateTool(GUID_guidPersistanceSlot);    // call our own IVsPackage::CreateTool method
    }
    if (SUCCEEDED(hr) && (m_srpToolWinFrame != NULL))
        hr = m_srpToolWinFrame->Show();
    return hr;
}
%ToolWindowItemEnd%

/////////////////////////////////////////////////////////////////////////////
// C%ProjectClass%Package IVsPackage Implementation

STDMETHODIMP C%ProjectClass%Package::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ATLTRACE(_T("C%ProjectClass%Package::SetSite\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;
    if (!pSP)
        return E_POINTER;
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
    hr = _AtlModule.LoadUILibrary(CLSID_%ProjectClass%Package, IDS_E_BADINSTALL);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }
%EditorStart%
    m_srpPkgSiteSP = pSP;            // Note: assignment to a smart pointer does an AddRef()

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
                                                (void **)&srpRegEd )))
        && (srpRegEd != NULL))
    {
        ATLTRACE(TEXT(">> C%ProjectClass%Package, registering editor factory.\n"));
        if (FAILED(srpRegEd->RegisterEditor(GUID_BscEditorFactory, 
                                            m_srpEdFact, &m_dwEditorCookie))) 
        {
            ATLTRACE(TEXT(">> C%ProjectClass%Package, RegisterEditor() failed.\n"));
            return E_FAIL;
        }
    }
%EditorEnd%
    return S_OK;
}

STDMETHODIMP C%ProjectClass%Package::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ATLTRACE(_T("C%ProjectClass%Package::QueryClose\n"));

    _ASSERTE(!m_fZombie);
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(pCanClose);
    if (!pCanClose)
        return E_POINTER;
    *pCanClose = TRUE;
    return S_OK;
}

STDMETHODIMP C%ProjectClass%Package::Close(void)
{
    ATLTRACE(_T("C%ProjectClass%Package::Close\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    // set our state for protection
    m_fZombie = TRUE;

%ToolWindowItemStart%
    m_srpToolWinFrame.Release();
%ToolWindowItemEnd%
%EditorStart%
    // QS for IVsRegisterEditors, unregister our editor factory
    CComPtr<IVsRegisterEditors> srpRegEd;
    if ((SUCCEEDED(m_srpPkgSiteSP->QueryService(SID_SVsRegisterEditors, 
                                                IID_IVsRegisterEditors, 
                                                (void **)&srpRegEd ))) && 
        (srpRegEd != NULL))
    {
        ATLTRACE(TEXT(">> C%ProjectClass%Package, unregistering editor factory.\n"));
        if (FAILED(srpRegEd->UnregisterEditor(m_dwEditorCookie))) 
        {
            ATLTRACE(TEXT(">> C%ProjectClass%Package, UnregisterEditor() failed.\n"));
            return E_FAIL;
        }
    }
    m_srpEdFact.Release();            // release our editor factory, destroys itself when ref count reaches zero
    m_srpUIShell.Release();           // release our ptr to the shell's ui service
    m_srpPkgSiteSP.Release();         // release our ptr to service provider
%EditorEnd%
    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);

    return S_OK;
}

STDMETHODIMP C%ProjectClass%Package::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ATLTRACE(_T("C%ProjectClass%Package::GetAutomationObject\n"));

     _ASSERTE(!m_fZombie);
    if (m_fZombie)
        return E_UNEXPECTED;

   _ASSERTE(ppDisp);
    if (!ppDisp)
        return E_POINTER;
    *ppDisp = NULL;
    return E_NOTIMPL;
}

STDMETHODIMP C%ProjectClass%Package::CreateTool(
                    /*[in]*/ REFGUID rguid) 
{ 
    ATLTRACE(_T("C%ProjectClass%Package::CreateTool\n"));
    _ASSERTE(!m_fZombie);

    USES_CONVERSION;

    if (m_fZombie)
        return E_UNEXPECTED;
%NotToolWindowItemStart%
    return E_NOTIMPL;
%NotToolWindowItemEnd%
%ToolWindowItemStart%
    if (rguid == GUID_guidPersistanceSlot)
    {
        CComPtr<IVsUIShell>    srpShell;

        // now get the IVsUIShell interface so we can create a tool window
        //
        HRESULT hr = _AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpShell);

        if (SUCCEEDED(hr))
        {
            CLSID clsidDocObj;
            BOOL    fDefaultPosition = TRUE;
            CComBSTR bstrTitle;
            TCHAR szTitle[128];

            if (! ::LoadString(_AtlBaseModule.GetResourceInstance(), IDS_WINDOW_TITLE, szTitle, countof(szTitle)))
                return HRESULT_FROM_WIN32(::GetLastError());

            hr = CLSIDFromProgID(L"HelloWorld.UserDocument1", &clsidDocObj);
            if (SUCCEEDED(hr))
            {
                if (!srpShell)
                    hr = E_UNEXPECTED;
                else
                    hr = srpShell->CreateToolWindow(
                                    CTW_fInitNew | CTW_fForceCreate,   // dwCTW
                                    NULL,                              // dwReserved
                                    NULL,                              // punkTool
                                    clsidDocObj,                       // rclsidTool
                                    GUID_guidPersistanceSlot,          // rguidPersistanceSlot
                                    GUID_NULL,                         // rguidAutoActivate
                                    NULL,                              // pSP
                                    T2OLE(szTitle),                    // pszCaption 
                                    &fDefaultPosition,                 // pfDefaultPosition
                                    &m_srpToolWinFrame);               // ppWindowFrame
            }
        
            // if CreateToolWindow failed let's give the user a useful error message
            if (FAILED(hr))
                _AtlModule.SetErrorInfo(hr, IDS_E_CANTCREATETOOL, 0);
            else if (m_srpToolWinFrame)
            {
                // Set the bitmap for the frame to be the same as the one used for the menu item
                CComVariant srpvt;
                srpvt.intVal = IDB_MENU_IMAGES;
                m_srpToolWinFrame->SetProperty(VSFPROPID_BitmapResource, srpvt);
                srpvt.intVal = 1;
                m_srpToolWinFrame->SetProperty(VSFPROPID_BitmapIndex, srpvt);
            }
        }
        return hr;
    }
    return E_INVALIDARG;
%ToolWindowItemEnd%
}

STDMETHODIMP C%ProjectClass%Package::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ATLTRACE(_T("C%ProjectClass%Package::ResetDefaults\n"));

    return E_NOTIMPL;
}

STDMETHODIMP C%ProjectClass%Package::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage)
{
    ATLTRACE(_T("C%ProjectClass%Package::GetPropertyPage\n"));

    return E_NOTIMPL;
}


///////////////////////////////////////////////////////////////////////////////
// C%ProjectClass%Package IOleCommandTarget Implementation

#pragma warning(disable:4065) // switch statement contains 'default' but no 'case' labels

STDMETHODIMP C%ProjectClass%Package::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    _ASSERTE(!m_fZombie);
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(cCmds == 1);
    _ASSERTE(prgCmds && pguidCmdGroup);

    if ((prgCmds == NULL) || (pguidCmdGroup == NULL) || (cCmds != 1))
        return E_INVALIDARG;

    DWORD cmdf = OLECMDF_SUPPORTED;

    if (*pguidCmdGroup == guid%ProjectClass%CmdSet)
    {
        // The following bitwise flags control the state of a command:
        //        OLECMDF_SUPPORTED, OLECMDF_ENABLED, OLECMDF_LATCHED,
        //        OLECMDF_NINCHED, OLECMDF_INVISIBLE, OLECMDF_DEFHIDEONCTXTMENU
        //
        // Common cases are the following:
        //    1. Enable a command --  cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED
        //    2. Disable a command -- cmdf = OLECMDF_SUPPORTED
        //    3. Hide a command --    cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE

        switch (prgCmds[0].cmdID)
        {
%MenuItemStart%            case %CommandID%:
                // This command is always enabled
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                break;
%MenuItemEnd%
%ToolWindowItemStart%
            case %ToolCommandID%:
                // This command is always enabled
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                break;
%ToolWindowItemEnd%
            default:
        return OLECMDERR_E_NOTSUPPORTED;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    prgCmds[0].cmdf = cmdf;
    return S_OK;
}

STDMETHODIMP C%ProjectClass%Package::Exec(
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

    if (*pguidCmdGroup == guid%ProjectClass%CmdSet)
    {
        // IOleCommandTargt::Exec should report errors that may occur
        // in the execution of a command. Therefore clear any existing
        // existing error info first
        _AtlModule.ClearErrorInfo();

        switch (nCmdID)
        {
%MenuItemStart%            case %CommandID%:
            {
                TCHAR szTitle[256];

                if (0 == ::LoadString(_AtlBaseModule.GetResourceInstance(), IDS_PROJNAME, szTitle, countof(szTitle)))
                {
                    hr = E_OUTOFMEMORY;
                    break;        // we must be out of memory
                }

                // Show a Message Box to prove we were here
                MessageBox(
                    NULL,
                    L"Executing the command",
                    szTitle,
                    MB_OK);
                break;
            }
%MenuItemEnd%
%ToolWindowItemStart%
            case %ToolCommandID%:
            {
                ShowToolWinFrame();
                break;
            }
%ToolWindowItemEnd%
            default:    
                return OLECMDERR_E_NOTSUPPORTED;
                break;
        }
}
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    return hr;
}
%EditorStart%
HRESULT C%ProjectClass%Package::GetShellUISvc(IVsUIShell **ppSvc)
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

HRESULT C%ProjectClass%Package::GetShellSvc(REFGUID rsid,
                            REFIID riid,
                            void **ppv)
{
    _ASSERTE(m_srpPkgSiteSP.p);
    return m_srpPkgSiteSP->QueryService(rsid, riid, ppv);
}
%EditorEnd%