
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// BufTskPr.cpp : Implementation of CFigBufferTaskProvider and CFigTaskItem

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes

#define MAX_FIG_MARKS 100


// =========================================================================
//                                          Unicode Escape Character Support
// ScanEscape
// Given a pointer to a backslash in a character stream, check for a unicode
// escape sequence.
inline HRESULT ScanEscape (PCWSTR& p, WCHAR& ch, BOOL fAdvance)
{
    ASSERT (*p == '\\');

    PCWSTR  pchStart = p;

    p++;
    if (*p == 'u')
    {
        while (*p == 'u')
            p++;
        WCHAR szEsc[5];
        for (int i = 0; i < 4; i++)
        {
            if (p[i] <= 'f' && isxdigit(p[i]))
                szEsc[i] = p[i];
            else
                goto Fail;
        }
        szEsc[4] = 0;

        unsigned long j = wcstoul(szEsc, NULL, 16);
        if (j != 0 || !wcscmp(szEsc, L"0000"))
        {
            ch = (WCHAR)j;
            p = fAdvance ? p+4 : pchStart;
            return NOERROR;
        }
    }

Fail:
    p = pchStart;
    return E_FAIL;
}

// NEXTCHAR, PEEKCHAR - Unicode-escape aware scanning
#define NEXTCHAR(p,ch) ((ch) = (*(p) != '\\' || (p)[1] != 'u' || FAILED (ScanEscape ((p), (ch), TRUE))) ? *(p)++ : (ch))
#define PEEKCHAR(p,ch) ((ch) = (*(p) != '\\' || (p)[1] != 'u' || FAILED (ScanEscape ((p), (ch), FALSE))) ? *(p) : (ch))

//                                          Unicode Escape Character Support
// =========================================================================


// =========================================================================
//                                                         CCommentTokenList

CCommentTokenList::CCommentTokenList() : 
    m_pHead(NULL) 
{}


CCommentTokenList::~CCommentTokenList()
{
    RemoveAll();
};


HRESULT CCommentTokenList::Add(COMMENTTOKEN * pct)
{
    ExpectedPtrRet(pct);
    COMMENTTOKEN * pctNew = new COMMENTTOKEN;
    if (pctNew == NULL)
        return E_OUTOFMEMORY;

    pctNew->vsTaskPriority = pct->vsTaskPriority;
    pctNew->cbstrToken.Attach(pct->cbstrToken.Detach());

    pctNew->pNext = m_pHead;
    m_pHead = pctNew;

    return S_OK;
}


void CCommentTokenList::RemoveAll()
{
    COMMENTTOKEN *p, *q;
    p=m_pHead;
    while (p!=NULL)
    {
        q=p->pNext;
        delete p;
        p=q;
    }
    m_pHead=NULL;
}


COMMENTTOKEN* CCommentTokenList::GetHead() 
{ 
    return m_pHead;
}

//                                                         CCommentTokenList
// =========================================================================


// =========================================================================
//                                                    CFigBufferTaskProvider

//Static members initialization
CCommentTokenList CFigBufferTaskProvider::ms_CommentTokenList;


CFigBufferTaskProvider::CFigBufferTaskProvider( 
    CVsPackage *pCVsPkg, IVsTextLines *pBuf, IFigParse *pIFigParse )
{
    ATLTRACE(TEXT(">> Constructing CFigBufferTaskProvider: 0x%X\n"), this);
    m_dwRef = 0;
    m_fZombie = FALSE;
    m_fInit = FALSE;
    m_pCVsPkg = pCVsPkg;
    m_pTextLines = pBuf;        
    m_srpParse = pIFigParse;    // Note: assignment to a smart pointer does an AddRef()
    m_pMks = NULL;  
    m_nDirtyLine = -1;
    m_dwProviderCookie = 0;
    m_dwTextLinesEventsCookie = 0;

}

CFigBufferTaskProvider::~CFigBufferTaskProvider()
{
    ATLTRACE(TEXT(">> Destructing CFigBufferTaskProvider: 0x%X\n"), this);

    UnInit();

    // free array of tokens
    if( m_pMks )
        delete[] m_pMks;     

    // release our enum obj (will release it's task list objs in the destructor)
    if (m_pvecTaskItems)
        m_pvecTaskItems->Release();
}

STDMETHODIMP CFigBufferTaskProvider::UnInit()
{
    HRESULT hr = S_OK;

    // unadvise IVsTextLinesEvents from buffer
    if (m_dwTextLinesEventsCookie != NULL)
    {
        CComPtr<IConnectionPointContainer> srpConPtCont;
        hr = m_pTextLines->QueryInterface( IID_IConnectionPointContainer,
                                            (void **)&srpConPtCont );
        if( SUCCEEDED( hr ))
        {
            CComPtr<IConnectionPoint> srpConPt;
            hr = srpConPtCont->FindConnectionPoint( IID_IVsTextLinesEvents,
                                                &srpConPt );
            if( SUCCEEDED( hr ))
            {
                hr = srpConPt->Unadvise( m_dwTextLinesEventsCookie );
            }
        }
        m_dwTextLinesEventsCookie = NULL;
    }

    // clean the task vector
    for( vecTaskItem_type::iterator pos = m_pvecTaskItems->begin(); 
         pos != m_pvecTaskItems->end(); pos++ )
        (*pos)->Release();
    m_pvecTaskItems->clear();

    // unregister as a task provider
    if ( (m_srpTaskList != NULL) && (m_dwProviderCookie != NULL) )
    {
        hr = m_srpTaskList->RefreshTasks(m_dwProviderCookie);
        ASSERT(SUCCEEDED(hr));
        hr = m_srpTaskList->UnregisterTaskProvider(m_dwProviderCookie);
        ASSERT(SUCCEEDED(hr));
        m_srpTaskList.Release();
        m_dwProviderCookie = NULL;
    }

    return hr;
}



STDMETHODIMP CFigBufferTaskProvider::Init()
{
    ExpectedExprRet(!m_fInit);

    HRESULT hr = S_OK;

    // create our enumerator object (also our STL vector of pointers to task objs)
    m_pvecTaskItems = new CFigTaskEnum( m_pCVsPkg );        
    if( NULL == m_pvecTaskItems )
        return E_OUTOFMEMORY;
    m_pvecTaskItems->AddRef();

    // setup an IVsTextLinesEvents advise on the buffer, intf is impl on buffer
    CComPtr<IConnectionPointContainer> srpConPtCont;
    hr = m_pTextLines->QueryInterface(
        IID_IConnectionPointContainer, 
        (void **)&srpConPtCont);
    IfFailRet(hr);

    CComPtr<IConnectionPoint> srpConPt;
    hr = srpConPtCont->FindConnectionPoint( IID_IVsTextLinesEvents, &srpConPt );
    IfFailRet(hr);

    hr = srpConPt->Advise( (IVsTextLinesEvents *)this, &m_dwTextLinesEventsCookie );
    IfFailRet(hr);

    // allocate a token array for our parser to fill
    m_pMks = new FIGMARK[ MAX_FIG_MARKS ];  // allocate an array of tokens
    if( NULL == m_pMks )
        return E_OUTOFMEMORY;

    // make sure this obj. inst. can be found on this buffer
    // (used by the text view filter obj. for this buffer, so
    //  it can call IFigTaskManager::CreateTask() )
    //
    CComPtr<IVsUserData> srpUserData;
    hr = m_pTextLines->QueryInterface( IID_IVsUserData, (void **)&srpUserData );
    IfFailRet(hr);

    CComVariant svPtr( static_cast<IUnknown *>( static_cast<IFigTaskManager*>( this )));
    srpUserData->SetData( GUID_BufferTaskProvider, svPtr );

    // register as a task provider with the task list
    CComPtr<IVsTaskList> srpTaskList;
    hr = _AtlModule.QueryService( 
                SID_SVsTaskList, IID_IVsTaskList, 
                (void **)&srpTaskList );
    IfFailRet(hr);

    m_srpTaskList = srpTaskList;
    ASSERT(m_srpTaskList != NULL);
    if (!m_srpTaskList)
        return E_UNEXPECTED;

    hr = srpTaskList->RegisterTaskProvider( static_cast<IVsTaskProvider*>(this), 
                                            &m_dwProviderCookie );
    IfFailRet(hr);
    
    // initialize the comment task list if not initialized already
    hr = CFigBufferTaskProvider::RefreshCommentTokens(TRUE);
    IfFailRet(hr);

    m_fInit = TRUE;

    hr = RefreshTaskList();
    IfFailRet(hr);

    return hr;
}



// called to parse a line of text from the buffer
// returns:
//   S_OK       when no tasks
//   S_FALSE    when there is a task display
//   other hr   when there was a COM error
HRESULT CFigBufferTaskProvider::ParseLineForTask(
    /* [in]  */ long            nLine,               // line to parse
    /* [out] */ long*           pnTaskStartColumn,   // task start column
    /* [out] */ long*           pnTaskEndColumn,     // task end column
    /* [out] */ BSTR*           pbstrTaskDescription,// task description
    /* [out] */ VSTASKCATEGORY* pVsTaskCategory,     // task category
    /* [out] */ VSTASKPRIORITY* pVsTaskPriority)     // task priority
{
    // validate input params
    ExpectedPtrRet(pnTaskStartColumn);
    ExpectedPtrRet(pnTaskEndColumn);
    ExpectedPtrRet(pbstrTaskDescription);
    ExpectedPtrRet(pVsTaskCategory);
    ExpectedPtrRet(pVsTaskPriority);

    // initialize out params
    *pnTaskStartColumn = -1;
    *pnTaskEndColumn = -1;
    *pbstrTaskDescription = NULL;
    *pVsTaskCategory = CAT_CODESENSE;
    *pVsTaskPriority = TP_HIGH;

    if( m_fZombie || !m_fInit )
        return E_UNEXPECTED;        // recursion guard

    HRESULT hr = S_OK;
    long nLineLength;
    CComBSTR bstrLine;

    hr = m_pTextLines->GetLengthOfLine( nLine, &nLineLength );
    if( FAILED( hr ) || nLineLength == 0 ) 
        return S_OK;

    // Puts the specified span of text into a BSTR; it is the caller's responsibility to free the BSTR.
    hr = m_pTextLines->GetLineText(
        nLine,          // starting line
        0,              // starting character index within the line (must be <= length of line)
        nLine,          // ending line
        nLineLength,    // ending character index within the line (must be <= length of line)
        &bstrLine );    // line text, if any
    if( FAILED( hr ) || bstrLine.Length() == 0 )
        return S_OK;

    // initialize parameters for the parse call
    long ncMarks = MAX_FIG_MARKS;
    if (!m_pMks)
        return E_UNEXPECTED;
    memset( m_pMks, 0, MAX_FIG_MARKS * sizeof( FIGMARK ));

    // null terminate the input line for our parser
    WCHAR* wszLine = new WCHAR[ nLineLength + 1 ];
    if (!wszLine)
        return E_OUTOFMEMORY;
    memset( wszLine, 0, ( nLineLength + 1 ) * sizeof( WCHAR ));
    wcsncpy( wszLine, bstrLine, nLineLength );
    bstrLine.Empty();

    // call the Line method on the parse object
    CComBSTR cbstrTaskDescription;
    hr = m_srpParse->Line( wszLine, &ncMarks, &m_pMks, &cbstrTaskDescription );

    if( cbstrTaskDescription != NULL ) 
    {
        // if there is an error - return the data for the error
        *pnTaskStartColumn = (long)m_pMks[ ncMarks - 1 ].nStart;
        *pnTaskEndColumn = (long)m_pMks[ ncMarks - 1 ].nEnd;
        *pbstrTaskDescription = cbstrTaskDescription.Detach();  // return the error text
        *pVsTaskCategory = CAT_CODESENSE;
        *pVsTaskPriority = TP_HIGH;
        hr = S_FALSE;
    } 
    else if ((ncMarks > 0) && (m_pMks[ncMarks-1].eTokenType == eComment))
    {
        // there is no error so parse the comments for comment task
        bool fComment;
        VSTASKPRIORITY priority;
        ULONG nCommentStartColumn = m_pMks[ ncMarks - 1 ].nStart + 1;
        hr = CFigBufferTaskProvider::CheckIfCommentTask(
            &wszLine[nCommentStartColumn], // do not pass the '  
            &fComment, 
            &priority); 
        if (SUCCEEDED(hr) && fComment)
        {
            *pnTaskStartColumn = (long)nCommentStartColumn;
            *pnTaskEndColumn = (long)m_pMks[ ncMarks - 1 ].nEnd + 1;
            cbstrTaskDescription = &wszLine[nCommentStartColumn];
            *pbstrTaskDescription = cbstrTaskDescription.Detach();  // return the comment text
            *pVsTaskCategory = CAT_COMMENTS;
            *pVsTaskPriority = priority;
            hr = S_FALSE;
        }
    }

    delete[] wszLine;

    // parse call failed, so return
    if( FAILED( hr )) {
        if( hr == E_INVALIDARG )
            ATLTRACE(TEXT( "CFigBufferTaskProvider::ParseLine Invalid args passed to pParse->Line()\n") );  
        else if( hr == E_OUTOFMEMORY ) 
            ATLTRACE(TEXT( "CFigBufferTaskProvider::ParseLine Too many tokens on the line.\n") );   
        else
            ATLTRACE(TEXT( "CFigBufferTaskProvider::ParseLine m_srpParse->Line() FAILED !\n") );    
    }

    return hr;
}


// *** IUnknown methods ***
STDMETHODIMP CFigBufferTaskProvider::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;     // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigBufferTaskProvider, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = static_cast<IUnknown*>(static_cast<IFigTaskManager*>(this));
        return NOERROR;
    }
    else if( riid == IID_IVsTextLinesEvents )
    {
        ATLTRACE(TEXT(">> CFigBufferTaskProvider, received QI for IID_IVsTextLinesEvents.\n"));
        AddRef();
        *ppvObj = static_cast<IVsTextLinesEvents*>(this);
        return NOERROR;
    }
    else if( riid == IID_IVsTaskListEvents )
    {
        ATLTRACE(TEXT(">> CFigBufferTaskProvider, received QI for IID_IVsTaskListEvents.\n"));
        AddRef();
        *ppvObj = static_cast<IVsTaskListEvents*>(this);
        return NOERROR;
    }
    else if( riid == IID_IFigTaskManager )
    {
        ATLTRACE(TEXT(">> CFigBufferTaskProvider, received QI for IID_IFigTaskManager.\n"));
        AddRef();
        *ppvObj = static_cast<IFigTaskManager*>(this);
        return NOERROR;
    }
    else if( riid == IID_IVsTaskProvider )
    {
        ATLTRACE(TEXT(">> CFigBufferTaskProvider, received QI for IID_IVsTaskProvider.\n"));
        AddRef();
        *ppvObj = static_cast<IVsTaskProvider*>(this);
        return NOERROR;
    }
    else if( riid == IID_IVsTaskProvider2 )
    {
        ATLTRACE(TEXT(">> CFigBufferTaskProvider, received QI for IID_IVsTaskProvider2.\n"));
        AddRef();
        *ppvObj = static_cast<IVsTaskProvider2*>(this);
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigBufferTaskProvider::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigBufferTaskProvider::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


// IVsTextLinesEvents methods ******************************************************
//
// The text buffer advises us of any changes by calling this method
//
STDMETHODIMP_(void) CFigBufferTaskProvider::OnChangeLineText(
                            /*[in] */ const TextLineChange *pTextLineChange,
                            /*[in] */ BOOL fLast )
{
    if( m_fZombie || !m_fInit )
        return;

    // Any edits on one line ?
    if( 
        NULL != pTextLineChange 
        && 
        pTextLineChange->iStartLine == pTextLineChange->iOldEndLine
        &&
        pTextLineChange->iStartLine == pTextLineChange->iNewEndLine 
       ) 
    {
        
        // this is the dirty flag for the line the user is currently
        // modifying
        //
        m_nDirtyLine = pTextLineChange->iStartLine;
    }
}

STDMETHODIMP_(void) CFigBufferTaskProvider::OnChangeLineAttributes (
                                                /*[in] */ long iFirstLine,
                                                /*[in] */ long iLastLine )
{
    if( m_fZombie || !m_fInit )
        return;

    // don't care about line color changes
}


// IFigTaskManager methods ******************************************************
//
STDMETHODIMP CFigBufferTaskProvider::CreateTask( 
    /*[in] */ long nLine,
    /*[in] */ IVsTextView *pView)
{
    HRESULT hr = S_OK;
    if( m_fZombie || !m_fInit )
        return E_UNEXPECTED;

    if( nLine != m_nDirtyLine )
        return S_FALSE;

    // reset the dirty flag
    m_nDirtyLine = -1;

    // parse the dirty line
    long nTaskStartColumn, nTaskEndColumn;
    CComBSTR cbstrTaskDescription;
    VSTASKCATEGORY vsTaskCategory;  // task category
    VSTASKPRIORITY vsTaskPriority;  // task priority
    hr = ParseLineForTask(
        nLine, 
        &nTaskStartColumn, 
        &nTaskEndColumn, 
        &cbstrTaskDescription, 
        &vsTaskCategory , 
        &vsTaskPriority);
    IfFailRet(hr);

    BOOL fRefreshTasks = FALSE;
    if( S_OK == hr || S_FALSE == hr ) 
    { 
        // delete any of our existing markers on this same line
        for( unsigned int l = 0; l < m_pvecTaskItems->size(); l++ ) 
        {
            CFigTaskItem *pOld = (*m_pvecTaskItems)[ l ];
            long line;
            pOld->get_Line( &line );
            if( line == nLine ) 
            {
                m_pvecTaskItems->erase( m_pvecTaskItems->begin() + l );
                pOld->Release();
                fRefreshTasks = TRUE;
                break;
            }
        }
    }

    if( (S_OK == hr) && fRefreshTasks)  
    {
        if( (m_srpTaskList != NULL) && (m_dwProviderCookie != NULL)) 
        {
            hr = m_srpTaskList->RefreshTasks(m_dwProviderCookie);
        }
        return hr;
    }

    if( S_FALSE != hr )
        return hr;

    if( nTaskStartColumn == nTaskEndColumn )  // don't want any zero length red squiggly markers !
        nTaskStartColumn = 0;

    // get file name
    CComBSTR bstrDoc( "unknown file name" );
    CComPtr<IPersistFileFormat> srpPFF;
    hr = m_pTextLines->QueryInterface( IID_IPersistFileFormat, (void **)&srpPFF );
    if( SUCCEEDED( hr )) {
        LPOLESTR pFileName;
        DWORD dwFormatIndex;
        if( SUCCEEDED( srpPFF->GetCurFile( &pFileName, &dwFormatIndex ))) {
            bstrDoc = pFileName;
            CComPtr<IMalloc> srpIM;
            if( SUCCEEDED( CoGetMalloc( 1, &srpIM )))
                srpIM->Free( pFileName );
        }
    }

    // create a CFigTaskItem with this error info and keep it in our vector
    CFigTaskItem *pTI = new CFigTaskItem( 
        cbstrTaskDescription, 
        bstrDoc, 
        nLine, 
        nTaskStartColumn, 
        nTaskEndColumn, 
        m_pTextLines,
        vsTaskCategory,
        vsTaskPriority);

    if( NULL == pTI )
        return E_OUTOFMEMORY;
    pTI->AddRef();
    m_pvecTaskItems->push_back( pTI );  

    if (vsTaskCategory != CAT_COMMENTS)
    {
        // tell the buffer to create this marker
        CComPtr<IVsTextLineMarker> srpTLM;
        hr = m_pTextLines->CreateLineMarker (
                MARKER_CODESENSE_ERROR,
                nLine,                      // starting line
                nTaskStartColumn,           // starting character index within the line (must be <= length of line)
                nLine,                      // ending line
                nTaskEndColumn,         // ending character index within the line (must be <= length of line)
                (IVsTextMarkerClient*)&(pTI->m_TextMarkerClient),
                &srpTLM );                  // if this is NULL, it means that the marker is buffer-owned
        if( FAILED( hr ))
            return hr;

        // have the task item also keep the pointer to the text marker,
        // so it can be released when the task is deleted
        pTI->SetMarker( srpTLM );
    }

    // tell the task list to display our new task
    if( (m_srpTaskList != NULL) && (m_dwProviderCookie != NULL) ) 
    {
        hr = m_srpTaskList->RefreshTasks( m_dwProviderCookie );
    }

    return hr;
}


// IVsTaskProvider methods ******************************************************
//

// Standard enumerator over tasks supplied by this provider
STDMETHODIMP CFigBufferTaskProvider::EnumTaskItems( 
                    /*[out]*/ IVsEnumTaskItems **ppEnum )
{
    HRESULT hr = S_OK;
    if( m_fZombie || !m_fInit )
        return E_UNEXPECTED;

    ExpectedPtrRet(ppEnum);

    // reset our enum obj's counter
    m_pvecTaskItems->Reset();

    // return the IVsEnumTaskItems intf. on this object.
    m_pvecTaskItems->AddRef();
    *ppEnum = static_cast<IVsEnumTaskItems*>(m_pvecTaskItems);

    return hr;
}

//phImageList is actually an HIMAGELIST*, but I can't get MIDL
//to recognize that even by including/importing commctrl.h, so just cast it
STDMETHODIMP CFigBufferTaskProvider::get_ImageList( 
                    /*[out]*/ HANDLE *phImageList )
{
    if( m_fZombie)
        return E_UNEXPECTED;

    if (!phImageList)
        return E_POINTER;

    // no custom images
    *phImageList = NULL;

    return E_NOTIMPL;
}

//return the list of subcategories for the tasks you provide.  The task
//itself will return an index into this list when asked for a subcategory
//If cbstr is passed in as zero and rgbstr as NULL, then the provider
//should set *pcActual to the actual number of BSTRs that need to be returned.
STDMETHODIMP CFigBufferTaskProvider::get_SubcategoryList(
                /*[in]*/ ULONG cbstr, 
                /*[out]*/ BSTR rgbstr[], 
                /*[out]*/ ULONG *pcActual )
{
    HRESULT hr = S_OK;
    if( m_fZombie )
        return E_UNEXPECTED;

    ExpectedPtrRet(pcActual);

    if( 0 == cbstr && NULL == rgbstr ) {
        *pcActual = 1;
        return S_OK;
    }

    CComBSTR bstrCat( L"Error" );
    if( 1 == cbstr ) {
        ExpectedPtrRet(rgbstr);
        *rgbstr = bstrCat.Copy();
        *pcActual = 1;
    }

    return hr;
}

// This method is for use if your task provider wants to unregister
// while it still has tasks and then later reregister and retake
// ownership of those tasks.  The bstr should uniquely describe this 
// provider. (EXAMPLE:  CodeSense:c:\dir\filename.java)
// If you don't plan to unregister while you have tasks, just
// return E_NOTIMPL
STDMETHODIMP CFigBufferTaskProvider::get_ReRegistrationKey( /*[out]*/ BSTR *pbstrKey )
{
    return E_NOTIMPL;
}

//To solve the circular ref problem (aka the "when do I unregister" problem):
//If you haven't unregistered by the time the tasklist package is closing down,
//you'll get this notification, which basically means "unregister now or forever
//hold your peace".  (This really should be named OnTaskListPackageClose or
//something like that, but when I first added it I thought I would call it from
//FinalRelease, it wasn't until later that I realized it should really be called
//once the task list can no longer be reached by a QueryService)
STDMETHODIMP CFigBufferTaskProvider::OnTaskListFinalRelease( /*[in]*/ IVsTaskList *pTaskList )
{
    HRESULT hr = S_OK;
    if( m_fZombie || !m_fInit )
        return E_UNEXPECTED;

    if ((m_srpTaskList != NULL) && (m_dwProviderCookie != NULL) )
    {
        hr = pTaskList->UnregisterTaskProvider(m_dwProviderCookie);
        m_srpTaskList.Release();
        m_dwProviderCookie = NULL;
    };
    return hr;
}

    // IVsTaskProvider2 methods:
STDMETHODIMP CFigBufferTaskProvider::get_MaintainInitialTaskOrder(
    /* [out,retval] */ BOOL * pbMaintainOrder)
{
    if (!pbMaintainOrder)
        return E_POINTER;
    *pbMaintainOrder = FALSE;
    return S_OK;
}


//==========================================================================
//                                                      Comment Task support

// IVsTaskListEvents
STDMETHODIMP CFigBufferTaskProvider::OnCommentTaskInfoChanged()
{
    HRESULT hr = CFigBufferTaskProvider::RefreshCommentTokens();
    IfFailRet(hr);

    hr = RefreshTaskList();
    IfFailRet(hr);

    return hr;
}

STDMETHODIMP CFigBufferTaskProvider::RefreshTaskList()
{
    HRESULT hr = S_OK;

    ExpectedExprRet(!m_fZombie && m_fInit);

    // get the number of lines in the buffer
    long cLines = 0;
    hr = m_pTextLines->GetLineCount(&cLines);
    IfFailRet(hr);
    
    // empty the task list
    for(vecTaskItem_type::iterator pos = m_pvecTaskItems->begin(); 
        pos != m_pvecTaskItems->end();
        pos++)
    {
        (*pos)->Release();
    }
    m_pvecTaskItems->clear();

    for (long i=0; i < cLines; i++)
    {
        // parse the line
        long nTaskStartColumn;
        long nTaskEndColumn;
        CComBSTR cbstrTaskDescription;
        VSTASKCATEGORY vsTaskCategory;  // task category
        VSTASKPRIORITY vsTaskPriority;  // task priority
        hr = ParseLineForTask(
            i, 
            &nTaskStartColumn, 
            &nTaskEndColumn, 
            &cbstrTaskDescription, 
            &vsTaskCategory , 
            &vsTaskPriority);
        IfFailRet(hr);

        if (hr != S_FALSE)
            continue;
        
        if( nTaskStartColumn == nTaskEndColumn )  // don't want any zero length red squiggly markers !
            nTaskStartColumn = 0;
        
        // get file name
        CComBSTR cbstrDoc("unknown file name");
        CComPtr<IPersistFileFormat> srpPFF;
        hr = m_pTextLines->QueryInterface( IID_IPersistFileFormat, (void **)&srpPFF );
        if(SUCCEEDED(hr)) 
        {
            LPOLESTR pFileName;
            DWORD dwFormatIndex;
            if( SUCCEEDED(srpPFF->GetCurFile(&pFileName,&dwFormatIndex ))) 
            {
                cbstrDoc = pFileName;
                CComPtr<IMalloc> srpIM;
                if( SUCCEEDED( CoGetMalloc( 1, &srpIM )))
                    srpIM->Free( pFileName );
            }
        }

        // create a CFigTaskItem with this error info and keep it in our vector
        CFigTaskItem *pTI = new CFigTaskItem( 
            cbstrTaskDescription, 
            cbstrDoc, 
            i, 
            nTaskStartColumn, 
            nTaskEndColumn, 
            m_pTextLines,
            vsTaskCategory,
            vsTaskPriority);
        if( NULL == pTI )
            return E_OUTOFMEMORY;

        pTI->AddRef();
        m_pvecTaskItems->push_back( pTI );  

        if (vsTaskCategory != CAT_COMMENTS)
        {
            // tell the buffer to create this marker
            CComPtr<IVsTextLineMarker> srpTLM;
            hr = m_pTextLines->CreateLineMarker (
                    MARKER_CODESENSE_ERROR,
                    i,                      // starting line
                    nTaskStartColumn,           // starting character index within the line (must be <= length of line)
                    i,                      // ending line
                    nTaskEndColumn,         // ending character index within the line (must be <= length of line)
                    (IVsTextMarkerClient*)&(pTI->m_TextMarkerClient),
                    &srpTLM );                  // if this is NULL, it means that the marker is buffer-owned
            if( FAILED( hr ))
                return hr;

            // have the task item also keep the pointer to the text marker,
            // so it can be released when the task is deleted
            pTI->SetMarker( srpTLM );
        }
    }

    // tell the task list to display our new tasks
    if( (m_srpTaskList != NULL) && (m_dwProviderCookie != NULL) ) 
    {
        hr = m_srpTaskList->RefreshTasks( m_dwProviderCookie );
    }
    
    return hr;
}


/* static */ 
CCommentTokenList& CFigBufferTaskProvider::GetCommentTokenList()
{
    return ms_CommentTokenList;
}

/* static */ 
HRESULT CFigBufferTaskProvider::RefreshCommentTokens(
    /* [in] */ BOOL fInit /* = FALSE */ ) 
{
    HRESULT hr = S_OK;

    CCommentTokenList& ctl = GetCommentTokenList();
    
    // check if we wany to initialize the list only
    if (fInit && (ctl.GetHead() != NULL))
        return S_OK;

    // now we refresh the list

    ctl.RemoveAll();

    CComPtr<IVsCommentTaskInfo> srpIVsCommentTaskInfo;
    hr = _AtlModule.QueryService(
        SID_SVsTaskList, 
        IID_IVsCommentTaskInfo, 
        (void**)&srpIVsCommentTaskInfo);
    IfFailRet(hr);

    CComPtr<IVsEnumCommentTaskTokens> srpIVsEnumCommentTaskTokens;
    hr = srpIVsCommentTaskInfo->get_EnumTokens(&srpIVsEnumCommentTaskTokens);
    IfFailRet(hr);

    CComPtr<IVsCommentTaskToken> srpIVsCommentTaskToken;
    COMMENTTOKEN ct;
    while (srpIVsEnumCommentTaskTokens->Next(1,&srpIVsCommentTaskToken,NULL) == S_OK)
    {
        if (SUCCEEDED (srpIVsCommentTaskToken->get_Text(&ct.cbstrToken)))
        {
            if (FAILED (srpIVsCommentTaskToken->get_Priority(&ct.vsTaskPriority)))
                ct.vsTaskPriority = TP_NORMAL;

            hr = ctl.Add(&ct);
            IfFailRet(hr);
        }
        srpIVsCommentTaskToken.Release();
    }
    return hr;
}

/* static */ 
HRESULT CFigBufferTaskProvider::CheckIfCommentTask(
    /* [in]  */ const WCHAR *pWC, 
    /* [out] */ bool *pbIsComment, 
    /* [out] */ VSTASKPRIORITY *pPriority)
{
    COMMENTTOKEN *pToken;    
    WCHAR ch;
    const WCHAR *pWCtemp, *pWCtoken;
    HRESULT hr = S_OK;
    bool bIsComment = false;
    ULONG j;   

    for (pToken = GetCommentTokenList().GetHead(); pToken!=NULL; pToken=pToken->pNext)
    {
        pWCtemp=pWC;
        bIsComment = true;
        for (pWCtoken = pToken->cbstrToken, j=0, PEEKCHAR(pWCtemp, ch); 
             j < pToken->cbstrToken.Length();
             NEXTCHAR(pWCtemp, ch), PEEKCHAR(pWCtemp, ch),j++, pWCtoken++)
        {
            if (*pWCtoken != ch)
            {
                bIsComment = false;
                break;
            }
        }
        if (ch != ':' && !iswspace(ch) && ch != '\0')
           continue;                        
                                      
        if (bIsComment)
            break;                
    }

    if (pbIsComment)
        *pbIsComment = bIsComment;       
    if (pPriority && pToken)
        *pPriority = pToken->vsTaskPriority;
    return hr;
}

//
//                                                      Comment Task support
//==========================================================================


//////////////////////////////////////////////////////////////////////////////////////
//******************************   CFigTaskItem   **********************************//
//////////////////////////////////////////////////////////////////////////////////////

CFigTaskItem::CFigTaskItem(
    BSTR bstrText, 
    BSTR bstrDocument, 
    long Line, 
    long StartCol, 
    long EndCol, 
    IVsTextLines *pView,
    VSTASKCATEGORY vsTaskCategory,
    VSTASKPRIORITY vsTaskPriority)
: 
m_TextMarkerClient(this)
{
    ATLTRACE(TEXT(">> Constructing CFigTaskItem: 0x%X\n"), this);
    m_dwRef = 0;
    m_fZombie = FALSE;
    m_bstrText = bstrText;
    m_bstrDocument = bstrDocument;
    m_Line = Line;
    m_StartCol = StartCol;
    m_EndCol = EndCol;
    m_pTextLines = pView;
    m_vsTaskCategory = vsTaskCategory;
    m_vsTaskPriority = vsTaskPriority;
}

CFigTaskItem::~CFigTaskItem()
{
    ATLTRACE(TEXT(">> Destructing CFigTaskItem: 0x%X\n"), this);
}

void CFigTaskItem::SetMarker( IVsTextLineMarker *pTLM )
{
    m_srpTLM = pTLM;  // NOTE: assignment to a smart pointer does an AddRef()
}


// *** IUnknown methods **********************************************************
STDMETHODIMP CFigTaskItem::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;     // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigTaskItem, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = static_cast<IUnknown*>(static_cast<IVsTaskItem*>(this));
        return NOERROR;
    }
    else if( riid == IID_IVsTaskItem )
    {
        ATLTRACE(TEXT(">> CFigTaskItem, received QI for IID_IVsTaskItem.\n"));
        AddRef();
        *ppvObj = static_cast<IVsTaskItem*>(this);
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigTaskItem::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigTaskItem::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        // because we have two COM objects sharing the same block of memory,
        // we can only delete ourselves when both refcounts go to zero.
        if( m_TextMarkerClient.m_dwRef == 0)
            delete this;        
        else
            // let go of our TextMarker. this will then cause the TextMarker 
            // to release our TextMarkerClient. we will then delete our memory
            // in the Release implementation of CFigTextMarkerClient.
            m_srpTLM.Release();

        return 0;
    }
    return( m_dwRef ); 
}


// IVsTaskItem methods: **************************************************************
//
// Properties
// Only implement the propput methods if you want that field to
// be modifiable by the user
STDMETHODIMP CFigTaskItem::get_Priority( /*[out]*/ VSTASKPRIORITY *ptpPriority )
{
    ExpectedPtrRet(ptpPriority);
    *ptpPriority = m_vsTaskPriority; 
    return S_OK;
}
STDMETHODIMP CFigTaskItem::put_Priority( /*[in]*/ VSTASKPRIORITY tpPriority )
{
    return E_NOTIMPL;
}
STDMETHODIMP CFigTaskItem::get_Category( /*[out]*/ VSTASKCATEGORY *pCat )
{
    ExpectedPtrRet(pCat);
   *pCat = m_vsTaskCategory; 
    return S_OK;
}
STDMETHODIMP CFigTaskItem::get_Checked( /*[out]*/ BOOL *pfChecked )
{
    ExpectedPtrRet(pfChecked);
    *pfChecked = FALSE; 
    return S_OK;
}
STDMETHODIMP CFigTaskItem::put_Checked( /*[in]*/ BOOL fChecked )
{
    return E_NOTIMPL;
}
STDMETHODIMP CFigTaskItem::get_Text( /*[out]*/ BSTR *pbstrName )
{
    ExpectedPtrRet(pbstrName);
    *pbstrName = m_bstrText.Copy(); 
    return S_OK;
}
STDMETHODIMP CFigTaskItem::put_Text( /*[in]*/ BSTR bstrName )
{
    return E_NOTIMPL;
}
STDMETHODIMP CFigTaskItem::get_Document( /*[out]*/ BSTR *pbstrMkDocument )
{
    ExpectedPtrRet(pbstrMkDocument);
    *pbstrMkDocument = m_bstrDocument.Copy(); 
    return S_OK;
}
STDMETHODIMP CFigTaskItem::get_Line( /*[out,retval]*/ long *piLine )
{
    ExpectedPtrRet(piLine);
    *piLine = m_Line; 
    return S_OK;
}
STDMETHODIMP CFigTaskItem::get_CanDelete( /*[out]*/ BOOL *pfCanDelete )
{
    ExpectedPtrRet(pfCanDelete);
    *pfCanDelete = TRUE; 
    return S_OK;
}
STDMETHODIMP CFigTaskItem::get_IsReadOnly( /*[in]*/ VSTASKFIELD field, 
                                           /*[out]*/ BOOL *pfReadOnly )
{
    ExpectedPtrRet(pfReadOnly);
    *pfReadOnly = TRUE; 
    return S_OK;
}
STDMETHODIMP CFigTaskItem::get_HasHelp( /*[out]*/ BOOL *pfHasHelp )
{
    ExpectedPtrRet(pfHasHelp);
    *pfHasHelp = FALSE; 
    return S_OK;
}
//return the index into the subcategory list maintained by the provider
STDMETHODIMP CFigTaskItem::get_SubcategoryIndex( /*[out]*/ long *pIndex )
{
    if (pIndex == NULL)
        return E_POINTER;

    if (m_vsTaskCategory == CAT_COMMENTS)
        return E_NOTIMPL;

    *pIndex = 0;
    return S_OK;
}
//If you have provided a custom image list, return the correct index
//into that.  Otherwise return one of the VSTASKBITMAP enums to use
//one of the default bitmaps.
STDMETHODIMP CFigTaskItem::get_ImageListIndex( /*[out]*/ long *pIndex )
{
    ExpectedPtrRet(pIndex);
    if (m_vsTaskCategory == CAT_COMMENTS)
        *pIndex = BMP_COMMENT;
    else 
        *pIndex = BMP_SQUIGGLE;
    return S_OK;
}
//implement this if you care whether errors on the same line are correctly sorted
STDMETHODIMP CFigTaskItem::get_Column( /*[out]*/ long *piCol )
{
    return E_NOTIMPL;
}
// Actions
STDMETHODIMP CFigTaskItem::NavigateTo( void )
{
    HRESULT hr = S_OK;

    CComPtr<IVsTextManager> srpTextMgr;
    CComPtr<IVsTextView> srpTextView;
    hr = _AtlModule.QueryService(SID_SVsTextManager, IID_IVsTextManager,
                              (void**)&srpTextMgr);
    IfFailGo(hr);

    hr = srpTextMgr->NavigateToLineAndColumn(
                            m_pTextLines, 
                            LOGVIEWID_Primary,
                            m_Line, m_StartCol,
                            m_Line, m_EndCol);

    //
    // Select the text range ourselves
    //
    hr = srpTextMgr->GetActiveView(FALSE, m_pTextLines, &srpTextView);
    IfFailGo(hr);
    hr = srpTextView->SetSelection(m_Line, m_StartCol, m_Line, m_EndCol);
    IfFailGo(hr);

Error:
    return hr;

}
STDMETHODIMP CFigTaskItem::NavigateToHelp( void )
{
    return E_NOTIMPL;
}
// Notifications
STDMETHODIMP CFigTaskItem::OnFilterTask( /*[in]*/ BOOL fVisible )
{
    return E_NOTIMPL;
}
STDMETHODIMP CFigTaskItem::OnDeleteTask()
{
    return E_NOTIMPL;
}



// *** IUnknown methods **********************************************************
STDMETHODIMP CFigTaskItem::CFigTextMarkerClient::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;     // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigTaskItem::CFigTextMarkerClient, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = static_cast<IUnknown*>(static_cast<IVsTextMarkerClient*>(this));
        return NOERROR;
    }
    else if( riid == IID_IVsTextMarkerClient )
    {
        ATLTRACE(TEXT(">> CFigTaskItem::CFigTextMarkerClient, received QI for IID_IVsTextMarkerClient.\n"));
        AddRef();
        *ppvObj = static_cast<IVsTextMarkerClient*>(this);
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigTaskItem::CFigTextMarkerClient::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigTaskItem::CFigTextMarkerClient::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        // NOTE: we have two COM objects sharing the same block of memory. We
        // can only delete this memory when both refcounts go to zero.
        // We are implemented in this fashion of two separate COM identities 
        // deliberately to break the refcount cycle
        // between the CFigTaskItem which creates and holds an AddRef'ed pointer
        // to a TextMarker object that in turns holds an AddRef'ed pointer on its 
        // IVsTextMarkerClient. If we used the same COM identity for the CFigTaskItem
        // object and the CTextMarkerClient object then there would be a refcounting
        // cycle which would not terminate gracefully. We call delete on 
        // 'm_pTaskItem' as this points to the complete block of memory
        // for both COM objects.
        if( m_pTaskItem->m_dwRef == 0)
            delete m_pTaskItem;     

        return 0;
    }
    return( m_dwRef ); 
}

// IVsTextMarkerClient methods:
// Receives callbacks from a marker.
//
// MarkerInvalidated is called when the text of a marker is deleted via a user action, but
// not when the buffer is closed; OnBeforeBufferClose is called in that case.
STDMETHODIMP_(void) CFigTaskItem::CFigTextMarkerClient::MarkerInvalidated( void )
{
}
STDMETHODIMP CFigTaskItem::CFigTextMarkerClient::GetTipText(
                /*[in]*/ IVsTextMarker* pMarker, 
                /*[out]*/ BSTR *pbstrText )
{
    HRESULT hr = S_OK;
    if (!pbstrText)
        hr = E_INVALIDARG;
    else 
        *pbstrText = NULL;

    if (FAILED(hr))
        return hr;

    if (m_pTaskItem)
        *pbstrText = m_pTaskItem->m_bstrText.Copy();    
    return S_OK;
}
//pszFileName is so you know if the buffer has been saved to a different
//name, in certain types of buffers, this may not be applicable, in which
//case the parameter may be NULL
STDMETHODIMP_(void) CFigTaskItem::CFigTextMarkerClient::OnBufferSave( LPCOLESTR pszFileName )
{
}
// called before the buffer goes away due to its being closed; clients may still grab
// span information from the marker in response to this
STDMETHODIMP_(void) CFigTaskItem::CFigTextMarkerClient::OnBeforeBufferClose( void )
{
}
// Commands
STDMETHODIMP CFigTaskItem::CFigTextMarkerClient::GetMarkerCommandInfo(
                /*[in]*/ IVsTextMarker* pMarker, 
                /*[in]*/ long iItem, 
                /*[out]*/ BSTR* pbstrText, 
                /*[out]*/ DWORD* pcmdf )
{
    HRESULT hr = S_OK;
    if (!pbstrText)
        hr = E_INVALIDARG;
    else 
        *pbstrText = NULL;
    if (!pcmdf)
        hr = E_INVALIDARG;
    else
        *pcmdf = 0;

    if (FAILED(hr))
        return hr;

    if (m_pTaskItem)
        *pbstrText = m_pTaskItem->m_bstrText.Copy();    
    return S_OK;
}
STDMETHODIMP CFigTaskItem::CFigTextMarkerClient::ExecMarkerCommand(
                /*[in]*/ IVsTextMarker* pMarker, 
                /*[in]*/ long iItem )
{
    return S_OK;
}
// OnAfterSpanReload is called when someone calls IVsTextLines::ReloadLines or IVsTextStream::ReloadStream.
// This means that the text under the marker has been altered, but it's been requested that the marker not
// be deleted.  Thus the marker's position may not be appropriate.  This is your change to correct it if
// needed.
STDMETHODIMP_(void) CFigTaskItem::CFigTextMarkerClient::OnAfterSpanReload( void )
{
}



//////////////////////////////////////////////////////////////////////////////////////
//******************************   CFigTaskEnum   **********************************//
//////////////////////////////////////////////////////////////////////////////////////

CFigTaskEnum::CFigTaskEnum( CVsPackage *pCVsPkg )
{
    ATLTRACE(TEXT(">> Constructing CFigTaskEnum: 0x%X\n"), this);
    m_dwRef = 0;
    m_iCurrentTaskItem = 0;
    m_pCVsPkg = pCVsPkg;
}

CFigTaskEnum::~CFigTaskEnum()
{
    ATLTRACE(TEXT(">> Destructing CFigTaskEnum: 0x%X\n"), this);

    // free the list of tasklist we have pointers to.
    for( vecTaskItem_type::iterator pos = begin(); pos != end(); pos++ )
        (*pos)->Release();
}

// *** IUnknown methods **********************************************************
STDMETHODIMP CFigTaskEnum::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;     // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        ATLTRACE(TEXT(">> CFigTaskEnum, received QI for IID_IUnknown.\n"));
        AddRef();
        *ppvObj = static_cast<IUnknown*>(this);
        return NOERROR;
    }
    else if( riid == IID_IVsEnumTaskItems )
    {
        ATLTRACE(TEXT(">> CFigTaskEnum, received QI for IID_IVsEnumTaskItems.\n"));
        AddRef();
        *ppvObj = static_cast<IVsEnumTaskItems*>(this);
        return NOERROR;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CFigTaskEnum::AddRef()
{
    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CFigTaskEnum::Release()
{
    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


// IVsEnumTaskItems methods ******************************************************
//
STDMETHODIMP CFigTaskEnum::Next(
                /*[in]*/ ULONG celt, 
                /*[out]*/ IVsTaskItem **rgelt, 
                /*[out]*/ ULONG *pceltFetched )
{
    if( NULL == pceltFetched ) {
        if( 1L != celt )
            return E_POINTER;
    } else
        *pceltFetched = 0L;

    if( NULL == rgelt || m_iCurrentTaskItem >= size() )
        return S_FALSE;

    ULONG cReturn = 0L;
    while( m_iCurrentTaskItem < size() && celt > 0 ) {
        *rgelt = static_cast<IVsTaskItem*>((*this).operator[]( m_iCurrentTaskItem++ ));
        _ASSERTE(*rgelt);
        (*rgelt)->AddRef();     // we must return an AddRef'ed pointer
        rgelt++;
        cReturn++;
        celt--;
    }

    if( NULL != pceltFetched )
        *pceltFetched = cReturn;

    return NOERROR;
}

STDMETHODIMP CFigTaskEnum::Skip( /*[in]*/ ULONG celt )
{
    if(( m_iCurrentTaskItem + celt ) >= size() )
        return S_FALSE;

    m_iCurrentTaskItem += celt;

    return NOERROR;
}

STDMETHODIMP CFigTaskEnum::Reset( void )
{
    m_iCurrentTaskItem = 0;

    return NOERROR;
}

STDMETHODIMP CFigTaskEnum::Clone( /*[out]*/ IVsEnumTaskItems **ppenum )
{
    ExpectedPtrRet(ppenum);
    *ppenum = NULL;

    CFigTaskEnum *pTE;
    pTE = new CFigTaskEnum( m_pCVsPkg );        // an STL linked list of pointers to CFigTaskItem objs
    if( NULL == pTE )
        return E_OUTOFMEMORY;
    pTE->AddRef();
    pTE->m_iCurrentTaskItem = m_iCurrentTaskItem;

    *ppenum = pTE;

    return NOERROR;
}



// end of file BufTskPr.cpp
