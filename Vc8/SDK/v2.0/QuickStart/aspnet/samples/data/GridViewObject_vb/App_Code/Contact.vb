
'-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET SDK Code Samples.
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
Imports System.Configuration
Imports System.Web
Imports System.Web.Security
Imports System.Web.UI
Imports System.Web.UI.WebControls
Imports System.Web.UI.WebControls.WebParts
Imports System.Web.UI.HtmlControls

' <summary>
' Summary description for Contact
' </summary>
Public Class Contact

    Private _contactID As Integer

    Public Property ContactID() As Integer
        Get
            Return _contactID
        End Get
        Set(ByVal value As Integer)
            _contactID = value
        End Set
    End Property

    Private _contactName As String

    Public Property ContactName() As String
        Get
            Return _contactName
        End Get
        Set(ByVal value As String)
            _contactName = value
        End Set
    End Property

    Public Sub New()

        '
        ' TODO: Add constructor logic here
        '
    End Sub

    Public Sub New(ByVal ContactID As Integer, ByVal ContactName As String)

        _contactID = ContactID
        _contactName = ContactName
    End Sub
End Class
