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
using System.Xml;
using System.Text;

namespace Microsoft.Samples.HowTo.ADONET
{
    /// <summary>
    /// Summary description for Employees.
    /// </summary>
    public class Employees : System.Web.UI.Page
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
            mySqlConnection.Open();
            SqlCommand mySqlCommand = new SqlCommand("select * from employees order by EmployeeID", mySqlConnection);

            try
            {
                SqlDataReader myReader = mySqlCommand.ExecuteReader();

                int record = 0;
                int photoColumn = myReader.GetOrdinal("Photo");
                builder.Append("<TABLE>");

                while (myReader.Read())
                {
                    record++;
                    builder.Append("<TR><TD colspan=" + myReader.FieldCount + ">************************ Employee number " + record.ToString() + " ************************</TD></TR>");
                    builder.Append("<TR>");

                    // Display each column and value, skipping the "Photo" column
                    for (int column = 0; column < myReader.FieldCount; column++)
                    {
                        if (column != photoColumn)
                        {
                            builder.Append("<TD>" + myReader.GetName(column) + "</TD><TD>" + myReader.GetValue(column).ToString() + "</TD>");
                        }
                    }
                    builder.Append("</TR>");

                }
                builder.Append("</TABLE>");
            }

            catch (Exception e)
            {
                builder.Append("</BR>" + e.ToString());
            }
            finally
            {
                mySqlConnection.Close();
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
