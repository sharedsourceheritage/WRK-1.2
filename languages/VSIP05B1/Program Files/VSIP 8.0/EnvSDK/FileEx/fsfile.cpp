
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSFile.cpp
//
// Implementation of CFileSystemFileItem
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"

CPtrArray CFileSystemFileItem::s_rgFilePool;

//*****************************************************************************
// CFileSystemFileItem Constructor/Destructor
//*****************************************************************************

CFileSystemFileItem::CFileSystemFileItem()
{
    m_pParentItem = NULL;
    m_lpszExt = NULL;
    m_fReadOnly = FALSE;
    m_fHidden = FALSE;
    m_fCompressed = FALSE;
    m_dwSize = 0;
    m_nSizeType = sizeBytes;

#ifdef _DEBUG
    m_fReset = TRUE;
#endif // _DEBUG
}

CFileSystemFileItem::~CFileSystemFileItem()
{
}


//*****************************************************************************
// CFileSystemFileItem Operations
//*****************************************************************************

void CFileSystemFileItem::InitFilePool()
{
    s_rgFilePool.SetSize(0, 10);
}

void CFileSystemFileItem::CloseFilePool()
{
    CFileSystemFileItem* pFile;
    long nCount = s_rgFilePool.GetUpperBound() + 1;

    for (long i = 0; i < nCount; i++)
    {
        pFile = (CFileSystemFileItem*)s_rgFilePool.GetAt(i);
        _ASSERTE(pFile);

        delete pFile;
    }
    s_rgFilePool.RemoveAll();
}

CFileSystemFileItem* CFileSystemFileItem::CreateFileItem()
{
    CFileSystemFileItem* pFile = NULL;
    long nCount = s_rgFilePool.GetUpperBound() + 1;

    if (nCount > 0)
    {
        pFile = (CFileSystemFileItem*)s_rgFilePool.GetAt(nCount - 1);
        _ASSERTE(pFile);

        s_rgFilePool.RemoveAt(nCount - 1);
    }
    else
    {
        pFile = new CFileSystemFileItem();
    }

    return pFile;
}

void CFileSystemFileItem::FreeFileItem(CFileSystemFileItem* pFile)
{
    _ASSERTE(pFile);

	if (pFile)
	{
		pFile->Reset();
		s_rgFilePool.Add(pFile);
	}
}


void CFileSystemFileItem::InitFile(CFileSystemFolderItem* pParent,
                                   LPCTSTR lpszName,
                                   BOOL fReadOnly, BOOL fHidden,
                                   BOOL fCompressed,
                                   DWORD dwSize, short nSizeType)
{
    _ASSERTE(m_fReset == TRUE);
    _ASSERTE(pParent);
    _ASSERTE(lpszName);

    int nExtIndex;

    m_strName = lpszName;

    nExtIndex = m_strName.ReverseFind(_T('.'));
    if (nExtIndex == -1)
        m_lpszExt = (LPCTSTR)m_strName + m_strName.GetLength();
    else
        m_lpszExt = (LPCTSTR)m_strName + nExtIndex + 1;

    m_pParentItem = pParent;
    m_fReadOnly = fReadOnly;
    m_fHidden = fHidden;
    m_fCompressed = fCompressed;

    m_dwSize = dwSize;
    m_nSizeType = nSizeType;

#ifdef _DEBUG
    m_fReset = FALSE;
#endif // _DEBUG
}

void CFileSystemFileItem::GetFilePath(CString& strPath)
{
    _ASSERTE(!m_fReset);
    _ASSERTE(m_pParentItem);

    m_pParentItem->GetFolderPath(strPath);

	///strPath.Append(_T("\\"));
    ///strPath.Append(m_strName);
	strPath+=(_T("\\"));
    strPath+=(m_strName);

}

int CFileSystemFileItem::CompareFile(CFileSystemFileItem* pFile, BOOL fExtension)
{
    _ASSERTE(pFile);

	if (!pFile)
		return -1;

    int nCompare = 0;

    if (fExtension)
        nCompare = _tcsicmp(m_lpszExt, pFile->GetFileExtension());
    if (nCompare == 0)
        nCompare = _tcsicmp(m_strName, pFile->GetFileName());

    return nCompare;
}


//*****************************************************************************
// CFileSystemFileItem Implementation
//*****************************************************************************

void CFileSystemFileItem::Reset()
{
    m_pParentItem = NULL;
    m_strName.Empty();
    m_lpszExt = NULL;
    m_fReadOnly = FALSE;
    m_fHidden = FALSE;
    m_fCompressed = FALSE;
    m_dwSize = 0;
    m_nSizeType = sizeBytes;

#ifdef _DEBUG
    m_fReset = TRUE;
#endif // _DEBUG
}
