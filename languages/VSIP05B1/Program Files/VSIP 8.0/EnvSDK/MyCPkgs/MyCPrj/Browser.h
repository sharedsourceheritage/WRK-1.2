
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Browser.h: 
//
//////////////////////////////////////////////////////////////////////

#pragma once

class ILibraryItem;

class CBrowseCounter
{

public:
    CBrowseCounter();

    virtual ~CBrowseCounter();

    STDMETHOD(ResetChanges)();

    STDMETHOD(Increment)(
        /* [in] */  VSTREELISTITEMCHANGE listChanges);

    STDMETHOD(UpdateCounter)(
        /* [out] */ ULONG *                 puCurUpdate,  
        /* [out] */ VSTREEITEMCHANGESMASK * pgrfChanges);

    STDMETHOD(GetListChanges)(
        /*[in,out]                 */ ULONG *                pcChanges, 
        /*[in, size_is(*pcChanges)]*/ VSTREELISTITEMCHANGE * prgListChanges);

protected:
    ULONG m_uCounter;
    ULONG m_cChanges;
    BOOL  m_fIsCounterDirty;
    VSTREELISTITEMCHANGE m_listChanges;   
};


typedef enum
{
    BNT_PHYSICALCONTAINER  = 1,
    BNT_CLASS      = 2,
    BNT_FUNCTION   = 3,
    BNT_VARIABLE   = 4,

} BROWSE_NODE_TYPE;

#define NULINDEX (ULONG)(-1)

class CBrowseNode 
{
public:

    static HRESULT CreateInstance(
            /* [in] */ ILibraryItem*    pILibraryItem,
            /* [in] */ BSTR             bstrName,
            /* [in] */ BROWSE_NODE_TYPE eType,
            /* [in] */ VSITEMID         itemId,
            /* [in] */ ULONG            uLineNumber,
            /* [out]*/ CBrowseNode **   ppCBrowseNode);

    virtual ~CBrowseNode();

protected:
    CBrowseNode(); 
    STDMETHOD(Init)(
        /* [in] */ ILibraryItem*    pILibraryItem,
        /* [in] */ BSTR             bstrName,
        /* [in] */ BROWSE_NODE_TYPE eType,
        /* [in] */ VSITEMID         itemId,
        /* [in] */ ULONG            uLineNumber);

public:
    STDMETHOD(GetLibraryItem)(
        /* [out] */ ILibraryItem** ppILibraryItem);

    STDMETHOD(GetItemId)(
        /* [out]  */ VSITEMID* pitemId);

    // Get a pointer to the main text for the list
    // Used by IVsLiteTreeList::GetText implementation
    STDMETHOD(GetText)(
        /* [in]  */ VSTREETEXTOPTIONS tto, 
        /* [out] */ const WCHAR **    ppszText);

    // Used by IVsLiteTreeList::GetTipText implementation
    STDMETHOD(GetTipText)(
        /* [in]  */ VSTREETOOLTIPTYPE eTipType, 
        /* [out] */ const WCHAR ** ppszText);

    // Retrieve information to draw the item
    // Used by IVsLiteTreeList::GetDisplayData implementation
    STDMETHOD(GetDisplayData)(
        /* [out] */ VSTREEDISPLAYDATA * pData);


    STDMETHOD(GetNavigationInfo)(
        /* [in, out]*/ VSOBNAVIGATIONINFO2 * pobNav);

    STDMETHOD(GetSourceContext)(
        /* [out] */ const WCHAR **pszFileName, 
        /* [out] */ ULONG *pulLineNum);

    // Returns the count of itemids (these must be from a single hierarchy) 
    // that make up the source files for the  element. 
    // Also returns the hierarchy ptr and itemid if requested.
    // If there are >1 itemids, return VSITEMID_SELECTION and a subsequent call 
    // will be made on GetMultipleSourceItems to get them. 
    // If there are no available source items, return
    // VSITEMID_ROOT to indicate the root of the hierarchy as a whole.
    STDMETHOD(CountSourceItems)(
        /* [out] */ IVsHierarchy **ppHier, 
        /* [out] */ VSITEMID *pitemid, 
        /*[out, retval]*/ ULONG *pcItems);

    // Called to cause navigation to the source (definition or declration) for the
    // item Index. You must must coordinate with the project system to open the
    // source file and navigate it to the approp. line. Return S_OK on success or an
    // hr error (along with rich error info if possible) if the navigation failed.
    STDMETHOD(GoToSource)(
        /* [in]  */ VSOBJGOTOSRCTYPE eSrcType);

    STDMETHOD(FillDescription)(
        /* [in]  */ IVsObjectBrowserDescription2 *pobDesc);

    STDMETHOD(GetCategoryField)(
        /* [in]  */ LIB_CATEGORY    eCategory, 
        /*[out,retval]*/ DWORD*     pField); 

    STDMETHOD(UpdateName)(
            /* [in] */ BSTR bstrName);

protected:
    STDMETHOD(GetGlyphIndexFromType)(
        USHORT* pBmpIndex);

    STDMETHOD(GetDisplayStateFromType)(
        VSTREEDISPLAYSTATE * pState);


protected:
    ILibraryItem*    m_pILibraryItem;    
    CComBSTR         m_cbstrName;            // node name
    BROWSE_NODE_TYPE m_eType;                // type
    VSITEMID         m_itemId;               // itemid    
    ULONG            m_uLineNumber;          // line number
};


class IBrowseDataProviderEvents :
    public IUnknown
{
public:

    STDMETHOD(OnBrowseDataAdded)(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode) = 0;

    STDMETHOD(OnBrowseDataRemoved)(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode) = 0;

    STDMETHOD(OnBrowseDataPropertyChanged)(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode) = 0;
};

typedef CVxTypedPtrArray<CVxPtrArray, CBrowseNode*> BrowseNodeArray;

class IBrowseDataProvider :
    public IUnknown
{
public:
    STDMETHOD(AddBrowseNodesToArray)(
        /* [in]      */ LIB_LISTTYPE         eListType, 
        /* [in,out]  */ BrowseNodeArray*     pBrowseNode) = 0;

    STDMETHOD(AdviseBrowseDataProviderEvents)(
        /* [in]   */ IBrowseDataProviderEvents* pIBrowseDataProviderEvents, 
        /* [out]  */ VSCOOKIE *    pdwCookie) = 0;

    STDMETHOD(UnadviseBrowseDataProviderEvents)(
        /* [in]  */ VSCOOKIE     dwCookie) = 0;
};

struct BrowseDataProviderEventsNode
{
    BrowseDataProviderEventsNode *pPrev;
    IBrowseDataProviderEvents *pbdpe;
    BrowseDataProviderEventsNode *pNext;
};

class IBrowseDataProviderImpl :
    public IBrowseDataProvider
{

public:
    IBrowseDataProviderImpl();
    virtual ~IBrowseDataProviderImpl();

    STDMETHOD(AdviseBrowseDataProviderEvents)(
        /* [in]   */ IBrowseDataProviderEvents* pIBrowseDataProviderEvents, 
        /* [out]  */ VSCOOKIE *    pdwCookie);

    STDMETHOD(UnadviseBrowseDataProviderEvents)(
        /* [in]  */ VSCOOKIE     dwCookie);

    STDMETHOD(NotifyOnBrowseDataAdded)(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode);

    STDMETHOD(NotifyOnBrowseDataRemoved)(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode);

    STDMETHOD(NotifyOnBrowseDataPropertyChanged)(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode);
protected:
    // event advises
    CVsAdviseList<IBrowseDataProviderEvents>    m_alBrowseDataProviderEvents;
};


class ILibraryItem :
    public IUnknown
{
public:
    STDMETHOD(Close)() = 0;

    STDMETHOD(GetHierarchy)(
            /* [out]  */ IVsHierarchy **  ppIVsHierarchy) = 0;

    // Used by IVsLiteTreeList::ToggleState implementation
    STDMETHOD(ToggleState)() = 0 ;

    STDMETHOD(GetCheckState)(
        /* [out] */ LIB_CHECKSTATE *pstate) = 0 ;

    // Get a pointer to the main text for the list
    STDMETHOD(GetText)(
        /* [in]  */ VSTREETEXTOPTIONS tto, 
        /* [out] */ const WCHAR **    ppszText) = 0;

};

class CLibraryItem : 
    public ILibraryItem,
    public IBrowseDataProviderImpl,
    public IVsHierarchyEvents,
    public CBrowseNode,
    public CComObjectRoot 
{

    BEGIN_COM_MAP(CLibraryItem)
        COM_INTERFACE_ENTRY(ILibraryItem)
        COM_INTERFACE_ENTRY(IBrowseDataProvider)
        COM_INTERFACE_ENTRY(IVsHierarchyEvents)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CLibraryItem)

//==========================================================================
//                                                construct, init , destruct
public:

    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              To create an CLibraryItem object 
    // Parameters: 
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CLibraryItem::CreateInstance(
            /* [in]  */ IVsLibrary*    pIVsLibrary,
            /* [in]  */ IVsHierarchy*  pIVsHierarchy,
            /* [out] */ CComObject<CLibraryItem> ** ppCLibraryItem);

protected:
    CLibraryItem(); 
    STDMETHOD(Init)(
            /* [in]  */ IVsLibrary*    pIVsLibrary,
            /* [in]  */ IVsHierarchy*  pIVsHierarchy);

    ~CLibraryItem();

//                                                construct, init , destruct
//==========================================================================

//==========================================================================
//                                                              ILibraryItem

public:
    STDMETHOD(Close)();

    STDMETHOD(GetHierarchy)(
            /* [out]  */ IVsHierarchy **  ppIVsHierarchy);

    // Used by IVsLiteTreeList::ToggleState implementation
    STDMETHOD(ToggleState)();

    STDMETHOD(GetCheckState)(
        /* [out] */ LIB_CHECKSTATE *pstate);

    // Get a pointer to the main text for the list
    // Used by IVsLiteTreeList::GetText implementation
    STDMETHOD(GetText)(
        /* [in]  */ VSTREETEXTOPTIONS tto, 
        /* [out] */ const WCHAR **    ppszText);

    // Retrieve information to draw the item
    // Used by IVsLiteTreeList::GetDisplayData implementation
    STDMETHOD(GetDisplayData)(
        /* [in]  */ BOOL fIsLibraryChecked,
        /* [out] */ VSTREEDISPLAYDATA * pData);

//                                                              ILibraryItem
//==========================================================================

//==========================================================================
//                                                       IBrowseDataProvider
public:

    STDMETHOD(AddBrowseNodesToArray)(
        /* [in]      */ LIB_LISTTYPE         eListType, 
        /* [in,out]  */ BrowseNodeArray*     pBrowseNodeArray);

//                                                       IBrowseDataProvider
//==========================================================================

//==========================================================================
//                                                        IVsHierarchyEvents
    STDMETHOD(OnItemAdded)(
        /* [in] */ VSITEMID itemidParent, 
        /* [in] */ VSITEMID itemidSiblingPrev, 
        /* [in] */ VSITEMID itemidAdded);

    STDMETHOD(OnItemsAppended)(
        /* [in] */ VSITEMID itemidParent);

    STDMETHOD(OnItemDeleted)(
        /* [in] */ VSITEMID itemid);

    STDMETHOD(OnPropertyChanged)(
        /* [in] */ VSITEMID itemid, 
        /* [in] */ VSHPROPID propid, 
        /* [in] */ DWORD flags); 

    STDMETHOD(OnInvalidateItems)(
        /* [in] */ VSITEMID itemidParent);

    STDMETHOD(OnInvalidateIcon)(
        /* [in] */ HICON hicon);

//                                                        IVsHierarchyEvents
//==========================================================================


protected:
    STDMETHOD_(ULONG, GetItemCount)();
    STDMETHOD(InitBrowseNodeArray)();
    STDMETHOD(IsFileMyc)(
        /* [in]  */ BSTR  bstrFileFullName,
        /* [out] */ BOOL* pfMycFile,
        /* [out] */ BSTR* pbstrDisplayName);


protected:
    CComPtr<IVsLibrary>   m_srpIVsLibrary;
    CComPtr<IVsHierarchy> m_srpIVsHierarchy;

    LIB_CHECKSTATE m_eCheckState;

    BrowseNodeArray m_rgpBrowseNode;
    BOOL  fIsBrowseNodeArrayInitialized;
    VSCOOKIE m_dwIVsHierarchyEventsCookie;    

};
