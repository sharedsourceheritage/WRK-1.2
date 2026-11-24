
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSCommand.cpp
//
// Implementation of CFileSystemCommand
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"

const TCHAR* s_lpszFileDirectory = _T("$(FileDir)");
#define FILEDIR_LENGTH    10

const TCHAR* s_lpszFileName = _T("$(FileName)");
#define FILENAME_LENGTH   11

const TCHAR* s_lpszFileExtension = _T("$(FileExt)");
#define FILEEXT_LENGTH    10

const TCHAR* s_lpszFilePath = _T("$(FilePath)");
#define FILEPATH_LENGTH   11

const TCHAR* s_lpszSelFolder = _T("$(SelFolder)");
#define SELFOLDER_LENGTH  12

const TCHAR* s_lpszMagic = _T("$(Magic)");
#define MAGIC_LENGTH      8


//*****************************************************************************
// CFileSystemCommand Constructor/Destructor
//*****************************************************************************

CFileSystemCommand::CFileSystemCommand()
{
    m_szName[0] = _T('\0');
    m_lpszCommand = NULL;
    m_lpszArgs = NULL;
    m_dwFlags = 0;
    m_fMacrosDetected = FALSE;
}

CFileSystemCommand::~CFileSystemCommand()
{
    Reset();
}


//*****************************************************************************
// CFileSystemCommand Operations
//*****************************************************************************

HRESULT CFileSystemCommand::InitCommand(LPCTSTR lpszName, LPCTSTR lpszCmd,
                                     LPCTSTR lpszArgs, DWORD dwFlags)
{
    _ASSERTE(lpszName);_ASSERTE(lpszCmd);_ASSERTE(lpszArgs);
    if ((lpszName == NULL) || (lpszCmd == NULL) || (lpszArgs == NULL))
        return E_POINTER;

    _ASSERTE( (_tcslen(lpszName) < MAX_CMD_NAME) && (_tcslen(lpszCmd) < MAX_PATH) && (_tcslen(lpszArgs) < MAX_PATH) );
    if ( (_tcslen(lpszName) >= MAX_CMD_NAME) || (_tcslen(lpszCmd) >= MAX_PATH) || (_tcslen(lpszArgs) >= MAX_PATH) )
        return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

    _tcscpy(m_szName, lpszName);

    m_lpszCommand = new WCHAR[_tcslen(lpszCmd) + 1];
    if (m_lpszCommand == NULL)
    {
        Reset();
        return E_OUTOFMEMORY;
    }
    _tcscpy(m_lpszCommand, lpszCmd);

    m_lpszArgs = new WCHAR[_tcslen(lpszArgs) + 1];
    if (m_lpszArgs == NULL)
    {
        Reset();
        return E_OUTOFMEMORY;
    }
    _tcscpy(m_lpszArgs, lpszArgs);

    m_dwFlags = dwFlags;
    return S_OK;
}

void CFileSystemCommand::SetCommand(LPCTSTR lpszName, LPCTSTR lpszCmd,
                                    LPCTSTR lpszArgs, DWORD dwFlags)
{
    Reset();
    InitCommand(lpszName, lpszCmd, lpszArgs, dwFlags);
}

HRESULT CFileSystemCommand::Execute(CFileSystemFolderItem* pSelFolder,
                                    CFileSystemFileItem* pSelFile)
{
#ifdef _DEBUG
    if (!m_fMacrosDetected)
        DetectMacroRequirements();
    _ASSERTE(m_fMacrosDetected);
#endif // _DEBUG

    _ASSERTE(pSelFolder || !RequiresFolder());
    _ASSERTE(pSelFile || !RequiresFile());

    USES_CONVERSION;

    CComPtr<ICommandExecuter> srpCmdExec;
    CString strArguments;
    CString strWorkingDir;
    BOOL fMagic;
    HRESULT hr;

    // construct the arguments string
    ExpandMacros(m_lpszArgs, pSelFolder, pSelFile, strArguments, &fMagic);

    if (fMagic)
    {
        // magic command... do it and ignore everything else
        hr = ExecuteMagic();
        goto OnError;
    }

    // get the working directory
    if (pSelFolder)
    {
        pSelFolder->GetFolderPath(strWorkingDir);
    }
    else if (pSelFile)
    {
        pSelFile->GetParent()->GetFolderPath(strWorkingDir);
    }

    hr = _VxModule.QueryService(SID_SCommandExecuter, IID_ICommandExecuter, (void**)&srpCmdExec);
    IfFailGo(hr);

    hr = srpCmdExec->ExecuteCommand(T2CW(m_lpszCommand), T2CW((LPCTSTR)strArguments),
                                    T2CW((LPCTSTR)strWorkingDir),
                                    m_dwFlags & CMD_MASK_FLAGS);

OnError:
    return hr;
}

HRESULT CFileSystemCommand::ExecuteMagic()
{
    CComPtr<IMagicDisplay> srpMagic;
    CComBSTR bstrURL;
    CString strCaption;
    HRESULT hr;

    USES_CONVERSION;

    //hr = _VxModule.GetResourceURL(L"ABOUT_HTM", TRUE, &bstrURL);
    hr = GetResourceURL(L"ABOUT_HTM", TRUE, &bstrURL);
    IfFailGo(hr);

    strCaption.LoadString(IDS_FILESYS_MAGIC);
    _ASSERTE(strCaption);

    hr = _VxModule.QueryService(SID_SMagicDisplay, IID_IMagicDisplay, (void**)&srpMagic);
    IfFailGo(hr);

    hr = srpMagic->ShowMagic(bstrURL, T2CW((LPCTSTR)strCaption), 520, 340);
    _ASSERTE(SUCCEEDED(hr));

OnError:
    return S_OK;
}


//*****************************************************************************
// CFileSystemCommand Implementation
//*****************************************************************************

void CFileSystemCommand::Reset()
{
    m_szName[0] = _T('\0');
    if (m_lpszCommand)
    {
        delete m_lpszCommand;
        m_lpszCommand = NULL;
    }
    if (m_lpszArgs)
    {
        delete m_lpszArgs;
        m_lpszArgs = NULL;
    }
    m_dwFlags = 0;
    m_fMacrosDetected = FALSE;
}

void CFileSystemCommand::DetectMacroRequirements()
{
    _ASSERTE(m_lpszArgs);

    TCHAR* lpszIter = m_lpszArgs;
    TCHAR* lpszMacro;
    int nMacroLength;

    while (*lpszIter)
    {
        if (*lpszIter == _T('$'))
        {
            lpszMacro = lpszIter;
            nMacroLength = 1;

            lpszIter++;
            while (*lpszIter)
            {
                nMacroLength++;
                if (*lpszIter == _T(')'))
                {
                    if (nMacroLength > 3)
                    {
                        if ((nMacroLength == SELFOLDER_LENGTH) &&
                            (_tcsncmp(lpszMacro, s_lpszSelFolder, nMacroLength) == 0))
                        {
                            m_dwFlags |= CMD_REQ_FOLDER;
                            break;
                        }
                        else if (((nMacroLength == FILEPATH_LENGTH) &&
                                  (_tcsncmp(lpszMacro, s_lpszFilePath, nMacroLength) == 0)) ||
                                 ((nMacroLength == FILEDIR_LENGTH) &&
                                  (_tcsncmp(lpszMacro, s_lpszFileDirectory, nMacroLength) == 0)) ||
                                 ((nMacroLength == FILENAME_LENGTH) &&
                                  (_tcsncmp(lpszMacro, s_lpszFileName, nMacroLength) == 0)) ||
                                 ((nMacroLength == FILEEXT_LENGTH) &&
                                  (_tcsncmp(lpszMacro, s_lpszFileExtension, nMacroLength) == 0)))
                        {
                            m_dwFlags |= CMD_REQ_FILE;
                            break;
                        }
                    }

                    // saw end of macro, but didn't recognize it
                    break;
                }
                lpszIter++;
            }
        }

        lpszIter++;
    }

    m_fMacrosDetected = TRUE;
}

void CFileSystemCommand::ExpandMacros(LPCTSTR lpszArgs,
                                      CFileSystemFolderItem* pSelFolder,
                                      CFileSystemFileItem* pSelFile,
                                      CString& strArguments, BOOL* pfMagic)
{
    _ASSERTE(lpszArgs);

    TCHAR* lpszIter = m_lpszArgs;
    TCHAR* lpszAdd = m_lpszArgs;
    TCHAR* lpszMacro;
    int nMacroLength;

    *pfMagic = FALSE;

    while (*lpszIter)
    {
        // macros begin with $
        if (*lpszIter == _T('$'))
        {
            // add the arguments seen so far
            if (lpszIter != lpszAdd)
            {

                ///strArguments.Append(lpszAdd, lpszIter - lpszAdd);
				Append (strArguments, lpszAdd, (int)(lpszIter-lpszAdd));

            }

            lpszMacro = lpszIter;
            nMacroLength = 1;

            lpszIter++;

            // loop through to find end of macro
            while (*lpszIter)
            {
                nMacroLength++;
                if (*lpszIter == _T(')'))
                {
                    if (nMacroLength > 3)
                    {
                        // check if its a macro we understand and replace it
                        // with the actual value

                        if ((nMacroLength == SELFOLDER_LENGTH) &&
                            (_tcsncmp(lpszMacro, s_lpszSelFolder, nMacroLength) == 0))
                        {
                            _ASSERTE(pSelFolder);
                            CString strPath;
							if (pSelFolder)
							{
								pSelFolder->GetFolderPath(strPath);
							    
								///strArguments.Append(strPath);
								strArguments+=strPath;
							}

                            break;
                        }
                        else if ((nMacroLength == FILEPATH_LENGTH) &&
                                 (_tcsncmp(lpszMacro, s_lpszFilePath, nMacroLength) == 0))
                        {
                            _ASSERTE(pSelFile);
                            CString strPath;

 							if (pSelFile)
							{
								pSelFile->GetFilePath(strPath);

								///strArguments.Append(strPath);
								strArguments+=strPath;
							}
							
                            break;
                        }
                        else if ((nMacroLength == FILEDIR_LENGTH) &&
                                 (_tcsncmp(lpszMacro, s_lpszFileDirectory, nMacroLength) == 0))
                        {
                            _ASSERTE(pSelFile);
                            CString strPath;

                            pSelFile->GetParent()->GetFolderPath(strPath);

                            ///strArguments.Append(strPath);
                            strArguments+=strPath;
							
                            break;
                        }
                        else if ((nMacroLength == FILENAME_LENGTH) &&
                                 (_tcsncmp(lpszMacro, s_lpszFileName, nMacroLength) == 0))
                        {
                            _ASSERTE(pSelFile);

                            ///strArguments.Append(pSelFile->GetFileName());
                            strArguments+=(pSelFile->GetFileName());
							                            
							break;
                        }
                        else if ((nMacroLength == FILEEXT_LENGTH) &&
                                 (_tcsncmp(lpszMacro, s_lpszFileExtension, nMacroLength) == 0))
                        {
                            _ASSERTE(pSelFile);
                            

                            ///strArguments.Append(pSelFile->GetFileExtension());
                            strArguments+=(pSelFile->GetFileExtension());
							
                            break;
                        }
                        else if ((nMacroLength == MAGIC_LENGTH) &&
                                 (_tcsncmp(lpszMacro, s_lpszMagic, nMacroLength) == 0))
                        {
                            *pfMagic = TRUE;
                            return;     // Magic command... we don't care about anything else
                        }
                    }

                    // no macro replacement... add as is to command

                    ///strArguments.Append(lpszIter, nMacroLength);
					Append(strArguments, lpszIter, nMacroLength);
					
                   
					break;
                }
                lpszIter++;
            }

            lpszAdd = lpszIter + 1;
        }

        lpszIter++;
    }

    // and add any left over argument text

    ///strArguments.Append(lpszAdd);
    strArguments+=(lpszAdd);
	
}
