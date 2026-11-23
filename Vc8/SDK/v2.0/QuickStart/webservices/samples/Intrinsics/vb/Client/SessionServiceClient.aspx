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

<%@ Page Language="VB" Debug="True" %>
 
<html>
<style>

    div
    {
        font: 8pt verdana;
        background-color:cccccc;
        border-color:black;
        border-width:1;
        border-style:solid;
        padding:10,10,10,10;
    }

</style>
<script language="VB" runat="server">

    Public Sub Page_Load(Sender As Object, E As EventArgs)

        'Create a new instance of the proxy class
        Dim sessionService As SessionService = New SessionService()
        'Change this URL if the location of the Web service changes
        sessionService.Url = "http://localhost/QuickStartv20/webservices/Samples/Intrinsics/vb/server/SessionService.asmx"
	'You must set the web service proxy's CookieContainer property to a new instance 
	'of System.Net.CookieContainer to enable session state
	sessionService.CookieContainer = new System.Net.CookieContainer()

        'Make three calls to the service to increment the session hit counter
        'The session hit counter can only be incremented in this session
        'If you open the client in a new browser, the hit counter is back to zero        
        Message1.InnerHtml = sessionService.UpdateSessionHitCounter() & "<BR>" & _
        sessionService.UpdateSessionHitCounter() & "<BR>" & sessionService.UpdateSessionHitCounter()
        
        'Make three calls to the service to increment the application hit counter
        'The application hit counter will be incremented by all sessions
        'If you open the client in a new browser, both sessions will increment the hit counter
        Message2.InnerHtml = sessionService.UpdateApplicationHitCounter() & "<BR>" & _
            sessionService.UpdateApplicationHitCounter() & "<BR>" & sessionService.UpdateApplicationHitCounter()
    End Sub

</script>
<body style="font: 10pt verdana">
<H4>Using Intrinsics with XML Web services</H4>

  <h5>UpdateHitCounter Output: </h5>
  <div id="Message1" runat="server"/>

  <h5>UpdateAppCounter Output: </h5>
  <div id="Message2" runat="server"/>

</body>
</html>


