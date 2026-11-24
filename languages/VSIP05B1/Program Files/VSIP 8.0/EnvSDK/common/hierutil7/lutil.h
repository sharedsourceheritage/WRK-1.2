//--------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (c) 1994-2000 Microsoft Corporation Inc.
// All rights reserved
//
// utils.h : declarations for a suite of simple utility functions.
// 
// NOTE: All functions here are mbcs/unicode compliant.
//       Do NOT add non mbcs/unicode compliant functions!
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif
#ifndef __LUTILS_H__
#define __LUTILS_H__

#define ASSERTWritePtr(ptr) ASSERT(ptr && !IsBadWritePtr(ptr, sizeof(*ptr)))
#define VERIFYWritePtr(ptr) ASSERTWritePtr(ptr); if (!ptr || IsBadWritePtr(ptr, sizeof(*ptr))) return E_INVALIDARG

#define UnicodeToAnsi(szA, szW) WideCharToMultiByte( CP_ACP, 0, szW, -1, szA, lstrlen(szW) + 1, NULL, NULL )
#define AnsiToUnicode(szW, szA) MultiByteToWideChar( CP_ACP, 0, szA, -1, szW, strlen(szA) + 1 )

// Returns TRUE if strFolderName (not full path), is a reserved folder name.
BOOL LUtilFolderContainsReserved(LPCTSTR strFolderName);

// Returns a project name from a given path
CString LUtilProjNameFromPath(LPCTSTR pszPath );

// Converts the WCHAR to an OLECHAR allocated with CoTaskMemAlloc
OLECHAR* LUtilWCHARToOleChar(const WCHAR* szString);
void LUtilRemoveTrailingWCHAR (LPWSTR sz, WCHAR ch);

// Returns TRUE if string is blank. 
BOOL LUtilIsBlankString(LPCTSTR string);

// Returns TRUE if name contains illegal filename characters (note that backslash
// is illegal for filenames (hence if you pass a full path this function will fail)
// This is a less restrictive fn used for validating existing files. For validating 
// new names of projects and items use VspContainsInvalidFileNameChars.
BOOL LUtilContainsInvalidFileChars(LPCTSTR name);

// Returns TRUE if name contains invalid filename characters. Slightly different
// check if bIsUrl is TRUE. This function is MBCS aware.
// This is a less restrictive fn used for validating existing files. For validating 
// new names of projects and items use VspContainsInvalidFileNameChars.
BOOL LUtilContainsInvalidFileOrUrlChars(LPCTSTR pszName, BOOL bIsUrl);

// The shell converts names of form: abc{space}{space}{dot}{dot} to
// just "abc". ie: Removes trailing dots and spaces. REturns TRUE if had to do some
// fixup.
BOOL LUtilFixFilename(CString& strName);

// Slash conversion
void LUtilPathSlashToUrlSlash(LPTSTR pBuff);
void LUtilPathSlashToUrlSlash(CString& strBuff);
void LUtilUrlSlashToPathSlash(LPTSTR pBuff);
void LUtilUrlSlashToPathSlash(CString& strBuff);

// Process related
void LUtilGetCurrentUser(CString& strCurUser);
void LUtilGetCurrentDomain(CString& strCurDomain);
void LUtilStripDomain(CString& strUserID);

// Returns TRUE if sz has ch as its terminating character. The overloaded CString
// version is provided to be much more efficient for CStrings.
BOOL LUtilHaveTrailingTChar(LPCTSTR sz, const TCHAR ch);
BOOL LUtilHaveTrailingTChar(const CString& string, const TCHAR ch);
void LUtilStripTrailingTChar(CString& string, const TCHAR ch);
void LUtilEnsureTrailingTChar(CString& string, const TCHAR ch);

// Removes all of the trailing chars.
void LUtilStripTrailingTChars(CString& string, const TCHAR ch);
// Removes all of the leading chars.
void LUtilStripLeadingTChars(CString& string, const TCHAR ch);

// File functions
BOOL LUtilGetFileTime(LPCTSTR pszFilename, FILETIME* pFileTime);
BOOL LUtilGetFileCreationTime(LPCTSTR pszFilename, FILETIME* pFileTime);
BOOL LUtilGetFileSize(LPCTSTR pszFilename, DWORD* pdwFileSize);
BOOL LUtilIsUNCPath(LPCTSTR pszPath);

// Handy path functions. Not very efficient though
CString LUtilStripPath(LPCTSTR szFilePath);
CString LUtilStripName(LPCTSTR szFilePath);
CString LUtilGetExtension(LPCTSTR szFilePath);
CString LUtilStripExtension(LPCTSTR szFilePath);
CString LUtilStripPathFromUNC(LPCTSTR szUNCPath);
CString LUtilStripPathFromURL(LPCTSTR szFileURL);
CString LUtilStripNameFromURL(LPCTSTR szFileURL);

// Returns a pointer to the name part of pszFilePath.
LPCTSTR LUtilGetName(LPCTSTR pszFilePath);

// similar to LUtilStripExtension except this function does it in place.
// Also only removes if extension matches szExt.
void LUtilStripExt(LPTSTR szFilePath, LPCTSTR szExt);

// File attribute modifying functions
void LUtilMakeFileWritable(LPCTSTR pszFilePath);
void LUtilMakeFileReadOnly(LPCTSTR pszFilePath);
BOOL LUtilFileExists(LPCTSTR pszFilePath);
BOOL LUtilFileIsReadOnly(LPCTSTR pszFilePath);
BOOL LUtilDirExists(LPCTSTR pszFilePath);

void LUtilFormatFileTime(FILETIME& ft, CString& strFormattedTime);

// Url functions
void LUtilEncodeURL(LPCTSTR pszSrc, LPTSTR pszDest, int maxChars);
BOOL LUtilIsAbsoluteUrl(const CString& strUrl);
BOOL LUtilIsDBWUrl(LPCTSTR strUrl);
// Returns TRUE if pszUrl begins with http: or https:
BOOL LUtilIsHttpUrl(LPCTSTR pszUrl);
BOOL LUtilIsFtpUrl(LPCTSTR pszUrl);

// Given a full url, returns the protocol://server/web/. Returns true if
// successful. NOTE that it modifies the string passed in!!!!!
BOOL LUtilGetWebUrl(LPTSTR pszUrl);

// Returns TRUE if pszUrl contains "localhost" or the local machine name for the server
BOOL LUtilUrlIsLocalMachine(LPCTSTR pszUrl);

// Given a path or url and a filename, concatanates the two correctly (handles trailing
// nontrailing slash in folder name). 
void LUtilBuildPath(CString& strDir, LPCTSTR pszFilename);
void LUtilBuildUrl(CString& strFolderUrl, LPCTSTR pszFileName);

// Given protocol://server/web, splits the url into protocol:\\server, web
void LUtilSplitUrl(LPCTSTR pszUrl, CString& strServer, CString& strWeb);

// Given a full url, http://server:80/folder1/folder2, splits the url into:
// strProtocol  - "http:"
// strPort      - "80" - empty string if no port specified
// strServer    - "server"
// strWebPath   - "folder1/folder2"
void LUtilSplitUrl2(LPCTSTR pszUrl, CString& strProtocol, CString& strServer, CString& strPort,
                  CString& strWebPath);
void LUtilStripProtocol(CString& strUrl);
// Searches for first ':' and returns everything upto and including it.
void LUtilGetProtocol(LPCTSTR pszUrl, CString& strProtocol);

// Returns the server name from the url.
void LUtilExtractServerFromURL(LPCTSTR pszUrl, CString& strServerName);

// Registry Functions
BOOL LUtilGetStringFromReg(HKEY hRootKey, LPCTSTR pszKeyPath, LPCTSTR pszValueName, CString& strResult);
BOOL LUtilSetStringInReg(HKEY hRootKey, LPCTSTR pszKeyPath, LPCTSTR pszValueName, LPCTSTR szVal);

// Lowercase string using system functions
void LUtilMakeLower(CString & cstr);

// case insensitive substr search.
int LUtilSearchSubstrNoCase(LPCTSTR pszSearchedStr, LPCTSTR pszSubstr);

// Sets the string as an error with formattting like VxFormatString1 and VxFormatString2
void LUtilSetErrString(UINT nIDPrompt, LPCTSTR pszHelpFile  = NULL);
void LUtilSetErrString(LPCTSTR pszErrString, UINT nIDForHelpCtx, LPCTSTR pszHelpFile = NULL);
void LUtilSetErrString1(UINT nIDPrompt, LPCTSTR pszString1, LPCTSTR pszHelpFile  = NULL);
void LUtilSetErrString2(UINT nIDPrompt, LPCTSTR pszString1, LPCTSTR pszString2, LPCTSTR pszHelpFile  = NULL);
void LUtilSetErrString3(UINT nIDPrompt, LPCTSTR pszString1, LPCTSTR pszString2, LPCTSTR pszString3, LPCTSTR pszHelpFile = NULL);

// Displays the win32 error by concatinating the string passed in, nIDPRompt, after
// formatting it with pszString 1, with the results of GetLastError() string. ie.
// requires a %1 and a %2 in the string.
HRESULT LUtilSetWin32Err(UINT nIDPrompt, LPCTSTR pszString1);

// Just sets error info to the GetLastError() string.
HRESULT LUtilSetWin32Err();
HRESULT LUtilSetWin32Err(DWORD dwLastError);

// Sets the error info from the HRESULT.
void LUtilSetHresultErr(HRESULT hr);

// Just get the Win32 error and the error string
void LUtilGetWin32ErrorAndString(DWORD* pdwError, CString& strError);

// Returns error string for wininet error.
BOOL LUtilGetInetErrorString(DWORD dwInetErr, CString& strMsg);

// Sets error info in the shell. Reports error info via the shell.
void LUtilSetErrorInfo(HRESULT hr, LPCTSTR pszDescription, DWORD dwHelpContextID, LPCTSTR pszHelpFile = NULL);
void LUtilReportErrorInfo(HRESULT hr);

// Message box methods
int LUtilMessageBox(LPCTSTR lpszText, UINT nType = MB_OK|MB_ICONEXCLAMATION, LPCTSTR pszCaption = NULL, DWORD dwContextHelpId = 0, LPCTSTR pszHelpFile = NULL);
int LUtilMessageBox(UINT nIDPrompt, UINT nType = MB_OK|MB_ICONEXCLAMATION, LPCTSTR pszCaption = NULL, DWORD dwContextHelpId = 0, LPCTSTR pszHelpFile = NULL);

// NOTE - read comment above implementation before using this
BOOL LUtilIsAbsolutePath(const TCHAR *sz);

BOOL LUtilConcatPaths(LPCTSTR szPathAbs, LPCTSTR szPathRel, CString &strPath);

BOOL LUtilGetTempFileInDir(CString &strDest, LPCTSTR lpszSuggestedRoot, LPCTSTR lpszExt, CString& strTempFile);

BOOL LUtilGetTempDirInDir(CString &strDest, LPCTSTR lpszSuggestedRoot, CString& strTempDir);

BOOL LUtilGetTempDirInDirFormat(LPCTSTR lpszFormat, DWORD dwDirNumber, CString &strDest, LPCTSTR lpszSuggestedRoot, CString& strTempDir);

// Retrieves the current error text. NOTE!!!! This also clears the error!!!
void LUtilGetErrorDescription(CString& strText);

// Retrieves all the current error information. NOTE!!!! This also clears the error!!! Returns
// S_FALSE if no error info
HRESULT LUtilGetErrorInfo(CString& strText, DWORD* pdwHelpCtx, CString& strHelpFile);

// Creates a directory and all the subdirectories up to it.
BOOL LUtilCreateDirectory(LPCTSTR name);

// Returns TRUE if the shell is in command line (non-interactive) mode
BOOL LUtilShellInCmdLineMode();

// Returns TRUE if the shell is in an automation function
BOOL LUtilIsShellInAutomationFunction();

// Replaces the extension in strFilename with pszNewExtension. Appends pszNewExtension if 
// strFilename doesn't have one.
void LUtilReplaceExtension(CString& strFilename, LPCTSTR pszNewExtension);

#endif
// End of lutils.h
