
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.h : Declaration of the CSlnExtPackage

#pragma once

class CNoteToolWindow;
class CSlnDynamicExtenderProvider;

/////////////////////////////////////////////////////////////////////////////
// CSlnExtPackage

class ATL_NO_VTABLE CSlnExtPackage : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CSlnExtPackage, &CLSID_SlnExtPackage>,
    public IVsPackage,
    public IOleCommandTarget,
    public IServiceProvider,
	public IVsPersistSolutionProps
{
public:
    CSlnExtPackage();
    ~CSlnExtPackage();

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

	HRESULT AddNewNote(); 
	HRESULT ShowToolWinFrame();

BEGIN_COM_MAP(CSlnExtPackage)
    COM_INTERFACE_ENTRY(IVsPackage)
    COM_INTERFACE_ENTRY(IOleCommandTarget)
    COM_INTERFACE_ENTRY(IServiceProvider)
	COM_INTERFACE_ENTRY(IVsPersistSolutionOpts)
	COM_INTERFACE_ENTRY(IVsPersistSolutionProps)
END_COM_MAP()

public:
// IVsPackage
    STDMETHOD(SetSite)(
                    /*[in]*/ IServiceProvider* pIServiceProvider);
    STDMETHOD(QueryClose)(
                    /*[out]*/ BOOL* pfCanClose);
    STDMETHOD(Close)(void);
    STDMETHOD(GetAutomationObject)(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppIDispatch);
    STDMETHOD(CreateTool)(
                    /*[in]*/ REFGUID rguidPersistanceSlot);
    STDMETHOD(ResetDefaults)(
                    /*[in]*/ PKGRESETFLAGS dwFlags);
    STDMETHOD(GetPropertyPage)(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage);

// IOleCommandTarget
	STDMETHOD(QueryStatus)(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText);
	STDMETHOD(Exec)(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdexecopt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut);

// IServiceProvider
    STDMETHOD(QueryService)(
                    /*[in] */ REFGUID rsid,
                    /*[in] */ REFIID  riid,
                    /*[out]*/ void**  ppvObject);

// IVsPersistSolutionOpts
	STDMETHOD(LoadUserOptions)(
					/*[in]*/ IVsSolutionPersistence* pPersistence,
					/*[in]*/ VSLOADUSEROPTS grfLoadOpts);
	STDMETHOD(ReadUserOptions)(
					/*[in]*/ IStream* pOptionsStream,
					/*[in]*/ LPCOLESTR szKey);
	STDMETHOD(SaveUserOptions)(
					/*[in]*/ IVsSolutionPersistence* pPersistence);
	STDMETHOD(WriteUserOptions)(
					/*[in]*/ IStream* pOptionsStream,
					/*[in]*/ LPCOLESTR szKey);

// IVsPersistSolutionProps
	STDMETHOD(OnProjectLoadFailure)(
					/*[in]*/ IVsHierarchy* pStubHierarchy,
					/*[in]*/ LPCOLESTR szProjectName,
					/*[in]*/ LPCOLESTR szProjectMk,
					/*[in]*/ LPCOLESTR szKey);
	STDMETHOD(QuerySaveSolutionProps)(
					/*[in]*/ IVsHierarchy* pHierarchy,
					/*[in]*/ VSQUERYSAVESLNPROPS* pqsspSave);
	STDMETHOD(ReadSolutionProps)(
					/*[in]*/ IVsHierarchy* pHierarchy,
					/*[in]*/ LPCOLESTR szProjectName,
					/*[in]*/ LPCOLESTR szProjectMk,
					/*[in]*/ LPCOLESTR szKey,
					/*[in]*/ BOOL fPreLoad,
					/*[in]*/ IPropertyBag* pPropBag);
	STDMETHOD(SaveSolutionProps)(
					/*[in]*/ IVsHierarchy* pHierarchy,
					/*[in]*/ IVsSolutionPersistence* pPersist);
	STDMETHOD(WriteSolutionProps)(
					/*[in]*/ IVsHierarchy* pHierarchy,
					/*[in]*/ LPCOLESTR szKey,
					/*[in]*/ IPropertyBag* pPropBag);

    STDMETHOD(GetSolutionNotes)(
        /* [out] */ ISolutionNotes ** ppISolutionNotes);

// Attributes
protected:
    BOOL m_fZombie;

    // pointer to our dynamically registered ExtenderProvider
    CComPtr<CSlnDynamicExtenderProvider> m_srpCSlnDynamicExtenderProvider;

	// IVsPackage
private:
	CComPtr<IVsWindowFrame> m_srpToolWinFrame;
	CComPtr<IVsWindowPane> m_srpToolWindow;
	CComObject<CNoteToolWindow>* m_pNoteWinObj;

	static WCHAR m_szPersistKey[];
};

