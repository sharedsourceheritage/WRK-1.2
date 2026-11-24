
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//--------------------------------------------------------------------------
// blddepnd.h: Build dependency object
//---------------------------------------------------------------------------
#pragma once

//---------------------------------------------------------------------------
//Build Dependency object
//---------------------------------------------------------------------------
class ATL_NO_VTABLE CFigBldDependency : 
    public CComObjectRootEx<CComSingleThreadModel>,     // explict,
    public IVsBuildDependency
{
protected:
    ~CFigBldDependency();
public:
	CFigBldDependency();
    virtual HRESULT Init(IVsHierarchy* pHier);

BEGIN_COM_MAP(CFigBldDependency)
    COM_INTERFACE_ENTRY(IVsBuildDependency)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(CFigBldDependency) 

// IVsDependency
public:
    virtual HRESULT STDMETHODCALLTYPE get_CanonicalName( 
        /* [out] */ BSTR __RPC_FAR *pbstrCanonicalName);

    virtual HRESULT STDMETHODCALLTYPE get_Type( 
        /* [out] */ GUID __RPC_FAR *pguidType);

    virtual HRESULT STDMETHODCALLTYPE get_Description( 
        /* [out] */ BSTR __RPC_FAR *pbstrDescription);

    virtual HRESULT STDMETHODCALLTYPE get_HelpContext( 
        /* [out] */ DWORD __RPC_FAR *pdwHelpContext);

    virtual HRESULT STDMETHODCALLTYPE get_HelpFile( 
        /* [out] */ BSTR __RPC_FAR *pbstrHelpFile);


// IVsBuildDependency
public:
    virtual HRESULT STDMETHODCALLTYPE get_MustUpdateBefore( 
        /* [out] */ BOOL __RPC_FAR *pfMustUpdateBefore);

    virtual HRESULT STDMETHODCALLTYPE get_ReferredProject( 
        /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIUnknownProject);

protected:
	CComPtr<IVsHierarchy>	m_srpRefHierarchy;

};

// End of blddepnd.h
