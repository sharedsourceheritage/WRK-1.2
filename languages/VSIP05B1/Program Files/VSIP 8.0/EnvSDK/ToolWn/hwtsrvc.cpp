
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// hwtsrvc.cpp : Implementation of CHelloWorldToolService


#include "stdafx.h"
#include "vspkg.h"
#include "hwtsrvc.h"


CHelloWorldToolService::CHelloWorldToolService(CToolWnPackage *pHwtPkg)
{
	ATLTRACE(TEXT("Constructing CHelloWorldToolService: 0x%X\n"), this);
	m_dwRef = 0;
	m_fZombie = FALSE;
	m_pHwtPkg = pHwtPkg;
}

CHelloWorldToolService::~CHelloWorldToolService()
{
	ATLTRACE(TEXT("Destructing CHelloWorldToolService: 0x%X\n"), this);
}

STDMETHODIMP CHelloWorldToolService::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
	if (ppvObj == NULL)
		return E_INVALIDARG;
	*ppvObj = NULL;		// always intialize out parameters
	if ((riid == IID_IHelloWorldTool) || (riid == IID_IUnknown))
	{
		AddRef();
		*ppvObj = (IHelloWorldTool *) this;
		return NOERROR;
	}

	return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CHelloWorldToolService::AddRef()
{
	++m_dwRef;
	return(m_dwRef);
}

STDMETHODIMP_(ULONG) CHelloWorldToolService::Release()
{
	--m_dwRef;
	if (m_dwRef == 0)
    {
		delete this;
        return 0;
    }
	return(m_dwRef); 
}


STDMETHODIMP CHelloWorldToolService::SayHello(BSTR bstrMsg)
{
	if (m_fZombie)
		return E_UNEXPECTED;
    if (!bstrMsg)
        return E_INVALIDARG;
	_ASSERTE(m_pHwtPkg);
	HRESULT hr = m_pHwtPkg->SayHello(bstrMsg);
	return hr;
}

