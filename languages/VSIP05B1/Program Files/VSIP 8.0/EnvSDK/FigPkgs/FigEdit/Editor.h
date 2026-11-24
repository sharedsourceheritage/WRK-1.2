
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Editor.h : Declaration of the CEditor list view editor 
//            using ATL window classes
//

// NOTE: This class was originally created in the edlin subdirectory.
//       If you want to play with the ATL window classes, that is a good place to start.

#pragma once


#define IMAGEWIDTH 16        // for image list
#define IMAGEGROWBY 4
#define IMAGEVALARROW 0
#define IMAGEVALCIRCLE 1
#define IMAGEVALRECTANGLE 2
#define IMAGEVALCOMMENT 3
#define IMAGEVALINVALID 4


/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CFigEditLine;
class CFigEditorView;
class CDropTarget;

/////////////////////////////////////////////////////////////////////////////
// CEditor
class CEditor : 
    public CWindowImpl<CEditor>
{
public:
    CEditor( CFigEditorView *pView );
    ~CEditor();

BEGIN_MSG_MAP(CEditor)
    MESSAGE_HANDLER(WM_CREATE, OnCreate)
    MESSAGE_HANDLER(WM_SIZE, OnSize)
    MESSAGE_HANDLER(WM_NOTIFY, OnNotify)
ALT_MSG_MAP(1)
    MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
    MESSAGE_HANDLER(WM_LBUTTONUP, OnLButtonUp)
    MESSAGE_HANDLER(WM_RBUTTONDOWN, OnRButtonDown)
    MESSAGE_HANDLER(WM_RBUTTONUP, OnRButtonUp)
END_MSG_MAP()

    LRESULT OnCreate( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );
    LRESULT OnSize( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );
    LRESULT OnNotify( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );
    LRESULT OnMouseMove( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );
    LRESULT OnLButtonUp( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );
    LRESULT OnRButtonDown( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );
    LRESULT OnRButtonUp( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );

    LRESULT OnInsert( WORD wNotifyCode, WORD wID, HWND hWndCtlr, BOOL& bHandled );

    BOOL AddLine( CFigEditLine* pLine );
    BOOL DeleteLine( CFigEditLine* pLine );
    BOOL SetLine( CFigEditLine* pLine );
    void UpdateList( CFigEditLine* pLine, BOOL fInsert );
    void SelectLine( long line );
    void UnselectLine( long line );
    void SelectDropTargetLine( long line );
    void UnselectDropTargetLine( long line );
    void ResizeWindow( void );
    void DeleteAllLines( void );
    long CalcDropLineFromPt( POINTL pt );    // determines line for drop target; scrolls if necessary

private:
    // Declare a contained window data member
    CContainedWindow m_ListView;
    HIMAGELIST  m_hImageList;
    bool m_bOwnImageList;
    CFigEditorView *m_pView;
    bool m_bDragWaitLButton;    // Set if drag-n-drop cancelled by ESC key and LButtonUp still pending
};

