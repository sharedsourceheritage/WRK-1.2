
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.h
//

#ifndef _CTC_GUIDS_

#include "objext.h"        // for ILocalRegistry
#include "oleipc.h"        // for ComponentUIManager

#define guidRDTViewPkg   CLSID_RDTViewPackage

// {64A0E39E-992D-42be-AC12-90077264B542}
DEFINE_GUID(guidRDTViewMenuGrp, 
	0x64a0e39e, 0x992d, 0x42be, 0xac, 0x12, 0x90, 0x07, 0x72, 0x64, 0xb5, 0x42);

// {81EAA1A9-42D9-44c5-A817-811447F837F2}
DEFINE_GUID(guidRDTViewCmdSet, 
	0x81eaa1a9, 0x42d9, 0x44c5, 0xa8, 0x17, 0x81, 0x14, 0x47, 0xf8, 0x37, 0xf2);

// {C1AE19B0-8DC9-47db-9D18-9EB1887570E3}
DEFINE_GUID(guidRDTViewToolWin, 
	0xc1ae19b0, 0x8dc9, 0x47db, 0x9d, 0x18, 0x9e, 0xb1, 0x88, 0x75, 0x70, 0xe3);

#else  // _CTC_GUIDS

#define guidRDTViewPkg		{ 0xd5cccf20, 0xa7f6, 0x4569, { 0xaa, 0x9e, 0x84, 0x5e, 0xd5, 0x7f, 0xbb, 0x74 } }
#define guidRDTViewMenuGrp	{ 0x64a0e39e, 0x992d, 0x42be, { 0xac, 0x12, 0x90, 0x07, 0x72, 0x64, 0xb5, 0x42 } }
#define guidRDTViewCmdSet	{ 0x81eaa1a9, 0x42d9, 0x44c5, { 0xa8, 0x17, 0x81, 0x14, 0x47, 0xf8, 0x37, 0xf2 } }

#endif // _CTC_GUIDS_
