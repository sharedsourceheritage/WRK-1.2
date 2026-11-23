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

<%@ WebService Language="C#" Class="Microsoft.Samples.WebServices.SoapHeaders.HeaderService" %>

using System;
using System.Web.Services;
using System.Web.Services.Protocols;

// Note the namespace has to be different from the one used
// on the proxy dll or we get errors about AuthHeader being
// defined in multiple places.
namespace Microsoft.Samples.WebServices.SoapHeaders {

     // AuthHeader class extends from SoapHeader
    public class AuthHeader : SoapHeader {
        public string Username;
        public string Password;
    }

    [WebService(Description="Simple sample to demonstrate use of SOAP Headers", Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
    public class HeaderService {

        public AuthHeader sHeader;

        [WebMethod(Description="This method requires a custom soap header set by the caller")]
        [SoapHeader("sHeader")]
        public string SecureMethod() {

            if (sHeader == null)
              return "ERROR: Please supply credentials";

            string usr = sHeader.Username;
            string pwd = sHeader.Password;

            if (AuthenticateUser(usr, pwd)) {
                 return "SUCCESS: " + usr;
            }
            else {
                 return "ERROR: Could not authenticate";
            }
        }

        private bool AuthenticateUser(string usr, string pwd) {

            if ((usr != null)&&(pwd != null)) {
                // could query a database here for credentials...
                return true;
             }
            return false;
        }
    }
}
