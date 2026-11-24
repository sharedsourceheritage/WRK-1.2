
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// guids.h: definitions of GUIDs/IIDs/CLSIDs

#pragma once

#define CLSID_MyPackage CLSID_FigPrjPackage

// GUID for FigPrj Project Type
// {C061DB26-5833-11d2-96F5-000000000000}
DEFINE_GUID(GUID_MyProjectType, 
0xc061db26, 0x5833, 0x11d2, 0x96, 0xf5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0);

// GUID_NODETYPE_FileVw_Project -- 
// returned as VSHPROPID_TypeGuid for project node
// {C061DB28-5833-11d2-96F5-000000000000}
DEFINE_GUID(GUID_NODETYPE_FileVw_Project, 
0xc061db28, 0x5833, 0x11d2, 0x96, 0xf5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0);


// GUID_NODETYPE_FileVw_File -- 
// to be used in image list for file nodes in project explorer
// {C061DB29-5833-11d2-96F5-000000000000}
DEFINE_GUID(GUID_NODETYPE_FileVw_File, 
0xc061db29, 0x5833, 0x11d2, 0x96, 0xf5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0);


// GUID_NODETYPE_FileVw_Folder -- 
// to be used in image list for folder nodes in project window (FileView)
// {C061DB2A-5833-11d2-96F5-000000000000}
DEFINE_GUID(GUID_NODETYPE_FileVw_Folder, 
0xc061db2a, 0x5833, 0x11d2, 0x96, 0xf5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0);

// GUID of FigEdit editor factory
// {FA554DC2-6DD4-11d1-AF71-006097DF568C}
DEFINE_GUID( GUID_FigEditorFactory, 
0xFA554DC2, 0x6DD4, 0x11d1, 0xAF, 0x71, 0x00, 0x60, 0x97, 0xDF, 0x56, 0x8C );


// {01839CA2-DF95-479b-86F2-71C6004C97F1}
DEFINE_GUID(GUID_NODETYPE_FigFile, 
0x1839ca2, 0xdf95, 0x479b, 0x86, 0xf2, 0x71, 0xc6, 0x0, 0x4c, 0x97, 0xf1);


// GUID for Enterprise Framework Project Type
// {FE3BBBB6-72D5-11d2-9ACE-00C04F79A2A4}
DEFINE_GUID(GUID_EFProjectType, 
0xfe3bbbb6, 0x72d5, 0x11d2, 0x9a, 0xce, 0x0, 0xc0, 0x4f, 0x79, 0xa2, 0xa4);
