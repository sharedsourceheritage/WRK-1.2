//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Globalization;
using System.Windows.Forms;
using Microsoft.Win32;

namespace WizardLibrary
{
    /// <summary>
    /// Definition of IWizardPage. Implemented by UserControl objects that wish to be a page within a wizard.
    /// </summary>
    public interface IWizardPage
    {
        /// <summary>
        /// Perform the first stage of code generation
        /// </summary>
        /// <param name="wizardLibrary">An instance of the framework library</param>
        void PerformWork1(WizardLibrary wizardLibrary);

        /// <summary>
        /// Perform the second, and final stage of code generation
        /// </summary>
        /// <param name="wizardLibrary">An instance of the framework library</param>
        void PerformWork2(WizardLibrary wizardLibrary);

        /// <summary>
        /// The title of the page.
        /// </summary>
        string HeadingLabel
        {
            get;
        }

        /// <summary>
        /// The F1 keyword corresponding to the help for that page.
        /// </summary>
        string HelpKeyword
        {
            get;
        }

        /// <summary>
        /// The Description of the page.
        /// </summary>
        string DescriptionLabel
        {
            get;
        }

        /// <summary>
        /// The icon of the page.
        /// </summary>
        System.Drawing.Image Icon
        {
            get;
        }

        /// <summary>
        /// Startup of the wizard.
        /// </summary>
        /// <param name="wizardLibrary">An instance of the framework library</param>
        void Initialize(WizardLibrary wizardLibrary);

        /// <summary>
        /// Make sure all required fields are filled before moving to the next page
        /// </summary>
        /// <returns>true = all required fields are filled and all fields are valid
        ///             false = at least one field was invalid or missing
        ///    </returns>
        bool ValidateFields();
    }


    public interface ICanDisablePages
    {
        /// <summary>
        /// Change the value in the array to reflect which pages should be displayed
        /// by the wizard based on the current options.
        /// This function should only change pages with index greater then currentPage.
        /// Use index relative to currentPage rather then absolute value so that
        /// page insertion at the begining of the wizard does not force this to be
        /// updated.
        /// </summary>
        /// <param name="pageStatus">[in/out] array specifying for each page if it should be displayed</param>
        /// <param name="size">[in] size of the pageStatus array</param>
        /// <param name="currentPage">[in] index of the page corresponding to "this"</param>
        void SetEnabledPages(bool[] pageStatus, int size, int currentPage);
    }


    public interface IUpdateNextButton
    {
        void UpdateNextButton();
    }

    /// <summary>
    /// Summary description for WizardLibrary.
    /// </summary>
    public abstract class WizardLibrary : System.Windows.Forms.Form, EnvDTE.IDTWizard, IUpdateNextButton
    {

        private System.ComponentModel.Container components = null;
        private bool[] pagesStatus;
        protected PackageWizard.TitlePage titlePage;
		private WinWrapper parentWindow;

        private readonly System.Drawing.Size mySize;

        protected string wizardName;
        protected string installDir;
        public string InstallDir
        {
            get
            {
                return installDir;
            }
        }

        // Registry root for VSIP.
        private const string vsipRegistryRoot = "Software\\Microsoft\\VisualStudio\\VSIP\\8.0";
        // This constant is the registry entry for the VSIP Wizards.
        // All the informations that the wizards need to persist between different runs
        // are suposed to be store under this key.
        private const string vsipWizardRegistryRoot = vsipRegistryRoot + @"\Wizards";

        // The path of the templates folder relative to the VSIP installation root.
        private const string wizardTemplatesFolder = @"EnvSDK\tools\Wizards\Templates";

        public string GetRegistryValue(string LabelName, string Default)
        {
            string strKeyName = vsipWizardRegistryRoot + @"\" + wizardName;
            Microsoft.Win32.RegistryKey regKey = Microsoft.Win32.Registry.CurrentUser.OpenSubKey(strKeyName);
            if ( regKey == null )
            {
                // If the registry key can't be opened (e.g. doesn't exist), return the default value
                return Default;
            }

            string strValue = regKey.GetValue(LabelName) as string;
            if (strValue == null)
            {
                // It was not possible to open the value, or its type is not string
                return Default;
            }

            // The value was found, return it
            return strValue;
        }

        public int GetRegistryValue(string LabelName, int Default)
        {
            string strKeyName = vsipWizardRegistryRoot + @"\" + wizardName;
            Microsoft.Win32.RegistryKey regKey = Microsoft.Win32.Registry.CurrentUser.OpenSubKey(strKeyName);
            if ( regKey == null )
            {
                // If the registry key can't be opened (e.g. doesn't exist), return the default value
                return Default;
            }

            int iValue;
            try
            {
                iValue = (int)regKey.GetValue(LabelName);
            }
            catch(Exception)
            {
                return Default;
            }

            // The value was found, return it
            return iValue;
        }

        public void SetRegistryValue(string LabelName, object Value)
        {
            // Open or create the registry key
            string strKeyName = vsipWizardRegistryRoot + @"\" + wizardName;
            Microsoft.Win32.RegistryKey regKey = Microsoft.Win32.Registry.CurrentUser.CreateSubKey(strKeyName);
            if ( regKey == null )
            {
                // We can't create the registry key.
                return;
            }
            regKey.SetValue(LabelName, Value);
        }

        /// <summary>
        /// Constructor for the WizardLibrary class
        /// </summary>
        protected WizardLibrary()
        {
            //
            // Required for Windows Form Designer support
            //
            InitializeComponent();

            mySize = new Size(500, 374);
            _wizardPages = new System.Collections.ArrayList();
            wizardResult = EnvDTE.wizardResult.wizardResultSuccess;
            customData = new System.Collections.Specialized.ListDictionary();

            wizardName = "";
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

        #region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
			this.hostPanel = new System.Windows.Forms.Panel();
			this.nextButton = new System.Windows.Forms.Button();
			this.backButton = new System.Windows.Forms.Button();
			this.helpButton = new System.Windows.Forms.Button();
			this.finishButton = new System.Windows.Forms.Button();
			this.cancelButton = new System.Windows.Forms.Button();
			this.panel1 = new System.Windows.Forms.Panel();
			this.iconPictureBox = new System.Windows.Forms.PictureBox();
			this.descriptionLabel = new System.Windows.Forms.Label();
			this.captionLabel = new System.Windows.Forms.Label();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.panel1.SuspendLayout();
			this.SuspendLayout();
			// 
			// hostPanel
			// 
			this.hostPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
				| System.Windows.Forms.AnchorStyles.Left) 
				| System.Windows.Forms.AnchorStyles.Right)));
			this.hostPanel.Location = new System.Drawing.Point(0, 74);
			this.hostPanel.Name = "hostPanel";
			this.hostPanel.Size = new System.Drawing.Size(499, 221);
			this.hostPanel.TabIndex = 0;
			// 
			// nextButton
			// 
			this.nextButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.nextButton.Location = new System.Drawing.Point(365, 313);
			this.nextButton.Name = "nextButton";
			this.nextButton.Size = new System.Drawing.Size(58, 20);
			this.nextButton.TabIndex = 4;
			this.nextButton.Text = "&Next >";
			this.nextButton.Click += new System.EventHandler(this.nextButton_Click);
			// 
			// backButton
			// 
			this.backButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.backButton.Location = new System.Drawing.Point(307, 313);
			this.backButton.Name = "backButton";
			this.backButton.Size = new System.Drawing.Size(58, 20);
			this.backButton.TabIndex = 3;
			this.backButton.Text = "< &Back";
			this.backButton.Click += new System.EventHandler(this.backButton_Click);
			// 
			// helpButton
			// 
			this.helpButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.helpButton.Location = new System.Drawing.Point(11, 313);
			this.helpButton.Name = "helpButton";
			this.helpButton.Size = new System.Drawing.Size(58, 20);
			this.helpButton.TabIndex = 1;
			this.helpButton.Text = "&Help";
			this.helpButton.Click += new System.EventHandler(this.helpButton_Click);
			// 
			// finishButton
			// 
			this.finishButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.finishButton.Location = new System.Drawing.Point(427, 313);
			this.finishButton.Name = "finishButton";
			this.finishButton.Size = new System.Drawing.Size(58, 20);
			this.finishButton.TabIndex = 5;
			this.finishButton.Text = "&Finish";
			this.finishButton.Click += new System.EventHandler(this.finishButton_Click);
			// 
			// cancelButton
			// 
			this.cancelButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.cancelButton.Location = new System.Drawing.Point(245, 313);
			this.cancelButton.Name = "cancelButton";
			this.cancelButton.Size = new System.Drawing.Size(58, 20);
			this.cancelButton.TabIndex = 2;
			this.cancelButton.Text = "Cancel";
			this.cancelButton.Click += new System.EventHandler(this.cancelButton_Click);
			// 
			// panel1
			// 
			this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
				| System.Windows.Forms.AnchorStyles.Right)));
			this.panel1.BackColor = System.Drawing.Color.White;
			this.panel1.Controls.Add(this.iconPictureBox);
			this.panel1.Controls.Add(this.descriptionLabel);
			this.panel1.Controls.Add(this.captionLabel);
			this.panel1.Location = new System.Drawing.Point(0, 0);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(499, 66);
			this.panel1.TabIndex = 6;
			// 
			// iconPictureBox
			// 
			this.iconPictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.iconPictureBox.BackColor = System.Drawing.Color.White;
			this.iconPictureBox.Location = new System.Drawing.Point(447, 10);
			this.iconPictureBox.Name = "iconPictureBox";
			this.iconPictureBox.Size = new System.Drawing.Size(40, 46);
			this.iconPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
			this.iconPictureBox.TabIndex = 2;
			this.iconPictureBox.TabStop = false;
			// 
			// descriptionLabel
			// 
			this.descriptionLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
				| System.Windows.Forms.AnchorStyles.Right)));
			this.descriptionLabel.BackColor = System.Drawing.Color.White;
			this.descriptionLabel.Location = new System.Drawing.Point(14, 30);
			this.descriptionLabel.Name = "descriptionLabel";
			this.descriptionLabel.Size = new System.Drawing.Size(426, 28);
			this.descriptionLabel.TabIndex = 1;
			this.descriptionLabel.Text = "label1";
			// 
			// captionLabel
			// 
			this.captionLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
				| System.Windows.Forms.AnchorStyles.Right)));
			this.captionLabel.BackColor = System.Drawing.Color.White;
			this.captionLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
			this.captionLabel.Location = new System.Drawing.Point(9, 8);
			this.captionLabel.Name = "captionLabel";
			this.captionLabel.Size = new System.Drawing.Size(419, 18);
			this.captionLabel.TabIndex = 0;
			this.captionLabel.Text = "label1";
			// 
			// groupBox1
			// 
			this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
				| System.Windows.Forms.AnchorStyles.Right)));
			this.groupBox1.BackColor = System.Drawing.Color.White;
			this.groupBox1.Location = new System.Drawing.Point(0, 64);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(499, 7);
			this.groupBox1.TabIndex = 7;
			this.groupBox1.TabStop = false;
			// 
			// groupBox2
			// 
			this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
			this.groupBox2.Location = new System.Drawing.Point(0, 294);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(520, 6);
			this.groupBox2.TabIndex = 8;
			this.groupBox2.TabStop = false;
			// 
			// WizardLibrary
			// 
			this.AcceptButton = this.nextButton;
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 14);
			this.CancelButton = this.cancelButton;
			this.ClientSize = new System.Drawing.Size(494, 342);
			this.ControlBox = false;
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.groupBox1);
			this.Controls.Add(this.cancelButton);
			this.Controls.Add(this.finishButton);
			this.Controls.Add(this.helpButton);
			this.Controls.Add(this.backButton);
			this.Controls.Add(this.nextButton);
			this.Controls.Add(this.hostPanel);
			this.Controls.Add(this.panel1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "WizardLibrary";
			this.ShowInTaskbar = false;
			this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
			this.Text = "WizardLibrary";
			this.panel1.ResumeLayout(false);
			this.ResumeLayout(false);
		        this.Resize +=new EventHandler(WizardLibrary_Resize);
		}
        #endregion

        public string wizardType;
        public string newProjectName;
        public string newProjectLocation;
        public string visualStudioInstallDirectory;
        public bool exclusiveProject;
        public string newSolutionName;
        public bool runSilent;
        public string projectName;
        public EnvDTE.ProjectItems projectItems;
        public string newItemLocation;
        public string newItemName;
        public string productInstallDirectory;
        public EnvDTE.DTE application;
        public object []CustomArguments;
        public System.Collections.Specialized.ListDictionary customData;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.PictureBox iconPictureBox;
        private System.Windows.Forms.Label descriptionLabel;
        private System.Windows.Forms.Label captionLabel;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.GroupBox groupBox2;

        /// <summary>
        /// Object to support parenting a window to the main IDE window.
        /// </summary>
        class WinWrapper : System.Windows.Forms.IWin32Window
        {
            public WinWrapper(int handle)
            {
                _handle = handle;
            }
            int _handle;
            public System.IntPtr Handle
            {
                get
                {
                    return new System.IntPtr(_handle);
                }
            }
        }

        /// <summary>
        /// Implementation of the EnvDTE.IDTWizard.Execute interface
        /// </summary>
        /// <param name="Application">A EnvDTE.DTE object</param>
        /// <param name="hwndOwner">Window parent handle</param>
        /// <param name="ContextParams"></param>
        /// <param name="CustomParams"></param>
        /// <param name="retval"></param>
        public void Execute(object Application, int hwndOwner, ref object[] ContextParams, ref object[] CustomParams, ref EnvDTE.wizardResult retval)
        {
            application = (EnvDTE.DTE)Application;
            if(application.ItemOperations.PromptToSave == EnvDTE.vsPromptResult.vsPromptResultCancelled)
            {
                retval = EnvDTE.wizardResult.wizardResultCancel;
                return;
            }

            // Make sure EvExtra is installed properly
            if (GetInstallDir() == string.Empty)
            {
                MessageBox.Show(this, "Some components could not be found. Please resintall VSIP Extra and try again.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                retval = EnvDTE.wizardResult.wizardResultCancel;
                return;
            }

            CustomArguments = CustomParams;
            wizardType = (string)ContextParams[0];
            
            //Fill in the available parameters based on the wizard type:
            if(System.String.Compare(wizardType, EnvDTE.Constants.vsWizardNewProject, true) == 0)
            {
                newProjectName = (string)ContextParams[1];
                newProjectLocation = (string)ContextParams[2];
                visualStudioInstallDirectory = (string)ContextParams[3];
                exclusiveProject = (bool)ContextParams[4];
                newSolutionName = (string)ContextParams[5];
                runSilent = (bool)ContextParams[6];
            }
            else if(System.String.Compare(wizardType, EnvDTE.Constants.vsWizardAddItem, true) == 0)
            {
                projectName = (string)ContextParams[1];
                projectItems = (EnvDTE.ProjectItems)ContextParams[2];
                newItemLocation = (string)ContextParams[3];
                newItemName = (string)ContextParams[4];
                productInstallDirectory = (string)ContextParams[5];
                runSilent = (bool)ContextParams[6];
            }

            // Create title page (must be done before calling Execute)
            titlePage = new PackageWizard.TitlePage(application);

            // Allow the wizard to create pages
            Execute((EnvDTE.DTE)Application, ref CustomParams);

            // Enable every pages
            pagesStatus = new bool[_wizardPages.Count];
            for(int i=0; i<pagesStatus.Length; ++i)
                pagesStatus[i] = true;
            // Disable pages that should not be enabled
            for(int index=0; index<_wizardPages.Count; ++index)
            {
                if (_wizardPages[index] is ICanDisablePages)
                {
                    ICanDisablePages pageDisabler = _wizardPages[index] as ICanDisablePages;
                    pageDisabler.SetEnabledPages(pagesStatus, pagesStatus.Length, index);
                }
            }

            if((_wizardPages.Count > 0) && (runSilent == false))
            {
                //If there is more than one page, and we should show UI,
				parentWindow = new WinWrapper(hwndOwner);

                // Start with the title page
                if (!DisplayTitlePage())
                {
                    retval = wizardResult;
                    return;
                }
                this.Hide();
                // then display the UI and run the wizard.
                if(_wizardPages.Count == 1)
                    nextButton.Enabled = false;
                else
                    nextButton.Enabled = true;
                currentPage = (IWizardPage)_wizardPages[0];
                System.Windows.Forms.Control control = (System.Windows.Forms.Control)_wizardPages[0];
                control.Visible = true;
                captionLabel.Text = currentPage.HeadingLabel;
                Text = wizardTitle + " (Page 1 of " + _wizardPages.Count.ToString() + ")";
                descriptionLabel.Text = currentPage.DescriptionLabel;
                iconPictureBox.Image = currentPage.Icon;
                this.ShowDialog(parentWindow);
                retval = wizardResult;
            }
            else if(runSilent == true)
            {
                //If the runSilent param is true, then do not display UI

                //Simulate clicking the finish button:
                finishButton_Click(null, null);

                retval = wizardResult;
            }
        }

        /// <summary>
        /// Add a list of projects to the dependecies for the specified project.
        /// </summary>
        /// <param name="Proj">The project to add the dependecies to.</param>
        /// <param name="depends">The list of projects to build before Proj.</param>
        public void AddProjectDependecies(EnvDTE.Project Proj, ArrayList depends)
        {
            // Get the VISP installation folder
            string installDir = this.InstallDir;

            // Add all the dependencies to the solution
            foreach (string depProj in depends)
            {
                string depProjPath;
                // Check if the path is absoute or relative
                if ( System.IO.Path.IsPathRooted(depProj) )
                {
                    depProjPath = depProj;
                }
                else
                {
                    // if the path is relative, then assume it is relative to
                    // the installation folder.
                    depProjPath = System.IO.Path.Combine(installDir, depProj);
                }

                // Check if the project exists
                if ( !System.IO.File.Exists(depProjPath) )
                {
                    string errorString = "This project depends on the following project that is not in the expected location:\n";
                    errorString += depProjPath + "\n\n";
                    errorString += "The wizard will continue to create your solution, but build errors are expected.";
                    MessageBox.Show(this, errorString, "Microsoft Development Environment, MessageBoxButtons.OK, MessageBoxIcon.Warnings");
                }
                else
                {
                    EnvDTE.Project newProj = this.application.Solution.AddFromFile(depProjPath, false);

                    // Get the dependencies object for the project
                    EnvDTE.BuildDependency depend = this.application.Solution.SolutionBuild.BuildDependencies.Item(Proj.UniqueName);
                    Debug.Assert(depend != null, "Error getting the build dependency object");

                    if (null != depend)
                    {
                        depend.AddProject(newProj.UniqueName);
                    }
                    
                }
            }
        }

        EnvDTE.wizardResult wizardResult;

        private System.Windows.Forms.Button nextButton;
        private System.Windows.Forms.Button backButton;
        private System.Windows.Forms.Button helpButton;
        private System.Windows.Forms.Button finishButton;
        private System.Windows.Forms.Button cancelButton;

        private System.Windows.Forms.Panel hostPanel;

        private string wizardTitle;

        /// <summary>
        /// Set the title of the wizard UI.
        /// </summary>
        public string Title
        {
            set
            {
                this.Text = value;
                wizardTitle = value;
            }
        }

        /// <summary>
        /// Add a page to the wizard.
        /// </summary>
        /// <param name="page">The page to be added. Should be implemented on a UserControl object.</param>
        /// <returns>Position in the list of pages the item is added to.</returns>
        public int AddPage(IWizardPage page)
        {
            System.Windows.Forms.Control control = (System.Windows.Forms.Control)page;
            control.Visible = false;
            control.Parent = this.hostPanel;
            control.Top = 0;
            control.Left = 0;
            control.Width = this.hostPanel.Width;
            control.Height = this.hostPanel.Height;
            page.Initialize(this);
            return _wizardPages.Add(page);
        }

        /// <summary>
        /// Create a project based on a project template
        /// </summary>
        /// <param name="templatePath">The path to the source project</param>
        /// <returns>The EnvDTE.Project object that is added to the solution</returns>
        public EnvDTE.Project CreateProject(string templatePath)
        {
            if((newSolutionName.Length > 0) && (exclusiveProject == true))
            {
                string solutionPath = newProjectLocation.Substring(0, newProjectLocation.LastIndexOf("\\"));
                application.Solution.Create(solutionPath, newSolutionName);
            }
            System.IO.Directory.CreateDirectory(newProjectLocation);
            return application.Solution.AddFromTemplate(templatePath, newProjectLocation, newProjectName, exclusiveProject);
        }

        public abstract void Execute(EnvDTE.DTE applicationObject, ref object[] CustomParams);

        IWizardPage currentPage;
        System.Collections.ArrayList _wizardPages;

        // This function will perform the real package creation asking to each page
        // to do whatever it has to do in order to build the solution.
        protected virtual void CreatePackage()
        {
            try
            {
                foreach(IWizardPage page in _wizardPages)
                {
                    page.PerformWork1(this);
                }
                foreach(IWizardPage page2 in _wizardPages)
                {
                    page2.PerformWork2(this);
                }
                wizardResult = EnvDTE.wizardResult.wizardResultSuccess;
            }
            catch(System.Exception)
            {
                wizardResult = EnvDTE.wizardResult.wizardResultFailure;
            }
        }

        /// <summary>
        /// Show the Title page
        /// If return value is false, caller should close the wizard
        /// </summary>
        private bool DisplayTitlePage()
        {
            this.Hide();
            titlePage.Location = this.Location;

            try
            {
                DialogResult result = titlePage.ShowDialog(parentWindow);
                // Map the result to the button
                if (result == DialogResult.Cancel)
                {
                    cancelButton_Click(null, null);
                }
                else if (result == DialogResult.Yes)
                {
                    finishButton_Click(null, null);
                }
                else if (result == DialogResult.No)
                {
                    wizardResult = EnvDTE.wizardResult.wizardResultBackOut;
                }
                else
                {
                    this.Location = titlePage.FinalLocation;
                    return true;
                }
            }
            finally
            {
                titlePage.Dispose();
            }
            return false;
        }

        /// <summary>
        /// Finish running the wizard, walk the pages calling the appropriate
        /// method to generate code.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void finishButton_Click(object sender, System.EventArgs e)
        {
            try
            {
                System.Windows.Forms.Control control = (System.Windows.Forms.Control)currentPage;

                // make sure current and following pages are valid (previous one have already been validated)
                int index = _wizardPages.IndexOf(currentPage);
                int oldIndex = -1;
                // First find the last enabled page
                int lastPage = _wizardPages.Count - 1;
                while (!pagesStatus[lastPage] && lastPage > index)
                {
                    --lastPage;
                }
                // Now validate all remaining pages
                while (index < lastPage)
                {
                    // Move to the next page
                    nextButton_Click(null, null);
                    oldIndex = index;
                    index = _wizardPages.IndexOf(currentPage);
                    // if an error was detected, both index will be the same
                    if (oldIndex == index)
                        return;
                }
                // If we did not detect any error validate the last page (which does not support next)
                if (!currentPage.ValidateFields())
                {
                    control.Focus();
                    return;
                }
                // hide page specific information has this is not necessary the page where they clicked finish
                control = (System.Windows.Forms.Control)currentPage;
                control.Visible = false;

                // Perform the real work to create the package
                CreatePackage();
            }
            finally
            {
                this.Close();
            }
        }

        /// <summary>
        /// Advance to the next page in the wizard
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void nextButton_Click(object sender, System.EventArgs e)
        {
            System.Windows.Forms.Control control = (System.Windows.Forms.Control)currentPage;

            // make sure current page is valid before moving on
            if (!currentPage.ValidateFields())
            {
                control.Focus();
                return;
            }

            control.Visible = false;
            int nIndex = _wizardPages.IndexOf(currentPage);

            // Update which page should be displayed
            if (currentPage is ICanDisablePages)
            {
                ICanDisablePages thisPage = currentPage as ICanDisablePages;
                thisPage.SetEnabledPages(pagesStatus, pagesStatus.Length, nIndex);
            }

            // Find the next page we should display
            if (pagesStatus.Length != _wizardPages.Count)
                throw new Exception("Unexpected internal state");
            bool foundNextPage = false;
            while(!foundNextPage)
            {
                ++nIndex;
                if(nIndex == _wizardPages.Count)
                {
                    throw new System.Exception("Error! No more pages, we should not be here.");
                }
                foundNextPage = pagesStatus[nIndex];
            }

            // Display the selected page
            currentPage = (IWizardPage)_wizardPages[nIndex];
            control = (System.Windows.Forms.Control)currentPage;
            control.Visible = true;
            captionLabel.Text = currentPage.HeadingLabel;
            descriptionLabel.Text = currentPage.DescriptionLabel;
            iconPictureBox.Image = currentPage.Icon;
            this.Text =  wizardTitle + " (Page " + (nIndex+1).ToString(CultureInfo.CurrentUICulture) + " of " + _wizardPages.Count.ToString(CultureInfo.CurrentUICulture) + ")";
            UpdateNextButton();
            control.Focus();
        }

        /// <summary>
        /// Back up one page in the wizard, or, if the page displayed is the first
        /// page, then return to the Ne Project/Add New Item dialog
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void backButton_Click(object sender, System.EventArgs e)
        {
            System.Windows.Forms.Control control = (System.Windows.Forms.Control)currentPage;

            control.Visible = false;
            int nNextPage = _wizardPages.IndexOf(currentPage);
            if(nNextPage == 0)
            {
                // Go back to title page
				if (!DisplayTitlePage())
				{
					this.Close();
					return;
				}
				else
				{
					this.Show();
				}
            }
            else
            {
                // Find previous displayable page
                --nNextPage;
                while(nNextPage>0 && !pagesStatus[nNextPage])
                    --nNextPage;
                currentPage = (IWizardPage)_wizardPages[nNextPage];
                nextButton.Enabled = true;
                AcceptButton = nextButton;
                control.Focus();
            }
            control = (System.Windows.Forms.Control)currentPage;
            control.Visible = true;
            captionLabel.Text = currentPage.HeadingLabel;
            descriptionLabel.Text = currentPage.DescriptionLabel;
            iconPictureBox.Image = currentPage.Icon;
            ++nNextPage;
            this.Text =  wizardTitle + " (Page " + nNextPage.ToString(CultureInfo.CurrentUICulture) + " of " + _wizardPages.Count.ToString(CultureInfo.CurrentUICulture) + ")";
        }

        /// <summary>
        /// Invoke help for the currently displayed page
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void helpButton_Click(object sender, System.EventArgs e)
        {
            // Get the help for the current page
            Microsoft.VisualStudio.VSHelp.Help help = (Microsoft.VisualStudio.VSHelp.Help)application.DTE.GetObject("Help");
            help.DisplayTopicFromF1Keyword(currentPage.HelpKeyword);
        }

        /// <summary>
        /// Cancel out of the wizard
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void cancelButton_Click(object sender, System.EventArgs e)
        {
            wizardResult = EnvDTE.wizardResult.wizardResultCancel;
            this.Close();
        }

        /// <summary>
        /// Look for the existance/content of the VSIP Extra install directory
        /// </summary>
        /// <returns>Location where VSIP Extra was installed, null if you don't want it back</returns>
        public string GetInstallDir()
        {
            string installDir = string.Empty;

            using (RegistryKey key = Registry.LocalMachine.OpenSubKey(vsipRegistryRoot))
            {
                if (key != null)
                {
                    object obj = key.GetValue("InstallDir");
                    if (obj != null && obj is string)
                    {
                        installDir = obj as string;
                    }
                }
            }
            return installDir;
        }

        public string WizardTemplatesDir
        {
            get
            {
                string installationDir = GetInstallDir();
                return System.IO.Path.Combine(installationDir, wizardTemplatesFolder);
            }
        }

        #region IUpdateNextButton Members

        public void UpdateNextButton()
        {
            int nIndex = _wizardPages.IndexOf(currentPage);
            if (currentPage is ICanDisablePages)
            {
                // Update which page should be displayed
                ICanDisablePages thisPage = currentPage as ICanDisablePages;
                thisPage.SetEnabledPages(pagesStatus, pagesStatus.Length, nIndex);
            }

            // Look if there is any pages left
            bool morePage = false;
            for(int i = nIndex+1; i<pagesStatus.Length; ++i)
                morePage |= pagesStatus[i];
            if(morePage)
            {
                nextButton.Enabled = true;
                AcceptButton = nextButton;
            }
            else
            {
                nextButton.Enabled = false;
                AcceptButton = finishButton;
            }
        }

        #endregion

        private void WizardLibrary_Resize(object sender, EventArgs e)
        {
            if ( this.Size != mySize )
            {
                this.Size = mySize;
            }
        }
    }
}