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

#ifndef __VSMODULE_H__
#define __VSMODULE_H__

#include <docobj.h>
#include <oleipc.h>

#define MAX_MSGTITLELEN         128
#define MAX_MSGTEXTLEN          512

// forward declarations
interface IServiceProvider;

// cached interfaces
interface IVsShell;
interface IVsUIShell;
interface IVsSolution;
interface IVsHelpSystem;
interface ILocalRegistry;
interface IUIHostLocale2;
interface IVsMonitorSelection;
interface IVsUIShellOpenDocument;
interface IVsRunningDocumentTable;
interface IOleComponentUIManager;
interface IVsStatusbar;
interface IVsDebugger;

namespace VxDTE
{
    // Forward declare the V7 DTE objects that are referenced by this header.  They are wrapped
    // with #ifndefs to avoid type redefinition errors that can occur of DTE.h happens to be
    // #included after vsmodule.
    #ifndef __ObjectExtenders_FWD_DEFINED__    
    interface ObjectExtenders;
    typedef interface ObjectExtenders ObjectExtenders;
    #define __ObjectExtenders_FWD_DEFINED__
    #endif
    
    #ifndef __IVsExtensibility_FWD_DEFINED__
    interface IVsExtensibility;
    typedef interface IVsExtensibility IVsExtensibility;
    #define __IVsExtensibility_FWD_DEFINED__
    #endif
};

// other interfaces
interface IVsUIHierarchyWindow;

//---------------------------------------------------------------------------
// Global VxModule class. Create one in your dll called _VxModule just like is
// done for _Module
//---------------------------------------------------------------------------
class CVxModule
{
public:
     CVxModule(LPCTSTR wszTickCounterName = NULL);
    ~CVxModule(void);

public:
    // Set (clear with NULL) the module site IServiceProvider
    void Close(void) { SetModuleSite(NULL); }
    HRESULT SetModuleSite(IServiceProvider* pSiteSP);
    void SetResourcePath(TCHAR *lpstrResource);
    WCHAR *GetRegistryRoot(VOID);
    WCHAR* GetSatelliteFileName();

    // Helpers to get module/resource instances.
    HINSTANCE   GetModuleInstance()
    {
        return _AtlBaseModule.GetModuleInstance();
    }
    HINSTANCE   GetResourceInstance()
    {
        return _AtlBaseModule.GetResourceInstance();
    }
    IServiceProvider* GetModuleSite(void)
    {
        return m_srpQIServiceProvider;   // un-addref'd
    }

    HRESULT QueryService(REFGUID refiid, REFIID riid, void **ppvObj);

    template<class T> HRESULT QueryService(REFGUID refiid, T **ppv)
    {   // the simplified typesafe version
        return QueryService(refiid, __uuidof(T), (void **)ppv);
    }
    IUnknown* GetCachedI(const unsigned int e);

    // load the satellite dll replacing the module's default ResourceInstance
    HRESULT LoadUILibrary(REFCLSID rclsidPackage, UINT nIDError);
    void  UnloadUILibrary(void);

    // Sets the help file to be used with the package
    HRESULT SetModuleHelpFile(LPCTSTR pszHelpFile, size_t cch);
    HRESULT SetModuleHelpFile(LPCTSTR pszHelpFile)
    {
        size_t cch = (NULL != pszHelpFile) ? _tcslen(pszHelpFile) : 0;
        return SetModuleHelpFile(pszHelpFile, cch);
    }
    LPCTSTR GetModuleHelpFile(void) const
    {
        return m_pszHelpFile;
    }
    
    HRESULT VSDllUnregisterServer(LPOLESTR pwszRegRoot);

    HRESULT VSDllRegisterServer(LPOLESTR pwszRegRoot, LPOLESTR pwszSatDll, BOOL bRegTypeLib = TRUE);
public:
    HRESULT DisplayHelpTopic(DWORD dwHelpTopic, long nCommand = 0x4/*VHS_Localize | VHS_Default*/);

    // This is the offset applied to the help context id's. Usually the help context id is the 
    // resid + this offset to provide uniqueness. Used by LUtilMessageBox().
    DWORD GetModuleHelpCtxOffset() { return m_dwModuleHelpCtxOffset;}
    void SetModuleHelpCtxOffset(DWORD dwHelpCtxOffset) {m_dwModuleHelpCtxOffset = dwHelpCtxOffset;}

    // This is a helper method to set up error information 
    // that should be reported back to the user when an 
    // error HRESULT is first originated.
    //
    void ClearErrorInfo(void)
    {
        (void)::SetErrorInfo(S_OK, 0);
    }
    void SetErrorInfo(
                /* [in] */ HRESULT hrError,
                /* [in] */ LPCTSTR pszErrMsg,
                /* [in] */ DWORD dwHelpContextID);
    void SetErrorInfo(
                /* [in] */ HRESULT hrError,
                /* [in] */ ULONG residErrMsg,
                /* [in] */ DWORD dwHelpContextID);
    void ReportErrorInfo(HRESULT hrError);

    long ShowMessage(UINT nIDTitle, UINT nIDMsg, UINT nIDHelp = -1,
                    OLEMSGBUTTON nButtons = OLEMSGBUTTON_OK,
                    OLEMSGDEFBUTTON nDefButton = OLEMSGDEFBUTTON_FIRST,
                    OLEMSGICON nIcon = OLEMSGICON_CRITICAL,
                    BOOL fAlert = FALSE);

public:
    HRESULT VsCreateInstance(REFCLSID rclsid, REFIID riid, void **ppvObj,
                    IUnknown* pUnkOuter = NULL, DWORD dwFlags = CLSCTX_ALL);

    template<class T>
    HRESULT VsCreateInstance(REFCLSID rclsid, T **ppObj,
                    IUnknown* pUnkOuter = NULL, DWORD dwFlags = CLSCTX_ALL)
    {
        return VsCreateInstance(rclsid, __uuidof(T), (void**)ppObj, pUnkOuter, dwFlags);
    }

    HRESULT GetIVsUIHierarchyWindow(REFGUID rguidPersistenceSlot,
                                 IVsUIHierarchyWindow **ppIVsUIHierarchyWindow);

public: // cached on demand services
    enum {  // REQUIRED to stay in same order as two other structures
         eVsShell
        ,eVsUIShell
        ,eVsSolution
        ,eVsHelpSystem
        ,eLocalRegistry
        ,eUIHostLocale2
        ,eVsMonitorSelection
        ,eVsUIShellOpenDocument
        ,eVsRunningDocumentTable
        ,eOleComponentUIManager
        ,eVsStatusbar
        ,eVsDebugger
        ,eVsExtensibility
        ,eVsObjectExtenders
    };
    
    IServiceProvider* GetIServiceProvider(void)
    {
        return GetModuleSite();
    }
    IVsShell* GetIVsShell(void)
    {
        return reinterpret_cast<IVsShell*>(GetCachedI(eVsShell));
    }
    IVsUIShell* GetIVsUIShell(void)
    {
        return reinterpret_cast<IVsUIShell*>(GetCachedI(eVsUIShell));
    }
    IVsSolution* GetIVsSolution(void)
    {
        return reinterpret_cast<IVsSolution*>(GetCachedI(eVsSolution));
    }
    IVsHelpSystem* GetIVsHelpSystem(void)
    {
        return reinterpret_cast<IVsHelpSystem*>(GetCachedI(eVsHelpSystem));
    }
    ILocalRegistry* GetILocalRegistry(void)
    {
        return reinterpret_cast<ILocalRegistry*>(GetCachedI(eLocalRegistry));
    }
    IUIHostLocale2* GetIUIHostLocale2(void)
    {
        return reinterpret_cast<IUIHostLocale2*>(GetCachedI(eUIHostLocale2));
    }
    IVsMonitorSelection* GetIVsMonitorSelection(void)
    {
        return reinterpret_cast<IVsMonitorSelection*>(GetCachedI(eVsMonitorSelection));
    }
    IVsUIShellOpenDocument* GetIVsUIShellOpenDocument(void)
    {
        return reinterpret_cast<IVsUIShellOpenDocument*>(GetCachedI(eVsUIShellOpenDocument));
    }
    IVsRunningDocumentTable* GetIVsRunningDocumentTable(void)
    {
        return reinterpret_cast<IVsRunningDocumentTable*>(GetCachedI(eVsRunningDocumentTable));
    }
    IOleComponentUIManager* GetIOleComponentUIManager(void)
    {
        return reinterpret_cast<IOleComponentUIManager*>(GetCachedI(eOleComponentUIManager));
    }

    IVsStatusbar* GetIVsStatusbar(void)
    {
        return reinterpret_cast<IVsStatusbar*>(GetCachedI(eVsStatusbar));
    }
    IVsDebugger* GetIVsDebugger(void)
    {
        return reinterpret_cast<IVsDebugger*>(GetCachedI(eVsDebugger));
    }

    VxDTE::IVsExtensibility* GetIVsExtensibility(void)
    {
        return reinterpret_cast<VxDTE::IVsExtensibility*>(GetCachedI(eVsExtensibility));
    }


    VxDTE::ObjectExtenders* GetObjectExtenders(void)
    {
            return reinterpret_cast<VxDTE::ObjectExtenders*>(GetCachedI(eVsObjectExtenders));
    }

        
    IVsUIShell* GetVsUIShell(void)
    {   // temporary
        return GetIVsUIShell();
    }

public:
    // Emits a tick-counter message to the profile log
    // if the environment variable VSDEBUGGERPERFLOG is set.
    // This varable contains the name of the log file.
    void OutputTickCounterString(LPCWSTR wszMsg);


protected:
    long m_lSiteCount;
    long m_lLibraryCount;

    LPTSTR m_pszHelpFile;
    DWORD m_dwModuleHelpCtxOffset;
    CComBSTR m_bstrHelpFile;
    CComQIPtr<IServiceProvider> m_srpQIServiceProvider;

    CComBSTR m_tickCounterLogFile;
    CComBSTR m_tickCounterName;
    DWORD   m_lastTickCount;
};

#endif // __VSMODULE_H__
