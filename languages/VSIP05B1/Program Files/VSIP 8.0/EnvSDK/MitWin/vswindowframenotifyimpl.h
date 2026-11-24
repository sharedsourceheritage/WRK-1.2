
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsWindowFrameNotifyImpl.h: interface for the CVsWindowFrameNotifyImpl class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

// Provide default implementation of IVsWindowFrameNotify
class ATL_NO_VTABLE CVsWindowFrameNotifyImpl  :
	public IVsWindowFrameNotify
{
public:
	CVsWindowFrameNotifyImpl() {};
	~CVsWindowFrameNotifyImpl() {};

	STDMETHOD(OnShow)(/*[in]*/ FRAMESHOW fShow)
	{
		ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("CVsWindowFrameNotifyImpl::OnShow \n") );
		return S_OK;
	}
	STDMETHOD(OnMove)()
	{
		ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("CVsWindowFrameNotifyImpl::OnMove \n") );
		return S_OK;
	}
	STDMETHOD(OnSize)()
	{
		ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("CVsWindowFrameNotifyImpl::OnSize \n") );
		return S_OK;
	}
	STDMETHOD(OnDockableChange)(/*[in]*/ BOOL fDockable)
	{
		ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("CVsWindowFrameNotifyImpl::OnDockableChange \n") );
		return S_OK;
	}
};
