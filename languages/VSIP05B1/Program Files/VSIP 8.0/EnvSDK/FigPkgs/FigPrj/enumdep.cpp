
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//--------------------------------------------------------------------------
// DepEnum.cpp: Project configuration enumerators.
//---------------------------------------------------------------------------
#include "stdafx.h"
#include "PrjInc.h"

//---------------------------------------------------------------------------
// Constructor
//---------------------------------------------------------------------------
CFigEnumDependencies::CFigEnumDependencies()
  :
    m_nextIndex (0)
{
	m_pBuildDependency = NULL;
}

//---------------------------------------------------------------------------
// Called to int the object with the cfg. Note that we addref each depecdency 
// object.
//---------------------------------------------------------------------------
HRESULT CFigEnumDependencies::Init(IVsBuildDependency* pBldDependency)
{
    ExpectedPtrRet(pBldDependency);
    m_nextIndex = 0;
	m_pBuildDependency = pBldDependency;
	m_pBuildDependency->AddRef();
    return S_OK;
}

//---------------------------------------------------------------------------
// Release hold on WebArchy
//---------------------------------------------------------------------------
CFigEnumDependencies::~CFigEnumDependencies()
{
    // Free the dependency
    if ( m_pBuildDependency )
    {
        m_pBuildDependency->Release();
    }
}

//---------------------------------------------------------------------------
// interface: IVsEnumDependencies
//---------------------------------------------------------------------------
HRESULT CFigEnumDependencies::Next( 
            /* [in] */ ULONG cElements,
            /* [size_is][out][in] */ IVsDependency __RPC_FAR *__RPC_FAR rgpIVsDependency[  ],
            /* [out] */ ULONG __RPC_FAR *pcElementsFetched)

{
    if (cElements == 0)
        return E_INVALIDARG;
    ExpectedPtrRet(rgpIVsDependency);

    ULONG cFetched = 0;

	if ( m_pBuildDependency && m_nextIndex < 1 ) 
	{
		rgpIVsDependency[m_nextIndex] = static_cast<IVsDependency*>(m_pBuildDependency);
		rgpIVsDependency[m_nextIndex]->AddRef();
		m_nextIndex++;
		cFetched++;
        cElements--;
    }

    if( pcElementsFetched != NULL )
        *pcElementsFetched = cFetched;

    // did we get 'em all?
    return 0 == cElements ? S_OK : S_FALSE;
}

//---------------------------------------------------------------------------
// interface: IVsEnumDependencies
//---------------------------------------------------------------------------
HRESULT CFigEnumDependencies::Skip( 
            /* [in] */ ULONG cElements)
{
    m_nextIndex += cElements;
    if( m_nextIndex > 1 )
    {
        m_nextIndex = 1;
        return S_FALSE;
    }
    return S_OK;
}

//---------------------------------------------------------------------------
// interface: IVsEnumDependencies
//---------------------------------------------------------------------------
HRESULT CFigEnumDependencies::Reset(void)
{
    m_nextIndex = 0;
    return S_OK;
}

//---------------------------------------------------------------------------
// interface: IVsEnumDependencies
//---------------------------------------------------------------------------
HRESULT CFigEnumDependencies::Clone( 
            /* [out] */ IVsEnumDependencies __RPC_FAR *__RPC_FAR *ppIVsEnumDependencies)
{
    HRESULT hr = S_OK;
    CFigEnumDependencies* pEnumDepends;
    pEnumDepends = new CComObject<CFigEnumDependencies>;
    if(pEnumDepends == NULL)
    {
        hr =  E_OUTOFMEMORY;
    }
    else
    {
        pEnumDepends->AddRef();
        hr = pEnumDepends->Init(m_pBuildDependency);
        if (SUCCEEDED(hr))
        {
            *ppIVsEnumDependencies = static_cast<IVsEnumDependencies*>(pEnumDepends);
            (*ppIVsEnumDependencies)->AddRef();
            hr = pEnumDepends->Skip(m_nextIndex);
        }
        pEnumDepends->Release();
    }
    return hr;
}

// End of projenum.cpp
