
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cpp : Implementation of CToolWnPackage
//

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"
#include "guids.h"

/////////////////////////////////////////////////////////////////////////////
// CToolWnPackage

CToolWnPackage::CToolWnPackage()
{
    ATLTRACE(_T("Creating CToolWnPackage: 0x%X\n"), this);
    m_srpToolWinFrame = NULL;
    m_srpHwTService = NULL;
    m_fZombie = FALSE;
}

CToolWnPackage::~CToolWnPackage()
{
    ATLTRACE(_T("Destructing CToolWnPackage: 0x%X\n"), this);
}


/* static */ 
HRESULT WINAPI CToolWnPackage::UpdateRegistry(
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
    CComBSTR cbstrCLSID_Package(CLSID_ToolWnPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrSID_SHelloWorldTool(SID_SHelloWorldTool);
    if (!cbstrSID_SHelloWorldTool) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_HelloWorldTool(GUID_HelloWorldTool);
    if (!cbstrGUID_HelloWorldTool) 
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
        {L"SID_SHelloWorldTool",            cbstrSID_SHelloWorldTool},
        {L"GUID_HelloWorldTool",            cbstrGUID_HelloWorldTool},
        {L"GUID_TaskList",                  cbstrGUID_TaskList},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_OFFICIALNAME",               wszIDS_OFFICIALNAME},
        {L"IDS_PRODUCTDETAILS",             wszIDS_PRODUCTDETAILS},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}


HRESULT CToolWnPackage::ShowToolWinFrame(void)
{ 
    HRESULT hr = NOERROR;

    // it is important to delay creating tool windows for performance reasons.
    // a good strategy is to wait until the first time that the tool window
    // needs to be shown. this is why we put the call to CreateTool in ShowToolWinFrame.
    if (!m_srpToolWinFrame)
    {
        hr = CreateTool(GUID_HelloWorldTool);    // call our own IVsPackage::CreateTool method
    }
    if (SUCCEEDED(hr) && (m_srpToolWinFrame != NULL))
        hr = m_srpToolWinFrame->Show();
    return hr;
}


HRESULT CToolWnPackage::SayHello(BSTR bstrMsg)
{ 
    if (!bstrMsg)
        return E_INVALIDARG;
    HRESULT hr = NOERROR;

    CComPtr<IUnknown> srpUnkVBDocObj;
    CComVariant varPunk;
    _ASSERTE(m_srpToolWinFrame);
    if (!m_srpToolWinFrame)
        return E_UNEXPECTED;
    hr = m_srpToolWinFrame->GetProperty(VSFPROPID_DocView, &varPunk);
    if (FAILED(hr))
        return hr;
    if ((varPunk.vt != VT_UNKNOWN) || (V_UNKNOWN(&varPunk) == NULL))
        return E_UNEXPECTED;
    srpUnkVBDocObj = (IUnknown *) V_UNKNOWN(&varPunk);
    if (srpUnkVBDocObj)
    {
        CComPtr<IHelloWorldTool> srpHwtVBDocObj;
        hr = srpUnkVBDocObj->QueryInterface(IID_IHelloWorldTool, (void **)&srpHwtVBDocObj);
        _ASSERTE(SUCCEEDED(hr) && (srpHwtVBDocObj != NULL));
        if (SUCCEEDED(hr) && (srpHwtVBDocObj != NULL))
        {
            hr = srpHwtVBDocObj->SayHello(bstrMsg);
        }
    }
    
    return hr;
}

/////////////////////////////////////////////////////////////////////////////
// CToolWnPackage IVsPackage Implementation

STDMETHODIMP CToolWnPackage::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ATLTRACE(_T("CToolWnPackage::SetSite\n"));
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
    hr = _AtlModule.LoadUILibrary(CLSID_ToolWnPackage, IDS_E_BADINSTALL);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }


    CComPtr<IProfferService> srpProffer;
    if ((SUCCEEDED(_AtlModule.QueryService(SID_SProfferService, IID_IProfferService, (void **)&srpProffer))) && (srpProffer != NULL))
    {
        DWORD dwCookie;
        srpProffer->ProfferService(SID_SHelloWorldTool, (IServiceProvider *) this, &dwCookie);
    }

    return S_OK;
}

STDMETHODIMP CToolWnPackage::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ATLTRACE(_T("CToolWnPackage::QueryClose\n"));
    _ASSERTE(pCanClose);
    if (!pCanClose)
        return E_POINTER;
    *pCanClose = TRUE;
    return S_OK;
}

STDMETHODIMP CToolWnPackage::Close(void)
{
    ATLTRACE(_T("CToolWnPackage::Close\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    // set our state for protection
    m_fZombie = TRUE;

    m_srpToolWinFrame.Release();

    m_srpHwTService.Release();

    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);

    return S_OK;
}

STDMETHODIMP CToolWnPackage::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ATLTRACE(_T("CToolWnPackage::GetAutomationObject\n"));
    _ASSERTE(ppDisp);
    if (!ppDisp)
        return E_POINTER;
    *ppDisp = NULL;
    return E_NOTIMPL;
}

STDMETHODIMP CToolWnPackage::CreateTool(
                    /*[in]*/ REFGUID rguid) 
{ 
    ATLTRACE(_T("CToolWnPackage::CreateTool\n"));
    _ASSERTE(!m_fZombie);

    USES_CONVERSION;

    if (m_fZombie)
        return E_UNEXPECTED;

    if (rguid == GUID_HelloWorldTool)
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
                        CTW_fInitNew | CTW_fForceCreate,    // dwCTW
                        NULL,                            // dwReserved
                        NULL,                            // punkTool
                        clsidDocObj,                    // rclsidTool
                        GUID_HelloWorldTool,            // rguidPersistanceSlot
                        GUID_NULL,                        // rguidAutoActivate
                        NULL,                            // pSP
                        T2OLE(szTitle),                        // pszCaption 
                        &fDefaultPosition,                // pfDefaultPosition
                        &m_srpToolWinFrame);            // ppWindowFrame
            }
        
            // if CreateToolWindow failed let's give the user a useful error message
            if (FAILED(hr))
                _AtlModule.SetErrorInfo(hr, IDS_E_CANTCREATETOOL, 0);
        }
        return hr;
    }
    return E_INVALIDARG;
}

STDMETHODIMP CToolWnPackage::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ATLTRACE(_T("CToolWnPackage::ResetDefaults\n"));

    return E_NOTIMPL;
}

STDMETHODIMP CToolWnPackage::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage)
{
    ATLTRACE(_T("CToolWnPackage::GetPropertyPage\n"));

    return E_NOTIMPL;
}


///////////////////////////////////////////////////////////////////////////////
// CToolWnPackage IOleCommandTarget Implementation

#pragma warning(disable:4065) // switch statement contains 'default' but no 'case' labels

STDMETHODIMP CToolWnPackage::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(cCmds == 1);
    _ASSERTE(prgCmds && pguidCmdGroup);

    if ((prgCmds == NULL) || (pguidCmdGroup == NULL) || (cCmds != 1))
        return E_INVALIDARG;

    DWORD cmdf;

    if (*pguidCmdGroup == guidToolWnCmdSet)
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
        BOOL fEnable = FALSE;

        switch (prgCmds[0].cmdID)
        {
        case icmdHelloWorld:
            fEnable = TRUE;
            break;


        case icmdTestHelloWorldService:
            if (m_srpToolWinFrame && m_srpToolWinFrame->IsVisible() == S_OK)
                fEnable = TRUE;
            else 
                fEnable = -1;    // our cmd is invisible if tool window is hidden
            break;

        default:
            fEnable = -2;
            break;
        }

        if(fEnable == -2)
          return OLECMDERR_E_NOTSUPPORTED;
        else if(fEnable == -1)
          cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE;
        else if(fEnable)
          cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
        else
          cmdf = OLECMDF_SUPPORTED;
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    prgCmds[0].cmdf = cmdf;
    return S_OK;
}

STDMETHODIMP CToolWnPackage::Exec(
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

    if (*pguidCmdGroup == guidToolWnCmdSet)
    {
        // IOleCommandTargt::Exec should report errors that may occur
        // in the execution of a command. Therefore clear any existing
        // existing error info first
        _AtlModule.ClearErrorInfo();

        switch (nCmdID)
        {
            case icmdHelloWorld:
                {
                hr = ShowToolWinFrame();
                break;
                }

            case icmdTestHelloWorldService:
                {
                CComPtr<IHelloWorldTool> srpHwtService;
                TCHAR szMsg[256];

                if (0 == ::LoadString(_AtlBaseModule.GetResourceInstance(), IDS_HELLOMESSAGE, szMsg, countof(szMsg)))
                {
                    hr = E_OUTOFMEMORY;
                    break;        // we must be out of memory
                }

                hr = _AtlModule.QueryService(SID_SHelloWorldTool, IID_IHelloWorldTool, (void**)&srpHwtService);
                if (FAILED(hr))
                {
                    // Let's give a useful error message if our service is not found
                    _AtlModule.SetErrorInfo(hr, IDS_E_SRVCNOTINSTALLED, 0);
                    break;
                }

                CComBSTR bstrMsg(szMsg);
                if ((srpHwtService != NULL) && (bstrMsg.Length() != 0))
                    hr = srpHwtService->SayHello(bstrMsg);
                
                break;
                } 

            default:    
                return OLECMDERR_E_NOTSUPPORTED;
                break;
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
// CToolWnPackage IServiceProvider Implementation

STDMETHODIMP CToolWnPackage::QueryService(
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

    // We provide one service from our package.
    if (rsid == SID_SHelloWorldTool)
    {
        if( m_srpHwTService == NULL ) {
            m_srpHwTService = new CHelloWorldToolService( this ); // Note: assignment to a smart pointer does an AddRef()
            if( m_srpHwTService == NULL ) 
                return E_OUTOFMEMORY;
        }
        hr = m_srpHwTService->QueryInterface( riid, ppvObject );
    }

    return hr;
}
