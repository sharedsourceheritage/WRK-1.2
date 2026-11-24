
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Proj.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "vspkg.h"
#include "projcfg.h"

CVxModule _VxModule;
CBscPrjModule _AtlModule;
CTraceCategory envsdkTraceGeneral(_T("envsdkTraceGeneral"));

HINSTANCE g_hInstance = NULL;

OBJECT_ENTRY_AUTO(CLSID_BscPrjPackage, CVsPackage)
OBJECT_ENTRY_AUTO(CLSID_LaunchPPG, CLaunchPPG)
OBJECT_ENTRY_AUTO(CLSID_CustomPPG, CCustomPPG)


/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
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
    // registers object
    // typelibs and all interfaces in typelibs are registered in UpdateRegistry (vspkg.cpp)
    return _AtlModule.RegisterServer(
        /* BOOL bRegTypeLib */ FALSE);  
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    PrxDllUnregisterServer();
#endif
    // Note: Type Libs are registered/Unregistered in vspkg.cpp, so we don't need to use
    // the facility provided by ATL.
    return _AtlModule.UnregisterServer(FALSE);
}
