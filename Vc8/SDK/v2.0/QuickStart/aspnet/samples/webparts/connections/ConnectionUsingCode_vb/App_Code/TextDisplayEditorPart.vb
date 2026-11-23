
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
Imports System.Web.UI
Imports System.Web.UI.WebControls
Imports System.Web.UI.WebControls.WebParts

Namespace Microsoft.Sample.WebParts

    Public Class TextDisplayEditorPart : Inherits EditorPart 

        Public Sub New()
      Me.Title = "Text Editor Part"

        End Sub 'New

        Private PartPropertyValue As TextBox
        Private _displayErrorMessage As Boolean = False



        Protected Overrides Sub CreateChildControls()
            Controls.Clear()
            PartPropertyValue = New TextBox()
            Me.Controls.Add(PartPropertyValue)

        End Sub 'CreateChildControls


        Public Overrides Sub SyncChanges()
            EnsureChildControls()
            Dim tp As TextDisplayWebPart
            tp = CType(WebPartToEdit, TextDisplayWebPart)
            If Not (tp Is Nothing) Then
                PartPropertyValue.Text = Convert.ToString(tp.MaxTextDisplayLength)
            End If

        End Sub 'SyncChanges


        Protected Overrides Sub RenderContents(ByVal writer As HtmlTextWriter)
            writer.AddAttribute(HtmlTextWriterAttribute.Border, "0")
            writer.AddAttribute(HtmlTextWriterAttribute.Cellspacing, "4")

            writer.RenderBeginTag(HtmlTextWriterTag.Table)
            writer.RenderBeginTag(HtmlTextWriterTag.Tr)
            writer.RenderBeginTag(HtmlTextWriterTag.Td)

      writer.Write("Text Length :")
            writer.WriteBreak()
            Me.PartPropertyValue.RenderControl(writer)

            If _displayErrorMessage Then
                writer.WriteBreak()
                Dim errorMessage As New Label()
                errorMessage.Text = "Error converting type"
                errorMessage.ApplyStyle(Me.Zone.ErrorStyle)
                errorMessage.RenderControl(writer)
            End If

            writer.RenderEndTag() ' Td
            writer.RenderEndTag() ' Tr
            writer.RenderEndTag()
            ' Table
        End Sub 'RenderContents


        Public Overrides Function ApplyChanges() As Boolean
            EnsureChildControls()
            Dim tp As TextDisplayWebPart
            tp = CType(WebPartToEdit, TextDisplayWebPart)
            If Not (tp Is Nothing) AndAlso Not String.IsNullOrEmpty(PartPropertyValue.Text) Then
                Try
                    tp.MaxTextDisplayLength = Convert.ToInt32(PartPropertyValue.Text)
                Catch
                    _displayErrorMessage = True
                    Return False
                End Try
            End If
            Return True

        End Function 'ApplyChanges
    End Class 'TextDisplayEditorPart
End Namespace