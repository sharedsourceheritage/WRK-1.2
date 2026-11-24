//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __VSFILE_H__
#define __VSFILE_H__

#ifndef _INC_STDIO
#include <stdio.h>
#endif

//---------------------------------------------------------------------------
// File - raw unbuffered disk file I/O
//---------------------------------------------------------------------------
class CVsFile
{
public:
// Flag values
	enum OpenFlags {
		modeRead =          0x0000,
		modeWrite =         0x0001,
		modeReadWrite =     0x0002,
		shareCompat =       0x0000,
		shareExclusive =    0x0010,
		shareDenyWrite =    0x0020,
		shareDenyRead =     0x0030,
		shareDenyNone =     0x0040,
		modeNoInherit =     0x0080,
		modeCreate =        0x1000,
		modeNoTruncate =    0x2000,
		typeText =          0x4000, // typeText and typeBinary are used in
		typeBinary =   (int)0x8000 // derived classes only
		};

	enum Attribute {
		normal =    0x00,
		readOnly =  0x01,
		hidden =    0x02,
		system =    0x04,
		volume =    0x08,
		directory = 0x10,
		archive =   0x20
		};

	// Construction
			 CVsFile(void);
	virtual ~CVsFile(void);

	virtual BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags);
	virtual BOOL Close(void);
	virtual void Abort(void);
	virtual DWORD GetLength() const;
	virtual BOOL Flush(void);


	// Input/Output
	virtual BOOL Read(void* lpBuf, DWORD nCount, DWORD *pnActualRead);
	virtual BOOL Write(const void *lpBuf, DWORD nCount, DWORD *pnActualWrite);

	// Position
	// dwMoveMethod = { FILE_BEGIN, FILE_END, FILE_CURRENT }
	virtual BOOL Seek(LONG lOff, DWORD dwMoveMethod, DWORD *pnPosition);
    virtual BOOL SetEndOfFile();

	// Static
	static BOOL Rename(LPCTSTR lpszOldName,	LPCTSTR lpszNewName);
	static BOOL Remove(LPCTSTR lpszFileName);

	// Implementation

protected:
	HANDLE m_hFile;
	BOOL m_bCloseOnDelete;
	CString m_strFileName;
};

//---------------------------------------------------------------------------
// STDIO file implementation
//---------------------------------------------------------------------------
class CVsStdioFile : public CVsFile
{
public:
	// Construction
			 CVsStdioFile(int nMaxSize = 128);
	virtual ~CVsStdioFile(void);

	virtual BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags);
	virtual BOOL Close(void);
	virtual void Abort(void);

	// Input/Output
	virtual BOOL Read(void* lpBuf, DWORD nCount, DWORD *pnActualRead);
	virtual BOOL Write(const void *lpBuf, DWORD nCount, DWORD *pnActualWrite);

	virtual BOOL ReadString(LPWSTR lpsz, UINT nMax);
	virtual BOOL ReadString(LPSTR lpsz, UINT nMax);
	virtual BOOL ReadString(CString& str);
	virtual BOOL WriteString(LPCWSTR lpsz);
	virtual BOOL WriteString(LPCSTR lpsz);

	// Position
	virtual BOOL Seek(LONG lOff, DWORD dwMoveMethod, DWORD *pnPosition);

	virtual BOOL Flush(void);

protected:
	FILE* m_pStream;    // stdio FILE
	int m_nMaxSize;
};

//---------------------------------------------------------------------------
// only valid for output files
// opens a temporary file instead of given filename
// at CVsSafeFile::Close, real file is removed, tempfile is renamed to real file
// at CVsSafeFile::Abort, tempfile is removed
//---------------------------------------------------------------------------
class CVsSafeFile : public CVsFile
{
public:
	virtual BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags, LPCTSTR lpszTempPath = NULL);
	virtual BOOL Close(void);
	virtual void Abort(void);

protected:
	CString m_strRealFileName;
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CVsMemFile : public CVsFile
{
public:
			 CVsMemFile(UINT nGrowBytes = 1024);
			 CVsMemFile(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);
	virtual ~CVsMemFile(void);

// Operations
	void Attach(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes = 0);
	BYTE* Detach();

	enum BufferCommand { bufferRead, bufferWrite, bufferCommit, bufferCheck };

// Advanced Overridables
protected:
	virtual BYTE* Alloc(DWORD nBytes);
	virtual BYTE* Realloc(BYTE* lpMem, DWORD nBytes);
	virtual BYTE* Memcpy(BYTE* lpMemTarget, const BYTE* lpMemSource, UINT nBytes);
	virtual void Free(BYTE* lpMem);
	virtual BOOL GrowFile(DWORD dwNewLen);

// Implementation
protected:
	UINT  m_nGrowBytes;
	DWORD m_nPosition;
	DWORD m_nBufferSize;
	DWORD m_nFileSize;
	BYTE* m_lpBuffer;
	BOOL  m_bAutoDelete;
	
	enum SeekPosition { begin = 0x0, current = 0x1, end = 0x2 };

public:
	virtual DWORD GetPosition() const;
	virtual BOOL Seek(LONG lOff,  DWORD dwMoveMethod, DWORD *pnPosition);
	virtual BOOL SetLength(DWORD dwNewLen);
	virtual DWORD GetLength() const {return m_nFileSize;};
	// Input/Output
	virtual BOOL Read(void* lpBuf, DWORD nCount, DWORD *pnActualRead);
	virtual BOOL Write(const void *lpBuf, DWORD nCount, DWORD *pnActualWrite);

    virtual BOOL SetEndOfFile();

	virtual void Abort(void);
	virtual BOOL Flush(void);
	virtual BOOL Close(void);
	virtual UINT GetBufferPtr(UINT nCommand, UINT nCount = 0,
		void** ppBufStart = NULL, void** ppBufMax = NULL);
};


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CVsSharedFile : public CVsMemFile
{
public:
// Constructors
	CVsSharedFile(UINT nAllocFlags = GMEM_DDESHARE|GMEM_MOVEABLE,
		UINT nGrowBytes = 4096);

// Attributes
	HGLOBAL Detach();
	void SetHandle(HGLOBAL hGlobalMemory, BOOL bAllowGrow = TRUE);

// Implementation
public:
	virtual ~CVsSharedFile();

protected:
	virtual BYTE* Alloc(DWORD nBytes);
	virtual BYTE* Realloc(BYTE* lpMem, DWORD nBytes);
	virtual void Free(BYTE* lpMem);

	UINT m_nAllocFlags;
	HGLOBAL m_hGlobalMemory;
	BOOL m_bAllowGrow;
};
#endif // __VSFILE_H__
