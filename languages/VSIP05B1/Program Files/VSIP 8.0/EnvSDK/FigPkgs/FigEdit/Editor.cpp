
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Editor.cpp : Implementaion of the CEditor list view editor 
//              using ATL window classes

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes

// (ATL CWindowImpl instructions:) Initialize the contained window:
// 1. Pass "SysListView32" to specify that the contained 
//    window should be based on the standard    
//    Windows list view control
// 2. Pass 'this' pointer to specify that CEditor 
//    contains the message map to be used for the 
//    contained window's message processing
// 3. Pass the identifier of the message map. '1'
//    identifies the alternate message map declared
//    with ALT_MSG_MAP(1)
CEditor::CEditor( CFigEditorView *pView ) : 
    m_ListView(_T("SysListView32"), this, 1),
    m_hImageList(NULL),
    m_bOwnImageList(false)
{
    m_pView = pView;
    m_hImageList = ImageList_LoadBitmap( _AtlModule.GetModuleInstance(),
                                         MAKEINTRESOURCE( IDB_IMAGELIST ), 
                                         IMAGEWIDTH, IMAGEGROWBY, RGB( 0, 255, 0 ));
    if (NULL != m_hImageList)
        m_bOwnImageList = true;
    m_bDragWaitLButton = true;
}

CEditor::~CEditor()
{
    // We have to destroy the image list only if it was created and we own it.
    if ( (NULL != m_hImageList) && m_bOwnImageList )
        ImageList_Destroy( m_hImageList );
}

LRESULT CEditor::OnCreate( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
    RECT rc;
    GetClientRect( &rc );
    m_ListView.Create( m_hWnd, rc, _T("FigEditor"), 
        WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_NOCOLUMNHEADER | LVS_SHOWSELALWAYS,
        0 );
    _ASSERTE( m_ListView.m_hWnd != NULL );
    _ASSERTE( m_hImageList != NULL );
    ListView_SetImageList( m_ListView.m_hWnd, m_hImageList, LVSIL_SMALL );
    // After we associate the image list to the list view, we don't own it anymore.
    m_bOwnImageList = false;

    LV_COLUMN lvc;
    lvc.mask = LVCF_WIDTH;
    lvc.cx = rc.right;
    ListView_InsertColumn( m_ListView.m_hWnd, 0, &lvc );

    ListView_SetExtendedListViewStyle( m_ListView.m_hWnd, LVS_EX_FULLROWSELECT );

    return 0;
}

LRESULT CEditor::OnSize( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
    m_ListView.MoveWindow( 0, 0, LOWORD(lParam), HIWORD(lParam) );
    ResizeWindow();
    return 0;
}

void CEditor::ResizeWindow( void )
{
    RECT rc;
    ::GetClientRect( m_ListView.m_hWnd, &rc );
    LV_COLUMN lvc;
    lvc.mask = LVCF_WIDTH;
    lvc.cx = rc.right;
    ListView_SetColumn( m_ListView.m_hWnd, 0, &lvc );
}

LRESULT CEditor::OnNotify( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
    NMHDR *pNmHdr = (NMHDR FAR *) lParam;  
    NM_LISTVIEW *pNmLv = (NM_LISTVIEW FAR *) lParam;  
    HRESULT hr;

    switch( pNmHdr->code ) {
    case LVN_ITEMCHANGING:
        return FALSE; // allow the change for LVN_ITEMCHANGING
    case LVN_ITEMCHANGED:
        if( pNmLv->uNewState & LVIS_SELECTED ) {  // item is selected

            // change the selected property on the line object
            CFigEditLine *pLine = (CFigEditLine *) pNmLv->lParam;
            if( pLine != NULL ) {
                pLine->SetSelection( TRUE );

                // make sure the ISelectionContainer methods on the view obj 
                // are called when the selection changes
                hr = m_pView->OnSelectChange();
            }
        }
        else if( pNmLv->uOldState & LVIS_SELECTED ) {  // item is NOT selected

            // change the selected property on the line object
            CFigEditLine *pLine = (CFigEditLine *) pNmLv->lParam;
            if( pLine != NULL ) {
                hr = pLine->SetSelection( FALSE );
                if ( SUCCEEDED(hr) )
                {
                    // make sure the ISelectionContainer methods on the view obj 
                    // are called when the selection changes
                    hr = m_pView->OnSelectChange();
                }
            }
        }
        break;
    }

    return 0;
}

LRESULT CEditor::OnMouseMove( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
    // Start drag-drop if dragging
    if (wParam & MK_LBUTTON)    // Is left button down?
    {
        if (!m_bDragWaitLButton)    // previously cancelled drag waiting for LButtonUp
        {
            _ASSERTE( NULL != m_pView );
            if (m_pView->OnDragDrop() == DRAGDROP_S_CANCEL) // call parent implementation of drag-n-drop
                m_bDragWaitLButton = true;  // drop was cancelled
        }
    }
    else m_bDragWaitLButton = false;

    return 0;
}

LRESULT CEditor::OnLButtonUp( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
    // In the case DoDragDrop is cancelled by ESC key, wait for LButtonUp before permitting
    // next drag-n-drop.
    m_bDragWaitLButton = false;
    return 0;
}

LRESULT CEditor::OnRButtonDown( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
    ReleaseCapture();  // we must do this, otherwise we won't get any WM_RBUTTONUP messages
    return 0;
}

LRESULT CEditor::OnRButtonUp( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
    POINT ptClick;
    ptClick.x = LOWORD( lParam );
    ptClick.y = HIWORD( lParam );
    ClientToScreen( &ptClick );
    POINTS pos;
    pos.x = (short)ptClick.x;       // click coordinates
    pos.y = (short)ptClick.y;

    HRESULT hr = S_OK;
    CComPtr<IOleComponentUIManager> srpCompMgr;     // get UI service
    hr = _AtlModule.QueryService( 
                    SID_SOleComponentUIManager, IID_IOleComponentUIManager, 
                    (void **)&srpCompMgr );
    if( FAILED( hr ))
        return hr;

    hr = srpCompMgr->ShowContextMenu(               // popup context menu (in .ctc file)
                    OLEROLE_HOSTEXTENSION,
                    CLSID_FigEditPackage,
                    IDMX_FIG_FIGLINE,
                    pos, 
                    m_pView );
    if( FAILED( hr ))
        return hr;

    return 0;
}

BOOL CEditor::AddLine( CFigEditLine* pLine )
{
    UpdateList( pLine, TRUE );
    ResizeWindow();
    return true;
}

BOOL CEditor::DeleteLine( CFigEditLine* pLine )
{
    _ASSERTE( pLine != NULL );
    if (!pLine)
        return FALSE;
    _ASSERTE( ::IsWindow( m_ListView.m_hWnd ));

    long line = pLine->GetLineNumber();
    ListView_DeleteItem( m_ListView.m_hWnd, line );
    ResizeWindow();
    return TRUE;
}

BOOL CEditor::SetLine( CFigEditLine* pLine )
{
    UpdateList( pLine, FALSE );
    return true;
}

void CEditor::UpdateList( CFigEditLine* pLine, BOOL fInsert )
{
    _ASSERTE( ::IsWindow( m_ListView.m_hWnd ));
    _ASSERTE( pLine != NULL );
    if (!pLine)
        return;

    long line = pLine->GetLineNumber();

    FigLineType Ftype;
    pLine->get_Type( &Ftype );
    long type;
    switch( Ftype ) 
    {
        case FigArrow:
            type = IMAGEVALARROW;  break;   // defined in editor.h
        case FigCircle:
            type = IMAGEVALCIRCLE;  break;
        case FigRectangle:
            type = IMAGEVALRECTANGLE;  break;
        case FigComment:
            type = IMAGEVALCOMMENT;  break;
        default:
            type = IMAGEVALINVALID;
    }

    CString strComment;
    CComBSTR cbstrCmt; // get comment text
    pLine->get_Comment( &cbstrCmt );
    if ( cbstrCmt.Length() != 0 ) 
    {
        strComment = cbstrCmt;
        strComment.TrimRight();
    }

    int iLineTextLen = strComment.GetLength() + 100;
    TCHAR* pchLineText = new TCHAR[ iLineTextLen ];
    if (!pchLineText)
        return; // E_OUTOFMEMORY

    switch( Ftype ) 
    {
    case FigCircle:
        {
        long P1 = 0, P2 = 0, P3 = 0;                // get parameters
        pLine->get_Parameter1( &P1 );
        pLine->get_Parameter2( &P2 );
        pLine->get_Parameter3( &P3 );
        wnsprintf( pchLineText, iLineTextLen, _T("[ %d %d %d ] %s"), P1, P2, P3, strComment.LockBuffer() );
        strComment.UnlockBuffer();
        pchLineText[iLineTextLen-1] = 0;
        }
        break;
    case FigArrow:
    case FigRectangle:
        {
        long P1 = 0, P2 = 0, P3 = 0, P4 = 0;                // get parameters
        pLine->get_Parameter1( &P1 );
        pLine->get_Parameter2( &P2 );
        pLine->get_Parameter3( &P3 );
        pLine->get_Parameter4( &P4 );
        wnsprintf( pchLineText, iLineTextLen, _T("[ %d %d %d %d ] %s"), P1, P2, P3, P4, strComment.LockBuffer() );
        strComment.UnlockBuffer();
        pchLineText[iLineTextLen-1] = 0;
        }
        break;
    default:
        wcsncpy(pchLineText, strComment, iLineTextLen);
        pchLineText[iLineTextLen-1] = 0;
    }
    
    LV_ITEM lvi;
    lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
    lvi.iItem = line;
    lvi.iSubItem = 0;
    lvi.stateMask = 0;
    lvi.state = 0;
    lvi.pszText = (LPTSTR) pchLineText;
    lvi.iImage = type;
    lvi.lParam = (LPARAM)pLine;                 // pointer to line obj.

    if( fInsert ) 
        ListView_InsertItem( m_ListView.m_hWnd, &lvi ); // insert new line
    else
        ListView_SetItem( m_ListView.m_hWnd, &lvi );

    if(pchLineText)
        delete[] pchLineText;
}

void CEditor::SelectLine( long line ) 
{
    ListView_SetItemState( m_ListView.m_hWnd, (int)line, 
        LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED );
}

void CEditor::UnselectLine( long line ) 
{
    ListView_SetItemState( m_ListView.m_hWnd, (int)line, 
        0, LVIS_SELECTED | LVIS_FOCUSED );
}
 
void CEditor::SelectDropTargetLine( long line ) 
{
    ListView_SetItemState( m_ListView.m_hWnd, (int)line, 
        LVIS_FOCUSED, LVIS_FOCUSED );
}

void CEditor::UnselectDropTargetLine( long line ) 
{
    ListView_SetItemState( m_ListView.m_hWnd, (int)line, 
        0, LVIS_FOCUSED );
}

void CEditor::DeleteAllLines( void )
{
    _ASSERTE( ::IsWindow( m_ListView.m_hWnd ));

    ListView_DeleteAllItems( m_ListView.m_hWnd );
    ResizeWindow();
}

// determines line for drop target; scrolls if necessary
long CEditor::CalcDropLineFromPt( POINTL pt )
{
    UINT    nTopLine = ListView_GetTopIndex( m_ListView.m_hWnd );
    RECT    rct;
    if (ListView_GetItemRect( m_ListView.m_hWnd, nTopLine, &rct, LVIR_BOUNDS ))
    {
        int     nRowHeight = rct.bottom - rct.top;
        POINT   ptOrigin = { 0, 0 };
        if (::ClientToScreen( m_ListView.m_hWnd, &ptOrigin ))
        {
            long    nInsertAt;
            nInsertAt = nTopLine;   // insert point starts at n
            if (pt.y >= (rct.top + ptOrigin.y))
                nInsertAt += (pt.y - (rct.top + ptOrigin.y)) / nRowHeight;
            long    nMaxLine = ListView_GetItemCount( m_ListView.m_hWnd );
            if (nInsertAt > nMaxLine)
                nInsertAt = nMaxLine;
            return nInsertAt;
        }
    }
    return -1;  // Couldn't determine the line number
}

// end of file Editor.cpp