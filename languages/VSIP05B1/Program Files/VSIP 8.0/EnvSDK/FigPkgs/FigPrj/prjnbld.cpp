
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//--------------------------------------------------------------------------
// prjnbld.cpp
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "PrjInc.h"

const TCHAR g_szBuildProjName[] = _T("BuildProject");
const TCHAR g_szBuildProjExt[] = _T(".csproj");
const TCHAR g_szMainForm[] = _T("MainForm.cs");
const TCHAR g_szFigureDrawingObject[] = _T("FigureDrawingObject.cs");


//==========================================================================
//                                                construct, init , destruct

//---------------------------------------------------------------------------
// creates a proxy to the cs Build project hierarchy
//---------------------------------------------------------------------------
HRESULT CBuildProjNode::CreateInstance(LPCTSTR pszFullPath, CBuildProjNode **pNode)
{
    ExpectedPtrRet(pNode);
    ExpectedPtrRet(pszFullPath);

    HRESULT hr;
    CComObject<CBuildProjNode> *pObj = NULL;
    hr = CComObject<CBuildProjNode>::CreateInstance(&pObj);
    if (SUCCEEDED(hr))
    {
        *pNode = pObj;
        pObj->SetFullPath(pszFullPath);
        pObj->AddRef();
    }
    return hr;
}


//---------------------------------------------------------------------------
// Constructor
//---------------------------------------------------------------------------
CBuildProjNode::CBuildProjNode(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CBuildProjNode::CBuildProjNode this = 0x%x\n"), this);

    m_guidProjectID = GUID_NULL;
    m_dwDocCookie = NULL;
    m_fInited = FALSE;
    m_fClosed = FALSE;
    m_vscookieIVsFileChangeEvents = VSCOOKIE_NIL;
    m_fIgnoreFileChanges = FALSE;
    m_hIcon = NULL; 
}


void CBuildProjNode::SetFullPath(LPCTSTR pszFullPath) 
{ 
    //Fire an event to extensibility if the name is changed
    if (m_fInited)
    {
        CAutomationEvents::FireProjectItemsEvent(
            this, 
            CAutomationEvents::ProjectItemsEventsDispIDs::ItemRenamed,
            GetFullPath());
    }

    m_strFullPath = pszFullPath;
    
    // compute caption to be used for VSHPROIPD_Caption value
    // we use filename without path or extension as the item caption
    CString strCaption;
    strCaption = ::LUtilProjNameFromPath(pszFullPath);
    SetName(strCaption);
}


//---------------------------------------------------------------------------
// Destructor
//---------------------------------------------------------------------------
CBuildProjNode::~CBuildProjNode(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CBuildProjNode::~CBuildProjNode this = 0x%x\n"), this);

    HRESULT hr = S_OK;
    ASSERT(m_fClosed);

    m_srpProjectItem.Release();

    ClearIconHandle();
}


STDMETHODIMP CBuildProjNode::Init(
    /* [in] */ LPCTSTR pszGuid)
{
    ExpectedPtrRet(pszGuid);
    ExpectedExprRet(lstrlen(pszGuid) > 0);

    CStringW wstrGuid = pszGuid;
    if (wstrGuid.IsEmpty())
        return E_OUTOFMEMORY;

    HRESULT hr = CLSIDFromString(wstrGuid.LockBuffer(), &m_guidProjectID);
    wstrGuid.ReleaseBuffer();
    IfFailRet(hr);

    return InitNestedHierarchy();
}


//---------------------------------------------------------------------------
// overide: CHierNestedContainer
//---------------------------------------------------------------------------
HRESULT CBuildProjNode::InitNestedHierarchy(void)
{
    
    HRESULT hr = E_FAIL;
    USES_CONVERSION;
    
    if (m_strFullPath.IsEmpty())
        return E_UNEXPECTED;
    CStringW strwFileName = ::LUtilStripPath(m_strFullPath);
    if (strwFileName.IsEmpty())
        return E_UNEXPECTED;
    CStringW strwFolderName = ::LUtilStripName(m_strFullPath);
    if (strwFolderName.IsEmpty())
        return E_UNEXPECTED;
    IVsSolution* pSolution = _VxModule.GetIVsSolution();
    if (pSolution == NULL)
        return E_UNEXPECTED;
    
    HCURSOR hcurOld = SetCursor(LoadCursor(NULL, IDC_WAIT));

    // If we are creating a new project, create the nested project out of thin air
    if ( !m_srpNestedHierarchy )
    {
        // We use CPF_CLONEFILE to copy the new project from an empty template
        // We use CPG_SILENT to create the nested project without asking the user  
        long grfCreateFlags = CPF_SILENT | CPF_OPENFILE;
        DWORD dwReserved = 0;
        GUID guidPrjFac = GUID_NULL;
        CComPtr<IVsProjectFactory>    srpVsPF = NULL;
        CComPtr<IUnknown>            srpUnknown = NULL;
        BOOL                        bCanceled = FALSE;
        CComVariant                    ccvt;
        IfFailGo( pSolution->GetProjectTypeGuid( dwReserved, strwFileName, &guidPrjFac ) );
        IfFailGo( pSolution->GetProjectFactory(0, &guidPrjFac, strwFileName, &srpVsPF ) );
        IfFailGo( srpVsPF->CreateProject(T2COLE(m_strFullPath), strwFolderName, NULL, grfCreateFlags, IID_IUnknown, (void **)&srpUnknown, &bCanceled) );

        if( !srpUnknown || bCanceled )
        {
            hr = E_ABORT;
            goto Error;
        }
        
        IfFailGo( srpUnknown->QueryInterface(IID_IVsHierarchy, (void **)&m_srpNestedHierarchy) );
        ASSERT(m_srpNestedHierarchy!= NULL);
        IfFalseGo( m_srpNestedHierarchy != NULL, E_FAIL);

        CComPtr<IVsHierarchy> srpParentHierarchy = GetCVsHierarchy()->GetIVsHierarchy(); 
        ASSERT(srpParentHierarchy != NULL);

        ccvt = static_cast<IVsHierarchy*>( srpParentHierarchy );
        IfFailGo( m_srpNestedHierarchy->SetProperty(VSITEMID_ROOT, VSHPROPID_ParentHierarchy, ccvt) );
        
        ccvt = static_cast<int>( GetVsItemID() ); 
        IfFailGo( m_srpNestedHierarchy->SetProperty(VSITEMID_ROOT, VSHPROPID_ParentHierarchyItemid, ccvt) );

    }   

    hr = LockRDTEntry();
    IfFailGo(hr);

    // listen to the project file changes
    hr = AdviseFileChange();
    ASSERT(SUCCEEDED(hr));
    hr = S_OK;// we do not fail if we cannot listen

Error:
    SetCursor(hcurOld);

    if (SUCCEEDED(hr))
        m_fInited = TRUE;

    return hr;
}


// add the nested hierarchy to the solution
STDMETHODIMP CBuildProjNode::AddNestedHierarchy()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // Add the new nested hierarchy to the solution
    HRESULT hr = S_OK;

    IVsSolution* pIVsSolution = _VxModule.GetIVsSolution();
    ExpectedExprRet(pIVsSolution != NULL);
    ExpectedExprRet(m_srpNestedHierarchy != NULL);

    hr = pIVsSolution->AddVirtualProjectEx(m_srpNestedHierarchy, 0, m_guidProjectID);


    // This forces the treeview to register as an event listener on the new hierarchy.
    // Without it the treeview is not updated when the hierarchy's icons or name changes.
    ExtExpand(EXPF_SelectItem);

    return hr;
}


//---------------------------------------------------------------------------
// Init's the cmd target of our nested hierarchy
//---------------------------------------------------------------------------
HRESULT CBuildProjNode::InitNestedCmdTarget(void)
{
    HRESULT hr = S_OK;
    if (!m_srpNestedOleCmdTrg)
    {
        hr = m_srpNestedHierarchy->QueryInterface(IID_IOleCommandTarget, (void **)&m_srpNestedOleCmdTrg);
    }
    return hr;
}


// Close the nested hierarchy
STDMETHODIMP CBuildProjNode::Close(
    /* [in] */ BOOL fAskToSaveIfDirty)
{
    ExpectedExprRet(!m_fClosed); // already closed

    HRESULT  hr        = S_OK;

    VSITEMID itemidDoc = VSITEMID_NIL;
    CComPtr<IVsHierarchy> pRDTHier;
    GetRDTDocumentInfo(m_strFullPath, &pRDTHier, &itemidDoc );

    // if the RDT has already been released by the solution, release our hold on it
    if((VSITEMID_NIL == itemidDoc) || !fAskToSaveIfDirty)
        UnlockRDTEntry();

    hr = _VxModule.GetIVsSolution()->RemoveVirtualProject(m_srpNestedHierarchy, 0);
    _IfFailRet(hr);

    // now we are closing ...

    if (m_srpProjectItem != NULL)
        static_cast<CAOProjectItemNested*>((ProjectItem*)m_srpProjectItem)->Close();

    // if we haven't already release the RDT cookie, do so now
    if( VSITEMID_NIL != itemidDoc )
    {
        hr = UnlockRDTEntry();
        ASSERT(SUCCEEDED(hr));
    }
    ASSERT(m_dwDocCookie == NULL);

    hr = UnadviseFileChange();
    ASSERT(SUCCEEDED(hr));

    ClearIconHandle();

    m_srpNestedHierarchy.Release();
    m_srpNestedOleCmdTrg.Release();
    m_srpIVsFileChangeEx.Release();
    m_srpUserCtx.Release();
    m_fIgnoreFileChanges = FALSE;
    m_fClosed = TRUE;
 
    return S_OK;
}


// lock this nested hierachy in the RDT.
HRESULT CBuildProjNode::LockRDTEntry()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    if (m_dwDocCookie)
        return S_FALSE;

    CComPtr<IVsHierarchy> srpParentHierarchy = GetCVsHierarchy()->GetIVsHierarchy();
    ExpectedExprRet(srpParentHierarchy != NULL);

    //register the nested project with the running document table
    IVsRunningDocumentTable* pRDT = _VxModule.GetIVsRunningDocumentTable();
    ExpectedExprRet(pRDT != NULL);

    HRESULT hr = S_OK;
    CComPtr<IVsHierarchy> pHierRegd;
    VSITEMID              cItem;
    CComPtr<IUnknown>     pUnk;
    USES_CONVERSION;

    VSRDTFLAGS dwRDTLockType = RDT_EditLock | RDT_VirtualDocument | RDT_ProjSlnDocument;
    hr = pRDT->FindAndLockDocument( 
       /* VSRDTFLAGS      */ dwRDTLockType, 
       /* LPCOLESTR       */ T2COLE(m_strFullPath),
       /* IVsHierarchy**  */ &pHierRegd, 
       /* VSITEMID        */ &cItem, 
       /* IUnknown**      */ &pUnk, 
       /* VSDOCCOOKIE*    */ &m_dwDocCookie);

    if ( (hr == S_OK) && m_dwDocCookie)
        return S_OK;

    return pRDT->RegisterAndLockDocument( 

        /* VSRDTFLAGS     */ dwRDTLockType,
        /* LPCOLESTR      */ T2COLE(m_strFullPath),
        /* IVsHierarchy*  */ srpParentHierarchy,
        /* VSITEMID       */ GetVsItemID(),
        /* IUnknown*      */ m_srpNestedHierarchy,
        /* VSDOCCOOKIE*   */ &m_dwDocCookie);
}


// unlock this nested hierachy from the RDT.
HRESULT CBuildProjNode::UnlockRDTEntry()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    if(!m_dwDocCookie)
        return S_FALSE;

    IVsRunningDocumentTable* pRDT = NULL;
    pRDT = _VxModule.GetIVsRunningDocumentTable();
    ExpectedExprRet(pRDT != NULL);

    HRESULT hr = pRDT->UnlockDocument(RDT_EditLock, m_dwDocCookie);
    IfFailRet(hr);
    m_dwDocCookie = 0;
    return S_OK;
}


HRESULT CBuildProjNode::AdviseFileChange()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // check if we did it already
    if (m_vscookieIVsFileChangeEvents != VSCOOKIE_NIL)
        return S_FALSE;

    HRESULT hr =S_OK;
    USES_CONVERSION;

    if (m_srpIVsFileChangeEx == NULL)
    {
        hr = _VxModule.QueryService(SID_SVsFileChangeEx, IID_IVsFileChangeEx, (void **)&m_srpIVsFileChangeEx);
        IfFailRet(hr)
    }
    ExpectedExprRet(m_srpIVsFileChangeEx != NULL);

    CComPtr<IVsHierarchy> srpParentHierarchy = GetCVsHierarchy()->GetIVsHierarchy(); 
    ExpectedExprRet(srpParentHierarchy != NULL);

    CComPtr<IVsFileChangeEvents> srpIVsFileChangeEvents;
    hr = srpParentHierarchy->QueryInterface(IID_IVsFileChangeEvents, (void**)&srpIVsFileChangeEvents);
    IfFailRet(hr)
    ExpectedExprRet(srpIVsFileChangeEvents != NULL);

    hr = m_srpIVsFileChangeEx->AdviseFileChange(
        /* [in] LPCOLESTR pszMkDocument     */ T2COLE(GetFullPath()),
        /* [in] VSFILECHANGEFLAGS grfFilter */ VSFILECHG_Time, 
        /* [in] IVsFileChangeEvents *pFCE   */ srpIVsFileChangeEvents, 
        /* [out] VSCOOKIE *pvsCookie        */ &m_vscookieIVsFileChangeEvents);
    ASSERT(SUCCEEDED(hr) && (m_vscookieIVsFileChangeEvents != VSCOOKIE_NIL) );

    return hr;
}


HRESULT CBuildProjNode::UnadviseFileChange()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    // check if we did it already
    if (m_vscookieIVsFileChangeEvents == VSCOOKIE_NIL)
        return S_FALSE;

    HRESULT hr = S_OK;

    if (m_srpIVsFileChangeEx == NULL)
        hr = _VxModule.QueryService(SID_SVsFileChangeEx, IID_IVsFileChangeEx, (void **)&m_srpIVsFileChangeEx);

    if (SUCCEEDED(hr) && m_srpIVsFileChangeEx)
    {
        hr = m_srpIVsFileChangeEx->UnadviseFileChange(
            /* [in] VSCOOKIE vsCookie */ m_vscookieIVsFileChangeEvents);
    }

    ASSERT(SUCCEEDED(hr));
    m_vscookieIVsFileChangeEvents = VSCOOKIE_NIL;
    return S_OK;
}
//                                                construct, init , destruct
//==========================================================================



//---------------------------------------------------------------------------
// interface: IOleCommandTarget
// delegate to nested hierarchy root node (not the nested hierarchy)
//---------------------------------------------------------------------------
STDMETHODIMP CBuildProjNode::QueryStatus(
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [out][in][size_is] */ OLECMD prgCmds[  ],
            /* [unique][out][in] */ OLECMDTEXT *pCmdText)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ASSERT(NULL != pguidCmdGroup);  // error case should be handled earlier
    ASSERT(1 == cCmds);

    HRESULT hr = InitNestedCmdTarget();
    if (SUCCEEDED(hr))
    {
        hr = m_srpNestedOleCmdTrg->QueryStatus(pguidCmdGroup, cCmds, prgCmds, pCmdText);
    }
    return hr;
}

//---------------------------------------------------------------------------
// interface: IOleCommandTarget
// delegate to nested hierarchy root node (not the nested hierarchy)
//---------------------------------------------------------------------------
STDMETHODIMP CBuildProjNode::Exec(
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ DWORD nCmdID,
            /* [in] */ DWORD nCmdexecopt,
            /* [unique][in] */ VARIANT *pvaIn,
            /* [unique][out][in] */ VARIANT *pvaOut)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ASSERT(NULL != pguidCmdGroup);  // error case should be handled earlier

    HRESULT hr = InitNestedCmdTarget();
    if (SUCCEEDED(hr))
    {
        hr = m_srpNestedOleCmdTrg->Exec(pguidCmdGroup, nCmdID, nCmdexecopt, pvaIn, pvaOut);
    }
    return hr;
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
UINT CBuildProjNode::GetIconIndex(ICON_TYPE eType) const
{  
    if(eType == ICON_StateImage)
    {
        VARIANT   var;
        UINT      state = STATEICON_BLANK;

        VariantInit(&var);

        HRESULT hr = S_OK;
        if (! m_srpNestedHierarchy)
        {
            ASSERT(FALSE);
            goto Error;
        }
        hr = m_srpNestedHierarchy->GetProperty(VSITEMID_ROOT, VSHPROPID_StateIconIndex, &var);
        if (FAILED(hr))
            goto Error;

        // state image is supported
        ASSERT(V_VT(&var) == VT_I4);
        if ( V_VT(&var) != VT_I4)
            goto Error;

        state = V_I4(&var);

      Error:
        VariantClear(&var);
        return state;
    }
    else
    {
        // -1 means the shell will next try VSHPROPID_IconHandle. 
        // If that fails it will use whatever icon
        // windows explorer has associated with our file
        return -1;
    }
}

//---------------------------------------------------------------------------
// delegates everything to the nested hierarchy
//---------------------------------------------------------------------------
HRESULT CBuildProjNode::DisplayContextMenu(void)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ASSERT(GetNested() != NULL);
    CComPtr<IVsUIHierarchy> srpVsUI;
    HRESULT hr = GetNested()->QueryInterface(IID_IVsUIHierarchy, (void**)&srpVsUI);
    IfFailRet(hr);
    ExpectedExprRet(srpVsUI != NULL);

    // a V_UI4 must be passed to the ExecCommand or it will crash!
    POINT  pnt;
    ::GetCursorPos(&pnt);
    POINTS pnts = { (SHORT)pnt.x, (SHORT)pnt.y };
    VARIANT var;
    VariantInit(&var);
    ULONG ulPoints;
    memcpy(&ulPoints, &pnts, sizeof(POINTS));
    V_VT(&var) = VT_UI4;
    V_UI4(&var) = ulPoints;

    // AddRef to protect for delete 
    hr = srpVsUI->ExecCommand((VSITEMID)VSITEMID_ROOT,
                                    &GUID_VsUIHierarchyWindowCmds,
                                    UIHWCMDID_RightClick, 0, &var, NULL);
    return hr;
}

//---------------------------------------------------------------------------
// delegates everything to the nested hierarchy
//---------------------------------------------------------------------------
HRESULT CBuildProjNode::DoDefaultAction(void)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ASSERT(GetNested() != NULL);
    // AddRef to protect for delete
    CComPtr<IVsUIHierarchy> srpVsUI;
    HRESULT hr = GetNested()->QueryInterface(IID_IVsUIHierarchy, (void**)&srpVsUI);
    IfFailRet(hr);
    ExpectedExprRet(srpVsUI != NULL);
    
    hr = srpVsUI->ExecCommand((VSITEMID)VSITEMID_ROOT,
                                    &GUID_VsUIHierarchyWindowCmds,
                                    UIHWCMDID_DoubleClick, 0, NULL, NULL);
    return hr;
}


HRESULT CBuildProjNode::GetProperty(VSHPROPID propid, VARIANT* pvar)
{  
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ASSERT(pvar);
    if (!pvar)
        return E_INVALIDARG;
    VariantInit(pvar);

    HRESULT hr = S_OK;
    switch (propid)
    {
    case VSHPROPID_ExtObject:
        if (!m_srpProjectItem)
        {    //Need to demand create the extensibility object.
            hr = CAOProjectItemNested::CreateInstance(this, &m_srpProjectItem);
            IfFailRet(hr);
            ExpectedExprRet(m_srpProjectItem != NULL);
        }
        IfFailGo(m_srpProjectItem->QueryInterface(IID_IDispatch, (LPVOID*)&V_DISPATCH(pvar)));
        V_VT(pvar) = VT_DISPATCH;
        break;

    // get it from the nested project
    case VSHPROPID_BrowseObject:
    case VSHPROPID_Name:
    case VSHPROPID_Caption:
    case VSHPROPID_SaveName:
    case VSHPROPID_EditLabel:
    case VSHPROPID_HandlesOwnReload:
        _ExpectedExprRet(m_srpNestedHierarchy);
        return m_srpNestedHierarchy->GetProperty(
            /* [in]  VSITEMID  itemid */ VSITEMID_ROOT,
            /* [in]  VSHPROPID propid */ propid,
            /* [out] VARIANT   *pvar  */ pvar);

    case VSHPROPID_IconHandle:
    case VSHPROPID_OpenFolderIconHandle:
        return GetIconHandle(propid,pvar);

    default:    // Delegate
        hr = CHierNestedContainer::GetProperty(propid, pvar);
        break;
    }
Error:
    return hr;
}


//-----------------------------------------------------------------------------
// Returns the project node. Will return NULL if this node is not in the node
// tree 
//-----------------------------------------------------------------------------
CFileVwProjNode* CBuildProjNode::GetProjectNode() const
{
    CHierNode *pNode = GetRootNode();
    if (!pNode)
        return NULL;

    if (!pNode->IsKindOf(Type_CFileVwProjNode))
    {
        ASSERT(FALSE);
        return NULL;
    }

    return static_cast<CFileVwProjNode *>(pNode);
}


STDMETHODIMP CBuildProjNode::OnIgnoreItemFileChanges(
    /* [in] */ BOOL fIgnore)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    if (fIgnore == m_fIgnoreFileChanges) // unmathced notification - ignore it
        return S_FALSE;
    m_fIgnoreFileChanges = fIgnore;

    HRESULT hr = S_OK;
    USES_CONVERSION;

    if (m_srpIVsFileChangeEx && m_vscookieIVsFileChangeEvents)
    {
        hr = m_srpIVsFileChangeEx->IgnoreFile(
            /* [in] VSCOOKIE vsCookie       */ m_vscookieIVsFileChangeEvents, 
            /* [in] LPCOLESTR pszMkDocument */ NULL,
            /* [in] BOOL fIgnore            */ fIgnore) ; 
        ASSERT(SUCCEEDED(hr));
    }
    return hr;
}


STDMETHODIMP CBuildProjNode::Save(
    /* [in]  */ VSSAVEFLAGS dwSave,
    /* [in]  */ LPCOLESTR pszSilentSaveAsName,
    /* [in]  */ IUnknown *punkDocData,
    /* [out] */ BOOL *pfCanceled)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pfCanceled);
    *pfCanceled = FALSE;

    if (!m_srpNestedHierarchy)
        return E_UNEXPECTED;

    HRESULT hrRet = S_OK;  // hr to be returned
    HRESULT hrTmp = S_OK;  // temporary hr

    // don't ignore/unignore file changes 
    // use Advise/Unadvise to work around rename situations
    hrTmp = UnadviseFileChange();
    ASSERT(SUCCEEDED(hrTmp));

    // we have to save the nested project node
    CComBSTR bstrMkDocumentNew;    
    CComPtr<IPersistFileFormat> srpFileFormat;
    hrRet = m_srpNestedHierarchy->QueryInterface(IID_IPersistFileFormat, (void **)&srpFileFormat);
    if( SUCCEEDED(hrRet) && (srpFileFormat != NULL) )
    {
        IVsUIShell *pIVsUIShell = _VxModule.GetVsUIShell(); // non-addref'ed
        ASSERT(NULL != pIVsUIShell);
        hrRet = pIVsUIShell->SaveDocDataToFile(dwSave, srpFileFormat, pszSilentSaveAsName, &bstrMkDocumentNew, pfCanceled);
    }

    // when supported do a rename of the nested project here 

    // succeeded or not we must hook to the file change events
    // don't ignore/unignore file changes 
    // use Advise/Unadvise to work around rename situations
    hrTmp = AdviseFileChange();
    ASSERT(SUCCEEDED(hrTmp));

    return hrRet;
}



//---------------------------------------------------------------------------
// Exeuctes ocmmands on our nested hierarchy
//---------------------------------------------------------------------------
HRESULT CBuildProjNode::ExecNestedCommand(int cmdID)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ASSERT(GetNested() != NULL);
    ASSERT( (cmdidDelete == cmdID));
    HRESULT hr = InitNestedCmdTarget();

    if (SUCCEEDED(hr))
    {
        hr = m_srpNestedOleCmdTrg->Exec(&guidVSStd97, cmdID, 0, NULL, NULL);

    }
    return hr;
}


//---------------------------------------------------------------------------
// Returns extensibility
//---------------------------------------------------------------------------
HRESULT CBuildProjNode::GetNestedAutomationProject(
    /* [out */ Project **ppProject)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(ppProject);
    *ppProject = NULL;
    
    HRESULT hr = S_OK;

    CComPtr<IVsHierarchy> srpIVsHierarchy = GetNested();
    ExpectedExprRet(srpIVsHierarchy != NULL)

    VARIANT var;
    var.vt = VT_EMPTY;
    hr = srpIVsHierarchy->GetProperty(VSITEMID_ROOT, VSHPROPID_ExtObject, &var);
    IfFailRet(hr);

    ASSERT(var.vt == VT_DISPATCH || var.vt == VT_UNKNOWN);
    if (var.vt == VT_DISPATCH || var.vt == VT_UNKNOWN)
    {
        hr = var.punkVal->QueryInterface(IID_Project, (void**)ppProject);
    }
    else
    {
        hr = E_FAIL;
    }
    VariantClear(&var);
    return hr;
}


HRESULT CBuildProjNode::AddItem(LPCTSTR pszSourcePath, LPCTSTR pszItemName)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    USES_CONVERSION;
    HRESULT                hr = S_OK;
    CComPtr<IVsProject> srpProject = NULL;
    VSADDRESULT            resultAddItem;
    LPCOLESTR            pwzSource = T2COLE(pszSourcePath);

    IfFailGo( m_srpNestedHierarchy->QueryInterface(IID_IVsProject, (void **)&srpProject) );
    ASSERT(srpProject != NULL);
    IfFailGo( srpProject->AddItem(VSITEMID_ROOT, VSADDITEMOP_OPENFILE, T2COLE(pszItemName), 1, &pwzSource, NULL, &resultAddItem) );

Error:    
    return hr;

}


//-----------------------------------------------------------------------------
// Return the lowercase, project relative path as our canonical name. 
// If the file is not contained in our project directory, then the absolute
// path will be returned.
//
// NOTE: it is important that the canonical name is returned in a consistent
// manner to allow the caller to reliably perform string comparisons to test
// whether two canonical names are identical. because the file system is not
// case sensitive (but rather case preserving) and because we use our file
// system path as the basis for our canonical name, we must convert the path
// to a deterministic case. by convention, we convert the file path to lower
// case.
//-----------------------------------------------------------------------------
HRESULT CBuildProjNode::GetCanonicalName(BSTR* pbstrName) const
{    
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    HRESULT hr = S_FALSE;
    CString strProjRelPath = GetFullPath();
    CString strRootPath = (reinterpret_cast<CFileVwProjNode*>(GetRootNode()))->GetFolderPath();

    if(strProjRelPath.Find(strRootPath) == 0)
    {
        // Strip off the project path
        strProjRelPath = strProjRelPath.Right(strProjRelPath.GetLength() - strRootPath.GetLength());
        hr = S_OK;
    }
    strProjRelPath.MakeLower();
    *pbstrName = strProjRelPath.AllocSysString();
    return (*pbstrName) ? hr : E_OUTOFMEMORY;    
}


//---------------------------------------------------------------------------
// Called by CVsHeirarchy on VSHPROPID_UserContext.
// Add our attributes and target links to filter our topics
// in the Dynamic Help window.
//---------------------------------------------------------------------------
HRESULT CBuildProjNode::GetUserContext(IVsUserContext **ppUserCtx)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CBuildProjNode::GetUserContext /VSHPROPID_UserContext/ this = 0x%x\n"), this);

    ExpectedPtrRet(ppUserCtx);
    *ppUserCtx = NULL;
 
    HRESULT hr = E_FAIL;
    if (m_srpUserCtx == NULL) 
    {
        hr = CreateUserContext(&m_srpUserCtx);
        IfFailRet(hr);
        ExpectedExprRet(m_srpUserCtx != NULL);

    }

    hr = m_srpUserCtx->RemoveAttribute(L"Item", NULL);  
    IfFailRet(hr);
    hr = m_srpUserCtx->AddAttribute(VSUC_Usage_Filter, L"Item", L"vs.envsdk.figprj.buildfilenode");  
    IfFailRet(hr);

    *ppUserCtx = m_srpUserCtx;
    (*ppUserCtx)->AddRef();

    return S_OK;            
}


HRESULT CBuildProjNode::GetGuidProperty(
    /* [in]  */ VSHPROPID propid, 
    /* [out] */ GUID*     pGuid) const
{
    ExpectedPtrRet(pGuid);
    *pGuid = GUID_NULL;

    HRESULT hr = S_OK;

    switch (propid)
    {
        case VSHPROPID_TypeGuid:
            // we represent a nested hierarchy project so 
            // return the corresponding guid defined in vsshell.idl
            *pGuid = GUID_ItemType_SubProject;
            break;
        default:
            hr = DISP_E_MEMBERNOTFOUND;
            break;
    }
    return hr;
}


HRESULT CBuildProjNode::GetIconHandle(
    /* [in]  */ VSHPROPID propid, 
    /* [out] */ VARIANT *pvar)
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedPtrRet(pvar);
    VariantInit(pvar);

    HRESULT hr = S_OK;

    if(m_srpNestedHierarchy == NULL)
    {
        // InitNestedHierarchy() should already have been called
        // do not assert though - we may be here if we are in the 
        // shell's cleanup code during a delete.
        return E_FAIL;
    }

    //get the icon if not set yet.
    if (m_hIcon == NULL)    
    {
        m_hIcon = (HICON)INVALID_HANDLE_VALUE;

        // it is a nested hierarchy, get the image icon from the nested hierarchy
        long    lIndex = 0;
        VARIANT varImgList, varIndex;
        HIMAGELIST hImgList = NULL;

        hr = m_srpNestedHierarchy->GetProperty(
            VSITEMID_ROOT, 
            VSHPROPID_IconImgList, 
            &varImgList);
        if (SUCCEEDED(hr))
        {
            ExpectedExprRet(V_VT(&varImgList) == VT_I4);
               
            hImgList = (HIMAGELIST)V_I4(&varImgList);

            if (propid == VSHPROPID_IconHandle)
            {
                hr = m_srpNestedHierarchy->GetProperty(VSITEMID_ROOT, VSHPROPID_IconIndex, &varIndex);
            }
            else
            {
                hr = m_srpNestedHierarchy->GetProperty(VSITEMID_ROOT, VSHPROPID_OpenFolderIconIndex, &varIndex);
            }

            if (SUCCEEDED(hr))
            {
                lIndex = V_I4(&varIndex);
                m_hIcon = ImageList_GetIcon(hImgList, lIndex, ILD_NORMAL );
            }
        }
    }

    // the nested project MAY be using icon handles - so just forward the call.
    // we have tried this before and it didnt work, so forward!
    if( INVALID_HANDLE_VALUE  == m_hIcon )
    {
        return m_srpNestedHierarchy->GetProperty(VSITEMID_ROOT, propid, pvar);
    }

    ASSERT( m_hIcon );

    V_VT(pvar) = VT_INT_PTR;

    // the shell does not destroy this icon - we "own" it, so no need to ,make a copy of it before handing
    // off to the shell
    V_INT_PTR(pvar) = (LONG)(m_hIcon);

    return S_OK;
}


void CBuildProjNode::ClearIconHandle()
{
    if( (m_hIcon != NULL) && (m_hIcon != INVALID_HANDLE_VALUE) )
    {
        ::DestroyIcon(m_hIcon);
        m_hIcon = NULL;
    }
}


STDMETHODIMP CBuildProjNode::Refresh()
{
	ASSERT(!IsZombie());
    if (IsZombie())
        return E_UNEXPECTED;

    ExpectedExprRet(m_srpNestedHierarchy != NULL);

    HRESULT hr = S_OK;

    CComPtr<IVsUIHierarchy>  srpIVsUIHierarchyNested;
    hr = m_srpNestedHierarchy->QueryInterface(
        IID_IVsUIHierarchy, 
        (void**)&srpIVsUIHierarchyNested);
    IfFailRet(hr);

    OLECMD cmdid = {cmdidRefresh, 0};
    hr = srpIVsUIHierarchyNested->QueryStatusCommand(VSITEMID_ROOT, &guidVSStd97, 1, &cmdid, NULL);
    IfFailRet(hr);

    if ( (cmdid.cmdf & (OLECMDF_SUPPORTED | OLECMDF_ENABLED)) == (OLECMDF_SUPPORTED | OLECMDF_ENABLED))
    {
        hr = srpIVsUIHierarchyNested->ExecCommand(VSITEMID_ROOT, &guidVSStd97, cmdidRefresh, 0, NULL, NULL);
        IfFailRet(hr);
    }

    return hr;
};


// End of projnbld.cpp
