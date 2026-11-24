//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//
//---------------------------------------------------------------------------
#include "hu_pch.h"
#include "VsFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////
// CVsMemFile implementation

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CVsMemFile::CVsMemFile(UINT nGrowBytes)
{
    ASSERT(nGrowBytes <= UINT_MAX);

    m_nGrowBytes = nGrowBytes;
    m_nPosition = 0;
    m_nBufferSize = 0;
    m_nFileSize = 0;
    m_lpBuffer = NULL;
    m_bAutoDelete = TRUE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CVsMemFile::CVsMemFile(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes)
{
    ASSERT(nGrowBytes <= UINT_MAX);

    m_nGrowBytes = nGrowBytes;
    m_nPosition = 0;
    m_nBufferSize = nBufferSize;
    m_nFileSize = nGrowBytes == 0 ? nBufferSize : 0;
    m_lpBuffer = lpBuffer;
    m_bAutoDelete = FALSE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CVsMemFile::~CVsMemFile(void)
{
    // Close should have already been called, but we check anyway
    if (NULL != m_lpBuffer)
    {
        Close();
    }
    ASSERT(m_lpBuffer == NULL);

    m_nGrowBytes = 0;
    m_nPosition = 0;
    m_nBufferSize = 0;
    m_nFileSize = 0;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CVsMemFile::Attach(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes)
{
    ASSERT(m_lpBuffer == NULL);

    m_nGrowBytes = nGrowBytes;
    m_nPosition = 0;
    m_nBufferSize = nBufferSize;
    m_nFileSize = nGrowBytes == 0 ? nBufferSize : 0;
    m_lpBuffer = lpBuffer;
    m_bAutoDelete = FALSE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BYTE* CVsMemFile::Detach(void)
{
    BYTE* lpBuffer = m_lpBuffer;
    m_lpBuffer = NULL;
    m_nFileSize = 0;
    m_nBufferSize = 0;
    m_nPosition = 0;

    return lpBuffer;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BYTE* CVsMemFile::Alloc(DWORD nBytes)
{
    return (BYTE*)VSAlloc((UINT)nBytes);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BYTE* CVsMemFile::Realloc(BYTE* lpMem, DWORD nBytes)
{
    return (BYTE*)VSRealloc(lpMem, (UINT)nBytes);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#if !defined(_M_CEE)
#pragma intrinsic(memcpy)
#endif
BYTE* CVsMemFile::Memcpy(BYTE* lpMemTarget, const BYTE* lpMemSource,
    UINT nBytes)
{
    ASSERT(lpMemTarget != NULL);
    ASSERT(lpMemSource != NULL);

    return (BYTE*)memcpy(lpMemTarget, lpMemSource, nBytes);
}
#pragma function(memcpy)

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CVsMemFile::Free(BYTE* lpMem)
{
    ASSERT(lpMem != NULL);

    VSFree(lpMem);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
DWORD CVsMemFile::GetPosition(void) const
{
    return m_nPosition;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVsMemFile::GrowFile(DWORD dwNewLen)
{
    if (dwNewLen > m_nBufferSize)
    {
        // grow the buffer
        DWORD dwNewBufferSize = (DWORD)m_nBufferSize;

        // watch out for buffers which cannot be grown!
        ASSERT(m_nGrowBytes != 0);
        if (m_nGrowBytes == 0)
            ASSERT(FALSE); // Must have a Grow Size

        // determine new buffer size
        while (dwNewBufferSize < dwNewLen)
            dwNewBufferSize += m_nGrowBytes;

        // allocate new buffer
        BYTE* lpNew;
        if (m_lpBuffer == NULL)
            lpNew = Alloc(dwNewBufferSize);
        else
            lpNew = Realloc(m_lpBuffer, dwNewBufferSize);
        if (NULL == lpNew)
        {
            ASSERT(!_T("E_OUTOFMEMORY"));
            return FALSE;
        }
        m_lpBuffer = lpNew;
        m_nBufferSize = dwNewBufferSize;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVsMemFile::SetLength(DWORD dwNewLen)
{
    if (dwNewLen > m_nBufferSize)
        if (!GrowFile(dwNewLen))
            return FALSE;

    if (dwNewLen < m_nPosition)
        m_nPosition = dwNewLen;

    m_nFileSize = dwNewLen;
    return TRUE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVsMemFile::Read(void* lpBuf, DWORD nCount, DWORD *pnActualRead)
{
    if (nCount == 0)
    {
        *pnActualRead = 0;
        return TRUE;
    }
    ASSERT(lpBuf != NULL);

    if (m_nPosition > m_nFileSize)
    {
        *pnActualRead = 0;
        return TRUE;
    }

    UINT nRead;
    if (m_nPosition + nCount > m_nFileSize)
        nRead = (UINT)(m_nFileSize - m_nPosition);
    else
        nRead = nCount;

    Memcpy((BYTE*)lpBuf, (BYTE*)m_lpBuffer + m_nPosition, nRead);
    m_nPosition += nRead;
    
    *pnActualRead = nRead;
    return TRUE;
}

//---------------------------------------------------------------------------
// return FALSE on failure, use GetLastError() for failure reason
//---------------------------------------------------------------------------
BOOL CVsMemFile::Write(const void *lpBuf, DWORD nCount, DWORD *pdwActualWrite)
{
    if (nCount == 0)
    {
        *pdwActualWrite = 0;
        return TRUE;
    }
    ASSERT(lpBuf != NULL);

    if (m_nPosition + nCount > m_nBufferSize)
    {
        if (!GrowFile(m_nPosition + nCount))
        {
            *pdwActualWrite = 0;
            return FALSE;
        }
    }
    ASSERT(m_nPosition + nCount <= m_nBufferSize);

    Memcpy((BYTE*)m_lpBuffer + m_nPosition, (BYTE*)lpBuf, nCount);

    m_nPosition += nCount;

    if (m_nPosition > m_nFileSize)
        m_nFileSize = m_nPosition;
    *pdwActualWrite = nCount;
    return TRUE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVsMemFile::Seek(LONG lOff,  DWORD dwMoveMethod, DWORD *pnPosition)
{
    ASSERT(dwMoveMethod == begin || dwMoveMethod == end || dwMoveMethod == current);

    LONG lNewPos = m_nPosition;

    if (dwMoveMethod == begin)
        lNewPos = lOff;
    else if (dwMoveMethod == current)
        lNewPos += lOff;
    else if (dwMoveMethod == end)
        lNewPos = m_nFileSize + lOff;
    else
    {
        *pnPosition = (DWORD)-1;
        return FALSE;
    }
    if (lNewPos < 0)
        ASSERT(FALSE);

    *pnPosition = m_nPosition = lNewPos;
    return TRUE;
}
//---------------------------------------------------------------------------
// Sets EOF to the current position of the file
//---------------------------------------------------------------------------
BOOL CVsMemFile::SetEndOfFile()
{
    return SetLength(GetPosition());
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVsMemFile::Flush(void)
{
    return TRUE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVsMemFile::Close(void)
{
    m_nGrowBytes = 0;
    m_nPosition = 0;
    m_nBufferSize = 0;
    m_nFileSize = 0;
    if (m_lpBuffer && m_bAutoDelete)
        Free(m_lpBuffer);
    m_lpBuffer = NULL;

    return TRUE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CVsMemFile::Abort(void)
{
    Close();
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// only CVsMemFile supports "direct buffering" interaction with CArchive
UINT CVsMemFile::GetBufferPtr(UINT nCommand, UINT nCount,
    void** ppBufStart, void**ppBufMax)
{
    ASSERT(nCommand == bufferCheck || nCommand == bufferCommit ||
        nCommand == bufferRead || nCommand == bufferWrite);

    if (nCommand == bufferCheck)
        return 1;   // just a check for direct buffer support

    if (nCommand == bufferCommit)
    {
        // commit buffer
        ASSERT(ppBufStart == NULL);
        ASSERT(ppBufMax == NULL);
        m_nPosition += nCount;
        if (m_nPosition > m_nFileSize)
            m_nFileSize = m_nPosition;
        return 0;
    }

    ASSERT(nCommand == bufferWrite || nCommand == bufferRead);
    ASSERT(ppBufStart != NULL);
    ASSERT(ppBufMax != NULL);

    // when storing, grow file as necessary to satisfy buffer request
    if (nCommand == bufferWrite && m_nPosition + nCount > m_nBufferSize)
        GrowFile(m_nPosition + nCount);

    // store buffer max and min
    *ppBufStart = m_lpBuffer + m_nPosition;

    // end of buffer depends on whether you are reading or writing
    if (nCommand == bufferWrite)
        *ppBufMax = m_lpBuffer + min(m_nBufferSize, m_nPosition + nCount);
    else
    {
        if (nCount == (UINT)-1)
            nCount = m_nBufferSize - m_nPosition;
        *ppBufMax = m_lpBuffer + min(m_nFileSize, m_nPosition + nCount);
        m_nPosition += (LONG32) (LPBYTE(*ppBufMax) - LPBYTE(*ppBufStart));
    }

    // return number of bytes in returned buffer space (may be <= nCount)
    // ASSERT this is < INT_MAX
    return (ULONG32) (LPBYTE(*ppBufMax) - LPBYTE(*ppBufStart));
}
