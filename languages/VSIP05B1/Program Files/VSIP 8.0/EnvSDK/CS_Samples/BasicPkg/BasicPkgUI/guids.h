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

#define guidBasicPkgPkg   CLSID_BasicPkgPackage

// Menu group added to the 'Tool' menu for our commands
// {22cc6a97-8c88-46b8-997c-f8dfb58034a5}
DEFINE_GUID(guidBasicPkgMenuGrp, 
0x22CC6A97, 0x8C88, 0x46B8, 0x99, 0x7C, 0xF8, 0xDF, 0xB5, 0x80, 0x34, 0xA5);

// Command set guid for our commands (used with IOleCommandTarget)
// {bc8da515-5743-4feb-a929-2938249cba26}
DEFINE_GUID(guidBasicPkgCmdSet, 
0xBC8DA515, 0x5743, 0x4FEB, 0xA9, 0x29, 0x29, 0x38, 0x24, 0x9C, 0xBA, 0x26);

#else  // _CTC_GUIDS


#define guidBasicPkgPkg      { 0xC2E44E89, 0xD13B, 0x47B1, { 0x87, 0xEE, 0xFD, 0xB7, 0x5F, 0x16, 0x7B, 0xCA } }
#define guidBasicPkgMenuGrp  { 0x22CC6A97, 0x8C88, 0x46B8, { 0x99, 0x7C, 0xF8, 0xDF, 0xB5, 0x80, 0x34, 0xA5 } }
#define guidBasicPkgCmdSet	  { 0xBC8DA515, 0x5743, 0x4FEB, { 0xA9, 0x29, 0x29, 0x38, 0x24, 0x9C, 0xBA, 0x26 } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
