
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// DSRefToolWindow.h: interface for the CDSRefToolWindow class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#include "commctrl.h"

class CDSRefToolWindow : 
	public CComObjectRootEx<CComSingleThreadModel>, 
	public IVsWindowPane,
	public IDropTarget,
	public IOleCommandTarget
{
public:
	CDSRefToolWindow();
	virtual ~CDSRefToolWindow();

//Callback functions
	static LRESULT CALLBACK StaticWndProc(HWND hwnd, UINT imsg, WPARAM wparam, LPARAM lparam);

protected:
// static members
	static BOOL m_bFirstInit;
	static TCHAR m_szClassName[];

	enum
    {
        EB_THIS = 0,
        EXTRABYTES = 4
    };

// COM Map
BEGIN_COM_MAP(CDSRefToolWindow)
    COM_INTERFACE_ENTRY(IVsWindowPane)
	COM_INTERFACE_ENTRY(IDropTarget)
	COM_INTERFACE_ENTRY(IOleCommandTarget)
END_COM_MAP()

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

// IDropTarget
	STDMETHOD(DragEnter)(
					/*[in]    */ IDataObject *pDataObj,
					/*[in]    */ DWORD grfKeyState,
					/*[in]    */ POINTL pt,
					/*[in,out]*/ DWORD *pdwEffect);
	STDMETHOD(DragOver)(
					/*[in]    */ DWORD grfKeyState,
					/*[in]    */ POINTL pt,
					/*[in,out]*/ DWORD *pdwEffect);
	STDMETHOD(DragLeave)();
	STDMETHOD(Drop)(
					/*[in]    */ IDataObject *pDataObj,
					/*[in]    */ DWORD grfKeyState,
					/*[in]    */ POINTL pt,
					/*[in,out]*/ DWORD *pdwEffect);

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


//Implementation
protected:
	BOOL RegisterWindowClass();
	LRESULT WndProc(UINT imsg, WPARAM wparam, LPARAM lparam);
	HRESULT GenerateNewTree(IDSRefConsumer*);
	HRESULT GenerateChildren(DSREFNODEID id, HTREEITEM htiParent);
	HRESULT AddNodeToTree(DSREFNODEID id, HTREEITEM htiParent, HTREEITEM* phtiNew);
	int GetImageForNode(DSREFNODEID id);
	char* GetTypeString(DSREFTYPE type);
	HRESULT WriteInfoForItem(DSREFNODEID id);
	BOOL QueryPaste();
	HRESULT DoPaste();

private:
	//members
	BOOL m_fZombie;
	HWND m_hwndParent;
	HWND m_hwndMain;
	HWND m_hwndTree;
	HWND m_hwndEdit;
	UINT m_uClipFmt;

	CComPtr<IDataObject> m_srpCurrentDragee;
	CComPtr<IDSRefConsumer> m_srpCurrentDSRef;
};
