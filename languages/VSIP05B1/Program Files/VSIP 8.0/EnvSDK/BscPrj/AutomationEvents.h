
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


/***************************************************************************
File name   : AutomationEvents.h
Description : Declaration of the following automation events:
              1) class CAutomationEvents 
***************************************************************************/

#pragma once

// forward declarations
class CAutomationEvents;
class CProjectsEventsContainer;
class CProjectItemsEventsContainer;


template<typename T> 
class CContainerList
{
public:
    CContainerList() {m_pNext = NULL;}
    ~CContainerList() { if (m_pNext) delete m_pNext;}
    void Set(T* pT) {m_pT = pT;}
    T* Get(void) {return m_pT;}

    CContainerList<T>* m_pNext;
    T* m_pT;
};



///////////////////////////////////////////////////////////////////////////
//  Class CAutomationEvents
//      Implements an event root object.
//      Event objects are retrieved from the DTE.Events object.
//      A package provides an event object by responding to IVsPackage::
//      GetAutomationObject. Automaton events are registered under 
//      Packages\<PackageGuid>\AutomationEvents registry key.
//      For example, "<MyName>ProjectItemsEvents" and "<MyName>ProjectsEvents".
//      The implementation of GetAutomationObject should watch for these
//      strings. When these event objects are requested, a small object needs
//      to be created that has the properties get_<MyName>ProjectsEvents, 
//      get_<MyName>ProjectItemsEvents, as well as any other event 
//      objects your package may support. When this object is returned 
//      to the shell, it will call the appropriate method on this object. 
//      If, for example, DTE.Events.<MyName>ProjectsEvents were called, 
//      the get_<MyName>ProjectsEvents property on this object will be 
//      invoked. From here, you create an instance of your event object, 
//      and this will be returned to the calling AddIn. In most cases, 
//      you will need to return a new object for each call to these 
//      methods because most event objects take a filter object, when 
//      firing your event, you will need to check this filter to verify 
//      that the event handler should be called.
///////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE CAutomationEvents :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IDispatchImpl<IBscEventsRoot, &IID_IBscEventsRoot, &LIBID_BscPrjExtLib>
{
public:
    friend CProjectsEventsContainer;
    friend CProjectItemsEventsContainer;

    // static helper functions for access to the automation events object
    static HRESULT GetAutomationEvents(IDispatch **ppdisp);

    static void ReleaseAutomationEvents();

    // static helper functions for firing the events
    static void FireProjectsEvent(
        /* [in] */ CHierNode*  pNode,
        /* [in] */ DISPID      dispidEvent,
        /* [in] */ LPCTSTR     szFileName = NULL); //must be the old name in case of ItemRenamed

    static void FireProjectItemsEvent(
        /* [in] */ CHierNode *  pNode,
        /* [in] */ DISPID       dispidEvent,
        /* [in] */ LPCTSTR      szFileName = NULL); //must be the old name in case of ItemRenamed

    struct ProjectItemsEventsDispIDs
	{
		enum DispIDs
		{
			ItemAdded = 1,
			ItemRemoved = 2,
			ItemRenamed = 3
		};
	};

	struct ProjectsEventsDispIDs
	{
		enum DispIDs
		{
			ItemAdded = 1,
			ItemRemoved = 2,
			ItemRenamed = 3
		};
	};

protected:
    CAutomationEvents();
    virtual ~CAutomationEvents();
    void Close();

public:
	BEGIN_COM_MAP(CAutomationEvents)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IBscEventsRoot)
	END_COM_MAP()

    // IBscEventsRoot interface
    STDMETHOD(get_BscProjectsEvents)(IDispatch** ppdisp);

    // Filter is an optional argument that addins can use to get events on for 
    // specific ProjectItems collections.  
    // If Filter is a Project, then these events only fire for items in that 
    // project.  
    // If it is a ProjectItems collection, then the events only fire for items 
    // in that collection.
	STDMETHOD(get_BscProjectItemsEvents)(IDispatch* Filter, IDispatch** ppdisp);


protected:

    void FireProjectItemsEvent(DISPID dispid, BSTR bstr, ProjectItem *pProjectItem);
    void FireProjectsEvent(DISPID dispid, BSTR bstr, Project *pProject);


protected:
    static void FindAndRemove(CProjectsEventsContainer*);
    static void FindAndRemove(CProjectItemsEventsContainer*);

    CContainerList<CProjectItemsEventsContainer>* m_pProjectItemsContainerList;
    CContainerList<CProjectsEventsContainer>* m_pProjectsContainerList;

    BOOL m_fClosed;

};

