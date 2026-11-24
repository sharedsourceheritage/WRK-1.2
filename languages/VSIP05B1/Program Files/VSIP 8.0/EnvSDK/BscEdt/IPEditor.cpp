
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//////////////////////////////////////////////////////////////////////////////////////
// IPEditor.cpp : Implementation of CBscEditorDocument (in-place activation)- see also
//                EdtCmn.cpp for methods common to both versions of the editor,
//                MacroRec.cpp for methods relating to macro recording and
//                FindRepl.cpp for methods relating to find and replace
// Note that this version of the editor is compiled if INPLACE is defined
#include "stdafx.h"
#include "EdCommon.h"
#include "guids.h"
#include "BscEdtUI\resource.h"

#ifdef INPLACE

/////////////////////////////////////////////////////////////////////////////
// CBscEditorDocument


////////////////////////////////////////////////////////////////////////////////
//
// Function:    Close (IOleObject::Close override)
//                This function overrides the IOleObject::Close method. We just
//                do some clean up and then call the IOleObject::Close (using
//                ATL template).
//
// Parameters:
//    dwSaveOption    In our case we are deleting the object so this option
//                    will be OLECLOSE_NOSAVE.
//
// Returns an HRESULT
////////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::Close(DWORD dwSaveOption)
{
    ATLTRACE(TEXT("CBscEditorDocument(IOleObject)::Close\n"));

    if (m_fZombie)
        return S_OK;

    // Set guard flag
    m_fZombie = TRUE;

    // Release status bar
    m_srpVsStatusBar.Release();

    // disconnect from the file change notification sink
    if (m_srpVsFileChangeEx && (VSCOOKIE_NIL != m_vscookieFileChangeConnection) )
    {
        m_srpVsFileChangeEx->UnadviseFileChange(
            /* [in] VSCOOKIE vsCookie */ m_vscookieFileChangeConnection);
        m_vscookieFileChangeConnection = VSCOOKIE_NIL;
    }
    m_srpVsFileChangeEx.Release();

    // Ensure that the window procedure is definitely our local procedure
    ::SetWindowLongPtr(m_hwndRTF, GWLP_WNDPROC, (LONG_PTR)m_pfWndProc);

    // Now call the IOleObject::Close (using ATL template)
    return IOleObject_Close(dwSaveOption);
}




////////////////////////////////////////////////////////////////////////////////
//
// Function:    TranslateAccelerator 
//                (IOleInPlaceActiveObject::TranslateAccelerator override)
//                This function overrides the 
//                IOleInPlaceActiveObject::TranslateAccelerator method. All
//                we do is to check that our object is not already closed and
//                if not we merely call IOleInPlaceActiveObject::TranslateAccelerator.
//
// Parameters:
//    lpmsg        
//
// Returns an HRESULT
////////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::TranslateAccelerator(LPMSG lpmsg)
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    return IOleInPlaceActiveObjectImpl<CBscEditorDocument>::TranslateAccelerator(lpmsg);
}

////////////////////////////////////////////////////////////////////////////////
//
// Function:    SetClientSite (IOleObject::SetClientSite override)
//                This function overrides the IOleObject::SetClientSite method. 
//                This method is invoked just after the object has been 
//                instantiated and at that time is passed a valid client site
//                pointer. The method is also invoked before the object is 
//                deleted and is given a null client site pointer at that time.
//                Basically we obtain a number of interface pointers after
//                instantiation and we release services before deletion. Fianlly
//                we call the overridden method befor exiting.
//
// Parameters:
//    pClientSite    Client site pointer (on startup) or NULL (prior to closedown).
//
// Returns an HRESULT
////////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::SetClientSite(IOleClientSite* pClientSite)
{

    ATLTRACE(TEXT("CBscEditorDocument::SetClientSite\n"));
    HRESULT        hr;                        // Return value

    // If pClientSite is not NULL then we are starting up so we must retrieve everything.
    // If pClientSite is NULL then we release a few pointers.
    if (pClientSite)
    {
        // First of all we must query for the service provider from the client site.
        //////////////////////////////////////////////////////////////
        //Grab InPlaceSite ServiceProvider
        hr = pClientSite->QueryInterface(IID_IServiceProvider, (void**)&m_srpSiteSP);

        ATLASSERT(m_srpSiteSP);
        if (!m_srpSiteSP)
            return E_FAIL;

        // Now get the Track Selection interface pointer
        hr =  m_srpSiteSP->QueryService(SID_SVsTrackSelectionEx, 
                                 IID_ITrackSelection,
                                 (void **) &m_srpTrackSelection);
        if (!m_srpTrackSelection)
            return E_FAIL;

        // Obtain the Shell service
        hr = m_srpSiteSP->QueryService(SID_SVsShell, IID_IVsShell, (void**)&m_srpShell);
        if (!m_srpShell)
            return E_FAIL;

        // Now get the Toolbox Clipboard Cycler. We need this to paste stuff from
        // the toolbox. See IVsToolboxUser interface and command cmdidPasteNextTBXCBItem.
        hr =  m_srpSiteSP->QueryService(SID_SVsToolbox, 
                                 IID_IVsToolboxClipboardCycler,
                                 (void **) &m_srpVsToolboxClipboardCycler);
        if (!m_srpVsToolboxClipboardCycler)
            return E_FAIL;

        // Get the current macro recording state
        if (!SUCCEEDED(hr = GetRecordState()))
            return hr;

    }
    else
    {
        // We are shutting down here so we need to release a few services.

        // Disconnect from event sink and release shell pointer
        if (m_srpShell)
        {
            m_srpShell.Release();
        }

        // If we are macro recording then release the service.
        if (m_srpMacroRecorder)
        {
            m_fMacroRecording = false;
            ResetMacroState();
            m_srpMacroRecorder.Release();
        }

        // Release track selection, Toolbox Clipboard Cycler and client site.
        if (m_srpTrackSelection)
        {
            ///////////////////////////////////////////////
            //Dump track selection
            m_srpTrackSelection->OnSelectChange(NULL);
            m_srpTrackSelection.Release();
        }
        if (m_srpVsToolboxClipboardCycler)
            m_srpVsToolboxClipboardCycler.Release();
        if (m_srpSiteSP)
            m_srpSiteSP.Release();

        // Release the UI pointers
        if (m_ccpUIMgr)
            m_ccpUIMgr.Release();
        if (m_ccpIPUIMgr)
            m_ccpIPUIMgr.Release();
        if (m_ccpIPCompSite)
            m_ccpIPCompSite.Release();
    }

    // Call the underlying (overridden) method
    return IOleObjectImpl<CBscEditorDocument>::SetClientSite(pClientSite);
}

////////////////////////////////////////////////////////////////////////////////
//
// Function:    InPlaceActivate (CComControlBase::InPlaceActivate override)
//                This function overrides the CComControlBase::InPlaceActivate 
//                method. This function Determines that the control can be in-place
//                activated, informs the container the control is going in-place
//                active, and activates the control.
//
// Parameters:
//    iVerb        Verb we expect to indicate UI activation - typically OLEIVERB_SHOW.
//    prcPosRect    Not used.
//
// Returns an HRESULT
////////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::InPlaceActivate(LONG iVerb, const RECT* /*prcPosRect*/)
{
    HRESULT hr;

    if (m_spClientSite == NULL)
        return S_OK;

    // Get the smart pointer to the inplace object
    CComPtr<IOleInPlaceObject> srpIPO;
    ControlQueryInterface(IID_IOleInPlaceObject, (void**)&srpIPO);
    ATLASSERT(srpIPO != NULL);

    hr = EnsureInPlaceSite();
    if (FAILED(hr))
        return hr;

    // If we are not currently active then activate.
    if (!m_bInPlaceActive)
    {

        BOOL bNoRedraw = FALSE;
        if (m_bWndLess)
            m_spInPlaceSite->OnInPlaceActivateEx(&bNoRedraw, ACTIVATE_WINDOWLESS);
        else
        {
            if (m_bInPlaceSiteEx)
                m_spInPlaceSite->OnInPlaceActivateEx(&bNoRedraw, 0);
            else
            {
                hr = m_spInPlaceSite->CanInPlaceActivate();
                // CanInPlaceActivate returns S_FALSE or S_OK
                if (FAILED(hr))
                    return hr;
                if ( hr != S_OK )
                {
                   // CanInPlaceActivate returned S_FALSE.
                   return( E_FAIL );
                }
                m_spInPlaceSite->OnInPlaceActivate();
            }
        }
    }

    m_bInPlaceActive = TRUE;

    // get location in the parent window,
    // as well as some information about the parent
    //
    OLEINPLACEFRAMEINFO frameInfo;
    RECT rcPos, rcClip;
    CComPtr<IOleInPlaceFrame> spInPlaceFrame;
    CComPtr<IOleInPlaceUIWindow> spInPlaceUIWindow;
    frameInfo.cb = sizeof(OLEINPLACEFRAMEINFO);

    m_spInPlaceSite->GetWindowContext(&spInPlaceFrame,
        &spInPlaceUIWindow, &rcPos, &rcClip, &frameInfo);

    if (!m_bWndLess)
    {
        if (m_hWndCD)
            ::ShowWindow(m_hWndCD, SW_SHOW);
        else
            EnsureControlWindow();
    }

    srpIPO->SetObjectRects(&rcPos, &rcClip);

    // Gone active by now, take care of UIACTIVATE
    if (DoesVerbUIActivate(iVerb))
    {
        if (!m_bUIActive)
        {
            m_bUIActive = TRUE;
            hr = m_spInPlaceSite->OnUIActivate();
            if (FAILED(hr))
                return hr;

            SetControlFocus(TRUE);
            
            m_ccpIPUIMgr->UIActivateForMe(m_dwRole, GUID_BscEditorFactory, 
                static_cast<IOleInPlaceActiveObject*>(this), 
                static_cast<IOleCommandTarget*>(this),
                0, NULL);

        }
    }

    m_spClientSite->ShowObject();

    //////////////////////////////////////////////////////////////
    //Make sure we are the selection container
    ISelectionContainer* pISC = (ISelectionContainer*)this;

    hr = m_srpTrackSelection->OnSelectChange(pISC);

    return S_OK;
}


////////////////////////////////////////////////////////////////////////////////
//
// Function:    IOleInPlaceObject_UIDeactivate 
//                (CComControlBase::IOleInPlaceObject_UIDeactivate override)
//                This function overrides the CComControlBase::IOleInPlaceObject_UIDeactivate 
//                method. We merely inform the frame windows we are inactive
//                and call the inplace site deactivation method.
//
// Parameters:
//    iVerb        Verb we expect to indicate UI activation - typically OLEIVERB_SHOW.
//    prcPosRect    Not used.
//
// Returns an HRESULT
////////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::IOleInPlaceObject_UIDeactivate(void)
{
    // if we're not UIActive, not much to do.
    //
    if (!m_bUIActive)
        return S_OK;

    m_bUIActive = FALSE;

    // notify frame windows, if appropriate, that we're no longer ui-active.
    //
    // we don't need to explicitly release the focus here since somebody
    // else grabbing the focus is what is likely to cause us to get lose it
    //
    m_spInPlaceSite->OnUIDeactivate(FALSE);

    return S_OK;
}



/////////////////////////////////////////////////////////////////////////////
//
// Function:    HrInit
//                This function is called from the editor factory
//                function CreateEditorInstance immediately after
//                instantiating our object (document) to perform
//                initialisation of our object.
//
// Parameters:
//    pCVsPkg        Package object
//
// Returns:        An HRESULT
//
////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::HrInit(CVsPackage *pCVsPkg)
{
    HRESULT hr = S_OK;

    ATLTRACE(TEXT("CBscEditorDocument::HrInit\n"));
    ATLASSERT(!m_pCVsPkg);        // recursion guard

    // Store the package pointer.
    m_pCVsPkg = pCVsPkg;

    // Make sure that the richedit dll is available
    hr = LoadRichEdit();
    if (FAILED(hr))
        return hr;

    return S_OK;
}




//MessageHandler
/////////////////////////////////////////////////////////////////////////////
//
// Function:    OnSize (Message Handler)
//                This function repositions the window when it has been resized
//                or moved.
//
// Parameters:
//    nMsg        Not used.
//    wParam        Not used.
//    lParam        Not used.
//    bHandled    Not used.
//
// Returns:        S_OK
//
////////////////////////////////////////////////////////////////////////////
LRESULT CBscEditorDocument::OnSize(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    RECT rc;
    ::GetClientRect(m_hWndCD, &rc);

    if (m_hwndRTF)
    {
        ::MoveWindow(m_hwndRTF, 
                   rc.left, 
                   rc.top, 
                   rc.right - rc.left,
                   rc.bottom - rc.top, 
                   TRUE);
    }

    return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
//
// Function:    OnCommand (Message Handler)
//                If there has been a change to the window text this function
//                sets the file as dirty and calls the support function which
//                informs the shell it needs to update its menus and tool bars.
//
// Parameters:
//    nMsg        Not used.
//    wParam        Parameter passed to GET_WM_COMMAND_HWND and GET_WM_COMMAND_CMD.
//    lParam        Parameter passed to GET_WM_COMMAND_HWND and GET_WM_COMMAND_CMD.
//    bHandled    Not used.
//
// Returns:        0
//
////////////////////////////////////////////////////////////////////////////
LRESULT CBscEditorDocument::OnCommand(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    
    if (GET_WM_COMMAND_HWND(wParam, lParam) == m_hwndRTF)
    {

        switch (GET_WM_COMMAND_CMD(wParam, lParam))
        {

        case EN_CHANGE:
            // We need to process this message only to update the Dirty flas, but this
            // means that we are interessed only in the FALSE->TRUE transition
            BOOL fIsDirty = FALSE;
            if (SUCCEEDED(IsDirty(&fIsDirty)) && (FALSE==fIsDirty))
            {
                // Before updating the flag we need to check with the source control
                // if the file can be changed.
                BOOL fDiscardInput = FALSE;
                FileCheckedOut(&fDiscardInput);
                if ( FALSE==fDiscardInput )
                {
                    // The Source Control system agrees that we can change it
                    ATLTRACE(TEXT("Setting Dirty flag from CBscEditorDocument::OnCommand\n"));
                    SetState(eFileStateDirty, TRUE);
                    VUpdateCmds();    // Ensure the shell utimately updates display
                }
                else
                {
                    // Something went wrong with the source control or this file can't
                    // be edited. In both cases we can't accept the changes.
                    SendMessage(m_hwndRTF, EM_UNDO, 0, 0);
                }
            }
            break;

        // $CONISDER: other notifications:     EN_ERRSPACE, EN_MAXTEXT
        }
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
//
// Function:    OnSetFocus (Message Handler)
//                This function merely sets the focus to the Rich Edit window                                
//
// Parameters:
//    nMsg        Not used.
//    wParam        Not used
//    lParam        Not used
//    bHandled    Not used.
//
// Returns:        An LRESULT
//
////////////////////////////////////////////////////////////////////////////
LRESULT CBscEditorDocument::OnSetFocus(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    
    ::SetFocus(m_hwndRTF);
    return 0;
}


/////////////////////////////////////////////////////////////////////////////
//
// Function:    OnNotify (Message Handler)
//                This function is interested in selection change messages,
//                (for which it calls the function to update the selection
//                or current insertion point) and mouse or keyboard events.                                
//
// Parameters:
//    nMsg        Not used.
//    wParam        Notification message (we examine the message code)
//    lParam        Not used
//    bHandled    Not used.
//
// Returns:        An LRESULT
//
////////////////////////////////////////////////////////////////////////////
LRESULT CBscEditorDocument::OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    
    switch(((NMHDR *) lParam)->code)
    {

    case EN_SELCHANGE:
        StatusBar_UpdatePos();
        VUpdateCmds();
        return 0;
    // $CONISDER: other notifications: EN_DROPFILES, EN_REQUESTRESIZE, EN_MSGFILTER
    case EN_MSGFILTER:
        // Keyboard or mouse event in RTF window.
        return (LRESULT) LHandleKeyboardMouseEvent((MSGFILTER *) lParam);
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
//
// Function:    OnParentNotify (Message Handler)
//                This function merely sets bHandled to FALSE to indicate    these
//                messages are handled elsewhere.                            
//
// Parameters:
//    nMsg        Not used.
//    wParam        Not used.
//    lParam        Not used.
//    bHandled    We set this to FALSE.
//
// Returns:        S_OK
//
////////////////////////////////////////////////////////////////////////////
LRESULT CBscEditorDocument::OnParentNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    bHandled = FALSE;

    return S_OK;
}


HRESULT CBscEditorDocument::EnsureInPlaceSite(void)
{
    HRESULT hr = S_OK;

    // Get the inplace site by querying for any one of three interfaces.
    // Note that one of these QIs should be successful.
    if (!m_bNegotiatedWnd)
    {
        // We should not be windowless but we check it for completeness
        if (!m_bWindowOnly)
            // Try for windowless site
            hr = m_spClientSite->QueryInterface(IID_IOleInPlaceSiteWindowless, (void **)&m_spInPlaceSite);

        if (m_spInPlaceSite)
        {
            m_bInPlaceSiteEx = TRUE;
            // CanWindowlessActivate returns S_OK or S_FALSE
            if ( m_spInPlaceSite->CanWindowlessActivate() == S_OK )
            {
                m_bWndLess = TRUE;
                m_bWasOnceWindowless = TRUE;
            }
            else
            {
                m_bWndLess = FALSE;
            }
        }
        else
        {
            m_spClientSite->QueryInterface(IID_IOleInPlaceSiteEx, (void **)&m_spInPlaceSite);
            if (m_spInPlaceSite)
                m_bInPlaceSiteEx = TRUE;
            else
                hr = m_spClientSite->QueryInterface(IID_IOleInPlaceSite, (void **)&m_spInPlaceSite);
        }
    }

    // Check that we have an inplace site.
    ATLASSERT(m_spInPlaceSite);
    if (!m_spInPlaceSite)
        return E_FAIL;

    m_bNegotiatedWnd = TRUE;

    return S_OK;
}

HRESULT CBscEditorDocument::EnsureControlWindow(void)
{
    if (m_bWndLess || m_hWndCD)
        return S_OK;

    HRESULT hr = S_OK;
    hr = EnsureInPlaceSite();
    if (FAILED(hr))
        return hr;
    if (!m_spInPlaceSite)
        return E_UNEXPECTED;

    // get location in the parent window,
    // as well as some information about the parent
    //
    OLEINPLACEFRAMEINFO frameInfo;
    RECT rcPos, rcClip;
    CComPtr<IOleInPlaceFrame> spInPlaceFrame;
    CComPtr<IOleInPlaceUIWindow> spInPlaceUIWindow;
    frameInfo.cb = sizeof(OLEINPLACEFRAMEINFO);
    HWND hwndParent;
    if (m_spInPlaceSite->GetWindow(&hwndParent) != S_OK)
        return E_FAIL;

    m_spInPlaceSite->GetWindowContext(&spInPlaceFrame,
        &spInPlaceUIWindow, &rcPos, &rcClip, &frameInfo);

    HWND h = CreateControlWindow(hwndParent, rcPos);
    ATLASSERT(h != NULL);    // will assert if creation failed
    ATLASSERT(h == m_hWndCD);
    if(h == NULL)
        return E_FAIL;

    return S_OK;
}



/////////////////////////////////////////////////////////////////////////////
//
// Function:    CreateRTFWindow
//                This function creates the RTF window and subclasses this
//                window so that we can receive all th keystrokes before
//                passing them on to the rich edit control - this facilitates
//                macro recording amongst other things. We also get the OLE
//                interface from the RTF control and hence the ITextDocument
//                and ITextRange interfaces.                        
//
// Parameters:
//    None
//
// Returns:        An HRESULT
//
////////////////////////////////////////////////////////////////////////////
HRESULT CBscEditorDocument::CreateRTFWindow(void)
{
    HRESULT hr = S_OK;

    if (m_hwndRTF)
        return S_OK;

    hr = EnsureControlWindow();
    if (FAILED(hr))
        return hr;

    CComPtr<IUnknown> srpUnk;
    
    RECT rc;
    if (!::GetClientRect(m_hWndCD, &rc))
    {
        hr = HrLastError();
        goto errExit;
    }

    // Now create the Rich edit control window
    m_hwndRTF = ::CreateWindowEx(0,     
                               RICHEDIT_CLASS,
                               (LPCTSTR) NULL,    
                               WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_WANTRETURN | ES_NOHIDESEL,
                               rc.left, rc.top,
                               rc.right - rc.left, rc.bottom - rc.top,
                               m_hWndCD,
                               NULL,
                               _AtlBaseModule.GetModuleInstance(),
                               NULL);
    
  if (!m_hwndRTF)
    {
        DWORD err = GetLastError();

        hr = E_FAIL;
        goto errExit;
    }


    // Set up the window procedure and its data pointer (i.e. subclass the window)
    m_pfWndProc = (WNDPROC)::SetWindowLongPtr(m_hwndRTF, GWLP_WNDPROC, (LONG_PTR)CBscEditorDocument::MyWndProc);
    ::SetWindowLongPtr(m_hwndRTF, GWLP_USERDATA, (LONG_PTR)this);

    // request EN_SELCHANGE, EN_CHANGE, EN_PROTECTED, and EN_DROPFILES - these will be handled
    // in CBscEditorDocument::OnNotify
    SendMessage(m_hwndRTF, EM_SETEVENTMASK, 0,     ENM_SELCHANGE | ENM_CHANGE | ENM_MOUSEEVENTS | EN_DROPFILES | ENM_KEYEVENTS);

    //now store away the OLE interface
    SendMessage(m_hwndRTF, EM_GETOLEINTERFACE, 0, (LPARAM)&srpUnk);

    hr = srpUnk->QueryInterface(IID_ITextDocument, (LPVOID*)&m_srpTextDocObj);
    if (hr != S_OK)
        goto errExit;

    // Get the TextRange object
    hr = m_srpTextDocObj->Range(0, tomForward, &m_srpTextRange);

errExit:
    return hr;
}


//////////////////////////////////////////////////////////////////
// IOleInPlaceComponent methods
// Note all other methods for this interface are defined inline
// in the header file EdCommon.h
//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
// Function:    UseComponentUIManager (IOleInPlaceComponent Interface)
//                This function stores the role for later use,
//                stores the inplace component site and uses
//                the given component UI manager to query for
//                the inplace component UI manager.
//
// Parameters:
//    dwCompRole        Role stored for later use in call to UIActivateForMe.
//    pgrfCompFlags    Not used.
//    pCompUIMgr        Component UI manager.
//    pIPCompSite        Inplace component site.
//
// Returns:        An HRESULT
//
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::UseComponentUIManager( 
                /* [in] */ DWORD dwCompRole, 
                /* [out]*/ DWORD *pgrfCompFlags,
                /* [in] */ IOleComponentUIManager *pCompUIMgr, 
                /* [in] */ IOleInPlaceComponentSite *pIPCompSite )
{
    m_dwRole = dwCompRole;
    
    m_ccpIPCompSite = pIPCompSite;
    m_ccpUIMgr = pCompUIMgr;
    
    IOleInPlaceComponentUIManager* pIPUIMgr = NULL;

    m_ccpUIMgr->QueryInterface(IID_IOleInPlaceComponentUIManager, (void**)&pIPUIMgr);

    if (pIPUIMgr)
    {
        m_ccpIPUIMgr = pIPUIMgr;
        pIPUIMgr->Release();
    }

    if (pgrfCompFlags)
        *pgrfCompFlags = 0;

    ATLTRACE(_T("CBscEditorDocument::UseComponentUIManager\n"));
    return S_OK;
}


#endif //INPLACE