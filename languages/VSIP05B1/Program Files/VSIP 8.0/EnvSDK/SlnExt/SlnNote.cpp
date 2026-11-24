
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// SlnNote.cpp : Implementation of of the CSlnNotes, CEnumNotes and CSlnNote
//
#include "stdafx.h"
#include "slnnote.h"
#include "notewin.h"
#include "guids.h"
#include "commctrl.h"

UINT CSlnNote::m_nCurNote = 0;
/////////////////////////////////////////////////////////////////////////////
// CSlnNote

CSlnNote::CSlnNote()
{
    ATLTRACE(_T("Creating CSlnNote: 0x%X\n"), this);
    m_idx = 0;
    m_pToolWin = NULL;
    m_bstrName = NULL;
    m_fShared = VARIANT_FALSE;
    m_fIssue = VARIANT_FALSE;
    m_fModified = VARIANT_TRUE;
    m_bstrText = NULL;
}

CSlnNote::~CSlnNote()
{
    ATLTRACE(_T("Destructing CSlnNote: 0x%X\n"), this);
    if(m_srpFrame)
    {
        Close();
    }
    SysFreeString(m_bstrName);
    if(m_bstrText)
        SysFreeString(m_bstrText);
}

HRESULT CSlnNote::Init(CNoteToolWindow* pWin)
{
    if (!pWin)
        return E_POINTER;
    HRESULT hr = NOERROR;
    m_pToolWin = pWin; // not referenced

    if(FAILED(hr = CreateUniqueName(m_pToolWin->m_hwndList)))
        return hr;

    if(FAILED(hr = AddToListBox(m_pToolWin->m_hwndList)))
        return hr;

    if(FAILED(hr = put_Visible(VARIANT_TRUE)))
        return hr;

    return NOERROR;
}

HRESULT CSlnNote::Close()
{
    HRESULT hr = NOERROR;
    IfFailGo(UpdateText());

    if(m_srpFrame)
    {
        m_srpFrame->CloseFrame(FRAMECLOSE_NoSave);
    }

Error:
    return hr;
}

HRESULT CSlnNote::CreateUniqueName(HWND hwndList)
{
    TCHAR szNote[] = _T("Note"), szName[MAX_NAME];
    USES_CONVERSION;

    ULONG lFound = -1;
    int nCount = ListView_GetItemCount(hwndList);
    
    do
    {
        TCHAR szTemp[MAX_NAME];
        TCHAR szNum[MAX_NAME - 4];
        m_nCurNote++;
        
        _tcscpy(szTemp, szNote);
        _itot(m_nCurNote, szNum, 10);
        _tcscat(szTemp, szNum);
        
        LVFINDINFO lvfi;
        lvfi.flags = LVFI_STRING;
        lvfi.psz = szTemp;
        lFound = ListView_FindItem(hwndList, -1, &lvfi);
        
        if(lFound == -1)
            _tcscpy(szName, szTemp);

    }while(lFound != -1);

    m_bstrName = SysAllocString(T2OLE(szName));

    return NOERROR;
}

HRESULT CSlnNote::AddToListBox(HWND hwndList)
{
    USES_CONVERSION;
    LVITEM lvi;
    lvi.mask = LVIF_TEXT | LVIF_STATE | LVIF_PARAM | LVIF_IMAGE;
    lvi.pszText = OLE2T(m_bstrName);
    lvi.iItem = m_idx = ListView_GetItemCount(hwndList);
    lvi.iSubItem = 0;
    lvi.state = LVIS_SELECTED;
    lvi.stateMask = -1;
    lvi.lParam = (LPARAM)this;
    lvi.iImage = m_fIssue ? 1 : 0;
    m_idx = ListView_InsertItem(hwndList, &lvi);
    lvi.mask = LVIF_TEXT;
    lvi.pszText = m_fIssue ? _T("Yes") : _T("No");
    lvi.iSubItem = 1;
    ListView_SetItem(hwndList, &lvi);
    lvi.mask = LVIF_TEXT;
    lvi.pszText = m_fShared ? _T("Yes") : _T("No");
    lvi.iSubItem = 2;
    ListView_SetItem(hwndList, &lvi);
    m_pToolWin->DoSelectionChange();

    return NOERROR;
}

HRESULT CSlnNote::UpdateText()
{
    HRESULT hr = NOERROR;

    if(m_srpFrame)
    {
        CComPtr<IVsTextLines> srpLines;
        CComQIPtr<IVsCodeWindow> srpView;
        VARIANT varProp;
        long lLineCount, lLengthOfLast;

        if(m_bstrText)
        {
            SysFreeString(m_bstrText);
            m_bstrText = NULL;
        }

        VariantInit(&varProp);
        IfFailGo(m_srpFrame->GetProperty(VSFPROPID_DocView, &varProp));
        srpView = varProp.punkVal;
        varProp.punkVal->Release();
        if(!srpView) return E_UNEXPECTED;

        IfFailGo(srpView->GetBuffer(&srpLines));
        IfFailGo(srpLines->GetLineCount(&lLineCount));
        if(lLineCount > 0)
        {
            IfFailGo(srpLines->GetLengthOfLine(lLineCount - 1, &lLengthOfLast));
            IfFailGo(srpLines->GetLineText(0, 0, lLineCount - 1, lLengthOfLast, &m_bstrText));
        }
    }

Error:
    return hr;
}


HRESULT CSlnNote::ChangeNameInListBox(BSTR bstrName)
{
    USES_CONVERSION;
    LVITEM lvi;
    lvi.mask = LVIF_TEXT;
    lvi.pszText = OLE2T(bstrName);
    lvi.iItem = m_idx;
    lvi.iSubItem = 0;

    ListView_SetItem(m_pToolWin->m_hwndList, &lvi);

    return NOERROR;
}

HRESULT CSlnNote::SaveOpts(IStream* pStream)
{
    HRESULT hr = NOERROR;

    CComVariant varName(m_bstrName);
    CComVariant varIssue(m_fIssue);
    CComVariant varText(m_bstrText);

    IfFailGo(UpdateText());
    IfFailGo(varIssue.ChangeType(VT_I4));
    IfFailGo(varName.WriteToStream(pStream));
    IfFailGo(varIssue.WriteToStream(pStream));
    IfFailGo(varText.WriteToStream(pStream));
Error:
    return hr;
}

HRESULT CSlnNote::SaveProps(IPropertyBag* pProps, UINT nKey)
{
    if (!pProps)
        return E_POINTER;
    HRESULT hr = NOERROR;

    OLECHAR szNameKey[MAX_NAME], szNum[MAX_NAME - 5];
    OLECHAR szIssueKey[MAX_NAME];
    OLECHAR szTextKey[MAX_NAME];
    WCHAR* szNewString = NULL;
    WCHAR* pc = NULL;
    BSTR bstrIssue = NULL;
    IfFailGo(UpdateText());

    _itow(nKey, szNum, 10);
    wcscpy(szNameKey, L"Name");
    wcscat(szNameKey, szNum);
    wcscpy(szIssueKey, L"Issue");
    wcscat(szIssueKey, szNum);
    wcscpy(szTextKey, L"Text");
    wcscat(szTextKey, szNum);
    
    // we're going to replace the tabs and line feeds in the
    // test string with obscure characters, because the 
    // we can only save one line of text per property in the propbag.
    // and this is easier than saving it out a line at a time.
    if(m_bstrText)
    {
        szNewString = new WCHAR[SysStringLen(m_bstrText) + 1];
        if (szNewString == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto Error;
        }
        wcscpy(szNewString, m_bstrText);
        pc = szNewString;
        while(*pc != '\0')
        {
            if(*pc == L'\r') *pc = L'\xBC';
            if(*pc == L'\n') *pc = L'\xBD';
            if(*pc == L'\t') *pc = L'\xBE';
            pc++;
        }
    }

    bstrIssue = SysAllocString(m_fIssue ? L"Y" : L"N");
    if (bstrIssue == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto Error;
    }
    IfFailGo(pProps->Write(szNameKey, &CComVariant(m_bstrName)));
    IfFailGo(pProps->Write(szIssueKey, &CComVariant(bstrIssue)));
    if(szNewString)
        IfFailGo(pProps->Write(szTextKey, &CComVariant(szNewString)));

Error:
    if(bstrIssue) SysFreeString(bstrIssue);
    if(szNewString) delete [] szNewString;
    return hr;

}

HRESULT CSlnNote::LoadFromStream(CNoteToolWindow* pWin, IStream* pStream)
{
    HRESULT hr = NOERROR;
    m_pToolWin = pWin; // not referenced

    //first load the name
    CComVariant varName;
    CComVariant varIssue;
    CComVariant varText;
    IfFailGo(varName.ReadFromStream(pStream));
    IfFailGo(varIssue.ReadFromStream(pStream));
    IfFailGo(varText.ReadFromStream(pStream));

    IfFailGo(varIssue.ChangeType(VT_BOOL));

    m_bstrName = SysAllocString(varName.bstrVal);
    m_bstrText = SysAllocString(varText.bstrVal);
    m_fIssue = varIssue.boolVal;

    IfFailGo(AddToListBox(m_pToolWin->m_hwndList));

    m_fModified = VARIANT_FALSE;

Error:
    return hr;
}

HRESULT CSlnNote::LoadFromPropBag(CNoteToolWindow* pWin, UINT nKey, IPropertyBag* pProps)
{
    if (!pProps)
        return E_POINTER;
    HRESULT hr = NOERROR;
    m_pToolWin = pWin; // not referenced

    OLECHAR szNameKey[MAX_NAME], szNum[MAX_NAME - 5];
    OLECHAR szIssueKey[MAX_NAME];
    OLECHAR szTextKey[MAX_NAME];
    WCHAR* szNewString = NULL;
    WCHAR* pc = NULL;

    _itow(nKey, szNum, 10);
    wcscpy(szNameKey, L"Name");
    wcscat(szNameKey, szNum);
    wcscpy(szIssueKey, L"Issue");
    wcscat(szIssueKey, szNum);
    wcscpy(szTextKey, L"Text");
    wcscat(szTextKey, szNum);

    CComVariant varName;
    CComVariant varIssue;
    CComVariant varText;
    IfFailGo(pProps->Read(szNameKey, &varName, NULL));
    IfFailGo(pProps->Read(szIssueKey, &varIssue, NULL));

    m_bstrName = SysAllocString(varName.bstrVal);

    // if we were loaded this way we are shared
    m_fShared = VARIANT_TRUE;

    m_fIssue = (wcscmp(varIssue.bstrVal, L"Y") ? VARIANT_FALSE : VARIANT_TRUE);

    //now we have to reconstitute the test
    if(SUCCEEDED(hr = pProps->Read(szTextKey, &varText, NULL)))
    {
        size_t len = SysStringLen(varText.bstrVal);
        szNewString = new WCHAR[len + 1];
        if (szNewString != NULL)
        {
            wcsncpy(szNewString, varText.bstrVal, len);
            szNewString[len] = '\0';
            pc = szNewString;
            while(*pc != '\0')
            {
                if(*pc == L'\xBC') *pc = L'\r';
                if(*pc == L'\xBD') *pc = L'\n';
                if(*pc == L'\xBE') *pc = L'\t';
                pc++;
            }
        }
        m_bstrText = SysAllocString(szNewString);
    }

    IfFailGo(AddToListBox(m_pToolWin->m_hwndList));

    m_fModified = VARIANT_FALSE;
Error:
    if(szNewString) delete [] szNewString;
    return hr;
}

/////////////////////////////////////////////////////////////////////////////
// CSlnNote ISolutionNote Implementation

STDMETHODIMP CSlnNote::get_DTE(_DTE** ppDTE)
{
    return _AtlModule.QueryService(SID_SDTE, IID__DTE, (LPVOID*)ppDTE);
}

STDMETHODIMP CSlnNote::get_Parent(_DTE** ppParent)
{
    return _AtlModule.QueryService(SID_SDTE, IID__DTE, (LPVOID*)ppParent);
}

STDMETHODIMP CSlnNote::get_Collection(ISolutionNotes** ppColl)
{
    return m_pToolWin->QueryInterface(IID_ISolutionNotes, (LPVOID*)ppColl);
}

STDMETHODIMP CSlnNote::get_Name(BSTR* pbstrName)
{
    if(!pbstrName) return E_POINTER;

    *pbstrName = SysAllocString(m_bstrName);
    return NOERROR;
}

STDMETHODIMP CSlnNote::put_Name(BSTR bstrName)
{
    HRESULT hr = NOERROR;

    if (!bstrName || wcslen(bstrName) == 0)
        return E_INVALIDARG;

    if(m_bstrName && !wcscmp(m_bstrName, bstrName)) return NOERROR;

    if(FAILED(hr = ChangeNameInListBox(bstrName)))
        return hr;

    if(m_bstrName) SysFreeString(m_bstrName);
    m_bstrName = SysAllocString(bstrName);

    // fire the event
    m_pToolWin->Fire_NoteRenamed((ISolutionNote*)this, &m_bstrName);

    m_pToolWin->DoSort(0);

    //and don't forget to change the title on the note window
    if(m_srpFrame)
    {
        CComVariant var;
        var = m_bstrName;
        m_srpFrame->SetProperty(VSFPROPID_pszPhysicalView, var);
        m_srpFrame->SetProperty(VSFPROPID_OwnerCaption, var);
    }

    m_fModified = VARIANT_TRUE;

    return NOERROR;
}

STDMETHODIMP CSlnNote::get_IsShared(VARIANT_BOOL* pfShared)
{
    if(!pfShared) return E_POINTER;
    
    *pfShared = m_fShared;
    return NOERROR;
}

STDMETHODIMP CSlnNote::put_IsShared(VARIANT_BOOL fShared)
{
    if(fShared == m_fShared) return NOERROR;

    m_fShared = fShared;

    LVITEM lvi;
    lvi.mask = LVIF_TEXT;
    lvi.iItem = m_idx;
    lvi.pszText = m_fShared ? _T("Yes") : _T("No");
    lvi.iSubItem = 2;
    ListView_SetItem(m_pToolWin->m_hwndList, &lvi);

    m_fModified = VARIANT_TRUE;

    return NOERROR;
}

STDMETHODIMP CSlnNote::get_IsIssue(VARIANT_BOOL* pfIssue)
{
    if(!pfIssue) return E_POINTER;

    *pfIssue = m_fIssue;
    return NOERROR;
}

STDMETHODIMP CSlnNote::put_IsIssue(VARIANT_BOOL fIssue)
{
    if(m_fIssue == fIssue) return NOERROR;

    m_fIssue = fIssue;

    LVITEM lvi;
    lvi.mask = LVIF_IMAGE;
    lvi.iItem = m_idx;
    lvi.iSubItem = 0;
    lvi.iImage = m_fIssue ? 1 : 0;
    ListView_SetItem(m_pToolWin->m_hwndList, &lvi);
    lvi.mask = LVIF_TEXT;
    lvi.pszText = m_fIssue ? _T("Yes") : _T("No");
    lvi.iSubItem = 1;
    ListView_SetItem(m_pToolWin->m_hwndList, &lvi);

    m_fModified = VARIANT_TRUE;

    return NOERROR;
}

STDMETHODIMP CSlnNote::get_Size(long* pSize)
{
    HRESULT hr = NOERROR;

    if(!pSize) return E_POINTER;
    IfFailGo(UpdateText());

    *pSize = (m_bstrText ? SysStringLen(m_bstrText) : 0);

Error:
    return hr;
}

STDMETHODIMP CSlnNote::get_Visible(VARIANT_BOOL* pfVisible)
{
    if(!pfVisible) return E_POINTER;

    if(m_srpFrame && m_srpFrame->IsVisible() == S_OK)
        *pfVisible = VARIANT_TRUE;
    else
        *pfVisible = VARIANT_FALSE;

    return NOERROR;
}

STDMETHODIMP CSlnNote::put_Visible(VARIANT_BOOL fVisible)
{
    HRESULT hr = NOERROR;
    if(fVisible == VARIANT_TRUE)
    {
        if(!m_srpFrame)
        {
            CComPtr<IVsUIShell> srpShell;
            CComPtr<IVsRunningDocumentTable> srpRDT;
            CComPtr<IVsHierarchy> srpHier;
            CComPtr<IUnknown> srpDocData;
            CComPtr<IVsSolution> srpSln;
            CComPtr<ILocalRegistry> srpReg;
            CComPtr<IVsCodeWindow> srpView;
            CComPtr<IVsTextLines> srpLines;
            CComBSTR bstrMkDoc;
            VARIANT var;
            VariantInit(&var);

            IfFailGo(_AtlModule.QueryService(SID_SVsUIShell, IID_IVsUIShell, (void **)&srpShell));
            IfFailGo(_AtlModule.QueryService(SID_SVsRunningDocumentTable, IID_IVsRunningDocumentTable, (LPVOID*)&srpRDT));
            IfFailGo(_AtlModule.QueryService(SID_SVsSolution, IID_IVsSolution, (LPVOID*)&srpSln));
            IfFailGo(_AtlModule.QueryService(SID_SLocalRegistry, IID_ILocalRegistry, (LPVOID*)&srpReg));
            IfFailGo(srpReg->CreateInstance(CLSID_VsCodeWindow, NULL, IID_IVsCodeWindow, CLSCTX_INPROC_SERVER, (LPVOID*)&srpView));
            IfFailGo(srpReg->CreateInstance(CLSID_VsTextBuffer, NULL, IID_IVsTextLines, CLSCTX_INPROC_SERVER, (LPVOID*)&srpLines));

            if(m_bstrText)
            {
                IfFailGo(srpLines->InitializeContent(m_bstrText, SysStringLen(m_bstrText)));
            }

            IfFailGo(srpView->SetBuffer(srpLines));
            IfFailGo(srpSln->QueryInterface(IID_IVsHierarchy, (LPVOID*)&srpHier));
            IfFailGo(srpHier->GetProperty(VSITEMID_ROOT, VSHPROPID_ItemDocCookie, &var));
            IfFailGo(srpRDT->GetDocumentInfo(var.lVal, NULL, NULL, NULL, &bstrMkDoc, NULL, NULL, NULL ));
            IfFailGo(srpLines->QueryInterface(IID_IUnknown, (LPVOID*)&srpDocData));
            IfFailGo(srpShell->CreateDocumentWindow(CDW_fAltDocData , bstrMkDoc, (IVsUIHierarchy*)srpHier.p, VSITEMID_ROOT, srpView, srpDocData, 
                                GUID_NULL, m_bstrName, CMDUIGUID_TextEditor, NULL, m_bstrName, NULL, NULL, &m_srpFrame));
            VariantClear(&var);
            VariantInit(&var);
            V_VT(&var) = VT_UNKNOWN;
            V_UNKNOWN(&var) = (IVsWindowFrameNotify*)this;
            IfFailGo(m_srpFrame->SetProperty(VSFPROPID_ViewHelper, var));
            IfFailGo(m_srpFrame->Show());
            IfFailGo(srpLines->SetStateFlags( (m_fModified == VARIANT_TRUE) ? BSF_MODIFIED : 0));
            return hr;
        }
        
        return m_srpFrame->Show();

    }
    else
    {
        if(m_srpFrame)
        {
            return Close();
        }
    }
    return NOERROR;

Error:
    return hr;
}

HRESULT CSlnNote::get_Modified(VARIANT_BOOL *pfModified)
{
    if(!pfModified) return E_POINTER;

    HRESULT hr = NOERROR;
    *pfModified = m_fModified;

    if(m_fModified == VARIANT_FALSE && m_srpFrame)
    {
        CComPtr<IVsTextLines> srpLines;
        CComQIPtr<IVsCodeWindow> srpView;
        VARIANT varProp;
        DWORD flags;
        
        VariantInit(&varProp);
        IfFailGo(m_srpFrame->GetProperty(VSFPROPID_DocView, &varProp));
        srpView = varProp.punkVal;
        varProp.punkVal->Release();
        if(!srpView) return E_UNEXPECTED;
        IfFailGo(srpView->GetBuffer(&srpLines));
        IfFailGo(srpLines->GetStateFlags(&flags));

        if(flags & BSF_MODIFIED)
            *pfModified = m_fModified = VARIANT_TRUE;
    }

Error:
    return hr;
}

HRESULT CSlnNote::ClearModifiedFlag()
{
    HRESULT hr = NOERROR;

    if(m_srpFrame)
    {
        CComPtr<IVsTextLines> srpLines;
        CComQIPtr<IVsCodeWindow> srpView;
        VARIANT varProp;

        VariantInit(&varProp);
        IfFailGo(m_srpFrame->GetProperty(VSFPROPID_DocView, &varProp));
        srpView = varProp.punkVal;
        varProp.punkVal->Release();
        if(!srpView) return E_UNEXPECTED;

        IfFailGo(srpView->GetBuffer(&srpLines));
        IfFailGo(srpLines->SetStateFlags(0));
    }

    m_fModified = VARIANT_FALSE;
Error:
    return hr;
}

/////////////////////////////////////////////////////////////////////////////
// CSlnNote IVsWindowFrameNotify Implementation
// we only care about the OnShow
STDMETHODIMP CSlnNote::OnShow(FRAMESHOW fShow)
{
    if(fShow == FRAMESHOW_WinHidden)
    {
        UpdateText();
        get_Modified(&m_fModified);
        m_srpFrame.Release();
        return NOERROR;
    }
    
    if(fShow == FRAMESHOW_WinShown)
    {
        //make sure we track the selection
        ListView_SetItemState(m_pToolWin->m_hwndList, m_idx, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED);
        m_pToolWin->DoSelectionChange();
    }

    return NOERROR;
}

STDMETHODIMP CSlnNote::OnMove()
{
    return E_NOTIMPL;
}

STDMETHODIMP CSlnNote::OnSize()
{
    return E_NOTIMPL;
}

STDMETHODIMP CSlnNote::OnDockableChange(BOOL)
{
    return E_NOTIMPL;
}
