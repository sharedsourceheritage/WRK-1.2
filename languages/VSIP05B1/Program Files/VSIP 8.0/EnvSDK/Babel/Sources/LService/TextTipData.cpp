/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "TextTipData.h"


CTextTipData::CTextTipData ()
: 
    m_pIVsTextTipWindow(NULL), 
    m_fWindowUp(FALSE),
    m_refCount(0),
    m_bstrText(NULL)
{
}


HRESULT CTextTipData::Init(
    IServiceProvider* pIServiceProvider,
    IVsTextView *     pView)
{
    if (!pView)
        return E_INVALIDARG;

    m_pIVsTextView = pView;

    // Create our method tip window (through the local registry)
    HRESULT hr = ProviderCreateInstance(
        pIServiceProvider, 
        CLSID_VsTextTipWindow,
        IID_IVsTextTipWindow, 
        (void**)(&m_pIVsTextTipWindow));
    if (FAILED(hr)) 
        return hr;
    
    if (!m_pIVsTextTipWindow)
        return E_FAIL;

    hr = m_pIVsTextTipWindow->SetTextTipData(this);
    if (FAILED(hr)) 
        return hr;
 
    return hr;
}



CTextTipData::~CTextTipData ()
{
    Close();
}


void CTextTipData::Close()
{
    Dismiss();
    if (m_pIVsTextTipWindow != NULL) 
    {
        m_pIVsTextTipWindow->Release();
        m_pIVsTextTipWindow = NULL;
    }
    bstrFree(m_bstrText);
}


////////////////////////////////////////////////////////////////////////////////
// CTextTipData::Update

HRESULT CTextTipData::Update(
    PCWSTR pszText, 
    long iPos, 
    long iLen)
{
    HRESULT     hr;

    m_iPos = iPos;
    m_iLen = iLen;

    bstrFree(m_bstrText);
    m_bstrText = ::SysAllocString(pszText);
    if (0==SysStringLen(m_bstrText))
        return E_FAIL;

    IVsTextView* pView = GetIVsTextView();
    if (!pView)
        return E_UNEXPECTED;

    hr = pView->UpdateTipWindow(m_pIVsTextTipWindow, UTW_CONTEXTCHANGED | UTW_CONTENTCHANGED);
    m_fWindowUp = SUCCEEDED (hr);

    return hr;
}


////////////////////////////////////////////////////////////////////////////////
// CTextTipData::CheckCaretPosition

void CTextTipData::CheckCaretPosition ()
{
    long    iLine, iCol, iPos, iSpace;

    if (FAILED (m_pIVsTextView->GetCaretPos (&iLine, &iCol)) ||
        FAILED (m_pIVsTextView->GetNearestPosition (iLine, iCol, &iPos, &iSpace)) ||
        (iPos < m_iPos || iPos > m_iPos + m_iLen))
    {
        m_pIVsTextView->UpdateTipWindow (m_pIVsTextTipWindow, UTW_DISMISS);
    }
}

////////////////////////////////////////////////////////////////////////////////
// CTextTipData::Dismiss

void CTextTipData::Dismiss ()
{
    if (m_fWindowUp)
        m_pIVsTextView->UpdateTipWindow (m_pIVsTextTipWindow, UTW_DISMISS);
}

////////////////////////////////////////////////////////////////////////////////
// CTextTipData::GetTipText

STDMETHODIMP CTextTipData::GetTipText (BSTR *pbstrText, BOOL *pfFontData)
{
    if (pbstrText == NULL)
        return E_INVALIDARG;

    if (pfFontData != NULL)
        *pfFontData = FALSE;        // UNDONE:  Do whatever formatting we might want...

    *pbstrText = ::SysAllocString(m_bstrText);
    if (*pbstrText == NULL)
        return E_OUTOFMEMORY;

    return S_OK;
}

////////////////////////////////////////////////////////////////////////////////
// CTextTipData::GetTipFontInfo

STDMETHODIMP CTextTipData::GetTipFontInfo (long iChars, ULONG *pdwFontInfo)
{
    return E_NOTIMPL;
}

////////////////////////////////////////////////////////////////////////////////
// CTextTipData::GetContextStream

STDMETHODIMP CTextTipData::GetContextStream (long *piPos, long *piLen)
{
    *piPos = m_iPos;
    *piLen = m_iLen;
    return S_OK;
}

////////////////////////////////////////////////////////////////////////////////
// CTextTipData::OnDismiss

STDMETHODIMP_(void) CTextTipData::OnDismiss ()
{
    m_fWindowUp = FALSE;
}

////////////////////////////////////////////////////////////////////////////////
// CTextTipData::UpdateView

STDMETHODIMP_(void) CTextTipData::UpdateView ()
{
}


STDMETHODIMP_(ULONG) CTextTipData::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CTextTipData::Release()
{
  if (DecRefCount(&m_refCount) == 0)
  {
    delete this;
    return 0;
  }
  else
    return m_refCount;
}


HRESULT CTextTipData::QueryInterface(REFIID riid, void **ppvObject)
{
    *ppvObject = NULL;

    if ((IID_IUnknown == riid)
        || (IID_IVsTextTipData == riid))
    {
        *ppvObject = (IVsTextTipData*) this;
        AddRef();
        return S_OK;
    }

    return E_NOINTERFACE;
}
