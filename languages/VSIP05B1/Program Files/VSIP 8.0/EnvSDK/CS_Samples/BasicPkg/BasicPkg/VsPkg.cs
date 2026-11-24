/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cs : Implementation of BasicPkg
//

using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.ComponentModel.Design;
using Microsoft.Win32;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.OLE.Interop;
using Microsoft.VisualStudio;

using MSVSIP = Microsoft.VisualStudio.Shell;

namespace Microsoft.VisualStudio.VSIP.Samples.BasicPkg
{
    /////////////////////////////////////////////////////////////////////////////
    // BasicPkg
    [MSVSIP.DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0Exp")]
    [MSVSIP.InstalledProductRegistration(ProductNameResId=100, ProductDetailsResId=102, IconResId=400, ProductId="8.0")]
	[MSVSIP.RegisterLoadKey("Standard", "8.0", "Basic Managed Package", "Microsoft", 1)]
    [MSVSIP.ProvideMenuResource(1000, 1)]
    [Guid("c2e44e89-d13b-47b1-87ee-fdb75f167bca")]
    public class BasicPkg : MSVSIP.Package
    {
		private MenuCommand myOtherCommand = null;

        public BasicPkg()
        {
            Trace.WriteLine(string.Format("Entering constructor for: {0}", this.ToString()));
        }

        /////////////////////////////////////////////////////////////////////////////
        // CBscPkgPackage Package Implementation
        #region Package Members

        protected override void Initialize()
        {
            Trace.WriteLine (string.Format("Entering Initialize() of: {0}", this.ToString()));
            base.Initialize();

			// Add our command handlers for menu (commands must exist in the .ctc file)
			MSVSIP.OleMenuCommandService mcs = GetService(typeof(IMenuCommandService)) as MSVSIP.OleMenuCommandService;
			if (mcs != null)
			{
				CommandID cmd = new CommandID(GuidList.guidBasicPkgCmdSet, PkgCmdIDList.icmdMyCommand);
				MenuCommand menuCmd = new MenuCommand(new EventHandler(OnMyCommand), cmd);
				menuCmd.Supported = true;
				menuCmd.Visible = true;
				menuCmd.Enabled = true;
				mcs.AddCommand(menuCmd);
				
				cmd = new CommandID(GuidList.guidBasicPkgCmdSet, PkgCmdIDList.icmdMyOtherCommand);
				myOtherCommand = new MenuCommand(new EventHandler(OnMyOtherCommand), cmd);
				myOtherCommand.Supported = true;
				myOtherCommand.Visible = false;
				myOtherCommand.Enabled = true;
				mcs.AddCommand(myOtherCommand);
			}
        }

        protected override void Dispose(bool disposing)
        {
            Trace.WriteLine (string.Format("Entering Dispose() of: {0}", this.ToString()));

            base.Dispose(disposing);
        }

        protected override object GetAutomationObject(
            /*[in] */ string propName)
        {
            Trace.WriteLine (string.Format("Entering GetAutomationObject() of: {0}", this.ToString()));

            throw new NotImplementedException();
        }

        #endregion


        private void OnMyCommand(object sender, EventArgs e)
        {
            if (myOtherCommand != null)
            {
                // Toggle the visibility of the other command
                myOtherCommand.Visible = !myOtherCommand.Visible;
            }
        }

        private void OnMyOtherCommand(object sender, EventArgs e)
        {
            // Show a Message Box to prove we were here
            IVsUIShell uiShell = (IVsUIShell)GetService(typeof(SVsUIShell));
            Guid clsid = Guid.Empty;
            int result = 0; // UNDONE: this should really be S_OK
            int hr = uiShell.ShowMessageBox(0,
                                ref clsid,
                                "My Other Command",
                                string.Format("Inside {0}.Exec()",
                                this.ToString()),
                                string.Empty,
                                0,
                                OLEMSGBUTTON.OLEMSGBUTTON_OK,
                                OLEMSGDEFBUTTON.OLEMSGDEFBUTTON_FIRST,
                                OLEMSGICON.OLEMSGICON_INFO,
                                0,		// false = application modal; true would make it system modal
                                out result);
            NativeMethods.ThrowOnFailure(hr);
        }
    }
}