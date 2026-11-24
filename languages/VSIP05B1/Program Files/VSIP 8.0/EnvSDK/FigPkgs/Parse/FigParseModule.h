#pragma once

#include "Parse.h"

// Definition of the class derived from CAtlDllModuleT that
// will handle the entry points of the dll
class CFigParseModule :
    public CAtlDllModuleT<CFigParseModule>
{
public:
    DECLARE_LIBID(LIBID_PARSELib);
};
