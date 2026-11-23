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

<%@ Webservice Language="VJ#" Class="SoapExceptionService" %>

import System.Web.Services.*;
import System.Web.Services.Protocols.*;
import System.Xml.*;

/** @attribute WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
public class SoapExceptionService 
{
   /** @attribute WebMethod() */
   public String ThrowsSoapException() throws SoapException
   {
      String myNS = "Microsoft.Samples.XmlMessaging.WebServices.SoapExceptionSample";
      //assume that there was an error validating the SOAP Message
      //the Soap Exception will report the name of the error, the line number, and the line position
      if(true)
      {
         XmlDocument doc = new XmlDocument();
         XmlNode detail = doc.CreateNode(XmlNodeType.Element, SoapException.DetailElementName.get_Name(), SoapException.DetailElementName.get_Namespace());
         
         XmlNode errorType = doc.CreateNode(XmlNodeType.Element, "ErrorType", myNS);
         errorType.set_InnerText("Validation");
         
         XmlNode lineNum = doc.CreateNode(XmlNodeType.Element, "Line", myNS);
         lineNum.set_InnerText("24");

         XmlNode linePos = doc.CreateNode(XmlNodeType.Element, "Position", myNS);
         linePos.set_InnerText("11");
         
         detail.AppendChild(errorType);
         detail.AppendChild(lineNum);
         detail.AppendChild(linePos);
         
         String errorMsg = "An error was received while processing the message (see Detail element for more information)";
         SoapException exc = new SoapException(errorMsg, SoapException.ClientFaultCode, "", detail);
         throw exc; 
      }
      return "Hello World";
   }
    
}