
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// guids.h: definitions of GUIDs/IIDs/CLSIDs

#pragma once

#include "oleipc.h"      // for ComponentUIManager
#include "bscprjid.h"

// {ECA9AE30-0010-4b5e-ACA3-9448DC9AA283}
DEFINE_GUID(IID_CMyProjectCfg, 
0xeca9ae30, 0x10, 0x4b5e, 0xac, 0xa3, 0x94, 0x48, 0xdc, 0x9a, 0xa2, 0x83);

// GUID for Enterprise Framework Project Type
// {FE3BBBB6-72D5-11d2-9ACE-00C04F79A2A4}
DEFINE_GUID(GUID_EFProjectType, 
0xfe3bbbb6, 0x72d5, 0x11d2, 0x9a, 0xce, 0x0, 0xc0, 0x4f, 0x79, 0xa2, 0xa4);
