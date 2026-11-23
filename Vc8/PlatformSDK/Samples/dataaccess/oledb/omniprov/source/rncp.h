// Start of the RNCP.h

#ifndef _RNCP_104C2CC1_6D0F_11d3_AC96_00C04F8DB3D5_H_
#define _RNCP_104C2CC1_6D0F_11d3_AC96_00C04F8DB3D5_H_

template <class T>
class CProxyIRowsetNotify : public IConnectionPointImpl<T, &IID_IRowsetNotify, CComDynamicUnkArray>
{
public:
	HRESULT Fire_OnFieldChange(IRowset * pRowset, HROW hRow, ULONG cColumns, ULONG * rgColumns, ULONG eReason, ULONG ePhase, LONG fCantDeny)
	{
		HRESULT ret = S_OK;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IRowsetNotify* pIRowsetNotify = reinterpret_cast<IRowsetNotify*>(sp.p);
			if (pIRowsetNotify != NULL)
				ret = pIRowsetNotify->OnFieldChange(pRowset, hRow, cColumns, rgColumns, eReason, ePhase, fCantDeny);
		}	return ret;
	
	}
	HRESULT Fire_RemoteOnFieldChange(IRowset * pRowset, HROW hRow, ULONG cColumns, ULONG * rgColumns, ULONG eReason, ULONG ePhase, LONG fCantDeny, IErrorInfo * * ppErrorInfoRem)
	{
		HRESULT ret = S_OK;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IRowsetNotify* pIRowsetNotify = reinterpret_cast<IRowsetNotify*>(sp.p);
			if (pIRowsetNotify != NULL)
				ret = pIRowsetNotify->RemoteOnFieldChange(pRowset, hRow, cColumns, rgColumns, eReason, ePhase, fCantDeny, ppErrorInfoRem);
		}	return ret;
	
	}
	HRESULT Fire_OnRowChange(IRowset * pRowset, ULONG cRows, const HROW* rghRows, ULONG eReason, ULONG ePhase, LONG fCantDeny)
	{
		HRESULT ret = S_OK;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IRowsetNotify* pIRowsetNotify = reinterpret_cast<IRowsetNotify*>(sp.p);
			if (pIRowsetNotify != NULL)
				ret = pIRowsetNotify->OnRowChange(pRowset, cRows, rghRows, eReason, ePhase, fCantDeny);
		}	return ret;
	
	}
	HRESULT Fire_RemoteOnRowChange(IRowset * pRowset, ULONG cRows, const HROW* rghRows, ULONG eReason, ULONG ePhase, LONG fCantDeny, IErrorInfo * * ppErrorInfoRem)
	{
		HRESULT ret = S_OK;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IRowsetNotify* pIRowsetNotify = reinterpret_cast<IRowsetNotify*>(sp.p);
			if (pIRowsetNotify != NULL)
				ret = pIRowsetNotify->RemoteOnRowChange(pRowset, cRows, rghRows, eReason, ePhase, fCantDeny, ppErrorInfoRem);
		}	return ret;
	
	}
	HRESULT Fire_OnRowsetChange(IRowset * pRowset, ULONG eReason, ULONG ePhase, LONG fCantDeny)
	{
		HRESULT ret = S_OK;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IRowsetNotify* pIRowsetNotify = reinterpret_cast<IRowsetNotify*>(sp.p);
			if (pIRowsetNotify != NULL)
				ret = pIRowsetNotify->OnRowsetChange(pRowset, eReason, ePhase, fCantDeny);
		}	return ret;
	
	}
	HRESULT Fire_RemoteOnRowsetChange(IRowset * pRowset, ULONG eReason, ULONG ePhase, LONG fCantDeny, IErrorInfo * * ppErrorInfoRem)
	{
		HRESULT ret = S_OK;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IRowsetNotify* pIRowsetNotify = reinterpret_cast<IRowsetNotify*>(sp.p);
			if (pIRowsetNotify != NULL)
				ret = pIRowsetNotify->RemoteOnRowsetChange(pRowset, eReason, ePhase, fCantDeny, ppErrorInfoRem);
		}	return ret;
	
	}
};
#endif

// Start of the RNCP.h