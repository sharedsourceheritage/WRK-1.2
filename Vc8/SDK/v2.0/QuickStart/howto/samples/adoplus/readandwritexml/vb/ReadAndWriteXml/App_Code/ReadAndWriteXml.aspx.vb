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
    Public Class ReadAndWriteXml
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
            Dim mySqlDataAdapter1 As SqlDataAdapter
            Dim mySqlDataAdapter2 As SqlDataAdapter
            Dim myDataSet As DataSet

            myConnection = New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
            mySqlDataAdapter1 = New SqlDataAdapter("select * from customers", myConnection)
            mySqlDataAdapter2 = New SqlDataAdapter("select * from orders", myConnection)

            myDataSet = New DataSet
            Try
                mySqlDataAdapter1.Fill(myDataSet, "Customers")
                mySqlDataAdapter2.Fill(myDataSet, "Orders")

                Dim strXMLData As String
                Dim strXMLSchema As String

                strXMLData = myDataSet.GetXml()
                strXMLSchema = myDataSet.GetXmlSchema()


                builder.Append("Select View Source to see XMLSchema <BR/>")
                builder.Append(strXMLSchema + "<BR/>")
                builder.Append("<BR/>")
                builder.Append("Data <BR/>")
                builder.Append(strXMLData + "<BR/>")


            Catch e As Exception
                builder.Append("<BR/>" + e.ToString())
            Finally
                myConnection.Close()
            End Try
        End Sub
    End Class
End Namespace
