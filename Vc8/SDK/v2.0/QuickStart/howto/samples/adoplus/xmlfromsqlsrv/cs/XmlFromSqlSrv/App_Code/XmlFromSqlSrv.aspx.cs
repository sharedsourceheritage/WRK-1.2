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
using System.IO;

namespace Microsoft.Samples.HowTo.ADONET
{
    /// <summary>
    /// Summary description for WebForm1.
    /// </summary>
    public class XmlFromSqlSrv : System.Web.UI.Page
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

            String sConnection = "server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind";
            SqlConnection mySqlConnection = new SqlConnection(sConnection);
            SqlCommand mySqlCommand = new SqlCommand("select * from customers FOR XML AUTO, XMLDATA", mySqlConnection);
            mySqlCommand.CommandTimeout = 15;

            try
            {
                mySqlConnection.Open();

                // Now create the DataSet and fill it with xml data.
                DataSet myDataSet1 = new DataSet();
                myDataSet1.ReadXml(mySqlCommand.ExecuteXmlReader(), XmlReadMode.Fragment);

                // Modify to match the other dataset
                myDataSet1.DataSetName = "NewDataSet";


                // Get the same data through the provider.
                SqlDataAdapter mySqlDataAdapter = new SqlDataAdapter("select * from customers", sConnection);
                DataSet myDataSet2 = new DataSet();
                mySqlDataAdapter.Fill(myDataSet2);

                // Write data to files: data1.xml and data2.xml for comparison.
                myDataSet1.WriteXml(Path.GetTempPath() + "data1.xml");
                myDataSet2.WriteXml(Path.GetTempPath() + "data2.xml");
                builder.Append("Data has been writen to the output files: data1.xml and data2.xml <BR/>");
                builder.Append("<BR/>");
                builder.Append("********************data1.xml******************** <BR/>");
                builder.Append(myDataSet1.GetXml() + "<BR/>");
                builder.Append("<BR/>");
                builder.Append("********************data2.xml******************** <BR/>");
                builder.Append(myDataSet2.GetXml() + "<BR/>");
            }
            catch (Exception e)
            {
                builder.Append("<BR/>" + e.ToString());
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
