<%@ Page Language="C#" Theme="Default" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>TreeView Bound to XML</title>
  </head>
  <body>
    <div>
      <h2>TreeView Bound to XML</h2>

      <form action="treeview13_xml_cs.aspx" runat="server">

        <asp:XmlDataSource ID="MySource" DataFile="~/App_Data/Bookstore.xml" runat="server"/>

        <asp:TreeView ID="TreeView1"
          SkinId="Bookstore"
          DataSourceId="MySource" 
          ExpandDepth="3"
          MaxDataBindDepth="3"
          runat="server">
          <Databindings>
            <asp:TreeNodeBinding DataMember="Bookstore" Text="Bookstore" ImageUrl="~/images/xp/folder.gif" />
            <asp:TreeNodeBinding DataMember="genre" TextField="name" ImageUrl="~/images/xp/folder.gif" />
            <asp:TreeNodeBinding DataMember="book" TextField="Title" ImageUrl="~/images/chm/closedbook.gif" />
            <asp:TreeNodeBinding DataMember="chapter" TextField="name" ImageUrl="~/images/xp/notepad.gif" />
          </Databindings>

        </asp:TreeView>

      </form>
    </div>
  </body>
</html>
