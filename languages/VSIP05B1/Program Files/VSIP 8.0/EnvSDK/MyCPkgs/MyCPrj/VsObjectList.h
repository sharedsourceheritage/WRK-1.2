
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsObjectList.h: interface for the CVsObjectList class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

class CVsObjectList : 
    public IVsObjectList,
    public IBrowseDataProviderEvents,
    public CComObjectRoot
{

BEGIN_COM_MAP(CVsObjectList)
    COM_INTERFACE_ENTRY(IVsObjectList)
END_COM_MAP()

//==========================================================================
//                                                construct, init , destruct

public:
    static HRESULT CreateInstance(
        /* [in]  */ IBrowseDataProvider* pIBrowseDataProvider, 
        /* [in]  */ IVsLibrary*          pIVsLibrary, 
        /* [in]  */ LIB_LISTTYPE         eListType, 
        /* [in]  */ LIB_LISTFLAGS        flags, 
        /* [in]  */ VSOBSEARCHCRITERIA * pobSrch, 
        /* [out] */ IVsObjectList **     ppList);

protected:
    CVsObjectList();
    STDMETHOD(Init)(
        /* [in]  */ IBrowseDataProvider* pIBrowseDataProvider, 
        /* [in]  */ IVsLibrary*          pIVsLibrary, 
        /* [in]  */ LIB_LISTTYPE         eListType, 
        /* [in]  */ LIB_LISTFLAGS        flags, 
        /* [in]  */ VSOBSEARCHCRITERIA * pobSrch); 

    virtual ~CVsObjectList();
    STDMETHOD(Close)();
    
    ULONG InternalRelease();

//                                                construct, init , destruct
//==========================================================================


//==========================================================================
//                                                            Common helpers

protected:
    //Check if this is a valid index
    STDMETHOD_(BOOL, IsValidIndex)(
        /* [in] */ ULONG uIndex);

//                                                            Common helpers
//==========================================================================


//==========================================================================
//                                                           IVsLiteTreeList
//
public:

    //Fetches VSTREEFLAGS
    STDMETHOD(GetFlags)(
        /* [out] */ VSTREEFLAGS *pFlags);

    //Count of items in this list
    STDMETHOD(GetItemCount)(
        /* [out] */ ULONG* pCount);
    
    //An item has been expanded, get the next list
    STDMETHOD(GetExpandedList)(
        /* [in]  */ ULONG              uIndex, 
        /* [out] */ BOOL *             pfCanRecurse, 
        /* [out] */ IVsLiteTreeList ** pptlNode);
    
    //Called during a ReAlign command if TF_CANTRELOCATE isn't set.  Return
    //E_FAIL if the list can't be located, in which case the list will be discarded.
    STDMETHOD(LocateExpandedList)(
        /* [in]  */ IVsLiteTreeList* pExpandedList, 
        /* [out] */ ULONG *          uIndex);
    
    //Called when a list is collapsed by the user.
    STDMETHOD(OnClose)(
        /* [out] */ VSTREECLOSEACTIONS *ptca);
    
    //Get a pointer to the main text for the list
    STDMETHOD(GetText)(
        /* [in]  */ ULONG             uIndex, 
        /* [in]  */ VSTREETEXTOPTIONS tto, 
        /* [out] */ const WCHAR **    ppszText);
    
    STDMETHOD(GetTipText)(
        /* [in]  */ ULONG          uIndex, 
        /* [in]  */ VSTREETOOLTIPTYPE eTipType, 
        /* [out] */ const WCHAR ** ppszText);
    
    //Is this item expandable?  Not called if TF_NOEXPANSION is set
    STDMETHOD(GetExpandable)(
        /* [in]  */ ULONG  uIndex, 
        /* [out] */ BOOL * pfExpandable);
    
    //Retrieve information to draw the item
    STDMETHOD(GetDisplayData)(
    /* [in]  */ ULONG               uIndex, 
    /* [out] */ VSTREEDISPLAYDATA * pData);
    
    //Return latest update increment.  True/False isn't sufficient here since
    //multiple trees may be using this list.  Returning an update counter > than
    //the last one cached by a given tree will force calls to GetItemCount and
    //LocateExpandedList as needed.
    STDMETHOD(UpdateCounter)(
    /* [out] */ ULONG *                 puCurUpdate,  
    /* [out] */ VSTREEITEMCHANGESMASK * pgrfChanges);
    
    // If prgListChanges is NULL, should return the # of changes in pcChanges. Otherwise
    // *pcChanges will indicate the size of the array (so that caller can allocate the array) to fill
    // with the VSTREELISTITEMCHANGE records
    STDMETHOD(GetListChanges)(
        /*[in,out]                 */ ULONG *                pcChanges, 
        /*[in, size_is(*pcChanges)]*/ VSTREELISTITEMCHANGE * prgListChanges);
    
    //Toggles the state of the given item (may be more than two states)
    STDMETHOD(ToggleState)(
    /* [in]  */ ULONG                      uIndex, 
    /* [out] */ VSTREESTATECHANGEREFRESH * ptscr);


//
//                                                           IVsLiteTreeList
//==========================================================================



//==========================================================================
//                                                             IVsObjectList
//
public:
    // Get list capabilities
    STDMETHOD(GetCapabilities)(
        /* [out] */  LIB_LISTCAPABILITIES *pCapabilities);

    // Get a sublist
    STDMETHOD(GetList)(
        /* [in]  */ ULONG                uIndex, 
        /* [in]  */ LIB_LISTTYPE         eListType, 
        /* [in]  */ LIB_LISTFLAGS        flags, 
        /* [in]  */ VSOBSEARCHCRITERIA * pobSrch, 
        /* [out] */ IVsObjectList **     ppList);
    
    STDMETHOD(GetCategoryField)(
        /* [in]  */ ULONG           uIndex, 
        /* [in]  */ LIB_CATEGORY    eCategory, 
        /*[out,retval]*/ DWORD*     pField); 

    STDMETHOD(GetExpandable2)(
        /* [in]  */ ULONG         uIndex, 
        /* [in]  */ LIB_LISTTYPE  ListTypeExcluded, 
        /* [out] */ BOOL *        pfExpandable);

    STDMETHOD(GetNavigationInfo)(
        /* [in]  */ ULONG                   uIndex, 
        /*[in, out]*/ VSOBNAVIGATIONINFO2 * pobNav);

    STDMETHOD(LocateNavigationInfo)(
        /* [in]  */ VSOBNAVIGATIONINFO2 *pobNav, 
        /* [in]  */ VSOBNAVNAMEINFONODE *pobName, 
        /* [in]  */ BOOL fDontUpdate, 
        /* [out] */ BOOL *pfMatchedName, 
        /* [out] */ ULONG *pIndex);

    STDMETHOD(GetBrowseObject)(
        /* [in]  */ ULONG uIndex, 
        /* [out] */ IDispatch **ppdispBrowseObj);

    STDMETHOD(GetUserContext)(
        /* [in]  */ ULONG uIndex, 
        /* [out] */ IUnknown **ppunkUserCtx);

    STDMETHOD(ShowHelp)(
        /* [in]  */ ULONG uIndex);

    STDMETHOD(GetSourceContext)(
        /* [in]  */ ULONG uIndex, 
        /* [out] */ const WCHAR **pszFileName, 
        /* [out] */ ULONG *pulLineNum);

    // Returns the count of itemids (these must be from a single hierarchy) that make up the source files
    // for the list element at Index. Also returns the hierarchy ptr and itemid if requested.
    // If there are >1 itemids, return VSITEMID_SELECTION and a subsequent call will be made
    // on GetMultipleSourceItems to get them. If there are no available source items, return
    // VSITEMID_ROOT to indicate the root of the hierarchy as a whole.
    STDMETHOD(CountSourceItems)(
        /* [in]  */ ULONG uIndex, 
        /* [out] */ IVsHierarchy **ppHier, 
        /* [out] */ VSITEMID *pitemid, 
        /*[out, retval]*/ ULONG *pcItems);

    // Used if CountSourceItems returns > 1. Details for filling up these out params are same 
    // as IVsMultiItemSelect::GetSelectedItems
    STDMETHOD(GetMultipleSourceItems)(
        /* [in]  */ ULONG uIndex, 
        /* [in]  */ VSGSIFLAGS grfGSI, 
        /* [in]  */ ULONG cItems, 
        /* [out, size_is(cItems)]*/ VSITEMSELECTION rgItemSel[]);

    // Return TRUE if navigation to source of the specified type (definition or declaration),
    // is possible, FALSE otherwise
    STDMETHOD(CanGoToSource)(
    /* [in]  */ ULONG            uIndex, 
    /* [in]  */ VSOBJGOTOSRCTYPE eSrcType, 
    /* [out] */ BOOL *           pfOK);

    // Called to cause navigation to the source (definition or declration) for the
    // item Index. You must must coordinate with the project system to open the
    // source file and navigate it to the approp. line. Return S_OK on success or an
    // hr error (along with rich error info if possible) if the navigation failed.
    STDMETHOD(GoToSource)(
        /* [in]  */ ULONG uIndex, 
        /* [in]  */ VSOBJGOTOSRCTYPE eSrcType);

    STDMETHOD(GetContextMenu)(
        /* [in]  */ ULONG uIndex, 
        /* [out] */ CLSID *pclsidActive, 
        /* [out] */ LONG *pnMenuId, 
        /* [out] */ IOleCommandTarget **ppCmdTrgtActive);
    
    STDMETHOD(QueryDragDrop)(
        /* [in]  */ ULONG uIndex, 
        /* [in]  */ IDataObject *pDataObject, 
        /* [in]  */ DWORD grfKeyState, 
        /*[in, out]*/DWORD * pdwEffect);

    STDMETHOD(DoDragDrop)(
        /* [in]  */ ULONG uIndex, 
        /* [in]  */ IDataObject * pDataObject, 
        /* [in]  */ DWORD grfKeyState, 
        /*[in, out]*/DWORD * pdwEffect);

    // Says whether the item Index can be renamed or not. If the passed in pszNewName is NULL,
    // it simply answers the general question of whether or not that item supports rename
    // (return TRUE or FALSE). If pszNewName is non-NULL, do validation of the new name
    // and return TRUE if successful rename with that new name is possible or an an error hr (along with FALSE)
    // if the name is somehow invalid (and set the rich error info to indicate to the user
    // what was wrong) 
    STDMETHOD(CanRename)(
        /* [in]  */ ULONG uIndex, 
        /* [in]  */ LPCOLESTR pszNewName, 
        /* [out] */ BOOL *pfOK);

    // Called when the user commits the Rename operation. Guaranteed that CanRename has already
    // been called with the newname so that you've had a chance to validate the name. If
    // Rename succeeds, return S_OK, other wise error hr (and set the rich error info)
    // indicating the problem encountered.
    STDMETHOD(DoRename)(
        /* [in]  */ ULONG uIndex, 
        /* [in]  */ LPCOLESTR pszNewName,
        /* [in]  */ VSOBJOPFLAGS grfFlags);

    // Says whether the item Index can be deleted or not. Return TRUE if it can, FALSE if not.
    STDMETHOD(CanDelete)(
        /* [in]  */ ULONG uIndex, 
        /* [out] */ BOOL *pfOK);

    // Called when the user asks to delete the item at Index. Will only happen if CanDelete on
    // the item previously returned TRUE. On a successful deletion this should return S_OK, if
    // the deletion failed, return the failure as an error hresult and set any pertinent error
    // info in the standard ole error info.
    STDMETHOD(DoDelete)(
        /* [in]  */ ULONG uIndex,
        /* [in]  */ VSOBJOPFLAGS grfFlags);

    STDMETHOD(FillDescription)(
        /* [in]  */ ULONG uIndex, 
        /* [in]  */ VSOBJDESCOPTIONS grfOptions, 
        /* [in]  */ IVsObjectBrowserDescription2 *pobDesc);

    // These three methods give the list a chance to provide clipboard formats for a drag-drop or 
    // copy/paste operation.
    // Caller first calls EnumClipboardFormats(index, flags, 0, NULL, &cExpected) to get the count
    // of clipboard formats the list is interested in providing, allocates an array of that size,
    // and then calls EnumClipboardFormats(index, flags, cExpected, prgCFs, &cActual)
    // Flags indicate whether this is part of a multiple selction of items. In the 
    // returned array, the list can indicate which formats it supports, on what STGMEDIUM and
    // whether the format is a composite one (caller does the actual rendering after calling
    // GetExtendedClipboardVariant) vs one that the list itself will render thru GetClipboardFormat
    // In the case of a multi-select, typically the list would only support composite formats
    // enabling the caller to write the format in the form: 
    // <count of items><foo variant from selected item1><foo variant from selected item2>..
    // (Note that only certain persistable VARIANT types are supported (as per CComVariant::WriteToStream).
    // In the single select case, the list is free to provide both traditional and composite formats
    // and will be called respectively on GetClipboardFormat or GetExtendedClipboardVariant for each.
    // Note that CV/OB will automatically provide a CF_NAVINFO and a CF_TEXT/CF_UNICODETEXT format, so
    // EnumClipboardFormats should NOT return these values.
    STDMETHOD(EnumClipboardFormats)(
        /* [in]                     */ ULONG             Index, 
        /* [in]                     */ VSOBJCFFLAGS      grfFlags,
        /* [in]                     */ ULONG             celt, 
        /* [in, out, size_is(celt)] */ VSOBJCLIPFORMAT   rgcfFormats[],
        /* [out, optional]          */ ULONG *           pcActual);

    STDMETHOD(GetClipboardFormat)(
        /* [in]  */ ULONG           Index,
        /* [in]  */ VSOBJCFFLAGS    grfFlags,
        /* [in]  */ FORMATETC *     pFormatetc,
        /* [in]  */ STGMEDIUM *     pMedium);

    STDMETHOD(GetExtendedClipboardVariant)(
        /* [in]  */ ULONG                   Index,
        /* [in]  */ VSOBJCFFLAGS            grfFlags,
        /* [in]  */ const VSOBJCLIPFORMAT * pcfFormat,
        /* [out] */ VARIANT *               pvarFormat);
                      
protected:

    STDMETHOD(GetListForClass)(
        /* [in]  */ CBrowseNode *         pParentBrowseNode, 
        /* [in]  */ LIB_LISTTYPE         eListType, 
        /* [in]  */ LIB_LISTFLAGS        flags, 
        /* [in]  */ VSOBSEARCHCRITERIA * pobSrch, 
        /* [out] */ IVsObjectList **     ppList);

//                                                             IVsObjectList
//==========================================================================


//==========================================================================
//                                                 IBrowseDataProviderEvents
public:

    STDMETHOD(OnBrowseDataAdded)(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode);

    STDMETHOD(OnBrowseDataRemoved)(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode);

    STDMETHOD(OnBrowseDataPropertyChanged)(
        /* [in]  */ LIB_LISTTYPE     eListType, 
        /* [in]  */ CBrowseNode*     pCBrowseNode);

//                                                 IBrowseDataProviderEvents
//==========================================================================


//==========================================================================
//                                                                   Members
protected:

    CComPtr<IBrowseDataProvider> m_srpIBrowseDataProvider;
    CComPtr<IVsLibrary> m_srpIVsLibrary;   // Holds a pointer to the library


    LIB_LISTTYPE  m_eListType;     //type of the list
    VSCOOKIE         m_dwIBrowseDataProviderEventsCookie;
 
    CBrowseCounter m_counter;

    BrowseNodeArray  m_rgpBrowseNode; // browse objects


//                                                                   Members
//==========================================================================

};
