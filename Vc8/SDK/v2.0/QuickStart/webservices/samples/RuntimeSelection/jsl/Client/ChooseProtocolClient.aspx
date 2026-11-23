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

<%@ Page Language="VJ#" Debug="true" %>

<script runat="server">

   public void Hello_Click(Object sender, EventArgs E)
   {
      HelloWorldService service = new HelloWorldService();
      //Change the location of the Web service in machine.config if desired
      service.set_Url(System.Configuration.ConfigurationSettings.get_AppSettings().get_Item("WSUrl"));
      output.set_Text(service.HelloWorld());
   }

   public void Reset_Click(Object sender, EventArgs E)
   {
      output.set_Text("");
   }
    
</script>

<body>
    <form id="form1" runat="server">
        <font face="Verdana" size="-1">
        <p>Modify web.config (in the 'client' subdirectory) to change the service used by the client. The client will change services at runtime.</p>
	<p>For example, you could implement your own "Hello World" Web service and tell your client to use it. Or point to the Hello World service in the 'ChooseProtocol' sample.</p>
        <p><input id="hello" type="submit" value="Submit" onserverClick="Hello_Click" runat="server" /> &nbsp;&nbsp;
        <input id="reset" type="submit" value="Reset Sample" onserverClick="Reset_Click" runat="server" /></p>
        <p><b>Output:</b> 
        <font color='red'><asp:Label id="output" text="" runat="server"/></font></p>
        <p>NOTE: In the wsdl file the service is indicated at the wrong location. The config settings will override this.</p>
        </font>
    </form>
</body>
</html>


