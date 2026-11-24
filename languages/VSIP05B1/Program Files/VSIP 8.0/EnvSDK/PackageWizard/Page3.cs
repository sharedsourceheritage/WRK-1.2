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
    public enum PackageOptions
    {
        none            = 0,
        MenuItem        = 1,
        ToolWindow        = 2,
        Editor            = 4
    };

    /// <summary>
    /// Summary description for Page3.
    /// </summary>
    [System.Runtime.InteropServices.ComVisible(false)]
    public class Page3 : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage, WizardLibrary.ICanDisablePages
    {
        private System.Windows.Forms.CheckBox MenuItem;
        private System.Windows.Forms.CheckBox ToolWindow;
        private System.Windows.Forms.CheckBox Editor;
        private WizardLibrary.IUpdateNextButton nextButton;

        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        // This constructor should only be called by the designer
        public Page3()
        {
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();

            nextButton = null;
        }

        public Page3(WizardLibrary.IUpdateNextButton parentWindow)
        {
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();

            nextButton = parentWindow;
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
            this.MenuItem = new System.Windows.Forms.CheckBox();
            this.ToolWindow = new System.Windows.Forms.CheckBox();
            this.Editor = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // MenuItem
            // 
            this.MenuItem.Location = new System.Drawing.Point(12, 12);
            this.MenuItem.Name = "MenuItem";
            this.MenuItem.Size = new System.Drawing.Size(468, 24);
            this.MenuItem.TabIndex = 0;
            this.MenuItem.Text = "Menu Command";
            this.MenuItem.CheckedChanged += new System.EventHandler(this.MenuItem_CheckedChanged);
            // 
            // ToolWindow
            // 
            this.ToolWindow.Location = new System.Drawing.Point(12, 48);
            this.ToolWindow.Name = "ToolWindow";
            this.ToolWindow.Size = new System.Drawing.Size(468, 24);
            this.ToolWindow.TabIndex = 1;
            this.ToolWindow.Text = "Tool Window";
            this.ToolWindow.CheckedChanged += new System.EventHandler(this.ToolWindow_CheckedChanged);
            // 
            // Editor
            // 
            this.Editor.Location = new System.Drawing.Point(12, 84);
            this.Editor.Name = "Editor";
            this.Editor.Size = new System.Drawing.Size(468, 24);
            this.Editor.TabIndex = 2;
            this.Editor.Text = "Custom Editor";
            this.Editor.CheckedChanged += new System.EventHandler(this.Editor_CheckedChanged);
            // 
            // Page3
            // 
            this.Controls.Add(this.Editor);
            this.Controls.Add(this.ToolWindow);
            this.Controls.Add(this.MenuItem);
            this.Name = "Page3";
            this.Size = new System.Drawing.Size(496, 220);
            this.ResumeLayout(false);

        }
        #endregion

        public void Initialize(WizardLibrary.WizardLibrary baseWizard)
        {
        }

        public void PerformWork1(WizardLibrary.WizardLibrary baseWizard)
        {
            // Create option flags
            PackageOptions options = PackageOptions.none;
            if (MenuItem.Checked)
                options |= PackageOptions.MenuItem;
            if (ToolWindow.Checked)
                options |= PackageOptions.ToolWindow;
            if (Editor.Checked)
                options |= PackageOptions.Editor;

            // Add options to the Data
            baseWizard.customData.Add("PackageOptions", options);
        }

        public void PerformWork2(WizardLibrary.WizardLibrary  baseWizard)
        {
        }

        public void ShowHelp()
        {
        }

        private void MenuItem_CheckedChanged(object sender, System.EventArgs e)
        {
            if (nextButton != null)
                nextButton.UpdateNextButton();
            else
                Debug.Fail("nextButton should NOT be null, did you use the wrong constructor?");
        }

        private void ToolWindow_CheckedChanged(object sender, System.EventArgs e)
        {
            if (nextButton != null)
                nextButton.UpdateNextButton();
            else
                Debug.Fail("nextButton should NOT be null, did you use the wrong constructor?");
        }

        private void Editor_CheckedChanged(object sender, System.EventArgs e)
        {
            if (nextButton != null)
                nextButton.UpdateNextButton();
            else
                Debug.Fail("nextButton should NOT be null, did you use the wrong constructor?");
        }

        public string HeadingLabel
        {
            get 
            {
                return "Select VSPackage Options";
            }
        }
        public string DescriptionLabel
        {
            get 
            {
                return "Select any additional functionality to include in your VSPackage.";
            }
        }
        public string HelpKeyword
        {
            get 
            {
                return "vs.vsip.VSPackageWizard.pkgOptions";
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
            // this page is always valid
            return true;
        }

        #region ICanDisablePage Members

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
        public void SetEnabledPages(bool[] pageStatus, int size, int currentPage)
        {
            // make sure size include all expected pages
            if (size <= currentPage + 3)
            {
                Debug.Fail("The wizard is missing some expected pages");
                // Do not disable anything
                return;
            }

            // For each check box, enable/disable the corresponding page
            pageStatus[currentPage+1] = MenuItem.Checked;
            pageStatus[currentPage+2] = ToolWindow.Checked;
            pageStatus[currentPage+3] = Editor.Checked;
        }

        #endregion

    }
}
