
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// BscEdtID.h: definitions of GUIDs/IIDs/CLSIDs used in this pkg

#pragma once

// for our custom editor factory, used in res\vspkg.rgs and when registering
DEFINE_GUID(GUID_BscEditorFactory, %FactoryGuid1%);

DEFINE_GUID(GUID_BscEditorCmdset, %CmdSetGuid1%);

DEFINE_GUID(CLSID_MiscFilesProject, 0xA2FE74E1, 0xB743, 0x11d0, 0xAE, 0x1A, 0x00, 0xA0, 0xC9, 0x0F, 0xFF, 0xC3);