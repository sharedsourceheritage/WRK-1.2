
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


/***************************************************************************
File name   : AutomationObjects.h
Description : Declaration of the following automation objects:
              1) class CAOProject 
              2) class CAOProjectItemBase
              3) class CAOProjectItemFile
              4) class CAOSelectedItem
***************************************************************************/

#pragma once

// forward declarations
class CFileVwFileNode;
class CFileVwFolderNode;
class CFileVwProjNode;
class CAOProject;
class CAOProjectItemBase;
class CAOProjectItemFile;
class CAOSelectedItem;
class CACProjectItems;


///////////////////////////////////////////////////////////////////////////
// Class CAOProject
// Implements VxDTE::Project
///////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE CAOProject :
    public CComObjectRootEx<CComSingleThreadModel>, // explict
    public IDispatchImpl<Project, &IID_Project, &LIBID_DTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>,
    public ISupportVSProperties,
    public ISupportErrorInfo
{
public:
    static HRESULT CreateInstance(
        /* [in]  */ CFileVwProjNode* pProjNode,
        /* [out] */ Project**        ppProject);
    virtual void Close();

protected:
    CAOProject();
    HRESULT Init(
        /* [in]  */ CFileVwProjNode* pProjNode);

    void FinalRelease();
    virtual bool IsValid();

public:

    BEGIN_COM_MAP(CAOProject)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(Project)
        COM_INTERFACE_ENTRY(ISupportVSProperties)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()


// =========================================================================
//                                                                   Project

    //----------------------------------------------------------------------
    // Function:    get_Name
    //      Returns the displayed name of the project.
    // Parameters:  
    //    /* [out] */ BSTR* lpbstrName);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Name)(
        /* [out] */ BSTR* lpbstrName);

    //----------------------------------------------------------------------
    // Function:    put_Name
    //      Sets the displayed name of the project.
    // Parameters:  
    //    /* [in]  */ BSTR bstrName);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(put_Name)(
        /* [in]  */ BSTR bstrName);

    //----------------------------------------------------------------------
    // Function:    get_FileName
    //      Returns the file system location of the project file, a full 
    //      pathname.
    // Parameters:  
    //    /* [out] */ BSTR * lpbstrReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_FileName)(
        /* [out] */ BSTR * lpbstrReturn);

    //----------------------------------------------------------------------
    // Function:    get_IsDirty
    //      Returns a Boolean value indicating whether or not the object was
    //      edited since the last time it was saved.
    // Parameters:  
    //    /* [out] */ VARIANT_BOOL * lpfReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_IsDirty)(
        /* [out] */ VARIANT_BOOL * lpfReturn);

    //----------------------------------------------------------------------
    // Function:    put_IsDirty
    //      Sets a Boolean value indicating whether or not the object was
    //      edited since the last time it was saved.
    //
    // Parameters:  
    //    /* [in]  */ VARIANT_BOOL Dirty);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(put_IsDirty)(
        /* [in]  */ VARIANT_BOOL Dirty);

    //----------------------------------------------------------------------
    // Function:    get_Collection
    //      Returns the collection that contains the object.  This is the 
    //      collection that the package provides, and which is hung from the
    //      DTE object.
    // Parameters:  
    //    /* [out] */ Projects ** lppaReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Collection)(
        /* [out] */ Projects ** lppaReturn);

    //----------------------------------------------------------------------
    // Function:    SaveAs
    //      Saves the project using the supplied file name.
    // Parameters:  
    //    /* [in]  */ BSTR FileName);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(SaveAs)(
        /* [in]  */ BSTR FileName);

    //----------------------------------------------------------------------
    // Function:    get_DTE
    //      Returns the top-level extensibility object.  In the Visual 
    //      Studio shell this is the same object as the Application object.
    // Parameters:  
    //    /* [out] */ DTE ** lppaReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_DTE)(
        /* [out] */ DTE ** lppaReturn);

    //----------------------------------------------------------------------
    // Function:    get_Kind
    //      Returns the type of the project as a string. Enviroment extensions 
    //      will have to provide uniquely defined type strings. This information
    //      should be available in the package type library or documentation.
    // Parameters:  
    //    /* [out] */ BSTR * lpbstrFileName);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Kind)(
        /* [out] */ BSTR * lpbstrFileName);

    //----------------------------------------------------------------------
    // Function:    get_ProjectItems
    //      Returns a collection that represents all the project items in 
    //      the project
    // Parameters:  
    //    /* [out] */ ProjectItems ** lppcReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ProjectItems)(
        /* [out] */ ProjectItems ** lppcReturn);

    //----------------------------------------------------------------------
    // Function:    get_Properties
    //      Returns a properties collection that represents all the 
    //      properties that pertain to the project
    // Parameters:  
    //    /* [out] */ Properties ** lppaReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Properties)(
        /* [out] */ Properties ** lppaReturn);

    //----------------------------------------------------------------------
    // Function:    get_UniqueName
    //      Returns the name of the project as a relative pathname from the 
    //      directory that contains the solution file to the the project file.
    //      This name is suitable for indexing Solution.Item("...").
    // Parameters:  
    //    /* [out] */ BSTR * lpbstrFileName);
    // Returns:     HRESULT
    // Notes:
    //      Packages can implement this for their xxProject objects by 
    //      calling IVsSolution::GetUniqueNameForProject.
    //----------------------------------------------------------------------
    STDMETHOD(get_UniqueName)(
        /* [out] */ BSTR * lpbstrFileName);

    //----------------------------------------------------------------------
    // Function:    get_Object
    //      Returns the project-specific automation object.
    // Parameters:  
    //    /* [out] */ IDispatch ** ppProjectModel);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Object)(
        /* [out] */ IDispatch ** ppProjectModel);

    //----------------------------------------------------------------------
    // Function:    get_Extender
    //      Returns the requested extender object if it is available for this
    //      Project implementation. May return Nothing.
    // Parameters:  
    //    /* [in]  */ BSTR            bstrExtenderName, 
    //    /* [out] */ IDispatch **    ppExtender);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Extender)(
        /* [in]  */ BSTR            bstrExtenderName, 
        /* [out] */ IDispatch **    ppExtender);

    //----------------------------------------------------------------------
    // Function:    get_ExtenderNames
    //      Returns a safe array of string names of currently applicable 
    //      extenders for this Project implementation.
    // Parameters:  
    //    /* [out] */ VARIANT *pvarExtenderNames);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ExtenderNames)(
        /* [out] */ VARIANT *pvarExtenderNames);

    //----------------------------------------------------------------------
    // Function:    get_ExtenderCATID
    //      Returns the GUID string for the Project object that is the 
    //      category ID for searching for automation extenders.  Implementers 
    //      of extenders for this object need to know its extender CATID.
    // Parameters:  
    //    /* [out] */ BSTR *pbstrRetval);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ExtenderCATID)(
        /* [out] */ BSTR *pbstrRetval);

    //----------------------------------------------------------------------
    // Function:    get_FullName
    //      Returns the file system location of the project file, a full 
    //      pathname.
    // Parameters:  
    //    /* [out] */ BSTR *lpbstrReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_FullName)(
        /* [out] */ BSTR *lpbstrReturn);

    //----------------------------------------------------------------------
    // Function:    get_Saved
    //      Returns a Boolean value indicating whether or not the object was
    //      edited since the last time it was saved.
    // Parameters:  
    //    /* [out] */ VARIANT_BOOL *lpfReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Saved)(
        /* [out] */ VARIANT_BOOL *lpfReturn);

    //----------------------------------------------------------------------
    // Function:    put_Saved
    //      Sets a Boolean value indicating whether or not the object was
    //      edited since the last time it was saved.
    // Parameters:  
    //    /* [in] */ VARIANT_BOOL Dirty);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(put_Saved)(
        /* [in] */ VARIANT_BOOL Dirty);

    //----------------------------------------------------------------------
    // Function:    get_ConfigurationManager
    // Parameters:  
    //    /* [out] */ ConfigurationManager ** ppConfigurationManager);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ConfigurationManager)(
        /* [out] */ ConfigurationManager ** ppConfigurationManager);

    //----------------------------------------------------------------------
    // Function:    get_Globals
    //      Returns the object that holds values for an addin that are 
    //      persisted in the project's file.
    // Parameters:  
    //    /* [out] */ Globals ** ppGlobals);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Globals)(
        /* [out] */ Globals ** ppGlobals);

    //----------------------------------------------------------------------
    // Function:    Save
    //      Save the project, writing the project file, set options, etc.  
    //      If the full pathname is supplied, then this method acts like 
    //      SaveAs.
    // Parameters:  
    //    /* [in] */BSTR FileName);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(Save)(
        /* [in] */BSTR FileName);

    //----------------------------------------------------------------------
    // Function:    get_ParentProjectItem
    //      If the project is wrapped by a wrapper project, then this 
    //      property returns the ProjectItem object from the wrapping 
    //      project's automation model. The returned ProjectItem's.SubProject 
    //      property returns this project (the wrapped project).
    // Parameters:  
    //    /* [out] */ ProjectItem **ppProjectItem);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ParentProjectItem)(
        /* [out] */ ProjectItem **ppProjectItem);

    //----------------------------------------------------------------------
    // Function:    get_CodeModel
    //      Returns the CodeModel object for the project.
    // Parameters:  
    //    /* [out] */ CodeModel **ppCodeModel);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_CodeModel)(
        /* [out] */ CodeModel **ppCodeModel);

    //----------------------------------------------------------------------
    // Function:    Delete
    //      Removes the project from the solution and permanently deletes it
    //      from permanent storage.
    // Parameters:  
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(Delete)();

//                                                                   Project
// =========================================================================


// =========================================================================
//                                                      ISupportVSProperties
public:
    STDMETHOD(NotifyPropertiesDelete)();
//                                                      ISupportVSProperties
// =========================================================================

// =========================================================================
//                                                        ISupportsErrorInfo
public:
    IMPLEMENT_ISUPPORTERRORINFO(CAOProject)
//                                                        ISupportsErrorInfo
// =========================================================================

protected:
    CFileVwProjNode* m_pProjNode;
    bool m_fClosed;

private:
    CComPtr<ProjectItems> m_srpProjectItems;
    CComPtr<Globals>      m_srpGlobals;
};





///////////////////////////////////////////////////////////////////////////
// Class CAOProjectItemBase
// Base class for ProjectItem classes
// Implements ProjectItem
///////////////////////////////////////////////////////////////////////////
class CAOProjectItemBase :
    public CComObjectRootEx<CComSingleThreadModel>, // explict
    public IDispatchImpl<ProjectItem, &IID_ProjectItem, &LIBID_DTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>,
    public ISupportVSProperties,
    public ISupportErrorInfo
{
public:
    CAOProjectItemBase();
    virtual HRESULT Init(CHierNode* pNode);
    virtual ~CAOProjectItemBase(){};
    virtual void Close();
    virtual bool IsValid();

    BEGIN_COM_MAP(CAOProjectItemBase)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ProjectItem)
        COM_INTERFACE_ENTRY(ISupportVSProperties)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()
    
// =========================================================================
//                                                               ProjectItem

    //----------------------------------------------------------------------
    // Function:    get_IsDirty
    //      Returns a Boolean value indicating whether or not the object was
    //      edited since the last time it was saved.
    // Parameters:  
    //    /* [out, retval] */ VARIANT_BOOL  *lpfReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_IsDirty)(
        /* [out, retval] */ VARIANT_BOOL  *lpfReturn);

    //----------------------------------------------------------------------
    // Function:    put_IsDirty
    //      Sets a Boolean value indicating whether or not the object was
    //      edited since the last time it was saved.
    // Parameters:  
    //    /* [in]          */ VARIANT_BOOL DirtyFlag);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(put_IsDirty)(
        /* [in]          */ VARIANT_BOOL DirtyFlag);

    //----------------------------------------------------------------------
    // Function:    get_FileNames
    //      Returns the full pathnames of the files associated with a 
    //      project item. For most ProjectItems there is only one file, 
    //      When the ProjectItem represents a directory on disk, then the 
    //      .FileNames contains one name (the full pathname to the directory).
    // Parameters:  
    //    /* [in]          */ short   Index, 
    //    /* [out, retval] */ BSTR  * lpbstrReturn);
    // Returns:     HRESULT
    // Note:
    //----------------------------------------------------------------------
    STDMETHOD(get_FileNames)(
        /* [in]          */ short   Index, 
        /* [out, retval] */ BSTR  * lpbstrReturn);

    //----------------------------------------------------------------------
    // Function:    SaveAs
    //      Saves the project item using a new file name
    // Parameters:  
    //    /* [in]          */ BSTR            NewFileName, 
    //    /* [out, retval] */ VARIANT_BOOL  * lpfReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(SaveAs)(
        /* [in]          */ BSTR            NewFileName, 
        /* [out, retval] */ VARIANT_BOOL  * lpfReturn);

    //----------------------------------------------------------------------
    // Function:    get_FileCount
    //      Returns the number of files associated with the project item. 
    //      Project items can be stored across one or multiple files. 
    // Parameters:  
    //    /* [out, retval] */ short  * lpsReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_FileCount)(
        /* [out, retval] */ short  * lpsReturn);

    //----------------------------------------------------------------------
    // Function:    get_Name
    //      Returns the display name of the project item
    // Parameters:  
    //    /* [out, retval] */ BSTR * pbstrReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Name)(
        /* [out, retval] */ BSTR * pbstrReturn);

    //----------------------------------------------------------------------
    // Function:    put_Name
    //      Sets the display name of the project item
    // Parameters:  
    //    /* [in]          */ BSTR bstrName);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(put_Name)(
        /* [in]          */ BSTR bstrName);
    
    //----------------------------------------------------------------------
    // Function:    get_Collection
    //      Returns the collection that contains the object.
    // Parameters:  
    //    /* [out, retval] */ ProjectItems ** lppcReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Collection)(
        /* [out, retval] */ ProjectItems ** lppcReturn);

    //----------------------------------------------------------------------
    // Function:    get_Properties
    //      Returns a properties collection that represents all the 
    //      properties that pertain to the project item.
    // Parameters:  
    //    /* [out, retval] */ Properties **   ppObject);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Properties)(
        /* [out, retval] */ Properties **   ppObject);

    //----------------------------------------------------------------------
    // Function:    get_DTE
    //      Returns the top-level extensibility object.  In the Visual 
    //      Studio shell this is the same object as the Application object.
    // Parameters:  
    //    /* [out, retval] */ DTE **  lppaReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_DTE)(
        /* [out, retval] */ DTE **  lppaReturn);

    //----------------------------------------------------------------------
    // Function:    get_Kind
    //      Returns the kind of the project item. This information should be
    //      available in the package type library or documentation.
    // Parameters:  
    //    /* [out, retval] */ BSTR  * lpbstrFileName);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Kind)(
        /* [out, retval] */ BSTR  * lpbstrFileName);

    //----------------------------------------------------------------------
    // Function:    get_ProjectItems
    //      Returns a collection of project items that may be hierarchically 
    //      below the project item.
    // Parameters:  
    //    /* [out, retval] */ ProjectItems ** lppcReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ProjectItems)(
        /* [out, retval] */ ProjectItems ** lppcReturn);

    //----------------------------------------------------------------------
    // Function:    get_IsOpen
    //      Returns whether the ProjectItem is open for a particular view 
    //      (designer, editor, etc.).  Using vsViewKindPrimary asks if the 
    //      project item is open in any view, a slightly different meaning 
    //      than when you call ProjectItem.Open.
    // Parameters:  
    //    /* [in]          */ BSTR            ViewKind, 
    //    /* [out, retval] */ VARIANT_BOOL  * lpfReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_IsOpen)(
        /* [in]          */ BSTR            ViewKind, 
        /* [out, retval] */ VARIANT_BOOL  * lpfReturn);

    //----------------------------------------------------------------------
    // Function:    Open
    //      Opens the ProjectItem in the specified view. This method may 
    //      return an existing window if the ProjectItem is already open in 
    //      the specified view. 
    // Parameters:  
    //    /* [in]          */ BSTR        ViewKind, 
    //    /* [out, retval] */ Window **   lppfReturn);
    // Returns:     HRESULT
    // Notes:       Implementors should create and return the window hidden,
    //      and if addins want users to see the window, they should set 
    //      Window.Visible to True.
    //----------------------------------------------------------------------
    STDMETHOD(Open)(
        /* [in]          */ BSTR        ViewKind, 
        /* [out, retval] */ Window **   lppfReturn);

    //----------------------------------------------------------------------
    // Function:    Remove
    //      Removes the ProjectItem. If ProjectItem.ProjectItems is non-NULL,
    //      then this method removes all the items recursively.
    // Parameters:  
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(Remove)();

    //----------------------------------------------------------------------
    // Function:    ExpandView
    //      Expands views of the project structure to show the ProjectItem.
    //      For example, expand the view in the Solution Browser window to 
    //      show the ProjectItem in the tree control.
    // Parameters:  
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(ExpandView)();

    //----------------------------------------------------------------------
    // Function:    get_Object
    //      Returns the project-specific automation object.
    // Parameters:  
    //    /* [out, retval] */ IDispatch **    ProjectItemModel);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Object)(
        /* [out, retval] */ IDispatch **    ProjectItemModel);

    //----------------------------------------------------------------------
    // Function:    get_Extender
    //      Returns the requested extender object if it is available for 
    //      this ProjectItem implementation.  May return Nothing.
    // Parameters:  
    //    /* [in]          */ BSTR            ExtenderName, 
    //    /* [out, retval] */ IDispatch **    Extender);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Extender)(
        /* [in]          */ BSTR            ExtenderName, 
        /* [out, retval] */ IDispatch **    Extender);

    //----------------------------------------------------------------------
    // Function:    get_ExtenderNames
    //      Returns a safe array of string names of currently applicable 
    //      extenders for this ProjectItem implementation.
    // Parameters:  
    //    /* [out, retval] */ VARIANT *       ExtenderNames);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ExtenderNames)(
        /* [out, retval] */ VARIANT *       ExtenderNames);

    //----------------------------------------------------------------------
    // Function:    get_ExtenderCATID
    //      Returns the GUID string for the ProjectItem object that is the 
    //      category ID for searching for automation extenders. Implementers 
    //      of extenders for this object need to know its extender CATID.
    // Parameters:  
    //    /* [out, retval] */ BSTR *          pRetval);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ExtenderCATID)(
        /* [out, retval] */ BSTR *          pRetval);

    //----------------------------------------------------------------------
    // Function:    get_Saved
    //      Returns a Boolean value indicating whether or not the object was
    //      edited since the last time it was saved.
    // Parameters:  
    //    /* [out, retval] */ VARIANT_BOOL *  lpfReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Saved)(
        /* [out, retval] */ VARIANT_BOOL *  lpfReturn);

    //----------------------------------------------------------------------
    // Function:    put_Saved
    //
    //      Sets a Boolean value indicating whether or not the object was
    //      edited since the last time it was saved.
    // Parameters:  
    //    /* [in]          */ VARIANT_BOOL    SavedFlag);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(put_Saved)(
        /* [in]          */ VARIANT_BOOL    SavedFlag);

    //----------------------------------------------------------------------
    // Function:    get_ConfigurationManager
    // Parameters:  
    //    /* [out, retval] */ ConfigurationManager ** ppConfigurationManager);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ConfigurationManager)(
        /* [out, retval] */ ConfigurationManager ** ppConfigurationManager);

    //----------------------------------------------------------------------
    // Function:    get_FileCodeModel
    //      Returns the FileCodeModel object. This is returned only for 
    //      project items for code files.
    // Parameters:  
    //    /* [out, retval] */ FileCodeModel **    ppFileCodeModel);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_FileCodeModel)(
        /* [out, retval] */ FileCodeModel **    ppFileCodeModel);

    //----------------------------------------------------------------------
    // Function:    Save
    //      Save the project item if it is open and modified. If the full 
    //      pathname is supplied, then this method acts like .SaveAs.
    // Parameters:  
    //    /* [defaultvalue("")] */ BSTR FileName);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(Save)(
        /* [defaultvalue("")] */ BSTR FileName);

    //----------------------------------------------------------------------
    // Function:    get_Document
    //      Returns the Document if the project item is open.
    // Parameters:  
    //    /* [out, retval] */ Document ** ppDocument);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Document)(
        /* [out, retval] */ Document ** ppDocument);

    //----------------------------------------------------------------------
    // Function:    get_SubProject
    //      If the project is a wrapper project, and this item represents a 
    //      wrapped project, then this property returns the automation 
    //      object for the wrapped project. Otherwise, this property returns
    //      Nothing. If the wrapped project does not have an automation 
    //      object, then this property returns the unmodeled project 
    //      automation object.
    // Parameters:  
    //    /* [out, retval] */ Project **  ppProject);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_SubProject)(
        /* [out, retval] */ Project **  ppProject);

    //----------------------------------------------------------------------
    // Function:    get_ContainingProject
    //      This returns the Project object that contains this ProjectItem. 
    //      This property is a convenience shortcut for a multiline loop and
    //      conditional test to find the project that contains an item.
    // Parameters:  
    //    /* [out, retval] */ Project **  ppProject);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ContainingProject)(
        /* [out, retval] */ Project **  ppProject);

    //----------------------------------------------------------------------
    // Function:    Delete
    //      Removes the ProjectItem from the project and deletes it from 
    //      permanent storage, such as the disk. If ProjectItem.ProjectItems
    //      is non-NULL, then this method removes all the items recursively.
    // Parameters:  
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(Delete)();

//                                                               ProjectItem
// =========================================================================


// =========================================================================
//                                                      ISupportVSProperties
public:
    // Called when the wrapper properties object ref cnt reaches 0. 
    //  Set to null so the next time get_props is called, it is obtained again.
    STDMETHOD(NotifyPropertiesDelete)();
//                                                      ISupportVSProperties
// =========================================================================


// =========================================================================
//                                                        ISupportsErrorInfo
public:
    IMPLEMENT_ISUPPORTERRORINFO(CAOProjectItemBase)
//                                                        ISupportsErrorInfo
// =========================================================================

protected:


    //----------------------------------------------------------------------
    // Function:    SaveItem
    //      Common helper routine used by SaveAs & Save methods.
    //      Uses IVsPersistHierarchyItem::SaveItem to save the item.
    // Parameters:  
    //    /* [in]       */ VSSAVEFLAGS  dwSave,
    //      Flags to use in IVsPersistHierarchyItem::SaveItem.
    //    /* [in]       */ BSTR         bstrFileName,
    //      File name.
    //    /* [out, opt] */ BOOL*        pfCancelled  = NULL );
    //      Optional flag indicating whether the operation was cancelled.
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    virtual HRESULT SaveItem(
        /* [in]       */ VSSAVEFLAGS  dwSave,
        /* [in]       */ BSTR         bstrFileName,
        /* [out, opt] */ BOOL*        pfCancelled  = NULL );

    //----------------------------------------------------------------------
    // Function:    GetDocData
    //      Gets the DocData ptr (IVsPersistDocData) for the current document.
    // Parameters:  
    //    /* [in]       */ BOOL                fOpen,  
    //      Flag whether to try to open the document if it is not opened
    //    /* [out, opt] */ IVsPersistDocData** ppIVsPersistDocData,
    //      Optional parameter returnng the DocData
    //    /* [out, opt] */ BOOL *              pfOpenedDuringTheCall);
    //      Optional flag indicating whether the document was opened during 
    //      the function call (if the functoion was called with fOpen = TRUE)
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    virtual HRESULT GetDocData(
        /* [in]       */ BOOL                fOpen,  //try to open the document if not opened
        /* [out, opt] */ IVsPersistDocData** ppIVsPersistDocData,
        /* [out, opt] */ BOOL *              pfOpenedDuringTheCall);

    //----------------------------------------------------------------------
    // Function:    DeleteItem
    //      Common helper routine used by Remove and Delete.
    //      Uses IVsHierarchyDeleteHandler::DeleteItem to perform the 
    //      operation.
    // Parameters:  
    //    /* [in] */ VSDELETEITEMOPERATION dwDelItemOp);
    //      Operation to perform - Remove or Delete
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    virtual HRESULT DeleteItem(
        /* [in] */ VSDELETEITEMOPERATION dwDelItemOp);

    //----------------------------------------------------------------------
    // Function:    OpenItem
    //      Common helper routine used by Open and GetDosData.
    // Parameters:  
    //    /* [in] */ BOOL fShow);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    virtual HRESULT OpenItem(
        /* [in]          */ BSTR ViewKind, 
        /* [in]          */ BOOL fShow,
        /* [out, retval] */ Window **  lppfReturn);

protected:
    IVsHierarchy* GetIVsHierarchy();
    VSITEMID GetVsItemID();
    CHierNode* GetNode();

protected:
      CHierNode *m_pNode;
    Properties * m_pProperties;
    bool m_fClosed;
};





///////////////////////////////////////////////////////////////////////////
// Class CAOProjectItemFile
// Implements ProjectItem for a file node
///////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE CAOProjectItemFile :
    public CAOProjectItemBase
{

//==========================================================================
//                                          construct, init , copy, destruct
public:
    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              Creates an CAOProjectItemFile object
    // Parameters: 
    //    /* [in]  */ CFileVwFileNode* pNode, 
    //    /* [out] */ ProjectItem **ppProjectItem)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CreateInstance(
        /* [in]  */ CFileVwFileNode* pNode,
        /* [out] */ ProjectItem**    ppProjectItem);
        
protected:
    CAOProjectItemFile(){};
    virtual ~CAOProjectItemFile(){};
//                                          construct, init , copy, destruct
//==========================================================================


// =========================================================================
//                                                     overriden ProjectItem

    //----------------------------------------------------------------------
    // Function:    get_IsOpen
    //      Returns whether the ProjectItem is open for a particular view 
    //      (designer, editor, etc.).  Using vsViewKindPrimary asks if the 
    //      project item is open in any view, a slightly different meaning 
    //      than when you call ProjectItem.Open.
    // Parameters:  
    //    /* [in]          */ BSTR            ViewKind, 
    //    /* [out, retval] */ VARIANT_BOOL  * lpfReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_IsOpen)(
        /* [in]          */ BSTR            ViewKind, 
        /* [out, retval] */ VARIANT_BOOL  * lpfReturn);

//                                                     overriden ProjectItem
// =========================================================================

protected:
    // overriden to open a file
    //----------------------------------------------------------------------
    // Function:    OpenItem
    //      Common helper routine used by Open and GetDosData.
    // Parameters:  
    //    /* [in] */ BOOL fShow);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    virtual HRESULT OpenItem(
        /* [in]          */ BSTR       ViewKind, 
        /* [in]          */ BOOL       fShow,
        /* [out, retval] */ Window **  lppfReturn);

protected:
    CFileVwFileNode* GetFile();
};




///////////////////////////////////////////////////////////////////////////
// Class CAOProjectItemFolder
// Implements ProjectItem for a folder node
///////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE CAOProjectItemFolder :
    public CAOProjectItemBase
{

//==========================================================================
//                                          construct, init , copy, destruct
public:
    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              Creates an CAOProjectItemFile object
    // Parameters: 
    //    /* [in]  */ CFileVwFileNode* pNode, 
    //    /* [out] */ ProjectItem **ppProjectItem)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CreateInstance(
        /* [in]  */ CFileVwFolderNode* pNode,
        /* [out] */ ProjectItem**    ppProjectItem);
        
protected:
    CAOProjectItemFolder(){};
    virtual ~CAOProjectItemFolder(){};
//                                          construct, init , copy, destruct
//==========================================================================


// =========================================================================
//                                                     overriden ProjectItem
    //----------------------------------------------------------------------
    // Function:    get_Kind
    //      Returns the kind of the project item. This information should be
    //      available in the package type library or documentation.
    // Parameters:  
    //    /* [out, retval] */ BSTR  * lpbstrFileName);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Kind)(
        /* [out, retval] */ BSTR  * lpbstrFileName);

    //----------------------------------------------------------------------
    // Function:    get_ProjectItems
    //      Returns a collection that represents all the project items in 
    //      the project
    // Parameters:  
    //    /* [out] */ ProjectItems ** lppcReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ProjectItems)(
        /* [out] */ ProjectItems ** lppcReturn);

//                                                     overriden ProjectItem
// =========================================================================

protected:

protected:
    CFileVwFolderNode* GetFolder();
    CComPtr<ProjectItems> m_srpProjectItems;
};




///////////////////////////////////////////////////////////////////////////
// Class CAOSelectedItem
// Implements SelectedItem
// Getting the SelectedItem object is much like getting a ProjectItem object. 
// Your hierarchy implementation will have the IVsHierarchy::GetProperty method 
// called with the VSHPROPID_ExtSelectedItem propid.  
// SelectedItems is implemented by Visual Studio, and a package writer needs 
// not implement this. Also, your package does not need to implement this object
// because Visual Studio will provide a generic implementation. 
// However, you may want to provide this for yourself  
// If you wish to use the Shell's default implementation of SelectedItem, 
// then #define USEDEFAULTSELECTION
///////////////////////////////////////////////////////////////////////////
#ifndef USEDEFAULTSELECTION

class ATL_NO_VTABLE CAOSelectedItem : 
    public CComObjectRootEx<CComMultiThreadModel>,
    public IDispatchImpl<SelectedItem, &IID_SelectedItem, &LIBID_DTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>,
    public ISupportErrorInfo
{
public:
    static HRESULT CreateInstance(
        /* [in]  */ CFileVwFileNode* pNode,
        /* [out] */ SelectedItem **  ppSelectedItem);
    virtual void Close(){m_fClosed = true;};

protected:
    CAOSelectedItem() : m_fClosed(false) {}
    HRESULT Init(CFileVwFileNode * pNode);
    virtual bool IsValid(){return !m_fClosed;};

public:

    BEGIN_COM_MAP(CAOSelectedItem)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(SelectedItem)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()

// =========================================================================
//                                                              SelectedItem    
public:

    //----------------------------------------------------------------------
    // Function:    get_Collection
    //      Returns the SelectedItems collection that contains this object.
    // Parameters:  
    //    /* [out, retval] */ SelectedItems ** lppReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Collection)(
        /* [out, retval] */ SelectedItems ** lppReturn);

    //----------------------------------------------------------------------
    // Function:    get_DTE
    //      Returns the top-level extensibility object.
    // Parameters:  
    //    /* [out, retval] */ DTE ** lppReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_DTE)(
        /* [out, retval] */ DTE ** lppReturn);

    //----------------------------------------------------------------------
    // Function:    get_Project
    //      Returns the project of the selected item.
    // Parameters:  
    //    /* [out, retval] */ Project ** lppReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Project)(
        /* [out, retval] */ Project ** lppReturn);

    //----------------------------------------------------------------------
    // Function:    get_ProjectItem
    //      Returns the project item of the selected item.
    // Parameters:  
    //    /* [out, retval] */ ProjectItem ** lppReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ProjectItem)(
        /* [out, retval] */ ProjectItem ** lppReturn);

    //----------------------------------------------------------------------
    // Function:    get_Name
    //      Returns the display name of the item, for example, how it is 
    //      shown in the Project Browser.
    // Parameters:  
    //    /* [out, retval] */ BSTR  * lpbstrReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Name)(
        /* [out, retval] */ BSTR  * lpbstrReturn);

    //----------------------------------------------------------------------
    // Function:    get_InfoCount
    //      Returns the number of info strings in .Info.
    // Parameters:  
    //    /* [out, retval] */ short  * lpnCount);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_InfoCount)(
        /* [out, retval] */ short  * lpnCount);

    //----------------------------------------------------------------------
    // Function:    get_Info
    //      Returns the specified info string. For example, this could be a 
    //      full pathname to a file.
    // Parameters:  
    //    /* [in] */ short Index, 
    //    /* [out, retval] */ VARIANT  * lpbstrReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Info)(
        /* [in]          */ short       Index, 
        /* [out, retval] */ VARIANT  *  lpbstrReturn);

//                                                              SelectedItem    
// =========================================================================


// =========================================================================
//                                                        ISupportsErrorInfo
public:
    IMPLEMENT_ISUPPORTERRORINFO(CAOSelectedItem)
//                                                        ISupportsErrorInfo
// =========================================================================


protected:
    CFileVwFileNode *m_pNode;
    bool m_fClosed;
};
#endif //USEDEFAULTSELECTION



