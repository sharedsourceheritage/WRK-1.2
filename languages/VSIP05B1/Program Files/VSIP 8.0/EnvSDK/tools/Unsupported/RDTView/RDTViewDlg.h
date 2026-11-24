// RDTViewDlg.h: interface for the CRDTViewDlg class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include <atlwin.h>
#include <atlhost.h>
#include "prjinc.h"

class CRDTViewDlg :
	public CAxDialogImpl<CRDTViewDlg>
{
public:
	CRDTViewDlg()
	{
	}

	~CRDTViewDlg()
	{
		// Since we have a circular reference between this CRDTViewDlg object and the 
		// CRDTViewTool object (we have a pointer to its IRDTViewTool), the destruction of 
		// this object means that the CRDTViewTool is already going away, so don't let Release()
		// get called on our IRDTViewTool pointer or else we'll get a stack overflow from all
		// the circular destructor calls.
		m_srpRdtViewTool.p = NULL;
	}

    enum { IDD = IDD_RDTVIEWDIALOG };

BEGIN_MSG_MAP(CRDTViewDlg)
    MESSAGE_HANDLER(WM_INITDIALOG,  OnInitDialog)
	MESSAGE_HANDLER(WM_SIZE, OnSize)
	COMMAND_HANDLER(IDC_LIST_DOCS, LBN_SELCHANGE, OnListDocsSelChange)
END_MSG_MAP()

    LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
        m_hwndListDocs = GetDlgItem(IDC_LIST_DOCS);
		m_hwndListProp = GetDlgItem(IDC_LIST_PROP);
        return 1;  // Let the system set the focus
    }

    LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    {
		Assert(m_hwndListDocs);
        (void)::MoveWindow(m_hwndListDocs, 1, 1, (LOWORD(lParam) - 1), ((HIWORD(lParam) / 2) - 2), TRUE);             

		Assert(m_hwndListProp);
		(void)::MoveWindow(m_hwndListProp, 1, ((HIWORD(lParam) / 2) + 1), (LOWORD(lParam) - 1), ((HIWORD(lParam) / 2) - 2), TRUE);

        return 0;
    }

	HWND HwndGetListDocs()
	{
		return m_hwndListDocs;
	}

	HWND HwndGetListProp()
	{
		return m_hwndListProp;
	}

	void SetRdtViewTool(IRDTViewTool* pRdtViewTool)
	{
		if (NULL == m_srpRdtViewTool.p)
			m_srpRdtViewTool = pRdtViewTool;
	}

	LRESULT OnListDocsSelChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		// Clear out the current contents of the properties listbox
		Assert(m_hwndListProp);
		(void)::SendMessage(m_hwndListProp, LB_RESETCONTENT, (WPARAM)0, (LPARAM)0);

		// Tell the tool window to populate the property browser with the properties for the 
		// currently selected document.
		Assert(m_srpRdtViewTool.p);
		Verify(SUCCEEDED(m_srpRdtViewTool->PopulateProperties(m_hwndListDocs, m_hwndListProp)));

		bHandled = FALSE;	// Let Windows do default handling of this notification
		return 0;
	}

protected:
	HWND m_hwndListDocs;
	HWND m_hwndListProp;
	CComPtr<IRDTViewTool> m_srpRdtViewTool;

};
