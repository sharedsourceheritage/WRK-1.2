
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// projcfg.cpp : Implementation of the CMyProjectCfg configuration object.
//			   This object is involved in Build/Debug/Deploy operations

#include "stdafx.h"
#include "PrjInc.h"

CMyProjectCfg::CMyProjectCfg()  
{
	ATLTRACE(TEXT("        specifically CMyProjectCfg created\n"));
	m_fCfgChangedSinceLastBuilt = TRUE;
}

CMyProjectCfg::~CMyProjectCfg()
{
	ATLTRACE(TEXT("CMyProjectCfg destructed -- "));
}

//--------------------------------------------------------------------------
// Function:    CMyProjectCfg::Init
//              Initialize CMyProjectCfg object
//
// Parameters:
// 
// Notes:
//      At the time Init() is called, CMyProjectHierarchy's SetRootNode() 
//      may not yet be called. Therefore, we cannot call GetProjectNode() 
//      or GetRootNode() in this function.
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::Init(
    CMyProjectHierarchy *pHier, 
    const CString& strCfgName,
    const CString& strPlatformName)
{
    ExpectedPtrRet(pHier);
    m_pHier = pHier;
    m_strCfgName = strCfgName;
    m_strPlatformName = strPlatformName;
    UpdateName();

    return S_OK;
}

HRESULT CMyProjectCfg::Clone(CMyProjectCfg* pClonedCfg)
{
    ExpectedPtrRet(pClonedCfg);

    HRESULT hr = S_OK;
       
    // Clone the property table
    pClonedCfg->m_strOutputDirectory=m_strOutputDirectory;

    // m_pHier is not cloned - it is set up in Init().

    // cfg 
    // m_strCfgName;
    // m_strPlatformName;
    // m_strName; // strCfgName+"|"+strPlatformName;

    // m_strCfgName, m_strPlatformName, and m_strName cannot be cloned 
    // because the names of the new config may be different. 
    // They are set up in Init().

    return hr;
}

CString CMyProjectCfg::GetName() 
{ 
    return m_strName; 
}


HRESULT CMyProjectCfg::RenameCfgName(const CString& strNewCfgName)
{
    m_strCfgName = strNewCfgName;
    UpdateName();
    return S_OK;
}


HRESULT CMyProjectCfg::UpdateName()
{
    m_strName = m_strCfgName;
    if ( ! m_strPlatformName.IsEmpty())
    {
       m_strName += _T("|");
       m_strName += m_strPlatformName;
    }
    return S_OK;
}


//---------------------------------------------------------------------------
// Write information for configuration to project file.
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::Save
(
IVsPropertyStreamOut *pIVsPropertyStreamOut
)
{
	USES_CONVERSION;

	ASSERT(pIVsPropertyStreamOut);
    ExpectedPtrRet(pIVsPropertyStreamOut);
	HRESULT hr = S_OK;

	hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
									STR_BUILDOUTPUTS,
									T2COLE(m_strOutputDirectory),
									NULL /*szLineComment*/);

	return hr;
}


//---------------------------------------------------------------------------
// Read information for configuration to project file.
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::Load
(
IVsPropertyStreamIn *pIVsPropertyStreamIn
) 
{
	ASSERT(pIVsPropertyStreamIn);
    ExpectedPtrRet(pIVsPropertyStreamIn);
	HRESULT hr = S_OK;

	for (;;)
	{
		CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamIn;
		VSPROPERTYSTREAMPROPERTYTYPE vspspt;

		WCHAR rgwchPropName[_MAX_PATH];

		CComVariant varValue;

		hr = pIVsPropertyStreamIn->Read(NUMBER_OF(rgwchPropName), rgwchPropName, NULL, &vspspt, &varValue, NULL);
		ASSERT(SUCCEEDED(hr));
		if (FAILED(hr))
			return hr;

		if (rgwchPropName[0] == L'\0')
			break;

		if (vspspt != VSPSPT_SIMPLE || varValue.vt != VT_BSTR)
		{
			ASSERT(vspspt == VSPSPT_SIMPLE && varValue.vt == VT_BSTR);
			return E_UNEXPECTED;
		}

		if (_wcsicmp(rgwchPropName, STR_BUILDOUTPUTS) == 0)
			m_strOutputDirectory = varValue.bstrVal;
		else
		{
			// NOTE: we'll just ignore properties without recognized names
		}
	}

	return hr;
}

//----------------------------------------------------------------------
// Function:    SetProjectFileDirty
//              Set the "dirty" state
//
// Parameters:  
//  /* [in] */ BOOL fIsDirty
//
// Returns:     HRESULT
// Notes:
//----------------------------------------------------------------------
HRESULT CMyProjectCfg::SetProjectFileDirty(
    /* [in] */ BOOL fIsDirty)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::SetProjectFileDirty \n"));

	VARIANT_BOOL vbDirty = fIsDirty ? VARIANT_TRUE : VARIANT_FALSE;

    return m_pHier->put_IsDirty(vbDirty);
}

//---------------------------------------------------------------------------
// interface:IVsCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::get_DisplayName(/* [out] */BSTR *pbstrDisplayName)
{
    return get_CanonicalName(pbstrDisplayName);
}

STDMETHODIMP CMyProjectCfg::get_IsDebugOnly(/* [out] */BOOL *pfIsDebugOnly)
{
    // Obsolete method - return FALSE
    ExpectedPtrRet(pfIsDebugOnly);
    *pfIsDebugOnly = FALSE;
    return S_OK;
}

STDMETHODIMP CMyProjectCfg::get_IsReleaseOnly(/*[out] */BOOL *pfIsReleaseOnly)
{
    // Obsolete method - return FALSE
    ExpectedPtrRet(pfIsReleaseOnly);
    *pfIsReleaseOnly = FALSE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::get_ProjectCfgProvider(/* [out] */IVsProjectCfgProvider **ppIVsProjectCfgProvider)
{
    ExpectedPtrRet(ppIVsProjectCfgProvider);

    HRESULT hr;
    CComPtr<IVsCfgProvider> srpCfgProvider;

    hr = m_pHier->GetCfgProvider(&srpCfgProvider);
    IfFailRet(hr);

    hr = srpCfgProvider->QueryInterface(IID_IVsProjectCfgProvider,
                                 (void**)ppIVsProjectCfgProvider);
    return hr;
}

//---------------------------------------------------------------------------
// interface:IVsProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::get_CanonicalName(/* [out] */BSTR *pbstrCanonicalName)
{
    ExpectedPtrRet(pbstrCanonicalName);

    *pbstrCanonicalName = m_strName.AllocSysString();

    return (*pbstrCanonicalName) ? S_OK : E_OUTOFMEMORY;
}

//---------------------------------------------------------------------------
// interface:IVsProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::EnumOutputs(/* [out] */IVsEnumOutputs **ppIVsEnumOutputs)
{
	if (!*ppIVsEnumOutputs)
		return E_INVALIDARG;
	*ppIVsEnumOutputs = NULL;	// always initialize out params

	return E_NOTIMPL;				// NYI

}

//---------------------------------------------------------------------------
// interface:IVsProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::OpenOutput(/* [in] */LPCOLESTR szOutputCanonicalName,
					/* [out] */IVsOutput **ppIVsOutput)
{
	if (!ppIVsOutput)
		return E_INVALIDARG;
	*ppIVsOutput = NULL;	// always initialize out params
    return E_NOTIMPL;		// this forces caller to call thru IVsEnumOutputs
}

//---------------------------------------------------------------------------
// interface:IVsProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::get_BuildableProjectCfg(/* [out] */IVsBuildableProjectCfg **ppIVsBuildableProjectCfg)
{
	if (!ppIVsBuildableProjectCfg)
		return E_INVALIDARG;
	*ppIVsBuildableProjectCfg = NULL;	// always initialize out params

	*ppIVsBuildableProjectCfg = static_cast<IVsBuildableProjectCfg*>(this);
	(*ppIVsBuildableProjectCfg)->AddRef();
    ASSERT(m_pHier->GetRootNode() != NULL);
    
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::get_IsPackaged(/* [out] */ BOOL __RPC_FAR *pfIsPackaged)
{
   ASSERT(pfIsPackaged != NULL);
   if (pfIsPackaged == NULL)
       return E_INVALIDARG;
   *pfIsPackaged = FALSE;
   return S_OK;
}
        
//---------------------------------------------------------------------------
// interface:IVsProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::get_RootURL(/* [out] */ BSTR *pbstrRootURL)
{
	if (!pbstrRootURL)
		return E_POINTER;
	*pbstrRootURL = NULL;	// always initialize out params

    CString strRoot(_T("file:///")), strAbs;
    CFileVwProjNode *pProjNode = m_pHier->GetProjectNode();

   	ASSERT(pProjNode->IsKindOf(Type_CFileVwProjNode));
   	
	strAbs = pProjNode->GetFolderPath();

    strRoot += strAbs;
    *pbstrRootURL = strRoot.AllocSysString();

    return (*pbstrRootURL) ? S_OK : E_OUTOFMEMORY;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::get_ProjectCfg(/* [out] */ IVsProjectCfg **ppIVsProjectCfg)
{
	// Validate
    ExpectedPtrRet(ppIVsProjectCfg);
    InitParam(ppIVsProjectCfg);
	*ppIVsProjectCfg = static_cast<IVsProjectCfg*>(this);;
	(*ppIVsProjectCfg)->AddRef();
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::AdviseBuildStatusCallback(/* [in] */ IVsBuildStatusCallback *pIVsBuildStatusCallback,
									 /* [out] */VSCOOKIE *pdwCookie)
{
	if (pdwCookie == NULL)
		return E_POINTER;

	if (NULL == pIVsBuildStatusCallback)
		return E_INVALIDARG;

	ULONG i;

	for (i=0; i<NUMBER_OF(m_rgsrpIVsBuildStatusCallback); i++)
	{
		if (m_rgsrpIVsBuildStatusCallback[i] == NULL)
			break;
	}

	if (i < NUMBER_OF(m_rgsrpIVsBuildStatusCallback))
	{
		*pdwCookie = (i + 1);
		m_rgsrpIVsBuildStatusCallback[i] = pIVsBuildStatusCallback;

		// We'll tick right now so we can just keep track of whether we want
		// to issue further ticks.
		HRESULT hr = pIVsBuildStatusCallback->Tick(NULL);
		ASSERT(SUCCEEDED(hr));

		m_rgfTicking[i] = (hr != S_FALSE);

		return NOERROR;
	}

	// We're out of room.
	return CONNECT_E_ADVISELIMIT;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::UnadviseBuildStatusCallback(/* [in] */ VSCOOKIE dwCookie)
{
	ASSERT(dwCookie > 0 && dwCookie <= NUMBER_OF(m_rgsrpIVsBuildStatusCallback));
	if (dwCookie <= 0 || dwCookie > NUMBER_OF(m_rgsrpIVsBuildStatusCallback))
		return E_INVALIDARG;
		
	ASSERT(m_rgsrpIVsBuildStatusCallback[dwCookie-1] != NULL);
	m_rgsrpIVsBuildStatusCallback[dwCookie-1] = NULL;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::QueryStartBuild(/* [in] */ DWORD dwOptions,
        /* [out, optional] */BOOL *pfSupported, /* [out, optional] */ BOOL *pfEnabled)
{
    if (pfSupported)
        *pfSupported = TRUE;
    if (pfEnabled)
        *pfEnabled = TRUE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::QueryStartClean(/* [in] */ DWORD dwOptions,
        /* [out, optional] */BOOL *pfSupported, /* [out, optional] */ BOOL *pfEnabled)
{
    if (pfSupported)
        *pfSupported = TRUE;
    if (pfEnabled)
        *pfEnabled = TRUE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::QueryStartUpToDateCheck(
	/* [in]			   */ DWORD dwOptions,
    /* [out, optional] */ BOOL* pfSupported, 
	/* [out, optional] */ BOOL* pfEnabled)
{
    if (pfSupported)
        *pfSupported = TRUE;
    if (pfEnabled)
        *pfEnabled = TRUE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg:: StartBuild(
/* [in] */IVsOutputWindowPane *pIVsOutputWindowPane,
/* [in] */DWORD dwOptions)
{
	HRESULT hr = S_OK;
    ExpectedPtrRet(pIVsOutputWindowPane);
	if (FFireBuildBegin())
	{
		CFigBuildManager FigBuildManager;
		BOOL fDoBuild = TRUE;
		if (!(dwOptions & VS_BUILDABLEPROJECTCFGOPTS_REBUILD))
		{
			// check for up-to-date
			BOOL fIsUpToDate = FALSE;
			hr = IsBuildUpToDate(&fIsUpToDate);
			if (SUCCEEDED(hr) && fIsUpToDate)
				fDoBuild = FALSE;
		}
		if (fDoBuild) 
		{
			hr = FigBuildManager.Build( pIVsOutputWindowPane, m_pHier, m_strOutputDirectory );		
			ASSERT(SUCCEEDED(hr));
			if (SUCCEEDED(hr) && (hr == S_OK))
				m_fCfgChangedSinceLastBuilt = FALSE;
		}
		else
		{
			CString strUpToDate;
			strUpToDate.LoadString(IDS_UPTODATE);
			ASSERT(!strUpToDate.IsEmpty());
			pIVsOutputWindowPane->OutputString(T2COLE(strUpToDate));
		}
		FireBuildEnd(hr == S_OK);
	}
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg:: StartClean(
/* [in] */IVsOutputWindowPane *pIVsOutputWindowPane,
/* [in] */DWORD dwOptions)
{
    HRESULT hr = S_OK;
    ExpectedPtrRet(pIVsOutputWindowPane);
	if (FFireBuildBegin())
	{
		CFigBuildManager FigBuildManager;
		hr = FigBuildManager.Clean(pIVsOutputWindowPane, m_pHier, m_strOutputDirectory );
		FireBuildEnd( SUCCEEDED(hr));
	}
	return hr;
}


STDMETHODIMP CMyProjectCfg::IsBuildUpToDate(
	/* [out] */ BOOL* pfIsBuildUpToDate)
{
    ExpectedPtrRet(pfIsBuildUpToDate);
    *pfIsBuildUpToDate = FALSE;
    HRESULT hr = S_OK;

    // first check whether the cfg settings has changed since the last time 
    // we built
    if (m_fCfgChangedSinceLastBuilt)
        return S_OK;

    // next check for any updates required from the build manager
    CFigBuildManager figBuildManager;
    hr = figBuildManager.IsBuildUpToDate(
                m_pHier, 
                m_strOutputDirectory, 
                pfIsBuildUpToDate);
    IfFailRet(hr);

    return hr;
}


//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::StartUpToDateCheck(
/* [in] */IVsOutputWindowPane *pIVsOutputWindowPane,
/* [in] */DWORD dwOptions)
{
    BOOL fIsUpToDate = FALSE;
    HRESULT hr = IsBuildUpToDate(&fIsUpToDate);
    if ( SUCCEEDED(hr) )
    {
        hr = (TRUE==fIsUpToDate) ? S_OK : E_FAIL;
    }
    return hr;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg:: QueryStatus
(
BOOL *pfBuildDone
)
{
    ExpectedPtrRet(pfBuildDone);
    *pfBuildDone = FALSE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg:: Stop
(
BOOL fSync
)
{
     return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg:: Wait
(
DWORD dwMilliseconds,
BOOL fTickWhenMessageQNotEmpty
)
{
     return S_OK;
}


// advise the sink that the build has begun.
BOOL CMyProjectCfg::FFireBuildBegin()
{
	BOOL fContinue = TRUE;
	HRESULT	hr;
	
	for (int i=0; i<NUMBER_OF(m_rgsrpIVsBuildStatusCallback); i++)
	{
		if (m_rgsrpIVsBuildStatusCallback[i] != NULL && m_rgfTicking[i])
		{
			hr = m_rgsrpIVsBuildStatusCallback[i]->BuildBegin(&fContinue);
			ASSERT(SUCCEEDED(hr));
			if (!fContinue)
				return FALSE;
		}
	}
	return TRUE;
}

// advise the sink that the build has ended.
void CMyProjectCfg::FireBuildEnd(BOOL fSuccessful)
{
	HRESULT	hr;
	
	for (int i=0; i<NUMBER_OF(m_rgsrpIVsBuildStatusCallback); i++)
	{
		if (m_rgsrpIVsBuildStatusCallback[i] != NULL && m_rgfTicking[i])
		{
			hr = m_rgsrpIVsBuildStatusCallback[i]->BuildEnd(fSuccessful);
			ASSERT(SUCCEEDED(hr));
		}
	}
}

//---------------------------------------------------------------------------
// interface:ISpecifyPropertyPages
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::GetPages(CAUUID *pPages)
{
    ExpectedPtrRet(pPages);

    pPages->cElems = 1;
    pPages->pElems = (GUID*)CoTaskMemAlloc(pPages->cElems*sizeof(GUID));
    if (!pPages->pElems)
        return E_OUTOFMEMORY;

    pPages->pElems[0] = CLSID_OutputDirectoryPPG;
    return S_OK;
}

//--------------------------------------------------------------------------
// interface IFigProjCfgProps
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::get_OutputDirectory(BSTR *pVal)
{
    ExpectedPtrRet(pVal);
    *pVal = m_strOutputDirectory.AllocSysString();
    return (*pVal) ? S_OK : E_OUTOFMEMORY;
}

HRESULT CMyProjectCfg::put_OutputDirectory(BSTR OutputDirectory)
{
	m_strOutputDirectory = CString(OutputDirectory);
	SetProjectFileDirty(TRUE);
	m_fCfgChangedSinceLastBuilt = TRUE;
	
  return S_OK;
}


STDMETHODIMP CMyProjectCfg::get_Extender(
    /* [in]          */ BSTR         bstrExtenderName, 
    /* [out, retval] */ IDispatch ** ppExtender)
{
    ExpectedPtrRet(bstrExtenderName);
    ExpectedPtrRet(ppExtender);
    InitParam(ppExtender);

    HRESULT hr = S_OK;

    CComPtr<VxDTE::ObjectExtenders> srpObjectExtenders = _VxModule.GetObjectExtenders();
    ExpectedExprRet(srpObjectExtenders != NULL);

    CComBSTR cbstrCATID;
    hr = get_ExtenderCATID(&cbstrCATID);
    IfFailRet(hr);

    hr = srpObjectExtenders->GetExtender(
        /* [in] BSTR ExtenderCATID              */ cbstrCATID,
        /* [in] BSTR ExtenderName               */ bstrExtenderName,
        /* [in] IDispatch *ExtendeeObject       */ (LPDISPATCH)this,
        /* [retval][out] IDispatch **Extender   */ ppExtender);

    return hr;
}


STDMETHODIMP CMyProjectCfg::get_ExtenderNames(
    /* [out, retval] */ VARIANT * pvarExtenderNames)
{
    ExpectedPtrRet(pvarExtenderNames);
    HRESULT hr = S_OK;

    CComPtr<VxDTE::ObjectExtenders> srpObjectExtenders = _VxModule.GetObjectExtenders();
    ExpectedExprRet(srpObjectExtenders != NULL);

    CComBSTR cbstrCATID;
    hr = get_ExtenderCATID(&cbstrCATID);
    IfFailRet(hr);

    hr = srpObjectExtenders->GetExtenderNames(
        /* [in] BSTR ExtenderCATID              */ cbstrCATID,
        /* [in] IDispatch *ExtendeeObject       */ (LPDISPATCH) this,
        /* [retval][out] VARIANT *ExtenderNames */ pvarExtenderNames);

    return hr;
}

    
STDMETHODIMP CMyProjectCfg::get_ExtenderCATID(
    /* [out, retval] */ BSTR * pbstrRetval)
{
    ExpectedPtrRet(pbstrRetval);
    InitParam(pbstrRetval);

    CComBSTR cbstrCATID(prjCATIDFigPrjProjectConfigBrowseObject);
    if (cbstrCATID.Length() == 0)
        return E_OUTOFMEMORY;

    *pbstrRetval = cbstrCATID.Detach();
    return S_OK;
}


//---------------------------------------------------------------------------
// interface: IVsDebuggableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::DebugLaunch
(
	/* [in] */ VSDBGLAUNCHFLAGS grfLaunch
)
{
    // Get the debug launch targets
    HRESULT             hr = E_FAIL;
    VsDebugTargetInfo*  pDebugTargetInfo = NULL;
    ULONG               numTgts = 0;

	IfFailGo(GetDebugLaunchTargets(grfLaunch, &pDebugTargetInfo, &numTgts));
	// If this is a non-debug launch, and we are debugging ASP, then just launch the URL
	//  If this is code debugging, we just pass the flag along to the debugger which
	//  will launch the exe without the debugger for us
	//
	if ( (DBGLAUNCH_NoDebug & grfLaunch) )
	{
        hr = S_OK;
        CString strExe = pDebugTargetInfo->bstrExe;
        strExe.Trim();
        if (strExe.IsEmpty())
            goto Error;
        if (strExe[0] != '"')
            strExe = '"' + strExe + '"';
		HINSTANCE res = ShellExecute(NULL, NULL, strExe, NULL, NULL, SW_SHOWNORMAL);
        goto Error;
	}
	else    // Run under the debugger
	{
		IVsDebugger* pDebugger = _VxModule.GetIVsDebugger();
		IfFalseGo(pDebugger, E_FAIL);
		// if dwOptions != DBGLAUNCH_LocalDeploy  use IVsDebuggerAssistant 
		// interface to map the startup item to deployed name before launching.
		ASSERT(pDebugTargetInfo && numTgts > 0);
		IfFailGo(pDebugger->LaunchDebugTargets(numTgts, pDebugTargetInfo));
    }

Error:
    if (pDebugTargetInfo)
    {
        // Clean up the launch target info
        for(DWORD i=0; i< numTgts; i++)
        {
            // Take out the BSTRs first.
            if(pDebugTargetInfo[i].bstrRemoteMachine)
                ::SysFreeString(pDebugTargetInfo[i].bstrRemoteMachine);
            if(pDebugTargetInfo[i].bstrExe)
                ::SysFreeString(pDebugTargetInfo[i].bstrExe);
            if(pDebugTargetInfo[i].bstrArg)
                ::SysFreeString(pDebugTargetInfo[i].bstrArg);
            if (pDebugTargetInfo[i].bstrCurDir)
                ::SysFreeString(pDebugTargetInfo[i].bstrCurDir);
            if (pDebugTargetInfo[i].bstrEnv)
                ::SysFreeString(pDebugTargetInfo[i].bstrEnv);
        }
        delete [] pDebugTargetInfo;
    }

    // Convert cancel to abort
    if(hr == OLE_E_PROMPTSAVECANCELLED)
        hr = E_ABORT;
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsDebuggableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::QueryDebugLaunch
(
	/* [in] */VSDBGLAUNCHFLAGS grfLaunch, 
	/* [out] */ BOOL __RPC_FAR *pfLaunchable
)
{
	if ( pfLaunchable == NULL )
	{
		return E_POINTER;
	}
    *pfLaunchable = TRUE;
    return S_OK;
}


HRESULT CMyProjectCfg::GetDebugLaunchTargets
(
	/* [in]  */ VSDBGLAUNCHFLAGS  grfLaunch,
	/* [out] */ VsDebugTargetInfo** ppDebugTargetInfo,
	/* [out]  */ ULONG* pcMax)
{
    ExpectedPtrRet(ppDebugTargetInfo);
    *ppDebugTargetInfo = NULL;
    ExpectedPtrRet(pcMax);
    *pcMax = 0;

    HRESULT     hr = S_OK;

    CComBSTR           cbstrOutputPath;
    CComBSTR           cbstrKeyOutput;
    VsDebugTargetInfo* pDebugTargetInfo=NULL;

    CComPtr<IVsOutputGroup> srpIVsOutputGroup;
	CComPtr<IVsHierarchy>   srpIVsHierarchyNested;
    CComPtr<IVsProjectCfg>  srpIVsProjectCfgNested;
    CComPtr<IVsProjectCfg2> srpIVsProjectCfg2Nested;
    CComPtr<IVsSolutionBuildManager> srpIVsSolutionBuildManager;

    // get the dependency project node;
    CBuildProjNode* pBuildProjNode = m_pHier->GetBuildProjNode();
    if (pBuildProjNode == NULL)
        return E_FAIL;

	srpIVsHierarchyNested = pBuildProjNode->GetNested();
    if (!srpIVsHierarchyNested)
        return E_FAIL;

    hr = _VxModule.QueryService(
        SID_SVsSolutionBuildManager,
        IID_IVsSolutionBuildManager,
        (void**) &srpIVsSolutionBuildManager);
    IfFailRet(hr);

    hr = srpIVsSolutionBuildManager->FindActiveProjectCfg(
        NULL,
        NULL,
        srpIVsHierarchyNested,
        &srpIVsProjectCfgNested);
    IfFailRet(hr);

    hr = srpIVsProjectCfgNested->QueryInterface(
        IID_IVsProjectCfg2,
        (void**) &srpIVsProjectCfg2Nested);
    IfFailRet(hr);

    hr = srpIVsProjectCfg2Nested->OpenOutputGroup(
        VS_OUTPUTGROUP_CNAME_Built,
        &srpIVsOutputGroup);
    IfFailRet(hr);

    hr = srpIVsOutputGroup->get_KeyOutput(&cbstrKeyOutput);
    IfFailRet(hr);

    // check if the output was deployed
    // Assume no remote deploy
    BOOL fRemoteDeploy = FALSE;
    CComBSTR cbstrDebugTarget;
    CComBSTR cbstrRemoteMachine;
    CComPtr<IVsSolutionDebuggingAssistant2> srpIVsSolutionDebuggingAssistant2;
    hr = _VxModule.QueryService(
        SID_SVsSolutionDebuggingAssistant2, 
        IID_IVsSolutionDebuggingAssistant2, 
        (void**)&srpIVsSolutionDebuggingAssistant2);
    // The deployment service may not be available
    // hence no assert/failure if it doesn't exist
    if (SUCCEEDED(hr) && (srpIVsSolutionDebuggingAssistant2 != NULL))
    {
        CComBSTR cbstrURL;
        ULONG    ulNoOfTargets;

	    // Projects start out their debugging sessions by calling MapOutputToDeployedURLs().
	    // The project sends through its configuration and the relevant IVsOutput.  Deployment
	    // check to see if it deployed the output.  If not, S_FALSE is returned.  
	    // If it was deployed, however, S_OK is returned, and lists of locations and machines
	    // are returned in the arrays.  (This is necessary since we might have deployed
	    // it to more than one place.)  Locations will be in the format "file:///D:\foo\bar\bang.exe"
	    // or, if relevant, "http://foo/bar/bang.html". Machines will be in the format "machine".
        hr = srpIVsSolutionDebuggingAssistant2->MapOutputToDeployedURLs(
		    /*[in] DWORD dwReserved                       */ 0,      // Reserved; must be 0
		    /*[in] IVsProjectCfg *pProjectCfg             */ srpIVsProjectCfgNested, 
		    /*[in] LPCOLESTR pszOutputCanonicalName       */ cbstrKeyOutput,
		    /*[in] ULONG celt                             */ 1,
		    /*[in,out,size_is(celt)] BSTR rgbstrMachines[]*/ &cbstrRemoteMachine,
		    /*[in,out,size_is(celt)] BSTR rgbstrURLs[]    */ &cbstrURL,
		    /*[out] ULONG *pcActual                       */ &ulNoOfTargets);
        if ( SUCCEEDED(hr) && (ulNoOfTargets > 0) )
        {
            fRemoteDeploy = TRUE;

            CString strDebugTarget = cbstrURL;
            strDebugTarget.MakeLower();
            strDebugTarget.Replace(_T("file:///"), NULL);     // removing the "file:///" part.

            cbstrDebugTarget = strDebugTarget;
        }
    }
    hr = S_OK;

    WCHAR wszDrive[_MAX_DRIVE];
    WCHAR wszDir[_MAX_DIR];
    _wsplitpath(cbstrKeyOutput,wszDrive,wszDir, NULL, NULL);
    cbstrOutputPath =  wszDrive;
    cbstrOutputPath += wszDir;

	pDebugTargetInfo = new VsDebugTargetInfo;
    IfFalseGo(pDebugTargetInfo, E_OUTOFMEMORY);

    ::ZeroMemory(pDebugTargetInfo, sizeof(VsDebugTargetInfo));

    // set the size of the struct
    //
    pDebugTargetInfo->cbSize = sizeof(VsDebugTargetInfo);    
    pDebugTargetInfo->dlo = DLO_Custom;

    //  clsidCustom tells the debugger which debug engine we want to use.
    //  Passing GUID_NULL uses the native debugger, and guidCOMPlusNativeEng
    //  uses the COM+ debug enging
    //
    pDebugTargetInfo->clsidCustom = guidCOMPlusNativeEng; //GUID_NULL;
    pDebugTargetInfo->bstrCurDir  = cbstrOutputPath.Detach();
    if (fRemoteDeploy)
    {
        pDebugTargetInfo->bstrExe           = cbstrDebugTarget.Detach();
        pDebugTargetInfo->bstrRemoteMachine = cbstrRemoteMachine.Detach();
    }
    else
    {
        pDebugTargetInfo->bstrExe     = cbstrKeyOutput.Detach();
    }

    IfFalseGo(pDebugTargetInfo->bstrArg = ::SysAllocString(L""), E_OUTOFMEMORY);

    //GetEnvBlockInToBstr (&pDebugTargetInfo->bstrEnv);

    pDebugTargetInfo->grfLaunch = grfLaunch;
    pDebugTargetInfo->fSendStdoutToOutputWindow = TRUE;

    ENVSDK_TRACE(envsdkTraceGeneral, TLI,
            L"FigPrj: Launching debugger on '%s' with arguments '%s' in directory '%s'\n",
            pDebugTargetInfo->bstrExe, pDebugTargetInfo->bstrArg, pDebugTargetInfo->bstrCurDir);

    // if our target file does not exits, then return an error and tell the
    //  user that we can't find the launch target
    //
    if (!fRemoteDeploy && !LUtilFileExists(pDebugTargetInfo->bstrExe))
    {
        LUtilSetErrString1(IDS_E_DEBUGTARGETMISSING, W2T(pDebugTargetInfo->bstrExe));
        hr = E_FAIL;
        goto Error;
    }

    *ppDebugTargetInfo = pDebugTargetInfo;
    *pcMax = 1;
    hr = NOERROR;

    // fall through
Error:
    if (FAILED(hr))
    {
        if (pDebugTargetInfo)
        {
            if(pDebugTargetInfo->bstrRemoteMachine)
                ::SysFreeString(pDebugTargetInfo->bstrRemoteMachine);
            if(pDebugTargetInfo->bstrExe)
                ::SysFreeString(pDebugTargetInfo->bstrExe);
            if(pDebugTargetInfo->bstrArg)
                ::SysFreeString(pDebugTargetInfo->bstrArg);
            if (pDebugTargetInfo->bstrCurDir)
                ::SysFreeString(pDebugTargetInfo->bstrCurDir);
            if (pDebugTargetInfo->bstrEnv)
                ::SysFreeString(pDebugTargetInfo->bstrEnv);
            
            delete pDebugTargetInfo;
        }
    }
    return hr;
}




