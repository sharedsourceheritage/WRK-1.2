
/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// PkgCmdID.cs
// MUST match PkgCmdID.h (for the satellite DLL)
using System;

namespace Vsip.DynamicMenu
{
    class PkgCmdIDList
    {
        private PkgCmdIDList() {}

        public const int cmdidMyCommand =        0x100;
        public const int cmdidAddMenu =          0x101;
        public const int cmdidRemoveMenu =       0x102;
        public const int cmdidDynamicFirst =     0x103;
    };
}