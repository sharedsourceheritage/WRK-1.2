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

    public void WithCredentials_Click(Object sender, EventArgs E)
    {
        UseDefaultCredentialsService service = new UseDefaultCredentialsService();
        //Change this URL if the location of the Web service changes 
        service.Url = "http://localhost/QuickStartv20/webservices/Samples/UseDefaultCredentials/cs/Server/UseDefaultCredentialsService.asmx";
        service.UseDefaultCredentials = true;
        output.Text = service.HelloWorld();
    }

    public void WithoutCredentials_Click(Object sender, EventArgs E)
    {
        UseDefaultCredentialsService service = new UseDefaultCredentialsService();
        //Change this URL if the location of the Web service changes 
        service.Url = "http://localhost/QuickStartv20/webservices/Samples/UseDefaultCredentials/cs/Server/UseDefaultCredentialsService.asmx";
        service.UseDefaultCredentials = false;
        output.Text = service.HelloWorld();
    }

    public void ResetSample_Click(Object sender, EventArgs E)
    {
        output.Text = "";
    }
    
</script>

<body>
    <form id="form1" runat="server">
        <p><font face="Verdana" size="-1">When the UseDefaultCredentials property 
	on an instance of a client proxy class is set to true the client will send 
	the default credentials to enable authentication at the service.</p>
	<p>First, try without sending credentials to a service that requires them via
	Windows authentication. This should fail (if this works properly, see the <b>Note</b> below):
        <p><input id="WithoutCredentials" type="submit" value="Try Without Credentials" onserverClick="WithoutCredentials_Click" runat="server" /></p>
	<p>Now try with sending the default credentials: 	
	<p><input id="WithCredentials" type="submit" value="Try With Credentials" onserverClick="WithCredentials_Click" runat="server" /></p>
        <p><b><font face="Verdana" size="-1">Output:</font></b> 
	<font face="Verdana" size="-1" color='red'><asp:Label id="output" text="" runat="server"/></font></p>
	<p><input id="ResetSample" type="submit" value="Reset" onserverClick="ResetSample_Click" runat="server" /></p>
	<p><b>NOTE:</b> For this sample to work as intended you must configure the 
	Application directory using the IIS Connection Manager:
	<ul>
	<li>Bring up the IIS Connection Manager by typing "inetmgr" in the Run command 
	window from the Start menu.
	<li>Find the application directory corresponding to this sample by expanding the 
	Web Sites folder and then Default Web Site.  By default, the path from there will 
	be QuickStartV20\webservices\samples\UseDefaultCredentials\ and then the language
	directory depending on your preference.  
	<li>Right click on the directory and select Properties.
	<li>Go to the Directory Security tab and click on Edit.  
	<li>Unselect "Anonymous Access" and select "Integrated Windows authentication".
	(Nothing else should be selected.) 
	<li>Click "Okay" and exit from the windows.
	</ul>
    </form>
</body>
</html>
