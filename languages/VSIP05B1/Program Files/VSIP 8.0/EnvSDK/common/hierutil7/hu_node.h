//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// File: hu_node.h
// Area: IVsHierarchy Utilities implementation
//
// Contents:
//  CHierNode definitions
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __HU_NODE_H__
#define __HU_NODE_H__

#ifndef __TEMPL_H__
#include "templ.h"
#endif

#include <context.h>

// forward declarations
class CHierContainer;
class CVsHierarchy;
enum  ICON_TYPE;

// the framework classes reserves 8 bits for itself leaving 24 open to user derived 
// classes. Note that CHierNode has no type info since every node derives from it. Your "type" 
// should be defined as follows: enum {Type_MyClass = (Type_FirstUser << 1) | Type_CMyBaseClass}
enum {
    Type_CHierContainer         = (1 << 0), 
    Type_CHierNestedContainer   = (1 << 1), 
    Type_FirstUser              = (1 << 8)
};

// Helper to faciliate implementing RTTI. This should be placed in the public
// section of your class definition. 
#define IMPLEMENT_RTTI(classname) \
    virtual UINT GetKindOf() const {return Type_##classname;}

// standard first call in a CHierNode derived QueryStatus
// the second if check is to workaround shell selection bug after a node
// has been removed from the tree
#define QUERY_STATUS_CHECK \
        ASSERT(cCmds == 1); \
        if(NULL == pguidCmdGroup || IsZombie()) \
        { \
            return OLECMDERR_E_UNKNOWNGROUP; \
        }

const UINT IDMX_NULLMENU = 0;

typedef CVxTypedPtrList<CVxPtrList, IVsWindowFrame *> OpenDocumentList;
// Holds addref'd pointers to IVsTaskItems.
typedef CVxTypedPtrArray<CVxPtrArray, IVsTaskItem*> CIVsTaskItemArray;

//---------------------------------------------------------------------------
// Name: CHierNode
//
// Description:
//  Base node class for every object in a hierarchy. Implements the idea of
//  a node that has a parent, but no children.
//
//---------------------------------------------------------------------------
class ATL_NO_VTABLE CHierNode :
    public CComObjectRootEx<CComSingleThreadModel>, // explict
    public ISupportErrorInfo                            // derives from IUnknown
{
protected:
                        CHierNode(void);
    virtual             ~CHierNode(void);   

public:
    // IsKindOf checking
    virtual UINT GetKindOf() const = 0 {return 0;}
    BOOL IsKindOf(UINT hKind) const
    { return (hKind == (hKind & GetKindOf())); }

    // return a CHierNode typecasted to a VSITEMID or VISTEMID_ROOT
    // Override in each derived class that can also be a VSITEMID_ROOT
    virtual VSITEMID GetVsItemID(void) const;

    // return the itemid of the first child or VSITEMID_NIL
    virtual VSITEMID GetFirstChild(BOOL fDisplayOnly = TRUE);

    // Used by the hierarchy in response to VSHPROPID_FirstChild/VSHPROPID_NextSibling. These
    // properties are spec'd to only return member items (visible or not)
    virtual VSITEMID GetFirstMemberChild();
    VSITEMID GetNextMemberSibling() const;

    // is this node expandable in the shell?
    // should this node be auto expanded in the shell?
    virtual BOOL Expandable() const;
    virtual BOOL ExpandByDefault() const;

    // is this node a container in the shell? it may be a container
    // and still not be expandable if all child items are hidden.
    virtual BOOL IsContainer() const;

    // traverses to root node via parents
    // the root node is expected to return the associated CVsHierarchy
    virtual CVsHierarchy* GetCVsHierarchy(void) const;

    virtual HRESULT GetNestedHierarchy(REFIID riid, 
                                        void **ppVsHierarchy, 
                                        VSITEMID *pitemidNested);

    // Property functions
    virtual HRESULT GetEditLabel(BSTR *ppEditLabel); // VSHPROPID_EditLabel
    virtual HRESULT SetEditLabel(BSTR   pEditLabel); // VSHPROPID_EditLabel

    virtual HRESULT GetProperty(VSHPROPID propid, VARIANT* pvar);
    virtual HRESULT SetProperty(VSHPROPID propid, const VARIANT&  var);
    virtual HRESULT GetGuidProperty(VSHPROPID propid, GUID* pGuid) const;
    
    virtual HRESULT DisplayContextMenu();
    virtual UINT GetContextMenu(void) { return IDMX_NULLMENU; }
    virtual HRESULT ShowContextMenu(UINT iCntxtMenuID, REFGUID GroupGuid, IOleCommandTarget* pIOleCmdTarg);

    // all nodes which neeed to handle these functions should over-ride them
    virtual const GUID* PGuidGetType(void) const;
    virtual UINT GetIconIndex(ICON_TYPE) const;
    virtual HRESULT GetCanonicalName(BSTR* ppszName) const;
    virtual HRESULT DoDefaultAction();

    // These three are to allow you to do something in response to the label
    // edit.  They just tell you the change in state, the changing of the name of your
    // item will be handled through the SetProperty command. Note they track the
    // following shell commands to our hierarchy:
    //      UIHWCMDID_StartLabelEdit
    //      UIHWCMDID_CommitLabelEdit
    //      UIHWCMDID_CancelLabelEdit
    // Defaults do nothing
    virtual HRESULT OnStartLabelEdit();
    virtual HRESULT OnCommitLabelEdit();
    virtual HRESULT OnCancelLabelEdit();

    // Task list support. Allows adding tasks to the passed in task array. Default does nothing
    virtual HRESULT GetTasks(CIVsTaskItemArray *pTaskItemArray){return S_OK;};

    // CHierNode Properties
    const CString& GetName(void) const
    {
        return m_strName;
    }

    // CHierNode Properties
    HRESULT GetDisplayCaption(BSTR* pbstrCaption);
    virtual HRESULT GetDisplayCaption(CString& strCaption);

    // ANSI, UNICODE, with shell notifications if pCVsHierarchy is non-NULL
    void SetName(LPCSTR pszNewName, CVsHierarchy *pCVsHierarchy=NULL);
    void SetName(LPCWSTR pszNewName, CVsHierarchy *pCVsHierarchy=NULL);
    void SetName(const CString& strNewName, CVsHierarchy *pCVsHierarchy=NULL);

    CHierContainer* GetParent(void) const
    {   // VSHPROPID_Parent
        return m_pNodeParent;
    }
    void SetParent(CHierContainer *pNode)
    {
        m_pNodeParent = pNode;
    }
    CHierNode* GetNext(BOOL fDisplayOnly = TRUE) const;
    
    void SetNext(CHierNode *pHierNode)
    {
        m_pNodeNext = pHierNode;
    }
    CHierNode* GetPrev(BOOL fDisplayOnly = TRUE) const;

    // traverse the parent nodes and return node whose parent is NULL
    CHierNode* GetRootNode(void) const;

    // is the given node an ancestor of this node
    BOOL HasAncestor(const CHierNode *pNode) const;

    HRESULT ExtExpand(EXPANDFLAGS expandflags, REFGUID rguidPersistenceSlot = GUID_SolutionExplorer) const;

    //Is this node a zombie, with no Root node in it's hierarchy
    BOOL IsZombie(void) const;

    // Static helper which is used to detect stale itemid's for nodes which have
    // gone away (different than the zombie case).
    static BOOL IsValidCHierNode(VSITEMID itemid);

    // Updates UI
    void    ReDraw(BOOL bUpdateIcon = TRUE, BOOL bUpdateStateIcon = TRUE, BOOL bUpdateText = FALSE);

    virtual HRESULT IsDocumentOpen(OpenDocumentList *rgOpenDocuments = NULL) { return S_FALSE; }
    virtual HRESULT CloseDocuments(BOOL bPromptToSave = FALSE);
    virtual HRESULT SaveDocument(BOOL bPromptToSave = FALSE);

    // VSHPROPID_UserContext
    virtual HRESULT GetUserContext(IVsUserContext **ppUserCtx);

    virtual DWORD   GetDisplayOrder() const {return 0;};

// IOleCommandTarget
public:
    STDMETHOD(QueryStatus)( 
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [out][in][size_is] */ OLECMD prgCmds[],
            /* [unique][out][in] */ OLECMDTEXT *pCmdText)
    {
        //ATLTRACENOTIMPL(_T("CHierNode::IOleCommandTarget::QueryStatus"));
        return OLECMDERR_E_NOTSUPPORTED;
    }
        
    STDMETHOD(Exec)( 
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ DWORD nCmdID,
            /* [in] */ DWORD nCmdexecopt,
            /* [unique][in] */ VARIANT *pvaIn,
            /* [unique][out][in] */ VARIANT *pvaOut)
    {
        //ATLTRACENOTIMPL(_T("CHierNode::IOleCommandTarget::Exec"));
        return OLECMDERR_E_NOTSUPPORTED;
    }
// Bit state functions
public:
    void SetIsDisplayable(BOOL bValue) { SetBits(ST_Displayable, bValue); }
    BOOL IsDisplayable() const { return IsSet(ST_Displayable);}
    void SetIsOpen(BOOL bValue) { SetBits(ST_IsOpen, bValue); }
    BOOL IsOpen() const { return IsSet(ST_IsOpen);}
    void SetIsMemberItem(BOOL bValue) { SetBits(ST_IsMemberItem, bValue); }
    BOOL IsMemberItem() const { return IsSet(ST_IsMemberItem);}

protected:
    CHierContainer* m_pNodeParent;
    CHierNode*      m_pNodeNext;    // to form a singly-linked list
    CString         m_strName;      // this node's name

    DWORD       m_grfStateFlags;        // ChildrenEnumerated, etc
    enum    // m_grfStateFlags
    {
        ST_ChildrenEnumerated = (1<<0),
        ST_IsOpen             = (1<<1), // File is open in an editor. Note user controlled. does not check
        ST_Displayable        = (1<<2),
        ST_SortedList         = (1<<3), // Containers only. True if a sorted by alpha list.
        ST_IsMemberItem       = (1<<4), // TRUE if this node is a member of the project
        ST_FirstUserFlag      = (1<<8)  // Derived classes are free to use these upper 24 bits
    };
    // m_grfStateFlags bit helpers
    BOOL    IsSet(int bits) const {return (m_grfStateFlags & bits)? TRUE : FALSE;} // Returns true if bit (or any bit in state is set)
    void    SetBits(int bits, BOOL bValue);                  // Sets/resets bit

#define DEFAULT_NODE_FLAGS (ST_Displayable | ST_IsMemberItem)
    
}; // CHierNode

#endif  // __HU_NODE_H__
