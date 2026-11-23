<%@ Page Language="VB" Theme="Default" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>TreeView Bound to XML</title>
  </head>
  <body>
    <div>
      <h2>TreeView Bound to XML</h2>
      
      <form action="treeview12_xml_vb.aspx" runat="server">

        <asp:XmlDataSource ID="MySource" DataFile="~/App_Data/Bookstore.xml" runat="server"/>

        <asp:TreeView ID="TreeView1" 
          SkinId="Bookstore"
          DataSourceId="MySource" 
          ExpandDepth="3"
          MaxDataBindDepth="3"
          runat="server" />

      </form>
    </div>
  </body>
</html>