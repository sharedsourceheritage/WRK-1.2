/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cs : Implementation of ToolWindow
//

using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.ComponentModel.Design;
using Microsoft.Win32;
using System.Windows.Forms;
using Microsoft.VisualStudio.Shell;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.OLE.Interop;

using MSVSIP = Microsoft.VisualStudio.Shell;

namespace Microsoft.VisualStudio.VSIP.Samples.ToolWindowCS
{
    /////////////////////////////////////////////////////////////////////////////
    // ToolWindow
    [MSVSIP.DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0Exp")]
    [MSVSIP.RegisterLoadKey("Standard", "8.0", "Managed Tool Window (C#)", "Microsoft", 1)]
    [MSVSIP.ProvideMenuResource(1000, 1)]
    [MSVSIP.ProvideToolWindow(typeof(MyToolWindow))]
    [Guid("7259e420-6241-4e0d-b535-5b820671d183")]
    public class ToolWindow : MSVSIP.Package
    {
		private IVsWindowFrame windowFrame;

        public ToolWindow()
        {
            Trace.WriteLine(string.Format("Entering constructor for: {0}", this.ToString()));
            windowFrame = null;
        }

	private void ShowToolWindow(object sender, EventArgs e)
        {
            ToolWindowPane window = this.FindToolWindow(typeof(MyToolWindow), 0, true);
            if (window != null && window.Frame != null)
            {
                windowFrame = (IVsWindowFrame)window.Frame;
            }
            if (windowFrame != null)
            {
                NativeMethods.ThrowOnFailure( windowFrame.Show() );
            }
        }

        private void ToolBarCommand(object sender, EventArgs e)
        {
            MyToolWindow window = (MyToolWindow)this.FindToolWindow(typeof(MyToolWindow), 0, true);

            if (window != null)
            {
                window.ToolBarCommand();
            }
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
                // ToolWindow Command
                CommandID cmd = new CommandID(GuidList.guidToolWindowCmdSet, PkgCmdIDList.cmdidMyTool);
                MenuCommand menuCmd = new MenuCommand(new EventHandler(ShowToolWindow), cmd);

                menuCmd.Supported = true;
                menuCmd.Visible = true;
                menuCmd.Enabled = true;
                mcs.AddCommand(menuCmd);

                // ToolBar Command
                cmd = new CommandID(GuidList.guidToolWindowCmdSet, PkgCmdIDList.cmdidMyCommand);
                menuCmd = new MenuCommand(new EventHandler(ToolBarCommand), cmd);

                menuCmd.Supported = true;
                menuCmd.Visible = true;
                menuCmd.Enabled = true;
                mcs.AddCommand(menuCmd);
            }
        }

        protected override void Dispose(bool disposing)
        {
            Trace.WriteLine (string.Format("Entering Dispose() of: {0}", this.ToString()));

            base.Dispose(disposing);
        }

        #endregion
    }
}