
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// BufTskPr.h : Declaration of CFigBufferTaskProvider

#pragma once

/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CFigTaskItem;
class CFigTaskEnum;

// this is an STL vector type which is used as a superclass for our Enum class
typedef vector<CFigTaskItem*> vecTaskItem_type;  


// =========================================================================
//                                                       Task Comment Tokens

// COMMENTTOKEN
// Keep the info about the task comment tokens
struct COMMENTTOKEN
{
    VSTASKPRIORITY  vsTaskPriority;
    CComBSTR        cbstrToken;
    COMMENTTOKEN*   pNext;
};


// CCommentTokenList
// Implements a list of comment tokens
class CCommentTokenList
{
public:
    CCommentTokenList();
    ~CCommentTokenList();

    HRESULT       Add(COMMENTTOKEN * pct);
    void          RemoveAll();
    COMMENTTOKEN* GetHead();

protected:
    COMMENTTOKEN * m_pHead;
};
//                                                       Task Comment Tokens
// =========================================================================


/////////////////////////////////////////////////////////////////////////////
// CFigBufferTaskProvider

class CFigBufferTaskProvider :
	public IVsTextLinesEvents,
	public IVsTaskListEvents,
	public IFigTaskManager,
	public IVsTaskProvider2
{
public:
	CFigBufferTaskProvider( CVsPackage *pCVsPkg, IVsTextLines *pBuf, IFigParse *pIFigParse );
	~CFigBufferTaskProvider();
	STDMETHODIMP UnInit();
	STDMETHODIMP Init();

    HRESULT ParseLineForTask( 
	    /* [in]  */ long			nLine,			     // line to parse
	    /* [out] */ long*			pnTaskStartColumn,   // task start column
	    /* [out] */ long*			pnTaskEndColumn,	 // task end column
	    /* [out] */ BSTR*			pbstrTaskDescription,// task description
	    /* [out] */ VSTASKCATEGORY* pVsTaskCategory,	 // task category
	    /* [out] */ VSTASKPRIORITY*	pVsTaskPriority);	 // task priority
	
	BEGIN_INTERFACE
	// IUnknown methods:
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// IVsTextLinesEvents methods:
	STDMETHODIMP_(void) OnChangeLineText(
					/*[in] */ const TextLineChange *pTextLineChange,
					/*[in] */ BOOL fLast );
	STDMETHODIMP_(void) OnChangeLineAttributes (
					/*[in] */ long iFirstLine,
					/*[in] */ long iLastLine );

	// IFigTaskManager methods:
	STDMETHOD(CreateTask)( 
					/*[in] */ long nLine,
					/*[in] */ IVsTextView *pView );

	// IVsTaskProvider methods:
	// Standard enumerator over tasks supplied by this provider
	STDMETHOD(EnumTaskItems)( /*[out]*/ IVsEnumTaskItems **ppEnum );

    //phImageList is actually an HIMAGELIST*, but I can't get MIDL
    //to recognize that even by including/importing commctrl.h, so just cast it
	STDMETHOD(get_ImageList)( /*[out]*/ HANDLE *phImageList );

	//return the list of subcategories for the tasks you provide.  The task
	//itself will return an index into this list when asked for a subcategory
	//If cbstr is passed in as zero and rgbstr as NULL, then the provider
	//should set *pcActual to the actual number of BSTRs that need to be returned.
	STDMETHOD(get_SubcategoryList)(
					/*[in]*/ ULONG cbstr, 
					/*[out]*/ BSTR rgbstr[], 
					/*[out]*/ ULONG *pcActual );

 	// This method is for use if your task provider wants to unregister
	// while it still has tasks and then later reregister and retake
	// ownership of those tasks.  The bstr should uniquely describe this 
	// provider. (EXAMPLE:  CodeSense:c:\dir\filename.java)
	// If you don't plan to unregister while you have tasks, just
	// return E_NOTIMPL
 	STDMETHOD(get_ReRegistrationKey)( /*[out]*/ BSTR *pbstrKey );

	//To solve the circular ref problem (aka the "when do I unregister" problem):
	//If you haven't unregistered by the time the tasklist package is closing down,
	//you'll get this notification, which basically means "unregister now or forever
	//hold your peace".  (This really should be named OnTaskListPackageClose or
	//something like that, but when I first added it I thought I would call it from
	//FinalRelease, it wasn't until later that I realized it should really be called
	//once the task list can no longer be reached by a QueryService)
	STDMETHOD(OnTaskListFinalRelease)( /*[in]*/ IVsTaskList *pTaskList );

	// IVsTaskProvider2 methods:
    STDMETHOD(get_MaintainInitialTaskOrder)(
        /* [out,retval] */ BOOL * pbMaintainOrder);


//==========================================================================
//													    Comment Task support
//
//--------------------------------------------------------------------------
//														   IVsTaskListEvents
public:
    STDMETHOD(OnCommentTaskInfoChanged)();
//														   IVsTaskListEvents
//--------------------------------------------------------------------------

protected:
    STDMETHOD(RefreshTaskList)();

    static CCommentTokenList& GetCommentTokenList();

	// The flag fInit indicates whether we want only to initialize the task list
	// If it is TRUE, the task list is refreshed only if it is empty
	// This avoid refreshing the task list every time a task provider is initialized
	static HRESULT RefreshCommentTokens(
		/* [in] */ BOOL fInit = FALSE);

	static HRESULT CheckIfCommentTask(
		/* [in]  */ const WCHAR *pWC, 
		/* [out] */ bool *pbIsComment, 
		/* [out] */ VSTASKPRIORITY *pPriority);
//
//													    Comment Task support
//==========================================================================

private:
    // ---------------------------------------------------------------------
    //                                                       Static memebers
    static CCommentTokenList ms_CommentTokenList;
    //                                                       Static memebers
    // ---------------------------------------------------------------------

	DWORD m_dwRef;
	BOOL m_fZombie;
	BOOL m_fInit;
	CVsPackage* m_pCVsPkg;
	IVsTextLines * m_pTextLines;
	DWORD m_dwTextLinesEventsCookie;	// for IVsTextLinesEvents advise sink
	CComPtr<IFigParse> m_srpParse;		// for parser
	LPFIGMARK	m_pMks;					// ''
	long m_nDirtyLine;
	CFigTaskEnum* m_pvecTaskItems;		// an STL vector of pointers to CFigTaskItem objs

    CComPtr<IVsTaskList> m_srpTaskList; 
    VSCOOKIE m_dwProviderCookie;
};


/////////////////////////////////////////////////////////////////////////////
// CFigTaskEnum

// this is a standard enumerator class that also is an STL vector
// of pointers to CFigTaskItem objs

class CFigTaskEnum :
	public vecTaskItem_type,
	public IVsEnumTaskItems
{
public:
	CFigTaskEnum( CVsPackage *pCVsPkg );
	~CFigTaskEnum();
	
	BEGIN_INTERFACE
	// IUnknown methods:
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// IVsEnumTaskItems methods:
	STDMETHODIMP Next(
					/*[in]*/ ULONG celt, 
					/*[out]*/ IVsTaskItem **rgelt, 
					/*[out]*/ ULONG *pceltFetched );
	STDMETHODIMP Skip( /*[in]*/ ULONG celt );
	STDMETHODIMP Reset( void );
	STDMETHODIMP Clone( /*[out]*/ IVsEnumTaskItems **ppenum );


private:
	DWORD m_dwRef;
	ULONG m_iCurrentTaskItem;
	CVsPackage* m_pCVsPkg;
};


/////////////////////////////////////////////////////////////////////////////
// CFigTaskItem

class CFigTaskItem : public IVsTaskItem
{
public:
	CFigTaskItem( 
		BSTR bstrText, 
		BSTR bstrDocument, 
		long Line, 
		long StartCol, 
		long EndCol, 
        IVsTextLines *pView,
		VSTASKCATEGORY vsTaskCategory,
		VSTASKPRIORITY vsTaskPriority);
		
	~CFigTaskItem();
	void SetMarker( IVsTextLineMarker *pTLM );

	BEGIN_INTERFACE
	// IUnknown methods:
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// IVsTaskItem methods:
	//
	// Properties
	// Only implement the propput methods if you want that field to
	// be modifiable by the user
	STDMETHODIMP get_Priority( /*[out]*/ VSTASKPRIORITY *ptpPriority );
	STDMETHODIMP put_Priority( /*[in]*/ VSTASKPRIORITY tpPriority );
	STDMETHODIMP get_Category( /*[out]*/ VSTASKCATEGORY *pCat );
	STDMETHODIMP get_Checked( /*[out]*/ BOOL *pfChecked );
	STDMETHODIMP put_Checked( /*[in]*/ BOOL fChecked );
	STDMETHODIMP get_Text( /*[out]*/ BSTR *pbstrName );
	STDMETHODIMP put_Text( /*[in]*/ BSTR bstrName );
	STDMETHODIMP get_Document( /*[out]*/ BSTR *pbstrMkDocument );
	STDMETHODIMP get_Line( /*[out,retval]*/ long *piLine );
	STDMETHODIMP get_CanDelete( /*[out]*/ BOOL *pfCanDelete );
	STDMETHODIMP get_IsReadOnly( /*[in]*/ VSTASKFIELD field, /*[out]*/ BOOL *pfReadOnly );
	STDMETHODIMP get_HasHelp( /*[out]*/ BOOL *pfHasHelp );
	//return the index into the subcategory list maintained by the provider
	STDMETHODIMP get_SubcategoryIndex( /*[out]*/ long *pIndex );
	//If you have provided a custom image list, return the correct index
	//into that.  Otherwise return one of the VSTASKBITMAP enums to use
	//one of the default bitmaps.
	STDMETHODIMP get_ImageListIndex( /*[out]*/ long *pIndex );
	//implement this if you care whether errors on the same line are correctly sorted
	STDMETHODIMP get_Column( /*[out]*/ long *piCol );
	// Actions
	STDMETHODIMP NavigateTo( void );
	STDMETHODIMP NavigateToHelp( void );
	// Notifications
	STDMETHODIMP OnFilterTask( /*[in]*/ BOOL fVisible );
	STDMETHODIMP OnDeleteTask();

	// NOTE: we have two COM objects sharing the same block of memory:
	//		CFigTaskItem : IVsTaskItem 
	// and	
	//		CFigTextMarkerClient : IVsTextMarkerClient.
	// We are implemented in this fashion of two separate COM identities 
	// deliberately to break the refcount cycle between the CFigTaskItem 
	// which creates and holds an AddRef'ed pointer to a TextMarker object 
	// that in turns holds an AddRef'ed pointer on its IVsTextMarkerClient. 
	// If we used the same COM identity for the IVsTaskItem object and the 
	// IVsTextMarkerClient object then there would be a refcounting
	// cycle which would not terminate gracefully. 	We can only delete the
	// CFigTaskItem object when both refcounts go to zero.
	class CFigTextMarkerClient : public IVsTextMarkerClient
	{
		friend CFigTaskItem;
	public:
		CFigTextMarkerClient(CFigTaskItem *pTaskItem) 
			: m_dwRef(0)
				{ m_pTaskItem = pTaskItem; }

	public:
		// IUnknown methods:
		STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
		STDMETHODIMP_(ULONG) AddRef();
		STDMETHODIMP_(ULONG) Release();

		// IVsTextMarkerClient methods:
		// Receives callbacks from a marker.
		//
		// MarkerInvalidated is called when the text of a marker is deleted via a user action, but
		// not when the buffer is closed; OnBeforeBufferClose is called in that case.
		STDMETHODIMP_(void) MarkerInvalidated( void );

		STDMETHODIMP GetTipText(
						/*[in]*/ IVsTextMarker* pMarker, 
						/*[out]*/ BSTR *pbstrText );

		//pszFileName is so you know if the buffer has been saved to a different
		//name, in certain types of buffers, this may not be applicable, in which
		//case the parameter may be NULL
		STDMETHODIMP_(void) OnBufferSave( LPCOLESTR pszFileName );

		// called before the buffer goes away due to its being closed; clients may still grab
		// span information from the marker in response to this
		STDMETHODIMP_(void) OnBeforeBufferClose( void );

		// Commands
		STDMETHODIMP GetMarkerCommandInfo(
						/*[in]*/ IVsTextMarker* pMarker, 
						/*[in]*/ long iItem, 
						/*[out]*/ BSTR* pbstrText, 
						/*[out]*/ DWORD* pcmdf );
		STDMETHODIMP ExecMarkerCommand(
						/*[in]*/ IVsTextMarker* pMarker, 
						/*[in]*/ long iItem );

		// OnAfterSpanReload is called when someone calls IVsTextLines::ReloadLines or IVsTextStream::ReloadStream.
		// This means that the text under the marker has been altered, but it's been requested that the marker not
		// be deleted.  Thus the marker's position may not be appropriate.  This is your change to correct it if
		// needed.
		STDMETHODIMP_(void) OnAfterSpanReload( void );

        // OnAfterMarkerChange is called when the location of the marker changes due to edits to the 
        // text of the buffer.
        STDMETHODIMP OnAfterMarkerChange(/*[in]*/ IVsTextMarker *) { return E_NOTIMPL; }

	private:
		CFigTaskItem *m_pTaskItem;	// held as un-AddRef'ed pointer;
		DWORD m_dwRef;
	} m_TextMarkerClient;
	friend CFigTextMarkerClient;

private:
	DWORD m_dwRef;
	BOOL m_fZombie;
	CComBSTR m_bstrText;
	CComBSTR m_bstrDocument;
	long m_Line;
	long m_StartCol;
	long m_EndCol;
	CComPtr<IVsTextLineMarker> m_srpTLM;
	IVsTextLines * m_pTextLines;
	VSTASKCATEGORY m_vsTaskCategory;
	VSTASKPRIORITY m_vsTaskPriority;
	
};

