
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

/********************************************************************************************
* BuildPPG.h
* Per configuration project settings PropertyPage support - Build 
********************************************************************************************/

#pragma once
  
class ATL_NO_VTABLE CBuildPPG :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CBuildPPG, &CLSID_BuildPPG>,
    public IMyCPrjPropertyPageImpl<CBuildPPG>,
    public CVsBaseDialogImpl<CBuildPPG>
{
public:

    enum {IDD = IDD_PP_BUILD};

    CBuildPPG();
    ~CBuildPPG();

    static HRESULT WINAPI UpdateRegistry(
        /* [in] */ BOOL bRegister);

BEGIN_COM_MAP(CBuildPPG)
    COM_INTERFACE_ENTRY_IMPL(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CBuildPPG)
    CHAIN_MSG_MAP(IMyCPrjPropertyPageImpl<CBuildPPG>)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    COMMAND_HANDLER(IDC_PROJECTTYPE,      CBN_SELCHANGE,  OnChangeProjectType)
    COMMAND_HANDLER(IDC_DEBUGCHECK,       BN_CLICKED,     OnClickedCheckButton)
    COMMAND_HANDLER(IDC_LISTINGCHECK,     BN_CLICKED,     OnClickedCheckButton)
    COMMAND_HANDLER(IDC_OUTPUTPATHBROWSE, BN_CLICKED,     OnClickedOutpuPathB)
    COMMAND_HANDLER(IDC_OUTPUTPATH,       EN_CHANGE,      OnChangeOutputPath)
    NOTIFY_HANDLER( IDC_SOURCEFILE,       TVN_SELCHANGING, OnChangeSourceFile )
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    // message handler
    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

    STDMETHOD(Apply)(); 

protected: 
    // command handler
    LRESULT OnChangeProjectType( WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnClickedCheckButton(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnClickedOutpuPathB( WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    LRESULT OnChangeOutputPath(  WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

    // notify handler
    LRESULT OnChangeSourceFile( int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    void GetDialogSize(const DLGTEMPLATE* pTemplate, SIZE* pSize);

    virtual void InitValues();
    HRESULT InitSourceFileTv();
    HRESULT InitSourceFileTvNode(HTREEITEM hParent, CFileVwBaseNode* pNode);
    HRESULT InitSourceFile();
    HRESULT SelectSourceFileTv();
    HRESULT InitProjectTypeCb();
    HRESULT InitProjectType();
    HRESULT InitOutputPath();
    HRESULT InitDebugCheck
    (
        /* [in] */ UINT&    val,                   // value of the checkbox
        /* [in] */ BOOL&    bIndeterminate         // whether the state is determined  
    );
    HRESULT InitListingCheck
    (
        /* [in] */ UINT&    val,                   // value of the checkbox
        /* [in] */ BOOL&    bIndeterminate         // whether the state is determined  
    );


    HRESULT ResetChangedStateFlags();
    HRESULT UpdateListingFileInUI();
    HRESULT UpdateDebugInfoFileInUI();
    void SetDirty(BOOL bDirty);
    void UpdateCommandLineInUI();
    
    // Generate the output file name
    // This function needs to be called whenever the user changes the output project 
    // type OR if the user changes the source file.
    HRESULT UpdateOutputFileInUI();


    void OnNoSourceFile();

protected:

    // Control handles
    HWND    m_hwndSourceFileTv;     // Source File Tree View
    HWND    m_hwndProjectTypeCb;    // Project Type Combo Box

    CString m_strBuildCommandLine;  // only the build part of the command line   
    CString m_strSrcFile;           // currently selected source file - full path
    CString m_strProjectType;       // type of the project - EXE (default) or DLL;  
    CString m_strOutputPath;        // /outdir  

    BOOL m_fIsSrcFileChanged;       // keep track of SrcFile changes
    BOOL m_fIsOutputPathChanged;    // keep track of OutputPath changes

}; // CBuildPPG
