<%@ Page Language="C#" MasterPageFile="~/aspnet/aspnet.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Monitoring Your Application</h2>

ASP.NET 2.0 provides more integrated tracing and instrumentation functionality to enable administrators to better diagnose and fix problems within the application.  The new runtime instrumentation features also allow constant monitoring of the application's runtime health and performance while it's operational.  The following monitoring features were added in ASP.NET 2.0:

<br/><br/>
<table class="table">
  <tr>
    <th>Feature</th><th>Description</th>
  </tr>
  <tr>
    <td>Integration of ASP.NET Trace and System.Diagnostics.Trace</td><td>This feature allows ASP.NET trace messages to be directed to System.Diagnostics.Trace, and visa versa. </td>
  </tr>
  <tr>
    <td>Programmatic consumption of ASP.NET trace messages.</td><td>This feature allows page designers to obtain trace messages and do custom processing/route them to another destination as appropriate.</td>
  </tr>
  <tr>
    <td>Web Events</td><td>This powerful feature enables ASP.NET and custom code to emit events containing useful information about the health and various actions in the system.</td>
  </tr>
</table>

<h3>Integration of ASP.NET Trace and System.Diagnostics.Trace</h3>

ASP.NET Trace messages can be now forwarded to <b>System.Diagnostics.Trace</b> in order to make them available to generic processing infrastructure and tools consuming System.Diagnostics.Trace messages.  This feature can be enabled in the <trace> configuration section by setting <code>writeToDiagnosticsTrace</code> to true.
<br/><br/>
Likewise, System.Diagnostics.Trace messages can be consumed by ASP.NET Trace and displayed with the page trace messages in the page trace output or the application trace viewer.  This is incredibly useful to trace the execution of generic .NET components within ASP.NET pages.  This is accomplished by wiring up the <b>WebPageTraceListener</b> in the <listeners> element of the <trace> configuration section, as shown in the sample below:
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/monitoring/tracing/DisplayingDiagnosticsTrace_cs.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/DisplayingDiagnosticsTrace.src"
        Caption="C# Diagnostics Trace Integration"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/monitoring/tracing/DisplayingDiagnosticsTrace_vb.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/DisplayingDiagnosticsTrace.src"
        Caption="VB Diagnostics Trace Integration"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

Note that <code>trace</code> option must be enabled during compilation of code containing System.Diagnostics.Trace statements for them to generate messages.

<h3>Programmatic Consumption of Asp.Net Trace Messages</h3>

Page writers can now consume trace messages in code, allowing them to do custom processing, presentation, and redirection of trace output.  In the sample below, the page uses the TraceContext.TraceFinished event to obtain a collection of trace records, and display them manually:
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/monitoring/tracing/ConsumingTraceRecords_cs.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/ConsumingTraceRecords.src"
        Caption="C# Consuming Trace Records"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/monitoring/tracing/ConsumingTraceRecords_vb.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/ConsumingTraceRecords.src"
        Caption="VB Consuming Trace Records"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Web Events</h3>

The web events feature provides a general framework for emitting runtime events to indicate the occurrence of interesting actions in the application, report application health, or any other information of interest.  The feature allows administrators to determine exactly which events they are interested in via event subscriptions in configuration, and specify channels through which the events are delivered.  The feature includes several channel providers out of the box that cater to a variety of scenarios:

<ul>
  <li>Saving events to Microsoft&trade; SQL Server
  <li>Sending event reports through email
  <li>Writing events to the Windows&trade; Event Log
  <li>Forwarding events through WMI
</ul>

ASP.NET 2.0 itself uses the web event feature to provide health reporting, auditing, and instrumentation of various pieces of runtime functionality.  Anyone can develop and raise custom event types to further instrument their application.
<br/><br/>
In the example below, the application is configured to send all emitted web events to the sql server provider.  The page raises an instance of the custom event type deriving from WebEventBase when it loads, and uses a datasource control to read the events directly out of the sql server event table.  The GridView displaying the list of events also shows some of the events that asp.net itself generates during the request processing cycle.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/monitoring/healthmonitoring/viewevents_cs/viewevents.aspx"
        ViewSource="~/aspnet/samples/monitoring/healthmonitoring/viewevents.src"
        Caption="C# Health Monitoring Events"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/monitoring/healthmonitoring/viewevents_vb/viewevents.aspx"
        ViewSource="~/aspnet/samples/monitoring/healthmonitoring/viewevents.src"
        Caption="VB Health Monitoring Events"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>


