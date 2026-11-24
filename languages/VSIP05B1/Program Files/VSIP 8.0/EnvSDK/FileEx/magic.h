
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// Magic.cpp
//
// Declaration of CMagicDisplay and CMagicDialog
//
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CMagicDisplay
//*****************************************************************************

class ATL_NO_VTABLE CMagicDisplay :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IMagicDisplay
{
// Constructor/Destructor
public:
    CMagicDisplay();
    ~CMagicDisplay();

// COM Interface Map
BEGIN_COM_MAP(CMagicDisplay)
    COM_INTERFACE_ENTRY(IMagicDisplay)
END_COM_MAP()

public:
// IMagicDisplay
    STDMETHOD(ShowMagic)(
                    /*[in]*/ LPCOLESTR lpszMagicURL,
                    /*[in]*/ LPCOLESTR lpszTitle,
                    /*[in]*/ long      cx,
                    /*[in]*/ long      cy);
};


//*****************************************************************************
// CMagicDialog
//*****************************************************************************

class CMagicDialog :
    public CVsDialogImpl<CMagicDialog>
{
// Constructor/Destructor
public:
    CMagicDialog();
    ~CMagicDialog();

    enum { IDD = IDD_MAGIC };

// Message Map
BEGIN_MSG_MAP(CMagicDialog)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    MESSAGE_HANDLER(WM_CLOSE, OnCloseDialog)
END_MSG_MAP()

// Message Handlers
public:
    // Prototypes:
    // LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    // LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    // LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnCloseDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

// Implementation
protected:

// Attributes
public:
    LPCOLESTR m_lpszURL;
    LPCOLESTR m_lpszCaption;
    long m_cx, m_cy;

protected:
    CComObject<CTridentHost>* m_pTridentHost;
    CComPtr<IUnknown> m_srpUnkTridentHost;
};
