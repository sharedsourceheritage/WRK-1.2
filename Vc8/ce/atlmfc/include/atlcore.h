// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

#ifndef __ATLCORE_H__
#define __ATLCORE_H__

#pragma once

#ifdef _ATL_ALL_WARNINGS
#pragma warning( push )
#endif

#pragma warning(disable: 4786) // identifier was truncated in the debug information

#include <atldef.h>
#include <windows.h>
#include <ole2.h>

#include <limits.h>
#include <tchar.h>
#ifndef _WIN32_WCE
#include <mbstring.h>
#endif

#ifdef _WIN32_WCE
#include <altcecrt.h>
#endif

namespace ATL
{

// Allow AtlGetThisModuleHandle to be overriden on WinCE implementations.
// This may be necessary if the application needs to use a custom entry point.
#if !defined(_WIN32_WCE) || !defined(AtlGetThisModuleHandle)

/////////////////////////////////////////////////////////////////////////////
// _AtlGetThisModuleHandle

#if !defined(_delayimp_h) && !defined(_WIN32_WCE)
extern "C" IMAGE_DOS_HEADER __ImageBase;
#endif

#ifdef _WIN32_WCE
extern HINSTANCE _AtlModuleInstance;
#endif

inline HINSTANCE _AtlGetThisModuleHandle()
{
#ifndef _WIN32_WCE
	return reinterpret_cast<HINSTANCE>(&__ImageBase);
#else // _WIN32_WCE
	// If _AtlModuleInstance is NULL then the 'this' module is the .exe for for the process.
	if(_AtlModuleInstance == NULL)
	{
		return GetModuleHandle(NULL);
	}
	else // else _AtlModuleInstance has the handle for the 'this' module
	{
		return _AtlModuleInstance;
	}
#endif // _WIN32_WCE
}

#define AtlGetThisModuleHandle _AtlGetThisModuleHandle

#endif // !defined(_WIN32_WCE) || !defined(AtlGetThisModuleHandle)

#if defined(_ATL_STATIC_LIB_IMPL) || defined(_ATL_DLL_IMPL)

HRESULT CoDisconnectObject(LPUNKNOWN pUnk, DWORD dwReserved);

HRESULT CoInitialize(LPVOID pvReserved);

HRESULT CoRevokeClassObject(DWORD dwRegister);

HRESULT CoRegisterClassObject(REFCLSID rclsid, LPUNKNOWN pUnk, DWORD dwClsContext, DWORD flags, LPDWORD lpdwRegister);

HRESULT CoMarshalInterface(LPSTREAM pStm, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags);

HRESULT CoUnmarshalInterface(LPSTREAM pStm, REFIID riid, LPVOID FAR* ppv);

HRESULT CoReleaseMarshalData(LPSTREAM pStm);

#endif // defined(_ATL_STATIC_LIB_IMPL) || defined(_ATL_DLL_IMPL)

#if defined(_ATL_STATIC_LIB_IMPL) || defined(_ATL_DLL_IMPL) || !defined(_CE_DCOM)

HRESULT OleSaveToStream(LPPERSISTSTREAM pPStm, LPSTREAM pStm);

HRESULT OleLoadFromStream(LPSTREAM pStm, REFIID iidInterface, LPVOID FAR* ppvObj);

#endif // defined(_ATL_STATIC_LIB_IMPL) || defined(_ATL_DLL_IMPL) || !defined(_CE_DCOM)

} // namespace ATL

#include <atlchecked.h>
#include <atlsimpcoll.h>
#include <atlosapice.h>

#pragma pack(push,_ATL_PACKING)
namespace ATL
{
/////////////////////////////////////////////////////////////////////////////
// Verify that a null-terminated string points to valid memory
inline BOOL AtlIsValidString(LPCWSTR psz, size_t nMaxLength = INT_MAX)
{
	(nMaxLength);
	return (psz != NULL);
}

// Verify that a null-terminated string points to valid memory
inline BOOL AtlIsValidString(LPCSTR psz, size_t nMaxLength = UINT_MAX)
{
	(nMaxLength);
	return (psz != NULL);
}

// Verify that a pointer points to valid memory
inline BOOL AtlIsValidAddress(const void* p, size_t nBytes,
	BOOL bReadWrite = TRUE)
{
	(bReadWrite);
	(nBytes);
	return (p != NULL);
}

template<typename T>
inline void AtlAssertValidObject(const T *pOb)
{
	ATLASSERT(pOb);
	ATLASSERT(AtlIsValidAddress(pOb, sizeof(T)));
	if(pOb)
		pOb->AssertValid();
}
#ifdef _DEBUG
#define ATLASSERT_VALID(x) ATL::AtlAssertValidObject(x)
#else
#define ATLASSERT_VALID(x) __noop;
#endif

// COM Sync Classes
class CComCriticalSection
{
public:
	CComCriticalSection() throw()
	{
		memset(&m_sec, 0, sizeof(CRITICAL_SECTION));
	}
	~CComCriticalSection()
	{
	}
	HRESULT Lock() throw()
	{
		EnterCriticalSection(&m_sec);
		return S_OK;
	}
	HRESULT Unlock() throw()
	{
		LeaveCriticalSection(&m_sec);
		return S_OK;
	}
	HRESULT Init() throw()
	{
		HRESULT hRes = E_FAIL;
		__try
		{
			InitializeCriticalSection(&m_sec);
			hRes = S_OK;
		}
		// structured exception may be raised in low memory situations
		__except(STATUS_NO_MEMORY == GetExceptionCode())
		{			
			hRes = E_OUTOFMEMORY;		
		}
		return hRes;
	}

	HRESULT Term() throw()
	{
		DeleteCriticalSection(&m_sec);
		return S_OK;
	}	
	CRITICAL_SECTION m_sec;
};

class CComAutoCriticalSection : public CComCriticalSection
{
public:
	CComAutoCriticalSection()
	{
		HRESULT hr = CComCriticalSection::Init();
		if (FAILED(hr))
			AtlThrow(hr);
	}
	~CComAutoCriticalSection() throw()
	{
		CComCriticalSection::Term();
	}
private :
	HRESULT Init(); // Not implemented. CComAutoCriticalSection::Init should never be called
	HRESULT Term(); // Not implemented. CComAutoCriticalSection::Term should never be called
};

class CComSafeDeleteCriticalSection : public CComCriticalSection
{
public:
	CComSafeDeleteCriticalSection(): m_bInitialized(false) 
	{
	}

	~CComSafeDeleteCriticalSection() throw()
	{
		if (!m_bInitialized)
		{
			return;
		}
		m_bInitialized = false;
		CComCriticalSection::Term();
	}

	HRESULT Init() throw()
	{
		ATLASSERT( !m_bInitialized );
		HRESULT hr = CComCriticalSection::Init();
		if (SUCCEEDED(hr))
		{
			m_bInitialized = true;
		}
		return hr;
	}

	HRESULT Term() throw()
	{
		if (!m_bInitialized)
		{
			return S_OK;
		}
		m_bInitialized = false;
		return CComCriticalSection::Term();
	}

	HRESULT Lock()
	{
		// CComSafeDeleteCriticalSection::Init or CComAutoDeleteCriticalSection::Init
		// not called or failed.
		// m_critsec member of CComObjectRootEx is now of type 
		// CComAutoDeleteCriticalSection. It has to be initialized
		// by calling CComObjectRootEx::_AtlInitialConstruct
		ATLASSUME(m_bInitialized);
		return CComCriticalSection::Lock();
	}

private:
	bool m_bInitialized;
};

class CComAutoDeleteCriticalSection : public CComSafeDeleteCriticalSection
{
private:
	// CComAutoDeleteCriticalSection::Term should never be called
	HRESULT Term() throw();
};

class CComFakeCriticalSection
{
public:
	HRESULT Lock() throw() { return S_OK; }
	HRESULT Unlock() throw() { return S_OK; }
	HRESULT Init() throw() { return S_OK; }
	HRESULT Term() throw() { return S_OK; }
};

/////////////////////////////////////////////////////////////////////////////
// Module 

// Used by any project that uses ATL
struct _ATL_BASE_MODULE70
{
	UINT cbSize;
	HINSTANCE m_hInst;
	HINSTANCE m_hInstResource;
#ifndef _WIN32_WCE
	bool m_bNT5orWin98;
#endif // _WIN32_WCE
	DWORD dwAtlBuildVer;
	const GUID* pguidVer;
	CComCriticalSection m_csResource;
	CSimpleArray<HINSTANCE> m_rgResourceInstance;
};
typedef _ATL_BASE_MODULE70 _ATL_BASE_MODULE;

class CAtlBaseModule : public _ATL_BASE_MODULE
{
public :
	static bool m_bInitFailed;
	CAtlBaseModule() throw();
	~CAtlBaseModule() throw ();

	HINSTANCE GetModuleInstance() throw()
	{
		return m_hInst;
	}
	HINSTANCE GetResourceInstance() throw()
	{
		return m_hInstResource;
	}
	HINSTANCE SetResourceInstance(HINSTANCE hInst) throw()
	{
		return static_cast< HINSTANCE >(InterlockedExchangePointer((void**)&m_hInstResource, hInst));
	}

	bool AddResourceInstance(HINSTANCE hInst) throw();
	bool RemoveResourceInstance(HINSTANCE hInst) throw();
	HINSTANCE GetHInstanceAt(int i) throw();
};

__declspec(selectany) bool CAtlBaseModule::m_bInitFailed = false;
extern CAtlBaseModule _AtlBaseModule;

/////////////////////////////////////////////////////////////////////////////
// String resource helpers

#pragma warning(push)
#pragma warning(disable: 4200)
	struct ATLSTRINGRESOURCEIMAGE
	{
		WORD nLength;
		WCHAR achString[];
	};
#pragma warning(pop)	// C4200

inline const ATLSTRINGRESOURCEIMAGE* _AtlGetStringResourceImage( HINSTANCE hInstance, HRSRC hResource, UINT id ) throw()
{
	const ATLSTRINGRESOURCEIMAGE* pImage;
	const ATLSTRINGRESOURCEIMAGE* pImageEnd;
	ULONG nResourceSize;
	HGLOBAL hGlobal;
	UINT iIndex;

	hGlobal = ::LoadResource( hInstance, hResource );
	if( hGlobal == NULL )
	{
		return( NULL );
	}

	pImage = (const ATLSTRINGRESOURCEIMAGE*)::LockResource( hGlobal );
	if( pImage == NULL )
	{
		return( NULL );
	}

	nResourceSize = ::SizeofResource( hInstance, hResource );
	pImageEnd = (const ATLSTRINGRESOURCEIMAGE*)(LPBYTE( pImage )+nResourceSize);
	iIndex = id&0x000f;

	while( (iIndex > 0) && (pImage < pImageEnd) )
	{
		pImage = (const ATLSTRINGRESOURCEIMAGE*)(LPBYTE( pImage )+(sizeof( ATLSTRINGRESOURCEIMAGE )+(pImage->nLength*sizeof( WCHAR ))));
		iIndex--;
	}
	if( pImage >= pImageEnd )
	{
		return( NULL );
	}
	if( pImage->nLength == 0 )
	{
		return( NULL );
	}

	return( pImage );
}

inline const ATLSTRINGRESOURCEIMAGE* AtlGetStringResourceImage( HINSTANCE hInstance, UINT id ) throw()
{
	HRSRC hResource;

	hResource = ::FindResource( hInstance, MAKEINTRESOURCE( ((id>>4)+1) ), RT_STRING );
	if( hResource == NULL )
	{
		return( NULL );
	}

	return _AtlGetStringResourceImage( hInstance, hResource, id );
}

#ifndef _WIN32_WCE
inline const ATLSTRINGRESOURCEIMAGE* AtlGetStringResourceImage( HINSTANCE hInstance, UINT id, WORD wLanguage ) throw()
{
	HRSRC hResource;

	hResource = ::FindResourceEx( hInstance, RT_STRING, MAKEINTRESOURCE( ((id>>4)+1) ), wLanguage );
	if( hResource == NULL )
	{
		return( NULL );
	}

	return _AtlGetStringResourceImage( hInstance, hResource, id );
}
#endif // _WIN32_WCE

inline const ATLSTRINGRESOURCEIMAGE* AtlGetStringResourceImage( UINT id ) throw()
{
	const ATLSTRINGRESOURCEIMAGE* p = NULL;
	HINSTANCE hInst = _AtlBaseModule.GetHInstanceAt(0);

	for (int i = 1; hInst != NULL && p == NULL; hInst = _AtlBaseModule.GetHInstanceAt(i++))
	{
		p = AtlGetStringResourceImage(hInst, id);
	}
	return p;
}

#ifndef _WIN32_WCE
inline const ATLSTRINGRESOURCEIMAGE* AtlGetStringResourceImage( UINT id, WORD wLanguage ) throw()
{
	const ATLSTRINGRESOURCEIMAGE* p = NULL;
	HINSTANCE hInst = _AtlBaseModule.GetHInstanceAt(0);

	for (int i = 1; hInst != NULL && p == NULL; hInst = _AtlBaseModule.GetHInstanceAt(i++))
	{
		p = AtlGetStringResourceImage(hInst, id, wLanguage);
	}
	return p;
}
#endif // _WIN32_WCE

inline int AtlLoadString(__in UINT nID, __out_ecount_part_z(nBufferMax, return + 1) LPTSTR lpBuffer, __in int nBufferMax) throw()
{
	HINSTANCE hInst = _AtlBaseModule.GetHInstanceAt(0);
	int nRet = 0;

	for (int i = 1; hInst != NULL && nRet == 0; hInst = _AtlBaseModule.GetHInstanceAt(i++))
	{
		nRet = LoadString(hInst, nID, lpBuffer, nBufferMax);
	}
	return nRet;
}

inline HINSTANCE AtlFindResourceInstance(LPCTSTR lpName, LPCTSTR lpType, WORD wLanguage = 0) throw()
{
	ATLASSERT(lpType != RT_STRING);	// Call AtlFindStringResourceInstance to find the string
	if (lpType == RT_STRING)
		return NULL;

	if (ATL_IS_INTRESOURCE(lpType))
	{
		/* Prefast false warnings caused by bad-shaped definition of MAKEINTRESOURCE macro from PSDK */
		if (lpType == ATL_RT_ICON)
		{
			lpType = ATL_RT_GROUP_ICON;
		}
		else if (lpType == ATL_RT_CURSOR)
		{
			lpType = ATL_RT_GROUP_CURSOR;
		}
	}

	HINSTANCE hInst = _AtlBaseModule.GetHInstanceAt(0);
	HRSRC hResource = NULL;

	for (int i = 1; hInst != NULL; hInst = _AtlBaseModule.GetHInstanceAt(i++))
	{
#ifndef _WIN32_WCE
		hResource = ::FindResourceEx(hInst, lpType, lpName, wLanguage);
#else // _WIN32_WCE
		(wLanguage);
		hResource = ::FindResource(hInst, lpName, lpType);
#endif // _WIN32_WCE
		if (hResource != NULL)
		{
			return hInst;
		}
	}

	return NULL;
}

inline HINSTANCE AtlFindResourceInstance(UINT nID, LPCTSTR lpType, WORD wLanguage = 0) throw()
{
	return AtlFindResourceInstance(MAKEINTRESOURCE(nID), lpType, wLanguage);
}

inline HINSTANCE AtlFindStringResourceInstance(UINT nID, WORD wLanguage = 0) throw()
{
	const ATLSTRINGRESOURCEIMAGE* p = NULL;
	HINSTANCE hInst = _AtlBaseModule.GetHInstanceAt(0);

	for (int i = 1; hInst != NULL && p == NULL; hInst = _AtlBaseModule.GetHInstanceAt(i++))
	{
#ifndef _WIN32_WCE
		p = AtlGetStringResourceImage(hInst, nID, wLanguage);
#else // _WIN32_WCE
		(wLanguage);
		p = AtlGetStringResourceImage(hInst, nID);
#endif // _WIN32_WCE
		if (p != NULL)
			return hInst;
	}

	return NULL;
}

/* 
Needed by both atlcomcli and atlsafe, so needs to be in here 
*/
inline HRESULT AtlSafeArrayGetActualVartype
(
    SAFEARRAY *psaArray,
    VARTYPE *pvtType
)
{
    HRESULT hrSystem=ATL::SafeArrayGetVartype(psaArray, pvtType);

    /*
    For Windows CE, SafeArrayGetVartype only supports SAFEARRAY's 
    with a VARTYPE of VT_BSTR, VT_VARIANT, VT_UNKNOWN, and VT_DISPATCH
    */

#ifndef _WIN32_WCE
    if(FAILED(hrSystem))
    {
        return hrSystem;
    }

    /* 
    When Windows has a SAFEARRAY of type VT_DISPATCH with FADF_HAVEIID,
    it returns VT_UNKNOWN instead of VT_DISPATCH. We patch the value to be correct
    This isn't necessary for Windows CE, as VT_DISPATCH is always returned if
    FADF_DISPATCH regardless of whether FADF_HAVEIID is set.
    */
    if(pvtType && *pvtType==VT_UNKNOWN)
    {
        if(psaArray && ((psaArray->fFeatures & FADF_HAVEIID)!=0))
        {
            if(psaArray->fFeatures & FADF_DISPATCH)
            {
                *pvtType=VT_DISPATCH;
            }
        }
    }
#endif // _WIN32_WCE

    return hrSystem;
}
template <typename _CharType>
inline _CharType* AtlCharNext(const _CharType* p) throw()
{
	ATLASSUME(p != NULL);	// Too expensive to check separately here 
#ifndef _WIN32_WCE
	if (*p == '\0')  // ::CharNextA won't increment if we're at a \0 already
#endif // _WIN32_WCE
		return const_cast<_CharType*>(p+1);
#ifndef _WIN32_WCE // This will only work for ANSI not MBCS, but MBCS isn't supported on CE.
	else
		return ::CharNextA(p);
#endif // _WIN32_WCE
}

template <>
inline wchar_t* AtlCharNext<wchar_t>(const wchar_t* p) throw()
{
	return const_cast< wchar_t* >( p+1 );
}
template<typename CharType>
inline const CharType* AtlstrchrT(const CharType* p, CharType ch) throw()
{
	ATLASSERT(p != NULL);	
	if(p==NULL)
	{
		return NULL;
	}
	while( *p != 0 )
	{
		if (*p == ch)
		{
			return p;
		}
		p = AtlCharNext(p);
	}
	//strchr for '\0' should succeed - the while loop terminates 
	//*p == 0, but ch also == 0, so NULL terminator address is returned
	return (*p == ch) ? p : NULL;
}
//Ansi and Unicode versions of printf, used with templated CharType trait classes.
#pragma warning(push)
#pragma warning(disable : 4793)
template<typename CharType>
inline int AtlprintfT(const CharType* pszFormat,... ) throw()
{
	int retval=0;
	va_list argList;
	va_start( argList, pszFormat );
	retval=vprintf(pszFormat,argList);
	va_end( argList );
	return retval;
}
#pragma warning(pop)

#pragma warning(push)
#pragma warning(disable : 4793)
template<>
inline int AtlprintfT(const wchar_t* pszFormat,... ) throw()
{
	int retval=0;
	va_list argList;
	va_start( argList, pszFormat );
	retval=vwprintf(pszFormat,	argList);
	va_end( argList );
	return retval;
}
#pragma warning(pop)

inline BOOL AtlConvertSystemTimeToVariantTime(const SYSTEMTIME& systimeSrc,double* pVarDtTm)
{
	ATLENSURE(pVarDtTm!=NULL);
	//Convert using ::SystemTimeToVariantTime and store the result in pVarDtTm then
	//convert variant time back to system time and compare to original system time.	
	BOOL ok = ::SystemTimeToVariantTime(const_cast<SYSTEMTIME*>(&systimeSrc), pVarDtTm);
	SYSTEMTIME sysTime;
	::ZeroMemory(&sysTime, sizeof(SYSTEMTIME));

	ok = ok && ::VariantTimeToSystemTime(*pVarDtTm, &sysTime);
	ok = ok && (systimeSrc.wYear == sysTime.wYear &&
			systimeSrc.wMonth == sysTime.wMonth &&
			systimeSrc.wDay == sysTime.wDay &&
			systimeSrc.wHour == sysTime.wHour &&
			systimeSrc.wMinute == sysTime.wMinute && 
			systimeSrc.wSecond == sysTime.wSecond);

	return ok;
}
/////////////////////////////////////////////////////////////////////////////
//

#if !defined(_WIN32_WCE) || (!defined(_ATL_CE_VALIDATE_THREADID) && (defined(_CE_DCOM) ||defined(_ATL_NO_CE_VALIDATE_THREADID)))

#define DECLARE_CE_THREADID_VALIDATION
#define CE_VALIDATE_THREADID() (void(0))
#define CE_VALIDATE_THREADID_ASSERT() (void(0))
#define CE_VALIDATE_THREADID_RETURN(r) (void(0))
#define CE_VALIDATE_THREADID_THROW(e) (void(0))

#else // !defined(_WIN32_WCE) || defined(_ATL_NO_CE_VALIDATE_THREADID)

#ifdef _ATL_NO_CE_VALIDATE_THREADID
	#undef _ATL_NO_CE_VALIDATE_THREADID
	#pragma message("_ATL_NO_CE_VALIDATE_THREADID undefined due _ATL_CE_VALIDATE_THREADID being defined")
#endif // _ATL_CE_VALIDATE_THREADID

class CAtlCEValidateThreadIDDefault
{
public:
	CAtlCEValidateThreadIDDefault() :
		m_threadID(GetCurrentThreadId())
	{
	}
	bool Validate()
	{
		return (GetCurrentThreadId() == m_threadID);
	}
private:
	DWORD m_threadID;
};

#define _ATL_CE_VALIDATE_THREADID

#ifndef DECLARE_CE_THREADID_VALIDATION
#define DECLARE_CE_THREADID_VALIDATION CAtlCEValidateThreadIDDefault m_threadValidator;
#endif

#ifndef CE_VALIDATE_THREADID
#define CE_VALIDATE_THREADID() (m_threadValidator.Validate())
#endif

#define CE_VALIDATE_THREADID_ASSERT() \
	(ATLASSERT(CE_VALIDATE_THREADID()))
	
#define CE_VALIDATE_THREADID_RETURN(r) \
	if(CE_VALIDATE_THREADID()) return r
		
#define CE_VALIDATE_THREADID_THROW(e) \
	if(CE_VALIDATE_THREADID()) throw e
		
#endif // !defined(_WIN32_WCE) || defined(_ATL_NO_CE_VALIDATE_THREADID)

#if !defined(_WIN32_WCE) || (!defined(_ATL_STATIC_LIB_IMPL) && !defined(_ATL_DLL_IMPL) && defined(_CE_DCOM))
using ::CoDisconnectObject;
using ::CoInitialize;
using ::CoRevokeClassObject;
using ::CoRegisterClassObject;
using ::CoReleaseMarshalData;
using ::CoMarshalInterface;
using ::CoUnmarshalInterface;
using ::OleSaveToStream;
using ::OleLoadFromStream;
#endif // !defined(_WIN32_WCE) || (!defined(_ATL_STATIC_LIB_IMPL) && !defined(_ATL_DLL_IMPL) && defined(_CE_DCOM))

}	// namespace ATL
#pragma pack(pop)

#ifdef _ATL_ALL_WARNINGS
#pragma warning( pop )
#endif

#endif	// __ATLCORE_H__
