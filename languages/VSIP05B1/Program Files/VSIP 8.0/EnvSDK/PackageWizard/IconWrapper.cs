//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Globalization;
using System.Text;
using System.Runtime.InteropServices;
using System.Drawing;
using System.Windows.Forms;

namespace PackageWizard
{
    /// <summary>
    /// Summary description for IconWrapper.
    /// </summary>
    public class IconWrapper
    {
        private string iconPath;
        private Icon icon;
        private Control parentWindow;

        /// <summary>
        /// Create an object to pick, load, and copy an ico file
        /// </summary>
        /// <param name="path">Path to an .ico file</param>
        public IconWrapper(string path, Control parent)
        {
            if (path == null)
                throw new ArgumentNullException("path");
            string ext = System.IO.Path.GetExtension(path);
            if (0 != string.Compare(ext, ".ico", true, CultureInfo.CurrentCulture))
                throw new ArgumentException("path must refer to an .ico file");

            // Load the icon and remember the path
            icon = new Icon(path);
            iconPath = path;
            parentWindow = parent;
        }

        #region Accessors
        /// <summary>
        /// Get the System.Drawing.Icon
        /// </summary>
        public Icon Icon
        {
            get
            {
                return icon;
            }
        }
        /// <summary>
        /// Get the path to the current icon
        /// </summary>
        public string IconPath
        {
            get
            {
                return iconPath;
            }
        }
        #endregion

        /// <summary>
        /// Bring up the Icon picker dialog, if the selected icon is a .ico file make it the new icon
        /// </summary>
        public void PickNewIcon()
        {
            // Initialize string buffer
            StringBuilder newIconPath = new StringBuilder(1024);
            newIconPath.Append(iconPath);
            string path = IconPath;
            bool pathChanged = false;

            // Use a file picker to pick the icon file
            OpenFileDialog fileBrowser = new OpenFileDialog();
            fileBrowser.Filter = "Icon files (*.ico)|*.ico";
            fileBrowser.Title = "Select an Icon";
            fileBrowser.ValidateNames = true;
            fileBrowser.Multiselect = false;
            fileBrowser.InitialDirectory = path;
            if (fileBrowser.ShowDialog(parentWindow) == DialogResult.OK)
            {
                path = fileBrowser.FileName;
                pathChanged = true;
            }

            if (pathChanged)
            {
                string ext = System.IO.Path.GetExtension(path);
                // Do some validation
                if (0 == string.Compare(ext, ".ico", true, CultureInfo.CurrentCulture))
                {
                    try
                    {
                        // Load the icon and remember the path (if loading was succesful)
                        icon = new Icon(path);
                        iconPath = path;
                    }
                    catch(ArgumentException e)
                    {
                        System.Diagnostics.Trace.WriteLine(e.Message);
                        MessageBox.Show(parentWindow, "Selected file does not contain a valid icon.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);;
                    }
                }
                else
                {
                    MessageBox.Show(parentWindow, "Only .ico files are supported.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
    }
}
