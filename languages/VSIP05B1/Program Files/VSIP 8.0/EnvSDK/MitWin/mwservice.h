
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// MWToolSrvc.h : Declaration of CMWToolServiceToolService

#pragma once

/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CMitWinPackage;

/////////////////////////////////////////////////////////////////////////////
// CMWToolService

class CMWToolService : 
    public IMWTool
{

public:

	CMWToolService(CMitWinPackage *pMWPkg);
	~CMWToolService();
	
	BEGIN_INTERFACE

	// *** IUnknown methods ***
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

    // IMWToolWindowService
    STDMETHOD(CreateMWToolWindow)(
                    /*[in]*/ REFGUID rguidPersistenceSlot, // GUID_NULL for default
                    /*[in]*/ DWORD dwID = 0);               // 0 for next available

private:
	BOOL            m_fZombie;
	DWORD           m_dwRef;
	CMitWinPackage* m_pMWPkg;
};
