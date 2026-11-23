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
    Public Class FilterDataTable
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
            ' Create a new Connection and SqlDataAdapter
            Dim myConnection As SqlConnection
            Dim mySqlDataAdapter As SqlDataAdapter

            myConnection = New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
            mySqlDataAdapter = New SqlDataAdapter("select * from customers", myConnection)

            Try
                ' Create the new instance of the DataSet
                Dim myDataSet As DataSet
                myDataSet = New DataSet

                ' Load the customer table from the database into a table called Customers in the dataset
                mySqlDataAdapter.Fill(myDataSet, "Customers")

                ' Create a new dataview instance on the Customers table that was just created
                Dim myDataView As DataView
                myDataView = New DataView(myDataSet.Tables("Customers"))

                ' Sort the view based on the FirstName column
                myDataView.Sort = "CustomerID"

                ' Filter the dataview to only show customers with the CustomerID of ALFKI.
                myDataView.RowFilter = "CustomerID='ALFKI'"

                Dim i As Integer
                For i = 0 To myDataView.Count - 1
                    builder.Append(myDataView(i)("CustomerID").ToString() + " - " + myDataView(i)("CompanyName").ToString())
                Next
            Catch e As Exception
                builder.Append("<BR/>" + e.ToString())
            Finally
                myConnection.close()
            End Try
        End Sub
    End Class
End Namespace
