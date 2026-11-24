
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSExtMgr.h
//
// Declaration of CFileSystemExtensionManager
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CFileSystemExtensionManager
//*****************************************************************************
struct CFileSystemExtension
{
    int nIcon;
    TCHAR szDescription[80];
};

class CFileSystemExtensionManager
{
// Constructor/Destructor
public:
    CFileSystemExtensionManager();
    ~CFileSystemExtensionManager();

// Operations
public:
    int GetExtensionIconIndex(CFileSystemFileItem* pFile);
    LPCTSTR GetExtensionDescription(CFileSystemFileItem* pFile);
    HIMAGELIST GetExtensionsImageList()   
	{ 
		EnsureImageList(); 
		return m_himlExt; 
	}

// Implementation
    void InitExtensions();
    void FreeExtensions();
protected:
    CFileSystemExtension* LookupExtension(LPCTSTR lpszExtension);
    CFileSystemExtension* AddExtension(LPCTSTR lpszExtension, int nIcon, LPCTSTR lpszDescription);
    void EnsureImageList();

// Attributes
protected:
    CVxMapStringToPtr m_mapExtensions;
    CFileSystemExtension* m_pDefaultExt;
    HIMAGELIST m_himlExt;
    BOOL m_fExtensionsInitialized;
    BOOL m_fExtensionsFreed;
};
