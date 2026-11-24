
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// OptPpg.cpp
//

#include "stdafx.h"
#include "PrjInc.h"
#include "OptPpg.h"

CComPtr<_OptionsPreferences> COptionsPpg::ms_srpOptionsPreferences;

///////////////////////////////////////////////////////////////////////////////
// COptionsPpg

COptionsPpg::COptionsPpg() : m_hwndPage(NULL)
{
}


HRESULT COptionsPpg::GetPage(
    /* [in]  */ _OptionsPreferences* pOptionsPreferences,
    /* [out] */ VSPROPSHEETPAGE*     pPage)
{
    _ASSERTE(pOptionsPreferences);
    if (!pOptionsPreferences)
        return E_POINTER;
    _ASSERTE(pPage);
    if (!pPage)
        return E_POINTER;

    ms_srpOptionsPreferences = pOptionsPreferences;

    pPage->dwSize = sizeof(VSPROPSHEETPAGE);
    pPage->dwFlags = PSP_DEFAULT | PSP_USECALLBACK; //| PSP_HASHELP;
    pPage->hInstance = _AtlBaseModule.GetResourceInstance();
    pPage->wTemplateId = IDD_OPTIONS;
    pPage->pfnDlgProc = COptionsPpg::DialogProc;
    pPage->lParam = NULL;
    pPage->pfnCallback = COptionsPpg::PageProc;
    pPage->pcRefParent = NULL;

    return S_OK;
}

INT_PTR CALLBACK COptionsPpg::DialogProc(HWND hWnd, UINT Message, WPARAM wParam,
                                      LPARAM lParam)
{
    static COptionsPpg* pPage = NULL;

    switch (Message)
    {
        case WM_INITDIALOG:
        {
            _ASSERTE(!pPage);
            PROPSHEETPAGEW* pPSP = (PROPSHEETPAGEW*)lParam;
            pPage = (COptionsPpg*)pPSP->lParam;

            if (pPage)
            {
                pPage->SetPageHandle(hWnd);
                pPage->LoadSettings();
                return TRUE;
            }
            return FALSE;
        }
        case WM_DESTROY:
            pPage = NULL;
            return TRUE;
        case WM_NOTIFY:
            return pPage && pPage->OnNotify(wParam, (NMHDR*)lParam);
        default:
            return FALSE;
    }
}

UINT CALLBACK COptionsPpg::PageProc(HWND hWnd, UINT Message,
                                    PROPSHEETPAGEA* pPage)
{
    static BOOL fCreated = FALSE;

    _ASSERTE(pPage);

    switch (Message)
    {
        case PSPCB_CREATE:
            pPage->lParam = (LPARAM)new COptionsPpg();
            fCreated = TRUE;
            break;
        case PSPCB_RELEASE:
            if (fCreated)
            {
                delete ((COptionsPpg*)pPage->lParam);
                fCreated = FALSE;
            }
    }
    return TRUE;
}


///////////////////////////////////////////////////////////////////////////////
// COptionsPpg Implementation


void COptionsPpg::LoadSettings()
{
    USES_CONVERSION;
    _ASSERTE(m_hwndPage);
    CComBSTR bstrTemp;

    HWND hwndEdit = GetDlgItem(m_hwndPage, IDC_OPTION_SETTING);
    _ASSERTE(hwndEdit);

    if (ms_srpOptionsPreferences != NULL)
    {
        HRESULT hr = ms_srpOptionsPreferences->get_Setting(&bstrTemp);
        // may fail if the reg key does not exist
        if (SUCCEEDED(hr))
        {
            SetWindowText(hwndEdit, OLE2T(bstrTemp));
        }
    }

    SendMessage(hwndEdit, EM_LIMITTEXT, MAX_SETTING_LEN, 0);
}

BOOL COptionsPpg::SaveSettings()
{
    USES_CONVERSION;

    _ASSERTE(m_hwndPage);

    HWND hwndEdit = GetDlgItem(m_hwndPage, IDC_OPTION_SETTING);
    _ASSERTE(hwndEdit);

    TCHAR pszValue[MAX_SETTING_LEN];

    GetWindowText(hwndEdit, pszValue, MAX_SETTING_LEN);

    if (ms_srpOptionsPreferences != NULL)
    {
        CComBSTR cbstrValue(pszValue);
        HRESULT hr = ms_srpOptionsPreferences->put_Setting(cbstrValue);
        _ASSERTE(SUCCEEDED(hr));
    }

    return TRUE;
}

BOOL COptionsPpg::ValidateSettings()
{
    _ASSERTE(m_hwndPage);

    return TRUE;    // always valid in our sample: allow changing pages
}

BOOL COptionsPpg::OnNotify(WPARAM wIDCtrl, NMHDR* pNotifyInfo)
{
    _ASSERTE(pNotifyInfo);

    switch (pNotifyInfo->code)
    {
        case PSN_APPLY:
            SetWindowLongPtr(m_hwndPage, DWLP_MSGRESULT, PSNRET_NOERROR);
            SaveSettings();
            return TRUE;
        case PSN_SETACTIVE:
            // init page
            return TRUE;
        case PSN_KILLACTIVE:
            if (ValidateSettings())
                SetWindowLongPtr(m_hwndPage, DWLP_MSGRESULT, FALSE);
            else
                SetWindowLongPtr(m_hwndPage, DWLP_MSGRESULT, TRUE);
            return TRUE;
        case PSN_HELP:
        case PSN_QUERYCANCEL:
            return FALSE;       // allow cancel
        case PSN_RESET:
            return FALSE;
    }
    return TRUE;
}
