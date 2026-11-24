
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// SlnNote.h : Declaration of the CSlnNotes, CEnumNotes and CSlnNote

#pragma once

//forward declares
class CSlnNotes;
class CSlnNote;
class CEnumNotes;
class CNoteToolWindow;

//defines
#define MAX_NAME 20

class ATL_NO_VTABLE CSlnNote : 
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CSlnNote, &CLSID_SolutionNote>,
	public IProvideClassInfo2Impl<&CLSID_SolutionNote, NULL, &LIBID_SlnExtLib>,
	public IDispatchImpl<ISolutionNote, &IID_ISolutionNote, &LIBID_SlnExtLib>,
	public IVsWindowFrameNotify
{
public:
	CSlnNote();
	~CSlnNote();

BEGIN_COM_MAP(CSlnNote)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(ISolutionNote)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IVsWindowFrameNotify)
END_COM_MAP()
	
public:

//ISolutionNote
	STDMETHOD(get_DTE)(
					/*[out]*/ _DTE** ppDTE);
	STDMETHOD(get_Parent)(
					/*[out]*/ _DTE** ppDTE);
	STDMETHOD(get_Collection)(ISolutionNotes** ppColl);
	STDMETHOD(get_Name)(BSTR* pbstrName);
	STDMETHOD(put_Name)(BSTR bstrName);
	STDMETHOD(get_IsShared)(VARIANT_BOOL* pfShared);
	STDMETHOD(put_IsShared)(VARIANT_BOOL fShared);
	STDMETHOD(get_IsIssue)(VARIANT_BOOL* pfIssue);
	STDMETHOD(put_IsIssue)(VARIANT_BOOL fIssue);
	STDMETHOD(get_Size)(long* pSize);
	STDMETHOD(get_Visible)(VARIANT_BOOL* pfVisible);
	STDMETHOD(put_Visible)(VARIANT_BOOL fVisible);
	STDMETHOD(get_Modified)(VARIANT_BOOL* pfModified);

	//IVsWindowFrameNotify
	STDMETHOD(OnShow)(FRAMESHOW fShow);
	STDMETHOD(OnMove)();
	STDMETHOD(OnSize)();
	STDMETHOD(OnDockableChange)(BOOL fDockable);

	//Implementation
	HRESULT Init(CNoteToolWindow* pWin);
	HRESULT Close();
	HRESULT SetIdx(UINT idx) { m_idx = idx; return NOERROR; }

	//persistence helpers
	HRESULT SaveOpts(IStream* pstm);
	HRESULT SaveProps(IPropertyBag* pProps, UINT nKey);
	HRESULT LoadFromStream(CNoteToolWindow* pWin, IStream* pstm);
	HRESULT LoadFromPropBag(CNoteToolWindow* pWin, UINT nKey, IPropertyBag* pProps);
	HRESULT ClearModifiedFlag();
private:
	HRESULT CreateUniqueName(HWND);
	HRESULT AddToListBox(HWND);
	HRESULT ChangeNameInListBox(BSTR);
	HRESULT UpdateText();
	CNoteToolWindow* m_pToolWin;
	UINT m_idx;
	BSTR m_bstrName;
	CComPtr<IVsWindowFrame> m_srpFrame;
	VARIANT_BOOL m_fShared;
	VARIANT_BOOL m_fIssue;
	VARIANT_BOOL m_fModified;
	BSTR m_bstrText;  //actual text of the note
	static UINT m_nCurNote;
};
