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

    public void DateTime_Click(Object sender, EventArgs E)
    {
        ServerInterfaceService service = new ServerInterfaceService();
	//Change this URL if the location of the Web service changes 
	service.set_Url("http://localhost/QuickStartv20/webservices/samples/ServerInterface/jsl/Server/serverinterface.asmx");

	DateTime currentTime = (DateTime)service.getCurrentDateTime();
        output.set_Text("Time is " + currentTime.get_TimeOfDay() + ", Date is " + currentTime.get_Date());
    }
    
</script>

<body>
    <form id="form1" runat="server">
        <p><font face="Verdana" size="-1">Call a Web service implemented using the new Server Interface feature </p>
        <p><input id="DateTime" type="submit" value="Get Current DateTime" onserverClick="DateTime_Click" runat="server" /></p>
        <p><b><font face="Verdana" size="-1">Output:</font></b> 
        <font face="Verdana" size="-1" color='red'><asp:Label id="output" text="" runat="server"/></font></p>
    </form>
</body>
</html>
