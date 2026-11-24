
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
	m_ExcludeFromBuild = true;
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
	m_fFireRenameEvent = FALSE;
	// the path should have been checked at this point
	SetFullPath(pszFullPath);	// this call also sets our nodes caption
	m_fFireRenameEvent = TRUE;
	return NOERROR;
}


void CFileVwFileNode::SetFullPath(LPCTSTR pszFullPath) 
{ 
	//Fire an event to extensibility
	if (m_fFireRenameEvent)
	{
        CAutomationEvents::FireProjectItemsEvent(
            this,
            CAutomationEvents::ProjectItemsEventsDispIDs::ItemRenamed,
            CFileVwBaseNode::GetFullPath());
    }

	CFileVwBaseNode::SetFullPath(pszFullPath);

    // compute caption to be used for VSHPROIPD_Caption value
	//		we use filename without path as the item caption
	CString strCaption;
	strCaption = GetFileName();
	SetName(strCaption);
}


HRESULT CFileVwFileNode::Close()
{
    if (m_srpProjectItem != NULL)
        static_cast<CAOProjectItemFile*>((ProjectItem*) m_srpProjectItem)->Close();

    return S_OK;
}

//---------------------------------------------------------------------------
// Write information for node to project file.
//---------------------------------------------------------------------------
HRESULT CFileVwFileNode::Save
(
IVsPropertyStreamOut *pIVsPropertyStreamOut
) 
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
) 
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
	BOOL fLatched = FALSE;

	if(*pguidCmdGroup == guidVSStd97)
	{
		hr = S_OK;
		switch(Cmd.cmdID)
		{
			case cmdidViewCode:
				if (SupportsCodeView())
				{
					fSupported =  TRUE;
					fEnabled = TRUE;
				}
				break;
			case cmdidViewForm:
				if (SupportsDesignView())
				{
					fSupported =  TRUE;
					fEnabled = TRUE;
				}
				break;
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
				fSupported =  TRUE;
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
		if (fLatched)
			Cmd.cmdf |= OLECMDF_LATCHED;
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
			case cmdidViewCode:
				hr = OnCmdViewCode();
				break;
			case cmdidViewForm:
				hr = OnCmdViewForm();
				break;
			case cmdidOpen:
				hr = OnCmdOpen();
				break;
			case cmdidOpenWith:
				hr = OnCmdOpenWith();
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
		hr = OpenDoc(
        	/* [in]  BOOL             fNewFile            = FALSE*/ FALSE,
	        /* [in]  BOOL             fUseOpenWith        = FALSE*/ TRUE
            /* [in]  BOOL             fShow               = TRUE */
	        /* [in]  REFGUID          rguidLogicalView    = LOGVIEWID_Primary*/
	        /* [in]  IUnknown *       punkDocDataExisting = DOCDATAEXISTING_UNKNOWN*/
	        /* [out] IVsWindowFrame** ppWindowFrame       = NULL*/);
	return hr;
}


//-----------------------------------------------------------------------------
// Opens this file with the default editor specified via OpenWith.
//-----------------------------------------------------------------------------
HRESULT CFileVwFileNode::OnCmdOpen()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = E_ABORT;
	if(!GetExecutionCtx().IsCancelled())
    {
        hr = OpenDocWithDefault(
            /* [in] BOOL fUseProjectSpecificEditor */ FALSE,
            /* [in] BOOL fNewFile                  */ FALSE);
    }

	return hr;
}


//-----------------------------------------------------------------------------
// Opens this file with the code editor.
//-----------------------------------------------------------------------------
HRESULT CFileVwFileNode::OnCmdViewCode()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = E_ABORT;
	if(!GetExecutionCtx().IsCancelled())
    {
		hr = OpenDocWithProjectSpecific(
            /* [in] REFGUID rguidLogicalView */ LOGVIEWID_Code,
            /* [in] BOOL    fNewFile         */ FALSE);
    }
	return hr;
}

//-----------------------------------------------------------------------------
// Opens this file with the GUI designer.
//-----------------------------------------------------------------------------
HRESULT CFileVwFileNode::OnCmdViewForm()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = E_ABORT;
	if(!GetExecutionCtx().IsCancelled())
    {
		hr = OpenDocWithProjectSpecific(
            /* [in] REFGUID rguidLogicalView */ LOGVIEWID_Designer,
            /* [in] BOOL    fNewFile         */ FALSE);
    }
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

  return E_NOTIMPL;
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
		return E_FAIL;
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

    HRESULT hr = OnPropertyChanged(DISPID_FigPrjSourceFile_ReadOnly, FALSE /*fDirtyPtoject*/);
    ASSERT(SUCCEEDED(hr));

    return S_OK;
}

STDMETHODIMP CFileVwFileNode::get_ExcludeFromBuild(VARIANT_BOOL *pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pVal);
	if (!m_ExcludeFromBuild) *pVal = VARIANT_FALSE;
	if (m_ExcludeFromBuild) *pVal = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CFileVwFileNode::put_ExcludeFromBuild(VARIANT_BOOL pVal)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // If we can't edit the project file or it's checked in and we
    // don't want to check it out then we do not update the property.
    if ( !static_cast<CMyProjectHierarchy*>(GetCVsHierarchy())->QueryEditProjectFile() )
    {
        return OLE_E_PROMPTSAVECANCELLED;
    }

	if (pVal == VARIANT_FALSE) m_ExcludeFromBuild = false;
	if (pVal == VARIANT_TRUE) m_ExcludeFromBuild = true;
    HRESULT hr = OnPropertyChanged(DISPID_FigPrjSourceFile_ExcludeFromBuild);
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
    ExpectedPtrRet(pbstrRetval);
    InitParam(pbstrRetval);

    CComBSTR cbstrCATID(prjCATIDFigPrjFileBrowseObject);
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


// =========================================================================
//                                                       Document management

HRESULT CFileVwFileNode::OpenDocWithDefault(
    /* [in] */ BOOL fUseProjectSpecificEditor,
    /* [in] */ BOOL fNewFile)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = S_OK;

    if (!fUseProjectSpecificEditor)
	{
        // - check if global standard editor should be used
	    CString strFullPath = GetFullPath();

		// the project is expected to persist on a per file-type 
        // (file extension) basis whether the Global standard editor 
        // should be used or the Project Specific editor should be used.
        CComPtr<IVsProjectSpecificEditorMap2> srpIVsProjectSpecificEditorMap2;
        CVsHierarchy* pCVsHierarchy = GetCVsHierarchy();
        ExpectedExprRet(pCVsHierarchy);

        hr = pCVsHierarchy->QueryInterface(IID_IVsProjectSpecificEditorMap2, (void**)&srpIVsProjectSpecificEditorMap2);
        if (SUCCEEDED(hr) && (srpIVsProjectSpecificEditorMap2 != NULL) )
        {   
            CComVariant cvar;
            hr = srpIVsProjectSpecificEditorMap2->GetSpecificEditorProperty(
                T2COLE(strFullPath), 
                VSPSEPROPID_UseGlobalEditorByDefault, 
                &cvar);
            if (SUCCEEDED(hr))
            {
                ASSERT(cvar.vt == VT_BOOL);
                fUseProjectSpecificEditor = (V_BOOL(&cvar) == VARIANT_FALSE);
            }        
            hr = S_OK;
        }
	}

    if(fUseProjectSpecificEditor && SupportsDesignView() )
    {
        hr = OpenDocWithProjectSpecific(
            /* [in] REFGUID rguidLogicalView*/ LOGVIEWID_Designer,
            /* [in] BOOL    fNewFile        */ fNewFile);
    }
    else if(fUseProjectSpecificEditor && SupportsCodeView() )
    {
        hr = OpenDocWithProjectSpecific(
            /* [in] REFGUID rguidLogicalView*/ LOGVIEWID_Code,
            /* [in] BOOL    fNewFile        */ fNewFile);
    }
    else
    {
        hr = OpenDoc(
		    /* [in]  BOOL       fNewFile            = FALSE*/ fNewFile
		    /* [in]  BOOL       fUseOpenWith        = FALSE*/
            /* [in]  BOOL       fShow               = TRUE */
		    /* [in]  REFGUID    rguidLogicalView    = LOGVIEWID_Primary*/
		    /* [in]  IUnknown * punkDocDataExisting = DOCDATAEXISTING_UNKNOWN*/
		    /* [out] IVsWindowFrame** ppWindowFrame = NULL*/);
    }

	return hr;
}


HRESULT CFileVwFileNode::OpenDocWithProjectSpecific(   
    /* [in] */ REFGUID rguidLogicalView,
    /* [in] */ BOOL    fNewFile)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

	HRESULT hr = S_OK;

    // check if we have project specific editor
    CComPtr<IVsProjectSpecificEditorMap> srpIVsProjectSpecificEditorMap;
    CVsHierarchy* pCVsHierarchy = GetCVsHierarchy();  
    ExpectedExprRet(pCVsHierarchy);

    // For designer/code we look up in the editor specific project map for the 
    // correct editor. We want to force the editor to the one for the project
    GUID guidProjectSpecificEditor = GUID_NULL;
    hr = pCVsHierarchy->QueryInterface(IID_IVsProjectSpecificEditorMap, (void**)&srpIVsProjectSpecificEditorMap);
    if ( SUCCEEDED(hr) && (srpIVsProjectSpecificEditorMap != NULL) )
    {
	    CString strFullPath = GetFullPath();
        hr = srpIVsProjectSpecificEditorMap->GetSpecificEditorType(
                /* [in]  LPCOLESTR  */  T2COLE(strFullPath), 
                /* [out] GUID *     */  &guidProjectSpecificEditor);
    }
    if (guidProjectSpecificEditor != GUID_NULL)
    {
        hr = OpenDocWithSpecific(
            /* REFGUID           rguidEditorType    */ guidProjectSpecificEditor, 
            /* LPCOLESTR         pszPhysicalView    */ NULL,
            /* REFGUID           rguidLogicalView   */ rguidLogicalView, 
            /* IUnknown *        punkDocDataExisting*/ DOCDATAEXISTING_UNKNOWN,
            /* IVsWindowFrame ** ppWindowFrame      */ NULL,     
            /* BOOL              fShowWindow = TRUE */ TRUE,
            /* BOOL              fNewFile = FALSE   */ fNewFile);
    }
    else
    {
        hr = OpenDoc(
		    /* [in]  BOOL       fNewFile            */ fNewFile,
		    /* [in]  BOOL       fUseOpenWith        */ FALSE,
            /* [in]  BOOL       fShow               */ TRUE,
		    /* [in]  REFGUID    rguidLogicalView    */ rguidLogicalView
		    /* [in]  IUnknown * punkDocDataExisting = DOCDATAEXISTING_UNKNOWN*/
		    /* [out] IVsWindowFrame** ppWindowFrame = NULL*/);
    }

	return hr;
}


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


    // LOGVIEWID_ProjectSpecific is passed when the user chooses the 
    // "(Project default editor)" option in the OpenWith dialog. In 
    // this case we should always use the project specific editor.
	if (LOGVIEWID_ProjectSpecificEditor == rguidLogicalView)
        return OpenDocWithDefault(
            /* [in] BOOL fUseProjectSpecificEditor */ TRUE,
            /* [in] BOOL fNewFile                  */ FALSE);

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
        hr = pMyHier->QueryInterface(IID_IUnknown, (void **)&punkMyHier);
        if ( FAILED(hr) )
            return hr;
        CComPtr<IUnknown> punkRDTHier;
        hr = srpIVsHierarchy->QueryInterface(IID_IUnknown, (void **)&punkRDTHier);
        if ( FAILED(hr) )
            return hr;
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
