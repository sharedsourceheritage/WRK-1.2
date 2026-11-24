//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (c) 1997 - 2000, Microsoft Corporation
// All Rights Reserved
//
// Information Contained Herein Is Proprietary and Confidential.
//
// file and directory path utilities
//---------------------------------------------------------------------------
#include "hu_pch.h"
#include "pathutil.h"

#define LCID_US_ENGLISH 0x409

//---------------------------------------------------------------------------
// Given a path, return one of the PathType constants.  A path is considered
// to be full if it starts with <any-char>:.  A path is a UNC path if it 
// starts with \\.  All other paths are considered to be relative paths.
//
// there are four types of files:
//  1. relative (folder\file.ext or ..\..\folder\file.ext)  -- PathRelative
//  2. unc (\\server\share\folder\file.ext)                 -- PathUNC
//  3. fully qualified (m:\folder\file.ext)                 -- PathFull
//  4. fully-qualified with no drive (\folder\file.ext)     -- PathFullMissingDrive
//---------------------------------------------------------------------------
PathType PathGuessType(const TCHAR* pszPath)
{
    if (pszPath[0] == _T('\\'))
    {
        if (pszPath[1] == _T('\\'))
            return PathUNC;
        else
            return PathFullMissingDrive;
    }
    else if (pszPath[0] != _T('\0') && pszPath[1] == _T(':'))
        return PathFull;
    else
        return PathRelative;
}

//---------------------------------------------------------------------------
// Return pointer to the name and extension portion of a path.
//---------------------------------------------------------------------------
TCHAR* PathFindName(const TCHAR* pszPath)
{
    const TCHAR* pszFile = pszPath + _tcslen(pszPath);
    
    while (pszFile > pszPath)
    {
        if (*pszFile == _T('\\') || *pszFile == _T(':'))
        {
            pszFile++;
            break;
        }
        
        pszFile--;
    }
    
    return (TCHAR *)pszFile;
}

//---------------------------------------------------------------------------
// Given a full or partial file / directory path, return a pointer to
// the extension portion of the filename.  This includes the period.
// If there is no extension, then the pointer is to the end of the 
// string.
//   "c:\bar\foo.txt"     returns ".txt"
//   "c:\"		  returns ""
//   "c:\foo"         returns ""
//   "c:\bar\foo.bar.txt" returns ".txt"
//   "c:\bar.foo\bar"     returns ""
//---------------------------------------------------------------------------
TCHAR* PathFindExt(const TCHAR* pszPath)
{
    const TCHAR* pszExt;
    const TCHAR* pszEnd = pszPath + _tcslen(pszPath);
    
    for (pszExt = pszEnd; pszExt > pszPath; pszExt--)
    {
        if (*pszExt == _T('.'))
            break;
        if (*pszExt == _T('\\') || *pszExt == _T(':'))
        {
            pszExt = pszEnd;
            break;
        }
    }
    
    // If we are at the beginning of a filename like "foo" with no extension, then we need to 
    // return the empty string (not foo).
    if(pszExt == pszPath && *pszPath != _T('.'))
        pszExt = pszEnd;

    return (TCHAR*)pszExt;
}

//---------------------------------------------------------------------------
// Given a directory or filename, add a directory or filename to the path.
// This is like WszCat, only it makes sure that a '\\' separator is added
// if necessary.  The return value is pszPath passed in.  For the general
// case, the pszPath buffer should be MAX_PATH * 2 characters.
//---------------------------------------------------------------------------
TCHAR* PathCatName(TCHAR* pszPath, const TCHAR* pszName)
{
    // Find end of path
    TCHAR* pszEnd = pszPath + _tcslen(pszPath);
    
    // Add separator if necessary
    if (pszEnd > pszPath && pszEnd[-1] != _T('\\'))
        *pszEnd++ = _T('\\');

    //Asumption pszPath is MAX_PATH * 2
    if (_tcslen(pszName) + _tcslen(pszPath) >= MAX_PATH*2)   
        return NULL;
    // Add name to path
    _tcscpy(pszEnd, pszName);
    
    return pszPath;
}

//---------------------------------------------------------------------------
// Given a full or partial file / directory path, return a pointer to the 
// the first character in the path that does not correspond to the device:
//   "c:\bar\foo.txt"   returns "\bar\foo.txt"
//   "c:\"		returns	"\"
//   "c:foo"        returns "foo"
//   "c:..\foo"     returns "..\foo"
//   "c:.."     returns ".."
//   "\\bar\foo"        returns ""
//   "\\bar\foo\foobar" returns "\foobar"
//   "bar\foo.txt"  returns "bar\foo.txt"
//   "foo.txt"      returns "foo.txt"
//---------------------------------------------------------------------------
TCHAR* PathFindDevice(const TCHAR* pszPath)
{
    PathType type = PathGuessType(pszPath);
    
    if (type == PathUNC)
    {
        const TCHAR* pszUNC;
        for (pszUNC = pszPath + 2; *pszUNC != _T('\\'); pszUNC++)
            if (*pszUNC == _T('\0'))
                return (TCHAR*)pszPath;
            for (pszUNC++; *pszUNC != _T('\\') && *pszUNC != _T('\0'); pszUNC++)
                ;
            return (TCHAR*)pszUNC;    // return first character after \\server\share
    }
    else if (type == PathFull)
        return (TCHAR*)pszPath + 2;  // return first character after drive and colon
    else
        return (TCHAR*)pszPath;   // return existing path since it's relative
}

//---------------------------------------------------------------------------
// Given a relative path, produce a fully qualified path.  This uses the 
// current directory to determine the path.  If the path is not relative,
// then this function has no effect on the buffer.  The pointer passed 
// in is returned.
//---------------------------------------------------------------------------
TCHAR* PathMakeFullFromCurDir(TCHAR* pszPath)
{
    // If it looks like a relative path
    if (PathGuessType(pszPath) == PathRelative)
    {
        // If we can get the full path
        TCHAR szFullPath[MAX_PATH];
        TCHAR* pszName;
        if (GetFullPathName(pszPath, MAX_PATH, szFullPath, &pszName))
        {
            // Return the full path
            _tcscpy(pszPath, szFullPath);
        }
    }
    
    return pszPath;
}

//---------------------------------------------------------------------------
// Given a relative path, produce a fully qualified path.  This uses the 
// directory passed in to determine the path.  If the path is not relative, 
// then this function has no effect on the buffer.  The pointer passed 
// in is returned.
//---------------------------------------------------------------------------
TCHAR* PathMakeFullFromDir(TCHAR* pszPath, const TCHAR* pszDir)
{
    // Save old directory, change to the desired directory
    TCHAR szSaveDir[MAX_PATH];
    if (GetCurrentDirectory(MAX_PATH, szSaveDir) && SetCurrentDirectory(pszDir))
    {
        // Create relative path
        PathMakeFullFromCurDir(pszPath);
        
        // Restore original directory
        SetCurrentDirectory(szSaveDir);
    }
    
    return pszPath;
}

#if 0
//---------------------------------------------------------------------------
// Given an full path, produce a UNC path.  If the path is not fully
// qualified, or the path cannot be turned into a UNC path, then 
// this function has no effect on the buffer.  The pointer passed in 
// is returned.
//---------------------------------------------------------------------------
TCHAR* PathMakeUNC(TCHAR* pszPath)
{
    // If it looks like an full path
    if (PathGuessType(pszPath) == PathFull)
    {
        // Build a device name
        TCHAR szDevice[] = _T("A:\\");
        *szDevice = *pszPath;
        
        // If the device is remote, and we can get the UNC name
        TCHAR szRemoteName[MAX_PATH];
        DWORD cchRemoteName = MAX_PATH;
        if ((GetDriveType(szDevice) == DRIVE_REMOTE) &&
            (WNetGetConnection(szDevice, szRemoteName, &cchRemoteName) == WN_SUCCESS))
        {
            cchRemoteName = _tcslen(szRemoteName);
            memmove(pszPath + cchRemoteName, pszPath + 2, (_tcslen(pszPath) - 2) * sizeof(TCHAR));
            memcpy(pszPath, szRemoteName, cchRemoteName * sizeof(TCHAR));
        }
    }
    
    return wszPath;
}
#endif //0

//---------------------------------------------------------------------------
// Given a path pointing to a file or directory, shorten the path string to
// to be just the path of the parent directory.  If there is no parent
// directory, then it has no effect on the buffer.  The pointer passed
// in is returned.  In no cases will the truncated path have a '\\' at
// the end of it. For example:
//
//    "c:\a\b\c"  returns "c:\a\b"
//    "\\a\\b"    returns "\\a\\b"
//    "\\a\\b\c"  returns "\\a\\b"
//    "c:\a\b"    returns "c:\a"
//    "c:\"	  returns "c:
//    "c:\a"      returns "c:
//
// This returns whether or not the buffer was modified.
//---------------------------------------------------------------------------
BOOL PathMakeDir(TCHAR* pszPath)
{
    // Find the trailing file or dir name, backup to backslash preceeding it
    TCHAR* pszBackSlash = PathFindName(pszPath) - 1;
    
    // Find the start of the leading dir (after the device)
    TCHAR* pszDir = PathFindDevice(pszPath);
    
    // If the name is not part of the device name
    if (pszBackSlash >= pszDir && *pszBackSlash == _T('\\'))
    {
        // Then truncate the path to be only the directory
        *pszBackSlash = _T('\0');
        
        // We modified the buffer
        return TRUE;
    }
    
    // We did not modify the buffer.
    return FALSE;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
LPTSTR MakeFullPathFromFolderAndRelativePath(LPCTSTR szBaseFolder, 
                                             LPCTSTR szRelativePath, 
                                             LPTSTR szFullPath, 
                                             ULONG cchFullPath)
{
    // cchFullPath must be the lenghts of the two strings +1 (at least)
    //  because the two paths might very well just come back "as-is"
    //  copied together (in the case where szRelativePath is just
    //  a path starting at szBaseFolder)
    ASSERT(cchFullPath > _tcslen(szBaseFolder)+_tcslen(szRelativePath));

    ASSERT(szBaseFolder && szRelativePath && szFullPath);
    ASSERT(!IsBadWritePtr(szFullPath, sizeof(TCHAR)*cchFullPath));

    // make sure we think this really is a relative path -- we don't work
    //  well with absolute or unc paths
    ASSERT(PathRelative == PathGuessType(szRelativePath));

    // alloc some space to copy the strings into a single string. We'll
    //  pass this single string to GetFullPathName which will munge them
    //  together and place the output in the return string.
    //
    TCHAR*  pchFile = NULL;
    TCHAR*  szPreFixupPath = (TCHAR *)_alloca(sizeof(TCHAR)*(_tcslen(szBaseFolder)+_tcslen(szRelativePath)+1));

    // munge the base folder & the relative path...
    // example -->  base-folder=c:/temp/foo/moo/ 
    //              relative-path=../../goobers.cls
    // becomes --> szPreFixupPath=c:/temp/foo/moo/../../goobers.cls
    //  result --> c:/temp/goobers.cls
    //
    _tcscpy(szPreFixupPath, szBaseFolder);
    _tcscat(szPreFixupPath, szRelativePath);

    // GetFullPathName fails with a 0-value return or greater than 0 return if
    // an insufficient buffer has been passed in.
    DWORD dwRet = GetFullPathName(szPreFixupPath, cchFullPath, szFullPath, &pchFile);
    if (dwRet == 0 || dwRet >= cchFullPath)
        return NULL;
    else
        return szFullPath;
}

//---------------------------------------------------------------------------
// Given a fully qualified path, produce a relative path.  This uses
// the specified directory to produce the path.  If the path is not full,
// then this function has no effect on the buffer.  The pointer passed
// in is returned.
//---------------------------------------------------------------------------
TCHAR* PathMakeRelativeToDir(TCHAR* pszPath, const TCHAR* pszDir)
{
    // If it's not already relative
    if (PathGuessType(pszPath) != PathRelative)
    {
        // If we can get the directory portion of the path
		TCHAR  szDir2[MAX_PATH];
        _tcscpy(szDir2, pszPath);
        if (PathMakeDir(szDir2))
        {
            // If there is a common part of the two directories
            int cchCommonDir;
            int cchCommonDir2;
            if (PathFindCommon(szDir2, pszDir, &cchCommonDir, &cchCommonDir2))
            {
                // Start with no relative path
				TCHAR szRelative[MAX_PATH];
                szRelative[0] = _T('\0');

                // Starting with the specified directory, get back up to the 
                // common part by adding a "..\\" for each dir that appears 
                // after the common portion.
                const TCHAR* pszUp;
                for (pszUp = pszDir + cchCommonDir; *pszUp; pszUp++)
                    if (*pszUp == _T('\\'))
                        _tcscat(szRelative, _T("..\\"));

                    // Now, get down to the directory specified by the path
                if (szDir2[cchCommonDir2] == _T('\\'))
                {
                    _tcscat(szRelative, szDir2 + cchCommonDir2 + 1);
                    _tcscat(szRelative, _T("\\"));
                }

                // Add the filename portion of the path
                _tcscat(szRelative, PathFindName(pszPath));

                // Return the new string
                _tcscpy(pszPath, szRelative);
            }
        }

    }

    return pszPath;
}

//---------------------------------------------------------------------------
// Given two fully qualified paths, find the number of characters that are in
// common between the two paths.  This will never break in the middle of a 
// directory or file name.  For example:
//
// wszPath1 = c:\a\b\c
// wszPath2 = c:\a\c
// returns   = 4, e.g. "c:\a" is common
//
// wszPath1 = c:\a
// wszPath2 = c:\b
// returns   = 2, e.g. "c:" is common
//
// wszPath1 = c:\a\b
// wszPath2 = c:\a
// returns   = 5, e.g. "c:\a" is common
//
// wszPath1 = c:\a\b\c
// wszPath2 = c:\a\b\c
// returns   = 8, e.g. everything in common
//
// wszPath1 = d:\a
// wszPath2 = c:\a
// returns   = 0, e.g. nothing in common
//
// wszPath1 = \\a\b
// wszPath2 = \\a\c
// returns   = 0, e.g. nothing in common
//
// Note that with unicode it is possible for the two common portions of the 
// path to be of different lengths, so both are returned.  In the previous
// examples, they are the same.
//
// The actual return value of the function is whether there is any common
// part to the two paths, e.g. whether *pcchPath1 > 0 && *pcchPath2 > 0.
//---------------------------------------------------------------------------
BOOL PathFindCommon(const TCHAR* pszPath1, const TCHAR* pszPath2, int* pcchPath1, int* pcchPath2)
{
    LCID lcidIntlDll = LOCALE_USER_DEFAULT;
    
    // Find end of device part of path
    int cchDevice1 = (LONG32) (PathFindDevice(pszPath1) - pszPath1);
    int cchDevice2 = (LONG32) (PathFindDevice(pszPath2) - pszPath2);

    // Both paths must have device names, or nothing is in common
    if (!cchDevice1 || !cchDevice2)
        return FALSE;

    // Compare the device names; if the don't match, nothing is in common
    if (!(2 == CompareString(lcidIntlDll, NORM_IGNORECASE | NORM_IGNOREWIDTH | NORM_IGNOREKANATYPE,
            pszPath1, cchDevice1, pszPath2, cchDevice2)))
        return FALSE;

    // Now look for directories in common
    const TCHAR* pszStart1 = pszPath1 + cchDevice1;
    const TCHAR* pszStart2 = pszPath2 + cchDevice2;
    while (*pszStart1 == _T('\\') && *pszStart2 == _T('\\'))
    {
        // Find next backslash in first path
        const TCHAR* pszEnd1;
        for (pszEnd1 = pszStart1 + 1; *pszEnd1; pszEnd1++)
            if (*pszEnd1 == _T('\\'))
                break;

            // Find next backslash in second path
        const TCHAR* pszEnd2;
        for (pszEnd2 = pszStart2 + 1; *pszEnd2; pszEnd2++)
            if (*pszEnd2 == _T('\\'))
                break;

            // Compare the two directories
        if (!(2 == CompareString(lcidIntlDll, NORM_IGNORECASE | NORM_IGNOREWIDTH | NORM_IGNOREKANATYPE, 
                pszStart1, (LONG32) (pszEnd1 - pszStart1), pszStart2, (LONG32) (pszEnd2 - pszStart2))))
        {
            // Done searching; use previous location as last common character
            break;
        }

        // Directories match, so continue
        pszStart1 = pszEnd1;
        pszStart2 = pszEnd2;
    }

    // Return number of characters in common for each string
    *pcchPath1 = (LONG32) (pszStart1 - pszPath1);
    *pcchPath2 = (LONG32) (pszStart2 - pszPath2);
    return TRUE;
}

