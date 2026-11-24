
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
//*****************************************************************************

#include "stdafx.h"

///////////////////////////////////////////////////////////////////////////////
// GetResourceURL - Builds up a res:// URL

HRESULT GetResourceURL(const WCHAR* wszName, 
                       BOOL fUIDLL, 
                       BSTR* pbstrURL)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" GetResourceURL \n") );
    _ASSERTE(pbstrURL);
    if (!pbstrURL)
        return E_POINTER;
    if (!wszName)
        return E_POINTER;
    InitParam(pbstrURL);

    WCHAR wszDllPath[_MAX_PATH];
    DWORD dwLen = ::GetModuleFileNameW(fUIDLL ? _AtlBaseModule.GetResourceInstance() : _AtlBaseModule.GetModuleInstance(), wszDllPath, _MAX_PATH);
    if (dwLen == 0)
        return HRESULT_FROM_WIN32(::GetLastError());
    if (dwLen == _MAX_PATH)
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    // add 8 to fit in NULL terminator and the res:// and extra / chars
    int iURLlen = lstrlenW(wszDllPath) + lstrlenW(wszName) + 8;
    (*pbstrURL) = SysAllocStringLen(NULL, iURLlen);

    if ((*pbstrURL) == NULL)
        return E_OUTOFMEMORY;
    
    swprintf(*pbstrURL, iURLlen, L"res://%s/%s", wszDllPath, wszName);
    return S_OK;
}

void UpdateCommandUI(BOOL fImmediate)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" UpdateCommandUI \n") );

    IVsUIShell* pUIShell = _VxModule.GetIVsUIShell();      // un-addref'd

    if (pUIShell)
    {
        pUIShell->UpdateCommandUI(fImmediate);
    }
}


///////////////////////////////////////////////////////////////////////////////
// Brings up the Environment Messagebox with the strings passed in
long ShowMessage(
    /* [in] */ LPCTSTR          lpszTitle, 
    /* [in] */ LPCTSTR          lpszMsg, 
    /* [in] */ UINT             nIDHelp,
    /* [in] */ OLEMSGBUTTON     nButtons, 
    /* [in] */ OLEMSGDEFBUTTON  nDefButton,
    /* [in] */ OLEMSGICON       nIcon, 
    /* [in] */ BOOL             fAlert)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" ShowMessage \n") );

    _ASSERTE(lpszTitle);
    _ASSERTE(lpszMsg);
    if (!lpszTitle)
        return -1;
    if (!lpszMsg)
        return -1;

    USES_CONVERSION;

    CComPtr<IOleComponentUIManager> srpCompUIMgr;
    HRESULT hr = E_FAIL;
    long nResult;

    hr = _VxModule.QueryService(SID_SOleComponentUIManager, IID_IOleComponentUIManager,
                      (void **)&srpCompUIMgr);
    if (FAILED(hr) || !srpCompUIMgr)
        return -1;

    hr = srpCompUIMgr->ShowMessage(
       /* DWORD dwCompRole          */ OLEROLE_TOPLEVELCOMPONENT,
       /* REFCLSID rclsidComp       */ GUID_NULL,
       /* LPOLESTR pszTitle         */ CT2OLE(lpszTitle),
       /* LPOLESTR pszText          */ CT2OLE(lpszMsg),
       /* LPOLESTR pszHelpFile      */ (nIDHelp != -1) ? T2W((LPTSTR)_VxModule.GetModuleHelpFile()) : NULL,
       /* DWORD dwHelpContextID     */ nIDHelp,
       /* OLEMSGBUTTON msgbtn       */ nButtons,
       /* OLEMSGDEFBUTTON msgdefbtn */ nDefButton,
       /* OLEMSGICON msgicon        */ nIcon,
       /* BOOL fSysAlert            */ fAlert,
       /* [retval] LONG* pnResult   */ &nResult);
    _ASSERTE(SUCCEEDED(hr));
    return nResult;
}


void Append (CString& str, TCHAR* lpsz, int cch)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" Append \n") );

    if (lpsz)
    {
        CString strTemp(lpsz, cch);    
        str+=strTemp;
    }
}


