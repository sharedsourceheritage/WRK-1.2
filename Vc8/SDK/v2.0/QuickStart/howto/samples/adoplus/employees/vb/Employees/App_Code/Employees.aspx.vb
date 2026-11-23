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
Imports Microsoft.VisualBasic
Imports System.Text

Namespace Microsoft.Samples.HowTo.ADONET
    Public Class Employees
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

            Dim mySqlConnection As SqlConnection = New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
            mySqlConnection.Open()

            Dim mySqlCommand As SqlCommand = New SqlCommand("select * from employees order by EmployeeID", mySqlConnection)

            Try
                Dim myReader As SqlDataReader = mySqlCommand.ExecuteReader()

                Dim record As Integer = 0
                Dim photoColumn As Integer = myReader.GetOrdinal("Photo")
                builder.Append("<TABLE>")
                Dim column As Integer

                While myReader.Read()
                    record = record + 1
                    Dim totalFields As Integer
                    totalFields = myReader.FieldCount

                    builder.Append("<TR><TD colspan=" + totalFields.ToString() + ">************************ Employee number " + record.ToString() + " ************************</TD></TR>")
                    builder.Append("<TR>")

                    ' Display each column and value, skipping the "Photo" column
                    For column = 0 To totalFields - 1
                        If column <> photoColumn Then
                            builder.Append("<TD>" + myReader.GetName(column) + "</TD><TD>" + myReader.GetValue(column).ToString() + "</TD>")
                        End If
                    Next
                    builder.Append("</TR>")
                End While
                builder.Append("</TABLE>")
            Catch e As Exception
                builder.Append("<BR/>" + e.ToString())
            Finally
                mySqlConnection.Close()
            End Try
        End Sub

    End Class
End Namespace
