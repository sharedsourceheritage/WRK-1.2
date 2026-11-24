
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


/***************************************************************************
File name   : AutomationExtenders.cpp
Description : Implementation of the following automation objects:
              1) class CSlnStaticExtender
              2) class CSlnStaticExtenderProvider
              3) class CSlnDynamicExtenderProvider
              4) class CSlnDynamicExtender
***************************************************************************/

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"
#include "AutomationExtenders.h"

const CComBSTR cbstrMyExtension = L"MyExtension";
const WCHAR wszSolutionNotesExtension[] = L"SolutionNotes";

const CHAR prjCATIDVCProjectBrowseObject[] = "{EE8299CB-19B6-4f20-ABEA-E1FD9A33B683}";

////////////////////////////////////////////////////////////////////////////
//                                                       CSlnStaticExtender
/* static */ CEnvSDKPtrArray<CSlnStaticExtender> CSlnStaticExtender::ms_rgCSlnStaticExtender;

//==========================================================================
//                                          construct, init , copy, destruct

/* static */
HRESULT CSlnStaticExtender::CreateInstance(
    /* [in]  */ BSTR             bstrExtenderCATID, 
    /* [in]  */ IDispatch *      pdispExtendeeObject, 
    /* [in]  */ IExtenderSite *  pIExtenderSite,
    /* [in]  */ long             lCookie,
    /* [out] */ IDispatch **     ppIDispatch)
{
    if (!bstrExtenderCATID)
        return E_POINTER;
    if (!pdispExtendeeObject)
        return E_POINTER;
    if (!pIExtenderSite)
        return E_POINTER;
    if (!ppIDispatch)
        return E_POINTER;
    *ppIDispatch = NULL;

    CComObject<CSlnStaticExtender>* pco = NULL;
    HRESULT hr = CComObject<CSlnStaticExtender>::CreateInstance(&pco);
    IfFailRet(hr);

    pco->AddRef();
    hr = pco->Init(bstrExtenderCATID, pdispExtendeeObject, pIExtenderSite, lCookie);
    if (SUCCEEDED(hr))
    {
        hr = pco->QueryInterface(IID_IDispatch, (void**)ppIDispatch);
    }
    pco->Release();

    IfFailRet(hr);

    ms_rgCSlnStaticExtender.Add((CSlnStaticExtender*)pco);

    return hr;
}


/* static */
void CSlnStaticExtender::CloseAll()
{
    int i ;
    for (i = 0; i < (int)ms_rgCSlnStaticExtender.Count(); i++)
    {
        // keep them alive during Close
        ms_rgCSlnStaticExtender.GetAt(i)->AddRef();
        ms_rgCSlnStaticExtender.GetAt(i)->Close();
    }
    // now release them
    for (i = 0; i < (int)ms_rgCSlnStaticExtender.Count(); i++)
        ms_rgCSlnStaticExtender.GetAt(i)->Release();
}


CSlnStaticExtender::CSlnStaticExtender() : 
    m_lCookie(0),
    m_vscookieIVsSolutionEvents(VSCOOKIE_NIL)
{
}


HRESULT CSlnStaticExtender::Init(
    /* [in] */ BSTR             bstrExtenderCATID, 
    /* [in] */ IDispatch *      pdispExtendeeObject, 
    /* [in] */ IExtenderSite *  pIExtenderSite,
    /* [in] */ long             lCookie)
{
    HRESULT hr = S_OK;
    USES_CONVERSION;

    m_cbstrExtenderCATID    = bstrExtenderCATID;
    m_lCookie               = lCookie;
    m_srpIExtenderSite      = pIExtenderSite;       // Does an Addref
    m_srpdispExtendeeObject = pdispExtendeeObject;  // Does an Addref

    hr = Reset();
    IfFailRet(hr);

    // if we are extending the solution browse object 
    // sync up to the Solution Events so we handle solution open/close
    if (m_srpSolution)
    {
        IVsSolution* pIVsSolution = _AtlModule.GetIVsSolution();
        ExpectedExprRet(pIVsSolution != NULL);

        hr = pIVsSolution->AdviseSolutionEvents(
            static_cast<IVsSolutionEvents *> (this), 
            &m_vscookieIVsSolutionEvents);
        IfFailRet(hr);
    }

    return hr;
}


HRESULT CSlnStaticExtender::Reset()
{
    HRESULT hr = S_OK;
    USES_CONVERSION;

    // m_cbstrExtenderCATID and m_srpdispExtendeeObject 
    // must be initialized when we are called

    // clear the extendee-specific data;
    m_srpSolution.Release();
    m_srpProject.Release();
    m_cbstrProperty.Empty();

    // now get a pointer to the Project or Solution object coresponding to the
    // pdispExtendeeObject browse object

    CComDispatchDriver cddExtendeeObject(m_srpdispExtendeeObject);

    if ( vsCATIDSolutionBrowseObject && _wcsicmp(m_cbstrExtenderCATID, A2CW(vsCATIDSolutionBrowseObject)) == 0)
    {
        // we extend solution browse object

        // get the dte object
        CComPtr<_DTE> srp_DTE;
        hr = _AtlModule.QueryService(SID_SDTE, IID__DTE, (void **)&srp_DTE);
        IfFailRet(hr);
        ExpectedExprRet(srp_DTE != NULL);

        // get the Solution object
        hr = srp_DTE->get_Solution( (Solution**) &m_srpSolution );
        IfFailRet(hr);
        ExpectedExprRet(m_srpSolution != NULL);

        // get the Solution's Globals collection
        CComPtr<Globals> srpGlobals;
        hr = m_srpSolution->get_Globals(&srpGlobals);
        IfFailRet(hr);
        ExpectedExprRet(srpGlobals != NULL);

        CComVariant cvar;
        hr = srpGlobals->get_VariableValue(cbstrMyExtension, &cvar);
        // might fail for new solutions
        if (SUCCEEDED(hr))
            m_cbstrProperty = cvar.bstrVal;

        return S_OK;
    }

    LPCWSTR strCATIDVCProjectBrowseObject = A2CW(prjCATIDVCProjectBrowseObject);
    LPCWSTR strCATIDVBProjectBrowseObject = A2CW(prjCATIDVBProjectBrowseObject);
    LPCWSTR strCATIDCSharpProjectBrowseObject = A2CW(prjCATIDCSharpProjectBrowseObject);
    if ( (NULL == strCATIDVCProjectBrowseObject) ||
         (NULL == strCATIDVBProjectBrowseObject) ||
         (NULL == strCATIDCSharpProjectBrowseObject) )
        return E_OUTOFMEMORY;

    // project file
    CComBSTR cbstrProjectFile;
    if ( _wcsicmp(m_cbstrExtenderCATID, strCATIDVCProjectBrowseObject) == 0)
    {
        // we extend VC project browse object
        CComVariant cvarFile;// project file
        hr = cddExtendeeObject.GetPropertyByName(OLESTR("ProjectFile"), &cvarFile);
        IfFailRet(hr);        

        cbstrProjectFile = cvarFile.bstrVal;
    }
    else if ( (_wcsicmp(m_cbstrExtenderCATID, strCATIDVBProjectBrowseObject) == 0) ||
              (_wcsicmp(m_cbstrExtenderCATID, strCATIDCSharpProjectBrowseObject) == 0) )
    {
        // we extend VB or C# project browse object
        CComVariant cvarPath;
        hr = cddExtendeeObject.GetPropertyByName(OLESTR("FullPath"), &cvarPath);
        IfFailRet(hr);

        CComVariant cvarFileName;
        hr = cddExtendeeObject.GetPropertyByName(OLESTR("FileName"), &cvarFileName);
        IfFailRet(hr);

        cbstrProjectFile = CComBSTR(cvarPath.bstrVal);
        cbstrProjectFile += CComBSTR(cvarFileName.bstrVal);
    }
    else
    {
        _ASSERTE(FALSE);
        return E_INVALIDARG;
    }

    IVsRunningDocumentTable* pRDT = _AtlModule.GetIVsRunningDocumentTable();
    ExpectedExprRet(pRDT != NULL)

    CComPtr<IVsHierarchy> srpIVsHierarchy_Parent;
    VSITEMID              vsitemidInParent  = VSITEMID_NIL;
    CComPtr<IUnknown>     srpIUnknown;
    VSDOCCOOKIE           vsDocCookie       = VSDOCCOOKIE_NIL;
    hr = pRDT->FindAndLockDocument(
        /* [in]  VSRDTFLAGS dwRDTLockType   */ RDT_NoLock,
        /* [in]  LPCOLESTR pszMkDocument    */ cbstrProjectFile,
        /* [out] IVsHierarchy **ppHier      */ &srpIVsHierarchy_Parent,
        /* [out] VSITEMID *pitemid          */ &vsitemidInParent,
        /* [out] IUnknown **ppunkDocData    */ &srpIUnknown,
        /* [out] VSCOOKIE *pdwCookie        */ &vsDocCookie);
    IfFailRet(hr);

    // FindAndLockDocument returns S_FALSE if the doc is not in the RDT
    _ASSERTE( (hr == S_OK) &&  (srpIVsHierarchy_Parent != NULL) && (vsitemidInParent != VSITEMID_NIL) );
    if ( (hr != S_OK) || !srpIVsHierarchy_Parent || (vsitemidInParent == VSITEMID_NIL) )
        return E_FAIL;

    // find the project hierarchy
    CComPtr<IVsHierarchy> srpIVsHierarchy;
    VSITEMID vsitemid;

    hr = srpIVsHierarchy_Parent->GetNestedHierarchy(vsitemidInParent, IID_IVsHierarchy, (void**) &srpIVsHierarchy, &vsitemid);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsHierarchy != NULL)

    CComVariant cvarDispObject;
    hr = srpIVsHierarchy->GetProperty(vsitemid, VSHPROPID_ExtObject, &cvarDispObject);
    IfFailRet(hr);
    ExpectedExprRet(cvarDispObject.pdispVal != NULL);
 
    // get the hiearchy's extensibility Project
    hr = cvarDispObject.pdispVal->QueryInterface(IID_Project, (void**)&m_srpProject);
    IfFailRet(hr);
    ExpectedExprRet(m_srpProject != NULL);

    // get the Project's Globals collection
    CComPtr<Globals> srpGlobals;
    hr = m_srpProject->get_Globals(&srpGlobals);
    IfFailRet(hr);
    ExpectedExprRet(srpGlobals != NULL);
  
    CComVariant cvar;
    hr = srpGlobals->get_VariableValue(cbstrMyExtension, &cvar);
    // might fail for new solutions
    if (SUCCEEDED(hr))
        m_cbstrProperty = cvar.bstrVal;

    return S_OK;
}

void CSlnStaticExtender::Close()
{
    //unadvise the Solution Events
    if (m_vscookieIVsSolutionEvents != VSCOOKIE_NIL)
    {
        VSCOOKIE vscookieTemp = m_vscookieIVsSolutionEvents;
        m_vscookieIVsSolutionEvents = VSCOOKIE_NIL;

        CComPtr<IVsSolution> srpIVsSolution;
        _AtlModule.QueryService(SID_SVsSolution, IID_IVsSolution, (void**) &srpIVsSolution);
        if (srpIVsSolution)
        {
            HRESULT hr = srpIVsSolution->UnadviseSolutionEvents(vscookieTemp);
            _ASSERTE(SUCCEEDED(hr));
        }
    }

    m_srpProject.Release();
    m_srpSolution.Release();
}


CSlnStaticExtender::~CSlnStaticExtender()
{
    Close();
    ms_rgCSlnStaticExtender.Remove(this);

    // Notify our site that we're going away
    //  The Extender MUST call back on IExtenderSite::NotifyDelete passing the 
    //  Cookie on its final release.
    if (m_srpIExtenderSite)
    {
        m_srpIExtenderSite->NotifyDelete(m_lCookie);
    }
}

//                                          construct, init , copy, destruct
//==========================================================================


//==========================================================================
//                                                        ISlnStaticExtender
STDMETHODIMP CSlnStaticExtender::put_MyProperty(
    /* [in] */ BSTR  bstrPropVal)
{
    HRESULT hr = S_OK;

    ExpectedExprRet(m_srpProject || m_srpSolution);

    CComPtr<Globals> srpGlobals;
    if (m_srpProject)
    {
        // get the Project's Globals collection
        hr = m_srpProject->get_Globals(&srpGlobals);
    }
    else
    {
        // get the Solution's Globals collection
        hr = m_srpSolution->get_Globals(&srpGlobals);
    }
    IfFailRet(hr);
    ExpectedExprRet(srpGlobals != NULL);

    hr = srpGlobals->put_VariableValue(cbstrMyExtension, CComVariant(bstrPropVal));
    IfFailRet(hr);

    hr = srpGlobals->put_VariablePersists(cbstrMyExtension, VARIANT_TRUE);
    IfFailRet(hr);

    // if we have a project let's dirty it
    if (m_srpProject)
    {
        hr = m_srpProject->put_IsDirty(VARIANT_TRUE);
        IfFailRet(hr);
    }

    m_cbstrProperty = bstrPropVal;

    if (bstrPropVal && !m_cbstrProperty)
        return E_OUTOFMEMORY; // allocation failed!

    return S_OK;
}


STDMETHODIMP CSlnStaticExtender::get_MyProperty(
    /* [out] */BSTR *pbstrPropVal)
{
    if (!pbstrPropVal)
        return E_POINTER;
   
    return m_cbstrProperty.CopyTo(pbstrPropVal);
}

//                                                        ISlnStaticExtender
//==========================================================================


//==========================================================================
//                                                         IVsSolutionEvents

STDMETHODIMP CSlnStaticExtender::OnAfterOpenSolution(
    /*[in]*/ IUnknown * pUnkReserved, 
    /*[in]*/ BOOL       fNewSolution)
{
    HRESULT hr = Reset();
    _ASSERT(SUCCEEDED(hr));

    return S_OK;
}
//                                                         IVsSolutionEvents
//==========================================================================


//                                                        CSlnStaticExtender
////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////
//                                                CSlnStaticExtenderProvider

//==========================================================================
//                                                              registration
/* static */ 
HRESULT WINAPI CSlnStaticExtenderProvider::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = _AtlModule.GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    if (FAILED(hr))
        return hr;

    // get the guid strings
    CComBSTR cbstrCLSID_ExtenderProvider(CLSID_SlnStaticExtenderProvider);
    if (!cbstrCLSID_ExtenderProvider) 
        return E_OUTOFMEMORY;

    // CATIDs
    CComBSTR cbstrCATIDSolutionBrowseObject(vsCATIDSolutionBrowseObject);
    if (!cbstrCATIDSolutionBrowseObject) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrCATIDVBProjectBrowseObject(prjCATIDVBProjectBrowseObject);
    if (!cbstrCATIDVBProjectBrowseObject) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrCATIDCSharpProjectBrowseObject(prjCATIDCSharpProjectBrowseObject);
    if (!cbstrCATIDCSharpProjectBrowseObject) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrCATIDVCProjectBrowseObject(prjCATIDVCProjectBrowseObject);
    if (!cbstrCATIDVCProjectBrowseObject) 
        return E_OUTOFMEMORY;

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"CLSID_ExtenderProvider",         cbstrCLSID_ExtenderProvider},
        {L"CATIDSolutionBrowseObject",      cbstrCATIDSolutionBrowseObject},
        {L"CATIDVBProjectBrowseObject",     cbstrCATIDVBProjectBrowseObject},
        {L"CATIDCSharpProjectBrowseObject", cbstrCATIDCSharpProjectBrowseObject},
        {L"CATIDVCProjectBrowseObject",     cbstrCATIDVCProjectBrowseObject},
        {L"wszMyExtension",                 cbstrMyExtension},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_REGSCRIPTAUTOMATION, bRegister, rgMap);
}
//                                                              registration
//==========================================================================


//==========================================================================
//                                                         IExtenderProvider
    
STDMETHODIMP CSlnStaticExtenderProvider::GetExtender(
    /* [in]          */ BSTR            bstrExtenderCATID, 
    /* [in]          */ BSTR            bstrExtenderName, 
    /* [in]          */ IDispatch *     pdispExtendeeObject,
    /* [in]          */ IExtenderSite * pExtenderSite,
    /* [in]          */ long            lCookie, 
    /* [out, retval] */ IDispatch **    ppdispExtender)
{
    _ASSERTE(bstrExtenderCATID && bstrExtenderName && pdispExtendeeObject && pExtenderSite && ppdispExtender);
    if (!bstrExtenderCATID || !bstrExtenderName || !pdispExtendeeObject || !pExtenderSite || !ppdispExtender)
        return E_POINTER;
    *ppdispExtender = NULL;

    HRESULT hr = S_OK;

    // make sure we get an IDispatch pointer to the Extendee
    CComPtr<IDispatch> srpdispExtendeeObject;
    hr = pdispExtendeeObject->QueryInterface(IID_IDispatch, (void**) &srpdispExtendeeObject);
    IfFailRet(hr);
    ExpectedExprRet(srpdispExtendeeObject != NULL);

    VARIANT_BOOL vbCanExtend;

    // do the CanExtend check here also
    hr = CanExtend(
        /* [in]          BSTR            bstrExtenderCATID*/    bstrExtenderCATID, 
        /* [in]          BSTR            bstrExtenderName*/     bstrExtenderName, 
        /* [in]          IDispatch *     pdispExtendeeObject*/  srpdispExtendeeObject, 
        /* [out, retval] VARIANT_BOOL *  pfRetval*/             &vbCanExtend);
    if (FAILED(hr))
        return hr;

    if (VARIANT_FALSE == vbCanExtend)
        return E_FAIL;

    // Finally create the extender
    hr = CSlnStaticExtender::CreateInstance(
    /* [in]  BSTR             bstrExtenderCATID*/   bstrExtenderCATID, 
    /* [in]  IDispatch *      pdispExtendeeObject*/ srpdispExtendeeObject, 
    /* [in]  IExtenderSite *  pIExtenderSite*/      pExtenderSite,
    /* [in]  long             lCookie*/             lCookie,
    /* [out] IDispatch **     ppIDispatch*/         ppdispExtender);

    return hr;
}


STDMETHODIMP CSlnStaticExtenderProvider::CanExtend(
    /* [in]          */ BSTR            bstrExtenderCATID, 
    /* [in]          */ BSTR            bstrExtenderName, 
    /* [in]          */ IDispatch *     pdispExtendeeObject, 
    /* [out, retval] */ VARIANT_BOOL *  pfRetval)
{
    _ASSERTE(bstrExtenderCATID && bstrExtenderName && pdispExtendeeObject && pfRetval);
    if (!bstrExtenderCATID || !bstrExtenderName || !pdispExtendeeObject || !pfRetval)
        return E_POINTER;
    *pfRetval = VARIANT_FALSE;

    USES_CONVERSION;

    // We extend the following browse objects
    //    Solution - vsCATIDSolutionBrowseObject
    //    VB Project - prjCATIDVBProjectBrowseObject
    //    C# Project - prjCATIDCSharpProjectBrowseObject
    //    VC Project - prjCATIDVCProjectBrowseObject
    if ( _wcsicmp(bstrExtenderName, cbstrMyExtension) != 0)
        return S_OK;

    if ( vsCATIDSolutionBrowseObject && (_wcsicmp(bstrExtenderCATID, A2CW(vsCATIDSolutionBrowseObject)) != 0) &&
         (_wcsicmp(bstrExtenderCATID, A2CW(prjCATIDVBProjectBrowseObject)) != 0) &&
         (_wcsicmp(bstrExtenderCATID, A2CW(prjCATIDCSharpProjectBrowseObject)) != 0) &&
         (_wcsicmp(bstrExtenderCATID, A2CW(prjCATIDVCProjectBrowseObject)) != 0) )
         return S_OK;

    // check for pdispExtendeeObject being the correct kind of obj here

    *pfRetval = VARIANT_TRUE;
    return S_OK;
}





////////////////////////////////////////////////////////////////////////////
//                                                       CSlnDynamicExtender

//==========================================================================
//                                          construct, init , copy, destruct

/* static */
HRESULT CSlnDynamicExtender::CreateInstance(
    /* [in]  */ IDispatch *      pdispExtendeeObject, 
    /* [in]  */ IExtenderSite *  pIExtenderSite,
    /* [in]  */ long             lCookie,
    /* [in]  */ ISolutionNotes * pISolutionNotes, 
    /* [out] */ IDispatch **     ppIDispatch)
{
    _ASSERTE(pdispExtendeeObject && pIExtenderSite && ppIDispatch && pISolutionNotes);
    if (!pdispExtendeeObject || !pIExtenderSite || !ppIDispatch || !pISolutionNotes)
        return E_POINTER;
    *ppIDispatch = NULL;

    CComObject<CSlnDynamicExtender>* pco = NULL;
    HRESULT hr = CComObject<CSlnDynamicExtender>::CreateInstance(&pco);
    if (FAILED(hr))
        return hr;

    pco->AddRef();
    hr = pco->Init(pdispExtendeeObject, pIExtenderSite, lCookie, pISolutionNotes);
    if (SUCCEEDED(hr))
    {
        hr = pco->QueryInterface(IID_IDispatch, (void**)ppIDispatch);
    }
    pco->Release();
    return hr;
}


STDMETHODIMP CSlnDynamicExtender::Init(
    /* [in]  */ IDispatch *      pdispExtendeeObject, 
    /* [in]  */ IExtenderSite *  pIExtenderSite,
    /* [in]  */ long             lCookie,
    /* [in]  */ ISolutionNotes * pISolutionNotes)
{
    m_srpISolutionNotes = pISolutionNotes;
    m_srpIExtenderSite  = pIExtenderSite;
    m_lCookie = lCookie;
    return S_OK;
}

CSlnDynamicExtender::~CSlnDynamicExtender()
{
    //  The Extender MUST call back on IExtenderSite::NotifyDelete passing the 
    //  Cookie on its final release.
    if(m_srpIExtenderSite)
    {
        m_srpIExtenderSite->NotifyDelete(m_lCookie);
    }
}
//                                          construct, init , copy, destruct
//==========================================================================


STDMETHODIMP CSlnDynamicExtender::get_NoteCount(long* pCount)
{
    if(!pCount) return E_POINTER;

    return m_srpISolutionNotes->get_Count(pCount);
}

//                                                       CSlnDynamicExtender
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
//                                               CSlnDynamicExtenderProvider

//==========================================================================
//                                          construct, init , copy, destruct

/* static */
HRESULT CSlnDynamicExtenderProvider::CreateInstance(
    /* [in]  */ CSlnExtPackage *           pPackage, 
    /* [out] */ CSlnDynamicExtenderProvider **  ppCSlnDynamicExtenderProvider)
{
    _ASSERTE(ppCSlnDynamicExtenderProvider && pPackage);
    if (!ppCSlnDynamicExtenderProvider || !pPackage)
        return E_POINTER;
    *ppCSlnDynamicExtenderProvider = NULL;

    CComObject<CSlnDynamicExtenderProvider>* pco = NULL;
    HRESULT hr = CComObject<CSlnDynamicExtenderProvider>::CreateInstance(&pco);
    if (FAILED(hr))
        return hr;

    hr = pco->Init(pPackage);
    pco->AddRef();
    if (SUCCEEDED(hr))
    {
        *ppCSlnDynamicExtenderProvider = pco;
        pco->AddRef();
    }
    pco->Release();
    return hr;
}


CSlnDynamicExtenderProvider::CSlnDynamicExtenderProvider() :
    m_pPackage(NULL),
    m_lSolutionCookie(0),
    m_lSolutionBrowseObjectCookie(0)
{
}


HRESULT CSlnDynamicExtenderProvider::Init(
    /* [in]  */ CSlnExtPackage * pPackage)
{
    _ASSERTE(pPackage);
    if (!pPackage)
        return E_POINTER;

    HRESULT hr = S_OK;

    m_pPackage = pPackage;

    //now set up the ObjectExtender stuff
    CComPtr<ObjectExtenders> srpObjectExtenders;
    hr = _AtlModule.QueryService(SID_SExtensionManager, IID_ObjectExtenders, (void**)&srpObjectExtenders);
    _ASSERTE(SUCCEEDED(hr));
    if (FAILED(hr))
        return hr;

    USES_CONVERSION;

    CComBSTR cbstrCATIDSolution(vsCATIDSolution);
    CComBSTR cbstrCATIDSolutionBrowseObject(vsCATIDSolutionBrowseObject);
    CComBSTR cbstrExtenderName(wszSolutionNotesExtension);
    CComBSTR cbstrLocalizedName;
    cbstrLocalizedName.LoadString(IDS_WINDOW_TITLE);

    hr = srpObjectExtenders->RegisterExtenderProvider(
        /* [in] BSTR ExtenderCATID*/                    cbstrCATIDSolution,
        /* [in] BSTR ExtenderName*/                     cbstrExtenderName,
        /* [in] IExtenderProvider *ExtenderProvider*/   (IExtenderProvider*)this,
        /* [in] BSTR LocalizedName*/                    cbstrLocalizedName,  
        /* [retval][out] long *Cookie*/                 &m_lSolutionCookie);
    _ASSERTE(SUCCEEDED(hr));
    if (FAILED(hr))
        return hr;

    hr = srpObjectExtenders->RegisterExtenderProvider(
        /* [in] BSTR ExtenderCATID*/                    cbstrCATIDSolutionBrowseObject,
        /* [in] BSTR ExtenderName*/                     cbstrExtenderName,
        /* [in] IExtenderProvider *ExtenderProvider*/   (IExtenderProvider*)this,
        /* [in] BSTR LocalizedName*/                    cbstrLocalizedName,  
        /* [retval][out] long *Cookie*/                 &m_lSolutionBrowseObjectCookie);
    _ASSERTE(SUCCEEDED(hr));
    if (FAILED(hr))
        return hr;

    return hr;
}


void CSlnDynamicExtenderProvider::Close()
{
    HRESULT hr = S_OK;

    //now release the ObjectExtender stuff
    CComPtr<ObjectExtenders> srpObjectExtenders;
    hr = _AtlModule.QueryService(SID_SExtensionManager, IID_ObjectExtenders, (void**)&srpObjectExtenders);
    _ASSERTE(SUCCEEDED(hr));
    if (FAILED(hr))
        return;

    //we want to do these things whether any of them fails or not
    hr = srpObjectExtenders->UnregisterExtenderProvider(m_lSolutionCookie);
    _ASSERTE(SUCCEEDED(hr));
    hr = srpObjectExtenders->UnregisterExtenderProvider(m_lSolutionBrowseObjectCookie);
    _ASSERTE(SUCCEEDED(hr));
}


//==========================================================================
//                                                         IExtenderProvider
    
STDMETHODIMP CSlnDynamicExtenderProvider::GetExtender(
    /* [in]          */ BSTR            bstrExtenderCATID, 
    /* [in]          */ BSTR            bstrExtenderName, 
    /* [in]          */ IDispatch *     pdispExtendeeObject,
    /* [in]          */ IExtenderSite * pExtenderSite,
    /* [in]          */ long            lCookie, 
    /* [out, retval] */ IDispatch **    ppdispExtender)
{
    _ASSERTE(bstrExtenderCATID && bstrExtenderName && pdispExtendeeObject && pExtenderSite && ppdispExtender);
    if (!bstrExtenderCATID || !bstrExtenderName || !pdispExtendeeObject || !pExtenderSite || !ppdispExtender)
        return E_POINTER;
    *ppdispExtender = NULL;

    HRESULT hr = S_OK;

    VARIANT_BOOL vbCanExtend;

    // do the CanExtend check here also
    hr = CanExtend(
        /* [in]          BSTR            bstrExtenderCATID*/    bstrExtenderCATID, 
        /* [in]          BSTR            bstrExtenderName*/     bstrExtenderName, 
        /* [in]          IDispatch *     pdispExtendeeObject*/  pdispExtendeeObject, 
        /* [out, retval] VARIANT_BOOL *  pfRetval*/             &vbCanExtend);
    if (FAILED(hr))
        return hr;

    if (VARIANT_FALSE == vbCanExtend)
        return E_FAIL;

    _ASSERTE(m_pPackage);
    if (!m_pPackage)
        return E_UNEXPECTED;
    CComPtr<ISolutionNotes> srpISolutionNotes;
    hr = m_pPackage->GetSolutionNotes(&srpISolutionNotes);
    if (FAILED(hr))
        return hr;

    // Finally create the extender
    hr = CSlnDynamicExtender::CreateInstance(
    /* [in]  IDispatch *      pdispExtendeeObject*/ pdispExtendeeObject, 
    /* [in]  IExtenderSite *  pIExtenderSite*/      pExtenderSite,
    /* [in]  long             lCookie*/             lCookie,
    /* [in]  ISolutionNotes * pISolutionNotes*/     srpISolutionNotes, 
    /* [out] IDispatch **     ppIDispatch*/         ppdispExtender);

    return hr;
}


STDMETHODIMP CSlnDynamicExtenderProvider::CanExtend(
    /* [in]          */ BSTR            bstrExtenderCATID, 
    /* [in]          */ BSTR            bstrExtenderName, 
    /* [in]          */ IDispatch *     pdispExtendeeObject, 
    /* [out, retval] */ VARIANT_BOOL *  pfRetval)
{
    _ASSERTE(bstrExtenderCATID && bstrExtenderName && pdispExtendeeObject && pfRetval);
    if (!bstrExtenderCATID || !bstrExtenderName || !pdispExtendeeObject || !pfRetval)
        return E_POINTER;
    *pfRetval = VARIANT_FALSE;

    USES_CONVERSION;

    // We extend the following objects
    //    Solution object - vsCATIDSolution
    //    Solution browse object - vsCATIDSolutionBrowseObject
    if ( _wcsicmp(wszSolutionNotesExtension, bstrExtenderName) != 0)
        return S_OK;

    if (vsCATIDSolution && (_wcsicmp(bstrExtenderCATID, A2CW(vsCATIDSolution)) !=0) 
        && (_wcsicmp(bstrExtenderCATID, A2CW(vsCATIDSolutionBrowseObject)) != 0))
        return S_OK;
        

    // check for pdispExtendeeObject being the correct kind of obj here

    *pfRetval = VARIANT_TRUE;
    return S_OK;
}

//                                                         IExtenderProvider
//==========================================================================

//                                               CSlnDynamicExtenderProvider
////////////////////////////////////////////////////////////////////////////
