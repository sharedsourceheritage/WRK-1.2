using System;
using System.ComponentModel;
using System.Collections;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using MSVSIP = Microsoft.VisualStudio.Shell;

namespace Microsoft.VisualStudio.VSIP.Samples.OptionsPage
{
	/// <summary>
	/// Summary description for OptionsPageGeneral.
	/// </summary>
	/// 
	[Guid("E6717D0B-111E-4a5b-9834-076CA319ED59")]
	public class OptionsPageGeneral : MSVSIP.DialogPage
	{
	
		/// <summary>
		///     The property that you want to be show in the options page.
		/// </summary>
		[Category("String Options")]
		[Description("My string option")]
		public string OptionString
		{
			get 
			{
				return _optionString;
			}
			set
			{
				_optionString = value;
			}
		}	

		/// <summary>
		///     The property that you want to be show in the options page.
		/// </summary>
		[Category("Integer Options")]
		[Description("My integer option")]
		public int OptionInteger
		{
			get 
			{
				return _optionInt;
			}
			set
			{
				_optionInt = value;
			}
		}	

		/// <summary>
		///     The custom property that you want to be show in the options page.
		/// </summary>
		[Category("Expandable Options")]
		[Description("My Expandable option")]
		public Size CustomSize
		{
			get 
			{
				return _optionCustSize;
			}
			set
			{
				_optionCustSize = value;
			}
		}	

		private string	_optionString = "Hello World";
		private int	_optionInt = 567;
		private Size _optionCustSize = new Size(50, 50);

		/// <include file='doc\DialogPage.uex' path='docs/doc[@for="DialogPage.OnActivate"]' />
		/// <devdoc>
		///     This method is called when VS wants to activate this
		///     page.  If the Cancel property of the event is set to true, the page is not activated.
		/// </devdoc>
		protected override void OnActivate(CancelEventArgs e)
		{
			Trace.WriteLine(string.Format("In OnActivate"));
			DialogResult res = MessageBox.Show("Press Cancel to cancel this activation.  OK to continue", "OnActivate", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
			if (res == DialogResult.Cancel)
			{
				Trace.WriteLine(string.Format("Cancelled the OnActivate event"));
				e.Cancel = true;
			}
		}

		/// <include file='doc\DialogPage.uex' path='docs/doc[@for="DialogPage.OnClosed"]' />
		/// <devdoc>
		///     This event is raised when the page is closed.   
		/// </devdoc>
		protected override void OnClosed(EventArgs e)
		{
			Trace.WriteLine(string.Format("In OnClosed"));
		}

		/// <include file='doc\DialogPage.uex' path='docs/doc[@for="DialogPage.OnDeactivate"]' />
		/// <devdoc>
		///     This method is called when VS wants to deatviate this
		///     page.  If true is set for the Cancel property of the event, 
		///     the page is not deactivated.
		/// </devdoc>
		protected override void OnDeactivate(CancelEventArgs e)
		{
			Trace.WriteLine(string.Format("In OnDeactivate"));
			DialogResult res = MessageBox.Show("Press Cancel to cancel this deactivation.  OK to continue", "OnDeactivate", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
			if (res == DialogResult.Cancel)
			{
				Trace.WriteLine(string.Format("Cancelled the OnDeactivate event"));
				e.Cancel = true;
			}
		}

		/// <include file='doc\DialogPage.uex' path='docs/doc[@for="DialogPage.OnApply"]' />
		/// <devdoc>
		///     This method is called when VS wants to save the user's 
		///     changes then the dialog is dismissed.
		/// </devdoc>
		protected override void OnApply(PageApplyEventArgs e)
		{
			Trace.WriteLine(string.Format("In OnApply"));
			DialogResult res = MessageBox.Show("Press Cancel to cancel this OnApply.  OK to continue", "OnApply", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
			if (res == DialogResult.Cancel)
			{
				Trace.WriteLine(string.Format("Cancelled the OnApply event"));
				e.ApplyBehavior = ApplyKind.Cancel;
			}
			else
			{
				base.OnApply(e);
			}
		}


	}
}
