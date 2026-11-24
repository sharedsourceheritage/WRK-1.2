//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//---------------------------------------------------------------------------

#include "hu_pch.h"
#include "VsFile.h"
#include "ValidAdd.h"
#include <io.h>
#include <fcntl.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static const TCHAR afxChNil = _T('\0');

//---------------------------------------------------------------------------
CVsFile::CVsFile(void) :
    m_hFile(INVALID_HANDLE_VALUE),
    m_bCloseOnDelete(FALSE)
{
}

//---------------------------------------------------------------------------
CVsFile::~CVsFile(void)
{
    if ((m_hFile != INVALID_HANDLE_VALUE) && m_bCloseOnDelete)
    {
        Abort();
    }
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsFile::Open(LPCTSTR lpszFileName, UINT nOpenFlags)
{
    ASSERT(m_hFile == INVALID_HANDLE_VALUE);
    ASSERT(VxIsValidString(lpszFileName));
    ASSERT((nOpenFlags & typeText) == 0);    // text mode not supported

    // CFile objects are always binary and CreateFile does not need flag
    nOpenFlags &= ~(UINT)typeBinary;

    m_hFile = INVALID_HANDLE_VALUE;
    m_bCloseOnDelete = FALSE;
    m_strFileName.Empty();

    LPTSTR lpszFilePart;
    TCHAR szTemp[_MAX_PATH + 1];
    DWORD nLen = GetFullPathName(lpszFileName, _MAX_PATH + 1, szTemp, &lpszFilePart);
    if (0 < nLen && nLen <= _MAX_PATH)
    {
        m_strFileName = szTemp;
    }
    else
    {
        ATLTRACE(_T("Warning: could not parse the path '%s'.\n"), lpszFileName);
        m_strFileName = lpszFileName;   // take it literally
    }
    ASSERT(shareCompat == 0);

    // map read/write mode
    ASSERT((modeRead|modeWrite|modeReadWrite) == 3);
    DWORD dwAccess = GENERIC_READ;
    switch (nOpenFlags & 3)
    {
    case modeRead:
        dwAccess = GENERIC_READ;
        break;
    case modeWrite:
        dwAccess = GENERIC_WRITE;
        break;
    case modeReadWrite:
        dwAccess = GENERIC_READ|GENERIC_WRITE;
        break;
    default:
        ASSERT(FALSE);  // invalid share mode
    }

    // map share mode
    DWORD dwShareMode = 0;
    switch (nOpenFlags & 0x70)
    {
    case shareCompat:       // map compatibility mode to exclusive
    case shareExclusive:
        dwShareMode = 0;
        break;
    case shareDenyWrite:
        dwShareMode = FILE_SHARE_READ;
        break;
    case shareDenyRead:
        dwShareMode = FILE_SHARE_WRITE;
        break;
    case shareDenyNone:
        dwShareMode = FILE_SHARE_WRITE|FILE_SHARE_READ;
        break;
    default:
        ASSERT(FALSE);  // invalid share mode?
    }

    // Note: typeText and typeBinary are used in derived classes only.

    // map creation flags
    DWORD dwCreateFlag;
    if (nOpenFlags & modeCreate)
    {
        if (nOpenFlags & modeNoTruncate)
            dwCreateFlag = OPEN_ALWAYS;
        else
            dwCreateFlag = CREATE_ALWAYS;
    }
    else
        dwCreateFlag = OPEN_EXISTING;

    // attempt file creation
    m_hFile = ::CreateFile(lpszFileName, dwAccess, dwShareMode, NULL,
                            dwCreateFlag, FILE_ATTRIBUTE_NORMAL, NULL);
    if (m_hFile == INVALID_HANDLE_VALUE)
    {
        return FALSE;
    }
    if (GetFileType(m_hFile) != FILE_TYPE_DISK)
    {
        CloseHandle(m_hFile);
        return HRESULT_FROM_WIN32(ERROR_CANT_ACCESS_FILE);
    }
    m_bCloseOnDelete = TRUE;
    return TRUE;
}

//---------------------------------------------------------------------------
// wrapper around ::CloseHandle()
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsFile::Close(void)
{
    ASSERT(m_hFile != INVALID_HANDLE_VALUE);

    BOOL fRet = TRUE;
    if (m_hFile != INVALID_HANDLE_VALUE)
    {
        fRet = ::CloseHandle(m_hFile);
        m_hFile = INVALID_HANDLE_VALUE;
    }
    m_bCloseOnDelete = FALSE;
    m_strFileName.Empty();
    return fRet;
}
//---------------------------------------------------------------------------
// Flushes the file's contents
//---------------------------------------------------------------------------
BOOL CVsFile::Flush()
{
    ASSERT(m_hFile != INVALID_HANDLE_VALUE);
    BOOL fRet = FALSE;
    if (m_hFile != INVALID_HANDLE_VALUE)
        fRet = ::FlushFileBuffers(m_hFile);
    return fRet;
}

//---------------------------------------------------------------------------
// close file ignoring all errors
//---------------------------------------------------------------------------
void CVsFile::Abort(void)
{
    if (m_hFile != INVALID_HANDLE_VALUE)
    {   // close and ignore errors
        ::CloseHandle(m_hFile);
        m_hFile = INVALID_HANDLE_VALUE;
    }
    m_bCloseOnDelete = FALSE;
    m_strFileName.Empty();
}

//---------------------------------------------------------------------------
// wrapper around ::ReadFile()
// pdwActualRead - actual number of bytes read
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsFile::Read(void* lpBuf, DWORD nCount, DWORD *pnActualRead)
{
    ASSERT(m_hFile != INVALID_HANDLE_VALUE);
    ASSERT(pnActualRead != NULL);
    
    if (nCount == 0)
    {   // avoid Win32 "null-read"
        *pnActualRead = nCount;
        return FALSE;
    }
    ASSERT(lpBuf != NULL);
    ASSERT(VxIsValidAddress(lpBuf, nCount));

    return ::ReadFile(m_hFile, lpBuf, nCount, pnActualRead, NULL);
}

//---------------------------------------------------------------------------
// wrapper around ::WriteFile()
// pdwPosition - actual number of bytes written
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsFile::Write(const void *lpBuf, DWORD nCount, DWORD *pdwActualWrite)
{
    ASSERT(m_hFile != INVALID_HANDLE_VALUE);
    ASSERT(pdwActualWrite != NULL);

    if (nCount == 0)
    {   // avoid Win32 "null-write"
        *pdwActualWrite = nCount;
        return FALSE;
    }
    ASSERT(lpBuf != NULL);
    ASSERT(VxIsValidAddress(lpBuf, nCount, FALSE));

    return ::WriteFile(m_hFile, lpBuf, nCount, pdwActualWrite, NULL);
}

//---------------------------------------------------------------------------
// wrapper around ::SetFilePointer()
// dwMoveMethod = { FILE_BEGIN, FILE_END, FILE_CURRENT }
// pdwPosition = resulting file position
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsFile::Seek(LONG lOff, DWORD nFrom, DWORD *pdwPosition)
{
    ASSERT(m_hFile != INVALID_HANDLE_VALUE);
    ASSERT(pdwPosition != NULL);
    ASSERT(nFrom == FILE_BEGIN || nFrom == FILE_END || nFrom == FILE_CURRENT);

    *pdwPosition = ::SetFilePointer(m_hFile, lOff, NULL, nFrom);
    if (*pdwPosition != (DWORD)-1)
    {
        return TRUE;
    }
    return FALSE;
}
//---------------------------------------------------------------------------
// wrapper around :: SetEndOfFile();
// return FALSE on failure, use GetLastError() for failure reason. Sets the
// EOF to the current position of the file
//---------------------------------------------------------------------------
BOOL CVsFile::SetEndOfFile()
{
    ASSERT(m_hFile != INVALID_HANDLE_VALUE);
    return ::SetEndOfFile(m_hFile);
}

//---------------------------------------------------------------------------
// wrapper around ::MoveFile()
//---------------------------------------------------------------------------
BOOL CVsFile::Rename(LPCTSTR lpszOldName, LPCTSTR lpszNewName)
{
    return ::MoveFile((LPTSTR)lpszOldName, (LPTSTR)lpszNewName);
}

//---------------------------------------------------------------------------
// returns a low DWORD count of bytes in the file
// Note: the contained function can return up to 2*DWORD,
// but we only handle files under 32K (1 DWORD)
//---------------------------------------------------------------------------
DWORD CVsFile::GetLength() const
{
    ASSERT(m_hFile != INVALID_HANDLE_VALUE);
    return ::GetFileSize(m_hFile, NULL);
}   

//---------------------------------------------------------------------------
// wrapper around ::Remove()
//---------------------------------------------------------------------------
BOOL CVsFile::Remove(LPCTSTR lpszFileName)
{
    return ::DeleteFile((LPTSTR)lpszFileName);
}

//---------------------------------------------------------------------------
CVsStdioFile::CVsStdioFile(int nMaxSize /*= 128*/) :
    m_nMaxSize(nMaxSize),   
    m_pStream(NULL)
{
}

//---------------------------------------------------------------------------
CVsStdioFile::~CVsStdioFile(void)
{
    if (m_pStream != NULL && m_bCloseOnDelete)
    {
        Abort();
    }
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::Open(LPCTSTR lpszFileName, UINT nOpenFlags)
{
    ASSERT(m_pStream == NULL);
    ASSERT(lpszFileName != NULL);

    m_pStream = NULL;

    if (!CVsFile::Open(lpszFileName, (nOpenFlags & ~typeText)))
        return FALSE;

    ASSERT(m_hFile != INVALID_HANDLE_VALUE);
    ASSERT(m_bCloseOnDelete);

    char szMode[4]; // C-runtime open string
    int nMode = 0;

    // determine read/write mode depending on CFile mode
    if (nOpenFlags & modeCreate)
    {
        if (nOpenFlags & modeNoTruncate)
            szMode[nMode++] = 'a';
        else
            szMode[nMode++] = 'w';
    }
    else if (nOpenFlags & modeWrite)
        szMode[nMode++] = 'a';
    else
        szMode[nMode++] = 'r';

    // add '+' if necessary (when read/write modes mismatched)
    if (szMode[0] == 'r' && (nOpenFlags & modeReadWrite) ||
        szMode[0] != 'r' && !(nOpenFlags & modeWrite))
    {
        // current szMode mismatched, need to add '+' to fix
        szMode[nMode++] = '+';
    }

    // will be inverted if not necessary
    int nFlags = _O_RDONLY|_O_TEXT;
    if (nOpenFlags & (modeWrite|modeReadWrite))
        nFlags ^= _O_RDONLY;

    if (nOpenFlags & typeBinary)
        szMode[nMode++] = 'b', nFlags ^= _O_TEXT;
    else
        szMode[nMode++] = 't';
    szMode[nMode++] = '\0';

    // open a C-runtime low-level file handle
    int nHandle = _open_osfhandle((intptr_t)m_hFile, nFlags);

    // open a C-runtime stream from that handle
    if (nHandle != -1)
        m_pStream = _fdopen(nHandle, szMode);

    if (m_pStream == NULL)
    {
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::Close(void)
{
    ASSERT(m_pStream != NULL);

    int nErr = 0;
    if (m_pStream != NULL)
    {
        nErr = fclose(m_pStream);
        m_pStream = NULL;
    }
    m_hFile = INVALID_HANDLE_VALUE;
    m_bCloseOnDelete = FALSE;
    m_strFileName.Empty();
    return !nErr;
}

//---------------------------------------------------------------------------
// close file ignoring all errors
//---------------------------------------------------------------------------
void CVsStdioFile::Abort(void)
{
    if (m_pStream != NULL)
    {   // close and ignore errors
        fclose(m_pStream);
        m_pStream = NULL;
    }
    m_hFile = INVALID_HANDLE_VALUE;
    m_bCloseOnDelete = FALSE;
    m_strFileName.Empty();
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::Read(void* lpBuf, DWORD nCount, DWORD *pnActualRead)
{
    ASSERT(m_pStream != NULL);
    ASSERT(pnActualRead != NULL);

    *pnActualRead = (DWORD)fread(lpBuf, sizeof(BYTE), nCount, m_pStream);
    if (ferror(m_pStream))
    {
        clearerr(m_pStream);
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::Write(const void *lpBuf, DWORD nCount, DWORD *pnActualWrite)
{
    ASSERT(m_pStream != NULL);
    ASSERT(pnActualWrite != NULL);

    *pnActualWrite = (DWORD)fwrite(lpBuf, sizeof(BYTE), nCount, m_pStream);
    if (ferror(m_pStream))
    {
        clearerr(m_pStream);
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// Unicode version. Return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::ReadString(LPWSTR lpsz, UINT nMax)
{
    ASSERT(m_pStream != NULL);

    LPWSTR lpszResult = fgetws(lpsz, nMax, m_pStream);
    if (lpszResult == NULL && !feof(m_pStream))
    {
        clearerr(m_pStream);
        return FALSE;
    }
    return lpszResult != NULL;
}

//---------------------------------------------------------------------------
// Ansi version. Return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::ReadString(LPSTR lpsz, UINT nMax)
{
    ASSERT(m_pStream != NULL);

    LPSTR lpszResult = fgets(lpsz, nMax, m_pStream);
    if (lpszResult == NULL && !feof(m_pStream))
    {
        clearerr(m_pStream);
        return FALSE;
    }
    return lpszResult != NULL;
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::ReadString(CString& rString)
{

    rString = &afxChNil;    // empty string without deallocating
    LPTSTR lpsz = rString.GetBuffer(m_nMaxSize);
    LPTSTR lpszResult;
    int nLen = 0;
    for (;;)
    {
        lpszResult = _fgetts(lpsz, m_nMaxSize+1, m_pStream);
        rString.ReleaseBuffer();

        // handle error/eof case
        if (lpszResult == NULL && !feof(m_pStream))
        {
            clearerr(m_pStream);
            return FALSE;
        }

        // if string is read completely or EOF
        if (lpszResult == NULL ||
            (nLen = lstrlen(lpsz)) < m_nMaxSize ||
            lpsz[nLen-1] == _T('\n'))
        {
            break;
        }
        nLen = rString.GetLength();
        lpsz = rString.GetBuffer(m_nMaxSize + nLen) + nLen;
    }

    // remove '\n' from end of string if present
    lpsz = rString.GetBuffer(0);
    nLen = (int)rString.GetLength();
    if (nLen != 0 && lpsz[nLen-1] == _T('\n'))
        rString.GetBufferSetLength(nLen-1);

    return lpszResult != NULL;
}

//---------------------------------------------------------------------------
// Unicode version. Return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::WriteString(LPCWSTR lpsz)
{
    ASSERT(m_pStream != NULL);

    if (fputws(lpsz, m_pStream) == _TEOF)
    {
        clearerr(m_pStream);
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// Ansi version. Return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::WriteString(LPCSTR lpsz)
{
    ASSERT(m_pStream != NULL);

    if (fputs(lpsz, m_pStream) == _TEOF)
    {
        clearerr(m_pStream);
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::Seek(LONG lOff, DWORD dwMoveMethod, DWORD *pnPosition)
{
    ASSERT(m_pStream != NULL);
    ASSERT(dwMoveMethod == SEEK_CUR || dwMoveMethod == SEEK_END || dwMoveMethod == SEEK_SET);

    *pnPosition = (DWORD)-1;
    if (fseek(m_pStream, lOff, dwMoveMethod))
    {
        clearerr(m_pStream);
        return FALSE;
    }
    *pnPosition = ftell(m_pStream);
    if (*pnPosition == (DWORD)-1)
    {
        clearerr(m_pStream);
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsStdioFile::Flush(void)
{
    if (m_pStream != NULL && fflush(m_pStream))
    {
        clearerr(m_pStream);
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsSafeFile::Open(LPCTSTR lpszFileName, UINT nOpenFlags, LPCTSTR lpszTempPath)
{
    LPTSTR lpszFilePart = NULL;
    TCHAR szTemp[_MAX_PATH + 1];
    DWORD nLen = ::GetFullPathName(lpszFileName, _MAX_PATH + 1, szTemp, &lpszFilePart);
    if (0 < nLen && nLen <= _MAX_PATH)
    {
        m_strRealFileName = szTemp;
    }
    else
    {
        ATLTRACE(_T("Warning: could not parse the path '%s'.\n"), lpszFileName);
        m_strRealFileName = lpszFileName;   // take it literally
    }

    ASSERT(lpszFilePart);
    if(!lpszFilePart)
        return FALSE;
    
    if (NULL == lpszTempPath)
    {
        nLen -= (int)_tcslen(lpszFilePart);
        lpszTempPath = (LPCTSTR)_alloca(_MAX_PATH * sizeof(TCHAR));
        _tcsncpy(const_cast<LPTSTR>(lpszTempPath), szTemp, nLen);
        const_cast<LPTSTR>(lpszTempPath)[nLen] = _T('\0');
    }   
    nLen = ::GetTempFileName(lpszTempPath, lpszFilePart, 0, szTemp);
    if (nLen)
    {
        return CVsFile::Open(szTemp, nOpenFlags);
    }
    return FALSE;
}

//---------------------------------------------------------------------------
// real file is removed, temp file is renamed to real file
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsSafeFile::Close(void)
{
    CString strTmp(m_strFileName);
    BOOL fRet = CVsFile::Close();
    if (fRet)
    {   // if real file remove fails, we don't remove temp file
        fRet = ::CopyFile(strTmp, m_strRealFileName, FALSE);
        ASSERT(fRet || L"failed to copy temporary file to global.asa");
        if (fRet)
        {
            fRet = ::DeleteFile(strTmp);
            ASSERT(fRet || L"failed to delete temporary global.asa");
        }
    }
    return fRet;
}

//---------------------------------------------------------------------------
// temp file is removed, original file should be untouched
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
void CVsSafeFile::Abort(void)
{
    m_strRealFileName = m_strFileName;
    CVsFile::Abort();
    CVsFile::Remove(m_strRealFileName);     
}

