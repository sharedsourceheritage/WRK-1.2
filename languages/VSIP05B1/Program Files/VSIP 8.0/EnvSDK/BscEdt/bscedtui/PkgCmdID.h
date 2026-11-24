
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// PkgCmdID.h : Menu commands defined for this Environment package


// do not use #pragma once - used by ctc compiler
#ifndef __PKGICMD_H_
#define __PKGICMD_H_

///////////////////////////////////////////////////////////////////////////////
// Menus

#define IDM_TLB_RTF					0x0001				// toolbar
#define IDMX_RTF					0x0002				// context menu
#define IDM_RTFMNU_ALIGN			0x0004
#define IDM_RTFMNU_SIZE				0x0005

///////////////////////////////////////////////////////////////////////////////
// Menu Groups

#define IDG_RTF_FMT_FONT1			0x1000
#define IDG_RTF_FMT_FONT2			0x1001
#define IDG_RTF_FMT_INDENT			0x1002
#define IDG_RTF_FMT_BULLET			0x1003

#define IDG_RTF_TLB_FONT1			0x1004
#define IDG_RTF_TLB_FONT2			0x1005
#define IDG_RTF_TLB_INDENT			0x1006
#define IDG_RTF_TLB_BULLET			0x1007
#define IDG_RTF_TLB_FONT_COMBOS		0x1008

#define IDG_RTF_CTX_EDIT			0x1009
#define IDG_RTF_CTX_PROPS			0x100a

#define IDG_RTF_EDITOR_CMDS			0x100b


///////////////////////////////////////////////////////////////////////////////
// Command IDs


#define icmdBold					0x0001
#define icmdItalic					0x0002
#define icmdUnderline				0x0003
#define icmdStrike					0x0004
#define icmdJustifyLeft				0x0005	
#define icmdJustifyCenter			0x0006
#define icmdJustifyRight			0x0007	
/// Align Commands
#define icmdLefts					0x0010
#define icmdCenters					0x0011
#define icmdRights					0x0012

#define icmdTop						0x0013
#define icmdMiddle					0x0014
#define icmdBottom					0x0015

#define icmdToGrid					0x0016

//Size Commands
#define icmdWidth					0x0017
#define icmdHeight					0x0018
#define icmdBoth					0x0019
	
// Font Commands
#define icmdFontName				0x001a
#define icmdFontNameHandler			0x001b
#define icmdFontSize				0x001c
#define icmdFontSizeHandler			0x001d

///////////////////////////////////////////////////////////////////////////////
// Button Bitmap IDs



#endif	// __PKGICMD_H_
			  
