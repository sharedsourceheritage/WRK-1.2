
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjFac.h : Declaration of the CMyProjectFactory and interfaces

#pragma once

//--------------------------------------------------------------------------
// provides:
//        interface: IVsProjectFactory
//        interface: IVsAggregatableProjectFactory
//--------------------------------------------------------------------------
class CMyProjectFactory :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IVsProjectFactory,
    public IVsAggregatableProjectFactory
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
        COM_INTERFACE_ENTRY(IVsAggregatableProjectFactory)
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
//                                             IVsAggregatableProjectFactory
// For multi-levels aggregation, the inner most project must persist the GUIDs
// of all of the projects that are part of the aggregation.

public:
    //----------------------------------------------------------------------
    // Function: GetAggregateProjectType
    // Returns a string containing a list of project type guids to be aggregated together to
    // create an instance of this project. It should minimally return 1 guid which is the project
    // type guid for itself. This method is expected to get this list of guids from the specified
    // project file
    //
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(GetAggregateProjectType)(
        /* [in] */ LPCOLESTR pszFilename,
        /* [out]*/ BSTR *pbstrProjTypeGuid);

    //----------------------------------------------------------------------
    // Function: PreCreateForOuter
    // Called  by the owner/outer so that the owned/inner project can create
    // an aggregatable version of  itself.
    // The owned project should only create its project object instance here. All
    // the heavy initialization  work should occur in IVsAggregatableProject::InitializeForOuter.
    // That ensures the owner/outer project will work correctly  during the owned/inner
    // initialization. The owned project must return its inner IUnknown
    //
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(PreCreateForOuter)(
        /* [in] */ IUnknown *pUnkOwner,
        /* [out]*/ IUnknown **ppunkProject);

//                                             IVsAggregatableProjectFactory
// =========================================================================
   
protected:

    //----------------------------------------------------------------------
    // Function:    GetPreCreateInfoFromProjectFile
    //              Called prior to creating a project to parse the project 
    //              file looking for values which we need prior to doing the 
    //              actual creation and initialization.
    // Parameters: 
    //    /* [in]  */ LPCTSTR  pszFileName,
    //    /* [out] */ CString& strOwnerKey,
    //    /* [out] */ long     *plMajor,
    //    /* [out] */ long     *plMinor);
    // Returns:     HRESULT
    // Notes: 
    //----------------------------------------------------------------------
    HRESULT GetPreCreateInfoFromProjectFile(
        /* [in]  */ LPCTSTR  pszFileName,
        /* [out] */ CString& strOwnerKey,
        /* [out] */ long     *plMajor,
        /* [out] */ long     *plMinor);


    //----------------------------------------------------------------------
    // Function:    CalculateNames
    //              Compute the project name (caption) and FullPath to the 
    //              project file being created.
    //              strProjName will be the name of the project without a 
    //              leading path or extension.
    // Parameters: 
    //        LPCOLESTR pszFilename,
    //        LPCOLESTR pszName,
    //        LPCOLESTR pszLocation,
    //        CString& strProjFullPath,
    //        CString& strProjName,
    //        CString& strProjLocation);
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
