using System;
using System.Diagnostics;
using System.Globalization;
using System.Runtime.InteropServices;
using Microsoft.VisualStudio;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.OLE.Interop;
using Microsoft.VisualStudio.Shell;

using IOleServiceProvider = Microsoft.VisualStudio.OLE.Interop.IServiceProvider;

namespace Microsoft.VisualStudio.VSIP.Samples.BasicEditor
{
    /// <summary>
    /// Factory for creating our editor
    /// </summary>
    [Guid("6bf7764f-d094-45a9-a5e7-86a00e504fa7")]
    public class EditorFactory : IVsEditorFactory
    {
        private BasicEditor MyPackage;
        private IOleServiceProvider vsServiceProvider;


        public EditorFactory(BasicEditor PackageEditor)
        {
            Trace.WriteLine(string.Format(CultureInfo.CurrentCulture, "Entering {0} constructor", this.ToString()));

            MyPackage = PackageEditor;
        }
		
        #region IVsEditorFactory Members

        public int SetSite(Microsoft.VisualStudio.OLE.Interop.IServiceProvider psp)
        {
            vsServiceProvider = psp;
            return NativeMethods.S_OK;
        }

        public int MapLogicalView(ref Guid rguidLogicalView, out string pbstrPhysicalView)
        {
            // We only support 1 phisical view, so return null
            pbstrPhysicalView = null;
            return NativeMethods.S_OK;
        }

        public int Close()
        {
            return NativeMethods.S_OK;
        }

        public int CreateEditorInstance(
                        uint grfCreateDoc,
                        string pszMkDocument,
                        string pszPhysicalView,
                        IVsHierarchy pvHier,
                        uint itemid,
                        System.IntPtr punkDocDataExisting,
                        out System.IntPtr ppunkDocView,
                        out System.IntPtr ppunkDocData,
                        out string pbstrEditorCaption,
                        out Guid pguidCmdUI,
                        out int pgrfCDW)
        {
            Trace.WriteLine(string.Format(CultureInfo.CurrentCulture, "Entering {0} CreateEditorInstace()", this.ToString()));

            // Initialize to null
            ppunkDocView = new System.IntPtr ();
            ppunkDocData = new System.IntPtr ();
            pguidCmdUI = new Guid ();
            pgrfCDW = 0;
            pbstrEditorCaption = null;

            // Validate inputs
            if ((grfCreateDoc & (NativeMethods.CEF_OPENFILE | NativeMethods.CEF_SILENT)) == 0)
            {
                throw new ArgumentException("Only Open or Silent is valid");
            }
            if (punkDocDataExisting != IntPtr.Zero)
            {
                return NativeMethods.VS_E_INCOMPATIBLEDOCDATA;
            }

            // Create the Document (editor)
            EditorPane NewEditor = new EditorPane(MyPackage);
            ppunkDocView = Marshal.GetIUnknownForObject(NewEditor);
            ppunkDocData = Marshal.GetIUnknownForObject(NewEditor);
            pbstrEditorCaption = "";
            return NativeMethods.S_OK;
        }

        #endregion
    }
}
