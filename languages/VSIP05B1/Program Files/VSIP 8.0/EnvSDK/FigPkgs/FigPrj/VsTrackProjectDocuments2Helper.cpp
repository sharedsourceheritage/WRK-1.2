
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsTrackProjectDocuments2Helper.cpp - implementation of 
// CVsTrackProjectDocuments2Helper

// Calls IVsTrackProjectDocuments2 methods to notify other hierarchies 
// that we are about to change/have changed a file.

#include "stdafx.h"
#include "PrjInc.h"

CVsTrackProjectDocuments2Helper::CVsTrackProjectDocuments2Helper(
    /* [in] */ IVsProject* pIVsProject)
{
    m_srpIVsProject = pIVsProject;
}


CComPtr<IVsTrackProjectDocuments2> 
CVsTrackProjectDocuments2Helper::GetIVsTrackProjectDocuments2()
{
    CComPtr<IVsTrackProjectDocuments2> srpIVsTrackProjectDocuments2;
    _VxModule.QueryService(
        SID_SVsTrackProjectDocuments,
        IID_IVsTrackProjectDocuments2,
        (void**)&srpIVsTrackProjectDocuments2);

    return srpIVsTrackProjectDocuments2;
}


HRESULT CVsTrackProjectDocuments2Helper::CanAddItem(
    /* [in] */ LPCOLESTR          pszFile,
    /* [in] */ ProjectEventFlags  flags /* = ProjectEventFlags_None */)
{
    ExpectedPtrRet(pszFile);

    HRESULT hr = S_OK;

    CComPtr<IVsTrackProjectDocuments2>  srpIVsTrackProjectDocuments2;
    srpIVsTrackProjectDocuments2 = GetIVsTrackProjectDocuments2();
    if (!srpIVsTrackProjectDocuments2)
    {
        ASSERT(FALSE);
        return  S_OK;
    }

    VSQUERYADDFILERESULTS fSummaryResult = VSQUERYADDFILERESULTS_AddOK;
    VSQUERYADDFILEFLAGS   fInputFlags = (flags & ProjectEventFlags_IsNestedProject) ? VSQUERYADDFILEFLAGS_IsNestedProjectFile : VSQUERYADDFILEFLAGS_NoFlags;

    if( SUCCEEDED( srpIVsTrackProjectDocuments2->OnQueryAddFiles( 
            m_srpIVsProject,
            1,
            &pszFile,
            &fInputFlags,
            &fSummaryResult,
            NULL ) )
      )
    {
        if( VSQUERYADDFILERESULTS_AddNotOK == fSummaryResult ) 
            hr = E_ABORT;
    }

    return hr;
}


void CVsTrackProjectDocuments2Helper::OnItemAdded( 
    /* [in] */ CHierNode*         pCHierNode,
    /* [in] */ ProjectEventFlags  flags /* = ProjectEventFlags_None */)
{
    if (!pCHierNode)
    {
        ASSERT(FALSE);
        return;
    }

    CComPtr<IVsTrackProjectDocuments2>  srpIVsTrackProjectDocuments2;
    srpIVsTrackProjectDocuments2 = GetIVsTrackProjectDocuments2();
    if (!srpIVsTrackProjectDocuments2)
    {
        ASSERT(FALSE);
        return;
    }

    CComBSTR cbstrMkDokument;
    HRESULT hr = m_srpIVsProject->GetMkDocument(pCHierNode->GetVsItemID(), &cbstrMkDokument);
    if (FAILED(hr))
    {
        ASSERT(FALSE);
        return;
    }
        
    VSADDFILEFLAGS fInputFlags = (flags & ProjectEventFlags_IsNestedProject) ? VSADDFILEFLAGS_IsNestedProjectFile : VSADDFILEFLAGS_NoFlags;

    BSTR rgbstrDocumentsNames[] = {cbstrMkDokument};
    hr = srpIVsTrackProjectDocuments2->OnAfterAddFilesEx( 
        m_srpIVsProject, 
        1, 
        rgbstrDocumentsNames,
        &fInputFlags
        );
    ASSERT(SUCCEEDED(hr));        

    return;
}


HRESULT CVsTrackProjectDocuments2Helper::CanRenameItem( 
    /* [in] */ CHierNode*         pCHierNode,
    /* [in] */ LPCOLESTR          pszNewName,
    /* [in] */ ProjectEventFlags  flags /* = ProjectEventFlags_None */)
{
    ExpectedPtrRet(pCHierNode);
    ExpectedPtrRet(pszNewName);

    CComPtr<IVsTrackProjectDocuments2>  srpIVsTrackProjectDocuments2;
    srpIVsTrackProjectDocuments2 = GetIVsTrackProjectDocuments2();
    if (!srpIVsTrackProjectDocuments2)
    {
        ASSERT(FALSE);
        return S_OK;
    }

    CComBSTR cbstrMkDokument;
    HRESULT hr = m_srpIVsProject->GetMkDocument(pCHierNode->GetVsItemID(), &cbstrMkDokument);
    if (FAILED(hr))
    {
        ASSERT(FALSE);
        return S_OK;
    }

    BOOL fRenameCanContinue = FALSE;
    VSQUERYADDFILERESULTS *pSummaryResult = NULL;

    if( SUCCEEDED( srpIVsTrackProjectDocuments2->OnQueryRenameFile( 
            m_srpIVsProject,
            cbstrMkDokument,
            pszNewName,
            (flags & ProjectEventFlags_IsNestedProject) ? VSRENAMEFILEFLAGS_IsNestedProjectFile : VSRENAMEFILEFLAGS_NoFlags,
            &fRenameCanContinue) )
      )
    {
        if( !fRenameCanContinue ) 
            hr = E_ABORT;
    }

    return hr;
}


void CVsTrackProjectDocuments2Helper::OnItemRenamed(
    /* [in] */ CHierNode*         pCHierNode,
    /* [in] */ LPCOLESTR          pszOldName,
    /* [in] */ ProjectEventFlags  flags /* = ProjectEventFlags_None */)
{
    if (!pCHierNode || !pszOldName)
    {
        ASSERT(FALSE);
        return;
    }

    CComPtr<IVsTrackProjectDocuments2>  srpIVsTrackProjectDocuments2;
    srpIVsTrackProjectDocuments2 = GetIVsTrackProjectDocuments2();
    if (!srpIVsTrackProjectDocuments2)
    {
        ASSERT(FALSE);
        return;
    }

    CComBSTR cbstrMkDokument;
    HRESULT hr = m_srpIVsProject->GetMkDocument(pCHierNode->GetVsItemID(), &cbstrMkDokument);
    if (FAILED(hr))
    {
        ASSERT(FALSE);
        return;
    }
    
    hr = srpIVsTrackProjectDocuments2->OnAfterRenameFile( 
                m_srpIVsProject,
                pszOldName,
                cbstrMkDokument,
                (flags & ProjectEventFlags_IsNestedProject) ? VSRENAMEFILEFLAGS_IsNestedProjectFile : VSRENAMEFILEFLAGS_NoFlags );
    ASSERT(SUCCEEDED(hr));        

    return;
}


HRESULT CVsTrackProjectDocuments2Helper::CanDeleteItem(
    /* [in] */ CHierNode*         pCHierNode,
    /* [in] */ ProjectEventFlags  flags /* = ProjectEventFlags_None */)
{
    ExpectedPtrRet(pCHierNode);

    CComPtr<IVsTrackProjectDocuments2>  srpIVsTrackProjectDocuments2;
    srpIVsTrackProjectDocuments2 = GetIVsTrackProjectDocuments2();
    if (!srpIVsTrackProjectDocuments2)
    {
        ASSERT(FALSE);
        return S_OK;
    }

    CComBSTR cbstrMkDokument;
    HRESULT hr = m_srpIVsProject->GetMkDocument(pCHierNode->GetVsItemID(), &cbstrMkDokument);
    if (FAILED(hr))
    {
        ASSERT(FALSE);
        return S_OK;
    }

    VSQUERYREMOVEFILEFLAGS flagsRemove     = (flags & ProjectEventFlags_IsNestedProject) ? VSQUERYREMOVEFILEFLAGS_IsNestedProjectFile : VSQUERYREMOVEFILEFLAGS_NoFlags;
    VSQUERYREMOVEFILERESULTS nResult = VSQUERYREMOVEFILERESULTS_RemoveNotOK;
    LPCOLESTR rgstrFiles[] = { cbstrMkDokument };
    
    if(SUCCEEDED(srpIVsTrackProjectDocuments2->OnQueryRemoveFiles( 
            m_srpIVsProject,
            1,
            rgstrFiles,
            &flagsRemove,
            &nResult,
            NULL)))
    {
        if(nResult != VSQUERYREMOVEFILERESULTS_RemoveOK)
            return E_ABORT;
    }

    return S_OK;
}


void CVsTrackProjectDocuments2Helper::OnItemDeleted(
    /* [in] */ LPCOLESTR          pszFile,
    /* [in] */ ProjectEventFlags  flags /* = ProjectEventFlags_None */)
{
    if (!pszFile)
    {
        ASSERT(FALSE);
        return;
    }

    CComPtr<IVsTrackProjectDocuments2>  srpIVsTrackProjectDocuments2;
    srpIVsTrackProjectDocuments2 = GetIVsTrackProjectDocuments2();
    if (!srpIVsTrackProjectDocuments2)
    {
        ASSERT(FALSE);
        return;
    }

    VSREMOVEFILEFLAGS flagsRemove = (flags & ProjectEventFlags_IsNestedProject) ? VSREMOVEFILEFLAGS_IsNestedProjectFile : VSREMOVEFILEFLAGS_NoFlags;
    
    HRESULT hr = srpIVsTrackProjectDocuments2->OnAfterRemoveFiles( 
                m_srpIVsProject,
                1,
                &pszFile,
                &flagsRemove );
    ASSERT(SUCCEEDED(hr));        

    return;
}
