
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// vspkg.cpp : Implementation of CVsPackage and interfaces

#include "stdafx.h"     // system includes
#include "PrjInc.h"     // project includes
#include "FigOutline.h"


/////////////////////////////////////////////////////////////////////////////
// CVsPackage

CVsPackage::CVsPackage()
{
    ENVSDK_TRACE(envsdkTraceGeneral,  TLC, _T(" CVsPackage::CVsPackage \n") );

    m_srpFigEditorFactory = NULL;
    m_vscookieFigEditorFactory = NULL;
    m_srpFigEditorFactoryEncoding = NULL;
    m_vscookieFigEditorFactoryEncoding = NULL;
    m_fZombie = FALSE;
    m_pTPP = NULL;
}

CVsPackage::~CVsPackage()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, _T(" CVsPackage::~CVsPackage \n") );
}

// This is a helper method to get a localized string 
// from the satellite resource only DLL (LangSvcUI)
//
HRESULT CVsPackage::GetLocalizedString(ULONG resid, BSTR *pbstrOut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::GetLocalizedString \n") );

    if (!pbstrOut)
        return E_INVALIDARG;

    HRESULT hr = NOERROR;
    CComPtr<IVsShell>   srpVsShell;

    // get the IVsShell interface so we can use it to
    // load the string from the satellite DLL for this package.
    //
    hr = _AtlModule.QueryService(SID_SVsShell, IID_IVsShell, (void **)&srpVsShell);

    if (FAILED( hr ))
        return hr;

    hr = srpVsShell->LoadPackageString( 
                CLSID_FigEditPackage,       // REFGUID guidPackage
                resid,                      // ULONG resid
                pbstrOut );                 // BSTR *pbstrOut

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
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::SetErrorInfo \n") );

    // short cut the NOERROR case
    if (NOERROR == hrError)
        {
        ::SetErrorInfo(NOERROR, NULL);
        return;
        }
        
    HRESULT hr = NOERROR;
    CComBSTR bstr;
    CComPtr<IVsUIShell> srpVsUIShell;

    // get the IVsShell interface so we can use it to
    // load the string from the satellite DLL for this package.
    //
    hr = _AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpVsUIShell);
    if (FAILED( hr ))
        return;

    hr = GetLocalizedString(residErrMsg, &bstr);
    if (FAILED( hr ))
        return;

    hr = srpVsUIShell->SetErrorInfo( 
            hrError,
            bstr,
            dwHelpContextID,
            NULL,   /* pszHelpFile -- this sample does not have a help file */
            NULL);  /* pszSource */

    return;
}

// This is a helper method to report errors to the user. 
//
void CVsPackage::ReportErrorInfo(
            /* [in] */ HRESULT hrError)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::ReportErrorInfo \n") );


    HRESULT hr = NOERROR;
    CComPtr<IVsUIShell> srpVsUIShell;

    // get the IVsShell interface so we can use it to
    // load the string from the satellite DLL for this package.
    //
    hr = _AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpVsUIShell);

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
    hr = _AtlModule.GetRegDevenvPath(&cbstrDevenvPath);
    IfFailRet(hr);

    // get the PROGID_VERSION
    CComBSTR cbstrProgidVersion;
    hr = _AtlModule.GetRegProgidVersion(&cbstrProgidVersion);
    IfFailRet(hr);

    // get the DDE_NAME
    CComBSTR cbstrDdeName;
    hr = _AtlModule.GetRegDdeName(&cbstrDdeName);
    IfFailRet(hr);

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = _AtlModule.GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    IfFailRet(hr);

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName(L"FigPkgUI.Dll");
    hr = _AtlModule.GetRegDefaultResourceStrings(&cbstrResDllPath, NULL);
    IfFailRet(hr);

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_FigEditPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_EditorFactory(GUID_EditorFactory);
    if (!cbstrGUID_EditorFactory) 
        return E_OUTOFMEMORY; 
    CComBSTR cbstrGUID_FigEditorFactoryEncoding(GUID_FigEditorFactoryEncoding);
    if (!cbstrGUID_FigEditorFactoryEncoding) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_DocOutline(GUID_DocOutline);
    if (!cbstrGUID_DocOutline) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrLOGVIEWID_Code(LOGVIEWID_Code);
    if (!cbstrLOGVIEWID_Code) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrLOGVIEWID_Designer(LOGVIEWID_Designer);
    if (!cbstrLOGVIEWID_Designer) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrguidFigEditTbxPropPage(guidFigEditTbxPropPage);
    if (!cbstrguidFigEditTbxPropPage) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrguidFigEditCmdUI(guidFigEditCmdUI);
    if (!cbstrguidFigEditCmdUI) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrguidFigCodeCmdUI(guidFigCodeCmdUI);
    if (!cbstrguidFigCodeCmdUI) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrSID_SFigOutline(SID_SFigOutline);
    if (!cbstrSID_SFigOutline) 
        return E_OUTOFMEMORY;

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    WCHAR wszIDS_EDITOR_NAME[iMaxResIdLen];
    WCHAR wszIDS_CODE_EDITOR[iMaxResIdLen];
    WCHAR wszIDS_FORM_EDITOR[iMaxResIdLen];
    WCHAR wszIDS_CODEPAGE_EDITOR_NAME[iMaxResIdLen];
    WCHAR wszIDS_FP_TBXPROPPAGE_NAME[iMaxResIdLen];
    _ultow(IDS_PACKAGE_LOAD_KEY,        wszIDS_PACKAGE_LOAD_KEY,        10);
    _ultow(IDS_EDITOR_NAME,             wszIDS_EDITOR_NAME,             10);
    _ultow(IDS_CODE_EDITOR,             wszIDS_CODE_EDITOR,             10);
    _ultow(IDS_FORM_EDITOR,             wszIDS_FORM_EDITOR,             10);
    _ultow(IDS_CODEPAGE_EDITOR_NAME,    wszIDS_CODEPAGE_EDITOR_NAME,    10);
    _ultow(IDS_FP_TBXPROPPAGE_NAME,     wszIDS_FP_TBXPROPPAGE_NAME,     10);

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"DEVENV_PATH",                    cbstrDevenvPath},
        {L"PROGID_VERSION",                 cbstrProgidVersion},
        {L"DDE_NAME",                        cbstrDdeName},
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"RESOURCE_PATH",                  cbstrResDllPath},
        {L"RESOURCE_DLL",                   cbstrResDllName},
        {L"CLSID_Package",                  cbstrCLSID_Package},
        {L"GUID_EditorFactory",             cbstrGUID_EditorFactory},
        {L"GUID_FigEditorFactoryEncoding",  cbstrGUID_FigEditorFactoryEncoding},
        {L"GUID_DocOutline",                cbstrGUID_DocOutline},
        {L"LOGVIEWID_Code",                 cbstrLOGVIEWID_Code},
        {L"LOGVIEWID_Designer",             cbstrLOGVIEWID_Designer},
        {L"guidFigEditTbxPropPage",         cbstrguidFigEditTbxPropPage},
        {L"guidFigEditCmdUI",               cbstrguidFigEditCmdUI},
        {L"guidFigCodeCmdUI",               cbstrguidFigCodeCmdUI},
        {L"SID_SFigOutline",                cbstrSID_SFigOutline},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_EDITOR_NAME",                wszIDS_EDITOR_NAME},
        {L"IDS_CODE_EDITOR",                wszIDS_CODE_EDITOR},
        {L"IDS_FORM_EDITOR",                wszIDS_FORM_EDITOR},
        {L"IDS_CODEPAGE_EDITOR_NAME",       wszIDS_CODEPAGE_EDITOR_NAME},
        {L"IDS_FP_TBXPROPPAGE_NAME",        wszIDS_FP_TBXPROPPAGE_NAME},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResource(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}


/*****************************************************************************
** IVsPackage Implementation
*****************************************************************************/

STDMETHODIMP CVsPackage::SetSite(IServiceProvider *pSP)
{

    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::SetSite \n") );
    
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    HRESULT hr = S_OK;
    CComPtr<IProfferService>    srpIProfferService;
    CComPtr<IVsRegisterEditors> srpIVsRegisterEditors;

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
    hr = _AtlModule.LoadUILibrary(CLSID_FigEditPackage, IDS_E_BADINSTALL);
    IfFailGo(hr);

    // create editor factory
    if( m_srpFigEditorFactory == NULL ) 
    {
        m_srpFigEditorFactory = new CFigEditorFactory(this); // Note: assignment to a smart pointer does an AddRef()        
        IfFailAllocGo(m_srpFigEditorFactory);
    }

    // create code page editor factory
    if( m_srpFigEditorFactoryEncoding == NULL ) 
    {
        m_srpFigEditorFactoryEncoding = new CFigEditorFactory(this, TRUE); // Note: assignment to a smart pointer does an AddRef()        
        IfFailAllocGo(m_srpFigEditorFactoryEncoding);
    }

    // QS for IVsRegisterEditors, register our editor factory
    hr = _AtlModule.QueryService(
                        SID_SVsRegisterEditors, 
                        IID_IVsRegisterEditors, 
                        (void **)&srpIVsRegisterEditors);
    IfFailGo(hr);
    ExpectedExprGo(srpIVsRegisterEditors != NULL);

    ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T("FigEdit: CVsPackage::SetSite : registering the fig editor...\n") );
    hr = srpIVsRegisterEditors->RegisterEditor(
                GUID_EditorFactory,
                m_srpFigEditorFactory, 
                &m_vscookieFigEditorFactory);
    IfFailGo(hr);

    ENVSDK_TRACE(envsdkTraceGeneral, TLI, _T("FigEdit: CVsPackage::SetSite : registering the fig codepage editor...\n") );
    hr = srpIVsRegisterEditors->RegisterEditor(
                GUID_FigEditorFactoryEncoding,
                m_srpFigEditorFactoryEncoding, 
                &m_vscookieFigEditorFactoryEncoding);
    IfFailGo(hr);

    m_pTPP = new CFeTbxPropPage();
    IfFailAllocGo(m_pTPP);
    hr = m_pTPP->Init();
    IfFailGo(hr);

    // proffer our service
    hr = _AtlModule.QueryService(
                        SID_SProfferService, 
                        IID_IProfferService, 
                        (void **)&srpIProfferService);
    IfFailGo(hr);
    ASSERT(srpIProfferService != NULL);

    if (srpIProfferService != NULL)
    {
        DWORD dwCookie;
        hr = srpIProfferService->ProfferService(
                        SID_SFigOutline, 
                        static_cast<IServiceProvider *>(this), 
                        &dwCookie);
        ASSERT(SUCCEEDED(hr));
    }
OnError:
    if (FAILED(hr))
    {
        // clean
        Close();
    }
    return hr;
}

STDMETHODIMP CVsPackage::QueryClose( BOOL *pCanClose )
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::QueryClose \n") );

    *pCanClose = TRUE;
    return NOERROR;
}

STDMETHODIMP CVsPackage::Close()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::Close \n") );

    if (m_fZombie)
        return S_FALSE;        // recursion guard

    // A package should not call IProfferService::RevokeService() in its Close() implementation 
    // (Note: the debug version of the Shell will Assert to help catch offenders). All services 
    // are expected to remain available for the entire duration of calling Close() on all packages. 
    // The Shell will automatically revoke and release the services after all packages have been 
    // called Close().

    HRESULT hr = S_OK;

    // unregister the project factories 
    if (m_vscookieFigEditorFactory || m_vscookieFigEditorFactoryEncoding)
    {
        // QS for IVsRegisterEditors, unregister our editor factory
        CComPtr<IVsRegisterEditors> srpIVsRegisterEditors;
        hr = _AtlModule.QueryService(
                        SID_SVsRegisterEditors, 
                        IID_IVsRegisterEditors, 
                        (void **)&srpIVsRegisterEditors);
        ASSERT(SUCCEEDED(hr) && (srpIVsRegisterEditors != NULL) );
        if (SUCCEEDED(hr) && (srpIVsRegisterEditors != NULL) )
        {
            if (m_vscookieFigEditorFactory)
            {
                hr = srpIVsRegisterEditors->UnregisterEditor(m_vscookieFigEditorFactory);
                ASSERT(SUCCEEDED(hr));
                m_vscookieFigEditorFactory = NULL;
            }
            if (m_vscookieFigEditorFactoryEncoding)
            {
                hr = srpIVsRegisterEditors->UnregisterEditor(m_vscookieFigEditorFactoryEncoding);
                ASSERT(SUCCEEDED(hr));
                m_vscookieFigEditorFactoryEncoding = NULL;
            }
    }
    }

    // release our editor factory, destroys itself when ref count reaches zero
    m_srpFigEditorFactory.Release();      
    m_srpFigEditorFactoryEncoding.Release();

    if (m_pTPP != NULL)
        delete m_pTPP;

    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);

    m_fZombie = TRUE;

    return NOERROR;
}

STDMETHODIMP CVsPackage::GetAutomationObject(LPCOLESTR pszPropName, IDispatch **ppDisp)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::GetAutomationObject \n") );

    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard
    ExpectedPtrRet(ppDisp);
    *ppDisp = NULL;
    return E_NOTIMPL;
}

STDMETHODIMP CVsPackage::CreateTool(REFGUID rguid) 
{ 
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::CreateTool \n") );

    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    return E_NOTIMPL;
}

STDMETHODIMP CVsPackage::ResetDefaults(PKGRESETFLAGS grfFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::ResetDefaults \n") );

    if( (grfFlags & PKGRF_TOOLBOXITEMS) || (grfFlags & PKGRF_TOOLBOXSETUP))
    {
        ExpectedExprRet(m_pTPP);
        return m_pTPP->ResetTbxItems(grfFlags);
    }
    return S_OK;
}


STDMETHODIMP CVsPackage::GetPropertyPage(REFGUID rguidPage, VSPROPSHEETPAGE *ppage) 
{ 
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::GetPropertyPage\n") );
    ExpectedExprRet(m_pTPP);
    ExpectedPtrRet(ppage);

    return m_pTPP->GetPropertyPage(rguidPage, ppage);
}


/*****************************************************************************
** IOleCommandTarget Implementation
*****************************************************************************/
#pragma warning(disable:4065) // switch statement contains 'default' but no 'case' labels

HRESULT CVsPackage::QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
{
    //ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::QueryStatus \n") );

    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    _ASSERTE(cCmds==1);

    if (prgCmds==NULL)
        return E_INVALIDARG;
    
    if ( pguidCmdGroup == NULL )
    {
        return OLECMDERR_E_NOTSUPPORTED;
    }
    else if ( CLSID_FigEditPackage == *pguidCmdGroup )
    {
        BOOL fEnable = FALSE;
        switch(prgCmds[0].cmdID)
        {
        default:
            return OLECMDERR_E_NOTSUPPORTED;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    return NOERROR;
}


HRESULT CVsPackage::Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANT *pvaIn, VARIANT *pvaOut)
{
    //ENVSDK_TRACE(envsdkTraceGeneral, TLF, _T(" CVsPackage::Exec \n") );

    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    HRESULT hr = NOERROR;

    if ( pguidCmdGroup == NULL )
    {
        return OLECMDERR_E_NOTSUPPORTED;
    }
    else if ( CLSID_FigEditPackage == *pguidCmdGroup )
    {
        // The IOleCommandTarget::Exec handler should take care of reporting
        // error messages to the user that occur in the execution of a command.
        // The convention is that the function that calls ReportErrorInfo()
        // should clear any cached error message before calling the functions
        // that could possibly generate errors.
        SetErrorInfo(NOERROR, NULL, 0); 

        switch (nCmdID)
        {
            default:    
                return OLECMDERR_E_NOTSUPPORTED;
                break;
        }

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


///////////////////////////////////////////////////////////////////////////////
// IServiceProvider Implementation

STDMETHODIMP CVsPackage::QueryService(
                    /*[in] */ REFGUID rsid,
                    /*[in] */ REFIID  riid,
                    /*[out]*/ void**  ppvObject)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsPackage::QueryService ")
        _T(", this = 0x%x \n"), this );

    if( m_fZombie )
        return E_UNEXPECTED;

    ExpectedPtrRet(ppvObject);
    *ppvObject = NULL;

    HRESULT hr = E_NOINTERFACE;

    if (rsid == SID_SFigOutline)
    {
        ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
            _T(": CVsPackage::QueryService ")
            _T(", this = 0x%x : SID_SFigOutline\n"), this );

        CComPtr<IFigOutline> srpIFigOutline;
        hr = CFigOutline::CreateInstance(&srpIFigOutline);
        IfFailRet(hr);
        ASSERT(SUCCEEDED(hr));

        hr = srpIFigOutline->QueryInterface(riid, ppvObject);
        ASSERT(SUCCEEDED(hr));
    }
    return hr;
}



/////////////////////////////////////////////////////////////////////////////
