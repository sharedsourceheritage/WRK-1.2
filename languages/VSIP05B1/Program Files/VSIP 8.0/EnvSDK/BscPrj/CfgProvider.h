
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// CfgProvider.h: interface for the CCfgProvider class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

// forward declarations
class CMyProjectCfg;
class CMyProjectHierarchy;

class ATL_NO_VTABLE CCfgProvider :
    public IVsProjectCfgProvider,       // -> IVsCfgProvider
    public IVsCfgProvider2,             // -> IVsCfgProvider
    public IVsCfgProviderEventsHelper,  // -> IUnknown
    public CComObjectRootEx<CComSingleThreadModel>

{
    BEGIN_COM_MAP(CCfgProvider)
        COM_INTERFACE_ENTRY(IVsProjectCfgProvider)
        COM_INTERFACE_ENTRY2(IVsCfgProvider, IVsCfgProvider2)
        COM_INTERFACE_ENTRY(IVsCfgProvider2)
        COM_INTERFACE_ENTRY(IVsCfgProviderEventsHelper)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CCfgProvider)

private:
    typedef CComObject<CMyProjectCfg> CProjectCfg;

//==========================================================================
//                                                construct, init , destruct
public:

    CCfgProvider();
	virtual ~CCfgProvider();
    
    //----------------------------------------------------------------------
    // Function:    Init
    //              To initialize the object
    // Parameters: 
    //  /* [in] */ CMyProjectHierarchy * pHier - project hierarchy
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT Init(
        /* [in] */ CMyProjectHierarchy * pHier);

    //----------------------------------------------------------------------
    // Function:    CreateDefaultCfgs
    //              Create the default set of configurations - 
    //              Debug and Release
    // Parameters:  
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT CreateDefaultCfgs();
    
    //----------------------------------------------------------------------
    // Function:    Destroy
    //              This function cleans the object. It should
    //              - release the project configurations objects
    //              - clean the array with the pointers to configuration objects
    //              - clean the array with cfg names
    //              - clean the array with platform names
    // Parameters:  
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT Destroy();

//                                                construct, init , destruct
//==========================================================================


//==========================================================================
//                                                                persisting

public:

    //----------------------------------------------------------------------
    // Function:    LoadCfgs
    //              Loads saved configurations
    //
    // Parameters:  
    //  /* [in] */ IVsPropertyStreamIn *pIVsPropertyStreamIn 
    //              Stream to load from
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT LoadCfgs(
        /* [in] */ IVsPropertyStreamIn *pIVsPropertyStreamIn);


    //----------------------------------------------------------------------
    // Function:    SaveCfgs
    //              Saves configurations
    //
    // Parameters:  
    //  /* [in] */ IVsPropertyStreamOut *pIVsPropertyStreamOut 
    //              Stream to save to
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT SaveCfgs(
        /* [in] */ IVsPropertyStreamOut *pIVsPropertyStreamOut);

protected:
    HRESULT CCfgProvider::SetProjectFileDirty(
        /* [in] */ BOOL fIsDirty);

//                                                                persisting
//==========================================================================


//==========================================================================
//                                                            IVsCfgProvider

public:


    //----------------------------------------------------------------------
    // Function:    GetCfgs
    //              Return the per-configuration objects for this object.
    //
    // Parameters:  
    //    /* [in]                     */ ULONG celt,
    //    /* [in, out, size_is(celt)] */ IVsCfg *rgpcfg[],
    //    /* [out, optional]          */ ULONG *pcActual,
    //    /* [out, optional]          */ VSCFGFLAGS *prgfFlags)
    //
    // Returns:     HRESULT
    // Notes:
    //      If celt is zero and pcActual is not NULL, the number of 
    //      configuration objects is returned in *pcActual.
    //      If celt is not zero, rgpcfg must not be NULL, or E_POINTER 
    //      is returned.
    //      An extremely common pattern is something like (omitting 
    //      error checks for readability):
    //      hr = pIVsCfgProvider->GetCfgs(0, NULL, &cExpected, NULL);
    //      prgpcfgs = ::CoTaskMemAlloc(cExpected * sizeof(IVsCfg *));
    //      hr = pIVsCfgProvider->GetCfgs(cExpected, prgpcfgs, &cActual, NULL);
    //
    //----------------------------------------------------------------------
    STDMETHOD(GetCfgs)(
        /* [in]                     */ ULONG celt,
        /* [in, out, size_is(celt)] */ IVsCfg *rgpcfg[],
        /* [out, optional]          */ ULONG *pcActual,
        /* [out, optional]          */ VSCFGFLAGS *prgfFlags);

//                                                            IVsCfgProvider
//==========================================================================



//==========================================================================
//                                                     IVsProjectCfgProvider


    //----------------------------------------------------------------------
    // Function:    OpenProjectCfg
    //
    // Parameters:  
    //    /* [in] */ LPCOLESTR szProjectCfgCanonicalName
    //    /* [out]*/ IVsProjectCfg **ppIVsProjectCfg)
    //
    // Returns:     HRESULT
    // Notes:
    //
    //----------------------------------------------------------------------
    STDMETHOD(OpenProjectCfg)(
        /* [in] */LPCOLESTR szProjectCfgCanonicalName,
        /* [out]*/IVsProjectCfg **ppIVsProjectCfg);
    
    //----------------------------------------------------------------------
    // Function:    get_UsesIndependentConfigurations
    //
    // Parameters:  
    //    /* [out] */ BOOL __RPC_FAR *pfUsesIndependentConfigurations
    //
    // Returns:     HRESULT
    // Notes:
    //
    //----------------------------------------------------------------------
    STDMETHOD(get_UsesIndependentConfigurations)( 
           /* [out] */ BOOL __RPC_FAR *pfUsesIndependentConfigurations);
 

//                                                     IVsProjectCfgProvider
//==========================================================================



//==========================================================================
//                                                           IVsCfgProvider2

//--------------------------------------------------------------------------
//                                                 IVsCfgProvider2 interface
public:
    

    //----------------------------------------------------------------------
    // Function:    GetCfgNames
    //              Returns a list of all configuration names.
    // Parameters:  
    //  /* [in]                     */  ULONG celt, 
    //  /* [in, out, size_is(celt)] */  BSTR  rgbstr[],
    //  /* [out, optional]          */  ULONG *pcActual)
    //
    // Returns:     HRESULT
    // Notes:
    //      The caller can get the # of configurations by calling
    //      GetCfgNames(0, NULL, &cActualCfgs);
    //      It is up to the caller to free all bstrs.
    //
    //----------------------------------------------------------------------
    STDMETHOD(GetCfgNames)(
        /* [in]                     */  ULONG celt, 
        /* [in, out, size_is(celt)] */  BSTR  rgbstr[],
        /* [out, optional]          */  ULONG *pcActual);

    //----------------------------------------------------------------------
    // Function:    GetPlatformNames
    //              Returns a list of all platform names.
    // Parameters:  
    //  /* [in]                     */  ULONG celt, 
    //  /* [in, out, size_is(celt)] */  BSTR  rgbstr[],
    //  /* [out, optional]          */  ULONG *pcActual)
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(GetPlatformNames)(
        /* [in]                     */ ULONG celt, 
        /* [in, out, size_is(celt)] */ BSTR rgbstr[], 
        /* [out, optional]          */ ULONG *pcActual);


    //----------------------------------------------------------------------
    // Function:    GetCfgOfName
    // Parameters:  
    //    /* [in]  */ LPCOLESTR pszCfgName, 
    //    /* [in]  */ LPCOLESTR pszPlatformName, 
    //    /* [out] */ IVsCfg **ppCfg)
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(GetCfgOfName)(
        /* [in]  */ LPCOLESTR pszCfgName, 
        /* [in]  */ LPCOLESTR pszPlatformName, 
        /* [out] */ IVsCfg **ppCfg);

    //----------------------------------------------------------------------
    // Function: AddCfgsOfCfgName
    //           Adds cfg objects for each supported platform 
    //
    // Parameters
    //    /* [in] */ LPCOLESTR pszCfgName
    //          New configuration name 
    //    /* [in] */ LPCOLESTR pszCloneCfgName
    //          Configuration to clone from. 
    //          NULL is a valid parameter for pszCloneCfgName, in case the
    //          user wants to just create a new one, without reference to 
    //          an old one.  
    //    /* [in] */ BOOL fPrivate)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(AddCfgsOfCfgName)(
        /* [in] */ LPCOLESTR pszCfgName, 
        /* [in] */ LPCOLESTR pszCloneCfgName, 
        /* [in] */ BOOL fPrivate);



    //----------------------------------------------------------------------
    // Function: DeleteCfgsOfCfgName
    //           Delete cfg objects for all supported platform 
    //
    // Parameters
    //    /* [in] */ LPCOLESTR pszCfgName
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(DeleteCfgsOfCfgName)(
        /* [in] */ LPCOLESTR pszCfgName);


    //----------------------------------------------------------------------
    // Function: RenameCfgsOfCfgName
    //           Rename cfg objects
    //
    // Parameters
    //    /* [in] */ LPCOLESTR pszOldName, 
    //    /* [in] */ LPCOLESTR pszNewName)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(RenameCfgsOfCfgName)(
        /* [in] */ LPCOLESTR pszOldName, 
        /* [in] */ LPCOLESTR pszNewName);

        
    //----------------------------------------------------------------------
    // Function: AddCfgsOfPlatformName
    // Parameters
    //    /* [in] */ LPCOLESTR pszPlatformName, 
    //    /* [in] */ LPCOLESTR pszClonePlatformName)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(AddCfgsOfPlatformName)(
        /* [in] */ LPCOLESTR pszPlatformName, 
        /* [in] */ LPCOLESTR pszClonePlatformName);

    
    //----------------------------------------------------------------------
    // Function: DeleteCfgsOfPlatformName
    // Parameters
    //    /* [in] */ LPCOLESTR pszPlatformName)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(DeleteCfgsOfPlatformName)(
        /* [in] */ LPCOLESTR pszPlatformName);


    //----------------------------------------------------------------------
    // Function: GetSupportedPlatformNames
    //           Get all platforms that can be supported.
    // Parameters
    //    /* [in]                     */ ULONG celt, 
    //    /* [in, out, size_is(celt)] */ BSTR rgbstr[],
    //    /* [out, optional]          */ ULONG *pcActual)
    // Returns:     HRESULT
    // Notes:
    //          The set of the supported platforms (returned by 
    //          GetSupportedPlatformNames) is a superset of the platforms 
    //          for which conf. objects currently exists (returned by 
    //          GetPlatformNames)
    //----------------------------------------------------------------------
    STDMETHOD(GetSupportedPlatformNames)(
        /* [in]                     */ ULONG celt, 
        /* [in, out, size_is(celt)] */ BSTR rgbstr[],
        /* [out, optional]          */ ULONG *pcActual);


    //----------------------------------------------------------------------
    // Function: GetCfgProviderProperty
    // Parameters
    //    /* [in]  */ VSCFGPROPID propid, 
    //    /* [out] */ VARIANT *pvar)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(GetCfgProviderProperty)(
        /* [in]  */ VSCFGPROPID propid, 
        /* [out] */ VARIANT *pvar);


    //----------------------------------------------------------------------
    // Function: AdviseCfgProviderEvents
    // Parameters
    //    /* [in]  */ IVsCfgProviderEvents *pCPE, 
    //    /* [out] */ DWORD *pdwCookie)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(AdviseCfgProviderEvents)(
        /* [in]  */ IVsCfgProviderEvents *pCPE, 
        /* [out] */ VSCOOKIE *pdwCookie);

    //----------------------------------------------------------------------
    // Function: UnadviseCfgProviderEvents
    // Parameters
    //    /* [in] */ DWORD dwCookie
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(UnadviseCfgProviderEvents)(
        /* [in] */ VSCOOKIE dwCookie);

//                                                 IVsCfgProvider2 interface
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
//                                             IVsCfgProvider2 impl. helpers

public:
    //----------------------------------------------------------------------
    // Function:    CfgsCount
    //              Get the number of currently existing cfg objects
    //
    // Parameters:  
    //
    // Returns:     The number of currently existing cfg objects
    // Notes:
    //----------------------------------------------------------------------
    USHORT CfgsCount() const;

protected:

    //----------------------------------------------------------------------
    // Function: GetMatchingCfg
    //           Get a pointer to cfg object matching the cfg and platform
    //           names or NULL
    // Parameters
    //    /* [in] */          const CString& strCfgName, 
    //    /* [in] */          const CString& strPlatformName)
    // Returns:  
    //           Pointer to cfg object matching the cfg and platform
    //           names or NULL
    // Notes:
    //----------------------------------------------------------------------
    CProjectCfg* GetMatchingCfg(
        /* [in] */          const CString& strCfgName, 
        /* [in] */          const CString& strPlatformName);


    //----------------------------------------------------------------------
    // Function: CreateProjectCfg
    //           Creates a project configuration,
    //           adds the cfg and platform names to the arrays
    // Parameters
    //    /* [in]  */ const CString& strCfgName, 
    //    /* [in]  */ const CString& strPlatformName, 
    //    /* [out] */ CProjectCfg ** ppProjectCfg)
    // Returns:  HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT CreateProjectCfg(
        /* [in]  */ const CString& strCfgName, 
        /* [in]  */ const CString& strPlatformName, 
        /* [out] */ CProjectCfg ** ppProjectCfg);

    //----------------------------------------------------------------------
    // Function: DeleteProjectCfg
    //           Deletes a project configuration,
    // Parameters
    //    /* [in] */ CProjectCfg * pProjectCfg 
    // Returns:  HRESULT
    // Notes:
    //           Releases the cfg object pointed by pProjectCfg, removes it 
    //           from the array, and removes the cfg name if there is no other
    //           cfg object with such a cfg name
    //----------------------------------------------------------------------
    HRESULT DeleteProjectCfg(
        /* [in] */ CProjectCfg * pProjectCfg) ;

    //----------------------------------------------------------------------
    // Function: SplitCfgPlatformName
    //
    // Parameters
    //    const CString& strName,
    //    CString& strCfgName,
    //    CString& strPlatformName)
    //
    // Returns:  HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT SplitCfgPlatformName(
        const CString& strName,
        CString& strCfgName,
        CString& strPlatformName);


    //----------------------------------------------------------------------
    // Function: CfgNamesCount
    // Parameters
    // Returns:  Returns the number of configuration names
    // Notes:
    //----------------------------------------------------------------------
    USHORT CfgNamesCount() const;


    //----------------------------------------------------------------------
    // Function: IsInCfgNames
    //           Check if a configuration name exists in the array
    // Parameters
    //    /* [in] */ const CString& strCfgName
    // Returns:  True if a configuration name exists in the array
    // Notes:
    //----------------------------------------------------------------------
    BOOL IsInCfgNames(
        /* [in] */ const CString& strCfgName);


    //----------------------------------------------------------------------
    // Function: CfgNamesAddName
    //           Add a new configuration name to the array
    // Parameters
    //    /* [in] */ const CString& strCfgName
    // Returns:  HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT CfgNamesAddName(
        /* [in] */ const CString& strCfgName);

    //----------------------------------------------------------------------
    // Function: CfgNamesDeleteName
    //           Delete a new configuration name to the array
    // Parameters
    //    /* [in] */ const CString& strCfgName
    // Returns:  HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT CfgNamesDeleteName(
        /* [in] */ const CString& strCfgName);
        

    //----------------------------------------------------------------------
    // Function: PlatformNamesCount
    // Parameters
    // Returns:  The number of platforms
    // Notes:
    //----------------------------------------------------------------------
    USHORT PlatformNamesCount() const;

    //----------------------------------------------------------------------
    // Function: PlatformNamesInit
    //           Initializes the array with the currently used platforms.
    // Parameters
    // Returns:  HRESULT
    // Notes:
    //           In the current implementation either one (Win32) platform is
    //           supported or platforms are not supported. In the latter case
    //           the array is initialized with one empty string.
    //----------------------------------------------------------------------
    HRESULT PlatformNamesInit() ;


    //----------------------------------------------------------------------
    // Function: IsInPlatformNames
    //           Check if a platform name exists in the array
    // Parameters
    //    /* [in] */ const CString& strPlatformName
    // Returns:  True if the platform name exists in the array
    // Notes:
    //----------------------------------------------------------------------
    BOOL IsInPlatformNames(
        /* [in] */ const CString& strPlatformName);

    //----------------------------------------------------------------------
    // Function: PlatformNamesAddName
    //           Add a new platform name to the array
    // Parameters
    //    /* [in] */ const CString& strPlatformName
    // Returns:  HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT PlatformNamesAddName(
        /* [in] */ const CString& strPlatformName);


//                                             IVsCfgProvider2 impl. helpers
//--------------------------------------------------------------------------

//                                                           IVsCfgProvider2
//==========================================================================

    
//==========================================================================
//                                      IVsCfgProviderEventsHelper interface

    // Defined in IVsCfgProvider2
    // STDMETHOD(AdviseCfgProviderEvents)(
    //    /* [in]  */ IVsCfgProviderEvents *pCPE, 
    //    /* [out] */ DWORD *pdwCookie);

    // Defined in IVsCfgProvider2
    // STDMETHOD(UnadviseCfgProviderEvents)(
    //    /*[in] */ DWORD dwCookie);


    STDMETHOD(NotifyOnCfgNameAdded)(
        /* [in] */ LPCOLESTR pszCfgName);


    STDMETHOD(NotifyOnCfgNameDeleted)(
        /* [in] */ LPCOLESTR pszCfgName);

    // note: if the rename operation is implemented as a clone & delete 
    // fire the add/delete events instead of this one.
    STDMETHOD(NotifyOnCfgNameRenamed)(
        /* [in] */ LPCOLESTR pszOldName, 
        /* [in] */ LPCOLESTR lszNewName);

    STDMETHOD(NotifyOnPlatformNameAdded)(
        /* [in] */ LPCOLESTR pszPlatformName);

    STDMETHOD(NotifyOnPlatformNameDeleted)(
        /* [in] */ LPCOLESTR pszPlatformName);

//                                      IVsCfgProviderEventsHelper interface
//==========================================================================


//==========================================================================
//                                                                   Members
protected:
 
    // Pointer to the project hierarchy
    CMyProjectHierarchy * m_pHier;

    // Pointers to the project cfgs
    CVxTypedPtrArray<CVxPtrArray, CProjectCfg*>  m_rgpProjectCfg;
    
    // Array with the cfg names
    CVxStringArray    m_rgstrCfgNames;
    
    // Array with the platform names
    CVxStringArray    m_rgstrPlatformNames;

    CVsAdviseList<IVsCfgProviderEvents> m_alCfgProviderEvents;

    BOOL m_fHasPlatformName; // do we want to show "Win32" or not?
//                                                                   Members
//==========================================================================
};
