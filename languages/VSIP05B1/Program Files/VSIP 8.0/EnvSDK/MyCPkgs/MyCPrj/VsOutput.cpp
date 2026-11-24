
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsOutput.cpp: implementation of the CVsOutput class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PrjInc.h" 


HRESULT CVsOutput::CreateInstance(
        /* [in]  */ IVsProjectCfg* pIVsProjectCfg, 
        /* [in]  */ const CString& strAbsPath,
        /* [out] */ IVsOutput2 **  ppIVsOutput2)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutput::CreateInstance \n"));

    ExpectedPtrRet(pIVsProjectCfg);
    if(strAbsPath.IsEmpty())
        return E_INVALIDARG;
    ExpectedPtrRet(ppIVsOutput2);
    *ppIVsOutput2 = NULL;

    CComObject<CVsOutput>* pCVsOutput = NULL;
    HRESULT hr = CComObject<CVsOutput>::CreateInstance(&pCVsOutput);
    IfFailRet(hr);

    pCVsOutput->AddRef();
    hr = pCVsOutput->Init(pIVsProjectCfg, strAbsPath);
    IfFailGo(hr);

    hr = pCVsOutput->QueryInterface(IID_IVsOutput2, (void**)ppIVsOutput2);

Error:
    if (pCVsOutput)
        pCVsOutput->Release();
    return hr;
}


CVsOutput::CVsOutput()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC,  
        _T(": CVsOutput::CVsOutput this = 0x%x\n"), this);

    // m_srpIVsProjectCfg
    // m_strAbsPath
}


HRESULT CVsOutput::Init(
    /* [in] */ IVsProjectCfg *pIVsProjectCfg , 
    /* [in] */ const CString& strAbsPath)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutput::Init this = 0x%x\n"), this);

    ExpectedPtrRet(pIVsProjectCfg);
    if(strAbsPath.IsEmpty())
        return E_INVALIDARG;

    m_srpIVsProjectCfg = pIVsProjectCfg;
    m_strAbsPath = strAbsPath;
    return S_OK;
}


void CVsOutput::Term()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutput::Term this = 0x%x\n"), this);

    // m_srpIVsProjectCfg
    // m_strAbsPath
}


CVsOutput::~CVsOutput()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD,  
        _T(": CVsOutput::~CVsOutput this = 0x%x\n"), this);

    Term();
}


STDMETHODIMP CVsOutput::get_DisplayName(
    /*[out]*/ BSTR *pbstrDisplayName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutput::get_DisplayName /IVsOutput/ this = 0x%x\n"), this);

    return get_CanonicalName(pbstrDisplayName);
}


STDMETHODIMP CVsOutput::get_CanonicalName(
    /*[out]*/ BSTR *pbstrCanonicalName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutput::get_CanonicalName /IVsOutput/ this = 0x%x\n"), this);

    ExpectedPtrRet(pbstrCanonicalName);
    ASSERT(!m_strAbsPath.IsEmpty());

    *pbstrCanonicalName = m_strAbsPath.AllocSysString();

    return (*pbstrCanonicalName) ? S_OK : E_OUTOFMEMORY;
}


STDMETHODIMP CVsOutput::get_DeploySourceURL(
    /*[out]*/ BSTR *pbstrDeploySourceURL)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutput::get_DeploySourceURL /IVsOutput/ this = 0x%x\n"), this);

    ExpectedPtrRet(pbstrDeploySourceURL);
    ASSERT(!m_strAbsPath.IsEmpty());

    CString strDeploy(_T("file:///"));
    strDeploy += m_strAbsPath;
 
    *pbstrDeploySourceURL = strDeploy.AllocSysString();
    return (*pbstrDeploySourceURL) ? S_OK : E_OUTOFMEMORY;
}


STDMETHODIMP CVsOutput::get_Type(
        /*[out]*/ GUID *pguidType)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutput::get_Type /IVsOutput/ this = 0x%x\n"), this);

    ExpectedPtrRet(pguidType);
    *pguidType = GUID_NULL;
    return S_OK;
}


STDMETHODIMP CVsOutput::get_RootRelativeURL(
    /* [out] */ BSTR *pbstrRelativePath) 
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutput::get_RootRelativeURL /IVsOutput2/ this = 0x%x\n"), this);

    ExpectedPtrRet(pbstrRelativePath);
    ASSERT(!m_strAbsPath.IsEmpty());

    HRESULT hr = S_OK;
    *pbstrRelativePath = SysAllocString(L".");
    return (*pbstrRelativePath) ? S_OK : E_OUTOFMEMORY;

}


// full path to the output (VT_BSTR)
const WCHAR g_wszOutputPath[] = L"PrimaryOutputPath";

STDMETHODIMP CVsOutput::get_Property(
    /* [in]  */ LPCOLESTR szProperty,
    /* [out] */ VARIANT*  pvar)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutput::get_Property /IVsOutput2/ this = 0x%x\n"), this);

    ExpectedPtrRet(pvar);
    VariantInit(pvar);
    
    HRESULT hr = S_OK;

    if (_wcsicmp(szProperty, g_wszOutputPath) == 0)
    {
        pvar->vt = VT_BSTR;
        pvar->bstrVal = m_strAbsPath.AllocSysString();
        if (pvar->bstrVal == NULL)
            hr = E_OUTOFMEMORY;
    }
    else
    {
        hr = E_INVALIDARG;
    }

    return hr;
}

