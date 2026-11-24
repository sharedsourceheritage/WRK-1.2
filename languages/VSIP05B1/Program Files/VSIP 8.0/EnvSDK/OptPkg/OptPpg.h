
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// OptPpg.h
//

#pragma once

///////////////////////////////////////////////////////////////////////////////
// COptionsPpg

class COptionsPpg
{
// Constructor
public:
    COptionsPpg();

// Operations
public:
    static HRESULT GetPage(
        /* [in]  */ _OptionsPreferences* pOptionsPreferences,
        /* [out] */ VSPROPSHEETPAGE*     pPage);

    static INT_PTR CALLBACK DialogProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
    static UINT CALLBACK PageProc(HWND hWnd, UINT Message, PROPSHEETPAGEA *ppage);

    HWND GetPageHandle() const { return m_hwndPage; }
    void SetPageHandle(HWND hwndPage)
    {
        _ASSERTE(!m_hwndPage);
        m_hwndPage = hwndPage;
    }

// Implementation
protected:
    void LoadSettings();
    BOOL SaveSettings();
    BOOL ValidateSettings();
    BOOL OnNotify(WPARAM wIDCtrl, NMHDR* pNotifyInfo);

// Attributes
protected:
    HWND m_hwndPage;
    static CComPtr<_OptionsPreferences> ms_srpOptionsPreferences;
};

