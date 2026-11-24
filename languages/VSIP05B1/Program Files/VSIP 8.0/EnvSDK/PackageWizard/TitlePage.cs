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
using System.Windows.Forms;

namespace PackageWizard
{
    /// <summary>
    /// Summary description for TitlePage.
    /// </summary>
    public class TitlePage : System.Windows.Forms.Form
    {
        public EnvDTE.DTE DTE;
        private Point finalLocation;
        private string helpKey;

        #region WinForm fields
        private System.Windows.Forms.Label descriptionLabel;
        private System.Windows.Forms.Label captionLabel;
        private System.Windows.Forms.Panel panel1;

        private System.Windows.Forms.Button nextButton;
        private System.Windows.Forms.Button backButton;
        private System.Windows.Forms.Button helpButton;
        private System.Windows.Forms.Button finishButton;
        private System.Windows.Forms.Button cancelButton;

        #endregion
        private System.Windows.Forms.PictureBox pictureBox1;
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        public TitlePage()
        {
            DTE = null;
            //
            // Required for Windows Form Designer support
            //
            InitializeComponent();

            helpKey = "";
        }

        public TitlePage(EnvDTE.DTE dte)
        {
            DTE = dte;
            //
            // Required for Windows Form Designer support
            //
            InitializeComponent();
            helpKey = "";
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
            System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(TitlePage));
            this.nextButton = new System.Windows.Forms.Button();
            this.backButton = new System.Windows.Forms.Button();
            this.helpButton = new System.Windows.Forms.Button();
            this.finishButton = new System.Windows.Forms.Button();
            this.cancelButton = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.descriptionLabel = new System.Windows.Forms.Label();
            this.captionLabel = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // nextButton
            // 
            this.nextButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.nextButton.DialogResult = System.Windows.Forms.DialogResult.OK;
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
            this.backButton.DialogResult = System.Windows.Forms.DialogResult.No;
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
            this.finishButton.DialogResult = System.Windows.Forms.DialogResult.Yes;
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
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
                | System.Windows.Forms.AnchorStyles.Left) 
                | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.BackColor = System.Drawing.Color.White;
            this.panel1.Controls.Add(this.descriptionLabel);
            this.panel1.Controls.Add(this.captionLabel);
            this.panel1.Location = new System.Drawing.Point(160, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(328, 297);
            this.panel1.TabIndex = 6;
            // 
            // descriptionLabel
            // 
            this.descriptionLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
                | System.Windows.Forms.AnchorStyles.Right)));
            this.descriptionLabel.BackColor = System.Drawing.Color.White;
            this.descriptionLabel.Location = new System.Drawing.Point(11, 72);
            this.descriptionLabel.Name = "descriptionLabel";
            this.descriptionLabel.Size = new System.Drawing.Size(302, 216);
            this.descriptionLabel.TabIndex = 1;
            // 
            // captionLabel
            // 
            this.captionLabel.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
                | System.Windows.Forms.AnchorStyles.Right)));
            this.captionLabel.BackColor = System.Drawing.Color.White;
            this.captionLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
            this.captionLabel.Location = new System.Drawing.Point(9, 10);
            this.captionLabel.Name = "captionLabel";
            this.captionLabel.Size = new System.Drawing.Size(304, 46);
            this.captionLabel.TabIndex = 0;
            this.captionLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
                | System.Windows.Forms.AnchorStyles.Left)));
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(0, 0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(160, 297);
            this.pictureBox1.TabIndex = 9;
            this.pictureBox1.TabStop = false;
            // 
            // TitlePage
            // 
            this.AcceptButton = this.nextButton;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 14);
            this.CancelButton = this.cancelButton;
            this.ClientSize = new System.Drawing.Size(494, 342);
            this.ControlBox = false;
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.finishButton);
            this.Controls.Add(this.helpButton);
            this.Controls.Add(this.backButton);
            this.Controls.Add(this.nextButton);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "TitlePage";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Package Wizard";
            this.Load += new System.EventHandler(this.TitlePage_Load);
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }
        #endregion

        /// <summary>
        /// Set the string displayed in the window title bar
        /// </summary>
        public string WindowTitle
        {
            set
            {
                this.Text = value;
            }
        }
        /// <summary>
        /// Set the string displayed in large font welcoming people to the wizard
        /// </summary>
        public string Title
        {
            set
            {
                this.captionLabel.Text = value;
            }
        }
        /// <summary>
        /// Set the detailed description of the wizard
        /// </summary>
        public string DetailedDescription
        {
            set
            {
                this.descriptionLabel.Text = value;
            }
        }

        public string HelpKey
        {
            set
            {
                helpKey = value;
            }
        }

        private void finishButton_Click(object sender, System.EventArgs e)
        {
            finalLocation = this.Location;
            this.Close();
        }

        private void nextButton_Click(object sender, System.EventArgs e)
        {
            finalLocation = this.Location;
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Close();
        }

        private void backButton_Click(object sender, System.EventArgs e)
        {
            this.Close();
        }

        private void cancelButton_Click(object sender, System.EventArgs e)
        {
            this.Close();
        }

        /// <summary>
        /// Invoke help for the currently displayed page
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void helpButton_Click(object sender, System.EventArgs e)
        {
            if (DTE != null)
            {
                Microsoft.VisualStudio.VSHelp.Help help = (Microsoft.VisualStudio.VSHelp.Help)DTE.GetObject("Help");
                help.DisplayTopicFromF1Keyword(helpKey);
            }
            else
            {
                Debug.Fail("DTE is null, have you used the wrong constructor?");
            }
        }

        private void TitlePage_Load(object sender, System.EventArgs e)
        {
            // The "Finish" button can't be used when the welcome page is displayed
            finishButton.Enabled = false;
        }

        public Point FinalLocation
        {
            get
            {
                return finalLocation;
            }
        }
    }
}
