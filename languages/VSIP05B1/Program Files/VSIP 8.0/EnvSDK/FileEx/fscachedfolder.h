
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSCachedFolder.h
//
// Declaration of CFileSystemCachedFolder
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CFileSytemCachedFolder
//*****************************************************************************

class CFileSystemCachedFolder
{
// Constructor/Destructor
public:
    CFileSystemCachedFolder();
    ~CFileSystemCachedFolder();

// Operations
public:
    void InitFolder(CFileSystemFolderItem* pFolder);
    void RefreshFolder();
    void Reset();
    CFileSystemFolderItem* GetFolder() 
	{ 
		return m_pParentItem; 
	}
    BOOL IsUsable()                    
	{ 
		return !m_fInUse; 
	}
    void SetUsable(BOOL fUsable)       
	{ 
		_ASSERTE(!m_fReset); m_fInUse = !fUsable; 
	}
    BOOL IsReset()                     
	{ 
		return m_fReset; 
	}

    long GetFileCount();
    CFileSystemFileItem* GetFile(int nIndex);

// Implementation
protected:
    void RemoveAllFiles();

// Attributes
protected:
    CFileSystemFolderItem* m_pParentItem;
    BOOL m_fInUse;
    BOOL m_fReset;

    HTREEITEM m_htiNode;

    CPtrArray m_rgFiles;
};
