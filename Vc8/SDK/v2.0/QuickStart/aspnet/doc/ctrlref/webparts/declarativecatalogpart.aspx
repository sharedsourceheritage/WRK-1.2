<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.DeclarativeCatalogPart" runat="server">
  DeclarativeCatalogPart
</Acme:TypeRef>
</h2>

<p>
The DeclarativeCatalogPart control provides a way for developers to add a set of server controls declaratively to a catalog on a Web page. A catalog, in the Web Parts control set, is simply a list of WebPart or other server controls that is visible when a page is in catalog display mode. A user can select controls from the list and add them to the Web page, which effectively gives users the ability to change the set of controls and the functionality on a page.
</p>
<p>The most common and convenient way to add a DeclarativeCatalogPart control to a page is by declaring it in page persistence format inside a <a href=CatalogZone.aspx>CatalogZone</a></p>

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/reference_cs/CatalogZone_DeclarativeCatalogPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/CatalogZone_DeclarativeCatalogPart.src"
        Caption="C# DeclarativeCatalogPart Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/reference_vb/CatalogZone_DeclarativeCatalogPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/CatalogZone_DeclarativeCatalogPart.src"
        Caption="VB DeclarativeCatalogPart Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
