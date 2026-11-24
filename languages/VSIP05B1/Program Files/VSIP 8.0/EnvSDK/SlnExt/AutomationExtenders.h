
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


/***************************************************************************
File name   : AutomationExtenders.h
Description : Declaration of the following automation extender objects:
              1) class CSlnStaticExtender
              2) class CSlnStaticExtenderProvider
              4) class CSlnDynamicExtender
              3) class CSlnDynamicExtenderProvider
***************************************************************************/

///////////////////////////////////////////////////////////////////////////
// Automation Extenders
//
//  Automation Extenders are typically light-weight OLE automation objects 
//  that add properties / methods to an existing Automation Object (Extendee).
//  Extenders are implemented as COM objects. An Extender typically extends 
//  a specific implementation of an automation interface (rather than just 
//  an automation interface) and must have some specific knowledge of the 
//  implementation to talk to it. This specific interface implementation is 
//  identified by an Extender Category ID (or CATID).
//  An Extender is basically a COM object that is given an Extendee instance 
//  when it is created and implements an IDispatch to add additional properties 
//  and methods to that extendee. It can also choose to implement an optional 
//  interface (IFilterProperties) to hide some of the extendee's properties 
//  from the client (the user of the automation object). 
//  Extenders are created through its Extender Provider
//  Automation Extenders are registered in VS7 either statically, by adding 
//  keys in the VS registry, or dynamically, by calling appropriate methods 
//  on the Extension Manager service.
//  While the GUID valued Category ID denotes the particular automation object
//  being extended, we need to distinguish between different Extensions to the 
//  same object, often provided by two totally separate Extenders. This is done 
//  through the Extender Name (string based). 
//  Extenders are also free to choose their preferred mechanism for persistence 
//  of the Extended properties. Typically they will call upon the Extendee 
//  to do this for them (for instance, if the Extendee supports a generic 
//  property bag), but they can also chose to persist / de-persist these on 
//  their own.
//  An Automation Object (Extendee) can prepare itself for being extended 
//  by defining a CATID for itself and supporting the following 3 members on
//  its automation interface:
//  - get_Extender
//  - get_ExtenderNames
//  - get_ExtenderCATID
//  For implementation of these methods check BscPrj, FigPrj, and MycPrj
//  samples in Environment SDK
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
// SlnExt Extenders
//
//  The SlnExt sample demonstrates two extensions:
//  I) SlnStaticExtender
//      This is a simple Extender, named "MyExtension", that extends the 
//      Solution Browse object as well as the C++, C#, and VB project browse 
//      objects by adding a string-valued "MyProperty" using their 
//      INSTRINIC CATIDS.
//      The Extender is statically registered (see Automation.rgs script).
//      Class CSlnStaticExtenderProvider represents the extender provider and 
//      class CSlnStaticExtender represents the extender.
//      In case of the solution, the shell creates and reuses the same
//      Solution Browse Object instance across solution opens/closes for the 
//      same VS session so the extender tracks solution open/close events and
//      updates the property value.
//      The extender persists the property value in Solution File's Globals or 
//      Project Files's Globals section.
//      Using the SlnStaticExtender:
//      1. Launch the VS7 shell and create or open a solution.
//      2. With the properties grid visible, select the Solution node in the
//         project explorer.
//      3. Notice the new property "MyProperty" in the property grid.
//      4. Also "MyProperty" property will be displayed in the property grid 
//         when a VB, C#, or VC project is selected in the Project Explorer.
//  II) SlnDynamicExtender
//      This is a simple Extender, named "SolutionNotes", that extends the
//      Solution and Solution Browse Objects by adding "NoteCount" property.
//      The property returns the number of notes in the SolutionNotes window.
//      The Extender is dynamically registered during the package 
//      SetSite call.
//      Class CSlnDynamicExtenderProvider represents the extender provider and 
//      class CSlnDynamicExtender represents the extender.
//      Using the SlnDynamicExtender:
//      1. Launch the VS7 shell and create or open a solution.
//      2. With the properties grid visible, select the Solution node in the
//         project explorer.
//      3. Notice the new property "NoteCount" in the property grid.
//      4. The NoteCount property can be also accessed by using the Solution 
//         object - DTE.Solution.Extender("SolutionNotes").NoteCount
//      
//
//
// Creating an Extender in C++ (statically registered)
//  1. Create a COM coclass that implements IExtenderProvider. 
//  2. Create a simple COM object (doesn't need to be a coclass) that is
//  the extender object that supports IDispatch (essential) and optionally 
//  IFilterProperties (if you plan to filter any properties on the object 
//  you're extending). Add the properties (puts and gets) on the IDispatch 
//  that you're adding/overriding.
//  3. Implement IExtenderProvider on your provider. CanExtend should check
//  if you're being called on the right CATID that you're extending and
//  with the right name and any other checks on the extendee itself.
//  GetExtender should actually create an extender class (defined in #2), 
//  init it and return it out.
//  4. To implement the extender class itself, you must:
//    a. Implement your IDispatch properties
//    b. Implement IFilterProperties::IsPropertyHidden if you are
//    hiding/replacing some properties.
//    c. Implement an Init method that caches at least the provided
//    site and cookie (and most likely also the extendee so you can
//    talk to it)
//    d. In its destructor or FinalRelease(), call NotifyDelete()
//    on the site passing the cookie back.
//  5. Finally add registration code in your .rgs to register your
//  extender provider with the shell. This registration is of the form
//  HKLM\SOFTWARE\Microsoft\VisualStudio\7.1\Extenders\<CATID your're extending>\<ExtensionName>
//  @="<CLSID of Extender Provider>"
//


#pragma once

// forward declarations
class CSlnExtPackage;

#ifndef DTE_LIB_VERSION_MAJ
    #define DTE_LIB_VERSION_MAJ 7
#endif
#ifndef DTE_LIB_VERSION_MIN
    #define DTE_LIB_VERSION_MIN 0
#endif


///////////////////////////////////////////////////////////////////////////
// Class CSlnStaticExtender
// Implements ISlnStaticExtender
///////////////////////////////////////////////////////////////////////////
class CSlnStaticExtender : 
    public CComObjectRoot,
    //  Note: In case of the solution, the shell creates and reuses the same
    //  Solution Browse Object instance across solution opens/closes for the same VS
    //  session. To do this correctly your extender provider/extender should track
    //  solution open and close events.
    public IVsSolutionEvents,
    public IDispatchImpl<ISlnStaticExtender, &IID_ISlnStaticExtender, &LIBID_SlnExtAutoLib, 1, 0>
    //  An Extender that wants to hide properties from display in the Property
    //  Browser must implement an additional interface, IFilterProperties.
    // public IDispatchImpl<IFilterProperties, &IFilterProperties, &LIBID_SlnExtAutoLib, 1, 0>
{
//==========================================================================
//                                          construct, init , copy, destruct
public:
    // create an extender instance
    static HRESULT CreateInstance(
        /* [in]  */ BSTR             bstrExtenderCATID, 
        /* [in]  */ IDispatch *      pdispExtendeeObject, 
        /* [in]  */ IExtenderSite *  pIExtenderSite,
        /* [in]  */ long             lCookie,
        /* [out] */ IDispatch **     ppIDispatch);

    // close all extenders
    static void CloseAll();

protected:
    CSlnStaticExtender();
    HRESULT FinalConstruct() { return S_OK; };
    HRESULT Init(
        /* [in] */ BSTR             bstrExtenderCATID, 
        /* [in] */ IDispatch *      pdispExtendeeObject, 
        /* [in] */ IExtenderSite *  pIExtenderSite,
        /* [in] */ long             lCookie);

    HRESULT Reset();
    void Close();
    void FinalRelease() {};
    virtual ~CSlnStaticExtender();
//                                          construct, init , copy, destruct
//==========================================================================

public:
    BEGIN_COM_MAP(CSlnStaticExtender)
        COM_INTERFACE_ENTRY(ISlnStaticExtender)
        COM_INTERFACE_ENTRY(IVsSolutionEvents)
        COM_INTERFACE_ENTRY2(IDispatch, ISlnStaticExtender)
        // COM_INTERFACE_ENTRY(IFilterProperties)
    END_COM_MAP()

    //DECLARE_NOT_AGGREGATABLE(CSlnStaticExtender) 
    // Remove the comment from the line above if you don't want your object to 
    // support aggregation. 

    DECLARE_PROTECT_FINAL_CONSTRUCT()

//==========================================================================
//                                                        ISlnStaticExtender    
public:
    STDMETHOD(put_MyProperty)(
        /* [in] */ BSTR  bstrPropVal);

    STDMETHOD(get_MyProperty)(
        /* [out] */BSTR *pbstrPropVal);
//                                                        ISlnStaticExtender    
//==========================================================================


//==========================================================================
//                                                         IVsSolutionEvents
//
public:

    STDMETHOD(OnAfterOpenProject)(
        /* [in] */ IVsHierarchy *pHierarchy, 
        /* [in] */ BOOL fAdded) {return S_OK;};

    STDMETHOD(OnQueryCloseProject)(
        /*[in]    */ IVsHierarchy *pHierarchy, 
        /*[in]    */ BOOL fRemoving, 
        /*[in,out]*/ BOOL *pfCancel) {return S_OK;};

    STDMETHOD(OnBeforeCloseProject)(
        /*[in]*/ IVsHierarchy *pHierarchy, 
        /*[in]*/ BOOL fRemoved) {return S_OK;};

    STDMETHOD(OnAfterLoadProject)(
        /*[in]*/ IVsHierarchy *pStubHierarchy, 
        /*[in]*/ IVsHierarchy *pRealHierarchy) {return S_OK;};

    STDMETHOD(OnQueryUnloadProject)(
        /*[in]    */ IVsHierarchy *pRealHierarchy, 
        /*[in,out]*/ BOOL *pfCancel) {return S_OK;};

    STDMETHOD(OnBeforeUnloadProject)(
        /*[in]*/ IVsHierarchy *pRealHierarchy, 
        /*[in]*/ IVsHierarchy *pStubHierarchy) {return S_OK;};

    STDMETHOD(OnAfterOpenSolution)(
        /*[in]*/ IUnknown *pUnkReserved, 
        /*[in]*/ BOOL fNewSolution);

    STDMETHOD(OnQueryCloseSolution)(
        /*[in]    */ IUnknown *pUnkReserved, 
        /*[in,out]*/ BOOL *pfCancel) {return S_OK;};

    STDMETHOD(OnBeforeCloseSolution)(
        /*[in]*/ IUnknown *pUnkReserved) {return S_OK;};

    STDMETHOD(OnAfterCloseSolution)(
        /*[in]*/ IUnknown *pUnkReserved) {return S_OK;};

//                                                         IVsSolutionEvents
//==========================================================================

private:
    static CEnvSDKPtrArray<CSlnStaticExtender> ms_rgCSlnStaticExtender;
    
    CComPtr<IDispatch>      m_srpdispExtendeeObject;// pointer to the Extendee
    CComPtr<IExtenderSite>  m_srpIExtenderSite;     // pointer to the Site
    long                    m_lCookie;              // cookie

    //Cookie used to hook up the solution events.
    VSCOOKIE                m_vscookieIVsSolutionEvents;

    // Pointer to a Project corresponding to the extended browse object
    // if we extend Solution browse object this pointer will be null
    CComPtr<Project>        m_srpProject;

    // Pointer to a _Solution corresponding to the extended browse object
    // if we extend Project browse object this pointer will be null
    CComPtr<_Solution>      m_srpSolution;

    CComBSTR                m_cbstrExtenderCATID;

    // our properties
    CComBSTR                m_cbstrProperty;        // MyProperty

    //  An Extender may or may not keep a back pointer to the ExtensionProvider
    //  that created it.
};




///////////////////////////////////////////////////////////////////////////
// Class CSlnStaticExtenderProvider
// Implements IExtenderProvider and ISlnStaticExtenderProvider interfaces
//  The ExtenderProvider is responsible for creating an Extender instance 
//  for the Extendee Automation Object in question (a particular instance) 
//  under the given CATID and ExtenderName through the GetExtender method. 
//  Extender Ptoviders are created either by the Extension Manager itself 
//  (in the case of static registry-based extensions) or by some client code 
//  that then dynamically registers them with the Extension Manager. 
///////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE CSlnStaticExtenderProvider : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CSlnStaticExtenderProvider, &CLSID_SlnStaticExtenderProvider>,
    public IDispatchImpl<ISlnStaticExtenderProvider, &IID_ISlnStaticExtenderProvider, &LIBID_SlnExtAutoLib, 1, 0>,
    public IDispatchImpl<IExtenderProvider, &IID_IExtenderProvider, &LIBID_EnvDTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>
{
//==========================================================================
//                                          construct, init , copy, destruct
public:
    CSlnStaticExtenderProvider() {};
    void FinalRelease() {};
    HRESULT FinalConstruct() { return S_OK; };
    ~CSlnStaticExtenderProvider() {};
//                                          construct, init , copy, destruct
//==========================================================================


//==========================================================================
//                                                                       ATL 
    BEGIN_COM_MAP(CSlnStaticExtenderProvider)
        COM_INTERFACE_ENTRY(ISlnStaticExtenderProvider)
        COM_INTERFACE_ENTRY(IExtenderProvider)
        COM_INTERFACE_ENTRY2(IDispatch, ISlnStaticExtenderProvider)
    END_COM_MAP()

    DECLARE_PROTECT_FINAL_CONSTRUCT()
//                                                                       ATL 
//==========================================================================


//==========================================================================
//                                                              Registration
    //---------------------------------------------------------------------
    // Function:    UpdateRegistry
    //              Contruct the _ATL_REGMAP_ENTRY and update the registry. 
    // Parameters: 
    //    /* [in] */ BOOL bRegister 
    //              Flag - to register or unregister
    //
    // Returns:     HRESULT
    //
    // Notes:
    //              Certain strings that will be seen by the user need to be 
    //              put in the registry. The VS way of doing this is to put 
    //              the string in the registry as '#40' where 40 is the 
    //              resource id of the string in the satellite dll (so that 
    //              the string can be localized properly). Unfortunately, if
    //              we put '#40' in the rgs file, then someone can change the 
    //              id of the string. This routine sets up a symbol table of 
    //              replacements for things found in the rgs file, and then 
    //              calls the appropriate routine to register the rgs file 
    //              after it's been preprocessed.
    //              Also, to make the rgs file easy to understand, replacement 
    //              variables for CLSIDs and GUIDs are used. The names of 
    //              the CLSIDs and GUIDs are used rather than the 
    //              corresponding values. 
    //  
    //              Replacement variables used in registry script (.rgs) files:
    //              MODULE          - standard ATL replacement variable
    //              REGROOTBEGIN    - opening string for the Visual Studio 
    //                  registry root (i.e., "NoRemove Software \n{\n NoRemove 
    //                  Microsoft \n{\n NoRemove VisualStudio \n{\n NoRemove 7.1 
    //                  \n{\n")
    //              REGROOTEND      - closing string for the Visual Studio 
    //                  registry root (i.e., L"\n}\n \n}\n \n}\n \n}\n")
    //              CLSID_Package        - package CLSID
    //              RESOURCE_DLL    - resource dll name
    //              RESOURCE_PATH   - resource dll path
    //
    //              For CLSIDs, GUIDs, and resource IDs the corresponding 
    //              name is used also for replacement variable. For example, 
    //              GUID_TaskList or IDS_PACKAGE_LOAD_KEY.
    //
    //              CLSID_xxx   - replacement variable for xxx CLSID
    //              GUID_xxx    - replacement variable for xxx GUID
    //              IDS_xxx     - replacement variable for xxx resource id
    //---------------------------------------------------------------------
    static HRESULT WINAPI UpdateRegistry(
        /* [in] */ BOOL bRegister);

//                                                              Registration
//==========================================================================


//==========================================================================
//                                                ISlnStaticExtenderProvider
public:
//                                                ISlnStaticExtenderProvider
//==========================================================================


//==========================================================================
//                                                         IExtenderProvider
public:
    //----------------------------------------------------------------------
    // Function:    GetExtender
    //      Creates an Extender instance for the Extendee Automation Object 
    //      in question (a particular instance) under the given CATID and 
    //      ExtenderName.
    // Parameters:  
    //    /* [in]          */ BSTR            bstrExtenderCATID, 
    //    /* [in]          */ BSTR            bstrExtenderName, 
    //    /* [in]          */ IDispatch *     pdispExtendeeObject,
    //    /* [in]          */ IExtenderSite * pExtenderSite,
    //    /* [in]          */ long            lCookie, 
    //    /* [out, retval] */ IDispatch **    ppdispExtender);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(GetExtender)( 
        /* [in]          */ BSTR            bstrExtenderCATID, 
        /* [in]          */ BSTR            bstrExtenderName, 
        /* [in]          */ IDispatch *     pdispExtendeeObject,
        /* [in]          */ IExtenderSite * pExtenderSite,
        /* [in]          */ long            lCookie, 
        /* [out, retval] */ IDispatch **    ppdispExtender);


    //----------------------------------------------------------------------
    // Function:    CanExtend
    //      Answers the question as to whether the specified Extender is 
    //      available for the given Extension (CATID and Extension Name) for 
    //      the specific instance.
    // Parameters:  
    //    /* [in]          */ BSTR            bstrExtenderCATID, 
    //    /* [in]          */ BSTR            bstrExtenderName, 
    //    /* [in]          */ IDispatch *     pdispExtendeeObject, 
    //    /* [out, retval] */ VARIANT_BOOL *  pfRetval);
    // Returns:     HRESULT
    // Notes:       Note that it is possible that the ExtenderProvider is able
    //      to create an Extension for the given CATID and Extension Name but 
    //      doesn't want to for the given Extendee instance (typically decided
    //      by property inspection on the Extendee).
    //----------------------------------------------------------------------
    STDMETHOD(CanExtend)( 
        /* [in]          */ BSTR            bstrExtenderCATID, 
        /* [in]          */ BSTR            bstrExtenderName, 
        /* [in]          */ IDispatch *     pdispExtendeeObject, 
        /* [out, retval] */ VARIANT_BOOL *  pfRetval);
//                                                         IExtenderProvider
//==========================================================================

protected:
    //members
};




class ATL_NO_VTABLE CSlnDynamicExtender :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<ISlnDynamicExtender, &IID_ISlnDynamicExtender, &LIBID_SlnExtAutoLib>
{
//==========================================================================
//                                          construct, init , copy, destruct
public:
    static HRESULT CreateInstance(
        /* [in]  */ IDispatch *      pdispExtendeeObject, 
        /* [in]  */ IExtenderSite *  pIExtenderSite,
        /* [in]  */ long             lCookie,
        /* [in]  */ ISolutionNotes * pISolutionNotes, 
        /* [out] */ IDispatch **     ppIDispatch);
protected:
    STDMETHOD(Init)(
        /* [in]  */ IDispatch *      pdispExtendeeObject, 
        /* [in]  */ IExtenderSite *  pIExtenderSite,
        /* [in]  */ long             lCookie,
        /* [in]  */ ISolutionNotes * pISolutionNotes);

    ~CSlnDynamicExtender();
//                                          construct, init , copy, destruct
//==========================================================================
public:
    BEGIN_COM_MAP(CSlnDynamicExtender)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ISlnDynamicExtender)
    END_COM_MAP()

//==========================================================================
//                                                       ISlnDynamicExtender
public:
    STDMETHOD(get_NoteCount)(long* pCount);
//                                                       ISlnDynamicExtender
//==========================================================================

private:
    
    CComPtr<IDispatch>      m_srpdispExtendeeObject;// pointer to the Extendee
    CComPtr<IExtenderSite>  m_srpIExtenderSite;     // pointer to the Site
    long                    m_lCookie;              // cookie
    
    CComPtr<ISolutionNotes> m_srpISolutionNotes;    // pointer to the window

    //  An Extender may or may not keep a back pointer to the ExtensionProvider
    //  that created it.
};



///////////////////////////////////////////////////////////////////////////
// Class CSlnDynamicExtenderProvider
// Implements IExtenderProvider 
// Demonstrates dynamically registered extender provider.
///////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE CSlnDynamicExtenderProvider : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IExtenderProvider, &IID_IExtenderProvider, &LIBID_EnvDTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>
{
//==========================================================================
//                                          construct, init , copy, destruct
public:
    static HRESULT CreateInstance(
        /* [in]  */ CSlnExtPackage *                pPackage, 
        /* [out] */ CSlnDynamicExtenderProvider **  ppCSlnDynamicExtenderProvider);
    void Close();

protected:
    CSlnDynamicExtenderProvider();
    HRESULT Init(
        /* [in]  */ CSlnExtPackage * pPackage);

    void FinalRelease() {};
    HRESULT FinalConstruct() { return S_OK; };
    ~CSlnDynamicExtenderProvider(){};
//                                          construct, init , copy, destruct
//==========================================================================


//==========================================================================
//                                                                       ATL 
    BEGIN_COM_MAP(CSlnDynamicExtenderProvider)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IExtenderProvider)
    END_COM_MAP()

    DECLARE_PROTECT_FINAL_CONSTRUCT()
//                                                                       ATL 
//==========================================================================


//==========================================================================
//                                                         IExtenderProvider
public:
    //----------------------------------------------------------------------
    // Function:    GetExtender
    //      Creates an Extender instance for the Extendee Automation Object 
    //      in question (a particular instance) under the given CATID and 
    //      ExtenderName.
    // Parameters:  
    //    /* [in]          */ BSTR            bstrExtenderCATID, 
    //    /* [in]          */ BSTR            bstrExtenderName, 
    //    /* [in]          */ IDispatch *     pdispExtendeeObject,
    //    /* [in]          */ IExtenderSite * pExtenderSite,
    //    /* [in]          */ long            lCookie, 
    //    /* [out, retval] */ IDispatch **    ppdispExtender);
    // Returns:     HRESULT
    //----------------------------------------------------------------------
    STDMETHOD(GetExtender)( 
        /* [in]          */ BSTR            bstrExtenderCATID, 
        /* [in]          */ BSTR            bstrExtenderName, 
        /* [in]          */ IDispatch *     pdispExtendeeObject,
        /* [in]          */ IExtenderSite * pExtenderSite,
        /* [in]          */ long            lCookie, 
        /* [out, retval] */ IDispatch **    ppdispExtender);


    //----------------------------------------------------------------------
    // Function:    CanExtend
    //      Answers the question as to whether the specified Extender is 
    //      available for the given Extension (CATID and Extension Name) for 
    //      the specific instance.
    // Parameters:  
    //    /* [in]          */ BSTR            bstrExtenderCATID, 
    //    /* [in]          */ BSTR            bstrExtenderName, 
    //    /* [in]          */ IDispatch *     pdispExtendeeObject, 
    //    /* [out, retval] */ VARIANT_BOOL *  pfRetval);
    // Returns:     HRESULT
    // Notes:       Note that it is possible that the ExtenderProvider is able
    //      to create an Extension for the given CATID and Extension Name but 
    //      doesn't want to for the given Extendee instance (typically decided
    //      by property inspection on the Extendee).
    //----------------------------------------------------------------------
    STDMETHOD(CanExtend)( 
        /* [in]          */ BSTR            bstrExtenderCATID, 
        /* [in]          */ BSTR            bstrExtenderName, 
        /* [in]          */ IDispatch *     pdispExtendeeObject, 
        /* [out, retval] */ VARIANT_BOOL *  pfRetval);
//                                                         IExtenderProvider
//==========================================================================

protected:
    CSlnExtPackage* m_pPackage;

    // registration cookie
    long m_lSolutionCookie;
    long m_lSolutionBrowseObjectCookie;
};
