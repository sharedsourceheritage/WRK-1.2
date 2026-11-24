
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsOutputGroup.cpp: implementation of the CVsOutputGroup class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PrjInc.h" 


/****************************************************************************\
**
**  CVsEnumOutputs
**
\****************************************************************************/
HRESULT CVsEnumOutputs::CreateInstance(
        /* [in]  */ IVsProjectCfg2* pIVsProjectCfg2,
        /* [in]  */ ULONG uOutput,
        /* [out] */ IVsEnumOutputs** ppIVsEnumOutputs)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsEnumOutputs::CreateInstance \n"));

    ExpectedPtrRet(pIVsProjectCfg2);
    ExpectedPtrRet(ppIVsEnumOutputs);
    InitParam(ppIVsEnumOutputs);

    CComObject<CVsEnumOutputs>* pCVsEnumOutputs = NULL;
    HRESULT hr = CComObject<CVsEnumOutputs>::CreateInstance(&pCVsEnumOutputs);
    IfFailRet(hr);

    pCVsEnumOutputs->AddRef();
    hr = pCVsEnumOutputs->Init(pIVsProjectCfg2, uOutput);
    IfFailGo(hr);

    hr = pCVsEnumOutputs->QueryInterface(
        IID_IVsEnumOutputs, 
        (void**)ppIVsEnumOutputs);

Error:
    if (pCVsEnumOutputs)
        pCVsEnumOutputs->Release();

    return hr;
}



HRESULT CVsEnumOutputs::Init(
        /* [in] */ IVsProjectCfg2* pIVsProjectCfg2,
        /* [in] */ ULONG uOutput)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsEnumOutputs::Init this = 0x%x \n"), this);

    ExpectedPtrRet(pIVsProjectCfg2);
    HRESULT hr;

    m_srpIVsProjectCfg2 = pIVsProjectCfg2;

    // init the array
    CComPtr<CMyProjectCfg> srpCMyProjectCfg;
    hr = m_srpIVsProjectCfg2->QueryInterface(
                            IID_CMyProjectCfg,
                            (void**)&srpCMyProjectCfg);
    IfFailRet(hr);

    hr = srpCMyProjectCfg->AddAllOutputsToArray(
                            &m_rgpIVsOutput2);
    IfFailRet(hr);
 
    m_uOutput = uOutput;
    ULONG cOutputs = m_rgpIVsOutput2.GetSize();
    if (m_uOutput >= cOutputs)
        return E_INVALIDARG;

    return hr;
}


CVsEnumOutputs::~CVsEnumOutputs()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD,   
        _T(": CVsEnumOutputs::~CVsEnumOutputs this = 0x%x \n"), this);
    
    // m_srpIVsProjectCfg2
    Term();
}


void CVsEnumOutputs::Term()
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


HRESULT CVsEnumOutputs::Reset()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsEnumOutputs::Reset /IVsEnumOutputs/ this = 0x%x \n"), this);

    m_uOutput = 0;
    return S_OK;
}


HRESULT CVsEnumOutputs::Next(
        /* [in]                          */ ULONG cElements, 
        /* [in, out, size_is(cElements)] */ IVsOutput * rgpIVsOutput[], 
        /* [out, optional]               */ ULONG * pcElementsFetched)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsEnumOutputs::Next /IVsEnumOutputs/ this = 0x%x \n"), this);


    HRESULT hr = S_OK;
    ULONG   i;
    ULONG   cOutputs = m_rgpIVsOutput2.GetSize();

    ExpectedPtrRet(rgpIVsOutput);
    for (i = 0; i < cElements; i++)
        rgpIVsOutput[i] = NULL;

    for (i = 0; i < cElements && m_uOutput < cOutputs; i++, m_uOutput++)
    {
        IVsOutput2* pIVsOutput2 =  m_rgpIVsOutput2[i];
        rgpIVsOutput[i] = pIVsOutput2;
        pIVsOutput2->AddRef();
    }

    if (pcElementsFetched)
        *pcElementsFetched = i;

    hr = (i == cElements) ? S_OK : S_FALSE;

    return hr;
}


HRESULT CVsEnumOutputs::Skip(
    /* [in] */ ULONG cElements)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsEnumOutputs::Skip /IVsEnumOutputs/ this = 0x%x \n"), this);

    HRESULT hr = S_OK;
    m_uOutput += cElements;
    ULONG   cOutputs = m_rgpIVsOutput2.GetSize();
    
    if (m_uOutput > cOutputs)
    {
        m_uOutput = cOutputs;
        hr = S_FALSE;
    }
    return hr;
}



HRESULT CVsEnumOutputs::Clone(
        /* [out] */ IVsEnumOutputs ** ppIVsEnumOutputs)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF,  
        _T(": CVsEnumOutputs::Clone /IVsEnumOutputs/ this = 0x%x \n"), this);

    return CVsEnumOutputs::CreateInstance(
                                m_srpIVsProjectCfg2,
                                m_uOutput,
                                ppIVsEnumOutputs);
}

