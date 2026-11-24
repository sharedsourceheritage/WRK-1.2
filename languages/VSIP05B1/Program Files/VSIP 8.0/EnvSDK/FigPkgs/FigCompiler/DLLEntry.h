#pragma once

#include "FigCompiler.h"

// The class derived from CAtlDllModuleT that handes the common tasks for a Dll,
// like the main entry point (DllMain) or the registration of the exposed COM objects.
class CFigCompilerModule :
    public CAtlDllModuleT<CFigCompilerModule>
{
public:
    DECLARE_LIBID(LIBID_FIGCOMPILERLib);
};
