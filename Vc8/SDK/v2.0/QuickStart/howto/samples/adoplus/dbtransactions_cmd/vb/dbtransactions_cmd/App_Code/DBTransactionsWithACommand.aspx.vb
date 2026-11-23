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
    Public Class DBTransactionsWithACommand
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
        Public Shared Sub Main()

        End Sub

        Public Sub Run()

            Dim myConnection As SqlConnection = New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
            Dim myCommand As SqlCommand = New SqlCommand
            Dim myTrans As SqlTransaction

            ' Open the connection.
            myConnection.Open()

            ' Assign the connection property.
            myCommand.Connection = myConnection

            ' Begin the transaction.
            myTrans = myConnection.BeginTransaction()

            ' Assign transaction object for a pending local transaction
            myCommand.Transaction = myTrans

            Try
                ' Restore database to it's original condition so sample will work correctly.
                myCommand.CommandText = "DELETE FROM Region WHERE (RegionID = 100) OR (RegionID = 101)"
                myCommand.ExecuteNonQuery()

                ' Insert the first record.
                myCommand.CommandText = "Insert into Region (RegionID, RegionDescription) VALUES (100, 'MidWestern')"
                myCommand.ExecuteNonQuery()

                ' Insert the second record.
                myCommand.CommandText = "Insert into Region (RegionID, RegionDescription) VALUES (101, 'MidEastern')"
                myCommand.ExecuteNonQuery()

                myTrans.Commit()
                builder.Append("<BR/>Both Records are written to the database!")
            Catch e As Exception
                ' Rollback the transaction
                myTrans.Rollback()
                builder.Append("<BR/>" + e.ToString())
                builder.Append("<BR/>Neither record is written to the database!")
            Finally
                myConnection.Close()
            End Try
        End Sub
    End Class
End Namespace
