namespace Microsoft.Samples.SqlServer
{
	public partial class Instructions : System.Windows.Forms.Form
	{
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Instructions));
            this.ProductModelIDLabel = new System.Windows.Forms.Label();
            this.ShowInstructionsButton = new System.Windows.Forms.Button();
            this.ShowRequestButton = new System.Windows.Forms.Button();
            this.ShowResponseButton = new System.Windows.Forms.Button();
            this.ShowXSLButton = new System.Windows.Forms.Button();
            this.webBrowser1 = new System.Windows.Forms.WebBrowser();
            this.ProductModelIDTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // ProductModelIDLabel
            // 
            resources.ApplyResources(this.ProductModelIDLabel, "ProductModelIDLabel");
            this.ProductModelIDLabel.Name = "ProductModelIDLabel";
            // 
            // ShowInstructionsButton
            // 
            resources.ApplyResources(this.ShowInstructionsButton, "ShowInstructionsButton");
            this.ShowInstructionsButton.Margin = new System.Windows.Forms.Padding(3, 3, 1, 3);
            this.ShowInstructionsButton.Name = "ShowInstructionsButton";
            this.ShowInstructionsButton.Click += new System.EventHandler(this.ShowInstructionsButton_Click);
            // 
            // ShowRequestButton
            // 
            resources.ApplyResources(this.ShowRequestButton, "ShowRequestButton");
            this.ShowRequestButton.Margin = new System.Windows.Forms.Padding(0, 3, 3, 3);
            this.ShowRequestButton.Name = "ShowRequestButton";
            this.ShowRequestButton.Click += new System.EventHandler(this.ShowRequestButton_Click);
            // 
            // ShowResponseButton
            // 
            resources.ApplyResources(this.ShowResponseButton, "ShowResponseButton");
            this.ShowResponseButton.Name = "ShowResponseButton";
            this.ShowResponseButton.Click += new System.EventHandler(this.ShowResponseButton_Click);
            // 
            // ShowXSLButton
            // 
            resources.ApplyResources(this.ShowXSLButton, "ShowXSLButton");
            this.ShowXSLButton.Name = "ShowXSLButton";
            this.ShowXSLButton.Click += new System.EventHandler(this.ShowXSLButton_Click);
            // 
            // webBrowser1
            // 
            resources.ApplyResources(this.webBrowser1, "webBrowser1");
            this.webBrowser1.Name = "webBrowser1";
            // 
            // ProductModelIDTextBox
            // 
            resources.ApplyResources(this.ProductModelIDTextBox, "ProductModelIDTextBox");
            this.ProductModelIDTextBox.Name = "ProductModelIDTextBox";
            // 
            // Instructions
            // 
            resources.ApplyResources(this, "$this");
            this.Controls.Add(this.ProductModelIDTextBox);
            this.Controls.Add(this.webBrowser1);
            this.Controls.Add(this.ShowXSLButton);
            this.Controls.Add(this.ShowResponseButton);
            this.Controls.Add(this.ShowRequestButton);
            this.Controls.Add(this.ShowInstructionsButton);
            this.Controls.Add(this.ProductModelIDLabel);
            this.Name = "Instructions";
            this.Padding = new System.Windows.Forms.Padding(9);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose(bool disposing)
		{
			if (disposing)
			{
				if (components != null)
				{
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}

		private System.Windows.Forms.Label ProductModelIDLabel;
		private System.Windows.Forms.Button ShowRequestButton;
		private System.Windows.Forms.Button ShowInstructionsButton;
		private System.Windows.Forms.Button ShowResponseButton;
		private System.Windows.Forms.Button ShowXSLButton;
		private System.Windows.Forms.WebBrowser webBrowser1;
		private System.Windows.Forms.TextBox ProductModelIDTextBox;
	}
}

