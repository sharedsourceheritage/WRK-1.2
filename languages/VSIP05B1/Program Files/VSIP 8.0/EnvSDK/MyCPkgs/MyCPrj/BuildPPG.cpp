
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// BuildPPG.cpp 

#include "stdafx.h"
#include "PrjInc.h" 

// ========================================================================
//                                                Constructors & destructor

CBuildPPG::CBuildPPG()
{
    ENVSDK_TRACE(atlTraceControls, TLC, 
        _T(": CBuildPPG::CBuildPPG created at 0x%x \n"), this);

    m_dwTitleID = IDS_BUILD_PAGE;
    ResetChangedStateFlags();
}


CBuildPPG::~CBuildPPG()
{
    ENVSDK_TRACE(atlTraceControls, TLD, 
        _T(": CBuildPPG::~CBuildPPG destroyed at 0x%x \n"), this);
}

//                                                Constructors & destructor
// ========================================================================

// ========================================================================
//                                                             registration
/* static */
HRESULT WINAPI CBuildPPG::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{

    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    IfFailRet(hr);

    // get the guid strings
    CComBSTR cbstrCLSID_BuildPPG(CLSID_BuildPPG);
    if (!cbstrCLSID_BuildPPG) 
        return E_OUTOFMEMORY;

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"CLSID_BuildPPG",     cbstrCLSID_BuildPPG},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResource(IDR_BUILD, bRegister, rgMap);
}
// ========================================================================

// ========================================================================
//                                                             OnInitDialog

LRESULT CBuildPPG::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::OnInitDialog \n"));

    m_bInitWasCalled        = TRUE;
    m_hwndSourceFileTv      = GetDlgItem(IDC_SOURCEFILE);
    m_hwndProjectTypeCb     = GetDlgItem(IDC_PROJECTTYPE);

    InitDialogValues();

    return 1;
}


void CBuildPPG::InitValues()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::InitValues \n"));

    HRESULT hr;
    BOOL    bIndeterminate;
    UINT    uCheckBoxState;
    LRESULT    i;

    // init the sourse file
    if (m_fMultipleProjectsSelected)
    {
        // disable the source file tree view
        ::EnableWindow(m_hwndSourceFileTv, FALSE);
    }
    else
    {
        hr = InitSourceFileTv();
        IfFailGo(hr);    
        hr = InitSourceFile();
        IfFailGo(hr);    
        hr = SelectSourceFileTv();
        IfFailGo(hr);    
    }

    // init the project type
    hr = InitProjectTypeCb();
    IfFailGo(hr);    
    hr = InitProjectType();
    IfFailGo(hr);
    if (m_strProjectType.IsEmpty())
        i = SendMessage(m_hwndProjectTypeCb, CB_SETCURSEL, (WPARAM) -1,  (LPARAM) 0);    
    else
        i = SendMessage(m_hwndProjectTypeCb, CB_SELECTSTRING, (WPARAM)-1, (LPARAM)(LPCTSTR)m_strProjectType);

    // init the output path
    hr = InitOutputPath();
    IfFailGo(hr);    
    if (! SetDlgItemText(IDC_OUTPUTPATH, m_strOutputPath)) 
        hr = HRESULT_FROM_WIN32(GetLastError());
    IfFailGo(hr);

    // init the debug info
    hr = InitDebugCheck(uCheckBoxState, bIndeterminate);
    IfFailGo(hr);
    if (! CheckDlgButton(IDC_DEBUGCHECK, uCheckBoxState) )
        hr = E_FAIL;
    IfFailGo(hr);

    // init the listing info
    hr = InitListingCheck(uCheckBoxState, bIndeterminate);
    IfFailGo(hr);
    if (! CheckDlgButton(IDC_LISTINGCHECK, uCheckBoxState) )
        hr = E_FAIL;
    IfFailGo(hr);
   
    // Setting the above values caused the edit boxes to change.  When they change, the Apply
    // button enables (as per out notification handler).  Reset that now...
    ResetChangedStateFlags();
    SetDirty(FALSE);

Error:    

    ASSERT(SUCCEEDED(hr));
    
    return;
}


HRESULT CBuildPPG::InitSourceFileTv()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::InitSourceFileTv \n") );

    HRESULT hr = S_OK;

    // check if the tree is initialized
    // it happens when the configuration is changed
    HTREEITEM htvi = TreeView_GetRoot(m_hwndSourceFileTv);
    if (htvi != NULL)
    {
        // clear any previous selections
        TreeView_Select(m_hwndSourceFileTv, NULL, TVGN_DROPHILITE);        
        TreeView_SelectItem(m_hwndSourceFileTv, NULL);
        return S_OK;
    }
   
    // insert the project name as the root of the tree control
    // and recursively initialie the tree
    hr = InitSourceFileTvNode(TVI_ROOT, m_pfvpn);

    return hr;
}


// inserts pNode as a child of the hParent item in the given tree view control,
// then recursively inserts all of pNode's children/descendants
HRESULT CBuildPPG::InitSourceFileTvNode
(
    /* [in]  */ HTREEITEM        hParent, 
    /* [out] */ CFileVwBaseNode* pNode
)
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::InitSourceFileTvNode \n") );

    ExpectedPtrRet(pNode);

    HRESULT hr = S_OK;

    CFileVwBaseNode * pChild =  (CFileVwBaseNode *) pNode->GetHeadEx();
    CString strName = pNode->GetFileName();

    TVINSERTSTRUCT tvInsert;
    tvInsert.hParent        = hParent;
    tvInsert.hInsertAfter   = TVI_LAST;
    tvInsert.item.mask      = TVIF_TEXT | TVIF_CHILDREN | TVIF_PARAM;
    tvInsert.item.pszText   = (LPTSTR) (LPCTSTR) strName;
    tvInsert.item.cChildren = (pChild != NULL);
    tvInsert.item.lParam    = (LPARAM) pNode;

    HTREEITEM hThisNode = TreeView_InsertItem(m_hwndSourceFileTv, &tvInsert);
    if (hThisNode == NULL) return E_FAIL;

    for (; pChild != NULL; pChild = (CFileVwBaseNode *) pChild->GetNext())
    {
        hr = InitSourceFileTvNode(hThisNode, pChild);
        IfFailRet(hr);
    }

    return hr;
}



HRESULT CBuildPPG::InitSourceFile()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::InitSourceFile \n") );

    HRESULT     hr;
    CComBSTR    ccbstrOld;
    CComBSTR    ccbstrNew;

    // get the first one
    ExpectedExprRet(m_ppIMyCProjCfgProps[0] != NULL);
    hr = m_ppIMyCProjCfgProps[0]->get_SourceFile(&ccbstrOld);
    IfFailRet(hr);

    for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
    {
        // get the next one
        ExpectedExprRet(m_ppIMyCProjCfgProps[uiCfg] != NULL);
        hr = m_ppIMyCProjCfgProps[uiCfg]->get_SourceFile(&ccbstrNew);
        IfFailRet(hr);

        // Check if the current and previous values are still equal.  If not,
        // then there is no way we can get a determinate value.
        if (!ccbstrNew || !ccbstrOld || wcscmp(ccbstrNew, ccbstrOld) != 0)
        {
            m_strSrcFile.Empty();
            return S_FALSE;            
        }
    }

    // The value has been determined
    m_strSrcFile = CString(ccbstrOld);
    return S_OK;
}


// This method highlights the tree view item with the full path matching
// NOTE: this function does not support folders in a project, so it should be rewritten if
//      that functionality is ever implemented.
HRESULT CBuildPPG::SelectSourceFileTv()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::SelectSourceFileTv \n") );

    if (m_strSrcFile.IsEmpty())
        return S_FALSE;

    CFileVwBaseNode* pfvbn;
    ExpectedPtrRet(m_pfvpn);
    pfvbn = m_pfvpn->GetNodeByFullPath(m_strSrcFile);
    if (!pfvbn)
        return S_FALSE;

    // Find the node
    HTREEITEM   hItem = TreeView_GetRoot(m_hwndSourceFileTv);
    if (hItem == NULL) return S_FALSE;
    TVITEM      tvItem;

    hItem = TreeView_GetChild(m_hwndSourceFileTv, hItem);
    while (hItem)
    {
        tvItem.hItem = hItem;
        tvItem.mask = TVIF_PARAM | TVIF_CHILDREN;
        TreeView_GetItem(m_hwndSourceFileTv, &tvItem);
        VSASSERT(!tvItem.cChildren, "Folders are not supported by this function!");

        CFileVwBaseNode * pfvbnTreeItem = (CFileVwBaseNode *) tvItem.lParam;
        if (pfvbn == pfvbnTreeItem)
        {
            TreeView_SelectItem(m_hwndSourceFileTv, hItem);
            return S_OK;
        }
        hItem = TreeView_GetNextSibling(m_hwndSourceFileTv, hItem);
    }

    return S_FALSE;
}    


HRESULT CBuildPPG::InitProjectTypeCb()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::InitProjectTypeCb \n") );

    // check if initialized
    if (SendMessage(m_hwndProjectTypeCb, CB_GETCOUNT, (WPARAM)0, (LPARAM) 0) != 0)
        return S_OK;

    SendMessage(m_hwndProjectTypeCb, CB_INSERTSTRING, -1, (LPARAM)_T("EXE"));
    SendMessage(m_hwndProjectTypeCb, CB_INSERTSTRING, -1, (LPARAM)_T("DLL"));
    return S_OK;
}


HRESULT CBuildPPG::InitProjectType()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::InitProjectType \n") );
    
    HRESULT     hr;
    CComBSTR    ccbstrOld;
    CComBSTR    ccbstrNew;

    // get the first one
    ExpectedExprRet(m_ppIMyCProjCfgProps[0] != NULL);
    hr = m_ppIMyCProjCfgProps[0]->get_ProjectType(&ccbstrOld);
    IfFailRet(hr);

    for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
    {
        // get the next one
        ExpectedExprRet(m_ppIMyCProjCfgProps[uiCfg] != NULL);
        hr = m_ppIMyCProjCfgProps[uiCfg]->get_ProjectType(&ccbstrNew);
        IfFailRet(hr);

        // Check if the current and previous values are still equal.  If not,
        // then there is no way we can get a determinate value.
        if (!ccbstrNew || !ccbstrOld || wcscmp(ccbstrNew, ccbstrOld) != 0)
        {
            m_strProjectType.Empty();
            return S_OK;            
        }
    }

    // The value has been determined
    m_strProjectType = ccbstrOld;
    return hr;
}


HRESULT CBuildPPG::InitOutputPath()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::InitOutputPath \n") );
    
    HRESULT     hr;
    CComBSTR    ccbstrOld;
    CComBSTR    ccbstrNew;

    // get the first one
    ExpectedExprRet(m_ppIMyCProjCfgProps[0] != NULL);
    hr = m_ppIMyCProjCfgProps[0]->get_OutputPath(&ccbstrOld);
    IfFailRet(hr);

    for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
    {
        // get the next one
        ExpectedExprRet(m_ppIMyCProjCfgProps[uiCfg] != NULL);
        hr = m_ppIMyCProjCfgProps[uiCfg]->get_OutputPath(&ccbstrNew);
        IfFailRet(hr);

        // Check if the current and previous values are still equal.  If not,
        // then there is no way we can get a determinate value.
        if (!ccbstrNew || !ccbstrOld || wcscmp(ccbstrNew, ccbstrOld) != 0)
        {
            m_strOutputPath.Empty();
            return S_OK;            
        }
    }

    // The value has been determined
    m_strOutputPath = CString(ccbstrOld);
    return hr;
}


HRESULT CBuildPPG::InitDebugCheck
(
    /* [in] */ UINT&    val,                   // value of the checkbox
    /* [in] */ BOOL&    bIndeterminate         // whether the state is determined  
)
{    
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::InitDebugCheck \n") );

    VARIANT_BOOL    vbOld; 
    VARIANT_BOOL    vbNew; 
    HRESULT hr      = S_OK;
    bIndeterminate  = TRUE;

    ExpectedExprRet(m_ppIMyCProjCfgProps[0] != NULL);
    hr = m_ppIMyCProjCfgProps[0]->get_DebugInfoChecked(&vbOld);
    IfFailRet(hr);

    for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
    {
        // get the next one
        ExpectedExprRet(m_ppIMyCProjCfgProps[uiCfg] != NULL);
        hr = m_ppIMyCProjCfgProps[uiCfg]->get_DebugInfoChecked(&vbNew);
        IfFailRet(hr);

        // Check if the current and previous values are still equal.  If not,
        // then there is no way we can get a determinate value.
        if (vbNew != vbOld)
        {
            val = BST_INDETERMINATE;
            return hr;            
        }
    }

    // The value has been determined
    val =  (vbOld == VARIANT_TRUE) ? BST_CHECKED : BST_UNCHECKED;
    bIndeterminate = FALSE;
    return hr;
}


HRESULT CBuildPPG::InitListingCheck
(
    /* [in] */ UINT&    val,                   // value of the checkbox
    /* [in] */ BOOL&    bIndeterminate         // whether the state is determined  
)
{    
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::InitListingCheck \n") );

    VARIANT_BOOL    vbOld; 
    VARIANT_BOOL    vbNew; 
    HRESULT hr      = S_OK;
    bIndeterminate  = TRUE;

    ExpectedExprRet(m_ppIMyCProjCfgProps[0] != NULL);
    hr = m_ppIMyCProjCfgProps[0]->get_ListingFileChecked(&vbOld);
    IfFailRet(hr);

    for (UINT uiCfg = 1; uiCfg < m_nObjects; uiCfg++)
    {
        // get the next one
        ExpectedExprRet(m_ppIMyCProjCfgProps[uiCfg] != NULL);
        hr = m_ppIMyCProjCfgProps[uiCfg]->get_ListingFileChecked(&vbNew);
        IfFailRet(hr);

        // Check if the current and previous values are still equal.  If not,
        // then there is no way we can get a determinate value.
        if (vbNew != vbOld)
        {
            val = BST_INDETERMINATE;
            return hr;            
        }
    }

    // The value has been determined
    val =  (vbOld == VARIANT_TRUE) ? BST_CHECKED : BST_UNCHECKED;
    bIndeterminate = FALSE;
    return hr;
}

//                                                             OnInitDialog
// ========================================================================


// ========================================================================
//                                                         Command handlers


LRESULT CBuildPPG::OnChangeProjectType(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::OnChangeProjectType \n") );

    CString strNew;
    if (FAILED(ComboBoxGetText(m_hwndProjectTypeCb, strNew))) 
        return 0;

    if (m_strProjectType != strNew) 
    {
        m_strProjectType = strNew;
        UpdateOutputFileInUI();
        SetDirty(TRUE);
    }
    return 0;
}


LRESULT CBuildPPG::OnClickedCheckButton(WORD  wNotifyCode, WORD  wID, HWND  hWndCtl, BOOL& bHandled)
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::OnClickedCheckButton \n") );

    UINT uState = IsDlgButtonChecked(wID);

    // prevent the user from selecting an indeterminate state
    if (uState != BST_CHECKED && uState != BST_UNCHECKED)
    {
        // Must be indeterminate state in the tri-state control
        CheckDlgButton(wID, BST_UNCHECKED);
    }

    SetDirty(TRUE);
    return 0;
}


//-------------------------------------------------------------------------
// Opens the file selection dialogs
//-------------------------------------------------------------------------
LRESULT CBuildPPG::OnClickedOutpuPathB(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::OnClickedOutpuPathB \n") );

    HRESULT hr;
    int     id;
    CString strOutputPath;

    hr = BrowseForFolder(IDS_BROWSEFORFOLDERTITLE,m_hWnd, id, strOutputPath);
    if (id == IDOK)
    {
        // set the member
        m_strOutputPath = strOutputPath;
        m_fIsOutputPathChanged = TRUE;

        // set the edit box
        SetDlgItemText(IDC_OUTPUTPATH, m_strOutputPath);
        SetDirty(TRUE);
    }
    return 0;
}




    // command handler
LRESULT CBuildPPG::OnChangeOutputPath(  WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::OnChangeOutputPath \n") );

    BSTR bstr = NULL;
    GetDlgItemText(IDC_OUTPUTPATH, bstr);
    m_strOutputPath = bstr;
    m_fIsOutputPathChanged = TRUE;
    ::SysFreeString(bstr);

    SetDirty(TRUE);
    return 0;
}

//                                                         Command handlers
// ========================================================================


// ========================================================================
//                                                          Notify handlers

LRESULT CBuildPPG::OnChangeSourceFile(int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::OnChangeSourceFile \n") );

    // User has selected another source file

    LPNMTREEVIEW pnmtv = (LPNMTREEVIEW)pnmh;

#ifdef DEBUG
    TCHAR        szOld[_MAX_FNAME+1];
    TCHAR        szNew[_MAX_FNAME+1];

    TVITEM tviOld, tviNew;
    tviOld.mask = TVIF_HANDLE | TVIF_TEXT | TVIF_STATE;
    tviOld.hItem = pnmtv->itemOld.hItem;
    tviOld.pszText = szOld;
    tviOld.cchTextMax = _MAX_FNAME;
    TreeView_GetItem(m_hwndSourceFileTv, &tviOld);
    BOOL fOldSelected = TVIS_SELECTED & tviOld.state;

    tviNew.mask = TVIF_HANDLE | TVIF_TEXT | TVIF_STATE;
    tviNew.hItem = pnmtv->itemNew.hItem;
    tviNew.pszText = szNew;
    tviNew.cchTextMax = _MAX_FNAME;
    TreeView_GetItem(m_hwndSourceFileTv, &tviNew);
    BOOL fNewSelected = TVIS_SELECTED & tviNew.state;
#endif 



    CFileVwBaseNode * pfvbn = (CFileVwBaseNode *) pnmtv->itemNew.lParam;
    if (!pfvbn)
        return FALSE;

    CString strFullPath = pfvbn->GetFullPath();
    TCHAR pszFileExt[_MAX_EXT + 1];
    _tsplitpath(strFullPath,NULL,NULL,NULL, pszFileExt);


    // highlight the selection only if the new selection is a source file
    if (_tcsicmp(pszFileExt, _T(".myc")) == 0)
    {
        // set the source file member
        m_strSrcFile = strFullPath;
        m_fIsSrcFileChanged = TRUE;

        TreeView_EnsureVisible(m_hwndSourceFileTv, pnmtv->itemNew.hItem);
        TreeView_Select(m_hwndSourceFileTv, pnmtv->itemNew.hItem, TVGN_DROPHILITE);        
        UpdateOutputFileInUI();
        SetDirty(TRUE);
        return FALSE;
    }

    return TRUE;
}


//                                                          Notify handlers
// ========================================================================


// ========================================================================
//                                                        Private utilities

// reset all the flags for "changed" state to false
HRESULT CBuildPPG::ResetChangedStateFlags()
{
    m_fIsSrcFileChanged = FALSE;
    m_fIsOutputPathChanged = FALSE;
    return S_OK;
}


void CBuildPPG::SetDirty(BOOL bDirty)
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::SetDirty \n") );

    // overriden to update the command line and other read-only controls
    UpdateCommandLineInUI();
    UpdateOutputFileInUI();
    UpdateDebugInfoFileInUI();
    UpdateListingFileInUI();
    IMyCPrjPropertyPageImpl<CBuildPPG>::SetDirty(bDirty);
}


void CBuildPPG::UpdateCommandLineInUI()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::UpdateCommandLineInUI \n") );

    CString strTemp;
    UINT    uState;

    m_strBuildCommandLine = _T("");

    // project type
    strTemp = m_strProjectType;
    strTemp.MakeLower();
    if (! strTemp.IsEmpty())
    {
        m_strBuildCommandLine += _T(" /");
        m_strBuildCommandLine += strTemp;
    }

    // debug info
    uState = IsDlgButtonChecked(IDC_DEBUGCHECK);
    if (uState == BST_CHECKED )
        strTemp = _T(" /debug");
    else if (uState == BST_UNCHECKED)
        strTemp = _T(" /nodebug");
    else if (uState == BST_INDETERMINATE)
        strTemp = _T("");
    else 
        _ASSERT(FALSE);
    m_strBuildCommandLine += strTemp;

    // listing info
    uState = IsDlgButtonChecked(IDC_LISTINGCHECK);
    if (uState == BST_CHECKED )
        strTemp = _T(" /list");
    else if (uState == BST_UNCHECKED)
        strTemp = _T("");
    else if (uState == BST_INDETERMINATE)
        strTemp = _T("");
    else 
        _ASSERT(FALSE);
    m_strBuildCommandLine += strTemp;

    // output path
    if (! m_strOutputPath.IsEmpty())
    {
        m_strBuildCommandLine += _T(" /outdir:\"");
        m_strBuildCommandLine += m_strOutputPath;
        m_strBuildCommandLine += _T("\"");
    }

    // source file
    if (! m_strSrcFile.IsEmpty())
    {
        m_strBuildCommandLine += _T(" \"");
        m_strBuildCommandLine += m_strSrcFile;
        m_strBuildCommandLine += _T("\"");
    }

    // display the command line
    SetDlgItemText(IDC_CMDLINE, m_strBuildCommandLine);

}


// Generate the output file name
// This function needs to be called whenever the user changes the output project 
// type OR if the user changes the source file.
HRESULT CBuildPPG::UpdateOutputFileInUI()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::UpdateOutputFileInUI \n") );

    HRESULT hr = S_OK;
    CString strOutputFile;

    // m_strSrcFile and m_strProjectType can be blank for multiple selections
    if (!m_strSrcFile.IsEmpty() && !m_strProjectType.IsEmpty())
    {
        // get the filename
        TCHAR pszSrcFileBaseName[_MAX_FNAME + 1];
        _tsplitpath(m_strSrcFile,NULL,NULL,pszSrcFileBaseName, NULL);
        strOutputFile = pszSrcFileBaseName;
        strOutputFile += _T(".");
        strOutputFile += m_strProjectType;
    }

    // Set the output file text
    SetDlgItemText(IDC_OUTPUT_FILE, strOutputFile);

    return hr;
}


// Generate the debug info file name (.pdb)
// This function needs to be called whenever the user changes the source file 
// OR if the user changes the debug info check box.
HRESULT CBuildPPG::UpdateDebugInfoFileInUI()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::UpdateDebugInfoFileInUI \n") );

    HRESULT hr = S_OK;
    CString strDebugInfoFile;

    // get debug info checkbox state
    UINT uState = IsDlgButtonChecked(IDC_DEBUGCHECK);
    if (uState == BST_CHECKED )
        // m_strSrcFile can be blank for multiple selections
        if (!m_strSrcFile.IsEmpty() )
        {
            // get the filename
            TCHAR szBaseName[_MAX_FNAME+1];
            _tsplitpath(m_strSrcFile,NULL,NULL,szBaseName, NULL);
            strDebugInfoFile = _T("( ");
            strDebugInfoFile += szBaseName;
            strDebugInfoFile += _T(".pdb )");
        }

    // Set the debug info file name
    SetDlgItemText(IDC_DEBUGNAME, strDebugInfoFile);

    return hr;
}


// Generate the listing file name (.lst)
// This function needs to be called whenever the user changes the source file 
// OR if the user changes the listing file check box.
HRESULT CBuildPPG::UpdateListingFileInUI()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::UpdateListingFileInUI \n") );

    HRESULT hr = S_OK;
    CString strListingFile;

    // get debug info checkbox state
    UINT uState = IsDlgButtonChecked(IDC_LISTINGCHECK);
    if (uState == BST_CHECKED )
        // m_strSrcFile can be blank for multiple selections
        if (!m_strSrcFile.IsEmpty() )
        {
            // get the filename
            TCHAR szBaseName[_MAX_FNAME+1];
            _tsplitpath(m_strSrcFile,NULL,NULL,szBaseName, NULL);
            strListingFile  = _T("( ");
            strListingFile += szBaseName;
            strListingFile += _T(".lst )");
        }

    // Set the debug info file name
    SetDlgItemText(IDC_LISTINGNAME, strListingFile);

    return hr;
}




void CBuildPPG::GetDialogSize(const DLGTEMPLATE* pTemplate, SIZE* pSize)
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::GetDialogSize \n") );

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

//                                                        Private utilities
// ========================================================================


STDMETHODIMP CBuildPPG::Apply()
{
    ENVSDK_TRACE(atlTraceControls, TLF,  _T(": CBuildPPG::Apply \n") );

    HRESULT hr              = S_OK;
    BSTR    bstrSrcFile     = NULL;                 // source file to send
    BSTR    bstrProjectType = NULL;                 // project type to send 
    BSTR    bstrOutputPath  = NULL;                 // output path to send
    UINT    uState          = BST_INDETERMINATE;    // button state
    VARIANT_BOOL vb         = VARIANT_FALSE;         

    if (m_bDirty)
    {
        // allocate the bstr that we are going to send
        if (m_fIsSrcFileChanged && (! m_strSrcFile.IsEmpty()))
        {
            bstrSrcFile = m_strSrcFile.AllocSysString();
            IfFailAllocGo(bstrSrcFile);
        }

        if (! m_strProjectType.IsEmpty())
        {
            bstrProjectType = m_strProjectType.AllocSysString();
            IfFailAllocGo(bstrProjectType);
        }

        if (m_fIsOutputPathChanged && (! m_strOutputPath.IsEmpty()))
        {
            bstrOutputPath = m_strOutputPath.AllocSysString();
            IfFailAllocGo(bstrOutputPath);
        }

        for (UINT uObj = 0; uObj < m_nObjects; uObj++)
        {
            ExpectedExprGo(m_ppIMyCProjCfgProps[uObj] != NULL);
            // set the source file
            if (m_fIsSrcFileChanged)
            {
                // update it
                hr = m_ppIMyCProjCfgProps[uObj]->put_SourceFile(bstrSrcFile);
                _IfFailGo(hr);
            }

            // set the project type
            // if it is empty then:
            //      if single congiguration    - it has not been set 
            //      if multiple cinfigurations - it is not determined and it has not been changed  
            if (! m_strProjectType.IsEmpty())
            {
                // update it
                hr = m_ppIMyCProjCfgProps[uObj]->put_ProjectType(bstrProjectType);
                _IfFailGo(hr);
            }

            // set the output path
            if (m_fIsOutputPathChanged)
            {
                // update it
                hr = m_ppIMyCProjCfgProps[uObj]->put_OutputPath(bstrOutputPath);
                _IfFailGo(hr);
            }

            // set the debug info flag
            // if it is BST_INDETERMINATE then:
            //      it must be multiple cinfigurations and it is not determined 
            uState     = IsDlgButtonChecked(IDC_DEBUGCHECK);
            if (uState != BST_INDETERMINATE)
            {
                // update it
                vb = (uState == BST_CHECKED) ? VARIANT_TRUE : VARIANT_FALSE; 
                hr = m_ppIMyCProjCfgProps[uObj]->put_DebugInfoChecked(vb);
                _IfFailGo(hr);
            }

            // set the listing file flag
            // if it is BST_INDETERMINATE then:
            //      it must be multiple cinfigurations and it is not determined 
            uState     = IsDlgButtonChecked(IDC_LISTINGCHECK);
            if (uState != BST_INDETERMINATE)
            {
                // update it
                vb = (uState == BST_CHECKED) ? VARIANT_TRUE : VARIANT_FALSE; 
                hr = m_ppIMyCProjCfgProps[uObj]->put_ListingFileChecked(vb);
                _IfFailGo(hr);
            }

        }
    }

    // clear the flags for changed fields
    ResetChangedStateFlags();
    SetDirty(FALSE);

Error:
    ::SysFreeString(bstrSrcFile);
    ::SysFreeString(bstrProjectType);
    ::SysFreeString(bstrOutputPath);


    return hr;

}

