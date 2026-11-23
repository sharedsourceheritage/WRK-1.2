<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>


<h2>How Do I...Instrument a small application with tracing?</h2>

<br /><br />Trace instrumentation enables developers and administrators
to monitor applications running in real-life settings (as opposed to
running in a debugger). Sometimes using a debugger can hide bugs and
obscure some performance and threading problems. Tracing is a very important
monitoring and debugging tool for distributed, multitier applications. Such
applications often contain problems that you can only observe when the application is
under a heavy load, and in the inherent randomness of a real-life environment.

<br /><br />This sample illustrates the basics of instrumenting applications with tracing. After running it, take a look at the source code. You will see how easy it is to add simple instrumentation to your applications.

<br /><br />You have to compile your instrumented applications with
trace or debug compiler directives enabled. Otherwise, all calls to <b>Trace</b> or
<b>Debug</b> (respectively) are ignored during compilation.

<br /><br />Before running the application, create a configuration 
file - TraceDemo.exe.config - in the same directory as the 
executable, and set <code>TraceMethods</code> and 
<code>Arithmetic</code> to
the values of your choice as shown below: 

<pre class="code">
&lt;?xml version="1.0" encoding="UTF-8" ?&gt;
&lt;configuration&gt;
    &lt;system.diagnostics&gt;
        &lt;switches&gt;
            &lt;!-- Set value property of the TraceMethods switch to:
                 0 (false) or 1 (true) --&gt;
            &lt;add name="TraceMethods" value="1" /&gt;

            &lt;!-- Set value property of the Arithmetic switch to:
                 1(error), 2(warning), 3(info), 4(verbose) --&gt;
            &lt;add name="Arithmetic" value="4" /&gt;
        &lt;/switches&gt;
        &lt;trace autoflush="false" indentsize="4" /&gt;
    &lt;/system.diagnostics&gt;
&lt;/configuration>
</pre>

Next, open a command line window
and run the Debug Monitor utility (DbMon.exe). You will be able to see any debug and trace messages coming
from any application running on your system.

<br /><br />
<b>Note: </b> DBMon.exe is available from the Windows Platform SDK on the <a target="_blank" href="http://msdn.microsoft.com">Microsoft Developer Network</a> website.

<h2>Example</h2>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/Tracing/TraceDemo/TraceDemo.src"
        Icon="../../images/console.gif"
        Caption="C# TraceDemo.exe"
	SamplePath="howto\samples\Services\Tracing\TraceDemo\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/Tracing/TraceDemo/TraceDemo.src"
        Icon="../../images/console.gif"
        Caption="VB TraceDemo.exe"
	SamplePath="howto\samples\Services\Tracing\TraceDemo\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/Tracing/TraceDemo/TraceDemo.src"
        Icon="../../images/console.gif"
        Caption="C++ TraceDemo.exe"
	SamplePath="howto\samples\Services\Tracing\TraceDemo\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
</Acme:LangSwitch>

</asp:Content>


