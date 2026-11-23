<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Monitoring Your Application</h2>

<div class="new">

<h3>What's New in 2.0</h3>

ASP.NET 2.0 provides more integrated tracing and instrumentation functionality to enable administrators to better diagnose and fix problems within the application. The new runtime instrumentation features also allow constant monitoring of the applications runtime health and performance while it is operational. 

<ul>
  <li><b>Integration of ASP.NET Trace and System.Diagnostics.Trace - </b> This feature allows ASP.NET trace messages to be directed to System.Diagnostics.Trace, and System.Diagnostics.Trace messages to be displayed in the ASP.NET Trace. </li>
  <br /><br />
  <li><b>Programmatic Consumption of ASP.NET Trace Messages - </b> This feature allows page designers to obtain trace messages and do custom processing/route them to another destination as appropriate.</li>
  <br /><br />
  <li><b>Web Events - </b> This powerful feature enables ASP.NET and custom code to emit events containing useful information about the health and various actions in the system to configurable event consumers.</li>
</ul>

This section discusses these and other monitoring features in ASP.NET 2.0.

</div>

<br /><br />
ASP.NET provides a number of ways to monitor the application and diagnose various problems that may arise during its development and operation.  Some of these mechanisms are better suited for development-time debugging of the application code, others for monitoring the health and performance of the application when it is deployed, and yet others for diagnosing and investigating problems when they occur.  The mechanisms are outlined in the table below.
<br /><br />

<table class="table">
  <tr>
    <th width="20%">Feature</th>
    <th>Description</th>
  </tr>
  <tr>
    <td><asp:HyperLink NavigateUrl="~/aspnet/doc/monitoring/tracing.aspx" runat="server">ASP.NET Trace</asp:HyperLink></td>
    <td>
      The ASP.NET trace is generated during the execution of an ASP.NET page, and captures various interesting details about the request, page control tree, and execution of various stages of the page lifecycle and controls, and also custom messages that can be written to the trace by the page developer.  The trace can be either appended to the response output of the page being traced, or examined as part of the list of traced requests in the application trace viewer.  
      <br /><br />
      This feature is primarily intended for development time debugging scenarios, and should not be used for production deployments.
      <br /><br />
      In ASP.NET 2.0, this feature has been upgraded to allow integration with the .NET framework standard tracing facility, the System.Diagnostics.Trace class in order to be able to consume trace information emitted by .NET components, and also provide ASP.NET tracing information through the standard framework trace facility. 
    </td>
  </tr>
  <tr>
    <td><asp:HyperLink NavigateUrl="~/aspnet/doc/monitoring/errors.aspx" runat="server">ASP.NET Error Handling</asp:HyperLink></td>
    <td>
      The error handling infrastructure in ASP.NET allow application code to track and report application errors, in a way that is most appropriate to the application.
      <br /><br />
      This is frequently used to both control the information shown to the client when a request encounters an error, and also record the error or notify the administrator when such an error occurs.  When used on production servers, error handling should be configured not to expose error details to the client.
    </td>
  </tr>
  <tr>
    <td><asp:HyperLink NavigateUrl="~/aspnet/doc/monitoring/webevents.aspx" runat="server">Health Monitoring with Web Events</asp:HyperLink></td>
    <td>
      ASP.NET 2.0 introduces a very powerful model for runtime instrumentation of applications, based on the Web Event feature.  The Web Event feature allows events to be generated during the lifetime of the application, and provides configuration rules to filter and direct these events to one of the ASP.NET built in or custom consumers.  This flexible model provides powerful functionality intended to accommodate production monitoring scenarios, and supports advanced extensibility to enable the application to provide its own event formats, instrument custom code, and send the events to custom consumer implementations.
      <br /><br />
      ASP.NET 2.0 itself leverages the Web Event feature to instrument the infrastructure with a number of system events that can be managed just like a custom application event and provide useful state information about the ASP.NET application.
      <br /><br />
      Health monitoring is intended for monitoring and diagnosing problems in production applications.
    </td>
  </tr>
  <tr>
    <td><b>Event Log</b></td>
    <td>
      ASP.NET writes messages to the event log in certain conditions in which ASP.NET infrastructure encounters a fatal failure, such as when it does not have access to required resources, or is unable to create worker processes to host ASP.NET applications.  
      <br /><br />
      The information in these events may be used to solve such problems, especially when first deploying ASP.NET applications to new machines where permission and installation issues may exist.
    </td>
  </tr>
  <tr>
    <td><b>Performance Counters</b></td>
    <td>
      ASP.NET provides a number of performance counters that can be used very effectively to monitor the health and performance of the application at a high level, to get a better idea of performance and functional issues before zeroing in on them via the other instrumentation mechanisms.
      <br /><br />
      This feature is intended for high level monitoring in both the development and production scenarios, and should be the first step in predicting and diagnosing problems.
      <br /><br />
      ASP.NET 2.0 provides a number of new performance counters that describe the operation of new features.
    </td>
  </tr>
</table>
<br />

This section describes how you can take advantage of features like tracing, error handling and web events for this purpose.

</asp:Content>

