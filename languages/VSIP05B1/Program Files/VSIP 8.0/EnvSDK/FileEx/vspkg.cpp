
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// VsPkg.cpp
//
// Implementation of CFileExPackage
//
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"
#include "FileSysTool.h"
#include "ExData.h"
#include "TriHost.h"
#include "Magic.h"
#include "CmdExec.h"

//*****************************************************************************
// CFileExPackage Constructor/Destructor
//*****************************************************************************

CFileExPackage::CFileExPackage()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::CFileExPackage \n") );

    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("FileEx: Creating CFileExPackage: 0x%X\n"), this);
    }

    m_fZombie = FALSE;
    m_dwMagicCookie = 0;
    m_dwCmdExecCookie = 0;
}

CFileExPackage::~CFileExPackage()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::~CFileExPackage \n") );

    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Destructing CFileExPackage: 0x%X\n"), this);
    }

}


//*****************************************************************************
// CFileExPackage IVsPackage Implementation
//*****************************************************************************

/* static */ 
HRESULT WINAPI CFileExPackage::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    if FAILED(hr)
        return hr;

    // get the RESOURCE_PATH and RESOURCE_DLL strings 
    CComBSTR cbstrResDllPath;
    CComBSTR cbstrResDllName;
    hr = GetRegDefaultResourceStrings(&cbstrResDllPath, &cbstrResDllName);
    if FAILED(hr)
        return hr;

    // get the guid strings
    CComBSTR cbstrCLSID_Package(CLSID_FileExPackage);
    if (!cbstrCLSID_Package) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrguidFileSysTool(guidFileSysTool);
    if (!cbstrguidFileSysTool) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrguidFileSysOutputWindow(guidFileSysOutputWindow);
    if (!cbstrguidFileSysOutputWindow) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_TaskList(GUID_TaskList);
    if (!cbstrGUID_TaskList) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrSID_SCommandExecuter(SID_SCommandExecuter);
    if (!cbstrSID_SCommandExecuter) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrSID_SMagicDisplay(SID_SMagicDisplay);
    if (!cbstrSID_SMagicDisplay) 
        return E_OUTOFMEMORY;
    CComBSTR cbstrGUID_ExDataEE(GUID_ExDataEE);
    if (!cbstrGUID_ExDataEE) 
        return E_OUTOFMEMORY;

    // get the resource id numbers
    const int iMaxResIdLen = 11;
    WCHAR wszIDS_PACKAGE_LOAD_KEY[iMaxResIdLen];
    WCHAR wszIDS_OFFICIALNAME[iMaxResIdLen];
    WCHAR wszIDS_PRODUCTDETAILS[iMaxResIdLen];
    WCHAR wszIDS_OUTPUTWIN_TITLE[iMaxResIdLen];
    WCHAR wszIDI_ABOUT[iMaxResIdLen];
    _ultow(IDS_PACKAGE_LOAD_KEY,        wszIDS_PACKAGE_LOAD_KEY,        10);
    _ultow(IDS_OFFICIALNAME,            wszIDS_OFFICIALNAME,            10);
    _ultow(IDS_PRODUCTDETAILS,          wszIDS_PRODUCTDETAILS,          10);
    _ultow(IDS_OUTPUTWIN_TITLE,         wszIDS_OUTPUTWIN_TITLE,         10);
    _ultow(IDI_ABOUT,                   wszIDI_ABOUT,                   10);

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"RESOURCE_PATH",                  cbstrResDllPath},
        {L"RESOURCE_DLL",                   cbstrResDllName},
        {L"CLSID_Package",                  cbstrCLSID_Package},
        {L"guidFileSysTool",                cbstrguidFileSysTool},
        {L"guidFileSysOutputWindow",        cbstrguidFileSysOutputWindow},
        {L"GUID_TaskList",                  cbstrGUID_TaskList},
        {L"SID_SCommandExecuter",           cbstrSID_SCommandExecuter},
        {L"SID_SMagicDisplay",              cbstrSID_SMagicDisplay},
        {L"GUID_ExDataEE",                  cbstrGUID_ExDataEE},
        {L"IDS_PACKAGE_LOAD_KEY",           wszIDS_PACKAGE_LOAD_KEY},
        {L"IDS_OFFICIALNAME",               wszIDS_OFFICIALNAME},
        {L"IDS_PRODUCTDETAILS",             wszIDS_PRODUCTDETAILS},
        {L"IDS_OUTPUTWIN_TITLE",            wszIDS_OUTPUTWIN_TITLE},
        {L"IDI_ABOUT",                      wszIDI_ABOUT},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_PACKAGE, bRegister, rgMap);
}


STDMETHODIMP CFileExPackage::SetSite(
                    /*[in]*/ IServiceProvider* pSP)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::SetSite \n") );
 
    ExpectedPtrRet(pSP);
    CheckZombieState(m_fZombie);

    CComPtr<IProfferService> srpProffer;
    HRESULT hr;

    // site the module
    _VxModule.SetModuleSite(pSP);

    // load the satellite dll, _AtlBaseModule.GetResourceInstance now returns UI 
    hr = _VxModule.LoadUILibrary(CLSID_FileExPackage, 0);
    _IfFailGo(hr);

    // init the extension manager
    g_ExtMgr.InitExtensions();

    // register proffered services
    hr = _VxModule.QueryService(SID_SProfferService, IID_IProfferService,
                              (void**)&srpProffer);
    IfFailGoMsg(hr, "Failed to get SID_SProfferService");

    hr = srpProffer->ProfferService(SID_SMagicDisplay, static_cast<IServiceProvider*>(this),
                                    &m_dwMagicCookie);
    IfFailGo(hr);

    hr = srpProffer->ProfferService(SID_SCommandExecuter, static_cast<IServiceProvider*>(this),
                                    &m_dwCmdExecCookie);
    IfFailGo(hr);

    // initialize the file system
    hr = g_FileSys.Initialize();
    IfFailGoMsg(hr, "Failed to initialize file system");

OnError:
    if (FAILED(hr))
    {
        // Call Close to free anything we may have cached, 
        // in case the package manager does not call it
        Close();
    }
    return hr;
}

STDMETHODIMP CFileExPackage::QueryClose(
                    /*[out]*/ BOOL* pCanClose)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::QueryClose \n") );
    IfNullRet(pCanClose);

    *pCanClose = TRUE;
    return S_OK;
}

STDMETHODIMP CFileExPackage::Close(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::Close \n") );

    if (m_fZombie)
        return S_FALSE;

    // release the File System Browser ToolWindow
    m_srpFileSysToolCmdTgt.Release();
    m_srpFileSysToolFrame.Release();

    // free the extension manager
    g_ExtMgr.FreeExtensions();

    // close the file system
    g_FileSys.Close();

    // unload the satellite dll
    _VxModule.UnloadUILibrary();

    // finally release the site
    _VxModule.SetModuleSite(NULL);


    m_fZombie = TRUE;
    return S_OK;
}

STDMETHODIMP CFileExPackage::GetAutomationObject(
                    /*[in] */ LPCOLESTR   pszPropName,
                    /*[out]*/ IDispatch** ppDisp)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::GetAutomationObject \n") );

    IfNullRet(ppDisp);

    *ppDisp = NULL;
    return E_NOTIMPL;
}

STDMETHODIMP CFileExPackage::CreateTool(
                    /*[in]*/ REFGUID rguidTool) 
{ 
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::CreateTool \n") );

    CheckZombieState(m_fZombie);

    HRESULT hr = E_NOTIMPL;

    if (rguidTool == guidFileSysTool)
    {
        hr = OnViewFileSysToolWindow(FALSE);
    }

    return hr;
}

STDMETHODIMP CFileExPackage::ResetDefaults(
                    /*[in]*/ PKGRESETFLAGS dwFlags)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::ResetDefaults \n") );

    return E_NOTIMPL;
}

STDMETHODIMP CFileExPackage::GetPropertyPage(
                    /*[in]    */ REFGUID          rguidPage,
                    /*[in,out]*/ VSPROPSHEETPAGE* pPage)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::GetPropertyPage \n") );

    ExpectedPtrRet(pPage);

    HRESULT hr = E_NOTIMPL;

    return hr;
}


//*****************************************************************************
// CFileExPackage IOleCommandTarget Implementation
//*****************************************************************************

STDMETHODIMP CFileExPackage::QueryStatus(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::QueryStatus \n") );

    CheckZombieState(m_fZombie);
    IfNullRet(pguidCmdGroup);
    IfNullRet(prgCmds);
    ExpectedExprRet(cCmds == 1);

    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;
    DWORD cmdf = 0;

    if (*pguidCmdGroup == guidEUCmd)
    {
        hr = S_OK;

        switch (prgCmds[0].cmdID)
        {
            case cmdidFileSysTool:
                cmdf = OLECMDF_SUPPORTED | OLECMDF_ENABLED;
                hr = S_OK;
                break;
            case cmdidFolderView:
            case cmdidShortcutView:
            case cmdidFilesOpenFile:
            case cmdidFilesPreviewFile:
            case cmdidFilesRefresh:
            case cmdidFilesFilter:
            case cmdidFilesFilterHandler:
            case cmdidFoldersRefresh:
                if (m_srpFileSysToolCmdTgt)
                {
                    hr = m_srpFileSysToolCmdTgt->QueryStatus(pguidCmdGroup, cCmds,
                                                             prgCmds, pCmdText);
                    return hr;
                }
                else
                {
                    cmdf = OLECMDF_SUPPORTED;
                    hr = S_OK;
                }
                break;
            default:
                hr = OLECMDERR_E_NOTSUPPORTED;
        }
    }

    prgCmds[0].cmdf = cmdf;
    return hr;
}

STDMETHODIMP CFileExPackage::Exec(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdExecOpt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::Exec \n") );

    CheckZombieState(m_fZombie);
    IfNullRet(pguidCmdGroup);

    HRESULT hr = OLECMDERR_E_UNKNOWNGROUP;
    BOOL fHandled = FALSE;
    BOOL fReportError = TRUE;

    _VxModule.ClearErrorInfo();

    if (*pguidCmdGroup == guidEUCmd)
    {
        switch (nCmdID)
        {
            case cmdidFileSysTool:
                fHandled = TRUE;
                hr = OnViewFileSysToolWindow(TRUE);
                break;
            case cmdidFilesFilter:
                if (pvaOut)
                {
                    hr = g_FileSys.ExecGetCurrentFilter(pvaOut);
                    fHandled = TRUE;
                    fReportError = FALSE;
                }
                else
                {
                    _ASSERTE_MSG(FALSE, "Command should have gone to file system tool");
                    hr = OLECMDERR_E_NOTSUPPORTED;
                }
                break;
            case cmdidFilesFilterHandler:
                hr = g_FileSys.ExecFilterHandler(pvaOut);
                fHandled = TRUE;
                fReportError = FALSE;
                break;
            case cmdidFilesOpenFile:
            case cmdidFilesPreviewFile:
            case cmdidFilesRefresh:
            case cmdidFolderView:
            case cmdidShortcutView:
            case cmdidFoldersRefresh:
                _ASSERTE_MSG(FALSE, "Command should have gone to file system tool");
                // fall through
            default:
                fHandled = FALSE;
                hr = OLECMDERR_E_NOTSUPPORTED;
        }
    }

    if (fHandled && fReportError)
    {
        _VxModule.ReportErrorInfo(hr);
        hr = S_OK;
    }

    return hr;
}


//*****************************************************************************
// CFileExPackage IServiceProvider Implementation
//*****************************************************************************

STDMETHODIMP CFileExPackage::QueryService(
                    /*[in] */ REFGUID rsid,
                    /*[in] */ REFIID  riid,
                    /*[out]*/ void**  ppvObject)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::QueryService \n") );

    CheckZombieState(m_fZombie);
    IfNullRet(ppvObject);

    InitParam(ppvObject);

    HRESULT hr = E_NOINTERFACE;

    if (rsid == SID_SCommandExecuter)
    {
        CComPtr<IUnknown> srpCmdExec;

        AtlCreateInstance(CCommandExecuter, IID_IUnknown, &srpCmdExec);
        IfFailGo(hr);

        hr = srpCmdExec->QueryInterface(riid, ppvObject);
    }
    else if (rsid == SID_SMagicDisplay)
    {
        CComPtr<IUnknown> srpUnkMagic;

        AtlCreateInstance(CMagicDisplay, IID_IUnknown, &srpUnkMagic);
        IfFailGo(hr);

        hr = srpUnkMagic->QueryInterface(riid, ppvObject);
    }

OnError:
    return hr;
}


//*****************************************************************************
// CFileExPackage IVsPackageStaticExData Implementation
//*****************************************************************************

STDMETHODIMP CFileExPackage::GetStaticExData(
                    /*[in] */ REFGUID          rguidData,
                    /*[out]*/ ULONG*           pcbData,
                    /*[out]*/ unsigned short** ppData,
                    /*[out]*/ ULONG*           pcMaxRecords)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::GetStaticExData \n") );

    SafeInitParam(pcbData);
    SafeInitParam(ppData);
    SafeInitParam(pcMaxRecords);

    HRESULT hr = E_NOTIMPL;

    if (rguidData == GUID_ExDataEE)
    {
        SafeInitParamTo(pcbData, sizeof(EEData));
        SafeInitParamTo(ppData, (unsigned short*)&(EEData[0]));
        SafeInitParamTo(pcMaxRecords, EE_MLS);
        hr = S_OK;
    }
    return hr;
}


//*****************************************************************************
// CFileExPackage CommandTarget Implementation
//*****************************************************************************

HRESULT CFileExPackage::OnViewFileSysToolWindow(BOOL fForceShow)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileExPackage::OnViewFileSysToolWindow \n") );

    HRESULT hr;

    if (m_srpFileSysToolFrame == NULL)
    {
        hr = CFileSystemToolWindow::CreateTool(&m_srpFileSysToolFrame);
        IfFailGo(hr);

        hr = m_srpFileSysToolFrame->QueryViewInterface(IID_IOleCommandTarget,
                                                       (void**)&m_srpFileSysToolCmdTgt);
        _ASSERTE(SUCCEEDED(hr));
    }

    _ASSERTE(m_srpFileSysToolFrame);

    if (fForceShow)
    {
        hr = m_srpFileSysToolFrame->Show();
        _ASSERTE(SUCCEEDED(hr));
    }

    hr = S_OK;

OnError:
    if (FAILED(hr))
    {
        if (m_srpFileSysToolFrame)
            m_srpFileSysToolFrame->CloseFrame(FRAMECLOSE_NoSave);

        m_srpFileSysToolFrame.Release();
        m_srpFileSysToolCmdTgt.Release();
    }
    return hr;
}
