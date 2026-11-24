
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


/***************************************************************************
File name   : AutomationCollections.h
Description : Declaration of the following automation collections:
              1) class CACProjects 
              2) class CACProjectItems
***************************************************************************/

#pragma once

// forward declarations
class CFileVwProjNode;

///////////////////////////////////////////////////////////////////////////
// Class CACProjects
// Implements VxDTE::Projects
// An IDispatch pointer is returned from IVsPackage::GetAutomationObject 
// for g_wszAutomationProjects
///////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE CACProjects :
    public CComObjectRootEx<CComSingleThreadModel>, // explict
    public IDispatchImpl<Projects, &IID_Projects, &LIBID_DTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>,
    public ISupportErrorInfo
{
public:
    static HRESULT CreateInstance(
        /* [out] */ IDispatch **     ppIDispatch);
	virtual void Close();

protected:
	CACProjects() : m_fClosed(false) {};
    virtual ~CACProjects(void){};
	virtual bool IsValid();

public:
	BEGIN_COM_MAP(CACProjects)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(Projects)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
	END_COM_MAP()

// =========================================================================
//                                                                  Projects

    //----------------------------------------------------------------------
    // Function:    Item
    //      Returns the indexed item where the index is numeric or string.
    // Parameters:  
    //    /* [in] */          VARIANT     index, 
    //      Item to locate in collection by name or position.
    //    /* [out, retval] */ Project **  lppcReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(Item)(
        /* [in] */          VARIANT     index, 
        /* [out, retval] */ Project **  lppcReturn);

    //----------------------------------------------------------------------
    // Function:    get_Parent
    //      Returns the parent object.
    // Parameters:  
    //    /* [out, retval] */ DTE **lppaReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Parent)(
        /* [out, retval] */ DTE **lppaReturn);

    //----------------------------------------------------------------------
    // Function:    get_Count
    //      Returns the count of Project objects in the collection
    // Parameters:  
    //    /* [out, retval] */ long  * lplReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Count)(
        /* [out, retval] */ long  * lplReturn);

    //----------------------------------------------------------------------
    // Function:    _NewEnum
    // Parameters:  
    //    /* [out, retval] */ IUnknown **lppiuReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(_NewEnum)(
        /* [out, retval] */ IUnknown **lppiuReturn);

    //----------------------------------------------------------------------
    // Function:    get_DTE
    //      Returns the top-level extensibility object.  In the Visual 
    //      Studio shell this is the same object as the Application object.
    // Parameters:  
    //    /* [out, retval] */ DTE **lppaReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_DTE)(
        /* [out, retval] */ DTE **lppaReturn);

    //----------------------------------------------------------------------
    // Function:    get_Properties
    //      Returns a properties collection that represents all the 
    //      properties that pertain to the project
    // Parameters:  
    //    /* [out, retval] */ Properties **ppObject);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Properties)(
        /* [out, retval] */ Properties **ppObject);

    //----------------------------------------------------------------------
    // Function:    get_Kind
    //      Returns the kind of the projects collection. This information 
    //      should be available in the package type library or documentation.
    // Parameters:  
    //    /* [out, retval] */ BSTR  *lpbstrReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Kind)(
        /* [out, retval] */ BSTR  *lpbstrReturn);

//                                                                  Projects
// =========================================================================


// =========================================================================
//                                                        ISupportsErrorInfo
    IMPLEMENT_ISUPPORTERRORINFO(CACProjects)
//                                                        ISupportsErrorInfo
// =========================================================================

protected:
	bool m_fClosed;
};




///////////////////////////////////////////////////////////////////////////
// Class CACProjectItems
// Implements VxDTE::ProjectItems

class ATL_NO_VTABLE CACProjectItems :
    public CComObjectRootEx<CComSingleThreadModel>, // explict
    public IDispatchImpl<ProjectItems, &IID_ProjectItems, &LIBID_DTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>,
    public ISupportErrorInfo
{
public:
    static HRESULT CreateInstance(
        /* [in]  */ CFileVwProjNode* pProjNode,
        /* [out] */ ProjectItems**   ppProjectItems);
	virtual void Close();

protected:
	CACProjectItems() : m_fClosed(false) {};
	HRESULT Init(
        /* [in] */ CFileVwProjNode* pProjNode);
	virtual bool IsValid();

public:

	BEGIN_COM_MAP(CACProjectItems)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ProjectItems)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
	END_COM_MAP()

// =========================================================================
//                                                              ProjectItems
public:

    //----------------------------------------------------------------------
    // Function:    Item
    //      Returns the Indexed item where the index is numeric or string.
    // Parameters:  
    //    /* [in]          */ VARIANT         index, 
    //    /* [out, retval] */ ProjectItem **  lppcReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(Item)(
        /* [in]          */ VARIANT         index, 
        /* [out, retval] */ ProjectItem **  lppcReturn);

    //----------------------------------------------------------------------
    // Function:    get_Parent
    //      Returns the parent object.
    // Parameters:  
    //    /* [out, retval] */ IDispatch **    lppptReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Parent)(
        /* [out, retval] */ IDispatch **    lppptReturn);

    //----------------------------------------------------------------------
    // Function:    get_Count
    //      Returns the count of Project objects in the collection
    // Parameters:  
    //    /* [out, retval] */ long  * lplReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Count)(
        /* [out, retval] */ long  * lplReturn);

    //----------------------------------------------------------------------
    // Function:    _NewEnum
    // Parameters:  
    //    /* [out, retval] */ IUnknown ** lppiuReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(_NewEnum)(
        /* [out, retval] */ IUnknown ** lppiuReturn);

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
    //      Returns the kind of the projectitems collection. This information 
    //      should be available in the package type library or documentation.
    // Parameters:  
    //    /* [out, retval] */ BSTR  * lpbstrReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_Kind)(
        /* [out, retval] */ BSTR  * lpbstrReturn);

    //----------------------------------------------------------------------
    // Function:    AddFromFile
    //      Adds a ProjectItem from a file already installed in the project 
    //      directory structure. If the file is not in the project directory 
    //      structure, it should be added with a link if possible.
    // Parameters:  
    //    /* [in]          */ BSTR            FileName, 
    //    /* [out, retval] */ ProjectItem **  lppcReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(AddFromFile)(
        /* [in]          */ BSTR            FileName, 
        /* [out, retval] */ ProjectItem **  lppcReturn);

    //----------------------------------------------------------------------
    // Function:    AddFromTemplate
    //      Adds a ProjectItem from a file, copying the file to the directory 
    //      containing the ProjectItems and performing any template processing 
    //      the project may determine is appropriate.
    // Parameters:  
    //    /* [in]          */ BSTR            FileName, 
    //      The file to copy to the ProjectItems directory and add to the 
    //      ProjectItems collection.
    //    /* [in]          */ BSTR            Name, 
    //      The filename with extension to give the item in the directory 
    //      associated with the ProjectItems collection.
    //    /* [out, retval] */ ProjectItem **  lppcReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(AddFromTemplate)(
        /* [in]          */ BSTR            FileName, 
        /* [in]          */ BSTR            Name, 
        /* [out, retval] */ ProjectItem **  lppcReturn);

    //----------------------------------------------------------------------
    // Function:    AddFromDirectory
    //      It takes the full pathname of a directory. It adds a ProjectItem 
    //      to the ProjectITems collection and then sets the new 
    //      ProjectItem.ProjectItems property to a collection of items, one 
    //      for each element in the named directory. AddFromDirectory 
    //      recursively adds all items from subdirectories. AddFromDirectory 
    //      returns the first newly created ProjectItem object described above.
    // Parameters:  
    //    /* [in]          */ BSTR            Directory, 
    //    /* [out, retval] */ ProjectItem **  lppcReturn);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(AddFromDirectory)(
        /* [in]          */ BSTR            Directory, 
        /* [out, retval] */ ProjectItem **  lppcReturn);

    //----------------------------------------------------------------------
    // Function:    get_ContainingProject
    //      This returns the Project object that contains this ProjectItems 
    //      collection. If this is the top-level ProjectItems collection, 
    //      then this property returns the same object as ProjectItems.Parent.
    // Parameters:  
    //    /* [out, retval] */ Project **ppProject);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(get_ContainingProject)(
        /* [out, retval] */ Project **ppProject);

    //----------------------------------------------------------------------
    // Function:    AddFolder
    //      This adds a folder ProjectItem to the ProjectItems collection and 
    //      returns the newly created ProjectItem object. Its ProjectItems 
    //      collection will be empty. Some project kinds do not support 
    //      adding certain kinds of folders (for example, vsFolderKindVirtual).
    // Parameters:  
    //    /* [in]          */ BSTR            Name, 
    //      The name of the folder within this ProjectItems.
    //    /* [in]          */ BSTR            Kind, 
    //      The kind of folder.  This defaults to vsFolderKindPhysical.
    //    /* [out, retval] */ ProjectItem **  ppProjectItem);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(AddFolder)(
        /* [in]          */ BSTR            Name, 
        /* [in]          */ BSTR            Kind, 
        /* [out, retval] */ ProjectItem **  ppProjectItem);

    //----------------------------------------------------------------------
    // Function:    AddFromFileCopy
    //      Adds a ProjectItem from a file already installed in the project 
    //      directory structure, or copying it verbatim if necessary to move 
    //      it into the project directory.  This method differs from 
    //      AddFromFile because it does not add a link, and it differs from 
    //      AddFromTemplate in that it does not template processing and does 
    //      not necessarily copy the file.
    // Parameters:  
    //    /* [in]          */ BSTR            FilePath, 
    //    /* [out, retval] */ ProjectItem **  ppProjectItem);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(AddFromFileCopy)(
        /* [in]          */ BSTR            FilePath, 
        /* [out, retval] */ ProjectItem **  ppProjectItem);


//                                                              ProjectItems
// =========================================================================


// =========================================================================
//                                                        ISupportsErrorInfo
public:
    IMPLEMENT_ISUPPORTERRORINFO(CACProjectItems)
//                                                        ISupportsErrorInfo
// =========================================================================

protected: 

	CFileVwProjNode* m_pProjNode;
	bool m_fClosed;
};
// Class CACProjectItems
///////////////////////////////////////////////////////////////////////////
