
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSSelection.cpp
//
// Implementation of CFileSystemSelection
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "FSSelection.h"

//*****************************************************************************
// CFileSystemSelection Constructor/Destructor
//*****************************************************************************

CFileSystemSelection::CFileSystemSelection()
{
    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Creating CFileSystemSelection: 0x%X\n"), this);
    }

    m_pSelFolder = NULL;
    m_pSelFile = NULL;
}

CFileSystemSelection::~CFileSystemSelection()
{
    if (VSFSWITCH(g_fFileExObjCtorDtor))
    {
        ATLTRACE(_T("Destructing CFileSystemSelection: 0x%X\n"), this);
    }
}


//*****************************************************************************
// CFileSystemSelection IFileSystemSelectionContainer Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemSelection::Initialize(
                    /*[in]*/ IServiceProvider* pSP)
{
    _ASSERTE(pSP);
	if (!pSP)
		return E_POINTER;

    _ASSERTE(!m_srpSelTracker);

    HRESULT hr;

    hr = pSP->QueryService(SID_STrackSelection, IID_ITrackSelection,
                           (void**)&m_srpSelTracker);
    IfFailGo(hr);

OnError:
    return hr;
}

STDMETHODIMP CFileSystemSelection::Close(void)
{
    if (m_srpSelTracker)
    {
        m_srpSelTracker->OnSelectChange(NULL);
        m_srpSelTracker.Release();
    }

    m_pSelFolder = NULL;
    m_pSelFile = NULL;
    return S_OK;
}

STDMETHODIMP CFileSystemSelection::UpdateFolderSelection(
                    /*[in]*/ DWORD_PTR dwFolderPtr)
{
    _ASSERTE(m_pSelFile == NULL);

    m_pSelFolder = (CFileSystemFolderItem*)dwFolderPtr;
    if (m_srpSelTracker)
        m_srpSelTracker->OnSelectChange(static_cast<ISelectionContainer*>(this));

    return S_OK;
}

STDMETHODIMP CFileSystemSelection::UpdateFileSelection(
                    /*[in]*/ DWORD_PTR dwFilePtr)
{
    _ASSERTE(m_pSelFolder == NULL);

    m_pSelFile = (CFileSystemFileItem*)dwFilePtr;
    if (m_srpSelTracker)
        m_srpSelTracker->OnSelectChange(static_cast<ISelectionContainer*>(this));

    return S_OK;
}


//*****************************************************************************
// CFileSystemSelection ISelectionContainer Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemSelection::CountObjects(
                    /*[in] */ DWORD  dwFlags, 
                    /*[out]*/ ULONG* pc)
{
    ExpectedPtrRet(pc);
    *pc = 0;

    if (m_pSelFolder || m_pSelFile)
        *pc = 1;

    return S_OK;
}

STDMETHODIMP CFileSystemSelection::GetObjects(
                    /*[in] */ DWORD      dwFlags, 
                    /*[in] */ ULONG      cObjects,
                    /*[out]*/ IUnknown** apUnkObjects)
{
    ExpectedExprRet(cObjects == 1);
    ExpectedPtrRet(apUnkObjects);

    apUnkObjects[0] = static_cast<IDispatch*>(this);
    apUnkObjects[0]->AddRef();
    return S_OK;
}

STDMETHODIMP CFileSystemSelection::SelectObjects(
                    /*[in]*/ ULONG      cSelect,
                    /*[in]*/ IUnknown** apUnkSelect,
                    /*[in]*/ DWORD      dwFlags)
{
    return S_OK;
}


//*****************************************************************************
// CFileSystemSelection ICategorizeProperties Implementation
//*****************************************************************************

static const PROPCAT PROPCAT_General = 0;
static const PROPCAT PROPCAT_Attribs = 1;

STDMETHODIMP CFileSystemSelection::MapPropertyToCategory(
                    /*[in] */ DISPID   dispid,
                    /*[out]*/ PROPCAT* ppropcat)
{
    ExpectedPtrRet(ppropcat);

    switch (dispid)
    {
        case DISPID_FileEx_ReadOnly:    // ReadOnly
        case DISPID_FileEx_Hidden:      // Hidden
        case DISPID_FileEx_Compressed:  // Compressed
            *ppropcat = PROPCAT_Attribs;
            break;
        default:
            *ppropcat = PROPCAT_General;
            break;
    }
    return S_OK;
}

STDMETHODIMP CFileSystemSelection::GetCategoryName(
                    /*[in] */ PROPCAT propcat, 
                    /*[in] */ LCID    lcid,
                    /*[out]*/ BSTR*   pbstrName)
{
    ExpectedPtrRet(pbstrName);
    ExpectedExprRet((propcat == PROPCAT_General) ||
                    (propcat == PROPCAT_Attribs));

    InitParam(pbstrName);
    
    CString strCategory;
    strCategory.LoadString(IDS_PROPCAT_GENERAL + propcat);
    *pbstrName = strCategory.AllocSysString();

    return *pbstrName ? S_OK : E_OUTOFMEMORY;
}


//*****************************************************************************
// CFileSystemSelection IFileSystemSelection Implementation
//*****************************************************************************

STDMETHODIMP CFileSystemSelection::get_Name(
                    /*[out,ret]*/ BSTR* pbstrName)
{
    ExpectedPtrRet(pbstrName);

    HRESULT hr = E_OUTOFMEMORY;
    InitParam(pbstrName);

    if (m_pSelFolder)
    {
        USES_CONVERSION;

        *pbstrName = SysAllocString(T2COLE(m_pSelFolder->GetFolderText()));
        if (*pbstrName)
            hr = S_OK;
    }
    else if (m_pSelFile)
    {
        USES_CONVERSION;

        *pbstrName = SysAllocString(T2COLE(m_pSelFile->GetFileName()));
        if (*pbstrName)
            hr = S_OK;
    }

    return hr;
}

STDMETHODIMP CFileSystemSelection::get_Path(
                    /*[out,ret]*/ BSTR* pbstrPath)
{
    ExpectedPtrRet(pbstrPath);

    HRESULT hr = E_OUTOFMEMORY;
    InitParam(pbstrPath);
   
    if (m_pSelFolder)
    {
        CString strPath;

        m_pSelFolder->GetFolderPath(strPath);
        *pbstrPath = strPath.AllocSysString();
        if (*pbstrPath)
            hr = S_OK;
    }
    else if (m_pSelFile)
    {
        CString strPath;

        m_pSelFile->GetFilePath(strPath);
        *pbstrPath = strPath.AllocSysString();
        if (*pbstrPath)
            hr = S_OK;
    }

    return hr;
}

STDMETHODIMP CFileSystemSelection::get_Type(
                    /*[out,ret]*/ BSTR* pbstrType)
{
    ExpectedPtrRet(pbstrType);

    HRESULT hr = E_OUTOFMEMORY;
    InitParam(pbstrType);

    if (m_pSelFolder)
    {
        CString strType;
        int nType = m_pSelFolder->GetFolderType();
        int nID;

        switch (nType)
        {
            case CFileSystemFolderItem::fsiDrive:
                nID = IDS_FILESYS_FOLDER_DRIVE;
                break;
            case CFileSystemFolderItem::fsiShortcut:
                nID = IDS_FILESYS_FOLDER_SHORTCUT;
                break;
            case CFileSystemFolderItem::fsiShortcutSubFolder:
                nID = IDS_FILESYS_FOLDER_SHFOLDER;
                break;
            case CFileSystemFolderItem::fsiFolder:
            default:
                nID = IDS_FILESYS_FOLDER_FOLDER;
                break;
        }

        strType.LoadString(nID);
        *pbstrType = strType.AllocSysString();
        if (*pbstrType)
            hr = S_OK;
    }
    else if (m_pSelFile)
    {
        USES_CONVERSION;

        LPCTSTR lpszType;

        lpszType = g_ExtMgr.GetExtensionDescription(m_pSelFile);
        _ASSERTE(lpszType);

        *pbstrType = SysAllocString(T2COLE(lpszType));
        if (*pbstrType)
            hr = S_OK;
    }

    return hr;
}

STDMETHODIMP CFileSystemSelection::get_Size(
                    /*[out,ret]*/ BSTR* pbstrSize)
{
    ExpectedPtrRet(pbstrSize);

    HRESULT hr = S_OK;
    InitParam(pbstrSize);

    if (m_pSelFile)
    {
        WCHAR* wszUnit = NULL;

        switch (m_pSelFile->GetSizeType())
        {
            case CFileSystemFileItem::sizeBytes:
                wszUnit = L"bytes";
                break;
            case CFileSystemFileItem::sizeKB:
                wszUnit = L"KB";
                break;
            case CFileSystemFileItem::sizeMB:
                wszUnit = L"MB";
                break;
            case CFileSystemFileItem::sizeGB:
                wszUnit = L"GB";
                break;
        }
        _ASSERTE(wszUnit);

        WCHAR   wszSize[24];
        swprintf(wszSize, NUMBER_OF(wszSize), L"%d %s", m_pSelFile->GetSize(), wszUnit);
        *pbstrSize = SysAllocString(wszSize);
        if (*pbstrSize)
        {
            hr = S_OK;
        }
        else
            hr = E_OUTOFMEMORY;
    }

    return hr;
}

STDMETHODIMP CFileSystemSelection::get_ReadOnly(
                    /*[out,ret]*/ VARIANT_BOOL* pfReadOnly)
{
    ExpectedPtrRet(pfReadOnly);

    HRESULT hr = E_FAIL;

    if (m_pSelFolder)
    {
        BOOL fReadOnly = m_pSelFolder->IsReadOnly();
        *pfReadOnly = fReadOnly ? VARIANT_TRUE : VARIANT_FALSE;
        hr = S_OK;
    }
    else if (m_pSelFile)
    {
        BOOL fReadOnly = m_pSelFile->IsReadOnly();
        *pfReadOnly = fReadOnly ? VARIANT_TRUE : VARIANT_FALSE;
        hr = S_OK;
    }

    return hr;
}

STDMETHODIMP CFileSystemSelection::get_Hidden(
                    /*[out,ret]*/ VARIANT_BOOL* pfHidden)
{
    ExpectedPtrRet(pfHidden);

    HRESULT hr = E_FAIL;

    if (m_pSelFolder)
    {
        BOOL fHidden = m_pSelFolder->IsHidden();
        *pfHidden = fHidden ? VARIANT_TRUE : VARIANT_FALSE;
        hr = S_OK;
    }
    else if (m_pSelFile)
    {
        BOOL fHidden = m_pSelFile->IsHidden();
        *pfHidden = fHidden ? VARIANT_TRUE : VARIANT_FALSE;
        hr = S_OK;
    }

    return hr;
}

STDMETHODIMP CFileSystemSelection::get_Compressed(
                    /*[out,ret]*/ VARIANT_BOOL* pfCompressed)
{
    ExpectedPtrRet(pfCompressed);

    HRESULT hr = E_FAIL;

    if (m_pSelFolder)
    {
        BOOL fCompressed = m_pSelFolder->IsCompressed();
        *pfCompressed = fCompressed ? VARIANT_TRUE : VARIANT_FALSE;
        hr = S_OK;
    }
    else if (m_pSelFile)
    {
        BOOL fCompressed = m_pSelFile->IsCompressed();
        *pfCompressed = fCompressed ? VARIANT_TRUE : VARIANT_FALSE;
        hr = S_OK;
    }

    return hr;
}
