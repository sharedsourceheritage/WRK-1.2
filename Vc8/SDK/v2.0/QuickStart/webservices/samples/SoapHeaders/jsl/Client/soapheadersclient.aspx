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
<%@ Import Namespace="System.Net" %>

<script language="VJ#" runat="server">

public void Page_Load(Object sender, EventArgs e) {

    // Create a new instance of the UsingSoapHeaders
    // proxy class used to call the remote .asmx file
    HeaderService h = new HeaderService();
    //change this URL if the location of the Web service changes
    h.set_Url("http://localhost/QuickStartv20/webservices/Samples/SoapHeaders/jsl/Server/SoapHeaders.asmx");
    h.set_Credentials(System.Net.CredentialCache.get_DefaultCredentials());

    // Call the secure method without credentials
    try 
    {
        output1.set_Text(h.SecureMethod());
    }
    catch (Exception ex) 
    {
        output1.set_Text("<pre>" + ex.get_StackTrace() + "</pre>");
    }

    // Create a new instance of the AuthHeader class
    AuthHeader myHeader = new AuthHeader();


    //WARNING: This sample is for demonstration purposes only.  Username/password information is sent in plain text,
    //which should never be done in a real application. It is not secure without modification.  
    myHeader.set_Username("JaneDoe");
    myHeader.set_Password("password");

    // Set the AuthHeader public member of the
    // UsingSoapHeaders class to myHeader
    h.set_AuthHeaderValue(myHeader);

    // Call the secure method with credentials
    try 
    {
        output2.set_Text(h.SecureMethod());
    }
    catch (Exception ex) 
    {
        output2.set_Text("<pre>" + ex.get_StackTrace() + "</pre>");
    }    
}

</script>

<html>

<body>
<font face='verdana'>
<h4>Using Soap Headers for Custom Authentication</h4>
<h5>First call result without SOAP Header: </h5>
<p><asp:Label id="output1" text="" runat="server"/></p>
<h5>Second call result with SOAP Header: </h5>
<p><asp:Label id="output2" text="" runat="server"/></p>
</font>
</body>

</html>