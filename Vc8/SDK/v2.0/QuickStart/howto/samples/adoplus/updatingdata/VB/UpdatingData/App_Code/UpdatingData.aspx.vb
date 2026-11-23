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
Imports System.Text

Namespace Microsoft.Samples.HowTo.ADONET
    Public Class UpdatingData
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
            Dim myConnection As SqlConnection
            Dim mySqlDataAdapter As SqlDataAdapter
            Dim mySqlDataAdapter1 As SqlDataAdapter


            myConnection = New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
            mySqlDataAdapter = New SqlDataAdapter("select * from customers", myConnection)
            mySqlDataAdapter1 = New SqlDataAdapter("select * from orders", myConnection)

            ' Restore database to it's original condition so sample will work correctly.
            Cleanup()

            Try
                Dim myDataSet As DataSet = New DataSet
                Dim myDataRow As DataRow

                ' Create command builder. This line automatically generates the update commands for you, so you don't 
                ' have to provide or create your own.
                Dim myDataRowsCommandBuilder As SqlCommandBuilder = New SqlCommandBuilder(mySqlDataAdapter)

                ' Set the MissingSchemaAction property to AddWithKey because Fill will not cause primary
                ' key & unique key information to be retrieved unless AddWithKey is specified.
                mySqlDataAdapter.MissingSchemaAction = MissingSchemaAction.AddWithKey
                mySqlDataAdapter1.MissingSchemaAction = MissingSchemaAction.AddWithKey

                mySqlDataAdapter.Fill(myDataSet, "Customers")
                builder.Append("Loaded data from Customers table into dataset. <BR/>")

                mySqlDataAdapter1.Fill(myDataSet, "Orders")
                builder.Append("Loaded data from Orders  table into dataset. <BR/>")

                ' ADD RELATION
                myDataSet.Relations.Add("CustOrders", myDataSet.Tables("Customers").Columns("CustomerId"), myDataSet.Tables("Orders").Columns("CustomerId"))

                ' EDIT
                myDataSet.Tables("Customers").Rows(0)("ContactName") = "Peach"

                ' ADD
                myDataRow = myDataSet.Tables("Customers").NewRow()
                myDataRow("CustomerId") = "NewID"
                myDataRow("ContactName") = "New Name"
                myDataRow("CompanyName") = "New Company Name"
                myDataSet.Tables("Customers").Rows.Add(myDataRow)
                builder.Append("Inserted new row into Customers. <BR/>")

                ' Update Database with SqlDataAdapter
                mySqlDataAdapter.Update(myDataSet, "Customers")
                builder.Append("Sent Update to database. <BR/>")

                builder.Append("DataSet processing has completed successfully!<BR/>")

            Catch e As Exception
                builder.Append("<BR/>" + e.ToString())
            End Try
        End Sub

        Public Sub Cleanup()
            Dim myConnection As SqlConnection
            Dim CleanupCommand As SqlCommand

            myConnection = New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")

            Try
                ' Restore database to it's original condition so sample will work correctly.
                myConnection.Open()
                CleanupCommand = New SqlCommand("DELETE FROM Customers WHERE CustomerId = 'NewID'", myConnection)
                CleanupCommand.ExecuteNonQuery()
            Catch e As Exception
                builder.Append("<BR/>" + e.ToString())
            Finally
                myConnection.Close()
            End Try
        End Sub

    End Class
End Namespace
