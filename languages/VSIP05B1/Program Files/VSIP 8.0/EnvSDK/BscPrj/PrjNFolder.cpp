
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "stdafx.h"
#include "PrjInc.h"
#include "PrjNFolder.h"
#include "PrjHier.h"

HRESULT CFileVwFolderNode::GetFolderPath(CString& strFolderPath) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Get the parent node in the hierarchy
    CHierNode* pParent = this->GetParent();
    if (NULL == pParent)
        return E_UNEXPECTED;

    // Check if the parent node is one of the expected ones
    BOOL fExpectedType = pParent->IsKindOf(Type_CFileVwFolderNode) || pParent->IsKindOf(Type_CFileVwProjNode);
    if ( !fExpectedType )
        return E_UNEXPECTED;

    // Get the path of the parent
    CFileVwBaseContainer* pContainer = static_cast<CFileVwBaseContainer*>(pParent);
    CString strParentPath;
    HRESULT hr = pContainer->GetFolderPath(strParentPath);
    if (FAILED(hr))
        return hr;

    // Check if the parent's path is empty
    if ( strParentPath.IsEmpty() )
        return E_UNEXPECTED;

    // Check if it ends with a slash
    if (strParentPath[strParentPath.GetLength()-1] != '\\')
        strParentPath += _T("\\");

    // Now add the name of this folder to the previous path
    strFolderPath = strParentPath + GetFileName();
    return S_OK;
}

HRESULT CFileVwFolderNode::CreateInstanceFromFolder(LPCTSTR pszFullPath, CFileVwFolderNode **ppFolderNode)
{
    // Check the input pointers
    ExpectedPtrRet(pszFullPath);
    ExpectedPtrRet(ppFolderNode);

    // Check if the path is correct
    DWORD dwFileAttrib = GetFileAttributes(pszFullPath);
    if (INVALID_FILE_ATTRIBUTES == dwFileAttrib)
    {
        // We can't find the attributes of the file, so return the error code set by the OS
        DWORD dwLastError = GetLastError();
        return HRESULT_FROM_WIN32(dwLastError);
    }
    if ( (dwFileAttrib & FILE_ATTRIBUTE_DIRECTORY) == 0 )
    {
        // The object exists, but it is not a folder, so generate an error.
        return E_INVALIDARG;
    }

    // Now we know that the folder exists, so we can create the node
    CComObject<CFileVwFolderNode> *pNode = NULL;
    HRESULT hr = CComObject<CFileVwFolderNode>::CreateInstance(&pNode);
    if (FAILED(hr))
        return hr;
    if (NULL == pNode)
        return E_FAIL;

    // Initialize the new node
    pNode->AddRef();
    pNode->SetFullPath(pszFullPath);
    pNode->SetName( pNode->GetFileName() );

    // return the new node to the caller
    *ppFolderNode = pNode;
    return S_OK;
}

HRESULT CFileVwFolderNode::CreateInstanceInFolder(LPCTSTR pszParentPath, CFileVwFolderNode **ppFolderNode)
{
    // Check the input pointers
    ExpectedPtrRet(pszParentPath);
    ExpectedPtrRet(ppFolderNode);

    CString strParentPath(pszParentPath);
    // remove trailing dots and spaces from the name
    LUtilFixFilename(strParentPath);
    // Check if the parent's path is empty.
    if (strParentPath.IsEmpty())
        return E_INVALIDARG;
    // Now remove the trailing slash.
    if (strParentPath[strParentPath.GetLength()-1] == '\\')
    {
        strParentPath = strParentPath.Left(strParentPath.GetLength()-1);
    }
    if (strParentPath.IsEmpty())
        return E_INVALIDARG;

    // Here we want to create a new folder with the name NewFolderX where X is a
    // number that makes the name unique.
    int index = 1;
    CString fileName;
    DWORD dwFileAttrib;
    BOOL fCanExit = FALSE;
    do
    {
        fileName.Format(_T("%s\\NewFolder%d"), strParentPath, index);
        dwFileAttrib = GetFileAttributes(fileName);
        if (INVALID_FILE_ATTRIBUTES == dwFileAttrib)
        {
            DWORD dwLastError = GetLastError();
            if (ERROR_FILE_NOT_FOUND != dwLastError)
            {
                // We expect "File not found", but any other error code is
                // a real error and we must fail the operation.
                return HRESULT_FROM_WIN32(dwLastError);
            }
            // This name is not in use, let's create the folder.
            if ( !CreateDirectory(fileName, NULL) )
            {
                dwLastError = GetLastError();
                return HRESULT_FROM_WIN32(dwLastError);
            }
            fCanExit = TRUE;
        }
        else
        {
            // A file or folder with this name exists, try the next one
            ++index;
        }
    } while (fCanExit == FALSE);

    // Here we expect the foder to be created, so we can use the other version of
    // the CreateInstance method
    return CFileVwFolderNode::CreateInstanceFromFolder(fileName, ppFolderNode);
}

STDMETHODIMP CFileVwFolderNode::GetAutomationObject(
        /* [out] */ IDispatch ** ppIDispatch)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(ppIDispatch);
    InitParam(ppIDispatch);

    HRESULT hr = S_OK;

    if (m_srpProjectItem == NULL)
    {
        hr = CAOProjectItemFolder::CreateInstance(this, &m_srpProjectItem);
        IfFailRet(hr);
        ExpectedExprRet(m_srpProjectItem);
    }

    return m_srpProjectItem->QueryInterface(IID_IDispatch, (void**)ppIDispatch);
}

HRESULT CFileVwFolderNode::get_FolderName(BSTR *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);

    *pVal = ::SysAllocString(GetName());
    if (NULL == *pVal)
        return E_OUTOFMEMORY;

    return S_OK;
}

HRESULT CFileVwFolderNode::put_FolderName(BSTR val)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    return SetEditLabel(val);
}


HRESULT CFileVwFolderNode::SetEditLabel(BSTR bstrLabel)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    USES_CONVERSION;
    HRESULT hr = S_OK;

    // Check the new name
    if ( ::SysStringLen(bstrLabel) == 0 )
    {
        _VxModule.SetErrorInfo(E_FAIL,IDS_RENAMEFILEFAILED, 0);
        return E_FAIL;
    }

    // Let the base class validate this rename and build the full path
    // for the renamed object.
    CString strNewName(W2CT(bstrLabel));
    BOOL fRenameSameFile;
    hr = CheckRename(strNewName, &fRenameSameFile);
    if ( FAILED(hr) )
        return hr;

    // Check if the hierarchy is in a editable state.
    CMyProjectHierarchy *pMyProjectHierarchy = static_cast<CMyProjectHierarchy*>(GetCVsHierarchy());
    ExpectedExprRet(pMyProjectHierarchy);
    if ( !pMyProjectHierarchy->QueryEditProjectFile() )
        return OLE_E_PROMPTSAVECANCELLED;

    // If the rename is a real rename (not just a change in the case of the name),
    // then we have to change the name in the file system.
    if ( FALSE == fRenameSameFile )
    {
        if (0 == MoveFile(GetFullPath(), strNewName))
        {
            // The rename failed, so get the last error
            DWORD dwLastError = GetLastError();
            hr = HRESULT_FROM_WIN32(dwLastError);
            _VxModule.SetErrorInfo(hr,IDS_RENAMEFILEFAILED, 0);
            return hr;
        }
    }

    // Rename this node
    SetFullPath( strNewName );
    SetName(GetFileName(), pMyProjectHierarchy);

    ReDraw(
        /* bUpdateIcon      (VSHPROPID_IconIndex)      */ TRUE, 
        /* bUpdateStateIcon (VSHPROPID_StateIconIndex) */ TRUE, 
        /* bUpdateText      (VSHPROPID_Caption)           */ TRUE);

    // All done, exit
    return S_FALSE;
}

HRESULT CFileVwFolderNode::GetEditLabel(BSTR *pbstrLabel)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Check the input pointer
    ExpectedPtrRet(pbstrLabel);

    // Allocate the new string
    CString strName(GetName());
    *pbstrLabel = ::SysAllocString(strName);
    if (NULL == *pbstrLabel)
        return E_OUTOFMEMORY;
    
    return S_OK;
}

//-----------------------------------------------------------------------------
// Called when the node is about to be deleted.
//-----------------------------------------------------------------------------
HRESULT CFileVwFolderNode::OnDelete(void)
{
    CAutomationEvents::FireProjectItemsEvent(
        this,
        CAutomationEvents::ProjectItemsEventsDispIDs::ItemRemoved);

    Close();
    return S_OK;
}

STDMETHODIMP CFileVwFolderNode::QueryStatus
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
    //QUERY_STATUS_CHECK;

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
                fEnabled = FALSE;
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

STDMETHODIMP CFileVwFolderNode::Exec
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
    
    return hr;
}

UINT CFileVwFolderNode::GetIconIndex(ICON_TYPE iconType) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    return (iconType == ICON_StateImage) ?
            CFileVwBaseNode::GetIconIndex(iconType)
        :   GetImageList()->IImageFromPguidType(PGuidGetType());
}

const GUID* CFileVwFolderNode::PGuidGetType(void) const
{
    return &GUID_NODETYPE_FileVw_Folder;
}

HRESULT CFileVwFolderNode::GetProperty(VSHPROPID propid, VARIANT* pvar)
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
    case VSHPROPID_TypeName:
        {
            CString strTypeName;
            if (!strTypeName.LoadString(IDS_FOLDERNODE_TYPE))
                return E_FAIL;
            V_VT(pvar) = VT_BSTR;
            V_BSTR(pvar) = strTypeName.AllocSysString();
            if (!pvar->bstrVal) return E_OUTOFMEMORY;
        }
        break;

    case VSHPROPID_BrowseObject:        // CHierNode derived property
        if(SUCCEEDED(hr = QueryInterface(IID_IDispatch, (void **)&V_DISPATCH(pvar))))
        {
            V_VT(pvar) = VT_DISPATCH;
        }
        break;

    case VSHPROPID_ExtObject:
        IfFailGo(GetAutomationObject(&V_DISPATCH(pvar)));
        V_VT(pvar) = VT_DISPATCH;
        break;

    default:
        // If this object doesn't know this property, try to ask
        // to the base class
        hr = CFileVwBaseNode::GetProperty(propid, pvar);
        break;
    }

Error:
    return hr;
}
