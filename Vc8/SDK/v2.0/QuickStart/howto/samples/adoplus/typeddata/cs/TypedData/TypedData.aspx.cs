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
using customerDataSet;

namespace Microsoft.Samples.HowTo.ADONET
{
    /// <summary>
    /// Summary description for WebForm1.
    /// </summary>
    public partial class TypedData : System.Web.UI.Page
    {
        StringBuilder builder = new StringBuilder();
        


        private void Page_Load(object sender, System.EventArgs e)
        {
            Run();
            this.output.InnerHtml = builder.ToString();
        }

        public void Run()
        {

            SqlDataAdapter mySqlDataAdapter = new SqlDataAdapter("Select * from customers", "server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");

            try
            {
                custDS myCustDS = new custDS();
                mySqlDataAdapter.Fill(myCustDS, "Customers");

                builder.Append("CustomerID <BR/>");

                foreach (custDS.customersRow myDataRow in myCustDS.customers)
                    builder.Append(myDataRow.CustomerID.ToString() + "<BR/>");
            }
            catch (Exception e)
            {
                builder.Append("<BR/>" + e.ToString());
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
