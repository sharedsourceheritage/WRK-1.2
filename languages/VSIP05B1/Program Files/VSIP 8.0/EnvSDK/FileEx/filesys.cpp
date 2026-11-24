
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FileSys.cpp
//
// Implementation of CFileSystem and related stuff
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "FSCmdDlg.h"

static const TCHAR* s_lpszOptionsRegRoot = _T("Software\\Microsoft\\FileEx\\1.0\\FileSystemBrowser");
static const TCHAR* s_lpszShortcutsKey = _T("Shortcuts");
static const TCHAR* s_lpszFiltersKey = _T("Filters");
static const TCHAR* s_lpszAllFilterValue = _T("AllFilter");
static const TCHAR* s_lpszCommandsKey = _T("Commands");
static const TCHAR* s_lpszCommandCountValue = _T("Count");
static const TCHAR* s_lpszCommandNameValue = _T("CmdName%d");
static const TCHAR* s_lpszCommandCmdValue = _T("Cmd%d");
static const TCHAR* s_lpszCommandArgsValue = _T("CmdArgs%d");
static const TCHAR* s_lpszCommandFlagsValue = _T("CmdFlags%d");

CFileSystem g_FileSys;

//*****************************************************************************
// CFileSystem Constructor/Destructor
//*****************************************************************************

CFileSystem::CFileSystem()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::CFileSystem \n") );

    m_fOptionsDirty = FALSE;
    m_nMRUFilters = 0;
    m_psaFilters = NULL;
    m_fInitialized = FALSE;
    m_fClosed = FALSE;

    for (int i = 0; i < MAX_MRU_FILTERS; i++)
        m_rgbstrMRUFilters[i] = NULL;
    m_fAllFilter = TRUE;
}

CFileSystem::~CFileSystem()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::~CFileSystem \n") );
}


//*****************************************************************************
// CFileSystem Operations
//*****************************************************************************

HRESULT CFileSystem::Initialize()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::Initialize \n") );

    if (m_fInitialized)
        return S_FALSE;

    m_fInitialized = TRUE;

    HKEY hkeyOptionsRoot = NULL;
    HRESULT hr;

    // initialize the folder pool
    CFileSystemFolderItem::InitFolderPool();

    // initialize the file pool
    CFileSystemFileItem::InitFilePool();

    // initialize drives collection
    m_rgDrives.SetSize(0, 2);

    // initialize the commands collection
    m_rgCommands.SetSize(0, 2);

    hr = LoadDrives();

    // open the registry root for options
    hkeyOptionsRoot = GetOptionsRegRoot(TRUE);

    // initialize shortcuts
    m_rgShortcuts.SetSize(0, 2);

    // get the registry root to load the options
    if (hkeyOptionsRoot)
    {
        hr = LoadShortcuts(hkeyOptionsRoot);
        IfFailGo(hr);

        hr = LoadFilters(hkeyOptionsRoot);
        IfFailGo(hr);

        hr = LoadCommands(hkeyOptionsRoot);
        IfFailGo(hr);
    }
    else
    {
        // first time... no options saved
        hr = S_OK;
        SetFileSystemOptionsDirty();
    }

OnError:
    if (hkeyOptionsRoot)
    {
        RegCloseKey(hkeyOptionsRoot);
    }
    return hr;
}

HRESULT CFileSystem::Close()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::Close \n") );

    if (m_fClosed)
        return S_FALSE;
    m_fClosed = TRUE;

    HKEY hkeyOptionsRoot = NULL;
    HRESULT hr;

    // save options if dirty
    if (m_fOptionsDirty)
    {
        hkeyOptionsRoot = GetOptionsRegRoot(FALSE);

        hr = SaveShortcuts(hkeyOptionsRoot);
        _ASSERTE(SUCCEEDED(hr));

        hr = SaveFilters(hkeyOptionsRoot);
        _ASSERTE(SUCCEEDED(hr));

        hr = SaveCommands(hkeyOptionsRoot);
        _ASSERTE(SUCCEEDED(hr));
    }

    if (hkeyOptionsRoot)
    {
        RegCloseKey(hkeyOptionsRoot);
    }

    // remove filters array
    FreeFilters();

    // remove all the drives
    RemoveAllDrives();

    // remove all the shortcuts
    RemoveAllShortcuts(FALSE);

    // reset all the cached folders
    for (int i = 0; i < MAX_CACHED_FOLDERS; i++)
    {
        m_rgCachedFolders[i].Reset();
    }

    // remove all the commands
    RemoveAllCommands();

    // close the folder pool
    CFileSystemFolderItem::CloseFolderPool();

    // close the file pool
    CFileSystemFileItem::CloseFilePool();

    return S_OK;
}


long CFileSystem::GetShortcutCount()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::GetShortcutCount \n") );

    return m_rgShortcuts.GetUpperBound() + 1;
}

CFileSystemFolderItem* CFileSystem::GetShortcut(int nIndex)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::GetShortcut \n") );

    _ASSERTE((nIndex >= 0) && (nIndex <= m_rgShortcuts.GetUpperBound()));

    CFileSystemFolderItem* pFolder =
        (CFileSystemFolderItem*)m_rgShortcuts.GetAt(nIndex);
    _ASSERTE(pFolder);

    return pFolder;
}

CFileSystemFolderItem* CFileSystem::AddShortcut(LPCTSTR lpszPath, BOOL fSetDirty)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::AddShortcut \n") );

    DWORD dwAttr = GetFileAttributes(lpszPath);
    CFileSystemFolderItem* pFolder = NULL;

    if (dwAttr == 0xFFFFFFFF)
    {
        // the folder no longer exists for some reason
        return NULL;
    }

    pFolder = CFileSystemFolderItem::CreateFolderItem();
    if (pFolder)
    {
        _ASSERTE(dwAttr & FILE_ATTRIBUTE_DIRECTORY);

        pFolder->InitShortcutFolder(lpszPath,
                                    ((dwAttr & FILE_ATTRIBUTE_READONLY) != 0),
                                    ((dwAttr & FILE_ATTRIBUTE_HIDDEN) != 0),
                                    ((dwAttr & FILE_ATTRIBUTE_COMPRESSED) != 0));
        m_rgShortcuts.Add(pFolder);

        if (fSetDirty)
            SetFileSystemOptionsDirty();
    }

    return pFolder;
}

BOOL CFileSystem::RemoveShortcut(CFileSystemFolderItem* pShortcut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::RemoveShortcut \n") );

    CFileSystemFolderItem* pFolder;
    int nFolders = m_rgShortcuts.GetUpperBound() + 1;
    BOOL fFound = FALSE;

    for (int i = 0; i < nFolders; i++)
    {
        pFolder = (CFileSystemFolderItem*)m_rgShortcuts.GetAt(i);
        _ASSERTE(pFolder);

        if (pFolder == pShortcut)
        {
            m_rgShortcuts.RemoveAt(i);
            CFileSystemFolderItem::FreeFolderItem(pFolder);

            SetFileSystemOptionsDirty();
            fFound = TRUE;
            break;
        }
    }

    return fFound;
}

void CFileSystem::RemoveAllShortcuts(BOOL fSetDirty)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::RemoveAllShortcuts \n") );

    CFileSystemFolderItem* pFolder;
    int nFolders = m_rgShortcuts.GetUpperBound() + 1;

    for (int i = 0; i < nFolders; i++)
    {
        pFolder = (CFileSystemFolderItem*)m_rgShortcuts.GetAt(i);
        _ASSERTE(pFolder);

        CFileSystemFolderItem::FreeFolderItem(pFolder);
    }

    m_rgShortcuts.RemoveAll();
    if (fSetDirty)
        SetFileSystemOptionsDirty();
}


long CFileSystem::GetDriveCount()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::GetDriveCount \n") );

    return m_rgDrives.GetUpperBound() + 1;
}

CFileSystemFolderItem* CFileSystem::GetDrive(int nIndex)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::GetDrive \n") );

    _ASSERTE((nIndex >= 0) && (nIndex < GetDriveCount()));

    return (CFileSystemFolderItem*)m_rgDrives.GetAt(nIndex);
}


CFileSystemCachedFolder* CFileSystem::GetFolderFiles(CFileSystemFolderItem* pFolder)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::GetFolderFiles \n") );

    _ASSERTE(pFolder);

    CFileSystemCachedFolder* pCachedFolder = NULL;
    int nLastUsable = -1;
    int nLastReset = -1;

    for (int i = 0; i < MAX_CACHED_FOLDERS; i++)
    {
        pCachedFolder = &m_rgCachedFolders[i];
        if (pCachedFolder->IsUsable())
            nLastUsable = i;
        if (pCachedFolder->IsReset())
            nLastReset = i;
        else
        {
            CFileSystemFolderItem* pTempFolder = pCachedFolder->GetFolder();
            _ASSERTE(pTempFolder);
            if (pTempFolder->ComparePath(pFolder) == 0)
            {
                pCachedFolder->SetUsable(FALSE);
                return pCachedFolder;
            }
        }
    }

    int nIndex = (nLastReset == -1) ? nLastUsable : nLastReset;

    _ASSERTE(nIndex != -1);
    pCachedFolder = &m_rgCachedFolders[nIndex];
    pCachedFolder->Reset();
    pCachedFolder->InitFolder(pFolder);
    pCachedFolder->SetUsable(FALSE);

    return pCachedFolder;
}

void CFileSystem::FreeFolderFiles(CFileSystemCachedFolder* pCachedFolder)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::FreeFolderFiles \n") );

    _ASSERTE(pCachedFolder);
    _ASSERTE(pCachedFolder->IsUsable() == FALSE);

	if (pCachedFolder)
		pCachedFolder->SetUsable(TRUE);
}


HRESULT CFileSystem::ExecFilterHandler(VARIANT* pvarOut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::ExecFilterHandler \n") );

    ExpectedPtrRet(pvarOut);

    HRESULT hr = E_OUTOFMEMORY;
    VariantClear(pvarOut);

    SAFEARRAY* psaFilters = NULL;

    if (!m_psaFilters)
        CreateFiltersSafeArray();
    if (m_psaFilters)
    {
        SafeArrayCopy(m_psaFilters, &psaFilters);
        IfFailAllocGo(psaFilters);
    }
    if (psaFilters != NULL)
    {
        V_VT(pvarOut) = VT_ARRAY | VT_BSTR;
        V_ARRAY(pvarOut) = psaFilters;

        hr = S_OK;
    }

OnError:
    return hr;
}

HRESULT CFileSystem::ExecGetCurrentFilter(VARIANT* pvarOut)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::ExecGetCurrentFilter \n") );

    ExpectedPtrRet(pvarOut);

    VariantClear(pvarOut);
    pvarOut->vt = VT_BSTR;

    if (m_fAllFilter)
        pvarOut->bstrVal = SysAllocString(L"*.*");
    else if (m_rgbstrMRUFilters[0])
        pvarOut->bstrVal = SysAllocString(m_rgbstrMRUFilters[0]);
    else
        pvarOut->bstrVal = SysAllocString(L"");

    return pvarOut->bstrVal ? S_OK : E_OUTOFMEMORY;
}

HRESULT CFileSystem::ExecSetCurrentFilter(VARIANT* pvarIn)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::ExecSetCurrentFilter \n") );

    ExpectedPtrRet(pvarIn);
    ExpectedExprRet((pvarIn->vt == VT_BSTR) && pvarIn->bstrVal);

    BSTR bstrFilter = pvarIn->bstrVal;
    HRESULT hr;
    int nIndex = -1;
    int i;

    // is it the all filter
    if (wcscmp(pvarIn->bstrVal, L"*.*") == 0)
    {
        m_fAllFilter = TRUE;
        hr = S_OK;
        goto OnError;
    }

    m_fAllFilter = FALSE;

    // search for an existing filter
    for (i = 0; i < MAX_MRU_FILTERS; i++)
    {
        if (m_rgbstrMRUFilters[i] == NULL)
            break;
        if (wcscmp(m_rgbstrMRUFilters[i], bstrFilter) == 0)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex != -1)
    {
        // found it... make it most recent
        BSTR bstrSelected = m_rgbstrMRUFilters[nIndex];
        for (i = nIndex - 1; i >= 0; i--)
            m_rgbstrMRUFilters[i+1] = m_rgbstrMRUFilters[i];
        m_rgbstrMRUFilters[0] = bstrSelected;

        FreeFiltersSafeArray();
        hr = S_OK;
    }
    else
    {
        // didn't find it... add it as most recent filter
        BSTR bstrSelected = SysAllocString(bstrFilter);
        IfFailAllocGo(bstrSelected);

        for (i = m_nMRUFilters - 1; i >= 0; i--)
            if ((i+1) != MAX_MRU_FILTERS)
                m_rgbstrMRUFilters[i+1] = m_rgbstrMRUFilters[i];

        m_rgbstrMRUFilters[0] = bstrSelected;
        m_nMRUFilters++;

        FreeFiltersSafeArray();
        hr = S_OK;
    }

OnError:
    if (SUCCEEDED(hr))
        SetFileSystemOptionsDirty();
    return hr;
}

BOOL CFileSystem::FilterFile(CFileSystemFileItem* pFile)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::FilterFile \n") );

    _ASSERTE(pFile);
    _ASSERTE(IsFilterEnabled());
	if (!pFile)
		return FALSE;

    USES_CONVERSION;
    return m_fAllFilter || PathMatchSpec(pFile->GetFileName(), W2CT(m_rgbstrMRUFilters[0]));
}


long CFileSystem::GetCommandCount()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::GetCommandCount \n") );

    return m_rgCommands.GetUpperBound() + 1;
}

CFileSystemCommand* CFileSystem::GetCommand(int nIndex)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::GetCommand \n") );

    _ASSERTE((nIndex >= 0) && (nIndex < GetCommandCount()));

    return (CFileSystemCommand*)m_rgCommands.GetAt(nIndex);
}

BOOL CFileSystem::AddCommand(CFileSystemCommand* pCommand, BOOL fSetDirty)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::AddCommand \n") );

    _ASSERTE(pCommand);
	if (!pCommand)
		return FALSE;

    m_rgCommands.Add(pCommand);
    if (fSetDirty)
        SetFileSystemOptionsDirty();

    return TRUE;
}

BOOL CFileSystem::RemoveCommand(CFileSystemCommand* pCommand)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::RemoveCommand \n") );

    _ASSERTE(pCommand);

    CFileSystemCommand* pCommandTest;
    int nCommands = m_rgCommands.GetUpperBound() + 1;

    for (int i = 0; i < nCommands; i++)
    {
        pCommandTest = (CFileSystemCommand*)m_rgCommands.GetAt(i);
        _ASSERTE(pCommandTest);

        if (pCommand == pCommandTest)
        {
            m_rgCommands.RemoveAt(i);
            delete pCommandTest;

            return TRUE;
        }
    }
    return FALSE;
}

void CFileSystem::RemoveAllCommands()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::RemoveAllCommands \n") );

    CFileSystemCommand* pCommand;
    int nCommands = m_rgCommands.GetUpperBound() + 1;

    for (int i = 0; i < nCommands; i++)
    {
        pCommand = (CFileSystemCommand*)m_rgCommands.GetAt(i);
        _ASSERTE(pCommand);

        delete pCommand;
    }
    m_rgCommands.RemoveAll();
}

void CFileSystem::SwapCommands(int nIndex1, int nIndex2)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::SwapCommands \n") );

    _ASSERTE((nIndex1 >= 0) && (nIndex1 < GetCommandCount()));
    _ASSERTE((nIndex2 >= 0) && (nIndex2 < GetCommandCount()));
    _ASSERTE(m_rgCommands.GetAt(nIndex1));
    _ASSERTE(m_rgCommands.GetAt(nIndex2));

    CFileSystemCommand* pTemp = (CFileSystemCommand*)m_rgCommands.GetAt(nIndex1);

    m_rgCommands.SetAt(nIndex1, m_rgCommands.GetAt(nIndex2));
    m_rgCommands.SetAt(nIndex2, pTemp);
}

BOOL CFileSystem::DefineCommands()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::DefineCommands \n") );

    CFileSystemCommandDlg dlg;

    dlg.DoModal();
    if (dlg.m_fChanged)
    {
        SetFileSystemOptionsDirty();
        return TRUE;
    }
    return FALSE;
}

void CFileSystem::ExecCommand(TCHAR* lpszCmd, CFileSystemFolderItem* pCurrentFolder)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::ExecCommand \n") );

    _ASSERTE(pCurrentFolder);
    _ASSERTE(lpszCmd && _tcslen(lpszCmd));
	if (!pCurrentFolder)
		return;
	if (!lpszCmd)
		return;

    CComPtr<ICommandExecuter> srpCmdExec;
    CString strCommand;
    CString strWorkingDir;
    HRESULT hr;

    USES_CONVERSION;

    pCurrentFolder->GetFolderPath(strWorkingDir);

    hr = _VxModule.QueryService(SID_SCommandExecuter, IID_ICommandExecuter, (void**)&srpCmdExec);
    IfFailGo(hr);

    if (lpszCmd[0] == L'=')
    {
        hr = srpCmdExec->ExecuteCommand(T2CW(lpszCmd+1), L"", T2CW((LPCTSTR)strWorkingDir),
                                        CMF_UseOutput | CMF_ClearOutput);
    }
    else
    {
        hr = srpCmdExec->ExecuteCommand(T2CW(lpszCmd), L"", T2CW((LPCTSTR)strWorkingDir), 0);
        _ASSERTE(SUCCEEDED(hr));
    }

OnError:
    ;
}


//*****************************************************************************
// CFileSystem Implementation
//*****************************************************************************

HKEY CFileSystem::GetOptionsRegRoot(BOOL fRead)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::GetOptionsRegRoot \n") );

    CRegKey keyRoot;

    if (fRead)
        keyRoot.Open(HKEY_CURRENT_USER, s_lpszOptionsRegRoot, KEY_READ);
    else
        keyRoot.Create(HKEY_CURRENT_USER, s_lpszOptionsRegRoot);

    return keyRoot.Detach();
}

HRESULT CFileSystem::LoadShortcuts(HKEY hkeyOptionsRoot)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::LoadShortcuts \n") );

    _ASSERTE(hkeyOptionsRoot);

	if (!hkeyOptionsRoot)
		return E_FAIL;

    CRegKey keyShortcuts;
    long nResult;
    HRESULT hr = E_FAIL;

    // open the Shortcuts key
    nResult = keyShortcuts.Open(hkeyOptionsRoot, s_lpszShortcutsKey, KEY_READ);
    if (nResult == ERROR_SUCCESS)
    {
        TCHAR szPath[_MAX_PATH];
        DWORD dwNumPaths;
        DWORD dwMaxPathLen;
        int i;

        // find out number of shortcuts saved
        nResult = RegQueryInfoKey(keyShortcuts, NULL, NULL, NULL, NULL, NULL, NULL,
                                  &dwNumPaths, &dwMaxPathLen, NULL, NULL, NULL);
        ExpectedExprGo((nResult == ERROR_SUCCESS) && (dwMaxPathLen < _MAX_PATH));

        // now loop through and add each shortcut to the array
        for (i = 0; i < (int)dwNumPaths; i++)
        {
            dwMaxPathLen = _MAX_PATH;
            nResult = RegEnumValue(keyShortcuts, i, szPath, &dwMaxPathLen, NULL,
                                   NULL, NULL, 0);
            ExpectedExprGo(nResult == ERROR_SUCCESS);

            if (dwMaxPathLen)
            {
                AddShortcut(szPath, FALSE);
            }
        }
        hr = S_OK;
    }

OnError:
    if (FAILED(hr))
    {
        SetFileSystemOptionsDirty();
        hr = S_OK;
    }
    return hr;
}

HRESULT CFileSystem::SaveShortcuts(HKEY hkeyOptionsRoot)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::SaveShortcuts \n") );

    _ASSERTE(hkeyOptionsRoot);

	if (!hkeyOptionsRoot)
		return E_FAIL;

    CRegKey keyShortcuts;
    long nResult;

    CFileSystemFolderItem* pFolder;
    int nShortcuts;
    int i;

    HRESULT hr = S_OK;

    // delete the shortcuts key, so all shortcuts in it go away
    keyShortcuts.Attach(hkeyOptionsRoot);
    keyShortcuts.DeleteSubKey(s_lpszShortcutsKey);
    keyShortcuts.Detach();

    // create the new Shortcuts key
    nResult = keyShortcuts.Create(hkeyOptionsRoot, s_lpszShortcutsKey);
    ExpectedExprGoMsg(nResult == ERROR_SUCCESS, "Failed to create Shortcuts key");

    nShortcuts = m_rgShortcuts.GetUpperBound() + 1;
    for (i = 0; i < nShortcuts; i++)
    {
        pFolder = (CFileSystemFolderItem*)m_rgShortcuts.GetAt(i);
        _ASSERTE(pFolder);

        keyShortcuts.SetStringValue(pFolder->GetFolderText(), _T(""));
    }

OnError:
    return hr;
}


HRESULT CFileSystem::LoadFilters(HKEY hkeyOptionsRoot)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::LoadFilters \n") );

    _ASSERTE(hkeyOptionsRoot);

	if (!hkeyOptionsRoot)
		return E_FAIL;

    USES_CONVERSION;

    CRegKey keyFilters;
    long nResult;
    HRESULT hr = E_FAIL;

    // open the Filters key
    nResult = keyFilters.Open(hkeyOptionsRoot, s_lpszFiltersKey, KEY_READ);
    if (nResult == ERROR_SUCCESS)
    {
        TCHAR szIndex[2];
        TCHAR szFilter[_MAX_PATH];
        DWORD dwFilterLen;
        DWORD dwAllFilters;
        int i;

        szIndex[1] = _T('\0');
        for (i = 0; i < MAX_MRU_FILTERS; i++)
        {
            szIndex[0] = _T('A') + i;
            szFilter[0] = _T('\0');
            dwFilterLen = _MAX_PATH;

            nResult = keyFilters.QueryStringValue(szIndex, szFilter, &dwFilterLen);
            if (nResult != ERROR_SUCCESS)
            {
                // no more filters
                break;
            }
            m_rgbstrMRUFilters[m_nMRUFilters] = SysAllocString(T2COLE(szFilter));
            IfFailAllocGo(m_rgbstrMRUFilters[m_nMRUFilters]);

            m_nMRUFilters++;
        }

        nResult = keyFilters.QueryDWORDValue(s_lpszAllFilterValue, dwAllFilters);
        if (nResult == ERROR_SUCCESS)
            m_fAllFilter = dwAllFilters ? TRUE : FALSE;
        else
        {
            m_fAllFilter = TRUE;
            SetFileSystemOptionsDirty();
        }
        hr = S_OK;
    }

    CreateFiltersSafeArray();

OnError:
    if (FAILED(hr))
    {
        SetFileSystemOptionsDirty();
        hr = S_OK;
    }
    return hr;
}

HRESULT CFileSystem::SaveFilters(HKEY hkeyOptionsRoot)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::SaveFilters \n") );

    _ASSERTE(hkeyOptionsRoot);

	if (!hkeyOptionsRoot)
		return E_FAIL;

    USES_CONVERSION;

    CRegKey keyFilters;
    TCHAR szIndex[2];
    long nResult;
    int i;
    HRESULT hr = S_OK;

    // delete the filters key, so all filters in it go away
    keyFilters.Attach(hkeyOptionsRoot);
    keyFilters.DeleteSubKey(s_lpszFiltersKey);
    keyFilters.Detach();

    // create the new Shortcuts key
    nResult = keyFilters.Create(hkeyOptionsRoot, s_lpszFiltersKey);
    ExpectedExprGoMsg(nResult == ERROR_SUCCESS, "Failed to create Filters key");

    szIndex[1] = _T('\0');
    for (i = 0; i < m_nMRUFilters; i++)
    {
        szIndex[0] = _T('A') + i;

        _ASSERTE(m_rgbstrMRUFilters[i]);
        keyFilters.SetStringValue(szIndex, W2CT(m_rgbstrMRUFilters[i]));
    }

    keyFilters.SetDWORDValue(s_lpszAllFilterValue, m_fAllFilter);

OnError:
    return hr;
}

HRESULT CFileSystem::CreateFiltersSafeArray()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::CreateFiltersSafeArray \n") );

    _ASSERTE(!m_psaFilters);

    SAFEARRAYBOUND saBound[1];

    saBound[0].cElements = m_nMRUFilters + 1;
    saBound[0].lLbound = 0;

    BSTR HUGEP* pbstr;
    HRESULT hr;
    int i;

    m_psaFilters = SafeArrayCreate(VT_BSTR, 1, saBound);
    IfFailAllocGo(m_psaFilters);

    hr = SafeArrayAccessData(m_psaFilters, (void HUGEP* FAR*)&pbstr);
    _ASSERTE(SUCCEEDED(hr));

    for (i = 0; i < m_nMRUFilters; i++)
    {
        _ASSERTE(m_rgbstrMRUFilters[i]);
        pbstr[i] = SysAllocString(m_rgbstrMRUFilters[i]);
    }
    pbstr[m_nMRUFilters] = SysAllocString(L"*.*");
    SafeArrayUnaccessData(m_psaFilters);
    hr = S_OK;

OnError:
    return hr;
}

HRESULT CFileSystem::FreeFiltersSafeArray()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::FreeFiltersSafeArray \n") );

    if (m_psaFilters)
    {
        SafeArrayDestroy(m_psaFilters);
        m_psaFilters = NULL;
    }
    return S_OK;
}

HRESULT CFileSystem::FreeFilters()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::FreeFilters \n") );

    FreeFiltersSafeArray();
    for (int i = 0; i < m_nMRUFilters; i++)
    {
        SysFreeString(m_rgbstrMRUFilters[i]);
        m_rgbstrMRUFilters[i] = NULL;
    }
    return S_OK;
}


HRESULT CFileSystem::LoadCommands(HKEY hkeyOptionsRoot)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::LoadCommands \n") );

    _ASSERTE(hkeyOptionsRoot);

	if (!hkeyOptionsRoot)
		return E_FAIL;

    CRegKey keyCommands;
    long nResult;
    HRESULT hr = E_FAIL;

    // open the Shortcuts key
    nResult = keyCommands.Open(hkeyOptionsRoot, s_lpszCommandsKey, KEY_READ);
    if (nResult == ERROR_SUCCESS)
    {
        DWORD dwNumCommands, dwLength;
        TCHAR szNameValue[128];
        TCHAR szCommandValue[128];
        TCHAR szArgsValue[128];
        TCHAR szFlagsValue[128];

        TCHAR szName[MAX_CMD_NAME];
        TCHAR szCommand[_MAX_PATH];
        TCHAR szArgs[_MAX_PATH];
        DWORD dwFlags;
        int i;

        // find out number of commands
        nResult = keyCommands.QueryDWORDValue(s_lpszCommandCountValue, dwNumCommands);
        ExpectedExprGo(nResult == ERROR_SUCCESS);

        for (i = 0; i < (int)dwNumCommands; i++)
        {
            CFileSystemCommand* pCommand = NULL;
            szName[0] = _T('\0');
            szCommand[0] = _T('\0');
            szArgs[0] = _T('\0');

            _sntprintf(szNameValue, NUMBER_OF(szNameValue), s_lpszCommandNameValue, i);
            _sntprintf(szCommandValue, NUMBER_OF(szCommandValue), s_lpszCommandCmdValue, i);
            _sntprintf(szArgsValue, NUMBER_OF(szArgsValue), s_lpszCommandArgsValue, i);
            _sntprintf(szFlagsValue, NUMBER_OF(szFlagsValue), s_lpszCommandFlagsValue, i);

            dwLength = MAX_CMD_NAME;
            nResult = keyCommands.QueryStringValue(szNameValue, szName, &dwLength);
            szName[MAX_CMD_NAME - 1] = _T('\0');
            if (nResult != ERROR_SUCCESS) { _ASSERTE(FALSE); continue; }

            dwLength = _MAX_PATH;
            nResult = keyCommands.QueryStringValue(szCommandValue, szCommand, &dwLength);
            szCommand[_MAX_PATH - 1] = _T('\0');
            if (nResult != ERROR_SUCCESS) { _ASSERTE(FALSE); continue; }

            dwLength = _MAX_PATH;
            nResult = keyCommands.QueryStringValue(szArgsValue, szArgs, &dwLength);
            szArgs[_MAX_PATH - 1] = _T('\0');
            if (nResult != ERROR_SUCCESS) { _ASSERTE(FALSE); continue; }

            nResult = keyCommands.QueryDWORDValue(szFlagsValue, dwFlags);
            if (nResult != ERROR_SUCCESS) { _ASSERTE(FALSE); continue; }

            pCommand = new CFileSystemCommand();
            if (pCommand == NULL)
            {
                hr = E_OUTOFMEMORY;
                goto OnError;
            }
            hr = pCommand->InitCommand(szName, szCommand, szArgs, dwFlags);
            if (SUCCEEDED(hr))
                AddCommand(pCommand, FALSE);
            else
            {
                delete pCommand;
                pCommand = NULL;
            }
        }
        hr = S_OK;
    }

OnError:
    if (FAILED(hr))
    {
        SetFileSystemOptionsDirty();
        hr = S_OK;
    }
    return hr;
}

HRESULT CFileSystem::SaveCommands(HKEY hkeyOptionsRoot)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::SaveCommands \n") );

    _ASSERTE(hkeyOptionsRoot);

	if (!hkeyOptionsRoot)
		return E_FAIL;

    CRegKey keyCommands;
    long nResult;

    TCHAR szNameValue[128];
    TCHAR szCommandValue[128];
    TCHAR szArgsValue[128];
    TCHAR szFlagsValue[128];

    CFileSystemCommand* pCommand;
    int nCommands;
    int i;

    HRESULT hr = S_OK;

    // delete the shortcuts key, so all shortcuts in it go away
    keyCommands.Attach(hkeyOptionsRoot);
    keyCommands.DeleteSubKey(s_lpszCommandsKey);
    keyCommands.Detach();

    // create the new Shortcuts key
    nResult = keyCommands.Create(hkeyOptionsRoot, s_lpszCommandsKey);
    ExpectedExprGoMsg(nResult == ERROR_SUCCESS, "Failed to create Commands key");

    nCommands = m_rgCommands.GetUpperBound() + 1;
    nResult = keyCommands.SetDWORDValue(s_lpszCommandCountValue, nCommands);
    ExpectedExprGoMsg(nResult == ERROR_SUCCESS, "Failed to set command count value");

    for (i = 0; i < nCommands; i++)
    {
        pCommand = (CFileSystemCommand*)m_rgCommands.GetAt(i);
        _ASSERTE(pCommand);

        _sntprintf(szNameValue, NUMBER_OF(szNameValue), s_lpszCommandNameValue, i);
        _sntprintf(szCommandValue, NUMBER_OF(szCommandValue), s_lpszCommandCmdValue, i);
        _sntprintf(szArgsValue, NUMBER_OF(szArgsValue), s_lpszCommandArgsValue, i);
        _sntprintf(szFlagsValue, NUMBER_OF(szFlagsValue), s_lpszCommandFlagsValue, i);

        nResult = keyCommands.SetStringValue(szNameValue, pCommand->GetCommandName());
        if (nResult != ERROR_SUCCESS) { _ASSERTE(FALSE); continue; }

        nResult = keyCommands.SetStringValue(szCommandValue, pCommand->GetCommandCommand());
        if (nResult != ERROR_SUCCESS) { _ASSERTE(FALSE); continue; }

        nResult = keyCommands.SetStringValue(szArgsValue, pCommand->GetCommandArgs());
        if (nResult != ERROR_SUCCESS) { _ASSERTE(FALSE); continue; }

        nResult = keyCommands.SetDWORDValue(szFlagsValue, pCommand->GetCommandFlags());
        if (nResult != ERROR_SUCCESS) { _ASSERTE(FALSE); continue; }
    }

    hr = S_OK;

OnError:
    return hr;
}


HRESULT CFileSystem::LoadDrives()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::LoadDrives \n") );

    TCHAR szDrive[] = _T("?:");
    TCHAR szDrivePath[] = _T("?:\\");
    DWORD dwAttr;
    int nDriveType;
    int nDrives = 0;
    DWORD dwDriveList = GetLogicalDrives();

    while (dwDriveList)
    {
        if (dwDriveList & 1)
        {
            CFileSystemFolderItem* pDrive = NULL;
            szDrive[0] = _T('A') + nDrives;
            szDrivePath[0] = _T('A') + nDrives;

            pDrive = CFileSystemFolderItem::CreateFolderItem();
            if (!pDrive)
                break;

            nDriveType = GetDriveType(szDrivePath);
            switch (nDriveType)
            {
                case DRIVE_FIXED:
                    nDriveType = CFileSystemFolderItem::fsdFixed;
                    break;
                case DRIVE_REMOVABLE:
                    nDriveType = CFileSystemFolderItem::fsdFloppy;
                    break;
                case DRIVE_CDROM:
                    nDriveType = CFileSystemFolderItem::fsdCDROM;
                    break;
                case DRIVE_REMOTE:
                    nDriveType = CFileSystemFolderItem::fsdNetwork;
                    break;
                default:
                    nDriveType = CFileSystemFolderItem::fsdUnknown;
                    break;
            }

            dwAttr = GetFileAttributes(szDrivePath);
            if (dwAttr == 0xFFFFFFFF)
            {
                // could be removable drive
                dwAttr = 0;
            }
            else
                _ASSERTE(dwAttr & FILE_ATTRIBUTE_DIRECTORY);

            pDrive->InitDriveFolder(szDrive, nDriveType,
                                    ((dwAttr & FILE_ATTRIBUTE_READONLY) != 0),
                                    FALSE,
                                    ((dwAttr & FILE_ATTRIBUTE_COMPRESSED) != 0));
            m_rgDrives.Add(pDrive);
        }
        dwDriveList >>= 1;
        nDrives++;
    }

    return S_OK;
}

void CFileSystem::RemoveAllDrives()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystem::RemoveAllDrives \n") );

    CFileSystemFolderItem* pDrive;
    int nDrives = m_rgDrives.GetUpperBound() + 1;

    for (int i = 0; i < nDrives; i++)
    {
        pDrive = (CFileSystemFolderItem*)m_rgDrives.GetAt(i);
        _ASSERTE(pDrive);

        CFileSystemFolderItem::FreeFolderItem(pDrive);
    }

    m_rgDrives.RemoveAll();
}
