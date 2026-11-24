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
#ifndef _PATHUTIL_H_
#define _PATHUTIL_H_

//---------------------------------------------------------------------------
// @@ Path utilities
//
// These are general purpose file-path manipulation routines.  The convention
// is that the caller must allocate enough space for the path.  Typically this
// is MAX_PATH characters.
//
// Whenever a directory is specified, then the trailing backslash (\) should 
// not be included as part of the string.
//---------------------------------------------------------------------------

// A categorization of path types
enum PathType
{
    // there are four types of files:
    //
    //  1. unc 
    //     (\\server\share\folder\file.ext)
    //
    PathUNC,

    //  2. fully qualified 
    //     (m:\folder\file.ext)
    //
    PathFull,

    //  3. fully-qualified with no drive 
    //     (\folder\file.ext)
    //
    PathFullMissingDrive,

    //  4. relative 
    //     (folder\file.ext or ..\..\folder\file.ext)
    //
    PathRelative
};

// Given a path, return one of the PathType constants.  A path is considered
// to be full if it starts with <any-char>:.  A path is a UNC path if it 
// starts with \\.  All other paths are considered to be relative paths.
PathType PathGuessType(const TCHAR* pszPath);

// Given a directory or filename, add a directory or filename to the path.
// This is like WszCat, only it makes sure that a '\\' separator is added
// if necessary.  The return value is pszPath passed in.  For the general
// case, the pszPath buffer should be MAX_PATH * 2 characters.
TCHAR* PathCatName(TCHAR* pszPath, const TCHAR* pszName);

// Given a full or partial file / directory path, return a pointer to the 
// the filename / directory name portion of the path.
//   "c:\bar\foo.txt"   returns "foo.txt"
//   "c:\"		returns	""
//   "c:foo"        returns "foo"
//   "c:..\foo"     returns "foo"
//   "c:.."     returns ".."
//   "\\bar\foo"        returns "foo"
//   "\\bar\foo\foobar" returns "\foobar"
//   "bar\foo.txt"  returns "bar\foo.txt"
//   "foo.txt"      returns "foo.txt"
TCHAR* PathFindName(const TCHAR* pszPath);

// Given a full or partial file / directory path, return a pointer to
// the extension portion of the filename.  This includes the period.
// If there is no extension, then the pointer is to the end of the 
// string.
//   "c:\bar\foo.txt"     returns ".txt"
//   "c:\"		  returns ""
//   "c:\foo"         returns ""
//   "c:\bar\foo.bar.txt" returns ".txt"
//   "c:\bar.foo\bar"     returns ""
TCHAR* PathFindExt(const TCHAR* pszPath);

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
TCHAR* PathFindDevice(const TCHAR* pszPath);

// Given a relative path, produce a fully qualified path.  This uses the 
// current directory to determine the path.  If the path is not relative,
// then this function has no effect on the buffer.  The pointer passed 
// in is returned.
TCHAR* PathMakeFullFromCurDir(TCHAR* pszPath);

// Given a relative path, produce a fully qualified path.  This uses the 
// directory passed in to determine the path.  If the path is not relative, 
// then this function has no effect on the buffer.  The pointer passed 
// in is returned.
TCHAR* PathMakeFullFromDir(TCHAR* pszPath, const TCHAR* pszDir);

#if 0
// Given a full path, produce a UNC path.  If the path is not fully
// qualified, or the path cannot be turned into a UNC path, then 
// this function has no effect on the buffer.  The pointer passed in 
// is returned.
TCHAR* PathMakeUNC(TCHAR* pszPath);
#endif //0

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
BOOL PathMakeDir(TCHAR* pszPath);


LPTSTR MakeFullPathFromFolderAndRelativePath(LPCTSTR szBaseFolder, 
                                             LPCTSTR szRelativePath, 
                                             LPTSTR szFullPath, 
                                             ULONG cchFullPath);

// Given a fully qualified path, produce a relative path.  This uses
// the specified directory to produce the path.  If the path is not full,
// then this function has no effect on the buffer.  The pointer passed
// in is returned.
TCHAR* PathMakeRelativeToDir(TCHAR* pszPath, const TCHAR* pszDir);

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
BOOL PathFindCommon(const TCHAR* pszPath1, const TCHAR* pszPath2, int* pcchPath1, int* pcchPath2);

#endif // _PATHUTIL_H_
