//Copyright (C) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.

To prevent VisualStudio from refusing to load your provider as you
develop it and add capabilities, you must set the following registry keys.

The "WarnedOldMSSCCIProvider" key will decrement each time you restart
Visual Studio, so you may need to reset the value to 500 after you have
restarted Visual Studio 500 times.

    [HKEY_CURRENT_USER\Software\Microsoft\VisualStudio\7.1\SourceControl]
    "WarnedOldMSSCCIProvider"=dword:00000500
    "UseOldSCC"=dword:00000001
    "DontDisplayCheckDotNETCompatible"=dword:00000000

To load your MSSCCI provider in Visual Studio, you must set the following
registry key. Update the "SCCServerPath" to the path to your dll.

    [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\SourceSafe]
    "SCCServerName"="MSSCCI Sample"
    "SCCServerPath"="C:\\sample\\debug\\samplemsscci.dll"

NOTE: End-users of the MSSCCI provider you are creating may already
have an existing MSSCCI provider installed. The installation program for
the MSSCCI provider you create should check to see if there are already
values for these retistry keys. If these keys are already set, your installation
program should ask the end-user whether or not to register your provider
as the primary provider and take the place of the already installed one.
