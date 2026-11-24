
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSExtMgr.cpp
//
// Implementation of CFileSystemExtensionManager
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"

CFileSystemExtensionManager g_ExtMgr;

//*****************************************************************************
// CFileSystemExtensionManager Constructor/Destructor
//*****************************************************************************

CFileSystemExtensionManager::CFileSystemExtensionManager()
{
    m_pDefaultExt = NULL;
    m_fExtensionsInitialized = FALSE;
    m_fExtensionsFreed = FALSE;

}

CFileSystemExtensionManager::~CFileSystemExtensionManager()
{
    m_pDefaultExt = NULL;
    m_fExtensionsInitialized = FALSE;
    m_fExtensionsFreed = FALSE;
}


//*****************************************************************************
// CFileSystemExtensionManager Operations
//*****************************************************************************

int CFileSystemExtensionManager::GetExtensionIconIndex(CFileSystemFileItem* pFile)
{
    _ASSERTE(pFile);
    if (!pFile)
        return 0;

    CFileSystemExtension* pExtension = NULL;
    LPCTSTR lpszExtension = pFile->GetFileExtension();

    _ASSERTE(lpszExtension);
    if (_tcslen(lpszExtension))
    {
        CString strExtension(lpszExtension);
        BOOL fExists;

        strExtension.MakeUpper();
        fExists = m_mapExtensions.Lookup(strExtension, (void*&)pExtension);
        if (fExists)
        {
            _ASSERTE(pExtension);
        }
        else
        {
            pExtension = LookupExtension(strExtension);
        }
    }

    if (pExtension == NULL)
        pExtension = m_pDefaultExt;

    return pExtension->nIcon;
}

LPCTSTR CFileSystemExtensionManager::GetExtensionDescription(CFileSystemFileItem* pFile)
{
    _ASSERTE(pFile);
    if (!pFile)
        return m_pDefaultExt->szDescription;

    CFileSystemExtension* pExtension = NULL;
    LPCTSTR lpszExtension = pFile->GetFileExtension();

    _ASSERTE(lpszExtension);
    if (_tcslen(lpszExtension))
    {
        CString strExtension(lpszExtension);
        BOOL fExists;

        strExtension.MakeUpper();
        fExists = m_mapExtensions.Lookup(strExtension, (void*&)pExtension);
        if (fExists)
        {
            _ASSERTE(pExtension);
        }
        else
        {
            pExtension = LookupExtension(strExtension);
        }
    }

    if (pExtension == NULL)
        pExtension = m_pDefaultExt;

    return pExtension->szDescription;
}


//*****************************************************************************
// CFileSystemExtensionManager Implementation
//*****************************************************************************

void CFileSystemExtensionManager::InitExtensions()
{
    if (m_fExtensionsInitialized)
        return;
    m_fExtensionsInitialized = TRUE;

    CString strDescription;

    strDescription.LoadString(IDS_FILESYS_FILE_APP);
    AddExtension(_T("EXE"), ILI_ILFILES_APP, strDescription);

    strDescription.LoadString(IDS_FILESYS_FILE_FILE);
    m_pDefaultExt = AddExtension(_T("*"), ILI_ILFILES_UNKNOWN, strDescription);

}

void CFileSystemExtensionManager::FreeExtensions()
{
    if (m_fExtensionsFreed)
        return;
    m_fExtensionsFreed = TRUE;

    POSITION pos;
    CFileSystemExtension* pExtension;
    CString strExtension;
    int i = 0;

    for (pos = m_mapExtensions.GetStartPosition(); pos != NULL;)
    {
        m_mapExtensions.GetNextAssoc(pos, strExtension, (void*&)pExtension);
        _ASSERTE(pExtension);

        delete pExtension;
    }

    m_mapExtensions.RemoveAll();

    if (m_himlExt)
    {
        ImageList_Destroy(m_himlExt);
        m_himlExt = NULL;
    }

}

CFileSystemExtension* CFileSystemExtensionManager::LookupExtension(LPCTSTR lpszExtension)
{
    _ASSERTE(lpszExtension && _tcslen(lpszExtension));
    if (!lpszExtension)
        return NULL;

    CFileSystemExtension* pExtension = NULL;
    CString strPath;
    SHFILEINFO sfi;
    DWORD_PTR nResult;

    strPath.GetBufferSetLength(1 + lstrlen(lpszExtension));
    strPath.Format(_T("%s%s"), _T("."), lpszExtension);

    nResult = SHGetFileInfo(strPath, 0, &sfi, sizeof(SHFILEINFO),
                            SHGFI_USEFILEATTRIBUTES | SHGFI_TYPENAME | SHGFI_ICON | SHGFI_SMALLICON);

    if (nResult)
    {
        _ASSERTE(sfi.hIcon);

        int nIcon;

        EnsureImageList();

        nIcon = ImageList_AddIcon(m_himlExt, sfi.hIcon);
        DestroyIcon(sfi.hIcon);
        pExtension = AddExtension(lpszExtension, nIcon, sfi.szTypeName);
    }

    return pExtension;
}

CFileSystemExtension* CFileSystemExtensionManager::AddExtension(LPCTSTR lpszExtension,
                                                                int nIcon,
                                                                LPCTSTR lpszDescription)
{
    CFileSystemExtension* pExtension = new CFileSystemExtension();
    if (pExtension == NULL)
        return NULL;

    pExtension->nIcon = nIcon;
    pExtension->szDescription[0] = _T('\0');
    int cchDescription = sizeof(pExtension->szDescription)/sizeof((pExtension->szDescription)[0]);
    if (lpszDescription)
    {
        _tcsncpy(pExtension->szDescription, lpszDescription, cchDescription - 1);
        pExtension->szDescription[cchDescription - 1] = _T('\0');
    }
    if (lpszExtension && (pExtension->szDescription[0] == _T('\0')))
    {
        _sntprintf(pExtension->szDescription, cchDescription - 1, _T("%s File"), lpszExtension);
        pExtension->szDescription[cchDescription - 1] = _T('\0');
    }

    m_mapExtensions.SetAt(lpszExtension, pExtension);
    return pExtension;
}

void CFileSystemExtensionManager::EnsureImageList()
{
    if (m_himlExt)
        return;

    m_himlExt = ImageList_LoadBitmap(_AtlBaseModule.GetResourceInstance(),
                                     MAKEINTRESOURCE(IDB_ILFILES),
                                     16, 4, RGB(0, 128, 128));
}
