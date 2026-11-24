
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


/***************************************************************************
File name   : AutomationCollections.cpp
Description : Implementation of the following automation collections:
              1) class CACProjects 
              2) class CACProjectItems
***************************************************************************/

#include "stdafx.h"
#include "PrjInc.h"
#include "PrjNRoot.h"


///////////////////////////////////////////////////////////////////////////
//                                                              CACProjects

/* static */
HRESULT CACProjects::CreateInstance(
    /* [out] */ IDispatch **     ppIDispatch)
{
    ExpectedPtrRet(ppIDispatch);
    *ppIDispatch = NULL;

    CComObject<CACProjects>* pco = NULL;
    HRESULT hr = CComObject<CACProjects>::CreateInstance(&pco);
    IfFailRet(hr);

    pco->AddRef();
    hr = pco->QueryInterface(IID_IDispatch, (void**)ppIDispatch);
    pco->Release();
    return hr;
}


void CACProjects::Close()
{
    m_fClosed = true;
}


bool CACProjects::IsValid()
{
    return !m_fClosed;
}


STDMETHODIMP CACProjects::Item(
    /* [in] */          VARIANT     index, 
    /* [out, retval] */ Project **  lppcReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTS);
    ExpectedPtrRet(lppcReturn);
    *lppcReturn = NULL;

    HRESULT hr = E_FAIL;

    // Smartpointer to balance Enter/Exit automation
    CEnterAutomationFunction enterAutomation;
    
    long lCount = 0;
    hr = get_Count(&lCount);
    IfFailRet(hr);

    long lIndex = 0;
    BSTR bstrIndex = NULL;
    Variant2Value(index, lIndex, bstrIndex);

    if ( (lIndex > 0) && (lIndex <= lCount) )
    {
        VsHierList *pVsHierList = CVsHierarchy::m_pVsHierList;
        for (long i = 0 ; i < lIndex-1 ; i++)
        {
            ExpectedExprRet(pVsHierList != NULL);
            pVsHierList = pVsHierList->pNext;
        }

        ExpectedExprRet(pVsHierList != NULL);
        ExpectedExprRet(pVsHierList->pVsHierarchy != NULL);
        CComVariant varPunk;
        hr = pVsHierList->pVsHierarchy->GetProperty(VSITEMID_ROOT, VSHPROPID_ExtObject, &varPunk);
        IfFailRet(hr);

        ExpectedExprRet(varPunk.pdispVal != NULL);
        hr = varPunk.pdispVal->QueryInterface(IID_Project, (LPVOID*)lppcReturn);
        IfFailRet(hr);

        return hr;
    }
    else if (::SysStringLen(bstrIndex))
    {
        VsHierList * pVsHierList = CVsHierarchy::m_pVsHierList;
        for (long i = 0 ; i < lCount ; i++)
        {
            ExpectedExprRet(pVsHierList != NULL);
            ExpectedExprRet(pVsHierList->pVsHierarchy != NULL);
            CComVariant varPunk;
            hr = pVsHierList->pVsHierarchy->GetProperty(VSITEMID_ROOT, VSHPROPID_ExtObject, &varPunk);
            IfFailRet(hr);

            ExpectedExprRet(varPunk.pdispVal != NULL);
            CComPtr<Project> srpProject;
            hr = varPunk.pdispVal->QueryInterface(IID_Project, (LPVOID*)&srpProject);
            IfFailRet(hr);

            CComBSTR cbstrName;
            hr = srpProject->get_Name(&cbstrName);
            IfFailRet(hr);

            if (cbstrName == bstrIndex)
            {
                *lppcReturn = (Project*) srpProject.p;
                (*lppcReturn)->AddRef();
                return S_OK;
            }
            pVsHierList = pVsHierList->pNext;
        }
        // fail if we did not find the project
        return E_INVALIDARG;
    }
    else
        return E_INVALIDARG;

    return hr;
}


STDMETHODIMP CACProjects::get_Parent(
    /* [out, retval] */ DTE **lppaReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTS);
    ExpectedPtrRet(lppaReturn);
    return _VxModule.QueryService(SID_SDTE, IID__DTE, (void **)lppaReturn);
}


STDMETHODIMP CACProjects::get_Count(
    /* [out, retval] */ long  * lplReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTS);
    ExpectedPtrRet(lplReturn);
    *lplReturn = 0;

    VsHierList *pTemp = CVsHierarchy::m_pVsHierList;
    while(pTemp)
    {
        (*lplReturn)++;
        pTemp = pTemp->pNext;
    }

    return S_OK;
}


STDMETHODIMP CACProjects::_NewEnum(
    /* [out, retval] */ IUnknown **lppiuReturn)
{
     _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTS);
    HRESULT hr = S_OK;
    long lCount = 0;
    long lCurrItem = 0;
    typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > enumvar;
    enumvar *p = NULL;
    CComVariant *pVars = NULL;
    p = new enumvar;
    if (!p)
        return E_OUTOFMEMORY;

    // To avoid memory leaks we need to keep a reference to the object in a smart pointer.
    CComPtr<IUnknown> pUnk;
    hr = p->QueryInterface(IID_IUnknown, (void**)&pUnk);
    if ( FAILED(hr) )
    {
        delete p;
        goto Error;
    }

    long l;
    
    IfFailGo(get_Count(&lCount));
    if (lCount == 0)
    {
        IfFailGo(p->Init(NULL, NULL, NULL, AtlFlagCopy));
        IfFailGo(p->QueryInterface(IID_IUnknown, (void**)lppiuReturn));
        goto Error;
    }

    pVars = new CComVariant[lCount+1];
    if (!pVars)
    {
        hr = E_OUTOFMEMORY;
        goto Error;
    }

    for (l = 1 ; l < lCount+1 ; l++)
    {
        Project *pProj;
        CComVariant varIndex(l);
        IfFailGo(Item(varIndex, &pProj));
        pVars[l-1] = pProj;
        pProj->Release();
    }

    IfFailGo(p->Init(&pVars[0], &(pVars[lCount]), NULL, AtlFlagCopy));
    IfFailGo(p->QueryInterface(IID_IUnknown, (void**)lppiuReturn));

Error:
    if (pVars)
        delete []pVars;
    return hr;
}


STDMETHODIMP CACProjects::get_DTE(
    /* [out, retval] */ DTE **lppaReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTS);
    return get_Parent(lppaReturn);
}


STDMETHODIMP CACProjects::get_Properties(
    /* [out, retval] */ Properties **ppObject)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTS);
    ExpectedPtrRet(ppObject);
    *ppObject = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CACProjects::get_Kind(
        /* [out, retval] */ BSTR  *lpbstrReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTS);
    ExpectedPtrRet(lpbstrReturn);
    *lpbstrReturn = NULL;

    CComBSTR cbstrKind(szProjectsKind);
    if (cbstrKind.Length() == 0)
        return E_OUTOFMEMORY;

    *lpbstrReturn = cbstrKind.Detach();
    return S_OK;
}


//                                                              CACProjects
///////////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////////////
//                                                          CACProjectItems

/* static */
HRESULT CACProjectItems::CreateInstance(
    /* [in]  */ CFileVwProjNode* pProjNode,
    /* [out] */ ProjectItems**   ppProjectItems)
{
    ExpectedPtrRet(pProjNode);
    ExpectedPtrRet(ppProjectItems);
    *ppProjectItems = NULL;

    CComObject<CACProjectItems>* pco = NULL;
    HRESULT hr = CComObject<CACProjectItems>::CreateInstance(&pco);
    IfFailRet(hr);

    pco->AddRef();
    hr = pco->Init(pProjNode);
    if (SUCCEEDED(hr))
    {
        hr = pco->QueryInterface(IID_ProjectItems, (void**)ppProjectItems);
    }
    pco->Release();
    return hr;
}


HRESULT CACProjectItems::Init(
    /* [in] */ CFileVwProjNode* pProjNode)
{
    ExpectedPtrRet(pProjNode);
    m_pProjNode = pProjNode;
    return S_OK;
}


void CACProjectItems::Close()
{
    m_fClosed = true;
}


bool CACProjectItems::IsValid()
{
    return !m_fClosed;
}


STDMETHODIMP CACProjectItems::Item(
    /* [in]          */ VARIANT         index, 
    /* [out, retval] */ ProjectItem **  lppcReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(lppcReturn);
    *lppcReturn = NULL;

    HRESULT hr = S_OK;

    ExpectedExprRet(m_pProjNode);
    ExpectedExprRet(m_pProjNode->GetCVsHierarchy());
    ExpectedExprRet(m_pProjNode->GetCVsHierarchy()->GetRootNode());

    CComVariant cvarExtObject;
    CHierNode * pCHierNode = NULL;
    pCHierNode = m_pProjNode->GetCVsHierarchy()->GetRootNode()->GetNodeByVariant(&index);
    if (!pCHierNode)
        return E_FAIL;

    hr = pCHierNode->GetProperty(VSHPROPID_ExtObject, &cvarExtObject);
    IfFailRet(hr);

    hr = cvarExtObject.pdispVal->QueryInterface(IID_ProjectItem, (LPVOID*)lppcReturn);
    return hr;
}


STDMETHODIMP CACProjectItems::get_Parent(
    /* [out, retval] */ IDispatch **    lppptReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(lppptReturn);
    *lppptReturn = NULL;

    ExpectedExprRet(m_pProjNode);
    HRESULT hr = m_pProjNode->GetAutomationObject(lppptReturn);
    return hr;
}


STDMETHODIMP CACProjectItems::get_Count(
        /* [out, retval] */ long  * lplReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(lplReturn);
    *lplReturn = NULL;

    ExpectedExprRet(m_pProjNode);
    *lplReturn = m_pProjNode->GetCount(/* BOOL fDisplayOnly = TRUE */ FALSE /*inlude hidden nodes*/);
    return S_OK;
}


STDMETHODIMP CACProjectItems::_NewEnum(
    /* [out, retval] */ IUnknown ** lppiuReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(lppiuReturn);
    *lppiuReturn = NULL;

    HRESULT hr = S_OK;
    long l;
    long lCount = 0;
    long lCurrItem = 0;
    typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > enumvar;
    enumvar *p = NULL;
    CComVariant *pVars = NULL;
    CComPtr<IUnknown> srpUnk;
    p = new enumvar;
    if (!p)
    {
        hr = E_OUTOFMEMORY;
        goto Error;
    }
    // Store in a smart pointer a reference to the object pointed by p to avoid
    // memory leaks in case of unexpected exit.
    hr = p->QueryInterface(IID_IUnknown, (void**)&srpUnk);
    if ( FAILED(hr) )
    {
        delete p;
        goto Error;
    }

    hr = get_Count(&lCount);
    IfFailGo(hr);

    if (lCount == 0)
    {
        hr = p->Init(NULL, NULL, NULL, AtlFlagCopy);
        IfFailGo(hr);
        hr = p->QueryInterface(IID_IUnknown, (void**)lppiuReturn);
        IfFailGo(hr);
        goto Error;
    }

    pVars = new CComVariant[lCount+1];
    if (!pVars)
    {
        hr = E_OUTOFMEMORY;
        goto Error;
    }

    for (l = 1 ; l < lCount+1 ; l++)
    {
        ProjectItem *pPI;
        CComVariant varIndex(l);
        IfFailGo(Item(varIndex, &pPI));
        pVars[l-1] = pPI;
        pPI->Release();
    }

    hr = p->Init(&pVars[0], &(pVars[lCount]), NULL, AtlFlagCopy);
    IfFailGo(hr);

    hr = p->QueryInterface(IID_IUnknown, (void**)lppiuReturn);
    IfFailGo(hr);

Error:
    if (pVars)
        delete []pVars;
    return hr;
}


STDMETHODIMP CACProjectItems::get_DTE(
    /* [out, retval] */ DTE **  lppaReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(lppaReturn);
    *lppaReturn = NULL;

    HRESULT hr = _VxModule.QueryService(SID_SDTE, IID__DTE, (void **)lppaReturn);
    return hr;
}


STDMETHODIMP CACProjectItems::get_Kind(
    /* [out, retval] */ BSTR  * lpbstrReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(lpbstrReturn);
    *lpbstrReturn = NULL;

    CComBSTR cbstrKind(szProjectItemsKind);
    if (cbstrKind.Length() == 0)
        return E_OUTOFMEMORY;

    *lpbstrReturn = cbstrKind.Detach();
    return S_OK;
}


STDMETHODIMP CACProjectItems::AddFromFile(
    /* [in]          */ BSTR            FileName, 
    /* [out, retval] */ ProjectItem **  lppcReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(lppcReturn);
    *lppcReturn = NULL;

    HRESULT hr = S_OK;
    USES_CONVERSION;

    // Smartpointer to balance Enter/Exit automation
    CEnterAutomationFunction enterAutomation;

    CFileVwFileNode *pFileNode;
    hr = m_pProjNode->AddExistingFile(W2CT(FileName), &pFileNode);
    _IfFailRet(hr);

    CComVariant cvar;
    hr = pFileNode->GetProperty(VSHPROPID_ExtObject, &cvar);
    IfFailRet(hr);

    hr = cvar.pdispVal->QueryInterface(IID_ProjectItem, (LPVOID*)lppcReturn);
    return hr;
}



STDMETHODIMP CACProjectItems::AddFromTemplate(
    /* [in]          */ BSTR            FileName, 
    /* [in]          */ BSTR            Name, 
    /* [out, retval] */ ProjectItem **  lppcReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(lppcReturn);
    *lppcReturn = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CACProjectItems::AddFromDirectory(
    /* [in]          */ BSTR            Directory, 
    /* [out, retval] */ ProjectItem **  lppcReturn)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(lppcReturn);
    *lppcReturn = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CACProjectItems::get_ContainingProject(
    /* [out, retval] */ Project **ppProject)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(ppProject);
    *ppProject = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CACProjectItems::AddFolder(
    /* [in]          */ BSTR            Name, 
    /* [in]          */ BSTR            Kind, 
    /* [out, retval] */ ProjectItem **  ppProjectItem)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(ppProjectItem);
    *ppProjectItem = NULL;
    return E_NOTIMPL;
}


STDMETHODIMP CACProjectItems::AddFromFileCopy(
        /* [in]          */ BSTR            FilePath, 
        /* [out, retval] */ ProjectItem **  ppProjectItem)
{
    _IfNotValidRet(E_FAIL, IDS_E_AUTO_NOPROJECTITEMS);
    ExpectedPtrRet(ppProjectItem);
    *ppProjectItem = NULL;
    return E_NOTIMPL;
}

//                                                          CACProjectItems
///////////////////////////////////////////////////////////////////////////
