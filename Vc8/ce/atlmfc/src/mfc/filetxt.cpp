// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#ifndef _WIN32_WCE
#include <errno.h>
#include <io.h>
#include <fcntl.h>
#endif // !_WIN32_WCE
#include "sal.h"



#define new DEBUG_NEW

////////////////////////////////////////////////////////////////////////////
// CStdioFile implementation

CStdioFile::CStdioFile()
{
#ifndef _WIN32_WCE
	m_pStream = NULL;
#endif // !_WIN32_WCE
}

#ifndef _WIN32_WCE
CStdioFile::CStdioFile(FILE* pOpenStream)
{
	ASSERT(pOpenStream != NULL);
	
	if (pOpenStream == NULL)
	{
		AfxThrowInvalidArgException();
	}
	
	m_pStream = pOpenStream;
	m_hFile = (HANDLE) _get_osfhandle(_fileno(pOpenStream));
	ASSERT(!m_bCloseOnDelete);
}
#endif // !_WIN32_WCE

CStdioFile::CStdioFile(LPCTSTR lpszFileName, UINT nOpenFlags)
{
	ASSERT(lpszFileName != NULL);
	ASSERT(AfxIsValidString(lpszFileName));

	if (lpszFileName == NULL)
	{
		AfxThrowInvalidArgException();
	}

	CFileException e;
	if (!Open(lpszFileName, nOpenFlags, &e))
		AfxThrowFileException(e.m_cause, e.m_lOsError, e.m_strFileName);
}

CStdioFile::~CStdioFile()
{
	AFX_BEGIN_DESTRUCTOR

	ASSERT_VALID(this);

#ifndef _WIN32_WCE // Let CFile::~CFile do the real work
	if (m_pStream != NULL && m_bCloseOnDelete)
		Close();

#endif // !_WIN32_WCE

	AFX_END_DESTRUCTOR
}

#ifndef _WIN32_WCE
BOOL CStdioFile::Open(LPCTSTR lpszFileName, UINT nOpenFlags,
	CFileException* pException)
{
	ASSERT(pException == NULL || AfxIsValidAddress(pException, sizeof(CFileException)));
	ASSERT(lpszFileName != NULL);
	ASSERT(AfxIsValidString(lpszFileName));

	if (lpszFileName == NULL)
	{
		return FALSE;
	}

	m_pStream = NULL;
	if (!CFile::Open(lpszFileName, (nOpenFlags & ~typeText), pException))
		return FALSE;

	ASSERT(m_hFile != hFileNull);
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
	int nHandle = _open_osfhandle((UINT_PTR) m_hFile, nFlags);

	// open a C-runtime stream from that handle
	if (nHandle != -1)
		m_pStream = _fdopen(nHandle, szMode);

	if (m_pStream == NULL)
	{
		// an error somewhere along the way...
		if (pException != NULL)
		{
			pException->m_lOsError = _doserrno;
			pException->m_cause = CFileException::OsErrorToException(_doserrno);
		}

		CFile::Abort(); // close m_hFile
		return FALSE;
	}

	return TRUE;
}

UINT CStdioFile::Read(void* lpBuf, UINT nCount)
{
	ASSERT_VALID(this);
	ASSERT(m_pStream != NULL);

	if (nCount == 0)
		return 0;   // avoid Win32 "null-read"

	ASSERT(AfxIsValidAddress(lpBuf, nCount));

	if (lpBuf == NULL)
	{
		AfxThrowInvalidArgException();
	}

	UINT nRead = 0;

	if ((nRead = (UINT)fread(lpBuf, sizeof(BYTE), nCount, m_pStream)) == 0 && !feof(m_pStream))
		AfxThrowFileException(CFileException::genericException, _doserrno, m_strFileName);
	if (ferror(m_pStream))
	{
		Afx_clearerr_s(m_pStream);
		AfxThrowFileException(CFileException::genericException, _doserrno, m_strFileName);
	}
	return nRead;
}

void CStdioFile::Write(const void* lpBuf, UINT nCount)
{
	ASSERT_VALID(this);
	ASSERT(m_pStream != NULL);
	ASSERT(AfxIsValidAddress(lpBuf, nCount, FALSE));

	if (lpBuf == NULL)
	{
		AfxThrowInvalidArgException();
	}

	if (fwrite(lpBuf, sizeof(BYTE), nCount, m_pStream) != nCount)
		AfxThrowFileException(CFileException::genericException, _doserrno, m_strFileName);
}
#endif // !_WIN32_WCE

void CStdioFile::WriteString(LPCTSTR lpsz)
{
	ASSERT(lpsz != NULL);
#ifndef _WIN32_WCE
	ASSERT(m_pStream != NULL);
#endif // !_WIN32_WCE
	
	if (lpsz == NULL)
	{
		AfxThrowInvalidArgException();
	}

#ifndef _WIN32_WCE
	if (_fputts(lpsz, m_pStream) == _TEOF)
		AfxThrowFileException(CFileException::diskFull, _doserrno, m_strFileName);
#else // !_WIN32_WCE
	// Writing is not buffered, just let the internal OS buffer handle it.
	CFile::Write(reinterpret_cast<const void*>(lpsz), ::wcslen(lpsz)*sizeof(*lpsz));
	CFile::Write(reinterpret_cast<const void*>(m_lpszNewLine), m_nNewLenBytes);
#endif // !_WIN32_WCE
}

LPTSTR CStdioFile::ReadString(__out_ecount(nMax) LPTSTR lpsz, UINT nMax)
{
	ASSERT(lpsz != NULL);
	ASSERT(AfxIsValidAddress(lpsz, nMax));
#ifndef _WIN32_WCE
	ASSERT(m_pStream != NULL);
#endif // !_WIN32_WCE

	if (lpsz == NULL)
	{
		AfxThrowInvalidArgException();
	}

#ifndef _WIN32_WCE
	LPTSTR lpszResult = _fgetts(lpsz, nMax, m_pStream);
	if (lpszResult == NULL && !feof(m_pStream))
	{
		Afx_clearerr_s(m_pStream);
		AfxThrowFileException(CFileException::genericException, _doserrno, m_strFileName);
	}
	return lpszResult;
#else // !_WIN32_WCE
	// Reading is not buffered, just let the internal OS buffer handle it.

	ULONGLONG nStartPosition = CFile::GetPosition();

	UINT nRead = CFile::Read(
		reinterpret_cast<void*>(lpsz), 
		nMax*sizeof(*lpsz) // convert from characters to bytes
		);
	
	nRead /= sizeof(*lpsz); // convert from bytes to characters

	if(nRead == 0)
	{
		// pointer currently past end of file
		AfxThrowFileException(CFileException::endOfFile, -1, m_strFileName);
	}

	// if nRead != nMax then nRead is position of EOF, which is where string should be terminated
	UINT nEndOfString = nRead;

	bool fAllRead = nRead == nMax;
	bool fEndOfLineFound = false;
	if(fAllRead)
	{
		// find end of line character, if none the string will be terminated at the very end.
		for(UINT nLen = 0; nLen < nRead; ++nLen)
		{
			if(lpsz[nLen]=='\n')
			{
				// found end of line character, terminate string string there.
				fEndOfLineFound = true;
				nEndOfString = nLen;
				break;
			}
		}
	}

	// null terminate the string.
	lpsz[nEndOfString] = '\0';

	// end of line was found in the last position or read less then nMax (i.e. EOF was found), but no end of line was found
	// no need to adjust the file pointer in either case.
	if((nEndOfString == nRead) || (!fAllRead && !fEndOfLineFound))
	{
		return lpsz;
	}
	
	// read nMax, but no end of line was found
	// last character is not included in result, so nStartPosition + nEndOfString is correct place to put file pointer, 
	// so no adjustment to nEndOfString required.
	//if(fAllRead && !fEndOfLineFound);

	// end of line was found before the last character (or we would have bailed above)
	// the end of line character is not included in the result, but shouldn't be in the next one either
	// so nStartPosition + nEndOfString + 1 is the correct place to put the file pointer.
	if(fEndOfLineFound)
	{
		++nEndOfString;
 	}

	// Reset the file pointer to the position immediately after the end of line character
	CFile::Seek(nStartPosition + nEndOfString * sizeof(TCHAR), begin); // convert from characters to bytes
	
	return lpsz;
#endif // !_WIN32_WCE
}

BOOL CStdioFile::ReadString(CString& rString)
{
	ASSERT_VALID(this);

#ifdef _WIN32_WCE
	ULONGLONG nStartPosition = CFile::GetPosition();
	bool fEndOfFile = false;
#endif // _WIN32_WCE

	rString = _T("");    // empty string without deallocating
	const int nMaxSize = 128;
	LPTSTR lpsz = rString.GetBuffer(nMaxSize);
	LPTSTR lpszResult;
	int nLen = 0;
	for (;;)
	{
#ifndef _WIN32_WCE
		lpszResult = _fgetts(lpsz, nMaxSize+1, m_pStream);
		rString.ReleaseBuffer();

		// handle error/eof case
		if (lpszResult == NULL && !feof(m_pStream))
		{
			Afx_clearerr_s(m_pStream);
			AfxThrowFileException(CFileException::genericException, _doserrno,
				m_strFileName);
		}

		// if string is read completely or EOF
		if (lpszResult == NULL ||
			(nLen = (int)ATL::lstrlen(lpsz)) < nMaxSize ||
			lpsz[nLen-1] == '\n')
			break;
#else // !_WIN32_WCE
		(lpszResult);

		// Reading is not buffered, just let the internal OS buffer handle it.
		UINT nRead = CFile::Read(
			reinterpret_cast<void*>(lpsz), 
			(nMaxSize)*sizeof(*lpsz) // convert from characters to bytes
			);
		
		nRead /= sizeof(*lpsz); // convert from bytes to characters

		if(nRead != nMaxSize)
		{
			// reached end of file, terminate the string here.
			fEndOfFile = true;
			nLen = nRead;
			break;
		}

		// check for end of line character
		for(nLen = 0 ; nLen < static_cast<int>(nRead) && lpsz[nLen] != '\n' ; ++nLen)
			;

		if(lpsz[nLen]=='\n')
		{
			// nLen is correct location of end of line, which should be replaced with a null terminator
			break;
		}
		
		rString.ReleaseBuffer();

#endif // !_WIN32_WCE

		nLen = rString.GetLength();
		lpsz = rString.GetBuffer(nMaxSize + nLen) + nLen;
	}

#ifdef _WIN32_WCE
	lpsz[nLen] = '\0';
	rString.ReleaseBuffer();
#endif // _WIN32_WCE

	nLen = rString.GetLength();

#ifndef _WIN32_WCE
	// remove '\n' from end of string if present
	lpsz = rString.GetBuffer(0);
	nLen = rString.GetLength();
	if (nLen != 0 && lpsz[nLen-1] == '\n')
		rString.GetBufferSetLength(nLen-1);
#else // !_WIN32_WCE
	// Reset the file pointer to the position immediately after the end of line character
	if(!fEndOfFile)
	{
		CFile::Seek(nStartPosition + (nLen + 1) * sizeof(TCHAR), begin);
	}
#endif // !_WIN32_WCE

	return nLen != 0;
}

#ifndef _WIN32_WCE
ULONGLONG CStdioFile::Seek(LONGLONG lOff, UINT nFrom)
{
	ASSERT_VALID(this);
	ASSERT(nFrom == begin || nFrom == end || nFrom == current);
	ASSERT(m_pStream != NULL);

   LONG lOff32;

   if ((lOff < LONG_MIN) || (lOff > LONG_MAX))
   {
	  AfxThrowFileException(CFileException::badSeek, -1, m_strFileName);
   }

   lOff32 = (LONG)lOff;
	if (fseek(m_pStream, lOff32, nFrom) != 0)
		AfxThrowFileException(CFileException::badSeek, _doserrno,
			m_strFileName);

	long pos = ftell(m_pStream);
	return pos;
}

ULONGLONG CStdioFile::GetLength() const
{
   ASSERT_VALID(this);

   LONG nCurrent;
   LONG nLength;
   LONG nResult;

   nCurrent = ftell(m_pStream);
   if (nCurrent == -1)
	  AfxThrowFileException(CFileException::invalidFile, _doserrno,
		 m_strFileName);

   nResult = fseek(m_pStream, 0, SEEK_END);
   if (nResult != 0)
	  AfxThrowFileException(CFileException::badSeek, _doserrno,
		 m_strFileName);

   nLength = ftell(m_pStream);
   if (nLength == -1)
	  AfxThrowFileException(CFileException::invalidFile, _doserrno,
		 m_strFileName);
   nResult = fseek(m_pStream, nCurrent, SEEK_SET);
   if (nResult != 0)
	  AfxThrowFileException(CFileException::badSeek, _doserrno,
		 m_strFileName);

   return nLength;
}

ULONGLONG CStdioFile::GetPosition() const
{
	ASSERT_VALID(this);
	ASSERT(m_pStream != NULL);

	long pos = ftell(m_pStream);
	if (pos == -1)
		AfxThrowFileException(CFileException::invalidFile, _doserrno,
			m_strFileName);
	return pos;
}

void CStdioFile::Flush()
{
	ASSERT_VALID(this);

	if (m_pStream != NULL && fflush(m_pStream) != 0)
		AfxThrowFileException(CFileException::diskFull, _doserrno,
			m_strFileName);
}

void CStdioFile::Close()
{
	ASSERT_VALID(this);
	ASSERT(m_pStream != NULL);

	int nErr = 0;

	if (m_pStream != NULL)
		nErr = fclose(m_pStream);

	m_hFile = hFileNull;
	m_bCloseOnDelete = FALSE;
	m_pStream = NULL;

	if (nErr != 0)
		AfxThrowFileException(CFileException::diskFull, _doserrno,
			m_strFileName);
}

void CStdioFile::Abort()
{
	ASSERT_VALID(this);

	if (m_pStream != NULL && m_bCloseOnDelete)
		fclose(m_pStream);  // close but ignore errors
	m_hFile = hFileNull;
	m_pStream = NULL;
	m_bCloseOnDelete = FALSE;
}

CFile* CStdioFile::Duplicate() const
{
	ASSERT_VALID(this);
	ASSERT(m_pStream != NULL);

	AfxThrowNotSupportedException();
}

void CStdioFile::LockRange(ULONGLONG /* dwPos */, ULONGLONG /* dwCount */)
{
	ASSERT_VALID(this);
	ASSERT(m_pStream != NULL);

	AfxThrowNotSupportedException();
}

void CStdioFile::UnlockRange(ULONGLONG /* dwPos */, ULONGLONG /* dwCount */)
{
	ASSERT_VALID(this);
	ASSERT(m_pStream != NULL);

	AfxThrowNotSupportedException();
}

#ifdef _DEBUG
void CStdioFile::Dump(CDumpContext& dc) const
{
	CFile::Dump(dc);

	dc << "m_pStream = " << (void*)m_pStream;
	dc << "\n";
}
#endif
#endif // !_WIN32_WCE


#ifdef _WIN32_WCE
LPCTSTR CStdioFile::m_lpszNewLine = _T("\n");
UINT CStdioFile::m_nNewLenBytes = 1 * sizeof(*CStdioFile::m_lpszNewLine);
#endif // _WIN32_WCE

IMPLEMENT_DYNAMIC(CStdioFile, CFile)
/////////////////////////////////////////////////////////////////////////////
