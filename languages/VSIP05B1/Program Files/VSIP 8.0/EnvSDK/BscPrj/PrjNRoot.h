
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNRoot.h : Declaration of root project node implementation. A project 
// node represents the VSITEMID_ROOT node in the IVsHierarchy of the project.

#pragma once

#include "PrjNContBase.h"
#include "PrjNFile.h"
#include "VsTrackProjectDocuments2Helper.h"

class CMyProjectHierarchy;
class CACProjectItems;
class CAutomationEvents;

//---------------------------------------------------------------------------
// Root FileView node for the Project Hierarchy
//
// implements (inherited from CHierNode):
//        interface: IOleCommandTarget
//
//---------------------------------------------------------------------------
class CFileVwProjNode :
    public CFileVwBaseContainer
{
    friend CMyProjectHierarchy;
    friend CFileVwBaseNode;
    friend CFileVwFileNode;
    
protected:
    virtual    ~CFileVwProjNode();

    HRESULT Initialize(CMyProjectHierarchy *pCMyProjectHierarchy, LPCTSTR pszCaption, LPCTSTR pszFullPath);

public:
    // RTTI implementation
    IMPLEMENT_RTTI(CFileVwProjNode)
    static HRESULT CreateInstance(CMyProjectHierarchy *pCMyProjectHierarchy, LPCTSTR pszCaption, LPCTSTR pszFullPath, CFileVwProjNode **ppProjNode);
    CFileVwProjNode();
    HRESULT Close();

    DECLARE_NOT_AGGREGATABLE(CFileVwProjNode)

    BEGIN_COM_MAP(CFileVwProjNode)
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

public:
    UINT GetIconIndex(ICON_TYPE iconType) const;
    virtual HRESULT GetFolderPath(CString& strFolderPath) const;
    virtual const CString& GetFullPath(void) const { return m_strFullPath; }
    virtual HRESULT GetProperty(VSHPROPID propid, VARIANT* pvar);
    virtual HRESULT GetGuidProperty(VSHPROPID propid, GUID* pGuid) const;
    virtual HRESULT SetGuidProperty(
        /* [in] */ VSHPROPID propid,
        /* [in] */ REFGUID   guid);

    IMPLEMENT_ISUPPORTERRORINFO(CFileVwProjNode);

    virtual VSITEMID        GetVsItemID() const;
    virtual CVsHierarchy*    GetCVsHierarchy() const;

    virtual const GUID*   PGuidGetType(void) const;

    virtual UINT GetContextMenu() { return IDM_VS_CTXT_PROJNODE; }
    virtual HRESULT GetObjectType(CString& strObjType)
    {
        return strObjType.LoadString(IDS_PROJNODE_TYPE) ? S_OK : E_FAIL;
    }

    // Manage IsDirty notion for project file
    BOOL QueryEditProjectFile();
    void SetProjectFileDirty(BOOL fDirty) { m_fDirty = fDirty; }
    BOOL IsProjectFileDirty(void) {    return m_fDirty; }

    // Manage the project name
    HRESULT GetEditLabel(BSTR *pbstrLabel);
    HRESULT SetEditLabel(BSTR bstrLabel);
    HRESULT RenameProject(BSTR bstrNewPrjName);
    HRESULT GetDefaultProjectExtension(CString& strExt);
    


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
    CMyProjectHierarchy*    m_pCMyProjectHierarchy;
    BOOL m_fDirty;

    // IVsTrackProjectDocuments2 helper
    CVsTrackProjectDocuments2Helper* m_pCVsTrackProjectDocuments2Helper;

        // Project GUID
    GUID            m_guidProject;

};
