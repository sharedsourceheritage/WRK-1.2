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

<%@ Webservice Language="VJ#" Class="BPConformance_asmx" %>

import System.Web.Services.*;
import System.Web.Services.Protocols.*;

/** Setting WebServiceBinding.ConformsTo to WsiClaims.BP10 makes the */
/** SOAP 1.1 port exposed by this service conform to the WS-I Basic Profile 1.0 */
/** Setting WebServiceBinding.EmitConformanceClaims = true emits documentation elements */
/** in the service's WSDL that indicate it is conformant to WS-I Basic Profile 1.0. These claims */
/** are not required, you can turn off conformance claims (while retaining port conformance) by */
/** setting EmitConformanceClaims = false */

/** @attribute WebServiceBinding(ConformsTo=WsiProfiles.BasicProfile1_1, EmitConformanceClaims=true) */
/** @attribute WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
public class BPConformance_asmx 
{
    /** @attribute WebMethod() */
    public String HelloWorldBP() 
    {
        String message = "'Hello World' from a Basic Profile compliant (BP-compliant) Web Service.";
        return message;
    }  
}