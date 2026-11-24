//--------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (c) 1994-2000 Microsoft Corporation Inc.
// All rights reserved
//
//
// langutil.cpp : Implementation of useful functions
//---------------------------------------------------------------------------
#include "hu_pch.h"
#include "hu_util.h"
#include "lutil.h"
#include "datetime.h"

// for NT security functions
typedef BOOL (WINAPI *OPENTHREADTOKEN)(HANDLE, DWORD, BOOL, PHANDLE); 
typedef BOOL (WINAPI *OPENPROCESSTOKEN)(HANDLE, DWORD, PHANDLE); 
typedef BOOL (WINAPI *GETTOKENINFORMATION)(HANDLE, TOKEN_INFORMATION_CLASS, LPVOID, DWORD,PDWORD);
typedef BOOL (WINAPI *LOOKUPACCOUNTSID)(LPCTSTR, PSID, LPTSTR, LPDWORD, LPTSTR, LPDWORD, PSID_NAME_USE);

#define COMPARE_FILENAMES   _tcsicmp
#define COMPARE_NOCASE      _tcsicmp

//-----------------------------------------------------------------------------
//  Returns TRUE if folder is _private, or starts with _vti_
//-----------------------------------------------------------------------------
BOOL LUtilFolderContainsReserved(LPCTSTR pszFolderName)
{
    return (_tcsnicmp(pszFolderName, _T("_vti"), 4) == 0);
}

//-----------------------------------------------------------------------------
// Converts the project file path to a project name
//-----------------------------------------------------------------------------
CString LUtilProjNameFromPath(LPCTSTR pszPath) 
{
    CString strProjName;
    TCHAR szName [_MAX_FNAME + _MAX_EXT];
    _tsplitpath(pszPath, NULL, NULL, szName, NULL);

    strProjName = szName;
    return strProjName;
} // ProjNameFromPath

//-----------------------------------------------------------------------------
// Converts the WCHAR to and OLECHAR. Note that the returned OLECHAR is
// allocated with CoTaskMemAlloc and MUST be freed with CoTaskMemFree.
//-----------------------------------------------------------------------------
OLECHAR* LUtilWCHARToOleChar(const WCHAR* szString)
{
    // Allocate an OLECHAR and copy the string
    size_t len = wcslen(szString);
    OLECHAR* pOleChar = (OLECHAR*)CoTaskMemAlloc((len+1) * sizeof(OLECHAR));
    if(pOleChar)
        wcscpy(pOleChar, szString);
    return pOleChar;
} // LUtilWCHARToOleChar

//-----------------------------------------------------------------------------
// very similar to LUtilHaveTrailingTChar except that it replaces the last
// character with null char if ch is found.
//-----------------------------------------------------------------------------
void LUtilRemoveTrailingWCHAR (LPWSTR sz, WCHAR ch)
{
    WCHAR *pLast;
    
    // find last occurrence of ch in sz. 
    pLast = wcsrchr(sz, ch);
    // Now, if it is the last character in the string, replace it with null char.
    if ((pLast != NULL) && (*(pLast+1) == L'\0'))
        *pLast = L'\0';
} // LUtilRemoveTrailingWCHAR

//-----------------------------------------------------------------------------
//  Returns TRUE if the string only contains whitespace
//  This function is MBCS aware.
//-----------------------------------------------------------------------------
BOOL LUtilIsBlankString(LPCTSTR string)
{
    LPCTSTR temp = string;
    while(*temp)
    {
        if(!_istspace(*temp))
            return FALSE;
        temp = _tcsinc(temp);
    }
    return TRUE;
}

//-----------------------------------------------------------------------------
//  Returns TRUE if name contains invalid filename characters. This function is
//  MBCS aware. This is a less restrictive
// fn used for validating existing files. For validating new names of projects and 
// items use VspContainsInvalidFileNameChars.
//-----------------------------------------------------------------------------
BOOL LUtilContainsInvalidFileChars(LPCTSTR pszName)
{
    if(_tcspbrk(pszName, _T("\\/:*?\"<>|")) || _tcscmp(pszName, _T("."))==0)
        return TRUE;
    return FALSE;
}

//-----------------------------------------------------------------------------
// Returns TRUE if name contains invalid filename characters. Slightly different
// check if bIsUrl is TRUE. This function is MBCS aware. This is a less restrictive
// fn used for validating existing files. For validating new names of projects and 
// items use VspContainsInvalidFileNameChars.
//-----------------------------------------------------------------------------
BOOL LUtilContainsInvalidFileOrUrlChars(LPCTSTR pszName, BOOL bIsUrl)
{
    if(bIsUrl)
        return (_tcspbrk(pszName, _T("\\/:*#?\"<>|")) || _tcscmp(pszName, _T("."))==0);
    else
        return LUtilContainsInvalidFileChars(pszName);
}

//-----------------------------------------------------------------------------
// The shell converts names of form: abc{space}{space}{dot}{dot} to
// just "abc". ie: Removes trailing dots and spaces.
//-----------------------------------------------------------------------------
BOOL LUtilFixFilename(CString& strName)
{
    BOOL bFixupDone = FALSE;
    strName.TrimRight();
    strName.TrimLeft();
    while(LUtilHaveTrailingTChar(strName, _T('.')))
    {
        bFixupDone = TRUE;
        strName = strName.Left(strName.GetLength()-1);
        strName.TrimRight();
    }
    return bFixupDone;
}

//-----------------------------------------------------------------------------
// Converts all forward slashes to backslashes in pBuff.
//-----------------------------------------------------------------------------
void LUtilUrlSlashToPathSlash(LPTSTR pBuff)
{
    while(*pBuff != 0)
    {
        if(*pBuff == _T('/'))
            *pBuff = _T('\\');
        pBuff = _tcsinc(pBuff);
    }
}

//-----------------------------------------------------------------------------
// Converts all forward slashes to backslashes in pBuff.
//-----------------------------------------------------------------------------
void LUtilUrlSlashToPathSlash(CString& strBuff)
{
    LUtilUrlSlashToPathSlash(strBuff.GetBuffer(strBuff.GetLength()));
    strBuff.ReleaseBuffer();
}
    
//-----------------------------------------------------------------------------
// Converts all backslashes slashes to forward slashes in pBuff.
//-----------------------------------------------------------------------------
void LUtilPathSlashToUrlSlash(LPTSTR pBuff)
{
    while(*pBuff != 0)
    {
        if(*pBuff == _T('\\'))
            *pBuff = _T('/');
        pBuff = _tcsinc(pBuff);
    }
}

//-----------------------------------------------------------------------------
// Converts all backslashes slashes to forward slashes in pBuff.
//-----------------------------------------------------------------------------
void LUtilPathSlashToUrlSlash(CString& strBuff)
{
    LUtilPathSlashToUrlSlash(strBuff.GetBuffer(strBuff.GetLength()));
    strBuff.ReleaseBuffer();
}

//-----------------------------------------------------------------------------
// Returns TRUE if contains a trailing given tchar else false
// This function is MBCS aware
//-----------------------------------------------------------------------------
BOOL LUtilHaveTrailingTChar(LPCTSTR sz, const TCHAR ch)
{
    ASSERT (sz != NULL && ch != _T('\0'));
    TCHAR *pLast = const_cast<TCHAR*>(_tcsrchr(sz, ch)); // find last occurrence of ch in sz 
    return ((pLast != NULL) && (*_tcsinc(pLast) == _T('\0')));
}

//-----------------------------------------------------------------------------
// Returns TRUE if contains a trailing given tchar else false
//-----------------------------------------------------------------------------
BOOL LUtilHaveTrailingTChar(const CString& string, const TCHAR ch)
{
    return string.GetLength()? (string[string.GetLength()-1] == ch) : FALSE;
}

//-----------------------------------------------------------------------------
// Removes the trailing TCHAR, if any, from the string passed in.
//-----------------------------------------------------------------------------
void LUtilStripTrailingTChar(CString& string, const TCHAR ch)
{
    if(LUtilHaveTrailingTChar(string, ch))
    {
        string.GetBuffer(string.GetLength());
        string.ReleaseBuffer(string.GetLength()-1);
    }
}
//-----------------------------------------------------------------------------
// Ensures the string has the trailing TCHAR.
//-----------------------------------------------------------------------------
void LUtilEnsureTrailingTChar(CString& string, const TCHAR ch)
{
    if(!LUtilHaveTrailingTChar(string, ch))
    {
        string += ch;
    }
}

//-----------------------------------------------------------------------------
// Removes all of the trailing TCHAR, if any, from the string passed in.
//-----------------------------------------------------------------------------
void LUtilStripTrailingTChars(CString& string, const TCHAR ch)
{
    ASSERT(string && (ch != _T('\0')));
    int i = string.GetLength();
    while (i && (string[i-1] == ch))
        i--;
    if (i < string.GetLength())
    {
        string.GetBuffer(string.GetLength());
        string.ReleaseBuffer(i);
    }
}


//-----------------------------------------------------------------------------
// Removes all of the leading TCHAR, if any, from the string passed in.
//-----------------------------------------------------------------------------
void LUtilStripLeadingTChars(CString& string, const TCHAR ch)
{
    ASSERT(string && (ch != _T('\0')));
    int i = 0;
    while(string[i] && (string[i] == ch))
        i++;
    if (i > 0)
        string.Delete(0, i);
}


//-----------------------------------------------------------------------------
// Returns in strCurUser the current logged in user.
//-----------------------------------------------------------------------------
void LUtilGetCurrentUser(CString& strCurUser)
{
    TCHAR name[256];
    ULONG size = 256;
    if(GetUserName(name, &size))
        strCurUser = name;
}
//-----------------------------------------------------------------------------
// Returns in strCurDomain the domain of the current logged in user.
//
// From Knowledge Base Article Q155698
//-----------------------------------------------------------------------------
void LUtilGetCurrentDomain(CString& strCurDomain)
{
    HANDLE hToken = NULL;
    TCHAR tszDomainName[512];
    DWORD cchDomainName = 512;
    OSVERSIONINFO osviInfo;
    BOOL fNT = TRUE;        // TRUE, if os is NT assume NT
    HINSTANCE hinstAdvapi = NULL;
    osviInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    *tszDomainName = _T('\0');
    strCurDomain = tszDomainName;

    // find the platform, since the method to obtain
    // the domain depends on platform.
    if (::GetVersionEx(&osviInfo))
    {
        fNT = (VER_PLATFORM_WIN32_NT == osviInfo.dwPlatformId);
    }

    if (fNT)
    {

        BOOL fSuccess;
        BYTE rgbInfoBuffer[512];
        DWORD cbInfoBuffer = 512;
        SID_NAME_USE snu;
        TCHAR tszUserName[512];
        DWORD cchUserName = 512;
        OPENTHREADTOKEN pfnOpenThreadToken = NULL;
        OPENPROCESSTOKEN pfnOpenProcessToken = NULL;
        GETTOKENINFORMATION pfnGetTokenInformation = NULL;
        LOOKUPACCOUNTSID pfnLookUpAccountSid = NULL;

        hinstAdvapi = ::LoadLibrary(_T("advapi32.dll"));
        if (hinstAdvapi == NULL)
            goto done;  // if we can't get the domain name, just continue

        pfnOpenThreadToken = (OPENTHREADTOKEN)GetProcAddress(hinstAdvapi, "OpenThreadToken");
        if (pfnOpenThreadToken == NULL)
            goto done;

        pfnOpenProcessToken = (OPENPROCESSTOKEN)GetProcAddress(hinstAdvapi, "OpenProcessToken");
        if (pfnOpenProcessToken == NULL)
            goto done;

        pfnGetTokenInformation = (GETTOKENINFORMATION)GetProcAddress(hinstAdvapi, "GetTokenInformation");
        if (pfnGetTokenInformation == NULL)
            goto done;

        pfnLookUpAccountSid = (LOOKUPACCOUNTSID)GetProcAddress(hinstAdvapi, "LookupAccountSidW");
        if (pfnLookUpAccountSid == NULL)
            goto done;

        // Get hold of the token. Preferably the thread token, if not the process one
        if (!pfnOpenThreadToken(GetCurrentThread(), TOKEN_QUERY, TRUE, &hToken))
        {
            if (GetLastError() == ERROR_NO_TOKEN)
            {
                if (!pfnOpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
                {
                    goto done;
                }
            }
        }

        // we need to get at the sid
        fSuccess = pfnGetTokenInformation(hToken, TokenUser, rgbInfoBuffer, cbInfoBuffer, &cbInfoBuffer);
        DWORD dwError = GetLastError();
        if (!fSuccess)
            goto done;

        fSuccess = pfnLookUpAccountSid(NULL, ((PTOKEN_USER)rgbInfoBuffer)->User.Sid, tszUserName, &cchUserName, tszDomainName, &cchDomainName, &snu);

        if (fSuccess)
        {
            strCurDomain = tszDomainName;
        }

    }

done:
    if (hToken)
        CloseHandle(hToken);

    if (hinstAdvapi)
        FreeLibrary(hinstAdvapi);
}

//-----------------------------------------------------------------------------
// Strips the domain part of the user id.
//-----------------------------------------------------------------------------
void LUtilStripDomain(CString& strUserID)
{
    int index = (int)strUserID.ReverseFind(_T('/'));
    if(index == -1)
        index = (int)strUserID.ReverseFind(_T('\\'));
    if(index != -1)
        strUserID = strUserID.Right(strUserID.GetLength() - index -1);
}

//-----------------------------------------------------------------------------
// Returns the last modified time the file pszFilename.
//-----------------------------------------------------------------------------
BOOL LUtilGetFileTime(LPCTSTR pszFilename, FILETIME* pFileTime)
{
    WIN32_FIND_DATA fd;
    HANDLE hFind = FindFirstFile(pszFilename, &fd);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        *pFileTime = fd.ftLastWriteTime;
        FindClose(hFind);
        return TRUE;
    }
    return FALSE;
}

//-----------------------------------------------------------------------------
// Returns the creation time for file pszFilename.
//-----------------------------------------------------------------------------
BOOL LUtilGetFileCreationTime(LPCTSTR pszFilename, FILETIME* pFileTime)
{
    WIN32_FIND_DATA fd;
    HANDLE hFind = FindFirstFile(pszFilename, &fd);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        *pFileTime = fd.ftCreationTime;
        FindClose(hFind);
        return TRUE;
    }
    return FALSE;
}

//-----------------------------------------------------------------------------
// Returns the file size. NOTE this function fails if the file size is greater 
// than 4 gig.
//-----------------------------------------------------------------------------
BOOL LUtilGetFileSize(LPCTSTR pszFilename, DWORD* pdwFileSize)
{
    *pdwFileSize = 0;
    WIN32_FIND_DATA fd;
    HANDLE hFind = FindFirstFile(pszFilename, &fd);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        // Get the data from the WIN32_FIND_DATA structure
        *pdwFileSize = fd.nFileSizeLow;
        FindClose(hFind);
        return TRUE;
    }
    return FALSE;
}

//-----------------------------------------------------------------------------
//  Returns TRUE if the path is a UNC path.
//-----------------------------------------------------------------------------
BOOL LUtilIsUNCPath( LPCTSTR pszPath )
{
    ASSERT( pszPath != NULL );
    return (pszPath[0] == _T('\\') && pszPath[1] == _T('\\'));
}

//-----------------------------------------------------------------------------
// Remove the drive and directory from a file name...
//-----------------------------------------------------------------------------
CString LUtilStripPath(LPCTSTR szFilePath)
{
    TCHAR szName [_MAX_FNAME + _MAX_EXT];
    TCHAR szExt [_MAX_EXT];
    _tsplitpath(szFilePath, NULL, NULL, szName, szExt);
    _tcscat(szName, szExt);
    return CString(szName);
}

//-----------------------------------------------------------------------------
// Retrieves everything to the right of \\server\share\ in a UNC path
//-----------------------------------------------------------------------------
CString LUtilStripPathFromUNC(LPCTSTR szUNCPath)
{
    CString strUNC(szUNCPath);
    CString strPathWithoutUNC;

    if (LUtilIsUNCPath(strUNC))
    {
        // Look for the first slash after the \\ in the unc path
        int iSlashLoc = strUNC.Find(_T("\\"),2);

        if (iSlashLoc != -1)
        {
            // Now look for the slash after iSlashLoc (to get past the share name)
            int iSlashLoc2 = strUNC.Find(_T("\\"), iSlashLoc+1);

            if (iSlashLoc2 != -1)
            {
                if (strUNC.GetLength() - (iSlashLoc2 + 1) > 0)
                {
                    strPathWithoutUNC = strUNC.Right(strUNC.GetLength() - (iSlashLoc2 + 1));
                }
            }
        }
    }
    return strPathWithoutUNC;
}

//-----------------------------------------------------------------------------
// Retrieves the filename from a url.
//-----------------------------------------------------------------------------
CString LUtilStripPathFromURL(LPCTSTR szFileURL)
{
    CString strFileURL(szFileURL);

    int iLastOcc = strFileURL.ReverseFind(_T('/'));

    if(iLastOcc != -1)
    {
        // no. of chars to be removed from the starting are iLastOcc + 1 since index was 0 based.
        return strFileURL.Right(strFileURL.GetLength() - (iLastOcc + 1));
    }
    else
    {   // Just return the whole thing
        return strFileURL;
    }
}    

//-----------------------------------------------------------------------------
// Remove the path part of a file path.  Return just the name
//-----------------------------------------------------------------------------
CString LUtilStripName(LPCTSTR szFilePath)
{
    TCHAR szPath [_MAX_DRIVE + _MAX_DIR];
    TCHAR szDir [_MAX_DIR];
    _tsplitpath(szFilePath, szPath, szDir, NULL, NULL);
    _tcscat(szPath, szDir);
    return CString(szPath);
}

//-----------------------------------------------------------------------------
// Retrieves the path from a URL.
//-----------------------------------------------------------------------------
CString LUtilStripNameFromURL(LPCTSTR szFileURL)
{
    CString strFileURL(szFileURL);

    int iLastOcc = strFileURL.ReverseFind(_T('/'));
    if(iLastOcc == -1)
        return strFileURL;
    else
        return strFileURL.Left(iLastOcc);
}    

//-----------------------------------------------------------------------------
// Get the extension of a file path.
//-----------------------------------------------------------------------------
CString LUtilGetExtension(LPCTSTR szFilePath)
{
    TCHAR szExt [_MAX_EXT];
    _tsplitpath(szFilePath, NULL, NULL, NULL, szExt);
    return CString(szExt);
}

//-----------------------------------------------------------------------------
// Remove the extension part of a file path.
//-----------------------------------------------------------------------------
CString LUtilStripExtension(LPCTSTR szFilePath)
{
    TCHAR szName [_MAX_FNAME];
    TCHAR szPath [_MAX_DRIVE + _MAX_DIR + _MAX_FNAME];
    TCHAR szDir [_MAX_DIR];
    _tsplitpath(szFilePath, szPath, szDir, szName, NULL);
    _tcscat(szPath, szDir);
    _tcscat(szPath, szName);
    return CString(szPath);
} // LUtilStripExtension

//-----------------------------------------------------------------------------
// Returns a pointer to the name part of pszFilePath. Empty string if no name
//-----------------------------------------------------------------------------
LPCTSTR LUtilGetName(LPCTSTR pszFilePath)
{
    LPCTSTR pszName = _tcsrchr(pszFilePath, _T('\\'));
    if(pszName)
        pszName++;
    else
        pszName = pszFilePath + _tcslen(pszFilePath);
    return pszName;
}

//----------------------------------------------------------------------------
// Truncate the string by removing the extension ext if present.
//----------------------------------------------------------------------------
void LUtilStripExt(LPTSTR szFilePath, LPCTSTR szExt)
{
    int cch, cchExt;

    cchExt = (int)_tcslen(szExt);
    cch = (int)_tcslen(szFilePath);
    
    if (cch >= cchExt)
      if (!COMPARE_FILENAMES(szFilePath + cch - cchExt, szExt))
        szFilePath[cch - cchExt] = 0;
} // LUtilStripExt

//-----------------------------------------------------------------------------
// Ensures the given file is writable (removes R/O, hidden attribs)
//-----------------------------------------------------------------------------
void LUtilMakeFileWritable(LPCTSTR pszFilePath)
{
    DWORD attribs = GetFileAttributes(pszFilePath);
    if(attribs != 0xffffffff)
    {
        if(attribs & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN))
            SetFileAttributes(pszFilePath, attribs & (~(FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN)));
    }
}

//-----------------------------------------------------------------------------
// Ensures the given file is set to readonly
//-----------------------------------------------------------------------------
void LUtilMakeFileReadOnly(LPCTSTR pszFilePath)
{
    DWORD attribs = GetFileAttributes(pszFilePath);
    if(attribs != 0xffffffff)
        SetFileAttributes(pszFilePath, attribs | FILE_ATTRIBUTE_READONLY);
}

//-----------------------------------------------------------------------------
// REturns TRUE if the R/O bit is set.
//-----------------------------------------------------------------------------
BOOL LUtilFileIsReadOnly(LPCTSTR pszFilePath)
{
    DWORD attribs = GetFileAttributes(pszFilePath);
    return (attribs != 0xffffffff) && (attribs & FILE_ATTRIBUTE_READONLY);
}

//-----------------------------------------------------------------------------
// Returns TRUE if file path exists. Returns FALSE if filepath if a directory
//-----------------------------------------------------------------------------
BOOL LUtilFileExists(LPCTSTR pszFilePath)
{
    DWORD attribs = GetFileAttributes(pszFilePath);
    if(attribs == 0xffffffff || attribs & FILE_ATTRIBUTE_DIRECTORY)
        return FALSE;
    return TRUE;
}

//-----------------------------------------------------------------------------
// Returns TRUE if file path exists. Returns FALSE if filepath if a directory
//-----------------------------------------------------------------------------
BOOL LUtilDirExists(LPCTSTR pszFilePath)
{
    DWORD attribs = GetFileAttributes(pszFilePath);
    if(attribs != 0xffffffff && attribs & FILE_ATTRIBUTE_DIRECTORY)
        return TRUE;
    return FALSE;
}

//-----------------------------------------------------------------------------
// Uses CVxOleDateTime to format the filetime.
//-----------------------------------------------------------------------------
void LUtilFormatFileTime(FILETIME& ft, CString& strFormattedTime)
{   
    CVxOleDateTime dt(ft);
    strFormattedTime = dt.Format();
}


//-----------------------------------------------------------------------------
// Encodes spaces in the URL with %20.
//-----------------------------------------------------------------------------
void LUtilEncodeURL(LPCTSTR pszSrc, LPTSTR pszDest, int maxChars) 
{
    ASSERT(pszSrc != NULL && pszDest != NULL);
    int spCount = 0;
    int count = 0;
    while(*pszSrc != 0 && count < maxChars) 
    {
        if(*pszSrc == L' ') 
        {   // Replace the space with %20.
            *pszDest = L'%';
            pszDest++;
            *pszDest = L'2';
            pszDest++;
            *pszDest = L'0';
            pszDest++;
            spCount++;
            pszSrc++;
            count += 3;
        } 
        else 
        {   // Just copy the character
            spCount = 0;
            *pszDest = *pszSrc;
            pszSrc++;
            pszDest++;
            count++;
        }
    }
    // Removing all trailing spaces
    pszDest[spCount*-3] = _T('\0');
}

//-----------------------------------------------------------------------------
// Returns TRUE if strUrl is an Absolute url. Only looks for the colon. which 
// means the function will be tripped up by file paths.
//-----------------------------------------------------------------------------
BOOL LUtilIsAbsoluteUrl(const CString& strUrl)
{
    if(strUrl.Find(_T(':')) == -1)
        return FALSE;
    return TRUE;
}
//-----------------------------------------------------------------------------
// Returns TRUE if pszUrl begins with http: or https:
//-----------------------------------------------------------------------------
BOOL LUtilIsHttpUrl(LPCTSTR pszUrl)
{
    if(_tcsncicmp(pszUrl, _T("http:"), 5) == 0 || _tcsncicmp(pszUrl, _T("https:"), 6) == 0)
        return TRUE;
    return FALSE;
}

//-----------------------------------------------------------------------------
// Returns TRUE if pszUrl begins with http: or https:
//-----------------------------------------------------------------------------
BOOL LUtilIsFtpUrl(LPCTSTR pszUrl)
{
    if(_tcsncicmp(pszUrl, _T("ftp:"), 4) == 0)
        return TRUE;
    return FALSE;
}

//-----------------------------------------------------------------------------
// Returns TRUE if strUrl is an file:/// url, or the first two characters are \\,
// or the second character is a colon
//-----------------------------------------------------------------------------
BOOL LUtilIsDBWUrl(LPCTSTR pszUrl)
{
    CString temp = pszUrl;
    temp.MakeLower();
    if(temp.GetLength() >= 2 && temp[1] == _T(':'))
        return TRUE;
    else if (temp.GetLength() >= 2 && (temp[0] == _T('\\') && temp[1] == _T('\\')))
        return TRUE;
    else if(temp.Find(_T("file://")) == 0)
        return TRUE;
    return FALSE;
}

//-----------------------------------------------------------------------------
// Given a full url, returns the protocol://server/web/. Returns true if
// successful. NOTE that it modifies the string passed in!!!!!
//-----------------------------------------------------------------------------
BOOL LUtilGetWebUrl(LPTSTR pszUrl)
{
    // Search for the colon
    BOOL bRet = FALSE;
    TCHAR* pszChar = _tcschr(pszUrl, _T(':'));
    if(pszChar != NULL)
    {   // Skip past the two or 3 slashes
        pszChar++;
        while(*pszChar && *pszChar == _T('/'))
            pszChar++;
        if(*pszChar)
        {   // Find next "/".
            pszChar = _tcschr(pszChar, _T('/'));
            if(pszChar)
            {   // Find next "/" or empty string.
                pszChar++;
                pszChar = _tcschr(pszChar, _T('/'));
                if(pszChar)
                {
                    pszChar++;
                    *(pszChar) = 0;
                }
                bRet = TRUE;
            }
        }
    }
    return bRet;
}
//-----------------------------------------------------------------------------
// Given a path and a filename, concatanates the two correctly (handles trailing
// nontrailing slash in folder name).  If strDir is empty, this function just
// returns whatever is in pszfilename
//-----------------------------------------------------------------------------
void LUtilBuildPath(CString& strDir, LPCTSTR pszFilename)
{
    if(strDir.IsEmpty())
    {
        strDir = pszFilename;
    }
    else if(strDir[strDir.GetLength()-1] != _T('\\') && pszFilename[0] != _T('\\'))
    {   // Folder does not have a trailing slash and filename does not have a leading slash
        strDir += _T('\\');
        strDir += pszFilename;
    }
    else if(strDir[strDir.GetLength()-1] == _T('\\') && pszFilename[0] == _T('\\'))
    {   // Folder has trailing slash and filename has a leading slash  we need to remove 
        // one of them
        strDir += &pszFilename[1];
    }
    else
    {   // Either Folder has trailing slash or filename has leading slash but not both
        strDir += pszFilename;
    }
}
//-----------------------------------------------------------------------------
// Given a url and a filename, concatanates the two correctly (handles trailing
// nontrailing slash in folder name). Handles leading / in pszUrl.  If strFolderUrl
//  is empty, this function just returns whatever is in pszFilename
//-----------------------------------------------------------------------------
void LUtilBuildUrl(CString& strFolderUrl, LPCTSTR pszFilename)
{
    if(strFolderUrl.IsEmpty())
    {
        strFolderUrl = pszFilename;
    }
    else if(strFolderUrl[strFolderUrl.GetLength()-1] != _T('/') && pszFilename[0] != _T('/'))
    {   // Folder does not have a trailing slash and filename does not have a leading slash
        strFolderUrl += _T('/');
        strFolderUrl += pszFilename;
    }
    else if(strFolderUrl[strFolderUrl.GetLength()-1] == _T('/') && pszFilename[0] == _T('/'))
    {   // Folder has trailing slash and filename has a leading slash  we need to remove 
        // one of them
        strFolderUrl += &pszFilename[1];
    }
    else
    {   // Either Folder has trailing slash or filename has leading slash but not both
        strFolderUrl += pszFilename;
    }
}

//-----------------------------------------------------------------------------
// Given protocol://server/web, splits the url into protocol://server, web
//-----------------------------------------------------------------------------
void LUtilSplitUrl(LPCTSTR pszUrl, CString& strServer, CString& strWeb)
{
    
    TCHAR* szTemp = (TCHAR*)_alloca((_tcslen(pszUrl) + 1) * sizeof(TCHAR));
    _tcscpy(szTemp, pszUrl);

    // Find protocol ":"
    TCHAR* p1 = _tcschr(szTemp, _T(':'));
    if(p1)
    {   // Skip 2 slashes
        p1++;
        if(*p1 == _T('/'))
        {
            p1++;
            if(*p1 == _T('/'))
                p1++;
        }
        // Now find next slash. This denotes the end of the server part. For file urls
        // this should be file://
        p1 = _tcschr(p1, _T('/'));
        if(p1)
        {   // Terminate to set the server
            *p1 = 0;
            strServer = szTemp;
            // Increment to the web and assign.
            p1++;
            strWeb = p1;
        }
        else
        {   // No webname
            strServer = pszUrl;
            strWeb.Empty();
        }
    }
}
//-----------------------------------------------------------------------------
// Given a full url, http://server:80/folder1/folder2, splits the url into:
// strProtocol  - "http:"
// strPort      - "80" - empty string if no port specified
// strServer    - "server"
// strWebPath   - "folder1/folder2"
//-----------------------------------------------------------------------------
void LUtilSplitUrl2(LPCTSTR pszUrl, CString& strProtocol, CString& strServer, CString& strPort,
                  CString& strWebPath)
{
    TCHAR* szTemp = (TCHAR*)_alloca((_tcslen(pszUrl) + 1) * sizeof(TCHAR));
    _tcscpy(szTemp, pszUrl);

    // Find protocol ":"
    TCHAR* p1 = _tcschr(szTemp, _T(':'));
    if(p1)
    {   // Skip colon
        p1 = _tcsinc(p1);
        TCHAR temp = *p1;
        *p1 = 0;
        // Save the protocol
        strProtocol = szTemp;
        *p1 = temp;
        // Now skip leading slashes
        while(*p1 == _T('/'))
        {
            p1 = _tcsinc(p1);
        }
        // p1 now points to the server part
        TCHAR* pszTemp = p1;
        // Search for a port colon
        p1 = _tcschr(p1, _T(':'));

        // If there are any slashes between the server name and the colon then 
        // the colon is not the port number but it's a part of the web path.
        // See VS7 300598.
        TCHAR* pszNextSlash = NULL;
        if(p1)
        {
            TCHAR* pszTemp1 = pszTemp;
            while (pszTemp1 < p1)
            {
                if (*pszTemp1 == _T('/'))
                {
                    pszNextSlash = pszTemp1;
                    p1 = NULL;     // No port
                    break;
                }
                
                pszTemp1 = _tcsinc(pszTemp1);
            }
        }

        if(p1)
        {
            *p1 = 0;
            strServer = pszTemp;
            // Search for next slash - end of port. If there
            // is no slash, we must assume the remainder is the port
            p1 =_tcsinc(p1);
            pszTemp = p1;
            p1 = _tcschr(p1, _T('/'));
            if(p1)
                *p1 = 0;
            strPort = pszTemp;
        }
        else
        {   // No port. Find next slash and terminate. If no trailing slash
            // we are done.
            p1 = pszNextSlash ? pszNextSlash : _tcschr(pszTemp, _T('/'));
            if(p1)
                *p1 = 0;
            strServer = pszTemp;
        }
        if(p1)
        {   // Skip the slash, remainder is the webpath
            p1 =_tcsinc(p1);
            strWebPath = p1;
        }
    }
}

//-----------------------------------------------------------------------------
// Strips the protocol (http://, etc)
//-----------------------------------------------------------------------------
void LUtilStripProtocol(CString& strUrl)
{
    TCHAR* szTemp = (TCHAR*)_alloca((strUrl.GetLength() + 1) * sizeof(TCHAR));
    _tcscpy(szTemp, strUrl);
    // Find protocol ":"
    TCHAR* p1 = _tcschr(szTemp, _T(':'));
    if(p1)
    {   // Skip leading slashes
        p1++;
        while(*p1 == _T('/'))
            p1++;
        // Do assignment. 
        strUrl = p1;
    }
}
//-----------------------------------------------------------------------------
// Searches for first ':' and returns everything upto and including it.
//-----------------------------------------------------------------------------
void LUtilGetProtocol(LPCTSTR pszUrl, CString& strProtocol)
{
    // Find protocol ":"
    const TCHAR* p1 = _tcschr(pszUrl, _T(':'));
    if(p1)
    {   // Count characters to copy
        p1++;
        DWORD nCount = (DWORD)(p1 - pszUrl);
        ASSERT(nCount >=1);
        LPTSTR pszBuff = strProtocol.GetBuffer(nCount+1);
        if(pszBuff)
        {
            memcpy(pszBuff, pszUrl, nCount*sizeof(TCHAR));
            pszBuff[nCount] = 0;
            strProtocol.ReleaseBuffer();
        }
    }
}
//-----------------------------------------------------------------------------
// Extracts the server name from the url
//-----------------------------------------------------------------------------
void LUtilExtractServerFromURL(LPCTSTR pszUrl, CString& strServerName)
{
    // Find protocol ":"
    const TCHAR* p1 = _tcschr(pszUrl, _T(':'));
    if(p1)
    {   // Skip leading slashes
        p1++;
        while(*p1 == _T('/'))
            p1++;
        // Do assignment. If no other slash, assume entire name is servername
        strServerName = p1;
        const TCHAR* p2 = _tcschr(p1, _T('/'));
        if(p2)
        {
            strServerName = strServerName.Left((LONG32)(p2-p1));
        }
    }
}

//-----------------------------------------------------------------------------
// Returns TRUE if pszUrl contains "localhost" or the local machine name for the server
//-----------------------------------------------------------------------------
BOOL LUtilUrlIsLocalMachine(LPCTSTR pszUrl)
{
    CString strProtocol, strServerName, strPort, strWebPath;
    BOOL bRet = FALSE;
    LUtilSplitUrl2(pszUrl, strProtocol, strServerName, strPort, strWebPath);
    if(!strServerName.IsEmpty())
    {
        if(COMPARE_NOCASE(strServerName, _T("localhost")) == 0)
        {
            bRet = TRUE;
        }
        else
        {   // Get the local computer name. We use the "A" version since this 
            // function is not wrapped by the win95 wrappers
            CHAR szComputerName[MAX_COMPUTERNAME_LENGTH + 1];
            DWORD dwSize = sizeof(szComputerName);

            if (::GetComputerNameA(szComputerName, &dwSize))
            {   // Convert to unicode (if unicode defined) to do comparison
                CString strComputerName = szComputerName;
                if(COMPARE_NOCASE(strServerName, strComputerName) == 0)
                    bRet = TRUE;
            }
        }
    }
    return bRet;
}

//-----------------------------------------------------------------------------
//  Returns in resultStr the string value for key keyPath, and value name. Passing
//  NULL for pszValueName will return the value for the key.
//-----------------------------------------------------------------------------
BOOL LUtilGetStringFromReg(HKEY hRootKey, LPCTSTR pszKeyPath, LPCTSTR pszValueName, 
                          CString& strResult)
{
    HKEY hkeyValue;
    TCHAR szValue[256];
    long err = RegOpenKeyEx(hRootKey, pszKeyPath, 0, KEY_READ, &hkeyValue);
    if(err == ERROR_SUCCESS)
    {
        ULONG ulcb = sizeof(szValue);
        err = RegQueryValueEx(hkeyValue, (LPTSTR)pszValueName, 0, NULL, (LPBYTE)szValue, &ulcb);
        RegCloseKey(hkeyValue);
        if(err == ERROR_SUCCESS)
        {   // Copy the data
            strResult = szValue;
            return TRUE;
        }
    }
    return FALSE;
}


//-----------------------------------------------------------------------------
//  Returns in resultStr the string value for key keyPath, and value name. Passing
//  NULL for pszValueName will return the value for the key.
//-----------------------------------------------------------------------------
BOOL LUtilSetStringInReg(HKEY hRootKey, LPCTSTR pszKeyPath, LPCTSTR pszValueName, LPCTSTR szVal)
{
    HKEY hkeyValue;

    long err = RegCreateKey(hRootKey, pszKeyPath, &hkeyValue);
    if(err == ERROR_SUCCESS)
    {
        err = RegSetValueEx(hkeyValue,  
                            pszValueName,  
                            0,  
                            REG_SZ,  
                            (const unsigned char *)szVal, 
                            (DWORD)_tcslen(szVal) + 1); 

        RegCloseKey(hkeyValue);
        if(err == ERROR_SUCCESS)
        {  
            return TRUE;
        }
    }
    return FALSE;
} 

//-----------------------------------------------------------------------------
//  Does an in-place conversion to lowercase on a CString. 
//-----------------------------------------------------------------------------
void LUtilMakeLower(CString & cstr)
{
    TCHAR* pstrLower = new TCHAR [cstr.GetLength() + 1];

    ASSERT(pstrLower);

    if(!pstrLower)
        return;

    int retVal = LCMapString( 
            MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT),SORT_DEFAULT), // locale identifier 
            LCMAP_LOWERCASE,    // mapping transformation type 
            cstr,               // address of source string 
            cstr.GetLength()+1, // number of characters in source string
            pstrLower,          // address of destination buffer 
            cstr.GetLength() + 1 // size of destination buffer 
        ); 

    // Only copy lower case string if the LCMapString succeeded.
    if(retVal != 0)
        cstr = pstrLower;
    // Cleanup
    delete [] pstrLower;
} 

//-----------------------------------------------------------------------------
// Does a case-insensitive search for strSubstr in strSearchedStr. Returns the 
// 0 based index of the first char if a match is found. -1 if no match found.
//-----------------------------------------------------------------------------
int LUtilSearchSubstrNoCase(LPCTSTR pszSearchedStr, LPCTSTR pszSubstr)
{
    CString strSearchedStrCopy = pszSearchedStr;
    CString strSubstrCopy = pszSubstr;

    strSearchedStrCopy.MakeLower();
    strSubstrCopy.MakeLower();

    return strSearchedStrCopy.Find(strSubstrCopy);
}


//-----------------------------------------------------------------------------
// Sets the shells error info with formatting like VxFormatString1 but also 
//-----------------------------------------------------------------------------
void LUtilSetErrString(UINT nIDPrompt, LPCTSTR pszHelpFile /* = NULL*/)
{
    CString msg;
    msg.LoadString(nIDPrompt);
    LUtilSetErrorInfo(E_FAIL, msg, nIDPrompt, pszHelpFile);
}

//-----------------------------------------------------------------------------
// Sets the shells error info with formatting like VxFormatString1 but also 
//-----------------------------------------------------------------------------
void LUtilSetErrString(LPCTSTR pszErrString, UINT nIDForHelpCtx, LPCTSTR pszHelpFile /* = NULL*/)
{
    LUtilSetErrorInfo(E_FAIL, pszErrString, nIDForHelpCtx, pszHelpFile);
}
//-----------------------------------------------------------------------------
// Sets the shells error info with formatting like VxFormatString1.
//-----------------------------------------------------------------------------
void LUtilSetErrString1(UINT nIDPrompt, LPCTSTR pszString1, LPCTSTR pszHelpFile /* = NULL*/)
{
    CString msg;
    VxFormatString1(msg, nIDPrompt, pszString1);
    LUtilSetErrorInfo(E_FAIL, msg, nIDPrompt, pszHelpFile);
}
//-----------------------------------------------------------------------------
// Formats an error with formating like VxFormatString2.
//-----------------------------------------------------------------------------
void LUtilSetErrString2(UINT nIDPrompt, LPCTSTR pszString1, LPCTSTR pszString2,
                       LPCTSTR pszHelpFile /* = NULL*/)
{
    CString msg;
    VxFormatString2(msg, nIDPrompt, pszString1, pszString2);
    LUtilSetErrorInfo(E_FAIL, msg, nIDPrompt, pszHelpFile);
}

//-----------------------------------------------------------------------------
// Formats an error with formating like VxFormatString3.
//-----------------------------------------------------------------------------
void LUtilSetErrString3(UINT nIDPrompt, LPCTSTR pszString1, LPCTSTR pszString2, 
                       LPCTSTR pszString3, LPCTSTR pszHelpFile /*= NULL*/)
{
    CString msg;
    VxFormatString3(msg, nIDPrompt, pszString1, pszString2, pszString3);
    LUtilSetErrorInfo(E_FAIL, msg, nIDPrompt, pszHelpFile);
}

//-----------------------------------------------------------------------------
// Displays the win32 error by concatinating the string passed in, nIDPRompt, after
// formatting it with pszString 1, with the results of GetLastError() string.
// ReturnS HRESULT_FROM_WIN32(GetLastError()). If you just want to display the win32
// error string, pass 0 for nIDPrompt. Note that the format of nIDPrompt should have
// a %1 for pszString1, and a %2 to place the win32 error string
//-----------------------------------------------------------------------------
HRESULT LUtilSetWin32Err(UINT nIDPrompt, LPCTSTR pszString1)
{
    ASSERT(nIDPrompt);
    DWORD err = ::GetLastError();
    CString msg, msg1;
    if(err != 0)
        Win32ErrorString(err, msg);
    if(nIDPrompt)
        VxFormatString2(msg1, nIDPrompt, pszString1, msg);
    else
        msg1 = msg;
    LUtilSetErrorInfo(HRESULT_FROM_WIN32(err), msg1, nIDPrompt);
    return HRESULT_FROM_WIN32(err);
}

//-----------------------------------------------------------------------------
// Sets the win32 error.
//-----------------------------------------------------------------------------
HRESULT LUtilSetWin32Err()
{
    return LUtilSetWin32Err(::GetLastError());
}

//-----------------------------------------------------------------------------
// Sets the win32 error given an error.
//-----------------------------------------------------------------------------
HRESULT LUtilSetWin32Err(DWORD dwLastError)
{
    if(dwLastError != 0 )
    {
        CString msg;
        Win32ErrorString(dwLastError, msg);
        LUtilSetErrorInfo(HRESULT_FROM_WIN32(dwLastError), msg, 0);
    }
    return HRESULT_FROM_WIN32(dwLastError);
}

//-----------------------------------------------------------------------------
// Sets the error info from the HRESULT.
//-----------------------------------------------------------------------------
void LUtilSetHresultErr(HRESULT hr)
{
    if (FAILED(hr))
    {
        CString strErrMsg;

        Win32ErrorString(HRESULT_FACILITY(hr) == FACILITY_WIN32 ? HRESULT_CODE(hr) : hr, strErrMsg);
        LUtilSetErrorInfo(hr, strErrMsg, 0);
    }
}

//-----------------------------------------------------------------------------
// Displays the last error set in the shell
//-----------------------------------------------------------------------------
void LUtilReportErrorInfo(HRESULT hr)
{   
    // Filter out bogus hr's where we shouldn't be displaying an error.
    if(hr != OLE_E_PROMPTSAVECANCELLED)
    {
        BOOL fInExt = FALSE;
        _VxModule.GetIVsExtensibility()->IsInAutomationFunction(&fInExt);
        if(fInExt || LUtilShellInCmdLineMode())
        {
            return;
        }
        IVsUIShell *pShell = _VxModule.GetIVsUIShell();
        if (NULL != pShell)
            pShell->ReportErrorInfo(hr);
        else
            ASSERT(FALSE);
    }
}

//-----------------------------------------------------------------------------
// Gets the last win32 error and its error string
//-----------------------------------------------------------------------------
void LUtilGetWin32ErrorAndString(DWORD* pdwError, CString& strError)
{
    *pdwError = ::GetLastError();
    if (*pdwError != 0)
        Win32ErrorString(*pdwError, strError);
    else
        strError.Empty();
}

//-----------------------------------------------------------------------------
// Sets the error information in the shell. 
//-----------------------------------------------------------------------------
void LUtilSetErrorInfo(HRESULT hrError, LPCTSTR pszDescription, DWORD dwHelpContextID, 
                      LPCTSTR pszHelpFile /* = NULL*/)
{
    USES_CONVERSION;

    HRESULT     hr = NOERROR;

    if (hrError == S_OK)
    {
        if ((pszDescription == NULL) && (!dwHelpContextID) && (pszHelpFile == NULL))
        {
            hr = ::SetErrorInfo(0, NULL);
            ASSERT(SUCCEEDED(hr));
            return;
        }
    }

    CComPtr<ICreateErrorInfo>   srpCreateErrInfo;
    CComPtr<IErrorInfo>         srpErrInfo;

    IfErrGo(::CreateErrorInfo(&srpCreateErrInfo));
    IfErrGo(srpCreateErrInfo->SetDescription(T2OLE((LPTSTR)pszDescription)));
    IfErrGo(srpCreateErrInfo->SetGUID(GUID_NULL));
    IfErrGo(srpCreateErrInfo->SetHelpContext(dwHelpContextID));
    IfErrGo(srpCreateErrInfo->SetHelpFile(T2OLE((LPTSTR)pszHelpFile)));
    IfErrGo(srpCreateErrInfo->SetSource(L""));
    IfErrGo(srpCreateErrInfo->QueryInterface(IID_IErrorInfo, (void **)&srpErrInfo));
    IfErrGo(::SetErrorInfo(0, srpErrInfo));

ERROR_EXIT:
    ASSERT(SUCCEEDED(hr));
}

//-----------------------------------------------------------------------------
//  Returns TRUE if the string is syntactially an absolute path drive: or \\
//  Does NOT check for validity of the path !!
//-----------------------------------------------------------------------------
BOOL LUtilIsAbsolutePath(const TCHAR *sz)
{
    // Must be at least 2 characters
    if(sz[0] == 0 || sz[1] == 0) 
    {
      return FALSE;
    }
    else if (sz[0] == _T('\\') && sz[1] == _T('\\'))
    {
      return TRUE;
    }
    else if (((sz[0] >= _T('a') && sz[0] <= _T('z')) || (sz[0] >= _T('A') && sz[0] <= _T('Z')))
                && sz[1] == _T(':'))
    {
      return TRUE;
    }

    return FALSE;

}

//---------------------------------------------------------------------------
// concatenates two paths - szPathAbs is always absolute (including drive letter), szPathRel can be relative (in which case we'll attempt 
// to add it to szPathAbs), or absolute (in which case it's the result)
//---------------------------------------------------------------------------
BOOL LUtilConcatPaths(LPCTSTR szPathAbs, LPCTSTR szPathRel, CString &strPath)
{
    BOOL fSucceed = TRUE;
    BOOL fNeedToCompressPath = false;

    ASSERT (szPathAbs && szPathRel);

    strPath.Empty();

    // check whether the path is an absolute path
    if (IsDirSep(szPathRel[0]))
    {
        // if not UNC, then prepend drive-letter
        if (!IsDirSep(szPathRel[1]))
        {
            strPath += szPathAbs[0];
            strPath += _T(':');
        }
    }
    else if (!(((szPathRel[0] >= _T('a') && szPathRel[0] <= _T('z')) || (szPathRel[0] >= _T('A') && szPathRel[0] <= _T('Z')))
                && szPathRel[1] == _T(':')))
    {
        // got a relative path -> prepend pathAbs
        strPath += szPathAbs;

        if (szPathRel[0] != _T('\0')&& strPath.Right(1) != _T('\\')) {
            strPath += _T('\\');
        }
    }

    strPath += szPathRel;

    {
        TCHAR szPath[MAX_PATH +1], *pch;

        szPath[0] = _T('\0');
        DWORD dwRet = GetFullPathName(strPath, _MAX_PATH, szPath, &pch);
        
        if (dwRet == 0 || szPath[0] == _T('\0'))
            fSucceed = FALSE;
        else
            strPath = szPath;
    }

    return fSucceed;
}



//---------------------------------------------------------------------------
// Get a temp file which doesn't exist in the directory strDest
// and put the filename into strFile.
//---------------------------------------------------------------------------
BOOL LUtilGetTempFileInDir(CString &strDest, LPCTSTR lpszSuggestedRoot, LPCTSTR lpszExt, CString& strTempFile)
{
    DWORD dwFileNumber = 0;
    CString strTempFilePath;
    CString strTempFormat;
    CString strRoot(lpszSuggestedRoot ? lpszSuggestedRoot : _T("File")), strExt(lpszExt);

    strTempFile.Empty();
    
    // get a temp file by going thru numbers 1 thru 9999.
    do {
        dwFileNumber++;
        strTempFormat.Format(_T("%s%u%s"), strRoot, dwFileNumber, strExt);
        strTempFilePath = strDest;
        strTempFilePath += strTempFormat;
        
        // if file doesn't exist, we found the filename!
        if (!LUtilFileExists(strTempFilePath))
            break;
    } while (dwFileNumber < 10000);

    if (dwFileNumber < 10000)
    {
        strTempFile = strTempFormat;
    }
    return (dwFileNumber < 10000);
} // LUtilGetTempFileInDir

// Get a temp directory which doesn't exist in the directory strDest
// and put the dirname into strTempDir.
BOOL LUtilGetTempDirInDir(CString &strDest, LPCTSTR lpszSuggestedRoot, CString& strTempDir)
{
	return LUtilGetTempDirInDirFormat(_T("%s%u"), 1, strDest, lpszSuggestedRoot, strTempDir);
}

// Get a temp directory which doesn't exist in the directory strDest
// and put the dirname into strTempDir.
// Allow the caller to specify the fomat and starting number
// if dwDirNumber is 0, no format is used
BOOL LUtilGetTempDirInDirFormat(LPCTSTR lpszFormat, DWORD dwDirNumber, CString &strDest, LPCTSTR lpszSuggestedRoot, CString& strTempDir)
{
    CString strTempDirPath;
    CString strTempFormat;
    CString strRoot(lpszSuggestedRoot ? lpszSuggestedRoot : _T("Dir"));

    strTempDir.Empty();
    
    // get a temp dir by going thru numbers 1 thru 9999.
    do {
		if (dwDirNumber)
			strTempFormat.Format(lpszFormat, strRoot, dwDirNumber);
		else 
			strTempFormat = strRoot;

        strTempDirPath = strDest;
		LUtilBuildPath(strTempDirPath, strTempFormat);
        
        // if dir doesn't exist, we found the dirname!
        if (!LUtilDirExists(strTempDirPath))
            break;

       dwDirNumber++;
	} while (dwDirNumber < 10000);

    if (dwDirNumber < 10000)
    {
        strTempDir = strTempFormat;
    }
    return (dwDirNumber < 10000);
} // LUtilGetTempDirInDir

//-----------------------------------------------------------------------------
// Just delegates to the actual implementation.
//-----------------------------------------------------------------------------
BOOL LUtilCreateDirectory(LPCTSTR strDirName)
{
    return UtilCreateDirectory(strDirName);
}

//-----------------------------------------------------------------------------
// Returns the currently set text. Note that his clears the error so use wisely!
//-----------------------------------------------------------------------------
void LUtilGetErrorDescription(CString& strText)
{
    CComPtr<IErrorInfo> srpIErrorInfo;
    HRESULT hr = ::GetErrorInfo(0, &srpIErrorInfo);
    if(hr == S_OK)
    {
        CComBSTR bstrErrDescription;
        if(srpIErrorInfo->GetDescription(&bstrErrDescription) == S_OK)
            strText = bstrErrDescription;
    }
}

//-----------------------------------------------------------------------------
// Returns the currently set text. Note that his clears the error so use wisely! 
// Returns S_FALSE if no error info
//-----------------------------------------------------------------------------
HRESULT LUtilGetErrorInfo(CString& strText, DWORD* pdwHelpCtx, CString& strHelpFile)
{
    CComPtr<IErrorInfo> srpIErrorInfo;
    HRESULT hr = ::GetErrorInfo(0, &srpIErrorInfo);
    if(hr == S_OK)
    {
        CComBSTR bstrErrDescription;
        CComBSTR bstrHelpFile;
        if(srpIErrorInfo->GetDescription(&bstrErrDescription) == S_OK)
            strText = bstrErrDescription;
        if(srpIErrorInfo->GetHelpFile(&bstrHelpFile) == S_OK)
            strHelpFile = bstrHelpFile;
        *pdwHelpCtx = 0;
        srpIErrorInfo->GetHelpContext(pdwHelpCtx);
    }
    return hr;
}

//-----------------------------------------------------------------------------
// Returns a string for the wininet error.
//-----------------------------------------------------------------------------
BOOL LUtilGetInetErrorString(DWORD dwInetErr, CString& strMsg)
{
    LPVOID lpMsgBuf = NULL;
    BOOL bRet = FALSE;
    HMODULE hMod = ::GetModuleHandle(_T("wininet.dll"));
    if(hMod && ::FormatMessage(
            FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_ALLOCATE_BUFFER,
            hMod,
            dwInetErr,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
            (LPTSTR)&lpMsgBuf, 0, NULL))
    {
        ASSERT(lpMsgBuf != NULL);
        strMsg = (LPTSTR)lpMsgBuf;
        bRet = TRUE;
    }
    if(lpMsgBuf)
        LocalFree(lpMsgBuf);
    return bRet;

}

//----------------------------------------------------------------------------
// Returns TRUE if Shell is in command line (non-interactive) mode
//----------------------------------------------------------------------------
BOOL LUtilShellInCmdLineMode()
{
    BOOL bRet = FALSE;
    IVsShell* pShell = _VxModule.GetIVsShell();
    if(pShell)
    {
        CComVariant var;
        if(SUCCEEDED(pShell->GetProperty(VSSPROPID_IsInCommandLineMode, &var)))
        {
            bRet = var.boolVal == VARIANT_TRUE;
        }
    }
    return bRet;
}

//----------------------------------------------------------------------------
// Returns TRUE if currently being called as part of executing an automation function
// (automation function must call IVsExtensiblity::Enter/ExitAutomation appropriately)
//----------------------------------------------------------------------------
BOOL LUtilIsShellInAutomationFunction(void)
{
    BOOL fIn = FALSE;
    CComPtr<IVsExtensibility> pExt;

    if ((SUCCEEDED(_VxModule.GetIServiceProvider()->QueryService(SID_SVsExtensibility, IID_IVsExtensibility, (LPVOID *)&pExt))) && (pExt != NULL))
    {
        pExt->IsInAutomationFunction(&fIn);
    }

    return fIn;
}

//----------------------------------------------------------------------------
// Replaces the extension in strFilename with pszNewExtension. Appends pszNewExtension if 
// strFilename doesn't have one. Assumes pszNewExtension has a leading '.'.
//----------------------------------------------------------------------------
void LUtilReplaceExtension(CString& strFilename, LPCTSTR pszNewExtension)
{
    ASSERT(pszNewExtension && pszNewExtension[0] == _T('.'));
    int index = strFilename.ReverseFind(_T('.'));
    if(index > 0)
        strFilename = strFilename.Left(index);
    else if(index == 0)
        strFilename.Empty();
    strFilename += pszNewExtension;
}

// End of lutil.cpp
