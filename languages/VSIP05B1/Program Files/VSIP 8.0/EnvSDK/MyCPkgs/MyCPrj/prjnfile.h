
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNFile.h : Declaration of file (project item) node implementation. A file 
// node represents an item node in the IVsHierarchy of the project.

#pragma once

class CMyProjectHierarchy;



//---------------------------------------------------------------------------
// Root FileView node for the Project Hierarchy
//
// implements (inherited from CHierNode):
//		interface: IOleCommandTarget
//
// implements:
//		interface: IDispatch
//		interface: IMyCPrjProjHierItemProps
//---------------------------------------------------------------------------
class CFileVwFileNode :
	public CFileVwBaseNode,
    public IConnectionPointContainerImpl<CFileVwFileNode>,
    public IPropertyNotifySinkCP<CFileVwFileNode>,
	public IDispatchImpl<IMyCPrjProjHierItemProps, &IID_IMyCPrjProjHierItemProps, &LIBID_MyCPrjPKGLib>
{
	friend CMyProjectHierarchy;
	friend CFileVwProjNode;
	
protected:
	virtual	~CFileVwFileNode();

	HRESULT Initialize(LPCTSTR pszFullPath);
	virtual void SetFullPath(LPCTSTR pszFullPath);
    virtual HRESULT Rename(LPCTSTR pszNewName);

public:
	// RTTI implementation
	IMPLEMENT_RTTI(CFileVwFileNode)
	static HRESULT CreateInstance(LPCTSTR pszFullPath, CFileVwFileNode **ppFileNode);
	CFileVwFileNode();
    virtual HRESULT Close();

    DECLARE_NOT_AGGREGATABLE(CFileVwFileNode)

    BEGIN_COM_MAP(CFileVwFileNode)
	    COM_INTERFACE_ENTRY(IMyCPrjProjHierItemProps)
	    COM_INTERFACE_ENTRY(IDispatch)
	    COM_INTERFACE_ENTRY(IConnectionPointContainer)
    END_COM_MAP()

    BEGIN_CONNECTION_POINT_MAP(CFileVwFileNode)
        CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    END_CONNECTION_POINT_MAP()

// IMyCPrjProjHierItemProps
public:
	STDMETHOD(get_FileName)(BSTR *pVal);
	STDMETHOD(put_FileName)(BSTR NewName);
	STDMETHOD(get_FilePath)(BSTR *pVal);
	STDMETHOD(get_IsOutput)(VARIANT_BOOL *pVal);
	STDMETHOD(get_ModifiedDate)(VARIANT *pVal);
	STDMETHOD(get_Size)(double *pVal);
	STDMETHOD(get_FileType)(BSTR *pVal);
	STDMETHOD(get_ReadOnly)(VARIANT_BOOL *pVal);
	STDMETHOD(put_ReadOnly)(VARIANT_BOOL pVal);
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

protected:
    STDMETHOD(OnPropertyChanged)(
        /* [in] */ DISPID dispid        = DISPID_UNKNOWN , 
        /* [in] */ BOOL   fDirtyProject = TRUE           );

public:

	IMPLEMENT_ISUPPORTERRORINFO(CFileVwFileNode);

	// IOleCommandTarget
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

	HRESULT Save(IVsPropertyStreamOut *pIVsPropertyStreamOut) const;
	HRESULT Load(IVsPropertyStreamIn *pIVsPropertyStreamIn) const;
	HRESULT GetEditLabel(BSTR *pbstrLabel);
	HRESULT SetEditLabel(BSTR bstrLabel);


	HRESULT OnCmdOpenWith();
	HRESULT OnCmdOpen();
	HRESULT OnCmdViewPage(BOOL fPreviewWith = FALSE);
	HRESULT OnDelete(void);
	void OnItemRenamed(
		/* [in] */ LPCTSTR pszOldName);
    

// =========================================================================
//                                                       Document management
public:

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
    // Preview the document in a browser.
    //----------------------------------------------------------------------
	HRESULT PreviewDoc(
        /* [in]  */ BOOL fPreviewWith);

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

protected:
	CComPtr<ProjectItem> m_srpProjectItem;
    #ifndef USEDEFAULTSELECTION
	    CComPtr<SelectedItem> m_srpSelectedItem;
    #endif

};
