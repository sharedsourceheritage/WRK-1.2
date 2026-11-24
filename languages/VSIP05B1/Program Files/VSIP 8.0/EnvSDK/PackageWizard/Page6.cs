//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Text;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Windows.Forms;

namespace PackageWizard
{
    public enum Languages {VC, CS};
    public interface INotifyOnLanguageChange
    {
        void OnLanguagechanged(Languages currentLanguage);
    }
    /// <summary>
    /// Summary description for Page6.
    /// </summary>
    [System.Runtime.InteropServices.ComVisible(false)]
    public class Page6 : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage, INotifyOnLanguageChange
    {
        readonly static char[] invalidChar = {'/','\\','?','*','<','>','|','"',':'};

        private System.Windows.Forms.PictureBox iconPictureBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox editorName;
        private System.Windows.Forms.TextBox extension;
        private System.Windows.Forms.TextBox defaultName;

        private IconWrapper icon;
        private Languages language;
        private string ext;
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        public Page6()
        {
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();

            // TODO: Add any initialization after the InitForm call

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
            this.iconPictureBox = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            this.editorName = new System.Windows.Forms.TextBox();
            this.extension = new System.Windows.Forms.TextBox();
            this.defaultName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // iconPictureBox
            // 
            this.iconPictureBox.Location = new System.Drawing.Point(48, 16);
            this.iconPictureBox.Name = "iconPictureBox";
            this.iconPictureBox.Size = new System.Drawing.Size(32, 32);
            this.iconPictureBox.TabIndex = 1;
            this.iconPictureBox.TabStop = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 64);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(104, 24);
            this.button1.TabIndex = 0;
            this.button1.Text = "Change Icon...";
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // editorName
            // 
            this.editorName.Location = new System.Drawing.Point(272, 12);
            this.editorName.MaxLength = 128;
            this.editorName.Name = "editorName";
            this.editorName.Size = new System.Drawing.Size(208, 22);
            this.editorName.TabIndex = 2;
            this.editorName.Text = "My Editor";
            // 
            // extension
            // 
            this.extension.Location = new System.Drawing.Point(272, 48);
            this.extension.MaxLength = 15;
            this.extension.Name = "extension";
            this.extension.Size = new System.Drawing.Size(208, 22);
            this.extension.TabIndex = 3;
            this.extension.Text = "myext";
            // 
            // defaultName
            // 
            this.defaultName.Location = new System.Drawing.Point(272, 84);
            this.defaultName.MaxLength = 128;
            this.defaultName.Name = "defaultName";
            this.defaultName.Size = new System.Drawing.Size(208, 22);
            this.defaultName.TabIndex = 4;
            this.defaultName.Text = "MyExtFile";
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(136, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(128, 23);
            this.label1.TabIndex = 5;
            this.label1.Text = "Editor Name:";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(136, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(128, 23);
            this.label2.TabIndex = 6;
            this.label2.Text = "File Extension:";
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(136, 84);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(128, 23);
            this.label3.TabIndex = 7;
            this.label3.Text = "Default File Name:";
            // 
            // Page6
            // 
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.defaultName);
            this.Controls.Add(this.extension);
            this.Controls.Add(this.editorName);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.iconPictureBox);
            this.Name = "Page6";
            this.Size = new System.Drawing.Size(496, 220);
            this.ResumeLayout(false);

        }
        #endregion

        private void button1_Click(object sender, System.EventArgs e)
        {
            icon.PickNewIcon();
            iconPictureBox.Image = icon.Icon.ToBitmap();
        }

        public void Initialize(WizardLibrary.WizardLibrary baseWizard)
        {
            language = Languages.VC;
            // Load our default icon
            string iconPath = System.IO.Path.Combine(baseWizard.WizardTemplatesDir, "File.ico");
            icon = new IconWrapper(iconPath, this);
            iconPictureBox.Image = icon.Icon.ToBitmap();
        }

        public void PerformWork1(WizardLibrary.WizardLibrary baseWizard)
        {
            TokenProcessor processor = (TokenProcessor)baseWizard.customData["TokenProcessor"];
            PackageOptions options = (PackageOptions)baseWizard.customData["PackageOptions"];
            if ((options & PackageOptions.Editor) != PackageOptions.none)
            {
                // An Editor was requested
                processor.AddReplace("%EditorName%", editorName.Text, TokenReplaceType.ReplaceString);
                // Ensure the extension does NOT start with a dot
                ext = extension.Text;
                if (ext.StartsWith("."))
                    ext = ext.Substring(1);
                processor.AddReplace("%Extension%", ext, TokenReplaceType.ReplaceString);
                processor.AddReplace("%DefaultName%", defaultName.Text, TokenReplaceType.ReplaceString);
                Guid factoryGuid = Guid.NewGuid();
                processor.AddReplace("%FactoryGuid%", factoryGuid.ToString(), TokenReplaceType.ReplaceString);
                processor.AddReplace("%FactoryGuid1%", processor.GuidToForm1(factoryGuid), TokenReplaceType.ReplaceString);
                // Deletion tag must be replaced by nothing
                processor.AddReplace("%EditorStart%", "", TokenReplaceType.ReplaceString);
                processor.AddReplace("%EditorEnd%", "", TokenReplaceType.ReplaceString);

                baseWizard.customData.Add("EditorFileName", "Editor");
            }
            else
            {
                // No Editor requested
                processor.AddDelete("%EditorStart%", "%EditorEnd%");
            }
        }

        public void PerformWork2(WizardLibrary.WizardLibrary  baseWizard)
        {
            PackageOptions options = (PackageOptions)baseWizard.customData["PackageOptions"];
            if ((options & PackageOptions.Editor) != PackageOptions.none)
            {
                // Add icon file to the Ui project
                EnvDTE.Project uiProject = (EnvDTE.Project)baseWizard.customData["UiProject"];
                uiProject.ProjectItems.AddFromTemplate(icon.IconPath, "File.ico");
                EnvDTE.Project project = (EnvDTE.Project)baseWizard.customData["Project"];

                if (language != Languages.VC)
                {
                    // Add reference to the TextManager Interop Assembly
                    VSLangProj.VSProject vsProject = (VSLangProj.VSProject)project.Object;
                    vsProject.References.Add("..\\..\\common\\VSIA\\Microsoft.VisualStudio.TextManager.Interop.dll");
                }

                // Prepare to add templates
                TokenProcessor processor = (TokenProcessor)baseWizard.customData["TokenProcessor"];
                processor.CurrentTemplatePath = baseWizard.WizardTemplatesDir;

                // Creating the directory where the project will be created
                string destination = baseWizard.newProjectLocation + "\\Templates";
                System.IO.Directory.CreateDirectory(destination);
                processor.NewProjectPath = destination;

                // Add template files
                processor.UntokenMiscFile("BasicEditor.vsdir", baseWizard.newProjectName + ".vsdir");
                processor.UntokenMiscFile("myext.myext", ext + "." + ext);
            }
        }

        public void ShowHelp()
        {
        }

        public string HeadingLabel
        {
            get 
            {
                return "Editor Options";
            }
        }
        public string DescriptionLabel
        {
            get 
            {
                return "Provide information for your custom editor. The editor will be the default Visual Studio editor for files with the extension you specify.";
            }
        }
        public string HelpKeyword
        {
            get 
            {
                return "vs.vsip.VSPackageWizard.edtrOptions";
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
            bool pageIsValid = editorName.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                editorName.Focus();
                MessageBox.Show(this, "You must specify an Editor name.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            for(int i=0; pageIsValid && i<editorName.TextLength; ++i)
                pageIsValid &= char.IsLetterOrDigit(editorName.Text, i) || char.IsWhiteSpace(editorName.Text, i);
            if (!pageIsValid)
            {
                editorName.Focus();
                MessageBox.Show(this, "Editor name can only contain letters, digits and spaces.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            pageIsValid = extension.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                extension.Focus();
                MessageBox.Show(this, "You must specify a file extension.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            int index = extension.Text.IndexOfAny(invalidChar);
            pageIsValid = index < 0;
            if (!pageIsValid)
            {
                extension.Focus();
                ++index; // Although they user start indexing at 0, message looks better this way
                MessageBox.Show(this, string.Format("Invalid character found at position {0} in the extension name. The following characters should not appear in the extension:  /\\?*<>|:\"", index.ToString()), "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            index = extension.Text.IndexOf('.', 1);
            pageIsValid = index < 0;
            if (!pageIsValid)
            {
                extension.Focus();
                ++index; // Although they user start indexing at 0, message looks better this way
                MessageBox.Show(this, string.Format("Invalid character found at position {0} in the extension name. A dot can only be used at the begining of the extension", index.ToString()), "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            pageIsValid = defaultName.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                defaultName.Focus();
                MessageBox.Show(this, "You must specify a default file name.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            index = defaultName.Text.IndexOfAny(invalidChar);
            pageIsValid = index < 0;
            if (!pageIsValid)
            {
                defaultName.Focus();
                ++index; // Although they user start indexing at 0, message looks better this way
                MessageBox.Show(this, string.Format("Invalid character found at position {0} in the default file name. The following characters should not be used:  /\\?*<>|:\"", index.ToString()), "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            return pageIsValid;
        }

        #region INotifyOnLanguageChange Members

        public void OnLanguagechanged(Languages currentLanguage)
        {
            language = currentLanguage;
        }

        #endregion
    }
}
