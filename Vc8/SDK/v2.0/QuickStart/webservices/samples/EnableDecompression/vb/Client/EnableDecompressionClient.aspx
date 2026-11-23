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

<%@ Page Language="VB" Debug="true" %>

<script runat="server">

Public Sub EnableDecompression_Click(sender As Object, E As EventArgs)
    Dim service As New EnableDecompressionService()
    'Change this URL if the location of the Web service changes 
    service.Url = "http://localhost/QuickStartv20/webservices/Samples/EnableDecompression/vb/Server/EnableDecompressionService.asmx"
    service.EnableDecompression = True
    output.Text = service.HelloWorld()
End Sub 'EnableDecompression_Click


Public Sub Reset_Click(sender As [Object], E As EventArgs)
    output.Text = ""
End Sub 'Reset_Click
    
</script>

<body>
    <form id="form1" runat="server">
        <p><font face="Verdana" size="-1">When the EnableDecompression property 
	on an instance of a client proxy class is set to true the client will 
	support decompression.</p>
        <p><input id="EnableDecompression" type="submit" value="Query Service" onserverClick="EnableDecompression_Click" runat="server" /></p>
        <p><b><font face="Verdana" size="-1">Output:</font></b> 
        <font face="Verdana" size="-1" color='red'><asp:Label id="output" text="" runat="server"/></font></p>
	<p><input id="Reset" type="submit" value="Reset" onserverClick="Reset_Click" runat="server" /></p>
    </form>
</body>
</html>
