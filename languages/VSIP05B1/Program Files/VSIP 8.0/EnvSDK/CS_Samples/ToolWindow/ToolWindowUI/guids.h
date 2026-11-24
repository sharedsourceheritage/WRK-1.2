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
// {7259e420-6241-4e0d-b535-5b820671d183}
DEFINE_GUID(GUID_guidPersistanceSlot, 
0x7259E420, 0x6241, 0x4E0D, 0xB5, 0x35, 0x5B, 0x82, 0x6, 0x71, 0xD1, 0x83);

#define guidToolWindowPkg   CLSID_ToolWindowPackage

// Menu group added to the 'Tool' menu for our commands
// {1f991f62-e5a4-48e9-97d0-0ac5f69f0ffe}
DEFINE_GUID(guidToolWindowMenuGrp, 
0x1F991F62, 0xE5A4, 0x48E9, 0x97, 0xD0, 0xA, 0xC5, 0xF6, 0x9F, 0xF, 0xFE);

// Command set guid for our commands (used with IOleCommandTarget)
// {d5ac54dc-170e-45fc-be1f-245dea6710ea}
DEFINE_GUID(guidToolWindowCmdSet, 
0xD5AC54DC, 0x170E, 0x45FC, 0xBE, 0x1F, 0x24, 0x5D, 0xEA, 0x67, 0x10, 0xEA);

#else  // _CTC_GUIDS


#define guidToolWindowPkg      { 0x7259E420, 0x6241, 0x4E0D, { 0xB5, 0x35, 0x5B, 0x82, 0x6, 0x71, 0xD1, 0x83 } }
#define guidToolWindowMenuGrp  { 0x1F991F62, 0xE5A4, 0x48E9, { 0x97, 0xD0, 0xA, 0xC5, 0xF6, 0x9F, 0xF, 0xFE } }
#define guidToolWindowCmdSet   { 0xD5AC54DC, 0x170E, 0x45FC, { 0xBE, 0x1F, 0x24, 0x5D, 0xEA, 0x67, 0x10, 0xEA } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
