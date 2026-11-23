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
<%@ Import Namespace="System.Web.Services.Protocols" %>
<%@ Import Namespace="System.Xml" %>
<%@ Import Namespace="System.IO" %>

<script runat="server">

Public Sub Button1_Click(sender As [Object], E As EventArgs)
   Dim service As New SoapExceptionService()
   'Change this URL if the location of the Web service changes 
   service.Url = "http://localhost/QuickStartv20/webservices/Samples/SoapException/vb/Server/SoapExceptionService.asmx"
   
   Try
      Dim returnValue As String = service.ThrowsSoapException()
   Catch soapExc As SoapException
      output.Text = " Received Soap Exception."
      message.Text = " " + soapExc.Message
      If soapExc.Actor = "" Then
         actor.Text = " (empty)"
      Else
         actor.Text = " " + soapExc.Actor
      End If 'write out the xml in the Detail element
      Dim builder As New StringBuilder()
      Dim writer As New StringWriter(builder)
      Dim xtw As New XmlTextWriter(writer)
      xtw.WriteString(soapExc.Detail.OuterXml)
      xtw.Flush()
      detail.Text = builder.ToString()
      xtw.Close()
   Catch exc As Exception
      output.Text = " Received exception: " + exc.Message
      message.Text = " N/A"
      actor.Text = " N/A"
      detail.Text = " N/A"
   End Try
End Sub 'Button1_Click

Public Sub Reset_Click(sender As [Object], E As EventArgs)
   output.Text = ""
   message.Text = ""
   actor.Text = ""
   detail.Text = ""
End Sub 'Reset_Click

</script>

<html>

<body>
   <form id="form1" runat="server">
      <font face="Verdana" size="-1"><p>The service throws a SoapException. This client outputs the information contained within the Soap Exception.</p>
      <p>
      <input id="Button1" type="submit" value="Call Web Service" onserverClick="Button1_Click" runat="server" />
      <input id="Submit1" type="submit" value="Reset" onserverClick="Reset_Click" runat="server" />
      </p>
      <p><b>Output:</b><font color='red'><asp:Label id="output" text="" runat="server"/></font>
      <br><b>Message:</b><font color='red'><asp:Label id="message" text="" runat="server"/></font>
      <br><b>SOAP Actor:</b><font color='red'><asp:Label id="actor" text="" runat="server"/></font>
      <br><b>Detail Element:</b><br /><font color='red'><asp:Label id="detail" text="" runat="server"/></font></p>
      </font>
   </form>
</body>

</html>


