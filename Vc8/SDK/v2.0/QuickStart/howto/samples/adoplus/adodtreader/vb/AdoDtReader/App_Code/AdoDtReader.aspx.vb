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
Imports System.Data.OleDb
Imports Microsoft.VisualBasic
Imports System.Text

Namespace Microsoft.Samples.HowTo.ADONET
    Public Class AdoDtReader
        Inherits System.Web.UI.Page


#Region " Web Form Designer Generated Code "

        'This call is required by the Web Form Designer.
        <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()

        End Sub



        'NOTE: The following placeholder declaration is required by the Web Form Designer.
        'Do not delete or move it.
        Private designerPlaceholderDeclaration As System.Object

        Dim builder As New StringBuilder()
        Protected WithEvents output As System.Web.UI.HtmlControls.HtmlForm

        Private Sub Page_Init(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Init
            'CODEGEN: This method call is required by the Web Form Designer
            'Do not modify it using the code editor.
            InitializeComponent()
        End Sub

#End Region

        Private Sub Page_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
            Run()
            output.InnerHtml = builder.ToString()
        End Sub



        Public Sub Run()
            Dim myDataReader As OleDbDataReader
            Dim myOleDbConnection As OleDbConnection
            Dim myOleDbCommand As OleDbCommand


            myOleDbConnection = New OleDbConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind;provider=SQLNCLI")
            myOleDbCommand = New OleDbCommand("SELECT EmployeeID, LastName, FirstName, Title, ReportsTo FROM Employees", myOleDbConnection)

            Try
                myOleDbConnection.Open()
                myDataReader = myOleDbCommand.ExecuteReader()

                builder.Append("<TABLE><TR><TD>EmployeeID</TD>")
                builder.Append("<TD>Name</TD>")
                builder.Append("<TD>Title</TD>")
                builder.Append("<TD>ReportsTo</TD></TR>")

                ' Always call Read before accessing data.
                Do While (myDataReader.Read())
                    builder.Append("<TR><TD>" + myDataReader.GetInt32(0).ToString() + "</TD>")
                    builder.Append("<TD>" + myDataReader.GetString(2) + " " + myDataReader.GetString(1) + "</TD>")
                    builder.Append("<TD>" + myDataReader.GetString(3) + "</TD>")
                    If (myDataReader.IsDBNull(4)) Then
                        builder.Append("<TD>N/A</TD></TR>")
                    Else
                        builder.Append("<TD>" + myDataReader.GetInt32(4).ToString() + "</TD></TR>")
                    End If
                Loop
            Catch e As Exception
                builder.Append("<BR/>" + e.ToString())
            Finally
                ' Always call Close when done reading.
                If Not (myDataReader Is Nothing) Then
                    myDataReader.Close()
                End If

                ' Close the connection when done with it.
                If (myOleDbConnection.State = ConnectionState.Open) Then
                    myOleDbConnection.Close()
                End If
            End Try
        End Sub

    End Class

End Namespace
