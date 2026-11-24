
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

// guidPersistanceSlot ID for our Hello World Tool Window
// {82BED311-57E3-11d1-87A5-00A0C91E2A46}
DEFINE_GUID(GUID_HelloWorldTool, 
0x82BED311, 0x57E3, 0x11d1, 0x87, 0xA5, 0x00, 0xA0, 0xC9, 0x1E, 0x2A, 0x46);

#define guidToolWnPkg   CLSID_ToolWnPackage

// Menu group added to the 'Views' menu for our commands
// {C3814682-4C40-11d2-976D-00A0C90A6BFE}
DEFINE_GUID(guidToolWnMenuGrp, 
    0xC3814682, 0x4C40, 0x11D2, 0x97, 0x6D, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE);

// Command set guid for our commands (used with IOleCommandTarget)
// {C3814683-4C40-11d2-976D-00A0C90A6BFE}
DEFINE_GUID(guidToolWnCmdSet, 
    0xC3814683, 0x4C40, 0x11D2, 0x97, 0x6D, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE);

#else  // _CTC_GUIDS


#define guidToolWnPkg      { 0xC3814681, 0x4C40, 0x11D2, { 0x97, 0x6D, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE } }
#define guidToolWnMenuGrp      { 0xC3814682, 0x4C40, 0x11D2, { 0x97, 0x6D, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE } }
#define guidToolWnCmdSet      { 0xC3814683, 0x4C40, 0x11D2, { 0x97, 0x6D, 0x00, 0xA0, 0xC9, 0x0A, 0x6B, 0xFE } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
