/*
 -
 -	R D T V I E W T O O L . C P P
 -
 *	
 *	Purpose:	Implements the CRDTViewTool class which implements the tool window 
 *				functionality.
 *
 */

#include "stdafx.h"
#include "RDTViewTool.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRDTViewTool::CRDTViewTool()
{
	
}

CRDTViewTool::~CRDTViewTool()
{
}



// IVsWindowPane implementation
//
STDMETHODIMP CRDTViewTool::SetSite(
                    /*[in] */ IServiceProvider* pSP)
{
    m_srpSiteSP = pSP;
    return S_OK;
}

STDMETHODIMP CRDTViewTool::CreatePaneWindow(
                    /*[in] */ HWND  hwndParent,
                    /*[in] */ int   x,
                    /*[in] */ int   y,
                    /*[in] */ int   cx,
                    /*[in] */ int   cy,
                    /*[out]*/ HWND* phwnd)
{
	if (NULL == phwnd)
	{
		Assert(FALSE);
		return E_POINTER;
	}

    HRESULT hr = S_OK;

	// Create the CRDTViewDlg dialog instance as a child of the specified frame
    m_dlg.Create(hwndParent);
    *phwnd=m_dlg.m_hWnd;
	Assert(*phwnd);

    m_dlg.ShowWindow(SW_SHOW);
    m_dlg.MoveWindow(x, y, cx, cy, TRUE);
	m_dlg.SetRdtViewTool(this);

    return hr;
}

STDMETHODIMP CRDTViewTool::GetDefaultSize(
                    /*[out]*/ SIZE* pSize)
{
	if (NULL == pSize)
		return E_INVALIDARG;

    pSize->cx = c_cxDefSize;
    pSize->cy = c_cyDefSize;

    return S_OK;
}

STDMETHODIMP CRDTViewTool::ClosePane()
{
	// Unadvise for RDT events
	Assert(m_srpDocViewer.p);
	Verify(SUCCEEDED(m_srpDocViewer->Unadvise()));
	
	// Destroy the dialog instance
    m_dlg.DestroyWindow();
    m_srpSiteSP.Release();
	m_srpDocViewer.Release();

    return S_OK;
}

STDMETHODIMP CRDTViewTool::LoadViewState(
                    /*[in] */ IStream* pStream)
{
    return S_OK;
}

STDMETHODIMP CRDTViewTool::SaveViewState(
                    /*[in] */ IStream* pStream)
{
    return S_OK;
}

STDMETHODIMP CRDTViewTool::TranslateAccelerator(
                    /*[in]*/ LPMSG lpmsg)
{
    return S_FALSE;
}


// IRDTViewTool implementation
STDMETHODIMP CRDTViewTool::GetListDocsHwnd(
					/*[out]*/ HWND* phwnd)
{
	if (NULL == phwnd)
	{
		Assert(FALSE);
		return E_POINTER;
	}

	*phwnd = m_dlg.HwndGetListDocs();
	return S_OK;
}

STDMETHODIMP CRDTViewTool::GetListPropHwnd(
					/*[out]*/ HWND* phwnd)
{
	if (NULL == phwnd)
	{
		Assert(FALSE);
		return E_POINTER;
	}

	*phwnd = m_dlg.HwndGetListProp();
	return S_OK;
}

STDMETHODIMP CRDTViewTool::SetDocViewer(
					/*[in]*/ IDocViewer* pDocViewer)
{
	if (NULL == pDocViewer)
	{
		Assert(FALSE);
		return E_INVALIDARG;
	}

	m_srpDocViewer = pDocViewer;	// does an implicit addref
	return S_OK;
}

STDMETHODIMP CRDTViewTool::PopulateProperties(
								HWND hwndListDocs,		// [in] HWND of doc listbox
								HWND hwndListProp)		// [in] HWND of properties listbox
{
	Assert(m_srpDocViewer.p);
	return m_srpDocViewer->PopulateProperties(hwndListDocs, hwndListProp);
}
