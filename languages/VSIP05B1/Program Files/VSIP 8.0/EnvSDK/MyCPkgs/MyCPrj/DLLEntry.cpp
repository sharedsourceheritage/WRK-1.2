
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Proj.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "PrjInc.h" 

CVxModule _VxModule;
CMyCPrjModule _AtlModule;
CTraceCategory envsdkTraceGeneral(_T("envsdkTraceGeneral"));

HINSTANCE g_hInstance = NULL;

OBJECT_ENTRY_AUTO(CLSID_MyCPrjPackage, CVsPackage)
OBJECT_ENTRY_AUTO(CLSID_BuildPPG, CBuildPPG)
OBJECT_ENTRY_AUTO(CLSID_DebugPPG, CDebugPPG)


/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
    if (!PrxDllMain(hInstance, dwReason, lpReserved))
        return FALSE;
#endif
    return _AtlModule.DllMain(dwReason, lpReserved);    // ok
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
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
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
    return _AtlModule.DllRegisterServer(
        /* BOOL bRegTypeLib */ FALSE);  
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    PrxDllUnregisterServer();
#endif
    // The typelib registration is performed by CVsPackage::UpdateRegistry (vspkg.cpp),
    // so we don't need the ATL facilities for typelib registration.
    return _AtlModule.DllUnregisterServer(
        /* BOOL bRegTypeLib */ FALSE);  
}


