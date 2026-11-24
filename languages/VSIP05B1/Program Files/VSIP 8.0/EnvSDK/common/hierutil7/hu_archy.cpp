		//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// VsHierarchy.cpp : Implementation of CIswsApp and DLL registration.
//---------------------------------------------------------------------------

#include "hu_pch.h"

#include "hu_archy.h"
#include "hu_ctnr.h"
#include "wtypes.h"
#include <fpstfmt.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// did we start this drag or not
BOOL  CVsHierarchy::g_bStartedDrag = FALSE;

// are we currently displaying a context menu for a selection in the UIHierarchy window?
BOOL  CVsHierarchy::g_bInContextMenu = FALSE;

VsHierList *CVsHierarchy::m_pVsHierList = NULL;

//---------------------------------------------------------------------------
// Constructor. Need to set the project node outside of the constructor.
//---------------------------------------------------------------------------
CVsHierarchy::CVsHierarchy(void) :
    m_hImageList(NULL),
    m_pRootNode(NULL),
    m_fHierClosed(FALSE),
    m_pParentHierarchy(NULL),
    m_dwParentHierarchyItemid(VSITEMID_NIL)
{
}

//---------------------------------------------------------------------------
// Destuctor -> release all event sinks and close
//---------------------------------------------------------------------------
CVsHierarchy::~CVsHierarchy(void)
{
    if (!IsZombie())        // zombie check, no assertion
    {
        IUnknown* pUnk = GetRootNode();
        ASSERT(NULL != pUnk);
        SetRootNode(NULL);
        pUnk->Release();
    }
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Called to set the IServerProvider site.
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::SetSite(
            /* [in] */ IServiceProvider *pSP)
{
    ASSERT(NULL != pSP);
    VsHierList *pVsHierList = new VsHierList;
    if(!pVsHierList)
        return E_OUTOFMEMORY;
    pVsHierList->pNext = CVsHierarchy::m_pVsHierList;
    pVsHierList->pVsHierarchy = this;
    CVsHierarchy::m_pVsHierList = pVsHierList;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Called to get the IServerProvider site.
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::GetSite(
            /* [out] */ IServiceProvider **ppSP)
{
    if (ppSP != NULL)
    {
        *ppSP = NULL;
        ATLTRACENOTIMPL(_T("CVsHierarchy::GetSite"));
    }
    ASSERT(ppSP != NULL);
    return E_INVALIDARG;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::QueryClose(BOOL *pfCanClose)
{
    if (NULL != pfCanClose)
    {
        *pfCanClose = TRUE;
        ATLTRACENOTIMPL(_T("CVsHierarchy::QueryClose"));
    }
    ASSERT(NULL != pfCanClose);
    return E_INVALIDARG;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Called to close the web hierarchy.
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::Close(void)
{
    VsHierList *pVsHierList = CVsHierarchy::m_pVsHierList;
    VsHierList *pTemp;

    if (pVsHierList && pVsHierList->pVsHierarchy == this)
    {
        CVsHierarchy::m_pVsHierList = pVsHierList->pNext;
        delete pVsHierList;
    }
    else
    {
        while(pVsHierList && (pVsHierList->pNext))
        {
            if (pVsHierList->pNext->pVsHierarchy == this)
            {
                pTemp = pVsHierList->pNext;
                pVsHierList->pNext = pVsHierList->pNext->pNext;
                delete pTemp;
            }
            pVsHierList = pVsHierList->pNext;
        }
    }
  
    m_fHierClosed = TRUE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Returns the guidType for the itemid.
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::GetGuidProperty(
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHPROPID propid,
            /* [out] */ GUID *pguid)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Fail if hierarchy already closed
    RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED

    HRESULT hr = E_INVALIDARG;
    ASSERT(pguid != NULL);
    if (pguid != NULL)
    {
        CHierNode *pNode = NULL;
        hr = VSITEMID2Node(itemid, &pNode);
        if (SUCCEEDED(hr))
        {
            ASSERT(pNode != NULL);
            hr = pNode->GetGuidProperty(propid, pguid);
        }
        else
        {   // asserts are in VSITEMID2Node
            *pguid = IID_NULL;
        }
    }
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Returns the guidType for the itemid.
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::SetGuidProperty(
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHPROPID propid,
            /* [in] */ REFGUID guid)
{
    ATLTRACENOTIMPL(_T("CVsHierarchy::IVsHierarchy::SetGuidProperty"));
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy helper function
// Returns the requested property for the CHierNode.
// There are several of properties handled on the VsHierarchy level
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::GetProperty(
            /* [in] */ CHierNode *pNode,
            /* [in] */ VSHPROPID propid,
            /* [out] */ VARIANT *pvar)
{
    ASSERT(NULL != pNode && !IsZombie() && NULL != pvar);

    HRESULT hr = S_OK;
    switch (propid)
    {
#ifdef _DEBUG
    case VSHPROPID_NIL:                 // invalid
        ASSERT(!_T("error: known invalid get properties"));
        hr = E_UNEXPECTED;
        break;
#endif

    case VSHPROPID_Parent:              // CHierNode property
        V_VT(pvar) = VT_INT_PTR;
        V_INT_PTR(pvar) = (pNode->GetParent() != NULL) ? pNode->GetParent()->GetVsItemID() : VSITEMID_NIL;
        break;

    case VSHPROPID_FirstVisibleChild:           // CHierContainer property
        V_VT(pvar) = VT_INT_PTR;
        V_INT_PTR(pvar) = GetFirstDisplayableNode(pNode);
        break;

    case VSHPROPID_NextVisibleSibling:          // CHierNode property
        V_VT(pvar) = VT_INT_PTR;
        V_INT_PTR(pvar) = GetNextDisplayableNode(pNode);
        break;

    case VSHPROPID_FirstChild:          // CHierContainer property
        V_VT(pvar) = VT_INT_PTR;
        V_INT_PTR(pvar) = pNode->GetFirstMemberChild();
        break;

    case VSHPROPID_NextSibling:         // CHierNode property
        V_VT(pvar) = VT_INT_PTR;
        V_INT_PTR(pvar) = pNode->GetNextMemberSibling();
        break;

    case VSHPROPID_Root:                // VsHierarchy property
        V_VT(pvar) = VT_INT_PTR;                
        V_INT_PTR(pvar) = VSITEMID_ROOT;
        break;

    case VSHPROPID_ParentHierarchyItemid:
        ASSERT(pNode->GetVsItemID() == VSITEMID_ROOT);
        V_VT(pvar) = VT_INT_PTR;
        V_INT_PTR(pvar) = m_dwParentHierarchyItemid;
        break;

    case VSHPROPID_IsHiddenItem:
        V_VT(pvar)   = VT_BOOL;
        V_BOOL(pvar) = (pNode->IsDisplayable()? VARIANT_FALSE: VARIANT_TRUE);
        break;

    case VSHPROPID_Caption:         // CHierNode property
        V_VT(pvar) = VT_BSTR;
        hr = pNode->GetDisplayCaption(&V_BSTR(pvar));
        break;

    case VSHPROPID_IconImgList:         // VsHierarchy property
        V_VT(pvar) = VT_INT_PTR;        
        V_INT_PTR(pvar) = (INT_PTR)GetImageList();
        if( NULL == V_INT_PTR(pvar) ) 
            hr = DISP_E_MEMBERNOTFOUND; // tells Environment it should attempt to supply an imagelist
        break;

    case VSHPROPID_IconIndex:           // VsHierarchy derived property
        V_VT(pvar) = VT_I4;
        V_I4(pvar) = static_cast<INT>(GetIconIndex(pNode, ICON_Closed));
        if (V_I4(pvar) == -1)
            hr = DISP_E_MEMBERNOTFOUND; // this tells Environment to supply windows def icon
        break;

    case VSHPROPID_Expandable:          // CHierNode & CHierContainer property
        V_VT(pvar) = VT_I4;
        V_I4(pvar) = pNode->Expandable();
        break;

    case VSHPROPID_ExpandByDefault:     // CHierContainer property
        V_VT(pvar)   = VT_BOOL;
        if (pNode == m_pRootNode)
            V_BOOL(pvar) = VARIANT_TRUE;
        else
            V_BOOL(pvar) = pNode->ExpandByDefault()? VARIANT_TRUE : VARIANT_FALSE;
        break;

    case VSHPROPID_Name:                // Node property
        V_VT(pvar) = VT_BSTR;
        hr = pNode->GetDisplayCaption(&V_BSTR(pvar));
        break;

    case VSHPROPID_OpenFolderIconIndex: // CHierContainer property
        V_VT(pvar) = VT_I4;
        V_I4(pvar) = static_cast<INT>(GetIconIndex(pNode, ICON_Open));
        if (V_I4(pvar) == -1)
            hr = DISP_E_MEMBERNOTFOUND; // this tells Environment to supply windows def icon
        break;

    case VSHPROPID_SelContainer:        // VsHierarchy [optional] property
        hr = DISP_E_MEMBERNOTFOUND;
        break;

    case VSHPROPID_ConfigurationProvider:  // hierarchy property
        hr = m_pRootNode->GetConfigProvider(pvar);
        break;

    case VSHPROPID_BrowseObject:        // CHierNode derived property
        // if the node is the root node check if CVsHierarchy object implements IDispatch
        if (pNode->GetVsItemID() == VSITEMID_ROOT && SUCCEEDED(hr = this->QueryInterface(IID_IDispatch, (void **)&V_DISPATCH(pvar))))
        {
            V_VT(pvar) = VT_DISPATCH;
        }
        else
        {   // reclear the variant
            ::VariantInit(pvar);
            if (FAILED(hr = pNode->GetProperty(propid, pvar)))
                hr = E_NOINTERFACE;
        }
        break;

    case VSHPROPID_AltHierarchy:        // VsHierarchy [optional] property
    case VSHPROPID_AltItemid:           // VsHierarchy [optional] property
    case VSHPROPID_SortPriority:        // Retrieves priority of this projct relative to others.
        hr = DISP_E_MEMBERNOTFOUND;
        break;

    case VSHPROPID_EditLabel:
        V_VT(pvar)   = VT_BSTR;
        V_BSTR(pvar) = NULL;
        hr = pNode->GetEditLabel(&V_BSTR(pvar));
        break;

    case VSHPROPID_StateIconIndex:
        V_VT(pvar) = VT_I4;
        V_I4(pvar) = static_cast<INT>(GetIconIndex(pNode, ICON_StateImage));
        if (V_I4(pvar) == -1)
            hr = DISP_E_MEMBERNOTFOUND; // this tells Environment to supply windows def icon
        break;

    case VSHPROPID_ParentHierarchy:
        ASSERT(pNode->GetVsItemID() == VSITEMID_ROOT);
        V_VT(pvar) = VT_UNKNOWN;
        V_UNKNOWN(pvar) = m_pParentHierarchy;
        if (NULL != V_UNKNOWN(pvar))
            V_UNKNOWN(pvar)->AddRef();
        break;

    case VSHPROPID_UserContext:
        {
        IVsUserContext *pUserCtx = NULL;
        V_VT(pvar)   = VT_UNKNOWN;
        V_UNKNOWN(pvar) = NULL;
        hr = pNode->GetUserContext(&pUserCtx);
        if (SUCCEEDED(hr))
            V_UNKNOWN(pvar) = pUserCtx;
        }
        break;

    case VSHPROPID_OwnerKey:
        V_VT(pvar) = VT_BSTR;
        V_BSTR(pvar) = SysAllocString( m_bstrOwnerKey );
        hr = V_BSTR(pvar) ? NOERROR : E_OUTOFMEMORY;
        break;

    case VSHPROPID_Container:          // CHierNode & CHierContainer property
        V_VT(pvar) = VT_BOOL;
        V_BOOL(pvar) = pNode->IsContainer() ? VARIANT_TRUE : VARIANT_FALSE;
        break;

    default:
        // Just let node handle.
        hr = pNode->GetProperty(propid, pvar);
    }
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Returns the requested property for the itemid.
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::GetProperty(
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHPROPID propid,
            /* [out] */ VARIANT *pvar)
{
    ASSERT(pvar != NULL);

	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Fail if hierarchy already closed
    RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED


    HRESULT hr = E_INVALIDARG;
    if (pvar != NULL)   // parameter checking
    {
        ::VariantInit(pvar);

        CHierNode *pNode = NULL;
        hr = VSITEMID2Node(itemid, &pNode);
        if (SUCCEEDED(hr))
        {
            ASSERT(NULL != pNode);
            hr = GetProperty(pNode, propid, pvar);
        }
    }
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Set's the given property on the item specified by itemid.
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::SetProperty(
            /* [in] */ CHierNode *pNode,
            /* [in] */ VSHPROPID propid,
            /* [in] */ const VARIANT& var)
{
    ASSERT(pNode != NULL && !IsZombie());

    HRESULT hr = E_INVALIDARG;
    switch (propid)
    {
    case VSHPROPID_EditLabel:
        ASSERT(VT_BSTR == V_VT(&var));
        if (VT_BSTR == V_VT(&var))
        {   // SetEditLabel should call the OnPropertyChanged if necessary
            hr = pNode->SetEditLabel(V_BSTR(&var));
        }
        break;

    case VSHPROPID_ParentHierarchy:
        // allow  the VT_DISPATCH and VT_UNKNOWN.
        ASSERT(VT_UNKNOWN == V_VT(&var) || VT_DISPATCH == V_VT(&var));
        if (VT_UNKNOWN == V_VT(&var))
        {
            m_pParentHierarchy = V_UNKNOWN(&var);   // NOTE: hold as UNADDREF'ed pointer
            hr = S_OK;
        } 
        else if (VT_DISPATCH == V_VT(&var))
        {
            hr = (V_DISPATCH(&var))->QueryInterface(IID_IUnknown, (void**)&m_pParentHierarchy);
            if (SUCCEEDED(hr))
            {
                //to match the UNADDREF'ed state of the IUnknown case, release here
                m_pParentHierarchy->Release(); //just dec'ing the ref count
            }
        }
        break;

    case VSHPROPID_ParentHierarchyItemid:
        ASSERT(VT_INT_PTR == V_VT(&var));
        if (VT_INT_PTR == V_VT(&var))
        {
            m_dwParentHierarchyItemid = V_INT_PTR(&var);
            hr = S_OK;
        }
        break;

    case VSHPROPID_OwnerKey:
        ASSERT(VT_BSTR == V_VT(&var));
        if (VT_BSTR == V_VT(&var))
        {
            SetOwnerKey(V_BSTR(&var));
            hr = S_OK;
        }
        break;

    default:
        hr = pNode->SetProperty(propid, var);;
    }
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Set's the given property on the item specified by itemid.
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::SetProperty(
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHPROPID propid,
            /* [in] */ VARIANT var)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Fail if hierarchy already closed
    RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED

    CHierNode *pNode = NULL;
    HRESULT hr = VSITEMID2Node(itemid, &pNode);
    if (SUCCEEDED(hr))
    {
        ASSERT(NULL != pNode);
        hr = SetProperty(pNode, propid, var);
    }
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Returns the nested hierarchy for item id.
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::GetNestedHierarchy(
            /* [in] */ VSITEMID itemid,
            /* [in] */ REFIID iidHierarchyNested,
            /* [iid_is][out] */ void  **ppHierarchyNested,
            /* [out] */ VSITEMID *pitemidNested)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Fail if hierarchy already closed
    RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED

    if (NULL != ppHierarchyNested && NULL != pitemidNested)
    {
        *ppHierarchyNested = NULL;
        *pitemidNested = (VSITEMID)VSITEMID_NIL;

        CHierNode *pNode = NULL;
        HRESULT hr = VSITEMID2Node(itemid, &pNode);
        if (SUCCEEDED(hr))
        {
            ASSERT(pNode != NULL);
            hr = pNode->GetNestedHierarchy(iidHierarchyNested, ppHierarchyNested, pitemidNested);
        }
        return hr;  // asserts are in VSITEMID2Node
    }
    ASSERT(NULL != ppHierarchyNested);
    return E_INVALIDARG;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Returns the canonical name for itemid.
//
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::GetCanonicalName(
            /* [in] */ VSITEMID itemid,
            /* [out] */ BSTR *pbstrName)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Fail if hierarchy already closed
    RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED

    CHierNode*  pNode = NULL;
    HRESULT     hr = VSITEMID2Node(itemid, &pNode);

    if (SUCCEEDED(hr))
    {
        ASSERT(pNode != NULL);
        hr = pNode->GetCanonicalName(pbstrName);
    }
    // asserts are in VSITEMID2Node
    return hr;  
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Returns the itemid for the canonical name pszName. The canonical name for
// Web hierarchies is it's absolute url??
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::ParseCanonicalName(
            /* [in] */ LPCOLESTR pszName,
            /* [out] */ VSITEMID *pitemid)
{
    if (pitemid != NULL)
    {
        *pitemid = (VSITEMID)VSITEMID_NIL;
        ATLTRACENOTIMPL(_T("CVsHierarchy::ParseCanonicalName"));
    }
    ASSERT(pitemid != NULL);
    return E_INVALIDARG;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Allows for a binary-comapatible change.  Needed since IVsUIHierarchy
// derives from IVsHierarchy
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::Unused0(void)
{
    ATLTRACENOTIMPL(_T("CVsHierarchy::Unused0"));
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Returns our toplevel project automation object
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::AdviseHierarchyEvents(
            /* [in] */ IVsHierarchyEvents *pEventSink,
            /* [out] */ VSCOOKIE *pdwCookie)
{
    ASSERT(NULL != pEventSink);
    ASSERT(NULL != pdwCookie);
    HRESULT hr = E_INVALIDARG;
    if (pEventSink != NULL && pdwCookie != NULL)
    {
        hr = m_hierEventAdvises.SetAdvise(pEventSink, pdwCookie);
    }
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Returns our toplevel project automation object
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::UnadviseHierarchyEvents(
            /* [in] */ VSCOOKIE dwCookie)
{
    return m_hierEventAdvises.UnAdvise(dwCookie);
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Allows for a binary-comapatible change.  Needed since IVsUIHierarchy
// derives from IVsHierarchy
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::Unused1(void)
{
    ATLTRACENOTIMPL(_T("CVsHierarchy::Unused1"));
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Allows for a binary-comapatible change.  Needed since IVsUIHierarchy
// derives from IVsHierarchy
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::Unused2(void)
{
    ATLTRACENOTIMPL(_T("CVsHierarchy::Unused1"));
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Allows for a binary-comapatible change.  Needed since IVsUIHierarchy
// derives from IVsHierarchy
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::Unused3(void)
{
    ATLTRACENOTIMPL(_T("CVsHierarchy::Unused1"));
}

//---------------------------------------------------------------------------
// interface: IVsHierarchy
// Allows for a binary-comapatible change.  Needed since IVsUIHierarchy
// derives from IVsHierarchy
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::Unused4(void)
{
    ATLTRACENOTIMPL(_T("CVsHierarchy::Unused1"));
}

//---------------------------------------------------------------------------
// Returns our toplevel project automation object. No longer a member of
// IVsHierarchy
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::GetAutomationObject(
            /* [out] */ IDispatch  **ppdisp)
{
    if (ppdisp != NULL)
    {
        *ppdisp = NULL;
        ATLTRACENOTIMPL(_T("CVsHierarchy::GetAutomationObject"));
    }
    ASSERT(ppdisp != NULL);
    return E_INVALIDARG;
}

//---------------------------------------------------------------------------
// interface: IVsUIHierarchy
// Called to execute the cmdid from the guidCmdSet on the itemid. If itemid =
// VSITEMID_SELECTED (the normal case), the command is applied to the selected
// items.
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::ExecCommand(
            /* [in] */          VSITEMID itemid,
            /* [unique][in] */  const GUID __RPC_FAR *pguidCmdGroup,
            /* [in] */          DWORD nCmdID,
            /* [in] */          DWORD nCmdexecopt,
            /* [unique][in] */  VARIANT __RPC_FAR *pvaIn,
            /* [unique][out][in] */ VARIANT __RPC_FAR *pvaOut)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Fail if hierarchy already closed
    RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED

    CHierNode *pNode = NULL;
    HierNodeList rgNodeList;
    HRESULT hr = VSITEMID2Node(itemid, rgNodeList);
    if (SUCCEEDED(hr))
    {   // Handle std hierarchy commands here
        if(*pguidCmdGroup == GUID_VsUIHierarchyWindowCmds)
        {
            switch(nCmdID)
            {
                case UIHWCMDID_RightClick:
                    // NOTE: Normally the IOleCommandTarget for the IVsHierarchy is not allowed to 
                    // handle commands like Cut, Copy, Paste, Delete, Rename during the current
                    // hierarchy point in the command routing. These type of commands should only
                    // apply to the object with focus. For example, it is very undesirable if 
                    // executing the Edit.Delete command while focus is in a document window was
                    // handled by the project to delete the select project item (i.e. the open 
                    // document). For a hierarchy these commands are normally processed via
                    // IVsUIHierarchy::ExecCommand. But in the case of bringing up a context menu
                    // we know that the hierarchy has focus, thus these commands are valid. In order
                    // to communicate this fact to our IOleCommandTarget implementation we set
                    // the "m_fInContextMenu" flag.
                    g_bInContextMenu = TRUE;
                    hr = DisplayContextMenu(rgNodeList);
                    g_bInContextMenu = FALSE;
                    break;
                case UIHWCMDID_DoubleClick:
                case UIHWCMDID_EnterKey:
                    do
                    {
                        pNode = rgNodeList.RemoveHead();
                        hr = pNode->DoDefaultAction();
                    } while(SUCCEEDED(hr) && !rgNodeList.IsEmpty());
                    break;
                case UIHWCMDID_StartLabelEdit:
                    pNode = rgNodeList.RemoveHead();
                    if(pNode)
                        hr = pNode->OnStartLabelEdit();
                    break;
                case UIHWCMDID_CommitLabelEdit:
                    pNode = rgNodeList.RemoveHead();
                    if(pNode)
                        hr = pNode->OnCommitLabelEdit();
                    break;
                case UIHWCMDID_CancelLabelEdit:
                    pNode = rgNodeList.RemoveHead();
                    if(pNode)
                        hr = pNode->OnCancelLabelEdit();
                    break;
                default:
                    hr = OLECMDERR_E_NOTSUPPORTED;
                    break;
            }
        }
        else
        {   // Pass command to nodes Exec command
            hr = ExecSelection(pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut, rgNodeList, TRUE);

        }
        return hr;

    }   
    // VSITEMID2Node will fail if the node is not in our hierarchy. This is an expected condition for 
    // nested projects. Return OLECMDERR_E_NOTSUPPORTED here so that shell knows to pass on the command
    // to next hierarchy in chain
    return OLECMDERR_E_NOTSUPPORTED;
}

//---------------------------------------------------------------------------
// interface: IVsUIHierarchy
// Called to update status on a command
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::QueryStatusCommand(
            /* [in] */ VSITEMID itemid,
            /* [unique][in] */ const GUID __RPC_FAR *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [size_is][out][in] */ OLECMD __RPC_FAR prgCmds[  ],
            /* [unique][out][in] */ OLECMDTEXT __RPC_FAR *pCmdText)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Fail if hierarchy already closed
    RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED

    HierNodeList rgNodeList;
    HRESULT hr = VSITEMID2Node(itemid, rgNodeList);

    if (SUCCEEDED(hr))
    {
        hr = QueryStatusSelection(pguidCmdGroup, cCmds, prgCmds, pCmdText, rgNodeList, TRUE);
    }
    else
    {
        // Its safer to return OLECMDERR_E_NOTSUPPORTED to shell rather than return failure
        // indicating that we actually handle the command.
        hr = OLECMDERR_E_NOTSUPPORTED;
    }
    return hr;  // asserts are in VSITEMID2Node
}

//---------------------------------------------------------------------------
// interface: IVsPersistHierarchyItem
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::IsItemDirty(
        /* [in] */ VSITEMID,    //vsid,
        /* [in] */ IUnknown *punkDocData,
        /* [out] */ BOOL *pfDirty)
{
    if (!punkDocData)
        return E_INVALIDARG;
    if (!pfDirty)
        return E_INVALIDARG;
    *pfDirty = FALSE;

    CComPtr<IVsPersistDocData> srpPersistDocData;
    HRESULT hr = punkDocData->QueryInterface(IID_IVsPersistDocData, (void**)&srpPersistDocData);

    if(SUCCEEDED(hr))
    {
        hr = srpPersistDocData->IsDocDataDirty(pfDirty);
    }

    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsPersistHierarchyItem
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::SaveItem(
        /* [in] */ VSSAVEFLAGS dwSave,
        /* [in] */ LPCOLESTR pszSilentSaveAsName,
        /* [in] */ VSITEMID itemid, 
        /* [in] */ IUnknown *punkDocData,
        /* [out] */ BOOL *pfCanceled)
{
    if (!pfCanceled)
        return E_INVALIDARG;
    *pfCanceled = FALSE;

    // validate itemid.
    CHierNode *pNode = NULL;
    if (itemid == VSITEMID_ROOT || itemid == VSITEMID_SELECTION || FAILED(VSITEMID2Node(itemid, &pNode)))
    {
        ASSERT(itemid != VSITEMID_ROOT && itemid != VSITEMID_SELECTION);
        ASSERT(SUCCEEDED(VSITEMID2Node(itemid, &pNode)));
        return E_INVALIDARG;
    }

    if (!punkDocData)
        return OLE_E_NOTRUNNING;    // we can only perform save if the document is open

    CComBSTR bstrMkDocumentNew;
    HRESULT hr = E_FAIL;

    if (VSSAVE_SilentSave & dwSave)
    {
        CComPtr<IPersistFileFormat> srpFileFormat;
        if ((SUCCEEDED(punkDocData->QueryInterface(IID_IPersistFileFormat ,
            (void **)&srpFileFormat))) && (srpFileFormat != NULL))
        {
            IVsUIShell *pIVsUIShell = _VxModule.GetVsUIShell(); // non-addref'ed
            ASSERT(NULL != pIVsUIShell);
            hr = pIVsUIShell->SaveDocDataToFile(VSSAVE_SilentSave, srpFileFormat, pszSilentSaveAsName, &bstrMkDocumentNew, pfCanceled);
        }       
    }
    else
    {
        CComPtr<IVsPersistDocData> srpPersistDocData;
        if ((SUCCEEDED(punkDocData->QueryInterface(IID_IVsPersistDocData,
            (void **)&srpPersistDocData))) && (srpPersistDocData != NULL))
        {
            hr = srpPersistDocData->SaveDocData(dwSave, &bstrMkDocumentNew, pfCanceled);
        }
    }

    // if a SaveAs occurred we need to update to the fact our item's name has changed.
    // this includes the following:
    //      1. call RenameDocument on the RunningDocumentTable
    //      2. update the full path name for the item in our hierarchy
    //      3. a directory-based project may need to transfer the open editor to the
    //         MiscFiles project if the new file is saved outside of the project directory.
    //         This is accomplished by calling IVsExternalFilesManager::TransferDocument
    // This work can not be done by CVsHierarchy::SaveItem; this must be done in a 
    // derived subclass implementation of OnHandleSaveItemRename.
    if ((!*pfCanceled) && bstrMkDocumentNew != NULL)
        hr = OnHandleSaveItemRename(itemid, punkDocData, bstrMkDocumentNew);

    return hr;
}

//---------------------------------------------------------------------------
// interface: IPkgDropDataSource
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::GetDropInfo(
            /* [out] */ DWORD *pdwOKEffects,
            /* [out] */ IDataObject **ppDataObject,
            /* [out] */ IDropSource **pDropSource)
{
    if (NULL != pdwOKEffects && NULL != ppDataObject && NULL != pDropSource)
    {
        *pdwOKEffects = DROPEFFECT_NONE;
        *ppDataObject = NULL;
        *pDropSource  = NULL;

        ATLTRACE(_T("CVsHierarchy:(%s):GetDropInfo() not implemented.\n"), GetRootNode()->GetName());
        return E_NOTIMPL;
    }
    ASSERT(NULL != pdwOKEffects && NULL != ppDataObject && NULL != pDropSource);
    return E_INVALIDARG;
}

//---------------------------------------------------------------------------
// interface: IPkgDropDataSource
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::OnDropNotify(
            /* [in] */ BOOL fDropped,
            /* [in] */ DWORD dwEffects)
{
    ASSERT(g_bStartedDrag); // ASSERT that a drag is in progress
    g_bStartedDrag = FALSE;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface: IPkgDropDataTarget, helper routine
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::DragEnter(
            /* [in] */ IDataObject *pDataObj)
{
    ASSERT(NULL != pDataObj);
    ATLTRACE(_T("CVsHierarchy:(%s):OnDragEnter() not implemented.\n"), GetRootNode()->GetName());
    return E_NOTIMPL;
}

//---------------------------------------------------------------------------
// interface: IPkgDropDataTarget
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::DragEnter(
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ VSITEMID itemid,
            /* [out] */ DWORD *pdwEffect)
{
    HRESULT hr = E_INVALIDARG;
    if (NULL != pdwEffect)
    {
        *pdwEffect = DROPEFFECT_NONE;
        if (NULL != pDataObj)
        {
            CHierNode *pNode = NULL;
            hr = VSITEMID2Node(itemid, &pNode);
            if (SUCCEEDED(hr))
            {
                hr = DragEnter(pDataObj);
                if (SUCCEEDED(hr))
                {
                    hr = DragOver(grfKeyState, pNode, pdwEffect);
                }
            }
        }
        ASSERT(NULL != pDataObj);
    }
    ASSERT(NULL != pdwEffect);
    return hr;
}

//---------------------------------------------------------------------------
// interface: IPkgDropDataTarget, helper routine
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::DragOver(
            /* [in] */ DWORD grfKeyState,
            /* [in] */ CHierNode *pNode,
            /* [out] */ DWORD *pdwEffect)
{
    ASSERT(NULL != pNode);
    ASSERT(NULL != pdwEffect && DROPEFFECT_NONE == *pdwEffect);

    ATLTRACE(_T("CVsHierarchy:(%s)(%s):OnDragOver() not implemented.\n"), GetRootNode()->GetName(), pNode->GetName());
    return E_NOTIMPL;
}

//---------------------------------------------------------------------------
// interface: IPkgDropDataTarget
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::DragOver(
            /* [in] */ DWORD grfKeyState,
            /* [in] */ VSITEMID itemid,
            /* [out] */ DWORD *pdwEffect)
{
    HRESULT hr = E_INVALIDARG;

    ASSERT(NULL != pdwEffect);
    if (NULL != pdwEffect)
    {
        *pdwEffect = DROPEFFECT_NONE;

        CHierNode *pNode = NULL;
        hr = VSITEMID2Node(itemid, &pNode);
        if (SUCCEEDED(hr))
        {
            ASSERT(NULL != pNode);
            hr = DragOver(grfKeyState, pNode, pdwEffect);
        }
    }
    return hr;
}

//---------------------------------------------------------------------------
// interface: IPkgDropDataTarget
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::DragLeave(void)
{
    ATLTRACE(_T("CVsHierarchy:(%s):OnDragLeave() not implemented.\n"), GetRootNode()->GetName());
    return E_NOTIMPL;
}

//---------------------------------------------------------------------------
// interface: IPkgDropDataTarget
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::Drop(
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ CHierNode *pNode,
            /* [out] */ DWORD *pdwEffect)
{
    ASSERT(NULL != pDataObj && NULL != pNode);
    ASSERT(NULL != pdwEffect && DROPEFFECT_NONE == *pdwEffect);

    ATLTRACE(_T("CVsHierarchy:(%s)(%s):OnDrop() not implemented.\n"), GetRootNode()->GetName(), pNode->GetName());
    return E_NOTIMPL;
}

//---------------------------------------------------------------------------
// interface: IPkgDropDataTarget
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::Drop(
            /* [in] */ IDataObject *pDataObj,
            /* [in] */ DWORD grfKeyState,
            /* [in] */ VSITEMID itemid,
            /* [out] */ DWORD *pdwEffect)
{
    HRESULT hr = E_INVALIDARG;
    if (NULL != pdwEffect)
    {
        *pdwEffect = DROPEFFECT_NONE;
        if (NULL != pDataObj)
        {
            CHierNode *pNode = NULL;
            hr = VSITEMID2Node(itemid, &pNode);
            if (SUCCEEDED(hr))
            {
                ASSERT(NULL != pNode);
                hr = Drop(pDataObj, grfKeyState, pNode, pdwEffect);
            }
        }
        ASSERT(NULL != pDataObj);
    }
    ASSERT(NULL != pdwEffect);
    return hr;
}

//---------------------------------------------------------------------------
// interface: IOleCommandTarget
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::QueryStatus(
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [out][in][size_is] */ OLECMD prgCmds[  ],
            /* [unique][out][in] */ OLECMDTEXT *pCmdText)
{
    HRESULT hr;
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Fail if hierarchy already closed
    RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED

        
    if (NULL == pguidCmdGroup)
    {
        hr = OLECMDERR_E_UNKNOWNGROUP;
    }
    else 
    {
        HierNodeList rgNodes;
        hr = GetSelectedNodes(rgNodes);
        if (SUCCEEDED(hr) && !rgNodes.IsEmpty())
        {
            hr = QueryStatusSelection(pguidCmdGroup, cCmds, prgCmds, pCmdText, rgNodes, g_bInContextMenu);
        }
        else
        {
            // Its safer to return OLECMDERR_E_NOTSUPPORTED to shell rather than return failure
            // indicating that we actually handle the command.
            hr = OLECMDERR_E_NOTSUPPORTED;
        }
    }

    return hr;
}

//---------------------------------------------------------------------------
// interface: IOleCommandTarget
//---------------------------------------------------------------------------
STDMETHODIMP CVsHierarchy::Exec(
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ DWORD nCmdID,
            /* [in] */ DWORD nCmdexecopt,
            /* [unique][in] */ VARIANT *pvaIn,
            /* [unique][out][in] */ VARIANT *pvaOut)
{
    HRESULT hr;
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Fail if hierarchy already closed
    RETURN_E_UNEXPECTED_IF_HIERARCHY_CLOSED

    if(NULL == pguidCmdGroup)
    {
        hr = OLECMDERR_E_UNKNOWNGROUP;
    }
    else
    {
        HierNodeList rgNodes;
        hr = GetSelectedNodes(rgNodes);
        if (SUCCEEDED(hr) && !rgNodes.IsEmpty())
        {
            hr = ExecSelection(pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut, rgNodes, g_bInContextMenu);
        }
        else
        {
            // Its safer to return OLECMDERR_E_NOTSUPPORTED to shell rather than return failure
            // indicating that we actually handle the command.
            hr = OLECMDERR_E_NOTSUPPORTED;
        }
    }
    return hr;
}

//-----------------------------------------------------------------------------
// CVsHierarchy::DisplayContextMenu
//-----------------------------------------------------------------------------
HRESULT CVsHierarchy::DisplayContextMenu(HierNodeList &rgSelection)
{
    return S_OK;
}

//-----------------------------------------------------------------------------
// CWebArchy::QueryStatusSelection
//-----------------------------------------------------------------------------
HRESULT CVsHierarchy::QueryStatusSelection(
    const GUID *pguidCmdGroup,
    ULONG cCmds,
    OLECMD prgCmds[],
    OLECMDTEXT *pCmdText,
    HierNodeList &rgSelection,
    BOOL          bIsHierCmd)

{
    return OLECMDERR_E_NOTSUPPORTED;
}

//-----------------------------------------------------------------------------
// CWebArchy::ExecSelection
//-----------------------------------------------------------------------------
HRESULT CVsHierarchy::ExecSelection(
    const GUID *pguidCmdGroup,
    DWORD nCmdID,
    DWORD nCmdexecopt,
    VARIANT *pvaIn,
    VARIANT *pvaOut,
    HierNodeList &rgSelection,
    BOOL          bIsHierCmd)
{
    return OLECMDERR_E_NOTSUPPORTED;
}

//---------------------------------------------------------------------------
// call OnItemAdded for each listed IVsHierarchyEvent sink
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::OnItemAdded(CHierNode *pNodeParent, CHierNode *pNodePrev, CHierNode *pNodeAdded) const
{
    ASSERT(NULL != pNodeParent && NULL != pNodeAdded);
    VSITEMID itemidParent = pNodeParent->GetVsItemID();
    VSITEMID itemidSiblingPrev = (NULL != pNodePrev) ? pNodePrev->GetVsItemID(): VSITEMID_NIL;
    VSITEMID itemidAdded = pNodeAdded->GetVsItemID();

    for (int i = 0; i < m_hierEventAdvises.GetCount(); ++i)
    {
        HRESULT hr = m_hierEventAdvises.GetAdviseSink(i)->OnItemAdded(itemidParent, itemidSiblingPrev, itemidAdded);
        ASSERT(SUCCEEDED(hr) || OLE_E_PROMPTSAVECANCELLED == hr);
        hr;
    }
    return S_OK;
}

//---------------------------------------------------------------------------
// call OnItemDeleted for each listed IVsHierarchyEvent sink
//
// ASSUMPTION: pNode may be in the middle of the destructor
//             but CHierNode::GetVsItemID okay to call
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::OnItemDeleted(CHierNode *pNode) const
{
    if(m_hierEventAdvises.GetCount() != 0)
    {
        VSITEMID itemid = pNode->GetVsItemID();
        // Note that in some cases (deletion of project node for example), an Advise
        // may be removed while we are iterating over it. To get around this problem we
        // take a snapshot of the advise list and walk that.
        int n = m_hierEventAdvises.GetCount();
        IVsHierarchyEvents** pEventSinks = new IVsHierarchyEvents*[n];

        if(!pEventSinks)
            return E_OUTOFMEMORY;

        for (int i = 0; i < n; ++i)
        {
            pEventSinks[i] = m_hierEventAdvises.GetAdviseSink(i);
        }

        for (i = 0; i < n; ++i)
        {
            HRESULT hr = pEventSinks[i]->OnItemDeleted(itemid);
            ASSERT(SUCCEEDED(hr));
            hr;
        }
        delete [] pEventSinks;
    }
    return S_OK;
}

//---------------------------------------------------------------------------
// call OnPropertyChanged for each listed IVsHierarchyEvent sink
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::OnPropertyChanged(CHierNode *pNode, VSHPROPID propid, DWORD flags) const
{
    VSITEMID itemid;

    if (pNode->IsDisplayable()) {
        itemid = pNode->GetVsItemID();
        for (int i = 0; i < m_hierEventAdvises.GetCount(); ++i)
        {
            HRESULT hr = m_hierEventAdvises.GetAdviseSink(i)->OnPropertyChanged(itemid, propid, flags);
            // Prevent warning about unused hr.
            hr;
        }
    }
    
    return S_OK;
}

//---------------------------------------------------------------------------
// call OnInvalidateItems for each listed IVsHierarchyEvent sink
//
// ASSUMPTION: pNode may be in the middle of the destructor
//             but CHierNode::GetVsItemID okay to call
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::OnInvalidateItems(CHierNode *pNode) const
{
    VSITEMID itemid = pNode->GetVsItemID();

    for (int i = 0; i < m_hierEventAdvises.GetCount(); ++i)
    {
        HRESULT hr = m_hierEventAdvises.GetAdviseSink(i)->OnInvalidateItems(itemid);
        ASSERT(SUCCEEDED(hr));
        hr;
    }
    return S_OK;
}

//---------------------------------------------------------------------------
// call OnInvalidateIcon for each listed IVsHierarchyEvent sink
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::OnInvalidateIcon(HICON hIcon) const
{

    for (int i = 0; i < m_hierEventAdvises.GetCount(); ++i)
    {
        HRESULT hr = m_hierEventAdvises.GetAdviseSink(i)->OnInvalidateIcon(hIcon);
        ASSERT(SUCCEEDED(hr));
        hr;
    }
    return S_OK;
}

//---------------------------------------------------------------------------
// Returns the itemid of the first displayable node under pNode
//---------------------------------------------------------------------------
VSITEMID CVsHierarchy::GetFirstDisplayableNode(CHierNode* pNode)
{
    return pNode->GetFirstChild(TRUE);
}

//---------------------------------------------------------------------------
// Returns the itemid of the next displayable node after pNode
//---------------------------------------------------------------------------
VSITEMID CVsHierarchy::GetNextDisplayableNode(CHierNode* pNode)
{
    return pNode->GetNext()? pNode->GetNext()->GetVsItemID() : VSITEMID_NIL;
}

//---------------------------------------------------------------------------
// Returns the previous displayable node for pNode. Note that pNode MUST be 
// displayable.
//---------------------------------------------------------------------------
CHierNode* CVsHierarchy::GetPrevDisplayableNode(CHierNode* pNode)
{
    ASSERT(pNode->IsDisplayable());
    return pNode->GetParent()->GetPrevChildOf(pNode);
}

//---------------------------------------------------------------------------
// converts an VSITEMID to a CHierNode *
// returns:
//      S_OK
//      E_FAIL              (NIL, SELECTED, FOCUSED)
//      E_INVALIDARG        (itemid == 0)
//      E_UNEXPECTED        (zombie state)
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::VSITEMID2Node(const VSITEMID itemid, CHierNode **ppNode) const
{
    ASSERT(ppNode != NULL);
    *ppNode = NULL;

    if (m_pRootNode != NULL)        // zombie check/assert
    {
        switch (itemid)
        {
            case VSITEMID_NIL:
                ASSERT(!_T("error: known invalid VSITEMID"));
                return E_FAIL;

            case VSITEMID_ROOT:
                *ppNode = GetRootNode();
                break;

            case VSITEMID_SELECTION:
                ASSERT(!_T("error: Hierarchy illegaly called with VSITEMID_SELECTION"));
                return E_UNEXPECTED;

            default:
                if(!CHierNode::IsValidCHierNode(itemid))
                {
                    ASSERT(FALSE);
                    return E_FAIL;
                }
                *ppNode = reinterpret_cast<CHierNode *>(itemid);

                ASSERT(NULL != *ppNode);
	            if( (*ppNode) == NULL )
	            {
                        return E_FAIL;
	            }
	        
                if (NULL == (*ppNode)->GetParent())
                {   // The node mostly like has been OnItemDelete'd
                    ATLTRACE(_T("ERROR: invalid VSITEMID -> CHierNode\n"));
                    return E_FAIL;
                }
        }
        if (*ppNode != NULL)
        {
            ASSERT((*ppNode)->GetVsItemID() == itemid);
            return S_OK;
        }
        ASSERT(*ppNode != NULL);
        return E_INVALIDARG;
    }
    return E_UNEXPECTED;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::VSITEMID2Node(const VSITEMID itemid, HierNodeList& rgNodeList) const
{
    HRESULT hr;
    if (VSITEMID_SELECTION != itemid)
    {
        CHierNode *pNode = NULL;
        hr = VSITEMID2Node(itemid, &pNode);
        if (SUCCEEDED(hr))
        {
            rgNodeList.AddHead(pNode);
        }
    }
    else
    {
        hr = GetSelectedNodes(rgNodeList);
        if(SUCCEEDED(hr) && rgNodeList.IsEmpty())
            hr = E_UNEXPECTED;
    }
    return hr;
}

//---------------------------------------------------------------------------
// fill out an array of selected nodes
//---------------------------------------------------------------------------
HRESULT CVsHierarchy::GetSelectedNodes(HierNodeList& rgNodes) const
{
    CComPtr<IVsMonitorSelection> srpMonSel;
    _VxModule.QueryService(SID_SVsShellMonitorSelection, IID_IVsMonitorSelection, (void **)&srpMonSel);
    ASSERT(srpMonSel != NULL);

    HRESULT hr;
    VSITEMID itemid;                        // if VSITEMID_SELECTION then multiselection
    CHierNode *pNode = NULL;
    CComPtr<IVsHierarchy> srpIVsHierarchy;  // if NULL then selection spans VsHierarchies
    CComPtr<IVsMultiItemSelect> srpIVsMultiItemSelect;
    CComPtr<ISelectionContainer> srpISelectionContainer;        // unused?

    IfErrGo(srpMonSel->GetCurrentSelection(&srpIVsHierarchy, &itemid, &srpIVsMultiItemSelect, &srpISelectionContainer));

    if (VSITEMID_NIL == itemid)
    {   // nothing selected
        ASSERT(SUCCEEDED(hr));
    }
    else if (VSITEMID_SELECTION != itemid)
    {   // Single selection. Note that callers of this function, may try to get the
        // selection when we aren't the active hierarchy - for this reason we need
        // to validate that the selected item belongs to us.
        if(srpIVsHierarchy == GetIVsHierarchy())
        {
            hr = VSITEMID2Node(itemid, &pNode);
            if (SUCCEEDED(hr))
            {
                rgNodes.AddHead(pNode);
            }
            else
            {
                //ASSERT(FALSE);
                ATLTRACE(_T("ERROR: invalid VSITEMID in selection\n"));
            }
        }
    }
    else if (srpIVsMultiItemSelect != NULL)
    {
        ULONG cItems = 0;
        BOOL  fSingleHierarchy = TRUE;
        hr = srpIVsMultiItemSelect->GetSelectionInfo(&cItems, &fSingleHierarchy);
        if (SUCCEEDED(hr))
        {
            ASSERT(0 < cItems); // nothing selected should already be filtered out
            if(!fSingleHierarchy || (fSingleHierarchy && srpIVsHierarchy == GetIVsHierarchy()))
            {
                VSITEMSELECTION *pItemSel = new VSITEMSELECTION[cItems];
                if (NULL != pItemSel)
                {
                    VSGSIFLAGS fFlags = (fSingleHierarchy) ? GSI_fOmitHierPtrs : static_cast<VSGSIFLAGS>(0);
                    hr = srpIVsMultiItemSelect->GetSelectedItems(fFlags, cItems, pItemSel);
                    if (SUCCEEDED(hr))
                    {
                        ULONG i;
                        for (i = 0; i < cItems; ++i)
                        {
                            if (fSingleHierarchy || pItemSel[i].pHier == GetIVsHierarchy() )
                            {
                                hr = VSITEMID2Node(pItemSel[i].itemid, &pNode);
                                if (SUCCEEDED(hr))
                                {
                                    rgNodes.AddTail(pNode);
                                    // Needs to be reset for multi-sel
                                    pNode = NULL;
                                }
                                else
                                {   // why is there an invalid itemid?
                                    ASSERT(SUCCEEDED(hr));
                                    break;
                                }
                            }
                        }
                        if (!fSingleHierarchy)
                        {   // release all the hierarchies
                            for (i = 0; i < cItems; ++i)
                            {
                                if (NULL != pItemSel[i].pHier)
                                    pItemSel[i].pHier->Release();
                            }
                        }
                    }
                }
                else
                {
                    hr = E_OUTOFMEMORY;
                }
                delete[] pItemSel;
            }
        }
    }
    else
    {
        ASSERT(srpIVsMultiItemSelect != NULL);
        hr = E_UNEXPECTED;
    }

ERROR_EXIT:
    return hr;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
DWORD UtilReduceSelection(HierNodeList &rgSelection)
{
    DWORD dwTotal = 0UL;
    HierNodeList rgReduced;
    while (!rgSelection.IsEmpty())
    {
        CHierNode *pNode = rgSelection.RemoveHead();
        ASSERT(NULL != pNode);

        if (NULL == pNode->GetParent())
        {   // special case the root node
            rgSelection.RemoveAll();
            rgReduced.RemoveAll();
            rgReduced.AddHead(pNode);
            dwTotal = 1UL;
            break;
        }

        POSITION pos = rgSelection.GetHeadPosition();
        while (NULL != pos)
        {
            POSITION prev = pos;
            CHierNode *pTestNode = rgSelection.GetNext(pos);
            ASSERT(NULL != pTestNode);
            ASSERT(pNode != pTestNode); // same node appears twice in selection

            if (pNode->HasAncestor(pTestNode))
            {   // don't add pNode to the rgReduced list
                pNode = NULL;
                break;
            }
            else if (pTestNode->HasAncestor(pNode))
            {
                ASSERT(NULL != prev);
                rgSelection.RemoveAt(prev);
            }
        }
        if (NULL != pNode)
        {
            rgReduced.AddHead(pNode);
            dwTotal++;
        }
    }
    while (!rgReduced.IsEmpty())
    {   // direction was reversed
        CHierNode *pNode = rgReduced.RemoveHead();
        rgSelection.AddHead(pNode);
    }
    return dwTotal;
}

// End of hu_archy.cpp
