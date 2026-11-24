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

// {DD923D8A-EFFB-4791-83B1-C032A371F510}
DEFINE_GUID(GUID_guidPersistanceSlot, 
0xdd923d8a, 0xeffb, 0x4791, 0x83, 0xb1, 0xc0, 0x32, 0xa3, 0x71, 0xf5, 0x10);

// Menu group added to the 'Tool' menu for our commands
// {8521CBEB-59FC-49d3-A133-17313083E136}
DEFINE_GUID(guidOptionsPageMenuGrp, 
0x8521cbeb, 0x59fc, 0x49d3, 0xa1, 0x33, 0x17, 0x31, 0x30, 0x83, 0xe1, 0x36);

// Command set guid for our commands (used with IOleCommandTarget)
// {8393EB17-8450-4a82-9934-F500E12FE49F}
DEFINE_GUID(guidOptionsPageCmdSet, 
0x8393eb17, 0x8450, 0x4a82, 0x99, 0x34, 0xf5, 0x0, 0xe1, 0x2f, 0xe4, 0x9f);

#else  // _CTC_GUIDS


#define guidOptionsPagePkg      { 0xb0002dc2, 0x56ee, 0x4931, { 0x93, 0xf7, 0x70, 0xd6, 0xe9, 0x86, 0x39, 0x40 } }
#define guidOptionsPageMenuGrp  { 0x8521cbeb, 0x59fc, 0x49d3, { 0xa1, 0x33, 0x17, 0x31, 0x30, 0x83, 0xe1, 0x36 } }
#define guidOptionsPageCmdSet   { 0x8393eb17, 0x8450, 0x4a82, { 0x99, 0x34, 0xf5, 0x00, 0xe1, 0x2f, 0xe4, 0x9f } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
