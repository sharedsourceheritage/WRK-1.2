
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// miscutil.cpp : miscellaneous utility routines

#include "stdafx.h"
#include "PrjInc.h"

HRESULT CheckFileName(LPCTSTR pszFileName)
{
    if (pszFileName == NULL || *pszFileName == L'\0')
        return HRESULT_FROM_WIN32(ERROR_INVALID_NAME);
    if (_tcslen(pszFileName) >= _MAX_PATH)
        return HRESULT_FROM_WIN32(ERROR_BUFFER_OVERFLOW);

    CString strFileName = pszFileName;
    LUtilFixFilename(strFileName);// Remove trailing dots and spaces
    
    // get the base name
    TCHAR szBaseName[_MAX_FNAME + 1];
    _tsplitpath(strFileName, NULL, NULL, szBaseName, NULL);

    if (LUtilContainsInvalidFileChars(szBaseName))
        return HRESULT_FROM_WIN32(ERROR_INVALID_NAME);

    CString strBaseName = szBaseName;
    LUtilFixFilename(strBaseName);// Remove trailing dots and spaces
    if (strBaseName.GetLength() == 0)
        return HRESULT_FROM_WIN32(ERROR_INVALID_NAME);

    const TCHAR* rgszReservedNames[] = 
    {
        _T("CON"), _T("PRN"), _T("AUX"), _T("CLOCK$"), _T("NUL"), 
        _T("COM1"),_T("COM2"), _T("COM3"),_T("COM4"),_T("COM5"), _T("COM6"), _T("COM7"),_T("COM8"), _T("COM9"),
        _T("LPT1"),_T("LPT2"), _T("LPT3"),_T("LPT4"),_T("LPT5"), _T("LPT6"), _T("LPT7"),_T("LPT8"), _T("LPT9") 
    };

    const size_t nSize  = sizeof(rgszReservedNames)/sizeof(rgszReservedNames[0]);
    for (size_t i = 0; i < nSize; i++)
    {
        if (_tcsicmp(strBaseName, rgszReservedNames[i]) == 0)
        {
            return HRESULT_FROM_WIN32(ERROR_INVALID_NAME);
        }
    }
    return S_OK;
}


HRESULT CheckFileType(LPCTSTR pszFilePath, BOOL fWhenExistOnly /* = FALSE */)
{
    if (!pszFilePath || *pszFilePath == L'\0')
        return E_INVALIDARG;

    HRESULT hr = S_OK;
    HANDLE hFile = ::CreateFile(pszFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        if (fWhenExistOnly)
            return S_OK;
        else
            return HRESULT_FROM_WIN32(GetLastError());
    }
    if (GetFileType(hFile) != FILE_TYPE_DISK)
        hr = HRESULT_FROM_WIN32(ERROR_INVALID_NAME);
    CloseHandle(hFile);
    return hr;
}

HRESULT GetFullLongFilePath(
    LPCTSTR pszFilePath, 
    CString& strFullPath,
    LPTSTR *lpFilePart /* = NULL */)
{
    strFullPath.Empty();
    if (lpFilePart)
        *lpFilePart = NULL;
    if (pszFilePath == NULL || *pszFilePath == L'\0')
        return HRESULT_FROM_WIN32(ERROR_INVALID_NAME);
    // make sure an absolute path is passed
    if (!LUtilIsAbsolutePath(pszFilePath))
        return E_INVALIDARG;

    const DWORD cchBuffer = _MAX_PATH;
    TCHAR szFullPath[cchBuffer + 1], *pch;
    szFullPath[0] = _T('\0');
    DWORD dwRet = GetFullPathName(pszFilePath, cchBuffer, szFullPath, &pch);
    if (dwRet == 0)
        return HRESULT_FROM_WIN32(GetLastError());
    if (dwRet >= cchBuffer)
        return HRESULT_FROM_WIN32(ERROR_BUFFER_OVERFLOW);

    TCHAR szLongPath[cchBuffer+1];
    dwRet = GetLongPathName(szFullPath, szLongPath, cchBuffer);
    if (dwRet == 0)
        return HRESULT_FROM_WIN32(GetLastError());
    if (dwRet >= cchBuffer)
        return HRESULT_FROM_WIN32(ERROR_BUFFER_OVERFLOW);

    strFullPath = szLongPath;
    if (lpFilePart)
        *lpFilePart = pch;
    return S_OK;
}

//-----------------------------------------------------------------------------
// Returns the currently set text. Note that his clears the error so use wisely!
//-----------------------------------------------------------------------------
void UtilGetErrorDescription(CString& strText)
{
    CComPtr<IErrorInfo>    srpIErrorInfo;
    HRESULT hr = ::GetErrorInfo(0, &srpIErrorInfo);
    if(hr == S_OK)
    {
        CComBSTR bstrErrDescription;
        if(srpIErrorInfo->GetDescription(&bstrErrDescription) == S_OK)
            strText = bstrErrDescription;
    }
}


///-----------------------------------------------------------------------------
//------------------------------------------------------------------------------
HRESULT UtilSetWin32Err(DWORD err, UINT nIDPrompt, LPCTSTR pszString1)
{
    ASSERT(nIDPrompt);
    CString msg, msg1;
    if(err != 0)
        Win32ErrorString(err, msg);
    if(nIDPrompt)
    {
        VxFormatString1(msg1, nIDPrompt, pszString1);
        msg1 += msg;
    }
    else
    {
        msg1 = msg;
    }
    HRESULT hr = HRESULT_FROM_WIN32(err);
    _VxModule.SetErrorInfo(hr, msg1,0);
    return hr;
}

//Utility function to query the RDT for document information given a document name
HRESULT GetRDTDocumentInfo(LPCTSTR szDocumentName, IVsHierarchy** ppHier, VSITEMID* pitemid)
{
    ExpectedPtrRet(szDocumentName);
    ASSERT(ppHier && pitemid);
    if (!ppHier || !pitemid)
        return E_INVALIDARG;

    USES_CONVERSION;
    *ppHier = NULL;
    *pitemid = NULL;

    // Get the document info.
    IVsRunningDocumentTable* pRDT = _VxModule.GetIVsRunningDocumentTable();
    if (!pRDT)
        return E_FAIL;

    CComPtr<IUnknown> pUnk;
    VSDOCCOOKIE docCookie;
    return pRDT->FindAndLockDocument( RDT_NoLock, T2COLE(szDocumentName), ppHier, pitemid,
                            &pUnk, &docCookie);
}


HRESULT GetRDTDocumentInfo(
    /* [in]  */ LPCTSTR             pszDocumentName, 
    /* [out] */ IVsHierarchy**      ppIVsHierarchy      /* = NULL */, 
    /* [out] */ VSITEMID*           pitemid             /* = NULL */,
    /* [out] */ IVsPersistDocData** ppIVsPersistDocData /* = NULL */,
    /* [out] */ VSDOCCOOKIE*        pVsDocCookie        /* = NULL */)
{
    ExpectedPtrRet(pszDocumentName);

    if (ppIVsHierarchy)
        *ppIVsHierarchy = NULL;
    if (pitemid)
        *pitemid = VSITEMID_NIL;
    if (ppIVsPersistDocData)
        *ppIVsPersistDocData = NULL;
    if (pVsDocCookie)
        *pVsDocCookie = VSDOCCOOKIE_NIL;

    USES_CONVERSION;

    // Get the document info.
    IVsRunningDocumentTable* pRDT = _VxModule.GetIVsRunningDocumentTable();
    ExpectedExprRet(pRDT);

    CComPtr<IVsHierarchy> srpIVsHierarchy;
    VSITEMID              vsItemId          = VSITEMID_NIL;
    CComPtr<IUnknown>     srpIUnknown;
    VSDOCCOOKIE           vsDocCookie       = VSDOCCOOKIE_NIL;
    HRESULT hr = pRDT->FindAndLockDocument(
        /* [in]  VSRDTFLAGS dwRDTLockType   */ RDT_NoLock,
        /* [in]  LPCOLESTR pszMkDocument    */ T2COLE(pszDocumentName),
        /* [out] IVsHierarchy **ppHier      */ &srpIVsHierarchy,
        /* [out] VSITEMID *pitemid          */ &vsItemId,
        /* [out] IUnknown **ppunkDocData    */ &srpIUnknown,
        /* [out] VSCOOKIE *pdwCookie        */ &vsDocCookie);
    IfFailRet(hr);

    // FindAndLockDocument returns S_FALSE if the doc is not in the RDT
    if (hr != S_OK)
        return hr;

    // now return the requested info
    if (ppIVsHierarchy && srpIVsHierarchy)
        *ppIVsHierarchy = srpIVsHierarchy.Detach();
    if (pitemid)
        *pitemid = vsItemId;
    if (ppIVsPersistDocData && srpIUnknown)
        srpIUnknown->QueryInterface(IID_IVsPersistDocData, (void**)ppIVsPersistDocData);
    if (pVsDocCookie)
        *pVsDocCookie = vsDocCookie;
 
    return S_OK;
}


//
// Create an empty IVsUserContext object
//
HRESULT CreateUserContext(
    /* [out] */ IVsUserContext** ppUserContext)
{
    ExpectedPtrRet(ppUserContext);
    *ppUserContext = NULL;

    HRESULT hr = E_FAIL;        
    IVsMonitorUserContext* pmuc = NULL;

    hr = _VxModule.QueryService(
                SID_SVsMonitorUserContext, 
                IID_IVsMonitorUserContext, 
                (void**)&pmuc );
    IfFailRet(hr);
    ExpectedExprRet(pmuc!=NULL); 

    hr = pmuc->CreateEmptyContext(ppUserContext);
    pmuc->Release(); 
            
    return hr;
}


HRESULT DisplayTopicFromF1Keyword(LPCTSTR pszF1Keyword)
{
    ExpectedPtrRet(pszF1Keyword);

    CComPtr<IVsHelp> srpIVsHelp;
    HRESULT hr = _VxModule.QueryService(SID_SVsHelp, IID_IVsHelp, (void**) &srpIVsHelp);
    IfFailRet(hr);

    CComBSTR cbstrF1Keyword(pszF1Keyword);
    if (!cbstrF1Keyword.Length())
        return E_OUTOFMEMORY;

    hr = srpIVsHelp->DisplayTopicFromF1Keyword(cbstrF1Keyword);
    return hr;
}


HRESULT GetVirtualRegistryRootW(
    /* [in, out] */ WCHAR* pwszVirtualRegistryRoot,
    /* [in]      */ int    cchBufferSize           /* = _MAX_PATH */)
{
    static CComBSTR s_cbstrVirtualRegistryRoot;

    ExpectedPtrRet(pwszVirtualRegistryRoot);

    HRESULT hr = S_OK;

    if (!s_cbstrVirtualRegistryRoot)
    {   
        IVsShell* pIVsShell = _VxModule.GetIVsShell();
        ExpectedExprRet(pIVsShell != NULL);

        CComVariant cvar;
        hr = pIVsShell->GetProperty(VSSPROPID_VirtualRegistryRoot, &cvar);
        IfFailRet(hr);
        ExpectedExprRet(cvar.vt == VT_BSTR);

        s_cbstrVirtualRegistryRoot.Attach(cvar.bstrVal);
        cvar.bstrVal = NULL;
    }

    int iLength = (int)s_cbstrVirtualRegistryRoot.Length();
    ExpectedExprRet(iLength > 0);

    if (cchBufferSize <= iLength)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    lstrcpyW(pwszVirtualRegistryRoot, s_cbstrVirtualRegistryRoot);
    return S_OK;

}


HRESULT CheckEnabledItem(
    /* [in] */ IDispatch *  pDisp, 
    /* [in] */ const GUID * pGUID, 
    /* [in] */ WCHAR *      pBuffer)
{
    ExpectedPtrRet(pDisp);
    ExpectedPtrRet(pBuffer);
    ExpectedPtrRet(pGUID);
    DISPID dispid;
    if(SUCCEEDED(pDisp->GetIDsOfNames(IID_NULL, &pBuffer, 1, LOCALE_NEUTRAL, &dispid)))
    {
        VxDTE::IVsExtensibility* pIVsExtensibility = _VxModule.GetIVsExtensibility();
        if(pIVsExtensibility != NULL)
        {
            if(pIVsExtensibility->IsMethodDisabled(pGUID, dispid) == S_OK)
            {
                LUtilSetErrString(IDS_E_METHODDISABLED);
                return E_FAIL;
            }
        }
    }
    return S_OK;
}


HRESULT GetInstallLocation(CString& strInstallLocation)
{
    // if your setup writes the installation folder into the registry
    // you should get the installation location from there

    // we use the module location
    strInstallLocation.Empty();

    TCHAR szBuffer[_MAX_PATH];
    DWORD dwLen = ::GetModuleFileName(_VxModule.GetModuleInstance(), szBuffer, _MAX_PATH);
    if (dwLen == 0)
        return HRESULT_FROM_WIN32(::GetLastError());
    if (dwLen == _MAX_PATH)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    TCHAR* pszLastSlash = _tcsrchr(szBuffer, _T('\\'));
    ASSERT(pszLastSlash);
    if (pszLastSlash)
        *pszLastSlash = 0;

    // Remove "\debug" or "\release"
    pszLastSlash = _tcsrchr(szBuffer, _T('\\'));
    ASSERT(pszLastSlash);
    if (pszLastSlash)
        *pszLastSlash = 0;

    strInstallLocation = szBuffer;
    if (strInstallLocation.GetLength() != lstrlen(szBuffer))
        return E_OUTOFMEMORY;
    return S_OK;
}


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
    WCHAR wszRegistrationRoot[cchBuffer+1];
    DWORD cchFreeBuffer = cchBuffer;
    if (pwszRegRoot)
    {
        if ( wcslen(pwszRegRoot) > cchFreeBuffer )
            return E_INVALIDARG;
        wcsncpy(wszRegistrationRoot, pwszRegRoot, cchFreeBuffer);
        cchFreeBuffer = cchBuffer - wcslen(wszRegistrationRoot);
    }
    else
    {
        // Get the length of the default registry root.
        DWORD cchDefRegRoot = lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION) + 1;
        if (cchDefRegRoot >= cchFreeBuffer)
            return E_UNEXPECTED;

        wcsncpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT_NOVERSION, cchFreeBuffer);
        cchFreeBuffer = cchBuffer - lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION);
        wcsncat(wszRegistrationRoot, L"\\", cchFreeBuffer);
        --cchFreeBuffer;

        // this is Environment SDK specific
        // we check for  EnvSdk_RegKey environment variable to
        // determine where to register
        DWORD cchEnvVarRead = GetEnvironmentVariableW(
            /* LPCTSTR */ L"EnvSdk_RegKey",               // environment variable name
            /* LPTSTR  */ &wszRegistrationRoot[cchDefRegRoot],// buffer for variable value
            /* DWORD   */ cchFreeBuffer);// size of buffer
        if (cchEnvVarRead >= cchFreeBuffer)
            return E_UNEXPECTED;
        // If the environment variable does not exist then we must use 
        // LREGKEY_VISUALSTUDIOROOT which has the version number.
        if (0 == cchEnvVarRead)
        {
            wcsncpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT, countof(wszRegistrationRoot));
            cchFreeBuffer = cchBuffer - lstrlenW(LREGKEY_VISUALSTUDIOROOT);
        }
    }
       
    CComBSTR cbstrRootBegin;
    CComBSTR cbstrRootEnd;
    
    // Make sure the string ends in backslash to simplify loop 
    // for processing backslashes.
    int len = (int)wcslen(wszRegistrationRoot);
    if(wszRegistrationRoot[len - 1] != L'\\')
    {
        wcsncat(wszRegistrationRoot, L"\\", cchFreeBuffer);
        --cchFreeBuffer;
    }

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
    DWORD dwLen = ::GetModuleFileNameW(_AtlModule.GetModuleInstance(), wszModuleFullName, cchBuffer);
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


HRESULT GetRegDefaultTemplatePath(
    /* [out] */ BSTR *      pbstrTemplatePath)
{
    _ASSERTE(pbstrTemplatePath != NULL);
    if (!pbstrTemplatePath)
        return E_POINTER;
    *pbstrTemplatePath = NULL;

    HRESULT hr = S_OK;

    const DWORD cchBuffer=_MAX_PATH;
    WCHAR wszModuleFullName[cchBuffer];
    DWORD dwLen = ::GetModuleFileNameW(_AtlModule.GetModuleInstance(), wszModuleFullName, cchBuffer);
    if (dwLen == 0)
        return HRESULT_FROM_WIN32(::GetLastError());
    if (dwLen == cchBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    // strip off the filename
    LPWSTR pwsz = wcsrchr(wszModuleFullName, L'\\');
    _ASSERTE(NULL != pwsz);
    if( pwsz != NULL )
        *pwsz = 0;

    // strip off 1 dir (debug\release)
    pwsz = wcsrchr(wszModuleFullName, L'\\');
    _ASSERTE(NULL != pwsz);
    if( pwsz != NULL )
        *(pwsz+1) = 0; //leave \ at the end

    CComBSTR cbstrInstallPath = wszModuleFullName;
    if (cbstrInstallPath.Length() == 0)
        return E_OUTOFMEMORY;

    *pbstrTemplatePath = cbstrInstallPath.Detach();

    return S_OK;
}


HRESULT GetRegDevenvPath(
    /* [out] */ BSTR *      pbstrDevenvPath)
{
    _ASSERTE(pbstrDevenvPath != NULL);
    if (!pbstrDevenvPath)
        return E_POINTER;

    HRESULT hr = S_OK;

    const DWORD cchBuffer=_MAX_PATH + 1;

    // get the reg hive
    WCHAR wszRegistrationRoot[cchBuffer];
    DWORD cchFreeBuffer = cchBuffer - 1;
    DWORD cchDefRegRoot = lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION) + 1;
    if (cchDefRegRoot >= cchFreeBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    wcsncpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT_NOVERSION, cchFreeBuffer);
    cchFreeBuffer -= lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION);
    wcsncat(wszRegistrationRoot, L"\\", cchFreeBuffer);
    --cchFreeBuffer;
    
    // this is Environment SDK specific
    // we check for  EnvSdk_RegKey environment variable to
    // determine where to register
    DWORD cchEnvVarRead = GetEnvironmentVariableW(
        /* LPCTSTR */ L"EnvSdk_RegKey",                    // environment variable name
        /* LPTSTR  */ &wszRegistrationRoot[cchDefRegRoot], // buffer for variable value
        /* DWORD   */ cchFreeBuffer);                      // size of buffer
    if (cchEnvVarRead >= cchFreeBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    // If the environment variable does not exist then we must use 
    // LREGKEY_VISUALSTUDIOROOT which has the version number.
    if (0 == cchEnvVarRead)
    {
        wcsncpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT, cchBuffer-1);
        wszRegistrationRoot[cchBuffer-1] = 0;
        cchFreeBuffer = cchBuffer - 1 - lstrlenW(LREGKEY_VISUALSTUDIOROOT);
    }

    const WCHAR wszVsSetup[] = L"\\Setup\\VS";
    if ((DWORD)lstrlenW(wszVsSetup) > cchFreeBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    wcsncat(wszRegistrationRoot, wszVsSetup, cchFreeBuffer);
    
    CRegKey keySetupVs;
    LONG lStatus = keySetupVs.Open(HKEY_LOCAL_MACHINE, W2CT(wszRegistrationRoot));
    if (lStatus != ERROR_SUCCESS)
        return E_UNEXPECTED;

    const TCHAR szVS7Location[]   = _T("VS7EnvironmentLocation");
    DWORD cchDevEnvBuffer = cchBuffer;
    TCHAR szDevenvPath[cchBuffer];

    lStatus = keySetupVs.QueryStringValue(szVS7Location ,szDevenvPath, &cchDevEnvBuffer);
    if (lStatus != ERROR_SUCCESS)
    {
        // try the environment directory
        cchDevEnvBuffer = cchBuffer;
        const TCHAR szEnvironmentDirectory[]   = _T("EnvironmentDirectory");
        lStatus = keySetupVs.QueryStringValue(szEnvironmentDirectory ,szDevenvPath, &cchDevEnvBuffer);
        if (lStatus != ERROR_SUCCESS)
            return E_FAIL;
        int len = lstrlen(szDevenvPath);
        if ((len <= 0) || (len >= cchBuffer - 2))
            return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

        if(szDevenvPath[len-1] != '\\' )
            _tcscat(szDevenvPath, _T("\\"));

        const TCHAR szDevenvExe[]   = _T("devenv.exe");
        if (lstrlen(szDevenvPath) + lstrlen(szDevenvExe) >= cchBuffer)
            return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
        _tcscat(szDevenvPath, szDevenvExe);
    }

    // now we have the devenv path
    CComBSTR cbstrDevenvPath = szDevenvPath;
    if (cbstrDevenvPath.Length() == 0)
        return E_OUTOFMEMORY;

    *pbstrDevenvPath = cbstrDevenvPath.Detach();
    return S_OK;
}

HRESULT GetRegProgidVersion(
    /* [out] */ BSTR *      pbstrProgidVersion)
{
    _ASSERTE(pbstrProgidVersion != NULL);
    if (!pbstrProgidVersion)
        return E_POINTER;

    // Set up the default value
    CComBSTR cbstrProgidVersion = RGS_VAR_PROGID_VERSION;
    if (cbstrProgidVersion.Length() == 0)
        return E_OUTOFMEMORY;

    HRESULT hr = S_OK;

    const DWORD cchBuffer=_MAX_PATH + 1;

    // get the environment variable EnvSdk_RegKey
    WCHAR wszEnvSdk_RegKey[cchBuffer];
    DWORD cchFreeBuffer = cchBuffer - 1;
    
    // this is Environment SDK specific
    // we check for  EnvSdk_RegKey environment variable to
    // determine the version number for our ProgID.
    DWORD cchEnvVarRead = GetEnvironmentVariableW(
        /* LPCTSTR */ L"EnvSdk_RegKey",               // environment variable name
        /* LPTSTR  */ wszEnvSdk_RegKey,               // buffer for variable value
        /* DWORD   */ cchFreeBuffer);                 // size of buffer
    if (cchEnvVarRead >= cchFreeBuffer)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    // If the environment variable does not exist then we must use 
    // RGS_VAR_PROGID_VERSION which has the version number.
    if (0 == cchEnvVarRead)
    {
        *pbstrProgidVersion = cbstrProgidVersion.Detach();
        return S_OK;
    }

    // We now look explicitly for version 7.0. If the environment variable doesn't
    // start with 7.0 we use the default RGS_VAR_PROGID_VERSION.
    if (wcsncmp(L"7.0", wszEnvSdk_RegKey, wcslen(L"7.0")) == 0)
        cbstrProgidVersion = L"7.0";

    *pbstrProgidVersion = cbstrProgidVersion.Detach();
    return S_OK;
}


//                                                       REGISTRATION UTILS
//=========================================================================


//=========================================================================
//                                                         Extender support
HRESULT GetExtender(
    /* [in]  */ LPCSTR          szguidCATID,
    /* [in]  */ IDispatch*      pIDispacth,
    /* [in]  */ BSTR            bstrExtenderName, 
    /* [out] */ IDispatch **    ppExtender)
{
    if (!bstrExtenderName)
        return E_INVALIDARG;
    ExpectedPtrRet(ppExtender);
    *ppExtender = NULL;

    HRESULT hr = S_OK;

    CComBSTR cbstrCATID(szguidCATID);
    if (cbstrCATID.Length() == 0)
        return E_OUTOFMEMORY;

    CComPtr<ObjectExtenders> srpExtMgr;
    // get internal ExtensionManager svc
    hr = _VxModule.QueryService(SID_SExtensionManager, IID_ObjectExtenders, (void **)&srpExtMgr);
    IfFailRet(hr);

    // call GetExtension on svc
    hr = srpExtMgr->GetExtender(cbstrCATID, bstrExtenderName, pIDispacth, ppExtender);
    IfFailRet(hr);

    return hr;
}


HRESULT GetExtenderNames(
    /* [in]  */ LPCSTR          szguidCATID,
    /* [in]  */ IDispatch*      pIDispacth,
    /* [out] */ VARIANT *pvarExtenderNames)
{
    ExpectedPtrRet(pvarExtenderNames);

    HRESULT hr = S_OK;
    CComBSTR cbstrCATID(szguidCATID);
    if (cbstrCATID.Length() == 0)
        return E_OUTOFMEMORY;
    
    // get internal ExtensionManager svc
    CComPtr<ObjectExtenders> srpExtMgr;
    hr = _VxModule.QueryService(SID_SExtensionManager, IID_ObjectExtenders, (void **)&srpExtMgr);
    IfFailRet(hr);

    // call GetExtensionNames on svc
    hr = srpExtMgr->GetExtenderNames(cbstrCATID, pIDispacth, pvarExtenderNames);
    IfFailRet(hr);

    return hr;
}


HRESULT GetExtenderCATID(
    /* [in]  */ LPCSTR          szguidCATID,
    /* [out] */ BSTR *pbstrRetval)
{
    ExpectedPtrRet(pbstrRetval);
    *pbstrRetval = NULL;

    HRESULT hr = S_OK;

    CComBSTR cbstrCATID(szguidCATID);
    if (cbstrCATID.Length() == 0)
        return E_OUTOFMEMORY;

    *pbstrRetval = cbstrCATID.Detach();
    
    return S_OK;
}
//                                                         Extender support
//=========================================================================


//=========================================================================
//                                                     Misc. helper classes

CSuspendFileChanges::CSuspendFileChanges(
    /* [in] */ const CString& strMkDocument, 
    /* [in] */ BOOL fSuspendNow /* = TRUE */) 
:
    m_strMkDocument(strMkDocument),
    m_fFileChangeSuspended(FALSE)
{
    if(fSuspendNow)
        Suspend();
}


CSuspendFileChanges::~CSuspendFileChanges()
{
    Resume();
}


void CSuspendFileChanges::Suspend()
{
    USES_CONVERSION;

    // Prevent suspend from suspending mroe than once
    if(m_fFileChangeSuspended)
        return;

    IVsRunningDocumentTable* pRDT = _VxModule.GetIVsRunningDocumentTable();
    ASSERT(pRDT);
    if (!pRDT)
        return;

    CComPtr<IUnknown> srpDocData;
    VSCOOKIE vscookie = VSCOOKIE_NIL;
    pRDT->FindAndLockDocument(RDT_NoLock, T2COLE(m_strMkDocument),  NULL, NULL, &srpDocData, &vscookie);
    if ( (vscookie == VSCOOKIE_NIL) || !srpDocData)
        return;

    CComPtr<IVsFileChangeEx> srpIVsFileChangeEx;
    HRESULT hr = _VxModule.QueryService(SID_SVsFileChangeEx, IID_IVsFileChangeEx, (void **)&srpIVsFileChangeEx);
    if (SUCCEEDED(hr) && srpIVsFileChangeEx)
    {
        m_fFileChangeSuspended = TRUE;
        srpIVsFileChangeEx->IgnoreFile(NULL, m_strMkDocument, TRUE); 
        srpDocData->QueryInterface(IID_IVsDocDataFileChangeControl, (void**)&m_srpIVsDocDataFileChangeControl);
        if(m_srpIVsDocDataFileChangeControl)
            m_srpIVsDocDataFileChangeControl->IgnoreFileChanges(TRUE);
    }
}


void CSuspendFileChanges::Resume()
{
    if(!m_fFileChangeSuspended)
        return;

    CComPtr<IVsFileChangeEx> srpIVsFileChangeEx;
    HRESULT hr = _VxModule.QueryService(SID_SVsFileChangeEx, IID_IVsFileChangeEx, (void **)&srpIVsFileChangeEx);
    if (SUCCEEDED(hr) && srpIVsFileChangeEx)

    srpIVsFileChangeEx->IgnoreFile(NULL, m_strMkDocument, FALSE); 
    if(m_srpIVsDocDataFileChangeControl)
        m_srpIVsDocDataFileChangeControl->IgnoreFileChanges(FALSE);
    m_fFileChangeSuspended = FALSE;
    m_srpIVsDocDataFileChangeControl.Release();
}
//                                                     Misc. helper classes
//=========================================================================
