//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Globalization;
using System.Runtime.InteropServices;
using System.Text;

namespace PackageWizard
{
    /// <summary>
    /// Summary description for Class1.
    /// </summary>
    [System.Runtime.InteropServices.ComVisible(true)]
    [GuidAttribute("6a15e75b-712d-4ae1-900a-91ff9309c952"), ProgIdAttribute("PackageWizard.Wizard")]
    public class Wizard : WizardLibrary.WizardLibrary 
    {
        // Enumeration 
        protected enum WizardType
        {
            GenericWizard    = 0,
            LanguageWizard    = 1,

            WizardTypeCount    = 2
        }
        protected WizardType wtType;

        private string[] rgstrTypes;

        public Wizard()
        {
            // Setup the types of wizards and set as default the default wizard
            wtType = WizardType.GenericWizard;
            rgstrTypes = new string[(int)WizardType.WizardTypeCount];
            rgstrTypes[(int)WizardType.GenericWizard] = "Generic";
            rgstrTypes[(int)WizardType.LanguageWizard] = "Language";
        }

        // This function will find the type of wizard requested by the caller
        private void FindWizardType(string strRequested)
        {
            if ( (strRequested == null) || (strRequested.Length == 0) )
            {
                // If the caller doesn't request any type, then use the default
                wtType = WizardType.GenericWizard;
                return;
            }

            // Loop on the defined types to find right one
            for (int i=0; i<=rgstrTypes.GetUpperBound(0); i++)
            {
                if (string.Compare(rgstrTypes[i], strRequested, true, CultureInfo.CurrentCulture)==0)
                {
                    // We have found the type
                    wtType = (WizardType)i;
                    return;
                }
            }

            // If we are here, then the requested type is unknown => throw an exception
            throw new Exception(strRequested + " is not a valid wizard type");
        }

        public override void Execute(EnvDTE.DTE application, ref object[] CustomParams)
        {
            // Get the VSIP install path from the registry
            installDir = GetInstallDir();
            if (!installDir.EndsWith("\\"))
                installDir += '\\';
            installDir += "EnvSDK";

            string strRequestedType = null;
            if (CustomParams.Length > 0)
            {
                strRequestedType = CustomParams[0] as string;
            }
            FindWizardType(strRequestedType);

            // Create the pages needed for the specified wizard type
            switch (wtType)
            {
                case WizardType.LanguageWizard:
                {
                    string strTitle = "Visual Studio Language Service Wizard";
                    Title = strTitle;
                    wizardName = "LanguagePackage";

                    // Set text for Welcome page
                    titlePage.WindowTitle = strTitle;
                    titlePage.Title = "Welcome to the Language Service Wizard";
                    titlePage.DetailedDescription = 
                        "The wizard helps you create a new VSPackage. The resulting package" +
                        " will be correctly registered to run in the VSIP Experimental environment. It will" +
                        " include basic functionality as chosen in the following pages.\r\n\r\n" +
                        "To continue, click Next.";
                    titlePage.HelpKey = "vs.vsip.LangServWiz.welcome";

                    AddPage( new Page7() );
                    AddPage( new GrammarFiles() );
                    AddPage( new LanguageOptions() );
                    AddPage( new Page8() );
                    break;
                }
                default:
                {
                    // The default case is the generic wizard
                    wizardName = "IntegrationPackage";
                    // Set title for all pages
                    string title = "Visual Studio Integration Package Wizard";
                    Title = title;

                    // Set text for Welcome page
                    titlePage.WindowTitle = title;
                    titlePage.Title = "Welcome to the Visual Studio Integration Package Wizard";
                    titlePage.DetailedDescription = "This wizard helps you create a new VSPackage. The resulting VSPackage" +
                        " will be correctly registered to run in the VSIP Experimental environment. " +
                        "The options you choose will include the basic functionality of the VSPackage." +
                        "\n\nTo continue, click Next.";
                    titlePage.HelpKey = "vs.vsip.VSPackageWizard.welcome";


                    // Create Page6 first as Page1 needs a reference to it to notify when language change
                    Page6 page6 = new Page6();
                    AddPage(new Page1());
                    AddPage(new Page2());
                    AddPage(new Page3(this));
                    AddPage(new Page4());
                    AddPage(new Page5());
                    AddPage(page6);
                    break;
                }
            }
        }

        protected override void CreatePackage()
        {
            // Create the token processor
            TokenProcessor processor = new TokenProcessor();
            processor.ProjectName = newProjectName;
            processor.NewProjectPath = newProjectLocation;
            processor.TheDTE = application.DTE;            

            // Add install directory to token processor
            processor.AddReplace("%InstallDir%", installDir, PackageWizard.TokenReplaceType.ReplaceCode);
            // Some tools do not support long path, so add the short path to the token processor
            uint shortPathMaxSize = 1024;
            StringBuilder installDirShort = new StringBuilder((int)shortPathMaxSize);
            GetShortPathName(installDir, installDirShort, shortPathMaxSize);
            processor.AddReplace("%InstallDirShort%", installDirShort.ToString(), PackageWizard.TokenReplaceType.ReplaceCode);

            // Add the token processor to data
            customData.Add("TokenProcessor", processor);

            if (exclusiveProject &&
                (newSolutionName == null || newSolutionName.Length == 0))
            {
                newSolutionName = newProjectName;
            }

            // Now call the CreatePackage as implemented in the base class
            base.CreatePackage();
        }

    [DllImport("kernel32.dll", CharSet=CharSet.Unicode)]
    private static extern uint GetShortPathName(
    string szLongPath,
    StringBuilder szShortPath,
    uint cchBufferSize);
    }
}
