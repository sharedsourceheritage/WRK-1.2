
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "stdafx.h"
#include "PrjInc.h"
#include "PrjNFile.h"
#include "PrjNFolder.h"
#include "PrjNRoot.h"
#include "PrjHier.h"

//-----------------------------------------------------------------------------
// CFileVwBaseContainer::OnCmdAddFolder
// Creates a new folder contained in the current container
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseContainer::OnCmdAddFolder()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

    // Get a reference to the project
    CFileVwProjNode* pProject = GetProjectNode();
    ExpectedPtrRet(pProject);

    // Create a new folder in the Project's folder
    CFileVwFolderNode *pFolder = NULL;
    CString strThisFolder;
    hr = GetFolderPath(strThisFolder);
    if (FAILED(hr))
        return hr;
    hr = CFileVwFolderNode::CreateInstanceInFolder(strThisFolder, &pFolder);
    if (FAILED(hr))
        return hr;
    if (NULL == pFolder)
        return E_FAIL;

    Add(pFolder);

    //Fire an event to extensibility
    CAutomationEvents::FireProjectItemsEvent(
        pFolder, 
        CAutomationEvents::ProjectItemsEventsDispIDs::ItemAdded);

    if (SUCCEEDED(hr))
    {
        // Since our expandable status may have changed, 
        // we need to refresh it in the UI
        GetCVsHierarchy()->OnPropertyChanged(this, VSHPROPID_Expandable, 0);

        pProject->SetProjectFileDirty(TRUE);
    }

    return hr;
}

HRESULT CFileVwBaseContainer::AddExistingFolder(LPCOLESTR pszFolderName, CFileVwBaseNode **ppNewFolder)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pszFolderName);
    ExpectedPtrRet(ppNewFolder);
    *ppNewFolder = NULL;

    HRESULT hr = S_OK;

    // Get a reference to the project
    CFileVwProjNode* pProject = GetProjectNode();
    ExpectedPtrRet(pProject);

    // Check if it is possible to change the project.
    if ( !pProject->QueryEditProjectFile() )
        return OLE_E_PROMPTSAVECANCELLED;

    // Get the folder associated to this container
    CString strThisFolder;
    hr = GetFolderPath(strThisFolder);
    if (FAILED(hr))
        return hr;
    if (strThisFolder.IsEmpty())
        return E_UNEXPECTED;
    // Check if this folder name ends with s slash
    if (strThisFolder[strThisFolder.GetLength()-1]!='\\')
        strThisFolder += _T("\\");

    CString strNewName(pszFolderName);
    // remove trailing dots and spaces from the name
    LUtilFixFilename(strNewName);

    // Create the full path for the new folder
    CString strNewPath = strThisFolder + strNewName;
    CFileVwFolderNode *pFolder = NULL;
    // Build the folder object.
    hr = CFileVwFolderNode::CreateInstanceFromFolder(strNewPath, &pFolder);
    if (FAILED(hr))
        return hr;
    if (NULL == pFolder)
        return E_FAIL;

    // Now it is possible to add the new object to the hierarchy
    Add(pFolder);

    if (SUCCEEDED(hr))
    {
        // Since our expandable status may have changed, 
        // we need to refresh it in the UI
        GetCVsHierarchy()->OnPropertyChanged(this, VSHPROPID_Expandable, 0);
        pProject->SetProjectFileDirty(TRUE);
        *ppNewFolder = pFolder;
    }

    return hr;
}

//-----------------------------------------------------------------------------
// CFileVwBaseContainer::CheckFileInFolder
// Checks if the file with path strFullPath is inside this container's folder;
// if that's not the case it will try to copy it and in this case will update
// strFullPath.
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseContainer::CheckFileInFolder(CString &strFullPath)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Check that this path doesn't ends with slash
    while ( !strFullPath.IsEmpty() && strFullPath[strFullPath.GetLength()-1]=='\\' )
        strFullPath = strFullPath.Left(strFullPath.GetLength()-1);
    if (strFullPath.IsEmpty())
        return E_INVALIDARG;

    // Split the path in its components.
    TCHAR rgchDrive [3];
    TCHAR rgchInPath[_MAX_PATH];
    TCHAR rgchInName[_MAX_PATH];
    TCHAR rgchInExt [_MAX_PATH];
    _tsplitpath(strFullPath, rgchDrive, rgchInPath, rgchInName, rgchInExt);

    // Copy the full path in a local variable that we will modify
    CString strTempPath;
    strTempPath.Format(_T("%s%s"), rgchDrive, rgchInPath);

    // Get the folder associated to this container
    CString strThisFolder;
    HRESULT hr = GetFolderPath(strThisFolder);
    if (FAILED(hr))
        return hr;
    if (strThisFolder.IsEmpty())
        return E_UNEXPECTED;
    strThisFolder.MakeLower();
    // Make sure that this folder's name ends with a slash
    if (strThisFolder[strThisFolder.GetLength()-1]!='\\')
        strThisFolder += _T("\\");

    if (strThisFolder.CompareNoCase(strTempPath) == 0)
    {
        // The item is inside this folder, so we can exit.
        return S_OK;
    }

    // Build the full path of the location where we want to copy the file.
    CString strDestination;
    strDestination.Format(_T("%s%s%s"), strThisFolder, rgchInName, rgchInExt);

    // Check if a file exists in the destination.
    DWORD dwAttrib = GetFileAttributes(strDestination);
    if (INVALID_FILE_ATTRIBUTES != dwAttrib)
        return E_FAIL;
    // If we are here, then it was not possible to read the attributes for the
    // destination. We are fine with this only if the reason is that the file
    // doesen't exist.
    DWORD dwLastError = GetLastError();
    if (ERROR_FILE_NOT_FOUND != dwLastError)
        return HRESULT_FROM_WIN32(dwLastError);

    // Try to copy the file.
    if ( !CopyFile(strFullPath, strDestination, TRUE) )
    {
        dwLastError = GetLastError();
        hr = HRESULT_FROM_WIN32(dwLastError);
        CString msg;
        VxFormatString2(msg, IDS_E_COPY_FAILED, strFullPath, strDestination);
        _VxModule.SetErrorInfo(hr, msg, 0);
        return hr;
    }

    // All done, so we can update the new name of the file and return
    strFullPath = strDestination;
    return S_OK;
}

//-----------------------------------------------------------------------------
// CFileVwBaseContainer::OnCmdAddItem
// Creates a new item (file) inside the current container
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseContainer::OnCmdAddItem
(
BOOL fAddNewItem,
LPCOLESTR pszSelectItem /* = NULL */,
LPCOLESTR pszExpandDir /* = NULL */
)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    static CComBSTR bstrFilter = "";      // filter string (initial/final value); valid if AllowStickyFilter set

    if ( !bstrFilter )
    {
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
            dwFlags = VSADDITEM_AddNewItems | VSADDITEM_SuggestTemplateName; // | VSADDITEM_ShowLocationField;
        else
            dwFlags = VSADDITEM_AddExistingItems | VSADDITEM_AllowMultiSelect | VSADDITEM_AllowStickyFilter;

        // The AddProjectItemDlg function uses an can modify the value of the filter string, so here
        // we need to detach from the bstring and take the ownership or the one returned by the function.
        BSTR strFilters = bstrFilter.Detach();

        hr = srpAddItemDlg->AddProjectItemDlg(
                GetVsItemID(),
                GUID_MyProjectType, 
                QI_cast<IVsProject>(GetCVsHierarchy()),
                dwFlags,
                pszExpandDir,
                pszSelectItem,
                NULL /*&bstrLocation*/,
                &strFilters,
                NULL /*&fDontShowAgain*/);

        if ( NULL != strFilters )
        {
            // Take the ownership of the returned string.
            bstrFilter.Attach(strFilters);
        }

        // NOTE: AddItem() will be called via the hierarchy IVsProject to add items.
    }

    return hr;
}

//-----------------------------------------------------------------------------
// CFileVwBaseContainer::AddItem
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseContainer::AddItem(
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

    CFileVwProjNode *pProject = GetProjectNode();
    ExpectedPtrRet(pProject);

    CExecution singleEx(&GetExecutionCtx());
    
    // Return if the project file is not editable or the project file was reloaded
    if ( !pProject->QueryEditProjectFile() )
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
// CFileVwBaseContainer::AddExistingFile
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseContainer::AddExistingFile
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

    // Check if this item is inside this container's folder.
    // Note that this function can change strFullPath if the item
    // is moved inside this folder.
    _IfFailRet(CheckFileInFolder(strFullPath));

    // check if such an item exist
    if (GetNodeByFullPath(strFullPath) != NULL)
    {
        // Tell the caller that the filename is already a member of the project.
        CString strMsg;
        VxFormatString1(strMsg, IDS_FILEALREADYEXISTS, strFullPath);
        _VxModule.SetErrorInfo(E_FAIL, strMsg, 0 /*dwHelpContextID */);
        return E_FAIL;
    }

    hr = CheckFileName(strFullPath);
    IfFailRet(hr);

    // check the file specified if we are not merely opening an existing project
    if (!fLoad)
    {
        hr = CheckFileType(strFullPath);
        IfFailRet(hr);
    }

    // the file looks ok

    CFileVwProjNode* pProject = GetProjectNode();
    ExpectedPtrRet(pProject);
    CVsTrackProjectDocuments2Helper* pTrackDoc = pProject->GetCVsTrackProjectDocuments2Helper();

    if (!fSilent)
    {
        ExpectedPtrRet(pTrackDoc);
        hr = pTrackDoc->CanAddItem(T2COLE(strFullPath));
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
            pTrackDoc->OnItemAdded(pNewFile);

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
        pProject->GetCVsHierarchy()->OnPropertyChanged(this, VSHPROPID_Expandable, 0);

        pProject->SetProjectFileDirty(TRUE);
    }

    return hr;
}

//-----------------------------------------------------------------------------
// CFileVwBaseContainer::AddNewFile
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseContainer::AddNewFile(
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
    CString strFullPathTarget;
    hr = GetFolderPath(strFullPathTarget);
    if (FAILED(hr))
        return hr;
    // Check if the target path is empty.
    if (strFullPathTarget.IsEmpty())
        return E_UNEXPECTED;
    // Check if the target path has the trailing slash
    if (strFullPathTarget[strFullPathTarget.GetLength()-1] != '\\')
        strFullPathTarget += _T("\\"); 
    strFullPathTarget += strNewFileName;        // Get the target path
    
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

//-----------------------------------------------------------------------------
// CFileVwBaseContainer::RunWizard
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseContainer::RunWizard(
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
    CFileVwProjNode* pProj = GetProjectNode();
    ExpectedPtrRet(pProj);
    hr = pProj->GetAutomationObject(&srpIDispatch_Project);
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
    IfFailGo(GetFolderPath(strProjectDir));
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
// CFileVwBaseContainer::DeleteNode
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseContainer::DeleteNode(
    /* [in] */ CHierNode* pNode,        // node to be deleted
    /* [in] */ BOOL fRemoveFromDisk)    // removes the file from disk
{
    ExpectedPtrRet(pNode);

    BOOL fCorrectType = pNode->IsKindOf(Type_CFileVwFileNode) || pNode->IsKindOf(Type_CFileVwFolderNode);

    ASSERT(fCorrectType);
    if( !fCorrectType )
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

    // Get a reference to the project
    CFileVwProjNode* pProject = GetProjectNode();
    ExpectedPtrRet(pProject);

    // Return if the project file is not editable or project file was reloaded
    if ( !pProject->QueryEditProjectFile() )
        return OLE_E_PROMPTSAVECANCELLED;

    CVsTrackProjectDocuments2Helper* pTrackDoc = pProject->GetCVsTrackProjectDocuments2Helper();
    ExpectedPtrRet(pTrackDoc);
    hr = pTrackDoc->CanDeleteItem(pNode);
    _IfFailRet(hr);

    // delete file node
    CFileVwBaseNode* pFileNode = static_cast<CFileVwBaseNode*>(pNode);
    CString strFullName = pFileNode->GetFullPath();
    ExpectedExprRet(!strFullName.IsEmpty());

    // If the node that we are deleting is a folder, then we have to delete also
    // all its sub-nodes.
    if (pFileNode->IsKindOf(Type_CFileVwFolderNode))
    {
        CMyProjectHierarchy* pHier = pProject->GetCMyProjectHierarchy();
        ExpectedPtrRet(pHier);
        // Note that in the loop we get always the first element in the list of the
        // folder's sub nodes; this is because we want to remove the elements, so the
        // list will change and pInnerNode->GetNext() will return NULL after its
        // removal from the hierarchy.
        for (CHierNode *pInnerNode = pFileNode->GetHead();
             NULL != pInnerNode;
             pInnerNode = pFileNode->GetHead())
        {
            IfFailRet(pHier->CloseAndRemoveItem(pInnerNode->GetVsItemID(), fRemoveFromDisk));
        }
    }

    // start delete here - do not return
    // tell the node that it is about to be deleted
    hr = pFileNode->OnDelete();
    ASSERT(SUCCEEDED(hr));

    // delete the node
    // note that Delete will 
    // - fire IVsHierarchyEvents::OnItemDeleted
    // - remove the node from the container
    // - release the node
    hr = Delete(pNode, pProject->GetCMyProjectHierarchy());
    ASSERT(SUCCEEDED(hr));

    // fire IVsTrackProjectDocuments
    pTrackDoc->OnItemDeleted(T2COLE(strFullName));

    // remove the item from disk (if necessary and if it is a file)
    if (fRemoveFromDisk && pNode->IsKindOf(Type_CFileVwFileNode))
    {
        LUtilMakeFileWritable(strFullName);
        if (! ::DeleteFile(strFullName) )
        {
            hr = HRESULT_FROM_WIN32(::GetLastError());
        }
    }

    // Finally, dirty the project file
    pProject->SetProjectFileDirty(TRUE);

    return hr;
}
