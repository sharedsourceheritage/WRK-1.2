
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// BscEdtID.h: definitions of GUIDs/IIDs/CLSIDs used in this pkg

#pragma once

// for our custom editor factory, used in res\vspkg.rgs and when registering
// {12093B32-EF68-11d1-9429-00AA00A3EFFF}
DEFINE_GUID(GUID_BscEditorFactory, 0x12093B32, 0xEF68, 0x11d1, 0x94, 0x29, 0x00, 0xAA, 0x00, 0xA3, 0xEF, 0xFF);

DEFINE_GUID(GUID_BscEditorCmdset, 0x12093B33, 0xEF68, 0x11d1, 0x94, 0x29, 0x00, 0xAA, 0x00, 0xA3, 0xEF, 0xFF);

DEFINE_GUID(GUID_BscEditorMenuset, 0x12093B34, 0xEF68, 0x11d1, 0x94, 0x29, 0x00, 0xAA, 0x00, 0xA3, 0xEF, 0xFF);

