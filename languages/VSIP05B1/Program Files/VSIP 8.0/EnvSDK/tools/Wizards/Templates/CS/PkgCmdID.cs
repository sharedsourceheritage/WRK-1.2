
/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// PkgCmdID.cs
// MUST match PkgCmdID.h (for the satellite DLL)
using System;

namespace Vsip.%ProjectClass%
{
    class PkgCmdIDList
    {
%MenuItemStart%        public const uint %CommandID% =        0x100;%MenuItemEnd%
%ToolWindowItemStart%        public const uint %ToolCommandID% =    0x101;%ToolWindowItemEnd%
    };
}