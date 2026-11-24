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

namespace Microsoft.VisualStudio.VSIP.Samples.ProvidesObjectPkg
{
    /////////////////////////////////////////////////////////////////////////////
    // BasicPkg
    [MSVSIP.DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0Exp")]
    [MSVSIP.ProvideMenuResource(1000, 1)]
    [MSVSIP.ProvideObject(typeof(ChildObject))]
    [Guid("3f12db33-7716-45e3-9987-31604118ea97")]
    public class ProvidesObject : MSVSIP.Package
    {
        public ProvidesObject()
        {
            Trace.WriteLine(string.Format("Entering constructor for: {0}", typeof(ProvidesObject).ToString()));
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
                CommandID cmd = new CommandID(GuidList.guidProvidesObjectCmdSet, PkgCmdIDList.icmdMyCommand);
                MenuCommand menuCmd = new MenuCommand(new EventHandler(OnMyCommand), cmd);
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


        private void OnMyCommand(object sender, EventArgs e)
        {
            Trace.WriteLine (string.Format("Entering OnMyCommand of: {0}", this.ToString()));

            ICodeNavigate child = null;

            ILocalRegistry3 lr3 = GetService(typeof(SLocalRegistry)) as ILocalRegistry3;

            if (lr3 != null)
            {
                IntPtr pObj = IntPtr.Zero;

                Guid riid = typeof(ICodeNavigate).GUID;
                int result = lr3.CreateManagedInstance(typeof(ChildObject).Assembly.CodeBase, null, typeof(ChildObject).ToString(), ref riid, out pObj);

                if (NativeMethods.Succeeded(result) && pObj != IntPtr.Zero)
                {
                    object obj;
                    try {
                        obj = Marshal.GetObjectForIUnknown(pObj);
                        child = obj as ICodeNavigate;
                    }
                    finally {
                        Marshal.Release(pObj);
                    }
                }
                else {
                    Trace.WriteLine (string.Format("Failed to create managed instance"));
                }
            }
            else {
                Trace.WriteLine (string.Format("Failed to get ILocalregistry3 interface from SLocalRegistry service"));
            }

            if (child != null)
            {
                child.DisplayDefaultEventHandler("The string from the package");
            }

            Trace.WriteLine (string.Format("Exiting OnMyCommand of: {0}", this.ToString()));
        }
    }
}