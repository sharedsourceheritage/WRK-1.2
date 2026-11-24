
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FileSys.h
//
// Declaration of CFileSystem and related stuff
//
//*****************************************************************************

#pragma once

#define MAX_CACHED_FOLDERS      10
#define MAX_MRU_FILTERS         16

//*****************************************************************************
// CFileSystem
//*****************************************************************************

class CFileSystem
{
// Constructor/Destructor
public:
    CFileSystem();
    ~CFileSystem();

// Operations
public:
    HRESULT Initialize();
    HRESULT Close();

    long GetShortcutCount();
    CFileSystemFolderItem* GetShortcut(int nIndex);
    CFileSystemFolderItem* AddShortcut(LPCTSTR lpszPath, BOOL fSetDirty = TRUE);
    BOOL RemoveShortcut(CFileSystemFolderItem* pShortcut);
    void RemoveAllShortcuts(BOOL fSetDirty = TRUE);

    long GetDriveCount();
    CFileSystemFolderItem* GetDrive(int nIndex);

    CFileSystemCachedFolder* GetFolderFiles(CFileSystemFolderItem* pFolder);
    void FreeFolderFiles(CFileSystemCachedFolder* pCachedFolder);

    HRESULT ExecFilterHandler(VARIANT* pvarOut);
    HRESULT ExecGetCurrentFilter(VARIANT* pvarOut);
    HRESULT ExecSetCurrentFilter(VARIANT* pvarIn);
    BOOL FilterFile(CFileSystemFileItem* pFile);
    BOOL IsFilterEnabled() 
	{ 
		return !m_fAllFilter && m_nMRUFilters && m_rgbstrMRUFilters[0]; 
	}

    long GetCommandCount();
    CFileSystemCommand* GetCommand(int nIndex);
    BOOL AddCommand(CFileSystemCommand* pCommand, BOOL fSetDirty = TRUE);
    BOOL RemoveCommand(CFileSystemCommand* pCommand);
    void RemoveAllCommands();
    void SwapCommands(int nIndex1, int nIndex2);
    BOOL DefineCommands();
    void ExecCommand(TCHAR* lpszCmd, CFileSystemFolderItem* pCurrentFolder);

    void SetFileSystemOptionsDirty()  
	{ 
		m_fOptionsDirty = TRUE; 
	}

// Implementation
protected:
    HKEY GetOptionsRegRoot(BOOL fRead);

    HRESULT LoadShortcuts(HKEY hkeyOptionsRoot);
    HRESULT SaveShortcuts(HKEY hkeyOptionsRoot);

    HRESULT LoadFilters(HKEY hkeyOptionsRoot);
    HRESULT SaveFilters(HKEY hkeyOptionsRoot);
    HRESULT CreateFiltersSafeArray();
    HRESULT FreeFiltersSafeArray();
    HRESULT FreeFilters();

    HRESULT LoadCommands(HKEY hkeyOptionsRoot);
    HRESULT SaveCommands(HKEY hkeyOptionsRoot);

    HRESULT LoadDrives();
    void RemoveAllDrives();

// Attributes
protected:
    CPtrArray m_rgShortcuts;
    CPtrArray m_rgDrives;

    CFileSystemCachedFolder m_rgCachedFolders[MAX_CACHED_FOLDERS];

    long m_nMRUFilters;
    SAFEARRAY* m_psaFilters;
    BSTR m_rgbstrMRUFilters[MAX_MRU_FILTERS];
    BOOL m_fAllFilter;

    CPtrArray m_rgCommands;

    BOOL m_fOptionsDirty;
    BOOL m_fInitialized;
    BOOL m_fClosed;

};
