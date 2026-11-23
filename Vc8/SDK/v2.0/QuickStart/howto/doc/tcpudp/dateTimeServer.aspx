<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Make a DateTime server with TCPListener?</h4>

<div class="indent" style="width:660">

<p>This sample illustrates how to use the <b>TCPListener</b> class to create a DateTime server program.</p>

<p>This application acts as a server for the standard Date and Time protocol. This protocol
works on port 13, and responds to any TCP connections to that port with the current date and time.</p>

<p>The application firsts creates a <b>TCPListener</b> object with the constructor that
specifies that the Listener should handle all incoming requests on port 13. Next, it goes
into a loop and continues to listen for incoming connections. The connections are then
accepted with the <b>Accept</b> method, and the socket returned is used to <b>Send</b>
the current date and time.</p>

<p>The <b>Receive</b> method could be called to get data from the client, but that method
is ignored, as the Date and Time protocol does not need any information that is sent from
the client, but automatically returns the information.</p>

</div>

<h4>Example</h4>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/net/TCPUDP/dateTimeServer.src"
        Icon="../../../images/console.gif"
        Caption="C# DateTimeServer.exe"
	SamplePath="howto\samples\net\TCPUDP\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/net/TCPUDP/dateTimeServer.src"
        Icon="../../../images/console.gif"
        Caption="VB DateTimeServer.exe"
	SamplePath="howto\samples\net\TCPUDP\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
 <VjsTemplate>
       <Acme:SourceRef
       RunSample=""
        ViewSource="~/howto/samples/net/TCPUDP/dateTimeServer.src"
        Icon="../../../images/console.gif"
        Caption="J# DateTimeServer.exe"
	SamplePath="howto\samples\net\TCPUDP\"
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


