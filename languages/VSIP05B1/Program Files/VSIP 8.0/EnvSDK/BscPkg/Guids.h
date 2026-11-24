
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

#define guidBscPkgPkg   CLSID_BscPkgPackage

// {53E207A2-5ED6-11d2-BF4A-0080C71D86A1}
DEFINE_GUID(guidBscPkgMenuGrp, 
    0x53E207A2, 0x5ED6, 0x11D2, 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1);

// {53E207A3-5ED6-11d2-BF4A-0080C71D86A1}
DEFINE_GUID(guidBscPkgCmdSet, 
    0x53E207A3, 0x5ED6, 0x11D2, 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1);

#else  // _CTC_GUIDS

#define guidBscPkgPkg      { 0x53E207A1, 0x5ED6, 0x11D2, { 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1 } }
#define guidBscPkgMenuGrp      { 0x53E207A2, 0x5ED6, 0x11D2, { 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1 } }
#define guidBscPkgCmdSet      { 0x53E207A3, 0x5ED6, 0x11D2, { 0xBF, 0x4A, 0x00, 0x80, 0xC7, 0x1D, 0x86, 0xA1 } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
