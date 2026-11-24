
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// Helpers.cpp
//
// Miscellaneous Utility Functions
//
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"

//=========================================================================
//                                                       REGISTRATION UTILS

HRESULT GetRegRootStrings(
    /* [out] */ BSTR *       pbstrRootBegin, 
    /* [out] */ BSTR *       pbstrRootEnd,
    /* [in]  */ const WCHAR* pwszRegRoot /* = NULL */)
{
    _ASSERTE(pbstrRootBegin && pbstrRootEnd);
    if(!pbstrRootBegin || !pbstrRootEnd)
        return E_POINTER;

    HRESULT hr = S_OK;

    const ULONG cchBuffer = _MAX_PATH;
    WCHAR wszRegistrationRoot[cchBuffer];
    DWORD cchFreeBuffer = cchBuffer - 1;
    if (pwszRegRoot)
    {
        if ( wcslen(pwszRegRoot) >= cchFreeBuffer )
            return E_INVALIDARG;
        wcscpy(wszRegistrationRoot, pwszRegRoot);
    }
    else
    {
        wcscpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT_NOVERSION);
        wcscat(wszRegistrationRoot, L"\\");
        
        // this is Environment SDK specific
        // we check for  EnvSdk_RegKey environment variable to
        // determine where to register
        DWORD cchDefRegRoot = lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION) + 1;
        cchFreeBuffer = cchFreeBuffer - cchDefRegRoot;
        DWORD cchEnvVarRead = GetEnvironmentVariableW(
            /* LPCTSTR */ L"EnvSdk_RegKey",               // environment variable name
            /* LPTSTR  */ &wszRegistrationRoot[cchDefRegRoot],// buffer for variable value
            /* DWORD   */ cchFreeBuffer);// size of buffer
        if (cchEnvVarRead >= cchFreeBuffer)
            return E_UNEXPECTED;
        // If the environment variable does not exist then we must use 
        // LREGKEY_VISUALSTUDIOROOT which has the version number.
        if (0 == cchEnvVarRead)
            wcscpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT);
    }
       
    CComBSTR cbstrRootBegin;
    CComBSTR cbstrRootEnd;
    
    // Make sure the string ends in backslash to simplify loop 
    // for processing backslashes.
    int len = (int)wcslen(wszRegistrationRoot);
    if(wszRegistrationRoot[len - 1] != L'\\')
        wcscat(wszRegistrationRoot, L"\\");

    WCHAR * pStart = wszRegistrationRoot;
    WCHAR * pSlash = wcschr(wszRegistrationRoot, L'\\');

    while(pSlash)
    {
        *pSlash = 0;
        hr = cbstrRootBegin.Append(L" NoRemove ");
        if (FAILED(hr)) 
            return hr;

        hr = cbstrRootBegin.Append(pStart);
        if (FAILED(hr)) 
            return hr;

        hr = cbstrRootBegin.Append(L"\n{\n");
        if (FAILED(hr)) 
            return hr;

        hr = cbstrRootEnd.Append(L"\n}\n");
        if (FAILED(hr)) 
            return hr;

        pStart = pSlash + 1;
        pSlash = wcschr(pStart, L'\\');
    }

    *pbstrRootBegin = cbstrRootBegin.Detach();
    *pbstrRootEnd   = cbstrRootEnd.Detach();

    return S_OK;
}


HRESULT GetRegDefaultResourceStrings(
    /* [out] */ BSTR * pbstrResDllPath, // optional, can be NULL
    /* [out] */ BSTR * pbstrResDllName) // optional, can be NULL
{
    if (pbstrResDllPath)
        *pbstrResDllPath = NULL;
    if (pbstrResDllName)
        *pbstrResDllName = NULL;

    HRESULT hr = S_OK;

    const DWORD cchBuffer=_MAX_PATH;
    WCHAR wszModuleFullName[cchBuffer];
    DWORD dwLen = ::GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), wszModuleFullName, cchBuffer);
    if (dwLen == 0)
        return HRESULT_FROM_WIN32(::GetLastError());
    if (dwLen == cchBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    WCHAR wszDrive[_MAX_DRIVE];
    WCHAR wszDir[_MAX_DIR];
    WCHAR wszFName[_MAX_FNAME];
    WCHAR wszExt[_MAX_EXT];

    _wsplitpath(wszModuleFullName, wszDrive, wszDir, wszFName, wszExt);

    CComBSTR cbstrResDllName(wszFName);
    if (cbstrResDllName.Length() == 0) 
        return E_OUTOFMEMORY;
    hr = cbstrResDllName.Append(L"UI");
    if (FAILED(hr)) 
        return hr;
    hr = cbstrResDllName.Append(wszExt);
    if (FAILED(hr)) 
        return hr;

    CComBSTR cbstrResDllPath(wszDrive);
    if (cbstrResDllPath.Length() == 0) 
        return E_OUTOFMEMORY;
    hr = cbstrResDllPath.Append(wszDir);
    if (FAILED(hr)) 
        return hr;

    if (pbstrResDllPath)
        *pbstrResDllPath = cbstrResDllPath.Detach();
    if (pbstrResDllName)
        *pbstrResDllName = cbstrResDllName.Detach();

    return S_OK;
}


//                                                       REGISTRATION UTILS
//=========================================================================
