
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSCommand.h
//
// Declaration of CFileSystemCommand
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CFileSystemCommand
//*****************************************************************************

#define CMD_REQ_FOLDER      0x0100
#define CMD_REQ_FILE        0x0200

#define CMD_MASK_FLAGS      0x00FF
#define CMD_MASK_REQ        0xFF00

#define MAX_CMD_NAME        128

extern const TCHAR* s_lpszFileDirectory;
extern const TCHAR* s_lpszFileName;
extern const TCHAR* s_lpszFileExtension;
extern const TCHAR* s_lpszFilePath;
extern const TCHAR* s_lpszSelFolder;
extern const TCHAR* s_lpszMagic;


class CFileSystemCommand
{
// Constructor/Destructor
public:
    CFileSystemCommand();
    ~CFileSystemCommand();

// Operations
public:
    HRESULT InitCommand(LPCTSTR lpszName, LPCTSTR lpszCmd, LPCTSTR lpszArgs, DWORD dwFlags);
    void SetCommand(LPCTSTR lpszName, LPCTSTR lpszCmd, LPCTSTR lpszArgs, DWORD dwFlags);

    LPCTSTR GetCommandName()     
	{ 
		return m_szName; 
	}
    LPCTSTR GetCommandCommand()  
	{ 
		return m_lpszCommand; 
	}
    LPCTSTR GetCommandArgs()     
	{ 
		return m_lpszArgs; 
	}
    DWORD GetCommandFlags()      
	{ 
		return m_dwFlags & CMD_MASK_FLAGS; 
	}

    BOOL RequiresFolder()        
	{ 
		if (!m_fMacrosDetected) DetectMacroRequirements(); 
		return m_dwFlags & CMD_REQ_FOLDER; 
	}
    BOOL RequiresFile()          
	{ 
		if (!m_fMacrosDetected) DetectMacroRequirements(); 
		return m_dwFlags & CMD_REQ_FILE; 
	}

    HRESULT Execute(CFileSystemFolderItem* pSelFolder, CFileSystemFileItem* pSelFile);
    HRESULT ExecuteMagic();

// Implementation
protected:
    void Reset();
    void DetectMacroRequirements();
    void ExpandMacros(LPCTSTR lpszArgs, CFileSystemFolderItem* pSelFolder, CFileSystemFileItem* pSelFile, CString& strArguments, BOOL* pfMagic);

// Attributes
protected:
    TCHAR m_szName[MAX_CMD_NAME];
    TCHAR* m_lpszCommand;
    TCHAR* m_lpszArgs;
    DWORD m_dwFlags;

    BOOL m_fMacrosDetected;
};
