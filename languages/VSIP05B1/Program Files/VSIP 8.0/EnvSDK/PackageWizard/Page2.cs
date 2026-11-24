//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Text;
using System.Runtime.InteropServices;

namespace PackageWizard
{
    /// <summary>
    /// Summary description for Page2.
    /// </summary>
    [System.Runtime.InteropServices.ComVisible(false)]
    public class Page2 : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage
    {
        private System.Windows.Forms.TextBox companyName;
        private System.Windows.Forms.TextBox packageName;
        private System.Windows.Forms.TextBox packageVersion;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.PictureBox iconPictureBox;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox detailedInfo;

        private EnvDTE.DTE DTE;
        private IconWrapper icon;
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        public Page2()
        {
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();

            // The designer complain if this is done from InitializeComponent()
            this.comboBox1.SelectedText = this.comboBox1.Items[0].ToString();

            // Set focus on the control we want to start on
            this.companyName.Focus();
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
            this.companyName = new System.Windows.Forms.TextBox();
            this.packageName = new System.Windows.Forms.TextBox();
            this.packageVersion = new System.Windows.Forms.TextBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.detailedInfo = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.iconPictureBox = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // companyName
            // 
            this.companyName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
                | System.Windows.Forms.AnchorStyles.Right)));
            this.companyName.Location = new System.Drawing.Point(280, 8);
            this.companyName.Name = "companyName";
            this.companyName.Size = new System.Drawing.Size(201, 20);
            this.companyName.TabIndex = 1;
            this.companyName.Text = "Company";
            // 
            // packageName
            // 
            this.packageName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
                | System.Windows.Forms.AnchorStyles.Right)));
            this.packageName.Location = new System.Drawing.Point(280, 40);
            this.packageName.Name = "packageName";
            this.packageName.Size = new System.Drawing.Size(201, 20);
            this.packageName.TabIndex = 2;
            this.packageName.Text = "Package Name";
            // 
            // packageVersion
            // 
            this.packageVersion.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
                | System.Windows.Forms.AnchorStyles.Right)));
            this.packageVersion.Location = new System.Drawing.Point(280, 72);
            this.packageVersion.Name = "packageVersion";
            this.packageVersion.Size = new System.Drawing.Size(201, 20);
            this.packageVersion.TabIndex = 3;
            this.packageVersion.Text = "1.0";
            // 
            // comboBox1
            // 
            this.comboBox1.Items.AddRange(new object[] {
                                                           "Standard",
                                                           "Professional",
                                                           "Enterprise Developer",
                                                           "Enterprise Architect"});
            this.comboBox1.Location = new System.Drawing.Point(320, 104);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(163, 21);
            this.comboBox1.TabIndex = 4;
            // 
            // detailedInfo
            // 
            this.detailedInfo.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
                | System.Windows.Forms.AnchorStyles.Left) 
                | System.Windows.Forms.AnchorStyles.Right)));
            this.detailedInfo.Location = new System.Drawing.Point(128, 142);
            this.detailedInfo.Multiline = true;
            this.detailedInfo.Name = "detailedInfo";
            this.detailedInfo.Size = new System.Drawing.Size(353, 69);
            this.detailedInfo.TabIndex = 5;
            this.detailedInfo.Text = "Information about my package";
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(128, 8);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(144, 23);
            this.label1.TabIndex = 6;
            this.label1.Text = "Company Name:";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(128, 40);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(144, 23);
            this.label2.TabIndex = 7;
            this.label2.Text = "VSPackage Name:";
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(128, 72);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(144, 23);
            this.label3.TabIndex = 8;
            this.label3.Text = "VSPackage Version:";
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(128, 104);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(176, 23);
            this.label4.TabIndex = 9;
            this.label4.Text = "Minimum Visual Studio Edition:";
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(16, 144);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(104, 23);
            this.label5.TabIndex = 10;
            this.label5.Text = "Detailed Info:";
            // 
            // iconPictureBox
            // 
            this.iconPictureBox.Location = new System.Drawing.Point(48, 16);
            this.iconPictureBox.Name = "iconPictureBox";
            this.iconPictureBox.Size = new System.Drawing.Size(32, 32);
            this.iconPictureBox.TabIndex = 11;
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
            // Page2
            // 
            this.Controls.Add(this.button1);
            this.Controls.Add(this.iconPictureBox);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.detailedInfo);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.packageVersion);
            this.Controls.Add(this.packageName);
            this.Controls.Add(this.companyName);
            this.Name = "Page2";
            this.Size = new System.Drawing.Size(499, 221);
            this.ResumeLayout(false);

        }
        #endregion

        public void Initialize(WizardLibrary.WizardLibrary baseWizard)
        {
            DTE = baseWizard.application;

            // Load our default icon
            string iconPath = System.IO.Path.Combine(baseWizard.WizardTemplatesDir, "Package.ico");
            icon = new IconWrapper(iconPath, this);
            iconPictureBox.Image = icon.Icon.ToBitmap();
        }

        public void PerformWork1(WizardLibrary.WizardLibrary baseWizard)
        {
            // Add tokens and their replacement strings to the token processor
            TokenProcessor processor = (TokenProcessor)baseWizard.customData["TokenProcessor"];
            processor.AddReplace("%CompanyName%", companyName.Text, TokenReplaceType.ReplaceString);
            processor.AddReplace("%PackageName%", packageName.Text, TokenReplaceType.ReplaceString);
            processor.AddReplace("%PackageVersion%", packageVersion.Text, TokenReplaceType.ReplaceString);
            processor.AddReplace("%MinVsEdition%", comboBox1.Text, TokenReplaceType.ReplaceString);
            processor.AddReplace("%DetailedInfo%", detailedInfo.Text, TokenReplaceType.ReplaceString);
        }

        public void PerformWork2(WizardLibrary.WizardLibrary  baseWizard)
        {
            // Add icon file to the Ui project
            EnvDTE.Project uiProject = (EnvDTE.Project)baseWizard.customData["UiProject"];
            uiProject.ProjectItems.AddFromTemplate(icon.IconPath, "Package.ico");
        }

        public void ShowHelp()
        {
        }

        private void button1_Click(object sender, System.EventArgs e)
        {
            icon.PickNewIcon();
            iconPictureBox.Image = icon.Icon.ToBitmap();
        }

        public string HeadingLabel
        {
            get 
            {
                return "Basic VSPackage Information";
            }
        }
        public string DescriptionLabel
        {
            get 
            {
                return "Provide the basic information about your VSPackage.";
            }
        }
        public string HelpKeyword
        {
            get 
            {
                return "vs.vsip.VSPackageWizard.basicPkgInfo";
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
            bool pageIsValid = companyName.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                companyName.Focus();
                MessageBox.Show(this, "You must specify a company name.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            pageIsValid = packageName.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                packageName.Focus();
                MessageBox.Show(this, "You must specify a package name.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            pageIsValid = packageVersion.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                packageVersion.Focus();
                MessageBox.Show(this, "You must specify a package version.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            pageIsValid = detailedInfo.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                detailedInfo.Focus();
                MessageBox.Show(this, "You must specify a detailed description.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            return pageIsValid;
        }
    }
}
