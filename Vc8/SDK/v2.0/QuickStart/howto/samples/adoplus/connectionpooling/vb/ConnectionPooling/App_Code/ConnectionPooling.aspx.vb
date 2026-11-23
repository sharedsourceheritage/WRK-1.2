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
Imports Microsoft.VisualBasic
Imports System.Text

Namespace Microsoft.Samples.HowTo.ADONET
    Public Class ConnectionPooling
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
            Try

                Dim connString As String

                ' Specification in the connection string:
                ' Please note: Pooling is implicit, you automatically get it unless you disable it. 
                '              Therefore, "true" is the default for the pooling keyword (pooling=true).   
                ' Connection Reset:    False
                ' Connection Lifetime: 5
                ' Enlist:              true
                ' Min Pool Size:       1
                ' Max Pool Size:       50
                connString = "server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind;" & _
                             "connection reset=false;" & _
                             "connection lifetime=5;" & _
                             "enlist=true;" & _
                             "min pool size=1;" & _
                             "max pool size=50"

                Dim myConnection1 As SqlConnection = New SqlConnection(connString)
                Dim myConnection2 As SqlConnection = New SqlConnection(connString)
                Dim myConnection3 As SqlConnection = New SqlConnection(connString)

                ' Open two connections. 
                builder.Append("<BR/>Open two connections.")
                myConnection1.Open()
                myConnection2.Open()

                ' Now there are two connections in the pool that matches the connection string.
                ' Return the both connections to the pool. 
                builder.Append("<BR/>Return both of the connections to the pool.")
                myConnection1.Close()
                myConnection2.Close()

                ' Get a connection out of the pool.
                builder.Append("<BR/>Open a connection from the pool.")
                myConnection1.Open()

                ' Get a second connection out of the pool.
                builder.Append("<BR/>Open a second connection from the pool.")
                myConnection2.Open()

                ' Open a third connection.
                builder.Append("<BR/>Open a third connection.")
                myConnection3.Open()

                ' Return the all connections to the pool.  
                builder.Append("<BR/>Return all three connections to the pool.")
                myConnection1.Close()
                myConnection2.Close()
                myConnection3.Close()

            Catch e As Exception
                ' Display the error.
                builder.Append("<BR/>" + e.ToString())
            End Try

        End Sub
    End Class
End Namespace
