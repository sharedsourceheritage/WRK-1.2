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

<%@ Webservice Language="VJ#" Class="MessageValidationService" %>

import System.*;
import System.Web.Services.*;
import System.Web.Services.Protocols.*;
import System.Xml.*;
import System.Xml.Serialization.*;
import System.Xml.Schema.*;
import System.IO.*;

/** @attribute WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
public class MessageValidationService {

   private String returnMessage = "Success! Validation was successful.";
    
   /** @attribute WebMethod() */
   public String SendToValidator(String input) 
   {
      XmlTextReader tr = new XmlTextReader(input, XmlNodeType.Document, null);
      XmlValidatingReader vr = new XmlValidatingReader(tr);

      XmlSchemaCollection schemas = new XmlSchemaCollection();
      schemas.Add("Microsoft.Samples.Web.Services", "http://localhost/quickstartv20/webservices/samples/MessageValidation/Book.xsd");
      vr.get_Schemas().Add(schemas); 
      vr.set_ValidationType(ValidationType.Schema);
      vr.add_ValidationEventHandler(new ValidationEventHandler(ValidationHandler));

      try
      {
          while (vr.Read())
          {
              //do nothing  
          }
      }
      catch (Exception exception)
      {
          return "Failure. An Exception was received, most likely indicating malformed XML. Message: " + exception.get_Message();
      }
      return returnMessage;       
   }

   public void ValidationHandler(Object sender, ValidationEventArgs args)
   {
      returnMessage = "Failure. Validation was not successful. Message: " + args.get_Message();   
   }   
}