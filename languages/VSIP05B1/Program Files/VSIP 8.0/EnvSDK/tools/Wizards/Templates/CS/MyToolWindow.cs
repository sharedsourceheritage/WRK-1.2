using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.Shell;

using IServiceProvider = System.IServiceProvider;
using IOleServiceProvider = Microsoft.VisualStudio.OLE.Interop.IServiceProvider;
using NativeMethods = Microsoft.VisualStudio.NativeMethods;

namespace Vsip.%ProjectClass%
{
    /// <summary>
    /// Summary description for MyToolWindow.
    /// </summary>
    [Guid("%ToolGuid%")]
    public class MyToolWindow : ToolWindowPane
    {
        // Reference to the control hosted in the window
        private MyControl control;

        public MyToolWindow() :
            base(null)
        {
            // set the window title
            this.Caption = "%ToolWindowName%";

            control = new MyControl();
        }

        override public IWin32Window Window
        {
            get
            {
                return (IWin32Window)control;
            }
        }

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        protected override void Dispose( bool disposing )
        {
            if( disposing )
            {
                IVsWindowFrame windowFrame = (IVsWindowFrame)this.Frame;

                if (windowFrame != null)
                {
                    windowFrame.CloseFrame((uint)__FRAMECLOSE.FRAMECLOSE_SaveIfDirty);
                }
            }
            base.Dispose( disposing );
        }


    }
}
