
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// Guids.h
//
// Defines GUIDs used within the package. Also defines GUIDs used within the
// commandbar definition file.
//
//*****************************************************************************

// do not use #pragma once - used by ctc compiler
#ifndef __GUIDS_H_
#define __GUIDS_H_

#ifndef _CTC_GUIDS_

#include "oleipc.h"

#define guidFileEx          CLSID_FileExPackage

// {ED7B8AC2-05C1-11d3-9AA9-00C04F79EFC3}
DEFINE_GUID(guidEUGrp, 
    0xed7b8ac2, 0x05c1, 0x11d3, 0x9a, 0xa9, 0x00, 0xc0, 0x4f, 0x79, 0xef, 0xc3);

// {ED7B8AC3-05C1-11d3-9AA9-00C04F79EFC3}
DEFINE_GUID(guidEUCmd, 
    0xed7b8ac3, 0x05c1, 0x11d3, 0x9a, 0xa9, 0x00, 0xc0, 0x4f, 0x79, 0xef, 0xc3);

// {ED7B8AC4-05C1-11d3-9AA9-00C04F79EFC3}
DEFINE_GUID(guidFileSysTool, 
    0xed7b8ac4, 0x05c1, 0x11d3, 0x9a, 0xa9, 0x00, 0xc0, 0x4f, 0x79, 0xef, 0xc3);

// {DCE4FF08-2C67-11d3-9AAF-00C04F79EFC3}
DEFINE_GUID(guidFileSysOutputWindow, 
    0xdce4ff08, 0x2c67, 0x11d3, 0x9a, 0xaf, 0x00, 0xc0, 0x4f, 0x79, 0xef, 0xc3);

// {64AC2454-BD18-11D1-87B5-00A0C91E2A46}
DEFINE_GUID(GUID_ExDataEE,
    0x64ac2454, 0xbd18, 0x11d1, 0x87, 0xb5, 0x00, 0xa0, 0xc9, 0x1e, 0x2a, 0x46);

#else  // _CTC_GUIDS

#define guidFileEx         { 0xed7b8ac1, 0x05c1, 0x11d3, { 0x9a, 0xa9, 0x00, 0xc0, 0x4f, 0x79, 0xef, 0xc3 } }
#define guidEUGrp          { 0xed7b8ac2, 0x05c1, 0x11d3, { 0x9a, 0xa9, 0x00, 0xc0, 0x4f, 0x79, 0xef, 0xc3 } }
#define guidEUCmd          { 0xed7b8ac3, 0x05c1, 0x11d3, { 0x9a, 0xa9, 0x00, 0xc0, 0x4f, 0x79, 0xef, 0xc3 } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
