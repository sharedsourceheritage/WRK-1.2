//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
//  File:   vsdoc.h
//  Area:   DocObj Hosting
//
//  Contents:
//      DocObj Hosting
//
// Microsoft Confidential
// Copyright 1997 - 2000 Microsoft Corporation. All Rights Reserved.
//
//-----------------------------------------------------------------------------
#include "hu_pch.h"
#include "vsdoc.h"
#include <objext.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-----------------------------------------------------------------------------
// VsLocalCreateInstance	
//-----------------------------------------------------------------------------
HRESULT VsLocalCreateInstance
(
	IServiceProvider* pSP, 
	REFCLSID clsid,
	IUnknown * punkOuter,
	DWORD dwFlags,
	REFIID riid,
	void **ppvObj
)
{
	ASSERT(pSP);

	CComPtr<ILocalRegistry>	srpLocalReg;
	HRESULT hr = pSP->QueryService(SID_SLocalRegistry,
							IID_ILocalRegistry,
							(void**) &srpLocalReg);
	if(SUCCEEDED(hr))
	{
		hr = srpLocalReg->CreateInstance(clsid, punkOuter, riid, dwFlags, ppvObj);
	}

	return hr;
}

//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::IsDocumentOpen	
//-----------------------------------------------------------------------------
BOOL CVsDocBaseTemplate::IsDocumentOpen(
	LPCOLESTR pszMkDocument,
	IVsUIHierarchy* pVsUIHierarchy,
	VSITEMID vsitemid,
	IServiceProvider *pServiceProvider,
	BOOL fActivate,
	IVsWindowFrame **ppDocumentFrame)
{
	BOOL fOpen = FALSE;

	ASSERT(pszMkDocument);
	ASSERT(pVsUIHierarchy);
	ASSERT(pServiceProvider);

	if (ppDocumentFrame)
		*ppDocumentFrame = NULL;
		
	CComPtr<IVsUIShellOpenDocument>	srpShell;
	HRESULT hr = pServiceProvider->QueryService(
					SID_SVsUIShellOpenDocument,
					IID_IVsUIShellOpenDocument,
					(void **)&srpShell);

	if (SUCCEEDED(hr))
	{
		CComPtr<IVsUIHierarchy> srpHierOpen;
		CComPtr<IVsWindowFrame> srpDocFrame;
		VSITEMID itemidOpen;
		
		hr = srpShell->IsDocumentOpen(
				CComQIPtr<IVsUIHierarchy>( pVsUIHierarchy ),	// make sure we pass a controlling IVsUIHierarchy*, as opposed to a cast pointer
				vsitemid,
				pszMkDocument,
				GUID_NULL,
				(fActivate) ? IDO_ActivateIfOpen : (VSIDOFLAGS)0,
				&srpHierOpen,
				&itemidOpen,
				&srpDocFrame,
				&fOpen);

		if (SUCCEEDED(hr))
			*ppDocumentFrame = srpDocFrame.Detach();
	}

	return (SUCCEEDED(hr) ? fOpen : FALSE);
}

//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::GetOpenDocument	
//-----------------------------------------------------------------------------
HRESULT CVsDocBaseTemplate::GetOpenDocument(
	LPCOLESTR pszMkDocument,
	IVsUIHierarchy* pVsUIHierarchy,
	VSITEMID vsitemid,
	IServiceProvider *pServiceProvider,
	IVsWindowFrame **ppDocFrame /*=NULL*/,
	IVsPersistDocData **ppDocData /*=NULL*/)
{
	HRESULT hr = S_OK;

	if (ppDocFrame!=NULL)
		*ppDocFrame = NULL;
	if (ppDocData!=NULL)
		*ppDocData = NULL;

	CComPtr<IVsWindowFrame> srpDocFrame;
	BOOL fOpen = IsDocumentOpen(
		pszMkDocument,
		pVsUIHierarchy,
		vsitemid,
		pServiceProvider,
		FALSE,
		&srpDocFrame);
	hr = fOpen ? S_OK : S_FALSE;
	
	if (hr==S_OK)
	{
		if (ppDocData!=NULL)
		{
			ASSERT(srpDocFrame);

			CComVariant var;
			hr = srpDocFrame->GetProperty(VSFPROPID_DocData, &var);
			
			CComPtr<IVsPersistDocData> srpDocData;
			if (SUCCEEDED(hr))
			{
				ASSERT(var.vt==VT_UNKNOWN);
				IUnknown *punkDocData = var.punkVal;
				hr = punkDocData->QueryInterface(IID_IVsPersistDocData, (void**)&srpDocData);
			}

			if (SUCCEEDED(hr))
			{
				*ppDocData = srpDocData.Detach();
			}
		}
		
		if (ppDocFrame!=NULL)
		{
			*ppDocFrame = srpDocFrame.Detach();
		}
	}

	return hr;
}

//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::CreateFrame	
//-----------------------------------------------------------------------------
HRESULT	CVsDocBaseTemplate::CreateFrame(
	LPCOLESTR pszMkDocument,
	CVsDoc*	pDoc, 
	IVsUIHierarchy* pVsUIHierarchy,
	VSITEMID vsitemid,
	IServiceProvider *pServiceProvider,
	IVsWindowFrame **ppDocumentFrame)
{
	USES_CONVERSION;

	ASSERT(pDoc);
	ASSERT(pServiceProvider);

	// Get DocData object
	CComPtr<IVsPersistDocData> srpDocData;
	HRESULT hr = pDoc->QueryInterface(IID_IVsPersistDocData, (void**)&srpDocData);

	// Get DocView object
	CComPtr<IUnknown> srpDocObj;
	if (SUCCEEDED(hr))
	{
		hr = pDoc->GetOleObject()->QueryInterface(IID_IUnknown, (void**)&srpDocObj);
	}

	// Frame Caption
	CString strCaption;
	if (SUCCEEDED(hr))
	{
		pDoc->GetFrameCaption(strCaption);
	}

	// Create frame
	VSCREATEDOCWIN grfDynamicCreateFlags = pDoc->GetDynamicCreateFlags();
	if (SUCCEEDED(hr) && pVsUIHierarchy!=NULL)
	{
		CComPtr<IVsUIShell> srpUIShell;
		hr = pServiceProvider->QueryService(
				SID_SVsUIShell,
				IID_IVsUIShell,
				(void **)&srpUIShell);

		if (SUCCEEDED(hr))
		{
			BOOL bDefaultPosition;
			hr = srpUIShell->CreateDocumentWindow(
					m_grfCreateFrame|grfDynamicCreateFlags,
					pszMkDocument,
					CComQIPtr<IVsUIHierarchy>( pVsUIHierarchy ), // make sure we pass a controlling IVsUIHierarchy*, as opposed to a cast pointer
					vsitemid,
					srpDocObj,
					srpDocData,
					m_clsid,
					NULL,		// pszPhysicalView
					(m_guidCmdUI!=IID_NULL ? m_guidCmdUI : m_clsid),
					pServiceProvider,
					pszMkDocument,
					NULL,
					&bDefaultPosition,
					ppDocumentFrame);
		}
	}
	else
	{
		// Create frame via External Files Service
		CComPtr<IVsExternalFilesManager> srpExternalFilesManager;
		hr = pServiceProvider->QueryService(
						SID_SVsExternalFilesManager,
						IID_IVsExternalFilesManager,
						(void **)&srpExternalFilesManager);

		if (SUCCEEDED(hr))
		{
			BOOL bDefPosition;
			hr = srpExternalFilesManager->AddDocument(
					m_grfCreateFrame|grfDynamicCreateFlags,
					pszMkDocument,
					srpDocObj,
					srpDocData,
					GUID_NULL,
					NULL,			// pszPhysicalView
					(m_guidCmdUI!=IID_NULL ? m_guidCmdUI : m_clsid),
					T2COLE(strCaption),
					NULL,
					&bDefPosition,
					ppDocumentFrame);
		}
	}

	if (SUCCEEDED(hr))
	{
		ASSERT(*ppDocumentFrame);
		pDoc->SetDocumentFrame(*ppDocumentFrame);

		//$BUG: Shell ignores caption passed to CreateDocumentWindow()
		pDoc->UpdateTitle();
	}

	return hr;
}

//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::ComposeMkDocument	
//-----------------------------------------------------------------------------
void CVsDocBaseTemplate::ComposeMkDocument(LPCTSTR szMkDocument, CString &strMkDocument)
{
	UINT idsEditorType = GetEditorType();

	if (szMkDocument && idsEditorType)
	{
		CString strEditorType;
		strEditorType.LoadString(idsEditorType);

		ASSERT(!strEditorType.IsEmpty());
		strMkDocument.Format(_T("%s : %s"), szMkDocument, strEditorType);
	}
	else
		strMkDocument = szMkDocument;
}

//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::AddDocument	
//-----------------------------------------------------------------------------
void CVsDocBaseTemplate::AddDocument(CVsDoc *pDoc)
{
	ASSERT(pDoc);

	m_Documents.AddTail(pDoc);
	pDoc->AddRef();

	pDoc->SetTemplate(this);
}

//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::RemoveDocument	
//-----------------------------------------------------------------------------
void CVsDocBaseTemplate::RemoveDocument(CVsDoc *pDoc)
{
	ASSERT(pDoc);

	POSITION pos = m_Documents.Find(pDoc);
	if (pos != NULL)
	{
		RemoveDocument(pos);
	}
}

//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::RemoveDocument	
//-----------------------------------------------------------------------------
void CVsDocBaseTemplate::RemoveDocument(POSITION pos)
{
	CVsDoc *pDoc = m_Documents.GetAt(pos);
	ASSERT(pDoc);

	m_Documents.RemoveAt(pos);
	pDoc->SetTemplate(NULL);
	pDoc->Release();
}

//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::RemoveAllDocuments	
//-----------------------------------------------------------------------------
void CVsDocBaseTemplate::RemoveAllDocuments()
{
	POSITION pos;
	while ((pos = m_Documents.GetHeadPosition())!=NULL)
	{
		RemoveDocument(pos);
	}
	ASSERT(m_Documents.GetCount()==0);
}

//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::CloseAllDocuments	
//-----------------------------------------------------------------------------
void CVsDocBaseTemplate::CloseAllDocuments(BOOL bPromptForSave)
{
	POSITION pos;
	while ((pos = m_Documents.GetHeadPosition())!=NULL)
	{
		HRESULT hr = GetDocAt(pos)->CloseDocumentFrame(bPromptForSave ? FRAMECLOSE_PromptSave : FRAMECLOSE_NoSave);
		ASSERT(SUCCEEDED(hr));
		hr;
	}

	ASSERT(m_Documents.GetCount()==0);
}


//-----------------------------------------------------------------------------
// CVsDocBaseTemplate::OnCloseDocument	
//-----------------------------------------------------------------------------
void CVsDocBaseTemplate::OnCloseDocument(CVsDoc *pDoc)
{
	ASSERT(pDoc);
	RemoveDocument(pDoc);
}

//-----------------------------------------------------------------------------
// CVsDoc::SetMkDocument	
//-----------------------------------------------------------------------------
void CVsDoc::SetMkDocument(LPCTSTR szMkDocument, BOOL fCompose /*=FALSE*/) 
{ 
	if (fCompose)
	{
		ASSERT(m_pTemplate);
		m_pTemplate->ComposeMkDocument(szMkDocument, m_strMkDocument);
	}
	else
	{
		m_strMkDocument = szMkDocument;
	}
}

//-----------------------------------------------------------------------------
// CVsDoc::SetEditorCaption
//-----------------------------------------------------------------------------
HRESULT CVsDoc::SetEditorCaption(LPCOLESTR szCaption)
{
	ASSERT(m_srpDocumentFrame);
	CComVariant srpvt(szCaption);

	return m_srpDocumentFrame->SetProperty(VSFPROPID_EditorCaption, srpvt);
}


//-----------------------------------------------------------------------------
// CVsDoc::SetTitle	
//-----------------------------------------------------------------------------
HRESULT CVsDoc::SetTitle(LPCOLESTR szCaption)
{
	ASSERT(m_srpDocumentFrame);
	CComVariant srpvt(szCaption);

	return m_srpDocumentFrame->SetProperty(VSFPROPID_OwnerCaption, srpvt);
}

//-----------------------------------------------------------------------------
// CVsDoc::UpdateTitle	
//-----------------------------------------------------------------------------
HRESULT CVsDoc::UpdateTitle()
{
	CString strCaption;
	GetFrameCaption(strCaption);

	USES_CONVERSION;
	return SetTitle(T2COLE(strCaption));
}

//-----------------------------------------------------------------------------
// CVsDoc::InitOrLoadPersistence	
//-----------------------------------------------------------------------------
HRESULT CVsDoc::InitOrLoadPersistence(LPCOLESTR pszMkDocument, BOOL fNew)
{
	HRESULT hr;

	m_fNew = fNew;
	if (m_fNew)
		hr = SetUntitledDocPath(pszMkDocument);
	else
		hr = LoadDocData(pszMkDocument);
	
	return hr;
}

//-----------------------------------------------------------------------------
// CVsDoc::CloseDocument	
//-----------------------------------------------------------------------------
void CVsDoc::CloseDocument()
{
	m_srpDocumentFrame.Release();

	if (m_pTemplate)
		m_pTemplate->OnCloseDocument(this);
}

//-----------------------------------------------------------------------------
// CVsDoc::CloseDocumentFrame	
//-----------------------------------------------------------------------------
HRESULT CVsDoc::CloseDocumentFrame(DWORD grfSaveOptions)
{
	ASSERT(m_srpDocumentFrame);
	return m_srpDocumentFrame->CloseFrame(grfSaveOptions);
}

//-----------------------------------------------------------------------------
// IVsPersistDocData
//-----------------------------------------------------------------------------
STDMETHODIMP CVsDoc::OnRegisterDocData( 
        /* [in] */ VSDOCCOOKIE docCookie,
        /* [in] */ IVsHierarchy __RPC_FAR *pHierNew,
        /* [in] */ VSITEMID itemidNew)
{
	return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// IVsPersistDocData
//-----------------------------------------------------------------------------
STDMETHODIMP CVsDoc::RenameDocData( 
        /* [in] */ VSRDTATTRIB grfAttribs,
        /* [in] */ IVsHierarchy __RPC_FAR *pHierNew,
        /* [in] */ VSITEMID itemidNew,
        /* [in] */ LPCOLESTR pszMkDocumentNew)
{
	return S_OK;
}
    
//-----------------------------------------------------------------------------
// IVsPersistDocData
//-----------------------------------------------------------------------------
STDMETHODIMP CVsDoc::IsDocDataReloadable( 
        /* [out] */ BOOL __RPC_FAR *pfReloadable)
{
	ASSERT(pfReloadable);
	HRESULT hr = E_POINTER;
	if(pfReloadable)
	{
		*pfReloadable = FALSE;
		hr = S_OK;
	}
	return hr;
}
    
//-----------------------------------------------------------------------------
// IVsPersistDocData
//-----------------------------------------------------------------------------
STDMETHODIMP CVsDoc::ReloadDocData( 
        /* [in] */ VSRELOADDOCDATA grfFlags)
{
	ASSERT(FALSE);
	return E_NOTIMPL;
}
