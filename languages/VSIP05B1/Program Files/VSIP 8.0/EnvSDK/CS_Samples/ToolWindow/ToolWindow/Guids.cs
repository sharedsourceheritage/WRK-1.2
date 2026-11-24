/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.cs
// MUST match guid.h (for the satellite DLL)
using System;

namespace Microsoft.VisualStudio.VSIP.Samples.ToolWindowCS
{
    class GuidList
    {
        private GuidList(){}

        public static readonly Guid guidToolWindowPkg =       new Guid("{7259e420-6241-4e0d-b535-5b820671d183}");
        public static readonly Guid guidToolWindowMenuGroup = new Guid("{1f991f62-e5a4-48e9-97d0-0ac5f69f0ffe}");
        public static readonly Guid guidToolWindowCmdSet =    new Guid("{d5ac54dc-170e-45fc-be1f-245dea6710ea}");

        public static Guid guidToolWindowPersistance =        new Guid("{7b00264f-bbda-42f2-8085-723ca3712763}");


    };
}