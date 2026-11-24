
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNContBase.h: Declaration of the base class for nodes that are also container

#pragma once

#include "PrjNBase.h"

class CFileVwBaseContainer :
    public CFileVwBaseNode
{
protected:
    // Protected constructor: this class is not supposed to be instanziated, only
    // object from the derived classes can be created.
    CFileVwBaseContainer() {};

    // Function to check if a file is inside this container's folder and,
    // if that's not the case, copy it to this directory. It is used during
    // "Add existing item" 
    HRESULT CheckFileInFolder(CString& strFullPath);

public:

    // A container is supposed to be used from automation to enumerate the items
    // that are contained in it.
    STDMETHOD(GetAutomationObject)(
    /* [out] */ IDispatch ** ppIDispatch) = 0;


    // public methods required to create items (file or folder) inside the node

    HRESULT OnCmdAddFolder();
    HRESULT AddExistingFolder(LPCOLESTR pszFolderName, CFileVwBaseNode **pNewFolder);

    HRESULT OnCmdAddItem(BOOL fAddNewItem, LPCOLESTR pszSelectItem = NULL,
                      LPCOLESTR pszExpandDir = NULL);

    HRESULT AddItem(
        /* [in]                        */ VSADDITEMOPERATION    dwAddItemOperation,
        /* [in]                        */ LPCOLESTR             pszItemName,
        /* [in]                        */ ULONG                 cFilesToOpen,
        /* [in, size_is(cFilesToOpen)] */ LPCOLESTR             rgpszFilesToOpen[],
        /* [in]                        */ HWND                  hwndDlg,
        /* [in]                        */ VSSPECIFICEDITORFLAGS grfEditorFlags,
        /* [in]                        */ REFGUID               rguidEditorType,
        /* [in]                        */ LPCOLESTR             pszPhysicalView,
        /* [in]                        */ REFGUID               rguidLogicalView,
        /* [out, retval]               */ VSADDRESULT *         pResult);

    HRESULT AddExistingFile(LPCTSTR pszFullPathSource, CFileVwFileNode **ppNewFile, BOOL fSilent = FALSE, BOOL fLoad = FALSE );
    HRESULT AddNewFile(
                LPCTSTR pszFullPathSource,
                LPCTSTR pszNewFileName,
                CFileVwFileNode** ppNewNode);
    HRESULT RunWizard(
        /* [in]                        */ LPCOLESTR             pszItemName,
        /* [in]                        */ ULONG                 cFilesToOpen,
        /* [in, size_is(cFilesToOpen)] */ LPCOLESTR             rgpszFilesToOpen[],
        /* [in]                        */ HWND                  hwndDlg,
        /* [out, retval]               */ VSADDRESULT *         pResult);


    // Delete a node
    HRESULT DeleteNode(
        /* [in] */ CHierNode* pNode,        // node to be delted
        /* [in] */ BOOL fRemoveFromDisk);   // removes the file from disk


};

