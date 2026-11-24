
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjHier.h : Declaration of CMyProjectHierarchy project implementation

#pragma once

/////////////////////////////////////////////////////////////////////////////
// These are used by the Load/Save operations.
extern const _declspec(selectany) WCHAR* STR_GENERALSECTION	= L"General";
extern const _declspec(selectany) WCHAR* STR_CONFIGSECTION	= L"Configurations";
extern const _declspec(selectany) WCHAR* STR_FILESSECTION	= L"Files";
extern const _declspec(selectany) WCHAR* STR_PROJRELPATH	= L"ProjRelPath";
extern const _declspec(selectany) WCHAR* STR_STARTUPSERVICES= L"ProjStartupServices";
extern const _declspec(selectany) WCHAR* STR_GLOBALSSECTION	= L"Globals";
extern const _declspec(selectany) WCHAR* STR_OWNERKEY	    = L"OwnerKey";
extern const _declspec(selectany) WCHAR* STR_PROJECTIDGUID	= L"ProjectIdGuid";

// Scc values
extern const _declspec(selectany) WCHAR* STR_SCCPROJECTNAME = L"SccProjectName";
extern const _declspec(selectany) WCHAR* STR_SCCLOCALPATH	= L"SccLocalPath";
extern const _declspec(selectany) WCHAR* STR_SCCAUXPATH		= L"SccAuxPath";
extern const _declspec(selectany) WCHAR* STR_SCCPROVIDER	= L"SccProvider";

/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CMyProjectHierarchy;
class CFileVwProjNode;

/////////////////////////////////////////////////////////////////////////////
// CMyProjectHierarchy
//---------------------------------------------------------------------------
// implements (inherited from CVsHierarchy):
//		interface: IVsHierarchy
//		interface: IVsUIHiearchy
//		interface: IVsPersistHierarchyItem
//		interface: IOleCommandTarget
//		interface: IVsHierarchyDropDataSource
//		interface: IVsHierarchyDropDataTarget
//		interface: ISupportErrorInfo
// 
// implements:
//		interface: IVsProject, IVsProject2, IVsProject3
//		interface: IPersistFileFormat
//		interface: IVsSccProject2
//		interface: IDispatch
//		interface: IMyCPrjProjHierProps
//		interface: VxDTE::IVsGlobalsCallback
//---------------------------------------------------------------------------

class CMyProjectHierarchy : 
	public CVsHierarchy, 
	public IVsProject3,					// ->IVsProject2 -> IVsProject
	public IPersistFileFormat,			// derives from IPersist
    public IVsGetCfgProvider,           // -> IUnknown 
    public IVsProjectStartupServices,   
	public IVsSccProject2,
	public IVsHierarchyDeleteHandler,
	public IVsHierarchyDropDataSource2, // ->IVsHierarchyDropDataSource
	public IVsUIHierWinClipboardHelperEvents,
    public VxDTE::IVsGlobalsCallback,  // support reading/writing data for extensibility clients
	public IDispatchImpl<IMyCPrjProjHierProps, &IID_IMyCPrjProjHierProps, &LIBID_MyCPrjPKGLib>
{
public:
	
	CMyProjectHierarchy(void);
	~CMyProjectHierarchy(void);
	
	HRESULT CMyProjectHierarchy::Init(
        /* [in]  */ LPCTSTR pszProjName, 
        /* [in]  */ LPCTSTR pszProjFullPath,
        /* [in]  */ LPCTSTR pszProjLocation,
        /* [in]  */ BOOL    fNewProject,
        /* [out] */ BOOL*   pfCanceled);
    BOOL CMyProjectHierarchy::NewProject(){ return m_fNewProject; }
	
	BEGIN_COM_MAP(CMyProjectHierarchy)
		COM_INTERFACE_ENTRY(IVsProject)				// derives from IUnknown
		COM_INTERFACE_ENTRY(IVsProject2)			// derives from IVsProject
		COM_INTERFACE_ENTRY(IVsProject3)			// derives from IVsProject2
		COM_INTERFACE_ENTRY(IVsSccProject2)			
		COM_INTERFACE_ENTRY(IVsHierarchyDeleteHandler)
		COM_INTERFACE_ENTRY(IPersist)				// derives from IUnknown
		COM_INTERFACE_ENTRY(IPersistFileFormat)		// derives from IPersist
        COM_INTERFACE_ENTRY(IVsGetCfgProvider)      
        COM_INTERFACE_ENTRY(IVsProjectStartupServices)
		COM_INTERFACE_ENTRY(IMyCPrjProjHierProps)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IVsHierarchyDropDataSource2)
		COM_INTERFACE_ENTRY(IVsUIHierWinClipboardHelperEvents)
        COM_INTERFACE_ENTRY_IID(VxDTE::IID_IVsGlobalsCallback, VxDTE::IVsGlobalsCallback)
		COM_INTERFACE_ENTRY_CHAIN(CVsHierarchy)		// chain to base case
		//COM_INTERFACE_ENTRY(IConnectionPointContainer)
		//COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	END_COM_MAP()
    DECLARE_POLY_AGGREGATABLE(CMyProjectHierarchy)
		
		//BEGIN_CONNECTION_POINT_MAP(CMyProjectHierarchy)
		//  CONNECTION_POINT_ENTRY(DIID__dispMyCProjectItemsEvents)
		//END_CONNECTION_POINT_MAP()
		
        
	// IVsProject
	STDMETHOD(IsDocumentInProject)(
		/* [in] */ LPCOLESTR pszMkDocument,
		/* [out] */ BOOL *pfFound,
		/* [out] */ VSDOCUMENTPRIORITY *pdwPriority,
		/* [out] */ VSITEMID *pvsid);
        
	STDMETHOD(GetMkDocument)(
		/* [in] */ VSITEMID vsid,
		/* [out] */ BSTR *pbstrMkDocument);
        
	STDMETHOD(OpenItem)(
		/* [in] */ VSITEMID vsid,
		/* [in] */ REFGUID rguidLogicalView,
		/* [in] */ IUnknown *punkDocDataExisting,
		/* [out] */ IVsWindowFrame **ppWindowFrame);
        
	STDMETHOD(GetItemContext)(
		/* [in] */ VSITEMID vsid,
		/* [out] */ IServiceProvider **ppSP);
        
	STDMETHOD(GenerateUniqueItemName)(
		/* [in] */ VSITEMID itemidLoc,
		/* [in] */ LPCOLESTR pszExt,
		/* [in] */ LPCOLESTR pszSuggestedRoot,
		/* [out] */ BSTR *pbstrItemName);
		
	STDMETHOD(AddItem)( 
		/* [in] */ VSITEMID itemidLoc,
		/* [in] */ VSADDITEMOPERATION dwAddItemOperation,
		/* [in] */ LPCOLESTR pszItemName,
		/* [in] */ DWORD cFilesToOpen,
		/* [size_is][in] */ LPCOLESTR rgpszFilesToOpen[],
		/* [in] */ HWND hwndDlg,
		/* [retval][out] */ VSADDRESULT __RPC_FAR *pResult);
		

 	// IVsProject2
    STDMETHOD(RemoveItem)( 
            /* [in]          */ DWORD    dwReserved,
            /* [in]          */ VSITEMID itemid,
            /* [retval][out] */ BOOL *   pfResult);
        

    STDMETHOD(ReopenItem)( 
            /* [in]          */ VSITEMID         itemid,
            /* [in]          */ REFGUID          rguidEditorType,
            /* [in]          */ LPCOLESTR        pszPhysicalView,
            /* [in]          */ REFGUID          rguidLogicalView,
            /* [in]          */ IUnknown*        punkDocDataExisting,
            /* [retval][out] */ IVsWindowFrame** ppWindowFrame);


    //  AddItemWithSpecific is used to add item(s) to the project and 
    //  additionally ask the project to open the item using the specified 
    //  editor information.  An extension of IVsProject::AddItem().
    STDMETHOD(AddItemWithSpecific)(
        /* [in]          ```           */ VSITEMID              itemidLoc,
        /* [in]                        */ VSADDITEMOPERATION    dwAddItemOperation,
        /* [in]                        */ LPCOLESTR             pszItemName,
        /* [in]                        */ ULONG                 cFilesToOpen,
        /* [in, size_is(cFilesToOpen)] */ LPCOLESTR             rgpszFilesToOpen[],
        /* [in]                        */ HWND                  hwndDlg,
        /* [in]                        */ VSSPECIFICEDITORFLAGS grfEditorFlags,
        /* [in]                        */ REFGUID               rguidEditorType,
        /* [in]                        */ LPCOLESTR             pszPhysicalView,
        /* [in]                        */ REFGUID               rguidLogicalView,
        /* [out, retval]               */ VSADDRESULT *         pResult);

    // OpenItemWithSpecific is used to ask the project to open the item using the
    // specified editor information.  An extension of IVsProject::OpenItem().
    STDMETHOD(OpenItemWithSpecific)(
        /* [in]  */ VSITEMID              itemid,
        /* [in]  */ VSSPECIFICEDITORFLAGS grfEditorFlags,
        /* [in]  */ REFGUID               rguidEditorType,
        /* [in]  */ LPCOLESTR             pszPhysicalView,
        /* [in]  */ REFGUID               rguidLogicalView,
        /* [in]  */ IUnknown*             punkDocDataExisting,
        /* [out] */ IVsWindowFrame**      ppWindowFrame);

    //  TransferItem is used to transfer ownership of a running document to the project.
    //  The project should call IVsRunningDocumentTable::RenameDocument to transfer 
    //  ownership of the document to its hierarchy and give the document a new 
    //  itemid within the project.
    //  This function is called when an open file is being transferred to 
    //  our project. The sequence is for the shell to call AddItemWithSpecific and
    //  then use TransferItem to transfer the open document to our project.
    STDMETHOD(TransferItem)(
        /* [in] */ LPCOLESTR       pszMkDocumentOld,// passed as pszDocumentOld to IVsRunningDocumentTable::RenameDocument
        /* [in] */ LPCOLESTR       pszMkDocumentNew,// passed as pszDocumentNew to IVsRunningDocumentTable::RenameDocument
        /* [in] */ IVsWindowFrame* punkWindowFrame);// optional if document not open


    // interface: IVsPersistHierarchyItem
    STDMETHOD(SaveItem)(
            /* [in]  */ VSSAVEFLAGS dwSave,
            /* [in]  */ LPCOLESTR   pszSilentSaveAsName,
            /* [in]  */ VSITEMID    itemid,    
            /* [in]  */ IUnknown *  punkDocData,
            /* [out] */ BOOL *      pfCanceled);

	// IPersistFileFormat
	STDMETHOD(GetClassID)(
		/* [out] */ CLSID *pClassID);
		
	STDMETHOD(IsDirty)(
		/* [out] */ BOOL *pfIsDirty);
		
	STDMETHOD(InitNew)(
		/*[in] */ DWORD nFormatIndex);
		
	STDMETHOD(Load)(
		/* [in] */ LPCOLESTR pszFilename,
		/* [in] */ DWORD grfMode,
		/* [in] */ BOOL fReadOnly);
		
	STDMETHOD(Save)(
		/* [in] */ LPCOLESTR pszFilename,
		/* [in] */ BOOL fRemember,
		/* [in] */ DWORD nFormatIndex);
	
	STDMETHOD(SaveCompleted)(
		/* [in] */ LPCOLESTR pszFileName);
		
	STDMETHOD(GetCurFile)(
		/* [out] */ LPOLESTR __RPC_FAR *ppszFilename,
		/* [out] */ DWORD __RPC_FAR *pnFormatIndex);
		
	STDMETHOD(GetFormatList)( 
		/* [out] */ LPOLESTR __RPC_FAR *ppszFormatList);
		
    
    // IVsGetCfgProvider
    STDMETHOD(GetCfgProvider)(
        /* [out] */ IVsCfgProvider** ppCfgProvider);


    // IVsProjectStartupServices
    STDMETHOD(AddStartupService)(
        /*[in]*/ REFGUID guidService);
    STDMETHOD(RemoveStartupService)(
        /*[in]*/ REFGUID guidService);
    STDMETHOD(GetStartupServiceEnum)(
        /*[out]*/ IEnumProjectStartupServices **ppEnum);

        
	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
	
	// IMyCPrjProjHierProps
    STDMETHOD(get_Name)(BSTR *pVal);
	STDMETHOD(put_Name)(BSTR NewName);
    STDMETHOD(get_ProjectPath)(BSTR *pVal);
    STDMETHOD(get_IsDirty)(VARIANT_BOOL *pVal);
    STDMETHOD(put_IsDirty)(VARIANT_BOOL pVal);
	
    // Returns the requested extender object if it is available.
    STDMETHOD(get_Extender)(
        /* [in]          */ BSTR         bstrExtenderName, 
        /* [out, retval] */ IDispatch ** ppExtender);

    // Returns a safe array of string names of currently applicable extenders.
    STDMETHOD(get_ExtenderNames)(
        /* [out, retval] */ VARIANT * pvarExtenderNames);

    // Returns the GUID string for the Project object that is the category ID for 
    // searching for automation extenders. Implementers of extenders for this object 
    // need to know its extender CATID.
    STDMETHOD(get_ExtenderCATID)(
        /* [out, retval] */ BSTR * pbstrRetval);


	// IVsSccProject2
    STDMETHOD(SccGlyphChanged)( 
        /* [in] */ int cAffectedNodes,
        /* [size_is][in] */ const VSITEMID rgitemidAffectedNodes[],
        /* [size_is][in] */ const VsStateIcon rgsiNewGlyphs[],
        /* [size_is][in] */ const DWORD rgdwNewSccStatus[]);
		
	STDMETHOD(SetSccLocation)( 
        /* [in] */ LPCOLESTR pszSccProjectName,
        /* [in] */ LPCOLESTR pszSccAuxPath,
        /* [in] */ LPCOLESTR pszSccLocalPath,
        /* [in] */ LPCOLESTR pszSccProvider);
		
	STDMETHOD(GetSccFiles)( 
        /* [in] */ VSITEMID,
        /* [out] */ CALPOLESTR* pCaStringsOut,
        /* [out] */ CADWORD* pCaFlagsOut);
		
	STDMETHOD(GetSccSpecialFiles)( 
       /* [in] */ VSITEMID,
       /* [in] */ LPCOLESTR pszSccFile,
       /* [out] */ CALPOLESTR *pCaStringsOut,
        /* [out] */ CADWORD* pCaFlagsOut);
		
	STDMETHOD(UnregisterSccProject)();
	STDMETHOD(RegisterSccProject)();

	// IVsHierarchyDeleteHandler
	STDMETHOD(QueryDeleteItem)(
		/* [in] */ VSDELETEITEMOPERATION dwDelItemOp,
		/* [in] */ VSITEMID itemid,
		/* [out]*/ BOOL *pfCanDelete);

	STDMETHOD(DeleteItem)(
		/* [in] */ VSDELETEITEMOPERATION dwDelItemOp,
		/* [in] */ VSITEMID itemid);

	virtual HRESULT RemoveItem(VSITEMID itemid, BOOL fRemoveFromDisk);
	HRESULT CloseAndRemoveItem(VSITEMID itemid, BOOL fRemoveFromDisk);

	//CVsHierarchy
	STDMETHOD(Close)(void);  //Override Close so we can call our event handler.
	
	HRESULT SetProperty(CHierNode *pNode, VSHPROPID propid, const VARIANT& var);  //Override so we can check for a rename.
	STDMETHOD(GetGuidProperty)(VSITEMID itemid, VSHPROPID propid, GUID* pguid);
    STDMETHOD(SetGuidProperty)(
        /* [in]  */ VSITEMID    itemid,
        /* [in]  */ VSHPROPID   propid,
        /* [in]  */ REFGUID     guid);  
	
	STDMETHODIMP ParseCanonicalName(
            /* [in] */ LPCOLESTR pszName,
            /* [out] */ VSITEMID *pitemid);
	
	CFileVwProjNode* GetProjectNode(void);
	
	const CString& GetProjectLocation() { return m_strProjLocation; }
	HRESULT OnProjectRenamed();

	BOOL QueryEditProjectFile();
	
	// Used for displaying the property pages of the project
	HRESULT DoProjectSettingsDlg();
	
	// private implementation, not the interface version
	//
	virtual HRESULT GetProperty(CHierNode* pNode, VSHPROPID propid, VARIANT* pvar);
	
	// Overriden method to handle the item Rename aspect of a SaveAs operation via a call to 
	// IVsPersistHierarchyItem::SaveItem.
	// If a SaveAs occurred the hierarchy needs to update to the fact that its item's name has changed.
	// This may include the following:
	//		1. call RenameDocument on the RunningDocumentTable
	//		2. update the full path name for the item in the hierarchy
	//		3. a directory-based project may need to transfer the open editor to the
	//		   MiscFiles project if the new file is saved outside of the project directory.
	//		   This is accomplished by calling IVsExternalFilesManager::TransferDocument
	// This work can not be done by CVsHierarchy::SaveItem; this must be done in a 
	// derived subclass implementation of OnHandleSaveItemRename. Alternatively, SaveItem
	// itself can be overriden.
	virtual HRESULT OnHandleSaveItemRename(VSITEMID itemid, IUnknown *punkDocData, LPCOLESTR pszMkDocumentNew);
	
	virtual HRESULT DisplayContextMenu(HierNodeList &rgSelection);
	virtual UINT GetContextMenu(HierNodeList &rgSelection);
	
	// Override to handle Query status in a particular way
	virtual HRESULT QueryStatusSelection(
		const GUID *pguidCmdGroup,
		ULONG cCmds,
		OLECMD prgCmds[],
		OLECMDTEXT *pCmdText,
		HierNodeList &rgSelection,
		BOOL		 bIsHierCmd);		// TRUE if cmd originated via CVSUiHierarchy::ExecCommand
	
	// Override to handle Exec in a particular way
	virtual HRESULT ExecSelection(
		const GUID *pguidCmdGroup,
		DWORD nCmdID,
		DWORD nCmdexecopt,
		VARIANT *pvaIn,
		VARIANT *pvaOut,
		HierNodeList &rgSelection,
		BOOL		 bIsHierCmd);		// TRUE if cmd originated via CVSUiHierarchy::ExecCommand
	
	// Helper functions for IPersistFileFormat persistance of project file
	HRESULT SaveGeneralProperties(IVsPropertyStreamOut *pIVsPropertyStreamOut);
	HRESULT SaveFiles(IVsPropertyStreamOut *pIVsPropertyStreamOut);
	HRESULT SaveConfigurations(IVsPropertyStreamOut *pIVsPropertyStreamOut);
	HRESULT LoadGeneralProperties(IVsPropertyStreamIn *pIVsPropertyStreamIn);
	HRESULT LoadFiles(IVsPropertyStreamIn *pIVsPropertyStreamIn);
	HRESULT LoadConfigurations(IVsPropertyStreamIn *pIVsPropertyStreamIn);
	
// =========================================================================
//                                           DRAG AND DROP, CUT, COPY, PASTE
public:

	// IVsHierarchyDropDataSource interface methods

    //----------------------------------------------------------------------
    // Function:    GetDropInfo
    //      Returns information about one or more of the items being dragged.
    // Parameters: 
    //    /* [out]  */ DWORD *         pdwOKEffects, 
    //      Pointer to a DWORD value describing the effects displayed while 
    //      the item is being dragged, 
    //    /* [out] */ IDataObject **  ppDataObject, 
    //      Pointer to the IDataObject interface on the item being dragged. 
    //    /* [out] */ IDropSource **  ppDropSource);
    //      Pointer to the IDropSource interface of the item being dragged.
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(GetDropInfo)(
        /* [out] */ DWORD *         pdwOKEffects, 
        /* [out] */ IDataObject **  ppDataObject, 
        /* [out] */ IDropSource **  ppDropSource);

    //----------------------------------------------------------------------
    // Function:    OnDropNotify
    //      Notifies clients that the dragged item was dropped.
    // Parameters: 
    //    /* [in] */ BOOL     fDropped, 
    //      If TRUE, then the dragged item was dropped on the target.
    //      If FALSE, then the drop did not occur.
    //    /* [in] */ DWORD    dwEffects);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(OnDropNotify)(
        /* [in] */ BOOL     fDropped, 
        /* [in] */ DWORD    dwEffects);
	
	// IVsHierarchyDropDataSource2 interface methods
    //----------------------------------------------------------------------
    // Function:    OnBeforeDropNotify
    //      Allows the drag source to prompt to save unsaved items being dropped.
    // Parameters: 
    //    /* [in]         */ IDataObject *    pDataObject,
    //    /* [in]         */ DWORD            grfKeyState,
    //    /* [out,retval] */ BOOL *           pfCancelDrop);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(OnBeforeDropNotify)(
        /* [in]         */ IDataObject *    pDataObject,
        /* [in]         */ DWORD            grfKeyState,
        /* [out,retval] */ BOOL *           pfCancelDrop);

	// IVsHierarchyDropDataTarget interface methods
	STDMETHOD(DragEnter)(IDataObject *pDataObject, DWORD grfKeyState, VSITEMID itemid, DWORD *pdwEffect);
	STDMETHOD(DragOver)(DWORD grfKeyState, VSITEMID itemid, DWORD *pdwEffect);
	STDMETHOD(DragLeave)(void);
	STDMETHOD(Drop)(IDataObject *pDataObject, DWORD grfKeyState, VSITEMID itemid, DWORD *pdwEffect);

    //----------------------------------------------------------------------
    // IVsUIHierWinClipboardHelper
    //
    // This interface is used to coordinate clipboard operations between hierarchies
    // in a UIHierarchyWindow.  Any hierarchy that wishes to coordinate its clipboard
    // operations with other hierarchies should implement IVsUIHierWinClipboardHelperEvents,
    // and register its interest in the clipboard events with AdviseClipboardHelperEvents.
    //
    // Here's how a typical cut/paste sequence would work:
    //
    // 1) The user performs a cut of project item from a project.
    //
    // 2) The source project creates an IDataObject containing the data for the cut project items.
    //    The source project needs to communicate to the destination project the nature of the source
    //    project--i.e., whether it is a "referenced-based" or a "storage-based" project. Generally
    //    a "storaged-based" project is one that will physically delete the storage for the item
    //    on a MOVE operation. A "referenced-based" project will only delete its reference to the
    //    storage of the item but leave the storage for the item intact. The nature of the source
    //    project is communicated based on the clipboard format used: a "reference-based" project
    //    uses CF_VSREFPROJECTITEMS, a "storage-based" project uses CF_VSSTGPROJECTITEMS format.
    //    In addition to passing the IDataObject to OLE, the source project passes it to the environment
    //    via the Cut method on the IVsUIHierWinClipboardHelper interface.  The source project then dims
    //    the appearance of the cut item using IVsUIHierarchyWindow::ExpandItem and either the
    //    EXPF_CutHighlightItem or EXPF_AddCutHighlightItem flag as appropriate.
    //
    // 3) The user performs a paste of the project item.
    //
    // 4) The destination project handles the contents of the IDataObject, and then communicates
    //    that a paste occurred by calling the Paste method on the IVsUIHierWinClipboardHelper interface.
    //    On this call the destination project specifies either DROPEFFECT_MOVE or DROPEFFECT_LINK
    //    depending on the appropriate type of Cut/Paste operation that should be performed.
    //    The destination project is the one that has enough information to determine whether a MOVE or
    //    a LINK operation should be performed. The destination project knows the nature of the
    //    source project based on whether CF_VSREFPROJECTITEMS or CF_VSSTGPROJECTITEMS format was offered.
    //    It also inherently knows whether itself is "reference-based" or "storage-based".
    //
    // 5) When its Paste method is called, the IVsUIHierWinClipboardHelper interface iterates through its
    //    list of interested listeners and calls the OnPaste method on each.  When the source project
    //    gets called in this way, if DROPEFFECT_MOVE is specifed, it should complete the cut by removing
    //    the cut item from itself ;otherwise the source project should un-dim the item using
    //    IVsUIHierarchyWindow::ExpandItem and the EXPF_UnCutHighlightItem flag.
    //
    // The IVsUIHierWinClipboardHelper interface is also a clipboard watcher, so when the contents of
    // the clipboard change, and the cut IDataObject is no longer on the clipboard, the OnClear method of
    // each listener will be called so that the cut item can be undimmed using IVsUIHierarchyWindow::ExpandItem
    // and the EXPF_UnCutHighlightItem flag.
    //
    // In a copy situation, of course, the item need not be dimmed since it has not been cut.
    //----------------------------------------------------------------------
	STDMETHOD(OnPaste)(BOOL fDataWasCut, DWORD dwEffects);
	STDMETHOD(OnClear)(BOOL fDataWasCut);

protected:

    enum DropDataType//Drop types
    {
        DDT_NONE,
        DDT_SHELL,
        DDT_VSSTG,
        DDT_VSREF
    };

	// Helper functions for drag-drop copy-cut-paste implementation
	HRESULT PackageSelectionDataObject(
        /* [out] */ IDataObject **  ppDataObject, 
        /* [in]  */ BOOL            fCutHighlightItems);

	HRESULT ProcessSelectionDataObject(
        /* [in]  */ IDataObject*    pDataObject, 
        /* [in]  */ DWORD           grfKeyState,
        /* [out] */ DropDataType*   pddt);

	HRESULT CleanupSelectionDataObject(
        /* [in] */ BOOL fDropped, 
        /* [in] */ BOOL fCut, 
        /* [in] */ BOOL fMoved);

	HRESULT CutSelectionToClipboard();
	HRESULT CopySelectionToClipboard();
	HRESULT PasteItemsFromClipboard();

    //----------------------------------------------------------------------
    // Function:    QueryDropDataType
    //              The method query tha DataObject for known formats such
    //              as File Drops (as from WindowsExplorer), 
    //              VSProject Reference Items (CF_VSREFPROJECTITEMS), or 
    //              VSProject Storage Items (CF_VSSTGPROJECTITEMS).
    // Parameters: 
    //    /* [in]  */  IDataObject* pDataObject,
    //              Data Object
    // Returns:     HRESULT
    //              S_OK - recognized format
    //              S_FALSE - could not find known format. m_ddt is set to 
    //                  DDT_NONE.
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(QueryDropDataType)(
        /* [in] */  IDataObject* pDataObject);


    //----------------------------------------------------------------------
    // Function:    QueryDropEffect
    //              The function returns the drop effect according to the 
    //              drop data type.
    // Parameters: 
    //    /* [in]  */  DropDataType ddt,
    //    /* [in]  */  DWORD        grfKeyState,
    //              Key state
    //    /* [out] */  DWORD *      pdwEffects);
    // Returns:     HRESULT
    //              S_OK
    //              S_FALSE - unknown drop data type.
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(QueryDropEffect)(
    /* [in]  */  DropDataType ddt,
    /* [in]  */  DWORD        grfKeyState,
    /* [out] */  DWORD *      pdwEffects);


    //----------------------------------------------------------------------
    // Function:    RegisterClipboardNotifications
    //              Advise/Unadvise for clipboard events (onpaste and onclear). 
    //              Can be safely called many times
    // Parameters: 
    //    /* [in] */ BOOL fRegister);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(RegisterClipboardNotifications)(
        /* [in] */ BOOL fRegister);

//                                           DRAG AND DROP, CUT, COPY, PASTE
// =========================================================================


// =========================================================================
//                                                        IVsGlobalsCallback
public:

    //----------------------------------------------------------------------
    // Function:    WriteVariablesToData
    //              Informs us, variable by variable, to persist global data
    // Parameters:  
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(WriteVariablesToData)(
	    /* [in] */ LPCOLESTR  pVariableName,
	    /* [in] */ VARIANT *  varData);

    //----------------------------------------------------------------------
    // Function:    ReadData
    //              Gives us a Globals object which we populate with current 
    //              global data
    // Parameters:  
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(ReadData)(
	    /* [in] */ VxDTE::Globals *pGlobals);

    //----------------------------------------------------------------------
    // Function:    ClearVariables
    //              Called by shell extensibility when the Global list of 
    //              data is cleared
    // Parameters:  
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(ClearVariables)();

    //----------------------------------------------------------------------
    // Function:    VariableChanged
    //              Informs us that a variable in Globals has been modified. 
    //              We set our dirty state in response.
    // Parameters:  
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(VariableChanged)();

    //----------------------------------------------------------------------
    // Function:    CanModifySource
    //              Called by the shell to see if the collection of globals 
    //              can be modified. For example, if the destination of the 
    //              persistance file is under source code control (ex: a 
    //              project file), we would not want to allow the file to be 
    //              saved. 
    // Parameters:  
    // Returns:     HRESULT
    // Notes:
    //              The implementor needs to return S_OK/S_FALSE depending 
    //              on what action is to be taken. 
    //----------------------------------------------------------------------
	STDMETHOD(CanModifySource)();

    //----------------------------------------------------------------------
    // Function:    GetParent
    //              Returns the extensibility object that owns the Globals 
    //              object
    // Parameters:  
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(GetParent)(
	    /* [out] */ IDispatch **ppOut);
        
protected:

    //----------------------------------------------------------------------
    // Function:    LoadGlobals
    //              This method loads globals saved in the project file.
    //
    // Parameters:  
    //  /* [in] */ IVsPropertyStreamIn *pIVsPropertyStreamIn 
    //              Stream to load from
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(LoadGlobals)(
        /* [in] */ IVsPropertyStreamIn *pIVsPropertyStreamIn);

    //----------------------------------------------------------------------
    // Function:    SaveGlobals
    //              This method saves globals into the project file.
    //
    // Parameters:  
    //  /* [in] */ IVsPropertyStreamOut *pIVsPropertyStreamOut 
    //              Stream to save to
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(SaveGlobals)(
        /* [in] */ IVsPropertyStreamOut *pIVsPropertyStreamOut);

    STDMETHOD(GetIVsGlobals)(
        /* [out] */ IVsGlobals ** ppIVsGlobals);

//                                                        IVsGlobalsCallback
// =========================================================================


protected:

    CFileVwFileNode* VSITEMID2FileNode(const VSITEMID vsitemid);

protected:
	CString			m_strProjFullPath;
	CString			m_strProjLocation;
	
	// File persistance support (IPersistFileFormat)
	DWORD			m_nFormatIndex;
	
	// SCC settings support
    CString			m_strSccProjectName;
    CString			m_strSccLocalPath;
    CString			m_strSccAuxPath;
    CString			m_strSccProvider;
	bool			m_fRegisteredWithScc;
	virtual UINT	GetIconIndex(CHierNode* pNode, ICON_TYPE iconType);
	
	// Our one and only Package Image List
	static PUIHierarchyImageList	g_pil;
	
    // Configuration provider
    CComObject<CCfgProvider> * m_pCfgProvider; 

    // IVsProjectStartupServices
    CVsProjectStartupServices  m_projectStartupServices;

	// DragDrop support
	BOOL             m_fDragSource;
    DropDataType     m_ddt;
	ULONG            m_nItemsDragged;
	VSITEMSELECTION *m_pItemSelDragged;
    VSCOOKIE         m_vscookieIVsUIHierWinClipboardHelperEvents;
    BOOL             m_fInCutCopy;

    // Globals map
    CVxMapStringToString m_mapGlobals;

    // New project flag
    BOOL            m_fNewProject;

	// Pointers to the array of file paths when loading existing project
    CVxTypedPtrArray<CVxPtrArray, CString*>  m_rgpFilePaths;

public:
    HANDLE     m_hThreadBuild;  // handle to the builder thread
	
};
