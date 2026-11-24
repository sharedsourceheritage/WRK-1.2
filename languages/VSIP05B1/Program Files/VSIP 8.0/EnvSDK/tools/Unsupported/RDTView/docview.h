/* 
 -
 -	D O C V I E W . H
 -
 *
 *	Purpose:	Defines the CDocViewer class, which implements the IDocViewer interface used
 *				to populate the RDTView tool window with information, and implements the event
 *				sink interface for RDT events.
 *
 */

#pragma once

static const UINT c_cchMaxCookie	= 20;
static const UINT c_cchMaxLbStr		= 1024;
static const UINT c_cMaxDirty		= 256;


class CDocViewer :	
			public CComObjectRootEx<CComSingleThreadModel>,
			public IVsRunningDocTableEvents3,
			public IDocViewer
{
public:
	CDocViewer();
	virtual ~CDocViewer();

BEGIN_COM_MAP(CDocViewer)
    COM_INTERFACE_ENTRY(IVsRunningDocTableEvents)
    COM_INTERFACE_ENTRY(IVsRunningDocTableEvents2)
    COM_INTERFACE_ENTRY(IVsRunningDocTableEvents3)
	COM_INTERFACE_ENTRY(IDocViewer)
END_COM_MAP()

// IDocViewer
	STDMETHOD(Advise)(
				/*[out]*/ VSCOOKIE* pdwCookie);

	STDMETHOD(Populate)(
				/*[in]*/ IVsWindowPane* pToolWindowPane);

	STDMETHOD(Unadvise)();
	
	STDMETHOD(UnadviseEx)(
				/*[in]*/ VSCOOKIE dwCookie);

	STDMETHOD(PopulateProperties)(
				/*[in]*/ HWND hwndListDocs,
				/*[in]*/ HWND hwndListProp);

// IVsRunningDocTableEvents
	STDMETHOD(OnAfterFirstDocumentLock)(
				VSCOOKIE docCookie,
				VSRDTFLAGS dwRDTLockType,
				DWORD dwReadLocksRemaining,
				DWORD dwEditLocksRemaining);

	STDMETHOD(OnBeforeLastDocumentUnlock)(
				VSCOOKIE docCookie,
				VSRDTFLAGS dwRDTLockType,
				DWORD dwReadLocksRemaining,
				DWORD dwEditLocksRemaining);

	STDMETHOD(OnAfterSave)(
				VSCOOKIE docCookie);

	STDMETHOD(OnAfterAttributeChange)(
				VSCOOKIE docCookie, 
				VSRDTATTRIB grfAttribs);

	STDMETHOD(OnBeforeDocumentWindowShow)(
				VSCOOKIE docCookie, 
				BOOL fFirstShow, 
				IVsWindowFrame *pFrame);

	STDMETHOD(OnAfterDocumentWindowHide)(
				VSCOOKIE docCookie, 
				IVsWindowFrame *pFrame);


// IVsRunningDocTableEvents2
	STDMETHOD(OnAfterAttributeChangeEx)(
				VSCOOKIE docCookie,
				VSRDTATTRIB grfAttribs,
				IVsHierarchy *pHierOld,
				VSITEMID itemidOld,
				LPCOLESTR pszMkDocumentOld,                     
				IVsHierarchy *pHierNew,
				VSITEMID itemidNew,
				LPCOLESTR pszMkDocumentNew);

// IVsRunningDocTableEvents3
	STDMETHOD(OnBeforeSave)(
				VSCOOKIE docCookie);


// Internal methods
protected:
	HRESULT GetRdtService();

	LRESULT LbWriteString(
				HWND hwnd,
				LPCTSTR tsz,
				...);

	inline void WriteFlagIfSet(
					HWND hwnd,
					LPCTSTR tsz,
					int n)
	{
		if (n)
			(void)LbWriteString(hwnd, _T("  %s"), tsz);
	}

	void HandleAttributeChange(
			VSCOOKIE docCookie,
			VSRDTATTRIB grf);

	LONG FindInDirtyList(
			VSCOOKIE docCookie);

// Internal data
protected:
	CComPtr<IVsRunningDocumentTable> m_srpRDT;
	VSCOOKIE m_dwSinkCookie;
	CComPtr<IVsWindowPane> m_srpWindowPane;
	LONG m_iCurSel;
	VSCOOKIE m_rgDirty[c_cMaxDirty];
	UINT m_cDirty;
};

