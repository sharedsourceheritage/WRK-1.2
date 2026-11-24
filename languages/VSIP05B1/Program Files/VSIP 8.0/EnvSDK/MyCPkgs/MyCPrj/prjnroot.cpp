
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNRoot.cpp : Implementation of CFileVwProjNode and interfaces

#include "stdafx.h"
#include "PrjInc.h" 


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
    ASSERT(!m_srpProject);
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
	m_pCMyProjectHierarchy = pCMyProjectHierarchy;	// hold un-addref'ed pointer

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
        ASSERT(pNode->IsKindOf(Type_CFileVwFileNode));
	    if(pNode->IsKindOf(Type_CFileVwFileNode))
        {
            CFileVwFileNode* pFileNode = static_cast<CFileVwFileNode*>(pNode);
            HRESULT hr = pFileNode->Close();
            ASSERT(SUCCEEDED(hr));
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


const CString& CFileVwProjNode::GetFolderPath(void) const 
{ 
	return m_pCMyProjectHierarchy->GetProjectLocation(); 
}

UINT CFileVwProjNode::GetIconIndex(ICON_TYPE iconType) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    return (iconType == ICON_StateImage) ?
            CFileVwBaseNode::GetIconIndex(iconType)
        :   GetImageList()->IImageFromPguidType(PGuidGetType());
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
STDMETHODIMP CFileVwProjNode::QueryStatus
(
const GUID*	pguidCmdGroup,
ULONG		cCmds,
OLECMD		prgCmds[],
OLECMDTEXT*	pCmdText
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
const GUID*	pguidCmdGroup,
DWORD		nCmdID,
DWORD		nCmdexecopt,
VARIANT*	pvaIn,
VARIANT*	pvaOut
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
// CFileVwProjNode::OnCmdAddItem
//-----------------------------------------------------------------------------
HRESULT CFileVwProjNode::OnCmdAddItem
(
BOOL fAddNewItem,
LPCOLESTR pszSelectItem /* = NULL */,
LPCOLESTR pszExpandDir /* = NULL */
)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

//    static CComBSTR bstrLocation;    // location field (initial/final value); valid if ShowLocationField set
    static CComBSTR bstrFilter;      // filter string (initial/final value); valid if AllowStickyFilter set

	if (!bstrFilter)
	{
		// bstrLocation = static_cast<CMyProjectHierarchy*>(GetCVsHierarchy())->GetProjectLocation();
		bstrFilter = "";
	}

	CComPtr<IVsAddProjectItemDlg> srpAddItemDlg;
	HRESULT hr = _VxModule.QueryService(
			SID_SVsAddProjectItemDlg,
			IID_IVsAddProjectItemDlg,
			(void**)&srpAddItemDlg);

	if (SUCCEEDED(hr))
	{
		ASSERT(srpAddItemDlg);
		DWORD dwFlags;
		if (fAddNewItem)
			dwFlags = VSADDITEM_AddNewItems | VSADDITEM_SuggestTemplateName; /* | VSADDITEM_ShowLocationField */
		else
			dwFlags = VSADDITEM_AddExistingItems | VSADDITEM_AllowMultiSelect | VSADDITEM_AllowStickyFilter;

		hr = srpAddItemDlg->AddProjectItemDlg(
				GetVsItemID(),
				GUID_MyProjectType, 
				QI_cast<IVsProject>(GetCVsHierarchy()),
				dwFlags,
				pszExpandDir,
				pszSelectItem,
				NULL /*&bstrLocation*/,
				&bstrFilter,
				NULL /*&fDontShowAgain*/);

		// NOTE: AddItem() will be called via the hierarchy IVsProject to add items.
	}

	return hr;
}


//-----------------------------------------------------------------------------
// CFileVwProjNode::AddItem
//-----------------------------------------------------------------------------
HRESULT CFileVwProjNode::AddItem(
    /* [in]                        */ VSADDITEMOPERATION    dwAddItemOperation,
    /* [in]                        */ LPCOLESTR             pszItemName,
    /* [in]                        */ ULONG                 cFilesToOpen,
    /* [in, size_is(cFilesToOpen)] */ LPCOLESTR             rgpszFilesToOpen[],
    /* [in]                        */ HWND                  hwndDlg,
    /* [in]                        */ VSSPECIFICEDITORFLAGS grfEditorFlags,
    /* [in]                        */ REFGUID               rguidEditorType,
    /* [in]                        */ LPCOLESTR             pszPhysicalView,
    /* [in]                        */ REFGUID               rguidLogicalView,
    /* [out, retval]               */ VSADDRESULT *         pResult)
{ 
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(rgpszFilesToOpen);
    ExpectedPtrRet(pResult);
	*pResult = ADDRESULT_Failure;

	HRESULT hr     = S_OK;
    HRESULT hrTemp = S_OK;
    USES_CONVERSION;

	CExecution singleEx(&GetExecutionCtx());
	
	// Return if the project file is not editable or the project file was reloaded
	if ( !QueryEditProjectFile() )
		return OLE_E_PROMPTSAVECANCELLED;
	
	switch(dwAddItemOperation)
	{
    case VSADDITEMOP_LINKTOFILE:
		// because we are a reference-based project system our handling for 
        // LINKTOFILE is the same as OPENFILE. 
        // a storage-based project system which handles OPENFILE by copying 
		// the file into the project directory would have distinct handling 
        // for LINKTOFILE vs. OPENFILE.
		// we fall through to VSADDITEMOP_OPENFILE....

	case VSADDITEMOP_OPENFILE:
	case VSADDITEMOP_CLONEFILE:
        {
            BOOL fNewFile = (dwAddItemOperation == VSADDITEMOP_CLONEFILE);

            for(DWORD i=0; i < cFilesToOpen; i++)
		    {
                CFileVwFileNode* pNewNode = NULL;

                if (fNewFile)
                {
		            ASSERT(cFilesToOpen == 1);
		            ASSERT(rgpszFilesToOpen[0]);
		            ASSERT(pszItemName);

		            hrTemp = AddNewFile(
                        OLE2CT(rgpszFilesToOpen[0]), 
                        OLE2CT(pszItemName), 
                        &pNewNode);
                }
                else
                {
                    // create and add node for the existing file to the project
                    hrTemp = AddExistingFile(OLE2CT(rgpszFilesToOpen[i]), &pNewNode);
                }
                if( FAILED(hrTemp) )
                {
                    // This means that we return an error code if even one 
                    // of the Items failed to Add (in the add exisitng files case)
                    hr = hrTemp;
                    continue;
                }

                // we should have a new file node at this point
                ASSERT(pNewNode);
                if (!pNewNode)
                    continue;

                // we are not opening an existing file if an editor is not specified
                if ( (!fNewFile) && (rguidEditorType == GUID_NULL) )
                    continue;

                // open the item
                ASSERT(grfEditorFlags & VSSPECIFICEDITOR_DoOpen);
                CComPtr<IVsWindowFrame> srpWindowFrame;
                if(grfEditorFlags & VSSPECIFICEDITOR_UseView)
                {   
                    // Standard open file
			        hrTemp = pNewNode->OpenDoc(
				        fNewFile /*fNewFile*/, 
				        FALSE    /*fUseOpenWith*/,
                        TRUE     /*fShow*/,
				        rguidLogicalView,
				        NULL, 
				        &srpWindowFrame);
                }
                else
                {   
                    hrTemp = pNewNode->OpenDocWithSpecific(
                        /* REFGUID           rguidEditorType    */ rguidEditorType, 
                        /* LPCOLESTR         pszPhysicalView    */ pszPhysicalView,
                        /* REFGUID           rguidLogicalView   */ rguidLogicalView, 
                        /* IUnknown *        punkDocDataExisting*/ NULL,
                        /* IVsWindowFrame ** ppWindowFrame      */ &srpWindowFrame,        
                        /* BOOL              fShowWindow = TRUE */ TRUE,
                        /* BOOL              fNewFile    = FALSE*/ fNewFile);
                }
                if (FAILED(hrTemp))
                {
                    // These don't affect the return value of this function because 
                    // by this stage the file has been sucessfully added to the project.
                    // But the problem can be reported to the user.
                }
		    }
        }
		break;
	
	case VSADDITEMOP_RUNWIZARD: // Wizard was selected		
        return RunWizard(
            /* [in]  LPCOLESTR     pszItemName       */ pszItemName,
            /* [in]  ULONG         cFilesToOpen      */ cFilesToOpen,
            /* [in]  LPCOLESTR     rgpszFilesToOpen[]*/ rgpszFilesToOpen,
            /* [in]  HWND          hwndDlg           */ hwndDlg,
            /* [out] VSADDRESULT * pResult           */ pResult);
	default:
		*pResult = ADDRESULT_Failure;
		hr = E_INVALIDARG;
	}

	if (SUCCEEDED(hr))
		*pResult = ADDRESULT_Success;

	if(GetExecutionCtx().IsCancelled() || hr == E_ABORT || hr == OLE_E_PROMPTSAVECANCELLED)
    {
		*pResult = ADDRESULT_Cancel;	
        hr = S_OK;
    }

	return hr;
}


//-----------------------------------------------------------------------------
// CFileVwProjNode::AddExistingFile
//-----------------------------------------------------------------------------
HRESULT CFileVwProjNode::AddExistingFile
(
    LPCTSTR pszFullPathSource,
    CFileVwFileNode **ppNewFile,
    BOOL fSilent, /* = FALSE */
    BOOL fLoad    /* = FALSE */
) 
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pszFullPathSource);

	HRESULT hr = NOERROR;

	// get the proper file name
	CString strFullPath;

    // If we are loading the files when opening an existing project then 
    // we do not check for the existence of the file.
    if (fLoad)
    {
        strFullPath = pszFullPathSource;
    }
    else
    {
	    hr = GetFullLongFilePath(pszFullPathSource, strFullPath);
	    IfFailRet(hr); 
    }
    LUtilFixFilename(strFullPath);// Remove trailing dots and spaces

	// check if such an item exist
    if (GetNodeByFullPath(strFullPath) != NULL)
    {
		// Tell the caller that the filename is already a member of the project.
		CString strMsg;
		VxFormatString1(strMsg, IDS_FILEALREADYEXISTS, strFullPath);
		_VxModule.SetErrorInfo(E_FAIL, strMsg, 0 /*dwHelpContextID */);
		return E_FAIL;
    }

	// check the file name
	hr = CheckFileName(strFullPath);
	IfFailRet(hr);

	// check the file type if we are not merely opening an existing project
    if (!fLoad)
    {
	    hr = CheckFileType(strFullPath);
	    IfFailRet(hr);
    }

    // the file looks ok

    if (!fSilent)
    {
        ExpectedPtrRet(m_pCVsTrackProjectDocuments2Helper);
        hr = m_pCVsTrackProjectDocuments2Helper->CanAddItem(T2COLE(strFullPath));
        _IfFailRet(hr);
    }

	CFileVwFileNode * pNewFile = NULL;
	hr = CFileVwFileNode::CreateInstance(strFullPath, &pNewFile);
	if (SUCCEEDED(hr))
	{
		ASSERT(pNewFile);
		Add(pNewFile);
        if (!fSilent)
        {
            m_pCVsTrackProjectDocuments2Helper->OnItemAdded(pNewFile);

		    //Fire an event to extensibility
            CAutomationEvents::FireProjectItemsEvent(
                pNewFile, 
                CAutomationEvents::ProjectItemsEventsDispIDs::ItemAdded);
        }
	}

	if (ppNewFile)
		*ppNewFile = pNewFile;
    
    if (SUCCEEDED(hr))
	{
		// Since our expandable status may have changed, 
		// we need to refresh it in the UI
        GetCVsHierarchy()->OnPropertyChanged(this, VSHPROPID_Expandable, 0);

        SetProjectFileDirty(TRUE);
	}

	return hr;
}


//-----------------------------------------------------------------------------
// CFileVwProjNode::AddNewFile
//-----------------------------------------------------------------------------
HRESULT CFileVwProjNode::AddNewFile(
    LPCTSTR pszFullPathSource,
    LPCTSTR pszNewFileName,
    CFileVwFileNode** ppNewNode) 
{ 
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	ASSERT(pszFullPathSource);
	ASSERT(pszNewFileName);
	if (!pszFullPathSource || !pszNewFileName)
		return E_INVALIDARG;

	USES_CONVERSION;

	HRESULT hr = NOERROR;

	CString strNewFileName = pszNewFileName;
	LUtilFixFilename(strNewFileName);// Remove trailing dots and spaces
	hr = CheckFileName(strNewFileName);
	if (FAILED(hr))
	{
		// Tell the caller that the filename isn't valid.
		CString strMsg;
		VxFormatString1(strMsg, IDS_INVALIDFILENAME, strNewFileName);
		_VxModule.SetErrorInfo(hr, strMsg, 0 /*dwHelpContextID*/);
		return hr;
	}

	CString strFullPathSource(pszFullPathSource);
	CString strFullPathTarget = GetFolderPath();
	strFullPathTarget += strNewFileName;	    // Get the target path
	
    // If target != source then we need to copy
    if (strFullPathTarget.CompareNoCase(strFullPathSource))
    {
		BOOL fCopied = TRUE;
		BOOL bStatus = FALSE;
		// Don't force an overwrite.
		bStatus = ::CopyFile(strFullPathSource, strFullPathTarget, TRUE);
 
		// Overwrite case
		if (!bStatus)
		{
			CString strMsg;
			VxFormatString1(strMsg, IDS_CONFIRMREPLACE, strNewFileName);
            ASSERT(!strMsg.IsEmpty());

            CString strCaption;
            if (!strCaption.LoadString(IDS_CONFIRMREPLACE_CAPTION))
                return E_FAIL;
            ASSERT(!strCaption.IsEmpty());

            int msgRet = UtilMessageBox(
                                strMsg, 
                                MB_YESNOCANCEL | MB_ICONEXCLAMATION, 
                                strCaption);

            if (msgRet == IDYES)
			{
	    		bStatus = ::CopyFile(strFullPathSource, strFullPathTarget, FALSE);
			}
            else if (msgRet == IDNO)
            {
                bStatus = TRUE;
                fCopied = FALSE;
            }
            else if (msgRet == IDCANCEL)
                return E_ABORT;
			else
			{
				ASSERT(FALSE);
				return E_FAIL;
			}
        }
        if (!bStatus)
        {
            LUtilSetWin32Err(IDS_E_COPY_FAILED, strNewFileName);
            return E_FAIL;
        }

	    // template was read-only, but our file should not be
        if (fCopied)
	        SetFileAttributes(strFullPathTarget, FILE_ATTRIBUTE_ARCHIVE);
    }

	// Now that we have made a copy of the template file, let's add our new file to the project
	hr = AddExistingFile(strFullPathTarget, ppNewNode);

	return hr;
}


HRESULT CFileVwProjNode::RunWizard(
    /* [in]                        */ LPCOLESTR             pszItemName,
    /* [in]                        */ ULONG                 cFilesToOpen,
    /* [in, size_is(cFilesToOpen)] */ LPCOLESTR             rgpszFilesToOpen[],
    /* [in]                        */ HWND                  hwndDlg,
    /* [out, retval]               */ VSADDRESULT *         pResult)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedExprRet(cFilesToOpen >= 1); // Must add at least one file here...
    ExpectedPtrRet(pResult);
    *pResult = ADDRESULT_Failure;

    HRESULT hr = S_OK;
    USES_CONVERSION;

	hr = CheckFileName(pszItemName);
    if(FAILED(hr))
    {
        LUtilSetErrString1(IDS_INVALIDFILENAME, OLE2CT(pszItemName));
        return hr;
    }

    CComPtr<VxDTE::IVsExtensibility> srpIVsExtensibility;
    hr = _VxModule.QueryService(
        VxDTE::SID_SVsExtensibility, 
        VxDTE::IID_IVsExtensibility, 
        (void **)&srpIVsExtensibility);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsExtensibility != NULL);

    SAFEARRAYBOUND sab = { 6, 0 };
    SAFEARRAY *psa = ::SafeArrayCreate(VT_VARIANT, 1, &sab);
    ASSERT(psa != NULL);
    if (psa == NULL)
        return E_OUTOFMEMORY;

    // Now we build up the ContextParams safearray
    //  [0] = Wizard type guid  (bstr)
    //  [1] = Project name  (bstr)
    //  [2] = ProjectItems collection (IDispatch)
    //  [3] = Local Directory (bstr)
    //  [4] = Filename the user typed (bstr)
    //  [5] = Product install Directory (bstr)

    // The first filename is the name of the wizard
    CComPtr<IDispatch>        srpIDispatch_Project;
    CComPtr<VxDTE::Project>   srpProject;
    VxDTE::ProjectItems*      pProjectItems = NULL;

    // The first filename is the name of the wizard
    CComBSTR cbstrWizardName(rgpszFilesToOpen[0]);
    CString  strInstallDir;
    CString  strProjectDir;

    // [0] = Wizard type guid  (bstr)
    long index = 0;
    #define GUID_AddItemWizard  L"{0F90E1D1-4999-11D1-B6D1-00A0C90F2744}"
    CComVariant cvar(GUID_AddItemWizard);
    hr = ::SafeArrayPutElement(psa, &index, &cvar);
    IfFailGo(hr);

    //  [1] = Project name  (bstr)
    index++;
    cvar = (LPCTSTR)GetName();
    hr = ::SafeArrayPutElement(psa, &index, &cvar);
    IfFailGo(hr);

    //  [2] = ProjectItems collection (IDispatch)
    index++;
    hr = GetAutomationObject(&srpIDispatch_Project);
    IfFailGo(hr);
    ExpectedExprGo(srpIDispatch_Project != NULL);
    hr = srpIDispatch_Project->QueryInterface(VxDTE::IID__Project, (void **)&srpProject);
    IfFailGo(hr);
    ExpectedExprGo(srpProject != NULL);
    hr = srpProject->get_ProjectItems(&pProjectItems);
    IfFailGo(hr);
    if (pProjectItems)
    {
        CComPtr<IDispatch> srpIDispatch_ProjectItems;
        srpIDispatch_ProjectItems.p = static_cast<IDispatch*>(pProjectItems);
        cvar = (IDispatch*)srpIDispatch_ProjectItems;
        hr = ::SafeArrayPutElement(psa, &index, &cvar);
        IfFailGo(hr);
    }
    else
    {
        hr = ::SafeArrayPutElement(psa, &index, NULL);
        IfFailGo(hr);
    }

    //  [3] = Local Directory (bstr)
    index++;
	strProjectDir = GetFolderPath();
    cvar = (LPCTSTR)strProjectDir;
    hr = ::SafeArrayPutElement(psa, &index, &cvar);
    IfFailGo(hr);
    
    //  [4] = Filename the user typed (bstr)
    index++;
    cvar = pszItemName;
    hr = ::SafeArrayPutElement(psa, &index, &cvar);
    IfFailGo(hr);

    //  [5] = Product install Directory (bstr)
    index++;
    hr = GetInstallLocation(strInstallDir);
    IfFailGo(hr);
    cvar = (LPCTSTR)strInstallDir;
    hr = ::SafeArrayPutElement(psa, &index, &cvar);
    IfFailGo(hr);

    // now run the wizard file
    VxDTE::wizardResult eExecResult;
    hr = srpIVsExtensibility->RunWizardFile(
        /* [in] BSTR                 bstrWizFilename*/ cbstrWizardName, 
        /* [in] long                 hwndOwner      */ HandleToLong(hwndDlg), 
        /* [in] SAFEARRAY (VARIANT)* vContextParams */ &psa, 
        /* [out, retval] wizardResult *pResult      */ &eExecResult);

    if(SUCCEEDED(hr))
    {
        if(eExecResult == VxDTE::wizardResultSuccess)
            *pResult = ADDRESULT_Success;
        else if(eExecResult == VxDTE::wizardResultFailure)
            *pResult = ADDRESULT_Failure;
        else if(eExecResult == VxDTE::wizardResultCancel)
        {
            *pResult = ADDRESULT_Cancel;
            hr = OLE_E_PROMPTSAVECANCELLED;
        }
    }
    else
    {
        *pResult = ADDRESULT_Failure;
        
        CComPtr<IErrorInfo> srpiErrInfo;
        HRESULT hrError = ::GetErrorInfo(0, &srpiErrInfo);
        if (SUCCEEDED(hrError) && !srpiErrInfo)
        {
            LUtilSetErrString1(IDS_E_RUNWIZARD, W2CT(cbstrWizardName));
        }
        else
             hrError = ::SetErrorInfo(0, srpiErrInfo);
    }
Error:
    (void)::SafeArrayDestroy(psa);

    return hr;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
HRESULT CFileVwProjNode::GetGuidProperty(VSHPROPID propid, GUID* pGuid) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

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
//	Returns requested guid property
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
	default:	// Delegate
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

	CString strNewFullName = GetFolderPath() + strNewName;// new full name (incl. path)
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
		/* bUpdateText      (VSHPROPID_Caption)		   */ TRUE);

	//Fire an event to extensibility
    CAutomationEvents::FireProjectsEvent(
        this, 
        CAutomationEvents::ProjectsEventsDispIDs::ItemRenamed,
        strOldFullName);
	
    return hr;    
}

HRESULT CFileVwProjNode::GetDefaultProjectExtension(CString& strExt)
{
	strExt = _T(".mycp");
	return S_OK;
}


HRESULT CFileVwProjNode::DeleteNode(
    /* [in] */ CHierNode* pNode,        // node to be deleted
    /* [in] */ BOOL fRemoveFromDisk)    // removes the file from disk
{
    ExpectedPtrRet(pNode);

    ASSERT(pNode->IsKindOf(Type_CFileVwFileNode));
	if(! pNode->IsKindOf(Type_CFileVwFileNode))
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

	// Return if the project file is not editable or the project file was reloaded
	if (!QueryEditProjectFile())
		return OLE_E_PROMPTSAVECANCELLED;

    ExpectedPtrRet(m_pCVsTrackProjectDocuments2Helper);
    hr = m_pCVsTrackProjectDocuments2Helper->CanDeleteItem(pNode);
    _IfFailRet(hr);

    // delete file node
    CFileVwFileNode* pFileNode = static_cast<CFileVwFileNode*>(pNode);
    CString strFullName = pFileNode->GetFullPath();
    ExpectedExprRet(!strFullName.IsEmpty());

    // start delete here - do not return
    // tell the node that it is about to be deleted
	hr = pFileNode->OnDelete();
    ASSERT(SUCCEEDED(hr));

    // delete the node
    // note that Delete will 
    // - fire IVsHierarchyEvents::OnItemDeleted
    // - remove the node from the container
    // - release the node
	hr = Delete(pNode, m_pCMyProjectHierarchy);
   ASSERT(SUCCEEDED(hr));

    // fire IVsTrackProjectDocuments
    m_pCVsTrackProjectDocuments2Helper->OnItemDeleted(T2COLE(strFullName));

	// remove the item from disk (if necessary)
	if (fRemoveFromDisk)
    {
        LUtilMakeFileWritable(strFullName);
        if (! ::DeleteFile(strFullName) )
            hr = HRESULT_FROM_WIN32(::GetLastError());
    }

    // Finally, dirty the project file
    SetProjectFileDirty(TRUE);

    return hr;
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
		/* [out] VSQueryEditResultFlags *prgfMoreInfo        */	NULL);
    // Return FALSE if we cannot edit the project file or the project file is reloaded
    if (FAILED(hr) || (fEditVerdict != QER_EditOK) )
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
