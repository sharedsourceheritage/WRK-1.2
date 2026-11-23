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

<%@ Webservice Language="VB" Class="SoapExceptionService" %>

Imports System.Web.Services
Imports System.Web.Services.Protocols
Imports System.Xml

<WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")>  _
Public Class SoapExceptionService
      
   <WebMethod()>  _
   Public Function ThrowsSoapException() As String

      Dim myNS As String = "Microsoft.Samples.XmlMessaging.WebServices.SoapExceptionSample"

      'assume that there was an error validating the SOAP Message
      'the Soap Exception will report the name of the error, the line number, and the line position
      If True Then
         Dim doc As New XmlDocument()
         Dim detail As XmlNode = doc.CreateNode(XmlNodeType.Element, SoapException.DetailElementName.Name, SoapException.DetailElementName.Namespace)
         
         Dim errorType As XmlNode = doc.CreateNode(XmlNodeType.Element, "ErrorType", myNS)
         errorType.InnerText = "Validation"
         
         Dim lineNum As XmlNode = doc.CreateNode(XmlNodeType.Element, "Line", myNS)
         lineNum.InnerText = "24"
         
         Dim linePos As XmlNode = doc.CreateNode(XmlNodeType.Element, "Position", myNS)
         linePos.InnerText = "11"
         
         detail.AppendChild(errorType)
         detail.AppendChild(lineNum)
         detail.AppendChild(linePos)
         
         Dim errorMsg As String = "An error was received while processing the message (see Detail element for more information)"
         Dim exc As New SoapException(errorMsg, SoapException.ClientFaultCode, "", detail)
         Throw exc
      End If

      Return "Hello World"

   End Function 'ThrowsSoapException

End Class 'SoapExceptionService 