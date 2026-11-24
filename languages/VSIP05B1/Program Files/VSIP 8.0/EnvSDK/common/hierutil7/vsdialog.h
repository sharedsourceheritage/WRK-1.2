//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1997 - 2000 Microsoft Corporation. All Rights Reserved.
//
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#include <atlwin.h>
#include <atlctl.h>
#include <uilocale.h>
#include "helpsys.h"
#include <vshelp.h>
//---------------------------------------------------------------------------
// Generic Message box. Comparable to ::MessageBox
//---------------------------------------------------------------------------

int UtilMessageBox(LPCTSTR pszText,
                   UINT nType = MB_OK|MB_ICONEXCLAMATION,
                   LPCTSTR pszCaption = NULL);

int UtilMessageBox(UINT nIDPrompt,
                   UINT nType = MB_OK|MB_ICONEXCLAMATION,
                   LPCTSTR pszCaption = NULL);

//---------------------------------------------------------------------------
// Load and munge a dialog template
//---------------------------------------------------------------------------
HRESULT LoadMungedDlgTemplate(int iResID, DLGTEMPLATE **ppMungedDlgTemplate,
                              HINSTANCE hResInst = _AtlBaseModule.GetResourceInstance());

//---------------------------------------------------------------------------
// Class: CVsModalState
//      Manage Modal State
//---------------------------------------------------------------------------
class CVsModalState 
{
public:
             CVsModalState(BOOL bDisableDlgOwnerHwnd = FALSE);
    virtual ~CVsModalState(void);

    HWND GetDialogOwnerHwnd()
    {
        return m_hwnd;
    }

protected:
    HRESULT EnableModeless(BOOL fEnable);
    HWND    m_hwnd;          // owner window
    BOOL    m_bDisabledHwnd; // TRUE if we disabled m_hwnd;
};

//---------------------------------------------------------------------------
// Class: CVsBaseDialogImpl
//---------------------------------------------------------------------------
template <class T>
class ATL_NO_VTABLE CVsBaseDialogImpl : public CDialogImpl<T>
{
public:
    CVsBaseDialogImpl(void) : CDialogImpl<T>()
    {
    }

    INT DoModal(HWND hWnd = NULL)
    {
        ASSERT(m_hWnd == NULL);

#ifdef _DEBUG
        // Required for ATL 3.0
        m_bModal = true;
#endif //_DEBUG
        // Go modal
        CVsModalState modalstate;
        
        // Use IUIHostLocale to munge dialog template for us.
        DLGTEMPLATE* pMungedDlgTempl = NULL;
        int nRet;
        if(LoadMungedDlgTemplate(T::IDD, &pMungedDlgTempl) == S_OK)
        {
            ASSERT(pMungedDlgTempl);
            _AtlWinModule.AddCreateWndData(&m_thunk.cd, (CDialogImplBase*)this);
            // ASSERT DialogBoxIndirectParam is going to return a 32bit quantity
            nRet = (LONG32) ::DialogBoxIndirectParam(_AtlBaseModule.GetResourceInstance(),
                                pMungedDlgTempl, (hWnd ? hWnd : modalstate.GetDialogOwnerHwnd()),
                                (DLGPROC)T::StartDialogProc, NULL);
            m_hWnd = NULL;
            // Free the munged template
            ::CoTaskMemFree(pMungedDlgTempl);
        }
        else
        {
            // If anytyhing goes wrong, we just use standard ATL implementation
            ASSERT(FALSE);
            // ASSERT DoModal is going to return a 32bit quantity
            nRet = (LONG32) CDialogImpl<T>::DoModal((hWnd ? hWnd : modalstate.GetDialogOwnerHwnd()));
        }
        return nRet;
    }

    HWND Create(HWND hWndParent)
    {
        ASSERT(m_hWnd == NULL);
#ifdef _DEBUG
        // Required for ATL 3.0
        m_bModal = false;
#endif //_DEBUG

        // Use IUIHostLocale to munge dialog template for us.
        DLGTEMPLATE* pMungedDlgTempl = NULL;
        HWND hWnd = NULL;
        if(LoadMungedDlgTemplate(T::IDD, &pMungedDlgTempl) == S_OK)
        {
            ASSERT(pMungedDlgTempl);
            _AtlWinModule.AddCreateWndData(&m_thunk.cd, (CDialogImplBase*)this);
            hWnd = ::CreateDialogIndirectParam(_AtlBaseModule.GetResourceInstance(),
                                pMungedDlgTempl, hWndParent,
                                (DLGPROC)T::StartDialogProc, NULL);
            ASSERT(m_hWnd == hWnd);

            // Free the munged template
            ::CoTaskMemFree(pMungedDlgTempl);
        }
        else
        {
            // If anytyhing goes wrong, we just use standard ATL implementation

            #ifdef HTMED_PACKAGE
            ASSERT(FALSE);
            #endif
            hWnd = CDialogImpl<T>::Create(hWndParent);
        }
        return hWnd;
    }
};

//---------------------------------------------------------------------------
// Class: CVsDialogImpl
//---------------------------------------------------------------------------
template <class T>
class ATL_NO_VTABLE CVsDialogImpl : public CVsBaseDialogImpl<T>
{
public:
        CVsDialogImpl(DWORD dwHelpContext=0) : m_dwHelpContext(dwHelpContext){}

BEGIN_MSG_MAP(CVsDialogImpl)
    MESSAGE_HANDLER(WM_HELP, OnHelp)
    COMMAND_ID_HANDLER(IDHELP, OnHelp) 
END_MSG_MAP()

    LRESULT OnHelp(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        BOOL fRet;

        return OnHelp((WORD)0, WORD(0), HWND(0), fRet);
    }

    // Invoke the shell's help function
    LRESULT OnHelp(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
    {
        USES_CONVERSION;

        if(!m_strF1Keyword.IsEmpty())
        {   // Use the new help system
            CComPtr<IVsHelp> srpIVsHelp;
            if(SUCCEEDED(_VxModule.QueryService(SID_SVsHelp, IID_IVsHelp, (void**) &srpIVsHelp)))
            {
                CComBSTR bstrF1Keyword = m_strF1Keyword;
                srpIVsHelp->DisplayTopicFromF1Keyword(bstrF1Keyword);
            }
        }
        else if(m_dwHelpContext >= 0)
        {
            if(m_strHelpFile.IsEmpty())
                _VxModule.DisplayHelpTopic(m_dwHelpContext, VHS_Localize | VHS_Default);
            else
            {   // Overridden help file
                IVsHelpSystem *pIVsHelpSystem = _VxModule.GetIVsHelpSystem();
                if(NULL != pIVsHelpSystem)
                {
                    pIVsHelpSystem->DisplayTopicFromIdentifier(T2COLE(m_strHelpFile), m_dwHelpContext, VHS_Localize | VHS_Default);
                }
            }
        }
        return 0;
    }

protected:
    DWORD   m_dwHelpContext;
    CString m_strHelpFile;      // Only set if you want to override the one in _VxModule.
    CString m_strF1Keyword;     // VS7 dialogs should set this value for their F1/help button keyword
};


//---------------------------------------------------------------------------
// Class: IVsPropertyPageImpImpl
// Override the methods of IPopertyPageImpl which require dialog template
// munging. Taken from the ATL implementation.
// WARNING - THIS MUST STAY IN SYNC WITH CHANGE TO ATL'S IMPLEMENTATION
//---------------------------------------------------------------------------
template <class T>
class ATL_NO_VTABLE IVsPropertyPageImpl : public IPropertyPageImpl<T>
{
public:
    IVsPropertyPageImpl(void) : IPropertyPageImpl<T>()
    {
    }

BEGIN_MSG_MAP(IVsPropertyPageImpl)
    CHAIN_MSG_MAP(IPropertyPageImpl<T>)
END_MSG_MAP()

    STDMETHOD(GetPageInfo)(PROPPAGEINFO *pPageInfo)
    {
        T* pT = static_cast<T*>(this);
        ATLTRACE(_T("IPropertyPageImpl::GetPageInfo\n"));

        if (pPageInfo == NULL)
        {
            ATLTRACE(_T("Error : PROPPAGEINFO passed == NULL\n"));
            return E_POINTER;
        }

        DLGTEMPLATE* pTemp = NULL;
        HRESULT hr = LoadMungedDlgTemplate(T::IDD, &pTemp);

        if (FAILED(hr) || NULL == pTemp)
        {   // If something goes wrong, dont quit, just use the ATL default.
            
            #ifdef HTMED_PACKAGE
            ASSERT(FALSE); 
            #endif
            return IPropertyPageImpl<T>::GetPageInfo(pPageInfo);
        }
        AtlGetDialogSize(pTemp, &m_size, true);

        pPageInfo->cb = sizeof(PROPPAGEINFO);
        pPageInfo->pszTitle = LoadStringHelper(pT->m_dwTitleID);
        pPageInfo->size = m_size;
        pPageInfo->pszHelpFile = LoadStringHelper(pT->m_dwHelpFileID);
        pPageInfo->pszDocString = LoadStringHelper(pT->m_dwDocStringID);
        pPageInfo->dwHelpContext = pT->m_dwHelpContext;
        CoTaskMemFree(pTemp);
        return S_OK;
    }

    // Only HTMUTIL needs this since their shell is ansi only!
#ifdef HTMUTIL_PACKAGE
    STDMETHOD(TranslateAccelerator)(MSG *pMsg)
    {
        T* pT = static_cast<T*>(this);
        ATLTRACE(_T("IPropertyPageImpl::TranslateAccelerator\n"));
        if ((pMsg->message < WM_KEYFIRST || pMsg->message > WM_KEYLAST) &&
            (pMsg->message < WM_MOUSEFIRST || pMsg->message > WM_MOUSELAST))
            return S_FALSE;

        return (IsDialogMessageA(pT->m_hWnd, pMsg)) ? S_OK : S_FALSE;
    }

#endif 

    STDMETHOD(Help)(LPCOLESTR pszHelpDir)
    {
        CComPtr<IVsHelpSystem> srpHelp;
        HRESULT hr = _VxModule.QueryService(SID_SHelpService, IID_IVsHelpSystem, (void **)&srpHelp);
        if (srpHelp != NULL)
        {
            LPOLESTR szHelpFile = LoadStringHelper(m_dwHelpFileID);
            CComBSTR bstrHelpFile(szHelpFile);
            CoTaskMemFree(szHelpFile);

            hr = srpHelp->DisplayTopicFromIdentifier(bstrHelpFile, m_dwHelpContext, VHS_Localize);
        }
        return 0;
    }
};

