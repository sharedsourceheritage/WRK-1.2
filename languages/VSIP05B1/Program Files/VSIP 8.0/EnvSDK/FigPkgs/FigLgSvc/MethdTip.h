
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// MethdTip.h : Declaration of CFigMethodData

#pragma once

#define NUM_METHOD_TYPES    3
#define MAX_NUM_PARAMS        4


/////////////////////////////////////////////////////////////////////////////
// forward declarations

/////////////////////////////////////////////////////////////////////////////
// CFigMethodData

class CFigMethodData :
    public IVsMethodData
{
public:
    CFigMethodData( CVsPackage *pCVsPkg, IVsTextView *pView );
    ~CFigMethodData();
    STDMETHODIMP Init();
    STDMETHODIMP SetType( int type );
    STDMETHODIMP SetCurrentParam( long curParam );
    
    BEGIN_INTERFACE
    // *** IUnknown methods **********************************************************
    STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
    STDMETHODIMP_(ULONG) AddRef();
    STDMETHODIMP_(ULONG) Release();

    // *** IVsMethodData methods ******************************************************
    STDMETHODIMP_(long)          GetOverloadCount( void );
    STDMETHODIMP_(const WCHAR *) GetMethodText(
                                    /*[in] */ long iMethod, 
                                    /*[in] */ MethodTextType type );
    STDMETHODIMP_(long)          GetParameterCount(
                                    /*[in] */ long iMethod );
    STDMETHODIMP_(const WCHAR *) GetParameterText(
                                    /*[in] */ long iMethod, 
                                    /*[in] */ long iParm, 
                                    /*[in] */ ParameterTextType type );
    STDMETHODIMP_(long)          GetCurrentParameter(
                                    /*[in] */ long iMethod );
    STDMETHODIMP_(HRESULT)       GetContextStream(
                                    /*[out]*/ long *piPos, 
                                    /*[out]*/ long *piLength );
    STDMETHODIMP_(void)          OnDismiss( void );
     STDMETHODIMP_(long)          GetCurMethod( void );
    STDMETHODIMP_(void)          UpdateView( void );
    STDMETHODIMP_(long)          NextMethod( void );
    STDMETHODIMP_(long)          PrevMethod( void );


private:
    DWORD m_dwRef;
    BOOL m_fZombie;
    BOOL m_fInit;
    CVsPackage* m_pCVsPkg;
    CComPtr<IVsTextView> m_srpTextView;
    int m_MethodType;
    WCHAR* m_MethodTexts[ NUM_METHOD_TYPES ];
    long m_nParameters[ NUM_METHOD_TYPES ];
    WCHAR* m_ParamsTexts[ NUM_METHOD_TYPES ][ MAX_NUM_PARAMS ];
    long m_curParam;

    HRESULT GetDescription(
                /* [in]  */ int resourceID,
                /* [out] */ WCHAR ** pString);
};

