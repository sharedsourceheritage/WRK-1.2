
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// projcfg.h : Declaration of the CMyProjectCfg configuration object.
//             This object is involved in Build/Debug/Deploy operations

#pragma once

#include "prjinc.h"
#include "genthd.h"
#include "VsOutputGroup.h" //Output Group

// forward references
class CMyProjectHierarchy;
class CMyProjBuildableCfg;

/////////////////////////////////////////////////////////////////////////////
// CMyProjectCfg
//      class for a given project configuration.
//---------------------------------------------------------------------------
// implements:
//      interface: IVsCfg
//      interface: IVsProjectCfg
//      interface: IVsDebuggableProjectCfg
//      interface: IVsProjectCfg2
//      interface: ISpecifyPropertyPages
//      interface: IDispatch
//      interface: IBscProjCfgProps
//---------------------------------------------------------------------------
class CMyProjectCfg :
        public IVsDebuggableProjectCfg, //-> IVsProjectCfg -> IVsCfg
        public IVsProjectCfg2,          //-> IVsProjectCfg -> IVsCfg
        public ISpecifyPropertyPages,
        public CComObjectRootEx<CComMultiThreadModel>,      // explict
        public IDispatchImpl<IBscProjCfgProps, &IID_IBscProjCfgProps, &LIBID_BscPrjPKGLib>
{

// =========================================================================
//                                 Construct, initialize, copy, and destruct
//
public:
    CMyProjectCfg();
    ~CMyProjectCfg();
    HRESULT Init(  
        CMyProjectHierarchy *pHier, 
        const CString& strCfgName,
        const CString& strPlatformName);
    HRESULT Clone(CMyProjectCfg* pClonedCfg);
//
//                                 Construct, initialize, copy, and destruct
// =========================================================================


// =========================================================================
//                                                                   ATL COM 

    BEGIN_COM_MAP(CMyProjectCfg)
        COM_INTERFACE_ENTRY2(IVsCfg,IVsDebuggableProjectCfg)
        COM_INTERFACE_ENTRY2(IVsProjectCfg,IVsDebuggableProjectCfg)
        COM_INTERFACE_ENTRY(IVsDebuggableProjectCfg)
        COM_INTERFACE_ENTRY(IVsProjectCfg2)
        COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IBscProjCfgProps)
        COM_INTERFACE_ENTRY_IID(IID_CMyProjectCfg, CMyProjectCfg)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CMyProjectCfg)

//                                                                   ATL COM 
// =========================================================================

public:
    CString GetName(); 
    HRESULT RenameCfgName(const CString& strNewCfgName);
    HRESULT UpdateName();

// =========================================================================
//                                                                Persisting
public:
    HRESULT Save(IVsPropertyStreamOut *pIVsPropertyStreamOut);
    HRESULT Load(IVsPropertyStreamIn *pIVsPropertyStreamIn);
    HRESULT SetProjectFileDirty(BOOL fDirty);
//                                                                Persisting
// =========================================================================


// IVsCfg
public:
    STDMETHOD(get_DisplayName)(/* [out] */BSTR *pbstrDisplayName);
    STDMETHOD(get_IsDebugOnly)(/* [out] */BOOL *pfIsDebugOnly);
    STDMETHOD(get_IsReleaseOnly)(/*[out] */BOOL *pfIsReleaseOnly);

// IVsProjectCfg
public:
    STDMETHOD(get_ProjectCfgProvider)(/* [out] */IVsProjectCfgProvider **ppIVsProjectCfgProvider);
    STDMETHOD(get_CanonicalName)(/* [out] */BSTR *pbstrCanonicalName);

    // This method is obsolete
    STDMETHOD(get_Platform)(/* [out] */GUID *pguidPlatform){return E_NOTIMPL;};

    STDMETHOD(EnumOutputs)(/* [out] */IVsEnumOutputs **ppIVsEnumOutputs);
    STDMETHOD(OpenOutput)(/* [in] */LPCOLESTR szOutputCanonicalName,
                    /* [out] */IVsOutput **ppIVsOutput);
    STDMETHOD(get_BuildableProjectCfg)(/* [out] */IVsBuildableProjectCfg **ppIVsBuildableProjectCfg);
    STDMETHOD(get_IsPackaged)(/* [out] */ BOOL __RPC_FAR *pfIsPackaged);

    // This method is obsolete
    STDMETHOD(get_IsSpecifyingOutputSupported)(/* [out] */ BOOL *pfIsSpecifyingOutputSupported){return E_NOTIMPL;};

    // This method is obsolete
    STDMETHOD(get_TargetCodePage)(/* [out] */ UINT *puiTargetCodePage){return E_NOTIMPL;};

    // This method is obsolete
    STDMETHOD(get_UpdateSequenceNumber)(/* [out] */ ULARGE_INTEGER *puliUSN){return E_NOTIMPL;};

    STDMETHOD(get_RootURL)(/* [out] */ BSTR *pbstrRootURL);

// IVsDebuggableProjectCfg
    STDMETHOD(DebugLaunch)(/* [in] */VSDBGLAUNCHFLAGS grfLaunch);
    STDMETHOD(QueryDebugLaunch)(/* [in] */VSDBGLAUNCHFLAGS grfLaunch, /* [out] */ BOOL __RPC_FAR *pfCanLaunch);

// helper functions for IVsDebuggableProjectCfg
    STDMETHOD(GetDebugLaunchTargetCount)(/* [in] */int iConfig, /* [out]*/ULONG *puCount);

// ISpecifyPropertyPages
public:
    STDMETHOD(GetPages)(/* [out] */ CAUUID *pPages);
// =========================================================================
//                                                            IVsProjectCfg2
    
// -------------------------------------------------------------------------
//                                                  IVsProjectCfg2 interface
//
// IVsProjectCfg2 : this derives from IVsProjectCfg, and thereby from IVsCfg.
// However, it should be noted that IVsCfg::get_IsDebugOnly() and 
// IVsCfg::get_RetailOnly() are mostly moot, since we're no longer limited to
// two configuration types.  Ergo, code which processes configurations should
// not make assumptions about the number of configurations, nor should it
// assume that a project which has only one configuration is necessarily debug
// or retail.
// The primary use of IVsProjectCfg2, beyond IVsProjectCfg usage, is to allow
// projects the freedom to group outputs.  However, the project must return
// the same number of groups for each configuration that it supports, even
// though the number of outputs contained within a group may vary from
// configuration to configuration.  The groups will also have the same
// identifier information (canonical name, display name, and group info) from
// configuration to configuration within a project.
public:
    

    //----------------------------------------------------------------------
    // Function:    get_CfgType
    //              Returns a pointer to the required interface if implemented.
    //              Otherwise, returns an error.
    // Parameters: 
    //    /* [in] */ REFIID iidCfg,
    //              Interface to look for.
    //  `           Examples of iidCfg values are IID_IVsBuildableProjectCfg,
    //              IID_IVsDebuggableProjectCfg, and IID_IVsDeployableProjectCfg
    //
    //    /* [out, iid_is(iidCfg)] */ void** ppCfg);
    //              A pointer to the interface or NULL.
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(get_CfgType)(
        /* [in] */                  REFIID iidCfg, 
        /* [out, iid_is(iidCfg)] */ void** ppCfg);
    
    //----------------------------------------------------------------------
    // Function:    get_OutputGroups
    //              Return an array of IVsOutputGroup, or just the count in  
    //              pcActual when celt and rgpIVsOutputGroup are NULL.
    //
    // Parameters: 
    //    /* [in]                     */ ULONG celt,
    //    /* [in, out, size_is(celt)] */ IVsOutputGroup *rgpIVsOutputGroup[],
    //    /* [out, optional]          */ ULONG *pcActual);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(get_OutputGroups)(
        /* [in]                     */ ULONG celt,
        /* [in, out, size_is(celt)] */ IVsOutputGroup *rgpIVsOutputGroup[],
        /* [out, optional]          */ ULONG *pcActual);

    //----------------------------------------------------------------------
    // Function:    OpenOutputGroup
    //              Returns a specific output group.
    //
    // Parameters: 
    //    /* [in]  */ LPCOLESTR szCanonicalName,
    //    /* [out] */ IVsOutputGroup **ppIVsOutputGroup);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(OpenOutputGroup)(
        /* [in]  */ LPCOLESTR szCanonicalName,
        /* [out] */ IVsOutputGroup **ppIVsOutputGroup);

    //----------------------------------------------------------------------
    // Function:    OutputsRequireAppRoot
    // Parameters: 
    //    /* [out] */ BOOL *pfRequiresAppRoot);
    // Returns:     HRESULT
    // Notes:
    //              This method replaces the get_IsWebApplication() method 
    //              from the now-obsolete IVsDeployWebProject interface.
    //----------------------------------------------------------------------
    STDMETHOD(OutputsRequireAppRoot)(
        /* [out] */ BOOL *pfRequiresAppRoot);
        
    //----------------------------------------------------------------------
    // Function:    get_VirtualRoot
    // Parameters: 
    //    /* [out] */ BSTR *pbstrVRoot);
    // Returns:     HRESULT
    // Notes:
    //              This method is identical to the get_VirtualRoot method 
    //              from the now-obsolete IVsDeployWebProject interface.  
    //              It is required for debugging web projects.
    //----------------------------------------------------------------------
    STDMETHOD(get_VirtualRoot)(
        /* [out] */ BSTR *pbstrVRoot);

    //----------------------------------------------------------------------
    // Function:    get_IsPrivate
    // Parameters: 
    //    /* [out] */ BOOL *pfPrivate);
    // Returns:     HRESULT
    // Notes:
    //              This method tells whether this is a private (per user 
    //              as opposed to shared w/all team) config.
    //----------------------------------------------------------------------
    STDMETHOD(get_IsPrivate)(
        /* [out] */ BOOL *pfPrivate);

//
//                                                  IVsProjectCfg2 interface
// -------------------------------------------------------------------------


// -------------------------------------------------------------------------
//                                                    IVsProjectCfg2 helpers

public:
    //----------------------------------------------------------------------
    // Function:    GetOutputGroupsCount
    //              Returns the number of the output groups.
    // Parameters: 
    // Returns:     USHORT - number of the output groups
    // Notes:
    //              Returns identical information regardless of cfg settings.
    //----------------------------------------------------------------------
    USHORT GetOutputGroupsCount();

    //----------------------------------------------------------------------
    // Function:    get_KeyOutput
    //              Returns the key output for the specified output group.
    // Parameters: 
    //    /* [in]  */ OUTPUTGROUPTYPE ogt,
    //    /* [out] */ BSTR*           pbstrCanonicalName);
    // Returns:     HRESULT 
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(get_OgtKeyOutput)(
        /* [in]  */ OUTPUTGROUPTYPE ogt,
        /* [out] */ BSTR*           pbstrCanonicalName);

    STDMETHOD(AddOgtOutputsToArray)(
        /* [in]      */  OUTPUTGROUPTYPE ogt,
        /* [in, out] */  IVsOutput2Array* prgpIVsOutput2);

    STDMETHOD(AddAllOutputsToArray)(
        /* [in, out] */  IVsOutput2Array* prgpIVsOutput2);

protected:
    STDMETHOD(AddBuiltOutputsToArray)(
        /* [in,out] */  IVsOutput2Array* prgpIVsOutput2);

    STDMETHOD(GetOutputAbsPath)(
        /* [out] */ BSTR* pbstr);


//                                                    IVsProjectCfg2 helpers
// -------------------------------------------------------------------------
//                                                            IVsProjectCfg2
// =========================================================================

// IBscProjCfgProps
public:
    STDMETHOD(get_CommandLine)(BSTR *pVal);
    STDMETHOD(put_CommandLine)(BSTR NewName);
    STDMETHOD(get_CommandLineArguments)(BSTR *pVal);
    STDMETHOD(put_CommandLineArguments)(BSTR NewName);
    STDMETHOD(get_BuildArguments)(BSTR *pVal);
    STDMETHOD(put_BuildArguments)(BSTR NewName);
    STDMETHOD(get_Outputs)(BSTR *pVal);
    STDMETHOD(put_Outputs)(BSTR NewName);

    // Returns the requested extender object if it is available.
    STDMETHOD(get_Extender)(
        /* [in]          */ BSTR         bstrExtenderName, 
        /* [out, retval] */ IDispatch ** ppExtender);

    // Returns a safe array of string names of currently applicable extenders.
    STDMETHOD(get_ExtenderNames)(
        /* [out, retval] */ VARIANT * pvarExtenderNames);

    // Returns the GUID string for the Project object that is the category ID for 
    // searching for automation extenders. Implementers of extenders for this object 
    // need to know its extender CATID.
    STDMETHOD(get_ExtenderCATID)(
        /* [out, retval] */ BSTR * pbstrRetval);


    CMyProjectHierarchy* CMyProjectCfg::GetHierarchy() {    return m_pHier;}


protected:
    BOOL FFireBuildBegin();
    void FireBuildEnd(BOOL fSuccessful);

// =========================================================================
//                                                                   MEMBERS
protected:
    // --------------------------------------------------------------------

    CMyProjectHierarchy *m_pHier; // ptr to hierarchy.
    // Internal properties
    CString      m_strCfgName;
    CString      m_strPlatformName;
    CString      m_strName; // strCfgName+"|"+strPlatformName;

public:
    CString m_strPrgCMDLine;
    CString m_strPrgArgs;
    CString m_strBuildCMD;
    CString m_strBuildOutputs;

protected:

    // IVsProjectCfg2 members
    OUTPUTGROUPTYPE m_rgogt[1]; // currently we support one output group
    // --------------------------------------------------------------------
//                                                                   MEMBERS
// =========================================================================
};


/////////////////////////////////////////////////////////////////////////////
// CMyProjBuildableCfg
//      class to handle the build operation for a given project configuration.
//
//---------------------------------------------------------------------------
// implements:
//      interface: IVsBuildableProjectCfg
//---------------------------------------------------------------------------
class CMyProjBuildableCfg :
        public IVsBuildableProjectCfg,
        public CComObjectRootEx<CComMultiThreadModel>       // explict
{
public:
    CMyProjBuildableCfg();
    ~CMyProjBuildableCfg();
    HRESULT Init(CMyProjectCfg *pProjectCfg, CMyProjectHierarchy *pHier);

BEGIN_COM_MAP(CMyProjBuildableCfg)
    COM_INTERFACE_ENTRY(IVsBuildableProjectCfg)     // derives from IUnknown
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(CMyProjBuildableCfg)

// IVsBuildableProjectCfg
public:
    STDMETHOD(get_ProjectCfg)(/* [out] */ IVsProjectCfg **ppIVsProjectCfg);
    STDMETHOD(AdviseBuildStatusCallback)(/* [in] */IVsBuildStatusCallback *pIVsBuildStatusCallback,
                               /* [out] */VSCOOKIE *pdwCookie);
    STDMETHOD(UnadviseBuildStatusCallback)(/* [in] */VSCOOKIE dwCookie);
    STDMETHOD(QueryStartBuild)(/* [in] */ DWORD dwOptions,
      /* [out, optional] */BOOL *pfSupported, /* [out, optional] */ BOOL *pfEnabled);
    STDMETHOD(QueryStartClean)(/* [in] */ DWORD dwOptions,
      /* [out, optional] */BOOL *pfSupported, /* [out, optional] */ BOOL *pfEnabled);
    STDMETHOD(QueryStartUpToDateCheck)(/* [in] */ DWORD dwOptions,
      /* [out, optional] */BOOL *pfSupported, /* [out, optional] */ BOOL *pfEnabled);
    STDMETHOD(StartBuild)(/* [in] */IVsOutputWindowPane *pIVsOutputWindowPane, /* [in] */DWORD dwOptions);
    STDMETHOD(StartClean)(/* [in] */IVsOutputWindowPane *pIVsOutputWindowPane, /* [in] */DWORD dwOptions);
    STDMETHOD(StartUpToDateCheck)(/* [in] */IVsOutputWindowPane *pIVsOutputWindowPane, /* [in] */DWORD dwOptions);
    STDMETHOD(QueryStatus)(/* [out] */BOOL *pfBuildDone);
    STDMETHOD(Stop)(/* [in] */BOOL fSync);
    STDMETHOD(Wait)(/* [in] */DWORD dwMilliseconds, /* [in] */BOOL fTickWhenMessageQNotEmpty);
    
public:
    BOOL FFireTick();
    BSTR GetProjectName();
    BSTR GetCommandLine();
    BSTR GetProjectDir();
    void SetThread(HANDLE hThread);
    BOOL Busy();

    // builder thread class
    class CBuilderThread : public CVsThread<CMyProjBuildableCfg>
    {
        typedef CVsThread<CMyProjBuildableCfg> super;
        friend class CMyProjBuildableCfg;

    public:
        CBuilderThread();
        ~CBuilderThread();

        enum Operation
        {
            eIdle,
            eBuild,
            eCheckUpToDate,
            eClean,
        };

        HRESULT Start(CMyProjBuildableCfg *pCMyProjBuildableCfg, Operation op);
        void Stop(BOOL fSync);
        void QueryStatus(BOOL *pfDone);

        virtual void InternalTick(BOOL &rfContine);

        CMyProjBuildableCfg *m_pCMyProjBuildableCfg;
        CComPtr<IVsLaunchPadFactory> m_srpIVsLaunchPadFactory;

        void Fire_Tick(BOOL &rfContinue);

    protected:
        virtual HRESULT PrepareInStartingThread(CMyProjBuildableCfg *pCMyProjBuildableCfg);
        virtual void ThreadMain(CMyProjBuildableCfg *pBuildableCfg);
        virtual HRESULT InnerThreadMain(CMyProjBuildableCfg *pBuildableCfg);

        virtual void ReleaseThreadHandle();

        void Fire_BuildBegin(BOOL &rfContinue);
        void Fire_BuildEnd(BOOL fSuccess);

        void DoBuild(BOOL &rfSuccessful);
        void DoCheckIsUpToDate(BOOL &rfSuccessful);
        void DoClean(BOOL &rfSuccessful);
        void OutputText(LPCWSTR wsz);

        IStream *m_rgpIStream_IVsBuildStatusCallback[5];
        IVsBuildStatusCallback *m_rgpIVsBuildStatusCallback[5];

        IStream *m_pIStream_IVsOutputWindowPane;
        IVsOutputWindowPane *m_pIVsOutputWindowPane;

        IStream *m_pIStream_IVsStatusbar;
        IVsStatusbar *m_pIVsStatusbar;

        BOOL m_fIsUpToDate;
        Operation m_op;

        HANDLE m_hEventStartSync;
#ifdef DEBUG
        DWORD m_dwWorkerThreadId;
#endif // DEBUG

        using super::Start;
    };

public:
    CBuilderThread  m_thread;
    
protected:

    CComBSTR cbstrProjectName;
    CComBSTR cbstrCommandLine; 
    CComBSTR cbstrProjectDir;

public:

    CMyProjectCfg *m_pProjectCfg; // ptr back to the config.
    CMyProjectHierarchy *m_pHier; // ptr to hierarchy.
    CComPtr<IVsBuildStatusCallback> m_rgsrpIVsBuildStatusCallback[5]; // allow 5 connections.
    BOOL    m_rgfTicking[5]; // whether tick events can be sent.
    BOOL    m_rgfStarted[5];
    BOOL    m_fDoIncrementalBuild;
#ifdef DEBUG
    DWORD   m_dwBuilderThreadId;
#endif // DEBUG
    CComPtr<IVsOutputWindowPane>    m_pIVsOutputWindowPane;
    CComPtr<IVsStatusbar>           m_pIVsStatusbar;
    
    BOOL    m_fStopBuild; // flag to stop the build in progress.

};

#define WM_PROJECTBUILDALLMSG       WM_USER+1
#define WM_PROJECTCLEANMSG          WM_USER+2
#define WM_PROJECTCHECKUPTODATEMSG  WM_USER+3

LRESULT CALLBACK ProjectBuildWndProc(HWND hwnd, UINT wm, WPARAM wParam, LPARAM lParam);


/********************************************************************************************
* Per configuration project settings PropertyPage support
********************************************************************************************/


template <typename T> 
class ATL_NO_VTABLE IBscProjPropertyPageImpl : public IVsPropertyPageImpl<T>
{
public:
    IBscProjPropertyPageImpl() : m_bInitWasCalled(FALSE)
    {
    }

BEGIN_MSG_MAP(IBscProjPropertyPageImpl)
    CHAIN_MSG_MAP(IVsPropertyPageImpl<T>)
END_MSG_MAP()

  LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        m_bInitWasCalled = TRUE;
        InitDialogValues();
        return 1;
    }

    STDMETHOD(Help)(LPCOLESTR pszHelpDir)
    {   
        // show help here 
        // Use Help::DisplayTopicFromF1Keyword method to display help about the property page
        return E_NOTIMPL;
    }

    void InitDialogValues()
    {
        InitValues();
    }
    // Because of a bug in atl, this is reproduced here with the fix
    void SetDirty(BOOL bDirty)
    {
        if (m_bDirty != bDirty)
        {
            m_bDirty = bDirty;
            m_pPageSite->OnStatusChange(PROPPAGESTATUS_DIRTY | PROPPAGESTATUS_VALIDATE);
        }
    }
    // Overridden to handle selection changes.
    STDMETHOD(SetObjects)(ULONG nObjects, IUnknown **ppUnk)
    {
        if (!ppUnk)     
            return S_OK;
        HRESULT hr = IVsPropertyPageImpl<T>::SetObjects(nObjects, ppUnk);
        if(hr == S_OK && m_bInitWasCalled && nObjects)
            InitDialogValues();
        return hr;
    }

protected:
    BOOL m_bInitWasCalled;
    // Override to initialize your dll's values
    virtual void InitValues(){};

};

class CMyProjectHierarchy;


class ATL_NO_VTABLE CLaunchPPG : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CLaunchPPG, &CLSID_LaunchPPG>,
    public IBscProjPropertyPageImpl<CLaunchPPG>,
    public CVsBaseDialogImpl<CLaunchPPG>
{

public:
    CLaunchPPG();

    enum {IDD = IDD_PP_LAUNCH};

    static HRESULT WINAPI UpdateRegistry(
        /* [in] */ BOOL bRegister);

BEGIN_COM_MAP(CLaunchPPG) 
    COM_INTERFACE_ENTRY_IMPL(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CLaunchPPG)
    CHAIN_MSG_MAP(IBscProjPropertyPageImpl<CLaunchPPG>)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    COMMAND_HANDLER(IDC_LAUNCHPRG, EN_CHANGE, OnChangePrg)
    COMMAND_HANDLER(IDC_CMDLINEPARAM, EN_CHANGE, OnChangeParam)
END_MSG_MAP()

//  LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

    LRESULT OnChangePrg(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnChangeParam(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    
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

    STDMETHODIMP Apply();
  
protected:
    virtual void InitValues();
    HRESULT InitCMDLine();
    HRESULT InitCMDLineArgs();

    // reset all the flags for "changed" state to false
    HRESULT ResetChangedStateFlags();

    
    BOOL m_fIsLaunchPrgChanged;
    BOOL m_fIsCmdLineParamChanged;
};



class ATL_NO_VTABLE CCustomPPG : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CCustomPPG, &CLSID_CustomPPG>,
    public IBscProjPropertyPageImpl<CCustomPPG>,
    public CVsBaseDialogImpl<CCustomPPG>
{
public:
    CCustomPPG(); 

    enum {IDD = IDD_PP_CUSTOM};

    static HRESULT WINAPI UpdateRegistry(
        /* [in] */ BOOL bRegister);

BEGIN_COM_MAP(CCustomPPG) 
    COM_INTERFACE_ENTRY_IMPL(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CCustomPPG)
    CHAIN_MSG_MAP(IBscProjPropertyPageImpl<CCustomPPG>)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
  COMMAND_HANDLER(IDC_BUILDCMDS, EN_CHANGE, OnChangeBuildCmds)
  COMMAND_HANDLER(IDC_BUILDOUTPUTS, EN_CHANGE, OnChangeBuildOutputs)
END_MSG_MAP()

//  LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnChangeBuildCmds(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnChangeBuildOutputs(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

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

    STDMETHODIMP Apply();
  
protected:
    virtual void InitValues();
    HRESULT InitBuildCmds();
    HRESULT InitBuildOutputs();

    // reset all the flags for "changed" state to false
    HRESULT ResetChangedStateFlags();
    

    BOOL m_fIsBuildCmdsChanged;
    BOOL m_fIsBuildOutputsChanged;
};

