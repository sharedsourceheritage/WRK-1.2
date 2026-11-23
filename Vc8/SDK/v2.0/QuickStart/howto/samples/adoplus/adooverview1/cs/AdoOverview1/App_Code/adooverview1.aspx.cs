//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET Framework SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------
using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;
using System.Text;


namespace Microsoft.Samples.HowTo.ADONET
{
    /// <summary>
    /// Summary description for WebForm1.
    /// </summary>
    public class AdoOverview1 : System.Web.UI.Page
    {
        StringBuilder builder = new StringBuilder();
        protected System.Web.UI.HtmlControls.HtmlForm output;


        private void Page_Load(object sender, System.EventArgs e)
        {
            Run();
            this.output.InnerHtml = builder.ToString();
        }

        public void Run()
        {

            SqlConnection mySqlConnection = new SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");

            try
            {
                mySqlConnection.Open();
                builder.Append("Opened Connection to " + mySqlConnection.ConnectionString + "</BR>");

                // Close the connection explicitly
                mySqlConnection.Close();
                builder.Append("Closed Connection.  It is important to close connections explicitly. </BR>");
            }
            catch
            {
                builder.Append("Couldn't Open Connection to " + mySqlConnection.ConnectionString);
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
