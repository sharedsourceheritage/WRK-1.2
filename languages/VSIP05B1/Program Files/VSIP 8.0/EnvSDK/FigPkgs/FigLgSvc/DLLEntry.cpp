
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// FigLgSvc.cpp : Implementation of DLL Exports.

#include "stdafx.h"            // system includes
#include "initguid.h"        // only done ONCE per DLL (declares GUIDS)
#include "PrjInc.h"            // project includes
#include "figlgsvc_i.c"
#include "FigEdit_i.c"
#include "parse_i.c"

// {CB728B20-F786-11ce-92AD-00AA00A74CD0}
DEFINE_GUID(IID_IProfferService, 0xcb728b20, 0xf786, 0x11ce, 0x92, 0xad, 0x0, 0xaa, 0x0, 0xa7, 0x4c, 0xd0);

CVsComModule _AtlModule;
CTraceCategory envsdkTraceGeneral(_T("envsdkTraceGeneral"));
 
HINSTANCE g_hInstance = NULL;

OBJECT_ENTRY_AUTO(CLSID_FigLgSvcPackage, CVsPackage)


/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    lpReserved;

#ifdef _MERGE_PROXYSTUB
    if (!PrxDllMain(hInstance, dwReason, lpReserved))
        return FALSE;
#endif
    return _AtlModule.DllMain(dwReason, lpReserved);
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllCanUnloadNow() != S_OK)
        return S_FALSE;
#endif
    return _AtlModule.DllCanUnloadNow();
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
        return S_OK;
#endif
    return _AtlModule.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    HRESULT hRes = PrxDllRegisterServer();
    if (FAILED(hRes))
        return hRes;
#endif

    // Note: vspkg.rgs file defines the information that gets registered

    // registers object, typelib and all interfaces in typelib
    return _AtlModule.DllRegisterServer();
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    PrxDllUnregisterServer();
#endif
    
    return _AtlModule.DllUnregisterServer();
}

