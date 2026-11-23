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
    /// Summary description for AdoOverview4.
    /// </summary>
    public class AdoOverview4 : System.Web.UI.Page
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
            // Create a new Connection and SqlDataAdapter

            SqlConnection myConnection = new SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");
            SqlDataAdapter mySqlDataAdapter = new SqlDataAdapter("Select * from Region", myConnection);
            SqlParameter workParam = null;

            // Restore database to it's original condition so sample will work correctly.
            Cleanup();

            // Build the insert Command
            mySqlDataAdapter.InsertCommand = new SqlCommand("Insert into Region (RegionID, RegionDescription) VALUES (@RegionID, @RegionDescription)", myConnection);

            workParam = mySqlDataAdapter.InsertCommand.Parameters.Add("@RegionID", SqlDbType.Int);
            workParam.SourceColumn = "RegionID";
            workParam.SourceVersion = DataRowVersion.Current;

            workParam = mySqlDataAdapter.InsertCommand.Parameters.Add("@RegionDescription", SqlDbType.NChar, 50);
            workParam.SourceVersion = DataRowVersion.Current;
            workParam.SourceColumn = "RegionDescription";

            // Build the update command
            mySqlDataAdapter.UpdateCommand = new SqlCommand("Update Region Set RegionDescription = @RegionDescription WHERE RegionID = @RegionID", myConnection);

            workParam = mySqlDataAdapter.UpdateCommand.Parameters.Add("@RegionID", SqlDbType.Int);
            workParam.SourceColumn = "RegionID";
            workParam.SourceVersion = DataRowVersion.Original;

            workParam = mySqlDataAdapter.UpdateCommand.Parameters.Add("@RegionDescription", SqlDbType.NChar, 50);
            workParam.SourceVersion = DataRowVersion.Current;
            workParam.SourceColumn = "RegionDescription";

            DataSet myDataSet = new DataSet();

            // Set the MissingSchemaAction property to AddWithKey because Fill will not cause primary key & unique key information to be retrieved unless AddWithKey is specified.
            mySqlDataAdapter.MissingSchemaAction = MissingSchemaAction.AddWithKey;
            mySqlDataAdapter.Fill(myDataSet, "Region");

            DataRow myDataRow1 = myDataSet.Tables["Region"].Rows.Find(2);
            myDataRow1[1] = "Changed this region desc";

            DataRow myDataRow2 = myDataSet.Tables["Region"].NewRow();
            myDataRow2[0] = 901;
            myDataRow2[1] = "A new region";
            myDataSet.Tables["Region"].Rows.Add(myDataRow2);

            try
            {
                mySqlDataAdapter.Update(myDataSet, "Region");
                builder.Append("Updating DataSet succeeded!</BR>");
            }
            catch (Exception e)
            {
                builder.Append(e.ToString());
            }
        }

        public void Cleanup()
        {
            SqlConnection myConnection = new SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");

            try
            {
                // Restore database to it's original condition so sample will work correctly.
                myConnection.Open();
                SqlCommand CleanupCommand = new SqlCommand("DELETE FROM Region WHERE RegionID = '901'", myConnection);
                CleanupCommand.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                builder.Append(e.ToString());
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
