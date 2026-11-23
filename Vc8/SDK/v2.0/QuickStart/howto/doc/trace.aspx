<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I... Work with tracing?</h2>

<br /><br />Trace instrumentation allows developers and administrators
to monitor the health of applications running in real-life settings (as opposed to
running in a debugger). Sometimes using a debugger can hide bugs and
obscure some performance and threading problems. Tracing is a very important
monitoring and debugging tool for distributed, multitier applications. Such
applications often contain problems that can only be observed when the application is
under a heavy load and the inherent randomness of a real-life environment.

<br /><br />This sample illustrates the basics of using the <b>Trace</b> and
<b>Debug</b> classes. Run it and take a look at the source code. You will see
how easy it is to add simple tracing to your applications.

<br /><br />You have to compile your instrumented applications with
trace or debug compiler directives enabled. Otherwise, all calls to <b>Trace</b> or
<b>Debug</b> (respectively) are ignored during compilation.

<br /><br />Before running the application, open a command line window
and run the Debug Monitor utility (DbMon.exe). You will be able to see any debug and trace messages coming
from any application running on your system.

<br /><br />
<b>Note: </b> DBMon.exe is available from the Windows Platform SDK on the <a target="_blank" href="http://msdn.microsoft.com">Microsoft Developer Network</a> website.

<h2>Example</h4>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/Tracing/Trace/Trace.src"
        Icon="../../images/console.gif"
        Caption="C# Trace.exe"
	Samplepath="howto\samples\Services\Tracing\Trace\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/Tracing/Trace/Trace.src"
        Icon="../../images/console.gif"
        Caption="VB Trace.exe"
	Samplepath="howto\samples\Services\Tracing\Trace\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/Tracing/Trace/Trace.src"
        Icon="../../images/console.gif"
        Caption="C++ Trace.exe"
	Samplepath="howto\samples\Services\Tracing\Trace\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
</Acme:LangSwitch>


</asp:Content>