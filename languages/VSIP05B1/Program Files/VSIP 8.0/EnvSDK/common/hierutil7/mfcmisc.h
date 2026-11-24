//-----------------------------------------------------------------------------
//  Microsoft Visual Studio
//
//  Contains misc classes ported from MFC
//
//  Copyright (C) 1996-2000 Microsoft Corporation,
//  All rights reserved.
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __MFCMISC_H__
#define __MFCMISC_H__

class CVsFile;

// Useful formatting functions to handle the %1, & %2 type formatting
void VxFormatString1(CString& rString, UINT nIDS, LPCTSTR lpsz1);
void VxFormatString2(CString& rString, UINT nIDS, LPCTSTR lpsz1,LPCTSTR lpsz2);
void VxFormatString3(CString& rString, UINT nIDS, LPCTSTR lpsz1,LPCTSTR lpsz2,LPCTSTR lpsz3);
void VxFormatStrings(CString& rString, UINT nIDS, LPCTSTR const* rglpsz, int nString);
void VxFormatStrings(CString& rString, LPCTSTR lpszFormat, LPCTSTR const* rglpsz, int nString);

// Does the equivalent of the old CString::Serialize
BOOL SerializeString(CString& str, CVsFile& file, BOOL bWrite);

//-----------------------------------------------------------------------------
// class CWaitCursor
//-----------------------------------------------------------------------------
class CWaitCursor
{
public:
    CWaitCursor() {m_hPrevCur = ::SetCursor(m_hWaitCur);}
    ~CWaitCursor() {::SetCursor(m_hPrevCur); }
    void Restore() {::SetCursor(m_hWaitCur);}

protected:
    HCURSOR m_hPrevCur;
    static HCURSOR m_hWaitCur;
};

#endif
