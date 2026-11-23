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

<%@ Page Language="C#" Debug="true" Async="true" %>
<%@ Import Namespace="System.Threading" %>

<script runat="server">	

    public void SerialButton_Click(Object sender, EventArgs E)
    {
        HelloWorldWaitService service = new HelloWorldWaitService();
    
        //Change this URL if the location of the Web service changes 
        service.Url = "http://localhost/QuickStartv20/webservices/Samples/RADAsync/cs/Server/HelloWorldWaitService.asmx";
    
        DateTime startTime = DateTime.Now;
        //1st synchronous call (will block until call completes)
        service.HelloWorld();

        //2nd synchronous call (will block until call completes)
        service.HelloWorld();

        //we can now compute total time for two synchronous calls
        DateTime endTime = DateTime.Now;
        TimeSpan timeFromStartToEnd = endTime - startTime;	
        output.Text = "Total Time (in seconds): " + timeFromStartToEnd.TotalSeconds.ToString();
    }

    public void ParallelButton_Click(Object sender, EventArgs E)
    {
       HelloWorldWaitService service = new HelloWorldWaitService();
       //Change this URL if the location of the Web service changes 
       service.Url = "http://localhost/QuickStartv20/webservices/Samples/RADAsync/cs/Server/HelloWorldWaitService.asmx";

       //Add our callback function to the event handler
       service.HelloWorldCompleted += this.HelloWorldCompleted;

       Session["StartTime"] = DateTime.Now;

       //1st asynchronous call (will return immediately)
       service.HelloWorldAsync("first call");

       //2nd asynchronous call (will return immediately) 
       service.HelloWorldAsync("second call");

    }
    
    public void HelloWorldCompleted(object sender, HelloWorldCompletedEventArgs args)
    {    
       String whichCall = (String)args.UserState;
       //On the second call compute the total for the two (asynchronous) calls
       if (whichCall.Equals("second call"))
       {
          //we can now compute total time for two asynchronous calls
          DateTime endTime = DateTime.Now;
          DateTime startTime = (DateTime)Session["StartTime"];
          TimeSpan timeFromStartToEnd = endTime - startTime;
          output.Text = "Total Time (in seconds): " + timeFromStartToEnd.TotalSeconds;   
       }
    }

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
        <font face="Verdana" size="-1"><p>Make your Web method calls synchronously or asynchronously using the new RAD Async method calls.</p> 
        <p>Each button calls the Web method twice. The 'Serial (Sync)' button should take approximately twice as long to execute. </p></font>
        <p><input id="SerialButton" type="submit" value="Serial (Sync)" onserverClick="SerialButton_Click" runat="server" /></p>
        <p><input id="ParallelButton" type="submit" value="Parallel (Async)" onserverClick="ParallelButton_Click" runat="server" /></p>
        <p><b><font face="Verdana" size="-1">Time (seconds):</font></b> 
        <font face="Verdana" size="-1" color='red'><asp:Label id="output" text="" runat="server"/></font></p>
    </form>
</body>
</html>
