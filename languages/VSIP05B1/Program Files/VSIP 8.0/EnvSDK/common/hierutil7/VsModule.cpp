//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Contains misc classes ported from MFC
//
// Microsoft Confidential
// Copyright (C) 1998 - 2000 Microsoft Corporation. All Rights Reserved.
// All rights reserved.
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#include "hu_pch.h"
#include "oleipc.h"
#include "tchar.h"
#include "lutil.h"
#include "vsfile.h"
#define countof(exp) ( sizeof( exp ) / sizeof( ( exp )[0] ) )

// The default constructor sets g_bstrRegRoot internal data to NULL. On the other hand _assigning_ it to NULL, 
// sets internal data to "". GetRegistryRoot() below requires use of the default contructor here.
static CComBSTR g_bstrRegRoot;
static CComBSTR g_bstrSatDll = NULL;


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
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
    ,{ &SID_SHelpService, &IID_IVsHelpSystem, NULL }
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


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CVxModule::CVxModule(LPCTSTR wszTickCounterName /* = Null */) :
    m_lSiteCount(0L),
    m_lLibraryCount(0L),
    m_pszHelpFile(NULL),
    m_dwModuleHelpCtxOffset(0),
    m_lastTickCount(0)
{

    // Check if were doing performance logging
    if (wszTickCounterName)
    {
        m_tickCounterName = wszTickCounterName;
        if (m_tickCounterName != NULL)
        {
            CString tmp;
            tmp.GetEnvironmentVariable(CString(L"VSDEBUGGERPERFLOG"));
            if (!tmp.IsEmpty())
            {
                m_tickCounterLogFile.Attach(tmp.AllocSysString());
            }
        }
    }

}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CVxModule::~CVxModule(void)
{
    delete[] m_pszHelpFile;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CVxModule::SetModuleSite(IServiceProvider *pSP)
{
    (NULL == pSP) ? --m_lSiteCount : ++m_lSiteCount;
    ASSERT(0L <= m_lSiteCount);

    HRESULT hr = S_OK;
    if(!m_srpQIServiceProvider || !m_lSiteCount)
    {   // release cached services
        ASSERT(NULL != g_rgqsPairs);
        ASSERT(g_rgqsPairs < g_pLastPair);

        for(QSPair *pPair = g_rgqsPairs; pPair != g_pLastPair; ++pPair)
        {
            RELEASE(pPair->m_pUnk);
        }
        hr = (NULL != (m_srpQIServiceProvider = pSP)) ? S_OK : E_NOINTERFACE;
    }
    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CVxModule::SetResourcePath(TCHAR *lpstrResource)
{
    TCHAR *pchar;
    TCHAR szModule[_MAX_PATH + 1];
    const TCHAR szResources[]=_T("%s");
    
    GetModuleFileName(_AtlBaseModule.GetModuleInstance(), szModule, _MAX_PATH);
    pchar = szModule;
    
    TCHAR *pcharLast = NULL;

    while (pchar)
    {
        pchar = _tcschr(pchar, _T('\\'));
        if (pchar)
        {
            pcharLast = pchar;
            pchar = CharNext(pchar);
        }
    }
    
    if(pcharLast)
        *pcharLast = _T('\0');

    wsprintf(lpstrResource, szResources,szModule);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
WCHAR *CVxModule::GetRegistryRoot(VOID)
{
    if (g_bstrRegRoot != NULL)
        return g_bstrRegRoot;
    else
        return LREGKEY_VISUALSTUDIOROOT;
}

WCHAR* CVxModule::GetSatelliteFileName()
{ 
    return g_bstrSatDll; 
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CVxModule::QueryService(REFGUID rsid, REFIID iid, void **ppvObj)
{
    _ASSERTE(NULL != ppvObj);
    if(NULL == ppvObj)
        return E_POINTER;
    *ppvObj = NULL;
    
    HRESULT hr = E_NOINTERFACE;
    ASSERT(m_srpQIServiceProvider != NULL); // hmmm, no site
    if(m_srpQIServiceProvider != NULL)
        hr = m_srpQIServiceProvider->QueryService(rsid, iid, ppvObj);
    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
IUnknown* CVxModule::GetCachedI(const unsigned int e)
{
    ASSERT(e < countof(g_rgqsPairs));
    ASSERT(NULL != g_rgqsPairs);

    QSPair *pPair = g_rgqsPairs + e;
    if(NULL == pPair->m_pUnk)
    {
        (void) QueryService(*pPair->m_SID, *pPair->m_IID, (void**)&pPair->m_pUnk);
        // Some of these interfaces are not available in cmd line mode so only assert
        // for those that should be available.
#ifdef _DEBUG
        if(LUtilShellInCmdLineMode())
        {   // Suppress assertion for IVsStatusBar, IVsDebugger, and IVsExtensibility
            if(e != eVsStatusbar && e != eVsDebugger && e != eVsExtensibility)
                ASSERT(pPair->m_pUnk);
        }
        else
        {   // All these should be available
            ASSERT(pPair->m_pUnk);
        }
#endif
    }
    return (pPair->m_pUnk);
}

//---------------------------------------------------------------------------
// load the UI Library only once
//---------------------------------------------------------------------------
HRESULT CVxModule::LoadUILibrary(REFCLSID rclsidPackage, UINT nID)
{
    ASSERT(0 <= m_lLibraryCount);
    HRESULT hr = S_OK;
    if(!m_lLibraryCount++)
    {
        IVsShell *pIVsShell = GetIVsShell();
        if(NULL != pIVsShell)
        {
            HINSTANCE hInst = NULL;
            hr = pIVsShell->LoadUILibrary(rclsidPackage, 0, (DWORD_PTR *)&hInst);
            ASSERT(((S_OK == hr) && (NULL != hInst)) || FAILED(hr));
            if(S_OK != hr)
            {
                hInst = _AtlBaseModule.GetModuleInstance();
                SetErrorInfo(hr, nID, 0);
                ReportErrorInfo(hr);
            }
            // Set the resource instance
            _AtlBaseModule.SetResourceInstance(hInst);
        }
        else hr = E_NOINTERFACE;
    }
    return hr;
}

//---------------------------------------------------------------------------
// load the UI Library only once
//---------------------------------------------------------------------------
void CVxModule::UnloadUILibrary(void)
{
    ASSERT(0 < m_lLibraryCount);
    if(1 == m_lLibraryCount--)
    {
        HINSTANCE hResource = _AtlBaseModule.GetResourceInstance();
        HINSTANCE hModule = _AtlBaseModule.GetModuleInstance();
        ASSERT(hResource != hModule);
        if(hResource != hModule)
        {
            if(NULL != hResource)
            {   // must be protected against NULL
                ::FreeLibrary(hResource);
            }
            _AtlBaseModule.SetResourceInstance(hModule);
        }
    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CVxModule::SetModuleHelpFile(LPCTSTR pszHelpFile, size_t cch)
{
    delete[] m_pszHelpFile;
    m_pszHelpFile = (cch) ? new TCHAR[cch+1] : NULL;
    if(NULL != m_pszHelpFile)
    {
        memcpy(m_pszHelpFile, pszHelpFile, cch * sizeof(TCHAR));
        m_pszHelpFile[cch] = _T('\0');
    }
    else if(cch)
    {
        return E_OUTOFMEMORY;
    }
    USES_CONVERSION;
    m_bstrHelpFile = T2CW(pszHelpFile);
    if(m_bstrHelpFile.Length() || (NULL == pszHelpFile) || (_T('\0') == *pszHelpFile))
        return S_OK;
    return E_OUTOFMEMORY;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CVxModule::DisplayHelpTopic(DWORD dwHelpTopic, long nCommand)
{
    _ASSERTE(NULL != dwHelpTopic);
    _ASSERTE(m_bstrHelpFile.Length());

    HRESULT hr = E_NOINTERFACE;
    IVsHelpSystem *pIVsHelpSystem = GetIVsHelpSystem();
    if(NULL != pIVsHelpSystem)
    {
        hr = pIVsHelpSystem->DisplayTopicFromIdentifier(m_bstrHelpFile, dwHelpTopic, nCommand);
    }
    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CVxModule
::SetErrorInfo(HRESULT hrError, LPCTSTR pszErrMsg, DWORD dwHelpContextID)
{
    if (S_OK == hrError)
    {   // short cut the S_OK case
        ::SetErrorInfo(S_OK, NULL);
        return;
    }        
    IVsUIShell *pIVsUIShell = GetIVsUIShell();
    if(NULL != pIVsUIShell)
    {
        USES_CONVERSION;
        HRESULT hr = pIVsUIShell->SetErrorInfo(
                                    hrError,
                                    T2COLE((LPTSTR)pszErrMsg),
                                    dwHelpContextID,
                                    W2COLE(m_bstrHelpFile),
                                    NULL);  /* pszSource */
        hr; // avoid warning
    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CVxModule::SetErrorInfo(HRESULT hrError, ULONG residErrMsg, DWORD dwHelpContextID)
{
    if (S_OK == hrError)
    {   // short cut the S_OK case
        ::SetErrorInfo(S_OK, NULL);
        return;
    }
    CString strErrMsg;
    strErrMsg.LoadString(residErrMsg);
    SetErrorInfo(hrError, strErrMsg, dwHelpContextID);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CVxModule::ReportErrorInfo(HRESULT hrError)
{
    if (S_OK == hrError)
        return;    // short cut the S_OK case
        
    IVsUIShell *pIVsUIShell = GetVsUIShell();
    if(NULL != pIVsUIShell)
    {
        (void) pIVsUIShell->ReportErrorInfo(hrError);
    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
long CVxModule::ShowMessage(UINT nIDTitle, UINT nIDMsg, UINT nIDHelp,
                              OLEMSGBUTTON nButtons, OLEMSGDEFBUTTON nDefButton,
                              OLEMSGICON nIcon, BOOL fAlert)
{
    USES_CONVERSION;

    _ASSERTE(nIDTitle);
    _ASSERTE(nIDMsg);
    _ASSERTE(m_srpQIServiceProvider);

    HRESULT hr = E_FAIL;
    long nResult = -1;

    IOleComponentUIManager *pCompUIMgr = GetIOleComponentUIManager();
    if(NULL == pCompUIMgr)
        return E_NOINTERFACE;

    LPOLESTR lpszTitle;
    LPOLESTR lpszMessage;

    TCHAR pszTitle[MAX_MSGTITLELEN];
    TCHAR pszMsg[MAX_MSGTEXTLEN];

    LoadString(_AtlBaseModule.GetResourceInstance(), nIDTitle, pszTitle, MAX_MSGTITLELEN);
    LoadString(_AtlBaseModule.GetResourceInstance(), nIDMsg, pszMsg, MAX_MSGTEXTLEN);

#ifdef _UNICODE
    lpszTitle = pszTitle;
    lpszMessage = pszMsg;
#else
    int nLen1 = (int)_tcslen(pszTitle);
    int nLen2 = (int)_tcslen(pszMsg);
    lpszTitle = new WCHAR[nLen1 + 1];
    lpszMessage = new WCHAR[nLen2 + 1];

    VSASSERT(lpszTitle, "");
    VSASSERT(lpszMessage, "");

    if (lpszTitle)
    {
        MultiByteToWideChar(CP_ACP, 0, pszTitle, nLen1, lpszTitle, nLen1+1);
    }

    if (lpszMessage)
    {
        MultiByteToWideChar(CP_ACP, 0, pszMsg, nLen2, lpszMessage, nLen2+1);
    }


#endif
    hr = pCompUIMgr->ShowMessage(OLEROLE_TOPLEVELCOMPONENT,
                                   GUID_NULL,
                                   lpszTitle, lpszMessage,
                                   (nIDHelp != -1) ? m_bstrHelpFile : NULL,
                                   nIDHelp, nButtons, nDefButton, nIcon,
                                   fAlert, &nResult);
    _ASSERTE(SUCCEEDED(hr));

#ifndef _UNICODE
    if (lpszTitle)
    {
        delete lpszTitle;
    }

    if (lpszMessage)
    {
        delete lpszMessage;
    }
#endif
    return nResult;
}


//---------------------------------------------------------------------------
// use the shell to do the CoCreate for us since it also does extra goo
// but if we are not sited, don't call for the local registery because
// it asserts and we want those asserts
//---------------------------------------------------------------------------
HRESULT CVxModule
::VsCreateInstance(REFCLSID rclsid, REFIID riid, void **ppvObj,
                   IUnknown* pUnkOuter, DWORD dwFlags)
{
    ASSERT(NULL != ppvObj);
    *ppvObj = NULL;

    HRESULT hr;
    if(NULL != GetModuleSite())
    {
        hr = E_NOINTERFACE;
        ILocalRegistry *pILocalRegistry = _VxModule.GetILocalRegistry();
        if(NULL != pILocalRegistry)
             hr = pILocalRegistry->CreateInstance(rclsid, pUnkOuter, riid, dwFlags, ppvObj);
    }
    else
    {
        hr = ::CoCreateInstance(rclsid, pUnkOuter, dwFlags, riid, ppvObj);
    }
    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CVxModule::GetIVsUIHierarchyWindow(REFGUID rguidPersistenceSlot,
                         IVsUIHierarchyWindow **ppIVsUIHierarchyWindow)
{
    ASSERT(IID_NULL != rguidPersistenceSlot);
    ASSERT(NULL != ppIVsUIHierarchyWindow && NULL == *ppIVsUIHierarchyWindow);

    HRESULT hr;
    IVsUIShell *pIVsUIShell = GetIVsUIShell();
    ASSERT(NULL != pIVsUIShell);
    if(NULL != pIVsUIShell)
    {
        CComVariant srpvt;
        CComPtr<IVsWindowPane> srpIVsWindowPane;
        CComPtr<IVsWindowFrame> srpIVsWindowFrame;

        hr = pIVsUIShell->FindToolWindow(NULL, rguidPersistenceSlot, &srpIVsWindowFrame);
        if(FAILED(hr))
            goto EXIT_JUMP;
        ASSERT(srpIVsWindowFrame != NULL);

        hr = srpIVsWindowFrame->GetProperty(VSFPROPID_DocView, &srpvt);
        if(FAILED(hr))
            goto EXIT_JUMP;

        ASSERT(VT_UNKNOWN == V_VT(&srpvt));
        if(VT_UNKNOWN != V_VT(&srpvt))
        {
            hr = E_FAIL;
            goto EXIT_JUMP;
        }
        ASSERT(NULL != V_UNKNOWN(&srpvt));

        hr = V_UNKNOWN(&srpvt)->QueryInterface(IID_IVsWindowPane, (void **)&srpIVsWindowPane);
        if(FAILED(hr))
            goto EXIT_JUMP;
        ASSERT(srpIVsWindowPane != NULL);

        hr = srpIVsWindowPane.QueryInterface(ppIVsUIHierarchyWindow);
        if(FAILED(hr))
            goto EXIT_JUMP;
        ASSERT(NULL != *ppIVsUIHierarchyWindow);
    }
    else hr = E_NOINTERFACE;

EXIT_JUMP:
    return hr;
}

HRESULT CVxModule::VSDllUnregisterServer(LPOLESTR pwszRegRoot)
{
    if( NULL == pwszRegRoot )
    {
        g_bstrRegRoot = LREGKEY_VISUALSTUDIOROOT;
    }
    else
    {
        g_bstrRegRoot = pwszRegRoot;
    }

    // Check if the object map is empty.
    if ( (NULL==_AtlComModule.m_ppAutoObjMapFirst) || (NULL==*(_AtlComModule.m_ppAutoObjMapFirst)) )
    {
        // Fall back to the old and obsolete _Module ( CComObject ) because it is possible that the client
        // is still using the old ATL macros like BEGIN_OBJECT_MAP.
        if (NULL != _pModule)
            return _pModule->UnregisterServer();
    }
    
    return _AtlComModule.UnregisterServer();
}

HRESULT CVxModule::VSDllRegisterServer(LPOLESTR pwszRegRoot, LPOLESTR pwszSatDll, BOOL bRegTypeLib /*= TRUE*/)
{
    if( NULL == pwszRegRoot )
    {
        g_bstrRegRoot = LREGKEY_VISUALSTUDIOROOT;
    }
    else
    {
        g_bstrRegRoot = pwszRegRoot;
    }
    
    _ASSERTE(pwszSatDll);
    g_bstrSatDll = pwszSatDll;

    // Check if the object map if empty.
    if ( (NULL==_AtlComModule.m_ppAutoObjMapFirst) || (NULL==*(_AtlComModule.m_ppAutoObjMapFirst)) )
    {
        // It is possible that the map is empty because the client of this module is still using the
        // obsolete macros ( BEGIN_OBJECT_MAP ... ), so we have to fall back to the obsolete _Module.
        if ( NULL != _pModule)
            return _pModule->RegisterServer(bRegTypeLib);
    }

    // Call the method of the global object that will do all the work.
    return _AtlComModule.RegisterServer(bRegTypeLib);
}

void CVxModule::OutputTickCounterString(LPCWSTR wszMsg)
{
    DWORD           currentTickCount;
    DWORD           deltaTicks;
    CString         strFormattedMessage;
    CVsStdioFile    file;

    // Check if any work to do
    if (m_tickCounterName == NULL || *m_tickCounterName == L'\0' ||
        m_tickCounterLogFile == NULL || *m_tickCounterLogFile == L'\0' ||
        wszMsg == NULL)
    {
        return;
    }

    // Get the tick counts
    currentTickCount = GetTickCount();
    deltaTicks = m_lastTickCount ? currentTickCount - m_lastTickCount : 0;
    m_lastTickCount = currentTickCount;     // update last value for next time
    
    // Format the tick counter message
    strFormattedMessage.Format(
            CString(L"%d (%.8s + %8d) : %s\r\n"), // this should match the debug package's format
            currentTickCount, 
            m_tickCounterName, 
            deltaTicks,
            wszMsg);
    
    // output to log file
    CString temp(m_tickCounterLogFile); // use CString to perform ANSI conversion if needed
    if (file.Open(temp, 
            CVsFile::modeCreate | 
            CVsFile::modeNoTruncate | 
            CVsFile::modeWrite | 
            CVsFile::typeText))
    {
        DWORD tmp;
        file.Seek(0, SEEK_END, &tmp);
        file.WriteString(strFormattedMessage);
        file.Close();
    }
}

