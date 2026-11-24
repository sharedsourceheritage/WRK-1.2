
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// CfgProvider.cpp: implementation of the CCfgProvider class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PrjInc.h" 

//==========================================================================
//                                                construct, init , destruct

CCfgProvider::CCfgProvider()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CCfgProvider::CCfgProvider this = 0x%x\n"), this);

    m_pHier = NULL;
    m_fHasPlatformName = TRUE;
}


CCfgProvider::~CCfgProvider()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CCfgProvider::~CCfgProvider this = 0x%x\n"), this);

    Destroy();
    m_pHier = NULL;
}


//----------------------------------------------------------------------
// Function:    Init
//              To initialize the object
// Parameters: 
//  /* [in] */ CMyProjectHierarchy * pHier - project hierarchy
//
// Returns:     HRESULT
// Notes:
//----------------------------------------------------------------------
HRESULT CCfgProvider::Init(
    /* [in] */ CMyProjectHierarchy * pHier)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::Init \n"));

    ExpectedPtrRet(pHier);

    m_pHier = pHier;
    return S_OK;
}


//----------------------------------------------------------------------
// Function:    CreateDefaultCfgs
//              Create the default set of configurations - 
//              Debug and Release
// Parameters:  
// Returns:     HRESULT
// Notes:
//----------------------------------------------------------------------
HRESULT CCfgProvider::CreateDefaultCfgs()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::CreateDefaultCfgs \n"));

    HRESULT hr = E_FAIL;

    // initialize the array with the platform names
    hr = PlatformNamesInit();
    IfFailRet(hr);

    // default debug and release
    hr = AddCfgsOfCfgName(L"Debug",NULL, FALSE);
    IfFailRet(hr);

    hr = AddCfgsOfCfgName(L"Release",NULL, FALSE);
    IfFailRet(hr);

    return S_OK;
}


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
HRESULT CCfgProvider::Destroy()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::Destroy \n"));

    for (int i = 0; i < CfgsCount(); i++)
    {
        if (m_rgpProjectCfg[i])
        {
            m_rgpProjectCfg[i]->Release();
        }
    }
    m_rgpProjectCfg.RemoveAll();
    m_rgstrCfgNames.RemoveAll();
    m_rgstrPlatformNames.RemoveAll();
    return S_OK;
}

//                                                construct, init , destruct
//==========================================================================


//==========================================================================
//                                                                persisting

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
HRESULT CCfgProvider::LoadCfgs(
    /* [in] */ IVsPropertyStreamIn *pIVsPropertyStreamIn)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::LoadCfgs \n"));

    ExpectedPtrRet(pIVsPropertyStreamIn);

    HRESULT hr = S_OK;
	for (;;)
	{
		CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamInInner;
		VSPROPERTYSTREAMPROPERTYTYPE vspspt;

		WCHAR rgwchCfgName[_MAX_PATH];
		CComVariant varValue;

		// Read next property section for a file. The name of the section 
        // is the path to the file.
		hr = pIVsPropertyStreamIn->Read(NUMBER_OF(rgwchCfgName), 
                                        rgwchCfgName, 
                                        NULL, 
                                        &vspspt, 
                                        &varValue, 
                                        NULL);
		IfFailRet(hr);

		if (rgwchCfgName[0] == L'\0')
			break;

		if (vspspt != VSPSPT_PROPERTY_SECTION || varValue.vt != VT_UNKNOWN || (varValue.punkVal == NULL))
		{
			ASSERT(vspspt == VSPSPT_PROPERTY_SECTION && varValue.vt == VT_UNKNOWN);
			return E_UNEXPECTED;
		}

		hr = varValue.punkVal->QueryInterface(
                                IID_IVsPropertyStreamIn, 
                                (void **) &srpIVsPropertyStreamInInner);
		IfFailRet(hr);

        // parse the name to get the cfg and platform names and then
        // create a configuration object

        CString strName = CString(rgwchCfgName);
        CString strCfgName;
        CString strPlatformName;
        hr = SplitCfgPlatformName(strName, strCfgName, strPlatformName);
		IfFailRet(hr);

        CProjectCfg * pProjectCfg = NULL;
        hr = CreateProjectCfg(strCfgName, strPlatformName, &pProjectCfg);
        IfFailRet(hr);
        ASSERT(pProjectCfg);

        // load the cfg from the stream
		hr = pProjectCfg->Load(srpIVsPropertyStreamInInner);
        pProjectCfg->Release();
        if (FAILED(hr))
        {
            DeleteProjectCfg(pProjectCfg);
            return hr;
        }

		if (srpIVsPropertyStreamInInner != NULL)
		{
			hr = srpIVsPropertyStreamInInner->SkipToEnd();
			if (FAILED(hr))
				return hr;
		}
	}
	return hr;
}


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
HRESULT CCfgProvider::SaveCfgs(
    /* [in] */ IVsPropertyStreamOut *pIVsPropertyStreamOut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::SaveCfgs \n"));

    ExpectedPtrRet(pIVsPropertyStreamOut);

	HRESULT hr = S_OK;
	
	// write out a PropertySection for each cfg using the CanonicalName 
    // as the section name.
    for (int i = 0; i < CfgsCount(); i++)
    {
        CComBSTR  bstrCfgName;
		CComPtr<IVsPropertyStreamOut> srpCfgSectionPropStmOut;
		VSCOOKIE dwCookie;
    
        hr = m_rgpProjectCfg[i]->get_CanonicalName(&bstrCfgName);
		IfFailRet(hr);
		hr = pIVsPropertyStreamOut->BeginPropertySection(
                                        bstrCfgName, 
                                        NULL, 
                                        &srpCfgSectionPropStmOut, 
                                        &dwCookie);
		IfFailRet(hr);

		hr = m_rgpProjectCfg[i]->Save(srpCfgSectionPropStmOut);
		IfFailRet(hr);

		(void)pIVsPropertyStreamOut->EndPropertySection(dwCookie);
		IfFailRet(hr);
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
HRESULT CCfgProvider::SetProjectFileDirty(
    /* [in] */ BOOL fIsDirty)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::SetProjectFileDirty \n"));

	VARIANT_BOOL vbDirty = fIsDirty ? VARIANT_TRUE : VARIANT_FALSE;

    return m_pHier->put_IsDirty(vbDirty);
}

//                                                                persisting
//==========================================================================


//==========================================================================
//                                                            IVsCfgProvider

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
STDMETHODIMP CCfgProvider::GetCfgs(
    /* [in]                     */ ULONG celt,
    /* [in, out, size_is(celt)] */ IVsCfg *rgpcfg[],
    /* [out, optional]          */ ULONG *pcActual,
    /* [out, optional]          */ VSCFGFLAGS *prgfFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::GetCfgs /IVsCfgProvider/ \n"));

    ULONG   cActual = 0;
    HRESULT hr = S_OK;
    
    if ((celt == 0) && (pcActual != NULL))
    { 
        // caller only wants the count of configs.
        *pcActual = CfgsCount();
        return S_OK;
    }

    if ((pcActual == NULL) && (celt != 1))
        return E_INVALIDARG;

    ASSERT(celt != 0);
    if (rgpcfg == NULL)
        return E_POINTER;

    ULONG   cCfgsAvail = CfgsCount();

    for (ULONG i = 0; i < celt && i < cCfgsAvail; i++)
    {
        if (m_rgpProjectCfg[i])
            hr = m_rgpProjectCfg[i]->QueryInterface(
                IID_IVsCfg,
                (void**) &rgpcfg[cActual]);
        if (SUCCEEDED(hr) && (rgpcfg[cActual] != NULL))
            cActual++;
    }
    if (NULL != pcActual)
       *pcActual = cActual;
    return cActual ? S_OK : S_FALSE;
}

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
STDMETHODIMP CCfgProvider::OpenProjectCfg(
    /* [in] */LPCOLESTR szProjectCfgCanonicalName,
    /* [out]*/IVsProjectCfg **ppIVsProjectCfg)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::OpenProjectCfg /IVsProjectCfgProvider/ \n"));

    ExpectedPtrRet(szProjectCfgCanonicalName);
    ExpectedPtrRet(ppIVsProjectCfg);
    InitParam(ppIVsProjectCfg);

    for (int i = 0; i < CfgsCount(); i++)
    {
        CComBSTR  bstrName;
    
        if (m_rgpProjectCfg[i])
        {
            HRESULT hr = m_rgpProjectCfg[i]->get_CanonicalName(&bstrName);
            if (SUCCEEDED(hr) && (bstrName != NULL) && (wcscmp(bstrName, szProjectCfgCanonicalName) == 0))
            {
                return m_rgpProjectCfg[i]->QueryInterface(
                        IID_IVsProjectCfg,
                        (void**) ppIVsProjectCfg);
            }
        }
    }
    return E_INVALIDARG;
}

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
STDMETHODIMP CCfgProvider::get_UsesIndependentConfigurations( 
       /* [out] */ BOOL __RPC_FAR *pfUsesIndependentConfigurations)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::get_UsesIndependentConfigurations /IVsProjectCfgProvider/ \n"));

    ExpectedPtrRet(pfUsesIndependentConfigurations);
    *pfUsesIndependentConfigurations = TRUE; 
    return S_OK;
}
//                                                     IVsProjectCfgProvider
//==========================================================================



//==========================================================================
//                                                           IVsCfgProvider2
//--------------------------------------------------------------------------
//                                                 IVsCfgProvider2 interface


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
STDMETHODIMP CCfgProvider::GetCfgNames(
    /* [in]                     */  ULONG celt, 
    /* [in, out, size_is(celt)] */  BSTR  rgbstr[],
    /* [out, optional]          */  ULONG *pcActual)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::GetCfgNames /IVsCfgProvider2/ \n"));

    // parameters check
    if ((pcActual == NULL) && (rgbstr == NULL)) 
        return E_POINTER;
    if ((pcActual == NULL) && (celt == 0))
        return E_INVALIDARG;

    USHORT cCfgsAvail = CfgNamesCount();
    USHORT cActual = 0;

    if ((celt == 0) && (pcActual != NULL))
    { 
        // caller only wants the count of configs.
        *pcActual = cCfgsAvail;
        return S_OK;
    }

    ASSERT(celt != 0);
    if (rgbstr == NULL)
        return E_POINTER;

    for (USHORT i = 0; i < celt && i < cCfgsAvail; i++)
    {
        rgbstr[cActual++] = m_rgstrCfgNames[i].AllocSysString();
        if (!rgbstr[i]) cActual--;//something is wrong (out of memory)
    }

    if (NULL != pcActual)
       *pcActual = cActual;

    return cActual ? S_OK : S_FALSE;
};


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
STDMETHODIMP CCfgProvider::GetPlatformNames(
    /* [in]                     */ ULONG celt, 
    /* [in, out, size_is(celt)] */ BSTR rgbstr[], 
    /* [out, optional]          */ ULONG *pcActual)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::GetPlatformNames /IVsCfgProvider2/ \n"));

    // parameters check
    if ((pcActual == NULL) && (rgbstr == NULL)) 
        return E_POINTER;
    if ((pcActual == NULL) && (celt == 0))
        return E_INVALIDARG;

    USHORT cPlatformsAvail = PlatformNamesCount();

    if (! m_fHasPlatformName)
        cPlatformsAvail = 0;

    USHORT cActual = 0;

    if ((celt == 0) && (pcActual != NULL))
    { 
        // caller only wants the count of configs.
        *pcActual = cPlatformsAvail;
        return S_OK;
    }

    ASSERT(celt != 0);
    if (rgbstr == NULL)
        return E_POINTER;

    for (USHORT i = 0; i < celt && i < cPlatformsAvail; i++)
    {
        rgbstr[cActual++] = m_rgstrPlatformNames[i].AllocSysString();
        if (!rgbstr[i]) cActual--;//something is wrong (out of memory)
    }

    if (NULL != pcActual)
       *pcActual = cActual;

    return S_OK;
};


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
STDMETHODIMP CCfgProvider::GetCfgOfName(
    /* [in]  */ LPCOLESTR pszCfgName, 
    /* [in]  */ LPCOLESTR pszPlatformName, 
    /* [out] */ IVsCfg **ppCfg)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::GetCfgOfName /IVsCfgProvider2/ \n"));

    // check
    ExpectedPtrRet(pszCfgName);
    if (m_fHasPlatformName)
        ExpectedPtrRet(pszPlatformName);
    ExpectedPtrRet(ppCfg);
    InitParam(ppCfg);

    HRESULT hr = E_FAIL;
    CString strCfgName(pszCfgName);
    CString strPlatformName;
    if (m_fHasPlatformName)
        strPlatformName=pszPlatformName;

    CProjectCfg * pProjectCfg = NULL;

    pProjectCfg = GetMatchingCfg(strCfgName, strPlatformName);
    if (! pProjectCfg)
        return E_FAIL;

    hr = pProjectCfg->QueryInterface(IID_IVsCfg, (void **)(ppCfg));
    return hr;

};


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
STDMETHODIMP CCfgProvider::AddCfgsOfCfgName(
    /* [in] */ LPCOLESTR pszCfgName, 
    /* [in] */ LPCOLESTR pszCloneCfgName, 
    /* [in] */ BOOL fPrivate)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::AddCfgsOfCfgName /IVsCfgProvider2/ \n"));
 
    // param check
    ExpectedPtrRet(pszCfgName);

    HRESULT hr = E_FAIL;
    CString strCfgName(pszCfgName);
    CString strCloneCfgName;

    // Check if the CfgName already exists
    if (IsInCfgNames(strCfgName))
        return E_FAIL;

    // Check if the CloneCfgName already exists
    if (pszCloneCfgName)
    {
        strCloneCfgName = pszCloneCfgName;
        if (! IsInCfgNames(strCloneCfgName))
            return E_FAIL;
    }

    if ( !m_pHier->QueryEditProjectFile() )
		return E_ABORT;
    
    // create the project cfg for each platform
    CString       strPlatformName;
    CProjectCfg * pNewProjectCfg = NULL;

    for (USHORT i = 0; i< PlatformNamesCount(); i++)
    {
        strPlatformName = m_rgstrPlatformNames[i];
        hr = CreateProjectCfg(strCfgName, strPlatformName, &pNewProjectCfg);
        IfFailGo(hr);

        if (pszCloneCfgName)
        { 
            // we should clone
            // find the cfg to clone
            CProjectCfg * pCloneCfg = NULL;
            pCloneCfg = GetMatchingCfg(
                            strCloneCfgName, 
                            strPlatformName);
            if (!pCloneCfg)
            {
                hr = E_FAIL;
                goto Error;
            }

            hr = pCloneCfg->Clone(pNewProjectCfg);
            IfFailGo(hr);
        }
        pNewProjectCfg->Release();
    }


Error:
    if (FAILED(hr))
    {

        if (pNewProjectCfg)
            pNewProjectCfg->Release();

        // delete the cfgs created so far
        for (USHORT i = 0; i< PlatformNamesCount(); i++)
        {
            strPlatformName = m_rgstrPlatformNames[i];
            pNewProjectCfg = GetMatchingCfg(strCfgName, strPlatformName);
            if (pNewProjectCfg)
            {
                DeleteProjectCfg(pNewProjectCfg);
            }
        }
    }
    else
    {
        NotifyOnCfgNameAdded(pszCfgName);
		SetProjectFileDirty(TRUE); // dirty the project file 
    }
    return hr;
}


//----------------------------------------------------------------------
// Function: DeleteCfgsOfCfgName
//           Delete cfg objects for all supported platform 
//
// Parameters
//    /* [in] */ LPCOLESTR pszCfgName
// Returns:     HRESULT
// Notes:
//----------------------------------------------------------------------
STDMETHODIMP CCfgProvider::DeleteCfgsOfCfgName(
    /* [in] */ LPCOLESTR pszCfgName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::DeleteCfgsOfCfgName /IVsCfgProvider2/ \n"));

    // param check
    ExpectedPtrRet(pszCfgName);

    CString strCfgName(pszCfgName);
    // Check if the CfgName already exists
    if (! IsInCfgNames(strCfgName))
        return E_FAIL;

    if ( !m_pHier->QueryEditProjectFile() )
		return E_ABORT;

    // delete the project cfg for all platforms
    CString       strPlatformName;
    CProjectCfg * pProjectCfg = NULL;

    for (USHORT i = 0; i< PlatformNamesCount(); i++)
    {
        strPlatformName = m_rgstrPlatformNames[i];
        pProjectCfg = GetMatchingCfg(strCfgName, strPlatformName);
        if (pProjectCfg)
        {
            DeleteProjectCfg(pProjectCfg);
        }
    }

    NotifyOnCfgNameDeleted(pszCfgName);

    // Dirty the project file so that the configurations are deleted
	SetProjectFileDirty(TRUE);

    return S_OK;
}


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
STDMETHODIMP CCfgProvider::RenameCfgsOfCfgName(
    /* [in] */ LPCOLESTR pszOldName, 
    /* [in] */ LPCOLESTR pszNewName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::RenameCfgsOfCfgName /IVsCfgProvider2/ \n"));

    // param check
    ExpectedPtrRet(pszOldName);
    ExpectedPtrRet(pszNewName);

    HRESULT hr = E_FAIL;
    CString strOldCfgName(pszOldName);
    CString strNewCfgName(pszNewName);

    // Check if the new name already exists
    if (IsInCfgNames(strNewCfgName))
        return E_FAIL;

    // Check if the old name exists
    if (! IsInCfgNames(strOldCfgName))
        return E_FAIL;

    if ( !m_pHier->QueryEditProjectFile() )
		return E_ABORT;
    
    // rename the project cfg for each platform
    CString       strPlatformName;
    CProjectCfg * pProjectCfg = NULL;

    for (USHORT i = 0; i< PlatformNamesCount(); i++)
    {
        strPlatformName = m_rgstrPlatformNames[i];
        pProjectCfg = GetMatchingCfg(strOldCfgName, strPlatformName);
        if (pProjectCfg)
            pProjectCfg->RenameCfgName(strNewCfgName);
    }
    // delete the old name and add the new name
    CfgNamesDeleteName(strOldCfgName);
    CfgNamesAddName(strNewCfgName);

    // notify
    NotifyOnCfgNameRenamed(pszOldName, pszNewName);
	SetProjectFileDirty(TRUE); // dirty the project file 

    return S_OK;
};


//----------------------------------------------------------------------
// Function: AddCfgsOfPlatformName
// Parameters
//    /* [in] */ LPCOLESTR pszPlatformName, 
//    /* [in] */ LPCOLESTR pszClonePlatformName)
// Returns:     HRESULT
// Notes:
//----------------------------------------------------------------------
STDMETHODIMP CCfgProvider::AddCfgsOfPlatformName(
    /* [in] */ LPCOLESTR pszPlatformName, 
    /* [in] */ LPCOLESTR pszClonePlatformName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::AddCfgsOfPlatformName /IVsCfgProvider2/ \n"));
    return S_OK; // we should not be called
};


//----------------------------------------------------------------------
// Function: DeleteCfgsOfPlatformName
// Parameters
//    /* [in] */ LPCOLESTR pszPlatformName)
// Returns:     HRESULT
// Notes:
//----------------------------------------------------------------------
STDMETHODIMP CCfgProvider::DeleteCfgsOfPlatformName(
    /* [in] */ LPCOLESTR pszPlatformName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::DeleteCfgsOfPlatformName /IVsCfgProvider2/ \n"));
    return S_OK; // we should not be called
};


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
STDMETHODIMP CCfgProvider::GetSupportedPlatformNames(
    /* [in]                     */ ULONG celt, 
    /* [in, out, size_is(celt)] */ BSTR rgbstr[],
    /* [out, optional]          */ ULONG *pcActual)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::GetSupportedPlatformNames /IVsCfgProvider2/ \n"));
	
    // since we do not allow the user to add platforms, we return the 
    // same set as the one in the platform names - either nothing or "Win32"
    return GetPlatformNames(celt, rgbstr, pcActual);

};


//----------------------------------------------------------------------
// Function: GetCfgProviderProperty
// Parameters
//    /* [in]  */ VSCFGPROPID propid, 
//    /* [out] */ VARIANT *pvar)
// Returns:     HRESULT
// Notes:
//----------------------------------------------------------------------
STDMETHODIMP CCfgProvider::GetCfgProviderProperty(
    /* [in]  */ VSCFGPROPID propid, 
    /* [out] */ VARIANT *pvar)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::GetCfgProviderProperty /IVsCfgProvider2/ \n"));

    ExpectedPtrRet(pvar);

    pvar->vt = VT_BOOL;
    switch (propid)
    {
        case VSCFGPROPID_SupportsCfgEditing:
        case VSCFGPROPID_SupportsCfgAdd:
        case VSCFGPROPID_SupportsCfgDelete:
        case VSCFGPROPID_SupportsCfgRename:
        {
            pvar->boolVal = VARIANT_TRUE;
            break;
        }

        case VSCFGPROPID_SupportsPlatformEditing:
        case VSCFGPROPID_SupportsPlatformAdd:        
        case VSCFGPROPID_SupportsPrivateCfgs:
        case VSCFGPROPID_SupportsPlatformDelete:
        {
            pvar->boolVal = VARIANT_FALSE;
            break;
        }

        default:
        {
            pvar->boolVal = VARIANT_FALSE;
            ASSERT("Unknown VSCFGPROPID!!");
        }
    }

    return S_OK;
};


//----------------------------------------------------------------------
// Function: AdviseCfgProviderEvents
// Parameters
//    /* [in]  */ IVsCfgProviderEvents *pCPE, 
//    /* [out] */ DWORD *pdwCookie)
// Returns:     HRESULT
// Notes:
//----------------------------------------------------------------------
STDMETHODIMP CCfgProvider::AdviseCfgProviderEvents(
    /* [in]  */ IVsCfgProviderEvents *pCPE, 
    /* [out] */ VSCOOKIE *pdwCookie)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::AdviseCfgProviderEvents /IVsCfgProvider2/ \n"));

    ExpectedPtrRet(pCPE);
    ExpectedPtrRet(pdwCookie);
    InitParam(pdwCookie);

    HRESULT hr = E_FAIL;

    // Do not addref pCPE because SetAdvise() does so automatically
    hr = m_alCfgProviderEvents.SetAdvise(pCPE, pdwCookie);
    
    return hr;
}


//----------------------------------------------------------------------
// Function: UnadviseCfgProviderEvents
// Parameters
//    /* [in] */ DWORD dwCookie
// Returns:     HRESULT
// Notes:
//----------------------------------------------------------------------
STDMETHODIMP CCfgProvider::UnadviseCfgProviderEvents(
    /* [in] */ VSCOOKIE dwCookie)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::UnadviseCfgProviderEvents /IVsCfgProvider2/ \n"));
    
    // Do not release pCPE because Unadvise() does so automatically
    return m_alCfgProviderEvents.UnAdvise(dwCookie);
}


//----------------------------------------------------------------------
// Function:    CfgsCount
//              Get the number of currently existing cfg objects
//
// Parameters:  
//
// Returns:     The number of currently existing cfg objects
// Notes:
//----------------------------------------------------------------------
USHORT CCfgProvider::CfgsCount() const
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::CfgsCount \n"));

    return m_rgpProjectCfg.GetSize();
}


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
CCfgProvider::CProjectCfg* CCfgProvider::GetMatchingCfg(
    /* [in] */          const CString& strCfgName, 
    /* [in] */          const CString& strPlatformName)
{
    if (strCfgName.IsEmpty())
        return NULL;

    if (m_fHasPlatformName && strPlatformName.IsEmpty() )
        return NULL;

    CString strName = strCfgName;

    if (m_fHasPlatformName)
        strName = strName +"|"+strPlatformName;

    for (USHORT i = 0; i < CfgsCount(); i++)
    {
        CProjectCfg *pProjectCfg = m_rgpProjectCfg[i];

        if (pProjectCfg->GetName().CompareNoCase(strName) == 0)
        {
            return pProjectCfg;
        }
    }
    return NULL;
}


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
HRESULT CCfgProvider::CreateProjectCfg(
    /* [in]  */ const CString& strCfgName, 
    /* [in]  */ const CString& strPlatformName, 
    /* [out] */ CProjectCfg ** ppProjectCfg) 
{
    ExpectedPtrRet(ppProjectCfg);
    InitParam(ppProjectCfg);

    HRESULT hr = S_OK;
    BOOL    fNewCfgNameAdded = FALSE;
    CProjectCfg * pProjectCfg = NULL;
    
    hr = CComObject<CMyProjectCfg>::CreateInstance(&pProjectCfg);
    IfFailRet(hr);

    pProjectCfg->AddRef();
    hr = pProjectCfg->Init(m_pHier, strCfgName, strPlatformName);
    IfFailGo(hr);

    // add the cfg name
    hr = CfgNamesAddName(strCfgName);
    IfFailGo(hr);        
    fNewCfgNameAdded = (hr == S_OK);

    // add the platform name
    hr = PlatformNamesAddName(strPlatformName);
    IfFailGo(hr);

Error:
    if (FAILED(hr))
    {
        pProjectCfg->Release();
        if (fNewCfgNameAdded)
            CfgNamesDeleteName(strCfgName);
    }
    else
    {
        m_rgpProjectCfg.Add(pProjectCfg);
        *ppProjectCfg = pProjectCfg;
        pProjectCfg->AddRef();
    }

    return hr;
}

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
HRESULT CCfgProvider::DeleteProjectCfg(
    /* [in] */ CProjectCfg * pProjectCfg) 
{
    ExpectedPtrRet(pProjectCfg);

    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::DeleteProjectCfg \n"));

    for (USHORT i = 0 ; i < CfgsCount(); i++)
    {
        if (m_rgpProjectCfg[i] == pProjectCfg)
        {
            // get its full name
            CString strName = pProjectCfg->GetName();
            
            // release it
            pProjectCfg->Release();
            m_rgpProjectCfg.RemoveAt(i);
            
            // remove the cfg name if the deleted object was
            // the last one with such a name
            CString strCfgName;
            CString strPlatformName;
            HRESULT hr = SplitCfgPlatformName(strName, strCfgName, strPlatformName);
            IfFailRet(hr);
            
            BOOL fDeleteCfgName = TRUE;
            CString strNameT;
            CString strCfgNameT;
            CString strPlatformNameT;
            for (USHORT j = 0 ; j < CfgsCount(); j++)
            {
                if (m_rgpProjectCfg[j])
                {
                    strNameT = m_rgpProjectCfg[j]->GetName();
                    hr = SplitCfgPlatformName(strNameT, strCfgNameT, strPlatformNameT);
                    if (SUCCEEDED(hr) && strCfgName.CompareNoCase(strCfgNameT) == 0)
                    {
                        // we do not have to delete anything
                        fDeleteCfgName = FALSE;
                        break;
                    }
                }
            }
            if (fDeleteCfgName)
                CfgNamesDeleteName(strCfgName);
        }
    }

    return S_OK;
}

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
HRESULT CCfgProvider::SplitCfgPlatformName(
    const CString& strName,
    CString& strCfgName,
    CString& strPlatformName)
{

    WCHAR * pwch = NULL;

    CComBSTR cbstrName = strName.AllocSysString();
    if (! cbstrName)
        return E_OUTOFMEMORY;

    // find the '|' separating cfg & platform names
    pwch = wcschr(cbstrName, L'|');
    if (NULL != pwch)
    {
        // we have platform name
        *pwch++ = L'\0';
        strCfgName = cbstrName; 
        strPlatformName = pwch; 
        if (strPlatformName.IsEmpty()) return E_UNEXPECTED;
    }
    else
    {
        // we do not have platform name
        strCfgName = strName; 
        strPlatformName.Empty();
    }
    if (strCfgName.IsEmpty()) return E_UNEXPECTED;
    return S_OK;
}


//----------------------------------------------------------------------
// Function: CfgNamesCount
// Parameters
// Returns:  Returns the number of configuration names
// Notes:
//----------------------------------------------------------------------
USHORT CCfgProvider::CfgNamesCount() const
{
    return m_rgstrCfgNames.GetSize();
}


//----------------------------------------------------------------------
// Function: IsInCfgNames
//           Check if a configuration name exists in the array
// Parameters
//    /* [in] */ const CString& strCfgName
// Returns:  True if a configuration name exists in the array
// Notes:
//----------------------------------------------------------------------
BOOL CCfgProvider::IsInCfgNames(
    /* [in] */ const CString& strCfgName)
{
    for (USHORT i = 0; i< CfgNamesCount(); i++)
    {
        if (strCfgName.CompareNoCase(m_rgstrCfgNames[i]) == 0)
            return TRUE;
    }
    return FALSE;
}


//----------------------------------------------------------------------
// Function: CfgNamesAddName
//           Add a new configuration name to the array
// Parameters
//    /* [in] */ const CString& strCfgName
// Returns:  HRESULT
// Notes:
//----------------------------------------------------------------------
HRESULT CCfgProvider::CfgNamesAddName(
    /* [in] */ const CString& strCfgName)
{
    // check if the name is already added
    if (IsInCfgNames(strCfgName))
        return S_FALSE;
    
    m_rgstrCfgNames.Add(strCfgName);

    return S_OK;
}


//----------------------------------------------------------------------
// Function: CfgNamesDeleteName
//           Delete a new configuration name to the array
// Parameters
//    /* [in] */ const CString& strCfgName
// Returns:  HRESULT
// Notes:
//----------------------------------------------------------------------
HRESULT CCfgProvider::CfgNamesDeleteName(
    /* [in] */ const CString& strCfgName)
{
    for (USHORT i = 0; i < CfgNamesCount(); i++)
    {
        if (strCfgName.CompareNoCase(m_rgstrCfgNames[i]) == 0)
        {
            m_rgstrCfgNames.RemoveAt(i);
            return S_OK;
        }
    }
    return S_FALSE;
}
    

//----------------------------------------------------------------------
// Function: PlatformNamesCount
// Parameters
// Returns:  The number of platforms
// Notes:
//----------------------------------------------------------------------
USHORT CCfgProvider::PlatformNamesCount() const
{
    return m_rgstrPlatformNames.GetSize();
}


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
HRESULT CCfgProvider::PlatformNamesInit() 
{
    CString strPlatformName;
    if (m_fHasPlatformName)            
        strPlatformName = _T("Win32");// only Win32 is supported

    m_rgstrPlatformNames.Add(strPlatformName);
    
    return S_OK;
}


//----------------------------------------------------------------------
// Function: IsInPlatformNames
//           Check if a platform name exists in the array
// Parameters
//    /* [in] */ const CString& strPlatformName
// Returns:  True if the platform name exists in the array
// Notes:
//----------------------------------------------------------------------
BOOL CCfgProvider::IsInPlatformNames(
    /* [in] */ const CString& strPlatformName)
{
    for (USHORT i = 0; i< PlatformNamesCount(); i++)
    {
        if (strPlatformName.CompareNoCase(m_rgstrPlatformNames[i]) == 0)
            return TRUE;
    }
    return FALSE;
}

//----------------------------------------------------------------------
// Function: PlatformNamesAddName
//           Add a new platform name to the array
// Parameters
//    /* [in] */ const CString& strPlatformName
// Returns:  HRESULT
// Notes:
//----------------------------------------------------------------------
HRESULT CCfgProvider::PlatformNamesAddName(
    /* [in] */ const CString& strPlatformName)
{
    // check if the name is already added
    if (IsInPlatformNames(strPlatformName))
        return S_FALSE;
    
    m_rgstrPlatformNames.Add(strPlatformName);

    return S_OK;
}


//==========================================================================
//                                      IVsCfgProviderEventsHelper interface

// Defined in IVsCfgProvider2
// STDMETHOD(AdviseCfgProviderEvents)(
//    /* [in]  */ IVsCfgProviderEvents *pCPE, 
//    /* [out] */ DWORD *pdwCookie);

// Defined in IVsCfgProvider2
// STDMETHOD(UnadviseCfgProviderEvents)(
//    /*[in] */ DWORD dwCookie);


STDMETHODIMP CCfgProvider::NotifyOnCfgNameAdded(
    /* [in] */ LPCOLESTR pszCfgName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::NotifyOnCfgNameAdded /IVsCfgProviderEventsHelper/ \n"));

    HRESULT hrRet = S_OK;
    HRESULT hr;

    CVsAdviseListEnumerator<IVsCfgProviderEvents> adviseEnum(&m_alCfgProviderEvents);
    for (IVsCfgProviderEvents* pSink = adviseEnum.GetFirst(); 
         pSink != NULL; 
         pSink = adviseEnum.GetNext()) 
    {
        hr = pSink->OnCfgNameAdded(pszCfgName);
        if (FAILED(hr))
            hrRet = hr;
    }

    return hrRet;
}


STDMETHODIMP CCfgProvider::NotifyOnCfgNameDeleted(
    /* [in] */ LPCOLESTR pszCfgName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::NotifyOnCfgNameDeleted /IVsCfgProviderEventsHelper/ \n"));

    HRESULT hrRet = S_OK;
    HRESULT hr;

    CVsAdviseListEnumerator<IVsCfgProviderEvents> adviseEnum(&m_alCfgProviderEvents);
    for (   IVsCfgProviderEvents* pSink = adviseEnum.GetFirst(); 
            pSink != NULL; 
            pSink = adviseEnum.GetNext()) 
    {
        hr = pSink->OnCfgNameDeleted(pszCfgName);
        if (FAILED(hr))
            hrRet = hr;
    }

    return hrRet;
}


// note: if the rename operation is implemented as a clone & delete 
// fire the add/delete events instead of this one.
STDMETHODIMP CCfgProvider::NotifyOnCfgNameRenamed(
    /* [in] */ LPCOLESTR pszOldName, 
    /* [in] */ LPCOLESTR lszNewName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::NotifyOnCfgNameRenamed /IVsCfgProviderEventsHelper/ \n"));

    HRESULT hrRet = S_OK, hr;

    CVsAdviseListEnumerator<IVsCfgProviderEvents> adviseEnum(&m_alCfgProviderEvents);
    for (   IVsCfgProviderEvents* pSink = adviseEnum.GetFirst(); 
            pSink != NULL; 
            pSink = adviseEnum.GetNext()) 
    {
        hr = pSink->OnCfgNameRenamed(pszOldName, lszNewName);
        if (FAILED(hr))
            hrRet = hr;
    }

    return hrRet;
}

STDMETHODIMP CCfgProvider::NotifyOnPlatformNameAdded(
    /* [in] */ LPCOLESTR pszPlatformName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::NotifyOnPlatformNameAdded /IVsCfgProviderEventsHelper/ \n"));

    return E_NOTIMPL;
}

STDMETHODIMP CCfgProvider::NotifyOnPlatformNameDeleted(
    /* [in] */ LPCOLESTR pszPlatformName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CCfgProvider::NotifyOnPlatformNameDeleted /IVsCfgProviderEventsHelper/ \n"));

    return E_NOTIMPL;
}

//                                      IVsCfgProviderEventsHelper interface
//==========================================================================


