
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// Magic.cpp
//
// Implementation of CMagicDisplay and CMaginDialog
//
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "TriHost.h"
#include "Magic.h"


//*****************************************************************************
// CMagicDisplay Constructor/Destructor
//*****************************************************************************

CMagicDisplay::CMagicDisplay()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMagicDisplay::CMagicDisplay \n") );

    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Creating CMagicDisplay: 0x%X\n"), this);
    }
}

CMagicDisplay::~CMagicDisplay()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMagicDisplay::~CMagicDisplay \n") );

    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Destructing CMagicDisplay: 0x%X\n"), this);
    }
}


//*****************************************************************************
// CMagicDisplay IMagicDisplay Implementation
//*****************************************************************************

STDMETHODIMP CMagicDisplay::ShowMagic(
                    /*[in]*/ LPCOLESTR lpszMagicURL,
                    /*[in]*/ LPCOLESTR lpszTitle,
                    /*[in]*/ long      cx,
                    /*[in]*/ long      cy)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMagicDisplay::ShowMagic \n") );

    ExpectedPtrRet(lpszMagicURL);

    CMagicDialog dlg;

    dlg.m_lpszCaption = lpszTitle;
    dlg.m_lpszURL = lpszMagicURL;
    dlg.m_cx = cx;
    dlg.m_cy = cy;

    dlg.DoModal();
    return S_OK;
}



//*****************************************************************************
// CMagicDialog Constructor/Destructor
//*****************************************************************************

CMagicDialog::CMagicDialog()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMagicDialog::CMagicDialog \n") );

    m_lpszURL = NULL;
    m_lpszCaption = NULL;

    m_pTridentHost = NULL;
}

CMagicDialog::~CMagicDialog()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMagicDialog::~CMagicDialog \n") );
}


//*****************************************************************************
// CMagicDialog Message Handlers
//*****************************************************************************

LRESULT CMagicDialog::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMagicDialog::OnInitDialog \n") );

    _ASSERTE(m_lpszURL);

    CComPtr<IUnknown> srpUnkTrident;
    HRESULT hr = S_OK;

    USES_CONVERSION;

    if ((m_cx != 0) && (m_cy != 0))
    {
        m_cx += 2 * GetSystemMetrics(SM_CXBORDER);
        m_cy += 2 * GetSystemMetrics(SM_CYBORDER) + GetSystemMetrics(SM_CYCAPTION);
        SetWindowPos(NULL, 0, 0, m_cx, m_cy, SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE);
    }

    if (m_lpszCaption)
        SetWindowText(W2CT(m_lpszCaption));

    CenterWindow();

    hr = CComObject<CTridentHost>::CreateInstance(&m_pTridentHost);
    IfFailAllocGo(m_pTridentHost);

    hr = m_pTridentHost->QueryInterface(IID_IUnknown, (void**)&m_srpUnkTridentHost);
    _ASSERTE(SUCCEEDED(hr));

    hr = m_pTridentHost->CreateTridentHost(m_hWnd, m_lpszURL);
    IfFailGo(hr);

    hr = m_pTridentHost->ActivateTrident();
    IfFailGo(hr);

OnError:
    if (FAILED(hr))
    {
        EndDialog(-1);
    }
    return 1;
}

LRESULT CMagicDialog::OnCloseDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CMagicDialog::OnCloseDialog \n") );

    if (m_pTridentHost)
    {
        m_pTridentHost->CloseTridentHost();
    }
    m_srpUnkTridentHost.Release();

    EndDialog(0);
    return 0;
}
