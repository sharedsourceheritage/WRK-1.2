//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1997 - 2000 Microsoft Corporation. All Rights Reserved.
//
//---------------------------------------------------------------------------
#include "hu_pch.h"
#include "vsdialog.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-----------------------------------------------------------------------------
// Displays pszText in a message box.
//-----------------------------------------------------------------------------
int UtilMessageBox(LPCTSTR pszText, UINT nType, LPCTSTR pszCaption)
{
    ASSERT(pszText);
    CVsModalState modalstate;
    return ::MessageBox(modalstate.GetDialogOwnerHwnd(),
                    pszText, pszCaption, nType);
}

//-----------------------------------------------------------------------------
// Loads a resource string and displays
//-----------------------------------------------------------------------------
int UtilMessageBox(UINT nIDPrompt, UINT nType, LPCTSTR pszCaption)
{
    CString string;
    VERIFY(string.LoadString(nIDPrompt));
    return ::UtilMessageBox(string, nType, pszCaption);
}

//---------------------------------------------------------------------------
// Load and munge a dialog template
//---------------------------------------------------------------------------
HRESULT LoadMungedDlgTemplate(int iResID, DLGTEMPLATE **ppMungedDlgTemplate,
                              HINSTANCE hResInst)
{   // General function to return a munged template. Use IUIHostLocale to munge 
    // dialog template for us. Caller is responsible for freeing the returned dlg template
    // with CoTaskMemFree()
    ASSERT(hResInst);
    ASSERT(ppMungedDlgTemplate);
    CComPtr<IUIHostLocale2> srpUihl;
    HRESULT hr = _VxModule.QueryService(SID_SUIHostLocale, IID_IUIHostLocale2, (void**)&srpUihl);
    if(hr == S_OK)
    {   // Note that Win95/Winnt automatically frees resources so we don't do it here.
        HRSRC hRes = ::FindResource(hResInst, MAKEINTRESOURCE(iResID), RT_DIALOG);
        ASSERT(hRes);
        if(hRes)
        {   // Load it
            HGLOBAL hGlob = ::LoadResource(hResInst, hRes);
            ASSERT(hGlob);
            if(hGlob)
            {   // Lock the sucker
                DLGTEMPLATE* pDlgTempl = (DLGTEMPLATE*)::LockResource(hGlob);
                ASSERT(pDlgTempl);
                // Munge away!
                hr = srpUihl->MungeDialogFont(::SizeofResource(hResInst, hRes), 
                                (BYTE*)pDlgTempl, (BYTE**)ppMungedDlgTemplate);
            }
        }
    }
    return hr;
}

//-----------------------------------------------------------------------------
// CVsModalState::CVsModalState - set bDisableDlgOwnerHwnd to TRUE if you want
// to disable the window as well as doing the EnableModeless bit.
//-----------------------------------------------------------------------------
CVsModalState::CVsModalState(BOOL bDisableDlgOwnerHwnd /*=FALSE*/)
 : 
    m_hwnd(NULL),
    m_bDisabledHwnd(FALSE)
{
    // Need to get dialog owner hwnd prior to enabling modeless false
    _VxModule.GetVsUIShell()->GetDialogOwnerHwnd(&m_hwnd);
    if(m_hwnd == NULL)
    {
        ASSERT(FALSE);
        m_hwnd = ::GetActiveWindow();
    }
    VERIFY(SUCCEEDED(EnableModeless(FALSE)));
    if(bDisableDlgOwnerHwnd && ::IsWindowEnabled(m_hwnd))
    {
        ::EnableWindow(m_hwnd, FALSE);
        m_bDisabledHwnd = TRUE;
    }
}

//-----------------------------------------------------------------------------
// CVsModalState::~CVsModalState
//-----------------------------------------------------------------------------
CVsModalState::~CVsModalState()
{
    if(m_bDisabledHwnd)
        ::EnableWindow(m_hwnd, TRUE);
    VERIFY(SUCCEEDED(EnableModeless(TRUE)));
}

//-----------------------------------------------------------------------------
// CVsModalState::EnableModeless
//-----------------------------------------------------------------------------
HRESULT CVsModalState::EnableModeless(BOOL fEnable)
{
    HRESULT hr = _VxModule.GetVsUIShell()->EnableModeless(fEnable);
    return hr;
}

// End of vsdialog.cpp
