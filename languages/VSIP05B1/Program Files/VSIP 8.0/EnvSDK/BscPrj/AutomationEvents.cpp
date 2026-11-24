
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


/***************************************************************************
File name   : AutomationEvents.cpp
Description : Implementation of the following automation events:
              1) class CProxy_dispProjectItemsEvents
              2) class CProxy_dispProjectsEvents
              3) class CProjectsEventsContainer
              4) class CProjectItemsEventsContainer
              5) class CAutomationEvents 
***************************************************************************/

#include "stdafx.h"
#include "PrjInc.h"
#include "PrjNRoot.h"


static CComObject<CAutomationEvents> * s_pCAutomationEvents = NULL;

///////////////////////////////////////////////////////////////////////////
//                                                   Proxy template classes

template <typename T>
class CProxy_dispProjectItemsEvents : 
    public IConnectionPointImpl<T, &DIID__dispProjectItemsEvents, CComDynamicUnkArray>
{
public:
	VOID Fire_ItemAdded(ProjectItem * pProjectItem)
	{
        if (!pProjectItem)
            return;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
        if (!pvars)
            return;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[0] = ((IDispatch*)pProjectItem);
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				HRESULT hr = pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_ItemRemoved(ProjectItem * pProjectItem)
	{
        if (!pProjectItem)
            return;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
        if (!pvars)
            return;

		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
                pvars[0] = ((IDispatch*)pProjectItem);
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_ItemRenamed(ProjectItem * pProjectItem, BSTR OldName)
	{
        if (!pProjectItem)
            return;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
        if (!pvars)
            return;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
        pvars[1] = ((IDispatch*)pProjectItem);
				pvars[0] = OldName;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
};

template <typename T>
class CProxy_dispProjectsEvents : 
    public IConnectionPointImpl<T, &DIID__dispProjectsEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:
	VOID Fire_ItemAdded(Project * pProject)
	{
        if (!pProject)
            return;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
        if (!pvars)
            return;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[0] = ((IDispatch*)pProject);
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_ItemRemoved(Project * pProject)
	{
        if (!pProject)
            return;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
        if (!pvars)
            return;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[0] = ((IDispatch*)pProject);
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_ItemRenamed(Project * pProject, BSTR OldName)
	{
        if (!pProject)
            return;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
        if (!pvars)
            return;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = ((IDispatch*)pProject);
				pvars[0] = OldName;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
};

//                                                   Proxy template classes
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//                                                 CProjectsEventsContainer 

class ATL_NO_VTABLE CProjectsEventsContainer :
    public CComObjectRootEx<CComMultiThreadModel>,
    public IDispatchImpl<_ProjectsEvents, &IID__ProjectsEvents, &LIBID_DTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>,
    public IProvideClassInfo2Impl<&CLSID_ProjectsEvents, &DIID__dispProjectsEvents, &LIBID_DTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>,
    public CProxy_dispProjectsEvents<CProjectsEventsContainer>,
    public IConnectionPointContainerImpl<CProjectsEventsContainer>
{
public:
    BEGIN_COM_MAP(CProjectsEventsContainer)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(_ProjectsEvents)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
        COM_INTERFACE_ENTRY(IProvideClassInfo2)
        COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
    END_COM_MAP()

    BEGIN_CONNECTION_POINT_MAP(CProjectsEventsContainer)    
        CONNECTION_POINT_ENTRY(DIID__dispProjectsEvents)
    END_CONNECTION_POINT_MAP()

    CProjectsEventsContainer();
    ~CProjectsEventsContainer();
    void FinalRelease();
  
    void FireEvent(DISPID dispid, BSTR bstr, Project *pProject);
};

CContainerList<CProjectsEventsContainer>* Add(CContainerList<CProjectsEventsContainer>* pHead, CProjectsEventsContainer* pCProjectsEventsContainer)
{
  CContainerList<CProjectsEventsContainer>* pContainerList = new CContainerList<CProjectsEventsContainer>;
  if (!pContainerList)
      return pHead;
  pContainerList->m_pNext = pHead;
  pContainerList->Set(pCProjectsEventsContainer);
  return pContainerList;
}

CContainerList<CProjectsEventsContainer>* FindAndRemove(CContainerList<CProjectsEventsContainer>* pHead, CProjectsEventsContainer* pCProjectsEventsContainer)
{
  if (pHead == NULL)
      return NULL;
  if (pCProjectsEventsContainer == NULL)
      return pHead;
  CContainerList<CProjectsEventsContainer>* pList = pHead;
  CContainerList<CProjectsEventsContainer>* pTemp;
  if (pHead->Get() == pCProjectsEventsContainer)
  {
    pList = pHead->m_pNext;
    pHead->m_pNext = NULL;
    delete pHead;
    return pList;
  }
  else
  {
    while(pList->m_pNext)
    {
      if (pList->m_pNext->Get() == pCProjectsEventsContainer)
      {
	      pTemp = pList->m_pNext;
	      pList->m_pNext = pList->m_pNext->m_pNext;
	      pTemp->m_pNext = NULL;
	      delete pTemp;
	      break;
      } 
      else
      {
      	pList = pList->m_pNext;
      }
    }
  }
  return pHead;
}

CProjectsEventsContainer::CProjectsEventsContainer()
{
}


CProjectsEventsContainer::~CProjectsEventsContainer()
{
}

void CProjectsEventsContainer::FinalRelease()
{
    //Must remove ourselves from the list of sinks
    CAutomationEvents::FindAndRemove(this);
}

void CProjectsEventsContainer::FireEvent(DISPID dispid, BSTR bstr, Project *pProject)
{
    if (dispid == CAutomationEvents::ProjectsEventsDispIDs::ItemAdded)
    {
        Fire_ItemAdded((Project*)pProject);
    }
    else if (dispid == CAutomationEvents::ProjectsEventsDispIDs::ItemRemoved)
    {
        Fire_ItemRemoved((Project*)pProject);
    }
    else if (dispid == CAutomationEvents::ProjectsEventsDispIDs::ItemRenamed)
    {
        Fire_ItemRenamed((Project*)pProject, bstr);
    }
}





///////////////////////////////////////////////////////////////////////////
//                                             CProjectItemsEventsContainer 

class ATL_NO_VTABLE CProjectItemsEventsContainer :
    public CComObjectRootEx<CComMultiThreadModel>,
    public IDispatchImpl<_ProjectItemsEvents, &IID__ProjectItemsEvents, &LIBID_DTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>,
    public IProvideClassInfo2Impl<&CLSID_ProjectItemsEvents, &DIID__dispProjectItemsEvents, &LIBID_DTE, DTE_LIB_VERSION_MAJ, DTE_LIB_VERSION_MIN>,
    public CProxy_dispProjectItemsEvents<CProjectItemsEventsContainer>,
    public IConnectionPointContainerImpl<CProjectItemsEventsContainer>
{
public:
    BEGIN_COM_MAP(CProjectItemsEventsContainer)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(_ProjectItemsEvents)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
        COM_INTERFACE_ENTRY(IProvideClassInfo2)
        COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
    END_COM_MAP()

    BEGIN_CONNECTION_POINT_MAP(CProjectItemsEventsContainer)    
        CONNECTION_POINT_ENTRY(DIID__dispProjectItemsEvents)
    END_CONNECTION_POINT_MAP()

    CProjectItemsEventsContainer();
    ~CProjectItemsEventsContainer();
    void FinalRelease();
  
    void SetFilter(IDispatch* pFilter) {m_srpFilter = pFilter;}
    void FireEvent(DISPID dispid, BSTR bstr, ProjectItem *pProjectItem);

private:
    CComPtr<IDispatch> m_srpFilter;
};

CContainerList<CProjectItemsEventsContainer>* Add(CContainerList<CProjectItemsEventsContainer>* pHead, CProjectItemsEventsContainer* pCProjectItemsEventsContainer)
{
  CContainerList<CProjectItemsEventsContainer>* pContainerList = new CContainerList<CProjectItemsEventsContainer>;
  if (!pContainerList)
      return pHead;
  pContainerList->m_pNext = pHead;
  pContainerList->Set(pCProjectItemsEventsContainer);
  return pContainerList;
}


CContainerList<CProjectItemsEventsContainer>* FindAndRemove(CContainerList<CProjectItemsEventsContainer>* pHead, CProjectItemsEventsContainer* pCProjectItemsEventsContainer)
{
  if (pHead == NULL)
      return NULL;
  if (pCProjectItemsEventsContainer == NULL)
      return pHead;
  CContainerList<CProjectItemsEventsContainer>* pList = pHead;
  CContainerList<CProjectItemsEventsContainer>* pTemp;
  if (pHead->Get() == pCProjectItemsEventsContainer)
  {
    pList = pHead->m_pNext;
    pHead->m_pNext = NULL;
    delete pHead;
    return pList;
  }
  else
  {
    while(pList->m_pNext)
    {
      if (pList->m_pNext->Get() == pCProjectItemsEventsContainer)
      {
	      pTemp = pList->m_pNext;
	      pList->m_pNext = pList->m_pNext->m_pNext;
	      pTemp->m_pNext = NULL;
	      delete pTemp;
	      break;
      }
      else
      {
      	pList = pList->m_pNext;
      }
    }
  }
  return pHead;
}

CProjectItemsEventsContainer::CProjectItemsEventsContainer()
{
}

CProjectItemsEventsContainer::~CProjectItemsEventsContainer()
{
}

void CProjectItemsEventsContainer::FinalRelease()
{
    //Must remove ourselves from the list of sinks
    CAutomationEvents::FindAndRemove(this);
}
  
void CProjectItemsEventsContainer::FireEvent(DISPID dispid, BSTR bstr, ProjectItem *pProjectItem)
{
    // Check the filter
    if (m_srpFilter != NULL)
    {
        // If Filter is a Project, then these events only fire for items 
        // in that project.
        CComPtr<Project> srpProjectFilter;
        HRESULT hr = m_srpFilter->QueryInterface(IID_Project, (void**) &srpProjectFilter);
        if (SUCCEEDED(hr) && (srpProjectFilter != NULL))
        {
            CComPtr<Project> srpItemProject;// project containing this item
            hr = pProjectItem->get_ContainingProject( &srpItemProject);
            if (SUCCEEDED(hr) && (srpItemProject != NULL) && !srpItemProject.IsEqualObject(srpProjectFilter) )
                return;
        }
        // If it is a ProjectItems collection, then the events only fire for items 
        // in that collection.
        CComPtr<ProjectItems> srpProjectItemsFilter;
        hr = m_srpFilter->QueryInterface(IID_ProjectItems, (void**) &srpProjectItemsFilter);
        if (SUCCEEDED(hr) && (srpProjectItemsFilter != NULL) )
        {
            CComPtr<ProjectItems> srpItemProjectItems;// project items collection containing this item
            hr = pProjectItem->get_Collection(&srpItemProjectItems);
            if (SUCCEEDED(hr) && (srpItemProjectItems != NULL) && !srpItemProjectItems.IsEqualObject(srpProjectItemsFilter) )
                return;
        }
    }
    if (dispid == CAutomationEvents::ProjectItemsEventsDispIDs::ItemAdded)
    {
        Fire_ItemAdded((ProjectItem*)pProjectItem);
    }
    else if (dispid == CAutomationEvents::ProjectItemsEventsDispIDs::ItemRemoved)
    {
        Fire_ItemRemoved((ProjectItem*)pProjectItem);
    }
    else if (dispid == CAutomationEvents::ProjectItemsEventsDispIDs::ItemRenamed)
    {
        Fire_ItemRenamed((ProjectItem*)pProjectItem, bstr);
    }
}




CContainerList<CProjectItemsEventsContainer>* FindAndRemove(CContainerList<CProjectItemsEventsContainer>* pHead, CProjectItemsEventsContainer* pCProjectItemsEventsContainer);
CContainerList<CProjectItemsEventsContainer>* Add(CContainerList<CProjectItemsEventsContainer>* pHead, CProjectItemsEventsContainer* pCProjectItemsEventsContainer);


///////////////////////////////////////////////////////////////////////////
//                                                        CAutomationEvents 

/* static */ 
HRESULT CAutomationEvents::GetAutomationEvents(IDispatch **ppdisp)
{
    HRESULT hr = NOERROR;
    if (s_pCAutomationEvents == NULL)
    {
        IfFailGo(CComObject<CAutomationEvents>::CreateInstance(&s_pCAutomationEvents));
        s_pCAutomationEvents->AddRef();
    }
    IfFailGo(s_pCAutomationEvents->QueryInterface(IID_IDispatch, (LPVOID*)ppdisp));

Error:
    return hr;
}

/* static */ 
void CAutomationEvents::ReleaseAutomationEvents()
{
    if (s_pCAutomationEvents != NULL)
    {
        s_pCAutomationEvents->Close();
        s_pCAutomationEvents->Release();
        s_pCAutomationEvents = NULL;
    }
}


/* static */ 
void CAutomationEvents::FireProjectsEvent(
    /* [in] */ CHierNode*  pNode,
    /* [in] */ DISPID      dispidEvent,
    /* [in] */ LPCTSTR     szFileName /* = NULL */) //old name in case of ItemRenamed
{
	if (!s_pCAutomationEvents)
        return;
    if (!pNode)
        return;

    CComVariant cvarExtObject;
	if(FAILED(pNode->GetProperty(VSHPROPID_ExtObject, &cvarExtObject)))
        return;
    ASSERT(cvarExtObject.pdispVal);
    if (!cvarExtObject.pdispVal)
        return;

	CComPtr<Project> srpProject;
	if (FAILED(cvarExtObject.pdispVal->QueryInterface(IID_Project,(void**)&srpProject)))
        return;

    CComBSTR cbstrFileName(szFileName);
    s_pCAutomationEvents->FireProjectsEvent(dispidEvent, cbstrFileName, srpProject);
}


/* static */ 
void CAutomationEvents::FireProjectItemsEvent(
    /* [in] */ CHierNode *  pNode,
    /* [in] */ DISPID       dispidEvent,
    /* [in] */ LPCTSTR      szFileName /* = NULL */) //old name in case of ItemRenamed
{
	if (!s_pCAutomationEvents)
        return;
    if (!pNode)
        return;

	CComVariant var;   
	if (FAILED(pNode->GetProperty(VSHPROPID_ExtObject, &var)))
        return;

    ASSERT(var.pdispVal);
    if (!var.pdispVal)
        return;

	CComPtr<ProjectItem> srpProjectItem;
	if (FAILED(var.pdispVal->QueryInterface(IID_ProjectItem, (void**)&srpProjectItem)))
        return;

    CComBSTR cbstrFileName(szFileName);
	s_pCAutomationEvents->FireProjectItemsEvent(dispidEvent, cbstrFileName, srpProjectItem);
}


CAutomationEvents::CAutomationEvents()
{
    m_pProjectsContainerList = NULL;
    m_pProjectItemsContainerList = NULL;
    m_fClosed = FALSE;
}


CAutomationEvents::~CAutomationEvents()
{
    Close();
}


void CAutomationEvents::Close()
{
    if (m_fClosed)
      return;

    //Remove the items from the list...
    if (m_pProjectsContainerList)
    {
        delete m_pProjectsContainerList;
        m_pProjectsContainerList = NULL;
    }
    if (m_pProjectItemsContainerList)
    {
        delete m_pProjectItemsContainerList;
        m_pProjectItemsContainerList = NULL;
    }
    m_fClosed = TRUE;
}


void CAutomationEvents::FireProjectItemsEvent(DISPID dispid, BSTR bstr, ProjectItem *pProjectItem)
{
    CContainerList<CProjectItemsEventsContainer>* pTemp = m_pProjectItemsContainerList;
    while (pTemp)
    {
        if (pTemp->m_pT)
            pTemp->m_pT->FireEvent(dispid, bstr, pProjectItem);
        pTemp = pTemp->m_pNext;
    }
}

void CAutomationEvents::FireProjectsEvent(DISPID dispid, BSTR bstr, Project *pProject)
{
    CContainerList<CProjectsEventsContainer>* pTemp = m_pProjectsContainerList;
    while (pTemp)
    {
        if (pTemp->m_pT)
            pTemp->m_pT->FireEvent(dispid, bstr, pProject);
        pTemp = pTemp->m_pNext;
    }
}



STDMETHODIMP CAutomationEvents::get_BscProjectsEvents(IDispatch** ppdisp)
{
  if (m_fClosed)
      return E_UNEXPECTED;
  CComPtr<_ProjectsEvents> srpEvts;
  HRESULT hr = NOERROR;
  CComObject<CProjectsEventsContainer> *pCProjectsEventsContainer = NULL;   // created with Ref count 0
  IfFailGo(CComObject<CProjectsEventsContainer>::CreateInstance(&pCProjectsEventsContainer));
  IfFailGo(pCProjectsEventsContainer->QueryInterface(IID__ProjectsEvents, (LPVOID*)&srpEvts));
  m_pProjectsContainerList = Add(m_pProjectsContainerList, pCProjectsEventsContainer);
  IfFailGo(srpEvts->QueryInterface(IID_IDispatch, (LPVOID*)ppdisp));
Error:
  return hr;
}

STDMETHODIMP CAutomationEvents::get_BscProjectItemsEvents(IDispatch* Filter, IDispatch** ppdisp)
{
    if (m_fClosed)
        return E_UNEXPECTED;
    HRESULT hr = NOERROR;
    CComPtr<_ProjectItemsEvents> srpEvts;

    CComObject<CProjectItemsEventsContainer> *pCProjectItemsEventsContainer = NULL;   // created with Ref count 0
    IfFailGo(CComObject<CProjectItemsEventsContainer>::CreateInstance(&pCProjectItemsEventsContainer));
    pCProjectItemsEventsContainer->SetFilter(Filter);
    IfFailGo(pCProjectItemsEventsContainer->QueryInterface(IID__ProjectItemsEvents, (LPVOID*)&srpEvts));
    m_pProjectItemsContainerList = Add(m_pProjectItemsContainerList, pCProjectItemsEventsContainer);
    IfFailGo(srpEvts->QueryInterface(IID_IDispatch, (LPVOID*)ppdisp));
Error:
    return hr;
}


/* static */
void CAutomationEvents::FindAndRemove(CProjectsEventsContainer* pContainer)
{
    if (s_pCAutomationEvents)
        s_pCAutomationEvents->m_pProjectsContainerList = ::FindAndRemove(s_pCAutomationEvents->m_pProjectsContainerList, pContainer);
}

/* static */
void CAutomationEvents::FindAndRemove(CProjectItemsEventsContainer* pContainer)
{
    if (s_pCAutomationEvents)
        s_pCAutomationEvents->m_pProjectItemsContainerList = ::FindAndRemove(s_pCAutomationEvents->m_pProjectItemsContainerList, pContainer);
}







