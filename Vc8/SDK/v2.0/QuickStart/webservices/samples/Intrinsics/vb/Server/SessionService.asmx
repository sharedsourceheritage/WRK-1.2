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

<%@ WebService Language="VB" Class="VBService.SessionService" %>

Imports System
Imports System.Web.Services

Namespace VBService

    <WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")> _
    Public Class SessionService : Inherits WebService

        'Setting EnableSession to true allows state to be persisted per Session
        <WebMethod(EnableSession:=True)> Public Function UpdateSessionHitCounter() As String

            'If the session hit counter is not initialized, set it to 1
            If Session("HitCounter") Is Nothing Then
                Session("HitCounter") = 1
                
                'Else increment the session hit counter
            Else
                Session("HitCounter") = CInt(Session("HitCounter")) + 1
            End If
            
            'Return the session hit counter
            Return "You have accessed this service " & Session("HitCounter").ToString() & " times."
        End Function

        'Setting EnableSession to false shows that state can also be persisted at the Application level
        <WebMethod(EnableSession:=False)> Public Function UpdateApplicationHitCounter() As String

            'If the application hit counter is not initialized, set it to 1
            If Application("HitCounter") Is Nothing Then
                Application("HitCounter") = 1
                'Else increment the application hit counter
            Else
                Application("HitCounter") = CInt(Application("HitCounter")) + 1
            End If

            'Return the application hit counter
            Return "You have accessed this service " & Application("HitCounter").ToString() & " times."
        End Function

    End Class
    
End Namespace 

    