
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsOutputGroup.h: interface for the CVsOutputGroup class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

// Output group types
typedef enum _OGT
{
    OGT_None = 0,               // no build action 
    OGT_Built,                  // exe/dll and other assembly files.
    OGT_ContentFiles,           // html, gif, etc.
    OGT_LocalizedResourceDlls,  // satellite dlls
    OGT_SourceFiles,            // sources
    OGT_Max = OGT_SourceFiles
} OUTPUTGROUPTYPE;

typedef CVxTypedPtrArray<CVxPtrArray, IVsOutput2*> IVsOutput2Array;


/////////////////////////////////////////////////////////////////////////
/* IVsOutputGroup : This construct allows projects to group outputs
 according to usage.  For instance, a DLL might be grouped with
 its PDB.  As mentioned in the comments for IVsProjectCfg2, the project must return
 the same number of groups for each configuration that it supports, even
 though the number of outputs contained within a group may vary from
 configuration to configuration.  For example, the group "Matt's DLL"
 might include mattd.dll and mattd.pdb in debug configuration, but
 only include matt.dll in retail configuration. The groups will also have
 the same identifier information (canonical name, display name, and group
 info) from configuration to configuration within a project.  This allows
 deployment and packaging to continue to operate even if configurations
 change.  Groups may also have a "key output" -- this allows packaging
 shortcuts to point to something meaningful.  Any group might be empty
 in a given configuration, so no assumptions should be made about the size
 of a group beyond the occassional "no more than one" constraint.


                               IVsProjectCfgProvider
                                        |
                 -------------------------------------------
                 |                                         |
        IVsProjectCfg2 ("Debug")                    IVsProjectCfg2 ("Retail")
                 |                                         |
                 |                                         |
    ---------------------------            ---------------------------
    |                         |            |                         |
  Group "Built"        Group "Source"    Group "Built"      Group "Source"
  ("Built code")       ("Source code")   ("Built code")      ("Source code") 
       |                      |                                      |                         |
 ----------------     ---------------      |                -------------------
 |              |     |             |                       |                 |                 |
"bD.EXE"    bD.PDB    b.cpp       b.h     "b.EXE"          b.cpp            b.h

The key output is in "".  
Group "Built" has a key output across configurations (either bD.exe or b.exe), 
so the user can create a shortcut to "Built", and know that the shortcut will 
work regardless of the configuration deployed.  Group "source" does not have 
a key output, so the user cannot create a shortcut to it.  If the debug group
"built" had a key output but the retail group "built" didn't, that would be 
WRONG.  The identity of the key output can vary across configurations, but 
not the fact that it has one.  It follows that if any configuration has a 
group that contains no outputs (and hence no key file), then other 
configurations with that group which do contain outputs cannot have key files.
The installer editors assume that canonical names & display names of groups, 
plus the existence of a key file, do not change based on configuration.

Note that if a project has an IVsOutput that it doesn't want to package/deploy,
it is sufficient to not put that output in a group.  The output can still
be enumerated normally via IVsProjectCfg::EnumOutputs, which returns all
of a configuration's outputs regardless of grouping.
*/

class CVsOutputGroup  :
    public IVsOutputGroup,
    public CComObjectRootEx<CComMultiThreadModel>
{
//==========================================================================
//                                                construct, init , destruct
public:

    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              To create an CVsOutputGroup object and return 
    //              IVsOutputGroup pointer.
    // Parameters: 
    //    /* [in]  */ IVsProjectCfg2*      pIVsProjectCfg2
    //              Pointer to the project configuration object.
    //
    //    /* [in]  */ OUTPUTGROUPTYPE ogt
    //              Type of the output group.
    //
    //    /* [out] */ IVsOutputGroup**     ppIVsOutputGroup
    //              
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CreateInstance(
        /* [in]  */ IVsProjectCfg2*      pIVsProjectCfg2, 
        /* [in]  */ OUTPUTGROUPTYPE ogt,
        /* [out] */ IVsOutputGroup**     ppIVsOutputGroup);


protected:
    CVsOutputGroup();
    virtual ~CVsOutputGroup();

    //----------------------------------------------------------------------
    // Function:    Init
    //              To initialize the object.
    // Parameters: 
    //    /* [in] */ IVsProjectCfg2*  pProjectCfg,
    //    /* [in] */ OUTPUTGROUPTYPE ogt);
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT Init(
        /* [in] */ IVsProjectCfg2*  pProjectCfg,
        /* [in] */ OUTPUTGROUPTYPE ogt);


    //----------------------------------------------------------------------
    // Function:    Term
    //              To release the resources used by the object.
    // Parameters: 
    // Returns:     
    // Notes:
    //----------------------------------------------------------------------
    void Term();

//                                                construct, init , destruct
//==========================================================================

BEGIN_COM_MAP(CVsOutputGroup)
    COM_INTERFACE_ENTRY(IVsOutputGroup)  // derives from IUnknown
END_COM_MAP()

//==========================================================================
//                                                            IVsOutputGroup
//
//--------------------------------------------------------------------------
//                                                  IVsOutputGroup interface
public:


    //----------------------------------------------------------------------
    // Function:    get_CanonicalName
    //              Get the canonical name of the group .
    // Parameters: 
    //    /* [out] */ BSTR *pbstrCanonicalName);
    // Returns:     HRESULT
    // Notes:
    //              Returns identical information regardless of the 
    //              configuration settings.
    //              The deployment project doesn't care what it is, so long 
    //              as it is unique within the groups but constant across 
    //              configurations.  The deployment project caches this, 
    //              so it can't change.
    //----------------------------------------------------------------------
    STDMETHOD(get_CanonicalName)(
        /* [out] */ BSTR *pbstrCanonicalName);

    //----------------------------------------------------------------------
    // Function:    get_DisplayName
    //              Get display name from the resources based 
    //              on output group type
    // Parameters: 
    //    /* [out] */ BSTR *pbstrDisplayName);
    // Returns:     HRESULT
    // Notes:
    //              Returns identical information regardless of the 
    //              configuration settings.
    //----------------------------------------------------------------------
    STDMETHOD(get_DisplayName)(
        /* [out] */ BSTR *pbstrDisplayName);


    //----------------------------------------------------------------------
    // Function:    get_KeyOutput
    // Parameters: 
    //    /* [out] */ BSTR *pbstrCanonicalName 
    //              The canonical name of the key output.
    //
    // Returns:     HRESULT
    // Notes:
    //              Results will vary based on the configuration:
    //              The primary purpose of this method is to determine if 
    //              the user can create a shortcut to this group during 
    //              installation and, if so, what file within this group 
    //              should be the target.  It returns the canonical name of 
    //              the appropriate IVsOutput.  The deployment project 
    //              doesn't cache the result; only caches *whether* it has a 
    //              key output. The deployment project analyzes the
    //              value when building/deploying, so the IVsOutput is free 
    //              to change its canonical name up until then (if the 
    //              canonical name is, for instance, the path to the output 
    //              (we don't recommend this, we prefer output canonical 
    //              names to be non-changing GUIDs). The key file may (and 
    //              probably will) vary across configuration for a given 
    //              group, but if it has a key file in one configuration, 
    //              it must have one in ALL configurations, and even if the 
    //              key file changes, the fact that it has one must not 
    //              change in either direction.
    //----------------------------------------------------------------------
    STDMETHOD(get_KeyOutput)(
        /* [out] */ BSTR *pbstrCanonicalName);

    //----------------------------------------------------------------------
    // Function:    get_ProjectCfg
    //              Back pointer to project cfg.
    // Parameters: 
    //    /* [out] */ IVsProjectCfg2 **ppIVsProjectCfg2);
    // Returns:     HRESULT
    // Notes:
    //              Results will vary based on the configuration.
    //----------------------------------------------------------------------
    STDMETHOD(get_ProjectCfg)(
        /* [out] */ IVsProjectCfg2 **ppIVsProjectCfg2);

    //----------------------------------------------------------------------
    // Function:    get_Outputs
    //              The list of outputs.  There might be none!  
    // Parameters: 
    //    /* [in]                     */ ULONG celt,
    //    /* [in, out, size_is(celt)] */ IVsOutput2 * rgpcfg[],
    //    /* [out, optional]          */ ULONG *pcActual);
    // Returns:     HRESULT
    // Notes:
    //              Not all files go out on every configuration, and a 
    //              groups files might all be configuration dependent!
    //              Results will vary based on the configuration.
    //----------------------------------------------------------------------
    STDMETHOD(get_Outputs)(
        /* [in]                     */ ULONG celt,
        /* [in, out, size_is(celt)] */ IVsOutput2* rgpIVsOutput2[],
        /* [out, optional]          */ ULONG *pcActual);

    //----------------------------------------------------------------------
    // Function:    get_DeployDependencies
    // Parameters: 
    //    /* [in]                     */ ULONG celt,
    //    /* [in, out, size_is(celt)] */ IVsDeployDependency * rgpdpd[],
    //    /* [out, optional]          */ ULONG *pcActual);
    // Returns:     HRESULT
    // Notes:
    //              Just return E_NOTIMPL if you have no dependencies.  
    //              Otherwise, return an array of IVsDeployDependencies, 
    //              The deployment project will merge them into the 
    //              installer and make sure they get deployed.
    //----------------------------------------------------------------------
    STDMETHOD(get_DeployDependencies)(
        /* [in]                     */ ULONG celt,
        /* [in, out, size_is(celt)] */ IVsDeployDependency * rgpdpd[],
        /* [out, optional]          */ ULONG *pcActual);

    STDMETHOD(get_Description)(
        /* [out] */ BSTR *pbstrDescription);

//                                                  IVsOutputGroup interface
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//                                                    IVsOutputGroup helpers
public:
    //----------------------------------------------------------------------
    // Function:    GetCanonicalNameFromOgt
    //              Get canonical name from the output group type.
    // Parameters: 
    //    /* [in]  */ OUTPUTGROUPTYPE ogt, 
    //    /* [out] */ BSTR* pbstrName)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT GetCanonicalNameFromOgt(
        /* [in]  */ OUTPUTGROUPTYPE ogt, 
        /* [out] */ BSTR* pbstrName);

protected:
    //----------------------------------------------------------------------
    // Function:    GetDisplayNameFromOgt
    //              Get display name from the output group type.
    // Parameters: 
    //    /* [in]  */ OUTPUTGROUPTYPE ogt, 
    //    /* [out] */ CString& strName)
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    HRESULT GetDisplayNameFromOgt(
        /* [in]  */ OUTPUTGROUPTYPE ogt, 
        /* [out] */ CString& strName);

        
//                                                    IVsOutputGroup helpers
//--------------------------------------------------------------------------
//
//                                                            IVsOutputGroup
//==========================================================================
    

//==========================================================================
//                                                                   Members
protected:
    CComPtr<IVsProjectCfg2>  m_srpIVsProjectCfg2;
    IVsOutput2Array  m_rgpIVsOutput2;    
    OUTPUTGROUPTYPE     m_ogt;       // output group type.
    BOOL m_fOutputsAdded;
};
//                                                                   Members
//==========================================================================
