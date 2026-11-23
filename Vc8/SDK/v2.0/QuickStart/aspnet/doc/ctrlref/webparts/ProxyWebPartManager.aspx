<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.WebPartManager" runat="server">
  ProxyWebPartManager
</Acme:TypeRef>
</h2>

 The ProxyWebPartManager class allows page developers a way to specify static connections in a content page when the WebPartManager has been specified in the master page.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_cs/ProxyWebPart_Content.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/ProxyWebPart_sample.src"
        Caption="C# WebPartManager Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_vb/ProxyWebPart_Content.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/ProxyWebPart_sample.src"
        Caption="VB WebPartManager Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
