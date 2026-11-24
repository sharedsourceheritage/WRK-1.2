/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "tasktokens.h"
#include "taskprovider.h"
#include "errorinfo.h"

/*---------------------------------------------------------
  EnumTaskItems
-----------------------------------------------------------*/
class EnumTaskItems : public IVsEnumTaskItems
{
private:
  ULONG        m_refCount;
  ObjectList*  m_taskItems;
  ObjectElem*  m_current;
  bool         m_reset;

public:
  EnumTaskItems( in ObjectList* taskItems );
  ~EnumTaskItems();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IVsTaskItemEnum
  STDMETHODIMP Next( in ULONG count, out IVsTaskItem** elems, out ULONG* fetched );
  STDMETHODIMP Skip( in ULONG count );
  STDMETHODIMP Reset( void );
  STDMETHODIMP Clone( out IVsEnumTaskItems** clone );
};


/*---------------------------------------------------------
  TaskProvider 
-----------------------------------------------------------*/
TaskProvider::TaskProvider()
{
  TRACE_CREATE( "TaskProvider", static_cast<IVsTaskProvider*>(this) );
  m_refCount        = 1;

  m_taskItems       = NULL;
  m_taskList        = NULL;
  m_taskListConnect = 0;  
  m_taskTokens      = NULL;
}


TaskProvider::~TaskProvider()
{
  TRACE_DESTROY( static_cast<IVsTaskProvider*>(this) );
  Done();  
}

STDMETHODIMP TaskProvider::Init( in IServiceProvider* provider )
{
  REFARG(provider);
  HRESULT hr;

  if (!m_taskList)
  {
    hr = provider->QueryService( SID_SVsTaskList, IID_IVsTaskList, reinterpret_cast<void**>(&m_taskList) );
    if (FAILED(hr)) return hr;
  }

  if (!m_taskListConnect)
  {
    hr = m_taskList->RegisterTaskProvider( static_cast<IVsTaskProvider*>(this), &m_taskListConnect );
    if (FAILED(hr)) return hr;
  }

  if (!m_taskTokens)
  {
    m_taskTokens = new TaskTokens( provider );
    if (!m_taskTokens) return E_OUTOFMEMORY;

    hr = m_taskTokens->Refresh();
    ASSERT(SUCCEEDED(hr));
  }

  return S_OK;
}

STDMETHODIMP TaskProvider::Done()
{
  RefreshTasks( NULL, NULL, NULL );

  if (m_taskListConnect)
  {
    m_taskList->UnregisterTaskProvider( m_taskListConnect );
    m_taskListConnect = 0;
  }

  RELEASE(m_taskList);
  RELEASE(m_taskTokens); 
  return S_OK;
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP TaskProvider::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsTaskProvider)
  {
    TRACE("TaskProvider::QueryInterface for IUnknown/IVsTaskProvider");
    *obj = static_cast<IVsTaskProvider*>(this);
  }
  else if (iid == IID_IVsTaskListEvents)
  {
    TRACE("TaskProvider::QueryInterface for IVsTaskListEvents");
    *obj = static_cast<IVsTaskListEvents*>(this);
  }
  else 
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) TaskProvider::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) TaskProvider::Release()
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
  TaskProvider
-----------------------------------------------------------*/
STDMETHODIMP TaskProvider::RefreshTasks( in IServiceProvider* provider,
                                         in IVsTextLines*     textLines, 
                                         in ObjectList*       errorInfos )
{
  TRACE("TaskProvider::RefreshTasks");
  if (!m_taskList || !m_taskListConnect) return E_UNEXPECTED;
  HRESULT hr = S_OK;

  //get file name
  BSTR fileName = NULL;
  if (textLines) hr = GetFilePath( textLines, &fileName );
            else hr = E_FAIL;
  if (FAILED(hr)) 
  {
      fileName = SysAllocString(L"<unknown>");
    if (!fileName) return E_OUTOFMEMORY;
  }

  //create a fresh task item list
  RELEASE(m_taskItems);     //release and remove all task items
  if (errorInfos == NULL || errorInfos->GetCount() == 0) { hr = S_OK; goto refresh; }

  m_taskItems = new ObjectList();
  if (!m_taskItems) { hr = E_OUTOFMEMORY; goto refresh; }

  //create task items
  ObjectElem* current;
  ErrorInfo*  errorInfo;
  for( errorInfos->GetFirst( &current, reinterpret_cast<IUnknown**>(&errorInfo) ); errorInfo; errorInfos->GetNext( &current, reinterpret_cast<IUnknown**>(&errorInfo) ) )
  {
    IVsTaskItem* taskItem;
    
    hr = errorInfo->CreateTask( provider, m_taskTokens, fileName, textLines, &taskItem );
    if (FAILED(hr)) goto refresh; 
    if (hr != S_OK) { RELEASE(taskItem); continue; }

    hr = m_taskItems->Insert( taskItem );
    RELEASE(taskItem);
    if (FAILED(hr)) goto refresh; 
  }

  //refresh task list (calls EnumTaskItems)
refresh:
  bstrFree(fileName);
  if (FAILED(hr)) { RELEASE(m_taskItems); }
  m_taskList->RefreshTasks( m_taskListConnect );
  if (FAILED(hr)) return hr;

  return S_OK;
}

STDMETHODIMP TaskProvider::RemoveErrorTasks()
{
  //TRACE("TaskProvider::RemoveErrorTasks");
  HRESULT hr = S_OK;
  
  if (!m_taskList || !m_taskListConnect || !m_taskItems) return S_OK;
  
  //create a fresh task item list
  ObjectList* taskItems = new ObjectList();
  if (!taskItems) return E_OUTOFMEMORY;
  
  //only retain comment tasks
  ObjectElem* current;
  IVsTaskItem* taskItem;
  for (m_taskItems->GetFirst( &current, reinterpret_cast<IUnknown**>(&taskItem)); taskItem; m_taskItems->GetNext( &current, reinterpret_cast<IUnknown**>(&taskItem)) )
  {
    long         lbitmap;
    VSTASKBITMAP bitmap;
    hr = taskItem->get_ImageListIndex( &lbitmap );
    bitmap = static_cast<VSTASKBITMAP>(lbitmap);
    if (FAILED(hr)) { RELEASE(taskItems); return hr; }

    if (bitmap == BMP_COMMENT)    //hmm, dubious way of recognising comment tasks
    {
      hr = taskItems->Insert( taskItem );
      if (FAILED(hr)) { RELEASE(taskItems); return hr; }
    }
  }

  //refresh the task list
  RELEASE(m_taskItems);
  if (taskItems->GetCount() == 0)
  {
    m_taskItems = NULL; RELEASE(taskItems);
  }
  else
  {
    m_taskItems = taskItems;
  }

  m_taskList->RefreshTasks( m_taskListConnect );
  return S_OK;
}



/*---------------------------------------------------------
  IVsTaskProvider
-----------------------------------------------------------*/
STDMETHODIMP TaskProvider::EnumTaskItems( out IVsEnumTaskItems **taskItems )
{
  //TRACE("TaskProvider::EnumTaskItems");
  OUTARG(taskItems);
  
  *taskItems = new ::EnumTaskItems( m_taskItems );
  if (*taskItems == NULL) return E_OUTOFMEMORY;

  return S_OK;
}

STDMETHODIMP TaskProvider::OnTaskListFinalRelease( in IVsTaskList* taskList )
{
  TRACE("TaskProvider::OnTaskFinalRelease");
  REFARG(taskList);
  ASSERT(SameObject(taskList,m_taskList));

  return Done();
}

STDMETHODIMP TaskProvider::get_ImageList( out HANDLE *imageList )
{
  TRACE("TaskProvider::get_ImageList");
  OUTARG(imageList);
  return S_OK;
}

STDMETHODIMP TaskProvider::get_SubcategoryList( in ULONG index, out BSTR names[], out ULONG* actual )
{
  TRACE("TaskProvider::get_SubcategoryList");
  if (index == 0 && names == NULL) 
  {
    *actual = 1;
  }
  else
  {
    if (index != 1) return E_INVALIDARG;
    names[0] = SysAllocString( L"error" );
    *actual  = 1;
  }

  return S_OK;
}

STDMETHODIMP TaskProvider::get_ReRegistrationKey( out BSTR* key )
{
  TRACE("TaskProvider::get_ReRegistrationKey");
  OUTARG(key);
  return E_NOTIMPL;
}

/*---------------------------------------------------------
  IVsTaskListEvents
-----------------------------------------------------------*/
STDMETHODIMP TaskProvider::OnCommentTaskInfoChanged()
{
  TRACE("TaskProvider::OnCommentTaskInfoChanged");
  if (!m_taskTokens) return E_UNEXPECTED;
  HRESULT hr;

  hr = m_taskTokens->Refresh();
  if (FAILED(hr)) return hr;

  return S_OK;
}



/*---------------------------------------------------------
  EnumTaskItems 
-----------------------------------------------------------*/
EnumTaskItems::EnumTaskItems( in ObjectList* taskItems )
{
  TRACE_CREATE_HIDE( "EnumTaskItems", static_cast<IVsEnumTaskItems*>(this) );
  
  m_refCount    = 1;
  m_taskItems   = NULL;
  m_current     = NULL;
  m_reset       = true;

  if (taskItems)
  {
    m_taskItems   = taskItems; ADDREF(m_taskItems);
  }

  Reset();
}


EnumTaskItems::~EnumTaskItems()
{
  TRACE_DESTROY( static_cast<IVsEnumTaskItems*>(this) );
  RELEASE(m_taskItems);  
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP EnumTaskItems::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IVsEnumTaskItems)
  {
    TRACE("EnumTaskItems::QueryInterface for IUnknown/IVsEnumTaskItems");
    *obj = static_cast<IVsEnumTaskItems*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) EnumTaskItems::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) EnumTaskItems::Release()
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
  IVsEnumTaskItems
-----------------------------------------------------------*/
STDMETHODIMP EnumTaskItems::Next( in ULONG count, out IVsTaskItem** elems, out ULONG* fetched )
{  
  //TRACE1("EnumTaskItems::Next: %i", count );
  REFARG(elems);
  if (fetched) *fetched = 0;
  if (!m_taskItems) return S_FALSE;

  for( ULONG idx = 0; idx < count; idx += 1)
  {
    IVsTaskItem* taskItem;

    if (m_reset)
    {
      m_taskItems->GetFirst( &m_current, reinterpret_cast<IUnknown**>(&taskItem) );
      m_reset = false;
    }
    else 
      m_taskItems->GetNext( &m_current, reinterpret_cast<IUnknown**>(&taskItem) );

    if (!taskItem) return S_FALSE; 

    elems[idx] = taskItem; ADDREF(taskItem);
    if (fetched) *fetched = idx+1;
  }

  return S_OK;
}

STDMETHODIMP EnumTaskItems::Skip( in ULONG count )
{
  TRACE("EnumTaskItems::Skip");
  if (!m_taskItems) return S_FALSE;

  for( ULONG idx = 0; idx < count; idx++ )
  {
    IVsTaskItem* taskItem;
  
    if (m_reset)
    {
      m_taskItems->GetNext( &m_current, reinterpret_cast<IUnknown**>(&taskItem) );
      m_reset = false;
    }
    else
      m_taskItems->GetFirst( &m_current, reinterpret_cast<IUnknown**>(&taskItem) );

    if (!taskItem) return S_FALSE;
  }

  return S_OK;
}

STDMETHODIMP EnumTaskItems::Reset( void )
{
  //TRACE("EnumTaskItems::Reset");

  m_current = NULL;
  m_reset   = true;
  return S_OK;
}

STDMETHODIMP EnumTaskItems::Clone( out IVsEnumTaskItems** clone )
{
  TRACE("EnumTaskItems::Clone");
  OUTARG(clone);

  EnumTaskItems* taskItems = new EnumTaskItems( m_taskItems );
  if (!taskItems) return E_OUTOFMEMORY;

  taskItems->m_current = m_current;
  taskItems->m_reset   = m_reset;
  *clone = static_cast<IVsEnumTaskItems*>(taskItems);

  return S_OK;
}

