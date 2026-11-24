
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

/***                              
*   VsLibraryMgr.h
*****************************************************************************/


#pragma once

// The class that implements the IVsLibraryMgr interface
class CVsLibraryMgr:
    public IVsLibraryMgr,
    public CComObjectRoot
{
    BEGIN_COM_MAP(CVsLibraryMgr)
        COM_INTERFACE_ENTRY(IVsLibraryMgr)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CVsLibraryMgr);
       
//==========================================================================
//                                                construct, init , destruct
public:

    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              To create an CVsLibraryMgr object and return 
    //              IVsLibraryMgr pointer.
    // Parameters: 
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CVsLibraryMgr::CreateInstance(
            /* [out] */ IVsLibraryMgr**   ppIVsLibraryMgr);

protected:
    CVsLibraryMgr();

    // ---------------------------------------------------------------------
    // Init: 
    //      Initializes the library manager, creates and initializes 
    //      the library object.
    //
    // ---------------------------------------------------------------------
    STDMETHOD(Init)();
    
    STDMETHOD(Close)(); 
    virtual ~CVsLibraryMgr();
    
//                                                construct, init , destruct
//==========================================================================

//==========================================================================
//                                                             CVsLibraryMgr
//
protected:
    //Check if this is a valid index
    STDMETHOD_(BOOL, IsValidIndex)(
        /* [in] */ ULONG uIndex);

//
//                                                             CVsLibraryMgr
//==========================================================================

//==========================================================================
//                                                            IVsLibraryMgr
//
public:

    // ---------------------------------------------------------------------
    //  GetCount: 
    //  [propget] HRESULT Count([out, retval] ULONG *pnCount);
    //  Return the number of libraries known by this manager
    //
    //  pnCount: Return value.
    // ---------------------------------------------------------------------
    STDMETHOD(GetCount)(
        /* [out, retval] */ ULONG *pnCount);


    // ---------------------------------------------------------------------
    // GetLibraryAt: 
    //  Return a library interface for the designated library
    //
    // nLibIndex: Library index
    // ppLibrary: Return value, pointer to the library interface
    // ---------------------------------------------------------------------
    STDMETHOD(GetLibraryAt)(
        /* [in]          */ ULONG         uIndex, 
        /* [out, retval] */ IVsLibrary ** ppLibrary);


    // --------------------------------------------------------------------
    // GetNameAt: 
    //  Return a displayable name for the designated library
    //
    // nLibIndex : Library index
    // pszName: Return value, name of the library.
    // --------------------------------------------------------------------
    STDMETHOD(GetNameAt)(
        /* [in]          */ ULONG    uIndex, 
        /* [out, retval] */ WCHAR ** pszName);


    // --------------------------------------------------------------------
    // ToggleCheckAt: 
    //  Set the selected state for a library item
    //
    // nLibIndex: Library index
    // --------------------------------------------------------------------
    STDMETHOD(ToggleCheckAt)(
        /* [in] */ ULONG uIndex);


    // ---------------------------------------------------------------------
    // GetCheckAt: 
    //  [propget] HRESULT GetCheckAt(
    //                      [in] ULONG nLibIndex, 
    //                      [out, retval] LIB_CHECKSTATE *pstate);
    //  Get the selected state for a library item
    //
    // nLibIndex  : Library index
    // ---------------------------------------------------------------------
    STDMETHOD(GetCheckAt)(
        /* [in] */          ULONG            uIndex, 
        /* [out, retval] */ LIB_CHECKSTATE * pstate);

    // ---------------------------------------------------------------------
    // SetLibraryGroupEnabled: 
    // Library picker needs to tell library manager if top level group is enabled
    //
    //    /* [in] */ LIB_PERSISTTYPE lpt, 
    //    /* [in] */ BOOL fEnable)
    //
    // ---------------------------------------------------------------------
    STDMETHOD(SetLibraryGroupEnabled)(
        /* [in] */ LIB_PERSISTTYPE lpt, 
        /* [in] */ BOOL fEnable);



//
//                                                            IVsLibraryMgr
//==========================================================================


protected:

    //Hold pointers to the project and reference libraries
    CVxTypedPtrArray<CVxPtrArray, ILibrary*> m_rgpILibrary;
};

