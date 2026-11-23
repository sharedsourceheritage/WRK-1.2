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

<%@ WebService Language="C#" Class="SessionService" %>

using System;
using System.Web.Services;

[WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
public class SessionService : WebService {

   //Setting EnableSession to true allows state to be persisted per Session
   [WebMethod(EnableSession=true)]
   public String UpdateSessionHitCounter() {

	//If the session hit counter is not initialized, set it to 1
        if (Session["HitCounter"] == null) {
            Session["HitCounter"] = 1;
        }
	//Else increment the session hit counter
        else {
            Session["HitCounter"] = ((int) Session["HitCounter"]) + 1;
        }

	//Return the session hit counter
        return "You have accessed this service " + Session["HitCounter"].ToString() + " times.";
   }

   //Setting EnableSession to false shows that state can also be persisted at the Application level
   [WebMethod(EnableSession=false)]
   public String UpdateApplicationHitCounter() {

	//If the application hit counter is not initialized, set it to 1
        if (Application["HitCounter"] == null) {
            Application["HitCounter"] = 1;
        }
	//Else increment the application hit counter
        else {
            Application["HitCounter"] = ((int) Application["HitCounter"]) + 1;
        }

	//Return the application hit counter
        return "You have accessed this service " + Application["HitCounter"].ToString() + " times.";
   } 
}