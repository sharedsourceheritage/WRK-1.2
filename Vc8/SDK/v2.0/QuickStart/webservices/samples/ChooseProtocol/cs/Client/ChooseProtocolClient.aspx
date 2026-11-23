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

<%@ page language="C#" debug="true" %>

<script runat="server">

    public void SOAP11_Click(Object sender, EventArgs E)
    {
        HelloWorldService service = new HelloWorldService();
		//Change this URL if the location of the Web service changes 
	service.Url = "http://localhost/QuickStartv20/webservices/Samples/ChooseProtocol/cs/Server/HelloWorldService.asmx";
		//This defines the SOAP protocol version to use (Soap 1.1 in this case)
        service.SoapVersion = System.Web.Services.Protocols.SoapProtocolVersion.Soap11;
        try
        {
            output.Text = service.HelloWorld() + " (using SOAP 1.1)";
        }
        catch (Exception exception)
        {
            output.Text = "Received error: " + exception.Message;
        }
    }

    public void SOAP12_Click(Object sender, EventArgs E)
    {
        HelloWorldService service = new HelloWorldService();
		//Change this URL if the location of the Web service changes
        service.Url = "http://localhost/QuickStartv20/webservices/Samples/ChooseProtocol/cs/Server/HelloWorldService.asmx";
        //This defines the SOAP protocol version to use (Soap 1.2 in this case)
        service.SoapVersion = System.Web.Services.Protocols.SoapProtocolVersion.Soap12;
        try
        {
            output.Text = service.HelloWorld() + " (using SOAP 1.2)";
        }
        catch (Exception exception)
        {
            output.Text = "Received error: " + exception.Message;
        }
    }
    
</script>

<body>
    <form id="form1" runat="server">
        <p><font face="Verdana" size="-1">Use SOAP 1.1 or SOAP 1.2 to make your Web service call. </p>
	<p> Modify web.config (in the 'server' subdirectory) to turn on or off Soap 1.1 and Soap 1.2.</font></p>
        <p><input id="SOAP11" type="submit" value="SOAP 1.1" onserverClick="SOAP11_Click" runat="server" /></p>
        <p><input id="SOAP12" type="submit" value="SOAP 1.2" onserverClick="SOAP12_Click" runat="server" /></p>
        <p><b><font face="Verdana" size="-1">Output:</font></b> 
        <font face="Verdana" size="-1" color='red'><asp:Label id="output" text="" runat="server"/></font></p>
    </form>
</body>
</html>
