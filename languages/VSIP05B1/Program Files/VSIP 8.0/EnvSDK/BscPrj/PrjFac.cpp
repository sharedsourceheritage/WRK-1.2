
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PrjFac.cpp : Implementation of CMyProjectFactory and interfaces

#include "stdafx.h"
#include "vspkg.h"
#include "PrjFac.h"
#include "PrjHier.h"

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
    ExpectedPtrRet(pfCanceled);
    ExpectedExprRet(pszFilename != NULL);

    HRESULT hr = S_OK;

    // In the open an existing project case pszFilename will be a full path to 
    // the existing project file to be opened and pszName/pszLocation will be NULL. 
    // In the create a new project case pszFilename will be the full path to the template
    // file to be cloned and pszName/pszLocation will be non-NULL pointing to the name
    // and location of the project to be created. 
    // Compute the project name (caption) and FullPath to the project file 
    // being created. 
    CString strProjName; //the name of the project without a leading path or extension.
    CString strProjFullPath;
    CString strProjLocation;
    CalculateNames(    pszFilename, pszName, pszLocation, strProjFullPath, strProjName, strProjLocation);

    if(grfCreateFlags & CPF_CLONEFILE)
    {
        // Copy the template file
        strProjFullPath = pszLocation;
        strProjFullPath += pszName;
        BOOL fResult = ::CopyFile(pszFilename, strProjFullPath, true);
        ASSERT(fResult);
        if (!fResult)
        {
            DWORD err = ::GetLastError();
            return HRESULT_FROM_WIN32(err);
        }
    }
    else
    {
        strProjFullPath = pszFilename;
    }

    long    lFileMajor;
    long    lFileMinor;
    CString strProjectGuids;
    hr = GetPreCreateInfoFromProjectFile(strProjFullPath, strProjectGuids, &lFileMajor, &lFileMinor);
    // if fail - assume no owner key and continue
    // If our project file is a newer version then we must fail here
    BOOL fNewerProjectFile = (lFileMajor > _wtol(ProjectMajorVersionNumber)) || ((lFileMajor == _wtol(ProjectMajorVersionNumber)) && (lFileMinor > _wtol(ProjectMinorVersionNumber)));
    if (fNewerProjectFile)
    {
        // We fail in this case.
        // IDS_E_PROJECTFILEVERSION_MISMATCH:
        // "The project '%1' was created with a newer version of Visual Studio 
        // which is incompatible with your version. You can only open this 
        // project with newer versions of Visual Studio."
        hr = VS_E_PROJECTMIGRATIONFAILED;
        LUtilSetErrString1(IDS_E_PROJECTFILEVERSION_MISMATCH, pszFilename);
        _VxModule.ReportErrorInfo(hr);
        return hr;
    }

    if (!strProjectGuids.IsEmpty())
    {
        CComBSTR bstrProjTypeGuids;
        bstrProjTypeGuids = strProjectGuids;
        CComPtr<IVsCreateAggregateProject> srpCAP;
        _VxModule.QueryService(SID_SVsCreateAggregateProject, IID_IVsCreateAggregateProject, (void**)&srpCAP);
        ASSERT(srpCAP);
        if(srpCAP)
        {
            // Create the project (including aggregator if any)
            hr = srpCAP->CreateAggregateProject(bstrProjTypeGuids,
                                                strProjFullPath,
                                                strProjLocation,
                                                strProjName,
                                                CPF_OPENFILE,
                                                iidProject, ppvProject);
            *pfCanceled = (hr == E_ABORT);
            return hr;
        }
        else
            return E_FAIL;
    }

    ASSERT("The project file was invalid");
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
//                                             IVsAggregatableProjectFactory
STDMETHODIMP CMyProjectFactory::GetAggregateProjectType(LPCOLESTR pszFilename, BSTR *pbstrProjTypeGuid)
{
    ExpectedPtrRet(pszFilename);
    ExpectedPtrRet(pbstrProjTypeGuid);
    *pbstrProjTypeGuid = NULL;

    CString strProjectGuids;
    long lFileMajor;
    long lFileMinor;
    // Get the list of GUIDs from the project file
    HRESULT hr = GetPreCreateInfoFromProjectFile(pszFilename, strProjectGuids, &lFileMajor, &lFileMinor);

    if (!strProjectGuids.IsEmpty())
    {
        // if we found the GUIDs, return them
        *pbstrProjTypeGuid = ::SysAllocString(strProjectGuids);
    }

    return *pbstrProjTypeGuid ? NOERROR : E_FAIL;
}

STDMETHODIMP CMyProjectFactory::PreCreateForOuter(IUnknown *pUnkOwner, IUnknown **ppunkProject)
{
    ExpectedPtrRet(ppunkProject); 
    InitParam(ppunkProject);

    HRESULT hr = S_OK;

    // create an Aggregated version of our project hierarchy
    CComPolyObject<CMyProjectHierarchy> *pAggHier;
    hr = CComPolyObject<CMyProjectHierarchy>::CreateInstance(pUnkOwner, &pAggHier);
    IfFailRet(hr);

    CMyProjectHierarchy *pHier;  // created with Ref count 0
    //
    // assign pAggHier to the inner object
    //
    pHier = &(pAggHier->m_contained);
    ASSERT(pHier);
    if (pHier == NULL)
    {
        delete pAggHier;
        return E_UNEXPECTED;
    }

    pHier->AddRef(); // addref to keep alive
    hr = pHier->SetSite(_VxModule.GetModuleSite());
    ASSERT(SUCCEEDED(hr));

    // get the inner IUnknown
    hr = pAggHier->QueryInterface(IID_IUnknown, (void**)ppunkProject);

    // Balance references
    pHier->Release();

    if (FAILED(hr))
    {
        // destroy the pAggHier
        delete pAggHier;
    }

    return hr;
}
//                                             IVsAggregatableProjectFactory
// =========================================================================

HRESULT CMyProjectFactory::GetPreCreateInfoFromProjectFile(
    /* [in]  */ LPCTSTR  pszFileName,
    /* [out] */ CString& strProjectGuids,
    /* [out] */ long     *plMajor,
    /* [out] */ long     *plMinor)
{
    ExpectedPtrRet(pszFileName);

    HRESULT hr    = S_OK;

    // Initialise prject file major and minor version numbers. Note if the proerties are not
    // in the project file we will assume both numbers are zero.
    *plMajor = 0;
    *plMinor = 0;
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

                if (_wcsicmp(rgwchPropName, STR_PROJECTGUIDS) == 0)
                {
                    strProjectGuids = cvarValue.bstrVal;
                }
                if (_wcsicmp(rgwchPropName, STR_PROJFILEMAJOR) == 0)
                {
                    *plMajor = _wtol(cvarValue.bstrVal);
                }
                if (_wcsicmp(rgwchPropName, STR_PROJFILEMINOR) == 0)
                {
                    *plMinor = _wtol(cvarValue.bstrVal);
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

        // If the Name has a .bscp on the end, remove it.
        int index = strProjName.Find(TEXT(".bscp"));
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
