<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Login Controls</h2>

<asp:DataList CssClass="bulletlist" RepeatColumns="4" DataSourceID="SiteMapDataSource1" runat="server">
  <ItemTemplate>
    <div style="padding-right:50px"><li><asp:HyperLink Text='<%# Eval("Title") %>' NavigateUrl='<%# Eval("Url") %>' runat="server"/></li></div>
  </ItemTemplate>
</asp:DataList>
<asp:SiteMapDataSource ID="SiteMapDataSource1" StartFromCurrentNode="true" ShowStartingNode="false" runat="server"/>

</asp:Content>

