
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

/*---------------------------------------------------------
  CEnumMethodField
-----------------------------------------------------------*/
class CEnumMethodField : public IEnumDebugFields
{
private:
  ULONG             m_refCount;
  IDebugField*      m_fieldThis; 
  IEnumDebugFields* m_parameters;
  IEnumDebugFields* m_locals;

  ULONG             m_currentIdx;
  ULONG             m_thisCount;
  ULONG             m_parameterCount;
  ULONG             m_localCount;

public:
  CEnumMethodField( in IDebugField* pfieldThis, 
                   in IEnumDebugFields* pparameters,
                   in IEnumDebugFields* plocals );
  ~CEnumMethodField();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out LPVOID* pobj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();
  
  //IEnumDebugProperty2
  STDMETHODIMP Next( in ULONG count, out IDebugField** ppelements, out ULONG* pfetched );
  STDMETHODIMP Skip( in ULONG count );
  STDMETHODIMP Reset();
  STDMETHODIMP Clone( out IEnumDebugFields** ppclone );
  STDMETHODIMP GetCount( out ULONG* pcount );
};
