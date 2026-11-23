<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Create a Remote Object as a Singleton?</h4>

<p>This example demonstrates how to modify the <a href="firstserver.aspx">Client/Server</a> example
by deploying the remote object as a
singleton.  The client starts two threads and calls the <b>CountMe</b> method on
the server on two different channels: TCP and HTTP.

<p>Although this example is very
simple, it does illustrate a few important concepts.<p>
<p>
<ul>

<li>The <b>HelloServer</b> object is only activated once and its destructor is never called.<p>

<li>When you run the client, thread number two appears to outperform thread number one.  The second
thread is indeed faster than the first since thread one uses the HTTP channel that
transports data in XML using SOAP while TCP uses a binary transport.
While TCP clearly outperforms HTTP, the latter is more general and should be
used when communicating with unknown endpoints.<p>

<li>The server object is locked while the counter is incremented in the <b>CountMe</b> call.<p>

<li>Notice that the count returned by the server is not reset between different
invocations of the client.  This behavior demonstrates that the server does
preserve its state during its lifetime.<p>

<li>Each client thread makes a call to the server and then yields control to
its partner to ensure they both get a chance to run.<p>

<li>Each thread registers its own channel and connects to the server using
different URIs.  These are <b>"http://localhost:8086/SayHello"</b> for thread
one and <b>"tcp://localhost:8085/SayHello"</b> for thread two.<p>

<li>The client executable waits for both threads to finish before terminating.<p>

</ul>

<p><b>NOTE:</b> &nbsp;Do not specify a port number when registering the client channels.  The
framework uses the port number on the channels to determine if the
channel should listen or connect.  When the channel is registered with
a port number, the channel listens. If the port number is zero, it
attempts to connect to a remote channel at the specified URI.<p>


<p><Acme:LangSwitch runat="server">
<CsTemplate>
<Acme:SourceRef
  RunSample=""
  ViewSource="~/HowTo/Samples/Remoting/singleton/server.src"
  Icon="../../../images/genicon.gif"
  Caption="C# Singleton Sample"
  SamplePath="HowTo\Samples\Remoting\singleton\"
  runat="server" />
</CsTemplate>
<VbTemplate>
<Acme:SourceRef
  RunSample=""
  ViewSource="~/HowTo/Samples/Remoting/singleton/server.src"
  Icon="../../../images/genicon.gif"
  Caption="VB Singleton Sample"
  SamplePath="HowTo\Samples\Remoting\singleton\"
  runat="server" />
</VbTemplate>
<CpTemplate>
<Acme:SourceRef
  RunSample=""
  ViewSource="~/HowTo/Samples/Remoting/singleton/server.src"
  Icon="../../../images/genicon.gif"
  Caption="C++ Singleton Sample"
  SamplePath="HowTo\Samples\Remoting\singleton\"
  runat="server" />
</CpTemplate>
 <VjsTemplate>
       <Acme:SourceRef
  RunSample=""
  ViewSource="~/HowTo/Samples/Remoting/singleton/server.src"
  Icon="../../../images/genicon.gif"
  Caption="J# Singleton Sample"
  SamplePath="HowTo\Samples\Remoting\singleton\"
  runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>
<p>




<p>
</asp:Content>



