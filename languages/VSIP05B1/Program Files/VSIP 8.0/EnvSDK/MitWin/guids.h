
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.h
//

// do not use #pragma once - used by ctc compiler
#ifndef __GUIDS_H_
#define __GUIDS_H_

#ifndef _CTC_GUIDS_


// guidPersistanceSlot ID for our Tool Window
DEFINE_GUID(GUID_MWTool, 
0x9BF42815, 0x409E, 0x4ce2, 0x93, 0x9A, 0xB7, 0x66, 0x86, 0xB0, 0xE0, 0x61);

#define guidMitWinPkg   CLSID_MitWinPackage

// Menu group added to the 'Views' menu for our commands
DEFINE_GUID(guidMitWinMenuGrp, 
    0xD88353D1, 0x611D, 0x4977, 0xB9, 0x63, 0x62, 0xBB, 0xE4, 0xA1, 0x73, 0xDD);

// Command set guid for our commands (used with IOleCommandTarget)
DEFINE_GUID(guidMitWinCmdSet, 
    0xAB657FB0, 0xB800, 0x4633, 0xAC, 0x1A, 0xEB, 0xD0, 0xE7, 0x42, 0xD6, 0x59);



#else  // _CTC_GUIDS

#define guidMitWinPkg       { 0x3CEF0176, 0x3736, 0x4c41, { 0x99, 0xDB, 0x75, 0x86, 0x63, 0xE1, 0x74, 0x25 } }
#define guidMitWinMenuGrp   { 0xD88353D1, 0x611D, 0x4977, { 0xB9, 0x63, 0x62, 0xBB, 0xE4, 0xA1, 0x73, 0xDD } }
#define guidMitWinCmdSet    { 0xAB657FB0, 0xB800, 0x4633, { 0xAC, 0x1A, 0xEB, 0xD0, 0xE7, 0x42, 0xD6, 0x59 } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
