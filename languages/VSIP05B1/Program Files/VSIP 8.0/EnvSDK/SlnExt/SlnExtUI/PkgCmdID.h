
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

#define IDM_SLNNOTES		0x1010
#define IDMX_SLNNOTE_CTX	0x2020
///////////////////////////////////////////////////////////////////////////////
// Menu Group IDs

#define IDG_SLNNOTE_CTXT_SOLUTION 0x99
#define IDG_SLNNOTES		0x100
#define IDG_SLNNOTE_CTX		0x200
///////////////////////////////////////////////////////////////////////////////
// Command IDs

#define icmdAddNote		0x1000
#define icmdViewNotes	0x2000
#define icmdDeleteNote	0x3000
#define icmdRenameNote	0x4000
///////////////////////////////////////////////////////////////////////////////
// Bitmap IDs

#define bmpidNote		0x1
#define bmpidIssue		0x2

#endif // __PKGCMDID_H_
