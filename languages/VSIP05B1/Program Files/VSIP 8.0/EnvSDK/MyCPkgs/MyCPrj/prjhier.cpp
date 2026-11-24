
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjHier.cpp : Implementation of CMyProjectHierarchy and IVsHierarchy related interfaces

#include "stdafx.h"
#include "PrjInc.h" 
#include <vsmem.h>

#define IfNonNullFreeSetNull(mem) { if ((mem) != NULL) { VSFree((mem)); (mem) = NULL; } }


//---------------------------------------------------------------------------
// Project Hierarchy constructor -- basically makes sure that the package
//      object lives as long as we do by add-ref'ing it.
//---------------------------------------------------------------------------
CMyProjectHierarchy::CMyProjectHierarchy()  
{
	m_nFormatIndex = DEF_FORMAT_INDEX;
	GetIVsPkg()->AddRef();
	SetImageList(::GetImageListHandle());

    m_pCfgProvider = NULL;

    m_hThreadBuild = NULL;  // handle to the builder thread

	m_fRegisteredWithScc = false;
	m_fDragSource = FALSE;
    m_ddt = DDT_NONE;
	m_nItemsDragged = 0;
	m_pItemSelDragged = NULL;
    m_vscookieIVsUIHierWinClipboardHelperEvents = VSCOOKIE_NIL;
    m_fInCutCopy = FALSE;

}

//---------------------------------------------------------------------------
// Releases the packge object so it can be destructed now that we are
//      going away.
//---------------------------------------------------------------------------
CMyProjectHierarchy::~CMyProjectHierarchy()
{
	GetIVsPkg()->Release();
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::Init(
    /* [in]  */ LPCTSTR pszProjName, 
    /* [in]  */ LPCTSTR pszProjFullPath,
    /* [in]  */ LPCTSTR pszProjLocation,
    /* [in]  */ BOOL    fNewProject,
    /* [out] */ BOOL*   pfCanceled)
{
    ExpectedPtrRet(pszProjName);
    ExpectedPtrRet(pszProjFullPath);
    ExpectedPtrRet(pszProjLocation);
    ExpectedPtrRet(pfCanceled);
    InitParamTo(pfCanceled, FALSE);

    HRESULT hr = S_OK;
    USES_CONVERSION;
    CComVariant var;

    // Save "New Project" flag value
    m_fNewProject = fNewProject;

    // create our project root node
    CFileVwProjNode *pnodeProj;
    hr = CFileVwProjNode::CreateInstance(this, pszProjName, pszProjFullPath, &pnodeProj);
    IfFailRet(hr);

    // Save our Name and location information
    m_strProjFullPath   = pszProjFullPath;
    m_strProjLocation   = pszProjLocation;

    // set the node to be the root of our project
    SetRootNode(pnodeProj);

    // Create the config provider
    hr = CComObject<CCfgProvider>::CreateInstance(&m_pCfgProvider);
    IfFailRet(hr); ExpectedExprRet(m_pCfgProvider != NULL);
    
    m_pCfgProvider->AddRef();   
    hr = m_pCfgProvider->Init(this);// initialize it
    IfFailGo(hr); 

    // Load our project file
    // ignore return value since we still want to have a project, 
    // even if we fail to load it but let's inform the user for the failure
    _VxModule.ClearErrorInfo();
    hr = Load(T2COLE(pszProjFullPath), (DWORD)0, TRUE /* ReadOnly */);
    if (FAILED(hr))
    {
        // report the exact problem with the error info available so far
        _VxModule.ReportErrorInfo(hr);

        // report the Load failure
        _VxModule.SetErrorInfo(E_FAIL, IDS_E_PROJECTLOADFAILED, 0);
        _VxModule.ReportErrorInfo(hr);
        hr = S_OK;
    }
    
    // check if cfgs are created - if not - create default ones
    if (m_pCfgProvider->CfgsCount() == 0)
    {
        // no cfgs so far - create defaults
        hr = m_pCfgProvider->CreateDefaultCfgs();
        IfFailGo(hr);
    }

    // start any startup services. Ignore errors.
    m_projectStartupServices.StartServices();

    // Register ourself with the scc manager.
    hr = RegisterSccProject();
    IfFailGo(hr);

    // If this is an existing project we must now check if our file types are valid
    ULONG   cFilePathStrings = m_rgpFilePaths.GetSize();
    for (ULONG i = 0; i < cFilePathStrings; i++)
    {
        hr = CheckFileType(*m_rgpFilePaths[i]);
        IfFailRet(hr);
    }

    // Delete our strings
    for (ULONG i = 0; i < cFilePathStrings; i++)
    {
        m_rgpFilePaths[i]->Empty();
        delete m_rgpFilePaths[i];
    }
    m_rgpFilePaths.RemoveAll();

    CAutomationEvents::FireProjectsEvent(
        pnodeProj, 
        CAutomationEvents::ProjectsEventsDispIDs::ItemAdded);

Error:
    if (FAILED(hr))
    {
        m_pCfgProvider->Release();
        m_pCfgProvider = NULL;
    }
    return hr;
}


//==========================================================================
//                                                        IVsGetCfgProvider
STDMETHODIMP CMyProjectHierarchy::GetCfgProvider (
    /* [out] */ IVsCfgProvider** ppCfgProvider)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(ppCfgProvider);
    InitParam(ppCfgProvider);

    HRESULT hr = E_NOINTERFACE;   
    if (m_pCfgProvider)
        hr = m_pCfgProvider->QueryInterface(IID_IVsCfgProvider, 
                                            (LPVOID*)ppCfgProvider);        
	return hr;
}
//                                                         IVsGetCfgProvider
//==========================================================================

//==========================================================================
//                                                 IVsProjectStartupServices

STDMETHODIMP CMyProjectHierarchy::AddStartupService(
    /*[in]*/ REFGUID guidService)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

    // Add this service to the list
    hr = m_projectStartupServices.AddStartupService(guidService);
    IfFailGo(hr);

    // Ensure that all services are started.
    // This will startup the newly added service.
    hr = m_projectStartupServices.StartServices();
    
	put_IsDirty(VARIANT_TRUE);

Error:
    return hr;
}

STDMETHODIMP CMyProjectHierarchy::RemoveStartupService(
    /*[in]*/ REFGUID guidService)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = m_projectStartupServices.RemoveStartupService(guidService);

	if (hr == S_OK) 
		put_IsDirty(VARIANT_TRUE);

	return hr;
}

STDMETHODIMP CMyProjectHierarchy::GetStartupServiceEnum(
    /*[out]*/ IEnumProjectStartupServices **ppEnum)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    return m_projectStartupServices.GetStartupServiceEnum(ppEnum);
}

//                                                 IVsProjectStartupServices
//==========================================================================


CFileVwProjNode* CMyProjectHierarchy::GetProjectNode(void)
{
#ifdef DEBUG
	ASSERT(NULL != m_pRootNode);
	if (m_pRootNode)
	{ 
		ASSERT(m_pRootNode->IsKindOf(Type_CFileVwProjNode));
	}
#endif
	return static_cast<CFileVwProjNode *>(m_pRootNode);
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy helper function
// Returns the requested property for the CHierNode.
// There are several of properties handled on the VsHierarchy level
//---------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::GetProperty
(
CHierNode*	pNode,	//in
VSHPROPID	propid,	//in
VARIANT*	pvar	//out
)
{
	ASSERT(NULL != pNode && !IsZombie() && NULL != pvar);
    ExpectedPtrRet(pNode);
    ExpectedPtrRet(pvar); ::VariantInit(pvar);
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = S_OK;
	switch (propid)
	{
		case VSHPROPID_AltHierarchy:		// VsHierarchy [optional] property
		case VSHPROPID_AltItemid:			// VsHierarchy [optional] property
			hr = DISP_E_MEMBERNOTFOUND;
			break;
        case VSHPROPID_ConfigurationProvider:  // hierarchy property
	        hr = GetCfgProvider((IVsCfgProvider **)&V_UNKNOWN(pvar));
	        if (SUCCEEDED(hr))
		        V_VT(pvar) = VT_UNKNOWN;
	        else
	        {	// reclear the variant
		        ::VariantInit(pvar);
	            hr = E_NOINTERFACE;
	        }
			break;

		default:
			hr = CVsHierarchy::GetProperty(pNode, propid, pvar);
	}
	return hr;
}


HRESULT CMyProjectHierarchy::SetProperty(
            /* [in] */ CHierNode *pNode,
            /* [in] */ VSHPROPID propid,
            /* [in] */ const VARIANT& var)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pNode);
    HRESULT hr = S_OK;

    if(propid == VSHPROPID_OwnerKey)
    {
        // Override ownerkey so we dirty project file if necessary
        hr = E_INVALIDARG;
        ASSERT(VT_BSTR == var.vt);
        if(VT_BSTR == var.vt)
        {   
            // Valid guid? Can't point to us and must be a valid clsid string
            GUID guidOwner;
            if(SUCCEEDED(CLSIDFromString(var.bstrVal, &guidOwner)) && 
                guidOwner != GUID_MyProjectType)
            {
                // Strings differ?
                CString oldKey = GetOwnerKey();
                CString newKey = var.bstrVal;
                hr = S_OK;
                if(oldKey.CompareNoCase(newKey) != 0)
                {
                    if(QueryEditProjectFile())
                    {                            
                        SetOwnerKey(var.bstrVal);
                        put_IsDirty(VARIANT_TRUE);
                    }
                    else
                    {
                        hr = OLE_E_PROMPTSAVECANCELLED;
                    }
                }
            }
        }
    }
    else
    {
        // delegate to CVsHierarchy
        hr = CVsHierarchy::SetProperty(pNode, propid, var);
    }
    if (SUCCEEDED(hr))
    {
        HRESULT hrTemp = OnPropertyChanged(pNode, propid, 0);
        ASSERT(SUCCEEDED(hrTemp));
    }
    return hr;
}


//---------------------------------------------------------------------------
//	Returns requested guid property
//---------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::GetGuidProperty(
    VSITEMID	itemid,	//in:
    VSHPROPID	propid,	//in:
    GUID*		pguid)	//out:
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pguid); 
    *pguid = GUID_NULL;

	if(propid == VSHPROPID_CmdUIGuid)
	{
		*pguid = CLSID_MyCPrjPackage;
		return S_OK;
	}
	return CVsHierarchy::GetGuidProperty(itemid, propid, pguid);
}

STDMETHODIMP CMyProjectHierarchy::SetGuidProperty(
    /* [in]  */ VSITEMID    itemid,
    /* [in]  */ VSHPROPID   propid,
    /* [in]  */ REFGUID     guid)  
{
    // Fail if hierarchy already closed
	RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED

    HRESULT hr = E_INVALIDARG;

    if (propid == VSHPROPID_ProjectIDGuid)
    {
        CHierNode *pNode = NULL;
        hr = VSITEMID2Node(itemid, &pNode);
        if (SUCCEEDED(hr))
        {
            ASSERT(pNode != NULL);
            ASSERT(pNode->IsKindOf(Type_CFileVwBaseNode));
            if (!pNode || !pNode->IsKindOf(Type_CFileVwBaseNode))
                return E_UNEXPECTED;
            
            hr = static_cast<CFileVwBaseNode*>(pNode)->SetGuidProperty(propid, guid);
        }

        return hr;
    }

    // Delegate
    hr = CVsHierarchy::SetGuidProperty(itemid, propid, guid);    
    return hr;
}


//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Returns the itemid for the canonical name pszName.
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::ParseCanonicalName(
            /* [in] */  LPCOLESTR pszName,
            /* [out] */ VSITEMID *pitemid)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pszName);
    ExpectedPtrRet(pitemid); *pitemid = VSITEMID_NIL;

    HRESULT hr = E_FAIL;

    CFileVwBaseNode * pRootNode = GetProjectNode();
    ExpectedExprRet(pRootNode!=NULL);

    CHierNode *pNode = NULL;
    pNode = pRootNode->GetNodeByCanonicalName(pszName);
    if (pNode != NULL)
    {
        *pitemid = pNode->GetVsItemID();
        hr = S_OK;
    }

    return hr;
} // CMyProjectHierarchy::ParseCanonicalName


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
UINT CMyProjectHierarchy::GetIconIndex
(
CHierNode*	pnode,
ICON_TYPE	iconType
)
{
    if (!pnode)
        return 0;
	return pnode->GetIconIndex(iconType);
}


//-----------------------------------------------------------------------------
// CMyProjectHierarchy::OnHandleSaveItemRename
//
// MUST be overriden to handle the item Rename aspect of a SaveAs operation via a call to 
// IVsPersistHierarchyItem::SaveItem.
// If a SaveAs occurred the hierarchy needs to update to the fact that its item's name has changed.
// This may include the following:
//		1. call RenameDocument on the RunningDocumentTable
//		2. update the full path name for the item in the hierarchy
//		3. a directory-based project may need to transfer the open editor to the
//		   MiscFiles project if the new file is saved outside of the project directory.
//		   This is accomplished by calling IVsExternalFilesManager::TransferDocument
// This work can not be done by CVsHierarchy::SaveItem; this must be done in a 
// derived subclass implementation of OnHandleSaveItemRename. Alternatively, SaveItem
// itself can be overriden.
//-----------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::OnHandleSaveItemRename
(
VSITEMID itemid, 
IUnknown *punkDocData, 
LPCOLESTR pwszMkDocumentNew
)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pwszMkDocumentNew);
	USES_CONVERSION;

	CFileVwFileNode* pNode = NULL;
	HRESULT hr = VSITEMID2Node(itemid, (CHierNode**)&pNode);
	IfFailRet(hr);

	ASSERT(pNode && pNode->IsKindOf(Type_CFileVwFileNode));
    if (!pNode || !pNode->IsKindOf(Type_CFileVwFileNode))
		return E_UNEXPECTED;

	CString strMkDocumentOld = pNode->GetFullPath();
	
    // do nothing if document name did not change
	if (_wcsicmp(OLE2CW(pwszMkDocumentNew), T2CW(strMkDocumentOld)) == 0)
	    return S_OK;

	hr = CheckFileName(pwszMkDocumentNew);
	IfFailRet(hr);

    pNode->SetFullPath(OLE2CT(pwszMkDocumentNew));

	CComPtr<IVsRunningDocumentTable> srpRDT;
	hr = _VxModule.QueryService(SID_SVsRunningDocumentTable, IID_IVsRunningDocumentTable, (void **)&srpRDT);

	// update the RunningDocumentTable. this will cause the document window captions to update.
	if (SUCCEEDED(hr))
    {
        if (!srpRDT)
            hr = E_UNEXPECTED;
        else
            hr = srpRDT->RenameDocument(T2COLE(strMkDocumentOld), pwszMkDocumentNew, HIERARCHY_DONTCHANGE, itemid);
    }

	if (FAILED(hr))
	{
		pNode->SetFullPath(strMkDocumentOld);
		return hr;
	}

	pNode->OnItemRenamed(strMkDocumentOld);

	// force the caption of this node to update in the project window
	if(pNode->GetParent() == NULL || pNode->GetParent()->HaveChildrenBeenEvaluated())
		OnPropertyChanged(pNode, VSHPROPID_Caption, 0);

    put_IsDirty(VARIANT_TRUE);

	return hr;	
}


//-----------------------------------------------------------------------------
// CMyProjectHierarchy::DisplayContextMenu
//-----------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::DisplayContextMenu(HierNodeList &rgSelection)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = S_OK;

	if (rgSelection.GetCount() == 1)
	{
		CHierNode *pNode = rgSelection.GetHead();
		ASSERT(pNode);

		hr = pNode->DisplayContextMenu();
	}
	else if (rgSelection.GetCount() > 1)
	{
		UINT idmxMenu = GetContextMenu(rgSelection);

		if (idmxMenu!=IDMX_NULLMENU)
		{
            hr = ::ShowContextMenu(idmxMenu, guidSHLMainMenu, NULL);
		}
	}
	return hr;
}

//-----------------------------------------------------------------------------
// CMyProjectHierarchy::GetContextMenu
//-----------------------------------------------------------------------------
UINT CMyProjectHierarchy::GetContextMenu(HierNodeList &rgSelection)
{
	UINT idmxMenu = IDMX_NULLMENU;
	BOOL fProjSelected = FALSE;
	for (POSITION pos = rgSelection.GetHeadPosition(); pos!=NULL;)
	{
		CHierNode *pNode = rgSelection.GetNext(pos);
		ASSERT(pNode);

		UINT idmxTemp = pNode->GetContextMenu();

		if (idmxTemp==IDMX_NULLMENU)
		{	// selection contains node that does not have a ctx menu
			idmxMenu = IDMX_NULLMENU;
			break;
		}
		else if (IDM_VS_CTXT_PROJNODE == idmxTemp )
		{
			// selection includes project node
			fProjSelected = TRUE;
		}
		else if (idmxMenu==IDMX_NULLMENU || idmxMenu==idmxTemp)
		{	// homogeneous selection
			idmxMenu = idmxTemp;
		}
		else if (IsItemNodeCtx(idmxTemp) && IsItemNodeCtx(idmxMenu))
		{
			// heterogeneous set of nodes that support common node commands
			idmxMenu = IDM_VS_CTXT_XPROJ_MULTIITEM;
		}
		else
		{	// heterogeneous set of nodes that have no common commands
			idmxMenu = IDMX_NULLMENU;
			break;
		}
	}

	// Multi-selection involving project node.
	if (idmxMenu!=IDMX_NULLMENU && fProjSelected)
		idmxMenu = IDM_VS_CTXT_XPROJ_PROJITEM;

	return idmxMenu;
}

//-----------------------------------------------------------------------------
// CMyProjectHierarchy::QueryStatusSelection
//-----------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::QueryStatusSelection(
	const GUID *pguidCmdGroup,
	ULONG cCmds,
	OLECMD prgCmds[],
	OLECMDTEXT *pCmdText,
	HierNodeList &rgSelection,
	BOOL		 fIsHierCmd)		// TRUE if cmd originated via CVSUiHierarchy::ExecCommand

{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pguidCmdGroup);
    ExpectedPtrRet(prgCmds);
    ExpectedExprRet(cCmds == 1);

	HRESULT hr = S_OK;
	BOOL fHandled = FALSE;
	BOOL fSupported = FALSE;
	BOOL fEnabled = FALSE;
	BOOL fInvisible = FALSE;
	BOOL fLatched = FALSE;
	OLECMD &Cmd = prgCmds[0];

	if (guidVSStd97 == *pguidCmdGroup)
	{
		// NOTE: We only want to support Cut/Copy/Paste/Delete/Rename commands
		// if focus is in the project window. This means that we should only
		// support these commands if they are dispatched via IVsUIHierarchy
		// interface and not if they are dispatch through IOleCommandTarget
		// during the command routing to the active project/hierarchy.
		if(!fIsHierCmd)
		{
			switch(Cmd.cmdID)
			{
				case cmdidCut:
				case cmdidCopy:
				case cmdidPaste:
			    case cmdidRename:
					return OLECMDERR_E_NOTSUPPORTED;
			}
		}

		switch(Cmd.cmdID)
		{
			// Forward the following commands to the project node whenever our project is 
			// the active project.
			case cmdidAddNewItem:
			case cmdidAddExistingItem:
				return GetProjectNode()->QueryStatus(pguidCmdGroup, cCmds, prgCmds, pCmdText);
		}
	}

	// Node commands 
	if (!fHandled)
	{
        fHandled = TRUE;
		OLECMD cmdTemp;
		cmdTemp.cmdID = Cmd.cmdID;

		fSupported = FALSE;
		fEnabled = TRUE;
		fInvisible = FALSE;
		fLatched = TRUE;

		for (POSITION pos = rgSelection.GetHeadPosition(); pos!=NULL && SUCCEEDED(hr);)
		{
			CHierNode *pNode = rgSelection.GetNext(pos);

			cmdTemp.cmdf = 0;
			hr = pNode->QueryStatus(pguidCmdGroup, 1, &cmdTemp, pCmdText);

			if (SUCCEEDED(hr))
			{
				//
				// cmd is supported iff any node supports cmd
				// cmd is enabled iff all nodes enable cmd
				// cmd is invisible iff any node sets invisibility
				// cmd is latched only if all are latched.
				fSupported	=	fSupported || (cmdTemp.cmdf & OLECMDF_SUPPORTED);
				fEnabled	=	fEnabled && (cmdTemp.cmdf & OLECMDF_ENABLED);
				fInvisible	=	fInvisible || (cmdTemp.cmdf & OLECMDF_INVISIBLE);
				fLatched	=	fLatched && (cmdTemp.cmdf & OLECMDF_LATCHED);

				//NOTE: Currently no commands use NINCHED
				ASSERT(!(cmdTemp.cmdf & OLECMDF_NINCHED));
			}

			// optimization
			if (!fSupported || fInvisible)
				break;
		}
	}

	if (SUCCEEDED(hr) && fSupported)
	{
		Cmd.cmdf = OLECMDF_SUPPORTED;
		
		if (fEnabled)
			Cmd.cmdf |= OLECMDF_ENABLED;
		if (fInvisible)
			Cmd.cmdf |= OLECMDF_INVISIBLE;
		if (fLatched)
			Cmd.cmdf |= OLECMDF_LATCHED;
	}

	return hr;
}

//-----------------------------------------------------------------------------
// CMyProjectHierarchy::ExecSelection
//-----------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::ExecSelection(
    const GUID *pguidCmdGroup,
    DWORD nCmdID,
    DWORD nCmdexecopt,
    VARIANT *pvaIn,
    VARIANT *pvaOut,
	HierNodeList &rgSelection,
	BOOL		 fIsHierCmd)	// TRUE if cmd originated via CVSUiHierarchy::ExecCommand
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pguidCmdGroup);
	HRESULT hr = OLECMDERR_E_NOTSUPPORTED;
	BOOL fHandled = FALSE;

    CExecution multiEx(&GetExecutionCtx());

    // Set multi-Select flag (sets count)
    if(rgSelection.GetCount() > 1)
        GetExecutionCtx().SetMultiSelect(rgSelection.GetCount());

	if(GUID_VsUIHierarchyWindowCmds == *pguidCmdGroup)
	{
		fHandled = TRUE;
		switch(nCmdID)
		{
		case UIHWCMDID_DoubleClick:
		case UIHWCMDID_EnterKey:
			do
			{
				CHierNode *pNode = rgSelection.RemoveHead();
				hr = pNode->DoDefaultAction();
			} while(!rgSelection.IsEmpty());
			break;
		default:
			hr = OLECMDERR_E_NOTSUPPORTED;
			break;
		}
	}
	else if (guidVSStd97 == *pguidCmdGroup)
	{
		if(!fIsHierCmd)
		{	
			// NOTE: We only want to support Cut/Copy/Paste/Delete/Rename commands
			// if focus is in the project window. This means that we should only
			// support these commands if they are dispatched via IVsUIHierarchy
			// interface and not if they are dispatch through IOleCommandTarget
			// during the command routing to the active project/hierarchy.
			switch(nCmdID)
			{
				case cmdidCut:
				case cmdidCopy:
				case cmdidPaste:
				case cmdidRename:
					fHandled = TRUE;
					hr = OLECMDERR_E_NOTSUPPORTED;
					break;
			}
		}
		if(!fHandled)
		{
			switch(nCmdID)
			{
			case cmdidAddNewItem:
			case cmdidAddExistingItem:
			// Forward the AddItem command to the project node whenever our project is 
			// the active project.
				return GetProjectNode()->Exec(pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut);
            case cmdidCut:
				CutSelectionToClipboard();
                fHandled = TRUE;
			    hr = NOERROR;
                break;
            case cmdidCopy:
				CopySelectionToClipboard();
                fHandled = TRUE;
			    hr = NOERROR;
                break;
			case cmdidPaste:
                fHandled = TRUE;
				hr = PasteItemsFromClipboard();
                break;
			default:
				hr = OLECMDERR_E_NOTSUPPORTED;
			}
		}
		
	}
	else
	{	// Assume we don't support other command groups by default.
		hr = OLECMDERR_E_NOTSUPPORTED;
	}
	
	// Node commands
	if (!fHandled)
	{
		for (POSITION pos = rgSelection.GetHeadPosition(); pos!=NULL;)
		{
			CHierNode *pNode = rgSelection.GetNext(pos);
			hr = pNode->Exec(pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut);
			if (FAILED(hr))
				break;
		}
	}

	if (hr == E_ABORT || hr == OLE_E_PROMPTSAVECANCELLED)
		hr = S_OK;
	return hr;
}


//---------------------------------------------------------------------------
// interface: IVsProject
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::IsDocumentInProject(
            /* [in] */ LPCOLESTR pwszMkDocument,
            /* [out] */ BOOL *pfFound,
            /* [out] */ VSDOCUMENTPRIORITY *pdwPriority,
            /* [out] */ VSITEMID *pitemid)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	if (pwszMkDocument == NULL)
		return E_INVALIDARG;
	if (pfFound == NULL)
		return E_POINTER;
	*pfFound = FALSE;
	if (pitemid)
		*pitemid = VSITEMID_NIL;
	if (pdwPriority)
		*pdwPriority = (VSDOCUMENTPRIORITY)0;

	if (IsZombie())
		return E_UNEXPECTED;

	HRESULT hr = NOERROR;

	USES_CONVERSION;
	CFileVwBaseNode* pNode = NULL;
	CFileVwProjNode* pProjNode = NULL;
	hr = VSITEMID2Node(VSITEMID_ROOT, (CHierNode**)&pProjNode);
    IfFailRet(hr);
    ASSERT(pProjNode);
    if (!pProjNode)
        return E_FAIL;

    // Must put special check for project file
    if(_wcsicmp(OLE2CW(pwszMkDocument), T2CW((LPCTSTR)m_strProjFullPath)) == 0)
    {
        if (pitemid)
            *pitemid = VSITEMID_ROOT;
		if (pdwPriority)
			*pdwPriority = DP_Standard;
        *pfFound = TRUE;
    } 
    else
	{
		if ((pNode = pProjNode->GetNodeByFullPath(OLE2CT(pwszMkDocument))) != NULL)
		{
			if (pitemid) 
				*pitemid = (VSITEMID)pNode;
			if (pdwPriority)
				*pdwPriority = DP_Standard;
			*pfFound = TRUE;
		} 
	}

	return hr;
}

//---------------------------------------------------------------------------
// interface: IVsProject
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::GetMkDocument(
            /* [in] */ VSITEMID itemid,
            /* [out] */ BSTR *pbstrMkDocument)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	CString strFullPath;
	CFileVwBaseNode* pNode = NULL;

	if (!pbstrMkDocument)
		return E_INVALIDARG;
	*pbstrMkDocument = NULL;	// always initialize out parameters

	if (IsZombie())
		return E_UNEXPECTED;

	HRESULT hr = VSITEMID2Node(itemid, (CHierNode**)&pNode);
	if (SUCCEEDED(hr))
	{
		strFullPath = pNode->GetFullPath();
		*pbstrMkDocument = strFullPath.AllocSysString();
		if (!*pbstrMkDocument)
			hr = E_OUTOFMEMORY;
	}
	return hr;
}

//---------------------------------------------------------------------------
// interface: IVsProject
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::OpenItem(
            /* [in] */ VSITEMID itemid,
            /* [in] */ REFGUID rguidLogicalView,
            /* [in] */ IUnknown *punkDocDataExisting,
            /* [out] */ IVsWindowFrame **ppWindowFrame)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	if (!ppWindowFrame)
		return E_INVALIDARG;
	*ppWindowFrame = NULL;		// always initialize out parameters

	if (IsZombie())
		return E_UNEXPECTED;

	CFileVwBaseNode *pNode = NULL;
	HRESULT hr = VSITEMID2Node(itemid, (CHierNode**)&pNode);
	if(SUCCEEDED(hr))
	{
        ASSERT(pNode && pNode->IsKindOf(Type_CFileVwFileNode));
        if(pNode && pNode->IsKindOf(Type_CFileVwFileNode))
		{
			hr = ((CFileVwFileNode*) pNode)->OpenDoc(
								FALSE /*fNewFile*/, 
								FALSE /*fUseOpenWith*/,
                                FALSE  /*fShow*/,
								rguidLogicalView,
								punkDocDataExisting, 
								ppWindowFrame);

		} 
		else
			hr = E_UNEXPECTED;
	}
	return hr;
}

//---------------------------------------------------------------------------
// interface: IVsProject
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::GetItemContext(
            /* [in] */ VSITEMID itemid,
            /* [out] */ IServiceProvider **ppSP)
{
	if (!ppSP)
		return E_INVALIDARG;

	if (IsZombie())
		return E_UNEXPECTED;

	// NOTE: this method allows a project to provide project context services 
	// to an item (document) editor. If the project does not need to provide special
	// services to its items then it should return NULL. Under no circumstances
	// should you return the IServiceProvider pointer that was passed to our
	// package from the Environment via IVsPackage::SetSite. The global services
	// will automatically be made available to editors. 
	*ppSP = NULL;

	return NOERROR;
}

//---------------------------------------------------------------------------
// interface: IVsProject
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::GenerateUniqueItemName(
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ LPCOLESTR pwszExt,
            /* [in] */ LPCOLESTR pwszSuggestedRoot,
            /* [out] */ BSTR *pbstrItemName)
{
    if (!pbstrItemName)
        return E_INVALIDARG;
    *pbstrItemName = NULL;
    if (IsZombie())
        return E_UNEXPECTED;

    CFileVwProjNode* pNode = GetProjectNode();
    ExpectedExprRet(pNode != NULL);
    CString strFolderPathTarget = pNode->GetFolderPath();
    if (strFolderPathTarget.IsEmpty())
        return E_UNEXPECTED;
    if (strFolderPathTarget[strFolderPathTarget.GetLength()-1] != '\\')
        strFolderPathTarget += '\\';
    CString strRoot(pwszSuggestedRoot ? pwszSuggestedRoot : L"File");
    if (strRoot.IsEmpty())
        return E_OUTOFMEMORY;

    CString strExt(pwszExt);

    CString strUniqueName;
    CString strFullPathTarget;
    TCHAR szIndex[32];
    for (int i = 1; i < INT_MAX; i++)
    {
        _itot(i, szIndex, 10);
        strUniqueName = strRoot + szIndex + strExt;
        if (strUniqueName.IsEmpty())
            return E_OUTOFMEMORY;
        strFullPathTarget = strFolderPathTarget + strUniqueName;
        if (strFullPathTarget.IsEmpty())
            return E_OUTOFMEMORY;
        if (!LUtilFileExists(strFullPathTarget))
        {
            *pbstrItemName = strUniqueName.AllocSysString();
            if(*pbstrItemName)
                return S_OK;
            else
                return E_OUTOFMEMORY;
            break;
        }
    }

    return E_FAIL;
}

//---------------------------------------------------------------------------
// interface: IVsProject
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::AddItem( 
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ VSADDITEMOPERATION dwAddItemOperation,
            /* [in] */ LPCOLESTR pszItemName,
			/* [in] */ DWORD cFilesToOpen,
            /* [size_is][in] */ LPCOLESTR rgpszFilesToOpen[],
            /* [in] */ HWND hwndDlg,
            /* [retval][out] */ VSADDRESULT *pResult)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    return AddItemWithSpecific(
    /* [in]  VSITEMID              itemidLoc            */ itemidLoc,
    /* [in]  VSADDITEMOPERATION    dwAddItemOperation   */ dwAddItemOperation,
    /* [in]  LPCOLESTR             pszItemName          */ pszItemName,
    /* [in]  ULONG                 cFilesToOpen         */ cFilesToOpen,
    /* [in]  LPCOLESTR             rgpszFilesToOpen[]   */ rgpszFilesToOpen,
    /* [in]  HWND                  hwndDlg              */ hwndDlg,
    /* [in]  VSSPECIFICEDITORFLAGS grfEditorFlags       */ VSSPECIFICEDITOR_DoOpen | 
                                                           VSSPECIFICEDITOR_UseView,
    /* [in]  REFGUID               rguidEditorType      */ GUID_NULL,
    /* [in]  LPCOLESTR             pszPhysicalView      */ NULL,
    /* [in]  REFGUID               rguidLogicalView     */ LOGVIEWID_Primary,
    /* [out] VSADDRESULT *         pResult              */ pResult);

}


//==========================================================================
//                                                               IVsProject2

STDMETHODIMP CMyProjectHierarchy::RemoveItem( 
        /* [in]          */ DWORD    dwReserved,
        /* [in]          */ VSITEMID itemid,
        /* [retval][out] */ BOOL *   pfResult)
{
    _ASSERTE( (itemid != VSITEMID_ROOT) && (itemid != VSITEMID_NIL) );
    if ( (itemid == VSITEMID_ROOT) || (itemid == VSITEMID_NIL) )
        return E_UNEXPECTED;

	_ASSERTE(pfResult != NULL);
	if (pfResult == NULL)
		return E_INVALIDARG;
    *pfResult = FALSE;

    HRESULT hr = E_INVALIDARG;

    //
    // just call into the IVsHierarchyDeleteHandler method
    //
    hr = DeleteItem(DELITEMOP_RemoveFromProject, itemid);

    if (SUCCEEDED(hr))
        *pfResult = TRUE;
    
    return hr;
}
    

STDMETHODIMP CMyProjectHierarchy::ReopenItem( 
        /* [in]          */ VSITEMID         itemid,
        /* [in]          */ REFGUID          rguidEditorType,
        /* [in]          */ LPCOLESTR        pszPhysicalView,
        /* [in]          */ REFGUID          rguidLogicalView,
        /* [in]          */ IUnknown*        punkDocDataExisting,
        /* [retval][out] */ IVsWindowFrame** ppWindowFrame)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    CHierNode* pNode;
	HRESULT hr = VSITEMID2Node(itemid, &pNode);
    IfFailRet(hr);
    ExpectedExprRet(pNode != NULL);

    if(!pNode->IsKindOf(Type_CFileVwFileNode) )
        return E_INVALIDARG;

    return static_cast<CFileVwFileNode*>(pNode)->OpenDocWithSpecific(
                rguidEditorType, 
                pszPhysicalView, 
                rguidLogicalView,
                punkDocDataExisting, 
                ppWindowFrame, 
                FALSE);
}


//                                                               IVsProject2
//==========================================================================


//==========================================================================
//                                                               IVsProject3

//  AddItemWithSpecific is used to add item(s) to the project and 
//  additionally ask the project to open the item using the specified 
//  editor information.  An extension of IVsProject::AddItem().
STDMETHODIMP CMyProjectHierarchy::AddItemWithSpecific(
    /* [in]          ```           */ VSITEMID              itemidLoc,
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
	if (IsZombie())
		return E_UNEXPECTED;
    ExpectedPtrRet(pResult);
    *pResult = ADDRESULT_Failure;

    HRESULT hr = S_OK;

	CFileVwProjNode* pProjectNode = GetProjectNode();
    ExpectedExprRet(pProjectNode != NULL);

	// NOTE: we currently ignore itemidLoc because we only support adding items as
	// children of our project node. Projects that support the notion of folders
	// will want to add the items relative to itemidLoc.
    hr = pProjectNode->AddItem(
        /* [in]  VSADDITEMOPERATION dwAddItemOperation */ dwAddItemOperation,
        /* [in]  LPCOLESTR pszItemName                 */ pszItemName,
        /* [in]  DWORD cFilesToOpen                    */ cFilesToOpen,
        /* [in]  LPCOLESTR rgpszFilesToOpen[]          */ rgpszFilesToOpen,
        /* [in]  HWND hwndDlg                          */ hwndDlg,
        /* [in]  VSSPECIFICEDITORFLAGS grfEditorFlags  */ grfEditorFlags,
        /* [in]  REFGUID               rguidEditorType */ rguidEditorType,
        /* [in]  LPCOLESTR             pszPhysicalView */ pszPhysicalView,
        /* [in]  REFGUID               rguidLogicalView*/ rguidLogicalView,
        /* [out] VSADDRESULT *pResult                  */ pResult);

    return hr;

}


// OpenItemWithSpecific is used to ask the project to open the item using the
// specified editor information.  An extension of IVsProject::OpenItem().
STDMETHODIMP CMyProjectHierarchy::OpenItemWithSpecific(
    /* [in]  */ VSITEMID              itemid,
    /* [in]  */ VSSPECIFICEDITORFLAGS grfEditorFlags,
    /* [in]  */ REFGUID               rguidEditorType,
    /* [in]  */ LPCOLESTR             pszPhysicalView,
    /* [in]  */ REFGUID               rguidLogicalView,
    /* [in]  */ IUnknown*             punkDocDataExisting,
    /* [out] */ IVsWindowFrame**      ppWindowFrame)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;


    HRESULT hr = S_OK;

    ASSERT(grfEditorFlags & VSSPECIFICEDITOR_DoOpen);
    if(grfEditorFlags & VSSPECIFICEDITOR_UseView)
    {   
        // Standard open file. Use IVsProject::OpenItem to open it 
        hr = OpenItem(
            /* [in]  VSITEMID         itemid             */ itemid,
            /* [in]  REFGUID          rguidLogicalView   */ rguidLogicalView,
            /* [in]  IUnknown *       punkDocDataExisting*/ punkDocDataExisting,
            /* [out] IVsWindowFrame** ppWindowFrame      */ ppWindowFrame);
    }
    else
    {   
        // Use IVsProject2::ReopenItem to open it 
        hr = ReopenItem(
            /* [in]  VSITEMID         itemid             */ itemid,
            /* [in]  REFGUID          rguidEditorType    */ rguidEditorType,
            /* [in]  LPCOLESTR        pszPhysicalView    */ pszPhysicalView,
            /* [in]  REFGUID          rguidLogicalView   */ rguidLogicalView,
            /* [in]  IUnknown*        punkDocDataExisting*/ punkDocDataExisting,
            /* [out] IVsWindowFrame** ppWindowFrame      */ ppWindowFrame);
    }

    return hr;
}


//  TransferItem is used to transfer ownership of a running document to the project.
//  The project should call IVsRunningDocumentTable::RenameDocument to transfer 
//  ownership of the document to its hierarchy and give the document a new 
//  itemid within the project.
//  This function is called when an open file is being transferred to 
//  our project. The sequence is for the shell to call AddItemWithSpecific and
//  then use TransferItem to transfer the open document to our project.
STDMETHODIMP CMyProjectHierarchy::TransferItem(
    /* [in] */ LPCOLESTR       pszMkDocumentOld,// passed as pszDocumentOld to IVsRunningDocumentTable::RenameDocument
    /* [in] */ LPCOLESTR       pszMkDocumentNew,// passed as pszDocumentNew to IVsRunningDocumentTable::RenameDocument
    /* [in] */ IVsWindowFrame* punkWindowFrame) // optional if document not open
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedExprRet(pszMkDocumentOld);
    ExpectedExprRet(pszMkDocumentNew);

    HRESULT hr = S_OK;
    
    // get the document from the running doc table
    // We get the document from the running doc table so that we can see 
    // if it is transient - if so we don't continuing on.
    IVsRunningDocumentTable *pIVsRunningDocumentTable = _VxModule.GetIVsRunningDocumentTable();
    ExpectedExprRet(pIVsRunningDocumentTable != NULL);

    VSDOCCOOKIE dwCookie = 0;
    VSITEMID    itemid   = VSITEMID_NIL;
    hr = pIVsRunningDocumentTable->FindAndLockDocument(
        /* [in]  VSRDTFLAGS     dwRDTLockType*/ RDT_NoLock,
        /* [in]  LPCOLESTR      pszMkDocument*/ pszMkDocumentOld,
        /* [out] IVsHierarchy** ppHier       */ NULL,
        /* [out] VSITEMID*      pitemid      */ NULL,
        /* [out] IUnknown**     ppunkDocData */ NULL,
        /* [out] VSCOOKIE*      pdwCookie    */ &dwCookie);
    IfFailRet(hr);

    VSRDTFLAGS grfFlags = 0;
    hr = pIVsRunningDocumentTable->GetDocumentInfo(dwCookie, &grfFlags, NULL, NULL, NULL, NULL, NULL, NULL);
    if (FAILED(hr) || (grfFlags & RDT_NonCreatable))
        return E_ABORT;

    // Now see if the document is in the project. If not, we fail
    BOOL fFound = FALSE;
    VSDOCUMENTPRIORITY dwPriority = (VSDOCUMENTPRIORITY)0;
    hr = IsDocumentInProject(pszMkDocumentNew, &fFound, &dwPriority, &itemid);
    if (FAILED(hr) || !fFound)
    {
        CFileVwProjNode* pProjNode=GetProjectNode();
        if (pProjNode != NULL)
            LUtilSetErrString2(IDS_E_FILENOTINPRJECT, pszMkDocumentNew, pProjNode->GetName());
        return E_FAIL;
    }

    ExpectedExprRet( (itemid != VSITEMID_NIL) && (itemid != VSITEMID_ROOT) );
    hr = pIVsRunningDocumentTable->RenameDocument(
        pszMkDocumentOld, 
        pszMkDocumentNew, 
        GetIVsUIHierarchy(), 
        itemid);
    IfFailRet(hr);

    //  Change the caption if we are passed a window frame
    if (punkWindowFrame != NULL) 
    {
            CComVariant cvarCaption = L"%3";
            punkWindowFrame->SetProperty(VSFPROPID_OwnerCaption, cvarCaption);
    }

    return S_OK;
}

//                                                               IVsProject3
//==========================================================================

//---------------------------------------------------------------------------
// interface: IVsPersistHierarchyItem
//---------------------------------------------------------------------------


STDMETHODIMP CMyProjectHierarchy::SaveItem(
        /* [in]  */ VSSAVEFLAGS dwSave,
        /* [in]  */ LPCOLESTR   pszSilentSaveAsName,
        /* [in]  */ VSITEMID    itemid,    
        /* [in]  */ IUnknown *  punkDocData,
        /* [out] */ BOOL *      pfCanceled)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pfCanceled);
    *pfCanceled = FALSE;

    CHierNode* pNode = NULL;
	HRESULT hr = VSITEMID2Node(itemid, (CHierNode**)&pNode);
    if( !pNode )
        return NOERROR;

    hr = CVsHierarchy::SaveItem(dwSave, pszSilentSaveAsName, itemid, punkDocData, pfCanceled);
    _IfFailRet(hr);

    // update all properties when saving the file 
    if (pNode->IsKindOf(Type_CFileVwFileNode))
    {
        HRESULT hrTemp = static_cast<CFileVwFileNode*>(pNode)->OnPropertyChanged(DISPID_UNKNOWN, FALSE);
        ASSERT(SUCCEEDED(hrTemp));
    }

    return hr;
}


//---------------------------------------------------------------------------
// interface: IPersistFileFormat
//-----------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::GetClassID(CLSID *pClassID)
{
	if (!pClassID)
		return E_INVALIDARG;

	*pClassID = GUID_MyProjectType;
	return S_OK;
}

//---------------------------------------------------------------------------
// interface: IPersistFileFormat
//-----------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::IsDirty(BOOL* pfIsDirty)
{
	ASSERT(pfIsDirty);
	if (!pfIsDirty)
		return E_INVALIDARG;

	if (IsZombie())
		return E_UNEXPECTED;

    *pfIsDirty = TRUE;
	if (GetProjectNode())
		 *pfIsDirty = GetProjectNode()->IsProjectFileDirty();

    return S_OK;

}

//---------------------------------------------------------------------------
// interface: IPersistFileFormat
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::InitNew(DWORD nFormatIndex)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	// The Environment creates new and loads existing projects by calling 
	// IVsProjectFactory::CreateProject. It never calls IPersistFileFormat::
	// InitNew or Load directly. The most common implementation of CreateProject
	// creates new projects by cloning a template file and then calling 
	// internally our own IPersistFileFormat::Load, thus InitNew should
	// never be called. Neverless, we have nothing we need to do here except
	// to set our project as dirty.

	GetProjectNode()->SetProjectFileDirty(TRUE);
	return S_OK;
}

//---------------------------------------------------------------------------
// interface: IPersistFileFormat
//-----------------------------------------------------------------------------

STDMETHODIMP CMyProjectHierarchy::Load
(
LPCOLESTR pszFileName,
DWORD grfMode,
BOOL fReadOnly
)
{
    ExpectedPtrRet(pszFileName);
    HRESULT hr = S_OK;
    HRESULT hrTemp = S_OK;

    if (grfMode != 0 && !(grfMode & STGM_READ))
        return E_INVALIDARG;

    if (IsZombie())
        return E_UNEXPECTED;

    // $NOTE: We always open in ReadOnly mode, so we ignore the last param.
    CComPtr<IVsStructuredFileIO> srpIVsStructuredFileIO;
    hr = _VxModule.QueryService(SID_SVsStructuredFileIO, IID_IVsStructuredFileIO, (void **)&srpIVsStructuredFileIO);
    if (FAILED(hr))
        return hr;
    ASSERT(srpIVsStructuredFileIO);
    ExpectedExprRet(srpIVsStructuredFileIO != NULL);

    ULONG nFormatIndex;
    CComPtr<IVsPropertyFileIn> srpIVsPropertyFileInOuter;
    CComBSTR bstrFormatVersion;

    hr = srpIVsStructuredFileIO->OpenExisting(
                pszFileName,
                FILE_SHARE_READ,
                OPEN_EXISTING,
                FILE_FLAG_SEQUENTIAL_SCAN,
                NULL /*pIVsStructuredFileIOHelper*/,
                &nFormatIndex,
                &srpIVsPropertyFileInOuter,
                &bstrFormatVersion);
    ASSERT(SUCCEEDED(hr));      
    if (FAILED(hr))
        return hr;

    for (;;)
    {
        WCHAR rgwchSectionName[512];

        CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamInInner;
        VSPROPERTYSTREAMPROPERTYTYPE vspspt;

        CComVariant varValue;

        hr = srpIVsPropertyFileInOuter->Read(
                NUMBER_OF(rgwchSectionName),
                rgwchSectionName,
                NULL,
                &vspspt,
                &varValue,
                NULL);
        ASSERT(SUCCEEDED(hr));
        if (FAILED(hr))
            break;

        if (rgwchSectionName[0] == L'\0')
            break;

        if (vspspt != VSPSPT_PROPERTY_SECTION || varValue.vt != VT_UNKNOWN || (varValue.punkVal == NULL))
        {
            VSASSERT(varValue.vt == VT_UNKNOWN, _T("Property stream implementation error: property section vt != VT_UNKNOWN"));
            hr = E_UNEXPECTED; 
            break;
        }

        hr = varValue.punkVal->QueryInterface(IID_IVsPropertyStreamIn, (void **) &srpIVsPropertyStreamInInner);
        ASSERT(SUCCEEDED(hr));
        if (FAILED(hr))
            break;

        if (_wcsicmp(rgwchSectionName, STR_GENERALSECTION) == 0)
            hr = LoadGeneralProperties(srpIVsPropertyStreamInInner);
        else if (_wcsicmp(rgwchSectionName, STR_CONFIGSECTION) == 0)
            hr = m_pCfgProvider->LoadCfgs(srpIVsPropertyStreamInInner);
        else if (_wcsicmp(rgwchSectionName, STR_FILESSECTION) == 0)
            hr = LoadFiles(srpIVsPropertyStreamInInner);
        else if (_wcsicmp(rgwchSectionName, STR_STARTUPSERVICES) == 0)
            hr = m_projectStartupServices.Load(srpIVsPropertyStreamInInner);
        else if (_wcsicmp(rgwchSectionName, STR_GLOBALSSECTION) == 0)
            hr = LoadGlobals(srpIVsPropertyStreamInInner);
        else
        {
            // NOTE: we'll just ignore sections without recognized names
        }

        if (srpIVsPropertyStreamInInner != NULL)
        {
            hrTemp = srpIVsPropertyStreamInInner->SkipToEnd();
            if (SUCCEEDED(hr)) hr = hrTemp;
        }
        if (FAILED(hr))
            break;
    }

    hrTemp = srpIVsPropertyFileInOuter->SkipToEnd();
    if (SUCCEEDED(hr)) hr = hrTemp;
	hrTemp = srpIVsPropertyFileInOuter->Close();
    if (SUCCEEDED(hr)) hr = hrTemp;

    m_nFormatIndex = nFormatIndex;

    GetProjectNode()->SetProjectFileDirty(FALSE);

    return hr;
}

//
//  Persistance helpers for Loading CMyProjectHierarchy project file
//

HRESULT CMyProjectHierarchy::LoadGeneralProperties
(
IVsPropertyStreamIn *pIVsPropertyStreamIn
) 
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ASSERT(pIVsPropertyStreamIn);
    ExpectedPtrRet(pIVsPropertyStreamIn);
    HRESULT hr = S_OK;

    for (;;)
    {
        CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamIn;
        VSPROPERTYSTREAMPROPERTYTYPE vspspt;

        WCHAR rgwchPropName[_MAX_PATH];

        CComVariant varValue;

        hr = pIVsPropertyStreamIn->Read(NUMBER_OF(rgwchPropName), rgwchPropName, NULL, &vspspt, &varValue, NULL);
        ASSERT(SUCCEEDED(hr));
        if (FAILED(hr))
            return hr;

        if (rgwchPropName[0] == L'\0')
            break;

        if (vspspt != VSPSPT_SIMPLE || varValue.vt != VT_BSTR)
        {
            ASSERT(vspspt == VSPSPT_SIMPLE && varValue.vt == VT_BSTR);
            return E_UNEXPECTED;
        }

        if (_wcsicmp(rgwchPropName, STR_SCCPROJECTNAME) == 0)
            m_strSccProjectName = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_SCCLOCALPATH) == 0)
            m_strSccLocalPath = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_SCCAUXPATH) == 0)
            m_strSccAuxPath = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_SCCPROVIDER) == 0)
            m_strSccProvider = varValue.bstrVal;
        else if (_wcsicmp(rgwchPropName, STR_OWNERKEY) == 0)
            SetOwnerKey(varValue.bstrVal);
        else if (_wcsicmp(rgwchPropName, STR_PROJECTIDGUID) == 0)
        {
            if(::SysStringLen(varValue.bstrVal))
            {   
                // Convert to GUID; ignore failures since the shell will regenerate
                // the project GUID if we don't set one here.
                GUID guidProject;
                if (SUCCEEDED(CLSIDFromString(varValue.bstrVal, &guidProject)))
                    SetGuidProperty(VSITEMID_ROOT, VSHPROPID_ProjectIDGuid, guidProject);
            }
        }
        else
        {
            // NOTE: we'll just ignore properties without recognized names
        }
    }

    return hr;
}


HRESULT CMyProjectHierarchy::LoadFiles
(
IVsPropertyStreamIn *pIVsPropertyStreamIn
) 
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	ASSERT(pIVsPropertyStreamIn);
    ExpectedPtrRet(pIVsPropertyStreamIn);
	HRESULT hr = S_OK;
    HRESULT hrTemp = S_OK;

	for (;;)
	{
		CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamInInner;
		VSPROPERTYSTREAMPROPERTYTYPE vspspt;

		WCHAR rgwchFileName[_MAX_PATH];
		CComVariant varValue;

		// Read next property section for a file. The name of the section is the path to the file.
		hr = pIVsPropertyStreamIn->Read(NUMBER_OF(rgwchFileName), rgwchFileName, NULL, &vspspt, &varValue, NULL);
		ASSERT(SUCCEEDED(hr));
		if (FAILED(hr))
			return hr;

		if (rgwchFileName[0] == L'\0')
			break;
        if (hr == S_FALSE) // the name has been truncated so skip this file
            continue;

        if (vspspt != VSPSPT_PROPERTY_SECTION || varValue.vt != VT_UNKNOWN || (varValue.punkVal == NULL))
		{
			ASSERT(vspspt == VSPSPT_PROPERTY_SECTION && varValue.vt == VT_UNKNOWN);
			return E_UNEXPECTED;
		}

		hr = varValue.punkVal->QueryInterface(IID_IVsPropertyStreamIn, (void **) &srpIVsPropertyStreamInInner);
		ASSERT(SUCCEEDED(hr));
		if (FAILED(hr))
			return hr;
        ExpectedExprRet(srpIVsPropertyStreamInInner != NULL);

		// Read the first property in the PROPERTY_SECTION for the file. it should be our "ProjRelPath" property
		WCHAR rgwchName[_MAX_PATH];
		CComVariant varPropValue;

		hr = srpIVsPropertyStreamInInner->Read(NUMBER_OF(rgwchName), rgwchName, NULL, &vspspt, &varPropValue, NULL);
		ASSERT(SUCCEEDED(hr));
		if (FAILED(hr))
			return hr;

		if (_wcsicmp(rgwchName, STR_PROJRELPATH) == 0 && varPropValue.vt == VT_BSTR)
		{
			CFileVwProjNode* pFileVwProjNode = static_cast<CFileVwProjNode*>(GetRootNode());
			CFileVwFileNode *pFileVwNode = NULL;
			CString strFullPath;

			if (varPropValue.bstrVal[0] == L'T')
			{
				strFullPath = GetProjectLocation();
				strFullPath += rgwchFileName;
			}
			else
				strFullPath = rgwchFileName;
			
            hr = pFileVwProjNode->AddExistingFile(strFullPath, &pFileVwNode, /* fSilent */ TRUE, /* fLoad */ TRUE);
			if (SUCCEEDED(hr) && pFileVwNode)
            {
                hr = pFileVwNode->Load(srpIVsPropertyStreamInInner);

                // Store full file path so that we can check file at a later stage. We need
                // to do this check after the call to RegisterSccProject because if we are
                // opening the project from source code control the files will not be copied
                // into the project folder by source code control until RegisterSccProject
                // is called.
                CString *strSavePath = new CString();
                *strSavePath = strFullPath;
                m_rgpFilePaths.Add(strSavePath);
            }
		}
		else
		{
			ASSERT(FALSE); // corrupted file. 
			// NOTE: we'll just ignore this file and proceed to try to read the next
		}

		if (srpIVsPropertyStreamInInner != NULL)
		{
            hrTemp = srpIVsPropertyStreamInInner->SkipToEnd();
            if (SUCCEEDED(hr)) hr = hrTemp;
        }
        if (FAILED(hr))
            return hr;
	}

	return hr;
}


//---------------------------------------------------------------------------
// interface: IPersistFileFormat
//-----------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::Save(
    LPCOLESTR pszFileNameIn,
    BOOL        fRemember,
    DWORD nFormatIndex)
{
    // Write your project information in an appropriate format.
    // This sample wtite to a file using IVsStructuredFileIO and IVsPropertyStreamOut.
    // You may store this information in a database, XML file, etc.
    // VB and VC use an XML format however we do not require you to use XML.
    // If you decide to use a schema for this and rely on XML, this is proprietary
    // to your project system. Microsoft do not provide a template schema.
    // Replace the following code as appropriate.
    USES_CONVERSION;

    HRESULT hr = S_OK;

    if (IsZombie())
        return E_UNEXPECTED;

    
    LPCOLESTR pszFileName = NULL;
    BOOL fClearDirty = FALSE;

    if (pszFileNameIn == NULL)
    {
        pszFileName = T2COLE(m_strProjFullPath);
        fClearDirty = TRUE;

        if (NULL == pszFileName)
        {
            ASSERT(pszFileName != NULL);
            return E_UNEXPECTED;
        }
    }
    else
    {
        pszFileName = pszFileNameIn;

        CString strFileName(pszFileName);
        // making sure the file was saved as in the prj location.
        CString strNewProjectPath = LUtilStripName(strFileName);
        if (strNewProjectPath.CompareNoCase(m_strProjLocation))
        {
            _VxModule.SetErrorInfo(E_FAIL, IDS_E_PATHNOTINPRJ, 0);
            return E_FAIL;
        }

        if (fRemember)
        {
            CString strNewProjectName = LUtilStripPath(strFileName);
            CComBSTR cbstrNewProjectName(strNewProjectName);
            // we must rename the project file
            hr = put_Name(cbstrNewProjectName);
            IfFailRet(hr);
            fClearDirty = TRUE;
        }
    }

    // ignore file change notifications
    CSuspendFileChanges suspendFileChanges(
        /* [in] const CString& strMkDocument      */ CString(pszFileName), 
        /* [in] BOOL           fSuspendNow = TRUE */ TRUE );

    CComPtr<IVsStructuredFileIO> srpIVsStructuredFileIO;
    hr = _VxModule.QueryService(SID_SVsStructuredFileIO, IID_IVsStructuredFileIO, (void **) &srpIVsStructuredFileIO);
    IfFailRet(hr);
    CComPtr<IVsPropertyFileOut> srpIVsPropertyFileOut;

    hr = srpIVsStructuredFileIO->CreateNew(
                pszFileName,
                nFormatIndex,
                0,
                CREATE_ALWAYS,
                0,
                NULL,           // IVsStructuredFileIOHelper,
                NULL,           // szFormatVersion
                NULL,           // szDescription
                &srpIVsPropertyFileOut);
    if (FAILED(hr))
        return hr;

    CComPtr<IVsPropertyStreamOut> srpIVsPropertyStreamOut;
    VSCOOKIE dwCookie;

    hr = srpIVsPropertyFileOut->BeginPropertySection(STR_GENERALSECTION, NULL, &srpIVsPropertyStreamOut, &dwCookie);
    if (FAILED(hr))
        return hr;
    hr = SaveGeneralProperties(srpIVsPropertyStreamOut);
    (void)srpIVsPropertyFileOut->EndPropertySection(dwCookie);
    if (FAILED(hr))
        return hr;
    srpIVsPropertyStreamOut.Release();

    hr = srpIVsPropertyFileOut->BeginPropertySection(STR_CONFIGSECTION, NULL, &srpIVsPropertyStreamOut, &dwCookie);
    if (FAILED(hr))
        return hr;
    hr = m_pCfgProvider->SaveCfgs(srpIVsPropertyStreamOut);
    (void)srpIVsPropertyFileOut->EndPropertySection(dwCookie);
    if (FAILED(hr))
        return hr;
    srpIVsPropertyStreamOut.Release();

    hr = srpIVsPropertyFileOut->BeginPropertySection(STR_FILESSECTION, NULL, &srpIVsPropertyStreamOut, &dwCookie);
    if (FAILED(hr))
        return hr;
    hr = SaveFiles(srpIVsPropertyStreamOut);
    (void) srpIVsPropertyFileOut->EndPropertySection(dwCookie);
    if (FAILED(hr))
        return hr;
    srpIVsPropertyStreamOut.Release();

    hr = srpIVsPropertyFileOut->BeginPropertySection(STR_STARTUPSERVICES, NULL, &srpIVsPropertyStreamOut, &dwCookie);
    if (FAILED(hr))
        return hr;
    hr = m_projectStartupServices.Save(srpIVsPropertyStreamOut);
    (void) srpIVsPropertyFileOut->EndPropertySection(dwCookie);
    if (FAILED(hr))
        return hr;
    srpIVsPropertyStreamOut.Release();

    hr = srpIVsPropertyFileOut->BeginPropertySection(STR_GLOBALSSECTION, NULL, &srpIVsPropertyStreamOut, &dwCookie);
    IfFailRet(hr);
    hr = SaveGlobals(srpIVsPropertyStreamOut);
    (void) srpIVsPropertyFileOut->EndPropertySection(dwCookie);
    IfFailRet(hr);
    srpIVsPropertyStreamOut.Release();

    hr = srpIVsPropertyFileOut->Close();
    if (FAILED(hr))
        return hr;

    srpIVsPropertyFileOut.Release();

    if (fRemember)
    {
        if (pszFileNameIn != NULL)
            m_strProjFullPath = pszFileNameIn;
        m_nFormatIndex = nFormatIndex;
    }

    if (fClearDirty)
        GetProjectNode()->SetProjectFileDirty(FALSE);

    return hr;
}


//
//  Persistance helpers for Saving CMyProjectHierarchy project file
//

HRESULT CMyProjectHierarchy::SaveGeneralProperties
(
IVsPropertyStreamOut *pIVsPropertyStreamOut
) 
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    USES_CONVERSION;

    ASSERT(pIVsPropertyStreamOut);
    ExpectedPtrRet(pIVsPropertyStreamOut);
    HRESULT hr = S_OK;

    if(!m_strSccProjectName.IsEmpty())
    {
        hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_SCCPROJECTNAME,
                                        T2COLE(m_strSccProjectName),
                                        NULL /*szLineComment*/);
        IfFailRet(hr);

        hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_SCCLOCALPATH,
                                        T2COLE(m_strSccLocalPath),
                                        NULL /*szLineComment*/);
        IfFailRet(hr);

        hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_SCCAUXPATH,
                                        T2COLE(m_strSccAuxPath),
                                        NULL /*szLineComment*/);
        IfFailRet(hr);

        hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_SCCPROVIDER,
                                        T2COLE(m_strSccProvider),
                                        NULL /*szLineComment*/);
        IfFailRet(hr);

    }
    if (GetOwnerKey().Length() != NULL)
    {
        hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                        STR_OWNERKEY,
                                        GetOwnerKey(),
                                        NULL /*szLineComment*/);
        IfFailRet(hr);
    }

    // Write our project GUID
    GUID guidProject;
    if (SUCCEEDED(GetGuidProperty(VSITEMID_ROOT, VSHPROPID_ProjectIDGuid, &guidProject)))
    {
        if (guidProject != GUID_NULL)
        {
            WCHAR wszGUID[40];
            if (StringFromGUID2(guidProject, wszGUID, 40) != 0)
            {
                hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
                                            STR_PROJECTIDGUID,
                                            wszGUID,
                                            NULL /*szLineComment*/);
                IfFailRet(hr);
            }
        }
    }

    return hr;
}


HRESULT CMyProjectHierarchy::SaveFiles
(
IVsPropertyStreamOut *pIVsPropertyStreamOut
) 
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	USES_CONVERSION;

	HRESULT hr = S_OK;

	ASSERT(GetRootNode());
	CHierNode* pHierNode = GetRootNode()->GetHead();
	CComVariant varValue;
	while(SUCCEEDED(hr) && pHierNode != NULL)
	{
		CFileVwBaseNode *pFileVwNode = static_cast<CFileVwBaseNode*>(pHierNode);
		CString strProjRelPath;

		hr = pFileVwNode->GetProjRelativePath(strProjRelPath);
		if (FAILED(hr))
			return hr;
		BOOL fProjRelPath = (hr == S_OK ? TRUE : FALSE);

		// write out a PropertySection for each item keyed with the CanonicalName of the item
		CComPtr<IVsPropertyStreamOut> srpFileSectionPropStmOut;
		VSCOOKIE dwCookie;
		hr = pIVsPropertyStreamOut->BeginPropertySection(T2COLE(strProjRelPath), NULL, &srpFileSectionPropStmOut, &dwCookie);
		if (FAILED(hr))
			return hr;
		hr = srpFileSectionPropStmOut->WriteSzAsBSTR(
										STR_PROJRELPATH,
										(fProjRelPath ? L"T" : L"F"),
										NULL /*szLineComment*/);
        if (SUCCEEDED(hr))
		    hr = pFileVwNode->Save(srpFileSectionPropStmOut);

		(void)pIVsPropertyStreamOut->EndPropertySection(dwCookie);
		if (FAILED(hr))
			return hr;

		// advance to next node in hierarchy
		pHierNode = pHierNode->GetNext();
	}
	return hr;
}


//---------------------------------------------------------------------------
// interface: IPersistFileFormat
//-----------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::SaveCompleted(LPCOLESTR pszFileName)
{
	if (IsZombie())
		return E_UNEXPECTED;

	// We don't actually do anything on SaveCompleted.
	return NOERROR;
}

//---------------------------------------------------------------------------
// interface: IPersistFileFormat
//-----------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::GetCurFile
(
LPOLESTR *ppszFileName,
DWORD *pnFormatIndex
)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	USES_CONVERSION;
	HRESULT hr = E_INVALIDARG;
    ExpectedPtrRet(ppszFileName);
    ExpectedPtrRet(pnFormatIndex);
	DWORD dwLen = m_strProjFullPath.GetLength() + sizeof(OLECHAR);
	*ppszFileName = (LPOLESTR)::CoTaskMemAlloc(dwLen * sizeof(OLECHAR));
	if (NULL != *ppszFileName)
	{
		wcscpy(*ppszFileName, T2COLE(m_strProjFullPath));
		*pnFormatIndex = m_nFormatIndex;
		hr = S_OK;
	}
	else
	{
		hr = E_OUTOFMEMORY;
	}
	return hr;
}

//---------------------------------------------------------------------------
// interface: IPersistFileFormat
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::GetFormatList(LPOLESTR *ppszFormatList)
{
	USES_CONVERSION;

	if (!ppszFormatList)
		return E_INVALIDARG;
	*ppszFormatList = NULL;

	if (IsZombie())
		return E_UNEXPECTED;

	CString strTypeName;
    if (!strTypeName.LoadString(IDS_PROJECT_TYPE))
        return E_FAIL;

	CComPtr<IVsStructuredFileIO> srpIVsStructuredFileIO;
	HRESULT hr = _VxModule.QueryService(SID_SVsStructuredFileIO, IID_IVsStructuredFileIO, (void **)&srpIVsStructuredFileIO);
	ASSERT(srpIVsStructuredFileIO);
	if (FAILED(hr))
		return hr;

	hr = srpIVsStructuredFileIO->GetFormatList(T2COLE(strTypeName), L"mycp", ppszFormatList);

	return hr;
}


//---------------------------------------------------------------------------
// interface ISupportErrorInfo
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IVsUIHierarchy,
		&IID_IVsHierarchy,
		&IID_IVsPersistHierarchyItem,
		&IID_IVsProject,
		&IID_IPersistFileFormat,
		&IID_IPersist,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

//---------------------------------------------------------------------------
// RegisterSccProject
// Send our opaque source code control settings to the scc manager.
// This called just after opening a project.
//---------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::RegisterSccProject()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;


    USES_CONVERSION;

    HRESULT hr = S_OK;
    // Only once please!
    if(!m_fRegisteredWithScc)
    {   // If no scc project name then assume not under source control
        if (!m_strSccProjectName.IsEmpty())
        {
            CComPtr<IVsSccManager2> srpIVsSccManager2;
            hr = _VxModule.QueryService(SID_SVsSccManager, IID_IVsSccManager2, (void **)&srpIVsSccManager2);
            if(SUCCEEDED(hr))
            {   
                hr = srpIVsSccManager2->RegisterSccProject(
                    /* [in] IVsSccProject2 *pscp2Project */ QI_cast<IVsSccProject2>(this),  // Project pointer
                    /* [in] LPCOLESTR pszSccProjectName  */ T2COLE(m_strSccProjectName),    // opaque setting
                    /* [in] LPCOLESTR pszSccAuxPath      */ T2COLE(m_strSccAuxPath),        // opaque setting
                    /* [in] LPCOLESTR pszSccLocalPath    */ T2COLE(m_strSccLocalPath),      // opaque setting
                    /* [in] LPCOLESTR pszProvider        */ T2COLE(m_strSccProvider));      // opaque setting
                m_fRegisteredWithScc = true;
                SccGlyphChanged(0, NULL, NULL,NULL);
            }
        }
    }
    ASSERT(SUCCEEDED(hr));
    return hr;
}

//---------------------------------------------------------------------------
// Unregisters us from the SCC manager
//---------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::UnregisterSccProject()
{
    HRESULT hr = S_OK;
    if (m_fRegisteredWithScc)
    {
        CComPtr<IVsSccManager2> srpIVsSccManager2;
        hr = _VxModule.QueryService(SID_SVsSccManager, IID_IVsSccManager2, (void **)&srpIVsSccManager2);
        if(SUCCEEDED(hr))
        {
            hr = srpIVsSccManager2->UnregisterSccProject(
                /* [in] IVsSccProject2 *pscp2Project */ QI_cast<IVsSccProject2>(this));
            m_fRegisteredWithScc = false;
        }
    }
    return hr;
}


//---------------------------------------------------------------------------
// Interface: IVsSccProject2
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::SccGlyphChanged( 
    /* [in] */ int cAffectedNodes,
    /* [size_is][in] */ const VSITEMID rgitemidAffectedNodes[],
    /* [size_is][in] */ const VsStateIcon rgsiNewGlyphs[],
    /* [size_is][in] */ const DWORD rgdwNewSccStatus[])
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;
    int i;
    CHierNode *pNode = NULL;
    
    if (cAffectedNodes==0 || !rgitemidAffectedNodes || !rgsiNewGlyphs)
    {
        // Update everything
        VsStateIcon siStateIcon = STATEICON_NOSTATEICON;
        CFileVwProjNode* pProjNode = GetProjectNode();
        if (!pProjNode)
            return E_UNEXPECTED;

        // ReDraw will cause GetIconIndex, which updates the glyphs to be called
        pProjNode->ReDraw(
            /* BOOL bUpdateIcon */FALSE, 
            /* BOOL bUpdateStateIcon */ TRUE, 
            /* BOOL bUpdateText */ FALSE);
        pNode = pProjNode->GetHeadEx();
        while (pNode != NULL)
        {
            if (pNode->IsKindOf(Type_CFileVwBaseNode))
            {
                // ReDraw will cause GetIconIndex, which updates the glyphs to be called
                pNode->ReDraw(
                    /* BOOL bUpdateIcon */FALSE, 
                    /* BOOL bUpdateStateIcon */ TRUE, 
                    /* BOOL bUpdateText */ FALSE);
            }
            pNode = pNode->GetNext();
        }
    }
    else
    {
	    for (i = 0; i < cAffectedNodes; i++) 
        {
		    if (SUCCEEDED(hr = VSITEMID2Node(rgitemidAffectedNodes[i], &pNode))) 
            {
			    if ( pNode && pNode->IsKindOf(Type_CFileVwBaseNode))
                {
                    // ReDraw will cause GetIconIndex, which updates the glyphs to be called
                     pNode->ReDraw(
                        /* BOOL bUpdateIcon */FALSE, 
                        /* BOOL bUpdateStateIcon */ TRUE, 
                        /* BOOL bUpdateText */ FALSE);
			    }
		    }
        }
	}
    
    return hr;
}


//---------------------------------------------------------------------------
// Interface: IVsSccProject2
// This is generally called upon "add project to scc", but could also
// be used to just change some of the settings.
//
// Regardless of the reason, these strings are for us to persist in
// the project file, and they are opaque.
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::SetSccLocation( 
	/* [in] */ LPCOLESTR pszSccProjectName,
	/* [in] */ LPCOLESTR pszSccAuxPath,
	/* [in] */ LPCOLESTR pszSccLocalPath,
	/* [in] */ LPCOLESTR pszSccProvider)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    BOOL bAnyChanged = FALSE;
    if(m_strSccProjectName != pszSccProjectName)
    {
        bAnyChanged = TRUE;
        m_strSccProjectName = pszSccProjectName;
    }
    if(m_strSccAuxPath != pszSccAuxPath)
    {
        bAnyChanged = TRUE;
        m_strSccAuxPath = pszSccAuxPath;
    }
    if(m_strSccLocalPath != pszSccLocalPath)
    {
        bAnyChanged = TRUE;
        m_strSccLocalPath = pszSccLocalPath;
    }
    if(m_strSccProvider != pszSccProvider)
    {
        bAnyChanged = TRUE;
        m_strSccProvider = pszSccProvider;
    }
    if(bAnyChanged)
    {	
		GetProjectNode()->SetProjectFileDirty(TRUE);
    }
    return S_OK;
}


//---------------------------------------------------------------------------
// Interface: IVsSccProject2
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::GetSccFiles( 
	/* [in] */ VSITEMID itemid,
	/* [out] */ CALPOLESTR __RPC_FAR *pCaStringsOut,
	/* [out] */ CADWORD __RPC_FAR *pCaFlagsOut)
{
		ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

USES_CONVERSION;

	HRESULT hr = E_INVALIDARG;
	ASSERT(itemid != VSITEMID_NIL && pCaStringsOut && pCaFlagsOut);
	if(itemid != VSITEMID_NIL && pCaStringsOut && pCaFlagsOut)
	{
		pCaStringsOut->cElems = 0;
		pCaStringsOut->pElems = NULL;
		CHierNode* pNode = NULL;
		VSITEMID2Node(itemid, &pNode);
		if(pNode)
		{	
			if(pNode == GetRootNode() || pNode->IsKindOf(Type_CFileVwProjNode))
			{	
				pCaStringsOut->cElems = 1;
				// Allocate an array of one
				hr = E_OUTOFMEMORY;
				pCaStringsOut->pElems = (LPOLESTR*)::CoTaskMemAlloc(sizeof(LPOLESTR));
				if(pCaStringsOut->pElems)
				{	// Allocate the item
					CString strName;
					// Return .mycp file for root node, full path for all others.
					if(pNode == GetRootNode())
					{
						ASSERT(!m_strProjFullPath.IsEmpty());
						strName = m_strProjFullPath;
					}
					else
					{
						strName = static_cast<CFileVwFileNode*>(pNode)->GetFileName();
					}

					pCaStringsOut->pElems[0] = (LPOLESTR)::CoTaskMemAlloc((strName.GetLength()+1)*sizeof(WCHAR));
					if(pCaStringsOut->pElems[0])
					{
						wcscpy(pCaStringsOut->pElems[0], T2COLE(strName));
						hr = S_OK;
					}
				}
			}
			else
			{
				hr = E_NOTIMPL;
			}
		}
	}
	return hr;
}

//---------------------------------------------------------------------------
// Interface: IVsSccProject2
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::GetSccSpecialFiles( 
	/* [in] */ VSITEMID itemid,
    /* [in] */ LPCOLESTR pszSccFile,
    /* [out] */ CALPOLESTR __RPC_FAR *pCaStringsOut,
	/* [out] */ CADWORD __RPC_FAR *pCaFlagsOut)
{
	// returning E_NOTIMPL indicates no special files
	return E_NOTIMPL;
}

//---------------------------------------------------------------------------
// Interface: IVsHierarchyDeleteHandler
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::QueryDeleteItem(
		/* [in] */ VSDELETEITEMOPERATION dwDelItemOp,
		/* [in] */ VSITEMID itemid,
		/* [out]*/ BOOL *pfCanDelete)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	ExpectedPtrRet(pfCanDelete);
	if (itemid == VSITEMID_SELECTION)
    {
        ASSERT(FALSE);
        return E_INVALIDARG;
    }

    if(VSITEMID_ROOT == itemid)
	    *pfCanDelete = (dwDelItemOp == DELITEMOP_RemoveFromProject);
    else
    	*pfCanDelete = (dwDelItemOp == DELITEMOP_RemoveFromProject || 
                        dwDelItemOp == DELITEMOP_DeleteFromStorage);
		
	return S_OK;
}

//---------------------------------------------------------------------------
// Interface: IVsHierarchyDeleteHandler
//---------------------------------------------------------------------------
STDMETHODIMP CMyProjectHierarchy::DeleteItem(
    /* [in] */ VSDELETEITEMOPERATION dwDelItemOp,
    /* [in] */ VSITEMID itemid)
{
    if ( (itemid == VSITEMID_SELECTION) || 
         (itemid == VSITEMID_NIL))
    {
        ASSERT(FALSE);
        return E_INVALIDARG;
    }

    if ((dwDelItemOp != DELITEMOP_RemoveFromProject) &&
        (dwDelItemOp != DELITEMOP_DeleteFromStorage))
    {
        ASSERT(FALSE);
        return E_ABORT;
    }

    HRESULT hr = S_OK;

    if(VSITEMID_ROOT == itemid)
    {
        // The project can only be removed from the solution, 
        // it can't be deleted from disk
        if( dwDelItemOp != DELITEMOP_RemoveFromProject ) 
            return E_ABORT;
        
        // Remove the entire project from the solution
        CComPtr<IVsSolution> srpSolution;
        if( SUCCEEDED( hr = _VxModule.QueryService(SID_SVsSolution, IID_IVsSolution, (void **)&srpSolution)) )
        {
            hr = srpSolution->CloseSolutionElement(
                /* [in] VSSLNCLOSEOPTIONS grfCloseOpts */ SLNSAVEOPT_PromptSave, 
                /* [in] IVsHierarchy *pHier            */ QI_cast<IVsHierarchy>(this), 
                /* [in] VSCOOKIE docCookie             */ NULL);                   
        }
        return hr;
    }

    hr = CloseAndRemoveItem( 
            itemid, 
            dwDelItemOp == DELITEMOP_DeleteFromStorage);

    return hr;
}


HRESULT CMyProjectHierarchy::CloseAndRemoveItem(
    VSITEMID itemid, 
    BOOL fRemoveFromDisk)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    if ( (itemid == VSITEMID_ROOT) || 
         (itemid == VSITEMID_NIL)  || 
         (itemid == VSITEMID_SELECTION) )
    {
        ASSERT(FALSE);
        return E_INVALIDARG;
    }

    HRESULT hr = S_OK;
    
    CFileVwFileNode* pFileNode = VSITEMID2FileNode(itemid);
    if (!pFileNode)
        return S_OK;

    hr = pFileNode->CloseDoc(fRemoveFromDisk ? SLNSAVEOPT_NoSave : SLNSAVEOPT_PromptSave);
    _IfFailRet(hr);
        
    hr = RemoveItem(itemid, fRemoveFromDisk);
    
    return hr;
}


HRESULT CMyProjectHierarchy::RemoveItem(
    VSITEMID itemid, 
    BOOL fRemoveFromDisk)
{ 
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	if ( (itemid == VSITEMID_ROOT) || 
         (itemid == VSITEMID_NIL)  || 
         (itemid == VSITEMID_SELECTION))
    {
        ASSERT(FALSE);
		return E_INVALIDARG;
    }
	
	HRESULT hr = S_OK;
	
	CFileVwProjNode* pProjectNode = GetProjectNode();
    ExpectedExprRet(pProjectNode != NULL);

    CHierNode* pNode;
	hr = VSITEMID2Node(itemid, &pNode);
    IfFailRet(hr);
    ExpectedExprRet(pNode != NULL);

    hr = pProjectNode->DeleteNode(pNode, fRemoveFromDisk);

    return hr;
}


// This function will display the projects settings dialog for the project. 
// This routine can be used when the project receives the 
// IVsDebuggableProjectCfg::DebugLaunch but proper launch settings have not 
// been set. The Solution Build VsPackage is the command handler for the 
// cmdidProjectSettings command, thus no action by the project is necessary 
// to explicitly handle the "<ProjectName> Properties..." command on the menu 
// or context menu.
HRESULT CMyProjectHierarchy::DoProjectSettingsDlg()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

  CComPtr<IOleCommandTarget> srpIOleCommandTarget;
  HRESULT hr = E_NOINTERFACE;
  CComPtr<IVsSolution> pSolution;
  GUID     guidProject;
  WCHAR rgwchBuffer[1024];
  CComVariant varIn;

  IfFailGo(_VxModule.QueryService(SID_SUIHostCommandDispatcher, IID_IOleCommandTarget, (LPVOID *)&srpIOleCommandTarget));
  if (srpIOleCommandTarget == NULL)
    goto Error;

  IfFailGo(_VxModule.QueryService(SID_SVsSolution, IID_IVsSolution, (void **)&pSolution));

  // get guid of project.
  IfFailGo(pSolution->GetGuidOfProject(
      /* [in] IVsHierarchy *pHierarchy */ QI_cast<IVsHierarchy>(this),
      /* [out] GUID *pguidProjectID */    &guidProject  ));

  if (0 == ::StringFromGUID2(guidProject, rgwchBuffer, NUMBER_OF(rgwchBuffer)))
  {
      hr = HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
      goto Error;
  }

  varIn = rgwchBuffer; // this should make a BSTR-iszed copy...

  IfFailGo(srpIOleCommandTarget->Exec(&CLSID_StandardCommandSet97, cmdidProjectSettings, 0, &varIn, NULL));

  hr = S_OK;
Error:
  return hr;
}


//---------------------------------------------------------------------------
// IMyCPrjProjHierProps
//---------------------------------------------------------------------------
HRESULT CMyProjectHierarchy::get_Name(BSTR *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	return GetProjectNode()->GetDisplayCaption(pVal);
}


HRESULT CMyProjectHierarchy::put_Name(BSTR NewName)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    CFileVwProjNode* pProjectNode = GetProjectNode();
    if (!pProjectNode)
        return E_UNEXPECTED;

	return pProjectNode->RenameProject(NewName);
}

HRESULT CMyProjectHierarchy::get_ProjectPath(BSTR *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);
	CString str = GetProjectNode()->GetFolderPath();
	*pVal = str.AllocSysString();
    return (*pVal) ? S_OK : E_OUTOFMEMORY;
}

HRESULT CMyProjectHierarchy::get_IsDirty(VARIANT_BOOL *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal); 
   
    BOOL fDirty = FALSE;

    HRESULT hr = IsDirty(&fDirty);
    IfFailRet(hr);

    *pVal = fDirty ? VARIANT_TRUE : VARIANT_FALSE;

    return S_OK;
}

HRESULT CMyProjectHierarchy::put_IsDirty(VARIANT_BOOL pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

	CFileVwProjNode* pProjectNode = GetProjectNode();
    if (!pProjectNode)
        return E_FAIL;

    pProjectNode->SetProjectFileDirty(pVal == VARIANT_TRUE);

    return hr;
}

STDMETHODIMP CMyProjectHierarchy::get_Extender(
    /* [in]          */ BSTR         bstrExtenderName, 
    /* [out, retval] */ IDispatch ** ppExtender)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(bstrExtenderName);
    ExpectedPtrRet(ppExtender);
    InitParam(ppExtender);

    HRESULT hr = S_OK;

    CComPtr<VxDTE::ObjectExtenders> srpObjectExtenders = _VxModule.GetObjectExtenders();
    ExpectedExprRet(srpObjectExtenders != NULL);

    CComBSTR cbstrCATID;
    hr = get_ExtenderCATID(&cbstrCATID);
    IfFailRet(hr);

    hr = srpObjectExtenders->GetExtender(
        /* [in] BSTR ExtenderCATID              */ cbstrCATID,
        /* [in] BSTR ExtenderName               */ bstrExtenderName,
        /* [in] IDispatch *ExtendeeObject       */ (LPDISPATCH)this,
        /* [retval][out] IDispatch **Extender   */ ppExtender);

    return hr;
}


STDMETHODIMP CMyProjectHierarchy::get_ExtenderNames(
    /* [out, retval] */ VARIANT * pvarExtenderNames)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

    CComPtr<VxDTE::ObjectExtenders> srpObjectExtenders = _VxModule.GetObjectExtenders();
    ExpectedExprRet(srpObjectExtenders != NULL);

    CComBSTR cbstrCATID;
    hr = get_ExtenderCATID(&cbstrCATID);
    IfFailRet(hr);

    hr = srpObjectExtenders->GetExtenderNames(
        /* [in] BSTR ExtenderCATID              */ cbstrCATID,
        /* [in] IDispatch *ExtendeeObject       */ (LPDISPATCH) this,
        /* [retval][out] VARIANT *ExtenderNames */ pvarExtenderNames);

    return hr;
}

    
STDMETHODIMP CMyProjectHierarchy::get_ExtenderCATID(
    /* [out, retval] */ BSTR * pbstrRetval)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pbstrRetval);
    InitParam(pbstrRetval);

    CComBSTR cbstrCATID(prjCATIDMyCPrjProjectBrowseObject);
    if (cbstrCATID.Length() == 0)
        return E_OUTOFMEMORY;

    *pbstrRetval = cbstrCATID.Detach();
    return S_OK;
}


HRESULT CMyProjectHierarchy::Close(void)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    CAutomationEvents::FireProjectsEvent(
        GetProjectNode(),
        CAutomationEvents::ProjectsEventsDispIDs::ItemRemoved);

    // Unadvise clipboard helper events
    RegisterClipboardNotifications(/* [in] BOOL fRegister */ FALSE);

	//Unregister ourselves from the scc manager.
	UnregisterSccProject();

    // Let go of startup services
    m_projectStartupServices.StopServices();

    if (m_pCfgProvider)
    {
        m_pCfgProvider->Release(); 
        m_pCfgProvider = NULL;
    }

    if (GetProjectNode())
        GetProjectNode()->Close();

	CVsHierarchy::Close();
	return S_OK;
}


// =========================================================================
//                                           DRAG AND DROP, CUT, COPY, PASTE

STDMETHODIMP CMyProjectHierarchy::GetDropInfo(
    /* [out] */ DWORD *         pdwOKEffects, 
    /* [out] */ IDataObject **  ppDataObject, 
    /* [out] */ IDropSource **  ppDropSource)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pdwOKEffects);
    ExpectedPtrRet(ppDataObject);
    ExpectedPtrRet(ppDropSource);
	*pdwOKEffects = DROPEFFECT_NONE;
	*ppDataObject = NULL;
	*ppDropSource = NULL;
	
	HRESULT hr = S_OK;
	
	hr = PackageSelectionDataObject(
        /* [out] IDataObject ** ppDataObject */ ppDataObject, 
        /* [in]  BOOL     fCutHighlightItems */ FALSE);
    _IfFailRet(hr);
	IfNullFail(*ppDataObject);
	
	*pdwOKEffects = DROPEFFECT_MOVE | DROPEFFECT_COPY;
	
	m_fDragSource = TRUE;
Error:
	return hr;
}


STDMETHODIMP CMyProjectHierarchy::OnDropNotify(
    /* [in] */ BOOL     fDropped, 
    /* [in] */ DWORD    dwEffects)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = NOERROR;
	m_fDragSource = FALSE;
	hr = CleanupSelectionDataObject(
        /* [in] BOOL fDropped*/ fDropped, 
        /* [in] BOOL fCut    */ FALSE, 
        /* [in] BOOL fMoved  */ dwEffects == DROPEFFECT_MOVE);
	return hr;
}


STDMETHODIMP CMyProjectHierarchy::OnBeforeDropNotify(
    /* [in]         */ IDataObject *    pDataObject,
    /* [in]         */ DWORD            grfKeyState,
    /* [out,retval] */ BOOL *           pfCancelDrop)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    if (pfCancelDrop)
        *pfCancelDrop = FALSE;

	HRESULT hr = S_OK;

    // check for dirty documents
    BOOL fDirty = FALSE;
	for (ULONG i = 0; i < m_nItemsDragged; i++)
    {
        CFileVwFileNode* pFileNode = VSITEMID2FileNode(m_pItemSelDragged[i].itemid);
        if (!pFileNode)
            continue;

        BOOL fDirtyDoc = FALSE;
        BOOL fOpenByUs = FALSE;
        hr = pFileNode->GetDocInfo(
            /* [out, opt] BOOL*  pfOpen     */ NULL,       // true if the doc is opened
            /* [out, opt] BOOL*  pfDirty    */ &fDirtyDoc, // true if the doc is dirty
            /* [out, opt] BOOL*  pfOpenByUs */ &fOpenByUs, // true if opened by our project
            /* [out, opt] VSDOCCOOKIE* pVsDocCookie*/ NULL);// VSDOCCOOKIE if open
        if (FAILED(hr))
            continue;

        if (fDirtyDoc && fOpenByUs)
        {
            fDirty = TRUE;
            break;
        }

    }

    // if there are no dirty docs we are ok to proceed
    if (!fDirty) 
        return S_OK;

    // prompt to save if there are dirty docs
    CString strCaption;
    if (!strCaption.LoadString(IDS_VISUALSTUDIO))
        return E_FAIL;
    ASSERT(!strCaption.IsEmpty());
    int msgRet = UtilMessageBox(
        /* UINT nIDPrompt                        */ IDS_PROMPT_SAVEDIRTYDOCS,
        /* UINT nType = MB_OK|MB_ICONEXCLAMATION */ MB_YESNOCANCEL | MB_ICONEXCLAMATION,
        /* LPCTSTR pszCaption = NULL             */ strCaption);
    switch (msgRet)
    {
        case IDYES:
            break;

        case IDNO:
            return S_OK;

        case IDCANCEL:
            if (pfCancelDrop)
                *pfCancelDrop = TRUE;
            return S_OK;

        default:
		    ASSERT(FALSE);
            return S_OK;
    }


	for (ULONG i = 0; i < m_nItemsDragged; i++)
    {
        CFileVwFileNode* pFileNode = VSITEMID2FileNode(m_pItemSelDragged[i].itemid);
        if (!pFileNode)
            continue;

        hr = pFileNode->SaveDoc(
            /* [in] VSSLNSAVEOPTIONS grfSaveOpts*/ SLNSAVEOPT_SaveIfDirty);
    }

    return hr;
}


STDMETHODIMP CMyProjectHierarchy::DragEnter(
    IDataObject * pDataObject, 
    DWORD         grfKeyState, 
    VSITEMID      itemid, 
    DWORD *       pdwEffect)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pDataObject);
    ExpectedPtrRet(pdwEffect);
	*pdwEffect = DROPEFFECT_NONE;

	if (m_fDragSource)
        return S_OK;

    HRESULT hr = S_OK;

    hr = QueryDropDataType(pDataObject);
    IfFailRet(hr);
    
    hr = QueryDropEffect(m_ddt, grfKeyState, pdwEffect);
    IfFailRet(hr);

    return hr;
}


STDMETHODIMP CMyProjectHierarchy::QueryDropDataType(
    /* [in]  */ IDataObject*  pDataObject)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pDataObject);

    m_ddt = DDT_NONE;

    // known formats include File Drops (as from WindowsExplorer),
    // VSProject Reference Items and VSProject Storage Items.
    FORMATETC fmtetc, fmtetcRef, fmtetcStg;
    
    fmtetc.cfFormat = CF_HDROP;
    fmtetc.ptd = NULL;
    fmtetc.dwAspect = DVASPECT_CONTENT;
    fmtetc.lindex = -1;
    fmtetc.tymed = TYMED_HGLOBAL;
    
    fmtetcRef.cfFormat = CF_VSREFPROJECTITEMS;
    fmtetcRef.ptd = NULL;
    fmtetcRef.dwAspect = DVASPECT_CONTENT;
    fmtetcRef.lindex = -1;
    fmtetcRef.tymed = TYMED_HGLOBAL;
    
    fmtetcStg.cfFormat = CF_VSSTGPROJECTITEMS;
    fmtetcStg.ptd = NULL;
    fmtetcStg.dwAspect = DVASPECT_CONTENT;
    fmtetcStg.lindex = -1;
    fmtetcStg.tymed = TYMED_HGLOBAL;
    
    if (pDataObject->QueryGetData(&fmtetc) == S_OK)
    {
        m_ddt = DDT_SHELL;
        return S_OK;
    }
    if (pDataObject->QueryGetData(&fmtetcRef) == S_OK)
    {
        // Data is from a Ref-based project.
        m_ddt = DDT_VSREF;
        return S_OK;
    }
    if (pDataObject->QueryGetData(&fmtetcStg) == S_OK)
    {
        // Data is from a Storage-based project.
        m_ddt = DDT_VSSTG;
        return S_OK;
    }

    return S_FALSE;
}


STDMETHODIMP CMyProjectHierarchy::QueryDropEffect(
    /* [in]  */  DropDataType ddt,
    /* [in]  */  DWORD        grfKeyState,
    /* [out] */  DWORD *      pdwEffects)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pdwEffects);
    *pdwEffects = DROPEFFECT_NONE;

    HRESULT hr = S_OK;

    // We are reference-based project so we should perform as follow:
    // for shell and physical items:
    //  NO MODIFIER - LINK
    //  SHIFT DRAG - NO DROP
    //  CTRL DRAG - NO DROP
    //  CTRL-SHIFT DRAG - LINK
    // for reference/link items
    //  NO MODIFIER - MOVE
    //  SHIFT DRAG - MOVE
    //  CTRL DRAG - COPY
    //  CTRL-SHIFT DRAG - LINK

    if ( (ddt != DDT_SHELL) && (ddt != DDT_VSREF) && (ddt != DDT_VSSTG) )
        return S_FALSE;

    switch (ddt)
    {
        case DDT_SHELL:
        case DDT_VSSTG:

            // CTRL-SHIFT
            if((grfKeyState & MK_CONTROL) && (grfKeyState & MK_SHIFT))
            {
                *pdwEffects = DROPEFFECT_LINK;
                return S_OK;
            }
            // CTRL
            if(grfKeyState & MK_CONTROL)
                return S_FALSE;

            // SHIFT
            if(grfKeyState & MK_SHIFT)
                return S_FALSE;

            // no modifier
            *pdwEffects = DROPEFFECT_LINK;
            return S_OK;
            
        case DDT_VSREF:
            // CTRL-SHIFT
            if((grfKeyState & MK_CONTROL) && (grfKeyState & MK_SHIFT))
            {
                *pdwEffects = DROPEFFECT_LINK;
                return S_OK;
            }
            // CTRL
            if(grfKeyState & MK_CONTROL)
            {
                *pdwEffects = DROPEFFECT_COPY;
                return S_OK;
            }

            // SHIFT
            if(grfKeyState & MK_SHIFT)
            {
                *pdwEffects = DROPEFFECT_MOVE;
                return S_OK;
            }

            // no modifier
            *pdwEffects = DROPEFFECT_MOVE;
            return S_OK;

        default:
            return S_FALSE;
    }

    return S_FALSE;
}


STDMETHODIMP CMyProjectHierarchy::DragOver(DWORD grfKeyState, VSITEMID itemid, DWORD *pdwEffect)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	if (pdwEffect == NULL)
		return E_POINTER;
	
    HRESULT hr = QueryDropEffect(m_ddt, grfKeyState, pdwEffect);
    IfFailRet(hr);

	return S_OK;
}

STDMETHODIMP CMyProjectHierarchy::DragLeave(void)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    m_ddt          = DDT_NONE;
	return NOERROR;
}

STDMETHODIMP CMyProjectHierarchy::Drop(
    IDataObject *   pDataObject, 
    DWORD           grfKeyState, 
    VSITEMID        itemid, 
    DWORD *         pdwEffect)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	if (pDataObject == NULL)
		return E_INVALIDARG;
	if (pdwEffect == NULL)
		return E_POINTER;
	*pdwEffect = DROPEFFECT_NONE;
	
	HRESULT hr = NOERROR;

	if (m_fDragSource) 
		return S_OK;
	
    DropDataType ddt;
	hr = ProcessSelectionDataObject(
        /* [in]  IDataObject* pDataObject*/ pDataObject, 
        /* [in]  DWORD        grfKeyState*/ grfKeyState,
        /* [out] DropDataType*           */ &ddt);

    // We need to report our own errors.
    if(FAILED(hr) && hr != E_UNEXPECTED && hr != OLE_E_PROMPTSAVECANCELLED)
    {
        LUtilReportErrorInfo(hr);
    }

    // If it is a drop from windows and we get any kind of error we return S_FALSE and dropeffect none. This
    // prevents bogus messages from the shell from being displayed
    if(FAILED(hr) && ddt == DDT_SHELL)
    {
        hr = S_FALSE;
    }

    if (hr == S_OK)
        QueryDropEffect(ddt, grfKeyState, pdwEffect);

	return hr;
}


HRESULT CMyProjectHierarchy::PackageSelectionDataObject(
    /* [out] */ IDataObject **  ppDataObject, 
    /* [in]  */ BOOL            fCutHighlightItems)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = S_OK;

	// delete any existing selection data object and restore state
	hr = CleanupSelectionDataObject(FALSE, FALSE, FALSE);
    IfFailRet(hr);

    CComPtr<IVsUIHierarchyWindow> srpIVsUIHierarchyWindow;
    hr = _VxModule.GetIVsUIHierarchyWindow(GUID_SolutionExplorer, &srpIVsUIHierarchyWindow);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsUIHierarchyWindow != NULL);

    CComPtr<IVsSolution> srpIVsSolution;
	hr = _VxModule.QueryService(SID_SVsSolution, IID_IVsSolution, (void **)&srpIVsSolution);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsSolution != NULL);

	CComPtr<IVsMonitorSelection> srpIVsMonitorSelection;
	hr = _VxModule.QueryService(SID_SVsShellMonitorSelection, IID_IVsMonitorSelection, (void **)&srpIVsMonitorSelection);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsMonitorSelection != NULL);

	VSITEMID vsitemid;
	CComPtr<IVsHierarchy>       srpIVsHierarchy_selection;
	CComPtr<IVsMultiItemSelect> srpIVsMultiItemSelect;
    hr = srpIVsMonitorSelection->GetCurrentSelection(
        /* [out] IVsHierarchy**        */ &srpIVsHierarchy_selection, 
        /* [out] VSITEMID*             */ &vsitemid, 
        /* [out] IVsMultiItemSelect**  */ &srpIVsMultiItemSelect, 
        /* [out] ISelectionContainer** */ NULL);
    IfFailRet(hr);

	HGLOBAL hGlobal     = NULL;
	LONG    lLenGlobal  = NULL; // length of the file names including null chars
    DWORD   cbAlloc     = NULL; // bytes to allocate
	
	CComPtr<IVsHierarchy> srpIVsHierarchy_this = GetIVsHierarchy();

    if  ( ( srpIVsHierarchy_selection != srpIVsHierarchy_this)  ||
          ( vsitemid == VSITEMID_ROOT) || 
          ( vsitemid == VSITEMID_NIL ) 
        )
        return E_ABORT;

	if ( (vsitemid == VSITEMID_SELECTION) && (srpIVsMultiItemSelect != NULL) )
    {
		BOOL fSingleHierarchy = FALSE;
        hr = srpIVsMultiItemSelect->GetSelectionInfo(&m_nItemsDragged, &fSingleHierarchy);
        IfFailRet(hr);
        if (!fSingleHierarchy)
            return E_ABORT;

		m_pItemSelDragged = (VSITEMSELECTION *) VSAlloc (m_nItemsDragged * sizeof(VSITEMSELECTION));
		IfNullFail(m_pItemSelDragged);

		hr = srpIVsMultiItemSelect->GetSelectedItems(GSI_fOmitHierPtrs, m_nItemsDragged, m_pItemSelDragged);
        IfFailGo(hr);

		for (ULONG i = 0; i < m_nItemsDragged; i++)
		{
			if (m_pItemSelDragged[i].itemid == VSITEMID_ROOT)
			{
                hr = E_ABORT;
                goto Error;
			}
			
			CComBSTR cbstrProjref;
			hr = srpIVsSolution->GetProjrefOfItem(srpIVsHierarchy_this, m_pItemSelDragged[i].itemid, &cbstrProjref);
            IfFailGo(hr);

			if ( (cbstrProjref == NULL) || (cbstrProjref.Length()==0) )
            {
                hr = E_FAIL;
                goto Error;
            }

            lLenGlobal += cbstrProjref.Length() + 1; // plus one to count the trailing null character
		}	
    }
	else if (vsitemid != VSITEMID_ROOT)
    {
		m_nItemsDragged = 1;
		m_pItemSelDragged = (VSITEMSELECTION *)VSAlloc(m_nItemsDragged * sizeof(VSITEMSELECTION));
		IfNullFail(m_pItemSelDragged);
		m_pItemSelDragged[0].pHier = NULL;
		m_pItemSelDragged[0].itemid = vsitemid;
		
		CComBSTR cbstrProjref = NULL;
		IfFailGo(srpIVsSolution->GetProjrefOfItem(srpIVsHierarchy_selection, vsitemid, &cbstrProjref));
		IfNullFail(cbstrProjref);
        lLenGlobal += cbstrProjref.Length() + 1; // plus one to count the trailing null character
    }

    // check for at least one effective file selected
	IfFalseGoto(lLenGlobal > 0, E_ABORT, Error);

    // account for 2nd NULL terminator byte
	lLenGlobal += 1;

    cbAlloc=(DWORD) ( sizeof(DROPFILES) + lLenGlobal * sizeof(WCHAR) );
	hGlobal = GlobalAlloc(GHND | GMEM_SHARE, cbAlloc);
	IfNullFail(hGlobal);
	
	LPDROPFILES pDropFiles;
	pDropFiles = (LPDROPFILES)GlobalLock(hGlobal);
	
	// set the offset where the starting point of the file start
	pDropFiles->pFiles = sizeof(DROPFILES);
	
	// structure contain wide characters
	pDropFiles->fWide = TRUE;

    int nCurPos = sizeof(DROPFILES);
	for (ULONG i = 0; i < m_nItemsDragged; i++)
    {
		CComBSTR cbstrProjref = NULL;
		hr = srpIVsSolution->GetProjrefOfItem(srpIVsHierarchy_this, m_pItemSelDragged[i].itemid, &cbstrProjref);
		if (FAILED(hr))
            continue;
        
        UINT cbProjRef = (cbstrProjref.Length() + 1) * sizeof(WCHAR);
        if (nCurPos + cbProjRef < cbAlloc)
        {
            wcscpy(((LPWSTR)((DWORD_PTR)pDropFiles + nCurPos)), cbstrProjref);
            nCurPos += cbProjRef;
        }

    }

    hr = S_OK;

    // final null terminator as per CF_VSSTGPROJECTITEMS format spec
    *((LPOLESTR)((DWORD_PTR)pDropFiles + nCurPos)) = 0;
    int res = ::GlobalUnlock(hGlobal);

	CComObject<CVxOleDataSource> *pDataObject = NULL;  // has ref count of 0
	CComObject<CVxOleDataSource>::CreateInstance(&pDataObject);
	IfNullFail(pDataObject);
	
	FORMATETC fmtetc;
	fmtetc.ptd      = NULL;
	fmtetc.dwAspect = DVASPECT_CONTENT;
	fmtetc.lindex   = -1;
	fmtetc.tymed    = TYMED_HGLOBAL;
    fmtetc.cfFormat = CF_VSREFPROJECTITEMS;

	STGMEDIUM stgmedium;
	stgmedium.tymed          = TYMED_HGLOBAL;
	stgmedium.hGlobal        = hGlobal;
	stgmedium.pUnkForRelease = NULL;

	pDataObject->CacheData(CF_VSREFPROJECTITEMS, &stgmedium, &fmtetc); 
	*ppDataObject = pDataObject;
	pDataObject->AddRef();
    
Error:
    if (SUCCEEDED(hr))
    {
        if (fCutHighlightItems)
        {
	        for (ULONG i = 0; i < m_nItemsDragged; i++)
            {
                srpIVsUIHierarchyWindow->ExpandItem( GetIVsUIHierarchy(), m_pItemSelDragged[i].itemid, i == 0 ? EXPF_CutHighlightItem : EXPF_AddCutHighlightItem);
            }
        }
    }
	if (FAILED(hr))
    {
		IfNonNullFreeSetNull(m_pItemSelDragged);
        m_nItemsDragged = 0;
    }

    return hr;
}


//-----------------------------------------------------------------------------
// Returns a cstring array populated with the files from a PROJREF drop. Note that 
// we can't use the systems DragQueryFile() functions because they will NOT work 
// on win9x with unicode strings. Returns the count of files. The format looks like 
// the following: DROPFILES structure with pFiles member containing the offset to 
// the list of files:
//   ----------------------------------------------------------------------------
//  |{DROPFILES structure}|ProjRefItem1|0|ProjRefItem2|0|.......|ProjRefItemN|0|0|
//   ----------------------------------------------------------------------------
//
// If index == -1 it returns everything otherwise it just returns the one file at index (0 based) and
// returns a count of 1. Count of 0 means it couldn't find the one at the index requested.
//-----------------------------------------------------------------------------
int UtilGetFilesFromPROJITEMDrop(HGLOBAL h, CVxStringArray& rgFiles, int index)
{
    int numFiles = 0;

    // Set a reasonable growby
    rgFiles.SetSize(0, 20);

    LPVOID pv = ::GlobalLock(h);
    ASSERT(pv);
    if (!pv)
        return 0;
   
    DROPFILES* pszDropFiles = reinterpret_cast<DROPFILES*>(pv);

    // It better be marked unicode
    ASSERT(pszDropFiles->fWide);
    if (pszDropFiles->fWide)
    {
        // The first member of the structure contains the offset to the files
        WCHAR* wzBuffer = reinterpret_cast<WCHAR*>(((BYTE*)pszDropFiles) + pszDropFiles->pFiles);
        // We go until *wzBuffer is null since we don't allow empty strings.
        while(*wzBuffer)
        {
            if(index == -1)
            {
                rgFiles.Add(wzBuffer);
                ASSERT(!rgFiles[numFiles].IsEmpty());
                wzBuffer += rgFiles[numFiles].GetLength()+1;
                numFiles++;
            }
            else
            {
                if(index == numFiles)
                {   // Just return the one asked for and return a count of 1.
                    rgFiles.Add(wzBuffer);
                    numFiles = 1;
                    goto Error;
                }
                numFiles++;

                // Skip to the next one.
                while(*wzBuffer++);
            }
        }
    }

    // if we didn't find the one requested 
    if(index != -1)
        numFiles = 0;

Error:

    ::GlobalUnlock(h);

    return numFiles;
}



HRESULT CMyProjectHierarchy::ProcessSelectionDataObject(
    /* [in]  */ IDataObject*    pDataObject, 
    /* [in]  */ DWORD           grfKeyState,
    /* [out] */ DropDataType*   pddt)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pDataObject);
	HRESULT hr = S_OK;
    if (pddt)
        *pddt = DDT_NONE;

    CFileVwProjNode* pProjectNode = GetProjectNode();
    ExpectedExprRet(pProjectNode != NULL);

	FORMATETC fmtetc;
	STGMEDIUM stgmedium;
	HDROP hDropInfo = NULL;
	int numFiles = 0;
	TCHAR szMoniker[MAX_PATH+1];
	USES_CONVERSION;

    DropDataType ddt = DDT_NONE;
    BOOL fItemProcessed = FALSE;

    // try HDROP
	fmtetc.cfFormat = CF_HDROP;
	fmtetc.ptd = NULL;
	fmtetc.dwAspect = DVASPECT_CONTENT;
	fmtetc.lindex = -1;
	fmtetc.tymed = TYMED_HGLOBAL;

	IfFalseGoto(pDataObject->QueryGetData(&fmtetc) == S_OK, NOERROR, AttemptVSRefFormat);
	IfFalseGoto(SUCCEEDED(pDataObject->GetData(&fmtetc, &stgmedium)), NOERROR, AttemptVSRefFormat);
	IfFalseGoto(stgmedium.tymed == TYMED_HGLOBAL, NOERROR, AttemptVSRefFormat);
	hDropInfo = (HDROP)stgmedium.hGlobal;
	IfFalseGoto(hDropInfo, NOERROR, AttemptVSRefFormat);

    // try shell format here
    ddt = DDT_SHELL;
	numFiles = ::DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	for (int iFile = 0; iFile < numFiles; iFile++)
	{
        UINT uiRet = ::DragQueryFile(hDropInfo, iFile, szMoniker, _MAX_PATH);
        if (!uiRet || (uiRet >= _MAX_PATH))
        {
            hr = HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
            continue;
        }
        szMoniker[_MAX_PATH] = _T('\0');

		// Is full path returned
        if (LUtilFileExists(szMoniker))
        {
            VSADDRESULT vsaddresult = ADDRESULT_Failure;
            LPCOLESTR oszMoniker = T2COLE(szMoniker);
            HRESULT hrTemp = pProjectNode->AddItem(
                /* [in]  VSADDITEMOPERATION dwAddItemOperation */ VSADDITEMOP_OPENFILE,
                /* [in]  LPCOLESTR pszItemName                 */ NULL,
                /* [in]  DWORD cFilesToOpen                    */ 1,
                /* [in]  LPCOLESTR rgpszFilesToOpen[]          */ &oszMoniker,
                /* [in]  HWND hwndDlg                          */ NULL,
                /* [in]  VSSPECIFICEDITORFLAGS grfEditorFlags  */ NULL,
                /* [in]  REFGUID               rguidEditorType */ GUID_NULL,
                /* [in]  LPCOLESTR             pszPhysicalView */ NULL,
                /* [in]  REFGUID               rguidLogicalView*/ GUID_NULL,
                /* [out] VSADDRESULT *pResult                  */ &vsaddresult);
            if ( (hrTemp == E_ABORT) || (hrTemp == OLE_E_PROMPTSAVECANCELLED) || (vsaddresult == ADDRESULT_Cancel) )
            {
                  hr = OLE_E_PROMPTSAVECANCELLED;
                  goto Error;
            }
            if (FAILED(hrTemp))
            {
                hr = hrTemp;
                continue;
            }
            fItemProcessed = TRUE;
        }
    }
	goto Error;
		
AttemptVSRefFormat:
	fmtetc.cfFormat = CF_VSREFPROJECTITEMS;
	fmtetc.ptd = NULL;
	fmtetc.dwAspect = DVASPECT_CONTENT;
	fmtetc.lindex = -1;
	fmtetc.tymed = TYMED_HGLOBAL;
	
	IfFalseGoto(pDataObject->QueryGetData(&fmtetc) == S_OK, E_FAIL, AttemptVSStgFormat);
	IfFailGoto(pDataObject->GetData(&fmtetc, &stgmedium), AttemptVSStgFormat);
	IfFalseGoto(stgmedium.tymed == TYMED_HGLOBAL, NOERROR, AttemptVSStgFormat);
	hDropInfo = (HDROP)stgmedium.hGlobal;
	IfFalseGoto(hDropInfo, NOERROR, AttemptVSStgFormat);
	
    ddt = DDT_VSREF;
    goto AddFiles;

AttemptVSStgFormat:
	fmtetc.cfFormat = CF_VSSTGPROJECTITEMS;
	fmtetc.ptd = NULL;
	fmtetc.dwAspect = DVASPECT_CONTENT;
	fmtetc.lindex = -1;
	fmtetc.tymed = TYMED_HGLOBAL;
	
	IfFalseGo(pDataObject->QueryGetData(&fmtetc) == S_OK, E_FAIL);
	IfFailGo(pDataObject->GetData(&fmtetc, &stgmedium));
	IfFalseGo(stgmedium.tymed == TYMED_HGLOBAL, NOERROR);
	hDropInfo = (HDROP)stgmedium.hGlobal;
	IfFalseGo(hDropInfo, NOERROR);
	
    ddt = DDT_VSSTG;

AddFiles:
    {
    CComPtr<IVsSolution> srpIVsSolution;
	IfFailGo(_VxModule.QueryService(SID_SVsSolution, IID_IVsSolution, (void **)&srpIVsSolution));
	IfNullFail(srpIVsSolution);

    // Note that we do NOT use ::DragQueryFile as this function will 
    // NOT work with unicode strings on win9x - even
    // with the unicode wrappers - and the projitem ref format is in unicode
    CVxStringArray rgSrcFiles;
    numFiles = UtilGetFilesFromPROJITEMDrop(hDropInfo, rgSrcFiles, -1 /*get'em all*/);
	for (int iFile = 0; iFile < numFiles; iFile++)
    {
        HRESULT hrTemp;
       	VSITEMID itemidLoc;
        CComPtr<IVsHierarchy> srpIVsHierarchy;
		hrTemp = srpIVsSolution->GetItemOfProjref(rgSrcFiles[iFile], &srpIVsHierarchy, &itemidLoc, NULL, NULL);
        if ( (hrTemp == E_ABORT) || (hrTemp == OLE_E_PROMPTSAVECANCELLED) )
        {
              hr = OLE_E_PROMPTSAVECANCELLED;
              goto Error;
        }
        if (FAILED(hrTemp))
        {
            hr = hrTemp;
            continue;
        }
        if (srpIVsHierarchy == NULL)
        {
            hr = E_UNEXPECTED;
            continue;
        }

        // If this is a virtual item, we skip it
        GUID typeGuid;
        hrTemp = srpIVsHierarchy->GetGuidProperty(itemidLoc, VSHPROPID_TypeGuid, &typeGuid);
        if (SUCCEEDED(hrTemp) && (typeGuid != GUID_ItemType_PhysicalFile) )
        {
            hr = E_FAIL;
            continue;
        }
        if ( (hrTemp == E_ABORT) || (hrTemp == OLE_E_PROMPTSAVECANCELLED) )
        {
              hr = OLE_E_PROMPTSAVECANCELLED;
              goto Error;
        }


        CComPtr<IVsProject> srpIVsProject;
		hrTemp = srpIVsHierarchy->QueryInterface(IID_IVsProject, (void **)&srpIVsProject);
        if (FAILED(hrTemp))
        {
            hr = hrTemp;
            continue;
        }
        if (srpIVsProject == NULL)
        {
            hr = E_UNEXPECTED;
            continue;
        }

        CComBSTR cbstrMoniker;
		hrTemp = srpIVsProject->GetMkDocument(itemidLoc, &cbstrMoniker);
        if (FAILED(hrTemp))
        {
            hr = hrTemp;
            continue;
        }
        
        LPCOLESTR oszMoniker = W2COLE(cbstrMoniker);
        VSADDRESULT vsaddresult = ADDRESULT_Failure;
        hrTemp = pProjectNode->AddItem(
            /* [in]  VSADDITEMOPERATION dwAddItemOperation */ VSADDITEMOP_OPENFILE,
            /* [in]  LPCOLESTR pszItemName                 */ NULL,
            /* [in]  DWORD cFilesToOpen                    */ 1,
            /* [in]  LPCOLESTR rgpszFilesToOpen[]          */ &oszMoniker,
            /* [in]  HWND hwndDlg                          */ NULL,
            /* [in]  VSSPECIFICEDITORFLAGS grfEditorFlags  */ NULL,
            /* [in]  REFGUID               rguidEditorType */ GUID_NULL,
            /* [in]  LPCOLESTR             pszPhysicalView */ NULL,
            /* [in]  REFGUID               rguidLogicalView*/ GUID_NULL,
            /* [out] VSADDRESULT *pResult                  */ &vsaddresult);
        if ( (hrTemp == E_ABORT) || (hrTemp == OLE_E_PROMPTSAVECANCELLED) || (vsaddresult == ADDRESULT_Cancel) )
        {
              hr = OLE_E_PROMPTSAVECANCELLED;
              goto Error;
        }
        if (FAILED(hrTemp))
        {
            hr = hrTemp;
            continue;
        }
        fItemProcessed = TRUE;
	}
    }
	
Error:

    if (hDropInfo)
		::GlobalFree(hDropInfo);

	if(FAILED(hr))
        return hr;

    if ( !fItemProcessed || (ddt == DDT_NONE) )
		return S_FALSE;

    if (pddt)
        *pddt = ddt;

	return S_OK;
}


HRESULT CMyProjectHierarchy::CleanupSelectionDataObject(
    /* [in] */ BOOL fDropped,
    /* [in] */ BOOL fCut, 
    /* [in] */ BOOL fMoved)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // we save if something fails but we are trying to do as much as possible
	HRESULT hrRet = S_OK; // hr to return

	HRESULT hr = S_OK;
	USES_CONVERSION;

	CComPtr<IVsUIHierarchyWindow> srpIVsUIHierarchyWindow;
    hr = _VxModule.GetIVsUIHierarchyWindow(
        /* REFGUID rguidPersistenceSlot */GUID_SolutionExplorer,
        /*IVsUIHierarchyWindow **ppIVsUIHierarchyWindow*/ &srpIVsUIHierarchyWindow);
    if (FAILED(hr))
        hrRet = hr;
    if (!srpIVsUIHierarchyWindow)
        hrRet = E_UNEXPECTED;

	for (ULONG i = 0; i < m_nItemsDragged; i++)
    {
		if ( (fMoved && fDropped) || fCut )
		{

            CFileVwFileNode* pFileNode = VSITEMID2FileNode(m_pItemSelDragged[i].itemid);
            if (!pFileNode)
                continue;

            BOOL fOpen      = FALSE;
            BOOL fDirty     = FALSE;
            BOOL fOpenByUs  = FALSE;
            hr = pFileNode->GetDocInfo(
                /* [out, opt] BOOL*  pfOpen     */ &fOpen,  // true if the doc is opened
                /* [out, opt] BOOL*  pfDirty    */ &fDirty, // true if the doc is dirty
                /* [out, opt] BOOL*  pfOpenByUs */ &fOpenByUs, // true if opened by our project
                /* [out, opt] VSDOCCOOKIE* pVsDocCookie*/ NULL);// VSDOCCOOKIE if open
            if (FAILED(hr))
                continue;

            // do not close it if the doc is dirty or we do not own it
            if (fDirty || (fOpen && !fOpenByUs) )
                continue;

            // close it if opened
            if (fOpen)
            {
                hr = pFileNode->CloseDoc(SLNSAVEOPT_NoSave);
                if (FAILED(hr))
                    hrRet = hr;
            }

			hr = RemoveItem(m_pItemSelDragged[i].itemid, FALSE);
            if (FAILED(hr))
                hrRet = hr;

		}
		else
		{
            if (srpIVsUIHierarchyWindow)
			    hr = srpIVsUIHierarchyWindow->ExpandItem(QI_cast<IVsUIHierarchy>(this), m_pItemSelDragged[i].itemid, EXPF_UnCutHighlightItem);
            if (FAILED(hr))
                hrRet = hr;
		}
    }
	
	m_nItemsDragged = 0;
	IfNonNullFreeSetNull(m_pItemSelDragged);
	return hrRet;
}

HRESULT CMyProjectHierarchy::CutSelectionToClipboard()
{
	HRESULT hr = NOERROR;
	IDataObject *pDataObject = NULL;
	IVsUIHierWinClipboardHelper *pClipboardHelper = NULL;
	
    m_fInCutCopy = TRUE;
    
	// Register clipboard helper events (OK to call multiple times)
	RegisterClipboardNotifications(/* [in] fRegister */ TRUE);

	IfFailGo(PackageSelectionDataObject(&pDataObject, TRUE));
	IfNullFail(pDataObject);
	IfFailGo(_VxModule.QueryService(SID_SVsUIHierWinClipboardHelper, IID_IVsUIHierWinClipboardHelper, (void **)&pClipboardHelper));
	IfNullFail(pClipboardHelper);
	
	IfFailGo(OleSetClipboard(pDataObject));
	IfFailGo(pClipboardHelper->Cut(pDataObject));
	
Error:
    m_fInCutCopy = FALSE;
	RELEASE(pDataObject);
	RELEASE(pClipboardHelper);
	return hr;
}

HRESULT CMyProjectHierarchy::CopySelectionToClipboard()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = NOERROR;
	IDataObject *pDataObject = NULL;
	IVsUIHierWinClipboardHelper *pClipboardHelper = NULL;
	
    m_fInCutCopy = TRUE;

	// Register clipboard helper events (OK to call multiple times)
	RegisterClipboardNotifications(/* [in] fRegister */ TRUE);

	IfFailGo(PackageSelectionDataObject(&pDataObject, FALSE));
	IfNullFail(pDataObject);
	IfFailGo(_VxModule.QueryService(SID_SVsUIHierWinClipboardHelper, IID_IVsUIHierWinClipboardHelper, (void **)&pClipboardHelper));
	IfNullFail(pClipboardHelper);
	
	IfFailGo(OleSetClipboard(pDataObject));
	IfFailGo(pClipboardHelper->Copy(pDataObject));
	
Error:
    m_fInCutCopy = FALSE;
	RELEASE(pDataObject);
	RELEASE(pClipboardHelper);
	return hr;
}

HRESULT CMyProjectHierarchy::PasteItemsFromClipboard()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = S_OK;

    DWORD dwDropEffect = DROPEFFECT_NONE;// drop effect used in OnPaste call

	CComPtr<IDataObject> srpIDataObject;
	hr = OleGetClipboard(&srpIDataObject);
    if (SUCCEEDED(hr))
    {
        DropDataType ddt;
	    hr = ProcessSelectionDataObject(
            /* [in]  IDataObject* pDataObject*/ srpIDataObject, 
            /* [in]  DWORD        grfKeyState*/ NULL,
            /* [out] DropDataType*           */ &ddt);
        if (SUCCEEDED(hr))
        {
            QueryDropEffect(ddt, NULL, &dwDropEffect);
        }
    }

    // Inform the shell that the paste happened. 
    // Note that any error information can be wiped out by the call to 
    // the clipboard helper. We need to save and restore it around this call.
    CHierSaveAndRestoreIErrorInfo saveErrInfo;

    CComPtr<IVsUIHierWinClipboardHelper> srpClipboardHelper;
    hr = _VxModule.QueryService(SID_SVsUIHierWinClipboardHelper, IID_IVsUIHierWinClipboardHelper, (void**)&srpClipboardHelper);
    ASSERT(srpClipboardHelper);
    if(SUCCEEDED(hr) && srpClipboardHelper)
    {
        hr = srpClipboardHelper->Paste(srpIDataObject, dwDropEffect);
    }

	return hr;
}

STDMETHODIMP CMyProjectHierarchy::OnPaste(BOOL fDataWasCut, DWORD dwEffects)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = NOERROR;
	
    if (dwEffects == DROPEFFECT_NONE)
    {
	    hr = CleanupSelectionDataObject(
            /* [in] BOOL fDropped*/ FALSE, 
            /* [in] BOOL fCut    */ fDataWasCut, 
            /* [in] BOOL fMoved  */ FALSE);
    }
    else
    {
	    hr = CleanupSelectionDataObject(
            /* [in] BOOL fDropped*/ FALSE, 
            /* [in] BOOL fCut    */ fDataWasCut, 
            /* [in] BOOL fMoved  */ dwEffects == DROPEFFECT_MOVE);
    }
	return hr;
}

STDMETHODIMP CMyProjectHierarchy::OnClear(BOOL fDataWasCut)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;
    
    // restore the previously cut/copied object back to its uncut state
    if (!m_fInCutCopy)
	    hr = CleanupSelectionDataObject(
            /* [in] BOOL fDropped*/ FALSE, 
            /* [in] BOOL fCut    */ fDataWasCut, 
            /* [in] BOOL fMoved  */ FALSE);
    
    return hr;
}



STDMETHODIMP CMyProjectHierarchy::RegisterClipboardNotifications(
    /* [in] */ BOOL fRegister)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

	if (fRegister && (m_vscookieIVsUIHierWinClipboardHelperEvents == VSCOOKIE_NIL) )
	{
		// register advise sink for clipboard helper events
        CComPtr<IVsUIHierWinClipboardHelper> srpIVsUIHierWinClipboardHelper;
        hr = _VxModule.QueryService(
            SID_SVsUIHierWinClipboardHelper, 
            IID_IVsUIHierWinClipboardHelper, 
            (void**)&srpIVsUIHierWinClipboardHelper);
        IfFailRet(hr);
        ExpectedExprRet(srpIVsUIHierWinClipboardHelper != NULL);

        hr = srpIVsUIHierWinClipboardHelper->AdviseClipboardHelperEvents(
            QI_cast<IVsUIHierWinClipboardHelperEvents>(this),
            &m_vscookieIVsUIHierWinClipboardHelperEvents);
        IfFailRet(hr);
        ExpectedExprRet(m_vscookieIVsUIHierWinClipboardHelperEvents != VSCOOKIE_NIL);
	}
	else if (!fRegister && (m_vscookieIVsUIHierWinClipboardHelperEvents != VSCOOKIE_NIL) )
	{
        CComPtr<IVsUIHierWinClipboardHelper> srpIVsUIHierWinClipboardHelper;
        hr = _VxModule.QueryService(
            SID_SVsUIHierWinClipboardHelper, 
            IID_IVsUIHierWinClipboardHelper, 
            (void**)&srpIVsUIHierWinClipboardHelper);
        ASSERT(SUCCEEDED(hr) && (srpIVsUIHierWinClipboardHelper != NULL) );
        if (SUCCEEDED(hr) && (srpIVsUIHierWinClipboardHelper != NULL))
        {
            hr = srpIVsUIHierWinClipboardHelper->UnadviseClipboardHelperEvents(
                m_vscookieIVsUIHierWinClipboardHelperEvents);
        }
		m_vscookieIVsUIHierWinClipboardHelperEvents = VSCOOKIE_NIL;
	}

	return hr;
}
//                                           DRAG AND DROP, CUT, COPY, PASTE
// =========================================================================


//---------------------------------------------------------------------------
//	Checks whether we can dirty the project file
//---------------------------------------------------------------------------
BOOL CMyProjectHierarchy::QueryEditProjectFile()
{
    CFileVwProjNode* pProjectNode = GetProjectNode();
    if (!pProjectNode)
        return FALSE;

    return pProjectNode->QueryEditProjectFile();
}


HRESULT CMyProjectHierarchy::OnProjectRenamed()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	// update the data
	CFileVwProjNode * pCFileVwProjNode = GetProjectNode();
	if (!pCFileVwProjNode)
		return E_FAIL;

	// we are not changing the location
	m_strProjFullPath = pCFileVwProjNode->GetFullPath();
	return S_OK;
}


// =========================================================================
//                                                        IVsGlobalsCallback
//

STDMETHODIMP CMyProjectHierarchy::WriteVariablesToData(
    /* [in] */ LPCOLESTR  pVariableName,
    /* [in] */ VARIANT *  varData)
{
    ExpectedPtrRet(pVariableName); 
    ExpectedPtrRet(varData);

    USES_CONVERSION;
    CComVariant cvar(*varData);
    HRESULT hr = cvar.ChangeType(VT_BSTR);
    IfFailRet(hr);

    CString strVal = cvar.bstrVal;

    m_mapGlobals.SetAt(OLE2CT(pVariableName), strVal);
    return S_OK;
}


STDMETHODIMP CMyProjectHierarchy::ReadData(
    /* [in] */ VxDTE::Globals *pGlobals)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pGlobals);

    HRESULT hr = S_OK;
    CString strKeyName;
    CString strKeyVal;

    VARIANT var;
    var.vt = VT_BSTR;
    BSTR bstrKeyName;

    POSITION pos = m_mapGlobals.GetStartPosition();
    while( pos )
    {
        m_mapGlobals.GetNextAssoc( pos, strKeyName, strKeyVal );

        var.bstrVal = strKeyVal.AllocSysString();
        bstrKeyName = strKeyName.AllocSysString();
        if ((NULL != var.bstrVal) && (NULL != bstrKeyName))
            hr = pGlobals->put_VariableValue(bstrKeyName, var);
        else
            hr = E_OUTOFMEMORY;
        SysFreeString(var.bstrVal);
        SysFreeString(bstrKeyName);
        IfFailRet(hr);
    }

    return S_OK;
}


STDMETHODIMP CMyProjectHierarchy::ClearVariables()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    m_mapGlobals.RemoveAll();
    return S_OK;
}


STDMETHODIMP CMyProjectHierarchy::VariableChanged()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    put_IsDirty(VARIANT_TRUE);
    return S_OK;
}


STDMETHODIMP CMyProjectHierarchy::CanModifySource()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Return if the project file is not editable
    return QueryEditProjectFile() ? S_OK : S_FALSE;
}


STDMETHODIMP CMyProjectHierarchy::GetParent(
    /* [out] */ IDispatch **ppOut)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    CFileVwProjNode* pProjectNode = GetProjectNode();
    ExpectedExprRet(pProjectNode != NULL);

    return pProjectNode->GetAutomationObject(ppOut);
} 


STDMETHODIMP CMyProjectHierarchy::LoadGlobals(
    /* [in] */ IVsPropertyStreamIn *pIVsPropertyStreamIn)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pIVsPropertyStreamIn);

    HRESULT hr = S_OK;
    USES_CONVERSION;

    for (;;)
    {
        CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamIn;
        VSPROPERTYSTREAMPROPERTYTYPE vspspt;

        const ULONG cchBuffer = _MAX_PATH;
        WCHAR wszPropName[cchBuffer];

        CComVariant cvarValue;
        hr = pIVsPropertyStreamIn->Read(
                cchBuffer, 
                wszPropName, 
                NULL, 
                &vspspt, 
                &cvarValue, 
                NULL);

        ASSERT(SUCCEEDED(hr));
        IfFailRet(hr);

        if (wszPropName[0] == L'\0')
            break;

        if (vspspt != VSPSPT_SIMPLE || cvarValue.vt != VT_BSTR)
        {
            ASSERT(FALSE);
            return E_UNEXPECTED;
        }

        m_mapGlobals.SetAt(W2CT(wszPropName), W2CT(cvarValue.bstrVal));
    }

    // load the data into the gobals object if it exists
    CComPtr<IVsGlobals> srpIVsGlobals;
    if (SUCCEEDED(GetIVsGlobals(&srpIVsGlobals)) && (srpIVsGlobals != NULL) )
    {
        // triggers a call to our implementation of IVsGlobalsCallback::ReadData
        hr = srpIVsGlobals->Load();
        ASSERT(SUCCEEDED(hr));
    }

    return hr;
}


STDMETHODIMP CMyProjectHierarchy::SaveGlobals(
    /* [in] */ IVsPropertyStreamOut *pIVsPropertyStreamOut)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pIVsPropertyStreamOut);

    HRESULT hr = S_OK;

    // First, save any extensibility global data
    CComPtr<IVsGlobals> srpIVsGlobals;
    if (SUCCEEDED(GetIVsGlobals(&srpIVsGlobals)) && (srpIVsGlobals != NULL) )
    {
        // triggers a call to our implementation of IVsGlobalsCallback::WriteVariablesToData
        hr = srpIVsGlobals->Save();
        IfFailRet(hr);
    }
    
    // now save the data
    CString strKey;
    CString strValue;
    POSITION pos = m_mapGlobals.GetStartPosition();
    while( pos )
    {
        m_mapGlobals.GetNextAssoc( pos, strKey, strValue );
        hr = pIVsPropertyStreamOut->WriteSzAsBSTR(
            /* [in] LPCOLESTR           szPropertyName */ T2COLE(strKey),
            /* [in] LPCOLESTR           szValue        */ T2COLE(strValue),
            /* [optional][in] LPCOLESTR szLineComment  */ NULL);
        IfFailRet(hr);
    }

    return S_OK;
}


STDMETHODIMP CMyProjectHierarchy::GetIVsGlobals(
    /* [out] */ IVsGlobals ** ppIVsGlobals)
{   
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(ppIVsGlobals);
    InitParam(ppIVsGlobals);

    HRESULT hr = S_OK;
  
    CComPtr<IDispatch> srpDispProject;
    hr = GetParent(&srpDispProject);
    IfFailRet(hr);
    ExpectedExprRet(srpDispProject != NULL);
    
    CComPtr<Project> srpProject;
    hr = srpDispProject->QueryInterface(VxDTE::IID__Project, (void **)&srpProject);
    IfFailRet(hr);
    ExpectedExprRet(srpProject != NULL);

    CComPtr<Globals> srpGlobals;
    hr = srpProject->get_Globals(&srpGlobals);
    _IfFailRet(hr);
    ExpectedExprRet(srpGlobals != NULL);
    
    hr = srpGlobals->QueryInterface(VxDTE::IID_IVsGlobals, (void **)ppIVsGlobals);
    IfFailRet(hr);

    return hr;
}

//
//                                                        IVsGlobalsCallback
// =========================================================================


CFileVwFileNode* CMyProjectHierarchy::VSITEMID2FileNode(const VSITEMID vsitemid)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return NULL;

	if (vsitemid == NULL)
        return NULL;
    
    CHierNode* pHierNode = NULL;
    HRESULT hr = VSITEMID2Node(vsitemid, &pHierNode);
    if (FAILED(hr))
        return NULL;

    ASSERT(pHierNode);
    if( !pHierNode)
        return NULL;
    if (!pHierNode->IsKindOf(Type_CFileVwFileNode))
        return NULL;

    return static_cast<CFileVwFileNode*>(pHierNode);
}


