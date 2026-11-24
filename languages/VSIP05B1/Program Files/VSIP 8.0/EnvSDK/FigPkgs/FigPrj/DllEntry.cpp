
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// FigPrj.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f FigPrjps.mk in the project directory.

#include "stdafx.h"
#include "PrjInc.h"

// Required globals
// CVxModule required by hierutil
CVxModule _VxModule;
CVsModule _AtlModule;

CTraceCategory envsdkTraceGeneral(_T("envsdkTraceGeneral"));

HINSTANCE g_hInstance = NULL;

OBJECT_ENTRY_AUTO(CLSID_FigPrjPackage, CVsPackage)
OBJECT_ENTRY_AUTO(CLSID_OutputDirectoryPPG, COutputDirectoryPPG)

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
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry
//
//
STDAPI DllRegisterServer(void)
{
    // Note: vspkg.rgs file defines the information that gets registered
    // registers object
    // typelibs and all interfaces in typelibs are registered in UpdateRegistry (vspkg.cpp)
    return _AtlModule.DllRegisterServer();
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry
//
//
STDAPI DllUnregisterServer(void)
{
    // Note: We have to call the DllUnregisterServer with FALSE as parameter
    // because otherwise the base class will try to unregister the type libs, but
    // the registration / unregistration of them is handled by CVsPackage::UpdateRegistry
    return _AtlModule.DllUnregisterServer(FALSE);
}


/////////////////////////////////////////////////////////////////////////////
// DLLGetDocumentation
//
// Called by OLEAUT32.DLL for ITypeInfo2::GetDocumentation2.  This gives us
// a chance to return a localized string for a given help context value.
// Note helpstringdll and helpstringcontext use in the idl file
// Parameters:
//    /* [in]  */ ITypeLib *  ptlib,
//              TypeLib associated w/ help context
//    /* [in]  */ ITypeInfo * ptinfo,             
//              TypeInfo associated w/ help context
//    /* [in]  */ LCID        lcid, 
//    /* [in]  */ DWORD       dwHelpStringContext,
//              help context id being looked for
//    /* [out] */ BSTR *      pbstrHelpString )   
//              localized help string associated with the context id passed in
STDAPI DLLGetDocumentation(
    /* [in]  */ ITypeLib *  ptlib,              //TypeLib associated w/ help context
    /* [in]  */ ITypeInfo * ptinfo,             //TypeInfo associated w/ help context
    /* [in]  */ LCID        lcid, 
    /* [in]  */ DWORD       dwHelpStringContext,//help context id being looked for
    /* [out] */ BSTR *      pbstrHelpString )   //localized help string associated with the
                                                //context id passed in
{
    ExpectedPtrRet(pbstrHelpString);
    CComBSTR cbstrHelp;
    if (!cbstrHelp.LoadString(dwHelpStringContext))
        return E_FAIL;
    *pbstrHelpString = cbstrHelp.Detach();
    return S_OK;
}
