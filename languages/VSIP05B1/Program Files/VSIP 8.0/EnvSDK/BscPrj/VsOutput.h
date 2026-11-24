
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsOutput.h: interface for the CVsOutput class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

class ATL_NO_VTABLE CVsOutput :
    public IVsOutput2,      // -> IVsOutput
    public CComObjectRootEx<CComMultiThreadModel>
{


//==========================================================================
//                                          construct, init , copy, destruct
public:
    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              Creates an CVsOutput object
    // Parameters: 
    //    /* [in]  */ IVsProjectCfg* pIVsProjectCfg, 
    //    /* [in]  */ const CString& strAbsPath,
    //    /* [out] */ IVsOutput2 **ppOutput)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CreateInstance(
        /* [in]  */ IVsProjectCfg* pIVsProjectCfg, 
        /* [in]  */ const CString& strAbsPath,
        /* [out] */ IVsOutput2 **ppOutput);
        

protected:
    CVsOutput();
    virtual ~CVsOutput();

    //----------------------------------------------------------------------
    // Function:    Init
    //              Initializes the object 
    // Parameters: 
    //    /* [in] */ IVsProjectCfg *pProjectCfg , 
    //    /* [in] */ const CString& strAbsPath);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT Init(
        /* [in] */ IVsProjectCfg *pProjectCfg , 
        /* [in] */ const CString& strAbsPath);

    //----------------------------------------------------------------------
    // Function:    Term
    //              Releases the resources used by the object
    // Parameters: 
    // Returns:     
    // Notes:
    //----------------------------------------------------------------------
    void Term();
//                                          construct, init , copy, destruct
//==========================================================================


BEGIN_COM_MAP(CVsOutput)
    COM_INTERFACE_ENTRY(IVsOutput)             // derives from IUnknown
    COM_INTERFACE_ENTRY(IVsOutput2)            // derives from IVsOutput
END_COM_MAP()


//==========================================================================
//                                                                 IVsOutput
//
public:

    //----------------------------------------------------------------------
    // Function:    get_DisplayName
    //              Get the display name 
    // Parameters: 
    //    /*[out]*/ BSTR *pbstrDisplayName);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(get_DisplayName)(
        /*[out]*/ BSTR *pbstrDisplayName);


    //----------------------------------------------------------------------
    // Function:    get_CanonicalName
    //              Get the canonical name 
    // Parameters: 
    //    /*[out]*/ BSTR *pbstrCanonicalName);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(get_CanonicalName)(
        /*[out]*/ BSTR *pbstrCanonicalName);


    //----------------------------------------------------------------------
    // Function:    get_DeploySourceURL
    //              The DeploySourceURL is the web location of the item.  
    // Parameters: 
    //    /*[out]*/ BSTR *pbstrDeploySourceURL);
    // Returns:     HRESULT
    // Notes:
    //              For items in the local filesystem, the URL should begin 
    //              with the eight characters:"file:///".  
    //              Consumers of outputs may not be able to process URLs of
    //              other forms, so it's very important for projects that 
    //              are generating URLs for local items to try to use this 
    //              form of URL as much as possible.
    //----------------------------------------------------------------------
    STDMETHOD(get_DeploySourceURL)(
        /*[out]*/ BSTR *pbstrDeploySourceURL);


    //----------------------------------------------------------------------
    // Function:    get_Type
    // Parameters: 
    //    /*[out]*/ GUID *pguidType);
    // Returns:     HRESULT
    // Notes:       Output item types are represented by GUIDs defined by the 
    //              environment and by packages. They indicate whether or not 
    //              an output item contains embedded objects. For example,
    //              GUID_NULL -              No embedded objects 
    //              GUID_VS_OTYPE_PACKAGE - .cab, .zip, or setup .exe that contain files  
    //              GUID_VS_OTYPE_ACTIVEX - .dll or .ocx that contain ActiveX controls  
    //----------------------------------------------------------------------
    STDMETHOD(get_Type)(
            /*[out]*/ GUID *pguidType);

//                                                                 IVsOutput
//==========================================================================

    
//==========================================================================
//                                                                IVsOutput2 


    //----------------------------------------------------------------------
    // Function:    get_RootRelativeURL
    // Parameters: 
    //    /* [out] */ BSTR *pbstrRelativePath); 
    // Returns:     HRESULT
    // Notes:
    //              get_RelativePath is useful for web-based project outputs
    //              from which the relative path cannot automatically be 
    //              calculated (because they're not currently local, and ergo
    //              don't match up with the value of get_RootURL on the 
    //              project cfg).  
    //              Returns the output's path relative to the application 
    //              directory WHEN INSTALLED.  This is only really useful 
    //              for web projects -- sometimes web outputs are relatively 
    //              different in where they go vs. where they are in the 
    //              project directory.  It's also useful when an output is 
    //              located outside of a project's directory.  
    //              IVsOutput::get_DeploySourceURL() is not helpful in 
    //              determining where the deployment project should install 
    //              this output relative to others.  If you're not a 
    //              hierarchical project, though, you should just return "."
    //----------------------------------------------------------------------
    STDMETHOD(get_RootRelativeURL)(
        /* [out] */ BSTR *pbstrRelativePath); 


    //----------------------------------------------------------------------
    // Function:    get_Property
    // Parameters: 
    //    /* [in]  */ LPCOLESTR szProperty,
    //    /* [out] */ VARIANT *pvar);
    // Returns:     HRESULT
    // Notes:
    //              This is a catch-all to handle coordination between 
    //              third-party projects and their deployment plugins.  
    //              The property and its variant type are known to both 
    //              sides.
    //----------------------------------------------------------------------
    STDMETHOD(get_Property)(
        /* [in]  */ LPCOLESTR szProperty,
        /* [out] */ VARIANT *pvar);

//                                                                IVsOutput2 
//==========================================================================


protected:
    CString         m_strAbsPath;
    IVsProjectCfg*  m_srpIVsProjectCfg;

};


