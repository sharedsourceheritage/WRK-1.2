
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//--------------------------------------------------------------------------
// enumdep.h: Project configuration enumerator
//---------------------------------------------------------------------------
#pragma once

//---------------------------------------------------------------------------
// Project dependency enumerator
//---------------------------------------------------------------------------
class CFigEnumDependencies : 
    public IVsEnumDependencies,
    public CComObjectRoot
{
public:
    CFigEnumDependencies();
    ~CFigEnumDependencies();

    virtual HRESULT Init(IVsBuildDependency* pBldDependency);

BEGIN_COM_MAP(CFigEnumDependencies)
    COM_INTERFACE_ENTRY(IVsEnumDependencies)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(CFigEnumDependencies) 

// IVsEnumDependencies
    public:
    virtual HRESULT STDMETHODCALLTYPE Reset( void);
    virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cElements,
            /* [size_is][out][in] */ IVsDependency __RPC_FAR *__RPC_FAR rgpIVsDependency[  ],
            /* [out] */ ULONG __RPC_FAR *pcElementsFetched);

    virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cElements);

    virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumDependencies __RPC_FAR *__RPC_FAR *ppIVsEnumDependencies);

protected:
    int	m_nextIndex;
    IVsBuildDependency* m_pBuildDependency;
};
// End of langprojenum.h
