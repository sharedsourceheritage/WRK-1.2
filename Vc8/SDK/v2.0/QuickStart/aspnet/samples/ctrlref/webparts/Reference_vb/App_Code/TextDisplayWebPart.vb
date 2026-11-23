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
Imports System.Collections.Generic
Imports System.Web
Imports System.Web.UI.WebControls
Imports System.Web.UI.WebControls.WebParts

Namespace Microsoft.Sample.WebParts

    Public Class TextDisplayWebPart
        Inherits WebPart
        ' Constructor
        Public Sub New()
            Me.AllowClose = False
            Me.Title = "Text Display Web Part"

        End Sub 'New

        ' Fields - Private
        Private _ContentText As String = "This Web Part displays text in this area."
        Private _MaxLength As Integer = -1
        Private _provider As ITextCommunication = Nothing


        'Properties

        <Personalizable(PersonalizationScope.Shared)> _
        Public Property MaxTextDisplayLength() As Integer
            Get
                Return _MaxLength
            End Get
            Set(ByVal value As Integer)
                _MaxLength = value
            End Set
        End Property

        <WebBrowsable(), Personalizable(), WebDisplayName("Content Text Property"), WebDescription("This property set the inner text of the control")> _
        Public Property ContentText() As String
            Get
                If MaxTextDisplayLength = -1 OrElse MaxTextDisplayLength >= _ContentText.Length Then
                    Return _ContentText
                ElseIf MaxTextDisplayLength > 0 Then
                    Return _ContentText.Substring(0, MaxTextDisplayLength - 1)
                Else
                    Return String.Empty
                End If
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
            Dim encodedString As String = HttpUtility.HtmlEncode(Me.ContentText)
            writer.Write(encodedString)

        End Sub 'RenderContents


        Public Overrides ReadOnly Property Verbs() As WebPartVerbCollection
            Get
                Dim saveVerb As WebPartVerb = New WebPartVerb("save", New WebPartEventHandler(AddressOf SaveData))
                saveVerb.Text = "save"
                Dim newVerbs() As WebPartVerb = {saveVerb}
                Dim wp As New WebPartVerbCollection(MyBase.Verbs, newVerbs)
                Return wp
            End Get
        End Property


        Public Sub SaveData(ByVal sender As Object, ByVal args As WebPartEventArgs)
            Me.Title = Me.Title + " Saved .."

        End Sub 'SaveData



        <ConnectionConsumer("Text Consumer")> _
        Public Sub GetInterfaceForConnection(ByVal provider As ITextCommunication)
            _provider = provider

        End Sub 'GetInterfaceForConnection


        Protected Overrides Sub OnPreRender(ByVal e As EventArgs)
            If Not (_provider Is Nothing) Then
                Me.ContentText = _provider.Text
            End If

        End Sub 'OnPreRender 
    End Class 'TextDisplayWebPart
End Namespace
