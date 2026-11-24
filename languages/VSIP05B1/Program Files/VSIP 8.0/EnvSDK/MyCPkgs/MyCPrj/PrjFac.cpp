
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// vsprjfac.cpp : Implementation of CMyProjectFactory and interfaces

#include "stdafx.h"
#include "PrjInc.h" 

// =========================================================================
//                                                 construct, init, destruct
CMyProjectFactory::CMyProjectFactory(void)
{
	ATLTRACE(TEXT("CMyProjectFactory created!\n"));
}


CMyProjectFactory::~CMyProjectFactory(void)
{
	ATLTRACE(TEXT("CMyProjectFactory destroyed!\n"));
}
//                                                 construct, init, destruct
// =========================================================================


// =========================================================================
//                                                         IVsProjectFactory
HRESULT CMyProjectFactory::CanCreateProject(
    /* [in]  */ LPCOLESTR pszFilename,
    /* [in]  */ DWORD     grfCreateProj,
    /* [out] */ BOOL *    pfCanCreate)
{
    ExpectedPtrRet(pfCanCreate);

	// Implement this when we can not create a project.
	*pfCanCreate = TRUE;
	return S_OK;
}


HRESULT CMyProjectFactory::CreateProject(
    /* [in]  */ LPCOLESTR                   pszFilename,
    /* [in]  */ LPCOLESTR                   pszLocation,
    /* [in]  */ LPCOLESTR                   pszName,
    /* [in]  */ VSCREATEPROJFLAGS           grfCreateFlags,
    /* [in]  */ REFIID                      iidProject,
    /* [out, iid_is(iidProject)]*/ void **  ppvProject,
    /* [out] */ BOOL *                      pfCanceled)
{

    HRESULT hr = S_OK;

    // if opening an existing project, check for owner key
    CString strOwnerKey;
	if(grfCreateFlags & CPF_OPENFILE)
	{
        ExpectedExprRet(pszFilename != NULL);
        hr = GetPreCreateInfoFromProjectFile(pszFilename, strOwnerKey);
        // if fail - assume no owner key and continue
    }

    if (strOwnerKey.GetLength() == 0)
    {
        // we do not have owner - go to initialization
        return InitializeForOwner(
            /* [in]  LPCOLESTR                 pszFilename*/ pszFilename,
            /* [in]  LPCOLESTR                 pszLocation*/ pszLocation,
            /* [in]  LPCOLESTR                 pszName    */ pszName,
            /* [in]  VSCREATEPROJFLAGS      grfCreateFlags*/ grfCreateFlags,
            /* [in]  REFIID                    iidProject */ iidProject,
            /* [in]  VSOWNEDPROJECTOBJECT      cookie     */ NULL,    
            /* [out, iid_is(iidProject)] void** ppvProject*/ ppvProject,
            /* [out] BOOL*                     pfCanceled */ pfCanceled);
    }

    // We have found an owner key. In this case create the owner 
    CLSID   guidOwnerProject;
    hr = CLSIDFromString(T2OLE((LPTSTR)(LPCTSTR)strOwnerKey), &guidOwnerProject);
    ASSERT(SUCCEEDED(hr));
    if (SUCCEEDED(hr))
    {
        // Get the owners project factory and use that to open/create the project
        CComPtr<IVsProjectFactory>    pIVsProjectFactory_Owner;
        IVsSolution * pIVsSolution = _VxModule.GetIVsSolution();
        ASSERT(pIVsSolution != NULL);
        if (pIVsSolution != NULL)
        {
            hr = pIVsSolution->GetProjectFactory(
                /* [in] DWORD dwReserved                     */ 0, 
                /* [in, out] GUID *pguidProjectType          */ &guidOwnerProject, 
                /* [in] LPCOLESTR pszMkProject               */ pszFilename,
                /* [out] IVsProjectFactory **ppProjectFactory*/ &pIVsProjectFactory_Owner);
            ASSERT(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                return pIVsProjectFactory_Owner->CreateProject(
                    /* [in]  LPCOLESTR              pszFilename   */ pszFilename,
                    /* [in]  LPCOLESTR              pszLocation   */ pszLocation,
                    /* [in]  LPCOLESTR              pszName       */ pszName,
                    /* [in]  VSCREATEPROJFLAGS      grfCreateFlags*/ grfCreateFlags,
                    /* [in]  REFIID                     iidProject*/ iidProject,
                    /* [out, iid_is(iidProject)]void ** ppvProject*/ ppvProject,
                    /* [out] BOOL *                     pfCanceled*/ pfCanceled);
            }
        }
    }

    // If we got here we couldn't get/create the owner project 
    // set an appropritate error.
    LUtilSetErrString(IDS_E_OWNERPROJECTNOTFOUND);
    return E_FAIL;
}


STDMETHODIMP CMyProjectFactory::SetSite(
			/* [in] */ IServiceProvider *pSP)
{
	return S_OK;
}


STDMETHODIMP CMyProjectFactory::Close(void)
{
	return S_OK;
}
//                                                         IVsProjectFactory
// =========================================================================


// =========================================================================
STDMETHODIMP CMyProjectFactory::PreCreateForOwner( 
    /* [in]  */ IUnknown                 *pUnkOwner,
    /* [out] */ IUnknown                 **ppUnkInner,
    /* [out] */ VSOWNEDPROJECTOBJECT*    pCookie )
{
    ExpectedPtrRet(pUnkOwner);
    ExpectedPtrRet(ppUnkInner); 
    InitParam(ppUnkInner);
    ExpectedPtrRet(pCookie);
    InitParam(pCookie);

    HRESULT hr = S_OK;

    // create an Aggregated version of our project hierarchy
    CComPolyObject<CMyProjectHierarchy> *pAggHier;
    hr = CComPolyObject<CMyProjectHierarchy>::CreateInstance(pUnkOwner, &pAggHier);
    IfFailRet(hr);

    CMyProjectHierarchy *pHier;  // created with Ref count 0
    //
    // assign pWebHier to the inner object
    //
    pHier = &(pAggHier->m_contained);

    pHier->AddRef(); // addref to keep alive - don't forget to release this ref in Initialize for owner

    // get the inner IUnknown
    if( SUCCEEDED( hr = pAggHier->QueryInterface( IID_IUnknown, (void**)ppUnkInner ) ) )
    {
        *pCookie = (VSOWNEDPROJECTOBJECT)(pHier);
    }
    else
    {
        // destroy the pAggHier (balances AddRef above)
        pHier->Release();
    }

    return hr;
}


STDMETHODIMP CMyProjectFactory::InitializeForOwner( 
    /* [in]  */ LPCOLESTR                 pszFilename,
    /* [in]  */ LPCOLESTR                 pszLocation,
    /* [in]  */ LPCOLESTR                 pszName,
    /* [in]  */ VSCREATEPROJFLAGS         grfCreateFlags,
    /* [in]  */ REFIID                    iidProject,
    /* [in]  */ VSOWNEDPROJECTOBJECT      cookie,    
    /* [out, iid_is(iidProject)] */void** ppvProject,
    /* [out] */ BOOL*                     pfCanceled)
{ 
    ExpectedPtrRet(pszFilename);
    ExpectedPtrRet(ppvProject);
    InitParam(ppvProject);
    ExpectedPtrRet(pfCanceled);
    InitParamTo(pfCanceled, FALSE)

    HRESULT hr = S_OK;
	CStatusBarMsg(IDS_PROJ_OPEN_WAIT);

	// Compute the project name (caption) and FullPath to the project file 
    // being created. 
	CString strProjName; //the name of the project without a leading path or extension.
	CString strProjFullPath;
	CString strProjLocation;

	// In the open an existing project case pszFilename will be a full path to 
	// the existing project file to be opened and pszName/pszLocation will be NULL. 
	// In the create a new project case pszFilename will be the full path to the template
	// file to be cloned and pszName/pszLocation will be non-NULL pointing to the name
	// and location of the project to be created. 
	CalculateNames(	pszFilename, pszName, pszLocation, strProjFullPath, strProjName, strProjLocation);

    CMyProjectHierarchy* pHier;
	if( NULL != cookie )
	{
	    // Attach to an existing hierarchy
        // Do not AddRef - PreCreateForOwner did AddRef
		pHier=(CMyProjectHierarchy*)(cookie);
	}
	else
	{
		CComObject<CMyProjectHierarchy> *pNewHier;  // created with Ref count 0
		hr = CComObject<CMyProjectHierarchy>::CreateInstance(&pNewHier);
        IfFailRet(hr);
        ExpectedExprRet(pNewHier != NULL);

		// we do AddRef here to keep us alive during initialization
        pHier = pNewHier;
        pHier->AddRef();
	}

	// call SetSite
	hr = pHier->SetSite(_VxModule.GetModuleSite());
    IfFailGo(hr);

	// Init the hierarchy 
	BOOL fNewProject;
	if(grfCreateFlags & CPF_OPENFILE)
	{
		fNewProject = FALSE;
	}
	else if(grfCreateFlags & CPF_CLONEFILE)
	{	
        // Clone existing template.
		fNewProject = TRUE;
        // first create the folder if itdoes not exist
        if(!strProjLocation.IsEmpty() && !LUtilDirExists(strProjLocation))
        {
            if (!UtilCreateDirectory(strProjLocation))
            {
                hr = HRESULT_FROM_WIN32(GetLastError());
                IfFailGo(hr);
            }
        }

        if (!CopyFile(OLE2CT(pszFilename), strProjFullPath, TRUE))
        {
                hr = HRESULT_FROM_WIN32(GetLastError());
                IfFailGo(hr);
        }

        // template was read-only, but our file should not be
        if (!SetFileAttributes(strProjFullPath, FILE_ATTRIBUTE_ARCHIVE))
        {
                hr = HRESULT_FROM_WIN32(GetLastError());
                IfFailGo(hr);
        }
	}
	else
	{	// Don't support other kinds of project creation.
		ASSERT(FALSE);
		hr = E_INVALIDARG;
        goto Error;
	}

	hr = pHier->Init(strProjName, strProjFullPath, strProjLocation, fNewProject, pfCanceled);

	// if all that succeeded hand it out (it's ref-count is 1 right now)
	if (SUCCEEDED(hr) && (!*pfCanceled))
	{
	    // Return the interface requested. 
        // Note that if successful it addrefs so we still need to do a release 
        // on pHier. 
        // If the QI fails, we end up doing the final release on pHier which 
        // will also free our project node which has a ref count of 1 at this point
		hr = pHier->QueryInterface(iidProject,(void**)ppvProject);
	}
	else
	{
		if (pHier)
			pHier->Close();
	}

Error:

    // balance AddRef we did when the hierarchy was created
	if (pHier)
        pHier->Release();  

	return hr;
}


//                                                    IVsOwnedProjectFactory
// =========================================================================


HRESULT CMyProjectFactory::GetPreCreateInfoFromProjectFile(
    /* [in]  */ LPCTSTR  pszFileName,
    /* [out] */ CString& strOwnerKey)
{
    ExpectedPtrRet(pszFileName);

    HRESULT hr    = S_OK;
    BOOL    fDone = FALSE;

	CComPtr<IVsStructuredFileIO> srpIVsStructuredFileIO;
	hr = _VxModule.QueryService(SID_SVsStructuredFileIO, IID_IVsStructuredFileIO, (void **)&srpIVsStructuredFileIO);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsStructuredFileIO != NULL);

	ULONG nFormatIndex;
	CComPtr<IVsPropertyFileIn> srpIVsPropertyFileIn_Outer;
	CComBSTR cbstrFormatVersion;
	hr = srpIVsStructuredFileIO->OpenExisting(
        /* [in] LPCOLESTR szFileName                    */ pszFileName,
        /* [in] DWORD dwShareMode                       */ FILE_SHARE_READ,
        /* [in] DWORD dwCreationDisposition             */ OPEN_EXISTING,
        /* [in] DWORD dwFlagsAndAttributes              */ FILE_FLAG_SEQUENTIAL_SCAN,
        /* [in] IVsStructuredFileIOHelper *p            */ NULL ,
        /* [out] ULONG *pnFormatIndex                   */ &nFormatIndex,
        /* [out] IVsPropertyFileIn **ppIVsPropertyFileIn*/ &srpIVsPropertyFileIn_Outer,
        /* [optional][out] BSTR *pbstrFormatVersion     */ &cbstrFormatVersion);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsPropertyFileIn_Outer != NULL);

    // read the sections
	for (;;)
	{
		WCHAR rgwchSectionName[512];
		CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamIn_Inner;
		VSPROPERTYSTREAMPROPERTYTYPE vspspt;
		CComVariant cvarValue;
		hr = srpIVsPropertyFileIn_Outer->Read(
			/*[in]      ULONG cchPropertyName                */ NUMBER_OF(rgwchSectionName),
			/*[in, out] OLECHAR szPropertyName[]             */ rgwchSectionName,
			/*[out]     ULONG *pcchPropertyNameActual        */ NULL,
			/*[out]     VSPROPERTYSTREAMPROPERTYTYPE *pvspspt*/ &vspspt,
			/*[out]     VARIANT *pvarValue                   */ &cvarValue,
			/*[in]      IErrorLog *pIErrorLog                */ NULL);
		ASSERT(SUCCEEDED(hr));
		if (FAILED(hr))
			break;

		if (rgwchSectionName[0] == L'\0')
			break;

		if (vspspt != VSPSPT_PROPERTY_SECTION || cvarValue.vt != VT_UNKNOWN)
		{
			VSASSERT(cvarValue.vt == VT_UNKNOWN, _T("Property stream implementation error: property section vt != VT_UNKNOWN"));
			hr = E_UNEXPECTED;
            break;
		}

		hr = cvarValue.punkVal->QueryInterface(IID_IVsPropertyStreamIn, (void **) &srpIVsPropertyStreamIn_Inner);
		ASSERT(SUCCEEDED(hr));
        ASSERT(srpIVsPropertyStreamIn_Inner != NULL);
		if (FAILED(hr) || (srpIVsPropertyStreamIn_Inner == NULL) )
			break;

		if (_wcsicmp(rgwchSectionName, STR_GENERALSECTION) == 0)
        {
	        for (;;)
	        {
		        CComPtr<IVsPropertyStreamIn> srpIVsPropertyStreamIn;
		        WCHAR rgwchPropName[_MAX_PATH];
		        CComVariant cvarValue;

		        hr = srpIVsPropertyStreamIn_Inner->Read(
                    NUMBER_OF(rgwchPropName), 
                    rgwchPropName, 
                    NULL, 
                    &vspspt, 
                    &cvarValue, 
                    NULL);
		        ASSERT(SUCCEEDED(hr));
		        if (FAILED(hr))
			        break;

		        if (rgwchPropName[0] == L'\0')
			        break;

		        if (vspspt != VSPSPT_SIMPLE || cvarValue.vt != VT_BSTR)
		        {
			        ASSERT(vspspt == VSPSPT_SIMPLE && cvarValue.vt == VT_BSTR);
                    hr = E_UNEXPECTED;
			        break;
		        }

		        if (_wcsicmp(rgwchPropName, STR_OWNERKEY) == 0)
                {
			        strOwnerKey = cvarValue.bstrVal;
                    break;
                }
	        }
            fDone = TRUE;
        }

		if (srpIVsPropertyStreamIn_Inner != NULL)
		{
			hr = srpIVsPropertyStreamIn_Inner->SkipToEnd();
			if (FAILED(hr))
				break;
		}

        if (fDone)
            break;
	}

    srpIVsPropertyFileIn_Outer->SkipToEnd();
    srpIVsPropertyFileIn_Outer->Close();

	return hr;
}


void CMyProjectFactory::CalculateNames(
    LPCOLESTR pszFilename,
    LPCOLESTR pszName,
    LPCOLESTR pszLocation,
    CString& strProjFullPath,
    CString& strProjName,
    CString& strProjLocation)
{
	if (pszName && pszLocation)
	{
		strProjLocation = pszLocation;
		strProjName = pszName;
		strProjFullPath = strProjLocation + strProjName;

		// If the Name has a .mycp on the end, remove it.
		int index = strProjName.Find(TEXT(".mycp"));
		if (index != -1)
		{
			strProjName = strProjName.Left(index);
		}
	}
	else if (pszFilename)
	{
		strProjFullPath = pszFilename;
		// Split up the pathname for to extract filename for our item Name and SaveName
		TCHAR szDrive[_MAX_DRIVE];
		TCHAR szDir[_MAX_DIR];
		TCHAR szFName[_MAX_FNAME];
		TCHAR szExt[_MAX_EXT];

		_tsplitpath(strProjFullPath, szDrive, szDir, szFName, szExt);

		strProjName = szFName;
		strProjLocation = szDrive;
		strProjLocation += szDir;
	}
	else
	{
		ASSERT(FALSE);
	}
}