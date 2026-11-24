//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//
// File: hu_node.cpp
// Area: CHierNode implementation
//
//---------------------------------------------------------------------------

#include "hu_pch.h"

#include "hu_node.h"
#include "hu_ctnr.h"
#include <oleipc.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
static DWORD g_dwCHierNode = 0;
#endif

#ifdef _DEBUG
#define LIST_VSPROP(exp) { VSHPROPID_##exp, _T("VSHPROPID_") ## _T(#exp) }

struct VSHPROP
{
    VSHPROPID m_id;
    LPCTSTR   m_sz;
} m_rgVSPROPID[] =
{
     LIST_VSPROP(NIL)
    ,LIST_VSPROP(Parent)
    ,LIST_VSPROP(FirstChild)
    ,LIST_VSPROP(NextSibling)
    ,LIST_VSPROP(Root)
    ,LIST_VSPROP(TypeGuid)
    ,LIST_VSPROP(SaveName)
    ,LIST_VSPROP(Caption)
    ,LIST_VSPROP(IconImgList)
    ,LIST_VSPROP(IconIndex)
    ,LIST_VSPROP(Expandable)
    ,LIST_VSPROP(ExpandByDefault)
    ,LIST_VSPROP(Name)  // obsolete: ProjectName
    ,LIST_VSPROP(IconHandle)
    ,LIST_VSPROP(OpenFolderIconHandle)
    ,LIST_VSPROP(OpenFolderIconIndex)
    ,LIST_VSPROP(CmdUIGuid)
    ,LIST_VSPROP(SelContainer)
    ,LIST_VSPROP(BrowseObject)
    ,LIST_VSPROP(AltHierarchy)
    ,LIST_VSPROP(AltItemid)
    ,LIST_VSPROP(ProjectDir)
    ,LIST_VSPROP(SortPriority)
    ,LIST_VSPROP(EditLabel)
    ,LIST_VSPROP(ExtObject)
    ,LIST_VSPROP(ExtSelectedItem)
    ,LIST_VSPROP(StateIconIndex)
    ,LIST_VSPROP(TypeName)  // obsolete: ProjectType
    ,LIST_VSPROP(ReloadableProjectFile)
    ,LIST_VSPROP(ParentHierarchy)
    ,LIST_VSPROP(ParentHierarchyItemid)
    ,LIST_VSPROP(ItemDocCookie) 
    ,LIST_VSPROP(UserContext)   
    ,LIST_VSPROP(Expanded)
    ,LIST_VSPROP(ConfigurationProvider)
    ,LIST_VSPROP(ImplantHierarchy)
    ,LIST_VSPROP(OwnerKey)       
    ,LIST_VSPROP(StartupServices)
    ,LIST_VSPROP(FirstVisibleChild)
    ,LIST_VSPROP(NextVisibleSibling)
    ,LIST_VSPROP(IsHiddenItem)
    ,LIST_VSPROP(IsNonMemberItem)
    ,LIST_VSPROP(ItemSubType)
};

struct VSHPROP *g_LastVSHPROP = m_rgVSPROPID + (sizeof(m_rgVSPROPID) / sizeof(VSHPROP));

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TraceVSHPROPID(CHierNode *pNode, const VSHPROPID e, BOOL fGetSet)
{
    ASSERT(NULL != pNode);
  //ASSERT((VSHPROPID_FIRST <= e && e <= VSHPROPID_LAST) || VSHPROPID_NIL == e);

    struct VSHPROP *first = m_rgVSPROPID;
    while (first < g_LastVSHPROP && first->m_id != e) first++;

    // ATLTRACE asserts for buffer overflows. This can happen with large strings. So we want
    // to check for GetName() > 200 and chop it off
    TCHAR szName[201];
    int cBytes = (int)(((int)pNode->GetName().GetLength() > 200? 200: (int)pNode->GetName().GetLength())*sizeof(TCHAR));
    memcpy(szName, (LPCTSTR)pNode->GetName(),cBytes); 
    szName[cBytes/sizeof(TCHAR)] = 0;
    if(first != g_LastVSHPROP)
    {
        /* Uncomment to get property tracing
        if (fGetSet)
            ATLTRACE(_T("unhandled GetProperty(%s = %d): \"%s\"\n"), first->m_sz, e, szName);
        else
            ATLTRACE(_T("unhandled SetProperty(%s = %d): \"%s\"\n"), first->m_sz, e, szName);
        */
    }
    else
    {
        /* Uncomment to get property tracing
        if (fGetSet)
            ATLTRACE(_T("unhandled GetProperty(VSHPROPID_? = %d): \"%s\"\n"), e,szName);
        else
            ATLTRACE(_T("unhandled SetProperty(VSHPROPID_? = %d): \"%s\"\n"), e,szName);
        */
    }
}

#else

#define TraceVSHPROPID(pItem, e, fGetSet)
#endif


// Our global hiernode map. We use this strictly for validating an itemid points
// to a valid node. The CHierNode constructor puts it's itemid (which is strictly a pointer) into the 
// map. On destruction, it removes itself from the map
static CVxMap<VSITEMID, VSITEMID, VSITEMID, VSITEMID> g_globalHierNodeMap;
static BOOL g_globalHierNodeMapInitialized = FALSE;

//---------------------------------------------------------------------------
// CHierNode constructor
//---------------------------------------------------------------------------
CHierNode::CHierNode(void) :
    m_pNodeParent(NULL),
    m_pNodeNext(NULL),
    m_grfStateFlags(DEFAULT_NODE_FLAGS)
{
#ifdef _DEBUG
    ++g_dwCHierNode;
    VSITEMID itemid;    
    ASSERT(g_globalHierNodeMap.Lookup(GetVsItemID(), itemid) == FALSE);
#endif
    // The first node created init's the hash table to a reasonable prime value.
    if(g_globalHierNodeMapInitialized == FALSE)
    {   
        g_globalHierNodeMap.InitHashTable(349);
        g_globalHierNodeMapInitialized = TRUE;
    }
    g_globalHierNodeMap.SetAt(GetVsItemID(), GetVsItemID());
}

//---------------------------------------------------------------------------
//  Destructor, check for valid state verification
//---------------------------------------------------------------------------
CHierNode::~CHierNode(void)
{
#ifdef _DEBUG
    ASSERT(GetNext() == NULL);
    ASSERT(GetParent() == NULL);

    ASSERT(0 < g_dwCHierNode);
    if (--g_dwCHierNode == 0)
    {   // we should see this message for each package
        ATLTRACE(_T("Last CHierNode destroyed: \"%s\"\n"), GetName());
    }
    VSITEMID itemid;    
    ASSERT(g_globalHierNodeMap.Lookup(GetVsItemID(), itemid) == TRUE);
#endif // _DEBUG

    g_globalHierNodeMap.RemoveKey(GetVsItemID());
}

//---------------------------------------------------------------------------
// return the VSITEMID value for this node
// a cast of the this pointer to the VSITEMID (dword) type
// exception will be for root nodes which should return VSITEMID_ROOT
//---------------------------------------------------------------------------
VSITEMID CHierNode::GetVsItemID(void) const
{
    return reinterpret_cast<VSITEMID>(this);
}

//---------------------------------------------------------------------------
// VSHPROPID_FirstChild
//---------------------------------------------------------------------------
VSITEMID CHierNode::GetFirstChild(BOOL fDisplayOnly /*= TRUE*/)
{
    return (VSITEMID)VSITEMID_NIL;
}

//---------------------------------------------------------------------------
// VSHPROPID_FirstChild
//---------------------------------------------------------------------------
VSITEMID CHierNode::GetFirstMemberChild()
{
    return (VSITEMID)VSITEMID_NIL;
}

//---------------------------------------------------------------------------
// VSHPROPID_NextChild
//---------------------------------------------------------------------------
VSITEMID CHierNode::GetNextMemberSibling() const
{
    CHierNode *pNode = m_pNodeNext;
    while(pNode && !pNode->IsMemberItem())
        pNode = pNode->m_pNodeNext;

    return pNode? pNode->GetVsItemID() : VSITEMID_NIL;
}

//---------------------------------------------------------------------------
// by default this node has nothing to expand upon VSHPROPID_Expandable
//---------------------------------------------------------------------------
BOOL CHierNode::Expandable() const
{
    return FALSE;
}

//---------------------------------------------------------------------------
// by default this node has nothing to expand upon VSHPROPID_ExpandByDefault
//---------------------------------------------------------------------------
BOOL CHierNode::ExpandByDefault() const
{
    return FALSE;
}

//---------------------------------------------------------------------------
// by default this node is not a container VSHPROPID_Container
//---------------------------------------------------------------------------
BOOL CHierNode::IsContainer() const
{
    return FALSE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CVsHierarchy* CHierNode::GetCVsHierarchy(void) const
{
    // if parent is NULL, then this should be in a root node of the hierarchy
    // tree or this is a serious programming mistake (or the nodes have been 
    // zombied.
    ASSERT(GetParent() || IsZombie());
    if(GetParent() == NULL  || IsZombie())
        return NULL;
    
    CHierNode *pNode = GetParent();
    while (NULL != pNode->GetParent())
        pNode = pNode->GetParent();
    return pNode->GetCVsHierarchy();
}

//---------------------------------------------------------------------------
// Base-implementation of GetNestedHierarchy handles the failure case. Any
//  node which will contain another hierarchy must over-ride this method.
//---------------------------------------------------------------------------
HRESULT CHierNode::GetNestedHierarchy(
    REFIID          ,//riid,            // in: interface to get
    void**  ppVsHierarchy,  // out: hierarchy this node nests
    VSITEMID*       pitemidNested)  // out: VSITEMID so nodes can be shortcuts
{
    // must be initialized by hierarchy (to minimize retail code)
    ASSERT(ppVsHierarchy != NULL && NULL == *ppVsHierarchy);
    ASSERT(pitemidNested != NULL && VSITEMID_NIL == *pitemidNested);
    return E_FAIL;
}

//---------------------------------------------------------------------------
// VSHPROPID_Caption
//---------------------------------------------------------------------------
HRESULT CHierNode::GetDisplayCaption(BSTR *pDisplayCaption)
{
    ASSERT(!IsZombie() && pDisplayCaption);
	if (IsZombie())
		return E_UNEXPECTED;
    HRESULT hr = S_OK;
    if(pDisplayCaption)
    {
        CString strCaption;
        if (SUCCEEDED(hr = GetDisplayCaption(strCaption)))
        {
            if (strCaption.GetLength() > _MAX_PATH - 1)
            {
                // don't return a display caption longer than _MAX_PATH-1, since the tree control cannot
                // handle it. instead, truncate the caption by ellipsing it (terminating it with "...").
                strCaption.SetAt(_MAX_PATH - 4, L'.');
                strCaption.SetAt(_MAX_PATH - 3, L'.');
                strCaption.SetAt(_MAX_PATH - 2, L'.');
                strCaption.Truncate(_MAX_PATH - 1);
            }

            *pDisplayCaption = strCaption.AllocSysString();
            if (*pDisplayCaption == NULL)
            {
                hr = E_OUTOFMEMORY;
            }
        }
    }
    else
        hr = E_INVALIDARG;
    return hr;
}
//---------------------------------------------------------------------------
// VSHPROPID_Caption
//---------------------------------------------------------------------------
HRESULT CHierNode::GetDisplayCaption(CString& strDisplayCaption)
{
    ASSERT(!IsZombie());
    strDisplayCaption = m_strName;
    return S_OK;
}

//---------------------------------------------------------------------------
// VSHPROPID_EditLabel - default returns the m_strName
//---------------------------------------------------------------------------
HRESULT CHierNode::GetEditLabel(BSTR *ppEditLabel)
{
    return E_NOTIMPL;
}

//---------------------------------------------------------------------------
// VSHPROPID_EditLabel
//---------------------------------------------------------------------------
HRESULT CHierNode::SetEditLabel(BSTR pEditLabel)
{
    return E_NOTIMPL;
}

//---------------------------------------------------------------------------
//  Returns requested guid property
//---------------------------------------------------------------------------
HRESULT CHierNode::GetGuidProperty(VSHPROPID propid, GUID* pGuid) const
{
    // 
    return E_NOTIMPL;
}

//---------------------------------------------------------------------------
// Returns the requested property for the CHierNode.
//---------------------------------------------------------------------------
HRESULT CHierNode::GetProperty(VSHPROPID propid, VARIANT* pvar)
{
    ASSERT(pvar != NULL);
    HRESULT hr = E_NOTIMPL;
    if(propid == VSHPROPID_IsNonMemberItem)
    {   // By default all items are members
        pvar->vt = VT_BOOL;
        pvar->boolVal = IsMemberItem()?VARIANT_FALSE : VARIANT_TRUE;
        hr = S_OK;
    }
    else
    {
        TraceVSHPROPID(this, propid, 1);
    }
    return hr;
}

//---------------------------------------------------------------------------
// puts the requested property for the CHierNode.
//---------------------------------------------------------------------------
HRESULT CHierNode::SetProperty(VSHPROPID propid, const VARIANT& var)
{
    TraceVSHPROPID(this, propid, 0);
    return E_NOTIMPL;
}
    
//---------------------------------------------------------------------------
// Override to put a context menu for the node.
//---------------------------------------------------------------------------
HRESULT CHierNode::DisplayContextMenu()
{
    return S_OK;
}

//---------------------------------------------------------------------------
// Helper implementation to actually display the context menu. You should override
// DisplayContextMenu() and have it call this function to do the work.
//---------------------------------------------------------------------------
HRESULT CHierNode::ShowContextMenu(UINT iCntxtMenuID,
                                    REFGUID GroupGuid,
                                    IOleCommandTarget* pIOleCmdTarg)
{
    CComPtr<IOleComponentUIManager> srpUIManager;
    HRESULT hr = _VxModule.QueryService(SID_SOleComponentUIManager, IID_IOleComponentUIManager, (void **)&srpUIManager);
    ASSERT(srpUIManager != NULL);
    if (srpUIManager != NULL)
    {
        POINT  pnt;
        ::GetCursorPos(&pnt);
        POINTS pnts = { (SHORT)pnt.x, (SHORT)pnt.y };

        hr = srpUIManager->ShowContextMenu(0, GroupGuid, iCntxtMenuID, pnts, pIOleCmdTarg);
    }
    return hr;
}

//---------------------------------------------------------------------------
// Override to return your guid
//---------------------------------------------------------------------------
const GUID* CHierNode::PGuidGetType(void) const
{
    ASSERT(!_T("You should be calling an over-ridden version of this..."));
    return &IID_NULL;
}

//---------------------------------------------------------------------------
// All nodes which neeed to handle this should over-ride it
//---------------------------------------------------------------------------
UINT CHierNode::GetIconIndex(ICON_TYPE) const
{   
    ASSERT(!_T("You should be calling an over-ridden version of this..."));
    return (UINT)-1;
}

//---------------------------------------------------------------------------
// Each node which can return a name must over-ride
//---------------------------------------------------------------------------
HRESULT CHierNode::GetCanonicalName(BSTR* ppszName) const
{   
    *ppszName = NULL;
    ATLTRACENOTIMPL(_T("CHierNode::GetCanonicalName"));
}

//---------------------------------------------------------------------------
// Default does nothing. Override to call your default command handler
//---------------------------------------------------------------------------
HRESULT CHierNode::DoDefaultAction(void)
{   // each node which has a "default" action must over-ride
    return S_OK;
}
//---------------------------------------------------------------------------
// Default does nothing. 
//---------------------------------------------------------------------------
HRESULT CHierNode::OnStartLabelEdit()
{   
    return S_OK;
}
//---------------------------------------------------------------------------
// Default does nothing. 
//---------------------------------------------------------------------------
HRESULT CHierNode::OnCommitLabelEdit()
{   
    return S_OK;
}
//---------------------------------------------------------------------------
// Default does nothing. 
//---------------------------------------------------------------------------
HRESULT CHierNode::OnCancelLabelEdit()
{   
    return S_OK;
}

//---------------------------------------------------------------------------
// Ansi version. If Hierarchy is non-null, notifies shell of change
//---------------------------------------------------------------------------
void CHierNode::SetName(LPCSTR pszNewName, CVsHierarchy *pCVsHierarchy /*= NULL*/)
{   // ANSI method with Notify
    m_strName = pszNewName;
    if (NULL != pCVsHierarchy)
        pCVsHierarchy->OnPropertyChanged(this, VSHPROPID_Caption, 0);
}
//---------------------------------------------------------------------------
// Wide string version. If Hierarchy is non-null, notifies shell of change
//---------------------------------------------------------------------------
void CHierNode::SetName(LPCWSTR pszNewName, CVsHierarchy *pCVsHierarchy /*= NULL*/)
{   // UNICODE method with Notify
    m_strName = pszNewName;
    if (NULL != pCVsHierarchy)
        pCVsHierarchy->OnPropertyChanged(this, VSHPROPID_Caption, 0);
}

//---------------------------------------------------------------------------
// Ctring version. If Hierarchy is non-null, notifies shell of change
//---------------------------------------------------------------------------
void CHierNode::SetName(const CString& strNewName, CVsHierarchy *pCVsHierarchy /*= NULL*/)
{   // UNICODE method with Notify
    m_strName = strNewName;
    if (NULL != pCVsHierarchy)
        pCVsHierarchy->OnPropertyChanged(this, VSHPROPID_Caption, 0);
}

//---------------------------------------------------------------------------
// VSHPROPID_NextSibling
//---------------------------------------------------------------------------
CHierNode* CHierNode::GetNext(BOOL fDisplayOnly) const
{
    CHierNode *pNode = m_pNodeNext;
    
    if (fDisplayOnly)
    {
        while(pNode && !pNode->IsDisplayable())
            pNode = pNode->m_pNodeNext;
    }
    return pNode;
}

//---------------------------------------------------------------------------
// Gets the child of this object's parent that occurs directly before
//  this node in the parent's list. This is an expensive operation, and is
//  nowhere as straight-forward as getting the next child in this list.
//---------------------------------------------------------------------------
CHierNode* CHierNode::GetPrev(BOOL fDisplayOnly) const
{
    if (GetParent() != NULL)
    {
        return GetParent()->GetPrevChildOf(this, fDisplayOnly);
    }
    ASSERT(GetParent() != NULL);    // incorrect usage?
    return NULL;
}

//---------------------------------------------------------------------------
//  Iteratively get the root node of the tree
//---------------------------------------------------------------------------
CHierNode* CHierNode::GetRootNode(void) const
{
    CHierNode *pNode = const_cast<CHierNode *>(this);   // safe
    for (; pNode->GetParent() != NULL; pNode = pNode->GetParent());
    return pNode;
}

//---------------------------------------------------------------------------
//  is the given node an ancestor of this node
//---------------------------------------------------------------------------
BOOL CHierNode::HasAncestor(const CHierNode *pNode) const
{
    CHierNode *pAncestor = GetParent();
    for (; pAncestor != NULL; pAncestor = pAncestor->GetParent())
    {
        if (pAncestor == pNode)
        {
            return TRUE;
        }
    }
    return FALSE;
}

//-----------------------------------------------------------------------------
// Call to expand the node.
//-----------------------------------------------------------------------------
HRESULT CHierNode::ExtExpand(EXPANDFLAGS expandflags, REFGUID rguidPersistenceSlot) const
{
    HRESULT hr;
    CComVariant srpvt;
    CComPtr<IVsWindowPane> srpIVsWindowPane;
    CComPtr<IVsWindowFrame> srpIVsWindowFrame;
    CComPtr<IVsUIHierarchyWindow> srpIVsUIHierarchyWindow;

    IVsUIShell *pIVsUIShell = _VxModule.GetVsUIShell(); // non-addref'ed
    ASSERT(NULL != pIVsUIShell);

    IfErrGo(pIVsUIShell->FindToolWindow(NULL, rguidPersistenceSlot, &srpIVsWindowFrame));

    IfErrGo(srpIVsWindowFrame->GetProperty(VSFPROPID_DocView, &srpvt));

    ASSERT(VT_UNKNOWN == V_VT(&srpvt));
    if (VT_UNKNOWN != V_VT(&srpvt))
    {
        IfErrGo(E_FAIL);
    }
    ASSERT(NULL != V_UNKNOWN(&srpvt));

    IfErrGo(V_UNKNOWN(&srpvt)->QueryInterface(IID_IVsWindowPane, (void **)&srpIVsWindowPane));
    ASSERT(srpIVsWindowPane != NULL);

    IfErrGo(srpIVsWindowPane->QueryInterface(IID_IVsUIHierarchyWindow, (void **)&srpIVsUIHierarchyWindow));
    ASSERT(srpIVsUIHierarchyWindow != NULL);
    ASSERT(NULL != GetCVsHierarchy());

    IfErrGo(srpIVsUIHierarchyWindow->ExpandItem( GetCVsHierarchy()->GetIVsUIHierarchy(), GetVsItemID(), expandflags));

ERROR_EXIT:
    return hr;
}

//-----------------------------------------------------------------------------
// IsZombie - Returns True if this node's top level parent is not a Root node
//-----------------------------------------------------------------------------
BOOL CHierNode::IsZombie(void) const
{
    CHierNode *pNode = GetRootNode();
    if (!pNode || (VSITEMID_ROOT != pNode->GetVsItemID())) 
        return TRUE;
    return FALSE;
}

//-----------------------------------------------------------------------------
// Static helper which is used to detect stale itemid's for nodes which have
// gone away (different than the zombie case).
//-----------------------------------------------------------------------------
BOOL CHierNode::IsValidCHierNode(VSITEMID itemid)
{
    VSITEMID itemidDummy;
    return g_globalHierNodeMap.Lookup(itemid, itemidDummy);
}

//-----------------------------------------------------------------------------
// Force node to repaint. Do it by resetting the icon index or text or both.
//-----------------------------------------------------------------------------
void CHierNode::ReDraw(BOOL bUpdateIcon /*=TRUE*/, BOOL bUpdateStateIcon /*=TRUE*/, 
                       BOOL bUpdateText /*= FALSE*/)
{
    // Root object or item must be in UI.
    CHierContainer* pParent = GetParent();
    if(pParent == NULL || pParent->HaveChildrenBeenEvaluated())
    {
        CVsHierarchy* pHier = GetCVsHierarchy();
        if(bUpdateIcon)
            pHier->OnPropertyChanged(this, VSHPROPID_IconIndex, 0);
        if(bUpdateStateIcon)
            pHier->OnPropertyChanged(this, VSHPROPID_StateIconIndex, 0);
        if(bUpdateText)
            pHier->OnPropertyChanged(this, VSHPROPID_Caption, 0);
    }
}

//-----------------------------------------------------------------------------
// Close open document for node
//-----------------------------------------------------------------------------
HRESULT CHierNode::CloseDocuments(BOOL bPromptToSave /*=FALSE*/)
{

    HRESULT hrRet = S_OK;  
    ASSERT(!IsZombie());
    if(IsZombie())
        return S_OK;

    // We walk the RDT looking for all running documents attached to this hierarchy and itemid. There
    // are cases where there may be two different editors (not views) open on the same document.
    CComPtr<IEnumRunningDocuments> srpEnumRDT;
    IVsRunningDocumentTable* pRDT = _VxModule.GetIVsRunningDocumentTable();
    ASSERT(pRDT);
    if(!pRDT)
        return S_OK;

    HRESULT hr = pRDT->GetRunningDocumentsEnum(&srpEnumRDT);
    ASSERT(SUCCEEDED(hr));
    if(SUCCEEDED(hr))
    {  
        VSCOOKIE dwDocCookie;
        VSSLNCLOSEOPTIONS saveOptions = bPromptToSave? SLNSAVEOPT_PromptSave : SLNSAVEOPT_NoSave;
        CComPtr<IVsHierarchy> srpOurHier = GetCVsHierarchy()->GetIVsHierarchy();
        srpEnumRDT->Reset();
        while(srpEnumRDT->Next(1, &dwDocCookie, NULL) == S_OK)
        {
            // Note we can pass NULL for all parameters we don't care about
            CComPtr<IVsHierarchy> srpHier;
            VSITEMID itemid = VSITEMID_NIL;
            pRDT->GetDocumentInfo(dwDocCookie, NULL/*pgrfRDTFlags*/, NULL/*pdwReadLocks*/, NULL/*pdwEditLocks*/, 
                                  NULL /*bstrMkDocumentOld*/, &srpHier, &itemid, NULL /*ppunkDocData*/);

            // Is this one of our documents?
            if(srpHier == srpOurHier && itemid == GetVsItemID())
            {
                // This is the only hr return code we care about
                hrRet =  _VxModule.GetIVsSolution()->CloseSolutionElement(saveOptions, srpOurHier, dwDocCookie);
                if(FAILED(hrRet))
                    break;
            }
        }
    }
    return hrRet;
}

//-----------------------------------------------------------------------------
// Save open document for node
//-----------------------------------------------------------------------------
HRESULT CHierNode::SaveDocument(BOOL bPromptToSave /*=FALSE*/)
{
    // this needs to be overrided
    ASSERT(FALSE);
    return E_FAIL;
}
//---------------------------------------------------------------------------
//  Sets/resets the bit(s) based in the value.
//---------------------------------------------------------------------------
void CHierNode::SetBits(int bits, BOOL bValue)
{ 
    if(bValue)
        m_grfStateFlags |=  bits;
    else
        m_grfStateFlags &= ~bits;
}


//---------------------------------------------------------------------------
// VSHPROPID_UserContext
//---------------------------------------------------------------------------
HRESULT CHierNode::GetUserContext(IVsUserContext **ppUserCtx)
{
    return E_NOTIMPL;
}



