//--------------------------------------------------------------------------
// Microsoft Visual Basic
//
// Copyright (c) 1998 Microsoft Corporation Inc.
// All rights reserved
//
//
// dirprjid.h
// DirectoryProject command table ids
//---------------------------------------------------------------------------
#ifndef __DIRPIDS_H__
#define __DIRPIDS_H__

//----------------------------------------------------------------------------
//
// GUID Identifiers
//
// Define CommandSet GUIDs in two ways - C compiler and CTC compiler.
// ** MAKE UPDATES TO BOTH GUID DECLS BELOW **
//----------------------------------------------------------------------------
#ifdef DEFINE_GUID

// {5BE15F80-5A3C-11d2-BF19-00C04F79EFBC}
DEFINE_GUID(guidDirPkgGrpId, 
    0x5be15f80, 0x5a3c, 0x11d2, 0xbf, 0x19, 0x0, 0xc0, 0x4f, 0x79, 0xef, 0xbc);

// {5BE15F81-5A3C-11d2-BF19-00C04F79EFBC}
DEFINE_GUID(guidDirPkgCmdId,
    0x5be15f81, 0x5a3c, 0x11d2, 0xbf, 0x19, 0x0, 0xc0, 0x4f, 0x79, 0xef, 0xbc);

// {5BE15F82-5A3C-11d2-BF19-00C04F79EFBC}
DEFINE_GUID(guidDirPkgBitmap, 
    0x5be15f82, 0x5a3c, 0x11d2, 0xbf, 0x19, 0x0, 0xc0, 0x4f, 0x79, 0xef, 0xbc);

#else

// {DE353D20-56EB-11d2-BF19-00C04F79EFBC}
#define CLSID_DirPrjPackage {0xde353d20, 0x56eb, 0x11d2, {0xbf, 0x19, 0x0, 0xc0, 0x4f, 0x79, 0xef, 0xbc}}

// {5BE15F80-5A3C-11d2-BF19-00C04F79EFBC}
#define guidDirPkgGrpId {0x5be15f80, 0x5a3c, 0x11d2, { 0xbf, 0x19, 0x0, 0xc0, 0x4f, 0x79, 0xef, 0xbc }}
        
// {5BE15F81-5A3C-11d2-BF19-00C04F79EFBC}
#define guidDirPkgCmdId {0x5be15f81, 0x5a3c, 0x11d2, { 0xbf, 0x19, 0x0, 0xc0, 0x4f, 0x79, 0xef, 0xbc }}

// {5BE15F82-5A3C-11d2-BF19-00C04F79EFBC}
#define guidDirPkgBitmap {0x5be15f82, 0x5a3c, 0x11d2, { 0xbf, 0x19, 0x0, 0xc0, 0x4f, 0x79, 0xef, 0xbc }}

#endif

//---------------------------------------------------------------------------
// Comand Table Version
//---------------------------------------------------------------------------
#define COMMANDTABLE_VERSION		1

// dummy menu and group
#define IDM_DIRPKG_DUMMY            1
#define IDM_DIRPKG_OFFLINE          2
#define IDM_DIRPKG_WEBFILES         3
#define IDM_DIRPKG_WEBPROJ          4
#define IDM_DIRPKG_ADDWEBITEM       5

// web package menus
#define IDM_WEBPKG_CSCD_ADDWEB      6
#define IDM_WEBPKG_MNUCTRL_ADDWEB   7
#define IDM_WEBPKG_WEB              8

// groups
#define IDG_DIRPKG_DUMMY             22

// Project menu
#define IDG_DIRPKG_PROJECT           23
#define IDG_DIRPKG_PROJECT_ADDREMOVE 24

// "Add Web" Menu Groups
#define IDG_WEBPKG_ADDWEB_CASCADE          25
#define IDG_WEBPKG_MNUCTRL_ADDWEB          26
#define IDG_WEBPKG_MNUCTRL_ADDWEB_BOTTOM   27

// "Offline" Gruops
#define IDG_DIRPKG_OFFLINE0     29
#define IDG_DIRPKG_OFFLINE1     30

// "Add Web Item" submenu groups.
#define IDG_DIRPKG_ADDWEBITEM0  31

// "Web Files" groups
#define IDG_DIRPKG_WEBFILES0    32
#define IDG_DIRPKG_WEBFILES1    33
#define IDG_DIRPKG_WEBFILES2    34

// Shell "view" menu groups
#define IDG_DIRPKG_VIEW_LINKS   35

// Toolbar groups
#define IDG_DIRPKG_TB1          36
#define IDG_DIRPKG_TB2          37

// "Web" Menu Groups
#define IDG_WEBPKG_WEB_MISCADD   40
#define IDG_WEBPKG_WEB_ADD       41
#define IDG_WEBPKG_WEB_REFERENCE 42
#define IDG_WEBPKG_WEB_OPTIONS   43

// Context menu groups.
#define IDG_VS_CTXT_WEBADDITEMS         50
#define IDG_VS_CTXT_WEBFOLDER_BROWSE    51
#define IDG_VS_CTXT_WEBITEM_BROWSE      52
#define IDG_VS_CTXT_WEBITEM_OPEN        53
#define IDG_VS_CTXT_WEBFOLDER_TRANSFER  54
#define IDG_VS_CTXT_WEBITEM_TRANSFER    55


//Command IDs
#define icmdDirPkgPermissions			0x0001
#define icmdDirPkgRemoveSCC   			0x0002
#define icmdDirPkgRefresh				0x0003
#define icmdDirPkgRecalculateLinks		0x0004
#define icmdDirPkgDirectMode			0x0006
#define icmdDirPkgSynchronize			0x0007
#define icmdDirPkgOffline				0x0008
#define icmdDirPkgCopyWeb				0x0009
#define icmdDirPkgCompareMaster         0x0011
#define icmdDirPkgShowAllFiles          0x0013
#define icmdDirPkgAddToProject          0x0014
#define icmdDirPkgOfflineSettings       0x0016
#define icmdDirPkgSyncOfflineFolders    0x0017
#define icmdDirPkgSyncAllOfflineFolders 0x0018
#define icmdDirPkgAddFileFromWeb        0x001A
#define icmdDirPkgStop                  0x001B
#define icmdDirPkgSetAsStartPage		0x001C
#define icmdDirPkgBrokenLinkReport		0x001D
#define icmdDirPkgAddReference          0x001E
#define icmdDirPkgAddDataCommand        0x001F
#define icmdDirPkgAddDataEnv            0x0020
#define icmdDirPkgExistingItem          0x0021
#define icmdDirPkgNewItem               0x0022
#define icmdDirPkgRemoveFromProject     0x0023
#define icmdDirPkgAddWebReference       0x0024
#define icmdDirPkgAddProjectOutputs     0x0028
#define icmdDirPkgAddWebReferenceCtx    0x0029
#define icmdDirPkgUpdateWebReference    0x002A
#define icmdNewWeb                      0x002B
#define icmdOpenExistingWeb             0x002C
#define icmdAddNewWeb                   0x002D
#define icmdAddExistingWeb              0x002E
#define icmdOpenWebSolution             0x002F
#define icmdSetBrowseLocation           0x0030
#define icmdRefreshWebFolder            0x0031
#define icmdCreateShortcut              0x0032

// Toolbar offsets
#define bmpDirPkgCopyWeb              1
#define bmpDirPkgSynchronize          2
#define bmpDirPkgIsolatedMode         3
#define bmpDirPkgDirectMode           4
#define bmpDirPkgDiscardChanges       5
#define bmpDirPkgGetWorkingCopy       6
#define bmpDirPkgReleaseWorkingCopy   7
#define bmpDirPkgGet                  8
#define bmpDirPkgShowAllFiles         9
#define bmpDirPkgStop                10
#define bmpDirPkgBrokenLinkReport    11
#define bmpDirPkgAddDataCommand      12
#define bmpDirPkgRemoveWebFromScc    13

#endif
// End of dirpids.h
