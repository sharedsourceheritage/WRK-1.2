
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// PkgCmdID.h
//
// IDs for commandbar items
//
//*****************************************************************************

// do not use #pragma once - used by ctc compiler
#ifndef __PKGCMDID_H_
#define __PKGCMDID_H_

///////////////////////////////////////////////////////////////////////////////
// Menu IDs          (0x010x)

#define IDM_TLB_FILESYSFOLDER     0x0101
#define IDM_TLB_FILESYSFILE       0x0102
#define IDM_CTX_FILESYSFOLDER     0x0103
#define IDM_CTX_FILESYSFILE       0x0104
#define IDM_MNU_FILESYSFILE_SORT  0x0105
#define IDM_MNU_FILESYS_COMMANDS  0x0106
#define IDM_CTX_CMDMACRO          0x0107


///////////////////////////////////////////////////////////////////////////////
// Menu Group IDs    (0x011x)

#define IDG_FILEPANE_COMMANDS     0x1000
#define IDG_FILEPANE_REFRESH      0x1001
#define IDG_FILEPANE_PROPS        0x1002
#define IDG_FILEPANE_FILTER       0x1003
#define IDG_FILEPANECTX_COMMANDS  0x1004
#define IDG_FILEPANECTX_ARRANGE   0x1005
#define IDG_FILEPANE_SORT         0x1006

#define IDG_FOLDERPANE_VIEW       0x1100
#define IDG_FOLDERPANE_COMMANDS   0x1101
#define IDG_FOLDERPANE_REFRESH    0x1102
#define IDG_FOLDERPANE_PROPS      0x1103
#define IDG_FOLDERCTX_SHORTCUT    0x1104
#define IDG_FOLDERCTX_REFRESH     0x1105
#define IDG_FOLDERCTX_FIND        0x1106
#define IDG_FOLDERCTX_WINDOS      0x1107
#define IDG_FOLDERCTX_PROPS       0x1108

#define IDG_FILESYSCTX_COMMANDS   0x1200
#define IDG_COMMANDS_LIST         0x1201
#define IDG_COMMANDS_DEFINE       0x1202

#define IDG_CMDCTX_FOLDER         0x1300
#define IDG_CMDCTX_FILE           0x1301

#define IDG_CMDTLB_COMMAND        0x1401


///////////////////////////////////////////////////////////////////////////////
// Command IDs       (0x2xxx)

#define cmdidFileSysTool          0x2100

#define cmdidFilesOpenFile        0x2200
#define cmdidFilesOpenFileWith    0x2201
#define cmdidFilesPreviewFile     0x2202
#define cmdidFilesSortName        0x2203
#define cmdidFilesSortExtension   0x2204
#define cmdidFilesSortReadOnly    0x2205
#define cmdidFilesRefresh         0x2210
#define cmdidFilesFilter          0x2220
#define cmdidFilesFilterHandler   0x2221

#define cmdidFolderView           0x2300
#define cmdidShortcutView         0x2301
#define cmdidFoldersRefresh       0x2310
#define cmdidFoldersRefreshThis   0x2311
#define cmdidAddShortcut          0x2320
#define cmdidDeleteShortcut       0x2321
#define cmdidBrowseShortcut       0x2322
#define cmdidFindHere             0x2330
#define cmdidExplorer             0x2340
#define cmdidMSDOS                0x2341

#define cmdidDefineCommands       0x2400
#define cmdidNoCommands           0x2401
#define cmdidCommandList0         0x2410
#define cmdidCommandList15        0x241F

#define cmdidMacroSelFolder       0x2500
#define cmdidMacroFileDir         0x2501
#define cmdidMacroFileName        0x2502
#define cmdidMacroFilePath        0x2503
#define cmdidMacroFileExt         0x2504


///////////////////////////////////////////////////////////////////////////////
// Bitmap IDs

#define bmpidFileSysTool          1
#define bmpidFolderView           2
#define bmpidShortcutView         3
#define bmpidRefresh              4
#define bmpidOpenFile             5
#define bmpidPreviewFile          6
#define bmpidAddShortcut          7
#define bmpidDeleteShortcut       8
#define bmpidExplorer             9
#define bmpidMSDOS                10
#define bmpidCommand              11

#endif // __PKGCMDID_H_
