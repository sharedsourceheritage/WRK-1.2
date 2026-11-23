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

<%@ Page Language="C#" ValidateRequest=false Debug="true" %>
<%@ Import Namespace="System.Xml" %>
<%@ Import Namespace="System.Xml.Serialization" %>
<%@ Import Namespace="System.Web" %>
<%@ Import Namespace="System.IO" %>

<script runat="server">

   public void Button1_Click(Object sender, EventArgs E)
   {
      Book book = new Book();
      book.Author = BookAuthor.Value;
      book.Title = BookTitle.Value;

      try
      {
         //First, create the xml to send using the Xml Serializer
         XmlSerializer xs = new XmlSerializer(typeof(Book), "Microsoft.Samples.Web.Services");
         StringBuilder builder = new StringBuilder();
         StringWriter writer = new StringWriter(builder);
         xs.Serialize(writer, book);
         writer.Close();
         string serializedContent = builder.ToString();
         EditXML.Text = serializedContent;
      }
      catch (Exception exception)
      {
         output.Text = "Received error: " + exception.Message;
      }   
   }

   public void Button2_Click(Object sender, EventArgs E)
   {
       string response = "";
       MessageValidationService service = new MessageValidationService();
       //Change this URL if the location of the Web service changes 
       service.Url = "http://localhost/QuickStartv20/webservices/Samples/MessageValidation/cs/Server/MessageValidationService.asmx";

       try
       {
           response = service.SendToValidator(EditXML.Text);
           output.Text = response;
       }
       catch (Exception exception)
       {
           output.Text = "Received error: " + exception.Message;
       }     
   }
    
   public void Button3_Click(Object sender, EventArgs E)
   {
      //this simply resets the sample to its original state
      BookAuthor.Value = "";
      BookTitle.Value = "";
      EditXML.Text = "";
      output.Text = "";
   }
    
</script>

<html>

<body>
   <form id="form1" runat="server">
      <font face="Verdana">
      <p><font size="-1"><b>Step 1:</b> Enter the title and author of your favorite book and then click <b>Generate XML</b>.</font></p>
      <p><b>Book Title: </b><input type=text id="BookTitle" value="" runat="server"/><br>
      <b>Book Author: </b><input type=text id="BookAuthor" value="" runat="server"/></p>
      <p><input id="GenerateButton" type="submit" value="Generate XML" onserverClick="Button1_Click" runat="server" /></p>
      <p><font size="-1"><b>Step 2:</b> Consider editing the generated XML to make it malformed or not comply with the <a href="../../Book.xsd">Book schema</a>. If you do not make any edits validation will be successful.</font></p>
      <b>Edit XML:</b><br /><asp:TextBox Rows=5 TextMode=MultiLine Height=125 Width=500 id="EditXML" Wrap=true runat=server/></p>
      <p><input id="SubmitButton" type="submit" value="Submit" onserverClick="Button2_Click" runat="server" />      
      &nbsp;&nbsp;<input id="ResetButton" type="submit" value="Reset" onserverClick="Button3_Click" runat="server" /></p>
      <p><b><font size="-1">Response (from Web service):</font></b><br> 
      <font size="-1" color='red'><asp:Label id="output" text="" runat="server"/></font></p>
      </font>
   </form>
</body>

</html>


