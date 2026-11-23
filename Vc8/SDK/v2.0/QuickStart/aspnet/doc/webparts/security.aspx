<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Authorizing Web Parts</h2>
The web parts control set includes a mechanism to authorize web parts that applies to all the ASP.NET server controls when adding or importing those to a page. 
Page developers implement an authorization filter by subscribing to the WebPartManager.OnAuthorizeWebPart event.
<br /><br />
This example shows a page that displays web parts that are of type Calendar:
<ol>
<li>Log in to the page. Calendars are displayed in the page.</li>
<li>Select "Catalog" from the dropdown. The CatalogZone will now be visible, and will display a calendar control in its Declarative Catalog part.</li>

</ol>

<Acme:LangSwitch runat=server>
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/WebPartManager/AuthorizingWebParts_cs"
        ViewSource="~/aspnet/samples/webparts/WebPartManager/AuthorizingWebParts.src"
        Caption="C# Authorizing Web Parts"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/WebPartManager/AuthorizingWebParts_vb"
        ViewSource="~/aspnet/samples/webparts/WebPartManager/AuthorizingWebParts.src"
        Caption="VB Authorizing Web Parts"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

You should inherit from the WebPartManager class and override the IsAuthorize method if the implementation of the WebPartManager.OnAuthorizeWebPart is the same across multiple pages. 
This approach will prevent redundant code across pages.

</asp:Content>

