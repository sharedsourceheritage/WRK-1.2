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
Imports System.Web
Imports System.Web.UI.WebControls
Imports System.Web.UI.WebControls.WebParts

Namespace Microsoft.Sample.WebParts

  Public Class TextDisplayWebPart : Inherits WebPart

    ' Constructor
    Public Sub New()

      Me.AllowClose = False
      Me.Title = "Text Display Web Part"
    End Sub

    ' Fields - Private
    Private _ContentText As String = "This Web Part displays text in this area."

    ' Properties
    <WebBrowsable()> _
    <Personalizable()> _
    Public Property ContentText() As String
      Get
        Return _ContentText
      End Get
      Set(ByVal value As String)
        _ContentText = value
      End Set
    End Property

    Public Overrides Property AllowMinimize() As Boolean
      Get
        Return False
      End Get
      Set(ByVal value As Boolean)
      End Set
    End Property

    ' Methods
    Protected Overrides Sub RenderContents(ByVal writer As System.Web.UI.HtmlTextWriter)
      Dim encodedString As String
      encodedString = HttpUtility.HtmlEncode(Me.ContentText)
      writer.Write(encodedString)
    End Sub

  End Class
End Namespace