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

<%@ Webservice Language="VB" Class="VBService.BPConformance_asmx" %>

Imports System.Web.Services 
Imports System.Web.Services.Protocols
 
' Setting WebServiceBinding.ConformanceClaims to WsiClaims.BP10 makes the 
' SOAP 1.1 port exposed by this service conform to the WS-I Basic Profile 1.0
' Setting WebServiceBinding.EmitConformanceClaims = true emits documentation elements
' in the service's WSDL that indicate it is conformant to WS-I Basic Profile 1.0. These claims 
' are not required, you can turn off conformance claims (while retaining port conformance) by 
' setting EmitConformanceClaims = false

Namespace VBService

<WebServiceBinding(ConformsTo:=WsiProfiles.BasicProfile1_1, EmitConformanceClaims:=True)> _
<WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")> _
Public Class BPConformance_asmx
      
    <WebMethod> _
    Public Function HelloWorldBP() As String
        Dim message As String = "'Hello World' from a Basic Profile compliant (BP-compliant) Web Service."
        Return message
    End Function 'HelloWorld

End Class 'BPConformance_asmx

End Namespace