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

#define guidBasicEditorPkg   CLSID_BasicEditorPackage

// Menu group added to the 'Tool' menu for our commands
// {a1e87b40-293e-4489-b69b-e178fb48fdd4}
DEFINE_GUID(guidBasicEditorMenuGrp, 
0xA1E87B40, 0x293E, 0x4489, 0xB6, 0x9B, 0xE1, 0x78, 0xFB, 0x48, 0xFD, 0xD4);

// Command set guid for our commands (used with IOleCommandTarget)
// {7a77ea8e-ea5a-4491-8288-68dde056b2dd}
DEFINE_GUID(guidBasicEditorCmdSet, 
0x7A77EA8E, 0xEA5A, 0x4491, 0x82, 0x88, 0x68, 0xDD, 0xE0, 0x56, 0xB2, 0xDD);

#else  // _CTC_GUIDS


#define guidBasicEditorPkg      { 0xA4635212, 0x1CF4, 0x4F5D, { 0x92, 0xED, 0x74, 0xDC, 0x17, 0xF6, 0xF5, 0xC8 } }
#define guidBasicEditorMenuGrp  { 0xA1E87B40, 0x293E, 0x4489, { 0xB6, 0x9B, 0xE1, 0x78, 0xFB, 0x48, 0xFD, 0xD4 } }
#define guidBasicEditorCmdSet	  { 0x7A77EA8E, 0xEA5A, 0x4491, { 0x82, 0x88, 0x68, 0xDD, 0xE0, 0x56, 0xB2, 0xDD } }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
