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

<%@ WebService Language="VJ#" Class="SessionService" %>

import System.*;
import System.Web.*;
import System.Web.SessionState.*;
import System.Web.Services.*;

/** @attribute WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
public class SessionService extends WebService {

   //Setting EnableSession to true allows state to be persisted per Session
   /** @attribute WebMethod(EnableSession=true) */
   public String UpdateSessionHitCounter() 
   {
        HttpSessionState session = get_Session();
	//If the session hit counter is not initialized, set it to 1
        if (session.get_Item("HitCounter") == null) 
        {
            session.set_Item("HitCounter", new Integer(1));
        }
	//Else increment the session hit counter
        else 
        {
            session.set_Item("HitCounter", new Integer(((Integer)session.get_Item(0)).intValue() + 1));
        }

	//Return the session hit counter
        return "You have accessed this service " + ((Integer)session.get_Item(0)).ToString() + " times.";
   }

   //Setting EnableSession to false shows that state can also be persisted at the Application level
   /** @attribute WebMethod(EnableSession=false) */
   public String UpdateApplicationHitCounter() 
   {
      HttpApplicationState application = get_Application();
      //If the application hit counter is not initialized, set it to 1
      if (application.get_Item("HitCounter") == null) 
      {
         application.set_Item("HitCounter", new Integer(1));
      }
      //Else increment the application hit counter
      else 
      {
         application.set_Item("HitCounter", new Integer(((Integer)application.get_Item(0)).intValue() + 1));
      }

      //Return the application hit counter
      return "You have accessed this service " + ((Integer)application.get_Item(0)).ToString() + " times.";
   } 
}