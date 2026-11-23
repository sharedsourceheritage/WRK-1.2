<%@ Page Language="VB" %>

<script runat="server">

  Sub TreeView_Select(ByVal sender As Object, ByVal e As EventArgs)
    Response.Write("You selected: " & TreeView1.SelectedNode.Value)
  End Sub

</script>

<html>
  <head id="Head1" runat="server">
    <title>TreeView and XmlDataSource</title>
  </head>
  <body>
    <h2>TreeView Bound to XML</h2>
    <form id="form1" runat="server">
      <div>
        <asp:TreeView ID="TreeView1" Runat="server" OnSelectedNodeChanged="TreeView_Select" DataSourceID="XmlDataSource1">
          <NodeStyle Font-Names="Verdana" Font-Size=".80em" HorizontalPadding="5" ChildNodesPadding="10" />
          <HoverNodeStyle Font-Underline="true" />
          <SelectedNodeStyle BackColor="Beige" />
          <LevelStyles>
            <asp:TreeNodeStyle Font-Bold="true" />
            <asp:TreeNodeStyle Font-Italic="true" />
          </LevelStyles>
          <Databindings>
            <asp:TreeNodeBinding DataMember="Bookstore" Text="Bookstore" ImageUrl="images/folder.gif" />
            <asp:TreeNodeBinding DataMember="genre" TextField="name" ImageUrl="images/folder.gif"/>
            <asp:TreeNodeBinding DataMember="book" TextField="Title" ImageUrl="images/closedbook.gif" />
            <asp:TreeNodeBinding DataMember="chapter" TextField="name" ImageUrl="images/notepad.gif" />
          </Databindings>
        </asp:TreeView>
        <asp:XmlDataSource ID="XmlDataSource1" Runat="server" DataFile="~/App_Data/bookstore.xml"
          XPath="Bookstore/genre[@name='Business']/book" />
      </div>
    </form>
  </body>
</html>
