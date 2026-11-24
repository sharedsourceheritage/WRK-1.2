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

namespace PackageWizard
{
    /// <summary>
    /// Summary description for Page4.
    /// </summary>
    [System.Runtime.InteropServices.ComVisible(false)]
    public class Page4 : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage
    {
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox commandName;
        private System.Windows.Forms.TextBox commandId;
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        public Page4()
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
            this.commandName = new System.Windows.Forms.TextBox();
            this.commandId = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // commandName
            // 
            this.commandName.Location = new System.Drawing.Point(176, 12);
            this.commandName.MaxLength = 128;
            this.commandName.Name = "commandName";
            this.commandName.Size = new System.Drawing.Size(296, 24);
            this.commandName.TabIndex = 0;
            this.commandName.Text = "My Command Name";
            // 
            // commandId
            // 
            this.commandId.Location = new System.Drawing.Point(176, 48);
            this.commandId.MaxLength = 128;
            this.commandId.Name = "commandId";
            this.commandId.Size = new System.Drawing.Size(296, 24);
            this.commandId.TabIndex = 1;
            this.commandId.Text = "cmdidMyCommand";
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(12, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(156, 23);
            this.label1.TabIndex = 3;
            this.label1.Text = "Command Name:";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(12, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(156, 23);
            this.label2.TabIndex = 4;
            this.label2.Text = "Command ID:";
            // 
            // Page4
            // 
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.commandId);
            this.Controls.Add(this.commandName);
            this.Name = "Page4";
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
            if ((options & PackageOptions.MenuItem) != PackageOptions.none)
            {
                // A menuitem was requested
                processor.AddReplace("%CommandName%", commandName.Text, TokenReplaceType.ReplaceString);
                processor.AddReplace("%CommandID%", commandId.Text, TokenReplaceType.ReplaceCode);
                // Deletion tag must be replaced by nothing
                processor.AddReplace("%MenuItemStart%", "", TokenReplaceType.ReplaceCode);
                processor.AddReplace("%MenuItemEnd%", "", TokenReplaceType.ReplaceCode);
            }
            else
            {
                // No menuitem requested
                processor.AddDelete("%MenuItemStart%", "%MenuItemEnd%");
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
                return "Command Options";
            }
        }
        public string DescriptionLabel
        {
            get 
            {
                return "Provide information for your first menu command. This command will be added to the Tools menu.";
            }
        }
        public string HelpKeyword
        {
            get 
            {
                return "vs.vsip.VSPackageWizard.cmdOptions";
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
            bool pageIsValid = commandName.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                commandName.Focus();
                MessageBox.Show(this, "You must specify a command name.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            for(int i=0; pageIsValid && i<commandName.TextLength; ++i)
                pageIsValid &= char.IsLetterOrDigit(commandName.Text, i) || char.IsWhiteSpace(commandName.Text, i);
            if (!pageIsValid)
            {
                commandName.Focus();
                MessageBox.Show(this, "Command name can only contain letters, digits and spaces.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            pageIsValid = commandId.Text.Trim().Length > 0;
            if (!pageIsValid)
            {
                commandId.Focus();
                MessageBox.Show(this, "You must specify a command ID.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            pageIsValid &= char.IsLetter(commandId.Text, 0);
            for(int i=0; pageIsValid && i<commandId.TextLength; ++i)
                pageIsValid &= char.IsLetterOrDigit(commandId.Text, i);
            if (!pageIsValid)
            {
                commandId.Focus();
                MessageBox.Show(this, "Command ID must start with a letter and can only contain letters and digits.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return pageIsValid;
            }
            return pageIsValid;
        }
    }
}
