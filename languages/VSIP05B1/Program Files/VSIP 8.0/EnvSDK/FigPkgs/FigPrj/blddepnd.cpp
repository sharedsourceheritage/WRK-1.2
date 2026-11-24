
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//--------------------------------------------------------------------------
// blddepnd.cpp: Build dependency object
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "PrjInc.h"

//---------------------------------------------------------------------------
// Constructor
//---------------------------------------------------------------------------
CFigBldDependency::CFigBldDependency()
{
	m_srpRefHierarchy = NULL;
}


//---------------------------------------------------------------------------
// Release hold on WebArchy
//---------------------------------------------------------------------------
CFigBldDependency::~CFigBldDependency()
{
}

//---------------------------------------------------------------------------
// Called to int the object with the cfg
//---------------------------------------------------------------------------
HRESULT CFigBldDependency::Init(IVsHierarchy* pHier)
{
    // Hold onto the referred project
	ExpectedPtrRet(pHier);
    m_srpRefHierarchy = pHier;
    return S_OK;
}


//---------------------------------------------------------------------------
// interface: IVsDependency
//---------------------------------------------------------------------------
STDMETHODIMP CFigBldDependency::get_CanonicalName( 
    /* [out] */ BSTR* pbstrCanonicalName)
{
    ASSERT(pbstrCanonicalName != NULL);
    HRESULT hr = S_OK;
    if(pbstrCanonicalName)
    {
        *pbstrCanonicalName = NULL;
    }
    else
        hr = E_POINTER;
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsDependency
//---------------------------------------------------------------------------
STDMETHODIMP CFigBldDependency::get_Type( 
    /* [out] */ GUID* pguidType)
{
    ASSERT(pguidType != NULL);
    HRESULT hr = S_OK;
    if(pguidType)
    {   // All our dependencies are build projects
        *pguidType = GUID_VS_DEPTYPE_BUILD_PROJECT;
    }
    else
        hr = E_POINTER;
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsDependency
//---------------------------------------------------------------------------
STDMETHODIMP CFigBldDependency::get_Description( 
    /* [out] */ BSTR *pbstrDescription)
{
    return E_NOTIMPL;
}

//---------------------------------------------------------------------------
// interface: IVsDependency
//---------------------------------------------------------------------------
STDMETHODIMP CFigBldDependency::get_HelpContext( 
    /* [out] */ DWORD *pdwHelpContext)
{
    return E_NOTIMPL;
}

//---------------------------------------------------------------------------
// interface: IVsDependency
//---------------------------------------------------------------------------
STDMETHODIMP CFigBldDependency::get_HelpFile( 
    /* [out] */ BSTR *pbstrHelpFile)
{
    return E_NOTIMPL;
}


//---------------------------------------------------------------------------
// interface: IVsBuildDependency
//---------------------------------------------------------------------------
STDMETHODIMP CFigBldDependency::get_MustUpdateBefore( 
        /* [out] */ BOOL *pfMustUpdateBefore)
{
    ASSERT(pfMustUpdateBefore != NULL);
    HRESULT hr = S_OK;
    if(pfMustUpdateBefore)
    {   
        *pfMustUpdateBefore = FALSE;
    }
    else
        hr = E_POINTER;
    return hr;
}

//---------------------------------------------------------------------------
// interface: IVsBuildDependency
//---------------------------------------------------------------------------
STDMETHODIMP CFigBldDependency::get_ReferredProject( 
        /* [out] */ IUnknown ** ppIUnknownProject)
{
    ASSERT(ppIUnknownProject != NULL);
    HRESULT hr = S_OK;

    if( ppIUnknownProject )
    {   
        *ppIUnknownProject = NULL;
		hr = m_srpRefHierarchy->QueryInterface(IID_IUnknown, (void**)ppIUnknownProject);
    }
    else
    {
        hr = E_POINTER;
    }
    return hr;
}

// End of blddepnd.cpp
