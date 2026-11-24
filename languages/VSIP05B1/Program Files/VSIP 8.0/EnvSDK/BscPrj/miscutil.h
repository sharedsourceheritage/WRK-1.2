
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// miscutil.h : miscellaneous utility routines

#pragma once

HRESULT CheckFileName(LPCTSTR pszFileName);
HRESULT CheckFileType(LPCTSTR pszFilePath, BOOL fWhenExistOnly = FALSE);
HRESULT GetFullLongFilePath(
	LPCTSTR pszFilePath, // path to the file
	CString& strFullLongPath, 
	LPTSTR *lpFilePart = NULL); // pointer to the file name

void UtilGetErrorDescription(CString& strText);
BOOL UtilIsExecutableFile(LPCTSTR pszFileName);

HRESULT UtilSetWin32Err(DWORD err, UINT nIDPrompt, LPCTSTR pszString1);

//-------------------------------------------------------------------------
// Function:    CheckEnabledItem
//              This function checks if the automation model method is 
//              enabled or disabled.
// Parameters: 
//    /* [in] */ IDispatch *  pDisp, 
//    /* [in] */ const GUID * pGUID, 
//    /* [in] */ WCHAR *      pBuffer
//
// Returns:     HRESULT
// Notes:
//              If the method is disabled this function sets the error info,
//              and returns E_FAIL. If the method is enabled S_OK is returned.
//-------------------------------------------------------------------------
HRESULT CheckEnabledItem(
    /* [in] */ IDispatch *  pDisp, 
    /* [in] */ const GUID * pGUID, 
    /* [in] */ WCHAR *      pBuffer);

//-------------------------------------------------------------------------
// Returns the install location minus the trailing slash.
//-------------------------------------------------------------------------
HRESULT GetInstallLocation(CString& strInstallLocation);

//-------------------------------------------------------------------------
// Utility function to query the RDT for document information given a document name
// Returns S_OK and the requested info if the file is in the RDT
// Returns S_FALSE if the file is not in the RDT
// Returns E_xxx for failure
//-------------------------------------------------------------------------
HRESULT GetRDTDocumentInfo(
    /* [in]  */ LPCTSTR             pszDocumentName, 
    /* [out] */ IVsHierarchy**      ppIVsHierarchy      /* = NULL */, 
    /* [out] */ VSITEMID*           pitemid             /* = NULL */,
    /* [out] */ IVsPersistDocData** ppIVsPersistDocData /* = NULL */,
    /* [out] */ VSDOCCOOKIE*        pVsDocCookie        /* = NULL */);

//=========================================================================
//                                                       REGISTRATION UTILS

//---------------------------------------------------------------------
// Function:    GetRegRootStrings
//              Contruct strings to be used in _ATL_REGMAP_ENTRY for the 
//              registry root (REGROOTBEGIN and REGROOTEND)
// Parameters: 
//    /* [out] */ BSTR *       pbstrRootBegin, 
//              Replacement string for REGROOTBEGIN. It looks like
//              "NoRemove Software \n{\n NoRemove Microsoft \n{\n NoRemove 
//              VisualStudio \n{\n NoRemove 7.1 \n{\n"
//    /* [out] */ BSTR *       pbstrRootEnd,
//              Replacement string for REGROOTEND. It looks like
//              "\n}\n \n}\n \n}\n \n}\n"
//    /* [in]  */ const WCHAR* pwszRegRoot = NULL)
//              Registry string that will be parsed to generate
//              pbstrRootBegin and pbstrRootEnd.
//              If pwszRegRoot is NULL the default (LREGKEY_VISUALSTUDIOROOT_NOVERSION) 
//              string will be used along with the string specified by 
//              EnvSdk_RegKey environment variable. The Environment SDK 
//              sample code checks for  EnvSdk_RegKey environment variable. 
//              If the variable exists then it is added to the default 
//              L"Software\\Microsoft\\VisualStudio\\" registry string.
//               EnvSdk_RegKey is expected to be of the form "7.x" or "7.xexp".
//              If  EnvSdk_RegKey does not exist the default (LREGKEY_VISUALSTUDIOROOT)
//              string will be used i.e. L"Software\\Microsoft\\VisualStudio\\7.1"
// Returns:     HRESULT
// Notes:
//---------------------------------------------------------------------
HRESULT GetRegRootStrings(
    /* [out] */ BSTR *       pbstrRootBegin, 
    /* [out] */ BSTR *       pbstrRootEnd,
    /* [in]  */ const WCHAR* pwszRegRoot = NULL);


//-------------------------------------------------------------------------
// Function:    GetRegDefaultResourceStrings
//              Contruct strings to be used in _ATL_REGMAP_ENTRY for the 
//              resource dll (RESOURCE_PATH and RESOURCE_DLL)
// Parameters: 
//    /* [out] */ BSTR *      pbstrResDllPath, // optional, can be NULL
//              Replacement string for RESOURCE_PATH. 
//
//    /* [out] */ BSTR *      pbstrResDllName) // optional, can be NULL
//              Replacement string for RESOURCE_DLL. 
//              UI suffix is added to the name of the main dll.
//
// Returns:     HRESULT
// Notes:
//-------------------------------------------------------------------------
HRESULT GetRegDefaultResourceStrings(
    /* [out] */ BSTR * pbstrResDllPath, // optional, can be NULL
    /* [out] */ BSTR * pbstrResDllName);// optional, can be NULL


//-------------------------------------------------------------------------
// Function:    GetRegDefaultTemplatePath
//              Contruct strings to be used in _ATL_REGMAP_ENTRY for the 
//              template path (TEMPLATE_PATH)
// Parameters: 
//    /* [out] */ BSTR *      pbstrTemplatePath)
//              Replacement string for TEMPLATE_PATH. 
//
// Returns:     HRESULT
// Notes:
//-------------------------------------------------------------------------
HRESULT GetRegDefaultTemplatePath(
    /* [out] */ BSTR *      pbstrTemplatePath);


//-------------------------------------------------------------------------
// Function:    GetRegDevenvPath
//              Returns the full path of the devenv.exe 
// Parameters: 
//    /* [out] */ BSTR *      pbstrDevenvPath)
//              devenv full path. 
//
// Returns:     HRESULT
// Notes:       Uses VS\7.1\setup\vs registry values to get to the devenv path
//              because this method is used at registration time.
//-------------------------------------------------------------------------
HRESULT GetRegDevenvPath(
    /* [out] */ BSTR *      pbstrDevenvPath);

//-------------------------------------------------------------------------
// Function:    GetRegProgidVersion
//              Gets the ProgID version number (e.g. 7.1) 
// Parameters: 
//    /* [out] */ BSTR *      pbstrProgidVersion)
//              ProgID Version. 
//
// Returns:     HRESULT
// Notes:       Determines the version number from the
//              environment variable EnvSdk_RegKey.
//-------------------------------------------------------------------------
HRESULT GetRegProgidVersion(
    /* [out] */ BSTR *      pbstrProgidVersion);


//                                                       REGISTRATION UTILS
//=========================================================================


//=========================================================================
//                                                                  DIALOGS

// General msg box with Yes,No,Cancel and a Apply to all items checkbox.
class CApplyToAllMsgBox : 
    public CVsDialogImpl<CApplyToAllMsgBox>
{

public:
    
    // Helpers to make using this message box easier.    
    
    // Helper functions launches the dialog, sets the caption, checks and sets
    // the context specified.
    static int DoContextMsgBox(LPCWSTR pszMsg, LPCWSTR pszCaption, UINT nContext,int nDefButton = IDYES);

    // Version which takes a res id for the caption.
    static int DoContextMsgBox(LPCWSTR pszMsg, UINT nIdCaption, UINT nContext, int nDefButton = IDYES);

    // Version which takes a res id for the msg and the caption. In addition, it 
    // formats pszMsgParam1 into nIdMsg using VxFormatString1. If nContext is 0,
    // it uses nIdMsg as the context value.
    static int DoContextMsgBox(UINT nIdMsg, LPCWSTR pszMsgParam1, UINT nIdCaption, UINT nContext = 0, int nDefButton = IDYES);

    CApplyToAllMsgBox(LPCWSTR pszMsg, LPCWSTR pszCaption, int nDefButton = IDYES);
    CApplyToAllMsgBox(LPCWSTR pszMsg, UINT    nIDCaption, int nDefButton = IDYES);

    enum { IDD = IDD_APPLYTOALL };

BEGIN_MSG_MAP(CApplyToAllMsgBox)
    CHAIN_MSG_MAP(CVsDialogImpl<CApplyToAllMsgBox>)
    MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
    COMMAND_ID_HANDLER(IDYES, OnButton)
    COMMAND_ID_HANDLER(IDCANCEL, OnButton)
    COMMAND_ID_HANDLER(IDNO, OnButton)
END_MSG_MAP()

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

    // Button handler. Handles all buttons
    LRESULT OnButton(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

    BOOL    m_bApplyToAll;
protected:
    CString m_strMsg;
    CString m_strCaption;
    int     m_defButton;
};
//                                                                  DIALOGS
//=========================================================================


//=========================================================================
//                                                         Extender support
HRESULT GetExtender(
    /* [in]  */ LPCSTR          szguidCATID,
    /* [in]  */ IDispatch*      pIDispacth,
    /* [in]  */ BSTR            bstrExtenderName, 
    /* [out] */ IDispatch **    ppExtender);

HRESULT GetExtenderNames(
    /* [in]  */ LPCSTR          szguidCATID,
    /* [in]  */ IDispatch*      pIDispacth,
    /* [out] */ VARIANT *pvarExtenderNames);


HRESULT GetExtenderCATID(
    /* [in]  */ LPCSTR          szguidCATID,
    /* [out] */ BSTR *pbstrRetval);
//                                                         Extender support
//=========================================================================


//=========================================================================
//                                                     Misc. helper classes

//-------------------------------------------------------------------------
// Helper class to suspend file changes on a file. 
// By setting the fSuspendNow flag filechanges will be suspended during 
// construction and resumed during descrution.
// Alternately, you can call Suspend()/Resume() yourself. 
// The class will always Resume() on destruction if Suspend has been called 
// and a subsequent Resume hasn't been called.
//-------------------------------------------------------------------------
class CSuspendFileChanges
{
public:
    CSuspendFileChanges(
        /* [in] */ const CString& strMkDocument, 
        /* [in] */ BOOL           fSuspendNow = TRUE); 
    ~CSuspendFileChanges();

    void Suspend();
    void Resume();
protected:
    CString     m_strMkDocument;
    BOOL        m_fFileChangeSuspended;
    CComPtr<IVsDocDataFileChangeControl> m_srpIVsDocDataFileChangeControl;
};
//                                                     Misc. helper classes
//=========================================================================
