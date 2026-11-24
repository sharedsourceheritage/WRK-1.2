
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNRoot.h : Declaration of root project node implementation. A project 
// node represents the VSITEMID_ROOT node in the IVsHierarchy of the project.

#pragma once

class CMyProjectHierarchy;
class CLangFileNode;
class CBuildProjNode;
class CACProjectItems;
class CAutomationEvents;

//---------------------------------------------------------------------------
// Root FileView node for the Project Hierarchy
//
// implements (inherited from CHierNode):
//		interface: IOleCommandTarget
//
//---------------------------------------------------------------------------
class CFileVwProjNode :
	public CFileVwBaseNode
{
	friend CMyProjectHierarchy;
	friend CFileVwBaseNode;
	friend CFileVwFileNode;
	friend CBuildProjNode;

protected:
	virtual	~CFileVwProjNode();

	HRESULT Initialize(CMyProjectHierarchy *pCMyProjectHierarchy, LPCTSTR pszCaption, LPCTSTR pszFullPath);

public:
	IMPLEMENT_RTTI(CFileVwProjNode)
	static HRESULT CreateInstance(CMyProjectHierarchy *pCMyProjectHierarchy, LPCTSTR pszCaption, LPCTSTR pszFullPath, CFileVwProjNode **ppProjNode);
	CFileVwProjNode();
    HRESULT Close();

DECLARE_NOT_AGGREGATABLE(CFileVwProjNode)

BEGIN_COM_MAP(CFileVwProjNode)
//	COM_INTERFACE_ENTRY(IOleCommandTarget)
END_COM_MAP()

// IOleCommandTarget
public:
	STDMETHOD(QueryStatus)( 
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [out][in][size_is] */ OLECMD prgCmds[],
            /* [unique][out][in] */ OLECMDTEXT *pCmdText);
        
	STDMETHOD(Exec)( 
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ DWORD nCmdID,
            /* [in] */ DWORD nCmdexecopt,
            /* [unique][in] */ VARIANT *pvaIn,
            /* [unique][out][in] */ VARIANT *pvaOut);
	IMPLEMENT_ISUPPORTERRORINFO(CFileVwProjNode);

public:
    UINT GetIconIndex(ICON_TYPE iconType) const;
	const CString& GetFolderPath(void) const; 
	virtual HRESULT GetProperty(VSHPROPID propid, VARIANT* pvar);
	virtual HRESULT GetGuidProperty(VSHPROPID propid, GUID* pGuid) const;
    virtual HRESULT SetGuidProperty(
        /* [in] */ VSHPROPID propid,
        /* [in] */ REFGUID   guid);

	// Manage IsDirty notion for project file
	BOOL QueryEditProjectFile();
	void SetProjectFileDirty(BOOL fDirty) { m_fDirty = fDirty; }
	BOOL IsProjectFileDirty(void) {	return m_fDirty; }
	void SetStartupItem(CLangFileNode *pStartupItem) { m_pStartupItem = pStartupItem; }
	CLangFileNode * GetStartupItem(void) { return m_pStartupItem; }
	BOOL GetShowAllFiles(void) { return m_fShowAllFiles; }
	void SetShowAllFiles(BOOL fShowAll);

public:
	HRESULT AddBuildProject(LPCTSTR pszFullPathSource,CBuildProjNode **ppNewFile, REFGUID rGuid);

	virtual VSITEMID		GetVsItemID() const;
	virtual CVsHierarchy*	GetCVsHierarchy() const;

	virtual const GUID*   PGuidGetType(void) const;

	virtual UINT GetContextMenu() { return IDM_VS_CTXT_PROJNODE; }
	HRESULT GetUserContext(IVsUserContext **ppUserCtx);

	virtual HRESULT GetObjectType(CString& strObjType)
	{
		return strObjType.LoadString(IDS_PROJNODE_TYPE) ? S_OK : E_FAIL;
	}

	HRESULT OnCmdAddItem(BOOL fAddNewItem, LPCWSTR pszSelectItem = NULL,
					  LPCWSTR pszExpandDir = NULL);
    HRESULT AddItem(
        /* [in]  */ VSADDITEMOPERATION    dwAddItemOperation,
        /* [in]  */ LPCOLESTR             pszItemName,
        /* [in]  */ ULONG                 cFilesToOpen,
        /* [in]  */ LPCOLESTR             rgpszFilesToOpen[],
        /* [in]  */ HWND                  hwndDlg,
        /* [in]  */ VSSPECIFICEDITORFLAGS grfEditorFlags,
        /* [in]  */ REFGUID               rguidEditorType,
        /* [in]  */ LPCOLESTR             pszPhysicalView,
        /* [in]  */ REFGUID               rguidLogicalView,
        /* [in]  */ BOOL                  fOpenWithDefault,
        /* [out] */ VSADDRESULT *         pResult);

    HRESULT AddExistingFile(LPCTSTR pszFullPathSource, CHierNode **ppNewFile, BOOL fSilent = FALSE, BOOL fLoad = FALSE );
	HRESULT AddNewFile(
				LPCTSTR pszFullPathSource,
				LPCTSTR pszNewFileName,
                CHierNode** ppNewNode);
    HRESULT RunWizard(
        /* [in]                        */ LPCOLESTR             pszItemName,
        /* [in]                        */ ULONG                 cFilesToOpen,
        /* [in, size_is(cFilesToOpen)] */ LPCOLESTR             rgpszFilesToOpen[],
        /* [in]                        */ HWND                  hwndDlg,
        /* [out, retval]               */ VSADDRESULT *         pResult);

	HRESULT OnCmdShowAllFiles(BOOL fDisplayAll);

    //----------------------------------------------------------------------
    // Recursivley shows all files. 
    //----------------------------------------------------------------------
    HRESULT ShowAllFiles();

    //----------------------------------------------------------------------
    // Recursivley ensures only the fig files are shown
    //----------------------------------------------------------------------
    HRESULT ShowFigFilesOnly();


	HRESULT GetEditLabel(BSTR *pbstrLabel);
	HRESULT SetEditLabel(BSTR bstrLabel);
	HRESULT RenameProject(BSTR bstrNewPrjName);
	HRESULT GetDefaultProjectExtension(CString& strExt);

    // Delete a node from the project
    HRESULT DeleteNode(
        /* [in] */ CHierNode* pNode,        // node to be delted
        /* [in] */ BOOL fRemoveFromDisk);   // removes the file from disk

    HRESULT DeleteNestedProject(
        /* [in] */  CBuildProjNode*  pNode);

    CVsTrackProjectDocuments2Helper* GetCVsTrackProjectDocuments2Helper()
    {
        return m_pCVsTrackProjectDocuments2Helper;
    }

    STDMETHOD(GetAutomationObject)(
        /* [out] */ IDispatch ** ppIDispatch);

	CMyProjectHierarchy* GetCMyProjectHierarchy()
    {
        return m_pCMyProjectHierarchy;
    }

	IVsHierarchy* GetIVsHierarchy();

protected:
	CComPtr<Project> m_srpProject;
	CMyProjectHierarchy*	m_pCMyProjectHierarchy;
	BOOL			m_fDirty;
	BOOL            m_fShowAllFiles;
	CLangFileNode*	m_pStartupItem;

    // IVsTrackProjectDocuments2 helper
    CVsTrackProjectDocuments2Helper* m_pCVsTrackProjectDocuments2Helper;

        // Project GUID
    GUID            m_guidProject;

};
