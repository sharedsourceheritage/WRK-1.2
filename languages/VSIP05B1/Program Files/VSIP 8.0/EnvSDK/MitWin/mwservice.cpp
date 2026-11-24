
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// MWService.cpp : Implementation of CMWToolService


#include "stdafx.h"
#include "PrjInc.h"
#include <limits.h>

CMWToolService::CMWToolService(CMitWinPackage *pMWPkg)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 3, _T(" CMWToolService::CMWToolService \n") );
    _ASSERTE(pMWPkg);

    m_fZombie = FALSE;
    m_dwRef = 0;
    m_pMWPkg = pMWPkg;
}

CMWToolService::~CMWToolService()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 3, _T(" CMWToolService::~CMWToolService \n") );
}

STDMETHODIMP CMWToolService::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolService::QueryInterface \n") );

    if (ppvObj == NULL) return E_INVALIDARG;

    *ppvObj = NULL;     // always intialize out parameters
    if ((riid == IID_IMWTool) || (riid == IID_IUnknown))
    {
        AddRef();
        *ppvObj = (IMWTool *) this;
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CMWToolService::AddRef()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolService::AddRef \n") );

    ++m_dwRef;
    return(m_dwRef);
}

STDMETHODIMP_(ULONG) CMWToolService::Release()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolService::Release \n") );

    --m_dwRef;
    if (m_dwRef == 0)
    {
        delete this;
        return 0;
    }
    return(m_dwRef); 
}

STDMETHODIMP  CMWToolService::CreateMWToolWindow(
                    /*[in]*/ REFGUID rguidPersistenceSlot,   // GUID_NULL for default
                    /*[in]*/ DWORD   dwID)                   // 0 for next available
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMWToolService::CreateMWToolWindow \n") );

    if (m_fZombie) 
        return E_UNEXPECTED;

    _ASSERTE(m_pMWPkg);

    HRESULT                     hr;
    CComPtr<IVsUIShell>         srpVsUIShell;
    TCHAR                       strNumber[32];
    TCHAR                       strCaption[128];
    CComPtr<IVsWindowFrame>     srpWindowFrame;
    CComPtr<IVsWindowPane>      srpWindowPane;
    CComObject<CMWToolWindow>*  spMWToolWindow = NULL;
    VSCREATETOOLWIN             dwCreateToolFlags = 
                                    CTW_fInitNew | 
                                    CTW_fForceCreate | 
                                    CTW_fMultiInstance |
                                    CTW_fToolbarHost;
    USES_CONVERSION;

    GUID guidToolWindow = ::InlineIsEqualGUID(rguidPersistenceSlot, GUID_NULL) ? 
                            GUID_MWTool : rguidPersistenceSlot;
    
    if (! ::InlineIsEqualGUID(guidToolWindow, GUID_MWTool))
        return E_INVALIDARG;

    // get the IVsUIShell interface so we can create a tool window
    hr = _AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpVsUIShell);
    IfFailGo(hr); ExpectedExprGo(srpVsUIShell != NULL);

    hr = CComObject<CMWToolWindow>::CreateInstance(&spMWToolWindow);

    if(SUCCEEDED(hr) && spMWToolWindow)
        hr = spMWToolWindow->QueryInterface(IID_IVsWindowPane, (void**)&srpWindowPane);
    else 
        hr = E_OUTOFMEMORY;

    IfFailGo(hr);

    if(!dwID) // look for next available ID
    {
        dwID++; // start with 1 - keep 0 reserved
        while(SUCCEEDED(srpVsUIShell->FindToolWindowEx(0,    guidToolWindow, 
                                                       dwID, &srpWindowFrame)))
        {
            srpWindowFrame.Release();
            dwID++;
        }
    }

    _sntprintf(strNumber, sizeof(strNumber)/sizeof(strNumber[0]), _T(" # %u"), dwID);
    if (!::LoadString(_AtlBaseModule.GetResourceInstance(), IDS_WINDOW_TITLE, 
                 strCaption, (int)(countof(strCaption) - _tcslen(strNumber) - 1)))
    {
        hr = HRESULT_FROM_WIN32(::GetLastError());
        goto OnError;
    }
    if (_tcslen(strCaption) + _tcslen(strNumber) >= countof(strCaption))
     {
        hr = HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
        goto OnError;
    }
    _tcscat(strCaption, strNumber);
    
    hr = srpVsUIShell->CreateToolWindow(
                                    dwCreateToolFlags,
                                    dwID,
                                    srpWindowPane,
                                    CLSID_NULL,
                                    guidToolWindow,
                                    GUID_NULL,
                                    NULL,
                                    T2OLE(strCaption),
                                    NULL,
                                    &srpWindowFrame);

    IfFailGo(hr); ExpectedExprGo(srpWindowFrame != NULL)
    
    hr = spMWToolWindow->Initialize(srpWindowFrame);

    if (FAILED(hr))
    {
        _ASSERTE(!_T("Failed to initialize the tool"));
        srpWindowFrame->CloseFrame(FRAMECLOSE_NoSave);
    }

OnError:
    return hr;
}
