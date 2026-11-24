
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsModule.cpp

#include "stdafx.h"
#include "VsModule.h"
#include <strsafe.h>

#ifndef RELEASE
#define RELEASE(PUNK)                \
{                                    \
    if (PUNK)                        \
    {                                \
        LPUNKNOWN punkXXX = (PUNK);  \
        (PUNK) = NULL;               \
        punkXXX->Release();          \
    }                                \
}
#endif

#ifndef countof
#define countof(exp) ( sizeof( exp ) / sizeof( ( exp )[0] ) )
#endif

typedef struct QSPair
{
    const GUID *m_SID;
    const GUID *m_IID;
    IUnknown  *m_pUnk; // the cached pointer
} QSPair;

static QSPair g_rgqsPairs[] =
{
     { &SID_SVsShell, &IID_IVsShell, NULL }
    ,{ &SID_SVsUIShell, &IID_IVsUIShell, NULL }
    ,{ &SID_SVsSolution, &IID_IVsSolution, NULL }
    ,{ &SID_SVsHelp, &IID_Help, NULL }
    ,{ &SID_SLocalRegistry, &IID_ILocalRegistry, NULL }
    ,{ &SID_SUIHostLocale, &IID_IUIHostLocale2, NULL }
    ,{ &SID_SVsShellMonitorSelection, &IID_IVsMonitorSelection, NULL }
    ,{ &SID_SVsUIShellOpenDocument, &IID_IVsUIShellOpenDocument, NULL }
    ,{ &SID_SVsRunningDocumentTable, &IID_IVsRunningDocumentTable, NULL }
    ,{ &SID_SOleComponentUIManager, &IID_IOleComponentUIManager, NULL }
    ,{ &SID_SVsStatusbar, &IID_IVsStatusbar, NULL }
    ,{ &SID_SVsShellDebugger, &IID_IVsDebugger, NULL }
    ,{ &VxDTE::SID_SVsExtensibility, &VxDTE::IID_IVsExtensibility, NULL }
    ,{ &VxDTE::SID_SExtensionManager, &VxDTE::IID_ObjectExtenders, NULL }
};

// precomputed pointer to end of the array
static QSPair *g_pLastPair = g_rgqsPairs + countof(g_rgqsPairs);


//=========================================================================
//                                         construct, destruct, init, close
CVsComModule::CVsComModule(void) :
    m_lSiteCount(0L),
    m_lLibraryCount(0L)
{}


CVsComModule::~CVsComModule(void)
{}


HRESULT CVsComModule::SetModuleSite(IServiceProvider *pSP)
{
    // In order to support a single package implementation DLL being used on
    // behalf of multiple registered packages, we keep a count of the times
    // SetModuleSite is called.
    // A single package DLL pretending to be multiple registered packages 
    // will get site'd once for each package, and each package will be
    // closed once, but internally we need to be site'd just once and
    // closed just once, therefore we keep a count in m_lSiteCount.
    // NOTE: This is an advanced feature. most package dlls will be used
    //       only on behalf of a single registered package.

    pSP ? m_lSiteCount++ : m_lSiteCount--;
    _ASSERTE(0L <= m_lSiteCount);

    if (pSP && (m_lSiteCount == 1))
    {
        // this is the first SiteModuleSite(pSite) call, do initialization.
        _ASSERTE(m_srpQIServiceProvider == NULL);
        m_srpQIServiceProvider = pSP;
        if (!m_srpQIServiceProvider)
            return E_NOINTERFACE;
        return S_OK;
    }
    else if ((pSP == NULL) && (m_lSiteCount == 0))
    {        
        // this is the last SiteModuleSite(NULL) call, do clean up 

        // time to release all the services we have been caching
        _ASSERTE(NULL != g_rgqsPairs);
        _ASSERTE(g_rgqsPairs < g_pLastPair);

        for(QSPair *pPair = g_rgqsPairs; pPair != g_pLastPair; ++pPair)
        {
            RELEASE(pPair->m_pUnk);
        }

        // finally release the site
        m_srpQIServiceProvider.Release();
    }
    return S_OK;
}
//                                         construct, destruct, init, close
//=========================================================================


HRESULT CVsComModule::QueryService(REFGUID rsid, REFIID iid, void **ppvObj)
{
    _ASSERTE(NULL != ppvObj);
    if(NULL == ppvObj)
        return E_POINTER;
    *ppvObj = NULL;
    
    HRESULT hr = E_NOINTERFACE;
    _ASSERTE(m_srpQIServiceProvider != NULL); // hmmm, no site
    if(m_srpQIServiceProvider != NULL)
        hr = m_srpQIServiceProvider->QueryService(rsid, iid, ppvObj);
    return hr;
}


IUnknown* CVsComModule::GetCachedI(const unsigned int e)
{
    _ASSERTE(e < countof(g_rgqsPairs));
    _ASSERTE(NULL != g_rgqsPairs);

    QSPair *pPair = g_rgqsPairs + e;
    if(NULL == pPair->m_pUnk)
    {
        (void) QueryService(*pPair->m_SID, *pPair->m_IID, (void**)&pPair->m_pUnk);
        // Some of these interfaces are not available in cmd line mode so only assert
        // for those that should be available.
#ifdef _DEBUG
        BOOL fShellInCmdLineMode = FALSE;
        IVsShell* pShell = GetIVsShell();
        if(pShell)
        {
            CComVariant var;
            if(SUCCEEDED(pShell->GetProperty(VSSPROPID_IsInCommandLineMode, &var)))
            {
                fShellInCmdLineMode = (var.boolVal == VARIANT_TRUE);
            }
        }

        if(fShellInCmdLineMode)
        {   // Suppress assertion for IVsStatusBar, IVsDebugger, and IVsExtensibility
            if(e != eVsStatusbar && e != eVsDebugger && e != eVsExtensibility)
                _ASSERTE(pPair->m_pUnk);
        }
        else
        {   // All these should be available
            _ASSERTE(pPair->m_pUnk);
        }
#endif
    }
    return (pPair->m_pUnk);
}


HRESULT CVsComModule::LoadUILibrary(REFCLSID rclsidPackage, UINT nID)
{
    _ASSERTE(0 <= m_lLibraryCount);
    if (m_lLibraryCount < 0)
        return E_UNEXPECTED;

    if(m_lLibraryCount > 0)
    {
        m_lLibraryCount++;
        return S_OK;
    }

    // m_lLibraryCount == 0
    IVsShell *pIVsShell = GetIVsShell();
    if(NULL == pIVsShell)
        return E_NOINTERFACE;

    HRESULT   hr    = S_OK;
    HINSTANCE hInst = NULL;
    hr = pIVsShell->LoadUILibrary(rclsidPackage, 0, (DWORD_PTR *)&hInst);   
    _ASSERTE( SUCCEEDED(hr) && (NULL != hInst));
    if (FAILED(hr) || (NULL == hInst))
    {
        if (SUCCEEDED(hr))
            hr = E_UNEXPECTED;
        // report the error. nIDError is the id of a string
        // resource within the package dll itself
        SetErrorInfo(hr, nID, 0);
        ReportErrorInfo(hr);
        return hr;
    }

    // Set the resource instance
    SetResourceInstance(hInst);
    m_lLibraryCount++;

    return hr;
}


void CVsComModule::UnloadUILibrary(void)
{
    _ASSERTE(0 < m_lLibraryCount);
    if (m_lLibraryCount <= 0)
    {
        // '0' might happen if the call to LoadUILibrary had failed
        return;
    }

    if (m_lLibraryCount == 1)
    {
        _ASSERTE(GetResourceInstance() != GetModuleInstance());
        if(GetResourceInstance() != GetModuleInstance())
        {
            if(NULL != GetResourceInstance())
            {   
                // must be protected against NULL
                ::FreeLibrary(GetResourceInstance());
            }
            SetResourceInstance(GetModuleInstance());
        }
    }

    m_lLibraryCount--;
}


HRESULT CVsComModule::VsCreateInstance(REFCLSID rclsid, REFIID riid, void **ppvObj,
                   IUnknown* pUnkOuter, DWORD dwFlags)
{
    _ASSERTE(NULL != ppvObj);
    if (ppvObj == NULL)
        return E_POINTER;
    *ppvObj = NULL;

    HRESULT hr;
    if(NULL != GetModuleSite())
    {
        hr = E_NOINTERFACE;
        ILocalRegistry *pILocalRegistry = GetILocalRegistry();
        if(NULL != pILocalRegistry)
             hr = pILocalRegistry->CreateInstance(rclsid, pUnkOuter, riid, dwFlags, ppvObj);
    }
    else
    {
        hr = ::CoCreateInstance(rclsid, pUnkOuter, dwFlags, riid, ppvObj);
    }
    return hr;
}


HRESULT CVsComModule::GetIVsUIHierarchyWindow(REFGUID rguidPersistenceSlot,
                         IVsUIHierarchyWindow **ppIVsUIHierarchyWindow)
{
    _ASSERTE(IID_NULL != rguidPersistenceSlot);
    _ASSERTE(NULL != ppIVsUIHierarchyWindow);
    if (NULL == ppIVsUIHierarchyWindow)
        return E_POINTER;
    *ppIVsUIHierarchyWindow = NULL;

    HRESULT hr;
    IVsUIShell *pIVsUIShell = GetIVsUIShell();
    _ASSERTE(NULL != pIVsUIShell);
    if(NULL != pIVsUIShell)
    {
        CComVariant srpvt;
        CComPtr<IVsWindowPane> srpIVsWindowPane;
        CComPtr<IVsWindowFrame> srpIVsWindowFrame;

        hr = pIVsUIShell->FindToolWindow(NULL, rguidPersistenceSlot, &srpIVsWindowFrame);
        if(FAILED(hr))
            goto EXIT_JUMP;
        _ASSERTE(srpIVsWindowFrame != NULL);

        hr = srpIVsWindowFrame->GetProperty(VSFPROPID_DocView, &srpvt);
        if(FAILED(hr))
            goto EXIT_JUMP;

        _ASSERTE(VT_UNKNOWN == V_VT(&srpvt));
        if(VT_UNKNOWN != V_VT(&srpvt))
        {
            hr = E_FAIL;
            goto EXIT_JUMP;
        }
        _ASSERTE(NULL != V_UNKNOWN(&srpvt));

        hr = V_UNKNOWN(&srpvt)->QueryInterface(IID_IVsWindowPane, (void **)&srpIVsWindowPane);
        if(FAILED(hr))
            goto EXIT_JUMP;
        _ASSERTE(srpIVsWindowPane != NULL);

        hr = srpIVsWindowPane.QueryInterface(ppIVsUIHierarchyWindow);
        if(FAILED(hr))
            goto EXIT_JUMP;
        _ASSERTE(NULL != *ppIVsUIHierarchyWindow);
    }
    else hr = E_NOINTERFACE;

EXIT_JUMP:
    return hr;
}


//=========================================================================
//                                                    HELP, ERROR, MESSAGES

void CVsComModule::SetErrorInfo(
    /* [in] */ HRESULT   hrError,
    /* [in] */ LPCTSTR   pszErrMsg,
    /* [in] */ LPCOLESTR pwszHelpKeyword /* = NULL */)
{
    if (SUCCEEDED(hrError))
    {
        ClearErrorInfo();
        return;
    }

    IVsUIShell *pIVsUIShell = GetIVsUIShell();
    if(NULL != pIVsUIShell)
    {
        USES_CONVERSION;
        HRESULT hr = pIVsUIShell->SetErrorInfo(
            /* [in] HRESULT   hr             */ hrError,
            /* [in] LPCOLESTR pszDescription */ T2COLE((LPCTSTR)pszErrMsg),
            /* [in] DWORD     dwReserved     */ NULL,
            /* [in] LPCOLESTR pszHelpKeyword */ pwszHelpKeyword,
            /* [in] LPCOLESTR pszSource      */ NULL);
        _ASSERTE(SUCCEEDED(hr));
    }
}


void CVsComModule::SetErrorInfo(
    /* [in] */ HRESULT   hrError,
    /* [in] */ ULONG     residErrMsg,
    /* [in] */ LPCOLESTR pwszHelpKeyword /* = NULL */)
{
    if (SUCCEEDED(hrError))
    {
        ClearErrorInfo();
        return;
    }

    TCHAR pszErrMsg[MAX_MSGTEXTLEN];

#ifdef _DEBUG
    pszErrMsg[countof(pszErrMsg)-1] = _T('\0');
#endif
    int nResult = LoadString(
        /* HINSTANCE hInstance */ GetResourceInstance(),// handle to resource module
        /* UINT uID            */ residErrMsg,          // resource identifier
        /* LPTSTR lpBuffer     */ pszErrMsg,            // resource buffer
        /* int nBufferMax      */ countof(pszErrMsg));   // size of buffer
    if (nResult == 0)
    {
        _ASSERTE(FALSE);
        return;
    }
    _ASSERTE(pszErrMsg[countof(pszErrMsg)-1] == _T('\0'));

    SetErrorInfo(hrError, pszErrMsg, pwszHelpKeyword);
}


void CVsComModule::ReportErrorInfo(HRESULT hrError)
{
    if (S_OK == hrError)
        return;    // short cut the S_OK case
        
    IVsUIShell *pIVsUIShell = GetIVsUIShell();
    if(NULL != pIVsUIShell)
    {
        (void) pIVsUIShell->ReportErrorInfo(hrError);
    }
}

long CVsComModule::ShowMessage(
    /* [in] */ UINT             nIDTitle, 
    /* [in] */ UINT             nIDMsg, 
    /* [in] */ OLEMSGBUTTON     nButtons, 
    /* [in] */ OLEMSGDEFBUTTON  nDefButton,
    /* [in] */ OLEMSGICON       nIcon, 
    /* [in] */ BOOL             fAlert)
{
    _ASSERTE(nIDTitle);
    _ASSERTE(nIDMsg);

    TCHAR pszTitle[MAX_MSGTITLELEN];
    if ( ! LoadString(GetResourceInstance(), nIDTitle, pszTitle, MAX_MSGTITLELEN))
    {
        _ASSERTE(FALSE);
        return -1;
    }

    TCHAR pszMsg[MAX_MSGTEXTLEN];
    if ( ! LoadString(GetResourceInstance(), nIDMsg, pszMsg, MAX_MSGTEXTLEN))
    {
        _ASSERTE(FALSE);
        return -1;
    }

    return ShowMessage(pszTitle, pszMsg, nButtons, nDefButton, nIcon, fAlert);
}


long CVsComModule::ShowMessage(
    /* [in] */ LPCTSTR          pszTitle, 
    /* [in] */ LPCTSTR          pszMsg, 
    /* [in] */ OLEMSGBUTTON     nButtons, 
    /* [in] */ OLEMSGDEFBUTTON  nDefButton,
    /* [in] */ OLEMSGICON       nIcon, 
    /* [in] */ BOOL             fAlert)
{
    HRESULT hr      = E_FAIL;
    long    nResult = -1;

    _ASSERTE(pszTitle && pszMsg);
    if ((pszTitle == NULL) || (pszMsg == NULL))
        return nResult;

    IOleComponentUIManager *pCompUIMgr = GetIOleComponentUIManager();
    _ASSERTE(NULL != pCompUIMgr);
    if(NULL == pCompUIMgr)
        return nResult;

    int nLen1 = lstrlen(pszTitle);
    int nLen2 = lstrlen(pszMsg);
    LPOLESTR lpszTitle   = new WCHAR[nLen1 + 1];
    LPOLESTR lpszMessage = new WCHAR[nLen2 + 1];
    _ASSERTE(lpszTitle && lpszMessage);
    if ((lpszTitle == NULL) || (lpszMessage == NULL))
        goto Error;

#ifdef _UNICODE
    if ( ! lstrcpyW(lpszTitle, pszTitle))
    {
        _ASSERTE(FALSE);
        goto Error;
    }
    if ( ! lstrcpyW(lpszMessage, pszMsg))
    {
        _ASSERTE(FALSE);
        goto Error;
    }
#else
    if ( ! MultiByteToWideChar(CP_ACP, 0, pszTitle, nLen1, lpszTitle, nLen1+1))
    {
        _ASSERTE(FALSE);
        goto Error;
    }
    lpszTitle[nLen1] = L'\0';
    if ( ! MultiByteToWideChar(CP_ACP, 0, pszMsg, nLen2, lpszMessage, nLen2+1))
    {
        _ASSERTE(FALSE);
        goto Error;
    }
    lpszMessage[nLen2] = L'\0';
#endif
    hr = pCompUIMgr->ShowMessage(
       /* DWORD dwCompRole          */ OLEROLE_TOPLEVELCOMPONENT,
       /* REFCLSID rclsidComp       */ GUID_NULL,
       /* LPOLESTR pszTitle         */ lpszTitle,
       /* LPOLESTR pszText          */ lpszMessage,
       /* LPOLESTR pszHelpFile      */ NULL,
       /* DWORD dwHelpContextID     */ NULL,
       /* OLEMSGBUTTON msgbtn       */ nButtons,
       /* OLEMSGDEFBUTTON msgdefbtn */ nDefButton,
       /* OLEMSGICON msgicon        */ nIcon,
       /* BOOL fSysAlert            */ fAlert,
       /* [retval] LONG* pnResult   */ &nResult);
    _ASSERTE(SUCCEEDED(hr));

Error:
    delete [] lpszTitle;
    delete [] lpszMessage;

    return nResult;
}

//                                                    HELP, ERROR, MESSAGES
//=========================================================================


//=========================================================================
//                                                             REGISTRATION

STDMETHODIMP CVsComModule::GetRegRootStrings(
    /* [out] */ BSTR *       pbstrRootBegin, 
    /* [out] */ BSTR *       pbstrRootEnd,
    /* [in]  */ const WCHAR* pwszRegRoot /* = NULL */)
{
    _ASSERTE(pbstrRootBegin && pbstrRootEnd);
    if(!pbstrRootBegin || !pbstrRootEnd)
        return E_POINTER;

    HRESULT hr = S_OK;

    const ULONG cchBuffer = _MAX_PATH + 1;
    WCHAR wszRegistrationRoot[cchBuffer];
    if (pwszRegRoot)
    {
        hr = StringCchCopyW(wszRegistrationRoot, cchBuffer, pwszRegRoot);
        if (FAILED(hr)) return hr;
    }
    else
    {
        hr = StringCchCopyW(wszRegistrationRoot, cchBuffer, LREGKEY_VISUALSTUDIOROOT_NOVERSION);
        if (FAILED(hr)) return hr;
        hr = StringCchCatW(wszRegistrationRoot, cchBuffer, L"\\");
        if (FAILED(hr)) return hr;
        
        // this is Environment SDK specific
        // we check for  EnvSdk_RegKey environment variable to
        // determine where to register
        DWORD cchDefRegRoot = lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION) + 1;
        DWORD cchFreeBuffer = cchBuffer - cchDefRegRoot;
        DWORD cchEnvVarRead = GetEnvironmentVariableW(
            /* LPCTSTR */ L"EnvSdk_RegKey",               // environment variable name
            /* LPTSTR  */ &wszRegistrationRoot[cchDefRegRoot],// buffer for variable value
            /* DWORD   */ cchFreeBuffer);// size of buffer
        if (cchEnvVarRead >= cchFreeBuffer)
            return E_UNEXPECTED;
        // If the environment variable does not exist then we must use 
        // LREGKEY_VISUALSTUDIOROOT which has the version number.
        if (0 == cchEnvVarRead)
        {
            hr = StringCchCopyW(wszRegistrationRoot, cchBuffer, LREGKEY_VISUALSTUDIOROOT);
            if (FAILED(hr)) return hr;
        }
    }
       
    CComBSTR cbstrRootBegin;
    CComBSTR cbstrRootEnd;
    
    // Make sure the string ends in backslash to simplify loop 
    // for processing backslashes.
    int len = (int)wcslen(wszRegistrationRoot);
    if(wszRegistrationRoot[len - 1] != L'\\')
    {
        hr = StringCchCatW(wszRegistrationRoot, cchBuffer, L"\\");
        if (FAILED(hr)) return hr;
    }

    WCHAR * pStart = wszRegistrationRoot;
    WCHAR * pSlash = wcschr(wszRegistrationRoot, L'\\');

    while(pSlash)
    {
        *pSlash = 0;
        hr = cbstrRootBegin.Append(L" NoRemove ");
        if (FAILED(hr)) 
            return hr;

        hr = cbstrRootBegin.Append(pStart);
        if (FAILED(hr)) 
            return hr;

        hr = cbstrRootBegin.Append(L"\n{\n");
        if (FAILED(hr)) 
            return hr;

        hr = cbstrRootEnd.Append(L"\n}\n");
        if (FAILED(hr)) 
            return hr;

        pStart = pSlash + 1;
        pSlash = wcschr(pStart, L'\\');
    }

    *pbstrRootBegin = cbstrRootBegin.Detach();
    *pbstrRootEnd   = cbstrRootEnd.Detach();

    return S_OK;
}


STDMETHODIMP CVsComModule::GetRegDefaultResourceStrings(
    /* [out] */ BSTR * pbstrResDllPath, // optional, can be NULL
    /* [out] */ BSTR * pbstrResDllName) // optional, can be NULL
{
    HRESULT hr = S_OK;

    const DWORD cchBuffer=_MAX_PATH;
    WCHAR wszModuleFullName[cchBuffer];
    DWORD dwLen = ::GetModuleFileNameW(GetModuleInstance(), wszModuleFullName, cchBuffer);
    if (dwLen == 0)
        return HRESULT_FROM_WIN32(::GetLastError());
    if (dwLen == cchBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    
    WCHAR wszDrive[_MAX_DRIVE];
    WCHAR wszDir[_MAX_DIR];
    WCHAR wszFName[_MAX_FNAME];
    WCHAR wszExt[_MAX_EXT];

    _wsplitpath(wszModuleFullName, wszDrive, wszDir, wszFName, wszExt);

    CComBSTR cbstrResDllName(wszFName);
    if (!cbstrResDllName) 
        return E_OUTOFMEMORY;
    hr = cbstrResDllName.Append(L"UI");
    if (FAILED(hr)) 
        return hr;
    hr = cbstrResDllName.Append(wszExt);
    if (FAILED(hr)) 
        return hr;

    CComBSTR cbstrResDllPath(wszDrive);
    if (!cbstrResDllPath) 
        return E_OUTOFMEMORY;
    hr = cbstrResDllPath.Append(wszDir);
    if (FAILED(hr)) 
        return hr;

    if (pbstrResDllPath)
        *pbstrResDllPath = cbstrResDllPath.Detach();
    if (pbstrResDllName)
        *pbstrResDllName = cbstrResDllName.Detach();

    return S_OK;
}


STDMETHODIMP CVsComModule::GetRegDefaultTemplatePath(
    /* [out] */ BSTR *      pbstrTemplatePath)
{
    _ASSERTE(pbstrTemplatePath != NULL);
    if (!pbstrTemplatePath)
        return E_POINTER;

    HRESULT hr = S_OK;

    const DWORD cchBuffer=_MAX_PATH;
    WCHAR wszModuleFullName[cchBuffer];
    DWORD dwLen = ::GetModuleFileNameW(GetModuleInstance(), wszModuleFullName, cchBuffer);
    if (dwLen == 0)
        return HRESULT_FROM_WIN32(::GetLastError());
    if (dwLen == cchBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    // strip off the filename
    LPWSTR pwsz = wcsrchr(wszModuleFullName, L'\\');
    _ASSERTE(NULL != pwsz);
    if( pwsz != NULL )
        *pwsz = 0;

    // strip off 1 dir (debug\release)
    pwsz = wcsrchr(wszModuleFullName, L'\\');
    _ASSERTE(NULL != pwsz);
    if( pwsz != NULL )
        *(pwsz+1) = 0; //leave \ at the end

    CComBSTR cbstrInstallPath = wszModuleFullName;
    if (!cbstrInstallPath)
        return E_OUTOFMEMORY;

    *pbstrTemplatePath = cbstrInstallPath.Detach();

    return S_OK;
}

STDMETHODIMP CVsComModule::GetRegDevenvPath(
    /* [out] */ BSTR *      pbstrDevenvPath)
{
    _ASSERTE(pbstrDevenvPath != NULL);
    if (!pbstrDevenvPath)
        return E_POINTER;

    HRESULT hr = S_OK;

    const DWORD cchBuffer=_MAX_PATH + 1;

    // get the reg hive
    WCHAR wszRegistrationRoot[cchBuffer];
    hr = StringCchCopyW(wszRegistrationRoot, cchBuffer, LREGKEY_VISUALSTUDIOROOT_NOVERSION);
    if (FAILED(hr)) return hr;
    hr = StringCchCatW(wszRegistrationRoot, cchBuffer, L"\\");
    if (FAILED(hr)) return hr;
    DWORD cchDefRegRoot = lstrlenW(wszRegistrationRoot);
    DWORD cchFreeBuffer = cchBuffer - cchDefRegRoot;
    
    // this is Environment SDK specific
    // we check for  EnvSdk_RegKey environment variable to
    // determine where to register
    DWORD cchEnvVarRead = GetEnvironmentVariableW(
        /* LPCTSTR */ L"EnvSdk_RegKey",                    // environment variable name
        /* LPTSTR  */ &wszRegistrationRoot[cchDefRegRoot], // buffer for variable value
        /* DWORD   */ cchFreeBuffer);                      // size of buffer
    if (cchEnvVarRead >= cchFreeBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    // If the environment variable does not exist then we must use 
    // LREGKEY_VISUALSTUDIOROOT which has the version number.
    if (0 == cchEnvVarRead)
    {
        hr = StringCchCopyW(wszRegistrationRoot, cchBuffer, LREGKEY_VISUALSTUDIOROOT);
        if (FAILED(hr)) return hr;
    }

    const WCHAR wszVsSetup[] = L"\\Setup\\VS";
    hr = StringCchCatW(wszRegistrationRoot, cchBuffer, wszVsSetup);
    if (FAILED(hr)) return hr;
    
    CRegKey keySetupVs;
    LONG lStatus = keySetupVs.Open(HKEY_LOCAL_MACHINE, W2CT(wszRegistrationRoot));
    if (lStatus != ERROR_SUCCESS)
        return E_UNEXPECTED;

    const TCHAR szDevEnvLocation[]   = _T("EnvironmentPath");
    DWORD cchDevEnvBuffer = cchBuffer;
    TCHAR szDevenvPath[cchBuffer];

    lStatus = keySetupVs.QueryStringValue(szDevEnvLocation,szDevenvPath, &cchDevEnvBuffer);
    if (lStatus != ERROR_SUCCESS)
    {
        // try the environment directory
        cchDevEnvBuffer = cchBuffer;
        const TCHAR szEnvironmentDirectory[]   = _T("EnvironmentDirectory");
        lStatus = keySetupVs.QueryStringValue(szEnvironmentDirectory ,szDevenvPath, &cchDevEnvBuffer);
        if (lStatus != ERROR_SUCCESS)
            return E_FAIL;
        int len = lstrlen(szDevenvPath);
        if ((len <= 0) || (len >= cchBuffer - 2))
            return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

        if(szDevenvPath[len-1] != '\\' )
        {
            hr = StringCchCat(szDevenvPath, cchBuffer, _T("\\"));
            if (FAILED(hr)) return hr;
        }

        const TCHAR szDevenvExe[]   = _T("devenv.exe");
        hr = StringCchCat(szDevenvPath, cchBuffer, szDevenvExe);
        if (FAILED(hr)) return hr;
    }

    // now we have the devenv path
    CComBSTR cbstrDevenvPath = szDevenvPath;
    if (cbstrDevenvPath.Length() == 0)
        return E_OUTOFMEMORY;

    *pbstrDevenvPath = cbstrDevenvPath.Detach();
    return S_OK;
}

STDMETHODIMP CVsComModule::GetRegProgidVersion(
    /* [out] */ BSTR *      pbstrProgidVersion)
{
    _ASSERTE(pbstrProgidVersion != NULL);
    if (!pbstrProgidVersion)
        return E_POINTER;

    // Set up the default value
    CComBSTR cbstrProgidVersion = RGS_VAR_PROGID_VERSION;
    if (cbstrProgidVersion.Length() == 0)
        return E_OUTOFMEMORY;

    HRESULT hr = S_OK;

    const DWORD cchBuffer=_MAX_PATH + 1;

    // get the environment variable EnvSdk_RegKey
    WCHAR wszEnvSdk_RegKey[cchBuffer];
    DWORD cchFreeBuffer = cchBuffer - 1;
    
    // this is Environment SDK specific
    // we check for  EnvSdk_RegKey environment variable to
    // determine the version number for our ProgID.
    DWORD cchEnvVarRead = GetEnvironmentVariableW(
        /* LPCTSTR */ L"EnvSdk_RegKey",               // environment variable name
        /* LPTSTR  */ wszEnvSdk_RegKey,               // buffer for variable value
        /* DWORD   */ cchFreeBuffer);                 // size of buffer
    if (cchEnvVarRead >= cchFreeBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    // If the environment variable does not exist then we must use 
    // RGS_VAR_PROGID_VERSION which has the version number.
    if (0 == cchEnvVarRead)
    {
        *pbstrProgidVersion = cbstrProgidVersion.Detach();
        return S_OK;
    }

    // We now look explicitly for version 7.0. If the environment variable doesn't
    // start with 7.0 we use the default RGS_VAR_PROGID_VERSION.
    if (wcsncmp(L"7.0", wszEnvSdk_RegKey, wcslen(L"7.0")) == 0)
        cbstrProgidVersion = L"7.0";

    *pbstrProgidVersion = cbstrProgidVersion.Detach();
    return S_OK;
}


STDMETHODIMP CVsComModule::GetRegDdeName(
    /* [out] */ BSTR *      pbstrDdeName)
{
    _ASSERTE(pbstrDdeName != NULL);
    if (!pbstrDdeName)
        return E_POINTER;

    // Set up the default value
    CComBSTR cbstrDdeName = RGS_VAR_DDE_NAME;
    if (cbstrDdeName.Length() == 0)
        return E_OUTOFMEMORY;

    HRESULT hr = S_OK;

    const DWORD cchBuffer=_MAX_PATH + 1;

    // get the environment variable EnvSdk_RegKey
    WCHAR wszEnvSdk_RegKey[cchBuffer];
    DWORD cchFreeBuffer = cchBuffer - 1;
    
    // this is Environment SDK specific
    // we check for  EnvSdk_RegKey environment variable to
    // determine the dde name. If EnvSdk_RegKey begins with
    // 7.0 we explicitly use "devenv" as our DDE_NAME. 
    // Otherwise we stick with the default(RGS_VAR_DDE_NAME).
    DWORD cchEnvVarRead = GetEnvironmentVariableW(
        /* LPCTSTR */ L"EnvSdk_RegKey",               // environment variable name
        /* LPTSTR  */ wszEnvSdk_RegKey,               // buffer for variable value
        /* DWORD   */ cchFreeBuffer);                 // size of buffer
    if (cchEnvVarRead >= cchFreeBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    // If the environment variable does not exist then we must use 
    // RGS_VAR_DDE_NAME which has the version number.
    if (0 == cchEnvVarRead)
    {
        *pbstrDdeName = cbstrDdeName.Detach();
        return S_OK;
    }

    // We now look explicitly for version 7.0. If the environment variable doesn't
    // start with 7.0 we use the default RGS_VAR_DDE_NAME.
    if (wcsncmp(L"7.0", wszEnvSdk_RegKey, wcslen(L"7.0")) == 0)
        cbstrDdeName = L"devenv";

    *pbstrDdeName = cbstrDdeName.Detach();
    return S_OK;
}


//                                                             REGISTRATION
//=========================================================================
