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
        <WebDisplayName("Content Text Property")> _
        <WebDescription("Change the information display by the Web Part")> _
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

        Public Overrides ReadOnly Property Verbs() As WebPartVerbCollection

            Get
                Dim saveVerb As WebPartVerb = New WebPartVerb("save", New WebPartEventHandler(AddressOf SaveData))
                saveVerb.Text = "Save"
                Dim newVerbs(0) As WebPartVerb
                newVerbs(0) = saveVerb
                Dim wp As WebPartVerbCollection = New WebPartVerbCollection(MyBase.Verbs, newVerbs)
                Return wp
            End Get
        End Property

        Public Sub SaveData(ByVal sender As Object, ByVal args As WebPartEventArgs)
            Me.Title = Me.Title + " Saved .."
        End Sub

    End Class
End Namespace
