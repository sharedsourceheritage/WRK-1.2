//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//
// hu_util.cpp : implementation of generic shared utilities
//-----------------------------------------------------------------------------


#include "hu_pch.h"
#include "mfcincl.h"
#include "hu_util.h"

//-----------------------------------------------------------------------------
// Execution context class. Allows program to set state about an execution through
// the use of key/value pairs. For example: the delete commaand could set the ctx
// IDYES for it's delete confirmation dialog. So when user checks "apply to all items"
// it won't prompt. The code can get back the ctx (in this case IDYES) and use
// that. The Start/EndSingleOp() method should be used at the start and end of an operation to
// flush out the context. MultiSelect handlers should use the start/end MultiOp 
// funcitons.
// The class provides a generic CANCELLED state since this applies across all items.
//-----------------------------------------------------------------------------
CExecutionCtx::CExecutionCtx()
  :
    m_bCancelled(FALSE),
    m_dwRef(0)
{
    m_exCtxArray.SetSize(0,5);
}

//----------------------------------------------------------------------------
// Cleans up object
//----------------------------------------------------------------------------
CExecutionCtx::~CExecutionCtx()
{
    Clear();
}

//----------------------------------------------------------------------------
// Clears all values from the ctx, including the cancelled status. 
//
//----------------------------------------------------------------------------
void CExecutionCtx::Clear()
{
    ClearData();
    m_dwRef = 0;
}

//----------------------------------------------------------------------------
// Clears all values from the ctx, including the cancelled status, but not ref count
//
//----------------------------------------------------------------------------
void CExecutionCtx::ClearData()
{
    for(int i=0; i< m_exCtxArray.GetSize(); i++)
    {
        CExCtx* pExCtx = m_exCtxArray[i];
        delete pExCtx;
    }
    m_exCtxArray.RemoveAll();
    m_bCancelled = FALSE;
}

//----------------------------------------------------------------------------
// Called to start an operation
//----------------------------------------------------------------------------
void CExecutionCtx::StartOp()
{
    if(m_dwRef == 0)
        Clear();
    ++m_dwRef;
}
//----------------------------------------------------------------------------
// Called at end operation
//----------------------------------------------------------------------------
void CExecutionCtx::EndOp()
{
    --m_dwRef;
    ASSERT(((int)m_dwRef) >= 0);
    if(((int)m_dwRef) < 0)
        m_dwRef = 0;
    if(m_dwRef == 0)
        Clear();
}

//----------------------------------------------------------------------------
// Returns the value at key, or 0 if not found.
//----------------------------------------------------------------------------
void* CExecutionCtx::GetValuePtr(DWORD key)
{
    CExCtx* pExCtx = GetExCtx(key);
    if(!pExCtx)
        return 0;
    return pExCtx->value;

}

//----------------------------------------------------------------------------
// Sets the value at key. If a value already exists, it is replaced.
//----------------------------------------------------------------------------
void CExecutionCtx::SetValuePtr(DWORD key, void* value)
{
    CExCtx* pExCtx = GetExCtx(key);
    if(!pExCtx)
    {
        if(value)
        {
            pExCtx = new CExCtx;
            ASSERT(pExCtx);
            if(!pExCtx)
                return;
            pExCtx->key = key;
            pExCtx->value = value;
            m_exCtxArray.Add(pExCtx);
        }
    }
    else
    {   // Setting a value to 0 effectively clears it.
        pExCtx->value = value;
    }

}

//----------------------------------------------------------------------------
// Searchs and returns the CExCtx structure for key.
//----------------------------------------------------------------------------
CExecutionCtx::CExCtx* CExecutionCtx::GetExCtx(DWORD key)
{
    for(int i=0; i< m_exCtxArray.GetSize(); i++)
    {
        CExCtx* pExCtx = m_exCtxArray[i];
        if(pExCtx->key == key)
            return pExCtx;
    }
    // Not found
    return NULL;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT LastWin32ErrorString(CString& strMsg)
{
    return Win32ErrorString(GetLastError(), strMsg);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT Win32ErrorString(DWORD dwError, CString& strMsg)
{
    LPVOID lpMsgBuf = NULL;
    HRESULT hr = S_OK;

    if (::FormatMessage(
            FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
            NULL,
            dwError,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR)&lpMsgBuf, 0, NULL))
    {
        ASSERT(lpMsgBuf != NULL);
        strMsg = (LPTSTR)lpMsgBuf;
    }
    else if (lpMsgBuf == NULL)
    {
        hr = E_OUTOFMEMORY;
    }
    else
    {
        ASSERT(!_T("programmer error"));
        hr = E_UNEXPECTED;
    }
    LocalFree(lpMsgBuf);
    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CErrorInfo::ReportError(HRESULT hRes, LPCTSTR lpszDesc)
{
    m_dwResult = hRes;
    m_strErrorDescription = lpszDesc;
    return m_dwResult;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CErrorInfo::ReportErrorWin32(DWORD dwError)
{
    Win32ErrorString(dwError, m_strErrorDescription);
    m_dwResult = HRESULT_FROM_WIN32(dwError);
    return m_dwResult;
}

//---------------------------------------------------------------------------
// Formats error string
//---------------------------------------------------------------------------
HRESULT __cdecl CErrorInfo::ReportError(HRESULT hRes, LPCTSTR  lpszFormat, ...)
{
    va_list argList;
    va_start(argList, lpszFormat);

    LPTSTR lpsz = NULL;

    ::FormatMessage(FORMAT_MESSAGE_FROM_STRING|FORMAT_MESSAGE_ALLOCATE_BUFFER, lpszFormat, 0, 0, (LPTSTR)&lpsz, 0, &argList);
    m_strErrorDescription = lpsz;
    LocalFree(lpsz);
    va_end(argList);
    m_dwResult = hRes;
    return m_dwResult;
}

//---------------------------------------------------------------------------
// Formats error string
//---------------------------------------------------------------------------
HRESULT __cdecl CErrorInfo::ReportError(HRESULT hRes, UINT nFormatID, ...)
{

    va_list argList;
    va_start(argList, nFormatID);

    LPTSTR lpsz = NULL;
    m_strErrorDescription.LoadString(nFormatID);
    ::FormatMessage(FORMAT_MESSAGE_FROM_STRING|FORMAT_MESSAGE_ALLOCATE_BUFFER, m_strErrorDescription, 0, 0, (LPTSTR)&lpsz, 0, &argList);
    m_strErrorDescription = lpsz;;
    LocalFree(lpsz);

    va_end(argList);
    m_dwResult = hRes;
    return m_dwResult;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
const CString& CErrorInfo::GetReportedErrorDescription(void) const
{
    return m_strErrorDescription;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CErrorInfo::GetReportedErrorHRESULT(void) const
{
    return m_dwResult;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CErrorInfo::ConvertReportedErrorToErrorInfo(const CLSID& clsid, const IID& iid)
{
    if (FAILED(m_dwResult))
        return AtlReportError(clsid, m_strErrorDescription, iid, m_dwResult);
    return m_dwResult;
}

//---------------------------------------------------------------------------
// dw should be initiailzed to 0
// bstr should be initialized to NULL
// at return, if dw is non-zero then a numeric index is to be used
//            else if bstr is non-NULL then a string index is to be used
//---------------------------------------------------------------------------
void Variant2Value(const VARIANT& vt, long &dw, BSTR &bstr)
{
    ASSERT(0 == dw);
    ASSERT(NULL == bstr);

    switch(V_VT(&vt))
    {
    case VT_I2:
        dw = V_I2(&vt);
        break;
    case VT_I4:
        dw = V_I4(&vt);
        break;
    case VT_BSTR:
        bstr = V_BSTR(&vt);
        break;
    case VT_UI2:
        dw = V_UI2(&vt);
        break;
    case VT_UI4:
        ASSERT(V_UI4(&vt) <= LONG_MAX);
        dw = V_UI4(&vt);
        break;
    case VT_I2|VT_BYREF:
        dw = *V_I2REF(&vt);
        break;
    case VT_I4|VT_BYREF:
        dw = *V_I4REF(&vt);
        break;
    case VT_BSTR|VT_BYREF:
        bstr = *V_BSTRREF(&vt);
        break;
    case VT_UI2|VT_BYREF:
        dw = *V_UI2REF(&vt);
        break;
    case VT_UI4|VT_BYREF:
        ASSERT(*V_UI4REF(&vt) <= LONG_MAX);
        dw = *V_UI4REF(&vt);
        break;
    }
}

//---------------------------------------------------------------------------
// ShowContextMenu
//---------------------------------------------------------------------------
HRESULT ShowContextMenu(UINT iCntxtMenuID, REFGUID GroupGuid, IOleCommandTarget* pIOleCmdTarg)
{
    CComPtr<IOleComponentUIManager> srpUIManager;
    HRESULT hr = _VxModule.QueryService(SID_SOleComponentUIManager, IID_IOleComponentUIManager, (void **)&srpUIManager);
    if (srpUIManager != NULL)
    {
        POINT  pnt;
        ::GetCursorPos(&pnt);
        POINTS pnts = { (SHORT)pnt.x, (SHORT)pnt.y };

        hr = srpUIManager->ShowContextMenu(0, GroupGuid, iCntxtMenuID, pnts, pIOleCmdTarg);
    }
    return hr;
}

//---------------------------------------------------------------------------
// ShowContextMenu - same as above except that it takes a points structure to 
// place the menu.
//---------------------------------------------------------------------------
HRESULT ShowContextMenu(UINT iCntxtMenuID, REFGUID GroupGuid, IOleCommandTarget* pIOleCmdTarg, POINTS points)
{
    CComPtr<IOleComponentUIManager> srpUIManager;
    HRESULT hr = _VxModule.QueryService(SID_SOleComponentUIManager, IID_IOleComponentUIManager, (void **)&srpUIManager);
    if (srpUIManager != NULL)
    {
        hr = srpUIManager->ShowContextMenu(0, GroupGuid, iCntxtMenuID, points, pIOleCmdTarg);
    }
    return hr;
}

//-----------------------------------------------------------------------------
// Returns TRUE if successfully sets the menu text. You can pass a NULL pCmdText.
// Function will fail if you do so.
//-----------------------------------------------------------------------------
BOOL LoadOLECMDTEXT(LPCTSTR pszMenuText, OLECMDTEXT* pCmdText)
{
    if(pCmdText)
    {
        ASSERT(_tcslen(pszMenuText) < pCmdText->cwBuf);
#ifdef _UNICODE
        ULONG charCount = (ULONG) _tcslen(pszMenuText);
        if (charCount > pCmdText->cwBuf - 1)
            charCount = pCmdText->cwBuf - 1;
#else
        ULONG charCount = MultiByteToWideChar(CP_ACP, MB_ERR_INVALID_CHARS, pszMenuText, -1, pCmdText->rgwz, pCmdText->cwBuf);
        if (charCount == 0 && pCmdText->cwBuf > 0)
            pCmdText->rgwz[0] = _T('\0');
#endif
        if(charCount)
        {
#ifdef _UNICODE
            _tcsncpy(pCmdText->rgwz, pszMenuText, pCmdText->cwBuf - 1);
            pCmdText->rgwz[pCmdText->cwBuf - 1] = _T('\0');
#endif
            
            pCmdText->cwActual = charCount;
            return TRUE;
        }
    }
    return FALSE;
}

//-----------------------------------------------------------------------------
// Returns TRUE if successfully sets the menu text.You can pass a NULL pCmdText.
// Function will fail if you do so.
//-----------------------------------------------------------------------------
BOOL LoadOLECMDTEXT(UINT nID, OLECMDTEXT* pCmdText)
{
    if(pCmdText == NULL)
        return FALSE;
    CString strMenuText;
    strMenuText.LoadString(nID);
    return ::LoadOLECMDTEXT(strMenuText, pCmdText);
}

//-----------------------------------------------------------------------------
//  Creates the directory strDirName. Unlike CreateDirectory() this function will
//  create all the intermediate directories along the way. Note you MUST provide 
//  the full path! It also sets a WIN32 error on all failures
//-----------------------------------------------------------------------------
BOOL UtilCreateDirectory(LPCTSTR strDirName)
{
    // Extract the root name of the volume. Note that we must allow for a null and the
    // possibility of appending a trailing slash. Hence the allocation size is the number of
    // characters plus 1 for the null (cbLen) plus 1 more.
    size_t len = _tcslen(strDirName);
    size_t cbLen = (len + 1) * sizeof(TCHAR);
    TCHAR* szRoot = (TCHAR*)_alloca(cbLen + sizeof(TCHAR));
    memcpy(szRoot, strDirName, cbLen);

    if(len > 1 && IsDirSep(szRoot[0]) && IsDirSep(szRoot[1]))
    {   
        // It is a UNC name, find second slash past '\\'
        LPTSTR lpsz = &szRoot[2];
        while (*lpsz != _T('\0') && (!IsDirSep(*lpsz)))
            lpsz = _tcsinc(lpsz);
        if (*lpsz != _T('\0'))
            lpsz = _tcsinc(lpsz);
        while (*lpsz != _T('\0') && (!IsDirSep(*lpsz)))
            lpsz = _tcsinc(lpsz);
        // Terminate after the UNC root (ie. '\\server\share\')
        if (*lpsz != _T('\0'))
            lpsz[1] = _T('\0');
    }
    else
    {
        // Not a UNC, look for just the first slash
        LPTSTR lpsz = szRoot;
        while (*lpsz != _T('\0') && (!IsDirSep(*lpsz)))
            lpsz = _tcsinc(lpsz);
        // Terminate it just after root (ie. 'x:\')
        if (*lpsz != _T('\0'))
            lpsz[1] = _T('\0');
    }

    // Figure out offset past the volume info and set buffer ptr there.
    TCHAR* buffer = (TCHAR*)_alloca(cbLen + sizeof(TCHAR));
    memcpy(buffer, strDirName, cbLen);
    TCHAR* pPath = &buffer[_tcsclen(szRoot)];

    DWORD dwAttributes;
    TCHAR* pNextToken = _tcstok( pPath, _T("\\/"));
    while(pNextToken)
    {
        // Append token to path so far
        _tcscat(szRoot, pNextToken);
        
        // If this subdir hasn't been created, do so.
        // and make sure that there isn't a file of this name already
        dwAttributes = ::GetFileAttributes(szRoot);
        if( (dwAttributes == -1) || !(dwAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
                if(!::CreateDirectory(szRoot, NULL) )
                {   // Failed create of subdir
                    return FALSE;
                }
        }
    
        // Add in separator and get next part of path
        _tcscat(szRoot, _T("\\"));
        pNextToken = _tcstok( NULL, _T("\\/"));
    }
    
    // Made it all the way through.
    return TRUE;
}

//-----------------------------------------------------------------------------
// load a string from registry to BSTR with all the checkings
// if the loaded string is empty
//-----------------------------------------------------------------------------
HRESULT UtilLoadStringToBSTR(int nID, BSTR *pbstr, HINSTANCE hInstance)
{
    ASSERT(NULL != hInstance);
    if (NULL == pbstr)
        return E_POINTER;

    WCHAR szwBuf[1024];

    ::SetLastError(0);
#ifdef _UNICODE
    int nLen = ::LoadString(hInstance, nID, szwBuf, 1024);
    // LoadString doesn't includes the '\0' in the count
#else
    CHAR szaBuf[1024];
    int nLen = ::LoadString(hInstance, nID, szaBuf, 1024);
    if (nLen && nLen < 1024)
    {
        nLen = ::MultiByteToWideChar(CP_ACP, 0, szaBuf, nLen, szwBuf, 1024);
        // MultiByteToWideChar includes the '\0' in the count
        if (nLen)
        {
            nLen -= 1;
        }
    }
#endif
    if (nLen && nLen < 1024)
    {
        *pbstr = ::SysAllocStringLen(szwBuf, nLen);
        return (NULL != *pbstr) ? S_OK : E_OUTOFMEMORY;
    }
    *pbstr = NULL;
    return HRESULT_FROM_WIN32(::GetLastError());
}

//-----------------------------------------------------------------------------
// convert an array of nIDS to a CALPOLESTR
// if NULL == rgVALS, pCaCookiesOut is filled out from 0 - (nCount-1)
//-----------------------------------------------------------------------------
HRESULT UtilLoadPredefinedStrings(int nCount, const int *rgIDS, const DWORD *rgVALS,
            CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut,
            HINSTANCE hInstance)
{
    ASSERT(0 < nCount && NULL != rgIDS);
    ASSERT(NULL != pCaStringsOut && NULL != pCaCookiesOut);
    ASSERT(NULL != hInstance);

    int nLen, i = 0;
    WCHAR szwBuf[1024];
#ifndef _UNICODE
    CHAR szaBuf[1024];
#endif

    pCaStringsOut->cElems = nCount;
    pCaCookiesOut->cElems = nCount;

    pCaStringsOut->pElems = (LPWSTR *)::CoTaskMemAlloc(nCount * sizeof(LPWSTR));
    if (NULL == pCaStringsOut->pElems)
        goto ERROR_JUMP;

    pCaCookiesOut->pElems = (DWORD *)::CoTaskMemAlloc(nCount * sizeof(DWORD));
    if (NULL == pCaCookiesOut->pElems)
        goto ERROR_JUMP;

    for (; i < nCount; ++i)
    {
#ifdef _UNICODE
        nLen = ::LoadString(hInstance, rgIDS[i], szwBuf, 1024);
        if (nLen)
        {   // LoadString doesn't includes the '\0' in the count
            nLen += 1;
        }
#else
        nLen = ::LoadString(hInstance, rgIDS[i], szaBuf, 1024);
        if (nLen && nLen < 1024)
        {
            nLen = ::MultiByteToWideChar(CP_ACP, 0, szaBuf, nLen, szwBuf, 1024);
            // MultiByteToWideChar includes the '\0' in the count
        }
#endif
        if (nLen && nLen < 1024)
        {
            // convert # characters to byte count
            nLen *= sizeof(WCHAR);

            pCaStringsOut->pElems[i] = (LPWSTR)::CoTaskMemAlloc(nLen);
            if (NULL == pCaStringsOut->pElems[i])
                goto ERROR_JUMP;
            memcpy(pCaStringsOut->pElems[i], szwBuf, nLen);
        }
        else pCaStringsOut->pElems[i] = NULL;
        if (NULL != rgVALS)
            pCaCookiesOut->pElems[i] = rgVALS[i];
        else pCaCookiesOut->pElems[i] = i;
    }
    return S_OK;

ERROR_JUMP:
    pCaStringsOut->cElems = 0;
    pCaCookiesOut->cElems = 0;

    if (NULL != pCaStringsOut->pElems)
    {
        ASSERT(NULL == pCaStringsOut->pElems[i]);   // this is the failure
        while (i--)
        {
            if (NULL != pCaStringsOut->pElems[i])
                ::CoTaskMemFree(pCaStringsOut->pElems[i]);
        }
        ::CoTaskMemFree(pCaStringsOut->pElems);
        
        if (NULL != pCaCookiesOut->pElems)
        {   // it won't allocate cookies unless it allocated strings
            ::CoTaskMemFree(pCaCookiesOut->pElems);
        }
    }
    pCaStringsOut->pElems = NULL;
    pCaCookiesOut->pElems = NULL;
    return E_OUTOFMEMORY;
}

//-----------------------------------------------------------------------------
//  UtilConvertToRelativeURL
//
//  Returns an item-relative URL.
//      The URL is returned identical if
//          the projects don't match
//          the protocols don't match
//
//  Assumes that protocol-less URLs are "http:". Must specify "file:" explicitly
//  to play with file URLs. 
//-----------------------------------------------------------------------------


static LPOLESTR
SkipServer(LPOLESTR pstr)
{
    pstr = wcschr(pstr, L'/');
    if (pstr == NULL)
        return NULL;
    pstr = wcschr(pstr+1, L'/');
    if (pstr == NULL)
        return NULL;
    pstr = wcschr(pstr+1, L'/');

    return pstr;            // positioned on the slash if there was one.
}

static LPOLESTR
SkipFile(LPOLESTR pstr)
{
    LPOLESTR    pstrT;

    pstrT = wcspbrk(pstr, L":\\/");
    if (pstrT == NULL)
        return pstr;

    // Guard against the case "//\\".

    if (pstrT == pstr &&
            IsDirSep(pstr[0]) &&
            IsDirSep(pstr[1]))
    {
        if (IsDirSep(pstr[2]) && IsDirSep(pstr[3]))
        {
            pstrT = pstr + 2;           // saw a "//\\"
        }
        else if (pstr[2] != L'\0'  && pstr[3] == L':')
        {
            pstrT = pstr + 3;           // saw a "//c:"
        }
        else if (IsDirSep(pstr[2]) && pstr[3] != L'\0' && pstr[4] == L':')
        {
            pstrT = pstr + 4;           // saw a "///c:"
        }
    }

    ASSERT(!wcschr(pstrT + 1, ':')); // better not be more colons!
    if (*pstrT == ':')  // drive letter possibility
    {
        return pstrT + 1;               // point at the character after the colon
    }
    if (pstrT[0] == pstrT[1])           // double slash?
    {
        // Skip server part. 

        pstrT = wcspbrk(pstrT + 2, L"\\/");
        if (pstrT == NULL)
            return pstr;                // malformed!

        // Skip share part.

        pstrT = wcspbrk(pstrT + 1, L"\\/");
        if (pstrT == NULL)
            return pstr;                // malformed!

        return pstrT;
    }

    return pstr;
}

static LPOLESTR
FindLastSlash(LPOLESTR pstr)
{
    LPOLESTR    pstrSlash;      // '/'
    LPOLESTR    pstrWhack;      // '\'

    pstrSlash = wcsrchr(pstr, L'/');
    pstrWhack = wcsrchr(pstr, L'\\');

    return pstrSlash > pstrWhack
            ? pstrSlash
            : pstrWhack;
}

HRESULT
UtilConvertToRelativeURL(
    LPOLESTR    pstrDestURL,        // URL to 'relativize'
    LPOLESTR    pstrDestFolder,     // URL to be relative to.
    LPOLESTR    pstrDestProject,    // Project to be relative to.
    BSTR *      pbstrRelativeURL)
{
    HRESULT     hr = S_OK;
    LPOLESTR    pstrFolder;
    LPOLESTR    pstrURL;
    LPOLESTR    pchLastSlash;
    CString     strWork;
    int         cch;
    int         cchFolder;
    int         i;
    int         ichLastSlash;
    bool        fAbsoluteURL = false;
    bool        fAbsoluteFolder = false;
    bool        fFileURL = false;

    // If there's a ':' in the URL we're relativizing, it's assumed
    // to contain the protocol. 

    pstrURL = pstrDestURL;
    if (wcschr(pstrDestURL, L':'))
    {
        // Check the protocol against the two we understand. If it is some other thing,
        // we punt.

        if (wcsncmp(pstrDestURL, L"http:", 5) != 0)
        {
            if (wcsncmp(pstrDestURL, L"file:", 5) != 0)
                goto Copy;

            // File URLs are normalized by skipping any '\\server\share' part.

            fFileURL = true;
            pstrURL = SkipFile(pstrDestURL + 5); // 5 skips the 'file:' prefix
        }
        else if (pstrDestProject != NULL)
        {
            // Project-relative URLs had better match the project prefix.

            cch = (int)wcslen(pstrDestProject);
            if (0 >= cch || _wcsnicmp(pstrDestURL, pstrDestProject, cch) != 0)
                goto Copy;

            // Project-relative URLs are normalized by skipping the project prefix.
            pstrURL = pstrDestURL + cch - 1;
            ASSERT(*pstrURL == '/');
        }
        else
        {
            // Generic 'http:' URLs skip the server part only.
            pstrURL = SkipServer(pstrDestURL);
        }

        if (!pstrURL)
            goto Copy;
        fAbsoluteURL = true;
    }

    // If the folder contains an 'http:' prefix, then find the server and skip that part.
    // otherwise it's assumed the folder is already in a project-relative format.

    pstrFolder = pstrDestFolder;
    if (wcsncmp(pstrDestFolder, L"file://", 7) == 0)
    {
        if (!fFileURL)
            goto Copy;

        pstrFolder = SkipFile(pstrDestFolder + 5);
        fAbsoluteFolder = true;
    }
    else 
    {
        if (wcsncmp(pstrDestFolder, L"http://", 7) == 0)
        {
            if (pstrDestProject != NULL)
            {
                // If a project was passed in, make sure the place we're relativizing to has the same path.
                // If they don't match, we're in trouble.

                cch = (int)wcslen(pstrDestProject);
                if (0 >= cch || _wcsnicmp(pstrDestFolder, pstrDestProject, cch) != 0)
                    goto Copy;
                pstrFolder = pstrDestFolder + cch - 1;
            }
            else
            {
                pstrFolder = SkipServer(pstrDestFolder);
            }

            if (!pstrFolder)
                goto Copy;
            
            fAbsoluteFolder = true;
        }
        else
        {   // neither file: nor http:, then look for a drive letter
            cch = (int)wcslen(pstrDestFolder);
            if(1 < cch && L':' == pstrDestFolder[1])
                fAbsoluteFolder = true;
        }
    }

    // If both the URL and the folder had absolute paths, we need to ensure
    // that the servers are the same.

    if (fAbsoluteFolder && fAbsoluteURL)
    {
        if (pstrURL - pstrDestURL != pstrFolder - pstrDestFolder ||
                _wcsnicmp(pstrDestURL, pstrDestFolder, (LONG32) (pstrURL - pstrDestURL)) != 0)
            goto Copy;
    }

    // From now on, ignore the item at the end of pstrFolder

    pchLastSlash = FindLastSlash(pstrFolder);
    ASSERT(pchLastSlash);
    cchFolder = 1 + (LONG32) (pchLastSlash - pstrFolder);

    // Both folder and item are now relative to the server root.

    // Locate the last slash in the URL. 

    pchLastSlash = FindLastSlash(pstrURL);

    if (pchLastSlash == NULL)
        ichLastSlash = 0;
    else
        ichLastSlash = 1 + (LONG32) (pchLastSlash - pstrURL);

    // Find any common directories. 

    cch = min(cchFolder, ichLastSlash);
    ichLastSlash = -1;
    for (i = 0; i < cch && pstrFolder[i] == pstrURL[i]; ++i)
    {
        if (IsDirSep(pstrFolder[i]))
            ichLastSlash = i;
    }

    // ichLastSlash should point beyond at last slash of the last common folder.

    // For each remaining slash, append a ../ to the path.

    for (; i < cchFolder; ++i)
    {
        if (IsDirSep(pstrFolder[i]))
        {
            strWork += (fFileURL ? L"..\\" : L"../");
        }
    }

    if (-1 == ichLastSlash)
    {   // no common parts, append all of the destination
        strWork += pstrURL;
    }
    else
    {   // append only the non-match part of the destination

        strWork += (pstrURL + ichLastSlash + 1);
    }


Cleanup:
    *pbstrRelativeURL = strWork.AllocSysString();
    if (!*pbstrRelativeURL && strWork.GetLength() > 0)
        hr = E_OUTOFMEMORY;

    return hr;

Copy:
    strWork = pstrDestURL;
    goto Cleanup;
}

//-----------------------------------------------------------------------------
// Renames the open doc. If rename fails, file is transferred to misc files project. 
// If bMoveToMiscProj = TRUE then the RDT rename is skipped and file put directly into
// Misc files project.
// 
// !!! Note that you must pass a valid hierachy ptr, not constants like HIERARCHY_DONTCHANGE.
//-----------------------------------------------------------------------------
HRESULT LUtilRenameOpenDoc(LPCTSTR pszOldName, LPCTSTR pszNewName, IVsUIHierarchy* pHier,
                          VSITEMID itemId, BOOL bMoveToMiscProj /*= FALSE*/)
{
    USES_CONVERSION;

    HRESULT hr = E_FAIL;
    IVsRunningDocumentTable* pRDT = _VxModule.GetIVsRunningDocumentTable();
    if(pRDT != NULL)
    {   
        if(!bMoveToMiscProj)
        {
            //both pszOldName and pszNewName should be OLE Strings
            hr = pRDT->RenameDocument(T2COLE(pszOldName), T2COLE(pszNewName), pHier, itemId);
        }
        // If rename Doc fails, or renaming to misc project..
        if(bMoveToMiscProj || hr != S_OK)
        {   // Transfer to external files project
            CComPtr<IVsExternalFilesManager> srpEFM;
            hr = _VxModule.QueryService(SID_SVsExternalFilesManager, IID_IVsExternalFilesManager, (void **)&srpEFM);
            ASSERT(srpEFM);
            if(srpEFM)
            {   // Get the shell so we can ask for a doc window to get the window frame
                IVsUIShellOpenDocument* pVsUIShellOpenDoc = _VxModule.GetIVsUIShellOpenDocument();
                if(pVsUIShellOpenDoc)
                {   // Need window frame
                    CComPtr<IVsWindowFrame> srpDocFrame;
                    BOOL  bOpen = FALSE;
                    pVsUIShellOpenDoc->IsDocumentOpen(pHier, itemId, T2COLE(pszOldName), GUID_NULL, IDO_IgnoreLogicalView,
                                                NULL, NULL, &srpDocFrame, &bOpen);
                    // We transfer to misc files. Note that srpDocFrame will be null if the document is not
                    // opened in a window.
                    hr = srpEFM->TransferDocument(T2COLE(pszOldName), bMoveToMiscProj ? T2COLE(pszNewName) : T2COLE(pszOldName) ,srpDocFrame);
                    if(FAILED(hr))
                    {   
                        // On failure we must try to close the open document. 
                        ASSERT(FALSE);
                        VSCOOKIE dwDocCookie = 0;
                        hr = _VxModule.GetIVsRunningDocumentTable()->FindAndLockDocument(RDT_NoLock, T2COLE(pszOldName), NULL, NULL, NULL, &dwDocCookie);
                        if(dwDocCookie)
                            hr =  _VxModule.GetIVsSolution()->CloseSolutionElement(SLNSAVEOPT_NoSave, pHier, dwDocCookie);
                    }
                }
            }
        }
    }
    ASSERT(SUCCEEDED(hr));
    return hr;
}

//-----------------------------------------------------------------------------
// Returns the debug mode of the shell (design/break/shell)
//-----------------------------------------------------------------------------
DBGMODE LUtilGetDebugMode()
{
    DBGMODE dbgmode = DBGMODE_Design;
    IVsDebugger* pDebugger = _VxModule.GetIVsDebugger();
    if(pDebugger) 
        pDebugger->GetMode(&dbgmode);
    return dbgmode;
}

//----------------------------------------------------------------------------
//  Determines if the interface riid is in the ATL interface map pointed
//  to by pAIE. If an interface entry in the interface map is a chain
//  entry to a base class, this function recursively visits the interface
//  map of the base class.
//----------------------------------------------------------------------------
HRESULT UtilQuerySupport(const _ATL_INTMAP_ENTRY * pAIE, REFIID riid)
{
    ASSERT(pAIE);

    while (pAIE->pFunc != NULL)
    {
        if (pAIE->piid == NULL)
        {
            if (pAIE->pFunc == CComObjectRootBase::_Chain)
            {
                _ATL_CHAINDATA* pcd = (_ATL_CHAINDATA*) pAIE->dw;
                if (UtilQuerySupport(pcd->pFunc(), riid) == S_OK)
                    return S_OK;
            }
        }
        else
        {
            if (pAIE->piid && InlineIsEqualGUID(*pAIE->piid,riid))
                return S_OK;
        }

        ++pAIE;
    }
    return S_FALSE;
}

