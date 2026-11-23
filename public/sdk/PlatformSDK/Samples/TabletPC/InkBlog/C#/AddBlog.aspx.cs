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
//  File: AddBlog.aspx.cs
//  ASP.NET code behind page used for submitting new blog data.
//
//  This class receives the blog data posted by the user to the server
//  and uses it to create a web page that is viewable from Default.aspx.
//  If the client supports inking, this page contains text for the blog 
//  title and ink serialized as GIF for the blog body.  Otherwise, if the 
//  client does not support inking, it will consist of text for both the blog 
//  title and body.  
//
//--------------------------------------------------------------------------

using System;
using System.Collections.Specialized;
using System.IO;
using System.Web.UI;

namespace InkBlog
{
    /// <summary>
    /// The AddBlog code-behind page.
    /// </summary>
    public class AddBlog : Page
    {

        /// <summary>
        /// Handles the Load event for this Page.
        /// 
        /// Retrieves the blog data posted to the server and uses it to
        /// create an HTML page that is viewable from Default.aspx.
        /// If the blog contains ink data, this page will consist of
        /// a GIF containing serialized ink data; otherwise, it will
        /// consist only of text.  
        /// </summary>
        /// <param name="sender">The object that raised the event.</param>
        /// <param name="e">The event arguments.</param>
        private void Page_Load(object sender, System.EventArgs e)
        {
            NameValueCollection form = Request.Form;

            if ( form.Keys.Count > 0 )
            {
                // Determine the location where blog web pages and images are 
                // stored on the server
                string blogPath = Server.MapPath("Blogs/");
                string imagePath = Path.Combine(blogPath,"Images");

                // If this location does not yet exist, create it.
                DirectoryInfo dirInfo = new DirectoryInfo(imagePath);
                if (!dirInfo.Exists)
                {
                    dirInfo.Create();
                }  

                // Specifies the name of the web page file to generate.
                //    In this case, we use a timestamp to uniquely identify each blog.
                string fileName = DateTime.Now.Ticks.ToString();

                // Extract the blog title and body data posted to the server
                String blogTitle = form.GetValues("BlogTitleText")[0];  
                String inkBody  = form.GetValues("BlogBodyInkData")[0]; 
                String textBody = form.GetValues("BlogBodyText")[0];

                // Html fragment to be inserted into the blog's web page.  
                string content = null;

                // Check if ink data is available.  If so create a corresponding GIF 
                // from the serialized ink data and an HTML fragment referencing it.
                // Otherwise, create an HTML fragment with text from the blog.
                if ( ( String.Empty != inkBody ) )
                {           
                    // Use helper method to create a GIF image file from ink data 
                    CreateGif(imagePath, fileName, inkBody);
                    
                    // Create an HTML fragment to reference the image file
                    content = "<img src=\"Blogs/Images/" + fileName + ".gif\"></img>";
                }                
                else 
                {
                    // If no ink data is available create an HTML fragment that contains
                    // the blog's text directly.
                    content = "<P>" + textBody + "</P>";
                }

                // Use helper method to create the blog web page on the server
                CreateHtm(blogPath, fileName, blogTitle, content);

                // Redirect the user to Default.aspx, which displays a list of all
                // available blogs.
                Response.Clear();
                Response.Redirect("Default.aspx");
            }
        }

        /// <summary>
        /// Helper method to create a GIF image file from the serialized ink data.
        /// Note:  since the ink data was serialized on the client side, the
        /// server does not need to have any specialized knowledge of ink.
        /// </summary>
        /// <param name="path">The location where the image should be created</param>
        /// <param name="fileName">The filename of the image</param>
        /// <param name="inkData">The serialized ink data</param>
        protected void CreateGif(String path, String fileName, String inkBody)
        {
            String gifFilePath = Path.Combine(path, fileName + ".gif");
            using (FileStream fs = File.Create(gifFilePath))
            {
                byte[] bytes = Convert.FromBase64String(inkBody);
                fs.Write(bytes,0,bytes.Length);
            }
        }

        /// <summary>
        /// Helper method to create a HTM file from the blog data.
        /// </summary>
        /// <param name="fileName">The location where the HTM file should be created</param>
        /// <param name="blogName">The filename of the image</param>
        /// <param name="content">The HTML fragment that either references the ink image or text data</param>
        protected void CreateHtm(String path, String fileName, String blogTitle, String content) 
        {
            String htmFilePath = Path.Combine(path, fileName + ".htm");

            using (StreamWriter htmFile = File.CreateText(htmFilePath))
            {
                htmFile.Write("<h3 align=center>" + blogTitle + " (" +DateTime.Now.ToString() + ")</h3>");
                htmFile.Write(content);
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
