<%@ Page Language="VB" %>
<html>
<head runat="server">
  <title>GridView Bound to SqlDataReader</title>
</head>
<body>
  <form id="form1" runat="server">
    <asp:GridView ID="GridView1" DataSourceID="SqlDataSource1" AutoGenerateColumns="False"
      runat="server">
      <Columns>
        <asp:BoundField DataField="TenMostExpensiveProducts" HeaderText="Product" />
        <asp:BoundField DataField="UnitPrice" DataFormatString="{0:c}" HeaderText="Price" />
      </Columns>
    </asp:GridView>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
      ConnectionString="<%$ ConnectionStrings:Northwind %>" 
      SelectCommand="Ten Most Expensive Products"
      SelectCommandType="StoredProcedure"
      DataSourceMode="DataReader" />
  </form>
</body>
</html>
