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
    public class ConnectionPooling : System.Web.UI.Page
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
            try
            {
                String connString;

                // Specification in the connection string:
                // Please note: Pooling is implicit, you automatically get it unless you disable it. 
                //              Therefore, "true" is the default for the pooling keyword (pooling=true).   
                // Connection Reset:    False
                // Connection Lifetime: 5
                // Enlist:              true
                // Min Pool Size:       1
                // Max Pool Size:       50
                connString = "server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind;" +
                    "connection reset=false;" +
                    "connection lifetime=5;" +
                    "min pool size=1;" +
                    "max pool size=50";

                SqlConnection myConnection1 = new SqlConnection(connString);
                SqlConnection myConnection2 = new SqlConnection(connString);
                SqlConnection myConnection3 = new SqlConnection(connString);

                // Open two connections.
                builder.Append("Open two connections. </BR>");
                myConnection1.Open();
                myConnection2.Open();

                // Now there are two connections in the pool that matches the connection string.
                // Return the both connections to the pool. 
                builder.Append("Return both of the connections to the pool. </BR>");
                myConnection1.Close();
                myConnection2.Close();

                // Get a connection out of the pool.
                builder.Append("Open a connection from the pool. </BR>");
                myConnection1.Open();

                // Get a second connection out of the pool.
                builder.Append("Open a second connection from the pool. </BR>");
                myConnection2.Open();

                // Open a third connection.
                builder.Append("Open a third connection. </BR>");
                myConnection3.Open();

                // Return the all connections to the pool.  
                builder.Append("Return all three connections to the pool. </BR>");
                myConnection1.Close();
                myConnection2.Close();
                myConnection3.Close();
            }
            catch (Exception e)
            {
                // Display the error.
                builder.Append(e.ToString());
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
