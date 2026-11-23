<!--
---------------------------------------------------------------------
  This file is part of the Microsoft .NET Framework SDK Code Samples.
 
  Copyright (C) Microsoft Corporation.  All rights reserved.
 
This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.
 
THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.
---------------------------------------------------------------------
-->

<%@ WebService Language="VB" Class="VBService.HeaderService" %>

Imports System
Imports System.Web.Services
Imports System.Web.Services.Protocols

Namespace VBService

    ' AuthHeader class extends from SoapHeader
    Public Class AuthHeader : Inherits SoapHeader
        Public Username As String
        Public Password As String
    End Class

    <WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")> _
    Public Class HeaderService

        Public sHeader As AuthHeader

        <WebMethod(), SoapHeader("sHeader")> Public Function SecureMethod() As String

            If (sHeader Is Nothing) Then
                Return "ERROR: Please supply credentials"
            End If

            Dim usr As String = sHeader.Username
            Dim pwd As String = sHeader.Password

            If (AuthenticateUser(usr, pwd)) Then
                Return "SUCCESS: " & usr

            Else
                Return "ERROR: Could not authenticate"
            End If

        End Function

        Private Function AuthenticateUser(ByVal usr As String, ByVal pwd As String) As Boolean

            If (Not (usr Is Nothing) And Not (pwd Is Nothing)) Then
                ' could query a database here for credentials...
                Return True
            End If
            Return False
        End Function

    End Class

End Namespace

