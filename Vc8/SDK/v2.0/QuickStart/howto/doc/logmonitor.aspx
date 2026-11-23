<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Monitor an event log?</h2>

<br /><br />Event logging provides a standard, centralized way for you to have your applications
record important software and hardware events. Windows supplies a standard user
interface for viewing the logs (Event Log). Using the common language runtime's EventLog
component, you can easily connect to existing event logs, and receive event notifications when a new entry is written to
the log.
<br /><br />

This sample illustrates how to monitor an event log for new entries.
It is a small console application that can be run from a command prompt. The
application takes one command line argument. The argument is the name of
the log that you want to monitor.
<br /><br />

Try running the sample as follows:
<br /><br />

<pre class="code">
&gt; LogMonitor.exe Application
</pre>

<br /><br />
Now run the LogWrite.exe sample and write a new entry to the application log. You
will see that the <b>LogMonitor</b> is being notified about the new entry being
written.
<br /><br />

In its simplest form, monitoring an event log involves:

<ol>

<li>Creating a new instance of an <b>EventLog</b> component and pointing it to a appropriate event log:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
String log;
...
EventLog aLog = new EventLog();
aLog.Log = log;
</Tab>
<Tab Name="VB">
Dim log As String
...
Dim aLog As New EventLog
aLog.Log = log
</Tab>
<Tab Name="C++">
String* log;
...

EventLog* aLog = new EventLog();
aLog->Log = log;
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>Adding an event handler:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
aLog.EntryWritten += new EventLogEventHandler(OnEntryWritten);
</Tab>
<Tab Name="VB">
AddHandler aLog.EntryWritten, AddressOf OnEntryWritten
</Tab>
<Tab Name="C++">
aLog->EntryWritten += new EntryWrittenEventHandler(this, LogMonitor::OnEntryWritten);
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>Handling the event notification in your event handler:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
public static void OnEntryWritten(Object source, EventLogEvent e) {
    Console.WriteLine("Written: " + e.Entry.Message);
}
</Tab>
<Tab Name="VB">
Sub OnEntryWritten(ByVal source As Object, ByVal e As EventLogEvent)
    Console.WriteLine("Written: " + e.Entry.Message)
End Sub
</Tab>
<Tab Name="C++">
void OnEntryWritten(Object* source, EntryWrittenEventArgs* e) 
{
    Console::WriteLine(String::Concat(S"Written: ", e->Entry->Message));
}
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>

</ol>

<h2>Example</h2>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/EventLog/LogMonitor/LogMonitor.src"
        Icon="../../images/console.gif"
        Caption="C# LogMonitor.exe"
	SamplePath="howto\samples\Services\EventLog\LogMonitor\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/EventLog/LogMonitor/LogMonitor.src"
        Icon="../../images/console.gif"
        Caption="VB LogMonitor.exe"
	SamplePath="howto\samples\Services\EventLog\LogMonitor\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/EventLog/LogMonitor/LogMonitor.src"
        Icon="../../images/console.gif"
        Caption="C++ LogMonitor.exe"
	SamplePath="howto\samples\Services\EventLog\LogMonitor\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
 <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>
