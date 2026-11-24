
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// FigEdID.h: definitions of GUIDs/IIDs/CLSIDs used in this pkg

#pragma once

// for our custom editor factory, used in vspkg.rgs and when registering
// {FA554DC2-6DD4-11d1-AF71-006097DF568C}
DEFINE_GUID(GUID_EditorFactory, 
0xFA554DC2, 0x6DD4, 0x11d1, 0xAF, 0x71, 0x00, 0x60, 0x97, 0xDF, 0x56, 0x8C );

// {335E2339-1FD4-4d4f-8014-2558F3288A1B}
DEFINE_GUID(GUID_FigEditorFactoryEncoding, 
0x335e2339, 0x1fd4, 0x4d4f, 0x80, 0x14, 0x25, 0x58, 0xf3, 0x28, 0x8a, 0x1b);

// Toolbox Add to toolbox dialog FigEdit Property page
// {B15585A9-ACEB-4c52-A0D1-88EC4D57A1BF}
DEFINE_GUID(guidFigEditTbxPropPage, 
0xB15585A9, 0xACEB, 0x4c52, 0xA0, 0xD1, 0x88, 0xEC, 0x4D, 0x57, 0xA1, 0xBF);
 