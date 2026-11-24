
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// NoteWin.h : Definition of CNoteToolWindow
//

#pragma once

#include "noteCP.h"

//forward declares
class CSlnNotes;
class CSlnNote;
class CEnumNotes;

//////////////////////////////////////////////////////////////
// CNoteToolWindow
class CNoteToolWindow :
		public CComObjectRootEx<CComSingleThreadModel>,
		public CComCoClass<CSlnNotes, &CLSID_SolutionNotes>,
		public IDispatchImpl<ISolutionNotes, &IID_ISolutionNotes, &LIBID_SlnExtLib>,
		public IVsWindowPane,
		public IVsBroadcastMessageEvents,
		public IOleCommandTarget,
		public ISelectionContainer,
		public IProvideClassInfo2Impl<&CLSID_SolutionNotes, &DIID_DSolutionNotesEvents, &LIBID_SlnExtLib>,
		public IConnectionPointContainerImpl<CNoteToolWindow>,
		public CSlnNotesEvents<CNoteToolWindow>,
		public IVsSolutionEvents
{
friend class CSlnNote; // for access to the list box
//Constructor/Destructor
public:
	CNoteToolWindow();
	virtual ~CNoteToolWindow();
	HRESULT Close();

	//Persistence helpers
	HRESULT SaveOpts(IStream* pstm);
	HRESULT SaveProps(IPropertyBag* pProps);
	HRESULT LoadOpts(IStream* pstm);
	HRESULT LoadProps(LPCOLESTR szKey, IPropertyBag* pProps);
	HRESULT GetModified(); //returns S_OK if modified, S_FALSE if not.

//Callback functions
	static LRESULT CALLBACK StaticWndProc(HWND hwnd, UINT imsg, WPARAM wparam, LPARAM lparam);
	static int CALLBACK ListCompare(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);  
protected:
// static members
	static BOOL m_bFirstInit;
	static TCHAR m_szClassName[];

	enum LVCOL
	{
		lvName,
		lvIssue,
		lvShared
	};

	enum
    {
        EB_THIS = 0,
        EXTRABYTES = 4
    };

// COM Map
BEGIN_COM_MAP(CNoteToolWindow)
	COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IVsWindowPane)
    COM_INTERFACE_ENTRY(IVsBroadcastMessageEvents)
    COM_INTERFACE_ENTRY(IOleCommandTarget)
	COM_INTERFACE_ENTRY(ISelectionContainer)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISolutionNotes)
	COM_INTERFACE_ENTRY(IVsSolutionEvents)
END_COM_MAP()

// CONNECTION POINT Map
BEGIN_CONNECTION_POINT_MAP(CNoteToolWindow)
	CONNECTION_POINT_ENTRY(DIID_DSolutionNotesEvents)
END_CONNECTION_POINT_MAP()

public:
// IVsWindowPane
	STDMETHOD(SetSite)(
					/*[in] */ IServiceProvider* pSP);
	STDMETHOD(CreatePaneWindow)(
					/*[in] */ HWND  hwndParent,
					/*[in] */ int   x,
					/*[in] */ int   y,
					/*[in] */ int   cx,
					/*[in] */ int   cy,
					/*[out]*/ HWND* phwnd);
	STDMETHOD(GetDefaultSize)(
					/*[out]*/ SIZE* psize);
	STDMETHOD(ClosePane)(void);
	STDMETHOD(LoadViewState)(
					/*[in] */ IStream* pstream);
	STDMETHOD(SaveViewState)(
					/*[in] */ IStream* pstream);
	STDMETHOD(TranslateAccelerator)(
							  LPMSG lpmsg);

// IVsBroadcastMessageEvents
	STDMETHOD(OnBroadcastMessage)(
                    /*[in]*/ UINT   msg,
                    /*[in]*/ WPARAM wParam,
                    /*[in]*/ LPARAM lParam);

// IOleCommandTarget
	STDMETHOD(QueryStatus)(
                    /*[in]    */ const GUID* pguidCmdGroup,
                    /*[in]    */ ULONG       cCmds,
                    /*[in,out]*/ OLECMD      prgCmds[],
                    /*[in,out]*/ OLECMDTEXT* pCmdText);
	STDMETHOD(Exec)(
                    /*[in] */ const GUID* pguidCmdGroup,
                    /*[in] */ DWORD       nCmdID,
                    /*[in] */ DWORD       nCmdexecopt,
                    /*[in] */ VARIANT*    pvaIn,
                    /*[out]*/ VARIANT*    pvaOut);

// ISelectionContainer
	STDMETHOD(CountObjects)(
					/*[in] */ DWORD dwFlags,
					/*[out]*/ ULONG* pc);
	STDMETHOD(GetObjects)(
					/*[in]     */ DWORD dwFlags,
					/*[in]     */ ULONG cObjects,
					/*[in, out]*/ IUnknown** apUnkObjects);
	STDMETHOD(SelectObjects)(
					/*[in]*/ ULONG cObjects,
					/*[in]*/ IUnknown** apUnkObjects,
					/*[in]*/ DWORD dwFlags);

// ISolutionNotes
	STDMETHOD(get_DTE)(
					/*[out]*/ _DTE** ppDTE);
	STDMETHOD(get_Parent)(
					/*[out]*/ _DTE** ppDTE);
	STDMETHOD(get_Count)(
					/*[out]*/ long* pVal);
	STDMETHOD(get__NewEnum)(
					/*[out]*/ IUnknown** ppEnum);
	STDMETHOD(Item)(
					/*[in] */ VARIANT Index, 
					/*[out]*/ ISolutionNote** ppNote);
	STDMETHOD(Add)(
					/*[out]*/ ISolutionNote** ppNote);

// IVsSolutionEvents
	  // fAdded == TRUE means project added to solution after solution open.
	  // fAdded == FALSE means project added to solution during solution open.
	STDMETHOD(OnAfterOpenProject)(
					/*[in]*/ IVsHierarchy *pHierarchy, 
					/*[in]*/ BOOL fAdded);
	  // fRemoving == TRUE means project being removed from solution before solution close.
	  // fRemoving == FALSE means project being removed from solution during solution close.
	STDMETHOD(OnQueryCloseProject)(
					/*[in]    */ IVsHierarchy *pHierarchy, 
					/*[in]    */ BOOL fRemoving, 
					/*[in,out]*/ BOOL *pfCancel);
	  // fRemoved == TRUE means project removed from solution before solution close.
	  // fRemoved == FALSE means project removed from solution during solution close.
	STDMETHOD(OnBeforeCloseProject)(
					/*[in]*/ IVsHierarchy *pHierarchy, 
					/*[in]*/ BOOL fRemoved);
	  // stub hierarchy is placeholder hierarchy for unloaded project.
	STDMETHOD(OnAfterLoadProject)(
					/*[in]*/ IVsHierarchy *pStubHierarchy, 
					/*[in]*/ IVsHierarchy *pRealHierarchy);
	STDMETHOD(OnQueryUnloadProject)(
					/*[in]    */ IVsHierarchy *pRealHierarchy, 
					/*[in,out]*/ BOOL *pfCancel);
	STDMETHOD(OnBeforeUnloadProject)(
					/*[in]*/ IVsHierarchy *pRealHierarchy, 
					/*[in]*/ IVsHierarchy *pStubHierarchy);
	// fNewSolution == TRUE means solution is being created now.
	// fNewSolution == FALSE means solution was created previously, is being loaded.
	STDMETHOD(OnAfterOpenSolution)(
					/*[in]*/ IUnknown *pUnkReserved, 
					/*[in]*/ BOOL fNewSolution);
	STDMETHOD(OnQueryCloseSolution)(
					/*[in]    */ IUnknown *pUnkReserved, 
					/*[in,out]*/ BOOL *pfCancel);
	STDMETHOD(OnBeforeCloseSolution)(
					/*[in]*/ IUnknown *pUnkReserved);
	STDMETHOD(OnAfterCloseSolution)(
					/*[in]*/ IUnknown *pUnkReserved);

//Implementation
protected:
	BOOL RegisterWindowClass();
	void InitListViewImageList();
	void InitListViewColumns();
	void OnSize(WPARAM wParam, WORD wWidth, WORD wHeight);
	LRESULT OnNotify(LPARAM lp);
	LRESULT DoSelectionChange();
	HRESULT DoDeleteNote(UINT idx);
	HRESULT DoRenameNote(TCHAR*, UINT);
	LRESULT DoContextMenu(POINT);
	HRESULT	DoSort(UINT id);
	HRESULT DoShowNote();
	HRESULT DestroyNotes();
	UINT    GetIDFromCursor();
	LRESULT WndProc(UINT iMsg, WPARAM wParam, LPARAM lParam);
	CSlnNote* GetSelectedNote();
	ULONG   GetNoteCount();

protected:
	CComPtr<IServiceProvider> m_srpServiceProvider;

    BOOL m_fZombie;
	BOOL m_fCmdEnabled;
	VSCOOKIE m_lEventsCookie;
	HWND	m_hwndList;
	HWND	m_hwndParent;
	HWND	m_hwndMain;
	HWND	m_hwndEdit;

};

class CEnumNotes : public IEnumVARIANT
{
public:
	CEnumNotes(HWND hwndList); //main constructor
	CEnumNotes(CEnumNotes* pEnum); //clone constructor

	//IUnknown methods
	STDMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
	STDMETHOD_(ULONG, AddRef)() { return ++m_cRef; }
	STDMETHOD_(ULONG, Release)() { if (--m_cRef == 0) { delete this; return 0;} return m_cRef; }

	//IEnumVARIANT methods
	STDMETHOD(Next)(ULONG celt, VARIANT* rgvar, ULONG* celtFetched);
	STDMETHOD(Skip)(ULONG celt);
	STDMETHOD(Reset)();
	STDMETHOD(Clone)(IEnumVARIANT** ppenum);

private:
	ULONG m_cRef;
	ULONG m_idxCur;
	HWND  m_hwndList;
};
