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

// #define guidProvidesObjectPkg   CLSID_ProvidesObjectPackage

// Menu group added to the 'Tool' menu for our commands
// {F2F87990-B9F5-492b-AADD-CD7E45880CDB}
DEFINE_GUID(guidProvidesObjectMenuGrp, 
0xf2f87990, 0xb9f5, 0x492b, 0xaa, 0xdd, 0xcd, 0x7e, 0x45, 0x88, 0xc, 0xdb);

// Command set guid for our commands (used with IOleCommandTarget)
// {92DDF991-D8B0-458f-ABB6-9BCCF8F819F5}
DEFINE_GUID(guidProvidesObjectCmdSet, 
0x92ddf991, 0xd8b0, 0x458f, 0xab, 0xb6, 0x9b, 0xcc, 0xf8, 0xf8, 0x19, 0xf5);

#else  // _CTC_GUIDS


#define guidProvidesObjectPkg	{ 0x3f12db33, 0x7716, 0x45e3, { 0x99, 0x87, 0x31, 0x60, 0x41, 0x18, 0xea, 0x97 } }
#define guidProvidesObjectMenuGrp  { 0xf2f87990, 0xb9f5, 0x492b, { 0xaa, 0xdd, 0xcd, 0x7e, 0x45, 0x88, 0xc, 0xdb } }
#define guidProvidesObjectCmdSet	  { 0x92ddf991, 0xd8b0, 0x458f, { 0xab, 0xb6, 0x9b, 0xcc, 0xf8, 0xf8, 0x19, 0xf5 } }


#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
