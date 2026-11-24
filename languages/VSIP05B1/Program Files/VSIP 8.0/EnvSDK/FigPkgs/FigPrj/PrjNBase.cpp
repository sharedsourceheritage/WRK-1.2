
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNBase.cpp : Implementation of CFileVwBaseNode and interfaces

#include "stdafx.h"
#include "PrjInc.h"

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

    HRESULT hr = OLECMDERR_E_NOTSUPPORTED;

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

    ExpectedPtrRet(pguidCmdGroup);

    HRESULT hr = OLECMDERR_E_NOTSUPPORTED;
    CExecution singleEx(&GetExecutionCtx());

    return hr;
}

//-----------------------------------------------------------------------------
// returns the node from child list who's GetFullPath() == pszFullPath
//-----------------------------------------------------------------------------
CHierNode* CFileVwBaseNode::GetNodeByFullPath(
    /* [in] */ LPCTSTR  pszFullPath)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return NULL;

    CString pszNodeFullPath;
    ASSERT(NULL != pszFullPath);
    if (!pszFullPath)
        return NULL;
    CHierNode* pNode = GetHeadEx(/* BOOL fDisplayOnly = TRUE */ FALSE);

    for (; pNode != NULL; pNode = pNode->GetNext(/* BOOL fDisplayOnly = TRUE */ FALSE))
    {
        if ( pNode->IsKindOf(Type_CFileVwBaseNode) )
        {
            if ((static_cast<CFileVwBaseNode*>(pNode)->GetFullPath()).CompareNoCase(pszFullPath) == 0)
            {
                return pNode;
            }
        }
        else if ( pNode->IsKindOf(Type_CBuildProjNode) )
        {
            if ((static_cast<CBuildProjNode*>(pNode)->GetFullPath()).CompareNoCase(pszFullPath) == 0)
            {
                return pNode;
            }
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
// Return the lowercase, project relative path as our canonical name. 
// If the file is not contained in our project directory, then the absolute
// path will be returned.
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
    CString strProjRelPath;
    HRESULT hr = GetProjRelativePath(strProjRelPath);
    IfFailRet(hr);
    strProjRelPath.MakeLower();
    *pbstrName = strProjRelPath.AllocSysString();
    return (*pbstrName) ? S_OK : E_OUTOFMEMORY;
}

//---------------------------------------------------------------------------
// If the file for the node is indeed project relative, then we return S_OK 
// and the lowercase, project relative path. 
// If the file is not contained in our project directory, then we return 
// S_FALSE and the absolute path.
//---------------------------------------------------------------------------
HRESULT CFileVwBaseNode::GetProjRelativePath  (CString& strProjRelPath) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    strProjRelPath = GetFullPath();
    ExpectedPtrRet(GetRootNode());
    CString strRootPath = (static_cast<CFileVwProjNode*>(GetRootNode()))->GetFolderPath();

    if(strProjRelPath.Find(strRootPath) == 0)
    {
        // Strip off the project path
        strProjRelPath = strProjRelPath.Right(strProjRelPath.GetLength() - strRootPath.GetLength());
        return S_OK;
    }
    return S_FALSE;    // file is not w/i the project directory. return the absolute path
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

    if ( (VSHPROPID_FIRST > propid || propid > VSHPROPID_LAST) && VSHPROPID_NIL != propid )
    {
        return E_INVALIDARG;                
    }

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

    // Build the list of paths.
    LPCOLESTR rgszFullPaths[] = { cbstrPath };

    // Get the glyph from the scc manager. 
    // Note that it will fail in command line scenarios.
    hr = srpIVsSccManager2->GetSccGlyph(
         /* [in] int cFiles                                          */ 1,               // Number of files: should be > 0
        /* [in, size_is(cFiles)]  const LPCOLESTR rgpszFullPaths[]  */ rgszFullPaths,   // Array of paths: cannot be NULL
        /* [out, size_is(cFiles)] VsStateIcon rgsiGlyphs[]          */ &siGlyph,        // Array of icons: cannot be NULL
        /* [out, size_is(cFiles)] DWORD rgdwSccStatus[]                */ &dwSccStatus);   // Status bits: can be NULL
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