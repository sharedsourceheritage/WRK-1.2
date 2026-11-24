
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// EdtFact.cpp : Implementation of CBscEditorFactory

#include "stdafx.h" 
#include "guids.h"
#include "EdtFact.h"
#include "EdCommon.h"
#include "BscEdtUI\resource.h"

/////////////////////////////////////////////////////////////////////////////
// CBscEditorFactory

CBscEditorFactory::CBscEditorFactory()
{
    ATLTRACE(TEXT(">> Constructing CBscEditorFactory: 0x%X\n"), this);
    m_fZombie = FALSE;
    m_pCVsPkg = NULL;
    m_srpEdFactSiteSP = NULL;
}

CBscEditorFactory::~CBscEditorFactory()
{
    ATLTRACE(TEXT(">> Destructing CBscEditorFactory: 0x%X\n"), this);
}

bool CBscEditorFactory::FInit(CVsPackage *pCVsPkg)
{
    ATLTRACE(TEXT("CBscEditorFactory::FInit\n"));
    _ASSERTE(!m_pCVsPkg);       // recursion guard
    m_pCVsPkg = pCVsPkg;
    return true;
}

/*****************************************************************************
** IVsEditorFactory Implementation
*****************************************************************************/

// An editor factory acts like an OLE ClassFactory for instantiating 
// document view objects (DocView) and document data objects (DocData). 
// The editor factory architecture enables creating editors that support 
// data/view separation (e.g. an editor could support the Window.NewWindow 
// functionality). The Shell helps coordinate tracking whether a document 
// is already open via a service called the RunningDocumentTable (a.k.a. RDT). 
// When an editor factory is asked to create a secondary view then 
// punkDocDataExisting will be non-NULL. This punkDocDataExisting must be 
// the punkDocData object that is registered in the RDT.
//
STDMETHODIMP CBscEditorFactory::CreateEditorInstance( 
    /*[in] */ VSCREATEEDITORFLAGS   grfCreateDoc,       // only open or silent is valid
    /*[in] */ LPCOLESTR             pszMkDocument,      // moniker file name
    /*[in] */ LPCOLESTR             pszPhysicalView,    // physical view name
    /*[in] */ IVsHierarchy*         pvHier,             // project
    /*[in] */ VSITEMID              itemid,
    /*[in] */ IUnknown*             punkDocDataExisting,// buffer already created ?
    /*[out]*/ IUnknown**            ppunkDocView,       // return our view
    /*[out]*/ IUnknown**            ppunkDocData,       // return our buffer
    /*[out]*/ BSTR*                 pbstrEditorCaption, // return our part of the caption [Custom] and [Readonly] if applicable
    /*[out]*/ GUID*                 pguidCmdUI,         // the package guid for our menus (in the .ctc file in the satelite dll too)
    /*[out]*/ VSEDITORCREATEDOCWIN* pgrfCDW)            // flags to be passed to CreateDocumentWindow
{

    ATLTRACE(TEXT("CBscEditorFactory::CreateEditorInstance\n"));

    if (m_fZombie)
        return E_UNEXPECTED;

    HRESULT hr = NOERROR;

    // perform parameter validation and initialization
    if (ppunkDocView) *ppunkDocView = NULL; else hr = E_INVALIDARG;
    if (ppunkDocData) *ppunkDocData = NULL; else hr = E_INVALIDARG;
    if (pbstrEditorCaption) *pbstrEditorCaption = NULL; else hr = E_INVALIDARG;
    if (pguidCmdUI) *pguidCmdUI = GUID_NULL; else hr = E_INVALIDARG;
    if (pgrfCDW) *pgrfCDW = NULL; else hr = E_INVALIDARG;
    if (pszPhysicalView != NULL) hr = E_INVALIDARG; // we support only a single physical view
    if (FAILED(hr))
        return hr;

    // only open or silent is valid
    if (! (grfCreateDoc & (CEF_OPENFILE | CEF_SILENT)) )
       return E_INVALIDARG;

    if(punkDocDataExisting != NULL)
    {
        // if the file is opened return VS_E_INCOMPATIBLEDOCDATA
        // the shell will ask the user to close it
        return VS_E_INCOMPATIBLEDOCDATA;
    }

    CComObject<CBscEditorDocument> *pDoc = new CComObject<CBscEditorDocument>;
    if (NULL == pDoc)
        return E_OUTOFMEMORY;

    CComPtr<IUnknown> srpIUnkBscEdtDoc;
    hr = pDoc->QueryInterface(IID_IUnknown, (void**)&srpIUnkBscEdtDoc);
    if (FAILED(hr))
    {
        delete pDoc;
        return hr;
    }

    hr = pDoc->HrInit(m_pCVsPkg);
    if (FAILED(hr))
        return hr;

    // setup editor caption
    CComBSTR cbstrEditorCaption;// our contribution to the caption
    cbstrEditorCaption.LoadString(IDS_EDITORCAPTION);
    *pbstrEditorCaption = cbstrEditorCaption.Detach(); 
    // When the file is read only the [ReadOnly] caption will be set during Load

    // The CmdUIGuid controls which menus and command accelerators should be available.
    *pguidCmdUI = GUID_BscEditorFactory;    // the package guid for our menus (in PkgCmdID.h, used in the .ctc file in the satelite dll too)

    // We have created only one object for both the DocData and the DocView so return it twice.
    srpIUnkBscEdtDoc.CopyTo(ppunkDocData);
    srpIUnkBscEdtDoc.CopyTo(ppunkDocView);
    
    *pgrfCDW = NULL; // we have no GUI the user could enter a cancel from

    return S_OK;

}


STDMETHODIMP CBscEditorFactory::SetSite( 
                    /*[in] */ IServiceProvider *pSP)
{
    ATLTRACE(TEXT("CBscEditorFactory::SetSite\n"));

    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    m_srpEdFactSiteSP = pSP;        // Note: assignment to a smart pointer does an AddRef()
    return NOERROR;
}


STDMETHODIMP CBscEditorFactory::Close(void)
{
    ATLTRACE(TEXT("CBscEditorFactory::Close\n"));

    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    m_fZombie = TRUE;
    m_srpEdFactSiteSP.Release();

    return NOERROR;
}


// This method is called before the CreateEditorInstance method
// to allow us to map LOGICAL views to PHYSICAL ones. Our Editor
// Factory supports only supports a single physical view (aka the
// text editor view)
//
// NOTE: Physical views are identified by a string of our choice with the 
// one constraint that the default/primary physical view for an editor  
// *MUST* use a NULL string as its physical view name (*pbstrPhysicalView = NULL).
//
STDMETHODIMP CBscEditorFactory::MapLogicalView( 
                    /*[in] */ REFGUID    rguidLogicalView,
                    /*[out]*/ BSTR      *pbstrPhysicalView)
{
    ATLTRACE(TEXT("CBscEditorFactory::MapLogicalView\n"));
    
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    if (!pbstrPhysicalView)
        return E_INVALIDARG;

    // we support only a single physical view
    *pbstrPhysicalView = NULL;      // initialize out parameter

    return S_OK;
}



