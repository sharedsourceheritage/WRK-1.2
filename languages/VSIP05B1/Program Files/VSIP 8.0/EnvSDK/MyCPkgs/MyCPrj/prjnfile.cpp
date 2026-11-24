
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjNRoot.cpp : Implementation of CFileVwFileNode and interfaces

#include "stdafx.h"
#include "PrjInc.h"

CFileVwFileNode::CFileVwFileNode()
{
}

CFileVwFileNode::~CFileVwFileNode()
{
}

//---------------------------------------------------------------------------
// Create & AddRef a File View project node & return it as an out param
//---------------------------------------------------------------------------
HRESULT CFileVwFileNode::CreateInstance
(
LPCTSTR pszFullPath,
CFileVwFileNode **ppFileNode 
)
{
	CComObject<CFileVwFileNode> *pFileNode = NULL;  // created with 0 ref cunt
	HRESULT hr = CComObject<CFileVwFileNode>::CreateInstance(&pFileNode);
	if (SUCCEEDED(hr))
	{
		pFileNode->AddRef();
		hr = pFileNode->Initialize(pszFullPath);
        if (FAILED(hr))
        {
            pFileNode->Release();
            pFileNode = NULL;
        }
	}
	*ppFileNode = pFileNode;

	return hr;
}


//---------------------------------------------------------------------------
// Initializing the file node only means to set its caption today.
//---------------------------------------------------------------------------
HRESULT CFileVwFileNode::Initialize
(
LPCTSTR pszFullPath
)
{
    ExpectedPtrRet(pszFullPath);

	// the path should have been checked at this point
	SetFullPath(pszFullPath);	// this call also sets our nodes caption
	return NOERROR;
}


void CFileVwFileNode::SetFullPath(LPCTSTR pszFullPath) 
{ 
	CFileVwBaseNode::SetFullPath(pszFullPath);

	// Update the caption for our file node based on the full path.
	CString strCaption;
	strCaption = GetFileName();
	SetName(strCaption);

}


HRESULT CFileVwFileNode::Close()
{
    if (m_srpProjectItem != NULL)
        static_cast<CAOProjectItemFile*>((ProjectItem*) m_srpProjectItem)->Close();
    #ifndef USEDEFAULTSELECTION
        if (m_srpSelectedItem != NULL)
            static_cast<CAOSelectedItem*>((SelectedItem*) m_srpSelectedItem)->Close();
    #endif

    return S_OK;
}

//---------------------------------------------------------------------------
// Write information for node to project file.
//---------------------------------------------------------------------------
HRESULT CFileVwFileNode::Save
(
IVsPropertyStreamOut *pIVsPropertyStreamOut
) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	ASSERT(pIVsPropertyStreamOut);
	HRESULT hr = S_OK;

	// we currently do not have any data to write. 
	// e.g., in the future we may save a bool property as to whether the 
	// file is considered an output for deployment.
	return hr;
}


//---------------------------------------------------------------------------
// Read information for node to project file.
//---------------------------------------------------------------------------
HRESULT CFileVwFileNode::Load
(
IVsPropertyStreamIn *pIVsPropertyStreamIn
) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	ASSERT(pIVsPropertyStreamIn);
	HRESULT hr = S_OK;

	// we currently do not have any data to read. 
	// e.g., in the future we may read a bool property as to whether the 
	// file is considered an output for deployment.
	return hr;
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
const GUID* CFileVwFileNode::PGuidGetType(void) const
{
	return &GUID_NODETYPE_FileVw_File;
}


//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
STDMETHODIMP CFileVwFileNode::QueryStatus
(
const GUID*	pguidCmdGroup,
ULONG		cCmds,
OLECMD		prgCmds[],
OLECMDTEXT*	pCmdText
)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pguidCmdGroup);
    ExpectedPtrRet(prgCmds);
    ExpectedExprRet(1 == cCmds);
	USES_CONVERSION;

	QUERY_STATUS_CHECK;

	OLECMD& Cmd = prgCmds[0];

	HRESULT hr = OLECMDERR_E_NOTSUPPORTED;
	BOOL fSupported = FALSE;
	BOOL fEnabled = FALSE;
	BOOL fInvisible = FALSE;

	if(*pguidCmdGroup == guidVSStd97)
	{
		hr = S_OK;
		switch(Cmd.cmdID)
		{
			case cmdidOpen:
				fSupported =  TRUE;
				fEnabled = TRUE;
				break;
			case cmdidOpenWith:
				fSupported =  TRUE;
				fEnabled = TRUE;
				break;
			case cmdidPreviewInBrowser:
				fSupported =  TRUE;
				fEnabled = TRUE;
				break;
			case cmdidBrowseWith:
				fSupported =  TRUE;
				fEnabled = TRUE;
				break;
			case cmdidCut:                   
			case cmdidCopy:                  
				fSupported = TRUE;
				fEnabled = TRUE;
				break;
			default:
				hr = OLECMDERR_E_NOTSUPPORTED;
				break;
		}
	}

	if (SUCCEEDED(hr) && fSupported)
	{
		Cmd.cmdf = OLECMDF_SUPPORTED;
		if (fInvisible)
			Cmd.cmdf |= OLECMDF_INVISIBLE;
		else if (fEnabled)
			Cmd.cmdf |= OLECMDF_ENABLED;
	}

	if (hr == OLECMDERR_E_NOTSUPPORTED)
		hr = CFileVwBaseNode::QueryStatus(pguidCmdGroup, cCmds, prgCmds, pCmdText);

	return hr;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
STDMETHODIMP CFileVwFileNode::Exec
(
const GUID*	pguidCmdGroup,
DWORD		nCmdID,
DWORD		nCmdexecopt,
VARIANT*	pvaIn,
VARIANT*	pvaOut
)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	if (!pguidCmdGroup)
		return E_INVALIDARG;
	
	HRESULT hr = OLECMDERR_E_NOTSUPPORTED;

	if (*pguidCmdGroup == guidVSStd97)
	{
		hr = S_OK;
		switch(nCmdID)
		{
			case cmdidOpen:
				hr = OnCmdOpen();
				break;
			case cmdidOpenWith:
				hr = OnCmdOpenWith();
				break;
			case cmdidPreviewInBrowser:
				hr = OnCmdViewPage();
				break;
			case cmdidBrowseWith:
				hr = OnCmdViewPage(TRUE);
				break;
			default:
				hr = OLECMDERR_E_NOTSUPPORTED;
				break;
		}
	}

	if (hr == OLECMDERR_E_NOTSUPPORTED)
		hr = CFileVwBaseNode::Exec(pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut);

	return hr;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
HRESULT CFileVwFileNode::GetGuidProperty(VSHPROPID propid, GUID* pGuid) const
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	ASSERT(pGuid);
	if (!pGuid)
		return E_INVALIDARG;
	*pGuid = GUID_NULL;

	HRESULT hr = S_OK;

	switch (propid)
	{
		case VSHPROPID_TypeGuid:
            // we represent physical file on disk so 
            // return the corresponding guid defined in vsshell.idl
			*pGuid = GUID_ItemType_PhysicalFile;
			break;
		default:
			hr = DISP_E_MEMBERNOTFOUND;
			break;
	}
	return hr;
}

//---------------------------------------------------------------------------
//	Returns requested guid property
//---------------------------------------------------------------------------
HRESULT CFileVwFileNode::GetProperty(VSHPROPID propid, VARIANT* pvar)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	ASSERT(pvar);
	if (!pvar)
		return E_INVALIDARG;
	VariantInit(pvar);

	HRESULT hr = S_OK;
	switch (propid)
	{
    #ifndef USEDEFAULTSELECTION
	    case VSHPROPID_ExtSelectedItem:
		    if (!m_srpSelectedItem)
		    {
                hr = CAOSelectedItem::CreateInstance(this, &m_srpSelectedItem);
                IfFailRet(hr);
                ExpectedExprRet(m_srpSelectedItem != NULL);
		    }
		    IfFailGo(m_srpSelectedItem->QueryInterface(IID_IDispatch, (LPVOID*)&V_DISPATCH(pvar)));
		    V_VT(pvar) = VT_DISPATCH;
		    break;
    #endif

	case VSHPROPID_ExtObject:
		if (!m_srpProjectItem)
		{	//Need to demand create the extensibility object.
            hr = CAOProjectItemFile::CreateInstance(this, &m_srpProjectItem);
            IfFailRet(hr);
            ExpectedExprRet(m_srpProjectItem != NULL);
		}
		IfFailGo(m_srpProjectItem->QueryInterface(IID_IDispatch, (LPVOID*)&V_DISPATCH(pvar)));
		V_VT(pvar) = VT_DISPATCH;
		break;

	case VSHPROPID_TypeName:
		{
			CString strTypeName;
			if (!strTypeName.LoadString(IDS_FILENODE_TYPE))
                return E_FAIL;
			V_VT(pvar) = VT_BSTR;
			V_BSTR(pvar) = strTypeName.AllocSysString();
            if (!pvar->bstrVal) return E_OUTOFMEMORY;
		}
		break;
    case VSHPROPID_BrowseObject:		// CHierNode derived property
		if(SUCCEEDED(hr = QueryInterface(IID_IDispatch, (void **)&V_DISPATCH(pvar))))
		{
			V_VT(pvar) = VT_DISPATCH;
		}
		break;

	default:	// Delegate
		hr = CFileVwBaseNode::GetProperty(propid, pvar);
		break;
	}
Error:
	return hr;
}


//-----------------------------------------------------------------------------
// Opens the file using the selected openWith edior.
//-----------------------------------------------------------------------------
HRESULT CFileVwFileNode::OnCmdOpenWith()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = E_ABORT;
	if(!GetExecutionCtx().IsCancelled())
		hr = OpenDoc(FALSE, TRUE);
	return hr;
}

//-----------------------------------------------------------------------------
// Opens this file.
//-----------------------------------------------------------------------------
HRESULT CFileVwFileNode::OnCmdOpen()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = E_ABORT;
	if(!GetExecutionCtx().IsCancelled())
		hr = OpenDoc();
	return hr;
}


//-----------------------------------------------------------------------------
// Called when the node is about to be deleted.
//-----------------------------------------------------------------------------
HRESULT CFileVwFileNode::OnDelete(void)
{
    CAutomationEvents::FireProjectItemsEvent(
        this,
        CAutomationEvents::ProjectItemsEventsDispIDs::ItemRemoved);

    Close();
    return S_OK;
}

//-----------------------------------------------------------------------------
// Launches the configured browser on this pages url.
//-----------------------------------------------------------------------------
HRESULT CFileVwFileNode::OnCmdViewPage(BOOL fPreviewWith /*= FALSE*/)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	if(GetExecutionCtx().IsCancelled())
        return E_ABORT;

    return PreviewDoc(fPreviewWith);
}


HRESULT CFileVwFileNode::get_FileName(BSTR *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);
    *pVal = m_strFileName.AllocSysString();
    if (!*pVal) return E_OUTOFMEMORY;
    return S_OK;
}

HRESULT CFileVwFileNode::put_FileName(BSTR NewName)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    return SetEditLabel(NewName);
}

HRESULT CFileVwFileNode::get_FilePath(BSTR *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);
	CString strFilePath = m_strFullPath;
	int nPos = strFilePath.ReverseFind('\\');
	strFilePath = strFilePath.Left(nPos+1);
    *pVal = strFilePath.AllocSysString();
    if (!*pVal) return E_OUTOFMEMORY;
    return S_OK;
}

HRESULT CFileVwFileNode::get_IsOutput(VARIANT_BOOL *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);
    *pVal = VARIANT_FALSE;
    return S_OK;
}

HRESULT CFileVwFileNode::get_ModifiedDate(VARIANT *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);
    pVal->vt = VT_DATE;
    pVal->date = 1;

    HANDLE hFile = CreateFile(m_strFullPath, 0/*GENERIC_READ*/, FILE_SHARE_WRITE|FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return E_FAIL;
    FILETIME ft;
    if(!GetFileTime(hFile, NULL, NULL, &ft))
    {
        CloseHandle(hFile);
        return E_FAIL;
    }
    CloseHandle(hFile);
    WORD wDOSDate, wDOSTime;
    if(!FileTimeToDosDateTime(&ft, &wDOSDate, &wDOSTime))
        return E_FAIL;
    if(!DosDateTimeToVariantTime(wDOSDate, wDOSTime, &pVal->date))
        return E_FAIL;
    return S_OK;
}

HRESULT CFileVwFileNode::get_Size(double *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);
    *pVal = 0;
    HRESULT hr = S_OK;
	long lTemp;
	HANDLE hFile = CreateFile(m_strFullPath, GENERIC_READ, FILE_SHARE_WRITE|FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return E_FAIL;
	DWORD dwHigh;
	DWORD dwSize = GetFileSize(hFile, &dwHigh);
    if (dwSize == INVALID_FILE_SIZE)
        hr = HRESULT_FROM_WIN32(::GetLastError());
	CloseHandle(hFile);
    IfFailRet(hr);
	lTemp = dwHigh;
	lTemp <<= 32;
	lTemp += dwSize;
	*pVal = lTemp;
    return S_OK;
}

HRESULT CFileVwFileNode::get_FileType(BSTR *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);
	CString strExt = m_strFileName;
	TCHAR szKeyName[MAX_PATH];
	HKEY hKey;
	DWORD dwType;
	DWORD dwSize = MAX_PATH;

	int nReverseFindPos = strExt.ReverseFind('.');
	if (nReverseFindPos == 0xffffffff)
	{
		CString strFile;
		if (!strFile.LoadString(IDS_FILE))
            return E_FAIL;
		*pVal = strFile.AllocSysString();
        if (!*pVal) return E_OUTOFMEMORY;
		return S_OK;
	}
	int nLoc = strExt.GetLength() - nReverseFindPos;
	strExt = strExt.Right(nLoc);

	CString strUnspecifiedType;
	VxFormatString1(strUnspecifiedType, IDS_SPACEFILE, strExt.Right(strExt.GetLength()-1));
	*pVal = strUnspecifiedType.AllocSysString();
	if (!*pVal) return E_OUTOFMEMORY;

	if (RegOpenKeyEx(HKEY_CLASSES_ROOT, strExt, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
		return S_OK;
	if (RegQueryValueEx(hKey, NULL, NULL, &dwType, (LPBYTE)szKeyName, &dwSize) != ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		return S_OK;
	}
	RegCloseKey(hKey);
	if(RegOpenKeyEx(HKEY_CLASSES_ROOT, szKeyName, 0, KEY_READ, &hKey) != ERROR_SUCCESS)
		return S_OK;
	dwSize = MAX_PATH;
	if(RegQueryValueEx(hKey, NULL, NULL, &dwType, (LPBYTE)szKeyName, &dwSize) != ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		return S_OK;
	}
	strExt = szKeyName;
	SysFreeString(*pVal);
	*pVal = strExt.AllocSysString();
	if (!*pVal) return E_OUTOFMEMORY;
  return S_OK;
}

HRESULT CFileVwFileNode::get_ReadOnly(VARIANT_BOOL *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);
    *pVal = VARIANT_FALSE;
	DWORD dwAttributes = GetFileAttributes(m_strFullPath);
	if (dwAttributes == 0xffffffff)
		return E_FAIL;
	*pVal = ((FILE_ATTRIBUTE_READONLY & dwAttributes) == FILE_ATTRIBUTE_READONLY) ? VARIANT_TRUE : VARIANT_FALSE;
    return S_OK;
}

HRESULT CFileVwFileNode::put_ReadOnly(VARIANT_BOOL pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	DWORD dwAttributes = GetFileAttributes(m_strFullPath);
	if (dwAttributes == 0xffffffff)
		return E_FAIL;
	DWORD dwRO = FILE_ATTRIBUTE_READONLY;
	
	if (pVal == VARIANT_FALSE)
	{
		dwRO = ~dwRO;
		dwAttributes &= dwRO;
	}
	else
		dwAttributes |= dwRO;
	if (!SetFileAttributes(m_strFullPath, dwAttributes))
		return E_FAIL;

    HRESULT hr = OnPropertyChanged(DISPID_MyCPrjSourceFile_ReadOnly, FALSE);
    ASSERT(SUCCEEDED(hr));

  return S_OK;
}


STDMETHODIMP CFileVwFileNode::get_Extender(
    /* [in]          */ BSTR         bstrExtenderName, 
    /* [out, retval] */ IDispatch ** ppExtender)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(bstrExtenderName);
    ExpectedPtrRet(ppExtender);
    InitParam(ppExtender);

    HRESULT hr = S_OK;

    CComPtr<VxDTE::ObjectExtenders> srpObjectExtenders = _VxModule.GetObjectExtenders();
    ExpectedExprRet(srpObjectExtenders != NULL);

    CComBSTR cbstrCATID;
    hr = get_ExtenderCATID(&cbstrCATID);
    IfFailRet(hr);

    hr = srpObjectExtenders->GetExtender(
        /* [in] BSTR ExtenderCATID              */ cbstrCATID,
        /* [in] BSTR ExtenderName               */ bstrExtenderName,
        /* [in] IDispatch *ExtendeeObject       */ (LPDISPATCH)this,
        /* [retval][out] IDispatch **Extender   */ ppExtender);

    return hr;
}


STDMETHODIMP CFileVwFileNode::get_ExtenderNames(
    /* [out, retval] */ VARIANT * pvarExtenderNames)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

    CComPtr<VxDTE::ObjectExtenders> srpObjectExtenders = _VxModule.GetObjectExtenders();
    ExpectedExprRet(srpObjectExtenders != NULL);

    CComBSTR cbstrCATID;
    hr = get_ExtenderCATID(&cbstrCATID);
    IfFailRet(hr);

    hr = srpObjectExtenders->GetExtenderNames(
        /* [in] BSTR ExtenderCATID              */ cbstrCATID,
        /* [in] IDispatch *ExtendeeObject       */ (LPDISPATCH) this,
        /* [retval][out] VARIANT *ExtenderNames */ pvarExtenderNames);

    return hr;
}

    
STDMETHODIMP CFileVwFileNode::get_ExtenderCATID(
    /* [out, retval] */ BSTR * pbstrRetval)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pbstrRetval);
    InitParam(pbstrRetval);

    CComBSTR cbstrCATID(prjCATIDMyCPrjFileBrowseObject);
    if (cbstrCATID.Length() == 0)
        return E_OUTOFMEMORY;

    *pbstrRetval = cbstrCATID.Detach();
    return S_OK;
}


STDMETHODIMP CFileVwFileNode::OnPropertyChanged(
    /* [in] */ DISPID dispid        /* = DISPID_UNKNOWN */, 
    /* [in] */ BOOL   fDirtyProject /* = TRUE           */)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // We return an error code but do not stop.
    HRESULT hr = S_OK;

    CComPtr<IUnknown> srpIUnknown;
    hr = QueryInterface(IID_IUnknown, (void**)&srpIUnknown);
    ASSERT(SUCCEEDED(hr) && (srpIUnknown != NULL));

    if (SUCCEEDED(hr) && (srpIUnknown != NULL))
    {
        // fire the event 
        hr = CFirePropNotifyEvent::FireOnChanged(srpIUnknown, dispid);
        ASSERT(SUCCEEDED(hr));
    }

    if (fDirtyProject)
    {
        CFileVwProjNode* pProjNode = GetProjectNode();
        ASSERT(pProjNode);
        if (pProjNode != NULL)
            pProjNode->SetProjectFileDirty(TRUE);
        else
            if (SUCCEEDED(hr))
                hr = E_UNEXPECTED;
    }

    return hr;
}


//---------------------------------------------------------------------------
// VSHPROPID_EditLabel - called by CVSHierarchy.
//---------------------------------------------------------------------------
HRESULT CFileVwFileNode::GetEditLabel(BSTR *pbstrLabel)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ASSERT(NULL != pbstrLabel && NULL == *pbstrLabel);
    ExpectedPtrRet(pbstrLabel);
    CString strNewName;
    strNewName = GetName();
    *pbstrLabel = strNewName.AllocSysString();
    return (*pbstrLabel) ? S_OK : E_OUTOFMEMORY;
} // CFileVwFileNode::GetEditLabel

//---------------------------------------------------------------------------
// VSHPROPID_EditLabel - called by CVSHierarchy
// NOTE: bstrLabel is being freed by the caller (shell).
//---------------------------------------------------------------------------
HRESULT CFileVwFileNode::SetEditLabel(BSTR   bstrLabel)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	USES_CONVERSION;

    return Rename(W2CT(bstrLabel));
} // CFileVwFileNode::SetEditLabel


//-----------------------------------------------------------------------------
// Renames the file to the new name.
// Note:  We move files around in the hierarchy so on successful rename
// we must return S_FALSE instead of S_OK as per spec to let the
// project window know to postpone repaint.
//-----------------------------------------------------------------------------
HRESULT CFileVwFileNode::Rename(LPCTSTR pszNewName)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;
	USES_CONVERSION;

    ExpectedExprRet(GetCVsHierarchy());
    CMyProjectHierarchy *pMyProjectHierarchy = static_cast<CMyProjectHierarchy*>(GetCVsHierarchy());
	if ( !pMyProjectHierarchy->QueryEditProjectFile() )
		return OLE_E_PROMPTSAVECANCELLED;

    // don't allow null or empty string
    if (!pszNewName || !*pszNewName)
    {
        _VxModule.SetErrorInfo(E_FAIL,IDS_RENAMEFILEFAILED, 0);
        return E_FAIL;
    }

    CString strNewName;
    strNewName = pszNewName;
	LUtilFixFilename(strNewName);// Remove trailing dots and spaces
    
    CString strNewFilename;
    strNewFilename = strNewName;

	// make sure no illegal characters
	hr = CheckFileName(strNewFilename);
	if (FAILED(hr))
	{
        CString msg;
        VxFormatString1(msg, IDS_INVALIDFILENAME, strNewFilename);
        _VxModule.SetErrorInfo(hr,msg, 0);
        return hr;
    }

    // get the current file name
    CString strCurrentFilename;
    strCurrentFilename = GetName();
	
    // If we rename same file-same case then ignore
    if (!lstrcmp(strCurrentFilename, strNewName))
        return S_OK;

    // If we rename same file to same name, but different case then remember this
    BOOL fRenameSameFile = FALSE;
    if (!lstrcmpi(strCurrentFilename, strNewName))
        fRenameSameFile = TRUE;
	
    strCurrentFilename = GetFullPath();

    // determine the full path of the new file name
    strNewFilename = strCurrentFilename;
    INT_PTR nLastBackslashPos;
    nLastBackslashPos = strNewFilename.ReverseFind(TEXT('\\'));
    if (nLastBackslashPos >= 0)
    {
        strNewFilename = strNewFilename.Left(nLastBackslashPos + 1);
    }
    strNewFilename += strNewName;

    // Check if file already exists and error if so...
    if (!fRenameSameFile)
    {
        HANDLE  hf;
        WIN32_FIND_DATA ffData;
        if ((hf = FindFirstFile(strNewFilename, &ffData)) != INVALID_HANDLE_VALUE)
        {
            FindClose(hf);
            CString msg;
            VxFormatString1(msg, IDS_RENAMEFILEALREADYEXISTS, strNewFilename);
            _VxModule.SetErrorInfo(E_FAIL,msg, 0);
            return E_FAIL;
        }
	}
	
    /// convert 
    LPCOLESTR  pwszFile = T2COLE(strCurrentFilename);
    LPCOLESTR  pwszNew  = T2COLE(strNewFilename);

    // Check if the document is in the cache and rename document in the cache.
    CComPtr<IVsRunningDocumentTable> pRDT;
    hr = _VxModule.QueryService(SID_SVsRunningDocumentTable, IID_IVsRunningDocumentTable, (PVOID *)&pRDT);
    IfFailRet(hr);

    CComPtr<IVsHierarchy> poHier;
    VSITEMID oItemID;
    VSCOOKIE     dwCookie = VSCOOKIE_NIL;
    hr = pRDT->FindAndLockDocument(RDT_ReadLock, pwszFile, &poHier, &oItemID, NULL, &dwCookie);
    IfFailRet(hr);
    if (dwCookie != VSCOOKIE_NIL)
        pRDT->UnlockDocument(RDT_ReadLock, dwCookie);
	
    // if document is open and we are not owner of document, do not rename it
    if (poHier != NULL)
    {
        CComPtr<IVsHierarchy> pMyHier = (GetCVsHierarchy()->GetIVsHierarchy());
        CComPtr<IUnknown> punkRDTHier;
        CComPtr<IUnknown> punkMyHier;
        pMyHier->QueryInterface(IID_IUnknown, (void **)&punkMyHier);
        poHier->QueryInterface(IID_IUnknown, (void **)&punkRDTHier);
        if (punkRDTHier != punkMyHier)
            return S_OK;
    }

    // see if any packages have a problem with this.
    CFileVwProjNode *pProject = GetProjectNode();
    ExpectedPtrRet(pProject);
    CVsTrackProjectDocuments2Helper* pCVsTrackProjectDocuments2Helper = NULL;
    pCVsTrackProjectDocuments2Helper = pProject->GetCVsTrackProjectDocuments2Helper();
    ASSERT(pCVsTrackProjectDocuments2Helper);
    if (pCVsTrackProjectDocuments2Helper)
    {
        hr = pCVsTrackProjectDocuments2Helper->CanRenameItem(
            static_cast<CHierNode*>(this),
            pwszNew);
        _IfFailRet(hr); // could be aborted
    }
	
    // Create the new file
    if (!fRenameSameFile)
    {
        if (!::CopyFile(strCurrentFilename, strNewFilename, TRUE))
			return HRESULT_FROM_WIN32(GetLastError());
    }

	// Set filename and path information 
	SetFullPath(strNewFilename);

    if (dwCookie != VSCOOKIE_NIL)
	{
        hr = pRDT->RenameDocument(pwszFile, pwszNew, poHier, oItemID);
		if (FAILED(hr))
		{
			//set the old name back
			SetFullPath(strCurrentFilename);
			if (!fRenameSameFile)
				::DeleteFile(strNewFilename);
            _VxModule.SetErrorInfo(E_FAIL,IDS_RENAMEFILEFAILED, 0);
            return E_FAIL;
		}
	}

    // ignore file change notifications
    CSuspendFileChanges suspendFileChanges(
        /* [in] const CString& strMkDocument*/ strNewFilename, 
        /* [in] BOOL           fSuspendNow = TRUE*/ TRUE );
        
    // update the caption of the hierarchy node
    CComVariant PropertyValue = strNewFilename;  
    IVsHierarchy *pHierarchy = pMyProjectHierarchy->GetIVsHierarchy();
	if (pHierarchy)
		pHierarchy->SetProperty(this->GetVsItemID(), VSHPROPID_Caption, PropertyValue);
	else
		pMyProjectHierarchy->SetProperty(this, VSHPROPID_Caption, PropertyValue);
	pProject->Remove(this);
	
    // rename the file
    BOOL fRet = TRUE;
    if (fRenameSameFile)
        fRet = ::MoveFile(strCurrentFilename, strNewFilename);
    else
        fRet = ::DeleteFile(strCurrentFilename);
    if (!fRet)
		hr = HRESULT_FROM_WIN32(GetLastError());

	// Add the renamed node back into the project
	pProject->Add(this);
	pMyProjectHierarchy->OnInvalidateItems(pProject);

    if (FAILED(hr))
    {
        _VxModule.SetErrorInfo(hr,IDS_RENAMEFILEFAILED, 0);
		//set the old name back
		SetFullPath(strCurrentFilename);
		return hr;
    }
	

	// Update SCC status including icon
    // ReDraw will cause GetIconIndex, which updates the glyphs to be called
	// Update
	ReDraw(
		/* bUpdateIcon      (VSHPROPID_IconIndex)      */ TRUE, 
		/* bUpdateStateIcon (VSHPROPID_StateIconIndex) */ TRUE, 
		/* bUpdateText      (VSHPROPID_Caption)		   */ TRUE);

    // Tell packages that care that it happened.
    if (pCVsTrackProjectDocuments2Helper)
    {
        pCVsTrackProjectDocuments2Helper->OnItemRenamed(
            static_cast<CHierNode*>(this),
            pwszFile);
    }

	// tell the extensibility 
	OnItemRenamed(strCurrentFilename);
    OnPropertyChanged(DISPID_VALUE);

    return S_FALSE;

} // CFileVwFileNode::Rename


//-----------------------------------------------------------------------------
// Called after the item is renamed
//-----------------------------------------------------------------------------
void CFileVwFileNode::OnItemRenamed(
	/* [in] */ LPCTSTR pszOldName)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return;

	//Fire an event to extensibility
    CAutomationEvents::FireProjectItemsEvent(
        this,
        CAutomationEvents::ProjectItemsEventsDispIDs::ItemRenamed,
        pszOldName);
}


// =========================================================================
//                                                       Document management


HRESULT CFileVwFileNode::OpenDoc(
	/* [in]  */ BOOL             fNewFile            /*= FALSE*/,
	/* [in]  */ BOOL             fUseOpenWith        /*= FALSE*/,
    /* [in]  */ BOOL             fShow               /*= TRUE */,
	/* [in]  */ REFGUID          rguidLogicalView    /*= LOGVIEWID_Primary*/,
	/* [in]  */ IUnknown *       punkDocDataExisting /*= DOCDATAEXISTING_UNKNOWN*/,
	/* [out] */ IVsWindowFrame** ppWindowFrame       /*= NULL*/)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

	USES_CONVERSION;

	// Get the IVsUIShellOpenDocument service so we can ask it to open a doc window
    IVsUIShellOpenDocument* pIVsUIShellOpenDocument = _VxModule.GetIVsUIShellOpenDocument();
    ExpectedExprRet(pIVsUIShellOpenDocument != NULL);

	CComPtr<IVsWindowFrame> srpIVsWindowFrame;
	CString strFullPath = GetFullPath();

	VSOSEFLAGS openFlags = OSE_ChooseBestStdEditor;

	if(fUseOpenWith)
		openFlags = OSE_UseOpenWithDialog;
    if(fNewFile)
        openFlags |= OSE_OpenAsNewFile;

    ExpectedExprRet(GetCVsHierarchy());
	hr = pIVsUIShellOpenDocument->OpenStandardEditor(
		/* [in]  VSOSEFLAGS   grfOpenStandard           */ openFlags,
		/* [in]  LPCOLESTR    pszMkDocument             */ T2COLE(strFullPath),
		/* [in]  REFGUID      rguidLogicalView          */ rguidLogicalView,
		/* [in]  LPCOLESTR    pszOwnerCaption           */ L"%3",
		/* [in]  IVsUIHierarchy  *pHier                 */ GetCVsHierarchy()->GetIVsUIHierarchy(),
		/* [in]  VSITEMID     itemid                    */ GetVsItemID(),
		/* [in]  IUnknown    *punkDocDataExisting       */ punkDocDataExisting,
		/* [in]  IServiceProvider *pSP                  */ NULL,
		/* [out, retval] IVsWindowFrame **ppWindowFrame */ &srpIVsWindowFrame);

	// Note that for external editors we don't get an srpIVsWindowFrame.
	if(SUCCEEDED(hr) && srpIVsWindowFrame)
	{
		if(fNewFile)
		{
            // SetUntitledDocPath is called by all projects after a new document instance is created.
            // Editors use the same CreateInstance/InitNew design pattern of standard COM objects.
            // Editors can use this method to perform one time initializations that are required after a new
            // document instance was created via IVsEditorFactory::CreateEditorInstance(CEF_CLONEFILE,...).
            // NOTE: Ideally this method would be called InitializeNewDocData but it is too late to rename this method.
            //              Most editors can ignore the parameter passed. It is a legacy of historical insignificance.
			CComVariant var;
			HRESULT hrTemp = srpIVsWindowFrame->GetProperty(VSFPROPID_DocData, &var);
			ASSERT(V_VT(&var) == VT_UNKNOWN && V_UNKNOWN(&var) != NULL);
			if(SUCCEEDED(hrTemp) && V_VT(&var) == VT_UNKNOWN && V_UNKNOWN(&var) != NULL)
			{
				CComPtr<IVsPersistDocData> srpDocData;
				hrTemp = (V_UNKNOWN(&var))->QueryInterface(IID_IVsPersistDocData, (void**)&srpDocData);
				ASSERT(srpDocData);
				if(SUCCEEDED(hrTemp) && srpDocData != NULL)
					srpDocData->SetUntitledDocPath(T2COLE(strFullPath));
			}
		}
			
		// Show window
        if (fShow)
			srpIVsWindowFrame->Show();

		// Return window frame if requested
		if(ppWindowFrame)
			*ppWindowFrame = srpIVsWindowFrame.Detach();
	}

	return hr;
}


HRESULT CFileVwFileNode::OpenDocWithSpecific(
    REFGUID           rguidEditorType, 
    LPCOLESTR         pszPhysicalView,
    REFGUID           rguidLogicalView, 
    IUnknown *        punkDocDataExisting,
    IVsWindowFrame ** ppWindowFrame,        
    BOOL              fShowWindow            /* = TRUE  */ ,
    BOOL              fNewFile               /* = FALSE */ )
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

    IVsUIShellOpenDocument* pVsUIShellOpenDoc = _VxModule.GetIVsUIShellOpenDocument();
    ExpectedExprRet(pVsUIShellOpenDoc != NULL);

    CString strFullPathName = GetFullPath();
    CComPtr<IVsWindowFrame> srpIVsWindowFrame;
    VSOSPEFLAGS grfOpenSpecific = fNewFile ? OSPE_OpenAsNewFile : 0;

    USES_CONVERSION;
    ExpectedExprRet(GetCVsHierarchy());
    hr = pVsUIShellOpenDoc->OpenSpecificEditor(
        /* VSOSPEFLAGS grfOpenSpecific      */ grfOpenSpecific,
        /* LPCOLESTR pszMkDocument          */ T2COLE(strFullPathName),
        /* REFGUID rguidEditorType          */ rguidEditorType,
        /* LPCOLESTR pszPhysicalView        */ pszPhysicalView,
        /* REFGUID rguidLogicalView         */ rguidLogicalView,
        /* LPCOLESTR pszOwnerCaption        */ L"%3",
        /* IVsUIHierarchy *pHier            */ GetCVsHierarchy()->GetIVsUIHierarchy(),
        /* VSITEMID itemid                  */ GetVsItemID(),
        /* IUnknown *punkDocDataExisting    */ punkDocDataExisting,
        /* IServiceProvider *pSPHierContext */ NULL,
        /* IVsWindowFrame **ppWindowFrame   */ &srpIVsWindowFrame);
    IfFailRet(hr);

    if (srpIVsWindowFrame != NULL)
    { 
		if(fNewFile)
		{
            // SetUntitledDocPath is called by all projects after a new document instance is created.
            // Editors use the same CreateInstance/InitNew design pattern of standard COM objects.
            // Editors can use this method to perform one time initializations that are required after a new
            // document instance was created via IVsEditorFactory::CreateEditorInstance(CEF_CLONEFILE,...).
            // NOTE: Ideally this method would be called InitializeNewDocData but it is too late to rename this method.
            //              Most editors can ignore the parameter passed. It is a legacy of historical insignificance.
			CComVariant var;
			HRESULT hrTemp = srpIVsWindowFrame->GetProperty(VSFPROPID_DocData, &var);
			ASSERT(V_VT(&var) == VT_UNKNOWN && V_UNKNOWN(&var) != NULL);
			if(SUCCEEDED(hrTemp) && V_VT(&var) == VT_UNKNOWN && V_UNKNOWN(&var) != NULL)
			{
				CComPtr<IVsPersistDocData> srpDocData;
				hrTemp = (V_UNKNOWN(&var))->QueryInterface(IID_IVsPersistDocData, (void**)&srpDocData);
				ASSERT(srpDocData);
				if(SUCCEEDED(hrTemp) && srpDocData != NULL)
					srpDocData->SetUntitledDocPath(T2COLE(strFullPathName));
			}
		}

        if(fShowWindow)
            srpIVsWindowFrame->Show();
        if(ppWindowFrame)
            *ppWindowFrame = srpIVsWindowFrame.Detach();
    }
    return hr;
}


HRESULT CFileVwFileNode::PreviewDoc(
    /* [in] */ BOOL fPreviewWith)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = S_OK;	
	USES_CONVERSION;

    BOOL        fOpen       = FALSE;
    BOOL        fDirty      = TRUE;
    BOOL        fOpenByUs   = FALSE;
    VSDOCCOOKIE vsDocCookie = VSDOCCOOKIE_NIL;

    hr = GetDocInfo(
        /* [out, opt] BOOL*  pfOpen     */ &fOpen, // true if the doc is opened
        /* [out, opt] BOOL*  pfDirty    */ &fDirty, // true if the doc is dirty
        /* [out, opt] BOOL*  pfOpenByUs */ &fOpenByUs, // true if opened by our project
        /* [out, opt] VSDOCCOOKIE* pVsDocCookie*/ &vsDocCookie);// VSDOCCOOKIE if open
    IfFailRet(hr);
    
    if (fDirty)
    {
        // When Doc is dirty, prompt to save if requested to.
        int msgRet = CApplyToAllMsgBox::DoContextMsgBox(IDS_P_SAVEONPREVIEW, GetName(), IDS_CAPTION_SAVEFILE);

        if (msgRet == IDCANCEL)
            return OLE_E_PROMPTSAVECANCELLED;

        if (msgRet == IDYES)
        {
            // Save.the document
            IVsSolution* pIVsSolution = _VxModule.GetIVsSolution();
            ExpectedExprRet(pIVsSolution != NULL);

            // SaveSolutionElement will call our hierarchies SaveItem method
            hr = pIVsSolution->SaveSolutionElement(
                /* [in] VSSLNSAVEOPTIONS grfSaveOpts*/ SLNSAVEOPT_SaveIfDirty,
                /* [in] IVsHierarchy *pHier         */ NULL,
                /* [in] VSCOOKIE docCookie          */ vsDocCookie);
            _IfFailRet(hr);
        }
    }

	CWaitCursor wc;

	// Figure out which url to use
	CString strFullPath;
	strFullPath = GetFullPath();

	IVsUIShellOpenDocument* pIVsUIShellOpenDocument = _VxModule.GetIVsUIShellOpenDocument();
    ExpectedExprRet(pIVsUIShellOpenDocument != NULL);

    DWORD dwReserved = 0;
	DWORD dwPrevFlags = 0;
	if(fPreviewWith)
		dwPrevFlags |= OSP_UsePreviewWithDialog;
	if(GetExecutionCtx().GetMultiSelect() > 1)
		dwPrevFlags |= OSP_LaunchNewBrowser | OSP_LaunchSystemBrowser;
	return pIVsUIShellOpenDocument->OpenStandardPreviewer(
        /* [in] VSOSPFLAGS ospOpenDocPreviewer*/ dwPrevFlags,
        /* [in] LPCOLESTR pszURL              */ T2COLE(strFullPath),
        /* [in] VSPREVIEWRESOLUTION resolution*/ PR_Default,
        /* [in] DWORD dwReserved              */ dwReserved);
}


HRESULT CFileVwFileNode::GetDocInfo(
    /* [out, opt] */ BOOL*        pfOpen,     // true if the doc is opened
    /* [out, opt] */ BOOL*        pfDirty,    // true if the doc is dirty
    /* [out, opt] */ BOOL*        pfOpenByUs, // true if opened by our project
    /* [out, opt] */ VSDOCCOOKIE* pVsDocCookie)// VSDOCCOOKIE if open
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    if (!pfOpen && !pfDirty && !pfOpenByUs && !pVsDocCookie)
        return S_OK;

    if (pfOpen)       *pfOpen       = FALSE;
    if (pfDirty)      *pfDirty      = FALSE;
    if (pfOpenByUs)   *pfOpenByUs   = FALSE;
    if (pVsDocCookie) *pVsDocCookie = VSDOCCOOKIE_NIL;

    HRESULT hr = S_OK;

    CString strFullName = GetFullPath();

    CComPtr<IVsHierarchy>      srpIVsHierarchy;
    CComPtr<IVsPersistDocData> srpIVsPersistDocData;
    VSITEMID vsitemid       = VSITEMID_NIL;
    VSDOCCOOKIE vsDocCookie = VSDOCCOOKIE_NIL;
    hr = GetRDTDocumentInfo(
        /* [in]  LPCTSTR             pszDocumentName    */ strFullName,
        /* [out] IVsHierarchy**      ppIVsHierarchy     */ &srpIVsHierarchy,
        /* [out] VSITEMID*           pitemid            */ &vsitemid,
        /* [out] IVsPersistDocData** ppIVsPersistDocData*/ &srpIVsPersistDocData,
        /* [out] VSDOCCOOKIE*        pVsDocCookie       */ &vsDocCookie);
    if (FAILED(hr))
        return hr;

    if (!srpIVsHierarchy || (vsDocCookie == VSDOCCOOKIE_NIL))
        return S_OK;

    if (pfOpen)
        *pfOpen = TRUE;
    if (pVsDocCookie)
        *pVsDocCookie = vsDocCookie;

    if (pfOpenByUs)
    {
        ExpectedExprRet(GetCVsHierarchy());
       // check if the doc is opened by another project
        CComPtr<IVsHierarchy> pMyHier = (GetCVsHierarchy()->GetIVsHierarchy());
        CComPtr<IUnknown> punkMyHier;
        pMyHier->QueryInterface(IID_IUnknown, (void **)&punkMyHier);
        CComPtr<IUnknown> punkRDTHier;
        srpIVsHierarchy->QueryInterface(IID_IUnknown, (void **)&punkRDTHier);
        if (punkRDTHier == punkMyHier)
            *pfOpenByUs = TRUE;
    }

    if (pfDirty && srpIVsPersistDocData)
        hr = srpIVsPersistDocData->IsDocDataDirty(pfDirty);

    return S_OK;
}


HRESULT CFileVwFileNode::SaveDoc(
    /* [in] */ VSSLNSAVEOPTIONS grfSaveOpts)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

    BOOL        fOpen       = FALSE;
    BOOL        fDirty      = TRUE;
    BOOL        fOpenByUs   = FALSE;
    VSDOCCOOKIE vsDocCookie = VSDOCCOOKIE_NIL;

    hr = GetDocInfo(
        /* [out, opt] BOOL*  pfOpen     */ &fOpen, // true if the doc is opened
        /* [out, opt] BOOL*  pfDirty    */ &fDirty, // true if the doc is dirty
        /* [out, opt] BOOL*  pfOpenByUs */ &fOpenByUs, // true if opened by our project
        /* [out, opt] VSDOCCOOKIE* pVsDocCookie*/ &vsDocCookie);// VSDOCCOOKIE if open
    IfFailRet(hr);

    if (!fOpenByUs || (vsDocCookie == VSCOOKIE_NIL) )
        return S_OK;

    CComPtr<IVsSolution> pIVsSolution = _VxModule.GetIVsSolution();
    ExpectedExprRet(pIVsSolution != NULL);

    hr = pIVsSolution->SaveSolutionElement(
        /* [in] VSSLNSAVEOPTIONS grfSaveOpts*/ grfSaveOpts, 
        /* [in] IVsHierarchy *pHier         */ NULL, 
        /* [in] VSCOOKIE docCookie          */ vsDocCookie);

    // may return E_ABORT if prompt is cancelled
    return hr;    
}


HRESULT CFileVwFileNode::CloseDoc(
    /* [in] */ VSSLNCLOSEOPTIONS grfCloseOpts = SLNSAVEOPT_NoSave) 
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_OK;

    BOOL        fOpen       = FALSE;
    BOOL        fOpenByUs   = FALSE;
    VSDOCCOOKIE vsDocCookie = VSDOCCOOKIE_NIL;

    hr = GetDocInfo(
        /* [out, opt] BOOL*  pfOpen     */ &fOpen, // true if the doc is opened
        /* [out, opt] BOOL*  pfDirty    */ NULL, // true if the doc is dirty
        /* [out, opt] BOOL*  pfOpenByUs */ &fOpenByUs, // true if opened by our project
        /* [out, opt] VSDOCCOOKIE* pVsDocCookie*/ &vsDocCookie);// VSDOCCOOKIE if open
    IfFailRet(hr);

    if (!fOpenByUs || (vsDocCookie == VSCOOKIE_NIL) )
        return S_OK;

    CComPtr<IVsSolution> pIVsSolution = _VxModule.GetIVsSolution();
    ExpectedExprRet(pIVsSolution != NULL);

    hr = pIVsSolution->CloseSolutionElement(
        /* [in] VSSLNCLOSEOPTIONS grfCloseOpts */ grfCloseOpts, 
        /* [in] IVsHierarchy *pHier            */ NULL, 
        /* [in] VSCOOKIE docCookie             */ vsDocCookie);

    // may return E_ABORT if prompt is cancelled
    return hr;    
}

//                                                       Document management
// =========================================================================
