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

namespace PackageWizard
{
    /// <summary>
    /// Summary description for Page7.
    /// </summary>
    public class Page7 : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage
    {
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.TextBox txtExten;
        private System.Windows.Forms.Label label2;

        private ArrayList dependencies;

        private const int maxNameLen = 100;

        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        // This collection will store the tokens known by this page
        private System.Collections.Hashtable hashTokens;

        public Page7()
        {
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();

            hashTokens = new Hashtable();

            this.txtName.MaxLength = maxNameLen;

            // Create the list of the dependencies
            dependencies = new ArrayList();
            dependencies.Add( @"babel\common\common.vcproj" );
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
            this.label1 = new System.Windows.Forms.Label();
            this.txtName = new System.Windows.Forms.TextBox();
            this.txtExten = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(8, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(120, 16);
            this.label1.TabIndex = 0;
            this.label1.Text = "Language Name:";
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(128, 8);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(224, 20);
            this.txtName.TabIndex = 0;
            this.txtName.Text = "myLanguage";
            // 
            // txtExten
            // 
            this.txtExten.Location = new System.Drawing.Point(128, 40);
            this.txtExten.Name = "txtExten";
            this.txtExten.Size = new System.Drawing.Size(224, 20);
            this.txtExten.TabIndex = 1;
            this.txtExten.Text = ".ext";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(8, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(120, 16);
            this.label2.TabIndex = 2;
            this.label2.Text = "File extension(s):";
            // 
            // Page7
            // 
            this.Controls.Add(this.txtExten);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtName);
            this.Controls.Add(this.label1);
            this.Name = "Page7";
            this.Size = new System.Drawing.Size(496, 220);
            this.ResumeLayout(false);

        }
        #endregion


        public void Initialize(WizardLibrary.WizardLibrary baseWizard)
        {
            // Initialize the collection of tokens.
            hashTokens.Add("LanguageName", "");
            hashTokens.Add("LanguageExtensions", "");
        }

        public void PerformWork1(WizardLibrary.WizardLibrary baseWizard)
        {
            // Build the list of extensions.
            // NOTE: This procedure assumes that no change was made in txtExten between
            // the call of ValidateFields and the call to this function
            string [] rgstrExt = txtExten.Text.Split(';');
            string strCppCode = "";
            foreach (string ext in rgstrExt)
            {
                strCppCode += "L\"" + ext + "\", ";
            }
            hashTokens["LanguageExtensions"] = strCppCode;

            // Get the insatance of the TokenProcessor
            TokenProcessor processor = (TokenProcessor)baseWizard.customData["TokenProcessor"];
            // Now set the value of the tokens
            IDictionaryEnumerator tokens = (IDictionaryEnumerator)hashTokens.GetEnumerator();
            while ( tokens.MoveNext() )
            {
                processor.AddReplace( "%"+(string)tokens.Key+"%", (string)tokens.Value, TokenReplaceType.ReplaceCode );
            }
        }

        public void PerformWork2(WizardLibrary.WizardLibrary  baseWizard)
        {
            // Get the token processor.
            TokenProcessor processor = (TokenProcessor)baseWizard.customData["TokenProcessor"];

            // Get the installation dir of VSIP
            string installDir = baseWizard.InstallDir;

            // Find out the path of the template solution
            string strTemplatePath = System.IO.Path.Combine(baseWizard.WizardTemplatesDir, "LP");

            // Set the template path for the processor
            processor.CurrentTemplatePath = strTemplatePath;

            if (baseWizard.exclusiveProject)
            {
                // Creating the directory where the project will be created
                System.IO.Directory.CreateDirectory(baseWizard.newProjectLocation);
                // Create solution
                baseWizard.application.Solution.Create(baseWizard.newProjectLocation, baseWizard.newSolutionName);
            }

            // Now change the tokens in the files
            processor.UntokenMiscFile("service.cpp");
            processor.UntokenMiscFile("service.h");
            processor.UntokenMiscFile("bservice.vcproj", baseWizard.newProjectName + ".vcproj");

            // Add the project to the solution
            string newProjPath = System.IO.Path.Combine(baseWizard.newProjectLocation, baseWizard.newProjectName + ".vcproj");
            EnvDTE.Project mainProj = baseWizard.application.Solution.AddFromFile(newProjPath, false);

            // Add all the dependecies to the main project
            baseWizard.AddProjectDependecies(mainProj, dependencies);

        }

        public void ShowHelp()
        {
        }

        public string HeadingLabel
        {
            get 
            {
                return "Language Information";
            }
        }
        public string HelpKeyword
        {
            get
            {
                // TODO:  Add TitlePage.HelpKeyword getter implementation
                return "vs.vsip.LangServWiz.langInfo";
            }
        }
        public string DescriptionLabel
        {
            get 
            {
                return "Provide information about your language. " +
                    "This will register the selected file extensions for your language service.";
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
            // The name of the language must be set.
            if (txtName.Text.Trim() == "")
            {
                MessageBox.Show(this, "You must specify a name for the language.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            string tokenVal = txtName.Text.Replace("\\", "\\\\");
            hashTokens["LanguageName"] = 
                "L\"" + 
                StringProcessor.EscapeString(txtName.Text, StringProcessor.LanguageType.LanguageCpp) + 
                "\"";

            // Check the file extensions. 
            // The list of the extension is supposed to be separated by a ';'.
            // The list can be empty, but no element in the list can be an empty string
            string [] rstrExt = txtExten.Text.Split(';');
            string strNewText = "";
            foreach (string ext in rstrExt)
            {
                string str = ext.Trim();
                if (str.Length == 0)
                {
                    // If this extension is an empty string, just skip it
                    continue;
                }
                // The extension must start with '.' and must contain at least another char
                if (str[0] != '.')
                {
                    str = '.' + ext;
                }
                else
                {
                    if (str.Length == 1)
                    {
                        MessageBox.Show(this, "A simple dot is not a correct file extension.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return false;
                    }
                }
                if ( strNewText.Length > 0 )
                    strNewText += ";";
                strNewText += str;
            }

            // Check that there is at least one extension
            if ( strNewText.Length == 0 )
            {
                MessageBox.Show(this, "You must specify a file extension.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtExten.Focus();
                return false;
            }

            // Check that there is no invalid char in the extension
            char[] invalidChars = {'/','\\','?','*','<','>','|','"',':'};
            int indexInvalid = strNewText.IndexOfAny(invalidChars);
            if ( indexInvalid > -1 )
            {
                MessageBox.Show(this, string.Format("Invalid character found at position {0} in the extension name. The following characters should not appear in the extension:  /\\?*<>|:\"", indexInvalid.ToString()), "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtExten.Focus();
                return false;
            }

            // All done, all the extension are correct; set the text of the textbox so that 
            // the user can see the correction we made and also this way the text is correct
            txtExten.Text = strNewText;

            return true;
        }

    }
}
