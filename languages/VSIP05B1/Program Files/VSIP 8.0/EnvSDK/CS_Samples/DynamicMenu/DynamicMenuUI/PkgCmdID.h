
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PkgCmdID.h
// Command IDs used in defining command bars
//

// do not use #pragma once - used by ctc compiler
#ifndef __PKGCMDID_H_
#define __PKGCMDID_H_

///////////////////////////////////////////////////////////////////////////////
// Menu IDs
#define IDM_DYN_CASCADE             0x1000

///////////////////////////////////////////////////////////////////////////////
// Menu Group IDs
#define MyMenuGroup 				0x1020
#define MyCascadeGroup              0x1021
#define MyCascadeDynGroup           0x1022

///////////////////////////////////////////////////////////////////////////////
// Command IDs
#define cmdidMyCommand      0x100
#define cmdidAddMenu        0x101
#define cmdidRemoveMenu     0x102
#define cmdidDynamicFirst   0x103

///////////////////////////////////////////////////////////////////////////////
// Bitmap IDs
#define bmpPic1 1
#define bmpPic2 2
#define bmpPicSmile 3
#define bmpPicX 4
#define bmpPicArrows 5


#endif // __PKGCMDID_H_
