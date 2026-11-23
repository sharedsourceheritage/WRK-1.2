<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Read from an event log?</h2>

<br /><br />Event logging provides a standard, centralized way for you
to have your applications record important software and hardware events. Windows
supplies a standard user interface for viewing the logs (Event Log).
Using the Microsoft .NET Framework's <b>EventLog</b> component, you can easily connect to existing event
logs on both local and remote computers, and read entries from these logs programmatically.
<br /><br />

This sample illustrates how to enumerate entries in an event
log. It is a small console application that can be run from a command prompt.
The application takes two command line arguments. The first argument is the name
of the log that you want to enumerate. The second argument is optional and allows you to
specify the machine name of the server on which the log resides.
<br /><br />

Try running the sample as follows:

<pre class="code">
&gt; LogInfo.exe Application
</pre>

<br /><br />
The sample will list all the entries from the application log. You can try the same
with the System, Security, and any other logs residing on your machine.

<br /><br />
In its simplest form, writing to an event log involves:

<ol>

<li>Creating a new instance of an <b>EventLog</b> component and pointing it to an appropriate event log:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
String log, machine;
...
EventLog aLog = new EventLog();
aLog.Log = log;
aLog.MachineName = machine;
</Tab>
<Tab Name="VB">
Dim log, machine As String
...
Dim aLog As New EventLog
aLog.Log = log
aLog.MachineName = machine
</Tab>

<Tab Name="C++">
String* log, machine;
...
EventLog* aLog = new EventLog();
aLog->Log = log;
aLog->MachineName = machine;
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>Enumerating through the <b>Entries</b> collection of the <b>EventLog</b> instance:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
foreach (EventLogEntry entry in aLog.Entries) {
    Console.WriteLine(&quot;\tEntry: " + entry.Message);
}
</Tab>
<Tab Name="VB">
For Each entry In alog.Entries
    Console.WriteLine("    Entry: " + entry.Message)
Next entry
</Tab>

<Tab Name="C++">
for (int i = 0; i < entries->Count; i++)
{
    entry = entries->get_Item(i);
    Console::WriteLine(String::Concat(S"\tEntry: ", entry->Message));
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
        ViewSource="~/howto/samples/Services/EventLog/LogInfo/LogInfo.src"
        Icon="../../images/console.gif"
        Caption="C# LogInfo.exe"
	SamplePath="howto\samples\Services\EventLog\LogInfo\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/EventLog/LogInfo/LogInfo.src"
        Icon="../../images/console.gif"
        Caption="VB LogInfo.exe"
	SamplePath="howto\samples\Services\EventLog\LogInfo\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/EventLog/LogInfo/LogInfo.src"
        Icon="../../images/console.gif"
        Caption="C++ LogInfo.exe"
	SamplePath="howto\samples\Services\EventLog\LogInfo\"
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
