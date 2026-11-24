
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsProjectStartupServices.cpp :

#include "stdafx.h"
#include "PrjInc.h"
#include "VsProjectStartupServices.h"
#include "vsmem.h"


HRESULT CGuid::CreateInstance(
    /* [in]  */ REFGUID guid,
    /* [out] */ CGuid** ppCGuid)
{
    ExpectedPtrRet(ppCGuid);
    InitParam(ppCGuid);
 
    CGuid* pCGuid = new CGuid(guid);
    if (!pCGuid)
        return E_OUTOFMEMORY;
    pCGuid->AddRef();
    *ppCGuid = pCGuid;
    return S_OK;
}

CGuid::CGuid()             
{
    m_guid = GUID_NULL; 
    m_dwRef = 0;
}

CGuid::CGuid(REFGUID guid) 
{
    m_guid = guid; 
    m_dwRef = 0;
}

REFGUID CGuid::GetGuid()
{
    return m_guid;
}

ULONG CGuid::AddRef()
{
    ++m_dwRef;	
    return(m_dwRef);
}

ULONG   CGuid::Release()           
{
    --m_dwRef;	
    if( m_dwRef == 0 ) 
    {
        delete this; 
        return 0;
    } 
    return m_dwRef;
}


/****************************************************************************\
** 
**  CProjectStartupService
**
\****************************************************************************/
HRESULT CProjectStartupService::CreateInstance(
        /* [in]  */ REFGUID guid,
        /* [out] */ CProjectStartupService** ppService)
{
    ExpectedPtrRet(ppService);
    InitParam(ppService);

    CProjectStartupService* pService = new CProjectStartupService();
    if (!pService)
        return E_OUTOFMEMORY;

    HRESULT hr = pService->Init(guid);
    if (FAILED(hr))
    {
        delete pService;
        pService = NULL;
    }

    *ppService = pService;
    return hr;
}

CProjectStartupService::CProjectStartupService() 
{
    m_pguidService = NULL;
}

HRESULT CProjectStartupService::Init(REFGUID guid)
{
    if (guid == GUID_NULL)
        return E_INVALIDARG;

    return CGuid::CreateInstance(guid, &m_pguidService);
}

CProjectStartupService::~CProjectStartupService()
{
    StopService();
    if (m_pguidService)
        m_pguidService->Release();
}


HRESULT CProjectStartupService::StartService()
{
    HRESULT hr = S_FALSE;
    
    if ( (m_pguidService  != NULL) && 
         (GetGuid() != GUID_NULL)  && 
         (m_srpUnkService == NULL) ) 
    {
        hr = _VxModule.QueryService(
                GetGuid(), 
                IID_IUnknown, 
                (void**)&m_srpUnkService);
            
        if (FAILED(hr))
        {
            m_srpUnkService = NULL;
        }
    }

    return hr;
}

 
HRESULT CProjectStartupService::StopService()
{
    m_srpUnkService.Release();
    return S_OK;
}


REFGUID CProjectStartupService::GetGuid() 
{ 
    ASSERT(m_pguidService);
    return m_pguidService->GetGuid(); 
}

CGuid* CProjectStartupService::GetCGuid() 
{ 
    return m_pguidService; 
}

/****************************************************************************\
**
**  CVsProjectStartupServices
**
\****************************************************************************/
//==========================================================================
//                                                               static data
//
const LPCWSTR CVsProjectStartupServices::ms_pszKey_ID = L"ID";
//
//                                                               static data
//==========================================================================


//==========================================================================
//                                                construct, init , destruct

CVsProjectStartupServices::CVsProjectStartupServices()
{
}


CVsProjectStartupServices::~CVsProjectStartupServices()
{
    ULONG cPss = m_rgpCProjectStartupService.GetSize();
    for(ULONG uIndex=0; uIndex < cPss; uIndex++)
    {
        CProjectStartupService* pPss = m_rgpCProjectStartupService.GetAt(uIndex);
        ASSERT(pPss != NULL);

        if (pPss != NULL)
            delete pPss;
    }
    m_rgpCProjectStartupService.RemoveAll();
}

//                                                construct, init , destruct
//==========================================================================


//==========================================================================
//                                                 IVsProjectStartupServices
//
STDMETHODIMP CVsProjectStartupServices::AddStartupService(
    /*[in]*/ REFGUID guidService)
{
    // Dont' add null-guids
    if (guidService == GUID_NULL)
        return E_INVALIDARG;

    //  If the services is already in the list, succeed with S_FALSE.
    if (Find(guidService) == S_OK)
        return S_FALSE;

    // Create the new startup service object. Don't start it.
    CProjectStartupService* pCProjectStartupService = NULL;
    HRESULT hr = CProjectStartupService::CreateInstance(
                    guidService, 
                    &pCProjectStartupService);
    IfFailRet(hr);
    ASSERT(pCProjectStartupService != NULL);
    
    // Add the service to the array, but don't start
    // the service yet. You must call 
    // StartServices to startup the service.
    m_rgpCProjectStartupService.Add(pCProjectStartupService); 

    return S_OK;
}

// Removes a service id GUID from the array.
// Releases the service if it has been loaded.
// 
STDMETHODIMP CVsProjectStartupServices::RemoveStartupService(
    /*[in]*/ REFGUID guidService)
{
    HRESULT hr = S_OK;
    ULONG   uIndex = 0;
    
    hr = Find(guidService, &uIndex);
    if (hr == S_OK)
    {
        CProjectStartupService* pPss = m_rgpCProjectStartupService.GetAt(uIndex);
        ASSERT(pPss != NULL);
        if (pPss != NULL)
        {
            // Release the service. Destructor will release the service.
            delete pPss;
        }
        
        m_rgpCProjectStartupService.RemoveAt(uIndex); 
    }

    return hr;
}


STDMETHODIMP CVsProjectStartupServices::GetStartupServiceEnum(
    /*[out]*/ IEnumProjectStartupServices **ppEnum)
{
    return CEnumProjectStartupServices::CreateInstance(
        &m_rgpCProjectStartupService,
        ppEnum);
}
 

// Lookup an array element by GUID
// Returns S_OK, or S_FALSE if not found
STDMETHODIMP CVsProjectStartupServices::Find(
        /*[in] */ REFGUID guid, 
        /*[out]*/ ULONG*  puIndex)
{
    // Ignore null guids in the list -- don't try to look them up.
    if (guid == GUID_NULL)
        return S_FALSE;
              
    ULONG cPss = m_rgpCProjectStartupService.GetSize();
    for(ULONG uIndex=0; uIndex < cPss; uIndex++)
    {
        CProjectStartupService* pPss = m_rgpCProjectStartupService.GetAt(uIndex);
        ASSERT(pPss != NULL);
        if ( (pPss != NULL) && (pPss->GetGuid() == guid) )
        {
            if (puIndex)
                *puIndex = uIndex;
            return S_OK;
        }
    }

    return S_FALSE;
}

//                                                 IVsProjectStartupServices
//==========================================================================

//==========================================================================
//                                                           Service Control

//
// Start any unstarted services in the services array.
STDMETHODIMP CVsProjectStartupServices::StartServices()
{
    HRESULT hr = S_OK;

    ULONG cPss = m_rgpCProjectStartupService.GetSize();
    for(ULONG uIndex=0; uIndex < cPss; uIndex++)
    {
        CProjectStartupService* pPss = m_rgpCProjectStartupService.GetAt(uIndex);
        ASSERT(pPss != NULL);
        if (pPss != NULL)
        {
            hr = pPss->StartService();
            ASSERT(SUCCEEDED(hr));
        }
    }
    return S_OK;  
}

STDMETHODIMP CVsProjectStartupServices::StopServices()
{
    HRESULT hr = S_OK;

    ULONG cPss = m_rgpCProjectStartupService.GetSize();
    for(ULONG uIndex=0; uIndex < cPss; uIndex++)
    {
        CProjectStartupService* pPss = m_rgpCProjectStartupService.GetAt(uIndex);
        ASSERT(pPss != NULL);
        if (pPss != NULL)
        {
            hr = pPss->StopService();
            ASSERT(SUCCEEDED(hr));
        }
    }
    return S_OK;  
}


//                                                           Service Control
//==========================================================================



//==========================================================================
//                                                                persisting


STDMETHODIMP CVsProjectStartupServices::Load(
    /* [in] */ IVsPropertyStreamIn *pIVsPropertyStreamIn)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsProjectStartupServices::Load \n"));

    ExpectedPtrRet(pIVsPropertyStreamIn);

	HRESULT hr = S_OK;

	for (;;)
	{
		CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamIn;
		VSPROPERTYSTREAMPROPERTYTYPE vspspt;

        const ULONG cchBuffer = _MAX_PATH;
		WCHAR rgwchPropName[cchBuffer];

		CComVariant cvarValue;
		hr = pIVsPropertyStreamIn->Read(
                cchBuffer, 
                rgwchPropName, 
                NULL, 
                &vspspt, 
                &cvarValue, 
                NULL);

		ASSERT(SUCCEEDED(hr));
        IfFailGo(hr);

		if (rgwchPropName[0] == L'\0')
			break;

		if (vspspt != VSPSPT_SIMPLE || cvarValue.vt != VT_BSTR)
		{
		    ASSERT(FALSE);
			hr = E_UNEXPECTED;
            goto Error;
		}

		if (_wcsicmp(rgwchPropName, ms_pszKey_ID) == 0)
        {
            USES_CONVERSION;
	        GUID guidValue = GUID_NULL;
            hr = ::CLSIDFromString(W2OLE(cvarValue.bstrVal), &guidValue);
	        if (FAILED(hr))
            {
		        ASSERT(FALSE);
                break;
            }
            AddStartupService(guidValue);
        }
        else
		{
			// NOTE: we'll just ignore properties without recognized names
		}
	}

Error:
   
	return hr;
}


STDMETHODIMP CVsProjectStartupServices::Save(
    /* [in] */ IVsPropertyStreamOut *pIVsPropertyStreamOut)
{

    ExpectedPtrRet(pIVsPropertyStreamOut);

	HRESULT hr = S_OK;
    ULONG cPss = m_rgpCProjectStartupService.GetSize();
    for(ULONG uIndex=0; uIndex < cPss; uIndex++)
    {
        CProjectStartupService* pPss = m_rgpCProjectStartupService.GetAt(uIndex);
        ASSERT(pPss != NULL);
        if (pPss != NULL)
        {
            LPOLESTR pszGuid = NULL;
            hr = ::StringFromCLSID(pPss->GetGuid(),&pszGuid);
            IfFailRet(hr);
		    hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
						ms_pszKey_ID,
						pszGuid,
						NULL /*szLineComment*/);
           	CoTaskMemFree(pszGuid);

            ASSERT(SUCCEEDED(hr));
            IfFailRet(hr);
        }
    }

	return hr;
}


//                                                                persisting
//==========================================================================



/****************************************************************************\
**
**  CEnumProjectStartupServices
**
\****************************************************************************/
HRESULT CEnumProjectStartupServices::CreateInstance(
    /* [in]  */ ProjectStartupServiceArray*   pProjectStartupServiceArray,
    /* [out] */ IEnumProjectStartupServices** ppIEnumProjectStartupServices)
{
    ExpectedPtrRet(ppIEnumProjectStartupServices);
    InitParam(ppIEnumProjectStartupServices);

    CComObject<CEnumProjectStartupServices>* pco = NULL;
    HRESULT hr = CComObject<CEnumProjectStartupServices>::CreateInstance(&pco);
    IfFailRet(hr);

    pco->AddRef();
    hr = pco->Init(pProjectStartupServiceArray);
    IfFailGo(hr);

    hr = pco->QueryInterface(
        IID_IEnumProjectStartupServices, 
        (void**)ppIEnumProjectStartupServices);

Error:
    if (pco)
        pco->Release();

    return hr;
}



HRESULT CEnumProjectStartupServices::Init(
    /* [in]  */ ProjectStartupServiceArray* pProjectStartupServiceArray)
{

    ExpectedPtrRet(pProjectStartupServiceArray);

    m_uGuidIndex = 0;

    HRESULT hr = S_OK;

    // init the array
    int cPss = pProjectStartupServiceArray->GetSize();
    m_rgpCGuid.SetSize(cPss);
    if(m_rgpCGuid.GetSize() != cPss)
        return E_FAIL;

    for(int iIndex=0; iIndex < cPss; iIndex++)
    {
        CProjectStartupService* pPss = pProjectStartupServiceArray->GetAt(iIndex);
        ASSERT(pPss != NULL);

        CGuid *pCGuid = pPss->GetCGuid();
        ASSERT(pCGuid != NULL);

        m_rgpCGuid.SetAt(iIndex, pCGuid);
        pCGuid->AddRef();
    }

    return hr;
}

HRESULT CEnumProjectStartupServices::Init(
    /* [in] */ CGuidArray* pCGuidArray,
    /* [in] */ ULONG uIndex)
{

    ExpectedPtrRet(pCGuidArray);

    m_uGuidIndex = uIndex;

    HRESULT hr = S_OK;

    // init the array
    int cGuids = pCGuidArray->GetSize();
    m_rgpCGuid.SetSize(cGuids);
    if(m_rgpCGuid.GetSize() != cGuids)
        return E_FAIL;

    for(int iIndex=0; iIndex < cGuids; iIndex++)
    {
        CGuid *pCGuid = pCGuidArray->GetAt(iIndex);
        ASSERT(pCGuid != NULL);

        m_rgpCGuid.SetAt(iIndex, pCGuid);
        pCGuid->AddRef();
    }

    return hr;
}


CEnumProjectStartupServices::~CEnumProjectStartupServices()
{  
    int cGuids = m_rgpCGuid.GetSize();
    for(int iIndex=0; iIndex < cGuids; iIndex++)
    {
        CGuid* pCGuid = m_rgpCGuid.GetAt(iIndex);
        ASSERT(pCGuid != NULL);

        if (pCGuid != NULL) 
        {
            pCGuid->Release();
        }
    }
    m_rgpCGuid.RemoveAll();       
}


HRESULT CEnumProjectStartupServices::Reset()
{
    m_uGuidIndex = 0;
    return S_OK;
}


HRESULT CEnumProjectStartupServices::Next(
    /* [in]                                           */ ULONG celt, 
    /* [out, size_is(celt), length_is(*pceltFetched)] */ GUID *rgelt, 
    /* [out]                                          */ ULONG *pceltFetched)
{

    HRESULT hr = S_OK;
    ULONG   i = 0;
    ULONG   cGuids = m_rgpCGuid.GetSize();

    ExpectedPtrRet(rgelt);
    for (i = 0; i < celt; i++)
        rgelt[i] = GUID_NULL;

    for (i = 0; i < celt && m_uGuidIndex < cGuids; i++, m_uGuidIndex++)
    {
        GUID guid = m_rgpCGuid.GetAt(i)->GetGuid();
        rgelt[i] = guid;
    }

    if (pceltFetched)
        *pceltFetched = i;

    hr = (i == celt) ? S_OK : S_FALSE;

    return hr;
}


HRESULT CEnumProjectStartupServices::Skip(
    /* [in] */ ULONG cElements)
{

    HRESULT hr = S_OK;
    m_uGuidIndex += cElements;
    ULONG   cGuids = m_rgpCGuid.GetSize();
    
    if (m_uGuidIndex > cGuids)
    {
        m_uGuidIndex = cGuids;
        hr = S_FALSE;
    }
    return hr;
}



HRESULT CEnumProjectStartupServices::Clone(
        /* [out] */ IEnumProjectStartupServices ** ppenum)
{
    ExpectedPtrRet(ppenum);
    InitParam(ppenum);

    CComObject<CEnumProjectStartupServices>* pco = NULL;
    HRESULT hr = CComObject<CEnumProjectStartupServices>::CreateInstance(&pco);
    IfFailRet(hr); 
    pco->AddRef();

    hr = pco->Init(&m_rgpCGuid, m_uGuidIndex);
    IfFailGo(hr);

    hr = pco->QueryInterface(
        IID_IEnumProjectStartupServices, 
        (void**)ppenum);
Error:
    if (pco)
        pco->Release();

    return hr;
}
