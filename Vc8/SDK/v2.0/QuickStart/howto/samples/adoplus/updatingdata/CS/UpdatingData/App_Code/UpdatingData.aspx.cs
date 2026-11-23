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
    public class UpdatingData : System.Web.UI.Page
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

            SqlConnection myConnection = new SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");
            SqlDataAdapter mySqlDataAdapter = new SqlDataAdapter("select * from customers", myConnection);
            SqlDataAdapter mySqlDataAdapter1 = new SqlDataAdapter("select * from orders", myConnection);

            // Restore database to it's original condition so sample will work correctly.
            Cleanup();

            try
            {
                DataSet myDataSet = new DataSet();
                DataRow myDataRow;

                // Create command builder. This line automatically generates the update commands for you, so you don't 
                // have to provide or create your own.
                SqlCommandBuilder mySqlCommandBuilder = new SqlCommandBuilder(mySqlDataAdapter);

                // Set the MissingSchemaAction property to AddWithKey because Fill will not cause primary
                // key & unique key information to be retrieved unless AddWithKey is specified.
                mySqlDataAdapter.MissingSchemaAction = MissingSchemaAction.AddWithKey;
                mySqlDataAdapter1.MissingSchemaAction = MissingSchemaAction.AddWithKey;

                mySqlDataAdapter.Fill(myDataSet, "Customers");
                builder.Append("Loaded data from Customers table into dataset. <BR/>");

                mySqlDataAdapter1.Fill(myDataSet, "Orders");
                builder.Append("Loaded data from Orders  table into dataset. <BR/>");

                // ADD RELATION
                myDataSet.Relations.Add("CustOrders", myDataSet.Tables["Customers"].Columns["CustomerId"], myDataSet.Tables["Orders"].Columns["CustomerId"]);

                // EDIT
                myDataSet.Tables["Customers"].Rows[0]["ContactName"] = "Peach";

                // ADD
                myDataRow = myDataSet.Tables["Customers"].NewRow();
                myDataRow["CustomerId"] = "NewID";
                myDataRow["ContactName"] = "New Name";
                myDataRow["CompanyName"] = "New Company Name";
                myDataSet.Tables["Customers"].Rows.Add(myDataRow);
                builder.Append("Inserted new row into Customers. <BR/>");

                // Update Database with SqlDataAdapter
                mySqlDataAdapter.Update(myDataSet, "Customers");
                builder.Append("Sent Update to database. <BR/>");

                builder.Append("DataSet processing has completed successfully!<BR/>");
            }
            catch (Exception e)
            {
                builder.Append("<BR/>" + e.ToString());
            }
        }

        public void Cleanup()
        {
            SqlConnection myConnection = new SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");

            try
            {
                // Restore database to it's original condition so sample will work correctly.
                myConnection.Open();
                SqlCommand CleanupCommand = new SqlCommand("DELETE FROM Customers WHERE CustomerId = 'NewID'", myConnection);
                CleanupCommand.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                builder.Append("<BR/>" + e.ToString());
            }
            finally
            {
                myConnection.Close();
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
