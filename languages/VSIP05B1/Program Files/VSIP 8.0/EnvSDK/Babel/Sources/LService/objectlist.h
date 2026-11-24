/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef objectlist_h
#define objectlist_h

struct ObjectElem;

class ObjectList : public IUnknown
{
private:
  ULONG       m_refCount;
  ObjectElem* m_objectList;

public:
  ObjectList();
  virtual ~ObjectList();

  
  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //List methods
  ULONG   GetCount();
  HRESULT Clear();
  HRESULT Insert( in IUnknown* obj );
  HRESULT Remove( in IUnknown* obj );
  
  HRESULT GetFirst( out ObjectElem** current, out IUnknown** obj );
  HRESULT GetNext( inout ObjectElem** current, out IUnknown** obj );
};

  
#endif
