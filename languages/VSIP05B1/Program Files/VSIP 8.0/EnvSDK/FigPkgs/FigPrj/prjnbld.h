
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//--------------------------------------------------------------------------
// prjnbld.h
//--------------------------------------------------------------------------
#pragma once

extern const TCHAR g_szBuildProjName[];
extern const TCHAR g_szBuildProjExt[];
extern const TCHAR g_szMainForm[];
extern const TCHAR g_szFigureDrawingObject[];

//--------------------------------------------------------------------------
// Nested build node.
//--------------------------------------------------------------------------
class ATL_NO_VTABLE CBuildProjNode :
    public CHierNestedContainer
{
//==========================================================================
//                                                construct, init , destruct
public:
    //----------------------------------------------------------------------
    // creates a proxy to the cs Build project hierarchy
    //----------------------------------------------------------------------
    static HRESULT CreateInstance(LPCTSTR pszFullPath, CBuildProjNode **pNode);
    
    //----------------------------------------------------------------------
    // initialize
    //----------------------------------------------------------------------
    STDMETHOD(Init)(
        /* [in] */ LPCTSTR pszGuid);

    //----------------------------------------------------------------------
    // Called when the parent project is fully created
    //----------------------------------------------------------------------
    STDMETHOD(AddNestedHierarchy)();

    //----------------------------------------------------------------------
    // Close the nested hierarchy
    //----------------------------------------------------------------------
    STDMETHOD(Close)(
        /* [in] */ BOOL fAskToSaveIfDirty = TRUE);

protected:
    CBuildProjNode(void);
    virtual ~CBuildProjNode(void);
    //----------------------------------------------------------------------
    // overide: CHierNestedContainer
    //----------------------------------------------------------------------
    virtual HRESULT InitNestedHierarchy(void);
	HRESULT InitNestedCmdTarget(void);

    //----------------------------------------------------------------------
    // lock this nested hierachy in the RDT.
    //----------------------------------------------------------------------
    HRESULT LockRDTEntry();

    //----------------------------------------------------------------------
    // unlock this nested hierachy from the RDT
    //----------------------------------------------------------------------
    HRESULT UnlockRDTEntry();

    //----------------------------------------------------------------------
    // Advise to the project file changes
    //----------------------------------------------------------------------
    HRESULT AdviseFileChange();

    //----------------------------------------------------------------------
    // Unadvise to the project file changes
    //----------------------------------------------------------------------
    HRESULT UnadviseFileChange();
//                                                construct, init , destruct
//==========================================================================

    // RTTI
    IMPLEMENT_RTTI(CBuildProjNode)

    // Error Info
    IMPLEMENT_ISUPPORTERRORINFO(CBuildProjNode)

	DECLARE_NOT_AGGREGATABLE(CBuildProjNode)


BEGIN_COM_MAP(CBuildProjNode)
END_COM_MAP()

public: // interface: IOleCommandTarget
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
		
public: // CHierNode
    virtual UINT GetIconIndex(ICON_TYPE) const;
    virtual HRESULT DisplayContextMenu(void);
    virtual HRESULT DoDefaultAction(void);
	virtual HRESULT GetProperty(VSHPROPID propid, VARIANT* pvar);

    //----------------------------------------------------------------------
    // Called by CVsHierarchy on VSHPROPID_UserContext.
    // Add our attributes and target links to filter our topics
    // in the Dynamic Help window.
    //----------------------------------------------------------------------
    virtual HRESULT GetUserContext(
        /* [out] */ IVsUserContext **ppUserCtx);
	
    //----------------------------------------------------------------------
    // Called by CVsHierarchy on GetGuidProperty.
    //----------------------------------------------------------------------
    virtual HRESULT GetGuidProperty(
        /* [in]  */ VSHPROPID propid, 
        /* [out] */ GUID*     pGuid) const;

protected:

    // Return icon handle for display in the project explorer tree
    // Called from GetProperty for VSHPROPID_IconIndex and 
    // VSHPROPID_OpenFolderIconHandle
    HRESULT GetIconHandle(
        /* [in]  */ VSHPROPID propid, 
        /* [out] */ VARIANT *pvar);

    // clear this node's icon handle (if it exists)
    void ClearIconHandle();

public: // CBuildProjNode
    HRESULT ExecNestedCommand(int cmdID);
	HRESULT GetNestedAutomationProject(
        /* [out */ Project **ppProject);

    void SetFullPath(LPCTSTR pszPath);
	HRESULT GetCanonicalName(BSTR* pbstrName) const;
	const CString& GetFullPath(void) const { return m_strFullPath; }
	HRESULT AddItem(LPCTSTR pszSourcePath, LPCTSTR pszItemName);

    //Returns the current RDT Cookie.
    VSDOCCOOKIE GetRDTCookie() { return m_dwDocCookie; }
    
    CFileVwProjNode* GetProjectNode() const;
    
    // IgnoreItemFielChange 
    STDMETHOD(OnIgnoreItemFileChanges)(
        /* [in] */ BOOL fIgnore);

    // Save the project file
    STDMETHOD(Save)(
            /* [in]  */ VSSAVEFLAGS dwSave,
            /* [in]  */ LPCOLESTR pszSilentSaveAsName,
            /* [in]  */ IUnknown *punkDocData,
            /* [out] */ BOOL *pfCanceled);

    STDMETHOD(Refresh)();

protected:
    CComPtr<IOleCommandTarget> m_srpNestedOleCmdTrg;
	CString		m_strFullPath;
	GUID		m_guidProjectID;
    BOOL        m_fInited;
    BOOL        m_fClosed;

    //This member holds a running doc table cookie for the nested project file.
    VSDOCCOOKIE             m_dwDocCookie;
    
    // IVsFileChangeEvents data
    CComPtr<IVsFileChangeEx> m_srpIVsFileChangeEx;
    VSCOOKIE m_vscookieIVsFileChangeEvents;
    BOOL     m_fIgnoreFileChanges;

	CComPtr<IVsUserContext> m_srpUserCtx;	// user context bag for Dynamic Help window

    // Automation object for this node
    CComPtr<ProjectItem>    m_srpProjectItem;

    //This member holds the icon for nested project roots
    HICON                   m_hIcon;
};
// End of prjbld.h
