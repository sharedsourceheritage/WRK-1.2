<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.WebPartManager" runat="server">
  WebPartManager
</Acme:TypeRef>
</h2>

 The WebPartManger is the central class of the Web Part Control Set, responsible for managing and coordinating all controls inside WebZones.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_cs/WebPartZone_Simple.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/WebPartZone_Simple.src"
        Caption="C# WebPartManager Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_vb/WebPartZone_Simple.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/WebPartZone_Simple.src"
        Caption="VB WebPartManager Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
