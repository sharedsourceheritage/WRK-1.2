
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

// {1D239270-AFE6-4dbd-AE0E-14CC5C5C37DA}
DEFINE_GUID(GUID_DSRefToolWindow, 
0x1d239270, 0xafe6, 0x4dbd, 0xae, 0xe, 0x14, 0xcc, 0x5c, 0x5c, 0x37, 0xda);

#define guidDSRefToolPkg   CLSID_DSRefToolPackage

// {53E207A2-5ED6-11d2-BF4A-0080C71D86A1}
DEFINE_GUID(guidDSRefToolMenuGrp, 
    0x53E207A2, 0x5ED6, 0x11D2, 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1);

// {53E207A3-5ED6-11d2-BF4A-0080C71D86A1}
DEFINE_GUID(guidDSRefToolCmdSet, 
    0x53E207A3, 0x5ED6, 0x11D2, 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1);

#else  // _CTC_GUIDS

#define guidDSRefToolPkg      { 0x53E207A1, 0x5ED6, 0x11D2, { 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1 } }
#define guidDSRefToolMenuGrp      { 0x53E207A2, 0x5ED6, 0x11D2, { 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1 } }
#define guidDSRefToolCmdSet      { 0x53E207A3, 0x5ED6, 0x11D2, { 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1 } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
