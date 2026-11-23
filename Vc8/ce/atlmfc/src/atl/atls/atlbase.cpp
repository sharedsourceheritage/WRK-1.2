// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

#include "StdAfx.H"

#pragma warning( disable: 4073 )  // initializers put in library initialization area

#ifdef _WIN32_WCE

__declspec(selectany) BOOL (WINAPI *_pAtlRawDllMain)(HANDLE, DWORD, LPVOID);

extern "C"
BOOL WINAPI AtlRawDllMain(HANDLE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	BOOL br = TRUE;
	if(dwReason == DLL_PROCESS_ATTACH)
	{
		if(_pAtlRawDllMain != NULL)
		{
			br = (*_pAtlRawDllMain)(hInstance, dwReason, lpReserved);
			if(br == FALSE) return br;
		}
		_AtlModuleInstance = static_cast<HINSTANCE>(hInstance);
	}
	else if(dwReason == DLL_PROCESS_DETACH)
	{
		if(_pAtlRawDllMain != NULL)
		{
			br = (*_pAtlRawDllMain)(hInstance, dwReason, lpReserved);
			if(br == FALSE) return br;
		}
	}
	return br;
}

extern "C" BOOL (WINAPI *_pRawDllMain)(HANDLE, DWORD , LPVOID) = &AtlRawDllMain;

namespace ATL
{

static FARPROC _ATLLoadOle32API(LPCWSTR lpProcName)
{
	static HINSTANCE hOle32Dll = ::LoadLibrary(L"ole32.dll");
	return ::GetProcAddressW(hOle32Dll, lpProcName);
}

#define DEFINE_DCOMAPI_START(api, parms1, parms2) \
HRESULT api(parms1) \
{ \
	typedef HRESULT (*api##_t)(parms1); \
	static FARPROC pfnAPI = _ATLLoadOle32API(L#api); \
	if(pfnAPI != NULL) \
	{ \
		return reinterpret_cast< api##_t >(pfnAPI)(parms2); \
	}

#define DEFINE_DCOMAPI(api, parms1, parms2) \
	DEFINE_DCOMAPI_START(api, parms1, parms2) \
	return E_NOTIMPL; \
}

#define CoDisconnectObject_Parms1 LPUNKNOWN pUnk, DWORD dwReserved
#define CoDisconnectObject_Parms2 pUnk, dwReserved
DEFINE_DCOMAPI(CoDisconnectObject, CoDisconnectObject_Parms1, CoDisconnectObject_Parms2)

#define CoInitialize_Parms1 LPVOID pvReserved
#define CoInitialize_Parms2 pvReserved
DEFINE_DCOMAPI(CoInitialize, CoInitialize_Parms1, CoInitialize_Parms2)

#define CoRevokeClassObject_Parms1 DWORD dwRegister
#define CoRevokeClassObject_Parms2 dwRegister
DEFINE_DCOMAPI(CoRevokeClassObject, CoRevokeClassObject_Parms1, CoRevokeClassObject_Parms2)

#define CoRegisterClassObject_Parms1 REFCLSID rclsid, LPUNKNOWN pUnk, DWORD dwClsContext, DWORD flags, LPDWORD lpdwRegister
#define CoRegisterClassObject_Parms2 rclsid, pUnk, dwClsContext, flags, lpdwRegister
DEFINE_DCOMAPI(CoRegisterClassObject, CoRegisterClassObject_Parms1, CoRegisterClassObject_Parms2)

#define CoMarshalInterface_Parms1 LPSTREAM pStm, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags
#define CoMarshalInterface_Parms2 pStm, riid, pUnk, dwDestContext, pvDestContext, mshlflags
DEFINE_DCOMAPI(CoMarshalInterface, CoMarshalInterface_Parms1, CoMarshalInterface_Parms2)

#define CoUnmarshalInterface_Parms1 LPSTREAM pStm, REFIID riid, LPVOID FAR* ppv
#define CoUnmarshalInterface_Parms2 pStm, riid, ppv
DEFINE_DCOMAPI(CoUnmarshalInterface, CoUnmarshalInterface_Parms1, CoUnmarshalInterface_Parms2)

#define CoReleaseMarshalData_Parms1 LPSTREAM pStm
#define CoReleaseMarshalData_Parms2 pStm
DEFINE_DCOMAPI(CoReleaseMarshalData, CoReleaseMarshalData_Parms1, CoReleaseMarshalData_Parms2)

#define OleSaveToStream_Parms1 LPPERSISTSTREAM pPStm, LPSTREAM pStm
#define OleSaveToStream_Parms2 pPStm, pStm
DEFINE_DCOMAPI_START(OleSaveToStream, OleSaveToStream_Parms1, OleSaveToStream_Parms2)
	if(pPStm == NULL || pStm == NULL)
	{
		return E_INVALIDARG;
	}
	
	// Get the CLSID
	CLSID clsid;
	HRESULT hr = pPStm->GetClassID(&clsid);

	// Write it to the stream
	if(SUCCEEDED(hr))
	{
		hr = ::WriteClassStm(pStm, clsid);
	}

	// Persist the stream
	if(SUCCEEDED(hr))
	{
		hr = pPStm->Save(pStm, TRUE);
	}

	return hr;
}

#define OleLoadFromStream_Parms1 LPSTREAM pStm, REFIID iidInterface, LPVOID FAR* ppvObj
#define OleLoadFromStream_Parms2 pStm, iidInterface, ppvObj
DEFINE_DCOMAPI_START(OleLoadFromStream, OleLoadFromStream_Parms1, OleLoadFromStream_Parms2)
	if(pStm == NULL || ppvObj == NULL)
	{
		return E_INVALIDARG;
	}

	// Initialize retval to null immediately
	*ppvObj = NULL;

	// Assume there is a CLSID in the stream
	CLSID clsid;
	HRESULT hr = ::ReadClassStm(pStm, &clsid);

	// Create the coclass
	CComPtr<IUnknown> pUnk;
	if(SUCCEEDED(hr))
	{
		hr = ::CoCreateInstance(
			clsid,
			NULL,
			CLSCTX_INPROC_SERVER,
			iidInterface,
			reinterpret_cast<LPVOID*>(&pUnk));
	}

	// Load the object from the stream
	if(SUCCEEDED(hr))
	{
		CComPtr<IPersistStream> pPS;
		hr = pUnk->QueryInterface(IID_IPersistStream, reinterpret_cast<LPVOID*>(&pPS));
		
		if(SUCCEEDED(hr))
		{
			hr = pPS->Load(pStm);
		}
		
		if(SUCCEEDED(hr))
		{
			hr = pUnk->QueryInterface(iidInterface, ppvObj);
		}
	}
	
	return hr;
}


};  // namespace ATL

#endif // _WIN32_WCE

namespace ATL
{

// {B62F5910-6528-11d1-9611-0000F81E0D0D}
extern "C" const GUID GUID_ATLVer30 = { 0xb62f5910, 0x6528, 0x11d1, { 0x96, 0x11, 0x0, 0x0, 0xf8, 0x1e, 0xd, 0xd } };

// {394C3DE0-3C6F-11d2-817B-00C04F797AB7}
extern "C" const GUID GUID_ATLVer70 = { 0x394c3de0, 0x3c6f, 0x11d2, { 0x81, 0x7b, 0x0, 0xc0, 0x4f, 0x79, 0x7a, 0xb7 } };

CAtlBaseModule::CAtlBaseModule() throw()
{
	cbSize = sizeof(_ATL_BASE_MODULE);

	m_hInst = m_hInstResource = AtlGetThisModuleHandle();

#ifndef _WIN32_WCE
	m_bNT5orWin98 = false;
	OSVERSIONINFO version;
	memset(&version, 0, sizeof(version));
	version.dwOSVersionInfoSize = sizeof(version);
	::GetVersionEx(&version);
	if(version.dwPlatformId == VER_PLATFORM_WIN32_NT)
	{
		if(version.dwMajorVersion >= 5)
		{
			m_bNT5orWin98 = true;
		}
	}
	else if(version.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
	{
		if((version.dwMajorVersion > 4) || ((version.dwMajorVersion == 4) && 
			(version.dwMinorVersion > 0)))
		{
			m_bNT5orWin98 = true;
		}
	}
#endif // _WIN32_WCE

	dwAtlBuildVer = _ATL_VER;
	pguidVer = &GUID_ATLVer70;

	if (FAILED(m_csResource.Init()))
	{
		ATLTRACE(atlTraceGeneral, 0, _T("ERROR : Unable to initialize critical section in CAtlBaseModule\n"));
		ATLASSERT(0);
		CAtlBaseModule::m_bInitFailed = true;
	}
}

CAtlBaseModule::~CAtlBaseModule() throw ()
{
	m_csResource.Term();
}

bool CAtlBaseModule::AddResourceInstance(HINSTANCE hInst) throw()
{
	CComCritSecLock<CComCriticalSection> lock(m_csResource, false);
	if (FAILED(lock.Lock()))
	{
		ATLTRACE(atlTraceGeneral, 0, _T("ERROR : Unable to lock critical section in CAtlBaseModule\n"));
		ATLASSERT(0);
		return false;
	}
	return m_rgResourceInstance.Add(hInst) != FALSE;
}

bool CAtlBaseModule::RemoveResourceInstance(HINSTANCE hInst) throw()
{
	CComCritSecLock<CComCriticalSection> lock(m_csResource, false);
	if (FAILED(lock.Lock()))
	{
			ATLTRACE(atlTraceGeneral, 0, _T("ERROR : Unable to lock critical section in CAtlBaseModule\n"));
		ATLASSERT(0);
		return false;
	}
	for (int i = 0; i < m_rgResourceInstance.GetSize(); i++)
	{
		if (m_rgResourceInstance[i] == hInst)
		{
			m_rgResourceInstance.RemoveAt(i);
			return true;
		}
	}
	return false;
}
HINSTANCE CAtlBaseModule::GetHInstanceAt(int i) throw()
{
	CComCritSecLock<CComCriticalSection> lock(m_csResource, false);
	if (FAILED(lock.Lock()))
	{
		ATLTRACE(atlTraceGeneral, 0, _T("ERROR : Unable to lock critical section in CAtlBaseModule\n"));
		ATLASSERT(0);
		return NULL;
	}
	if (i > m_rgResourceInstance.GetSize() || i < 0)
	{
		return NULL;
	}

	if (i == m_rgResourceInstance.GetSize())
	{
		return m_hInstResource;
	}

	return m_rgResourceInstance[i];
}

#pragma init_seg( lib )

#ifdef _WIN32_WCE
HINSTANCE _AtlModuleInstance = NULL;
#endif // _WIN32_WCE

CAtlBaseModule	_AtlBaseModule;

};  // namespace ATL
