<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Connections Between Web Parts</h2>

Web parts are also capable of exchanging data between them, using web part connections.
Using connections, you can have one web part provide one or more property values that can be
used by other web parts on the page. Web part connections have the following elements:
<ul>
<li>An interface that defines the communications contract between two parts. The interface
describes properties and methods available through the connection.</li>
<br />
<li>A web part that behaves as a connection provider.  To specify a provider connection point,
a web part needs to have a method that creates and returns an instance of the communications
interface. This method should be marked with the <b>ConnectionProvider</b> attribute. By default, A single
provider connection point can be used with multiple connection consumers.
</li>
<br />
<li>A web part that behaves as a connection consumer. To specify a consumer connection point,
a web part needs to have a method that takes an instance of the communications interface as
a parameter. This method should be marked with the <b>ConnectionConsumer</b> attribute. By default, A single
consumer connection point can only be used with one connection provider.
</li>
</ul>
You can connect web parts statically when you build the page, or allow parts to be connected 
dynamically by the user. At runtime, web part connections are managed by the WebPartManager, as follows:
<ol>
<li>For each registered provider, the WebPartManager calls its provider connection point method.</li>
<li>The provider part return an instance of the communications interface.</li>
<li>For each consumer registered for this provider, the WebPartManager calls its consumer connection point method, passing an instance of the interface .</li>
<li>The consumer part calls properties and methods on the interface instance.</li>
</ol>
This example shows a connection between two web parts on the page. The part that displays text connects to
the user control web part that allows text entry. The two parts exchange text through the ITextCommunication
interface.
<br /><br />
<ol>
<li>Type text on the user control and click the button. the text that you typed should display on the Text Display Web Part</li>
</ol>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/StaticConnection_cs"
        ViewSource="~/aspnet/samples/webparts/connections/StaticConnection.src"
        Caption="C# Static Connection "
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/StaticConnection_vb"
        ViewSource="~/aspnet/samples/webparts/connections/StaticConnection.src"
        Caption="VB Static Connection"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br /> 
A user can establish connections between web parts by using the ConnectionZone. These type of connections are called dynamic connections.
<br />
This example shows how to Connect web Part dynamically
<ol>
<li>Log in to the page.</li>
<li>Select "Connect" from the dropdown. </li>
<li>Click the dropdown arrow on the Text Display Web Part's Verb Menu, and select "Connect" from the menu. The ConnectionZone will now be visible.</li>
<li>Click on "Create a connection to a Provider" link</li>
<li>Select Super cool user control from the dropdown</li>
<li>Click connect</li>
<li>Type text on the user control and click the button. the text that you typed should display on the Text Display Web Part</li>
</ol>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/DynamicConnection_cs"
        ViewSource="~/aspnet/samples/webparts/connections/DynamicConnection.src"
        Caption="C# Dynamic Connection"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/DynamicConnection_cs"
        ViewSource="~/aspnet/samples/webparts/connections/DynamicConnection.src"
        Caption="VB Dynamic Connections"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br /><br />
A Web Part can provide multiple connection point; as a result it can participate on multiple connections.
<br />
This example show how to Connect web Part dynamically
<ol>
<li>Log in to the page.</li>
<li>Select "Connect" from the dropdown. </li>
<li>Click the dropdown arrow on the Text Display Web Part's Verb Menu, and select "Connect" from the menu. The ConnectionZone will now be visible.</li>
<li>Click on "Create a connection to a Provider" link</li>
<li>Select Super cool user control from the dropdown</li>
<li>Click connect</li>
<li>Click on "Create a connection to a consumer" link</li>
<li>Select "Untitled" from the dropdown</li>
<li>Click connect</li>

<li>Type text on the user control and click the button. the text that you typed should display on the Text Display Web Part as well as the number of letters in the text</li>
</ol>

<Acme:LangSwitch ID="LangSwitch1" runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/MultipleConnectionPoints_cs"
        ViewSource="~/aspnet/samples/webparts/connections/MultipleConnectionPoints.src"
        Caption="C# Multiple Connection Points"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/MultipleConnectionPoints_vb"
        ViewSource="~/aspnet/samples/webparts/connections/MultipleConnectionPoints.src"
        Caption="VB Multiple Connection Points"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch> 
<br />

Developer can create connection via code. <br />
<br />
This example show how to Connect web Part using code.
<ol>
<li>Click on "Connect Web Part" button</li>
<li>Type text on the user control and click the button. The text that you typed should display on the Text Display Web Part </li>
<li>Click on "Disconnect Web Part" button. The text that you typed should not be display on the Text Display Web Part </li>
</ol>

<Acme:LangSwitch ID="LangSwitch2" runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/ConnectionUsingCode_Cs"
        ViewSource="~/aspnet/samples/webparts/connections/ConnectionUsingCode.src"
        Caption="C# Connecting Web Parts using Code"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/ConnectionUsingCode_vb"
        ViewSource="~/aspnet/samples/webparts/connections/ConnectionUsingCode.src"
        Caption="VB Connecting Web Parts using Code"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch> 
<br />
Developer can disable connection point at runtime. <br /><br />
This example show how to disable connection point at runtime.
<ol>
<li>Click the "Disable" radio button. this will break the connection between web parts</li>
<li>Click the "enable" radio button. this will reestablish the connection between web parts</li>
</ol>

<Acme:LangSwitch ID="LangSwitch3" runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/DisableConnectionPoint_Cs"
        ViewSource="~/aspnet/samples/webparts/connections/DisableConnectionPoint.src"
        Caption="C# Disabling Connection Point"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/connections/DisableConnectionPoint_vb"
        ViewSource="~/aspnet/samples/webparts/connections/DisableConnectionPoint.src"
        Caption="VB Disabling Connection Point"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch> 


</asp:Content>

