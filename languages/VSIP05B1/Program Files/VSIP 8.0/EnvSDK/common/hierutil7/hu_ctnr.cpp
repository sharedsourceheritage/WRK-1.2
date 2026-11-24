//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//
// File: hu_ctnr.cpp
// Area: IHierarchy Utilities implementation
//
// Contents:
//---------------------------------------------------------------------------

#include "hu_pch.h"

#include "hu_ctnr.h"
#ifndef __AFX_H__           // If not use MFC
#include "mfcmisc.h"
#endif  // __AFX_H__
#include "hu_archy.h"
#include "hu_util.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-----------------------------------------------------------------------------
// CHierContainer Constructor, initializes base class CHierNode and class vars
//-----------------------------------------------------------------------------
CHierContainer::CHierContainer(void) :
    m_pHeadNode(NULL),
    m_pTailNode(NULL)
{
}

//-----------------------------------------------------------------------------
//  CHierContainer Destructor, DELETES all children
//-----------------------------------------------------------------------------
CHierContainer::~CHierContainer(void)
{
    DeleteAll(NULL);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
VSITEMID CHierContainer::GetFirstChild(BOOL fDisplayOnly)
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return VSITEMID_NIL;

    return (NULL != GetHeadEx(fDisplayOnly)) ? GetHead(fDisplayOnly)->GetVsItemID() : VSITEMID_NIL;
}

//---------------------------------------------------------------------------
// VSHPROPID_NextChild
//---------------------------------------------------------------------------
VSITEMID CHierContainer::GetFirstMemberChild()
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return VSITEMID_NIL;

    CHierNode *pNode = GetHeadEx(FALSE);
    while(pNode && !pNode->IsMemberItem())
        pNode = pNode->GetNext(FALSE);

    return pNode? pNode->GetVsItemID() : VSITEMID_NIL;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CHierNode* CHierContainer::GetHead(BOOL fDisplayOnly) const
{
    CHierNode *pNode;
    
    if (fDisplayOnly)
    {
        pNode = m_pHeadNode;
        if ((pNode) && (!pNode->IsDisplayable()))
            pNode = pNode->GetNext();
            
        return pNode;
    }
    else
        return m_pHeadNode;
}

//-----------------------------------------------------------------------------
// Virtual function that all containers must over-ride to show they are
//  actual containers of objects, not just leaf-nodes
//-----------------------------------------------------------------------------
CHierNode* CHierContainer::GetHeadEx(BOOL fDisplayOnly)
{
    if (!HaveChildrenBeenEvaluated())
    {
        CWaitCursor cursWait;
        HRESULT hr = EnumerateChildren();
        if (SUCCEEDED(hr))
        {
            m_grfStateFlags |= ST_ChildrenEnumerated;
        }
        else
        {   //  Failed to enumerate children. Just return that we don't have any. 
            return NULL;
        }
    }
    return GetHead(fDisplayOnly);
}

//---------------------------------------------------------------------------
// is this node expandable? VSHPROPID_Expandable
//---------------------------------------------------------------------------
BOOL CHierContainer::Expandable() const
{
    return TRUE;
}

//---------------------------------------------------------------------------
//should this node be autoexpanded in the shell? VSHPROPID_ExpandByDefault
//---------------------------------------------------------------------------
BOOL CHierContainer::ExpandByDefault() const
{
    return FALSE;
}

//-----------------------------------------------------------------------------
//  This method instructs the node to refresh its children. (which in our
//  case will lose all the children, and then set a flag to FALSE, indicating
//  that the next time someone asks for our children, we have to enumerate
//  them again).
//-----------------------------------------------------------------------------
HRESULT CHierContainer::Refresh(CVsHierarchy *pCVsHierarchy)
{
    DeleteAll(pCVsHierarchy);
    m_grfStateFlags &= ~ST_ChildrenEnumerated;

    return S_OK;
}

//-----------------------------------------------------------------------------
// Loops over all this object's children, counting them and returns that count
//-----------------------------------------------------------------------------
long CHierContainer::GetCount(BOOL fDisplayOnly) const
{
    long n = 0;
    CHierNode *pNext = GetHead(fDisplayOnly);

    while (pNext != NULL)
    {
        pNext = pNext->GetNext(fDisplayOnly);
        ++n;
    }
    return n;
}

//-----------------------------------------------------------------------------
// Returns the previous child, given the current child. (or NULL)
//-----------------------------------------------------------------------------
CHierNode* CHierContainer::GetPrevChildOf(const CHierNode* pCurrent, BOOL fDisplayOnly) const
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return NULL;

    ASSERT(m_pHeadNode != NULL);
    if (pCurrent == m_pHeadNode)
    {
        return NULL;
    }
    CHierNode* pNodePrev = m_pHeadNode;
    while (pNodePrev != NULL && pNodePrev->GetNext(fDisplayOnly) != pCurrent)
    {
        pNodePrev = pNodePrev->GetNext(fDisplayOnly);
    }

    // If the node we end up with isn't displayable, then there are not
    // any displayble nodes...
    if (pNodePrev && (fDisplayOnly && !pNodePrev->IsDisplayable()))
        pNodePrev = NULL;

    return pNodePrev;
}

//-----------------------------------------------------------------------------
// Adds pNewNode after pCurrNode
// If pCurrNode is NULL, adds NewNode as the head if an unsorted list, else 
// pCurrNode is used as a hint to the addsorted. 
//-----------------------------------------------------------------------------
void CHierContainer::AddAfter(CHierNode* const pCurrNode, CHierNode* const pNewNode)
{
    if(IsSortedList())
    {
        AddSorted(pCurrNode, pNewNode);
    }
    else
    {
        if (pCurrNode)
        {
            pNewNode->SetNext(pCurrNode->GetNext(FALSE));
            pNewNode->SetParent(pCurrNode->GetParent());
            pCurrNode->SetNext(pNewNode);

            if (pCurrNode == m_pTailNode)
            {
                m_pTailNode = pNewNode;
            }

            // Finally, inform the hierarchy.
            if(HaveChildrenBeenEvaluated() && pNewNode->IsDisplayable())
            {   // Need to get the previous displayable node based on the hierarchies sorting, not the
                // order they are linked together.
                GetCVsHierarchy()->OnItemAdded(this, GetCVsHierarchy()->GetPrevDisplayableNode(pNewNode), pNewNode);
            }
        }
        else
        {
            AddHead(pNewNode);
        }
    }
}

//-----------------------------------------------------------------------------
// Adds the given node to the head of this containers list.
//-----------------------------------------------------------------------------
void CHierContainer::AddHead(CHierNode *const pNode)
{
    ASSERT(pNode != NULL);

    pNode->SetParent(this);
    pNode->SetNext(m_pHeadNode);

    m_pHeadNode = pNode;
    if (m_pTailNode == NULL)
    {
        m_pTailNode = pNode;
    }

    NotifyHierarchyOfAdd(NULL, pNode);
}

//-----------------------------------------------------------------------------
//  Adds the given node to the tail of this containers list.
//-----------------------------------------------------------------------------
void CHierContainer::AddTail(CHierNode *const pNode)
{
    ASSERT(pNode != NULL);

    pNode->SetParent(this);
    pNode->SetNext(NULL);

    if(m_pTailNode != NULL)
    {
        ASSERT(m_pHeadNode != NULL);
        m_pTailNode->SetNext(pNode);
        m_pTailNode = pNode;
    }
    else
    {
        ASSERT(m_pHeadNode == NULL);
        m_pHeadNode = m_pTailNode = pNode;
    }
    // Finally, inform the hierarchy.
    if(HaveChildrenBeenEvaluated() && pNode->IsDisplayable())
    {   // Need to get the previous displayable node based on the hierarchies sorting.
        GetCVsHierarchy()->OnItemAdded(this, GetCVsHierarchy()->GetPrevDisplayableNode(pNode), pNode);
    }
}

//-----------------------------------------------------------------------------
//  Generic Add function calls AddTail. Override to get custom add behavior.
//-----------------------------------------------------------------------------
void CHierContainer::Add(CHierNode *const pNode)
{
    if(IsSortedList())
        AddSorted(NULL, pNode);
    else
        AddTail(pNode);
}

//-----------------------------------------------------------------------------
// Adds file pNoded after file pStartingNode. If pStartingNode is NULL, it starts
// its search from the beginning of the list.
//-----------------------------------------------------------------------------
void CHierContainer::AddSorted(CHierNode* const pStartingNode, CHierNode *const pNode)
{
    pNode->SetParent(this);
    pNode->SetNext(NULL);
    // Search for insertion point by doing an alpha comparison amongst the nodes
    // If we are passed a start node, use it as the previous, and its ptr as the curNode,
    // otherwise just start at the beginning.
    CHierNode* pCurNode = pStartingNode? pStartingNode->GetNext(FALSE) : m_pHeadNode;
    CHierNode* pPrevNode = pStartingNode;
#ifdef _DEBUG
    // Validate starting node has same parent, and that it really comes before this node
    if(pStartingNode)
        ASSERT(pStartingNode->GetParent() == this && lstrcmpi(pStartingNode->GetName(), pNode->GetName()) < 0);
#endif
    // Optimization to help project loads where the items are being added sorted, and there aren't really
    // any duplicates. If no startingNode is specified, do a quick check against the tail to see if it belongs there
    if(!pStartingNode && m_pTailNode)
    {
        if(lstrcmpi(m_pTailNode->GetName(), pNode->GetName()) < 0)
        {
            AddTail(pNode);
            return;
        }
    }

    while(pCurNode)
    {   // ASSERT that there are not two items with the same name since the sorting relies on this.
        ASSERT(lstrcmpi(pCurNode->GetName(), pNode->GetName()) != 0);
        if(lstrcmpi(pCurNode->GetName(), pNode->GetName()) > 0)
        {   // Insert before this folder
            if(pPrevNode)
            {   // Inserting somewhere in the middle
                pPrevNode->SetNext(pNode);
            }
            else
            {   // Inserting at the head
                m_pHeadNode = pNode;
            }
            // Update who the just added node points to, we're done.
            pNode->SetNext(pCurNode);
            break;
        }
        pPrevNode = pCurNode;
        pCurNode = pCurNode->GetNext(FALSE);

    }
    // Past the end of the list, so this node becomes the new tail and maybe the new head too
    if(pCurNode == NULL)
    {
        if(m_pHeadNode == NULL)
        {
            ASSERT(m_pTailNode == NULL && pPrevNode == NULL);
            m_pHeadNode = pNode;
            m_pTailNode = pNode;
        }
        else
        {
            ASSERT(m_pTailNode && pPrevNode == m_pTailNode);

            if(!m_pTailNode || pPrevNode != m_pTailNode)
                return;

            m_pTailNode->SetNext(pNode);
            m_pTailNode = pNode;
        }
    }

    // Finally, inform the hierarchy.
    if(HaveChildrenBeenEvaluated() && pNode->IsDisplayable())
    {
        // Need to get the previous displayable node based on the hierarchies sorting.
        pPrevNode = GetCVsHierarchy()->GetPrevDisplayableNode(pNode);
        GetCVsHierarchy()->OnItemAdded(this, pPrevNode, pNode);
    }
}
//-----------------------------------------------------------------------------
//  Remove the given node from this container, does not delete the node
//  Return Values:
//      S_OK - success
//      E_FAIL - The node is not in the list of children (also ASSERTs)
//-----------------------------------------------------------------------------
HRESULT CHierContainer::Remove(CHierNode *pNode)
{
    ASSERT(pNode != NULL);

    CHierNode *pNodeCur  = m_pHeadNode; // The node to be removed
    CHierNode *pNodePrev = NULL;        // fix this node's next pointer

    while (pNode != pNodeCur && pNodeCur != NULL)
    {   // find pNode in list of children
        pNodePrev = pNodeCur;
        pNodeCur = pNodeCur->GetNext(FALSE);
    }
    // ASSERT if caller gave a node not in the list
    ASSERT(pNodeCur != NULL);

    if (pNodeCur != NULL)
    {   // Then we found the node in the list. (this is a good thing!)
        if (pNodeCur == m_pHeadNode)
        {   // pNode is the HeadNode
            ASSERT(pNode == m_pHeadNode);
            m_pHeadNode = pNode->GetNext(FALSE);
            if (m_pHeadNode == NULL)
            {   // single child case
                m_pTailNode = NULL;
            }
        }
        else if (pNodeCur == m_pTailNode)
        {   // We are removing the last node.
            m_pTailNode = pNodePrev;
            pNodePrev->SetNext(NULL);
        }
        else
        {   // We are just removing a node in the middle.
            pNodePrev->SetNext(pNode->GetNext(FALSE));
        }

        pNode->SetParent(NULL);
        pNode->SetNext(NULL);
        return S_OK;
    }
    return E_FAIL;
}

//-----------------------------------------------------------------------------
//  This method removes a child from the container and deletes it.
//  Return Values:
//      S_OK - successfully removed & deleted node
//      E_FAIL - Remove from the list failed. It probably ASSERTed too.
//-----------------------------------------------------------------------------
HRESULT CHierContainer::Delete(CHierNode *pNode, CVsHierarchy *pCVsHierarchy)
{   
    ASSERT(NULL != pNode);

    HRESULT hr;
    if (NULL != pCVsHierarchy)
    {
        hr = pCVsHierarchy->OnItemDeleted(pNode);
        ASSERT(SUCCEEDED(hr));
    }
    hr = Remove(pNode);
    if (SUCCEEDED(hr))
    {   // remove item from hierarchy (and its selection) before release
        pNode->Release();
    }
    return hr;
}

//-----------------------------------------------------------------------------
// This method removes all children from the container and destroys them.
//-----------------------------------------------------------------------------
void CHierContainer::DeleteAll(CVsHierarchy *pCVsHierarchy)
{
    while (GetHead(FALSE) != NULL)
    {
        HRESULT hr = Delete(GetHead(FALSE), pCVsHierarchy);
        ASSERT(SUCCEEDED(hr));
        hr;
    }
}

//-----------------------------------------------------------------------------
// Returns the number of nodes of type nodeType. 
//-----------------------------------------------------------------------------
UINT CHierContainer::GetNodeOfTypeCount(UINT nodeType, BOOL fDisplayOnly /*=TRUE*/)
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return 0;

    UINT i = 0;
    CHierNode* pNode = GetHead(fDisplayOnly);
    while(pNode)
    {
        if(pNode->IsKindOf(nodeType))
            i++;
        pNode = pNode->GetNext(fDisplayOnly);
    }
    return i;
}

//-----------------------------------------------------------------------------
// Returns the first folder or NULL if none.
//-----------------------------------------------------------------------------
CHierNode* CHierContainer::GetFirstNodeOfType(UINT nodeType, BOOL fDisplayOnly /*=TRUE*/)
{
	if (IsZombie())
		return NULL;

    CHierNode* pNode = GetHead(fDisplayOnly);
    while(pNode)
    {
        if(pNode->IsKindOf(nodeType))
            break;
        pNode = pNode->GetNext(fDisplayOnly);
    }
    
    return pNode;
}

//-----------------------------------------------------------------------------
// Returns the next folder or NULL if no more
//-----------------------------------------------------------------------------
CHierNode* CHierContainer::GetNextNodeOfType(UINT nodeType, CHierNode* pPrevNode, BOOL fDisplayOnly /*=TRUE*/)
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return NULL;

    ASSERT(pPrevNode && pPrevNode->IsKindOf(nodeType) && pPrevNode->GetParent() == this);
    CHierNode* pNode = pPrevNode->GetNext(fDisplayOnly);
    while(pNode && !pNode->IsKindOf(nodeType))
    {
        pNode = pNode->GetNext(fDisplayOnly);
    }
    return pNode;
}


//-----------------------------------------------------------------------------
// Searches the node list looking for a node which matches strRelPath, where 
// strPath is relative to this node. The path can be a url path or a file path.
// Returns the node or NULL. Basically, any string with aa \ or / used to 
// distinguish the levels.
//-----------------------------------------------------------------------------
CHierNode* CHierContainer::GetMatchingNode(LPCTSTR pszRelPath, BOOL fDisplayOnly)
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return NULL;

    // Dupe string (Gets modified by strtok!)
    // removing the project node part (root path part)
    DWORD dwLength = (DWORD)((_tcslen(pszRelPath)+1) * sizeof(TCHAR));
    TCHAR* pBuff = (TCHAR *)_alloca(dwLength);
    memcpy(pBuff, pszRelPath, dwLength);

    // Start at the top
    CHierContainer *pCurNode = this;
    
    TCHAR* pNextToken = _tcstok( pBuff, _T("\\/"));
    while (pNextToken != NULL)
    {
        ASSERT(pCurNode->IsKindOf(Type_CHierContainer));

        // Look for match for this token at this level
        pCurNode = static_cast<CHierContainer*>(pCurNode->GetNodeByName(pNextToken, fDisplayOnly));

        // Do next if found
        if (pCurNode != NULL)
        {
            pNextToken = _tcstok(NULL, _T("\\/"));

            // If the found node is not a container, pNextToken had better be NULL.
            // Otherwise we have an error condition and we just return null.
            if(!pCurNode->IsKindOf(Type_CHierContainer) && pNextToken != NULL)
            {   // Error.
                pCurNode = NULL;
                break;
            }
        }
        else 
        {
            break;
        }
    }
    return pCurNode;
}
//-----------------------------------------------------------------------------
// returns the node from child list who's GetName() == pszName
//-----------------------------------------------------------------------------
CHierNode* CHierContainer::GetNodeByName(LPCTSTR pszName, BOOL fDisplayOnly)
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return NULL;

    ASSERT(NULL != pszName);
    int val;
    // Quick check for sorted lists to see if pszName is after the last item. If
    // so we can bail early.
    if(IsSortedList() && m_pTailNode && (!fDisplayOnly || m_pTailNode->IsDisplayable()))
    {   
        val = lstrcmpi(m_pTailNode->GetName(), pszName);
        if( val < 0)
            return NULL;
        else if(val == 0)
            return m_pTailNode;
    }
    CHierNode* pNode = GetHeadEx(fDisplayOnly);
    for (; pNode != NULL; pNode = pNode->GetNext(fDisplayOnly))
    {
        val = lstrcmpi(pNode->GetName(), pszName);
        if(val == 0)
            return pNode;
        else if(val > 0 && IsSortedList())  // Optimization for sorted lists
            break;
    }
    return NULL;
}

//-----------------------------------------------------------------------------
// returns the node from child list who's the dwIndexth child
// 0-based indicies
//-----------------------------------------------------------------------------
CHierNode* CHierContainer::GetNodeByIndex(DWORD dwIndex,BOOL fDisplayOnly)
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return NULL;

    CHierNode* pNode = GetHeadEx(fDisplayOnly);
    while (pNode != NULL && dwIndex--)
    {
        pNode = pNode->GetNext(fDisplayOnly);
    }
    return pNode;
}

//-----------------------------------------------------------------------------
// returns the node from the child list who matchs the variant information
// 1-based indicies
//-----------------------------------------------------------------------------
CHierNode* CHierContainer::GetNodeByVariant(const VARIANT *pvar, BOOL fDisplayOnly)
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return NULL;

    ASSERT(NULL != pvar);
    CHierNode *pNode = NULL;
    LONG dwIndex = 0;
    BSTR bstrIndex = NULL;
    Variant2Value(*pvar, dwIndex, bstrIndex);

    if (0 < dwIndex)
    {
        pNode = GetNodeByIndex(dwIndex - 1, fDisplayOnly);
    }
    else if (::SysStringLen(bstrIndex))
    {
        USES_CONVERSION;
        pNode = GetNodeByName(W2T(bstrIndex), fDisplayOnly);
    }
    return pNode;
}

//-----------------------------------------------------------------------------
// Close open document for node
//-----------------------------------------------------------------------------
HRESULT CHierContainer::CloseDocuments(BOOL bPromptToSave /*=FALSE*/)
{
	ASSERT(!IsZombie());
	if (IsZombie())
		return NULL;

    CHierNode* pNode = static_cast<CHierNode *>(GetHead(FALSE /*bDisplayOnly*/));
    HRESULT hr = S_OK;
    while(pNode && SUCCEEDED(hr))
    {
        hr = pNode->CloseDocuments(bPromptToSave);
        pNode = static_cast<CHierNode *>(pNode->GetNext());
    }
    
    if (SUCCEEDED(hr))
    {
        hr = CHierNode::CloseDocuments(bPromptToSave);
    }
    return hr;
}

