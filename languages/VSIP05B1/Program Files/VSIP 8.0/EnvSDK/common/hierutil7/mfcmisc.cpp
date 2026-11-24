//-----------------------------------------------------------------------------
//  Microsoft Visual Studio
//
//  Contains misc classes ported from MFC
//
//  Copyright (C) 1996 - 2000 Microsoft Corporation,
//  All rights reserved.
//-----------------------------------------------------------------------------
#include "hu_pch.h"
#include "mfcincl.h"
//-----------------------------------------------------------------------------
// class CWaitCursor
//-----------------------------------------------------------------------------
HCURSOR CWaitCursor::m_hWaitCur = ::LoadCursor(NULL, IDC_WAIT);


int VxLoadString(UINT nID, LPTSTR lpszBuf, UINT nMaxBuf, HINSTANCE hInst);

//-----------------------------------------------------------------------------
// Formatting helpers
//-----------------------------------------------------------------------------
void VxFormatStrings(CString& rString, UINT nIDS, LPCTSTR const* rglpsz, int nString)
{
    TCHAR szFormat[512];
    if (!VxLoadString(nIDS, szFormat, 512, _AtlBaseModule.GetResourceInstance()) != 0)
    {
        ATLTRACE(_T("Error: failed to load VxFormatString string 0x%04x.\n"), nIDS);
        ASSERT(FALSE);
        return;
    }
    VxFormatStrings(rString, szFormat, rglpsz, nString);
}

void VxFormatStrings(CString& rString, LPCTSTR lpszFormat, LPCTSTR const* rglpsz, 
                      int nString)
{
    // determine length of destination string
    int nTotalLen = 0;
    LPCTSTR pchSrc = lpszFormat;
    while (*pchSrc != '\0')
    {
        if (pchSrc[0] == '%' &&
             ( (pchSrc[1] >= '1' && pchSrc[1] <= '9') ||
                (pchSrc[1] >= 'A' && pchSrc[1] <= 'Z')) )
        {
            // %A comes after %9 -- we'll need it someday
            int i;
            if (pchSrc[1] > '9')
                i = 9 + (pchSrc[1] - 'A');
            else
                i = pchSrc[1] - '1';
            pchSrc += 2;
            if (i >= nString)
                ++nTotalLen;
            else if (rglpsz[i] != NULL)
                nTotalLen += lstrlen(rglpsz[i]);
        }
        else
        {
            if (_istlead(*pchSrc))
                ++nTotalLen, ++pchSrc;
            ++pchSrc;
            ++nTotalLen;
        }
    }

    pchSrc = lpszFormat;
    LPTSTR pchDest = rString.GetBuffer(nTotalLen);
    while (*pchSrc != '\0')
    {
        if (pchSrc[0] == '%' &&
             ( (pchSrc[1] >= '1' && pchSrc[1] <= '9') ||
                (pchSrc[1] >= 'A' && pchSrc[1] <= 'Z')) )
        {
            // %A comes after %9 -- we'll need it someday
            int i;
            if (pchSrc[1] > '9')
                i = 9 + (pchSrc[1] - 'A');
            else
                i = pchSrc[1] - '1';
            pchSrc += 2;
            if (i >= nString)
            {
                ATLTRACE(_T("Error: illegal string index requested %d.\n"), i);
                *pchDest++ = '?';
            }
            else if (rglpsz[i] != NULL)
            {
                lstrcpy(pchDest, rglpsz[i]);
                pchDest += lstrlen(pchDest);
            }
        }
        else
        {
            if (_istlead(*pchSrc))
                *pchDest++ = *pchSrc++; // copy first of 2 bytes
            *pchDest++ = *pchSrc++;
        }
    }
    rString.ReleaseBuffer((int)((LPCTSTR)pchDest - (LPCTSTR)rString));
        // ReleaseBuffer will assert if we went too far
}

void VxFormatString1(CString& rString, UINT nIDS, LPCTSTR lpsz1)
{
    VxFormatStrings(rString, nIDS, &lpsz1, 1);
}

void VxFormatString2(CString& rString, UINT nIDS, LPCTSTR lpsz1,LPCTSTR lpsz2)
{
    LPCTSTR rglpsz[2];
    rglpsz[0] = lpsz1;
    rglpsz[1] = lpsz2;
    VxFormatStrings(rString, nIDS, rglpsz, 2);
}

void VxFormatString3(CString& rString, UINT nIDS, LPCTSTR lpsz1,LPCTSTR lpsz2,LPCTSTR lpsz3)
{
    LPCTSTR rglpsz[3];
    rglpsz[0] = lpsz1;
    rglpsz[1] = lpsz2;
    rglpsz[2] = lpsz3;
    VxFormatStrings(rString, nIDS, rglpsz, 3);
}

int VxLoadString(UINT nID, LPTSTR lpszBuf, UINT nMaxBuf, HINSTANCE hInst)
{
    ASSERT(VxIsValidAddress(lpszBuf, nMaxBuf*sizeof(TCHAR)));
#ifdef _DEBUG
    // LoadString without annoying warning from the Debug kernel if the
    //  segment containing the string is not present
    if (::FindResource(hInst, MAKEINTRESOURCE((nID>>4)+1), RT_STRING) == NULL)
    {
        lpszBuf[0] = '\0';
        return 0; // not found
    }
#endif //_DEBUG
    int nLen = ::LoadString(_AtlBaseModule.GetResourceInstance(), nID, lpszBuf, nMaxBuf);
    if (nLen == 0)
        lpszBuf[0] = '\0';
    return nLen;
}


static BOOL ReadStringLength(CVsFile& file, DWORD *pdwLen)
{

    // attempt BYTE length first
    BYTE bLen;
    if (!file.Read(&bLen, sizeof(BYTE), pdwLen) ||  *pdwLen != sizeof(BYTE))
        return FALSE;

    if (bLen < 0xff)
    {
        *pdwLen = bLen;
        return TRUE;
    }

    // attempt WORD length
    WORD wLen;
    if (!file.Read(&wLen, sizeof(WORD), pdwLen) ||  *pdwLen != sizeof(WORD))
        return FALSE;

    if (wLen == 0xfffe)
    {
        // UNICODE string prefix (length will follow)
        *pdwLen = (DWORD)-1;
    }
    else if (wLen == 0xffff)
    {
        DWORD nNewLen;
        // read DWORD of length
        if (!file.Read(&nNewLen, sizeof(DWORD), pdwLen) ||  *pdwLen != sizeof(DWORD))
            return FALSE;
        *pdwLen = nNewLen;
    }
    return TRUE;
}

// return FALSE on failure, use GetLastError() for failure reason
BOOL SerializeString(CString& str, CVsFile& file, BOOL bWrite)
{
    DWORD dwLen;
    if (bWrite)
    {
        // special signature to recognize unicode strings
#ifdef _UNICODE
        BYTE uniByte = 0xff;
        WORD uniWord= 0xfffe;
        if (!file.Write( &uniByte, sizeof(BYTE), &dwLen))
            return FALSE;
        if (!file.Write( &uniWord, sizeof(WORD), &dwLen))
            return FALSE;
#endif
        int len = (int)str.GetLength();
        if (len < 255)
        {
            if (!file.Write(&len, sizeof(BYTE), &dwLen))
                return FALSE;
        }
        else if (len < 0xfffe)
        {
            BYTE data = 0xff;
            if (!file.Write( &data, sizeof(BYTE), &dwLen))
                return FALSE;
            if (!file.Write(&len, sizeof(WORD), &dwLen))
                return FALSE;
        }
        else
        {
            DWORD data = 0xffffff;
            if (!file.Write(&data, 3, &dwLen))
                return FALSE;
            if (!file.Write(&len, sizeof(DWORD), &dwLen))
                return FALSE;
        }
        // Don't write 0 data
        if(len)
        {
            if (!file.Write((LPCTSTR)str, len*sizeof(TCHAR), &dwLen))
                return FALSE;
        }
    }
    else
    {   // Reading
    #ifdef _UNICODE
        int nConvert = 1;   // if we get ANSI, convert
    #else
        int nConvert = 0;   // if we get UNICODE, convert
    #endif

        DWORD nNewLen;
        if (!ReadStringLength(file, &nNewLen))
            return FALSE;

        if (nNewLen == (DWORD)-1)
        {
            nConvert = 1 - nConvert;
            if (!ReadStringLength(file, &nNewLen))
                return FALSE;

            ASSERT(nNewLen != -1);
        }

        // set length of string to new length
        UINT nByteLen = nNewLen;
        TCHAR* pBuffer;
    #ifdef _UNICODE
        pBuffer = str.GetBufferSetLength((int)nNewLen);
        nByteLen += nByteLen * (1 - nConvert);  // bytes to read
    #else
        nByteLen += nByteLen * nConvert;    // bytes to read
        if (nNewLen == 0)
            pBuffer = str.GetBufferSetLength(0);
        else
            pBuffer = str.GetBufferSetLength((int)nByteLen+nConvert);
    #endif

        // read in the characters
        if (nNewLen != 0)
        {
            ASSERT(nByteLen != 0);

            // read new data
            if (!file.Read(pBuffer, nByteLen, &dwLen)   ||  dwLen != nByteLen)
                return FALSE;
        
            str.ReleaseBuffer(nNewLen);
            // convert the data if as necessary
            if (nConvert != 0)
            {   // Note that we didn't implement the conversions.
                ASSERT(FALSE);
            }
        }
    }
    return TRUE;
}

#ifdef new
#pragma push_macro("new")
#undef new
#define _REDEF_NEW
#endif

///////////////////////////////////////////////////////////////////////////////
// CString support for template collections
template<> void ConstructElements<CString> (CString* pElements, int nCount)
{
    ASSERT(nCount == 0 || VxIsValidAddress(pElements, nCount * sizeof(CString)));

    for (; nCount--; ++pElements)
    {
        ::new(pElements) CString;
//        memcpy(pElements, &_cstrPchNil, sizeof(*pElements));
    }
}

#ifdef _REDEF_NEW
#pragma pop_macro("new")
#undef _REDEF_NEW
#endif

template<> void DestructElements<CString> (CString* pElements, int nCount)
{
    ASSERT(nCount == 0 || VxIsValidAddress(pElements, nCount * sizeof(CString)));

    for (; nCount--; ++pElements)
        pElements->~CString();
}

template<> void CopyElements<CString> (CString* pDest, const CString* pSrc, int nCount)
{
    ASSERT(nCount == 0 || VxIsValidAddress(pDest, nCount * sizeof(CString)));
    ASSERT(nCount == 0 || VxIsValidAddress(pSrc, nCount * sizeof(CString)));

    for (; nCount--; ++pDest, ++pSrc)
        *pDest = *pSrc;
}

template<> UINT HashKey<LPCWSTR> (LPCWSTR key)
{
    UINT nHash = 0;
    while (*key)
        nHash = (nHash<<5) + nHash + *key++;
    return nHash;
}

template<> UINT HashKey<LPCSTR> (LPCSTR key)
{
    UINT nHash = 0;
    while (*key)
        nHash = (nHash<<5) + nHash + *key++;
    return nHash;
}
