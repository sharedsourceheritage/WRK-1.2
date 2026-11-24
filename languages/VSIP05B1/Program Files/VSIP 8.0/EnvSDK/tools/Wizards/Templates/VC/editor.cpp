
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Editor.cpp : Implementation of CBscEditorDocument
//
// This version of the editor implements the IVsWindowPane interface.
// This is only included in the compilation if the compile time switch
// INPLACE is NOT defined.
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"    
#include "..\%ProjectName%UI\guids.h"
#include "EdCommon.h"        // project includes
#include "..\%ProjectName%UI\resource.h"

    
#ifndef INPLACE

CONST TCHAR szWndClassName[] = TEXT("RTFEditWin");






/////////////////////////////////////////////////////////////////////////////
// CBscEditorDocument


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
HRESULT CBscEditorDocument::HrInit(C%ProjectClass%Package *pCVsPkg)
{
    ATLTRACE(TEXT("CBscEditorDocument::HrInit\n"));
    _ASSERTE(!m_pCVsPkg);        // recursion guard

    m_pCVsPkg = pCVsPkg;
    static bool bInitialized = false;

    if (!bInitialized)
    {
        // Make sure that the richedit dll is available
        HRESULT hr = LoadRichEdit();
        if (FAILED(hr))
            return hr;

        // Register our window class
        WNDCLASS wc;

        wc.style = CS_DBLCLKS;
        wc.lpfnWndProc = (WNDPROC) WndProcSTATIC;    // Call back function
        wc.cbClsExtra = 0;
        wc.cbWndExtra = sizeof(VOID *);
        wc.hInstance = _AtlBaseModule.GetModuleInstance();
        wc.hIcon = NULL;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = GetSysColorBrush(COLOR_WINDOW);
        wc.lpszMenuName = NULL;
        wc.lpszClassName = szWndClassName;

        if (0 == RegisterClass(&wc))
        {
            return HrLastError();
        }
        
        bInitialized = true;
    }

    return S_OK;
}

  


/*****************************************************************************
** IVsWindowPane Implementation
*****************************************************************************/

/////////////////////////////////////////////////////////////////////////////
//
// Function:    SetSite (Interface IVsWindowPane)
//                This function is called on intialising the IVsWindowPane. We
//                determine the current macro recording state from the shell and
//                hook up the Find/Replace dialog provided by the shell.
//
// Parameters:
//    pSP            Service Providor
//
// Returns:        An HRESULT
//
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::SetSite(
                    /*[in] */ IServiceProvider *pSP)
{
    ATLTRACE(TEXT("CBscEditorDocument::SetSite\n"));

    _ASSERTE(pSP != NULL);
    if (!pSP)
        return E_POINTER;
    HRESULT            hr;

    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    m_srpSiteSP = pSP;        // Note: assignment to a smart pointer does an AddRef()

    // Get the Shell service so that we can read the macro recording state.
    hr = m_srpSiteSP->QueryService(SID_SVsShell, IID_IVsShell, (void**)&m_srpShell);
    if (!m_srpShell)
        return E_FAIL;

    // Now get the Track Selection interface pointer
    hr =  m_srpSiteSP->QueryService(SID_SVsTrackSelectionEx, 
                             IID_ITrackSelection,
                             (void **) &m_srpTrackSelection);
    if (!m_srpTrackSelection)
        return E_FAIL;

    // Now get the Toolbox Clipboard Cycler. We need this to paste stuff from
    // the toolbox. See IVsToolboxUser interface and command cmdidPasteNextTBXCBItem.
    hr =  m_srpSiteSP->QueryService(SID_SVsToolbox, 
                             IID_IVsToolboxClipboardCycler,
                             (void **) &m_srpVsToolboxClipboardCycler);
    if (!m_srpVsToolboxClipboardCycler)
        return E_FAIL;

    // Get the currrent macro recording state
    if (!SUCCEEDED(hr = GetRecordState()))
        return hr;

    if (FAILED(m_srpSiteSP->QueryService (SID_SVsStatusbar, IID_IVsStatusbar, (void **)&m_srpVsStatusBar)))
       m_srpVsStatusBar = NULL; // ok not to have one...

    //////////////////////////////////////////////////////////////
    //Make sure we are the selection container
    ISelectionContainer* pISC = (ISelectionContainer*)this;

    hr = m_srpTrackSelection->OnSelectChange(pISC);

       
    return NOERROR;
}


/////////////////////////////////////////////////////////////////////////////
//
// Function:    CreatePaneWindow (IVsWindowPane interface)
//                This function creates a parent window and the
//                RTF window itself. The parent window receives
//                notification messages. The RTF window is also
//                subclassed basically so we can examine all the 
//                keystrokes etc. before passing them on to the
//                RichEdit control. We do this to facilitate
//                macro recording.
//
// Parameters:
//    hwndParent    Parent window handle (parent of our parent)
//    x, y        Window position in screen coordinates
//    cx, cy        Window width and height
//    phwnd        Return location for our parent window handle
//
// Returns:        An HRESULT
//
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::CreatePaneWindow(
                    /*[in] */ HWND hwndParent,
                    /*[in] */ int x,
                    /*[in] */ int y,
                    /*[in] */ int cx,
                    /*[in] */ int cy,
                    /*[out]*/ HWND *phwnd)
{
    ATLTRACE(TEXT("CBscEditorDocument::CreatePaneWindow\n"));
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    // Validate params
    if (!phwnd)
        return E_POINTER;

    HRESULT    hr = NOERROR;
    CComPtr<IUnknown> srpUnk;
    
    _ASSERTE(NULL == m_hwnd);
    _ASSERTE(NULL == m_hwndRTF);

    // Create the RichEdit control's parent window (this will receive its notifications)
    m_hwnd = CreateWindowEx(0,             
                            szWndClassName,
                            (LPCTSTR) NULL,    
                            WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE,
                            x, y, cx, cy,
                            hwndParent,
                            NULL,
                            _AtlBaseModule.GetModuleInstance(),
                            NULL);
    if (!m_hwnd)
    {
        hr = E_FAIL;
        goto errExit;
    }

    // Store ptr to this doc in window class struct extra bytes
    // Note that we set up the window function pointer in HrInit
    // when we register our window class.
    SetWindowLongPtr(m_hwnd, 0, (LONG_PTR) this);

    RECT rc;
    if (!GetClientRect(m_hwnd, &rc))
    {
        hr = HrLastError();
        goto errExit;
    }

    // Now create the Rich edit control window
    // Note that we use ES_NOHIDESEL so that the selected text is highlighted
    // during find and replace operations.
    m_hwndRTF = CreateWindowEx(0,     
                               RICHEDIT_CLASS,
                               (LPCTSTR) NULL,    
                               WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_WANTRETURN | ES_NOHIDESEL,
                               rc.left, rc.top,
                               rc.right - rc.left, rc.bottom - rc.top,
                               m_hwnd,
                               NULL,
                               _AtlBaseModule.GetModuleInstance(),
                               NULL);
    if (!m_hwndRTF)
    {
        hr = E_FAIL;
        goto errExit;
    }

    // Set up the window procedure and its data pointer (i.e. subclass the Rich edit control window)
    m_pfWndProc = (WNDPROC)::SetWindowLongPtr(m_hwndRTF, GWLP_WNDPROC, (LONG_PTR)CBscEditorDocument::MyWndProc);
    ::SetWindowLongPtr(m_hwndRTF, GWLP_USERDATA, (LONG_PTR)this);

    // request EN_SELCHANGE, EN_CHANGE, EN_PROTECTED, and EN_DROPFILES
    SendMessage(m_hwndRTF, EM_SETEVENTMASK, 0,     ENM_SELCHANGE | ENM_CHANGE | ENM_MOUSEEVENTS | EN_DROPFILES | ENM_KEYEVENTS);

    // Obtain a ptr to the underlying ITextDocument from the RTF control
    SendMessage(m_hwndRTF, EM_GETOLEINTERFACE, 0, (LPARAM)(LPVOID *)&srpUnk);
    if (!srpUnk)
    {
        hr = E_FAIL;
        goto errExit;
    }
    if (FAILED(hr = srpUnk->QueryInterface(IID_ITextDocument, (LPVOID *)&m_srpTextDocObj)))
    {
        goto errExit;
    }

    // Finally show the window
    ShowWindow(m_hwnd, SW_SHOW);

    goto successExit;

errExit:

    if (m_hwnd)
    {
        DestroyWindow(m_hwnd);
    }
    m_hwndRTF = NULL;
    m_hwnd = NULL;

    // fall thru

successExit:

    *phwnd = m_hwnd;
    return hr;

}

/////////////////////////////////////////////////////////////////////////////
//
// Function:    GetDefaultSize (IVsWindowPane interface)
//                We merely retrieve the window deafult size.
//
// Parameters:
//    psize        Return location for window size details.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::GetDefaultSize(
                    /*[out]*/ SIZE *psize)
{
    ATLTRACE(TEXT("CBscEditorDocument::GetDefaultSize\n"));
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    if (!psize)
        return E_POINTER;

    *psize = m_WinSize;
    return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
//
// Function:    ClosePane (IVsWindowPane interface)
//                Basically we release our services and destroy our window.
//
// Parameters:
//    None
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::ClosePane(void)
{
    ATLTRACE(TEXT("CBscEditorDocument::ClosePane\n"));
    if (m_fZombie)
        return S_OK;

    m_fZombie = TRUE;

    if (m_srpVsStatusBar)
        m_srpVsStatusBar.Release();

    // Disconnect from the file change notification sink
    if (m_srpVsFileChangeEx && (VSCOOKIE_NIL != m_vscookieFileChangeConnection) )
    {
        m_srpVsFileChangeEx->UnadviseFileChange(
            /* [in] VSCOOKIE vsCookie */ m_vscookieFileChangeConnection);
        m_vscookieFileChangeConnection = VSCOOKIE_NIL;
    }
    m_srpVsFileChangeEx.Release();

    // Release ptrs to RTF control's object model
    if (m_srpTextDocObj)
        m_srpTextDocObj.Release();

    // Destroy the windows
    _ASSERTE(m_hwnd);
    if (m_hwnd)
        DestroyWindow(m_hwnd);

    m_hwndRTF = NULL;
    m_hwnd = NULL;

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

    // Release track selection, toolbox clipboard cycler and site
    if (m_srpTrackSelection)
        m_srpTrackSelection.Release();
    if (m_srpVsToolboxClipboardCycler)
        m_srpVsToolboxClipboardCycler.Release();
    if (m_srpSiteSP)
        m_srpSiteSP.Release();


    return S_OK;
}

/////////////////////////////////////////////////////////////////////////////
//
// Function:    LoadViewState (IVsWindowPane interface)
//                Nothing to do here.
//
// Parameters:
//    pstream        Not used.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::LoadViewState(
                    /*[in] */ IStream *pstream)
{
    ATLTRACE(TEXT("CBscEditorDocument::LoadViewState\n"));
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    return S_OK;
}


/////////////////////////////////////////////////////////////////////////////
//
// Function:    SaveViewState (IVsWindowPane interface)
//                Nothing to do here.
//
// Parameters:
//    pstream        Not used.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::SaveViewState(
                    /*[in] */ IStream *pstream)
{
    ATLTRACE(TEXT("CBscEditorDocument::SaveViewState\n"));
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    return S_OK;
}


/////////////////////////////////////////////////////////////////////////////
//
// Function:    TranslateAccelerator (IVsWindowPane interface)
//                Nothing to do here.
//
// Parameters:
//    lpmsg        Not used.
//
// Returns:        An HRESULT
////////////////////////////////////////////////////////////////////////////
STDMETHODIMP CBscEditorDocument::TranslateAccelerator(
                              LPMSG lpmsg)
{
    if (m_fZombie)
        return E_UNEXPECTED;        // recursion guard

    return S_FALSE; // we don't handle any messages
}







/*****************************************************************************
** other methods
*****************************************************************************/

//
// Parent window function
//
/////////////////////////////////////////////////////////////////////////////
//
// Function:    WndProcSTATIC
//                Callback function attached to the parent window of
//                the Richedit control window. 
//
// Parameters:
//    hwnd        Handle for the associated window
//    wm            Window message ID
//    wParam        Command parameter 1
//    lParam        Command parameter 2
///
// Returns:        An LRESULT
////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK CBscEditorDocument::WndProcSTATIC(
                              HWND hwnd,
                              UINT wm, 
                              WPARAM wParam, 
                              LPARAM lParam)
{
    USES_CONVERSION;

    // Obtain the user data associated with our window. In this case it is a
    // pointer to our object (document).
    CBscEditorDocument *pThis = (CBscEditorDocument *) GetWindowLongPtr(hwnd, 0);

    if (pThis)
    {    
        switch (wm)
        {
        case WM_SETFOCUS:
            ::SetFocus(pThis->m_hwndRTF);
            break;

        case WM_SIZE:
            // Window has been resized.
            RECT rc;
            GetClientRect(hwnd, &rc);

            if (pThis->m_hwndRTF)
            {
                MoveWindow(pThis->m_hwndRTF, 
                           rc.left, 
                           rc.top, 
                           rc.right - rc.left,
                           rc.bottom - rc.top, 
                           TRUE);
            }
            break;

        case WM_COMMAND:
            // Menu command, notification message from control to parent or
            // an accelerator keystroke has been translated.
            if (GET_WM_COMMAND_HWND(wParam, lParam) == pThis->m_hwndRTF)
            {

                switch (GET_WM_COMMAND_CMD(wParam, lParam))
                {

                case EN_CHANGE:
                    // We need to process this message only to update the Dirty flas, but this
                    // means that we are interessed only in the FALSE->TRUE transition
                    BOOL fIsDirty = FALSE;
                    if (SUCCEEDED(pThis->IsDirty(&fIsDirty)) && (FALSE==fIsDirty))
                    {
                        // Before updating the flag we need to check with the source control
                        // if the file can be changed.
                        BOOL fDiscardInput = FALSE;
                        if (SUCCEEDED(pThis->FileCheckedOut(&fDiscardInput)) && (FALSE==fDiscardInput))
                        {
                            // The Source Control system agrees that we can change it
                            ATLTRACE(TEXT("Setting Dirty flag from CBscEditorDocument::WndProcSTATIC\n"));
                            pThis->SetState(eFileStateDirty, TRUE);
                            pThis->VUpdateCmds();    // Ensure the shell utimately updates display
                        }
                        else
                        {
                            // Something went wrong with the source control or this file can't
                            // be edited. In both cases we can't accept the changes.
                            SendMessage(pThis->m_hwndRTF, EM_UNDO, 0, 0);
                        }
                    }
                    break;

                // $CONISDER: other notifications:     EN_ERRSPACE, EN_MAXTEXT
                }
                return 0;
            }
            break;
            
        case WM_NOTIFY:
            // Control to parent message
            switch(((NMHDR *) lParam)->code)
            {

            case EN_SELCHANGE:
                // Selection has changed.
                pThis->StatusBar_UpdatePos();
                pThis->VUpdateCmds();
                return 0;
            
            case EN_MSGFILTER:
                // Keyboard or mouse event in RTF window.
                return (LRESULT) pThis->LHandleKeyboardMouseEvent((MSGFILTER *) lParam);

            // $CONISDER: other notifications: EN_DROPFILES, EN_REQUESTRESIZE, EN_MSGFILTER
            }
            break;
                            
        case WM_TIMER:
            if (wParam == WFILECHANGEDTIMERID) 
            {
                DWORD dwProcessID;
                HWND hwndEnv = GetActiveWindow();
                
                // This timer is set in CBscEditorDocument::FilesChanged which is a notification
                // from the SVsFileChangeEx service that the file we are editing has changed outside
                // of the environment. We want to prompt the user whether they want to reload the file.
                // it is important to not syncronisly reload the file inside of the FilesChanged
                // notification. first it is possible that there will be more than one FilesChanged 
                // notification being sent (sometimes you get separate notifications for file attribute
                // changing and file size/time changing). also it is the preferred UI style to not
                // prompt the user until the user re-activates the environment application window.
                // this is why we use a timer to delay prompting the user.
                
                // If the environment is the active window, shut off the timer and prompt to reload file.
                GetWindowThreadProcessId(hwndEnv, &dwProcessID);
                if (dwProcessID == GetCurrentProcessId())
                {
                    ::KillTimer(pThis->m_hwnd, 1);
                    pThis->m_fFileChangedTimerSet = FALSE;

                    TCHAR pszMsg[MAX_MSGTEXTLEN];
                    long nResult = LoadString(_AtlBaseModule.GetResourceInstance(), IDS_OUTSIDEEDITORFILECHANGE, pszMsg, countof(pszMsg));
                    _ASSERTE(nResult != 0);

                    if (IDYES == _AtlModule.ShowMessage(W2CT(pThis->m_bsFileName), pszMsg, OLEMSGBUTTON_YESNO, OLEMSGDEFBUTTON_FIRST, OLEMSGICON_QUERY))
                    {
                        pThis->ReloadDocData(0);
                    }
                }
            }
            break;

        default:
            break;
        }

    }

    // If we have not fully processed the message then call the
    // default window procedure.
    return DefWindowProc(hwnd, wm, wParam, lParam);
}














#endif //INPLACE
