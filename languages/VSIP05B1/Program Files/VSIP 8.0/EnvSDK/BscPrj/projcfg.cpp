
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// projcfg.cpp : Implementation of the CMyProjectCfg configuration object.
//             This object is involved in Build/Debug/Deploy operations

#include "stdafx.h"
#include "PrjInc.h"

#include "PrjNRoot.h"
#include "ProjCfg.h"
#include "VsOutput.h"       // IVsOutput,IVsOutput2 
#include "VsEnumOutputs.h"  // CVsEnumOutputs
#include "vsmem.h"

#include "genthd.h"
#include "PrjHier.h"

#ifndef countof
#define countof(exp) ( sizeof( exp ) / sizeof( ( exp )[0] ) )
#endif

/////////////////////////////////////////////////////////////////////////////
// These are used by the Load/Save operations.
const  WCHAR* STR_LaunchCmdLine = L"LaunchCmdLine";
const  WCHAR* STR_LaunchArgs    = L"LaunchArgs";
const  WCHAR* STR_BuildCmdLine  = L"BuildCmdLine";
const  WCHAR* STR_BuildOutputs  = L"BuildOutputs";
   
// =========================================================================
//                                 Construct, initialize, copy, and destruct
//
CMyProjectCfg::CMyProjectCfg()  
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CMyProjectCfg::CMyProjectCfg : this = 0x%x \n"), this);
}

CMyProjectCfg::~CMyProjectCfg()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CMyProjectCfg::~CMyProjectCfg : this = 0x%x \n"), this);
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

    // IVsProjectCfg2 members
    m_rgogt[0] = OGT_Built;

    return S_OK;
}


HRESULT CMyProjectCfg::Clone(CMyProjectCfg* pClonedCfg)
{
    ExpectedPtrRet(pClonedCfg);

    HRESULT hr = S_OK;
       
    // Clone the property table
    pClonedCfg->m_strPrgCMDLine=m_strPrgCMDLine;
    pClonedCfg->m_strPrgArgs=m_strPrgArgs;
    pClonedCfg->m_strBuildCMD=m_strBuildCMD;
    pClonedCfg->m_strBuildOutputs=m_strBuildOutputs;

    // m_pHier is not cloned - it is set up in Init().

    // cfg 
    // m_strCfgName;
    // m_strPlatformName;
    // m_strName; // strCfgName+"|"+strPlatformName;

    // m_strCfgName, m_strPlatformName, and m_strName cannot be cloned 
    // because the names of the new config may be different. 
    // They are set up in Init().

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
                                    STR_LaunchCmdLine,
                                    T2COLE(m_strPrgCMDLine),
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_LaunchArgs,
                                    T2COLE(m_strPrgArgs),
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_BuildCmdLine,
                                    T2COLE(m_strBuildCMD),
                                    NULL /*szLineComment*/);
    IfFailRet(hr);

    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                    STR_BuildOutputs,
                                    T2COLE(m_strBuildOutputs),
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

        if (_wcsicmp(rgwchPropName, STR_LaunchCmdLine) == 0)
        {
            m_strPrgCMDLine = varValue.bstrVal;
            m_strPrgCMDLine.Trim();
        }
        else if (_wcsicmp(rgwchPropName, STR_LaunchArgs) == 0)
            m_strPrgArgs = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_BuildCmdLine) == 0)
            m_strBuildCMD = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_BuildOutputs) == 0)
            m_strBuildOutputs = varValue.bstrVal;
        else
        {
            // NOTE: we'll just ignore properties without recognized names
        }
    }

    return hr;
}

//                                                                Persisting
// =========================================================================


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

STDMETHODIMP CMyProjectCfg::get_CanonicalName(/* [out] */BSTR *pbstrCanonicalName)
{
    ExpectedPtrRet(pbstrCanonicalName);

    *pbstrCanonicalName = m_strName.AllocSysString();

    return (*pbstrCanonicalName) ? S_OK : E_OUTOFMEMORY;
}


// =========================================================================
//                                                   IVsDebuggableProjectCfg
//
HRESULT CMyProjectCfg::DebugLaunch(/* [in] */ VSDBGLAUNCHFLAGS grfLaunch)
{
    HRESULT hr = E_NOTIMPL;
    CComPtr<IVsDebugger> srpVsDebugger;
    VsDebugTargetInfo  dbgi;
    if (m_strPrgCMDLine.IsEmpty())
        return S_OK;

    if( DBGLAUNCH_NoDebug & grfLaunch )
    {
        CString strCommand;
        BOOL fQuote = (m_strPrgCMDLine[0] != _T('"'));
        if (fQuote)
            strCommand += '"';
        strCommand += m_strPrgCMDLine;
        if (fQuote)
            strCommand += '"';
        ShellExecute(NULL, NULL, strCommand, m_strPrgArgs, NULL, SW_SHOWNORMAL);
        return(S_OK);
    }
    else 
    {
        // When the debug target is the project build output, the project have to use 
        // IVsSolutionDebuggingAssistant2 to determine if the target was deployed.
        // The interface allows the project to find out where the outputs were deployed to 
        // and direct the debugger to the deployed locations as appropriate.
        // Projects start out their debugging sessions by calling MapOutputToDeployedURLs().

        // Here we do not use IVsSolutionDebuggingAssistant2 because our debug target is 
        // explicitly set in the project options and it is not built by the project.
        // For demo of how to use IVsSolutionDebuggingAssistant2 refer to MycPrj sample in the 
        // Environment SDK. 

        hr = _VxModule.QueryService(SID_SVsShellDebugger, IID_IVsDebugger, (void **)&srpVsDebugger);
        if (SUCCEEDED(hr))
        {
            CString strDir;
            CString strMachine;
                
            memset(&dbgi, 0, sizeof(VsDebugTargetInfo));
            dbgi.cbSize = sizeof(VsDebugTargetInfo);
            dbgi.bstrRemoteMachine = NULL;
            
            dbgi.dlo = DLO_Custom;          // specifies how this process should be launched
            // clsidCustom is the clsid of the debug engine to use to launch the debugger
            dbgi.clsidCustom = guidCOMPlusNativeEng;        // the mixed-mode debugger
            dbgi.bstrMdmRegisteredName = NULL; // used with DLO_AlreadyRunning. The name of the
                // app as it is registered with the MDM.
                
            dbgi.bstrExe = m_strPrgCMDLine.AllocSysString();
            strDir = m_pHier->GetProjectLocation();
            dbgi.bstrCurDir = strDir.AllocSysString();
            
            if (!m_strPrgArgs.IsEmpty())
            {
                dbgi.bstrArg = m_strPrgArgs.AllocSysString();   // command line arguments to the exe. used with DLO_CreateProcess.
                if (NULL == dbgi.bstrArg)
                    hr = E_OUTOFMEMORY;               
            }
            else
                dbgi.bstrArg = NULL;
            
            if ((NULL == dbgi.bstrExe) || (NULL == dbgi.bstrCurDir))
                hr = E_OUTOFMEMORY;
            if (SUCCEEDED(hr))
            {
                hr = srpVsDebugger->LaunchDebugTargets(1, &dbgi);
            }
            if (FAILED(hr))
            {
                CString str;
                VxFormatString1(str, IDP_ISP_ERRLAUNCHINGAPP, NULL);
                _VxModule.SetErrorInfo(E_FAIL, str, 0 /*dwHelpContextID*/);
                hr = E_FAIL;
            }
            if (dbgi.bstrExe)
            {
                ::SysFreeString(dbgi.bstrExe);
            }
            if (dbgi.bstrArg)
            {
                ::SysFreeString(dbgi.bstrArg);
            }
        }
    }
    return(hr);
}

//---------------------------------------------------------------------------
// helper function for IVsDebuggableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::GetDebugLaunchTargetCount(/* [in] */int iConfig, /* [out]*/ULONG *puCount)
{
    if ( m_strPrgCMDLine.IsEmpty() || !UtilIsExecutableFile(m_strPrgCMDLine) ) 
    {
        *puCount = 0;
    }
    else 
    {
        *puCount = 1; // there is only one target bscproject
    }
    return S_OK;    
}

HRESULT CMyProjectCfg::QueryDebugLaunch(/* [in] */VSDBGLAUNCHFLAGS grfLaunch, /* [out] */ BOOL __RPC_FAR *pfCanLaunch)
{
    ULONG uCount;
    GetDebugLaunchTargetCount(0, &uCount);
    *pfCanLaunch = uCount > 0;
    return S_OK;
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


STDMETHODIMP CMyProjectCfg::get_BuildableProjectCfg(/* [out] */IVsBuildableProjectCfg **ppIVsBuildableProjectCfg)
{
    if (!ppIVsBuildableProjectCfg)
        return E_INVALIDARG;
    *ppIVsBuildableProjectCfg = NULL;   // always initialize out params

    CComObject<CMyProjBuildableCfg> *pProjBuildableCfg = NULL;
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
   ASSERT(pfIsPackaged != NULL);
   if (pfIsPackaged == NULL)
       return E_INVALIDARG;
   *pfIsPackaged = FALSE;
   return S_OK;
}
        
STDMETHODIMP CMyProjectCfg::get_RootURL(/* [out] */ BSTR *pbstrRootURL)
{
    if (!pbstrRootURL)
        return E_POINTER;
    *pbstrRootURL = NULL;   // always initialize out params

    CString strRoot(_T("file:///")), strAbs;
    CFileVwProjNode *pProjNode = m_pHier->GetProjectNode();

    ASSERT(pProjNode->IsKindOf(Type_CFileVwProjNode));
    
    HRESULT hr = pProjNode->GetFolderPath(strAbs);
    if (FAILED(hr))
        return hr;

    strRoot += strAbs;
    *pbstrRootURL = strRoot.AllocSysString();

    return (*pbstrRootURL) ? S_OK : E_OUTOFMEMORY;
}

//---------------------------------------------------------------------------
// interface:ISpecifyPropertyPages
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::GetPages(CAUUID *pPages)
{
    ExpectedPtrRet(pPages);
    pPages->cElems = 2;
    pPages->pElems = (GUID*)CoTaskMemAlloc(pPages->cElems*sizeof(GUID));
    if (!pPages->pElems)
        return E_OUTOFMEMORY;

    pPages->pElems[0] = CLSID_LaunchPPG;
    pPages->pElems[1] = CLSID_CustomPPG;
    return S_OK;
}


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

    // if there are outputs that are not in the output groups - add them

    return hr;
}


STDMETHODIMP CMyProjectCfg::GetOutputAbsPath(
    /* [out] */ BSTR* pbstr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CMyProjectCfg::GetOutputAbsPath this = 0x%x \n"), this);
    ExpectedPtrRet(pbstr);

    CString strOutputAbsPath;

    CComBSTR bstrOutput;
    HRESULT hr = get_Outputs(&bstrOutput);
    IfFailRet(hr);
    CString strOutputFile = bstrOutput;
    strOutputFile.TrimLeft();
    strOutputFile.TrimRight();

    CString strProjectFolder;
    IfFailRet(m_pHier->GetProjectNode()->GetFolderPath(strProjectFolder));
    if (! strOutputFile.IsEmpty() )
        if (LUtilIsAbsolutePath(strOutputFile))
            strOutputAbsPath = strOutputFile;
        else
            if (!LUtilConcatPaths(strProjectFolder, strOutputFile, strOutputAbsPath))
                return E_FAIL;

    strOutputAbsPath.MakeLower();
    *pbstr = strOutputAbsPath.AllocSysString();
    if (NULL == (*pbstr))
        return E_OUTOFMEMORY;
    return S_OK;
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
    hr = GetOutputAbsPath(&cbstrOutputFile);

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



//                                                    IVsProjectCfg2 helpers
// -------------------------------------------------------------------------

//                                                            IVsProjectCfg2
// =========================================================================




//---------------------------------------------------------------------------
// interface:IBscProjCfgProps
//---------------------------------------------------------------------------
HRESULT CMyProjectCfg::get_CommandLine(BSTR *pVal)
{
    ExpectedPtrRet(pVal);
    *pVal = m_strPrgCMDLine.AllocSysString();
    if (NULL == (*pVal))
        return E_OUTOFMEMORY;
    return S_OK;
}

HRESULT CMyProjectCfg::put_CommandLine(BSTR NewName)
{
  m_strPrgCMDLine = CString(NewName);
  m_strPrgCMDLine.Trim();
  SetProjectFileDirty(TRUE);
  return S_OK;
}

HRESULT CMyProjectCfg::get_CommandLineArguments(BSTR *pVal)
{
    ExpectedPtrRet(pVal);
    *pVal = m_strPrgArgs.AllocSysString();
    if (NULL == (*pVal))
        return E_OUTOFMEMORY;
    return S_OK;
}

HRESULT CMyProjectCfg::put_CommandLineArguments(BSTR NewName)
{
  m_strPrgArgs = CString(NewName);
  SetProjectFileDirty(TRUE);
  return S_OK;
}

HRESULT CMyProjectCfg::get_BuildArguments(BSTR *pVal)
{
    ExpectedPtrRet(pVal);
    *pVal = m_strBuildCMD.AllocSysString();
    if (NULL == (*pVal))
        return E_OUTOFMEMORY;
    return S_OK;
}

HRESULT CMyProjectCfg::put_BuildArguments(BSTR NewName)
{
  m_strBuildCMD = CString(NewName);
  SetProjectFileDirty(TRUE);
  return S_OK;
}

HRESULT CMyProjectCfg::get_Outputs(BSTR *pVal)
{
    ExpectedPtrRet(pVal);
    *pVal = m_strBuildOutputs.AllocSysString();
    if (NULL == (*pVal))
        return E_OUTOFMEMORY;
    return S_OK;
}

HRESULT CMyProjectCfg::put_Outputs(BSTR NewName)
{
    // Check if file name is valid
	HRESULT hr = E_INVALIDARG;
    HANDLE hFile = CreateFile(NewName,
                              0,
                              0,
                              NULL,
							  OPEN_ALWAYS,
							  SECURITY_SQOS_PRESENT | SECURITY_IDENTIFICATION,
							  NULL);

	// Now make sure the file is an actual file and not a pipe, device,...
	if (hFile != INVALID_HANDLE_VALUE
        && GetFileType(hFile) == FILE_TYPE_DISK)
    {
		// Valid file
		m_strBuildOutputs = CString(NewName);
		SetProjectFileDirty(TRUE);
        hr = S_OK;
    }
	else
	{
		// Invalid file specified, show an error message
        TCHAR szMsg[128];
        if (! ::LoadString(_AtlBaseModule.GetResourceInstance(), IDS_E_INVALID_OUTPUT, szMsg, countof(szMsg)))
            return hr;
        IVsUIShell* pIVsUIShell = _VxModule.GetIVsUIShell();
		LONG result;
        if (pIVsUIShell)
            pIVsUIShell->ShowMessageBox(OLEROLE_TOPLEVELCOMPONENT,
                                        GUID_NULL,
										NULL,
										szMsg,
										NULL,
										0,
										OLEMSGBUTTON_OK,
										OLEMSGDEFBUTTON_FIRST,
										OLEMSGICON_CRITICAL,
										FALSE,
										&result);
	}


	if (hFile)
		CloseHandle(hFile);

  return hr;
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

    CComBSTR cbstrCATID(prjCATIDBscPrjProjectConfigBrowseObject);
    if (cbstrCATID.Length() == 0)
        return E_OUTOFMEMORY;

    *pbstrRetval = cbstrCATID.Detach();
    return S_OK;
}


//=========================================================================
//                                                                    BUILD

static HRESULT RunCustomBuildBatchFile(
    CString                               strBatchFileText,
    IVsOutputWindowPane *                 pIVsOutputWindowPane,
    CMyProjBuildableCfg::CBuilderThread * pBuilder);


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

HRESULT CMyProjBuildableCfg::Init(
    CMyProjectCfg *       pProjectCfg, 
    CMyProjectHierarchy * pHier)
{
    ExpectedPtrRet(pProjectCfg);
    ExpectedPtrRet(pHier);
    m_pProjectCfg = pProjectCfg;
    m_pHier = pHier;
    ((IVsHierarchy*)(m_pHier->GetIVsHierarchy()))->AddRef();

    HRESULT hr = S_OK;
    ASSERT(m_pHier->GetRootNode() != NULL);
    if (m_pHier->GetRootNode() != NULL)
    {
        cbstrProjectName = pHier->GetRootNode()->GetName();
        CString strProjDir;
        IfFailRet(m_pHier->GetProjectNode()->GetFolderPath(strProjDir));
        cbstrProjectDir = strProjDir;
    }

    hr = m_pProjectCfg->get_BuildArguments(&cbstrCommandLine);
    ASSERT(SUCCEEDED(hr));
    return hr;
}

// tick the sink and check if build can continue or not.
BOOL CMyProjBuildableCfg::FFireTick()
{
    BOOL fContinue = TRUE;
    HRESULT hr;
    
    for (int i=0; i<NUMBER_OF(m_rgsrpIVsBuildStatusCallback); i++)
    {
        if (m_rgsrpIVsBuildStatusCallback[i] != NULL && m_rgfTicking[i])
        {
            hr = m_rgsrpIVsBuildStatusCallback[i]->Tick(&fContinue);
            ASSERT(SUCCEEDED(hr));
            if (!fContinue)
                return FALSE;
        }
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

    for (ULONG i=0; i<NUMBER_OF(m_rgsrpIVsBuildStatusCallback); i++)
        m_rgsrpIVsBuildStatusCallback[i] = NULL;
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
    /* [in] */ IVsBuildStatusCallback * pIVsBuildStatusCallback,
    /* [out] */VSCOOKIE *                  pdwCookie)
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
STDMETHODIMP CMyProjBuildableCfg::UnadviseBuildStatusCallback(
    /* [in] */ VSCOOKIE dwCookie)
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
    if (NULL == pfSupported || NULL == pfEnabled)
        return E_POINTER;
    *pfSupported = *pfEnabled = FALSE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjBuildableCfg:: StartBuild(
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

    HRESULT hr = m_thread.Start(this, CBuilderThread::eBuild);

    SetThread(m_thread.m_hThread);
    return hr;
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

//---------------------------------------------------------------------------
// interface:IVsBuildableProjectCfg
//---------------------------------------------------------------------------
HRESULT CMyProjBuildableCfg:: StartUpToDateCheck(
    /* [in] */IVsOutputWindowPane * pIVsOutputWindowPane,
    /* [in] */DWORD                 dwOptions)
{
    return S_OK;
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
HRESULT CMyProjBuildableCfg::Stop(
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
    ULONG i;

    for (i=0; i<NUMBER_OF(m_rgpIVsBuildStatusCallback); i++)
        m_rgpIVsBuildStatusCallback[i] = NULL;

    for (i=0; i<NUMBER_OF(m_rgpIStream_IVsBuildStatusCallback); i++)
        m_rgpIStream_IVsBuildStatusCallback[i] = NULL;

}

CMyProjBuildableCfg::CBuilderThread::~CBuilderThread()
{
    bool fFinished = this->IsPreviousOperationFinished();
    ASSERT(fFinished);

#ifdef DEBUG
    ULONG i;

    for (i=0; i<NUMBER_OF(m_rgpIVsBuildStatusCallback); i++)
        ASSERT(m_rgpIVsBuildStatusCallback[i] == NULL);
#endif // DEBUG

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
    ULONG i;
    HRESULT hr = S_OK;

    ASSERT(m_pIStream_IVsOutputWindowPane == NULL);
    ASSERT(m_pIVsOutputWindowPane == NULL);

    ASSERT(m_pIStream_IVsStatusbar == NULL);
    ASSERT(m_pIVsStatusbar == NULL);

    for (i=0; i<NUMBER_OF(m_rgpIStream_IVsBuildStatusCallback); i++)
    {
        ASSERT(m_rgpIStream_IVsBuildStatusCallback[i] == NULL);
        m_rgpIStream_IVsBuildStatusCallback[i] = NULL;
    }

    for (i=0; i<NUMBER_OF(m_rgpIStream_IVsBuildStatusCallback); i++)
    {
        if (pCMyProjBuildableCfg->m_rgsrpIVsBuildStatusCallback[i] != NULL)
        {
            IfFailGo(::CoMarshalInterThreadInterfaceInStream(
                                IID_IVsBuildStatusCallback,
                                pCMyProjBuildableCfg->m_rgsrpIVsBuildStatusCallback[i],
                                &m_rgpIStream_IVsBuildStatusCallback[i]));
        }
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
        for (i=0; i<NUMBER_OF(m_rgpIStream_IVsBuildStatusCallback); i++)
        {
            if (m_rgpIStream_IVsBuildStatusCallback[i] != NULL)
            {
                m_rgpIStream_IVsBuildStatusCallback[i]->Release();
                m_rgpIStream_IVsBuildStatusCallback[i] = NULL;
            }
        }
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
    ULONG i;
    HRESULT hr;

#ifdef DEBUG
    m_dwWorkerThreadId = ::GetCurrentThreadId();
#endif // DEBUG

    for (i=0; i<NUMBER_OF(m_rgpIStream_IVsBuildStatusCallback); i++)
    {
        ASSERT(m_rgpIVsBuildStatusCallback[i] == NULL);
        m_rgpIVsBuildStatusCallback[i] = NULL;
        if (m_rgpIStream_IVsBuildStatusCallback[i] != NULL)
        {
            hr = ::CoGetInterfaceAndReleaseStream(m_rgpIStream_IVsBuildStatusCallback[i],
                   IID_IVsBuildStatusCallback, (void **) &m_rgpIVsBuildStatusCallback[i]);
            m_rgpIStream_IVsBuildStatusCallback[i] = NULL;
            // If one failed, we'll just move along; there's not much else we can do!
            ASSERT(SUCCEEDED(hr));
        }
    }

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

    for (i=0; i<NUMBER_OF(m_rgpIVsBuildStatusCallback); i++)
    {
        IVsBuildStatusCallback *&rpIVsBuildStatusCallback = m_rgpIVsBuildStatusCallback[i];

        if (rpIVsBuildStatusCallback != NULL)
        {
            rpIVsBuildStatusCallback->Release();
            rpIVsBuildStatusCallback = NULL;
        }
    }

#ifdef DEBUG
        m_dwWorkerThreadId = 0;
#endif // DEBUG

    return S_OK;
}

// The actual building of the project
void CMyProjBuildableCfg::CBuilderThread::DoBuild(BOOL &rfSuccessfulBuild)
{
    HRESULT hr = S_OK;
    CStringW wstrProjectName = m_pCMyProjBuildableCfg->GetProjectName();
    // display "Compiling <projectname> ..." message in output window and statusbar.
    CStringW wstrText;
    wstrText.Format(IDS_COMPILING, wstrProjectName);
    OutputText(wstrText);

    hr = RunCustomBuildBatchFile(
        m_pCMyProjBuildableCfg->GetCommandLine(),
        m_pIVsOutputWindowPane, 
        this);

    BOOL    fErrors = (hr != S_OK);
    BOOL    fContinue = TRUE;
    Fire_Tick(fContinue);

    wstrText.Format(
        !fContinue ? IDS_BUILDCANCELLED : 
                     (fErrors ? IDS_BUILDFAILED : IDS_BUILDSUCCEEDED), 
        wstrProjectName);
    OutputText(wstrText);

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

    for (ULONG i=0; i<NUMBER_OF(m_rgpIVsBuildStatusCallback); i++)
    {
        IVsBuildStatusCallback *pIVsBuildStatusCallback = m_rgpIVsBuildStatusCallback[i];

        if (pIVsBuildStatusCallback != NULL)
        {
            HRESULT hr = pIVsBuildStatusCallback->BuildBegin(&rfContinue);
            ASSERT(SUCCEEDED(hr));

            if (!rfContinue)
                break;

            m_pCMyProjBuildableCfg->m_rgfStarted[i] = true;
        }
    }
}

void CMyProjBuildableCfg::CBuilderThread::Fire_BuildEnd(
    BOOL fSuccess)
{
    for (ULONG i=0; i<NUMBER_OF(m_rgpIVsBuildStatusCallback); i++)
    {
        IVsBuildStatusCallback *pIVsBuildStatusCallback = m_rgpIVsBuildStatusCallback[i];

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

    // check if the build is stopped
    if (m_pCMyProjBuildableCfg->m_fStopBuild)
    {
        rfContinue = FALSE;
        return;
    }

    // We use the pointer that's in the object, because we don't want to use the marshalled version.
    for (ULONG i=0; i<NUMBER_OF(m_rgpIVsBuildStatusCallback); i++)
    {
        IVsBuildStatusCallback *pIVsBuildStatusCallback = m_rgpIVsBuildStatusCallback[i];
        if ((pIVsBuildStatusCallback != NULL) && m_pCMyProjBuildableCfg->m_rgfTicking[i])
        {
            HRESULT hr = pIVsBuildStatusCallback->Tick(&rfContinue);
            ASSERT(SUCCEEDED(hr));

            if (!rfContinue)
                break;
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

// Runs the user specified pre and post build commands.
HRESULT RunCustomBuildBatchFile(
    CString                                 strBatchFileText, 
    IVsOutputWindowPane *                   pIVsOutputWindowPane, 
    CMyProjBuildableCfg::CBuilderThread *   pBuilder)
{
    if (strBatchFileText.IsEmpty())
        return S_OK;
    ExpectedPtrRet(pBuilder);
    ExpectedPtrRet(pIVsOutputWindowPane);

    HRESULT hr = S_OK;
    USES_CONVERSION;

    // get the project root directory.
    CComBSTR cbstrProjectDir;
    cbstrProjectDir = pBuilder->m_pCMyProjBuildableCfg->GetProjectDir();
 
    CComPtr<IVsLaunchPad> srpIVsLaunchPad;
    ExpectedExprRet(pBuilder->m_srpIVsLaunchPadFactory != NULL);
    hr = pBuilder->m_srpIVsLaunchPadFactory->CreateLaunchPad(&srpIVsLaunchPad);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsLaunchPad != NULL);

    CComObject<CLaunchPadEvents> *pCLaunchPadEvents;
    hr =CComObject<CLaunchPadEvents>::CreateInstance(&pCLaunchPadEvents);
    IfFailRet(hr);
    pCLaunchPadEvents->m_pBuilder = pBuilder;

    CComPtr<IVsLaunchPadEvents> srpIVsLaunchPadEvents;
    hr = pCLaunchPadEvents->QueryInterface(IID_IVsLaunchPadEvents, (void **) &srpIVsLaunchPadEvents);
    IfFailRet(hr);

    hr = srpIVsLaunchPad->ExecBatchScript(
        /* [in] LPCOLESTR pszBatchFileContents         */ T2COLE((LPCTSTR)strBatchFileText),
        /* [in] LPCOLESTR pszWorkingDir                */ cbstrProjectDir,      // may be NULL, passed on to CreateProcess (wee Win32 API for details)
        /* [in] LAUNCHPAD_FLAGS lpf                    */ LPF_PipeStdoutToOutputWindow,
        /* [in] IVsOutputWindowPane *pOutputWindowPane */ pIVsOutputWindowPane, // if LPF_PipeStdoutToOutputWindow, which pane in the output window should the output be piped to
        /* [in] ULONG nTaskItemCategory                */ 0, // if LPF_PipeStdoutToTaskList is specified
        /* [in] ULONG nTaskItemBitmap                  */ 0, // if LPF_PipeStdoutToTaskList is specified
        /* [in] LPCOLESTR pszTaskListSubcategory       */ NULL, // if LPF_PipeStdoutToTaskList is specified
        /* [in] IVsLaunchPadEvents *pVsLaunchPadEvents */ srpIVsLaunchPadEvents,
        /* [out] BSTR *pbstrOutput                     */ NULL); // all output generated (may be NULL)
    IfFailRet(hr);

    return hr;
}



CLaunchPPG::CLaunchPPG()
{
    m_dwTitleID = IDS_LAUNCH_PAGE;
    ResetChangedStateFlags();
}

/* static */ 
HRESULT WINAPI CLaunchPPG::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{

    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    IfFailRet(hr);

    // get the guid strings
    CComBSTR cbstrCLSID_LaunchPPG(CLSID_LaunchPPG);
    if (!cbstrCLSID_LaunchPPG) 
        return E_OUTOFMEMORY;

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"CLSID_LaunchPPG",                cbstrCLSID_LaunchPPG},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_LAUNCH, bRegister, rgMap);
}


LRESULT CLaunchPPG::OnChangePrg(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    m_fIsLaunchPrgChanged = TRUE;
    SetDirty(TRUE);
    return 0;
}

LRESULT CLaunchPPG::OnChangeParam(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    m_fIsCmdLineParamChanged = TRUE;
    SetDirty(TRUE);
    return 0;
}


void CLaunchPPG::InitValues()
{
    InitCMDLine();
    InitCMDLineArgs();

    //Setting the above values caused the edit boxes to change. When they change, the Apply button
    //  enables (as per our notification handler). Reset that now...
    ResetChangedStateFlags();
    SetDirty(FALSE);
}

HRESULT CLaunchPPG::InitCMDLine()
{
    
    HRESULT     hr = E_FAIL;
    CComBSTR    ccbstrOld;
    CComBSTR    ccbstrNew;
    USES_CONVERSION;

    // get the first one
    CComQIPtr<IBscProjCfgProps> pBscProjCfgPropsFirst(m_ppUnk[0]);
    IfNullGo(pBscProjCfgPropsFirst, E_FAIL);

    IfFailGo(pBscProjCfgPropsFirst->get_CommandLine(&ccbstrOld));

    for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
    {
        // get the next one
        CComQIPtr<IBscProjCfgProps> pBscProjCfgPropsNext(m_ppUnk[uiCfg]);
        IfNullGo(pBscProjCfgPropsNext, E_FAIL);

        IfFailGo(pBscProjCfgPropsNext->get_CommandLine(&ccbstrNew));

        // Check if the current and previous values are still equal.  If not,
        // then there is no way we can get a determinate value.
        if (!ccbstrNew || !ccbstrOld || (wcscmp(ccbstrNew, ccbstrOld) != 0))
        {
            SetDlgItemText(IDC_LAUNCHPRG, _T(""));
            IfFailGo(E_FAIL);
        }
    }

    // The value has been determined
    SetDlgItemText(IDC_LAUNCHPRG, W2T(ccbstrOld));

Error:
    return hr;
}

HRESULT CLaunchPPG::InitCMDLineArgs()
{
    
    HRESULT     hr = E_FAIL;
    CComBSTR    ccbstrOld;
    CComBSTR    ccbstrNew;
    USES_CONVERSION;

    // get the first one
    CComQIPtr<IBscProjCfgProps> pBscProjCfgPropsFirst(m_ppUnk[0]);
    IfNullGo(pBscProjCfgPropsFirst, E_FAIL);

    IfFailGo(pBscProjCfgPropsFirst->get_CommandLineArguments(&ccbstrOld));

    for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
    {
        // get the next one
        CComQIPtr<IBscProjCfgProps> pBscProjCfgPropsNext(m_ppUnk[uiCfg]);
        IfNullGo(pBscProjCfgPropsNext, E_FAIL);

        IfFailGo(pBscProjCfgPropsNext->get_CommandLineArguments(&ccbstrNew));

        // Check if the current and previous values are still equal.  If not,
        // then there is no way we can get a determinate value.
        if (!ccbstrNew || !ccbstrOld || (wcscmp(ccbstrNew, ccbstrOld) != 0))
        {
            SetDlgItemText(IDC_CMDLINEPARAM, _T(""));
            IfFailGo(E_FAIL);
        }
    }

    // The value has been determined
    SetDlgItemText(IDC_CMDLINEPARAM, W2T(ccbstrOld));

Error:
    return hr;
}

// reset all the flags for "changed" state to false
HRESULT CLaunchPPG::ResetChangedStateFlags()
{
    m_fIsLaunchPrgChanged = FALSE;
    m_fIsCmdLineParamChanged = FALSE;
    return S_OK;
}



STDMETHODIMP CLaunchPPG::Apply()
{
    HRESULT hr = S_OK;
    ExpectedExprRet(*m_ppUnk);
    CMyProjectCfg* pMyProjectCfg = reinterpret_cast<CMyProjectCfg*>(*m_ppUnk);
    CMyProjectHierarchy* pHier;
    
    pHier = pMyProjectCfg->GetHierarchy();
    ExpectedExprRet(pHier);

    if ( !pHier->QueryEditProjectFile() )
    {
        return OLE_E_PROMPTSAVECANCELLED;
    }
      
    CComBSTR cbstrCMDLine = NULL;
    CComBSTR cbstrCMDLineArgs = NULL;

    if (!GetDlgItemText(IDC_LAUNCHPRG, cbstrCMDLine.m_str))
        return E_FAIL;
    if (!GetDlgItemText(IDC_CMDLINEPARAM, cbstrCMDLineArgs.m_str))
        return E_FAIL;

    for (UINT uObj = 0; uObj < m_nObjects; uObj++)
    {
        CComQIPtr<IBscProjCfgProps> pBscProjCfgProps(m_ppUnk[uObj]);
        if (pBscProjCfgProps)
        {    
            if (m_fIsLaunchPrgChanged)
            {
                hr = pBscProjCfgProps->put_CommandLine(cbstrCMDLine);
                IfFailRet(hr);
            }
            if (m_fIsCmdLineParamChanged)
            {
                hr = pBscProjCfgProps->put_CommandLineArguments(cbstrCMDLineArgs);
                IfFailRet(hr);
            }
        }
    }

    // reset the status flags
    ResetChangedStateFlags();        
    SetDirty(FALSE);
    return S_OK;
}
      
CCustomPPG::CCustomPPG() 
{
    m_dwTitleID = IDS_CUSTOM_PAGE;
    ResetChangedStateFlags();
}

/* static */ 
HRESULT WINAPI CCustomPPG::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{

    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    IfFailRet(hr);

    // get the guid strings
    CComBSTR cbstrCLSID_CustomPPG(CLSID_CustomPPG);
    if (!cbstrCLSID_CustomPPG) 
        return E_OUTOFMEMORY;

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"CLSID_CustomPPG",                cbstrCLSID_CustomPPG},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_CUSTOM, bRegister, rgMap);
}


LRESULT CCustomPPG::OnChangeBuildCmds(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    m_fIsBuildCmdsChanged = TRUE;
    SetDirty(TRUE);
    return 0;
}

LRESULT CCustomPPG::OnChangeBuildOutputs(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    m_fIsBuildOutputsChanged = TRUE;
    SetDirty(TRUE);
    return 0;
}


void CCustomPPG::InitValues()
{
    InitBuildCmds();
    InitBuildOutputs();
        
    //Setting the above values caused the edit boxes to change. When they change, the Apply button
    //  enables (as per our notification handler). Reset that now...
    ResetChangedStateFlags();
    SetDirty(FALSE);
}


HRESULT CCustomPPG::InitBuildCmds()
{
    
    HRESULT     hr = E_FAIL;
    CComBSTR    ccbstrOld;
    CComBSTR    ccbstrNew;
    USES_CONVERSION;

    // get the first one
    CComQIPtr<IBscProjCfgProps> pBscProjCfgPropsFirst(m_ppUnk[0]);
    IfNullGo(pBscProjCfgPropsFirst, E_FAIL);

    IfFailGo(pBscProjCfgPropsFirst->get_BuildArguments(&ccbstrOld));

    for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
    {
        // get the next one
        CComQIPtr<IBscProjCfgProps> pBscProjCfgPropsNext(m_ppUnk[uiCfg]);
        IfNullGo(pBscProjCfgPropsNext, E_FAIL);

        IfFailGo(pBscProjCfgPropsNext->get_BuildArguments(&ccbstrNew));

        // Check if the current and previous values are still equal.  If not,
        // then there is no way we can get a determinate value.
        if (!ccbstrNew || !ccbstrOld || (wcscmp(ccbstrNew, ccbstrOld) != 0))
        {
            SetDlgItemText(IDC_BUILDCMDS, _T(""));
            IfFailGo(E_FAIL);
        }
    }

    // The value has been determined
    SetDlgItemText(IDC_BUILDCMDS, W2T(ccbstrOld));

Error:
    return hr;
}


HRESULT CCustomPPG::InitBuildOutputs()
{
    
    HRESULT     hr = E_FAIL;
    CComBSTR    ccbstrOld;
    CComBSTR    ccbstrNew;
    USES_CONVERSION;

    // get the first one
    CComQIPtr<IBscProjCfgProps> pBscProjCfgPropsFirst(m_ppUnk[0]);
    IfNullGo(pBscProjCfgPropsFirst, E_FAIL);

    IfFailGo(pBscProjCfgPropsFirst->get_Outputs(&ccbstrOld));

    for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
    {
        // get the next one
        CComQIPtr<IBscProjCfgProps> pBscProjCfgPropsNext(m_ppUnk[uiCfg]);
        IfNullGo(pBscProjCfgPropsNext, E_FAIL);

        IfFailGo(pBscProjCfgPropsNext->get_Outputs(&ccbstrNew));

        // Check if the current and previous values are still equal.  If not,
        // then there is no way we can get a determinate value.
        if (!ccbstrNew || !ccbstrOld || (wcscmp(ccbstrNew, ccbstrOld) != 0))
        {
            SetDlgItemText(IDC_BUILDOUTPUTS, _T(""));
            IfFailGo(E_FAIL);
        }
    }

    // The value has been determined
    SetDlgItemText(IDC_BUILDOUTPUTS, W2T(ccbstrOld));

Error:
    return hr;
}

// reset all the flags for "changed" state to false
HRESULT CCustomPPG::ResetChangedStateFlags()
{
    m_fIsBuildCmdsChanged = FALSE;
    m_fIsBuildOutputsChanged = FALSE;
    return S_OK;
}


STDMETHODIMP CCustomPPG::Apply()
{
    HRESULT hr = S_OK;
    ExpectedExprRet(*m_ppUnk);
    CMyProjectCfg* pMyProjectCfg = reinterpret_cast<CMyProjectCfg*>(*m_ppUnk);
    CMyProjectHierarchy* pHier;
    
    pHier = pMyProjectCfg->GetHierarchy();
    ExpectedExprRet(pHier);
    
    if ( !pHier->QueryEditProjectFile() )
    {
        return OLE_E_PROMPTSAVECANCELLED;
    }
        
    CComBSTR cbstrBuildCMD = NULL;
    CComBSTR cbstrBuildOutputs = NULL;
    
    if (!GetDlgItemText(IDC_BUILDCMDS, cbstrBuildCMD.m_str))
        return E_FAIL;
    if (!GetDlgItemText(IDC_BUILDOUTPUTS, cbstrBuildOutputs.m_str))
        return E_FAIL;
    
    for (UINT uObj = 0; uObj < m_nObjects; uObj++)
    {
        CComQIPtr<IBscProjCfgProps> pBscProjCfgProps(m_ppUnk[uObj]);
        if (pBscProjCfgProps)
        {    
            if (m_fIsBuildCmdsChanged)
            {
                hr = pBscProjCfgProps->put_BuildArguments(cbstrBuildCMD);
                IfFailRet(hr);
            }
            if (m_fIsBuildOutputsChanged)
            {
                hr = pBscProjCfgProps->put_Outputs(cbstrBuildOutputs);
                IfFailRet(hr);
            }
        }
    }
    
   
    ResetChangedStateFlags();
    SetDirty(FALSE);
    return S_OK;
}
