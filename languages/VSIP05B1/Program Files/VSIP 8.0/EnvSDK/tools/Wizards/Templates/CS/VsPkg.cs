/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cs : Implementation of %ProjectClass%
//

using System;
using System.Diagnostics;
using System.Globalization;
using System.Runtime.InteropServices;
using System.ComponentModel.Design;
using Microsoft.Win32;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.OLE.Interop;
using Microsoft.VisualStudio.Shell;
using MSVSIP = Microsoft.VisualStudio.Shell;

[assembly:ComVisible(true)]

namespace Vsip.%ProjectClass%
{
    /////////////////////////////////////////////////////////////////////////////
    // %ProjectClass%
    [MSVSIP.DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0")]
    [MSVSIP.InstalledProductRegistration(ProductNameResId = 100, ProductDetailsResId = 102, IconResId = 400, ProductId = "%PackageVersion%")]
    [MSVSIP.RegisterLoadKey("%MinVsEdition%", "%PackageVersion%", "%PackageName%", "%CompanyName%", 1)]
    [MSVSIP.ProvideMenuResource(1000, 1)]
%ToolWindowItemStart%    [MSVSIP.ProvideToolWindow(typeof(MyToolWindow))]%ToolWindowItemEnd%
%EditorStart%    [MSVSIP.RegisterEditorExtension(typeof(EditorFactory), ".%Extension%", 32, 
              ProjectGuid = "{A2FE74E1-B743-11d0-AE1A-00A0C90FFFC3}", 
              TemplateDir = "..\\Templates", 
              NameResourceID = 106)]%EditorEnd%
    [Guid("%PackageGuid%")]
    public class %ProjectClass% : MSVSIP.Package
    {
%ToolWindowItemStart%
        const int bitmapResourceID = 300;
        private IVsWindowFrame windowFrame;
%ToolWindowItemEnd%
%EditorStart%
        private EditorFactory editorFactory;
%EditorEnd%
        public %ProjectClass%()
        {
            Trace.WriteLine(string.Format(CultureInfo.CurrentCulture, "Entering constructor for: {0}", this.ToString()));
        }

%ToolWindowItemStart%
        private void ShowToolWindow(object sender, EventArgs e)
        {
            ToolWindowPane window = this.FindToolWindow(typeof(MyToolWindow), 0, true);
            if (window != null && window.Frame != null)
            {
                windowFrame = (IVsWindowFrame)window.Frame;
            }
            if (windowFrame != null)
            {
                windowFrame.Show();
            }
        }
%ToolWindowItemEnd%

        /////////////////////////////////////////////////////////////////////////////
        // CBscPkgPackage Package Implementation
        #region Package Members

        protected override void Initialize()
        {
            Trace.WriteLine (string.Format(CultureInfo.CurrentCulture, "Entering Initialize() of: {0}", this.ToString()));
            base.Initialize();
%EditorStart%
            //Create Editor Factory
            editorFactory = new EditorFactory(this);
            base.RegisterEditorFactory(editorFactory);
%EditorEnd%

            // Add our command handlers for menu (commands must exist in the .ctc file)
            MSVSIP.OleMenuCommandService mcs = GetService(typeof(IMenuCommandService)) as MSVSIP.OleMenuCommandService;
            if ( null != mcs )
            {
%MenuItemStart%
                // Create the command for the menu item.
                CommandID menuCommandID = new CommandID(GuidList.guid%ProjectClass%CmdSet, (int)PkgCmdIDList.%CommandID%);
                MenuCommand menuItem = new MenuCommand( new EventHandler(MenuItemCallback), menuCommandID );
                mcs.AddCommand( menuItem );
%MenuItemEnd%
%ToolWindowItemStart%
                // Create the command for the tool window
                CommandID toolwndCommandID = new CommandID(GuidList.guid%ProjectClass%CmdSet, (int)PkgCmdIDList.%ToolCommandID%);
                MenuCommand menuToolWin = new MenuCommand( new EventHandler(ShowToolWindow), toolwndCommandID);
                mcs.AddCommand( menuToolWin );
%ToolWindowItemEnd%
            }
        }


        protected override void Dispose(bool disposing)
        {
            Trace.WriteLine (string.Format(CultureInfo.CurrentCulture, "Entering Dispose() of: {0}", this.ToString()));
%ToolWindowItemStart%
            if (windowFrame != null)
                windowFrame.CloseFrame((uint)__FRAMECLOSE.FRAMECLOSE_SaveIfDirty);
%ToolWindowItemEnd%
            base.Dispose(disposing);
        }

        protected override object GetAutomationObject(
            /*[in] */ string propName)
        {
            Trace.WriteLine (string.Format(CultureInfo.CurrentCulture, "Entering GetAutomationObject() of: {0}", this.ToString()));

            throw new NotImplementedException();
        }

        #endregion

%MenuItemStart%
        /// <summary>
        /// This function is the callback used to execute a command when the a menu item is clicked.
        /// </summary>
        private void MenuItemCallback(object sender, EventArgs e)
        {
            // Show a Message Box to prove we were here
            IVsUIShell uiShell = (IVsUIShell)GetService(typeof(SVsUIShell));
            Guid clsid = Guid.Empty;
            int result;
            uiShell.ShowMessageBox(
                       0,
                       ref clsid,
                       "%PackageName%",
                       string.Format(CultureInfo.CurrentCulture, "Inside {0}.MenuItemCallback()", this.ToString()),
                       string.Empty,
                       0,
                       OLEMSGBUTTON.OLEMSGBUTTON_OK,
                       OLEMSGDEFBUTTON.OLEMSGDEFBUTTON_FIRST,
                       OLEMSGICON.OLEMSGICON_INFO,
                       0,        // false
                       out result);
        }
%MenuItemEnd%


    }
}