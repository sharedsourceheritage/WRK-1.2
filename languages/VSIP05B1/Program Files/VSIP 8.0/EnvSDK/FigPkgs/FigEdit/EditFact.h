
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// EditFact.h : Declaration of CFigEditorFactory

#pragma once


/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CVsPackage;
class CFigEditorView;

/////////////////////////////////////////////////////////////////////////////
// CFigEditorFactory

class CFigEditorFactory :
	public IVsEditorFactory
{
public:
	CFigEditorFactory( 
		/* [in] */ CVsPackage * pCVsPkg, 
		/* [in] */ BOOL fEncoding = FALSE);
	~CFigEditorFactory();
	
	BEGIN_INTERFACE
	// *** IUnknown methods ***
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// IVsEditorFactory methods
	STDMETHODIMP CreateEditorInstance( 
	    /*[in] */ VSCREATEEDITORFLAGS   grfCreateDoc,		// only open or silent is valid
	    /*[in] */ LPCOLESTR			    pszMkDocument,	    // moniker file name
	    /*[in] */ LPCOLESTR			    pszPhysicalView,	// physical view name
	    /*[in] */ IVsHierarchy*	        pvHier,			    // project
	    /*[in] */ VSITEMID			    itemid,
	    /*[in] */ IUnknown*             punkDocDataExisting,// buffer already created ?
	    /*[out]*/ IUnknown**            ppunkDocView,		// return our view
	    /*[out]*/ IUnknown**            ppunkDocData,		// return our buffer
	    /*[out]*/ BSTR*                 pbstrEditorCaption,	// return our part of the caption [Custom] and [Readonly] if applicable
	    /*[out]*/ GUID*                 pguidCmdUI,			// the package guid for our menus (in the .ctc file in the satelite dll too)
	    /*[out]*/ VSEDITORCREATEDOCWIN* pgrfCDW);	        // flags to be passed to CreateDocumentWindow

	STDMETHODIMP SetSite( 
					/*[in] */ IServiceProvider *pSP );
	STDMETHODIMP Close( void );
	STDMETHODIMP MapLogicalView( 
					/*[in] */ REFGUID	 rguidLogicalView,
					/*[out]*/ BSTR		*pbstrPhysicalView );

private:
	DWORD m_dwRef;
	CComPtr<IServiceProvider> m_srpEdFactSiteSP;
	CVsPackage* m_pCVsPkg;
	BOOL m_fZombie; 

    // m_fEncoding indicates whether the editor factory is the one supporting encoding.
    // In this case codepagePrompt should be set in the buffer user data.
	BOOL m_fEncoding;
};

/////////////////////////////////////////////////////////////////////////////
