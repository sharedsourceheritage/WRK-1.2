
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// vspkg.h : Declaration of the CVsPackage and interfaces

#pragma once

#include "resource.h"       // main symbols

#include <commctrl.h>

extern HINSTANCE g_hInstance;

/////////////////////////////////////////////////////////////////////////////
// forward declarations

/////////////////////////////////////////////////////////////////////////////
// CVsPackage

class CVsPackage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVsPackage, &CLSID_BscEdtPackage>,
	public IVsPackage
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

	// IVsPackage methods 
	STDMETHODIMP SetSite(IServiceProvider *pIServiceProvider);
	STDMETHODIMP QueryClose(BOOL *pfCanClose);
	STDMETHODIMP Close();
	STDMETHODIMP GetAutomationObject(LPCOLESTR pszPropName, IDispatch **ppIDispatch);
	STDMETHODIMP CreateTool(REFGUID rguidPersistanceSlot);  
	STDMETHODIMP ResetDefaults(PKGRESETFLAGS dwFlags);		
	STDMETHODIMP GetPropertyPage(REFGUID rguidPage, VSPROPSHEETPAGE *ppage); 

//DECLARE_NOT_AGGREGATABLE(CVsPackage)

BEGIN_COM_MAP(CVsPackage)
	COM_INTERFACE_ENTRY(IVsPackage)					// Required interface for a VsPackage
END_COM_MAP()

	// Other helpers
	HRESULT GetShellUISvc(IVsUIShell **ppSvc);
	HRESULT	GetShellSvc(REFGUID rsid, REFIID riid, void **ppv);

// IVsPackage
private:
	BOOL  m_fZombie;
	CComPtr<IServiceProvider> m_srpPkgSiteSP;
	CComPtr<IVsUIShell> m_srpUIShell;
	CComPtr<IVsEditorFactory> m_srpEdFact;
	VSCOOKIE m_dwEditorCookie;			// Cookie returned when registering editor

};


