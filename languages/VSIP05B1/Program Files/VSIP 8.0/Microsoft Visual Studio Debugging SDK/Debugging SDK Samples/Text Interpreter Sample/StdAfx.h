// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__E54530B6_1C40_4BB2_93A5_502082025ADC__INCLUDED_)
#define AFX_STDAFX_H__E54530B6_1C40_4BB2_93A5_502082025ADC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
#include "msdbg.h"

#define WM_CONTINUE_SYNC_EVENT WM_USER + 0x99
#define WM_CONTINUE  WM_USER + 0x9A

class CExeModule : 
    public CAtlExeModuleT<CExeModule>
{
private:
    typedef CAtlExeModuleT<CExeModule> base;
public:
   HRESULT RegisterServer(
      BOOL bRegTypeLib = FALSE, const CLSID* pCLSID = NULL);
   HRESULT UnregisterServer(
      BOOL bUnRegTypeLib, const CLSID* pCLSID = NULL);
       LONG Unlock();
    DWORD dwThreadID;
    HANDLE hEventShutdown;
    void MonitorShutdown();
    bool StartMonitor();
    bool bActivity;
};
extern CExeModule _AtlModule;
#include <atlcom.h>

#include "TextInterpreterAtl.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E54530B6_1C40_4BB2_93A5_502082025ADC__INCLUDED)
