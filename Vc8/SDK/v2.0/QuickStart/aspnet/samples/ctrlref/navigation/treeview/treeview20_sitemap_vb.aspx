<%@ Page Language="VB" Theme="Default" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>DataBinding TreeView to SiteMapDataSource</title>
  </head>
  <body>
    <div>
      <h2>DataBinding TreeView to SiteMapDataSource</h2>

      <form action="treeview20_sitemap_vb.aspx" runat="server">

        <asp:SiteMapDataSource ID="SiteMapSource" runat="server"/>

        <asp:TreeView ID="MyTreeView" 
          SkinId="BulletedList3" 
          DataSourceId="SiteMapSource" 
          runat="server">
          <LevelStyles>
            <asp:TreeNodeStyle Font-Bold="True" Font-Size="10pt" ChildNodesPadding="5" />
            <asp:TreeNodeStyle Font-Underline="True" ChildNodesPadding="5" />
          </LevelStyles>
          <Databindings>
            <asp:TreeNodeBinding TextField="Title" NavigateUrlField="Url" />
          </Databindings>
        </asp:TreeView>

        <br /><br />
        Note that the links above do not navigate to actual pages.  They are only for demonstrating an example site map.

      </form>
    </div>
  </body>
</html>
