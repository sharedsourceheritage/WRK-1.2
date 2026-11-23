<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.ConnectionZone" runat="server">
  ConnectionZone
</Acme:TypeRef>
</h2>

<p>
The <b>ConnectionZone</b> control enables web parts to be connected to each other dynamically.
You can use this control to enable connections and to set properties for a connection. 
However, a web part must be designed to allow connections to participate in one.</p>

<p>
To create a connection dynamically, the user must first make the ConnectionZone control
visible by taking an action to switch the page to connection display mode (ConnectionDisplayMode).
The user can then create connections by selecting the connection verb from the web part's Verb menu.</p>

<p>
<b>Note:</b> In addition to dynamic connections, you can connect web parts to each other
statically, by using the <b>StaticConnections</b> property.
</p>

<br /><br />


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/reference_cs/ConnectionZone.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/ConnectionZone.src"
        Caption="C# ConnectionsZone Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/reference_vb/ConnectionZone.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/ConnectionZone.src"
        Caption="VB ConnectionsZone Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


</asp:Content>
