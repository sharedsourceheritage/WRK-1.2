<%@ Page Language="VB" Theme="Default" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>Populating TreeView Nodes from a SQL Database</title>
  </head>
  <script language="VB" runat="server">

    Sub GetProductCategories(ByVal node As TreeNode)

      Dim categories As CategoryList = WarehouseDB.GetProductCategories()
      Dim c As Category
      For Each c In categories
        Dim newNode As TreeNode = New TreeNode(c.Name, c.Id)

        newNode.SelectAction = TreeNodeSelectAction.Expand
        newNode.PopulateOnDemand = True
        node.ChildNodes.Add(newNode)
      Next
    End Sub

    Sub GetProductsForCategory(ByVal node As TreeNode)

      Dim categoryId As String = node.Value
      Dim products As ProductList = WarehouseDB.GetProductsForCategory(categoryId)
      Dim p As Product
      For Each p In products
        Dim newNode As TreeNode = New TreeNode(p.Name, p.Id)
        node.ChildNodes.Add(newNode)
      Next
    End Sub

    Sub PopulateNode(ByVal source As Object, ByVal e As TreeNodeEventArgs)
      Select Case e.Node.Depth
        Case 0
          GetProductCategories(e.Node)
        Case 1
          GetProductsForCategory(e.Node)
      End Select
    End Sub

  </script>
  <body>
    <div>
      <h2>Populating TreeView Nodes from a SQL Database</h2>

      <form action="treeview11_database_vb.aspx" runat="server">

        <asp:TreeView ID="TreeView1" OnTreeNodePopulate="PopulateNode" SkinId="Simple" Width="250" ExpandDepth="0" runat="server">
          <Nodes>
            <asp:TreeNode Text="Inventory" SelectAction="Expand" PopulateOnDemand="true"/>
          </Nodes>
        </asp:TreeView>

      </form>
    </div>
  </body>
</html>
