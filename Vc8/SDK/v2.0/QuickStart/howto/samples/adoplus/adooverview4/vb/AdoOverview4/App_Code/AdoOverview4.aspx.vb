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
    Public Class AdoOverview4
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
            Dim workParam As SqlParameter


            myConnection = New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
            mySqlDataAdapter = New SqlDataAdapter("Select * from Region", myConnection)

            ' Restore database to it's original condition so sample will work correctly.
            Cleanup()

            ' Build the insert Command
            mySqlDataAdapter.InsertCommand = New SqlCommand("Insert into Region (RegionID, RegionDescription) VALUES (@RegionID, @RegionDescription)", myConnection)

            workParam = mySqlDataAdapter.InsertCommand.Parameters.Add("@RegionID", SqlDbType.Int)
            workParam.SourceColumn = "RegionID"
            workParam.SourceVersion = DataRowVersion.Current

            workParam = mySqlDataAdapter.InsertCommand.Parameters.Add("@RegionDescription", SqlDbType.NChar, 50)
            workParam.SourceVersion = DataRowVersion.Current
            workParam.SourceColumn = "RegionDescription"

            ' Build the update command
            mySqlDataAdapter.UpdateCommand = New SqlCommand("Update Region Set RegionDescription = @RegionDescription WHERE RegionID = @RegionID", myConnection)

            workParam = mySqlDataAdapter.UpdateCommand.Parameters.Add("@RegionID", SqlDbType.Int)
            workParam.SourceColumn = "RegionID"
            workParam.SourceVersion = DataRowVersion.Original

            workParam = mySqlDataAdapter.UpdateCommand.Parameters.Add("@RegionDescription", SqlDbType.NChar, 50)
            workParam.SourceVersion = DataRowVersion.Current
            workParam.SourceColumn = "RegionDescription"

            Dim myDataSet As DataSet
            myDataSet = New DataSet

            ' Set the MissingSchemaAction property to AddWithKey because Fill will not cause primary key & unique key information to be retrieved unless AddWithKey is specified.
            mySqlDataAdapter.MissingSchemaAction = MissingSchemaAction.AddWithKey
            mySqlDataAdapter.Fill(myDataSet, "Region")

            Dim myDataRow1 As DataRow
            myDataRow1 = myDataSet.Tables("Region").Rows.Find(2)
            myDataRow1(1) = "Changed this region desc"

            Dim myDataRow2 As DataRow
            myDataRow2 = myDataSet.Tables("Region").NewRow()
            myDataRow2(0) = 901
            myDataRow2(1) = "A new region"
            myDataSet.Tables("Region").Rows.Add(myDataRow2)

            Try
                mySqlDataAdapter.Update(myDataSet, "Region")
                builder.Append("Updating DataSet succeeded!")
            Catch e As Exception
                builder.Append("<BR/>" + e.ToString())
            End Try
        End Sub

        Public Sub Cleanup()
            Dim myConnection As SqlConnection = New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")

            Try
                ' Restore database to it's original condition so sample will work correctly.
                myConnection.Open()
                Dim CleanupCommand As SqlCommand = New SqlCommand("DELETE FROM Region WHERE RegionID = '901'", myConnection)
                CleanupCommand.ExecuteNonQuery()
            Catch e As Exception
                builder.Append("<BR/>" + e.ToString())
            Finally
                myConnection.Close()
            End Try
        End Sub
    End Class
End Namespace
