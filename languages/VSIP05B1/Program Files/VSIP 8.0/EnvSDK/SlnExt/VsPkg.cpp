
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cpp : Implementation of CSlnExtPackage
//

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"
#include "notewin.h"
#include "AutomationExtenders.h"

WCHAR CSlnExtPackage::m_szPersistKey[] = L"SolutionNotes";

BOOL IsInCommandLineMode()
{
    BOOL fShellInCmdLineMode = FALSE;
    IVsShell* pIVsShell = _AtlModule.GetIVsShell();
    if(pIVsShell)
    {
        CComVariant var;
        if(SUCCEEDED(pIVsShell->GetProperty(VSSPROPID_IsInCommandLineMode, &var)))
        {
            fShellInCmdLineMode = (var.boolVal == VARIANT_TRUE);
        }
    }
    return fShellInCmdLineMode;
}

/////////////////////////////////////////////////////////////////////////////
// CSlnExtPackage

CSlnExtPackage::CSlnExtPackage()
{
    ATLTRACE(_T("Creating CSlnExtPackage: 0x%X\n"), this);
    
    m_pNoteWinObj = NULL;
    m_fZombie = FALSE;
}

CSlnExtPackage::~CSlnExtPackage()
{
    ATLTRACE(_T("Destructing CSlnExtPackage: 0x%X\n"), this);
}



/* static */ 
HRESULT WINAPI CSlnExtPackage::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = _AtlModule.GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    if (FAILED(hr))
        return hr;

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName;
    hr = _AtlModule.GetRegDefaultResourceStrings(&cbstrResDllPath, &cbstrResDllName);
    if (FAILED(hr))
        return hr;

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_SlnExtPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_SlnNotesTool(GUID_SlnNotesTool);
    if (!cbstrGUID_SlnNotesTool) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrUICONTEXT_SolutionExists(UICONTEXT_SolutionExists);
    if (!cbstrUICONTEXT_SolutionExists) 
        return E_OUTOFMEMORY;

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
        {L"CLSID_Package",                  cbstrCLSID_Package},
        {L"GUID_SlnNotesTool",              cbstrGUID_SlnNotesTool},
        {L"UICONTEXT_SolutionExists",       cbstrUICONTEXT_SolutionExists},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_OFFICIALNAME",               wszIDS_OFFICIALNAME},
        {L"IDS_PRODUCTDETAILS",             wszIDS_PRODUCTDETAILS},
        {NULL, NULL}
    };

    hr = _AtlModule.UpdateRegistryFromResourceS(IDR_REGISTRYSCRIPT, bRegister, rgMap);
    _ASSERTE(SUCCEEDED(hr));
    if (FAILED(hr))
        return hr;

    // now register/unregister the typelibs
    int rgTlb[] = 
    { 
        IDTLIB_SAMPLE,      // main typelib
        IDTLIB_AUTOMATION   // automation typelib
    };
    for (int iTlbRes = 0; iTlbRes < countof(rgTlb); iTlbRes++)
    {
        WCHAR wszTypeLibRes[21];
        lstrcpyW(wszTypeLibRes, L"\\");
        _itow(rgTlb[iTlbRes], wszTypeLibRes+lstrlenW(wszTypeLibRes), 10);
        if (bRegister)
            hr = _AtlComModule.RegisterTypeLib(wszTypeLibRes);
        else
            _AtlComModule.UnRegisterTypeLib(wszTypeLibRes);

        _ASSERTE(SUCCEEDED(hr));
        if (FAILED(hr))
            return hr;
    }

    return hr;
}

HRESULT CSlnExtPackage::ShowToolWinFrame(void)
{ 
    HRESULT hr = NOERROR;

    // it is important to delay creating tool windows for performance reasons.
    // a good strategy is to wait until the first time that the tool window
    // needs to be shown. this is why we put the call to CreateTool in ShowToolWinFrame.
    if (!m_srpToolWinFrame)
        hr = CreateTool(GUID_SlnNotesTool);    // call our own IVsPackage::CreateTool method
    if (SUCCEEDED(hr))
        hr = m_srpToolWinFrame->Show();
    return hr;
}

/////////////////////////////////////////////////////////////////////////////
// CSlnExtPackage IVsPackage Implementation

STDMETHODIMP CSlnExtPackage::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ATLTRACE(_T("CSlnExtPackage::SetSite\n"));
    _ASSERTE(!m_fZombie);
    USES_CONVERSION;

    if (m_fZombie)
        return E_UNEXPECTED;    // protect against multiple SetSite calls

    HRESULT hr;

    hr = _AtlModule.SetModuleSite(pSP);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }

    // Load the UI Library.
    // This call will initialize "_AtlBaseModule.m_hInstResource" to point to our 
    // localized satellite DLL.
    // Note that IDS_E_BADINSTALL is the id of a string resource within the 
    // package dll itself.
    hr = _AtlModule.LoadUILibrary(CLSID_SlnExtPackage, IDS_E_BADINSTALL);
    if (FAILED(hr))
    {
        _ASSERTE(FALSE);
        return hr;
    }

    hr = CSlnDynamicExtenderProvider::CreateInstance(this, &m_srpCSlnDynamicExtenderProvider);
    _ASSERTE(SUCCEEDED(hr));

    return hr;
}

STDMETHODIMP CSlnExtPackage::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ATLTRACE(_T("CSlnExtPackage::QueryClose\n"));
    _ASSERTE(pCanClose);

    if (!pCanClose)
        return E_POINTER;
    *pCanClose = TRUE;
    return S_OK;
}

STDMETHODIMP CSlnExtPackage::Close(void)
{
    ATLTRACE(_T("CSlnExtPackage::Close\n"));
    _ASSERTE(!m_fZombie);

    HRESULT hr = NOERROR;

    if (m_fZombie)
        return E_UNEXPECTED;

    // set our state for protection
    m_fZombie = TRUE;

    //close the note window
    if(m_pNoteWinObj)
    {
        m_pNoteWinObj->Close();
        m_pNoteWinObj = NULL;
    }

    // and release the pointers we are holding
    m_srpToolWindow.Release();
    m_srpToolWinFrame.Release();

    if (m_srpCSlnDynamicExtenderProvider != NULL)
    {
        m_srpCSlnDynamicExtenderProvider->Close();
        m_srpCSlnDynamicExtenderProvider.Release();
    }

    // close the static extenders
    CSlnStaticExtender::CloseAll();

    _AtlModule.UnloadUILibrary();
    _AtlModule.SetModuleSite(NULL);

    return hr;
}

STDMETHODIMP CSlnExtPackage::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ATLTRACE(_T("CSlnExtPackage::GetAutomationObject\n"));
    _ASSERTE(ppDisp);

   if (!ppDisp)
       return E_POINTER;
   *ppDisp = NULL;
    // create the tool window if not created
    if (!m_srpToolWindow)
    {
        HRESULT hr = CreateTool(GUID_SlnNotesTool);
        if (FAILED(hr)) 
            return hr;
    }
    return m_srpToolWindow->QueryInterface(IID_ISolutionNotes, (LPVOID*)ppDisp);
}

STDMETHODIMP CSlnExtPackage::CreateTool(
                    /*[in]*/ REFGUID rguid) 
{ 
    ATLTRACE(_T("CSlnExtPackage::CreateTool\n"));
    _ASSERTE(!m_fZombie);

    if (m_fZombie)
        return E_UNEXPECTED;

    if (rguid == GUID_SlnNotesTool)
    {
        CComPtr<IVsUIShell>    srpShell;

        // now get the IVsUIShell interface so we can create a tool window
        //
        HRESULT hr = _AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpShell);

        if (SUCCEEDED(hr))
        {
            USES_CONVERSION;
            BOOL    fDefaultPosition = TRUE;
            CComBSTR bstrTitle;
            TCHAR szTitle[128];
            
            if (! ::LoadString(_AtlBaseModule.GetResourceInstance(), IDS_WINDOW_TITLE, szTitle, countof(szTitle)))
                return HRESULT_FROM_WIN32(::GetLastError());

            hr = CComObject<CNoteToolWindow>::CreateInstance(&m_pNoteWinObj);
            _ASSERTE((SUCCEEDED(hr) && m_pNoteWinObj) || !_T("Failed to create notes window"));
            if (!m_pNoteWinObj)
                return E_OUTOFMEMORY;

            hr = m_pNoteWinObj->QueryInterface(IID_IVsWindowPane, (void**)&m_srpToolWindow);
            _ASSERTE(SUCCEEDED(hr) || !_T("Could not get IVsWindowPane from notes toolwindow"));

            hr = srpShell->CreateToolWindow(
                        CTW_fInitNew | CTW_fForceCreate,    // dwCTW
                        NULL,                            // dwReserved
                        (IUnknown*)m_srpToolWindow.p,    // punkTool
                        GUID_NULL,                    // rclsidTool
                        GUID_SlnNotesTool,            // rguidPersistanceSlot
                        GUID_NULL,                        // rguidAutoActivate
                        NULL,                            // pSP
                        T2OLE(szTitle),                        // pszCaption 
                        &fDefaultPosition,                // pfDefaultPosition
                        &m_srpToolWinFrame);            // ppWindowFrame
        
            // if CreateToolWindow failed let's give the user a useful error message
            if (FAILED(hr))
            {
                _AtlModule.SetErrorInfo(hr, IDS_E_CANTCREATETOOL, 0);
                return hr;
            }

            //initialize the bitmap
            CComVariant cvar;
            cvar = IDB_NOTES;
            m_srpToolWinFrame->SetProperty(
                    /* [in] VSFPROPID propid */  VSFPROPID_BitmapResource,
                    /* [in] VARIANT   var    */  cvar);

            cvar = bmpidNote - 1;          // cmdbar bitmap indexes are 1-based
            m_srpToolWinFrame->SetProperty(
                    /* [in] VSFPROPID propid */  VSFPROPID_BitmapIndex,
                    /* [in] VARIANT   var    */  cvar);
            return hr;
        }
    }

    return E_NOTIMPL;
}

STDMETHODIMP CSlnExtPackage::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ATLTRACE(_T("CSlnExtPackage::ResetDefaults\n"));

    return E_NOTIMPL;
}

STDMETHODIMP CSlnExtPackage::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* ppage)
{
    ATLTRACE(_T("CSlnExtPackage::GetPropertyPage\n"));

    return E_NOTIMPL;
}


///////////////////////////////////////////////////////////////////////////////
// CSlnExtPackage IOleCommandTarget Implementation

#pragma warning(disable:4065) // switch statement contains 'default' but no 'case' labels

STDMETHODIMP CSlnExtPackage::QueryStatus(
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

    if (*pguidCmdGroup == guidSlnExtCmdSet)
    {
        // The following bitwise flags control the state of a command:
        //        OLECMDF_SUPPORTED, OLECMDF_ENABLED, OLECMDF_LATCHED,
        //        OLECMDF_NINCHED, OLECMDF_INVISIBLE, OLECMDF_DEFHIDEONCTXTMENU
        //
        // Common cases are the following:
        //    1. Enable a command --  cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED
        //    2. Disable a command -- cmdf = OLECMDF_SUPPORTED
        //    3. Hide a command --    cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE
        cmdf = OLECMDF_SUPPORTED;

        switch (prgCmds[0].cmdID)
        {
        case icmdAddNote:
            {
                //only visible if there is a solution
                CComPtr<IVsSolution> srpSol;
                CComBSTR bstrDir;

                if(SUCCEEDED(_AtlModule.QueryService(SID_SVsSolution, IID_IVsSolution, (LPVOID*)&srpSol)))
                {
                    srpSol->GetSolutionInfo(&bstrDir, NULL, NULL);
                    if(bstrDir.m_str)
                    {
                        cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                        break;
                    }
                }
            }
            cmdf = OLECMDF_SUPPORTED | OLECMDF_INVISIBLE;
            break;

        case icmdViewNotes:
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

STDMETHODIMP CSlnExtPackage::Exec(
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

    if (*pguidCmdGroup == guidSlnExtCmdSet)
    {
        // IOleCommandTargt::Exec should report errors that may occur
        // in the execution of a command. Therefore clear any existing
        // existing error info first
        _AtlModule.ClearErrorInfo();

        switch (nCmdID)
        {
            case icmdAddNote:
                hr = AddNewNote();
                break;

            case icmdViewNotes:
                hr = ShowToolWinFrame();
                break;

            default:
                return OLECMDERR_E_NOTSUPPORTED;
        }

        if (FAILED(hr))
        {
            _AtlModule.ReportErrorInfo(hr);
            hr = S_OK;
        }
    }
    else
        return OLECMDERR_E_UNKNOWNGROUP;

    return hr;
}


///////////////////////////////////////////////////////////////////////////////
// CSlnExtPackage IServiceProvider Implementation

STDMETHODIMP CSlnExtPackage::QueryService(
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

HRESULT CSlnExtPackage::AddNewNote()
{
    HRESULT hr = NOERROR;
    if(!m_srpToolWinFrame || m_srpToolWinFrame->IsVisible() == S_FALSE)
        if(FAILED(hr = ShowToolWinFrame())) return hr;

    CComQIPtr<ISolutionNotes> srpSlnNotes(m_srpToolWindow);
    return srpSlnNotes->Add(NULL);
}

///////////////////////////////////////////////////////////////////////////////
// CSlnExtPackage IVsPersistSolutionOpts Implementation
STDMETHODIMP CSlnExtPackage::LoadUserOptions(IVsSolutionPersistence* pPersistence, VSLOADUSEROPTS grfLoadOpts)
{
    if (IsInCommandLineMode())
        return S_OK;
    if (!pPersistence)
        return E_POINTER;
    return pPersistence->LoadPackageUserOpts((IVsPersistSolutionOpts*)this, m_szPersistKey);
}

STDMETHODIMP CSlnExtPackage::ReadUserOptions(IStream* pOptionsStream, LPCOLESTR szKey)
{
    if (IsInCommandLineMode())
        return S_OK;
    HRESULT hr = NOERROR;
    if(!m_pNoteWinObj)
        if(FAILED(hr = CreateTool(GUID_SlnNotesTool))) return hr;
    return m_pNoteWinObj->LoadOpts(pOptionsStream);
}

STDMETHODIMP CSlnExtPackage::SaveUserOptions(IVsSolutionPersistence* pPersistence)
{
    if (IsInCommandLineMode())
        return S_OK;
    if (!pPersistence)
        return E_POINTER;
    return pPersistence->SavePackageUserOpts((IVsPersistSolutionOpts*)this, m_szPersistKey);
}

STDMETHODIMP CSlnExtPackage::WriteUserOptions(IStream* pOptionsStream, LPCOLESTR szKey)
{
    if (IsInCommandLineMode())
        return S_OK;
    if(!m_pNoteWinObj) return NOERROR;
    return m_pNoteWinObj->SaveOpts(pOptionsStream);
}

///////////////////////////////////////////////////////////////////////////////
// CSlnExtPackage IVsPersistSolutionOpts Implementation

STDMETHODIMP CSlnExtPackage::OnProjectLoadFailure(IVsHierarchy* pStubHierarchy, LPCOLESTR szProjectName, LPCOLESTR szProjectMk, LPCOLESTR szKey)
{
    return E_NOTIMPL;
}

STDMETHODIMP CSlnExtPackage::QuerySaveSolutionProps(IVsHierarchy* pHierarchy, VSQUERYSAVESLNPROPS* pqsspSave)
{
    if(!pqsspSave) return E_POINTER;

    if(pHierarchy)
    {
        // only put ours on the global level,
        // no per project props
        *pqsspSave = QSP_HasNoProps;
    }
    else
    {
        if(!m_pNoteWinObj) 
            *pqsspSave = QSP_HasNoDirtyProps;
        else
            *pqsspSave = (m_pNoteWinObj->GetModified() == S_OK) ? QSP_HasDirtyProps : QSP_HasNoDirtyProps;
    }

    return NOERROR;
}

STDMETHODIMP CSlnExtPackage::ReadSolutionProps(IVsHierarchy* pHierarchy, LPCOLESTR szProjectName, LPCOLESTR szProjectMk, LPCOLESTR szKey, BOOL fPreLoad, IPropertyBag* pPropBag)
{
    if (IsInCommandLineMode())
        return S_OK;
    HRESULT hr = NOERROR;
    if(!m_pNoteWinObj)
        if(FAILED(hr = CreateTool(GUID_SlnNotesTool))) return hr;
    return m_pNoteWinObj->LoadProps(szKey, pPropBag);
}

STDMETHODIMP CSlnExtPackage::SaveSolutionProps(IVsHierarchy* pHierarchy, IVsSolutionPersistence* pPersistence)
{
    // we only save into the global section
    if (IsInCommandLineMode())
        return S_OK;
    if(!pHierarchy)
    {
        if (!pPersistence)
            return E_POINTER;
        return pPersistence->SavePackageSolutionProps(FALSE, pHierarchy, (IVsPersistSolutionProps*)this, m_szPersistKey);
    }
    else return NOERROR;
}

STDMETHODIMP CSlnExtPackage::WriteSolutionProps(IVsHierarchy* pHierarchy, LPCOLESTR szKey, IPropertyBag* pPropBag)
{
    if (IsInCommandLineMode())
        return S_OK;
    if(!m_pNoteWinObj) return NOERROR;
    return m_pNoteWinObj->SaveProps(pPropBag);
}

STDMETHODIMP CSlnExtPackage::GetSolutionNotes(
    /* [out] */ ISolutionNotes ** ppISolutionNotes)
{
    if (!m_pNoteWinObj)
    {
        HRESULT hr = CreateTool(GUID_SlnNotesTool);
        IfFailRet(hr);
        ExpectedExprRet(m_pNoteWinObj != NULL);
    }
    return m_pNoteWinObj->QueryInterface(IID_ISolutionNotes, (void**)ppISolutionNotes);
}
