
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// DebugPPG.cpp: implementation of the DebugPPG class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PrjInc.h" 

// =========================================================================
//                                                 construct, init, destruct
/* static */
HRESULT CMyCDebugPropPg::CreateInstance(
    /* [in]  */ IMyCSettingsPage *   pIMyCSettingsPage, 
    /* [in]  */ IUnknown *           pUnkParent,
    /* [out] */ IUnknown ** pIUnkPropPage)
{
	HRESULT hr = S_OK;
	CComObject<CMyCDebugPropPg> * pObj;
	hr = CComObject<CMyCDebugPropPg>::CreateInstance(&pObj);
    IfFailRet(hr);
    ExpectedExprRet(pObj != NULL);

    pObj->AddRef();
    hr = pObj->Init(pIMyCSettingsPage, pUnkParent, pIUnkPropPage);
    pObj->Release();
    return hr;
}


CMyCDebugPropPg::CMyCDebugPropPg() : 
    m_enumMyCPrjDebugStartMode(MyCPrjDebugStartMode_Project) 
{
}


HRESULT CMyCDebugPropPg::Init(
    /* [in]  */ IMyCSettingsPage *   pIMyCSettingsPage, 
    /* [in]  */ IUnknown *           pUnkParent,
    /* [out] */ IUnknown **          pIUnkPropPage)
{
    ExpectedPtrRet(pIMyCSettingsPage);
    ExpectedPtrRet(pUnkParent);
    ExpectedPtrRet(pIUnkPropPage);
    *pIUnkPropPage = NULL;

	HRESULT hr = S_OK;

    if (!m_rgcbstrDebugStartMode[0].LoadString(IDS_DEBUGSTARTMODE_PROJECT))
        return E_FAIL;
    if (!m_rgcbstrDebugStartMode[1].LoadString(IDS_DEBUGSTARTMODE_APPLICATION))
        return E_FAIL;

	m_pIMyCSettingsPage   = pIMyCSettingsPage;

    // initialize the members
    hr = pUnkParent->QueryInterface(IID_IMyCProjCfgProps, (void**) &m_srpIMyCProjCfgProps);
    IfFailRet(hr);

    hr = m_srpIMyCProjCfgProps->get_DebugStartMode(&m_enumMyCPrjDebugStartMode);
    IfFailRet(hr);

    hr = m_srpIMyCProjCfgProps->get_StartApp(&m_cbstrStartApp);
    IfFailRet(hr);

    hr = m_srpIMyCProjCfgProps->get_StartAppPath(&m_cbstrStartAppPath);
    IfFailRet(hr);

    hr = m_srpIMyCProjCfgProps->get_CustomStartupArguments(&m_cbstrCustomStartupArguments);
    IfFailRet(hr);

	hr = QueryInterface(IID_IUnknown, (void**) pIUnkPropPage);
    return hr;
}


CMyCDebugPropPg::~CMyCDebugPropPg() 
{
} 
//                                                 construct, init, destruct
// =========================================================================


// =========================================================================
//                                                      IPerPropertyBrowsing
// Used to populate Debug Start Mode list box

STDMETHODIMP CMyCDebugPropPg::GetDisplayString(
    /* [in] */ DISPID dispID,
    /* [out] */ BSTR *pBstr)
{
	if(pBstr == NULL )
		return E_POINTER;
	*pBstr = NULL;
			
    CComVariant var;
	HRESULT hr = S_OK;

	if( dispID == MyCPrjPROJPROPID_DebugStartMode )
	{
        return m_rgcbstrDebugStartMode[m_enumMyCPrjDebugStartMode].CopyTo(pBstr);
    }

    return E_NOTIMPL;
}


STDMETHODIMP CMyCDebugPropPg::MapPropertyToPage(
    /* [in]  */ DISPID dispID,
    /* [out] */ CLSID *pClsid)
{
    return E_NOTIMPL;
}


STDMETHODIMP CMyCDebugPropPg::GetPredefinedStrings( 
    /* [in]  */ DISPID          dispID,
    /* [out] */ CALPOLESTR *    pCaStringsOut,
    /* [out] */ CADWORD *       pCaCookiesOut)
{
	if (pCaStringsOut == NULL || pCaCookiesOut == NULL)
		return E_POINTER;

    if( dispID != MyCPrjPROJPROPID_DebugStartMode )
        return E_NOTIMPL;

    HRESULT hr = S_OK;

    int iEntries = MyCPrjDebugStartModeMax - MyCPrjDebugStartModeMin + 1;
	DWORD *pCookies = NULL;
	LPOLESTR *pStrings = NULL;

	//---- set up the collections to be returned ----
	pCookies = (DWORD *)CoTaskMemAlloc(iEntries*sizeof(DWORD));
	if (! pCookies)
    {
        hr = E_OUTOFMEMORY;
		goto OnError;
    }

	pStrings = (LPOLESTR *)CoTaskMemAlloc(iEntries*sizeof(LPOLESTR));
	if (! pStrings)
    {
        hr = E_OUTOFMEMORY;
		goto OnError;
    }

    int iAdded = 0;
	for (int i=0; i < iEntries; i++)
	{
        LPCOLESTR src = m_rgcbstrDebugStartMode[i];
		LPOLESTR dst;

		// store cookie
		pCookies[i] = i;

		// allocate and store string
		dst = (LPOLESTR)CoTaskMemAlloc((lstrlenW(src)+1)*sizeof(WCHAR));
		if (! dst)
        {
            hr = E_OUTOFMEMORY;
			goto OnError;
        }

        lstrcpyW(dst, src);
		pStrings[iAdded] = dst;
        iAdded++;
	}

	pCaCookiesOut->cElems = iEntries;
	pCaCookiesOut->pElems = pCookies;
	pCaStringsOut->cElems = iEntries;
	pCaStringsOut->pElems = pStrings;
	
	return S_OK;

OnError:
	CoTaskMemFree(pCookies);
	if (pStrings)
	{
		for (i=0; i < iAdded; i++)
			CoTaskMemFree(pStrings[i]);
		CoTaskMemFree(pStrings);
	}

	return hr;
}


STDMETHODIMP CMyCDebugPropPg::GetPredefinedValue( 
    /* [in]  */ DISPID dispID,
    /* [in]  */ DWORD dwCookie,
    /* [out] */ VARIANT *pVarOut)
{
    if( dispID != MyCPrjPROJPROPID_DebugStartMode )
        return E_NOTIMPL;

    ExpectedPtrRet(pVarOut);

    pVarOut->vt = VT_I4;
    pVarOut->lVal = dwCookie;
    return S_OK;
}
//                                                      IPerPropertyBrowsing
// =========================================================================

     
// =========================================================================
//                                                    IVsPerPropertyBrowsing

STDMETHODIMP CMyCDebugPropPg::HideProperty(DISPID dispid, BOOL* pfHide)
{
    if (!pfHide)
        return E_INVALIDARG;
    return E_NOTIMPL;
}


STDMETHODIMP CMyCDebugPropPg::DisplayChildProperties(DISPID dispid, BOOL* pfDisplay)
{
    if (!pfDisplay)
        return E_INVALIDARG;
    return E_NOTIMPL;
}


STDMETHODIMP CMyCDebugPropPg::GetLocalizedPropertyInfo(
    DISPID dispid, 
    LCID localeID, 
    BSTR* pbstrLocalizedName, 
    BSTR* pbstrLocalizedDescription)
{
    // The function can return both or either value as NULL
    if (pbstrLocalizedName)
        *pbstrLocalizedName = NULL;

    if (pbstrLocalizedDescription)
        *pbstrLocalizedDescription = NULL;

    CComBSTR cbstrLocalizedName;
    CComBSTR cbstrLocalizedDescription;
    switch(dispid)
    {
    case MyCPrjPROJPROPID_DebugStartMode:
        cbstrLocalizedName.LoadString(IDS_PROP_DEBUGSTARTMODE_LOCNAME);
        cbstrLocalizedDescription.LoadString(IDS_PROP_DEBUGSTARTMODE_LOCDESC);
        break;
    case MyCPrjPROJPROPID_StartApp:
        cbstrLocalizedName.LoadString(IDS_PROP_STARTAPP_LOCNAME);
        cbstrLocalizedDescription.LoadString(IDS_PROP_STARTAPP_LOCDESC);
        break;
    case MyCPrjPROJPROPID_StartAppPath:
        cbstrLocalizedName.LoadString(IDS_PROP_STARTAPPPATH_LOCNAME);
        cbstrLocalizedDescription.LoadString(IDS_PROP_STARTAPPPATH_LOCDESC);
        break;
    case MyCPrjPROJPROPID_CustomStartupArguments:
        cbstrLocalizedName.LoadString(IDS_PROP_CUSTOMSTARTUPARGUMENTS_LOCNAME);
        cbstrLocalizedDescription.LoadString(IDS_PROP_CUSTOMSTARTUPARGUMENTS_LOCDESC);
        break;
    default:
        ASSERT(FALSE);
        break;
    }

    if ( (cbstrLocalizedName.Length() == 0) || (cbstrLocalizedDescription.Length() == 0) )
        return E_OUTOFMEMORY;

    if (pbstrLocalizedName)
        *pbstrLocalizedName = cbstrLocalizedName.Detach();

    if (pbstrLocalizedDescription)
        *pbstrLocalizedDescription = cbstrLocalizedDescription.Detach();

    return S_OK;
}  


STDMETHODIMP CMyCDebugPropPg::HasDefaultValue(DISPID dispid, BOOL* fDefault)
{
    return E_NOTIMPL;
}


STDMETHODIMP CMyCDebugPropPg::IsPropertyReadOnly(DISPID dispid, BOOL* pfReadOnly)
{
    if (!pfReadOnly)
        return E_INVALIDARG;
    return E_NOTIMPL;
}


STDMETHODIMP CMyCDebugPropPg::GetClassName(BSTR*) 
{
	return E_NOTIMPL;
}


STDMETHODIMP CMyCDebugPropPg::CanResetPropertyValue(DISPID , BOOL* ) 
{
	return E_NOTIMPL;
}


STDMETHODIMP CMyCDebugPropPg::ResetPropertyValue(DISPID ) 
{
	return E_NOTIMPL;
}
//                                                    IVsPerPropertyBrowsing
// =========================================================================


// =========================================================================
//                                                     IMyCPropertyContainer
STDMETHODIMP CMyCDebugPropPg::Commit()
{
    HRESULT hr = S_OK;
    hr = m_srpIMyCProjCfgProps->put_DebugStartMode(m_enumMyCPrjDebugStartMode);
    _IfFailRet(hr);
    hr = m_srpIMyCProjCfgProps->put_StartApp(m_cbstrStartApp);
    _IfFailRet(hr);
    hr = m_srpIMyCProjCfgProps->put_StartAppPath(m_cbstrStartAppPath);
    _IfFailRet(hr);
    hr = m_srpIMyCProjCfgProps->put_CustomStartupArguments(m_cbstrCustomStartupArguments);
    _IfFailRet(hr);

	return hr;
}
//                                                     IMyCPropertyContainer
// =========================================================================


// =========================================================================
//                                                         IMyCDebugPropPage

STDMETHODIMP CMyCDebugPropPg::get_DebugStartMode(
    /* [out] */ MyCPrjDebugStartMode *pdebugStartMode)
{
    ExpectedPtrRet(pdebugStartMode);
    *pdebugStartMode = m_enumMyCPrjDebugStartMode;
    return S_OK;
}


STDMETHODIMP CMyCDebugPropPg::put_DebugStartMode(
    /* [in]  */ MyCPrjDebugStartMode debugStartMode)
{
    if ( (debugStartMode < MyCPrjDebugStartModeMin) && (debugStartMode > MyCPrjDebugStartModeMax) )
        return E_INVALIDARG;
    m_enumMyCPrjDebugStartMode = debugStartMode;
    return SetProperty();
}


STDMETHODIMP CMyCDebugPropPg::get_StartApp(
    /* [out] */ BSTR *pbstr)
{
    return m_cbstrStartApp.CopyTo(pbstr);
}


STDMETHODIMP CMyCDebugPropPg::put_StartApp(
    /* [in]  */ BSTR bstr)
{
    HRESULT hr = m_cbstrStartApp.AssignBSTR(bstr);
    IfFailRet(hr);
    return SetProperty();
}


STDMETHODIMP CMyCDebugPropPg::get_StartAppPath(
    /* [out] */ BSTR *pbstr)
{
    return m_cbstrStartAppPath.CopyTo(pbstr);
}


STDMETHODIMP CMyCDebugPropPg::put_StartAppPath(
    /* [in]  */ BSTR bstr)
{
    HRESULT hr = m_cbstrStartAppPath.AssignBSTR(bstr);
    IfFailRet(hr);
    return SetProperty();
}


STDMETHODIMP CMyCDebugPropPg::get_CustomStartupArguments(
    /* [out] */ BSTR *pbstr)
{
    return m_cbstrCustomStartupArguments.CopyTo(pbstr);
}


STDMETHODIMP CMyCDebugPropPg::put_CustomStartupArguments(
    /* [in]  */ BSTR bstr)
{
    HRESULT hr = m_cbstrCustomStartupArguments.AssignBSTR(bstr);
    IfFailRet(hr);
    return SetProperty();
}


HRESULT CMyCDebugPropPg::SetProperty()
{
	if (m_pIMyCSettingsPage)
		m_pIMyCSettingsPage->Dirty();
	return S_OK;      
}
//                                                         IMyCDebugPropPage
// =========================================================================
