//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// hu_archy.h: Definition of the CVsHierarchy class
//
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __HU_ARCHY_H__
#define __HU_ARCHY_H__

#ifndef  __docobj_h__
#include <DOCOBJ.H>     // OLE interfaces
#endif

#ifndef  __OBJEXT_H
#include <objext.h>     // VB6 interfaces & guids
#endif

#ifndef __TEMPL_H__
#include "templ.h"
#endif

#ifndef __ADVISLST_H__
#include "advislst.h"
#endif

#include "hu_util.h"

class CHierNode;
class CHierContainer;

typedef CVxTypedPtrList<CVxPtrList, CHierNode *> HierNodeList;

typedef enum ICON_TYPE
{
    ICON_Open,
    ICON_Closed,
    ICON_StateImage
} ICON_TYPE;


class CVsHierarchy;

struct VsHierList
{
  VsHierList()
  {
    pNext = NULL;
    pVsHierarchy = NULL;
  }

  CVsHierarchy *pVsHierarchy;
  VsHierList *pNext;
};


//
// When retrieving a shell interface from CVsHierarchy, perform a QI to get the desired interface.
// We can't perform a simple cast from CVsHierarchy to any shell interface because that prevents CVsHierarchy from 
// being aggregated correctly.
//
// Usage:   IVsHierarchy* pHier = QI_cast<IVsHierarchy>(this);
//          IVsProject*   pProj = QI_cast<IVsProject>(this);
//          etc.
//
template <typename T> CComPtr<T> QI_cast( const CVsHierarchy* pCVsHierarchy) 
{ 
    CComPtr<T>  pT;
    ((CVsHierarchy*)pCVsHierarchy)->QueryInterface( __uuidof(T), (void**)&pT );
    ASSERT( pT );
    return pT;
}

// Helper macro to return E_UNEXPECTED if the hierarchy has been closed
#define RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED \
        if(IsClosed()) \
        { \
            ATLTRACE(_T("Warning: Hierarchy function called after it was closed.\n"));\
            return E_UNEXPECTED; \
        }

//---------------------------------------------------------------------------
// provides:
//      interface: IVsHierarchy
//      interface: IVsUIHiearchy
//      interface: IVsPersistHiearchyItem
//      interface: IOleCommandTarget
//      interface: IPkgDropDataSource
//      interface: IPkgDropDataTarget
// consumes:
//      interface: ITrackSelectionEx
//---------------------------------------------------------------------------
class ATL_NO_VTABLE CVsHierarchy : 
    public CComObjectRootEx<CComSingleThreadModel>,     // explict
    public IVsUIHierarchy,
    public IVsPersistHierarchyItem,
    public IOleCommandTarget,
    public IVsHierarchyDropDataSource,
    public IVsHierarchyDropDataTarget,
    public ISupportErrorInfo
{
protected:
    virtual ~CVsHierarchy(void);
    virtual UINT GetIconIndex(CHierNode* pNode, ICON_TYPE icontype) = 0;

public:
    CVsHierarchy(void);

    static VsHierList *m_pVsHierList;

public: // get/set property methods
    // Made virtual to allow sub classes to do extra processing at this time. 
    // Overriders should call the base class.
    virtual void SetRootNode(CHierContainer *pRootNode)
    {
        m_pRootNode = pRootNode;
    }
    CHierContainer* GetRootNode(void) const
    {
        ASSERT(NULL != m_pRootNode);
        return m_pRootNode;
    }
    // return the controlling IUnk. A CComPtr copy is returned so that we don't loose the addref
    CComPtr<IVsHierarchy>   GetIVsHierarchy(void) const
    {
        return QI_cast<IVsHierarchy>( this );
    }
    // return the controlling IUnk. A CComPtr copy is returned so that we don't loose the addref
    CComPtr<IVsUIHierarchy>   GetIVsUIHierarchy(void) const
    {
        return QI_cast<IVsUIHierarchy>( this );
    }

    void SetImageList(HIMAGELIST hImageList)
    {
        ASSERT(!m_hImageList && hImageList);
        m_hImageList = hImageList;
    }
    HIMAGELIST GetImageList(void) const
    {
        return m_hImageList;
    }
    BOOL IsZombie(void) const
    {
        return (m_pRootNode == NULL);
    }
    BOOL IsClosed(void) const
    {
        return (m_fHierClosed);
    }
    const CComBSTR& GetOwnerKey()   const
    {
        return m_bstrOwnerKey;
    }
    void SetOwnerKey(LPCWSTR pszOwnerKey)
    {
        m_bstrOwnerKey = pszOwnerKey;
    }
    virtual HRESULT GetSelectedNodes(HierNodeList& rgNodes) const;

public: // IVsHierarchyEvent propagation
    HRESULT OnItemAdded(CHierNode *pNodeParent, CHierNode *pNodePrev, CHierNode *pNodeAdded) const;
    HRESULT OnItemDeleted(CHierNode *pNode) const;
    HRESULT OnPropertyChanged(CHierNode *pNode, VSHPROPID propid, DWORD flags) const;
    HRESULT OnInvalidateItems(CHierNode *pNode) const;
    HRESULT OnInvalidateIcon(HICON hIcon) const;

BEGIN_COM_MAP(CVsHierarchy)
    COM_INTERFACE_ENTRY(IVsHierarchy)       // derives from IUnknown
    COM_INTERFACE_ENTRY(IVsUIHierarchy)     // derives from IVsHierarchy
    COM_INTERFACE_ENTRY(IVsPersistHierarchyItem) // derives from IUnknown
    COM_INTERFACE_ENTRY(IOleCommandTarget)  // derives from IUnknown
    COM_INTERFACE_ENTRY(IVsHierarchyDropDataSource) // dervies from IUnknown
    COM_INTERFACE_ENTRY(IVsHierarchyDropDataTarget) // dervies from IUnknown
    COM_INTERFACE_ENTRY(ISupportErrorInfo)  // dervies from IUnknown
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(CVsHierarchy)

// IVsHierarchy
public:
    STDMETHOD(SetSite)(
            /* [in] */ IServiceProvider *pSP);

    STDMETHOD(GetSite)(
            /* [out] */ IServiceProvider **ppSP);

    STDMETHOD(QueryClose)(
            /* [out] */ BOOL *pfCanClose);

    STDMETHOD(Close)(void);

    STDMETHOD(GetGuidProperty)(
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHPROPID propid,
            /* [out] */ GUID *pguid);

    STDMETHOD(SetGuidProperty)(
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHPROPID propid,
            /* [in] */ REFGUID guid);

    virtual HRESULT GetProperty(    // not in interface, helper routine
            /* [in] */ CHierNode *pNode,
            /* [in] */ VSHPROPID propid,
            /* [out] */ VARIANT *pvar);

    STDMETHOD(GetProperty)(
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHPROPID propid,
            /* [out] */ VARIANT *pvar);

    virtual HRESULT SetProperty(    // not in interface, helper routine
            /* [in] */ CHierNode *pNode,
            /* [in] */ VSHPROPID propid,
            /* [in] */ const VARIANT& var);

    STDMETHOD(SetProperty)(
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHPROPID propid,
            /* [in] */ VARIANT var);

    STDMETHOD(GetNestedHierarchy)(
            /* [in] */ VSITEMID itemid,
            /* [in] */ REFIID riid,
            /* [out] */ void **ppHierarchyNested,
            /* [out] */ VSITEMID *pitemidNested);

    STDMETHOD(GetCanonicalName)(
            /* [in] */ VSITEMID itemid,
            /* [out] */ BSTR *ppszName);

    STDMETHOD(ParseCanonicalName)(
            /* [in] */ LPCOLESTR pszName,
            /* [out] */ VSITEMID *pitemid);

    STDMETHOD(Unused0)(void);

    STDMETHOD(AdviseHierarchyEvents)(
            /* [in] */ IVsHierarchyEvents *pEventSink,
            /* [out] */ VSCOOKIE *pdwCookie);

    STDMETHOD(UnadviseHierarchyEvents)(
            /* [in] */ VSCOOKIE dwCookie);

    STDMETHOD(Unused1)(void);
    STDMETHOD(Unused2)(void);
    STDMETHOD(Unused3)(void);
    STDMETHOD(Unused4)(void);

// General method. NOT part of IVsHierarhcy
    STDMETHOD(GetAutomationObject)(
            /* [out] */ IDispatch **ppdisp);

// IVsUIHierarchy
public:
    STDMETHOD(QueryStatusCommand)( 
            /* [in] */ VSITEMID itemid,
            /* [unique][in] */ const GUID __RPC_FAR *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [size_is][out][in] */ OLECMD __RPC_FAR prgCmds[  ],
            /* [unique][out][in] */ OLECMDTEXT __RPC_FAR *pCmdText);

    STDMETHOD(ExecCommand)( 
            /* [in] */ VSITEMID itemid,
            /* [unique][in] */ const GUID __RPC_FAR *pguidCmdGroup,
            /* [in] */ DWORD nCmdID,
            /* [in] */ DWORD nCmdexecopt,
            /* [unique][in] */  VARIANT __RPC_FAR *pvaIn,
            /* [unique][out][in] */ VARIANT __RPC_FAR *pvaOut);


// IVsPersistHierarchyItem
public:
    STDMETHOD(IsItemDirty)( 
        /* [in] */ VSITEMID vsid,
        /* [in] */ IUnknown __RPC_FAR *punkDocData,
        /* [out] */ BOOL __RPC_FAR *pfDirty);
    
    STDMETHOD(SaveItem)( 
        /* [in] */ VSSAVEFLAGS dwSave,
        /* [in] */ LPCOLESTR lpstrMkDocument,
        /* [in] */ VSITEMID vsid,
        /* [in] */ IUnknown __RPC_FAR *punkDocData,
        /* [out] */ BOOL __RPC_FAR *pfCanceled);

// IVsHierarchyDropDataSource
public:
    STDMETHOD(GetDropInfo)( // make pure after everyone implements
            /* [out] */ DWORD *pdwOKEffects,
            /* [out] */ IDataObject **ppDataObject,
            /* [out] */ IDropSource **pDropSource);
        
    STDMETHOD(OnDropNotify)( 
            /* [in] */ BOOL fDropped,
            /* [in] */ DWORD dwEffects);

// IVsHierarchyDropDataTarget
public:
    virtual HRESULT DragEnter(  // not in interface, helper routine
            /* [in] */ IDataObject *pDataObj);

    STDMETHOD(DragEnter)( 
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ VSITEMID itemid,
            /* [out] */ DWORD *pdwEffect);
        
    virtual HRESULT DragOver(       // not in interface, helper routine
            /* [in] */ DWORD grfKeyState,
            /* [in] */ CHierNode *pNode,
            /* [out] */ DWORD *pdwEffect);

    STDMETHOD(DragOver)(
            /* [in] */ DWORD grfKeyState,
            /* [in] */ VSITEMID itemid,
            /* [out] */ DWORD *pdwEffect);
        
    STDMETHOD(DragLeave)(void);
        
    virtual HRESULT Drop(       // not in interface, helper routine
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ CHierNode *pNode,
            /* [out] */ DWORD *pdwEffect);

    STDMETHOD(Drop)(
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ VSITEMID itemid,
            /* [out] */ DWORD *pdwEffect);

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
// Itemid conversion
    HRESULT VSITEMID2Node(const VSITEMID itemid, CHierNode **ppNode) const;
    HRESULT VSITEMID2Node(const VSITEMID itemid, HierNodeList& rgNodeList) const;

    // Virtuals called in response to VSHPROPID_FirstChild, VSHPROPID_GextNextSibling. Defaults
    // just call pNode's GetFirstChild()/GetNext() methods. Override to display the nodes differently
    virtual VSITEMID GetFirstDisplayableNode(CHierNode* pNode);
    virtual VSITEMID GetNextDisplayableNode(CHierNode* pNode);

    // Following function returns the previous node in the hierwindow. It is obviously dependant on 
    // the sorting way GetFirstDisplayableNode, GetNextDisplayable node are implemented. 
    virtual CHierNode* GetPrevDisplayableNode(CHierNode* pNode);

protected:  // protected methods
    // Override to handle in a particular way
    virtual HRESULT DisplayContextMenu(HierNodeList &rgSelection);

    // Override to handle Query status in a particular way
    virtual HRESULT QueryStatusSelection(
        const GUID *pguidCmdGroup,
        ULONG cCmds,
        OLECMD prgCmds[],
        OLECMDTEXT *pCmdText,
        HierNodeList &rgSelection,
        BOOL         bIsHierCmd);       // TRUE if cmd originated via CVSUiHierarchy::ExecCommand
    
    // Override to handle Exec in a particular way
    virtual HRESULT ExecSelection(
        const GUID *pguidCmdGroup,
        DWORD nCmdID,
        DWORD nCmdexecopt,
        VARIANT *pvaIn,
        VARIANT *pvaOut,
        HierNodeList &rgSelection,
        BOOL         bIsHierCmd);       // TRUE if cmd originated via CVSUiHierarchy::ExecCommand

    // MUST be overriden to handle the item Rename aspect of a SaveAs operation via a call to 
    // IVsPersistHierarchyItem::SaveItem.
    // If a SaveAs occurred the hierarchy needs to update to the fact that its item's name has changed.
    // This may include the following:
    //      1. call RenameDocument on the RunningDocumentTable
    //      2. update the full path name for the item in the hierarchy
    //      3. a directory-based project may need to transfer the open editor to the
    //         MiscFiles project if the new file is saved outside of the project directory.
    //         This is accomplished by calling IVsExternalFilesManager::TransferDocument
    // This work can not be done by CVsHierarchy::SaveItem; this must be done in a 
    // derived subclass implementation of OnHandleSaveItemRename. Alternatively, SaveItem
    // itself can be overriden.
    virtual HRESULT OnHandleSaveItemRename(VSITEMID itemid, IUnknown *punkDocData, LPCOLESTR pszMkDocumentNew)
                        { ASSERT(FALSE); return E_UNEXPECTED; } // this method must be overriden 

protected:  // protected variables
    HIMAGELIST m_hImageList;

    CHierContainer *m_pRootNode;

    // Hierarchy event advises
    CVsAdviseList<IVsHierarchyEvents>   m_hierEventAdvises;

    BOOL   m_fHierClosed;

    // Properties to support being a used as a nested hierarchy
    IUnknown *m_pParentHierarchy;
    VSITEMID m_dwParentHierarchyItemid;

    // support VSHPROPID_OwnerKey
    CComBSTR    m_bstrOwnerKey;

    static BOOL g_bStartedDrag;

    static BOOL g_bInContextMenu;   // is OK to support Cut/Copy,Paste/Rename/etc.
};

//-----------------------------------------------------------------------------
// reduce a selection list such that a node doesn't have a parent that is
// also in the list.  returns count of items remaining in list
//-----------------------------------------------------------------------------
DWORD UtilReduceSelection(HierNodeList &rgSelection);

#endif __HU_ARCHY_H__
