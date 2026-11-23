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
    Public Class OutParamsWithACommand
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

            myConnection = New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")

            ' Create stored procedure with out parameter
            Try
                Dim CreateProcCommand As SqlCommand
                Dim DropProcCommand As SqlCommand
                CreateProcCommand = New SqlCommand("CREATE PROCEDURE GetCompanyName  @CustomerId nchar(5), @CompanyName nchar(40) out as select @CompanyName = CompanyName from Customers where CustomerId = @CustomerId", myConnection)
                DropProcCommand = New SqlCommand("IF EXISTS (SELECT name FROM sysobjects WHERE name = 'GetCompanyName' AND type = 'P') DROP PROCEDURE GetCompanyName", myConnection)

                myConnection.Open()
                DropProcCommand.ExecuteNonQuery()   ' remove procedure if it exists
                CreateProcCommand.ExecuteNonQuery() ' create procedure

                Dim myCommand As SqlCommand
                myCommand = New SqlCommand("GetCompanyName", myConnection)
                myCommand.CommandType = CommandType.StoredProcedure

                ' Fill the parameters collection based upon stored procedure
                Dim workParam As SqlParameter

                workParam = myCommand.Parameters.Add("@CustomerID", SqlDbType.NChar, 5)
                ' ParameterDirection.Input is the default for the Direction property. Thus the following line is not
                ' needed here. To set the Direction property to its default value, use the following line.
                'workParam.Direction = ParameterDirection.Input

                workParam = myCommand.Parameters.Add("@CompanyName", SqlDbType.NChar, 40)
                workParam.Direction = ParameterDirection.Output

                myCommand.Parameters("@CustomerID").Value = "ALFKI"

                myCommand.ExecuteNonQuery()
                builder.Append("CompanyName = " + myCommand.Parameters("@CompanyName").Value.ToString())
            Catch e As Exception
                builder.Append("</BR>" + e.ToString())
            Finally
                myConnection.Close()
            End Try

        End Sub
    End Class
End Namespace
