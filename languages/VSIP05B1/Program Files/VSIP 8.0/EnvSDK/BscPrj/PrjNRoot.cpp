
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNRoot.cpp : Implementation of CFileVwProjNode and interfaces

#include "stdafx.h"
#include "PrjInc.h"
#include "PrjNBase.h"
#include "PrjNRoot.h"
#include "PrjNFile.h"
#include "PrjNFolder.h"
#include "PrjHier.h"
#include "vspkg.h"


// Clipboard helper function
BOOL ClipboardHasDropFormat()
{
    BOOL fResult = FALSE;
    static UINT rgFormats[] = { CF_VSREFPROJECTITEMS, CF_VSSTGPROJECTITEMS, CF_HDROP };
    
    if (OpenClipboard(NULL))
    {
        fResult = (GetPriorityClipboardFormat(rgFormats, sizeof(rgFormats)/sizeof(UINT)) > 0);
        CloseClipboard();
    }
    return fResult;
}


CFileVwProjNode::CFileVwProjNode()
:
    m_guidProject(GUID_NULL)
{
    m_pCMyProjectHierarchy = NULL;
    m_fDirty = FALSE;
    m_pCVsTrackProjectDocuments2Helper = NULL;
}

CFileVwProjNode::~CFileVwProjNode()
{
    // Cleanup our kiddies with no notifications
    DeleteAll(NULL);
    ASSERT(m_srpProject == NULL);
    ASSERT(!m_pCVsTrackProjectDocuments2Helper);
}

//---------------------------------------------------------------------------
// Create & AddRef a File View project node & return it as an out param
//---------------------------------------------------------------------------
HRESULT CFileVwProjNode::CreateInstance
(
CMyProjectHierarchy *pCMyProjectHierarchy, 
LPCTSTR pszCaption,
LPCTSTR pszFullPath,
CFileVwProjNode **ppProjNode
)
{
    CComObject<CFileVwProjNode> *pProjNode = NULL;  // created with 0 ref cunt
    HRESULT hr = CComObject<CFileVwProjNode>::CreateInstance(&pProjNode);
    if (SUCCEEDED(hr))
    {
        pProjNode->AddRef();

        hr = pProjNode->Initialize(pCMyProjectHierarchy, pszCaption, pszFullPath);
        if (FAILED(hr))
        {
            pProjNode->Close();
            pProjNode->Release();
            pProjNode = NULL;
        }

    }
    *ppProjNode = pProjNode;
    return hr;
}

//---------------------------------------------------------------------------
// Initializing the project node only means to set its caption today.
//---------------------------------------------------------------------------
HRESULT CFileVwProjNode::Initialize
(
CMyProjectHierarchy *pCMyProjectHierarchy, 
LPCTSTR pszCaption,
LPCTSTR pszFullPath
)
{
    ExpectedPtrRet(pszCaption);
    ExpectedPtrRet(pszFullPath);

    HRESULT hr = S_OK;

    // check the path specified
    
    CString strFullPath;
    hr = GetFullLongFilePath(pszFullPath, strFullPath);
    IfFailRet(hr);
    LUtilFixFilename(strFullPath);// Remove trailing dots and spaces
    hr = CheckFileName(strFullPath);
    IfFailRet(hr);
    hr = CheckFileType(strFullPath);
    IfFailRet(hr);

    SetFullPath(strFullPath);
    SetName(pszCaption);
    m_pCMyProjectHierarchy = pCMyProjectHierarchy;    // hold un-addref'ed pointer

    CComPtr<IVsProject> srpIVsProject;
    hr = m_pCMyProjectHierarchy->QueryInterface(IID_IVsProject, (void**) &srpIVsProject);
    IfFailRet(hr);

    m_pCVsTrackProjectDocuments2Helper = new CVsTrackProjectDocuments2Helper(srpIVsProject);
    if (!m_pCVsTrackProjectDocuments2Helper)
    {
        ASSERT(FALSE);
        return E_OUTOFMEMORY;
    }       

    return S_OK;
}


HRESULT CFileVwProjNode::Close()
{
    // Close all children in this container.
    CHierNode* pNode = GetHead( /* BOOL fDisplayOnly */ FALSE);
    while (pNode != NULL)
    {
        // check the node type
        // note that it may be a folder node when folders are supported
        ASSERT(pNode->IsKindOf(Type_CFileVwFileNode) || pNode->IsKindOf(Type_CFileVwFolderNode));
        if(pNode->IsKindOf(Type_CFileVwFileNode))
        {
            CFileVwFileNode* pFileNode = static_cast<CFileVwFileNode*>(pNode);
            HRESULT hr = pFileNode->Close();
            ASSERT(SUCCEEDED(hr));
        }
        else if (pNode->IsKindOf(Type_CFileVwFolderNode))
        {
            CFileVwFolderNode* pFolderNode = static_cast<CFileVwFolderNode*>(pNode);
            ASSERT(SUCCEEDED(pFolderNode->Close()));
        }

        pNode = pNode->GetNext();
    }

    if (m_pCVsTrackProjectDocuments2Helper)
    {
        delete m_pCVsTrackProjectDocuments2Helper;
        m_pCVsTrackProjectDocuments2Helper = NULL; 
    }
    if (m_srpProject != NULL)
        static_cast<CAOProject*>((Project*)m_srpProject)->Close();
    m_srpProject.Release();
    return S_OK;
}



//---------------------------------------------------------------------------
// Override this function to say that we are a Root Node.
//---------------------------------------------------------------------------
VSITEMID CFileVwProjNode::GetVsItemID(void) const
{
    return VSITEMID_ROOT;
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
const GUID* CFileVwProjNode::PGuidGetType(void) const
{
    return &GUID_NODETYPE_FileVw_Project;
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
CVsHierarchy* CFileVwProjNode::GetCVsHierarchy(void) const
{
    return m_pCMyProjectHierarchy;
}


HRESULT CFileVwProjNode::GetFolderPath(CString& strFolderPath) const
{ 
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    strFolderPath = m_pCMyProjectHierarchy->GetProjectLocation();
    return S_OK;
}

UINT CFileVwProjNode::GetIconIndex(ICON_TYPE iconType) const
{
    return (iconType == ICON_StateImage) ?
            CFileVwBaseNode::GetIconIndex(iconType)
        :   GetImageList()->IImageFromPguidType(PGuidGetType());
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
STDMETHODIMP CFileVwProjNode::QueryStatus
(
const GUID*    pguidCmdGroup,
ULONG        cCmds,
OLECMD        prgCmds[],
OLECMDTEXT*    pCmdText
)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pguidCmdGroup);
    ExpectedPtrRet(prgCmds);
    ExpectedExprRet(1 == cCmds);
    QUERY_STATUS_CHECK;

    OLECMD& Cmd = prgCmds[0];

    HRESULT hr = S_OK;
    BOOL fSupported = FALSE;
    BOOL fEnabled = FALSE;
    BOOL fInvisible = FALSE;
    
    if(*pguidCmdGroup == guidVSStd97)
    {
        switch(Cmd.cmdID)
        {
            case cmdidAddNewItem:
            case cmdidAddExistingItem:
            case cmdidNewFolder:
                fSupported =  TRUE;
                fEnabled = TRUE;
                break;
            case cmdidPaste:
                fSupported =  TRUE;
                fEnabled = ClipboardHasDropFormat();
                break;
            default:
                hr = OLECMDERR_E_NOTSUPPORTED;
                break;
        }
    }
    
    else 
    {
        hr = OLECMDERR_E_NOTSUPPORTED;
    }
    if (SUCCEEDED(hr) && fSupported)
    {
        Cmd.cmdf = OLECMDF_SUPPORTED;
        if (fInvisible)
            Cmd.cmdf |= OLECMDF_INVISIBLE;
        else if (fEnabled)
            Cmd.cmdf |= OLECMDF_ENABLED;
    }

    if (hr == OLECMDERR_E_NOTSUPPORTED)
        hr = CFileVwBaseNode::QueryStatus(pguidCmdGroup, cCmds, prgCmds, pCmdText);

    return hr;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
STDMETHODIMP CFileVwProjNode::Exec
(
const GUID*    pguidCmdGroup,
DWORD        nCmdID,
DWORD        nCmdexecopt,
VARIANT*    pvaIn,
VARIANT*    pvaOut
)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    if (!pguidCmdGroup)
        return E_INVALIDARG;
    
    HRESULT hr = OLECMDERR_E_NOTSUPPORTED;

    if (*pguidCmdGroup == guidVSStd97)
    {
        hr = S_OK;
        switch(nCmdID)
        {
            case cmdidAddNewItem:
            case cmdidAddExistingItem:
                hr = OnCmdAddItem(nCmdID == cmdidAddNewItem);
                break;

            case cmdidNewFolder:
                hr = OnCmdAddFolder();
                break;

            default:
                hr = OLECMDERR_E_NOTSUPPORTED;
                break;
        }
    }

    if (hr == OLECMDERR_E_NOTSUPPORTED)
        hr = CFileVwBaseNode::Exec(pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut);

    return hr;
}






//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
HRESULT CFileVwProjNode::GetGuidProperty(VSHPROPID propid, GUID* pGuid) const
{
    ASSERT(pGuid);
    if (!pGuid)
        return E_INVALIDARG;
    *pGuid = GUID_NULL;

    HRESULT hr = S_OK;

    switch (propid)
    {
        case VSHPROPID_TypeGuid:
            *pGuid = GUID_NODETYPE_FileVw_Project;
            break;
        case VSHPROPID_ProjectIDGuid:
            if (m_guidProject != GUID_NULL)
                *pGuid = m_guidProject;
            else
                hr = E_FAIL;
            break;
        default:
            hr = DISP_E_MEMBERNOTFOUND;
            break;
    }
    return hr;
}


HRESULT CFileVwProjNode::SetGuidProperty(
    /* [in] */ VSHPROPID propid,
    /* [in] */ REFGUID   guid)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    switch (propid)
    {
        case VSHPROPID_ProjectIDGuid:

            if (guid == m_guidProject)
                return S_OK;

            if (m_guidProject != GUID_NULL)
            {
                ASSERT(FALSE); // the project id guid is already set
                return E_FAIL;
            }

            if (m_pCMyProjectHierarchy->NewProject())
            {
                SetProjectFileDirty(TRUE);
            }

            m_guidProject = guid;

            return S_OK;

        default:
            break;
    }

    ATLTRACENOTIMPL(_T("CFileVwProjNode::SetGuidProperty (IVsHierarchy)"));
}

//---------------------------------------------------------------------------
//    Returns requested guid property
//---------------------------------------------------------------------------
HRESULT CFileVwProjNode::GetProperty(VSHPROPID propid, VARIANT* pvar)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ASSERT(pvar);
    if (!pvar)
        return E_INVALIDARG;
    VariantInit(pvar);

    HRESULT hr = S_OK;
    switch (propid)
    {
    case VSHPROPID_ProjectDir:
        V_VT(pvar) = VT_BSTR;
        V_BSTR(pvar) = m_pCMyProjectHierarchy->GetProjectLocation().AllocSysString();
        if (!pvar->bstrVal) hr = E_OUTOFMEMORY;
        break;

    case VSHPROPID_ExtObject:
        hr = GetAutomationObject(&V_DISPATCH(pvar));
        IfFailGo(hr);
        V_VT(pvar) = VT_DISPATCH;
        break;

    case VSHPROPID_TypeName:
        {
            CString strTypeName;
            if (!strTypeName.LoadString(IDS_PROJECT_TYPE))
            {
                hr = E_FAIL;
                break;
            }

            V_VT(pvar) = VT_BSTR;
            V_BSTR(pvar) = strTypeName.AllocSysString();
            if (!pvar->bstrVal) hr = E_OUTOFMEMORY;
        }
        break;

    case VSHPROPID_StartupServices:
        hr = m_pCMyProjectHierarchy->QueryInterface(
                                IID_IVsProjectStartupServices, 
                                (void **)&V_UNKNOWN(pvar));
        if (SUCCEEDED(hr))
            V_VT(pvar) = VT_UNKNOWN;
        else
            ::VariantInit(pvar);
        break;

    default:    // Delegate
        hr = CFileVwBaseNode::GetProperty(propid, pvar);
    }
Error:
    return hr;
}


//---------------------------------------------------------------------------
// VSHPROPID_EditLabel - called by CVSHierarchy.
//---------------------------------------------------------------------------
HRESULT CFileVwProjNode::GetEditLabel(BSTR *pbstrLabel)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    CString strNewName;
    
    ASSERT(NULL != pbstrLabel && NULL == *pbstrLabel);
    strNewName = GetName();
    *pbstrLabel = strNewName.AllocSysString();
    return (*pbstrLabel) ? S_OK : E_OUTOFMEMORY;
} // CFileVwFileNode::GetEditLabel


HRESULT CFileVwProjNode::SetEditLabel(BSTR bstrLabel)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    return RenameProject(bstrLabel);
}


//-----------------------------------------------------------------------------
// Renames the project.
//-----------------------------------------------------------------------------
HRESULT CFileVwProjNode::RenameProject(BSTR bstrNewPrjName)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;


    HRESULT hr = E_FAIL;

    // check the file name
    CString strNewName(bstrNewPrjName);     // new short project name
    // cleanup the filename
    LUtilFixFilename(strNewName);

    if(strNewName.IsEmpty())
    {
        CString msg;
        VxFormatString1(msg, IDS_E_NEEDTOENTERFILENAME, strNewName);
        _VxModule.SetErrorInfo(hr, msg, 0);
        return hr;
    }
    else if(strNewName[0] == L'.')
    {   // project names cannot begin with a period
        _VxModule.SetErrorInfo(hr, IDS_E_NOLEADINGPERIOD, 0);
        return hr;
    }

    // See if new name has an extension and that it is the right one.
    CString strDefaultProjectExtension;     // default extension for our project
    GetDefaultProjectExtension(strDefaultProjectExtension);
    const TCHAR*  pszExt = _tcsrchr((LPCTSTR)strNewName, L'.');
    if(pszExt == NULL || _tcsicmp(pszExt, strDefaultProjectExtension) != 0 )
        strNewName += strDefaultProjectExtension;

    CString strOldName = GetFileName();     // old short project name
    if(strNewName == strOldName)// No name change.
        return S_OK;

    hr = CheckFileName(strNewName);
    if (FAILED(hr))// Bad filename chars
    {   
        CString msg;
        VxFormatString1(msg, IDS_INVALIDFILENAME, strNewName);
        _VxModule.SetErrorInfo(hr,msg, 0);
        return hr;
    }

    CString strNewFullName;
    IfFailRet(GetFolderPath(strNewFullName));
    strNewFullName += strNewName;// new full name (incl. path)
    // check if it exist
    HANDLE hFile = ::CreateFile(strNewFullName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        CloseHandle(hFile);
        CString msg;
        VxFormatString1(msg, IDS_RENAMEFILEALREADYEXISTS, strNewFullName);
        hr = E_FAIL;
        _VxModule.SetErrorInfo(hr, msg, 0);
        return hr;
    }

    // now ask to rename the file
    CString strOldFullName = GetFullPath(); // old full name (incl. path)
    BOOL    fRenameCanCont  = FALSE;        // flag "Rename Can Continue"
    CComPtr<IVsProject>  srpIVsProject;
    ExpectedExprRet(m_pCMyProjectHierarchy != NULL);
    hr = m_pCMyProjectHierarchy->QueryInterface(IID_IVsProject, (void**)&srpIVsProject);
    IfFailRet(hr); ExpectedExprRet(srpIVsProject != NULL);

    // Need to ensure we can checkout the solution since it needs to be updated to 
    // reflect the new project filename.
    IVsSolution* pIVsSolution = _VxModule.GetIVsSolution();
    ExpectedExprRet(pIVsSolution != NULL);
    hr = pIVsSolution->QueryRenameProject(
        srpIVsProject, 
        strOldFullName, 
        strNewFullName, 
        0,
        &fRenameCanCont);
    if(FAILED(hr) || !fRenameCanCont)
        return OLE_E_PROMPTSAVECANCELLED;

    // now move the file
    if (!MoveFile(strOldFullName,strNewFullName))
        return UtilSetWin32Err(GetLastError(), IDS_E_RENAMINGITEM, strOldName);

    // make sure it is file on disk
    hr = CheckFileType(strNewFullName);
    IfFailRet(hr);

    // Bookkeeping time. We need to update our project name, our title, 
    // and force our rootnode to update its caption.
    TCHAR szNewFileNameNoExt[_MAX_FNAME];
    _tsplitpath(strNewFullName, NULL, NULL, szNewFileNameNoExt, NULL);
    SetName(szNewFileNameNoExt); // set m_strName
    SetFullPath(strNewFullName); // set m_strFullPath & m_strFileName

    // rename the project data in the hier
    m_pCMyProjectHierarchy->OnProjectRenamed(); 
    
    // Make sure the property browser is updated
    IVsUIShell* pIVsUIShell = _VxModule.GetIVsUIShell();
    if (pIVsUIShell)
        pIVsUIShell->RefreshPropertyBrowser(DISPID_VALUE);

    // Let the world know that the project is renamed
    // Solution needs to be told of rename. 
    HRESULT hrTemp = pIVsSolution->OnAfterRenameProject(
            srpIVsProject, 
            strOldFullName,
            strNewFullName, 
            0);  
    ASSERT(SUCCEEDED(hrTemp));

    // Fire OnPropertyChanged
    // ReDraw will cause GetIconIndex, which updates the glyphs to be called
    ReDraw( 
        /* bUpdateIcon      (VSHPROPID_IconIndex)      */ FALSE, 
        /* bUpdateStateIcon (VSHPROPID_StateIconIndex) */ TRUE, 
        /* bUpdateText      (VSHPROPID_Caption)           */ TRUE);

    //Fire an event to extensibility
    CAutomationEvents::FireProjectsEvent(
        this, 
        CAutomationEvents::ProjectsEventsDispIDs::ItemRenamed,
        strOldFullName);
    
    return hr;    
}


HRESULT CFileVwProjNode::GetDefaultProjectExtension(CString& strExt)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    strExt = _T(".bscp");
    return S_OK;
}



BOOL CFileVwProjNode::QueryEditProjectFile()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // If the file is already dirty, then just return true
    if (IsProjectFileDirty())
        return TRUE;

    if(GetCVsHierarchy()->IsClosed() || GetCVsHierarchy()->IsZombie())
    {
        // We're already zombied. Better return FALSE.
        return FALSE;
    }

    // get IVsQueryEditQuerySave2
    CComPtr<IVsQueryEditQuerySave2> srpIVsQueryEditQuerySave2;
    HRESULT hr = _VxModule.QueryService(
        SID_SVsQueryEditQuerySave, 
        IID_IVsQueryEditQuerySave2,
        (void**)&srpIVsQueryEditQuerySave2);
    // if we did not get it return true
    ASSERT(SUCCEEDED(hr) && srpIVsQueryEditQuerySave2);
    if (FAILED(hr) || !srpIVsQueryEditQuerySave2)
        return TRUE;

    // now ask for edit
    USES_CONVERSION;
    VSQueryEditFlags  rgfQueryEdit = QEF_DisallowInMemoryEdits;
    VSQueryEditResult fEditVerdict;
    LPCOLESTR pszFileName = T2COLE(GetFullPath());
    hr = srpIVsQueryEditQuerySave2->QueryEditFiles(
        /* [in] VSQueryEditFlags rgfQueryEdit                */ rgfQueryEdit,
        /* [in] int cFiles                                   */ 1,            // File count
        /* [in] const LPCOLESTR rgpszMkDocuments[]           */ &pszFileName, // File to process
        /* [in] const VSQEQSFlags rgrgf[]                    */ NULL,         // Valid file attributes?
        /* [in] const VSQEQS_FILE_ATTRIBUTE_DATA rgFileInfo[]*/ NULL,         // File attributes
        /* [out] VSQueryEditResult *pfEditVerdict            */ &fEditVerdict,// Proceed with edit or cancel
        /* [out] VSQueryEditResultFlags *prgfMoreInfo        */    NULL);
    // Return FALSE if we cannot edit the project file or the project file is reloaded
    if (FAILED(hr) || (fEditVerdict != QER_EditOK))
        return FALSE;
    if(GetCVsHierarchy()->IsClosed() || GetCVsHierarchy()->IsZombie())
    {
        // The project file has probably been reloaded. Return FALSE.
        return FALSE;
    }

    return TRUE;
}


STDMETHODIMP CFileVwProjNode::GetAutomationObject(
        /* [out] */ IDispatch ** ppIDispatch)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(ppIDispatch);
    InitParam(ppIDispatch);

    HRESULT hr = S_OK;

    if (m_srpProject == NULL)
    {
        hr = CAOProject::CreateInstance(this, &m_srpProject);
        IfFailRet(hr);
        ExpectedExprRet(m_srpProject);
    }

    return m_srpProject->QueryInterface(IID_IDispatch, (void**)ppIDispatch);
}


IVsHierarchy* CFileVwProjNode::GetIVsHierarchy()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return NULL;

    ASSERT(m_pCMyProjectHierarchy);
    if (!m_pCMyProjectHierarchy)
        return NULL;
    return m_pCMyProjectHierarchy->GetIVsHierarchy();
}
