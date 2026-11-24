
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsOutputGroup.cpp: implementation of the CVsOutputGroup class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VsOutputGroup.h"
#include "projcfg.h"
#include "vsmem.h"

//  These are the canonical names for output groups.  
//  Canonical names must not be localized!  Using these
//  canonical names allows projects to ask for specific types of outputs.
//  Users do not see these canonical names -- they see the display names
//  and description fields instead -- so you can still "localize" your output
//  groups visually as required.
//  These names are Unicode, since typically they are passed as LPCOLESTR 
//  arguments to COM methods.
#ifndef VS_OUTPUTGROUP_CNAME_Built
#define VS_OUTPUTGROUP_CNAME_Built                  L"Built"
#endif

#ifndef VS_OUTPUTGROUP_CNAME_ContentFiles
#define VS_OUTPUTGROUP_CNAME_ContentFiles           L"ContentFiles"
#endif

#ifndef VS_OUTPUTGROUP_CNAME_LocalizedResourceDlls
#define VS_OUTPUTGROUP_CNAME_LocalizedResourceDlls  L"LocalizedResourceDlls"
#endif

#ifndef VS_OUTPUTGROUP_CNAME_SourceFiles
#define VS_OUTPUTGROUP_CNAME_SourceFiles            L"SourceFiles"
#endif

#ifndef VS_OUTPUTGROUP_CNAME_Documentation
#define VS_OUTPUTGROUP_CNAME_Documentation          L"Documentation"
#endif

HRESULT CVsOutputGroup::CreateInstance(
        /* [in]  */ IVsProjectCfg2*  pIVsProjectCfg2, 
        /* [in]  */ OUTPUTGROUPTYPE  ogt,
        /* [out] */ IVsOutputGroup** ppIVsOutputGroup)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutputGroup::CreateInstance \n"));

    ExpectedPtrRet(pIVsProjectCfg2);
    ExpectedPtrRet(ppIVsOutputGroup);
    *ppIVsOutputGroup = NULL;

    CComObject<CVsOutputGroup>* pCVsOutputGroup = NULL;
    HRESULT hr = CComObject<CVsOutputGroup>::CreateInstance(&pCVsOutputGroup);
    IfFailRet(hr);

    pCVsOutputGroup->AddRef();
    hr = pCVsOutputGroup->Init(pIVsProjectCfg2, ogt);
    IfFailGo(hr);

    hr = pCVsOutputGroup->QueryInterface(
        IID_IVsOutputGroup, 
        (void**)ppIVsOutputGroup);

Error:
    if (pCVsOutputGroup)
        pCVsOutputGroup->Release();

    return hr;
}


CVsOutputGroup::CVsOutputGroup()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC,  
        _T(": CVsOutputGroup::CVsOutputGroup this = 0x%x\n"), this);

    // m_srpIVsProjectCfg2
    m_ogt = OGT_None;
    m_fOutputsAdded = FALSE; // will add the outputs later - when asked
}


HRESULT CVsOutputGroup::Init(
        /* [in] */ IVsProjectCfg2*  pProjectCfg,
        /* [in] */ OUTPUTGROUPTYPE ogt)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutputGroup::Init this = 0x%x\n"), this);

    ExpectedPtrRet(pProjectCfg);
    m_srpIVsProjectCfg2 = pProjectCfg;
    m_ogt = ogt;
    m_fOutputsAdded = FALSE; // will add the outputs later - when asked

    HRESULT hr;
    switch(ogt)
    {
        case OGT_Built:
        case OGT_SourceFiles:
            hr = S_OK;
            break;
        default:
            ASSERT(FALSE);
            hr = E_FAIL;
            break;
    }

    return hr;
}


CVsOutputGroup::~CVsOutputGroup()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD,  
        _T(": CVsOutputGroup::~CVsOutputGroup this = 0x%x\n"), this);
    Term();
}


void CVsOutputGroup::Term()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsOutputGroup::Term this = 0x%x\n"), this);

    int cOutputs = m_rgpIVsOutput2.GetSize();
    for (int i = 0; i < cOutputs; i++)
    {
        IVsOutput2* pIVsOutput2 =  m_rgpIVsOutput2[i];
        if (pIVsOutput2)
            pIVsOutput2->Release();
    }

    // remove all from the array.
    m_rgpIVsOutput2.RemoveAll();

    // m_srpIVsProjectCfg
}


STDMETHODIMP CVsOutputGroup::get_CanonicalName(
        /* [out] */ BSTR *pbstrCanonicalName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutputGroup::get_CanonicalName /IVsOutputGroup/ this = 0x%x \n"), this);

    ExpectedPtrRet(pbstrCanonicalName);
    InitParam(pbstrCanonicalName);

    return GetCanonicalNameFromOgt(m_ogt, pbstrCanonicalName);
}


STDMETHODIMP CVsOutputGroup::get_DisplayName(
    /* [out] */ BSTR *pbstrDisplayName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutputGroup::get_DisplayName /IVsOutputGroup/ this = 0x%x \n"), this);

    ExpectedPtrRet(pbstrDisplayName);
    *pbstrDisplayName = NULL;

    HRESULT hr;
    CString strName;
    hr = GetDisplayNameFromOgt(m_ogt, strName);
    IfFailRet(hr);

    if (!strName.IsEmpty())
        *pbstrDisplayName = strName.AllocSysString();
    return (*pbstrDisplayName) ? S_OK : E_OUTOFMEMORY;
}


STDMETHODIMP CVsOutputGroup::get_KeyOutput(
    /* [out] */ BSTR *pbstrCanonicalName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutputGroup::get_KeyOutput /IVsOutputGroup/ this = 0x%x \n"), this);

    ExpectedPtrRet(pbstrCanonicalName);
    InitParam(pbstrCanonicalName);

    HRESULT hr;

    CComPtr<CMyProjectCfg> srpCMyProjectCfg;
    hr = m_srpIVsProjectCfg2->QueryInterface(
                            IID_CMyProjectCfg,
                            (void**)&srpCMyProjectCfg);
    IfFailRet(hr);

    return srpCMyProjectCfg->get_OgtKeyOutput(m_ogt, pbstrCanonicalName);
}


STDMETHODIMP CVsOutputGroup::get_ProjectCfg(
    /* [out] */ IVsProjectCfg2 ** ppIVsProjectCfg2)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutputGroup::get_ProjectCfg /IVsOutputGroup/ this = 0x%x \n"), this);

    return m_srpIVsProjectCfg2.CopyTo(ppIVsProjectCfg2);
}


STDMETHODIMP CVsOutputGroup::get_Outputs(
    /* [in]                     */ ULONG celt,
    /* [in, out, size_is(celt)] */ IVsOutput2* rgpIVsOutput2[],
    /* [out, optional]          */ ULONG *pcActual)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutputGroup::get_Outputs /IVsOutputGroup/ this = 0x%x \n"), this);

    HRESULT hr = S_OK;

    // create the outputs if not created
    if (! m_fOutputsAdded)
    {
        m_fOutputsAdded = TRUE;
        CComPtr<CMyProjectCfg> srpCMyProjectCfg;
        hr = m_srpIVsProjectCfg2->QueryInterface(
                                IID_CMyProjectCfg,
                                (void**)&srpCMyProjectCfg);

        IfFailRet(hr);

        hr = srpCMyProjectCfg->AddOgtOutputsToArray(m_ogt, &m_rgpIVsOutput2);
        IfFailRet(hr);
    }

    ULONG   i;
    ULONG   cOutputs = m_rgpIVsOutput2.GetSize();

    // if caller wants only the count
    if (celt == 0)
    {
        ASSERT(rgpIVsOutput2 == NULL);
        ASSERT(pcActual);
        if (pcActual)
            *pcActual = cOutputs;
        return pcActual ? S_OK : E_INVALIDARG;
    }

    ExpectedPtrRet(rgpIVsOutput2);
    for (i = 0; i < celt; i++)
        rgpIVsOutput2[i] = NULL;

    for (i = 0; i < celt && i < cOutputs; i++)
    {
        IVsOutput2* pIVsOutput2 =  m_rgpIVsOutput2[i];
        if (pIVsOutput2 == NULL)
        {
            ASSERT(FALSE);
            hr = E_FAIL;
            goto Error;
        }

        rgpIVsOutput2[i] = pIVsOutput2;
        rgpIVsOutput2[i]->AddRef();
    }

Error:
    if (FAILED(hr))
    {
        for (ULONG j = 0; j < i; j++)
        {
            if(rgpIVsOutput2[j])
            {
                rgpIVsOutput2[j]->Release();
                rgpIVsOutput2[j]=NULL;
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


STDMETHODIMP CVsOutputGroup::get_DeployDependencies(
    /* [in]                     */ ULONG celt,
    /* [in, out, size_is(celt)] */ IVsDeployDependency * rgpdpd[],
    /* [out, optional]          */ ULONG *pcActual)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutputGroup::get_DeployDependencies /IVsOutputGroup/ this = 0x%x \n"), this);

    _ASSERTE(pcActual);
    if (pcActual == NULL)
        return E_INVALIDARG;

    *pcActual = 0;

    // if the output group have any dependencies return them here
    return S_OK;
}


STDMETHODIMP CVsOutputGroup::get_Description(
    /* [out] */ BSTR *pbstrDescription)
{
    // localized description to be loaded here
    // we just return the display name
    return get_DisplayName(pbstrDescription);
}


HRESULT CVsOutputGroup::GetCanonicalNameFromOgt(
        /* [in]  */ OUTPUTGROUPTYPE ogt, 
        /* [out] */ BSTR* pbstrName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutputGroup::GetCanonicalNameFromOgt \n"));

    ExpectedPtrRet(pbstrName);
    InitParam(pbstrName);

    switch(ogt)
    {
        case OGT_Built :
            *pbstrName = ::SysAllocString(VS_OUTPUTGROUP_CNAME_Built);
            break;
        case OGT_ContentFiles: 
            *pbstrName = ::SysAllocString(VS_OUTPUTGROUP_CNAME_ContentFiles);
            break;
        case OGT_LocalizedResourceDlls:
            *pbstrName = ::SysAllocString(VS_OUTPUTGROUP_CNAME_LocalizedResourceDlls);
            break;
        case OGT_SourceFiles:
            *pbstrName = ::SysAllocString(VS_OUTPUTGROUP_CNAME_SourceFiles);
            break;
        default:
            ASSERT(FALSE);
            return E_INVALIDARG;
    }
    return (*pbstrName) ? S_OK : E_OUTOFMEMORY;
}


HRESULT CVsOutputGroup::GetDisplayNameFromOgt(
        /* [in]  */ OUTPUTGROUPTYPE ogt, 
        /* [out] */ CString& strName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsOutputGroup::GetDisplayNameFromOgt this = 0x%x \n"), this);

    int ids;

    HRESULT hr = E_FAIL;;
    strName.Empty();
    switch(ogt)
    {
        case OGT_Built :
            ids = IDS_OUTPUTGROUP_EXECUTABLES;
            break;
        case OGT_ContentFiles: 
            ids = IDS_OUTPUTGROUP_CONTENTFILES;
            break;
        case OGT_LocalizedResourceDlls:
            ids = IDS_OUTPUTGROUP_SATELLITEDLLS;
            break;
        case OGT_SourceFiles:
            ids = IDS_OUTPUTGROUP_SOURCEFILES;
            break;
        default:
            ASSERT(FALSE);
            goto Error;
    }

    // load string from the resource file
    strName.LoadString(ids);
    if (strName.IsEmpty())
        hr = E_OUTOFMEMORY;
    else
        hr = S_OK;
Error:
    return hr;
}



