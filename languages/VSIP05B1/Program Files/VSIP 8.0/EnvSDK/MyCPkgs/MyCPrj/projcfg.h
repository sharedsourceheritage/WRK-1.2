
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// projcfg.h : Declaration of the CMyProjectCfg configuration object.
//			   This object is involved in Build/Debug/Deploy operations

#pragma once


// forward references
class CMyProjectHierarchy;


////////////////////////////////////////////////////////////////////////////
// CVsDebugTargetInfo
//      VsDebugTargetInfo helper class
//--------------------------------------------------------------------------
class CVsDebugTargetInfo : public VsDebugTargetInfo
{
public:
    CVsDebugTargetInfo()
    {
        ::ZeroMemory(this, sizeof(VsDebugTargetInfo));
        cbSize = sizeof(VsDebugTargetInfo);
    }

    ~CVsDebugTargetInfo()
    {
        Clear();
    }

    void Clear()
    {
        if(bstrRemoteMachine)
            ::SysFreeString(bstrRemoteMachine);
        if(bstrExe)
            ::SysFreeString(bstrExe);
        if(bstrArg)
            ::SysFreeString(bstrArg);
        if (bstrCurDir)
            ::SysFreeString(bstrCurDir);
        if (bstrEnv)
            ::SysFreeString(bstrEnv);
    }
};


////////////////////////////////////////////////////////////////////////////
// CMyProjectCfg
//		class for a given project configuration.
//--------------------------------------------------------------------------
// implements:
//		interface: IVsCfg
//		interface: IVsProjectCfg
//		interface: IVsDebuggableProjectCfg
//		interface: IVsProjectCfg2
//		interface: ISpecifyPropertyPages
//		interface: IDispatch
//		interface: IMyCProjCfgProps
//--------------------------------------------------------------------------
class CMyProjectCfg :
		public IVsDebuggableProjectCfg, //-> IVsProjectCfg -> IVsCfg
        public IVsProjectCfg2,          //-> IVsProjectCfg -> IVsCfg
		public ISpecifyPropertyPages,
		public CComObjectRootEx<CComMultiThreadModel>,	// explicit
		public IDispatchImpl<IMyCProjCfgProps, &IID_IMyCProjCfgProps, &LIBID_MyCPrjPKGLib>

{

// =========================================================================
//                                 Construct, initialize, copy, and destruct
//
public:
	CMyProjectCfg();
    ~CMyProjectCfg();
	HRESULT Init(  
        CMyProjectHierarchy *pHier, 
        const CString& strCfgName,
        const CString& strPlatformName);
    HRESULT Clone(CMyProjectCfg* pClonedCfg);
//
//                                 Construct, initialize, copy, and destruct
// =========================================================================

// =========================================================================
//                                                                   ATL COM 

    BEGIN_COM_MAP(CMyProjectCfg)
        COM_INTERFACE_ENTRY2(IVsCfg,IVsDebuggableProjectCfg)
	    COM_INTERFACE_ENTRY2(IVsProjectCfg,IVsDebuggableProjectCfg)
	    COM_INTERFACE_ENTRY(IVsDebuggableProjectCfg)
	    COM_INTERFACE_ENTRY(IVsProjectCfg2)
	    COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IMyCProjCfgProps)
        COM_INTERFACE_ENTRY_IID(IID_CMyProjectCfg, CMyProjectCfg)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CMyProjectCfg)

//                                                                   ATL COM 
// =========================================================================

public:
    CString GetName(); 
    HRESULT RenameCfgName(const CString& strNewCfgName);
    HRESULT UpdateName();
	CMyProjectHierarchy* CMyProjectCfg::GetHierarchy() {return m_pHier;}


// =========================================================================
//                                                                Persisting
public:
    // ---------------------------------------------------------------------
    // Save
    // Save the configuration to a stream 
    HRESULT Save(IVsPropertyStreamOut *pIVsPropertyStreamOut);

    // ---------------------------------------------------------------------
    // Load
    // Load the configuration form a stream 
	HRESULT Load(IVsPropertyStreamIn *pIVsPropertyStreamIn);

    HRESULT SetProjectFileDirty(BOOL fDirty);
//                                                                Persisting
// =========================================================================


// =========================================================================
//                                                                    IVsCfg
public:
	STDMETHOD(get_DisplayName)(/* [out] */BSTR *pbstrDisplayName);
	STDMETHOD(get_IsDebugOnly)(/* [out] */BOOL *pfIsDebugOnly);
	STDMETHOD(get_IsReleaseOnly)(/*[out] */BOOL *pfIsReleaseOnly);
//                                                                    IVsCfg
// =========================================================================

// =========================================================================
//                                                             IVsProjectCfg
public:
	STDMETHOD(get_ProjectCfgProvider)(/* [out] */IVsProjectCfgProvider **ppIVsProjectCfgProvider);
	STDMETHOD(get_CanonicalName)(/* [out] */BSTR *pbstrCanonicalName);

    // This method is obsolete
	STDMETHOD(get_Platform)(/* [out] */GUID *pguidPlatform){return E_NOTIMPL;};

	STDMETHOD(EnumOutputs)(/* [out] */IVsEnumOutputs **ppIVsEnumOutputs);
	STDMETHOD(OpenOutput)(/* [in] */LPCOLESTR szOutputCanonicalName,
					/* [out] */IVsOutput **ppIVsOutput);
	STDMETHOD(get_BuildableProjectCfg)(/* [out] */IVsBuildableProjectCfg **ppIVsBuildableProjectCfg);
	STDMETHOD(get_IsPackaged)(/* [out] */ BOOL __RPC_FAR *pfIsPackaged);

    // This method is obsolete
	STDMETHOD(get_IsSpecifyingOutputSupported)(/* [out] */ BOOL *pfIsSpecifyingOutputSupported){return E_NOTIMPL;};

    // This method is obsolete
    STDMETHOD(get_TargetCodePage)(/* [out] */ UINT *puiTargetCodePage){return E_NOTIMPL;};

    // This method is obsolete
	STDMETHOD(get_UpdateSequenceNumber)(/* [out] */ ULARGE_INTEGER *puliUSN){return E_NOTIMPL;};

	STDMETHOD(get_RootURL)(/* [out] */ BSTR *pbstrRootURL);
//                                                             IVsProjectCfg
// =========================================================================

// =========================================================================
//                                                   IVsDebuggableProjectCfg
//
// If a project configuration can be launched from the debugger, it must 
// support the IVsDebuggableProjectCfg interface.
// Unlike the IVsBuildableProjectCfg interface, this is unlikely to require 
// a separate object, so it's just an optional interface on the project 
// configuration object.
//
//--------------------------------------------------------------------------
//                                       IVsDebuggableProjectCfg   interface
//
public:
    //----------------------------------------------------------------------
    // Function:    DebugLaunch : Launches the debugger
    // Parameters: 
    //    /* [in] */VSDBGLAUNCHFLAGS grfLaunch);
    //              Flags that determine the conditions under which to launch 
    //              the debugger. Values are taken from the VSDBGLAUNCHFLAGS 
    //              enumeration. 
    // Returns:     HRESULT
    //----------------------------------------------------------------------
	STDMETHOD(DebugLaunch)(
        /* [in] */VSDBGLAUNCHFLAGS grfLaunch);

    //-----------------------------------------------------------------------
    // Function:    QueryDebugLaunch
    //              Determines whether the debugger can be launched, given the 
    //              state of the launch flags.
    // Parameters
    //    /* [in] */ VSDBGLAUNCHFLAGS grfLaunch, 
    //              Flags that determine the conditions under which to launch 
    //              the debugger. Values are taken from the VSDBGLAUNCHFLAGS 
    //              enumeration. 
    //    /* [out] */ BOOL * pfCanLaunch);
    //              TRUE if the debugger can be launched. 
    // Returns:     HRESULT
    //-----------------------------------------------------------------------
	STDMETHOD(QueryDebugLaunch)(
        /* [in] */VSDBGLAUNCHFLAGS grfLaunch, 
        /* [out] */ BOOL *pfCanLaunch);
//
//                                       IVsDebuggableProjectCfg   interface
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//                                IVsDebuggableProjectCfg   helper functions
//
protected:
    HRESULT SetDebugLaunchTgts(); 
    HRESULT SetExeLaunchTgts();

    //----------------------------------------------------------------------
    // Function:    IsDeploymentRemote
    //              Checks if the ouput, which is debug target, is deployed 
    //              on a remote machine
    // Returns:     HRESULT
    //              S_FALSE if deployment is not installed.
    //              S_OK    if the target is deployed
    //              E_xx    for failure
    //----------------------------------------------------------------------
    STDMETHOD(IsDeploymentRemote)(
        /* [out] */ BOOL&    fRemoteDeploy, 
        /* [out] */ BSTR*    pbstrDebugTarget, 
        /* [out] */ BSTR*    pbstrDebugMachine);

    void DeleteDebugLaunchTargets();

    STDMETHOD(GetDebugLaunchTargetCount)(
        /* [in] */int iConfig, 
        /* [out]*/ULONG *puCount);


//
//                                IVsDebuggableProjectCfg   helper functions
//--------------------------------------------------------------------------
//                                                   IVsDebuggableProjectCfg
// =========================================================================

// =========================================================================
//                                                     ISpecifyPropertyPages

public:
    STDMETHOD(GetPages)(/* [out] */ CAUUID *pPages);

//                                                     ISpecifyPropertyPages
// =========================================================================


    
// =========================================================================
//                                                            IVsProjectCfg2
    
// -------------------------------------------------------------------------
//                                                  IVsProjectCfg2 interface
//
// IVsProjectCfg2 : this derives from IVsProjectCfg, and thereby from IVsCfg.
// However, it should be noted that IVsCfg::get_IsDebugOnly() and 
// IVsCfg::get_RetailOnly() are mostly moot, since we're no longer limited to
// two configuration types.  Ergo, code which processes configurations should
// not make assumptions about the number of configurations, nor should it
// assume that a project which has only one configuration is necessarily debug
// or retail.
// The primary use of IVsProjectCfg2, beyond IVsProjectCfg usage, is to allow
// projects the freedom to group outputs.  However, the project must return
// the same number of groups for each configuration that it supports, even
// though the number of outputs contained within a group may vary from
// configuration to configuration.  The groups will also have the same
// identifier information (canonical name, display name, and group info) from
// configuration to configuration within a project.
public:
	

    //----------------------------------------------------------------------
    // Function:    get_CfgType
    //              Returns a pointer to the required interface if implemented.
    //              Otherwise, returns an error.
    // Parameters: 
    //    /* [in] */ REFIID iidCfg,
    //              Interface to look for.
    //  `           Examples of iidCfg values are IID_IVsBuildableProjectCfg,
    //              IID_IVsDebuggableProjectCfg, and IID_IVsDeployableProjectCfg
    //
    //    /* [out, iid_is(iidCfg)] */ void** ppCfg);
    //              A pointer to the interface or NULL.
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(get_CfgType)(
        /* [in] */                  REFIID iidCfg, 
        /* [out, iid_is(iidCfg)] */ void** ppCfg);
	
    //----------------------------------------------------------------------
    // Function:    get_OutputGroups
    //              Return an array of IVsOutputGroup, or just the count in  
    //              pcActual when celt and rgpIVsOutputGroup are NULL.
    //
    // Parameters: 
    //    /* [in]                     */ ULONG celt,
    //    /* [in, out, size_is(celt)] */ IVsOutputGroup *rgpIVsOutputGroup[],
    //    /* [out, optional]          */ ULONG *pcActual);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(get_OutputGroups)(
        /* [in]                     */ ULONG celt,
        /* [in, out, size_is(celt)] */ IVsOutputGroup *rgpIVsOutputGroup[],
        /* [out, optional]          */ ULONG *pcActual);

    //----------------------------------------------------------------------
    // Function:    OpenOutputGroup
    //              Returns a specific output group.
    //
    // Parameters: 
    //    /* [in]  */ LPCOLESTR szCanonicalName,
    //    /* [out] */ IVsOutputGroup **ppIVsOutputGroup);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(OpenOutputGroup)(
        /* [in]  */ LPCOLESTR szCanonicalName,
        /* [out] */ IVsOutputGroup **ppIVsOutputGroup);

    //----------------------------------------------------------------------
    // Function:    OutputsRequireAppRoot
    // Parameters: 
    //    /* [out] */ BOOL *pfRequiresAppRoot);
    // Returns:     HRESULT
    // Notes:
    //              This method replaces the get_IsWebApplication() method 
    //              from the now-obsolete IVsDeployWebProject interface.
    //----------------------------------------------------------------------
    STDMETHOD(OutputsRequireAppRoot)(
        /* [out] */ BOOL *pfRequiresAppRoot);
		
    //----------------------------------------------------------------------
    // Function:    get_VirtualRoot
    // Parameters: 
    //    /* [out] */ BSTR *pbstrVRoot);
    // Returns:     HRESULT
    // Notes:
    //              This method is identical to the get_VirtualRoot method 
    //              from the now-obsolete IVsDeployWebProject interface.  
    //              It is required for debugging web projects.
    //----------------------------------------------------------------------
    STDMETHOD(get_VirtualRoot)(
        /* [out] */ BSTR *pbstrVRoot);

    //----------------------------------------------------------------------
    // Function:    get_IsPrivate
    // Parameters: 
    //    /* [out] */ BOOL *pfPrivate);
    // Returns:     HRESULT
    // Notes:
    //              This method tells whether this is a private (per user 
    //              as opposed to shared w/all team) config.
    //----------------------------------------------------------------------
    STDMETHOD(get_IsPrivate)(
        /* [out] */ BOOL *pfPrivate);

//
//                                                  IVsProjectCfg2 interface
// -------------------------------------------------------------------------


// -------------------------------------------------------------------------
//                                                    IVsProjectCfg2 helpers

public:

    //----------------------------------------------------------------------
    // Function:    get_KeyOutput
    //              Returns the key output for the specified output group.
    // Parameters: 
    //    /* [in]  */ OUTPUTGROUPTYPE ogt,
    //    /* [out] */ BSTR*           pbstrCanonicalName);
    // Returns:     HRESULT 
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(get_OgtKeyOutput)(
        /* [in]  */ OUTPUTGROUPTYPE ogt,
        /* [out] */ BSTR*           pbstrCanonicalName);

    //----------------------------------------------------------------------
    // Function:    AddOgtOutputsToArray
    //              Adds outputs from output group type "ogt" to array of
    //              IVsOutput2 pointers pointed by "prgpIVsOutput2".
    // Parameters: 
    //    /* [in]      */  OUTPUTGROUPTYPE ogt,
    //    /* [in, out] */  IVsOutput2Array* prgpIVsOutput2);
    // Returns:     HRESULT 
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(AddOgtOutputsToArray)(
        /* [in]      */  OUTPUTGROUPTYPE ogt,
        /* [in, out] */  IVsOutput2Array* prgpIVsOutput2);

    //----------------------------------------------------------------------
    // Function:    AddAllOutputsToArray
    //              Adds all outputs from the project configuration to 
    //              array of IVsOutput2 pointers pointed by "prgpIVsOutput2".
    // Parameters: 
    //    /* [in, out] */  IVsOutput2Array* prgpIVsOutput2);
    // Returns:     HRESULT 
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(AddAllOutputsToArray)(
        /* [in, out] */  IVsOutput2Array* prgpIVsOutput2);

protected:
    //----------------------------------------------------------------------
    // Function:    GetOutputGroupsCount
    //              Returns the number of the output groups.
    // Parameters: 
    // Returns:     USHORT - number of the output groups
    // Notes:
    //              Returns identical information regardless of cfg settings.
    //----------------------------------------------------------------------
    USHORT GetOutputGroupsCount();

    STDMETHOD(AddBuiltOutputsToArray)(
        /* [in,out] */  IVsOutput2Array* prgpIVsOutput2);

    STDMETHOD(AddSourceFilesOutputsToArray)(
        /* [in, out] */  IVsOutput2Array* prgpIVsOutput2);


//                                                    IVsProjectCfg2 helpers
// -------------------------------------------------------------------------
//                                                            IVsProjectCfg2
// =========================================================================
    


// =========================================================================
//                                                         IMyCProjCfgProps
//
// -------------------------------------------------------------------------
//                                                IMyCProjCfgProps interface
public:
    STDMETHOD(get_SourceFile)        (/* [out] */ BSTR *pbstr);
    STDMETHOD(put_SourceFile)        (/* [in]  */ BSTR bstr);
    STDMETHOD(get_ProjectType)       (/* [out] */ BSTR *pbstr);
    STDMETHOD(put_ProjectType)       (/* [in]  */ BSTR bstr);
    STDMETHOD(get_OutputPath)        (/* [out] */ BSTR *pbstr);
    STDMETHOD(put_OutputPath)        (/* [in]  */ BSTR bstr);
    STDMETHOD(get_DebugInfoChecked)  (/* [out] */ VARIANT_BOOL * pvb);
    STDMETHOD(put_DebugInfoChecked)  (/* [in]  */ VARIANT_BOOL vb);
    STDMETHOD(get_ListingFileChecked)(/* [out] */ VARIANT_BOOL * pvb);
    STDMETHOD(put_ListingFileChecked)(/* [in]  */ VARIANT_BOOL vb);
    STDMETHOD(get_CommandLine)       (/* [out] */ BSTR *pbstr);

    //--------------------------------------------------------------------------
    //[propget] HRESULT OutputFile([out, retval] BSTR *pbstr);
    // Get the absolute name (lower case) of the output file (exe, or dll) or 
    // "" if the source file or the project type are not specified in the 
    // configuration properties 
    //--------------------------------------------------------------------------
    STDMETHOD(get_OutputFile)        (/* [out] */ BSTR *pbstr);
    STDMETHOD(get_DebugStartMode)    (/* [out] */ MyCPrjDebugStartMode *pdebugStartMode);
    STDMETHOD(put_DebugStartMode)    (/* [in]  */ MyCPrjDebugStartMode debugStartMode);
    STDMETHOD(get_StartApp)          (/* [out] */ BSTR *pbstr);
    STDMETHOD(put_StartApp)          (/* [in]  */ BSTR bstr);
    STDMETHOD(get_StartAppPath)      (/* [out] */ BSTR *pbstr);
    STDMETHOD(put_StartAppPath)      (/* [in]  */ BSTR bstr);
    STDMETHOD(get_CustomStartupArguments) (/* [out] */ BSTR *pbstr);
    STDMETHOD(put_CustomStartupArguments) (/* [in]  */ BSTR bstr);
        
    // Returns the requested extender object if it is available.
    STDMETHOD(get_Extender)(
        /* [in]          */ BSTR         bstrExtenderName, 
        /* [out, retval] */ IDispatch ** ppExtender);

    // Returns a safe array of string names of currently applicable extenders.
    STDMETHOD(get_ExtenderNames)(
        /* [out, retval] */ VARIANT * pvarExtenderNames);

    // Returns the GUID string for the Project object that is the category ID for 
    // searching for automation extenders. Implementers of extenders for this object 
    // need to know its extender CATID.
    STDMETHOD(get_ExtenderCATID)(
        /* [out, retval] */ BSTR * pbstrRetval);


//                                                IMyCProjCfgProps interface
// -------------------------------------------------------------------------

// -------------------------------------------------------------------------
//                                           IMyCProjCfgProps implementation
protected:
    HRESULT GetProperty
    (
        /* [in ] */ const CString& str,     // string to copy from
        /* [out] */       BSTR *   pbstr    // bstr to copy to
    );

    HRESULT GetProperty
    (
        /* [in ] */ VARIANT_BOOL   vb,     // copy from
        /* [out] */ VARIANT_BOOL * pvb     // copy to
    );
    //----------------------------------------------------------------------
    //Generic PutProperty functions
    //----------------------------------------------------------------------
    HRESULT PutProperty
    (
        /* [in]  */ BSTR     bstr,   // bstr to copy from
        /* [in]  */ BOOL     fMustRebuild,    // must rebuild flag
        /* [out] */ CString& str     // string to copy to
    );

    HRESULT PutProperty
    (
        /* [in]  */ VARIANT_BOOL   vbFrom, // copy from
        /* [in]  */ BOOL           fMustRebuild,    // must rebuild flag
        /* [out] */ VARIANT_BOOL&  vbTo    // string to copy to
    );

public:
    BOOL& MustRebuild() { return m_fMustRebuild;};

//                                           IMyCProjCfgProps implementation
// -------------------------------------------------------------------------
//                                                         IMyCProjCfgProps
// =========================================================================

// =========================================================================
//                                                                   MEMBERS
protected:
    // --------------------------------------------------------------------
	//                                                           Properties
    // If you add additional properties, be sure to update Clone method
    // Exported properties
    // Build
    CString      m_strSourceFile;        // full path to the source file
	CString      m_strProjectType;       // type of the project (dll or exe)
	CString      m_strOutputPath;        // output path
    VARIANT_BOOL m_vbDebugInfoChecked;   // debug info flag
    VARIANT_BOOL m_vbListingFileChecked; // listing file flag
    // Debug
    CString      m_strStartApp;
    CString      m_strStartAppPath;
    CString      m_strCustomStartupArguments;
    MyCPrjDebugStartMode m_enumMyCPrjDebugStartMode;

	// Internal properties
    CString      m_strCfgName;
    CString      m_strPlatformName;
    CString      m_strName; // strCfgName+"|"+strPlatformName;

    CMyProjectHierarchy *m_pHier; // ptr to hierarchy.
    BOOL         m_fMustRebuild;

    // DebuggableProjectCfg members;
    CVsDebugTargetInfo * m_pTargetExe;
    VSDBGLAUNCHFLAGS m_grfLaunch;

    // IVsProjectCfg2 members
    OUTPUTGROUPTYPE m_rgogt[2]; // currently we support two output groups
    // --------------------------------------------------------------------
//                                                                   MEMBERS
// =========================================================================

};



/////////////////////////////////////////////////////////////////////////////
// CMyProjBuildableCfg
//		class to handle the build operation for a given project configuration.
//
//---------------------------------------------------------------------------
// implements:
//		interface: IVsBuildableProjectCfg
//---------------------------------------------------------------------------
class CMyProjBuildableCfg :
		public IVsBuildableProjectCfg,
        public IVsBuildStatusCallback,
		public CComObjectRootEx<CComMultiThreadModel> // explict
{
public:
	CMyProjBuildableCfg();
	~CMyProjBuildableCfg();
	HRESULT Init(CMyProjectCfg *pProjectCfg, CMyProjectHierarchy *pHier);

    BEGIN_COM_MAP(CMyProjBuildableCfg)
	    COM_INTERFACE_ENTRY(IVsBuildableProjectCfg)	// derives from IUnknown
	    COM_INTERFACE_ENTRY(IVsBuildStatusCallback)	// derives from IUnknown
    END_COM_MAP()
    DECLARE_NOT_AGGREGATABLE(CMyProjBuildableCfg)

// IVsBuildableProjectCfg
public:
	STDMETHOD(get_ProjectCfg)(
        /* [out] */ IVsProjectCfg **ppIVsProjectCfg);

	STDMETHOD(AdviseBuildStatusCallback)(
        /* [in]  */ IVsBuildStatusCallback *pIVsBuildStatusCallback,
        /* [out] */ VSCOOKIE *pdwCookie);

	STDMETHOD(UnadviseBuildStatusCallback)(
        /* [in] */ VSCOOKIE dwCookie);

    STDMETHOD(QueryStartBuild)(
        /* [in]            */ DWORD dwOptions,
        /* [out, optional] */ BOOL *pfSupported, 
        /* [out, optional] */ BOOL *pfEnabled);

    STDMETHOD(QueryStartClean)(
        /* [in]            */ DWORD dwOptions,
        /* [out, optional] */ BOOL *pfSupported, 
        /* [out, optional] */ BOOL *pfEnabled);

    STDMETHOD(QueryStartUpToDateCheck)(
        /* [in]            */ DWORD dwOptions,
        /* [out, optional] */ BOOL *pfSupported, 
        /* [out, optional] */ BOOL *pfEnabled);

	STDMETHOD(StartBuild)(
        /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane, 
        /* [in] */ DWORD dwOptions);

	STDMETHOD(StartClean)(
        /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane, 
        /* [in] */ DWORD dwOptions);

	STDMETHOD(StartUpToDateCheck)(
        /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane, 
        /* [in] */ DWORD dwOptions);

	STDMETHOD(QueryStatus)(
        /* [out] */BOOL *pfBuildDone);

	STDMETHOD(Stop)(
        /* [in] */BOOL fSync);

	STDMETHOD(Wait)(
        /* [in] */ DWORD dwMilliseconds, 
        /* [in] */ BOOL fTickWhenMessageQNotEmpty);

    // *** IVsBuildStatusCallback methods ***
    STDMETHOD(BuildBegin)(BOOL *pfContinue);
    STDMETHOD(BuildEnd)(BOOL fSuccess);
    STDMETHOD(Tick)(BOOL *pfContinue);

protected:
	STDMETHOD(IsBuildUpToDate)(
	    /* [out] */ BOOL* pfIsBuildUpToDate);
    BOOL FireBuildBegin();
    void FireBuildEnd(BOOL fSuccessful);

public:
	BOOL FFireTick();
    BSTR GetProjectName();
    BSTR GetCommandLine();
    BSTR GetProjectDir();
    BSTR GetSourceFile();
    BSTR GetProjectType();
    void SetThread(HANDLE hThread);
    BOOL Busy();

	// builder thread class
	class CBuilderThread : public CVsThread<CMyProjBuildableCfg>
	{
		typedef CVsThread<CMyProjBuildableCfg> super;
		friend class CMyProjBuildableCfg;

	public:
		CBuilderThread();
		~CBuilderThread();

		enum Operation
		{
			eIdle,
			eBuild,
			eCheckUpToDate,
			eClean,
		};

		HRESULT Start(CMyProjBuildableCfg *pCMyProjBuildableCfg, Operation op);
		void Stop(BOOL fSync);
		void QueryStatus(BOOL *pfDone);

		virtual void InternalTick(BOOL &rfContine);

		CMyProjBuildableCfg *m_pCMyProjBuildableCfg;
        CComPtr<IVsLaunchPadFactory> m_srpIVsLaunchPadFactory;

		void Fire_Tick(BOOL &rfContinue);

	protected:
		virtual HRESULT PrepareInStartingThread(CMyProjBuildableCfg *pCMyProjBuildableCfg);
		virtual void ThreadMain(CMyProjBuildableCfg *pBuildableCfg);
		virtual HRESULT InnerThreadMain(CMyProjBuildableCfg *pBuildableCfg);

		virtual void ReleaseThreadHandle();

		void Fire_BuildBegin(BOOL &rfContinue);
		void Fire_BuildEnd(BOOL fSuccess);

		void DoBuild(BOOL &rfSuccessful);
		void DoCheckIsUpToDate(BOOL &rfSuccessful);
		void DoClean(BOOL &rfSuccessful);
        void OutputText(LPCWSTR wsz);
        HRESULT OutputTaskItemText(
            /* [in] */ LPCTSTR        pszOutputString,
            /* [in] */ LPCTSTR        pszFilename     = _T(""),
            /* [in] */ LPCTSTR        pszTaskItemText = NULL ,
            /* [in] */ VSTASKPRIORITY nPriority       = TP_HIGH,
            /* [in] */ VSTASKCATEGORY nCategory       = CAT_BUILDCOMPILE,
            /* [in] */ LPCTSTR        pszSubcategory  = _T(""),
            /* [in] */ VSTASKBITMAP   nBitmap         = BMP_COMPILE,
            /* [in] */ ULONG          nLineNum        = 0);
        HRESULT RunCommandLine();

        
        CVxTypedPtrArray<CVxPtrArray, IStream*> m_rgpIStream_IVsBuildStatusCallback;
        CVxTypedPtrArray<CVxPtrArray, IVsBuildStatusCallback*> m_rgpIVsBuildStatusCallback;

		IStream *m_pIStream_IVsOutputWindowPane;
		IVsOutputWindowPane *m_pIVsOutputWindowPane;

		IStream *m_pIStream_IVsStatusbar;
		IVsStatusbar *m_pIVsStatusbar;

		BOOL m_fIsUpToDate;
		Operation m_op;

		HANDLE m_hEventStartSync;
#ifdef DEBUG
		DWORD m_dwWorkerThreadId;
#endif // DEBUG

		using super::Start;
	};

public:
    CBuilderThread  m_thread;

protected:

    CComBSTR cbstrProjectName;
    CComBSTR cbstrCommandLine; 
    CComBSTR cbstrProjectDir;
    CComBSTR cbstrSourceFile;
    CComBSTR cbstrProjectType;
    
public:
	CMyProjectCfg *m_pProjectCfg; // ptr back to the config.
	CMyProjectHierarchy *m_pHier; // ptr to hierarchy.

    CVsAdviseList<IVsBuildStatusCallback> m_alIVsBuildStatusCallback;

#ifdef DEBUG
	DWORD   m_dwBuilderThreadId;
#endif // DEBUG
	CComPtr<IVsOutputWindowPane>    m_pIVsOutputWindowPane;
	CComPtr<IVsStatusbar>           m_pIVsStatusbar;

    BOOL    m_fStopBuild; // flag to stop the build in progress.

};

#define WM_PROJECTBUILDALLMSG       WM_USER+1
#define WM_PROJECTCLEANMSG          WM_USER+2
#define WM_PROJECTCHECKUPTODATEMSG  WM_USER+3

LRESULT CALLBACK ProjectBuildWndProc(HWND hwnd, UINT wm, WPARAM wParam, LPARAM lParam);

