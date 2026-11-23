<%@ Page Language="VB" %>
<html>
<head runat="server">
  <title>GridView Bound Fields</title>
</head>
<body>
  <form id="form1" runat="server">
    <asp:GridView ID="GridView1" DataSourceID="SqlDataSource1" AutoGenerateColumns="False"
      runat="server">
      <Columns>
        <asp:BoundField HeaderText="ID" DataField="au_id" ReadOnly="true" />
        <asp:BoundField HeaderText="Last Name" DataField="au_lname" />
        <asp:BoundField HeaderText="First Name" DataField="au_fname" />
        <asp:BoundField HeaderText="Phone" DataField="phone" />
        <asp:BoundField HeaderText="Address" DataField="address" />
        <asp:BoundField HeaderText="City" DataField="city" />
        <asp:BoundField HeaderText="State" DataField="state" />
        <asp:BoundField HeaderText="Zip Code" DataField="zip" />
        <asp:CheckBoxField HeaderText="Contract" DataField="contract" />
      </Columns>
    </asp:GridView>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
      SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]"
      ConnectionString="<%$ ConnectionStrings:Pubs %>" />
  </form>
</body>
</html>
