
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// MyCProjPropPageImpl.h :

#pragma once

// forward references 
class CFileVwBaseNode;
class CFileVwProjNode;

/********************************************************************************************
* Per configuration project settings PropertyPage support
********************************************************************************************/

template <typename T> 
class ATL_NO_VTABLE IMyCPrjPropertyPageImpl : public IVsPropertyPageImpl<T>
{
public:
    IMyCPrjPropertyPageImpl() : m_bInitWasCalled(FALSE)
    {
        ENVSDK_TRACE(atlTraceControls, TLC, 
            _T("MyCPrj: IVsPropertyPageImpl<T>::IMyCPrjPropertyPageImpl at 0x%x \n"), 
            this );
    }

    ~IMyCPrjPropertyPageImpl() 
    {
        ENVSDK_TRACE(atlTraceControls, TLD, 
            _T("MyCPrj: IVsPropertyPageImpl<T>::IMyCPrjPropertyPageImpl at 0x%x \n"), 
            this );
        
        // clean the interafce pointers
        T* pT = static_cast<T*>(this);
        if (pT->m_ppIMyCProjCfgProps != NULL)
            for (UINT i = 0; i < m_nObjects; i++)
                if (pT->m_ppIMyCProjCfgProps[i] != NULL)
                    pT->m_ppIMyCProjCfgProps[i]->Release();

        delete[] pT->m_ppIMyCProjCfgProps;
        
    }

BEGIN_MSG_MAP(IMyCPrjPropertyPageImpl)
    CHAIN_MSG_MAP(IVsPropertyPageImpl<T>)
END_MSG_MAP()

  LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        ENVSDK_TRACE(atlTraceControls, TLF, _T("MyCPrj: IVsPropertyPageImpl<T>::OnInitDialog \n") );
        m_bInitWasCalled = TRUE;
        InitDialogValues();
        return 1;
    }

    STDMETHOD(Help)(LPCOLESTR pszHelpDir)
    {   
        // show context help
        ENVSDK_TRACE(atlTraceControls, TLF, _T("MyCPrj: IVsPropertyPageImpl<T>::Help \n") );
        return E_NOTIMPL;
    }

    // Because of a bug in atl, this is reproduced here with the fix
    void SetDirty(BOOL bDirty)
    {
        ENVSDK_TRACE(atlTraceControls, TLF, _T("MyCPrj: IVsPropertyPageImpl<T>::SetDirty \n") );
        if (m_bDirty != bDirty)
        {
            m_bDirty = bDirty;
            if (m_pPageSite != NULL)
                m_pPageSite->OnStatusChange(PROPPAGESTATUS_DIRTY | PROPPAGESTATUS_VALIDATE);
        }
    }

    // Overridden to handle selection changes.
    STDMETHOD(SetObjects)(ULONG nObjects, IUnknown **ppUnk)
    {
        ENVSDK_TRACE(atlTraceControls, TLF, 
            _T("MyCPrj: IVsPropertyPageImpl<T>::SetObjects \n") );

        if (!ppUnk)     
            return E_POINTER; 

        T* pT = static_cast<T*>(this);       
        // save the number of previous objects 
        UINT nPrevObject = pT->m_nObjects; 

        // call the standart implementation
        HRESULT hr = IVsPropertyPageImpl<T>::SetObjects(nObjects, ppUnk);
        if (FAILED(hr)) 
            return hr;

        // set my interface pointers
        if (pT->m_ppIMyCProjCfgProps != NULL && nPrevObject > 0)
        {
            for (UINT iObj = 0; iObj < nPrevObject; iObj++)
                if (pT->m_ppIMyCProjCfgProps[iObj])
                    pT->m_ppIMyCProjCfgProps[iObj]->Release();
            delete [] pT->m_ppIMyCProjCfgProps;
        }

        pT->m_ppIMyCProjCfgProps = NULL;
        pT->m_ppIMyCProjCfgProps = new IMyCProjCfgProps*[nObjects];
        if (pT->m_ppIMyCProjCfgProps == NULL) 
            return E_OUTOFMEMORY;

        memset(pT->m_ppIMyCProjCfgProps, 0, sizeof(IMyCProjCfgProps*) * nObjects);
        for (UINT i = 0; i < nObjects; i++)
        {
            ExpectedExprRet(pT->m_ppUnk[i] != NULL);
            hr = pT->m_ppUnk[i]->QueryInterface(IID_IMyCProjCfgProps, 
                                                (void**)&pT->m_ppIMyCProjCfgProps[i]);
            if (FAILED(hr))
                return hr;
        }

        hr = InitMultipleProjectsSelected();

        if ((hr == S_OK) && m_bInitWasCalled && nObjects)
            InitDialogValues();
        return hr;
    }

protected:
    void InitDialogValues()
    {
        ENVSDK_TRACE(atlTraceControls, TLF, 
            _T("MyCPrj: IVsPropertyPageImpl<T>::InitDialogValues \n") );
        
        InitValues();
    }

    // Override to initialize your dll's values
    virtual void InitValues(){};

    HRESULT InitMultipleProjectsSelected() 
    {
        HRESULT hr = S_OK;

        m_fMultipleProjectsSelected = TRUE;
        m_pfvpn = NULL;

        CFileVwProjNode * pProjectOld = NULL;

        for (UINT i = 0; i < m_nObjects; i++)
        {
            // get the project cfg 
            CComPtr<CMyProjectCfg> srpCMyProjectCfg;
            ExpectedExprRet(m_ppUnk[i] != NULL);
            hr = m_ppUnk[i]->QueryInterface(IID_CMyProjectCfg, 
                                            (LPVOID*) &srpCMyProjectCfg);
            IfFailRet(hr);
        
            // get the project node
            CFileVwProjNode* pProject;
            ExpectedExprRet(srpCMyProjectCfg != NULL && srpCMyProjectCfg->GetHierarchy() != NULL);
            pProject = srpCMyProjectCfg->GetHierarchy()->GetProjectNode(); //unaddref-ed
        
            if (!pProject)
                return E_FAIL;

            if (pProjectOld == NULL)
            {
                pProjectOld = pProject;
                continue;
            }
        
            if (pProjectOld != pProject)
                return S_OK;
        }

        // single project selected
        m_fMultipleProjectsSelected = FALSE;
        m_pfvpn = pProjectOld;
        return S_OK;
    }

    HRESULT GetPropertyIntersection(
                    DISPID dispid, 
                    VARIANT* pvarIntersected, 
                    BOOL* pbIndet)
    {
        ExpectedPtrRet(pbIndet);
        ExpectedPtrRet(pvarIntersected);
        CComVariant cvarCur, cvarPrev;
        HRESULT hr = S_OK;

        *pbIndet = FALSE;
        VariantClear(pvarIntersected);
    
        for (UINT i = 0; i < m_nObjects; i++)
        {
            CComDispatchDriver ccddDispatch = m_ppIMyCProjCfgProps[i];
            cvarCur.Clear();
            hr = ccddDispatch.GetProperty(dispid, &cvarCur);
            if (FAILED(hr))
            {
                ASSERT(FALSE);
                break;
            }

            if (i != 0 && cvarCur != cvarPrev)
            {
                *pbIndet = TRUE;
                break;
            }
            cvarPrev = cvarCur;
        }

        if (FAILED(hr))
            *pbIndet = TRUE;

        if (!*pbIndet)
            hr = cvarPrev.Detach(pvarIntersected);
 
        return hr;
    }

    // This function intersects an already populated combobox "hComboBox" 
    // for enumeration property "dispid". If intersection is indeterminate,
    // clears the edit box.  
    // Otherwise, displays the string indicated by the intersected value.
    HRESULT IntersectComboBox(HWND hComboBox, DISPID dispid)
    {
        HRESULT hr = S_OK;
        CComVariant cvar;
        BOOL bIndeterminate;
        CString str;

        // Obtain the intersection
        hr = GetPropertyIntersection(dispid, &cvar, &bIndeterminate);
        IfFailGo(hr);

        if (! bIndeterminate)
            str = CString(cvar);

        if (str.IsEmpty())
			::SendMessage((hComboBox), CB_SETCURSEL, (WPARAM)(int)(-1), 0L);
        else
			::SendMessage((hComboBox), CB_SELECTSTRING, (WPARAM)(int)(-1), (LPARAM)(LPCTSTR)(str));
    Error:
        return hr;
    }

    void SetEditControlFromVariant(HWND hwndCtl, VARIANT* pvar)
    {
        ExpectedPtrRet(pvar);
        CString strVal(*pvar);
		SetWindowText(hwndCtl, strVal);
    }

    HRESULT ComboBoxGetText
    (
        /* [in] */      HWND     hwnd,      // control handle
        /* [in, out] */ CString& str        // text
    )
    {
        ENVSDK_TRACE(atlTraceControls, TLF, _T("MyCPrj: IMyCPrjPropertyPageImpl<T>::ComboBoxGetText \n") );

        // get the selection
        LRESULT iSelection = SendMessage(hwnd, CB_GETCURSEL, 0, 0);

        if (iSelection == CB_ERR)
        {
            str.Empty();
            return S_OK;
        }

        str.Empty();
        //get the length of the string
        int cChars = (int)SendMessage(hwnd, CB_GETLBTEXTLEN, iSelection, 0);
        if ((cChars == CB_ERR) || (cChars == 0))
            return S_OK;

        // get the string
        LPTSTR psz = new TCHAR[cChars + 1];
        if (!psz) return E_OUTOFMEMORY;
        psz[0] = '\0';
        SendMessage(hwnd, CB_GETLBTEXT, (WPARAM)iSelection, (LPARAM)psz);
        str = psz;
        delete[] psz;
        str.TrimLeft();
        str.TrimRight();

        return S_OK;
    }

    HRESULT SetPropertyFromCombo(
               IDispatch* pTbl, 
               HWND hwndCtl, 
               DISPID dispid)
    {
        ExpectedPtrRet(pTbl);
        HRESULT hr = S_OK;
        CComVariant cvar;
        CString strComboBox;

        hr = ComboBoxGetText(hwndCtl, strComboBox); 
        IfFailRet(hr);

        cvar = strComboBox; 

        // Attempt the put
        hr = PutVariant(pTbl, dispid, &cvar);
        return hr;
    }

    HRESULT PutVariant(IDispatch* pTbl, DISPID dispid, VARIANT* pvar)
    {
        ExpectedPtrRet(pTbl);
        CComDispatchDriver ccddDispatch(pTbl);
        return ccddDispatch.PutProperty(dispid, pvar);
    }

    HRESULT SetPropertyFromEditControl(
                 IDispatch* pTbl, 
                 HWND hwndCtl, 
                 DISPID dispid)
    {
        ExpectedPtrRet(pTbl);
        HRESULT hr = S_OK;
        CComVariant cvar;
        CString str;

        int cChars = ::GetWindowTextLength(hwndCtl) + 1 ;

        // get the string
        LPTSTR psz = new TCHAR[cChars + 1];
        if (!psz) return E_OUTOFMEMORY;
        psz[0] = '\0'
        ::GetWindowText(hwndCtl, psz, cChars);
        str = psz;
        delete[] psz;
        str.TrimLeft();
        str.TrimRight();

        cvar = str;
        hr = PutVariant(pTbl, dispid, &cvar);
        return hr;
    }

    
    HRESULT BrowseForFolder
    (
        UINT        uTitleID,        // resource ID of the title
        HWND        hwndOwner,      // owner
        int&        iRet,           // IDOK, IDCANCEL
        CString&    strPath         // chosen path 
    )
    {
        ENVSDK_TRACE(atlTraceControls, TLF, _T("MyCPrj: IMyCPrjPropertyPageImpl<T>::BrowseForFolder \n") );

        HRESULT          hr;
        CString          strTitle;                  // info displayed in the dialog box
        TCHAR            szPath[_MAX_PATH + 1];
        VSBROWSEINFOW    vsbi;

        // load the title
        strTitle.LoadString(uTitleID);

        ZeroMemory(&vsbi, sizeof(VSBROWSEINFOW));
        vsbi.lStructSize = sizeof(VSBROWSEINFOW);
        vsbi.hwndOwner = hwndOwner;
        vsbi.pwzDlgTitle = strTitle;
        vsbi.pwzDirName = szPath;
        vsbi.nMaxDirName = MAX_PATH;
        vsbi.pwzInitialDir = NULL;
        vsbi.dwHelpTopic = 0;
        vsbi.dwFlags = BIF_RETURNONLYFSDIRS;

        CComPtr<IVsUIShell> srpUIShell;
        hr = _VxModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpUIShell);
        IfFailRet(hr); ExpectedExprRet(srpUIShell != NULL);

        if (SUCCEEDED(hr = srpUIShell->GetDirectoryViaBrowseDlg(&vsbi)))
        {
            if (szPath[0] == '\0')
            {
                iRet = IDCANCEL;
                hr = S_OK;
            }
            else
            {
                strPath=szPath;
                iRet = IDOK;
                hr = S_OK;
            }
        }
        return hr;
    }

protected:

    BOOL m_bInitWasCalled;
    IMyCProjCfgProps** m_ppIMyCProjCfgProps;
    BOOL m_fMultipleProjectsSelected;
    
    // Pointer to the project node when one project is selected
    // or NULL if multiple projects are selected
    CFileVwProjNode * m_pfvpn;

};
