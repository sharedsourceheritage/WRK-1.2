
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// OptionsPreferences.h: Definition of the COptionsPreferences class
//
//////////////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////////////////////
// COptionsPreferences

class COptionsPreferences : 
	public IDispatchImpl<_OptionsPreferences, &IID__OptionsPreferences, &LIBID_OptPkgLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<COptionsPreferences,&CLSID_OptionsPreferences>
{
public:
    static HRESULT COptionsPreferences::CreateInstance(
        /* [out] */ _OptionsPreferences** pp_OptionsPreferences);
protected:
	COptionsPreferences();
	~COptionsPreferences();

public:

    BEGIN_COM_MAP(COptionsPreferences)
	    COM_INTERFACE_ENTRY(IDispatch)
	    COM_INTERFACE_ENTRY(_OptionsPreferences)
	    COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()
    DECLARE_NOT_AGGREGATABLE(COptionsPreferences) 

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IOptionsPreferences
public:
	STDMETHOD(get_Setting)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Setting)(/*[in]*/ BSTR newVal);

protected:
    void ReleaseSetting();

private:
    LPWSTR m_pwszSetting;
};
