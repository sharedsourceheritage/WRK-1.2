//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.IO;

namespace PackageWizard
{
    /// <summary>
    /// Summary description for Page1.
    /// </summary>
    [System.Runtime.InteropServices.ComVisible(false)]
    public class Page1 : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage
    {
        // Language
        private System.Windows.Forms.RadioButton CPlusPlus;
        private System.Windows.Forms.RadioButton CSharp;
        // Key for Signing
        private System.Windows.Forms.GroupBox keyGroup;
        private System.Windows.Forms.RadioButton newKey;
        private System.Windows.Forms.RadioButton existingKey;
        private System.Windows.Forms.Label existingKeyNote;
        private System.Windows.Forms.TextBox keyPath;
        private System.Windows.Forms.Button browseButton;


        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        // List of the projects to build in order to be able to build the package.
        private ArrayList dependecies;

        // This constructor should only be called by the designer
        public Page1()
        {
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();

            // Create the list of projects a C++ package depends on
            dependecies = new ArrayList();
            dependecies.Add( @"common\VsEnvSdkUtil\vsenvsdkutil.vcproj" );

            // Set focus on the control we want to start on
            this.CPlusPlus.Focus();
        }

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        protected override void Dispose( bool disposing )
        {
            if( disposing )
            {
                if(components != null)
                {
                    components.Dispose();
                }
            }
            base.Dispose( disposing );
        }

        #region Component Designer generated code
        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.CPlusPlus = new System.Windows.Forms.RadioButton();
            this.CSharp = new System.Windows.Forms.RadioButton();
            this.newKey= new System.Windows.Forms.RadioButton();
            this.existingKey= new System.Windows.Forms.RadioButton();
            this.existingKeyNote= new System.Windows.Forms.Label();
            this.keyGroup = new System.Windows.Forms.GroupBox();
            this.keyPath = new System.Windows.Forms.TextBox();
            this.browseButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // CPlusPlus
            // 
            this.CPlusPlus.Checked = true;
            this.CPlusPlus.Location = new System.Drawing.Point(12, 12);
            this.CPlusPlus.Name = "CPlusPlus";
            this.CPlusPlus.Size = new System.Drawing.Size(460, 24);
            this.CPlusPlus.TabIndex = 0;
            this.CPlusPlus.TabStop = true;
            this.CPlusPlus.Text = "Visual C++";
            // 
            // CSharp
            // 
            this.CSharp.Location = new System.Drawing.Point(12, 48);
            this.CSharp.Name = "CSharp";
            this.CSharp.Size = new System.Drawing.Size(460, 24);
            this.CSharp.TabIndex = 1;
            this.CSharp.Text = "Visual C#";
            this.CSharp.CheckedChanged += new EventHandler(this.OnLanguageChanged);
            // 
            // keyGroup
            // 
            this.keyGroup.Location = new System.Drawing.Point(48, 84);
            this.keyGroup.Name = "keyGroup";
            this.keyGroup.Size = new System.Drawing.Size(420, 132);
            this.keyGroup.Text = "Obtain keys for assembly signing";
            this.keyGroup.Enabled = false;
            // 
            // newKey
            // 
            this.newKey.Location = new System.Drawing.Point(12, 16);
            this.newKey.Name = "newKey";
            this.newKey.Size = new System.Drawing.Size(300, 24);
            this.newKey.TabIndex = 2;
            this.newKey.Text = "Generate a new key file to sign the assembly";
            this.newKey.Checked= true;
            // 
            // existingKey
            // 
            this.existingKey.Location = new System.Drawing.Point(12, 48);
            this.existingKey.Name = "existingKey";
            this.existingKey.Size = new System.Drawing.Size(300, 24);
            this.existingKey.TabIndex = 3;
            this.existingKey.Text = "Use the following key file to sign the assembly:";
            this.existingKey.CheckedChanged += new EventHandler(this.OnKeyChanged);
            // 
            // keyPath
            // 
            this.keyPath.Location = new System.Drawing.Point(32, 72);
            this.keyPath.Name = "keyPath";
            this.keyPath.Size = new System.Drawing.Size(300, 24);
            this.keyPath.TabIndex = 4;
            this.keyPath.Text = "";
            this.keyPath.Enabled = false;
            // 
            // existingKeyNote
            // 
            this.existingKeyNote.Location = new System.Drawing.Point(32, 96);
            this.existingKeyNote.Name = "existingKeyNote";
            this.existingKeyNote.Size = new System.Drawing.Size(300, 24);
            this.existingKeyNote.Text = "The file will be copied to key.snk and added to the project.";
            this.existingKeyNote.Enabled = false;
            // 
            // browseButton
            // 
            this.browseButton.Location = new System.Drawing.Point(340, 71);
            this.browseButton.Name = "browseButton";
            this.browseButton.Size = new System.Drawing.Size(60, 22);
            this.browseButton.TabIndex = 5;
            this.browseButton.Text = "&Browse...";
            this.browseButton.Enabled = false;
            this.browseButton.Click += new EventHandler(this.OnBrowse);
            // 
            // Page1
            // 
            this.Controls.Add(this.CSharp);
            this.Controls.Add(this.CPlusPlus);
            this.keyGroup.Controls.Add(this.newKey);
            this.keyGroup.Controls.Add(this.existingKey);
            this.keyGroup.Controls.Add(this.existingKeyNote);
            this.keyGroup.Controls.Add(this.keyPath);
            this.keyGroup.Controls.Add(this.browseButton);
            this.Controls.Add(this.keyGroup);
            this.Name = "Page1";
            this.Size = new System.Drawing.Size(546, 220);
            this.ResumeLayout(false);

        }
        #endregion

        // *******************************
        // EventHandlers
        //*******************************
        private void OnLanguageChanged(object sender, System.EventArgs e)
        {
            // Only enable the UI to specify the source for the assembly signing if they select C#
            keyGroup.Enabled = CSharp.Checked;
        }

        private void OnKeyChanged(object sender, System.EventArgs e)
        {
            // Only enable the path to the key file if they want to provide their own key
            keyPath.Enabled = existingKey.Checked;
            this.existingKeyNote.Enabled = existingKey.Checked;
            browseButton.Enabled = existingKey.Checked;
        }

        private void OnBrowse(object sender, System.EventArgs e)
        {
            OpenFileDialog fileBrowser = new OpenFileDialog();
            fileBrowser.Filter = "Key files (*.snk)|*.snk|All files (*.*)|*.*";
            fileBrowser.Title = "Select a Key File to Sign Your Assembly";
            fileBrowser.ValidateNames = true;
            fileBrowser.Multiselect = false;
            fileBrowser.InitialDirectory = keyPath.Text;
            if (fileBrowser.ShowDialog(this) == DialogResult.OK)
            {
                keyPath.Text = fileBrowser.FileName;
            }
            
        }

        //*******************************
        // Wizard page functionality
        //*******************************

        public void Initialize(WizardLibrary.WizardLibrary baseWizard)
        {
        }

        public void PerformWork1(WizardLibrary.WizardLibrary baseWizard)
        {
            // Do Nothing
        }

        public void PerformWork2(WizardLibrary.WizardLibrary  baseWizard)
        {
            TokenProcessor processor = (TokenProcessor)baseWizard.customData["TokenProcessor"];
            PackageOptions options = (PackageOptions)baseWizard.customData["PackageOptions"];

            //Find the location of the template files.
            string TemplatePath = baseWizard.WizardTemplatesDir;
            
            // Creating the directory where the project will be created
            System.IO.Directory.CreateDirectory(baseWizard.newProjectLocation);

            if (baseWizard.exclusiveProject)
            {
                // Create solution
                string solutionPath = System.IO.Path.GetDirectoryName( baseWizard.newProjectLocation );
                baseWizard.application.Solution.Create(solutionPath, baseWizard.newSolutionName);
            }

            // Create main project
            string CurrentTemplatePath;
            EnvDTE.Project project = null;
            if (CSharp.Checked)
            {
                // Compute template location
                CurrentTemplatePath = System.IO.Path.Combine(TemplatePath, "CS\\");
                processor.CurrentTemplatePath = CurrentTemplatePath;

                // Create copy of the template project with correct path to dependencies
                processor.UntokenMiscFile("ProjectTemplate.csproj", baseWizard.newProjectName + ".csproj");

                // Now copy all the basic package files (they will be untokenized later)
                File.Copy(CurrentTemplatePath + "AssemblyInfo.cs", baseWizard.newProjectLocation + "\\AssemblyInfo.cs");
                File.Copy(CurrentTemplatePath + "Guids.cs", baseWizard.newProjectLocation + "\\Guids.cs");
                File.Copy(CurrentTemplatePath + "PkgCmdID.cs", baseWizard.newProjectLocation + "\\PkgCmdID.cs");
                File.Copy(CurrentTemplatePath + "VsPkg.cs", baseWizard.newProjectLocation + "\\VsPkg.cs");

                // Add the template project:
                project = baseWizard.application.Solution.AddFromFile(baseWizard.newProjectLocation + "\\" + baseWizard.newProjectName + ".csproj", false);

                // Add optional file(s)
                if ((options & PackageOptions.ToolWindow) != PackageOptions.none)
                {
                    // Compute file names and locations
                    string source = string.Format("{0}\\MyToolWindow.cs", CurrentTemplatePath);
                    string destination = (string)baseWizard.customData["ToolWindowFileName"];
                    destination += ".cs";
                    project.ProjectItems.AddFromTemplate(source, destination);
                    // Copy also the user control
                    source = System.IO.Path.Combine(CurrentTemplatePath, "MyControl.cs");
                    destination = "MyControl.cs";
                    project.ProjectItems.AddFromTemplate(source, destination);
                }
                if ((options & PackageOptions.Editor) != PackageOptions.none)
                {
                    // Compute file names and locations
                    string source = string.Format("{0}\\Editor.cs", CurrentTemplatePath);
                    string destination = (string)baseWizard.customData["EditorFileName"];
                    destination += ".cs";
                    project.ProjectItems.AddFromTemplate(source, destination);
                    source = string.Format("{0}\\EditorFactory.cs", CurrentTemplatePath);
                    project.ProjectItems.AddFromFileCopy(source);
                    source = string.Format("{0}\\EditorPane.cs", CurrentTemplatePath);
                    project.ProjectItems.AddFromFileCopy(source);
                }
                
                // Replace tokens with the actual values
                foreach(EnvDTE.ProjectItem projectItem in project.ProjectItems)
                {
                    processor.UntokenProjectFile(projectItem);
                }

                // To facilitate debugging, make F5 do: devenv /rootsuffix Exp
                string devenv = Application.ExecutablePath;
                project.ConfigurationManager.Item("Debug", "Any CPU").Properties.Item("StartAction").Value = 1;
                project.ConfigurationManager.Item("Debug", "Any CPU").Properties.Item("StartProgram").Value = devenv;
                project.ConfigurationManager.Item("Debug", "Any CPU").Properties.Item("StartArguments").Value = "/rootsuffix Exp";
                project.ConfigurationManager.Item("Release", "Any CPU").Properties.Item("StartAction").Value = 1;
                project.ConfigurationManager.Item("Release", "Any CPU").Properties.Item("StartProgram").Value = devenv;
                project.ConfigurationManager.Item("Release", "Any CPU").Properties.Item("StartArguments").Value = "/rootsuffix Exp";

                // Now process file(s) that should not have token replacement on them
                // Key file for strong assembly signing
                const string keyFileName = "Key.snk";
                string keyFile = Path.Combine(baseWizard.newProjectLocation, keyFileName);
                if (newKey.Checked)
                {
                    // Create a new key file
                    KeyGenerator.CreateNewKeyFile(keyFile);
                    project.ProjectItems.AddFromFile(keyFile);
                }
                else
                {
                    // Copy existing key file
                    project.ProjectItems.AddFromTemplate(keyPath.Text, keyFileName);
                }

                //Now close all files that were open for changing names and save them
                baseWizard.application.Documents.CloseAll(EnvDTE.vsSaveChanges.vsSaveChangesYes);
            }
            else if (CPlusPlus.Checked)
            {
                // Compute template location
                CurrentTemplatePath = System.IO.Path.Combine(TemplatePath, "VC\\");
                processor.CurrentTemplatePath = CurrentTemplatePath;

                // Creating the res directory
                System.IO.Directory.CreateDirectory(System.IO.Path.Combine(baseWizard.newProjectLocation, "res"));

                //////////////////////////////////////////
                // Adding files to the directory manually.
                // The VC support for creating project progamatically is not as nice as the C# one

                // Process each file
                processor.UntokenMiscFile("DLLEntry.cpp");
                processor.UntokenMiscFile("guids.cpp");
                processor.UntokenMiscFile("prjinc.h");
                processor.UntokenMiscFile("resource.h");
                processor.UntokenMiscFile("stdafx.cpp");
                processor.UntokenMiscFile("stdafx.h");
                processor.UntokenMiscFile("VsModule.cpp");
                processor.UntokenMiscFile("VsModule.h");
                processor.UntokenMiscFile("VsPkg.cpp");
                processor.UntokenMiscFile("VsPkg.h");
                processor.UntokenMiscFile("res\\VsPkg.rgs");
                // -- project.def
                processor.UntokenMiscFile("Project.def", baseWizard.newProjectName + ".def");
                // -- project.idl
                processor.UntokenMiscFile("Project.idl", baseWizard.newProjectName + ".idl");
                // -- project.rc
                processor.UntokenMiscFile("Project.rc.txt", baseWizard.newProjectName + ".rc");
                // -- project.vcproj
                processor.UntokenMiscFile("ProjectTemplate.vcproj", baseWizard.newProjectName + ".vcproj");

                //Get rid of the Miscellaneous Files
                /*UNDONE: make this work
                EnvDTE.Project MiscFiles = baseWizard.application.Solution.Item("Miscellaneous Files");
                foreach(EnvDTE.ProjectItem projectItem in MiscFiles.ProjectItems)
                {
                    projectItem.Remove();
                }*/

                //////////////////////////////////
                //Add the project to the solution
                project = baseWizard.application.Solution.AddFromFile(baseWizard.newProjectLocation + "\\" + baseWizard.newProjectName + ".vcproj", false);

                // Add optional files
                if ((options & PackageOptions.ToolWindow) != PackageOptions.none)
                {
                    // Register the VB activeX tool window
                    string helloDllPath = "/s \"" + baseWizard.InstallDir + "\\ToolWn\\vbdocobj\\HelloWorld.dll\"";
                    Process.Start("regsvr32.exe", helloDllPath);
                }
                if ((options & PackageOptions.Editor) != PackageOptions.none)
                {
                    string source = "editor.cpp";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "EdtCmn.cpp";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "edtfact.cpp";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "FindRepl.cpp";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "fontcombo.cpp";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "IPEditor.cpp";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "MacroRec.cpp";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "bscedtid.h";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "EdCommon.h";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "edtfact.h";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "tom.h";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                    source = "util.h";
                    processor.UntokenMiscFile(source);
                    project.ProjectItems.AddFromFile(source);
                }
                // Make F5 do: devenv /rootsuffix Exp
                string devenv = Application.ExecutablePath;
                project.ConfigurationManager.Item("Debug", "Win32").Properties.Item("Command").Value = devenv;
                project.ConfigurationManager.Item("Debug", "Win32").Properties.Item("CommandArguments").Value = "/rootsuffix Exp";
                project.ConfigurationManager.Item("Release", "Win32").Properties.Item("Command").Value = devenv;
                project.ConfigurationManager.Item("Release", "Win32").Properties.Item("CommandArguments").Value = "/rootsuffix Exp";

                // For C++ projects we have to add the dependecies to the projects that will
                // build the required libraries
                baseWizard.AddProjectDependecies(project, dependecies);
            }
            // Done creating the main project

            //////////////////////////////////////////////////////////
            // Adding Satelite DLL
            // Use the same solution to add the satellite dll project
            EnvDTE.Project UiProject = null;
            #region SatelliteDll
            CurrentTemplatePath = System.IO.Path.Combine(TemplatePath, "UI\\");
            processor.CurrentTemplatePath = CurrentTemplatePath;
            // Creating the directory where the project will be created
            processor.NewProjectPath = baseWizard.newProjectLocation + "Ui";
            System.IO.Directory.CreateDirectory(baseWizard.newProjectLocation + "Ui");

            //////////////////////////////////////////
            // Adding files to the directory manually.
            // The VC support for creating project progamatically is not as nice as the C# one

            // Process each file
            processor.UntokenMiscFile("Guids.h");
            processor.UntokenMiscFile("PkgCmd.ctc");
            processor.UntokenMiscFile("PkgCmdID.h");
            processor.UntokenMiscFile("Resource.h");
            // -- projectui.rc
            processor.UntokenMiscFile("ProjectUi.rc.txt", baseWizard.newProjectName + "Ui.rc");
            // -- projectui.vcproj
            processor.UntokenMiscFile("ProjectUi.vcproj", baseWizard.newProjectName + "Ui.vcproj");

            //////////////////////////////////
            // Add the project to the solution
            UiProject = baseWizard.application.Solution.AddFromFile(baseWizard.newProjectLocation + "Ui\\" + baseWizard.newProjectName + "Ui.vcproj", false);

            // Add the bitmap file
            UiProject.ProjectItems.AddFromTemplate(CurrentTemplatePath + "\\Images.bmp", "Images.bmp");

            // Add project to the DATA for use by other pages
            baseWizard.customData.Add("Project", project);
            baseWizard.customData.Add("UiProject", UiProject);
            #endregion

            // Now add also the satellite dll to the list of the dependecies for the main project.
            EnvDTE.BuildDependency depend = 
                baseWizard.application.Solution.SolutionBuild.BuildDependencies.Item( project.UniqueName );
            if (null != depend)
            {
                depend.AddProject( UiProject.UniqueName );
            }

            if (CPlusPlus.Checked)
            {
                // Add reference to files that are part of the UI project
                project.ProjectItems.AddFromFile(baseWizard.newProjectLocation + "Ui\\Guids.h");
                project.ProjectItems.AddFromFile(baseWizard.newProjectLocation + "Ui\\PkgCmdID.h");
            }
        }

        public void ShowHelp()
        {
        }

        public string HeadingLabel
        {
            get 
            {
                return "Select a Programming Language";
            }
        }
        public string DescriptionLabel
        {
            get 
            {
                return "You can implement your VSPackage in different programming languages. If you choose Visual C#, you must use a key file to sign the assembly.";
            }
        }
        public string HelpKeyword
        {
            get 
            {
                return "vs.vsip.VSPackageWizard.selectLanguage";
            }
        }
        public System.Drawing.Image Icon
        {
            get
            {
                System.Reflection.Assembly asm = System.Reflection.Assembly.GetExecutingAssembly();
                return System.Drawing.Image.FromStream(asm.GetManifestResourceStream("PackageWizard.SmallArtWork.bmp"));
            }
        }
        
        public bool ValidateFields()
        {
            bool pageIsValid = CPlusPlus.Checked | CSharp.Checked;
            if (!pageIsValid)
            {
                MessageBox.Show(this, "You must specify which language you want to use.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            if (CSharp.Checked && existingKey.Checked)
            {
                // This function returns false for: null, empty, invalid path name, folder, non existing.
                pageIsValid = System.IO.File.Exists(keyPath.Text);
                if (!pageIsValid)
                {
                    MessageBox.Show(this, "If you want to use an existing Key, you need to specify a valid path to the key file you want to use.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    keyPath.Focus();
                    keyPath.SelectAll();
                }
            }
            return pageIsValid;
        }
    }
}
