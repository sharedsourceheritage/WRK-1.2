
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cpp : Implementation of CAIWToolPackage
//

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"

#define TWIPS_PER_INCH  1440
double FontSizeOfLogfontHeight(LONG lfHeight)
{
    HDC hdc = GetDC(NULL);
    double lpy = GetDeviceCaps(hdc, LOGPIXELSY);
    double twipsPerPixel = ((double)TWIPS_PER_INCH) / lpy;
    double dFontSize = - (twipsPerPixel * lfHeight) / 20.0;
    return dFontSize;
}

/////////////////////////////////////////////////////////////////////////////
// CAIWToolPackage

CAIWToolPackage::CAIWToolPackage()
{
    ATLTRACE(_T("Creating CAIWToolPackage: 0x%X\n"), this);

    m_fZombie = FALSE;
}

CAIWToolPackage::~CAIWToolPackage()
{
    ATLTRACE(_T("Destructing CAIWToolPackage: 0x%X\n"), this);
}


/* static */ 
HRESULT WINAPI CAIWToolPackage::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = _AtlModule.GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    if (FAILED(hr)) return hr;

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName;
    hr = _AtlModule.GetRegDefaultResourceStrings(&cbstrResDllPath, &cbstrResDllName);
    if (FAILED(hr)) return hr;

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_AIWToolPackage);
    if (!cbstrCLSID_Package) return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_AutomationImmediateWindow(GUID_AutomationImmediateWindow);
    if (!cbstrGUID_AutomationImmediateWindow) return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_TaskList(GUID_TaskList);
    if (!cbstrGUID_TaskList) return E_OUTOFMEMORY;

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    WCHAR wszIDS_OFFICIALNAME[iMaxResIdLen];
    WCHAR wszIDS_PRODUCTDETAILS[iMaxResIdLen];
    _ultow(IDS_PACKAGE_LOAD_KEY, wszIDS_PACKAGE_LOAD_KEY, 10);
    _ultow(IDS_OFFICIALNAME,   wszIDS_OFFICIALNAME,   10);
    _ultow(IDS_PRODUCTDETAILS, wszIDS_PRODUCTDETAILS, 10);

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"RESOURCE_PATH",                  cbstrResDllPath},
        {L"RESOURCE_DLL",                   cbstrResDllName},
        {L"CLSID_Package",                  cbstrCLSID_Package},
        {L"GUID_AutomationImmediateWindow", cbstrGUID_AutomationImmediateWindow},
        {L"GUID_TaskList",                  cbstrGUID_TaskList},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_OFFICIALNAME",               wszIDS_OFFICIALNAME},
        {L"IDS_PRODUCTDETAILS",             wszIDS_PRODUCTDETAILS},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResource(IDR_PACKAGE, bRegister, rgMap);
}

HRESULT CAIWToolPackage::ShowToolWinFrame(void)
{ 
    HRESULT hr = S_OK;

    // it is important to delay creating tool windows for performance reasons.
    // a good strategy is to wait until the first time that the tool window
    // needs to be shown. this is why we put the call to CreateTool in ShowToolWinFrame.
    if (!m_srpToolWinFrame)
        hr = CreateTool(GUID_AutomationImmediateWindow);    // call our own IVsPackage::CreateTool method
    if (SUCCEEDED(hr))
        hr = m_srpToolWinFrame->Show();
    return hr;
}

/////////////////////////////////////////////////////////////////////////////
// CAIWToolPackage IVsPackage Implementation

STDMETHODIMP CAIWToolPackage::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ATLTRACE(_T("CAIWToolPackage::SetSite\n"));
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
    hr = _AtlModule.LoadUILibrary(CLSID_AIWToolPackage, IDS_E_BADINSTALL);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }

    return S_OK;
}

STDMETHODIMP CAIWToolPackage::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ATLTRACE(_T("CAIWToolPackage::QueryClose\n"));
    _ASSERTE(pCanClose);

    *pCanClose = TRUE;
    return S_OK;
}

STDMETHODIMP CAIWToolPackage::Close(void)
{
    ATLTRACE(_T("CAIWToolPackage::Close\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;
    
    HRESULT hr = S_OK;

    if (m_srpVBSCommandLine)
    {
        hr = m_srpVBSCommandLine->Reset();
        m_srpVBSCommandLine.Release();
    }

    m_srpToolWinFrame.Release();

    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);

    // set our state for protection
    m_fZombie = TRUE;
    return hr;
}

STDMETHODIMP CAIWToolPackage::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ATLTRACE(_T("CAIWToolPackage::GetAutomationObject\n"));
    _ASSERTE(ppDisp);

    *ppDisp = NULL;
    return E_NOTIMPL;
}

STDMETHODIMP CAIWToolPackage::CreateTool(
                    /*[in]*/ REFGUID rguid) 
{ 
    ATLTRACE(_T("CAIWToolPackage::CreateTool\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    USES_CONVERSION;

    if (rguid == GUID_AutomationImmediateWindow)
    {
        CComPtr<IVsUIShell> srpShell;

        // now get the IVsUIShell interface so we can create a tool window
        //
        HRESULT hr = _AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpShell);

        if (SUCCEEDED(hr))
        {
            CLSID clsidDocObj;
            BOOL    fDefaultPosition = TRUE;
            TCHAR szTitle[128];

            ::LoadString(_AtlBaseModule.GetResourceInstance(), IDS_WINDOW_TITLE, szTitle, countof(szTitle));

            hr = CLSIDFromProgID(L"ScriptControl.ScriptControl", &clsidDocObj);
            if (SUCCEEDED(hr))
            {
                hr = srpShell->CreateToolWindow(
                        CTW_fInitNew | CTW_fForceCreate,    // dwCTW
                        NULL,                           // dwReserved
                        NULL,                           // punkTool
                        clsidDocObj,                    // rclsidTool
                        GUID_AutomationImmediateWindow, // rguidPersistanceSlot
                        GUID_NULL,                      // rguidAutoActivate
                        NULL,                           // pSP
                        T2OLE(szTitle),                 // pszCaption 
                        &fDefaultPosition,              // pfDefaultPosition
                        &m_srpToolWinFrame);            // ppWindowFrame
            }
            // if CreateToolWindow failed let's give the user a useful error message
            if (FAILED(hr))
            {
                _AtlModule.SetErrorInfo(hr, IDS_E_CANTCREATETOOL, 0);
                return hr;
            }

            // retrieve the pointer to our custom IVBSCommandLine interface on our VB object
            CComPtr<IUnknown> srpUnkVBObj;
            CComVariant varPunk;
            _ASSERTE(m_srpToolWinFrame);
            if (! m_srpToolWinFrame)
                return E_UNEXPECTED;
            m_srpToolWinFrame->GetProperty(VSFPROPID_DocView, &varPunk);
            srpUnkVBObj = (IUnknown *) V_UNKNOWN(&varPunk);
            _ASSERTE(srpUnkVBObj);
            if (! srpUnkVBObj)
                return E_UNEXPECTED;
            hr = srpUnkVBObj->QueryInterface(IID_IVBSCommandLine, (void **)&m_srpVBSCommandLine);
            _ASSERTE(m_srpVBSCommandLine);
            if (! m_srpVBSCommandLine)
                return E_UNEXPECTED;

            // retrieve the Environment FontFamily and FontSize to pass into our tool window
            CComPtr<IUIHostLocale> srpUIHostLocale;
            _AtlModule.QueryService(SID_SUIHostLocale, IID_IUIHostLocale, (void **) &srpUIHostLocale);
            _ASSERTE(srpUIHostLocale);
            if (! srpUIHostLocale)
                return E_UNEXPECTED;
            UIDLGLOGFONT logfont;
            srpUIHostLocale->GetDialogFont(&logfont);
            CComBSTR bstrFontName(logfont.lfFaceName);
            double dFontSize = FontSizeOfLogfontHeight(logfont.lfHeight);
            m_srpVBSCommandLine->Init(logfont.lfCharSet, bstrFontName, dFontSize);

            // Add our DTE object into the script engine namespace
            CComBSTR bstrDTE("DTE");
            CComPtr<IDispatch> srpDTE;
            _AtlModule.QueryService(SID_SDTE, IID_IDispatch, (void **) &srpDTE);
            m_srpVBSCommandLine->AddObject(bstrDTE, srpDTE, VARIANT_TRUE);

            //initialize the bitmap
            CComVariant cvar;
            cvar = IDB_CMDBARICONS;
            m_srpToolWinFrame->SetProperty(
                    /* [in] VSFPROPID propid */  VSFPROPID_BitmapResource,
                    /* [in] VARIANT   var    */  cvar);

            cvar = bmpidAutoImmedWin - 1;          // cmdbar bitmap indexes are 1-based
            m_srpToolWinFrame->SetProperty(
                    /* [in] VSFPROPID propid */  VSFPROPID_BitmapIndex,
                    /* [in] VARIANT   var    */  cvar);

            return hr;
        }
    }
    return E_UNEXPECTED;
}

STDMETHODIMP CAIWToolPackage::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ATLTRACE(_T("CAIWToolPackage::ResetDefaults\n"));

    return E_NOTIMPL;
}

STDMETHODIMP CAIWToolPackage::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage)
{
    ATLTRACE(_T("CAIWToolPackage::GetPropertyPage\n"));

    return E_NOTIMPL;
}


///////////////////////////////////////////////////////////////////////////////
// CAIWToolPackage IOleCommandTarget Implementation

#pragma warning(disable:4065) // switch statement contains 'default' but no 'case' labels

STDMETHODIMP CAIWToolPackage::QueryStatus(
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

    if (*pguidCmdGroup == guidAIWToolCmdSet)
    {
        // The following bitwise flags control the state of a command:
        //      OLECMDF_SUPPORTED, OLECMDF_ENABLED, OLECMDF_LATCHED,
        //      OLECMDF_NINCHED, OLECMDF_INVISIBLE, OLECMDF_DEFHIDEONCTXTMENU
        //
        // Common cases are the following:
        //  1. Enable a command --  cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED
        //  2. Disable a command -- cmdf = OLECMDF_SUPPORTED
        //  3. Hide a command --    cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE
        cmdf = OLECMDF_SUPPORTED;

        BOOL fEnable = FALSE;
        switch(prgCmds[0].cmdID)
        {
        case icmdAutoImmedWin:
            fEnable = TRUE;
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

STDMETHODIMP CAIWToolPackage::Exec(
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

    if (*pguidCmdGroup == guidAIWToolCmdSet)
    {
        // IOleCommandTargt::Exec should report errors that may occur
        // in the execution of a command. Therefore clear any existing
        // existing error info first
        _AtlModule.ClearErrorInfo();

        switch (nCmdID)
        {
            case icmdAutoImmedWin:
                {
                hr = ShowToolWinFrame();
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
// CAIWToolPackage IServiceProvider Implementation

STDMETHODIMP CAIWToolPackage::QueryService(
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
