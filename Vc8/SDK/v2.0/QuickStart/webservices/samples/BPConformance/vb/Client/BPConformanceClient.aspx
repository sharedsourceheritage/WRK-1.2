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

<%@ page language="VB"%>

<script runat="server">

Public Sub Page_Load(sender As [Object], E As EventArgs)
   'Create a new instance of the proxy class
   Dim bpService As New BPConformance_asmx()
   'Change this URL if the location of the Web service changes
   bpService.Url = "http://localhost/QuickStartv20/webservices/Samples/BPConformance/vb/server/bpconformance.asmx"
   'Call the WS-I BP 1.1-compliant Web service
   ServiceOutput.InnerText = bpService.HelloWorldBP()
End Sub 'Page_Load
    
</script>

<html>
<head runat="server">
    <title>BP 1.1 Conformance Sample</title>
</head>
<body>
<form id="form1" runat="server">
<p><font size='+1' face='verdana' color='red'><span id='ServiceOutput' runat='server'></span></font></p>
</form>
</body>
</html>
