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
using System.Text;
using System.Data.SqlClient;

namespace Microsoft.Samples.HowTo.ADONET
{
    /// <summary>
    /// Summary description for WebForm1.
    /// </summary>
    public class HandleErrors : System.Web.UI.Page
    {

        StringBuilder builder = new StringBuilder();
        protected System.Web.UI.HtmlControls.HtmlForm output;

        private void Page_Load(object sender, System.EventArgs e)
        {
            Run();
            this.output.InnerHtml = builder.ToString();
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


        public void Run()
        {
            // Create a new Connection and SqlDataAdapter

            SqlConnection myConnection = new SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");
            SqlDataAdapter mySqlDataAdapter = new SqlDataAdapter("select * from customers", myConnection);

            // Create the new instance of the DataSet
            DataSet myDataSet = new DataSet();

            try
            {
                // Load the customer table from the database into a table called Customers in the dataset
                mySqlDataAdapter.Fill(myDataSet, "Customers");

                // Create a new dataview instance on the Customers table that was just created
                DataView myDataView = new DataView(myDataSet.Tables["Customers"]);

                // Sort the view based on the FirstName column
                myDataView.Sort = "CustomerID";

                myDataSet.Tables["Customers"].Rows[0].RowError = "An Error was added";
                myDataSet.Tables["Customers"].Rows[1].RowError = "This is another error message";

                if (myDataSet.Tables["Customers"].HasErrors)
                {
                    DataRow[] ErrDataRows = myDataSet.Tables["Customers"].GetErrors();
                    builder.Append("DataTable " + myDataSet.Tables["Customers"].TableName + " has " + ErrDataRows.Length.ToString() + " Error(s)! </BR>");

                    for (int i = 0; i <= ErrDataRows.Length - 1; i++)
                    {
                        builder.Append("Row Error for row " + ErrDataRows[i]["CustomerID"].ToString() + " --  Error Msg=" + ErrDataRows[i].RowError + "</BR>");
                    }
                }
                else
                {
                    builder.Append("================= </BR>");
                    builder.Append("DataTable " + myDataSet.Tables["Customers"].TableName + " Has no errors</BR>");
                }
            }
            catch (Exception e)
            {
                builder.Append("</BR>" + e.ToString());
            }
            finally
            {
                myConnection.Close();
            }
        }
    }
}
