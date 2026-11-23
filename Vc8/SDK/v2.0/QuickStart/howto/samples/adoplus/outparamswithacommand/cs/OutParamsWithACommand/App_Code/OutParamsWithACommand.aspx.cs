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
    public class OutParamsWithACommand : System.Web.UI.Page
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

            // Create stored procedure with out parameter
            try
            {
                SqlCommand CreateProcCommand = new SqlCommand("CREATE PROCEDURE GetCompanyName  @CustomerId nchar(5), @CompanyName nchar(40) out as select @CompanyName = CompanyName from Customers where CustomerId = @CustomerId", myConnection);
                SqlCommand DropProcCommand = new SqlCommand("IF EXISTS (SELECT name FROM sysobjects WHERE name = 'GetCompanyName' AND type = 'P') DROP PROCEDURE GetCompanyName", myConnection);

                myConnection.Open();
                DropProcCommand.ExecuteNonQuery();   // remove procedure if it exists
                CreateProcCommand.ExecuteNonQuery(); // create procedure

                SqlCommand myCommand = new SqlCommand("GetCompanyName", myConnection);
                myCommand.CommandType = CommandType.StoredProcedure;

                // Fill the parameters collection based upon stored procedure.
                SqlParameter workParam = null;

                workParam = myCommand.Parameters.Add("@CustomerID", SqlDbType.NChar, 5);
                // ParameterDirection.Input is the default for the Direction property. Thus the following line is not
                // needed here. To set the Direction property to its default value, use the following line.
                // workParam.Direction = ParameterDirection.Input;

                workParam = myCommand.Parameters.Add("@CompanyName", SqlDbType.NChar, 40);
                workParam.Direction = ParameterDirection.Output;

                myCommand.Parameters["@CustomerID"].Value = "ALFKI";

                myCommand.ExecuteNonQuery();
                builder.Append("CompanyName = " + myCommand.Parameters["@CompanyName"].Value.ToString());
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
