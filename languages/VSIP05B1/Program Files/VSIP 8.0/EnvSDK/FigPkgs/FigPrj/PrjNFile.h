
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNFile.h : Declaration of file (project item) node implementation. A file 
// node represents an item node in the IVsHierarchy of the project.

#pragma once

class CMyProjectHierarchy;
class CFileVwProjNode;


//---------------------------------------------------------------------------
// File node for the Project Hierarchy
//---------------------------------------------------------------------------
class CFileVwFileNode :
	public CFileVwBaseNode

{
	friend CMyProjectHierarchy;
	friend CFileVwProjNode;
  
protected:
	virtual	~CFileVwFileNode();

	HRESULT Initialize(LPCTSTR pszFullPath);
	virtual void SetFullPath(LPCTSTR pszFullPath);

public:
	IMPLEMENT_RTTI(CFileVwFileNode)
	static HRESULT CreateInstance(LPCTSTR pszFullPath, CFileVwFileNode **ppFileNode);
	CFileVwFileNode();
    virtual HRESULT Close();

DECLARE_NOT_AGGREGATABLE(CFileVwFileNode)

BEGIN_COM_MAP(CFileVwFileNode)
END_COM_MAP()


// IFigPrjProjHierItemProps
public:
	STDMETHOD(get_FileName)(BSTR *pVal);
	STDMETHOD(put_FileName)(BSTR NewName);
	STDMETHOD(get_FilePath)(BSTR *pVal);
	STDMETHOD(get_ModifiedDate)(VARIANT *pVal);
	STDMETHOD(get_Size)(double *pVal);
	STDMETHOD(get_FileType)(BSTR *pVal);
	STDMETHOD(get_ReadOnly)(VARIANT_BOOL *pVal);
	STDMETHOD(put_ReadOnly)(VARIANT_BOOL pVal);
	STDMETHOD(get_ExcludeFromBuild)(VARIANT_BOOL *pVal);
	STDMETHOD(put_ExcludeFromBuild)(VARIANT_BOOL pVal);

    // Returns the requested extender object if it is available.
    STDMETHOD(get_Extender)(
        /* [in]          */ BSTR         bstrExtenderName, 
        /* [out, retval] */ IDispatch ** ppExtender);

    // Returns a safe array of string names of currently applicable extenders.
    STDMETHOD(get_ExtenderNames)(
        /* [out, retval] */ VARIANT * pvarExtenderNames);

    // Returns the GUID string for the Project object that is the category ID for 
    // searching for automation extenders. Implementers of extenders for this object 
    // need to know its extender CATID.
    STDMETHOD(get_ExtenderCATID)(
        /* [out, retval] */ BSTR * pbstrRetval);

	IMPLEMENT_ISUPPORTERRORINFO(CFileVwFileNode);

protected:
    STDMETHOD(OnPropertyChanged)(
        /* [in] */ DISPID dispid        = DISPID_UNKNOWN , 
        /* [in] */ BOOL   fDirtyProject = TRUE           );

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

	virtual HRESULT GetProperty(VSHPROPID propid, VARIANT* pvar);
	virtual HRESULT GetGuidProperty(VSHPROPID propid, GUID* pGuid) const;

	//FIG - Added since this is common to both cs and Fig
public:

	// our file node is neither Expandable or should be ExpandedByDefault.
	// return VARIANT_FALSE here will make VSHPROPID_Expandable and
	// VSHPROPID_ExpandByDefault return false.
	virtual BOOL Expandable() const { return FALSE; }
	virtual const GUID*   PGuidGetType(void) const;
	virtual HRESULT DoDefaultAction() { return OnCmdOpen(); }
	virtual UINT GetContextMenu() { return IDM_VS_CTXT_ITEMNODE; }
	virtual HRESULT GetObjectType(CString& strObjType)
	{
		return strObjType.LoadString(IDS_FILENODE_TYPE) ? S_OK : E_FAIL;
	}

	virtual HRESULT Save(IVsPropertyStreamOut *pIVsPropertyStreamOut);
	virtual HRESULT Load(IVsPropertyStreamIn *pIVsPropertyStreamIn);

    virtual BOOL SupportsDesignView() {return IsKindOf(Type_CFigFileNode);}
    virtual BOOL SupportsCodeView() {return IsKindOf(Type_CFigFileNode);}
	HRESULT OnCmdOpenWith();
	HRESULT OnCmdOpen();
	HRESULT OnCmdViewCode();
	HRESULT OnCmdViewForm();
	HRESULT OnDelete(void);


// =========================================================================
//                                                       Document management
public:

    //----------------------------------------------------------------------
    // Opens this file with default editor - either global or project specific.
    // If fUseProjectSpecificEditor is TRUE then project-specific editor is used
    // If fUseProjectSpecificEditor is FALSE then IVsProjectSpecificEditorMap2::
    // GetSpecificEditorProperty is called with VSPSEPROPID_UseGlobalEditorByDefault
    // to determine whether the project-specific editor is the default one.
    //----------------------------------------------------------------------
    HRESULT OpenDocWithDefault(
        /* [in] */ BOOL fUseProjectSpecificEditor,
        /* [in] */ BOOL fNewFile);

    //----------------------------------------------------------------------
    // opens the code or desugner view with project specific editor
    //----------------------------------------------------------------------
    HRESULT OpenDocWithProjectSpecific(
        /* [in] */ REFGUID rguidLogicalView,
        /* [in] */ BOOL    fNewFile);

    //----------------------------------------------------------------------
    // Performs the actual open operation. Returns S_OK if successful.
    //----------------------------------------------------------------------
	HRESULT OpenDoc(
		/* [in]  */ BOOL       fNewFile            = FALSE, 
		/* [in]  */ BOOL       fUseOpenWith        = FALSE,
        /* [in]  */ BOOL       fShow               = TRUE,
		/* [in]  */ REFGUID    rguidLogicalView    = LOGVIEWID_Primary,
		/* [in]  */ IUnknown * punkDocDataExisting = DOCDATAEXISTING_UNKNOWN, 
		/* [out] */ IVsWindowFrame** ppWindowFrame = NULL);

    //----------------------------------------------------------------------
    // Performs the actual open operation with a specific editor.
    //----------------------------------------------------------------------
    HRESULT OpenDocWithSpecific(
        /* [in]  */ REFGUID           rguidEditorType, 
        /* [in]  */ LPCOLESTR         pszPhysicalView,
        /* [in]  */ REFGUID           rguidLogicalView, 
        /* [in]  */ IUnknown *        punkDocDataExisting   = NULL,
        /* [out] */ IVsWindowFrame ** ppWindowFrame         = NULL, 
        /* [in]  */ BOOL              fShowWindow           = TRUE,
        /* [in]  */ BOOL              fNewFile              = FALSE);

    //----------------------------------------------------------------------
    // Returns information about the doc state.
    //----------------------------------------------------------------------
    HRESULT GetDocInfo(
        /* [out, opt] */ BOOL*        pfOpen,     // true if the doc is opened
        /* [out, opt] */ BOOL*        pfDirty,    // true if the doc is dirty
        /* [out, opt] */ BOOL*        pfOpenByUs, // true if opened by our project
        /* [out, opt] */ VSDOCCOOKIE* pVsDocCookie);// VSDOCCOOKIE if open

    //----------------------------------------------------------------------
    // Save the document if it is open by our project.
    //----------------------------------------------------------------------
    HRESULT SaveDoc(
        /* [in] */ VSSLNSAVEOPTIONS grfSaveOpts);
    
    //----------------------------------------------------------------------
    // Close the document if it is open by our project.
    //----------------------------------------------------------------------
    HRESULT CloseDoc(
        /* [in] */ VSSLNCLOSEOPTIONS grfCloseOpts);

//                                                       Document management
// =========================================================================

public:
	bool m_ExcludeFromBuild;

protected:
	//When this item is created, we need to set the name of the file it represents,
	//	causing a rename event befor the ItemAdded event. This is turned off uing the
	//	folloing flag:
	BOOL m_fFireRenameEvent;

    // Automation ProjectItem for this node
	CComPtr<ProjectItem> m_srpProjectItem;
};
