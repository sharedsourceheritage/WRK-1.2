/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.cs
// MUST match guid.h (for the satellite DLL)
using System;

namespace Microsoft.VisualStudio.VSIP.Samples.ProvidesObjectPkg
{
    class GuidList
    {
        private GuidList() {}

        public static readonly Guid guidProvidesObjectPkg = new Guid("{3f12db33-7716-45e3-9987-31604118ea97}");
        public static readonly Guid guidProvidesObjectMenuGrp = new Guid("{f2f87990-b9f5-492b-aadd-cd7e45880cdb}");
        public static readonly Guid guidProvidesObjectCmdSet = new Guid("{92ddf991-d8b0-458f-abb6-9bccf8f819f5}");
    };
}