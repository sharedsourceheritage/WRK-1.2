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

<%@ webservice language="C#" class="HelloWorldWaitService" %>

using System.Web.Services;
using System.Web.Services.Protocols;
using System.Threading;

[WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
public class HelloWorldWaitService {

    [WebMethod]
    public string HelloWorld() {
        Thread.Sleep(5000);
        return "Hello World";
    }
    
}