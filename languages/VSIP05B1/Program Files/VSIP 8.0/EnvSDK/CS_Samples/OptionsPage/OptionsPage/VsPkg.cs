/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cs : Implementation of ManagedOptionsPackage
//

using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using Microsoft.Win32;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.OLE.Interop;
using Microsoft.VisualStudio.VSIP;
using System.Reflection;
using System.Windows.Forms;
using System.ComponentModel;
using System.ComponentModel.Design;

using MSVSIP = Microsoft.VisualStudio.Shell;

namespace Microsoft.VisualStudio.VSIP.Samples.OptionsPage
{

	/////////////////////////////////////////////////////////////////////////////
	// ManagedOptionsPackage
	[MSVSIP.DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0")]

	[MSVSIP.ProvideOptionPageAttribute(typeof(OptionsPageGeneral),"My Options Page (C#)","General", 101, 106, true)]
	[MSVSIP.ProvideProfileAttribute(typeof(OptionsPageGeneral), "My Options Page (C#)","My Options Page (C#) - General Options", 101, 106, true)]

	[MSVSIP.ProvideOptionPageAttribute(typeof(OptionsPageCustom), "My Options Page (C#)", "Custom", 101, 107, true)]

	[Guid("B0002DC2-56EE-4931-93F7-70D6E9863940")]
	public class OptionsPagePackage : MSVSIP.Package
	{
		public OptionsPagePackage()
		{
		}

		protected override void Initialize()
		{
			Trace.WriteLine (string.Format("Entering Initialize() of: {0}", this.ToString()));
			base.Initialize();
		}
	}
}