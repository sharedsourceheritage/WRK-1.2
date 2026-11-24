
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNBase.cpp : Implementation of CFileVwBaseNode and interfaces

#include "stdafx.h"
#include "PrjInc.h"
#include "PrjNBase.h"
#include "PrjNRoot.h"


const CString& CFileVwBaseNode::GetFullPath(void) const
{
    CHierContainer *pParentNode = GetParent();
    ASSERT(NULL != pParentNode);
    // If the parent is unknown it's an error, anyway we can still
    // return the previously stored full path (Note that this can be wrong
    // if any of the parents are renamed).
    if (NULL == pParentNode)
        return m_strFullPath;

    // Check the type of the parent. As before if the type is not correct
    // return the previously stored path.
    BOOL fExpectedType = pParentNode->IsKindOf(Type_CFileVwFolderNode) ||
                         pParentNode->IsKindOf(Type_CFileVwProjNode);
    if ( !fExpectedType )
    {
        ASSERT(false);
        return m_strFullPath;
    }

    // Get the container object and ask it for its path.
    CFileVwBaseNode* pParent = static_cast<CFileVwBaseNode*>(pParentNode);
    CString strParentPath;
    if (FAILED(pParent->GetFolderPath(strParentPath)))
        return m_strFullPath;

    // Remove the slash at the end of the name.
    while ( !strParentPath.IsEmpty() && (strParentPath[strParentPath.GetLength()-1]=='\\') )
        strParentPath = strParentPath.Left(strParentPath.GetLength()-1);
    if ( strParentPath.IsEmpty() )
    {
        ASSERT(false);
        return m_strFullPath;
    }

    m_strFullPath.Format(_T("%s\\%s"), strParentPath, m_strFileName);
    return m_strFullPath;
}


void CFileVwBaseNode::SetFullPath(LPCTSTR pszFullPath) 
{ 
    if (!pszFullPath)
        return;
    m_strFullPath = pszFullPath; 

    // Split up the pathname for to extract filename for our item Name and SaveName
    TCHAR szExt[_MAX_EXT];
    TCHAR szFileName[_MAX_FNAME];

    _tsplitpath(pszFullPath, NULL, NULL, szFileName, szExt);
    m_strFileName = szFileName;
    m_strFileName += szExt;
}

//-----------------------------------------------------------------------------
// interface: IOleCommandTarget
//-----------------------------------------------------------------------------
STDMETHODIMP CFileVwBaseNode::QueryStatus( 
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [out][in][size_is] */ OLECMD prgCmds[],
            /* [unique][out][in] */ OLECMDTEXT *pCmdText)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pguidCmdGroup);
    ExpectedPtrRet(prgCmds);
    ExpectedExprRet(1 == cCmds);
    
    HRESULT hr = S_OK;
    BOOL fSupported = FALSE;
    BOOL fEnabled = FALSE;
    BOOL fInvisible = FALSE;

    if(*pguidCmdGroup == guidVSStd97)
    {   // Shell commands
        switch(prgCmds[0].cmdID)
        {
        case cmdidCut:
        case cmdidCopy:
            // make sure this is not the project node
            if (!IsKindOf(Type_CFileVwProjNode))
            {
                fSupported = TRUE;
                fEnabled = TRUE;
            }
            break;
        default:
            hr = OLECMDERR_E_NOTSUPPORTED;
        }
    }
    if (SUCCEEDED(hr) && fSupported)
    {
        prgCmds[0].cmdf = OLECMDF_SUPPORTED;
        if (fInvisible)
            prgCmds[0].cmdf |= OLECMDF_INVISIBLE;
        else if (fEnabled)
            prgCmds[0].cmdf |= OLECMDF_ENABLED;
    }
    
    return hr;
}

//-----------------------------------------------------------------------------
// interface: IOleCommandTarget
//-----------------------------------------------------------------------------
STDMETHODIMP CFileVwBaseNode::Exec( 
                                   /* [unique][in] */ const GUID *pguidCmdGroup,
                                   /* [in] */ DWORD nCmdID,
                                   /* [in] */ DWORD nCmdexecopt,
                                   /* [unique][in] */ VARIANT *pvaIn,
                                   /* [unique][out][in] */ VARIANT *pvaOut)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;
    ExpectedPtrRet(pguidCmdGroup);
    
    if (*pguidCmdGroup == guidVSStd97)
    {
        hr = OLECMDERR_E_NOTSUPPORTED;
    }
    else
    {
        hr = OLECMDERR_E_NOTSUPPORTED;
    }
    
    return hr;
} // CFileVwBaseNode::Exec


//-----------------------------------------------------------------------------
// returns the node from child list who's GetFullPath() == pszFullPath
//-----------------------------------------------------------------------------
CFileVwBaseNode* CFileVwBaseNode::GetNodeByFullPath(LPCTSTR pszFullPath)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return NULL;

    ASSERT(NULL != pszFullPath);
    if (!pszFullPath)
        return NULL;
    CFileVwBaseNode* pNode = (CFileVwBaseNode *)GetHeadEx(/* BOOL fDisplayOnly = TRUE */ FALSE);
    for (; pNode != NULL; pNode = (CFileVwBaseNode *)pNode->GetNext(/* BOOL fDisplayOnly = TRUE */ FALSE))
    {
        if ((pNode->GetFullPath()).CompareNoCase(pszFullPath) == 0)
        {
            return pNode;
        }
    }
    return NULL;
}


//-----------------------------------------------------------------------------
// returns the node from child list who's GetCanonicalName() == pszCanonicalName
//-----------------------------------------------------------------------------
CHierNode* CFileVwBaseNode::GetNodeByCanonicalName(
    LPCOLESTR pszCanonicalName)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return NULL;

    if (!pszCanonicalName)
    {
        ASSERT(FALSE);
        return NULL;
    }
    
    CHierNode* pNode = GetHeadEx(/* BOOL fDisplayOnly = TRUE */ FALSE);
    for (; pNode != NULL; pNode = pNode->GetNext(/* BOOL fDisplayOnly = TRUE */ FALSE))
    {
        CComBSTR cbstrNodeName;
        HRESULT hr = pNode->GetCanonicalName(&cbstrNodeName);
        if ( SUCCEEDED(hr) && !wcscmp((BSTR)cbstrNodeName, pszCanonicalName) )
        {
            return pNode;
        }
    }
    return NULL;
}

//-----------------------------------------------------------------------------
// Return the lowercase, absolute path as our canonical name. 
//
// NOTE: it is important that the canonical name is returned in a consistent
// manner to allow the caller to reliably perform string comparisons to test
// whether two canonical names are identical. because the file system is not
// case sensitive (but rather case preserving) and because we use our file
// system path as the basis for our canonical name, we must convert the path
// to a deterministic case. by convention, we convert the file path to lower
// case.
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseNode::GetCanonicalName(BSTR* pbstrName) const
{    
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pbstrName);
    *pbstrName = NULL;
    CString strFullPath;
    strFullPath = GetFullPath();
    strFullPath.MakeLower();
    *pbstrName = strFullPath.AllocSysString();
    return (*pbstrName) ? S_OK : E_OUTOFMEMORY;
}


//---------------------------------------------------------------------------
// If the file for the node is indeed project relative, then we return S_OK 
// and the lowercase, project relative path. 
// If the file is not contained in our project directory, then we return 
// S_FALSE and the absolute path.
//---------------------------------------------------------------------------
HRESULT CFileVwBaseNode::GetProjRelativePath(CString& strProjRelPath) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    strProjRelPath = GetFullPath();
    strProjRelPath.MakeLower();
    ExpectedPtrRet(GetRootNode());
    CString strRootPath;
    HRESULT hr = (static_cast<CFileVwProjNode*>(GetRootNode()))->GetFolderPath(strRootPath);
    if (FAILED(hr))
        return hr;
    strRootPath.MakeLower();

    if(strProjRelPath.Find(strRootPath) == 0)
    {
        // Strip off the project path
        strProjRelPath = strProjRelPath.Right(strProjRelPath.GetLength() - strRootPath.GetLength());
        return S_OK;
    }
    return S_FALSE;    // file is not w/i the project directory. return the absolute path
}

//---------------------------------------------------------------------------
// Similar to GetProjRelativePath; it will check if this node has a path
// that is inside the parent's folder and in this case returns S_OK.
// If it's outside the parent's cone, the return value will be S_FALSE and
// the returned path will be the absolute one
//---------------------------------------------------------------------------
HRESULT CFileVwBaseNode::GetParentRelativePath(CString& strProjRelPath) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Absolute path of this node.
    strProjRelPath = GetFullPath();
    strProjRelPath.MakeLower();

    // Get a reference to the parent.
    CHierContainer* pParent = GetParent();
    ExpectedPtrRet(pParent);
    BOOL fExpectedParentType = pParent->IsKindOf(Type_CFileVwFolderNode) || 
                               pParent->IsKindOf(Type_CFileVwProjNode);
    // The parent is supposed to be the project or a folder.
    ASSERT(fExpectedParentType);
    if ( !fExpectedParentType )
        return E_UNEXPECTED;
    CFileVwBaseContainer* pParentNode = static_cast<CFileVwBaseContainer*>(pParent);
    CString strRootPath;
    HRESULT hr = pParentNode->GetFolderPath(strRootPath);
    if (FAILED(hr))
        return hr;
    strRootPath.MakeLower();

    if(strProjRelPath.Find(strRootPath) == 0)
    {
        // Now the relative path is lower case. Get the original one in order
        // to preserve the case of the name.
        strProjRelPath = GetFullPath();
        // Strip off the project path
        strProjRelPath = strProjRelPath.Right(strProjRelPath.GetLength() - strRootPath.GetLength());
        // Remove the slash at the beginning of the path
        while ( !strProjRelPath.IsEmpty() && (strProjRelPath[0]=='\\') )
        {
            strProjRelPath = strProjRelPath.Mid(1);
        }
        if ( strProjRelPath.IsEmpty() )
            return E_UNEXPECTED;
        return S_OK;
    }

    return S_FALSE;
}

HRESULT CFileVwBaseNode::CheckRename(CString &strNewName, BOOL *pfRenameSameFile)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    if (NULL == pfRenameSameFile)
        return E_POINTER;
    *pfRenameSameFile = FALSE;

    // remove trailing dots and spaces from the name
    LUtilFixFilename(strNewName);

    // make sure no illegal characters
    CString strNewFilename(strNewName);
    HRESULT hr = CheckFileName(strNewFilename);
    if (FAILED(hr))
    {
        CString msg;
        VxFormatString1(msg, IDS_INVALIDFILENAME, strNewFilename);
        _VxModule.SetErrorInfo(hr,msg, 0);
        return hr;
    }

    // get the current file name
    CString strCurrentFilename;
    strCurrentFilename = GetName();
    
    // If we rename same file-same case then ignore
    if (!lstrcmp(strCurrentFilename, strNewName))
        return S_OK;

    // If we rename same file to same name, but different case then remember this
    if (!lstrcmpi(strCurrentFilename, strNewName))
        *pfRenameSameFile = TRUE;

    strCurrentFilename = GetFullPath();

    // determine the full path of the new file name
    strNewFilename = strCurrentFilename;
    INT_PTR nLastBackslashPos;
    nLastBackslashPos = strNewFilename.ReverseFind(TEXT('\\'));
    if (nLastBackslashPos >= 0)
    {
        strNewFilename = strNewFilename.Left(nLastBackslashPos + 1);
    }
    strNewFilename += strNewName;

    // Check if file already exists and error if so...
    if (!*pfRenameSameFile)
    {
        HANDLE  hf;
        WIN32_FIND_DATA ffData;
        if ((hf = FindFirstFile(strNewFilename, &ffData)) != INVALID_HANDLE_VALUE)
        {
            FindClose(hf);
            CString msg;
            VxFormatString1(msg, IDS_RENAMEFILEALREADYEXISTS, strNewFilename);
            _VxModule.SetErrorInfo(E_FAIL,msg, 0);
            return E_FAIL;
        }
    }

    // Return to the caller the full path of the new object
    strNewName = strNewFilename;
    return S_OK;
}

//-----------------------------------------------------------------------------
// Returns the project node. Will return NULL if this node is not in the node
// tree 
//-----------------------------------------------------------------------------
CFileVwProjNode* CFileVwBaseNode::GetProjectNode() const
{
    CHierNode *pNode = GetRootNode();
    if (!pNode) return NULL;
    ASSERT(pNode->IsKindOf(Type_CFileVwProjNode));
    return static_cast<CFileVwProjNode *>(pNode);
}

//-----------------------------------------------------------------------------
// Force node to repaint. Do it by resetting the icon index or text or both.
//-----------------------------------------------------------------------------
void CFileVwBaseNode::ReDraw(BOOL bUpdateIcon /*=TRUE*/, BOOL bUpdateStateIcon /*=TRUE*/, 
                     BOOL bUpdateText /*= FALSE*/)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return;

    // Root object or item must be in UI.
    CHierContainer* pParent = GetParent();
    if(pParent == NULL || pParent->HaveChildrenBeenEvaluated())
    {
        CVsHierarchy* pHier = GetCVsHierarchy();
        if (!pHier) return;
        if(bUpdateIcon)
            pHier->OnPropertyChanged(this, VSHPROPID_IconIndex, 0);
        if(bUpdateStateIcon)
            pHier->OnPropertyChanged(this, VSHPROPID_StateIconIndex, 0);
        if(bUpdateText)
            pHier->OnPropertyChanged(this, VSHPROPID_Caption, 0);
    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CFileVwBaseNode::GetProperty(VSHPROPID propid, VARIANT* pvar)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pvar);
    HRESULT hr = S_OK;
    switch (propid)
    {
    case VSHPROPID_Name:
    case VSHPROPID_SaveName:
        V_VT(pvar) = VT_BSTR;
        V_BSTR(pvar) = GetFileName().AllocSysString();
        if (!pvar->bstrVal) return E_OUTOFMEMORY;
        break;
    default:    // Delegate
        hr = CHierContainer::GetProperty(propid, pvar);
    }
    return hr;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
HRESULT CFileVwBaseNode::DisplayContextMenu()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    DWORD idmx = GetContextMenu();
    HRESULT hr = NOERROR;
    
    if (idmx != IDMX_NULLMENU)
        hr = CHierNode::ShowContextMenu(idmx, guidSHLMainMenu, NULL);
    return hr;
}


//---------------------------------------------------------------------------
//    Sets/resets the bit(s) based in the value.
//---------------------------------------------------------------------------
void CFileVwBaseNode::SetBits(int bits, BOOL bValue)
{ 
    if(bValue)
        m_grfStateFlags |=  bits;
    else
        m_grfStateFlags &= ~bits;
}


//-----------------------------------------------------------------------------
// Updates the files SCC status(ST_IsUnderSCC) and the checkout status 
// kept by the ST_IsCheckedOut bit
//-----------------------------------------------------------------------------
BOOL CFileVwBaseNode::UpdateSccStatus(DWORD dwSccStatus)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    DWORD dwOldSccState = m_grfStateFlags & (ST_IsUnderSCC | ST_IsCheckedOut);
    // Update under SCC status
    m_grfStateFlags &= ~(ST_IsUnderSCC | ST_IsCheckedOut);
    if(dwSccStatus != SCC_STATUS_INVALID && dwSccStatus & SCC_STATUS_CONTROLLED)
    {
        m_grfStateFlags |= ST_IsUnderSCC;
        if(dwSccStatus & SCC_STATUS_CHECKEDOUT)
            m_grfStateFlags |= ST_IsCheckedOut;
    }
    // UI need updating?
    return dwOldSccState  != (m_grfStateFlags & (ST_IsUnderSCC | ST_IsCheckedOut));
}



//---------------------------------------------------------------------------
// Set the source code control glyph
//---------------------------------------------------------------------------
UINT CFileVwBaseNode::GetIconIndex(ICON_TYPE iconType) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    if( iconType != ICON_StateImage )
    {
        // -1 means we want Environment to supply Windows associated icon for file type
        return -1;
    }

    UINT nIndex = STATEICON_BLANK;
    
    CComPtr<IVsSccManager2> srpIVsSccManager2;
    HRESULT hr = _VxModule.QueryService(SID_SVsSccManager, IID_IVsSccManager2, (void **)&srpIVsSccManager2);
    if(FAILED(hr) || srpIVsSccManager2 == NULL)
        return nIndex;

    VsStateIcon siGlyph     = STATEICON_NOSTATEICON;
    DWORD       dwSccStatus = SCC_STATUS_INVALID;
    CComBSTR cbstrPath(GetFullPath());

    // Create the array with the path of all the files
    LPCOLESTR rgstrFilesPath[] = { cbstrPath };

    // Get the glyph from the scc manager. 
    // Note that it will fail in command line scenarios.
    hr = srpIVsSccManager2->GetSccGlyph(
         /* [in] int cFiles                                         */ 1,              // Number of files: should be > 0
        /* [in, size_is(cFiles)]  const LPCOLESTR rgpszFullPaths[]  */ rgstrFilesPath, // Array of paths: cannot be NULL
        /* [out, size_is(cFiles)] VsStateIcon rgsiGlyphs[]          */ &siGlyph,       // Array of icons: cannot be NULL
        /* [out, size_is(cFiles)] DWORD rgdwSccStatus[]             */ &dwSccStatus);  // Status bits: can be NULL
    if (FAILED(hr))
        return nIndex;

    nIndex = siGlyph;

    // Need to const cast to allow calling non-const UpdateSccStatus.
    const_cast<CFileVwBaseNode*>(this)->UpdateSccStatus(dwSccStatus);

    return nIndex;
}


VSHIERARCHYITEMSTATE CFileVwBaseNode::GetItemState(
    /* [in] */ VSHIERARCHYITEMSTATE dwStateMask) const
{
    CComPtr<IVsUIHierarchyWindow> srpIVsUIHierarchyWindow;
    VSHIERARCHYITEMSTATE retItemState = 0;
    HRESULT hr = _VxModule.GetIVsUIHierarchyWindow(GUID_SolutionExplorer, &srpIVsUIHierarchyWindow);
    if(SUCCEEDED(hr))
    {
        if (GetCVsHierarchy())
            hr = srpIVsUIHierarchyWindow->GetItemState(GetCVsHierarchy()->GetIVsUIHierarchy(), GetVsItemID(), dwStateMask, &retItemState);
        else 
            hr = E_UNEXPECTED;
    }
    return SUCCEEDED(hr)?retItemState : 0;
}

