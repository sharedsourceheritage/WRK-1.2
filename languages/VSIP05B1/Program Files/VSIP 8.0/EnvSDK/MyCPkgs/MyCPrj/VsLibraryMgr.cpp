
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

/***                              
*  VsLibraryMgr.cpp
*****************************************************************************/


#include "stdafx.h"
#include "PrjInc.h"


//==========================================================================
//                                                construct, init , destruct
//
HRESULT CVsLibraryMgr::CreateInstance( 
        /* [out] */ IVsLibraryMgr**   ppIVsLibraryMgr)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibraryMgr::CreateInstance \n"));

    ExpectedPtrRet(ppIVsLibraryMgr);
    InitParam(ppIVsLibraryMgr);

    CComObject<CVsLibraryMgr>* pco = NULL;
    HRESULT hr = CComObject<CVsLibraryMgr>::CreateInstance(&pco);
    IfFailRet(hr);

    ASSERT(pco != NULL);
    pco->AddRef();
    hr = pco->Init();
    IfFailGo(hr);

    hr = pco->QueryInterface(
                IID_IVsLibraryMgr, 
                (void**)ppIVsLibraryMgr);

Error:
    if (pco)
        pco->Release();

    return hr;
}


CVsLibraryMgr::CVsLibraryMgr() 
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CVsLibraryMgr::CVsLibraryMgr , this = 0x%x \n"), this );
}


HRESULT CVsLibraryMgr::Init()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibraryMgr::Init , this = 0x%x \n"), this );

    HRESULT hr = S_OK;

    //Create a project library
    CComPtr<ILibrary> srpILibrary;
    hr = CVsLibrary::CreateInstance(&srpILibrary);
    IfFailRet(hr);
 
    m_rgpILibrary.Add(srpILibrary.Detach());

    return hr;
}


CVsLibraryMgr::~CVsLibraryMgr()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CVsLibraryMgr::~CVsLibraryMgr , this = 0x%x \n"), this );
    
    Close();
}



STDMETHODIMP CVsLibraryMgr::Close()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibraryMgr::Close , this = 0x%x \n"), this );


    // release the lib array
    ULONG cLibrary;
    GetCount(&cLibrary);
    for (ULONG uIndex = 0; uIndex < cLibrary; uIndex++)
    {
        m_rgpILibrary[uIndex]->Close();
        m_rgpILibrary[uIndex]->Release();
    }
    m_rgpILibrary.RemoveAll();

    return S_OK;
}


//
//                                                construct, init , destruct
//==========================================================================


STDMETHODIMP_(BOOL) CVsLibraryMgr::IsValidIndex(
    /* [in] */ ULONG uIndex)
{
    ULONG cLibrary;
    GetCount(&cLibrary);

    if (uIndex < cLibrary)
        return TRUE;
    else
        return FALSE;
};


//==========================================================================
//                                                            IVsLibraryMgr
//

HRESULT CVsLibraryMgr::GetCount(
            /* [out, retval] */ ULONG *pnCount)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibraryMgr::GetCount /IVsLibraryMgr/ , this = 0x%x \n"), this );

    ExpectedPtrRet(pnCount);

    *pnCount = m_rgpILibrary.GetSize();
    return S_OK;
}


HRESULT CVsLibraryMgr::GetLibraryAt(
            /* [in]          */ ULONG         uIndex, 
            /* [out, retval] */ IVsLibrary ** ppLibrary)
{    
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibraryMgr::GetLibraryAt /IVsLibraryMgr/ , this = 0x%x \n"), this );

    ExpectedPtrRet(ppLibrary);
    InitParam(ppLibrary);

    //Make sure that we have the library that is being requested
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    return m_rgpILibrary[uIndex]->QueryInterface(
                                        IID_IVsLibrary,
                                        (void**) ppLibrary);
}


HRESULT CVsLibraryMgr::GetNameAt(
            /* [in]          */ ULONG    uIndex, 
            /* [out, retval] */ WCHAR ** pszName)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibraryMgr::GetNameAt /IVsLibraryMgr/ , this = 0x%x \n"), this );
    ExpectedPtrRet(pszName);
    InitParam(pszName);

    //Make sure that we have the library that is being requested
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    return m_rgpILibrary[uIndex]->GetName(pszName);
}


HRESULT CVsLibraryMgr::ToggleCheckAt(
            /* [in] */ ULONG uIndex)
{  
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibraryMgr::ToggleCheckAt /IVsLibraryMgr/ , this = 0x%x \n"), this );
   
    //Make sure that we have the library that is being requested
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    m_rgpILibrary[uIndex]->ToggleCheck();  

    return S_OK;
}


HRESULT CVsLibraryMgr::GetCheckAt(
            /* [in] */          ULONG           uIndex, 
            /* [out, retval] */ LIB_CHECKSTATE *pstate)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsLibraryMgr::GetCheckAt /IVsLibraryMgr/ , this = 0x%x \n"), this );

    ExpectedPtrRet(pstate);

    //Make sure that we have the library that is being requested
    if (! IsValidIndex(uIndex))
        return E_UNEXPECTED;

    return m_rgpILibrary[uIndex]->GetCheckState(pstate);
}


HRESULT CVsLibraryMgr::SetLibraryGroupEnabled(
            /* [in] */ LIB_PERSISTTYPE lpt, 
            /* [in] */ BOOL fEnable)
{
    ATLTRACENOTIMPL(
                    _T(": CVsLibraryMgr::SetLibraryGroupEnabled /IVsLibraryMgr/ "));
}




//
//                                                            IVsLibraryMgr
//==========================================================================

