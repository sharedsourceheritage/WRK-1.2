
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// hwtsrvc.h : Declaration of CHelloWorldToolServiceToolService

#pragma once

/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CToolWnPackage;

/////////////////////////////////////////////////////////////////////////////
// CHelloWorldToolService

class CHelloWorldToolService : public IHelloWorldTool
{
public:
	CHelloWorldToolService(CToolWnPackage *pHwtPkg);
	~CHelloWorldToolService();
	
	BEGIN_INTERFACE
	// *** IUnknown methods ***
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// *** IHelloWorldTool methods ***
	STDMETHODIMP SayHello(BSTR bstrURL);

private:
	DWORD m_dwRef;
	CToolWnPackage* m_pHwtPkg;
	BOOL m_fZombie;
};

