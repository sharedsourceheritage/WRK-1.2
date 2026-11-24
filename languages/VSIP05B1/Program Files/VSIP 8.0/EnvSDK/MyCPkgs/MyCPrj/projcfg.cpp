
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// projcfg.cpp : Implementation of the CMyProjectCfg configuration object.
//             This object is involved in Build/Debug/Deploy operations

#include "stdafx.h"
#include "PrjInc.h" 

/////////////////////////////////////////////////////////////////////////////
// These are used by the Load/Save operations.
const  WCHAR* STR_SourceFile         = L"SourceFile";
const  WCHAR* STR_ProjectType        = L"ProjectType";
const  WCHAR* STR_OutputPath         = L"OutputPath";
const  WCHAR* STR_DebugInfoChecked   = L"DebugInfoChecked";
const  WCHAR* STR_ListingFileChecked = L"ListingFileChecked";
const  WCHAR* STR_DebugStartMode     = L"DebugStartMode";
const  WCHAR* STR_StartApp           = L"StartApp";
const  WCHAR* STR_StartAppPath       = L"StartAppPath";
const  WCHAR* STR_CustomStartupArguments = L"CustomStartupArguments";



static const WCHAR g_wszMyCCompilerName[] = L"myc.exe";

// =========================================================================
//                                 Construct, initialize, copy, and destruct
//
CMyProjectCfg::CMyProjectCfg()  
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
         _T(":  CMyProjectCfg::CMyProjectCfg : this = 0x%x \n"), this);
}


CMyProjectCfg::~CMyProjectCfg()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
         _T(": CMyProjectCfg::~CMyProjectCfg : this = 0x%x \n"), this);

    ASSERT(!m_pTargetExe);
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
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::Init this = 0x%x \n"), this);

    ExpectedPtrRet(pHier);
    m_pHier     = pHier;
    m_strCfgName = strCfgName;
    m_strPlatformName = strPlatformName;
    UpdateName();


    // cfg default properties - can be overriden by Load or Clone
    BOOL fDebugCfg;
    fDebugCfg = (m_strCfgName.CompareNoCase(_T("Debug")) == 0);
    m_vbDebugInfoChecked   = fDebugCfg ? VARIANT_TRUE : VARIANT_FALSE;
    m_vbListingFileChecked = VARIANT_FALSE;
    m_enumMyCPrjDebugStartMode = MyCPrjDebugStartMode_Project;
    m_strProjectType = "EXE";

    m_fMustRebuild = TRUE;

    // DebuggableProjectCfg members;
    m_pTargetExe = NULL;

    // IVsProjectCfg2 members
    m_rgogt[0] = OGT_Built;
    m_rgogt[1] = OGT_SourceFiles;

    return S_OK;
}


HRESULT CMyProjectCfg::Clone(CMyProjectCfg* pClonedCfg)
{
    ExpectedPtrRet(pClonedCfg);

    HRESULT hr = S_OK;
       
    // Clone the property table
    pClonedCfg->m_strSourceFile=m_strSourceFile;
    pClonedCfg->m_strProjectType=m_strProjectType;
    pClonedCfg->m_strOutputPath=m_strOutputPath;
    pClonedCfg->m_vbDebugInfoChecked=m_vbDebugInfoChecked;
    pClonedCfg->m_vbListingFileChecked=m_vbListingFileChecked;
    pClonedCfg->m_enumMyCPrjDebugStartMode = m_enumMyCPrjDebugStartMode;
    pClonedCfg->m_strStartApp=m_strStartApp;
    pClonedCfg->m_strStartAppPath=m_strStartAppPath;
    pClonedCfg->m_strCustomStartupArguments=m_strCustomStartupArguments;


    // cfg 
    // m_strCfgName;
    // m_strPlatformName;
    // m_strName; // strCfgName+"|"+strPlatformName;

    // m_strCfgName, m_strPlatformName, and m_strName cannot be cloned 
    // because the names of the new config may be different. 
    // They are set up in Init().

    // m_pHier is not cloned - it is set up in Init().
    // m_fMustRebuild is not cloned - it is set to TRUE in Init().
    // m_rgogt is not cloned - it is set up in Init().

    return hr;
}

//
//                                 Construct, initialize, copy, and destruct
// =========================================================================


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


// =========================================================================
//                                                                Persisting

//--------------------------------------------------------------------------
// Write information for configuration to project file.
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::Save
(
    IVsPropertyStreamOut *pIVsPropertyStreamOut
) 
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::Save this = 0x%x \n"), this);

    USES_CONVERSION;

    ASSERT(pIVsPropertyStreamOut);
    ExpectedPtrRet(pIVsPropertyStreamOut);
    HRESULT hr = S_OK;

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_SourceFile,
                                    T2COLE(m_strSourceFile),
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_ProjectType,
                                    T2COLE(m_strProjectType),
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_OutputPath,
                                    T2COLE(m_strOutputPath),
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
            STR_DebugInfoChecked,
            T2COLE( (m_vbDebugInfoChecked == VARIANT_TRUE) ? 
                    _T("TRUE") : _T("FALSE")),
            NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
            STR_ListingFileChecked,
            T2COLE( (m_vbListingFileChecked == VARIANT_TRUE) ? 
                    _T("TRUE") : _T("FALSE")),
            NULL /*szLineComment*/);
    IfFailRet(hr);

    WCHAR wszDebugStartMode[32];
    _ltow((long) m_enumMyCPrjDebugStartMode, wszDebugStartMode, 10);
    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_DebugStartMode,
                                    wszDebugStartMode,
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_StartApp,
                                    T2COLE(m_strStartApp),
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_StartAppPath,
                                    T2COLE(m_strStartAppPath),
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_CustomStartupArguments,
                                    T2COLE(m_strCustomStartupArguments),
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    return hr;
}


//--------------------------------------------------------------------------
// Read information for configuration to project file.
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::Load
(
IVsPropertyStreamIn *pIVsPropertyStreamIn
) 
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::Load this = 0x%x \n"), this);

    ASSERT(pIVsPropertyStreamIn);
    ExpectedPtrRet(pIVsPropertyStreamIn);
    HRESULT hr = S_OK;

    for (;;)
    {
        CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamIn;
        VSPROPERTYSTREAMPROPERTYTYPE vspspt;

        WCHAR rgwchPropName[_MAX_PATH];

        CComVariant varValue;

        hr = pIVsPropertyStreamIn->Read(
             /* [in] ULONG cchPropertyName           */ NUMBER_OF(rgwchPropName), 
             /* [in, out] OLECHAR szPropertyName[]   */ rgwchPropName, 
             /* [out] ULONG *pcchPropertyNameActual  */ NULL, 
             /* [out] VSPROPERTYSTREAMPROPERTYTYPE * */ &vspspt, 
             /* [out] VARIANT *pvarValue             */ &varValue, 
             /* [in] IErrorLog *pIErrorLog           */ NULL);

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

        if (_wcsicmp(rgwchPropName, STR_SourceFile) == 0)
            m_strSourceFile = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_OutputPath) == 0)
            m_strOutputPath = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_ProjectType) == 0)
        {
            if (varValue.bstrVal != NULL)
            {
                if ((_wcsicmp(varValue.bstrVal, L"EXE") == 0) || (_wcsicmp(varValue.bstrVal, L"DLL") == 0))
                    m_strProjectType = varValue.bstrVal;
            }
        }
        else if (_wcsicmp(rgwchPropName, STR_DebugInfoChecked) == 0)
        {
            if (_wcsicmp(varValue.bstrVal, L"TRUE") == 0)
                m_vbDebugInfoChecked = VARIANT_TRUE;
            else
                m_vbDebugInfoChecked = VARIANT_FALSE;
        }
        else if (_wcsicmp(rgwchPropName, STR_ListingFileChecked) == 0)
        {
            if (_wcsicmp(varValue.bstrVal, L"TRUE") == 0)
                m_vbListingFileChecked = VARIANT_TRUE;
            else
                m_vbListingFileChecked = VARIANT_FALSE;
        }
        else if (_wcsicmp(rgwchPropName, STR_DebugStartMode) == 0)
        {
            LONG lStartMode = _wtol(varValue.bstrVal);
            if ((lStartMode >= MyCPrjDebugStartModeMin) && (lStartMode <= MyCPrjDebugStartModeMax))
                m_enumMyCPrjDebugStartMode = (MyCPrjDebugStartMode) lStartMode;
        }
        else if (_wcsicmp(rgwchPropName, STR_StartApp) == 0)
            m_strStartApp = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_StartAppPath) == 0)
            m_strStartAppPath = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_CustomStartupArguments) == 0)
            m_strCustomStartupArguments = varValue.bstrVal;
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

//                                                                Persisting
// =========================================================================


// =========================================================================
//                                                                    IVsCfg
//
//--------------------------------------------------------------------------
// Function     get_DisplayName 
//              Returns the name of the cfg bag.
// Parameters
//   pbstrDisplayName - Pointer to the display name. 
//--------------------------------------------------------------------------
STDMETHODIMP CMyProjectCfg::get_DisplayName(/* [out] */BSTR *pbstrDisplayName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_DisplayName this = 0x%x \n"), this);
    
    ExpectedPtrRet(pbstrDisplayName);

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


//                                                                    IVsCfg
// =========================================================================


// =========================================================================
//                                                             IVsProjectCfg
//
STDMETHODIMP CMyProjectCfg::get_ProjectCfgProvider(
    /* [out] */IVsProjectCfgProvider **ppIVsProjectCfgProvider)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_ProjectCfgProvider this = 0x%x \n"), this);
    
    ExpectedPtrRet(ppIVsProjectCfgProvider);

    HRESULT hr;
    CComPtr<IVsCfgProvider> srpCfgProvider;

    hr = m_pHier->GetCfgProvider(&srpCfgProvider);
    IfFailRet(hr);

    hr = srpCfgProvider->QueryInterface(IID_IVsProjectCfgProvider,
                                 (void**)ppIVsProjectCfgProvider);
    return hr;
}


STDMETHODIMP CMyProjectCfg::get_CanonicalName(/* [out] */BSTR *pbstrCanonicalName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_CanonicalName this = 0x%x \n"), this);
    
    ExpectedPtrRet(pbstrCanonicalName);

    *pbstrCanonicalName = m_strName.AllocSysString();

    return (*pbstrCanonicalName) ? S_OK : E_OUTOFMEMORY;
}


STDMETHODIMP CMyProjectCfg::EnumOutputs(
    /* [out] */IVsEnumOutputs **ppIVsEnumOutputs)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CMyProjectCfg::EnumOutputs this = 0x%x \n"), this);

    ExpectedPtrRet(ppIVsEnumOutputs);
    InitParam(ppIVsEnumOutputs);

    return CVsEnumOutputs::CreateInstance(
                static_cast<IVsProjectCfg2*>(this), 
                0, 
                ppIVsEnumOutputs);

}

STDMETHODIMP CMyProjectCfg::OpenOutput(
    /* [in]  */ LPCOLESTR szOutputCanonicalName,
    /* [out] */ IVsOutput **ppIVsOutput)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CMyProjectCfg::OpenOutput this = 0x%x \n"), this);
    
    ExpectedPtrRet(ppIVsOutput);
    InitParam(ppIVsOutput);
    
    return E_NOTIMPL;       // this forces caller to call thru IVsEnumOutputs
}

STDMETHODIMP CMyProjectCfg::get_BuildableProjectCfg(
    /* [out] */IVsBuildableProjectCfg **ppIVsBuildableProjectCfg)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_BuildableProjectCfg this = 0x%x \n"), this);
    
    if (!ppIVsBuildableProjectCfg)
        return E_INVALIDARG;
    *ppIVsBuildableProjectCfg = NULL;

    CComObject<CMyProjBuildableCfg> *pProjBuildableCfg;
    pProjBuildableCfg = new CComObject<CMyProjBuildableCfg>;
    if (!pProjBuildableCfg)
        return E_OUTOFMEMORY;
    HRESULT hr = pProjBuildableCfg->Init(this, m_pHier);
    if (FAILED(hr))
    {
        delete pProjBuildableCfg;
        return hr;
    }
    
    *ppIVsBuildableProjectCfg = (IVsBuildableProjectCfg *)pProjBuildableCfg;
    (*ppIVsBuildableProjectCfg)->AddRef();
    ASSERT(m_pHier->GetRootNode() != NULL);

    return S_OK;
}

STDMETHODIMP CMyProjectCfg::get_IsPackaged(/* [out] */ BOOL __RPC_FAR *pfIsPackaged)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_IsPackaged this = 0x%x \n"), this);
   ASSERT(pfIsPackaged != NULL);
   if (pfIsPackaged == NULL)
       return E_INVALIDARG;
   *pfIsPackaged = FALSE;
   return S_OK;
}
        
STDMETHODIMP CMyProjectCfg::get_RootURL(/* [out] */ BSTR *pbstrRootURL)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_RootURL this = 0x%x \n"), this);
    
    if (!pbstrRootURL)
        return E_POINTER;
    *pbstrRootURL = NULL;   // always initialize out params

    CString strRoot(_T("file:///")), strAbs;
    CFileVwProjNode *pProjNode = m_pHier->GetProjectNode();

    ASSERT(pProjNode->IsKindOf(Type_CFileVwProjNode));
    
    strAbs = pProjNode->GetFolderPath();

    strRoot += strAbs;
    *pbstrRootURL = strRoot.AllocSysString();

    return (*pbstrRootURL) ? S_OK : E_OUTOFMEMORY;
}


//
//                                                             IVsProjectCfg
// =========================================================================


// =========================================================================
//                                                   IVsDebuggableProjectCfg
//

HRESULT CMyProjectCfg::DebugLaunch( 
    /* [in] */ VSDBGLAUNCHFLAGS grfLaunch)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::DebugLaunch this = 0x%x \n"), this);

    // Get the debug launch targets
    HRESULT             hr = E_FAIL;

    m_grfLaunch = grfLaunch;
    ULONG numTargets = 1;
    VsDebugTargetInfo* pdti = NULL;
    VsDebugTargetInfo* pTarget = NULL;
    IVsDebugger* pDebugger = NULL;

    hr = SetDebugLaunchTgts();
    IfFailGo(hr);

    pDebugger = _VxModule.GetIVsDebugger();
    if (!pDebugger)
    {
        hr = E_FAIL;
        goto Error;
    }

    // Shallow copy the targets into an array on the stack and pass 
    // to the debugger
    pdti=(VsDebugTargetInfo*) malloc(numTargets * sizeof(VsDebugTargetInfo));

    if (pdti)
    {
        pTarget = pdti;
        *pTarget++ = *m_pTargetExe;
    
        #ifdef DEBUG
        for (ULONG i=0; i < numTargets; i++)
        {
            ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
                _T("DebugLaunch : exe='%s', arg='%s', curdir='%s'\n"),
                pdti[i].bstrExe, 
                pdti[i].bstrArg,
                pdti[i].bstrCurDir);
        }
        #endif
    
        hr = pDebugger->LaunchDebugTargets(numTargets, pdti);

    }
    else
    {
        hr = E_OUTOFMEMORY;
    }

Error:
    DeleteDebugLaunchTargets();

    if (pdti) free(pdti);

    // Convert cancel to abort
    if (hr == OLE_E_PROMPTSAVECANCELLED)
        hr = E_ABORT;
        
    return hr;
}

            
HRESULT CMyProjectCfg::QueryDebugLaunch(
    /* [in]  */  VSDBGLAUNCHFLAGS grfLaunch, 
    /* [out] */  BOOL __RPC_FAR *pfCanLaunch)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::QueryDebugLaunch this = 0x%x \n"), this);

    ExpectedPtrRet(pfCanLaunch);

    ULONG uCount;
    GetDebugLaunchTargetCount(0, &uCount);
    *pfCanLaunch = uCount > 0;
    return S_OK;
}


HRESULT CMyProjectCfg::SetDebugLaunchTgts()
{
    HRESULT hr = E_FAIL;

    DeleteDebugLaunchTargets();

    switch (m_enumMyCPrjDebugStartMode)
    {
        case MyCPrjDebugStartMode_Project:
        case MyCPrjDebugStartMode_Application:
            hr = SetExeLaunchTgts();
            break;

        default:
            ASSERT(FALSE);
            hr = E_UNEXPECTED;
    }

    return hr;
}


HRESULT CMyProjectCfg::SetExeLaunchTgts()
{
    HRESULT hr = S_OK;

    // Determine which target we're going to launch
    BOOL     fIsProject = (MyCPrjDebugStartMode_Project == m_enumMyCPrjDebugStartMode); 
    BOOL     fRemoteDeploy = FALSE;
    CComBSTR cbstrExe;
    CComBSTR cbstrRemoteMachine;
    if (fIsProject)
    {
        hr = IsDeploymentRemote(fRemoteDeploy, &cbstrExe, &cbstrRemoteMachine);
        // if the call fail try a local one
        if (FAILED(hr))
            fRemoteDeploy = FALSE;

        if (!fRemoteDeploy)
        {
            hr = get_OutputFile(&cbstrExe);
            IfFailRet(hr);
        }
    }
    else
    {
        hr = get_StartApp(&cbstrExe);
        IfFailRet(hr);
    }

    USES_CONVERSION;
    if (cbstrExe.Length()==0)
    {
        LUtilSetErrString1(IDS_E_DEBUGTARGETMISSING, W2T(cbstrExe));
        return E_FAIL;
    }

    WCHAR pwszFileExt[_MAX_EXT+1];
    _wsplitpath(cbstrExe,NULL,NULL,NULL, pwszFileExt);
    if (lstrcmpiW(pwszFileExt,L".exe") != 0)
    {
        LUtilSetErrString1(fIsProject ? IDS_E_DEBUGTARGETDLLPROJ : IDS_E_DEBUGTARGETNOTEXE, W2T(cbstrExe));
        return E_FAIL;
    }

    // if our target file does not exits, then return an error and tell the
    //  user that we can't find the launch target
    if (!fRemoteDeploy && !LUtilFileExists(W2T(cbstrExe)))
    {
        LUtilSetErrString1(IDS_E_DEBUGTARGETMISSING, W2T(cbstrExe));
        return E_FAIL;
    }    
    
    // assume memory failure -- we set it to success after we do all of our
    //  allocations.
    hr = E_OUTOFMEMORY;
    ASSERT(m_pTargetExe == NULL);
    m_pTargetExe = new CVsDebugTargetInfo;
    IfFailAllocGo(m_pTargetExe);

    if (fIsProject)
    {
        m_pTargetExe->dlo = DLO_Custom;
        m_pTargetExe->clsidCustom =  guidCOMPlusOnlyEng;
    }
    else
    {
        m_pTargetExe->dlo = DLO_CreateProcess;
        m_pTargetExe->clsidCustom = guidCOMPlusNativeEng;
    }

    // Exe
    m_pTargetExe->bstrExe = cbstrExe.Detach();

    if (fRemoteDeploy)
        m_pTargetExe->bstrRemoteMachine = cbstrRemoteMachine.Detach();

    // Args
    if (!m_strCustomStartupArguments.IsEmpty())
    {
        m_pTargetExe->bstrArg = m_strCustomStartupArguments.AllocSysString();
        IfFailAllocGo(m_pTargetExe->bstrArg);            
    }

    // Current directory
    if (!m_strStartAppPath.IsEmpty())
        m_pTargetExe->bstrCurDir = m_strStartAppPath.AllocSysString(); 
    else
        m_pTargetExe->bstrCurDir = m_pHier->GetProjectLocation().AllocSysString();
    IfFailAllocGo(m_pTargetExe->bstrCurDir);

    // Launch flags && std-out
    m_pTargetExe->grfLaunch = m_grfLaunch;
    m_pTargetExe->fSendStdoutToOutputWindow = TRUE;

    hr = S_OK;

Error:

    if (FAILED(hr))
    {
        // clean m_pTargetExe
        DeleteDebugLaunchTargets();
    }

    return hr;
}


HRESULT CMyProjectCfg::IsDeploymentRemote(
    /* [out] */ BOOL&    fRemoteDeploy, 
    /* [out] */ BSTR*    pbstrDebugTarget, 
    /* [out] */ BSTR*    pbstrDebugMachine)
{
    // Assume no remote deploy
    fRemoteDeploy = FALSE;

    ExpectedPtrRet(pbstrDebugTarget);
    InitParam(pbstrDebugTarget);
    ExpectedPtrRet(pbstrDebugMachine);
    InitParam(pbstrDebugMachine);

    HRESULT  hr = S_FALSE;

    CComPtr<IVsProjectCfg> srpIVsProjectCfg;
    hr = QueryInterface(IID_IVsProjectCfg, (void**)&srpIVsProjectCfg);
    IfFailRet(hr);

    CComPtr<IVsProjectCfg2> srpIVsProjectCfg2;
    hr = srpIVsProjectCfg->QueryInterface(IID_IVsProjectCfg2, (void**)&srpIVsProjectCfg2);
    IfFailRet(hr);

    CComPtr<IVsOutputGroup> srpIVsOutputGroup;
    hr = srpIVsProjectCfg2->OpenOutputGroup(VS_OUTPUTGROUP_CNAME_Built, &srpIVsOutputGroup);
    IfFailRet(hr);

    CComBSTR cbstrKeyOutput; 
    hr = srpIVsOutputGroup->get_KeyOutput(&cbstrKeyOutput);
    IfFailRet(hr);

    CComPtr<IVsSolutionDebuggingAssistant2> srpIVsSolutionDebuggingAssistant2;
    hr = _VxModule.QueryService(
        SID_SVsSolutionDebuggingAssistant2, 
        IID_IVsSolutionDebuggingAssistant2, 
        (void**)&srpIVsSolutionDebuggingAssistant2);
    if (FAILED(hr))
    {
        // The deployment service may not be available
        // hence no assert/failure if it doesn't exist
        // No debugging service, return S_FALSE;
        return S_FALSE;
    }
    ExpectedExprRet(srpIVsSolutionDebuggingAssistant2 != NULL);
 
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
        /*[in] IVsProjectCfg *pProjectCfg             */ srpIVsProjectCfg, 
        /*[in] LPCOLESTR pszOutputCanonicalName       */ cbstrKeyOutput,
        /*[in] ULONG celt                             */ 1,
        /*[in,out,size_is(celt)] BSTR rgbstrMachines[]*/ pbstrDebugMachine,
        /*[in,out,size_is(celt)] BSTR rgbstrURLs[]    */ &cbstrURL,
        /*[out] ULONG *pcActual                       */ &ulNoOfTargets);

    if ( SUCCEEDED(hr) && (ulNoOfTargets > 0) )
    {
        fRemoteDeploy = TRUE;

        CString strDebugTarget = cbstrURL;
        strDebugTarget.MakeLower();
        strDebugTarget.Replace(_T("file:///"), NULL);     // removing the "file:///" part.

        *pbstrDebugTarget = strDebugTarget.AllocSysString();
        if (!*pbstrDebugTarget) return E_OUTOFMEMORY;
    }

    return hr;
}


void CMyProjectCfg::DeleteDebugLaunchTargets()
{
    if (m_pTargetExe)
    {
        delete m_pTargetExe;
        m_pTargetExe = NULL;
    }
}


//---------------------------------------------------------------------------
// helper function for IVsDebuggableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::GetDebugLaunchTargetCount(
    /* [in] */  int     iConfig, 
    /* [out]*/  ULONG * puCount)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::GetDebugLaunchTargetCount this = 0x%x \n"), this);

    ExpectedPtrRet(puCount);
    *puCount = 1;
    return S_OK;    
}

//
//                                                   IVsDebuggableProjectCfg
// =========================================================================


// =========================================================================
//                                                     ISpecifyPropertyPages
HRESULT CMyProjectCfg::GetPages(CAUUID *pPages)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  _T(": CMyProjectCfg::GetPages this = 0x%x \n"), this);
    ExpectedPtrRet(pPages);

    pPages->cElems = 2;
    pPages->pElems = (GUID*)CoTaskMemAlloc(pPages->cElems*sizeof(GUID));
    if (!pPages->pElems)
        return E_OUTOFMEMORY;

    pPages->pElems[0] = CLSID_BuildPPG;
    pPages->pElems[1] = CLSID_DebugPPG;
    return S_OK;
}
//                                                     ISpecifyPropertyPages
// =========================================================================


// =========================================================================
//                                                            IVsProjectCfg2
    
// -------------------------------------------------------------------------
//                                                  IVsProjectCfg2 interface
//

STDMETHODIMP CMyProjectCfg::get_CfgType(
    /* [in] */                  REFIID iidCfg, 
    /* [out, iid_is(iidCfg)] */ void** ppCfg)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::get_CfgType /IVsProjectCfg2/ this = 0x%x \n"), this);

    ExpectedPtrRet(ppCfg);
    *ppCfg = NULL;

    HRESULT hr = S_OK;

    if (iidCfg == IID_IVsBuildableProjectCfg)
        return get_BuildableProjectCfg((IVsBuildableProjectCfg **) ppCfg);
    else if (iidCfg == IID_IVsDebuggableProjectCfg)
        return QueryInterface(IID_IVsDebuggableProjectCfg,ppCfg);
    else
        hr = E_FAIL;

    return hr;
}


STDMETHODIMP CMyProjectCfg::get_OutputGroups(
    /* [in]                     */ ULONG celt,
    /* [in, out, size_is(celt)] */ IVsOutputGroup *rgpIVsOutputGroup[],
    /* [out, optional]          */ ULONG *pcActual)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::get_OutputGroups /IVsProjectCfg2/ this = 0x%x \n"), this);

    USHORT i = 0;
    USHORT cGroups = GetOutputGroupsCount();

    if( celt == 0 )
    {
        ExpectedPtrRet(pcActual);
        *pcActual = cGroups;
        return S_OK;
    }

    ExpectedPtrRet(rgpIVsOutputGroup);

    HRESULT hr = S_OK;
    for (i = 0; i < celt; i++)
    {
        rgpIVsOutputGroup[i] = NULL;
    }

    CComQIPtr<IVsProjectCfg2> srpIVsProjectCfg2 = this;

    for (i = 0; i < celt && i < cGroups; i++)
    {
        hr = CVsOutputGroup::CreateInstance(
            srpIVsProjectCfg2,
            m_rgogt[i], 
            &rgpIVsOutputGroup[i]);
        IfFailGo(hr);
    }

Error:
    if (FAILED(hr))
    {
        for (USHORT j = 0; j < i; j++)
        {
            if(rgpIVsOutputGroup[j])
            {
                rgpIVsOutputGroup[j]->Release();
                rgpIVsOutputGroup[j]=NULL;
            }
        }
        i = 0;
    } 
    else
    {
        hr = (celt == i) ? S_OK : S_FALSE;
    }

    if (pcActual)
        *pcActual = i;
    
    return hr;
}


STDMETHODIMP CMyProjectCfg::OpenOutputGroup(
    /* [in]  */ LPCOLESTR szCanonicalName,
    /* [out] */ IVsOutputGroup **ppIVsOutputGroup)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::OpenOutputGroup /IVsProjectCfg2/ this = 0x%x \n"), this);

    ExpectedPtrRet(szCanonicalName);
    ExpectedPtrRet(ppIVsOutputGroup);
    InitParam(ppIVsOutputGroup);

    HRESULT hr = E_UNEXPECTED;
    USHORT  cGroups = GetOutputGroupsCount();
    CComBSTR cbstrCanonicalName;
    CComQIPtr<IVsProjectCfg2> srpIVsProjectCfg2 = this;

   
    for (USHORT i = 0; i < cGroups; i++)
    {
        hr = CVsOutputGroup::GetCanonicalNameFromOgt(m_rgogt[i], &cbstrCanonicalName);
        if (FAILED(hr))
            break;

        if (wcscmp(cbstrCanonicalName,szCanonicalName) == 0)
        {
            // this is the group the caller wants - create it
            hr = CVsOutputGroup::CreateInstance(
                srpIVsProjectCfg2,
                m_rgogt[i], 
                ppIVsOutputGroup);
            break;
        }
        cbstrCanonicalName.Empty();
    }

    return hr;
}


STDMETHODIMP CMyProjectCfg::OutputsRequireAppRoot(
    /* [out] */ BOOL *pfRequiresAppRoot)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::OutputsRequireAppRoot /IVsProjectCfg2/ this = 0x%x \n"), this);

    ExpectedPtrRet(pfRequiresAppRoot);
    *pfRequiresAppRoot = FALSE;
    return E_NOTIMPL;
}

    
STDMETHODIMP CMyProjectCfg::get_VirtualRoot(
    /* [out] */ BSTR *pbstrVRoot)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::get_VirtualRoot /IVsProjectCfg2/ this = 0x%x \n"), this);

    ExpectedPtrRet(pbstrVRoot);
    InitParam(pbstrVRoot);
    return E_NOTIMPL;
}


STDMETHODIMP CMyProjectCfg::get_IsPrivate(
    /* [out] */ BOOL *pfPrivate)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::get_IsPrivate /IVsProjectCfg2/ this = 0x%x \n"), this);

    ExpectedPtrRet(pfPrivate);
    *pfPrivate = FALSE;
    return S_OK;
}

//
//                                                  IVsProjectCfg2 interface
// -------------------------------------------------------------------------

// -------------------------------------------------------------------------
//                                                    IVsProjectCfg2 helpers

USHORT CMyProjectCfg::GetOutputGroupsCount()
{
    return (USHORT) NUMBER_OF(m_rgogt);
};


STDMETHODIMP CMyProjectCfg::get_OgtKeyOutput(
    /* [in]  */ OUTPUTGROUPTYPE  ogt,
    /* [out] */ BSTR*            pbstrCanonicalName)
{
    ExpectedPtrRet(pbstrCanonicalName);
    InitParam(pbstrCanonicalName);

    HRESULT hr = S_OK;
    switch(ogt)
    {
        case OGT_Built :
            hr = get_OutputFile(pbstrCanonicalName);
            IfFailRet(hr);
            if (SysStringLen(*pbstrCanonicalName) == 0)
            {
                // return something - we will have an output file at the time
                // of the build
                *pbstrCanonicalName =  ::SysAllocString(L"Output File");
            }
            break;
        case OGT_SourceFiles:
            *pbstrCanonicalName =  ::SysAllocString(L"");
            break;
        default:
            ASSERT(FALSE);
            hr = E_FAIL;
            break;
    }
    return (*pbstrCanonicalName) ? S_OK : E_OUTOFMEMORY;

}


STDMETHODIMP CMyProjectCfg::AddOgtOutputsToArray(
    /* [in]      */  OUTPUTGROUPTYPE ogt,
    /* [in, out] */  IVsOutput2Array* prgpIVsOutput2)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::AddOutputsToArray \n"));
    ExpectedPtrRet(prgpIVsOutput2);

    HRESULT hr = S_OK;
    switch(ogt)
    {
        case OGT_Built :
            return AddBuiltOutputsToArray(prgpIVsOutput2);
        case OGT_SourceFiles:
            return AddSourceFilesOutputsToArray(prgpIVsOutput2);
        default:
            ASSERT(FALSE);
            return E_FAIL;
    }
    return hr;
}


STDMETHODIMP CMyProjectCfg::AddAllOutputsToArray(
    /* [in, out] */  IVsOutput2Array* prgpIVsOutput2)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::AddAllOutputsToArray \n"));
    ExpectedPtrRet(prgpIVsOutput2);

    HRESULT hr = S_OK;

    hr = AddOgtOutputsToArray(
                            OGT_Built,
                            prgpIVsOutput2);
    IfFailRet(hr);

    hr = AddOgtOutputsToArray(
                            OGT_SourceFiles,
                            prgpIVsOutput2);
    IfFailRet(hr);

    // if there are outputs that are not in the output groups - add them

    return hr;
}


STDMETHODIMP CMyProjectCfg::AddBuiltOutputsToArray(
    /* [in,out] */  IVsOutput2Array* prgpIVsOutput2)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::AddBuiltOutputsToArray \n"));
    ExpectedPtrRet(prgpIVsOutput2);

    HRESULT hr = S_OK;
    CComBSTR cbstrOutputFile;

    // Obtain project output file
    hr = get_OutputFile(&cbstrOutputFile);
    IfFailRet(hr);

    CComPtr<IVsOutput2> srpIVsOutput2;
    CString strAbsPath = cbstrOutputFile;
    if (strAbsPath.IsEmpty()) // do not add it
        return S_OK;

    hr = CVsOutput::CreateInstance(
            static_cast<IVsProjectCfg2*>(this), 
            strAbsPath, 
            &srpIVsOutput2);
    IfFailRet(hr);

    prgpIVsOutput2->Add(srpIVsOutput2.Detach());
    return hr;
}


STDMETHODIMP CMyProjectCfg::AddSourceFilesOutputsToArray(
    /* [in, out] */  IVsOutput2Array* prgpIVsOutput2)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::AddSourceFilesOutputsToArray \n"));
    ExpectedPtrRet(prgpIVsOutput2);

    HRESULT hr = S_OK;
    CComBSTR cbstrSourceFile;

    // Currently only one source file is compiled in the MyCPrj project
    // so only this file is listed as a source rather than enumerating 
    // all source files in the project.

    // Obtain the project source file
    hr = get_SourceFile(&cbstrSourceFile);
    IfFailRet(hr);

    CComPtr<IVsOutput2> srpIVsOutput2;
    CString strAbsPath = cbstrSourceFile;
    if (strAbsPath.IsEmpty())
        return S_OK;

    hr = CVsOutput::CreateInstance(
            static_cast<IVsProjectCfg2*>(this), 
            strAbsPath, 
            &srpIVsOutput2);
    IfFailRet(hr);

    prgpIVsOutput2->Add(srpIVsOutput2.Detach());
    return hr;
}



//                                                    IVsProjectCfg2 helpers
// -------------------------------------------------------------------------

//                                                            IVsProjectCfg2
// =========================================================================



// =========================================================================
//                                                          IMyCProjCfgProps
//

//--------------------------------------------------------------------------
//[propget, helpstring("")] HRESULT SourceFile([out, retval] BSTR * pbstr);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::get_SourceFile( /* [out] */ BSTR *pbstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_SourceFile this = 0x%x \n"), this);

    ExpectedPtrRet(pbstr);
    *pbstr = NULL;

    CComBSTR cbstrSourceFile;
    HRESULT hr = GetProperty(m_strSourceFile, &cbstrSourceFile);
    IfFailRet(hr);
    
    // if the source file is not set, 
    // get the first myc file in the project
    if (!cbstrSourceFile.Length())
    {
        CFileVwProjNode* pProject;
        pProject = m_pHier->GetProjectNode(); //unaddref-ed
        ExpectedExprRet(pProject != NULL);

        CFileVwBaseNode* pNode = (CFileVwBaseNode *) pProject->GetHeadEx();
        for (; pNode != NULL; pNode = (CFileVwBaseNode *)pNode->GetNext())
        {

            CString strExt = LUtilGetExtension(pNode->GetFullPath());
            if (strExt.CompareNoCase(_T(".myc")) == 0)
            {   
                // we found a myc file - return it
                cbstrSourceFile = pNode->GetFullPath();
                break;
            }
        }

    }

    *pbstr = cbstrSourceFile.Detach();
    return S_OK;
}

//--------------------------------------------------------------------------
//[propput, helpstring("")] HRESULT SourceFile([in] BSTR bstr);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::put_SourceFile( /* [in] */ BSTR bstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::put_SourceFile this = 0x%x \n"), this);
    return PutProperty(bstr, /*fMustRebuild*/ TRUE, m_strSourceFile);
}

//--------------------------------------------------------------------------
//[propget, helpstring("")] HRESULT ProjectType([out, retval] BSTR *pbstr);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::get_ProjectType(/* [out] */ BSTR *pbstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_ProjectType this = 0x%x \n"), this);
   return GetProperty(m_strProjectType,pbstr);
}

//--------------------------------------------------------------------------
//[propput, helpstring("")] HRESULT ProjectType([in] BSTR bstr);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::put_ProjectType(/* [in] */ BSTR bstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::put_ProjectType this = 0x%x \n"), this);
    if (!bstr || ( (_wcsicmp(bstr, L"EXE") != 0) && (_wcsicmp(bstr, L"DLL") != 0)))
        return E_INVALIDARG;
    return PutProperty(bstr, /*fMustRebuild*/ TRUE, m_strProjectType);
}

//--------------------------------------------------------------------------
//[propget, helpstring("")] HRESULT OutputPath([out, retval] BSTR *pbstr);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::get_OutputPath(/* [out] */ BSTR *pbstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_OutputPath this = 0x%x \n"), this);
    return GetProperty(m_strOutputPath,pbstr);
}

//--------------------------------------------------------------------------
//[propput, helpstring("")] HRESULT OutputPath([in] BSTR bstr);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::put_OutputPath(/* [in] */ BSTR bstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::put_OutputPath this = 0x%x \n"), this);
    return PutProperty(bstr, /*fMustRebuild*/ TRUE, m_strOutputPath);
}

//--------------------------------------------------------------------------
//[propget, helpstring("")] HRESULT DebugInfoChecked([out, retval] VARIANT_BOOL * pvb);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::get_DebugInfoChecked(/* [out] */ VARIANT_BOOL * pvb)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_DebugInfoChecked this = 0x%x \n"), this);
    return GetProperty(m_vbDebugInfoChecked,pvb);
}

//--------------------------------------------------------------------------
//[propput, helpstring("")] HRESULT DebugInfoChecked([in] VARIANT_BOOL vb);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::put_DebugInfoChecked(/*[in]*/ VARIANT_BOOL vb)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::put_DebugInfoChecked this = 0x%x \n"), this);
    return PutProperty(vb, /*fMustRebuild*/ TRUE, m_vbDebugInfoChecked);
}

//--------------------------------------------------------------------------
//[propget, helpstring("")] HRESULT ListingFileChecked([out, retval] VARIANT_BOOL *pvb);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::get_ListingFileChecked(/* [out] */ VARIANT_BOOL * pvb)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_ListingFileChecked this = 0x%x \n"), this);
    return GetProperty(m_vbListingFileChecked,pvb);
}

//--------------------------------------------------------------------------
//[propput, helpstring("")] HRESULT ListingFileChecked(/*[in]*/ VARIANT_BOOL vb);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::put_ListingFileChecked(/*[in]*/ VARIANT_BOOL vb)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::put_ListingFileChecked this = 0x%x \n"), this);
    return PutProperty(vb, /*fMustRebuild*/ TRUE, m_vbListingFileChecked);
}


//--------------------------------------------------------------------------
//[propget, helpstring("")] HRESULT CommandLine([out, retval] BSTR *pVal);
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::get_CommandLine(/* [out] */ BSTR *pbstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_CommandLine this = 0x%x \n"), this);

    ExpectedPtrRet(pbstr);

    CString strBuildCommandLine;
    CString strTemp;

    // project type
    strTemp = m_strProjectType;
    strTemp.MakeLower();
    if (! strTemp.IsEmpty())
    {
        strBuildCommandLine += _T(" /");
        strBuildCommandLine += strTemp;
    }

    // debug info
    if (m_vbDebugInfoChecked == VARIANT_TRUE)
        strTemp = _T(" /debug");
    else 
        strTemp = _T(" /nodebug");
    strBuildCommandLine += strTemp;


    // listing info
    if (m_vbListingFileChecked == VARIANT_TRUE)
        strTemp = _T(" /list");
    else 
        strTemp = _T("");
    strBuildCommandLine += strTemp;

    // output path
    if (! m_strOutputPath.IsEmpty())
    {
        strBuildCommandLine += _T(" /outdir:\"");
        strBuildCommandLine += m_strOutputPath;
        strBuildCommandLine += _T("\"");
    }

    // source file
    CComBSTR cbstrSourceFile;
    HRESULT hr = get_SourceFile(&cbstrSourceFile);
    IfFailRet(hr);
    strTemp = cbstrSourceFile;
    if (!strTemp.IsEmpty())
    {
        strBuildCommandLine += _T(" \"");
        strBuildCommandLine += strTemp;
        strBuildCommandLine += _T("\"");
    }

    *pbstr = strBuildCommandLine.AllocSysString();
    return (*pbstr) ? S_OK : E_OUTOFMEMORY;

}


HRESULT CMyProjectCfg::get_OutputFile
(
    /* [out, retval] */ BSTR *pbstr    
)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_OutputFile this = 0x%x \n"), this);
    ExpectedPtrRet(pbstr);

    CString strOutputFile;
    CComBSTR cbstrSourceFile;
    HRESULT hr = get_SourceFile(&cbstrSourceFile);
    IfFailRet(hr);
    CString strSourceFile = cbstrSourceFile;
    if (! strSourceFile.IsEmpty() && !m_strProjectType.IsEmpty())
    {
        // get the filename
        TCHAR pszSrcFileBaseName[_MAX_FNAME + 1];
        _tsplitpath(strSourceFile,NULL,NULL,pszSrcFileBaseName, NULL);
        strOutputFile = pszSrcFileBaseName;
        strOutputFile += _T(".");
        strOutputFile = strOutputFile + m_strProjectType;

        CString strProjectFolder = m_pHier->GetProjectNode()->GetFolderPath();
        CString strAbsOutputPath;

        if (! m_strOutputPath.IsEmpty() )
            if (LUtilIsAbsolutePath(m_strOutputPath))
                strAbsOutputPath = m_strOutputPath;
            else
                if (!LUtilConcatPaths(strProjectFolder, m_strOutputPath, strAbsOutputPath))
                    return E_FAIL;

        if (strAbsOutputPath.IsEmpty())
            strAbsOutputPath = strProjectFolder;

        if (LUtilHaveTrailingTChar(strAbsOutputPath, _T('\\')))
            strOutputFile = strAbsOutputPath+strOutputFile;
        else
            strOutputFile = strAbsOutputPath+_T("\\")+strOutputFile;
    }

    strOutputFile.MakeLower();
    *pbstr = strOutputFile.AllocSysString();
    return (*pbstr) ? S_OK : E_OUTOFMEMORY;
}

HRESULT CMyProjectCfg::get_DebugStartMode(
    /* [out] */ MyCPrjDebugStartMode *pdebugStartMode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_DebugStartMode this = 0x%x \n"), this);

    ExpectedPtrRet(pdebugStartMode);
    *pdebugStartMode = m_enumMyCPrjDebugStartMode;
    return S_OK;
}

HRESULT CMyProjectCfg::put_DebugStartMode(
    /* [in]  */ MyCPrjDebugStartMode debugStartMode)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::put_DebugStartMode this = 0x%x \n"), this);

    if ( (debugStartMode < MyCPrjDebugStartModeMin) || (debugStartMode > MyCPrjDebugStartModeMax) )
        return E_INVALIDARG;

    ExpectedExprRet(m_pHier);
    if(!m_pHier->QueryEditProjectFile())
        return OLE_E_PROMPTSAVECANCELLED;

    m_enumMyCPrjDebugStartMode = debugStartMode;
    SetProjectFileDirty(TRUE);
    return S_OK;
}


HRESULT CMyProjectCfg::get_StartApp(/* [out] */ BSTR *pbstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_StartApp this = 0x%x \n"), this);
    return GetProperty(m_strStartApp,pbstr);
}

HRESULT CMyProjectCfg::put_StartApp(/* [in] */ BSTR bstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::put_StartApp this = 0x%x \n"), this);
    return PutProperty(bstr, /*fMustRebuild*/ FALSE, m_strStartApp);
}

HRESULT CMyProjectCfg::get_StartAppPath(/* [out] */ BSTR *pbstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_StartAppPath this = 0x%x \n"), this);
    return GetProperty(m_strStartAppPath,pbstr);
}

HRESULT CMyProjectCfg::put_StartAppPath(/* [in] */ BSTR bstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::put_StartAppPath this = 0x%x \n"), this);
    return PutProperty(bstr, /*fMustRebuild*/ FALSE, m_strStartAppPath);
}
       
HRESULT CMyProjectCfg::get_CustomStartupArguments(/* [out] */ BSTR *pbstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::get_CustomStartupArguments this = 0x%x \n"), this);
    return GetProperty(m_strCustomStartupArguments,pbstr);
}

HRESULT CMyProjectCfg::put_CustomStartupArguments(/* [in] */ BSTR bstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::put_CustomStartupArguments this = 0x%x \n"), this);
    return PutProperty(bstr, /*fMustRebuild*/ FALSE, m_strCustomStartupArguments);
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

    CComBSTR cbstrCATID(prjCATIDMyCPrjProjectConfigBrowseObject);
    if (cbstrCATID.Length() == 0)
        return E_OUTOFMEMORY;

    *pbstrRetval = cbstrCATID.Detach();
    return S_OK;
}


//--------------------------------------------------------------------------
//Generic GetProperty functions
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::GetProperty
(
    /* [in ] */ const CString& str,     // string to copy from
    /* [out] */       BSTR *   pbstr   // bstr to copy to
)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::GetProperty this = 0x%x \n"), this);
    ExpectedPtrRet(pbstr);
    *pbstr = str.AllocSysString();
    return (*pbstr) ? S_OK : E_OUTOFMEMORY;
}

HRESULT CMyProjectCfg::GetProperty
(
    /* [in ] */ VARIANT_BOOL   vb,     // copy from
    /* [out] */ VARIANT_BOOL * pvb    // copy to
)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::GetProperty this = 0x%x \n"), this);
    ExpectedPtrRet(pvb);
    *pvb = vb;
    return S_OK;
}

//--------------------------------------------------------------------------
//Generic PutProperty functions
//--------------------------------------------------------------------------
HRESULT CMyProjectCfg::PutProperty(
    /* [in]  */ BSTR     bstr,          // bstr to copy from
    /* [in]  */ BOOL     fMustRebuild,  // must rebuild flag
    /* [out] */ CString& str)           // string to copy to
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::PutProperty this = 0x%x \n"), this);

    ExpectedExprRet(m_pHier);
    if(!m_pHier->QueryEditProjectFile())
        return OLE_E_PROMPTSAVECANCELLED;

    str = CString(bstr); 
    // set the dirty state
    SetProjectFileDirty(TRUE);
    if (fMustRebuild)
        m_fMustRebuild = TRUE;
    return S_OK;
}

HRESULT CMyProjectCfg::PutProperty(
    /* [in]  */ VARIANT_BOOL   vbFrom,          // copy from
    /* [in]  */ BOOL           fMustRebuild,    // must rebuild flag
    /* [out] */ VARIANT_BOOL&  vbTo)            // string to copy to
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
         _T(": CMyProjectCfg::PutProperty this = 0x%x \n"), this);

    ExpectedExprRet(m_pHier);
    if(!m_pHier->QueryEditProjectFile())
        return OLE_E_PROMPTSAVECANCELLED;

    vbTo = vbFrom;
    // set the dirty state
    SetProjectFileDirty(TRUE);
    if (fMustRebuild)
        m_fMustRebuild = TRUE;
    return S_OK;
}

//                                                          IMyCProjCfgProps
// =========================================================================

// =========================================================================
//                                                                     BUILD

class CLaunchPadEvents : 
    public IVsLaunchPadEvents,
    public CComObjectRoot
{
    BEGIN_COM_MAP(CLaunchPadEvents)
      COM_INTERFACE_ENTRY(IVsLaunchPadEvents)
    END_COM_MAP()

    // IVsLaunchPadEvents
    virtual HRESULT STDMETHODCALLTYPE Tick(
        /* [out] */ BOOL __RPC_FAR * pfCancel);

public:
    CMyProjBuildableCfg::CBuilderThread *m_pBuilder;
};


STDMETHODIMP CLaunchPadEvents::Tick( 
    /* [out] */ BOOL __RPC_FAR * pfCancel)
{
    ExpectedPtrRet(pfCancel);
    *pfCancel = FALSE;    

    BOOL fContinue = TRUE;
    ExpectedExprRet(m_pBuilder);
    m_pBuilder->Fire_Tick(fContinue);
    if (!fContinue)
    {
      *pfCancel = TRUE;
    }
    
    return S_OK;
};


HRESULT CMyProjBuildableCfg::Init(CMyProjectCfg *pProjectCfg, CMyProjectHierarchy *pHier)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CMyProjBuildableCfg::Init this = 0x%x \n"), this);
    ExpectedPtrRet(pProjectCfg);
    ExpectedPtrRet(pHier);
    m_pProjectCfg = pProjectCfg;
    m_pHier = pHier;
    ((IVsHierarchy*)(m_pHier->GetIVsHierarchy()))->AddRef();

    ASSERT(m_pHier->GetRootNode() != NULL);
    ExpectedExprRet(m_pHier->GetRootNode());
    if (m_pHier->GetRootNode() != NULL)
    {
        cbstrProjectName = pHier->GetRootNode()->GetName();
        cbstrProjectDir = m_pHier->GetProjectNode()->GetFolderPath();
    }

    HRESULT hr = m_pProjectCfg->get_CommandLine(&cbstrCommandLine);
    ASSERT(SUCCEEDED(hr));
    IfFailRet(hr);
    hr = m_pProjectCfg->get_SourceFile(&cbstrSourceFile);
    ASSERT(SUCCEEDED(hr));
    IfFailRet(hr);
    hr = m_pProjectCfg->get_ProjectType(&cbstrProjectType);
    ASSERT(SUCCEEDED(hr));
    IfFailRet(hr);
    return hr;
}

// tick the sink and check if build can continue or not.
BOOL CMyProjBuildableCfg::FFireTick()
{
    BOOL fContinue = TRUE;
    CVsAdviseListEnumerator<IVsBuildStatusCallback> adviseEnum(&m_alIVsBuildStatusCallback);
    for (IVsBuildStatusCallback* pSink = adviseEnum.GetFirst();  pSink != NULL; pSink = adviseEnum.GetNext())
    {
            HRESULT hr = pSink->Tick(&fContinue);
            ASSERT(SUCCEEDED(hr));
            if (SUCCEEDED(hr) && !fContinue)
                return FALSE;
    }
    return TRUE;
}


BSTR CMyProjBuildableCfg::GetProjectName()
{
    return cbstrProjectName;
}
BSTR CMyProjBuildableCfg::GetCommandLine()
{
    return cbstrCommandLine;
}
BSTR CMyProjBuildableCfg::GetProjectDir()
{
    return cbstrProjectDir;
}
BSTR CMyProjBuildableCfg::GetSourceFile()
{
    return cbstrSourceFile;
}
BSTR CMyProjBuildableCfg::GetProjectType()
{
    return cbstrProjectType;
}

void CMyProjBuildableCfg::SetThread(HANDLE hThread)
{
    ASSERT(m_pHier != NULL);
    if (m_pHier == NULL)
        return;

    m_pHier->m_hThreadBuild = hThread;
}

BOOL CMyProjBuildableCfg::Busy()
{
    ASSERT(m_pHier != NULL);
    if (m_pHier == NULL)
        return FALSE;

    return (m_pHier->m_hThreadBuild != NULL);
}


// initialize callbacks, etc.
CMyProjBuildableCfg::CMyProjBuildableCfg()
{
#ifdef DEBUG
    m_dwBuilderThreadId = ::GetCurrentThreadId();
#endif // DEBUG
}


CMyProjBuildableCfg::~CMyProjBuildableCfg()
{
    if (m_thread.m_hThread != NULL)
        SetThread(NULL);

    if (m_pHier)
    {
        ((IVsHierarchy*)(m_pHier->GetIVsHierarchy()))->Release();
    }
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjBuildableCfg::get_ProjectCfg(
    /* [out] */ IVsProjectCfg ** ppIVsProjectCfg)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjBuildableCfg::get_ProjectCfg this = 0x%x \n"), this);

    // Validate
    ExpectedPtrRet(ppIVsProjectCfg);
    InitParam(ppIVsProjectCfg);
    ExpectedExprRet(m_pProjectCfg != NULL);
    *ppIVsProjectCfg = static_cast<IVsDebuggableProjectCfg*> (m_pProjectCfg);
    (*ppIVsProjectCfg)->AddRef();

    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjBuildableCfg::AdviseBuildStatusCallback(
    /* [in] */ IVsBuildStatusCallback *    pIVsBuildStatusCallback,
    /* [out] */VSCOOKIE *                  pdwCookie)
{
    if (pdwCookie == NULL)
        return E_POINTER;

    if (NULL == pIVsBuildStatusCallback)
        return E_INVALIDARG;

    // Do not addref pIVsBuildStatusCallback because SetAdvise() does so automatically
    return m_alIVsBuildStatusCallback.SetAdvise(pIVsBuildStatusCallback, pdwCookie);

}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjBuildableCfg::UnadviseBuildStatusCallback(
    /* [in] */ VSCOOKIE dwCookie)
{
    // Do not release IVsBuildableProjectCfg because Unadvise() does so automatically
    return m_alIVsBuildStatusCallback.UnAdvise(dwCookie);
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjBuildableCfg::QueryStartBuild(
    /* [in]            */ DWORD  dwOptions,
    /* [out, optional] */ BOOL * pfSupported, 
    /* [out, optional] */ BOOL * pfEnabled)
{
    if (NULL == pfSupported || NULL == pfEnabled)
        return E_POINTER;
    *pfSupported = *pfEnabled = TRUE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjBuildableCfg::QueryStartClean(
    /* [in]            */ DWORD  dwOptions,
    /* [out, optional] */ BOOL * pfSupported, 
    /* [out, optional] */ BOOL * pfEnabled)
{
    if (NULL == pfSupported || NULL == pfEnabled)
        return E_POINTER;
    *pfSupported = *pfEnabled = TRUE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjBuildableCfg::QueryStartUpToDateCheck(
    /* [in]            */ DWORD  dwOptions,
    /* [out, optional] */ BOOL * pfSupported, 
    /* [out, optional] */ BOOL * pfEnabled)
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
HRESULT CMyProjBuildableCfg::StartBuild(
    /* [in] */IVsOutputWindowPane * pIVsOutputWindowPane,
    /* [in] */DWORD                 dwOptions)
{
    if (Busy())
        return VS_E_BUSY;

    ExpectedPtrRet(pIVsOutputWindowPane);
    if (!(dwOptions & VS_BUILDABLEPROJECTCFGOPTS_REBUILD))
    {
        // check for up-to-date
        BOOL fIsUpToDate = FALSE;
        HRESULT hr = IsBuildUpToDate(&fIsUpToDate);
        if (SUCCEEDED(hr) && fIsUpToDate)
        {
            if (FireBuildBegin())
            {
                   CString strUpToDate;
                strUpToDate.LoadString(IDS_UPTODATE);
                ASSERT(!strUpToDate.IsEmpty());
                pIVsOutputWindowPane->OutputString(T2COLE(strUpToDate));
                   FireBuildEnd(TRUE);
            }
            return S_OK;
        }
    }
    
    m_fStopBuild = FALSE;
    m_pIVsOutputWindowPane = pIVsOutputWindowPane;

    _VxModule.QueryService(SID_SVsStatusbar, IID_IVsStatusbar, (void **)&m_pIVsStatusbar);
    // Note that the QueryService for SID_SVsStatusbar will fail during command line build

    // advise for build events so we know if the build succeeded
    VSCOOKIE vscookie = VSCOOKIE_NIL;
    HRESULT hr = AdviseBuildStatusCallback(
        /* [in] IVsBuildStatusCallback * */  static_cast<IVsBuildStatusCallback*>(this),
        /* [out] VSCOOKIE *              */  &vscookie);
    IfFailRet(hr);
    
    hr = m_thread.Start(this, CBuilderThread::eBuild);
    
    if (vscookie != VSCOOKIE_NIL)
    {
        HRESULT hrTemp = UnadviseBuildStatusCallback(/* [in]  VSCOOKIE */ vscookie);
        ASSERT(SUCCEEDED(hrTemp));
    }
    IfFailRet(hr);

    SetThread(m_thread.m_hThread);
    return hr;
}

// *** IVsBuildStatusCallback methods ***
STDMETHODIMP CMyProjBuildableCfg::BuildBegin(BOOL *pfContinue)
{
    // clear the "MustRebuild" flag in the project cfg
    // do not forget to set it to TRUE if the build fail
    m_pProjectCfg->MustRebuild() = FALSE;
    return S_OK;
}


STDMETHODIMP CMyProjBuildableCfg::BuildEnd(BOOL fSuccess)
{
    if (!fSuccess)
        m_pProjectCfg->MustRebuild() = TRUE;
    return S_OK;
}


STDMETHODIMP CMyProjBuildableCfg::Tick(BOOL *pfContinue)
{
    // check if the build is stopped
    if (pfContinue)
        *pfContinue = !m_fStopBuild;
    return S_OK;
}


//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjBuildableCfg:: StartClean(
    /* [in] */IVsOutputWindowPane * pIVsOutputWindowPane,
    /* [in] */DWORD                 dwOptions)
{
    if (Busy())
        return VS_E_BUSY;
        
    ExpectedPtrRet(pIVsOutputWindowPane);
    m_fStopBuild = FALSE;
    m_pIVsOutputWindowPane = pIVsOutputWindowPane;

    _VxModule.QueryService(SID_SVsStatusbar, IID_IVsStatusbar, (void **)&m_pIVsStatusbar);
    // Note that the QueryService for SID_SVsStatusbar will fail during command line build

    HRESULT hr = m_thread.Start(this, CBuilderThread::eClean);

    SetThread(m_thread.m_hThread);
    return hr;
}


STDMETHODIMP CMyProjBuildableCfg::IsBuildUpToDate(
    /* [out] */ BOOL* pfIsBuildUpToDate)
{
    ExpectedPtrRet(pfIsBuildUpToDate);
    *pfIsBuildUpToDate = FALSE;
    HRESULT hr = S_OK;

    // first check whether we must rebuild 
    if (m_pProjectCfg->MustRebuild())
        return S_OK;

    // now check the built files
    ExpectedExprRet(m_pProjectCfg != NULL);

    // get the source file
    CComBSTR cbstrSourceFile;
    hr = m_pProjectCfg->get_SourceFile(&cbstrSourceFile);
    IfFailRet(hr);
    if (cbstrSourceFile.Length() == 0)
    {
        // no file -> no build
        *pfIsBuildUpToDate = TRUE;
        return S_OK;
    }

    CComBSTR cbstrOutputFile;
    hr = m_pProjectCfg->get_OutputFile(&cbstrOutputFile);
    IfFailRet(hr);

    // now compare the times
    FILETIME ftSource;
    FILETIME ftDest;
    if ( LUtilGetFileTime(W2CT(cbstrSourceFile), &ftSource) &&
         LUtilGetFileTime(W2CT(cbstrOutputFile), &ftDest)) 
        {
            *pfIsBuildUpToDate = (CompareFileTime(&ftSource, &ftDest) <= 0);
        }

    return S_OK;
}


// advise the sink that the build has begun.
BOOL CMyProjBuildableCfg::FireBuildBegin()
{
    BOOL fContinue = TRUE;
    HRESULT    hr;
    
    CVsAdviseListEnumerator<IVsBuildStatusCallback> adviseEnum(&m_alIVsBuildStatusCallback);
    for (IVsBuildStatusCallback* pSink = adviseEnum.GetFirst();  pSink != NULL; pSink = adviseEnum.GetNext())
    {
        hr = pSink->BuildBegin(&fContinue);
        ASSERT(SUCCEEDED(hr));
        if (SUCCEEDED(hr) && !fContinue)
            return FALSE;
    }
    return TRUE;
}

// advise the sink that the build has ended.
void CMyProjBuildableCfg::FireBuildEnd(BOOL fSuccessful)
{
    HRESULT    hr;
    
    CVsAdviseListEnumerator<IVsBuildStatusCallback> adviseEnum(&m_alIVsBuildStatusCallback);
    for (IVsBuildStatusCallback* pSink = adviseEnum.GetFirst();  pSink != NULL; pSink = adviseEnum.GetNext())
    {
        hr = pSink->BuildEnd(fSuccessful);
        ASSERT(SUCCEEDED(hr));
    }
}


//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjBuildableCfg::StartUpToDateCheck(
    /* [in] */IVsOutputWindowPane * pIVsOutputWindowPane,
    /* [in] */DWORD                 dwOptions)
{
    BOOL fIsUpToDate = FALSE;
    HRESULT hr = IsBuildUpToDate(&fIsUpToDate);
    if (SUCCEEDED(hr) && fIsUpToDate)
        return S_OK;
    return E_FAIL;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjBuildableCfg:: QueryStatus(
    BOOL *pfBuildDone)
{
    ASSERT(pfBuildDone != NULL);
    if (pfBuildDone == NULL)
        return E_POINTER;

    *pfBuildDone = !Busy();
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjBuildableCfg:: Stop(
    BOOL fSync)
{
    // make sure that we are not destroyed during the stop
    CComQIPtr<IVsBuildableProjectCfg> srpKeepMeAliveDuringTheStop(this);

     m_thread.Stop(fSync);
     return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjBuildableCfg:: Wait(
    DWORD dwMilliseconds,
    BOOL  fTickWhenMessageQNotEmpty)
{
     BOOL fCancelled;
     m_thread.WaitAndTick(dwMilliseconds, fTickWhenMessageQNotEmpty, fCancelled);

    if (fCancelled)
        this->Stop(TRUE);

     return S_OK;
}

// MS between ticks fired during a build
#define TICK_PERIOD_MS (200)

CMyProjBuildableCfg::CBuilderThread::CBuilderThread() 
    : 
    super(0, 0, TICK_PERIOD_MS),
    m_op(eIdle),
    m_pCMyProjBuildableCfg(NULL),
    m_pIVsOutputWindowPane(NULL),
    m_pIStream_IVsOutputWindowPane(NULL),
    m_pIVsStatusbar(NULL),
    m_pIStream_IVsStatusbar(NULL)
#ifdef DEBUG
    , m_dwWorkerThreadId(0)
#endif // DEBUG
{
}

CMyProjBuildableCfg::CBuilderThread::~CBuilderThread()
{
    bool fFinished = this->IsPreviousOperationFinished();
    ASSERT(fFinished);

    ASSERT(m_rgpIVsBuildStatusCallback.GetSize() == 0);

    ASSERT(m_pIVsStatusbar == NULL);
    ASSERT(m_pIStream_IVsStatusbar == NULL);

    ASSERT(m_pIVsOutputWindowPane == NULL);
    ASSERT(m_pIStream_IVsOutputWindowPane == NULL);
}

void CMyProjBuildableCfg::CBuilderThread::InternalTick(
    BOOL &rfContinue)
{
    // This should never be fired by the worker thread, only the builder's thread.
    ASSERT(::GetCurrentThreadId() == m_pCMyProjBuildableCfg->m_dwBuilderThreadId);
    rfContinue = m_pCMyProjBuildableCfg->FFireTick();
}

HRESULT CMyProjBuildableCfg::CBuilderThread::Start(
    CMyProjBuildableCfg * pCMyProjBuildableCfg, 
    Operation             op)
{
    ASSERT(m_op == eIdle);
    ASSERT((m_pCMyProjBuildableCfg == NULL) ||
           (m_pCMyProjBuildableCfg == pCMyProjBuildableCfg));
    ExpectedPtrRet(pCMyProjBuildableCfg);

    m_op = op;
    m_pCMyProjBuildableCfg = pCMyProjBuildableCfg;

    // get a pointer to IVsLaunchPadFactory
    if (!m_srpIVsLaunchPadFactory)
    {
        HRESULT hr = _VxModule.QueryService(
                SID_SVsLaunchPadFactory, 
                IID_IVsLaunchPadFactory, 
                (void **) &m_srpIVsLaunchPadFactory);
        IfFailRet(hr);
        ExpectedExprRet(m_srpIVsLaunchPadFactory != NULL);
    }

    return super::Start(pCMyProjBuildableCfg);
}

HRESULT CMyProjBuildableCfg::CBuilderThread::PrepareInStartingThread(
    CMyProjBuildableCfg * pCMyProjBuildableCfg)
{
    ExpectedPtrRet(pCMyProjBuildableCfg);
    HRESULT hr = S_OK;
    int i;

    ASSERT(m_pIStream_IVsOutputWindowPane == NULL);
    ASSERT(m_pIVsOutputWindowPane == NULL);

    ASSERT(m_pIStream_IVsStatusbar == NULL);
    ASSERT(m_pIVsStatusbar == NULL);

    ASSERT(m_rgpIStream_IVsBuildStatusCallback.GetSize() == 0);
    m_rgpIStream_IVsBuildStatusCallback.RemoveAll();

    CVsAdviseListEnumerator<IVsBuildStatusCallback> adviseEnum(&pCMyProjBuildableCfg->m_alIVsBuildStatusCallback);
    for (IVsBuildStatusCallback* pSink = adviseEnum.GetFirst();  pSink != NULL; pSink = adviseEnum.GetNext())
    {
        IStream* pIStream = NULL;
        hr = ::CoMarshalInterThreadInterfaceInStream(
            /* REFIID riid      */ IID_IVsBuildStatusCallback,  //Reference to the identifier of the interface
            /* LPUNKNOWN pUnk   */ pSink,  //Pointer to the interface to be marshaled
            /* LPSTREAM * ppStm */ &pIStream);   //Address of output variable that receives the 
                                        // IStream interface pointer for the marshaled 
                                        // interface
        ASSERT(SUCCEEDED(hr) && (pIStream != NULL));
        IfFailGo(hr);
        m_rgpIStream_IVsBuildStatusCallback.Add(pIStream);
    }

    IfFailGo(this->MarshalParentIUnknown(static_cast<IVsBuildableProjectCfg *>(pCMyProjBuildableCfg)));

    IfFailGo(::CoMarshalInterThreadInterfaceInStream(
                    IID_IUnknown,
                    static_cast<IVsOutputWindowPane *>(pCMyProjBuildableCfg->m_pIVsOutputWindowPane),
                    &m_pIStream_IVsOutputWindowPane));

    // Note that the m_pIVsStatusbar is NULL during command line build
    if (pCMyProjBuildableCfg->m_pIVsStatusbar != NULL) 
    {
        IfFailGo(::CoMarshalInterThreadInterfaceInStream(
                    IID_IUnknown,
                    static_cast<IVsStatusbar *>(pCMyProjBuildableCfg->m_pIVsStatusbar),
                    &m_pIStream_IVsStatusbar));
    }
Error:
    if (hr != S_OK)
    {
        // cleanup
        for (i = 0; i < m_rgpIStream_IVsBuildStatusCallback.GetSize(); i++)
        {
            ASSERT(m_rgpIStream_IVsBuildStatusCallback.GetAt(i) != NULL);
            if (m_rgpIStream_IVsBuildStatusCallback.GetAt(i) != NULL)
            {
                m_rgpIStream_IVsBuildStatusCallback.GetAt(i)->Release();
            }
        }
        m_rgpIStream_IVsBuildStatusCallback.RemoveAll();


        this->UnmarshalParentIUnknown();
        if (m_pIStream_IVsOutputWindowPane)
        {
            m_pIStream_IVsOutputWindowPane->Release();
            m_pIStream_IVsOutputWindowPane = NULL;
        }
        if (m_pIStream_IVsStatusbar)
        {
            m_pIStream_IVsStatusbar->Release();
            m_pIStream_IVsStatusbar = NULL;
        }
    }
    return hr;
}

void CMyProjBuildableCfg::CBuilderThread::ReleaseThreadHandle()
{
    ASSERT(m_op != eIdle);
    super::ReleaseThreadHandle();
    m_op = eIdle;
}

void CMyProjBuildableCfg::CBuilderThread::ThreadMain(
    CMyProjBuildableCfg * pCMyProjBuildableCfg)
{

    HRESULT hr = this->InnerThreadMain(pCMyProjBuildableCfg);
    VSASSERT(SUCCEEDED(hr), _T("Inner thread main failed!"));
}

HRESULT CMyProjBuildableCfg::CBuilderThread::InnerThreadMain(
    CMyProjBuildableCfg * pCMyProjBuildableCfg)
{
    HRESULT hr;
    int i;

#ifdef DEBUG
    m_dwWorkerThreadId = ::GetCurrentThreadId();
#endif // DEBUG

    for (i = 0; i < m_rgpIStream_IVsBuildStatusCallback.GetSize(); i++)
    {
        ASSERT(m_rgpIStream_IVsBuildStatusCallback.GetAt(i) != NULL);
        if (m_rgpIStream_IVsBuildStatusCallback.GetAt(i) != NULL)
        {
            IVsBuildStatusCallback* pIVsBuildStatusCallback = NULL;

            hr = ::CoGetInterfaceAndReleaseStream(
                /* LPSTREAM pStm */ m_rgpIStream_IVsBuildStatusCallback.GetAt(i),    
                //Pointer to the stream from which the object is to be marshaled

                /* REFIID riid   */ IID_IVsBuildStatusCallback,    
                //Reference to the identifier of the interface

                /* LPVOID * ppv  */ (void**) &pIVsBuildStatusCallback);
                //Address of output variable that receives the interface pointer requested in riid

            ASSERT(SUCCEEDED(hr));
            // If one failed, we'll just move along; there's not much else we can do!
            if (SUCCEEDED(hr))
            {
                m_rgpIVsBuildStatusCallback.Add(pIVsBuildStatusCallback);
            }
            // Note that even if the unmarshaling fails, the stream is still released
            // by the call
        }
    }
    m_rgpIStream_IVsBuildStatusCallback.RemoveAll();


    ASSERT(m_pIVsOutputWindowPane == NULL);
    m_pIVsOutputWindowPane = NULL;

    if (m_pIStream_IVsOutputWindowPane != NULL)
    {
        hr = ::CoGetInterfaceAndReleaseStream(m_pIStream_IVsOutputWindowPane, 
                IID_IVsOutputWindowPane, (void **) &m_pIVsOutputWindowPane);
        m_pIStream_IVsOutputWindowPane = NULL;
        ASSERT(SUCCEEDED(hr));
    }

    ASSERT(m_pIVsStatusbar == NULL);
    m_pIVsStatusbar = NULL;

    if (m_pIStream_IVsStatusbar != NULL)
    {
        hr = ::CoGetInterfaceAndReleaseStream(m_pIStream_IVsStatusbar, 
                IID_IVsStatusbar, (void **) &m_pIVsStatusbar);
        m_pIStream_IVsStatusbar = NULL;
        ASSERT(SUCCEEDED(hr));
    }

    BOOL fContinue = TRUE;
    BOOL fSuccessfulBuild = FALSE; // set up for Fire_BuildEnd() later on.

    this->Fire_BuildBegin(fContinue);
    
    switch (m_op)
    {
    default:
        ASSERT(false);
        break;

    case eBuild:
        this->DoBuild(fSuccessfulBuild);
        break;

    case eCheckUpToDate:
        this->DoCheckIsUpToDate(fSuccessfulBuild);
        break;

    case eClean:
        this->DoClean(fSuccessfulBuild);
        break;
    }

//BuildEnd:
    if (m_pIVsStatusbar)
    {
        m_pIVsStatusbar->Release();
        m_pIVsStatusbar = NULL;
    }
    if (m_pIVsOutputWindowPane != NULL)
    {
        m_pIVsOutputWindowPane->Release();
        m_pIVsOutputWindowPane = NULL;
    }

    this->Fire_BuildEnd(fSuccessfulBuild);

    for (i = 0; i < m_rgpIVsBuildStatusCallback.GetSize(); i++)
    {
        IVsBuildStatusCallback* pIVsBuildStatusCallback = m_rgpIVsBuildStatusCallback.GetAt(i);
        ASSERT(pIVsBuildStatusCallback != NULL);
        if (pIVsBuildStatusCallback != NULL)
        {
            pIVsBuildStatusCallback->Release();
        }
    }
    m_rgpIVsBuildStatusCallback.RemoveAll();

#ifdef DEBUG
        m_dwWorkerThreadId = 0;
#endif // DEBUG

    return S_OK;
}

// The actual building of the project
void CMyProjBuildableCfg::CBuilderThread::DoBuild(BOOL &rfSuccessfulBuild)
{

    HRESULT  hr           = S_OK;
    BOOL     fErrors      = TRUE;
    BOOL     fContinue    = TRUE;

    CStringW wstrProjectName = m_pCMyProjBuildableCfg->GetProjectName();
    CStringW  wstrOutput; // string to be shown in the output window - something like "%s succeeded." or "compiling %s".

    // display "Compiling <projectname> ..." message in output window and statusbar.
    wstrOutput.Format(IDS_COMPILING, wstrProjectName);
    OutputText(wstrOutput);
    hr = RunCommandLine();
    if (hr == S_OK)
        fErrors = FALSE;
    
    Fire_Tick(fContinue);

    // result
    UINT uIDS = !fContinue ? IDS_BUILDCANCELLED :(fErrors ? IDS_BUILDFAILED : IDS_BUILDSUCCEEDED);
    wstrOutput.Format(uIDS, wstrProjectName);
    OutputText(wstrOutput);

    rfSuccessfulBuild = fContinue && !fErrors;
}

// we dont do clean any more.
void CMyProjBuildableCfg::CBuilderThread::DoClean(
    BOOL &rfSuccessfulBuild)
{
    rfSuccessfulBuild = TRUE;
}

void CMyProjBuildableCfg::CBuilderThread::DoCheckIsUpToDate(
    BOOL &rfSuccessful)
{
    m_fIsUpToDate = FALSE;
    rfSuccessful = TRUE;
}

void CMyProjBuildableCfg::CBuilderThread::Stop(
    BOOL fSync)
{
    // currently we are implementing asynchronous stop
    // just post the stop
    ASSERT(m_op != eIdle);
    m_pCMyProjBuildableCfg->m_fStopBuild = TRUE;
}

void CMyProjBuildableCfg::CBuilderThread::QueryStatus(BOOL *pfDone)
{
    if (pfDone != NULL)
        *pfDone = (m_op == eIdle) ? TRUE : FALSE;
}

void CMyProjBuildableCfg::CBuilderThread::Fire_BuildBegin(
    BOOL &rfContinue)
{
    ASSERT(rfContinue);

    for (int i = 0; i < m_rgpIVsBuildStatusCallback.GetSize(); i++)
    {
        IVsBuildStatusCallback *pIVsBuildStatusCallback = m_rgpIVsBuildStatusCallback.GetAt(i);
        ASSERT(pIVsBuildStatusCallback != NULL);
        if (pIVsBuildStatusCallback != NULL)
        {
            HRESULT hr = pIVsBuildStatusCallback->BuildBegin(&rfContinue);
            ASSERT(SUCCEEDED(hr));

            if (!rfContinue)
                break;
        }
    }
}

void CMyProjBuildableCfg::CBuilderThread::Fire_BuildEnd(
    BOOL fSuccess)
{
    for (int i = 0; i < m_rgpIVsBuildStatusCallback.GetSize(); i++)
    {
        IVsBuildStatusCallback *pIVsBuildStatusCallback = m_rgpIVsBuildStatusCallback.GetAt(i);
        ASSERT(pIVsBuildStatusCallback != NULL);
        if (pIVsBuildStatusCallback != NULL)
        {
            HRESULT hr = pIVsBuildStatusCallback->BuildEnd(fSuccess);
            ASSERT(SUCCEEDED(hr));
        }
    }
}

// Use this function when in the builder thread since this uses
// the marshalled interface ptrs.
void CMyProjBuildableCfg::CBuilderThread::Fire_Tick(
    BOOL &rfContinue)
{
    ASSERT(rfContinue);

    ASSERT(::GetCurrentThreadId() == m_dwWorkerThreadId);

    for (int i = 0; i < m_rgpIVsBuildStatusCallback.GetSize(); i++)
    {
        IVsBuildStatusCallback *pIVsBuildStatusCallback = m_rgpIVsBuildStatusCallback.GetAt(i);
        ASSERT(pIVsBuildStatusCallback != NULL);
        if ((pIVsBuildStatusCallback != NULL) )
        {
            BOOL fContinue = TRUE;
            HRESULT hr = pIVsBuildStatusCallback->Tick(&fContinue);
            ASSERT(SUCCEEDED(hr));
            if (SUCCEEDED(hr) && !fContinue)
            {
                rfContinue = FALSE;
                break;
            }
        }
    }
}

// display status in the output window.
void CMyProjBuildableCfg::CBuilderThread::OutputText(LPCWSTR wsz)
{
    if (m_pIVsStatusbar)
    {
        m_pIVsStatusbar->SetText(wsz);
    }
    if (m_pIVsOutputWindowPane)
    {
        m_pIVsOutputWindowPane->OutputString(wsz);
        m_pIVsOutputWindowPane->OutputString(L"\n");
    }
}


HRESULT CMyProjBuildableCfg::CBuilderThread::OutputTaskItemText(
    /* [in] */ LPCTSTR        pszOutputString,
    /* [in] */ LPCTSTR        pszFilename       /* = _T("") */,
    /* [in] */ LPCTSTR        pszTaskItemText   /* = NULL */,
    /* [in] */ VSTASKPRIORITY nPriority         /* = TP_HIGH */ ,
    /* [in] */ VSTASKCATEGORY nCategory         /* = CAT_BUILDCOMPILE */,
    /* [in] */ LPCTSTR        pszSubcategory    /* = _T("") */,
    /* [in] */ VSTASKBITMAP   nBitmap,          /* = BMP_COMPILE */
    /* [in] */ ULONG          nLineNum          /* = 0 */)
{
    ExpectedPtrRet(pszOutputString);
    ExpectedPtrRet(pszSubcategory);
    ExpectedPtrRet(pszFilename);
    ExpectedExprRet(m_pIVsOutputWindowPane != NULL);

    LPCTSTR pszItemText = NULL;
    if (pszTaskItemText != NULL)
        pszItemText = pszTaskItemText;
    else
        pszItemText = pszOutputString;

    HRESULT hr = m_pIVsOutputWindowPane->OutputTaskItemString(
        /* [in] LPCOLESTR      pszOutputString*/ T2COLE(pszOutputString),
        /* [in] VSTASKPRIORITY nPriority      */ nPriority,
        /* [in] VSTASKCATEGORY nCategory      */ nCategory,
        /* [in] LPCOLESTR      pszSubcategory */ T2COLE(pszSubcategory),
        /* [in] VSTASKBITMAP   nBitmap        */ nBitmap,
        /* [in] LPCOLESTR      pszFilename    */ T2COLE(pszFilename),
        /* [in] ULONG          nLineNum       */ nLineNum,
        /* [in] LPCOLESTR      pszTaskItemText*/ T2COLE(pszItemText));
    IfFailRet(hr);

    hr = m_pIVsOutputWindowPane->FlushToTaskList();

    return hr;
}


HRESULT CMyProjBuildableCfg::CBuilderThread::RunCommandLine()
{
    HRESULT hr = S_OK;
    CString strOutput;
    USES_CONVERSION;

    // get the build info
    CComBSTR cbstrCmdLine;
    cbstrCmdLine = m_pCMyProjBuildableCfg->GetCommandLine();
    if (cbstrCmdLine.Length() == 0)
    {
        strOutput.LoadString(IDS_BUILD_EMPTY_COMMAND_LINE);
        OutputTaskItemText(strOutput);
        return S_FALSE;
    }

    CComBSTR cbstrSrcFile;
    cbstrSrcFile = m_pCMyProjBuildableCfg->GetSourceFile();
    if (cbstrSrcFile.Length() == 0)
    {
        strOutput.LoadString(IDS_BUILD_NO_SOURCE_FILE);
        OutputTaskItemText(strOutput);
        return S_FALSE;
    }

    CComBSTR cbstrPrjType;
    cbstrPrjType = m_pCMyProjBuildableCfg->GetProjectType();
    if (cbstrPrjType.Length() == 0)
    {
        strOutput.LoadString(IDS_BUILD_NO_PROJECT_TYPE);
        OutputTaskItemText(strOutput);
        return S_FALSE;
    }

    WCHAR wszMyCPath[_MAX_PATH]; // compiler path

    // seacrh for the compiler
    // we look next to the dll 
    DWORD dwLen = ::GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), wszMyCPath, _MAX_PATH);
    if (dwLen == 0)
        return HRESULT_FROM_WIN32(::GetLastError());
    if (dwLen == MAX_PATH)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    WCHAR* pwchSlash = wcsrchr(wszMyCPath, L'\\' );
    if( pwchSlash == NULL )  // Remove module name
        return E_UNEXPECTED;
    *(pwchSlash+1) = L'\0';
    if (lstrlenW(wszMyCPath) + lstrlenW(g_wszMyCCompilerName) >= _MAX_PATH)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    lstrcatW(wszMyCPath, g_wszMyCCompilerName);
    if (!LUtilFileExists(wszMyCPath))
    {
        strOutput.LoadString(IDS_E_COMPILERNOTFOUND);
        OutputTaskItemText(strOutput);
        return S_FALSE;
    }

    // get the project root directory.
    CComBSTR cbstrProjectDir;
    cbstrProjectDir = m_pCMyProjBuildableCfg->GetProjectDir();    

    CComPtr<IVsLaunchPad>           srpVsLaunchPad;
    if (!m_srpIVsLaunchPadFactory)
    {
        ASSERT(FALSE);
        return E_UNEXPECTED;
    }
    hr = m_srpIVsLaunchPadFactory->CreateLaunchPad(&srpVsLaunchPad);
    IfFailRet(hr);

    CComObject<CLaunchPadEvents> *  pCLaunchPadEvents;
    hr = CComObject<CLaunchPadEvents>::CreateInstance(&pCLaunchPadEvents);
    IfFailRet(hr);

    pCLaunchPadEvents->m_pBuilder = this;
    CComPtr<IVsLaunchPadEvents>     srpVsLaunchPadEvents;
    hr = pCLaunchPadEvents->QueryInterface(IID_IVsLaunchPadEvents, 
                                           (void **) &srpVsLaunchPadEvents);
    IfFailRet(hr);

    CComBSTR cbstrOutput;
    DWORD    dwExitCode = 0;
    ExpectedPtrRet(m_pIVsOutputWindowPane);
    hr = srpVsLaunchPad->ExecCommand(
      /*[in] LPCOLESTR pszApplicationName          */ wszMyCPath, // passed on to CreateProcess (see Win32 API for details)
      /*[in] LPCOLESTR pszCommandLine              */ cbstrCmdLine, // passed on to CreateProcess (see Win32 API for details)
      /*[in] LPCOLESTR pszWorkingDir               */ cbstrProjectDir, // may be NULL, passed on to CreateProcess (wee Win32 API for details)
      /*[in] LAUNCHPAD_FLAGS lpf                   */ LPF_PipeStdoutToOutputWindow | LPF_PipeStdoutToTaskList,
      /*[in] IVsOutputWindowPane *pOutputWindowPane*/ m_pIVsOutputWindowPane, // if LPF_PipeStdoutToOutputWindow, which pane in the output window should the output be piped to
      /*[in] ULONG nTaskItemCategory               */ CAT_BUILDCOMPILE, // if LPF_PipeStdoutToTaskList is specified
      /*[in] ULONG nTaskItemBitmap                 */ BMP_COMPILE, // if LPF_PipeStdoutToTaskList is specified
      /*[in] LPCOLESTR pszTaskListSubcategory      */ L"", // if LPF_PipeStdoutToTaskList is specified
      /*[in] IVsLaunchPadEvents *pVsLaunchPadEvents*/ srpVsLaunchPadEvents,
      /*[out] DWORD *pdwProcessExitCode            */ &dwExitCode, // value return by process
      /*[out] BSTR *pbstrOutput                    */ &cbstrOutput); // all output generated (may be NULL)
    
    ENVSDK_TRACE(envsdkTraceGeneral, TLI, 
        _T(": RunCommandLine cbstrOutput = %s \n"), W2T(cbstrOutput));
    
    // check the error code returned
    if ( FAILED(hr) || dwExitCode)
        hr = S_FALSE;
    else
        hr = S_OK;

    return hr;                      
}

