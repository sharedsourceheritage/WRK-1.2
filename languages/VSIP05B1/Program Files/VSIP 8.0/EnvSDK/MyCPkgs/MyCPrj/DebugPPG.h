
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

/********************************************************************************************
* DebugPPG.h
* Per configuration project settings PropertyPage support - Debug 
* The page ilustrates IVSMDPropertyGrid use.
********************************************************************************************/

#pragma once
 
/////////////////////////////////////////////////////////////////////////////
// CSettingsPage
template <
    const CLSID * Tpclsid,  // CLSID of the property page
    DWORD TTitleID,         // Title ID
    DWORD TGroupID,         // Group ID of Category Title
    class TCMyPropertyPage  // Property Page behind this settings page
>
class ATL_NO_VTABLE CSettingsPage :
    public IPropertyPageImpl<CSettingsPage>,
    public IVsPropertyPage,
    public IMyCSettingsPage,
    public CDialogImpl<CSettingsPage>,
    public CComObjectRoot,
    public CComCoClass<CSettingsPage, Tpclsid>
{

// =========================================================================
//                                                 construct, init, destruct
public:
    CSettingsPage()
    {
        m_dwTitleID = TTitleID;
        m_dwHelpFileID = NULL; // we do not have help 
        // pass dummy IDS_ to get the help method invoked
        m_bActive = FALSE;
        m_nLastObjects = 0;
        m_ppUnkArray = NULL;
    }

    ~CSettingsPage()
    {
        ReleaseObjects();
    }

protected:
    void ReleaseObjects()
    {
        if(m_ppUnkArray == NULL)
            return;

        UINT i;
        for (i = 0; i < m_nLastObjects; i++)
        {
            if( m_ppUnkArray[i] != NULL )
                m_ppUnkArray[i]->Release();
        }
        delete [] m_ppUnkArray;
        m_ppUnkArray = NULL;
        m_nLastObjects = 0;
    }
//                                                 construct, init, destruct
// =========================================================================

public:
    enum {IDD = IDDP_SETTINGSPAGE};

    DECLARE_NO_REGISTRY()
    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(CSettingsPage)
        COM_INTERFACE_ENTRY(IPropertyPage)
        COM_INTERFACE_ENTRY(IVsPropertyPage)
        COM_INTERFACE_ENTRY(IMyCSettingsPage)
    END_COM_MAP()

    BEGIN_MSG_MAP(CSettingsPage)
        CHAIN_MSG_MAP(IPropertyPageImpl<CSettingsPage>)
    END_MSG_MAP()

    // Handler prototypes:
    //  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    //  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    //  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);


// =========================================================================
//                                                             IPropertyPage
public:

    STDMETHOD(Activate)(HWND hWndParent, LPCRECT pRect, BOOL /* bModal */)
    {
        ENVSDK_TRACE(atlTraceControls,2,_T("IPropertyPageImpl::Activate\n"));

        if (pRect == NULL)
        {
            ENVSDK_TRACE(atlTraceControls,2,_T("Error : Passed a NULL rect\n"));
            return E_POINTER;
        }

        m_hWnd = Create(hWndParent);
        if (NULL == m_hWnd) return E_FAIL;

        if( m_nObjects == 0 )
            return S_OK;

        m_size.cx = pRect->right - pRect->left;
        m_size.cy = pRect->bottom - pRect->top;

        HRESULT hr = S_OK;
        if( m_pGrid == NULL )
        {
            CComPtr<IVSMDPropertyBrowser> srpIVSMDPropertyBrowser;
            hr = _VxModule.QueryService(
                SID_SVSMDPropertyBrowser, 
                __uuidof(IVSMDPropertyBrowser), 
                (void**)&srpIVSMDPropertyBrowser);

            // if we didn't get a prop browser, something is wrong
            IfFailRet(hr);
            ExpectedExprRet(srpIVSMDPropertyBrowser != NULL);

            hr = srpIVSMDPropertyBrowser->CreatePropertyGrid(&m_pGrid);
            IfFailRet(hr);
            ExpectedExprRet(m_pGrid != NULL);
        }
        
        m_bActive = TRUE;

        if( hr == S_OK )
        {
            HWND hwndGrid;
            HWND hwndGridPos;
            RECT rectGridPos;
            RECT rectGrid;
            hwndGridPos = ::GetDlgItem(m_hWnd, IDC_GRIDPOS);
            if (NULL == hwndGridPos) return HRESULT_FROM_WIN32(GetLastError());
            if (!::GetWindowRect(hwndGridPos, &rectGridPos)) return HRESULT_FROM_WIN32(GetLastError());
            
            rectGrid.top = 0;
            rectGrid.left = 0;
            rectGrid.bottom = rectGridPos.bottom - rectGridPos.top;
            rectGrid.right = rectGridPos.right - rectGridPos.left;
            
            hr = m_pGrid->get_Handle(&hwndGrid);
            IfFailRet(hr);
            CWindow wndGrid;
            wndGrid.Attach(hwndGrid);
            wndGrid.SetParent(m_hWnd);

            VARIANT vt;
            VariantInit(&vt);
            V_VT(&vt) = VT_BOOL;
            V_BOOL(&vt) = VARIANT_FALSE;

            hr = m_pGrid->SetOption(PGOPT_TOOLBAR, vt);
            IfFailRet(hr);
            // Set the sort order of props. you could want PGSORT_CATEGORIZED instead.
            hr = m_pGrid->put_GridSort(PGSORT_NOSORT);        
            IfFailRet(hr);
            if (!wndGrid.SetWindowPos( HWND_TOP, &rectGrid, SWP_FRAMECHANGED ))
                return HRESULT_FROM_WIN32(GetLastError());

            return UpdateObjects();
        }
        return S_OK;
    }
        
    STDMETHOD(Deactivate)(void)
    {
        HRESULT hr;
        ReleaseObjects();

        hr = IPropertyPageImpl<CSettingsPage>::Deactivate();
        m_bActive = FALSE;
        return hr;
    }
        
    STDMETHOD(SetObjects)(ULONG nObjects, IUnknown **ppUnk)
    {
        HRESULT hr;

        // call base-class implementation
        hr = IPropertyPageImpl<CSettingsPage>::SetObjects( nObjects, ppUnk );
        if( FAILED(hr) )
            return hr;

        // update the objects if we have ever been activated.
        if( m_bActive )
            hr = UpdateObjects();
            
        return hr;
    }
        
    STDMETHOD(Apply)(void)
    {
        HRESULT hr = S_OK;

        UINT i;
        for (i = 0; i < m_nObjects; i++)
        {
            if( m_ppUnkArray && (m_ppUnkArray[i] != NULL) )
            {
                CComQIPtr<IMyCPropertyContainer> pContainer = m_ppUnkArray[i];
                if( pContainer != NULL)
                {
                    hr = pContainer->Commit();
                    _IfFailRet(hr);
                }
            }
        }
        SetDirty(FALSE);
        if( m_pGrid )
            m_pGrid->Refresh();
        return S_OK;
    }
        
    STDMETHOD(Help)(LPCOLESTR pszHelpDir)
    {
        // show help here 
        // Use Help::DisplayTopicFromF1Keyword method to display help about the property page
        return E_NOTIMPL;
    }

    STDMETHOD(TranslateAccelerator)(MSG *pMsg)
    {
        ExpectedPtrRet(pMsg);
        if ((pMsg->message < WM_KEYFIRST || pMsg->message > WM_KEYLAST) &&
            (pMsg->message < WM_MOUSEFIRST || pMsg->message > WM_MOUSELAST))
            return S_FALSE;

        return (::IsDialogMessage(m_hWnd, pMsg)) ? S_OK : S_FALSE;
    }

protected:
    HRESULT UpdateObjects( void )
    {
        // Get Rid of the old list
        ReleaseObjects();

        // Make a new list
        m_ppUnkArray = new IUnknown*[ m_nObjects ];
        if (!m_ppUnkArray)
            return E_OUTOFMEMORY;
        memset(m_ppUnkArray, 0, sizeof(IUnknown*) * m_nObjects);
        m_nLastObjects = m_nObjects;

        for (UINT i = 0; i < m_nObjects; i++)
        {
            HRESULT hr;

            CComPtr<IMyCSettingsPage> pPage;
            QueryInterface(__uuidof(IMyCSettingsPage), (void**)&pPage);

            hr = TCMyPropertyPage::CreateInstance(pPage, m_ppUnk[i],  &m_ppUnkArray[i]);
            IfFailRet(hr);
        }

        if (m_pGrid)
        {
            HRESULT hr = m_pGrid->SetSelectedObjects(m_nObjects, m_ppUnkArray);
            IfFailRet(hr);
            hr = m_pGrid->Refresh();
            IfFailRet(hr);
        }

        return S_OK;
    }
//                                                             IPropertyPage
// =========================================================================


// =========================================================================
//                                                           IVsPropertyPage
public:

    //If your page doesn't have a category (i.e. you want it to show up on the top level
    //of the treeview) either just implement IPropertyPage, or return E_NOTIMPL
    //from this method.  Otherwise, the shell will first call you with an iLevel
    //of 0.  You return the name of the category that should be the closest direct
    //ancestor of this page in the tree.  Then the shell will call with iLevel
    //of 1.  If you want your page only indented one level, return S_FALSE.  
    //The shell will keep going with iLevel increasing by 1 each time
    //until you return something other than S_OK or you hit the
    //shell's internal limit of what it supports.
    //E_NOTIMPL and S_FALSE will stop processing without showing an
    //error to the user.  Any other non-S_OK return value may or may not cause 
    //error information to be shown the user.  
    //Currently the shell only supports 2 levels of categories, like this:
    //  CatLevel1
    //  --CatLevel0
    //  ----PageName
    STDMETHOD(get_CategoryTitle)(
        /* [in]          */ UINT iLevel,
        /* [out, retval] */ BSTR *pbstrCategory)
    {
        if( (iLevel == 0) && TGroupID )
        {
            ExpectedPtrRet(pbstrCategory);
            CComBSTR cbstrTitle;
            if (!cbstrTitle.LoadString(TGroupID)) return E_OUTOFMEMORY;
            *pbstrCategory = cbstrTitle.Detach();
            return S_OK;
        }
        return S_FALSE;
    }

//                                                           IVsPropertyPage
// =========================================================================


// =========================================================================
//                                                          IMyCSettingsPage
public:

    STDMETHOD(Dirty)(void)
    {
        SetDirty(TRUE);
        return S_OK;
    }
    STDMETHOD(Refresh)()
    {
        if( m_pGrid )
            return m_pGrid->Refresh();
        return S_OK;
    }
//                                                          IMyCSettingsPage
// =========================================================================

protected:
    BOOL         m_bActive;
    UINT         m_nLastObjects;
    IUnknown **    m_ppUnkArray; // array of pointers to the PropertyPageObject
    CComPtr<IVSMDPropertyGrid> m_pGrid;
};





class ATL_NO_VTABLE CMyCDebugPropPg :
    public IPerPropertyBrowsing,
    public IVsPerPropertyBrowsing,
    public IMyCPropertyContainer,
    public IDispatchImpl<IMyCDebugPropPage, &IID_IMyCDebugPropPage, &LIBID_MyCPrjPKGLib>,
    public CComObjectRoot
{
// =========================================================================
//                                                 construct, init, destruct
public:
    static HRESULT CreateInstance(
        /* [in]  */ IMyCSettingsPage *   pPage, 
        /* [in]  */ IUnknown *           pUnkParent,
        /* [out] */ IUnknown ** pIUnkPropPage);

protected:
    CMyCDebugPropPg();

    HRESULT Init(
        /* [in]  */ IMyCSettingsPage *   pPage, 
        /* [in]  */ IUnknown *           pUnkParent,
        /* [out] */ IUnknown **          pIUnkPropPage);

    ~CMyCDebugPropPg();
//                                                 construct, init, destruct
// =========================================================================

public:
    BEGIN_COM_MAP(CMyCDebugPropPg)
        COM_INTERFACE_ENTRY(IPerPropertyBrowsing)
        COM_INTERFACE_ENTRY(IVsPerPropertyBrowsing)
        COM_INTERFACE_ENTRY(IMyCPropertyContainer)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IMyCDebugPropPage)
    END_COM_MAP()


// =========================================================================
//                                                      IPerPropertyBrowsing
// Used to populate Debug Start Mode list box

public:
    STDMETHOD(GetDisplayString)(
        /* [in] */ DISPID dispID,
        /* [out] */ BSTR *pBstr);

    STDMETHOD(MapPropertyToPage)(
        /* [in]  */ DISPID dispID,
        /* [out] */ CLSID *pClsid);

    STDMETHOD(GetPredefinedStrings)( 
        /* [in]  */ DISPID          dispID,
        /* [out] */ CALPOLESTR *    pCaStringsOut,
        /* [out] */ CADWORD *       pCaCookiesOut);

    STDMETHOD(GetPredefinedValue)( 
        /* [in]  */ DISPID dispID,
        /* [in]  */ DWORD dwCookie,
        /* [out] */ VARIANT *pVarOut);
//                                                      IPerPropertyBrowsing
// =========================================================================

     
// =========================================================================
//                                                    IVsPerPropertyBrowsing
// To provide localized info displayed iin the property browser
public :
    STDMETHOD(HideProperty)(DISPID dispid, BOOL* pfHide);

    STDMETHOD(DisplayChildProperties)(DISPID dispid, BOOL* pfDisplay);

    STDMETHOD(GetLocalizedPropertyInfo)(
        DISPID dispid, 
        LCID localeID, 
        BSTR* pbstrLocalizedName, 
        BSTR* pbstrLocalizedDescription);

    STDMETHOD(HasDefaultValue)(DISPID dispid, BOOL* fDefault);

    STDMETHOD(IsPropertyReadOnly)(DISPID dispid, BOOL* pfReadOnly);
    
    STDMETHOD(GetClassName)(BSTR*);
    
    STDMETHOD(CanResetPropertyValue)(DISPID , BOOL* );
    
    STDMETHOD(ResetPropertyValue)(DISPID );
//                                                    IVsPerPropertyBrowsing
// =========================================================================


// =========================================================================
//                                                     IMyCPropertyContainer
public:
    STDMETHOD(Commit)();
//                                                     IMyCPropertyContainer
// =========================================================================


// =========================================================================
//                                                          IDispatch override
    STDMETHOD(Invoke)(DISPID dispid, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pdispParams, VARIANT *pvarResult, EXCEPINFO *pexcepInfo, UINT *puArgErr )
    {
        HRESULT hr = IDispatchImpl<IMyCDebugPropPage, &IID_IMyCDebugPropPage, &LIBID_MyCPrjPKGLib>::Invoke( dispid, riid, lcid, wFlags, pdispParams, pvarResult, pexcepInfo, puArgErr );
        if ( (dispid == MyCPrjPROJPROPID_DebugStartMode) && (wFlags & DISPATCH_PROPERTYPUT) )
            return S_OK;
        return hr;
    }
//                                                          IDispatch override
// =========================================================================


// =========================================================================
//                                                         IMyCDebugPropPage
public:
    STDMETHOD(get_DebugStartMode)(
        /* [out] */ MyCPrjDebugStartMode *pdebugStartMode);

    STDMETHOD(put_DebugStartMode)(
        /* [in]  */ MyCPrjDebugStartMode debugStartMode);

    STDMETHOD(get_StartApp)(
        /* [out] */ BSTR *pbstr);

    STDMETHOD(put_StartApp)(
        /* [in]  */ BSTR bstr);

    STDMETHOD(get_StartAppPath)(
        /* [out] */ BSTR *pbstr);

    STDMETHOD(put_StartAppPath)(
        /* [in]  */ BSTR bstr);

    STDMETHOD(get_CustomStartupArguments)(
        /* [out] */ BSTR *pbstr);

    STDMETHOD(put_CustomStartupArguments)(
        /* [in]  */ BSTR bstr);

protected:
    HRESULT SetProperty();
//                                                         IMyCDebugPropPage
// =========================================================================

protected:
    CComPtr<IMyCProjCfgProps> m_srpIMyCProjCfgProps;
    CComPtr<IMyCSettingsPage> m_pIMyCSettingsPage;

    // Debug properties
    MyCPrjDebugStartMode   m_enumMyCPrjDebugStartMode;
    CComBSTR      m_rgcbstrDebugStartMode[MyCPrjDebugStartModeMax-MyCPrjDebugStartModeMin+1];
    CComBSTR      m_cbstrMyCPrjDebugStartMode_Application;
    CComBSTR      m_cbstrStartApp;
    CComBSTR      m_cbstrStartAppPath;
    CComBSTR      m_cbstrCustomStartupArguments;

};


class CDebugPPG :
    public CSettingsPage<&CLSID_DebugPPG,IDS_DEBUG_PAGE,0, CMyCDebugPropPg>
{
public :
    static HRESULT WINAPI UpdateRegistry(
    /* [in] */ BOOL bRegister)
    {
        HRESULT hr = S_OK;

        // get the REGROOTBEGIN and REGROOTEND strings 
        CComBSTR cbstrRegRootBegin;
        CComBSTR cbstrRegRootEnd;
        hr = GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
        IfFailRet(hr);

        // get the guid strings
        CComBSTR cbstrCLSID_DebugPPG(CLSID_DebugPPG);
        if (!cbstrCLSID_DebugPPG) 
            return E_OUTOFMEMORY;

        // now set the atl reg map
        _ATL_REGMAP_ENTRY rgMap[] =
        {
            // NOTE: these names cannot be longer than 30 characters. 
            {L"REGROOTBEGIN",                   cbstrRegRootBegin},
            {L"REGROOTEND",                     cbstrRegRootEnd},
            {L"CLSID_DebugPPG",     cbstrCLSID_DebugPPG},
            {NULL, NULL}
        };

        return _AtlModule.UpdateRegistryFromResourceS(IDR_DEBUG, bRegister, rgMap);
    }
};

