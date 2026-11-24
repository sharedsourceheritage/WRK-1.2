
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.cpp
//

#include "stdafx.h"
#include "initguid.h"
#include "Guids.h"

#ifndef VSBLDENV
#include "vsshellid.c"
#include "helpsysid.c"
#include "RDTView_i.c"
#else  // VSBLDENV
#include "RDTView_i.c"
#endif // VSBLDENV
