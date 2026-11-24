
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
// Menu IDs (0x1xxx)
#define IDM_MW_CASCADE              0x1000
#define IDM_TLB_MWTOOL              0x1101

///////////////////////////////////////////////////////////////////////////////
// Menu Group IDs (0x2xxx)
#define IDG_MW_LIST                 0x2000
#define IDG_MAINTOOL_VIEW           0x2100

///////////////////////////////////////////////////////////////////////////////
// Command IDs  (0x3xxx)
#define icmdMWToolWindow            0x3000
#define icmdNewWindow               0x3001

#define icmdListFirst               0x3200
#define icmdListLast                0x3999

///////////////////////////////////////////////////////////////////////////////
// Bitmap IDs

#define bmpidMWTool                 1
#define bmpidNewWindow              2

#endif // __PKGCMDID_H_
