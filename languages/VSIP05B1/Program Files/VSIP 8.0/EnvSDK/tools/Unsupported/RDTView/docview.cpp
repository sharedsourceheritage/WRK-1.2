/*
 -
 -    D O C V I E W . C P P
 -
 *
 *    Purpose:    Implements the CDocViewer class.
 *                CDocViewer implements an IDocViewer interface that is used to query 
 *                the VS environment's running document table and populate two list boxes
 *                with its current state.  CDocViewer also houses the event sink interface passed to 
 *                IVsRunningDocumentTable::AdviseRunningDocTableEvents(), so therefore it also
 *                implements IVsRunningDocTableEvents, IVsRunningDocTableEvents2, and IVsRunningDocTableEvents3.
 *
 */

#include "stdafx.h"
#include "docview.h"
#include "prjinc.h"
#include <limits.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDocViewer::CDocViewer()
{
    m_dwSinkCookie = 0;
    m_iCurSel = -1;
    ::ZeroMemory(m_rgDirty, (c_cMaxDirty * sizeof(m_rgDirty[0])));
    m_cDirty = 0;
}

CDocViewer::~CDocViewer()
{
    m_srpWindowPane.Release();
}

/*
 -
 -    GetRdtService()
 -
 *    This is called when the RDT service is needed and hasn't yet been obtained.  It simply gets
 *    a pointer to IVsRunningDocumentTable and stores it in m_srpRDT.
 *
 */
HRESULT CDocViewer::GetRdtService()
{
    Assert(NULL == m_srpRDT.p);
    HRESULT hr = _Module.QueryService(SID_SVsRunningDocumentTable, IID_IVsRunningDocumentTable, (void**)&m_srpRDT);
    if (SUCCEEDED(hr))
        Assert(m_srpRDT.p);

    return hr;
}


/*
 -
 -    LbWriteString()
 -
 *    Writes a string to the list box with the specified HWND.
 *    Returns the count of characters in the string if successful, otherwise LB_ERR or LB_ERRSPACE.
 *
 */
LRESULT CDocViewer::LbWriteString(
                        HWND hwnd,            // [in] HWND of listbox to add string to
                        LPCTSTR tsz,        // [in] Text to write
                        ...)
{
    va_list rgArgs;
    va_start(rgArgs, tsz);

    TCHAR tszStr[c_cchMaxLbStr + 1];
    tszStr[c_cchMaxLbStr] = _T('\0');
    int cch = _vsntprintf(tszStr, c_cchMaxLbStr, tsz, rgArgs);
    Assert((cch > -1) && (cch < c_cchMaxLbStr));
    if (cch > -1)
        tszStr[cch] = _T('\0');
    va_end(rgArgs);

    LRESULT lResult = ::SendMessage(hwnd, LB_ADDSTRING, (WPARAM)0, (LPARAM)tszStr);
    Assert((lResult != LB_ERR) && (lResult != LB_ERRSPACE));
    return lResult;
} 

/*
 -
 -    HandleAttributeChange()
 -
 *    Handles an OnAfterAttributeChange or OnAfterAttributeChangeEx notification by updating the dirty list
 *    based on a DocDataIsDirty or DocDataIsNotDirty attribute.  Any other attributes are ignored.
 *    This method does not repopulate the list; the caller should call Populate() after it returns.
 *
 */
void CDocViewer::HandleAttributeChange(
                    VSCOOKIE docCookie,        // [in] Cookie of document firing attribute change notification
                    VSRDTATTRIB grf)        // [in] grf of attributes
{
    if (grf & RDTA_DocDataIsDirty)
    {
        // Doc is now dirty.  Add docCookie to m_rgDirty.
        if (m_cDirty >= c_cMaxDirty)
        {
            // There is a current limit of 256 simultaneously dirty documents.
            Assert(FALSE);
            return;
        }

        m_rgDirty[m_cDirty++] = docCookie;
    }
    else if (grf & RDTA_DocDataIsNotDirty)
    {
        // Doc is now not dirty.  Remove docCookie from m_rgDirty.
        UINT iItem = FindInDirtyList(docCookie);
        if (iItem < 0)
        {
            // Wouldn't expect to get a DocIsNotDirty notification for a document for which
            // no DocIsDirty notification was ever fired.
            Assert(FALSE);
        }
        else
        {
            Assert(m_cDirty <= c_cMaxDirty);
            for (UINT i = iItem; i < (m_cDirty - 1); i++)
            {
                m_rgDirty[i] = m_rgDirty[i+1];
            }

            Assert(m_cDirty > 0);
            m_cDirty--;
        }
    }
    else
    {
        // Do nothing for any other bits set in grf
    }

} // CDocViewer::HandleAttributeChange()


/*
 -
 -    FindInDirtyList()
 -
 *    Search the dirty list for the specified cookie.
 *    Return the 0-based index to the array if found, else return -1.
 *
 */
LONG CDocViewer::FindInDirtyList(
                        VSCOOKIE docCookie)        // [in] Document cookie to search for in dirty list
{
    for (UINT i = 0; i < m_cDirty; i++)
    {
        if (docCookie == m_rgDirty[i])
            return i;
    }

    return -1;
}


//////////////////////////////////////////////////////////////////////
// IDocViewer implementation
//////////////////////////////////////////////////////////////////////

/*
 -
 -    Advise()
 -
 *    Advises for IVsRunningDocTableEvents[2,3] events.
 *
 */
STDMETHODIMP CDocViewer::Advise(
                            VSCOOKIE* pdwCookie)                    // [out] Sink cookie returned
{
    if (NULL == pdwCookie)
    {
        Assert(FALSE);
        return E_POINTER;
    }

    HRESULT hr = S_OK;
    *pdwCookie = 0;

    if (NULL == m_srpRDT.p)
        IfFailGo(GetRdtService());

    hr = m_srpRDT->AdviseRunningDocTableEvents(this, &m_dwSinkCookie);
    if (SUCCEEDED(hr))
        *pdwCookie = m_dwSinkCookie;

_done:
    return hr;
} // CDocViewer::Advise()


/*
 -
 -    Populate()
 -
 *    This is called when we show the RDT Viewer tool window, as well as when we receive event notification
 *    that indicates the list needs to be refreshed.  We get the HWND of the list box to display the 
 *    documents in by QI'ing the IVsWindowPane passed in for IVsRdtViewTool.  The IVsWindowPane passed in
 *    must therefore point to an object that implements IVsRdtViewTool or this will fail.
 */
STDMETHODIMP CDocViewer::Populate(
                            IVsWindowPane* pToolWindowPane)    // [in] Tool window containing RDTView doc obj
{
    if (NULL == pToolWindowPane)
    {
        Assert(FALSE);    
        return E_INVALIDARG;
    }
    
    CComPtr<IRDTViewTool> srpRdtViewTool;
    CComPtr<IEnumRunningDocuments> srpEnumDoc;
    VSCOOKIE    hDoc        = 0;
    ULONG        cActual        = 0;
    VSRDTFLAGS    grf            = 0;
    DWORD        cReadLock    = 0;
    DWORD        cEditLock    = 0;
    CComBSTR    bstrName;
    VSITEMID    itemid        = 0;
    HRESULT        hr            = S_OK;
    HWND        hwndList    = NULL;
    LONG        iItem        = 0;
    TCHAR*        tszText        = NULL;
    LRESULT        lResult        = 0;
    LONG        cch            = 0;
    LONG        cchMax        = 0;
    LONG        iWideItem    = 0;
    USES_CONVERSION;

    // Store the IVsWindowPane pointer
    if (NULL == m_srpWindowPane.p)
        m_srpWindowPane = pToolWindowPane;        // does an addref

    if (NULL == m_srpRDT.p)
        GetRdtService();

    // Get the HWND to the listbox in the RDT Viewer tool window.  It's accessible from the 
    // IRDTViewTool interface
    hr = pToolWindowPane->QueryInterface(IID_IRDTViewTool, (void**)&srpRdtViewTool);
    IfFailAssertGo(hr);    

    hr = srpRdtViewTool->GetListDocsHwnd(&hwndList);
    IfFailAssertGo(hr);
    Assert(hwndList);

    // Clear the listbox
    (void)::SendMessage(hwndList, LB_RESETCONTENT, (WPARAM)0, (LPARAM)0);

    // Get the running doc enumerator and add each document's name to the listbox
    hr = m_srpRDT->GetRunningDocumentsEnum(&srpEnumDoc);
    IfFailGo(hr);

    do
    {
        hr = srpEnumDoc->Next(1, &hDoc, &cActual);
        if (S_OK == hr)
        {
            Assert(1 == cActual);
            if (bstrName.m_str)
                bstrName.Empty();

            hr = m_srpRDT->GetDocumentInfo(
                                hDoc,            // docCookie
                                &grf,            // pgrfRDTFlags
                                &cReadLock,        // pdwReadLocks
                                &cEditLock,        // pdwEditLocks
                                &bstrName,        // pbstrMkDocument
                                NULL,            // ppHier
                                &itemid,        // pitemid
                                NULL);            // ppunkDocData

            if (SUCCEEDED(hr))
            {
                // Write a string to the listbox formed as "<cookie> pbstrMkDocument"
                // If the document is dirty, add a '*' to the end of the filename to indicate this.
                if (FindInDirtyList(hDoc) > -1)
                {
                    // cch = (max len of the cookie + 6 ('<', '>', ' ', ' ', '*', '\0') + len of name)
                    cch = c_cchMaxCookie + 6 + bstrName.Length();
                    tszText = new TCHAR[cch + 1];
                    Assert(tszText);
                    if (NULL == tszText)
                    {
                        return E_OUTOFMEMORY;
                    }
                    tszText[cch] = 0;
                    cch = _sntprintf(tszText, cch, _T("<%Id> %s *"), hDoc, OLE2T(bstrName));
                }
                else
                {
                    // cch = (max len of the cookie + 4 ('<', '>', ' ', '\0') + len of name)
                    cch = c_cchMaxCookie + 4 + bstrName.Length();
                    tszText = new TCHAR[cch + 1];
                    Assert(tszText);
                    if (NULL == tszText)
                    {
                        return E_OUTOFMEMORY;
                    }
                    tszText[cch] = 0;
                    cch = _sntprintf(tszText, cch, _T("<%Id> %s"), hDoc, OLE2T(bstrName));
                }

                // Send to the listbox
                lResult = ::SendMessage(hwndList, LB_ADDSTRING, (WPARAM)0, (LPARAM)tszText);
                Assert((lResult != LB_ERR) && (lResult != LB_ERRSPACE));
                delete [] tszText;
                if (cch > cchMax)
                {
                    cchMax = cch;
                    iWideItem = iItem;
                }
                iItem++;
            }
            else
            {
                Assert(FALSE);    // Why can't we get doc info for hDoc?
            }
        }
    } while (S_OK == hr);

    // If there are any documents, force a refresh on the document properties pane, based on the currently
    // selected document.  If there was no previous selection, select the first document in the list.
    // In any case, force selection of either the last known selected index or the first item in the list,
    // so that the properties list box will be able to display info.
    if (iItem > 0)
    {
        if ((m_iCurSel < 0) || (m_iCurSel > iItem))
            m_iCurSel = 0;

        Verify(::SendMessage(hwndList, LB_SETCURSEL, (WPARAM)m_iCurSel, (LPARAM)0) != LB_ERR);

        // Set the horizontal extent of the listbox based on our longest string
        HDC hdc = ::GetDC(hwndList);
        SIZE size;
        Assert(hdc);
        TCHAR* tszWide = new TCHAR[cchMax + 1];
        Assert(tszWide);
        if (!tszWide)
            return E_OUTOFMEMORY;
        cch = (LONG)::SendMessage(hwndList, LB_GETTEXT, (WPARAM)iWideItem, (LPARAM)tszWide);
        Assert(cch == cchMax);
        Verify(::GetTextExtentPoint32(hdc, tszWide, cch, &size));
        (void)::SendMessage(hwndList, LB_SETHORIZONTALEXTENT, (WPARAM)(size.cx), (LPARAM)0);
        delete [] tszWide;
        Verify(::ReleaseDC(hwndList, hdc));

        // Force the listbox to update the properties based on a selchange notification
        (void)::SendMessage(::GetParent(hwndList), WM_COMMAND, MAKEWPARAM(IDC_LIST_DOCS, LBN_SELCHANGE), (LPARAM)hwndList);
    }
    else
    {
        // Clear the properties listbox
        HWND hwndListProp = NULL;
        hr = srpRdtViewTool->GetListPropHwnd(&hwndListProp);
        if (SUCCEEDED(hr))
        {
            (void)::SendMessage(hwndListProp, LB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
        }
        else
        {
            Assert(FALSE);
        }
    }

_done:
    return hr;
} // CDocViewer::Populate()


/*
 -
 -    Unadvise()
 -
 *    Unadvises for IVsRunningDocTableEvents[2,3].  Uses the cookie we have stored.
 *
 */
STDMETHODIMP CDocViewer::Unadvise()
{
    return UnadviseEx(m_dwSinkCookie);
}


/*
 -
 -    UnadviseEx()
 -
 *    Unadvises for IVsRunningDocTableEvents[2,3].  Takes an explicit cookie.
 *
 */
STDMETHODIMP CDocViewer::UnadviseEx(
                            VSCOOKIE dwCookie)                            // [in] Sink cookie
{
    if (0 == m_dwSinkCookie)
    {
        Assert(FALSE);    // Can't unadvise without advising
        return E_UNEXPECTED;
    }

    if (NULL == m_srpRDT.p)
    {
        Assert(FALSE);    // How did we Advise with no RDT service?
        return E_UNEXPECTED;
    }

    if (0 == dwCookie)
        return E_INVALIDARG;

    m_dwSinkCookie = 0;
    return m_srpRDT->UnadviseRunningDocTableEvents(dwCookie);
}


/*
 -
 -    PopulateProperties()
 -
 *    Populates the properties list box with the properties for the document currently selected in the 
 *    document list box.
 *
 */
STDMETHODIMP CDocViewer::PopulateProperties(
                            HWND hwndListDocs,                        // [in] HWND of doc listbox
                            HWND hwndListProp)                        // [in] HWND of properties listbox
{
    if (NULL == hwndListDocs)
        return E_INVALIDARG;

    if (NULL == hwndListProp)
        return E_INVALIDARG;

    LONG        iItem        = 0;
    LONG        cchItem        = 0;
    TCHAR*        tszItem        = NULL;
    TCHAR*        tszCookie    = NULL;
    VSCOOKIE    hDoc        = 0;
    VSRDTFLAGS    grfRDTFlags    = 0;
    DWORD        cReadLock    = 0;
    DWORD        cEditLock    = 0;
    CComBSTR    bstrName;
    VSITEMID    itemid        = 0;
    HRESULT        hr            = S_OK;
    USES_CONVERSION;

    // Get the current listbox selection
    m_iCurSel = (LONG)::SendMessage(hwndListDocs, LB_GETCURSEL, (WPARAM)0, (LPARAM)0);
    if (m_iCurSel != LB_ERR)
    {
        // There is a current selection - get the current string
        cchItem = (LONG)::SendMessage(hwndListDocs, LB_GETTEXTLEN, (WPARAM)m_iCurSel, (LPARAM)0);
        if (cchItem > 0)
        {
            tszItem = new TCHAR[cchItem + 1];
            Assert(tszItem);

            Verify(::SendMessage(hwndListDocs, LB_GETTEXT, (WPARAM)m_iCurSel, (LPARAM)tszItem) == cchItem);

            // Parse the cookie from the string
            tszCookie = tszItem;
            while ((tszCookie) && (*tszCookie != _T('\0')) && (*tszCookie != _T('<')))
                tszCookie = _tcsinc(tszCookie);

            if ((NULL == tszCookie) || (_T('\0') == *tszCookie))
            {
                Assert(FALSE);    // Never found the opening '<'
                hr = E_UNEXPECTED;
                goto _done;
            }

            // Get past the '<'
            tszCookie = _tcsinc(tszCookie);

            // Get up to the '>'
            tszCookie = _tcstok(tszCookie, _T(">"));
            Assert(tszCookie);

#ifdef _WIN64
            hDoc = _tstoi64(tszCookie);
#else
            hDoc = _ttol(tszCookie);
#endif

            delete [] tszItem;
            tszItem = NULL;

            // Get the properties of this document
            Assert(m_srpRDT.p);
            hr = m_srpRDT->GetDocumentInfo(
                                hDoc,            // docCookie
                                &grfRDTFlags,    // pgrfRDTFlags
                                &cReadLock,        // pdwReadLocks
                                &cEditLock,        // pdwEditLocks
                                &bstrName,        // pbstrMkDocument
                                NULL,            // ppHier
                                &itemid,        // pitemid
                                NULL);            // ppunkDocData
            if (SUCCEEDED(hr))
            {
                // Write the properties to the properties listbox

                // Cookie
                (void)LbWriteString(hwndListProp, _T("Cookie: 0x%p (%Id)"), hDoc, hDoc);

                // Name
                (void)LbWriteString(hwndListProp, _T("Name: %s"), OLE2T(bstrName));

                // Mark if dirty
                if (FindInDirtyList(hDoc) > -1)
                    (void)LbWriteString(hwndListProp, _T("*Dirty*"));

                // Masks
                (void)LbWriteString(hwndListProp, _T("RDT_LOCKMASK: 0x%X"), (grfRDTFlags & RDT_LOCKMASK));
                (void)LbWriteString(hwndListProp, _T("RDT_DOCMASK: 0x%X"), (grfRDTFlags & RDT_DOCMASK));
                (void)LbWriteString(hwndListProp, _T("RDT_SAVEMASK: 0x%X"), (grfRDTFlags & RDT_SAVEMASK));

                // Flags
                if (grfRDTFlags)
                {
                    (void)LbWriteString(hwndListProp, _T("Flags set:"));
                    WriteFlagIfSet(hwndListProp, _T("RDT_ReadLock"), grfRDTFlags & RDT_ReadLock);
                    WriteFlagIfSet(hwndListProp, _T("RDT_EditLock"), grfRDTFlags & RDT_EditLock);
                    WriteFlagIfSet(hwndListProp, _T("RDT_RequestUnlock"), grfRDTFlags & RDT_RequestUnlock);
                    WriteFlagIfSet(hwndListProp, _T("RDT_DontSaveAs"), grfRDTFlags & RDT_DontSaveAs);
                    WriteFlagIfSet(hwndListProp, _T("RDT_NonCreatable"), grfRDTFlags & RDT_NonCreatable);
                    WriteFlagIfSet(hwndListProp, _T("RDT_DontSave"), grfRDTFlags & RDT_DontSave);
                    WriteFlagIfSet(hwndListProp, _T("RDT_DontAutoOpen"), grfRDTFlags & RDT_DontAutoOpen);
                    WriteFlagIfSet(hwndListProp, _T("RDT_CaseSensitive"), grfRDTFlags & RDT_CaseSensitive);
                    WriteFlagIfSet(hwndListProp, _T("RDT_CantSave"), grfRDTFlags & RDT_CantSave);
                    WriteFlagIfSet(hwndListProp, _T("RDT_VirtualDocument"), grfRDTFlags & RDT_VirtualDocument);
                    WriteFlagIfSet(hwndListProp, _T("RDT_Unlock_NoSave"), grfRDTFlags & RDT_Unlock_NoSave);
                    WriteFlagIfSet(hwndListProp, _T("RDT_Unlock_PromptSave"), grfRDTFlags & RDT_Unlock_PromptSave);
                }
                else
                {
                    (void)LbWriteString(hwndListProp, _T("<No flags set>"));
                }

                // cReadLock
                (void)LbWriteString(hwndListProp, _T("cReadLocks: %d"), cReadLock);

                // cEditLock
                (void)LbWriteString(hwndListProp, _T("cEditLocks: %d"), cEditLock);

                // itemid
                (void)LbWriteString(hwndListProp, _T("itemid: %Id"), itemid);
            }
            else
            {
                Assert(FALSE);    // Why couldn't we get the doc info for this VSCOOKIE?
            }
        } // Non-empty string at current selection
    } // Current selection
    else
    {
        // There is no current selection, nothing to do here
    }


_done:
    if (tszItem)
        delete [] tszItem;

    return hr;
} // CDocViewer::PopulateProperties()


//////////////////////////////////////////////////////////////////////
// IVsRunningDocTableEvents implementation
//////////////////////////////////////////////////////////////////////

// Hide, Show, and Attribute Change notifications are the only events that need processing; I don't believe
// we need to care about Lock/Unlock/Save events.
//
// Hide and Show events require a refresh since it means a document may have just been added or removed.
//
// We process attribute change notifications to update our dirty list, so we can display a '*' next to a
// document if it's currently considered dirty.

STDMETHODIMP CDocViewer::OnAfterFirstDocumentLock(
                VSCOOKIE docCookie,
                VSRDTFLAGS dwRDTLockType,
                DWORD dwReadLocksRemaining,
                DWORD dwEditLocksRemaining)
{
    return E_NOTIMPL;
}

STDMETHODIMP CDocViewer::OnBeforeLastDocumentUnlock(
                VSCOOKIE docCookie,
                VSRDTFLAGS dwRDTLockType,
                DWORD dwReadLocksRemaining,
                DWORD dwEditLocksRemaining)
{
    return E_NOTIMPL;
}

STDMETHODIMP CDocViewer::OnAfterSave(
                VSCOOKIE docCookie)
{
    return E_NOTIMPL;
}

STDMETHODIMP CDocViewer::OnAfterAttributeChange(
                VSCOOKIE docCookie, 
                VSRDTATTRIB grfAttribs)
{
    HandleAttributeChange(docCookie, grfAttribs);
    Verify(SUCCEEDED(Populate(m_srpWindowPane)));
    return S_OK;
}

STDMETHODIMP CDocViewer::OnBeforeDocumentWindowShow(
                VSCOOKIE docCookie, 
                BOOL fFirstShow, 
                IVsWindowFrame *pFrame)
{
    Verify(SUCCEEDED(Populate(m_srpWindowPane)));
    return S_OK;
}

STDMETHODIMP CDocViewer::OnAfterDocumentWindowHide(
                VSCOOKIE docCookie, 
                IVsWindowFrame *pFrame)
{
    Verify(SUCCEEDED(Populate(m_srpWindowPane)));
    return S_OK;
}

//////////////////////////////////////////////////////////////////////
// IVsRunningDocTableEvents2
//////////////////////////////////////////////////////////////////////
STDMETHODIMP CDocViewer::OnAfterAttributeChangeEx(
                VSCOOKIE docCookie,
                VSRDTATTRIB grfAttribs,
                IVsHierarchy *pHierOld,
                VSITEMID itemidOld,
                LPCOLESTR pszMkDocumentOld,                     
                IVsHierarchy *pHierNew,
                VSITEMID itemidNew,
                LPCOLESTR pszMkDocumentNew)
{
    HandleAttributeChange(docCookie, grfAttribs);
    Verify(SUCCEEDED(Populate(m_srpWindowPane)));
    return S_OK;
}

//////////////////////////////////////////////////////////////////////
// IVsRunningDocTableEvents3
//////////////////////////////////////////////////////////////////////
STDMETHODIMP CDocViewer::OnBeforeSave(
                VSCOOKIE docCookie)
{
    return E_NOTIMPL;
}
