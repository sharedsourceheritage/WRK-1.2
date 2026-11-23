<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Write a Simple Service Application?</h2>

<br /><br />Microsoft Windows NT services enable you to create long running executable applications
that run in their own Windows sessions. These services can be automatically started when
the computer boots, can be paused and restarted, and typically do not show any user
interface. This makes services ideal for use on a server or whenever you need long-running
functionality that does not interfere with other users who are working on the same computer.
You can also run services in the security context of a specific user account that is
different from the logged-on user or the default computer account. For more information
about services and Windows sessions, see the &quot;About Services&quot; section in the
Platform SDK documentation in MSDN Online.

<br /><br />Using the .NET Framework, you can easily create services by creating an application that
is installed as a service. For example, suppose you want to monitor performance counter data
and react to threshold values. You could do this by writing an NT service and deploying it
to the computer that has the counters you want to monitor.

<br /><br />The following sample is a simple service application. You can install it using the .NET Framework SDK
Installation Utility. From a command prompt run:

<pre class="code">
&gt; InstallUtil.exe SimpleService.exe
</pre>

<br /><br />After the installation is completed you can start the Hello World Service from the
Services Management Console. After the service starts you should see the service's event
log being filled with greetings from the sample service. You can use the Services
Management Console to pause, continue, start, and stop the service, and observe how such
operations affect the messages written to the event log. After you are done experimenting
with the sample, you can uninstall the service by running the following command from the
command window (you should stop the service before uninstalling it):

<pre class="code">
&gt; InstallUtil.exe /u SimpleService.exe
</pre>

<h4>Example</h4>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/ServiceApplication/SimpleService/SimpleService.src"
        Icon="../../images/console.gif"
        Caption="C# SimpleService.exe"
	SamplePath="howto\samples\Services\ServiceApplication\SimpleService\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/ServiceApplication/SimpleService/SimpleService.src"
        Icon="../../images/console.gif"
        Caption="VB SimpleService.exe"
	SamplePath="howto\samples\Services\ServiceApplication\SimpleService\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />	
  </CpTemplate>
</Acme:LangSwitch>

</asp:Content>
