<%@ Page Language="VB" %>
<html>
<head runat="server">
  <title>Sorting Data Using GridView</title>
</head>
<body>
  <form id="form1" runat="server">
    <asp:GridView ID="GridView1" AllowSorting="true" runat="server" DataSourceID="SqlDataSource1"
      AutoGenerateColumns="False">
      <Columns>
        <asp:BoundField HeaderText="ID" DataField="au_id" SortExpression="au_id" />
        <asp:BoundField HeaderText="Last Name" DataField="au_lname" SortExpression="au_lname" />
        <asp:BoundField HeaderText="First Name" DataField="au_fname" SortExpression="au_fname" />
        <asp:BoundField HeaderText="Phone" DataField="phone" SortExpression="phone" />
        <asp:BoundField HeaderText="Address" DataField="address" SortExpression="address" />
        <asp:BoundField HeaderText="City" DataField="city" SortExpression="city" />
        <asp:BoundField HeaderText="State" DataField="state" SortExpression="state" />
        <asp:BoundField HeaderText="Zip Code" DataField="zip" SortExpression="zip" />
        <asp:CheckBoxField HeaderText="Contract" SortExpression="contract" DataField="contract" />
      </Columns>
    </asp:GridView>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
      SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]"
      ConnectionString="<%$ ConnectionStrings:Pubs %>" />
  </form>
</body>
</html>
