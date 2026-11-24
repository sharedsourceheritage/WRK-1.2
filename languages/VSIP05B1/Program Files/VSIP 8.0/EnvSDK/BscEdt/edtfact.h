
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// EdtFact.h : Declaration of CBscEditorFactory

#pragma once


/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CVsPackage;
class CBscEditorDocument;

/////////////////////////////////////////////////////////////////////////////
// CBscEditorFactory

class CBscEditorFactory :
	public CComObjectRootEx<CComSingleThreadModel>,
	virtual public IVsEditorFactory
{
public:
	CBscEditorFactory();
	virtual ~CBscEditorFactory();
	bool FInit(CVsPackage *pCVsPkg);

// COM Map
BEGIN_COM_MAP(CBscEditorFactory)
    COM_INTERFACE_ENTRY(IVsEditorFactory)
END_COM_MAP()

public:	
	// IVsEditorFactory methods
	STDMETHODIMP CreateEditorInstance( 
					/*[in] */ VSCREATEEDITORFLAGS grfCreateDoc,
					/*[in] */ LPCOLESTR           pszMkDocument,
					/*[in] */ LPCOLESTR           pszPhysicalView,
					/*[in] */ IVsHierarchy       *pvHier,
					/*[in] */ VSITEMID            itemid,
					/*[in] */ IUnknown           *punkDocDataExisting,
					/*[out]*/ IUnknown          **ppunkDocView, 
					/*[out]*/ IUnknown          **ppunkDocData, 
					/*[out]*/ BSTR				 *pbstrEditorCaption,
					/*[out]*/ GUID				 *pguidCmdUI,
                    /*[out]*/ VSEDITORCREATEDOCWIN* pgrfCDW);
	STDMETHODIMP SetSite( 
					/*[in] */ IServiceProvider *pSP);
	STDMETHODIMP Close(void);
	STDMETHODIMP MapLogicalView( 
					/*[in] */ REFGUID	 rguidLogicalView,
					/*[out]*/ BSTR		*pbstrPhysicalView);


private:
	CComPtr<IServiceProvider> m_srpEdFactSiteSP;
	CVsPackage* m_pCVsPkg;
	BOOL m_fZombie; 
};

/////////////////////////////////////////////////////////////////////////////

