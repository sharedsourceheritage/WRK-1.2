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
Partial Class CallBackEventHandler_vb
    Inherits System.Web.UI.Page
    Implements ICallbackEventHandler

    Private _callBackResult As String

    Private Sub Page_Load(ByVal source As Object, ByVal e As System.EventArgs)

        Dim callBack As String = Page.ClientScript.GetCallbackEventReference(Me, "arg", "ClientCallback", "context", "ClientCallbackError", False)
        Dim clientFunction As String = "function GetChildren(arg, context){ " & callBack & "; }"
        Page.ClientScript.RegisterClientScriptBlock(Me.GetType(), "GetChildren", clientFunction, True)

        If Page.IsPostBack AndAlso Not Page.IsCallback Then

            Label1.Text = "You Selected: " & Request.Form("ParentDropDown") & ": " & Request.Form("ChildDropDown")
        End If
    End Sub

    Public Sub RaiseCallbackEvent(ByVal eventArgument As String) Implements System.Web.UI.ICallbackEventHandler.RaiseCallbackEvent
        Select Case eventArgument

            Case "Item 1"
                _callBackResult = "One|Two|Three"
            Case "Item 2"
                _callBackResult = "Four|Five|Six"
            Case "Item 3"
                _callBackResult = "Seven|Eight|Nine"
            Case Else
                _callBackResult = ""
        End Select
    End Sub

    Public Function GetCallbackResult() As String Implements System.Web.UI.ICallbackEventHandler.GetCallbackResult
        Return _callBackResult
    End Function
End Class
