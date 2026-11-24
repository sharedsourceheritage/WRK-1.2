
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

//Forward declarations

interface DECLSPEC_UUID("DB928292-6469-11d2-9702-006008EB6BF1")
IFigCompiler : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE Compile(
        /* [in] */  BSTR    bstrXOffset,
        /* [in] */  BSTR    bstrYOffset,
        /* [in] */  BSTR    bstrpenColor,
        /* [in] */    BSTR    bstrSourceFile,
        /* [in] */    BSTR    bstrSourceDirectory,
        /* [in] */    BSTR    bstrOutputDirectory,
        /* [in] */  BOOL    fPropertyChanged,
        /* [in/out] */ BSTR* pbstrErrorString);
};

const IID IID_IFigCompiler = {0xDB928292,0x6469,0x11d2,{0x97,0x02,0x00,0x60,0x08,0xEB,0x6B,0xF1}};
const CLSID CLSID_FigCompiler = {0xDB928291,0x6469,0x11d2,{0x97,0x02,0x00,0x60,0x08,0xEB,0x6B,0xF1}};

class CProcessedFigFile {
public:
    CProcessedFigFile()    {};
    ~CProcessedFigFile(){};
    
    //These two are strictly so the compiler will work
    //with tokens.  They are never called
    bool operator<(const CProcessedFigFile& x) const {return true;};
    bool operator==(const CProcessedFigFile& x) const {return true;};
    CString m_FileName;
    void CreateFigCall(FILE *stream);
};

typedef std::vector<CProcessedFigFile> FigVector;

class CFigBuildManager {
public:
    CFigBuildManager()
    {
        m_pNewFigComp = NULL;
    };
    ~CFigBuildManager()
    {
        if (m_pNewFigComp)
        {
            m_pNewFigComp->Release();
            m_pNewFigComp = NULL;
        }
    };
    HRESULT Build(IVsOutputWindowPane *pIVsOutputWindowPane, CMyProjectHierarchy *pMyProjectHierarchy, CString m_strOutputDirectory);
    STDMETHOD(Clean)(
        /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane, 
        /* [in] */ CMyProjectHierarchy *pMyProjectHierarchy, 
        /* [in] */ CString strOutDir);
    STDMETHOD(IsBuildUpToDate)(
        /* [in] */ CMyProjectHierarchy* pMyProjectHierarchy, 
        /* [in] */ CString strOutDir,
        /* [out] */ BOOL *pfUpToDate);

    HRESULT LoadFigCompilerServer(IVsOutputWindowPane *pIVsOutputWindowPane);
    HRESULT InsertLangCalls(IVsOutputWindowPane *pIVsOutputPane,FILE* stream,CString outputFile,FigVector successful);

protected:
    STDMETHOD(GetAbsoluteOutputDirectory)(
        /* [in] */      CMyProjectHierarchy* pMyProjectHierarchy, 
        /* [in]      */ const CString& strGivenOutputDirectory,       
        /* [in, out] */       CString& strAbsoluteOutputDirectory);

    STDMETHOD(GetOutputOfFigFile)(
        /* [in]      */ const CString& strFigFileShortName,       
        /* [in]      */ const CString& strOutputDirectory,       
        /* [in, out] */       CString& strOutputFileShortName,
        /* [in, out] */       CString& strOutputFileFullName);

    //Used for the compiler
    IFigCompiler* m_pNewFigComp;

};

class CFigFileNode : 
    public CFileVwFileNode,
    public IDispatchImpl<FigureSourceFile, &IID_FigureSourceFile, &LIBID_FigPrjPKGLib>,
    public IConnectionPointContainerImpl<CFigFileNode>,
    public IPropertyNotifySinkCP<CFigFileNode>,
    public ICategorizeProperties
{
public:
    CFigFileNode();
    ~CFigFileNode();
    
    IMPLEMENT_RTTI(CFigFileNode)

    const GUID* PGuidGetType(void) const { return &GUID_NODETYPE_FigFile;}

    HRESULT Save(IVsPropertyStreamOut *pIVsPropertyStreamOut);
    HRESULT Load(IVsPropertyStreamIn *pIVsPropertyStreamIn);
    HRESULT Compile(CString pOutputDirectory,IFigCompiler* pNewFigComp,BSTR* bstr_Error);
    static HRESULT CreateInstance(LPCTSTR pszFullPath, CFigFileNode **ppFileNode);
    HRESULT GetUserContext(IVsUserContext **ppUserCtx);
    BOOL IsPropertyChanged() {return m_fPropertyChanged;}
public:
    CString m_XOffset;
    CString m_YOffset;
    FigLineColor m_FigLineColor;
    BOOL m_fPropertyChanged;
    
    
    DECLARE_NOT_AGGREGATABLE(CFigFileNode)
        
    BEGIN_COM_MAP(CFigFileNode)
        //        COM_INTERFACE_ENTRY(IOleCommandTarget)
        COM_INTERFACE_ENTRY2(IDispatch, FigureSourceFile)
        COM_INTERFACE_ENTRY_IID(IID_ICategorizeProperties, ICategorizeProperties)
        COM_INTERFACE_ENTRY(IConnectionPointContainer)
    END_COM_MAP()
    
    BEGIN_CONNECTION_POINT_MAP(CFigFileNode)
        CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    END_CONNECTION_POINT_MAP()

    // interface FigureSourceFile
        
    STDMETHOD(get_FileName)(BSTR *pVal);
    STDMETHOD(put_FileName)(BSTR NewName);
    STDMETHOD(get_FilePath)(BSTR *pVal);
    STDMETHOD(get_ModifiedDate)(VARIANT *pVal);
    STDMETHOD(get_Size)(double *pVal);
    STDMETHOD(get_FileType)(BSTR *pVal);
    STDMETHOD(get_ReadOnly)(VARIANT_BOOL *pVal);
    STDMETHOD(put_ReadOnly)(VARIANT_BOOL pVal);

    // Returns the requested extender object if it is available.
    STDMETHOD(get_Extender)(
        /* [in]          */ BSTR         bstrExtenderName, 
        /* [out, retval] */ IDispatch ** ppExtender)
    {  return CFileVwFileNode::get_Extender(bstrExtenderName, ppExtender); }

    // Returns a safe array of string names of currently applicable extenders.
    STDMETHOD(get_ExtenderNames)(
        /* [out, retval] */ VARIANT * pvarExtenderNames)
    {  return CFileVwFileNode::get_ExtenderNames(pvarExtenderNames); }

    // Returns the GUID string for the Project object that is the category ID for 
    // searching for automation extenders. Implementers of extenders for this object 
    // need to know its extender CATID.
    STDMETHOD(get_ExtenderCATID)(
        /* [out, retval] */ BSTR * pbstrRetval)
    {  return CFileVwFileNode::get_ExtenderCATID(pbstrRetval); }

    //FIG - Added for Samples Project
    STDMETHOD(get_ExcludeFromBuild)(VARIANT_BOOL *pVal);
    STDMETHOD(put_ExcludeFromBuild)(VARIANT_BOOL pVal);
    STDMETHOD(get_XOffset)(THIS_ BSTR FAR* pXOffset);
    STDMETHOD(put_XOffset)(BSTR pXOffset);
    STDMETHOD(get_YOffset)(THIS_ BSTR FAR* pYOffset);
    STDMETHOD(put_YOffset)(BSTR pYOffset);
    STDMETHODIMP put_PenColor( FigLineColor Type );
    STDMETHODIMP get_PenColor( FigLineColor *pPenColor );
    
    // interface ICategorizeProperties 
    STDMETHOD(MapPropertyToCategory)(DISPID dispid, PROPCAT* ppropcat);
    STDMETHOD(GetCategoryName)(PROPCAT propcat, LCID lcid, BSTR* pbstrName);

protected:
    STDMETHOD(OnPropertyChanged)(
        /* [in] */ DISPID dispid         = DISPID_UNKNOWN , 
        /* [in] */ BOOL   fDirtyProject  = TRUE           );

};

class CLangFileNode : 
    public CFileVwFileNode,
    public IDispatchImpl<LangSourceFile, &IID_LangSourceFile, &LIBID_FigPrjPKGLib>,
    public IConnectionPointContainerImpl<CLangFileNode>,
    public IPropertyNotifySinkCP<CLangFileNode>,
    public ICategorizeProperties
{
public:
    IMPLEMENT_RTTI(CLangFileNode)
        CLangFileNode();
    ~CLangFileNode();
    static HRESULT CreateInstance(LPCTSTR pszFullPath, CLangFileNode **ppFileNode);
    HRESULT GetUserContext(IVsUserContext **ppUserCtx);
    
    DECLARE_NOT_AGGREGATABLE(CLangFileNode)
    BEGIN_COM_MAP(CLangFileNode)
        //        COM_INTERFACE_ENTRY(IOleCommandTarget)
        COM_INTERFACE_ENTRY2(IDispatch, LangSourceFile)
        COM_INTERFACE_ENTRY_IID(IID_ICategorizeProperties, ICategorizeProperties)
        COM_INTERFACE_ENTRY(IConnectionPointContainer)
    END_COM_MAP()

    BEGIN_CONNECTION_POINT_MAP(CLangFileNode)
        CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    END_CONNECTION_POINT_MAP()
        
    // interface LangSourceFile 
    
    STDMETHOD(get_FileName)(BSTR *pVal);
    STDMETHOD(put_FileName)(BSTR NewName);
    STDMETHOD(get_FilePath)(BSTR *pVal);
    STDMETHOD(get_ModifiedDate)(VARIANT *pVal);
    STDMETHOD(get_Size)(double *pVal);
    STDMETHOD(get_FileType)(BSTR *pVal);
    STDMETHOD(get_ReadOnly)(VARIANT_BOOL *pVal);
    STDMETHOD(put_ReadOnly)(VARIANT_BOOL pVal);
    //FIG - Added for Samples Project
    STDMETHOD(get_ExcludeFromBuild)(VARIANT_BOOL *pVal);
    STDMETHOD(put_ExcludeFromBuild)(VARIANT_BOOL pVal);
    STDMETHOD(get_StartupItem)(VARIANT_BOOL *pVal);
    STDMETHOD(put_StartupItem)(VARIANT_BOOL pVal);

    // Returns the requested extender object if it is available.
    STDMETHOD(get_Extender)(
        /* [in]          */ BSTR         bstrExtenderName, 
        /* [out, retval] */ IDispatch ** ppExtender)
    {  return CFileVwFileNode::get_Extender(bstrExtenderName, ppExtender); }

    // Returns a safe array of string names of currently applicable extenders.
    STDMETHOD(get_ExtenderNames)(
        /* [out, retval] */ VARIANT * pvarExtenderNames)
    {  return CFileVwFileNode::get_ExtenderNames(pvarExtenderNames); }

    // Returns the GUID string for the Project object that is the category ID for 
    // searching for automation extenders. Implementers of extenders for this object 
    // need to know its extender CATID.
    STDMETHOD(get_ExtenderCATID)(
        /* [out, retval] */ BSTR * pbstrRetval)
    {  return CFileVwFileNode::get_ExtenderCATID(pbstrRetval); }
    
    // interface ICategorizeProperties 
    STDMETHOD(MapPropertyToCategory)(DISPID dispid, PROPCAT* ppropcat);
    STDMETHOD(GetCategoryName)(PROPCAT propcat, LCID lcid, BSTR* pbstrName);
    
};

class CLangLine {
public:
    CLangLine()    {};
    ~CLangLine(){};
    
    //These two are strictly so the compiler will work
    //with tokens.  They are never called
    bool operator<(const CLangLine& x) const {return true;};
    bool operator==(const CLangLine& x) const {return true;};
    bool IsMagic();
    void PutLine(FILE* ostream);
    CString m_Line;
};

typedef std::vector<CLangLine> CLangLines;


class ATL_NO_VTABLE COutputDirectoryPPG : 
public CComObjectRootEx<CComSingleThreadModel>,
public CComCoClass<COutputDirectoryPPG, &CLSID_OutputDirectoryPPG>,
public IFigProjPropertyPageImpl<COutputDirectoryPPG>,
public CVsBaseDialogImpl<COutputDirectoryPPG>
{
public:
    COutputDirectoryPPG()
    {
        m_dwTitleID = IDS_OUTPUTDIRECTORY_PAGE;
        m_strF1HelpKeyword = "vs.envsdk.figprj.ProjectPropertiesGeneral";
        ResetChangedStateFlags();
    }
    
    enum {IDD = IDD_PP_OUTPUT};
    
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
        CComBSTR cbstrCLSID_OutputDirectoryPPG(CLSID_OutputDirectoryPPG);
        if (!cbstrCLSID_OutputDirectoryPPG) 
            return E_OUTOFMEMORY;

        // now set the atl reg map
        _ATL_REGMAP_ENTRY rgMap[] =
        {
            // NOTE: these names cannot be longer than 30 characters. 
            {L"REGROOTBEGIN",                   cbstrRegRootBegin},
            {L"REGROOTEND",                     cbstrRegRootEnd},
            {L"CLSID_OutputDirectoryPPG",     cbstrCLSID_OutputDirectoryPPG},
            {NULL, NULL}
        };

        return _AtlModule.UpdateRegistryFromResource(IDR_OUTPUT, bRegister, rgMap);
    }
    
    BEGIN_COM_MAP(COutputDirectoryPPG) 
        COM_INTERFACE_ENTRY_IMPL(IPropertyPage)
    END_COM_MAP()
    
    BEGIN_MSG_MAP(COutputDirectoryPPG)
        CHAIN_MSG_MAP(IFigProjPropertyPageImpl<COutputDirectoryPPG>)
        MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
        COMMAND_HANDLER(IDC_OUTPUTDIR, EN_CHANGE, OnChange)
    END_MSG_MAP()
        
        //    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
        
    LRESULT OnChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
    {
        m_fIsOutputDirectoryChanged = TRUE;
        SetDirty(TRUE);
        return 0;
    }
    
    void GetDialogSize(const DLGTEMPLATE* pTemplate, SIZE* pSize)
    {
        DLGTEMPLATE* pMungedDlgTempl = NULL;
        
        if(LoadMungedDlgTemplate(IDD, &pMungedDlgTempl) == S_OK)
        {
            _DialogSizeHelper::GetDialogSize(pMungedDlgTempl, pSize);
            // Free the munged template
            ::CoTaskMemFree(pMungedDlgTempl);
        }
        else 
        {
            // If anytyhing goes wrong, we just use standard ATL implementation
            ASSERT(FALSE);
            _DialogSizeHelper::GetDialogSize(pTemplate, pSize);
        }
    }

    STDMETHODIMP Apply()
    {
        ExpectedExprRet(*m_ppUnk);
        CMyProjectCfg* pMyProjectCfg = reinterpret_cast<CMyProjectCfg*>(*m_ppUnk);
        CMyProjectHierarchy* pHier;
        
        pHier = pMyProjectCfg->GetHierarchy();
        ExpectedExprRet(pHier);

        if ( !pHier->QueryEditProjectFile() )
        {
            return OLE_E_PROMPTSAVECANCELLED;
        }
      
        CComBSTR cbstrOutputDirectory = NULL; // output directory to send
        
        if (m_fIsOutputDirectoryChanged)
        {
            GetDlgItemText(IDC_OUTPUTDIR, cbstrOutputDirectory.m_str);
            for (UINT uObj = 0; uObj < m_nObjects; uObj++)
            {
                CComQIPtr<FigureProjectCfg> pFigProjCfgProps(m_ppUnk[uObj]);
                if (pFigProjCfgProps)
                {
                    HRESULT hr = pFigProjCfgProps->put_OutputDirectory(cbstrOutputDirectory);
                    IfFailRet(hr);
                }
                cbstrOutputDirectory.Empty();
            }
        }

        ResetChangedStateFlags();
        
        SetDirty(FALSE);
        return S_OK;
    }
    
protected:
    virtual void InitValues()
    {
        InitOutputDirectory();

        //Setting the above values caused the edit boxes to change. When they change, the Apply button
        //  enables (as per our notification handler). Reset that now...
        ResetChangedStateFlags();
        SetDirty(FALSE);
    }

    HRESULT InitOutputDirectory()
    {
        
        HRESULT     hr = E_FAIL;
        CComBSTR    ccbstrOld;
        CComBSTR    ccbstrNew;
        USES_CONVERSION;

        // get the first one
        ExpectedExprRet(m_ppUnk != NULL);
        CComQIPtr<FigureProjectCfg> pFigProjCfgPropsFirst(m_ppUnk[0]);
        IfNullGo(pFigProjCfgPropsFirst, E_FAIL);

        IfFailGo(pFigProjCfgPropsFirst->get_OutputDirectory(&ccbstrOld));

        for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
        {
            // get the next one
            CComQIPtr<FigureProjectCfg> pFigProjCfgPropsNext(m_ppUnk[uiCfg]);
            IfNullGo(pFigProjCfgPropsNext, E_FAIL);

            IfFailGo(pFigProjCfgPropsNext->get_OutputDirectory(&ccbstrNew));

            // Check if the current and previous values are still equal.  If not,
            // then there is no way we can get a determinate value.
            if (!ccbstrNew || !ccbstrOld || wcscmp(ccbstrNew, ccbstrOld) != 0)
            {
                SetDlgItemText(IDC_OUTPUTDIR, _T(""));
                IfFailGo(E_FAIL);
            }
        }
    
        // The value has been determined
        SetDlgItemText(IDC_OUTPUTDIR, W2T(ccbstrOld));

    Error:
        return hr;
    }

    // reset all the flags for "changed" state to false
    HRESULT ResetChangedStateFlags()
    {
        m_fIsOutputDirectoryChanged = FALSE;
        return S_OK;
    }

    BOOL m_fIsOutputDirectoryChanged;
};
