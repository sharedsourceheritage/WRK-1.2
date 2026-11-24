
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsProjectStartupServices.h: Definition of the CVsProjectStartupServices class
//
//////////////////////////////////////////////////////////////////////

#pragma once

class CGuid
{
public:
    static HRESULT CreateInstance(
            /* [in]  */ REFGUID guid,
            /* [out] */ CGuid** ppCGuid);
protected:
    CGuid();
    CGuid(REFGUID guid);
public:
    REFGUID GetGuid();
    ULONG   AddRef();
    ULONG   Release();
protected:
    GUID  m_guid;
    DWORD m_dwRef;
};


class CProjectStartupService
{
public:
    static HRESULT CreateInstance(
            /* [in]  */ REFGUID guid,
            /* [out] */ CProjectStartupService** ppService);

    virtual ~CProjectStartupService();
protected:
            CProjectStartupService();
            HRESULT Init(REFGUID guid);

public:
    HRESULT StartService();
    HRESULT StopService();
    CGuid*  GetCGuid();
    REFGUID GetGuid();

protected:
    CGuid*            m_pguidService;
    CComPtr<IUnknown> m_srpUnkService;
};

typedef CVxTypedPtrArray<CVxPtrArray, CProjectStartupService*> ProjectStartupServiceArray;

/////////////////////////////////////////////////////////////////////////////
// CVsProjectStartupServices

class CVsProjectStartupServices  
{

//==========================================================================
//                                                construct, init , destruct
public:
	CVsProjectStartupServices();
	virtual ~CVsProjectStartupServices();
//                                                construct, init , destruct
//==========================================================================


//==========================================================================
//                                                 IVsProjectStartupServices 
public:
    //----------------------------------------------------------------------
    // Function:    AddStartupService
    //              Adds a service id GUID to the array, but does not call 
    //              QS on the service here.
    // Parameters:  
    //    /*[in]*/ REFGUID guidService);
    //              service GUID to add
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(AddStartupService)(
        /*[in]*/ REFGUID guidService);

    //----------------------------------------------------------------------
    // Function:    RemoveStartupService
    //              Removes a service id GUID from the array
    // Parameters:  
    //    /*[in]*/ REFGUID guidService);
    //              service GUID to remove
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(RemoveStartupService)(
        /*[in]*/ REFGUID guidService);

    //----------------------------------------------------------------------
    // Function:    GetStartupServiceEnum
    // Parameters:  
    //    /*[out]*/ IEnumProjectStartupServices **ppEnum);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(GetStartupServiceEnum)(
        /*[out]*/ IEnumProjectStartupServices **ppEnum);

protected:
    //----------------------------------------------------------------------
    // Function:    Find
    //              Lookup an array element by GUID
    // Parameters:  
    //    /*[in] */ REFGUID guid, 
    //              Service GUID to look for
    //    /*[out]*/ ULONG*  puIndex = NULL);
    //              Index in the array if the service was found.
    //              The index is valid only when S_OK is returned.
    // Returns:     HRESULT
    //              Returns S_OK, or S_FALSE if not found
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Find)(
        /*[in] */ REFGUID guid, 
        /*[out]*/ ULONG*  puIndex = NULL);

//                                                 IVsProjectStartupServices
//==========================================================================

//==========================================================================
//                                                           Service Control

public:
    //----------------------------------------------------------------------
    // Function:    StartServices
    //              Starts (QS) the services in the array.
    // Parameters:  None
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(StartServices)();

    //----------------------------------------------------------------------
    // Function:    StopServices
    //              Stops (releases) the services in the array.
    // Parameters:  None
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(StopServices)();
//                                                           Service Control
//==========================================================================


//==========================================================================
//                                                                persisting
public:
    //----------------------------------------------------------------------
    // Function:    Load
    //              Loads saved services
    //
    // Parameters:  
    //  /* [in] */ IVsPropertyStreamIn *pIVsPropertyStreamIn 
    //              Stream to load from
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Load)(
        /* [in] */ IVsPropertyStreamIn *pIVsPropertyStreamIn);


    //----------------------------------------------------------------------
    // Function:    Save
    //              Saves services
    //
    // Parameters:  
    //  /* [in] */ IVsPropertyStreamOut *pIVsPropertyStreamOut 
    //              Stream to save to
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Save)(
        /* [in] */ IVsPropertyStreamOut *pIVsPropertyStreamOut);

//                                                                persisting
//==========================================================================

//==========================================================================
//                                                                   members
private:
    static const LPCWSTR    ms_pszKey_ID;

    // Pointers to the CProjectStartupService
    ProjectStartupServiceArray  m_rgpCProjectStartupService;
//
//==========================================================================

};


typedef CVxTypedPtrArray<CVxPtrArray, CGuid*> CGuidArray;

////////////////////////////////////////////////////////////////////////////
class CEnumProjectStartupServices :
    public IEnumProjectStartupServices,
    public CComObjectRootEx<CComSingleThreadModel>
{

//==========================================================================
//                                                construct, init , destruct
public:

    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              Creates an CEnumProjectStartupServices object
    // Parameters: 
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CEnumProjectStartupServices::CreateInstance(
        /* [in]  */ ProjectStartupServiceArray* pProjectStartupServiceArray,
        /* [out] */ IEnumProjectStartupServices** ppIEnumProjectStartupServices);

protected:

    //----------------------------------------------------------------------
    // Function:    Init
    //              Initializes the enumerator
    // Parameters: 
    //    /* [in] */ ProjectStartupServiceArray* pProjectStartupServiceArray,
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT Init(
        /* [in] */ ProjectStartupServiceArray* pProjectStartupServiceArray);

    //----------------------------------------------------------------------
    // Function:    Init
    //              Initializes the enumerator - used for cloning
    // Parameters: 
    //    /* [in] */ CGuidArray* pCGuidArray,
    //    /* [in] */ ULONG uIndex);
    //              The index to start iterating at (for cloning)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT Init(
        /* [in] */ CGuidArray* pCGuidArray,
        /* [in] */ ULONG uIndex);

    //----------------------------------------------------------------------
    // Function:    ~CVsEnumOutputs
    //              Destroy this enumerator..
    // Parameters: 
    // Returns:     
    // Notes:
    //----------------------------------------------------------------------
    ~CEnumProjectStartupServices(); 


//                                                construct, init , destruct
//==========================================================================

    BEGIN_COM_MAP(CEnumProjectStartupServices)
        COM_INTERFACE_ENTRY(IEnumProjectStartupServices)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CEnumProjectStartupServices);

public:

    //----------------------------------------------------------------------
    // Function:    Reset
    //              Reset the enumerator back to the beginning.
    // Parameters: 
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Reset());


    //----------------------------------------------------------------------
    // Function:    Next
    //              Get the next set of elements in the iterator.
    // Parameters: 
    //    /* [in] */ ULONG celt,
    //              the size of the element array.
    //    /* [out, size_is(celt), length_is(*pceltFetched)] */ GUID *rgelt, 
    //    /* [out]                                          */ ULONG *pceltFetched);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Next)(
        /* [in]                                           */ ULONG celt, 
        /* [out, size_is(celt), length_is(*pceltFetched)] */ GUID *rgelt, 
        /* [out]                                          */ ULONG *pceltFetched);


    //----------------------------------------------------------------------
    // Function:    Skip
    // Parameters: 
    //    /* [in] */ ULONG celt);
    //              the number of elements to skip
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Skip)(
        /* [in] */ ULONG celt);

    //----------------------------------------------------------------------
    // Function:    Clone
    //              Make a copy of this enumerator.
    // Parameters: 
    //    /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs);
    //              the clone of the enumerator
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Clone)(
        /* [out] */ IEnumProjectStartupServices ** ppenum);


//==========================================================================
//                                                                   Members
protected:
    CGuidArray m_rgpCGuid;
    ULONG      m_uGuidIndex;
//                                                                   Members
//==========================================================================
};
