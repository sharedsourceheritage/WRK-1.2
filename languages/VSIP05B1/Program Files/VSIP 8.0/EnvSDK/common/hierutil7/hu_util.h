//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// hu_util.h : definition of generic shared utilities
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __HU_UTIL_H__
#define __HU_UTIL_H__

#include <stdarg.h>

#ifndef  __docobj_h__
#include <DOCOBJ.H>		// OLE interfaces
#endif

#ifndef  __OBJEXT_H
#include <objext.h>		// VB6 interfaces & guids
#endif

#ifndef __TEMPL_H__
#include "templ.h"
#endif

#ifndef __ADVISLST_H__
#include "advislst.h"
#endif

#ifndef __HU_URL_H
#include "hu_url.h"
#endif

//-----------------------------------------------------------------------------
// Useful directory separator check
//-----------------------------------------------------------------------------
inline BOOL IsDirSep(CHAR ch)
{
	return ('\\' == ch || '/' == ch);
}

inline BOOL IsDirSep(WCHAR ch)
{
	return (L'\\' == ch || L'/' == ch);
}

//---------------------------------------------------------------------------
// convert a variant to a numeric or string index
// dw should be initiailzed to 0
// bstr should be initialized to NULL
// at return, if dw is non-zero then a numeric index is to be used
//			  else if bstr is non-NULL then a string index is to be used
//---------------------------------------------------------------------------
void Variant2Value(const VARIANT& vt, long &dw, BSTR &bstr);

//-----------------------------------------------------------------------------
// Execution context class. Allows program to set state about an execution through
// the use of key/value pairs. For example: the delete commaand could set the ctx
// IDYES for it's delete confirmation dialog. So when user checks "apply to all items"
// it won't prompt. The code can get back the ctx (in this case IDYES) and use
// that. The Start/EndSingleOp() method should be used at the start and end of an operation to
// flush out the context. MultiSelect handlers should use the start/end MultiOp 
// funcitons.
// The class provides a generic CANCELLED state since this applies across all items.
//-----------------------------------------------------------------------------
#define CTX_MULTISELECT  0xffffffff
class CExecutionCtx
{
public:
				CExecutionCtx();
				~CExecutionCtx();
		void	SetCancelled(){m_bCancelled = TRUE;}
		void	ClearCancelled(){m_bCancelled = FALSE;}
		void	SetMultiSelect(DWORD dwCount){SetValue(CTX_MULTISELECT, dwCount);}
		DWORD	GetMultiSelect(){return GetValue(CTX_MULTISELECT);}
		void	StartOp();
		void	EndOp();
		BOOL	IsCancelled(){return m_bCancelled;}
		DWORD	GetValue(DWORD key) { return PtrToUlong(GetValuePtr(key)); }
		void	SetValue(DWORD key, DWORD value) { SetValuePtr(key, ULongToPtr(value)); }
		void*	GetValuePtr(DWORD key);
		void	SetValuePtr(DWORD key, void* value);
		// Use nesting level to determine multiop func
		BOOL	IsMultiOp() {return m_dwRef > 1;}
		DWORD	GetRefCount() {return m_dwRef;}
		void	ClearData();
protected:
		void	Clear();

	struct CExCtx
		{
			DWORD	key;
			void*	value;
		};
		BOOL	m_bCancelled;
		DWORD	m_dwRef;	// Nesting control
		CVxTypedPtrArray<CVxPtrArray, CExCtx*> m_exCtxArray;

		CExCtx* GetExCtx(DWORD key);
};

// Useful helper to automatically do the start/end operations for you
class CExecution
{
public:
				CExecution(CExecutionCtx* pCtx) : m_pCtx(pCtx){pCtx->StartOp();};
				~CExecution() {m_pCtx->EndOp();};
protected:
	CExecutionCtx*	m_pCtx;
};


HRESULT LastWin32ErrorString(CString& strMSg);
HRESULT Win32ErrorString(DWORD dwError, CString& strMsg);

//---------------------------------------------------------------------------
// Error info class to manage error information
//---------------------------------------------------------------------------
class CErrorInfo
{
public:
	// clear errors by passing in NULL, S_OK
	HRESULT ReportError(HRESULT hRes, LPCTSTR lpszDesc);
	HRESULT ReportErrorWin32(DWORD dwError = GetLastError());

	// calls ::FormatMessage
	HRESULT __cdecl ReportError(HRESULT hRes, LPCTSTR  lpszFormat, ...);
	HRESULT __cdecl ReportError(HRESULT hRes, UINT nFormatID, ...);

	// does not clear the error
	const CString& GetReportedErrorDescription(void) const;
	HRESULT  GetReportedErrorHRESULT(void) const;

	// uses AtlReportError
	HRESULT ConvertReportedErrorToErrorInfo(const CLSID& clsid, const IID& iid = GUID_NULL);

public:		// data members
	HRESULT m_dwResult;
	CString m_strErrorDescription;
};

//---------------------------------------------------------------------------
// Simple smartptr type class to save and restore IErrorInfo.
//---------------------------------------------------------------------------
class CHierSaveAndRestoreIErrorInfo
{
public:
    CHierSaveAndRestoreIErrorInfo()
    {
        ::GetErrorInfo(0, &m_srpErrorInfo);
    }
    ~CHierSaveAndRestoreIErrorInfo()
    {
        if(m_srpErrorInfo)
            ::SetErrorInfo(0, m_srpErrorInfo);
    }
    // Returns non addref'd pointer to IErrorInfo. Note that returned value can
    // be NULL
    IErrorInfo* GetErrorInfo() {return m_srpErrorInfo;}

protected:
    CComPtr<IErrorInfo> m_srpErrorInfo;
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
template <class T> class CTmplLock {
public:
	CTmplLock(T *pThis) : m_pThis(pThis)
	{
		m_pThis->Lock();
	}
	~CTmplLock(void)
	{
		m_pThis->Unlock();
	}
	T* m_pThis;
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CAutoLock {
public:
	CAutoLock(CComObjectThreadModel::AutoCriticalSection *pLock) : m_pLock(pLock)
	{
		pLock->Lock();
	}
	~CAutoLock(void)
	{
		m_pLock->Unlock();
	}
	CComObjectThreadModel::AutoCriticalSection *m_pLock;
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CManualLock {
public:
	CManualLock(CComObjectThreadModel::CriticalSection *pLock) : m_pLock(pLock)
	{
		pLock->Lock();
	}
	~CManualLock(void)
	{
		m_pLock->Unlock();
	}
	CComObjectThreadModel::CriticalSection *m_pLock;
};

//---------------------------------------------------------------------------
// set a variable to a value
// restoring the original value of the variable at scope exit
//---------------------------------------------------------------------------
template <class T> class CSmartValueTemplate {
public:
	CSmartValueTemplate(T *pVar, T tValue) :
		m_pVariable(pVar),	m_tOriginalValue(*pVar)
	{
		*m_pVariable = tValue;
	}
	~CSmartValueTemplate(void)
	{
		Restore();
	}
	void Restore(void)
	{
		if (NULL != m_pVariable)
		{
			*m_pVariable = m_tOriginalValue;
		}
	}
	void RestoreEx(void)
	{
		Restore();
		m_pVariable = NULL;
	}

	T *m_pVariable;
	T  m_tOriginalValue;
};

HRESULT ShowContextMenu(UINT iCntxtMenuID, REFGUID GroupGuid, IOleCommandTarget* pIOleCmdTarg);
HRESULT ShowContextMenu(UINT iCntxtMenuID, REFGUID GroupGuid, IOleCommandTarget* pIOleCmdTarg, POINTS points);

BOOL LoadOLECMDTEXT(LPCTSTR pszMenuText, OLECMDTEXT* pCmdText);
BOOL LoadOLECMDTEXT(UINT nID, OLECMDTEXT* pCmdText);

//-----------------------------------------------------------------------------
// load a string from registery to BSTR with all the checkings
//-----------------------------------------------------------------------------
HRESULT UtilLoadStringToBSTR(int nID, BSTR *pbstr,
							 HINSTANCE hInstance = _AtlBaseModule.GetResourceInstance());

//-----------------------------------------------------------------------------
// convert an array of nIDS to a CALPOLESTR
// if NULL == rgVALS, pCaCookiesOut is filled out from 0 - (nCount-1)
//-----------------------------------------------------------------------------
HRESULT UtilLoadPredefinedStrings(int nCount, const int *rgIDS, const DWORD *rgVALS,
			CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut,
			HINSTANCE hInstance = _AtlBaseModule.GetResourceInstance());

//-----------------------------------------------------------------------------
// Creates a directory and all the subdirectories up to it.
//-----------------------------------------------------------------------------
BOOL UtilCreateDirectory(LPCTSTR name);

// Renames a doc in the RDT, transfers to misc files project if RDT fails, or bMoveToMiscProj
// is TRUE
HRESULT LUtilRenameOpenDoc(LPCTSTR pszOldName, LPCTSTR pszNewName, IVsUIHierarchy* pHier,
                          VSITEMID itemId, BOOL bMoveToMiscProj = FALSE);

// Returns the debug mode of the shell (design/break/shell)
DBGMODE LUtilGetDebugMode();

//----------------------------------------------------------------------------
//	Determines if the interface riid is in the ATL interface map pointed
//	to by pAIE. If an interface entry in the interface map is a chain
//	entry to a base class, this function recursively visits the interface
//	map of the base class.
//----------------------------------------------------------------------------
HRESULT UtilQuerySupport(const _ATL_INTMAP_ENTRY * pAIE, REFIID riid);

// Helper to implement ISupportErrorInfo. Place this macro in you most 
// derived class
#define IMPLEMENT_ISUPPORTERRORINFO(classname) \
public:\
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) \
	{ \
	    return UtilQuerySupport(classname##::_GetEntries(), riid); \
	}

#endif // __HU_UTIL_H__
