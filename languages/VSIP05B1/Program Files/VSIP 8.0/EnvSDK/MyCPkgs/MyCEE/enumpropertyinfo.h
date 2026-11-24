
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

/*---------------------------------------------------------
  EnumProperty
-----------------------------------------------------------*/
class CEnumPropertyInfo : public IEnumDebugPropertyInfo2
{
private:
  ULONG                   m_refCount;
  IDebugSymbolProvider*   m_provider;
  IDebugAddress*          m_address;
  IDebugBinder*           m_binder;
  IEnumDebugFields*       m_fields;
  DEBUGPROP_INFO_FLAGS    m_infoFlags;
  DWORD                   m_radix;

public:
  CEnumPropertyInfo( in IDebugSymbolProvider *pprovider,
                    in IDebugAddress         *paddress,
                    in IDebugBinder         *pbinder,
                    in DWORD                radix,
                    in IEnumDebugFields     *pfields,
                    in DEBUGPROP_INFO_FLAGS infoFlags );
  ~CEnumPropertyInfo();
  
  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out LPVOID* pobj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();
  
  //IEnumDebugProperty2
  STDMETHODIMP Next( in ULONG count, out DEBUG_PROPERTY_INFO* pelements, out ULONG* pfetched );
  STDMETHODIMP Skip( in ULONG count );
  STDMETHODIMP Reset();
  STDMETHODIMP Clone( out IEnumDebugPropertyInfo2** ppclone );
  STDMETHODIMP GetCount( out ULONG* pcount );
};
