/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.h
//

// do not use #pragma once - used by ctc compiler
#ifndef __GUIDS_H_
#define __GUIDS_H_

#ifndef _CTC_GUIDS_

%ToolWindowItemStart%
// guidPersistanceSlot ID for our Tool Window
// {%ToolGuid%}
DEFINE_GUID(GUID_guidPersistanceSlot, 
%ToolGuid1%);
%ToolWindowItemEnd%
#define guid%ProjectClass%Pkg   CLSID_%ProjectClass%Package

// Command set guid for our commands (used with IOleCommandTarget)
// {%CmdSetGuid%}
DEFINE_GUID(guid%ProjectClass%CmdSet, 
%CmdSetGuid1%);

#else  // _CTC_GUIDS


#define guid%ProjectClass%Pkg      { %PackageGuid2% }
#define guid%ProjectClass%CmdSet	  { %CmdSetGuid2% }

#endif // _CTC_GUIDS_

#endif // __GUIDS_H_
