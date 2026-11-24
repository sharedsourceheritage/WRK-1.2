
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsModule.h

#pragma once 

#define MAX_MSGTITLELEN         128
#define MAX_MSGTEXTLEN          512

// forward declarations
interface IServiceProvider;
interface IVsUIHierarchyWindow;
// cached interfaces
interface IVsShell;
interface IVsUIShell;
interface IVsSolution;
interface Help;
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


// CVsComModule Implementation
// Extends the ATL CComModule with operations specific to the host.
class CVsComModule :
    public CAtlDllModuleT<CVsComModule> 
{
public:
     CVsComModule(void);
    ~CVsComModule(void);

    DECLARE_LIBID(LIBID_OptPkgLib);

    // Set (clear with NULL) the module site IServiceProvider
    void Close(void) { SetModuleSite(NULL); }
    HRESULT SetModuleSite(IServiceProvider* pSiteSP);

    IServiceProvider* GetModuleSite(void)
    {
        return m_srpQIServiceProvider;   // un-addref'd
    }

    HRESULT QueryService(REFGUID refiid, REFIID riid, void **ppvObj);
    IUnknown* GetCachedI(const unsigned int e);

    //----------------------------------------------------------------------
    // Load the UI Library only once
    // Initialize "_AtlBaseModule.m_hInstResource" to point to our localized 
    // satellite DLL.
    // After this point _AtlBaseModule.GetResourceInstance() will return the hinst of 
    // our localized satellite DLL not our VsPackage implementation DLL.
    //----------------------------------------------------------------------
    HRESULT LoadUILibrary(REFCLSID rclsidPackage, UINT nIDError);

    //----------------------------------------------------------------------
    // Unload the UI Library only once
    // If this is the last call, then the resource dll instance
    // will be restored to the module's instance
    //----------------------------------------------------------------------
    void    UnloadUILibrary(void);

    //----------------------------------------------------------------------
    // use the shell to do the CoCreate for us
    // but if we are not sited, don't call for the local registery because
    // it asserts and we want those asserts
    //----------------------------------------------------------------------
    HRESULT VsCreateInstance(REFCLSID rclsid, REFIID riid, void **ppvObj,
                    IUnknown* pUnkOuter = NULL, DWORD dwFlags = CLSCTX_INPROC_SERVER);

    HRESULT GetIVsUIHierarchyWindow(REFGUID rguidPersistenceSlot,
                                 IVsUIHierarchyWindow **ppIVsUIHierarchyWindow);

    // cached on demand services
    enum {  // REQUIRED to stay in same order as two other structures
         eVsShell
        ,eVsUIShell
        ,eVsSolution
        ,eHelp
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
    Help* GetHelp(void)
    {
        return reinterpret_cast<Help*>(GetCachedI(eHelp));
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


//=========================================================================
//                                                    HELP, ERROR, MESSAGES
public:

    //---------------------------------------------------------------------
    // Function:    SetErrorInfo
    //              Helper method to set up error information that should 
    //              be reported back to the user when an error HRESULT is 
    //              first originated.
    // Parameters: 
    //    /* [in] */ HRESULT   hrError,
    //              Error result
    //    /* [in] */ LPCTSTR   pszErrMsg,
    //              Message to be displayed
    //    /* [in] */ LPCOLESTR pwszHelpKeyword = NULL);
    //              A keyword used for help lookup
    // Returns:     void
    // Notes:
    //---------------------------------------------------------------------
     void SetErrorInfo(
        /* [in] */ HRESULT   hrError,
        /* [in] */ LPCTSTR   pszErrMsg,
        /* [in] */ LPCOLESTR pwszHelpKeyword = NULL);

    //---------------------------------------------------------------------
    // Function:    SetErrorInfo
    //              Helper method to set up error information that should 
    //              be reported back to the user when an error HRESULT is 
    //              first originated. It loads the error string from the UI 
    //              dll, and sets the global ErrorInfo object
    // Parameters: 
    //    /* [in] */ HRESULT   hrError,
    //              Error result
    //    /* [in] */ ULONG     residErrMsg,
    //              Resource id of the error message
    //    /* [in] */ LPCOLESTR pwszHelpKeyword = NULL);
    //              A keyword used for help lookup
    // Returns:     void
    // Notes:
    //---------------------------------------------------------------------
    void SetErrorInfo(
        /* [in] */ HRESULT   hrError,
        /* [in] */ ULONG     residErrMsg,
        /* [in] */ LPCOLESTR pwszHelpKeyword = NULL);

    //---------------------------------------------------------------------
    // Function:    ClearErrorInfo
    //              Clears the error info in the global ErrorInfo object.
    // Parameters: 
    // Returns:     void
    // Notes:
    //---------------------------------------------------------------------
    void ClearErrorInfo(void)
    {
        (void)::SetErrorInfo(S_OK, 0);
    }

    //---------------------------------------------------------------------
    // Function:    ReportErrorInfo
    //              Reports the error info saved in the global ErrorInfo 
    //              object.
    // Parameters: 
    //              /* [in] */ HRESULT hrError
    //              Error result
    // Returns:     void
    // Notes:
    //---------------------------------------------------------------------
    void ReportErrorInfo(/* [in] */ HRESULT hrError);

    //---------------------------------------------------------------------
    // Function:    ShowMessage
    //              Brings up the Environment Messagebox with the strings 
    //              specified with resource id
    // Parameters: 
    //    /* [in] */ UINT             nIDTitle, 
    //    /* [in] */ UINT             nIDMsg, 
    //    /* [in] */ OLEMSGBUTTON     nButtons    = OLEMSGBUTTON_OK, 
    //    /* [in] */ OLEMSGDEFBUTTON  nDefButton  = OLEMSGDEFBUTTON_FIRST,
    //    /* [in] */ OLEMSGICON       nIcon       = OLEMSGICON_CRITICAL, 
    //    /* [in] */ BOOL             fAlert      = FALSE);
    // Returns:     long
    // Notes:
    //---------------------------------------------------------------------
    long ShowMessage(
        /* [in] */ UINT             nIDTitle, 
        /* [in] */ UINT             nIDMsg, 
        /* [in] */ OLEMSGBUTTON     nButtons    = OLEMSGBUTTON_OK, 
        /* [in] */ OLEMSGDEFBUTTON  nDefButton  = OLEMSGDEFBUTTON_FIRST,
        /* [in] */ OLEMSGICON       nIcon       = OLEMSGICON_CRITICAL, 
        /* [in] */ BOOL             fAlert      = FALSE);

    //---------------------------------------------------------------------
    // Function:    ShowMessage
    //              Brings up the Environment Messagebox with the strings 
    //              passed in
    // Parameters: 
    //    /* [in] */ LPCTSTR          pszTitle, 
    //    /* [in] */ LPCTSTR          pszMsg, 
    //    /* [in] */ OLEMSGBUTTON     nButtons    = OLEMSGBUTTON_OK, 
    //    /* [in] */ OLEMSGDEFBUTTON  nDefButton  = OLEMSGDEFBUTTON_FIRST,
    //    /* [in] */ OLEMSGICON       nIcon       = OLEMSGICON_CRITICAL, 
    //    /* [in] */ BOOL             fAlert      = FALSE);
    // Returns:     long
    // Notes:
    //---------------------------------------------------------------------
    long ShowMessage(
        /* [in] */ LPCTSTR          pszTitle, 
        /* [in] */ LPCTSTR          pszMsg, 
        /* [in] */ OLEMSGBUTTON     nButtons    = OLEMSGBUTTON_OK, 
        /* [in] */ OLEMSGDEFBUTTON  nDefButton  = OLEMSGDEFBUTTON_FIRST,
        /* [in] */ OLEMSGICON       nIcon       = OLEMSGICON_CRITICAL, 
        /* [in] */ BOOL             fAlert      = FALSE);

//                                                    HELP, ERROR, MESSAGES
//=========================================================================

        
//=========================================================================
//                                                             REGISTRATION
public:
    //---------------------------------------------------------------------
    // Function:    GetRegRootStrings
    //              Contruct strings to be used in _ATL_REGMAP_ENTRY for the 
    //              registry root (REGROOTBEGIN and REGROOTEND)
    // Parameters: 
    //    /* [out] */ BSTR *       pbstrRootBegin, 
    //              Replacement string for REGROOTBEGIN. It looks like
    //              "NoRemove Software \n{\n NoRemove Microsoft \n{\n NoRemove 
    //              VisualStudio \n{\n NoRemove 7.1 \n{\n"
    //    /* [out] */ BSTR *       pbstrRootEnd,
    //              Replacement string for REGROOTEND. It looks like
    //              "\n}\n \n}\n \n}\n \n}\n"
    //    /* [in]  */ const WCHAR* pwszRegRoot = NULL)
    //              Registry string that will be parsed to generate
    //              pbstrRootBegin and pbstrRootEnd.
    //              If pwszRegRoot is NULL the default (LREGKEY_VISUALSTUDIOROOT_NOVERSION) 
    //              string will be used along with the string specified by 
    //              EnvSdk_RegKey environment variable. The Environment SDK 
    //              sample code checks for  EnvSdk_RegKey environment variable. 
    //              If the variable exists then it is added to the default 
    //              L"Software\\Microsoft\\VisualStudio\\" registry string.
    //              EnvSdk_RegKey is expected to be of the form "7.x" or "7.xexp".
    //              If  EnvSdk_RegKey does not exist the default (LREGKEY_VISUALSTUDIOROOT)
    //              string will be used i.e. L"Software\\Microsoft\\VisualStudio\\7.1"
    // Returns:     HRESULT
    // Notes:
    //---------------------------------------------------------------------
    STDMETHOD(GetRegRootStrings)(
        /* [out] */ BSTR *       pbstrRootBegin, 
        /* [out] */ BSTR *       pbstrRootEnd,
        /* [in]  */ const WCHAR* pwszRegRoot = NULL);

    //---------------------------------------------------------------------
    // Function:    GetRegDefaultResourceStrings
    //              Contruct strings to be used in _ATL_REGMAP_ENTRY for the 
    //              resource dll (RESOURCE_PATH and RESOURCE_DLL)
    // Parameters: 
    //    /* [out] */ BSTR *      pbstrResDllPath, // optional, can be NULL
    //              Replacement string for RESOURCE_PATH. 
    //
    //    /* [out] */ BSTR *      pbstrResDllName) // optional, can be NULL
    //              Replacement string for RESOURCE_DLL. 
    //              UI suffix is added to the name of the main dll.
    // Returns:     HRESULT
    // Notes:
    //---------------------------------------------------------------------
    STDMETHOD(GetRegDefaultResourceStrings)(
        /* [out] */ BSTR * pbstrResDllPath, // optional, can be NULL
        /* [out] */ BSTR * pbstrResDllName);// optional, can be NULL

    //---------------------------------------------------------------------
    // Function:    GetRegDefaultTemplatePath
    //              Contruct strings to be used in _ATL_REGMAP_ENTRY for the 
    //              template path (TEMPLATE_PATH)
    // Parameters: 
    //    /* [out] */ BSTR *      pbstrTemplatePath)
    //              Replacement string for TEMPLATE_PATH. 
    //
    // Returns:     HRESULT
    // Notes:
    //---------------------------------------------------------------------
    STDMETHOD(GetRegDefaultTemplatePath)(
        /* [out] */ BSTR *      pbstrTemplatePath);

//                                                             REGISTRATION
//=========================================================================

protected:
    long m_lSiteCount;
    long m_lLibraryCount;

    CComQIPtr<IServiceProvider> m_srpQIServiceProvider;
};
