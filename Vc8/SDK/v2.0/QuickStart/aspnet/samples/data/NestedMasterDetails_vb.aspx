<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Protected Sub FormView1_DataBound(ByVal sender As Object, ByVal e As System.EventArgs)
    OrderDetailsDataSource.SelectParameters("OrderID").DefaultValue = FormView1.DataItem("OrderID")
  End Sub
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Nested Master Details</title>
</head>
<body>
  <form id="form1" runat="server">
    <div><h2>Orders and Order Details</h2>
      <asp:FormView AllowPaging="True" DataKeyNames="OrderID" DataSourceID="OrdersDataSource"
        ID="FormView1" OnDataBound="FormView1_DataBound" runat="server">
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
            runat="server">
            <Columns>
              <asp:BoundField DataField="OrderID" HeaderText="OrderID" SortExpression="OrderID" />
              <asp:BoundField DataField="ProductName" HeaderText="ProductName" SortExpression="ProductName" />
              <asp:BoundField DataField="UnitPrice" HeaderText="UnitPrice" SortExpression="UnitPrice" />
              <asp:BoundField DataField="Quantity" HeaderText="Quantity" SortExpression="Quantity" />
            </Columns>
          </asp:GridView>
        </ItemTemplate>
        <PagerSettings Position="Top" Mode="NextPrevious" NextPageText="Next Order &amp;gt;&amp;gt;" PreviousPageText="&amp;lt;&amp;lt; Previous Order" />
        <PagerStyle Font-Size="0.7em" />
      </asp:FormView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Northwind %>" ID="OrdersDataSource"
        runat="server" SelectCommand="SELECT [OrderID], [OrderDate], [ShipCity], [ShipCountry] FROM [Orders]">
      </asp:SqlDataSource>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Northwind %>" ID="OrderDetailsDataSource"
        runat="server" SelectCommand="SELECT [Order Details].OrderID, Products.ProductName, [Order Details].UnitPrice, [Order Details].Quantity FROM [Order Details] INNER JOIN Products ON [Order Details].ProductID = Products.ProductID WHERE  [Order Details].OrderID = @OrderID">
        <SelectParameters>
          <asp:Parameter Name="OrderID" />
        </SelectParameters>
      </asp:SqlDataSource>
    </div>
  </form>
</body>
</html>
