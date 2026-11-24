
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cpp : Implementation of CRDTViewPackage
//

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"
#include "docview.h"
#include "rdtviewtool.h"

/////////////////////////////////////////////////////////////////////////////
// CRDTViewPackage

CRDTViewPackage::CRDTViewPackage()
{
    ATLTRACE(_T("Creating CRDTViewPackage: 0x%X\n"), this);

    m_fZombie = FALSE;
	m_spDocViewerObj = NULL;
	m_dwSinkCookie = 0;
}

CRDTViewPackage::~CRDTViewPackage()
{
	ATLTRACE(_T("Destructing CRDTViewPackage: 0x%X\n"), this);
}

/* static */ 
HRESULT WINAPI CRDTViewPackage::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = _Module.GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    if FAILED(hr)
        return hr;

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName;
    hr = _Module.GetRegDefaultResourceStrings(&cbstrResDllPath, &cbstrResDllName);
    if FAILED(hr)
        return hr;

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    WCHAR wszIDS_OFFICIALNAME[iMaxResIdLen];
    WCHAR wszIDS_PRODUCTDETAILS[iMaxResIdLen];
    _ultow(IDS_PACKAGE_LOAD_KEY,        wszIDS_PACKAGE_LOAD_KEY,        10);
    _ultow(IDS_OFFICIALNAME,            wszIDS_OFFICIALNAME,            10);
    _ultow(IDS_PRODUCTDETAILS,          wszIDS_PRODUCTDETAILS,          10);

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"RESOURCE_PATH",                  cbstrResDllPath},
        {L"RESOURCE_DLL",                   cbstrResDllName},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_OFFICIALNAME",               wszIDS_OFFICIALNAME},
        {L"IDS_PRODUCTDETAILS",             wszIDS_PRODUCTDETAILS},
        {NULL, NULL}
    };

    return _Module.UpdateRegistryFromResource(IDR_REGISTRYSCRIPT, bRegister, rgMap);
}


/////////////////////////////////////////////////////////////////////////////
// CRDTViewPackage IVsPackage Implementation

STDMETHODIMP CRDTViewPackage::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ATLTRACE(_T("CRDTViewPackage::SetSite\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;    // protect against multiple SetSite calls

    HRESULT hr;

    hr = _Module.SetModuleSite(pSP);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }

    // Load the UI Library.
    // This call will initialize "_Module.m_hInstResource" to point to our 
    // localized satellite DLL.
    // Note that IDS_E_BADINSTALL is the id of a string resource within the 
    // package dll itself.
    hr = _Module.LoadUILibrary(CLSID_RDTViewPackage, IDS_E_BADINSTALL);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }

    return S_OK;
}

STDMETHODIMP CRDTViewPackage::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ATLTRACE(_T("CRDTViewPackage::QueryClose\n"));
    _ASSERTE(pCanClose);

    *pCanClose = TRUE;
    return S_OK;
}

STDMETHODIMP CRDTViewPackage::Close(void)
{
    ATLTRACE(_T("CRDTViewPackage::Close\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    _Module.UnloadUILibrary();
    _Module.SetModuleSite(NULL);

    // set our state for protection
    m_fZombie = TRUE;
    return S_OK;
}

STDMETHODIMP CRDTViewPackage::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ATLTRACE(_T("CRDTViewPackage::GetAutomationObject\n"));
    _ASSERTE(ppDisp);

    *ppDisp = NULL;
    return E_NOTIMPL;
}

STDMETHODIMP CRDTViewPackage::CreateTool(
                    /*[in]*/ REFGUID rguid) 
{ 
    ATLTRACE(_T("CRDTViewPackage::CreateTool\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

	if (guidRDTViewToolWin == rguid)
	{
		CComPtr<IVsUIShell> srpShell;

		// Get the IVsUIShell interface so we can create a tool window
		HRESULT hr = _Module.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void**)&srpShell);

		if (SUCCEEDED(hr))
		{
			CComBSTR	bstrCaption;
			CComObject<CRDTViewTool>* spToolWin = NULL;
			CComPtr<IRDTViewTool> srpRdtViewTool;

			// Get window caption from resources
			Verify(bstrCaption.LoadString(_Module.m_hInstResource, IDS_TITLE_TOOLWINDOW));

			// Create an instance of the CRDTViewTool COM object and get a pointer to its
			// IVsWindowPane interface to pass to IVsUIShell::CreateToolWindow()
			hr = CComObject<CRDTViewTool>::CreateInstance(&spToolWin);
			if (FAILED(hr))
			{
				_Module.SetErrorInfo(hr, IDS_E_CANTLOADTOOLWINDOW, 0);
				return hr;
			}

			hr = spToolWin->QueryInterface(IID_IVsWindowPane, (void**)&m_srpWindowPane);
			Assert(SUCCEEDED(hr));

			// Create an instance of IDocViewer if we don't already have one, and
			// inform the CRDTViewTool object of its address.  We do this so we can 
			// do things like unadvise of RDT events via IDocViewer when the tool window pane
			// is closed.
			if (NULL == m_spDocViewerObj)
			{
				hr = CComObject<CDocViewer>::CreateInstance(&m_spDocViewerObj);
				if (SUCCEEDED(hr))
				{
					hr = m_spDocViewerObj->QueryInterface(IID_IDocViewer, (void**)&m_srpDocViewer);
					Assert(SUCCEEDED(hr));
				}
			}

			hr = spToolWin->QueryInterface(IID_IRDTViewTool, (void**)&srpRdtViewTool);
			Assert(SUCCEEDED(hr));
			Verify(SUCCEEDED(srpRdtViewTool->SetDocViewer(m_srpDocViewer)));
			spToolWin->Release();

			if (SUCCEEDED(hr))
			{
				Assert(m_srpWindowPane.p);
				hr = srpShell->CreateToolWindow(
									CTW_fInitNew,			// dwCTW
									NULL,					// dwReserved
									m_srpWindowPane,		// punkTool
									CLSID_NULL,				// rclsidTool
									guidRDTViewToolWin,		// rguidPersistenceSlot
									GUID_NULL,				// rguidAutoActivate
									NULL,					// pSP
									bstrCaption.Detach(),	// pszCaption
									NULL,					// pfDefaultPosition
									&m_srpToolWindowFrame);	// ppWindowFrame

				// If CreateToolWindow failed let's give the user a useful error message
				if (FAILED(hr))
					_Module.SetErrorInfo(hr, IDS_E_CANTCREATETOOL, 0);
			} // if (QI for IVsWindowPane succeeded)

			return hr;
		} // if (QueryService for IVsUIShell succeeded)
	} // if (guidRDTViewToolWin)

    return E_INVALIDARG;	// Got called with unknown rguid
}

STDMETHODIMP CRDTViewPackage::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ATLTRACE(_T("CRDTViewPackage::ResetDefaults\n"));

    return E_NOTIMPL;
}

STDMETHODIMP CRDTViewPackage::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage)
{
    ATLTRACE(_T("CRDTViewPackage::GetPropertyPage\n"));

    return E_NOTIMPL;
}


///////////////////////////////////////////////////////////////////////////////
// CRDTViewPackage IOleCommandTarget Implementation

#pragma warning(disable:4065) // switch statement contains 'default' but no 'case' labels

STDMETHODIMP CRDTViewPackage::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(cCmds == 1);
    _ASSERTE(prgCmds && pguidCmdGroup);

    if ((prgCmds == NULL) || (pguidCmdGroup == NULL))
        return E_INVALIDARG;

    DWORD cmdf;

    if (*pguidCmdGroup == guidRDTViewCmdSet)
    {
		// The following bitwise flags control the state of a command:
		//		OLECMDF_SUPPORTED, OLECMDF_ENABLED, OLECMDF_LATCHED,
		//		OLECMDF_NINCHED, OLECMDF_INVISIBLE, OLECMDF_DEFHIDEONCTXTMENU
		//
		// Common cases are the following:
		//	1. Enable a command --  cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED
		//	2. Disable a command -- cmdf = OLECMDF_SUPPORTED
		//	3. Hide a command --    cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE
        cmdf = OLECMDF_SUPPORTED;

        switch (prgCmds[0].cmdID)
        {
			case icmdViewRDTViewer:
				cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
				break;

            default:
                return OLECMDERR_E_NOTSUPPORTED;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    prgCmds[0].cmdf = cmdf;
    return S_OK;
}

STDMETHODIMP CRDTViewPackage::Exec(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdexecopt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut)
{
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(pguidCmdGroup);

    if (pguidCmdGroup == NULL)
        return E_INVALIDARG;

    HRESULT hr = S_OK;

    if (*pguidCmdGroup == guidRDTViewCmdSet)
    {
        // IOleCommandTargt::Exec should report errors that may occur
        // in the execution of a command. Therefore clear any existing
        // existing error info first
        _Module.ClearErrorInfo();

        switch (nCmdID)
        {
			case icmdViewRDTViewer:

				// Open RDTView tool window 
				if (NULL == m_srpToolWindowFrame.p)
					hr = CreateTool(guidRDTViewToolWin);

				if (SUCCEEDED(hr))
					hr = m_srpToolWindowFrame->Show();

				// Pass to CDocViewer to populate with data
				if (SUCCEEDED(hr))
				{
					Assert(m_srpDocViewer.p);
					hr = m_srpDocViewer->Populate(m_srpWindowPane);
					
					// Advise for events
					if ((SUCCEEDED(hr)) && (0 == m_dwSinkCookie))
						hr = m_srpDocViewer->Advise(&m_dwSinkCookie);
				}

				break;

            default:
                return OLECMDERR_E_NOTSUPPORTED;
        }

        if (FAILED(hr))
        {
            _Module.ReportErrorInfo(hr);
            hr = S_OK;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    return hr;
}


///////////////////////////////////////////////////////////////////////////////
// CRDTViewPackage IServiceProvider Implementation

STDMETHODIMP CRDTViewPackage::QueryService(
                    /*[in] */ REFGUID rsid,
                    /*[in] */ REFIID  riid,
                    /*[out]*/ void**  ppvObject)
{
    if (m_fZombie)
        return E_UNEXPECTED;

    _ASSERTE(ppvObject);

    if (ppvObject == NULL)
        return E_POINTER;

    HRESULT hr = E_NOINTERFACE;
    *ppvObject = NULL;

    return hr;
}
