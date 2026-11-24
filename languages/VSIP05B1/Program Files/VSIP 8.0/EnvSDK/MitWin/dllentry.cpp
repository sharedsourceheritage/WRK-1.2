
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// DllEntry.cpp : Implementation of DLL Exports.

// Note: Proxy/Stub Information
//        To build a separate proxy/stub DLL, 
//        run nmake -f MitWinps.mk in the project directory.

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"

CVsComModule _AtlModule;

CTraceCategory envsdkTraceGeneral(_T("envsdkTraceGeneral"));

OBJECT_ENTRY_AUTO(CLSID_MitWinPackage, CMitWinPackage)

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    ATLTRACE(TEXT("MitWin: DllMain \n"));

    return _AtlModule.DllMain(dwReason, lpReserved);
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    ATLTRACE(TEXT("MitWin: DllCanUnloadNow \n"));
    return _AtlModule.DllCanUnloadNow();
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    ATLTRACE(TEXT("MitWin: DllGetClassObject \n"));
    return _AtlModule.GetClassObject(rclsid, riid, ppv);
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry
//
//
STDAPI DllRegisterServer(void)
{
    return _AtlModule.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry
//
//
STDAPI DllUnregisterServer(void)
{
    return _AtlModule.UnregisterServer(TRUE);
}
