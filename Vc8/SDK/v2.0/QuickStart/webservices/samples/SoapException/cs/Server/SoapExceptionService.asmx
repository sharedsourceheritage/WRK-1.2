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

<%@ Webservice Language="C#" Class="SoapExceptionService" %>

using System.Web.Services;
using System.Web.Services.Protocols;
using System.Xml;

[WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
public class SoapExceptionService {

   [WebMethod]
   public string ThrowsSoapException() 
   {
      string myNS = "Microsoft.Samples.XmlMessaging.WebServices.SoapExceptionSample";
      //assume that there was an error validating the SOAP Message
      //the Soap Exception will report the name of the error, the line number, and the line position
      if(true)
      {
         XmlDocument doc = new XmlDocument();
         XmlNode detail = doc.CreateNode(XmlNodeType.Element, SoapException.DetailElementName.Name, SoapException.DetailElementName.Namespace);
         
         XmlNode errorType = doc.CreateNode(XmlNodeType.Element, "ErrorType", myNS);
         errorType.InnerText = "Validation";
         
         XmlNode lineNum = doc.CreateNode(XmlNodeType.Element, "Line", myNS);
         lineNum.InnerText = "24";

         XmlNode linePos = doc.CreateNode(XmlNodeType.Element, "Position", myNS);
         linePos.InnerText = "11";
         
         detail.AppendChild(errorType);
         detail.AppendChild(lineNum);
         detail.AppendChild(linePos);
         
         string errorMsg = "An error was received while processing the message (see Detail element for more information)";
         SoapException exc = new SoapException(errorMsg, SoapException.ClientFaultCode, "", detail);
         throw exc; 
      }
      return "Hello World";
   }
    
}