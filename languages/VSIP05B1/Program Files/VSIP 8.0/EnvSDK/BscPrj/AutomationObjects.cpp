
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


/***************************************************************************
File name   : AutomationObjects.cpp
Description : Implementation of the following automation objects:
              1) class CAOProject 
              2) class CAOProjectItemBase
              3) class CAOProjectItemFile
              4) class CAOSelectedItem
***************************************************************************/

#include "stdafx.h"
#include "PrjInc.h"
#include "PrjNRoot.h"
#include "PrjNFolder.h"
#include "VsPkg.h"

///////////////////////////////////////////////////////////////////////////
//                                                               CAOProject

//==========================================================================
//                                          construct, init , copy, destruct
/* static */
HRESULT CAOProject::CreateInstance(
    /* [in]  */ CFileVwProjNode* pProjNode,
    /* [out] */ Project**        ppProject)
{
    ExpectedPtrRet(pProjNode);
    ExpectedPtrRet(ppProject);
    *ppProject = NULL;

    CComObject<CAOProject>* pco = NULL;
    HRESULT hr = CComObject<CAOProject>::CreateInstance(&pco);
    IfFailRet(hr);

    pco->AddRef();
    hr = pco->Init(pProjNode);
    if (SUCCEEDED(hr))
    {
        hr = pco->QueryInterface(IID_Project, (void**)ppProject);
    }
    pco->Release();
    return hr;
}


CAOProject::CAOProject()
: m_fClosed(false)
{
}


void CAOProject::Close()
{
    m_fClosed = true;
    if (m_srpProjectItems != NULL)
        static_cast<CACProjectItems*>((ProjectItems*)m_srpProjectItems)->Close();
}


HRESULT CAOProject::Init(
    /* [in]  */ CFileVwProjNode* pProjNode)
{
    ExpectedPtrRet(pProjNode);
    m_pProjNode = pProjNode;
    return S_OK;
}


void CAOProject::FinalRelease()
{
    m_srpProjectItems.Release();
}

bool CAOProject::IsValid()
{
    return !m_fClosed;
}

//                                          construct, init , copy, destruct
//==========================================================================



STDMETHODIMP CAOProject::get_Name(
    /* [out] */ BSTR* lpbstrName)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lpbstrName);
    *lpbstrName = NULL;

    ExpectedExprRet(m_pProjNode);
    return m_pProjNode->GetDisplayCaption(lpbstrName);
}


STDMETHODIMP CAOProject::put_Name(
    /* [in]  */ BSTR bstrName)
{
     _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
 
    // Smartpointer to balance Enter/Exit automation
    CEnterAutomationFunction enterAutomation;

    ExpectedExprRet(m_pProjNode);
    HRESULT hr = m_pProjNode->RenameProject(bstrName);
    return hr;
}


STDMETHODIMP CAOProject::get_FileName(
    /* [out] */ BSTR * lpbstrReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lpbstrReturn);
    *lpbstrReturn = NULL;

    ExpectedExprRet(m_pProjNode);
    CString str = m_pProjNode->GetFullPath();
    *lpbstrReturn = str.AllocSysString();
    if (!*lpbstrReturn)
        return E_OUTOFMEMORY;

    return S_OK;
}


STDMETHODIMP CAOProject::get_IsDirty(
        /* [out] */ VARIANT_BOOL * lpfReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lpfReturn);
    *lpfReturn = VARIANT_FALSE;

    ExpectedExprRet(m_pProjNode);
    *lpfReturn = m_pProjNode->IsProjectFileDirty() ? VARIANT_TRUE : VARIANT_FALSE;
    return S_OK;
}


STDMETHODIMP CAOProject::put_IsDirty(
    /* [in]  */ VARIANT_BOOL Dirty)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedExprRet(m_pProjNode);
    m_pProjNode->SetProjectFileDirty(Dirty == VARIANT_TRUE);
    return S_OK;
}


STDMETHODIMP CAOProject::get_Collection(
    /* [out] */ Projects ** lppaReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lppaReturn);
    *lppaReturn = NULL;

    CVsPackage* pCVsPackage = GetCVsPkg();
    ExpectedExprRet(pCVsPackage != NULL);

    CComPtr<IDispatch> srpIDispatch;
    HRESULT hr = pCVsPackage->GetAutomationProjects(&srpIDispatch);
    IfFailRet(hr);
    ExpectedExprRet(srpIDispatch != NULL);

    return srpIDispatch->QueryInterface(IID_Projects, (void**)lppaReturn);
}


STDMETHODIMP CAOProject::SaveAs(
    /* [in]  */ BSTR FileName)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    // First we must check if this method is enabled/disabled and if
    // it is disabled we merely return E_FAIL.
    // Note that CheckEnabledItem will set the error info if
    // the method is not enabled.
    if (FAILED(CheckEnabledItem(this, &IID_Project, L"SaveAs")))
        return E_FAIL;

    CString strFileName(FileName);  
    strFileName.TrimLeft();
    strFileName.TrimRight();
    if(strFileName.IsEmpty())
        return E_INVALIDARG;

    return Save(FileName);
}


STDMETHODIMP CAOProject::get_DTE(
    /* [out] */ DTE ** lppaReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lppaReturn);
    *lppaReturn = NULL;

    return _VxModule.QueryService(SID_SDTE, IID__DTE, (void **)lppaReturn);
}


STDMETHODIMP CAOProject::get_Kind(
    /* [out] */ BSTR * lpbstrReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lpbstrReturn);
    *lpbstrReturn = NULL;

    CComBSTR cbstrKind(szProjectKind);
    if (cbstrKind.Length() == 0)
        return E_OUTOFMEMORY;

    *lpbstrReturn = cbstrKind.Detach();
    return S_OK;
}


STDMETHODIMP CAOProject::get_ProjectItems(
    /* [out] */ ProjectItems ** lppcReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lppcReturn);
    *lppcReturn = NULL;

    HRESULT hr = S_OK;
    
    if (!m_srpProjectItems)
    {
        hr = CACProjectItems::CreateInstance(m_pProjNode, &m_srpProjectItems);
        IfFailRet(hr);
        ExpectedExprRet(m_srpProjectItems != NULL);
    }

    hr = m_srpProjectItems.CopyTo(lppcReturn);
    return hr;
}


STDMETHODIMP CAOProject::get_Properties(
    /* [out] */ Properties ** lppaReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lppaReturn);
    *lppaReturn = NULL;

    HRESULT hr = S_OK;
    IVsExtensibility* pIVsExtensibility = _VxModule.GetIVsExtensibility();
    ExpectedExprRet(pIVsExtensibility != NULL);

    ExpectedExprRet(m_pProjNode);
    IVsHierarchy* pIVsHierarchy = m_pProjNode->GetIVsHierarchy();
    ExpectedExprRet(pIVsHierarchy);

    CComVariant cvar;
    hr = pIVsHierarchy->GetProperty(VSITEMID_ROOT, VSHPROPID_BrowseObject, &cvar);
    IfFailRet(hr);
    ExpectedExprRet(VT_DISPATCH == V_VT(&cvar));

    hr = pIVsExtensibility->get_Properties(this, cvar.pdispVal, lppaReturn);
    IfFailRet(hr);

    return hr;
}


STDMETHODIMP CAOProject::get_UniqueName(
    /* [out] */ BSTR * lpbstrFileName)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lpbstrFileName);
    *lpbstrFileName = NULL;

    HRESULT hr = S_OK;
    CComPtr<IVsSolution> srpSolution;
    hr = _VxModule.QueryService(SID_SVsSolution, IID_IVsSolution, (void **)&srpSolution);
    IfFailRet(hr);

    ExpectedExprRet(m_pProjNode != NULL);
    IVsHierarchy* pIVsHierarchy = m_pProjNode->GetIVsHierarchy();
    ExpectedExprRet(pIVsHierarchy != NULL);

    hr = srpSolution->GetUniqueNameOfProject(pIVsHierarchy,lpbstrFileName);
    IfFailRet(hr);

    return hr; 
}


STDMETHODIMP CAOProject::get_Object(
    /* [out] */ IDispatch ** ppProjectModel)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(ppProjectModel);
    *ppProjectModel = NULL;

    // Note that we do not expose project specific object
    // When a project specific object is supported it should be returned here
    
    return E_NOTIMPL;
}


STDMETHODIMP CAOProject::get_Extender(
    /* [in]  */ BSTR            bstrExtenderName, 
    /* [out] */ IDispatch **    ppExtender)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    return GetExtender(szguidCATIDProject, (LPDISPATCH)this, bstrExtenderName, ppExtender);
}


STDMETHODIMP CAOProject::get_ExtenderNames(
    /* [out] */ VARIANT *pvarExtenderNames)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
     return GetExtenderNames(szguidCATIDProject, (LPDISPATCH)this, pvarExtenderNames);
}


STDMETHODIMP CAOProject::get_ExtenderCATID(
    /* [out] */ BSTR *pbstrRetval)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    return GetExtenderCATID(szguidCATIDProject, pbstrRetval);
}


STDMETHODIMP CAOProject::get_FullName(
    /* [out] */ BSTR *lpbstrReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    return get_FileName(lpbstrReturn);
}


STDMETHODIMP CAOProject::get_Saved(
    /* [out] */ VARIANT_BOOL *lpfReturn)
{ 
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lpfReturn);
    *lpfReturn = VARIANT_FALSE;

    VARIANT_BOOL fDirty = VARIANT_TRUE;
    HRESULT hr = get_IsDirty(&fDirty);
    IfFailRet(hr);

    *lpfReturn = (VARIANT_TRUE == fDirty) ? VARIANT_FALSE : VARIANT_TRUE;
    return hr;
}


STDMETHODIMP CAOProject::put_Saved(
    /* [in] */ VARIANT_BOOL fSaved)
{ 
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    VARIANT_BOOL fDirty = (VARIANT_TRUE == fSaved) ? VARIANT_FALSE : VARIANT_TRUE;
    return put_IsDirty(fDirty);
}


STDMETHODIMP CAOProject::get_ConfigurationManager(
    /* [out] */ ConfigurationManager ** ppConfigurationManager)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(ppConfigurationManager);
    *ppConfigurationManager = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CAOProject::get_Globals(
    /* [out] */ Globals ** ppGlobals)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(ppGlobals);
    InitParam(ppGlobals);

    HRESULT hr = S_OK;

    hr = CheckEnabledItem(this, &IID__DTE, L"Globals");
    IfFailRet(hr);

    // if don't already have m_srpGlobals, get it from shell
    if( !m_srpGlobals )
    {   
        VxDTE::IVsExtensibility* pIVsExtensibility = _VxModule.GetIVsExtensibility();
        if (!pIVsExtensibility)
            return E_FAIL;  // couldn't get DTE !

        VARIANT varIVsGlobalsCallback;
        VariantInit( &varIVsGlobalsCallback );
        varIVsGlobalsCallback.vt = VT_UNKNOWN;
        IVsHierarchy* pIVsHierarchy = m_pProjNode->GetIVsHierarchy();
        ExpectedExprRet(pIVsHierarchy != NULL);
        hr = pIVsHierarchy->QueryInterface(IID_IUnknown, (void**)&varIVsGlobalsCallback.punkVal);
        IfFailRet(hr);

        hr = pIVsExtensibility->GetGlobalsObject(varIVsGlobalsCallback, &m_srpGlobals);
        IfFailRet(hr);

        varIVsGlobalsCallback.punkVal->Release();
    }

    ExpectedExprRet(m_srpGlobals);

    *ppGlobals = m_srpGlobals;
    (*ppGlobals)->AddRef();

    return hr;
}



STDMETHODIMP CAOProject::Save(
    /* [in] */BSTR FileName)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    // make sure we don't throw up any message boxes
    // Smartpointer to balance Enter/Exit automation
    CEnterAutomationFunction enterAutomation;

    HRESULT hr = S_OK;
    USES_CONVERSION;

    CComBSTR cbstrCurrentFileName;
    hr = get_FileName(&cbstrCurrentFileName);
    IfFailRet(hr);

    ExpectedExprRet(m_pProjNode != NULL);
    IVsHierarchy* pIVsHierarchy = m_pProjNode->GetIVsHierarchy();
    ExpectedExprRet(pIVsHierarchy != NULL);

    // first check for SaveAs case
    if (::SysStringLen(FileName))
    {
        CString strFileName = FileName;
        strFileName.TrimLeft();
        strFileName.TrimRight();

        if (!strFileName.IsEmpty())
        {
            // See if new name has an extension and that it is the right one.
            WCHAR* pszExt = wcsrchr(FileName, L'.');
            CString strDefaultExtension;
            hr = m_pProjNode->GetDefaultProjectExtension(strDefaultExtension);
            IfFailRet(hr);

            if(pszExt == NULL || _wcsicmp(pszExt, T2CW(strDefaultExtension)) )
                strFileName += strDefaultExtension;

            // if the SaveAs name matches the current name then it's not a SaveAs.
            if (_wcsicmp(T2CW(strFileName), cbstrCurrentFileName))
            {
                // SaveAs case

                CComPtr<IPersistFileFormat> srpIPersistFileFormat;
                hr = pIVsHierarchy->QueryInterface(IID_IPersistFileFormat, (void**) &srpIPersistFileFormat);
                IfFailRet(hr);

                // Calling Save on the hierarchy isn't a problem in SaveAs case as the 
                // shell team is only tracking file change notification for existing 
                // documents. In this case a new one is created & then used.
                hr = srpIPersistFileFormat->Save(T2CW(strFileName), TRUE, 0); 
                return hr;
            }
        }
    }

    // Save operation

    // get the RDT pointer
    IVsRunningDocumentTable *pRDT = _VxModule.GetIVsRunningDocumentTable();
    ExpectedExprRet(pRDT != NULL);

    // lock the document
    VSCOOKIE vscookie = VSCOOKIE_NIL;       
    hr = pRDT->FindAndLockDocument(
        /* [in]  VSRDTFLAGS     dwRDTLockType*/ RDT_NoLock,
        /* [in]  LPCOLESTR      pszMkDocument*/ cbstrCurrentFileName,
        /* [out] IVsHierarchy** ppHier       */ NULL,
        /* [out] VSITEMID*      pitemid      */ NULL,
        /* [out] IUnknown**     ppunkDocData */ NULL,
        /* [out] VSCOOKIE*      pdwCookie    */ &vscookie);
    IfFailRet(hr);

    // Calling this instead of directly calling Save on the hierarchy,
    // so that the shell team turns off file change notification
    // (dialog prompting do you wish to reload prj does not come up ) 
    hr = pRDT->SaveDocuments(
        /* [in] VSRDTSAVEOPTIONS grfSaveOpts */ RDTSAVEOPT_ForceSave, 
        /* [in] IVsHierarchy *pHier          */ pIVsHierarchy,
        /* [in] VSITEMID itemid              */ VSITEMID_ROOT, 
        /* [in] VSCOOKIE docCookie           */ vscookie);
    IfFailRet(hr);

    return hr;
}


STDMETHODIMP CAOProject::get_ParentProjectItem(
    /* [out] */ ProjectItem **ppProjectItem)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(ppProjectItem);
    InitParam(ppProjectItem);
    return E_NOTIMPL;
}


STDMETHODIMP CAOProject::get_CodeModel(
    /* [out] */ CodeModel **ppCodeModel)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(ppCodeModel);
    InitParam(ppCodeModel);
    return E_NOTIMPL;
}


STDMETHODIMP CAOProject::Delete()
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    return E_NOTIMPL;
}


STDMETHODIMP CAOProject::NotifyPropertiesDelete()
{
    return S_OK;
}

//                                                               CAOProject
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//                                                       CAOProjectItemBase

//==========================================================================
//                                          construct, init , copy, destruct

CAOProjectItemBase::CAOProjectItemBase()
{
    m_pProperties = NULL;
    m_fClosed = false;
}

HRESULT CAOProjectItemBase::Init(CHierNode* pNode)
{
    ExpectedPtrRet(pNode);
    m_pNode = pNode;
    return S_OK;
}

void CAOProjectItemBase::Close()
{
    m_fClosed = true;
}

bool CAOProjectItemBase::IsValid()
{
    return !m_fClosed;
}

//                                          construct, init , copy, destruct
//==========================================================================


// =========================================================================
//                                                               ProjectItem

STDMETHODIMP CAOProjectItemBase::get_IsDirty(
    /* [out, retval] */ VARIANT_BOOL  *lpfReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lpfReturn);
    *lpfReturn = VARIANT_FALSE;

    HRESULT hr = S_OK;

    CComPtr<IVsPersistDocData> srpIVsPersistDocData;
    hr = GetDocData(
        /* [in]       BOOL fOpen*/ FALSE,  //open the document if not opened
        /* [out, opt] IVsPersistDocData** ppIVsPersistDocData*/ &srpIVsPersistDocData,
        /* [out, opt] BOOL pfOpenedDuringTheCall*/ NULL);
    IfFailRet(hr);

    BOOL fDirty = FALSE;
    if (srpIVsPersistDocData != NULL)
        srpIVsPersistDocData->IsDocDataDirty(&fDirty);

    if (fDirty)
        *lpfReturn = VARIANT_TRUE;
        
    return S_OK;
}


STDMETHODIMP CAOProjectItemBase::put_IsDirty(
    /* [in]          */ VARIANT_BOOL DirtyFlag)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    return E_NOTIMPL;
}


STDMETHODIMP CAOProjectItemBase::get_FileNames(
    /* [in]          */ short   Index, 
    /* [out, retval] */ BSTR  * lpbstrReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lpbstrReturn);
    *lpbstrReturn = NULL;

    if (Index != 1) 
        return E_INVALIDARG; // we have only one file

    HRESULT hr = S_OK;

    IVsHierarchy* pIVsHierarchy = GetIVsHierarchy();
    ExpectedExprRet(pIVsHierarchy != NULL);

    CComPtr<IVsProject> srpIVsProject;
    hr = pIVsHierarchy->QueryInterface(IID_IVsProject, (void**) &srpIVsProject);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsProject != NULL);

    hr = srpIVsProject->GetMkDocument(GetVsItemID(), lpbstrReturn);
    IfFailRet(hr);

    return S_OK;
}   


STDMETHODIMP CAOProjectItemBase::SaveAs(
    /* [in]          */ BSTR            NewFileName, 
    /* [out, retval] */ VARIANT_BOOL  * lpfReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(NewFileName);
    ExpectedPtrRet(lpfReturn);
    *lpfReturn = VARIANT_FALSE;

    HRESULT hr = S_OK;

    BOOL fCancelled;
    hr = SaveItem(VSSAVE_SilentSave, NewFileName, &fCancelled);
    IfFailRet(hr);

    *lpfReturn = (fCancelled) ? VARIANT_FALSE : VARIANT_TRUE;

    return hr;

}


STDMETHODIMP CAOProjectItemBase::get_FileCount(
    /* [out, retval] */ short  * lpsReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    *lpsReturn = 1;
    // If we support nested folders, then we need to return the number of files in
    // that folder here. If there is not a 1:1 correspondance between project item
    // and a file, that would be returned here also.
    return NOERROR;
}


STDMETHODIMP CAOProjectItemBase::get_Name(
    /* [out, retval] */ BSTR * pbstrReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(pbstrReturn);
    *pbstrReturn = NULL;

    HRESULT hr = S_OK;

    CHierNode* pNode = GetNode();
    ExpectedExprRet(pNode != NULL);

    hr = pNode->GetDisplayCaption(pbstrReturn);
    return hr;
}


STDMETHODIMP CAOProjectItemBase::put_Name(
    /* [in]          */ BSTR bstrName)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(bstrName);
    *bstrName = NULL;

    HRESULT hr = S_OK;

    // make sure we don't throw up any message boxes
    // Smartpointer to balance Enter/Exit automation
    CEnterAutomationFunction enterAutomation;

    CHierNode* pNode = GetNode();
    ExpectedExprRet(pNode != NULL);

    hr = pNode->SetEditLabel(bstrName);
    return hr;
}
    

STDMETHODIMP CAOProjectItemBase::get_Collection(
    /* [out, retval] */ ProjectItems ** lppcReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lppcReturn);
    *lppcReturn = NULL;

    HRESULT hr = NOERROR;

    // NOTE: This only works for a flat file system.
    // If folders are added, this should be updated to get the correct collection
    CHierNode* pNode = GetNode();
    ExpectedExprRet(pNode != NULL);

    CHierContainer* pHierContainer = pNode->GetParent();
    ExpectedExprRet(pHierContainer != NULL);

    CComVariant cvar;
    hr = pHierContainer->GetProperty(VSHPROPID_ExtObject, &cvar);
    IfFailRet(hr);
    ExpectedExprRet(VT_DISPATCH == V_VT(&cvar));
    ExpectedExprRet(cvar.pdispVal != NULL);

    CComPtr<Project> srpProject;
    hr = cvar.pdispVal->QueryInterface(IID_Project, (void**) &srpProject);
    IfFailRet(hr);

    hr = srpProject->get_ProjectItems(lppcReturn);
    return hr;
}


STDMETHODIMP CAOProjectItemBase::get_Properties(
    /* [out, retval] */ Properties ** ppObject)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(ppObject);
    *ppObject = NULL;

    HRESULT hr = S_OK;

    CHierNode* pNode = GetNode();
    ExpectedExprRet(pNode != NULL);

    CComVariant cvar;
    hr = pNode->GetProperty(VSHPROPID_BrowseObject, &cvar);
    IfFailRet(hr);
    ExpectedExprRet(VT_DISPATCH == V_VT(&cvar));

    BOOL fReleaseProperties = FALSE;
    if (!m_pProperties)
    {
        IVsExtensibility* pIVsExtensibility = _VxModule.GetIVsExtensibility();
        ExpectedExprRet(pIVsExtensibility != NULL);

        hr = pIVsExtensibility->get_Properties(this, cvar.pdispVal, &m_pProperties);
        IfFailRet(hr);
        ExpectedExprRet(m_pProperties != NULL);
        fReleaseProperties = TRUE;
    }

    hr = m_pProperties->QueryInterface(IID_Properties, (void **)ppObject);

    // m_pProperties still addref'ed thru the QI. When its ref cnt reaches 0, 
    // ISupportVSProperties::NotifyPropertiesDelete() is called.
    // When that is done m_pProperties is reinit to NULL so that it is obtained 
    // again.
    if (TRUE == fReleaseProperties)
        m_pProperties->Release();

    return hr;
}


STDMETHODIMP CAOProjectItemBase::get_DTE(
    /* [out, retval] */ DTE **  lppaReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lppaReturn);
    *lppaReturn = NULL;

    HRESULT hr = _VxModule.QueryService(SID_SDTE, IID__DTE, (void **)lppaReturn);
    return hr;
}


STDMETHODIMP CAOProjectItemBase::get_Kind(
    /* [out, retval] */ BSTR  * lpbstrFileName)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lpbstrFileName);
    *lpbstrFileName = NULL;

    CComBSTR cbstrKind(vsProjectItemKindPhysicalFile);
    if (cbstrKind.Length() == 0)
        return E_OUTOFMEMORY;

    *lpbstrFileName = cbstrKind.Detach();
    return S_OK;
}
    

STDMETHODIMP CAOProjectItemBase::get_ProjectItems(
        /* [out, retval] */ ProjectItems ** lppcReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lppcReturn);
    *lppcReturn = NULL; // no children
    return S_OK;
}


STDMETHODIMP CAOProjectItemBase::get_IsOpen(
    /* [in]          */ BSTR            ViewKind, 
    /* [out, retval] */ VARIANT_BOOL  * lpfReturn)
{

    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lpfReturn);
    *lpfReturn = VARIANT_FALSE;

    // just return false here derived classes will override it
    return S_OK;
}


STDMETHODIMP CAOProjectItemBase::Open(
    /* [in]          */ BSTR        ViewKind, 
    /* [out, retval] */ Window **   lppfReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lppfReturn);
    InitParam(lppfReturn);

    return OpenItem(ViewKind, FALSE, lppfReturn);
}


STDMETHODIMP CAOProjectItemBase::Remove()
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    // First we must check if this method is enabled/disabled and if
    // it is disabled we merely return E_FAIL.
    // Note that CheckEnabledItem will set the error info if
    // the method is not enabled.
    if (FAILED(CheckEnabledItem(this, &IID_ProjectItem, L"Remove")))
        return E_FAIL;

    return DeleteItem(DELITEMOP_RemoveFromProject);
}


STDMETHODIMP CAOProjectItemBase::ExpandView()
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    HRESULT hr = S_OK;

    // make sure we don't throw up any message boxes
    // Smartpointer to balance Enter/Exit automation
    CEnterAutomationFunction enterAutomation;

    CHierNode* pNode = GetNode();
    ExpectedExprRet(pNode != NULL);
    
    hr = pNode->ExtExpand(EXPF_ExpandFolder);

    return hr;
}


STDMETHODIMP CAOProjectItemBase::get_Object(
    /* [out, retval] */ IDispatch **    ProjectItemModel)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(ProjectItemModel);
    InitParam(ProjectItemModel);

    // Note that we do not expose project specific object
    // When a project specific object is supported it should be returned here

    return E_NOTIMPL;
}


STDMETHODIMP CAOProjectItemBase::get_Extender(
    /* [in]  */ BSTR            bstrExtenderName, 
    /* [out] */ IDispatch **    ppExtender)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    return GetExtender(szguidCATIDProjectItem, (LPDISPATCH)this, bstrExtenderName, ppExtender);
}


STDMETHODIMP CAOProjectItemBase::get_ExtenderNames(
    /* [out] */ VARIANT *pvarExtenderNames)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    return GetExtenderNames(szguidCATIDProjectItem, (LPDISPATCH)this, pvarExtenderNames);
}


STDMETHODIMP CAOProjectItemBase::get_ExtenderCATID(
    /* [out] */ BSTR *pbstrRetval)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    return GetExtenderCATID(szguidCATIDProjectItem, pbstrRetval);
}


STDMETHODIMP CAOProjectItemBase::get_Saved(
    /* [out, retval] */ VARIANT_BOOL *  lpfReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lpfReturn);
    *lpfReturn = VARIANT_FALSE;

    VARIANT_BOOL fDirty = VARIANT_TRUE;
    HRESULT hr = get_IsDirty(&fDirty);
    IfFailRet(hr);

    *lpfReturn = (VARIANT_TRUE == fDirty) ? VARIANT_FALSE : VARIANT_TRUE;
    return hr;
}


STDMETHODIMP CAOProjectItemBase::put_Saved(
    /* [in]          */ VARIANT_BOOL    SavedFlag)
{ 
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    VARIANT_BOOL fDirty = (VARIANT_TRUE == SavedFlag) ? VARIANT_FALSE : VARIANT_TRUE;
    return put_IsDirty(fDirty);
}



STDMETHODIMP CAOProjectItemBase::get_ConfigurationManager(
    /* [out, retval] */ ConfigurationManager ** ppConfigurationManager)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(ppConfigurationManager);
    *ppConfigurationManager = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CAOProjectItemBase::get_FileCodeModel(
    /* [out, retval] */ FileCodeModel **    ppFileCodeModel)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(ppFileCodeModel);
    *ppFileCodeModel = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CAOProjectItemBase::Save(
    /* [defaultvalue("")] */ BSTR FileName)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    HRESULT hr = S_OK;

    if (::SysStringLen(FileName))
    {
        hr = SaveItem(VSSAVE_SilentSave, FileName);
        return hr;
    }
    else
    {
        CComBSTR cbstrFullFileName;
        hr = get_FileNames(1, &cbstrFullFileName);
        IfFailRet(hr);

        hr = SaveItem(VSSAVE_SilentSave, cbstrFullFileName);
        return hr;
    }

    return hr;
}


STDMETHODIMP CAOProjectItemBase::get_Document(
    /* [out, retval] */ Document ** ppDocument)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(ppDocument);
    *ppDocument = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CAOProjectItemBase::get_SubProject(
    /* [out, retval] */ Project **  ppProject)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(ppProject);
    *ppProject = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CAOProjectItemBase::get_ContainingProject(
    /* [out, retval] */ Project **  ppProject)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(ppProject);
    *ppProject = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CAOProjectItemBase::Delete()
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    // First we must check if this method is enabled/disabled and if
    // it is disabled we merely return E_FAIL.
    // Note that CheckEnabledItem will set the error info if
    // the method is not enabled.
    if (FAILED(CheckEnabledItem(this, &IID_ProjectItem, L"Delete")))
        return E_FAIL;

    return DeleteItem(DELITEMOP_DeleteFromStorage);
}

//                                                               ProjectItem
// =========================================================================


// =========================================================================
//                                                      ISupportVSProperties

STDMETHODIMP CAOProjectItemBase::NotifyPropertiesDelete()
{
    // Called when the wrapper properties object ref cnt reaches 0. 
    //  Set to null so the next time get_props is called, it is obtained again.
    m_pProperties = NULL;
    return NOERROR;
}
//                                                      ISupportVSProperties
// =========================================================================









HRESULT CAOProjectItemBase::GetDocData(
    /* [in]       */ BOOL                fOpen,  //open the document if not opened
    /* [out, opt] */ IVsPersistDocData** ppIVsPersistDocData,
    /* [out, opt] */ BOOL *              pfOpenedDuringTheCall)// opened during the call
{
    if (ppIVsPersistDocData)
        *ppIVsPersistDocData = NULL;
    if (pfOpenedDuringTheCall)
        *pfOpenedDuringTheCall = FALSE;

    HRESULT hr = S_OK;
    USES_CONVERSION;

    CComBSTR cbstrFullFileName;
    hr = get_FileNames(1, &cbstrFullFileName);
    IfFailRet(hr);

    CComPtr<IVsPersistDocData> srpIVsPersistDocData;
    hr = GetRDTDocumentInfo(
        /* [in]  LPCTSTR             pszDocumentName    */ W2CT(cbstrFullFileName), 
        /* [out] IVsHierarchy**      ppIVsHierarchy     */ NULL,
        /* [out] VSITEMID*           pitemid            */ NULL,
        /* [out] IVsPersistDocData** ppIVsPersistDocData*/ &srpIVsPersistDocData,
        /* [out] VSDOCCOOKIE*        pVsDocCookie       */ NULL);
    IfFailRet(hr);

    if (srpIVsPersistDocData != NULL)
    {
        if (ppIVsPersistDocData)
            *ppIVsPersistDocData = srpIVsPersistDocData.Detach();
        if (pfOpenedDuringTheCall)
            *pfOpenedDuringTheCall = FALSE;
        return S_OK;
    }

    if (!fOpen)
        return S_FALSE;

    // file isn't already open so open it
    CComPtr<Window> srpWindow;
    CComBSTR cbstrViewKind(vsViewKindPrimary);
    hr = OpenItem(cbstrViewKind, TRUE, &srpWindow);
    IfFailRet(hr);

    hr = GetRDTDocumentInfo(
        /* [in]  LPCTSTR             pszDocumentName    */ W2CT(cbstrFullFileName), 
        /* [out] IVsHierarchy**      ppIVsHierarchy     */ NULL,
        /* [out] VSITEMID*           pitemid            */ NULL,
        /* [out] IVsPersistDocData** ppIVsPersistDocData*/ &srpIVsPersistDocData,
        /* [out] VSDOCCOOKIE*        pVsDocCookie       */ NULL);
    IfFailRet(hr);

    if (ppIVsPersistDocData)
        *ppIVsPersistDocData = srpIVsPersistDocData.Detach();
    if (pfOpenedDuringTheCall)
        *pfOpenedDuringTheCall = TRUE;
    return hr;
}


//---------------------------------------------------------------------------
// Common helper routine used by SaveAs & Save methods.
//---------------------------------------------------------------------------
HRESULT CAOProjectItemBase::SaveItem(
    /* [in]       */ VSSAVEFLAGS  dwSave,
    /* [in]       */ BSTR         bstrFileName,
    /* [out, opt] */ BOOL*        pfCancelled  /* = NULL */)
{
    if (pfCancelled)
        *pfCancelled = FALSE;

    HRESULT hr = S_OK;

    // currently we require the full file name (incl. path) to be specified
 
    // Smartpointer to balance Enter/Exit automation
    CEnterAutomationFunction enterAutomation;

    CComPtr<IVsPersistDocData> srpIVsPersistDocData;
    hr = GetDocData(
        /* [in]       BOOL fOpen*/ TRUE,  //open the document if not opened
        /* [out, opt] IVsPersistDocData** ppIVsPersistDocData*/ &srpIVsPersistDocData,
        /* [out, opt] BOOL pfOpenedDuringTheCall*/ NULL);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsPersistDocData);

    IVsHierarchy* pIVsHierarchy = GetIVsHierarchy();
    ExpectedExprRet(pIVsHierarchy);

    CComPtr<IVsPersistHierarchyItem> srpIVsPersistHierarchyItem;
    hr = pIVsHierarchy->QueryInterface(IID_IVsPersistHierarchyItem, (void**) &srpIVsPersistHierarchyItem);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsPersistHierarchyItem != NULL);

    BOOL fCancelled = FALSE; 
    hr = srpIVsPersistHierarchyItem->SaveItem(dwSave, bstrFileName, GetVsItemID(), srpIVsPersistDocData, &fCancelled);
    IfFailRet(hr);

    if(fCancelled && pfCancelled)
        *pfCancelled = TRUE;

    return hr;
}


HRESULT CAOProjectItemBase::DeleteItem(
    /* [in] */ VSDELETEITEMOPERATION dwDelItemOp)
{
    HRESULT hr = S_OK;

    // make sure we don't throw up any message boxes
    // Smartpointer to balance Enter/Exit automation
    CEnterAutomationFunction enterAutomation;

    // call into the hierarchy to do the work.

    IVsHierarchy* pIVsHierarchy = GetIVsHierarchy();
    ExpectedExprRet(pIVsHierarchy != NULL);

    CComPtr<IVsHierarchyDeleteHandler> srpIVsHierarchyDeleteHandler;
    hr = pIVsHierarchy->QueryInterface(IID_IVsHierarchyDeleteHandler, (void**) &srpIVsHierarchyDeleteHandler);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsHierarchyDeleteHandler != NULL);
    
    hr = srpIVsHierarchyDeleteHandler->DeleteItem(
        dwDelItemOp,
        GetVsItemID());

    return hr;
}


HRESULT CAOProjectItemBase::OpenItem(
    /* [in]          */ BSTR       ViewKind, 
    /* [in]          */ BOOL       fShow,
    /* [out, retval] */ Window **  lppfReturn)
{
    // derived classes should override if the item can be opened
    return E_NOTIMPL;
}


IVsHierarchy* CAOProjectItemBase::GetIVsHierarchy()
{
    ASSERT(m_pNode);
    if (!m_pNode)
        return NULL;

    ASSERT(m_pNode->GetCVsHierarchy());
    if (!m_pNode->GetCVsHierarchy())
        return NULL;

    return m_pNode->GetCVsHierarchy()->GetIVsHierarchy();
}


VSITEMID CAOProjectItemBase::GetVsItemID()
{
    ExpectedExprRet(m_pNode);
    return m_pNode->GetVsItemID();
}


CHierNode* CAOProjectItemBase::GetNode()
{
    return m_pNode;
}



//                                                       CAOProjectItemBase
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//                                                       CAOProjectItemFile

/* static */
HRESULT CAOProjectItemFile::CreateInstance(
    /* [in]  */ CFileVwFileNode* pNode,
    /* [out] */ ProjectItem**    ppProjectItem)
{
    ExpectedPtrRet(pNode);
    ExpectedPtrRet(ppProjectItem);
    *ppProjectItem = NULL;

    CComObject<CAOProjectItemFile>* pco = NULL;
    HRESULT hr = CComObject<CAOProjectItemFile>::CreateInstance(&pco);
    IfFailRet(hr);

    pco->AddRef();
    hr = pco->Init(pNode);
    if (SUCCEEDED(hr))
    {
        hr = pco->QueryInterface(IID_ProjectItem, (void**)ppProjectItem);
    }
    pco->Release();
    return hr;
}


STDMETHODIMP CAOProjectItemFile::get_IsOpen(
    /* [in]          */ BSTR            ViewKind, 
    /* [out, retval] */ VARIANT_BOOL  * lpfReturn)
{

    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lpfReturn);
    *lpfReturn = VARIANT_FALSE;

    HRESULT hr = S_OK;

    GUID guidLogicalView = LOGVIEWID_Any;

    // If we didn't get a logical view, then just ignore the view parameter.
    VSIDOFLAGS idoFlags = (VSIDOFLAGS)0;
    if (ViewKind && SysStringLen(ViewKind))
    {
        hr = IIDFromString(ViewKind, &guidLogicalView);
        IfFailRet(hr);
    }
    else
    {
        idoFlags = IDO_IgnoreLogicalView;
    }

    IVsUIShellOpenDocument* pIVsUIShellOpenDocument = _VxModule.GetIVsUIShellOpenDocument();
    ExpectedExprRet(pIVsUIShellOpenDocument != NULL);

    IVsHierarchy* pIVsHierarchy = GetIVsHierarchy();
    ExpectedExprRet(pIVsHierarchy != NULL);

    CComPtr<IVsUIHierarchy> srpIVsUIHierarchy;
    hr = pIVsHierarchy->QueryInterface(IID_IVsUIHierarchy, (void**) &srpIVsUIHierarchy);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsUIHierarchy != NULL);

    CComBSTR cbstrMkDocument;
    hr = get_FileNames(1, &cbstrMkDocument);
    IfFailRet(hr);
    
    // Now ask the shell if the document is open or not.
    BOOL fOpen = FALSE;
    hr = pIVsUIShellOpenDocument->IsDocumentOpen(
            /* [in]  IVsUIHierarchy  *pHierCaller   */ srpIVsUIHierarchy,
            /* [in]  VSITEMID     itemidCaller      */ GetVsItemID(), 
            /* [in]  LPCOLESTR    pszMkDocument     */ cbstrMkDocument,
            /* [in]  REFGUID      rguidLogicalView  */ guidLogicalView,
            /* [in]  VSIDOFLAGS   grfIDO            */ idoFlags,
            /* [out] IVsUIHierarchy **ppHierOpen    */ NULL,
            /* [out] VSITEMID    *pitemidOpen       */ NULL,
            /* [out] IVsWindowFrame **ppWindowFrame */ NULL,
            /* [out, retval] BOOL *pfOpen           */ &fOpen);
    IfFailRet(hr);

    if (fOpen)
        *lpfReturn = VARIANT_TRUE;
    
    return hr;
}


HRESULT CAOProjectItemFile::OpenItem(
    /* [in]          */ BSTR       ViewKind, 
    /* [in]          */ BOOL       fShow,
    /* [out, retval] */ Window **  lppfReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lppfReturn);
    InitParam(lppfReturn);

    // make sure we don't throw up any message boxes
    // Smartpointer to balance Enter/Exit automation
    CEnterAutomationFunction enterAutomation;

    HRESULT hr = S_OK;

    GUID guidLogicalView = LOGVIEWID_Primary;
    if (ViewKind && SysStringLen(ViewKind))
    {
        hr = IIDFromString(ViewKind, &guidLogicalView);
        IfFailRet(hr);
    }

    CFileVwFileNode* pFileNode = GetFile();
    ExpectedExprRet(pFileNode != NULL);

    CComPtr<IVsWindowFrame> srpIVsWindowFrame;
    hr = pFileNode->OpenDoc(
            FALSE /*fNewFile*/, 
            FALSE /*fUseOpenWith*/,
            fShow /*fShow*/,
            guidLogicalView,
            DOCDATAEXISTING_UNKNOWN, 
            &srpIVsWindowFrame);
    IfFailRet(hr);
    ExpectedExprRet(srpIVsWindowFrame);

    CComVariant cvar;
    hr = srpIVsWindowFrame->GetProperty(VSFPROPID_ExtWindowObject, &cvar);
    IfFailRet(hr);
    ExpectedExprRet(cvar.punkVal != NULL)

    hr = cvar.punkVal->QueryInterface(IID_Window, (void **)lppfReturn);

    return hr;

}



CFileVwFileNode* CAOProjectItemFile::GetFile()
{
    ASSERT(m_pNode);
    if (!m_pNode)
        return NULL;

    if (m_pNode->IsKindOf(Type_CFileVwFileNode))
        return static_cast<CFileVwFileNode*>(m_pNode);

    ASSERT(FALSE);
    return NULL;
}

//                                                       CAOProjectItemFile
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
//                                                     CAOProjectItemFolder
HRESULT CAOProjectItemFolder::CreateInstance(
    /* [in]  */ CFileVwFolderNode* pNode,
    /* [out] */ ProjectItem**      ppProjectItem)
{
    ExpectedPtrRet(pNode);
    ExpectedPtrRet(ppProjectItem);
    *ppProjectItem = NULL;

    CComObject<CAOProjectItemFolder>* pco = NULL;
    HRESULT hr = CComObject<CAOProjectItemFolder>::CreateInstance(&pco);
    IfFailRet(hr);

    pco->AddRef();
    hr = pco->Init(pNode);
    if (SUCCEEDED(hr))
    {
        hr = pco->QueryInterface(IID_ProjectItem, (void**)ppProjectItem);
    }
    pco->Release();
    return hr;
}

CFileVwFolderNode* CAOProjectItemFolder::GetFolder()
{
    ASSERT(m_pNode);
    if (!m_pNode)
        return NULL;

    if (m_pNode->IsKindOf(Type_CFileVwFolderNode))
        return static_cast<CFileVwFolderNode*>(m_pNode);

    ASSERT(FALSE);
    return NULL;
}

STDMETHODIMP CAOProjectItemFolder::get_Kind(
    /* [out, retval] */ BSTR  * lpbstrFileName)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEM);
    ExpectedPtrRet(lpbstrFileName);
    *lpbstrFileName = NULL;

    CComBSTR cbstrKind(vsProjectItemKindPhysicalFolder);
    if (cbstrKind.Length() == 0)
        return E_OUTOFMEMORY;

    *lpbstrFileName = cbstrKind.Detach();
    return S_OK;
}

STDMETHODIMP CAOProjectItemFolder::get_ProjectItems(
    /* [out] */ ProjectItems ** lppcReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECT);
    ExpectedPtrRet(lppcReturn);
    *lppcReturn = NULL;

    HRESULT hr = S_OK;
    
    if (!m_srpProjectItems)
    {
        hr = CACProjectItems::CreateInstance(GetFolder(), &m_srpProjectItems);
        IfFailRet(hr);
        ExpectedExprRet(m_srpProjectItems != NULL);
    }

    hr = m_srpProjectItems.CopyTo(lppcReturn);
    return hr;
}


//                                                     CAOProjectItemFolder
///////////////////////////////////////////////////////////////////////////




#ifndef USEDEFAULTSELECTION
///////////////////////////////////////////////////////////////////////////
//                                                          CAOSelectedItem

/* static */
HRESULT CAOSelectedItem::CreateInstance(
    /* [in]  */ CFileVwFileNode* pNode,
    /* [out] */ SelectedItem **  ppSelectedItem)
{
    ExpectedPtrRet(pNode);
    ExpectedPtrRet(ppSelectedItem);
    *ppSelectedItem = NULL;

    CComObject<CAOSelectedItem>* pco = NULL;
    HRESULT hr = CComObject<CAOSelectedItem>::CreateInstance(&pco);
    IfFailRet(hr);

    pco->AddRef();
    hr = pco->Init(pNode);
    if (SUCCEEDED(hr))
    {
        hr = pco->QueryInterface(IID_SelectedItem, (void**)ppSelectedItem);
    }
    pco->Release();
    return hr;
}

HRESULT CAOSelectedItem::Init(CFileVwFileNode * pNode)
{
    ExpectedPtrRet(pNode);
    m_pNode = pNode;
    return S_OK;
}


STDMETHODIMP CAOSelectedItem::get_Collection(
    /* [out, retval] */ SelectedItems ** lppReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOSELECTEDITEM);
    ExpectedPtrRet(lppReturn);
    *lppReturn = NULL;

    HRESULT hr = S_OK;

    CComPtr<_DTE> srpDTE;
    hr = _VxModule.QueryService(SID_SDTE, IID__DTE, (void **) &srpDTE);
    IfFailRet(hr);

    hr = srpDTE->get_SelectedItems(lppReturn);
    IfFailRet(hr);

    return hr;
}


STDMETHODIMP CAOSelectedItem::get_DTE(
    /* [out, retval] */ DTE ** lppReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOSELECTEDITEM);
    ExpectedPtrRet(lppReturn);
    *lppReturn = NULL;

    HRESULT hr = _VxModule.QueryService(SID_SDTE, IID__DTE, (void **)lppReturn);
    return hr;
}


STDMETHODIMP CAOSelectedItem::get_Project(
    /* [out, retval] */ Project ** lppReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOSELECTEDITEM);
    ExpectedPtrRet(lppReturn);
    *lppReturn = NULL;

    HRESULT hr = S_OK;
    CComPtr<ProjectItem> srpProjectItem;
    hr = get_ProjectItem(&srpProjectItem);
    IfFailRet(hr);
    ExpectedExprRet(srpProjectItem != NULL);

    CComPtr<ProjectItems> srpProjectItems;
    hr =  srpProjectItem->get_ProjectItems(&srpProjectItems);
    IfFailRet(hr);
    ExpectedExprRet(srpProjectItems != NULL);
    //NOTE: You need to walk up the tree of ProjectItems if you 
    //have more than one level.

    CComPtr<IDispatch> srpIDispatch;
    hr = srpProjectItems->get_Parent(&srpIDispatch);
    IfFailRet(hr);
    ExpectedExprRet(srpIDispatch != NULL);

    hr = srpIDispatch->QueryInterface(IID_Project, (void**)lppReturn );
    IfFailRet(hr);

    return hr;
}

STDMETHODIMP CAOSelectedItem::get_ProjectItem(
    /* [out, retval] */ ProjectItem ** lppReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOSELECTEDITEM);
    ExpectedPtrRet(lppReturn);
    *lppReturn = NULL;

    HRESULT hr = S_OK;
    CComVariant cvar;
    hr = m_pNode->GetProperty(VSHPROPID_ExtObject, &cvar);
    IfFailRet(hr);
    ExpectedExprRet(VT_DISPATCH == V_VT(&cvar));

    hr = cvar.pdispVal->QueryInterface(IID_ProjectItem, (void**) lppReturn);
    IfFailRet(hr);

    return hr;
}



STDMETHODIMP CAOSelectedItem::get_Name(
    /* [out, retval] */ BSTR  * lpbstrReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOSELECTEDITEM);
    ExpectedPtrRet(lpbstrReturn);
    *lpbstrReturn = NULL;
    return m_pNode->get_FileName(lpbstrReturn);
}


STDMETHODIMP CAOSelectedItem::get_InfoCount(
    /* [out, retval] */ short  * lpnCount)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOSELECTEDITEM);
    ExpectedPtrRet(lpnCount);
    *lpnCount = 0;
    return S_OK;
}


STDMETHODIMP CAOSelectedItem::get_Info(
    /* [in]          */ short      Index, 
    /* [out, retval] */ VARIANT  * lpbstrReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOSELECTEDITEM);
    ExpectedPtrRet(lpbstrReturn);
    return E_INVALIDARG;
}


//                                                          CAOSelectedItem
///////////////////////////////////////////////////////////////////////////
#endif //USEDEFAULTSELECTION
