//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// File: hu_ctnr.h
// Area: Namespace utilities
// Contents: CHierContainer class
//  Description: Derived from CHierNode class, it is a container
//  (ie. non-leaf) element in a hierarchy.
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __HU_CTNR_H__
#define __HU_CTNR_H__

#ifndef  __HU_NODE_H__
#include "hu_node.h"
#endif

#include "hu_archy.h"

//-----------------------------------------------------------------------------
// Name: CHierContainer
//
// Description:
//  Class for every object in a hierarchy that has children. Implements the
//  idea of a node that has children, relies on CHierNode to take care of
//  parent/sibling info.
//
//-----------------------------------------------------------------------------
class ATL_NO_VTABLE CHierContainer :
    public CHierNode
{
protected:
             CHierContainer(void);
    virtual ~CHierContainer(void);

public: 
    // RTTI implementation
    IMPLEMENT_RTTI(CHierContainer)

    // CHierNode overrides
    virtual BOOL Expandable() const;
    virtual BOOL ExpandByDefault() const;

    virtual VSITEMID GetFirstChild(BOOL fDisplayOnly = TRUE);

    // Used by the hierarchy in response to VSHPROPID_FirstChild/VSHPROPID_NextSibling. These
    // properties are spec'd to only return member items (visible or not)
    virtual VSITEMID GetFirstMemberChild();

public: // CHierContainer

    // CHierContainer virtual methods
    virtual HRESULT     Refresh(CVsHierarchy *pCVsHierarchy);
    virtual HRESULT     EnumerateChildren(void) = 0;

    virtual CHierNode*  GetHeadEx(BOOL fDisplayOnly = TRUE);

    CHierNode* GetHead(BOOL fDisplayOnly = TRUE) const;
    
    CHierNode* GetTail(void) const
    {
        return m_pTailNode;
    }
    long GetCount(BOOL fDisplayOnly = TRUE) const;  // return number of children

    CHierNode* GetPrevChildOf(const CHierNode* pCurrent, BOOL fDisplayOnly = TRUE) const;

    // Override to get custom add behavior suchas keeping the list sorted.
    // If not sorted list, itcalls AddTail(), else calls AddSorted();
    virtual void Add(CHierNode *const pNode);

    virtual void    AddAfter(CHierNode* const pCurrNode, CHierNode* const pNewNode);
    virtual void    AddHead(CHierNode *const pNode);
    virtual void    AddTail(CHierNode *const pNode);
    virtual HRESULT Remove(CHierNode* pNode);
    virtual HRESULT Delete(CHierNode* pNode, CVsHierarchy *pCVsHierarchy);
    virtual void    DeleteAll(CVsHierarchy *pCVsHierarchy);
    virtual HRESULT CloseDocuments(BOOL bPromptToSave = FALSE);

    // returns the node from child list who's GetDisplayName() == pszName
    CHierNode *GetNodeByName(LPCTSTR pszName, BOOL fDisplayOnly = TRUE);
    CHierNode *GetNodeByIndex(DWORD dwIndex, BOOL fDisplayOnly = TRUE);
    CHierNode *GetNodeByVariant(const VARIANT *pvar, BOOL fDisplayOnly = TRUE);

    // Allows walking of nodes based on the IsKindOf node type.
    UINT        GetNodeOfTypeCount(UINT nodeType, BOOL fDisplayOnly = TRUE);
    CHierNode*  GetFirstNodeOfType(UINT nodeType, BOOL fDisplayOnly = TRUE);
    CHierNode*  GetNextNodeOfType(UINT nodeType, CHierNode* pPrevNode, BOOL fDisplayOnly = TRUE);

    virtual HRESULT     GetConfigProvider(VARIANT *pvar) { return E_NOTIMPL; }

    // Finds node 
    virtual CHierNode* GetMatchingNode(LPCTSTR pszRelPath, BOOL fDisplayOnly = TRUE);


    // Sorted list info
    void SetIsSortedList(BOOL bValue) { SetBits(ST_SortedList, bValue); }
    BOOL IsSortedList() const { return (m_grfStateFlags & ST_SortedList);}

    BOOL HaveChildrenBeenEvaluated(void) const
    {
        return (m_grfStateFlags & ST_ChildrenEnumerated);
    }

    void SetChildrenBeenEvaluated(BOOL fChildrenBeenEvaluated)
    {
        if (fChildrenBeenEvaluated)
        {
            m_grfStateFlags |= ST_ChildrenEnumerated;
        }
        else
        {
            m_grfStateFlags &= ~ST_ChildrenEnumerated;
        }
    }

protected:
    void NotifyHierarchyOfAdd(CHierNode* pNodePrev, CHierNode* pNodeAdded)
    {
        if (HaveChildrenBeenEvaluated() && pNodeAdded->IsDisplayable())
        {
            GetCVsHierarchy()->OnItemAdded(this, pNodePrev, pNodeAdded);
        }
    }
    // Used by sorted lists.
    virtual void AddSorted(CHierNode* const pStartingNode, CHierNode* const pNewNode);

    CHierNode*  m_pHeadNode;
    CHierNode*  m_pTailNode;
};

#endif // __HU_CTNR_H__

