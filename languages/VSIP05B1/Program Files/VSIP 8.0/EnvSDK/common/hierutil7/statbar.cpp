//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1997 - 2000 Microsoft Corporation. All Rights Reserved.
//
// statbar.h : status bar wrapper classes.
//---------------------------------------------------------------------------
#include "hu_pch.h"
#include "statbar.h"
#include "mfcmisc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//----------------------------------------------------------------------------
// Construct and set resource messsage with ID
//----------------------------------------------------------------------------
CStatusBarMsg::CStatusBarMsg(UINT idMsg, int idAnimationIndex /*=-1*/)
  :
    m_idAnimationIndex(idAnimationIndex)
{
    USES_CONVERSION;
    CString msg;
    msg.LoadString(idMsg);
    FinishConstruct(msg);
}
//----------------------------------------------------------------------------
// Construct and set resource messsage with ID and 1 string parameter
//----------------------------------------------------------------------------
CStatusBarMsg::CStatusBarMsg(UINT idMsg, LPCTSTR strParameter, 
                             int idAnimationIndex /*=-1*/)
  :
    m_idAnimationIndex(idAnimationIndex)
{
    CString msg;
    VxFormatString1(msg, idMsg, strParameter);
    FinishConstruct(msg);
}

//----------------------------------------------------------------------------
// Construct and set message
//----------------------------------------------------------------------------
CStatusBarMsg::CStatusBarMsg(LPCTSTR pszMsg, int idAnimationIndex /*=-1*/)
  :
    m_idAnimationIndex(idAnimationIndex)
{
    FinishConstruct(pszMsg);
}

//----------------------------------------------------------------------------
// Common constructor finisher
//----------------------------------------------------------------------------
void CStatusBarMsg::FinishConstruct(LPCTSTR pszMsg)
{
    USES_CONVERSION;
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
    {
        pStatBar->SetText(T2CW(pszMsg));
        if(m_idAnimationIndex != -1)
        {
            ASSERT(m_idAnimationIndex >= SBAI_MIN && m_idAnimationIndex <= SBAI_MAX);
            CComVariant var((short)m_idAnimationIndex);
            pStatBar->Animation(TRUE, &var);
        }
    }
}

//----------------------------------------------------------------------------
// Restore original message.
//----------------------------------------------------------------------------
CStatusBarMsg::~CStatusBarMsg()
{
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
    {
        pStatBar->SetText(L"");
        if(m_idAnimationIndex != -1)
        {   // Stop the animation
            CComVariant var((short)m_idAnimationIndex);
            pStatBar->Animation(FALSE, &var);
        }
    }
}

//----------------------------------------------------------------------------
// Set text
//----------------------------------------------------------------------------
void CStatusBarMsg::SetText(UINT idMsg)
{
    USES_CONVERSION;
    CString msg;
    msg.LoadString(idMsg);

    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
        pStatBar->SetText(T2CW(msg));
}
//----------------------------------------------------------------------------
// SetText
//----------------------------------------------------------------------------
void CStatusBarMsg::SetText(UINT idMsg, LPCTSTR strParameter)
{
    USES_CONVERSION;
    CString msg;
    VxFormatString1(msg, idMsg, strParameter);
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
        pStatBar->SetText(T2CW(msg));
}

//----------------------------------------------------------------------------
// Text setting methods
//----------------------------------------------------------------------------
void CStatusBarMsg::SetText(LPCTSTR pszMsg)
{
    USES_CONVERSION;
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
        pStatBar->SetText(T2CW(pszMsg));
}

//----------------------------------------------------------------------------
// Status bar progress indicator
//----------------------------------------------------------------------------
CStatusBarProgress::CStatusBarProgress(LPCTSTR pszLabel /*= NULL*/,
                           int nProgress /*=0*/, int nTotal /*=100*/)
  :
    m_strLabel(pszLabel),
    m_nProgress(nProgress),
    m_nTotal(nTotal),
    m_dwCookie(0)
{
}

//----------------------------------------------------------------------------
// Cleanup progress bar
//----------------------------------------------------------------------------
CStatusBarProgress::~CStatusBarProgress()
{
    USES_CONVERSION;
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
    {   // Stop progress bar
        pStatBar->Progress(&m_dwCookie, FALSE, T2CW(m_strLabel), m_nProgress, m_nTotal);
    }
}

//----------------------------------------------------------------------------
// Sets the label and updates progress bar using current progress values.
//----------------------------------------------------------------------------
void CStatusBarProgress::SetLabel(LPCTSTR pszLabel)
{
    USES_CONVERSION;
    m_strLabel = pszLabel;
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
    {   // Stop progress bar
        pStatBar->Progress(&m_dwCookie, TRUE, T2CW(m_strLabel), m_nProgress, m_nTotal);
    }
}

//----------------------------------------------------------------------------
// Updates the progress
//----------------------------------------------------------------------------
void CStatusBarProgress::SetProgress(int nCurProgress)
{
    USES_CONVERSION;
    ASSERT(nCurProgress <= m_nTotal);
    m_nProgress = nCurProgress;
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
    {   // Stop progress bar
        pStatBar->Progress(&m_dwCookie, TRUE, T2CW(m_strLabel), m_nProgress, m_nTotal);
    }
}
//----------------------------------------------------------------------------
// Updates the progress bar with new values.
//----------------------------------------------------------------------------
void CStatusBarProgress::SetAll(LPCTSTR pszLabel, int nCurProgress, int nTotal)
{
    USES_CONVERSION;
    m_nProgress = nCurProgress;
    m_nTotal = nTotal;
    m_strLabel = pszLabel;
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
    {   // Stop progress bar
        pStatBar->Progress(&m_dwCookie, TRUE, T2CW(m_strLabel), m_nProgress, m_nTotal);
    }
}


//----------------------------------------------------------------------------
// Status bar animation handler. Assumes bitmap resource id (if bIsBitmap is true)
// is in the module  instance (not the resource instance)
//----------------------------------------------------------------------------
CStatusBarAnimation::CStatusBarAnimation(int idAnimation, BOOL bIsBitmap /*= FALSE*/)
  :
    m_idAnimation(idAnimation),
    m_hBitmap(0)
{
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
    {
        if(bIsBitmap)
        {
            m_hBitmap = ::LoadBitmap(_AtlBaseModule.GetModuleInstance(), MAKEINTRESOURCE(idAnimation));
            ASSERT(m_hBitmap);
            if(m_hBitmap)
            {
#ifdef _WIN64
                CComVariant var((LPCOLESTR)m_hBitmap);
#else
                CComVariant var((long)m_hBitmap);
#endif
                pStatBar->Animation(TRUE, &var);
            }
        }
        else
        {
            ASSERT(m_idAnimation >= SBAI_MIN && m_idAnimation <= SBAI_MAX);
            CComVariant var((short)m_idAnimation);
            pStatBar->Animation(TRUE, &var);
        }
    }
}

//----------------------------------------------------------------------------
// Stops the animation.
//----------------------------------------------------------------------------
CStatusBarAnimation::~CStatusBarAnimation()
{
    IVsStatusbar* pStatBar = _VxModule.GetIVsStatusbar();
    if(pStatBar != NULL)
    {
        if(m_hBitmap)
        {
#ifdef _WIN64
            CComVariant var((LPCOLESTR)m_hBitmap);
#else
            CComVariant var((long)m_hBitmap);
#endif
            pStatBar->Animation(FALSE, &var);
        }
        else
        {
            CComVariant var((short)m_idAnimation);
            pStatBar->Animation(FALSE, &var);
        }
    }
}

// End of utilclss.cpp
