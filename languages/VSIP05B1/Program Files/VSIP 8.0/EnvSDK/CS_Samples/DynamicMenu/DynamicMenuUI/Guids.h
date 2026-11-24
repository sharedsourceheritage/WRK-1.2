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
// {ce9cc1aa-4eb1-4068-b584-ffa55d7b10a9}
DEFINE_GUID(GUID_guidPersistanceSlot, 
0xCE9CC1AA, 0x4EB1, 0x4068, 0xB5, 0x84, 0xFF, 0xA5, 0x5D, 0x7B, 0x10, 0xA9);

#define guidDynamicMenuPkg   CLSID_DynamicMenuPackage

// Menu group added to the 'Tool' menu for our commands
// {2b167292-db7c-466f-aadc-ded61794b688}
DEFINE_GUID(guidDynamicMenuMenuGrp, 
0x2B167292, 0xDB7C, 0x466F, 0xAA, 0xDC, 0xDE, 0xD6, 0x17, 0x94, 0xB6, 0x88);

// Command set guid for our commands (used with IOleCommandTarget)
// {38da9fea-35df-4167-ae94-daa3a5cf2de4}
DEFINE_GUID(guidDynamicMenuCmdSet, 
0x38DA9FEA, 0x35DF, 0x4167, 0xAE, 0x94, 0xDA, 0xA3, 0xA5, 0xCF, 0x2D, 0xE4);

#else  // _CTC_GUIDS


#define guidDynamicMenuPkg      { 0xCE9CC1AA, 0x4EB1, 0x4068, { 0xB5, 0x84, 0xFF, 0xA5, 0x5D, 0x7B, 0x10, 0xA9 } }
#define guidDynamicMenuMenuGrp  { 0x2B167292, 0xDB7C, 0x466F, { 0xAA, 0xDC, 0xDE, 0xD6, 0x17, 0x94, 0xB6, 0x88 } }
#define guidDynamicMenuCmdSet	  { 0x38DA9FEA, 0x35DF, 0x4167, { 0xAE, 0x94, 0xDA, 0xA3, 0xA5, 0xCF, 0x2D, 0xE4 } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
