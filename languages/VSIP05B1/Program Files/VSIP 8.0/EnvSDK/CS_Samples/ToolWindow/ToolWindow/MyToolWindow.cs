using System;
using System.Collections;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Drawing;
using Microsoft.Win32;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using Microsoft.VisualStudio.Shell;
using Microsoft.VisualStudio.Shell.Interop;

using IServiceProvider = System.IServiceProvider;
using IOleServiceProvider = Microsoft.VisualStudio.OLE.Interop.IServiceProvider;

namespace Microsoft.VisualStudio.VSIP.Samples.ToolWindowCS
{
    /// <summary>
    /// Summary description for MyToolWindow.
    /// </summary>
	[Guid("7b00264f-bbda-42f2-8085-723ca3712763")]
	public class MyToolWindow : ToolWindowPane
    {
		private MyControl control;

        public MyToolWindow()
            :base(null)
        {
            // set the window title
            this.Caption = "Managed Tool Window (C#)";

            // set the CommandID for the window ToolBar
            this.ToolBar = new CommandID(GuidList.guidToolWindowCmdSet, PkgCmdIDList.myMenu);

			// set the icon for the frame
			this.BitmapResourceID = 300;  // bitmap strip resource ID
			this.BitmapIndex = 3;         // index in the bitmap strip

			control = new MyControl();
        }

        override public IWin32Window Window
        {
            get
            {
                return (IWin32Window)control;
            }
        }

        /// <include file='doc\WindowPane.uex' path='docs/doc[@for="WindowPane.Dispose1"]' />
        /// <devdoc>
        ///     Called when this tool window pane is being disposed.
        /// </devdoc>
        override protected void Dispose(bool disposing)
        {
            if (disposing)
            {
                IVsWindowFrame windowFrame = (IVsWindowFrame)this.Frame;

                if (windowFrame != null)
                {
                    // Note: don't check for the return code here.
                    int hr = windowFrame.CloseFrame((uint)__FRAMECLOSE.FRAMECLOSE_SaveIfDirty);
                }
            }
            base.Dispose(disposing);
        }

        /// <summary>
        /// This function is only used to "do something noticeable" when the toolbar button is clicked.
        /// It is called from the package.
        /// A typical tool window may not need this function.
        /// 
        /// The current behavior change the background color of the control
        /// </summary>
        public void ToolBarCommand()
        {
            if (this.control.BackColor == Color.Coral)
                this.control.BackColor = Color.White;
            else
                this.control.BackColor = Color.Coral;
        }
    }
}
