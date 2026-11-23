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

<%@ Webservice Language="VB" Class="MessageValidationService" %>

Imports System
Imports System.Web.Services
Imports System.Web.Services.Protocols
Imports System.Xml
Imports System.Xml.Serialization
Imports System.Xml.Schema
Imports System.IO

<WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")>  _
Public Class MessageValidationService
   
   Private returnMessage As String = "Success! Validation was successful."
   
   <WebMethod()>  _
   Public Function SendToValidator(input As String) As String
      Dim tr As New XmlTextReader(input, XmlNodeType.Document, Nothing)
      Dim vr As New XmlValidatingReader(tr)
      
      Dim schemas As New XmlSchemaCollection()
      schemas.Add("Microsoft.Samples.Web.Services", "http://localhost/quickstartv20/webservices/samples/MessageValidation/Book.xsd")
      vr.Schemas.Add(schemas)
      vr.ValidationType = ValidationType.Schema
      AddHandler vr.ValidationEventHandler, AddressOf ValidationHandler
      
      Try
         While vr.Read()
         End While
      'do nothing  
      Catch exception As Exception
         returnMessage = "Failure. An Exception was received, most likely indicating malformed XML. Message: " + exception.Message
      End Try
      Return returnMessage
   End Function 'SendToValidator
   
   Public Sub ValidationHandler(sender As Object, args As ValidationEventArgs)
      returnMessage = "Failure. Validation was not successful. Message: " + args.Message
   End Sub 'ValidationHandler

End Class 'MessageValidationService