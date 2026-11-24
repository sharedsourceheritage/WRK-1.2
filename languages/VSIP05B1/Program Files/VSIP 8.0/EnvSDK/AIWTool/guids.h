
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

#define guidAIWToolPkg   CLSID_AIWToolPackage

// guidPersistanceSlot ID for our Automation Immediate Window tool window
// {29609E10-E480-11d1-87C1-00A0C91E2A46}
DEFINE_GUID(GUID_AutomationImmediateWindow, 
0x29609e10, 0xe480, 0x11d1, 0x87, 0xc1, 0x0, 0xa0, 0xc9, 0x1e, 0x2a, 0x46);

// {0C5C8612-4E77-11d2-976E-00A0C90A6BFE}
DEFINE_GUID(guidAIWToolMenuGrp, 
    0x0C5C8612, 0x4E77, 0x11D2, 0x97, 0x6E, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE);

// {0C5C8613-4E77-11d2-976E-00A0C90A6BFE}
DEFINE_GUID(guidAIWToolCmdSet, 
    0x0C5C8613, 0x4E77, 0x11D2, 0x97, 0x6E, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE);

#else  // _CTC_GUIDS

#define guidAIWToolPkg      { 0x0C5C8611, 0x4E77, 0x11D2, { 0x97, 0x6E, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE } }
#define guidAIWToolMenuGrp      { 0x0C5C8612, 0x4E77, 0x11D2, { 0x97, 0x6E, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE } }
#define guidAIWToolCmdSet      { 0x0C5C8613, 0x4E77, 0x11D2, { 0x97, 0x6E, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
