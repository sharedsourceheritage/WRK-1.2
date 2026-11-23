<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Protected Sub DataList1_ItemDataBound(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.DataListItemEventArgs)
    Dim s As SqlDataSource = e.Item.FindControl("OrderDetailsDataSource")
    s.SelectParameters("OrderID").DefaultValue = e.Item.DataItem("OrderID")
  End Sub
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Nested Master Details List</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>
        Orders and Order Details</h2>
      <asp:DataList DataKeyField="OrderID" DataSourceID="OrdersDataSource" ID="DataList1" GridLines="Both" CellPadding="15"
        OnItemDataBound="DataList1_ItemDataBound" runat="server">
        <AlternatingItemStyle BackColor="AntiqueWhite" />
        <ItemTemplate>
          <b>OrderID:</b>
          <asp:Label ID="OrderIDLabel" runat="server" Text='<%# Eval("OrderID") %>'></asp:Label><br />
          <b>OrderDate:</b>
          <asp:Label ID="OrderDateLabel" runat="server" Text='<%# Eval("OrderDate") %>'></asp:Label><br />
          <b>ShipCity:</b>
          <asp:Label ID="ShipCityLabel" runat="server" Text='<%# Eval("ShipCity") %>'></asp:Label><br />
          <b>ShipCountry:</b>
          <asp:Label ID="ShipCountryLabel" runat="server" Text='<%# Eval("ShipCountry") %>'></asp:Label><br />
          <br />
          <asp:GridView AutoGenerateColumns="False" DataSourceID="OrderDetailsDataSource" ID="GridView1"
            runat="server" Width="100%">
            <Columns>
              <asp:BoundField DataField="OrderID" HeaderText="OrderID" SortExpression="OrderID" />
              <asp:BoundField DataField="ProductName" HeaderText="ProductName" SortExpression="ProductName" />
              <asp:BoundField DataField="UnitPrice" HeaderText="UnitPrice" SortExpression="UnitPrice" />
              <asp:BoundField DataField="Quantity" HeaderText="Quantity" SortExpression="Quantity" />
            </Columns>
          </asp:GridView>
          <br /><br />
          <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Northwind %>" ID="OrderDetailsDataSource"
            runat="server" SelectCommand="SELECT [Order Details].OrderID, Products.ProductName, [Order Details].UnitPrice, [Order Details].Quantity FROM [Order Details] INNER JOIN Products ON [Order Details].ProductID = Products.ProductID WHERE  [Order Details].OrderID = @OrderID">
            <SelectParameters>
              <asp:Parameter Name="OrderID" />
            </SelectParameters>
          </asp:SqlDataSource>
        </ItemTemplate>
      </asp:DataList>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Northwind %>" ID="OrdersDataSource"
        runat="server" SelectCommand="SELECT [OrderID], [OrderDate], [ShipCity], [ShipCountry] FROM [Orders]">
      </asp:SqlDataSource>
    </div>
  </form>
</body>
</html>
