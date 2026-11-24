
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// pkgicmd.h : Menu commands defined for this Environment package


// do not use #pragma once - used by ctc compiler
#ifndef __PKGICMD_H_
#define __PKGICMD_H_

#ifndef NOGUIDS

#ifdef DEFINE_GUID
	// Guid for the CmdUI (menus) used by the views created by our editor factory
	DEFINE_GUID ( guidFigEditCmdUI,
	0x672b24d0, 0x8d14, 0x11d1, 0xaf, 0x8d, 0x00, 0x60, 0x97, 0xdf, 0x56, 0x8c );
	DEFINE_GUID ( guidEditPkg,
	0xFA554DC1, 0x6DD4, 0x11d1, 0xAF, 0x71, 0x00, 0x60, 0x97, 0xDF, 0x56, 0x8C );

    // {3A629B85-AFF8-4af2-B982-57875A64D8C5}
    DEFINE_GUID(guidFigCodeCmdUI,
    0x3a629b85, 0xaff8, 0x4af2, 0xb9, 0x82, 0x57, 0x87, 0x5a, 0x64, 0xd8, 0xc5);

#else
	// Guid for the CmdUI (menus) used by the views created by our editor factory
	#define guidFigEditCmdUI \
	{ 0x672b24d0, 0x8d14, 0x11d1, { 0xaf, 0x8d, 0x00, 0x60, 0x97, 0xdf, 0x56, 0x8c } }
	// Guid for the package UI custom menu our editors use
	// same as CLSID_FigEditPackage declared in FigEdit_i.c (midl generated)
	// for our custom editor menus
	#define guidEditPkg \
	{ 0xFA554DC1, 0x6DD4, 0x11d1, { 0xAF, 0x71, 0x00, 0x60, 0x97, 0xDF, 0x56, 0x8C } }

    // {3A629B85-AFF8-4af2-B982-57875A64D8C5}
    #define guidFigCodeCmdUI \
    { 0x3a629b85, 0xaff8, 0x4af2, { 0xb9, 0x82, 0x57, 0x87, 0x5a, 0x64, 0xd8, 0xc5 } }

#endif

#endif //NOGUIDS

#define icmdAddArrow				0x0101
#define icmdAddCircle				0x0102
#define icmdAddRectangle			0x0103
#define icmdAddComment				0x0104

#define IDM_FIG_INSERT				0x0200
#define IDMX_FIG_FIGLINE			0x0220
#define IDMX_FIG_FIGLINE_INSERT		0x0221

#define IDG_FIG_INSERT_INSERTLINE	0x0100
#define IDG_FIG_INSERT_LINEGRP		0x0101


#endif	// __PKGICMD_H_
