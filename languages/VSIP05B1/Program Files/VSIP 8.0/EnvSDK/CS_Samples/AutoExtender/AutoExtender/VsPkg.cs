/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsPkg.cs : Implementation of AutoExtenderPackage
// Package is automatically loaded when UICONTEXT_SolutionExists is turned on
//

#define TRACE

using System;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.InteropServices;
using Microsoft.Win32;
using Microsoft.VisualStudio.Shell.Interop;

using MSVSIP = Microsoft.VisualStudio.Shell;

namespace Microsoft.VisualStudio.VSIP.Samples.AutoExtender
{
    /////////////////////////////////////////////////////////////////////////////
    // AutoExtender
    [MSVSIP.DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0Exp")]
    [MSVSIP.InstalledProductRegistration(ProductName = "Managed Auto Extender (C#)", ProductDetails = "This package extends the solution and projects", ProductId = "8.0")]
    [MSVSIP.RegisterAutoLoad("F1536EF8-92EC-443C-9ED7-FDADF150DA82")]
    [MSVSIP.RegisterExtender("A2392464-7C22-11D3-BDCA-00C04F688E50", "7C7E655A-0FBD-43c8-BC2E-C83BB68BFFA2" , "StaticSolutionBrowserObjExtender")]
    [MSVSIP.ProvideObject(typeof(StaticExtenderProvider))]
    [Guid("00689F3B-0D4A-4cb2-B427-CB9491A8F1FF")]
    public class AutoExtenderPackage : MSVSIP.Package
    {
        public AutoExtenderPackage()
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName);
            cookieDynamicExtenderProvider = 0;
            Trace.WriteLine("Leaving " + methodName);
        }

        // Finializable object take longer to allocate and more than one 
        // generations to GC. Implement descructor only when it's really 
        // needed.
        // ~AutoExtenderPackage()
        // {
        // }

        /////////////////////////////////////////////////////////////////////////////
        // AutoExtenderPackage Package Implementation
        #region Package Members

        protected override void Initialize()
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName);

            base.Initialize();

            // get extender manager
            extensionManager = (EnvDTE.ObjectExtenders)GetService(typeof(EnvDTE.ObjectExtenders));
            if (null == extensionManager)
            {
                throw new NullReferenceException("GetService failed to get the extender object");
            }

            // create dynamic extender provider instance
            dynamicExtenderProvider = new DynamicExtenderProvider();
            
            // register dynamic extender provider with extension manager
            cookieDynamicExtenderProvider = extensionManager.RegisterExtenderProvider(
                    VSLangProj.PrjBrowseObjectCATID.prjCATIDCSharpProjectBrowseObject, 
                    DynamicExtenderProvider.DynamicExtenderName,
                    dynamicExtenderProvider,
                    string.Empty);            // Localized name
            Trace.WriteLine(String.Format("DynamicExtenderProvider registered 0x{0:X}", cookieDynamicExtenderProvider) );

            Trace.WriteLine("Leaving " + methodName);
        }

        protected override void Dispose(bool disposing)
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName + " " + disposing);

            // unregister dynamic extender provider with extension manager
            if (null!=extensionManager && 0!=cookieDynamicExtenderProvider)
            {
                extensionManager.UnregisterExtenderProvider(cookieDynamicExtenderProvider);
                Trace.WriteLine("DynamicExtenderProvider unregistered");
            }
            base.Dispose(disposing);

            Trace.WriteLine("Leaving " + methodName);
        }

        #endregion


        //////////////////////////////////////////////////////////////////
        // AutoExtenderPackage Fields

        private EnvDTE.ObjectExtenders extensionManager;
        private DynamicExtenderProvider dynamicExtenderProvider;

        // This cookie identifies a dynamic extender provider registered at 
        // extension manager's site. It's returned from RegisterExtenderProvider
        // call and passed as in-param when calling UnregisterExtenderProvider. 
        private int cookieDynamicExtenderProvider;
    }
} 
