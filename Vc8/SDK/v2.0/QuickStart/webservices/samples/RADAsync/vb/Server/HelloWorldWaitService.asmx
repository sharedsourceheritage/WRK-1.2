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

<%@ WebService Language="VB" Class="HelloWorldWaitService" %>

Imports System.Web.Services
Imports System.Web.Services.Protocols
Imports System.Threading

<WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")> _
Public Class HelloWorldWaitService 

    <WebMethod()> _
    Public Function HelloWorld() As String 
        Thread.Sleep(5000)
        Return "Hello World"
    End Function
    
End Class 'HelloWorldWaitService
