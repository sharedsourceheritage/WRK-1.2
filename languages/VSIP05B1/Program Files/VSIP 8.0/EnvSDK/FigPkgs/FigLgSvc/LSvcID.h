
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// LSvcID.h: definitions of GUIDs/IIDs/CLSIDs used in this pkg

#pragma once

// SID for Language Service {8E7704E2-6523-11d1-AF67-006097DF568C}
DEFINE_GUID( SID_SFigLgSvc, 
0x8e7704e2, 0x6523, 0x11d1, 0xaf, 0x67, 0x0, 0x60, 0x97, 0xdf, 0x56, 0x8c);

//DEFINE_GUID( CLSID_StandardCommandSet97,
//0x5efc7975, 0x14bc, 0x11cf, 0x9b, 0x2b, 0x00, 0xaa, 0x00, 0x57, 0x38, 0x19 );

// Used with Set/GetData on the VsTextBuffer
DEFINE_GUID( GUID_BufferTaskProvider, 
0xb346df90, 0xca42, 0x11d1, 0xaf, 0xbf, 0x0, 0x60, 0x97, 0xdf, 0x56, 0x8c );

// from fpstfmt.h/.idl
// Interface ID for IPersistFileFormat  {3AFAE242-B530-11d0-8199-00A0C91BBEE3}
DEFINE_GUID( IID_IPersistFileFormat, 
0x3afae242, 0xb530, 0x11d0, 0x81, 0x99, 0x0, 0xa0, 0xc9, 0x1b, 0xbe, 0xe3 );
