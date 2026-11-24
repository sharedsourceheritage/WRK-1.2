//---------------------------------------------------------------------------
//
// Microsoft Visual Studio
//
// Copyright (c) 1998-2000 Microsoft Corporation Inc.
// All rights reserved
//
// HierTaskList.h  - Implements a generic task items and task enumerator
//
//---------------------------------------------------------------------------
#include "hu_pch.h"
#include "hiertasklist.h"
#include "helpsys.h"
#include <vshelp.h>
//=============================================================================
// CHierTaskItemBase
//=============================================================================
CHierTaskItemBase::CHierTaskItemBase()
{

}

//-----------------------------------------------------------------------------
// get_Priority. Default returns TP_NORMAL. Override to set your own priority
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_Priority(VSTASKPRIORITY *ptpPriority)
{
    ASSERT(ptpPriority);
    HRESULT hr = E_INVALIDARG;
    if(ptpPriority)
    {
        *ptpPriority = TP_NORMAL;
        hr = S_OK;
    }
    return hr;
}

//-----------------------------------------------------------------------------
// put_Priority. Don't support changing this. Override if necessary
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::put_Priority(VSTASKPRIORITY tpPriority)
{
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// get_Category. Default returns CAT_MISC. Override to set your own category.
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_Category(VSTASKCATEGORY *pCat)
{
    ASSERT(pCat);
    HRESULT hr = E_INVALIDARG;
    if(pCat)
    {
        *pCat = CAT_MISC;
        hr = S_OK;
    }
    return hr;
}

//-----------------------------------------------------------------------------
// get_SubcategoryIndex
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_SubcategoryIndex(long *pIndex)
{
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// get_ImageListIndex
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_ImageListIndex(long *pIndex)
{
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// get_Checked. Override to support
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_Checked(BOOL *pfChecked)
{
    ASSERT(pfChecked);
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// put_Checked. Override to support
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::put_Checked(BOOL fChecked)
{
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// get_Text. Returns the text description
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_Text(BSTR *pbstrText)
{
    ASSERT(pbstrText);
    HRESULT hr = E_INVALIDARG;
    if(pbstrText)
    {
        hr = S_OK;
        *pbstrText = m_strText.AllocSysString();
        if(*pbstrText == NULL)
            hr = E_OUTOFMEMORY;
    }
    return hr;
}

//-----------------------------------------------------------------------------
// put_Text. Set's the description
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::put_Text(BSTR bstrName)
{
    ASSERT(bstrName);
    HRESULT hr = E_INVALIDARG;
    if(bstrName)
    {
        m_strText = bstrName;
        hr = S_OK;
    }
    return hr;
}

//-----------------------------------------------------------------------------
// get_Document. Override to return document path
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_Document(BSTR *pbstrMkDocument)
{
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// get_Line. Override to support
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_Line(long *piLine)
{
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// get_Column. Override to support
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_Column(long *piCol)
{
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// get_CanDelete. Default returns FALSE. Override to change
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_CanDelete(BOOL *pfCanDelete)
{
    ASSERT(pfCanDelete);
    HRESULT hr = E_INVALIDARG;
    if(pfCanDelete)
    {
        hr = S_OK;
        *pfCanDelete = FALSE;
    }
    return hr;
}

//-----------------------------------------------------------------------------
// get_IsReadOnly. Default assumes all fields are readonly. Override to change
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_IsReadOnly(VSTASKFIELD field, BOOL *pfReadOnly)
{
    ASSERT(pfReadOnly);
    HRESULT hr = E_INVALIDARG;
    if(pfReadOnly)
    {
        hr = S_OK;
        *pfReadOnly = TRUE;
    }
    return hr;
}

//-----------------------------------------------------------------------------
// get_HasHelp. Returns TRUE if the help keyword has been set.
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::get_HasHelp(BOOL *pfHasHelp)
{
    ASSERT(pfHasHelp);
    HRESULT hr = E_INVALIDARG;
    if(pfHasHelp)
    {
        hr = S_OK;
        *pfHasHelp = !m_strHelpKeyword.IsEmpty();
    }
    return hr;
}

//-----------------------------------------------------------------------------
// NavigateTo. Default does nothing
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::NavigateTo()
{
    HRESULT hr = E_NOTIMPL;
    return hr;
}

//-----------------------------------------------------------------------------
// NavigateToHelp
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::NavigateToHelp()
{
    if(!m_strHelpKeyword.IsEmpty())
    {   
        // Call the help system
        CComPtr<IVsHelp> srpIVsHelp;
        if(SUCCEEDED(_VxModule.QueryService(SID_SVsHelp, IID_IVsHelp, (void**) &srpIVsHelp)))
        {
            CComBSTR bstrHelpKeyword = m_strHelpKeyword;
            srpIVsHelp->DisplayTopicFromF1Keyword(bstrHelpKeyword);
        }
    }
    return S_OK;
}

//-----------------------------------------------------------------------------
// OnFilterTask
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::OnFilterTask(BOOL fVisible)
{
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// OnDeleteTask. Must remove ourself from the list of 
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::OnDeleteTask()
{
    return E_NOTIMPL;
}

//-----------------------------------------------------------------------------
// IVsProvideUserContext - by pushing user context to dynamic help allows the error
// help to appear in the dynmaic help window and also enables F1 on the task item
//-----------------------------------------------------------------------------
STDMETHODIMP CHierTaskItemBase::GetUserContext(IVsUserContext** ppUserContext) 
{ 
    ASSERT(ppUserContext);
    HRESULT hr = E_NOTIMPL;
    if(ppUserContext) 
    {
        *ppUserContext = NULL;
        // Only push user context if we have help
        if(!m_strHelpKeyword.IsEmpty())
        {
            CComPtr<IVsMonitorUserContext> srpMonitorUserContext;
            if(SUCCEEDED(_VxModule.QueryService(SID_SVsMonitorUserContext, IID_IVsMonitorUserContext, (void **)&srpMonitorUserContext)))
            {
                srpMonitorUserContext->CreateEmptyContext(ppUserContext);

                if(*ppUserContext) 
                {   //Add the helpkeyword attribute to the new context 
#ifdef UNICODE
                    (*ppUserContext)->AddAttribute(VSUC_Usage_LookupF1, L"keyword", m_strHelpKeyword); 
#else
                    USES_CONVERSION;
                    (*ppUserContext)->AddAttribute(VSUC_Usage_LookupF1, L"keyword", T2OLE(m_strHelpKeyword)); 
#endif
                    hr = S_OK;
                } 
            }
        } 
    } 
    else
    {
        hr = E_INVALIDARG;
    }
    return hr; 
} 

//=============================================================================
// CHierEnumTaskItems
//=============================================================================
CHierEnumTaskItems::CHierEnumTaskItems() 
 : m_pTaskItemArray(NULL),
   m_index(0)
{
}

//-----------------------------------------------------------------------------
// Cleanup
//-----------------------------------------------------------------------------
CHierEnumTaskItems::~CHierEnumTaskItems()
{
    if(m_pTaskItemArray)
    {   // Release all the task items and then nuke the array
        for(int i=0; i< m_pTaskItemArray->GetSize(); i++)
            m_pTaskItemArray->GetAt(i)->Release();
        delete m_pTaskItemArray;
    }
}

//-----------------------------------------------------------------------------
// Initialize the enumerator. Note that the enumerator takes ownership of the
// task array.
//-----------------------------------------------------------------------------
void CHierEnumTaskItems::Init(CIVsTaskItemArray* pTaskItemArray)
{   // Takes ownership of the array
    ASSERT(m_pTaskItemArray == NULL);
    m_pTaskItemArray = pTaskItemArray;
    m_index = 0;
}

//-----------------------------------------------------------------------------
// Next
//-----------------------------------------------------------------------------
STDMETHODIMP CHierEnumTaskItems::Next(ULONG celt, IVsTaskItem **rgelt, ULONG *pceltFetched)
{
    ASSERT(m_pTaskItemArray);
    HRESULT       hr = S_OK;
    unsigned long count = 0;
    while(count < celt && (m_index < m_pTaskItemArray->GetSize()))
    {
        rgelt[count] = m_pTaskItemArray->GetAt(m_index);
        ASSERT(rgelt[count]);
        rgelt[count]->AddRef();
        count++;
        m_index++;
    }

    // Only if a valid pceltFetched is provided do we update it
    if(pceltFetched)
        *pceltFetched = count;

    // We don't have anything left to enumerate
    if(count == 0)
        hr = S_FALSE;

    return hr;
}

//-----------------------------------------------------------------------------
// Skip
//-----------------------------------------------------------------------------
STDMETHODIMP CHierEnumTaskItems::Skip(ULONG celt)
{
    ASSERT(m_pTaskItemArray);
    HRESULT hr = E_UNEXPECTED;
    if(m_pTaskItemArray)
    {
        m_index += celt;
        if(m_index > m_pTaskItemArray->GetSize())
            m_index = m_pTaskItemArray->GetSize();

        hr = S_OK;
    }
    return hr;
}

//-----------------------------------------------------------------------------
// Reset
//-----------------------------------------------------------------------------
STDMETHODIMP CHierEnumTaskItems::Reset(void)
{
    m_index = 0;
    return S_OK;
}

//-----------------------------------------------------------------------------
// Clone
//-----------------------------------------------------------------------------
STDMETHODIMP CHierEnumTaskItems::Clone(IVsEnumTaskItems **ppenum)
{
    CComObject<CHierEnumTaskItems>* pEnum = NULL;
    HRESULT hr = CComObject<CHierEnumTaskItems>::CreateInstance(&pEnum);
    if(SUCCEEDED(hr))
    {
        pEnum->AddRef();
        hr = E_OUTOFMEMORY;
        CIVsTaskItemArray* pItemArray = new CIVsTaskItemArray;
        if(pItemArray)
        {   // Set the size correctly. Make sure it worked
            pItemArray->SetSize(m_pTaskItemArray->GetSize());
            if(pItemArray->GetSize() == m_pTaskItemArray->GetSize())
            {
                for(int i=0; i< m_pTaskItemArray->GetSize(); i++)
                {   // Add each item
                    IVsTaskItem* pItem = m_pTaskItemArray->GetAt(i);
                    pItemArray->SetAt(i, pItem);
                    pItem->AddRef();
                }
                hr = S_OK;
                // Initialize the enumerator
                pEnum->Init(pItemArray);
                pEnum->Skip(m_index);
            }
            else
            {
                delete pItemArray;
            }
        }
        if(SUCCEEDED(hr))
            hr = pEnum->QueryInterface(IID_IVsEnumTaskItems, (void**)ppenum);
        // Release our hold on the enum
        pEnum->Release();
    }
    return hr;
}

// End of hiertasklist.cpp

