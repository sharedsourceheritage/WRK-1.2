//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1997 - 2000 Microsoft Corporation. All Rights Reserved.
//
// statbar.h : status bar wrapper classes.
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __STATBAR_H__
#define __STATBAR_H__

// ----------------------------------------------------------------------------
// Utility class to save current status message, and restore previous one
// when done. Constructor displays the message. Destructor clears msg. If
// nAnimationIndex is != -1, then it also plays the indicated animation.
// ----------------------------------------------------------------------------
class CStatusBarMsg
{
public:
    CStatusBarMsg(UINT idMsg, int nAnimationIndex = -1);
    CStatusBarMsg(LPCTSTR pszMsg, int nAnimationIndex = -1);
    CStatusBarMsg(UINT idMsg, LPCTSTR strParameter, int nAnimationIndex = -1);
    void SetText(UINT idMsg);
    void SetText(LPCTSTR pszMsg);
    void SetText(UINT idMsg, LPCTSTR strParameter);

    ~CStatusBarMsg();
protected:
    int                   m_idAnimationIndex;
    void                  FinishConstruct(LPCTSTR pszMsg);
};

// ----------------------------------------------------------------------------
// Utility class to manage a progress indicator on the status bar.
// ----------------------------------------------------------------------------
class CStatusBarProgress
{
public:
            CStatusBarProgress(LPCTSTR pszLabel = NULL, int nProgress = 0, int nTotal =100);
            ~CStatusBarProgress();
    void    SetLabel(LPCTSTR pszLabel);
    void    SetProgress(int nCurProgress);
    void    SetAll(LPCTSTR pszLabel, int nCurProgress, int nTotal);
protected:
    int                   m_nProgress;
    int                   m_nTotal;
    CString               m_strLabel;
    VSCOOKIE              m_dwCookie;
};

// ----------------------------------------------------------------------------
// Utility class play the indicated animation. If bIsBitamp is FALSE, then idAnimation
// refers to one of the shells built in animation icons, otherwise it is the
// resource id of the bitmap animation strip.
// ----------------------------------------------------------------------------
class CStatusBarAnimation
{
public:
    CStatusBarAnimation(int idAnimation, BOOL bIsBitmap = FALSE);
    ~CStatusBarAnimation();
protected:
    int     m_idAnimation;
    HBITMAP m_hBitmap;
};

#endif 
