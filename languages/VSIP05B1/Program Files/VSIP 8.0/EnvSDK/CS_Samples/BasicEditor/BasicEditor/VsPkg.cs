/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cs : Implementation of BasicEditor
//

using System;
using System.Diagnostics;
using System.Globalization;
using System.Runtime.InteropServices;
using Microsoft.Win32;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.OLE.Interop;
using Microsoft.VisualStudio.Shell;

using MSVSIP = Microsoft.VisualStudio.Shell;

namespace Microsoft.VisualStudio.VSIP.Samples.BasicEditor
{
    /////////////////////////////////////////////////////////////////////////////
    // BasicEditor
    [MSVSIP.DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0Exp")]
    [MSVSIP.InstalledProductRegistration(ProductNameResId=100, ProductDetailsResId=102, IconResId=400, ProductId="8.0")]
    [MSVSIP.RegisterLoadKey("Standard", "8.0", "Basic Managed Editor (C#)", "Microsoft", 1)]
    [MSVSIP.ProvideMenuResource(1000, 1)]
    [MSVSIP.RegisterEditorExtensionAttribute(typeof(EditorFactory), ".myext", 32, 
                    ProjectGuid = "{A2FE74E1-B743-11d0-AE1A-00A0C90FFFC3}", 
                    TemplateDir = "..\\..\\Templates", 
                    NameResourceID = 106)]
    [Guid("a4635212-1cf4-4f5d-92ed-74dc17f6f5c8")]
    public class BasicEditor : MSVSIP.Package
    {


        private EditorFactory editorFactory;

        public BasicEditor()
        {
            Trace.WriteLine(string.Format(CultureInfo.CurrentCulture, "Entering constructor for: {0}", this.ToString()));
        }



        /////////////////////////////////////////////////////////////////////////////
        // CBscPkgPackage Package Implementation
        #region Package Members

        protected override void Initialize()
        {
            Trace.WriteLine (string.Format(CultureInfo.CurrentCulture, "Entering Initialize() of: {0}", this.ToString()));
            base.Initialize();

            //Create Editor Factory
            editorFactory = new EditorFactory(this);
            base.RegisterEditorFactory(editorFactory);

        }

        protected override void Dispose(bool disposing)
        {
            Trace.WriteLine (string.Format(CultureInfo.CurrentCulture, "Entering Dispose() of: {0}", this.ToString()));

            base.Dispose(disposing);
        }

        protected override object GetAutomationObject(
            /*[in] */ string propName)
        {
            Trace.WriteLine (string.Format(CultureInfo.CurrentCulture, "Entering GetAutomationObject() of: {0}", this.ToString()));

            throw new NotImplementedException();
        }

        #endregion

    }
}