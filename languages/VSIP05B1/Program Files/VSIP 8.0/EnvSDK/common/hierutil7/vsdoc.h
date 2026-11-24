//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
//  File:   vsdoc.h
//  Area:   Shell DocObj Hosting
//
//  Contents:
//      Shell DocObj Hosting
//
// Microsoft Confidential
// Copyright 1997 - 2000 Microsoft Corporation. All Rights Reserved.
//
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef _VSDOC_H_
#define _VSDOC_H_

// Includes ------------------------------------------------------------------
#ifndef __AFX_H__           // If not use MFC
#ifndef __MFCINCL_H__
    #include "mfcincl.h"
#endif
#endif // __AFX_H__

// Forward References ---------------------------------------------------------
class CVsDocBaseTemplate;
class CVsDoc;
class CHierNode;

HRESULT VsLocalCreateInstance(
    IServiceProvider* pSP, 
    REFCLSID clsid,
    IUnknown * punkOuter,
    DWORD dwFlags,
    REFIID riid,
    void **ppvObj);

//-----------------------------------------------------------------------------
//  Class:  CVsDoc
//-----------------------------------------------------------------------------
class ATL_NO_VTABLE CVsDoc :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IVsPersistDocData
{
public:
    CVsDoc(void) :
        m_pTemplate(NULL),
        m_pNode(NULL),
        m_fNew(TRUE)
    {
    }

    virtual VSCREATEDOCWIN GetDynamicCreateFlags() { return 0; }
    virtual void GetFrameCaption(CString &strCaption) = 0;
    virtual HRESULT InitOrLoadPersistence(LPCOLESTR pszMkDocument, BOOL fNew);
    virtual void CloseDocument();
    HRESULT CloseDocumentFrame(DWORD grfSaveOptions);

    virtual HRESULT OnCreateFrame(IVsWindowFrame *pDocumentFrame)
        { return S_OK; 
        }

    virtual HRESULT OnPostCreateFrame(IVsWindowFrame *pDocumentFrame)
        { return S_OK; 
        }

    CVsDocBaseTemplate *GetTemplate() const
        { return m_pTemplate;
        }
    void SetTemplate(CVsDocBaseTemplate *pTemplate)
        { m_pTemplate = pTemplate;
        }
    IUnknown* GetOleObject() const
        { return m_srpObject;
        }
    void SetOleObject(IUnknown* pObject)
        { m_srpObject = pObject;
        }

    void SetMkDocument(LPCTSTR szMkDocument, BOOL fCompose = FALSE);
    LPCTSTR GetMkDocument() { return m_strMkDocument; }

    HRESULT SetEditorCaption(LPCOLESTR szCaption);
    HRESULT SetTitle(LPCOLESTR szCaption);
    HRESULT UpdateTitle();

    BOOL IsNew(void)
    {
        return m_fNew;
    }
    void SetNew(BOOL fNew)
    {
        m_fNew = fNew;
    }

    void SetDocumentFrame(IVsWindowFrame *pDocumentFrame) 
        { 
            m_srpDocumentFrame = pDocumentFrame;
        }

public:
    // IVsPersistDocData methods
    STDMETHOD(Close)()
        {
            CloseDocument();
            return S_OK;
        }
    virtual HRESULT STDMETHODCALLTYPE OnRegisterDocData( 
        /* [in] */ VSDOCCOOKIE docCookie,
        /* [in] */ IVsHierarchy __RPC_FAR *pHierNew,
        /* [in] */ VSITEMID itemidNew);
    
    virtual HRESULT STDMETHODCALLTYPE RenameDocData( 
        /* [in] */ VSRDTATTRIB grfAttribs,
        /* [in] */ IVsHierarchy __RPC_FAR *pHierNew,
        /* [in] */ VSITEMID itemidNew,
        /* [in] */ LPCOLESTR pszMkDocumentNew);
    
    virtual HRESULT STDMETHODCALLTYPE IsDocDataReloadable( 
        /* [out] */ BOOL __RPC_FAR *pfReloadable);
    
    virtual HRESULT STDMETHODCALLTYPE ReloadDocData( 
        /* [in] */ VSRELOADDOCDATA grfFlags);


BEGIN_COM_MAP(CVsDoc)
    COM_INTERFACE_ENTRY(IVsPersistDocData)
END_COM_MAP()

DECLARE_NOT_AGGREGATABLE(CVsDoc) 

protected:
    CVsDocBaseTemplate *m_pTemplate;
    CComPtr<IUnknown> m_srpObject;
    CString m_strMkDocument;
    CHierNode*                  m_pNode;        // node/VSITEMID doc should be associated with
    BOOL                        m_fNew;
    CComPtr<IVsWindowFrame> m_srpDocumentFrame;
};

//-----------------------------------------------------------------------------
//  Class:  CVSDocBaseTemplate
//-----------------------------------------------------------------------------
class CVsDocBaseTemplate
{
public:
    CVsDocBaseTemplate() 
        : m_grfCreateFrame(RDT_NonCreatable),
          m_clsid(IID_NULL), m_guidCmdUI(IID_NULL),
          m_fUseLocalCreateInstance(FALSE)
        {}

    ~CVsDocBaseTemplate() { RemoveAllDocuments(); }

    BOOL IsDocumentOpen(
        LPCOLESTR pszMkDocument,
        IVsUIHierarchy* pVsUIHierarchy,
        VSITEMID vsitemid,
        IServiceProvider *pServiceProvider,
        BOOL fActivate,
        IVsWindowFrame **ppDocumentFrame);
    HRESULT GetOpenDocument(
        LPCOLESTR pszMkDocument,
        IVsUIHierarchy* pVsUIHierarchy,
        VSITEMID vsitemid,
        IServiceProvider *pServiceProvider,
        IVsWindowFrame **ppDocFrame = NULL,
        IVsPersistDocData **ppDocData = NULL);
    
    virtual HRESULT CreateFrame(
        LPCOLESTR pszMkDocument,
        CVsDoc* pDocData, 
        IVsUIHierarchy* pVsUIHierarchy,
        VSITEMID vsitemid,
        IServiceProvider *pServiceProvider,
        IVsWindowFrame **ppDocumentFrame);
    void OnCloseDocument(CVsDoc *pDoc);

    POSITION GetFirstDocPosition() { return m_Documents.GetHeadPosition(); }
    CVsDoc* GetNextDoc(POSITION& rPos) { return m_Documents.GetNext(rPos); }
    CVsDoc* GetDocAt(POSITION Pos) { return m_Documents.GetAt(Pos); }
    int GetCount() { return m_Documents.GetCount(); }

    virtual void ComposeMkDocument(LPCTSTR szMkDocument, CString &strMkDocument);
    void CloseAllDocuments(BOOL bPromptForSave);

public:
    VSCREATEDOCWIN m_grfCreateFrame;

protected:
    virtual UINT GetEditorType() { return 0; }
    void AddDocument(CVsDoc *pDoc);
    void RemoveDocument(CVsDoc *pDoc);
    void RemoveDocument(POSITION pos);
    void RemoveAllDocuments();

protected:
    CVxTypedPtrList<CVxPtrList, CVsDoc*> m_Documents;
    CLSID m_clsid;
    GUID m_guidCmdUI;
    BOOL m_fUseLocalCreateInstance;
};

//-----------------------------------------------------------------------------
//  Class:  CVSDocTemplate
//-----------------------------------------------------------------------------
typedef enum tagVSDOCOPEN {
    VSDOCOPEN_NEW = 0x1,
    VSDOCOPEN_EXISTING = 0x2,
    VSDOCOPEN_HIDEEXISTING = 0x4
} VSDOCOPEN;

template<class VSDOC, class ARGTYPE> 
class CVSCompDocTemplate : public CVsDocBaseTemplate
{
public:
    HRESULT OpenOrActivateDocument(
        LPCOLESTR pszMkDocument,
        IVsUIHierarchy* pVsUIHierarchy,
        VSITEMID vsitemid,
        VSDOCOPEN grfOpen,
        IServiceProvider *pServiceProvider,
        ARGTYPE *pArg,
        IVsWindowFrame **ppDocumentFrame);
        
    HRESULT OpenDocument(
        LPCOLESTR pszMkDocument,
        IVsUIHierarchy* pVsUIHierarchy,
        VSITEMID vsitemid,
        VSDOCOPEN grfOpen,
        IServiceProvider *pServiceProvider,
        ARGTYPE *pArg,
        IVsWindowFrame **ppDocumentFrame);

    HRESULT DocCreateInstance(VSDOC** ppDoc, BOOL fNew);

    VSDOC* GetNextDoc(POSITION& rPos) 
        { return (VSDOC *)CVsDocBaseTemplate::GetNextDoc(rPos);
        }
    VSDOC* GetDocAt(POSITION Pos) 
        { return (VSDOC *)CVsDocBaseTemplate::GetDocAt(Pos);
        }
};

//-----------------------------------------------------------------------------
//  Class:  CVSDocTemplate
//-----------------------------------------------------------------------------
template<class VSDOC, class NODE> 
class CVSDocTemplate : public CVSCompDocTemplate<VSDOC, NODE>
{
public:
    CVSDocTemplate(){}

    HRESULT OpenOrActivateDocument(
        LPCOLESTR pszMkDocument,
        NODE* pNode,
        VSDOCOPEN grfOpen,
        IVsWindowFrame **ppDocumentFrame = NULL);
        
    HRESULT OpenDocument(
        LPCOLESTR pszMkDocument,
        NODE* pNode,
        VSDOCOPEN grfOpen);
        
    HRESULT OpenDocument(
        LPCOLESTR pszMkDocument,
        NODE* pNode,
        VSDOCOPEN grfOpen,
        IServiceProvider *pServiceProvider,
        IVsWindowFrame **ppDocumentFrame);

    HRESULT GetOpenDocument(
        NODE* pNode,
        IVsWindowFrame **ppDocFrame = NULL,
        IVsPersistDocData **ppDocData = NULL);
};

//-----------------------------------------------------------------------------
// CVSCompDocTemplate <VSDOC, ARGTYPE>::DocCreateInstance
//-----------------------------------------------------------------------------
template<class VSDOC, class ARGTYPE>
HRESULT CVSCompDocTemplate <VSDOC, ARGTYPE>::DocCreateInstance
(
VSDOC** ppDoc,
BOOL fNew
)
{
    ASSERT(ppDoc);
    *ppDoc = NULL;

    CComObject<VSDOC>* pDoc = NULL;
    HRESULT hr = CComObject<VSDOC>::CreateInstance(&pDoc);

    if (SUCCEEDED(hr))
    {
        ASSERT(pDoc);
        pDoc->SetNew(fNew);

        pDoc->AddRef();
        AddDocument(pDoc);
        *ppDoc = pDoc;
    }

    return hr;
}

//-----------------------------------------------------------------------------
// CVSCompDocTemplate <VSDOC, ARGTYPE>::OpenDocument
//-----------------------------------------------------------------------------
template<class VSDOC, class ARGTYPE>
HRESULT CVSCompDocTemplate<VSDOC, ARGTYPE>::OpenDocument(
    LPCOLESTR pszMkDocument,
    IVsUIHierarchy* pVsHierarchy,
    VSITEMID vsitemid,
    VSDOCOPEN grfOpen,
    IServiceProvider *pServiceProvider,
    ARGTYPE *pArg,
    IVsWindowFrame **ppDocumentFrame)
{
    if (ppDocumentFrame)
        *ppDocumentFrame = NULL;

    // Create DocData object
    CComPtr<VSDOC> srpDoc;
    HRESULT hr = DocCreateInstance(&srpDoc, (grfOpen == VSDOCOPEN_NEW));

    // Create DocObj (DocView) object
    CComPtr<IUnknown> srpObject;
    if (SUCCEEDED(hr))
    {
        if (m_fUseLocalCreateInstance)
        {
            hr = ::VsLocalCreateInstance(
                    pServiceProvider,
                    m_clsid,
                    NULL,
                    CLSCTX_INPROC_SERVER,
                    IID_IUnknown,
                    (void **)&srpObject);
        }
        else
        {
            hr = ::CoCreateInstance(
                    m_clsid,
                    NULL,
                    CLSCTX_INPROC_SERVER,
                    IID_IUnknown,
                    (void **)&srpObject);
        }
    }

    // Initialize DocData
    if (SUCCEEDED(hr))
    {
        ASSERT(srpDoc);
        srpDoc->SetMkDocument(pszMkDocument);
        srpDoc->SetOleObject(srpObject);
        hr = srpDoc->Init(pArg);
    }

    // InitNew or Load persistence
    if (SUCCEEDED(hr))
    {
        // da Vinci components require persistence methods to before DocObj is sited.
        hr = srpDoc->InitOrLoadPersistence(pszMkDocument, (grfOpen == VSDOCOPEN_NEW));
    }

    // Create Frame
    CComPtr<IVsWindowFrame> srpDocumentFrame;
    if (SUCCEEDED(hr))
    {
        hr = CreateFrame(srpDoc->GetMkDocument(), srpDoc, pVsHierarchy, vsitemid, pServiceProvider, &srpDocumentFrame);
    }

    // OnCreateFrame Hook
    if (SUCCEEDED(hr))
    {
        hr = srpDoc->OnCreateFrame(srpDocumentFrame);
    }

    // Show frame
    if ((hr == S_OK) && (grfOpen != VSDOCOPEN_HIDEEXISTING))
    {
        hr = srpDocumentFrame->Show();
    }

    // OnPostCreateFrame Hook
    if (hr == S_OK)
    {
        hr = srpDoc->OnPostCreateFrame(srpDocumentFrame);
    }

    // Save and restore the error info at end. Cleaning up the windows
    // causes it to be cleared.
    CComPtr<IErrorInfo> srpIErrorInfo;
    if(FAILED(hr))
        ::GetErrorInfo(0, &srpIErrorInfo);

    if(hr == S_OK && ppDocumentFrame)
    {
        *ppDocumentFrame = srpDocumentFrame.Detach();
    }
    else if (srpDocumentFrame)
    {
        srpDocumentFrame->CloseFrame(FRAMECLOSE_NoSave);
    }

    if(FAILED(hr))
    {
        if (srpDoc)
            srpDoc->CloseDocument();

        if(srpIErrorInfo)
            ::SetErrorInfo(0, srpIErrorInfo);
    }

    return hr;
}

//-----------------------------------------------------------------------------
// CVSCompDocTemplate<VSDOC, ARGTYPE>::OpenOrActivateDocument
//-----------------------------------------------------------------------------
template<class VSDOC, class ARGTYPE>
HRESULT CVSCompDocTemplate<VSDOC, ARGTYPE>::OpenOrActivateDocument(
        LPCOLESTR pszMkDocument,
        IVsUIHierarchy* pVsUIHierarchy,
        VSITEMID vsitemid,
        VSDOCOPEN grfOpen,
        IServiceProvider *pServiceProvider,
        ARGTYPE *pArg,
        IVsWindowFrame **ppDocumentFrame)

{
    CString strMkDocument;
    ComposeMkDocument(pszMkDocument, strMkDocument);
    ASSERT(!strMkDocument.IsEmpty());

    // Activate document if already open
    if (IsDocumentOpen(
                    strMkDocument,
                    pVsUIHierarchy,
                    vsitemid,
                    pServiceProvider,
                    TRUE,
                    ppDocumentFrame))
    {
        return S_OK;
    }

    return OpenDocument(
            strMkDocument,
            pVsUIHierarchy,
            vsitemid,
            grfOpen,
            pServiceProvider,
            pArg,
            ppDocumentFrame);
}

//-----------------------------------------------------------------------------
// CVSDocTemplate<VSDOC, NODE>::OpenDocument
//-----------------------------------------------------------------------------
template<class VSDOC, class NODE>
HRESULT CVSDocTemplate<VSDOC, NODE>::OpenDocument(
    LPCOLESTR pszMkDocument,
    NODE* pNode,
    VSDOCOPEN grfOpen)
{
    ASSERT(pNode);
    ASSERT(pNode->GetCVsHierarchy());

    CVsHierarchy* pVsHierarchy = pNode->GetCVsHierarchy();
    VSITEMID vsitemid = pNode ? pNode->GetVsItemID() : VSITEMID_NIL;
    IServiceProvider *pServiceProvider = _VxModule.GetModuleSite();

    CComPtr<IVsWindowFrame> srpDocumentFrame;
    return CVSCompDocTemplate<VSDOC, NODE>::OpenDocument(
                pszMkDocument,
                pVsHierarchy,
                vsitemid,
                grfOpen,
                pServiceProvider,
                pNode,
                &srpDocumentFrame);
}

//-----------------------------------------------------------------------------
// CVSDocTemplate<VSDOC, NODE>::OpenDocument
//-----------------------------------------------------------------------------
template<class VSDOC, class NODE>
HRESULT CVSDocTemplate<VSDOC, NODE>::OpenDocument(
    LPCOLESTR pszMkDocument,
    NODE* pNode,
    VSDOCOPEN grfOpen,
    IServiceProvider *pServiceProvider,
    IVsWindowFrame **ppDocumentFrame)
{
    CVsHierarchy* pVsHierarchy = pNode? pNode->GetCVsHierarchy() : NULL;
    VSITEMID vsitemid = pNode ? pNode->GetVsItemID() : VSITEMID_NIL;

    return CVSCompDocTemplate<VSDOC, NODE>::OpenDocument(
                pszMkDocument,
                pVsHierarchy,
                vsitemid,
                grfOpen,
                pServiceProvider,
                pNode,
                ppDocumentFrame);
}

//-----------------------------------------------------------------------------
// CVSDocTemplate <VSDOC, ARGTYPE>::OpenOrActivateDocument
//-----------------------------------------------------------------------------
template<class VSDOC, class NODE>
HRESULT CVSDocTemplate<VSDOC, NODE>::OpenOrActivateDocument(
        LPCOLESTR pszMkDocument,
        NODE* pNode,
        VSDOCOPEN grfOpen,
        IVsWindowFrame **ppDocumentFrame)
{
    ASSERT(pNode);
    ASSERT(pNode->GetCVsHierarchy());

    CVsHierarchy* pVsHierarchy = pNode->GetCVsHierarchy();
    VSITEMID vsitemid = pNode->GetVsItemID();
    IServiceProvider *pServiceProvider = _VxModule.GetModuleSite();
    CComPtr<IVsWindowFrame> srpDocumentFrame;
    if (NULL == ppDocumentFrame)
        ppDocumentFrame = &srpDocumentFrame;

    return CVSCompDocTemplate<VSDOC, NODE>::OpenOrActivateDocument(
                pszMkDocument,
                pVsHierarchy,
                vsitemid,
                grfOpen,
                pServiceProvider,
                pNode,
                ppDocumentFrame);
}

//-----------------------------------------------------------------------------
// CVSDocTemplate <VSDOC, NODE>::GetOpenDocument
//-----------------------------------------------------------------------------
template<class VSDOC, class NODE>
HRESULT CVSDocTemplate<VSDOC, NODE>::GetOpenDocument(
    NODE* pNode,
    IVsWindowFrame **ppDocFrame /*=NULL*/,
    IVsPersistDocData **ppDocData /*=NULL*/)
{
    ASSERT(pNode);
    ASSERT(pNode->GetCVsHierarchy());

    CComBSTR bstrCanonicalName;
    pNode->GetCanonicalName(&bstrCanonicalName);

    CString strMkDocument;
    ComposeMkDocument(bstrCanonicalName, strMkDocument);
    ASSERT(!strMkDocument.IsEmpty());

    CVsHierarchy* pVsHierarchy = pNode->GetCVsHierarchy();
    VSITEMID vsitemid = pNode->GetVsItemID();
    IServiceProvider *pServiceProvider = _VxModule.GetModuleSite();

    return CVsDocBaseTemplate::GetOpenDocument(
                strMkDocument,
                pVsHierarchy,
                vsitemid,
                pServiceProvider,
                ppDocFrame,
                ppDocData);
}

#endif //_VSDOC_H_

