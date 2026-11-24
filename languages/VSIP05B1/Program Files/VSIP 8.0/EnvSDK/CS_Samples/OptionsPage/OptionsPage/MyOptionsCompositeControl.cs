using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Windows.Forms;
using System.Drawing;

namespace Microsoft.VisualStudio.VSIP.Samples.OptionsPage
{
	/// <summary>
	/// Summary description for MyOptionsCompositeControl.
	/// </summary>
	public class MyOptionsCompositeControl : System.Windows.Forms.UserControl
	{
		private System.Windows.Forms.PictureBox pictureBox1;
		private System.Windows.Forms.OpenFileDialog openFileDialog1;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button button2;

		private OptionsPageCustom _customPage;

		/// <summary> 
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public MyOptionsCompositeControl()
		{
			// This call is required by the Windows.Forms Form Designer.
			InitializeComponent();

			// TODO: Add any initialization after the InitializeComponent call

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
			this.pictureBox1 = new System.Windows.Forms.PictureBox();
			this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
			this.button1 = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
			this.SuspendLayout();
// 
// pictureBox1
// 
			this.pictureBox1.Location = new System.Drawing.Point(16, 16);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(264, 120);
			this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
			this.pictureBox1.TabIndex = 0;
			this.pictureBox1.TabStop = false;
// 
// button1
// 
			this.button1.Location = new System.Drawing.Point(16, 152);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(112, 23);
			this.button1.TabIndex = 1;
			this.button1.Text = "Choose &Image...";
			this.button1.Click += new System.EventHandler(this.button1_Click);
// 
// button2
// 
			this.button2.Location = new System.Drawing.Point(160, 152);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(96, 23);
			this.button2.TabIndex = 2;
			this.button2.Text = "&Clear Image";
			this.button2.Click += new System.EventHandler(this.button2_Click);
// 
// MyOptionsCompositeControl
// 
			this.AllowDrop = true;
			this.Controls.Add(this.button2);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.pictureBox1);
			this.Name = "MyOptionsCompositeControl";
			this.Size = new System.Drawing.Size(292, 195);
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
			this.ResumeLayout(false);

		}
		#endregion

		private void button1_Click(object sender, System.EventArgs e)
		{
			if (DialogResult.OK == openFileDialog1.ShowDialog())
			{
				_customPage.CustomBitmap = openFileDialog1.FileName;
				RefreshImage();
			}
		}

		private void button2_Click(object sender, System.EventArgs e)
		{
			_customPage.CustomBitmap = null;
			RefreshImage();
		}

		private void RefreshImage()
		{
			if (_customPage == null) return;

			string fileName = _customPage.CustomBitmap;
			if (fileName != null && fileName.Length != 0)
				pictureBox1.Image = Image.FromFile(fileName);
			else
				pictureBox1.Image = null;
		}

		public OptionsPageCustom OptionsPage
		{
			set
			{
				_customPage = value;
				RefreshImage();
			}
		}
	}

}
