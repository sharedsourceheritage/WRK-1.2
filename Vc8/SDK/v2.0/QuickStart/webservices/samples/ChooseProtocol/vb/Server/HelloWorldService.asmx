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

<%@ WebService Language="VB" Class="VBService.HelloWorldService" Debug="true" %>

Imports System
Imports System.Web.Services
Imports System.Web.Services.Protocols

Namespace VBService

    <WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")> _
    Public Class HelloWorldService : Inherits WebService
   
        <WebMethod()> Public Function HelloWorld() As String
            Return "Hello World"
        End Function 'HelloWorld
   
    End Class 'HelloWorldService 

End Namespace