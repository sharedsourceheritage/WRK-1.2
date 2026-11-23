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

<%@ WebService Language="VB" class="ServerInterfaceService" %>

Imports System
Imports System.Web.Services

<WebServiceBinding(Name:="ReportDateTime", Namespace:="Microsoft.Samples.XmlMessaging.WebServices")>  _
Public Interface IReportDateTime

    <WebMethod()>  _
    Function getCurrentDateTime() As DateTime

End Interface 'IReportDateTime

<WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")>  _
Public Class ServerInterfaceService
    Implements IReportDateTime
   
    Public Function getCurrentDateTime() As DateTime Implements IReportDateTime.getCurrentDateTime
        Dim now As DateTime = DateTime.Now
        Return now
    End Function 'getCurrentDateTime

End Class 'ServerInterfaceService

