
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSCachedFolder.cpp
//
// Implementation of CFileSystemCachedFolder
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"

//*****************************************************************************
// CFileSystemCachedFolder Constructor/Destructor
//*****************************************************************************

CFileSystemCachedFolder::CFileSystemCachedFolder()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemCachedFolder::CFileSystemCachedFolder \n") );

    m_pParentItem = NULL;
    m_fInUse = FALSE;
    m_fReset = TRUE;

    m_rgFiles.SetSize(0, 10);
}

CFileSystemCachedFolder::~CFileSystemCachedFolder()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemCachedFolder::~CFileSystemCachedFolder \n") );

    _ASSERTE(m_rgFiles.GetUpperBound() < 0);
}


//*****************************************************************************
// CFileSystemCachedFolder Operations
//*****************************************************************************

void CFileSystemCachedFolder::InitFolder(CFileSystemFolderItem* pFolder)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemCachedFolder::InitFolder \n") );

    _ASSERTE(pFolder);
    _ASSERTE(m_fReset == TRUE);

    m_pParentItem = pFolder;
    m_fReset = FALSE;

    RefreshFolder();
}

void CFileSystemCachedFolder::RefreshFolder()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemCachedFolder::RefreshFolder \n") );

    _ASSERTE(m_fReset == FALSE);
    _ASSERTE(m_pParentItem);

    RemoveAllFiles();

    CString strSearch;
    WIN32_FIND_DATA fd;
    HANDLE hFind;
    BOOL fItemFound;

    m_pParentItem->GetFolderPath(strSearch);
	
    ///strSearch.Append(_T("\\*.*"));
	strSearch += _T("\\*.*");

    fItemFound = TRUE;
    hFind = FindFirstFile(strSearch, &fd);
    while ((hFind != INVALID_HANDLE_VALUE) && fItemFound)
    {
        // leave out the '.' and '..' and folders
        if ((fd.cFileName[0] != _T('.')) &&
            !(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            CFileSystemFileItem* pFile;

            pFile = CFileSystemFileItem::CreateFileItem();
            if (!pFile)
                break;

            ULARGE_INTEGER uiSize;
            DWORD dwSize;
            short nSizeType = CFileSystemFileItem::sizeBytes;

            uiSize.LowPart = fd.nFileSizeLow;
            uiSize.HighPart = fd.nFileSizeHigh;

            if (uiSize.QuadPart > 1024)
            {
                uiSize.QuadPart >>= 10;
                nSizeType = CFileSystemFileItem::sizeKB;
                if (uiSize.QuadPart > 1024)
                {
                    uiSize.QuadPart >>= 10;
                    nSizeType = CFileSystemFileItem::sizeMB;
                    if (uiSize.QuadPart > 1024)
                    {
                        uiSize.QuadPart >>= 10;
                        nSizeType = CFileSystemFileItem::sizeGB;
                    }
                }
            }
            dwSize = (DWORD)uiSize.LowPart;

            pFile->InitFile(m_pParentItem, fd.cFileName,
                            ((fd.dwFileAttributes & FILE_ATTRIBUTE_READONLY) != 0),
                            ((fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) != 0),
                            ((fd.dwFileAttributes & FILE_ATTRIBUTE_COMPRESSED) != 0),
                            dwSize, nSizeType);
            m_rgFiles.Add(pFile);
        }
        fItemFound = FindNextFile(hFind, &fd);
    }
    FindClose(hFind);
}

void CFileSystemCachedFolder::Reset()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemCachedFolder::Reset \n") );

    m_pParentItem = NULL;
    m_fInUse = FALSE;
    RemoveAllFiles();
    m_fReset = TRUE;
}

long CFileSystemCachedFolder::GetFileCount()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemCachedFolder::GetFileCount \n") );

    _ASSERTE(!m_fReset);
    _ASSERTE(m_fInUse);

    return m_rgFiles.GetUpperBound() + 1;
}

CFileSystemFileItem* CFileSystemCachedFolder::GetFile(int nIndex)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemCachedFolder::GetFile \n") );

    _ASSERTE((nIndex >= 0) && (nIndex < GetFileCount()));

    return (CFileSystemFileItem*)m_rgFiles.GetAt(nIndex);
}


//*****************************************************************************
// CFileSystemCachedFolder Implementation
//*****************************************************************************

void CFileSystemCachedFolder::RemoveAllFiles()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CFileSystemCachedFolder::RemoveAllFiles \n") );

    CFileSystemFileItem* pFile;
    int nFiles = m_rgFiles.GetUpperBound() + 1;

    for (int i = 0; i < nFiles; i++)
    {
        pFile = (CFileSystemFileItem*)m_rgFiles.GetAt(i);
        _ASSERTE(pFile);

        CFileSystemFileItem::FreeFileItem(pFile);
    }

    m_rgFiles.RemoveAll();
}
