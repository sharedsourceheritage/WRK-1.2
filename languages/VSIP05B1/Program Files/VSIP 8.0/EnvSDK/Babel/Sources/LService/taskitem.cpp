/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "textmarker.h"
#include "taskitem.h"

/*---------------------------------------------------------
  TaskItem
-----------------------------------------------------------*/
class TaskItem : public IVsTaskItem
{
private:
  ULONG               m_refCount;
  IServiceProvider*   m_provider;
  IVsTextLineMarker*  m_textLineMarker;

  BSTR                m_tipText;
  BSTR                m_fileName;
  VSTASKPRIORITY      m_priority;
  VSTASKBITMAP        m_bitmap;
  VSTASKCATEGORY      m_category;
  bool                m_checked;
  bool                m_readOnly;

public:
  TaskItem( in IServiceProvider* provider, in IVsTextLineMarker* textLineMarker,
            in const wchar_t* tipText, in const wchar_t* fileName, bool readOnly,
            in VSTASKPRIORITY priority, in VSTASKBITMAP bitmap, in VSTASKCATEGORY category
          );
  ~TaskItem();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  // IVsTaskItem methods:
  STDMETHODIMP get_Priority( out VSTASKPRIORITY* priority );
  STDMETHODIMP put_Priority( in  VSTASKPRIORITY  priority );
 
  STDMETHODIMP get_Checked( out BOOL* checked );
  STDMETHODIMP put_Checked( in  BOOL  checked );

  STDMETHODIMP get_Text( out BSTR* text );
  STDMETHODIMP put_Text( in  BSTR  text );

  STDMETHODIMP get_Category( out VSTASKCATEGORY* category );
  STDMETHODIMP get_Document( out BSTR* documentName );
  STDMETHODIMP get_CanDelete( out BOOL* canDelete );
  STDMETHODIMP get_IsReadOnly( in VSTASKFIELD field, out BOOL* readOnly );
  STDMETHODIMP get_HasHelp( out BOOL* hasHelp );
  
  STDMETHODIMP get_SubcategoryIndex( out long* index );
  STDMETHODIMP get_ImageListIndex( out long* index );
  
  STDMETHODIMP get_Line( out long* line );
  STDMETHODIMP get_Column( out long* column );
  STDMETHODIMP get_EndColumn( out long* column );
  
  STDMETHODIMP NavigateTo( void );
  STDMETHODIMP NavigateToHelp( void );
  
  STDMETHODIMP OnFilterTask( in BOOL visible );
  STDMETHODIMP OnDeleteTask();
};

/*---------------------------------------------------------
  CreateTask
-----------------------------------------------------------*/
HRESULT CreateTask( in IServiceProvider* provider,
                    in IVsTextLines*     textLines,
                    in MARKERTYPE        markerType,                  
                    in BSTR tipText, in const wchar_t* fileName, in bool readOnly,
                    in TextSpan& span,
                    in VSTASKPRIORITY priority, in VSTASKBITMAP bitmap, in VSTASKCATEGORY category,
                    out IVsTaskItem** taskItem
                  )
{
  OUTARG(taskItem);
  REFARG(provider);
  REFARG(textLines);
  HRESULT hr;

  IVsTextLineMarker* textLineMarker =  NULL;
  hr = CreateMarker( textLines, span, tipText, markerType, &textLineMarker );
  if (FAILED(hr)) return hr;

  *taskItem = new TaskItem( provider, textLineMarker, tipText, fileName, readOnly, priority, bitmap, category );
  RELEASE(textLineMarker);
  if (*taskItem == NULL) return E_OUTOFMEMORY;

  return S_OK;
}

/*---------------------------------------------------------
  TaskItem 
-----------------------------------------------------------*/
TaskItem::TaskItem( in IServiceProvider* provider, in IVsTextLineMarker* textLineMarker,
                    in const wchar_t* tipText, in const wchar_t* fileName, in bool readOnly,
                    in VSTASKPRIORITY priority, in VSTASKBITMAP bitmap, in VSTASKCATEGORY category
                  )
{
  TRACE_CREATE_HIDE( "TaskItem", static_cast<IVsTaskItem*>(this) );
  ASSERT(textLineMarker);
  ASSERT(provider);

  m_refCount        = 1;
  m_provider        = provider;       ADDREF(m_provider);
  m_textLineMarker  = textLineMarker; ADDREF(m_textLineMarker);

  m_tipText         = SysAllocString(tipText);
  m_fileName        = SysAllocString(fileName);
  m_priority        = priority;
  m_bitmap          = bitmap;
  m_category        = category;
  m_readOnly        = readOnly;

  m_checked         = false;
}


TaskItem::~TaskItem()
{
  TRACE_DESTROY( static_cast<IVsTaskItem*>(this) );
  bstrFree(m_tipText);
  bstrFree(m_fileName);
  RELEASE(m_textLineMarker);
  RELEASE(m_provider);
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP TaskItem::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsTaskItem)
  {
    //TRACE("TaskItem::QueryInterface for IUnknown/IVsTaskItem");
    *obj = static_cast<IVsTaskItem*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) TaskItem::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) TaskItem::Release()
{
  if (DecRefCount(&m_refCount) == 0)
  {
    delete this;
    return 0;
  }
  else
    return m_refCount;
}

/*---------------------------------------------------------
  IVsTaskItem
-----------------------------------------------------------*/
STDMETHODIMP TaskItem::get_Priority( out VSTASKPRIORITY* priority )
{
  //TRACE("TaskItem::get_Priority");
  if (!priority) return E_INVALIDARG;
  *priority = m_priority;
  return S_OK;
}

STDMETHODIMP TaskItem::put_Priority( in  VSTASKPRIORITY  priority )
{
  //TRACE("TaskItem::get_Priority");
  m_priority = priority;
  return S_OK;
}

STDMETHODIMP TaskItem::get_Checked( out BOOL* checked )
{
  //TRACE("TaskItem::get_Checked");
  OUTARG(checked);
  *checked = m_checked;
  return S_OK;
}

STDMETHODIMP TaskItem::put_Checked( in BOOL checked )
{
  //TRACE("TaskItem::put_Checked");
  if (m_readOnly) return E_NOTIMPL;

  m_checked = (checked != false);
  return S_OK;
}

STDMETHODIMP TaskItem::get_Text( out BSTR* text )
{
  //TRACE("TaskItem::get_Text");
  OUTARG(text);
  *text = SysAllocString(m_tipText);
  return S_OK;
}

STDMETHODIMP TaskItem::put_Text( in BSTR text )
{
  //TRACE("TaskItem::put_Text");
  if (m_readOnly) return E_NOTIMPL;

  bstrFree(m_tipText);
  m_tipText = SysAllocString(text);
  return S_OK;
}

STDMETHODIMP TaskItem::get_Category( out VSTASKCATEGORY* category )
{
  //TRACE("TaskItem::get_Category");
  if (!category) return E_INVALIDARG;
  *category = m_category;
  return S_OK;
}

STDMETHODIMP TaskItem::get_Document( out BSTR* documentName )
{
  //TRACE("TaskItem::get_Document");
  OUTARG(documentName);
  *documentName = SysAllocString( m_fileName );
  return S_OK;
}

STDMETHODIMP TaskItem::get_CanDelete( out BOOL* canDelete )
{
  //TRACE("TaskItem::get_CanDelete");
  OUTARG(canDelete);
  *canDelete = TRUE;
  return S_OK;
}

STDMETHODIMP TaskItem::get_IsReadOnly( in VSTASKFIELD field, out BOOL* readOnly )
{
  //TRACE("TaskItem::get_IsReadOnly");
  OUTARG(readOnly)
  
  switch (field)
  {
    case FLD_CHECKED:     *readOnly = m_readOnly; break;
    case FLD_DESCRIPTION: *readOnly = m_readOnly; break;
    default:              *readOnly = TRUE;       break;
  }
  return S_OK;
}

STDMETHODIMP TaskItem::get_HasHelp( out BOOL* hasHelp )
{
  //TRACE("TaskItem::get_HasHelp");
  OUTARG(hasHelp);
  *hasHelp = FALSE;
  return S_OK;
}

STDMETHODIMP TaskItem::get_SubcategoryIndex( out long* index )
{
  //TRACE("TaskItem::get_SubcategoryIndex");
  OUTARG(index);
  return E_NOTIMPL;
}

STDMETHODIMP TaskItem::get_ImageListIndex( out long* index )
{
  //TRACE("TaskItem::get_ImageListIndex");
  OUTARG(index);
  *index = m_bitmap; 
  return S_OK;
}

STDMETHODIMP TaskItem::get_Line( out long* line )
{
  //TRACE("TaskItem::get_Line");
  OUTARG(line);
  if (!m_textLineMarker) return E_UNEXPECTED;

  HRESULT hr;
  TextSpan span;
  hr = m_textLineMarker->GetCurrentSpan( &span );
  if (FAILED(hr)) return hr;

  *line = span.iStartLine;  
  return S_OK;
}

STDMETHODIMP TaskItem::get_Column( out long* column )
{
  //TRACE("TaskItem::get_Column");
  OUTARG(column);
  if (!m_textLineMarker) return E_UNEXPECTED;

  HRESULT hr;
  TextSpan span;
  hr = m_textLineMarker->GetCurrentSpan( &span );
  if (FAILED(hr)) return hr;

  *column = span.iStartIndex;  
  return S_OK;
}

STDMETHODIMP TaskItem::get_EndColumn( out long* column )
{
  //TRACE("TaskItem::get_EndColumn");
  OUTARG(column);
  if (!m_textLineMarker) return E_UNEXPECTED;

  HRESULT hr;
  TextSpan span;
  hr = m_textLineMarker->GetCurrentSpan( &span );
  if (FAILED(hr)) return hr;

  *column = span.iEndIndex;  
  return S_OK;
}

STDMETHODIMP TaskItem::NavigateTo( void )
{
  //TRACE("TaskItem::NavigateTo");
  if (!m_textLineMarker) return E_UNEXPECTED;

  HRESULT hr;
  TextSpan span;
  hr = m_textLineMarker->GetCurrentSpan( &span );
  if (FAILED(hr)) return hr;
  
  IVsWindowFrame* docFrame = NULL;
  IVsTextView*    textView = NULL;
  hr = OpenDocument( m_provider, m_fileName, NULL, NULL, &docFrame, &textView );
  if (FAILED(hr)) return hr;

  hr = docFrame->Show();
  RELEASE(docFrame);
  if (FAILED(hr)) { RELEASE(textView); return hr; }

  textView->SetCaretPos( span.iStartLine, span.iStartIndex );
  textView->SetSelection( span.iStartLine, span.iStartIndex, span.iEndLine, span.iEndIndex );
  
  hr = textView->EnsureSpanVisible( span );
  RELEASE(textView);
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP TaskItem::NavigateToHelp( void )
{
  //TRACE("TaskItem::NavigateToHelp");
  return E_NOTIMPL;
}

STDMETHODIMP TaskItem::OnFilterTask( in BOOL visible )
{
  //TRACE("TaskItem::OnFilterTask");
  return S_OK;
}

STDMETHODIMP TaskItem::OnDeleteTask()
{
  //TRACE("TaskItem::OnDeleteTask");
  RELEASE(m_textLineMarker);
  return S_OK;
}
