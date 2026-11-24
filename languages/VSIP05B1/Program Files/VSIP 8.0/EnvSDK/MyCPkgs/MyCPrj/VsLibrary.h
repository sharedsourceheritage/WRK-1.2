
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once


// Interface used by library manager
class ILibrary :
    public IUnknown
{
public:
    //Return a displayable name for the designated library
    STDMETHOD(GetName)(
        /* [out] */ WCHAR **pszName) = 0;

    //Set the selected state for a library item
    STDMETHOD(ToggleCheck)() = 0;

    //Get the selected state for a library item
    STDMETHOD(GetCheckState)(
        /* [out] */ LIB_CHECKSTATE *pstate) = 0;

    STDMETHOD(GetImageList)(
        /* [out] */ HANDLE *    phImageList) = 0;

    STDMETHOD(Close)() = 0;
        
};


/////////////////////////////////////////////////////////////////////////////
// CVsLibrary

class CVsLibrary :     
    public IVsLibrary,
    public IVsLiteTreeList,
    public IVsSolutionEvents,
    public ILibrary,
    public IBrowseDataProviderImpl,
    public IBrowseDataProviderEvents,
    public CComObjectRoot
{ 

public:

BEGIN_COM_MAP(CVsLibrary)
    COM_INTERFACE_ENTRY(IVsLibrary)
    COM_INTERFACE_ENTRY(IVsLiteTreeList)
    COM_INTERFACE_ENTRY(IVsSolutionEvents)
    COM_INTERFACE_ENTRY(ILibrary)
    COM_INTERFACE_ENTRY(IBrowseDataProvider)
    COM_INTERFACE_ENTRY(IBrowseDataProviderEvents)
END_COM_MAP()

//==========================================================================
//                                                construct, init , destruct
public:

    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              To create an CVsLibrary object and return 
    //              IVsLibrary pointer.
    // Parameters: 
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CVsLibrary::CreateInstance(
            /* [out] */ ILibrary**     ppILibrary);

protected:
    CVsLibrary(); 
    ~CVsLibrary();
    STDMETHOD(Init)();

//                                                construct, init , destruct
//==========================================================================

//==========================================================================
//                                                                  ILibrary
//

public:
    STDMETHOD(Close)();

    //Return a displayable name for the designated library
    STDMETHOD(GetName)(
        /* [out] */ WCHAR **pszName);

    //Set the selected state for a library item
    STDMETHOD(ToggleCheck)();

    //Get the selected state for a library item
    STDMETHOD(GetCheckState)(
        /* [out] */ LIB_CHECKSTATE *pstate);

    STDMETHOD(GetImageList)(
        /* [out] */ HANDLE *    phImageList);

protected:
    //Check if this is a valid index
    STDMETHOD_(BOOL, IsValidIndex)(
        /* [in] */ ULONG uIndex);

    STDMETHOD(CountChecks)(
        /* [out]  */ ULONG* pcChecked,  
        /* [out]  */ ULONG* pcUnchecked); 

//
//                                                                  ILibrary
//==========================================================================

//==========================================================================
//                                                       IBrowseDataProvider
    STDMETHOD(AddBrowseNodesToArray)(
        /* [in]      */ LIB_LISTTYPE         eListType, 
        /* [in,out]  */ BrowseNodeArray*     pBrowseNodeArray);
//                                                       IBrowseDataProvider
//==========================================================================

//==========================================================================
//                                                                IVsLibrary
//
//--------------------------------------------------------------------------
//                                                      IVsLibrary interface
public:

    //  Return E_FAIL if category not supported.
    STDMETHOD(GetSupportedCategoryFields)(
        /*[in]         */ LIB_CATEGORY eCategory, 
        /*[out, retval]*/ DWORD *      pCatField);

    //Retrieve a IVsObjectList interface of LISTTYPE
    STDMETHOD(GetList)(
        /*[in]         */ LIB_LISTTYPE         eListType,  
        /*[in]         */ LIB_LISTFLAGS        eFlags, 
        /*[in]         */ VSOBSEARCHCRITERIA * pobSrch, 
        /*[out, retval]*/ IVsObjectList **     ppList);

    //Retreive a list of library contents.  Return S_FALSE and NULL if library not expandable
    STDMETHOD(GetLibList)(
        /*[in]         */ LIB_PERSISTTYPE lptType,
        /*[out, retval]*/ IVsLiteTreeList **ppList);

    //Get various settings for the library
    STDMETHOD(GetLibFlags)(
        /*[out, retval]*/ LIB_FLAGS *pfFlags);

    //Counter to check if the library has changed
    STDMETHOD(UpdateCounter)(
        /*[out]*/ ULONG *pCurUpdate);

    // Unqiue guid identifying each library that never changes (even across shell instances)
    STDMETHOD(GetGuid)(
        const GUID **ppguidLib);

    // Returns the separator string used to separate namespaces, classes and members 
    // eg. "::" for VC and "." for VB
    STDMETHOD(GetSeparatorString)(
        LPCWSTR *pszSeparator);

    //Retrieve the persisted state of this library from the passed stream 
    //(essentially information for each browse container being browsed). Only
    //implement for GLOBAL browse containers
    STDMETHOD(LoadState)(
        /* [in] */ IStream *        pIStream, 
        /* [in] */ LIB_PERSISTTYPE  lptType);
    
    //Save the current state of this library to the passed stream 
    //(essentially information for each browse container being browsed). Only
    //implement for GLOBAL browse containers
    STDMETHOD(SaveState)(
        /* [in] */ IStream *        pIStream,
        /* [in] */ LIB_PERSISTTYPE  lptType);

    // Used to obtain a list of browse containers corresponding to the given
    // project (hierarchy). Only return a list if your package owns this hierarchy
    // Meaningful only for libraries providing PROJECT browse containers.
	STDMETHOD(GetBrowseContainersForHierarchy)(
        /* [in]                     */ IVsHierarchy *    pHierarchy,
		/* [in]                     */ ULONG             celt,
		/* [in, out, size_is(celt)] */ VSBROWSECONTAINER rgBrowseContainers[],
        /* [out, optional]          */ ULONG *           pcActual);

    // Start browsing the component specified in PVSCOMPONENTSELECTORDATA (name is equivalent to that
    // returned thru the liblist's GetText method for this browse container). 
    // Only meaningful for registered libraries for a given type of GLOBAL browse container 
	STDMETHOD(AddBrowseContainer)(
	    /* [in]      */ PVSCOMPONENTSELECTORDATA pcdComponent,
        /* [in, out] */ LIB_ADDREMOVEOPTIONS *   pgrfOptions,
        /* [out]     */ BSTR *                   pbstrComponentAdded);
    
    // Stop browsing the component identified by name (name is equivalent to that
    // returned thru the liblist's GetText method for this browse container 
    // Only meaningful for registered libraries for a given type of GLOBAL browse container 
    STDMETHOD(RemoveBrowseContainer)(
        /* [in] */ DWORD    dwReserved, 
        /* [in] */ LPCWSTR  pszLibName);




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
//                                                         IVsSolutionEvents
//
public:

    // fAdded == TRUE means project added to solution after solution open.
    // fAdded == FALSE means project added to solution during solution open.
    STDMETHOD(OnAfterOpenProject)(
        /* [in] */ IVsHierarchy *pHierarchy, 
        /* [in] */ BOOL fAdded);

    // fRemoving == TRUE means project being removed from solution before solution close.
    // fRemoving == FALSE means project being removed from solution during solution close.
    STDMETHOD(OnQueryCloseProject)(
        /*[in]    */ IVsHierarchy *pHierarchy, 
        /*[in]    */ BOOL fRemoving, 
        /*[in,out]*/ BOOL *pfCancel);

    // fRemoved == TRUE means project removed from solution before solution close.
    // fRemoved == FALSE means project removed from solution during solution close.
    STDMETHOD(OnBeforeCloseProject)(
        /*[in]*/ IVsHierarchy *pHierarchy, 
        /*[in]*/ BOOL fRemoved);

    // stub hierarchy is placeholder hierarchy for unloaded project.
    STDMETHOD(OnAfterLoadProject)(
        /*[in]*/ IVsHierarchy *pStubHierarchy, 
        /*[in]*/ IVsHierarchy *pRealHierarchy);

    STDMETHOD(OnQueryUnloadProject)(
        /*[in]    */ IVsHierarchy *pRealHierarchy, 
        /*[in,out]*/ BOOL *pfCancel);

    STDMETHOD(OnBeforeUnloadProject)(
        /*[in]*/ IVsHierarchy *pRealHierarchy, 
        /*[in]*/ IVsHierarchy *pStubHierarchy);

    // fNewSolution == TRUE means solution is being created now.
    // fNewSolution == FALSE means solution was created previously, is being loaded.
    STDMETHOD(OnAfterOpenSolution)(
        /*[in]*/ IUnknown *pUnkReserved, 
        /*[in]*/ BOOL fNewSolution);

    STDMETHOD(OnQueryCloseSolution)(
        /*[in]    */ IUnknown *pUnkReserved, 
        /*[in,out]*/ BOOL *pfCancel);

    STDMETHOD(OnBeforeCloseSolution)(
        /*[in]*/ IUnknown *pUnkReserved);

    STDMETHOD(OnAfterCloseSolution)(
        /*[in]*/ IUnknown *pUnkReserved);

//                                                         IVsSolutionEvents
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

protected:

    CComBSTR        m_cbstrName;
    LIB_CHECKSTATE  m_eCheckState;
    LIB_FLAGS       m_eLibFlags;
    HIMAGELIST      m_hImages;   //image list.
    
    //UpdateCounter Version Stamp
    ULONG           m_uLibraryCounter; 

    //Cookie used to hook up the solution events.
    VSCOOKIE        m_dwIVsSolutionEventsCookie;  
    
    //Array of Projects
    CVxTypedPtrArray<CVxPtrArray, CComObject<CLibraryItem> *> m_rgpLibraryItem;

    CBrowseCounter m_counterLibList;

};

