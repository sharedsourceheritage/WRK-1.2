/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef taskprovider_h
#define taskprovider_h

class TaskTokens;

/*---------------------------------------------------------
  TaskProvider
-----------------------------------------------------------*/
class TaskProvider : public IVsTaskProvider,
                     public IVsTaskListEvents
{
private:
  ULONG             m_refCount;
  
  ObjectList*       m_taskItems;
  IVsTaskList*      m_taskList;
  TaskTokens*       m_taskTokens;

#ifdef VS6SDK
  DWORD             m_taskListConnect;
#else
  VSCOOKIE          m_taskListConnect;
#endif

  
public:
  TaskProvider();
  ~TaskProvider();

  STDMETHODIMP Init( in IServiceProvider* provider );
  STDMETHODIMP Done();

  //TaskProvider
  STDMETHODIMP RefreshTasks( in IServiceProvider* provider,
                             in IVsTextLines*     textLines, 
                             in ObjectList*       errorInfos );
  STDMETHODIMP RemoveErrorTasks();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IVsTaskProvider
  STDMETHODIMP EnumTaskItems( out IVsEnumTaskItems **taskItems );
  STDMETHODIMP OnTaskListFinalRelease( in IVsTaskList* taskList );

  STDMETHODIMP get_ImageList( out HANDLE *imageList );
  STDMETHODIMP get_SubcategoryList( in ULONG index, out BSTR names[], out ULONG* actual );
  STDMETHODIMP get_ReRegistrationKey( out BSTR* key );

  //IVsTaskListEvents
  STDMETHODIMP OnCommentTaskInfoChanged();
};

#endif
