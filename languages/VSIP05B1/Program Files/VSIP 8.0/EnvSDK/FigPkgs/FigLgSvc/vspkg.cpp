
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// vspkg.cpp : Implementation of CVsPackage and interfaces

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes


/////////////////////////////////////////////////////////////////////////////
// CVsPackage

CVsPackage::CVsPackage()
{
    ATLTRACE(TEXT(">> Constructing CVsPackage: 0x%X\n"), this);
    m_srpLService = NULL;
    m_fZombie = FALSE;
}

CVsPackage::~CVsPackage()
{
    ATLTRACE(TEXT(">> Destructing CVsPackage: 0x%X\n"), this);
}

// This is a helper method to get a localized string 
// from the satellite resource only DLL (FigPkgUI)
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
    hr = _AtlModule.QueryService(SID_SVsShell, IID_IVsShell, (void **)&srpVsShell);

    if (FAILED( hr ))
        return hr;

    hr = srpVsShell->LoadPackageString( 
                CLSID_FigLgSvcPackage,        // REFGUID guidPackage
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

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = _AtlModule.GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    IfFailRet(hr);

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName(L"FigPkgUI.dll");
    hr = _AtlModule.GetRegDefaultResourceStrings(&cbstrResDllPath, NULL);
    IfFailRet(hr);

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_FigLgSvcPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrSID_SFigLgSvc(SID_SFigLgSvc);
    if (!cbstrSID_SFigLgSvc) 
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
        {L"SID_SFigLgSvc",                  cbstrSID_SFigLgSvc},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResource(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}

/*****************************************************************************
** IVsPackage Implementation
*****************************************************************************/

STDMETHODIMP CVsPackage::SetSite(IServiceProvider *pSP)
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    if ( pSP ) 
        _AtlModule.SetModuleSite(pSP);


    // profer our language service
    CComPtr<IProfferService> srpProffer;
    if(( SUCCEEDED( _AtlModule.QueryService(
                    SID_SProfferService, IID_IProfferService, 
                    (void **)&srpProffer ))) && ( srpProffer != NULL ))
    {
        ATLTRACE(TEXT(">> CVsPackage, proffering SID_SFigLgSvc Service.\n"));
        DWORD dwCookie;
        srpProffer->ProfferService( SID_SFigLgSvc, 
                                    (IServiceProvider *) this, &dwCookie );
    }

    return NOERROR;
}

STDMETHODIMP CVsPackage::QueryClose(BOOL *pCanClose)
{
    if (NULL==pCanClose)
        return E_INVALIDARG;
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

    m_srpLService.Release();     // get rid of our CFigLanguageService obj

    _AtlModule.SetModuleSite(NULL);

    return NOERROR;
}

STDMETHODIMP CVsPackage::GetAutomationObject(LPCOLESTR pszPropName, IDispatch **ppDisp)
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard
    if (NULL==ppDisp)
        return E_INVALIDARG;

    *ppDisp = NULL;
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
    else if ( CLSID_FigLgSvcPackage == *pguidCmdGroup )
    {
        BOOL fEnable = FALSE;
        switch(prgCmds[0].cmdID)
        {

        case 0:  //remove when a real cmd id is added
        default:
            fEnable = -2;
            break;
        }

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
    else if ( CLSID_FigLgSvcPackage == *pguidCmdGroup )
    {
        // The IOleCommandTarget::Exec handler should take care of reporting
        // error messages to the user that occur in the execution of a command.
        // The convention is that the function that calls ReportErrorInfo()
        // should clear any cached error message before calling the functions
        // that could possibly generate errors.
        SetErrorInfo(NOERROR, NULL, 0);    

        switch (nCmdID)
        {
                
            case 0:  //remove when a real cmd id is added
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
    if( m_fZombie )
        return E_UNEXPECTED;        // recursion guard

    if( ppvObject == NULL )
        return E_INVALIDARG;

    HRESULT hr = E_NOINTERFACE;
    *ppvObject = NULL;                // always initialize out parameters

    // We provide one service from our package.
    if( rsid == SID_SFigLgSvc )
    {
        ATLTRACE(TEXT(">> CVsPackage, received QueryService for SID_SFigLgSvc.\n"));

        if( m_srpLService == NULL ) {
            m_srpLService = new CFigLanguageService( this );  // Note: assignment to a smart pointer does an AddRef()

            if( m_srpLService == NULL ) 
                return E_OUTOFMEMORY;
        }

        hr = m_srpLService->QueryInterface( riid, ppvObject );    // if QI is successful, ref cnt is incremented
    }

    return hr;
}


/////////////////////////////////////////////////////////////////////////////
