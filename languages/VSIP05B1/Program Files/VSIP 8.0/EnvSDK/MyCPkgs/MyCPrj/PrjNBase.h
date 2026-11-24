
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNBase.h : Declaration of base project node implementation. A project 
// node represents a single itemid (node) in the IVsHierarchy of the project.

#pragma once

/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CFileVwBaseNode;
class CFileVwProjNode;


// Object Type information
enum
{
	Type_CFileVwBaseNode = (Type_FirstUser << 1) | Type_CHierContainer,
	Type_CFileVwProjNode = (Type_FirstUser << 2) | Type_CFileVwBaseNode,
	Type_CFileVwFileNode = (Type_FirstUser << 3) | Type_CFileVwBaseNode,
};

/////////////////////////////////////////////////////////////////////////////
// CFileVwBaseNode
//---------------------------------------------------------------------------
// implements (inherited from CHierNode):
//		interface: IOleCommandTarget
// Note: IOleCommandTarget no longer implemented in CHierNode
//---------------------------------------------------------------------------

class ATL_NO_VTABLE CFileVwBaseNode :
	public CHierContainer
{
protected:
	virtual ~CFileVwBaseNode(void) { }

public:
	virtual ULONG STDMETHODCALLTYPE AddRef(void) = 0; 
	virtual ULONG STDMETHODCALLTYPE Release(void) = 0;
	STDMETHOD(QueryInterface)(REFIID, void**) = 0;

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

public:
	// RTTI implementation
	IMPLEMENT_RTTI(CFileVwBaseNode)

		
	virtual HRESULT	GetCanonicalName(BSTR* ppszName) const;
	virtual HRESULT GetProperty(VSHPROPID propid, VARIANT* pvar);
    virtual HRESULT SetGuidProperty(
        /* [in] */ VSHPROPID propid,
        /* [in] */ REFGUID   guid) { return E_NOTIMPL;}

	virtual HRESULT	EnumerateChildren() { return S_OK; }
	virtual HRESULT DisplayContextMenu();

	HRESULT GetProjRelativePath(CString& strProjRelPath) const;
	const CString& GetFullPath(void) const { return m_strFullPath; }
	const CString& GetFileName(void) const { return m_strFileName; }
	virtual void SetFullPath(LPCTSTR pszFullPath);
	CFileVwBaseNode* GetNodeByFullPath(LPCTSTR pszFullPath);
    CHierNode* GetNodeByCanonicalName(LPCOLESTR pszCanonicalName);
	CFileVwProjNode* GetProjectNode(void) const;
	virtual HRESULT GetObjectType(CString& strObjType) = 0;

	// This virtual method should be overriden in derived node types in order 
	// to write properties to the project file.
	virtual HRESULT Save(IVsPropertyStreamOut *pIVsPropertyStreamOut) 
			{ return S_OK; }

	// This virtual method should be overriden in derived node types in order 
	// to read properties to the project file.
	virtual HRESULT Load(IVsPropertyStreamOut *pIVsPropertyStreamOut) 
			{ return S_OK; }

	void ReDraw(BOOL bUpdateIcon = TRUE, BOOL bUpdateStateIcon =TRUE, BOOL bUpdateText = FALSE);

    //---------------------------------------------------------------------
    // returns an item's ui state 
    //---------------------------------------------------------------------
    VSHIERARCHYITEMSTATE GetItemState(
        /* [in] */ VSHIERARCHYITEMSTATE dwStateMask) const;
    BOOL IsExpanded() const {return GetItemState(HIS_Expanded) == HIS_Expanded;}

	// Source control Helper functions
    virtual BOOL UpdateSccStatus(DWORD dwSccStatus);
    virtual void ClearSccState(void) { m_grfStateFlags &= ST_StateClearMask; };
    virtual void SetSccUnderSCC(void) { m_grfStateFlags |= ST_IsUnderSCC; };
    virtual void SetSccCheckedOut(void) { m_grfStateFlags |= ST_IsCheckedOut; };

    // Return the state image for this node.
	virtual UINT GetIconIndex(ICON_TYPE	iconType) const;

	// State flags (stored in m_grfStateFlags)
	enum
	{
		// These are mutually exclusive bits ie. only one of them can be set.
        ST_IsCheckedOut   = (ST_FirstUserFlag),	// File is checked out
        ST_IsUnderSCC	  = (ST_FirstUserFlag <<1),	// File is under scc.
		ST_StateMask	  = ST_IsCheckedOut| ST_IsUnderSCC,
		ST_StateClearMask = ~ST_StateMask,		// Clears all state bits.
	};

protected:
	CString m_strFullPath;
	CString m_strFileName;

	// State access helpers
	BOOL	IsSet(int bits) const {return (m_grfStateFlags & bits)? TRUE : FALSE;} // Returns true if bit (or any bit in state is set)
	void	SetBits(int bits, BOOL bValue);					 // Sets/resets bit
};

