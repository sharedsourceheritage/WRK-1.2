<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.CatalogZone" runat="server">
  CatalogZone
</Acme:TypeRef>
</h2>
<p>
Serves as the primary control in the Web Parts control set for hosting ASP.NET server controls of type CatalogPart on a Web page. 
</p>
<p>
A CatalogZone control becomes visible only when a user switches a Web page to catalog display mode (CatalogDisplayMode). 
</p>
A catalog can contain several types of CatalogPart controls. The following list summarizes the CatalogPart controls provided with the Web Parts control set
<ul>
<li><a href="pagecatalogpart.aspx">PageCatalogPart</a></li>
<li><a href="DeclarativeCatalogPart.aspx">DeclarativeCatalogPart</a></li>
<li><a href="ImportCatalogPart.aspx">ImportCatalogPart</a> </li>
</ul>

<Acme:LangSwitch ID="LangSwitch1" runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_cs/CatalogZone_DeclarativeCatalogPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/CatalogZone_DeclarativeCatalogPart.src"
        Caption="C# CatalogZone Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_vb/CatalogZone_DeclarativeCatalogPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/CatalogZone_DeclarativeCatalogPart.src"
        Caption="VB CatalogZone Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
