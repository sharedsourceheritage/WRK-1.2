
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

#include "PrjNContBase.h"

//---------------------------------------------------------------------------
// Root FolderView node for the Project Hierarchy
//
// implements (inherited from CHierNode):
//        interface: IOleCommandTarget
//
// implements:
//        interface: IDispatch
//        interface: IBscPrjProjHierFolderProps
//---------------------------------------------------------------------------
class CFileVwFolderNode :
    public CFileVwBaseContainer,
    public IConnectionPointContainerImpl<CFileVwFolderNode>,
    public IPropertyNotifySinkCP<CFileVwFolderNode>,
    public IDispatchImpl<IBscProjProjHierFolderProps, &IID_IBscProjProjHierFolderProps, &LIBID_BscPrjPKGLib>
{
protected:
    CFileVwFolderNode() {};
    ~CFileVwFolderNode() {};

public:
    DECLARE_NOT_AGGREGATABLE(CFileVwFolderNode)

    BEGIN_COM_MAP(CFileVwFolderNode)
        COM_INTERFACE_ENTRY(IBscProjProjHierFolderProps)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IConnectionPointContainer)
    END_COM_MAP()

    BEGIN_CONNECTION_POINT_MAP(CFileVwFolderNode)
        CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
    END_CONNECTION_POINT_MAP()

    IMPLEMENT_ISUPPORTERRORINFO(CFileVwFolderNode);

    static HRESULT CreateInstanceFromFolder(LPCTSTR pszFullPath, CFileVwFolderNode **ppFolderNode);
    static HRESULT CreateInstanceInFolder(LPCTSTR pszParentPath, CFileVwFolderNode **ppFolderNode);

    virtual UINT GetContextMenu() { return IDM_VS_CTXT_FOLDERNODE; }
    virtual HRESULT GetObjectType(CString& strObjType)
    {
        return strObjType.LoadString(IDS_FOLDERNODE_TYPE) ? S_OK : E_FAIL;
    }
    UINT GetIconIndex(ICON_TYPE iconType) const;
    const GUID*   PGuidGetType(void) const;
    HRESULT GetProperty(VSHPROPID propid, VARIANT* pvar);
    STDMETHOD (GetAutomationObject) (IDispatch ** ppIDispatch);

    virtual HRESULT OnDelete(void);

    virtual HRESULT GetFolderPath(CString& strFolderPath) const;

// =========================================================================
//                                                       RTTI Implementation
public:
    IMPLEMENT_RTTI(CFileVwFolderNode)
    HRESULT Close() { return S_OK; } ;

//
// =========================================================================

// =========================================================================
//                                               inherited from CVSHierarchy
public:
    HRESULT GetEditLabel(BSTR *pbstrLabel);
    HRESULT SetEditLabel(BSTR bstrLabel);
//
// =========================================================================


// =========================================================================
//                                               interface IOleCommandTarget
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

//                                               interface IOleCommandTarget
// =========================================================================


// =========================================================================
//                                     interface IBscProjProjHierFolderProps
public:
    STDMETHOD(get_FolderName)(BSTR *pVal);
    STDMETHOD(put_FolderName)(BSTR val);
//
// =========================================================================

protected:
    // Get a reference to the ProjectItem used for automation
    CComPtr<ProjectItem> m_srpProjectItem;
};
