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
// {40ED3A09-2A86-46f3-B0D3-0FD6A2513803}
DEFINE_GUID(guidToolWindowPersistance, 
0x40ED3A09, 0x2A86, 0x46f3, 0xB0, 0xD3, 0x0F, 0xD6, 0xA2, 0x51, 0x38, 0x03);

#define guidToolWindowPkg   CLSID_ToolWindowPackage

// Menu group added to the 'Views' menu for our commands
// {54562b79-9fcb-4cf4-866f-9be7b6ddcd21}
DEFINE_GUID(guidToolWindowMenuGrp, 
0xA679A6F6, 0x7C0C, 0x4930, 0xA0, 0xF9, 0x4D, 0x68, 0x7A, 0xA1, 0xDF, 0x50);

// Command set guid for our commands (used with IOleCommandTarget)
// {5987084b-604b-463c-a9e2-ee74dadf742b}
DEFINE_GUID(guidToolWindowCmdSet, 
0xF59E33F4, 0xBF77, 0x4f09, 0x9A, 0x7F, 0x23, 0x28, 0xD5, 0xF3, 0xEE, 0xBB);

#else  // _CTC_GUIDS

#define guidToolWindowPkg      { 0xAD5410E4, 0x25BA, 0x4b7a, { 0xB4, 0xF2, 0xAE, 0xBD, 0x02, 0x5B, 0x41, 0x23 } } 
#define guidToolWindowMenuGrp  { 0xA679A6F6, 0x7C0C, 0x4930, { 0xA0, 0xF9, 0x4D, 0x68, 0x7A, 0xA1, 0xDF, 0x50 } } 
#define guidToolWindowCmdSet   { 0xF59E33F4, 0xBF77, 0x4f09, { 0x9A, 0x7F, 0x23, 0x28, 0xD5, 0xF3, 0xEE, 0xBB } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
