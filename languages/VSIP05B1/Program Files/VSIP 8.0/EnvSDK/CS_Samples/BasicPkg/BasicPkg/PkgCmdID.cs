
/***************************************************************************
         Copyright (c) Microsoft CorporationAll rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind
    it is not recommended for use in a production environment.
***************************************************************************/

// PkgCmdID.cs
// MUST match PkgCmdID.h (for the satellite DLL)
using System;

namespace Microsoft.VisualStudio.VSIP.Samples.BasicPkg
{
	class PkgCmdIDList
	{
		private PkgCmdIDList() {}

		public const int icmdMyCommand =	0x100;
		public const int icmdMyOtherCommand =	0x101;
	};
}