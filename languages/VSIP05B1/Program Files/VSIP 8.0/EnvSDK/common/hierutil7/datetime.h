//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (C) 1992-2000 Microsoft Corporation
// All rights reserved.
//
// This code was originally ported from the Microsoft Foundation Class Library.
//
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __DATETIME_H__
#define __DATETIME_H__
#ifndef _INC_TIME
#include <time.h>
#endif

#define VX_OLE_DATETIME_ERROR (-1)

class CVsFile;

//---------------------------------------------------------------------------
class CVxOleDateTime
{
// Constructors
public:
    static CVxOleDateTime PASCAL GetCurrentTime();

    CVxOleDateTime();

    CVxOleDateTime(const CVxOleDateTime& dateSrc);
    CVxOleDateTime(const VARIANT& varSrc);
    CVxOleDateTime(DATE dtSrc);

    CVxOleDateTime(time_t timeSrc);
    CVxOleDateTime(const SYSTEMTIME& systimeSrc);
    CVxOleDateTime(const FILETIME& filetimeSrc);

    CVxOleDateTime(int nYear, int nMonth, int nDay,
        int nHour, int nMin, int nSec);
    CVxOleDateTime(WORD wDosDate, WORD wDosTime);

// Attributes
public:
    enum DateTimeStatus
    {
        valid = 0,
        invalid = 1,    // Invalid date (out of range, etc.)
        null = 2,       // Literally has no value
    };

    DATE m_dt;
    DateTimeStatus m_status;

    void SetStatus(DateTimeStatus status);
    DateTimeStatus GetStatus() const;

    int GetYear() const;
    int GetMonth() const;       // month of year (1 = Jan)
    int GetDay() const;         // day of month (0-31)
    int GetHour() const;        // hour in day (0-23)
    int GetMinute() const;      // minute in hour (0-59)
    int GetSecond() const;      // second in minute (0-59)
    int GetDayOfWeek() const;   // 1=Sun, 2=Mon, ..., 7=Sat
    int GetDayOfYear() const;   // days since start of year, Jan 1 = 1

// Operations
public:
    const CVxOleDateTime& operator=(const CVxOleDateTime& dateSrc);
    const CVxOleDateTime& operator=(DATE dtSrc);

    const CVxOleDateTime& operator=(const time_t& timeSrc);
    const CVxOleDateTime& operator=(const SYSTEMTIME& systimeSrc);
    const CVxOleDateTime& operator=(const FILETIME& filetimeSrc);

    BOOL operator==(const CVxOleDateTime& date) const;
    BOOL operator!=(const CVxOleDateTime& date) const;
    BOOL operator<(const CVxOleDateTime& date) const;
    BOOL operator>(const CVxOleDateTime& date) const;
    BOOL operator<=(const CVxOleDateTime& date) const;
    BOOL operator>=(const CVxOleDateTime& date) const;

    operator DATE() const;
    
    // return FALSE on failure, use GetLastError() for failure reason
    BOOL Serialize(CVsFile& file, BOOL bWrite);

    int SetDateTime(int nYear, int nMonth, int nDay,
        int nHour, int nMin, int nSec);
    int SetDate(int nYear, int nMonth, int nDay);
    int SetTime(int nHour, int nMin, int nSec);
    BOOL ParseDateTime(LPCTSTR lpszDate, DWORD dwFlags = 0,
        LCID lcid = LANG_USER_DEFAULT);

    // formatting
    CString Format(DWORD dwFlags = 0, LCID lcid = LANG_USER_DEFAULT) const;
    CString Format(LPCTSTR lpszFormat) const;
    CString Format(UINT nFormatID) const;

// Implementation
protected:
    void CheckRange();
};

//---------------------------------------------------------------------------
// Inline functions
//---------------------------------------------------------------------------
inline CVxOleDateTime::CVxOleDateTime()
    { m_dt = 0; SetStatus(valid); }
inline CVxOleDateTime::CVxOleDateTime(const CVxOleDateTime& dateSrc)
    { m_dt = dateSrc.m_dt; m_status = dateSrc.m_status; }
inline CVxOleDateTime::CVxOleDateTime(const VARIANT& varSrc)
    { SetStatus(invalid); if (VT_DATE==varSrc.vt) {*this = varSrc.date;} }
inline CVxOleDateTime::CVxOleDateTime(DATE dtSrc)
    { m_dt = dtSrc; SetStatus(valid); }
inline CVxOleDateTime::CVxOleDateTime(time_t timeSrc)
    { *this = timeSrc; }
inline CVxOleDateTime::CVxOleDateTime(const SYSTEMTIME& systimeSrc)
    { *this = systimeSrc; }
inline CVxOleDateTime::CVxOleDateTime(const FILETIME& filetimeSrc)
    { *this = filetimeSrc; }
inline CVxOleDateTime::CVxOleDateTime(int nYear, int nMonth, int nDay,
    int nHour, int nMin, int nSec)
    { SetDateTime(nYear, nMonth, nDay, nHour, nMin, nSec); }
inline CVxOleDateTime::CVxOleDateTime(WORD wDosDate, WORD wDosTime)
    { m_status = DosDateTimeToVariantTime(wDosDate, wDosTime, &m_dt) ?
        valid : invalid; }
inline const CVxOleDateTime& CVxOleDateTime::operator=(const CVxOleDateTime& dateSrc)
    { m_dt = dateSrc.m_dt; m_status = dateSrc.m_status; return *this; }
inline CVxOleDateTime::DateTimeStatus CVxOleDateTime::GetStatus() const
    { return m_status; }
inline void CVxOleDateTime::SetStatus(DateTimeStatus status)
    { m_status = status; }
inline BOOL CVxOleDateTime::operator==(const CVxOleDateTime& date) const
    { return (m_status == date.m_status && m_dt == date.m_dt); }
inline BOOL CVxOleDateTime::operator!=(const CVxOleDateTime& date) const
    { return (m_status != date.m_status || m_dt != date.m_dt); }
inline CVxOleDateTime::operator DATE() const
    { return m_dt; }
inline int CVxOleDateTime::SetDate(int nYear, int nMonth, int nDay)
    { return SetDateTime(nYear, nMonth, nDay, 0, 0, 0); }
inline int CVxOleDateTime::SetTime(int nHour, int nMin, int nSec)
    // Set date to zero date - 12/30/1899
    { return SetDateTime(1899, 12, 30, nHour, nMin, nSec); }

#endif


