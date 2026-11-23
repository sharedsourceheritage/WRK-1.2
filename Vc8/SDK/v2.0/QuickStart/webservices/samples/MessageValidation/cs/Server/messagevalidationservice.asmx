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

<%@ Webservice Language="C#" Class="MessageValidationService" %>

using System;
using System.Web.Services;
using System.Web.Services.Protocols;
using System.Xml;
using System.Xml.Serialization;
using System.Xml.Schema;
using System.IO;

[WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
public class MessageValidationService {

   private string returnMessage = "Success! Validation was successful.";
    
   [WebMethod]
   public string SendToValidator(string input) 
   {
      XmlTextReader tr = new XmlTextReader(input, XmlNodeType.Document, null);
      XmlValidatingReader vr = new XmlValidatingReader(tr);

      XmlSchemaCollection schemas = new XmlSchemaCollection();
      schemas.Add("Microsoft.Samples.Web.Services", "http://localhost/quickstartv20/webservices/samples/MessageValidation/Book.xsd");
      vr.Schemas.Add(schemas); 
      vr.ValidationType = ValidationType.Schema;
      vr.ValidationEventHandler += new ValidationEventHandler (ValidationHandler);

      try
      {
          while (vr.Read())
          {
              //do nothing  
          }
      }
      catch (Exception exception)
      {
          returnMessage = "Failure. An Exception was received, most likely indicating malformed XML. Message: " + exception.Message;
      }
      return returnMessage;       
   }

   public void ValidationHandler(object sender, ValidationEventArgs args)
   {
      returnMessage = "Failure. Validation was not successful. Message: " + args.Message;   
   }   
}