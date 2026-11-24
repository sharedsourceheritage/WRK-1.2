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
    /// <summary>
    /// Summary description for Page5.
    /// </summary>
    [System.Runtime.InteropServices.ComVisible(false)]
    public class Page5 : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage
    {
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox windowName;
        private System.Windows.Forms.TextBox toolCommandID;
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        public Page5()
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
            this.windowName = new System.Windows.Forms.TextBox();
            this.toolCommandID = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // windowName
            // 
            this.windowName.Location = new System.Drawing.Point(176, 12);
            this.windowName.MaxLength = 128;
            this.windowName.Name = "windowName";
            this.windowName.Size = new System.Drawing.Size(296, 24);
            this.windowName.TabIndex = 0;
            this.windowName.Text = "My Tool Window";
            // 
            // toolCommandID
            // 
            this.toolCommandID.Location = new System.Drawing.Point(176, 48);
            this.toolCommandID.MaxLength = 128;
            this.toolCommandID.Name = "toolCommandID";
            this.toolCommandID.Size = new System.Drawing.Size(296, 24);
            this.toolCommandID.TabIndex = 1;
            this.toolCommandID.Text = "cmdidMyTool";
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(12, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(156, 23);
            this.label1.TabIndex = 3;
            this.label1.Text = "Window Name:";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(12, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(156, 23);
            this.label2.TabIndex = 4;
            this.label2.Text = "Command ID:";
            // 
            // Page5
            // 
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.toolCommandID);
            this.Controls.Add(this.windowName);
            this.Name = "Page5";
            this.Size = new System.Drawing.Size(496, 220);
            this.ResumeLayout(false);

        }
        #endregion

        public void Initialize(WizardLibrary.WizardLibrary baseWizard)
        {
        }

        public void PerformWork1(WizardLibrary.WizardLibrary baseWizard)
        {
            TokenProcessor processor = (TokenProcessor)baseWizard.customData["TokenProcessor"];
            PackageOptions options = (PackageOptions)baseWizard.customData["PackageOptions"];
            if ((options & PackageOptions.ToolWindow) != PackageOptions.none)
            {
                // A toolwindow was requested
                processor.AddReplace("%ToolWindowName%", windowName.Text, TokenReplaceType.ReplaceString);
                processor.AddReplace("%ToolCommandID%", toolCommandID.Text, TokenReplaceType.ReplaceCode);
                Guid toolGuid = Guid.NewGuid();
                processor.AddReplace("%ToolGuid%", toolGuid.ToString(), TokenReplaceType.ReplaceString);
                processor.AddReplace("%ToolGuid1%", processor.GuidToForm1(toolGuid), TokenReplaceType.ReplaceString);
                processor.AddDelete("%NotToolWindowItemStart%", "%NotToolWindowItemEnd%");
                // Deletion tag must be replaced by nothing
                processor.AddReplace("%ToolWindowItemStart%", "", TokenReplaceType.ReplaceString);
                processor.AddReplace("%ToolWindowItemEnd%", "", TokenReplaceType.ReplaceString);

                // Add file name for the tool window
                StringBuilder fileName = new StringBuilder(windowName.Text);
                fileName.Replace("/","");
                fileName.Replace("\\","");
                fileName.Replace("?","");
                fileName.Replace("*","");
                fileName.Replace("<","");
                fileName.Replace(">","");
                fileName.Replace("|","");
                fileName.Replace("\"","");
                fileName.Replace(":","");
                string cleanFileName = fileName.ToString().Trim();
                if (cleanFileName.Length <= 0)
                    cleanFileName = "MyToolWindow";
                baseWizard.customData.Add("ToolWindowFileName", cleanFileName);
            }
            else
            {
                // No toolwindow requested
                processor.AddReplace("%NotToolWindowItemStart%", "", TokenReplaceType.ReplaceString);
                processor.AddReplace("%NotToolWindowItemEnd%", "", TokenReplaceType.ReplaceString);
                processor.AddDelete("%ToolWindowItemStart%", "%ToolWindowItemEnd%");
            }
        }

        public void PerformWork2(WizardLibrary.WizardLibrary  baseWizard)
        {
        }

        public void ShowHelp()
        {
        }

        public string HeadingLabel
        {
            get 
            {
                return "Tool Window Options";
            }
        }
        public string DescriptionLabel
        {
            get 
            {
                return "Provide information for your tool window. A command to open your window will be added to the Other Windows submenu of the View menu.";
            }
        }
        public string HelpKeyword
        {
            get 
            {
                return "vs.vsip.VSPackageWizard.toolOptions";
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
            bool pageIsValid = windowName.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                windowName.Focus();
                MessageBox.Show(this, "You must specify a Window name.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            for(int i=0; pageIsValid && i<windowName.TextLength; ++i)
                pageIsValid &= char.IsLetterOrDigit(windowName.Text, i) || char.IsWhiteSpace(windowName.Text, i);
            if (!pageIsValid)
            {
                windowName.Focus();
                MessageBox.Show(this, "Window name can only contain letters, digits and spaces.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            pageIsValid = toolCommandID.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                toolCommandID.Focus();
                MessageBox.Show(this, "You must specify a command ID.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            pageIsValid &= char.IsLetter(toolCommandID.Text, 0);
            for(int i=0; pageIsValid && i<toolCommandID.TextLength; ++i)
                pageIsValid &= char.IsLetterOrDigit(toolCommandID.Text, i);
            if (!pageIsValid)
            {
                toolCommandID.Focus();
                MessageBox.Show(this, "Command ID must start with a letter and can only contain letters and digits.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            return pageIsValid;
        }
    }
}
