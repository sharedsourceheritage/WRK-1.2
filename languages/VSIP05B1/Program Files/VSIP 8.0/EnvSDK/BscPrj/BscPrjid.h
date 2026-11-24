
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Projid.h: definitions of GUIDs/IIDs/CLSIDs used in sample.pkg

#pragma once

#define CLSID_MyPackage CLSID_BscPrjPackage

// GUID for BscPrj Project Type
// {06D95370-B7D2-11d1-87B4-00A0C91E2A46}
DEFINE_GUID(GUID_MyProjectType, 
0x06d95370, 0xb7d2, 0x11d1, 0x87, 0xb4, 0x0, 0xa0, 0xc9, 0x1e, 0x2a, 0x46);

// GUID_NODETYPE_FileVw_Project -- 
// returned as VSHPROPID_TypeGuid for project node
// {8F6B12F0-BAB0-11d1-87B5-00A0C91E2A46}
DEFINE_GUID(GUID_NODETYPE_FileVw_Project, 
0x8f6b12f0, 0xbab0, 0x11d1, 0x87, 0xb5, 0x0, 0xa0, 0xc9, 0x1e, 0x2a, 0x46);

// GUID_NODETYPE_FileVw_File -- 
// to be used in image list for file nodes in project explorer
// {8F6B12F1-BAB0-11d1-87B5-00A0C91E2A46}
DEFINE_GUID(GUID_NODETYPE_FileVw_File, 
0x8f6b12f1, 0xbab0, 0x11d1, 0x87, 0xb5, 0x0, 0xa0, 0xc9, 0x1e, 0x2a, 0x46);

// GUID_NODETYPE_FileVw_Folder -- 
// to be used in image list for folder nodes in project window (FileView)
// {8F6B12F2-BAB0-11d1-87B5-00A0C91E2A46}
DEFINE_GUID(GUID_NODETYPE_FileVw_Folder, 
0x8f6b12f2, 0xbab0, 0x11d1, 0x87, 0xb5, 0x0, 0xa0, 0xc9, 0x1e, 0x2a, 0x46);
