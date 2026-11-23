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

<%@ WebService Language="VJ#" Class="HeaderService" %>

import System.*;
import System.Web.Services.*;
import System.Web.Services.Protocols.*;


     // AuthHeader class extends from SoapHeader
    public class AuthHeader extends SoapHeader {
        public String Username;
        public String Password;
    }

    /** @attribute WebService(Description="Simple sample to demonstrate use of SOAP Headers", Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
    public class HeaderService {

        public AuthHeader sHeader;

        /** @attribute WebMethod(Description="This method requires a custom soap header set by the caller") */
        /** @attribute SoapHeader("sHeader") */
        public String SecureMethod() {

            if (sHeader == null)
              return "ERROR: Please supply credentials";

            String usr = sHeader.Username;
            String pwd = sHeader.Password;

            if (AuthenticateUser(usr, pwd)) {
                 return "SUCCESS: " + usr;
            }
            else {
                 return "ERROR: Could not authenticate";
            }
        }

        private boolean AuthenticateUser(String usr, String pwd) {

            if ((usr != null)&&(pwd != null)) {
                // could query a database here for credentials...
                return true;
             }
            return false;
        }
    }

