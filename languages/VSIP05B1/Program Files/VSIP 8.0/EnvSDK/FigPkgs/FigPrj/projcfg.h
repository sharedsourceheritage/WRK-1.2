
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
  
/////////////////////////////////////////////////////////////////////////////
// CMyProjectCfg
//		class for a given project configuration.
//---------------------------------------------------------------------------
// implements:
//		interface: IVsCfg
//		interface: IVsProjectCfg
//		interface: IVsDebuggableProjectCfg
//		interface: IVsBuildableProjectCfg
//		interface: ISpecifyPropertyPages
//		interface: IDispatch
//---------------------------------------------------------------------------
class CMyProjectCfg :
	public IVsDebuggableProjectCfg, // -> IVsProjectCfg -> IVsCfg
	public IVsBuildableProjectCfg,
	public CComObjectRootEx<CComMultiThreadModel>,		// explict
	public ISpecifyPropertyPages,
	public IDispatchImpl<FigureProjectCfg, &IID_FigureProjectCfg, &LIBID_FigPrjPKGLib>
{
public:
	CMyProjectCfg();
    ~CMyProjectCfg();
	HRESULT Init(  
        CMyProjectHierarchy *pHier, 
        const CString& strCfgName,
        const CString& strPlatformName);
    HRESULT Clone(CMyProjectCfg* pClonedCfg);

	HRESULT Save(IVsPropertyStreamOut *pIVsPropertyStreamOut);
	HRESULT Load(IVsPropertyStreamIn *pIVsPropertyStreamIn);
    HRESULT SetProjectFileDirty(BOOL fDirty);

    CString  GetName(); 
    HRESULT RenameCfgName(const CString& strNewCfgName);
    HRESULT UpdateName();


BEGIN_COM_MAP(CMyProjectCfg)
    COM_INTERFACE_ENTRY(IVsCfg)
	COM_INTERFACE_ENTRY(IVsProjectCfg)		// derives from IUnknown
	COM_INTERFACE_ENTRY(IVsDebuggableProjectCfg)
	COM_INTERFACE_ENTRY(IVsBuildableProjectCfg)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
  COM_INTERFACE_ENTRY(FigureProjectCfg)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(CMyProjectCfg)

// IVsCfg
public:
	STDMETHOD(get_DisplayName)(/* [out] */BSTR *pbstrDisplayName);
	STDMETHOD(get_IsDebugOnly)(/* [out] */BOOL *pfIsDebugOnly);
	STDMETHOD(get_IsReleaseOnly)(/*[out] */BOOL *pfIsReleaseOnly);

// IVsProjectCfg
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

// IVsDebuggableProjectCfg
	STDMETHOD(DebugLaunch)(/* [in] */VSDBGLAUNCHFLAGS grfLaunch);
	STDMETHOD(QueryDebugLaunch)(
		/* [in] */VSDBGLAUNCHFLAGS grfLaunch, 
		/* [out] */ BOOL __RPC_FAR *pfLaunchable);

// helper function for IVsDebuggableProjectCfg
    STDMETHOD(GetDebugLaunchTargets)(
		/* [in]  */ VSDBGLAUNCHFLAGS  grfLaunch,
		/* [out] */ VsDebugTargetInfo** ppDebugTargetInfo,
		/* [out]  */ ULONG* pcMax);

// ISpecifyPropertyPages
public:
    STDMETHOD(GetPages)(/* [out] */ CAUUID *pPages);

// IVsBuildableProjectCfg
public:
	STDMETHOD(get_ProjectCfg)(/* [out] */ IVsProjectCfg **ppIVsProjectCfg);

	STDMETHOD(AdviseBuildStatusCallback)(/* [in] */IVsBuildStatusCallback *pIVsBuildStatusCallback,
	                           /* [out] */VSCOOKIE *pdwCookie);
	STDMETHOD(UnadviseBuildStatusCallback)(/* [in] */VSCOOKIE dwCookie);

    STDMETHOD(QueryStartBuild)(/* [in] */ DWORD dwOptions,
        /* [out, optional] */BOOL *pfSupported, /* [out, optional] */ BOOL *pfEnabled);
    STDMETHOD(QueryStartClean)(/* [in] */ DWORD dwOptions,
        /* [out, optional] */BOOL *pfSupported, /* [out, optional] */ BOOL *pfEnabled);
    STDMETHOD(QueryStartUpToDateCheck)(/* [in] */ DWORD dwOptions,
        /* [out, optional] */BOOL *pfSupported, /* [out, optional] */ BOOL *pfEnabled);
	STDMETHOD(StartBuild)(/* [in] */IVsOutputWindowPane *pIVsOutputWindowPane, /* [in] */DWORD dwOptions);
	STDMETHOD(StartClean)(/* [in] */IVsOutputWindowPane *pIVsOutputWindowPane, /* [in] */DWORD dwOptions);
	STDMETHOD(StartUpToDateCheck)(/* [in] */IVsOutputWindowPane *pIVsOutputWindowPane, /* [in] */DWORD dwOptions);
	STDMETHOD(QueryStatus)(/* [out] */BOOL *pfBuildDone);
	STDMETHOD(Stop)(/* [in] */BOOL fSync);
	STDMETHOD(Wait)(/* [in] */DWORD dwMilliseconds, /* [in] */BOOL fTickWhenMessageQNotEmpty);


    // interface FigureProjectCfg
    STDMETHOD(get_OutputDirectory)(BSTR *pVal);
    STDMETHOD(put_OutputDirectory)(BSTR OutputDirectory);

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

    CMyProjectHierarchy* CMyProjectCfg::GetHierarchy() { return m_pHier;}


protected:
	BOOL FFireBuildBegin();
	void FireBuildEnd(BOOL fSuccessful);
	STDMETHOD(IsBuildUpToDate)(
		/* [out] */ BOOL* pfIsBuildUpToDate);

protected:
	CMyProjectHierarchy *m_pHier; // ptr to hierarchy.
	// Internal properties
    CString      m_strCfgName;
    CString      m_strPlatformName;
    CString      m_strName; // strCfgName+"|"+strPlatformName;

	CComPtr<IVsBuildStatusCallback> m_rgsrpIVsBuildStatusCallback[5]; // allow 5 connections.
	BOOL	m_fCfgChangedSinceLastBuilt;
	BOOL		m_rgfTicking[5]; // whether tick events can be sent.
	BOOL    m_rgfStarted[5];
	BOOL    m_fDoIncrementalBuild;

	CString m_strOutputDirectory;
};



/********************************************************************************************
* Per configuration project settings PropertyPage support
********************************************************************************************/


template <typename T> 
class ATL_NO_VTABLE IFigProjPropertyPageImpl : public IVsPropertyPageImpl<T>
{
public:
	IFigProjPropertyPageImpl() : m_bInitWasCalled(FALSE)
	{
		m_dwHelpFileID = IDS_PROJECT_TYPE; // dummy ID to get the help method invoked
	}

BEGIN_MSG_MAP(IFigProjPropertyPageImpl)
	CHAIN_MSG_MAP(IVsPropertyPageImpl<T>)
END_MSG_MAP()

  LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		m_bInitWasCalled = TRUE;
		InitDialogValues();
		return 1;
	}

	STDMETHOD(Help)(LPCOLESTR pszHelpDir)
    {
        // show help here 
        HRESULT hr = DisplayTopicFromF1Keyword(m_strF1HelpKeyword);
        return hr;
	}

	void InitDialogValues()
	{
		InitValues();
	}
	// Because of a bug in atl, this is reproduced here with the fix
	void SetDirty(BOOL bDirty)
	{
		if (m_bDirty != bDirty)
		{
			m_bDirty = bDirty;
			m_pPageSite->OnStatusChange(PROPPAGESTATUS_DIRTY | PROPPAGESTATUS_VALIDATE);
		}
	}
	// Overridden to handle selection changes.
	STDMETHOD(SetObjects)(ULONG nObjects, IUnknown **ppUnk)
	{
        if (!ppUnk)     
            return S_OK;
		HRESULT hr = IVsPropertyPageImpl<T>::SetObjects(nObjects, ppUnk);
		if(hr == S_OK && m_bInitWasCalled && nObjects)
			InitDialogValues();
		return hr;
	}

protected:
	BOOL m_bInitWasCalled;
	// Override to initialize your dll's values
	virtual void InitValues(){};
  
    CString     m_strF1HelpKeyword;
};
