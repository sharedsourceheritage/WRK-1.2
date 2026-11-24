
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSFolder.h
//
// Declaration of CFileSytemFolderItem
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CFileSystemFolderItem
//*****************************************************************************

class CFileSystemFolderItem
{
// Constructor/Destructor
public:
    CFileSystemFolderItem();
    ~CFileSystemFolderItem();

    enum { fsiDrive = 1, fsiFolder = 2, fsiShortcut = 3, fsiShortcutSubFolder = 4 };
    enum { fsdUnknown = 0, fsdFixed = 1, fsdFloppy = 2, fsdCDROM = 3, fsdNetwork = 4 };

// Operations
public:
    static void InitFolderPool();
    static void CloseFolderPool();
    static CFileSystemFolderItem* CreateFolderItem();
    static void FreeFolderItem(CFileSystemFolderItem* pFolder);

    void InitShortcutFolder(LPCTSTR lpszPath, BOOL fReadOnly, BOOL fHidden, BOOL fCompressed);
    void InitDriveFolder(LPCTSTR lpszDrive, int nDriveType, BOOL fReadOnly, BOOL fHidden, BOOL fCompressed);
    void InitFolder(CFileSystemFolderItem* pParent, LPCTSTR lpszText, BOOL fReadOnly, BOOL fHidden, BOOL fCompressed);

    int GetFolderType()                         
	{ 
		_ASSERTE(!m_fReset); 
		return m_nType; 
	}
    int GetDriveType()                          
	{ 
		_ASSERTE(!m_fReset); 
		_ASSERTE(m_nType == fsiDrive); 
		return m_nDriveType; 
	}
    LPCTSTR GetFolderText()                     
	{ 
		_ASSERTE(!m_fReset); 
		return m_strText; 
	}
    void GetFolderPath(CString& strPath);
    int ComparePath(CFileSystemFolderItem* pFolder);
    BOOL IsUNCFolder();
    HTREEITEM GetFolderTreeHandle()             
	{ 
		_ASSERTE(!m_fReset); 
		return m_htiNode; 
	}
    void SetFolderTreeHandle(HTREEITEM hti)     
	{ 
		_ASSERTE(!m_fReset); 
		m_htiNode = hti; 
	}
    BOOL IsReadOnly()                           
	{ 
		_ASSERTE(!m_fReset); 
		return m_fReadOnly != 0; 
	}
    BOOL IsHidden()                             
	{ 
		_ASSERTE(!m_fReset); 
		return m_fHidden != 0; 
	}
    BOOL IsCompressed()                         
	{ 
		_ASSERTE(!m_fReset); 
		return m_fCompressed != 0; 
	}

    BOOL IsHierarchyBuilt()                     
	{ 
		_ASSERTE(!m_fReset); 
		return !m_fHierarchyDirty; 
	}
    void EnsureHierarchy();
    BOOL Refresh(BOOL fNow);
    void RefreshHierarchy(BOOL fNow);
    int GetHierarchyItemCount();
    CFileSystemFolderItem* GetHierarchyItem(int nIndex);

// Implementation
protected:
    void Reset();
    void FreeHierarchyItems();
    void InternalGetFolderPath(CString& strPath, int nPostLength);
    void RemoveHierarchyItem(CFileSystemFolderItem* pHierItem);

// Attributes
protected:
    short m_nType;
    short m_nDriveType;

    CFileSystemFolderItem* m_pParentItem;
    CString m_strText;

    HTREEITEM m_htiNode;

    BOOL m_fHierarchyDirty;
    CPtrArray* m_prgHierarchyItems;

    BOOL m_fReadOnly : 1;
    BOOL m_fHidden : 1;
    BOOL m_fCompressed : 1;

#ifdef _DEBUG
    BOOL m_fReset;
#endif // _DEBUG

    static CPtrArray s_rgFolderPool;
};
