
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential
//*****************************************************************************
// FigOutline.h
//
// Declaration of CFigOutline
//
//*****************************************************************************

#pragma once

// Extra data associated with each item in the treeview
// OutlineTvItemInfo struct is attached to each item and maintains the info about
// the item (line number) so we can change the data without bothering the treeview
typedef struct tagOutlineTvItemInfo
{
    FigLineType   fltFigType;   // type of the figure object
    LONG          lLineNumber;  // line number
} OutlineTvItemInfo;

enum OutlineFixedNode
{
    OutlineGroupArrows     = 0,
    OutlineGroupCircles    = 1,
    OutlineGroupRectangles = 2,
    OutlineGroupComments   = 3,
    OutlineRoot = 4
};
#define OUTLINE_FIXED_NODE_COUNT    5




class ATL_NO_VTABLE CFigOutline :
    public IFigOutline,
    public IVsTextLinesEvents,
    public IVsDocOutlineProvider,
    public IOleCommandTarget,
    public IVsBroadcastMessageEvents,
    public IVsUserContextUpdate,       // to update the user context when needed
    public CComObjectRootEx<CComSingleThreadModel>
{

public:

// COM Interface Map
BEGIN_COM_MAP(CFigOutline)
    COM_INTERFACE_ENTRY(IFigOutline)
    COM_INTERFACE_ENTRY(IVsDocOutlineProvider)
    COM_INTERFACE_ENTRY(IOleCommandTarget)
    COM_INTERFACE_ENTRY(IVsTextLinesEvents)
    COM_INTERFACE_ENTRY(IVsBroadcastMessageEvents)
END_COM_MAP()


//==========================================================================
//                                                      construct & destruct

public:
    //----------------------------------------------------------------------
    // Function:    CreateInstance
    //              Create an instance of CFigOutline and return a pointer
    //              to IFigOutline interface. 
    //
    // Parameters: 
    //    /* [out] */ IFigOutline**  ppIVsDocOutlineProvider);
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    static HRESULT CreateInstance(
        /* [out] */ IFigOutline**  ppIVsDocOutlineProvider);

protected:
    CFigOutline();
    ~CFigOutline();
    
//                                                      construct & destruct
//==========================================================================

//==========================================================================
//                                                               IFigOutline
public:

    //----------------------------------------------------------------------
    // Function:    Init
    //              Initialize the object - must be called before using 
    //              the object.
    // Parameters: 
    //    /* [in]  */ IVsTextLines* pIVsTextLines,
    //              pointer to the text buffer
    //    /* [in]  */ HWND hwndParent,
    //              handle to the parent window
    //    /* [in]  */ IVsTextView* pIVsTextViewPrimary);
    //              pointer to the primary text view if any
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Init)(
        /* [in]  */ IVsTextLines* pIVsTextLines,
        /* [in]  */ HWND hwndParent,
        /* [in]  */ IVsTextView* pIVsTextViewPrimary);

    //----------------------------------------------------------------------
    // Function:    Close
    //              Clean the object.
    // Parameters: 
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Close)();

//--------------------------------------------------------------------------
//                                                       IFigOutline helpers
protected:

    //----------------------------------------------------------------------
    // Function:    RegisterOutlineClass
    //              Register the window outline class.
    // Parameters: 
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(RegisterOutlineClass)();

//                                                               IFigOutline
//==========================================================================


//==========================================================================
//                                                     IVsDocOutlineProvider
public:

    //----------------------------------------------------------------------
    // Function:    GetOutlineCaption
    //              Get the caption used in the outline.
    // Parameters: 
    //    /*[in] */ VSOUTLINECAPTION nCaptionType, 
    //    /*[out]*/ BSTR* pbstrCaption);
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(GetOutlineCaption)(
        /*[in] */ VSOUTLINECAPTION nCaptionType, 
        /*[out]*/ BSTR* pbstrCaption);

    //----------------------------------------------------------------------
    // Function:    GetOutline
    //              Get the outline window and pointer to the IOleCommandTarget
    //              interface
    // Parameters: 
    //    /*[out]*/ HWND* phwnd, 
    //    /*[out]*/ IOleCommandTarget** ppCmdTarget);
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(GetOutline)(
        /*[out]*/ HWND* phwnd, 
        /*[out]*/ IOleCommandTarget** ppCmdTarget);

    //----------------------------------------------------------------------
    // Function:    ReleaseOutline
    //              Release the outline window.
    // Parameters: 
    //    /*[in]*/ HWND hwnd, 
    //    /*[in]*/ IOleCommandTarget* pCmdTarget);
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(ReleaseOutline)(
        /*[in]*/ HWND hwnd, 
        /*[in]*/ IOleCommandTarget* pCmdTarget);

    //----------------------------------------------------------------------
    // Function:    OnOutlineStateChange
    //              Inform on outline changes.
    // Parameters: 
    //    /*[in]*/ VSOUTLINESTATES dwMask, 
    //    /*[in]*/ VSOUTLINESTATES dwState);
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(OnOutlineStateChange)(
        /*[in]*/ VSOUTLINESTATES dwMask, 
        /*[in]*/ VSOUTLINESTATES dwState);

//--------------------------------------------------------------------------
//                                             IVsDocOutlineProvider helpers
protected:

    //----------------------------------------------------------------------
    // Function:    UpdateOutlineTree
    //              Update the tree view used in the outline. 
    //              Called at the beginning to initialize the tree view with 
    //              the data in the text buffer.
    // Parameters: 
    //    /* [in] */ BOOL fForceUpdate); 
    //              If TRUE, force the function to update the tree.
    //              If FALSE, update the tree only if the tree has not been
    //              initialized.
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(UpdateOutlineTree)(
        /* [in] */ BOOL fForceUpdate);

//                                                     IVsDocOutlineProvider
//==========================================================================


//==========================================================================
//                                                         IOleCommandTarget
public:

    //----------------------------------------------------------------------
    // Function:    QueryStatus
    // Parameters: 
    //                /*[in]    */ const GUID* pguidCmdGroup,
    //                /*[in]    */ ULONG       cCmds,
    //                /*[in,out]*/ OLECMD      prgCmds[],
    //                /*[in,out]*/ OLECMDTEXT* pCmdText);
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(QueryStatus)(
        /*[in]    */ const GUID* pguidCmdGroup,
        /*[in]    */ ULONG       cCmds,
        /*[in,out]*/ OLECMD      prgCmds[],
        /*[in,out]*/ OLECMDTEXT* pCmdText);

    //----------------------------------------------------------------------
    // Function:    Exec
    // Parameters: 
    //                /*[in] */ const GUID* pguidCmdGroup,
    //                /*[in] */ DWORD       nCmdID,
    //                /*[in] */ DWORD       nCmdExecOpt,
    //                /*[in] */ VARIANT*    pvaIn,
    //                /*[out]*/ VARIANT*    pvaOut);
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(Exec)(
        /*[in] */ const GUID* pguidCmdGroup,
        /*[in] */ DWORD       nCmdID,
        /*[in] */ DWORD       nCmdExecOpt,
        /*[in] */ VARIANT*    pvaIn,
        /*[out]*/ VARIANT*    pvaOut);
//                                                         IOleCommandTarget
//==========================================================================


//==========================================================================
//                                                        IVsTextLinesEvents
public:

    //----------------------------------------------------------------------
    // Function:    OnChangeLineText
    //              Called when the text buffer is changed. Used to update 
    //              the tree view when the text buffer is updated.
    // Parameters: 
	//	/*[in] */ const TextLineChange *pTextLineChange,
	//	/*[in] */ BOOL fLast );
    //
    // Returns:     void
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD_(void, OnChangeLineText)(
		/*[in] */ const TextLineChange *pTextLineChange,
		/*[in] */ BOOL fLast );

    //----------------------------------------------------------------------
    // Function:    OnChangeLineAttributes
    //              Called when the line attributes are changed. 
    // Parameters: 
	//	/*[in] */ long iFirstLine,
	//	/*[in] */ long iLastLine);
    //
    // Returns:     void
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD_(void, OnChangeLineAttributes)(
		/*[in] */ long iFirstLine,
		/*[in] */ long iLastLine);

//--------------------------------------------------------------------------
//                                                IVsTextLinesEvents helpers
protected:


    //----------------------------------------------------------------------
    // Function:    AddLine
    //              The function updates the tree view when new line is added
    //              in the text buffer.
    //              Called from OnChangeLineText function.
    // Parameters: 
    //    /* [in] */ long nLine);
    //              The index of the line added.
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(AddLine)( 
        /* [in] */ long nLine);

    //----------------------------------------------------------------------
    // Function:    ParseLine
    //              The function parses the line with index nLine and returns
    //              the type, parameters and the comments.
    //              Called from AddLine to get the information about the new 
    //              line.
    //
    // Parameters: 
    //    /* [in] */ long nLine);
    //              The index of the line to be parsed.
    //    /* [out] */ FigLineType *pType, 
    //              Type of the figure line.
    //    /* [out] */ long *pP1, 
    //    /* [out] */ long *pP2, 
	//    /* [out] */ long *pP3, 
    //    /* [out] */ long *pP4, 
    //              Parameters of the figure.
    //    /* [out] */ BSTR *pbstrComment);
    //              Comments if any.
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(ParseLine)( 
        /* [in]  */  long nLine, 
        /* [out] */ FigLineType *pType, 
        /* [out] */ long *pP1, 
        /* [out] */ long *pP2, 
	    /* [out] */ long *pP3, 
        /* [out] */ long *pP4, 
        /* [out] */ BSTR *pbstrComment);

    //----------------------------------------------------------------------
    // Function:    GetParentNode
    //              The function returns the parent node in the tree view 
    //              according to the specified FigLineType.
    //              There is a subtree for each figure type.
    // Parameters: 
    //    /* [in] */ FigLineType flt);
    //              Figure type
    //
    // Returns:     HTREEITEM
    //              Handle to the parent node (root of the coresponding 
    //              subtree)
    // Notes:
    //----------------------------------------------------------------------
    HTREEITEM GetParentNode(
        /* [in] */ FigLineType flt);

    //----------------------------------------------------------------------
    // Function:    DeleteLine
    //              The function updates the tree view when a line is deleted
    //              in the text buffer.
    //              Called from OnChangeLineText function.
    // Parameters: 
    //    /* [in] */ long nLine);
    //              The index of the deleted line.
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(DeleteLine)(
        /* [in] */ long nLine);

    //----------------------------------------------------------------------
    // Function:    FindTreeItemFromLineNumber
    //              The function finds the tree view node with the 
    //              specified line number in nLineIndex.
    //              Called from DeleteLine function.
    // Parameters: 
    //    /* [in]  */ long       nLineIndex,
    //              Line number used to search the tree view data
    //    /* [out] */ HTREEITEM* phtiParent,
    //              Parent node of the node with the specified line number.
    //    /* [out] */ HTREEITEM* phti,
    //              Node with the specified line number.
    //    /* [out] */ OutlineTvItemInfo** ppotii);
    //              Pointer to the OutlineTvItemInfo with the specified
    //              line number. The pointer is stored in lParam of the 
    //              tree view node.
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(FindTreeItemFromLineNumber)(
        /* [in]  */ long       nLineIndex,
        /* [out] */ HTREEITEM* phtiParent,
        /* [out] */ HTREEITEM* phti,
        /* [out] */ OutlineTvItemInfo** ppotii);
    
    //----------------------------------------------------------------------
    // Function:    SetLine
    //              The function updates the tree view when a line is changed
    //              in the text buffer.
    //              Called from OnChangeLineText function.
    // Parameters: 
    //    /* [in] */ long nLine);
    //              The index of the updated line.
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(SetLine)(
        /* [in] */ long nLine);



//                                                        IVsTextLinesEvents
//==========================================================================


//==========================================================================
//                                                 IVsBroadcastMessageEvents
public:

    //----------------------------------------------------------------------
    // Function:    OnBroadcastMessage
    //              The function propagates the broadcasted messages to the 
    //              tree view.
    // Parameters: 
    //                /*[in]*/ UINT   msg,
    //                /*[in]*/ WPARAM wParam,
    //                /*[in]*/ LPARAM lParam);
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(OnBroadcastMessage)(
                    /*[in]*/ UINT   msg,
                    /*[in]*/ WPARAM wParam,
                    /*[in]*/ LPARAM lParam);

//                                                 IVsBroadcastMessageEvents
//==========================================================================


//==========================================================================
//                                                    Context Window support

protected:

    //----------------------------------------------------------------------
    // Function:    AddSubcontext
    //              The function adds the context for the outline to the 
    //              context of the parent document otline window.
    // Parameters: 
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(AddSubcontext)();

    //----------------------------------------------------------------------
    // Function:    RemoveSubcontext
    //              The function removes the context for the outline from  
    //              the context of the parent document otline window.
    // Parameters: 
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(RemoveSubcontext)();

    //----------------------------------------------------------------------
    // Function:    GetDocOutlineUserContext
    //              The function returns pointer to the context of the   
    //              parent document otline window.
    // Parameters: 
    //    /* [out] */ IVsUserContext** ppIVsUserContext);
    //              Pointer that receives the pointer to the context of the 
    //              parent document otline window.
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(GetDocOutlineUserContext)(
        /* [out] */ IVsUserContext** ppIVsUserContext);

    
//--------------------------------------------------------------------------
//                                                      IVsUserContextUpdate
public:

    //----------------------------------------------------------------------
    // Function:    UpdateUserContext
    //              Sends notification that the Dynamic Help window is 
    //              updating context. This method also clears the dirty flag 
    //              from the context bag.
    // Parameters: 
    //          /* [in] */ IVsUserContext * pCtx, 
    //              Pointer to the IVsUserContext interface (the context bag) 
    //              to update. 
    //          /* [in] */ VSCOOKIE dwCookie); 
    //              Not used
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
    STDMETHOD(UpdateUserContext)(
              /* [in] */ IVsUserContext * pCtx, 
              /* [in] */ VSCOOKIE dwCookie); 

//                                                      IVsUserContextUpdate
//--------------------------------------------------------------------------

//                                                    Context Window support
//==========================================================================


//==========================================================================
//                                                     Window implementation

    //----------------------------------------------------------------------
    // Function:    StaticWndProc
    //              Satndard window procedure.
    // Parameters: 
    //    HWND   hwnd,   
    //    UINT   iMsg, 
    //    WPARAM wParam, 
    //    LPARAM lParam);
    //
    // Returns:     LRESULT
    // Notes:
    //----------------------------------------------------------------------
    static LRESULT CALLBACK StaticWndProc(
        HWND   hwnd,   
        UINT   iMsg, 
        WPARAM wParam, 
        LPARAM lParam);

protected:
    enum
    {
        EB_THIS = 0,
        EXTRABYTES = 4
    };

    //----------------------------------------------------------------------
    // Function:    WndProc
    //              Window procedure.
    // Parameters: 
    //    UINT uMsg, 
    //    WPARAM wParam, 
    //    LPARAM lParam);
    //
    // Returns:     LRESULT
    // Notes:
    //----------------------------------------------------------------------
    LRESULT WndProc(
        UINT uMsg, 
        WPARAM wParam, 
        LPARAM lParam);

    //----------------------------------------------------------------------
    // Function:    OnCreate
    //              Message handler.
    // Parameters: 
    // Returns:     LRESULT
    // Notes:
    //----------------------------------------------------------------------
    LRESULT OnCreate();

    //----------------------------------------------------------------------
    // Function:    InitTree
    //              Intialize the tree view on OnCreate.
    // Parameters: 
    // Returns:     void
    // Notes:
    //----------------------------------------------------------------------
    void InitTree();

    //----------------------------------------------------------------------
    // Function:    InitFont
    //              Initialize the font to be used in the outline.
    // Parameters: 
    // Returns:     void
    // Notes:
    //----------------------------------------------------------------------
    void InitFont();

    //----------------------------------------------------------------------
    // Function:    AddFixedNodes
    //              The function adds the predefined fixed nodes in the tree
    //              view. One node for each figure type is added.
    // Parameters: 
    // Returns:     void
    // Notes:
    //----------------------------------------------------------------------
    void AddFixedNodes();

    //----------------------------------------------------------------------
    // Function:    GetFixedNodeImageIndex
    //              The function returns the index in the image list of the 
    //              specified outline fixed node.
    // Parameters: 
    //    OutlineFixedNode ofn); 
    // Returns:     int 
    //              Index in the image list.
    // Notes:
    //----------------------------------------------------------------------
    int GetFixedNodeImageIndex(
        OutlineFixedNode ofn);

    //----------------------------------------------------------------------
    // Function:    OnSize
    //              Message handler.
    // Parameters: 
    //    WPARAM nFlag, 
    //    int cx, 
    //    int cy);
    // Returns:     LRESULT
    // Notes:
    //----------------------------------------------------------------------
    LRESULT OnSize(
        WPARAM nFlag, 
        int cx, 
        int cy);

    //----------------------------------------------------------------------
    // Function:    OnSetFocus
    //              Message handler.
    // Parameters: 
    //    HWND hwndLastFocus);
    // Returns:     LRESULT
    // Notes:
    //----------------------------------------------------------------------
    LRESULT OnSetFocus(
        HWND hwndLastFocus);

    //----------------------------------------------------------------------
    // Function:    OnDblClickItem
    //              Message handler.
    //              Used to navigate to the corresponding source item when 
    //              a text view is opened.
    // Parameters: 
    // Returns:     LRESULT
    // Notes:
    //----------------------------------------------------------------------
    LRESULT OnDblClickItem();

    //----------------------------------------------------------------------
    // Function:    NavigateToItem
    //              The function navigates to the corresponding source item 
    //              when a text view is opened.
    // Parameters: 
    //    HTREEITEM hti, 
    //    BOOL fActivateSource);
    //
    // Returns:     BOOL
    // Notes:
    //----------------------------------------------------------------------
    BOOL NavigateToItem(
        HTREEITEM hti, 
        BOOL fActivateSource);

    //----------------------------------------------------------------------
    // Function:    OnSelChangeItem
    //              Message handler.
    // Parameters: 
    // Returns:     LRESULT
    // Notes:
    //----------------------------------------------------------------------
    LRESULT OnSelChangeItem();

//                                                     Window implementation
//==========================================================================


//==========================================================================
//                                                                   Members
protected:

    //----------------------------------------------------------------------
    //                                                           window data
    static ATOM       ms_atomWndClass;
    static const      TCHAR* ms_lpszOutlineClass;
    static CAtlString ms_rgstrFixedNodes[OUTLINE_FIXED_NODE_COUNT];
    static BOOL       ms_fFixedNodesInitialized;
    HWND m_hwndParent;
    HWND m_hwndMain;
    HWND m_hwndTree;
    HIMAGELIST m_hilTree;
    HFONT m_hFontUI;
    HTREEITEM  m_rghtiFixed[OUTLINE_FIXED_NODE_COUNT];
    long m_rgnExpandedState[OUTLINE_FIXED_NODE_COUNT];
    CEnvSDKPtrArray<OutlineTvItemInfo> m_rgotii;

    //----------------------------------------------------------------------
    //                                                    interface pointers
   	CComPtr<IVsTextLines>   m_srpIVsTextLines;
    CComPtr<IFigParse>      m_srpIFigParse;
    CComPtr<IVsTextView>    m_srpIVsTextViewPrimary;
    CComPtr<IVsUserContext> m_srpIVsUserContext;// our user context

    //----------------------------------------------------------------------
    //                                                         Event cookies
    DWORD m_dwIVsTextLinesEventsCookie;
    VSCOOKIE m_dwIVsBroadcastMessageEventsCookie;
    VSCOOKIE m_vscookieIVsUserContext;
    VSCOOKIE m_vscookieIVsUserContextUpdate;

    //----------------------------------------------------------------------
    //                                                            Misc. data
    CComBSTR m_cbstrMkDoc;

    // Indicate whether the tree has been initialized at least once
    BOOL m_fOutlineTreeInitialized;

    // Zombie state 
    BOOL m_fZombie;
//                                                                   Members
//==========================================================================

};
