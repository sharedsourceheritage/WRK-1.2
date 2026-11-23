<%@ Page Theme="Default" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>Populating TreeView Nodes from a SQL Database</title>
  </head>
  <script language="C#" runat="server">

    void GetProductCategories (TreeNode node) {

        CategoryList categories = WarehouseDB.GetProductCategories();
        foreach (Category c in categories) {
            TreeNode newNode = new TreeNode(c.Name, c.Id);

            newNode.SelectAction = TreeNodeSelectAction.Expand; 
            newNode.PopulateOnDemand = true;
            node.ChildNodes.Add(newNode);
        }
    }

    void GetProductsForCategory (TreeNode node) {

        String categoryId = node.Value;
        ProductList products = WarehouseDB.GetProductsForCategory(categoryId);
        foreach (Product p in products) {
            TreeNode newNode = new TreeNode(p.Name, p.Id);
            node.ChildNodes.Add(newNode);
        }
    }

    void PopulateNode (Object source, TreeNodeEventArgs e) {
        switch (e.Node.Depth) {
            case 0 :
              GetProductCategories(e.Node); 
              break;
            case 1 :
              GetProductsForCategory(e.Node); 
              break;
        }
    }

  </script>
  <body>
    <div>
      <h2>Populating TreeView Nodes from a SQL Database</h2>

      <form action="treeview11_database_cs.aspx" runat="server">

        <asp:TreeView ID="TreeView1" OnTreeNodePopulate="PopulateNode" SkinId="Simple" Width="250" ExpandDepth="0" runat="server">
          <Nodes>
            <asp:TreeNode Text="Inventory" SelectAction="Expand" PopulateOnDemand="true"/>
          </Nodes>
        </asp:TreeView>

      </form>
    </div>
  </body>
</html>
