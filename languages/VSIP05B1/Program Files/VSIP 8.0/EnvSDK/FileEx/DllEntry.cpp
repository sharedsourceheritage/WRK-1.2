
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// DllEntry.cpp
//
// Implementation of DLL Exports
//
//*****************************************************************************

#include "stdafx.h"
#include "PrjInc.h"
#include "VsPkg.h"


CVxModule _VxModule;       // Needed by hierutil
CFileExModule _AtlModule;  // Needed by ATL
CTraceCategory envsdkTraceGeneral(_T("envsdkTraceGeneral"));

OBJECT_ENTRY_AUTO(CLSID_FileExPackage, CFileExPackage)


VSDEFINE_SWITCH(g_fEnableTrace, "FileEx", "Enable OutputDebugString");
VSDEFINE_SWITCH(g_fFileExObjCtorDtor, "FileEx", "Trace object ctors and dtors");

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" DllMain \n") );

    return _AtlModule.DllMain(dwReason, lpReserved);    // ok
}


/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" DllCanUnloadNow \n") );

    return _AtlModule.DllCanUnloadNow();
}


/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" DllGetClassObject \n") );

    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry
//
//
STDAPI DllRegisterServer(void)
{
    return _AtlModule.DllRegisterServer(TRUE);
}


/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry
//
//
STDAPI DllUnregisterServer(void)
{
    return _AtlModule.DllUnregisterServer(TRUE);
}

