
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSFile.h
//
// Declaration of CFileSystemFileItem
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CFileSystemFileItem
//*****************************************************************************

class CFileSystemFileItem
{
// Constructor/Destructor
public:
    CFileSystemFileItem();
    ~CFileSystemFileItem();

    enum { sizeBytes, sizeKB, sizeMB, sizeGB };

// Operations
public:
    static void InitFilePool();
    static void CloseFilePool();
    static CFileSystemFileItem* CreateFileItem();
    static void FreeFileItem(CFileSystemFileItem* pFile);

    void InitFile(CFileSystemFolderItem* pParent, LPCTSTR lpszName, BOOL fReadOnly, BOOL fHidden, BOOL fCompressed, DWORD dwSize, short nSizeType);

    LPCTSTR GetFileName()                       
	{
		_ASSERTE(!m_fReset); 
		return m_strName; 
	}
    LPCTSTR GetFileExtension()                  
	{ 
		_ASSERTE(!m_fReset); 
		return m_lpszExt; 
	}
    void GetFilePath(CString& strPath);
    int CompareFile(CFileSystemFileItem* pFile, BOOL fExtension);
    CFileSystemFolderItem* GetParent()          
	{ 
		_ASSERTE(!m_fReset); 
		return m_pParentItem; 
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

    DWORD GetSize()                             
	{ 
		_ASSERTE(!m_fReset); 
		return m_dwSize; 
	}
    short GetSizeType()                         
	{ 
		_ASSERTE(!m_fReset); 
		return m_nSizeType; 
	}

// Implementation
protected:
    void Reset();

// Attributes
protected:
    CFileSystemFolderItem* m_pParentItem;
    CString m_strName;
    LPCTSTR m_lpszExt;

    BOOL m_fReadOnly : 1;
    BOOL m_fHidden : 1;
    BOOL m_fCompressed : 1;

    DWORD m_dwSize;
    short m_nSizeType;

#ifdef _DEBUG
    BOOL m_fReset;
#endif // _DEBUG

    static CPtrArray s_rgFilePool;
};
