namespace DefaultNamespace 
{
    using System;
    using System.Drawing;
    using System.Collections;
    using System.ComponentModel;
    using System.Windows.Forms;

    /*
     * This class can take a variable number of parameters on the command
     * line. Program execution begins with the Main() method. The class
     * constructor is not invoked unless an object of type 'MainForm'
     * created in the Main() method.
     */
    public class MainForm : Form
    {
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

        public MainForm() 
        {
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

            //
            // TODO: Add any constructor code after InitializeComponent call
            //
        }

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if (components != null) 
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

        
        private void FigureDraw(Object source, PaintEventArgs e)
        {   
            //The following line will be replaced by the compiler   
            //This line will be replaced by calls to cs classes. Do not edit this line
        }

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.Size = new System.Drawing.Size(300,300);
			this.Text = "FigForm";
            this.Paint += new PaintEventHandler(FigureDraw);
		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main() 
		{
			Application.Run(new MainForm());
		}
	}
}