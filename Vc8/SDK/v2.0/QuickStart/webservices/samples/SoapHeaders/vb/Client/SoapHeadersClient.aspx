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

<script language="VB" runat="server">

Public Sub Page_Load(sender As Object, e As EventArgs)

   Response.Write("<font face=""verdana""><h4>Using Soap Headers for Custom Authentication</h4>")

   ' Create a new instance of the UsingSoapHeaders
   ' proxy class used to call the remote .asmx file
   Dim h As New HeaderService
   ' change this URL if the location of the Web service changes
   h.Url = "http://localhost/QuickStartv20/webservices/Samples/SoapHeaders/vb/Server/SoapHeaders.asmx"
   h.Credentials = System.Net.CredentialCache.DefaultCredentials

   ' Call the secure method without credentials
   Response.Write("<h5>First call result without SOAP Header:</h5>")
   Try
      Response.Write("<p>")
      Response.Write(h.SecureMethod())
      Response.Write("</p>")
   Catch ex As Exception
      Response.Write("<pre>")
      Response.Write(ex.StackTrace) 
      Response.Write("</pre>")
   End Try

   ' Create a new instance of the AuthHeader class
   Dim myHeader As New AuthHeader

   'WARNING: This sample is for demonstration purposes only.  Username/password information is sent in plain text,
   'which should never be done in a real application. It is not secure without modification.  
   myHeader.Username = "JaneDoe"
   myHeader.Password = "password"

   ' Set the AuthHeader public member of the
   ' UsingSoapHeaders class to myHeader
   h.AuthHeaderValue = myHeader

   ' Call the secure method with credentials
   Response.Write("<h5>Second call result with SOAP Header:</h5><p>" & h.SecureMethod() & "</p></font>")

End Sub

</script>
