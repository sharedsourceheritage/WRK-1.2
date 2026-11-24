
/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// PkgCmdID.cs
// MUST match PkgCmdID.h (for the satellite DLL)
using System;

namespace Microsoft.VisualStudio.VSIP.Samples.ToolWindowCS
{
    class PkgCmdIDList
    {
        private PkgCmdIDList() {}

        public const int cmdidMyTool =		0x100;
        public const int cmdidMyCommand =	0x101;
        public const int myMenu =			0x300;
        public const int myMenuGroup =		0x1020;
    };
}