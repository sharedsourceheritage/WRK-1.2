using System;
using System.ComponentModel;
using System.Collections;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using MSVSIP = Microsoft.VisualStudio.Shell;

namespace Microsoft.VisualStudio.VSIP.Samples.OptionsPage
{
	/// <summary>
	/// Summary description for OptionsPageCustom.
	/// </summary>
	/// 
	[Guid("0A9F3920-3881-4f50-8986-9EDEC7B33566")]
	public class OptionsPageCustom : MSVSIP.DialogPage
	{
		private string _imageFile;

		/// <include file='doc\DialogPage.uex' path='docs/doc[@for="DialogPage".Window]' />
		/// <devdoc>
		///     The window this dialog page will use for its UI.
		///     This window handle must be constant, so if you are
		///     returning a Windows Forms control you must make sure
		///     it does not recreate its handle.  If the window object
		///     implements IComponent it will be sited by the 
		///     dialog page so it can get access to global services.
		/// </devdoc>
		[Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
		protected override IWin32Window Window
		{
			get
			{
				MyOptionsCompositeControl page = new MyOptionsCompositeControl();
				page.Location = new Point(0, 0);
				page.OptionsPage = this;
				return page;
			}
		}

		/// <summary>
		///     The property that needs to be persisted.
		/// </summary>
		[DesignerSerializationVisibility(DesignerSerializationVisibility.Visible)]
		public string CustomBitmap
		{
			get 
			{
				return _imageFile;
			}
			set
			{
				_imageFile = value;
			}
		}
	}
}
