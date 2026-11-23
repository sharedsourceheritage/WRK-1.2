'-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET Framework SDK Code Samples.
' 
'  Copyright (C) Microsoft Corporation.  All rights reserved.
' 
'This source code is intended only as a supplement to Microsoft
'Development Tools and/or on-line documentation.  See these other
'materials for detailed information regarding Microsoft code samples.
' 
'THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
'KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'PARTICULAR PURPOSE.
'-----------------------------------------------------------------------
Imports System
Imports System.Data
Imports System.Data.SqlClient
Imports System.XML
Imports System.Text
Imports System.IO.Path

Namespace Microsoft.Samples.HowTo.ADONET
    Public Class XmlFromSqlSrv
        Inherits System.Web.UI.Page

#Region " Web Form Designer Generated Code "

        'This call is required by the Web Form Designer.
        <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()

        End Sub

        'NOTE: The following placeholder declaration is required by the Web Form Designer.
        'Do not delete or move it.
        Private designerPlaceholderDeclaration As System.Object

        Private Sub Page_Init(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Init
            'CODEGEN: This method call is required by the Web Form Designer
            'Do not modify it using the code editor.
            InitializeComponent()
        End Sub

#End Region

        Dim builder As New StringBuilder()
        Protected WithEvents output As System.Web.UI.HtmlControls.HtmlForm

        Private Sub Page_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
            Run()
            output.InnerHtml = builder.ToString()
        End Sub


        Public Sub Run()

            Dim sConnection As String = "server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind"
            Dim mySqlConnection As SqlConnection = New SqlConnection(sConnection)
            Dim mySqlCommand As SqlCommand = New SqlCommand("select * from customers FOR XML AUTO, XMLDATA", mySqlConnection)
            mySqlCommand.CommandTimeout = 15

            Try
                mySqlConnection.Open()

                ' Now create the DataSet and fill it with xml data.
                Dim myDataSet1 As DataSet = New DataSet
                myDataSet1.ReadXml(mySqlCommand.ExecuteXmlReader(), XmlReadMode.Fragment)

                ' Modify to match the other dataset
                myDataSet1.DataSetName = "NewDataSet"


                ' Get the same data through the provider.
                Dim mySqlDataAdapter As SqlDataAdapter = New SqlDataAdapter("select * from customers", sConnection)
                Dim myDataSet2 As DataSet = New DataSet
                mySqlDataAdapter.Fill(myDataSet2)

                ' Write data to files: data1.xml and data2.xml.
                myDataSet1.WriteXml(GetTempPath() + "data1.xml")
                myDataSet2.WriteXml(GetTempPath() + "data2.xml")
                builder.Append("Data has been writen to the output files: data1.xml and data2.xml <BR/>")
                builder.Append("<BR/>")
                builder.Append("********************data1.xml******************** <BR/>")
                builder.Append(myDataSet1.GetXml() + "<BR/>")
                builder.Append("<BR/>")
                builder.Append("********************data2.xml******************** <BR/>")
                builder.Append(myDataSet2.GetXml() + "<BR/>")


            Catch e As Exception
                builder.Append("<BR/>" + e.ToString())
            Finally
                mySqlConnection.Close()
            End Try
        End Sub

    End Class
End Namespace
