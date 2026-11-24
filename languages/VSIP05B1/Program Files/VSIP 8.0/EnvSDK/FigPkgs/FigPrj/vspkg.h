
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// vspkg.h : Declaration of the CVsPackage and interfaces

#pragma once

extern HINSTANCE g_hInstance;

/////////////////////////////////////////////////////////////////////////////
// forward declarations

/////////////////////////////////////////////////////////////////////////////

// CVsPackage

class CVsPackage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVsPackage, &CLSID_FigPrjPackage>,
	public IVsPackage, 
	public IVsInstalledProduct,
	public IOleCommandTarget,
	public IServiceProvider
{

public:
	CVsPackage();
	virtual ~CVsPackage();

    //---------------------------------------------------------------------
    // Function:    UpdateRegistry
    //              Contruct the _ATL_REGMAP_ENTRY and update the registry. 
    // Parameters: 
    //    /* [in] */ BOOL bRegister 
    //              Flag - to register or unregister
    //
    // Returns:     HRESULT
    //
    // Notes:
    //              Certain strings that will be seen by the user need to be 
    //              put in the registry. The VS way of doing this is to put 
    //              the string in the registry as '#40' where 40 is the 
    //              resource id of the string in the satellite dll (so that 
    //              the string can be localized properly). Unfortunately, if
    //              we put '#40' in the rgs file, then someone can change the 
    //              id of the string. This routine sets up a symbol table of 
    //              replacements for things found in the rgs file, and then 
    //              calls the appropriate routine to register the rgs file 
    //              after it's been preprocessed.
    //              Also, to make the rgs file easy to understand, replacement 
    //              variables for CLSIDs and GUIDs are used. The names of 
    //              the CLSIDs and GUIDs are used rather than the 
    //              corresponding values. 
    //  
    //              Replacement variables used in registry script (.rgs) files:
    //              MODULE			- standard ATL replacement variable
    //              REGROOTBEGIN	- opening string for the Visual Studio 
    //                  registry root (i.e., "NoRemove Software \n{\n NoRemove 
    //                  Microsoft \n{\n NoRemove VisualStudio \n{\n NoRemove 7.1 
    //                  \n{\n")
    //              REGROOTEND		- closing string for the Visual Studio 
    //                  registry root (i.e., L"\n}\n \n}\n \n}\n \n}\n")
    //              CLSID_Package		 - package CLSID
    //              RESOURCE_DLL	- resource dll name
    //              RESOURCE_PATH	- resource dll path
    //              TEMPLATE_PATH   - project's template folders path
    //
    //              For CLSIDs, GUIDs, and resource IDs the corresponding 
    //              name is used also for replacement variable. For example, 
    //              GUID_TaskList or IDS_PACKAGE_LOAD_KEY.
    //
    //              CLSID_xxx	- replacement variable for xxx CLSID
    //              GUID_xxx	- replacement variable for xxx GUID
    //              IDS_xxx	    - replacement variable for xxx resource id
    //---------------------------------------------------------------------
    static HRESULT WINAPI UpdateRegistry(
        /* [in] */ BOOL bRegister);

	HRESULT FinalConstruct();
	HRESULT GetLocalizedString(ULONG resid, BSTR *pbstrOut);
	void SetErrorInfo(HRESULT hrError, ULONG residErrMsg, DWORD dwHelpContextID);
	void ReportErrorInfo(HRESULT hrError);

	// return (without extra addrefs) of cached pointers,
	// if NULL is returned then use an HRESULT of E_NOINTERFACE
	// cached pointers are released during the IVsPackage::Close method
	friend CExecutionCtx&       GetExecutionCtx();

	// Global Execution Context object
	static CExecutionCtx g_executionCtx;


	// *** IVsPackage methods ***
	STDMETHODIMP SetSite(IServiceProvider *pIServiceProvider);
	STDMETHODIMP QueryClose(BOOL *pfCanClose);
	STDMETHODIMP Close();

        //----------------------------------------------------------------------
    // Function:    GetAutomationObject
    //              Returns an automation object
    // Parameters:  
    //    /* [in]  */ LPCOLESTR     pszPropName, 
    //    /* [out] */ IDispatch **  ppIDispatch)
    // Returns:     HRESULT
    // Notes:
    //  Automation objects
    //      DTE (the main object in Visual Studio) supports early binding of 
    //      core methods/properties, and late binding of dynamic objects.
    //      Calling the late bound properties/methods depends on the 
    //      programming language used, and there are two ways of accessing them. 
    //      The first method is to call the standard IDispatch::Invoke method, 
    //      second is to use GetObject method on DTE, passing a string 
    //      representing the object you wish to retrieve.
    //      Adding this late binding feature to your package is a two-step process.
    //      First, you will need to register the names of your automation 
    //      objects under Packages\<PackageGuid>\Automation key.
    //      For example, "<MyName>Projects"="".
    //      To supply the object, you need to implement the GetAutomationObject 
    //      method on the IVsPackage interface. 
    //      When an object is needed from your package, this method is called with 
    //      the string that was passed to GetObject or GetIDsOfNames.
    //      You need to verify that the name you use for a Automation object 
    //      is unique.
    //      You should use a case--insensitive compare when checking the 
    //      pszPropName string.
    //    Sourcing Events
    //      Event objects are retrieved from the DTE.Events object.
    //      A package provides an event object by responding to IVsPackage::
    //      GetAutomationObject. Automaton events are registered under 
    //      Packages\<PackageGuid>\AutomationEvents registry key.
    //      For example, "<MyName>ProjectItemsEvents" and "<MyName>ProjectsEvents".
    //      The implementation of GetAutomationObject should watch for these
    //      strings. When these event objects are requested, a small object needs
    //      to be created that has the properties get_<MyName>ProjectsEvents, 
    //      get_<MyName>ProjectItemsEvents, as well as any other event 
    //      objects your package may support. When this object is returned 
    //      to the shell, it will call the appropriate method on this object. 
    //      If, for example, DTE.Events.<MyName>ProjectsEvents were called, 
    //      the get_<MyName>ProjectsEvents property on this object will be 
    //      invoked. From here, you create an instance of your event object, 
    //      and this will be returned to the calling AddIn. In most cases, 
    //      you will need to return a new object for each call to these 
    //      methods because most event objects take a filter object, when 
    //      firing your event, you will need to check this filter to verify 
    //      that the event handler should be called.
    //----------------------------------------------------------------------
	STDMETHOD(GetAutomationObject)(
        /* [in]  */ LPCOLESTR       pszPropName, 
        /* [out] */ IDispatch **    ppIDispatch);

	STDMETHODIMP CreateTool(REFGUID rguidPersistanceSlot);
	STDMETHODIMP ResetDefaults(PKGRESETFLAGS dwFlags);
	STDMETHODIMP GetPropertyPage(REFGUID rguidPage, VSPROPSHEETPAGE *ppage);

	// IVsInstalledProduct methods:
	STDMETHOD(get_IdBmpSplash)(UINT* pIdBmp);
	STDMETHOD(get_OfficialName)(BSTR* pbstrName);
	STDMETHOD(get_ProductID)(BSTR* pbstrPID);
	STDMETHOD(get_ProductDetails)(BSTR* pbstrProductDetails);
	STDMETHOD(get_IdIcoLogoForAboutbox)(UINT* pIdIco);

	// IOleCommandTarget methods:
	STDMETHODIMP QueryStatus(const GUID *pguidCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText);
	STDMETHODIMP Exec(const GUID *pguidCmdGroup, DWORD nCmdID, DWORD nCmdexecopt, VARIANT *pvaIn, VARIANT *pvaOut);

    // IServiceProvider methods:
	STDMETHODIMP QueryService(REFGUID rsid, REFIID riid, void **ppvObject);

//DECLARE_NOT_AGGREGATABLE(CVsPackage)

BEGIN_COM_MAP(CVsPackage)
	COM_INTERFACE_ENTRY(IVsPackage)					// Required interface for a VsPackage
	COM_INTERFACE_ENTRY(IVsInstalledProduct)		// Needed for splash screen/help about
	COM_INTERFACE_ENTRY(IOleCommandTarget)			// Needed to implement menu commands
	COM_INTERFACE_ENTRY(IServiceProvider)			// Needed to proffer services
END_COM_MAP()


public:
	// Our one and only Package Object
	static CVsPackage*				g_pPkg;

	// Our one and only Package Image List
	static PUIHierarchyImageList	g_pil;
	HRESULT		CreateImageList();
	void		DestroyImageList()
					{ delete g_pil; g_pil = NULL;
					}

    HRESULT GetAutomationProjects(/* [out] */ IDispatch ** ppIDispatch);

protected:
    CComPtr<IDispatch>        m_srpAutomationProjects;
	BOOL m_fZombie;
	VSCOOKIE m_dwProjectCookie;

};

// shortcut methods
inline IVsPackage* GetIVsPkg(void)
{
	ASSERT(CVsPackage::g_pPkg != NULL);
	return static_cast<IVsPackage *>(CVsPackage::g_pPkg);
}

inline CVsPackage* GetCVsPkg(void)
{
	ASSERT(CVsPackage::g_pPkg != NULL);
	return CVsPackage::g_pPkg;
}

inline PUIHierarchyImageList GetImageList()
{
	ASSERT(CVsPackage::g_pil != NULL);
	return CVsPackage::g_pil;
}

inline HIMAGELIST GetImageListHandle()
{
	ASSERT(CVsPackage::g_pil != NULL);
	return (*CVsPackage::g_pil);
}
inline CExecutionCtx& GetExecutionCtx()
{
	return CVsPackage::g_executionCtx;
}
