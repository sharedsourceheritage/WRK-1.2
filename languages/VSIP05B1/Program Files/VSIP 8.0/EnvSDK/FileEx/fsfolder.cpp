
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSFolder.cpp
//
// Implementation of CFileSystemFolderItem
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"

CPtrArray CFileSystemFolderItem::s_rgFolderPool;

//*****************************************************************************
// CFileSystemFolderItem Constructor/Destructor
//*****************************************************************************

CFileSystemFolderItem::CFileSystemFolderItem()
{
    m_nType = 0;
    m_nDriveType = 0;
    m_pParentItem = NULL;
    m_htiNode = NULL;
    m_fHierarchyDirty = TRUE;
    m_prgHierarchyItems = NULL;
    m_fReadOnly = FALSE;
    m_fHidden = FALSE;
    m_fCompressed = FALSE;

#ifdef _DEBUG
    m_fReset = TRUE;
#endif // _DEBUG
}

CFileSystemFolderItem::~CFileSystemFolderItem()
{
    if (m_prgHierarchyItems)
    {
        FreeHierarchyItems();
        delete m_prgHierarchyItems;
    }
}


//*****************************************************************************
// CFileSystemFolderItem Operations
//*****************************************************************************

void CFileSystemFolderItem::InitFolderPool()
{
    s_rgFolderPool.SetSize(0, 5);
}

void CFileSystemFolderItem::CloseFolderPool()
{
    CFileSystemFolderItem* pFolder;
    long nCount = s_rgFolderPool.GetUpperBound() + 1;

    for (long i = 0; i < nCount; i++)
    {
        pFolder = (CFileSystemFolderItem*)s_rgFolderPool.GetAt(i);
        _ASSERTE(pFolder);

        delete pFolder;
    }
    s_rgFolderPool.RemoveAll();
}

CFileSystemFolderItem* CFileSystemFolderItem::CreateFolderItem()
{
    CFileSystemFolderItem* pFolder = NULL;
    long nCount = s_rgFolderPool.GetUpperBound() + 1;

    if (nCount > 0)
    {
        pFolder = (CFileSystemFolderItem*)s_rgFolderPool.GetAt(nCount - 1);
        _ASSERTE(pFolder);

        s_rgFolderPool.RemoveAt(nCount - 1);
    }
    else
    {
        pFolder = new CFileSystemFolderItem();
    }

    return pFolder;
}

void CFileSystemFolderItem::FreeFolderItem(CFileSystemFolderItem* pFolder)
{
    _ASSERTE(pFolder);

	if (pFolder)
	{
		pFolder->Reset();
		s_rgFolderPool.Add(pFolder);
	}
}


void CFileSystemFolderItem::InitShortcutFolder(LPCTSTR lpszPath,
                                               BOOL fReadOnly, BOOL fHidden,
                                               BOOL fCompressed)
{
    _ASSERTE(m_fReset == TRUE);
    _ASSERTE(lpszPath);

    m_nType = fsiShortcut;
    m_strText = lpszPath;
    m_fReadOnly = fReadOnly;
    m_fHidden = fHidden;
    m_fCompressed = fCompressed;

#ifdef _DEBUG
    m_fReset = FALSE;
#endif // _DEBUG
}

void CFileSystemFolderItem::InitDriveFolder(LPCTSTR lpszDrive, int nDriveType,
                                            BOOL fReadOnly, BOOL fHidden,
                                            BOOL fCompressed)
{
    _ASSERTE(m_fReset == TRUE);
    _ASSERTE(lpszDrive);

    m_nType = fsiDrive;
    m_strText = lpszDrive;
    m_nDriveType = nDriveType;
    m_fReadOnly = fReadOnly;
    m_fHidden = fHidden;
    m_fCompressed = fCompressed;

#ifdef _DEBUG
    m_fReset = FALSE;
#endif // _DEBUG
}

void CFileSystemFolderItem::InitFolder(CFileSystemFolderItem* pParent,
                                       LPCTSTR lpszText,
                                       BOOL fReadOnly, BOOL fHidden,
                                       BOOL fCompressed)
{
    _ASSERTE(m_fReset == TRUE);
    _ASSERTE(pParent);
    _ASSERTE(lpszText);

    if (pParent && pParent->GetFolderType() == fsiShortcut)
        m_nType = fsiShortcutSubFolder;
    else
        m_nType = fsiFolder;

    m_strText = lpszText;
    m_pParentItem = pParent;
    m_fReadOnly = fReadOnly;
    m_fHidden = fHidden;
    m_fCompressed = fCompressed;

#ifdef _DEBUG
    m_fReset = FALSE;
#endif // _DEBUG
}

void CFileSystemFolderItem::GetFolderPath(CString& strPath)
{
    _ASSERTE(!m_fReset);

    switch (m_nType)
    {
        case fsiDrive:
        case fsiShortcut:
            strPath = m_strText;
            break;
        case fsiFolder:
        case fsiShortcutSubFolder:
            _ASSERTE(m_pParentItem);
            m_pParentItem->InternalGetFolderPath(strPath, m_strText.GetLength() + 1);

            ///strPath.Append(_T("\\"));
            ///strPath.Append(m_strText);
            strPath+=(_T("\\"));
            strPath+=(m_strText);
            			
			break;
    }
}

int CFileSystemFolderItem::ComparePath(CFileSystemFolderItem* pFolder)
{
    _ASSERTE(pFolder);
	if (!pFolder)
		return -1;

    CString strPathThis;
    CString strPath;

    GetFolderPath(strPathThis);
    pFolder->GetFolderPath(strPath);

    return _tcsicmp(strPathThis, strPath);
}

BOOL CFileSystemFolderItem::IsUNCFolder()
{
    return (m_pParentItem == NULL) && (m_strText.GetLength() > 2) &&
            (m_strText.GetAt(0) == _T('\\')) &&
            (m_strText.GetAt(1) == _T('\\'));
}


void CFileSystemFolderItem::EnsureHierarchy()
{
    if (m_fHierarchyDirty)
    {
        if (m_prgHierarchyItems)
        {
            // free existing items if any
            FreeHierarchyItems();
        }
        else
        {
            // create the hierarchy items array now
            m_prgHierarchyItems = new CPtrArray();
            m_prgHierarchyItems->SetSize(0, 2);
        }

        // now enumerate and fill in the hierarchy
        CString strSearch;
        WIN32_FIND_DATA fd;
        HANDLE hFind;
        BOOL fItemFound;

        GetFolderPath(strSearch);

        ///strSearch.Append(_T("\\*."));
        strSearch+=(_T("\\*."));

        fItemFound = TRUE;
        hFind = FindFirstFile(strSearch, &fd);
        while ((hFind != INVALID_HANDLE_VALUE) && fItemFound)
        {
            // leave out the '.' and '..' and files without extensions
            if ((fd.cFileName[0] != _T('.')) &&
                (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                CFileSystemFolderItem* pHierItem;

                pHierItem = CFileSystemFolderItem::CreateFolderItem();
                if (!pHierItem)
                    break;

                pHierItem->InitFolder(this, fd.cFileName,
                                      ((fd.dwFileAttributes & FILE_ATTRIBUTE_READONLY) != 0),
                                      ((fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) != 0),
                                      ((fd.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED) != 0));
                m_prgHierarchyItems->Add(pHierItem);
            }
            fItemFound = FindNextFile(hFind, &fd);
        }
        FindClose(hFind);

        // mark the hierarchy clean
        m_fHierarchyDirty = FALSE;
    }
}

BOOL CFileSystemFolderItem::Refresh(BOOL fNow)
{
    CString strPath;
    BOOL fExists = TRUE;

    GetFolderPath(strPath);
    if (GetFileAttributes(strPath) == 0xFFFFFFFF)
        fExists = FALSE;

    if (fExists)
    {
        RefreshHierarchy(fNow);
    }
    else
    {
        if ((m_nType == fsiShortcutSubFolder) || (m_nType == fsiFolder))
        {
            _ASSERTE(m_pParentItem);

            m_pParentItem->RemoveHierarchyItem(this);
        }
        else if (m_nType == fsiShortcut)
        {
            g_FileSys.RemoveShortcut(this);
        }
    }

    return fExists;
}

void CFileSystemFolderItem::RefreshHierarchy(BOOL fNow)
{
    m_fHierarchyDirty = TRUE;
    if (fNow)
    {
        EnsureHierarchy();
    }
}

int CFileSystemFolderItem::GetHierarchyItemCount()
{
    EnsureHierarchy();
    return m_prgHierarchyItems ? (m_prgHierarchyItems->GetUpperBound() + 1) : 0;
}

CFileSystemFolderItem* CFileSystemFolderItem::GetHierarchyItem(int nIndex)
{
    _ASSERTE(m_fHierarchyDirty == FALSE);
    _ASSERTE((nIndex >= 0) && (nIndex < GetHierarchyItemCount()));

    return (CFileSystemFolderItem*)m_prgHierarchyItems->GetAt(nIndex);
}


//*****************************************************************************
// CFileSystemFolderItem Implementation
//*****************************************************************************

void CFileSystemFolderItem::Reset()
{
    m_nType = 0;
    m_nDriveType = 0;
    m_pParentItem = NULL;
    m_strText.Empty();
    m_htiNode = NULL;
    FreeHierarchyItems();
    m_fHierarchyDirty = TRUE;
    m_fReadOnly = FALSE;
    m_fHidden = FALSE;
    m_fCompressed = FALSE;

#ifdef _DEBUG
    m_fReset = TRUE;
#endif // _DEBUG
}

void CFileSystemFolderItem::FreeHierarchyItems()
{
    if (m_prgHierarchyItems)
    {
        int nHierItems = m_prgHierarchyItems->GetUpperBound() + 1;
        CFileSystemFolderItem* pHierItem;

        for (int i = 0; i < nHierItems; i++)
        {
            pHierItem = (CFileSystemFolderItem*)m_prgHierarchyItems->GetAt(i);
            _ASSERTE(pHierItem);

            CFileSystemFolderItem::FreeFolderItem(pHierItem);
        }
        m_prgHierarchyItems->RemoveAll();
    }
}

void CFileSystemFolderItem::InternalGetFolderPath(CString& strPath, int nPostLength)
{
    _ASSERTE(!m_fReset);

    switch (m_nType)
    {
        case fsiDrive:
        case fsiShortcut:
            strPath.GetBufferSetLength(nPostLength + m_strText.GetLength());
            strPath = m_strText;
            break;
        case fsiFolder:
        case fsiShortcutSubFolder:
            _ASSERTE(m_pParentItem);
            m_pParentItem->InternalGetFolderPath(strPath, nPostLength + m_strText.GetLength() + 1);

            ///strPath.Append(_T("\\"));
            ///strPath.Append(m_strText);
            strPath+=(_T("\\"));
            strPath+=(m_strText);

			break;
    }
}

void CFileSystemFolderItem::RemoveHierarchyItem(CFileSystemFolderItem* pHierItem)
{
    _ASSERTE(pHierItem);
    _ASSERTE(m_prgHierarchyItems);

    int nHierItems = m_prgHierarchyItems->GetUpperBound() + 1;
    CFileSystemFolderItem* pTemp;

    for (int i = 0; i < nHierItems; i++)
    {
        pTemp = (CFileSystemFolderItem*)m_prgHierarchyItems->GetAt(i);
        _ASSERTE(pTemp);

        if (pTemp == pHierItem)
        {
            CFileSystemFolderItem::FreeFolderItem(pHierItem);
            m_prgHierarchyItems->RemoveAt(i);
            return;
        }
    }
}
