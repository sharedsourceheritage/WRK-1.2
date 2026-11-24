/*
 -
 -	R D T V I E W T O O L . H
 -
 *
 *	Purpose:	Defines the CRDTViewTool class, which implements the tool window interfaces.
 *				IVsWindowPane is the interface passed to IVsUIShell::CreateToolWindow() when the
 *				tool window is created.
 *
 *				IRDTViewTool exposes functionality used to populate the list boxes with document
 *				information.
 *
 */

#pragma once

#include "RDTViewDlg.h"

static const UINT c_cxDefSize = 700;
static const UINT c_cyDefSize = 300;

class ATL_NO_VTABLE CRDTViewTool :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IVsWindowPane,
	public IRDTViewTool
{
public:
	CRDTViewTool();
	virtual ~CRDTViewTool();

DECLARE_NOT_AGGREGATABLE(CRDTViewTool)
DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRDTViewTool)
    COM_INTERFACE_ENTRY(IVsWindowPane)
    COM_INTERFACE_ENTRY(IRDTViewTool)
END_COM_MAP()

// IVsWindowPane
public:

	STDMETHOD(SetSite)(
					/*[in]*/ IServiceProvider* pSP);

	STDMETHOD(CreatePaneWindow)(
					/*[in] */ HWND  hwndParent,
					/*[in] */ int   x,
					/*[in] */ int   y,
					/*[in] */ int   cx,
					/*[in] */ int   cy,
					/*[out]*/ HWND* phwnd);

	STDMETHOD(GetDefaultSize)(
					/*[out]*/ SIZE* pSize);

	STDMETHOD(ClosePane)(void);

	STDMETHOD(LoadViewState)(
					/*[in]*/ IStream* pStream);

	STDMETHOD(SaveViewState)(
					/*[in]*/ IStream* pStream);

	STDMETHOD(TranslateAccelerator)(
					/*[in]*/ LPMSG lpmsg);


// IRDTViewTool
	STDMETHOD(GetListDocsHwnd)(
					/*[out]*/ HWND* phwnd);

	STDMETHOD(GetListPropHwnd)(
					/*[out]*/ HWND* phwnd);

	STDMETHOD(SetDocViewer)(
					/*[in]*/ IDocViewer* pDocViewer);

	STDMETHOD(PopulateProperties)(
					/*[in]*/ HWND hwndListDocs,
					/*[in]*/ HWND hwndListProp);

// Internal data
protected:
	CRDTViewDlg					m_dlg;
    CComPtr<IServiceProvider>   m_srpSiteSP;
	CComPtr<IDocViewer>			m_srpDocViewer;

};

