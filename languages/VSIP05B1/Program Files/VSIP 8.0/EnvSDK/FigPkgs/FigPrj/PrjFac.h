
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjFac.h : Declaration of the CMyProjectFactory and interfaces

#pragma once

//--------------------------------------------------------------------------
// provides:
//		interface: IVsProjectFactory
//		interface: IVsOwnedProjectFactory
//--------------------------------------------------------------------------
class CMyProjectFactory :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IVsProjectFactory,
	public IVsOwnedProjectFactory
{
// =========================================================================
//                                                 construct, init, destruct
public:
	CMyProjectFactory(void);

protected:
	~CMyProjectFactory(void);
//                                                 construct, init, destruct
// =========================================================================

    BEGIN_COM_MAP(CMyProjectFactory)
	    COM_INTERFACE_ENTRY(IVsProjectFactory)
	    COM_INTERFACE_ENTRY(IVsOwnedProjectFactory)
    END_COM_MAP()
    DECLARE_NOT_AGGREGATABLE(CMyProjectFactory)


// =========================================================================
//                                                         IVsProjectFactory
public:

    //----------------------------------------------------------------------
    // Function:    CanCreateProject
    //              Tells whether or not we can create a project
    // Parameters: 
    //    /* [in] */ LPCOLESTR pszFilename,
    //    /* [in] */ DWORD grfCreateProj,
    //    /* [out] */ BOOL *pfCanCreate);
    // Returns:     HRESULT
    // Notes: 
    //----------------------------------------------------------------------
	STDMETHOD(CanCreateProject)(
        /* [in]  */ LPCOLESTR pszFilename,
        /* [in]  */ DWORD     grfCreateProj,
        /* [out] */ BOOL *    pfCanCreate);

	STDMETHOD(CreateProject)(
        /* [in]  */ LPCOLESTR                   pszFilename,
        /* [in]  */ LPCOLESTR                   pszLocation,
        /* [in]  */ LPCOLESTR                   pszName,
        /* [in]  */ VSCREATEPROJFLAGS           grfCreateFlags,
        /* [in]  */ REFIID                      iidProject,
        /* [out, iid_is(iidProject)]*/ void **  ppvProject,
        /* [out] */ BOOL *                      pfCanceled);

	STDMETHOD(SetSite)(
			/* [in] */ IServiceProvider *pSP);

	STDMETHOD(Close)(void);

//                                                         IVsProjectFactory
// =========================================================================


// =========================================================================
//                                                    IVsOwnedProjectFactory
//
// Projects that support being aggregated by an Owner must persist the 
// OwnerKey in their project file. 
// When CreateProject is called on a project with an OwnerKey, the owned 
// project should convert its OwnerKey to a (project factory) GUID then call 
// CreateProject on this project factory to do the actual creation.
// 
// An owner will create its owned project in two phases:
// 1. Call IVsOwnedProjectFactory.PreCreateForOwner. This gives the owned 
//    project a chance to create an aggregated project object based on the 
//    input controlling IUnknown (pUnkOwner). The owned project passes 
//    back the inner IUnk and the aggregated object to the owner project, 
//    giving it a chance to store the inner IUnk.
// 2. Call IVsOwnedProjectFactory.InitializeForOwner. The owned project does
//    all its instantiation here (what usually goes into 
//    IVsProjectFactory.CreateProject on unowned projects). The input 
//    VSOWNEDPROJECTOBJECT is typically the aggregated owned project. The 
//    owned project can use this variable to determine if its project 
//    object has already been created (cookie!=NULL) or needs to be created 
//    (cookie==NULL).
//
// Related Property:
//    VSHPROPID_OwnerKey  - BSTR owner key string that identifies the 
//          project GUID of the owning project. Only projects that implement 
//          IVsOwnedProjectFactory should support this property.

public:

    //----------------------------------------------------------------------
    // Function:    PreCreateForOwner
    //              Called by the owner/outer so that the owned/inner project 
    //              can create an aggregated version of itself, using pOwner 
    //              as the controlling IUnknown. 
    // Parameters: 
    //    /* [in]  */ IUnknown                 *pUnkOwner,
    //    /* [out] */ IUnknown                 **ppUnkInner,
    //    /* [out] */ VSOWNEDPROJECTOBJECT*    pCookie );
    //
    // Returns:     HRESULT
    // Notes:
    //              The owned project should only create its project object 
    //              instance here. All the heavy initialisation work should 
    //              occur in InitializeForOwner. That ensures the owner/outer 
    //              project will work correctly during the owned/inner 
    //              initialisation.
    //              The owned project must return its inner IUnknown and its 
    //              Project object (cast as a VSOWNEDPROJECTOBJECT cookie) 
    //              back to the owning project.
    //----------------------------------------------------------------------
    STDMETHOD(PreCreateForOwner)( 
        /* [in]  */ IUnknown                 *pUnkOwner,
        /* [out] */ IUnknown                 **ppUnkInner,
        /* [out] */ VSOWNEDPROJECTOBJECT*    pCookie );

    //----------------------------------------------------------------------
    // Function:    InitializeForOwner
    //              Called by the owner to tell the owned project to do all 
    //              it's initialisation.
    // Parameters: 
    //    /* [in]  */ LPCOLESTR                 pszFilename,
    //    /* [in]  */ LPCOLESTR                 pszLocation,
    //    /* [in]  */ LPCOLESTR                 pszName,
    //    /* [in]  */ VSCREATEPROJFLAGS         grfCreateFlags,
    //    /* [in]  */ REFIID                    iidProject,
    //    /* [in]  */ VSOWNEDPROJECTOBJECT      cookie,    
    //              additional parameter over IVsProjectFactory.CreateProject
    //    /* [out, iid_is(iidProject)] */void** ppvProject,
    //    /* [out] */ BOOL*                     pfCanceled); 
    //
    // Returns:     HRESULT
    // Notes:
    //              The owned project should do all its CreateProject work 
    //              in here. The cookie parameter is just the cookie which 
    //              the owned project passed back in PreCreateForOwner. This
    //              allows the owned project to create its project object
    //----------------------------------------------------------------------
    STDMETHOD(InitializeForOwner)( 
        /* [in]  */ LPCOLESTR                 pszFilename,
        /* [in]  */ LPCOLESTR                 pszLocation,
        /* [in]  */ LPCOLESTR                 pszName,
        /* [in]  */ VSCREATEPROJFLAGS         grfCreateFlags,
        /* [in]  */ REFIID                    iidProject,
        /* [in]  */ VSOWNEDPROJECTOBJECT      cookie,    
        /* [out, iid_is(iidProject)] */void** ppvProject,
        /* [out] */ BOOL*                     pfCanceled); 


//                                                    IVsOwnedProjectFactory
// =========================================================================

protected:

    //----------------------------------------------------------------------
    // Function:    GetPreCreateInfoFromProjectFile
    //              Called prior to creating a project to parse the project 
    //              file looking for values which we need prior to doing the 
    //              actual creation and initialization.
    // Parameters: 
    //    /* [in]  */ LPCTSTR  pszFileName,
    //    /* [out] */ CString& strOwnerKey);
    // Returns:     HRESULT
    // Notes: 
    //----------------------------------------------------------------------
    HRESULT GetPreCreateInfoFromProjectFile(
        /* [in]  */ LPCTSTR  pszFileName,
        /* [out] */ CString& strOwnerKey);


    //----------------------------------------------------------------------
    // Function:    CalculateNames
    //              Compute the project name (caption) and FullPath to the 
    //              project file being created.
    //              strProjName will be the name of the project without a 
    //              leading path or extension.
    // Parameters: 
	//		LPCOLESTR pszFilename,
	//		LPCOLESTR pszName,
	//		LPCOLESTR pszLocation,
	//		CString& strProjFullPath,
	//		CString& strProjName,
	//		CString& strProjLocation);
    // Returns:     HRESULT
    // Notes: 
    //              In the open an existing project case pszFilename will be a 
    //              full path to the existing project file to be opened and 
    //              pszName/pszLocation will be NULL. 
    //              In the create a new project case pszFilename will be the 
    //              full path to the template file to be cloned and 
    //              pszName/pszLocation will be non-NULL pointing to the name
    //              and location of the project to be created. 
    //              thus in this case pszFilename will be ignored in this 
    //              function.
    //----------------------------------------------------------------------
	void CalculateNames(
			LPCOLESTR pszFilename,
			LPCOLESTR pszName,
			LPCOLESTR pszLocation,
			CString& strProjFullPath,
			CString& strProjName,
			CString& strProjLocation);

};
