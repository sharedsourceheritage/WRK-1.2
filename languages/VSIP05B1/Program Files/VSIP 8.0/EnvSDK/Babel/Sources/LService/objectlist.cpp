/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include "objectlist.h"
#include "vsmem.h"

/*---------------------------------------------------------
  ObjectElem 
-----------------------------------------------------------*/
struct ObjectElem
{
  ObjectElem* next;
  IUnknown*   obj;
};

/*---------------------------------------------------------
  ObjectList 
-----------------------------------------------------------*/
ObjectList::ObjectList()
{
  TRACE_CREATE_HIDE( "ObjectList", this);
  m_refCount   = 1;
  m_objectList = NULL;
}


ObjectList::~ObjectList()
{
  TRACE_DESTROY( this );
  Clear();
}


/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP ObjectList::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("ObjectList::QueryInterface for IUnknown");
    *obj = static_cast<IUnknown*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) ObjectList::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) ObjectList::Release()
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
  List
-----------------------------------------------------------*/
HRESULT ObjectList::Clear()
{
  ObjectElem* elem;
  
  elem = m_objectList;
  while (elem)
  {
    ObjectElem* next;

    RELEASE(elem->obj);
    next = elem->next;
    FREE(elem);
    elem = next;
  }

  m_objectList = NULL;
  return S_OK;
}

ULONG ObjectList::GetCount()
{
  ULONG count = 0;
  for (ObjectElem* elem = m_objectList; elem; elem = elem->next)
  {
    count++;
  }

  return count;
}

HRESULT ObjectList::Insert( in IUnknown* obj )
{
  REFARG(obj);
  HRESULT hr;

  ObjectElem* elem = ALLOC(ObjectElem);
  if (!elem) return E_OUTOFMEMORY;

  hr = obj->QueryInterface( IID_IUnknown, reinterpret_cast<void**>(&(elem->obj)) );
  if (FAILED(hr)) { FREE(elem); return hr; }
  
  elem->next   = m_objectList;
  m_objectList = elem;

  return S_OK;
}
  
HRESULT ObjectList::Remove( in IUnknown* obj )
{
  REFARG(obj);
  HRESULT hr;

  IUnknown* unkObj;
  hr = obj->QueryInterface( IID_IUnknown, reinterpret_cast<void**>(&unkObj));
  if (FAILED(hr)) return hr;

  ObjectElem* elem = m_objectList;
  ObjectElem* prev = NULL;  
  while (elem && (elem->obj != unkObj)) 
  {
    prev = elem;
    elem = elem->next;
  }
  RELEASE(unkObj);
  if (!elem) return S_FALSE;

  //remove from chain
  if (prev)
    prev->next = elem->next;
  else
    m_objectList = elem->next;

  RELEASE(elem->obj);
  FREE(elem);

  return S_OK;
}


HRESULT ObjectList::GetFirst( out ObjectElem** current, out IUnknown** obj )
{
  OUTARG(obj);
  OUTARG(current);

  *current = m_objectList;
  return GetNext( current, obj );
}

HRESULT ObjectList::GetNext( inout ObjectElem** current, out IUnknown** obj )
{
  OUTARG(obj);
  INOUTARG(current);

  if (*current == NULL) return S_FALSE;

  *obj = (*current)->obj;
//  ADDREF(*obj);
  *current = (*current)->next;
  return S_OK;
}
