
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


#pragma once

class CVsEnumOutputs : 
    public IVsEnumOutputs,
    public CComObjectRootEx<CComSingleThreadModel>
{

//==========================================================================
//                                                construct, init , destruct
public:

    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              Creates an CVsEnumOutputs object
    // Parameters: 
    //        /* [in]  */ IVsProjectCfg2* pIVsProjectCfg2,
    //        /* [in]  */ ULONG uOutput,
    //        /* [out] */ IVsEnumOutputs** ppIVsEnumOutputs)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CVsEnumOutputs::CreateInstance(
            /* [in]  */ IVsProjectCfg2* pIVsProjectCfg2,
            /* [in]  */ ULONG uOutput,
            /* [out] */ IVsEnumOutputs** ppIVsEnumOutputs);

protected:

    //----------------------------------------------------------------------
    // Function:    Init
    //              Initializes the enumerator.
    // Parameters: 
    //    /* [in] */ IVsProjectCfg2* pIVsProjectCfg2 
    //              The project configuration to iterate over
    //    /* [in] */ ULONG uOutput);
    //              The output to start iterating at (for cloning)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT Init(
        /* [in] */ IVsProjectCfg2* pIVsProjectCfg2,
        /* [in] */ ULONG uOutput);

    //----------------------------------------------------------------------
    // Function:    ~CVsEnumOutputs
    //              Destroy this enumerator..
    // Parameters: 
    // Returns:     
    // Notes:
    //----------------------------------------------------------------------
    ~CVsEnumOutputs(); 

    //----------------------------------------------------------------------
    // Function:    Term
    //              Releases the resources used by the object
    // Parameters: 
    // Returns:     
    // Notes:
    //----------------------------------------------------------------------
    void Term();

//                                                construct, init , destruct
//==========================================================================

    BEGIN_COM_MAP(CVsEnumOutputs)
        COM_INTERFACE_ENTRY(IVsEnumOutputs)
    END_COM_MAP()

    DECLARE_NOT_AGGREGATABLE(CVsEnumOutputs);

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
    //    /* [in] */ ULONG cElements,
    //              the size of the element array.
    //    /* [in, out, size_is(cElements)] */ IVsOutput *rgpIVsOutput[], 
    //    /* [out, optional]               */ ULONG *pcElementsFetched);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Next)(
        /* [in]                          */ ULONG cElements, 
        /* [in, out, size_is(cElements)] */ IVsOutput *rgpIVsOutput[], 
        /* [out, optional]               */ ULONG *pcElementsFetched);


    //----------------------------------------------------------------------
    // Function:    Skip
    // Parameters: 
    //    /* [in] */ ULONG cElements);
    //              the number of elements to skip
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Skip)(
        /* [in] */ ULONG cElements);

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
        /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs);

//==========================================================================
//                                                                   Members
protected:

    CComPtr<IVsProjectCfg2> m_srpIVsProjectCfg2;
    ULONG m_uOutput;
    IVsOutput2Array  m_rgpIVsOutput2;    
//                                                                   Members
//==========================================================================
};
