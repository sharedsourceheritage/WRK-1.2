//-------------------------------------------------------------------------
//
//  This is part of the Microsoft Tablet PC Platform SDK
//  Copyright (C) 2004 Microsoft Corporation
//  All rights reserved.
//
//  This source code is only intended as a supplement to the
//  Microsoft Tablet PC Platform SDK Reference and related electronic 
//  documentation provided with the Software Development Kit.
//  See these sources for more detailed information. 
//
//  File: Default.aspx.cs
//  ASP.NET code behind page that displays a list of all blog entries 
//  collected on the server. 
//
//--------------------------------------------------------------------------


using System;
using System.IO;
using System.Web.UI;

namespace InkBlog
{
    /// <summary>
    /// The Default code-behind page.
    /// </summary>
    public class _Default : Page
    {
    
        /// <summary>
        /// Handles the Load event for this Page.
        /// 
        /// Displays a web page with a list of all blog entries collected on the
        /// server.  It also contains a button that allows the user to add 
        /// more blog entries using AddBlog.aspx.  
        /// </summary>
        /// <param name="sender">The object that raised the event.</param>
        /// <param name="e">The event arguments.</param>
        private void Page_Load(object sender, System.EventArgs e)
        {

            // Display a button that allows the user to add more blog entries 
            Response.Write("<hr><a href=\"AddBlog.aspx\">Add Blog</a><br><hr>");

            string path = Server.MapPath("Blogs");            
            DirectoryInfo dirInfo = new DirectoryInfo(path);
            
            // Output the content of each page in the server's blog directory.
            if (dirInfo.Exists)
            {
                foreach (FileInfo file in dirInfo.GetFiles("*.htm")) 
                {
                    using (StreamReader sr = file.OpenText())
                    {
                        Response.Write(sr.ReadToEnd());
                    }
                }
            }
        }

        #region Web Form Designer generated code
        override protected void OnInit(EventArgs e)
        {
            //
            // CODEGEN: This call is required by the ASP.NET Web Form Designer.
            //
            InitializeComponent();
            base.OnInit(e);
        }
        
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {    
            this.Load += new System.EventHandler(this.Page_Load);

        }
        #endregion

    }
}
