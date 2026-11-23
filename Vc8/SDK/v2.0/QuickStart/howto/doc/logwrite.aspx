<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Write to an event log?</h2>

<br /><br />Event logging provides a standard, centralized way for
your applications to record important software and hardware events.
Windows supplies a standard user interface for viewing the logs (the Event Viewer). Using the common language runtime's <b>EventLog</b> component, you can easily connect to existing event logs on a local computer, and write entries to
these logs. You can also read entries from existing logs and create your own
custom event logs.
<br /><br />
This sample illustrates how to write to an event log. It's a
small console application that can be run from a command prompt. The
application takes three command line arguments. The first argument is the log
to which the application will write. The second is the message to be written.
The third is the name of the source of the event log entry (message).
<br /><br />
Try running the sample as follows:

<pre class="code">
&gt; LogWrite.exe MyLog &quot;Hello World!&quot; &quot;LogWrite Sample&quot;
</pre>

<br /><br />
Now, open the event log viewer and observe that there is a
new log added to the list of logs on your machine. The log's name is "MyLog"and it contains an entry written by "LogWrite Sample" (source). Double-click on
the entry. It will greet you with a "Hello World!" message.

<br /><br />
In its simplest form, writing to an event log involves:

<ol>
<li>Registering an event source (if not already registered):

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
if (!EventLog.SourceExists(source)) {
    EventLog.CreateEventSource(source,log);
}
</Tab>
<Tab Name="VB">
If (Not EventLog.SourceExists(source)) Then
    EventLog.CreateEventSource(source, log)
End If
</Tab>
<Tab Name="C++">
if ( !EventLog::SourceExists(source) )
{
    EventLog::CreateEventSource(source, log);
}
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>Creating a new instance of an <b>EventLog</b> component and setting its <b>Source</b> property:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
EventLog aLog = new EventLog();
aLog.Source = source;
</Tab>
<Tab Name="VB">
Dim aLog As New EventLog
aLog.Source = source
</Tab>
<Tab Name="C++">
EventLog* aLog = new EventLog();
aLog->Source = source;
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>Calling the <b>WriteEntry</b> method:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
String message =  "some message";
aLog.WriteEntry(message, EventLogEntryType.Information);
</Tab>
<Tab Name="VB">
Dim message As String = "some message"
aLog.WriteEntry(message, EventLogEntryType.Information)
</Tab>
<Tab Name="C++">
String* message =  "some message";
aLog->WriteEntry(message, EventLogEntryType::Information);
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

</ol>

<br /><br />Now, you may want to try to modify the sample so it writes
error log entries instead of informational entries. Just change
the EventLogEntryType.Information to EventLogEntryType.Error, rebuild the
sample and run it again.

</ol>

<h2>Example</h2>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/EventLog/LogWrite/LogWrite.src"
        Icon="../../images/console.gif"
        Caption="C# LogWrite.exe"
	SamplePath="howto\samples\Services\EventLog\LogWrite\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/EventLog/LogWrite/LogWrite.src"
        Icon="../../images/console.gif"
        Caption="VB LogWrite.exe"
	SamplePath="howto\samples\Services\EventLog\LogWrite\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/EventLog/LogWrite/LogWrite.src"
        Icon="../../images/console.gif"
        Caption="C++ LogWrite.exe"
	SamplePath="howto\samples\Services\EventLog\LogWrite\"
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

