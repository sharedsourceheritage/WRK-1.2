#pragma once

#include "FigPrj.h"

// This class, derived from CAtlDllModule, is required by ATL.
class CVsModule :
    public CAtlDllModuleT<CVsModule>
{
public:
    DECLARE_LIBID(LIBID_FigPrjPKGLib);

    HINSTANCE GetResourceInstance() { return _AtlBaseModule.GetResourceInstance(); }
    HINSTANCE SetResourceInstance(HINSTANCE hInst) { return _AtlBaseModule.SetResourceInstance(hInst); }
    HINSTANCE GetModuleInstance() throw() { return _AtlBaseModule.GetModuleInstance(); }

    HRESULT RegisterTypeLib(LPCTSTR lpszIndex) { return _AtlComModule.RegisterTypeLib(lpszIndex); }
    HRESULT UnRegisterTypeLib(LPCTSTR lpszIndex) { return _AtlComModule.UnRegisterTypeLib(lpszIndex); }
};
