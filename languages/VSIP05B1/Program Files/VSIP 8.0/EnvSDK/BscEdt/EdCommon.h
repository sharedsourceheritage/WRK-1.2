
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//////////////////////////////////////////////////////////////////////////////
// EdCommon.h : Declaration of the CBscEditorDocument
//
// Note that there are two versions of the editor one implements in-place activation
// and the other implements the IVsWindowPane interface. Note that which editor is
// compiled depends on whether INPLACE is defined or not. If INPLACE is defined
// the in-place activation version is compiled, if it is not defined then the
// IVsWindowPane version is compiled.


///////////////////////////////////////////////////////////////////////////////
// Note on new file dialog.
//
// We have decided that our file type should appear under "General" in the
// new files dialog. In order to achieve this we need the following:-
//     - A .vsdir file in the same directory as NewFileItems.vsdir.
//       In our case the file name is BscEdt.vsdir but the only 
//       naming requirement is the .vsdir extension.
//     - An empty RTF file in the same directory as NewFileItems.vsdir. In
//       our case we chose rtf.rtf. Note this file name appears in BscEdt.vsdir
//       (see vsdir file format below)
//     - An icon in our general resource file BscEdt\BscEdt.rc
//     - Three text strings in our language specific resource
//       file BscEdt\BscEdtUI\BscEdtUI.rc :-
//          - "Rich Text file" - this is shown next to our icon.
//          - "A blank rich text file" - shown in the description window
//             in the new file dialog.
//          - "Rtf" - This is the base file name. New files will initially
//             be named Rtf1.rtf, Rtf2.rtf... etc.
///////////////////////////////////////////////////////////////////////////////
// BscEdt.vsdir contents:-
//    rtf.rtf|{12093B31-EF68-11d1-9429-00AA00A3EFFF}|#6|50|#7|0|205|0|#8
//
// The fields in order are as follows:-
//    - rtf.rtf - our empty RTF file
//    - {12093B31-EF68-11d1-9429-00AA00A3EFFF} - our BscEdt package guid
//    - #6 - the ID of "Rich Text file"
//      (see IDS_FILETEXT in BscEdt\BscEdtUI\resource.h and BscEdtUI.rc)
//    - 50 - the display ordering priority
//    - #7 - the ID of "A blank rich text file"
//      (see IDS_WINDTEXT in BscEdt\BscEdtUI\resource.h and BscEdtUI.rc)
//    - 0 - resource dll string (we don't use this)
//    - 205 - the ID of our icon
//      (see IDI_ICON1 in BscEdt\resource.h and BscEdt.rc)
//    - 0 - various flags (we don't use this - se vsshell.idl)
//    - #8 - the ID of "Rtf"
//      (see IDS_FILENAME in BscEdt\BscEdtUI\resource.h and BscEdtUI.rc)
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <windows.h>
#include <atlctl.h>
#include <atlstr.h>
#include "guids.h"
#include <richedit.h>
#include <stdidcmd.h>
#include <stdiduie.h>    // For status bar consts.
#include "util.h"
#include "textfind.h"
#include <windowsx.h>



// ID of timer message send from IVsFileChageEvents method FilesChanged to
// window.
#define WFILECHANGEDTIMERID 1

// Paste wParam in a WM_CHAR message
#define CTRL_V          22
// Delete wParam in a WM_CHAR message
#define CTRL_X          24
// Bold wParam in a WM_CHAR message
#define CTRL_B           2
// Italic wParam in a WM_CHAR message
#define CTRL_I           9
// Underline wParam in a WM_CHAR message
#define CTRL_U          21
// Justify Left wParam in a WM_CHAR message
#define CTRL_L          12
// Justify Center wParam in a WM_CHAR message
#define CTRL_E           5
// Justify Right wParam in a WM_CHAR message
#define CTRL_R          18
// Select All wParam in a WM_CHAR message
#define CTRL_A           1


/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CVsPackage;

// Enum used in IOleCommandTarget handlers to Clear, Set or Toggle (default)
// the Character Format State (i.e. Bold, Italic, Underline or Strikeout)
typedef enum 
    {
        eStateClear,
        eStateSet,
        eStateToggle
    } FormatState;

// File state bit flags (note hex values)
typedef enum
    {
        eFileStateNone               =    0x0000,
        eFileStateNew                =    0x0001,
        eFileStateDirty              =    0x0002,
        eFileStateFileSysReadOnly    =    0x0004,
        eFileStateUserReadOnly       =    0x0008,
        eFileStateAllowEdits         =    0x0010

    } FileState;

// Last command type sent to the macro recorder. Note that there are more commands
// recorded than is implied by this list. Commands in this list (other than
// eLastMacroNone) are coalesced when multiples of the same command are received
// consecutively.
typedef enum
    {
        eLastMacroNone,
        eLastMacroText,
        eLastMacroDownArrowLine,
        eLastMacroDownArrowLineSel,
        eLastMacroDownArrowPara,
        eLastMacroDownArrowParaSel,
        eLastMacroUpArrowLine,
        eLastMacroUpArrowLineSel,
        eLastMacroUpArrowPara,
        eLastMacroUpArrowParaSel,
        eLastMacroLeftArrowChar,
        eLastMacroLeftArrowCharSel,
        eLastMacroLeftArrowWord,
        eLastMacroLeftArrowWordSel,
        eLastMacroRightArrowChar,
        eLastMacroRightArrowCharSel,
        eLastMacroRightArrowWord,
        eLastMacroRightArrowWordSel,
        eLastMacroDeleteChar,
        eLastMacroDeleteWord,
        eLastMacroBackSpaceChar,
        eLastMacroBackSpaceWord
    } LastMacro;

// Structure for storing font name and character set for use with
// font combo box for selecting font.
typedef struct
{
    BSTR    szFontName;
    BYTE    bCharSet;
}    FontData;

/////////////////////////////////////////////////////////////////////////////
// CBscEditorDocument
// Basically a list of the interfaces implemented by this class. Note that
// some of the interfaces are implemented by only one of the editor versions.
class ATL_NO_VTABLE CBscEditorDocument : 
#ifdef INPLACE
    public CComCoClass<CBscEditorDocument, &GUID_BscEditorFactory>,
    public CComControl<CBscEditorDocument>,
    public IOleObjectImpl<CBscEditorDocument>,
    public IOleInPlaceActiveObjectImpl<CBscEditorDocument>,
    public IOleInPlaceObjectWindowlessImpl<CBscEditorDocument>,
#else
    public IVsWindowPane,
#endif
    public IOleCommandTarget,
    public CComObjectRootEx<CComSingleThreadModel>,
    //Text/File Editor interfaces
    public IVsPersistDocData,
    public IVsDocDataFileChangeControl,
    public IPersistFileFormat,
    public IVsFileChangeEvents,
    //View interfaces
#ifdef INPLACE
    public IOleInPlaceComponent,
#endif
    public ISelectionContainer,
    public IVsToolboxUser,
    public IVsStatusbarUser,
    // Support IDispatch
    public IDispatchImpl<IBscEditor, &IID_IBscEditor, &LIBID_BscEdtLib>,
    // Support extensibility
    public IVsExtensibleObject,
    // Support IVsFindTarget interface
    public IVsFindTarget,
    public IVsFileBackup

{
public:

    // Constructor
    CBscEditorDocument()
    {
#ifdef INPLACE
        m_bWindowOnly = true;        // CComControl class member
#endif
        m_fZombie = false;
        m_pCVsPkg = NULL;
        m_vscookieFileChangeConnection = VSCOOKIE_NIL;
        m_WinSize.cx = 50;
        m_WinSize.cy = 50;
        m_hwnd = NULL;
        m_hwndRTF = NULL;
        m_srpTrackSelection = NULL;
        m_srpSiteSP = NULL;
        m_pfWndProc = NULL;
        m_fFileChangedTimerSet = false;
        m_fFileReloaded = false;
        m_cIgnoreFileChangeLevel = 0;
        m_fMacroRecording = false;
        m_pUnkFindState = NULL;
        m_pFonts = NULL;
        m_cFontNames = 0;
        m_dwFontNameIndex = 0;
        m_bBackupObsolete = TRUE;

        ResetState();

        ResetMacroState();

    }

    // Desctructor
    ~CBscEditorDocument()
    {
        SetFileName(NULL);        // Free the file name BSTR

        // Release the Find/Replace IUnknown if appropriate
        if (m_pUnkFindState)
            m_pUnkFindState->Release();

        // Delete the array of font names (which is used to
        // fill the font name drop-down menu)
        if (m_pFonts)
            DeleteFontNameArray();
    }

// The following macro prevents the object being deleted during
// during CComObjectRootEx::FinalConstruct if reference count
// is incremented and then decremented to zero.
DECLARE_PROTECT_FINAL_CONSTRUCT()

// The COM map is the mechanism that exposes interfaces on an object to
// a client through QueryInterface.
BEGIN_COM_MAP(CBscEditorDocument)
#ifdef INPLACE
    COM_INTERFACE_ENTRY(IOleObject)
    COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
    COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
    COM_INTERFACE_ENTRY(IOleInPlaceObject)
    COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
    COM_INTERFACE_ENTRY(IOleInPlaceComponent)
#else
    COM_INTERFACE_ENTRY(IVsWindowPane)    
#endif
    COM_INTERFACE_ENTRY(ISelectionContainer)
    COM_INTERFACE_ENTRY(IVsToolboxUser)
    COM_INTERFACE_ENTRY(IPersist)
    COM_INTERFACE_ENTRY(IOleCommandTarget)
    COM_INTERFACE_ENTRY(IVsPersistDocData)
    COM_INTERFACE_ENTRY(IPersistFileFormat)
    COM_INTERFACE_ENTRY(IVsDocDataFileChangeControl)
    COM_INTERFACE_ENTRY(IVsStatusbarUser)
    COM_INTERFACE_ENTRY(IVsFileChangeEvents)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IBscEditor)
    COM_INTERFACE_ENTRY(IVsExtensibleObject)
    COM_INTERFACE_ENTRY(IVsFindTarget)
    COM_INTERFACE_ENTRY(IVsFileBackup)
END_COM_MAP()

#ifdef INPLACE
// The default message map. CWindowImpl::WindowProc uses the default
// message map to process messages sent to the window. The message map
// directs messages either to the appropriate handler function or to
// another message map.
BEGIN_MSG_MAP(CBscEditorDocument)
    CHAIN_MSG_MAP(CComControl<CBscEditorDocument>)
    MESSAGE_HANDLER(WM_SIZE, OnSize)
    MESSAGE_HANDLER(WM_COMMAND, OnCommand)
    MESSAGE_HANDLER(WM_NOTIFY, OnNotify)
    MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
    MESSAGE_HANDLER(WM_PARENTNOTIFY, OnParentNotify)
    DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()


    //IOleObject::Close override
    STDMETHOD(Close)(DWORD dwSaveOption);

    // IOleInPlaceActiveObject::TranslateAccelerator override
    STDMETHOD(TranslateAccelerator)(LPMSG lpmsg);

    //IOleObject::SetClientSite override
    STDMETHOD(SetClientSite)(IOleClientSite* pClientSite);

    //CComControlBase::InPlaceActivate Override
    HRESULT InPlaceActivate(LONG iVerb, const RECT* /*prcPosRect*/);

    //CComControlBase::IOleInPlaceObject_UIDeactivate Override
    HRESULT IOleInPlaceObject_UIDeactivate(void);
    
public:
    // IOleInPlaceComponent methods
    STDMETHOD(UseComponentUIManager)(
                    /* [in] */ DWORD dwCompRole, 
                    /* [in] */ DWORD *pgrfCompFlags,
                    /* [in] */ IOleComponentUIManager *pCompUIMgr, 
                    /* [in] */ IOleInPlaceComponentSite *pIPCompSite );

    STDMETHOD(OnWindowActivate)( 
                    /* [in] */ DWORD dwWindowType,
                    /* [in] */ BOOL fActivate)
    {
        ATLTRACE(_T("IOleInPlaceComponent::OnWindowActivate\n"));
        return S_OK;
    }

    STDMETHOD_(void,OnEnterState)( 
                    /* [in] */ DWORD dwStateId, 
                    /* [in] */ BOOL fEnter)
    {
        ATLTRACE(_T("IOleInPlaceComponent::OnEnterState\n"));
    }

    STDMETHOD_(BOOL,FDoIdle)(
                    /* [in] */ DWORD grfidlef)
    {
        ATLTRACE(_T("IOleInPlaceComponentImpl::FDoIdle\n"));
        return TRUE;
    }

    STDMETHOD_(BOOL,FQueryClose)(
                    /* [in] */ BOOL fPromptUser)
    {
        ATLTRACE(_T("IOleInPlaceComponentImpl::FQueryClose\n"));
        return TRUE;
    }

    STDMETHOD(TranslateCntrAccelerator)(
                    /* [in] */ MSG *pMsg)
    {
        ATLTRACE(_T("IOleInPlaceComponentImpl::TranslateAccelerator\n"));
        return S_FALSE;
    }

    STDMETHOD(GetCntrContextMenu)( 
                    /* [in] */ DWORD dwRoleActiveObj,
                    /* [in] */ REFCLSID rclsidActiveObj,
                    /* [in] */ LONG nMenuIdActiveObj, 
                    /* [in] */ POINTS &pos, 
                    /* [out] */ CLSID *pclsidCntr,
                    /* [out] */ OLEMENUID *menuid, 
                    /* [out] */ DWORD *pgrf)
    {
        ATLTRACE(_T("IOleInPlaceComponent::GetCntrContextMenu\n"));
        return S_OK;
    }

    STDMETHOD(GetCntrHelp)( 
                    /* [in][out] */ DWORD *pdwRole, 
                    /* [in][out] */ CLSID *pclsid,
                    /* [in] */ POINT posMouse, 
                    /* [in] */ DWORD dwHelpCmd,
                    /* [in] */ LPOLESTR pszHelpFileIn, 
                    /* [out] */ LPOLESTR *ppszHelpFileOut,
                    /* [in] */ DWORD dwDataIn, 
                    /* [out] */ DWORD *pdwDataOut)
    {
        ATLTRACE(_T("IOleInPlaceComponent::GetCntrHelp\n"));
        return S_OK;
    }

    STDMETHOD(GetCntrMessage)( 
                    /* [in][out] */ DWORD *pdwRole, 
                    /* [in][out] */ CLSID *pclsid,
                    /* [in] */ LPOLESTR pszTitleIn, 
                    /* [in] */ LPOLESTR pszTextIn,
                    /* [in] */ LPOLESTR pszHelpFileIn,
                    /* [out] */ LPOLESTR *ppszTitleOut, 
                    /* [out] */ LPOLESTR *ppszTextOut,
                    /* [out] */ LPOLESTR *ppszHelpFileOut,
                    /* [in][out] */ DWORD *pdwHelpContextID,
                    /* [in][out] */ OLEMSGBUTTON *pmsgbtn, 
                    /* [in][out] */ OLEMSGDEFBUTTON *pmsgdefbtn,
                    /* [in][out] */ OLEMSGICON *pmsgicon, 
                    /* [in][out] */ BOOL *pfSysAlert)
    {
        ATLTRACE(_T("IOleInPlaceComponent::GetCntrHelp\n"));
        return S_OK;
    }



    // Message Handlers
    LRESULT OnSize(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnCommand(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnSetFocus(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    LRESULT OnParentNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
#else
public:

    // IVsWindowPane methods:
    STDMETHODIMP SetSite(
                    /*[in] */ IServiceProvider *pSP);
    STDMETHODIMP CreatePaneWindow(
                    /*[in] */ HWND hwndParent,
                    /*[in] */ int x,
                    /*[in] */ int y,
                    /*[in] */ int cx,
                    /*[in] */ int cy,
                    /*[out]*/ HWND *hwnd);
    STDMETHODIMP GetDefaultSize(
                    /*[out]*/ SIZE *psize);
    STDMETHODIMP ClosePane( void);
    STDMETHODIMP LoadViewState(
                    /*[in] */ IStream *pstream);
    STDMETHODIMP SaveViewState(
                    /*[in] */ IStream *pstream);
    STDMETHODIMP TranslateAccelerator(
                              LPMSG lpmsg);

    // Wndproc for the parent window
    static LRESULT CALLBACK WndProcSTATIC(HWND hwnd, UINT wm, WPARAM wParam, LPARAM lParam);
#endif

    //ISelectionContainer methods
    STDMETHOD(CountObjects)( 
                    /*[in] */ DWORD dwFlags,
                    /*[out]*/ ULONG * pc);
    STDMETHOD(GetObjects)(  
                    /*[in] */ DWORD dwFlags,
                    /*[in] */ ULONG cObjects,
                    /*[out]*/ IUnknown **apUnkObjects);
    STDMETHOD(SelectObjects)(  
                    /*[in] */ ULONG cSelect,
                    /*[out]*/ IUnknown **apUnkSelect,
                    /*[in] */ DWORD dwFlags);


    // Initialisation method called from IVsEditorFactory CreateEditorInstance method
    HRESULT HrInit(CVsPackage *pCVsPkg);

    //IVsToolboxUser
    STDMETHOD(IsSupported)(
                    /*[in] */ IDataObject* pDO);
    STDMETHOD(ItemPicked)(
                    /*[in] */ IDataObject* pDO);

    // IOleCommandTarget methods:
    STDMETHODIMP QueryStatus(   
                    /*[in] */ const GUID *pguidCmdGroup,
                    /*[in] */ ULONG cCmds,
                    /*[out]*/ OLECMD prgCmds[],
                    /*[out]*/ OLECMDTEXT *pCmdText);
    STDMETHODIMP Exec(    
                    /*[in] */ const GUID *pguidCmdGroup,
                    /*[in] */ DWORD nCmdID,
                    /*[in] */ DWORD nCmdexecopt,
                    /*[in] */ VARIANT *pvaIn,
                    /*[out]*/ VARIANT *pvaOut);

    // IBscEditor - this is the object model exposed by the editor in order to
    // facilitate macro recording. Most of the methods are merely wrappers for
    // ITextSelection and ITextRange interface methods.
    STDMETHOD(get_DTE)(
                    /* [out] */ _DTE** ppDTE);
    STDMETHOD(get_Parent)(
                    /* [out] */ _DTE** ppDTE);
    STDMETHOD(get_DefaultTabStop)(
                    /* [out] */ float* pdVal);
    STDMETHOD(put_DefaultTabStop)(
                    /* [in] */ float dVal);
    STDMETHOD(get_Range)(
                    /* [out] */ ITextRange** ppRange);
    STDMETHOD(get_Selection)(
                    /* [out] */ ITextSelection** ppSelection);
    STDMETHOD(get_Flags)(
                    /* [out] */ long* plFlags);
    STDMETHOD(put_Flags)(
                    /* [in] */ long lFlags);
    STDMETHOD(FindText)(
                    /* [in] */ BSTR pStr);
    STDMETHOD(SetText)(
                    /* [in] */ BSTR pStr);
    STDMETHOD(TypeText)(
                    /* [in] */ BSTR pStr);
    STDMETHOD(Cut)(void);
    STDMETHOD(Copy)(void);
    STDMETHOD(Paste)(void);
    STDMETHOD(Delete)(
                    /* [in] */ long lUnit,
                    /* [in] */ long cUnit);
    STDMETHOD(MoveUp)(
                    /* [in] */ long lUnit,
                    /* [in] */ long cUnit,
                    /* [in] */ long lExtend);
    STDMETHOD(MoveDown)(
                    /* [in] */ long lUnit,
                    /* [in] */ long cUnit,
                    /* [in] */ long lExtend);
    STDMETHOD(MoveLeft)(
                    /* [in] */ long lUnit,
                    /* [in] */ long cUnit,
                    /* [in] */ long lExtend);
    STDMETHOD(MoveRight)(
                    /* [in] */ long lUnit,
                    /* [in] */ long cUnit,
                    /* [in] */ long lExtend);
    STDMETHOD(EndKey)(
                    /* [in] */ long lUnit,
                    /* [in] */ long lExtend);
    STDMETHOD(HomeKey)(
                    /* [in] */ long lUnit,
                    /* [in] */ long lExtend);
                                        

    // IVsPersistDocData methods
    STDMETHODIMP GetGuidEditorType(
                    /* [out] */ CLSID *pClassID);       
    STDMETHODIMP IsDocDataDirty( 
                    /* [out] */ BOOL *pfDirty);   
    STDMETHODIMP SetUntitledDocPath( 
                    /* [in] */ LPCOLESTR pszDocDataPath);        
    STDMETHODIMP LoadDocData( 
                    /* [in] */ LPCOLESTR pszMkDocument);    
    STDMETHODIMP SaveDocData( 
                    /* [in] */ VSSAVEFLAGS dwSave,
                    /* [out] */ BSTR *pbstrMkDocumentNew,
                    /* [out] */ BOOL *pfSaveCanceled);       
    STDMETHODIMP Close (void);      
    STDMETHODIMP OnRegisterDocData( 
                    /* [in] */ VSCOOKIE docCookie,
                    /* [in] */ IVsHierarchy *pHierNew,
                    /* [in] */ VSITEMID itemidNew);       
    STDMETHODIMP RenameDocData( 
                    /* [in] */ VSRDTATTRIB grfAttribs,
                    /* [in] */ IVsHierarchy *pHierNew,
                    /* [in] */ VSITEMID itemidNew,
                    /* [in] */ LPCOLESTR pszMkDocumentNew);
    STDMETHODIMP IsDocDataReloadable( 
                    /* [out] */ BOOL *pfReloadable);
    STDMETHODIMP ReloadDocData( 
                    /* [in] */ VSRELOADDOCDATA grfFlags);
        

    // IVsDocDataFileChangeControl methods

    // NOTE: all good editors will implement IVsPersistDocData::ReloadDocData. This 
    // means that the editor also advises for file change events via
    // SVsFileChangeEx service to listen if the file changes outside of the environment
    // and then prompt to reload (see IVsFileChangeEvents::FilesChanged implementation).
    // All editors that properly implement this reload feature need to implement
    // IVsDocDataFileChangeControl interface to allow parties like SCC to tell the
    // editor to ignore file changes at times (e.g. when SCC is getting the latest
    // version of the file. SCC will directly call IVsPersistDocData::ReloadDocData
    // at the right time. it does not want the user to be prompted to reload the file.
    STDMETHODIMP IgnoreFileChanges(
                    /* [in] */ BOOL fIgnore);

    // IPersist methods (IPersistFileFormat derives from this)
    STDMETHODIMP GetClassID( 
                    /* [out] */ CLSID *pClassID);

    // IPersistFileFormat methods
    STDMETHODIMP IsDirty( 
                    /* [out] */ BOOL *pfIsDirty);
    STDMETHODIMP InitNew( 
                    /* [in] */ DWORD nFormatIndex);
    STDMETHODIMP Load( 
                    /* [in] */ LPCOLESTR pszFilename,
                    /* [in] */ DWORD grfMode,
                    /* [in] */ BOOL fReadOnly);
    STDMETHODIMP Save( 
                    /* [in] */ LPCOLESTR pszFilename,
                    /* [in] */ BOOL fRemember,
                    /* [in] */ DWORD nFormatIndex);
    STDMETHODIMP SaveCompleted( 
                    /* [in] */ LPCOLESTR pszFilename);
    STDMETHODIMP GetCurFile( 
                    /* [out] */ LPOLESTR *ppszFilename,
                    /* [out] */ DWORD *pnFormatIndex);
    STDMETHODIMP GetFormatList( 
                    /* [out] */ LPOLESTR *ppszFormatList);

                    
    // IVsStatusbarUser methods
    STDMETHODIMP SetInfo();    // Document that uses the statusbar was activated

    // IVsFileChangeEvents methods
    STDMETHODIMP FilesChanged(  
                    /* [in] */ DWORD cChanges,
                    /* [in] */ LPCOLESTR rglpstrFile[],
                    /* [in] */ VSFILECHANGEFLAGS rggrfChange[]);
    STDMETHODIMP DirectoryChanged(
                    /* [in] */ LPCOLESTR pszDirectory);

    //IVsExtensibleObject - enables the object to support macro recording
    STDMETHOD(GetAutomationObject)( 
                    /* [in] */ LPCOLESTR szPropName,
                    /* [out]*/ IDispatch** ppObject);

    // IVsFindTarget methods
    STDMETHOD   (GetCapabilities)( 
                    /* [out] */ BOOL * pfImage,
                    /* [out] */ DWORD * pgrfOptions);
    STDMETHOD   (GetProperty)( 
                    /* [in] */ VSFTPROPID propid,
                    /* [out]*/ VARIANT *pvar);
    STDMETHOD   (GetSearchImage)(
                    /* [in] */ DWORD grfOptions, 
                    /* [out]*/ IVsTextSpanSet ** pSpans,
                    /* [out]*/ IVsTextImage ** pTextImage);
    STDMETHOD    (Find)(    
                    /* [in] */ LPCOLESTR pszSearch,
                    /* [in] */ VSFINDOPTIONS grfOptions,
                    /* [in] */ BOOL fResetStartPoint,
                    /* [in] */ IVsFindHelper * pHelper,
                    /* [out]*/ VSFINDRESULT * pResult);
    STDMETHOD    (Replace)(  
                    /* [in] */ LPCOLESTR pszSearch,
                    /* [in] */ LPCOLESTR pszReplace,
                    /* [in] */ VSFINDOPTIONS grfOptions,
                    /* [in] */ BOOL fResetStartPoint,
                    /* [in] */ IVsFindHelper * pHelper,
                    /* [out]*/ BOOL * pbReplaced);
    STDMETHOD   (GetMatchRect)(
                    /* [out]*/ PRECT prc);
    STDMETHOD   (NavigateTo)(
                    /* [in] */ const TextSpan * pts);
    STDMETHOD   (GetCurrentSpan)(
                    /* [out]*/ TextSpan * pts);
    STDMETHOD   (SetFindState)(
                    /* [in] */ IUnknown * punk);
    STDMETHOD   (GetFindState)(
                    /* [out]*/ IUnknown **ppunk);
    STDMETHOD   (NotifyFindTarget)(
                    /* [in] */ VSFTNOTIFY notification);
    STDMETHOD   (MarkSpan)( 
                    /* [in] */ const TextSpan __RPC_FAR *pts);
    
    // other

    // Helper to set filename for file being edited
    HRESULT SetFileName(LPCWSTR szFileName);

    // File State functions 
    BOOL FStateGet(FileState eState) { return (m_eState & eState) ? TRUE : FALSE; }
    VOID ResetState()    { m_eState = eFileStateNone; }
    VOID SetState(FileState eState, BOOL fSet)
    { 
        // Every time the document has changed in any way the previous backup is obsolete.
        m_bBackupObsolete = TRUE;

        if (fSet)     
            m_eState |= eState;
        else
            m_eState &= (~eState);
    }

    VOID SetNew(BOOL fNew);
    VOID SetDirty(BOOL fDirty);
    VOID SetReadOnly(BOOL fUserReadOnly, BOOL fFileSystemReadOnly);
    BOOL FIsReadOnly()
    {
        return FStateGet(eFileStateFileSysReadOnly) || FStateGet(eFileStateUserReadOnly);
    }

    // Helper function to obtain the macro recording state.
    HRESULT GetRecordState()
    {
        CComVariant var;
        HRESULT     hr;
        if (SUCCEEDED(hr = m_srpShell->GetProperty(VSSPROPID_RecordState, &var)))
        {
            m_eRecordState = (static_cast<VSRECORDSTATE>(var.lVal));
        }
        else
        {
            // If this failed we switch macro recording off
            m_eRecordState = VSRECORDSTATE_OFF;
        }
        return hr;
    }

    // This function determines the current macro recording state and then connects
    // or releases the macro recording service accordingly.
    VOID EstablishRecordState();

    // These functions handle the type of the last command sent to the macro recorder.
    // Note it is only meaningful to obtain the last type when macro recording is
    // switched on.
    VOID ResetMacroState()    
    { 
        m_eMacroState = eLastMacroNone;
        m_cCommands = 0;
        ResetLeadByteFlag();
    }
    VOID SetMacroState(LastMacro eLastMacroState) { m_eMacroState = eLastMacroState; }
    LastMacro GetMacroState() { return m_eMacroState; }
    long GetMacroCommandCount() { return m_cCommands; }
    VOID IncrMacroCommandCount() { ++m_cCommands; }

    // These functions set, reset and read the flag used when converting multibyte
    // characters during macro recording.
    VOID SetLeadByteFlag() { m_fLeadReceived = true; }
    VOID ResetLeadByteFlag() { m_fLeadReceived = false; }
    BOOL LeadByteFlagIsSet() { return m_fLeadReceived; }

    // This function determines if the last line sent to the macro recorder was
    // sent from this object. Note it is not valid to call this function if
    // macro recording is switched off.
    BOOL ObjectIsLastMacroEmitter()
    {
        GUID    guid;                // GUID of last macro writer

        m_srpMacroRecorder->GetLastEmitterId(&guid);
        return IsEqualGUID(guid, m_guidMacroRecorder);
    }

    // This function outputs a line to the macro recorder in response to a
    // delete or backspace key.
    VOID RecordDelete(LastMacro eState, BOOL fNegate, LPCWSTR pszWordOrChar);

    // This function outputs a line to the macro recorder in response to an
    // Up, Down, Left or Right Arrow.
    VOID RecordMove(LastMacro eState, LPCWSTR pszDir, LPCWSTR pszScope, LPCWSTR pszExtOrMove);

    // File persistence helpers
    HRESULT ReadData(HANDLE hFile, BOOL fInsert);
    HRESULT WriteData(HANDLE hFile);
    HRESULT ReadFromFile(LPCWSTR pszFilename, BOOL fInsert, BOOL *pfIsSysReadOnly);
    HRESULT WriteToFile(LPCWSTR pszFilename);

    // File Change notification helpers
    HRESULT EnsureFileChange();
    HRESULT SetFileChangeAdvise(LPCWSTR pszFileName, BOOL fStart);
    HRESULT SuspendFileChangeAdvise(LPCWSTR pszFileName, BOOL fSuspend);
    HRESULT FileLoadAdvise(BOOL fReload);

    // Selection helpers
    BOOL FEmptySelection();

    // Find Target helper to get selection string if it is only single line
    HRESULT GetInitialPattern(BSTR *pbstrSelection);

    // Find Target helper to set up the search parameters
    HRESULT SetSearchLimits(ITextRange *pSearchRange, VSFINDOPTIONS grfOptions, BOOL fResetStartPoint);

    // Find Target helper
    BOOL ResetRequired(long cFirst, BOOL fBackwards);

    // Find Target helper for comparing strings
    BOOL StringsAreSame(LPCOLESTR pszString1, LPCOLESTR pszString2, BOOL fCaseSensitive);

    // Function to obtain and set Character and paragraph properties.
    DWORD GetCharFormatState(DWORD dwEffect);
    VOID SetCharFormatState(DWORD dwEffect, long lState = tomToggle);
    DWORD GetParaFormatState(long lState);
    DWORD GetBulletState(void);
    VOID SetParaFormatState(long lState);
    VOID SetBulletState(void);

    //RTF Window Proc
    static LRESULT CALLBACK MyWndProc(HWND, UINT, WPARAM, LPARAM);

    // Helper function to obtain the ITextSelection flags
    long LGetSelFlags();

    // OleCommandTarget Helper functions for selecting font names and sizes.
    HRESULT FillFontNameArray(VARIANT *pvarOut);
    HRESULT FillFontSizeArray(VARIANT *pvarOut);
    HRESULT CreateFontNameArray();
    HRESULT GetFontName(VARIANT *pvarOut);
    HRESULT GetFontSize(VARIANT *pvarOut);
    HRESULT SetFontName(VARIANT *pvarNew);
    HRESULT SetFontSize(VARIANT *pvarNew);

    // Property get, set functions etc. to facilitate the handling of the
    // data member varaiables associated with the font names and sizes.
    DWORD GetFontNameIndex() { return m_dwFontNameIndex; }
    VOID IncrFontNameIndex() { ++m_dwFontNameIndex; }
    VOID DecrFontNameIndex() { if (m_dwFontNameIndex > 0) --m_dwFontNameIndex; }
    DWORD GetFontNameCount() { return m_cFontNames; }
    VOID IncrFontNameCount() { ++m_cFontNames; }
    VOID DecrFontNameCount() { if (m_cFontNames > 0) --m_cFontNames; }
    BSTR GetFontNameEntry(DWORD dwIndex) { return m_pFonts[dwIndex].szFontName; }    
    VOID SetFontNameEntry(BSTR bstrFontName)    
    { 
        m_pFonts[GetFontNameIndex()].szFontName = bstrFontName;
    }
    VOID SetFontCharSetEntry(BYTE bCharSet)    
    { 
        m_pFonts[GetFontNameIndex()].bCharSet = bCharSet;
    }
    VOID DeleteFontNameArray()    
    {
        if (m_pFonts)
        {
            // Delete the individual BSTRs and then delete the array itself
            for (long i = 0; i < m_cFontNames; i++)
                ::SysFreeString(m_pFonts[i].szFontName);
            delete [] m_pFonts;
            m_pFonts = NULL;
        }
    }

    // Helper function for query status for command cmdidPasteNextTBXCBItem
    BOOL        CanCycleClipboard(void);
    HRESULT     PasteClipboardObject(void);

    // Helper function to checkout file if necessary.
    BOOL FileCheckedOut(BOOL *fDiscardInput);

    // Helper functions for checking for the validity of filenames
    HRESULT CheckFileName(LPCTSTR pszFileName);
    HRESULT CheckFileType(LPCTSTR pszFilePath, BOOL fWhenExistOnly = FALSE);
    BOOL FixFilename(CString& strName);
    BOOL ContainsInvalidFileChars(LPCTSTR pszName);
    BOOL HaveTrailingTChar(const CString& string, const TCHAR ch);


protected:
#ifdef INPLACE

    // The function obtains the correct m_spInPlaceSite pointer and 
    // sets m_bNegotiatedWnd, m_bWndLess, m_bWasOnceWindowless, and m_bInPlaceSiteEx
    // Note that in our case m_spInPlaceSite is a pointer to IOleInPlaceSite
    HRESULT EnsureInPlaceSite(void);

    // The function creates (if necessary) the control window using CreateControlWindow
    HRESULT EnsureControlWindow(void);

    // Creates RTF window etc.
    HRESULT CreateRTFWindow(void);

#endif

    // Keyboard/mouse event handler
    long LHandleKeyboardMouseEvent(MSGFILTER *pMsgFilter);

    // Helper function to set the ITextSelection flags
    void SetSelFlags(long grfFlags);

    // Calls IVSUIShell method to tell the environment to update the state of 
    // the command bars (menus and toolbars).
    void VUpdateCmds();

    // Status bar management functions
    void StatusBar_UpdatePos();
    void StatusBar_UpdateInsMode();
    void StatusBar_UpdateSelMode();

    // Member functions used to interface with the shell macro recording service.
    // Note that although macro recording may fail we do not return any errors.
    void RecordKeyStroke(UINT msg, WPARAM wParam, LPARAM lParam);
    void RecordCommand(const GUID *pguidCmdGroup, DWORD nCmdID);

    HRESULT LoadRichEdit();

    //////////////////////////////////////////////////////////////////////////////
    // Data members
    //////////////////////////////////////////////////////////////////////////////


    // Component UI Manager
    CComPtr<IOleComponentUIManager>                 m_ccpUIMgr;

    // In-place component UI Manager
    CComPtr<IOleInPlaceComponentUIManager>          m_ccpIPUIMgr;

    // In-place component site
    CComPtr<IOleInPlaceComponentSite>               m_ccpIPCompSite;

    // ??????????
    DWORD                                           m_dwRole;

    // This is set to FALSE when the class is created and then set to
    // TRUE when Close (in-place activation) or ClosePane(IVsWindowPane)
    // is called.
    BOOL                                            m_fZombie;

    // Pointer to IVsPackage
    CVsPackage*                                     m_pCVsPkg;

    // Various interface pointers
    CComPtr<IServiceProvider>                       m_srpSiteSP;
    CComPtr<IVsTrackSelectionEx>                    m_srpTrackSelection;
    CComPtr<ITextDocument>                          m_srpTextDocObj;
    CComPtr<ITextRange>                             m_srpTextRange;
    CComPtr<ITextSelection>                         m_srpTextSelection;
    CComPtr<IVsRunningDocumentTable>                m_srpRDT;

    // Window size
    SIZE                                            m_WinSize;

    // Parent window handle
    HWND                                            m_hwnd;

    // RTF window handle
    HWND                                            m_hwndRTF;

    // Window procedure pointer
    WNDPROC                                         m_pfWndProc;

    // File name 
    CComBSTR                                        m_bsFileName;

    // Current file state (bit mask) - see enum FileState
    DWORD                                           m_eState;

    // FileChange Notification stuff
    CComPtr<IVsFileChangeEx>                        m_srpVsFileChangeEx;
    VSCOOKIE                                        m_vscookieFileChangeConnection;
    BOOL                                            m_fFileChangedTimerSet;
    int                                             m_cIgnoreFileChangeLevel;
    BOOL                                            m_fFileReloaded;

    // Current macro recording state
    VSRECORDSTATE                                   m_eRecordState;

    // This flag indicates whether or not we are actually recording.
    // It's used to determine whether we need to obtain or
    // release the recording service when the recording 
    // state changes.
    BOOL                                            m_fMacroRecording;

    // Macro recording service smart pointer
    CComPtr<IVsMacroRecorder>                       m_srpMacroRecorder;

    // GUID for use with the macro recorder
    GUID                                            m_guidMacroRecorder;

    // Last macro commend type recorded (only valid when
    // macro recording is switched on.
    LastMacro                                       m_eMacroState;

    // Flag used when macro recording to indicate that we have received the
    // lead byte of a multibyte character and are awaiting the trailing byte.
    BOOL                                            m_fLeadReceived;

    // BSTR to which to append characters when outputting
    // text to the macro recorder.
    CComBSTR                                        m_bstrText;

    // Buffer to hold a pair of characters from a multibyte character set
    // which need to be converted to a wide character.
    char                                            m_szMultiByteString[2];

    // Count of certain consecutive commands emitted to the macro recorder
    long                                            m_cCommands;

    //Shell smart pointer
    CComPtr<IVsShell>                               m_srpShell;

    // Statusbar
    CComPtr<IVsStatusbar>                           m_srpVsStatusBar;

    // QueryEditQuerySave interface
    CComPtr<IVsQueryEditQuerySave2>                 m_srpVsQueryEditQuerySave2;

    // Toolbox clipboard cycler
    CComPtr<IVsToolboxClipboardCycler>              m_srpVsToolboxClipboardCycler;

    // IUnknown for use with IVsFindTarget interface
    IUnknown*                                       m_pUnkFindState;

    // IVsFindTarget Data 
    
    // Permitted search limits. This is either the selection
    // limits (selection search) or the portion of the document
    // forward or backward from the initial start position. Note
    // these fields are updated after wrapping.
    long                                        m_cPermittedStart;
    long                                        m_cPermittedEnd;

    // The following fields are used to update those above after
    // search wrapping is detected.
    long                                        m_cWrapStart;
    long                                        m_cWrapEnd;

    // The search character start and end positions for the next "FindText"
    long                                        m_cSearchStart;
    long                                        m_cSearchEnd;

    // The search result to return if the next "FindText" does not find a match.
    VSFINDRESULT                                m_SearchFailResult;

    // The last status returned from the find.
    VSFINDRESULT                                m_LastResult;

    // Whether the last search was backwards
    BOOL                                        m_fBackwards;

    // Array of structures containing font name (BSTR) and
    // character set (BYTE) for all the fonts displayed in
    // the drop down menu below the font name combo box in
    // the character formatting tool bar.
    FontData*                                    m_pFonts;

    // Count of font names supplied in drop down menu with font combo box.
    long                                        m_cFontNames;

    // Index of next font name to be added to m_pFonts.
    DWORD                                        m_dwFontNameIndex;
    
    // Visual Studio File Recovery backs up all objects in the Running 
    // Document Table that support IVsFileBackup and have unsaved changes and an obsolete backup.
    
    BOOL m_bBackupObsolete;

    // IVsFileBackup methods

    STDMETHOD(BackupFile)(LPCOLESTR pszBackup);
    STDMETHOD(IsBackupFileObsolete)(BOOL* pbObsolete);
};
