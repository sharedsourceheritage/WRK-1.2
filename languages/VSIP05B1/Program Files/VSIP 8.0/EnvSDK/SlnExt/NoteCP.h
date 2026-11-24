
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

#pragma warning(disable : 4800)
template <class T>
class CSlnNotesEvents : public IConnectionPointImpl<T, &DIID_DSolutionNotesEvents, CComDynamicUnkArray>
{

public:
	VOID Fire_NoteAdded(ISolutionNote* pNote)
	{
		T* pT = static_cast<T*>(this);
		CComVariant* pvars = new CComVariant[1];
		IUnknown** ppunk;

		for(ppunk = m_vec.begin(); ppunk < m_vec.end(); ppunk++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = *ppunk;
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[0] = (IDispatch*)pNote;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_NoteRenamed(ISolutionNote* pNote, BSTR* pNewName)
	{
		T* pT = static_cast<T*>(this);
		// CComVariant doesn't handle ByRef types,
		// so just use old-fashioned variants
		VARIANT* pvars = new VARIANT[2];
		IUnknown** ppunk;

		for(ppunk = m_vec.begin(); ppunk < m_vec.end(); ppunk++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = *ppunk;
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL && pNote != NULL)
			{
				VariantInit(&pvars[1]);
				V_VT(&pvars[1]) = VT_DISPATCH;
				V_DISPATCH(&pvars[1]) = (IDispatch*)pNote;
				pvars[1].pdispVal->AddRef();
				VariantInit(&pvars[0]);
				V_VT(&pvars[0]) = VT_BSTR | VT_BYREF;
				V_BSTRREF(&pvars[0]) = pNewName;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_NoteDeleted(ISolutionNote* pNote, VARIANT_BOOL* pfCancel)
	{
		T* pT = static_cast<T*>(this);
		// CComVariant doesn't handle ByRef types,
		// so just use old-fashioned variants
		VARIANT* pvars = new VARIANT[2];
		IUnknown** ppunk;

		for(ppunk = m_vec.begin(); ppunk < m_vec.end(); ppunk++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = *ppunk;
			pT->Unlock();
			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL && pNote != NULL)
			{
				VariantInit(&pvars[1]);
				V_VT(&pvars[1]) = VT_DISPATCH;
				V_DISPATCH(&pvars[1]) = (IDispatch*)pNote;
				pvars[1].pdispVal->AddRef();
				VariantInit(&pvars[0]);
				V_VT(&pvars[0]) = VT_BOOL | VT_BYREF;
				V_BOOLREF(&pvars[0]) = pfCancel;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
};
