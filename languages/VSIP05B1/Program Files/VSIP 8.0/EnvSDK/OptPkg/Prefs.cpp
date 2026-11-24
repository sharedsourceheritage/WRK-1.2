
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// OptionsPreferences.cpp : Implementation of CTestApp and DLL registration.

#include "stdafx.h"
#include "OptPkg.h"
#include "Prefs.h"

/////////////////////////////////////////////////////////////////////////////
//
/* static */
HRESULT COptionsPreferences::CreateInstance(
    /* [out] */ _OptionsPreferences** pp_OptionsPreferences)
{
    if (!pp_OptionsPreferences)
        return E_POINTER;
    *pp_OptionsPreferences = NULL;

    CComObject<COptionsPreferences>* pco = NULL;
    HRESULT hr = CComObject<COptionsPreferences>::CreateInstance(&pco);
    _ASSERTE(SUCCEEDED(hr));
    if (FAILED(hr))
        return hr;

    pco->AddRef();
    hr = pco->QueryInterface(IID__OptionsPreferences, (void**)pp_OptionsPreferences);
    pco->Release();
    return hr;
}

COptionsPreferences::COptionsPreferences()
{
    m_pwszSetting = NULL;
}

COptionsPreferences::~COptionsPreferences()
{
    ReleaseSetting();
}

STDMETHODIMP COptionsPreferences::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &IID__OptionsPreferences,
    };

    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if (::InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}

STDMETHODIMP COptionsPreferences::get_Setting(BSTR *pVal)
{
    if (pVal == NULL)
        return E_POINTER;
    *pVal = NULL;

    HRESULT hr = S_OK;

    CComPtr<ILocalRegistry2> srpLocalRegistry;
    hr = _AtlModule.QueryService(SID_SLocalRegistry, IID_ILocalRegistry2, (void **)&srpLocalRegistry);
    if (FAILED(hr))
        return hr;
    if (srpLocalRegistry == NULL)
        return E_UNEXPECTED;

    CComBSTR cbstrRoot;
    hr = srpLocalRegistry->GetLocalRegistryRoot(&cbstrRoot);
    if (FAILED(hr))
        return hr;
    if (cbstrRoot.Length() == 0)
        return E_UNEXPECTED;

    hr = cbstrRoot.Append("\\OptionsPkg");
    if (FAILED(hr))
        return hr;

    CRegKey keyPrefs;
    long nResult;
    nResult = keyPrefs.Open(HKEY_CURRENT_USER, cbstrRoot, KEY_READ);
    if (nResult == ERROR_SUCCESS)
    {
        DWORD nLen = 0;
        nResult = keyPrefs.QueryStringValue(_T("Value"), NULL, &nLen);
        if ((nResult == ERROR_SUCCESS) && (nLen <= MAX_SETTING_LEN))
        {
            WCHAR* pszSetting = new WCHAR[nLen+1];
            if (pszSetting == NULL)
                return E_OUTOFMEMORY;
            nResult = keyPrefs.QueryStringValue(_T("Value"), pszSetting, &nLen);
            if (nResult == ERROR_SUCCESS)
            {
                pszSetting[nLen] = '\0';
                ReleaseSetting();
                m_pwszSetting = pszSetting;
            }
            else
            {
                if (pszSetting)
                    delete[] pszSetting;
            }
        }
    }

    *pVal = ::SysAllocString(m_pwszSetting);
    return ((*pVal != NULL) ? S_OK : E_OUTOFMEMORY);
}

STDMETHODIMP COptionsPreferences::put_Setting(BSTR newVal)
{
    HRESULT hr = S_OK;
      
    CComPtr<ILocalRegistry2> srpLocalRegistry;
    hr = _AtlModule.QueryService(SID_SLocalRegistry, IID_ILocalRegistry2, (void **)&srpLocalRegistry);
    if (FAILED(hr))
        return hr;
    if (srpLocalRegistry == NULL)
        return E_UNEXPECTED;

    CComBSTR cbstrRoot;
    hr = srpLocalRegistry->GetLocalRegistryRoot(&cbstrRoot);
    if (FAILED(hr))
        return hr;
    if (cbstrRoot.Length() == 0)
        return E_UNEXPECTED;

    hr = cbstrRoot.Append("\\OptionsPkg");
    if (FAILED(hr))
        return hr;

    CRegKey keyPrefs;
    long nResult;
    nResult = keyPrefs.Create(HKEY_CURRENT_USER, cbstrRoot);
    if (nResult != ERROR_SUCCESS)
        return E_FAIL;

    UINT uiLen = ::SysStringLen(newVal);
    if (uiLen > MAX_SETTING_LEN)
        return E_FAIL;

    ReleaseSetting();
    m_pwszSetting = new WCHAR[uiLen + 1];
    if (m_pwszSetting == NULL)
        return E_OUTOFMEMORY;
    m_pwszSetting[uiLen] = L'\0';

    if (uiLen != 0)
        wcscpy(m_pwszSetting, newVal);

    if (m_pwszSetting)
        nResult = keyPrefs.SetStringValue(_T("Value"), m_pwszSetting);
    else
        nResult = keyPrefs.SetStringValue(_T(""), m_pwszSetting);
    if (nResult != ERROR_SUCCESS)
        return E_FAIL;

    return S_OK;
}

void COptionsPreferences::ReleaseSetting()
{
    if (m_pwszSetting)
    {
        delete m_pwszSetting;
        m_pwszSetting = NULL;
    }
}
