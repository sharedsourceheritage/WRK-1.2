
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
    _AtlBaseModule.SetResourceInstance(hInst);
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
        HINSTANCE hResource = _AtlBaseModule.GetResourceInstance();
        HINSTANCE hModule = _AtlBaseModule.GetModuleInstance();
        _ASSERTE(hResource != hModule);
        if(hResource != hModule)
        {
            if(NULL != hResource)
            {   
                // must be protected against NULL
                ::FreeLibrary(hResource);
            }
            _AtlBaseModule.SetResourceInstance(hModule);
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
        /* HINSTANCE hInstance */ _AtlBaseModule.GetResourceInstance(),// handle to resource module
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
    if ( ! LoadString(_AtlBaseModule.GetResourceInstance(), nIDTitle, pszTitle, MAX_MSGTITLELEN))
    {
        _ASSERTE(FALSE);
        return -1;
    }

    TCHAR pszMsg[MAX_MSGTEXTLEN];
    if ( ! LoadString(_AtlBaseModule.GetResourceInstance(), nIDMsg, pszMsg, MAX_MSGTEXTLEN))
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

    int iTitleSize = lstrlen(pszTitle) + 1;
    int iMessageSize = lstrlen(pszMsg) + 1;
    LPOLESTR lpszTitle   = new WCHAR[iTitleSize];
    LPOLESTR lpszMessage = new WCHAR[iMessageSize];
    _ASSERTE(lpszTitle && lpszMessage);
    if ((lpszTitle == NULL) || (lpszMessage == NULL))
        goto Error;

    if ( FAILED(StringCchCopy(lpszTitle, iTitleSize, pszTitle)) )
    {
        _ASSERTE(FALSE);
        goto Error;
    }
    if ( FAILED(StringCchCopy(lpszMessage, iTitleSize, pszMsg)) )
    {
        _ASSERTE(FALSE);
        goto Error;
    }

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

    const ULONG cchBuffer = _MAX_PATH;
    WCHAR wszRegistrationRoot[cchBuffer];
    if (pwszRegRoot)
    {
        hr = StringCchCopy(wszRegistrationRoot, cchBuffer, pwszRegRoot);
        if ( FAILED(hr) )
            return hr;
    }
    else
    {
        hr = StringCchCopy(wszRegistrationRoot, cchBuffer, LREGKEY_VISUALSTUDIOROOT_NOVERSION);
        if ( FAILED(hr) )
            return hr;
        hr = StringCchCat(wszRegistrationRoot, cchBuffer, L"\\");
        if ( FAILED(hr) )
            return hr;
        
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
            hr = StringCchCopy(wszRegistrationRoot, cchBuffer, LREGKEY_VISUALSTUDIOROOT);
            if ( FAILED(hr) )
                return hr;
        }
    }
       
    CComBSTR cbstrRootBegin;
    CComBSTR cbstrRootEnd;
    
    // Make sure the string ends in backslash to simplify loop 
    // for processing backslashes.
    size_t sizeRegRoot;
    hr = StringCchLength(wszRegistrationRoot, cchBuffer, &sizeRegRoot);
    if ( FAILED(hr) )
        return hr;
    if(wszRegistrationRoot[sizeRegRoot - 1] != L'\\')
    {
        hr = StringCchCat(wszRegistrationRoot, cchBuffer, L"\\");
        if (FAILED(hr))
            return hr;
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
    DWORD dwLen = ::GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), wszModuleFullName, cchBuffer);
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
    DWORD dwLen = ::GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), wszModuleFullName, cchBuffer);
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


//                                                             REGISTRATION
//=========================================================================

