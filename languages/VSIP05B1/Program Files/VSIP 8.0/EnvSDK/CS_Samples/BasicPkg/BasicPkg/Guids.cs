/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// Guids.cs
// MUST match guid.h (for the satellite DLL)
using System;

namespace Microsoft.VisualStudio.VSIP.Samples.BasicPkg
{
    class GuidList
    {
        private GuidList(){}

        public static readonly Guid guidBasicPkgPkg =			new Guid("{c2e44e89-d13b-47b1-87ee-fdb75f167bca}");
        public static readonly Guid guidBasicPkgMenuGroup =		new Guid("{22cc6a97-8c88-46b8-997c-f8dfb58034a5}");
        public static readonly Guid guidBasicPkgCmdSet =        new Guid("{bc8da515-5743-4feb-a929-2938249cba26}");
    };
}