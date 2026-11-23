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

<%@ WebService Language="C#" class="ServerInterfaceService" %>

using System;
using System.Web.Services;

[WebServiceBinding(Name="ReportDateTime", Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
public interface IReportDateTime
{
    [WebMethod]
    DateTime getCurrentDateTime();
}

[WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
public class ServerInterfaceService : IReportDateTime
{
    public DateTime getCurrentDateTime()
    {
        DateTime now = DateTime.Now;
        return now;
    }
}

