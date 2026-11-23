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

<%@ Page Language="VB" Debug="true" Async="true" %>
<%@ Import Namespace="System.Threading" %>

<script runat="server">

Public Sub SerialButton_Click(sender As Object, E As EventArgs)
    Dim service As New HelloWorldWaitService()
    'Change this URL if the location of the Web service changes 
    service.Url = "http://localhost/QuickStartv20/webservices/Samples/RADAsync/vb/Server/HelloWorldWaitService.asmx"
   
    Dim startTime As DateTime = DateTime.Now
    '1st synchronous call (will block until call completes)
    service.HelloWorld()
    '2nd synchronous call (will block until call completes)
    service.HelloWorld()
    Dim endTime as DateTime = DateTime.Now
    Dim timeFromStartToEnd As TimeSpan = endTime - startTime
   
    output.Text = "Total Time (in seconds): " + timeFromStartToEnd.TotalSeconds.ToString()
End Sub 'SerialButton_Click
 

Public Sub ParallelButton_Click(sender As [Object], E As EventArgs)
    Dim service As New HelloWorldWaitService()
    'Change this URL if the location of the Web service changes 
    service.Url = "http://localhost/QuickStartv20/webservices/Samples/RADAsync/vb/Server/HelloWorldWaitService.asmx"
   
    'Add our callback function to the event handler
    AddHandler service.HelloWorldCompleted, AddressOf Me.HelloWorldCompleted
   
    Session("startTime") = DateTime.Now
    '1st asynchronous call (will return immediately)
    service.HelloWorldAsync("first call")
    '2nd asynchronous call (will return immediately)
    service.HelloWorldAsync("second call")
   
End Sub 'ParallelButton_Click

Public Sub HelloWorldCompleted(sender As Object, args As HelloWorldCompletedEventArgs)

    Dim endTime As DateTime = DateTime.Now
    Dim startTime As DateTime = Session("startTime")
    Dim timeFromStartToEnd As TimeSpan = endTime - startTime
    output.Text = "Total Time (in seconds): " & timeFromStartToEnd.TotalSeconds

End Sub 'HelloWorldCompleted

</script>

<script language="JavaScript">
<!--
    function doHourglass()
    {
        document.body.style.cursor = 'wait';
    }
-->
</script>

<body onbeforeunload="doHourglass();" onunload="doHourglass();">
    <form id="form1" runat="server">
        <font face="Verdana" size="-1"><p>Make your Web method calls synchronously or asynchronously using the new RAD Async method calls. </p></font>
        <p><input id="SerialButton" type="submit" value="Serial (Sync)" onserverClick="SerialButton_Click" runat="server" /></p>
        <p><input id="ParallelButton" type="submit" value="Parallel (Async)" onserverClick="ParallelButton_Click" runat="server" /></p>
        <p><b><font face="Verdana" size="-1">Time (seconds):</font></b> 
        <font face="Verdana" size="-1" color='red'><asp:Label id="output" text="" runat="server"/></font></p>
    </form>
</body>
</html>
