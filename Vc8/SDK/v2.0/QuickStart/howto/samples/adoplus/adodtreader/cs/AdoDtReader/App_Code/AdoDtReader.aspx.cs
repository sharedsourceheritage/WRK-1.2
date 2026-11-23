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
using System.Data.OleDb;
using System.Text;


namespace Microsoft.Samples.HowTo.ADONET
{
    /// <summary>
    /// Summary description for WebForm1.
    /// </summary>
    public class AdoDtReader : System.Web.UI.Page
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
            OleDbDataReader myDataReader = null;

            OleDbConnection myOleDbConnection = new OleDbConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind;provider=SQLNCLI");
            OleDbCommand myOleDbCommand = new OleDbCommand("SELECT EmployeeID, LastName, FirstName, Title, ReportsTo FROM Employees", myOleDbConnection);

            try
            {
                myOleDbConnection.Open();
                myDataReader = myOleDbCommand.ExecuteReader();

                builder.Append("<Table>");
                builder.Append("<tr><td>Employee ID</td>");
                builder.Append("<td>Name</td>");
                builder.Append("<td>Title</td>");
                builder.Append("<td>Reports To</td></tr>");

                // Always call Read before accessing data.
                while (myDataReader.Read())
                {
                    builder.Append("<tr><td>" + myDataReader.GetInt32(0) + "</td>");
                    builder.Append("<td>" + myDataReader.GetString(2) + " " + myDataReader.GetString(1) + "\t");
                    builder.Append("<td>" + myDataReader.GetString(3) + "\t");
                    if (myDataReader.IsDBNull(4))
                        builder.Append("<td>N/A</td>");
                    else
                        builder.Append("<td>" + myDataReader.GetInt32(4) + "</td></tr>");
                }
                builder.Append("</TABLE>");
            }
            catch (Exception e)
            {
                builder.Append(e.ToString());
            }
            finally
            {
                // Always call Close when done reading.
                if (myDataReader != null)
                    myDataReader.Close();

                // Close the connection when done with it.
                if (myOleDbConnection.State == ConnectionState.Open)
                    myOleDbConnection.Close();
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
