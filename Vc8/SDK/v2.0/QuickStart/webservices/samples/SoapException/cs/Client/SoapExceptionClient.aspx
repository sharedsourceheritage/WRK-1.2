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

<%@ Page Language="C#" Debug="true" %>
<%@ Import Namespace="System.Web.Services.Protocols" %>
<%@ Import Namespace="System.Xml" %>
<%@ Import Namespace="System.IO" %>

<script runat="server">

   public void Button1_Click(Object sender, EventArgs E)
   {
      SoapExceptionService service = new SoapExceptionService();
      //Change this URL if the location of the Web service changes 
      service.Url = "http://localhost/QuickStartv20/webservices/Samples/SoapException/cs/Server/SoapExceptionService.asmx";

      try
      {
          string returnValue = service.ThrowsSoapException();
      }
      catch (SoapException soapExc)
      {
          output.Text = " Received Soap Exception."; 
          message.Text = " " + soapExc.Message;
          if (soapExc.Actor == "")
             actor.Text = " (empty)";
          else 
             actor.Text = " " + soapExc.Actor;
          //write out the xml in the Detail element
          StringBuilder builder = new StringBuilder();
          StringWriter writer = new StringWriter(builder);
          XmlTextWriter xtw = new XmlTextWriter(writer);
          xtw.WriteString(soapExc.Detail.OuterXml);
          xtw.Flush();
          detail.Text = builder.ToString();
          xtw.Close();
      }
      catch (Exception exc)
      {
         output.Text = " Received exception: " + exc.Message;
         message.Text = " N/A";
         actor.Text = " N/A";
         detail.Text = " N/A";
      }
   }
   public void Reset_Click(Object sender, EventArgs E)
   {
      output.Text = "";
      message.Text = "";
      actor.Text = "";
      detail.Text = "";
   }
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


