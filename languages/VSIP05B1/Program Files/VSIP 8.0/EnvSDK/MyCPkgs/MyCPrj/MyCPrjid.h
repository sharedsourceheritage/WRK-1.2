
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Projid.h: definitions of GUIDs/IIDs/CLSIDs used in sample.pkg

#pragma once

#define CLSID_MyPackage CLSID_MyCPrjPackage

// GUID for MyCPrj Project Type
// {8bdfd93a-c064-46af-bcb8-11460c53c7e4}
DEFINE_GUID(GUID_MyProjectType, 
0x8bdfd93a, 0xc064, 0x46af, 0xbc, 0xb8, 0x11, 0x46, 0x0c, 0x53, 0xc7, 0xe4);

// GUID_NODETYPE_FileVw_Project --
// returned as VSHPROPID_TypeGuid for project node
// {482a4143-bf31-41e8-a5cb-133d53bd93a3}
DEFINE_GUID(GUID_NODETYPE_FileVw_Project, 
0x482a4143, 0xbf31, 0x41e8, 0xa5, 0xcb, 0x13, 0x3d, 0x53, 0xbd, 0x93, 0xa3);

// GUID_NODETYPE_FileVw_File -- 
// to be used in image list for file nodes in project explorer
// {96823eea-54c9-410e-b9b8-c2b05e14f664}
DEFINE_GUID(GUID_NODETYPE_FileVw_File, 
0x96823eea, 0x54c9, 0x410e, 0xb9, 0xb8, 0xc2, 0xb0, 0x5e, 0x14, 0xf6, 0x64);

// GUID_NODETYPE_FileVw_Folder -- 
// to be used in image list for folder nodes in project window (FileView)
// {239d4fba-11ed-4e5f-b5ed-444feafaf8ca}
DEFINE_GUID(GUID_NODETYPE_FileVw_Folder, 
0x239d4fba, 0x11ed, 0x4e5f, 0xb5, 0xed, 0x44, 0x4f, 0xea, 0xfa, 0xf8, 0xca);
