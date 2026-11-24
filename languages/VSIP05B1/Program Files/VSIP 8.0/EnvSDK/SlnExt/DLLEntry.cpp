
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// SlnExt.cpp : Implementation of DLL Exports.

// Note: Proxy/Stub Information
//        To build a separate proxy/stub DLL, 
//        run nmake -f SlnExtps.mk in the project directory.

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"
#include "AutomationExtenders.h"


CVsComModule _AtlModule;

OBJECT_ENTRY_AUTO(CLSID_SlnExtPackage, CSlnExtPackage)
OBJECT_ENTRY_AUTO(CLSID_SlnStaticExtenderProvider, CSlnStaticExtenderProvider)

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    return _AtlModule.DllMain(dwReason, lpReserved);
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.GetClassObject(rclsid, riid, ppv);
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object
    // typelibs and all interfaces in typelibs are registered in UpdateRegistry (vspkg.cpp)
    return _AtlModule.RegisterServer(
        /* BOOL bRegTypeLib */ FALSE);  
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    // typelibs and all interfaces in typelibs are unregistered in UpdateRegistry (vspkg.cpp)
    return _AtlModule.UnregisterServer(FALSE);
}

